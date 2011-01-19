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




== Tips for debugging Java in gdb ==
If you want to run java programs in gdb, then you should make sure that gdb ignores some unix signals that java reroutes and expects to receive. If gdb intercepts these the java program won't work.
The easy way to do this is to add this macro to your .gdbinit and start it before running any java programs. (We advice against this for non-java programs, since it hides most segfaults from gdb)

define javadebug
handle SIGUSR1 nostop noprint pass
handle SIGSEGV nostop noprint pass
handle SIGILL nostop noprint pass
handle SIGQUIT nostop noprint pass
end

