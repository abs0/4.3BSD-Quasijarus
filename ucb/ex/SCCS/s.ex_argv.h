h57695
s 00007/00007/00027
d D 7.4 03/04/13 15:18:44 msokolov 12 11
c 8-bit ex
e
s 00008/00002/00026
d D 7.3 85/05/31 15:57:08 dist 11 9
c Add copyright
e
s 00008/00002/00025
d D 5.1.1.1 85/05/31 11:51:03 dist 10 6
c Add copyright
e
s 00010/00010/00018
d D 7.2 81/07/26 20:02:18 mark 9 8
c fixes for 3b
e
s 00013/00012/00015
d D 7.1 81/07/08 22:28:23 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00027
d D 6.1 80/10/19 01:20:15 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00027
d D 5.1 80/08/20 16:08:14 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00025
d D 4.2 80/08/01 17:59:04 mark 5 4
c added sccs, Bill put in more buffers
e
s 00000/00000/00026
d D 4.1 80/08/01 00:09:58 mark 4 3
c release 3.4, June 24, 1980
e
s 00000/00000/00026
d D 3.1 80/07/31 23:36:17 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00001/00001/00025
d D 2.1 80/07/31 23:17:41 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00026/00000/00000
d D 1.1 80/07/31 23:00:05 mark 1 0
c date and time created 80/07/31 23:00:05 by mark
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 8
D 10
/* Copyright (c) 1980 Regents of the University of California */
/* sccs id:	%W% %G%  */
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 10
E 8
I 8
D 11
/* Copyright (c) 1981 Regents of the University of California */
/* sccs id:	%W%	%G%  */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 11
E 8
E 5
/*
 * The current implementation of the argument list is poor,
 * using an argv even for internally done "next" commands.
 * It is not hard to see that this is restrictive and a waste of
 * space.  The statically allocated glob structure could be replaced
 * by a dynamically allocated argument area space.
 */
D 8
char	**argv;
char	**argv0;
char	*args;
char	*args0;
short	argc;
short	argc0;
short	morargc;		/* Used with "More files to edit..." */
E 8
I 8
D 9
extern char	**argv;
extern char	**argv0;
extern char	*args;
extern char	*args0;
extern short	argc;
extern short	argc0;
extern short	morargc;		/* Used with "More files to edit..." */
E 9
I 9
D 12
var char	**argv;
var char	**argv0;
var char	*args;
var char	*args0;
E 12
I 12
var u_char	**argv;
var u_char	**argv0;
var u_char	*args;
var u_char	*args0;
E 12
var short	argc;
var short	argc0;
var short	morargc;		/* Used with "More files to edit..." */
E 9
E 8

D 2
short	firstln;		/* From +lineno */
E 2
I 2
D 8
int	firstln;		/* From +lineno */
E 2
char	*firstpat;		/* From +/pat	*/
E 8
I 8
D 9
extern int	firstln;		/* From +lineno */
extern char	*firstpat;		/* From +/pat	*/
E 9
I 9
var int	firstln;		/* From +lineno */
D 12
var char	*firstpat;		/* From +/pat	*/
E 12
I 12
var u_char	*firstpat;		/* From +/pat	*/
E 12
E 9
E 8

/* Yech... */
struct	glob {
	short	argc;			/* Index of current file in argv */
	short	argc0;			/* Number of arguments in argv */
D 12
	char	*argv[NARGS + 1];	/* WHAT A WASTE! */
	char	argspac[NCARGS + sizeof (int)];
E 12
I 12
	u_char	*argv[NARGS + 1];	/* WHAT A WASTE! */
	u_char	argspac[NCARGS + sizeof (int)];
E 12
D 8
} frob;
E 8
I 8
};
D 9
extern struct	glob frob;
E 9
I 9
var struct	glob frob;
E 9
E 8
E 1
