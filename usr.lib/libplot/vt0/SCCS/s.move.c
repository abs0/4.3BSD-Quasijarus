h24874
s 00013/00000/00000
d D 4.1 83/06/27 14:26:17 sam 1 0
c date and time created 83/06/27 14:26:17 by sam
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
move(xi,yi){
	struct {char pad,c; int x,y;} p;
	p.c = 9;
	p.x = xnow = xsc(xi);
	p.y = ynow = ysc(yi);
	write(vti,&p.c,5);
}
E 1
