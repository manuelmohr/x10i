package x10firm.visit.x10lib;

import java.util.Collections;
import java.util.List;

import polyglot.types.LocalInstance;
import polyglot.types.Type;
import x10.types.MethodInstance;
import x10.types.X10ClassType;
import x10firm.types.FirmTypeSystem;
import x10firm.visit.FirmGenerator;
import x10firm.visit.MethodConstruction;
import x10firm.visit.VarEntry;
import firm.Entity;
import firm.Mode;
import firm.nodes.CopyB;
import firm.nodes.Load;
import firm.nodes.Node;
import firm.nodes.Store;

/**
 * Firm Generator for x10.lang.Pointer
 */
public class PointerGenerator extends NativeGenericDispatcher {
	/**
	 *  Firm generator for the "read" method in x10.lang.Pointer
	 */
	static class GenRead implements NativeGenericMethodGenerator {
		@Override
		public boolean gen(final FirmGenerator codeGenerator, final MethodInstance meth,
						   final List<LocalInstance> formals) {
			final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
			final X10ClassType owner = (X10ClassType)meth.container();
			final Entity entity = firmTypeSystem.getMethodEntity(meth);

			assert meth.typeParameters().size() == 1;
			final Type typeParameter = meth.typeParameters().get(0);

			assert formals.size() == 0;

			final Type returnType = meth.returnType();
			final Type thisType = meth.flags().isStatic() ? null : owner;
			final MethodConstruction savedConstruction = codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
					returnType, thisType);

			MethodConstruction con = codeGenerator.getFirmConstruction();
			final Mode parMode = firmTypeSystem.getFirmMode(typeParameter);
			Node par = null;
			if(firmTypeSystem.isFirmStructType(typeParameter)) {
				final firm.Type firm_type = firmTypeSystem.asType(typeParameter);
				final firm.Type frameType = entity.getGraph().getFrameType();
				final Entity paramEntity = Entity.createParameterEntity(frameType, 0, firm_type);
				par = codeGenerator.getEntityFromCurrentFrame(paramEntity);
			} else {
				par = con.getVariable(0, parMode);
			}
			assert par != null;

			final firm.Type type = firmTypeSystem.asType(typeParameter);
			final Node mem = con.getCurrentMem();
			final Mode loadMode = type.getMode();
			final Node load = con.newLoad(mem, par, loadMode);
			final Node newMem = con.newProj(load, Mode.getM(), Load.pnM);
			final Node result = con.newProj(load, loadMode, Load.pnRes);
			con.setCurrentMem(newMem);
			final Node mem2 = con.getCurrentMem();
			final Node retNode = con.newReturn(mem2, new Node[]{result});
			assert retNode != null;
			con.getGraph().getEndBlock().addPred(retNode);
			con.setCurrentBlockBad();

			codeGenerator.finishConstruction(entity, savedConstruction);

			return true;
		}

		/**
		 * Returns the name of the method
		 */
		@Override
		public String getMethodName() {
			return "read";
		}
	}

	/**
	 *  Firm generator for the "write" method in x10.lang.Pointer
	 */
	static class GenWrite implements NativeGenericMethodGenerator {
		@Override
		public boolean gen(final FirmGenerator codeGenerator, final MethodInstance meth,
						   final List<LocalInstance> formals) {
			final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
			final X10ClassType owner = (X10ClassType)meth.container();
			final Entity entity = firmTypeSystem.getMethodEntity(meth);

			assert meth.typeParameters().size() == 1;
			final Type typeParameter = meth.typeParameters().get(0);

			assert formals.size() == 1;
			final LocalInstance val = formals.get(0);

			final Type returnType = meth.returnType();
			final Type thisType = meth.flags().isStatic() ? null : owner;
			final MethodConstruction savedConstruction = codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
					returnType, thisType);

			MethodConstruction con = codeGenerator.getFirmConstruction();
			final VarEntry var_val = con.getVarEntry(val);
			assert var_val != null;

			final Mode ptrMode = Mode.getP();
			final Node address = con.getVariable(0, ptrMode);

			if(firmTypeSystem.isFirmStructType(typeParameter)) {
				final firm.Type firm_type = firmTypeSystem.asType(typeParameter);
				final firm.Type frameType = entity.getGraph().getFrameType();
				final Entity paramEntity = Entity.createParameterEntity(frameType, var_val.getIdx(), firm_type);
				final Node asgn = codeGenerator.getEntityFromCurrentFrame(paramEntity);
				final Node mem = con.getCurrentMem();
				final Node copyB = con.newCopyB(mem, address, asgn, paramEntity.getType());
				final Node curMem = con.newProj(copyB, Mode.getM(), CopyB.pnM);
				con.setCurrentMem(curMem);
			} else {
				final Node asgn = con.getVariable(var_val.getIdx(), firmTypeSystem.getFirmMode(val.type()));
				final Node mem = con.getCurrentMem();
				final Node store = con.newStore(mem, address, asgn);
				final Node newMem = con.newProj(store, Mode.getM(), Store.pnM);
				con.setCurrentMem(newMem);
			}

			final Node mem = con.getCurrentMem();
			final Node retNode = con.newReturn(mem, new Node[]{});
			assert retNode != null;

			con.getGraph().getEndBlock().addPred(retNode);
			con.setCurrentBlockBad();

			codeGenerator.finishConstruction(entity, savedConstruction);

			return true;
		}

		/**
		 * Returns the name of the method
		 */
		@Override
		public String getMethodName() {
			return "write";
		}
	}

	/**
	 * Constructor
	 */
	public PointerGenerator() {
		addMethodGenerator(new GenRead());
		addMethodGenerator(new GenWrite());
	}

	/**
	 * Returns the dispatch name
	 */
	@Override
	public String getDispatchName() {
		return "x10.lang.Pointer";
	}
}
