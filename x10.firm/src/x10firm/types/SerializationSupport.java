package x10firm.types;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

import x10.types.X10ClassType;
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
import firm.bindings.binding_oo.ddispatch_binding;
import firm.bindings.binding_typerep.ir_type_state;
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

	private static final String SERIALIZE_METHOD_NAME = "__serialize";
	private static final String SERIALIZE_METHOD_SIGNATURE = "PN3x104lang3AnyEPN3x104lang3AnyE";
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

	private int maxClassUid = 1;

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

		final Node returnMem = con.getCurrentMem();
		final Node returnn = con.newReturn(returnMem, new Node[] {});
		con.getGraph().getEndBlock().addPred(returnn);
		con.setUnreachable();

		con.finish();
	}
}
