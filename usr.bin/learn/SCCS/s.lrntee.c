h46748
s 00002/00001/00035
d D 4.3 86/05/15 17:58:33 bloom 3 2
c updates from John Kunze
e
s 00000/00000/00036
d D 4.2 83/04/26 01:23:55 mckusick 2 1
c 
e
s 00036/00000/00000
d D 4.1 83/04/26 01:21:12 mckusick 1 0
c date and time created 83/04/26 01:21:12 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

main()
{
D 3
	int f, c;
E 3
I 3
	int f;
	char c;
E 3

	f = creat(".ocopy", 0666);
	while (read(0, &c, 1) == 1) {
		write (1, &c, 1);
		put(c, f);
	}
	fl(f);
	close(f);
}

static char ln[512];
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
	while (*s == '%' && *(s+1) == ' ')
		s += 2;
	write(f, s, p-s);
}
E 1
