package x10firm.visit.x10lib;

import java.util.Collections;
import java.util.List;

import polyglot.ast.FloatLit.Kind;
import polyglot.ast.IntLit;
import polyglot.ast.Return;
import polyglot.types.LocalInstance;
import polyglot.types.Type;
import polyglot.util.Position;
import x10.ast.X10NodeFactory_c;
import x10.types.MethodInstance;
import x10.types.X10ClassType;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.visit.FirmGenerator;
import firm.Entity;
import firm.nodes.Node;
import firm.nodes.OOConstruction;

public class ZeroGenerator extends NativeGenericDispatcher {

	/**
	 *  Support code for the getSize method in X10FirmSupport.x10
	 */
	static class GenGet implements NativeGenericMethodGenerator {

		@Override
		public boolean gen(final FirmGenerator codeGenerator, final MethodInstance meth,
						   final List<LocalInstance> formals) {
			/** Generation:
			 * switch(T) {
			 *    case isRef(T): return NULL;
			 *    case isBoolean(T): return false;
			 *    case isChar(T): return '0';
			 *    case isOtherPrimitiveType(T): return (T)0;
			 *    default: // must be a struct
			 *       T tmp; memset(T); return tmp;
			 * }
			 */
			final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
			final GenericTypeSystem x10TypeSystem = codeGenerator.getX10TypeSystem();
			final X10NodeFactory_c xnf = codeGenerator.getNodeFactory();
			final X10ClassType owner = (X10ClassType)meth.container();
			final Entity entity = firmTypeSystem.getMethodEntity(meth);

			assert(meth.typeParameters().size() == 1);
			final Type typeParameter = meth.typeParameters().get(0);

			final OOConstruction savedConstruction = codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
					meth.flags(), meth.returnType(), owner);

			final Position pos = Position.COMPILER_GENERATED;

			Return ret = null;
			boolean isStruct = false;
			if(x10TypeSystem.isRefType(typeParameter)) {
				ret = xnf.Return(pos, xnf.NullLit(pos).type(x10TypeSystem.Null()));
			} else if(x10TypeSystem.isBoolean(typeParameter)) {
				ret = xnf.Return(pos, xnf.BooleanLit(pos, false).type(x10TypeSystem.Boolean()));
			} else if(x10TypeSystem.isChar(typeParameter)) {
				ret = xnf.Return(pos, xnf.CharLit(pos, '0').type(x10TypeSystem.Char()));
			} else if(firmTypeSystem.isFirmPrimitiveType(typeParameter)) {
				if(x10TypeSystem.isByte(typeParameter)) {
					ret = xnf.Return(pos, xnf.IntLit(pos, IntLit.BYTE, 0).type(x10TypeSystem.Byte()));
				} else if(x10TypeSystem.isUByte(typeParameter)) {
					ret = xnf.Return(pos, xnf.IntLit(pos, IntLit.UBYTE, 0).type(x10TypeSystem.UByte()));
				} else if(x10TypeSystem.isShort(typeParameter)) {
					ret = xnf.Return(pos, xnf.IntLit(pos, IntLit.SHORT, 0).type(x10TypeSystem.Short()));
				} else if(x10TypeSystem.isUShort(typeParameter)) {
					ret = xnf.Return(pos, xnf.IntLit(pos, IntLit.USHORT, 0).type(x10TypeSystem.UShort()));
				} else if(x10TypeSystem.isInt(typeParameter)) {
					ret = xnf.Return(pos, xnf.IntLit(pos, IntLit.INT, 0).type(x10TypeSystem.Int()));
				} else if(x10TypeSystem.isUInt(typeParameter)) {
					ret = xnf.Return(pos, xnf.IntLit(pos, IntLit.UINT, 0).type(x10TypeSystem.UInt()));
				}  else if(x10TypeSystem.isLong(typeParameter)) {
					ret = xnf.Return(pos, xnf.IntLit(pos, IntLit.LONG, 0).type(x10TypeSystem.Long()));
				} else if(x10TypeSystem.isULong(typeParameter)) {
					ret = xnf.Return(pos, xnf.IntLit(pos, IntLit.ULONG, 0).type(x10TypeSystem.ULong()));
				} else if(x10TypeSystem.isFloat(typeParameter)) {
					ret = xnf.Return(pos, xnf.FloatLit(pos, Kind.FLOAT, 0.0).type(x10TypeSystem.Float()));
				} else if(x10TypeSystem.isDouble(typeParameter)) {
					ret = xnf.Return(pos, xnf.FloatLit(pos, Kind.DOUBLE, 0.0).type(x10TypeSystem.Double()));
				} else if(x10TypeSystem.isFirmPointer(typeParameter)) {
					ret = xnf.Return(pos, xnf.NullLit(pos).type(x10TypeSystem.Null()));
				} else {
					assert false : "Missing type check";
				}
			} else {
				// must be a struct
				// allocate a new struct type and return it.
				// TODO: Add memset call
				isStruct = true;
				final Node tmp = codeGenerator.genStackAlloc(typeParameter);
				OOConstruction con = codeGenerator.getFirmConstruction();
				final Node mem = con.getCurrentMem();
				final Node retNode = tmp != null ? con.newReturn(mem, new Node[]{tmp}) : con.newReturn(mem, new Node[]{});
				assert(retNode != null);

				con.getGraph().getEndBlock().addPred(retNode);
				con.setCurrentBlockBad();
			}

			if(!isStruct) {
				assert(ret != null);
				codeGenerator.visitAppropriate(ret);
			}

			codeGenerator.finishConstruction(entity, savedConstruction);

			return true;
		}

		/**
		 * Returns the name of the method
		 */
		@Override
		public String getMethodName() {
			return "get";
		}
	}

	/**
	 * Constructor
	 */
	public ZeroGenerator() {
		addMethodGenerator(new GenGet());
	}

	/**
	 * Returns the dispatch name
	 */
	@Override
	public String getDispatchName() {
		return "Zero";
	}
}