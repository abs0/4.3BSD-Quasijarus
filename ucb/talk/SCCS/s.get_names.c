h07125
s 00010/00005/00102
d D 5.5 88/06/29 20:22:19 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00098
d D 5.4 88/05/20 12:37:03 bostic 6 5
c add Berkeley specific header
e
s 00009/00006/00092
d D 5.3 88/05/20 12:10:57 edward 5 4
c use getpwuid in addition to getlogin to get user name, and some cleanup
e
s 00037/00024/00061
d D 5.2 86/03/13 17:40:45 mckusick 4 3
c new version from sam@monet.berkeley.edu
e
s 00007/00001/00078
d D 5.1 85/06/06 09:17:52 dist 3 2
c Add copyright
e
s 00061/00085/00018
d D 1.2 84/04/11 15:13:50 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00103/00000/00000
d D 1.1 84/04/11 15:02:52 karels 1 0
c date and time created 84/04/11 15:02:52 by karels
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 7
E 6
 */

E 3
I 1
D 2
/* $Header: get_names.c 1.2 83/03/26 14:35:54 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6
E 3
E 2

#include "talk.h"
D 4
#include "ctl.h"
E 4
I 4
#include <sys/param.h>
#include <protocols/talkd.h>
I 5
#include <pwd.h>
E 5
E 4

D 4
char *getlogin(), *ttyname(), *rindex();
E 4
I 4
char	*getlogin();
char	*ttyname();
char	*rindex();
D 5
static	any();
E 5
extern	CTL_MSG msg;
E 4

D 4
extern CTL_MSG msg;

I 2
struct hostent *gethostbyname();

E 4
E 2
/*
 * Determine the local and remote user, tty, and machines
 */
D 2

struct hostent *gethostbyname();

E 2
get_names(argc, argv)
D 2
int argc;
char *argv[];
E 2
I 2
	int argc;
	char *argv[];
E 2
{
D 2
    char hostname[HOST_NAME_LENGTH];
    char *his_name;
    char *my_name;
    char *my_machine_name;
    char *his_machine_name;
    char *my_tty;
    char *his_tty;
    char *ptr;
    int name_length;
E 2
I 2
D 4
	char hostname[HOST_NAME_LENGTH];
	char *his_name;
	char *my_name;
	char *my_machine_name;
	char *his_machine_name;
	char *my_tty;
	char *his_tty;
	char *ptr;
E 4
I 4
	char hostname[MAXHOSTNAMELEN];
	char *his_name, *my_name;
	char *my_machine_name, *his_machine_name;
	char *my_tty, *his_tty;
	register char *cp;
E 4
E 2

D 2
    if (argc < 2 ) {
	printf("Usage:  talk user [ttyname]\n");
	exit(-1);
    }
    if ( !isatty(0) ) {
	printf("Standard input must be a tty, not a pipe or a file\n");
	exit(-1);
    }

    my_name = getlogin();
    if (my_name == NULL) {
	printf("You don't exist. Go away.\n");
	exit(-1);
    }

    name_length = HOST_NAME_LENGTH;
    gethostname(hostname, &name_length);
    my_machine_name = hostname;

    my_tty = rindex(ttyname(0), '/') + 1;

	/* check for, and strip out, the machine name 
	    of the target */

    for (ptr = argv[1]; *ptr != '\0' &&
			 *ptr != '@' &&
			 *ptr != ':' &&
			 *ptr != '!' &&
			 *ptr != '.'     ; ptr++) {
    }

    if (*ptr == '\0') {

	    /* this is a local to local talk */

	his_name = argv[1];
	his_machine_name = my_machine_name;

    } else {

	if (*ptr == '@') {
		/* user@host */
	    his_name = argv[1];
	    his_machine_name = ptr + 1;
E 2
I 2
	if (argc < 2 ) {
D 4
		printf("Usage:	talk user [ttyname]\n");
E 4
I 4
		printf("Usage: talk user [ttyname]\n");
E 4
		exit(-1);
	}
	if (!isatty(0)) {
		printf("Standard input must be a tty, not a pipe or a file\n");
		exit(-1);
	}
D 5
	my_name = getlogin();
	if (my_name == NULL) {
		printf("You don't exist. Go away.\n");
		exit(-1);
E 5
I 5
	if ((my_name = getlogin()) == NULL) {
		struct passwd *pw;

		if ((pw = getpwuid(getuid())) == NULL) {
			printf("You don't exist. Go away.\n");
			exit(-1);
		}
		my_name = pw->pw_name;
E 5
	}
	gethostname(hostname, sizeof (hostname));
	my_machine_name = hostname;
D 5
	my_tty = rindex(ttyname(0), '/') + 1;
E 5
	/* check for, and strip out, the machine name of the target */
D 4
	for (ptr = argv[1]; *ptr != '\0' && *ptr != '@' && *ptr != ':' &&
	    *ptr != '!' && *ptr != '.'; ptr++)
E 4
I 4
	for (cp = argv[1]; *cp && !any(*cp, "@:!."); cp++)
E 4
		;
D 4
	if (*ptr == '\0') {
E 4
I 4
	if (*cp == '\0') {
E 4
		/* this is a local to local talk */
		his_name = argv[1];
		his_machine_name = my_machine_name;
E 2
	} else {
D 2
		/* host.user or host!user or host:user */
	    his_name = ptr + 1;
	    his_machine_name = argv[1];
E 2
I 2
D 4
		if (*ptr == '@') {
E 4
I 4
		if (*cp++ == '@') {
E 4
			/* user@host */
			his_name = argv[1];
D 4
			his_machine_name = ptr + 1;
E 4
I 4
			his_machine_name = cp;
E 4
		} else {
			/* host.user or host!user or host:user */
D 4
			his_name = ptr + 1;
E 4
I 4
			his_name = cp;
E 4
			his_machine_name = argv[1];
		}
D 4
		*ptr = '\0';
E 4
I 4
		*--cp = '\0';
E 4
E 2
	}
D 2
	*ptr = '\0';
    }


    if (argc > 2) {
	his_tty = argv[2];	/* tty name is arg 2 */
    } else {
	his_tty = (char *) 0;
    }

    get_addrs(my_machine_name, his_machine_name);

E 2
I 2
	if (argc > 2)
		his_tty = argv[2];	/* tty name is arg 2 */
	else
		his_tty = "";
	get_addrs(my_machine_name, his_machine_name);
E 2
D 4
	/* Load these useful values into the standard message header */
D 2

    msg.id_num = 0;

    strncpy(msg.l_name, my_name, NAME_SIZE);
    msg.l_name[NAME_SIZE - 1] = '\0';

    strncpy(msg.r_name, his_name, NAME_SIZE);
    msg.r_name[NAME_SIZE - 1] = '\0';

    strncpy(msg.r_tty, his_tty, TTY_SIZE);
    msg.r_tty[TTY_SIZE - 1] = '\0';
E 2
I 2
	msg.id_num = 0;
E 4
I 4
	/*
	 * Initialize the message template.
	 */
	msg.vers = TALK_VERSION;
	msg.addr.sa_family = htons(AF_INET);
	msg.ctl_addr.sa_family = htons(AF_INET);
	msg.id_num = htonl(0);
E 4
	strncpy(msg.l_name, my_name, NAME_SIZE);
	msg.l_name[NAME_SIZE - 1] = '\0';
	strncpy(msg.r_name, his_name, NAME_SIZE);
	msg.r_name[NAME_SIZE - 1] = '\0';
	strncpy(msg.r_tty, his_tty, TTY_SIZE);
	msg.r_tty[TTY_SIZE - 1] = '\0';
I 4
}

static
any(c, cp)
	register char c, *cp;
{

	while (*cp)
		if (c == *cp++)
			return (1);
	return (0);
E 4
E 2
}
E 1
