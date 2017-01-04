h32407
s 00019/00000/00000
d D 4.1 83/06/27 14:26:15 sam 1 0
c date and time created 83/06/27 14:26:15 by sam
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
line(x0,y0,x1,y1){
	struct{char x,c; int x0,y0,x1,y1;} p;
	p.c = 3;
	p.x0 = xsc(x0);
	p.y0 = ysc(y0);
	p.x1 = xnow = xsc(x1);
	p.y1 = ynow = ysc(y1);
	write(vti,&p.c,9);
}
cont(x0,y0){
	line(xnow,ynow,xsc(x0),ysc(y0));
	return;
}
E 1
