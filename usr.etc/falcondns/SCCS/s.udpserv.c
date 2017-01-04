h56247
s 00001/00001/00144
d D 1.18 2013/08/10 07:11:40 msokolov 18 17
c external queries bypass the queue
e
s 00009/00000/00136
d D 1.17 2013/01/13 15:31:43 msokolov 17 16
c duplicate query suppression implemented
e
s 00000/00001/00136
d D 1.16 2013/01/07 20:17:03 msokolov 16 15
c tcpserv revamped for multiple simultaneous queries on one connection
e
s 00001/00001/00136
d D 1.15 2013/01/06 07:03:45 msokolov 15 14
c MSDNS => FalconDNS
e
s 00001/00012/00136
d D 1.14 2011/12/07 21:08:09 msokolov 14 13
c final output hooked in
e
s 00001/00000/00147
d D 1.13 2011/11/11 20:55:17 msokolov 13 12
c #include <machine/endian.h> for hton[ls] and ntoh[ls]
e
s 00001/00001/00146
d D 1.12 2011/11/02 06:55:10 msokolov 12 11
c query trace adapted for nested queries
e
s 00034/00023/00113
d D 1.11 2011/11/02 02:02:11 msokolov 11 10
c proper handling of multiple local IP addresses in udpserv
e
s 00000/00001/00136
d D 1.10 2011/11/01 21:11:11 msokolov 10 9
c don't bother setting q_socket
e
s 00000/00001/00137
d D 1.9 2011/11/01 08:00:48 msokolov 9 8
c NOA concept rethought
e
s 00012/00000/00126
d D 1.8 2011/11/01 02:40:18 msokolov 8 7
c udpserv ACL implemented
e
s 00003/00000/00123
d D 1.7 2011/10/30 21:06:44 msokolov 7 6
c set the socket to non-blocking just in case
e
s 00038/00000/00085
d D 1.6 2011/10/30 19:40:03 msokolov 6 5
c udpserv is now live
e
s 00002/00000/00083
d D 1.5 2011/10/30 01:22:30 msokolov 5 4
c oops
e
s 00011/00003/00072
d D 1.4 2011/10/30 01:16:48 msokolov 4 3
c query processing shaping up
e
s 00001/00007/00074
d D 1.3 2011/09/07 18:52:50 msokolov 3 2
c handle_query_initial() hooked up
e
s 00003/00001/00078
d D 1.2 2011/09/07 06:35:27 msokolov 2 1
c minor fixes from weeks ago
e
s 00079/00000/00000
d D 1.1 2011/08/14 17:26:03 msokolov 1 0
c date and time created 2011/08/14 17:26:03 by msokolov
e
u
U
t
T
I 1
/*
D 15
 * Michael Sokolov's Domain Name Server (MSDNS)
E 15
I 15
 * FalconDNS daemon by Michael Spacefalcon
E 15
 *
 * UDP query server
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 13
#include <machine/endian.h>
E 13
#include <sys/socket.h>
I 7
#include <sys/ioctl.h>
E 7
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "query.h"
#include "globals.h"
#include "selectloop.h"
I 8
#include "acl.h"
E 8

I 11
extern char *myalloc();
E 11
extern struct query *alloc_query_struct();

D 11
static int sock;
E 11
I 11
struct udpserv_instance {
	int	socket;
	struct	sockaddr_in addr;
};
E 11

static void
D 11
query_malloc_fail()
E 11
I 11
query_malloc_fail(s)
E 11
{
	char dummy;

D 11
	recv(sock, &dummy, 1, 0);
E 11
I 11
	recv(s, &dummy, 1, 0);
E 11
	syslog(LOG_CRIT, "UDP query dropped because of malloc failure");
}

void
D 4
udpserv_send_response(q)
E 4
I 4
udpserv_query_complete(q)
E 4
	register struct query *q;
{
I 17
	register struct query *dq, *nq;

E 17
I 6
D 14
	if (q->q_trace) {
		struct query_stage *qs = &q->q_stages[q->q_curstage];
		fprintf(q->q_trace,
			"final result from stage %d: code %d, flags %04x\n",
			q->q_curstage, qs->qs_result, qs->qs_flags);
		fprintf(q->q_trace, "CNAME count %d, answer count %d\n",
			qs->qs_cname_rrcount, qs->qs_answer_rrcount);
D 12
		fclose(q->q_trace);
E 12
I 12
		query_trace_free(q);
E 12
	}
E 6
I 4
/*
E 4
I 2
	query_response_byteswap_counts(q);
E 14
I 14
D 16
	query_response_wrapup(q);
E 16
E 14
E 2
D 11
	sendto(sock, q->q_msg, q->q_msglen, 0, &q->q_sin,
E 11
I 11
	sendto(q->q_socket, q->q_msg, q->q_msglen, 0, &q->q_sin,
E 11
		sizeof(struct sockaddr_in));
I 17
	for (dq = q->q_nextdup; dq; dq = nq) {
		*(u_short *)q->q_msg = *(u_short *)dq->q_msg;
		sendto(dq->q_socket, q->q_msg, q->q_msglen, 0, &dq->q_sin,
			sizeof(struct sockaddr_in));
		nq = dq->q_nextdup;
		free_query_struct(dq);
	}
E 17
I 4
D 14
*/
E 14
I 5
D 9
	release_query_noa_subtrees(q);
E 9
E 5
E 4
	free_query_struct(q);
}

void
D 11
udpserv_recv_handler()
E 11
I 11
udpserv_recv_handler(ui)
	struct udpserv_instance *ui;
E 11
{
	register struct query *q;
	int fromlen;
I 8
	register struct aclentry *acl;
E 8

	q = alloc_query_struct(PACKETSZ);
	if (!q) {
D 11
		query_malloc_fail();
E 11
I 11
		query_malloc_fail(ui->socket);
E 11
		return;
	}
I 11
	q->q_socket = ui->socket;
E 11
	q->q_msg = (u_char *)q + sizeof(struct query);
	q->q_msg_maxlen = PACKETSZ;
D 10
	q->q_socket = sock;
E 10
	fromlen = sizeof(struct sockaddr_in);
D 11
	q->q_msglen = recvfrom(sock, q->q_msg, PACKETSZ, 0, &q->q_sin,
E 11
I 11
	q->q_msglen = recvfrom(q->q_socket, q->q_msg, PACKETSZ, 0, &q->q_sin,
E 11
				&fromlen);
D 2
	if (q->q_msglen < sizeof(HEADER)) {
E 2
I 2
	if (q->q_msglen < sizeof(HEADER) || q->q_msg[2] & 0x80) {
E 2
		/*
		 * If we get a datagram shorter than the header,
		 * i.e., completely unparseable, we silently discard
		 * it and don't bother with an error response which
		 * may not be possible if there is no XID etc.
I 2
		 * We do the same if the query packet claims to be a response.
E 2
		 *
		 * Errors from the recvfrom system call go here too.
		 */
I 8
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
E 8
		free(q);
		return;
	}
D 4
	q->q_callwhendone = udpserv_send_response;
D 3
	/*
	 * Here we are going to hand the query struct
	 * to the main query handler and return.
	 * The code will be filled out when the main query code
	 * gets written.
	 */
	free(q);	/* temporary plug for memory leak */
E 3
I 3
	handle_query_initial(q, 0);
E 4
I 4
	q->q_flags = QFLAGS_UDPSERV;
	if (handle_query_initial(q) < 0) {
D 11
		sendto(sock, q->q_msg, q->q_msglen, 0, &q->q_sin,
E 11
I 11
		sendto(q->q_socket, q->q_msg, q->q_msglen, 0, &q->q_sin,
E 11
			sizeof(struct sockaddr_in));
		free(q);
		return;
	}
I 5
	q->q_callwhendone = udpserv_query_complete;
E 5
D 18
	put_query_on_queue(q, QSTATE_STAGE);
E 18
I 18
	stage_query(q);
E 18
I 6
}

void
D 11
setup_udpserv(port)
E 11
I 11
setup_udpserv(addr, port)
	u_long addr;	/* network b.o. */
	int port;	/* host b.o. */
E 11
{
D 11
	struct sockaddr_in addr;
E 11
I 7
	static int one = 1;
I 11
	register struct udpserv_instance *ui;
E 11
E 7

D 11
	if (sock) {
		fprintf(stderr, "msdns.conf: duplicate udpserv line\n");
E 11
I 11
	ui = (struct udpserv_instance *)
		myalloc(sizeof(struct udpserv_instance));
	if (!ui) {
		perror("udpserv instance malloc");
E 11
		exit(1);
	}
D 11
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock < 0) {
E 11
I 11
	ui->addr.sin_family = AF_INET;
	ui->addr.sin_addr.s_addr = addr;
	ui->addr.sin_port = htons(port);
	ui->socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (ui->socket < 0) {
E 11
		syslog(LOG_CRIT, "creating udpserv socket: %m");
		perror("udpserv socket");
		exit(1);
	}
D 11
	if (bind(sock, &addr, sizeof addr) < 0) {
E 11
I 11
	if (bind(ui->socket, &ui->addr, sizeof(struct sockaddr_in)) < 0) {
E 11
		syslog(LOG_ERR, "bind udpserv socket to port %d: %m", port);
		perror("bind udpserv socket");
		exit(1);
	}
I 7
D 11
	ioctl(sock, FIONBIO, &one);
E 7
	select_desc[sock].sel_read = udpserv_recv_handler;
	FD_SET(sock, &select_for_read);
	if (sock > select_max_fd)
		select_max_fd = sock;
E 11
I 11
	ioctl(ui->socket, FIONBIO, &one);
	select_desc[ui->socket].sel_read = udpserv_recv_handler;
	select_desc[ui->socket].sel_opaque = (caddr_t)ui;
	FD_SET(ui->socket, &select_for_read);
	if (ui->socket > select_max_fd)
		select_max_fd = ui->socket;
E 11
E 6
E 4
E 3
}
E 1
