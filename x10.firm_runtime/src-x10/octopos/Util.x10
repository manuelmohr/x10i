package octopos;

import x10.compiler.LinkSymbol;

public class Util {
    @LinkSymbol("leon_get_noc_ts")
    public static native def getNocTimestamp(): ULong;

    private def this(): Util;
}
