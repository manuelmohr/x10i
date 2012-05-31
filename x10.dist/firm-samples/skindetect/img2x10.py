#!/usr/bin/python

from struct import *
from subprocess import call
import sys
from sys import stdout
from PIL import Image

if (len(sys.argv) <= 1):
	print "Usage: %s imagefile" % sys.argv[0]
	sys.exit(1)

img = Image.open(sys.argv[1])
width, height = img.size

call(["convert", sys.argv[1], "pic.rgb"])

cfile = 'static const char *data = "'
with open("pic.rgb", "rb") as f:
	byte = f.read(1)
	while byte != "":
		val = unpack('B', byte)[0]
		cfile += "\\%03o" % val
		byte = f.read(1)
cfile += "\";\nconst char *_ZN9ImageData7getDataEv()\n{\n\treturn data;\n}"
call(["rm", "-f", "pic.rgb"])
with open("image_data.c", "w") as f:
	f.write(cfile)
call(["gcc", "-m32", "-c", "image_data.c"])

x10file = "public class ImageData {\n\tpublic static val width = %d;\n\tpublic static val height = %d;\n\tpublic static native def getData(): Pointer;\n}" % (width, height)
with open("ImageData.x10", "w") as f:
	f.write(x10file)
