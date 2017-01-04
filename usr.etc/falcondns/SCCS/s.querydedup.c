h22710
s 00074/00000/00000
d D 1.1 2013/01/13 15:29:48 msokolov 1 0
c date and time created 2013/01/13 15:29:48 by msokolov
e
u
U
t
T
I 1
/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Duplicate query suppression logic
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include "dname.h"
#include "class.h"
#include "query.h"

extern u_char *myalloc();

#define	flagsmask(f)	((f) & (QFLAGS_WANT_AA|QFLAGS_TCPSERV|QFLAGS_UDPSERV))

is_udp_duplicate(oldchain, newq)
	struct query *oldchain;
	register struct query *newq;
{
	register struct query *cand;

	for (cand = oldchain; cand; cand = cand->q_nextdup)
		if (cand->q_sin.sin_addr.s_addr == newq->q_sin.sin_addr.s_addr
		    && cand->q_sin.sin_port == newq->q_sin.sin_port)
			return(1);
	return(0);
}

query_dup_intercept(newq)
	register struct query *newq;
{
	struct class *cl;
	register int cmplen;
	register u_char *cmpstr;
	register struct query *p, **pp;

	cl = newq->q_class;
	if (!cl->c_dupcatcher) {
		cl->c_dupcatcher = (struct query **)
					myalloc(sizeof(struct query *) * 256);
		if (!cl->c_dupcatcher)
			return(0);
		bzero(cl->c_dupcatcher, sizeof(struct query *) * 256);
	}
	cmplen = newq->q_stages[0].qs_qname.dn_stringlen - 1;
	cmpstr = newq->q_stages[0].qs_qname.dn_labels[0];
	for (pp = cl->c_dupcatcher + cmplen; p = *pp; pp = &p->q_dupcatch_next){
		if (p->q_type != newq->q_type)
			continue;
		if (bcmp(p->q_stages[0].qs_qname.dn_labels[0], cmpstr, cmplen))
			continue;
		if (flagsmask(p->q_flags) == flagsmask(newq->q_flags))
			break;
	}
	if (!p) {
		newq->q_dupcatch_backptr = pp;
		*pp = newq;
		newq->q_dupcatch_next = 0;
		return(0);
	}
	if (p->q_flags & QFLAGS_UDPSERV && is_udp_duplicate(p, newq)) {
		free_query_struct(newq);
		return(1);
	}
	newq->q_nextdup = p->q_nextdup;
	p->q_nextdup = newq;
	return(1);
}
E 1
