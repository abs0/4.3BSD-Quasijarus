h21853
s 00001/00001/00056
d R 5.3 88/02/17 19:16:15 mckusick 7 6
c use proper stack alignment
e
s 00015/00000/00042
d D 5.2 86/11/12 09:52:27 mckusick 6 5
c add CCI (tahoe) support
e
s 00007/00003/00035
d D 5.1 85/06/05 15:41:29 dist 5 4
c Add copyright
e
s 00000/00000/00038
d D 2.1 84/02/08 20:49:57 aoki 4 3
c synchronize to version 2
e
s 00000/00000/00038
d D 1.3 83/09/19 07:08:21 thien 3 2
c changing to unlinted source
e
s 00030/00013/00008
d D 1.2 83/02/01 20:05:13 peter 2 1
c alignments are machine dependent.
e
s 00021/00000/00000
d D 1.1 80/08/27 22:28:03 peter 1 0
c date and time created 80/08/27 22:28:03 by peter
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */

/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

    /*
     *	alignment of various types in bytes.
     *	sizes are found using sizeof( type ).
     */
D 2
#define	A_CHAR		1
#define	A_INT		4
#define	A_FLOAT		4
#define	A_DOUBLE	4
#define	A_LONG		4
#define	A_SHORT		2
#define	A_POINT		4
#define	A_STRUCT	1
#define	A_STACK		4
#define	A_FILET		4
#define	A_SET		4
#define	A_MIN		1
#define	A_MAX		4
E 2
I 2
#ifdef vax
#   define A_CHAR	1
#   define A_INT	4
#   define A_FLOAT	4
#   define A_DOUBLE	4
#   define A_LONG	4
#   define A_SHORT	2
#   define A_POINT	4
#   define A_STRUCT	1
#   define A_STACK	4
#   define A_FILET	4
#   define A_SET	4
#   define A_MIN	1
#   define A_MAX	4
#endif vax
I 6
#ifdef tahoe
#   define A_CHAR	1
#   define A_INT	4
#   define A_FLOAT	4
#   define A_DOUBLE	4
#   define A_LONG	4
#   define A_SHORT	2
#   define A_POINT	4
#   define A_STRUCT	4
#   define A_STACK	4
#   define A_FILET	4
#   define A_SET	4
#   define A_MIN	1
#   define A_MAX	4
#endif tahoe
E 6
#ifdef mc68000
#   define A_CHAR	1
#   define A_INT	2
#   define A_FLOAT	2
#   define A_DOUBLE	2
#   define A_LONG	2
#   define A_SHORT	2
#   define A_POINT	2
#   define A_STRUCT	2
#   define A_STACK	2
#   define A_FILET	2
#   define A_SET	2
#   define A_MIN	1
#   define A_MAX	2
#endif mc68000
E 2
E 1
