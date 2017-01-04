h16931
s 00010/00000/00000
d D 4.1 83/06/27 14:26:13 sam 1 0
c date and time created 83/06/27 14:26:13 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

frame(n)
{
	extern vti;
	n=n&0377 | 02000;
	write(vti,&n,2);
}
E 1
