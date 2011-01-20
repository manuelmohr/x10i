interface IFace {
	public def interfaceMethod() : Void;
}

class Base {
	public def foo() : Void { }
}

class Sub extends Base implements IFace {
	public def foo() : Void { }
	public def interfaceMethod() : Void {}
}

class DDispatch {
	public static def main() : Void {
		var inst : IFace = new Sub();
		inst.interfaceMethod();
		
		var inst2 : Base = new Sub();
		inst2.foo();
	}
}
