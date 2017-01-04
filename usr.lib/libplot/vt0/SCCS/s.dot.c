h27701
s 00016/00000/00000
d D 4.1 83/06/27 14:26:10 sam 1 0
c date and time created 83/06/27 14:26:10 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

extern vti;
dot(xi,yi,dx,n,pat)
int pat[];
{
	struct {char pad,c; int xi,yi,dx;} p;
	p.c = 7;
	p.xi = xsc(xi);
	p.yi = ysc(yi);
	p.dx = xsc(dx);
	write(vti,&p.c,7);
	write(vti,pat,n?n&0377:256);
}
E 1
