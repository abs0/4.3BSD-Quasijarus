/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Outbound TCP query service with queueing
 */

#ifndef lint
static char sccsid[] = "@(#)tcpqueue.c	1.6 (IFCTF) 2013/08/09";
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

static void
discard_canceled_queries(tqu)
	struct tcpqueue *tqu;
{
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
abort_handler(tqu)
	register struct tcpqueue *tqu;
{
	static struct linger rst_linger = {1, 0};
	register int s;

	s = tqu->tqu_socket;
	setsockopt(s, SOL_SOCKET, SO_LINGER, &rst_linger, sizeof rst_linger);
	close(s);
	FD_CLR(s, &select_for_read);
	FD_CLR(s, &select_for_write);
	signal_errors(tqu);
	free(tqu->tqu_rspbuf);
	free_tcpqueue(tqu);
}

void
tcpqueue_read_handler(tqu)
	register struct tcpqueue *tqu;
{
	register int cc;
	register struct tcpquery *qr;
	register struct timesched *t;

	cc = read(tqu->tqu_socket, tqu->tqu_io_ptr, tqu->tqu_io_left);
	if (cc <= 0) {
error:		timesched_discard(tqu->tqu_timeout);
		abort_handler(tqu);
		return;
	}
	tqu->tqu_io_ptr += cc;
	tqu->tqu_io_left -= cc;
	if (tqu->tqu_io_left)
		return;
	if (!tqu->tqu_rsplen) {
		cc = (tqu->tqu_rspbuf[0] << 8) | tqu->tqu_rspbuf[1];
		if (cc < sizeof(HEADER))
			goto error;
		tqu->tqu_rsplen = cc;
		tqu->tqu_io_ptr = tqu->tqu_rspbuf;
		tqu->tqu_io_left = cc;
		return;
	}
	/* success! */
	timesched_discard(tqu->tqu_timeout);
	FD_CLR(tqu->tqu_socket, &select_for_read);
	qr = tqu->tqu_queryhead;
	qr->tq_response_callbk(qr, tqu->tqu_rspbuf, tqu->tqu_rsplen);
	qr = qr->tq_next;
	free(tqu->tqu_queryhead);
	if (!qr) {
closeit:	close(tqu->tqu_socket);
		free(tqu->tqu_rspbuf);
		free_tcpqueue(tqu);
		return;
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
}

void
tcpqueue_write_handler(tqu)
	register struct tcpqueue *tqu;
{
	register int cc;

	cc = write(tqu->tqu_socket, tqu->tqu_io_ptr, tqu->tqu_io_left);
	if (cc <= 0) {
		timesched_discard(tqu->tqu_timeout);
		abort_handler(tqu);
		return;
	}
	tqu->tqu_io_ptr += cc;
	tqu->tqu_io_left -= cc;
	if (tqu->tqu_io_left)
		return;
	FD_CLR(tqu->tqu_socket, &select_for_write);
	FD_SET(tqu->tqu_socket, &select_for_read);
	tqu->tqu_io_ptr = tqu->tqu_rspbuf;
	tqu->tqu_io_left = 2;
	tqu->tqu_rsplen = 0;
}

void
tcpqueue_start_connect()
{
	register struct tcpqueue *tqu;
	register struct tcpquery *qr;
	register struct timesched *t;
	register int s;
	static int one = 1;

	tqu = tcpqueue_waitq;
	tcpqueue_waitq = tqu->tqu_next;
	discard_canceled_queries(tqu);
	if (!(qr = tqu->tqu_queryhead)) {
		free(tqu);
		return;
	}
	tqu->tqu_rspbuf = myalloc(65535);
	if (!tqu->tqu_rspbuf) {
mallocfail:	syslog(LOG_CRIT, "malloc failure prevents outbound TCP query");
errout:		signal_errors(tqu);
		free(tqu);
		return;
	}
	t = (struct timesched *) myalloc(sizeof(struct timesched));
	if (!t) {
		free(tqu->tqu_rspbuf);
		goto mallocfail;
	}
	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s < 0) {
		syslog(LOG_CRIT, "unable to create socket for TCP out: %m");
freeall_errout:	free(t);
		free(tqu->tqu_rspbuf);
		goto errout;
	}
	ioctl(s, FIONBIO, &one);
	if (connect(s, &tqu->tqu_sin, sizeof(struct sockaddr_in)) < 0 &&
	    errno != EINPROGRESS) {
		close(s);
		syslog(LOG_ERR, "outbound TCP connect: %m");
		goto freeall_errout;
	}
	tqu->tqu_socket = s;
	tqu->tqu_io_ptr = qr->tq_query;
	tqu->tqu_io_left = qr->tq_querylen;
	tqu->tqu_timeout = t;
	t->tim_time = current_time + outbound_tcp_timeout;
	t->tim_func = abort_handler;
	t->tim_arg = (caddr_t) tqu;
	time_schedule(t);
	select_desc[s].sel_read = tcpqueue_read_handler;
	select_desc[s].sel_write = tcpqueue_write_handler;
	select_desc[s].sel_opaque = (caddr_t) tqu;
	FD_SET(s, &select_for_write);
	if (s > select_max_fd)
		select_max_fd = s;
	tqu->tqu_next = tcpqueue_active;
	tcpqueue_active = tqu;
	tcpqueue_outstanding++;
}
