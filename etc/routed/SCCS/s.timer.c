h54007
s 00010/00005/00106
d D 5.6 88/05/31 12:14:33 karels 11 10
c new tracing of changes, finish perspective change
e
s 00009/00003/00102
d D 5.5 88/02/16 18:51:02 bostic 10 9
c add Berkeley specific headers
e
s 00004/00003/00101
d D 5.4 87/04/02 13:06:35 karels 9 8
c finish up interface metric code: store metric from our perspective,
c plus increment for those we send to; delete route from kernel when unreachable,
c but keep in tables to advertise deletion
e
s 00003/00009/00101
d D 5.3 85/11/20 14:37:57 karels 8 7
c want to act as supplier if we have only a single point-point link;
c can't run timer on any interfaces if not a supplier
e
s 00003/00001/00107
d D 5.2 85/08/13 08:03:00 karels 7 6
c don't time out only interface if P-P and thus must be supplier
e
s 00007/00001/00101
d D 5.1 85/06/04 16:38:00 dist 6 5
c Add copyright
e
s 00027/00000/00075
d D 4.5 84/04/09 15:05:44 karels 5 4
c many cleanups; avoid interface timing out; put it back asap
e
s 00001/00005/00074
d D 4.4 83/06/01 16:26:56 sam 4 3
c notyet has come
e
s 00009/00002/00070
d D 4.3 83/05/25 17:51:17 sam 3 2
c protocol change; byte swap those fields which need it;  also add 
c a version stamp to allow future changes
e
s 00001/00001/00071
d D 4.2 83/01/11 14:38:43 sam 2 1
c 4.1c conversion contortions
e
s 00072/00000/00000
d D 4.1 82/11/02 22:28:10 sam 1 0
c date and time created 82/11/02 22:28:10 by sam
e
u
U
t
T
I 6
/*
D 11
 * Copyright (c) 1983 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 11
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
 */

E 6
I 1
#ifndef lint
D 3
static char sccsid[] = "%W% %G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 6
#endif
E 6
I 6
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10
E 6

/*
 * Routing Table Management Daemon
 */
D 2
#include "router.h"
E 2
I 2
#include "defs.h"
E 2

int	timeval = -TIMER_RATE;

/*
 * Timer routine.  Performs routing information supply
 * duties and manages timers on routing table entries.
 */
timer()
{
	register struct rthash *rh;
	register struct rt_entry *rt;
	struct rthash *base = hosthash;
D 11
	int doinghost = 1, timetobroadcast;
E 11
I 11
	int doinghost = 1, timetobroadcast, changes = 0;
E 11
I 7
	extern int externalinterfaces;
I 11
	time_t now;
E 11
E 7

	timeval += TIMER_RATE;
	if (lookforinterfaces && (timeval % CHECK_INTERVAL) == 0)
		ifinit();
	timetobroadcast = supplier && (timeval % SUPPLY_INTERVAL) == 0;
again:
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++) {
		rt = rh->rt_forw;
		for (; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
			/*
			 * We don't advance time on a routing entry for
D 8
			 * a passive gateway or that for our only interface. 
			 * The latter is excused because we don't act as
			 * a routing information supplier and hence would
			 * time it out.  This is fair as if it's down
			 * we're cut off from the world anyway and it's
			 * not likely we'll grow any new hardware in
			 * the mean time.
E 8
I 8
			 * a passive gateway, or any interface if we're
			 * not acting as supplier.
E 8
			 */
			if (!(rt->rt_state & RTS_PASSIVE) &&
D 7
			    (supplier || !(rt->rt_state & RTS_INTERFACE)))
E 7
I 7
D 8
			    (externalinterfaces > 1 ||
			    !(rt->rt_state & RTS_INTERFACE)))
E 8
I 8
			    (supplier || !(rt->rt_state & RTS_INTERFACE)))
E 8
E 7
				rt->rt_timer += TIMER_RATE;
D 9
			if (rt->rt_timer >= EXPIRE_TIME)
				rt->rt_metric = HOPCNT_INFINITY;
E 9
			if (rt->rt_timer >= GARBAGE_TIME) {
				rt = rt->rt_back;
				rtdelete(rt->rt_forw);
				continue;
			}
I 9
D 11
			if (rt->rt_timer >= EXPIRE_TIME)
E 11
I 11
			if (rt->rt_timer >= EXPIRE_TIME) {
				if (traceactions && changes++ == 0) {
					(void) time(&now);
					curtime = ctime(&now);
				}
E 11
				rtchange(rt, &rt->rt_router, HOPCNT_INFINITY);
I 11
			}
E 11
E 9
			if (rt->rt_state & RTS_CHANGED) {
				rt->rt_state &= ~RTS_CHANGED;
				/* don't send extraneous packets */
				if (!supplier || timetobroadcast)
					continue;
				msg->rip_cmd = RIPCMD_RESPONSE;
I 3
				msg->rip_vers = RIPVERSION;
E 3
				msg->rip_nets[0].rip_dst = rt->rt_dst;
D 4
				msg->rip_nets[0].rip_metric =
D 3
				    min(rt->rt_metric+1, HOPCNT_INFINITY);
E 3
I 3
				   min(rt->rt_metric+1, HOPCNT_INFINITY);
#ifdef notyet
E 4
				msg->rip_nets[0].rip_dst.sa_family =
				   htons(msg->rip_nets[0].rip_dst.sa_family);
				msg->rip_nets[0].rip_metric =
D 4
				   htonl(msg->rip_nets[0].rip_metric);
#endif
E 4
I 4
D 9
				   htonl(min(rt->rt_metric+1, HOPCNT_INFINITY));
E 9
I 9
D 11
				   htonl(min(rt->rt_metric + rt->rt_ifmetric,
				   HOPCNT_INFINITY));
E 11
I 11
				   htonl(min(rt->rt_metric, HOPCNT_INFINITY));
E 11
E 9
E 4
E 3
				toall(sendmsg);
			}
		}
	}
	if (doinghost) {
		doinghost = 0;
		base = nethash;
		goto again;
	}
	if (timetobroadcast)
		toall(supply);
	alarm(TIMER_RATE);
}
I 5

/*
 * On hangup, let everyone know we're going away.
 */
hup()
{
	register struct rthash *rh;
	register struct rt_entry *rt;
	struct rthash *base = hosthash;
	int doinghost = 1;

	if (supplier) {
again:
		for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++) {
			rt = rh->rt_forw;
			for (; rt != (struct rt_entry *)rh; rt = rt->rt_forw)
				rt->rt_metric = HOPCNT_INFINITY;
		}
		if (doinghost) {
			doinghost = 0;
			base = nethash;
			goto again;
		}
		toall(supply);
	}
	exit(1);
}
E 5
E 1
