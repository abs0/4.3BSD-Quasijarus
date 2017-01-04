h39591
s 00000/00001/00018
d D 4.2 85/01/02 19:16:44 jak 2 1
c delete sleep(2): didn't work right since no flush() and better
c done by driver with dF#1000 in /etc/termcap.
e
s 00019/00000/00000
d D 4.1 83/06/27 14:19:18 sam 1 0
c date and time created 83/06/27 14:19:18 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

extern int ohiy;
extern int ohix;
extern int oloy;
extern int oextra;
erase(){
	int i;
		putch(033);
		putch(014);
		ohiy= -1;
		ohix = -1;
		oextra = -1;
		oloy = -1;
D 2
		sleep(2);
E 2
		return;
}
E 1
