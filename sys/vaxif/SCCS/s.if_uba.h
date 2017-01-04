h63093
s 00013/00002/00105
d D 7.3 88/08/04 15:30:32 bostic 14 13
c add Berkeley specific copyright
e
s 00003/00001/00104
d D 7.2 86/08/09 15:16:59 karels 13 12
c generalize uba code to handle Q bus more gracefully
e
s 00001/00001/00104
d D 7.1 86/06/05 01:38:39 mckusick 12 11
c 4.3BSD release version
e
s 00002/00002/00103
d D 6.6 86/02/23 23:30:05 karels 11 10
c lint
e
s 00001/00000/00104
d D 6.5 85/12/18 19:54:59 karels 10 9
c record and use number of map registers actually use in ifw_nmr
e
s 00004/00001/00100
d D 6.4 85/11/07 10:57:14 karels 9 8
c allow receive from transmit buffer (for deuna)
e
s 00064/00018/00037
d D 6.3 85/09/16 22:24:34 karels 8 7
c generalized if_uba support for multiple rcv/xmt buffers per device
e
s 00007/00001/00048
d D 6.2 85/06/08 14:00:23 mckusick 7 6
c Add copyright
e
s 00000/00000/00049
d D 6.1 83/07/29 07:38:35 sam 6 5
c 4.2 distribution
e
s 00001/00000/00048
d D 4.5 82/02/03 11:22:56 sam 5 4
c add flags for uballoc to simplify direct data path interfaces
e
s 00003/00003/00045
d D 4.4 81/12/09 21:11:43 wnj 4 3
c rearrange fields
e
s 00005/00009/00043
d D 4.3 81/12/03 17:29:28 wnj 3 2
c cleanup
e
s 00009/00001/00043
d D 4.2 81/11/26 11:56:10 wnj 2 1
c before carry to ARPAVAX
e
s 00044/00000/00000
d D 4.1 81/11/25 18:14:25 wnj 1 0
c date and time created 81/11/25 18:14:25 by wnj
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
D 12
 * Copyright (c) 1982 Regents of the University of California.
E 12
I 12
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 12
D 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
I 14
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
E 14
 *
 *	%W% (Berkeley) %G%
 */
E 7

/*
 * Structure and routine definitions
 * for UNIBUS network interfaces.
 */

D 3
#define	IF_NUBAMR	6
E 3
I 3
#define	IF_MAXNUBAMR	10
E 3
/*
D 8
 * Each interface has one of these structures giving information
 * about UNIBUS resources held by the interface.
E 8
I 8
 * Each interface has structures giving information
 * about UNIBUS resources held by the interface
 * for each send and receive buffer.
E 8
 *
 * We hold IF_NUBAMR map registers for datagram data, starting
 * at ifr_mr.  Map register ifr_mr[-1] maps the local network header
 * ending on the page boundary.  Bdp's are reserved for read and for
 * write, given by ifr_bdp.  The prototype of the map register for
 * read and for write is saved in ifr_proto.
 *
 * When write transfers are not full pages on page boundaries we just
 * copy the data into the pages mapped on the UNIBUS and start the
 * transfer.  If a write transfer is of a (1024 byte) page on a page
 * boundary, we swap in UNIBUS pte's to reference the pages, and then
 * remap the initial pages (from ifu_wmap) when the transfer completes.
 *
 * When read transfers give whole pages of data to be input, we
 * allocate page frames from a network page list and trade them
 * with the pages already containing the data, mapping the allocated
 * pages to replace the input pages for the next UNIBUS data input.
 */
D 8
struct	ifuba {
	short	ifu_uban;			/* uba number */
I 3
	short	ifu_hlen;			/* local net header length */
E 3
	struct	uba_regs *ifu_uba;		/* uba regs, in vm */
	struct ifrw {
I 4
		caddr_t	ifrw_addr;		/* virt addr of header */
		int	ifrw_bdp;		/* unibus bdp */
E 4
		int	ifrw_info;		/* value from ubaalloc */
D 4
		short	ifrw_bdp;		/* unibus bdp */
		struct	pte *ifrw_mr;		/* base of map registers */
E 4
		int	ifrw_proto;		/* map register prototype */
D 4
		caddr_t	ifrw_addr;		/* virt addr of header */
E 4
I 4
		struct	pte *ifrw_mr;		/* base of map registers */
E 4
	} ifu_r, ifu_w;
D 3
	struct	pte ifu_wmap[IF_NUBAMR];	/* base pages for output */
I 2
	short	ifu_hlen;
E 2
/* ifu_xswapd is set when we have swapped write pte's to do direct output */
D 2
/* bit i of ifu_xswapd 
E 2
I 2
/* bit i of ifu_xswapd */
E 2
	short	ifu_xswapd;			/* bit map of pages swapped */
I 2
	int	ifu_ierrors;
	int	ifu_oerrors;
	int	ifu_collisions;
E 3
I 3
	struct	pte ifu_wmap[IF_MAXNUBAMR];	/* base pages for output */
	short	ifu_xswapd;			/* mask of clusters swapped */
I 5
	short	ifu_flags;			/* used during uballoc's */
E 5
	struct	mbuf *ifu_xtofree;		/* pages being dma'd out */
E 8
I 8

/*
 * Information per interface.
 */
struct	ifubinfo {
	short	iff_uban;			/* uba number */
	short	iff_hlen;			/* local net header length */
D 13
	struct	uba_regs *iff_uba;		/* uba regs, in vm */
E 13
I 13
	struct	uba_regs *iff_uba;		/* uba adaptor regs, in vm */
	struct	pte *iff_ubamr;			/* uba map regs, in vm */
E 13
	short	iff_flags;			/* used during uballoc's */
E 8
E 3
E 2
};
I 2

I 8
/*
 * Information per buffer.
 */
struct ifrw {
	caddr_t	ifrw_addr;			/* virt addr of header */
D 9
	int	ifrw_bdp;			/* unibus bdp */
E 9
I 9
	short	ifrw_bdp;			/* unibus bdp */
	short	ifrw_flags;			/* type, etc. */
#define	IFRW_W	0x01				/* is a transmit buffer */
E 9
	int	ifrw_info;			/* value from ubaalloc */
	int	ifrw_proto;			/* map register prototype */
	struct	pte *ifrw_mr;			/* base of map registers */
};

/*
 * Information per transmit buffer, including the above.
 */
struct ifxmt {
	struct	ifrw ifrw;
	caddr_t	ifw_base;			/* virt addr of buffer */
	struct	pte ifw_wmap[IF_MAXNUBAMR];	/* base pages for output */
	struct	mbuf *ifw_xtofree;		/* pages being dma'd out */
	short	ifw_xswapd;			/* mask of clusters swapped */
I 10
	short	ifw_nmr;			/* number of entries in wmap */
E 10
};
#define	ifw_addr	ifrw.ifrw_addr
#define	ifw_bdp		ifrw.ifrw_bdp
I 9
#define	ifw_flags	ifrw.ifrw_flags
E 9
#define	ifw_info	ifrw.ifrw_info
#define	ifw_proto	ifrw.ifrw_proto
#define	ifw_mr		ifrw.ifrw_mr

/*
 * Most interfaces have a single receive and a single transmit buffer,
 * and use struct ifuba to store all of the unibus information.
 */
struct ifuba {
	struct	ifubinfo ifu_info;
	struct	ifrw ifu_r;
	struct	ifxmt ifu_xmt;
};

#define	ifu_uban	ifu_info.iff_uban
#define	ifu_hlen	ifu_info.iff_hlen
#define	ifu_uba		ifu_info.iff_uba
I 13
#define	ifu_ubamr	ifu_info.iff_ubamr
E 13
#define	ifu_flags	ifu_info.iff_flags
#define	ifu_w		ifu_xmt.ifrw
#define	ifu_xtofree	ifu_xmt.ifw_xtofree

E 8
#ifdef 	KERNEL
D 8
struct	mbuf *if_rubaget();
E 8
I 8
#define	if_ubainit(ifuba, uban, hlen, nmr) \
		if_ubaminit(&(ifuba)->ifu_info, uban, hlen, nmr, \
D 11
			&(ifuba)->ifu_r, 1, &(ifuba)->ifu_w, 1)
E 11
I 11
			&(ifuba)->ifu_r, 1, &(ifuba)->ifu_xmt, 1)
E 11
#define	if_rubaget(ifu, totlen, off0, ifp) \
		if_ubaget(&(ifu)->ifu_info, &(ifu)->ifu_r, totlen, off0, ifp)
#define	if_wubaput(ifu, m) \
D 11
		if_ubaput(&(ifu)->ifu_info, &(ifu)->ifu_w, m)
E 11
I 11
		if_ubaput(&(ifu)->ifu_info, &(ifu)->ifu_xmt, m)
E 11
struct	mbuf *if_ubaget();
E 8
#endif
E 2
E 1
