package x10firm.visit.builtins;

import java.util.Collections;
import java.util.List;

import com.sun.jna.Pointer;

import polyglot.types.LocalInstance;
import polyglot.types.Type;
import polyglot.util.Position;
import x10.types.MethodInstance;
import x10firm.types.FirmTypeSystem;
import x10firm.visit.CodeGenError;
import x10firm.visit.FirmGenerator;
import x10firm.visit.MethodConstruction;
import firm.CompoundType;
import firm.Entity;
import firm.Ident;
import firm.MethodType;
import firm.Mode;
import firm.bindings.binding_be;
import firm.bindings.binding_iroptimize;
import firm.nodes.Call;
import firm.nodes.Node;

/**
 * Create instance of built-in {@code static x10.lang.Zero.get[T](): T} method.
 */
class X10LangZeroGet implements BuiltinMethodGenerator {
	private static Mode getSizeTMode() {
		final int machineSize = binding_be.be_get_machine_size() / 8;

		switch (machineSize) {
		case 1:
			return Mode.getBu();
		case 2:
			return Mode.getHu();
		case 4:
			return Mode.getIu();
		case 8:
			return Mode.getLu();
		case 16:
			return Mode.getLLu();
		default:
			throw new CodeGenError("Unknown machine size: " + machineSize, Position.COMPILER_GENERATED);
		}
	}

	private static MethodType getMemsetMethodType() {
		final firm.Type pointer = Mode.getP().getType();
		final firm.Type signedInt = Mode.getIs().getType();
		final firm.Type sizeT = getSizeTMode().getType();
		final firm.Type[] parameterTypes = new firm.Type[]{pointer, signedInt, sizeT};
		final firm.Type[] resultTypes = new firm.Type[]{pointer};

		final MethodType methodType = new firm.MethodType(parameterTypes, resultTypes);
		return methodType;
	}

	@Override
	public void generate(final FirmGenerator codeGenerator, final MethodInstance meth,
		                 final List<LocalInstance> formals) {
		final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
		final Entity entity = firmTypeSystem.getMethodEntity(meth);

		assert meth.typeParameters().size() == 1;
		final Type typeParameter = meth.typeParameters().get(0);

		final Type returnType = meth.returnType();
		final MethodConstruction savedConstruction
			= codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
				returnType, null);
		final MethodConstruction con = codeGenerator.getFirmConstruction();

		final Node ret;
		final firm.Type firmType = firmTypeSystem.asType(typeParameter);
		if (!(firmType instanceof CompoundType)) {
			final Mode mode = firmTypeSystem.getFirmMode(typeParameter);
			final Node node = con.newConst(mode.getNull());
			final Node mem = con.getCurrentMem();
			ret = con.newReturn(mem, new Node[] {node});
		} else {
			final Mode mode = firmTypeSystem.getFirmMode(typeParameter);
			final Node tmpStruct = codeGenerator.genStackAlloc(typeParameter);

			final MethodType memsetType = getMemsetMethodType();
			final Ident memsetIdent = new Ident("memset");
			final Pointer memsetEntPtr =
					binding_iroptimize.create_compilerlib_entity(memsetIdent.ptr, memsetType.ptr);
			final Entity memsetEntity = new Entity(memsetEntPtr);
			final Node memsetAddress = con.newSymConst(memsetEntity);
			final Node structSizeP32 = con.newSymConstTypeSize(firmType, mode);
			final Node structSize = con.newConv(structSizeP32, Mode.getIu());
			final Node zero = con.newConst(0, Mode.getIs());
			final Node[] memsetArgs = new Node[]{tmpStruct, zero, structSize};
			final Node call = con.newCall(con.getCurrentMem(), memsetAddress, memsetArgs, memsetType);
			final Node callResults = con.newProj(call, Mode.getT(), Call.pnTResult);
			final Node callResult = con.newProj(callResults, mode, 0);
			final Node callMem = con.newProj(call, Mode.getM(), Call.pnM);
			con.setCurrentMem(callMem);
			ret = con.newReturn(con.getCurrentMem(), new Node[]{callResult});
		}
		con.getGraph().getEndBlock().addPred(ret);
		con.setUnreachable();
		codeGenerator.finishConstruction(entity, savedConstruction);
	}
}
