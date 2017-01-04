h55310
s 00004/00004/00005
d D 4.2 85/01/21 22:21:51 serge 2 1
c clean up
e
s 00009/00000/00000
d D 4.1 83/05/03 13:47:52 sam 1 0
c date and time created 83/05/03 13:47:52 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

# ifndef NDEBUG
D 2
# define _assert(ex) {if (!(ex)){fprintf(stderr,"Assertion failed: file %s, line %d\n", __FILE__, __LINE__);exit(1);}}
# define assert(ex) {if (!(ex)){fprintf(stderr,"Assertion failed: file %s, line %d\n", __FILE__, __LINE__);exit(1);}}
E 2
I 2
# define _assert(ex)	{if (!(ex)){fprintf(stderr,"Assertion failed: file \"%s\", line %d\n", __FILE__, __LINE__);exit(1);}}
# define assert(ex)	_assert(ex)
E 2
# else
D 2
# define _assert(ex) ;
# define assert(ex) ;
E 2
I 2
# define _assert(ex)
# define assert(ex)
E 2
# endif
E 1
