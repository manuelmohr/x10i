public class SelfRef {
	public var s : SelfRef;

	def this() {
		s = this;
	}
	def bar() = 42;
	def foo2() {
		return s.bar();
	}
}
