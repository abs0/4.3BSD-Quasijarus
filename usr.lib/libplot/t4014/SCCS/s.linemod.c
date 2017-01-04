h26438
s 00023/00000/00000
d D 4.1 83/06/27 14:19:22 sam 1 0
c date and time created 83/06/27 14:19:22 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

linemod(s)
char *s;
{
	char c;
	putch(033);
	switch(s[0]){
	case 'l':	
		c = 'd';
		break;
	case 'd':	
		if(s[3] != 'd')c='a';
		else c='b';
		break;
	case 's':
		if(s[5] != '\0')c='c';
		else c='`';
	}
	putch(c);
}
E 1
