h53712
s 00010/00005/00338
d D 7.4 88/06/27 18:59:43 bostic 49 48
c install approved copyright notice
e
s 00008/00002/00335
d D 7.3 87/12/30 11:57:40 bostic 48 47
c add Berkeley header
e
s 00002/00001/00335
d D 7.2 87/01/15 15:09:37 karels 47 46
c mark routes modified by redirects
e
s 00001/00001/00335
d D 7.1 86/06/04 23:42:21 mckusick 46 45
c 4.3BSD release version
e
s 00002/00001/00334
d D 6.19 86/04/12 22:52:38 karels 45 42
c in rtrequest, use local addr to find I/F for host if not pt-pt
e
s 00006/00002/00333
d R 6.19 86/04/12 22:48:16 karels 44 42
c in rtrequest, use local addr if route to host, not pt-pt
e
s 00002/00001/00334
d R 6.19 86/04/12 22:05:31 karels 43 42
c in rtrequest, look up gw addr if no dstaddr on route to host
e
s 00002/00001/00333
d D 6.18 86/03/21 10:56:37 karels 42 41
c oops, logic error that doesn't hit often
e
s 00003/00002/00331
d D 6.17 86/03/04 14:00:15 karels 41 40
c lint
e
s 00003/00005/00330
d D 6.16 86/02/17 17:58:57 karels 40 39
c redirect installing new route to host is dynamic, mark it
e
s 00004/00002/00331
d D 6.15 86/02/16 20:20:28 karels 39 38
c don't install gatewayed routes to ourself as a result of redirects
e
s 00002/00002/00331
d D 6.14 85/11/22 11:41:13 sklower 38 37
c get the rest of the references to rtinit.
e
s 00002/00009/00331
d D 6.13 85/11/09 15:51:09 sklower 37 36
c in rtinit, allow for deleting pt to pt hosts, by requiring
e
s 00036/00026/00304
d D 6.12 85/09/16 21:17:15 karels 36 35
c only accept redirects from current gateway; mark dynamically
c created routes; put new routes on front of chain instead of tail
e
s 00020/00001/00310
d D 6.11 85/07/18 22:34:00 sklower 35 34
c Changes to allow multiple pt to pt links to have the same local address.
e
s 00007/00001/00304
d D 6.10 85/06/08 12:27:51 mckusick 34 33
c Add copyright
e
s 00001/00002/00304
d D 6.9 85/05/27 20:32:18 karels 33 32
c free route after receiving redirect for route to interface
c (thanks, Symbolics, for making it possible to find this one!)
e
s 00007/00007/00299
d D 6.8 85/03/19 16:01:47 karels 32 31
c move net addresses from interface layer into protocols
e
s 00013/00015/00293
d D 6.7 84/09/05 17:49:50 karels 31 30
c allow variable-size hash tables, with size in global;
c spl while searching hash list (if we want it be still be there when we use it);)
c take the first route found for now
e
s 00012/00012/00296
d D 6.6 84/08/28 17:39:18 bloom 30 28
c fix header includes.  no more ../h
e
s 00009/00009/00299
d R 6.6 84/08/28 17:14:01 bloom 29 28
c Change include paths.  No more ../h.
e
s 00003/00003/00305
d D 6.5 84/07/08 15:37:22 sam 28 27
c checked in for karels; make hash index a macro so it can be turned into a mask operation
e
s 00003/00004/00305
d D 6.4 84/04/12 11:33:38 karels 27 26
c rtredirect must distinguish routes to hosts
e
s 00024/00014/00285
d D 6.3 83/12/15 15:24:07 karels 26 25
c rtalloc reallocates route if old one is not marked RTF_UP;
c rtredirect has additional argument to distinguish between host and network
c redirects
e
s 00003/00002/00296
d D 6.2 83/10/20 15:11:29 karels 25 24
c route hash values are unsigned, else hash function gives negative index
e
s 00000/00000/00298
d D 6.1 83/07/29 07:08:53 sam 24 23
c 4.2 distribution
e
s 00009/00004/00289
d D 4.22 83/06/30 01:15:23 sam 23 22
c create dynamic routes on wildcard match
c *** CHANGED *** 83/06/30 01:16:31 sam
c don't create dynamic routes on wildcard match
e
s 00017/00000/00276
d D 4.21 83/06/12 19:47:35 sam 22 21
c revamp network ioctls; add IFF_NOTRAILERS
e
s 00069/00038/00207
d D 4.20 83/05/30 18:49:40 sam 21 20
c add wildcard routing and routing statistics; also routing redirects 
c can generate new routing table entries
e
s 00003/00002/00242
d D 4.19 83/04/05 14:27:52 sam 20 19
c families are really unsigned, avoid sign extension pitfalls
e
s 00008/00001/00236
d D 4.18 83/03/15 18:24:40 sam 19 18
c socket ioctls
e
s 00040/00000/00197
d D 4.17 83/03/12 19:45:02 sam 18 17
c handle routing redirects, albeit simplisticly
e
s 00002/00001/00195
d D 4.16 83/02/10 22:01:09 sam 17 16
c remove /usr/include dependencies
e
s 00002/00001/00194
d D 4.15 83/02/02 16:45:47 sam 16 14
c fix unsigned problem in hash values
e
s 00001/00001/00194
d R 4.15 83/02/02 12:23:00 sam 15 14
c make hash's unsigned so % doesn't give negative value
e
s 00001/00001/00194
d D 4.14 82/12/14 17:13:58 sam 14 13
c typed mbufs
e
s 00002/00004/00193
d D 4.13 82/10/17 22:16:32 root 13 12
c lint
e
s 00000/00002/00197
d D 4.12 82/10/09 05:40:39 wnj 12 11
c header file dependencies fixed up and untested changes to raw interface
e
s 00000/00002/00199
d D 4.11 82/06/20 00:55:13 sam 11 10
c purge COUNT stuff now that we can use gprof
e
s 00044/00049/00157
d D 4.10 82/06/12 23:19:48 wnj 10 9
c now the routing code might wokr
e
s 00034/00042/00172
d D 4.9 82/06/06 21:21:00 wnj 9 8
c fix search loop
e
s 00006/00000/00208
d D 4.8 82/05/11 22:24:44 sam 8 7
c don't look at routes (or routes with interfaces) marked down
e
s 00004/00000/00204
d D 4.7 82/05/04 20:26:37 sam 7 6
c bounds check on afswitch array
e
s 00011/00004/00193
d D 4.6 82/03/31 20:36:58 sam 6 5
c routing tried and working, add logical host stuff
e
s 00045/00049/00152
d D 4.5 82/03/30 19:57:38 sam 5 4
c routing code now operational
e
s 00044/00052/00157
d D 4.4 82/03/30 11:32:53 sam 4 3
c with routing, but not forwarding
e
s 00052/00047/00157
d D 4.3 82/03/29 11:32:53 sam 3 2
c first cut (incomplete) at routing
e
s 00021/00011/00183
d D 4.2 82/03/28 14:23:29 sam 2 1
c convert interfaces to sockaddr's and add hooks for routing
e
s 00194/00000/00000
d D 4.1 82/03/27 22:57:39 sam 1 0
c date and time created 82/03/27 22:57:39 by sam
e
u
U
f b 
t
T
I 1
D 34
/*	%M%	%I%	%E%	*/
E 34
I 34
/*
D 46
 * Copyright (c) 1980 Regents of the University of California.
E 46
I 46
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 46
D 48
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 48
I 48
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 49
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 49
I 49
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 49
E 48
 *
 *	%W% (Berkeley) %G%
 */
E 34

D 30
#include "../h/param.h"
I 2
#include "../h/systm.h"
D 3
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/file.h"
#include "../h/inode.h"
#include "../h/buf.h"
E 3
E 2
#include "../h/mbuf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
I 22
#include "../h/dir.h"
#include "../h/user.h"
E 22
D 3
#include "../h/socketvar.h"
E 3
I 2
#include "../h/ioctl.h"
I 17
#include "../h/errno.h"
E 30
I 30
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "dir.h"
#include "user.h"
#include "ioctl.h"
#include "errno.h"
E 30

E 17
E 2
D 12
#include "../net/in.h"
#include "../net/in_systm.h"
E 12
I 2
D 30
#include "../net/if.h"
E 2
#include "../net/af.h"
#include "../net/route.h"
E 30
I 30
#include "if.h"
#include "af.h"
#include "route.h"
E 30
I 3
D 17
#include <errno.h>
E 17
E 3
D 2
#include <errno.h>
E 2

I 10
int	rttrash;		/* routes not in table but not freed */
I 21
struct	sockaddr wildcard;	/* zero valued cookie for wildcard searches */
I 31
int	rthashsize = RTHASHSIZ;	/* for netstat, etc. */
E 31

E 21
E 10
/*
 * Packet routing routines.
 */
D 10

E 10
D 4
/*
 * With much ado about nothing...
 * route the cars that climb halfway to the stars...
 */
D 3
route(ro)
E 3
I 3
allocroute(ro)
E 4
I 4
rtalloc(ro)
E 4
E 3
	register struct route *ro;
{
D 21
	register struct rtentry *rt, *rtmin;
E 21
I 21
	register struct rtentry *rt;
E 21
	register struct mbuf *m;
I 2
D 4
	register int key;
E 4
I 4
D 5
	register int hash;
E 5
I 5
D 16
	register int hash, (*match)();
E 16
I 16
D 25
	register unsigned hash;
E 25
I 25
	register u_long hash;
E 25
D 21
	register int (*match)();
E 16
E 5
E 4
E 2
	struct afhash h;
E 21
	struct sockaddr *dst = &ro->ro_dst;
I 21
D 31
	int (*match)(), doinghost;
E 31
I 31
	int (*match)(), doinghost, s;
E 31
	struct afhash h;
E 21
D 2
	int af = dst->sa_family;
E 2
I 2
D 5
	int af = dst->sa_family, doinghost;
E 5
I 5
D 20
	int af = dst->sa_family;
E 20
I 20
	u_int af = dst->sa_family;
I 21
D 31
	struct rtentry *rtmin;
E 31
	struct mbuf **table;
E 21
E 20
E 5
E 2

D 3
COUNT(ROUTE);
D 2
	if (ro->ro_ifp)		/* ??? */
E 2
I 2
	if (ro && ro->ro_rt && ro->ro_rt->rt_ifp)	/* ??? */
E 3
I 3
D 4
COUNT(ALLOCROUTE);
	if (ro->ro_rt && ro->ro_rt->rt_ifp)	/* can't happen */
E 4
I 4
D 11
COUNT(RTALLOC);
E 11
D 26
	if (ro->ro_rt && ro->ro_rt->rt_ifp)			/* XXX */
E 4
E 3
E 2
		return;
E 26
I 26
	if (ro->ro_rt && ro->ro_rt->rt_ifp && (ro->ro_rt->rt_flags & RTF_UP))
		return;				 /* XXX */
E 26
I 7
	if (af >= AF_MAX)
		return;
E 7
	(*afswitch[af].af_hash)(dst, &h);
D 4
	m = routehash[h.afh_hosthash % RTHASHSIZ];
	key = h.afh_hostkey;
E 4
I 4
D 5
	hash = h.afh_hosthash;
E 4
	rtmin = 0, doinghost = 1;
again:
I 4
	m = routehash[hash % RTHASHSIZ];
E 4
	for (; m; m = m->m_next) {
E 5
I 5
D 21
	rtmin = 0, hash = h.afh_hosthash;
	for (m = rthost[hash % RTHASHSIZ]; m; m = m->m_next) {
E 5
		rt = mtod(m, struct rtentry *);
D 3
#define	equal(a1, a2) \
	(bcmp((caddr_t)(a1), (caddr_t)(a2), sizeof(struct sockaddr)) == 0)
E 3
D 4
		if (rt->rt_key != key)
E 4
I 4
D 5
		if (rt->rt_hash[doinghost] != hash)
E 5
I 5
		if (rt->rt_hash != hash)
E 5
E 4
			continue;
I 8
		if ((rt->rt_flags & RTF_UP) == 0 ||
		    (rt->rt_ifp->if_flags & IFF_UP) == 0)
			continue;
E 8
D 5
		if (doinghost) {
I 3
#define	equal(a1, a2) \
	(bcmp((caddr_t)(a1), (caddr_t)(a2), sizeof(struct sockaddr)) == 0)
E 3
			if (!equal(&rt->rt_dst, dst))
				continue;
		} else {
			if (rt->rt_dst.sa_family != af)
				continue;
			if ((*afswitch[af].af_netmatch)(&rt->rt_dst, dst) == 0)
				continue;
		}
E 5
I 5
		if (bcmp((caddr_t)&rt->rt_dst, (caddr_t)dst, sizeof (*dst)))
			continue;
E 5
		if (rtmin == 0 || rt->rt_use < rtmin->rt_use)
			rtmin = rt;
	}
D 5
	if (rtmin) {
D 4
		ro->ro_dst = rt->rt_dst;
E 4
		ro->ro_rt = rt;
		rt->rt_refcnt++;
D 3
		return;
E 3
I 3
D 4
		return (rt->rt_flags & RTF_DIRECT);
E 4
I 4
		return;
E 5
I 5
	if (rtmin) 
		goto found;

	hash = h.afh_nethash;
E 21
I 21
D 31
	rtmin = 0;
E 31
E 21
	match = afswitch[af].af_netmatch;
D 21
	for (m = rtnet[hash % RTHASHSIZ]; m; m = m->m_next) {
E 21
I 21
	hash = h.afh_hosthash, table = rthost, doinghost = 1;
I 31
	s = splnet();
E 31
again:
D 28
	for (m = table[hash % RTHASHSIZ]; m; m = m->m_next) {
E 28
I 28
	for (m = table[RTHASHMOD(hash)]; m; m = m->m_next) {
E 28
E 21
		rt = mtod(m, struct rtentry *);
		if (rt->rt_hash != hash)
I 8
			continue;
		if ((rt->rt_flags & RTF_UP) == 0 ||
		    (rt->rt_ifp->if_flags & IFF_UP) == 0)
E 8
			continue;
D 21
		if (rt->rt_dst.sa_family != af || !(*match)(&rt->rt_dst, dst))
			continue;
E 21
I 21
		if (doinghost) {
			if (bcmp((caddr_t)&rt->rt_dst, (caddr_t)dst,
			    sizeof (*dst)))
				continue;
		} else {
			if (rt->rt_dst.sa_family != af ||
			    !(*match)(&rt->rt_dst, dst))
				continue;
		}
E 21
D 31
		if (rtmin == 0 || rt->rt_use < rtmin->rt_use)
			rtmin = rt;
E 31
I 31
		rt->rt_refcnt++;
		splx(s);
		if (dst == &wildcard)
			rtstat.rts_wildcard++;
		ro->ro_rt = rt;
		return;
E 31
E 5
E 4
E 3
	}
D 5
	if (doinghost) {
		doinghost = 0;
D 2
		m = routethash[h.afh_nethash % RTHASHSIZ];
E 2
I 2
D 4
		m = routehash[h.afh_nethash % RTHASHSIZ];
E 2
		key = h.afh_netkey;
E 4
I 4
		hash = h.afh_nethash;
E 4
		goto again;
	}
D 2
	ro->ro_ifp = 0;
E 2
	ro->ro_rt = 0;
I 3
D 4
	return (0);
E 4
I 4
	return;
E 5
I 5
D 21
found:
E 21
I 21
D 31
	if (rtmin == 0 && doinghost) {
E 31
I 31
	if (doinghost) {
E 31
		doinghost = 0;
		hash = h.afh_nethash, table = rtnet;
		goto again;
	}
	/*
	 * Check for wildcard gateway, by convention network 0.
	 */
D 31
	if (rtmin == 0 && dst != &wildcard) {
E 31
I 31
	if (dst != &wildcard) {
E 31
		dst = &wildcard, hash = 0;
		goto again;
	}
E 21
D 31
	ro->ro_rt = rtmin;
I 6
D 21
	if (rtmin)
		rtmin->rt_refcnt++;
E 21
I 21
	if (rtmin == 0) {
		rtstat.rts_unreach++;
		return;
	}
	rtmin->rt_refcnt++;
	if (dst == &wildcard)
		rtstat.rts_wildcard++;
E 31
I 31
	splx(s);
	rtstat.rts_unreach++;
E 31
E 21
E 6
E 5
E 4
E 3
}

I 3
D 4
freeroute(rt)
E 4
I 4
rtfree(rt)
E 4
	register struct rtentry *rt;
{
I 10
D 13
	register struct mbuf **mp;
E 13
E 10
I 4

E 4
D 6
COUNT(FREEROUTE);
E 6
	if (rt == 0)
D 13
		panic("freeroute");
E 13
I 13
		panic("rtfree");
E 13
	rt->rt_refcnt--;
D 10
	/* on refcnt == 0 reclaim? notify someone? */
E 10
I 10
	if (rt->rt_refcnt == 0 && (rt->rt_flags&RTF_UP) == 0) {
		rttrash--;
		(void) m_free(dtom(rt));
	}
E 10
}

I 5
D 10
#define	equal(a1, a2) \
	(bcmp((caddr_t)(a1), (caddr_t)(a2), sizeof (struct sockaddr)) == 0)
E 10
E 5
D 4
#ifdef notdef
E 3
struct rtentry *
reroute(sa)
	register struct sockaddr *sa;
{
	register struct rtentry *rt;
	register struct mbuf *m;
I 2
	register int key;
E 2
	struct afhash h;

COUNT(REROUTE);
	(*afswitch[sa->sa_family].af_hash)(sa, &h);
	m = routehash[h.afh_hosthash];
	key = h.afh_hostkey;
	for (; m; m = m->m_next) {
		rt = mtod(m, struct rtentry *);
		if (rt->rt_key != key)
			continue;
		if (equal(&rt->rt_gateway, sa))
			return (rt);
	}
	return (0);
}
I 3
#endif
E 3

E 4
/*
I 18
 * Force a routing table entry to the specified
 * destination to go through the given gateway.
 * Normally called as a result of a routing redirect
 * message from the network layer.
 *
 * N.B.: must be called at splnet or higher
 *
D 36
 * Should notify all parties with a reference to
 * the route that it's changed (so, for instance,
D 21
 * round trip time estimates may be recalculated),
E 21
I 21
 * current round trip time estimates could be flushed),
E 21
 * but we have no back pointers at the moment.
E 36
 */
D 26
rtredirect(dst, gateway)
E 26
I 26
D 36
rtredirect(dst, gateway, flags)
E 26
	struct sockaddr *dst, *gateway;
E 36
I 36
rtredirect(dst, gateway, flags, src)
	struct sockaddr *dst, *gateway, *src;
E 36
I 26
	int flags;
E 26
{
	struct route ro;
	register struct rtentry *rt;

	/* verify the gateway is directly reachable */
D 21
	if (if_ifwithnet(gateway) == 0)
E 21
I 21
D 32
	if (if_ifwithnet(gateway) == 0) {
E 32
I 32
	if (ifa_ifwithnet(gateway) == 0) {
E 32
		rtstat.rts_badredirect++;
E 21
		return;
I 21
	}
E 21
	ro.ro_dst = *dst;
D 21
	ro.ro_rt = NULL;
E 21
I 21
	ro.ro_rt = 0;
E 21
	rtalloc(&ro);
	rt = ro.ro_rt;
I 36
#define	equal(a1, a2) \
	(bcmp((caddr_t)(a1), (caddr_t)(a2), sizeof(struct sockaddr)) == 0)
E 36
	/*
I 36
	 * If the redirect isn't from our current router for this dst,
D 39
	 * it's either old or wrong.
E 39
I 39
	 * it's either old or wrong.  If it redirects us to ourselves,
	 * we have a routing loop, perhaps as a result of an interface
	 * going down recently.
E 39
	 */
D 39
	if (rt && !equal(src, &rt->rt_gateway)) {
E 39
I 39
	if ((rt && !equal(src, &rt->rt_gateway)) || ifa_ifwithaddr(gateway)) {
E 39
		rtstat.rts_badredirect++;
D 42
		rtfree(rt);
E 42
I 42
		if (rt)
			rtfree(rt);
E 42
		return;
	}
	/*
E 36
I 21
D 23
	 * Create a new entry if the lookup failed.
	 * This is necessary for hosts which use routing
	 * redirects generated by smart gateways to dynamically
	 * build the routing tables.
E 23
I 23
	 * Create a new entry if we just got back a wildcard entry
	 * or the the lookup failed.  This is necessary for hosts
	 * which use routing redirects generated by smart gateways
	 * to dynamically build the routing tables.
E 23
	 */
I 23
	if (rt &&
	    (*afswitch[dst->sa_family].af_netmatch)(&wildcard, &rt->rt_dst)) {
		rtfree(rt);
		rt = 0;
	}
E 23
	if (rt == 0) {
D 27
		rtinit(dst, gateway, RTF_GATEWAY);
E 27
I 27
D 36
		rtinit(dst, gateway, (flags & RTF_HOST) | RTF_GATEWAY);
E 36
I 36
D 38
		rtinit(dst, gateway,
E 38
I 38
D 41
		rtinit(dst, gateway, SIOCADDRT,
E 41
I 41
		rtinit(dst, gateway, (int)SIOCADDRT,
E 41
E 38
		    (flags & RTF_HOST) | RTF_GATEWAY | RTF_DYNAMIC);
E 36
E 27
		rtstat.rts_dynamic++;
		return;
	}
	/*
E 21
	 * Don't listen to the redirect if it's
	 * for a route to an interface. 
D 21
	 *
	 * Should probably create a new entry when
	 * the lookup fails.  This will be necessary
	 * when wildcard routes are added.
E 21
	 */
D 21
	if (rt == NULL || (rt->rt_flags & RTF_GATEWAY) == 0)
E 21
I 21
	if (rt->rt_flags & RTF_GATEWAY) {
D 26
		/*
		 * Smash the current notion of the gateway to
		 * this destination.  This is probably not right,
		 * as it's conceivable a flurry of redirects could
		 * cause the gateway value to fluctuate wildly during
		 * dynamic routing reconfiguration.
		 */
		rt->rt_gateway = *gateway;
		rtfree(rt);
		rtstat.rts_newgateway++;
E 21
		return;
E 26
I 26
		if (((rt->rt_flags & RTF_HOST) == 0) && (flags & RTF_HOST)) {
			/*
D 27
			 * Changing from route to gateway => route to host.
E 27
I 27
			 * Changing from route to net => route to host.
E 27
			 * Create new route, rather than smashing route to net.
			 */
D 33
			rtfree(rt);
E 33
D 38
			rtinit(dst, gateway, flags);
E 38
I 38
D 40
			rtinit(dst, gateway, SIOCADDRT, flags);
E 40
I 40
D 41
			rtinit(dst, gateway, SIOCADDRT, flags | RTF_DYNAMIC);
E 41
I 41
			rtinit(dst, gateway, (int)SIOCADDRT,
			    flags | RTF_DYNAMIC);
E 41
			rtstat.rts_dynamic++;
E 40
E 38
D 27
			rtstat.rts_newgateway++;
E 27
		} else {
			/*
			 * Smash the current notion of the gateway to
D 40
			 * this destination.  This is probably not right,
			 * as it's conceivable a flurry of redirects could
			 * cause the gateway value to fluctuate wildly during
			 * dynamic routing reconfiguration.
E 40
I 40
			 * this destination.
E 40
			 */
			rt->rt_gateway = *gateway;
I 47
			rt->rt_flags |= RTF_MODIFIED;
			rtstat.rts_newgateway++;
E 47
D 33
			rtfree(rt);
E 33
D 27
			rtstat.rts_newgateway++;
E 27
		}
I 27
D 47
		rtstat.rts_newgateway++;
E 47
E 27
E 26
D 21
	rt->rt_gateway = *gateway;
	rtfree(rt);
E 21
I 21
D 36
	}
E 36
I 36
	} else
		rtstat.rts_badredirect++;
E 36
I 33
	rtfree(rt);
E 33
I 22
}

/*
 * Routing table ioctl interface.
 */
rtioctl(cmd, data)
	int cmd;
	caddr_t data;
{

	if (cmd != SIOCADDRT && cmd != SIOCDELRT)
		return (EINVAL);
	if (!suser())
		return (u.u_error);
	return (rtrequest(cmd, (struct rtentry *)data));
E 22
E 21
}

/*
E 18
D 3
 * Routing control calls allow a routing daemon
 * to consistenly access the routing data base for updates.
E 3
I 3
 * Carry out a request to change the routing table.  Called by
D 21
 * interfaces at boot time to make their ``local routes'' known
 * and for ioctl's.
E 21
I 21
 * interfaces at boot time to make their ``local routes'' known,
 * for ioctl's, and as the result of routing redirects.
E 21
E 3
 */
D 3
rtcontrol(req, addr)
	caddr_t addr;
{
D 2
	register struct rtreq rq;
E 2
I 2
	register struct rtentry rq;
E 2
	int x = splimp(), err = 0;

COUNT(RTCONTROL);
	if (suser())
		goto bad;
D 2
	if (copyin(addr, (caddr_t)&rq, sizeof(struct rtreq))) {
E 2
I 2
	if (copyin(addr, (caddr_t)&rq, sizeof(struct rtentry))) {
E 2
		u.u_error = EFAULT;
		goto bad;
	}
	err = rtrequest(req, &rq);
bad:
	splx(x);
	return (err);
}

/*
 * Carry out a user request to modify the data base.
 */
E 3
D 10
rtrequest(req, new)
E 10
I 10
rtrequest(req, entry)
E 10
	int req;
D 9
	register struct rtentry *new;
E 9
I 9
D 10
	struct rtentry *new;
E 10
I 10
	register struct rtentry *entry;
E 10
E 9
{
D 10
	register struct rtentry *rt;
E 10
	register struct mbuf *m, **mprev;
I 36
	struct mbuf **mfirst;
E 36
I 2
D 4
	register int key;
E 4
I 4
D 5
	register int hash;
E 4
E 2
	struct sockaddr *sa = &new->rt_dst;
E 5
I 5
D 9
	register int hash, (*match)();
E 9
D 10
	register struct sockaddr *sa = &new->rt_dst;
	register struct sockaddr *gate = &new->rt_gateway;
E 10
I 10
	register struct rtentry *rt;
E 10
E 5
	struct afhash h;
I 6
D 9
	struct mbuf **oldmprev;
E 9
E 6
D 2
	int af = sa->sa_family;
E 2
I 2
D 3
	int af = sa->sa_family, doinghost;
E 3
I 3
D 10
	int af = sa->sa_family, doinghost, s, error = 0;
I 9
	int hash, (*match)();
E 10
I 10
D 20
	int af, s, error = 0, hash, (*match)();
E 20
I 20
D 25
	int s, error = 0, hash, (*match)();
E 25
I 25
	int s, error = 0, (*match)();
E 25
	u_int af;
I 25
	u_long hash;
E 25
E 20
D 32
	struct ifnet *ifp;
E 32
I 32
	struct ifaddr *ifa;
I 35
	struct ifaddr *ifa_ifwithdstaddr();
E 35
E 32
E 10
E 9
E 3
E 2

I 3
D 11
COUNT(RTREQUEST);
E 11
I 10
	af = entry->rt_dst.sa_family;
E 10
I 7
	if (af >= AF_MAX)
		return (EAFNOSUPPORT);
E 7
E 3
D 10
	(*afswitch[af].af_hash)(sa, &h);
D 4
	mprev = &routehash[h.afh_hosthash % RTHASHSIZ];
	key = h.afh_hostkey;
E 4
I 4
D 9
	hash = h.afh_hosthash;
I 5
	mprev = &rthost[hash % RTHASHSIZ];
E 5
E 4
	doinghost = 1;
E 9
I 9
	doinghost = new->rt_flags & RTF_HOST;
	if (doinghost) {
E 10
I 10
	(*afswitch[af].af_hash)(&entry->rt_dst, &h);
	if (entry->rt_flags & RTF_HOST) {
E 10
		hash = h.afh_hosthash;
D 28
		mprev = &rthost[hash % RTHASHSIZ];
E 28
I 28
		mprev = &rthost[RTHASHMOD(hash)];
E 28
	} else {
		hash = h.afh_nethash;
D 28
		mprev = &rtnet[hash % RTHASHSIZ];
E 28
I 28
		mprev = &rtnet[RTHASHMOD(hash)];
E 28
	}
	match = afswitch[af].af_netmatch;
E 9
I 3
	s = splimp();
E 3
D 9
again:
E 9
I 4
D 5
	mprev = &routehash[hash % RTHASHSIZ];
E 5
E 4
D 36
	for (; m = *mprev; mprev = &m->m_next) {
E 36
I 36
	for (mfirst = mprev; m = *mprev; mprev = &m->m_next) {
E 36
		rt = mtod(m, struct rtentry *);
D 4
		if (rt->rt_key != key)
E 4
I 4
D 5
		if (rt->rt_hash[doinghost] != hash)
E 5
I 5
		if (rt->rt_hash != hash)
E 5
E 4
			continue;
D 10
		if (doinghost) {
D 2
			if (!equal(&rt->rt_dst, dst))
E 2
I 2
D 5
			if (!equal(&rt->rt_dst, &new->rt_dst))
E 5
I 5
			if (!equal(&rt->rt_dst, sa))
E 10
I 10
		if (entry->rt_flags & RTF_HOST) {
D 36
#define	equal(a1, a2) \
	(bcmp((caddr_t)(a1), (caddr_t)(a2), sizeof (struct sockaddr)) == 0)
E 36
			if (!equal(&rt->rt_dst, &entry->rt_dst))
E 10
E 5
E 2
				continue;
		} else {
D 5
			if (rt->rt_dst.sa_family != af)
E 5
I 5
D 10
			if (rt->rt_dst.sa_family != sa->sa_family ||
			    (*match)(&rt->rt_dst, sa) == 0)
E 10
I 10
			if (rt->rt_dst.sa_family != entry->rt_dst.sa_family ||
			    (*match)(&rt->rt_dst, &entry->rt_dst) == 0)
E 10
E 5
				continue;
D 5
			if ((*afswitch[af].af_netmatch)(&rt->rt_dst, sa) == 0)
				continue;
E 5
		}
I 3
D 9
		/* require full match on deletions */
D 5
		if (req == SIOCDELRT &&
		    !equal(&rt->rt_gateway, &new->rt_gateway))
E 5
I 5
		if (req == SIOCDELRT && !equal(&rt->rt_gateway, gate))
E 5
			continue;
		/* don't keep multiple identical entries */
D 5
		if (req == SIOCADDRT &&
		    equal(&rt->rt_gateway, &new->rt_gateway)) {
E 5
I 5
		if (req == SIOCADDRT && equal(&rt->rt_gateway, gate)) {
E 5
			error = EEXIST;
			goto bad;
		}
E 3
		break;
E 9
I 9
D 10
		if (equal(&rt->rt_gateway, gate))
E 10
I 10
		if (equal(&rt->rt_gateway, &entry->rt_gateway))
E 10
			break;
E 9
	}
D 9
	if (m == 0 && doinghost) {
D 5
		doinghost = 0;
E 5
D 4
		mprev = &routehash[h.afh_nethash % RTHASHSIZ];
		key = h.afh_netkey;
E 4
I 4
		hash = h.afh_nethash;
I 6
		oldmprev = mprev;
E 6
I 5
		mprev = &rtnet[hash % RTHASHSIZ];
		match = afswitch[af].af_netmatch;
		doinghost = 0;
E 5
E 4
		goto again;
	}
I 5

E 5
D 4

E 4
D 3
	if (m == 0 && req != SIOCADDRT)
D 2
		return (ESEARCH);
E 2
I 2
		return (ESRCH);
E 3
I 3
	if (m == 0 && req != SIOCADDRT) {
		error = ESRCH;
		goto bad;
	}
I 5
found:
E 9
E 5
E 3
E 2
	switch (req) {

	case SIOCDELRT:
I 9
		if (m == 0) {
			error = ESRCH;
			goto bad;
		}
E 9
D 10
		rt->rt_flags &= ~RTF_UP;
		if (rt->rt_refcnt > 0)	/* should we notify protocols? */
D 3
			break;
		*mprev = m_free(m);
E 3
I 3
			error = EBUSY;
		else
			*mprev = m_free(m);
E 3
		break;

	case SIOCCHGRT:
I 9
		if (m == 0) {
			error = ESRCH;
			goto bad;
		}
E 9
		rt->rt_flags = new->rt_flags;
E 10
I 10
		*mprev = m->m_next;
E 10
D 9
		if (rt->rt_refcnt > 0)
E 9
I 9
		if (rt->rt_refcnt > 0) {
E 9
D 2
			return (EINUSE);
E 2
I 2
D 3
			return (EBUSY);
E 2
		if (!equal(&rt->rt_gateway, &new->rt_gateway))
E 3
I 3
D 10
			error = EBUSY;
D 5
		else if (!equal(&rt->rt_gateway, &new->rt_gateway))
E 5
I 5
D 9
		else if (!equal(&rt->rt_gateway, gate))
E 5
E 3
			goto newneighbor;
E 9
I 9
			goto bad;
		}
		if (!equal(&rt->rt_gateway, gate))
			goto changerouter;
E 10
I 10
			rt->rt_flags &= ~RTF_UP;
			rttrash++;
			m->m_next = 0;
		} else
			(void) m_free(m);
E 10
E 9
		break;

	case SIOCADDRT:
I 9
D 10
		if (m != 0) {
E 10
I 10
		if (m) {
E 10
			error = EEXIST;
			goto bad;
		}
I 10
D 32
		ifp = if_ifwithaddr(&entry->rt_gateway);
		if (ifp == 0) {
			ifp = if_ifwithnet(&entry->rt_gateway);
			if (ifp == 0) {
E 32
I 32
D 35
		ifa = ifa_ifwithaddr(&entry->rt_gateway);
E 35
I 35
D 36
		/*
		 * If we are adding a route to an interface,
		 * and the interface is a pt to pt link
		 * we should search for the destination
		 * as our clue to the interface.  Otherwise
		 * we can use the local address.
		 */
		if ((entry->rt_flags & RTF_GATEWAY)==0) {
E 36
I 36
		if ((entry->rt_flags & RTF_GATEWAY) == 0) {
			/*
			 * If we are adding a route to an interface,
			 * and the interface is a pt to pt link
			 * we should search for the destination
			 * as our clue to the interface.  Otherwise
			 * we can use the local address.
			 */
I 45
			ifa = 0;
E 45
E 36
			if (entry->rt_flags & RTF_HOST) 
				ifa = ifa_ifwithdstaddr(&entry->rt_dst);
D 45
			else
E 45
I 45
			if (ifa == 0)
E 45
				ifa = ifa_ifwithaddr(&entry->rt_gateway);
		} else {
D 36
		/* If we are adding a route to a remote net
		 * or host, the gateway may still be on the
		 * other end of a pt to pt link.
		 */
E 36
I 36
			/*
			 * If we are adding a route to a remote net
			 * or host, the gateway may still be on the
			 * other end of a pt to pt link.
			 */
E 36
			ifa = ifa_ifwithdstaddr(&entry->rt_gateway);
		}
E 35
		if (ifa == 0) {
			ifa = ifa_ifwithnet(&entry->rt_gateway);
			if (ifa == 0) {
E 32
				error = ENETUNREACH;
				goto bad;
			}
		}
E 10
E 9
D 4
		m = m_getclr(M_DONTWAIT);
E 4
I 4
D 14
		m = m_get(M_DONTWAIT);
E 14
I 14
		m = m_get(M_DONTWAIT, MT_RTABLE);
E 14
E 4
D 3
		if (m == 0)
			return (ENOBUFS);
E 3
I 3
		if (m == 0) {
			error = ENOBUFS;
D 9
			break;
E 9
I 9
			goto bad;
E 9
		}
I 10
D 36
		*mprev = m;
E 36
I 36
		m->m_next = *mfirst;
		*mfirst = m;
E 36
E 10
E 3
		m->m_off = MMINOFF;
I 4
		m->m_len = sizeof (struct rtentry);
E 4
D 6
		*mprev = m;
E 6
		rt = mtod(m, struct rtentry *);
D 10
		*rt = *new;
E 10
D 4
		rt->rt_key = h.afh_nethash | h.afh_hosthash;
E 4
I 4
D 5
		rt->rt_hash[0] = h.afh_nethash;
		rt->rt_hash[1] = h.afh_hosthash;
E 5
I 5
D 6
		rt->rt_hash = new->rt_flags & RTF_HOST ?
			h.afh_hosthash : h.afh_nethash;
E 6
I 6
D 9
		if (new->rt_flags & RTF_HOST) {
			rt->rt_hash = h.afh_hosthash;
			*oldmprev = m;
		} else {
			rt->rt_hash = h.afh_nethash;
			*mprev = m;
		}
E 9
I 9
		rt->rt_hash = hash;
D 10
		*mprev = m;
E 9
E 6
		rt->rt_use = 0;
E 10
I 10
		rt->rt_dst = entry->rt_dst;
		rt->rt_gateway = entry->rt_gateway;
D 36
		rt->rt_flags =
		    RTF_UP | (entry->rt_flags & (RTF_HOST|RTF_GATEWAY));
E 36
I 36
		rt->rt_flags = RTF_UP |
		    (entry->rt_flags & (RTF_HOST|RTF_GATEWAY|RTF_DYNAMIC));
E 36
E 10
		rt->rt_refcnt = 0;
E 5
E 4
D 9
newneighbor:
E 9
I 9
D 10
changerouter:
E 9
D 4
		rt->rt_ifp = if_ifonnetof(&new->rt_gateway);
E 4
I 4
D 5
		rt->rt_ifp = if_ifwithnet(&new->rt_gateway);
E 5
I 5
		rt->rt_ifp = if_ifwithnet(gate);
E 5
E 4
		if (rt->rt_ifp == 0)
			rt->rt_flags &= ~RTF_UP;
E 10
I 10
		rt->rt_use = 0;
D 32
		rt->rt_ifp = ifp;
E 32
I 32
		rt->rt_ifp = ifa->ifa_ifp;
E 32
E 10
I 4
D 5
		rt->rt_use = 0;
E 4
		rt->rt_refcnt = 0;
E 5
		break;
	}
D 3
	return (0);
E 3
I 3
bad:
	splx(s);
	return (error);
I 4
}

/*
 * Set up a routing table entry, normally
 * for an interface.
 */
D 37
rtinit(dst, gateway, flags)
E 37
I 37
rtinit(dst, gateway, cmd, flags)
E 37
	struct sockaddr *dst, *gateway;
D 37
	int flags;
E 37
I 37
	int cmd, flags;
E 37
{
	struct rtentry route;
I 19
D 37
	int cmd;
E 37
E 19
D 13
	struct route ro;
E 13

I 19
D 37
	if (flags == -1) {
		cmd = (int)SIOCDELRT;
		flags = 0;
	} else {
		cmd = (int)SIOCADDRT;
	}
E 37
E 19
I 10
	bzero((caddr_t)&route, sizeof (route));
E 10
	route.rt_dst = *dst;
	route.rt_gateway = *gateway;
	route.rt_flags = flags;
D 10
	route.rt_use = 0;
E 10
D 13
	(void) rtrequest(SIOCADDRT, &route);
E 13
I 13
D 19
	(void) rtrequest((int)SIOCADDRT, &route);
E 19
I 19
	(void) rtrequest(cmd, &route);
E 19
E 13
D 10
	ro.ro_rt = 0;
	ro.ro_dst = *dst;
	rtalloc(&ro);
E 10
E 4
E 3
}
E 1
