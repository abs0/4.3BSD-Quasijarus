h32039
s 00015/00007/00057
d D 5.5 03/05/09 21:36:32 msokolov 7 6
c allow remote host specification by numeric IP address
e
s 00010/00005/00054
d D 5.4 88/06/29 20:22:17 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00050
d D 5.3 88/05/20 12:37:01 bostic 5 4
c add Berkeley specific header
e
s 00020/00019/00033
d D 5.2 86/03/13 17:40:37 mckusick 4 3
c new version from sam@monet.berkeley.edu
e
s 00007/00001/00045
d D 5.1 85/06/06 09:17:37 dist 3 2
c Add copyright
e
s 00034/00065/00012
d D 1.2 84/04/11 15:13:43 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00077/00000/00000
d D 1.1 84/04/11 15:02:50 karels 1 0
c date and time created 84/04/11 15:02:50 by karels
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */

E 3
I 1
D 2
/* $Header: get_addrs.c 1.5 83/04/01 17:55:41 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 3
E 2

#include "talk_ctl.h"
I 7
#include <arpa/inet.h>
E 7
I 4
#include <netdb.h>
E 4

D 2
struct hostent *gethostbyname();
struct servent *getservbyname();
E 2
I 2
D 4
struct	hostent *gethostbyname();
struct	servent *getservbyname();
E 2

E 4
get_addrs(my_machine_name, his_machine_name)
D 2
char *my_machine_name;
char *his_machine_name;
E 2
I 2
D 4
	char *my_machine_name;
	char *his_machine_name;
E 4
I 4
	char *my_machine_name, *his_machine_name;
E 4
E 2
{
D 2
    struct hostent *hp;
    struct servent *sp;
E 2
I 2
	struct hostent *hp;
	struct servent *sp;
I 7
	long ip;
E 7
E 2

D 2
    msg.pid = getpid();

E 2
I 2
D 4
	msg.pid = getpid();
E 4
I 4
	msg.pid = htonl(getpid());
E 4
E 2
	/* look up the address of the local host */
D 2

    hp = gethostbyname(my_machine_name);

    if (hp == (struct hostent *) 0) {
	printf("This machine doesn't exist. Boy, am I confused!\n");
	exit(-1);
    }

    if (hp->h_addrtype != AF_INET) {
	printf("Protocal mix up with local machine address\n");
	exit(-1);
    }

    bcopy(hp->h_addr, (char *)&my_machine_addr, hp->h_length);

E 2
I 2
	hp = gethostbyname(my_machine_name);
	if (hp == (struct hostent *) 0) {
D 4
		printf("This machine doesn't exist. Boy, am I confused!\n");
E 4
I 4
		fprintf(stderr,
		    "talk: %s: Can't figure out network address.\n",
		    my_machine_name);
E 4
		exit(-1);
	}
	bcopy(hp->h_addr, (char *)&my_machine_addr, hp->h_length);
E 2
D 4
	/* if he is on the same machine, then simply copy */
D 2

    if ( bcmp((char *)&his_machine_name, (char *)&my_machine_name,
		sizeof(his_machine_name)) == 0) {
	bcopy((char *)&my_machine_addr, (char *)&his_machine_addr,
		sizeof(his_machine_name));
    } else {

	/* look up the address of the recipient's machine */

	hp = gethostbyname(his_machine_name);

	if (hp == (struct hostent *) 0 ) {
	    printf("%s is an unknown host\n", his_machine_name);
	    exit(-1);
E 2
I 2
	if (bcmp((char *)&his_machine_name, (char *)&my_machine_name,
	    sizeof(his_machine_name)) == 0)
		bcopy((char *)&my_machine_addr, (char *)&his_machine_addr,
		    sizeof(his_machine_name));
	else {
		/* look up the address of the recipient's machine */
E 4
I 4
	/*
	 * If the callee is on-machine, just copy the
	 * network address, otherwise do a lookup...
	 */
	if (strcmp(his_machine_name, my_machine_name)) {
E 4
D 7
		hp = gethostbyname(his_machine_name);
		if (hp == (struct hostent *) 0 ) {
D 4
			printf("%s is an unknown host\n", his_machine_name);
E 4
I 4
			fprintf(stderr,
			    "talk: %s: Can't figure out network address.\n",
			    his_machine_name);
E 4
			exit(-1);
E 7
I 7
		ip = inet_addr(his_machine_name);
		if (ip != -1)
			bcopy(&ip, (char *) &his_machine_addr, sizeof(ip));
		else {
			hp = gethostbyname(his_machine_name);
			if (hp == (struct hostent *) 0 ) {
			    fprintf(stderr,
				"talk: %s: Can't figure out network address.\n",
				his_machine_name);
			    exit(-1);
			}
			bcopy(hp->h_addr, (char *) &his_machine_addr,
				hp->h_length);
E 7
		}
D 7
		bcopy(hp->h_addr, (char *) &his_machine_addr, hp->h_length);
E 7
E 2
D 4
	}
D 2

	if (hp->h_addrtype != AF_INET) {
	    printf("Protocol mix up with remote machine address\n");
	    exit(-1);
	}

	bcopy(hp->h_addr, (char *) &his_machine_addr, hp->h_length);
    }

E 2
	/* find the daemon portal */
D 2

#ifdef NTALK
    sp = getservbyname("ntalk", "udp");
#else
    sp = getservbyname("talk", "udp");
#endif

    if (strcmp(sp->s_proto, "udp") != 0) {
	printf("Protocol mix up with talk daemon\n");
	exit(-1);
    }

    if (sp == 0) {
	    p_error("This machine doesn't support a tcp talk daemon");
	    exit(-1);
    }

    daemon_port = sp->s_port;
E 2
I 2
	sp = getservbyname("talk", "udp");
E 4
I 4
	} else
		his_machine_addr = my_machine_addr;
	/* find the server's port */
	sp = getservbyname("ntalk", "udp");
E 4
	if (sp == 0) {
D 4
		p_error("This machine doesn't support talk");
E 4
I 4
		fprintf(stderr, "talk: %s/%s: service is not registered.\n",
		     "ntalk", "udp");
E 4
		exit(-1);
	}
	daemon_port = sp->s_port;
E 2
}
E 1
