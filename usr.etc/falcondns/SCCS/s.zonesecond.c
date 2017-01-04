h18036
s 00001/00001/00412
d D 1.13 2013/08/10 08:24:10 msokolov 13 12
c don't set Z_RETRYING when MNAME query is delayed for not-ready-to-serve
e
s 00001/00001/00412
d D 1.12 2013/08/10 07:11:51 msokolov 12 11
c external queries bypass the queue
e
s 00006/00003/00407
d D 1.11 2013/01/14 00:51:35 msokolov 11 10
c don't start MNAME query until the class is ready to serve
e
s 00001/00000/00409
d D 1.10 2013/01/14 00:40:13 msokolov 10 9
c class ready-to-serve flag implemented
e
s 00001/00001/00408
d D 1.9 2013/01/06 08:56:39 msokolov 9 8
c more sensible and consistent msgparse function naming:
c s/extract_dname_from_msg/msgparse_extract_dname/
c s/parse_incoming_rr/msgparse_rdata/
e
s 00001/00001/00408
d D 1.8 2013/01/06 07:04:20 msokolov 8 7
c MSDNS => FalconDNS
e
s 00012/00005/00397
d D 1.7 2011/12/17 20:47:57 msokolov 7 6
c SOA check bug: forgot about the TCP message length octets
e
s 00007/00000/00395
d D 1.6 2011/12/17 08:24:40 msokolov 6 5
c workaround for the child exit race condition
e
s 00022/00000/00373
d D 1.5 2011/12/17 07:59:08 msokolov 5 4
c zonexfer_child_reaper() implemented
e
s 00036/00000/00337
d D 1.4 2011/12/17 07:37:46 msokolov 4 3
c axfr_pull_complete() implemented
e
s 00038/00002/00299
d D 1.3 2011/12/17 07:10:00 msokolov 3 2
c start_axfr_pull() implemented
e
s 00022/00019/00279
d D 1.2 2011/12/17 06:38:05 msokolov 2 1
c tcpqueue revamped
e
s 00298/00000/00000
d D 1.1 2011/12/16 06:22:48 msokolov 1 0
c date and time created 2011/12/16 06:22:48 by msokolov
e
u
U
t
T
I 1
/*
D 8
 * Michael Sokolov's Domain Name Server (MSDNS)
E 8
I 8
 * FalconDNS daemon by Michael Spacefalcon
E 8
 *
 * Remote/secondary zone refresh code
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <sys/socket.h>
I 4
#include <sys/wait.h>
E 4
#include <machine/endian.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "class.h"
#include "dname.h"
#include "zone.h"
#include "tree.h"
#include "rr.h"
#include "query.h"
#include "tcpqueue.h"
#include "msgparse.h"
I 4
#include "globals.h"
E 4

extern u_char *myalloc();
extern struct query *create_internal_query();
extern u_char *msgparse_extract_rr();

I 3
extern char axfr_puller[];

E 3
static
ensure_old_soa(z)
	register struct zone *z;
{
	if (z->z_activetree)
		return(0);
	syslog(LOG_ERR, "secondary zone %s (%d): no old SOA to refresh against",
		z->z_ascii_domname, z->z_class->c_class);
	return(-1);
}

void
D 2
soacheck_response_handler(tq)
	register struct tcpqueue *tq;
E 2
I 2
soacheck_response_handler(tq, msg, msglen)
	register struct tcpquery *tq;
	u_char *msg;
	int msglen;
E 2
{
	register struct zone *z;
	register HEADER *hdr;
	register u_char *cp;
	struct parsedrr rr;
	u_long oldserial, newserial;
	long serialdiff;

	z = (struct zone *) tq->tq_userinfo;
	if (!z)
		return;
	z->z_soa_check = 0;
D 2
	hdr = (HEADER *) tq->tq_rspbuf;
E 2
I 2
	hdr = (HEADER *) msg;
E 2
	if (hdr->rcode != NOERROR) {
		if (!(z->z_flags & Z_RETRYING))
			syslog(LOG_ERR,
			"SOA refresh of %s (%d): %s responded with RCODE=%d",
				z->z_ascii_domname, z->z_class->c_class,
				inet_ntoa(tq->tq_sin.sin_addr), hdr->rcode);
		schedule_zone_refresh(z, 1);
		return;
	}
	if (ntohs(hdr->qdcount) > 1) {
badecho:	syslog(LOG_ERR,
	"SOA refresh of %s (%d): TCP response from %s: bad echo of query",
			z->z_ascii_domname, z->z_class->c_class,
			inet_ntoa(tq->tq_sin.sin_addr));
		schedule_zone_refresh(z, 1);
		return;
	}
	if (hdr->qdcount) {
D 2
		if (tq->tq_rsplen < tq->tq_querylen)
E 2
I 2
D 7
		if (msglen < tq->tq_querylen)
E 7
I 7
		if (msglen < tq->tq_querylen - 2)
E 7
E 2
			goto badecho;
D 2
		if (bcmp(tq->tq_query + sizeof(HEADER),
			 tq->tq_rspbuf + sizeof(HEADER),
E 2
I 2
D 7
		if (bcmp(tq->tq_query + sizeof(HEADER), msg + sizeof(HEADER),
E 2
			 tq->tq_querylen - sizeof(HEADER)))
E 7
I 7
		if (bcmp(tq->tq_query + 2 + sizeof(HEADER),
			 msg + sizeof(HEADER),
			 tq->tq_querylen - sizeof(HEADER) - 2))
E 7
			goto badecho;
	}
	if (!hdr->aa) {
		syslog(LOG_ERR,
			"SOA refresh of %s (%d): %s responded with AA=0",
			z->z_ascii_domname, z->z_class->c_class,
			inet_ntoa(tq->tq_sin.sin_addr));
		schedule_zone_refresh(z, 1);
		return;
	}
	if (ntohs(hdr->ancount) != 1) {
resp_not_soa:	syslog(LOG_ERR,
	"refresh of %s (%d): TCP response from %s is not the expected SOA",
			z->z_ascii_domname, z->z_class->c_class,
			inet_ntoa(tq->tq_sin.sin_addr));
		schedule_zone_refresh(z, 1);
		return;
	}
	if (hdr->qdcount)
D 2
		cp = tq->tq_query + tq->tq_querylen;
E 2
I 2
D 7
		cp = msg + tq->tq_querylen;
E 7
I 7
		cp = msg + tq->tq_querylen - 2;
E 7
E 2
	else
D 2
		cp = tq->tq_query + sizeof(HEADER);
	if (!msgparse_extract_rr(&rr, cp, tq->tq_query + tq->tq_querylen,
				 tq->tq_query)) {
E 2
I 2
		cp = msg + sizeof(HEADER);
	if (!msgparse_extract_rr(&rr, cp, msg + msglen, msg)) {
E 2
parse_err:	syslog(LOG_ERR,
		"SOA refresh of %s (%d): error parsing TCP response from %s",
			z->z_ascii_domname, z->z_class->c_class,
			inet_ntoa(tq->tq_sin.sin_addr));
		schedule_zone_refresh(z, 1);
		return;
	}
	if (!dname_compare(&rr.prr_owner, z->z_dname))
		goto resp_not_soa;
	if (rr.prr_fix.class != z->z_class->c_class)
		goto resp_not_soa;
	if (rr.prr_fix.type != T_SOA)
		goto resp_not_soa;
D 2
	if (parse_incoming_rr(&rr, tq->tq_query) < 0)
E 2
I 2
D 9
	if (parse_incoming_rr(&rr, msg) < 0)
E 9
I 9
	if (msgparse_rdata(&rr, msg) < 0)
E 9
E 2
		goto parse_err;
	/* yay, we've got the new SOA: now compare it against the old */
	if (ensure_old_soa(z) < 0)
		return;
	oldserial = z->z_activetree->n_soa->soa_serial;
	cp = rr.prr_rdata_misc;
	GETLONG(newserial, cp);
	serialdiff = newserial - oldserial;
	if (serialdiff == 0) {
		syslog(LOG_INFO,
		"SOA refresh of %s (%d): serial from %s equals ours (%lu)",
			z->z_ascii_domname, z->z_class->c_class,
			inet_ntoa(tq->tq_sin.sin_addr), oldserial);
		schedule_zone_refresh(z, 0);
		return;
	}
	if (serialdiff < 0) {
		syslog(LOG_NOTICE,
	"SOA refresh of %s (%d): serial from %s is %lu, older than our %lu",
			z->z_ascii_domname, z->z_class->c_class,
			inet_ntoa(tq->tq_sin.sin_addr), newserial, oldserial);
		schedule_zone_refresh(z, 0);
		return;
	}
	syslog(LOG_NOTICE,
	"zone refresh: %s (%d) needs update: %s has serial %lu, we have %lu",
		z->z_ascii_domname, z->z_class->c_class,
		inet_ntoa(tq->tq_sin.sin_addr), newserial, oldserial);
	start_axfr_pull(z);
}

void
soacheck_error_handler(tq)
D 2
	struct tcpqueue *tq;
E 2
I 2
	struct tcpquery *tq;
E 2
{
	register struct zone *z;

	z = (struct zone *) tq->tq_userinfo;
	if (!z)
		return;
	z->z_soa_check = 0;
	if (!(z->z_flags & Z_RETRYING))
		syslog(LOG_ERR,
		"refresh of %s (%d): SOA-check TCP connection to %s failed",
			z->z_ascii_domname, z->z_class->c_class,
			inet_ntoa(tq->tq_sin.sin_addr));
	schedule_zone_refresh(z, 1);
}

start_remote_zone_soa_check(z)
	register struct zone *z;
{
D 2
	register struct tcpqueue *tq;
E 2
I 2
	register struct tcpquery *tq;
E 2
	register u_char *dp;
I 7
	register int i;
E 7

	if (ensure_old_soa(z) < 0)
		return(-1);
D 2
	dp = myalloc(sizeof(struct tcpqueue) + z->z_dname->dn_stringlen + 16);
E 2
I 2
D 7
	dp = myalloc(sizeof(struct tcpquery) + z->z_dname->dn_stringlen + 16);
E 7
I 7
	dp = myalloc(sizeof(struct tcpquery) + 2 + sizeof(HEADER) +
		     z->z_dname->dn_stringlen + 4);
E 7
E 2
	if (!dp) {
D 2
		syslog(LOG_CRIT,
E 2
I 2
mallocfail:	syslog(LOG_CRIT,
E 2
		"secondary zone %s (%d): malloc failure prevents refresh",
			z->z_ascii_domname, z->z_class->c_class);
		return(-1);
	}
D 2
	tq = (struct tcpqueue *) dp;
	dp += sizeof(struct tcpqueue);
E 2
I 2
	tq = (struct tcpquery *) dp;
	dp += sizeof(struct tcpquery);
E 2
	tq->tq_query = dp;
I 7
	dp += 2;
E 7
	bzero(dp + 2, 10);
	dp[5] = 1;
	dp += sizeof(HEADER);
	bcopy(z->z_dname->dn_labels[0], dp, z->z_dname->dn_stringlen);
	dp += z->z_dname->dn_stringlen;
	PUTSHORT(T_SOA, dp);
	PUTSHORT(z->z_class->c_class, dp);
	tq->tq_querylen = dp - tq->tq_query;
I 7
	i = tq->tq_querylen - 2;
	dp = tq->tq_query;
	PUTSHORT(i, dp);
E 7
	tq->tq_sin.sin_family = AF_INET;
	tq->tq_sin.sin_addr.s_addr = z->z_fromaddr_current;
	tq->tq_sin.sin_port = htons(NAMESERVER_PORT);
	tq->tq_userinfo = (caddr_t) z;
	tq->tq_response_callbk = soacheck_response_handler;
	tq->tq_error_callbk = soacheck_error_handler;
I 2
	if (tcpqueue_submit_query(tq) < 0) {
		free(tq);
		goto mallocfail;
	}
E 2
	z->z_soa_check = tq;
D 2
	tcpqueue_submit(tq);
E 2
}

void
mname_query_complete(q)
	register struct query *q;
{
	register struct zone *z;
	register int i;

	z = (struct zone *) q->q_parent;
	if (!z) {
		free_query_struct(q);
		return;
	}
	z->z_mname_query = 0;
	if (q->q_stages[q->q_curstage].qs_result != QSRESULT_ANSWER) {
		free_query_struct(q);
		if (!(z->z_flags & Z_RETRYING))
			syslog(LOG_ERR,
				"refresh of %s (%d): query for MNAME failed",
				z->z_ascii_domname, z->z_class->c_class);
		schedule_zone_refresh(z, 1);
		return;
	}
	i = intquery_extract_A_answer(q, &z->z_fromaddr_current, 1, 0);
	free_query_struct(q);
	if (i) {
		syslog(LOG_DEBUG, "refresh of %s (%d): MNAME resolved to %s",
			z->z_ascii_domname, z->z_class->c_class,
			inet_ntoa(*(struct in_addr *)&z->z_fromaddr_current));
		start_remote_zone_soa_check(z);
	} else {
		if (!(z->z_flags & Z_RETRYING))
			syslog(LOG_ERR,
		"refresh of %s (%d): query for MNAME returned no A records",
				z->z_ascii_domname, z->z_class->c_class);
		schedule_zone_refresh(z, 1);
	}
}

start_mname_query(z)
	register struct zone *z;
{
	register struct query *q;

	if (ensure_old_soa(z) < 0)
		return(-1);
	q = create_internal_query(0);
	if (!q) {
		syslog(LOG_CRIT,
		"secondary zone %s (%d): malloc failure prevents refresh",
			z->z_ascii_domname, z->z_class->c_class);
		return(-1);
	}
	q->q_class = z->z_class;
	dname_copy(z->z_activetree->n_soa->soa_mname, &q->q_stages[0].qs_qname);
	q->q_type = T_A;
	q->q_callwhendone = mname_query_complete;
	q->q_parent = (caddr_t) z;
	z->z_mname_query = q;
D 12
	put_query_on_queue(q, QSTATE_STAGE);
E 12
I 12
	stage_query(q);
E 12
	return(0);
}

remote_zone_refresh(z)
	register struct zone *z;
{
D 11
	if (z->z_fromaddr_config == INADDR_NONE)
		start_mname_query(z);
	else {
E 11
I 11
	if (z->z_fromaddr_config == INADDR_NONE) {
		if (z->z_class->c_ready_to_serve)
			start_mname_query(z);
		else
D 13
			schedule_zone_refresh(z, 1);
E 13
I 13
			schedule_zone_refresh(z, 2);
E 13
	} else {
E 11
		z->z_fromaddr_current = z->z_fromaddr_config;
		start_remote_zone_soa_check(z);
	}
}

abort_remote_zone_refresh(z)
	register struct zone *z;
{
	register struct query *q;
D 2
	register struct tcpqueue *tq;
E 2
I 2
	register struct tcpquery *tq;
E 2

	if (q = z->z_mname_query) {
		q->q_parent = 0;
		z->z_mname_query = 0;
	}
	if (tq = z->z_soa_check) {
		tq->tq_userinfo = 0;
		z->z_soa_check = 0;
	}
	z->z_puller_pid = 0;
}

start_axfr_pull(z)
D 3
	struct zone *z;
E 3
I 3
	register struct zone *z;
E 3
{
D 3
	syslog(LOG_ERR, "AXFR pull not implemented yet");
E 3
I 3
	int fd;
	register int i;
	char classarg[8];

	strcpy(z->z_temp_filename, "axfrXXXXXX");
	fd = mkstemp(z->z_temp_filename);
	if (fd < 0) {
		syslog(LOG_CRIT, "refresh of %s (%d): mkstemp failed",
			z->z_ascii_domname, z->z_class->c_class);
		schedule_zone_refresh(z, 1);
		return;
	}
	fchmod(fd, 0644);
	i = vfork();
	if (i < 0) {
		syslog(LOG_CRIT, "refresh of %s (%d): vfork failed: %m",
			z->z_ascii_domname, z->z_class->c_class);
		close(fd);
		schedule_zone_refresh(z, 1);
		return;
	}
	if (i) {
		close(fd);
		z->z_puller_pid = i;
I 6
		zonexfer_children++;
E 6
		return;
	}
	dup2(fd, 1);
	for (i = getdtablesize(); --i > 2; )
		close(i);
	sprintf(classarg, "-c%d", z->z_class->c_class);
	execl(axfr_puller, "zonexfer", classarg, "-s",
		inet_ntoa(*(struct in_addr *)&z->z_fromaddr_current),
		z->z_ascii_domname, "-", 0);
	/* no way to report an error message at this point! */
	_exit(1);
I 4
}

axfr_pull_complete(z, status)
	register struct zone *z;
	register union wait *status;
{
	z->z_puller_pid = 0;
	if (status->w_termsig) {
		syslog(LOG_CRIT,
		"refresh of %s (%d): zonexfer terminated with signal %d",
			z->z_ascii_domname, z->z_class->c_class,
			status->w_termsig);
		schedule_zone_refresh(z, 1);
		return;
	}
	if (status->w_retcode) {
		syslog(LOG_ERR,
		"refresh of %s (%d): zonexfer terminated with exit code %d",
			z->z_ascii_domname, z->z_class->c_class,
			status->w_termsig);
		schedule_zone_refresh(z, 1);
		return;
	}
	syslog(LOG_NOTICE, "refresh of %s (%d): AXFR completed successfully",
		z->z_ascii_domname, z->z_class->c_class);
	if (rename(z->z_temp_filename, z->z_filename) < 0) {
		syslog(LOG_CRIT,
			"refresh of %s (%d): unable to rename %s to %s: %m",
			z->z_ascii_domname, z->z_class->c_class,
			z->z_temp_filename, z->z_filename);
		return;
	}
	z->z_flags |= Z_FILEREAD_NEEDED;
	zones_needing_fileread++;
I 10
	z->z_class->c_outstanding_loads++;
E 10
E 4
E 3
}
I 5

zonexfer_child_reaper()
{
	register int pid;
	union wait status;
	register struct zone *z;

	for (;;) {
		pid = wait3(&status, WNOHANG, 0);
		if (pid < 1)
			return;
I 6
		if (!zonexfer_children) {
			syslog(LOG_CRIT,
				"BUG: reaped a child with zonexfer_children=0");
			abort();
		}
		zonexfer_children--;
E 6
		for (z = global_zone_list; z; z = z->z_next_global)
			if (z->z_puller_pid == pid)
				break;
		if (z)
			axfr_pull_complete(z, &status);
		else
			syslog(LOG_WARNING,
			"received exit status of abandoned child process %d",
				pid);
	}
}
E 5
E 1
