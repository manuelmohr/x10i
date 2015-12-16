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
import firm.Mode.Arithmetic;
import firm.OO;
import firm.PointerType;
import firm.Program;
import firm.Relation;
import firm.SegmentType;
import firm.Type;
import firm.bindings.binding_oo.ddispatch_binding;
import firm.nodes.Alloc;
import firm.nodes.Block;
import firm.nodes.Call;
import firm.nodes.Cond;
import firm.nodes.Load;
import firm.nodes.Node;
import firm.nodes.Store;

/**
 * Helper class to generate the methods required for the serialization
 * and deserialization of values and objects, based on ideas from the
 * C++ backend.
 *
 * @see "x10.firm_runtime/src-c/x10_serialization.h"
 *
 * @author julian
 */
public final class SerializationSupport {

	private int maxClassUid = 1;

	private static final String GC_XMALLOC = "gc_xmalloc";
	private static final String GC_XMALLOC_ATOMIC = "gc_xmalloc_atomic";
	private static final String SERIALIZATION_WRITE_DATA = "x10_serialization_write_data";
	private static final String DESERIALIZATION_RESTORE_DATA = "x10_deserialization_restore_data";

	private static final String SERIALIZE_METHOD_NAME = "__serialize";
	private static final String SERIALIZE_METHOD_SIGNATURE = "PvPv";
	private MethodType serializeMethodType;

	private static final String DESERIALIZE_METHOD_NAME = "__deserialize";
	private static final String DESERIALIZE_METHOD_SIGNATURE = "PvPv";
	private MethodType deserializeMethodType;

	private static final String DESERIALIZE_METHOD_TABLE_NAME = "__deserialize_methods";
	private static final String SERIALIZE_METHOD_TABLE_NAME = "__serialize_methods";

	private Entity serializationWriteObject;
	private Entity deserializationRestoreObject;
	private Entity gcXMalloc;
	private Entity gcXMallocAtomic;
	private Entity serializationWriteData;
	private Entity deserializationRestoreData;
	private firm.Type sizeTType;

	/** Store the serialization function for each (class) type. */
	private final Map<Type, Entity> serializeFunctions = new HashMap<Type, Entity>();
	/** Store the deserialization function for each (class) type. */
	private final Map<Type, Entity> deserializeFunctions = new HashMap<Type, Entity>();

	/** record of the method / constructor used in the custom serialization protocol. */
	private static class CustomSerializationMethods {
		Entity serializeMethod;
		Entity deserializeConstructor;
	}

	private final Map<Type, CustomSerializationMethods> customSerializationMethods
		= new HashMap<Type, CustomSerializationMethods>();

	/**
	 * Initialize serialization support.
	 *
	 * This builds the entities for (de-)serializing primitives and objects.
	 */
	public void init(final FirmTypeSystem firmTypeSystem) {
		assert serializationWriteObject == null;

		final Type typeP = Mode.getP().getType();
		final Type[] emptyTypelist = new Type[] {};

		// first step: create the entities representing the runtime methods in x10_serialization.c
		final firm.Type[] swoParameterTypes = new firm.Type[] {typeP, typeP};
		final MethodType swoType = new MethodType(swoParameterTypes, emptyTypelist);
		final String swoName = NameMangler.mangleKnownName("x10_serialization_write_object");
		serializationWriteObject = firmTypeSystem.getGlobalEntity(swoName, swoType);
		serializationWriteObject.setLdIdent(swoName);

		final firm.Type[] droParamTypes = new firm.Type[] {typeP, typeP};
		final MethodType droType = new MethodType(droParamTypes, emptyTypelist);
		final String droName = NameMangler.mangleKnownName("x10_deserialization_restore_object");
		deserializationRestoreObject = firmTypeSystem.getGlobalEntity(droName, droType);
		deserializationRestoreObject.setLdIdent(droName);

		sizeTType = Mode.createIntMode("size_t", Arithmetic.TwosComplement, Mode.getP().getSizeBits(),
				false, Mode.getP().getModuloShift()).getType();

		final MethodType mallocType = new MethodType(new Type[] {sizeTType}, new Type[] {typeP});
		gcXMalloc = firmTypeSystem.getGlobalEntity(GC_XMALLOC, mallocType);
		gcXMalloc.setLdIdent(NameMangler.mangleKnownName(GC_XMALLOC));
		gcXMallocAtomic = firmTypeSystem.getGlobalEntity(GC_XMALLOC_ATOMIC, mallocType);
		gcXMallocAtomic.setLdIdent(NameMangler.mangleKnownName(GC_XMALLOC_ATOMIC));

		final MethodType serWriteDataType = new MethodType(new Type[] {typeP, typeP, sizeTType},
				emptyTypelist);
		serializationWriteData = firmTypeSystem.getGlobalEntity(SERIALIZATION_WRITE_DATA, serWriteDataType);
		serializationWriteData.setLdIdent(NameMangler.mangleKnownName(SERIALIZATION_WRITE_DATA));

		final MethodType deserRestoreDataType = new MethodType(new Type[] {typeP, typeP, sizeTType},
				emptyTypelist);
		deserializationRestoreData = firmTypeSystem.getGlobalEntity(DESERIALIZATION_RESTORE_DATA,
				deserRestoreDataType);
		deserializationRestoreData.setLdIdent(NameMangler.mangleKnownName(DESERIALIZATION_RESTORE_DATA));
	}

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

		final SegmentType global = Program.getGlobalType();

		final String serializeMethodName =
				NameMangler.mangleGeneratedMethodName(astType, SERIALIZE_METHOD_NAME, SERIALIZE_METHOD_SIGNATURE);
		if (serializeMethodType == null)
			serializeMethodType = new MethodType(new firm.Type[] {Mode.getP().getType(), Mode.getP().getType()},
					new firm.Type[] {});

		assert !serializeFunctions.containsKey(firmType);

		final Entity serEntity = new Entity(global, serializeMethodName, serializeMethodType);
		OO.setEntityBinding(serEntity, ddispatch_binding.bind_static);
		OO.setMethodExcludeFromVTable(serEntity, true);
		serializeFunctions.put(firmType, serEntity);

		final String deserializeMethodName =
				NameMangler.mangleGeneratedMethodName(astType, DESERIALIZE_METHOD_NAME, DESERIALIZE_METHOD_SIGNATURE);
		if (deserializeMethodType == null)
			deserializeMethodType = new MethodType(new firm.Type[] {Mode.getP().getType(), Mode.getP().getType()},
					new firm.Type[] {});

		final Entity deserEntity = new Entity(global, deserializeMethodName, deserializeMethodType);
		OO.setEntityBinding(deserEntity, ddispatch_binding.bind_static);
		OO.setMethodExcludeFromVTable(deserEntity, true);
		deserializeFunctions.put(firmType, deserEntity);
	}

	/**
	 * Mark a type as custom serialized, i.e. a type implementing x10.io.CustomSerialization.
	 * @param firmType The type to be marked.
	 */
	public void markAsCustomSerialized(final ClassType firmType) {
		customSerializationMethods.put(firmType, new CustomSerializationMethods());
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
	 * @param ctorFirm firm entity representing the constructor
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
	 * Generate the deserialization method table based on the final layout of the types.
	 *
	 * @param firmTypes a collection of all firm types. Only class types will be handled.
	 */
	public void finishSerialization(final Collection<ClassType> firmTypes, final FirmTypeSystem firmTypeSystem) {
		final firm.Type typeP = Mode.getP().getType();

		// Emit the table used to lookup the __deserialize method and vtable address
		// of a class. It is indexed by the class' type uid.
		final String dmtName = NameMangler.mangleKnownName(DESERIALIZE_METHOD_TABLE_NAME);
		final int nEntries = maxClassUid * 2;
		final ArrayType dmtType = new ArrayType(typeP);
		dmtType.setSize(nEntries);
		dmtType.finishLayout();
		final Entity deserializeMethodTable = firmTypeSystem.getGlobalEntity(dmtName, dmtType);
		final Initializer dmtInitializer = new Initializer(nEntries);

		final String smtName = NameMangler.mangleKnownName(SERIALIZE_METHOD_TABLE_NAME);
		final ArrayType smtType = new ArrayType(typeP);
		smtType.setSize(maxClassUid);
		smtType.finishLayout();
		final Entity serializeMethodTable = firmTypeSystem.getGlobalEntity(smtName, smtType);
		final Initializer smtInitializer = new Initializer(maxClassUid);

		final Graph constCode = Program.getConstCodeGraph();

		for (final ClassType classType : firmTypes) {
			final int classUid = OO.getClassUID(classType);
			if (classUid == 0) /* this will filter out structs and interfaces */
				continue;

			final Entity deserEntity = deserializeFunctions.get(classType);
			final Entity serEntity = serializeFunctions.get(classType);
			final Entity vtableEntity = OO.getClassVTableEntity(classType);

			assert classUid > 0;
			assert deserEntity != null;
			assert vtableEntity != null;

			final Node symcDeser = constCode.newAddress(deserEntity);
			final Initializer initDeser = new Initializer(symcDeser);
			dmtInitializer.setCompoundValue(classUid * 2, initDeser);
			final Node symcVtable = constCode.newAddress(vtableEntity);
			final Initializer initVtable = new Initializer(symcVtable);
			dmtInitializer.setCompoundValue(classUid * 2 + 1, initVtable);

			final Node symcSer = constCode.newAddress(serEntity);
			final Initializer initSer = new Initializer(symcSer);
			smtInitializer.setCompoundValue(classUid, initSer);
		}
		deserializeMethodTable.setInitializer(dmtInitializer);
		serializeMethodTable.setInitializer(smtInitializer);
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
		// don't recurse to the superclass, as constructors are not inherited.

		return null;
	}

	private void genCallToSerialize(final Type type, final Construction con, final Node bufPtr, final Node objPtr) {
		final Node mem = con.getCurrentMem();
		if (type instanceof PointerType) {
			/* this is an object reference */
			final Node load = con.newLoad(mem, objPtr, Mode.getP());
			final Node loadMem = con.newProj(load, Mode.getM(), Load.pnM);
			final Node newObjPtr = con.newProj(load, Mode.getP(), Load.pnRes);

			final Node swoSymConst = con.newAddress(serializationWriteObject);
			final Node call = con.newCall(loadMem, swoSymConst,
					new Node[] {bufPtr, newObjPtr}, serializationWriteObject.getType());
			final Node callMem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(callMem);
		} else {
			/* this has to be a value type (a Struct or the $super / $__value__ entity,
			 * or a primitive type) because otherwise we'd have a PointerType.
			 * in any case, we know exactly which serializer we need to call. */
			final Entity serializationFunction = serializeFunctions.get(type);
			assert serializationFunction != null;
			final Node symc = con.newAddress(serializationFunction);
			final Type functionType = serializationFunction.getType();
			final Node call = con.newCall(mem, symc, new Node[] {bufPtr, objPtr}, functionType);
			final Node callMem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(callMem);
		}
	}

	private void generateIndexedMemoryChunkSerialize(final Construction con, final X10ClassType astType,
	                                                 final ClassType klass, final Node bufPtr,
	                                                 final Node objPtr, final FirmTypeSystem firmTypeSystem) {
		Node ptr = null;
		Node length = null;
		Node lengthAddr = null;
		Type lengthType = null;

		for (Entity member : klass.getMembers()) {
			final Type memberType = member.getType();
			if (memberType instanceof MethodType)
				continue;

			// This is slightly ugly because it also depends on the name mangling.
			if (member.getName().endsWith("ptrE")) {
				final Node ptrAddr = con.newMember(objPtr, member);
				final Node load = con.newLoad(con.getCurrentMem(), ptrAddr, Mode.getP());
				con.setCurrentMem(con.newProj(load, Mode.getM(), Load.pnM));
				ptr = con.newProj(load, Mode.getP(), Load.pnRes);
			} else if (member.getName().endsWith("lengthE")) {
				lengthType = memberType;
				lengthAddr = con.newMember(objPtr, member);
				final Node load = con.newLoad(con.getCurrentMem(), lengthAddr, Mode.getIs());
				con.setCurrentMem(con.newProj(load, Mode.getM(), Load.pnM));
				length = con.newProj(load, Mode.getIs(), Load.pnRes);
			} else {
				assert false : "IndexedMemoryChunk has extraneous members";
			}
		}
		assert ptr != null && length != null;

		// First, serialize length
		genCallToSerialize(lengthType, con, bufPtr, lengthAddr);

		assert astType.typeArguments().size() == 1;
		final polyglot.types.Type argumentType = astType.typeArguments().get(0);
		final Type elementType = firmTypeSystem.asType(argumentType);

		// Generate call to write_data for primitive types
		final boolean isPrimitive = firmTypeSystem.getFirmMode(argumentType).isNum();
		if (isPrimitive) {
			final Node writeDataAddr = con.newAddress(serializationWriteData);
			Node mem = con.getCurrentMem();

			final Node elementSize = con.newSize(Mode.getIs(), elementType);
			final Node dataSize = con.newMul(length, elementSize, Mode.getIs());
			final Node dataSizeIu = con.newConv(dataSize, sizeTType.getMode());
			final Node writeDataCall = con.newCall(mem, writeDataAddr,
					new Node[] {bufPtr, ptr, dataSizeIu}, serializationWriteData.getType());
			mem = con.newProj(writeDataCall, Mode.getM(), Call.pnM);
			con.setCurrentMem(mem);
			return;
		}

		// Otherwise, build a loop to serialize each element stores in the chunk
		con.setVariable(0, con.newConst(0, Mode.getIs()));
		con.setVariable(1, ptr);
		final Node jmpToCond = con.newJmp();

		final Block condBlock = con.newBlock();
		condBlock.addPred(jmpToCond);
		con.setCurrentBlock(condBlock);
		final Node cmp = con.newCmp(con.getVariable(0, Mode.getIs()), length, Relation.Less);
		final Node cond = con.newCond(cmp);
		final Node projTrue = con.newProj(cond, Mode.getX(), Cond.pnTrue);
		final Node projFalse = con.newProj(cond, Mode.getX(), Cond.pnFalse);

		final Block bodyBlock = con.newBlock();
		bodyBlock.addPred(projTrue);
		con.setCurrentBlock(bodyBlock);
		final Node currentIndex = con.getVariable(0, Mode.getIs());
		final Node currentAddr = con.getVariable(1, Mode.getP());
		genCallToSerialize(elementType, con, bufPtr, currentAddr);
		final Node nextIndex = con.newAdd(currentIndex, con.newConst(1, Mode.getIs()), Mode.getIs());
		final Mode offsetMode = currentAddr.getMode().getReferenceOffsetMode();
		final Node elementSize = con.newSize(offsetMode, elementType);
		final Node nextAddr = con.newAdd(currentAddr, elementSize, Mode.getP());
		con.setVariable(0, nextIndex);
		con.setVariable(1, nextAddr);
		final Node backJmp = con.newJmp();
		condBlock.addPred(backJmp);
		condBlock.mature();

		final Block returnBlock = con.newBlock();
		returnBlock.addPred(projFalse);
		con.setCurrentBlock(returnBlock);
	}

	/**
	 * Register a serialization function from the runtime library.
	 * This is used for primitive types and similar where we cannot/or do now want to automatically generate one,
	 * but instead use a given variant form the runtime library.
	 */
	public void setKnownSerializationFunction(final Type type, final Entity function) {
		serializeFunctions.put(type, function);
	}

	/**
	 * Register a deserialization function for a specific firm type.
	 * This is used for primitive types and similar where we cannot/or do now want to automatically generate one,
	 * but instead use a given variant form the runtime library.
	 */
	public void setKnownDeserializationFunction(final Type type, final Entity function) {
		deserializeFunctions.put(type, function);
	}

	/**
	 * Generate the serialization function for the given type.
	 * @param astType The X10 type.
	 * @param klass The corresponding Firm type.
	 * @param firmTypeSystem Reference to the Firm type system object.
	 */
	public void generateSerializationFunction(final X10ClassType astType, final ClassType klass,
	                                          final FirmTypeSystem firmTypeSystem) {
		if (!serializeFunctions.containsKey(klass))
			return;

		final Entity serEntity = serializeFunctions.get(klass);

		final Graph graph = new Graph(serEntity, 2);
		final Construction con = new Construction(graph);
		final Node swoSymConst = con.newAddress(serializationWriteObject);

		final Node args = graph.getArgs();
		final Node bufPtr = con.newProj(args, Mode.getP(), 0);
		final Node objPtr = con.newProj(args, Mode.getP(), 1);

		if (astType.isString()) {
			final String stringSerializeName = NameMangler.mangleKnownName("x10_string_serialize");
			final Entity stringSerializeEntity =
					firmTypeSystem.getGlobalEntity(stringSerializeName, serializeMethodType);
			final Node stringSerializeSymc = con.newAddress(stringSerializeEntity);

			Node mem = con.getCurrentMem();
			final Node call = con.newCall(mem, stringSerializeSymc, new Node[] {bufPtr, objPtr}, serializeMethodType);
			mem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(mem);
		} else if (astType.isIndexedMemoryChunk()) {
			generateIndexedMemoryChunkSerialize(con, astType, klass, bufPtr, objPtr, firmTypeSystem);
		} else if (customSerializationMethods.containsKey(klass)) {
			final Entity customSerializeMethod = lookupCustomSerializeMethod(klass);
			assert customSerializeMethod != null;

			final Node customSymc = con.newAddress(customSerializeMethod);
			Node mem = con.getCurrentMem();

			final Node customCall = con.newCall(mem, customSymc, new Node[] {objPtr}, customSerializeMethod.getType());
			mem = con.newProj(customCall, Mode.getM(), Call.pnM);
			final Node customRes = con.newProj(customCall, Mode.getT(), Call.pnTResult);
			final Node serialData = con.newProj(customRes, Mode.getP(), 0);

			final Node writeCall = con.newCall(mem, swoSymConst, new Node[] {bufPtr, serialData},
					serializationWriteObject.getType());
			mem = con.newProj(writeCall, Mode.getM(), Call.pnM);
			con.setCurrentMem(mem);
		} else {
			for (Entity member : klass.getMembers()) {
				final Type memberType = member.getType();
				if (memberType instanceof MethodType)
					continue;
				if (OO.getFieldIsTransient(member))
					continue;

				final Node sel = con.newMember(objPtr, member);
				genCallToSerialize(memberType, con, bufPtr, sel);
			}
		}

		final Node returnMem = con.getCurrentMem();
		final Node returnn = con.newReturn(returnMem, new Node[] {});
		con.getGraph().getEndBlock().addPred(returnn);
		con.setUnreachable();

		con.finish();
	}

	private void genCallToDeserialize(final Type type, final Construction con, final Node bufPtr, final Node objPtr) {
		final Node mem = con.getCurrentMem();
		if (type instanceof PointerType) {
			/* object references */
			final Node droSymc = con.newAddress(deserializationRestoreObject);
			final Node call = con.newCall(mem, droSymc,
					new Node[] {bufPtr, objPtr},
					deserializationRestoreObject.getType());
			final Node callMem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(callMem);
		} else {
			/* primitives, structs and superclass subobjects */
			final Entity deserializer = deserializeFunctions.get(type);
			assert deserializer != null;
			final Node symc = con.newAddress(deserializer);
			final Type deserializerType = deserializer.getType();
			final Node call = con.newCall(mem, symc,
					new Node[] {bufPtr, objPtr}, deserializerType);
			final Node callMem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(callMem);
		}
	}

	private Entity chooseMallocEntity(final FirmTypeSystem firmTypeSystem, final polyglot.types.Type elementType) {
		final Mode paramMode = firmTypeSystem.getFirmMode(elementType);
		final boolean isPointerFree = paramMode.isNum();
		return isPointerFree ? gcXMallocAtomic : gcXMalloc;
	}

	private void generateIndexedMemoryChunkDeserialize(final Construction con, final X10ClassType astType,
	                                                   final ClassType klass, final Node bufPtr,
	                                                   final Node objPtr, final FirmTypeSystem firmTypeSystem) {
		Node ptrPtr = null;
		Node lengthPtr = null;
		Type lengthType = null;

		for (Entity member : klass.getMembers()) {
			final Type memberType = member.getType();
			if (memberType instanceof MethodType)
				continue;

			// This is slightly ugly because it also depends on the name mangling.
			if (member.getName().endsWith("ptrE")) {
				ptrPtr = con.newMember(objPtr, member);
			} else if (member.getName().endsWith("lengthE")) {
				lengthType = memberType;
				lengthPtr = con.newMember(objPtr, member);
			} else {
				assert false : "IndexedMemoryChunk has extraneous members";
			}
		}
		assert ptrPtr != null && lengthPtr != null;

		// First, deserialize length
		genCallToDeserialize(lengthType, con, bufPtr, lengthPtr);
		final Node load = con.newLoad(con.getCurrentMem(), lengthPtr, Mode.getIs());
		con.setCurrentMem(con.newProj(load, Mode.getM(), Load.pnM));
		final Node length = con.newProj(load, Mode.getIs(), Load.pnRes);

		assert astType.typeArguments().size() == 1;
		final polyglot.types.Type x10ElementType = astType.typeArguments().get(0);
		final Type elementType = firmTypeSystem.asType(x10ElementType);

		// Second, allocate memory for the new backing storage
		final Node elemSize = con.newSize(Mode.getIs(), elementType);
		final Node mallocSize = con.newMul(length, elemSize, Mode.getIs());
		final Node mallocSizeIu = con.newConv(mallocSize, sizeTType.getMode());
		final Node mallocSymConst = con.newAddress(chooseMallocEntity(firmTypeSystem, x10ElementType));
		final Node[] mallocArgs = new Node[] {mallocSizeIu};
		final Node mallocCall = con.newCall(con.getCurrentMem(), mallocSymConst, mallocArgs, gcXMalloc.getType());
		con.setCurrentMem(con.newProj(mallocCall, Mode.getM(), Call.pnM));
		final Node mallocResults = con.newProj(mallocCall, Mode.getT(), Call.pnTResult);
		final Node newStorage = con.newProj(mallocResults, Mode.getP(), 0);
		final Node storePtr = con.newStore(con.getCurrentMem(), ptrPtr, newStorage);
		con.setCurrentMem(con.newProj(storePtr, Mode.getM(), Store.pnM));

		// Third, generate call to restore_data for primitive types
		final Mode elementMode = firmTypeSystem.getFirmMode(x10ElementType);
		final boolean isPrimitive = elementMode.isNum();
		if (isPrimitive) {
			final Node restoreDataAddr = con.newAddress(deserializationRestoreData);
			Node mem = con.getCurrentMem();
			final Node loadPtr = con.newLoad(mem, ptrPtr, Mode.getP());
			mem = con.newProj(loadPtr, Mode.getM(), Load.pnM);
			final Node ptr = con.newProj(loadPtr, Mode.getP(), Load.pnRes);
			final Node elementSize = con.newSize(Mode.getIs(), elementType);
			final Node dataSize = con.newMul(length, elementSize, Mode.getIs());
			final Node dataSizeIu = con.newConv(dataSize, sizeTType.getMode());
			final Node restoreDataCall = con.newCall(mem, restoreDataAddr,
					new Node[] {bufPtr, ptr, dataSizeIu}, deserializationRestoreData.getType());
			mem = con.newProj(restoreDataCall, Mode.getM(), Call.pnM);
			con.setCurrentMem(mem);
			return;
		}

		// Third, build a loop to deserialize every element into our new backing storage
		con.setVariable(0, con.newConst(0, Mode.getIs()));
		con.setVariable(1, newStorage);
		final Node jmpToCond = con.newJmp();

		final Block condBlock = con.newBlock();
		condBlock.addPred(jmpToCond);
		con.setCurrentBlock(condBlock);
		final Node cmp = con.newCmp(con.getVariable(0, Mode.getIs()), length, Relation.Less);
		final Node cond = con.newCond(cmp);
		final Node projTrue = con.newProj(cond, Mode.getX(), Cond.pnTrue);
		final Node projFalse = con.newProj(cond, Mode.getX(), Cond.pnFalse);

		final Block bodyBlock = con.newBlock();
		bodyBlock.addPred(projTrue);
		con.setCurrentBlock(bodyBlock);
		final Node currentIndex = con.getVariable(0, Mode.getIs());
		final Node currentAddr = con.getVariable(1, Mode.getP());
		genCallToDeserialize(elementType, con, bufPtr, currentAddr);
		final Node nextIndex = con.newAdd(currentIndex, con.newConst(1, Mode.getIs()), Mode.getIs());
		final Mode offsetMode = currentAddr.getMode().getReferenceOffsetMode();
		final Node elementSize = con.newSize(offsetMode, elementType);
		final Node nextAddr = con.newAdd(currentAddr, elementSize, Mode.getP());
		con.setVariable(0, nextIndex);
		con.setVariable(1, nextAddr);
		final Node backJmp = con.newJmp();
		condBlock.addPred(backJmp);
		condBlock.mature();

		final Block returnBlock = con.newBlock();
		returnBlock.addPred(projFalse);
		con.setCurrentBlock(returnBlock);
	}

	/**
	 * Generate the deserialization function for the given type.
	 * @param astType The X10 type.
	 * @param klass The corresponding Firm type.
	 * @param firmTypeSystem Reference to the Firm type system object.
	 */
	public void generateDeserializationFunction(final X10ClassType astType, final ClassType klass,
	                                            final FirmTypeSystem firmTypeSystem) {
		if (!deserializeFunctions.containsKey(klass))
			return;

		final Entity deserEntity = deserializeFunctions.get(klass);

		final Graph graph = new Graph(deserEntity, 2);
		final Construction con = new Construction(graph);

		final Node droSymc = con.newAddress(deserializationRestoreObject);

		final Node args = graph.getArgs();
		final Node bufPtr = con.newProj(args, Mode.getP(), 0);
		final Node objPtr = con.newProj(args, Mode.getP(), 1);

		if (astType.isString()) {
			final String stringDeserializeName = NameMangler.mangleKnownName("x10_string_deserialize");
			final Entity stringDeserializeEntity =
					firmTypeSystem.getGlobalEntity(stringDeserializeName, deserializeMethodType);
			final Node stringDeserializeSymc = con.newAddress(stringDeserializeEntity);

			Node mem = con.getCurrentMem();
			final Node call = con.newCall(mem, stringDeserializeSymc, new Node[] {bufPtr, objPtr},
					deserializeMethodType);
			mem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(mem);
		} else if (astType.isIndexedMemoryChunk()) {
			generateIndexedMemoryChunkDeserialize(con, astType, klass, bufPtr, objPtr, firmTypeSystem);
		} else if (customSerializationMethods.containsKey(klass)) {
			final Entity customDeserializeConstructor = lookupCustomDeserializeConstructor(klass);
			if (customDeserializeConstructor == null)
				throw new InternalCompilerError(String.format(
						"no constructor 'this(x10.io.SerialData)' for custom deserialization protocol found in %s",
						klass.getName()));

			final boolean isStruct = astType.isX10Struct();
			Node mem = con.getCurrentMem();
			final Node customSymc = con.newAddress(customDeserializeConstructor);

			final Node size = con.newSize(Mode.getIu(), Mode.getP().getType());
			final Node serialDataAlloc = con.newAlloc(mem, size, Mode.getP().getType().getAlignmentBytes());
			mem = con.newProj(serialDataAlloc, Mode.getM(), Alloc.pnM);
			final Node serialDataPtr = con.newProj(serialDataAlloc, Mode.getP(), Alloc.pnRes);

			final Node restoreCall = con.newCall(mem, droSymc, new Node[] {bufPtr,  serialDataPtr},
					deserializationRestoreObject.getType());
			mem = con.newProj(restoreCall, Mode.getM(), Call.pnM);

			final Node load = con.newLoad(mem, serialDataPtr, Mode.getP());
			mem = con.newProj(load, Mode.getM(), Load.pnM);
			final Node serialData = con.newProj(load, Mode.getP(), Load.pnRes);

			final Node[] ctorCallArgs = isStruct ? new Node[] {serialData} : new Node[] {objPtr, serialData};
			final Node ctorCall = con.newCall(mem, customSymc, ctorCallArgs,
					customDeserializeConstructor.getType());
			mem = con.newProj(ctorCall, Mode.getM(), Call.pnM);

			/* If we're dealing with a struct, the constructor does not take a hidden parameter (see above)
			 * and returns the newly constructed struct by value.  We therefore have to copy the returned
			 * value to the target destination. */
			if (isStruct) {
				final Node results = con.newProj(ctorCall, Mode.getT(), Call.pnTResult);
				final Mode resultMode = firmTypeSystem.getFirmMode(astType);
				final Node newObj = con.newProj(results, resultMode, 0);
				final Node copyB = con.newCopyB(mem, objPtr, newObj, klass,
						firm.bindings.binding_ircons.ir_cons_flags.cons_none);
				mem = copyB;
			}

			con.setCurrentMem(mem);
		} else {
			for (Entity member : klass.getMembers()) {
				final Type memberType = member.getType();
				if (memberType instanceof MethodType)
					continue;
				if (OO.getFieldIsTransient(member))
					continue;

				final Node sel = con.newMember(objPtr, member);
				genCallToDeserialize(memberType, con, bufPtr, sel);
			}
		}

		final Node returnMem = con.getCurrentMem();
		final Node returnn = con.newReturn(returnMem, new Node[] {});
		con.getGraph().getEndBlock().addPred(returnn);
		con.setUnreachable();

		con.finish();
	}
}
