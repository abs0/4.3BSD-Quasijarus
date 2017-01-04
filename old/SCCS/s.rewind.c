h26186
s 00013/00000/00000
d D 4.1 80/10/01 17:28:12 bill 1 0
c date and time created 80/10/01 17:28:12 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
/* rewinds mag tape drive */
main(argc,argv) char**argv; {
	char *f;
	int fd;

	if (argc > 1) f = argv[1];
		else  f = "/dev/mt0";

	fd = open(f,0);
	if (fd < 0) printf("Can't open %s\n",f);
		else close(fd);
}
E 1
