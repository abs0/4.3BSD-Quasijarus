h64260
s 00002/00002/00025
d D 5.2 88/01/03 00:33:21 bostic 4 3
c neither K&R or ANSI C allow untyped function declarations
e
s 00007/00003/00020
d D 5.1 85/06/06 16:08:32 dist 3 2
c Add copyright
e
s 00001/00001/00022
d D 1.2 82/01/18 22:15:03 linton 2 1
c sccsid
e
s 00023/00000/00000
d D 1.1 82/01/18 19:02:40 linton 1 0
c date and time created 82/01/18 19:02:40 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

/*
 * Mappings definitions.
 *
 * The mappings module is the interface between the object code and
 * source file representations of the program.
 *
 * This module is strongly tied to the object module, and needs the
 * most of the data defined in "object.h".
 */

ADDRESS objaddr();	/* get the object address corresponding to a line */

char *srcfilename();	/* get the nearest source file <= a given address */
LINENO srcline();	/* get the nearest source line <= a given address */
LINENO linelookup();	/* look for a line number with exactly given address */

D 4
newfunc();		/* record the appearance of a new function */
E 4
I 4
int newfunc();		/* record the appearance of a new function */
E 4
SYM *whatblock();	/* find the function associated with an address */
D 4
clrfunctab();		/* re-initialize function table */
E 4
I 4
int clrfunctab();	/* re-initialize function table */
E 4
E 1
