/*
 * Created on Sep 26, 2005
 */
package x10.wala.translator;

import java.util.Map;

import x10.wala.classLoader.AsyncCallSiteReference;
import x10.wala.loader.X10SourceLoaderImpl;
import x10.wala.ssa.AstX10InstructionFactory;
import x10.wala.translator.X10toCAstTranslator.AsyncEntity;
import x10.wala.translator.X10toCAstTranslator.ClosureBodyEntity;
import x10.wala.translator.X10toCAstTranslator.TypeDeclarationCAstEntity;
import x10.wala.tree.X10CAstEntity;
import x10.wala.tree.X10CastNode;
import x10.wala.tree.visit.X10DelegatingCAstVisitor;

import com.ibm.wala.cast.ir.translator.AstTranslator;
import com.ibm.wala.cast.ir.translator.AstTranslator.AstLexicalInformation;
import com.ibm.wala.cast.ir.translator.AstTranslator.RootContext;
import com.ibm.wala.cast.ir.translator.AstTranslator.WalkContext;
import com.ibm.wala.cast.java.loader.JavaSourceLoaderImpl;
import com.ibm.wala.cast.java.translator.JavaCAst2IRTranslator;
import com.ibm.wala.cast.java.types.JavaPrimitiveTypeMap;
import com.ibm.wala.cast.loader.AstMethod.DebuggingInformation;
import com.ibm.wala.cast.tree.CAstEntity;
import com.ibm.wala.cast.tree.CAstNode;
import com.ibm.wala.cast.tree.CAstType;
import com.ibm.wala.cast.tree.visit.CAstVisitor;
import com.ibm.wala.cfg.AbstractCFG;
import com.ibm.wala.cfg.IBasicBlock;
import com.ibm.wala.classLoader.ModuleEntry;
import com.ibm.wala.classLoader.NewSiteReference;
import com.ibm.wala.classLoader.SourceFileModule;
import com.ibm.wala.ssa.SymbolTable;
import com.ibm.wala.types.Descriptor;
import com.ibm.wala.types.MethodReference;
import com.ibm.wala.types.TypeName;
import com.ibm.wala.types.TypeReference;
import com.ibm.wala.util.debug.Assertions;
import com.ibm.wala.util.strings.Atom;

/**
 * Relevant commit that causes compile errors - move of setValue to Context object:
 * 
 * commit 4c6d062dbb385a05887c5a9e37b30b3b285d77b6
Author: dolby-oss <dolby-oss@f5eafffb-2e1d-0410-98e4-8ec43c5233c4>
Date:   Fri Jan 27 20:15:33 2012 +0000

    blunt force trauma to CAst frond end:
    1) Structural changes in the AstTranslator to allow retranslation and generation of custom IR.  This is mostly moving state from the translator itself into the context.
    2) Some refactoring to share some AST generation code across the Java and JavaScript front ends.
    3) Switching to the latest Rhino, release 1.7R3; this is a pervasive change to the JavaScript Rhino translator, since it involves switching to the new AST interface in Rhino.
    4) Common code to, as an option, translate Do-style loops by replicating the loop body.  This allows the use of CAstNode.LOOP forms for such loops.
    5) Some bug fixes to the mechanisms of the CAstRewriter to handle weird control flow cases.
    6) An example of retranslation to specialize JavaScript methods based on how many arguments they receive at call sites.
    
    
    git-svn-id: https://wala.svn.sourceforge.net/svnroot/wala/trunk@4425 f5eafffb-2e1d-0410-98e4-8ec43c5233c4

M   com.ibm.wala.cast/source/java/com/ibm/wala/cast/ir/translator/AstTranslator.java

 * 
 *
 */
public class X10CAst2IRTranslator extends X10DelegatingCAstVisitor<WalkContext> /* implements ArrayOpHandler */ {
	
	private static class X10JavaCAst2IRTranslator extends JavaCAst2IRTranslator {

		protected final X10SourceLoaderImpl x10Loader;
		private final ModuleEntry entry;
		private final CAstEntity sourceFileEntity;
	    
		private X10JavaCAst2IRTranslator(ModuleEntry entry, CAstEntity sourceFileEntity, JavaSourceLoaderImpl loader) {
			super(entry, sourceFileEntity, loader);
			x10Loader = (X10SourceLoaderImpl) loader;
			this.entry = entry;
			this.sourceFileEntity = sourceFileEntity;
		}
		
		public void translate(X10CAst2IRTranslator translator) {
			translator.translate(sourceFileEntity, entry);
		}

		/* (non-Javadoc)
		 * @see com.ibm.wala.cast.ir.translator.AstTranslator#doLexicallyScopedRead(com.ibm.wala.cast.tree.CAstNode, com.ibm.wala.cast.ir.translator.AstTranslator.WalkContext, java.lang.String)
		 *
		 * Ugly hack to allow code in this class to see this protected method, since it is now declared in this
		 * package in this subclass.
		 */
		@Override
		protected int doLexicallyScopedRead(CAstNode node, WalkContext context, String name) {
			return super.doLexicallyScopedRead(node, context, name);
		}

        @Override
        protected void defineFunction(CAstEntity n,
                      WalkContext definingContext,
                      AbstractCFG cfg,
                      SymbolTable symtab,
                      boolean hasCatchBlock,
                      Map<IBasicBlock,TypeReference[]> caughtTypes,
                      boolean hasMonitorOp,
                      AstLexicalInformation lexicalInfo,
                      DebuggingInformation debugInfo) {
            if (n.getKind() == X10CAstEntity.ASYNC_BODY) {
                x10Loader.defineAsync(n,
                        asyncTypeReference(x10Loader, n),
                        n.getPosition(), definingContext, cfg, symtab, hasCatchBlock, caughtTypes,
                        hasMonitorOp, lexicalInfo, debugInfo);
            } else if (n.getKind() == X10CAstEntity.CLOSURE_BODY) {
                x10Loader.defineClosure(n,
                        closureTypeReference(x10Loader, n),
                        n.getPosition(), definingContext, cfg, symtab, hasCatchBlock, caughtTypes,
                        hasMonitorOp, lexicalInfo, debugInfo);
            } else
                super.defineFunction(n, definingContext, cfg, symtab, hasCatchBlock, caughtTypes, hasMonitorOp, lexicalInfo, debugInfo);
        }
    }

    public X10CAst2IRTranslator(ModuleEntry entry, CAstEntity sourceFileEntity, X10SourceLoaderImpl loader) {
        this(new X10JavaCAst2IRTranslator(entry, sourceFileEntity, loader));
    }

    private final X10JavaCAst2IRTranslator translator;

    private final AstX10InstructionFactory insts;
    
    private X10CAst2IRTranslator(X10JavaCAst2IRTranslator translator) {
        super(translator);
        this.translator = translator;
//        this.translator.setArrayOpHandler(this);
        this.insts = (AstX10InstructionFactory) translator.loader().getInstructionFactory();
    }

    protected void leaveFunctionExpr(CAstNode n, WalkContext c, CAstVisitor visitor) {
        int result;
        CAstEntity fn= (CAstEntity) n.getChild(0).getValue();

        if (fn.getKind() == X10CAstEntity.ASYNC_BODY)
            result= processAsyncExpr(n, c);
        else if (fn.getKind() == X10CAstEntity.CLOSURE_BODY)
            result= processClosureExpr(n, c);
        else {
            Assertions.UNREACHABLE("FUNCTION_EXPR neither async nor closure in leaveFunctionExpr().");
            return;
        }
        c.setValue(n, result);
    }

    private int processAsyncExpr(CAstNode n, WalkContext c) {
        WalkContext context= (WalkContext) c;
        CAstEntity fn= (CAstEntity) n.getChild(0).getValue();
        int result= context.currentScope().allocateTempValue();
        int ex= context.currentScope().allocateTempValue();
        doMaterializeAsync(context, result, ex, fn);
        return result;
    }

    private void doMaterializeAsync(WalkContext context, int result, int ex, CAstEntity fn) {
        TypeReference asyncRef= asyncTypeReference(fn);

        context.cfg().addInstruction(insts.NewInstruction(context.cfg().getCurrentInstruction(), result,
                NewSiteReference.make(context.cfg().getCurrentInstruction(), asyncRef)));
    }

    private int processClosureExpr(CAstNode n, Context c) {
        WalkContext context= (WalkContext) c;
        CAstEntity fn= (CAstEntity) n.getChild(0).getValue();
        int result= context.currentScope().allocateTempValue();
        int ex= context.currentScope().allocateTempValue();
        doMaterializeClosure(context, result, ex, fn);
        return result;
    }

    private void doMaterializeClosure(WalkContext context, int result, int ex, CAstEntity fn) {
        TypeReference closureRef= closureTypeReference(fn);

        context.cfg().addInstruction(insts.NewInstruction(context.cfg().getCurrentInstruction(), result,
                NewSiteReference.make(context.cfg().getCurrentInstruction(), closureRef)));
    }

    private static TypeReference asyncTypeReference(JavaSourceLoaderImpl loader, CAstEntity fn) {
        return TypeReference.findOrCreate(loader.getReference(), "LA" + fn.getName());
    }

    private TypeReference asyncTypeReference(CAstEntity fn) {
        return asyncTypeReference(translator.loader(), fn);
    }

    public MethodReference asyncEntityToMethodReference(CAstEntity asyncEntity) {
        CAstType.Method bodyType= (CAstType.Method) asyncEntity.getType();
        CAstType retType= bodyType.getReturnType();
//      CAstType owningType= bodyType.getDeclaringType();
//      JavaSourceLoaderImpl fLoader = translator.loader();

        Atom asyncName= Atom.findOrCreateUnicodeAtom(asyncEntity.getName());
        Descriptor asyncDesc= Descriptor.findOrCreate(null, TypeName.string2TypeName(retType.getName()));
        // RMF 1/12/07 - Type ref must agree with what's used when the async type is defined!
        // The following commented-out version didn't do that...
//      TypeReference owningTypeRef= TypeReference.findOrCreate(fLoader.getReference(), TypeName.string2TypeName(owningType.getName()));
        TypeReference owningTypeRef= asyncTypeReference(asyncEntity);

        return MethodReference.findOrCreate(owningTypeRef, asyncName, asyncDesc);
    }

    protected boolean visitAsyncBodyEntity(CAstEntity n, WalkContext context, WalkContext codeContext, CAstVisitor visitor) {
        translator.initFunctionEntity(n, context, codeContext);
        return false;
    }
    protected void leaveAsyncBodyEntity(CAstEntity n, WalkContext context, WalkContext codeContext, CAstVisitor visitor) {
        translator.closeFunctionEntity(n, context, codeContext);
    }

    protected boolean visitAsyncInvoke(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveAsyncInvoke(CAstNode n, WalkContext c, CAstVisitor visitor) {
        CAstEntity bodyEntity = (CAstEntity) n.getChild(n.getChildCount()-1).getChild(0).getValue();
        
        // Figure out whether this is a future or an async
        int exceptValue = c.currentScope().allocateTempValue();
        AsyncCallSiteReference acsr = new AsyncCallSiteReference(asyncEntityToMethodReference(bodyEntity), c.cfg().getCurrentInstruction());
        int rcvrValue = c.getValue(n.getChild(n.getChildCount()-1));
        int clockValues[] = new int[ n.getChildCount() - 1];
        for(int i = 0; i < clockValues.length; i++) {
            clockValues[i] = c.getValue(n.getChild(i));
        }

        if (((CAstType.Function) bodyEntity.getType()).getReturnType() == JavaPrimitiveTypeMap.VoidType)
            c.cfg().addInstruction(insts.AsyncInvoke(c.cfg().getCurrentInstruction(), new int[] { rcvrValue }, exceptValue, acsr, clockValues));
        else {
            int retValue = c.currentScope().allocateTempValue();

            c.cfg().addInstruction(insts.AsyncInvoke(c.cfg().getCurrentInstruction(), retValue, new int[] { rcvrValue }, exceptValue, acsr, clockValues));
            c.setValue(n, retValue);
        }
    }

    private static TypeReference closureTypeReference(JavaSourceLoaderImpl loader, CAstEntity fn) {
        return TypeReference.findOrCreate(loader.getReference(), "Lclosure" + fn.getPosition());
    }

    private TypeReference closureTypeReference(CAstEntity fn) {
        return closureTypeReference(translator.loader(), fn);
    }

    protected boolean visitClosureBodyEntity(CAstEntity n, WalkContext context, WalkContext codeContext, CAstVisitor visitor) {
        translator.initFunctionEntity(n, context, codeContext);
        return false;
    }
    protected void leaveClosureBodyEntity(CAstEntity n, WalkContext context, WalkContext codeContext, CAstVisitor visitor) {
        translator.closeFunctionEntity(n, context, codeContext);
    }

    protected boolean visitAtomicEnter(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveAtomicEnter(CAstNode n, WalkContext c, CAstVisitor visitor) {
        c.cfg().addInstruction(insts.Atomic(c.cfg().getCurrentInstruction(), true));
    }
    protected boolean visitAtomicExit(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveAtomicExit(CAstNode n, WalkContext c, CAstVisitor visitor) {
        c.cfg().addInstruction(insts.Atomic(c.cfg().getCurrentInstruction(), false));
    }
    protected boolean visitFinishEnter(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveFinishEnter(CAstNode n, WalkContext c, CAstVisitor visitor) {
        c.cfg().addInstruction(insts.Finish(c.cfg().getCurrentInstruction(), true));
    }
    protected boolean visitFinishExit(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveFinishExit(CAstNode n, WalkContext c, CAstVisitor visitor) {
        WalkContext context = (WalkContext)c;
        context.cfg().addInstruction(insts.Finish(context.cfg().getCurrentInstruction(), false));
    }
    
    
    protected boolean visitNext(CAstNode n, WalkContext c, CAstVisitor visitor) {
        WalkContext context = (WalkContext)c;
        context.cfg().addInstruction(insts.Next(context.cfg().getCurrentInstruction()));
        return true;
    }
    
    protected boolean visitIterInit(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveIterInit(CAstNode n, WalkContext c, CAstVisitor visitor) {
        WalkContext context = (WalkContext)c;
        int targetValue = c.getValue(n.getChild(0));
        int retValue = context.currentScope().allocateTempValue();
        context.cfg().addInstruction(insts.IterInit(context.cfg().getCurrentInstruction(), retValue, targetValue));
        c.setValue(n, retValue);
    }
    protected boolean visitIterHasNext(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveIterHasNext(CAstNode n, WalkContext c, CAstVisitor visitor) {
        WalkContext context = (WalkContext)c;
        int targetValue = c.getValue(n.getChild(0));
        int retValue = context.currentScope().allocateTempValue();
        context.cfg().addInstruction(insts.IterHasNext(context.cfg().getCurrentInstruction(), retValue, targetValue));
        c.setValue(n, retValue);
    }
    protected boolean visitIterNext(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveIterNext(CAstNode n, WalkContext c, CAstVisitor visitor) {
        WalkContext context = (WalkContext)c;
        int targetValue = c.getValue(n.getChild(0));
        int retValue = context.currentScope().allocateTempValue();
        context.cfg().addInstruction(insts.IterNext(context.cfg().getCurrentInstruction(), retValue, targetValue));
        c.setValue(n, retValue);
    }
    protected boolean visitHere(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveHere(CAstNode n, WalkContext c, CAstVisitor visitor) {
        WalkContext context = (WalkContext)c;
        int retValue = context.currentScope().allocateTempValue();
        context.cfg().addInstruction(insts.Here(context.cfg().getCurrentInstruction(), retValue));
        c.setValue(n, retValue);
    }

    protected void leaveThis(CAstNode n, WalkContext c, CAstVisitor visitor) {
    	WalkContext context = (WalkContext)c;
    	CAstEntity entity = context.top();
    	if (entity instanceof AsyncEntity || entity instanceof ClosureBodyEntity) {
    		c.setValue(n, translator.doLexicallyScopedRead(n, context, "this"));
    	} else {
    		super.leaveThis(n, c, visitor);
    	}
    }
    
    protected boolean visitTupleExpr(CAstNode n, WalkContext c, CAstVisitor visitor) { /* empty */ return false; }
    protected void leaveTupleExpr(CAstNode n, WalkContext c, CAstVisitor visitor) {
        WalkContext context = (WalkContext)c;
        int retValue = context.currentScope().allocateTempValue();
        int slotValues[] = new int[n.getChildCount() - 1];
        for(int i = 0; i < slotValues.length; i++) {
            slotValues[i] = context.getValue(n.getChild(i+1));
        }
        context.cfg().addInstruction(insts.Tuple(context.cfg().getCurrentInstruction(), retValue, slotValues));
        context.setValue(n, retValue);
    }
    
    protected boolean visitAtStmtEnter(final CAstNode node, final WalkContext context, final CAstVisitor visitor) {
      context.cfg().addInstruction(insts.AtStmt(context.cfg().getCurrentInstruction(), true));
      return true;
    }
    
    protected boolean visitAtStmtExit(final CAstNode node, final WalkContext context, final CAstVisitor visitor) {
      context.cfg().addInstruction(insts.AtStmt(context.cfg().getCurrentInstruction(), false));
      return true;
    }
    
    protected boolean visitTypeEntity(final CAstEntity node, final WalkContext context, final WalkContext typeContext, 
                                      final CAstVisitor visitor) {
      // We avoid type declarations in _.x10 file.
      if (node instanceof TypeDeclarationCAstEntity) {
        return true;
      } else {
        return super.visitTypeEntity(node, context, typeContext, visitor);
      }
    }

    public void translate(final CAstEntity N, final ModuleEntry module) {
//    private void translate(final CAstEntity N, final String nm) {
        if (AstTranslator.DEBUG_TOP)
            System.err.println("translating " + N);
//      PrintWriter printWriter= new PrintWriter(System.out);
//      X10CAstPrinter.printTo(N, printWriter);
//      printWriter.flush();
        visitEntities(N, translator.new RootContext(N, module), this);
    }

    /* UGH! */
    public void translate() {
        translator.translate(this);
    }
    
    public JavaCAst2IRTranslator getCAst2IRTranslator() {
        return translator;
    }

    /**
     * Returns true if the given array reference operation indexes using an x10.lang.point,
     * rather than an array of ints (as in ordinary Java)
     */
    private boolean isRefByPoint(CAstNode arrayRefNode) {
        return arrayRefNode.getChildCount() > 3 || // if there are multiple indices, it's not by point
            arrayRefNode.getKind() == X10CastNode.ARRAY_REF_BY_POINT;
    }
/*
    public void doArrayRead(WalkContext context, int result, int arrayValue, CAstNode arrayRefNode, int[] dimValues) {
        TypeReference arrayTypeRef= (TypeReference) arrayRefNode.getChild(1).getValue();

        if (isRefByPoint(arrayRefNode))
            context.cfg().addInstruction(
                    insts.ArrayLoadByPoint(result, arrayValue, dimValues[0], arrayTypeRef));
        else
            context.cfg().addInstruction(
                    insts.ArrayLoadByIndex(result, arrayValue, dimValues, arrayTypeRef));
    }

    public void doArrayWrite(WalkContext context, int arrayValue, CAstNode arrayRefNode, int[] dimValues, int rval) {
        TypeReference arrayTypeRef =
            arrayRefNode.getKind() == CAstNode.ARRAY_LITERAL ?
                    ((TypeReference) arrayRefNode.getChild(0).getChild(0).getValue()).getArrayElementType() :
                     (TypeReference) arrayRefNode.getChild(1).getValue();

        if (isRefByPoint(arrayRefNode))
            context.cfg().addInstruction(
                    insts.ArrayStoreByPoint(arrayValue, dimValues[0], rval, arrayTypeRef));
        else
            context.cfg().addInstruction(
                    insts.ArrayStoreByIndex(arrayValue, dimValues, rval, arrayTypeRef));
    }
*/
    @Override
    protected boolean doVisitAssignNodes(CAstNode n, WalkContext context, CAstNode v, CAstNode a, CAstVisitor visitor) {
        int NT = a.getKind();
        boolean assign = NT == CAstNode.ASSIGN;
        boolean preOp = NT == CAstNode.ASSIGN_PRE_OP;
        if (n.getKind() == X10CastNode.ARRAY_REF_BY_POINT) {
            doVisitArrayRefNode(n, v, a, assign, preOp, context, visitor);
            return true;
        } else {
            return false;
        }
    }
}
