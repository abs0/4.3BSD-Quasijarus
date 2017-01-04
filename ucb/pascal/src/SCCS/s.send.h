h18797
s 00007/00003/00029
d D 5.1 85/06/05 16:01:10 dist 4 3
c Add copyright
e
s 00000/00000/00032
d D 2.1 84/02/08 20:42:48 aoki 3 2
c synchronize to version 2
e
s 00000/00000/00032
d D 1.2 83/09/19 07:08:47 thien 2 1
c changing to unlinted source
e
s 00032/00000/00000
d D 1.1 80/08/27 19:54:27 peter 1 0
c date and time created 80/08/27 19:54:27 by peter
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1979 Regents of the University of California */

/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

#define	RINIT	1
#define	RENQ	2
#define	RTREE	3
#define	RTRFREE	4
#define	RTRCHK	5
#define	REVENIT	6
#define	RSTRING	7
#define	REVLAB	8
#define	REVCNST	9
#define	REVTBEG	10
#define	REVTYPE	11
#define	REVTEND	12
#define	REVVBEG	13
#define	REVVAR	14
#define	REVVEND	15
#define	REVFHDR	16
#define	REVFFWD	17
#define	REVFBDY	18
#define	REVFEND	19
#define	ROPUSH	20
#define	ROPOP	21
#define	ROSET	22
#define	RKILL	23
#define	RFINISH	24

#define	RLAST	24

extern	char *trdesc[];
E 1
