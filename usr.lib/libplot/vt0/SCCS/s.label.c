h20764
s 00017/00000/00000
d D 4.1 83/06/27 14:26:14 sam 1 0
c date and time created 83/06/27 14:26:14 by sam
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

label(s)
char *s;
{
	int i, o;

	o = 01401;
	write(vti, &o, 2);
	for(i=0; s[i++]; )
		;
	write(vti, s, i);
}
E 1
