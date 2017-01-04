/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * TCP query server
 */

#ifndef lint
static char sccsid[] = "@(#)tcpserv.c	1.10 (IFCTF) 2013/08/10";
#endif

#include <sys/types.h>
#include <machine/endian.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "query.h"
#include "globals.h"
#include "selectloop.h"
#include "acl.h"

extern char *myalloc();
extern struct query *alloc_query_struct();

struct tcpserv_instance {
	int	socket;
	struct	sockaddr_in addr;
};

struct tcpconn {
	int	socket;
	int	aclperm;
	struct	query *rxquery;
	int	rx_got_length;
	u_char	*rdptr;
	int	rdleft;
	u_char	rxlenbuf[2];
	int	queries_in_process;
	struct	query *respq_head;
	struct	query **respq_tail;
	u_char	*wrptr;
	int	wrleft;
	struct	timesched *timeout;
};

void tcpserv_query_complete();
void tcpserv_query_complete_dupwrap();

static void
close_socket(s, rst)
	register int s;
	int rst;
{
	static struct linger rst_linger = {1, 0};

	if (rst)
		setsockopt(s, SOL_SOCKET, SO_LINGER, &rst_linger,
			   sizeof rst_linger);
	close(s);
	FD_CLR(s, &select_for_read);
	FD_CLR(s, &select_for_write);
}

static void
tcpconn_error(tc)
	register struct tcpconn *tc;
{
	register struct query *q;

	if (tc->timeout)
		timesched_discard(tc->timeout);
	close_socket(tc->socket, 1);
	tcpserv_active_conn--;
	if (q = tc->rxquery)
		free_query_struct(q);
	for (q = tc->respq_head; q; q = q->q_next) {
		if (q->q_state == QSTATE_RSPOUT_AXFR)
			axfrserv_release(q);
		free_query_struct(q);
	}
	if (tc->queries_in_process)
		tc->socket = 0;
	else
		free(tc);
}

static void
timeout_handler(tc)
	register struct tcpconn *tc;
{
	tc->timeout = 0;
	tcpconn_error(tc);
}

static void
read_init(tc)
	register struct tcpconn *tc;
{
	tc->rx_got_length = 0;
	tc->rdptr = tc->rxlenbuf;
	tc->rdleft = 2;
}

void
tcpserv_read_handler(tc)
	register struct tcpconn *tc;
{
	register struct query *q;
	register int cc;

	q = tc->rxquery;
	cc = read(tc->socket, tc->rdptr, tc->rdleft);
	if (cc == 0 && !tc->rx_got_length && tc->rdleft == 2 &&
	    !tc->respq_head) {
		/* clean closure */
		if (tc->timeout)
			timesched_discard(tc->timeout);
		close_socket(tc->socket, 0);
		tcpserv_active_conn--;
		if (q)
			free_query_struct(q);
		if (tc->queries_in_process)
			tc->socket = 0;
		else
			free(tc);
		return;
	} else if (cc <= 0) {
		tcpconn_error(tc);
		return;
	}
	tc->rdptr += cc;
	tc->rdleft -= cc;
	if (tc->rdleft)
		return;
	if (tc->rx_got_length) {
		if (tc->timeout && !tc->respq_head) {
			timesched_discard(tc->timeout);
			tc->timeout = 0;
		}
		read_init(tc);
		tc->rxquery = 0;
		tc->queries_in_process++;
		q->q_flags = QFLAGS_TCPSERV;
		if (handle_query_initial(q) < 0) {
			q->q_state = QSTATE_RSPOUT;
			tcpserv_query_complete(q);
		} else if (q->q_type == T_AXFR) {
			axfrserv_start(q);
			tcpserv_query_complete(q);
		} else {
			q->q_callwhendone = tcpserv_query_complete_dupwrap;
			stage_query(q);
		}
		return;
	}
	cc = (tc->rxlenbuf[0] << 8) | tc->rxlenbuf[1];
	if (cc < sizeof(HEADER)) {
		tcpconn_error(tc);
		return;
	}
	if (!q) {
		q = alloc_query_struct(65537);
		if (!q) {
			syslog(LOG_ERR, "no memory for incoming TCP query");
			tcpconn_error(tc);
			return;
		}
		tc->rxquery = q;
		q->q_parent = (caddr_t) tc;
		q->q_msg = (u_char *)q + sizeof(struct query) + 2;
		q->q_msg_maxlen = 65535;
		q->q_aclperm = tc->aclperm;
	}
	q->q_msglen = cc;
	tc->rdptr = q->q_msg;
	tc->rdleft = cc;
	tc->rx_got_length = 1;
}

void
tcpserv_start_output(tc)
	register struct tcpconn *tc;
{
	register struct query *q;
	register struct timesched *t;

	q = tc->respq_head;
	if (q) {
		tc->wrptr = q->q_msg - 2;
		tc->wrleft = q->q_msglen + 2;
		*(u_short *)tc->wrptr = htons(q->q_msglen);
		if (tcpserv_send_timeout &&
		    (t = (struct timesched *)
				myalloc(sizeof(struct timesched)))) {
			t->tim_time = current_time + tcpserv_send_timeout;
			t->tim_func = timeout_handler;
			t->tim_arg = (caddr_t) tc;
			time_schedule(t);
			tc->timeout = t;
		}
		FD_SET(tc->socket, &select_for_write);
	} else {
		FD_CLR(tc->socket, &select_for_write);
		if (tc->queries_in_process)
			return;
		if (!tcpserv_max_idle)
			return;
		if (tc->aclperm & ACL_ALLOW_IDLE)
			return;
		t = (struct timesched *) myalloc(sizeof(struct timesched));
		if (!t)
			return;
		t->tim_time = current_time + tcpserv_max_idle;
		t->tim_func = timeout_handler;
		t->tim_arg = (caddr_t) tc;
		time_schedule(t);
		tc->timeout = t;
	}
}

void
tcpserv_write_handler(tc)
	register struct tcpconn *tc;
{
	register int cc;
	register struct query *q;

	cc = write(tc->socket, tc->wrptr, tc->wrleft);
	if (cc <= 0) {
		tcpconn_error(tc);
		return;
	}
	tc->wrptr += cc;
	tc->wrleft -= cc;
	if (tc->wrleft)
		return;
	if (tc->timeout) {
		timesched_discard(tc->timeout);
		tc->timeout = 0;
	}
	q = tc->respq_head;
	tc->respq_head = q->q_next;
	if (!tc->respq_head)
		tc->respq_tail = &tc->respq_head;
	if (q->q_state == QSTATE_RSPOUT_AXFR) {
		axfrserv_continue(q);
		q->q_next = 0;
		*tc->respq_tail = q;
		tc->respq_tail = &q->q_next;
	} else if (!tc->rxquery)
		tc->rxquery = q;
	else
		free_query_struct(q);
	tcpserv_start_output(tc);
}

void
tcpserv_query_complete(q)
	register struct query *q;
{
	register struct tcpconn *tc;

	tc = (struct tcpconn *) q->q_parent;
	tc->queries_in_process--;
	if (tc->socket <= 0) {
		if (q->q_state == QSTATE_RSPOUT_AXFR)
			axfrserv_release(q);
		free_query_struct(q);
		if (!tc->queries_in_process)
			free(tc);
		return;
	}
	q->q_next = 0;
	*tc->respq_tail = q;
	tc->respq_tail = &q->q_next;
	if (q == tc->respq_head)
		tcpserv_start_output(tc);
}

void
tcpserv_complete_duplicates(orq)
	struct query *orq;
{
	register int msglen = orq->q_msglen;
	register u_char *srcptr = orq->q_msg + 2;
	register struct query *dq, *nq;

	for (dq = orq->q_nextdup; dq; dq = nq) {
		dq->q_msglen = msglen;
		bcopy(srcptr, dq->q_msg + 2, msglen - 2);
		nq = dq->q_nextdup;
		tcpserv_query_complete(dq);
	}
}

void
tcpserv_query_complete_dupwrap(q)
	register struct query *q;
{
	if (q->q_nextdup)
		tcpserv_complete_duplicates(q);
	tcpserv_query_complete(q);
}

void
tcpserv_acceptor(ti)
	struct tcpserv_instance *ti;
{
	struct sockaddr_in from;
	int fromlen;
	register int s;
	register struct aclentry *acl;
	register struct tcpconn *tc;
	register struct timesched *t;
	static int one = 1;

	fromlen = sizeof(struct sockaddr_in);
	s = accept(ti->socket, &from, &fromlen);
	if (s < 0) {
		syslog(LOG_CRIT, "tcpserv accept: %m");
		return;
	}
	if (tcpserv_active_conn >= tcpserv_max_conn) {
		syslog(LOG_WARNING,
			"refusing TCP connection: %d already active",
			tcpserv_active_conn);
		close_socket(s, 1);
		return;
	}
	for (acl = tcpserv_acl; ; acl++)
		if ((from.sin_addr.s_addr & acl->acl_ipmask) == acl->acl_ipbase)
			break;
	if (!(acl->acl_perm & ACL_ALLOW_QUERY)) {
		close_socket(s, 1);
		return;
	}
	tc = (struct tcpconn *) myalloc(sizeof(struct tcpconn));
	if (!tc) {
		syslog(LOG_ERR,
			"refusing TCP connection: no memory for state struct");
		close_socket(s, 1);
		return;
	}
	tcpserv_active_conn++;
	tc->socket = s;
	tc->aclperm = acl->acl_perm;
	tc->rxquery = 0;
	tc->queries_in_process = 0;
	tc->respq_head = 0;
	tc->respq_tail = &tc->respq_head;
	read_init(tc);
	ioctl(s, FIONBIO, &one);
	setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &one, sizeof(int));
	select_desc[s].sel_read = tcpserv_read_handler;
	select_desc[s].sel_write = tcpserv_write_handler;
	select_desc[s].sel_opaque = (caddr_t) tc;
	if (s > select_max_fd)
		select_max_fd = s;
	FD_SET(s, &select_for_read);
	if (tcpserv_max_idle && !(tc->aclperm & ACL_ALLOW_IDLE) &&
	    (t = (struct timesched *) myalloc(sizeof(struct timesched)))) {
		t->tim_time = current_time + tcpserv_max_idle;
		t->tim_func = timeout_handler;
		t->tim_arg = (caddr_t) tc;
		time_schedule(t);
		tc->timeout = t;
	} else
		tc->timeout = 0;
}

void
setup_tcpserv(addr, port)
	u_long addr;	/* network b.o. */
	int port;	/* host b.o. */
{
	static int one = 1;
	register struct tcpserv_instance *ti;

	ti = (struct tcpserv_instance *)
		myalloc(sizeof(struct tcpserv_instance));
	if (!ti) {
		perror("tcpserv instance malloc");
		exit(1);
	}
	ti->addr.sin_family = AF_INET;
	ti->addr.sin_addr.s_addr = addr;
	ti->addr.sin_port = htons(port);
	ti->socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ti->socket < 0) {
		syslog(LOG_CRIT, "creating tcpserv socket: %m");
		perror("tcpserv socket");
		exit(1);
	}
	if (bind(ti->socket, &ti->addr, sizeof(struct sockaddr_in)) < 0) {
		syslog(LOG_ERR, "bind tcpserv socket to port %d: %m", port);
		perror("bind tcpserv socket");
		exit(1);
	}
	if (listen(ti->socket, SOMAXCONN) < 0) {
		syslog(LOG_CRIT, "tcpserv listen syscall: %m");
		perror("tcpserv listen syscall");
		exit(1);
	}
	ioctl(ti->socket, FIONBIO, &one);
	select_desc[ti->socket].sel_read = tcpserv_acceptor;
	select_desc[ti->socket].sel_opaque = (caddr_t) ti;
	FD_SET(ti->socket, &select_for_read);
	if (ti->socket > select_max_fd)
		select_max_fd = ti->socket;
}
