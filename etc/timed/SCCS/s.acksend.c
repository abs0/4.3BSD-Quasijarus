h52313
s 00010/00005/00083
d D 2.6 88/06/18 14:08:00 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00079
d D 2.5 87/12/23 14:29:55 bostic 8 7
c append Berkeley header; NASA wants a copy
e
s 00002/00003/00080
d D 2.4 86/05/27 15:57:56 karels 7 6
c toss MAXSEQ
e
s 00001/00001/00082
d D 2.3 86/04/11 18:16:02 bloom 6 5
c major work on multiple network code (Kirk Smith, ks@ef.purdue.edu)
e
s 00006/00000/00077
d D 2.2 86/04/11 16:35:29 bloom 5 4
c check sequence number
e
s 00010/00017/00067
d D 2.1 85/12/10 13:06:17 bloom 4 3
c Multi network support
e
s 00014/00005/00070
d D 1.3 85/11/16 19:07:49 bloom 3 2
c make sure bytenetorder not called multiple times per packet
e
s 00001/00001/00074
d D 1.2 85/09/18 19:43:10 bloom 2 1
c fix syslog messages
e
s 00075/00000/00000
d D 1.1 85/06/22 22:07:44 gusella 1 0
c date and time created 85/06/22 22:07:44 by gusella
e
u
U
t
T
I 1
/*
D 7
 * Copyright (c) 1983 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1985 Regents of the University of California.
E 7
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

#define RECEIVED	0
#define LOST	 	1
#define SECFORACK	1	/* seconds */
#define USECFORACK	0	/* microseconds */
#define MAXCOUNT	5

struct tsp *answer;
D 4
extern int sock;
extern struct sockaddr_in server;
I 3
extern int trace;
extern FILE *fd;
E 4
E 3

/*
 * Acksend implements reliable datagram transmission by using sequence 
 * numbers and retransmission when necessary.
D 4
 * `name' is set to name of destination whose address is in global 
 * variable `server'.
E 4
I 4
 * `name' is the name of the destination
 * `addr' is the address to send to
E 4
 * If `name' is ANYADDR, this routine implements reliable broadcast.
 */

D 4
struct tsp *acksend(message, name, ack)
E 4
I 4
struct tsp *acksend(message, addr, name, ack, net)
E 4
struct tsp *message;
I 4
struct sockaddr_in *addr;
E 4
char *name;
int ack;
I 4
struct netinfo *net;
E 4
{
	int count;
	int flag;
	extern u_short sequence;
	struct timeval tout;
	struct tsp *readmsg();
D 3
	int bytenetorder();
E 3

	count = 0;

I 3
	message->tsp_vers = TSPVERSION;
	message->tsp_seq = sequence;
	if (trace) {
		fprintf(fd, "acksend: ");
		if (name == ANYADDR)
			fprintf(fd, "broadcast: ");
		else
			fprintf(fd, "%s: ", name);
D 6
		print(message);
E 6
I 6
		print(message, addr);
E 6
	}
	bytenetorder(message);
E 3
	do {
D 3
		message->tsp_seq = sequence;
E 3
D 4
		if (name == ANYADDR) {
			broadcast(message);
		} else {
D 3
			message->tsp_vers = TSPVERSION;
			bytenetorder(message);
E 3
			if (sendto(sock, (char *)message, sizeof(struct tsp),
					0, &server, 
					sizeof(struct sockaddr_in)) < 0) {
D 2
				syslog(LOG_ERR, "timed: sendto: %m");
E 2
I 2
D 3
				syslog(LOG_ERR, "sendto: %m");
E 3
I 3
				syslog(LOG_ERR, "acksend: sendto: %m");
E 3
E 2
				exit(1);
			}
E 4
I 4
		if (sendto(sock, (char *)message, sizeof(struct tsp), 0, addr,
		    sizeof(struct sockaddr_in)) < 0) {
			syslog(LOG_ERR, "acksend: sendto: %m");
			exit(1);
E 4
		}
		tout.tv_sec = SECFORACK;
		tout.tv_usec = USECFORACK;
D 4
		answer  = readmsg(ack, name, &tout);
E 4
I 4
		answer  = readmsg(ack, name, &tout, net);
E 4
		if (answer != NULL) {
I 5
			if (answer->tsp_seq != sequence) {
				if (trace)
					fprintf(fd, "acksend: seq # %d != %d\n",
					    answer->tsp_seq, sequence);
				continue;
			}
E 5
			flag = RECEIVED;
		} else {
			flag = LOST;
			if (++count == MAXCOUNT) {
				break;
			}
		}
	} while (flag != RECEIVED);
D 7
	if (++sequence > MAXSEQ)
		sequence = 1;
E 7
I 7
	sequence++;
E 7
	return(answer);
}
E 1
