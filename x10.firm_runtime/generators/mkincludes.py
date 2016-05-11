#!/usr/bin/env python
import sys
prefix = sys.argv[1]
files = sys.argv[2:]
files.sort()
for f in files:
	print("#include \"" + prefix + f + "\"")
