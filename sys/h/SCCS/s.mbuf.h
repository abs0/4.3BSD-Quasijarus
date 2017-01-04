h17125
s 00001/00001/00178
d D 7.10 88/02/08 10:53:23 karels 49 47
c update copyright dates
e
s 00009/00003/00172
d D 7.8.1.2 88/02/08 10:52:35 karels 48 46
c update copyright on branch
e
s 00008/00002/00171
d D 7.9 87/12/30 11:59:22 bostic 47 45
c add Berkeley header
e
s 00000/00000/00175
d D 7.8.1.1 87/10/06 14:22:50 karels 46 45
x 41 40
c branch version without malloc (for monet and dist)
e
s 00017/00006/00156
d D 7.8 87/07/03 12:15:21 karels 45 41
c fix potential bug when cluster allocation fails;
c add MCLBYTES for larger page sizes
e
s 00017/00006/00156
d R 7.8 87/07/03 12:11:34 karels 44 41
c fix potential bug when cluster allocation fails; 
c add MCLBYTES for larger page sizes
e
s 00017/00006/00156
d R 7.8 87/07/03 11:24:26 karels 43 41
c fix potential bug when cluster allocation fails; 
c add MCLBYTES for larger page sizes
e
s 00014/00005/00157
d R 7.8 87/06/30 18:12:05 karels 42 41
c fix potential bug when cluster allocation fails;
c add MCLBYTES for larger page sizes
e
s 00001/00002/00161
d D 7.7 87/06/21 18:13:26 mckusick 41 40
c MPG_SPACE is replaced by malloc
e
s 00000/00001/00163
d D 7.6 87/06/20 14:26:15 mckusick 40 39
c no more MT_ZOMBIE's
e
s 00008/00005/00156
d D 7.5 87/02/02 18:02:02 karels 39 38
c more statistics
e
s 00004/00000/00157
d D 7.4 86/12/03 22:24:13 karels 38 37
c more mbufs for gateways
e
s 00002/00002/00155
d D 7.3 86/09/11 06:20:02 karels 37 36
x 36
c better fix for MCLGET race, call m_clalloc from MCLALLOC
e
s 00005/00003/00154
d D 7.2 86/09/04 19:16:08 karels 36 34
c need to splimp in MCLGET for calling m_clalloc
e
s 00005/00003/00154
d R 7.2 86/09/04 11:32:46 karels 35 34
c need to call m_clalloc at splimp from MCLALLOC
e
s 00001/00001/00156
d D 7.1 86/06/04 23:24:49 mckusick 34 33
c 4.3BSD release version
e
s 00001/00001/00156
d D 6.12 86/02/21 19:04:54 karels 33 32
c missed arg to m_clalloc
e
s 00029/00005/00128
d D 6.11 86/02/18 16:35:39 karels 32 30
c clean up cluster allocation
e
s 00028/00006/00127
d R 6.11 86/02/18 16:26:31 karels 31 30
c clean up cluster allocation
e
s 00000/00004/00133
d D 6.10 85/12/19 16:18:34 karels 30 29
c rm bbnnet
e
s 00006/00000/00131
d D 6.9 85/09/16 23:32:53 karels 29 28
c pullup a bit extra if wasy
e
s 00002/00002/00129
d D 6.8 85/09/05 15:31:43 karels 28 27
c full sized mbcluster pool; fix wakeup
e
s 00005/00000/00126
d D 6.7 85/08/22 10:00:31 walsh 27 26
c bbn net code currently requires 256 byte mbufs for protocol state
e
s 00001/00001/00125
d D 6.6 85/06/29 12:13:34 karels 26 24
c off by one in MFREE
e
s 00001/00001/00125
d R 6.6 85/06/29 12:09:10 karels 25 24
c off by one in MFREE
e
s 00007/00001/00119
d D 6.5 85/06/08 15:01:09 mckusick 24 23
c Add copyright
e
s 00007/00001/00113
d D 6.4 85/05/05 23:27:34 karels 23 22
c implement M_WAIT
e
s 00001/00000/00113
d D 6.3 85/03/07 22:00:54 karels 22 21
c new type
e
s 00005/00004/00108
d D 6.2 84/08/21 10:16:15 karels 21 20
c add RIGHTS type for mbufs, use m_act correctly for queuing datagrams
c (for sam)
e
s 00000/00000/00112
d D 6.1 83/07/29 06:13:02 sam 20 19
c 4.2 distribution
e
s 00001/00001/00111
d D 4.18 83/03/25 11:51:07 sam 19 18
c make histogram very large so we don't have to change this file again
e
s 00001/00001/00111
d D 4.17 83/01/17 21:14:54 sam 18 16
c more machine independet
e
s 00001/00001/00111
d R 4.17 83/01/17 15:47:30 sam 17 16
c machine independent?
e
s 00028/00011/00084
d D 4.16 82/12/14 17:20:10 sam 16 15
c typed mbufs
e
s 00001/00001/00094
d D 4.15 82/10/20 01:56:58 root 15 14
c lint
e
s 00002/00001/00093
d D 4.14 82/10/05 22:09:04 root 14 13
c MGET sets m_off to MMINOFF
e
s 00001/00007/00093
d D 4.13 82/06/14 22:17:00 wnj 13 12
c get rid of m_mbcommitted
e
s 00020/00011/00080
d D 4.12 82/05/18 21:48:03 sam 12 11
c rethink statistics
e
s 00003/00000/00088
d D 4.11 82/01/24 18:46:12 wnj 11 10
c M_COPYALL
e
s 00001/00001/00087
d D 4.10 81/12/23 14:07:39 root 10 9
c m_pullup declared struct mbuf *
e
s 00004/00002/00084
d D 4.9 81/12/20 15:29:51 root 9 8
c consistency checks on free/alloc
e
s 00010/00004/00076
d D 4.8 81/12/09 20:49:21 wnj 8 7
c pages->clusters
e
s 00003/00003/00077
d D 4.7 81/11/29 22:14:05 wnj 7 6
c lint & wkend editing
e
s 00014/00015/00066
d D 4.6 81/11/26 11:53:47 wnj 6 5
c before carry to arpavax
e
s 00001/00001/00080
d D 4.5 81/11/18 15:46:51 wnj 5 4
c more cleanup
e
s 00001/00001/00080
d D 4.4 81/11/14 16:51:04 wnj 4 3
c just before overlay of ip
e
s 00017/00013/00064
d D 4.3 81/11/08 16:39:18 wnj 3 2
c first listing
e
s 00013/00009/00064
d D 4.2 81/10/29 20:51:46 wnj 2 1
c misc changes
e
s 00073/00000/00000
d D 4.1 81/10/29 17:39:02 wnj 1 0
c date and time created 81/10/29 17:39:02 by wnj
e
u
U
f b 
t
T
I 1
D 12
/* %M% %I% %E% */
E 12
I 12
D 24
/*	%M%	%I%	%E%	*/
E 24
I 24
/*
D 34
 * Copyright (c) 1982 Regents of the University of California.
E 34
I 34
D 48
D 49
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 49
I 49
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 49
E 34
D 47
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 48
I 48
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 48
E 47
I 47
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 47
 *
 *	%W% (Berkeley) %G%
 */
E 24
E 12

/*
 * Constants related to memory allocator.
 */
I 27
D 30
#ifdef BBNNET
#define MSIZE		256
#else
E 30
E 27
D 6
#define	PGSIZE		1024
E 6
#define	MSIZE		128			/* size of an mbuf */
I 27
D 30
#endif
E 30

I 45
#if CLBYTES > 1024
#define	MCLBYTES	1024
#define	MCLSHIFT	10
#define	MCLOFSET	(MCLBYTES - 1)
#else
#define	MCLBYTES	CLBYTES
#define	MCLSHIFT	CLSHIFT
#define	MCLOFSET	CLOFSET
#endif

E 45
E 27
#define	MMINOFF		12			/* mbuf header length */
#define	MTAIL		4
#define	MMAXOFF		(MSIZE-MTAIL)		/* offset where data ends */
#define	MLEN		(MSIZE-MMINOFF-MTAIL)	/* mbuf data length */
I 38
#ifdef GATEWAY
#define	NMBCLUSTERS	512
#else
E 38
D 3
#define	NMPAGES		256
E 3
I 3
D 7
#define	NMBPAGES	256
E 7
I 7
#define	NMBCLUSTERS	256
I 38
#endif
E 38
I 12
#define	NMBPCL		(CLBYTES/MSIZE)		/* # mbufs per cluster */
E 12
E 7
E 3

/*
 * Macros for type conversion
D 8
 *
 * CONSTANTS HERE ARE A CROCK
E 8
 */

D 6
/* network page map number to virtual address, and back */
D 3
#define	pftom(x) ((struct mbuf *)((x << 10) + (int)netutl))
#define	mtopf(x) ((((int)x & ~0x3ff) - (int)netutl) >> 10)
E 3
I 3
#define	pftom(x) ((struct mbuf *)((x << 10) + (int)mbutl))
#define	mtopf(x) ((((int)x & ~0x3ff) - (int)mbutl) >> 10)
E 6
I 6
/* network cluster number to virtual address, and back */
D 45
#define	cltom(x) ((struct mbuf *)((int)mbutl + ((x) << CLSHIFT)))
#define	mtocl(x) (((int)x - (int)mbutl) >> CLSHIFT)
E 45
I 45
#define	cltom(x) ((struct mbuf *)((int)mbutl + ((x) << MCLSHIFT)))
#define	mtocl(x) (((int)x - (int)mbutl) >> MCLSHIFT)
E 45
E 6
E 3

/* address in mbuf to mbuf head */
D 6
#define	dtom(x)		((struct mbuf *)((int)x & ~0x7f))
#define	mtoff(x) 	(((int)x & 0x3ff) >> 7)
E 6
I 6
#define	dtom(x)		((struct mbuf *)((int)x & ~(MSIZE-1)))

/* mbuf head, to typed data */
E 6
#define	mtod(x,t)	((t)((int)(x) + (x)->m_off))

struct mbuf {
	struct	mbuf *m_next;		/* next buffer in chain */
	u_long	m_off;			/* offset of data */
	short	m_len;			/* amount of data in this mbuf */
D 9
	short	m_cnt;			/* reference count */
E 9
I 9
D 16
	short	m_free;			/* is mbuf free? (consistency check) */
E 16
I 16
	short	m_type;			/* mbuf type (0 == free) */
E 16
E 9
	u_char	m_dat[MLEN];		/* data storage */
	struct	mbuf *m_act;		/* link in higher-level mbuf list */
};
D 3
struct	mbuf *mfree, *mpfree;
int	nmpfree;
char	mprefcnt[NMPAGES];
struct	mbuf *m_get(), *m_free(), *m_more();
E 3

I 16
/* mbuf types */
#define	MT_FREE		0	/* should be on free list */
#define	MT_DATA		1	/* dynamic (data) allocation */
#define	MT_HEADER	2	/* packet header */
#define	MT_SOCKET	3	/* socket structure */
#define	MT_PCB		4	/* protocol control block */
#define	MT_RTABLE	5	/* routing tables */
#define	MT_HTABLE	6	/* IMP host tables */
#define	MT_ATABLE	7	/* address resolution tables */
#define	MT_SONAME	8	/* socket name */
D 40
#define	MT_ZOMBIE	9	/* zombie proc status */
E 40
#define	MT_SOOPTS	10	/* socket options */
#define	MT_FTABLE	11	/* fragment reassembly header */
I 21
#define	MT_RIGHTS	12	/* access rights */
I 22
#define	MT_IFADDR	13	/* interface address */
E 22
E 21

E 16
I 3
D 8
#define	M_WAIT	1
E 8
I 8
/* flags to m_get */
#define	M_DONTWAIT	0
#define	M_WAIT		1
E 8

I 8
/* flags to m_pgalloc */
#define	MPG_MBUFS	0		/* put new mbufs on free list */
#define	MPG_CLUSTERS	1		/* put new clusters on free list */
D 41
#define	MPG_SPACE	2		/* don't free; caller wants space */
E 41

I 11
/* length to m_copy to copy all */
#define	M_COPYALL	1000000000

I 29
/*
 * m_pullup will pull up additional length if convenient;
 * should be enough to hold headers of second-level and higher protocols. 
 */
#define	MPULL_EXTRA	32

E 29
E 11
E 8
E 3
D 16
#define	MGET(m, i) \
E 16
I 16
#define	MGET(m, i, t) \
E 16
D 2
	{ int ms = spl_imp(); \
E 2
I 2
	{ int ms = splimp(); \
E 2
	  if ((m)=mfree) \
D 2
		{ netcb.n_bufs--; mfree = (m)->m_next; (m)->m_next = 0; } \
E 2
I 2
D 9
		{ mbstat.m_bufs--; mfree = (m)->m_next; (m)->m_next = 0; } \
E 9
I 9
D 16
		{ if ((m)->m_free == 0) panic("mget"); (m)->m_free = 0; \
D 12
		  mbstat.m_bufs--; mfree = (m)->m_next; (m)->m_next = 0; } \
E 12
I 12
D 14
		  mbstat.m_mbfree--; mfree = (m)->m_next; (m)->m_next = 0; } \
E 14
I 14
		  mbstat.m_mbfree--; mfree = (m)->m_next; (m)->m_next = 0; \
E 16
I 16
		{ if ((m)->m_type != MT_FREE) panic("mget"); (m)->m_type = t; \
D 21
		  mbstat.m_mbfree--; mbstat.m_mtypes[t]++; \
E 21
I 21
		  mbstat.m_mtypes[MT_FREE]--; mbstat.m_mtypes[t]++; \
E 21
		  mfree = (m)->m_next; (m)->m_next = 0; \
E 16
		  (m)->m_off = MMINOFF; } \
E 14
E 12
E 9
E 2
	  else \
D 16
		(m) = m_more(i); \
E 16
I 16
		(m) = m_more(i, t); \
E 16
	  splx(ms); }
D 6
#define	MPGET(m, i) \
E 6
I 6
D 32
#define	MCLGET(m, i) \
E 32
I 32
/*
 * Mbuf page cluster macros.
 * MCLALLOC allocates mbuf page clusters.
 * Note that it works only with a count of 1 at the moment.
I 36
 * It must be called at splimp.
E 36
 * MCLGET adds such clusters to a normal mbuf.
D 45
 * m->m_len is set to CLBYTES upon success.
E 45
I 45
 * m->m_len is set to MCLBYTES upon success, and to MLEN on failure.
E 45
 * MCLFREE frees clusters allocated by MCLALLOC.
 */
#define	MCLALLOC(m, i) \
E 32
E 6
D 2
	{ int ms = spl_imp(); \
E 2
I 2
D 36
	{ int ms = splimp(); \
I 37
	  if (mclfree == 0) \
		(void)m_clalloc((i), MPG_CLUSTERS, M_DONTWAIT); \
E 37
E 2
D 6
	  if ((m)=mpfree) \
	      { ++mprefcnt[mtopf(m)]; nmpfree--; mpfree = (m)->m_next; } \
E 6
I 6
	  if ((m)=mclfree) \
E 36
I 36
	{ if ((m)=mclfree) \
E 36
D 12
	      { ++mclrefcnt[mtocl(m)]; nmclfree--; mclfree = (m)->m_next; } \
E 12
I 12
	     {++mclrefcnt[mtocl(m)];mbstat.m_clfree--;mclfree = (m)->m_next;} \
E 12
E 6
D 36
	  splx(ms); }
E 36
I 36
	}
E 36
I 32
#define	M_HASCL(m)	((m)->m_off >= MSIZE)
D 45
#define	MTOCL(m)	((struct mbuf *)(mtod((m), int)&~CLOFSET))
E 45
I 45
#define	MTOCL(m)	((struct mbuf *)(mtod((m), int) &~ MCLOFSET))
E 45

#define	MCLGET(m) \
	{ struct mbuf *p; \
I 36
	  int ms = splimp(); \
E 36
D 37
	  if (mclfree == 0) \
D 33
		(void)m_clalloc(1, MPG_CLUSTERS); \
E 33
I 33
		(void)m_clalloc(1, MPG_CLUSTERS, M_DONTWAIT); \
E 37
E 33
	  MCLALLOC(p, 1); \
	  if (p) { \
		(m)->m_off = (int)p - (int)(m); \
D 45
		(m)->m_len = CLBYTES; \
	  } \
E 45
I 45
		(m)->m_len = MCLBYTES; \
	  } else \
		(m)->m_len = MLEN; \
E 45
I 36
	  splx(ms); \
E 36
	}
#define	MCLFREE(m) { \
	if (--mclrefcnt[mtocl(m)] == 0) \
	    { (m)->m_next = mclfree;mclfree = (m);mbstat.m_clfree++;} \
	}
E 32
#define	MFREE(m, n) \
D 2
	{ int ms = spl_imp(); \
E 2
I 2
	{ int ms = splimp(); \
I 9
D 16
	  if ((m)->m_free) panic("mfree"); (m)->m_free = 1; \
E 16
I 16
	  if ((m)->m_type == MT_FREE) panic("mfree"); \
D 21
	  mbstat.m_mtypes[(m)->m_type]--; (m)->m_type = MT_FREE; \
E 21
I 21
	  mbstat.m_mtypes[(m)->m_type]--; mbstat.m_mtypes[MT_FREE]++; \
	  (m)->m_type = MT_FREE; \
E 21
E 16
E 9
E 2
D 26
	  if ((m)->m_off > MSIZE) { \
E 26
I 26
D 32
	  if ((m)->m_off >= MSIZE) { \
E 26
D 18
		(n) = (struct mbuf *)(mtod(m, int)&~0x3ff); \
E 18
I 18
		(n) = (struct mbuf *)(mtod(m, int)&~CLOFSET); \
E 18
D 6
		if (--mprefcnt[mtopf(n)] == 0) \
		    { (n)->m_next = mpfree; mpfree = (n); nmpfree++; } \
E 6
I 6
		if (--mclrefcnt[mtocl(n)] == 0) \
D 12
		    { (n)->m_next = mclfree; mclfree = (n); nmclfree++; } \
E 12
I 12
		    { (n)->m_next = mclfree;mclfree = (n);mbstat.m_clfree++;} \
E 32
I 32
	  if (M_HASCL(m)) { \
		(n) = MTOCL(m); \
		MCLFREE(n); \
E 32
E 12
E 6
	  } \
	  (n) = (m)->m_next; (m)->m_next = mfree; \
D 2
	  (m)->m_off = 0; (m)->m_act = 0; mfree = (m); netcb.n_bufs++; \
E 2
I 2
D 12
	  (m)->m_off = 0; (m)->m_act = 0; mfree = (m); mbstat.m_bufs++; \
E 12
I 12
D 21
	  (m)->m_off = 0; (m)->m_act = 0; mfree = (m); mbstat.m_mbfree++; \
E 21
I 21
	  (m)->m_off = 0; (m)->m_act = 0; mfree = (m); \
E 21
E 12
E 2
D 23
	  splx(ms); }
E 23
I 23
	  splx(ms); \
	  if (m_want) { \
		  m_want = 0; \
D 28
		  wakeup((caddr_t)mfree); \
E 28
I 28
		  wakeup((caddr_t)&mfree); \
E 28
	  } \
	}
E 23
D 6
#define	NMBPG (PGSIZE/MSIZE)		/* mbufs/page */
E 6

I 12
/*
D 13
 * Mbuf statistics.  Clients can committ hunks of space until we are
 * overcommitted by the fraction represented by MBUFOVERALLOCFRAG.
 * We keep track of the amount of space committed, the number
 * of mbufs and clusters allocated from the free memory pool, and
 * the number of mbufs and clusters on our free lists.
E 13
I 13
 * Mbuf statistics.
E 13
 */
D 13
#define	MBUFOVERALLOCFRACTION	3 / 2		/* don't parenthesize ! */
E 13
E 12
I 2
struct mbstat {
D 3
	short	m_bufs;				/* # free msg buffers */
	short	m_hiwat;			/* # free mbufs allocated */
	short	m_lowat;			/* min. # free mbufs */
	short	m_pages;			/* # pages owned by network */
E 3
I 3
D 12
	short	m_bufs;			/* # free msg buffers */
	short	m_hiwat;		/* # free mbufs allocated */
	short	m_lowat;		/* min. # free mbufs */
D 8
	short	m_pages;		/* # pages owned by network */
E 8
I 8
	short	m_clusters;		/* # pages owned by network */
E 12
I 12
D 13
	short	m_mbcommitted;		/* most we'll allow pool size to get */
E 13
D 16
	short	m_mbufs;		/* mbufs obtained from page pool */
	short	m_mbfree;		/* mbufs on our free list */
	short	m_clusters;		/* clusters obtained from page pool */
	short	m_clfree;		/* free clusters */
E 12
E 8
	short	m_drops;		/* times failed to find space */
E 16
I 16
D 39
	short	m_mbufs;	/* mbufs obtained from page pool */
D 21
	short	m_mbfree;	/* mbufs on our free list */
E 21
	short	m_clusters;	/* clusters obtained from page pool */
	short	m_clfree;	/* free clusters */
	short	m_drops;	/* times failed to find space */
D 19
	short	m_mtypes[32];	/* type specific mbuf allocations */
E 19
I 19
	short	m_mtypes[256];	/* type specific mbuf allocations */
E 39
I 39
	u_long	m_mbufs;	/* mbufs obtained from page pool */
	u_long	m_clusters;	/* clusters obtained from page pool */
D 41
	u_long	m_space;	/* interface pages obtained from page pool */
E 41
I 41
	u_long	m_spare;	/* spare field */
E 41
	u_long	m_clfree;	/* free clusters */
	u_long	m_drops;	/* times failed to find space */
	u_long	m_wait;		/* times waited for space */
	u_long	m_drain;	/* times drained protocols for space */
	u_short	m_mtypes[256];	/* type specific mbuf allocations */
E 39
E 19
E 16
E 3
};

E 2
#ifdef	KERNEL
D 3
extern	struct mbuf netutl[];		/* virtual address of net free mem */
extern	struct pte Netmap[];		/* page tables to map Netutl */
E 3
I 3
extern	struct mbuf mbutl[];		/* virtual address of net free mem */
extern	struct pte Mbmap[];		/* page tables to map Netutl */
E 3
I 2
struct	mbstat mbstat;
I 3
D 7
int	nmbpages;
E 7
I 7
D 12
int	nmbclusters;
E 12
I 12
D 15
extern	int nmbclusters;
E 15
I 15
int	nmbclusters;
E 15
E 12
E 7
D 6
struct	mbuf *mfree, *mpfree;
int	nmpfree;
char	mprefcnt[NMBPAGES];
E 6
I 6
struct	mbuf *mfree, *mclfree;
D 12
int	nmclfree;
E 12
D 7
char	mclrefcnt[NMBPAGES];
E 7
I 7
D 28
char	mclrefcnt[NMBCLUSTERS];
E 28
I 28
char	mclrefcnt[NMBCLUSTERS + 1];
E 28
I 23
int	m_want;
E 23
E 7
E 6
D 4
struct	mbuf *m_get(), *m_free(), *m_more();
E 4
I 4
D 5
struct	mbuf *m_get(), *m_getclr(), *m_free(), *m_more();
E 5
I 5
D 10
struct	mbuf *m_get(), *m_getclr(), *m_free(), *m_more(), *m_copy();
E 10
I 10
struct	mbuf *m_get(),*m_getclr(),*m_free(),*m_more(),*m_copy(),*m_pullup();
E 10
I 8
caddr_t	m_clalloc();
E 8
E 5
E 4
E 3
E 2
#endif
D 2
	short	n_bufs;				/* # free msg buffers */
	short	n_hiwat;			/* # free mbufs allocated */
	short	n_lowat;			/* min. # free mbufs */
	short	n_pages;			/* # pages owned by network */
E 2
E 1
