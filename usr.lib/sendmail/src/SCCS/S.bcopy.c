h54738
s 00014/00002/00050
d D 5.1 85/06/07 14:28:52 dist 11 10
m 
c Add copyright
e
s 00023/00002/00029
d D 4.2 84/08/11 16:58:18 eric 10 9
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00000/00000/00031
d D 4.1 83/07/25 19:42:50 eric 9 8
m 
c 4.2 release version
e
s 00001/00000/00030
d D 3.4 82/05/31 18:48:02 eric 8 7
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00022/00001/00008
d D 3.3 81/12/06 12:37:17 eric 7 6
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00001/00001/00008
d D 3.2 81/09/06 19:47:40 eric 6 5
c cleanup, commenting, linting, etc.
e
s 00000/00000/00009
d D 3.1 81/03/07 14:25:17 eric 5 4
c ----- delivermail ==> postbox -----
e
s 00000/00000/00009
d D 2.1 80/11/05 11:00:01 eric 4 3
c release 2
e
s 00000/00000/00009
d D 1.3 80/08/02 13:48:22 eric 3 2
c cleaned up comments
e
s 00002/00000/00007
d D 1.2 80/07/25 22:02:47 eric 2 1
c add ID keywords
e
s 00007/00000/00000
d D 1.1 80/06/23 08:23:31 eric 1 0
e
u
U
f b 
f i 
t
T
I 2
D 6
/* %W%	%G% */
E 6
I 6
D 7
static char	SccsId[] =	"%W%	%G%";
E 7
I 7
D 11
# include "useful.h"
E 11
I 11
/*
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 11

D 11
SCCSID(%W%	%Y%	%G%);
E 11
I 11
#ifndef lint
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint

# include "useful.h"
E 11

/*
D 10
**  BMOVE -- block move.
E 10
I 10
**  BCOPY -- block copy.
E 10
**
**	Parameters:
**		s -- source of bytes.
**		d -- destination of bytes.
**		l -- length of block to move.
**
**	Returns:
**		none.
**
**	Side Effects:
**		copies 's' to 'd' for 'l' bytes.
**
**	Notes:
**		This can be easily written in assembly language on
**		machines like VAXes if performance is needed.
*/
E 7
E 6

I 8
/*VARARGS0*/
E 8
E 2
I 1
D 10
bmove(s, d, l)
E 10
I 10
bcopy(s, d, l)
E 10
	register char *s, *d;
	register int l;
{
	while (l-- > 0)
		*d++ = *s++;
I 10
}
/*
**  BZERO -- zero a block of memory
**
**	Parameters:
**		p -- location to clear.
**		l -- number of bytes to clear.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

bzero(p, l)
	register char *p;
	register int l;
{
	while (l-- > 0)
		*p++ = 0;
E 10
}
E 1
