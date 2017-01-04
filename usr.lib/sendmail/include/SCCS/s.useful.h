h08439
s 00010/00005/00067
d D 4.4 88/06/29 21:56:18 bostic 21 20
m install
m approved
m copyright
m notice
c install approved copyright notice
e
s 00012/00004/00060
d D 4.3 88/03/24 14:50:55 bostic 20 19
m 
c add Berkeley specific headers
e
s 00000/00001/00064
d D 4.2 87/10/22 20:03:32 bostic 19 18
m ANSI
m C;
m sprintf
m now
m returns
m an
m int.
c ANSI C; sprintf now returns an int.
e
s 00000/00000/00065
d D 4.1 83/07/25 19:10:51 eric 18 17
m 
c 4.2 release version
e
s 00004/00004/00061
d D 3.13 83/03/26 12:42:39 eric 17 16
m 214
c u_short should be unsigned short; actually this is a punt
e
s 00001/00001/00064
d D 3.12 83/03/26 12:12:41 eric 16 15
m 214
c Undo glickman's change of types.h => param.h -- why did he do this?
e
s 00006/00000/00059
d D 3.11 83/01/04 10:54:16 eric 15 14
m 
c add min and max
e
s 00001/00001/00058
d D 3.10 82/06/07 22:19:14 eric 14 13
c make bitset work even on an implicit cast to bool across subr calls
e
s 00001/00001/00058
d D 3.9 82/05/05 20:26:40 eric 13 12
c (glickman) Changed include of types.h to param.h for ndir.h.
e
s 00003/00002/00056
d D 3.8 82/03/22 22:02:15 eric 12 11
c make better assumptions about definition of u_long, etc.
e
s 00020/00001/00038
d D 3.7 81/12/06 12:39:00 eric 11 10
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00002/00002/00037
d D 3.6 81/12/05 12:13:28 eric 10 9
c add strncpy and strncat
e
s 00001/00001/00038
d D 3.5 81/11/08 17:26:37 eric 9 8
c LINT
e
s 00006/00001/00033
d D 3.4 81/09/24 10:30:34 eric 8 7
c changes to work under a V6 system -- mostly compilation flags
e
s 00007/00003/00027
d D 3.3 81/08/17 09:37:30 eric 7 6
c cleanup -- dispose of setbit clrbit rot, include sys/types.h
e
s 00013/00000/00017
d D 3.2 81/08/09 15:03:10 eric 6 5
c lint it
e
s 00004/00000/00013
d D 3.1 81/03/07 14:27:12 eric 5 4
c ----- delivermail ==> postbox -----
e
s 00000/00000/00013
d D 2.1 80/11/05 11:00:03 eric 4 3
c release 2
e
s 00001/00001/00012
d D 1.3 80/10/11 18:11:13 eric 3 2
c cleanup to simplify configuration & fix minor bugs
e
s 00002/00000/00011
d D 1.2 80/07/25 22:02:10 eric 2 1
c add ID keywords
e
s 00011/00000/00000
d D 1.1 80/05/14 10:05:27 eric 1 0
e
u
msokolov
bostic
eric
U
f b 
f i 
t
T
I 1
/*
D 20
**  USEFUL.H -- Some useful stuff.
I 2
**
D 11
**	%W%	%G%
E 11
I 11
**	%W%	%Y%	%G%
E 11
E 2
*/
E 20
I 20
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 21
 *
 *	%W% (Berkeley) %G%
 */
E 20

D 3
# define bool	int
E 3
I 3
D 7
# define bool	char
E 7
I 7
# ifndef makedev
D 13
# include <sys/types.h>
E 13
I 13
D 16
# include <sys/param.h>
E 16
I 16
# include <sys/types.h>
E 16
E 13
# endif

/* support for bool type */
typedef char	bool;
E 7
E 3
# define TRUE	1
# define FALSE	0

# ifndef NULL
# define NULL	0
# endif NULL
I 5

D 7
# define setbit(bit, word)	(word |= bit)
# define clrbit(bit, word)	(word &= ~bit)
E 7
I 7
/* bit hacking */
E 7
D 14
# define bitset(bit, word)	((word) & (bit))
E 14
I 14
# define bitset(bit, word)	(((word) & (bit)) != 0)
E 14
I 11

I 15
/* some simple functions */
# ifndef max
# define max(a, b)	((a) > (b) ? (a) : (b))
# define min(a, b)	((a) < (b) ? (a) : (b))
# endif max

E 15
/* assertions */
# ifndef NASSERT
# define ASSERT(expr, msg, parm)\
	if (!(expr))\
	{\
		fprintf(stderr, "assertion botch: %s:%d: ", __FILE__, __LINE__);\
		fprintf(stderr, msg, parm);\
	}
# else NASSERT
# define ASSERT(expr, msg, parm)
# endif NASSERT

/* sccs id's */
# ifndef lint
# define SCCSID(arg)	static char SccsId[] = "arg";
# else lint
# define SCCSID(arg)
# endif lint
E 11
I 6

/* define the types of some common functions */
D 10
extern char	*strcpy();
extern char	*strcat();
E 10
I 10
extern char	*strcpy(), *strncpy();
extern char	*strcat(), *strncat();
E 10
extern char	*malloc();
extern char	*index(), *rindex();
extern int	errno;
D 19
extern char	*sprintf();
E 19
D 9
extern long	time();
E 9
I 9
extern time_t	time();
E 9
extern char	*ctime();
# ifndef V6
extern char	*getenv();
D 8
# endif
E 8
I 8
D 12
# else V6
E 12
I 12
# endif V6
# ifndef VMUNIX
E 12
D 17
typedef char	*u_short;
typedef long	u_long;
typedef char	u_char;
typedef int	void;
E 17
I 17
typedef unsigned short	u_short;
typedef long		u_long;
typedef char		u_char;
typedef int		void;
E 17
D 12
# endif V6
E 12
I 12
# endif VMUNIX
E 12
E 8
E 6
E 5
E 1
