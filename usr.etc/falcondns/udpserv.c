/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * UDP query server
 */

#ifndef lint
static char sccsid[] = "@(#)udpserv.c	1.18 (IFCTF) 2013/08/10";
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

struct udpserv_instance {
	int	socket;
	struct	sockaddr_in addr;
};

static void
query_malloc_fail(s)
{
	char dummy;

	recv(s, &dummy, 1, 0);
	syslog(LOG_CRIT, "UDP query dropped because of malloc failure");
}

void
udpserv_query_complete(q)
	register struct query *q;
{
	register struct query *dq, *nq;

	sendto(q->q_socket, q->q_msg, q->q_msglen, 0, &q->q_sin,
		sizeof(struct sockaddr_in));
	for (dq = q->q_nextdup; dq; dq = nq) {
		*(u_short *)q->q_msg = *(u_short *)dq->q_msg;
		sendto(dq->q_socket, q->q_msg, q->q_msglen, 0, &dq->q_sin,
			sizeof(struct sockaddr_in));
		nq = dq->q_nextdup;
		free_query_struct(dq);
	}
	free_query_struct(q);
}

void
udpserv_recv_handler(ui)
	struct udpserv_instance *ui;
{
	register struct query *q;
	int fromlen;
	register struct aclentry *acl;

	q = alloc_query_struct(PACKETSZ);
	if (!q) {
		query_malloc_fail(ui->socket);
		return;
	}
	q->q_socket = ui->socket;
	q->q_msg = (u_char *)q + sizeof(struct query);
	q->q_msg_maxlen = PACKETSZ;
	fromlen = sizeof(struct sockaddr_in);
	q->q_msglen = recvfrom(q->q_socket, q->q_msg, PACKETSZ, 0, &q->q_sin,
				&fromlen);
	if (q->q_msglen < sizeof(HEADER) || q->q_msg[2] & 0x80) {
		/*
		 * If we get a datagram shorter than the header,
		 * i.e., completely unparseable, we silently discard
		 * it and don't bother with an error response which
		 * may not be possible if there is no XID etc.
		 * We do the same if the query packet claims to be a response.
		 *
		 * Errors from the recvfrom system call go here too.
		 */
		free(q);
		return;
	}
	for (acl = udpserv_acl; ; acl++)
		if ((q->q_sin.sin_addr.s_addr & acl->acl_ipmask) ==
		    acl->acl_ipbase)
			break;
	if (acl->acl_perm & ACL_ALLOW_QUERY)
		q->q_aclperm = acl->acl_perm;
	else {
		free(q);
		return;
	}
	q->q_flags = QFLAGS_UDPSERV;
	if (handle_query_initial(q) < 0) {
		sendto(q->q_socket, q->q_msg, q->q_msglen, 0, &q->q_sin,
			sizeof(struct sockaddr_in));
		free(q);
		return;
	}
	q->q_callwhendone = udpserv_query_complete;
	stage_query(q);
}

void
setup_udpserv(addr, port)
	u_long addr;	/* network b.o. */
	int port;	/* host b.o. */
{
	static int one = 1;
	register struct udpserv_instance *ui;

	ui = (struct udpserv_instance *)
		myalloc(sizeof(struct udpserv_instance));
	if (!ui) {
		perror("udpserv instance malloc");
		exit(1);
	}
	ui->addr.sin_family = AF_INET;
	ui->addr.sin_addr.s_addr = addr;
	ui->addr.sin_port = htons(port);
	ui->socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (ui->socket < 0) {
		syslog(LOG_CRIT, "creating udpserv socket: %m");
		perror("udpserv socket");
		exit(1);
	}
	if (bind(ui->socket, &ui->addr, sizeof(struct sockaddr_in)) < 0) {
		syslog(LOG_ERR, "bind udpserv socket to port %d: %m", port);
		perror("bind udpserv socket");
		exit(1);
	}
	ioctl(ui->socket, FIONBIO, &one);
	select_desc[ui->socket].sel_read = udpserv_recv_handler;
	select_desc[ui->socket].sel_opaque = (caddr_t)ui;
	FD_SET(ui->socket, &select_for_read);
	if (ui->socket > select_max_fd)
		select_max_fd = ui->socket;
}
