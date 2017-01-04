h64990
s 00002/00002/00018
d D 4.6 85/09/11 18:07:52 mckusick 6 5
c new from Kahan
e
s 00001/00001/00019
d D 4.5 85/08/22 16:04:52 miriam 5 4
c Use old gamma.
e
s 00006/00002/00014
d D 4.4 85/08/20 14:21:31 miriam 4 3
c Update from Prof. Kahan.
e
s 00011/00006/00005
d D 4.3 85/05/23 15:40:28 miriam 3 2
c From Prof. Kahan - includes addition routines in the math library.
e
s 00001/00001/00010
d D 4.2 84/03/08 08:31:44 karels 2 1
c fmod=>modf
e
s 00011/00000/00000
d D 4.1 83/05/03 13:48:02 sam 1 0
c date and time created 83/05/03 13:48:02 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*	%M%	%I%	%G%	*/
E 3

D 2
extern double fabs(), floor(), ceil(), fmod(), ldexp(), frexp();
E 2
I 2
D 3
extern double fabs(), floor(), ceil(), modf(), ldexp(), frexp();
E 2
extern double sqrt(), hypot(), atof();
extern double sin(), cos(), tan(), asin(), acos(), atan(), atan2();
extern double exp(), log(), log10(), pow();
extern double sinh(), cosh(), tanh();
E 3
I 3
extern double asinh(), acosh(), atanh();
extern double erf(), erfc();
D 4
extern double E(), L(), exp(), log(), log10(), pow();
E 4
I 4
extern double exp(), expm1(), log(), log10(), log1p(), pow();
E 4
D 6
extern double fabs(), floor(), ceil();
E 3
D 4
extern double gamma();
E 4
I 4
D 5
extern double lgama();
E 5
I 5
extern double gamma();
E 6
I 6
extern double fabs(), floor(), ceil(), rint();
extern double lgamma();
E 6
E 5
E 4
I 3
extern double hypot(), cabs();
extern double copysign(), drem(), logb(), scalb();
I 4
extern int finite();
#ifdef vax
extern double infnan();
#endif
E 4
E 3
extern double j0(), j1(), jn(), y0(), y1(), yn();
I 3
extern double sin(), cos(), tan(), asin(), acos(), atan(), atan2();
extern double sinh(), cosh(), tanh();
extern double cbrt(), sqrt();
extern double modf(), ldexp(), frexp(), atof();
E 3

#define HUGE	1.701411733192644270e38
E 1
