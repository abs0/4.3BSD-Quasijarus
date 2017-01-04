h22592
s 00011/00006/00111
d D 7.6 88/06/29 16:58:12 bostic 15 14
c install approved copyright notice
e
s 00000/00001/00117
d D 7.5 88/05/26 09:43:35 karels 14 13
c lint
e
s 00015/00007/00103
d D 7.4 88/05/06 12:33:09 karels 13 12
c clean up queuing, keep message counts correctly, check for 1822L NOPs, etc
e
s 00017/00009/00093
d D 7.3 88/02/08 10:30:16 karels 12 11
c new copyrights; new IMP interface with H/W, using cb_output rather
c than cb_start (so can start RFNM timer when packet goes out, and output is
c round-robin by destination)
e
s 00015/00004/00087
d D 7.2 88/02/03 17:26:48 karels 11 10
c working with new up/down FSM, dropcount, statistics and host entry
e
s 00001/00001/00090
d D 7.1 86/06/04 23:56:41 mckusick 10 9
c 4.3BSD release version
e
s 00007/00001/00084
d D 6.3 85/06/08 12:32:38 mckusick 9 8
c Add copyright
e
s 00001/00001/00084
d D 6.2 85/03/19 16:18:49 karels 8 7
c move net addresses from interface layer into protocols
e
s 00000/00000/00085
d D 6.1 83/07/29 07:15:35 sam 7 6
c 4.2 distribution
e
s 00017/00002/00068
d D 4.6 82/04/25 18:34:54 sam 6 5
c make host structure deletion timer based
e
s 00012/00011/00058
d D 4.5 82/03/09 17:40:38 root 5 4
c logical host handling, fix up some cruft, ...
e
s 00033/00005/00036
d D 4.4 82/02/21 13:08:29 root 4 3
c cleanup code a bit
e
s 00001/00001/00040
d D 4.3 82/02/16 15:11:57 root 3 2
c first "working" imp driver
e
s 00002/00002/00039
d D 4.2 82/02/12 15:17:05 wnj 2 1
c closer to a working imp driver
e
s 00041/00000/00000
d D 4.1 82/02/06 19:48:09 sam 1 0
c date and time created 82/02/06 19:48:09 by sam
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 10
 * Copyright (c) 1982 Regents of the University of California.
E 10
I 10
D 12
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
D 15
 * Copyright (c) 1982,1986,1988 Regents of the University of California.
E 15
I 15
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 15
 * All rights reserved.
E 12
 *
I 12
 * Redistribution and use in source and binary forms are permitted
D 15
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
I 15
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
E 15
 *
E 12
 *	%W% (Berkeley) %G%
 */
E 9

/*
 * Host structure used with IMP's.
 * Used to hold outgoing packets which
 * would exceed allowed RFNM count.
 *
 * These structures are packed into
 * mbuf's and kept as small as possible.
 */
struct host {
	struct	mbuf *h_q;		/* holding queue */
I 12
	u_short	h_timer;		/* used to stay off deletion */
E 12
D 11
	struct	in_addr h_addr;		/* host's address */
E 11
I 11
	u_short	h_imp;			/* host's imp number */
	u_char	h_host;			/* host's number on imp */
D 12
	u_char	h_unit;			/* imp unit number */
E 12
E 11
D 4
	u_short	h_status;          	/* host status */
E 4
I 4
D 6
	short	h_qcnt;          	/* size of holding q */
E 6
I 6
	u_char	h_qcnt;          	/* size of holding q */
D 12
	u_char	h_timer;		/* used to stay off deletion */
E 12
E 6
E 4
	u_char	h_rfnm;			/* # outstanding rfnm's */
D 6
	u_char	h_refcnt;		/* reference count */
E 6
I 6
	u_char	h_flags;		/* see below */
E 6
};
I 6

/*
 * A host structure is kept around (even when there are no
 * references to it) for a spell to avoid constant reallocation
 * and also to reflect IMP status back to sites which aren't
 * directly connected to the IMP.  When structures are marked
D 13
 * free, a timer is started; when the timer expires the structure
E 13
I 13
 * idle, a timer is started; when the timer expires the structure
E 13
D 12
 * is scavenged.
E 12
I 12
 * is deallocated.  A structure may be reused before the timer expires.
 * A structure holds a reference on the containing mbuf when it is marked
D 13
 * HF_INUSE or its timer is running.
E 13
I 13
 * HF_INUSE.
E 13
E 12
 */
#define	HF_INUSE	0x1
#define	HF_DEAD		(1<<IMPTYPE_HOSTDEAD)
#define	HF_UNREACH	(1<<IMPTYPE_HOSTUNREACH)

I 12
#define	HOSTTIMER	128		/* keep structure around awhile */

E 12
I 11
/*
D 13
 * Mark a host structure free
E 13
I 13
 * Mark a host structure free; used if host entry returned by hostlookup 
 * isn't needed.  h_rfnm must be zero.
E 13
 */
#define	hostfree(hp) { \
D 13
	(hp)->h_flags &= ~HF_INUSE; \
I 12
	(hp)->h_timer = HOSTTIMER; \
E 13
I 13
	if ((hp)->h_timer == 0 && (hp)->h_qcnt == 0 && \
	    (hp)->h_flags & HF_INUSE) \
		hostrelease(hp); \
E 13
E 12
}

E 11
D 12
#define	HOSTTIMER	128		/* keep structure around awhile */
E 6

E 12
D 4
#define	HOSTS_DOWN	0		/* host believed down */
#define HOSTS_UP	128 		/* host up */

E 4
/*
I 13
 * Release a host entry when last rfnm is received.
 */
#define	hostidle(hp)	{ (hp)->h_timer = HOSTTIMER; }

/*
E 13
 * Host structures, as seen inside an mbuf.
D 11
 * Hashing on the host address is used to
E 11
I 11
 * Hashing on the host and imp is used to
E 11
 * select an index into the first mbuf.  Collisions
 * are then resolved by searching successive
 * mbuf's at the same index.  Reclamation is done
D 12
 * automatically at the time a structure is free'd.
E 12
I 12
 * automatically at the time a structure is freed.
E 12
 */
#define	HPMBUF	((MLEN - sizeof(int)) / sizeof(struct host))
I 13
/* don't need to swab as long as HPMBUF is odd */
E 13
D 3
#define	HOSTHASH(a)	((a.s_addr) % HPMBUF)
E 3
I 3
D 4
#define	HOSTHASH(a)	(((a).s_addr&~0x80000000) % HPMBUF)
E 4
I 4
D 11
#if vax
D 8
#define	HOSTHASH(a)	((((a).s_addr>>8)+(a).s_net) % HPMBUF)
E 8
I 8
#define	HOSTHASH(a)	((((a).s_addr>>24)+(a).s_addr) % HPMBUF)
E 11
I 11
#if defined(notdef) && BYTE_ORDER == BIG_ENDIAN
D 13
#define	HOSTHASH(imp, host)	(((imp)+(host)) % HPMBUF)
E 13
I 13
#define	HOSTHASH(imp, host)	((unsigned)(ntohs(imp)+(host)) % HPMBUF)
E 13
#else
D 13
#define	HOSTHASH(imp, host)	((ntohs(imp)+(host)) % HPMBUF)
E 13
I 13
#define	HOSTHASH(imp, host)	((unsigned)((imp)+(host)) % HPMBUF)
E 13
E 11
E 8
#endif
E 4
E 3

I 4
/*
 * In-line expansions for queuing operations on
 * host message holding queue.  Queue is maintained
 * as circular list with the head pointing to the
 * last message in the queue.
 */
#define	HOST_ENQUE(hp, m) { \
	register struct mbuf *n; \
D 5
	hp->h_qcnt++; \
	if ((n = hp->h_q) == 0) \
		hp->h_q = m->m_act = m; \
E 5
I 5
	(hp)->h_qcnt++; \
	if ((n = (hp)->h_q) == 0) \
		(hp)->h_q = (m)->m_act = (m); \
E 5
	else { \
D 5
		m->m_act = n->m_act; \
		hp->h_q = n->m_act = m; \
E 5
I 5
		(m)->m_act = n->m_act; \
		(hp)->h_q = n->m_act = (m); \
E 5
	} \
}
#define	HOST_DEQUE(hp, m) { \
D 5
	if (m = hp->h_q) { \
		if (m->m_act == m) \
			hp->h_q = 0; \
E 5
I 5
	if ((m) = (hp)->h_q) { \
		if ((m)->m_act == (m)) \
			(hp)->h_q = 0; \
E 5
		else { \
D 5
			m = m->m_act; \
			hp->h_q->m_act = m->m_act; \
E 5
I 5
			(m) = (m)->m_act; \
			(hp)->h_q->m_act = (m)->m_act; \
E 5
		} \
D 5
		hp->h_qcnt--; \
E 5
I 5
		(hp)->h_qcnt--; \
		(m)->m_act = 0; \
E 5
	} \
}

E 4
struct hmbuf {
	int	hm_count;		/* # of struct's in use */
	struct	host hm_hosts[HPMBUF];	/* data structures proper */
};

#ifdef KERNEL
D 2
struct host *h_lookup();
struct host *h_enter();
E 2
I 2
struct host *hostlookup();
struct host *hostenter();
I 4
D 14
struct mbuf *hostdeque();
E 14
E 4
E 2
#endif
E 1
