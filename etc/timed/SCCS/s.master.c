h48279
s 00010/00005/00554
d D 2.16 88/06/18 14:08:15 bostic 21 20
c install approved copyright notice
e
s 00009/00003/00550
d D 2.15 87/12/23 14:30:09 bostic 20 19
c append Berkeley header; NASA wants a copy
e
s 00009/00006/00544
d D 2.14 86/06/05 14:56:22 bloom 19 18
c be careful with measure file pointer, multiple quits can cause problems
e
s 00003/00003/00547
d D 2.13 86/06/03 14:58:25 lepreau 18 17
c check for equality after rounding; typo
e
s 00002/00006/00548
d D 2.12 86/06/03 10:25:13 bloom 17 16
c round times now that microseconds are propogated for logwtmp()
e
s 00002/00001/00552
d D 2.11 86/05/28 20:09:41 bloom 16 15
c lint cleanup (fix sequence number problem)
e
s 00002/00008/00551
d D 2.10 86/05/28 10:21:33 bloom 15 14
c preserve microseconds
e
s 00001/00003/00558
d D 2.9 86/05/27 15:58:01 karels 14 13
c toss MAXSEQ
e
s 00010/00010/00551
d D 2.8 86/05/27 15:34:32 karels 13 12
c syslog priorities
e
s 00032/00000/00529
d D 2.7 86/05/17 21:09:14 lepreau 12 11
c log date changes to wtmp.  no rounding cause timed zeroes tv_usec
e
s 00034/00000/00495
d D 2.6 86/05/15 09:18:37 bloom 11 10
c add loop detection
e
s 00002/00002/00493
d D 2.5 86/05/01 09:46:30 bloom 10 9
c correct expected response to a QUIT
e
s 00008/00008/00487
d D 2.4 86/04/21 15:57:05 bloom 9 8
c date now sends absolute time, measure lost an arg, fix problem with 
c deleting a host
e
s 00046/00044/00449
d D 2.3 86/04/11 18:16:20 bloom 8 7
c major work on multiple network code (Kirk Smith, ks@ef.purdue.edu)
e
s 00033/00000/00460
d D 2.2 86/02/17 13:18:18 bloom 7 6
c clean hostlist when going from master to slave (from ks@purdue)
e
s 00080/00074/00380
d D 2.1 85/12/10 13:06:56 bloom 6 5
c Multi network support
e
s 00001/00000/00453
d D 1.5 85/11/16 19:07:59 bloom 5 4
c make sure bytenetorder not called multiple times per packet
e
s 00002/00003/00451
d D 1.4 85/11/16 18:32:16 bloom 4 3
c use line buffering for traces instead of explicit calls to fflush
e
s 00011/00003/00443
d D 1.3 85/10/29 11:49:35 bloom 3 2
c syslog clobbers the date returned by ctime()
e
s 00028/00029/00418
d D 1.2 85/09/18 19:48:26 bloom 2 1
c fix syslog messages, move constants, print changed from time, close trace file
c misc. other cleanup
e
s 00447/00000/00000
d D 1.1 85/06/22 22:07:53 gusella 1 0
c date and time created 85/06/22 22:07:53 by gusella
e
u
U
t
T
I 1
/*
D 13
 * Copyright (c) 1983 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1985 Regents of the University of California.
E 13
D 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 20
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 20
#endif not lint
E 20
I 20
#endif /* not lint */
E 20

#include "globals.h"
#include <protocols/timed.h>
I 12
#include <sys/file.h>
E 12
#include <setjmp.h>
I 12
#include <utmp.h>
E 12

D 2
#define OFF	0
#define ON	1

E 2
D 6
extern struct sockaddr_in from;
extern struct sockaddr_in server;

extern int trace;
E 6
extern int machup;
D 6
extern int slvcount;
E 6
extern int measure_delta;
D 6
extern int sock;
extern char hostname[];
extern struct host hp[];
extern char *fj;
extern FILE *fd;
E 6
I 6
extern jmp_buf jmpenv;
E 6

I 11
D 16
extern short sequence;
E 16
I 16
extern u_short sequence;
E 16

E 11
#ifdef MEASURE
int header;
D 19
char *fi;
FILE *fp;
E 19
I 19
FILE *fp = NULL;
E 19
#endif

/*
 * The main function of `master' is to periodically compute the differences 
 * (deltas) between its clock and the clocks of the slaves, to compute the 
 * network average delta, and to send to the slaves the differences between 
 * their individual deltas and the network delta.
 * While waiting, it receives messages from the slaves (i.e. requests for
 * master's name, remote requests to set the network time, ...), and
 * takes the appropriate action.
 */

master()
{
	int ind;
D 6
	int length;
E 6
	long pollingtime;
	struct timeval wait;
	struct timeval time;
I 12
	struct timeval otime;
E 12
	struct timezone tzone;
D 8
	struct timeval mytime;
E 8
	struct tsp *msg, to;
	struct sockaddr_in saveaddr;
D 6
	extern jmp_buf jmpenv;
E 6
	int findhost();
	char *date();
D 6
	char *strcpy();
E 6
	struct tsp *readmsg();
	struct tsp *answer, *acksend();
I 2
D 3
	char *olddate;
E 3
I 3
	char olddate[32];
I 6
	struct sockaddr_in server;
	register struct netinfo *ntp;
E 6
E 3
E 2

#ifdef MEASURE
D 19
	fi = "/usr/adm/timed.masterlog";
	fp = fopen(fi, "w");
I 4
	setlinebuf(fp);
E 19
I 19
	if (fp == NULL) {
		fp = fopen("/usr/adm/timed.masterlog", "w");
		setlinebuf(fp);
	}
E 19
E 4
#endif

D 2
	syslog(LOG_ERR, "timed: THIS MACHINE IS MASTER\n");
E 2
I 2
D 13
	syslog(LOG_INFO, "THIS MACHINE IS MASTER");
E 13
I 13
	syslog(LOG_INFO, "This machine is master");
E 13
E 2
	if (trace)
		fprintf(fd, "THIS MACHINE IS MASTER\n");

D 6
	masterup();
E 6
I 6
	for (ntp = nettab; ntp != NULL; ntp = ntp->next)
		if (ntp->status == MASTER)
			masterup(ntp);
E 6
	pollingtime = 0;

loop:
	(void)gettimeofday(&time, (struct timezone *)0);
	if (time.tv_sec >= pollingtime) {
		pollingtime = time.tv_sec + SAMPLEINTVL;
D 6
		synch();
E 6
I 6
		synch(0L);
I 11

		for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
			to.tsp_type = TSP_LOOP;
			to.tsp_vers = TSPVERSION;
D 14
			to.tsp_seq = sequence;
E 14
I 14
			to.tsp_seq = sequence++;
E 14
			to.tsp_hopcnt = 10;
			(void)strcpy(to.tsp_name, hostname);
			bytenetorder(&to);
			if (sendto(sock, (char *)&to, sizeof(struct tsp), 0,
			    &ntp->dest_addr, sizeof(struct sockaddr_in)) < 0) {
				syslog(LOG_ERR, "sendto: %m");
				exit(1);
D 14
			if (++sequence > MAXSEQ)
				sequence = 1;
E 14
			}
		}
E 11
E 6
	}

	wait.tv_sec = pollingtime - time.tv_sec;
	wait.tv_usec = 0;
D 6
	msg = readmsg(TSP_ANY, (char *)ANYADDR, &wait);
E 6
I 6
	msg = readmsg(TSP_ANY, (char *)ANYADDR, &wait, (struct netinfo *)NULL);
E 6
	if (msg != NULL) {
		switch (msg->tsp_type) {

		case TSP_MASTERREQ:
D 6
			ind = addmach(msg->tsp_name);
E 6
I 6
D 8
			ind = addmach(msg->tsp_name, &from);
E 6
			if (trace)
				prthp();
			if (hp[ind].seq !=  msg->tsp_seq) {
				hp[ind].seq = msg->tsp_seq;
D 6
				bcopy((char *)&hp[ind].addr, 
					    (char *)&(server.sin_addr.s_addr),
					    hp[ind].length);
E 6
				to.tsp_type = TSP_SETTIME;
				(void)strcpy(to.tsp_name, hostname);
				/*
				 * give the upcoming slave the time
				 * to check its input queue before
				 * setting the time
				 */
				sleep(1);
				to.tsp_time.tv_usec = 0;
D 6
				(void)gettimeofday(&mytime, (struct timezone *)0);
E 6
I 6
				(void) gettimeofday(&mytime,
				    (struct timezone *)0);
E 6
				to.tsp_time.tv_sec = mytime.tv_sec;
D 6
				answer = acksend(&to, hp[ind].name, TSP_ACK);
E 6
I 6
				answer = acksend(&to, &hp[ind].addr,
				    hp[ind].name, TSP_ACK,
				    (struct netinfo *)NULL);
E 6
				if (answer == NULL) {
D 2
					syslog(LOG_ERR, "timed: ERROR ON SETTIME machine: %s\n", hp[ind].name);
E 2
I 2
D 6
					syslog(LOG_ERR, "ERROR ON SETTIME machine: %s", hp[ind].name);
E 6
I 6
					syslog(LOG_ERR,
					    "ERROR ON SETTIME machine: %s",
					    hp[ind].name);
E 6
E 2
					slvcount--;
				}
D 2
				pollingtime = 0;
E 2
			}
E 8
			break;
		case TSP_SLAVEUP:
D 6
			(void) addmach(msg->tsp_name);
E 6
I 6
D 8
			(void) addmach(msg->tsp_name, &from);
E 8
I 8
			ind = addmach(msg->tsp_name, &from);
			newslave(ind, msg->tsp_seq);
E 8
E 6
D 2
			pollingtime = 0;
E 2
			break;
D 9
		case TSP_DATE:
E 9
I 9
		case TSP_SETDATE:
E 9
			saveaddr = from;
D 15
			msg->tsp_time.tv_usec = 0;
E 15
I 2
D 3
			olddate = date();
E 3
I 3
			/*
			 * the following line is necessary due to syslog
			 * calling ctime() which clobbers the static buffer
			 */
			(void)strcpy(olddate, date());
E 3
E 2
			(void)gettimeofday(&time, &tzone);
I 12
			otime = time;
E 12
D 9
			time.tv_sec += msg->tsp_time.tv_sec;
E 9
I 9
			time.tv_sec = msg->tsp_time.tv_sec;
			time.tv_usec = msg->tsp_time.tv_usec;
E 9
D 13
			time.tv_sec++;
E 13
			(void)settimeofday(&time, &tzone);
D 2
			syslog(LOG_ERR, "timed: date changed to: %s\n", date());
E 2
I 2
			syslog(LOG_NOTICE, "date changed from: %s", olddate);
I 12
			logwtmp(otime, time);
E 12
E 2
			msg->tsp_type = TSP_DATEACK;
			msg->tsp_vers = TSPVERSION;
			(void)strcpy(msg->tsp_name, hostname);
			bytenetorder(msg);
D 6
			length = sizeof(struct sockaddr_in);
E 6
			if (sendto(sock, (char *)msg, sizeof(struct tsp), 0,
D 6
						&saveaddr, length) < 0) {
E 6
I 6
			    &saveaddr, sizeof(struct sockaddr_in)) < 0) {
E 6
D 2
				syslog(LOG_ERR, "timed: sendto: %m");
E 2
I 2
				syslog(LOG_ERR, "sendto: %m");
E 2
				exit(1);
			}
			spreadtime();
			pollingtime = 0;
			break;
D 9
		case TSP_DATEREQ:
E 9
I 9
		case TSP_SETDATEREQ:
E 9
			ind = findhost(msg->tsp_name);
			if (ind < 0) { 
D 2
				syslog(LOG_ERR, "timed: error on DATEREQ\n");
				break;
E 2
I 2
D 13
			    syslog(LOG_ERR,
E 13
I 13
			    syslog(LOG_WARNING,
E 13
				"DATEREQ from uncontrolled machine");
			    break;
E 2
			}
			if (hp[ind].seq !=  msg->tsp_seq) {
				hp[ind].seq = msg->tsp_seq;
D 15
				msg->tsp_time.tv_usec = 0;
E 15
I 2
D 3
				olddate = date();
E 3
I 3
				/*
				 * the following line is necessary due to syslog
				 * calling ctime() which clobbers the static buffer
				 */
				(void)strcpy(olddate, date());
E 3
E 2
				(void)gettimeofday(&time, &tzone);
I 12
				otime = time;
E 12
D 9
				time.tv_sec += msg->tsp_time.tv_sec;
E 9
I 9
				time.tv_sec = msg->tsp_time.tv_sec;
				time.tv_usec = msg->tsp_time.tv_usec;
E 9
D 13
				time.tv_sec++;
E 13
				(void)settimeofday(&time, &tzone);
D 2
				syslog(LOG_ERR, "timed: date changed to: %s\n", date());
E 2
I 2
				syslog(LOG_NOTICE,
				    "date changed by %s from: %s",
				    msg->tsp_name, olddate);
I 12
				logwtmp(otime, time);
E 12
E 2
				spreadtime();
				pollingtime = 0;
			}
			break;
		case TSP_MSITE:
D 6
			msg->tsp_type = TSP_ACK;
			msg->tsp_vers = TSPVERSION;
			(void)strcpy(msg->tsp_name, hostname);
			bytenetorder(msg);
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
			break;
E 6
		case TSP_MSITEREQ:
			break;
		case TSP_TRACEON:
			if (!(trace)) {
D 6
				fd = fopen(fj, "w");
E 6
I 6
				fd = fopen(tracefile, "w");
E 6
I 4
				setlinebuf(fd);
E 4
				fprintf(fd, "Tracing started on: %s\n\n", 
							date());
D 4
				(void)fflush(fd);
E 4
			}
			trace = ON;
			break;
		case TSP_TRACEOFF:
			if (trace) {
				fprintf(fd, "Tracing ended on: %s\n", date());
D 4
				(void)fflush(fd);
E 4
D 2
				(void)close((int)fd);
E 2
I 2
				(void)fclose(fd);
E 2
			}
I 6
#ifdef GPROF
			moncontrol(0);
			_mcleanup();
			moncontrol(1);
#endif
E 6
			trace = OFF;
			break;
		case TSP_ELECTION:
			to.tsp_type = TSP_QUIT;
			(void)strcpy(to.tsp_name, hostname);
			server = from;
D 6
			answer = acksend(&to, msg->tsp_name, TSP_ACK);
E 6
I 6
			answer = acksend(&to, &server, msg->tsp_name, TSP_ACK,
			    (struct netinfo *)NULL);
E 6
			if (answer == NULL) {
D 2
				syslog(LOG_ERR, "timed: election error\n");
E 2
I 2
				syslog(LOG_ERR, "election error");
E 2
			} else {
D 6
				(void) addmach(msg->tsp_name);
E 6
I 6
				(void) addmach(msg->tsp_name, &from);
E 6
			}
			pollingtime = 0;
			break;
		case TSP_CONFLICT:
			/*
			 * After a network partition, there can be 
			 * more than one master: the first slave to 
			 * come up will notify here the situation.
			 */

			(void)strcpy(to.tsp_name, hostname);

I 6
D 8
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
				if ((ntp->mask & from.sin_addr.s_addr) ==
				    ntp->net)
					break;
			}
			if (ntp == NULL)
E 8
I 8
			if (fromnet == NULL)
E 8
				break;
E 6
			for(;;) {
				to.tsp_type = TSP_RESOLVE;
D 6
				answer = acksend(&to, (char *)ANYADDR, 
								TSP_MASTERACK);
E 6
I 6
D 8
				answer = acksend(&to, &ntp->dest_addr,
				    (char *)ANYADDR, TSP_MASTERACK, ntp);
E 8
I 8
				answer = acksend(&to, &fromnet->dest_addr,
				    (char *)ANYADDR, TSP_MASTERACK, fromnet);
E 8
E 6
				if (answer == NULL)
					break;
D 2
				(void) addmach(answer->tsp_name);
E 2
				to.tsp_type = TSP_QUIT;
				server = from;
D 6
				msg = acksend(&to, answer->tsp_name, 
								TSP_MASTERACK);
E 6
I 6
D 10
				msg = acksend(&to, &server, answer->tsp_name, 
				    TSP_MASTERACK, (struct netinfo *)NULL);
E 10
I 10
				msg = acksend(&to, &server, answer->tsp_name,
				    TSP_ACK, (struct netinfo *)NULL);
E 10
E 6
				if (msg == NULL) {
D 2
					syslog(LOG_ERR, "timed: error on sending QUIT\n");
E 2
I 2
					syslog(LOG_ERR, "error on sending QUIT");
				} else {
D 6
					(void) addmach(answer->tsp_name);
E 6
I 6
					(void) addmach(answer->tsp_name, &from);
E 6
E 2
				}
			}
D 6
			masterup();
E 6
I 6
D 8
			masterup(ntp);
E 8
I 8
			masterup(fromnet);
E 8
E 6
			pollingtime = 0;
			break;
		case TSP_RESOLVE:
			/*
			 * do not want to call synch() while waiting
			 * to be killed!
			 */
			(void)gettimeofday(&time, (struct timezone *)0);
			pollingtime = time.tv_sec + SAMPLEINTVL;
			break;
		case TSP_QUIT:
			/* become slave */
#ifdef MEASURE
D 2
			(void)close((int)fp);
E 2
I 2
D 19
			(void)fclose(fp);
E 19
I 19
			if (fp != NULL) {
				(void)fclose(fp);
				fp = NULL;
			}
E 19
E 2
#endif
			longjmp(jmpenv, 2);
			break;
I 11
		case TSP_LOOP:
			/*
			 * We should not have received this from a net
			 * we are master on.  There must be two masters
			 * in this case.
			 */
			to.tsp_type = TSP_QUIT;
			(void)strcpy(to.tsp_name, hostname);
			server = from;
			answer = acksend(&to, &server, msg->tsp_name, TSP_ACK,
				(struct netinfo *)NULL);
			if (answer == NULL) {
D 13
				syslog(LOG_ERR, "election error");
E 13
I 13
				syslog(LOG_WARNING,
				    "loop breakage: no reply to QUIT");
E 13
			} else {
				(void)addmach(msg->tsp_name, &from);
			}
E 11
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
 * `synch' synchronizes all the slaves by calling measure, 
 * networkdelta and correct 
 */

D 6
synch()
E 6
I 6
synch(mydelta)
long mydelta;
E 6
{
	int i;
	int measure_status;
	long netdelta;
	struct timeval tack;
#ifdef MEASURE
#define MAXLINES	8
D 2
	static int lines;
E 2
I 2
	static int lines = 1;
E 2
	struct timeval start, end;
#endif
	int measure();
	int correct();
	long networkdelta();
	char *date();

	if (slvcount > 1) {
#ifdef MEASURE
		(void)gettimeofday(&start, (struct timezone *)0);
		if (header == ON || --lines == 0) {
			fprintf(fp, "%s\n", date());
			for (i=0; i<slvcount; i++)
				fprintf(fp, "%.7s\t", hp[i].name);
			fprintf(fp, "\n");
			lines = MAXLINES;
			header = OFF;
		}
#endif
		machup = 1;
		hp[0].delta = 0;
		for(i=1; i<slvcount; i++) {
D 6
			bcopy((char *)&hp[i].addr, 
					(char *)&(server.sin_addr.s_addr), 
					hp[i].length); 
E 6
			tack.tv_sec = 0;
D 9
			tack.tv_usec = 100000;
D 6
			if ((measure_status = measure(&tack, ON)) < 0) {
E 6
I 6
			if ((measure_status = measure(&tack, &hp[i].addr,
			    ON)) < 0) {
E 9
I 9
			tack.tv_usec = 500000;
			if ((measure_status = measure(&tack, &hp[i].addr)) <0) {
E 9
E 6
D 2
				syslog(LOG_ERR, "timed: measure: %m\n");
E 2
I 2
				syslog(LOG_ERR, "measure: %m");
E 2
				exit(1);
			}
			hp[i].delta = measure_delta;
			if (measure_status == GOOD)
				machup++;
		}
D 6
		if (machup > 1) {
			netdelta = networkdelta();
			correct(netdelta);
E 6
I 6
		if (status & SLAVE) {
			/* called by a submaster */
			if (trace)
				fprintf(fd, "submaster correct: %d ms.\n",
				    mydelta);
			correct(mydelta);	
		} else {
			if (machup > 1) {
				netdelta = networkdelta();
				if (trace)
					fprintf(fd,
					    "master correct: %d ms.\n",
					    mydelta);
				correct(netdelta);
			}
E 6
		}
#ifdef MEASURE
		gettimeofday(&end, 0);
		end.tv_sec -= start.tv_sec;
		end.tv_usec -= start.tv_usec;
		if (end.tv_usec < 0) {
			end.tv_sec -= 1;
			end.tv_usec += 1000000;
		}
		fprintf(fp, "%d ms.\n", (end.tv_sec*1000+end.tv_usec/1000));
D 4
		(void)fflush(fp);
E 4
#endif
		for(i=1; i<slvcount; i++) {
			if (hp[i].delta == HOSTDOWN) {
D 8
				free((char *)hp[i].name);
E 8
I 8
				rmmach(i);
E 8
D 9
				hp[i] = hp[--slvcount];
E 9
#ifdef MEASURE
				header = ON;
#endif
			}
		}
I 6
	} else {
		if (status & SLAVE) {
			correct(mydelta);
		}
E 6
	}
}

/*
 * 'spreadtime' sends the time to each slave after the master
 * has received the command to set the network time 
 */

spreadtime()
{
	int i;
D 2
	struct timeval mytime;
E 2
	struct tsp to;
	struct tsp *answer, *acksend();

	for(i=1; i<slvcount; i++) {
D 6
		bcopy((char *)&hp[i].addr, (char *)&(server.sin_addr.s_addr), 
						hp[i].length); 
E 6
		to.tsp_type = TSP_SETTIME;
D 2
		to.tsp_time.tv_usec = 0;
E 2
		(void)strcpy(to.tsp_name, hostname);
D 2
		(void)gettimeofday(&mytime, (struct timezone *)0);
		to.tsp_time.tv_sec = mytime.tv_sec;
E 2
I 2
		(void)gettimeofday(&to.tsp_time, (struct timezone *)0);
E 2
D 6
		answer = acksend(&to, hp[i].name, TSP_ACK);
E 6
I 6
		answer = acksend(&to, &hp[i].addr, hp[i].name, TSP_ACK,
		    (struct netinfo *)NULL);
E 6
		if (answer == NULL) {
D 2
			syslog(LOG_ERR, "timed: ERROR ON SETTIME machine: %s\n", hp[i].name);
E 2
I 2
D 13
			syslog(LOG_ERR, "ERROR ON SETTIME machine: %s", hp[i].name);
E 13
I 13
			syslog(LOG_WARNING,
			    "no reply to SETTIME from: %s", hp[i].name);
E 13
E 2
		}
	}
}

findhost(name)
char *name;
{
	int i;
	int ind;

	ind = -1;
	for (i=1; i<slvcount; i++) {
		if (strcmp(name, hp[i].name) == 0) {
			ind = i;
			break;
		}
	}
	return(ind);
}

/*
 * 'addmach' adds a host to the list of controlled machines
 * if not already there 
 */

D 6
addmach(name)
E 6
I 6
addmach(name, addr)
E 6
char *name;
I 6
struct sockaddr_in *addr;
E 6
{
	int ret;
	int findhost();
D 6
	char *malloc();
	struct hostent *hptmp, *gethostbyname();
E 6

	ret = findhost(name);
	if (ret < 0) {
D 6
		hptmp = gethostbyname(name);
		if (hptmp == NULL) {
D 2
			syslog(LOG_ERR, "timed: gethostbyname: %m\n");
E 2
I 2
			syslog(LOG_ERR, "gethostbyname: %m");
E 2
			exit(1);
		}
		hp[slvcount].length = hptmp->h_length;
		bcopy((char *)hptmp->h_addr, (char *)&hp[slvcount].addr, 
						hptmp->h_length); 
E 6
I 6
		hp[slvcount].addr = *addr;
E 6
D 2
		hp[slvcount].name = (char *)malloc(32);
		(void)strcpy(hp[slvcount].name, hptmp->h_name);
E 2
I 2
		hp[slvcount].name = (char *)malloc(MAXHOSTNAMELEN);
		(void)strcpy(hp[slvcount].name, name);
E 2
		hp[slvcount].seq = 0;
		ret = slvcount;
		if (slvcount < NHOSTS)
			slvcount++;
		else {
D 2
			syslog(LOG_EMERG, "timed: no more slots in host table\n");
E 2
I 2
D 13
			syslog(LOG_ALERT, "no more slots in host table");
E 13
I 13
			syslog(LOG_ERR, "no more slots in host table");
E 13
E 2
		}
	} else {
		/* need to clear sequence number anyhow */
		hp[ret].seq = 0;
	}
#ifdef MEASURE
	header = ON;
#endif
	return(ret);
}

I 7
/*
 * Remove all the machines from the host table that exist on the given
 * network.  This is called when a master transitions to a slave on a
 * given network.
 */

rmnetmachs(ntp)
	register struct netinfo *ntp;
{
	int i;

	if (trace)
		prthp();
	for (i = 1; i < slvcount; i++)
		if ((hp[i].addr.sin_addr.s_addr & ntp->mask) == ntp->net)
			rmmach(i--);
	if (trace)
		prthp();
}

/*
 * remove the machine with the given index in the host table.
 */
rmmach(ind)
	int ind;
{
	if (trace)
		fprintf(fd, "rmmach: %s\n", hp[ind].name);
D 8
	if (slvcount-ind-1 > 0)
		bcopy(&hp[ind+1], &hp[ind], (slvcount-ind-1)*sizeof(hp[ind]));
	slvcount--;
E 8
I 8
	free(hp[ind].name);
	hp[ind] = hp[--slvcount];
E 8
}

E 7
prthp()
{
	int i;

	fprintf(fd, "host table:");
	for (i=1; i<slvcount; i++)
		fprintf(fd, " %s", hp[i].name);
	fprintf(fd, "\n");
}

D 6
masterup()
E 6
I 6
masterup(net)
struct netinfo *net;
E 6
{
	struct timeval wait;
D 6
	char *strcpy();
E 6
	struct tsp to, *msg, *readmsg();
I 8
D 15
	int ind;
E 15
E 8

	to.tsp_type = TSP_MASTERUP;
I 6
	to.tsp_vers = TSPVERSION;
E 6
	(void)strcpy(to.tsp_name, hostname);
I 5
D 6
	bytenetorder(&msg);
E 5
	broadcast(&to);
E 6
I 6
	bytenetorder(&to);
	if (sendto(sock, (char *)&to, sizeof(struct tsp), 0, &net->dest_addr,
	    sizeof(struct sockaddr_in)) < 0) {
		syslog(LOG_ERR, "sendto: %m");
		exit(1);
	}
E 6

	for (;;) {
		wait.tv_sec = 1;
		wait.tv_usec = 0;
D 6
		msg = readmsg(TSP_SLAVEUP, (char *)ANYADDR, &wait);
E 6
I 6
		msg = readmsg(TSP_SLAVEUP, (char *)ANYADDR, &wait, net);
E 6
		if (msg != NULL) {
D 6
			(void) addmach(msg->tsp_name);
E 6
I 6
D 8
			(void) addmach(msg->tsp_name, &from);
E 8
I 8
D 15
			ind = addmach(msg->tsp_name, &from);
E 15
I 15
			(void) addmach(msg->tsp_name, &from);
E 15
E 8
E 6
		} else
			break;
I 8
	}
}

newslave(ind, seq)
I 16
u_short seq;
E 16
{
	struct tsp to;
	struct tsp *answer, *acksend();
D 15
	struct timeval mytime;
E 15

	if (trace)
		prthp();
	if (seq == 0 || hp[ind].seq !=  seq) {
		hp[ind].seq = seq;
		to.tsp_type = TSP_SETTIME;
		(void)strcpy(to.tsp_name, hostname);
		/*
		 * give the upcoming slave the time
		 * to check its input queue before
		 * setting the time
		 */
		sleep(1);
D 15
		to.tsp_time.tv_usec = 0;
		(void) gettimeofday(&mytime,
E 15
I 15
		(void) gettimeofday(&to.tsp_time,
E 15
		    (struct timezone *)0);
D 15
		to.tsp_time.tv_sec = mytime.tv_sec;
E 15
		answer = acksend(&to, &hp[ind].addr,
		    hp[ind].name, TSP_ACK,
		    (struct netinfo *)NULL);
		if (answer == NULL) {
D 13
			syslog(LOG_ERR,
			    "ERROR ON SETTIME machine: %s",
E 13
I 13
			syslog(LOG_WARNING,
			    "no reply to initial SETTIME from: %s",
E 13
			    hp[ind].name);
			rmmach(ind);
		}
I 12
	}
}

char *wtmpfile = "/usr/adm/wtmp";
struct utmp wtmp[2] = {
	{ "|", "", "", 0 },
	{ "{", "", "", 0 }
};

D 17
/*
 * Rounding doesn't work well because new time is always
 * truncated, but oldtime is normally distributed.
 */
E 17
logwtmp(otime, ntime)
struct timeval otime, ntime;
{
	int f;

D 18
	if (otime.tv_sec == ntime.tv_sec)
E 18
I 18
	wtmp[0].ut_time = otime.tv_sec + (otime.tv_usec + 500000) / 1000000;
	wtmp[1].ut_time = ntime.tv_sec + (ntime.tv_usec + 500000) / 1000000;
	if (wtmp[0].ut_time == wtmp[1].ut_time)
E 18
		return;
D 17
	wtmp[0].ut_time = otime.tv_sec; /* +(otime.tv_usec + 500000)/1000000;*/
	wtmp[1].ut_time = ntime.tv_sec; /* +(ntime.tv_usec + 500000)/1000000;*/
E 17
I 17
D 18
	wtmp[0].ut_time = otime.tv_sec; + (otime.tv_usec + 500000) / 1000000;
	wtmp[1].ut_time = ntime.tv_sec; + (ntime.tv_usec + 500000) / 1000000;
E 18
E 17
	if ((f = open(wtmpfile, O_WRONLY|O_APPEND)) >= 0) {
		(void) write(f, (char *)wtmp, sizeof(wtmp));
		(void) close(f);
E 12
E 8
	}
}
E 1
