h34459
s 00010/00005/00568
d D 7.7 88/06/29 17:06:26 bostic 31 30
c install approved copyright notice
e
s 00008/00002/00565
d D 7.6 87/12/07 17:45:03 bostic 30 29
c use Berkeley specific header
e
s 00001/00001/00566
d D 7.5 87/10/30 08:25:31 bostic 29 28
c keep USETRAILERS from SIOCSARP
e
s 00010/00004/00557
d D 7.4 87/10/06 12:10:47 karels 28 25
c don't send trailer replies to IP replies that appear extraneous
c (ps300's loop otherwise!)
e
s 00010/00004/00557
d R 7.4 87/10/06 11:53:41 karels 27 25
c don't send trailer replies to IP replies that appear extraneous
c (ps300's loop otherwise!)
e
s 00006/00002/00529
d D 7.1.1.1 87/02/27 16:07:13 karels 26 23
c minimal fixes to update 4.3 distribution
e
s 00010/00005/00551
d D 7.3 87/01/10 16:37:49 karels 25 24
c use the right type for mask replies!
e
s 00033/00008/00523
d D 7.2 86/12/16 16:16:14 karels 24 23
c block reentrance of arpinput/arptnew with splimp;
c larger tables for gateway (shouldn't use 2-dimensional array!);
c use loopback even if not up yet, for configuration at boot time
c when primary interface doesn't hear itself talk.
e
s 00001/00001/00530
d D 7.1 86/06/05 00:24:24 mckusick 23 22
c 4.3BSD release version
e
s 00001/00001/00530
d D 6.18 86/03/04 13:53:05 karels 22 21
c lint
e
s 00002/00002/00529
d D 6.17 86/02/23 23:23:13 karels 21 20
c lint
e
s 00015/00010/00516
d D 6.16 86/02/18 09:48:26 karels 20 19
c translate my address if necessary (used to work because
c wwe put ourselves into the table when addressed)
e
s 00001/00001/00525
d D 6.15 86/02/12 16:45:16 karels 19 18
c use most recent address rather than least recent (possible
c robustness/security problem)
e
s 00171/00063/00355
d D 6.14 86/01/13 16:52:01 karels 18 17
c separate ARP header from IP-specific portion; break out IP
c portion of the input code; add trailer negotiation
e
s 00005/00003/00413
d D 6.13 85/09/16 22:41:56 karels 17 16
c more buckets; adjust input packets for presence of interface pointer;
c fix logic error if all entries in a bucket are new
e
s 00000/00001/00416
d D 6.12 85/08/26 09:01:49 walsh 16 15
c fix lint error
e
s 00001/00016/00416
d D 6.11 85/08/22 09:37:09 walsh 15 14
c removed old 3 bytes ethernet<->IP address mapping scheme based on oldmap.
e
s 00007/00001/00425
d D 6.10 85/06/08 12:36:22 mckusick 14 13
c Add copyright
e
s 00008/00008/00418
d D 6.9 85/04/24 22:54:37 karels 13 12
c correct the fix for uninitialized variable after dup IP address
e
s 00053/00035/00373
d D 6.8 85/04/16 09:55:59 karels 12 11
c purge struct ether_addr (not portable)
e
s 00013/00013/00395
d D 6.7 85/03/18 17:15:42 karels 11 10
c move net address to protocol layer; keep a copy of IP address
c in arpcom; ETHERPUP_xxTYPE => ETHERTYPE_xx
e
s 00012/00012/00396
d D 6.6 84/08/29 15:35:35 bloom 10 9
c Include file changes.  No more ../h
e
s 00006/00001/00402
d D 6.5 84/07/08 15:39:11 sam 9 8
c checked in for karels; don't return looutput status as mbuf has already 
c been freed (corrects lost mbuf problem)
e
s 00142/00130/00261
d D 6.4 84/03/22 15:11:22 karels 8 7
c new version of ARP (from sun); allows permanent, "published" entries
e
s 00001/00001/00390
d D 6.3 83/12/15 15:27:43 karels 7 6
c len of arp packet doesn't include ethernet header
e
s 00020/00006/00371
d D 6.2 83/08/28 00:35:51 sam 6 4
c insert IFF_NOARP flag and make old address mapping range a 
c patchable constant -- will this keep those cretins quiet?
e
s 00015/00006/00371
d R 6.2 83/08/28 00:21:43 sam 5 4
c listen to IFF_NOARP to silence all those cretins
e
s 00000/00000/00377
d D 6.1 83/07/29 07:10:57 sam 4 3
c 4.2 distribution
e
s 00005/00002/00372
d D 4.3 83/06/13 23:03:10 sam 3 2
c lint
e
s 00034/00022/00340
d D 4.2 83/05/27 13:45:48 sam 2 1
c lint
e
s 00362/00000/00000
d D 4.1 83/03/15 13:19:18 sam 1 0
c date and time created 83/03/15 13:19:18 by sam
e
u
U
f b 
t
T
I 1
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
D 23
 * Copyright (c) 1982 Regents of the University of California.
E 23
I 23
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 23
D 30
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 30
I 30
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 31
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 31
I 31
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
E 31
E 30
 *
 *	%W% (Berkeley) %G%
 */
E 14

/*
 * Ethernet address resolution protocol.
I 24
 * TODO:
 *	run at splnet (add ARP protocol intr.)
 *	link entries onto hash chains, keep free list
 *	add "inuse/lock" bit (or ref. count) along with valid bit
E 24
 */

D 10
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/socket.h"
#include "../h/time.h"
#include "../h/kernel.h"
I 2
#include "../h/errno.h"
I 8
#include "../h/ioctl.h"
E 10
I 10
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "socket.h"
#include "time.h"
#include "kernel.h"
#include "errno.h"
#include "ioctl.h"
I 18
#include "syslog.h"
E 18
E 10
E 8
E 2

#include "../net/if.h"
D 10
#include "../netinet/in.h"
I 8
#include "../netinet/in_systm.h"
#include "../netinet/ip.h"
E 8
#include "../netinet/if_ether.h"
E 10
I 10
#include "in.h"
#include "in_systm.h"
#include "ip.h"
#include "if_ether.h"
E 10

I 24
#ifdef GATEWAY
#define	ARPTAB_BSIZ	16		/* bucket size */
#define	ARPTAB_NB	37		/* number of buckets */
#else
E 24
D 8

/*
 * Internet to ethernet address resolution table.
 */
struct	arptab {
	struct	in_addr at_iaddr;	/* internet address */
	u_char	at_enaddr[6];		/* ethernet address */
	struct	mbuf *at_hold;		/* last packet until resolved/timeout */
	u_char	at_timer;		/* minutes since last reference */
	u_char	at_flags;		/* flags */
};
/* at_flags field values */
#define	ATF_INUSE	1		/* entry in use */
#define ATF_COM		2		/* completed entry (enaddr valid) */

E 8
D 17
#define	ARPTAB_BSIZ	5		/* bucket size */
E 17
I 17
#define	ARPTAB_BSIZ	9		/* bucket size */
E 17
#define	ARPTAB_NB	19		/* number of buckets */
I 24
#endif
E 24
#define	ARPTAB_SIZE	(ARPTAB_BSIZ * ARPTAB_NB)
struct	arptab arptab[ARPTAB_SIZE];
I 8
int	arptab_size = ARPTAB_SIZE;	/* for arp command */
E 8

I 18
/*
 * ARP trailer negotiation.  Trailer protocol is not IP specific,
 * but ARP request/response use IP addresses.
 */
#define ETHERTYPE_IPTRAILERS ETHERTYPE_TRAIL

E 18
#define	ARPTAB_HASH(a) \
D 18
	((short)((((a) >> 16) ^ (a)) & 0x7fff) % ARPTAB_NB)
E 18
I 18
	((u_long)(a) % ARPTAB_NB)
E 18

#define	ARPTAB_LOOK(at,addr) { \
	register n; \
	at = &arptab[ARPTAB_HASH(addr) * ARPTAB_BSIZ]; \
	for (n = 0 ; n < ARPTAB_BSIZ ; n++,at++) \
		if (at->at_iaddr.s_addr == addr) \
			break; \
	if (n >= ARPTAB_BSIZ) \
D 18
		at = 0; }
E 18
I 18
		at = 0; \
}
E 18

D 8
struct	arpcom *arpcom;		/* chain of active ether interfaces */
E 8
D 18
int	arpt_age;		/* aging timer */

E 18
/* timer values */
#define	ARPT_AGE	(60*1)	/* aging timer, 1 min. */
#define	ARPT_KILLC	20	/* kill completed entry in 20 mins. */
#define	ARPT_KILLI	3	/* kill incomplete entry in 3 minutes */

D 8
u_char	etherbroadcastaddr[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
E 8
I 8
D 12
struct ether_addr etherbroadcastaddr = {{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }};
E 12
I 12
u_char	etherbroadcastaddr[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
E 12
E 8
extern struct ifnet loif;

D 6
#define	OLDMAP	1		/* if LNA > 1023 use old 3COM mapping */
E 6
I 6
/*
D 15
 * Local addresses in the range oldmap to infinity are
 * mapped according to the old mapping scheme.  That is,
 * mapping of Internet to Ethernet addresses is performed
 * by taking the high three bytes of the network interface's
 * address and the low three bytes of the local address part.
 * This only allows boards from the same manufacturer to
 * communicate unless the on-board address is overridden
 * (not possible in many manufacture's hardware).
 *
 * NB: setting oldmap to zero completely disables ARP
 *     (i.e. identical to setting IFF_NOARP with an ioctl).
 */
int	oldmap = 1024;
E 6

/*
E 15
D 8
 * Attach an ethernet interface to the list "arpcom" where
 * arptimer() can find it.  If first time 
 * initialization, start arptimer().
 */
arpattach(ac)
	register struct arpcom *ac;
{
	register struct arpcom *acp;

	for (acp = arpcom; acp != (struct arpcom *)0; acp = acp->ac_ac)
		if (acp == ac)		/* if already on list */
			return;
	ac->ac_ac = arpcom;
	arpcom = ac;
	if (arpcom->ac_ac == 0)		/* very first time */
		arptimer();
}

/*
E 8
 * Timeout routine.  Age arp_tab entries once a minute.
 */
arptimer()
{
D 2
	register struct arpcom *ac;
E 2
	register struct arptab *at;
	register i;

D 2
	timeout(arptimer, 0, hz);
E 2
I 2
D 18
	timeout(arptimer, (caddr_t)0, hz);
E 2
D 8
#ifdef notdef
	if (++arpt_sanity > ARPT_SANITY) {
I 2
		register struct arpcom *ac;

E 2
		/*
		 * Randomize sanity timer based on my host address.
		 * Ask who has my own address;  if someone else replies,
		 * then they are impersonating me.
		 */
		arpt_sanity = arpcom->ac_enaddr[5] & 0x3f;
		for (ac = arpcom; ac != (struct arpcom *)-1; ac = ac->ac_ac)
			arpwhohas(ac, &((struct sockaddr_in *)
			    &ac->ac_if.if_addr)->sin_addr);
	}
#endif
E 8
	if (++arpt_age > ARPT_AGE) {
		arpt_age = 0;
		at = &arptab[0];
		for (i = 0; i < ARPTAB_SIZE; i++, at++) {
D 8
			if (at->at_flags == 0)
E 8
I 8
			if (at->at_flags == 0 || (at->at_flags & ATF_PERM))
E 8
				continue;
			if (++at->at_timer < ((at->at_flags&ATF_COM) ?
			    ARPT_KILLC : ARPT_KILLI))
				continue;
			/* timer has expired, clear entry */
			arptfree(at);
		}
E 18
I 18
	timeout(arptimer, (caddr_t)0, ARPT_AGE * hz);
	at = &arptab[0];
	for (i = 0; i < ARPTAB_SIZE; i++, at++) {
		if (at->at_flags == 0 || (at->at_flags & ATF_PERM))
			continue;
		if (++at->at_timer < ((at->at_flags&ATF_COM) ?
		    ARPT_KILLC : ARPT_KILLI))
			continue;
		/* timer has expired, clear entry */
		arptfree(at);
E 18
	}
}

/*
 * Broadcast an ARP packet, asking who has addr on interface ac.
 */
arpwhohas(ac, addr)
	register struct arpcom *ac;
	struct in_addr *addr;
{
	register struct mbuf *m;
	register struct ether_header *eh;
	register struct ether_arp *ea;
	struct sockaddr sa;

	if ((m = m_get(M_DONTWAIT, MT_DATA)) == NULL)
D 2
		return (1);
E 2
I 2
D 3
		return (ENOBUFS);
E 3
I 3
D 8
		return;
E 8
I 8
D 21
		return (1);
E 21
I 21
		return;
E 21
E 8
E 3
E 2
D 7
	m->m_len = sizeof *ea + sizeof *eh;
E 7
I 7
	m->m_len = sizeof *ea;
E 7
	m->m_off = MMAXOFF - m->m_len;
	ea = mtod(m, struct ether_arp *);
	eh = (struct ether_header *)sa.sa_data;
D 2
	bzero((caddr_t)ea, sizeof *ea);
	bcopy(etherbroadcastaddr, eh->ether_dhost, sizeof etherbroadcastaddr);
E 2
I 2
	bzero((caddr_t)ea, sizeof (*ea));
D 8
	bcopy((caddr_t)etherbroadcastaddr, (caddr_t)eh->ether_dhost,
	   sizeof (etherbroadcastaddr));
E 8
I 8
D 12
	eh->ether_dhost = etherbroadcastaddr;
E 12
I 12
	bcopy((caddr_t)etherbroadcastaddr, (caddr_t)eh->ether_dhost,
	    sizeof(eh->ether_dhost));
E 12
E 8
E 2
D 11
	eh->ether_type = ETHERPUP_ARPTYPE;	/* if_output will swap */
E 11
I 11
	eh->ether_type = ETHERTYPE_ARP;		/* if_output will swap */
E 11
	ea->arp_hrd = htons(ARPHRD_ETHER);
D 11
	ea->arp_pro = htons(ETHERPUP_IPTYPE);
E 11
I 11
	ea->arp_pro = htons(ETHERTYPE_IP);
E 11
D 8
	ea->arp_hln = sizeof ea->arp_sha;	/* hardware address length */
	ea->arp_pln = sizeof ea->arp_spa;	/* protocol address length */
E 8
I 8
D 12
	ea->arp_hln = sizeof arp_sha(ea);	/* hardware address length */
	ea->arp_pln = sizeof arp_spa(ea);	/* protocol address length */
E 12
I 12
	ea->arp_hln = sizeof(ea->arp_sha);	/* hardware address length */
	ea->arp_pln = sizeof(ea->arp_spa);	/* protocol address length */
E 12
E 8
	ea->arp_op = htons(ARPOP_REQUEST);
D 2
	bcopy(ac->ac_enaddr, ea->arp_sha, sizeof ea->arp_sha);
E 2
I 2
D 8
	bcopy((caddr_t)ac->ac_enaddr, (caddr_t)ea->arp_sha,
	   sizeof (ea->arp_sha));
E 2
	bcopy((caddr_t)&((struct sockaddr_in *)&ac->ac_if.if_addr)->sin_addr,
D 2
	    ea->arp_spa, sizeof ea->arp_spa);
	bcopy((caddr_t)addr, ea->arp_tpa, sizeof ea->arp_tpa);
E 2
I 2
	   (caddr_t)ea->arp_spa, sizeof (ea->arp_spa));
	bcopy((caddr_t)addr, (caddr_t)ea->arp_tpa, sizeof (ea->arp_tpa));
E 8
I 8
D 12
	arp_sha(ea) = ac->ac_enaddr;
D 11
	arp_spa(ea) = ((struct sockaddr_in *)&ac->ac_if.if_addr)->sin_addr;
E 11
I 11
	arp_spa(ea) = ac->ac_ipaddr;
E 11
	arp_tpa(ea) = *addr;
E 12
I 12
	bcopy((caddr_t)ac->ac_enaddr, (caddr_t)ea->arp_sha,
	   sizeof(ea->arp_sha));
	bcopy((caddr_t)&ac->ac_ipaddr, (caddr_t)ea->arp_spa,
	   sizeof(ea->arp_spa));
	bcopy((caddr_t)addr, (caddr_t)ea->arp_tpa, sizeof(ea->arp_tpa));
E 12
E 8
E 2
	sa.sa_family = AF_UNSPEC;
D 3
	return ((*ac->ac_if.if_output)(&ac->ac_if, m, &sa));
E 3
I 3
D 8
	(void) (*ac->ac_if.if_output)(&ac->ac_if, m, &sa);
E 8
I 8
D 21
	return ((*ac->ac_if.if_output)(&ac->ac_if, m, &sa));
E 21
I 21
	(*ac->ac_if.if_output)(&ac->ac_if, m, &sa);
E 21
E 8
E 3
}

I 26
int	useloopback = 1;	/* use loopback interface for local traffic */

E 26
I 24
int	useloopback = 1;	/* use loopback interface for local traffic */

E 24
/*
 * Resolve an IP address into an ethernet address.  If success, 
D 18
 * desten is filled in and 1 is returned.  If there is no entry
 * in arptab, set one up and broadcast a request 
 * for the IP address;  return 0.  Hold onto this mbuf and 
 * resend it once the address is finally resolved.
E 18
I 18
 * desten is filled in.  If there is no entry in arptab,
 * set one up and broadcast a request for the IP address.
 * Hold onto this mbuf and resend it once the address
 * is finally resolved.  A return value of 1 indicates
 * that desten has been filled in and the packet should be sent
 * normally; a 0 return indicates that the packet has been
 * taken over here, either now or for later transmission.
E 18
 *
 * We do some (conservative) locking here at splimp, since
 * arptab is also altered from input interrupt service (ecintr/ilintr
D 11
 * calls arpinput when ETHERPUP_ARPTYPE packets come in).
E 11
I 11
 * calls arpinput when ETHERTYPE_ARP packets come in).
E 11
 */
D 18
arpresolve(ac, m, destip, desten)
E 18
I 18
arpresolve(ac, m, destip, desten, usetrailers)
E 18
	register struct arpcom *ac;
	struct mbuf *m;
	register struct in_addr *destip;
D 8
	register u_char *desten;
E 8
I 8
D 12
	register struct ether_addr *desten;
E 12
I 12
	register u_char *desten;
I 18
	int *usetrailers;
E 18
E 12
E 8
{
	register struct arptab *at;
I 6
D 24
	register struct ifnet *ifp;
E 24
I 8
D 16
	register int i;
E 16
E 8
E 6
D 2
	register i;
E 2
	struct sockaddr_in sin;
D 24
	int s, lna;
E 24
I 24
	u_long lna;
	int s;
E 24

I 18
	*usetrailers = 0;
E 18
D 11
	lna = in_lnaof(*destip);
	if (lna == INADDR_ANY) {	/* broadcast address */
E 11
I 11
	if (in_broadcast(*destip)) {	/* broadcast address */
E 11
D 2
		bcopy(etherbroadcastaddr, desten, sizeof etherbroadcastaddr);
E 2
I 2
D 8
		bcopy((caddr_t)etherbroadcastaddr, (caddr_t)desten,
		   sizeof (etherbroadcastaddr));
E 8
I 8
D 12
		*desten = etherbroadcastaddr;
E 12
I 12
		bcopy((caddr_t)etherbroadcastaddr, (caddr_t)desten,
		    sizeof(etherbroadcastaddr));
E 12
E 8
E 2
		return (1);
	}
I 11
	lna = in_lnaof(*destip);
E 11
D 6
	if (destip->s_addr == ((struct sockaddr_in *)&ac->ac_if.if_addr)->
	    sin_addr.s_addr) {			/* if for us, use lo driver */
E 6
I 6
D 24
	ifp = &ac->ac_if;
E 24
D 20
	/* if for us, then use software loopback driver */
D 11
	if (destip->s_addr ==
D 8
	    ((struct sockaddr_in *)&ifp->if_addr)-> sin_addr.s_addr) {
E 8
I 8
	    ((struct sockaddr_in *)&ifp->if_addr)-> sin_addr.s_addr &&
E 11
I 11
	if (destip->s_addr == ac->ac_ipaddr.s_addr &&
E 11
	    (loif.if_flags & IFF_UP)) {
E 8
E 6
		sin.sin_family = AF_INET;
		sin.sin_addr = *destip;
D 2
		looutput(&loif, m, &sin);
		return (0);
E 2
I 2
D 9
		return (looutput(&loif, m, (struct sockaddr *)&sin));
E 9
I 9
		(void) looutput(&loif, m, (struct sockaddr *)&sin);
		/*
D 18
		 * We really don't want to indicate failure,
		 * but the packet has already been sent and freed.
E 18
I 18
		 * The packet has already been sent and freed.
E 18
		 */
		return (0);
E 20
I 20
	/* if for us, use software loopback driver if up */
	if (destip->s_addr == ac->ac_ipaddr.s_addr) {
D 24
D 26
		if (loif.if_flags & IFF_UP) {
E 26
I 26
		if (useloopback) {
E 26
E 24
I 24
		/*
		 * This test used to be
		 *	if (loif.if_flags & IFF_UP)
		 * It allowed local traffic to be forced
		 * through the hardware by configuring the loopback down.
		 * However, it causes problems during network configuration
		 * for boards that can't receive packets they send.
		 * It is now necessary to clear "useloopback"
		 * to force traffic out to the hardware.
		 */
		if (useloopback) {
E 24
			sin.sin_family = AF_INET;
			sin.sin_addr = *destip;
			(void) looutput(&loif, m, (struct sockaddr *)&sin);
			/*
			 * The packet has already been sent and freed.
			 */
			return (0);
		} else {
			bcopy((caddr_t)ac->ac_enaddr, (caddr_t)desten,
			    sizeof(ac->ac_enaddr));
			return (1);
		}
E 20
E 9
E 2
	}
D 6
#ifdef OLDMAP
	if (lna >= 1024) {
E 6
I 6
D 8
	if ((ifp->if_flags & IFF_NOARP) || lna >= oldmap) {
E 6
D 2
		bcopy(ac->ac_enaddr, desten, 3);
E 2
I 2
		bcopy((caddr_t)ac->ac_enaddr, (caddr_t)desten, 3);
E 2
		desten[3] = (lna >> 16) & 0x7f;
		desten[4] = (lna >> 8) & 0xff;
		desten[5] = lna & 0xff;
		return (1);
	}
E 8
D 6
#endif OLDMAP
E 6
	s = splimp();
	ARPTAB_LOOK(at, destip->s_addr);
	if (at == 0) {			/* not found */
D 8
		at = arptnew(destip);
		at->at_hold = m;
		arpwhohas(ac, destip);
		splx(s);
		return (0);
E 8
I 8
D 15
		if ((ifp->if_flags & IFF_NOARP) || lna >= oldmap) {
E 15
I 15
D 24
		if (ifp->if_flags & IFF_NOARP) {
E 24
I 24
		if (ac->ac_if.if_flags & IFF_NOARP) {
E 24
E 15
D 12
			*desten = ac->ac_enaddr;
			desten->ether_addr_octet[3] = (lna >> 16) & 0x7f;
			desten->ether_addr_octet[4] = (lna >> 8) & 0xff;
			desten->ether_addr_octet[5] = lna & 0xff;
E 12
I 12
			bcopy((caddr_t)ac->ac_enaddr, (caddr_t)desten, 3);
			desten[3] = (lna >> 16) & 0x7f;
			desten[4] = (lna >> 8) & 0xff;
			desten[5] = lna & 0xff;
E 12
			splx(s);
			return (1);
		} else {
			at = arptnew(destip);
I 24
			if (at == 0)
				panic("arpresolve: no free entry");
E 24
			at->at_hold = m;
			arpwhohas(ac, destip);
			splx(s);
			return (0);
		}
E 8
	}
	at->at_timer = 0;		/* restart the timer */
	if (at->at_flags & ATF_COM) {	/* entry IS complete */
D 2
		bcopy(at->at_enaddr, desten, 6);
E 2
I 2
D 8
		bcopy((caddr_t)at->at_enaddr, (caddr_t)desten, 6);
E 8
I 8
D 12
		*desten = at->at_enaddr;
E 12
I 12
		bcopy((caddr_t)at->at_enaddr, (caddr_t)desten,
		    sizeof(at->at_enaddr));
I 18
		if (at->at_flags & ATF_USETRAILERS)
			*usetrailers = 1;
E 18
E 12
E 8
E 2
		splx(s);
		return (1);
	}
	/*
	 * There is an arptab entry, but no ethernet address
	 * response yet.  Replace the held mbuf with this
	 * latest one.
	 */
	if (at->at_hold)
		m_freem(at->at_hold);
	at->at_hold = m;
	arpwhohas(ac, destip);		/* ask again */
	splx(s);
	return (0);
}

/*
D 8
 * Find my own IP address.  It will either be waiting for us in
 * monitor RAM, or can be obtained via broadcast to the file/boot
 * server (not necessarily using the ARP packet format).
 *
 * Unimplemented at present, return 0 and assume that the host
 * will set his own IP address via the SIOCSIFADDR ioctl.
 */
I 2
/*ARGSUSED*/
E 2
struct in_addr
arpmyaddr(ac)
	register struct arpcom *ac;
{
	static struct in_addr addr;

I 3
#ifdef lint
	ac = ac;
#endif
E 3
	addr.s_addr = 0;
	return (addr);
}

/*
E 8
D 11
 * Called from ecintr/ilintr when ether packet type ETHERPUP_ARP
E 11
I 11
 * Called from 10 Mb/s Ethernet interrupt handlers
 * when ether packet type ETHERTYPE_ARP
E 11
D 8
 * is received.  Algorithm is exactly that given in RFC 826.
E 8
I 8
D 18
 * is received.  Algorithm is that given in RFC 826.
E 18
I 18
 * is received.  Common length and type checks are done here,
 * then the protocol-specific routine is called.
 */
arpinput(ac, m)
	struct arpcom *ac;
	struct mbuf *m;
{
	register struct arphdr *ar;

	if (ac->ac_if.if_flags & IFF_NOARP)
		goto out;
	IF_ADJ(m);
	if (m->m_len < sizeof(struct arphdr))
		goto out;
	ar = mtod(m, struct arphdr *);
	if (ntohs(ar->ar_hrd) != ARPHRD_ETHER)
		goto out;
	if (m->m_len < sizeof(struct arphdr) + 2 * ar->ar_hln + 2 * ar->ar_pln)
		goto out;

	switch (ntohs(ar->ar_pro)) {

	case ETHERTYPE_IP:
	case ETHERTYPE_IPTRAILERS:
		in_arpinput(ac, m);
		return;

	default:
		break;
	}
out:
	m_freem(m);
}

/*
 * ARP for Internet protocols on 10 Mb/s Ethernet.
 * Algorithm is that given in RFC 826.
E 18
E 8
 * In addition, a sanity check is performed on the sender
 * protocol address, to catch impersonators.
I 18
 * We also handle negotiations for use of trailer protocol:
 * ARP replies for protocol type ETHERTYPE_TRAIL are sent
 * along with IP replies if we want trailers sent to us,
 * and also send them in response to IP replies.
 * This allows either end to announce the desire to receive
 * trailer packets.
 * We reply to requests for ETHERTYPE_TRAIL protocol as well,
 * but don't normally send requests.
E 18
 */
D 18
arpinput(ac, m)
E 18
I 18
in_arpinput(ac, m)
E 18
	register struct arpcom *ac;
	struct mbuf *m;
{
	register struct ether_arp *ea;
	struct ether_header *eh;
D 17
	register struct arptab *at = 0;  /* same as "merge" flag */
E 17
I 17
	register struct arptab *at;  /* same as "merge" flag */
I 18
	struct mbuf *mcopy = 0;
E 18
E 17
	struct sockaddr_in sin;
	struct sockaddr sa;
D 13
	struct mbuf *mhold;
E 13
D 18
	struct in_addr isaddr,itaddr,myaddr;
E 18
I 18
	struct in_addr isaddr, itaddr, myaddr;
D 24
D 26
	int proto, op;
E 26
I 26
	int proto, op, s;
E 26
E 24
I 24
D 28
	int proto, op, s;
E 28
I 28
	int proto, op, s, completed = 0;
E 28
E 24
E 18

I 17
D 18
	IF_ADJ(m);
	at = 0;
E 17
	if (m->m_len < sizeof *ea)
		goto out;
I 8
	if (ac->ac_if.if_flags & IFF_NOARP)
		goto out;
E 18
E 8
D 11
	myaddr = ((struct sockaddr_in *)&ac->ac_if.if_addr)->sin_addr;
E 11
I 11
	myaddr = ac->ac_ipaddr;
E 11
	ea = mtod(m, struct ether_arp *);
D 11
	if (ntohs(ea->arp_pro) != ETHERPUP_IPTYPE)
E 11
I 11
D 18
	if (ntohs(ea->arp_pro) != ETHERTYPE_IP)
E 11
		goto out;
E 18
I 18
	proto = ntohs(ea->arp_pro);
	op = ntohs(ea->arp_op);
E 18
D 8
	isaddr.s_addr = ((struct in_addr *)ea->arp_spa)->s_addr;
	itaddr.s_addr = ((struct in_addr *)ea->arp_tpa)->s_addr;
D 2
	if (!bcmp(ea->arp_sha, ac->ac_enaddr, sizeof ac->ac_enaddr))
E 2
I 2
	if (!bcmp((caddr_t)ea->arp_sha, (caddr_t)ac->ac_enaddr,
E 8
I 8
D 12
	isaddr = arp_spa(ea);
	itaddr = arp_tpa(ea);
	if (!bcmp((caddr_t)&arp_sha(ea), (caddr_t)&ac->ac_enaddr,
E 8
	  sizeof (ac->ac_enaddr)))
E 12
I 12
D 24
	isaddr.s_addr = ((struct in_addr *)ea->arp_spa)->s_addr;
	itaddr.s_addr = ((struct in_addr *)ea->arp_tpa)->s_addr;
E 24
I 24
	bcopy((caddr_t)ea->arp_spa, (caddr_t)&isaddr, sizeof (isaddr));
	bcopy((caddr_t)ea->arp_tpa, (caddr_t)&itaddr, sizeof (itaddr));
E 24
	if (!bcmp((caddr_t)ea->arp_sha, (caddr_t)ac->ac_enaddr,
	  sizeof (ea->arp_sha)))
E 12
E 2
		goto out;	/* it's from me, ignore it. */
I 18
	if (!bcmp((caddr_t)ea->arp_sha, (caddr_t)etherbroadcastaddr,
	    sizeof (ea->arp_sha))) {
		log(LOG_ERR,
		    "arp: ether address is broadcast for IP address %x!\n",
		    ntohl(isaddr.s_addr));
		goto out;
	}
E 18
	if (isaddr.s_addr == myaddr.s_addr) {
D 18
		printf("duplicate IP address!! sent from ethernet address: ");
D 8
		printf("%x %x %x %x %x %x\n", ea->arp_sha[0], ea->arp_sha[1],
		    ea->arp_sha[2], ea->arp_sha[3],
		    ea->arp_sha[4], ea->arp_sha[5]);
E 8
I 8
D 12
		printf("%x %x %x %x %x %x\n", ea->arp_xsha[0], ea->arp_xsha[1],
			ea->arp_xsha[2], ea->arp_xsha[3],
			ea->arp_xsha[4], ea->arp_xsha[5]);
E 12
I 12
		printf("%x %x %x %x %x %x\n", ea->arp_sha[0], ea->arp_sha[1],
			ea->arp_sha[2], ea->arp_sha[3],
			ea->arp_sha[4], ea->arp_sha[5]);
E 18
I 18
		log(LOG_ERR, "%s: %s\n",
			"duplicate IP address!! sent from ethernet address",
			ether_sprintf(ea->arp_sha));
E 18
E 12
		itaddr = myaddr;
E 8
D 12
		if (ntohs(ea->arp_op) == ARPOP_REQUEST)
E 12
I 12
D 18
		if (ntohs(ea->arp_op) == ARPOP_REQUEST) {
			bcopy((caddr_t)ac->ac_enaddr, (caddr_t)ea->arp_sha,
			    sizeof(ea->arp_sha));
E 18
I 18
		if (op == ARPOP_REQUEST)
E 18
E 12
			goto reply;
I 12
D 18
		}
E 18
E 12
		goto out;
	}
I 26
	s = splimp();
E 26
I 24
	s = splimp();
E 24
	ARPTAB_LOOK(at, isaddr.s_addr);
D 8
	if (at) {
D 2
		bcopy(ea->arp_sha, at->at_enaddr, sizeof ea->arp_sha);
E 2
I 2
		bcopy((caddr_t)ea->arp_sha, (caddr_t)at->at_enaddr,
		   sizeof (ea->arp_sha));
E 8
I 8
D 13
	if (at) {		/* XXX ? - can overwrite ATF_PERM */
E 13
I 13
D 19
	if (at && (at->at_flags & ATF_COM) == 0) {
E 19
I 19
	if (at) {
E 19
E 13
D 12
		at->at_enaddr = arp_sha(ea);
E 12
I 12
		bcopy((caddr_t)ea->arp_sha, (caddr_t)at->at_enaddr,
		    sizeof(ea->arp_sha));
I 28
		if ((at->at_flags & ATF_COM) == 0)
			completed = 1;
E 28
E 12
E 8
E 2
		at->at_flags |= ATF_COM;
		if (at->at_hold) {
D 13
			mhold = at->at_hold;
			at->at_hold = 0;
E 13
			sin.sin_family = AF_INET;
			sin.sin_addr = isaddr;
			(*ac->ac_if.if_output)(&ac->ac_if, 
D 13
			    mhold, (struct sockaddr *)&sin);
E 13
I 13
			    at->at_hold, (struct sockaddr *)&sin);
			at->at_hold = 0;
E 13
		}
D 8
	}
	if (itaddr.s_addr != myaddr.s_addr)
		goto out;	/* if I am not the target */
	if (at == 0) {		/* ensure we have a table entry */
E 8
I 8
D 13
	} else if (itaddr.s_addr == myaddr.s_addr) {
E 13
I 13
	}
	if (at == 0 && itaddr.s_addr == myaddr.s_addr) {
E 13
		/* ensure we have a table entry */
E 8
D 25
		at = arptnew(&isaddr);
D 2
		bcopy(ea->arp_sha, at->at_enaddr, sizeof ea->arp_sha);
E 2
I 2
D 8
		bcopy((caddr_t)ea->arp_sha, (caddr_t)at->at_enaddr,
		   sizeof (ea->arp_sha));
E 8
I 8
D 12
		at->at_enaddr = arp_sha(ea);
E 12
I 12
		bcopy((caddr_t)ea->arp_sha, (caddr_t)at->at_enaddr,
		    sizeof(ea->arp_sha));
E 12
E 8
E 2
		at->at_flags |= ATF_COM;
E 25
I 25
		if (at = arptnew(&isaddr)) {
			bcopy((caddr_t)ea->arp_sha, (caddr_t)at->at_enaddr,
			    sizeof(ea->arp_sha));
I 28
			completed = 1;
E 28
			at->at_flags |= ATF_COM;
		}
E 25
	}
I 26
	splx(s);
E 26
I 24
	splx(s);
E 24
D 18
	if (ntohs(ea->arp_op) != ARPOP_REQUEST)
		goto out;
I 8
	ARPTAB_LOOK(at, itaddr.s_addr);
	if (at == NULL) {
		if (itaddr.s_addr != myaddr.s_addr)
			goto out;	/* if I am not the target */
		at = arptnew(&myaddr);
D 12
		at->at_enaddr = ac->ac_enaddr;
E 12
I 12
		bcopy((caddr_t)ac->ac_enaddr, (caddr_t)at->at_enaddr,
		   sizeof(at->at_enaddr));
E 12
		at->at_flags |= ATF_COM;
	} 
	if (itaddr.s_addr != myaddr.s_addr && (at->at_flags & ATF_PUBL) == 0)
		goto out;
		
E 18
I 12
D 13
	bcopy((caddr_t)at->at_enaddr, (caddr_t)ea->arp_sha,
	    sizeof(ea->arp_sha));
E 13
E 12
E 8
reply:
D 2
	bcopy(ea->arp_sha, ea->arp_tha, sizeof ea->arp_sha);
	bcopy(ea->arp_spa, ea->arp_tpa, sizeof ea->arp_spa);
	bcopy(ac->ac_enaddr, ea->arp_sha, sizeof ea->arp_sha);
	bcopy((caddr_t)&myaddr, ea->arp_spa, sizeof ea->arp_spa);
E 2
I 2
D 8
	bcopy((caddr_t)ea->arp_sha, (caddr_t)ea->arp_tha,
	   sizeof (ea->arp_sha));
	bcopy((caddr_t)ea->arp_spa, (caddr_t)ea->arp_tpa,
	   sizeof (ea->arp_spa));
	bcopy((caddr_t)ac->ac_enaddr, (caddr_t)ea->arp_sha,
	   sizeof (ea->arp_sha));
	bcopy((caddr_t)&myaddr, (caddr_t)ea->arp_spa,
	   sizeof (ea->arp_spa));
E 8
I 8
D 12
	arp_tha(ea) = arp_sha(ea);
	arp_tpa(ea) = arp_spa(ea);
	arp_sha(ea) = at->at_enaddr;
	arp_spa(ea) = itaddr;
E 12
I 12
D 18
	bcopy((caddr_t)ea->arp_sha, (caddr_t)ea->arp_tha,
	    sizeof(ea->arp_sha));
	bcopy((caddr_t)ea->arp_spa, (caddr_t)ea->arp_tpa,
	    sizeof(ea->arp_spa));
I 13
	if (at)		/* done above if at == 0 */
E 18
I 18
	switch (proto) {

	case ETHERTYPE_IPTRAILERS:
		/* partner says trailers are OK */
		if (at)
			at->at_flags |= ATF_USETRAILERS;
		/*
		 * Reply to request iff we want trailers.
		 */
		if (op != ARPOP_REQUEST || ac->ac_if.if_flags & IFF_NOTRAILERS)
			goto out;
		break;

	case ETHERTYPE_IP:
		/*
D 28
		 * Reply if this is an IP request, or if we want to send
		 * a trailer response.
E 28
I 28
		 * Reply if this is an IP request,
		 * or if we want to send a trailer response.
		 * Send the latter only to the IP response
		 * that completes the current ARP entry.
E 28
		 */
D 28
		if (op != ARPOP_REQUEST && ac->ac_if.if_flags & IFF_NOTRAILERS)
E 28
I 28
		if (op != ARPOP_REQUEST &&
		    (completed == 0 || ac->ac_if.if_flags & IFF_NOTRAILERS))
E 28
			goto out;
	}
	if (itaddr.s_addr == myaddr.s_addr) {
		/* I am the target */
		bcopy((caddr_t)ea->arp_sha, (caddr_t)ea->arp_tha,
		    sizeof(ea->arp_sha));
		bcopy((caddr_t)ac->ac_enaddr, (caddr_t)ea->arp_sha,
		    sizeof(ea->arp_sha));
	} else {
		ARPTAB_LOOK(at, itaddr.s_addr);
		if (at == NULL || (at->at_flags & ATF_PUBL) == 0)
			goto out;
		bcopy((caddr_t)ea->arp_sha, (caddr_t)ea->arp_tha,
		    sizeof(ea->arp_sha));
E 18
		bcopy((caddr_t)at->at_enaddr, (caddr_t)ea->arp_sha,
		    sizeof(ea->arp_sha));
I 18
	}

	bcopy((caddr_t)ea->arp_spa, (caddr_t)ea->arp_tpa,
	    sizeof(ea->arp_spa));
E 18
E 13
	bcopy((caddr_t)&itaddr, (caddr_t)ea->arp_spa,
	    sizeof(ea->arp_spa));
E 12
E 8
E 2
D 18
	ea->arp_op = htons(ARPOP_REPLY);
E 18
I 18
	ea->arp_op = htons(ARPOP_REPLY); 
	/*
	 * If incoming packet was an IP reply,
	 * we are sending a reply for type IPTRAILERS.
	 * If we are sending a reply for type IP
	 * and we want to receive trailers,
	 * send a trailer reply as well.
	 */
	if (op == ARPOP_REPLY)
		ea->arp_pro = htons(ETHERTYPE_IPTRAILERS);
	else if (proto == ETHERTYPE_IP &&
	    (ac->ac_if.if_flags & IFF_NOTRAILERS) == 0)
D 22
		mcopy = m_copy(m, 0, M_COPYALL);
E 22
I 22
		mcopy = m_copy(m, 0, (int)M_COPYALL);
E 22
E 18
	eh = (struct ether_header *)sa.sa_data;
D 2
	bcopy(ea->arp_tha, eh->ether_dhost, sizeof eh->ether_dhost);
E 2
I 2
D 8
	bcopy((caddr_t)ea->arp_tha, (caddr_t)eh->ether_dhost,
	   sizeof (eh->ether_dhost));
E 8
I 8
D 12
	eh->ether_dhost = arp_tha(ea);
E 12
I 12
	bcopy((caddr_t)ea->arp_tha, (caddr_t)eh->ether_dhost,
	    sizeof(eh->ether_dhost));
E 12
E 8
E 2
D 11
	eh->ether_type = ETHERPUP_ARPTYPE;
E 11
I 11
	eh->ether_type = ETHERTYPE_ARP;
E 11
	sa.sa_family = AF_UNSPEC;
	(*ac->ac_if.if_output)(&ac->ac_if, m, &sa);
I 18
	if (mcopy) {
		ea = mtod(mcopy, struct ether_arp *);
		ea->arp_pro = htons(ETHERTYPE_IPTRAILERS);
		(*ac->ac_if.if_output)(&ac->ac_if, mcopy, &sa);
	}
E 18
	return;
out:
	m_freem(m);
	return;
}

/*
 * Free an arptab entry.
 */
arptfree(at)
	register struct arptab *at;
{
	int s = splimp();

	if (at->at_hold)
		m_freem(at->at_hold);
	at->at_hold = 0;
	at->at_timer = at->at_flags = 0;
	at->at_iaddr.s_addr = 0;
	splx(s);
}

/*
 * Enter a new address in arptab, pushing out the oldest entry 
 * from the bucket if there is no room.
I 8
 * This always succeeds since no bucket can be completely filled
 * with permanent entries (except from arpioctl when testing whether
D 12
 * another permanent entry).
E 12
I 12
 * another permanent entry will fit).
I 24
 * MUST BE CALLED AT SPLIMP.
E 24
E 12
E 8
 */
struct arptab *
arptnew(addr)
	struct in_addr *addr;
{
	register n;
D 17
	int oldest = 0;
E 17
I 17
	int oldest = -1;
E 17
D 8
	register struct arptab *at, *ato;
E 8
I 8
	register struct arptab *at, *ato = NULL;
	static int first = 1;
E 8

D 8
	ato = at = &arptab[ARPTAB_HASH(addr->s_addr) * ARPTAB_BSIZ];
E 8
I 8
	if (first) {
		first = 0;
		timeout(arptimer, (caddr_t)0, hz);
	}
	at = &arptab[ARPTAB_HASH(addr->s_addr) * ARPTAB_BSIZ];
E 8
D 12
	for (n = 0 ; n < ARPTAB_BSIZ ; n++,at++) {
E 12
I 12
	for (n = 0; n < ARPTAB_BSIZ; n++,at++) {
E 12
		if (at->at_flags == 0)
			goto out;	 /* found an empty entry */
I 8
		if (at->at_flags & ATF_PERM)
			continue;
E 8
D 25
		if (at->at_timer > oldest) {
E 25
I 25
		if ((int) at->at_timer > oldest) {
E 25
			oldest = at->at_timer;
			ato = at;
		}
	}
I 8
	if (ato == NULL)
D 12
		return(NULL);
E 12
I 12
		return (NULL);
E 12
E 8
	at = ato;
	arptfree(at);
out:
	at->at_iaddr = *addr;
	at->at_flags = ATF_INUSE;
	return (at);
I 8
}

arpioctl(cmd, data)
	int cmd;
	caddr_t data;
{
	register struct arpreq *ar = (struct arpreq *)data;
	register struct arptab *at;
	register struct sockaddr_in *sin;
	int s;

	if (ar->arp_pa.sa_family != AF_INET ||
	    ar->arp_ha.sa_family != AF_UNSPEC)
		return (EAFNOSUPPORT);
	sin = (struct sockaddr_in *)&ar->arp_pa;
	s = splimp();
	ARPTAB_LOOK(at, sin->sin_addr.s_addr);
	if (at == NULL) {		/* not found */
		if (cmd != SIOCSARP) {
			splx(s);
			return (ENXIO);
		}
D 11
		if (if_ifwithnet(&ar->arp_pa) == NULL) {
E 11
I 11
		if (ifa_ifwithnet(&ar->arp_pa) == NULL) {
E 11
			splx(s);
			return (ENETUNREACH);
		}
	}
	switch (cmd) {

	case SIOCSARP:		/* set entry */
		if (at == NULL) {
			at = arptnew(&sin->sin_addr);
I 25
			if (at == NULL) {
				splx(s);
				return (EADDRNOTAVAIL);
			}
E 25
			if (ar->arp_flags & ATF_PERM) {
			/* never make all entries in a bucket permanent */
				register struct arptab *tat;
				
				/* try to re-allocate */
				tat = arptnew(&sin->sin_addr);
				if (tat == NULL) {
					arptfree(at);
					splx(s);
					return (EADDRNOTAVAIL);
				}
				arptfree(tat);
			}
		}
D 12
		at->at_enaddr = *(struct ether_addr *)ar->arp_ha.sa_data;
E 12
I 12
		bcopy((caddr_t)ar->arp_ha.sa_data, (caddr_t)at->at_enaddr,
		    sizeof(at->at_enaddr));
E 12
		at->at_flags = ATF_COM | ATF_INUSE |
D 29
			(ar->arp_flags & (ATF_PERM|ATF_PUBL));
E 29
I 29
			(ar->arp_flags & (ATF_PERM|ATF_PUBL|ATF_USETRAILERS));
E 29
		at->at_timer = 0;
		break;

	case SIOCDARP:		/* delete entry */
		arptfree(at);
		break;

	case SIOCGARP:		/* get entry */
D 12
		*(struct ether_addr *)ar->arp_ha.sa_data = at->at_enaddr;
E 12
I 12
		bcopy((caddr_t)at->at_enaddr, (caddr_t)ar->arp_ha.sa_data,
		    sizeof(at->at_enaddr));
E 12
		ar->arp_flags = at->at_flags;
		break;
	}
	splx(s);
	return (0);
I 18
}

/*
 * Convert Ethernet address to printable (loggable) representation.
 */
char *
ether_sprintf(ap)
	register u_char *ap;
{
	register i;
	static char etherbuf[18];
	register char *cp = etherbuf;
	static char digits[] = "0123456789abcdef";

	for (i = 0; i < 6; i++) {
		*cp++ = digits[*ap >> 4];
		*cp++ = digits[*ap++ & 0xf];
		*cp++ = ':';
	}
	*--cp = 0;
	return (etherbuf);
E 18
E 8
}
E 1
