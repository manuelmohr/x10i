
import SimpleLib;

interface IFace {
	public def interfaceMethod() : Void;
}

class Base {
	public val a : Int = 456;
	public def foo() : Void { val x: Int = 123; SimpleLib.print(a); }
}

class Base2 extends Base {
	public def foo() : Void { SimpleLib.print(456); }
}

class Sub extends Base implements IFace {
	public val a : Int = 1;
	public def foo() : Void { val x: Int = 123; SimpleLib.print(789); }
	public def interfaceMethod() : Void { val x: Int = 123; SimpleLib.print(a); }
}

class TestClass {
	public val a: Int = 789;
	public def doIt() : Void {  SimpleLib.print(a); }
}

class TestClass2 extends TestClass {
	public val b: Int = 2323;
	public def this() { SimpleLib.print(666); }
	public def doIt() : Void {  SimpleLib.print(a); }
}

class DDispatch {
	public static def main(Array[String]) : Void {
		
		var inst : IFace = new Sub();
		inst.interfaceMethod();
		
		var inst2 : Base = new Base();
		inst2.foo();
		
		if(inst2 instanceof IFace) {
			SimpleLib.print(6666666);
		} else {
			SimpleLib.print(7777777);
		}

		var test: TestClass = new TestClass();
		test.doIt();

		if(test instanceof TestClass2) {
			SimpleLib.print(-1);
		} else {
			SimpleLib.print(-2);
		}

		var test2: TestClass = new TestClass2();
		test2.doIt();
		

		var inst3 : Base = new Base2();
		inst3.foo();

		if(inst3 instanceof Any) {
			SimpleLib.print(33);
		} else {
			SimpleLib.print(55);
		}

		var inst4 : Base = new Sub();
		inst4.foo();

		if(inst4 instanceof Base) {
			SimpleLib.print(777);
		} else {
			SimpleLib.print(888);
		}
		
	}
}
