#include "types.h"
#include "adt/array.h"
#include "main.h"
#include "x10_string.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>

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

x10_string *_ZN3x102io4File10NativeFile6getCwdEv()
{
	char buf[512];
	const char *cwd = getcwd(buf, sizeof(buf));
	if (cwd == NULL) {
		return x10_string_from_cstring("");
	} else {
		return x10_string_from_cstring(cwd);
	}
}

x10_boolean _ZN3x102io4File10NativeFile7canReadEPN3x104lang6StringE(const x10_string *path)
{
	char *str    = cstring_from_x10_string(path);
	int   status = access(str, R_OK);
	free(str);
	return (x10_boolean)(status == 0);
}

x10_boolean _ZN3x102io4File10NativeFile8canWriteEPN3x104lang6StringE(const x10_string *path)
{
	char *str    = cstring_from_x10_string(path);
	int   status = access(str, W_OK);
	free(str);
	return (x10_boolean)(status == 0);
}

x10_boolean _ZN3x102io4File10NativeFile6existsEPN3x104lang6StringE(const x10_string *path)
{
	char *str    = cstring_from_x10_string(path);
	int   status = access(str, F_OK);
	free(str);
	return (x10_boolean)(status == 0);
}

x10_boolean _ZN3x102io4File10NativeFile11isDirectoryEPN3x104lang6StringE(const x10_string *path)
{
	struct stat info;
	char *str    = cstring_from_x10_string(path);
	int   status = stat(str, &info);
	free(str);
	return (x10_boolean)(status == 0 && S_ISDIR(info.st_mode));
}

x10_boolean _ZN3x102io4File10NativeFile6isFileEPN3x104lang6StringE(const x10_string *path)
{
	struct stat info;
	char *str    = cstring_from_x10_string(path);
	int   status = stat(str, &info);
	free(str);
	return (x10_boolean)(status == 0 && S_ISREG(info.st_mode));
}

x10_long _ZN3x102io4File10NativeFile12lastModifiedEPN3x104lang6StringE(const x10_string *path)
{
	struct stat info;
	char *str    = cstring_from_x10_string(path);
	int   status = stat(str, &info);
	free(str);
	return (x10_long)(status == 0 ? info.st_mtime : 0);
}

x10_long _ZN3x102io4File10NativeFile6lengthEPN3x104lang6StringE(const x10_string *path)
{
	struct stat info;
	char *str    = cstring_from_x10_string(path);
	int   status = stat(str, &info);
	free(str);
	return (x10_long)(status == 0 ? info.st_size : 0);
}

x10_boolean _ZN3x102io4File10NativeFile15setLastModifiedEPN3x104lang6StringEx(const x10_string *path, const x10_long v)
{
	struct stat info;
	char *str    = cstring_from_x10_string(path);
	int   status = stat(str, &info);
	if (status != 0)
		return (x10_boolean) false;
	struct utimbuf times;
	times.actime  = info.st_atime;
	times.modtime = v;
	status        = utime(str, &times);
	free(str);
	return (x10_boolean)(status == 0);
}

x10_boolean _ZN3x102io4File10NativeFile6deleteEPN3x104lang6StringE(const x10_string *path)
{
	char *str    = cstring_from_x10_string(path);
	int   status = remove(str);
	free(str);
	return (x10_boolean)(status == 0);
}

x10_boolean _ZN3x102io4File10NativeFile5mkdirEPN3x104lang6StringE(const x10_string *path)
{
	char *str    = cstring_from_x10_string(path);
	int   status = mkdir(str, 0755);
	free(str);
	return (x10_boolean)(status == 0);
}

x10_boolean _ZN3x102io4File10NativeFile8renameToEPN3x104lang6StringEPN3x104lang6StringE(const x10_string *path, const x10_string *dest)
{
	char *str    = cstring_from_x10_string(path);
	char *dstr   = cstring_from_x10_string(dest);
	int   status = rename(str, dstr);
	free(str);
	free(dstr);
	return (x10_boolean)(status == 0);
}
