h41720
s 00043/00000/00000
d D 4.1 80/10/01 17:25:08 bill 1 0
c date and time created 80/10/01 17:25:08 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
char *dn;

main(argc, argv)
char *argv[];
{
	register f, n, c;


	if(argc < 2)
		goto arg;
	dn = "/dev/dn0";
	if(*argv[1] == '-') {
		dn = argv[1]+1;
		argc--;
		argv++;
	}
	if(argc < 2)
		goto arg;
	c = 0;
loop:
	f = open(dn, 1);
	if(f < 0)
		goto slp;
	for(n=0; argv[1][n]; n++)
		;
	alarm(120);
	if(write(f, argv[1], n) == n)
		exit(0);

slp:
	if(f >= 0)
		close(f);
	c++;
	if(c > 100)
		exit(1);
	sleep(10);
	goto loop;

arg:
	printf("arg c\n");
	exit(1);
}
E 1
