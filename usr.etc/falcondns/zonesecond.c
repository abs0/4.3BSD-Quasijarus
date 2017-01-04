/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Remote/secondary zone refresh code
 */

#ifndef lint
static char sccsid[] = "@(#)zonesecond.c	1.13 (IFCTF) 2013/08/10";
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
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
#include "globals.h"

extern u_char *myalloc();
extern struct query *create_internal_query();
extern u_char *msgparse_extract_rr();

extern char axfr_puller[];

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
soacheck_response_handler(tq, msg, msglen)
	register struct tcpquery *tq;
	u_char *msg;
	int msglen;
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
	hdr = (HEADER *) msg;
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
		if (msglen < tq->tq_querylen - 2)
			goto badecho;
		if (bcmp(tq->tq_query + 2 + sizeof(HEADER),
			 msg + sizeof(HEADER),
			 tq->tq_querylen - sizeof(HEADER) - 2))
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
		cp = msg + tq->tq_querylen - 2;
	else
		cp = msg + sizeof(HEADER);
	if (!msgparse_extract_rr(&rr, cp, msg + msglen, msg)) {
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
	if (msgparse_rdata(&rr, msg) < 0)
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
	struct tcpquery *tq;
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
	register struct tcpquery *tq;
	register u_char *dp;
	register int i;

	if (ensure_old_soa(z) < 0)
		return(-1);
	dp = myalloc(sizeof(struct tcpquery) + 2 + sizeof(HEADER) +
		     z->z_dname->dn_stringlen + 4);
	if (!dp) {
mallocfail:	syslog(LOG_CRIT,
		"secondary zone %s (%d): malloc failure prevents refresh",
			z->z_ascii_domname, z->z_class->c_class);
		return(-1);
	}
	tq = (struct tcpquery *) dp;
	dp += sizeof(struct tcpquery);
	tq->tq_query = dp;
	dp += 2;
	bzero(dp + 2, 10);
	dp[5] = 1;
	dp += sizeof(HEADER);
	bcopy(z->z_dname->dn_labels[0], dp, z->z_dname->dn_stringlen);
	dp += z->z_dname->dn_stringlen;
	PUTSHORT(T_SOA, dp);
	PUTSHORT(z->z_class->c_class, dp);
	tq->tq_querylen = dp - tq->tq_query;
	i = tq->tq_querylen - 2;
	dp = tq->tq_query;
	PUTSHORT(i, dp);
	tq->tq_sin.sin_family = AF_INET;
	tq->tq_sin.sin_addr.s_addr = z->z_fromaddr_current;
	tq->tq_sin.sin_port = htons(NAMESERVER_PORT);
	tq->tq_userinfo = (caddr_t) z;
	tq->tq_response_callbk = soacheck_response_handler;
	tq->tq_error_callbk = soacheck_error_handler;
	if (tcpqueue_submit_query(tq) < 0) {
		free(tq);
		goto mallocfail;
	}
	z->z_soa_check = tq;
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
	stage_query(q);
	return(0);
}

remote_zone_refresh(z)
	register struct zone *z;
{
	if (z->z_fromaddr_config == INADDR_NONE) {
		if (z->z_class->c_ready_to_serve)
			start_mname_query(z);
		else
			schedule_zone_refresh(z, 2);
	} else {
		z->z_fromaddr_current = z->z_fromaddr_config;
		start_remote_zone_soa_check(z);
	}
}

abort_remote_zone_refresh(z)
	register struct zone *z;
{
	register struct query *q;
	register struct tcpquery *tq;

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
	register struct zone *z;
{
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
		zonexfer_children++;
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
	z->z_class->c_outstanding_loads++;
}

zonexfer_child_reaper()
{
	register int pid;
	union wait status;
	register struct zone *z;

	for (;;) {
		pid = wait3(&status, WNOHANG, 0);
		if (pid < 1)
			return;
		if (!zonexfer_children) {
			syslog(LOG_CRIT,
				"BUG: reaped a child with zonexfer_children=0");
			abort();
		}
		zonexfer_children--;
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
