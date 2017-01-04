h15373
s 00002/00002/00026
d D 5.2 86/03/09 19:44:23 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00024
d D 5.1 85/06/05 12:03:44 mckusick 4 3
c Add copyright
e
s 00001/00001/00024
d D 4.3 81/02/28 22:25:24 wnj 3 2
c now ident to atol
e
s 00017/00017/00008
d D 4.2 81/02/28 22:24:42 wnj 2 1
c now same as atoi
e
s 00025/00000/00000
d D 4.1 80/12/21 16:39:26 wnj 1 0
c date and time created 80/12/21 16:39:26 by wnj
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
atoi(ap)
char *ap;
E 2
I 2
D 3
/* @(#)atoi.c	4.2 (Berkeley) 1/11/81 */
E 3
I 3
D 4
/* %W% (Berkeley) %E% */
E 4
I 4
D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5

E 4
E 3
atoi(p)
register char *p;
E 2
{
D 2
	register int  n, c;
	register char *p;
	int f;
E 2
I 2
	register int n;
	register int f;
E 2

D 2
	p = ap;
E 2
	n = 0;
	f = 0;
D 2
loop:
	while(*p == ' ' || *p == '	')
		p++;
	if(*p == '-') {
		f++;
		p++;
		goto loop;
E 2
I 2
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
E 2
	}
	while(*p >= '0' && *p <= '9')
		n = n*10 + *p++ - '0';
D 2
	if(f)
		n = -n;
	return(n);
E 2
I 2
	return(f? -n: n);
E 2
}
E 1
