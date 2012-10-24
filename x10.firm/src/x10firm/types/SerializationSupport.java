package x10firm.types;

import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.util.InternalCompilerError;
import x10.types.MethodInstance;
import x10.types.X10ClassType;
import x10.types.X10ConstructorInstance;
import firm.ArrayType;
import firm.ClassType;
import firm.Construction;
import firm.Entity;
import firm.Graph;
import firm.Initializer;
import firm.MethodType;
import firm.Mode;
import firm.OO;
import firm.PointerType;
import firm.Program;
import firm.Type;
import firm.bindings.binding_ircons.ir_where_alloc;
import firm.bindings.binding_oo.ddispatch_binding;
import firm.bindings.binding_typerep.ir_type_state;
import firm.nodes.Alloc;
import firm.nodes.Call;
import firm.nodes.Load;
import firm.nodes.Node;
import firm.nodes.OOConstruction;

/**
 * Helper class to generate the methods required for the serialization
 * and deserialization of values and objects, based on ideas from the
 * C++ backend.
 *
 * @author julian
 */
public final class SerializationSupport {

	private int maxClassUid = 1;

	private static final String SERIALIZE_METHOD_NAME = "__serialize";
	private static final String SERIALIZE_METHOD_SIGNATURE = "PvPv";
	private MethodType serializeMethodType;

	private static final String DESERIALIZE_METHOD_NAME = "__deserialize";
	private static final String DESERIALIZE_METHOD_SIGNATURE = "PvPv";
	private MethodType deserializeMethodType;

	private static final String DESERIALIZE_METHOD_TABLE_NAME = "__deserialize_methods";

	private Entity serializationWritePrimitiveEntity;
	private Entity serializationWriteObjectEntity;
	private Entity deserializationRestorePrimitiveEntity;
	private Entity deserializationRestoreObjectEntity;

	/** Store the (de)serialization method for each (class) type. */
	private final Map<Type, Entity> serializeMethods = new HashMap<Type, Entity>();
	private final Map<Type, Entity> deserializeMethods = new HashMap<Type, Entity>();

	/** used to determine whether a class wants to implement the custom serialization protocol. */
	private X10ClassType customSerializationInterface;

	/** record of the method / constructor used in the custom serialization protocol. */
	private static class CustomSerializationMethods {
		Entity serializeMethod;
		Entity deserializeConstructor;
	}

	private final Map<Type, CustomSerializationMethods> customSerializationMethods
		= new HashMap<Type, CustomSerializationMethods>();

	/**
	 * Create the __serialize and __deserialize method entities for the given type.
	 *
	 * @param astType a X10 class or struct type
	 * @param firmType the firm type representing astType
	 */
	public void setupSerialization(final X10ClassType astType, final ClassType firmType) {
		assert !astType.flags().isInterface();

		if (!astType.flags().isStruct()) {
			OO.setClassUID(firmType, maxClassUid++);
		}

		if (customSerializationInterface != null
				&& astType.isSubtype(customSerializationInterface, astType.typeSystem().emptyContext()))
			customSerializationMethods.put(firmType, new CustomSerializationMethods());

		final ClassType global = Program.getGlobalType();

		final String serializeMethodName =
				NameMangler.mangleGeneratedMethodName(astType, SERIALIZE_METHOD_NAME, SERIALIZE_METHOD_SIGNATURE);
		if (serializeMethodType == null)
			serializeMethodType = new MethodType(new firm.Type[] {Mode.getP().getType(), Mode.getP().getType()},
					new firm.Type[] {});

		if (astType.isObject() || astType.superClass() != null) {
			/* normal classes, dynamic dispatch of serializer method required */
			assert !serializeMethods.containsKey(firmType);

			final Entity serEntity = new Entity(firmType, serializeMethodName, serializeMethodType);

			if (!astType.isObject()) {
				final ClassType superType = (ClassType) firmType.getSuperType(0);
				final Entity superSerEntity = serializeMethods.get(superType);
				assert superSerEntity != null;
				serEntity.addEntityOverwrites(superSerEntity);
			}

			OO.setEntityBinding(serEntity, ddispatch_binding.bind_dynamic);
			serializeMethods.put(firmType, serEntity);
		} else {
			/* (de)serializers for structs will be bound statically */
			assert !serializeMethods.containsKey(firmType);

			final Entity serEntity = new Entity(global, serializeMethodName, serializeMethodType);
			OO.setEntityBinding(serEntity, ddispatch_binding.bind_static);
			OO.setMethodExcludeFromVTable(serEntity, true);

			serializeMethods.put(firmType, serEntity);
		}

		final String deserializeMethodName =
				NameMangler.mangleGeneratedMethodName(astType, DESERIALIZE_METHOD_NAME, DESERIALIZE_METHOD_SIGNATURE);
		if (deserializeMethodType == null)
			deserializeMethodType = new MethodType(new firm.Type[] {Mode.getP().getType(), Mode.getP().getType()},
					new firm.Type[] {});

		final Entity deserEntity = new Entity(global, deserializeMethodName, deserializeMethodType);
		OO.setEntityBinding(deserEntity, ddispatch_binding.bind_static);
		OO.setMethodExcludeFromVTable(deserEntity, true);
		deserializeMethods.put(firmType, deserEntity);
	}

	/**
	 * Record the X10ClassType of the custom serialization interface when it is encountered.
	 * @param iface the type representing x10.io.CustomSerialization
	 */
	public void setCustomSerializationInterface(final X10ClassType iface) {
		customSerializationInterface = iface;
	}

	/**
	 * Remembers the given method if the owner implements x10.io.CustomSerialization
	 * and its signature is serialize() : x10.io.SerialData.
	 *
	 * @param method the method to remember
	 * @param ownerFirm firm type representing the owner
	 * @param methodFirm firm entity representing the method
	 */
	public void setCustomSerializeMethod(final MethodInstance method,
			final ClassType ownerFirm, final Entity methodFirm) {
		if (!customSerializationMethods.containsKey(ownerFirm))
			return;
		if (!(method.name().toString().equals("serialize")
			&& method.formalTypes().size() == 0
			&& method.returnType().toString().equals("x10.io.SerialData"))) {
			return;
		}

		final CustomSerializationMethods csm = customSerializationMethods.get(ownerFirm);
		csm.serializeMethod = methodFirm;
	}

	/**
	 * Remembers the given constructor if it belongs to a class implementing
	 * x10.io.CustomSerialization and its signature is this(x10.io.SerialData).
	 *
	 * @param ctor the constructor to remember
	 * @param ownerFirm firm type representing the owner
	 * @param ctorFirm firm entity representig the constructor
	 */
	public void setCustomDeserializeConstructor(final X10ConstructorInstance ctor,
			final ClassType ownerFirm, final Entity ctorFirm) {
		if (!customSerializationMethods.containsKey(ownerFirm))
			return;

		final List<polyglot.types.Type> formals = ctor.formalTypes();
		if (!(formals.size() == 1 && formals.get(0).toString().equals("x10.io.SerialData")))
			return;

		final CustomSerializationMethods csm = customSerializationMethods.get(ownerFirm);
		csm.deserializeConstructor = ctorFirm;
	}

	/**
	 * Generate the (de)serialization methods based on the final layout of the type,
	 * and generate the deserialization method table.
	 *
	 * @param firmTypes a collection of all firm types. Only class types will be handled.
	 */
	public void generateSerializationMethods(final Collection<firm.Type> firmTypes) {
		assert serializationWritePrimitiveEntity == null;
		assert serializationWriteObjectEntity == null;
		assert deserializationRestorePrimitiveEntity == null;
		assert deserializationRestoreObjectEntity == null;

		final firm.Type global = Program.getGlobalType();
		final firm.Type typeP = Mode.getP().getType();
		final firm.Type typeIu = Mode.getIu().getType();
		final firm.Type[] retTypeVoid = new firm.Type[] {};

		final firm.Type[] swpParameterTypes = new firm.Type[] {typeP, typeP, typeIu};
		final MethodType swpType = new MethodType(swpParameterTypes, retTypeVoid);
		final String swpName = NameMangler.mangleKnownName("x10_serialization_write_primitive");
		serializationWritePrimitiveEntity = new Entity(global, swpName, swpType);
		serializationWritePrimitiveEntity.setLdIdent(swpName);

		final firm.Type[] swoParameterTypes = new firm.Type[] {typeP, typeP};
		final MethodType swoType = new MethodType(swoParameterTypes, retTypeVoid);
		final String swoName = NameMangler.mangleKnownName("x10_serialization_write_object");
		serializationWriteObjectEntity = new Entity(global, swoName, swoType);
		serializationWriteObjectEntity.setLdIdent(swoName);

		final firm.Type[] drpParameterTypes = new firm.Type[] {typeP, typeP, typeIu};
		final MethodType drpType = new MethodType(drpParameterTypes, retTypeVoid);
		final String drpName = NameMangler.mangleKnownName("x10_deserialization_restore_primitive");
		deserializationRestorePrimitiveEntity = new Entity(global, drpName, drpType);
		deserializationRestorePrimitiveEntity.setLdIdent(drpName);

		final firm.Type[] droParamTypes = new firm.Type[] {typeP, typeP};
		final MethodType droType = new MethodType(droParamTypes, retTypeVoid);
		final String droName = NameMangler.mangleKnownName("x10_deserialization_restore_object");
		deserializationRestoreObjectEntity = new Entity(global, droName, droType);
		deserializationRestoreObjectEntity.setLdIdent(droName);

		for (final Type type : firmTypes) {
			if (!(type instanceof ClassType))
				continue;

			final ClassType classType = (ClassType) type;
			generateSerializationMethod(classType);
			generateDeserializationMethod(classType);
		}

		final String dmtName = NameMangler.mangleKnownName(DESERIALIZE_METHOD_TABLE_NAME);
		final int nEntries = maxClassUid * 2;
		final ArrayType dmtType = new ArrayType(typeP);
		dmtType.setBounds(0, 0, nEntries);
		dmtType.setSizeBytes(typeP.getSizeBytes() * nEntries);
		dmtType.setTypeState(ir_type_state.layout_fixed);
		dmtType.setAlignmentBytes(32);
		final Entity deserializeMethodTable = new Entity(global, dmtName, dmtType);

		final Graph constCode = Program.getConstCodeGraph();
		final Initializer init = new Initializer(nEntries);

		for (final Type type : firmTypes) {
			if (!(type instanceof ClassType))
				continue;

			final ClassType classType = (ClassType) type;
			final int classUid = OO.getClassUID(classType);
			if (classUid == 0) /* this will filter out structs and interfaces */
				continue;

			final Entity deserEntity = deserializeMethods.get(classType);
			final Entity vtableEntity = OO.getClassVTableEntity(classType);

			assert classUid > 0;
			assert deserEntity != null;
			assert vtableEntity != null;

			final Node symcDeser = constCode.newSymConst(deserEntity);
			final Initializer initDeser = new Initializer(symcDeser);
			init.setCompoundValue(classUid * 2, initDeser);
			final Node symcVtable = constCode.newSymConst(vtableEntity);
			final Initializer initVtable = new Initializer(symcVtable);
			init.setCompoundValue(classUid * 2 + 1, initVtable);
		}
		deserializeMethodTable.setInitializer(init);
	}

	private Entity lookupCustomSerializeMethod(final ClassType klass) {
		if (customSerializationMethods.containsKey(klass)) {
			final CustomSerializationMethods csm = customSerializationMethods.get(klass);
			if (csm.serializeMethod != null)
				return csm.serializeMethod;

			if (klass.getNSuperTypes() > 0) {
				final Type superType = klass.getSuperType(0);
				assert superType instanceof ClassType;
				return lookupCustomSerializeMethod((ClassType) superType);
			}
		}

		return null;
	}

	private Entity lookupCustomDeserializeConstructor(final ClassType klass) {
		if (customSerializationMethods.containsKey(klass)) {
			final CustomSerializationMethods csm = customSerializationMethods.get(klass);
			return csm.deserializeConstructor;
		}

		return null;
	}

	private void generateSerializationMethod(final ClassType klass) {
		if (!serializeMethods.containsKey(klass))
			return;

		final Entity serEntity = serializeMethods.get(klass);

		final Graph graph = new Graph(serEntity, 0);
		final Construction con = new OOConstruction(graph);
		final Node swpSymConst = con.newSymConst(serializationWritePrimitiveEntity);
		final Node swoSymConst = con.newSymConst(serializationWriteObjectEntity);

		final Node args = graph.getArgs();
		final Node bufPtr = con.newProj(args, Mode.getP(), 0);
		final Node objPtr = con.newProj(args, Mode.getP(), 1);

		if (klass.getName().equals("x10.lang.String")) {
			final String stringSerializeName = NameMangler.mangleKnownName("x10_string_serialize");
			final Entity stringSerializeEntity = new Entity(klass, stringSerializeName, serializeMethodType);
			final Node stringSerializeSymc = con.newSymConst(stringSerializeEntity);

			Node mem = con.getCurrentMem();
			final Node call = con.newCall(mem, stringSerializeSymc, new Node[] {bufPtr, objPtr}, serializeMethodType);
			mem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(mem);
		} else if (customSerializationMethods.containsKey(klass)) {
			final Entity customSerializeMethod = lookupCustomSerializeMethod(klass);
			assert customSerializeMethod != null;

			final Node customSymc = con.newSymConst(customSerializeMethod);
			Node mem = con.getCurrentMem();

			final Node customCall = con.newCall(mem, customSymc, new Node[] {objPtr}, customSerializeMethod.getType());
			mem = con.newProj(customCall, Mode.getM(), Call.pnM);
			final Node customRes = con.newProj(customCall, Mode.getT(), Call.pnTResult);
			final Node serialData = con.newProj(customRes, Mode.getP(), 0);

			final Node writeCall = con.newCall(mem, swoSymConst, new Node[] {bufPtr, serialData},
					serializationWriteObjectEntity.getType());
			mem = con.newProj(writeCall, Mode.getM(), Call.pnM);
			con.setCurrentMem(mem);
		} else {
			for (Entity member : klass.getMembers()) {
				final Type memberType = member.getType();
				if (memberType instanceof MethodType)
					continue;
				if (OO.getFieldIsTransient(member))
					continue;

				Node mem = con.getCurrentMem();
				final Node sel = con.newSel(objPtr, member);

				if (memberType instanceof ClassType) {
					/* this has to be a Struct or the $super / $__value__ entity,
					 * because otherwise we'd have a PointerType.
					 * in any case, we know exactly which serializer we need to call. */

					final Entity structSerializer = serializeMethods.get(memberType);
					assert structSerializer != null;
					final Node symc = con.newSymConst(structSerializer);
					final Node call = con.newCall(mem, symc,
							new Node[] {bufPtr, sel}, structSerializer.getType());
					mem = con.newProj(call, Mode.getM(), Call.pnM);
					con.setCurrentMem(mem);
				} else if (memberType instanceof PointerType) {
					/* this is an object reference */

					final Node load = con.newLoad(mem, sel, Mode.getP());
					mem = con.newProj(load, Mode.getM(), Load.pnM);
					con.setCurrentMem(mem);
					final Node newObjPtr = con.newProj(load, Mode.getP(), Load.pnRes);

					final Node call = con.newCall(mem, swoSymConst,
							new Node[] {bufPtr, newObjPtr}, serializationWriteObjectEntity.getType());
					mem = con.newProj(call, Mode.getM(), Call.pnM);
					con.setCurrentMem(mem);
				} else {
					/* primitives */

					final Node call = con.newCall(mem, swpSymConst,
							new Node[] {bufPtr, sel, con.newSymConstTypeSize(memberType, Mode.getIu())},
							serializationWritePrimitiveEntity.getType());
					mem = con.newProj(call, Mode.getM(), Call.pnM);
					con.setCurrentMem(mem);
				}
			}
		}

		final Node returnMem = con.getCurrentMem();
		final Node returnn = con.newReturn(returnMem, new Node[] {});
		con.getGraph().getEndBlock().addPred(returnn);
		con.setUnreachable();

		con.finish();
	}

	private void generateDeserializationMethod(final ClassType klass) {
		if (!deserializeMethods.containsKey(klass))
			return;

		final Entity deserEntity = deserializeMethods.get(klass);

		final Graph graph = new Graph(deserEntity, 0);
		final Construction con = new OOConstruction(graph);

		final Node drpSymc = con.newSymConst(deserializationRestorePrimitiveEntity);
		final Node droSymc = con.newSymConst(deserializationRestoreObjectEntity);

		final Node args = graph.getArgs();
		final Node bufPtr = con.newProj(args, Mode.getP(), 0);
		final Node objPtr = con.newProj(args, Mode.getP(), 1);

		if (klass.getName().equals("x10.lang.String")) {
			final String stringDeserializeName = NameMangler.mangleKnownName("x10_string_deserialize");
			final Entity stringDeserializeEntity = new Entity(klass, stringDeserializeName, deserializeMethodType);
			final Node stringDeserializeSymc = con.newSymConst(stringDeserializeEntity);

			Node mem = con.getCurrentMem();
			final Node call = con.newCall(mem, stringDeserializeSymc, new Node[] {bufPtr, objPtr},
					deserializeMethodType);
			mem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(mem);
		} else if (customSerializationMethods.containsKey(klass)) {
			final Entity customDeserializeConstructor = lookupCustomDeserializeConstructor(klass);
			if (customDeserializeConstructor == null)
				throw new InternalCompilerError(String.format(
						"no constructor 'this(x10.io.SerialData)' for custom deserialization protocol found in %s",
						klass.getName()));

			Node mem = con.getCurrentMem();
			final Node customSymc = con.newSymConst(customDeserializeConstructor);

			final Node serialDataAlloc = con.newAlloc(mem, con.newConst(1, Mode.getIu()),
					new PointerType(Mode.getP().getType()), ir_where_alloc.stack_alloc);
			mem = con.newProj(serialDataAlloc, Mode.getM(), Alloc.pnM);
			final Node serialDataPtr = con.newProj(serialDataAlloc, Mode.getP(), Alloc.pnRes);

			final Node restoreCall = con.newCall(mem, droSymc, new Node[] {bufPtr,  serialDataPtr},
					deserializationRestoreObjectEntity.getType());
			mem = con.newProj(restoreCall, Mode.getM(), Call.pnM);

			final Node load = con.newLoad(mem, serialDataPtr, Mode.getP());
			mem = con.newProj(load, Mode.getM(), Load.pnM);
			final Node serialData = con.newProj(load, Mode.getP(), Load.pnRes);

			final Node ctorCall = con.newCall(mem, customSymc, new Node[] {objPtr, serialData},
					customDeserializeConstructor.getType());
			mem = con.newProj(ctorCall, Mode.getM(), Call.pnM);

			con.setCurrentMem(mem);
		} else {
			for (Entity member : klass.getMembers()) {
				final Type memberType = member.getType();
				if (memberType instanceof MethodType)
					continue;
				if (OO.getFieldIsTransient(member))
					continue;

				Node mem = con.getCurrentMem();
				final Node sel = con.newSel(objPtr, member);

				if (memberType instanceof ClassType) {
					/* structs and superclass subobjects */
					final Entity structDeserializer = deserializeMethods.get(memberType);
					assert structDeserializer != null;
					final Node symc = con.newSymConst(structDeserializer);
					final Node call = con.newCall(mem, symc,
							new Node[] {bufPtr, sel}, deserializeMethodType);
					mem = con.newProj(call, Mode.getM(), Call.pnM);
					con.setCurrentMem(mem);
				} else if (memberType instanceof PointerType) {
					/* object references */
					final Node call = con.newCall(mem, droSymc,
							new Node[] {bufPtr, sel},
							deserializationRestoreObjectEntity.getType());
					mem = con.newProj(call, Mode.getM(), Call.pnM);
					con.setCurrentMem(mem);
				} else {
					/* primitives */
					final Node call = con.newCall(mem, drpSymc,
							new Node[] {bufPtr, sel, con.newSymConstTypeSize(memberType, Mode.getIu())},
							deserializationRestorePrimitiveEntity.getType());
					mem = con.newProj(call, Mode.getM(), Call.pnM);
					con.setCurrentMem(mem);
				}
			}
		}

		final Node returnMem = con.getCurrentMem();
		final Node returnn = con.newReturn(returnMem, new Node[] {});
		con.getGraph().getEndBlock().addPred(returnn);
		con.setUnreachable();

		con.finish();
	}
}
