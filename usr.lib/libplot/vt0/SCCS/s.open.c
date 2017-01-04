h45983
s 00007/00007/00017
d D 4.2 83/11/10 15:22:50 ralph 2 1
c fixed warning messages.
e
s 00024/00000/00000
d D 4.1 83/06/27 14:26:19 sam 1 0
c date and time created 83/06/27 14:26:19 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

int xnow;
int ynow;
D 2
float boty 0.;
float botx 0.;
float oboty 0.;
float obotx 0.;
float scalex 1.;
float scaley 1.;
int vti -1;
E 2
I 2
float boty = 0.;
float botx = 0.;
float oboty = 0.;
float obotx = 0.;
float scalex = 1.;
float scaley = 1.;
int vti = -1;
E 2

openvt ()
{
		vti = open("/dev/vt0",1);
		return;
}
openpl()
{
	vti = open("/dev/vt0",1);
	return;
}
E 1
