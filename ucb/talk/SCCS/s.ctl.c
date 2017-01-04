h11518
s 00010/00005/00080
d D 5.4 88/06/29 20:22:13 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00076
d D 5.3 88/05/20 12:36:57 bostic 5 4
c add Berkeley specific header
e
s 00029/00029/00050
d D 5.2 86/03/13 17:40:07 mckusick 4 3
c new version from sam@monet.berkeley.edu
e
s 00007/00001/00072
d D 5.1 85/06/06 09:16:34 dist 3 2
c Add copyright
e
s 00025/00041/00048
d D 1.2 84/04/11 15:13:18 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00089/00000/00000
d D 1.1 84/04/11 15:02:43 karels 1 0
c date and time created 84/04/11 15:02:43 by karels
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
/* $Header: ctl.c 1.4 83/06/09 23:37:01 moore Exp $ */
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

D 2
/* This file handles haggling with the various talk daemons to
   get a socket to talk to. sockt is opened and connected in
   the progress
E 2
I 2
/*
 * This file handles haggling with the various talk daemons to
 * get a socket to talk to. sockt is opened and connected in
 * the progress
E 2
 */

#include "talk_ctl.h"

D 2
struct sockaddr_in daemon_addr = { AF_INET };
struct sockaddr_in ctl_addr = { AF_INET };
struct sockaddr_in my_addr = { AF_INET };
E 2
I 2
struct	sockaddr_in daemon_addr = { AF_INET };
struct	sockaddr_in ctl_addr = { AF_INET };
struct	sockaddr_in my_addr = { AF_INET };
E 2

D 4
    /* inet addresses of the two machines */
E 4
I 4
	/* inet addresses of the two machines */
E 4
D 2
struct in_addr my_machine_addr;
struct in_addr his_machine_addr;
E 2
I 2
struct	in_addr my_machine_addr;
struct	in_addr his_machine_addr;
E 2

u_short daemon_port;	/* port number of the talk daemon */

D 2
int ctl_sockt;
int sockt;
int invitation_waiting = 0;
E 2
I 2
int	ctl_sockt;
int	sockt;
int	invitation_waiting = 0;
E 2

CTL_MSG msg;

open_sockt()
{
D 4
    int length;
E 4
I 4
	int length;
E 4

D 4
    my_addr.sin_addr = my_machine_addr;
    my_addr.sin_port = 0;
D 2

    sockt = socket(AF_INET, SOCK_STREAM, 0, 0);

    if (sockt <= 0) {
E 2
I 2
    sockt = socket(AF_INET, SOCK_STREAM, 0);
    if (sockt <= 0)
E 2
	p_error("Bad socket");
D 2
    }

    if ( bind(sockt, &my_addr, sizeof(my_addr)) != 0) {
E 2
I 2
    if (bind(sockt, &my_addr, sizeof(my_addr)) != 0)
E 2
	p_error("Binding local socket");
D 2
    }

E 2
    length = sizeof(my_addr);
D 2

    if (getsockname(sockt, &my_addr, &length) == -1) {
E 2
I 2
    if (getsockname(sockt, &my_addr, &length) == -1)
E 2
	p_error("Bad address for socket");
E 4
I 4
	my_addr.sin_addr = my_machine_addr;
	my_addr.sin_port = 0;
	sockt = socket(AF_INET, SOCK_STREAM, 0);
	if (sockt <= 0)
		p_error("Bad socket");
	if (bind(sockt, &my_addr, sizeof(my_addr)) != 0)
		p_error("Binding local socket");
	length = sizeof(my_addr);
	if (getsockname(sockt, &my_addr, &length) == -1)
		p_error("Bad address for socket");
E 4
D 2
    }
E 2
}

D 2
    /* open the ctl socket */

E 2
I 2
/* open the ctl socket */
E 2
open_ctl() 
{
D 4
    int length;
E 4
I 4
	int length;
E 4

D 4
    ctl_addr.sin_port = 0;
    ctl_addr.sin_addr = my_machine_addr;
D 2

    ctl_sockt = socket(AF_INET, SOCK_DGRAM, 0, 0);

    if (ctl_sockt <= 0) {
E 2
I 2
    ctl_sockt = socket(AF_INET, SOCK_DGRAM, 0);
    if (ctl_sockt <= 0)
E 2
	p_error("Bad socket");
D 2
    }

    if (bind(ctl_sockt, &ctl_addr, sizeof(ctl_addr), 0) != 0) {
E 2
I 2
    if (bind(ctl_sockt, &ctl_addr, sizeof(ctl_addr), 0) != 0)
E 2
	p_error("Couldn't bind to control socket");
D 2
    }

E 2
    length = sizeof(ctl_addr);
D 2
    if (getsockname(ctl_sockt, &ctl_addr, &length) == -1) {
E 2
I 2
    if (getsockname(ctl_sockt, &ctl_addr, &length) == -1)
E 2
	p_error("Bad address for ctl socket");
E 4
I 4
	ctl_addr.sin_port = 0;
	ctl_addr.sin_addr = my_machine_addr;
	ctl_sockt = socket(AF_INET, SOCK_DGRAM, 0);
	if (ctl_sockt <= 0)
		p_error("Bad socket");
	if (bind(ctl_sockt, &ctl_addr, sizeof(ctl_addr), 0) != 0)
		p_error("Couldn't bind to control socket");
	length = sizeof(ctl_addr);
	if (getsockname(ctl_sockt, &ctl_addr, &length) == -1)
		p_error("Bad address for ctl socket");
E 4
D 2
    }
E 2
}

/* print_addr is a debug print routine */
D 2

E 2
print_addr(addr)
D 4
struct sockaddr_in addr;
E 4
I 4
	struct sockaddr_in addr;
E 4
{
D 4
    int i;
E 4
I 4
	int i;
E 4

D 4
    printf("addr = %x, port = %o, family = %o zero = ",
	    addr.sin_addr, addr.sin_port, addr.sin_family);
D 2

    for (i = 0; i<8;i++) {
E 2
I 2
    for (i = 0; i<8;i++)
E 4
I 4
	printf("addr = %x, port = %o, family = %o zero = ",
		addr.sin_addr, addr.sin_port, addr.sin_family);
	for (i = 0; i<8;i++)
E 4
E 2
	printf("%o ", (int)addr.sin_zero[i]);
D 2
    }
E 2
D 4
    putchar('\n');
E 4
I 4
	putchar('\n');
E 4
}
E 1
