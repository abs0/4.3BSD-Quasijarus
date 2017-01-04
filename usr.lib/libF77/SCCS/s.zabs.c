h48150
s 00002/00004/00028
d D 5.2 86/11/03 21:54:46 mckusick 2 1
c tahoe only
e
s 00032/00000/00000
d D 5.1 86/11/03 20:00:15 mckusick 1 0
c from CCI
e
u
U
t
T
I 1
/*
 *	%W%	%G%
 */

D 2
/*
 *	"@(#)zabs.c	1.1"
 */

E 2
I 2
#ifdef tahoe
E 2
/* THIS IS BASED ON TAHOE FP REPRESENTATION */
#include <tahoemath/FP.h>

double zabs(real, imag)
double real, imag;
{
double temp, sqrt();

if(real < 0)
	*(long int *)&real ^= SIGN_BIT;
if(imag < 0)
	*(long int *)&imag ^= SIGN_BIT;
if(imag > real){
	temp = real;
	real = imag;
	imag = temp;
}
if(imag == 0.)		/* if((real+imag) == real) */
	return(real);

temp = imag/real;
temp = real*sqrt(1.0 + temp*temp);  /*overflow!!*/
return(temp);
}
I 2
#endif tahoe
E 2
E 1
