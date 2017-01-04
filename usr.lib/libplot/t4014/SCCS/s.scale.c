h31699
s 00026/00000/00000
d D 4.1 83/06/27 14:19:26 sam 1 0
c date and time created 83/06/27 14:19:26 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

extern float scalex;
extern float scaley;
extern int scaleflag;
scale(i,x,y)
char i;
float x,y;
{
	switch(i) {
	default:
		return;
	case 'c':
		x *= 2.54;
		y *= 2.54;
	case 'i':
		x /= 200;
		y /= 200;
	case 'u':
		scalex = 1/x;
		scaley = 1/y;
	}
	scaleflag = 1;
}
E 1
