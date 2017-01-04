h42847
s 00010/00005/00090
d D 2.6 88/06/18 14:08:14 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00085
d D 2.5 87/12/23 14:30:08 bostic 7 6
c append Berkeley header; NASA wants a copy
e
s 00019/00010/00070
d D 2.4 86/05/27 15:34:12 karels 6 5
c add MAXADJ, and some comments
e
s 00001/00001/00079
d D 2.3 86/04/21 15:16:14 bloom 5 4
c increase TRIALS since algorithm has been rewritten
e
s 00005/00000/00075
d D 2.2 86/04/11 18:16:16 bloom 4 3
c major work on multiple network code (Kirk Smith, ks@ef.purdue.edu)
e
s 00026/00003/00049
d D 2.1 85/12/10 13:06:53 bloom 3 2
c Multi network support
e
s 00021/00001/00031
d D 1.2 85/09/18 19:34:18 bloom 2 1
c shuffle constants between files, move host structure from timed.h, add some
c global vars
e
s 00032/00000/00000
d D 1.1 85/06/22 22:07:52 gusella 1 0
c date and time created 85/06/22 22:07:52 by gusella
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
 *
 *	%W% (Berkeley) %G%
E 7
 */
D 7

/*	%W%	(Berkeley)	%G%	*/
E 7

D 2
#include <sys/types.h>
E 2
I 2
#include <sys/param.h>
E 2
#include <stdio.h>
#include <sys/time.h>
#include <errno.h>
#include <syslog.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

extern int errno;
I 3
extern int sock;
E 3

D 6
#define RANGE		20
#define MSGS 		5
D 5
#define TRIALS		6
E 5
I 5
#define TRIALS		10
E 5
#define SAMPLEINTVL	240	
#define MAXSEQ 		30000
E 6
I 6
#define SAMPLEINTVL	240		/* synch() freq for master, sec */
#define	MAXADJ		20		/* max correction (sec) for adjtime */
/*
 * Parameters for network time measurement
 * of each host using ICMP timestamp requests.
 */
#define RANGE		20		/* best expected round-trip time, ms */
#define MSGS 		5		/* # of timestamp replies to average */
#define TRIALS		10		/* max # of timestamp echos sent */

E 6
#define MINTOUT		360
#define MAXTOUT		900

#define GOOD		1
#define UNREACHABLE	2
#define NONSTDTIME	3
#define HOSTDOWN 	0x7fffffff
I 2

#define OFF	0
#define ON	1

D 6
#define SLAVE 	1
#define MASTER	2
#define IGNORE	4
#define ALL	(SLAVE|MASTER|IGNORE)
E 6
I 6
/*
 * Global and per-network states.
 */
#define NOMASTER 	0		/* no master on any network */
#define SLAVE 		1
#define MASTER		2
#define IGNORE		4
#define ALL		(SLAVE|MASTER|IGNORE)
E 6
I 3
#define SUBMASTER	(SLAVE|MASTER)
E 3

D 6
#define NHOSTS		30	/* max number of hosts controlled by timed */
E 6
I 6
#define NHOSTS		100	/* max number of hosts controlled by timed */
E 6

struct host {
	char *name;
D 3
	char *addr;
	int length;
E 3
I 3
	struct sockaddr_in addr;
E 3
	long delta;
	u_short seq;
};

D 3
u_long	mynet, netmask;
E 3
I 3
struct netinfo {
	struct netinfo *next;
	u_long net;
	u_long mask;
	struct in_addr my_addr;
	struct sockaddr_in dest_addr;	/* broadcast addr or point-point */
	long status;
};

extern struct netinfo *nettab;
extern int status;
extern int trace;
extern int sock;
extern struct sockaddr_in from;
I 4
extern struct netinfo *fromnet, *slavenet;
E 4
extern FILE *fd;
extern char hostname[];
extern char tracefile[];
extern struct host hp[];
extern int backoff;
extern long delay1, delay2;
extern int slvcount;
I 4
extern int nslavenets;		/* Number of nets were I could be a slave */
extern int nmasternets;		/* Number of nets were I could be a master */
extern int nignorednets;	/* Number of ignored nets */
extern int nnets;		/* Number of nets I am connected to */
E 4

char *strcpy(), *malloc();
E 3
E 2
E 1
