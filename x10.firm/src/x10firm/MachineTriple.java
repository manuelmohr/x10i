package x10firm;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import polyglot.main.UsageError;

/**
 * A "machine-triple" is a triple describing a target or host machine
 * of a compiler. It is composed from cpu, manufacturer and operating system.
 */
public final class MachineTriple {
	private final String cpu;
	private final String manufacturer;
	private final String operatingSystem;
	private final String osVariant;

	/** Constructs a target triple from a triple string.
	 *
	 * @param triple A triple string such as "i686-apple-darwin", "sparc-unknown-linux-gnu"
	 * and the common "i686-linux-gnu" (which is misleading because linux-gnu is the
	 * operating system part).
	 */
	public MachineTriple(final String triple) throws UsageError {
		final Pattern pattern = Pattern.compile("([^-]+)-([^-]+)-(.+)");
		final Matcher matcher = pattern.matcher(triple);

		if (!matcher.matches())
			throw new UsageError("Invalid target triple: \"" + triple + "\"");

		int g = 1;
		cpu = matcher.group(g++);
		String newManufacturer = matcher.group(g++);
		String newOperatingSystem = matcher.group(g++);
		String newOSVariant = null;

		/** some people leave out the manufacturer, in combination with
		 * the "linux-gnu" operating system the parser gets confused and
		 * needs a special case here */
		if (newManufacturer.contains("linux")) {
			newOperatingSystem = newManufacturer + "-" + newOperatingSystem;
			newManufacturer = "unknown";
		} else if (newOperatingSystem.contains("octopos") || newOperatingSystem.contains("irtss")) {
			/* Support OctoPOS variants. */
			final int index = newOperatingSystem.indexOf('-');
			if (index != -1) {
				newOSVariant = newOperatingSystem.substring(index + 1);
				newOperatingSystem = newOperatingSystem.substring(0, index);
			}
		}

		manufacturer = newManufacturer;
		operatingSystem = newOperatingSystem;
		osVariant = newOSVariant;
	}

	/** Get CPU string. */
	public String getCpu() {
		return cpu;
	}

	/** Get instruction set architecture. */
	public String getIsa() {
		if (cpu.equals("i386") || cpu.equals("i486") || cpu.equals("i586") || cpu.equals("i686"))
			return "ia32";
		if (cpu.equals("x86_64"))
			return "amd64";
		return cpu;
	}

	/** Returns operating system part of the target triple. */
	public String getOS() {
		return operatingSystem;
	}

	/** Returns operating system variant. */
	public String getOSVariant() {
		return osVariant;
	}

	/** Returns manufacturer part of the target triple. */
	public String getManufacturer() {
		return manufacturer;
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
