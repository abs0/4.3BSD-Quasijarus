h36889
s 00007/00001/00040
d D 5.1 85/06/07 23:11:52 kre 3 2
c Add copyright
e
s 00005/00001/00036
d D 1.2 83/04/30 16:46:30 dlw 2 1
c changed to use MAXPATHLEN. DLW
e
s 00037/00000/00000
d D 1.1 83/04/16 22:31:59 dlw 1 0
c date and time created 83/04/16 22:31:59 by dlw
e
u
U
t
T
I 1
/*
D 3
char	id_chmod[]	= "%W%";
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
 * chmod - change file mode bits
 *
 * synopsis:
 *	integer function chmod (fname, mode)
 *	character*(*) fname, mode
 */

#include "../libI77/f_errno.h"
I 2
#include <sys/param.h>
#ifndef	MAXPATHLEN
#define MAXPATHLEN	128
#endif
E 2

long chmod_(name, mode, namlen, modlen)
char	*name, *mode;
long	namlen, modlen;
{
D 2
	char	nambuf[256];
E 2
I 2
	char	nambuf[MAXPATHLEN];
E 2
	char	modbuf[32];
	int	retcode;

	if (namlen >= sizeof nambuf || modlen >= sizeof modbuf)
		return((long)(errno=F_ERARG));
	g_char(name, namlen, nambuf);
	g_char(mode, modlen, modbuf);
	if (nambuf[0] == '\0')
		return((long)(errno=ENOENT));
	if (modbuf[0] == '\0')
		return((long)(errno=F_ERARG));
	if (fork())
	{
		if (wait(&retcode) == -1)
			return((long)errno);
		return((long)retcode);
	}
	else
		execl("/bin/chmod", "chmod", modbuf, nambuf, (char *)0);
}
E 1
