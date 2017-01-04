h33733
s 00002/00002/00039
d D 5.2 86/03/09 19:46:25 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00012/00009/00029
d D 5.1 85/06/05 12:16:43 mckusick 3 2
c Add copyright
e
s 00004/00003/00034
d D 4.2 84/08/16 14:32:37 ralph 2 1
c fix bug for x == power of 2 or zero.
e
s 00037/00000/00000
d D 4.1 80/12/21 16:39:40 wnj 1 0
c date and time created 80/12/21 16:39:40 by wnj
e
u
U
t
T
I 1
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
D 4
#ifndef lint
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif LIBC_SCCS and not lint
E 4

E 3
/*
D 3
	the call
		x = frexp(arg,&exp);
	must return a double fp quantity x which is <1.0
	and the corresponding binary exponent "exp".
	such that
		arg = x*2^exp
I 2
	if the argument is 0.0, return 0.0 mantissa and 0 exponent.
E 2
*/
E 3
I 3
 *	the call
 *		x = frexp(arg,&exp);
 *	must return a double fp quantity x which is <1.0
 *	and the corresponding binary exponent "exp".
 *	such that
 *		arg = x*2^exp
 *	if the argument is 0.0, return 0.0 mantissa and 0 exponent.
 */
E 3

double
frexp(x,i)
double x;
int *i;
{
	int neg;
	int j;
	j = 0;
	neg = 0;
	if(x<0){
		x = -x;
		neg = 1;
		}
D 2
	if(x>1.0)
		while(x>1){
E 2
I 2
	if(x>=1.0)
		while(x>=1.0){
E 2
			j = j+1;
			x = x/2;
			}
D 2
	else if(x<0.5)
E 2
I 2
	else if(x<0.5 && x != 0.0)
E 2
		while(x<0.5){
			j = j-1;
			x = 2*x;
			}
	*i = j;
	if(neg) x = -x;
	return(x);
	}
E 1
