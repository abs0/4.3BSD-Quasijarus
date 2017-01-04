h04214
s 00001/00001/00036
d D 7.1 86/06/04 23:24:28 mckusick 12 11
c 4.3BSD release version
e
s 00007/00001/00030
d D 6.3 85/06/08 15:00:29 mckusick 11 10
c Add copyright
e
s 00001/00001/00030
d D 6.2 85/06/07 15:35:29 bloom 10 9
c use MAXHOSTNAMELEN
e
s 00000/00000/00031
d D 6.1 83/07/29 06:12:57 sam 9 8
c 4.2 distribution
e
s 00001/00000/00030
d D 4.8 83/05/30 17:44:22 sam 8 7
c put phz where it belongs
e
s 00002/00000/00028
d D 4.7 82/10/21 20:56:56 root 7 6
c lint
e
s 00002/00000/00026
d D 4.6 82/10/21 17:30:35 root 6 5
c lint
e
s 00000/00002/00026
d D 4.5 82/10/20 01:16:13 root 5 4
c lint
e
s 00009/00001/00019
d D 4.4 82/09/12 03:19:27 root 4 3
c 
e
s 00002/00000/00018
d D 4.3 82/09/08 08:11:22 root 3 2
c label_t now a structure; other misc changes
e
s 00003/00000/00015
d D 4.2 82/09/06 23:01:13 root 2 1
c more timer stuff
e
s 00015/00000/00000
d D 4.1 82/09/04 09:27:11 root 1 0
c date and time created 82/09/04 09:27:11 by root
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 12
 * Copyright (c) 1982 Regents of the University of California.
E 12
I 12
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11

/*
 * Global variables for the kernel
 */

I 6
long	rmalloc();

E 6
/* 1.1 */
long	hostid;
D 10
char	hostname[32];
E 10
I 10
char	hostname[MAXHOSTNAMELEN];
E 10
I 2
int	hostnamelen;
E 2
D 5
int	nextpid;
E 5

/* 1.2 */
struct	timeval boottime;
struct	timeval time;
struct	timezone tz;			/* XXX */
I 2
int	hz;
I 8
int	phz;				/* alternate clock's frequency */
E 8
int	tick;
I 3
int	lbolt;				/* awoken once a second */
D 4
int	unsel(),unrto();
E 4
I 4
D 5
int	selitexpire();
E 5
int	realitexpire();

I 7
double	avenrun[3];

E 7
#ifdef GPROF
extern	int profiling;
extern	char *s_lowpc;
extern	u_long s_textsize;
extern	u_short *kcount;
#endif
E 4
E 3
E 2
E 1
