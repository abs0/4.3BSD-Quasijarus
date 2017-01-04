h19373
s 00011/00000/00000
d D 4.1 83/06/27 14:26:05 sam 1 0
c date and time created 83/06/27 14:26:05 by sam
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
arc(xi,yi,x0,y0,x1,y1){
	char c;
	c = 6;
	write(vti,&c,1);
	write(vti,&xi,12);
}
E 1
