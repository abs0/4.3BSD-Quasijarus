h41434
s 00000/00000/00037
d D 4.2 83/04/25 23:59:24 mckusick 2 1
c 
e
s 00037/00000/00000
d D 4.1 83/02/24 12:56:19 mckusick 1 0
c date and time created 83/02/24 12:56:19 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include <stdio.h>
main()
{
	int f, c;

	f = creat(".ocopy", 0666);
	while (read(0, &c, 1) == 1) {
		write (1, &c, 1);
		put(c, f);
	}
	fl(f);
	close(f);
}

static char ln[BUFSIZ];
char *p = ln;
put(c, f)
{
	*p++ = c;
	if (c == '\n') {
		fl(f);
		p=ln;
	}
}
fl(f)
{
	register char *s;

	s = ln;
	while (*s == '$' && *(s+1) == ' ')
		s += 2;
	write(f, s, p-s);
}
E 1
