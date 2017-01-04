/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Periodic cache sweeper code
 */

#ifndef lint
static char sccsid[] = "@(#)cachesweep.c	1.6 (IFCTF) 2013/01/11";
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

static struct timesched *cache_sweep_scheduled;

void
cache_sweep_donode(n)
	register struct node *n;
{
	register struct rescache *rc, **rcp;
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
	for (rcp = &n->n_cached_ans; rc = *rcp; ) {
		if (current_time >= rc->rc_expire) {
			*rcp = rc->rc_next;
			if (rc->rc_pos)
				free_rrchain(rc->rc_pos);
			free(rc);
			continue;
		}
		rcp = &rc->rc_next;
	}
	if (n->n_cached_cname && current_time >= n->n_cached_cname->rr_expire) {
		free(n->n_cached_cname);
		n->n_cached_cname = 0;
	}
	if (n->n_cached_nxdom && current_time >= n->n_cached_nxdom->rc_expire) {
		free(n->n_cached_nxdom);
		n->n_cached_nxdom = 0;
	}
	if (n->n_cached_ans || n->n_cached_cname || n->n_cached_nxdom)
		return;
	if (n->n_refcount > 1 || n->n_unlinked)
		return;
	if (ns = n->n_ns) {
		if (ns->ns_type != NSTYPE_CACHEDREF)
			return;
		if (ns->ns_expire > current_time)
			return;
		free_ns_rrset(ns);
		n->n_ns = 0;
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
	stats_report();
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
	cache_sweep_scheduled = tim;
	return(1);
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
}
