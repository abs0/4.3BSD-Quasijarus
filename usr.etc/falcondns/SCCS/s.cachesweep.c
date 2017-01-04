h50372
s 00034/00008/00126
d D 1.6 2013/01/11 23:02:54 msokolov 6 5
c first round of changes for the new FSR cache design
e
s 00001/00001/00133
d D 1.5 2013/01/06 07:04:13 msokolov 5 4
c MSDNS => FalconDNS
e
s 00000/00040/00134
d D 1.4 2011/12/20 06:02:43 msokolov 4 3
c stats reporting moved into stats.c
e
s 00041/00001/00133
d D 1.3 2011/12/13 04:54:32 msokolov 3 2
c TC stats implemented
e
s 00016/00002/00118
d D 1.2 2011/12/11 06:46:14 msokolov 2 1
c cache-sweep-now command added
e
s 00120/00000/00000
d D 1.1 2011/12/11 04:40:21 msokolov 1 0
c date and time created 2011/12/11 04:40:21 by msokolov
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
 * Periodic cache sweeper code
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "tree.h"
#include "nsrec.h"
#include "globals.h"
#include "selectloop.h"

extern u_char *myalloc();

D 2
static int cache_sweep_scheduled;
E 2
I 2
static struct timesched *cache_sweep_scheduled;
E 2

void
cache_sweep_donode(n)
	register struct node *n;
{
D 6
	register struct rr *rr, **rrp;
E 6
I 6
	register struct rescache *rc, **rcp;
E 6
	register struct ns_rrset *ns;

	if (n->n_refcount < 1) {
		syslog(LOG_CRIT, "BUG: n_refcount<1 in cache sweep");
		abort();
	}
	if (n->n_refcount == 1) {
		free_subtree(n);
		return;
	}
	n->n_refcount--;
D 6
	for (rrp = &n->n_rrcache; rr = *rrp; ) {
		if (current_time >= rr->rr_expire) {
			*rrp = rr->rr_next;
			free(rr);
E 6
I 6
	for (rcp = &n->n_cached_ans; rc = *rcp; ) {
		if (current_time >= rc->rc_expire) {
			*rcp = rc->rc_next;
			if (rc->rc_pos)
				free_rrchain(rc->rc_pos);
			free(rc);
E 6
			continue;
		}
D 6
		rrp = &rr->rr_next;
E 6
I 6
		rcp = &rc->rc_next;
E 6
	}
D 6
	if (n->n_rrcache)
E 6
I 6
	if (n->n_cached_cname && current_time >= n->n_cached_cname->rr_expire) {
		free(n->n_cached_cname);
		n->n_cached_cname = 0;
	}
	if (n->n_cached_nxdom && current_time >= n->n_cached_nxdom->rc_expire) {
		free(n->n_cached_nxdom);
		n->n_cached_nxdom = 0;
	}
	if (n->n_cached_ans || n->n_cached_cname || n->n_cached_nxdom)
E 6
		return;
D 6
	if (n->n_refcount > 1)
E 6
I 6
	if (n->n_refcount > 1 || n->n_unlinked)
E 6
		return;
	if (ns = n->n_ns) {
		if (ns->ns_type != NSTYPE_CACHEDREF)
			return;
		if (ns->ns_expire > current_time)
			return;
		free_ns_rrset(ns);
		n->n_ns = 0;
I 6
	}
	if (n->n_zonehead) {
		/*
		 * It's a zonal node below a bottom cut point
		 * that got included in the cache sweep because
		 * the FSR has hung some cached answers from it.
		 *
		 * Not only do we not delete it, but we cut it out
		 * of the cache sweep list so we won't bother it
		 * again unless it gets new cached stuff.
		 */
		*n->n_cache_backptr = n->n_nextincache;
		if (n->n_nextincache)
			n->n_nextincache->n_cache_backptr = n->n_cache_backptr;
		n->n_cache_backptr = 0;
		return;
E 6
	}
	if (node_has_children(n))
		return;
	/* get rid of it! */
	if (n->n_nextsib)
		n->n_nextsib->n_backptr = n->n_backptr;
	*n->n_backptr = n->n_nextsib;
	free_subtree(n);
}

void
cache_sweep_process()
{
	register struct node *n, *nn;

	n = cache_sweep_ptr;
	nn = n->n_nextincache;
	if (nn)
		nn->n_refcount++;
	cache_sweep_donode(n);
	cache_sweep_ptr = nn;
	if (nn)
		return;
	syslog(LOG_DEBUG, "cache sweep complete");
	schedule_cache_sweep();
}

void
cache_sweep_start()
{
	register struct node *n;

	cache_sweep_scheduled = 0;
D 3
	/* stats reports will go here */
E 3
I 3
	stats_report();
E 3
	if (n = cache_node_list) {
		syslog(LOG_DEBUG, "starting cache sweep");
		n->n_refcount++;
		cache_sweep_ptr = n;
	} else {
		syslog(LOG_DEBUG, "no cache to sweep, rescheduling");
		schedule_cache_sweep();
	}
}

schedule_cache_sweep()
{
	register struct timesched *tim;

	if (cache_sweep_scheduled || cache_sweep_ptr || !cache_sweep_interval)
		return(0);
	tim = (struct timesched *) myalloc(sizeof(struct timesched));
	if (!tim) {
		syslog(LOG_CRIT,
			"unable to schedule cache sweep: malloc failed");
		return(-1);
	}
	tim->tim_time = current_time + cache_sweep_interval;
	tim->tim_func = cache_sweep_start;
	time_schedule(tim);
D 2
	cache_sweep_scheduled = 1;
E 2
I 2
	cache_sweep_scheduled = tim;
E 2
	return(1);
I 2
}

void
cache_sweep_cmd()
{
	if (cache_sweep_ptr) {
		syslog(LOG_ERR, "cache sweep is already in progress");
		return;
	}
	if (cache_sweep_scheduled) {
		timesched_discard(cache_sweep_scheduled);
		cache_sweep_scheduled = 0;
	}
	cache_sweep_start();
I 3
}
D 4

stats_report()
{
	if (stats_incoming_udp_tc) {
		syslog(LOG_NOTICE,
			"%d TC UDP responses received since last cache sweep",
			stats_incoming_udp_tc);
		stats_incoming_udp_tc = 0;
	}
	if (stats_incoming_tcp_tc) {
		syslog(LOG_NOTICE,
			"%d TC TCP responses received since last cache sweep",
			stats_incoming_tcp_tc);
		stats_incoming_tcp_tc = 0;
	}
	if (stats_outgoing_udp_tc) {
		syslog(LOG_NOTICE,
			"%d TC UDP responses sent since last cache sweep",
			stats_outgoing_udp_tc);
		stats_outgoing_udp_tc = 0;
	}
	if (stats_outgoing_tcp_tc) {
		syslog(LOG_NOTICE,
			"%d TC TCP responses sent since last cache sweep",
			stats_outgoing_tcp_tc);
		stats_outgoing_tcp_tc = 0;
	}
	if (stats_local_ar_tc) {
		syslog(LOG_NOTICE,
		"local AR failed to fit %d times since last cache sweep",
			stats_local_ar_tc);
		stats_local_ar_tc = 0;
	}
	if (stats_fwd_ar_tc) {
		syslog(LOG_NOTICE,
		"forwarded AR failed to fit %d times since last cache sweep",
			stats_fwd_ar_tc);
		stats_fwd_ar_tc = 0;
	}
E 3
E 2
}
E 4
E 1
