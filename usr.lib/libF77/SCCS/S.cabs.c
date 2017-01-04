h54184
s 00005/00001/00024
d D 5.1 85/06/07 21:38:18 kre 2 1
c Add copyright
e
s 00025/00000/00000
d D 1.1 83/01/21 11:08:45 dlw 1 0
c date and time created 83/01/21 11:08:45 by dlw
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

double cabs(real, imag)
double real, imag;
{
double temp, sqrt();

if(real < 0)
	real = -real;
if(imag < 0)
	imag = -imag;
if(imag > real){
	temp = real;
	real = imag;
	imag = temp;
}
if((real+imag) == real)
	return(real);

temp = imag/real;
temp = real*sqrt(1.0 + temp*temp);  /*overflow!!*/
return(temp);
}
E 1
