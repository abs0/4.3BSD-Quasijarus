h20433
s 00018/00000/00000
d D 1.1 86/01/12 18:04:56 sam 1 0
c date and time created 86/01/12 18:04:56 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/
/*	cat.c	6.1	83/07/29	*/

main()
{
	int c, i;
	char buf[50];

	do {
		printf("File: ");
		gets(buf);
		i = open(buf, 0);
	} while (i <= 0);

	while ((c = getc(i)) > 0)
		putchar(c);
	exit(0);
}
E 1
