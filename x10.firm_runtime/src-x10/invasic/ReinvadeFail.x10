package invasic;

/** This Exception is thrown, if a reinvade operation fails,
  * such that the claim is not useable anymore.
  * For example, requiring exactly a million PEs fails on small architectures. */
public class ReinvadeFail extends Exception {
	public def this(msg:String) {
		super(msg);
	}
}
