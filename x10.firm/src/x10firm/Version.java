package x10firm;

/**
 * Polyglot requires this class to specify the version of our extension.
 */
public class Version extends x10.Version {
	@Override
	public String name() {
		return "x10firm";
	}

	@Override
	public int major() {
		return 0;
	}

	@Override
	public int minor() {
		return 1;
	}

	@Override
	public int patch_level() {
		return 0;
	}
}
