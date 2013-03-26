#include "types.h"
#include "array.h"
#include "main.h"
#include "x10_string.h"

#include <stdlib.h>
#include <string.h>
#include <dirent.h>

x10_object *_ZN3x102io4File10NativeFile4listEPN3x104lang6StringE(const x10_string *path)
{
	char *cpath = cstring_from_x10_string(path);
	DIR  *dir   = opendir(cpath);
	free(cpath);
	if (dir == NULL) {
		return _ZN3x105array5Array15makeStringArrayEPvi((x10_pointer) NULL, 0);
	}

	x10_string   **filenames = NEW_ARR_F(x10_string*, 0);
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		x10_string *name = x10_string_from_cstring(entry->d_name);
		ARR_APP1(x10_string*, filenames, name);
	}
	closedir(dir);

	const int   elems = ARR_LEN(filenames);
	x10_object *list  = _ZN3x105array5Array15makeStringArrayEPvi((x10_pointer)filenames, elems);

	return list;
}

/*
 * Stub implementations
 */
x10_boolean _ZN3x102io4File10NativeFile7canReadEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return false;
}

x10_boolean _ZN3x102io4File10NativeFile8canWriteEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return false;
}

x10_boolean _ZN3x102io4File10NativeFile6existsEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return false;
}

x10_boolean _ZN3x102io4File10NativeFile11isDirectoryEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return false;
}

x10_boolean _ZN3x102io4File10NativeFile6isFileEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return false;
}

x10_long _ZN3x102io4File10NativeFile12lastModifiedEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return 0L;
}

x10_long _ZN3x102io4File10NativeFile6lengthEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return 0L;
}

x10_boolean _ZN3x102io4File10NativeFile15setLastModifiedEPN3x104lang6StringEx(const x10_string *path, const x10_long v)
{
	(void) path;
	(void) v;
	return false;
}

x10_boolean _ZN3x102io4File10NativeFile6deleteEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return false;
}

x10_boolean _ZN3x102io4File10NativeFile5mkdirEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return false;
}

x10_boolean _ZN3x102io4File10NativeFile6mkdirsEPN3x104lang6StringE(const x10_string *path)
{
	(void) path;
	return false;
}

x10_boolean _ZN3x102io4File10NativeFile8renameToEPN3x104lang6StringEPN3x104lang6StringE(const x10_string *path, const x10_string *dest)
{
	(void) path;
	(void) dest;
	return false;
}
