h03361
s 00008/00001/00031
d D 5.1 85/06/07 23:21:01 kre 2 1
c Add copyright
e
s 00032/00000/00000
d D 1.1 83/04/23 10:46:01 dlw 1 0
c date and time created 83/04/23 10:46:01 by dlw
e
u
U
t
T
I 1
/*
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
 */

/*
E 2
 * hostnm - return this machines hostname
D 2
 *	%W%
E 2
 *
 * synopsis:
 *	integer function hostnm (name)
 *	character(*) name
 *
 * where:
 *	name	will receive the host name
 *	The returned value will be 0 if successful, an error number otherwise.
 */

extern int	errno;

long
hostnm_ (name, len)
char	*name;
long	len;
{
	char	buf[64];
	register char	*bp;
	int	blen	= sizeof buf;

	if (gethostname (buf, blen) == 0)
	{
		b_char (buf, name, len);
		return (0L);
	}
	else
		return((long)errno);
}
E 1
