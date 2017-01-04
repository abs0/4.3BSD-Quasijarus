h06242
s 00011/00004/00039
d D 4.2 85/08/28 18:45:52 mckusick 2 1
c give more complete error messages
e
s 00043/00000/00000
d D 4.1 80/10/01 17:27:29 bill 1 0
c date and time created 80/10/01 17:27:29 by bill
e
u
U
t
T
I 2
#ifndef lint
E 2
I 1
static char *sccsid = "%W% (Berkeley) %G%";
I 2
#endif not lint

#include <stdio.h>

E 2
main(argc, argv)
D 2
int argc;
char **argv;
E 2
I 2
	int argc;
	char **argv;
E 2
{
	int m, a, b;

	if(argc != 5) {
		printf("arg count\n");
		goto usage;
	}
	if(*argv[2] == 'b')
		m = 060666; else
	if(*argv[2] == 'c')
		m = 020666; else
		goto usage;
	a = number(argv[3]);
	if(a < 0)
		goto usage;
	b = number(argv[4]);
	if(b < 0)
		goto usage;
D 2
	if(mknod(argv[1], m, (a<<8)|b) < 0)
		perror("mknod");
E 2
I 2
	if(mknod(argv[1], m, (a<<8)|b) < 0) {
		fprintf(stderr, "mknod: ");
		perror(argv[1]);
	}
E 2
	exit(0);

usage:
	printf("usage: mknod name b/c major minor\n");
}

number(s)
char *s;
{
	int n, c;

	n = 0;
	while(c = *s++) {
		if(c<'0' || c>'9')
			return(-1);
		n = n*10 + c-'0';
	}
	return(n);
}
E 1
