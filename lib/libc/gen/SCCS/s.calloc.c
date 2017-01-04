h28856
s 00002/00002/00025
d D 5.2 86/03/09 19:44:43 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00024
d D 5.1 85/06/05 12:08:27 mckusick 3 2
c Add copyright
e
s 00013/00020/00012
d D 4.2 85/01/21 22:41:38 serge 2 1
c use bzero
e
s 00032/00000/00000
d D 4.1 80/12/21 16:39:29 wnj 1 0
c date and time created 80/12/21 16:39:29 by wnj
e
u
U
t
T
I 1
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
D 4
#ifndef lint
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif LIBC_SCCS and not lint
E 4
E 3
D 2
/*	calloc - allocate and clear memory block
*/
#define CHARPERINT (sizeof(int)/sizeof(char))
#define NULL 0
E 2

I 2
/*
 * Calloc - allocate and clear memory block
 */
E 2
char *
calloc(num, size)
D 2
unsigned num, size;
E 2
I 2
	register unsigned num, size;
E 2
{
D 2
	register char *mp;
	char *malloc();
	register int *q;
	register m;
E 2
I 2
	extern char *malloc();
	register char *p;
E 2

D 2
	num *= size;
	mp = malloc(num);
	if(mp == NULL)
		return(NULL);
	q = (int *) mp;
	m = (num+CHARPERINT-1)/CHARPERINT;
	while(--m>=0)
		*q++ = 0;
	return(mp);
E 2
I 2
	size *= num;
	if (p = malloc(size))
		bzero(p, size);
	return (p);
E 2
}

cfree(p, num, size)
D 2
char *p;
unsigned num, size;
E 2
I 2
	char *p;
	unsigned num;
	unsigned size;
E 2
{
	free(p);
}
E 1
