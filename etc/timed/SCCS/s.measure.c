h38841
s 00010/00005/00180
d D 2.6 88/06/18 14:08:18 bostic 8 7
c install approved copyright notice
e
s 00009/00003/00176
d D 2.5 87/12/23 14:30:11 bostic 7 6
c append Berkeley header; NASA wants a copy
e
s 00001/00001/00178
d D 2.4 86/05/28 20:09:53 bloom 6 5
c lint cleanup (fix sequence number problem)
e
s 00027/00020/00152
d D 2.3 86/04/21 15:59:16 bloom 5 4
c ip header returned with raw packet, checksum must be 0 for calculating
c checksum, use best measurement if within RANGE, check sequence numbers
e
s 00065/00086/00107
d D 2.2 86/04/11 18:14:21 karels 4 3
c major hacks for performance
e
s 00026/00026/00167
d D 2.1 85/12/10 13:07:09 bloom 3 2
c Multi network support
e
s 00007/00001/00186
d D 1.2 85/10/23 13:42:09 gusella 2 1
c checks for NONSTDTIME properly
e
s 00187/00000/00000
d D 1.1 85/06/26 22:17:06 gusella 1 0
c date and time created 85/06/26 22:17:06 by gusella
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
E 7
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

#include "globals.h"
#include <protocols/timed.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#define BIASP	 	43199999
#define BIASN		-43200000
#define MODULO	 	86400000
#define PROCESSING_TIME	5 	/* ms. to reduce error in measurement */

#define PACKET_IN	1024
D 4
#define PACKET_OUT	160
E 4

extern int id;
int measure_delta;
extern int sock_raw;
I 5
static n_short seqno = 0;
E 5
D 3
extern struct sockaddr_in server;
E 3

/*
 * Measures the differences between machines' clocks using
 * ICMP timestamp messages.
D 4
 * Called by master with ckrange = 1, by clockdiff with ckrange = 0.
E 4
 */

D 3
measure(wait, ckrange)
E 3
I 3
D 4
measure(wait, addr, ckrange)
E 4
I 4
measure(wait, addr)
E 4
E 3
struct timeval *wait;
I 3
struct sockaddr_in *addr;
E 3
D 4
int ckrange;
E 4
{
	int length;
	int status;
D 5
	int msgcount, trials, ntransmitted;
E 5
I 5
	int msgcount, trials;
E 5
D 3
	int cc, count, ready, found;
E 3
I 3
	int cc, count;
	fd_set ready;
E 3
	long sendtime, recvtime, histime;
	long min1, min2, diff;
D 3
	long delta1, delta2;
	struct timeval tv1, tv2, tout;
	struct sockaddr_in where;
E 3
I 3
	register long delta1, delta2;
	struct timeval tv1, tout;
E 3
D 5
	u_char packet[PACKET_IN];
E 5
I 5
	u_char packet[PACKET_IN], opacket[64];
E 5
	register struct icmp *icp = (struct icmp *) packet;
D 5
	
E 5
I 5
	register struct icmp *oicp = (struct icmp *) opacket;
	struct ip *ip = (struct ip *) packet;

E 5
	min1 = min2 = 0x7fffffff;
D 5
	ntransmitted = 1;
D 4
	trials = 0;
E 4
	status = GOOD;
E 5
I 5
	status = HOSTDOWN;
E 5
	measure_delta = HOSTDOWN;

/* empties the icmp input queue */
I 3
	FD_ZERO(&ready);
E 3
empty:
	tout.tv_sec = tout.tv_usec = 0;
D 3
	ready = 1<<sock_raw;
	found = select(20, &ready, (int *)0, (int *)0, &tout);
	if (found) {
E 3
I 3
	FD_SET(sock_raw, &ready);
	if (select(FD_SETSIZE, &ready, (fd_set *)0, (fd_set *)0, &tout)) {
E 3
		length = sizeof(struct sockaddr_in);
		cc = recvfrom(sock_raw, (char *)packet, PACKET_IN, 0, 
D 3
							&where, &length);
E 3
I 3
		    (struct sockaddr_in *)NULL, &length);
E 3
		if (cc < 0)
			return(-1);
		goto empty;
	}

	/*
	 * To measure the difference, select MSGS messages whose round-trip
	 * time is smaller than RANGE if ckrange is 1, otherwise simply
	 * select MSGS messages regardless of round-trip transmission time.
	 * Choose the smallest transmission time in each of the two directions.
	 * Use these two latter quantities to compute the delta between
	 * the two clocks.
	 */

D 4
	msgcount = 1;
E 4
I 3
	length = sizeof(struct sockaddr_in);
I 4
D 5
	icp->icmp_type = ICMP_TSTAMP;
	icp->icmp_code = 0;
	icp->icmp_cksum = 0;
	icp->icmp_id = id;
	icp->icmp_rtime = 0;
	icp->icmp_ttime = 0;
E 5
I 5
	oicp->icmp_type = ICMP_TSTAMP;
	oicp->icmp_code = 0;
	oicp->icmp_cksum = 0;
	oicp->icmp_id = id;
	oicp->icmp_rtime = 0;
	oicp->icmp_ttime = 0;
E 5
E 4
	FD_ZERO(&ready);
E 3
D 4
	while(msgcount <= MSGS) {
		icp->icmp_type = ICMP_TSTAMP;
		icp->icmp_code = 0;
		icp->icmp_cksum = 0;
E 4
I 4
	msgcount = 0;
	for (trials = 0; msgcount < MSGS && trials < TRIALS; ++trials) {
E 4
D 5
		icp->icmp_seq = ntransmitted++;
D 4
		icp->icmp_id = id;
		icp->icmp_rtime = 0;
		icp->icmp_ttime = 0;
E 4
I 4
		trials++;
E 5
I 5
		oicp->icmp_seq = ++seqno;
		oicp->icmp_cksum = 0;
E 5
E 4

		tout.tv_sec = wait->tv_sec;
		tout.tv_usec = wait->tv_usec;
D 3
		ready = 1<<sock_raw;
E 3

D 3
		where = server;

E 3
    		(void)gettimeofday (&tv1, (struct timezone *)0);
D 5
		sendtime = icp->icmp_otime = (tv1.tv_sec % (24*60*60)) * 1000 
E 5
I 5
		sendtime = oicp->icmp_otime = (tv1.tv_sec % (24*60*60)) * 1000 
E 5
							+ tv1.tv_usec / 1000;
D 4
		icp->icmp_cksum = in_cksum((u_short *)icp, PACKET_OUT);
E 4
I 4
D 5
		icp->icmp_cksum = in_cksum((u_short *)icp, sizeof(*icp));
E 5
I 5
		oicp->icmp_cksum = in_cksum((u_short *)oicp, sizeof(*oicp));
E 5
E 4
	
D 4
		count = sendto(sock_raw, (char *)packet, PACKET_OUT, 0, 
E 4
I 4
D 5
		count = sendto(sock_raw, (char *)packet, sizeof(*icp), 0, 
E 5
I 5
		count = sendto(sock_raw, (char *)opacket, sizeof(*oicp), 0, 
E 5
E 4
D 3
				&where, sizeof(where));
E 3
I 3
				addr, sizeof(struct sockaddr_in));
E 3
		if (count < 0) {
			status = UNREACHABLE;
			return(-1);
		}
D 3
		found = select(20, &ready, (int *)0, (int *)0, &tout);
		if (found) {
			length = sizeof(struct sockaddr_in);
E 3
I 3
D 4
		FD_SET(sock_raw, &ready);
		if (select(FD_SETSIZE, &ready, (fd_set *)0, (fd_set *)0,
		    &tout)) {
E 3
			cc = recvfrom(sock_raw, (char *)packet, PACKET_IN, 0, 
E 4
I 4
		for (;;) {
			FD_SET(sock_raw, &ready);
			if ((count = select(FD_SETSIZE, &ready, (fd_set *)0,
			    (fd_set *)0, &tout)) <= 0)
				break;
D 6
			cc = recvfrom(sock_raw, packet, PACKET_IN, 0, 
E 6
I 6
			cc = recvfrom(sock_raw, (char *)packet, PACKET_IN, 0, 
E 6
E 4
D 3
							&where, &length);
			(void)gettimeofday(&tv2, (struct timezone *)0);
E 3
I 3
			    (struct sockaddr_in *)NULL, &length);
			(void)gettimeofday(&tv1, (struct timezone *)0);
E 3
			if (cc < 0)
				return(-1);
D 4
			if((icp->icmp_type == ICMP_TSTAMPREPLY) && 
					(icp->icmp_id == id)) {
				trials = 0;
D 3
				recvtime = (tv2.tv_sec % (24*60*60)) * 1000 + tv2.tv_usec / 1000;
E 3
I 3
				recvtime = (tv1.tv_sec % (24*60*60)) * 1000 +
				    tv1.tv_usec / 1000;
E 3
				diff = recvtime - sendtime;
				/*
				 * diff can be less than 0 aroud midnight
				 */
				if ((diff > RANGE && ckrange) || diff < 0) {
					continue;
				}
				histime = ntohl((u_long)icp->icmp_rtime);
D 2
				if ((histime >> 32) == -1) {
E 2
I 2
				/*
 				 * a hosts using a time format different from 
				 * ms. since midnight UT (as per RFC792) should
				 * set the high order bit of the 32-bit time
				 * value it transmits.
				 */
				if ((histime & 0x80000000) != 0) {
E 2
					status = NONSTDTIME;
					break;
				}
				delta1 = histime - sendtime;
				/*
				 * Handles wrap-around to avoid that around 
				 * midnight small time differences appear 
				 * enormous. However, the two machine's clocks
				 * must be within 12 hours from each other.
				 */
				if (delta1 < BIASN)
					delta1 += MODULO;
				else if (delta1 > BIASP)
					delta1 -= MODULO;
				delta2 = recvtime - histime;
				if (delta2 < BIASN)
					delta2 += MODULO;
				else if (delta2 > BIASP)
					delta2 -= MODULO;
				if (delta1 < min1)  
					min1 = delta1;
				if (delta2 < min2)
					min2 = delta2;

				msgcount++;
			} else {
				/* empties the icmp input queue */
				tout.tv_sec = tout.tv_usec = 0;
D 3
				ready = 1<<sock_raw;
				found = select(20, &ready, (int *)0, 
							(int *)0, &tout);
				if (found) {
					length = sizeof(struct sockaddr_in);
E 3
I 3
				FD_SET(sock_raw, &ready);
				if (select(FD_SETSIZE, &ready, (fd_set *)0,
				    (fd_set *)0, &tout)) {
E 3
					cc = recvfrom(sock_raw, (char *)packet,
D 3
						 PACKET_IN, 0, &where, &length);
E 3
I 3
						 PACKET_IN, 0,
						 (struct sockaddr_in *)NULL,
						 &length);
E 3
					if (cc < 0)
						return(-1);
				}
E 4
I 4
D 5
			if((icp->icmp_type != ICMP_TSTAMPREPLY) || 
			    icp->icmp_id != id)
E 4
				continue;
E 5
I 5
			icp = (struct icmp *)(packet + (ip->ip_hl << 2));
			if((icp->icmp_type == ICMP_TSTAMPREPLY) &&
			    icp->icmp_id == id && icp->icmp_seq == seqno)
				break;
E 5
D 4
			}
		} else {
			if (++trials < TRIALS) {
				continue;
			} else {
				status = HOSTDOWN;
				break;
			}
E 4
		}
D 4
	}					/* end of while */
E 4
I 4
		if (count <= 0)
			continue;		/* resend */
		recvtime = (tv1.tv_sec % (24*60*60)) * 1000 +
		    tv1.tv_usec / 1000;
		diff = recvtime - sendtime;
		/*
		 * diff can be less than 0 aroud midnight
		 */
		if (diff < 0)
			continue;
		msgcount++;
		histime = ntohl((u_long)icp->icmp_rtime);
		/*
		 * a hosts using a time format different from 
		 * ms. since midnight UT (as per RFC792) should
		 * set the high order bit of the 32-bit time
		 * value it transmits.
		 */
		if ((histime & 0x80000000) != 0) {
			status = NONSTDTIME;
			break;
		}
I 5
		status = GOOD;
E 5
		delta1 = histime - sendtime;
		/*
		 * Handles wrap-around to avoid that around 
		 * midnight small time differences appear 
		 * enormous. However, the two machine's clocks
		 * must be within 12 hours from each other.
		 */
		if (delta1 < BIASN)
			delta1 += MODULO;
		else if (delta1 > BIASP)
			delta1 -= MODULO;
		delta2 = recvtime - histime;
		if (delta2 < BIASN)
			delta2 += MODULO;
		else if (delta2 > BIASP)
			delta2 -= MODULO;
		if (delta1 < min1)  
			min1 = delta1;
		if (delta2 < min2)
			min2 = delta2;
D 5
		if (diff < RANGE)
E 5
I 5
		if (diff < RANGE) {
			min1 = delta1;
			min2 = delta2;
E 5
			break;
I 5
		}
E 5
	}
E 4

	/*
	 * If no answer is received for TRIALS consecutive times, 
	 * the machine is assumed to be down
	 */
	 if (status == GOOD) {
		measure_delta = (min1 - min2)/2 + PROCESSING_TIME;
	}
	return(status);
}
E 1
