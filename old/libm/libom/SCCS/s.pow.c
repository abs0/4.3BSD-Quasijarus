h59057
s 00006/00001/00215
d R 4.4 85/06/03 16:10:01 miriam 4 3
c Return reserve operand for vax
e
s 00207/00032/00009
d R 4.3 85/05/23 15:01:05 miriam 3 2
c From Prof. Kahan
e
s 00002/00000/00039
d D 4.2 83/06/30 13:48:21 sam 2 1
c machine dependent
e
s 00039/00000/00000
d D 4.1 82/12/25 10:46:51 sam 1 0
c date and time created 82/12/25 10:46:51 by sam
e
u
U
t
T
I 1
/*	%W%	%G%	*/

/*
	computes a^b.
	uses log and exp
*/

#include	<errno.h>
int errno;
double log(), exp();

double
pow(arg1,arg2)
double arg1, arg2;
{
	double temp;
	long l;

I 2
#ifdef vax
E 2
	asm("	bispsw	$0xe0");
I 2
#endif
E 2
	if(arg1 <= 0.) {
		if(arg1 == 0.) {
			if(arg2 <= 0.)
				goto domain;
			return(0.);
		}
		l = arg2;
		if(l != arg2)
			goto domain;
		temp = exp(arg2 * log(-arg1));
		if(l & 1)
			temp = -temp;
		return(temp);
	}
	return(exp(arg2 * log(arg1)));

domain:
	errno = EDOM;
	return(0.);
}
E 1
