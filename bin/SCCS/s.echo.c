h45506
s 00001/00001/00023
d D 4.2 85/05/27 21:44:51 serge 2 1
c don't accept -nANYTHING in place of -n
e
s 00024/00000/00000
d D 4.1 80/10/01 17:26:28 bill 1 0
c date and time created 80/10/01 17:26:28 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
#include <stdio.h>

main(argc, argv)
int argc;
char *argv[];
{
	register int i, nflg;

	nflg = 0;
D 2
	if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n') {
E 2
I 2
	if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n' && !argv[1][2]) {
E 2
		nflg++;
		argc--;
		argv++;
	}
	for(i=1; i<argc; i++) {
		fputs(argv[i], stdout);
		if (i < argc-1)
			putchar(' ');
	}
	if(nflg == 0)
		putchar('\n');
	exit(0);
}
E 1
