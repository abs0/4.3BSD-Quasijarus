h35478
s 00010/00005/00551
d D 2.18 88/06/18 14:08:23 bostic 22 21
c install approved copyright notice
e
s 00009/00003/00547
d D 2.17 87/12/23 14:30:16 bostic 21 20
c append Berkeley header; NASA wants a copy
e
s 00010/00008/00540
d D 2.16 86/06/05 14:56:42 bloom 20 19
c be careful with measure file pointer, multiple quits can cause problems
e
s 00002/00002/00546
d D 2.15 86/05/28 20:09:58 bloom 19 18
c lint cleanup (fix sequence number problem)
e
s 00000/00003/00548
d D 2.14 86/05/28 10:21:22 bloom 18 17
c preserve microseconds
e
s 00001/00003/00550
d D 2.13 86/05/27 15:58:11 karels 17 16
c toss MAXSEQ
e
s 00014/00013/00539
d D 2.12 86/05/27 15:34:43 karels 16 15
c syslog priorities
e
s 00003/00001/00549
d D 2.11 86/05/17 21:09:27 lepreau 15 14
c log date changes to wtmp.  no rounding cause timed zeroes tv_usec
e
s 00000/00002/00550
d D 2.10 86/05/15 23:33:29 bloom 14 13
c make it compile
e
s 00124/00028/00428
d D 2.9 86/05/15 09:18:25 bloom 13 12
c add loop detection
e
s 00001/00000/00455
d D 2.8 86/05/01 16:27:51 bloom 12 11
c set ellection time properly after SETTIME
e
s 00001/00001/00454
d D 2.7 86/05/01 09:46:41 bloom 11 10
c correct expected response to a QUIT
e
s 00014/00004/00441
d D 2.6 86/04/21 15:53:24 bloom 10 9
c change for date being absolute, forward change requests correctly 
c from ks@ef.purgue.edu
e
s 00015/00001/00430
d D 2.5 86/04/18 19:18:08 bloom 9 8
c fix core dumps when using MEASURE
e
s 00158/00082/00273
d D 2.4 86/04/11 18:16:45 bloom 8 7
c major work on multiple network code (Kirk Smith, ks@ef.purdue.edu)
e
s 00013/00002/00342
d D 2.3 86/02/17 13:20:55 bloom 7 6
c propogate DATEREQ properly
e
s 00039/00002/00305
d D 2.2 86/02/10 11:58:44 bloom 6 4
c have to respond to MASTERREQ if submaster; should the election timer be reset
e
s 00039/00000/00307
d R 2.2 86/02/10 11:56:58 bloom 5 4
c have to respond to a MASTERREQ if submaster; should we reset the election
c timer as well?
e
s 00099/00028/00208
d D 2.1 85/12/10 13:07:26 bloom 4 3
c Multi network support
e
s 00001/00002/00235
d D 1.3 85/11/16 18:32:31 bloom 3 2
c use line buffering for traces instead of explicit calls to fflush
e
s 00024/00031/00213
d D 1.2 85/09/18 19:55:02 bloom 2 1
c move constants, fix syslog messages, don't busy wait, log time changed from,
c misc cleanup
e
s 00244/00000/00000
d D 1.1 85/06/27 01:13:14 gusella 1 0
c date and time created 85/06/27 01:13:14 by gusella
e
u
U
t
T
I 1
/*
D 16
 * Copyright (c) 1983 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1985 Regents of the University of California.
E 16
D 21
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 21
I 21
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 22
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 22
I 22
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
E 22
E 21
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 21
#endif not lint
E 21
I 21
#endif /* not lint */
E 21

#include "globals.h"
#include <protocols/timed.h>
#include <setjmp.h>

D 2
#define OFF	0
#define ON	1

E 2
D 4
extern long delay1;
extern long delay2;
extern int trace;
extern int sock;
extern struct sockaddr_in from;
extern struct sockaddr_in server;
extern char hostname[];
extern char *fj;
extern FILE *fd;
E 4
I 4
extern jmp_buf jmpenv;
E 4

I 13
D 19
extern short sequence;
E 19
I 19
extern u_short sequence;
E 19

E 13
slave()
{
	int length;
	int senddateack;
D 8
	long electiontime, refusetime;
E 8
I 8
	long electiontime, refusetime, looktime;
E 8
	u_short seq;
D 2
	char candidate[32];
E 2
I 2
	char candidate[MAXHOSTNAMELEN];
E 2
D 7
	struct tsp *msg, *readmsg();
E 7
I 7
	struct tsp *msg, to, *readmsg();
E 7
D 4
	extern int backoff;
E 4
D 2
	struct sockaddr_in saveaddr;
E 2
I 2
	struct sockaddr_in saveaddr, msaveaddr;
E 2
D 4
	extern jmp_buf jmpenv;
E 4
	struct timeval wait;
D 7
	struct timeval time;
E 7
I 7
D 15
	struct timeval time, mytime;
E 15
I 15
D 19
	struct timeval time, mytime, otime;
E 19
I 19
	struct timeval time, otime;
E 19
E 15
E 7
D 2
	struct timezone tzone;
E 2
	struct tsp *answer, *acksend();
	int timeout();
D 4
	char *date(), *strcpy();
E 4
I 4
	char *date();
E 4
	long casual();
	int bytenetorder();
I 2
D 4
	char *olddate;
E 4
I 4
	char olddate[32];
	struct sockaddr_in server;
	register struct netinfo *ntp;
I 7
	int ind;
I 8
	struct tsp resp;
	extern int Mflag;
I 13
	extern int justquit;
E 13
E 8
E 7
#ifdef MEASURE
I 9
D 20
	int tempstat;
E 20
E 9
	extern FILE *fp;
#endif
I 8
	if (slavenet) {
		resp.tsp_type = TSP_SLAVEUP;
		resp.tsp_vers = TSPVERSION;
		(void)strcpy(resp.tsp_name, hostname);
		bytenetorder(&resp);
		if (sendto(sock, (char *)&resp, sizeof(struct tsp), 0,
		    &slavenet->dest_addr, sizeof(struct sockaddr_in)) < 0) {
			syslog(LOG_ERR, "sendto: %m");
			exit(1);
		}
	}
E 8
E 4
E 2

D 2
	syslog(LOG_ERR, "timed: THIS MACHINE IS A SLAVE\n");
E 2
I 2
D 4
	syslog(LOG_NOTICE, "THIS MACHINE IS A SLAVE");
E 2
	if (trace) {
		fprintf(fd, "THIS MACHINE IS A SLAVE\n");
E 4
I 4
	if (status & MASTER) {
#ifdef MEASURE
D 20
		fp = fopen("/usr/adm/timed.masterlog", "w");
		setlinebuf(fp);
E 20
I 20
		if (fp == NULL) {
			fp = fopen("/usr/adm/timed.masterlog", "w");
			setlinebuf(fp);
		}
E 20
#endif
D 16
		syslog(LOG_NOTICE, "THIS MACHINE IS A SUBMASTER");
E 16
I 16
		syslog(LOG_INFO, "THIS MACHINE IS A SUBMASTER");
E 16
		if (trace) {
			fprintf(fd, "THIS MACHINE IS A SUBMASTER\n");
		}
		for (ntp = nettab; ntp != NULL; ntp = ntp->next)
			if (ntp->status == MASTER)
				masterup(ntp);
I 13

E 13
	} else {
D 16
		syslog(LOG_NOTICE, "THIS MACHINE IS A SLAVE");
E 16
I 16
		syslog(LOG_INFO, "THIS MACHINE IS A SLAVE");
E 16
		if (trace) {
			fprintf(fd, "THIS MACHINE IS A SLAVE\n");
		}
E 4
	}

	seq = 0;
	senddateack = OFF;
	refusetime = 0;

	(void)gettimeofday(&time, (struct timezone *)0);
	electiontime = time.tv_sec + delay2;
I 8
D 13
	if (Mflag && nignorednets > 0)
		looktime = time.tv_sec + delay2;
E 13
I 13
	if (Mflag)
		if (justquit)
			looktime = time.tv_sec + delay2;
		else 
			looktime = 1;
E 13
	else
		looktime = 0;
E 8

loop:
	length = sizeof(struct sockaddr_in);
	(void)gettimeofday(&time, (struct timezone *)0);
	if (time.tv_sec > electiontime) {
		if (trace) 
			fprintf(fd, "election timer expired\n");
		longjmp(jmpenv, 1);
	}
I 8
	if (looktime && time.tv_sec > looktime) {
		if (trace) 
D 13
			fprintf(fd, "Looking for nets to master\n");
E 13
I 13
			fprintf(fd, "Looking for nets to master and loops\n");
E 13
		
D 13
		for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
			if (ntp->status == IGNORE) {
				lookformaster(ntp);
				if (ntp->status == MASTER)
					masterup(ntp);
				else
					ntp->status = IGNORE;
E 13
I 13
		if (nignorednets > 0) {
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
				if (ntp->status == IGNORE) {
					lookformaster(ntp);
					if (ntp->status == MASTER)
						masterup(ntp);
					else
						ntp->status = IGNORE;
				}
E 13
			}
D 13
		}
E 13
I 9
D 20
#ifdef MEASURE
D 13
		tempstat = status;
E 13
I 13
			tempstat = status;
E 13
#endif
E 20
E 9
D 13
		setstatus();
E 13
I 13
			setstatus();
E 13
I 9
#ifdef MEASURE
D 13
		/*
		 * Check to see if we just became master
		 */
		if ((status & MASTER) && !(tempstat & MASTER)) {
			fp = fopen("/usr/adm/timed.masterlog", "w");
			setlinebuf(fp);
		}
E 13
I 13
			/*
			 * Check to see if we just became master
I 20
			 * (file not open)
E 20
			 */
D 20
			if ((status & MASTER) && !(tempstat & MASTER)) {
E 20
I 20
			if (fp == NULL) {
E 20
				fp = fopen("/usr/adm/timed.masterlog", "w");
				setlinebuf(fp);
			}
E 13
#endif
E 9
D 13
		
		if (nignorednets > 0) {
			(void)gettimeofday(&time, (struct timezone *)0);
			looktime = time.tv_sec + delay2;
D 9
		}
E 9
I 9
		} else
			looktime = 0;
E 13
I 13
		}

		for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
		    if (ntp->status == MASTER) {
			to.tsp_type = TSP_LOOP;
			to.tsp_vers = TSPVERSION;
D 17
			to.tsp_seq = sequence;
E 17
I 17
			to.tsp_seq = sequence++;
E 17
			to.tsp_hopcnt = 10;
			(void)strcpy(to.tsp_name, hostname);
			bytenetorder(&to);
			if (sendto(sock, (char *)&to, sizeof(struct tsp), 0,
			    &ntp->dest_addr, sizeof(struct sockaddr_in)) < 0) {
				syslog(LOG_ERR, "sendto: %m");
				exit(1);
D 17
			if (++sequence > MAXSEQ)
				sequence = 1;
E 17
			}
		    }
		}
		(void)gettimeofday(&time, (struct timezone *)0);
		looktime = time.tv_sec + delay2;
E 13
E 9
	}
E 8
	wait.tv_sec = electiontime - time.tv_sec + 10;
	wait.tv_usec = 0;
D 4
	msg = readmsg(TSP_ANY, (char *)ANYADDR, &wait);
E 4
I 4
	msg = readmsg(TSP_ANY, (char *)ANYADDR, &wait, (struct netinfo *)NULL);
E 4
	if (msg != NULL) {
		switch (msg->tsp_type) {
I 8
D 10
		case TSP_DATE:
E 10
I 10
		case TSP_SETDATE:
E 10
#ifdef TESTING
		case TSP_TEST:
#endif
		case TSP_MSITE:
		case TSP_TRACEOFF:
		case TSP_TRACEON:
			break;
		case TSP_MASTERUP:
			if (fromnet == NULL) {
				if (trace) {
					fprintf(fd, "slave ignored: ");
					print(msg, &from);
				}
				goto loop;
			}
			break;
		default:
			if (fromnet == NULL || fromnet->status == IGNORE) {
				if (trace) {
					fprintf(fd, "slave ignored: ");
					print(msg, &from);
				}
				goto loop;
			}
			break;
		}
E 8

I 8
		switch (msg->tsp_type) {

E 8
		case TSP_ADJTIME:
I 8
			if (fromnet->status != SLAVE)
				break;
E 8
			(void)gettimeofday(&time, (struct timezone *)0);
			electiontime = time.tv_sec + delay2;
			if (seq != msg->tsp_seq) {
				seq = msg->tsp_seq;
D 4
				adjclock(&(msg->tsp_time));
E 4
I 4
				if ((status & SUBMASTER) == SUBMASTER) {
					synch((msg->tsp_time.tv_sec * 1000) + 
					    (msg->tsp_time.tv_usec / 1000));
				} else {
					adjclock(&(msg->tsp_time));
				}
E 4
			}
			break;
		case TSP_SETTIME:
I 8
			if (fromnet->status != SLAVE)
				break;
E 8
			if (seq == msg->tsp_seq)
D 2
				goto endsettime;
E 2
I 2
				break;
E 2

			seq = msg->tsp_seq;

D 2
			(void)gettimeofday(&time, &tzone);
			time.tv_sec = msg->tsp_time.tv_sec;
			time.tv_usec = 500000;
			(void)settimeofday(&time, &tzone);
			syslog(LOG_ERR, "timed: date changed to: %s\n",
							date());
E 2
I 2
D 4
			olddate = date();
E 4
I 4
			(void)strcpy(olddate, date());
I 15
			(void)gettimeofday(&otime, (struct timezone *)0);
E 15
E 4
			(void)settimeofday(&msg->tsp_time,
				(struct timezone *)0);
			syslog(LOG_NOTICE, "date changed by %s from: %s",
				msg->tsp_name, olddate);
I 15
			logwtmp(otime, msg->tsp_time);
E 15
I 4
			if ((status & SUBMASTER) == SUBMASTER)
				spreadtime();
I 12
			(void)gettimeofday(&time, (struct timezone *)0);
E 12
E 4
E 2
			electiontime = time.tv_sec + delay2;

			if (senddateack == ON) {
				senddateack = OFF;
				msg->tsp_type = TSP_DATEACK;
				(void)strcpy(msg->tsp_name, hostname);
				bytenetorder(msg);
				length = sizeof(struct sockaddr_in);
				if (sendto(sock, (char *)msg, 
						sizeof(struct tsp), 0,
						&saveaddr, length) < 0) {
D 2
					syslog(LOG_ERR, "timed: sendto: %m");
E 2
I 2
					syslog(LOG_ERR, "sendto: %m");
E 2
					exit(1);
				}
			}
D 2
endsettime:
E 2
			break;
		case TSP_MASTERUP:
I 8
			if (slavenet && fromnet != slavenet)
				break;
			makeslave(fromnet);
			setstatus();
E 8
			msg->tsp_type = TSP_SLAVEUP;
			msg->tsp_vers = TSPVERSION;
			(void)strcpy(msg->tsp_name, hostname);
			bytenetorder(msg);
			answerdelay();
			length = sizeof(struct sockaddr_in);
			if (sendto(sock, (char *)msg, sizeof(struct tsp), 0, 
						&from, length) < 0) {
D 2
				syslog(LOG_ERR, "timed: sendto: %m");
E 2
I 2
				syslog(LOG_ERR, "sendto: %m");
E 2
				exit(1);
			}
			backoff = 1;
			delay2 = casual((long)MINTOUT, (long)MAXTOUT);
			(void)gettimeofday(&time, (struct timezone *)0);
			electiontime = time.tv_sec + delay2;
I 2
			refusetime = 0;
E 2
			break;
		case TSP_MASTERREQ:
D 6
			(void)gettimeofday(&time, (struct timezone *)0);
			electiontime = time.tv_sec + delay2;
E 6
I 6
D 8
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
				if ((ntp->mask & from.sin_addr.s_addr) ==
				    ntp->net) {
					if (ntp->status == MASTER)
						break;
				}
			}
			if (!(status & MASTER) || ntp == NULL) {
				(void)gettimeofday(&time, (struct timezone *)0);
				electiontime = time.tv_sec + delay2;
E 8
I 8
			if (fromnet->status != SLAVE)
E 8
				break;
D 8
			}
			ind = addmach(msg->tsp_name, &from);
			if (trace)
				prthp();
			if (hp[ind].seq !=  msg->tsp_seq) {
				hp[ind].seq = msg->tsp_seq;
				to.tsp_type = TSP_SETTIME;
				(void)strcpy(to.tsp_name, hostname);
				/*
				 * give the upcoming slave the time
				 * to check its input queue before
				 * setting the time
				 */
				sleep(1);
				to.tsp_time.tv_usec = 0;
				(void) gettimeofday(&mytime,
				    (struct timezone *)0);
				to.tsp_time.tv_sec = mytime.tv_sec;
				answer = acksend(&to, &hp[ind].addr,
				    hp[ind].name, TSP_ACK,
				    (struct netinfo *)NULL);
				if (answer == NULL) {
					syslog(LOG_ERR,
					    "ERROR ON SETTIME machine: %s",
					    hp[ind].name);
					slvcount--;
				}
			}
E 8
I 8
			(void)gettimeofday(&time, (struct timezone *)0);
			electiontime = time.tv_sec + delay2;
E 8
E 6
			break;
D 10
		case TSP_DATE:
E 10
I 10
		case TSP_SETDATE:
E 10
			saveaddr = from;
D 18
			msg->tsp_time.tv_usec = 0;
E 18
D 10
			msg->tsp_type = TSP_DATEREQ;
E 10
I 10
			msg->tsp_type = TSP_SETDATEREQ;
E 10
			msg->tsp_vers = TSPVERSION;
			(void)strcpy(msg->tsp_name, hostname);
D 4
			answer = acksend(msg, (char *)ANYADDR, TSP_DATEACK);
E 4
I 4
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
				if (ntp->status == SLAVE)
					break;
			}
I 8
			if (ntp == NULL)
				break;
E 8
			answer = acksend(msg, &ntp->dest_addr, (char *)ANYADDR,
			    TSP_DATEACK, ntp);
E 4
			if (answer != NULL) {
				msg->tsp_type = TSP_ACK;
				bytenetorder(msg);
				length = sizeof(struct sockaddr_in);
D 4
				if (sendto(sock, (char *)msg, 
						sizeof(struct tsp), 0,
						&saveaddr, length) < 0) {
E 4
I 4
				if (sendto(sock, (char *)msg,
				    sizeof(struct tsp), 0, &saveaddr,
				    length) < 0) {
E 4
D 2
					syslog(LOG_ERR, "timed: sendto: %m");
E 2
I 2
					syslog(LOG_ERR, "sendto: %m");
E 2
					exit(1);
				}
				senddateack = ON;
			}
			break;
I 4
D 10
		case TSP_DATEREQ:
E 10
I 10
		case TSP_SETDATEREQ:
E 10
I 7
			saveaddr = from;
E 7
D 8
			if (status != SUBMASTER)
E 8
I 8
			if (status != SUBMASTER || fromnet->status != MASTER)
E 8
I 7
				break;
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
D 8
				if ((ntp->mask & from.sin_addr.s_addr) ==
				    ntp->net) {
					if (ntp->status == MASTER)
						break;
				}
			}
			if (ntp == NULL)
E 7
				break;
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
E 8
				if (ntp->status == SLAVE)
					break;
			}
I 10
			ind = findhost(msg->tsp_name);
			if (ind < 0) {
D 16
			    syslog(LOG_ERR,
E 16
I 16
			    syslog(LOG_WARNING,
E 16
				"DATEREQ from uncontrolled machine");
			    break;
			}
D 16
			syslog(LOG_NOTICE,
E 16
I 16
			syslog(LOG_DEBUG,
E 16
			    "forwarding date change request for %s",
			    msg->tsp_name);
D 13
			strcpy(msg->tsp_name, hostname);
E 13
I 13
			(void)strcpy(msg->tsp_name, hostname);
E 13
E 10
			answer = acksend(msg, &ntp->dest_addr, (char *)ANYADDR,
			    TSP_DATEACK, ntp);
			if (answer != NULL) {
				msg->tsp_type = TSP_DATEACK;
				bytenetorder(msg);
				length = sizeof(struct sockaddr_in);
				if (sendto(sock, (char *)msg,
				    sizeof(struct tsp), 0, &saveaddr,
				    length) < 0) {
					syslog(LOG_ERR, "sendto: %m");
					exit(1);
				}
			}
			break;
E 4
		case TSP_TRACEON:
			if (!(trace)) {
D 4
				fd = fopen(fj, "w");
E 4
I 4
				fd = fopen(tracefile, "w");
E 4
I 3
				setlinebuf(fd);
E 3
				fprintf(fd, "Tracing started on: %s\n\n", 
								date());
D 3
				(void)fflush(fd);
E 3
			}
			trace = ON;
			break;
		case TSP_TRACEOFF:
			if (trace) {
				fprintf(fd, "Tracing ended on: %s\n", date());
D 3
				(void)fflush(fd);
E 3
D 2
				(void)close((int)fd);
E 2
I 2
				(void)fclose(fd);
E 2
			}
I 4
#ifdef GPROF
			moncontrol(0);
			_mcleanup();
			moncontrol(1);
#endif
E 4
			trace = OFF;
			break;
I 4
		case TSP_SLAVEUP:
D 8
			if (!(status & MASTER))
				break;
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
				if ((ntp->mask & from.sin_addr.s_addr) ==
				    ntp->net) {
					if (ntp->status == MASTER)
						addmach(msg->tsp_name, &from);
					break;
				}
E 8
I 8
			if ((status & MASTER) && fromnet->status == MASTER) {
				ind = addmach(msg->tsp_name, &from);
				newslave(ind, msg->tsp_seq);
E 8
			}
			break;
E 4
		case TSP_ELECTION:
D 8
			(void)gettimeofday(&time, (struct timezone *)0);
			electiontime = time.tv_sec + delay2;
			seq = 0;            /* reset sequence number */
			if (time.tv_sec < refusetime)
				msg->tsp_type = TSP_REFUSE;
			else {
				msg->tsp_type = TSP_ACCEPT;
				refusetime = time.tv_sec + 30;
E 8
I 8
			if (fromnet->status == SLAVE) {
				(void)gettimeofday(&time, (struct timezone *)0);
				electiontime = time.tv_sec + delay2;
				seq = 0;            /* reset sequence number */
				if (time.tv_sec < refusetime)
					msg->tsp_type = TSP_REFUSE;
				else {
					msg->tsp_type = TSP_ACCEPT;
					refusetime = time.tv_sec + 30;
				}
				(void)strcpy(candidate, msg->tsp_name);
				(void)strcpy(msg->tsp_name, hostname);
				answerdelay();
				server = from;
				answer = acksend(msg, &server, candidate, TSP_ACK,
				    (struct netinfo *)NULL);
D 16
				if (answer == NULL) {
					syslog(LOG_ERR, "problem in election\n");
				}
E 8
			}
D 8
			(void)strcpy(candidate, msg->tsp_name);
			(void)strcpy(msg->tsp_name, hostname);
			answerdelay();
			server = from;
D 4
			answer = acksend(msg, candidate, TSP_ACK);
E 4
I 4
			answer = acksend(msg, &server, candidate, TSP_ACK,
			    (struct netinfo *)NULL);
E 4
			if (answer == NULL) {
D 2
				syslog(LOG_ERR, "timed: problem in election\n");
E 2
I 2
				syslog(LOG_ERR, "problem in election\n");
E 8
I 8
			else {	/* fromnet->status == MASTER */
E 16
I 16
				if (answer == NULL)
					syslog(LOG_WARNING,
					   "no answer from master candidate\n");
			} else {	/* fromnet->status == MASTER */
E 16
				to.tsp_type = TSP_QUIT;
				(void)strcpy(to.tsp_name, hostname);
				server = from;
				answer = acksend(&to, &server, msg->tsp_name,
				    TSP_ACK, (struct netinfo *)NULL);
				if (answer == NULL) {
D 16
					syslog(LOG_ERR, "election error");
E 16
I 16
					syslog(LOG_WARNING,
					    "election error: no reply to QUIT");
E 16
				} else {
					(void) addmach(msg->tsp_name, &from);
				}
E 8
E 2
			}
			break;
I 8
                case TSP_CONFLICT:
			if (fromnet->status != MASTER)
				break;
                        /*
                         * After a network partition, there can be
                         * more than one master: the first slave to
                         * come up will notify here the situation.
                         */
                        (void)strcpy(to.tsp_name, hostname);

                        if (fromnet == NULL)
                                break;
                        for(;;) {
                                to.tsp_type = TSP_RESOLVE;
                                answer = acksend(&to, &fromnet->dest_addr,
                                    (char *)ANYADDR, TSP_MASTERACK, fromnet);
                                if (answer == NULL)
                                        break;
                                to.tsp_type = TSP_QUIT;
                                server = from;
                                msg = acksend(&to, &server, answer->tsp_name,
D 11
                                    TSP_MASTERACK, (struct netinfo *)NULL);
E 11
I 11
                                    TSP_ACK, (struct netinfo *)NULL);
E 11
                                if (msg == NULL) {
D 16
                                        syslog(LOG_ERR, "error on sending QUIT");
                                } else {
E 16
I 16
                                        syslog(LOG_WARNING,
					    "conflict error: no reply to QUIT");
				} else {
E 16
D 13
                                        (void) addmach(answer->tsp_name, &from);                                }
E 13
I 13
                                        (void) addmach(answer->tsp_name, &from);
				}
E 13
                        }
                        masterup(fromnet);
                        break;
E 8
		case TSP_MSITE:
I 8
			if (!slavenet)
				break;
E 8
D 2
			saveaddr = from;
E 2
I 2
			msaveaddr = from;
E 2
			msg->tsp_type = TSP_MSITEREQ;
			msg->tsp_vers = TSPVERSION;
			(void)strcpy(msg->tsp_name, hostname);
D 4
			answer = acksend(msg, (char *)ANYADDR, TSP_ACK);
E 4
I 4
D 8
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
				if (ntp->status == SLAVE)
					break;
			}
			answer = acksend(msg, &ntp->dest_addr, (char *)ANYADDR,
			    TSP_ACK, ntp);
E 8
I 8
			answer = acksend(msg, &slavenet->dest_addr,
					 (char *)ANYADDR, TSP_ACK, slavenet);
E 8
E 4
			if (answer != NULL) {
				msg->tsp_type = TSP_ACK;
				length = sizeof(struct sockaddr_in);
				bytenetorder(msg);
				if (sendto(sock, (char *)msg, 
						sizeof(struct tsp), 0,
D 2
						&saveaddr, length) < 0) {
					syslog(LOG_ERR, "timed: sendto: %m");
E 2
I 2
						&msaveaddr, length) < 0) {
					syslog(LOG_ERR, "sendto: %m");
E 2
					exit(1);
				}
			}
			break;
		case TSP_ACCEPT:
		case TSP_REFUSE:
D 4
		case TSP_SLAVEUP:
		case TSP_DATEREQ:
E 4
			break;
I 8
		case TSP_RESOLVE:
			break;
		case TSP_QUIT:
			/* become slave */
#ifdef MEASURE
D 20
			(void)fclose(fp);
E 20
I 20
			if (fp != NULL) {
				(void)fclose(fp);
				fp = NULL;
			}
E 20
#endif
			longjmp(jmpenv, 2);
			break;
E 8
#ifdef TESTING
		case TSP_TEST:
			electiontime = 0;
			break;
#endif
I 4
		case TSP_MSITEREQ:
			if (status & MASTER)
				break;
			if (trace) {
				fprintf(fd, "garbage: ");
D 8
				print(msg);
E 8
I 8
				print(msg, &from);
I 13
			}
			break;

		case TSP_LOOP:
			/* looking for loops of masters */
			if ( !(status & MASTER))
				break;
			if (fromnet->status == SLAVE) {
			    if ( !strcmp(msg->tsp_name, hostname)) {
				  for(;;) {
				    to.tsp_type = TSP_RESOLVE;
				    answer = acksend(&to, &fromnet->dest_addr,
					(char *)ANYADDR, TSP_MASTERACK,
					fromnet);
				    if (answer == NULL)
					    break;
				    to.tsp_type = TSP_QUIT;
				    (void)strcpy(to.tsp_name, hostname);
				    server = from;
				    answer = acksend(&to, &server,
					answer->tsp_name, TSP_ACK,
					(struct netinfo *)NULL);
				    if (answer == NULL) {
					syslog(LOG_ERR, "loop kill error");
				    } else {
					electiontime = 0;
				    }
				  }
			    } else {
				if (msg->tsp_hopcnt-- <= 0)
				    break;
D 14
				(void)strcpy(loopname, msg->tsp_name);
				rloopseq = msg->tsp_seq;
E 14
				bytenetorder(msg);
				ntp = nettab;
				for (; ntp != NULL; ntp = ntp->next)
				    if (ntp->status == MASTER)
					if (sendto(sock, (char *)msg, 
					    sizeof(struct tsp), 0,
					    &ntp->dest_addr, length) < 0) {
						syslog(LOG_ERR, "sendto: %m");
						exit(1);
					}
			    }
			} else {
			    /*
			     * We should not have received this from a net
			     * we are master on.  There must be two masters
			     * in this case.
			     */
D 18
			    if (trace)
				fprintf(fd, "loop kill %x %x\n", fromnet->my_addr.s_addr, from.sin_addr.s_addr);
E 18
			    if (fromnet->my_addr.s_addr == from.sin_addr.s_addr)
				break;
			    for (;;) {
				to.tsp_type = TSP_RESOLVE;
				answer = acksend(&to, &fromnet->dest_addr,
				    (char *)ANYADDR, TSP_MASTERACK,
				    fromnet);
				if (answer == NULL)
					break;
				to.tsp_type = TSP_QUIT;
				(void)strcpy(to.tsp_name, hostname);
				server = from;
				answer = acksend(&to, &server, answer->tsp_name,
				    TSP_ACK, (struct netinfo *)NULL);
				if (answer == NULL) {
					syslog(LOG_ERR, "loop kill error2");
				} else {
					(void)addmach(msg->tsp_name, &from);
				}
			    }
E 13
E 8
			}
			break;
E 4
		default:
			if (trace) {
				fprintf(fd, "garbage: ");
D 8
				print(msg);
E 8
I 8
				print(msg, &from);
E 8
			}
			break;
		}
	}
	goto loop;
}

/*
 * Used before answering a broadcast message to avoid network
 * contention and likely collisions.
 */
answerdelay()
{
D 2
	struct timeval time, timeout;
E 2
I 2
	struct timeval timeout;
E 2

D 2
	(void)gettimeofday(&time, (struct timezone *)0);
	timeout.tv_sec = time.tv_sec;
	timeout.tv_usec = time.tv_usec + delay1;
E 2
I 2
	timeout.tv_sec = 0;
	timeout.tv_usec = delay1;
E 2

D 2
	while (timercmp(&time, &timeout, <)) {
		(void)gettimeofday(&time, (struct timezone *)0);
	}
	
E 2
I 2
	(void)select(0, (fd_set *)NULL, (fd_set *)NULL, (fd_set *)NULL,
	    &timeout);
E 2
	return;
}
E 1
