This repository tracks a whole Eclipse workspace, since we need to track five projects at once.

== Prerequesties ==

* You should have eclipse 3.6.X (later is probably ok too)

== Git Submodules ==

The jFirm library is an external project. You should import it with git
submodules. Usually the following is enough:

	git submodule update --init

== Complete Build ==

cd x10.dist
ant

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

