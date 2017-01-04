h28827
s 00014/00002/00014
d D 5.1 85/06/05 13:59:23 dist 4 3
c Add copyright
e
s 00000/00000/00016
d D 2.1 84/02/08 20:29:13 aoki 3 2
c synchronize to version 2
e
s 00002/00002/00014
d D 1.2 81/03/06 23:02:12 mckusic 2 1
c add onyx code
e
s 00016/00000/00000
d D 1.1 81/01/08 12:43:59 mckusick 1 0
c date and time created 81/01/08 12:43:59 by mckusick
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1979 Regents of the University of California */
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 4

D 4
static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

    /*
     *	this writes the declaration of the current time stamp
     *	onto standard output.
     *	useful for making Version.c to give the creation date for px.
     */

D 2
#include	<time.h>
E 2
I 2
extern long time();
E 2

main()
{
D 2
	printf( "long	createtime = %d;\n" , time(0) );
E 2
I 2
	printf( "long	createtime = %D;\n" , time(0) );
E 2
}
E 1
