h51055
s 00026/00000/00000
d D 5.1 85/07/14 17:24:21 eric 1 0
c date and time created 85/07/14 17:24:21 by eric
e
u
U
t
T
I 1
/*
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
**
**	%W% (Berkeley) %G%
*/

/*
**  Trace Package.
*/

typedef u_char	*TRACEV;

extern TRACEV	tTvect;			/* current trace vector */

# ifndef tTVECT
# define tTVECT		tTvect
# endif tTVECT

# define tTf(flag, level)	(tTVECT[flag] >= level)
# define tTlevel(flag)		(tTVECT[flag])
E 1
