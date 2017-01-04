h00576
s 00010/00000/00024
d D 5.1 85/05/08 12:37:04 dist 2 1
c Create SCCS file, add copyright
e
s 00024/00000/00000
d D 1.1 85/05/08 12:21:53 dist 1 0
c date and time created 85/05/08 12:21:53 by dist
e
u
U
t
T
I 1
/*
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

/*
E 2
acos(arg) return the arccos,
	respectively of their arguments.

	Arctan is called after appropriate range reduction.
*/

#include	<errno.h>
int errno;
double atan();
double asin();
static double pio2	= 1.570796326794896619;

double
acos(arg) double arg; {

	asm("	bispsw	$0xe0");
	if(arg > 1.|| arg < -1.){
		errno = EDOM;
		return(0.);
	}

	return(pio2 - asin(arg));
}
E 1
