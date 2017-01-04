h54249
s 00010/00005/00140
d D 2.5 88/06/18 14:08:13 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00136
d D 2.4 87/12/23 14:30:07 bostic 8 7
c append Berkeley header; NASA wants a copy
e
s 00001/00002/00138
d D 2.3 86/05/28 09:40:53 bloom 7 6
c finish up for Mike
e
s 00027/00010/00113
d D 2.2 86/05/27 15:35:02 karels 6 5
c use settimeofday if it's too large a change
e
s 00002/00009/00121
d D 2.1 85/12/10 13:06:49 bloom 5 4
c Multi network support
e
s 00000/00001/00130
d D 1.4 85/11/16 18:32:12 bloom 4 3
c use line buffering for traces instead of explicit calls to fflush
e
s 00002/00001/00129
d D 1.3 85/09/18 19:43:23 bloom 3 2
c fix syslog messages
e
s 00001/00001/00129
d D 1.2 85/09/17 21:04:38 eric 2 1
c facilities in syslog
e
s 00130/00000/00000
d D 1.1 85/06/22 22:07:51 gusella 1 0
c date and time created 85/06/22 22:07:51 by gusella
e
u
U
t
T
I 1
/*
D 6
 * Copyright (c) 1983 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1985 Regents of the University of California.
E 6
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

D 5
extern int slvcount;
extern struct host hp[];
extern char hostname[];
extern struct sockaddr_in server;
E 5
#ifdef MEASURE
extern FILE *fp;
#endif

/* 
 * `correct' sends to the slaves the corrections for their clocks
 */

correct(avdelta)
long avdelta;
{
	int i;
	int corr;
D 5
	char *strcpy();
E 5
	struct timeval adjlocal;
	struct tsp msgs;
	struct timeval mstotvround();
	struct tsp *answer, *acksend();

#ifdef MEASURE
	for(i=0; i<slvcount; i++) {
		if (hp[i].delta == HOSTDOWN)
			fprintf(fp, "%s\t", "down");
		else { 
			fprintf(fp, "%d\t", hp[i].delta);
		}
	}
	fprintf(fp, "\n");
#endif
	corr = avdelta - hp[0].delta;
	adjlocal = mstotvround(&corr);
	adjclock(&adjlocal);
#ifdef MEASURE
	fprintf(fp, "%d\t", corr);
#endif

	for(i=1; i<slvcount; i++) {
		if (hp[i].delta != HOSTDOWN)  {
D 5
			bcopy((char *)&hp[i].addr, 
					(char *)&(server.sin_addr.s_addr),
						hp[i].length);
E 5
			corr = avdelta - hp[i].delta;
			msgs.tsp_time = mstotvround(&corr);
			msgs.tsp_type = (u_char)TSP_ADJTIME;
			(void)strcpy(msgs.tsp_name, hostname);
D 5
			answer = acksend(&msgs, hp[i].name, TSP_ACK);
E 5
I 5
			answer = acksend(&msgs, &hp[i].addr, hp[i].name,
			    TSP_ACK, (struct netinfo *)NULL);
E 5
			if (answer == NULL) {
				hp[i].delta = HOSTDOWN;
#ifdef MEASURE
				fprintf(fp, "%s\t", "down");
			} else {
				fprintf(fp, "%d\t", corr);
#endif
			}
		} else {
#ifdef MEASURE
			fprintf(fp, "%s\t", "down");
#endif
		}
	}
#ifdef MEASURE
	fprintf(fp, "\n");
D 4
	(void)fflush(fp);
E 4
#endif
}

/* 
 * `mstotvround' rounds up the value of the argument to the 
 * nearest multiple of five, and converts it into a timeval 
 */
 
struct timeval mstotvround(x)
int *x;
{
	int temp;
	struct timeval adj;

	temp = *x % 5;
	if (temp >= 3)
		*x = *x-temp+5;
	else {
		if (temp <= -3)
			*x = *x - temp -5;
		else 
			*x = *x-temp;
	}
	adj.tv_sec = *x/1000;
	adj.tv_usec = (*x-adj.tv_sec*1000)*1000;
	if (adj.tv_usec < 0) {
		adj.tv_usec += 1000000;
		adj.tv_sec--;
	}
	return(adj);
}

adjclock(corr)
struct timeval *corr;
{
I 6
	struct timeval now;

E 6
	if (timerisset(corr)) {
D 6
		if (corr->tv_sec < SAMPLEINTVL/10 && 
					corr->tv_sec > - SAMPLEINTVL/10) {
E 6
I 6
D 7
		if (corr->tv_sec < MAXADJ && corr->tv_sec > - MAXADJ)
E 7
I 7
		if (corr->tv_sec < MAXADJ && corr->tv_sec > - MAXADJ) {
E 7
E 6
			(void)adjtime(corr, (struct timeval *)0);
		} else {
D 6
			corr->tv_usec = 0;
			if (corr->tv_sec > 0)
				corr->tv_sec = SAMPLEINTVL/10 - 2;
			else
				corr->tv_sec = - SAMPLEINTVL/10 + 2;
			(void)adjtime(corr, (struct timeval *)0);
E 6
D 2
			syslog(LOG_WARNING, "timed: adjclock called with too large a parameter\n");
E 2
I 2
D 3
			syslog(LOG_WARNING, "timed: adjclock called with too large a parameter");
E 3
I 3
			syslog(LOG_WARNING,
D 6
			    "adjclock called with too large a parameter");
E 6
I 6
			    "clock correction too large to adjust (%d sec)",
			    corr->tv_sec);
			(void) gettimeofday(&now, (struct timezone *)0);
			timevaladd(&now, corr);
			if (settimeofday(&now, (struct timezone *)0) < 0)
				syslog(LOG_ERR, "can't set time");
E 6
E 3
E 2
		}
I 6
D 7
		first = 0;
E 7
	}
}

timevaladd(tv1, tv2)
	register struct timeval *tv1, *tv2;
{
	
	tv1->tv_sec += tv2->tv_sec;
	tv1->tv_usec += tv2->tv_usec;
	if (tv1->tv_usec >= 1000000) {
		tv1->tv_sec++;
		tv1->tv_usec -= 1000000;
	}
	if (tv1->tv_usec < 0) {
		tv1->tv_sec--;
		tv1->tv_usec += 1000000;
E 6
	}
}
E 1
