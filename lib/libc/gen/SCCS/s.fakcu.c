h48236
s 00002/00002/00009
d D 5.2 86/03/09 19:46:14 donn 4 2
c added LIBC_SCCS condition for sccs ids
e
s 00005/00001/00010
d R 5.2 86/02/04 17:58:13 karels 3 2
c as before, _stdio_init
e
s 00003/00001/00008
d D 5.1 85/06/05 12:15:35 mckusick 2 1
c Add copyright
e
s 00009/00000/00000
d D 4.1 84/11/13 14:50:28 karels 1 0
c date and time created 84/11/13 14:50:28 by karels
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %E% */
E 2
I 2
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
E 2

/*
 * Null cleanup routine to resolve reference in exit() 
 * if not using stdio.
 */
_cleanup()
{
}
E 1
