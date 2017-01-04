h42505
s 00003/00001/00259
d D 1.6 2013/08/09 06:42:40 msokolov 6 5
c memory leak in the corner case of tcpqueue_start_connect()
c when all queries for this destination have been canceled
e
s 00001/00001/00259
d D 1.5 2013/01/06 07:04:19 msokolov 5 4
c MSDNS => FalconDNS
e
s 00019/00006/00241
d D 1.4 2011/12/17 21:37:58 msokolov 4 3
c 
e
s 00001/00000/00246
d D 1.3 2011/12/17 09:03:20 msokolov 3 2
c missing return
e
s 00148/00070/00098
d D 1.2 2011/12/17 06:38:02 msokolov 2 1
c tcpqueue revamped
e
s 00168/00000/00000
d D 1.1 2011/12/14 22:33:35 msokolov 1 0
c date and time created 2011/12/14 22:33:35 by msokolov
e
u
U
t
T
I 1
/*
D 5
 * Michael Sokolov's Domain Name Server (MSDNS)
E 5
I 5
 * FalconDNS daemon by Michael Spacefalcon
E 5
 *
 * Outbound TCP query service with queueing
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "tcpqueue.h"
#include "globals.h"
#include "selectloop.h"

extern int errno;

extern u_char *myalloc();

I 2
tcpqueue_submit_query(newq)
	register struct tcpquery *newq;
{
	register struct tcpqueue *p, **pp;

	newq->tq_next = 0;
	for (p = tcpqueue_active; p; p = p->tqu_next)
		if (p->tqu_sin.sin_addr.s_addr == newq->tq_sin.sin_addr.s_addr
		    && p->tqu_sin.sin_port == newq->tq_sin.sin_port) {
			*p->tqu_querytail = newq;
			p->tqu_querytail = &newq->tq_next;
			return(0);
		}
	for (pp = &tcpqueue_waitq; p = *pp; pp = &p->tqu_next)
		if (p->tqu_sin.sin_addr.s_addr == newq->tq_sin.sin_addr.s_addr
		    && p->tqu_sin.sin_port == newq->tq_sin.sin_port) {
			*p->tqu_querytail = newq;
			p->tqu_querytail = &newq->tq_next;
			return(0);
		}
	p = (struct tcpqueue *) myalloc(sizeof(struct tcpqueue));
	if (!p)
		return(-1);
	bcopy(&newq->tq_sin, &p->tqu_sin, sizeof(struct sockaddr_in));
	p->tqu_next = 0;
	p->tqu_queryhead = newq;
	p->tqu_querytail = &newq->tq_next;
	*pp = p;
	return(0);
}

E 2
static void
D 2
abort_handler(tq)
	register struct tcpqueue *tq;
E 2
I 2
discard_canceled_queries(tqu)
	struct tcpqueue *tqu;
E 2
{
I 2
	register struct tcpquery *qr, *next;

	for (qr = tqu->tqu_queryhead; qr; qr = next) {
		if (qr->tq_userinfo)
			break;
		next = qr->tq_next;
		free(qr);
	}
	tqu->tqu_queryhead = qr;
}

static void
signal_errors(tqu)
	struct tcpqueue *tqu;
{
	register struct tcpquery *qr, *next;

	for (qr = tqu->tqu_queryhead; qr; qr = next) {
		next = qr->tq_next;
		qr->tq_error_callbk(qr);
		free(qr);
	}
}

static void
I 4
free_tcpqueue(tbdel)
	register struct tcpqueue *tbdel;
{
	register struct tcpqueue *p, **pp;

	for (pp = &tcpqueue_active; p = *pp; pp = &p->tqu_next)
		if (p == tbdel) {
			*pp = p->tqu_next;
			free(tbdel);
			tcpqueue_outstanding--;
			return;
		}
	syslog(LOG_CRIT, "BUG: tcpqueue to be freed isn't in tcpqueue_active");
	abort();
}

static void
E 4
abort_handler(tqu)
	register struct tcpqueue *tqu;
{
E 2
	static struct linger rst_linger = {1, 0};
	register int s;

D 2
	s = tq->tq_socket;
E 2
I 2
	s = tqu->tqu_socket;
E 2
	setsockopt(s, SOL_SOCKET, SO_LINGER, &rst_linger, sizeof rst_linger);
	close(s);
	FD_CLR(s, &select_for_read);
	FD_CLR(s, &select_for_write);
D 2
	tq->tq_error_callbk(tq);
	free(tq->tq_rspbuf);
	free(tq);
E 2
I 2
	signal_errors(tqu);
	free(tqu->tqu_rspbuf);
D 4
	tcpqueue_active = tqu->tqu_next;
	free(tqu);
E 2
	tcpqueue_outstanding--;
E 4
I 4
	free_tcpqueue(tqu);
E 4
}

void
D 2
tcpqueue_read_handler(tq)
	register struct tcpqueue *tq;
E 2
I 2
tcpqueue_read_handler(tqu)
	register struct tcpqueue *tqu;
E 2
{
	register int cc;
I 2
	register struct tcpquery *qr;
	register struct timesched *t;
E 2

D 2
	cc = read(tq->tq_socket, tq->tq_io_ptr, tq->tq_io_left);
E 2
I 2
	cc = read(tqu->tqu_socket, tqu->tqu_io_ptr, tqu->tqu_io_left);
E 2
	if (cc <= 0) {
D 2
error:		timesched_discard(tq->tq_timeout);
		abort_handler(tq);
E 2
I 2
error:		timesched_discard(tqu->tqu_timeout);
		abort_handler(tqu);
E 2
		return;
	}
D 2
	tq->tq_io_ptr += cc;
	tq->tq_io_left -= cc;
	if (tq->tq_io_left)
E 2
I 2
	tqu->tqu_io_ptr += cc;
	tqu->tqu_io_left -= cc;
	if (tqu->tqu_io_left)
E 2
		return;
D 2
	if (!tq->tq_rsplen) {
		cc = (tq->tq_rspbuf[0] << 8) | tq->tq_rspbuf[1];
E 2
I 2
	if (!tqu->tqu_rsplen) {
		cc = (tqu->tqu_rspbuf[0] << 8) | tqu->tqu_rspbuf[1];
E 2
		if (cc < sizeof(HEADER))
			goto error;
D 2
		tq->tq_rsplen = cc;
		tq->tq_io_ptr = tq->tq_rspbuf;
		tq->tq_io_left = cc;
E 2
I 2
		tqu->tqu_rsplen = cc;
		tqu->tqu_io_ptr = tqu->tqu_rspbuf;
		tqu->tqu_io_left = cc;
E 2
		return;
	}
	/* success! */
D 2
	timesched_discard(tq->tq_timeout);
	close(tq->tq_socket);
	FD_CLR(tq->tq_socket, &select_for_read);
	tq->tq_response_callbk(tq);
	free(tq->tq_rspbuf);
	free(tq);
	tcpqueue_outstanding--;
E 2
I 2
	timesched_discard(tqu->tqu_timeout);
	FD_CLR(tqu->tqu_socket, &select_for_read);
	qr = tqu->tqu_queryhead;
	qr->tq_response_callbk(qr, tqu->tqu_rspbuf, tqu->tqu_rsplen);
	qr = qr->tq_next;
	free(tqu->tqu_queryhead);
	if (!qr) {
closeit:	close(tqu->tqu_socket);
		free(tqu->tqu_rspbuf);
D 4
		tcpqueue_active = tqu->tqu_next;
		free(tqu);
		tcpqueue_outstanding--;
E 4
I 4
		free_tcpqueue(tqu);
E 4
I 3
		return;
E 3
	}
	tqu->tqu_queryhead = qr;
	discard_canceled_queries(tqu);
	qr = tqu->tqu_queryhead;
	if (!qr)
		goto closeit;
	t = (struct timesched *) myalloc(sizeof(struct timesched));
	if (!t) {
		syslog(LOG_CRIT, "malloc failure prevents outbound TCP query");
		signal_errors(tqu);
		goto closeit;
	}
	tqu->tqu_io_ptr = qr->tq_query;
	tqu->tqu_io_left = qr->tq_querylen;
	tqu->tqu_timeout = t;
	t->tim_time = current_time + outbound_tcp_timeout;
	t->tim_func = abort_handler;
	t->tim_arg = (caddr_t) tqu;
	time_schedule(t);
	FD_SET(tqu->tqu_socket, &select_for_write);
E 2
}

void
D 2
tcpqueue_write_handler(tq)
	register struct tcpqueue *tq;
E 2
I 2
tcpqueue_write_handler(tqu)
	register struct tcpqueue *tqu;
E 2
{
	register int cc;

D 2
	cc = write(tq->tq_socket, tq->tq_io_ptr, tq->tq_io_left);
E 2
I 2
	cc = write(tqu->tqu_socket, tqu->tqu_io_ptr, tqu->tqu_io_left);
E 2
	if (cc <= 0) {
D 2
		timesched_discard(tq->tq_timeout);
		abort_handler(tq);
E 2
I 2
		timesched_discard(tqu->tqu_timeout);
		abort_handler(tqu);
E 2
		return;
	}
D 2
	tq->tq_io_ptr += cc;
	tq->tq_io_left -= cc;
	if (tq->tq_io_left)
E 2
I 2
	tqu->tqu_io_ptr += cc;
	tqu->tqu_io_left -= cc;
	if (tqu->tqu_io_left)
E 2
		return;
D 2
	FD_CLR(tq->tq_socket, &select_for_write);
	select_desc[tq->tq_socket].sel_read = tcpqueue_read_handler;
	FD_SET(tq->tq_socket, &select_for_read);
	tq->tq_io_ptr = tq->tq_rspbuf;
	tq->tq_io_left = 2;
	tq->tq_rsplen = 0;
E 2
I 2
	FD_CLR(tqu->tqu_socket, &select_for_write);
	FD_SET(tqu->tqu_socket, &select_for_read);
	tqu->tqu_io_ptr = tqu->tqu_rspbuf;
	tqu->tqu_io_left = 2;
	tqu->tqu_rsplen = 0;
E 2
}

void
tcpqueue_start_connect()
{
D 2
	register struct tcpqueue *tq;
E 2
I 2
	register struct tcpqueue *tqu;
	register struct tcpquery *qr;
E 2
	register struct timesched *t;
	register int s;
	static int one = 1;

D 2
	tq = tcpqueue_head;
	tcpqueue_head = tq->tq_next;
	if (!tcpqueue_head)
		tcpqueue_tail = &tcpqueue_head;
	if (!tq->tq_userinfo) {
		free(tq);
E 2
I 2
	tqu = tcpqueue_waitq;
	tcpqueue_waitq = tqu->tqu_next;
	discard_canceled_queries(tqu);
D 6
	if (!(qr = tqu->tqu_queryhead))
E 6
I 6
	if (!(qr = tqu->tqu_queryhead)) {
		free(tqu);
E 6
E 2
		return;
I 6
	}
E 6
D 2
	}
	tq->tq_rspbuf = myalloc(65535);
	if (!tq->tq_rspbuf) {
E 2
I 2
	tqu->tqu_rspbuf = myalloc(65535);
	if (!tqu->tqu_rspbuf) {
E 2
mallocfail:	syslog(LOG_CRIT, "malloc failure prevents outbound TCP query");
D 2
errout:		tq->tq_error_callbk(tq);
		free(tq);
E 2
I 2
errout:		signal_errors(tqu);
		free(tqu);
E 2
		return;
	}
	t = (struct timesched *) myalloc(sizeof(struct timesched));
	if (!t) {
D 2
		free(tq->tq_rspbuf);
E 2
I 2
		free(tqu->tqu_rspbuf);
E 2
		goto mallocfail;
	}
	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s < 0) {
		syslog(LOG_CRIT, "unable to create socket for TCP out: %m");
freeall_errout:	free(t);
D 2
		free(tq->tq_rspbuf);
E 2
I 2
		free(tqu->tqu_rspbuf);
E 2
		goto errout;
	}
	ioctl(s, FIONBIO, &one);
D 2
	if (connect(s, &tq->tq_sin, sizeof(struct sockaddr_in)) < 0 &&
E 2
I 2
	if (connect(s, &tqu->tqu_sin, sizeof(struct sockaddr_in)) < 0 &&
E 2
	    errno != EINPROGRESS) {
		close(s);
		syslog(LOG_ERR, "outbound TCP connect: %m");
		goto freeall_errout;
	}
D 2
	tq->tq_socket = s;
	tq->tq_io_ptr = tq->tq_query;
	tq->tq_io_left = tq->tq_querylen;
	tq->tq_timeout = t;
E 2
I 2
	tqu->tqu_socket = s;
	tqu->tqu_io_ptr = qr->tq_query;
	tqu->tqu_io_left = qr->tq_querylen;
	tqu->tqu_timeout = t;
E 2
	t->tim_time = current_time + outbound_tcp_timeout;
	t->tim_func = abort_handler;
D 2
	t->tim_arg = (caddr_t) tq;
E 2
I 2
	t->tim_arg = (caddr_t) tqu;
E 2
	time_schedule(t);
I 2
	select_desc[s].sel_read = tcpqueue_read_handler;
E 2
	select_desc[s].sel_write = tcpqueue_write_handler;
D 2
	select_desc[s].sel_opaque = (caddr_t) tq;
E 2
I 2
	select_desc[s].sel_opaque = (caddr_t) tqu;
E 2
	FD_SET(s, &select_for_write);
	if (s > select_max_fd)
		select_max_fd = s;
I 2
	tqu->tqu_next = tcpqueue_active;
	tcpqueue_active = tqu;
E 2
	tcpqueue_outstanding++;
D 2
}

tcpqueue_submit(tq)
	register struct tcpqueue *tq;
{
	tq->tq_next = 0;
	*tcpqueue_tail = tq;
	tcpqueue_tail = &tq->tq_next;
	return(0);
E 2
}
E 1
