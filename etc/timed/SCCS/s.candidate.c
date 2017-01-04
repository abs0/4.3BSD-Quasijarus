h18951
s 00010/00005/00121
d D 2.5 88/06/18 14:08:03 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00117
d D 2.4 87/12/23 14:29:58 bostic 8 7
c append Berkeley header; NASA wants a copy
e
s 00002/00002/00118
d D 2.3 86/04/21 15:52:02 bloom 7 6
c date now passes off an absolute time, packet types changed
e
s 00001/00001/00119
d D 2.2 86/04/11 18:16:09 bloom 6 5
c major work on multiple network code (Kirk Smith, ks@ef.purdue.edu)
e
s 00015/00017/00105
d D 2.1 85/12/10 13:06:23 bloom 5 4
c Multi network support
e
s 00001/00000/00121
d D 1.4 85/11/16 19:07:53 bloom 4 3
c make sure bytenetorder not called multiple times per packet
e
s 00062/00056/00059
d D 1.3 85/11/16 17:45:59 bloom 3 2
c use loop constructs instead of goto's
e
s 00002/00004/00113
d D 1.2 85/09/18 19:44:41 bloom 2 1
c move constants to header file, fix syslog messages
e
s 00117/00000/00000
d D 1.1 85/06/22 22:07:47 gusella 1 0
c date and time created 85/06/22 22:07:47 by gusella
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8

#include "globals.h"
#include <protocols/timed.h>

D 2
#define MASTER 		1
#define SLAVE 		0
E 2
#define ELECTIONWAIT	3	/* seconds */

D 5
extern int trace;
extern int slvcount;
extern int backoff;
extern long delay2;
extern char hostname[];
extern struct sockaddr_in from;
extern struct sockaddr_in server;
extern FILE *fd;

E 5
/*
 * `election' candidates a host as master: it is called by a slave 
 * which runs with the -M option set when its election timeout expires. 
 * Note the conservative approach: if a new timed comes up, or another
 * candidate sends an election request, the candidature is withdrawn.
 */

D 5
election()
E 5
I 5
election(net)
struct netinfo *net;
E 5
{
	int ret;
D 5
	char *strcpy();
E 5
	struct tsp *resp, msg, *readmsg();
	struct timeval wait;
	struct tsp *answer, *acksend();
	long casual();
I 5
	struct sockaddr_in server;
E 5

D 2
	syslog(LOG_ERR, "timed: THIS MACHINE IS A CANDIDATE\n");
E 2
I 2
	syslog(LOG_INFO, "THIS MACHINE IS A CANDIDATE");
E 2
	if (trace) {
		fprintf(fd, "THIS MACHINE IS A CANDIDATE\n");
	}

	ret = MASTER;
	slvcount = 1;

	msg.tsp_type = TSP_ELECTION;
I 5
	msg.tsp_vers = TSPVERSION;
E 5
	(void)strcpy(msg.tsp_name, hostname);
I 4
	bytenetorder(&msg);
E 4
D 5
	broadcast(&msg);
E 5
I 5
	if (sendto(sock, (char *)&msg, sizeof(struct tsp), 0, &net->dest_addr,
	    sizeof(struct sockaddr_in)) < 0) {
		syslog(LOG_ERR, "sendto: %m");
		exit(1);
	}
E 5

D 3
loop:
	wait.tv_sec = ELECTIONWAIT;
	wait.tv_usec = 0;
	resp = readmsg(TSP_ANY, (char *)ANYADDR, &wait);
	if (resp != NULL) {
		switch (resp->tsp_type) {
E 3
I 3
	do {
		wait.tv_sec = ELECTIONWAIT;
		wait.tv_usec = 0;
D 5
		resp = readmsg(TSP_ANY, (char *)ANYADDR, &wait);
E 5
I 5
		resp = readmsg(TSP_ANY, (char *)ANYADDR, &wait, net);
E 5
		if (resp != NULL) {
			switch (resp->tsp_type) {
E 3

D 3
		case TSP_ACCEPT:
			(void) addmach(resp->tsp_name);
			break;
		case TSP_MASTERUP:
		case TSP_MASTERREQ:
			/*
			 * If a timedaemon is coming up at the same time,
			 * give up the candidature: it will be the master.
			 */
			ret = SLAVE;
			break;
		case TSP_QUIT:
		case TSP_REFUSE:
			/*
			 * Collision: change value of election timer 
			 * using exponential backoff.
			 * The value of timer will be recomputed (in slave.c)
			 * using the original interval when election will 
			 * be successfully completed.
			 */
			backoff *= 2;
			delay2 = casual((long)MINTOUT, 
						(long)(MAXTOUT * backoff));
			ret = SLAVE;
			break;
		case TSP_ELECTION:
			/* no master for another round */
			msg.tsp_type = TSP_REFUSE;
			(void)strcpy(msg.tsp_name, hostname);
			server = from;
			answer = acksend(&msg, resp->tsp_name, TSP_ACK);
			if (answer == NULL) {
D 2
				syslog(LOG_ERR, "timed: error in election\n");
E 2
I 2
				syslog(LOG_ERR, "error in election");
E 2
			} else {
E 3
I 3
			case TSP_ACCEPT:
E 3
D 5
				(void) addmach(resp->tsp_name);
E 5
I 5
				(void) addmach(resp->tsp_name, &from);
E 5
I 3
				break;

			case TSP_MASTERUP:
			case TSP_MASTERREQ:
				/*
				 * If a timedaemon is coming up at the same time,
				 * give up the candidature: it will be the master.
				 */
				ret = SLAVE;
				break;

			case TSP_QUIT:
			case TSP_REFUSE:
				/*
				 * Collision: change value of election timer 
				 * using exponential backoff.
				 * The value of timer will be recomputed (in slave.c)
				 * using the original interval when election will 
				 * be successfully completed.
				 */
				backoff *= 2;
				delay2 = casual((long)MINTOUT, 
							(long)(MAXTOUT * backoff));
				ret = SLAVE;
				break;

			case TSP_ELECTION:
				/* no master for another round */
				msg.tsp_type = TSP_REFUSE;
				(void)strcpy(msg.tsp_name, hostname);
				server = from;
D 5
				answer = acksend(&msg, resp->tsp_name, TSP_ACK);
E 5
I 5
				answer = acksend(&msg, &server, resp->tsp_name,
				    TSP_ACK, (struct netinfo *)NULL);
E 5
				if (answer == NULL) {
					syslog(LOG_ERR, "error in election");
				} else {
D 5
					(void) addmach(resp->tsp_name);
E 5
I 5
					(void) addmach(resp->tsp_name, &from);
E 5
				}
				break;

			case TSP_SLAVEUP:
D 5
				(void) addmach(resp->tsp_name);
E 5
I 5
				(void) addmach(resp->tsp_name, &from);
E 5
				break;

D 7
			case TSP_DATE:
			case TSP_DATEREQ:
E 7
I 7
			case TSP_SETDATE:
			case TSP_SETDATEREQ:
E 7
				break;

			default:
				if (trace) {
					fprintf(fd, "candidate: ");
D 6
					print(resp);
E 6
I 6
					print(resp, &from);
E 6
				}
				break;
E 3
			}
I 3
		} else {
E 3
			break;
D 3
		case TSP_SLAVEUP:
			(void) addmach(resp->tsp_name);
			break;
		case TSP_DATE:
		case TSP_DATEREQ:
			break;
		default:
			if (trace) {
				fprintf(fd, "candidate: ");
				print(resp);
			}
			break;
E 3
		}
D 3

		if (ret == MASTER)
			goto loop;
	}
E 3
I 3
	} while (ret == MASTER);
E 3
	return(ret);
}
E 1
