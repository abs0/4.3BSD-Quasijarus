h35999
s 00021/00000/00000
d D 4.1 83/06/27 14:19:27 sam 1 0
c date and time created 83/06/27 14:19:27 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

extern float botx;
extern float boty;
extern float obotx;
extern float oboty;
extern float scalex;
extern float scaley;
extern int scaleflag;
space(x0,y0,x1,y1){
	botx = 0.;
	boty = 0.;
	obotx = x0;
	oboty = y0;
	if(scaleflag)
		return;
	scalex = 3120./(x1-x0);
	scaley = 3120./(y1-y0);
}
E 1
