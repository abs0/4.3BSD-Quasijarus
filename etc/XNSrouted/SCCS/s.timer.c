h24210
s 00002/00002/00109
d D 5.4 86/02/14 18:28:39 sklower 4 3
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00012/00002/00099
d D 5.3 85/08/16 21:49:26 sklower 3 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00002/00002/00099
d D 5.2 85/08/16 20:44:14 sklower 2 1
c status as of 4.3 alpha tape
e
s 00101/00000/00000
d D 5.1 85/08/16 20:22:56 sklower 1 0
c date and time created 85/08/16 20:22:56 by sklower
e
u
U
t
T
I 3
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 * Includes material written at Cornell University by Bill Nesheim,
 * by permission of the author.
 */


E 3
I 1
#ifndef lint
D 3
static char rcsid[] = "$Header$";
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

/*
 * Routing Table Management Daemon
 */
#include "defs.h"

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
	int doinghost = 1, timetobroadcast;

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
			 * a passive gateway or that for our only interface. 
			 * The latter is excused because we don't act as
			 * a routing information supplier and hence would
			 * time it out.  This is fair as if it's down
			 * we're cut off from the world anyway and it's
			 * not likely we'll grow any new hardware in
			 * the mean time.
			 */
			if (!(rt->rt_state & RTS_PASSIVE) &&
			    (supplier || !(rt->rt_state & RTS_INTERFACE)))
				rt->rt_timer += TIMER_RATE;
			if (rt->rt_timer >= EXPIRE_TIME)
				rt->rt_metric = HOPCNT_INFINITY;
			if (rt->rt_timer >= GARBAGE_TIME) {
				rt = rt->rt_back;
				/* Perhaps we should send a REQUEST for this route? */
				rtdelete(rt->rt_forw);
				continue;
			}
			if (rt->rt_state & RTS_CHANGED) {
				rt->rt_state &= ~RTS_CHANGED;
				/* don't send extraneous packets */
				if (!supplier || timetobroadcast)
					continue;
				msg->rip_cmd = htons(RIPCMD_RESPONSE);
D 2
				xnnet(msg->rip_nets[0].rip_dst) = 
					htonl(xnnet(((struct sockaddr_xn *)&rt->rt_dst)->sxn_addr.xn_net));
E 2
I 2
D 4
				xnnet(msg->rip_nets[0].rip_dst[0]) = 
					ns_netof(satons_addr(rt->rt_dst));
E 4
I 4
				msg->rip_nets[0].rip_dst =
					(satons_addr(rt->rt_dst)).x_net;
E 4
E 2
				msg->rip_nets[0].rip_metric =
				   	htons(min(rt->rt_metric+1, HOPCNT_INFINITY));
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
E 1
