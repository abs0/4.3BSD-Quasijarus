h33944
s 00020/00000/00000
d D 4.1 83/06/27 14:26:22 sam 1 0
c date and time created 83/06/27 14:26:22 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

extern float obotx;
extern float oboty;
extern float boty;
extern float botx;
extern float scalex;
extern float scaley;
xsc(xi){
	int xa;
	xa = (xi-obotx)*scalex+botx;
	return(xa);
}
ysc(yi){
	int ya;
	ya = (yi-oboty)*scaley+boty;
	return(ya);
}
E 1
