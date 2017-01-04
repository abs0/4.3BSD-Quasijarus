h37363
s 00002/00002/00009
d D 5.2 86/03/09 20:48:40 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00008
d D 5.1 85/06/05 13:32:52 mckusick 2 1
c Add copyright
e
s 00009/00000/00000
d D 1.1 83/06/23 23:31:43 root 1 0
c date and time created 83/06/23 23:31:43 by root
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3
E 2

exit(code)
	int code;
{

	_cleanup();
	_exit(code);
}
E 1
