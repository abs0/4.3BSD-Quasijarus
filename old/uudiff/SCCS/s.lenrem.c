h26137
s 00013/00000/00000
d D 4.1 83/01/01 19:02:28 sam 1 0
c date and time created 83/01/01 19:02:28 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

main(argc,argv)
	char *argv[];
{
/* args: 1 is name to fix, 2 is this directory */
if (argv[1][0] == '/')
	printf("%s\n",argv[1]);
else
	printf("%s/%s\n", argv[2], argv[1]);
}
E 1
