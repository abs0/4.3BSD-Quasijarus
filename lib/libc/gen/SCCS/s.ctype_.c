h59254
s 00002/00002/00023
d D 5.4 86/03/09 19:45:37 donn 9 8
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00024
d D 5.3 85/09/11 17:04:39 bloom 8 7
c fix iscntrl instead of the manual page
e
s 00001/00001/00024
d D 5.2 85/09/05 10:02:30 bloom 7 6
c isprint(space) should be true
e
s 00004/00001/00021
d D 5.1 85/06/05 12:12:57 mckusick 6 5
c Add copyright
e
s 00001/00001/00021
d D 4.4 85/03/01 15:16:51 karels 5 4
c so we change the manual?
e
s 00001/00001/00021
d D 4.3 85/02/04 11:01:12 serge 4 2
c changed size of _ctype_[] to 257 (EOF, '\0' ... '\377')
e
s 00001/00001/00021
d R 4.3 85/02/03 18:23:24 serge 3 2
c increased size of _ctype_[] to 256
e
s 00001/00001/00021
d D 4.2 83/07/08 23:03:36 sam 2 1
c space is a printing character according to the manual
e
s 00022/00000/00000
d D 4.1 80/12/21 16:39:35 wnj 1 0
c date and time created 80/12/21 16:39:35 by wnj
e
u
U
t
T
I 1
D 6
/* %W% (Berkeley) %G% */
E 6
I 6
D 9
#ifndef lint
E 9
I 9
#if defined(LIBC_SCCS) && !defined(lint)
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif LIBC_SCCS and not lint
E 9

E 6
#include	<ctype.h>

D 4
char _ctype_[] = {
E 4
I 4
char _ctype_[1 + 256] = {
E 4
	0,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
D 8
	_C,	_S,	_S,	_S,	_S,	_S,	_C,	_C,
E 8
I 8
	_C,	_C|_S,	_C|_S,	_C|_S,	_C|_S,	_C|_S,	_C,	_C,
E 8
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
D 2
	_S,	_P,	_P,	_P,	_P,	_P,	_P,	_P,
E 2
I 2
D 5
	_S|_P,	_P,	_P,	_P,	_P,	_P,	_P,	_P,
E 5
I 5
D 7
	_S,	_P,	_P,	_P,	_P,	_P,	_P,	_P,
E 7
I 7
	_S|_B,	_P,	_P,	_P,	_P,	_P,	_P,	_P,
E 7
E 5
E 2
	_P,	_P,	_P,	_P,	_P,	_P,	_P,	_P,
	_N,	_N,	_N,	_N,	_N,	_N,	_N,	_N,
	_N,	_N,	_P,	_P,	_P,	_P,	_P,	_P,
	_P,	_U|_X,	_U|_X,	_U|_X,	_U|_X,	_U|_X,	_U|_X,	_U,
	_U,	_U,	_U,	_U,	_U,	_U,	_U,	_U,
	_U,	_U,	_U,	_U,	_U,	_U,	_U,	_U,
	_U,	_U,	_U,	_P,	_P,	_P,	_P,	_P,
	_P,	_L|_X,	_L|_X,	_L|_X,	_L|_X,	_L|_X,	_L|_X,	_L,
	_L,	_L,	_L,	_L,	_L,	_L,	_L,	_L,
	_L,	_L,	_L,	_L,	_L,	_L,	_L,	_L,
	_L,	_L,	_L,	_P,	_P,	_P,	_P,	_C
};
E 1
