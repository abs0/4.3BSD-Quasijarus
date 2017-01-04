h63256
s 00011/00006/00238
d D 7.9 88/06/29 16:58:09 bostic 35 34
c install approved copyright notice
e
s 00008/00001/00236
d D 7.8 88/06/10 09:29:34 karels 34 33
c need to reset hostq when compressing (might point to freed mbuf)
e
s 00001/00001/00236
d D 7.7 88/05/24 11:12:24 karels 33 32
c lint
e
s 00001/00002/00236
d D 7.6 88/05/11 12:46:24 karels 32 31
c lower priority for lost rfnm messages
e
s 00014/00013/00224
d D 7.5 88/05/06 12:33:06 karels 31 30
c clean up queuing, keep message counts correctly, check for 1822L NOPs, etc
e
s 00007/00002/00230
d D 7.4 88/02/08 10:41:01 karels 30 29
c don't leave hostq pointing at garbage
e
s 00055/00040/00177
d D 7.3 88/02/08 10:30:12 karels 29 28
c new copyrights; new IMP interface with H/W, using cb_output rather
c than cb_start (so can start RFNM timer when packet goes out, and output is
c round-robin by destination)
e
s 00053/00065/00164
d D 7.2 88/02/03 17:26:46 karels 28 27
c working with new up/down FSM, dropcount, statistics and host entry
e
s 00001/00001/00228
d D 7.1 86/06/04 23:56:15 mckusick 27 26
c 4.3BSD release version
e
s 00001/00001/00228
d D 6.7 85/09/18 20:07:39 karels 26 25
c new syslog
e
s 00001/00001/00228
d D 6.6 85/09/16 21:47:41 karels 25 24
c oops, how about all of the address
e
s 00014/00006/00215
d D 6.5 85/09/16 21:30:16 karels 24 23
c fix races: queue error messages for processing at splnet, don't lose
c if timing out host entries while walking queue; keep timer on rfnm's, restart
c if it expires; don't restart hostdead timer when touching entry, or a ping
c will keep it down forever
e
s 00007/00001/00214
d D 6.4 85/06/08 12:32:25 mckusick 23 22
c Add copyright
e
s 00003/00002/00212
d D 6.3 85/02/28 14:27:33 karels 22 21
c mods for Classs B,C support, RFNM fixes from BRL
e
s 00004/00004/00210
d D 6.2 84/08/29 16:17:55 bloom 21 20
c Change to include files.  No more ../h
e
s 00000/00000/00214
d D 6.1 83/07/29 07:15:32 sam 20 19
c 4.2 distribution
e
s 00001/00000/00213
d D 4.19 83/06/13 11:59:10 sam 19 18
c missing endif
e
s 00001/00001/00212
d D 4.18 83/02/23 16:33:21 sam 18 17
c typo
e
s 00012/00020/00201
d D 4.17 83/02/23 00:01:34 sam 17 16
c cleanup splnet's; if_imphost code interlocks at splimp now
e
s 00001/00001/00220
d D 4.16 82/12/14 17:18:45 sam 16 15
c typed mbufs
e
s 00004/00004/00217
d D 4.15 82/10/09 05:50:03 wnj 15 14
c fix header files
e
s 00000/00001/00221
d D 4.14 82/10/05 18:49:20 root 14 13
c m_get inits m_off; remove TCPTRUEOOB
e
s 00000/00006/00222
d D 4.13 82/06/20 00:53:05 sam 13 12
c purge COUNT stuff now that we can use gprof
e
s 00001/00002/00227
d D 4.12 82/05/11 17:45:08 sam 12 11
c infinite loop
e
s 00002/00000/00227
d D 4.11 82/05/10 13:00:05 sam 11 10
c flags weren't zero'd out
e
s 00063/00023/00164
d D 4.10 82/04/25 18:34:48 sam 10 9
c make host structure deletion timer based
e
s 00000/00002/00187
d D 4.9 82/03/16 13:54:00 root 9 8
c fixes to imp
e
s 00001/00001/00188
d D 4.8 82/03/15 04:43:44 wnj 8 7
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00001/00003/00188
d D 4.7 82/03/12 16:12:52 sam 7 6
c fix some lint
e
s 00006/00002/00185
d D 4.6 82/03/09 17:40:41 root 6 5
c logical host handling, fix up some cruft, ...
e
s 00020/00001/00167
d D 4.5 82/02/21 13:08:24 root 5 4
c cleanup code a bit
e
s 00007/00003/00161
d D 4.4 82/02/16 17:09:14 root 4 3
c messed up rfnm q's
e
s 00041/00053/00123
d D 4.3 82/02/16 15:11:51 root 3 2
c first "working" imp driver
e
s 00027/00025/00149
d D 4.2 82/02/12 15:16:59 wnj 2 1
c closer to a working imp driver
e
s 00174/00000/00000
d D 4.1 82/02/06 19:47:58 sam 1 0
c date and time created 82/02/06 19:47:58 by sam
e
u
U
t
T
I 1
D 23
/*	%M%	%I%	%E%	*/
E 23
I 23
/*
D 27
 * Copyright (c) 1982 Regents of the University of California.
E 27
I 27
D 29
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 27
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 29
I 29
D 35
 * Copyright (c) 1982,1986,1988 Regents of the University of California.
E 35
I 35
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 35
 * All rights reserved.
E 29
 *
I 29
 * Redistribution and use in source and binary forms are permitted
D 35
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 35
I 35
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
E 35
 *
E 29
 *	%W% (Berkeley) %G%
 */
E 23

#include "imp.h"
#if NIMP > 0
/*
 * Host table manipulation routines.
 * Only needed when shipping stuff through an IMP.
I 17
 *
 * Everything in here is called at splimp from
 * from the IMP protocol code (if_imp.c), or
 * interlocks with the code at splimp.
E 17
 */
D 17

E 17
D 21
#include "../h/param.h"
#include "../h/mbuf.h"
E 21
I 21
#include "param.h"
#include "mbuf.h"
I 28
#include "socket.h"
E 28
I 24
#include "syslog.h"
E 24
E 21
I 17

I 28
#include "../net/if.h"

E 28
E 17
D 15
#include "../net/in.h"
#include "../net/in_systm.h"
D 3
#include "../net/host.h"
E 3
#include "../net/if_imp.h"
I 3
#include "../net/if_imphost.h"
E 15
I 15
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 17

E 17
D 21
#include "../netimp/if_imp.h"
#include "../netimp/if_imphost.h"
E 21
I 21
#include "if_imp.h"
#include "if_imphost.h"
E 21
E 15
E 3

D 29
/*
 * Head of host table hash chains.
 */
D 3
struct mbuf hosttable = { 0, MMINOFF };
E 3
I 3
struct mbuf *hosts;
E 29
I 28
extern struct imp_softc imp_softc[];
E 28
E 3

/*
 * Given an internet address
 * return a host structure (if it exists).
 */
struct host *
D 2
h_lookup(addr)
E 2
I 2
D 28
hostlookup(addr)
E 2
	struct in_addr addr;
E 28
I 28
hostlookup(imp, host, unit)
	int imp, host, unit;
E 28
{
	register struct host *hp;
	register struct mbuf *m;
D 28
	register int hash = HOSTHASH(addr);
E 28
I 28
	register int hash = HOSTHASH(imp, host);
E 28
I 10
D 17
	int s = splnet();
E 17
E 10

D 2
COUNT(H_LOOKUP);
printf("h_lookup(%x)\n", addr);
E 2
I 2
D 13
COUNT(HOSTLOOKUP);
E 13
I 6
D 9
	addr.s_lh = 0;
E 9
E 6
D 3
printf("hostlookup(%x)\n", addr);
E 2
	for (m = &hosttable; m; m = m->m_next) {
E 3
I 3
D 29
	for (m = hosts; m; m = m->m_next) {
E 29
I 29
	for (m = imp_softc[unit].imp_hosts; m; m = m->m_next) {
E 29
E 3
		hp = &mtod(m, struct hmbuf *)->hm_hosts[hash];
D 10
		if (hp->h_refcnt == 0)
D 3
			break;
D 2
printf("h_lookup: addr=%x\n", hp->h_addr.s_addr);
E 2
I 2
printf("hostlookup: addr=%x\n", hp->h_addr.s_addr);
E 3
I 3
			continue;
E 3
E 2
D 6
	        if (hp->h_addr.s_addr == addr.s_addr)    
E 6
I 6
	        if (hp->h_addr.s_addr == addr.s_addr)
E 6
			return (hp);
E 10
I 10
D 28
	        if (hp->h_addr.s_addr == addr.s_addr) {
E 28
I 28
D 29
	        if (hp->h_imp == imp && hp->h_host == host &&
		    hp->h_unit == unit) {
E 29
I 29
	        if (hp->h_imp == imp && hp->h_host == host) {
D 31
			if ((hp->h_flags & HF_INUSE) == 0 && hp->h_timer == 0)
E 31
I 31
			if ((hp->h_flags & HF_INUSE) == 0)
E 31
				mtod(dtom(hp), struct hmbuf *)->hm_count++;
E 29
E 28
			hp->h_flags |= HF_INUSE;
D 17
			goto found;
E 17
I 17
			return (hp);
E 17
		}
E 10
	}
D 10
	return (0);
E 10
I 10
D 17
	hp = 0;
found:
	splx(s);
	return (hp);
E 17
I 17
	return ((struct host *)0);
E 17
E 10
}

/*
 * Enter a reference to this host's internet
 * address.  If no host structure exists, create
 * one and hook it into the host database.
 */
struct host *
D 2
h_enter(addr)                 
E 2
I 2
D 28
hostenter(addr)                 
E 2
	struct in_addr addr;
E 28
I 28
hostenter(imp, host, unit)
	int imp, host, unit;
E 28
{
D 3
	register struct mbuf *m, *mprev;
	register struct host *hp;
E 3
I 3
	register struct mbuf *m, **mprev;
	register struct host *hp, *hp0 = 0;
E 3
D 28
	register int hash = HOSTHASH(addr);
E 28
I 28
	register int hash = HOSTHASH(imp, host);
E 28
I 10
D 17
	int s = splnet();
E 17
E 10

D 2
COUNT(H_ENTER);
printf("h_enter(%x)\n", addr);
E 2
I 2
D 13
COUNT(HOSTENTER);
E 13
I 6
D 9
	addr.s_lh = 0;
E 9
E 6
D 3
printf("hostenter(%x)\n", addr);
E 2
	for (m = &hosttable; m; mprev = m, m = m->m_next) {
E 3
I 3
D 29
	mprev = &hosts;
E 29
I 29
	mprev = &imp_softc[unit].imp_hosts;
E 29
	while (m = *mprev) {
I 8
		mprev = &m->m_next;
E 8
E 3
		hp = &mtod(m, struct hmbuf *)->hm_hosts[hash];
I 28
D 29
	        if (hp->h_imp == imp && hp->h_host == host &&
		    hp->h_unit == unit)
E 29
I 29
	        if (hp->h_imp == imp && hp->h_host == host) {
D 31
			if ((hp->h_flags & HF_INUSE) == 0 && hp->h_timer == 0)
E 31
I 31
			if ((hp->h_flags & HF_INUSE) == 0)
E 31
				mtod(dtom(hp), struct hmbuf *)->hm_count++;
E 29
			goto foundhost;
I 29
		}
E 29
E 28
D 3
		if (hp->h_refcnt == 0)
			break;
D 2
printf("h_enter: addr=%x\n", addr);
E 2
I 2
printf("hostenter: addr=%x\n", addr);
E 3
I 3
D 10
		if (hp->h_refcnt == 0) {
E 10
I 10
		if ((hp->h_flags & HF_INUSE) == 0) {
D 28
			if (hp->h_addr.s_addr == addr.s_addr)
				goto foundhost;
E 28
E 10
			if (hp0 == 0)
				hp0 = hp;
			continue;
		}
E 3
E 2
D 28
	        if (hp->h_addr.s_addr == addr.s_addr)    
			goto foundhost;
E 28
I 3
D 8
		mprev = &m->m_next;
E 8
E 3
	}

	/*
	 * No current host structure, make one.
	 * If our search ran off the end of the
	 * chain of mbuf's, allocate another.
	 */
D 2
printf("h_enter: new host\n");
E 2
I 2
D 3
printf("hostenter: new host\n");
E 2
	if (m == 0) {
E 3
I 3
	if (hp0 == 0) {
E 3
D 16
		m = m_getclr(M_DONTWAIT);
E 16
I 16
		m = m_getclr(M_DONTWAIT, MT_HTABLE);
E 16
D 10
		if (m == 0)
E 10
I 10
D 17
		if (m == 0) {
			splx(s);
E 10
			return (0);
I 10
		}
E 17
I 17
		if (m == NULL)
			return ((struct host *)0);
E 17
E 10
D 3
		mprev->m_next = m;
		m->m_act = mprev;
		hp = &mtod(m, struct hmbuf *)->hm_hosts[hash];
E 3
I 3
		*mprev = m;
D 14
		m->m_off = MMINOFF;
E 14
		hp0 = &mtod(m, struct hmbuf *)->hm_hosts[hash];
E 3
	}
D 3
	mtod(m, struct hmbuf *)->hm_count++;
E 3
I 3
D 31
	mtod(dtom(hp0), struct hmbuf *)->hm_count++;
E 31
	hp = hp0;
I 31
	mtod(dtom(hp), struct hmbuf *)->hm_count++;
E 31
E 3
D 28
	hp->h_addr = addr;
E 28
I 28
	hp->h_imp = imp;
	hp->h_host = host;
D 29
	hp->h_unit = unit;
E 29
E 28
D 5
	hp->h_status = HOSTS_UP;
E 5
I 5
D 10
	hp->h_qcnt = 0;
E 10
I 10
	hp->h_timer = 0;
I 11
	hp->h_flags = 0;
E 11
E 10
E 5

foundhost:
D 10
	hp->h_refcnt++;		/* know new structures have 0 val */
E 10
I 10
	hp->h_flags |= HF_INUSE;
D 17
	splx(s);
E 17
E 10
	return (hp);
}

/*
D 10
 * Free a reference to a host.  If this causes the
 * host structure to be released do so.
E 10
I 10
D 28
 * Mark a host structure free and set it's
 * timer going.
E 28
I 28
 * Reset a given imp unit's host entries.
I 34
 * Must be called at splimp.
E 34
E 28
E 10
 */
D 2
h_free(addr)                               
E 2
I 2
D 3
hostfree(addr)                               
E 2
	struct in_addr addr;
E 3
I 3
D 28
hostfree(hp)                               
	register struct host *hp;
E 28
I 28
hostreset(unit)
	int unit;
E 28
E 3
{
I 10
D 17
	int s = splnet();
E 17
D 28

E 10
D 7
	register struct mbuf *m;
D 3
	register struct host *hp;
	register int hash = HOSTHASH(addr);
E 3

E 7
D 2
COUNT(H_FREE);
printf("h_free(%x)\n", addr);
E 2
I 2
D 13
COUNT(HOSTFREE);
E 13
D 3
printf("hostfree(%x)\n", addr);
E 2
	for (m = &hosttable; m; m = m->m_next) {
		hp = &mtod(m, struct hmbuf *)->hm_hosts[hash];
		if (hp->h_refcnt == 0)
			return;
	        if (hp->h_addr.s_addr == addr.s_addr) {
			if (--hp->h_refcnt == 0)
D 2
				h_release(mtod(m, struct hmbuf *), hp);
E 2
I 2
				hostrelease(mtod(m, struct hmbuf *), hp);
E 2
			return;
		}
	}
D 2
	panic("h_free");
E 2
I 2
	panic("hostfree");
E 3
I 3
D 10
	if (--hp->h_refcnt)
		return;
	hostrelease(hp);
E 10
I 10
	hp->h_flags &= ~HF_INUSE;
	hp->h_timer = HOSTTIMER;
	hp->h_rfnm = 0;
D 17
	splx(s);
E 17
E 10
E 3
E 2
}

/*
 * Reset a given network's host entries.
D 10
 * This involves clearing all packet queue's
 * and releasing host structures.
E 10
 */
D 2
h_reset(net)	    
E 2
I 2
hostreset(net)	    
E 2
D 22
	int net;
E 22
I 22
D 24
	long net;
E 24
I 24
	u_long net;
E 24
E 22
{
E 28
	register struct mbuf *m;
	register struct host *hp, *lp;
I 3
	struct hmbuf *hm;
I 24
D 28
	struct mbuf *mnext;
E 28
E 24
D 10
	int x;
E 10
I 10
D 17
	int s = splnet();
E 17
E 10
E 3

D 2
COUNT(H_RESET);
printf("h_reset(%x)\n", net);
E 2
I 2
D 13
COUNT(HOSTRESET);
E 13
D 3
printf("hostreset(%x)\n", net);
E 2
	for (m = &hosttable; m; m = m->m_next) {
		hp = mtod(m, struct hmbuf *)->hm_hosts; 
E 3
I 3
D 10
	x = splimp();
E 10
D 24
	for (m = hosts; m; m = m->m_next) {
E 24
I 24
D 28
	for (m = hosts; m; m = mnext) {
		mnext = m->m_next;
E 28
I 28
D 29
	for (m = hosts; m; m = m->m_next) {
E 29
I 29
	for (m = imp_softc[unit].imp_hosts; m; m = m->m_next) {
E 29
E 28
E 24
		hm = mtod(m, struct hmbuf *);
		hp = hm->hm_hosts; 
E 3
		lp = hp + HPMBUF;
D 3
		while (hp < lp) {
E 3
I 3
D 10
		while (hm->hm_count != 0 && hp < lp) {
E 10
I 10
		while (hm->hm_count > 0 && hp < lp) {
E 10
E 3
D 6
			if (hp->h_addr.s_net == net)
E 6
I 6
D 22
			if (hp->h_addr.s_net == net) {
E 22
I 22
D 28
			if (in_netof(hp->h_addr) == net) {
E 22
D 10
				hp->h_refcnt = 0;
E 10
I 10
				hp->h_flags &= ~HF_INUSE;
E 28
I 28
D 29
			if (hp->h_unit == unit)
E 28
E 10
E 6
D 2
				h_release(mtod(m, struct hmbuf *), hp);
E 2
I 2
D 7
				hostrelease(mtod(m, struct hmbuf *), hp);
E 7
I 7
				hostrelease(hp);
E 29
I 29
			hostrelease(hp);
E 29
E 7
I 6
D 28
			}
E 28
E 6
E 2
			hp++;
		}
	}
I 28
D 29
	hostcompress();
E 29
I 29
	hostcompress(unit);
E 29
E 28
I 3
D 10
	splx(x);
E 10
I 10
D 17
	splx(s);
E 17
E 10
E 3
}

/*
 * Remove a host structure and release
 * any resources it's accumulated.
I 10
D 17
 * This routine is always called at splnet.
E 17
E 10
 */
D 2
h_release(hm, hp)
E 2
I 2
D 3
hostrelease(hm, hp)
E 2
	struct hmbuf *hm;
E 3
I 3
hostrelease(hp)
E 3
	register struct host *hp;
{
D 3
	register struct mbuf *m;
E 3
I 3
D 29
	register struct mbuf *m, **mprev, *mh = dtom(hp);
E 29
I 29
D 31
	struct mbuf *mh = dtom(hp);
E 31
E 29
E 3

I 29
D 31
	hostflush(hp);
	hp->h_flags = 0;
E 31
I 31
	if (hp->h_q)
		hostflush(hp);
E 31
	hp->h_rfnm = 0;
D 31
	--mtod(mh, struct hmbuf *)->hm_count;
E 31
I 31
	if (hp->h_flags & HF_INUSE)
		--mtod(dtom(hp), struct hmbuf *)->hm_count;
	hp->h_flags = 0;
E 31
}

/*
 * Flush the message queue for a host.
 */
hostflush(hp)
	register struct host *hp;
{
D 33
	register struct mbuf *m, **mprev;
E 33
I 33
	register struct mbuf *m;
E 33

E 29
D 2
COUNT(H_RELEASE);
printf("h_release(%x,%x)\n", hm, hp);
E 2
I 2
D 13
COUNT(HOSTRELEASE);
E 13
D 3
printf("hostrelease(%x,%x)\n", hm, hp);
E 3
E 2
	/*
	 * Discard any packets left on the waiting q
	 */
D 2
	while (m = hp->h_q) {
		hp->h_q = m->m_act;
E 2
I 2
	if (m = hp->h_q) {
D 4
		m = m->m_next;
		hp->h_q->m_next = 0;
E 4
I 4
		register struct mbuf *n;

		do {
			n = m->m_act;
			m_freem(m);
			m = n;
		} while (m != hp->h_q);
E 4
		hp->h_q = 0;
I 29
		hp->h_qcnt = 0;
E 29
E 2
D 4
		m_freem(m);
E 4
	}
I 11
D 29
	hp->h_flags = 0;
I 22
	hp->h_rfnm = 0;
E 22
E 11
D 3
	/*
	 * We could compact the database here, but is
	 * it worth it?  For now we assume not and just
	 * handle the simple case.
	 */
D 2
printf("h_releasse: count=%d\n", hm->h_count);
E 2
I 2
printf("hostrelease: count=%d\n", hm->hm_count);
E 2
	if (--hm->hm_count || (m = dtom(hm)) == &hosttable)
E 3
I 3
D 28
	if (--mtod(mh, struct hmbuf *)->hm_count)
E 3
		return;
D 3
	m->m_act->m_next = m->m_next;
	m->m_next->m_act = m->m_act;
D 2
	m_freem(m);
E 2
I 2
	(void) m_free(m);
E 3
I 3
	mprev = &hosts;
	while ((m = *mprev) != mh)
		mprev = &m->m_next;
D 10
	*mprev = mh->m_next;
	(void) m_free(mh);
E 10
I 10
	*mprev = m_free(mh);
E 28
I 28
	--mtod(mh, struct hmbuf *)->hm_count;
E 29
E 28
E 10
I 5
}

I 34
/*
 * Release mbufs in host table that contain no entries
 * currently in use.  Must be called at splimp.
 */
E 34
D 28
/*
 * Remove a packet from the holding q.
 * The RFNM counter is also bumped.
 */
struct mbuf *
hostdeque(hp)
	register struct host *hp;
E 28
I 28
D 29
hostcompress()
E 29
I 29
hostcompress(unit)
	int unit;
E 29
E 28
{
D 28
	register struct mbuf *m;
E 28
I 28
	register struct mbuf *m, **mprev;
I 34
	struct imp_softc *sc = &imp_softc[unit];
E 34
E 28

D 28
	hp->h_rfnm--;
	HOST_DEQUE(hp, m);
	if (m)
		return (m);
	if (hp->h_rfnm == 0)
		hostfree(hp);
	return (0);
E 28
I 28
D 29
	mprev = &hosts;
E 29
I 29
D 34
	mprev = &imp_softc[unit].imp_hosts;
E 34
I 34
	mprev = &sc->imp_hosts;
	sc->imp_hostq = 0;
E 34
E 29
	while (m = *mprev) {
		if (mtod(m, struct hmbuf *)->hm_count == 0)
			*mprev = m_free(m);
		else
			mprev = &m->m_next;
	}
E 28
I 10
}

/*
 * Host data base timer routine.
 * Decrement timers on structures which are
 * waiting to be deallocated.  On expiration
 * release resources, possibly deallocating
 * mbuf associated with structure.
 */
hostslowtimo()
{
	register struct mbuf *m;
	register struct host *hp, *lp;
I 30
	struct imp_softc *sc;
E 30
	struct hmbuf *hm;
I 24
D 28
	struct mbuf *mnext;
E 24
D 17
	int s = splnet();
E 17
I 17
	int s = splimp();
E 28
I 28
D 29
	int s = splimp(), any = 0;
E 29
I 29
	int s = splimp(), unit, any;
I 31
D 32
	extern int imppri;
E 32
E 31
E 29
E 28
E 17

D 13
COUNT(HOSTSLOWTIMO);
E 13
D 24
	for (m = hosts; m; m = m->m_next) {
E 24
I 24
D 28
	for (m = hosts; m; m = mnext) {
		mnext = m->m_next;
E 28
I 28
D 29
	for (m = hosts; m; m = m->m_next) {
E 29
I 29
	for (unit = 0; unit < NIMP; unit++) {
	    any = 0;
D 30
	    for (m = imp_softc[unit].imp_hosts; m; m = m->m_next) {
E 30
I 30
	    sc = &imp_softc[unit];
	    for (m = sc->imp_hosts; m; m = m->m_next) {
E 30
E 29
E 28
E 24
		hm = mtod(m, struct hmbuf *);
		hp = hm->hm_hosts; 
		lp = hp + HPMBUF;
D 12
		while (hm->hm_count > 0 && hp < lp) {
E 12
I 12
		for (; hm->hm_count > 0 && hp < lp; hp++) {
E 12
D 24
			if (hp->h_flags & HF_INUSE)
				continue;
			if (hp->h_timer && --hp->h_timer == 0)
E 24
I 24
D 28
			if (hp->h_timer && --hp->h_timer == 0) {
				if (hp->h_rfnm)
D 26
				    log(KERN_RECOV,
E 26
I 26
				    log(LOG_WARNING,
E 26
					"imp?: host %x, lost %d rfnms\n",
D 25
					ntohs(hp->h_addr.s_addr), hp->h_rfnm);
E 25
I 25
					ntohl(hp->h_addr.s_addr), hp->h_rfnm);
E 25
E 24
				hostrelease(hp);
E 28
I 28
		    if (hp->h_timer && --hp->h_timer == 0) {
			if (hp->h_rfnm) {
D 29
			    log(LOG_WARNING,
			        "imp%d: host %d/imp %d, lost %d rfnms\n",
			        hp->h_unit, hp->h_host, ntohs(hp->h_imp),
			        hp->h_rfnm);
			    imp_softc[hp->h_unit].imp_lostrfnm += hp->h_rfnm;
			    hp->h_rfnm = 0;
			    if (hp->h_q) {
				imprestarthost(hp);
				continue;
			    }
E 29
I 29
D 31
				log(LOG_WARNING,
E 31
I 31
D 32
				log(imppri,
E 32
I 32
				log(LOG_INFO,			/* XXX */
E 32
E 31
				    "imp%d: host %d/imp %d, lost rfnm\n",
				    unit, hp->h_host, ntohs(hp->h_imp));
D 31
				imprestarthost(unit, hp);
E 29
E 28
I 24
			}
I 28
D 29
			any = 1;
			hostrelease(hp);
E 29
I 29
			if (hp->h_rfnm == 0 && hp->h_qcnt == 0) {
E 31
I 31
				sc->imp_lostrfnm++;
				imprestarthost(sc, hp);
			} else {
E 31
				any = 1;
				hostrelease(hp);
I 30
				if (sc->imp_hostq == m)
					sc->imp_hostq = 0;
E 30
			}
E 29
		    }
E 28
E 24
D 12
			hp++;
E 12
		}
I 29
	    }
D 30
	    if (any)
E 30
I 30
D 31
	    if (any) {
E 31
I 31
	    if (any)
E 31
E 30
		hostcompress(unit);
I 30
D 31
	    }
E 31
E 30
E 29
	}
I 28
D 29
	if (any)
		hostcompress();
E 29
E 28
D 17
	splx(s);
E 17
I 17
D 18
	splimp(s);
E 18
I 18
	splx(s);
E 18
E 17
E 10
E 5
E 3
E 2
}
I 19
#endif
E 19
E 1
