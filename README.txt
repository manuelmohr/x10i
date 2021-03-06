This repository tracks a whole Eclipse workspace, since we need to track five projects at once.

== Prerequisites ==

* You should have eclipse 3.6.X (later is probably ok too)
* A working gcc compiler
* apache-ant (1.8.x works, maybe also earlier versions)

== Initial build ==

There are somethings like initialising git submodules, and creating the x10
c++ class libraries which have to be performed at least once initially.
We put all this stuff into the setup.sh so running this should be enough to get you going:

  ./setup.sh
  cd x10.dist
  ant dist-firm

If you want to use OctoPOS/iRTSS see below for building that.

== Eclipse Import ==

Note: Eclipse is NOT NECESSARY to build and run x10i. It is useful,
if you want to change the Java code of x10i, though.

1. It's probably best to create a new empty workspace for this.
2. click "File" -> "Import ..."
3. select "General" -> "Existing projects into workspace"
4. select current workspace as root directory (click "browse" and "ok" should be enough)
5. select the projects: x10.common, x10.compiler, x10.constraints, x10.dist, jFirm, liboo (But not x10.wala, x10.runtime, x10.firm_runtime, they only give you errors)
6. click "Finish"

Now all projects should be imported into your Eclipse workspace.
The inter-project relationships should already be set correctly.

== Usage ==

After the build the x10.dist directory should hold a working x10 distribution.
This means executables in bin/ and library files in lib/.
For our Firm backend use bin/x10firm instead of bin/x10c or bin/x10c++.

Tip: "ant dist-firm" compiles everything necessary for x10firm without
     recompiling the x10c++, x10c parts


== Tips for debugging Java in gdb ==
If you want to run java programs in gdb, then you should make sure that gdb ignores some unix signals that java reroutes and expects to receive. If gdb intercepts these the java program won't work.
The easy way to do this is to add this macro to your .gdbinit and start it before running any java programs. (We advice against this for non-java programs, since it hides most segfaults from gdb)

define javadebug
handle SIGUSR1 nostop pass
handle SIGSEGV nostop pass
handle SIGILL nostop pass
handle SIGQUIT nostop pass
end

Tip2:
You can easily run x10firm in gdb like this:
JAVA="gdb --args java" x10firm ...

Tip3: Somehow the JVM manages to take control before a SIGABRT signal is sent
 from a failed assert in C code. So if you hit an assert and only see a broken
 backtrace, then instead create a breakpoint on the "abort" function and the
 debugger will stop early enough for you to see a meaningfull backtrace.

Tip4: If you are unlucky and have a SIGSEGV in the C code, then you should not
 use the "javadebug" macro from above but instead press "c" multiple times
 to skip all the java internal SIGSEGVs until you hit the SIGSEGV in the C
 code.

== AST Dumping ==
You can use -dump PASSNAME to dump the x10 ast after a specific pass (for
example "Desugarer"). Passnames can be in all the goals in the ExtensionInfo.

== OctoPOS Target ==

Requires octopos-app within this base directory.
Depending on what you do, you might have to create more symlinks
within octopos to choose the right release/variant/version.
Ultimately, building x10i requires the subdir:

  octopos-app/releases/current/x86guest/default/

Usually `current` and `default` are symlinks.
If they are missing or wrong, you will probably get an error
like a missing `stdio.h` with iRTSS.

Also required is an executable called i686-invasic-irtss-gcc
(or similar depending on compilation target). You can probably
just create a symlink to the normal gcc executable. Just make
sure it is in your $PATH.

  ln -s /usr/bin/gcc i686-invasic-irtss-gcc

Within x10.dist compile via

  ant dist-firm -DTARGET=i686-invasic-irtss

Now you can use

  x10firm -mtarget=i686-invasic-irtss Foo.x10

If you build iRTSS yourself and want to use a custom version,
you need to tell the build system about that.
You are then on your own to install iRTSS in the `octopos-app` directory.

  ant dist-firm -DTARGET=i686-invasic-irtss -DCUSTOM_IRTSS=true

== InvasIC Host Place Mode ==

When using InvasIC hardware, the FPGA is usually connected to a host
system.  When running a program on the FPGA, it is often useful to be able to
exchange data between host and FPGA (e.g., for visualization).

To this end, x10firm allows presenting the host as a special X10 place to the
programmer.  Hence, the programmer can use "at (Place.INVASIC_HOST) doStuff();"
to execute doStuff() on the host system.  This "at" has no special constraints,
i.e. it allows sending data to and receiving data from the host in the form of
regular X10 objects.  Sending data to the host works by capturing and using
the respective objects in the 'at' block; receiving data from host works by
using the 'at' in expression form and returning the respective objects.

Under the hood, this 'at' is handled specially and relays all data via the
ethernet interface.  Technically, this allows an X10 program to communicate
between a POSIX version and an OctoPOS version of the same program.  For
testing purposes, both versions can be x86 code (using the OctoPOS guest layer).
In production, the OctoPOS version will likely run on the FPGA.  Here, the X10
runtime transparently performs endianness conversion (see below).

How to use:
- If used with the FPGA, i.e. a SPARC binary, enable the define
  BIG_ENDIAN_SERIALIZATION in firm_runtime's Makefile first and recompile
  for the POSIX target.
- Compile X10 program twice:
    - Once for POSIX, e.g., target i686-linux-gnu
    - Once for OctoPOS, e.g., target sparc-invasic-octopos
      (or i686-invasic-octopos for testing)
- Start POSIX binary with "--invasicSystem $FPGA_IP".  For testing with the
  guest layer, most likely use "localhost"; for the FPGA the IP used to be
  192.168.0.100.
- Run OctoPOS binary, e.g., on FPGA.

Caveats:
- Compatibility with special form "at (E) async S" is not yet supported.
