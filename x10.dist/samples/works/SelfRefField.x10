public class SelfRefField {
	public var s : SelfRefField;

	public def this() {
		s = this;
	}
}
