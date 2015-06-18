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

Note: You should only need to do this once. At least if you just run x10firm
the eclipse rebuilding should be enough after the initial build here.

== Eclipse Import ==

1. It's probably best to create a new empty workspace for this.
2. click "File" -> "Import ..."
3. select "General" -> "Existing projects into workspace"
4. select current workspace as root directory (click "browse" and "ok" should be enough)
5. all projects should be selected (x10.common, x10.compiler, x10.constraints, x10.dist, x10.runtime, jFirm)
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

Also required is an executable called i686-invasic-irtss-gcc
(or similar depending on compilation target). You can probably
just create a symlink to the normal gcc executable. Just make
sure it is in your $PATH.

  ln -s /usr/bin/gcc i686-invasic-irtss-gcc

Within x10.dist compile via

	ant dist-firm -DTARGET=i686-invasic-irtss

Now you can use

  x10firm -mtarget=i686-invasic-irtss Foo.x10
