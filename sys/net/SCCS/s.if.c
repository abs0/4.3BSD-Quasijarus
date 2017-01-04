h45508
s 00004/00000/00387
d D 7.9 02/08/02 23:38:33 msokolov 56 55
c notify netmon on if_down
e
s 00009/00009/00378
d D 7.8 02/08/02 22:10:00 msokolov 55 54
c ifp <-> ifr_name conversion support more than 10 units
e
s 00001/00000/00386
d D 7.7 02/07/23 23:55:47 msokolov 54 53
c add SIOCPPPGETIPCPS
e
s 00009/00000/00377
d D 7.6 02/07/22 21:08:07 msokolov 53 52
c add ppp if ioctls
e
s 00010/00000/00367
d D 7.5 02/07/08 00:04:58 msokolov 52 51
c add variable MTU support
e
s 00010/00005/00357
d D 7.4 88/06/27 18:59:28 bostic 51 50
c install approved copyright notice
e
s 00020/00000/00342
d D 7.3 88/04/07 17:23:42 karels 50 49
c add if_qflush
e
s 00008/00002/00334
d D 7.2 87/12/30 11:57:23 bostic 49 48
c add Berkeley header
e
s 00001/00001/00335
d D 7.1 86/06/04 23:39:06 mckusick 48 47
c 4.3BSD release version
e
s 00002/00000/00334
d D 6.13 86/06/02 14:27:02 karels 47 46
c rm unused (for lint)
e
s 00010/00000/00324
d D 6.12 86/02/06 14:18:11 karels 46 45
c add LOOPBACK flag, interface metric
e
s 00001/00001/00323
d D 6.11 85/12/19 16:12:47 karels 45 44
c rm bbnnet; rm PUP
e
s 00002/00000/00322
d D 6.10 85/12/06 10:39:29 bloom 44 43
c can't let users take interfaces up and down
e
s 00006/00007/00316
d D 6.9 85/09/16 21:11:04 karels 43 42
c ctlinput takes a sockaddr; ifinit doesn't need to call per-if init yet;
c call if's ioctl when changing flags, so can notice down transition
e
s 00021/00000/00302
d D 6.8 85/07/18 22:34:14 sklower 42 41
c Changes to allow multiple pt to pt links to have the same local address.
e
s 00007/00001/00295
d D 6.7 85/06/08 12:25:59 mckusick 41 40
c Add copyright
e
s 00055/00066/00241
d D 6.6 85/04/01 13:49:51 karels 40 38
c move net addresses from interface layer into protocols;
c ifioctl calls proto PRU_CONTROL with addresses, etc.;
c watch out for magic bits in interface flags
e
s 00059/00053/00254
d R 6.6 85/03/19 15:58:59 karels 39 38
c move net addresses from interface layer into protocols;
c ifioctl calls proto PRU_CONTROL with addresses, etc.;
c watch out for magic bits in interface flags
e
s 00011/00011/00296
d D 6.5 84/08/28 17:38:54 bloom 38 35
c fix header includes.  no more ../h
e
s 00009/00009/00298
d R 6.5 84/08/28 17:13:17 bloom 37 35
c Change include paths.  No more ../h.
e
s 00006/00000/00307
d R 6.5 84/04/13 10:34:28 karels 36 35
c add ioctl to determine if broadcast address (for subnets)
e
s 00012/00000/00295
d D 6.4 84/03/22 15:10:16 karels 35 33
c new ioctls for ARP
e
s 00008/00000/00295
d R 6.4 84/03/20 15:23:11 karels 34 33
c new ARP
e
s 00001/00001/00294
d D 6.3 84/03/09 11:31:18 karels 33 32
c don't clobber unit number in ifreq on SIOCGIFxxx.
e
s 00001/00001/00294
d D 6.2 83/09/27 21:33:46 sam 32 31
c missing parameter to reset routines
e
s 00000/00000/00295
d D 6.1 83/07/29 07:08:33 sam 31 30
c 4.2 distribution
e
s 00010/00001/00285
d D 4.30 83/06/12 23:09:27 sam 30 29
c more parts to the ioctls
e
s 00046/00046/00240
d D 4.29 83/06/12 19:47:16 sam 29 28
c revamp network ioctls; add IFF_NOTRAILERS
e
s 00003/00001/00283
d D 4.28 83/05/27 13:56:29 sam 28 27
c lint and wnj changes
e
s 00009/00008/00275
d D 4.27 83/03/19 18:02:29 sam 27 26
c leave buffer pointer unchanged; null terminate interface names
e
s 00111/00000/00172
d D 4.26 83/03/15 18:24:28 sam 26 25
c socket ioctls
e
s 00003/00000/00169
d D 4.25 83/02/10 18:45:30 sam 25 24
c hz not in systm.h anymore
e
s 00006/00008/00163
d D 4.24 82/11/13 23:10:36 sam 24 23
c merge 4.1b and 4.1c
e
s 00002/00002/00169
d D 4.23 82/10/31 14:59:00 root 23 22
c s/ubareset/reset/
e
s 00001/00001/00170
d D 4.22 82/10/20 01:18:48 root 22 21
c lint
e
s 00000/00000/00171
d D 4.21 82/10/17 22:16:19 root 21 20
c lint
e
s 00003/00003/00168
d D 4.20 82/10/09 05:40:02 wnj 20 19
c header file dependencies fixed up and untested changes to raw interface
e
s 00003/00000/00168
d D 4.19 82/09/12 03:22:53 root 19 18
c if_slowtimo timeout driven
e
s 00020/00000/00148
d D 4.18 82/06/23 21:10:00 sam 18 17
c added watchdog routines
e
s 00000/00002/00148
d D 4.17 82/06/20 00:51:38 sam 17 16
c purge COUNT stuff now that we can use gprof
e
s 00000/00041/00150
d D 4.16 82/06/13 22:59:42 sam 16 15
c add class a/b/c net #'s and purge logical host kludge code
e
s 00004/00001/00187
d D 4.15 82/05/04 20:26:33 sam 15 14
c bounds check on afswitch array
e
s 00012/00000/00176
d D 4.14 82/04/24 20:37:37 sam 14 13
c icmp and ctlinput working -- missing protocol specific ctlinput's
e
s 00001/00001/00175
d D 4.13 82/03/30 19:57:17 sam 13 12
c routing code now operational
e
s 00019/00000/00157
d D 4.12 82/03/30 11:31:13 sam 12 11
c with routing, but not forwarding
e
s 00073/00018/00084
d D 4.11 82/03/28 14:20:46 sam 11 10
c convert interfaces to sockaddr's and add hooks for routing
e
s 00006/00001/00096
d D 4.10 82/03/15 04:43:05 wnj 10 9
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00003/00001/00094
d D 4.9 82/03/09 17:39:23 root 9 8
c handle broadcast packets
e
s 00004/00002/00091
d D 4.8 82/02/03 20:07:17 wnj 8 7
c if_attach now puts interfaces on the end of the q
e
s 00002/00000/00091
d D 4.7 82/02/03 10:43:44 sam 7 6
c explicit vax dependecy indicated
e
s 00022/00003/00069
d D 4.6 81/12/07 21:55:10 wnj 6 5
c added routines and bug fixes
e
s 00009/00000/00063
d D 4.5 81/12/02 16:57:51 wnj 5 4
c yet more lint
e
s 00017/00000/00046
d D 4.4 81/11/29 21:58:23 wnj 4 3
c lint and interface cleanups
e
s 00011/00013/00035
d D 4.3 81/11/26 11:55:45 wnj 3 2
c before carry to ARPAVAX
e
s 00007/00001/00041
d D 4.2 81/11/20 00:46:28 wnj 2 1
c linted
e
s 00042/00000/00000
d D 4.1 81/11/18 16:51:49 wnj 1 0
c date and time created 81/11/18 16:51:49 by wnj
e
u
U
f b 
t
T
I 1
D 41
/*	%M%	%I%	%E%	*/
E 41
I 41
/*
D 48
 * Copyright (c) 1980 Regents of the University of California.
E 48
I 48
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 48
D 49
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 49
I 49
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 51
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 51
I 51
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
E 51
E 49
 *
 *	%W% (Berkeley) %G%
 */
E 41

D 38
#include "../h/param.h"
#include "../h/systm.h"
I 11
#include "../h/socket.h"
I 14
#include "../h/protosw.h"
I 25
D 29
#include "../h/time.h"
E 29
I 29
#include "../h/dir.h"
#include "../h/user.h"
E 29
#include "../h/kernel.h"
I 26
#include "../h/ioctl.h"
#include "../h/errno.h"
E 38
I 38
#include "param.h"
I 50
#include "mbuf.h"
E 50
#include "systm.h"
#include "socket.h"
I 40
#include "socketvar.h"
E 40
#include "protosw.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "ioctl.h"
#include "errno.h"
E 38
E 26

E 25
E 14
E 11
D 3
#include "../net/inet.h"
#include "../net/inet_systm.h"
E 3
I 3
D 20
#include "../net/in.h"
#include "../net/in_systm.h"
E 20
E 3
D 38
#include "../net/if.h"
I 11
#include "../net/af.h"
E 38
I 38
#include "if.h"
#include "af.h"
E 38
E 11

I 35
#include "ether.h"
I 56
#include "netmon.h"
E 56

E 35
I 10
int	ifqmaxlen = IFQ_MAXLEN;

I 11
/*
 * Network interface utility routines.
 *
D 40
 * Routines with if_ifwith* names take sockaddr *'s as
 * parameters.  Other routines take value parameters,
 * e.g. if_ifwithnet takes the network number.
E 40
I 40
 * Routines with ifa_ifwith* names take sockaddr *'s as
 * parameters.
E 40
 */

E 11
E 10
I 6
ifinit()
{
	register struct ifnet *ifp;

	for (ifp = ifnet; ifp; ifp = ifp->if_next)
D 10
		if (ifp->if_init)
E 10
I 10
D 43
		if (ifp->if_init) {
E 10
D 11
			(*ifp->if_init)();
E 11
I 11
			(*ifp->if_init)(ifp->if_unit);
E 11
I 10
			if (ifp->if_snd.ifq_maxlen == 0)
				ifp->if_snd.ifq_maxlen = ifqmaxlen;
		}
E 43
I 43
		if (ifp->if_snd.ifq_maxlen == 0)
			ifp->if_snd.ifq_maxlen = ifqmaxlen;
E 43
I 19
	if_slowtimo();
E 19
E 10
}

I 20
D 29
#if vax
E 29
I 29
#ifdef vax
E 29
E 20
I 11
/*
 * Call each interface on a Unibus reset.
 */
E 11
ifubareset(uban)
	int uban;
{
	register struct ifnet *ifp;

	for (ifp = ifnet; ifp; ifp = ifp->if_next)
D 23
		if (ifp->if_ubareset)
			(*ifp->if_ubareset)(uban);
E 23
I 23
		if (ifp->if_reset)
D 32
			(*ifp->if_reset)(uban);
E 32
I 32
			(*ifp->if_reset)(ifp->if_unit, uban);
E 32
E 23
}
I 20
#endif
E 20

I 11
/*
 * Attach an interface to the
 * list of "active" interfaces.
 */
E 11
E 6
I 5
if_attach(ifp)
	struct ifnet *ifp;
{
I 8
	register struct ifnet **p = &ifnet;
E 8

D 17
COUNT(IF_ATTACH);
E 17
D 8
	ifp->if_next = ifnet;
	ifnet = ifp;
E 8
I 8
	while (*p)
		p = &((*p)->if_next);
	*p = ifp;
E 8
}

I 11
/*
 * Locate an interface based on a complete address.
 */
E 11
E 5
I 2
/*ARGSUSED*/
D 40
struct ifnet *
E 2
D 11
if_ifwithaddr(in)
	struct in_addr in;
E 11
I 11
if_ifwithaddr(addr)
E 40
I 40
struct ifaddr *
ifa_ifwithaddr(addr)
E 40
	struct sockaddr *addr;
E 11
{
	register struct ifnet *ifp;
I 40
	register struct ifaddr *ifa;
E 40

I 2
D 17
COUNT(IF_IFWITHADDR);
E 17
E 2
D 3
#if 0
E 3
D 11
	for (ifp = ifnet; ifp; ifp = ifp->if_next)
D 9
		if (ifp->if_addr.s_addr == in.s_addr)
E 9
I 9
		if (in.s_addr == ifp->if_addr.s_addr ||
		    (ifp->if_broadaddr.s_addr != 0 &&
		     in.s_addr == ifp->if_broadaddr.s_addr))
E 11
I 11
#define	equal(a1, a2) \
	(bcmp((caddr_t)((a1)->sa_data), (caddr_t)((a2)->sa_data), 14) == 0)
D 40
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (ifp->if_addr.sa_family != addr->sa_family)
E 40
I 40
	for (ifp = ifnet; ifp; ifp = ifp->if_next)
	    for (ifa = ifp->if_addrlist; ifa; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr.sa_family != addr->sa_family)
E 40
			continue;
D 40
		if (equal(&ifp->if_addr, addr))
E 11
E 9
			break;
E 40
I 40
		if (equal(&ifa->ifa_addr, addr))
			return (ifa);
E 40
I 11
		if ((ifp->if_flags & IFF_BROADCAST) &&
D 40
		    equal(&ifp->if_broadaddr, addr))
			break;
E 40
I 40
		    equal(&ifa->ifa_broadaddr, addr))
			return (ifa);
E 40
	}
E 11
D 3
#else
	ifp = ifnet;
#endif
E 3
D 40
	return (ifp);
E 40
I 40
	return ((struct ifaddr *)0);
E 40
}
I 42
/*
 * Locate the point to point interface with a given destination address.
 */
/*ARGSUSED*/
struct ifaddr *
ifa_ifwithdstaddr(addr)
	struct sockaddr *addr;
{
	register struct ifnet *ifp;
	register struct ifaddr *ifa;

	for (ifp = ifnet; ifp; ifp = ifp->if_next) 
	    if (ifp->if_flags & IFF_POINTOPOINT)
		for (ifa = ifp->if_addrlist; ifa; ifa = ifa->ifa_next) {
			if (ifa->ifa_addr.sa_family != addr->sa_family)
				continue;
			if (equal(&ifa->ifa_dstaddr, addr))
				return (ifa);
	}
	return ((struct ifaddr *)0);
}
E 42

I 2
D 11
/*ARGSUSED*/
E 11
I 11
/*
 * Find an interface on a specific network.  If many, choice
 * is first found.
 */
E 11
D 40
struct ifnet *
E 2
D 11
if_ifonnetof(in)
	struct in_addr in;
E 11
I 11
if_ifwithnet(addr)
E 40
I 40
struct ifaddr *
ifa_ifwithnet(addr)
E 40
	register struct sockaddr *addr;
E 11
{
	register struct ifnet *ifp;
I 40
	register struct ifaddr *ifa;
E 40
D 3
#if 0
E 3
D 11
	int net;
E 11
I 11
D 20
	register int af = addr->sa_family;
E 20
I 20
	register u_int af = addr->sa_family;
E 20
D 15
	register int (*netmatch)() = afswitch[af].af_netmatch;
E 15
I 15
	register int (*netmatch)();
E 15
E 11

I 15
	if (af >= AF_MAX)
		return (0);
	netmatch = afswitch[af].af_netmatch;
E 15
I 2
D 11
COUNT(IF_IFONNETOF);
E 2
D 3
	net = 0;			/* XXX */
E 3
I 3
	net = in.s_net;			/* XXX */
E 11
I 11
D 40
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (af != ifp->if_addr.sa_family)
E 40
I 40
	for (ifp = ifnet; ifp; ifp = ifp->if_next)
	    for (ifa = ifp->if_addrlist; ifa; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr.sa_family != addr->sa_family)
E 40
			continue;
D 40
		if ((*netmatch)(addr, &ifp->if_addr))
			break;
E 40
I 40
		if ((*netmatch)(&ifa->ifa_addr, addr))
			return (ifa);
E 40
	}
D 40
	return (ifp);
E 40
I 40
	return ((struct ifaddr *)0);
E 40
}

I 47
#ifdef notdef
E 47
/*
D 40
 * As above, but parameter is network number.
 */
struct ifnet *
if_ifonnetof(net)
	register int net;
{
	register struct ifnet *ifp;

E 11
E 3
	for (ifp = ifnet; ifp; ifp = ifp->if_next)
		if (ifp->if_net == net)
			break;
D 3
#else
	ifp = ifnet;
#endif
E 3
	return (ifp);
}

I 4
D 11
/*ARGSUSED*/
E 11
I 11
/*
E 40
 * Find an interface using a specific address family
 */
E 11
E 4
D 2
struct	ifnet ifen = { 0, 0, 1024, 0, 0 };
E 2
I 2
D 3
struct	ifnet ifen;
E 2
struct	ifnet *ifnet = &ifen;
E 3
I 3
D 40
struct ifnet *
D 11
if_gatewayfor(addr)
	struct in_addr addr;
E 11
I 11
if_ifwithaf(af)
E 40
I 40
struct ifaddr *
ifa_ifwithaf(af)
E 40
	register int af;
E 11
{
I 11
	register struct ifnet *ifp;
I 40
	register struct ifaddr *ifa;
E 40
E 11

D 11
COUNT(IF_GATEWAYFOR);
	return (0);
E 11
I 11
	for (ifp = ifnet; ifp; ifp = ifp->if_next)
D 40
		if (ifp->if_addr.sa_family == af)
			break;
	return (ifp);
E 40
I 40
	    for (ifa = ifp->if_addrlist; ifa; ifa = ifa->ifa_next)
		if (ifa->ifa_addr.sa_family == af)
			return (ifa);
	return ((struct ifaddr *)0);
E 40
I 14
}
I 47
#endif
E 47

/*
 * Mark an interface down and notify protocols of
 * the transition.
I 24
 * NOTE: must be called at splnet or eqivalent.
E 24
 */
if_down(ifp)
	register struct ifnet *ifp;
{
I 40
	register struct ifaddr *ifa;
E 40
I 19

E 19
	ifp->if_flags &= ~IFF_UP;
D 40
	pfctlinput(PRC_IFDOWN, (caddr_t)&ifp->if_addr);
E 40
I 40
	for (ifa = ifp->if_addrlist; ifa; ifa = ifa->ifa_next)
D 43
		pfctlinput(PRC_IFDOWN, (caddr_t)&ifa->ifa_addr);
E 43
I 43
		pfctlinput(PRC_IFDOWN, &ifa->ifa_addr);
I 50
	if_qflush(&ifp->if_snd);
I 56
#if NNETMON > 0
	netmon_ifevent(ifp);
#endif
E 56
}

/*
 * Flush an interface queue.
 */
if_qflush(ifq)
	register struct ifqueue *ifq;
{
	register struct mbuf *m, *n;

	n = ifq->ifq_head;
	while (m = n) {
		n = m->m_act;
		m_freem(m);
	}
	ifq->ifq_head = 0;
	ifq->ifq_tail = 0;
	ifq->ifq_len = 0;
E 50
E 43
E 40
E 14
E 11
I 4
}
I 18

/*
 * Handle interface watchdog timer routines.  Called
 * from softclock, we decrement timers (if set) and
 * call the appropriate interface routine on expiration.
 */
if_slowtimo()
{
	register struct ifnet *ifp;

D 24
	for (ifp = ifnet; ifp; ifp = ifp->if_next)
		if (ifp->if_timer && --ifp->if_timer == 0) {
			if (ifp->if_watchdog == 0) {
				printf("%s%d: no watchdog routine\n", 
					ifp->if_name, ifp->if_unit);
				continue;
			}
E 24
I 24
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (ifp->if_timer == 0 || --ifp->if_timer)
			continue;
		if (ifp->if_watchdog)
E 24
			(*ifp->if_watchdog)(ifp->if_unit);
D 24
		}
E 24
I 24
	}
E 24
I 19
D 22
	timeout(if_slowtimo, 0, hz / IFNET_SLOWHZ);
E 22
I 22
	timeout(if_slowtimo, (caddr_t)0, hz / IFNET_SLOWHZ);
I 26
}

/*
D 29
 * Service a socket ioctl request directed
 * to an interface.
E 29
I 29
 * Map interface name to
 * interface structure pointer.
E 29
 */
D 29
ifrequest(cmd, data)
	int cmd;
	caddr_t data;
E 29
I 29
struct ifnet *
ifunit(name)
	register char *name;
E 29
{
D 29
	register struct ifnet *ifp;
	register struct ifreq *ifr;
E 29
	register char *cp;
D 29
	int unit, s;
E 29
I 29
	register struct ifnet *ifp;
D 55
	int unit;
E 55
I 55
	register int unit = 0, namelen;
E 55
E 29

D 29
	ifr = (struct ifreq *)data;
	for (cp = ifr->ifr_name; *cp; cp++)
E 29
I 29
	for (cp = name; cp < name + IFNAMSIZ && *cp; cp++)
E 29
		if (*cp >= '0' && *cp <= '9')
			break;
D 29
	if (*cp == 0)
		return (ENXIO);		/* couldn't find unit */
E 29
I 29
	if (*cp == '\0' || cp == name + IFNAMSIZ)
		return ((struct ifnet *)0);
E 29
D 33
	unit = *cp - '0', *cp = 0;
E 33
I 33
D 55
	unit = *cp - '0';
E 55
I 55
	namelen = cp - name;
	while (cp < name + IFNAMSIZ && *cp) {
		if (*cp < '0' || *cp > '9')
			return ((struct ifnet *)0);
		unit = unit * 10 + *cp++ - '0';
	}
E 55
E 33
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
D 28
		if (bcmp(ifp->if_name, ifr->ifr_name, cp - ifr->ifr_name))
E 28
I 28
D 29
		if (bcmp(ifp->if_name, ifr->ifr_name,
		    (unsigned)(cp - ifr->ifr_name)))
E 29
I 29
D 55
		if (bcmp(ifp->if_name, name, (unsigned)(cp - name)))
E 55
I 55
		if (bcmp(ifp->if_name, name, namelen))
E 55
E 29
E 28
			continue;
		if (unit == ifp->if_unit)
D 29
			goto found;
E 29
I 29
			break;
E 29
	}
D 29
	return (ENXIO);
E 29
I 29
	return (ifp);
}
E 29

D 29
found:
E 29
I 29
/*
 * Interface ioctls.
 */
D 40
ifioctl(cmd, data)
E 40
I 40
ifioctl(so, cmd, data)
	struct socket *so;
E 40
	int cmd;
	caddr_t data;
{
	register struct ifnet *ifp;
	register struct ifreq *ifr;

E 29
	switch (cmd) {

D 29
	case SIOCGIFADDR:
		ifr->ifr_addr = ifp->if_addr;
		break;
E 29
I 29
	case SIOCGIFCONF:
		return (ifconf(cmd, data));
I 35

D 43
#if defined(INET) && NETHER > 0
E 43
I 43
D 45
#if (defined(INET) || defined(BBNNET)) && NETHER > 0
E 45
I 45
#if defined(INET) && NETHER > 0
E 45
E 43
	case SIOCSARP:
	case SIOCDARP:
		if (!suser())
			return (u.u_error);
		/* FALL THROUGH */
	case SIOCGARP:
		return (arpioctl(cmd, data));
#endif
E 35
E 29
D 40

	case SIOCSIFADDR:
D 29
		if_rtinit(ifp, -1);	/* delete previous route */
		s = splimp();
		ifp->if_addr = ifr->ifr_addr;
		(*ifp->if_init)(unit);
		splx(s);
E 29
I 29
	case SIOCSIFFLAGS:
	case SIOCSIFDSTADDR:
		if (!suser())
			return (u.u_error);
E 29
		break;
E 40
I 29
	}
	ifr = (struct ifreq *)data;
	ifp = ifunit(ifr->ifr_name);
	if (ifp == 0)
		return (ENXIO);
	switch (cmd) {
E 29

I 29
D 40
	case SIOCGIFADDR:
		ifr->ifr_addr = ifp->if_addr;
		break;

E 29
	case SIOCGIFDSTADDR:
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0)
			return (EINVAL);
		ifr->ifr_dstaddr = ifp->if_dstaddr;
		break;

E 40
D 29
	case SIOCSIFDSTADDR:
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0)
			return (EINVAL);
		s = splimp();
		ifp->if_dstaddr = ifr->ifr_dstaddr;
		splx(s);
		break;

E 29
	case SIOCGIFFLAGS:
		ifr->ifr_flags = ifp->if_flags;
		break;

I 46
	case SIOCGIFMETRIC:
		ifr->ifr_metric = ifp->if_metric;
		break;

I 52
	case SIOCGIFMTU:
		ifr->ifr_mtu = ifp->if_mtu;
		break;

E 52
E 46
I 30
	case SIOCSIFFLAGS:
I 44
		if (!suser())
			return (u.u_error);
E 44
		if (ifp->if_flags & IFF_UP && (ifr->ifr_flags & IFF_UP) == 0) {
			int s = splimp();
			if_down(ifp);
			splx(s);
		}
D 40
		ifp->if_flags = ifr->ifr_flags;
E 40
I 40
		ifp->if_flags = (ifp->if_flags & IFF_CANTCHANGE) |
			(ifr->ifr_flags &~ IFF_CANTCHANGE);
I 43
		if (ifp->if_ioctl)
			(void) (*ifp->if_ioctl)(ifp, cmd, data);
I 46
		break;

	case SIOCSIFMETRIC:
		if (!suser())
			return (u.u_error);
		ifp->if_metric = ifr->ifr_metric;
E 46
E 43
E 40
		break;
I 52

	/* The if may or may not handle these to its ability */
	case SIOCSIFMTU:
I 53
	case SIOCPPPSRESTIM:
	case SIOCPPPSMAXCONF:
	case SIOCPPPSMAXTERM:
	case SIOCPPPSPECACT:
E 53
		if (!suser())
			return (u.u_error);
I 53
	case SIOCPPPGETSTATE:
	case SIOCPPPGETFLAGS:
	case SIOCPPPGRESTIM:
	case SIOCPPPGMAXCONF:
	case SIOCPPPGMAXTERM:
I 54
	case SIOCPPPGETIPCPS:
E 54
E 53
		return((*ifp->if_ioctl)(ifp, cmd, data));
E 52

E 30
D 29
	case SIOCSIFFLAGS:
		if ((ifr->ifr_flags & IFF_UP) == 0 &&
		    (ifp->if_flags & IFF_UP)) {
			s = splimp();
			if_down(ifp);
			splx(s);
		}
		ifp->if_flags = ifr->ifr_flags;
		break;

E 29
	default:
D 29
		return (EINVAL);
E 29
I 29
D 40
		if (ifp->if_ioctl == 0)
E 40
I 40
		if (so->so_proto == 0)
E 40
			return (EOPNOTSUPP);
D 30
		return ((*ifp->if_ioctl)(cmd, data));
E 30
I 30
D 40
		return ((*ifp->if_ioctl)(ifp, cmd, data));
E 40
I 40
		return ((*so->so_proto->pr_usrreq)(so, PRU_CONTROL,
			cmd, data, ifp));
E 40
E 30
E 29
	}
	return (0);
}

/*
 * Return interface configuration
 * of system.  List may be used
 * in later ioctl's (above) to get
 * other information.
 */
I 28
/*ARGSUSED*/
E 28
ifconf(cmd, data)
	int cmd;
	caddr_t data;
{
	register struct ifconf *ifc = (struct ifconf *)data;
	register struct ifnet *ifp = ifnet;
I 40
	register struct ifaddr *ifa;
E 40
D 27
	register char *cp;
	struct ifreq ifr;
E 27
I 27
D 55
	register char *cp, *ep;
E 55
	struct ifreq ifr, *ifrp;
E 27
	int space = ifc->ifc_len, error = 0;

I 27
	ifrp = ifc->ifc_req;
D 55
	ep = ifr.ifr_name + sizeof (ifr.ifr_name) - 2;
E 55
E 27
	for (; space > sizeof (ifr) && ifp; ifp = ifp->if_next) {
D 27
		bcopy(ifp->if_name, ifr.ifr_name, sizeof (ifr.ifr_name));
		for (cp = ifr.ifr_name; *cp; cp++)
E 27
I 27
D 55
		bcopy(ifp->if_name, ifr.ifr_name, sizeof (ifr.ifr_name) - 2);
		for (cp = ifr.ifr_name; cp < ep && *cp; cp++)
E 27
			;
D 27
		*cp = '0' + ifp->if_unit;
E 27
I 27
		*cp++ = '0' + ifp->if_unit; *cp = '\0';
E 55
I 55
		sprintf(ifr.ifr_name, "%s%d", ifp->if_name, ifp->if_unit);
E 55
E 27
D 40
		ifr.ifr_addr = ifp->if_addr;
D 27
		error = copyout((caddr_t)&ifr, ifc->ifc_buf, sizeof (ifr));
E 27
I 27
		error = copyout((caddr_t)&ifr, (caddr_t)ifrp, sizeof (ifr));
E 27
		if (error)
			break;
D 27
		space -= sizeof (ifr);
		ifc->ifc_req++;
E 27
I 27
		space -= sizeof (ifr), ifrp++;
E 40
I 40
		if ((ifa = ifp->if_addrlist) == 0) {
			bzero((caddr_t)&ifr.ifr_addr, sizeof(ifr.ifr_addr));
			error = copyout((caddr_t)&ifr, (caddr_t)ifrp, sizeof (ifr));
			if (error)
				break;
			space -= sizeof (ifr), ifrp++;
		} else 
		    for ( ; space > sizeof (ifr) && ifa; ifa = ifa->ifa_next) {
			ifr.ifr_addr = ifa->ifa_addr;
			error = copyout((caddr_t)&ifr, (caddr_t)ifrp, sizeof (ifr));
			if (error)
				break;
			space -= sizeof (ifr), ifrp++;
		}
E 40
E 27
	}
	ifc->ifc_len -= space;
	return (error);
E 26
E 22
E 19
}
E 18
D 16

I 11
/*
 * Formulate an Internet address from network + host.  Used in
 * building addresses stored in the ifnet structure.
 */
E 11
struct in_addr
if_makeaddr(net, host)
	int net, host;
{
	u_long addr;

	if (net < 128)
D 6
		addr = (host << 8) | net;
E 6
I 6
		addr = (net << 24) | host;
E 6
	else if (net < 65536)
D 6
		addr = (host << 16) | net;
E 6
I 6
		addr = (net << 16) | host;
E 6
	else
D 6
		addr = (host << 24) | net;
E 6
I 6
		addr = (net << 8) | host;
I 7
#ifdef vax
E 7
E 6
	addr = htonl(addr);
I 7
#endif
E 7
	return (*(struct in_addr *)&addr);
E 4
}
I 12

/*
 * Initialize an interface's routing
 * table entry according to the network.
 * INTERNET SPECIFIC.
 */
if_rtinit(ifp, flags)
	register struct ifnet *ifp;
	int flags;
{
	struct sockaddr_in sin;

	if (ifp->if_flags & IFF_ROUTE)
		return;
	bzero((caddr_t)&sin, sizeof (sin));
	sin.sin_family = AF_INET;
	sin.sin_addr = if_makeaddr(ifp->if_net, 0);
D 13
	rtinit(&sin, &sin, flags);
E 13
I 13
	rtinit(&sin, &ifp->if_addr, flags);
E 13
}
E 16
E 12
E 3
E 1
