#!/usr/bin/env python
from jinja2 import Environment, Template
import sys

cmpOps = [ "==", "!=", "<", ">", "<=", ">=" ]
binOps = [ " + ", " - ", "*", "/" ]
intBinOps = binOps + [ "&", "|", "^", "%" ]
shiftOps = [ "<<", ">>", ">>>" ]
class Type(object):
	def __init__(self, name, mangled, ctype, size, signed,
	             binOps=intBinOps, unOps=["+", "-", "~"], cmpOps=cmpOps,
	             shiftOps=shiftOps, needsToString=True, needsParse=True,
	             movableBy=None, needsHashCode=True):
		self.name          = name
		self.mangled       = mangled
		self.ctype         = ctype
		self.size          = size
		self.signed        = signed
		self.cmpOps        = cmpOps
		self.binOps        = binOps
		self.unOps         = unOps
		self.shiftOps      = shiftOps
		self.needsHashCode = needsHashCode
		self.needsToString = needsToString
		self.needsParse    = needsParse
		self.movableBy     = movableBy
		self.coerceFrom    = []
		self.convertFrom   = []
	
opMangling = {
	"==":  "eq",
	"!=":  "ne",
	"<":   "lt",
	">":   "gt",
	"<=":  "le",
	">=":  "ge",
	"%":   "rm",
	"&":   "an",
	"|":   "or",
	"^":   "eo",
	"<<":  "ls",
	">>":  "rs",
	">>>": "v3rbs",
	" + ": "pl",
	" - ": "mi",
	"+":   "ps",
	"-":   "ng",
	"*":   "ml",
	"/":   "dv",
	"!":   "nt",
	"~":   "co",
}

intTypes = [
	Type("x10.lang.Byte",    "a",  "x10_byte",    8, True),
	Type("x10.lang.UByte",   "h",  "x10_ubyte",   8, False),
	Type("x10.lang.Short",   "s",  "x10_short",  16, True),
	Type("x10.lang.UShort",  "t",  "x10_ushort", 16, False),
	Type("x10.lang.Int",     "i",  "x10_int",    32, True),
	Type("x10.lang.UInt",    "j",  "x10_uint",   32, False),
	Type("x10.lang.Long",    "x",  "x10_long",   64, True),
	Type("x10.lang.ULong",   "y",  "x10_ulong",  64, False),
]
floatTypes = [
	Type("x10.lang.Float",   "f",  "x10_float",  32, True,
	     binOps=[" + ", " - ", "*", "/"], shiftOps=[], unOps=["+", "-"],
	     needsToString=False, needsParse=False, needsHashCode=False),
	Type("x10.lang.Double",  "d",  "x10_double", 64, True,
	     binOps=[" + ", " - ", "*", "/"], shiftOps=[], unOps=["+", "-"],
	     needsToString=False, needsParse=False, needsHashCode=False),
]
types = intTypes + floatTypes + [
	Type("x10.lang.Char",    "c",  "x10_char",    8, False,
	     binOps=[], shiftOps=[], unOps=[],
	     needsToString=False, needsParse=False, movableBy="x10.lang.Int"),
	Type("x10.lang.Pointer", "Pv", "x10_pointer", 0, False,
	     binOps=[], shiftOps=[], unOps=[],
	     needsToString=False, needsParse=False, movableBy="x10.lang.Int"),
	Type("x10.lang.Boolean", "b",  "x10_boolean", 1, False,
	     binOps=["&", "|", "^"], shiftOps=[], unOps=["!"], cmpOps=[],
	     needsToString=False, needsParse=False),
]
typedict = dict()
for type in types:
	typedict[type.name] = type
for type in types:
	if type.movableBy != None:
		type.movableBy = typedict[type.movableBy]

# initialize convert/coersion lists
for type in intTypes:
	type.convertFrom = []
	type.coerceFrom = []
	type.convertFrom += floatTypes
	for other in intTypes:
		if type == other:
			continue

		if other.size > type.size:
			type.convertFrom.append(other)
		elif other.size == type.size:
			type.convertFrom.append(other)
		else:
			type.coerceFrom.append(other)
for type in floatTypes:
	type.coerceFrom = intTypes
	for other in floatTypes:
		if type == other:
			continue
		if type.size < other.size:
			type.convertFrom.append(other)
		else:
			type.coerceFrom.append(other)
typedict["x10.lang.Char"].convertFrom = [
	typedict["x10.lang.Byte"],
	typedict["x10.lang.Short"],
	typedict["x10.lang.Int"],
	typedict["x10.lang.Long"],
]

def mangleNameElement(element):
	if element in opMangling:
		return opMangling[element]
	if element.startswith("$"):
		return element[1:]
	return str(len(element))+element

def mangleName(name):
	elements = name.split(".")
	return "N" + "".join(map(mangleNameElement, elements)) + "E"

def mangleType(type):
	if type in typedict:
		return typedict[type].mangled
	return "P" + mangleName(type)

def getUnsignedIntType(size):
	for t in types:
		if t.signed == False and t.size == size:
			return t
	raise "Couldn't find unsigned type with size " + size

env=Environment()

template = env.from_string(
'''/* Warning: automatically generated code */
#include "x10.h"
#include "x10_string.h"

static x10_char numerals[] = {
	T_('0'), T_('1'), T_('2'), T_('3'), T_('4'),
	T_('5'), T_('6'), T_('7'), T_('8'), T_('9'),
	T_('a'), T_('b'), T_('c'), T_('d'), T_('e'), T_('f')
};

{% for type in types %}
	{%- set xtype = type.name %}
	{%- set ctype = type.ctype %}
	{%- macro method(name) -%}
		_Z{{mangleName(type.name + "." + name)}}
		{%- for t in varargs -%}
			{{mangleType(t)}}
		{%- endfor -%}
	{%- endmacro %}

/* {{xtype}}.equals({{xtype}}):Boolean */
x10_boolean {{method("equals", xtype)}}({{ctype}} self, {{ctype}} other)
{
	return self == other;
}

{%- if type.needsHashCode %}

/* {{xtype}}.hashCode():Int */
x10_int {{method("hashCode")}}v({{ctype}} self)
{
	{%- if type.size <= typedict["x10.lang.Int"].size %}
	return (x10_int)self;
	{%- else %}
	return x10_hashCode((const unsigned char*)&self, sizeof(self));
	{%- endif %}
}
{%- endif %}

{%- if type.needsToString %}

/* {{xtype}}.toString(Int):String */
x10_string *{{method("toString", "x10.lang.Int")}}({{ctype}} self, x10_int radix)
{
	assert(radix >= 2);
	assert(radix <= (x10_int)ARRAY_SIZE(numerals));
	x10_char buf[21];
	{{ctype}} normalised = self;
	{%- if type.signed %}
	if (self < 0) {
		normalised = -self;
	}
	{%- endif %}
	x10_char *b = &buf[ARRAY_SIZE(buf)];
	do {
		*(--b) = numerals[normalised % radix];
		normalised /= radix;
	} while (normalised != 0);
	{%- if type.signed %}
	if (self < 0) {
		*(--b) = '-';
	}
	{%- endif %}
	return x10_string_from_cstring_len((buf+sizeof(buf)-b)/sizeof(buf[0]), b);
}
{%- endif %}

{%- if type.needsParse %}

/* {{xtype}}.parse(String,Int):{{xtype}} */
{{ctype}} {{method("parse", "x10.lang.String", "x10.lang.Int")}}(x10_string *string, x10_int radix)
{
	assert(radix >= 2);
	assert(radix <= 36);
	{{ctype}} result = 0;
	{{ctype}} dradix = ({{ctype}})radix;
	/* TODO: handle negative numbers... */
	for (x10_int i = 0; i < string->len; ++i) {
		x10_char c = string->chars[i];
		{{ctype}} digit_value;
		if (c >= T_('0') && c <= T_('9')) {
			digit_value = ({{ctype}})(c - T_('0'));
		} else if (c >= T_('a') && c <= T_('z')) {
			digit_value = ({{ctype}})(c - T_('a'));
		} else if (c >= T_('A') && c <= T_('Z')) {
			digit_value = ({{ctype}})(c - T_('A'));
		} else {
			x10_throw_exception_object(0);
		}
		if (digit_value > dradix)
			x10_throw_exception_object(0);
		result = result*dradix + digit_value;
	}
	return result;
}
{%- endif %}

{%- for op in type.cmpOps %}

/* {{xtype}}.operator {{op}}({{xtype}}):Boolean */
x10_boolean {{method(op, xtype)}}({{ctype}} self, {{ctype}} other)
{
	return self {{op}} other;
}
{%- endfor %}

{%- for op in type.binOps %}

/* {{xtype}}.operator {{op}}({{xtype}}):{{xtype}} */
{{ctype}} {{method(op, xtype)}}({{ctype}} self, {{ctype}} other)
{
	return self {{op}} other;
}
{%- endfor %}

{%- for op in type.unOps %}

/* {{xtype}}.operator {{op}}():{{xtype}} */
{{ctype}} {{method(op)}}v({{ctype}} self)
{
	return {{op}}self;
}
{%- endfor %}

{%- for op in type.shiftOps %}

/* {{xtype}}.operator {{op}}(Int):{{xtype}} */
{{ctype}} {{method(op, "x10.lang.Int")}}({{ctype}} self, x10_int count)
{
	{%- if op == ">>>" %}
	{%- if not type.signed %}
	return self >> count;
	{%- else %}
	return ({{ctype}})(({{getUnsignedIntType(type.size).ctype}})self >> count);
	{%- endif %}
	{%- else %}
	return self {{op}} count;
	{%- endif %}
}
{%- endfor %}

{%- if type.movableBy != None %}
	{%- set movable = type.movableBy %}

/* static {{xtype}}.operator ({{xtype}})+({{movable.name}}):{{xtype}} */
{{ctype}} {{method(" + ", xtype, movable.name)}}({{ctype}} a, {{movable.ctype}} b)
{
	return a + b;
}

/* static {{ctype}}.operator ({{xtype}})-({{movable.name}}):{{xtype}} */
{{ctype}} {{method(" - ", xtype, movable.name)}}({{ctype}} a, {{movable.ctype}} b)
{
	return a - b;
}

/* static {{ctype}}.operator ({{xtype}})-({{xtype}}):{{movable.name}} */
{{movable.ctype}} {{method(" - ", xtype, xtype)}}({{ctype}} a, {{ctype}} b)
{
	return a - b;
}
{%- endif %}

{%- for otype in type.coerceFrom %}

/* {{xtype}}.operator ({{otype.name}}):{{xtype}} */
{{ctype}} {{method("$cv"+type.mangled, otype.name)}}({{otype.ctype}} other)
{
	return other;
}
{%- endfor %}

{%- for otype in type.convertFrom %}

/* {{xtype}}.operator ({{otype.name}}) as {{xtype}} */
{{ctype}} {{method("$v" + str(len(type.mangled)+2) + "as" + type.mangled, otype.name)}}({{otype.ctype}} other)
{
	return ({{ctype}})other;
}
{%- endfor %}

{% endfor %}
''')

sys.stdout.write(template.render(
	types=types,
	intTypes=intTypes,
	mangleName=mangleName,
	mangleType=mangleType,
	typedict=typedict,
	getUnsignedIntType=getUnsignedIntType,
	len=len,
	str=str
	)
)
