h22680
s 00015/00000/00000
d D 4.1 80/10/01 17:24:37 bill 1 0
c date and time created 80/10/01 17:24:37 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
main(argc, argv)
char **argv;
{
	extern errno;
	if (argc > 1)
		acct(argv[1]);
	else
		acct((char *)0);
	if (errno) {
		perror("accton");
		exit(1);
	}
	exit(0);
}
E 1
