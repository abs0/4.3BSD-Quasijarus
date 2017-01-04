h14574
s 00007/00003/00048
d D 5.1 85/06/05 15:03:07 dist 5 4
c Add copyright
e
s 00000/00000/00051
d D 2.1 84/02/08 20:42:59 aoki 4 3
c synchronize to version 2
e
s 00000/00000/00051
d D 1.3 83/09/19 07:01:26 thien 3 2
c Restoring to unlinted version
e
s 00021/00008/00030
d D 1.2 83/08/19 05:03:31 thien 2 1
c The changes were made to allow successful linting
e
s 00038/00000/00000
d D 1.1 80/08/27 19:56:47 peter 1 0
c date and time created 80/08/27 19:56:47 by peter
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

    /*
     *	is there some reason why these aren't #defined?
     */

I 2
#include	"0.h"
#include	"tree_ty.h"

struct tnode *
E 2
tree1 ( arg1 )
    int		arg1;
    {
D 2
	tree ( 1 , arg1 );
E 2
I 2
	return( tree ( 1 , arg1 ));
E 2
    }

I 2
struct tnode *
E 2
tree2 ( arg1 , arg2 )
    int		arg1 , arg2;
    {
D 2
	tree ( 2 , arg1 , arg2 );
E 2
I 2
	return( tree ( 2 , arg1 , arg2 ));
E 2
    }

I 2
struct tnode *
E 2
tree3 ( arg1 , arg2 , arg3 )
D 2
    int		arg1 , arg2 , arg3;
E 2
I 2
    int		arg1 , arg2 ;
    struct	tnode *arg3;
E 2
    {
D 2
	tree ( 3 , arg1 , arg2 , arg3 );
E 2
I 2
	return( tree ( 3 , arg1 , arg2 , arg3 ));
E 2
    }

I 2
struct tnode *
E 2
tree4 ( arg1 , arg2 , arg3 , arg4 )
D 2
    int		arg1 , arg2 , arg3 , arg4;
E 2
I 2
    int		arg1 , arg2 ;
    struct tnode *arg3 , *arg4;
E 2
    {
D 2
	tree ( 4 , arg1 , arg2 , arg3 , arg4 );
E 2
I 2
	return( tree ( 4 , arg1 , arg2 , arg3 , arg4 ));
E 2
    }

I 2
struct tnode *
E 2
tree5 ( arg1 , arg2 , arg3 , arg4 , arg5 )
D 2
    int		arg1 , arg2 , arg3 , arg4 , arg5;
E 2
I 2
    int		arg1 , arg2 ;
    struct tnode *arg3 , *arg4 , *arg5;
E 2
    {
D 2
	tree ( 5 , arg1 , arg2 , arg3 , arg4 , arg5 );
E 2
I 2
	return (tree ( 5 , arg1 , arg2 , arg3 , arg4 , arg5 ));
E 2
    }

E 1
