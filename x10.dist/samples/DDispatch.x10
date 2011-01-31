
import SimpleLib;
/*
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
	public val a : Int = 123456;
	public def foo() : Void { val x: Int = 123; SimpleLib.print(789); }
	public def interfaceMethod() : Void { val x: Int = 123; SimpleLib.print(a); }
}
*/
class TestClass {
	public val a: Int = 456;
	public def doIt() : Void {  SimpleLib.print(a); }
}

class TestClass2 extends TestClass {
	public val b: Int = 2323;
	public def this() { SimpleLib.print(666); }
	public def doIt() : Void {  SimpleLib.print(a); }
}

class DDispatch {
	public static def main(Array[String]) : Void {
		/*
		var inst : IFace = new Sub();
		inst.interfaceMethod();
		*/
		/*
		var inst2 : Base = new Base();
		inst2.foo();
		*/

	//	var test: TestClass = new TestClass();
	//	test.doIt();

		var test2: TestClass = new TestClass2();
		test2.doIt();
		/*
		var inst3 : Base = new Base2();
		inst3.foo();

		var inst4 : Base = new Sub();
		inst4.foo();
		*/
	}
}
