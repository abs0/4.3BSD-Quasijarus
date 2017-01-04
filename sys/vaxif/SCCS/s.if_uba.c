h31982
s 00013/00002/00375
d D 7.10 88/08/04 15:30:29 bostic 45 44
c add Berkeley specific copyright
e
s 00002/00001/00375
d D 7.9 88/05/24 18:52:01 mckusick 44 43
c lint
e
s 00009/00010/00367
d D 7.8 88/05/14 11:11:25 karels 43 42
c clean up pte computations (not all pte's are in Mbmap now)
e
s 00001/00000/00376
d D 7.7 87/10/22 15:59:51 bostic 42 41
c include malloc.h
e
s 00007/00007/00369
d D 7.6 87/06/21 17:21:57 mckusick 41 35
c m_clalloc(..., MPG_SPACE, ...) => malloc
e
s 00002/00002/00374
d D 7.5.1.1 87/06/04 13:51:48 bostic 40 35
c DEUNA fix, rcv_xmtbuf panic, diff with V7.1
e
s 00001/00001/00375
d R 7.5.1.1 87/06/04 13:50:21 bostic 39 35
c DEUNA fix, diff to V7.1
e
s 00001/00001/00375
d R 7.5.1.1 87/06/04 13:47:33 bostic 38 35
c DEUNA fixes, rcv_xmtbuf panic
e
s 00000/00000/00376
d R 7.5.1.1 87/06/04 13:35:22 bostic 37 35
c DEUNA problems; rcv_xmtbuf, fixes for V7.1
e
s 00002/00002/00374
d R 7.6 87/06/04 12:26:32 bostic 36 35
c DEUNA fix
e
s 00002/00002/00374
d D 7.5 87/05/04 10:03:19 karels 35 33
c keep r and w straight
e
s 00002/00002/00374
d R 7.5 87/03/31 19:39:48 karels 34 33
c keep r and w straight
e
s 00004/00007/00372
d D 7.4 87/03/10 19:46:40 karels 33 31
c maybe this time! fix rcv_xmtbuf/restor_xmtbuf bug that screws buffers
c if old sends mapped out more pages than the current one
e
s 00003/00007/00372
d R 7.4 87/03/10 17:46:05 karels 32 31
c maybe this time! fix rcv_xmtbuf/restor_xmtbuf bug that screws buffers
c if old sends mapped out more pages than the current one
e
s 00002/00002/00377
d D 7.3 86/08/09 15:16:51 karels 31 30
c generalize uba code to handle Q bus more gracefully
e
s 00001/00001/00378
d D 7.2 86/08/07 10:52:28 karels 30 29
c rm bogus rcv_xmit panic
e
s 00001/00001/00378
d D 7.1 86/06/05 17:11:21 mckusick 29 28
c 4.3BSD release version
e
s 00001/00001/00378
d D 6.12 86/04/01 11:20:15 karels 28 27
c NBPG => CLBYTES/2
e
s 00004/00004/00375
d D 6.11 86/02/23 23:29:49 karels 27 26
c lint
e
s 00006/00006/00373
d D 6.10 86/02/20 17:17:35 karels 26 25
c lint
e
s 00005/00006/00374
d D 6.9 86/02/18 16:27:41 karels 25 24
c clean up cluster allocation
e
s 00002/00001/00378
d D 6.8 85/12/18 19:54:49 karels 24 23
c record and use number of map registers actually use in ifw_nmr
e
s 00068/00005/00311
d D 6.7 85/11/07 10:57:04 karels 23 22
c allow receive from transmit buffer (for deuna)
e
s 00080/00057/00236
d D 6.6 85/09/16 22:24:23 karels 22 21
c generalized if_uba support for multiple rcv/xmt buffers per device
e
s 00034/00005/00259
d D 6.5 85/09/03 11:51:38 karels 21 20
c prepend interface pointer to packet in if_rubaget, for receiving protocol
e
s 00007/00001/00257
d D 6.4 85/06/08 13:59:54 mckusick 20 19
c Add copyright
e
s 00014/00007/00244
d D 6.3 85/06/03 08:45:01 karels 19 18
c allow for zero-length headers, don't reuse x in if_wubaput
e
s 00009/00009/00242
d D 6.2 84/08/29 20:44:34 bloom 18 17
c change ot includes.  no more ../h
e
s 00000/00000/00251
d D 6.1 83/07/29 07:38:31 sam 17 16
c 4.2 distribution
e
s 00002/00001/00249
d D 4.16 82/12/17 12:14:17 sam 16 15
c sun merge
e
s 00001/00001/00249
d D 4.15 82/12/14 17:21:58 sam 15 14
c typed mbufs
e
s 00005/00003/00245
d D 4.14 82/10/10 17:02:53 root 14 13
c put vax headers in their place
e
s 00001/00003/00247
d D 4.13 82/10/09 06:11:18 wnj 13 12
c fix includes
e
s 00000/00004/00250
d D 4.12 82/06/20 00:53:14 sam 12 11
c purge COUNT stuff now that we can use gprof
e
s 00013/00008/00241
d D 4.11 82/05/19 15:57:10 wnj 11 10
c on uba reset remap already allocated pages
e
s 00001/00000/00248
d D 4.10 82/03/28 14:22:04 sam 10 9
c convert interfaces to sockaddr's and add hooks for routing
e
s 00003/00003/00245
d D 4.9 82/02/03 11:22:59 sam 9 8
c add flags for uballoc to simplify direct data path interfaces
e
s 00001/00001/00247
d D 4.8 81/12/23 14:01:25 root 8 7
c typo in if_uba.c
e
s 00000/00001/00248
d D 4.7 81/12/21 11:56:21 root 7 6
c spurious ifu->ifu_xswapd = 0
e
s 00000/00004/00249
d D 4.6 81/12/09 20:40:30 wnj 6 5
c remove crud
e
s 00034/00027/00219
d D 4.5 81/12/09 20:39:14 wnj 5 4
c with debugging crud
e
s 00045/00041/00201
d D 4.4 81/12/03 17:29:21 wnj 4 3
c cleanup
e
s 00031/00031/00211
d D 4.3 81/11/29 21:59:06 wnj 3 2
c lint and interface cleanups
e
s 00036/00025/00206
d D 4.2 81/11/26 11:56:03 wnj 2 1
c before carry to ARPAVAX
e
s 00231/00000/00000
d D 4.1 81/11/25 18:13:50 wnj 1 0
c date and time created 81/11/25 18:13:50 by wnj
e
u
U
f b 
t
T
I 1
D 20
/*	%M%	%I%	%E%	*/
E 20
I 20
/*
D 29
 * Copyright (c) 1982 Regents of the University of California.
E 29
I 29
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 29
D 45
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 45
I 45
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
E 45
 *
 *	%W% (Berkeley) %G%
 */
E 20

I 16
D 43
#include "../machine/pte.h"

E 43
E 16
D 18
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/map.h"
D 16
#include "../h/pte.h"
E 16
I 2
#include "../h/buf.h"
E 2
D 14
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 14
#include "../h/cmap.h"
D 14
#include "../h/mtpr.h"
E 14
I 2
#include "../h/vmmac.h"
I 10
#include "../h/socket.h"
E 18
I 18
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "map.h"
#include "buf.h"
#include "cmap.h"
#include "vmmac.h"
#include "socket.h"
I 23
#include "syslog.h"
I 42
#include "malloc.h"
E 42
E 23
E 18
I 14

E 14
E 10
D 13
#include "../net/in.h"
#include "../net/in_systm.h"
E 13
#include "../net/if.h"
I 14

I 43
#include "../vax/pte.h"
E 43
#include "../vax/mtpr.h"
E 14
E 2
D 13
#include "../net/if_uba.h"
E 13
I 13
D 18
#include "../vaxif/if_uba.h"
E 18
I 18
#include "if_uba.h"
E 18
I 14
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 14
E 13

/*
 * Routines supporting UNIBUS network interfaces.
 *
 * TODO:
 *	Support interfaces using only one BDP statically.
 */

/*
 * Init UNIBUS for interface on uban whose headers of size hlen are to
 * end on a page boundary.  We allocate a UNIBUS map register for the page
 * with the header, and nmr more UNIBUS map registers for i/o on the adapter,
D 22
 * doing this twice: once for reading and once for writing.  We also
E 22
I 22
 * doing this once for each read and once for each write buffer.  We also
E 22
 * allocate page frames in the mbuffer pool for these pages.
 */
D 22
if_ubainit(ifu, uban, hlen, nmr)
	register struct ifuba *ifu;
	int uban, hlen, nmr;
E 22
I 22
if_ubaminit(ifu, uban, hlen, nmr, ifr, nr, ifw, nw)
	register struct ifubinfo *ifu;
	int uban, hlen, nmr, nr, nw;
	register struct ifrw *ifr;
	register struct ifxmt *ifw;
E 22
{
D 2
	register caddr_t cp = m_pgalloc(2 * (nmr + 1));
E 2
I 2
D 5
	register caddr_t cp = (caddr_t)m_pgalloc(2 * (nmr + 1));
	int i;
E 5
I 5
D 22
	register caddr_t cp;
E 22
I 22
	register caddr_t p;
	caddr_t cp;
E 22
D 19
	int i, ncl;
E 19
I 19
D 41
	int i, ncl, off;
E 41
I 41
	int i, nclbytes, off;
E 41
E 19
E 5
E 2

I 2
D 12
COUNT(IF_UBAINIT);
E 12
I 5
D 19
	ncl = clrnd(nmr + CLSIZE) / CLSIZE;
E 19
I 19
	if (hlen)
		off = CLBYTES - hlen;
	else
		off = 0;
D 41
	ncl = clrnd(nmr) / CLSIZE;
E 41
I 41
	nclbytes = CLBYTES * (clrnd(nmr) / CLSIZE);
E 41
	if (hlen)
D 41
		ncl++;
E 41
I 41
		nclbytes += CLBYTES;
E 41
E 19
D 11
	cp = m_clalloc(2 * ncl, MPG_SPACE);
E 5
E 2
	if (cp == 0)
		return (0);
I 4
	ifu->ifu_hlen = hlen;
E 4
D 2
	ifu->if_uban = uban;
	ifu->if_uba = &uba_hd[uban]->uh_uba;
	ifu->if_r.if_addr = cp + NMBPG - hlen;
	ifu->if_w.if_addr = ifu->if_r.if_addr + (nmr + 1) * NMBPG;
	if (if_ubaalloc(ifu, &ifu->if_r) == 0)
E 2
I 2
	ifu->ifu_uban = uban;
	ifu->ifu_uba = uba_hd[uban].uh_uba;
D 5
	ifu->ifu_r.ifrw_addr = cp + NBPG - hlen;
	ifu->ifu_w.ifrw_addr = ifu->ifu_r.ifrw_addr + (nmr + 1) * NBPG;
E 5
I 5
	ifu->ifu_r.ifrw_addr = cp + CLBYTES - hlen;
	ifu->ifu_w.ifrw_addr = ifu->ifu_r.ifrw_addr + ncl * CLBYTES;
E 11
I 11
D 22
	if (ifu->ifu_r.ifrw_addr)
D 19
		cp = ifu->ifu_r.ifrw_addr - (CLBYTES - hlen);
E 19
I 19
		cp = ifu->ifu_r.ifrw_addr - off;
E 22
I 22
	if (ifr[0].ifrw_addr)
		cp = ifr[0].ifrw_addr - off;
E 22
E 19
	else {
D 22
		cp = m_clalloc(2 * ncl, MPG_SPACE);
E 22
I 22
D 27
		cp = m_clalloc((nr + nw) * ncl, MPG_SPACE);
E 27
I 27
D 41
		cp = m_clalloc((nr + nw) * ncl, MPG_SPACE, M_DONTWAIT);
E 41
I 41
D 44
		cp = (caddr_t)malloc((nr + nw) * nclbytes, M_DEVBUF, M_NOWAIT);
E 44
I 44
		cp = (caddr_t)malloc((u_long)((nr + nw) * nclbytes), M_DEVBUF,
		    M_NOWAIT);
E 44
E 41
E 27
E 22
		if (cp == 0)
			return (0);
D 19
		ifu->ifu_r.ifrw_addr = cp + CLBYTES - hlen;
E 19
I 19
D 22
		ifu->ifu_r.ifrw_addr = cp + off;
E 19
		ifu->ifu_w.ifrw_addr = ifu->ifu_r.ifrw_addr + ncl * CLBYTES;
		ifu->ifu_hlen = hlen;
		ifu->ifu_uban = uban;
		ifu->ifu_uba = uba_hd[uban].uh_uba;
E 22
I 22
		p = cp;
		for (i = 0; i < nr; i++) {
			ifr[i].ifrw_addr = p + off;
D 41
			p += ncl * CLBYTES;
E 41
I 41
			p += nclbytes;
E 41
		}
		for (i = 0; i < nw; i++) {
			ifw[i].ifw_base = p;
			ifw[i].ifw_addr = p + off;
D 41
			p += ncl * CLBYTES;
E 41
I 41
			p += nclbytes;
E 41
		}
		ifu->iff_hlen = hlen;
		ifu->iff_uban = uban;
		ifu->iff_uba = uba_hd[uban].uh_uba;
I 31
D 40
		ifu->iff_ubamr = uba_hd[uban].uh_mr;
E 40
E 31
E 22
	}
E 11
E 5
D 4
	if (if_ubaalloc(ifu, &ifu->ifu_r) == 0)
E 4
I 4
D 22
	if (if_ubaalloc(ifu, &ifu->ifu_r, nmr) == 0)
E 4
E 2
		goto bad;
D 2
	if (if_ubaalloc(ifu, &ifu->if_w) == 0)
E 2
I 2
D 4
	if (if_ubaalloc(ifu, &ifu->ifu_w) == 0)
E 4
I 4
	if (if_ubaalloc(ifu, &ifu->ifu_w, nmr) == 0)
E 4
E 2
		goto bad2;
D 4
	for (i = 0; i < IF_NUBAMR; i++)
E 4
I 4
	for (i = 0; i < nmr; i++)
E 4
D 2
		ifu->if_xmap[i] = ifu->if_w.if_map[i+1];
	ifu->if_xswapd = 0;
E 2
I 2
D 5
		ifu->ifu_wmap[i] = ifu->ifu_w.ifrw_mr[i+1];
E 5
I 5
		ifu->ifu_wmap[i] = ifu->ifu_w.ifrw_mr[i];
E 5
	ifu->ifu_xswapd = 0;
E 22
I 22
	for (i = 0; i < nr; i++)
		if (if_ubaalloc(ifu, &ifr[i], nmr) == 0) {
			nr = i;
			nw = 0;
			goto bad;
		}
	for (i = 0; i < nw; i++)
		if (if_ubaalloc(ifu, &ifw[i].ifrw, nmr) == 0) {
			nw = i;
			goto bad;
		}
	while (--nw >= 0) {
		for (i = 0; i < nmr; i++)
			ifw[nw].ifw_wmap[i] = ifw[nw].ifw_mr[i];
		ifw[nw].ifw_xswapd = 0;
I 23
		ifw[nw].ifw_flags = IFRW_W;
I 24
		ifw[nw].ifw_nmr = nmr;
E 24
E 23
	}
E 22
E 2
	return (1);
D 22
bad2:
D 2
	ubafree(ifu->ifu_uban, ifu->if_r.ifrw_info);
E 2
I 2
	ubarelse(ifu->ifu_uban, &ifu->ifu_r.ifrw_info);
E 22
E 2
bad:
D 5
	m_pgfree(cp, 2 * (nmr + 1));
E 5
I 5
D 22
	m_pgfree(cp, 2 * ncl);
I 11
	ifu->ifu_r.ifrw_addr = 0;
E 22
I 22
	while (--nw >= 0)
D 35
		ubarelse(ifu->iff_uban, &ifr[nw].ifrw_info);
E 35
I 35
		ubarelse(ifu->iff_uban, &ifw[nw].ifw_info);
E 35
	while (--nr >= 0)
D 35
		ubarelse(ifu->iff_uban, &ifw[nr].ifw_info);
E 35
I 35
		ubarelse(ifu->iff_uban, &ifr[nr].ifrw_info);
E 35
D 41
	m_pgfree(cp, (nr + nw) * ncl);
E 41
I 41
	free(cp, M_DEVBUF);
E 41
	ifr[0].ifrw_addr = 0;
E 22
E 11
E 5
	return (0);
}

/*
D 22
 * Setup either a ifrw structure by allocating UNIBUS map registers,
E 22
I 22
 * Setup an ifrw structure by allocating UNIBUS map registers,
E 22
D 9
 * a buffered data path, and initializing the fields of the ifrw structure
 * to minimize run-time overhead.
E 9
I 9
 * possibly a buffered data path, and initializing the fields of
 * the ifrw structure to minimize run-time overhead.
E 9
 */
static
D 4
if_ubaalloc(ifu, ifrw)
E 4
I 4
if_ubaalloc(ifu, ifrw, nmr)
E 4
D 22
	struct ifuba *ifu;
E 22
I 22
	struct ifubinfo *ifu;
E 22
	register struct ifrw *ifrw;
I 4
	int nmr;
E 4
{
	register int info;

I 2
D 12
COUNT(IF_UBAALLOC);
E 12
E 2
	info =
D 2
	    uballoc(ifu->ifu_uban, ifrw->ifrw_addr, IF_NUBAMR*NMBPG + hlen,
E 2
I 2
D 4
	    uballoc(ifu->ifu_uban, ifrw->ifrw_addr, IF_NUBAMR*NBPG + ifu->ifu_hlen,
E 4
I 4
D 22
	    uballoc(ifu->ifu_uban, ifrw->ifrw_addr, nmr*NBPG + ifu->ifu_hlen,
E 4
E 2
D 9
	        UBA_NEED16|UBA_NEEDBDP);
E 9
I 9
	        ifu->ifu_flags);
E 22
I 22
	    uballoc(ifu->iff_uban, ifrw->ifrw_addr, nmr*NBPG + ifu->iff_hlen,
	        ifu->iff_flags);
E 22
E 9
	if (info == 0)
D 2
		goto bad;
E 2
I 2
		return (0);
E 2
	ifrw->ifrw_info = info;
	ifrw->ifrw_bdp = UBAI_BDP(info);
D 2
	ifrw->ifrw_proto = UBAMR_MRV | UBAI_DPDF(info);
	ifrw->ifrw_mr = &ifu->if_uba[UBAI_MR(info) + 1];
E 2
I 2
D 5
	ifrw->ifrw_proto = UBAMR_MRV | (UBAI_MR(info) << UBAMR_DPSHIFT);
E 5
I 5
	ifrw->ifrw_proto = UBAMR_MRV | (UBAI_BDP(info) << UBAMR_DPSHIFT);
E 5
D 19
	ifrw->ifrw_mr = &ifu->ifu_uba->uba_map[UBAI_MR(info) + 1];
E 19
I 19
D 22
	ifrw->ifrw_mr = &ifu->ifu_uba->uba_map[UBAI_MR(info) + (ifu->ifu_hlen?
E 22
I 22
D 31
	ifrw->ifrw_mr = &ifu->iff_uba->uba_map[UBAI_MR(info) + (ifu->iff_hlen?
E 22
		1 : 0)];
E 31
I 31
D 40
	ifrw->ifrw_mr = &ifu->iff_ubamr[UBAI_MR(info) + (ifu->iff_hlen? 1 : 0)];
E 40
I 40
	ifrw->ifrw_mr = &ifu->iff_uba->uba_map[UBAI_MR(info) + (ifu->iff_hlen?
		1 : 0)];
E 40
E 31
E 19
	return (1);
E 2
}

/*
D 3
 * Pull read data off a interface, given length.
 * Map the header into a mbuf, and then copy or
 * remap the data into a chain of mbufs.
 * Return 0 if there is no space, or a pointer
 * to the assembled mbuf chain.
E 3
I 3
 * Pull read data off a interface.
 * Len is length of data, with local net header stripped.
 * Off is non-zero if a trailer protocol was used, and
 * gives the offset of the trailer information.
 * We copy the trailer information and then all the normal
 * data into mbufs.  When full cluster sized units are present
 * on the interface on cluster boundaries we can get them more
 * easily by remapping, and take advantage of this here.
I 21
 * Prepend a pointer to the interface structure,
 * so that protocols can determine where incoming packets arrived.
I 23
 * Note: we may be called to receive from a transmit buffer by some
 * devices.  In that case, we must force normal mapping of the buffer,
 * so that the correct data will appear (only unibus maps are 
 * changed when remapping the transmit buffers).
E 23
E 21
E 3
 */
struct mbuf *
D 3
if_rubaget(ifu, len)
E 3
I 3
D 21
if_rubaget(ifu, totlen, off0)
E 21
I 21
D 22
if_rubaget(ifu, totlen, off0, ifp)
E 21
E 3
	register struct ifuba *ifu;
E 22
I 22
if_ubaget(ifu, ifr, totlen, off0, ifp)
	struct ifubinfo *ifu;
	register struct ifrw *ifr;
E 22
D 3
	int len;
E 3
I 3
	int totlen, off0;
I 21
	struct ifnet *ifp;
E 21
E 3
{
D 4
	register struct mbuf *m;
E 4
I 4
D 22
	struct mbuf *top, **mp, *m;
E 22
I 22
	struct mbuf *top, **mp;
	register struct mbuf *m;
E 22
	int off = off0, len;
E 4
D 5
	register caddr_t cp;
E 5
I 5
D 22
	register caddr_t cp = ifu->ifu_r.ifrw_addr + ifu->ifu_hlen;
E 22
I 22
D 25
	register caddr_t cp = ifr->ifrw_addr + ifu->iff_hlen;
E 25
I 25
D 26
	register caddr_t cp = ifr->ifrw_addr + ifu->iff_hlen, p;
E 26
I 26
	register caddr_t cp = ifr->ifrw_addr + ifu->iff_hlen, pp;
E 26
E 25
E 22
E 5
D 3
	struct mbuf *mp, *p, *top;
E 3
I 3
D 4
	struct mbuf **mp, *p, *top;
	int len, off = off0;
E 4
E 3

I 2
D 12
COUNT(IF_RUBAGET);
E 12
E 2
D 3
	/*
	 * First pull local net header off into a mbuf.
	 */
	MGET(m, 0);
	if (m == 0)
		return (0);
	m->m_off = MMINOFF;
D 2
	m->m_len = ifu->if_hlen;
E 2
I 2
	m->m_len = ifu->ifu_hlen;
E 2
	top = m;
	cp = ifu->ifu_r.ifrw_addr;
D 2
	bcopy(cp, mtod(m, caddr_t), ifu->if_hlen);
	len -= hlen;
	cp += hlen;
E 2
I 2
	bcopy(cp, mtod(m, caddr_t), ifu->ifu_hlen);
	len -= ifu->ifu_hlen;
	cp += ifu->ifu_hlen;
E 3
E 2
D 22

E 22
I 5
D 6
printf("if_rubaget totlen %d off0 %d cp %x\n", totlen, off0, cp);
E 6
E 5
D 3
	/*
	 * Now pull data off.  If whole pages
	 * are there, pull into pages if possible,
	 * otherwise copy small blocks into mbufs.
	 */
	mp = m;
	while (len > 0) {
E 3
I 3
	top = 0;
	mp = &top;
I 23
	if (ifr->ifrw_flags & IFRW_W)
		rcv_xmtbuf((struct ifxmt *)ifr);
E 23
	while (totlen > 0) {
E 3
D 15
		MGET(m, 0);
E 15
I 15
		MGET(m, M_DONTWAIT, MT_DATA);
E 15
D 23
		if (m == 0)
D 2
			goto flush;
E 2
I 2
			goto bad;
E 23
I 23
		if (m == 0) {
			m_freem(top);
			top = 0;
			goto out;
		}
E 23
I 3
		if (off) {
			len = totlen - off;
D 22
			cp = ifu->ifu_r.ifrw_addr + ifu->ifu_hlen + off;
E 22
I 22
			cp = ifr->ifrw_addr + ifu->iff_hlen + off;
E 22
		} else
			len = totlen;
E 3
E 2
D 5
		if (len >= CLSIZE) {
E 5
I 5
D 6
printf("m %x len %d off %d cp %x\n", m, len, off, cp);
E 6
D 21
		if (len >= CLBYTES) {
E 21
I 21
D 28
		if (len >= NBPG) {
E 28
I 28
		if (len >= CLBYTES/2) {
E 28
E 21
E 5
I 4
D 25
			struct mbuf *p;
E 25
E 4
			struct pte *cpte, *ppte;
D 4
			int i, x, *ip;
E 4
I 4
			int x, *ip, i;
E 4

I 21
			/*
			 * If doing the first mbuf and
			 * the interface pointer hasn't been put in,
			 * put it in a separate mbuf to preserve alignment.
			 */
			if (ifp) {
				len = 0;
				goto nopage;
			}
E 21
D 25
			MCLGET(p, 1);
			if (p == 0)
E 25
I 25
			MCLGET(m);
			if (m->m_len != CLBYTES)
E 25
				goto nopage;
D 5
			m->m_len = CLSIZE;
E 5
I 5
D 21
			len = m->m_len = CLBYTES;
E 21
I 21
D 22
			len = m->m_len = min(len, CLBYTES);
E 22
I 22
			m->m_len = MIN(len, CLBYTES);
E 22
E 21
E 5
D 25
			m->m_off = (int)p - (int)m;
E 25
D 4
			if ((int)cp & CLOFF)
E 4
I 4
			if (!claligned(cp))
E 4
				goto copy;

			/*
D 4
			 * Cluster size data on cluster size boundary.
			 * Input by remapping newly allocated pages to
			 * UNIBUS, and taking pages with data already
			 * in them.
			 *
			 * Cpte is the pte of the virtual memory which
			 * is mapped to the UNIBUS, and ppte is the pte
			 * for the fresh pages.  We switch the memory
			 * copies of these pte's, to make the allocated
			 * virtual memory contain the data (using the old
			 * physical pages).  We have to rewrite
			 * the UNIBUS map so that the newly allocated
			 * pages will be used for the next UNIBUS read,
			 * and invalidate the kernel translations
			 * for the virtual addresses of the pages
			 * we are flipping.
			 *
			 * The idea here is that this is supposed
			 * to take less time than copying the data.
E 4
I 4
D 26
			 * Switch pages mapped to UNIBUS with new page p,
E 26
I 26
			 * Switch pages mapped to UNIBUS with new page pp,
E 26
			 * as quick form of copy.  Remap UNIBUS and invalidate.
E 4
			 */
I 25
D 26
			p = mtod(m, char *);
E 26
I 26
			pp = mtod(m, char *);
E 26
E 25
D 4
			cpte = &Mbmap[mtocl(cp)];
			ppte = &Mbmap[mtocl(p)];
E 4
I 4
D 43
			cpte = &Mbmap[mtocl(cp)*CLSIZE];
D 26
			ppte = &Mbmap[mtocl(p)*CLSIZE];
E 26
I 26
			ppte = &Mbmap[mtocl(pp)*CLSIZE];
E 43
I 43
			cpte = kvtopte(cp);
			ppte = kvtopte(pp);
E 43
E 26
E 4
D 2
			x = btop(cp - ifu->if_r.ifrw_addr);
E 2
I 2
D 22
			x = btop(cp - ifu->ifu_r.ifrw_addr);
E 2
D 5
			ip = (int *)&ifu->ifu_r.ifrw_mr[x+1];
E 5
I 5
			ip = (int *)&ifu->ifu_r.ifrw_mr[x];
E 22
I 22
			x = btop(cp - ifr->ifrw_addr);
			ip = (int *)&ifr->ifrw_mr[x];
E 22
E 5
			for (i = 0; i < CLSIZE; i++) {
				struct pte t;
D 4
				t = *ppte; *ppte = *cpte; *cpte = t;
E 4
I 4
				t = *ppte; *ppte++ = *cpte; *cpte = t;
E 4
D 43
				*ip++ =
D 2
				    *cpte++->pg_pfnum|ifu->if_r.ifrw_proto;
E 2
I 2
D 22
				    cpte++->pg_pfnum|ifu->ifu_r.ifrw_proto;
E 22
I 22
				    cpte++->pg_pfnum|ifr->ifrw_proto;
E 43
I 43
				*ip++ = cpte++->pg_pfnum|ifr->ifrw_proto;
E 43
E 22
E 2
				mtpr(TBIS, cp);
D 2
				cp += NMBPG;
E 2
I 2
				cp += NBPG;
E 2
D 26
				mtpr(TBIS, (caddr_t)p);
D 2
				p += NMBPG / sizeof (*p);
E 2
I 2
D 25
				p += NBPG / sizeof (*p);
E 25
I 25
				p += NBPG;
E 26
I 26
				mtpr(TBIS, (caddr_t)pp);
				pp += NBPG;
E 26
E 25
E 2
			}
			goto nocopy;
		}
nopage:
D 21
		m->m_len = MIN(MLEN, len);
E 21
		m->m_off = MMINOFF;
I 21
		if (ifp) {
			/*
			 * Leave room for ifp.
			 */
			m->m_len = MIN(MLEN - sizeof(ifp), len);
			m->m_off += sizeof(ifp);
		} else 
			m->m_len = MIN(MLEN, len);
E 21
I 5
D 6
printf("nopage m->m_len %d, m %x\n", m->m_len, len);
E 6
E 5
copy:
I 5
D 6
printf("copy %d from %x to %x", m->m_len, cp, mtod(m, caddr_t));
E 6
E 5
		bcopy(cp, mtod(m, caddr_t), (unsigned)m->m_len);
		cp += m->m_len;
nocopy:
D 3
		len -= m->m_len;
		mp->m_next = m;
		mp = m;
E 3
I 3
		*mp = m;
		mp = &m->m_next;
		if (off) {
I 4
			/* sort of an ALGOL-W style for statement... */
E 4
			off += m->m_len;
			if (off == totlen) {
D 22
				cp = ifu->ifu_r.ifrw_addr + ifu->ifu_hlen;
E 22
I 22
				cp = ifr->ifrw_addr + ifu->iff_hlen;
E 22
				off = 0;
D 5
				totlen -= off0;
E 5
I 5
				totlen = off0;
E 5
			}
D 5
		}
E 5
I 5
		} else
D 8
			totlen -= len;
E 8
I 8
			totlen -= m->m_len;
I 21
		if (ifp) {
			/*
			 * Prepend interface pointer to first mbuf.
			 */
			m->m_len += sizeof(ifp);
			m->m_off -= sizeof(ifp);
			*(mtod(m, struct ifnet **)) = ifp;
			ifp = (struct ifnet *)0;
		}
E 21
E 8
E 5
E 3
	}
I 23
out:
	if (ifr->ifrw_flags & IFRW_W)
		restor_xmtbuf((struct ifxmt *)ifr);
E 23
	return (top);
D 23
bad:
	m_freem(top);
	return (0);
E 23
I 23
}

/*
 * Change the mapping on a transmit buffer so that if_ubaget may
 * receive from that buffer.  Copy data from any pages mapped to Unibus
 * into the pages mapped to normal kernel virtual memory, so that
 * they can be accessed and swapped as usual.  We take advantage
 * of the fact that clusters are placed on the xtofree list
 * in inverse order, finding the last one.
 */
static
rcv_xmtbuf(ifw)
	register struct ifxmt *ifw;
{
	register struct mbuf *m;
	struct mbuf **mprev;
	register i;
D 33
	int t;
E 33
	char *cp;

D 27
	while (i = ffs(ifw->ifw_xswapd)) {
E 27
I 27
	while (i = ffs((long)ifw->ifw_xswapd)) {
E 27
		cp = ifw->ifw_base + i * CLBYTES;
		i--;
		ifw->ifw_xswapd &= ~(1<<i);
D 33
		i *= CLSIZE;
E 33
		mprev = &ifw->ifw_xtofree;
		for (m = ifw->ifw_xtofree; m && m->m_next; m = m->m_next)
			mprev = &m->m_next;
		if (m == NULL)
D 30
			panic("rcv_xmtbuf");
E 30
I 30
D 33
			return;
E 33
I 33
			break;
E 33
E 30
		bcopy(mtod(m, caddr_t), cp, CLBYTES);
D 27
		m_free(m);
E 27
I 27
		(void) m_free(m);
E 27
		*mprev = NULL;
D 33
		for (t = 0; t < CLSIZE; t++) {
			ifw->ifw_mr[i] = ifw->ifw_wmap[i];
			i++;
		}
E 33
	}
I 33
	ifw->ifw_xswapd = 0;
	for (i = 0; i < ifw->ifw_nmr; i++)
		ifw->ifw_mr[i] = ifw->ifw_wmap[i];
E 33
}

/*
 * Put a transmit buffer back together after doing an if_ubaget on it,
 * which may have swapped pages.
 */
static
restor_xmtbuf(ifw)
	register struct ifxmt *ifw;
{
	register i;

D 24
	for (i = 0; i < IF_MAXNUBAMR; i++)
E 24
I 24
	for (i = 0; i < ifw->ifw_nmr; i++)
E 24
		ifw->ifw_wmap[i] = ifw->ifw_mr[i];
E 23
}

/*
 * Map a chain of mbufs onto a network interface
 * in preparation for an i/o operation.
 * The argument chain of mbufs includes the local network
 * header which is copied to be in the mapped, aligned
 * i/o space.
 */
D 22
if_wubaput(ifu, m)
	register struct ifuba *ifu;
E 22
I 22
if_ubaput(ifu, ifw, m)
	struct ifubinfo *ifu;
	register struct ifxmt *ifw;
E 22
	register struct mbuf *m;
{
	register struct mbuf *mp;
	register caddr_t cp, dp;
	register int i;
D 4
	int xswapd = ifu->ifu_xswapd;
	int x;
E 4
I 4
	int xswapd = 0;
D 19
	int x, cc;
E 19
I 19
	int x, cc, t;
E 19
E 4

I 2
D 12
COUNT(IF_WUBAPUT);
E 12
E 2
D 7
	ifu->ifu_xswapd = 0;
E 7
D 22
	cp = ifu->ifu_w.ifrw_addr;
E 22
I 22
	cp = ifw->ifw_addr;
E 22
	while (m) {
		dp = mtod(m, char *);
D 5
		if (claligned(cp) && claligned(dp)) {
E 5
I 5
D 21
		if (claligned(cp) && claligned(dp) && m->m_len == CLBYTES) {
E 21
I 21
		if (claligned(cp) && claligned(dp) &&
		    (m->m_len == CLBYTES || m->m_next == (struct mbuf *)0)) {
E 21
E 5
D 43
			struct pte *pte; int *ip;
D 4
			pte = &Mbmap[mtocl(dp)];
E 4
I 4
			pte = &Mbmap[mtocl(dp)*CLSIZE];
E 43
I 43
			struct pte *pte;
			int *ip;

			pte = kvtopte(dp);
E 43
E 4
D 22
			x = btop(cp - ifu->ifu_w.ifrw_addr);
D 2
			ip = &ifu->ifu_w.ifrw_mr[x + 1];
E 2
I 2
D 5
			ip = (int *)&ifu->ifu_w.ifrw_mr[x + 1];
E 5
I 5
			ip = (int *)&ifu->ifu_w.ifrw_mr[x];
E 22
I 22
			x = btop(cp - ifw->ifw_addr);
			ip = (int *)&ifw->ifw_mr[x];
E 22
E 5
E 2
			for (i = 0; i < CLSIZE; i++)
D 43
				*ip++ =
D 22
				    ifu->ifu_w.ifrw_proto | pte++->pg_pfnum;
E 22
I 22
				    ifw->ifw_proto | pte++->pg_pfnum;
E 43
I 43
				*ip++ = ifw->ifw_proto | pte++->pg_pfnum;
E 43
E 22
D 4
			ifu->ifu_xswapd |= 1 << (x>>CLSHIFT);
		} else
E 4
I 4
D 5
			ifu->ifu_xswapd |= 1 << (x>>(CLSHIFT-PGSHIFT));
E 5
I 5
			xswapd |= 1 << (x>>(CLSHIFT-PGSHIFT));
E 5
			mp = m->m_next;
D 22
			m->m_next = ifu->ifu_xtofree;
			ifu->ifu_xtofree = m;
E 22
I 22
			m->m_next = ifw->ifw_xtofree;
			ifw->ifw_xtofree = m;
E 22
			cp += m->m_len;
		} else {
E 4
			bcopy(mtod(m, caddr_t), cp, (unsigned)m->m_len);
D 4
		cp += m->m_len;
		MFREE(m, mp);			/* XXX too soon! */
E 4
I 4
			cp += m->m_len;
			MFREE(m, mp);
		}
E 4
		m = mp;
	}
I 4

	/*
D 22
	 * Xswapd is the set of clusters we just mapped out.  Ifu->ifu_xswapd
E 22
I 22
	 * Xswapd is the set of clusters we just mapped out.  Ifu->iff_xswapd
E 22
	 * is the set of clusters mapped out from before.  We compute
	 * the number of clusters involved in this operation in x.
	 * Clusters mapped out before and involved in this operation
	 * should be unmapped so original pages will be accessed by the device.
	 */
D 22
	cc = cp - ifu->ifu_w.ifrw_addr;
	x = ((cc - ifu->ifu_hlen) + CLBYTES - 1) >> CLSHIFT;
I 5
	ifu->ifu_xswapd &= ~xswapd;
E 5
E 4
	xswapd &= ~ifu->ifu_xswapd;
D 5
	if (xswapd)
		while (i = ffs(xswapd)) {
			i--;
I 4
			if (i >= x)
				break;
E 4
			xswapd &= ~(1<<i);
D 4
			i <<= CLSHIFT;
E 4
I 4
			i *= CLSIZE;
E 4
			for (x = 0; x < CLSIZE; x++) {
D 2
				ifu->ifu_rw.ifrw_mr[i] = ifu->ifu_xmap[i];
E 2
I 2
				ifu->ifu_w.ifrw_mr[i] = ifu->ifu_wmap[i];
E 2
				i++;
			}
E 5
I 5
	while (i = ffs(ifu->ifu_xswapd)) {
E 22
I 22
	cc = cp - ifw->ifw_addr;
	x = ((cc - ifu->iff_hlen) + CLBYTES - 1) >> CLSHIFT;
	ifw->ifw_xswapd &= ~xswapd;
D 27
	while (i = ffs(ifw->ifw_xswapd)) {
E 27
I 27
	while (i = ffs((long)ifw->ifw_xswapd)) {
E 27
E 22
		i--;
		if (i >= x)
			break;
D 22
		ifu->ifu_xswapd &= ~(1<<i);
E 22
I 22
		ifw->ifw_xswapd &= ~(1<<i);
E 22
		i *= CLSIZE;
D 19
		for (x = 0; x < CLSIZE; x++) {
E 19
I 19
		for (t = 0; t < CLSIZE; t++) {
E 19
D 22
			ifu->ifu_w.ifrw_mr[i] = ifu->ifu_wmap[i];
E 22
I 22
			ifw->ifw_mr[i] = ifw->ifw_wmap[i];
E 22
			i++;
E 5
		}
I 5
	}
E 5
I 3
D 4
	return (cp - ifu->ifu_w.ifrw_addr);
E 4
I 4
D 22
	ifu->ifu_xswapd |= xswapd;
E 22
I 22
	ifw->ifw_xswapd |= xswapd;
E 22
	return (cc);
E 4
E 3
}
E 1
