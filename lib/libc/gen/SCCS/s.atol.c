h50994
s 00002/00002/00027
d D 5.2 86/03/09 19:44:34 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00025
d D 5.1 85/06/05 12:07:54 mckusick 2 1
c Add copyright
e
s 00026/00000/00000
d D 4.1 80/12/21 16:39:27 wnj 1 0
c date and time created 80/12/21 16:39:27 by wnj
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3

E 2
long
atol(p)
register char *p;
{
	long n;
	register int f;

	n = 0;
	f = 0;
	for(;;p++) {
		switch(*p) {
		case ' ':
		case '\t':
			continue;
		case '-':
			f++;
		case '+':
			p++;
		}
		break;
	}
	while(*p >= '0' && *p <= '9')
		n = n*10 + *p++ - '0';
	return(f? -n: n);
}
E 1
