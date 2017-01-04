h15209
s 00010/00005/00393
d D 5.7 88/06/29 20:49:25 bostic 17 16
c install approved copyright notice
e
s 00010/00004/00388
d D 5.6 88/03/28 13:51:45 bostic 16 15
c add Berkeley specific header
e
s 00026/00043/00366
d D 5.5 86/02/07 21:35:44 minshall 15 14
c Centralize re-synchronization routine.  Only do re-synchronization
e
s 00001/00000/00408
d D 5.4 86/02/07 15:04:50 minshall 14 13
c Fix a few of the lint errors.
e
s 00049/00002/00359
d D 5.3 86/02/07 11:23:32 minshall 13 12
c Add re-transmission to send, and input buffer flush
c to both send and receive.
e
s 00167/00158/00194
d D 5.2 86/02/06 15:01:35 minshall 12 11
c Install version from Jim Guyton <guyton@rand-unix>.
e
s 00007/00001/00345
d D 5.1 85/06/06 09:22:35 dist 11 10
c Add copyright
e
s 00056/00049/00290
d D 4.10 84/10/18 19:06:57 sam 10 9
c split receive and send buffers (other way just don't work), from 
c mogul@stanford
e
s 00004/00000/00335
d D 4.9 84/10/18 18:45:11 sam 9 8
c fix print format for garbage packets (from mogul@stanford)
e
s 00084/00039/00251
d D 4.8 84/04/12 22:25:14 sam 8 7
c take fixes from rws@mit-ai (follow protocol)
e
s 00003/00001/00287
d D 4.7 83/08/11 22:44:41 sam 7 6
c standardize sccs keyword lines
e
s 00076/00079/00212
d D 4.6 83/06/12 01:26:48 sam 6 5
c too much to say...let's just say it seems to work now
e
s 00002/00002/00289
d D 4.5 83/05/11 22:04:27 sam 5 4
c split tftpd out to etc source directory
e
s 00005/00005/00286
d D 4.4 82/11/15 01:26:18 sam 4 3
c recvfrom/sendto flags arg out of order
e
s 00015/00006/00276
d D 4.3 82/11/14 15:21:50 sam 3 2
c convert to 4.1c sys calls and directory layout
e
s 00002/00000/00280
d D 4.2 82/08/17 15:59:32 sam 2 1
c missing initializations
e
s 00280/00000/00000
d D 4.1 82/08/16 22:20:31 sam 1 0
c date and time created 82/08/16 22:20:31 by sam
e
u
U
t
T
I 11
/*
D 12
 * Copyright (c) 1983 Regents of the University of California.
E 12
I 12
D 16
 * Copyright (c) 1985 Regents of the University of California.
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 16
I 16
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
E 16
 */

E 11
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif
E 11
I 11
D 16
#endif not lint
E 16
I 16
#endif /* not lint */
E 16
E 11
E 7

I 12
/* Many bug fixes are from Jim Guyton <guyton@rand-unix> */

E 12
/*
 * TFTP User Program -- Protocol Machines
 */
#include <sys/types.h>
D 3
#include <net/in.h>
E 3
#include <sys/socket.h>
I 13
D 15
#include <sys/ioctl.h>
E 15
E 13
I 12
#include <sys/time.h>
E 12
I 3

#include <netinet/in.h>
D 8

E 8
I 8
D 12
#include <arpa/inet.h>
E 12
I 12

E 12
E 8
I 5
#include <arpa/tftp.h>

E 5
E 3
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <setjmp.h>
I 8
D 12
#include <netdb.h>
E 12
E 8
I 3
D 5

E 3
#include "tftp.h"
E 5

extern	int errno;
D 12
extern	struct sockaddr_in sin;
extern	char mode[];
int	f;
int	trace;
D 8
int	verbose;
E 8
int	connected;
D 10
char	buf[BUFSIZ];
E 10
I 10
char	sbuf[BUFSIZ];			/* send buffer */
char	rbuf[BUFSIZ];			/* receive buffer */
E 10
I 6
int	rexmtval;
int	maxtimeout;
E 12
I 12

extern  struct sockaddr_in sin;         /* filled in by main */
extern  int     f;                      /* the opened socket */
extern  int     trace;
extern  int     verbose;
extern  int     rexmtval;
extern  int     maxtimeout;

#define PKTSIZE    SEGSIZE+4
char    ackbuf[PKTSIZE];
E 12
E 6
int	timeout;
jmp_buf	toplevel;
I 6
jmp_buf	timeoutbuf;
E 6

timer()
{
D 6
	timeout += TIMEOUT;
	if (timeout >= MAXTIMEOUT) {
E 6
I 6

	timeout += rexmtval;
	if (timeout >= maxtimeout) {
E 6
		printf("Transfer timed out.\n");
		longjmp(toplevel, -1);
	}
D 6
	alarm(TIMEOUT);
E 6
I 6
	longjmp(timeoutbuf, 1);
E 6
}

/*
 * Send the requested file.
 */
D 12
sendfile(fd, name)
E 12
I 12
sendfile(fd, name, mode)
E 12
	int fd;
	char *name;
I 12
	char *mode;
E 12
{
D 10
	register struct tftphdr *tp = (struct tftphdr *)buf;
E 10
I 10
D 12
	register struct tftphdr *stp = (struct tftphdr *)sbuf;
	register struct tftphdr *rtp = (struct tftphdr *)rbuf;
E 10
	register int block = 0, size, n, amount = 0;
D 8
	struct sockaddr_in from;
E 8
I 8
	struct sockaddr_in from, to;
E 8
	time_t start = time(0), delta;
I 3
D 8
	int fromlen;
E 8
I 8
	int fromlen, aborted = 0;
E 12
I 12
	register struct tftphdr *ap;       /* data and ack packets */
	struct tftphdr *r_init(), *dp;
	register int block = 0, size, n;
	register unsigned long amount = 0;
	struct sockaddr_in from;
	int fromlen;
	int convert;            /* true if doing nl->crlf conversion */
	FILE *file;
E 12
E 8
E 3

I 8
D 12
	to = sin;
E 12
I 12
	startclock();           /* start stat's clock */
	dp = r_init();          /* reset fillbuf/read-ahead code */
	ap = (struct tftphdr *)ackbuf;
	file = fdopen(fd, "r");
	convert = !strcmp(mode, "netascii");

E 12
E 8
D 6
	size = makerequest(WRQ, name) - 4;
I 2
	timeout = 0;
E 2
	sigset(SIGALRM, timer);
E 6
I 6
	signal(SIGALRM, timer);
E 6
	do {
D 6
		if (block != 0) {
E 6
I 6
		if (block == 0)
D 12
			size = makerequest(WRQ, name) - 4;
E 12
I 12
			size = makerequest(WRQ, name, dp, mode) - 4;
E 12
		else {
E 6
D 10
			size = read(fd, tp->th_data, SEGSIZE);
E 10
I 10
D 12
			size = read(fd, stp->th_data, SEGSIZE);
E 12
I 12
		/*      size = read(fd, dp->th_data, SEGSIZE);   */
			size = readit(file, &dp, convert);
E 12
E 10
			if (size < 0) {
D 8
				nak(errno + 100);
E 8
I 8
D 12
				nak(&to, errno + 100);
E 12
I 12
				nak(errno + 100);
E 12
E 8
				break;
			}
D 10
			tp->th_opcode = htons((u_short)DATA);
			tp->th_block = htons((u_short)block);
E 10
I 10
D 12
			stp->th_opcode = htons((u_short)DATA);
			stp->th_block = htons((u_short)block);
E 12
I 12
			dp->th_opcode = htons((u_short)DATA);
			dp->th_block = htons((u_short)block);
E 12
E 10
		}
		timeout = 0;
D 6
		alarm(TIMEOUT);
rexmt:
E 6
I 6
		(void) setjmp(timeoutbuf);
I 13
send_data:
D 15
		/* Now, we flush anything pending to be read */
		/* This is to try to keep in synch between the two sides */
		while (1) {
			int i, j = 0;
			char rbuf[PKTSIZE];

			(void) ioctl(f, FIONREAD, &i);
			if (i) {
				j++;
				fromlen = sizeof from;
				n = recvfrom(f, rbuf, sizeof (rbuf), 0,
					(caddr_t)&from, &fromlen);
			} else {
				if (j && trace) {
					printf("discarded %d packets\n", j);
				}
				break;
			}
		}
E 15
E 13
E 6
		if (trace)
D 8
			tpacket("sent", tp, size + 4);
D 3
		if (send(f, &sin, buf, size + 4) != size + 4) {
E 3
I 3
D 4
		n = sendto(f, buf, size + 4, (caddr_t)&sin, sizeof (sin), 0);
E 4
I 4
		n = sendto(f, buf, size + 4, 0, (caddr_t)&sin, sizeof (sin));
E 8
I 8
D 10
			tpacket("sent", &to, tp, size + 4);
		n = sendto(f, buf, size + 4, 0, (caddr_t)&to, sizeof (to));
E 10
I 10
D 12
			tpacket("sent", &to, stp, size + 4);
		n = sendto(f, sbuf, size + 4, 0, (caddr_t)&to, sizeof (to));
E 12
I 12
			tpacket("sent", dp, size + 4);
		n = sendto(f, dp, size + 4, 0, (caddr_t)&sin, sizeof (sin));
E 12
E 10
E 8
E 4
		if (n != size + 4) {
E 3
D 6
			perror("send");
			break;
E 6
I 6
			perror("tftp: sendto");
D 8
			goto abort;
E 8
I 8
D 12
			aborted = 1;
			goto done;
E 12
I 12
			goto abort;
E 12
E 8
E 6
		}
I 12
		read_ahead(file, convert);
E 12
D 6
again:
D 3
		n = receive(f, &from, buf, sizeof (buf));
E 3
I 3
		fromlen = sizeof (from);
D 4
		n = recvfrom(f, buf, sizeof (buf), (caddr_t)&from, &fromlen, 0);
E 4
I 4
		n = recvfrom(f, buf, sizeof (buf), 0, (caddr_t)&from, &fromlen);
E 4
E 3
		if (n <= 0) {
			if (n == 0)
				goto again;
			if (errno == EINTR)
				goto rexmt;
E 6
I 6
D 13
		do {
E 13
I 13
		for ( ; ; ) {
E 13
I 8
D 12
again:
E 12
E 8
			alarm(rexmtval);
			do {
				fromlen = sizeof (from);
D 10
				n = recvfrom(f, buf, sizeof (buf), 0,
E 10
I 10
D 12
				n = recvfrom(f, rbuf, sizeof (rbuf), 0,
E 12
I 12
				n = recvfrom(f, ackbuf, sizeof (ackbuf), 0,
E 12
E 10
				    (caddr_t)&from, &fromlen);
			} while (n <= 0);
E 6
			alarm(0);
D 6
			perror("receive");
			break;
		}
		alarm(0);
		if (trace)
			tpacket("received", tp, n);
I 3
		/* should verify packet came from server */
E 3
#if vax || pdp11
		tp->th_opcode = ntohs(tp->th_opcode);
		tp->th_block = ntohs(tp->th_block);
#endif
		if (tp->th_opcode == ERROR) {
			printf("Error code %d: %s\n", tp->th_code,
				tp->th_msg);
			break;
		}
		if (tp->th_opcode != ACK || block != tp->th_block)
			goto again;
E 6
I 6
			if (n < 0) {
				perror("tftp: recvfrom");
D 8
				goto abort;
E 8
I 8
D 12
				aborted = 1;
				goto done;
E 12
I 12
				goto abort;
E 12
E 8
			}
I 8
D 12
			if (to.sin_addr.s_addr != from.sin_addr.s_addr) {
D 10
				tpacket("discarded (wrong host)", &from, tp, n);
E 10
I 10
				tpacket("discarded (wrong host)",
				    &from, rtp, n);
E 10
				goto again;
			}
			if (to.sin_port = sin.sin_port)
				to.sin_port = from.sin_port;
			if (to.sin_port != from.sin_port) {
D 10
				tpacket("discarded (wrong port)", &from, tp, n);
E 10
I 10
				tpacket("discarded (wrong port)",
				    &from, rtp, n);
E 10
				goto again;
			}
E 12
I 12
			sin.sin_port = from.sin_port;   /* added */
E 12
E 8
			if (trace)
D 8
				tpacket("received", tp, n);
E 8
I 8
D 10
				tpacket("received", &from, tp, n);
E 10
I 10
D 12
				tpacket("received", &from, rtp, n);
E 12
I 12
				tpacket("received", ap, n);
E 12
E 10
E 8
			/* should verify packet came from server */
D 10
			tp->th_opcode = ntohs(tp->th_opcode);
			tp->th_block = ntohs(tp->th_block);
			if (tp->th_opcode == ERROR) {
				printf("Error code %d: %s\n", tp->th_code,
					tp->th_msg);
E 10
I 10
D 12
			rtp->th_opcode = ntohs(rtp->th_opcode);
			rtp->th_block = ntohs(rtp->th_block);
			if (rtp->th_opcode == ERROR) {
				printf("Error code %d: %s\n", rtp->th_code,
					rtp->th_msg);
E 10
D 8
				goto abort;
E 8
I 8
				aborted = 1;
				goto done;
E 12
I 12
			ap->th_opcode = ntohs(ap->th_opcode);
			ap->th_block = ntohs(ap->th_block);
			if (ap->th_opcode == ERROR) {
				printf("Error code %d: %s\n", ap->th_code,
					ap->th_msg);
				goto abort;
E 12
E 8
			}
D 10
		} while (tp->th_opcode != ACK && block != tp->th_block);
E 10
I 10
D 12
		} while (rtp->th_opcode != ACK && block != rtp->th_block);
E 12
I 12
D 13
		} while (ap->th_opcode != ACK || block != ap->th_block);
E 13
I 13
			if (ap->th_opcode == ACK) {
I 15
				int j;

E 15
				if (ap->th_block == block) {
					break;
D 15
				} else if (ap->th_block == (block-1)) {
					goto send_data;	/* resend packet */
E 15
				}
I 15
				/* On an error, try to synchronize
				 * both sides.
				 */
				j = synchnet(f);
				if (j && trace) {
					printf("discarded %d packets\n",
							j);
				}
				if (ap->th_block == (block-1)) {
					goto send_data;
				}
E 15
			}
		}
E 13
E 12
E 10
E 6
		if (block > 0)
			amount += size;
		block++;
	} while (size == SEGSIZE || block == 1);
D 6
	alarm(0);
E 6
I 6
D 8
abort:
E 6
	(void) close(fd);
	if (amount > 0) {
E 8
I 8
D 12
	if (!aborted && amount > 0) {
E 8
		delta = time(0) - start;
		printf("Sent %d bytes in %d seconds.\n", amount, delta);
	}
I 8
done:
	(void) close(fd);
	return (aborted);
E 12
I 12
abort:
	fclose(file);
	stopclock();
	if (amount > 0)
		printstats("Sent", amount);
E 12
E 8
}

/*
 * Receive a file.
 */
D 12
recvfile(fd, name)
E 12
I 12
recvfile(fd, name, mode)
E 12
	int fd;
	char *name;
I 12
	char *mode;
E 12
{
D 10
	register struct tftphdr *tp = (struct tftphdr *)buf;
E 10
I 10
D 12
	register struct tftphdr *stp = (struct tftphdr *)sbuf;
	register struct tftphdr *rtp = (struct tftphdr *)rbuf;
E 10
	register int block = 1, n, size, amount = 0;
D 8
	struct sockaddr_in from;
E 8
I 8
	struct sockaddr_in from, to;
E 8
	time_t start = time(0), delta;
I 3
D 6
	int fromlen;
E 6
I 6
D 8
	int fromlen, firsttrip = 1;
E 8
I 8
	int fromlen, firsttrip = 1, aborted = 0;
E 12
I 12
	register struct tftphdr *ap;
	struct tftphdr *dp, *w_init();
	register int block = 1, n, size;
	unsigned long amount = 0;
	struct sockaddr_in from;
	int fromlen, firsttrip = 1;
	FILE *file;
	int convert;                    /* true if converting crlf -> lf */
E 12
E 8
E 6
E 3

I 8
D 12
	to = sin;
E 12
I 12
	startclock();
	dp = w_init();
	ap = (struct tftphdr *)ackbuf;
	file = fdopen(fd, "w");
	convert = !strcmp(mode, "netascii");

E 12
E 8
D 6
	size = makerequest(RRQ, name);
I 2
	timeout = 0;
E 2
	sigset(SIGALRM, timer);
	alarm(TIMEOUT);
	goto rexmt;
E 6
I 6
	signal(SIGALRM, timer);
E 6
	do {
I 6
		if (firsttrip) {
D 12
			size = makerequest(RRQ, name);
E 12
I 12
			size = makerequest(RRQ, name, ap, mode);
E 12
			firsttrip = 0;
		} else {
D 10
			tp->th_opcode = htons((u_short)ACK);
			tp->th_block = htons((u_short)(block));
E 10
I 10
D 12
			stp->th_opcode = htons((u_short)ACK);
			stp->th_block = htons((u_short)(block));
E 12
I 12
			ap->th_opcode = htons((u_short)ACK);
			ap->th_block = htons((u_short)(block));
E 12
E 10
			size = 4;
			block++;
		}
E 6
		timeout = 0;
D 6
		alarm(TIMEOUT);
		tp->th_opcode = htons((u_short)ACK);
		tp->th_block = htons((u_short)(block));
		size = 4;
		block++;
rexmt:
E 6
I 6
		(void) setjmp(timeoutbuf);
I 12
send_ack:
I 13
D 15
		/* Now, we flush anything pending to be read */
		/* This is to try to keep in synch between the two sides */
		while (1) {
			int i, j = 0;
			char rbuf[PKTSIZE];

			(void) ioctl(f, FIONREAD, &i);
			if (i) {
				j++;
				fromlen = sizeof from;
				n = recvfrom(f, rbuf, sizeof (rbuf), 0,
					(caddr_t)&from, &fromlen);
			} else {
				if (j && trace) {
					printf("discarded %d packets\n", j);
				}
				break;
			}
		}
E 15
E 13
E 12
E 6
		if (trace)
D 8
			tpacket("sent", tp, size);
D 3
		if (send(f, &sin, buf, size) != size) {
E 3
I 3
D 4
		if (sendto(f, buf, size, (caddr_t)&sin, sizeof (sin), 0) != size) {
E 4
I 4
D 6
		if (sendto(f, buf, size, 0, (caddr_t)&sin, sizeof (sin)) != size) {
E 4
E 3
			perror("send");
			break;
		}
again:
D 3
		n = receive(f, &from, buf, sizeof (buf));
E 3
I 3
D 4
		n = recvfrom(f, buf, sizeof (buf), (caddr_t)&from, &fromlen, 0);
E 4
I 4
		n = recvfrom(f, buf, sizeof (buf), 0, (caddr_t)&from, &fromlen);
E 4
E 3
		if (n <= 0) {
			if (n == 0)
				goto again;
			if (errno == EINTR)
				goto rexmt;
E 6
I 6
		if (sendto(f, buf, size, 0, (caddr_t)&sin,
		    sizeof (sin)) != size) {
E 8
I 8
D 10
			tpacket("sent", &to, tp, size);
		if (sendto(f, buf, size, 0, (caddr_t)&to,
E 10
I 10
D 12
			tpacket("sent", &to, stp, size);
		if (sendto(f, sbuf, size, 0, (caddr_t)&to,
E 10
		    sizeof (to)) != size) {
E 12
I 12
			tpacket("sent", ap, size);
		if (sendto(f, ackbuf, size, 0, (caddr_t)&sin,
		    sizeof (sin)) != size) {
E 12
E 8
E 6
			alarm(0);
D 6
			perror("receive");
			break;
E 6
I 6
			perror("tftp: sendto");
D 8
			goto abort;
E 8
I 8
D 12
			aborted = 1;
			goto done;
E 12
I 12
			goto abort;
E 12
E 8
E 6
		}
D 6
		alarm(0);
		if (trace)
			tpacket("received", tp, n);
I 3
		/* should verify client address */
E 3
#if vax || pdp11
		tp->th_opcode = ntohs(tp->th_opcode);
		tp->th_block = ntohs(tp->th_block);
#endif
		if (tp->th_opcode == ERROR) {
			printf("Error code %d: %s\n", tp->th_code,
				tp->th_msg);
			break;
		}
		if (tp->th_opcode != DATA || block != tp->th_block)
			goto again;
E 6
I 6
D 12
		do {
I 8
again:
E 12
I 12
		write_behind(file, convert);
		for ( ; ; ) {
E 12
E 8
			alarm(rexmtval);
D 8
			do
E 8
I 8
D 12
			do {
E 12
I 12
			do  {
E 12
				fromlen = sizeof (from);
E 8
D 10
				n = recvfrom(f, buf, sizeof (buf), 0,
E 10
I 10
D 12
				n = recvfrom(f, rbuf, sizeof (rbuf), 0,
E 12
I 12
				n = recvfrom(f, dp, PKTSIZE, 0,
E 12
E 10
				    (caddr_t)&from, &fromlen);
D 8
			while (n <= 0);
E 8
I 8
			} while (n <= 0);
E 8
			alarm(0);
			if (n < 0) {
				perror("tftp: recvfrom");
D 8
				goto abort;
E 8
I 8
D 12
				aborted = 1;
				goto done;
E 12
I 12
				goto abort;
E 12
E 8
			}
I 8
D 12
			if (to.sin_addr.s_addr != from.sin_addr.s_addr) {
D 10
				tpacket("discarded (wrong host)", &from, tp, n);
E 10
I 10
				tpacket("discarded (wrong host)",
				    &from, rtp, n);
E 10
				goto again;
			}
			if (to.sin_port = sin.sin_port)
				to.sin_port = from.sin_port;
			if (to.sin_port != from.sin_port) {
D 10
				tpacket("discarded (wrong port)", &from, tp, n);
E 10
I 10
				tpacket("discarded (wrong port)",
				    &from, rtp, n);
E 10
				goto again;
			}
E 12
I 12
			sin.sin_port = from.sin_port;   /* added */
E 12
E 8
			if (trace)
D 8
				tpacket("received", tp, n);
			/* should verify client address */
E 8
I 8
D 10
				tpacket("received", &from, tp, n);
E 8
			tp->th_opcode = ntohs(tp->th_opcode);
			tp->th_block = ntohs(tp->th_block);
			if (tp->th_opcode == ERROR) {
				printf("Error code %d: %s\n", tp->th_code,
					tp->th_msg);
E 10
I 10
D 12
				tpacket("received", &from, rtp, n);
			rtp->th_opcode = ntohs(rtp->th_opcode);
			rtp->th_block = ntohs(rtp->th_block);
			if (rtp->th_opcode == ERROR) {
				printf("Error code %d: %s\n", rtp->th_code,
					rtp->th_msg);
E 10
D 8
				goto abort;
E 8
I 8
				aborted = 1;
				goto done;
E 12
I 12
				tpacket("received", dp, n);
			/* should verify client address */
			dp->th_opcode = ntohs(dp->th_opcode);
			dp->th_block = ntohs(dp->th_block);
			if (dp->th_opcode == ERROR) {
				printf("Error code %d: %s\n", dp->th_code,
					dp->th_msg);
				goto abort;
E 12
E 8
			}
D 8
		} while (tp->th_opcode != DATA && block != tp->th_block);
E 8
I 8
D 10
		} while (tp->th_opcode != DATA && tp->th_block != block);
E 8
E 6
		size = write(fd, tp->th_data, n - 4);
E 10
I 10
D 12
		} while (rtp->th_opcode != DATA && rtp->th_block != block);
		size = write(fd, rtp->th_data, n - 4);
E 12
I 12
			if (dp->th_opcode == DATA) {
D 15
				if (dp->th_block == block)
E 15
I 15
				int j;

				if (dp->th_block == block) {
E 15
					break;          /* have next packet */
D 15
				if (dp->th_block == (block-1))
E 15
I 15
				}
				/* On an error, try to synchronize
				 * both sides.
				 */
				j = synchnet(f);
				if (j && trace) {
					printf("discarded %d packets\n", j);
				}
				if (dp->th_block == (block-1)) {
E 15
					goto send_ack;  /* resend ack */
I 15
				}
E 15
			}
		}
	/*      size = write(fd, dp->th_data, n - 4); */
		size = writeit(file, &dp, n - 4, convert);
E 12
E 10
		if (size < 0) {
D 8
			nak(errno + 100);
			break;
E 8
I 8
D 12
			perror("tftp: write");
			nak(&to, errno + 100);
			aborted = 1;
			goto done;
E 12
I 12
			nak(errno + 100);
			break;
E 12
E 8
		}
		amount += size;
	} while (size == SEGSIZE);
D 6
	alarm(0);
E 6
I 6
D 8
abort:
E 8
I 8
D 12
done:
E 8
E 6
D 10
	tp->th_opcode = htons((u_short)ACK);
	tp->th_block = htons((u_short)block);
D 3
	(void) send(f, &sin, buf, 4);
E 3
I 3
D 4
	(void) sendto(f, buf, 4, &sin, sizeof (sin), 0);
E 4
I 4
D 8
	(void) sendto(f, buf, 4, 0, &sin, sizeof (sin));
E 8
I 8
	(void) sendto(f, buf, 4, 0, &to, sizeof (to));
E 10
I 10
	stp->th_opcode = htons((u_short)ACK);
	stp->th_block = htons((u_short)block);
	(void) sendto(f, sbuf, 4, 0, &to, sizeof (to));
E 10
E 8
E 4
E 3
	(void) close(fd);
D 8
	if (amount > 0) {
E 8
I 8
	if (!aborted && amount > 0) {
E 8
		delta = time(0) - start;
		printf("Received %d bytes in %d seconds.\n", amount, delta);
	}
I 8
	return (aborted);
E 12
I 12
abort:                                          /* ok to ack, since user */
	ap->th_opcode = htons((u_short)ACK);    /* has seen err msg */
	ap->th_block = htons((u_short)block);
	(void) sendto(f, ackbuf, 4, 0, &sin, sizeof (sin));
	write_behind(file, convert);            /* flush last buffer */
	fclose(file);
	stopclock();
	if (amount > 0)
		printstats("Received", amount);
E 12
E 8
}

D 12
makerequest(request, name)
E 12
I 12
makerequest(request, name, tp, mode)
E 12
	int request;
D 12
	char *name;
E 12
I 12
	char *name, *mode;
	struct tftphdr *tp;
E 12
{
D 10
	register struct tftphdr *tp;
E 10
I 10
D 12
	register struct tftphdr *stp;
E 10
	int size;
E 12
	register char *cp;

D 10
	tp = (struct tftphdr *)buf;
	tp->th_opcode = htons((u_short)request);
	strcpy(tp->th_stuff, name);
E 10
I 10
D 12
	stp = (struct tftphdr *)sbuf;
	stp->th_opcode = htons((u_short)request);
	strcpy(stp->th_stuff, name);
E 10
	size = strlen(name);
D 10
	cp = tp->th_stuff + strlen(name);
E 10
I 10
	cp = stp->th_stuff + strlen(name);
E 12
I 12
	tp->th_opcode = htons((u_short)request);
	cp = tp->th_stuff;
	strcpy(cp, name);
	cp += strlen(name);
E 12
E 10
	*cp++ = '\0';
	strcpy(cp, mode);
D 12
	cp += sizeof ("netascii") - 1;
E 12
I 12
	cp += strlen(mode);
E 12
	*cp++ = '\0';
D 10
	return (cp - buf);
E 10
I 10
D 12
	return (cp - sbuf);
E 12
I 12
	return (cp - (char *)tp);
E 12
E 10
}

struct errmsg {
	int	e_code;
	char	*e_msg;
} errmsgs[] = {
	{ EUNDEF,	"Undefined error code" },
	{ ENOTFOUND,	"File not found" },
	{ EACCESS,	"Access violation" },
	{ ENOSPACE,	"Disk full or allocation exceeded" },
	{ EBADOP,	"Illegal TFTP operation" },
	{ EBADID,	"Unknown transfer ID" },
	{ EEXISTS,	"File already exists" },
	{ ENOUSER,	"No such user" },
	{ -1,		0 }
};

/*
 * Send a nak packet (error message).
 * Error code passed in is one of the
 * standard TFTP codes, or a UNIX errno
 * offset by 100.
 */
D 8
nak(error)
E 8
I 8
D 12
nak(to, error)
	struct sockaddr_in *to;
E 12
I 12
nak(error)
E 12
E 8
	int error;
{
D 10
	register struct tftphdr *tp;
E 10
I 10
D 12
	register struct tftphdr *stp;
E 12
I 12
	register struct tftphdr *tp;
E 12
E 10
	int length;
	register struct errmsg *pe;
	extern char *sys_errlist[];

D 10
	tp = (struct tftphdr *)buf;
	tp->th_opcode = htons((u_short)ERROR);
	tp->th_code = htons((u_short)error);
E 10
I 10
D 12
	stp = (struct tftphdr *)sbuf;
	stp->th_opcode = htons((u_short)ERROR);
	stp->th_code = htons((u_short)error);
E 12
I 12
	tp = (struct tftphdr *)ackbuf;
	tp->th_opcode = htons((u_short)ERROR);
	tp->th_code = htons((u_short)error);
E 12
E 10
	for (pe = errmsgs; pe->e_code >= 0; pe++)
		if (pe->e_code == error)
			break;
D 12
	if (pe->e_code < 0)
E 12
I 12
	if (pe->e_code < 0) {
E 12
		pe->e_msg = sys_errlist[error - 100];
D 10
	strcpy(tp->th_msg, pe->e_msg);
E 10
I 10
D 12
	strcpy(stp->th_msg, pe->e_msg);
E 12
I 12
		tp->th_code = EUNDEF;
	}
	strcpy(tp->th_msg, pe->e_msg);
E 12
E 10
	length = strlen(pe->e_msg) + 4;
	if (trace)
D 8
		tpacket("sent", tp, length);
	if (send(f, &sin, buf, length) != length)
		perror("nak");
E 8
I 8
D 10
		tpacket("sent", to, tp, length);
	if (sendto(f, buf, length, 0, to, sizeof (*to)) != length)
E 10
I 10
D 12
		tpacket("sent", to, stp, length);
	if (sendto(f, sbuf, length, 0, to, sizeof (*to)) != length)
E 10
		perror("tftp: nak");
E 12
I 12
		tpacket("sent", tp, length);
	if (sendto(f, ackbuf, length, 0, &sin, sizeof (sin)) != length)
		perror("nak");
E 12
E 8
}

D 8
tpacket(s, tp, n)
E 8
I 8
D 12
tpacket(s, sin, tp, n)
	struct sockaddr_in *sin;
E 12
I 12
tpacket(s, tp, n)
I 14
	char *s;
E 14
E 12
E 8
	struct tftphdr *tp;
	int n;
{
	static char *opcodes[] =
	   { "#0", "RRQ", "WRQ", "DATA", "ACK", "ERROR" };
	register char *cp, *file;
	u_short op = ntohs(tp->th_opcode);
	char *index();

I 8
D 12
	printf("%s ", s);
	if (sin) {
		struct hostent *hp = gethostbyaddr(&sin->sin_addr,
		     sizeof (sin->sin_addr), AF_INET);

		printf("%s.%d ",
		    hp == 0 ? inet_ntoa(sin->sin_addr) : hp->h_name,
		    ntohs(sin->sin_port));
	}
E 12
E 8
	if (op < RRQ || op > ERROR)
D 8
		printf("%s opcode=%x ", s, op);
E 8
I 8
D 12
		printf("opcode=%x ", op);
E 12
I 12
		printf("%s opcode=%x ", s, op);
E 12
E 8
	else
D 8
		printf("%s %s ", s, opcodes[op]);
E 8
I 8
D 12
		printf("%s ", opcodes[op]);
E 12
I 12
		printf("%s %s ", s, opcodes[op]);
E 12
E 8
	switch (op) {

	case RRQ:
	case WRQ:
		n -= 2;
		file = cp = tp->th_stuff;
		cp = index(cp, '\0');
		printf("<file=%s, mode=%s>\n", file, cp + 1);
		break;

	case DATA:
		printf("<block=%d, %d bytes>\n", ntohs(tp->th_block), n - 4);
		break;

	case ACK:
		printf("<block=%d>\n", ntohs(tp->th_block));
		break;

	case ERROR:
		printf("<code=%d, msg=%s>\n", ntohs(tp->th_code), tp->th_msg);
		break;
I 9
D 12

	default:
		putchar('\n');
		break;
E 12
E 9
	}
}
I 12

struct timeval tstart;
struct timeval tstop;
struct timezone zone;

startclock() {
	gettimeofday(&tstart, &zone);
}

stopclock() {
	gettimeofday(&tstop, &zone);
}

printstats(direction, amount)
char *direction;
unsigned long amount;
{
	double delta;
			/* compute delta in 1/10's second units */
	delta = ((tstop.tv_sec*10.)+(tstop.tv_usec/100000)) -
		((tstart.tv_sec*10.)+(tstart.tv_usec/100000));
	delta = delta/10.;      /* back to seconds */
	printf("%s %d bytes in %.1f seconds", direction, amount, delta);
	if (verbose)
		printf(" [%.0f bits/sec]", (amount*8.)/delta);
	putchar('\n');
}

E 12
E 1
