#
#  This file is part of the X10 project (http://x10-lang.org).
#
#  This file is licensed to You under the Eclipse Public License (EPL);
#  You may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#      http://www.opensource.org/licenses/eclipse-1.0.php
#
#  (C) Copyright IBM Corporation 2006-2011.
#

X10C	?= x10c
X10J	?= x10j
X10	?= x10
PATH_SEP=$(if $(filter CYGWIN%, $(shell uname -s)),;,:)

all:	bin/XClass.class

bin-java/JClass.class:	src-java/JClass.java
	$(X10J) -d bin-java src-java/JClass.java

bin/XClass.class:	src/XClass.x10 bin-java/JClass.class
	$(X10C) -d bin -cp bin-java src/XClass.x10

run:	bin/XClass.class
	$(X10) -cp "bin$(PATH_SEP)bin-java" XClass

clean:
	rm -f bin-java/* bin/*
