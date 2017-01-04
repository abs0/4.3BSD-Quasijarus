h25002
s 00013/00000/00000
d D 4.1 83/06/27 14:26:20 sam 1 0
c date and time created 83/06/27 14:26:20 by sam
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
extern xnow,ynow;
point(xi,yi){
	struct {char pad,c; int x,y;} p;
	p.c = 2;
	p.x = xnow = xsc(xi);
	p.y = ynow =  ysc(yi);
	write(vti,&p.c,5);
}
E 1
