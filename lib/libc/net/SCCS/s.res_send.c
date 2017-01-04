h10035
s 00010/00005/00361
d D 6.21 88/06/27 17:14:18 bostic 36 35
c install approved copyright notice
e
s 00021/00019/00345
d D 6.20 88/05/19 15:49:13 karels 35 34
c disconnect after first server regardless of how we fail
e
s 00009/00004/00355
d D 6.19 88/03/07 21:17:25 bostic 34 33
c added Berkeley specific header
e
s 00046/00008/00313
d D 6.18 87/11/07 23:28:05 karels 33 32
c don't try to connect connected socket, and keep sending;
c check for answer buffer overflow, set truncated flag, and toss overflow data
e
s 00012/00003/00309
d D 6.17 87/05/12 22:12:48 karels 32 31
c connect once, then disconnect
e
s 00015/00009/00297
d D 6.16 87/01/15 06:38:52 kjd 31 30
c fix problem with connect/send
e
s 00010/00000/00296
d D 6.15 86/11/18 16:02:47 kjd 30 28
c fix fdset for 4.2bsd sites
e
s 00009/00000/00296
d R 6.15 86/10/30 13:49:27 kjd 29 28
c add FD_SET for 4.2BSD sites
e
s 00016/00005/00280
d D 6.14 86/07/02 14:12:52 bloom 28 27
c virtual circuits must be able to fall back to the host table as well
e
s 00003/00002/00282
d D 6.13 86/05/07 15:27:31 kjd 27 26
c use FD_ macros
e
s 00011/00005/00273
d D 6.12 86/04/30 17:54:25 bloom 26 25
c change the writes to a writev for tcp,  performance improves drasticly
e
s 00006/00004/00272
d D 6.11 86/04/11 17:42:24 kjd 25 23
c change retry loop to test before decrementing
e
s 00006/00002/00274
d R 6.11 86/04/11 11:16:01 kjd 24 23
c change retry loop to decrement after test
e
s 00026/00021/00250
d D 6.10 86/04/10 15:49:23 kjd 23 22
c Change timeouts, use perror to print error messages, lint clean up
e
s 00019/00003/00252
d D 6.9 86/04/10 09:05:10 bloom 22 21
c add entry point for closing tcp socket, a bit of lint work
e
s 00001/00000/00254
d D 6.8 86/03/17 10:02:34 bloom 21 20
c flag socket as closed if timed out
e
s 00001/00001/00253
d D 6.7 86/03/17 09:07:12 kjd 20 19
c move resolv.h to /usr/include
e
s 00001/00001/00253
d D 6.6 86/03/14 19:09:28 kjd 19 18
c change include types.h to param.h
e
s 00002/00002/00252
d D 6.5 86/03/09 20:36:32 donn 18 17
c added LIBC_SCCS condition for sccs ids
e
s 00026/00001/00228
d D 6.4 86/03/05 18:39:59 karels 17 16
c #ifdef the connect/send for UDP (for 4.3 only); indicate whether
c any server seemed to be present with distinguished error return
e
s 00007/00004/00222
d D 6.3 86/02/22 13:57:49 karels 16 15
c use connect on dg sockets to allow unreachable reporting;
c don't resend just because an old response came in.
e
s 00025/00012/00201
d D 6.2 86/02/22 11:16:46 bloom 15 14
c add support for holding a tcp connection open
e
s 00000/00000/00213
d D 6.1 85/10/31 15:29:52 kjd 14 13
c Freeze for November 1 network distribution
e
s 00001/00002/00212
d D 5.8 85/10/30 09:11:03 kjd 13 12
c change recvfrom to recv
e
s 00001/00001/00213
d D 5.7 85/10/25 18:14:02 kjd 12 11
c #ifdef openlog for 4.3  LOG_DAEMON isn't in 4.2
e
s 00029/00019/00185
d D 5.6 85/10/21 17:19:13 kjd 11 10
c have resolver query multiple servers
e
s 00027/00001/00177
d D 5.5 85/09/14 11:21:10 bloom 10 9
c add ifdef DEBUG around debugging code, res_init() now returns a value
e
s 00002/00002/00176
d D 5.4 85/07/29 18:03:58 kjd 9 8
c Move /usr/include/nameser.h & reslov.h to /usr/include/arpa
e
s 00001/00000/00177
d D 5.3 85/07/25 16:43:10 kjd 8 7
c If a server times out return errno ETIMEDOUT
e
s 00002/00000/00175
d D 5.2 85/07/16 11:07:50 kjd 7 5
c add missing close()
e
s 00000/00000/00175
d R 5.2 85/07/16 11:03:35 kjd 6 5
c add missing close()
e
s 00007/00006/00168
d D 5.1 85/05/30 12:07:27 dist 5 4
c Add copyright
e
s 00005/00000/00169
d D 4.4 85/04/01 15:11:27 ralph 4 3
c add copyright notice
e
s 00004/00006/00165
d D 4.3 85/03/28 09:26:14 ralph 3 2
c name changes and fix return value in res_init().
e
s 00000/00005/00171
d D 4.2 85/03/27 14:48:09 ralph 2 1
c delete debugging stuff.
e
s 00185/00000/00000
d D 4.1 85/03/01 10:42:21 ralph 1 0
c date and time created 85/03/01 10:42:21 by ralph
e
u
U
t
T
I 11
D 34

E 34
E 11
I 1
D 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

E 5
/*
I 4
D 5
 * Copyright (c) 1985 Regents of the University of California
 *	All Rights Reserved
E 5
I 5
 * Copyright (c) 1985 Regents of the University of California.
D 34
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 34
I 34
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 36
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 36
I 36
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
E 36
E 34
E 5
 */
I 5

D 18
#ifndef lint
E 18
I 18
#if defined(LIBC_SCCS) && !defined(lint)
E 18
static char sccsid[] = "%W% (Berkeley) %G%";
D 18
#endif not lint
E 18
I 18
D 34
#endif LIBC_SCCS and not lint
E 34
I 34
#endif /* LIBC_SCCS and not lint */
E 34
E 18
E 5

/*
E 4
 * Send query to name server and wait for reply.
 */

D 19
#include <sys/types.h>
E 19
I 19
#include <sys/param.h>
E 19
#include <sys/time.h>
#include <sys/socket.h>
I 26
#include <sys/uio.h>
E 26
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>
D 9
#include <nameser.h>
#include <resolv.h>
E 9
I 9
#include <arpa/nameser.h>
D 20
#include <arpa/resolv.h>
E 20
I 20
#include <resolv.h>
E 20
E 9

extern int errno;

I 22
static int s = -1;	/* socket used for communications */
I 32
static struct sockaddr no_addr;
E 32
I 30
  

#ifndef FD_SET
#define	NFDBITS		32
#define	FD_SETSIZE	32
#define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1 << ((n) % NFDBITS)))
#define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1 << ((n) % NFDBITS)))
#define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1 << ((n) % NFDBITS)))
#define FD_ZERO(p)	bzero((char *)(p), sizeof(*(p)))
#endif
E 30

E 22
I 15
#define KEEPOPEN (RES_USEVC|RES_STAYOPEN)

E 15
D 3
sendquery(buf, buflen, answer, anslen)
E 3
I 3
res_send(buf, buflen, answer, anslen)
E 3
	char *buf;
	int buflen;
	char *answer;
	int anslen;
{
	register int n;
D 11
	int s, retry, v_circuit, resplen;
E 11
I 11
D 15
	int s, retry, v_circuit, resplen, ns;
E 15
I 15
	int retry, v_circuit, resplen, ns;
D 22
	static int s = -1;
E 22
I 17
D 33
	int gotsomewhere = 0;
E 33
I 33
	int gotsomewhere = 0, connected = 0;
E 33
E 17
E 15
E 11
	u_short id, len;
	char *cp;
D 27
	int dsmask;
E 27
I 27
	fd_set dsmask;
E 27
	struct timeval timeout;
	HEADER *hp = (HEADER *) buf;
	HEADER *anhp = (HEADER *) answer;
I 26
	struct iovec iov[2];
I 28
	int terrno = ETIMEDOUT;
I 33
	char junk[512];
E 33
E 28
E 26

I 23
D 25
	extern u_short htons(), ntohs();

E 25
E 23
I 10
#ifdef DEBUG
E 10
	if (_res.options & RES_DEBUG) {
D 3
		printf("sendquery()\n");
E 3
I 3
		printf("res_send()\n");
E 3
		p_query(buf);
	}
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
D 3
	if (!(_res.options & RES_INIT)) {
		if (!res_init())
			return (-1);
	}
E 3
I 3
	if (!(_res.options & RES_INIT))
D 10
		res_init();
E 10
I 10
		if (res_init() == -1) {
			return(-1);
		}
E 10
E 3
D 15
	s = -1;
E 15
	v_circuit = (_res.options & RES_USEVC) || buflen > PACKETSZ;
	id = hp->id;
	/*
	 * Send request, RETRY times, or until successful
	 */
D 25
	for (retry = _res.retry; --retry >= 0; ) {
E 25
I 25
	for (retry = _res.retry; retry > 0; retry--) {
E 25
I 11
	   for (ns = 0; ns < _res.nscount; ns++) {
#ifdef DEBUG
		if (_res.options & RES_DEBUG)
			printf("Querying server (# %d) address = %s\n", ns+1,
D 23
			      inet_ntoa(_res.nsaddr_list[ns].sin_addr.s_addr)); 
E 23
I 23
D 33
			      inet_ntoa(_res.nsaddr_list[ns].sin_addr.s_addr));
E 33
I 33
			      inet_ntoa(_res.nsaddr_list[ns].sin_addr));
E 33
E 23
#endif DEBUG
E 11
		if (v_circuit) {
I 33
			int truncated = 0;

E 33
			/*
			 * Use virtual circuit.
			 */
D 15
			if (s < 0)
E 15
I 15
			if (s < 0) {
E 15
				s = socket(AF_INET, SOCK_STREAM, 0);
I 17
				if (s < 0) {
I 28
					terrno = errno;
E 28
#ifdef DEBUG
					if (_res.options & RES_DEBUG)
D 23
					    printf("socket failed %d\n",errno);
E 23
I 23
					    perror("socket failed");
E 23
#endif DEBUG
					continue;
				}
E 17
D 11
			if (connect(s, &_res.nsaddr, sizeof(_res.nsaddr)) < 0) {
E 11
I 11
D 15
			if (connect(s, &(_res.nsaddr_list[ns]), 
			   sizeof(struct sockaddr)) < 0) {
E 15
I 15
D 23
				if (connect(s, &(_res.nsaddr_list[ns]), 
E 23
I 23
				if (connect(s, &(_res.nsaddr_list[ns]),
E 23
				   sizeof(struct sockaddr)) < 0) {
I 28
					terrno = errno;
E 28
E 15
E 11
I 10
#ifdef DEBUG
E 10
D 15
				if (_res.options & RES_DEBUG)
					printf("connect failed %d\n", errno);
E 15
I 15
					if (_res.options & RES_DEBUG)
D 23
					    printf("connect failed %d\n",errno);
E 23
I 23
					    perror("connect failed");
E 23
E 15
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
D 15
				(void) close(s);
				s = -1;
				continue;
E 15
I 15
					(void) close(s);
					s = -1;
					continue;
				}
E 15
			}
			/*
			 * Send length & message
			 */
D 22
			len = htons(buflen);
E 22
I 22
			len = htons((u_short)buflen);
E 22
D 23
			if (write(s, &len, sizeof(len)) != sizeof(len) ||
D 11
			    write(s, buf, buflen) != buflen) {
E 11
I 11
				    write(s, buf, buflen) != buflen) {
E 23
I 23
D 26
			if (write(s, (char *)&len, sizeof(len)) != sizeof(len)||
			    write(s, buf, buflen) != buflen) {
E 26
I 26
			iov[0].iov_base = (caddr_t)&len;
			iov[0].iov_len = sizeof(len);
			iov[1].iov_base = buf;
			iov[1].iov_len = buflen;
			if (writev(s, iov, 2) != sizeof(len) + buflen) {
I 28
				terrno = errno;
E 28
E 26
E 23
E 11
I 10
#ifdef DEBUG
E 10
				if (_res.options & RES_DEBUG)
D 23
					printf("write failed %d\n", errno);
E 23
I 23
					perror("write failed");
E 23
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
				(void) close(s);
				s = -1;
				continue;
			}
			/*
			 * Receive length & response
			 */
			cp = answer;
			len = sizeof(short);
D 23
			while (len > 0 && (n = read(s, cp, len)) > 0) {
E 23
I 23
D 26
			while (len > 0 &&
E 26
I 26
			while (len != 0 &&
E 26
			    (n = read(s, (char *)cp, (int)len)) > 0) {
E 23
				cp += n;
				len -= n;
			}
			if (n <= 0) {
I 28
				terrno = errno;
E 28
I 10
#ifdef DEBUG
E 10
				if (_res.options & RES_DEBUG)
D 23
					printf("read failed %d\n", errno);
E 23
I 23
					perror("read failed");
E 23
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
				(void) close(s);
				s = -1;
				continue;
			}
			cp = answer;
D 22
			resplen = len = ntohs(*(short *)cp);
E 22
I 22
D 33
			resplen = len = ntohs(*(u_short *)cp);
E 33
I 33
			if ((resplen = ntohs(*(u_short *)cp)) > anslen) {
#ifdef DEBUG
				if (_res.options & RES_DEBUG)
					fprintf(stderr, "response truncated\n");
#endif DEBUG
				len = anslen;
				truncated = 1;
			} else
				len = resplen;
E 33
E 22
D 23
			while (len > 0 && (n = read(s, cp, len)) > 0) {
E 23
I 23
D 26
			while (len > 0 &&
E 26
I 26
			while (len != 0 &&
E 26
			   (n = read(s, (char *)cp, (int)len)) > 0) {
E 23
				cp += n;
				len -= n;
			}
			if (n <= 0) {
I 28
				terrno = errno;
E 28
I 10
#ifdef DEBUG
E 10
				if (_res.options & RES_DEBUG)
D 23
					printf("read failed %d\n", errno);
E 23
I 23
					perror("read failed");
E 23
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
				(void) close(s);
				s = -1;
				continue;
			}
I 33
			if (truncated) {
				/*
				 * Flush rest of answer
				 * so connection stays in synch.
				 */
				anhp->tc = 1;
				len = resplen - anslen;
				while (len != 0) {
					n = (len > sizeof(junk) ?
					    sizeof(junk) : len);
					if ((n = read(s, junk, n)) > 0)
						len -= n;
					else
						break;
				}
			}
E 33
		} else {
			/*
			 * Use datagrams.
			 */
			if (s < 0)
				s = socket(AF_INET, SOCK_DGRAM, 0);
I 17
#if	BSD >= 43
E 17
D 11
			if (sendto(s, buf, buflen, 0, &_res.nsaddr,
			    sizeof(_res.nsaddr)) != buflen) {
E 11
I 11
D 16
			if (sendto(s, buf, buflen, 0, &_res.nsaddr_list[ns],
			    sizeof(struct sockaddr)) != buflen) {
E 16
I 16
D 31
			if (connect(s, &_res.nsaddr_list[ns],
			    sizeof(struct sockaddr)) < 0 ||
			    send(s, buf, buflen, 0) != buflen) {
E 31
I 31
D 32
			if (_res.nscount == 1) {
E 32
I 32
			if (_res.nscount == 1 || retry == _res.retry) {
E 32
				/*
D 32
				 * Connect/Send is detrimental if you
				 * are going to poll more than one server
E 32
I 32
				 * Don't use connect if we might
				 * still receive a response
				 * from another server.
E 32
				 */
D 33
				if (connect(s, &_res.nsaddr_list[ns],
				    sizeof(struct sockaddr)) < 0 ||
				    send(s, buf, buflen, 0) != buflen) {
E 33
I 33
				if (connected == 0) {
					if (connect(s, &_res.nsaddr_list[ns],
					    sizeof(struct sockaddr)) < 0) {
E 33
E 31
E 16
E 11
I 10
#ifdef DEBUG
I 33
						if (_res.options & RES_DEBUG)
							perror("connect");
#endif DEBUG
						continue;
					}
					connected = 1;
				}
				if (send(s, buf, buflen, 0) != buflen) {
#ifdef DEBUG
E 33
E 10
D 11
				if (_res.options & RES_DEBUG)
E 11
I 11
D 23
				if (_res.options & RES_DEBUG) 
E 11
D 16
					printf("sendto errno = %d\n", errno);
E 16
I 16
					printf("connect/send errno = %d\n",
					    errno);
E 23
I 23
D 31
				if (_res.options & RES_DEBUG)
					perror("connect");
E 31
I 31
					if (_res.options & RES_DEBUG)
D 33
						perror("connect");
E 33
I 33
						perror("send");
E 33
E 31
E 23
E 16
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
I 17
D 31
				continue;
E 17
E 11
E 10
			}
I 17
#else BSD
E 31
I 31
					continue;
				}
D 35
			} else
E 35
I 35
			} else {
				/*
				 * Disconnect if we want to listen
				 * for responses from more than one server.
				 */
				if (connected) {
					(void) connect(s, &no_addr,
					    sizeof(no_addr));
					connected = 0;
				}
E 35
#endif BSD
E 31
D 35
			if (sendto(s, buf, buflen, 0, &_res.nsaddr_list[ns],
			    sizeof(struct sockaddr)) != buflen) {
E 35
I 35
				if (sendto(s, buf, buflen, 0,
				    &_res.nsaddr_list[ns],
				    sizeof(struct sockaddr)) != buflen) {
E 35
#ifdef DEBUG
D 23
				if (_res.options & RES_DEBUG) 
					printf("sendto errno = %d\n", errno);
E 23
I 23
D 35
				if (_res.options & RES_DEBUG)
					perror("sendto");
E 35
I 35
					if (_res.options & RES_DEBUG)
						perror("sendto");
E 35
E 23
#endif DEBUG
D 35
				continue;
E 35
I 35
					continue;
				}
#if	BSD >= 43
E 35
			}
I 35
#endif
E 35
D 31
#endif BSD
E 31
I 31

E 31
E 17
			/*
D 23
			 * Wait for reply 
E 23
I 23
			 * Wait for reply
E 23
			 */
D 11
			timeout.tv_sec = _res.retrans;
E 11
I 11
D 23
			timeout.tv_sec = 
				((_res.retrans * _res.retry) / _res.nscount);
E 23
I 23
			timeout.tv_sec = (_res.retrans << (_res.retry - retry))
				/ _res.nscount;
			if (timeout.tv_sec <= 0)
				timeout.tv_sec = 1;
E 23
E 11
			timeout.tv_usec = 0;
I 16
wait:
E 16
D 27
			dsmask = 1 << s;
E 27
I 27
			FD_ZERO(&dsmask);
			FD_SET(s, &dsmask);
E 27
D 26
			n = select(s+1, &dsmask, 0, 0, &timeout);
E 26
I 26
			n = select(s+1, &dsmask, (fd_set *)NULL,
				(fd_set *)NULL, &timeout);
E 26
			if (n < 0) {
I 10
#ifdef DEBUG
E 10
				if (_res.options & RES_DEBUG)
D 23
					printf("select errno = %d\n", errno);
E 23
I 23
					perror("select");
E 23
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
				continue;
			}
			if (n == 0) {
				/*
				 * timeout
				 */
I 10
#ifdef DEBUG
E 10
				if (_res.options & RES_DEBUG)
					printf("timeout\n");
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
I 32
D 35
				/*
				 * Disconnect if we want to listen
				 * for responses from more than one server.
				 */
D 33
				if (_res.nscount > 1 && retry == _res.retry)
E 33
I 33
				if (_res.nscount > 1 && connected) {
E 33
					(void) connect(s, &no_addr,
					    sizeof(no_addr));
I 33
					connected = 0;
				}
E 35
E 33
E 32
I 17
				gotsomewhere = 1;
E 17
E 11
E 10
				continue;
			}
D 13
			if ((resplen = recvfrom(s, answer, anslen,
D 12
			    0, 0, 0)) <= 0) {
E 12
I 12
			    0, (struct sockaddr *)0, (int *)0)) <= 0) {
E 13
I 13
			if ((resplen = recv(s, answer, anslen, 0)) <= 0) {
E 13
E 12
I 10
#ifdef DEBUG
E 10
				if (_res.options & RES_DEBUG)
D 23
					printf("recvfrom, errno=%d\n", errno);
E 23
I 23
					perror("recvfrom");
E 23
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
				continue;
			}
I 17
			gotsomewhere = 1;
E 17
			if (id != anhp->id) {
				/*
				 * response from old query, ignore it
				 */
I 10
#ifdef DEBUG
E 10
				if (_res.options & RES_DEBUG) {
D 2
					int f;

E 2
					printf("old answer:\n");
D 2
					f = creat("ro", 0644);
					write(f, answer, resplen);
					close(f);
E 2
					p_query(answer);
				}
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
D 16
				continue;
E 16
I 16
				goto wait;
E 16
			}
			if (!(_res.options & RES_IGNTC) && anhp->tc) {
				/*
				 * get rest of answer
				 */
I 10
#ifdef DEBUG
E 10
				if (_res.options & RES_DEBUG)
					printf("truncated answer\n");
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
				(void) close(s);
				s = -1;
D 25
				retry = _res.retry;
E 25
I 25
				/*
				 * retry decremented on continue
				 * to desired starting value
				 */
				retry = _res.retry + 1;
E 25
				v_circuit = 1;
				continue;
			}
		}
I 10
#ifdef DEBUG
E 10
		if (_res.options & RES_DEBUG) {
			printf("got answer:\n");
			p_query(answer);
		}
I 10
D 11
#endif
E 11
I 11
#endif DEBUG
E 11
E 10
I 7
D 15
		(void) close(s);
E 7
		return (resplen);
E 15
I 15
		/*
		 * We are going to assume that the first server is preferred
		 * over the rest (i.e. it is on the local machine) and only
		 * keep that one open.
		 */
D 35
		if ((_res.options & KEEPOPEN) == KEEPOPEN && ns == 0) {
			return (resplen);
		} else {
E 35
I 35
		if ((_res.options & KEEPOPEN) == 0 || ns != 0) {
E 35
			(void) close(s);
			s = -1;
D 35
			return (resplen);
E 35
		}
I 35
		return (resplen);
E 35
E 15
I 11
	   }
E 11
	}
I 7
D 28
	(void) close(s);
I 21
	s = -1;
E 21
I 8
D 17
	errno = ETIMEDOUT;
E 17
I 17
	if (v_circuit == 0 && gotsomewhere == 0)
		errno = ECONNREFUSED;
E 28
I 28
	if (s >= 0) {
		(void) close(s);
		s = -1;
	}
	if (v_circuit == 0)
		if (gotsomewhere == 0)
			errno = ECONNREFUSED;
		else
			errno = ETIMEDOUT;
E 28
	else
D 28
		errno = ETIMEDOUT;
E 28
I 28
		errno = terrno;
E 28
E 17
E 8
E 7
	return (-1);
I 22
}

/*
 * This routine is for closing the socket if a virtual circuit is used and
 * the program wants to close it.  This provides support for endhostent()
 * which expects to close the socket.
 *
 * This routine is not expected to be user visible.
 */
_res_close()
{
	if (s != -1) {
		(void) close(s);
		s = -1;
	}
E 22
}
E 1
