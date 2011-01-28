
import SimpleLib;

interface IFace {
	public def interfaceMethod() : Void;
}

class Base {
	public def foo() : Void { SimpleLib.print(123); }
}

class Base2 extends Base {
	public def foo() : Void { SimpleLib.print(456); }
}

class Sub extends Base implements IFace {
	public def foo() : Void { SimpleLib.print(789); }
	public def interfaceMethod() : Void { SimpleLib.print(666); }
}

class DDispatch {
	public static def main(Array[String]) : Void {
		var inst : IFace = new Sub();
		inst.interfaceMethod();
		
		var inst2 : Base = new Base();
		inst2.foo();

		var inst3 : Base = new Base2();
		inst3.foo();

		var inst4 : Base = new Sub();
		inst4.foo();
	}
}
