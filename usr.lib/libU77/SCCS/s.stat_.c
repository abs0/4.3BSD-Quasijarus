h58966
s 00007/00001/00045
d D 5.1 85/06/07 23:28:36 kre 4 3
c Add copyright
e
s 00005/00001/00042
d D 1.3 83/04/30 17:07:02 dlw 3 2
c changed to use MAXPATHLEN. DLW
e
s 00003/00002/00040
d D 1.2 83/04/25 11:37:31 dlw 2 1
c modified for 4.2bsd. DLW
e
s 00042/00000/00000
d D 1.1 81/02/18 21:37:03 dlw 1 0
c date and time created 81/02/18 21:37:03 by dlw
e
u
U
t
T
I 1
/*
D 4
char id_stat[] = "%W%";
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
 *
I 4
 *	%W%	%G%
 */

/*
E 4
 * get file status
 *
 * calling sequence:
D 2
 *	integer stat, statb(11)
E 2
I 2
 *	integer stat, statb(12)
E 2
 *	call stat (name, statb)
 * where:
 *	'statb' will receive the stat structure for file 'name'.
 */

D 3
#include <sys/types.h>
E 3
I 3
#include <sys/param.h>
#ifndef	MAXPATHLEN
#define MAXPATHLEN	128
#endif
E 3
#include <sys/stat.h>
#include "../libI77/f_errno.h"

long stat_(name, stbuf, namlen)
char *name; long *stbuf, namlen;
{
D 2
	char buf[128];
E 2
I 2
D 3
	char buf[256];
E 3
I 3
	char buf[MAXPATHLEN];
E 3
E 2
	struct stat statb;

	if (namlen >= sizeof buf)
		return((long)(errno=F_ERARG));
	g_char(name, namlen, buf);
	if (stat(buf, &statb) == 0)
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
I 2
		*stbuf++ = statb.st_blksize;
E 2
		return(0L);
	}
	return ((long)errno);
}
E 1
