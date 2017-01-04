h36390
s 00005/00001/00010
d D 5.1 85/06/07 22:08:58 kre 2 1
c Add copyright
e
s 00011/00000/00000
d D 1.1 83/01/21 11:16:29 dlw 1 0
c date and time created 83/01/21 11:16:29 by dlw
e
u
U
t
T
I 1
/*
D 2
 *	"%W%"
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
E 2
 */

double pow_dd(ap, bp)
double *ap, *bp;
{
double pow();

return(pow(*ap, *bp) );
}
E 1
