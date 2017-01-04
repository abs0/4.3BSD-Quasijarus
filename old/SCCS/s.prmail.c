h61878
s 00015/00001/00060
d D 5.1 85/05/31 09:24:19 dist 3 2
c Add copyright
e
s 00001/00001/00060
d D 4.2 83/02/09 15:19:12 sam 2 1
c dumb
e
s 00061/00000/00000
d D 4.1 80/10/10 00:51:33 bill 1 0
c date and time created 80/10/10 00:51:33 by bill
e
u
U
t
T
I 1
D 3
static	char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

#include <pwd.h>
/*
 * prmail
 */
struct	passwd *getpwuid();
char	*getenv();

main(argc, argv)
	int argc;
	char **argv;
{
	register struct passwd *pp;

	--argc, ++argv;
	if (chdir("/usr/spool/mail") < 0) {
		perror("/usr/spool/mail");
		exit(1);
	}
	if (argc == 0) {
		char *user = getenv("USER");
		if (user == 0) {
			pp = getpwuid(getuid());
			if (pp == 0) {
				printf("Who are you?\n");
				exit(1);
			}
			user = pp->pw_name;
		}
		prmail(user, 0);
	} else
		while (--argc >= 0)
			prmail(*argv++, 1);
	exit(0);
}

#include <sys/types.h>
#include <sys/stat.h>

prmail(user, other)
	char *user;
{
	struct stat stb;
	char cmdbuf[256];

	if (stat(user, &stb) < 0) {
		printf("No mail for %s.\n", user);
		return;
	}
D 2
	if (access(user, "4") < 0) {
E 2
I 2
	if (access(user, 4) < 0) {
E 2
		printf("Mailbox for %s unreadable\n", user);
		return;
	}
	if (other)
		printf(">>> %s <<<\n", user);
	sprintf(cmdbuf, "more %s", user);
	system(cmdbuf);
	if (other)
		printf("-----\n\n");
}
E 1
