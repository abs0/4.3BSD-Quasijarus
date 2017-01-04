h20743
s 00012/00000/00000
d D 4.1 83/01/01 19:02:29 sam 1 0
c date and time created 83/01/01 19:02:29 by sam
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
char *p;
for (p=argv[1]; *p; p++);
while (*p != '/') p--;
printf("%s\n", p+1);
}
E 1
