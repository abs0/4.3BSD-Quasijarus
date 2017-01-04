h60522
s 00007/00001/00045
d D 5.1 85/06/07 23:16:12 kre 4 3
c Add copyright
e
s 00002/00001/00044
d D 1.3 83/04/25 11:38:51 dlw 3 2
c modified for 4.2bsd. DLW
e
s 00001/00001/00044
d D 1.2 81/02/20 12:54:54 dlw 2 1
c fixed errno for bad unit to be F_ERUNIT. DLW
e
s 00045/00000/00000
d D 1.1 81/02/18 21:37:15 dlw 1 0
c date and time created 81/02/18 21:37:15 by dlw
e
u
U
t
T
I 1
/*
D 4
char id_fstat[] = "%W%";
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
D 3
 *	integer fstat, statb(11)
E 3
I 3
 *	integer fstat, statb(12)
E 3
 *	call fstat (name, statb)
 * where:
 *	'statb' will receive the stat structure for file 'name'.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include "../libI77/f_errno.h"
#include "../libI77/fiodefs.h"

extern unit units[];

long fstat_(lunit, stbuf)
long *lunit, *stbuf;
{
	struct stat statb;

	if (*lunit < 0 || *lunit >= MXUNIT)
D 2
		return((long)(errno=F_ERARG));
E 2
I 2
		return((long)(errno=F_ERUNIT));
E 2
	if (!units[*lunit].ufd)
		return((long)(errno=F_ERNOPEN));
	if (fstat(fileno(units[*lunit].ufd), &statb) == 0)
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
I 3
		*stbuf++ = statb.st_blksize;
E 3
		return(0L);
	}
	return ((long)errno);
}
E 1
