h08220
s 00001/00001/00410
d D 1.10 2013/08/10 07:11:47 msokolov 10 9
c external queries bypass the queue
e
s 00001/00000/00410
d D 1.9 2013/01/15 04:32:46 msokolov 9 8
c brown paper bag
e
s 00027/00001/00383
d D 1.8 2013/01/13 15:31:48 msokolov 8 7
c duplicate query suppression implemented
e
s 00194/00114/00190
d D 1.7 2013/01/07 20:17:06 msokolov 7 6
c tcpserv revamped for multiple simultaneous queries on one connection
e
s 00001/00001/00303
d D 1.6 2013/01/06 07:04:09 msokolov 6 5
c MSDNS => FalconDNS
e
s 00001/00000/00303
d D 1.5 2011/12/14 19:26:49 msokolov 5 4
c enable SO_KEEPALIVE
e
s 00011/00002/00292
d D 1.4 2011/12/14 19:21:12 msokolov 4 3
c write timeout implemented
e
s 00019/00002/00275
d D 1.3 2011/12/14 19:16:57 msokolov 3 2
c read timeout implemented
e
s 00021/00004/00256
d D 1.2 2011/12/14 00:56:10 msokolov 2 1
c AXFR service hooked in
e
s 00260/00000/00000
d D 1.1 2011/12/13 23:01:06 msokolov 1 0
c date and time created 2011/12/13 23:01:06 by msokolov
e
u
U
t
T
I 1
/*
D 6
 * Michael Sokolov's Domain Name Server (MSDNS)
E 6
I 6
 * FalconDNS daemon by Michael Spacefalcon
E 6
 *
 * TCP query server
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
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

I 7
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

E 7
void tcpserv_query_complete();
I 8
void tcpserv_query_complete_dupwrap();
E 8
D 7
void tcpserv_start_output();
E 7

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
D 7
close_query(q, rst)
	register struct query *q;
	int rst;
E 7
I 7
tcpconn_error(tc)
	register struct tcpconn *tc;
E 7
{
D 7
	if (q->q_timeout)
		timesched_discard(q->q_timeout);
	close_socket(q->q_socket, rst);
I 2
	if (q->q_state == QSTATE_RSPOUT_AXFR)
		axfrserv_release(q);
E 2
	free_query_struct(q);
E 7
I 7
	register struct query *q;

	if (tc->timeout)
		timesched_discard(tc->timeout);
	close_socket(tc->socket, 1);
E 7
	tcpserv_active_conn--;
I 7
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
E 7
}

I 3
static void
D 7
timeout_handler(q)
	register struct query *q;
E 7
I 7
timeout_handler(tc)
	register struct tcpconn *tc;
E 7
{
D 7
	q->q_timeout = 0;
	close_query(q, 1);
E 7
I 7
	tc->timeout = 0;
	tcpconn_error(tc);
E 7
}

I 7
static void
read_init(tc)
	register struct tcpconn *tc;
{
	tc->rx_got_length = 0;
	tc->rdptr = tc->rxlenbuf;
	tc->rdleft = 2;
}

E 7
E 3
void
D 7
tcpserv_read_handler(q)
	register struct query *q;
E 7
I 7
tcpserv_read_handler(tc)
	register struct tcpconn *tc;
E 7
{
I 7
	register struct query *q;
E 7
	register int cc;

D 7
	cc = read(q->q_socket, q->q_msgptr, q->q_msg_remain);
	if (cc == 0 && q->q_state == QSTATE_TCPRDLEN && q->q_msg_remain == 2) {
		close_query(q, 0);
E 7
I 7
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
E 7
		return;
	} else if (cc <= 0) {
D 7
		close_query(q, 1);
E 7
I 7
		tcpconn_error(tc);
E 7
		return;
	}
D 7
	q->q_msgptr += cc;
	q->q_msg_remain -= cc;
	if (q->q_msg_remain)
E 7
I 7
	tc->rdptr += cc;
	tc->rdleft -= cc;
	if (tc->rdleft)
E 7
		return;
D 7
	switch (q->q_state) {
	case QSTATE_TCPRDLEN:
		cc = (q->q_msg[0] << 8) | q->q_msg[1];
		if (cc < sizeof(HEADER)) {
			close_query(q, 1);
			return;
E 7
I 7
	if (tc->rx_got_length) {
		if (tc->timeout && !tc->respq_head) {
			timesched_discard(tc->timeout);
			tc->timeout = 0;
E 7
		}
D 7
		q->q_msglen = cc;
		q->q_state = QSTATE_TCPRDMSG;
		q->q_msgptr = q->q_msg;
		q->q_msg_remain = cc;
		return;
	case QSTATE_TCPRDMSG:
		FD_CLR(q->q_socket, &select_for_read);
		if (q->q_timeout) {
			timesched_discard(q->q_timeout);
			q->q_timeout = 0;
		}
E 7
I 7
		read_init(tc);
		tc->rxquery = 0;
		tc->queries_in_process++;
E 7
		q->q_flags = QFLAGS_TCPSERV;
		if (handle_query_initial(q) < 0) {
			q->q_state = QSTATE_RSPOUT;
D 7
			tcpserv_start_output(q);
E 7
I 7
			tcpserv_query_complete(q);
E 7
D 2
			return;
E 2
I 2
		} else if (q->q_type == T_AXFR) {
			axfrserv_start(q);
D 7
			tcpserv_start_output(q);
E 7
I 7
			tcpserv_query_complete(q);
E 7
		} else {
D 8
			q->q_callwhendone = tcpserv_query_complete;
E 8
I 8
			q->q_callwhendone = tcpserv_query_complete_dupwrap;
E 8
D 10
			put_query_on_queue(q, QSTATE_STAGE);
E 10
I 10
			stage_query(q);
E 10
E 2
		}
I 9
		return;
E 9
I 7
	}
	cc = (tc->rxlenbuf[0] << 8) | tc->rxlenbuf[1];
	if (cc < sizeof(HEADER)) {
		tcpconn_error(tc);
E 7
D 2
		q->q_callwhendone = tcpserv_query_complete;
		put_query_on_queue(q, QSTATE_STAGE);
E 2
		return;
D 7
	default:
		syslog(LOG_CRIT, "BUG: bad state %d in tcpserv_read_handler()",
			q->q_state);
		abort();
E 7
	}
I 7
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
E 7
}

void
D 7
tcpserv_start_read(q)
	register struct query *q;
E 7
I 7
tcpserv_start_output(tc)
	register struct tcpconn *tc;
E 7
{
I 7
	register struct query *q;
E 7
I 3
	register struct timesched *t;

E 3
D 7
	q->q_state = QSTATE_TCPRDLEN;
	q->q_msgptr = q->q_msg;
	q->q_msg_remain = 2;
D 3
	/* timeout remains to be implemented */
	q->q_timeout = 0;
E 3
I 3
	if (tcpserv_max_idle && !(q->q_aclperm & ACL_ALLOW_IDLE) &&
	    (t = (struct timesched *) myalloc(sizeof(struct timesched)))) {
E 7
I 7
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
E 7
		t->tim_time = current_time + tcpserv_max_idle;
		t->tim_func = timeout_handler;
D 7
		t->tim_arg = (caddr_t) q;
E 7
I 7
		t->tim_arg = (caddr_t) tc;
E 7
		time_schedule(t);
D 7
		q->q_timeout = t;
	} else
		q->q_timeout = 0;
E 3
	FD_SET(q->q_socket, &select_for_read);
E 7
I 7
		tc->timeout = t;
	}
E 7
}

void
D 7
tcpserv_write_handler(q)
	register struct query *q;
E 7
I 7
tcpserv_write_handler(tc)
	register struct tcpconn *tc;
E 7
{
	register int cc;
I 7
	register struct query *q;
E 7

D 7
	cc = write(q->q_socket, q->q_msgptr, q->q_msg_remain);
E 7
I 7
	cc = write(tc->socket, tc->wrptr, tc->wrleft);
E 7
	if (cc <= 0) {
D 7
		close_query(q, 1);
E 7
I 7
		tcpconn_error(tc);
E 7
		return;
	}
D 7
	q->q_msgptr += cc;
	q->q_msg_remain -= cc;
	if (q->q_msg_remain)
E 7
I 7
	tc->wrptr += cc;
	tc->wrleft -= cc;
	if (tc->wrleft)
E 7
		return;
D 7
	FD_CLR(q->q_socket, &select_for_write);
	if (q->q_timeout) {
		timesched_discard(q->q_timeout);
		q->q_timeout = 0;
E 7
I 7
	if (tc->timeout) {
		timesched_discard(tc->timeout);
		tc->timeout = 0;
E 7
	}
D 2
	tcpserv_start_read();
E 2
I 2
D 7
	switch (q->q_state) {
	case QSTATE_RSPOUT:
		tcpserv_start_read(q);
		return;
	case QSTATE_RSPOUT_AXFR:
E 7
I 7
	q = tc->respq_head;
	tc->respq_head = q->q_next;
	if (!tc->respq_head)
		tc->respq_tail = &tc->respq_head;
	if (q->q_state == QSTATE_RSPOUT_AXFR) {
E 7
		axfrserv_continue(q);
D 7
		tcpserv_start_output(q);
		return;
	default:
		syslog(LOG_CRIT, "BUG: bad state %d in tcpserv_write_handler()",
			q->q_state);
		abort();
	}
E 7
I 7
		q->q_next = 0;
		*tc->respq_tail = q;
		tc->respq_tail = &q->q_next;
	} else if (!tc->rxquery)
		tc->rxquery = q;
	else
		free_query_struct(q);
	tcpserv_start_output(tc);
E 7
E 2
}

void
tcpserv_query_complete(q)
	register struct query *q;
{
D 7
	query_response_wrapup(q);
	q->q_state = QSTATE_RSPOUT;
	tcpserv_start_output(q);
}
E 7
I 7
	register struct tcpconn *tc;
E 7

D 7
void
tcpserv_start_output(q)
	register struct query *q;
{
I 4
	register struct timesched *t;

E 4
	q->q_msgptr = q->q_msg - 2;
	q->q_msg_remain = q->q_msglen + 2;
	*(u_short *)q->q_msgptr = htons(q->q_msglen);
D 4
	/* timeout remains to be implemented */
	q->q_timeout = 0;
E 4
I 4
	if (tcpserv_send_timeout &&
	    (t = (struct timesched *) myalloc(sizeof(struct timesched)))) {
		t->tim_time = current_time + tcpserv_send_timeout;
		t->tim_func = timeout_handler;
		t->tim_arg = (caddr_t) q;
		time_schedule(t);
		q->q_timeout = t;
	} else
		q->q_timeout = 0;
E 4
	FD_SET(q->q_socket, &select_for_write);
E 7
I 7
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
I 8
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
E 8
E 7
}

void
tcpserv_acceptor(ti)
	struct tcpserv_instance *ti;
{
	struct sockaddr_in from;
	int fromlen;
	register int s;
	register struct aclentry *acl;
D 7
	register struct query *q;
E 7
I 7
	register struct tcpconn *tc;
	register struct timesched *t;
E 7
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
D 7
	q = alloc_query_struct(65537);
	if (!q) {
E 7
I 7
	tc = (struct tcpconn *) myalloc(sizeof(struct tcpconn));
	if (!tc) {
E 7
		syslog(LOG_ERR,
D 7
			"refusing TCP connection: no memory for state+buffer");
E 7
I 7
			"refusing TCP connection: no memory for state struct");
E 7
		close_socket(s, 1);
		return;
	}
	tcpserv_active_conn++;
D 7
	q->q_socket = s;
	q->q_msg = (u_char *)q + sizeof(struct query) + 2;
	q->q_msg_maxlen = 65535;
	q->q_aclperm = acl->acl_perm;
E 7
I 7
	tc->socket = s;
	tc->aclperm = acl->acl_perm;
	tc->rxquery = 0;
	tc->queries_in_process = 0;
	tc->respq_head = 0;
	tc->respq_tail = &tc->respq_head;
	read_init(tc);
E 7
	ioctl(s, FIONBIO, &one);
I 5
	setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &one, sizeof(int));
E 5
	select_desc[s].sel_read = tcpserv_read_handler;
	select_desc[s].sel_write = tcpserv_write_handler;
D 7
	select_desc[s].sel_opaque = (caddr_t) q;
E 7
I 7
	select_desc[s].sel_opaque = (caddr_t) tc;
E 7
	if (s > select_max_fd)
		select_max_fd = s;
D 7
	tcpserv_start_read(q);
E 7
I 7
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
E 7
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
E 1
