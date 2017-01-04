h16751
s 00010/00000/00000
d D 4.1 83/06/27 14:26:12 sam 1 0
c date and time created 83/06/27 14:26:12 by sam
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
erase(){
	int i;
	i=0401;
	write(vti,&i,2);
}
E 1
