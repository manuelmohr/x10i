public class SelfRefField {
	public var s : SelfRefField;

	public def setSelfRef() {
		s = this;
	}
}
