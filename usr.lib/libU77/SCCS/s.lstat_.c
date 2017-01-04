h51098
s 00007/00001/00046
d D 5.1 85/06/07 23:24:16 kre 3 2
c Add copyright
e
s 00005/00001/00043
d D 1.2 83/04/30 17:07:58 dlw 2 1
c changed to use MAXPATHLEN. DLW
e
s 00044/00000/00000
d D 1.1 83/04/25 11:35:15 dlw 1 0
c date and time created 83/04/25 11:35:15 by dlw
e
u
U
t
T
I 1
/*
D 3
char id_stat[] = "%W%";
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
 *
I 3
 *	%W%	%G%
 */

/*
E 3
 * get file status
 *
 * calling sequence:
 *	integer lstat, statb(12)
 *	external lstat
 *	ierr = lstat (name, statb)
 * where:
 *	'statb' will receive the stat structure for file 'name'.
 */

D 2
#include <sys/types.h>
E 2
I 2
#include <sys/param.h>
#ifndef	MAXPATHLEN
#define MAXPATHLEN	128
#endif
E 2
#include <sys/stat.h>
#include "../libI77/f_errno.h"

long lstat_(name, stbuf, namlen)
char *name; long *stbuf, namlen;
{
D 2
	char buf[256];
E 2
I 2
	char buf[MAXPATHLEN];
E 2
	struct stat statb;

	if (namlen >= sizeof buf)
		return((long)(errno=F_ERARG));
	g_char(name, namlen, buf);
	if (lstat(buf, &statb) == 0)
	{
		*stbuf++ = statb.st_dev;
		*stbuf++ = statb.st_ino;
		*stbuf++ = statb.st_mode;
		*stbuf++ = statb.st_nlink;
		*stbuf++ = statb.st_uid;
		*stbuf++ = statb.st_gid;
		*stbuf++ = statb.st_rdev;
		*stbuf++ = statb.st_size;
		*stbuf++ = statb.st_atime;
		*stbuf++ = statb.st_mtime;
		*stbuf++ = statb.st_ctime;
		*stbuf++ = statb.st_blksize;
		return(0L);
	}
	return ((long)errno);
}
E 1
