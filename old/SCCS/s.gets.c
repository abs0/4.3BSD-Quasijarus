h48640
s 00001/00000/00024
d D 4.2 81/06/19 13:47:16 wnj 2 1
c fix to bug per hpk
e
s 00024/00000/00000
d D 4.1 80/10/01 17:26:59 bill 1 0
c date and time created 80/10/01 17:26:59 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
#include <stdio.h>

/*
 * gets [ default ]
 *
 *      read a line from standard input, echoing to std output
 *      if an error occurs just return "default"
 *      if no default and error exit abnormally
 */
main(argc, argv)
	int argc;
	char *argv[];
{
	char buf[BUFSIZ];
	
I 2
	setbuf(stdin, NULL);
E 2
	if (gets(buf) == NULL || buf[0] < ' ') {
		if (argc == 1)
			exit(1);
		strcpy(buf,argv[1]);
	}
	printf("%s\n", buf);
	exit(0);
}
E 1
