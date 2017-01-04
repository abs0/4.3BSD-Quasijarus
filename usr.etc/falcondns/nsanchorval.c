/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * NS-anchor refresh/validation logic
 */

#ifndef lint
static char sccsid[] = "@(#)nsanchorval.c	1.6 (IFCTF) 2013/08/10";
#endif

#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "class.h"
#include "tree.h"
#include "nsrec.h"
#include "globals.h"
#include "selectloop.h"
#include "msgparse.h"
#include "query.h"
#include "udpout.h"

extern u_char *myalloc();
extern struct query *create_internal_query();
extern u_char *msgparse_skip_dname();
extern u_char *msgparse_extract_rr();

void nsval_handle_response(), nsval_handle_error();
void nsval_submit_a_query();
void nsval_reschedule();

void
nsanchor_start_refresh(a)
	register struct ns_anchor *a;
{
	register struct query *q;
	register struct node *n;

	a->nsa_val_sched = 0;
	q = create_internal_query(0);
	if (!q) {
		syslog(LOG_CRIT,
			"unable to malloc query struct for NS-anchor refresh");
		return;
	}
	n = a->nsa_node;
	n->n_refcount++;
	q->q_class = a->nsa_class;
	dname_copy(a->nsa_dname, &q->q_stages[0].qs_qname);
	q->q_type = T_NS;
	q->q_noa = n;
	q->q_parent = (caddr_t) a;
	a->nsa_val_op = q;
	q->q_askforns_response_callbk = nsval_handle_response;
	q->q_askforns_error_callbk = nsval_handle_error;
	askforns_entry(q);
}

void
nsval_handle_response(q, msg, msglen)
	struct query *q;
	u_char *msg;
	int msglen;
{
	register struct ns_anchor *a;
	register HEADER *hdr;
	int ancount, i;
	register u_char *cp;
	struct parsedrr rr;
	register struct nsrr *srv;
	u_long ttl;

	free_subtree(q->q_noa);
	a = (struct ns_anchor *) q->q_parent;
	/* has this anchor been deleted? */
	if (!a->nsa_node) {
		free_query_struct(q);
		free_ns_rrset(a);
		return;
	}
	/* the real work begins */
	hdr = (HEADER *)msg;
	if (hdr->rcode != NOERROR) {
		syslog(LOG_WARNING,
	"refreshing NS-anchor at %s (%d): server responded with RCODE=%d",
			a->nsa_ascii_domname, a->nsa_class->c_class,
			hdr->rcode);
		free_query_struct(q);
		a->nsa_val_op = 0;
		nsval_reschedule(a, a->nsa_retry_interval);
		return;
	}
	if (!hdr->aa) {
		syslog(LOG_ERR,
		"refreshing NS-anchor at %s (%d): server responded with AA=0",
			a->nsa_ascii_domname, a->nsa_class->c_class);
warn_retry:	free_query_struct(q);
		a->nsa_val_op = 0;
		nsval_reschedule(a, a->nsa_warn_interval);
		return;
	}
	ancount = ntohs(hdr->ancount);
	if (ancount != a->nsa_rrset.ns_count) {
wrong_resp:	syslog(LOG_ERR,
	"refreshing NS-anchor at %s (%d): server response is not our NS RRset",
			a->nsa_ascii_domname, a->nsa_class->c_class);
		goto warn_retry;
	}
	if (hdr->qdcount)
		cp = msg + q->q_udpout->uo_querylen;
	else
		cp = msg + sizeof(HEADER);
	ttl = a->nsa_ttl_limit;
	for (i = 0; i < ancount; i++) {
		cp = msgparse_extract_rr(&rr, cp, msg + msglen, msg);
		if (!cp) {
parse_err:		syslog(LOG_ERR,
		"refreshing NS-anchor at %s (%d): error parsing NS response",
				a->nsa_ascii_domname, a->nsa_class->c_class);
			goto warn_retry;
		}
		if (!dname_compare(&rr.prr_owner, a->nsa_dname))
			goto wrong_resp;
		if (rr.prr_fix.class != a->nsa_class->c_class)
			goto wrong_resp;
		if (rr.prr_fix.type != T_NS)
			goto wrong_resp;
		if (msgparse_rdata(&rr, msg) < 0)
			goto parse_err;
		for (srv = a->nsa_rrset.ns_chain; srv; srv = srv->nsrr_next)
			if (dname_compare(srv + 1, &rr.prr_rdata_dn[0]))
				break;
		if (!srv)
			goto wrong_resp;
		if (rr.prr_fix.ttl < ttl)
			ttl = rr.prr_fix.ttl;
	}
	syslog(LOG_INFO,
		"NS-anchor at %s (%d): NS refresh successful, TTL is %lu",
		a->nsa_ascii_domname, a->nsa_class->c_class, ttl);
	a->nsa_rrset.ns_expire = current_time + ttl;
	a->nsa_val_ttl = ttl;
	nsval_submit_a_query(a, q, a->nsa_rrset.ns_chain);
}

void
nsval_handle_error(q)
	register struct query *q;
{
	register struct ns_anchor *a;

	free_subtree(q->q_noa);
	a = (struct ns_anchor *) q->q_parent;
	free_query_struct(q);
	/* has this anchor been deleted? */
	if (!a->nsa_node) {
		free_ns_rrset(a);
		return;
	}
	a->nsa_val_op = 0;
	syslog(LOG_INFO,
	"refreshing NS-anchor at %s (%d): unable to query, will retry in %d s",
		a->nsa_ascii_domname, a->nsa_class->c_class,
		a->nsa_retry_interval);
	nsval_reschedule(a, a->nsa_retry_interval);
}

void
nsval_a_query_done(q)
	register struct query *q;
{
	register struct ns_anchor *a;
	register struct nsrr *srv;
	register u_char *cp;
	struct rrfixed fix;
	u_long ttl;
	int i, j, matchcnt, nextrefresh;
	time_t cexpire;

	a = (struct ns_anchor *) q->q_parent;
	/* has this anchor been deleted? */
	if (!a->nsa_node) {
		free_query_struct(q);
		free_ns_rrset(a);
		return;
	}
	srv = a->nsa_val_server;
	switch (q->q_stages[0].qs_result) {
	case QSRESULT_ANSWER:
		break;
	case QSRESULT_CNAME:
		syslog(LOG_ERR,
"refreshing NS-anchor at %s (%d): %s is an alias, please use canonical name",
			a->nsa_ascii_domname, a->nsa_class->c_class,
			srv->nsrr_ascii);
		goto next;
	default:
		syslog(LOG_WARNING,
		"refreshing NS-anchor at %s (%d): A query for %s failed",
			a->nsa_ascii_domname, a->nsa_class->c_class,
			srv->nsrr_ascii);
		goto next;
	}
	matchcnt = 0;
	ttl = a->nsa_ttl_limit;
	for (i = 0; i < srv->nsrr_addrcnt; i++) {
		for (cp = q->q_answer_ptr, j = 0;
		     j < q->q_stages[0].qs_answer_rrcount; j++) {
			cp = msgparse_skip_dname(cp, q->q_msgptr);
			if (!cp)
				break;
			msgparse_get_rrfix(cp, &fix);
			cp += RRFIXEDSZ;
			if (fix.type == T_A && fix.class == C_IN &&
			    fix.rdlength == 4 &&
			    !bcmp(cp, &srv->nsrr_addrs[i], 4)) {
				matchcnt++;
				if (fix.ttl < ttl)
					ttl = fix.ttl;
				break;
			}
			cp += fix.rdlength;
		}
	}
	if (matchcnt != srv->nsrr_addrcnt) {
		syslog(LOG_ERR,
		"NS-anchor at %s (%d): server %s: A differs from expected",
			a->nsa_ascii_domname, a->nsa_class->c_class,
			srv->nsrr_ascii);
		goto next;
	}
	if (q->q_stages[0].qs_flags & QSFLAGS_AA) {
		syslog(LOG_INFO,
			"NS-anchor server %s: A refresh successful, TTL is %lu",
			srv->nsrr_ascii, ttl);
		srv->nsrr_A_expire = current_time + ttl;
		if (ttl < a->nsa_val_ttl)
			a->nsa_val_ttl = ttl;
	} else {
		syslog(LOG_INFO,
			"NS-anchor server %s: A refresh succeeded via cache",
			srv->nsrr_ascii);
		cexpire = current_time + ttl;
		if (cexpire > srv->nsrr_A_expire)
			srv->nsrr_A_expire = cexpire;
	}
next:	if (srv->nsrr_next)
		nsval_submit_a_query(a, q, srv->nsrr_next);
	else {
		free_query_struct(q);
		a->nsa_val_op = 0;
		nextrefresh = (int) a->nsa_val_ttl * a->nsa_ttl_percent / 100;
		syslog(LOG_INFO, "NS-anchor at %s (%d): next refresh in %d s",
			a->nsa_ascii_domname, a->nsa_class->c_class,
			nextrefresh);
		nsval_reschedule(a, nextrefresh);
	}
}

void
nsval_submit_a_query(a, q, srv)
	register struct ns_anchor *a;
	register struct query *q;
	register struct nsrr *srv;
{
	a->nsa_val_server = srv;
	reuse_internal_query(q);
	dname_copy((struct dname *)(srv + 1), &q->q_stages[0].qs_qname);
	q->q_type = T_A;
	q->q_callwhendone = nsval_a_query_done;
	stage_query(q);
}

void
nsval_reschedule(a, delay)
	register struct ns_anchor *a;
	int delay;
{
	register struct timesched *t;

	t = (struct timesched *) myalloc(sizeof(struct timesched));
	if (!t)
		return;
	t->tim_time = current_time + delay;
	t->tim_func = nsanchor_start_refresh;
	t->tim_arg = (caddr_t) a;
	time_schedule(t);
	a->nsa_val_sched = t;
}
