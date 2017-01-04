h31399
s 00010/00005/00025
d D 5.4 88/06/29 20:22:32 bostic 6 5
c install approved copyright notice
e
s 00008/00002/00022
d D 5.3 88/05/20 12:37:13 bostic 5 4
c add Berkeley specific header
e
s 00003/00001/00021
d D 5.2 86/03/13 17:42:10 mckusick 4 3
c new version from sam@monet.berkeley.edu
e
s 00007/00001/00015
d D 5.1 85/06/06 09:15:29 dist 3 2
c Add copyright
e
s 00010/00010/00006
d D 1.2 84/04/11 15:15:13 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00016/00000/00000
d D 1.1 84/04/11 15:03:16 karels 1 0
c date and time created 84/04/11 15:03:16 by karels
e
u
U
t
T
I 1
D 2
/* $Header: talk_ctl.h 1.1 83/03/26 14:36:39 moore Exp $ */
E 2
I 2
D 3
/*	%W% %G%	*/
E 3
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
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

D 4
#include "ctl.h"
E 4
I 4
#include <sys/types.h>
#include <protocols/talkd.h>
#include <netinet/in.h>
E 4
#include "talk.h"
#include <errno.h>

D 2
extern int errno;
E 2
I 2
extern	int errno;
E 2

D 2
extern struct sockaddr_in daemon_addr;
extern struct sockaddr_in ctl_addr;
extern struct sockaddr_in my_addr;
extern struct in_addr my_machine_addr;
extern struct in_addr his_machine_addr;
extern u_short daemon_port;
extern int ctl_sockt;
extern CTL_MSG msg;
E 2
I 2
extern	struct sockaddr_in daemon_addr;
extern	struct sockaddr_in ctl_addr;
extern	struct sockaddr_in my_addr;
extern	struct in_addr my_machine_addr;
extern	struct in_addr his_machine_addr;
extern	u_short daemon_port;
extern	int ctl_sockt;
extern	CTL_MSG msg;
E 2
E 1
