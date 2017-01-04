h18640
s 00011/00000/00000
d D 4.1 83/06/27 14:26:08 sam 1 0
c date and time created 83/06/27 14:26:08 by sam
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
circle(x,y,r){
	char c;
	c = 5;
	write(vti,&c,1);
	write(vti,&x,6);
}
E 1
