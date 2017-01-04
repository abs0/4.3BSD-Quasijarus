h15611
s 00007/00000/00000
d D 4.1 83/06/27 14:19:15 sam 1 0
c date and time created 83/06/27 14:19:15 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

circle(x,y,r){
	arc(x,y,x+r,y,x+r,y);
}
E 1
