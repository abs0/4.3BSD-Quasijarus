h58732
s 00007/00001/00052
d D 5.1 85/06/07 23:10:27 kre 4 3
c Add copyright
e
s 00005/00001/00048
d D 1.3 83/04/30 16:42:09 dlw 3 2
c changed to MAXPATHLEN. DLW
e
s 00003/00001/00046
d D 1.2 81/02/18 21:48:26 dlw 2 1
c added name len check, null name errno. DLW
e
s 00047/00000/00000
d D 1.1 81/02/11 21:50:29 dlw 1 0
c date and time created 81/02/11 21:50:29 by dlw
e
u
U
t
T
I 1
/*
D 4
char id_access[] = "%W%";
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
 * determine accessability of a file
 *
 * calling format:
 *	integer access
 *	ierror = access(filename, mode)
 * where:
 *	ierror will be 0 for successful access; an error number otherwise.
 *	filename is a character string
 *	mode is a character string which may include any combination of
 *	'r', 'w', 'x', ' '. (' ' => test for existence)
 */

#include "../libI77/f_errno.h"
I 3
#include <sys/param.h>
#ifndef	MAXPATHLEN
#define MAXPATHLEN	128
#endif
E 3

long access_(name, mode, namlen, modlen)
char *name, *mode;
long namlen, modlen;
{
D 3
	char buf[128];
E 3
I 3
	char buf[MAXPATHLEN];
E 3
	int m = 0;

I 2
	if (namlen >= sizeof buf)
		return((long)(errno=F_ERARG));
E 2
	g_char(name, namlen, buf);
	if (buf[0] == '\0')
D 2
		return((long)(errno=F_ERARG));
E 2
I 2
		return((long)(errno=ENOENT));
E 2
	if (access(buf, 0) < 0)
		return((long)errno);
	while (modlen--) switch(*mode++)
	{
		case 'x':
			m |= 1;
			break;

		case 'w':
			m |= 2;
			break;

		case 'r':
			m |= 4;
			break;
	}
	if (m > 0 && access(buf, m) < 0)
		return((long)errno);
	return(0L);
}
E 1
