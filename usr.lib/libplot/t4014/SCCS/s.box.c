h20112
s 00013/00000/00000
d D 4.1 83/06/27 14:19:13 sam 1 0
c date and time created 83/06/27 14:19:13 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

box(x0, y0, x1, y1)
{
	move(x0, y0);
	cont(x0, y1);
	cont(x1, y1);
	cont(x1, y0);
	cont(x0, y0);
	move(x1, y1);
}
E 1
