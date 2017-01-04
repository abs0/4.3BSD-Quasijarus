h34810
s 00007/00003/00027
d D 5.1 85/06/05 14:57:41 dist 5 4
c Add copyright
e
s 00000/00000/00030
d D 2.1 84/02/08 20:42:55 aoki 4 3
c synchronize to version 2
e
s 00000/00000/00030
d D 1.3 83/09/19 07:01:05 thien 3 2
c Restoring to unlinted version
e
s 00005/00001/00025
d D 1.2 83/08/19 05:02:52 thien 2 1
c The changes were made to allow successful linting
e
s 00026/00000/00000
d D 1.1 80/08/27 19:56:31 peter 1 0
c date and time created 80/08/27 19:56:31 by peter
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
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5

I 2
#ifndef lint
E 2
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
I 2
#endif
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5
E 2

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
I 2
#include "tree_ty.h"
E 2

/*
 * Lvalue computes the address
 * of a qualified name and
 * leaves it on the stack.
 */
struct nl *
stklval(r, modflag)
D 2
	int *r, modflag;
E 2
I 2
	struct  tnode *r;
	int	modflag;
E 2
{
	/*
	 * For the purposes of the interpreter stklval
	 * is the same as an lvalue.
	 */

	return(lvalue(r, modflag , LREQ ));
}
E 1
