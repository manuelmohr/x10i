class SimpleCall {
	public native static def foo() : Void;

	public static def callFoo() : Void {
		foo();
	}
}
