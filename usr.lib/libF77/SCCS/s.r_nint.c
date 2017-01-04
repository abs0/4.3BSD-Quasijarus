h63618
s 00004/00002/00014
d D 5.3 85/07/09 15:34:06 jerry 4 3
c do store in global to force convert to float despite C bug.
e
s 00001/00001/00015
d D 5.2 85/07/08 14:30:56 jerry 3 2
c declare function as float, not double.
e
s 00005/00001/00011
d D 5.1 85/06/07 22:27:11 kre 2 1
c Add copyright
e
s 00012/00000/00000
d D 1.1 83/01/21 11:18:15 dlw 1 0
c date and time created 83/01/21 11:18:15 by dlw
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

I 4
float flt_retval;

E 4
D 3
double r_nint(x)
E 3
I 3
float r_nint(x)
E 3
float *x;
{
double floor();

D 4
return( (*x)>=0 ?
	floor(*x + .5) : -floor(.5 - *x) );
E 4
I 4
flt_retval = (*x)>=0 ? floor(*x + .5) : -floor(.5 - *x);
return(flt_retval);
E 4
}
E 1
