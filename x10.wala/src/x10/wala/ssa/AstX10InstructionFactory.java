package x10.wala.ssa;

import com.ibm.wala.cast.ir.ssa.AstLexicalAccess.Access;
import com.ibm.wala.cast.java.ssa.AstJavaInstructionFactory;
import com.ibm.wala.classLoader.CallSiteReference;
import com.ibm.wala.ssa.SSAInstruction;
import com.ibm.wala.types.TypeReference;

public interface AstX10InstructionFactory extends AstJavaInstructionFactory {
	AsyncInstruction AsyncInvoke(int iindex, int result, int[] params, int exception, CallSiteReference site, int[] clocks);
	AsyncInstruction AsyncInvoke(int iindex, int[] params, int exception, CallSiteReference site, int[] clocks);
	AsyncInstruction AsyncInvoke(int iindex, int[] results, int[] params, int exception, Access[] lexicalReads, Access[] lexicalWrites, CallSiteReference csr);
	AtomicInstruction Atomic(int iindex, boolean isEnter);
	FinishInstruction Finish(int iindex, boolean isEnter);
	NextInstruction Next(int iindex);
	HereInstruction Here(int iindex, int retValue);
	IterHasNextInstruction IterHasNext(int iindex, int hasNextValue, int regionIter);
	IterInitInstruction IterInit(int iindex, int iterVal, int regionVal);
	IterNextInstruction IterNext(int iindex, int nextValue, int regionIter);
	TupleInstruction Tuple(int iindex, int retValue, int[] slotValues);
	AtStmtInstruction AtStmt(int iindex, boolean isEnter);
}
