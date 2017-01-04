h60322
s 00010/00005/00439
d D 7.10 88/06/29 17:20:20 bostic 67 66
c install approved copyright notice
e
s 00000/00010/00444
d D 7.9 88/05/26 08:56:36 karels 66 65
c rm unused m_pgfree
e
s 00006/00004/00448
d D 7.8 88/04/09 17:21:19 karels 65 64
c really working m_copydata
e
s 00035/00000/00417
d D 7.7 88/02/27 13:46:54 karels 64 63
c add m_copydata
e
s 00001/00001/00416
d D 7.6 88/02/08 11:05:21 karels 63 61
c update date on copyright
e
s 00009/00003/00412
d D 7.4.1.2 88/02/08 11:04:35 karels 62 60
c update copyright on branch
e
s 00008/00002/00409
d D 7.5 87/12/30 12:01:20 bostic 61 59
c add Berkeley header
e
s 00000/00000/00415
d D 7.4.1.1 87/11/24 14:15:30 karels 60 59
x 56
c branch for tahoe release (no malloc)
e
s 00010/00004/00401
d D 7.4 87/11/23 14:59:02 karels 59 56
c try to make this work when MCLBYTES != CLBYTES !
e
s 00010/00004/00401
d R 7.4 87/11/23 14:57:17 karels 58 56
c try to make this work when MCLBYTES != CLBYTES
e
s 00010/00004/00401
d R 7.4 87/11/23 14:09:00 karels 57 56
c try to make it work when CLBYTES != MCLBYTES
e
s 00000/00004/00405
d D 7.3 87/06/21 18:13:53 mckusick 56 55
c MPG_SPACE is replaced by malloc
e
s 00031/00008/00378
d D 7.2 87/02/02 18:01:48 karels 55 54
c log, not panic, when mbuf map exhausted; more statistics
e
s 00001/00001/00385
d D 7.1 86/06/05 00:15:53 mckusick 54 53
c 4.3BSD release version
e
s 00001/00001/00385
d D 6.10 86/06/01 16:30:13 karels 53 52
c can allocate more clusters later, don't need so many at first
e
s 00001/00001/00385
d D 6.9 85/11/06 18:56:13 karels 52 51
c try to make panic message intelligible
e
s 00057/00030/00329
d D 6.8 85/09/16 20:46:24 karels 51 50
c fix m_adj to work right trimming from tail (there can be 0-length mbufs
c in the chain); make m_pullup use first mbuf if enough room without copying,
c and pullup a bit extra for next-level protocol
e
s 00001/00001/00358
d D 6.7 85/09/05 15:30:50 karels 50 49
c hmm, this tells me something
e
s 00012/00007/00347
d D 6.6 85/06/29 12:19:44 karels 49 48
c cleanups in m_pullup: remove unneeded length test, be careful
c to leave offset pointing in current mbuf [cluster], don't go an extra turn
c around the loop with a zero count
e
s 00007/00001/00347
d D 6.5 85/06/08 14:58:08 mckusick 48 47
c Add copyright
e
s 00039/00018/00309
d D 6.4 85/05/27 20:00:28 karels 47 46
c implement M_WAIT; reduce redundant splimp's
e
s 00009/00009/00318
d D 6.3 84/08/29 20:27:44 bloom 46 45
c Change to includes.  no more ../h
e
s 00001/00003/00326
d D 6.2 84/02/22 08:48:05 karels 45 44
c m_copy replicates type per mbuf (not all headers)
e
s 00000/00000/00329
d D 6.1 83/07/29 06:46:20 sam 44 43
c 4.2 distribution
e
s 00000/00000/00329
d D 1.43 83/05/27 12:50:19 sam 43 42
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00009/00004/00320
d D 1.42 82/12/17 11:49:08 sam 42 41
c sun merge
e
s 00016/00013/00308
d D 1.41 82/12/14 17:10:24 sam 41 40
c typed mbufs
e
s 00001/00001/00320
d D 1.40 82/10/21 23:53:48 root 40 39
c lint
e
s 00001/00000/00320
d D 1.39 82/10/21 20:59:30 root 39 38
c lint
e
s 00000/00001/00320
d D 1.38 82/10/09 05:38:49 wnj 38 37
c fix up header file dependencies 
e
s 00002/00006/00319
d D 1.37 82/10/05 21:57:53 root 37 36
c send(... SOF_OOB) and receive(... SOF_PREVIEW)
e
s 00000/00011/00325
d D 1.36 82/06/20 12:21:41 sam 36 35
c purge COUNT crap now that we have gprof
e
s 00000/00023/00336
d D 1.35 82/06/14 22:16:59 wnj 35 34
c get rid of m_release stuff
e
s 00001/00001/00358
d D 1.34 82/05/19 01:19:39 sam 34 33
c make more lucid
e
s 00006/00009/00353
d D 1.33 82/05/18 21:46:28 sam 33 32
c rethink statistics?
e
s 00010/00009/00352
d D 1.32 82/03/13 12:54:36 sam 32 31
c lint
e
s 00003/00000/00358
d D 1.31 82/03/12 16:03:33 sam 31 30
c keep lint happy
e
s 00011/00011/00347
d D 1.30 82/03/09 20:32:17 root 30 29
c 
e
s 00002/00002/00356
d D 1.29 82/02/08 23:02:38 root 29 28
c bug fix in m_pullup
e
s 00002/00001/00356
d D 1.28 82/01/25 18:38:18 wnj 28 27
c bug fixes (round 1)
e
s 00007/00003/00350
d D 1.27 82/01/24 18:32:10 wnj 27 26
c M_COPYALL len argument to m_copy causes all to be copied
e
s 00002/00000/00351
d D 1.26 82/01/19 06:39:20 wnj 26 25
c closef parameter indicating whether error return
c to complete non-blc
e
s 00034/00003/00317
d D 1.25 81/12/23 14:09:42 root 25 24
c m_pullup
e
s 00001/00000/00319
d D 1.24 81/12/21 11:54:27 root 24 23
c #undef m_more
e
s 00001/00000/00318
d D 1.23 81/12/20 15:28:54 root 23 22
c m_free set to 0
e
s 00000/00004/00318
d D 1.22 81/12/12 18:07:35 root 22 21
c delete prints
e
s 00000/00002/00322
d D 1.21 81/12/12 17:49:34 root 21 20
c almost works
e
s 00001/00000/00323
d D 1.20 81/12/09 21:20:15 wnj 20 19
c cleanup
e
s 00109/00124/00214
d D 1.19 81/12/09 20:53:55 wnj 19 18
c new and cleaner version
e
s 00001/00001/00337
d D 1.18 81/11/30 16:22:51 wnj 18 17
c lint
e
s 00026/00016/00312
d D 1.17 81/11/26 11:58:23 wnj 17 16
c before carry to arpavax
e
s 00011/00005/00317
d D 1.16 81/11/22 10:49:01 wnj 16 15
c fix reserve/release to work in m_hiwat and shift lowat
e
s 00004/00006/00318
d D 1.15 81/11/21 22:13:20 root 15 14
c fix mbuf accounting
e
s 00006/00004/00318
d D 1.14 81/11/21 15:13:22 wnj 14 13
c m_reserve/m_release args scale
e
s 00002/00002/00320
d D 1.13 81/11/20 14:43:11 wnj 13 12
c more lint
e
s 00001/00000/00321
d D 1.12 81/11/20 00:45:57 wnj 12 11
c linted
e
s 00062/00006/00259
d D 1.11 81/11/18 15:45:06 wnj 11 10
c more cleanup
e
s 00022/00020/00243
d D 1.10 81/11/16 14:20:47 wnj 10 9
c lint
e
s 00015/00000/00248
d D 1.9 81/11/14 16:43:39 wnj 9 8
c before header overlay
e
s 00020/00046/00228
d D 1.8 81/11/08 16:55:00 wnj 8 7
c first listing
e
s 00018/00000/00256
d D 1.7 81/11/04 00:28:57 wnj 7 6
c more cleanups, fields in ucb.h
e
s 00055/00035/00201
d D 1.6 81/10/30 15:11:35 wnj 6 5
c page at a time version
e
s 00018/00037/00218
d D 1.5 81/10/29 20:27:01 wnj 5 4
c cleanup of header files
e
s 00002/00002/00253
d D 1.4 81/10/28 19:35:17 wnj 4 3
c mtod with type casts
e
s 00020/00002/00235
d D 1.3 81/10/28 16:37:51 wnj 3 2
c first compiled halfbrid... not working yet
e
s 00003/00001/00234
d D 1.2 81/10/23 10:07:08 wnj 2 1
c first working version with page macros and new snd_copy
e
s 00235/00000/00000
d D 1.1 81/10/22 13:44:41 wnj 1 0
c date and time created 81/10/22 13:44:41 by wnj
e
u
U
f b 
t
T
I 1
D 2
/* mbuf.c 1.6 81/10/21 */
E 2
I 2
D 3
/* %M% %I% %E% */
E 3
I 3
D 4
/* mbuf.c 1.2 81/10/23 */
E 4
I 4
D 10
/* %M% %I% %E% */
E 10
I 10
D 48
/*	%M%	%I%	%E%	*/
E 48
I 48
/*
D 54
 * Copyright (c) 1982 Regents of the University of California.
E 54
I 54
D 62
D 63
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 63
I 63
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 63
E 54
D 61
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 62
I 62
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 62
E 61
I 61
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 67
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 67
I 67
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
E 67
E 61
 *
 *	%W% (Berkeley) %G%
 */
E 48
E 10
E 4
E 3
E 2

I 42
#include "../machine/pte.h"

E 42
D 46
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
D 42
#include "../h/pte.h"
E 42
#include "../h/cmap.h"
#include "../h/map.h"
I 3
#include "../h/mbuf.h"
E 3
D 5
#include "../bbnnet/net.h"
D 3
#include "../bbnnet/mbuf.h"
E 3
#include "../bbnnet/tcp.h"
#include "../bbnnet/ip.h"
E 5
I 5
D 8
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
D 6
#include "../inet/tcp.h"
E 6
#include "../inet/ip.h"
I 6
#include "../inet/tcp.h"
E 8
I 8
D 10
#include "../net/inet_systm.h"		/* ### */
E 10
I 10
D 17
#include "../net/inet_systm.h"		/* XXX */
E 17
I 17
D 38
#include "../net/in_systm.h"		/* XXX */
E 38
E 17
E 10
E 8
E 6
E 5
#include "../h/vm.h"
I 39
#include "../h/kernel.h"
E 46
I 46
#include "param.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "cmap.h"
#include "map.h"
#include "mbuf.h"
#include "vm.h"
#include "kernel.h"
I 55
#include "syslog.h"
#include "domain.h"
#include "protosw.h"
E 55
E 46
E 39

I 19
mbinit()
{
I 47
	int s;
E 47
D 21
	register struct mbuf *m;
	register i;
E 21

I 59
#if CLBYTES < 4096
#define NCL_INIT	(4096/CLBYTES)
#else
#define NCL_INIT	1
#endif
E 59
D 36
COUNT(MBINIT);
E 36
D 35
	if (m_reserve(32) == 0)
		goto bad;
E 35
D 42
	if (m_clalloc(4, MPG_MBUFS) == 0)
E 42
I 42
D 47
	if (m_clalloc(4096/CLBYTES, MPG_MBUFS) == 0)
E 47
I 47
	s = splimp();
D 59
	if (m_clalloc(4096/CLBYTES, MPG_MBUFS, M_DONTWAIT) == 0)
E 59
I 59
	if (m_clalloc(NCL_INIT, MPG_MBUFS, M_DONTWAIT) == 0)
E 59
E 47
E 42
		goto bad;
D 42
	if (m_clalloc(32, MPG_CLUSTERS) == 0)
E 42
I 42
D 47
	if (m_clalloc(8*4096/CLBYTES, MPG_CLUSTERS) == 0)
E 47
I 47
D 53
	if (m_clalloc(8*4096/CLBYTES, MPG_CLUSTERS, M_DONTWAIT) == 0)
E 53
I 53
D 59
	if (m_clalloc(4096/CLBYTES, MPG_CLUSTERS, M_DONTWAIT) == 0)
E 59
I 59
	if (m_clalloc(NCL_INIT, MPG_CLUSTERS, M_DONTWAIT) == 0)
E 59
E 53
E 47
E 42
		goto bad;
I 47
	splx(s);
E 47
	return;
bad:
	panic("mbinit");
}

I 47
/*
 * Must be called at splimp.
 */
I 55
/* ARGSUSED */
E 55
E 47
caddr_t
D 47
m_clalloc(ncl, how)
E 47
I 47
m_clalloc(ncl, how, canwait)
E 47
	register int ncl;
	int how;
{
	int npg, mbx;
	register struct mbuf *m;
	register int i;
I 55
	static int logged;
E 55
D 47
	int s;
E 47

D 36
COUNT(M_CLALLOC);
E 36
	npg = ncl * CLSIZE;
I 26
D 47
	s = splimp();		/* careful: rmalloc isn't reentrant */
E 47
E 26
D 40
	mbx = rmalloc(mbmap, npg);
E 40
I 40
	mbx = rmalloc(mbmap, (long)npg);
E 40
I 26
D 47
	splx(s);
E 26
D 22
printf("ncl %d how %d npg %d mbx %d\n", ncl, how, npg, mbx);
E 22
	if (mbx == 0)
E 47
I 47
	if (mbx == 0) {
D 55
		if (canwait == M_WAIT)
D 52
			panic("out of mbuf map");
E 52
I 52
			panic("out of mbufs: map full");
E 55
I 55
		if (logged == 0) {
			logged++;
			log(LOG_ERR, "mbuf map full\n");
		}
E 55
E 52
E 47
		return (0);
I 47
	}
E 47
D 59
	m = cltom(mbx / CLSIZE);
E 59
I 59
	m = cltom(mbx * NBPG / MCLBYTES);
E 59
D 34
	if (memall(&Mbmap[mbx], ncl * CLSIZE, proc, CSYS) == 0)
E 34
I 34
D 42
	if (memall(&Mbmap[mbx], npg, proc, CSYS) == 0)
E 42
I 42
	if (memall(&Mbmap[mbx], npg, proc, CSYS) == 0) {
D 47
		s = splimp();
E 47
		rmfree(mbmap, (long)npg, (long)mbx);
D 47
		splx(s);
E 47
E 42
E 34
		return (0);
I 42
	}
E 42
	vmaccess(&Mbmap[mbx], (caddr_t)m, npg);
D 22
printf("m %x &Mbmap[mbx] %x\n", m, &Mbmap[mbx]);
E 22
	switch (how) {

	case MPG_CLUSTERS:
I 59
		ncl = ncl * CLBYTES / MCLBYTES;
E 59
D 47
		s = splimp();
E 47
		for (i = 0; i < ncl; i++) {
			m->m_off = 0;
			m->m_next = mclfree;
			mclfree = m;
D 59
			m += CLBYTES / sizeof (*m);
E 59
I 59
			m += MCLBYTES / sizeof (*m);
E 59
D 33
			nmclfree++;
E 33
I 33
			mbstat.m_clfree++;
E 33
		}
		mbstat.m_clusters += ncl;
D 47
		splx(s);
E 47
		break;

	case MPG_MBUFS:
		for (i = ncl * CLBYTES / sizeof (*m); i > 0; i--) {
			m->m_off = 0;
I 23
D 41
			m->m_free = 0;
E 41
I 41
			m->m_type = MT_DATA;
			mbstat.m_mtypes[MT_DATA]++;
E 41
I 33
			mbstat.m_mbufs++;
E 33
E 23
			(void) m_free(m);
			m++;
		}
D 33
		mbstat.m_clusters += ncl;
E 33
I 20
		break;
I 55
D 56

	case MPG_SPACE:
		mbstat.m_space++;
		break;
E 56
E 55
E 20
	}
	return ((caddr_t)m);
}

D 66
m_pgfree(addr, n)
	caddr_t addr;
	int n;
{

D 36
COUNT(M_PGFREE);
E 36
I 31
#ifdef lint
	addr = addr; n = n;
#endif
E 31
D 22
	printf("m_pgfree %x %d\n", addr, n);
E 22
}

E 66
D 47
m_expand()
E 47
I 47
/*
 * Must be called at splimp.
 */
m_expand(canwait)
	int canwait;
E 47
{
I 55
	register struct domain *dp;
	register struct protosw *pr;
	int tries;
E 55

D 36
COUNT(M_EXPAND);
E 36
D 33
	if (mbstat.m_bufs >= mbstat.m_hiwat)
		return (0);
E 33
D 47
	if (m_clalloc(1, MPG_MBUFS) == 0)
E 47
I 47
D 55
	if (m_clalloc(1, MPG_MBUFS, canwait) == 0)
E 47
		goto steal;
	return (1);
steal:
	/* should ask protocols to free code */
	return (0);
E 55
I 55
	for (tries = 0;; ) {
		if (m_clalloc(1, MPG_MBUFS, canwait))
			return (1);
		if (canwait == 0 || tries++)
			return (0);

		/* ask protocols to free space */
		for (dp = domains; dp; dp = dp->dom_next)
			for (pr = dp->dom_protosw; pr < dp->dom_protoswNPROTOSW;
			    pr++)
				if (pr->pr_drain)
					(*pr->pr_drain)();
		mbstat.m_drain++;
	}
E 55
}

/* NEED SOME WAY TO RELEASE SPACE */
D 35

/*
 * Space reservation routines
 */
E 19
I 7
D 14
m_reserve(mbufs)
	int mbufs;
E 14
I 14
D 15
m_reserve(cc)
	int cc;
E 15
I 15
m_reserve(mbufs)
	int mbufs;
E 15
E 14
{
I 14
D 15
	int mbufs = cc / MSIZE;
E 15
E 14

D 8
	if (mbstat.m_lowat + mbufs > NNETPAGES * NMBPG - 32) 
E 8
I 8
D 16
	if (mbstat.m_lowat + mbufs > NMBPAGES * NMBPG - 32) 
E 16
I 16
D 19
/*
	printf("reserve %d\n", mbufs);
*/
E 19
D 17
	if (mbstat.m_lowat + (mbufs>>1) > NMBPAGES * NMBPG - 32) 
E 17
I 17
D 18
	if (mbstat.m_lowat + (mbufs>>1) > (NMBPAGES-32) * CLBYTES) 
E 18
I 18
D 33
	if (mbstat.m_lowat + (mbufs>>1) > (NMBCLUSTERS-32) * CLBYTES) 
E 33
I 33
	if (mbstat.m_mbcommitted + mbufs >
	      (nmbclusters * NMBPCL) * MBUFOVERALLOCFRACTION)
E 33
E 18
E 17
E 16
E 8
		return (0);
D 16
	mbstat.m_lowat += mbufs;
	mbstat.m_hiwat = 2 * mbstat.m_lowat;
E 16
I 16
D 33
	mbstat.m_hiwat += mbufs;
	mbstat.m_lowat = mbstat.m_hiwat >> 1;
E 33
I 33
	mbstat.m_mbcommitted += mbufs;
E 33
E 16
I 10
	return (1);
E 10
}

D 14
m_release(mbufs)
	int mbufs;
E 14
I 14
D 15
m_release(cc)
	int cc;
E 15
I 15
m_release(mbufs)
	int mbufs;
E 15
E 14
{
I 14
D 15
	int mbufs = cc / MSIZE;
E 15
E 14

D 16
	mbstat.m_lowat -= mbufs;
	mbstat.m_hiwat = 2 * mbstat.m_lowat;
E 16
I 16
D 19
/*
	printf("release %d\n", mbufs);
*/
E 19
D 33
	mbstat.m_hiwat -= mbufs;
	mbstat.m_lowat = mbstat.m_hiwat >> 1;
E 33
I 33
	mbstat.m_mbcommitted -= mbufs;
E 33
E 16
}
E 35

I 19
/*
 * Space allocation routines.
 * These are also available as macros
 * for critical paths.
 */
E 19
E 7
struct mbuf *
D 41
m_get(canwait)
	int canwait;
E 41
I 41
m_get(canwait, type)
	int canwait, type;
E 41
{
	register struct mbuf *m;

D 36
COUNT(M_GET);
E 36
D 41
	MGET(m, canwait);
E 41
I 41
	MGET(m, canwait, type);
E 41
	return (m);
}

struct mbuf *
I 9
D 41
m_getclr(canwait)
	int canwait;
E 41
I 41
m_getclr(canwait, type)
	int canwait, type;
E 41
{
	register struct mbuf *m;

D 36
COUNT(M_GETCLR);
E 36
D 10
	m = m_get(m, canwait);
E 10
I 10
D 41
	m = m_get(canwait);
E 41
I 41
D 47
	m = m_get(canwait, type);
E 47
I 47
	MGET(m, canwait, type);
E 47
E 41
E 10
	if (m == 0)
		return (0);
D 37
	m->m_off = MMINOFF;
E 37
	bzero(mtod(m, caddr_t), MLEN);
	return (m);
}

struct mbuf *
E 9
m_free(m)
	struct mbuf *m;
{
	register struct mbuf *n;

D 36
COUNT(M_FREE);
E 36
	MFREE(m, n);
	return (n);
}

I 47
/*
 * Get more mbufs; called from MGET macro if mfree list is empty.
 * Must be called at splimp.
 */
E 47
I 10
/*ARGSUSED*/
E 10
struct mbuf *
D 41
m_more(type)
	int type;
E 41
I 41
m_more(canwait, type)
	int canwait, type;
E 41
{
D 10
	int s;
E 10
	register struct mbuf *m;

D 36
COUNT(M_MORE);
E 36
D 47
	if (!m_expand()) {
D 8
		netstat.m_drops++;
E 8
I 8
		mbstat.m_drops++;
E 8
		return (NULL);
E 47
I 47
	while (m_expand(canwait) == 0) {
		if (canwait == M_WAIT) {
I 55
			mbstat.m_wait++;
E 55
			m_want++;
D 50
			sleep((caddr_t)mfree, PZERO - 1);
E 50
I 50
			sleep((caddr_t)&mfree, PZERO - 1);
I 65
			if (mfree)
				break;
E 65
E 50
		} else {
			mbstat.m_drops++;
			return (NULL);
		}
E 47
	}
D 10
#define m_more(x) ((struct mbuf *)panic("m_more"))
	MGET(m, 0);
E 10
I 10
D 41
#define m_more(x) (panic("m_more"), (struct mbuf *)0)
	MGET(m, type);
E 41
I 41
#define m_more(x,y) (panic("m_more"), (struct mbuf *)0)
	MGET(m, canwait, type);
E 41
I 24
#undef m_more
E 24
E 10
	return (m);
}

D 6
m_freem(m)                      /* free mbuf chain headed by m */
E 6
I 6
m_freem(m)
E 6
	register struct mbuf *m;
{
	register struct mbuf *n;
D 10
	register int s, cnt;
E 10
I 10
D 11
	register int s, i;
E 11
I 11
	register int s;
E 11
E 10

D 36
COUNT(M_FREEM);
E 36
	if (m == NULL)
D 10
		return (0);
	cnt = 0;
E 10
I 10
		return;
D 11
	i = 0;
E 11
E 10
D 5
	s = spl_imp();
E 5
I 5
	s = splimp();
E 5
	do {
D 6
		MFREE(m, n);
E 6
I 6
D 11
		if (m->m_off > MMAXOFF)
D 10
			cnt += NMBPG;
E 6
		cnt++;
E 10
I 10
			i += NMBPG;
		i++;
E 11
E 10
I 6
		MFREE(m, n);
E 6
	} while (m = n);
	splx(s);
D 10
	return (cnt);
E 10
I 10
D 11
	return;
E 11
I 11
}

I 12
D 19
/*ARGSUSED*/
E 12
m_pullup(m, len)
	struct mbuf *m;
	int len;
{

	return (0);
}

E 19
I 19
/*
 * Mbuffer utility routines.
 */
I 47

/*
I 64
/*
E 64
 * Make a copy of an mbuf chain starting "off" bytes from the beginning,
 * continuing for "len" bytes.  If len is M_COPYALL, copy to end of mbuf.
 * Should get M_WAIT/M_DONTWAIT from caller.
 */
E 47
E 19
struct mbuf *
m_copy(m, off, len)
	register struct mbuf *m;
	int off;
	register int len;
{
	register struct mbuf *n, **np;
	struct mbuf *top, *p;
I 41
D 45
	int type;
E 45
E 41
D 36
COUNT(M_COPY);
E 36

	if (len == 0)
		return (0);
	if (off < 0 || len < 0)
		panic("m_copy");
I 41
D 45
	type = m->m_type;
E 45
E 41
	while (off > 0) {
		if (m == 0)
			panic("m_copy");
		if (off < m->m_len)
			break;
		off -= m->m_len;
		m = m->m_next;
	}
	np = &top;
	top = 0;
	while (len > 0) {
I 27
		if (m == 0) {
			if (len != M_COPYALL)
				panic("m_copy");
			break;
		}
E 27
D 41
		MGET(n, 1);
E 41
I 41
D 45
		MGET(n, M_WAIT, type);
E 45
I 45
D 47
		MGET(n, M_WAIT, m->m_type);
E 47
I 47
		MGET(n, M_DONTWAIT, m->m_type);
E 47
E 45
E 41
		*np = n;
		if (n == 0)
			goto nospace;
D 27
		if (m == 0)
			panic("m_copy");
E 27
		n->m_len = MIN(len, m->m_len - off);
		if (m->m_off > MMAXOFF) {
			p = mtod(m, struct mbuf *);
			n->m_off = ((int)p - (int)n) + off;
D 17
			mprefcnt[mtopf(p)]++;
E 17
I 17
			mclrefcnt[mtocl(p)]++;
E 17
D 37
		} else {
			n->m_off = MMINOFF;
E 37
I 37
		} else
E 37
			bcopy(mtod(m, caddr_t)+off, mtod(n, caddr_t),
			    (unsigned)n->m_len);
D 37
		}
E 37
D 27
		len -= n->m_len;
E 27
I 27
		if (len != M_COPYALL)
			len -= n->m_len;
E 27
		off = 0;
		m = m->m_next;
		np = &n->m_next;
	}
	return (top);
nospace:
D 22
	printf("m_copy: no space\n");
E 22
	m_freem(top);
	return (0);
I 64
}

/*
 * Copy data from an mbuf chain starting "off" bytes from the beginning,
 * continuing for "len" bytes, into the indicated buffer.
 */
D 65
struct mbuf *
E 65
m_copydata(m, off, len, cp)
	register struct mbuf *m;
D 65
	int off;
E 65
I 65
	register int off;
E 65
	register int len;
D 65
	caddr_t *cp;
E 65
I 65
	caddr_t cp;
E 65
{
	register unsigned count;

	if (off < 0 || len < 0)
		panic("m_copydata");
	while (off > 0) {
		if (m == 0)
			panic("m_copydata");
		if (off < m->m_len)
			break;
		off -= m->m_len;
		m = m->m_next;
	}
	while (len > 0) {
		if (m == 0)
			panic("m_copydata");
D 65
		count = MIN(m->m_len, len);
E 65
I 65
		count = MIN(m->m_len - off, len);
E 65
		bcopy(mtod(m, caddr_t) + off, cp, count);
		len -= count;
I 65
		cp += count;
E 65
		off = 0;
		m = m->m_next;
	}
E 64
E 11
E 10
}

D 6

mbufinit()                      /* init network buffer mgmt system */
E 6
I 6
D 8
mbufinit()
E 8
I 8
D 19
mbinit()
E 8
E 6
{
	register struct mbuf *m;
	register i;

COUNT(MBUFINIT);
D 8
	m = (struct mbuf *)&netutl[0];  /* ->start of buffer virt mem */
	vmemall(&Netmap[0], 2, proc, CSYS);
	vmaccess(&Netmap[0], m, 2);
E 8
I 8
	m = (struct mbuf *)&mbutl[0];  /* ->start of buffer virt mem */
D 10
	vmemall(&Mbmap[0], 2, proc, CSYS);
	vmaccess(&Mbmap[0], m, 2);
E 10
I 10
	(void) vmemall(&Mbmap[0], 2, proc, CSYS);
	vmaccess(&Mbmap[0], (caddr_t)m, 2);
E 10
E 8
D 17
	for (i=0; i < NMBPG; i++) {
E 17
I 17
	for (i=0; i < CLBYTES / sizeof (struct mbuf); i++) {
E 17
I 2
		m->m_off = 0;
E 2
D 13
		m_free(m);
E 13
I 13
		(void) m_free(m);
E 13
		m++;
	}
D 10
	pg_alloc(3);
E 10
I 10
D 17
	(void) pg_alloc(3);
E 17
I 17
	(void) m_pgalloc(3);
E 17
E 10
D 5
	netcb.n_pages = 4;
	netcb.n_bufs = 32;
	netcb.n_lowat = 16;
	netcb.n_hiwat = 32;
E 5
I 5
	mbstat.m_pages = 4;
	mbstat.m_bufs = 32;
	mbstat.m_lowat = 16;
	mbstat.m_hiwat = 32;
I 6
D 10
	{ int i,j,k,n;
E 10
I 10
	{ int j,k,n;
E 10
	n = 32;
	k = n << 1;
D 8
	if ((i = rmalloc(netmap, n)) == 0)
E 8
I 8
	if ((i = rmalloc(mbmap, n)) == 0)
E 8
D 10
		return (0);
E 10
I 10
		panic("mbinit");
E 10
	j = i<<1;
D 17
	m = pftom(i);
E 17
I 17
	m = cltom(i);
E 17
	/* should use vmemall sometimes */
D 8
	if (memall(&Netmap[j], k, proc, CSYS) == 0) {
E 8
I 8
	if (memall(&Mbmap[j], k, proc, CSYS) == 0) {
E 8
		printf("botch\n");
		return;
	}
D 8
	vmaccess(&Netmap[j], (caddr_t)m, k);
E 8
I 8
	vmaccess(&Mbmap[j], (caddr_t)m, k);
E 8
	for (j=0; j < n; j++) {
		m->m_off = 0;
D 17
		m->m_next = mpfree;
		mpfree = m;
		m += NMBPG;
		nmpfree++;
E 17
I 17
		m->m_next = mclfree;
		mclfree = m;
		m += CLBYTES / sizeof (*m);
		nmclfree++;
E 17
	}
	}
E 6
E 5
}

D 17
pg_alloc(n)
E 17
I 17
m_pgalloc(n)
E 17
	register int n;
{
	register i, j, k;
	register struct mbuf *m;
	int bufs, s;

D 17
COUNT(PG_ALLOC);
E 17
I 17
COUNT(M_PGALLOC);
E 17
	k = n << 1;
D 8
	if ((i = rmalloc(netmap, n)) == 0)
E 8
I 8
	if ((i = rmalloc(mbmap, n)) == 0)
E 8
		return (0);
	j = i<<1;
D 17
	m = pftom(i);
E 17
I 17
	m = cltom(i);
E 17
	/* should use vmemall sometimes */
D 8
	if (memall(&Netmap[j], k, proc, CSYS) == 0)
E 8
I 8
	if (memall(&Mbmap[j], k, proc, CSYS) == 0)
E 8
		return (0);
D 8
	vmaccess(&Netmap[j], (caddr_t)m, k);
E 8
I 8
	vmaccess(&Mbmap[j], (caddr_t)m, k);
E 8
	bufs = n << 3;
D 5
	s = spl_imp();
E 5
I 5
	s = splimp();
E 5
	for (j=0; j < bufs; j++) {
I 2
		m->m_off = 0;
E 2
D 13
		m_free(m);
E 13
I 13
		(void) m_free(m);
E 13
		m++;
	}
	splx(s);
D 5
	netcb.n_pages += n;
E 5
I 5
	mbstat.m_pages += n;
E 5
	return (1);
}

I 17
/*ARGSUSED*/
m_pgfree(addr, n)
	caddr_t addr;
	int n;
{

COUNT(M_PGFREE);
	printf("m_pgfree %x %d\n", addr, n);
}

E 17
m_expand()
{
	register i;
D 6
	register struct ipq *fp;
	register struct ip *q;
	register struct tcb *tp;
E 6
D 10
	register struct mbuf *m, *n;
E 10
	int need, needp, needs;

COUNT(M_EXPAND);
D 5
	needs = need = netcb.n_hiwat - netcb.n_bufs;    /* #bufs to add */
	needp = need >> 3;                              /* #pages to add */
E 5
I 5
	needs = need = mbstat.m_hiwat - mbstat.m_bufs;
	needp = need >> 3;
E 5
D 17
	if (pg_alloc(needp))
E 17
I 17
	if (m_pgalloc(needp))
E 17
		return (1);
D 6
	for (i=0; i < needp; i++, need-=NMBPG)
		if (needp == 1 || pg_alloc(1) == 0)		/* ??? */
E 6
I 6
D 17
	for (i=0; i < needp; i++, need -= NMBPG)
		if (pg_alloc(1) == 0)
E 17
I 17
	for (i=0; i < needp; i++, need -= CLBYTES / sizeof (struct mbuf))
		if (m_pgalloc(1) == 0)
E 17
E 6
			goto steal;
	return (need < needs);
steal:
D 5
	fp = netcb.n_ip_tail;           /* ip reass.q */
	while (need > 0 && fp) {
		q = fp->iqx.ip_next;    /* free mbufs assoc. w/chain */
		while (q != (struct ip *)fp) {
			need -= m_freem(dtom(q));
			q = q->ip_next;
		}
		ip_freef(fp);           /* free header */
		fp = netcb.n_ip_tail;
	}
	tp = netcb.n_tcb_tail;          /* ->tcbs */
	while (need > 0 && tp != NULL) {
		m = tp->t_rcv_unack;
		while (m != NULL) {
			n = m->m_act;
			need -= m_freem(m);
			m = n;
		}
		tp->t_rcv_unack = NULL;
		tp = tp->t_tcb_prev;
	}
E 5
I 5
D 6
#ifdef notdef
	/* free fragments */
	/* free unacks */
#endif
E 5
	return (need < needs);
E 6
I 6
	/* while (not enough) ask protocols to free code */
	;
I 10
	return (0);
E 10
E 6
}

#ifdef notdef
m_relse()
{
D 5
	int free;

E 5
D 6
COUNT(M_RELSE);
E 6
D 5
	free = (netcb.n_bufs - netcb.n_hiwat) >> 3;    /* # excess free pages */
	return;
E 5
I 5

I 6
COUNT(M_RELSE);
E 6
E 5
}
#endif

E 19
D 6
struct mbuf *
E 6
I 6
m_cat(m, n)
	register struct mbuf *m, *n;
{
D 30

E 30
	while (m->m_next)
		m = m->m_next;
D 30
	while (n)
D 28
		if (m->m_off + m->m_len + n->m_len <= MMAXOFF) {
E 28
I 28
		if (m->m_off < MMAXOFF &&
		    m->m_off + m->m_len + n->m_len <= MMAXOFF) {
E 28
D 10
			bcopy(mtod(n, caddr_t), mtod(m, caddr_t) + m->m_len, n->m_len);
E 10
I 10
			bcopy(mtod(n, caddr_t), mtod(m, caddr_t) + m->m_len,
			    (u_int)n->m_len);
E 10
			m->m_len += n->m_len;
			n = m_free(n);
		} else {
E 30
I 30
	while (n) {
		if (m->m_off >= MMAXOFF ||
		    m->m_off + m->m_len + n->m_len > MMAXOFF) {
			/* just join the two chains */
E 30
			m->m_next = n;
D 30
			m = n;
			n = m->m_next;
E 30
I 30
			return;
E 30
		}
I 30
		/* splat the data from one into the other */
		bcopy(mtod(n, caddr_t), mtod(m, caddr_t) + m->m_len,
		    (u_int)n->m_len);
		m->m_len += n->m_len;
		n = m_free(n);
	}
E 30
}

E 6
m_adj(mp, len)
	struct mbuf *mp;
D 10
	register len;
E 10
I 10
	register int len;
E 10
{
D 51
	register struct mbuf *m, *n;
E 51
I 51
	register struct mbuf *m;
	register count;
E 51

I 6
D 8
/*
	for (m = mp; m; m = m->m_next) {
		printf("a %x %d\n", m, m->m_len);
	}
*/
E 8
E 6
D 36
COUNT(M_ADJ);
E 36
	if ((m = mp) == NULL)
		return;
D 8
	if (len >= 0) {                 /* adjust from top of msg chain */
E 8
I 8
	if (len >= 0) {
E 8
		while (m != NULL && len > 0) {
D 8
			if (m->m_len <= len) {          /* free this mbuf */
E 8
I 8
			if (m->m_len <= len) {
E 8
				len -= m->m_len;
				m->m_len = 0;
				m = m->m_next;
D 8
			} else {                        /* adjust mbuf */
E 8
I 8
			} else {
E 8
				m->m_len -= len;
				m->m_off += len;
				break;
			}
		}
D 8

	} else {                        /* adjust from bottom of msg chain */
E 8
I 8
	} else {
D 51
		/* a 2 pass algorithm might be better */
E 51
I 51
		/*
		 * Trim from tail.  Scan the mbuf chain,
		 * calculating its length and finding the last mbuf.
		 * If the adjustment only affects this mbuf, then just
		 * adjust and return.  Otherwise, rescan and truncate
		 * after the remaining size.
		 */
E 51
E 8
		len = -len;
D 51
		while (len > 0 && m->m_len != 0) {
D 8
			/* find end of chain */
E 8
			while (m != NULL && m->m_len != 0) {
				n = m;
				m = m->m_next;
			}
D 8
			if (n->m_len <= len) {          /* last mbuf */
E 8
I 8
			if (n->m_len <= len) {
E 8
				len -= n->m_len;
				n->m_len = 0;
				m = mp;
D 8
			} else {                        /* adjust length */
E 8
I 8
			} else {
E 8
				n->m_len -= len;
E 51
I 51
		count = 0;
		for (;;) {
			count += m->m_len;
			if (m->m_next == (struct mbuf *)0)
E 51
				break;
I 51
			m = m->m_next;
		}
		if (m->m_len >= len) {
			m->m_len -= len;
			return;
		}
		count -= len;
		/*
		 * Correct length for chain is "count".
		 * Find the mbuf with last data, adjust its length,
		 * and toss data from remaining mbufs on chain.
		 */
		for (m = mp; m; m = m->m_next) {
			if (m->m_len >= count) {
				m->m_len = count;
				break;
E 51
			}
I 51
			count -= m->m_len;
E 51
		}
I 51
		while (m = m->m_next)
			m->m_len = 0;
E 51
	}
I 19
}

I 49
/*
 * Rearange an mbuf chain so that len bytes are contiguous
 * and in the data area of an mbuf (so that mtod and dtom
D 51
 * will work for a structure of size len).
 * Returns the resulting mbuf chain on success,
 * frees it and returns null on failure.
E 51
I 51
 * will work for a structure of size len).  Returns the resulting
 * mbuf chain on success, frees it and returns null on failure.
 * If there is room, it will add up to MPULL_EXTRA bytes to the
 * contiguous region in an attempt to avoid being called next time.
E 51
 */
E 49
D 25
/*ARGSUSED*/
m_pullup(m, len)
	struct mbuf *m;
E 25
I 25
struct mbuf *
D 51
m_pullup(m0, len)
	struct mbuf *m0;
E 51
I 51
m_pullup(n, len)
	register struct mbuf *n;
E 51
E 25
	int len;
{
I 25
D 51
	register struct mbuf *m, *n;
D 32
	int cnt;
E 32
I 32
	int count;
E 51
I 51
	register struct mbuf *m;
	register int count;
	int space;
E 51
E 32
E 25

I 29
D 51
	n = m0;
E 29
I 25
	if (len > MLEN)
		goto bad;
D 37
	MGET(m, 0);
E 37
I 37
D 41
	MGET(m, M_DONTWAIT);
E 41
I 41
	MGET(m, M_DONTWAIT, n->m_type);
E 41
E 37
	if (m == 0)
		goto bad;
D 37
	m->m_off = MMINOFF;
E 37
	m->m_len = 0;
E 51
I 51
	if (n->m_off + len <= MMAXOFF && n->m_next) {
		m = n;
		n = n->m_next;
		len -= m->m_len;
	} else {
		if (len > MLEN)
			goto bad;
		MGET(m, M_DONTWAIT, n->m_type);
		if (m == 0)
			goto bad;
		m->m_len = 0;
	}
	space = MMAXOFF - m->m_off;
E 51
D 29
	n = m0;
E 29
	do {
D 32
		cnt = MIN(MLEN - m->m_len, len);
		if (cnt > n->m_len)
			cnt = n->m_len;
		bcopy(mtod(n, caddr_t), mtod(m, caddr_t)+m->m_len, cnt);
		len -= cnt;
		m->m_len += cnt;
		n->m_off += cnt;
		n->m_len -= cnt;
E 32
I 32
D 49
		count = MIN(MLEN - m->m_len, len);
		if (count > n->m_len)
			count = n->m_len;
E 49
I 49
D 51
		count = MIN(n->m_len, len);
E 51
I 51
		count = MIN(MIN(space - m->m_len, len + MPULL_EXTRA), n->m_len);
E 51
E 49
		bcopy(mtod(n, caddr_t), mtod(m, caddr_t)+m->m_len,
		  (unsigned)count);
		len -= count;
		m->m_len += count;
D 49
		n->m_off += count;
E 49
		n->m_len -= count;
E 32
		if (n->m_len)
D 49
			break;
		n = m_free(n);
	} while (n);
E 49
I 49
			n->m_off += count;
		else
			n = m_free(n);
D 51
	} while (len && n);
E 49
	if (len) {
E 51
I 51
	} while (len > 0 && n);
	if (len > 0) {
E 51
		(void) m_free(m);
		goto bad;
	}
	m->m_next = n;
	return (m);
bad:
D 29
	m_freem(m0);
E 29
I 29
	m_freem(n);
E 29
E 25
	return (0);
E 19
D 8
}

/*
 * convert mbuf virtual to physical addr for uballoc
 */
mtophys(m)
	register struct mbuf *m;
{
	register i;
	register unsigned long addr;
	register struct pte *pte;

COUNT(MTOPHYS);
	i = (((int)m & ~PGOFSET) - (int)netutl) >> PGSHIFT;
	pte = &Netmap[i];
	addr = (pte->pg_pfnum << PGSHIFT) | ((int)m & PGOFSET);
	return (addr);
E 8
I 3
D 6
}

m_cat(m, n)
	register struct mbuf *m, *n;
{

	while (m->m_next)
		m = m->m_next;
	while (n)
		if (m->m_off + m->m_len + n->m_len <= MMAXOFF) {
D 4
			bcopy(mtod(n), mtod(m) + m->m_len, n->m_len);
E 4
I 4
			bcopy(mtod(n, caddr_t), mtod(m, caddr_t) + m->m_len, n->m_len);
E 4
			m->m_len += n->m_len;
			n = m_free(n);
		} else {
			m->m_next = n;
			m = n;
			n = m->m_next;
		}
E 6
E 3
}
E 1
