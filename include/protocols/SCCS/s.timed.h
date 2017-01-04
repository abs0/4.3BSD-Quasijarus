h25438
s 00010/00005/00068
d D 1.8 88/06/27 16:38:23 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00063
d D 1.7 87/12/23 14:41:50 bostic 7 6
c add Berkeley header; NASA wants a copy
e
s 00001/00001/00066
d D 1.6 86/05/28 19:00:01 bloom 6 5
c make sequence numbers consistent type
e
s 00012/00005/00055
d D 1.5 86/05/07 09:45:36 bloom 5 4
c add packet type for loop detection
e
s 00005/00003/00055
d D 1.4 86/04/18 19:17:12 bloom 4 3
c add new numbers in protocol for date request
e
s 00007/00007/00051
d D 1.3 86/01/12 15:14:33 bloom 3 2
c cleanup
e
s 00002/00012/00056
d D 1.2 85/09/18 19:37:24 bloom 2 1
c mv implementation specific stuff to server, use already defined constant for
c hostname length, change type[0]
e
s 00068/00000/00000
d D 1.1 85/06/14 23:28:31 gusella 1 0
c date and time created 85/06/14 23:28:31 by gusella
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
#define NHOSTS		30	/* max number of hosts controlled by timed */

struct host {
	char *name;
	char *addr;
	int length;
	long delta;
	u_short seq;
};

E 2
/*
 * Time Synchronization Protocol
 */

#define	TSPVERSION	1
#define ANYADDR 	NULL

struct tsp {
	u_char	tsp_type;
	u_char	tsp_vers;
D 6
	short	tsp_seq;
E 6
I 6
	u_short	tsp_seq;
E 6
D 5
	struct timeval tsp_time;
E 5
I 5
	union {
		struct timeval tspu_time;
		char tspu_hopcnt;
	} tsp_u;
E 5
D 2
	char tsp_name[32];
E 2
I 2
	char tsp_name[MAXHOSTNAMELEN];
E 2
};
I 5

#define	tsp_time	tsp_u.tspu_time
#define	tsp_hopcnt	tsp_u.tspu_hopcnt
E 5
 
/*
 * Command types.
 */
#define	TSP_ANY			0	/* match any types */
#define	TSP_ADJTIME		1	/* send adjtime */
#define	TSP_ACK			2	/* generic acknowledgement */
#define	TSP_MASTERREQ		3	/* ask for master's name */ 
D 3
#define TSP_MASTERACK		4	/* acknowledge master request */
E 3
I 3
#define	TSP_MASTERACK		4	/* acknowledge master request */
E 3
#define	TSP_SETTIME		5	/* send network time */
D 3
#define TSP_MASTERUP		6	/* inform slaves that master is up */
E 3
I 3
#define	TSP_MASTERUP		6	/* inform slaves that master is up */
E 3
#define	TSP_SLAVEUP		7	/* slave is up but not polled */
#define	TSP_ELECTION		8	/* advance candidature for master */
#define	TSP_ACCEPT		9	/* support candidature of master */
#define	TSP_REFUSE		10	/* reject candidature of master */
D 3
#define TSP_CONFLICT		11	/* two or more masters present */
E 3
I 3
#define	TSP_CONFLICT		11	/* two or more masters present */
E 3
#define	TSP_RESOLVE		12	/* masters' conflict resolution */
#define	TSP_QUIT		13	/* reject candidature if master is up */
#define	TSP_DATE		14	/* reset the time (date command) */
D 3
#define TSP_DATEREQ		15	/* remote request to reset the time */
#define TSP_DATEACK		16	/* acknowledge time setting  */
E 3
I 3
#define	TSP_DATEREQ		15	/* remote request to reset the time */
#define	TSP_DATEACK		16	/* acknowledge time setting  */
E 3
#define	TSP_TRACEON		17	/* turn tracing on */
#define	TSP_TRACEOFF		18	/* turn tracing off */
D 3
#define TSP_MSITE		19	/* find out master's site */
#define TSP_MSITEREQ		20	/* remote master's site request */
E 3
I 3
#define	TSP_MSITE		19	/* find out master's site */
#define	TSP_MSITEREQ		20	/* remote master's site request */
E 3
#define	TSP_TEST		21	/* for testing election algo */
I 4
D 5
#define TSP_SETDATE		22	/* New from date command */
#define TSP_SETDATEREQ		23	/* New remote for above */
E 5
I 5
#define	TSP_SETDATE		22	/* New from date command */
#define	TSP_SETDATEREQ		23	/* New remote for above */
#define	TSP_LOOP		24	/* loop detection packet */
E 5
E 4

D 4
#define	TSPTYPENUMBER		22
E 4
I 4
D 5
#define	TSPTYPENUMBER		24
E 5
I 5
#define	TSPTYPENUMBER		25
E 5
E 4

#ifdef TSPTYPES
char *tsptype[TSPTYPENUMBER] =
D 2
  { "#0", "ADJTIME", "ACK", "MASTERREQ", "MASTERACK", "SETTIME", "MASTERUP", 
E 2
I 2
  { "ANY", "ADJTIME", "ACK", "MASTERREQ", "MASTERACK", "SETTIME", "MASTERUP", 
E 2
  "SLAVEUP", "ELECTION", "ACCEPT", "REFUSE", "CONFLICT", "RESOLVE", "QUIT", 
D 4
  "DATE", "DATEREQ", "DATEACK", "TRACEON", "TRACEOFF", "MSITE", 
  "MSITEREQ", "TEST" };
E 4
I 4
  "DATE", "DATEREQ", "DATEACK", "TRACEON", "TRACEOFF", "MSITE", "MSITEREQ",
D 5
  "TEST", "SETDATE", "SETDATEREQ" };
E 5
I 5
  "TEST", "SETDATE", "SETDATEREQ", "LOOP" };
E 5
E 4
#endif
E 1
