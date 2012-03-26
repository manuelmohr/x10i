package x10firm;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import polyglot.main.UsageError;

/**
 * A "machine-triple" is a triple describing a target or host machine
 * of a compiler. It is composed from cpu, manufacturer and operating-system
 */
public final class MachineTriple {
	private final String cpu;
	private final String manufacturer;
	private final String operatingSystem;

	/** Constructs a target triple from a triple string.
	 *
	 * @param triple A triple string such as "i686-apple-darwin", "sparc-unknown-linux-gnu"
	 * and the common "i686-linux-gnu" (which is misleading because linux-gnu is the
	 * operatingsystem part)
	 */
	public MachineTriple(final String triple) throws UsageError {
		final Pattern pattern = Pattern.compile("([^-]+)-([^-]+)-(.+)");
		final Matcher matcher = pattern.matcher(triple);

		if (!matcher.matches())
			throw new UsageError("Invalid target triple: \"" + triple + "\"");

		cpu = matcher.group(1);
		String newManufacturer = matcher.group(2);
		String newOperatingSystem = matcher.group(3);

		/** some people leave out the manifacturere, in combination with
		 * the "linux-gnu" operating system the parser gets confused and
		 * needs a special case here */
		if (newManufacturer.contains("linux")) {
			newOperatingSystem = newManufacturer + "-" + newOperatingSystem;
			newManufacturer = "unknown";
		}
		this.manufacturer = newManufacturer;
		this.operatingSystem = newOperatingSystem;
	}

	/** Get CPU string. */
	public String getCpu() {
		return cpu;
	}

	/** Get instruction set architecture. */
	public String getIsa() {
		if (cpu.equals("i386") || cpu.equals("i486") || cpu.equals("i586") || cpu.equals("i686"))
			return "ia32";
		return cpu;
	}

	/** Returns operating system part of the target triple. */
	public String getOS() {
		return operatingSystem;
	}

	@Override
	public String toString() {
		if (manufacturer.equals("unknown"))
			return cpu + "-" + operatingSystem;
		return cpu + "-" + manufacturer + "-" + operatingSystem;
	}

	/** returns true if operating system is your typical
	 * unix variant. This mostly means POSIX available,
	 * and ELF object file format.
	 */
	public boolean isUnixishOS() {
		return operatingSystem.contains("linux")
				|| operatingSystem.equals("bsd")
				|| operatingSystem.equals("solaris");
	}

	/** returns true if operating system is a darwin
	 * variant. This mostly means Mach-O object file
	 * format and a "_" prefix to names.
	 */
	public boolean isDarwin() {
		return operatingSystem.startsWith("darwin");
	}

	/** returns true if operating system is a darwin
	 * variant. This mostly means COFF object file
	 * format and a "_" prefix to names.
	 */
	public boolean isWindowsOS() {
		return operatingSystem.equals("win32")
				|| operatingSystem.contains("mingw");
	}
}
