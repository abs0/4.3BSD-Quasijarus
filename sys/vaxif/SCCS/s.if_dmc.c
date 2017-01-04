h32988
s 00001/00001/00974
d D 7.6 00/03/12 12:40:41 msokolov 49 48
c interface must be UP and RUNNING to send packets, not just UP
e
s 00030/00015/00945
d D 7.5 88/10/22 14:02:11 karels 48 47
c use uballoc macros, new qbus autoconf (old mbufs)
e
s 00008/00022/00952
d D 7.4 88/10/12 15:04:40 sklower 47 46
c checkpoint version before var sockaddr changes
e
s 00013/00002/00961
d D 7.3 88/08/04 15:16:02 bostic 46 45
c add Berkeley specific copyright
e
s 00088/00064/00875
d D 7.2 88/05/27 16:38:20 karels 45 44
c cleanup up-down code; limit snd queue to 3 packets until we get going;
c use if_timer instead of private timeout
e
s 00001/00001/00938
d D 7.1 86/06/05 17:03:12 mckusick 44 43
c 4.3BSD release version
e
s 00001/00000/00938
d D 6.13 86/06/02 14:44:32 karels 43 42
c lint
e
s 00022/00006/00916
d D 6.12 86/04/23 12:23:48 karels 42 41
c protect IF_ENQUEUE, add code to reset when marked down
e
s 00004/00004/00918
d D 6.11 86/03/24 19:27:30 karels 41 40
c don't make me work
e
s 00005/00008/00917
d D 6.10 86/02/20 16:06:50 karels 40 38
c lint; change some printd's to log's
e
s 00004/00008/00917
d R 6.10 86/02/19 22:14:27 karels 39 38
c lint; change some printd's to log's
e
s 00000/00003/00925
d D 6.9 86/01/08 14:29:48 karels 38 37
c rm bbnnet
e
s 00000/00000/00928
d D 6.8 85/12/19 15:42:16 karels 37 36
c rm bbnnet
e
s 00035/00318/00893
d D 6.7 85/09/16 22:25:03 karels 36 35
c generalized if_uba support for multiple rcv/xmt buffers per device
e
s 00007/00001/01204
d D 6.6 85/06/08 13:52:51 mckusick 35 34
c Add copyright
e
s 00019/00031/01186
d D 6.5 85/05/01 09:07:42 karels 34 33
c move interface addresses into protocols; remove struct ether_addr again
e
s 00439/00211/00778
d D 6.4 84/12/20 16:11:17 karels 33 32
c from salkind, with some changes/retentions
e
s 00659/00137/00330
d D 6.3 84/09/27 07:50:16 tef 32 31
c Major rewrite, mostly by Bill Nesheim (bill@cornell); uses clists
c for command queues to allow multiple outstanding dma requests; has
c new unibus interface from Lou Salkind; works even at 1Mbaud with DMR-11's.
e
s 00012/00012/00455
d D 6.2 84/08/29 20:42:43 bloom 31 30
c change ot includes.  no more ../h
e
s 00000/00000/00467
d D 6.1 83/07/29 07:37:15 sam 30 29
c 4.2 distribution
e
s 00008/00008/00459
d D 4.29 83/06/13 22:45:30 sam 29 28
c lint
e
s 00009/00007/00458
d D 4.28 83/06/13 00:12:44 sam 28 27
c just a little bit more
e
s 00071/00034/00394
d D 4.27 83/06/12 23:59:56 sam 27 26
c someday I'll get all this correct (sigh)
e
s 00000/00001/00428
d D 4.26 83/05/27 13:49:50 sam 26 25
c lint
e
s 00001/00001/00428
d D 4.25 83/02/21 16:09:10 sam 25 24
c typo
e
s 00002/00000/00427
d D 4.24 83/02/20 23:35:55 sam 24 23
c add disclaimer
e
s 00015/00006/00412
d D 4.23 83/02/20 22:58:46 sam 23 22
c merge changes from steve glaser
e
s 00001/00001/00417
d D 4.22 82/12/17 12:13:16 sam 22 21
c sun merge
e
s 00005/00003/00413
d D 4.21 82/11/13 23:04:25 sam 21 20
c merge 4.1b with 4.1c
e
s 00001/00001/00415
d D 4.20 82/10/31 15:04:42 root 20 19
c ubareset routines now just if_reset!
e
s 00009/00007/00407
d D 4.19 82/10/10 16:58:32 root 19 18
c move vax headers into vax directories
e
s 00004/00006/00410
d D 4.18 82/10/09 06:09:29 wnj 18 17
c fix includes
e
s 00000/00009/00416
d D 4.17 82/06/20 00:51:52 sam 17 16
c purge COUNT stuff now that we can use gprof
e
s 00001/00001/00424
d D 4.16 82/06/13 22:59:50 sam 16 15
c add class a/b/c net #'s and purge logical host kludge code
e
s 00001/00002/00424
d D 4.15 82/06/12 23:17:48 wnj 15 14
c now the routing code might wokr
e
s 00005/00012/00421
d D 4.14 82/04/24 22:34:41 sam 14 13
c patches from shannon
e
s 00003/00001/00430
d D 4.13 82/04/20 14:02:14 sam 13 12
c make 3com kludge conditional
e
s 00001/00001/00430
d D 4.12 82/04/16 14:19:18 sam 12 11
c don't let driver sleep on interrupt stack if can't get bdp
e
s 00001/00000/00430
d D 4.11 82/04/11 02:39:18 feldman 11 10
c raise splimp for ec hack (temporary)
e
s 00004/00003/00426
d D 4.10 82/04/10 18:25:45 sam 10 9
c invert output path to pass back error indications
e
s 00001/00001/00428
d D 4.9 82/03/30 19:57:22 sam 9 8
c routing code now operational
e
s 00016/00000/00413
d D 4.8 82/03/30 11:31:21 sam 8 7
c with routing, but not forwarding
e
s 00019/00015/00394
d D 4.7 82/03/28 14:21:03 sam 7 6
c convert interfaces to sockaddr's and add hooks for routing
e
s 00001/00001/00408
d D 4.6 82/03/19 01:48:30 wnj 6 5
c fix to use only one soft intr for net thereby fixing bug in raw sockets
e
s 00013/00003/00396
d D 4.5 82/03/15 04:43:14 wnj 5 4
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00003/00003/00396
d D 4.4 82/03/13 12:51:35 sam 4 3
c lint
e
s 00007/00063/00392
d D 4.3 82/02/15 11:46:12 root 3 2
c move defines into header file and bring bdp stuff uptodate
e
s 00001/00001/00454
d D 4.2 82/02/12 12:12:02 root 2 1
c btop -> btoc
e
s 00455/00000/00000
d D 4.1 82/02/08 22:16:44 root 1 0
c date and time created 82/02/08 22:16:44 by root
e
u
U
t
T
I 1
D 35
/*	%M%	%I%	%E%	*/
E 35
I 35
/*
D 44
 * Copyright (c) 1982 Regents of the University of California.
E 44
I 44
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 44
D 46
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 46
I 46
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
E 46
 *
 *	%W% (Berkeley) %G%
 */
E 35

#include "dmc.h"
#if NDMC > 0
D 33
#define printd if(dmcdebug)printf
D 23
int dmcdebug = 1;
E 23
I 23
int dmcdebug = 0;
E 33
I 33

E 33
E 23
/*
 * DMC11 device driver, internet version
 *
D 32
 * TODO
 *	allow more than one outstanding read or write.
E 32
I 32
D 33
 *	Bill Nesheim	(bill@cornell.arpa or {vax135,uw-beaver,ihnp4}!bill)
E 33
I 33
 *	Bill Nesheim
E 33
 *	Cornell University
D 33
 *	Department of Computer Science
E 33
E 32
I 24
 *
D 27
 * UNTESTED WITH 4.1C
E 27
I 27
D 32
 * UNTESTED WITH 4.2
E 32
I 32
D 33
 *	Based loosly on 4.2BSD release
 *	The UNIBUS support routines were taken from Lou Salkind's DEUNA driver
 *
 * TO DO:
 *	generalize unibus routines
 *	add timeout to mark interface down when other end of link dies
 *	figure out better way to check for completed buffers
 *	(not critical with DMC, only 7 bufs, but may cause problems
 *		on a DMR)
E 33
I 33
 *	Lou Salkind
 *	New York University
E 33
E 32
E 27
E 24
 */
I 33

/* #define DEBUG	/* for base table dump on fatal error */

E 33
I 22
#include "../machine/pte.h"
E 22

D 31
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
D 22
#include "../h/pte.h"
E 22
#include "../h/buf.h"
I 29
#include "../h/ioctl.h"			/* must precede tty.h */
E 29
#include "../h/tty.h"
#include "../h/protosw.h"
#include "../h/socket.h"
D 19
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/cpu.h"
#include "../h/mtpr.h"
E 19
#include "../h/vmmac.h"
I 19
D 27
#include <errno.h>
E 27
I 27
D 29
#include "../h/ioctl.h"
E 29
#include "../h/errno.h"
E 31
I 31
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
D 32
#include "ioctl.h"			/* must precede tty.h */
E 32
I 32
#include "ioctl.h"		/* must precede tty.h */
E 32
#include "tty.h"
#include "protosw.h"
#include "socket.h"
I 40
#include "syslog.h"
E 40
#include "vmmac.h"
#include "errno.h"
E 31
E 27

#include "../net/if.h"
I 21
#include "../net/netisr.h"
E 21
#include "../net/route.h"
I 36

D 38
#ifdef	BBNNET
#define	INET
#endif
E 38
#ifdef	INET
E 36
E 19
D 18
#include "../net/in.h"
#include "../net/in_systm.h"
E 18
I 18
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 43
#include "../netinet/in_var.h"
E 43
I 33
#include "../netinet/ip.h"
D 36
#include "../netinet/ip_var.h"
E 36
I 36
#endif
E 36
E 33
E 18
D 19
#include "../net/if.h"
E 19
I 19

#include "../vax/cpu.h"
#include "../vax/mtpr.h"
E 19
D 18
#include "../net/if_uba.h"
I 3
#include "../net/if_dmc.h"
E 3
#include "../net/ip.h"
#include "../net/ip_var.h"
E 18
I 18
D 31
#include "../vaxif/if_uba.h"
#include "../vaxif/if_dmc.h"
E 31
I 31
#include "if_uba.h"
#include "if_dmc.h"
E 31
E 18
I 8
D 19
#include "../net/route.h"
I 10
#include <errno.h>
E 19
I 19
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 19
E 10
E 8

I 33
#include "../h/time.h"
#include "../h/kernel.h"

D 45
int	dmctimer;			/* timer started? */
int	dmc_timeout = 8;		/* timeout value */
int	dmcwatch();
E 45
I 45
/*
 * output timeout value, sec.; should depend on line speed.
 */
int	dmc_timeout = 20;
E 45

E 33
I 23
D 32
#ifndef DMC_USEMAINT
#define	DMC_USEMAINT	1	/* use maintenance mode */
#endif

E 32
E 23
/*
 * Driver information for auto-configuration stuff.
 */
D 27
int	dmcprobe(), dmcattach(), dmcinit(), dmcoutput(), dmcreset();
E 27
I 27
int	dmcprobe(), dmcattach(), dmcinit(), dmcioctl();
D 45
int	dmcoutput(), dmcreset();
E 45
I 45
int	dmcoutput(), dmcreset(), dmctimeout();
E 45
E 27
struct	uba_device *dmcinfo[NDMC];
u_short	dmcstd[] = { 0 };
struct	uba_driver dmcdriver =
	{ dmcprobe, 0, dmcattach, 0, dmcstd, "dmc", dmcinfo };

I 32
D 33
/* as long as we use clists for command queues, we only have 28 bytes to use! */
/* DMC-11 only has 7 buffers; DMR-11 has 64 */
E 33
#define NRCV 7
D 33
#define NXMT (NRCV - 2)	/* avoid running out of buffers on recv end */ 
E 33
I 33
#define NXMT 3 
E 33
D 36
#define NTOT (NRCV + NXMT)
I 33
#define NCMDS	(NTOT+4)	/* size of command queue */
E 36
I 36
#define NCMDS	(NRCV+NXMT+4)	/* size of command queue */
E 36
E 33

I 33
#define printd if(dmcdebug)printf
int dmcdebug = 0;

E 33
/* error reporting intervals */
#define DMC_RPNBFS	50
#define DMC_RPDSC	1
D 33
#define DMC_RPTMO	20
#define DMC_RPDCK	5
E 33
I 33
#define DMC_RPTMO	10
#define DMC_RPDCK	10
E 33

struct  dmc_command {
	char	qp_cmd;		/* command */
	short	qp_ubaddr;	/* buffer address */
	short	qp_cc;		/* character count || XMEM */
	struct	dmc_command *qp_next;	/* next command on queue */
};

E 32
D 3
struct dmcdevice {
	union {
		char	b[8];
		short	w[4];
	} un;
};

#define	bsel0	un.b[0]
#define	bsel1	un.b[1]
#define	bsel2	un.b[2]
#define	bsel3	un.b[3]
#define	bsel4	un.b[4]
#define	bsel5	un.b[5]
#define	bsel6	un.b[6]
#define	bsel7	un.b[7]
#define	sel0	un.w[0]
#define	sel2	un.w[1]
#define	sel4	un.w[2]
#define	sel6	un.w[3]

#define	DMCMTU	(2048)

#define RDYSCAN	16	/* loop delay for RDYI after RQI */

/* defines for bsel0 */
#define	DMC_BACCI	0
#define	DMC_CNTLI	1
#define	DMC_PERR	2
#define	DMC_BASEI	3
#define	DMC_WRITE	0		/* transmit block */
#define	DMC_READ	4		/* read block */
#define	DMC_RQI		0040		/* port request bit */
#define	DMC_IEI		0100		/* enable input interrupts */
#define	DMC_RDYI	0200		/* port ready */

/* defines for bsel1 */
#define	DMC_MCLR	0100		/* DMC11 Master Clear */
#define	DMC_RUN		0200		/* clock running */

/* defines for bsel2 */
#define	DMC_BACCO	0
#define	DMC_CNTLO	1
#define	DMC_OUX		0		/* transmit block */
#define	DMC_OUR		4		/* read block */
#define	DMC_IEO		0100		/* enable output interrupts */
#define	DMC_RDYO	0200		/* port available */

/* defines for CNTLI mode */
#define	DMC_HDPLX	02000		/* half duplex DDCMP operation */
#define	DMC_SEC		04000		/* half duplex secondary station */
#define	DMC_MAINT	00400		/* enter maintenance mode */

/* defines for BACCI/O and BASEI mode */
#define	DMC_XMEM	0140000		/* xmem bit position */
#define	DMC_CCOUNT	0037777		/* character count mask */
#define	DMC_RESUME	0002000		/* resume (BASEI only) */

/* defines for CNTLO */
#define	DMC_CNTMASK	01777
#define DMC_FATAL	01620

E 3
D 7
#define	DMC_PF	0xff		/* 8 bits of protocol type in ui_flags */
E 7
I 7
D 27
#define	DMC_AF	0xff		/* 8 bits of address type in ui_flags */
E 7
D 16
#define	DMC_NET	0xff00		/* 8 bits of net number in ui_flags */
E 16
I 16
#define	DMC_NET	0xffffff00	/* 24 bits of net number in ui_flags */
E 16

E 27
D 36
/*
I 32
 * The dmcuba structures generalize the ifuba structure
D 33
 * to an arbitrary number of recieve and transmit buffers.
E 33
I 33
 * to an arbitrary number of receive and transmit buffers.
E 33
 */
struct	ifxmt {
D 33
	struct	ifrw x_ifrw;		/* mapping imfo */
E 33
I 33
	struct	ifrw x_ifrw;		/* mapping info */
E 33
	struct	pte x_map[IF_MAXNUBAMR];	/* output base pages */
	short 	x_xswapd;		/* mask of clusters swapped */
	struct	mbuf *x_xtofree;	/* pages being dma'd out */
};
I 33

E 33
struct	dmcuba {
	short	ifu_uban;		/* uba number */
	short	ifu_hlen;		/* local net header length */
	struct	uba_regs *ifu_uba;	/* uba regs, in vm */
	struct	ifrw ifu_r[NRCV];	/* receive information */
	struct	ifxmt ifu_w[NXMT];	/* transmit information */
				/* these should only be pointers */
	short	ifu_flags;		/* used during uballoc's */
};

E 36
struct dmcbufs {
	int	ubinfo;		/* from uballoc */
	short	cc;		/* buffer size */
	short	flags;		/* access control */
};
#define	DBUF_OURS	0	/* buffer is available */
#define	DBUF_DMCS	1	/* buffer claimed by somebody */
#define	DBUF_XMIT	4	/* transmit buffer */
D 33
#define	DBUF_RCV	8	/* recieve buffer */
E 33
I 33
#define	DBUF_RCV	8	/* receive buffer */
E 33

D 36
struct mbuf *dmc_get();
E 36

/*
E 32
 * DMC software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * sc_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
D 32
 * We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
E 32
I 32
 * We also have, for each interface, a  set of 7 UBA interface structures
 * for each, which
 * contain information about the UNIBUS resources held by the interface:
E 32
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
struct dmc_softc {
D 32
	struct	ifnet sc_if;		/* network-visible interface */
	struct	ifuba sc_ifuba;		/* UNIBUS resources */
E 32
I 32
D 41
	short	sc_oused;		/* output buffers currently in use */
	short	sc_iused;		/* input buffers given to DMC */
E 32
	short	sc_flag;		/* flags */
I 33
	int	sc_nticks;		/* seconds since last interrupt */
E 41
E 33
D 32
	short	sc_oactive;		/* output active */
E 32
I 32
	struct	ifnet sc_if;		/* network-visible interface */
D 33
	struct	dmcbufs sc_rbufs[NRCV];	/* recieve buffer info */
E 33
I 33
D 45
	struct	dmcbufs sc_rbufs[NRCV];	/* receive buffer info */
E 33
	struct	dmcbufs sc_xbufs[NXMT];	/* transmit buffer info */
D 36
	struct	dmcuba sc_ifuba;	/* UNIBUS resources */
E 36
I 36
	struct	ifubinfo sc_ifuba;	/* UNIBUS resources */
	struct	ifrw sc_ifr[NRCV];	/* UNIBUS receive buffer maps */
	struct	ifxmt sc_ifw[NXMT];	/* UNIBUS receive buffer maps */
E 45
I 41
	short	sc_oused;		/* output buffers currently in use */
	short	sc_iused;		/* input buffers given to DMC */
	short	sc_flag;		/* flags */
D 45
	int	sc_nticks;		/* seconds since last interrupt */
E 45
E 41
E 36
E 32
	int	sc_ubinfo;		/* UBA mapping info for base table */
D 32
	struct clist sc_que;		/* command queue */
E 32
I 32
	int	sc_errors[4];		/* non-fatal error counters */
#define sc_datck sc_errors[0]
#define sc_timeo sc_errors[1]
#define sc_nobuf sc_errors[2]
#define sc_disc  sc_errors[3]
I 45
	struct	dmcbufs sc_rbufs[NRCV];	/* receive buffer info */
	struct	dmcbufs sc_xbufs[NXMT];	/* transmit buffer info */
	struct	ifubinfo sc_ifuba;	/* UNIBUS resources */
	struct	ifrw sc_ifr[NRCV];	/* UNIBUS receive buffer maps */
	struct	ifxmt sc_ifw[NXMT];	/* UNIBUS receive buffer maps */
E 45
	/* command queue stuff */
D 33
	struct	dmc_command sc_cmdbuf[NTOT+3];
E 33
I 33
	struct	dmc_command sc_cmdbuf[NCMDS];
E 33
	struct	dmc_command *sc_qhead;	/* head of command queue */
	struct	dmc_command *sc_qtail;	/* tail of command queue */
	struct	dmc_command *sc_qactive;	/* command in progress */
	struct	dmc_command *sc_qfreeh;	/* head of list of free cmd buffers */
	struct	dmc_command *sc_qfreet;	/* tail of list of free cmd buffers */
	/* end command queue stuff */
E 32
} dmc_softc[NDMC];

/* flags */
D 32
#define	DMCRUN		01
#define	DMCBMAPPED	02		/* base table mapped */
E 32
I 32
D 33
#define	DMC_ALLOC	01	/* unibus resources allocated */
#define	DMC_BMAPPED	02	/* base table mapped */
E 33
I 33
D 42
#define DMC_ALLOC	01		/* unibus resources allocated */
#define DMC_BMAPPED	02		/* base table mapped */
#define DMC_RESTART	04		/* software restart in progress */
#define DMC_ACTIVE	08		/* device active */
E 42
I 42
D 45
#define DMC_ALLOC	0x01		/* unibus resources allocated */
E 45
I 45
#define DMC_RUNNING	0x01		/* device initialized */
E 45
#define DMC_BMAPPED	0x02		/* base table mapped */
#define DMC_RESTART	0x04		/* software restart in progress */
D 45
#define DMC_ACTIVE	0x08		/* device active */
#define DMC_RUNNING	0x20		/* device initialized */
E 45
I 45
#define DMC_ONLINE	0x08		/* device running (had a RDYO) */
E 45
E 42
E 33
E 32

D 32
struct dmc_base {
	short	d_base[128];		/* DMC base table */
E 32
I 32
D 33
struct	dmc_base {
	short	d_base[128];	/* DMC base table */
E 33
I 33
struct dmc_base {
	short	d_base[128];		/* DMC base table */
E 33
E 32
} dmc_base[NDMC];

D 32
#define	loword(x)	((short *)&x)[0]
#define	hiword(x)	((short *)&x)[1]
E 32
I 32
/* queue manipulation macros */
#define	QUEUE_AT_HEAD(qp, head, tail) \
	(qp)->qp_next = (head); \
	(head) = (qp); \
	if ((tail) == (struct dmc_command *) 0) \
		(tail) = (head) 
E 32

I 32
#define QUEUE_AT_TAIL(qp, head, tail) \
	if ((tail)) \
		(tail)->qp_next = (qp); \
	else \
		(head) = (qp); \
	(qp)->qp_next = (struct dmc_command *) 0; \
	(tail) = (qp)

#define DEQUEUE(head, tail) \
	(head) = (head)->qp_next;\
	if ((head) == (struct dmc_command *) 0)\
		(tail) = (head)

E 32
dmcprobe(reg)
	caddr_t reg;
{
	register int br, cvec;
	register struct dmcdevice *addr = (struct dmcdevice *)reg;
	register int i;

I 8
D 17
COUNT(DMCPROBE);
E 17
E 8
#ifdef lint
	br = 0; cvec = br; br = cvec;
	dmcrint(0); dmcxint(0);
#endif
	addr->bsel1 = DMC_MCLR;
	for (i = 100000; i && (addr->bsel1 & DMC_RUN) == 0; i--)
		;
D 33
	if ((addr->bsel1 & DMC_RUN) == 0)
E 33
I 33
	if ((addr->bsel1 & DMC_RUN) == 0) {
		printf("dmcprobe: can't start device\n" );
E 33
D 7
		return(0);
E 7
I 7
		return (0);
E 7
D 32
	addr->bsel1 &= ~DMC_MCLR;
E 32
I 32
D 33
	/* MCLR is self clearing */
E 33
I 33
	}
E 33
E 32
	addr->bsel0 = DMC_RQI|DMC_IEI;
D 33
	DELAY(100000);
E 33
I 33
	/* let's be paranoid */
	addr->bsel0 |= DMC_RQI|DMC_IEI;
	DELAY(1000000);
E 33
	addr->bsel1 = DMC_MCLR;
	for (i = 100000; i && (addr->bsel1 & DMC_RUN) == 0; i--)
		;
I 11
D 13
	br = 0x16;		/* temporary ec hack */
E 13
I 13
D 29
#ifdef ECHACK
	br = 0x16;
#endif
E 29
E 13
E 11
D 7
	return(1);
E 7
I 7
	return (1);
E 7
}

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.
 */
dmcattach(ui)
	register struct uba_device *ui;
{
	register struct dmc_softc *sc = &dmc_softc[ui->ui_unit];
I 32
D 33
	register struct dmc_command *qp;
E 33
E 32
I 7
D 27
	register struct sockaddr_in *sin;
E 27
E 7

I 8
D 17
COUNT(DMCATTACH);
E 17
E 8
	sc->sc_if.if_unit = ui->ui_unit;
	sc->sc_if.if_name = "dmc";
	sc->sc_if.if_mtu = DMCMTU;
D 27
	sc->sc_if.if_net = (ui->ui_flags & DMC_NET) >> 8;
	sc->sc_if.if_host[0] = 17;	/* random number */
D 7
	sc->sc_if.if_addr =
	    if_makeaddr(sc->sc_if.if_net, sc->sc_if.if_host[0]);
E 7
I 7
	sin = (struct sockaddr_in *)&sc->sc_if.if_addr;
D 14
	sin->sa_family = AF_INET;
E 14
I 14
	sin->sin_family = AF_INET;
E 14
	sin->sin_addr = if_makeaddr(sc->sc_if.if_net, sc->sc_if.if_host[0]);
E 27
E 7
	sc->sc_if.if_init = dmcinit;
	sc->sc_if.if_output = dmcoutput;
I 27
	sc->sc_if.if_ioctl = dmcioctl;
E 27
D 20
	sc->sc_if.if_ubareset = dmcreset;
E 20
I 20
	sc->sc_if.if_reset = dmcreset;
I 45
	sc->sc_if.if_watchdog = dmctimeout;
E 45
E 20
I 3
D 12
	sc->sc_ifuba.ifuba_flags = UBA_NEEDBDP;
E 12
I 12
D 14
	sc->sc_ifuba.ifuba_flags = UBA_NEEDBDP | UBA_CANTWAIT;
E 14
I 14
D 32
	/* DON'T KNOW IF THIS WILL WORK WITH A BDP AT HIGH SPEEDS */
	sc->sc_ifuba.ifu_flags = UBA_NEEDBDP | UBA_CANTWAIT;
E 32
I 32
	sc->sc_if.if_flags = IFF_POINTOPOINT;
D 36
	sc->sc_ifuba.ifu_flags = UBA_CANTWAIT;
E 36
I 36
	sc->sc_ifuba.iff_flags = UBA_CANTWAIT;
E 36

D 33
	/* set up command queues */
	sc->sc_qfreeh = sc->sc_qfreet =
		sc->sc_qhead = sc->sc_qtail = sc->sc_qactive =
		(struct dmc_command *) 0;
	/* set up free command buffer list */
	for (qp = &sc->sc_cmdbuf[0]; qp < &sc->sc_cmdbuf[NTOT+2]; qp++ ) {
		QUEUE_AT_HEAD( qp, sc->sc_qfreeh, sc->sc_qfreet);
	}
E 33
E 32
E 14
E 12
E 3
D 36
	if_attach(&sc->sc_if);
E 36
I 33
D 45
	if (dmctimer == 0) {
		dmctimer = 1;
		timeout(dmcwatch, (caddr_t) 0, hz);
	}
E 45
I 36
	if_attach(&sc->sc_if);
E 36
E 33
}

/*
 * Reset of interface after UNIBUS reset.
D 34
 * If interface is on specified UBA, reset it's state.
E 34
I 34
 * If interface is on specified UBA, reset its state.
E 34
 */
dmcreset(unit, uban)
	int unit, uban;
{
	register struct uba_device *ui;
I 32
	register struct dmc_softc *sc = &dmc_softc[unit];
E 32

I 8
D 17
COUNT(DMCRESET);
E 17
E 8
	if (unit >= NDMC || (ui = dmcinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_ubanum != uban)
		return;
	printf(" dmc%d", unit);
I 32
D 33
	sc->sc_flag = 0;	/* previous unibus resources no longer valid */
E 33
I 33
	sc->sc_flag = 0;
I 34
	sc->sc_if.if_flags &= ~IFF_RUNNING;
E 34
E 33
E 32
	dmcinit(unit);
}

/*
 * Initialization of interface; reinitialize UNIBUS usage.
 */
dmcinit(unit)
	int unit;
{
	register struct dmc_softc *sc = &dmc_softc[unit];
	register struct uba_device *ui = dmcinfo[unit];
	register struct dmcdevice *addr;
I 27
	register struct ifnet *ifp = &sc->sc_if;
D 32
	struct sockaddr_in *sin;
E 32
I 32
	register struct ifrw *ifrw;
	register struct ifxmt *ifxp;
	register struct dmcbufs *rp;
I 33
	register struct dmc_command *qp;
I 34
	struct ifaddr *ifa;
E 34
E 33
E 32
E 27
	int base;
I 32
D 34
	struct sockaddr_in *sin;
E 34
I 33
	int s;
E 33
E 32

I 8
D 17
COUNT(DMCINIT);
E 17
E 8
D 33
	printd("dmcinit\n");
E 33
D 27
	if ((sc->sc_flag&DMCBMAPPED) == 0) {
		sc->sc_ubinfo = uballoc(ui->ui_ubanum,
		    (caddr_t)&dmc_base[unit], sizeof (struct dmc_base), 0);
		sc->sc_flag |= DMCBMAPPED;
	}
	if (if_ubainit(&sc->sc_ifuba, ui->ui_ubanum, 0,
D 2
	    (int)btop(DMCMTU)) == 0) {
E 2
I 2
	    (int)btoc(DMCMTU)) == 0) {
E 2
		printf("dmc%d: can't initialize\n", unit);
I 7
		sc->sc_if.if_flags &= ~IFF_UP;
E 27
I 27
D 32
	sin = (struct sockaddr_in *)&ifp->if_addr;
	if (sin->sin_addr.s_addr == 0)
E 32
I 32
	addr = (struct dmcdevice *)ui->ui_addr;

D 34
	sin = (struct sockaddr_in *) &ifp->if_addr;
	if (sin->sin_addr.s_addr == 0)	/* if address still unknown */
E 34
I 34
	/*
	 * Check to see that an address has been set
	 * (both local and destination for an address family).
	 */
	for (ifa = ifp->if_addrlist; ifa; ifa = ifa->ifa_next)
		if (ifa->ifa_addr.sa_family && ifa->ifa_dstaddr.sa_family)
			break;
	if (ifa == (struct ifaddr *) 0)
E 34
E 32
E 27
E 7
		return;
I 27
D 32
	if ((ifp->if_flags & IFF_RUNNING) == 0) {
		if ((sc->sc_flag&DMCBMAPPED) == 0) {
			sc->sc_ubinfo = uballoc(ui->ui_ubanum,
			    (caddr_t)&dmc_base[unit],
			    sizeof (struct dmc_base), 0);
			sc->sc_flag |= DMCBMAPPED;
		}
		if (if_ubainit(&sc->sc_ifuba, ui->ui_ubanum, 0,
		    (int)btoc(DMCMTU)) == 0) {
E 32
I 32
D 34
	sin = (struct sockaddr_in *) &ifp->if_dstaddr;
	if (sin->sin_addr.s_addr == 0)	/* if address still unknown */
		return;
E 34

	if ((addr->bsel1&DMC_RUN) == 0) {
		printf("dmcinit: DMC not running\n");
D 34
		ifp->if_flags &= ~(IFF_RUNNING|IFF_UP);
E 34
I 34
		ifp->if_flags &= ~IFF_UP;
E 34
		return;
	}
	/* map base table */
D 33
	if ((sc->sc_flag&DMC_BMAPPED) == 0) {
E 33
I 33
	if ((sc->sc_flag & DMC_BMAPPED) == 0) {
E 33
		sc->sc_ubinfo = uballoc(ui->ui_ubanum,
			(caddr_t)&dmc_base[unit], sizeof (struct dmc_base), 0);
		sc->sc_flag |= DMC_BMAPPED;
	}
	/* initialize UNIBUS resources */
	sc->sc_iused = sc->sc_oused = 0;
D 33
	if ((sc->sc_flag&DMC_ALLOC) == 0) {
		if (dmc_ubainit(&sc->sc_ifuba, ui->ui_ubanum, 0,
				(int)btoc(DMCMTU)) == 0) {
E 33
I 33
D 34
	if ((sc->sc_flag & DMC_ALLOC) == 0) {
E 34
I 34
	if ((ifp->if_flags & IFF_RUNNING) == 0) {
E 34
D 36
		if (dmc_ubainit(&sc->sc_ifuba, ui->ui_ubanum,
		    sizeof(struct dmc_header), (int)btoc(DMCMTU)) == 0) {
E 36
I 36
		if (if_ubaminit(&sc->sc_ifuba, ui->ui_ubanum,
		    sizeof(struct dmc_header), (int)btoc(DMCMTU),
		    sc->sc_ifr, NRCV, sc->sc_ifw, NXMT) == 0) {
E 36
E 33
E 32
D 34
			printf("dmc%d: can't initialize\n", unit);
E 34
I 34
			printf("dmc%d: can't allocate uba resources\n", unit);
E 34
			ifp->if_flags &= ~IFF_UP;
			return;
		}
D 32
		addr = (struct dmcdevice *)ui->ui_addr;
		addr->bsel2 |= DMC_IEO;
		base = sc->sc_ubinfo & 0x3ffff;
		printd("  base 0x%x\n", base);
		dmcload(sc, DMC_BASEI, base, (base>>2)&DMC_XMEM);
		dmcload(sc, DMC_CNTLI, 0, DMC_USEMAINT ? DMC_MAINT : 0);
		base = sc->sc_ifuba.ifu_r.ifrw_info & 0x3ffff;
		dmcload(sc, DMC_READ, base, ((base>>2)&DMC_XMEM)|DMCMTU);
		printd("  first read queued, addr 0x%x\n", base);
		ifp->if_flags |= IFF_UP|IFF_RUNNING;
E 32
I 32
D 34
		sc->sc_flag |= DMC_ALLOC;
E 34
I 34
		ifp->if_flags |= IFF_RUNNING;
E 34
E 32
E 27
	}
I 45
	sc->sc_flag &= ~DMC_ONLINE;
E 45
I 42
	sc->sc_flag |= DMC_RUNNING;
I 45
	/*
	 * Limit packets enqueued until we see if we're on the air.
	 */
	ifp->if_snd.ifq_maxlen = 3;
E 45
E 42
D 27
	addr = (struct dmcdevice *)ui->ui_addr;
	addr->bsel2 |= DMC_IEO;
	base = sc->sc_ubinfo & 0x3ffff;
	printd("  base 0x%x\n", base);
	dmcload(sc, DMC_BASEI, base, (base>>2)&DMC_XMEM);
D 23
	dmcload(sc, DMC_CNTLI, 0, 0);
E 23
I 23
	dmcload(sc, DMC_CNTLI, 0, DMC_USEMAINT ? DMC_MAINT : 0);
E 23
	base = sc->sc_ifuba.ifu_r.ifrw_info & 0x3ffff;
	dmcload(sc, DMC_READ, base, ((base>>2)&DMC_XMEM)|DMCMTU);
	printd("  first read queued, addr 0x%x\n", base);
I 7
	sc->sc_if.if_flags |= IFF_UP;
E 27
I 8
D 32
	/* set up routing table entry */
D 27
	if ((sc->sc_if.if_flags & IFF_ROUTE) == 0) {
D 15
		rtinit(&sc->sc_if.if_addr, &sc->sc_if.if_addr,
D 9
			RTF_DIRECT|RTF_UP);
E 9
I 9
			RTF_DIRECT|RTF_HOST|RTF_UP);
E 15
I 15
		rtinit(&sc->sc_if.if_addr, &sc->sc_if.if_addr, RTF_HOST|RTF_UP);
E 15
E 9
		sc->sc_if.if_flags |= IFF_ROUTE;
E 27
I 27
	if ((ifp->if_flags & IFF_ROUTE) == 0) {
D 29
		rtinit(sin, sin, RTF_HOST|RTF_UP);
E 29
I 29
		rtinit((struct sockaddr *)sin, (struct sockaddr *)sin,
		    RTF_HOST|RTF_UP);
E 29
		ifp->if_flags |= IFF_ROUTE;
E 32
I 32

	/* initialize buffer pool */
D 33
	/* recieves */
E 33
I 33
	/* receives */
E 33
D 36
	ifrw = &sc->sc_ifuba.ifu_r[0];
E 36
I 36
	ifrw = &sc->sc_ifr[0];
E 36
	for (rp = &sc->sc_rbufs[0]; rp < &sc->sc_rbufs[NRCV]; rp++) {
D 48
		rp->ubinfo = ifrw->ifrw_info & 0x3ffff;
E 48
I 48
		rp->ubinfo = UBAI_ADDR(ifrw->ifrw_info);
E 48
D 33
		rp->cc = DMCMTU;
E 33
I 33
		rp->cc = DMCMTU + sizeof (struct dmc_header);
E 33
		rp->flags = DBUF_OURS|DBUF_RCV;
D 33
		printd("rcv: 0x%x\n",rp->ubinfo);
E 33
		ifrw++; 
	}
	/* transmits */
D 36
	ifxp = &sc->sc_ifuba.ifu_w[0];
E 36
I 36
	ifxp = &sc->sc_ifw[0];
E 36
	for (rp = &sc->sc_xbufs[0]; rp < &sc->sc_xbufs[NXMT]; rp++) {
D 36
		rp->ubinfo = ifxp->x_ifrw.ifrw_info & 0x3ffff;
E 36
I 36
D 48
		rp->ubinfo = ifxp->ifw_info & 0x3ffff;
E 48
I 48
		rp->ubinfo = UBAI_ADDR(ifxp->ifw_info);
E 48
E 36
		rp->cc = 0;
		rp->flags = DBUF_OURS|DBUF_XMIT;
D 33
		printd("xmit: 0x%x\n",rp->ubinfo);
E 33
		ifxp++; 
	}
I 33

	/* set up command queues */
	sc->sc_qfreeh = sc->sc_qfreet
		 = sc->sc_qhead = sc->sc_qtail = sc->sc_qactive =
		(struct dmc_command *)0;
	/* set up free command buffer list */
	for (qp = &sc->sc_cmdbuf[0]; qp < &sc->sc_cmdbuf[NCMDS]; qp++) {
		QUEUE_AT_HEAD(qp, sc->sc_qfreeh, sc->sc_qfreet);
	}

E 33
	/* base in */
D 48
	base = sc->sc_ubinfo & 0x3ffff;
D 33
	printd("  base 0x%x\n", base);
	dmcload(sc, DMC_BASEI, base, (base>>2)&DMC_XMEM);
E 33
I 33
	dmcload(sc, DMC_BASEI, base, (base>>2) & DMC_XMEM);
E 48
I 48
	base = UBAI_ADDR(sc->sc_ubinfo);
	dmcload(sc, DMC_BASEI, (u_short)base, (base>>2) & DMC_XMEM);
E 48
E 33
	/* specify half duplex operation, flags tell if primary */
	/* or secondary station */
	if (ui->ui_flags == 0)
D 33
		       /* use DDMCP mode in full duplex */
			dmcload(sc, DMC_CNTLI, 0, 0);
E 33
I 33
D 42
		/* use DDMCP mode in full duplex */
E 42
I 42
		/* use DDCMP mode in full duplex */
E 42
		dmcload(sc, DMC_CNTLI, 0, 0);
E 33
	else if (ui->ui_flags == 1)
D 33
		       /* use MAINTENENCE mode */
		       dmcload(sc, DMC_CNTLI, 0, DMC_MAINT );
E 33
I 33
		/* use MAINTENENCE mode */
		dmcload(sc, DMC_CNTLI, 0, DMC_MAINT );
E 33
	else if (ui->ui_flags == 2)
		/* use DDCMP half duplex as primary station */
		dmcload(sc, DMC_CNTLI, 0, DMC_HDPLX);
	else if (ui->ui_flags == 3)
		/* use DDCMP half duplex as secondary station */
		dmcload(sc, DMC_CNTLI, 0, DMC_HDPLX | DMC_SEC);
D 33
	
E 33
I 33

	/* enable operation done interrupts */
D 45
	sc->sc_flag &= ~DMC_ACTIVE;
E 45
	while ((addr->bsel2 & DMC_IEO) == 0)
		addr->bsel2 |= DMC_IEO;
	s = spl5();
E 33
	/* queue first NRCV buffers for DMC to fill */
	for (rp = &sc->sc_rbufs[0]; rp < &sc->sc_rbufs[NRCV]; rp++) {
		rp->flags |= DBUF_DMCS;
		dmcload(sc, DMC_READ, rp->ubinfo,
D 33
			(((rp->ubinfo>>2)&DMC_XMEM)|rp->cc));
E 33
I 33
			(((rp->ubinfo>>2)&DMC_XMEM) | rp->cc));
E 33
		sc->sc_iused++;
E 32
E 27
	}
I 32
D 33

	/* enable output interrupts */
	while ((addr->bsel2&DMC_IEO) == 0)
		addr->bsel2 |= DMC_IEO;
E 33
I 33
	splx(s);
E 33
D 34
	ifp->if_flags |= IFF_UP|IFF_RUNNING;
I 33

E 34
E 33
E 32
E 8
E 7
}

/*
 * Start output on interface.  Get another datagram
 * to send from the interface queue and map it to
 * the interface before starting output.
I 32
 *
 * Must be called at spl 5
E 32
 */
D 45
dmcstart(dev)
	dev_t dev;
E 45
I 45
dmcstart(unit)
	int unit;
E 45
{
D 45
	int unit = minor(dev);
E 45
D 26
	struct uba_device *ui = dmcinfo[unit];
E 26
	register struct dmc_softc *sc = &dmc_softc[unit];
D 32
	int addr, len;
E 32
	struct mbuf *m;
I 32
	register struct dmcbufs *rp;
	register int n;
E 32

I 8
D 17
COUNT(DMCSTART);
E 17
E 8
D 32
	printd("dmcstart\n");
	/*
	 * Dequeue a request and map it to the UNIBUS.
	 * If no more requests, just return.
	 */
	IF_DEQUEUE(&sc->sc_if.if_snd, m);
	if (m == 0)
E 32
I 32
D 33
	if ((sc->sc_flag & DMC_ALLOC) == 0) {
		printf("dmcstart: no unibus resources!!\n");
E 32
		return;
D 32
	len = if_wubaput(&sc->sc_ifuba, m);

E 32
I 32
	}
E 33
E 32
	/*
D 32
	 * Have request mapped to UNIBUS for transmission.
	 * Purge any stale data from this BDP and start the output.
E 32
I 32
	 * Dequeue up to NXMT requests and map them to the UNIBUS.
	 * If no more requests, or no dmc buffers available, just return.
E 32
	 */
D 3
	UBAPURGE(sc->sc_ifuba.ifu_uba, sc->sc_ifuba.ifu_w.ifrw_bdp);
E 3
I 3
D 14
	if (sc->sc_ifuba.ifuba_flags & UBA_NEEDBDP)
E 14
I 14
D 32
	if (sc->sc_ifuba.ifu_flags & UBA_NEEDBDP)
E 14
		UBAPURGE(sc->sc_ifuba.ifu_uba, sc->sc_ifuba.ifu_w.ifrw_bdp);
E 3
	addr = sc->sc_ifuba.ifu_w.ifrw_info & 0x3ffff;
	printd("  len %d, addr 0x%x, ", len, addr);
	printd("mr 0x%x\n", sc->sc_ifuba.ifu_w.ifrw_mr[0]);
	dmcload(sc, DMC_WRITE, addr, (len&DMC_CCOUNT)|((addr>>2)&DMC_XMEM));
	sc->sc_oactive = 1;
E 32
I 32
	n = 0;
	for (rp = &sc->sc_xbufs[0]; rp < &sc->sc_xbufs[NXMT]; rp++ ) {
		/* find an available buffer */
D 33
		if ((rp->flags&DBUF_DMCS) == 0){
E 33
I 33
		if ((rp->flags & DBUF_DMCS) == 0) {
E 33
			IF_DEQUEUE(&sc->sc_if.if_snd, m);
			if (m == 0)
				return;
D 33
			if ((rp->flags&DBUF_XMIT) == 0)
				printf("dmcstart: not xmit buf\n");
E 33
			/* mark it dmcs */
			rp->flags |= (DBUF_DMCS);
			/*
			 * Have request mapped to UNIBUS for transmission
			 * and start the output.
			 */
D 33
			rp->cc = (dmcput(&sc->sc_ifuba, n, m))&DMC_CCOUNT;
E 33
I 33
D 36
			rp->cc = dmcput(&sc->sc_ifuba, n, m);
E 36
I 36
			rp->cc = if_ubaput(&sc->sc_ifuba, &sc->sc_ifw[n], m);
E 36
			rp->cc &= DMC_CCOUNT;
E 33
D 45
			sc->sc_oused++;
E 45
I 45
			if (++sc->sc_oused == 1)
				sc->sc_if.if_timer = dmc_timeout;
E 45
			dmcload(sc, DMC_WRITE, rp->ubinfo, 
				rp->cc | ((rp->ubinfo>>2)&DMC_XMEM));
		}
		n++;
	}
E 32
}

/*
 * Utility routine to load the DMC device registers.
 */
dmcload(sc, type, w0, w1)
	register struct dmc_softc *sc;
D 48
	int type, w0, w1;
E 48
I 48
	int type;
	u_short w0, w1;
E 48
{
	register struct dmcdevice *addr;
D 32
	register int unit, sps, n;
E 32
I 32
	register int unit, sps;
	register struct dmc_command *qp;
E 32

I 8
D 17
COUNT(DMCLOAD);
E 17
E 8
D 32
	printd("dmcload: 0x%x 0x%x 0x%x\n", type, w0, w1);
	unit = sc - dmc_softc;
E 32
I 32
D 33
	unit = (sc - dmc_softc)/ sizeof (struct dmc_softc);
E 33
I 33
	unit = sc - dmc_softc;
E 33
E 32
	addr = (struct dmcdevice *)dmcinfo[unit]->ui_addr;
	sps = spl5();
D 32
	if ((n = sc->sc_que.c_cc) == 0)
		addr->bsel0 = type | DMC_RQI;
	else
D 4
		putc(type | DMC_RQI, &sc->sc_que);
	putw(w0, &sc->sc_que);
	putw(w1, &sc->sc_que);
E 4
I 4
		(void) putc(type | DMC_RQI, &sc->sc_que);
	(void) putw(w0, &sc->sc_que);
	(void) putw(w1, &sc->sc_que);
E 4
	if (n == 0)
E 32
I 32

	/* grab a command buffer from the free list */
	if ((qp = sc->sc_qfreeh) == (struct dmc_command *)0)
		panic("dmc command queue overflow");
	DEQUEUE(sc->sc_qfreeh, sc->sc_qfreet);

	/* fill in requested info */
	qp->qp_cmd = (type | DMC_RQI);
	qp->qp_ubaddr = w0;
	qp->qp_cc = w1;
	
	if (sc->sc_qactive) {	/* command in progress */
		if (type == DMC_READ) {
			QUEUE_AT_HEAD(qp, sc->sc_qhead, sc->sc_qtail);
		} else {
			QUEUE_AT_TAIL(qp, sc->sc_qhead, sc->sc_qtail);
		}
	} else {	/* command port free */
		sc->sc_qactive = qp;
		addr->bsel0 = qp->qp_cmd;
E 32
		dmcrint(unit);
I 32
	}
E 32
	splx(sps);
}

/*
 * DMC interface receiver interrupt.
 * Ready to accept another command,
 * pull one off the command queue.
 */
dmcrint(unit)
	int unit;
{
	register struct dmc_softc *sc;
	register struct dmcdevice *addr;
I 32
	register struct dmc_command *qp;
E 32
	register int n;
D 14
	int w0, w1; /* DEBUG */
E 14

I 8
D 17
COUNT(DMCRINT);
E 17
E 8
	addr = (struct dmcdevice *)dmcinfo[unit]->ui_addr;
	sc = &dmc_softc[unit];
I 32
	if ((qp = sc->sc_qactive) == (struct dmc_command *) 0) {
D 33
		printf("dmcrint: no command\n");
E 33
I 33
		printf("dmc%d: dmcrint no command\n", unit);
E 33
		return;
	}
E 32
	while (addr->bsel0&DMC_RDYI) {
D 14
		w0 = getw(&sc->sc_que); /* DEBUG */
		addr->sel4 = w0; /* DEBUG */
		w1 = getw(&sc->sc_que); /* DEBUG */
		addr->sel6 = w1; /* DEBUG */
		/* DEBUG
E 14
D 32
		addr->sel4 = getw(&sc->sc_que);
		addr->sel6 = getw(&sc->sc_que);
E 32
I 32
		addr->sel4 = qp->qp_ubaddr;
		addr->sel6 = qp->qp_cc;
E 32
D 14
		DEBUG */
E 14
		addr->bsel0 &= ~(DMC_IEI|DMC_RQI);
D 14
		printd("  w0 0x%x, w1 0x%x\n", w0, w1);
E 14
D 32
		while (addr->bsel0&DMC_RDYI)
			;
		if (sc->sc_que.c_cc == 0)
D 23
			return;
E 23
I 23
			goto out;
E 23
		addr->bsel0 = getc(&sc->sc_que);
E 32
I 32
D 33
		printd("load done, cmd 0x%x, ubaddr 0x%x, cc 0x%x\n",
			qp->qp_cmd, qp->qp_ubaddr, qp->qp_cc);
E 33
		/* free command buffer */
		QUEUE_AT_HEAD(qp, sc->sc_qfreeh, sc->sc_qfreet);
		while (addr->bsel0 & DMC_RDYI) {
			/*
			 * Can't check for RDYO here 'cause
			 * this routine isn't reentrant!
			 */
			DELAY(5);
		}
		/* move on to next command */
D 33
		if ((sc->sc_qactive = sc->sc_qhead)==(struct dmc_command *) 0) 
			/* all done */
			break;
E 33
I 33
		if ((sc->sc_qactive = sc->sc_qhead) == (struct dmc_command *)0)
			break;		/* all done */
E 33
		/* more commands to do, start the next one */
		qp = sc->sc_qactive;
		DEQUEUE(sc->sc_qhead, sc->sc_qtail);
		addr->bsel0 = qp->qp_cmd;
E 32
		n = RDYSCAN;
D 33
		while (n-- && (addr->bsel0&DMC_RDYI) == 0)
D 32
			;
E 32
I 32
			DELAY(5);
E 33
I 33
		while (n-- > 0)
			if ((addr->bsel0&DMC_RDYI) || (addr->bsel2&DMC_RDYO))
				break;
E 33
E 32
	}
D 32
	if (sc->sc_que.c_cc)
		addr->bsel0 |= DMC_IEI;
I 23
out:
D 25
	dmxint(unit);
E 25
I 25
	dmcxint(unit);
E 32
I 32
	if (sc->sc_qactive) {
		addr->bsel0 |= DMC_IEI|DMC_RQI;
		/* VMS does it twice !*$%@# */
		addr->bsel0 |= DMC_IEI|DMC_RQI;
	}
I 33

E 33
E 32
E 25
E 23
}

/*
 * DMC interface transmitter interrupt.
D 32
 * A transfer has completed, check for errors.
E 32
I 32
 * A transfer may have completed, check for errors.
E 32
 * If it was a read, notify appropriate protocol.
 * If it was a write, pull the next one off the queue.
 */
dmcxint(unit)
	int unit;
{
	register struct dmc_softc *sc;
I 28
	register struct ifnet *ifp;
E 28
	struct uba_device *ui = dmcinfo[unit];
	struct dmcdevice *addr;
	struct mbuf *m;
D 33
	register struct ifqueue *inq;
E 33
I 33
	struct ifqueue *inq;
E 33
D 23
	int arg, cmd, len;
E 23
I 23
D 29
	int arg, arg2, cmd, len;
E 29
I 29
D 32
	int arg, cmd, len;
E 32
I 32
D 42
	int arg, pkaddr, cmd, len;
E 42
I 42
	int arg, pkaddr, cmd, len, s;
E 42
	register struct ifrw *ifrw;
	register struct dmcbufs *rp;
I 33
	register struct ifxmt *ifxp;
	struct dmc_header *dh;
	int off, resid;
E 33
E 32
E 29
E 23

I 8
D 17
COUNT(DMCXINT);
E 17
E 8
	addr = (struct dmcdevice *)ui->ui_addr;
I 23
D 32
	cmd = addr->bsel2 & 0xff;
	if ((cmd & DMC_RDYO) == 0)
		return;
I 29
#ifdef notdef
E 29
	arg2 = addr->sel4;
I 29
#endif
E 29
E 23
	arg = addr->sel6;
D 23
	cmd = addr->bsel2&7;
E 23
	addr->bsel2 &= ~DMC_RDYO;
E 32
	sc = &dmc_softc[unit];
I 28
	ifp = &sc->sc_if;
E 28
D 32
	printd("dmcxint\n");
E 32
I 32

D 33
	cmd = addr->bsel2 & 0xff;
	arg = addr->sel6 & 0xffff;
	if ((cmd&DMC_RDYO) == 0)  {
		printf("dmc%d: bogus xmit intr\n", unit);
		return; 
	}
	/* reconstruct UNIBUS address of buffer returned to us */
	pkaddr = ((arg&DMC_XMEM)<<2)|(addr->sel4 & 0xffff);
	/* release port */
	addr->bsel2 &= ~DMC_RDYO;
E 32
D 23
	switch (cmd) {
E 23
I 23
	switch (cmd & 07) {
E 33
I 33
	while (addr->bsel2 & DMC_RDYO) {
E 33
E 23

D 33
	case DMC_OUR:
		/*
D 32
		 * A read has completed.  Purge input buffered
		 * data path.  Pass packet to type specific
E 32
I 32
		 * A read has completed.  
		 * Pass packet to type specific
E 32
		 * higher-level input routine.
		 */
D 28
		sc->sc_if.if_ipackets++;
E 28
I 28
		ifp->if_ipackets++;
E 28
D 3
		UBAPURGE(sc->sc_ifuba.ifu_uba, sc->sc_ifuba.ifu_r.ifrw_bdp);
E 3
I 3
D 14
		if (sc->sc_ifuba.ifuba_flags & UBA_NEEDBDP)
E 14
I 14
D 32
		if (sc->sc_ifuba.ifu_flags & UBA_NEEDBDP)
E 14
			UBAPURGE(sc->sc_ifuba.ifu_uba,
				sc->sc_ifuba.ifu_r.ifrw_bdp);
E 32
E 3
		len = arg & DMC_CCOUNT;
D 32
		printd("  read done, len %d\n", len);
E 32
I 32
		/* find location in dmcuba struct */
		ifrw = &sc->sc_ifuba.ifu_r[0];
		rp = &sc->sc_rbufs[0];
		for (; rp < &sc->sc_rbufs[NRCV]; rp++) {
			if (rp->ubinfo == pkaddr)
				goto foundrcv;
			ifrw++;
		}
		printf("bad rcv pkt addr 0x%x len 0x%x\n", pkaddr, len);
		goto setup;
		
	foundrcv:
		if ((rp->flags&DBUF_DMCS) == 0) {
			printf("dmcxint: done unalloc rbuf\n");
		}
E 32
D 7
		switch (ui->ui_flags & DMC_PF) {
E 7
I 7
D 28
		switch (ui->ui_flags & DMC_AF) {
E 28
I 28
		switch (ifp->if_addr.sa_family) {
E 33
I 33
		cmd = addr->bsel2 & 0xff;
		arg = addr->sel6 & 0xffff;
		/* reconstruct UNIBUS address of buffer returned to us */
		pkaddr = ((arg&DMC_XMEM)<<2) | (addr->sel4 & 0xffff);
		/* release port */
		addr->bsel2 &= ~DMC_RDYO;
		switch (cmd & 07) {

		case DMC_OUR:
			/*
			 * A read has completed.  
			 * Pass packet to type specific
			 * higher-level input routine.
			 */
			ifp->if_ipackets++;
			/* find location in dmcuba struct */
D 36
			ifrw= &sc->sc_ifuba.ifu_r[0];
E 36
I 36
			ifrw= &sc->sc_ifr[0];
E 36
			for (rp = &sc->sc_rbufs[0]; rp < &sc->sc_rbufs[NRCV]; rp++) {
				if(rp->ubinfo == pkaddr)
					break;
				ifrw++;
			}
			if (rp >= &sc->sc_rbufs[NRCV])
				panic("dmc rcv");
			if ((rp->flags & DBUF_DMCS) == 0)
				printf("dmc%d: done unalloc rbuf\n", unit);

			len = (arg & DMC_CCOUNT) - sizeof (struct dmc_header);
			if (len < 0 || len > DMCMTU) {
				ifp->if_ierrors++;
				printd("dmc%d: bad rcv pkt addr 0x%x len 0x%x\n",
				    unit, pkaddr, len);
				goto setup;
			}
			/*
			 * Deal with trailer protocol: if type is trailer
			 * get true type from first 16-bit word past data.
			 * Remember that type was trailer by setting off.
			 */
			dh = (struct dmc_header *)ifrw->ifrw_addr;
			dh->dmc_type = ntohs((u_short)dh->dmc_type);
#define dmcdataaddr(dh, off, type)	((type)(((caddr_t)((dh)+1)+(off))))
			if (dh->dmc_type >= DMC_TRAILER &&
			    dh->dmc_type < DMC_TRAILER+DMC_NTRAILER) {
				off = (dh->dmc_type - DMC_TRAILER) * 512;
				if (off >= DMCMTU)
					goto setup;		/* sanity */
				dh->dmc_type = ntohs(*dmcdataaddr(dh, off, u_short *));
				resid = ntohs(*(dmcdataaddr(dh, off+2, u_short *)));
				if (off + resid > len)
					goto setup;		/* sanity */
				len = off + resid;
			} else
				off = 0;
			if (len == 0)
				goto setup;

			/*
			 * Pull packet off interface.  Off is nonzero if
			 * packet has trailing header; dmc_get will then
			 * force this header information to be at the front,
			 * but we still have to drop the type and length
			 * which are at the front of any trailer data.
			 */
D 36
			m = dmc_get(&sc->sc_ifuba, ifrw, len, off);
E 36
I 36
			m = if_ubaget(&sc->sc_ifuba, ifrw, len, off, ifp);
E 36
			if (m == 0)
				goto setup;
I 48
			if (off) {
				ifp = *(mtod(m, struct ifnet **));
				m->m_off += 2 * sizeof (u_short);
				m->m_len -= 2 * sizeof (u_short);
				*(mtod(m, struct ifnet **)) = ifp;
			}
E 48
D 47
			if (off) {
I 36
D 40
				struct ifnet *ifp;

E 40
				ifp = *(mtod(m, struct ifnet **));
E 36
				m->m_off += 2 * sizeof (u_short);
				m->m_len -= 2 * sizeof (u_short);
I 36
				*(mtod(m, struct ifnet **)) = ifp;
E 36
			}
E 47
			switch (dh->dmc_type) {

E 33
E 28
E 7
#ifdef INET
D 7
		case PF_INET:
E 7
I 7
D 33
		case AF_INET:
E 7
D 6
			setipintr();
E 6
I 6
			schednetisr(NETISR_IP);
E 6
			inq = &ipintrq;
			break;
E 33
I 33
			case DMC_IPTYPE:
				schednetisr(NETISR_IP);
				inq = &ipintrq;
				break;
E 33
#endif
I 33
			default:
				m_freem(m);
				goto setup;
			}
E 33

I 42
			s = splimp();
E 42
D 33
		default:
D 7
			printf("dmc%d: unknown packet type %d\n", unit,
			    ui->ui_flags & DMC_NET);
E 7
I 7
			printf("dmc%d: unknown address type %d\n", unit,
D 28
			    ui->ui_flags & DMC_AF);
E 28
I 28
			    ifp->if_addr.sa_family);
E 28
E 7
			goto setup;
		}
E 33
I 33
			if (IF_QFULL(inq)) {
				IF_DROP(inq);
				m_freem(m);
			} else
				IF_ENQUEUE(inq, m);
I 42
			splx(s);
E 42
E 33
D 32
		m = if_rubaget(&sc->sc_ifuba, len, 0);
		if (m == 0)
E 32
I 32

D 33
		m = dmc_get(&sc->sc_ifuba, ifrw, len, 0);
		if (m == (struct mbuf *)0)
E 32
			goto setup;
D 5
		IF_ENQUEUE(inq, m);
E 5
I 5
		if (IF_QFULL(inq)) {
			IF_DROP(inq);
D 21
			(void) m_freem(m);
E 21
I 21
			m_freem(m);
E 21
		} else
			IF_ENQUEUE(inq, m);
E 5
D 32

E 32
setup:
D 32
		arg = sc->sc_ifuba.ifu_r.ifrw_info & 0x3ffff;
E 32
I 32
		arg = ifrw->ifrw_info & 0x3ffff;
E 32
		dmcload(sc, DMC_READ, arg, ((arg >> 2) & DMC_XMEM) | DMCMTU);
D 32
		return;
E 32
I 32
		break;
E 33
I 33
	setup:
			/* is this needed? */
D 48
			rp->ubinfo = ifrw->ifrw_info & 0x3ffff;
E 48
I 48
			rp->ubinfo = UBAI_ADDR(ifrw->ifrw_info);
E 48
E 33
E 32

D 33
	case DMC_OUX:
		/*
		 * A write has completed, start another
		 * transfer if there is more data to send.
		 */
D 32
		if (sc->sc_oactive == 0)
			return;		/* SHOULD IT BE A FATAL ERROR? */
		printd("  write done\n");
E 32
D 28
		sc->sc_if.if_opackets++;
E 28
I 28
		ifp->if_opackets++;
E 28
D 32
		sc->sc_oactive = 0;
		if (sc->sc_ifuba.ifu_xtofree) {
D 5
			m_freem(sc->sc_ifuba.ifu_xtofree);
E 5
I 5
D 21
			(void) m_freem(sc->sc_ifuba.ifu_xtofree);
E 21
I 21
			m_freem(sc->sc_ifuba.ifu_xtofree);
E 21
E 5
			sc->sc_ifuba.ifu_xtofree = 0;
E 32
I 32
		printd("OUX pkaddr 0x%x\n",pkaddr);
		/* find associated dmcbuf structure */
		rp = &sc->sc_xbufs[0];
		for (; rp < &sc->sc_xbufs[NXMT]; rp++) {
			if (rp->ubinfo == pkaddr)
				goto found;
E 32
		}
D 28
		if (sc->sc_if.if_snd.ifq_head == 0)
E 28
I 28
D 32
		if (ifp->if_snd.ifq_head == 0)
E 28
			return;
E 32
I 32
		printf("dmc%d: bad packet address 0x%x\n",
			unit, pkaddr);
		break;
	found:
		if ((rp->flags&DBUF_DMCS) == 0)
			printf("dmc returned unallocated packet 0x%x\n",
				pkaddr);
		/* mark buffer free */
		rp->flags &= ~(DBUF_DMCS);
		sc->sc_oused--;
E 32
		dmcstart(unit);
D 32
		return;
E 32
I 32
		break;
E 33
I 33
			dmcload(sc, DMC_READ, rp->ubinfo, 
			    ((rp->ubinfo >> 2) & DMC_XMEM) | rp->cc);
			break;
E 33
E 32

D 33
	case DMC_CNTLO:
		arg &= DMC_CNTMASK;
		if (arg&DMC_FATAL) {
I 32
			register int i;

			printf("dmc%d: fatal error, flags=%b\n",
			    unit, arg, CNTLO_BITS);
			ifp->if_flags &= ~(IFF_RUNNING|IFF_UP);
			/* master clear device */
E 32
			addr->bsel1 = DMC_MCLR;
D 32
			sc->sc_flag &= ~DMCRUN;
			/*** DO SOMETHING TO RESTART DEVICE ***/
			printf("DMC FATAL ERROR 0%o\n", arg);
E 32
I 32
			for (i = 100000; i && (addr->bsel1 & DMC_RUN) == 0; i--)
				;
			dmcinit(unit);
			ifp->if_ierrors++;
E 33
I 33
		case DMC_OUX:
			/*
			 * A write has completed, start another
			 * transfer if there is more data to send.
			 */
			ifp->if_opackets++;
			/* find associated dmcbuf structure */
D 36
			ifxp = &sc->sc_ifuba.ifu_w[0];
E 36
I 36
			ifxp = &sc->sc_ifw[0];
E 36
			for (rp = &sc->sc_xbufs[0]; rp < &sc->sc_xbufs[NXMT]; rp++) {
				if(rp->ubinfo == pkaddr)
					break;
				ifxp++;
			}
			if (rp >= &sc->sc_xbufs[NXMT]) {
				printf("dmc%d: bad packet address 0x%x\n",
				    unit, pkaddr);
				break;
			}
			if ((rp->flags & DBUF_DMCS) == 0)
				printf("dmc%d: unallocated packet 0x%x\n",
				    unit, pkaddr);
			/* mark buffer free */
D 36
			if (ifxp->x_xtofree) {
				(void)m_freem(ifxp->x_xtofree);
				ifxp->x_xtofree = 0;
E 36
I 36
			if (ifxp->ifw_xtofree) {
				(void)m_freem(ifxp->ifw_xtofree);
				ifxp->ifw_xtofree = 0;
E 36
			}
			rp->flags &= ~DBUF_DMCS;
D 45
			sc->sc_oused--;
			sc->sc_nticks = 0;
			sc->sc_flag |= DMC_ACTIVE;
E 45
I 45
			if (--sc->sc_oused == 0)
				sc->sc_if.if_timer = 0;
			else
				sc->sc_if.if_timer = dmc_timeout;
			if ((sc->sc_flag & DMC_ONLINE) == 0) {
				extern int ifqmaxlen;

				/*
				 * We're on the air.
				 * Open the queue to the usual value.
				 */
				sc->sc_flag |= DMC_ONLINE;
				ifp->if_snd.ifq_maxlen = ifqmaxlen;
			}
E 45
E 33
			break;
E 32
D 33
		} else {
D 32
			/* ACCUMULATE STATISTICS */
			printf("DMC SOFT ERROR 0%o\n", arg);
E 32
I 32
                        /* ACCUMULATE STATISTICS */
E 33
I 33

		case DMC_CNTLO:
			arg &= DMC_CNTMASK;
			if (arg & DMC_FATAL) {
D 40
				printd("dmc%d: fatal error, flags=%b\n",
E 40
I 40
D 45
				log(LOG_ERR, "dmc%d: fatal error, flags=%b\n",
E 40
				    unit, arg, CNTLO_BITS);
E 45
I 45
				if (arg != DMC_START)
					log(LOG_ERR,
					    "dmc%d: fatal error, flags=%b\n",
					    unit, arg, CNTLO_BITS);
E 45
D 34
				ifp->if_flags &= ~(IFF_RUNNING|IFF_UP);
E 34
				dmcrestart(unit);
				break;
			}
			/* ACCUMULATE STATISTICS */
E 33
			switch(arg) {
			case DMC_NOBUFS:
D 33
                        	ifp->if_ierrors++;
				if((sc->sc_nobuf++ % DMC_RPNBFS) != 0)
					break;
				goto report;
E 33
I 33
				ifp->if_ierrors++;
				if ((sc->sc_nobuf++ % DMC_RPNBFS) == 0)
					goto report;
				break;
E 33
			case DMC_DISCONN:
D 33
				if((sc->sc_disc++ % DMC_RPDSC) != 0)
					break;
				goto report;
E 33
I 33
				if ((sc->sc_disc++ % DMC_RPDSC) == 0)
					goto report;
				break;
E 33
			case DMC_TIMEOUT:
D 33
				if((sc->sc_timeo++ % DMC_RPTMO) != 0)
					break;
				goto report;
E 33
I 33
				if ((sc->sc_timeo++ % DMC_RPTMO) == 0)
					goto report;
				break;
E 33
			case DMC_DATACK:
D 33
                        	ifp->if_oerrors++;
				if((sc->sc_datck++ % DMC_RPDCK) != 0)
					break;
				goto report;
E 33
I 33
				ifp->if_oerrors++;
				if ((sc->sc_datck++ % DMC_RPDCK) == 0)
					goto report;
				break;
E 33
			default:
				goto report;
			}
			break;
		report:
D 33
                        printf("dmc%d: soft error, flags=%b\n",
                            unit, arg, CNTLO_BITS);
E 32
		}
D 32
		return;
E 32
I 32
		break;
E 33
I 33
			printd("dmc%d: soft error, flags=%b\n", unit,
			    arg, CNTLO_BITS);
			if ((sc->sc_flag & DMC_RESTART) == 0) {
				/*
				 * kill off the dmc to get things
				 * going again by generating a
				 * procedure error
				 */
				sc->sc_flag |= DMC_RESTART;
D 48
				arg = sc->sc_ubinfo & 0x3ffff;
E 48
I 48
				arg = UBAI_ADDR(sc->sc_ubinfo);
E 48
				dmcload(sc, DMC_BASEI, arg, (arg>>2)&DMC_XMEM);
			}
			break;
E 33
E 32

D 33
	default:
		printf("dmc%d: bad control %o\n", unit, cmd);
E 33
I 33
		default:
			printf("dmc%d: bad control %o\n", unit, cmd);
			break;
		}
E 33
	}
I 33
	dmcstart(unit);
E 33
I 32
	return;
E 32
}

/*
 * DMC output routine.
D 33
 * Just send the data, header was supplied by
 * upper level protocol routines.
E 33
I 33
 * Encapsulate a packet of type family for the dmc.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
E 33
 */
D 7
dmcoutput(ifp, m, pf)
E 7
I 7
D 33
dmcoutput(ifp, m, dst)
E 33
I 33
dmcoutput(ifp, m0, dst)
E 33
E 7
	register struct ifnet *ifp;
D 33
	register struct mbuf *m;
E 33
I 33
	register struct mbuf *m0;
E 33
D 7
	int pf;
E 7
I 7
	struct sockaddr *dst;
E 7
{
D 29
	struct uba_device *ui = dmcinfo[ifp->if_unit];
E 29
D 33
	int s;
E 33
I 33
	int type, error, s;
	register struct mbuf *m = m0;
	register struct dmc_header *dh;
	register int off;
E 33

I 45
D 49
	if ((ifp->if_flags & IFF_UP) == 0) {
E 49
I 49
	if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) != (IFF_UP|IFF_RUNNING)) {
E 49
		error = ENETDOWN;
		goto bad;
	}

E 45
I 8
D 17
COUNT(DMCOUTPUT);
E 17
E 8
D 32
	printd("dmcoutput\n");
E 32
D 7
	if (pf != (ui->ui_flags & DMC_PF)) {
		printf("dmc%d: protocol %d not supported\n", ifp->if_unit, pf);
D 5
		m_freem(m);
E 5
I 5
		(void) m_freem(m);
E 7
I 7
D 28
	if (dst->sa_family != (ui->ui_flags & DMC_AF)) {
E 28
I 28
D 33
	if (dst->sa_family != ifp->if_addr.sa_family) {
E 28
D 21
		printf("dmc%d: af%d not supported\n", ifp->if_unit, pf);
E 21
I 21
		printf("dmc%d: af%d not supported\n", ifp->if_unit,
D 28
			dst->sa_family);
E 28
I 28
		    dst->sa_family);
E 28
E 21
		m_freem(m);
E 7
E 5
D 10
		return (0);
E 10
I 10
		return (EAFNOSUPPORT);
E 33
I 33
	switch (dst->sa_family) {
#ifdef	INET
	case AF_INET:
D 47
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
E 47
I 47
D 48
		off = m->m_pkthdr.len - m->m_len;
E 48
I 48
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
E 48
E 47
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
		if (off > 0 && (off & 0x1ff) == 0 &&
D 47
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
E 47
I 47
D 48
		    (m->m_flags & M_EXT) == 0 &&
		    m->m_data >= m->m_pktdat + 2 * sizeof (u_short)) {
E 48
I 48
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
E 48
E 47
			type = DMC_TRAILER + (off>>9);
D 47
			m->m_off -= 2 * sizeof (u_short);
E 47
I 47
D 48
			m->m_data -= 2 * sizeof (u_short);
E 48
I 48
			m->m_off -= 2 * sizeof (u_short);
E 48
E 47
			m->m_len += 2 * sizeof (u_short);
			*mtod(m, u_short *) = htons((u_short)DMC_IPTYPE);
			*(mtod(m, u_short *) + 1) = htons((u_short)m->m_len);
			goto gottrailertype;
		}
		type = DMC_IPTYPE;
		off = 0;
		goto gottype;
#endif

	case AF_UNSPEC:
		dh = (struct dmc_header *)dst->sa_data;
		type = dh->dmc_type;
		goto gottype;

	default:
		printf("dmc%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
		error = EAFNOSUPPORT;
		goto bad;
E 33
E 10
	}
D 32
	s = splimp();
E 32
I 32
D 33
	s = spl5();
E 33
I 33

gottrailertype:
	/*
	 * Packet to be sent as a trailer; move first packet
	 * (control information) to end of chain.
	 */
	while (m->m_next)
		m = m->m_next;
	m->m_next = m0;
	m = m0->m_next;
	m0->m_next = 0;
	m0 = m;

gottype:
	/*
	 * Add local network header
	 * (there is space for a uba on a vax to step on)
	 */
D 47
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof(struct dmc_header) > m->m_off) {
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			error = ENOBUFS;
			goto bad;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
		m->m_len = sizeof (struct dmc_header);
	} else {
		m->m_off -= sizeof (struct dmc_header);
		m->m_len += sizeof (struct dmc_header);
E 47
I 47
D 48
	M_PREPEND(m, sizeof(struct dmc_header), M_DONTWAIT);
	if (m == 0) {
		error = ENOBUFS;
		goto bad;
E 48
I 48
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof(struct dmc_header) > m->m_off) {
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			error = ENOBUFS;
			goto bad;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
		m->m_len = sizeof (struct dmc_header);
	} else {
		m->m_off -= sizeof (struct dmc_header);
		m->m_len += sizeof (struct dmc_header);
E 48
E 47
	}
	dh = mtod(m, struct dmc_header *);
	dh->dmc_type = htons((u_short)type);

	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
	s = splimp();
E 33
E 32
I 5
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
D 7
		(void) m_freem(m);
E 7
I 7
		m_freem(m);
E 7
		splx(s);
D 10
		return (0);
E 10
I 10
		return (ENOBUFS);
E 10
	}
E 5
	IF_ENQUEUE(&ifp->if_snd, m);
D 32
	if (dmc_softc[ifp->if_unit].sc_oactive == 0)
		dmcstart(ifp->if_unit);
E 32
I 32
	dmcstart(ifp->if_unit);
E 32
	splx(s);
D 10
	return (1);
E 10
I 10
	return (0);
I 33

bad:
	m_freem(m0);
	return (error);
E 33
I 27
}

I 33

E 33
/*
 * Process an ioctl request.
 */
I 36
/* ARGSUSED */
E 36
dmcioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 34
	struct ifreq *ifr = (struct ifreq *)data;
	struct sockaddr_in *sin;
E 34
	int s = splimp(), error = 0;
I 42
	register struct dmc_softc *sc = &dmc_softc[ifp->if_unit];
E 42

	switch (cmd) {

	case SIOCSIFADDR:
D 33
		if (ifp->if_flags & IFF_RUNNING)
D 32
			if_rtinit(ifp, -1);	/* delete previous route */
E 32
I 32
			if_rtinit(ifp, -1);     /* delete previous route */
E 33
E 32
D 34
		sin = (struct sockaddr_in *)&ifr->ifr_addr;
I 33
		if (sin->sin_family != AF_INET)
			return (EINVAL);
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
E 33
D 29
		ifp->if_addr = *sin;
E 29
I 29
		ifp->if_addr = *(struct sockaddr *)sin;
E 29
		ifp->if_net = in_netof(sin->sin_addr);
E 34
D 32
		ifp->if_host[0] = in_lnaof(sin->sin_addr);
		dmcinit(ifp->if_unit);
E 32
I 32
		ifp->if_flags |= IFF_UP;
D 34
		/* set up routing table entry */
		if ((ifp->if_flags & IFF_ROUTE) == 0) {
			rtinit(&ifp->if_dstaddr, &ifp->if_addr, RTF_HOST|RTF_UP);
			ifp->if_flags |= IFF_ROUTE;
		}
E 34
I 34
		if ((ifp->if_flags & IFF_RUNNING) == 0)
			dmcinit(ifp->if_unit); 
E 34
E 32
		break;

	case SIOCSIFDSTADDR:
D 34
		ifp->if_dstaddr = ifr->ifr_dstaddr;
E 34
I 34
		if ((ifp->if_flags & IFF_RUNNING) == 0)
			dmcinit(ifp->if_unit); 
E 34
		break;
D 32

E 32
I 32
		
I 42
	case SIOCSIFFLAGS:
		if ((ifp->if_flags & IFF_UP) == 0 &&
D 45
		    sc->sc_flag & DMC_RUNNING) {
			((struct dmcdevice *)
			   (dmcinfo[ifp->if_unit]->ui_addr))->bsel1 = DMC_MCLR;
			sc->sc_flag &= ~DMC_RUNNING;
		} else if (ifp->if_flags & IFF_UP &&
E 45
I 45
		    sc->sc_flag & DMC_RUNNING)
			dmcdown(ifp->if_unit);
		else if (ifp->if_flags & IFF_UP &&
E 45
		    (sc->sc_flag & DMC_RUNNING) == 0)
			dmcrestart(ifp->if_unit);
		break;

E 42
E 32
	default:
		error = EINVAL;
	}
I 32
D 34
	if ((ifp->if_flags & IFF_RUNNING) == 0)
		dmcinit(ifp->if_unit); 
E 34
E 32
	splx(s);
	return (error);
I 32
}

I 33
D 36

E 36
E 33
/*
D 36
 * Routines supporting UNIBUS network interfaces.
 */

/*
 * Init UNIBUS for interface on uban whose headers of size hlen are to
 * end on a page boundary.  We allocate a UNIBUS map register for the page
 * with the header, and nmr more UNIBUS map registers for i/o on the adapter,
 * doing this for each receive and transmit buffer.  We also
 * allocate page frames in the mbuffer pool for these pages.
 */
dmc_ubainit(ifu, uban, hlen, nmr)
	register struct dmcuba *ifu;
	int uban, hlen, nmr;
{
	register caddr_t cp, dp;
	register struct ifrw *ifrw;
	register struct ifxmt *ifxp;
	int i, ncl;

	ncl = clrnd(nmr + CLSIZE) / CLSIZE;
D 33
	if (ifu->ifu_r[0].ifrw_addr) {
E 33
I 33
	if (ifu->ifu_r[0].ifrw_addr)
E 33
		/*
		 * If the first read buffer has a non-zero
		 * address, it means we have already allocated core
		 */
		cp = ifu->ifu_r[0].ifrw_addr - (CLBYTES - hlen);
D 33
	} else {
E 33
I 33
	else {
E 33
		cp = m_clalloc(NTOT * ncl, MPG_SPACE);
		if (cp == 0)
			return (0);
		ifu->ifu_hlen = hlen;
		ifu->ifu_uban = uban;
		ifu->ifu_uba = uba_hd[uban].uh_uba;
		dp = cp + CLBYTES - hlen;
		for (ifrw = ifu->ifu_r; ifrw < &ifu->ifu_r[NRCV]; ifrw++) {
			ifrw->ifrw_addr = dp;
			dp += ncl * CLBYTES;
		}
		for (ifxp = ifu->ifu_w; ifxp < &ifu->ifu_w[NXMT]; ifxp++) {
			ifxp->x_ifrw.ifrw_addr = dp;
			dp += ncl * CLBYTES;
		}
	}
	/* allocate for receive ring */
	for (ifrw = ifu->ifu_r; ifrw < &ifu->ifu_r[NRCV]; ifrw++) {
		if (dmc_ubaalloc(ifu, ifrw, nmr) == 0) {
			struct ifrw *rw;

			for (rw = ifu->ifu_r; rw < ifrw; rw++)
				ubarelse(ifu->ifu_uban, &rw->ifrw_info);
			goto bad;
		}
	}
	/* and now transmit ring */
	for (ifxp = ifu->ifu_w; ifxp < &ifu->ifu_w[NXMT]; ifxp++) {
		ifrw = &ifxp->x_ifrw;
		if (dmc_ubaalloc(ifu, ifrw, nmr) == 0) {
			struct ifxmt *xp;

			for (xp = ifu->ifu_w; xp < ifxp; xp++)
				ubarelse(ifu->ifu_uban, &xp->x_ifrw.ifrw_info);
			for (ifrw = ifu->ifu_r; ifrw < &ifu->ifu_r[NRCV]; ifrw++)
				ubarelse(ifu->ifu_uban, &ifrw->ifrw_info);
			goto bad;
		}
		for (i = 0; i < nmr; i++)
			ifxp->x_map[i] = ifrw->ifrw_mr[i];
		ifxp->x_xswapd = 0;
	}
	return (1);
bad:
	m_pgfree(cp, NTOT * ncl);
	ifu->ifu_r[0].ifrw_addr = 0;
	return (0);
}

/*
 * Setup either a ifrw structure by allocating UNIBUS map registers,
 * possibly a buffered data path, and initializing the fields of
 * the ifrw structure to minimize run-time overhead.
 */
static
dmc_ubaalloc(ifu, ifrw, nmr)
	struct dmcuba *ifu;
	register struct ifrw *ifrw;
	int nmr;
{
	register int info;

	info =
	    uballoc(ifu->ifu_uban, ifrw->ifrw_addr, nmr*NBPG + ifu->ifu_hlen,
		ifu->ifu_flags);
	if (info == 0)
		return (0);
	ifrw->ifrw_info = info;
	ifrw->ifrw_bdp = UBAI_BDP(info);
	ifrw->ifrw_proto = UBAMR_MRV | (UBAI_BDP(info) << UBAMR_DPSHIFT);
	ifrw->ifrw_mr = &ifu->ifu_uba->uba_map[UBAI_MR(info) + 1];
	return (1);
}

/*
 * Pull read data off a interface.
 * Len is length of data, with local net header stripped.
 * Off is non-zero if a trailer protocol was used, and
 * gives the offset of the trailer information.
 * We copy the trailer information and then all the normal
 * data into mbufs.  When full cluster sized units are present
 * on the interface on cluster boundaries we can get them more
 * easily by remapping, and take advantage of this here.
 */
struct mbuf *
dmc_get(ifu, ifrw, totlen, off0)
	register struct dmcuba *ifu;
	register struct ifrw *ifrw;
	int totlen, off0;
{
	struct mbuf *top, **mp, *m;
	int off = off0, len;
	register caddr_t cp = ifrw->ifrw_addr + ifu->ifu_hlen;

	top = 0;
	mp = &top;
	while (totlen > 0) {
		MGET(m, M_DONTWAIT, MT_DATA);
		if (m == 0)
			goto bad;
		if (off) {
			len = totlen - off;
			cp = ifrw->ifrw_addr + ifu->ifu_hlen + off;
		} else
			len = totlen;
		if (len >= CLBYTES) {
			struct mbuf *p;
			struct pte *cpte, *ppte;
			int x, *ip, i;

			MCLGET(p, 1);
			if (p == 0)
				goto nopage;
			len = m->m_len = CLBYTES;
			m->m_off = (int)p - (int)m;
			if (!claligned(cp))
				goto copy;

			/*
			 * Switch pages mapped to UNIBUS with new page p,
			 * as quick form of copy.  Remap UNIBUS and invalidate.
			 */
			cpte = &Mbmap[mtocl(cp)*CLSIZE];
			ppte = &Mbmap[mtocl(p)*CLSIZE];
			x = btop(cp - ifrw->ifrw_addr);
			ip = (int *)&ifrw->ifrw_mr[x];
			for (i = 0; i < CLSIZE; i++) {
				struct pte t;
				t = *ppte; *ppte++ = *cpte; *cpte = t;
				*ip++ =
				    cpte++->pg_pfnum|ifrw->ifrw_proto;
				mtpr(TBIS, cp);
				cp += NBPG;
				mtpr(TBIS, (caddr_t)p);
				p += NBPG / sizeof (*p);
			}
			goto nocopy;
		}
nopage:
		m->m_len = MIN(MLEN, len);
		m->m_off = MMINOFF;
copy:
		bcopy(cp, mtod(m, caddr_t), (unsigned)m->m_len);
		cp += m->m_len;
nocopy:
		*mp = m;
		mp = &m->m_next;
		if (off) {
			/* sort of an ALGOL-W style for statement... */
			off += m->m_len;
			if (off == totlen) {
				cp = ifrw->ifrw_addr + ifu->ifu_hlen;
				off = 0;
				totlen = off0;
			}
		} else
			totlen -= m->m_len;
	}
	return (top);
bad:
	m_freem(top);
	return (0);
}

/*
 * Map a chain of mbufs onto a network interface
 * in preparation for an i/o operation.
 * The argument chain of mbufs includes the local network
 * header which is copied to be in the mapped, aligned
 * i/o space.
 */
dmcput(ifu, n, m)
	struct dmcuba *ifu;
	int n;
	register struct mbuf *m;
{
	register struct mbuf *mp;
	register caddr_t cp;
	register struct ifxmt *ifxp;
	register struct ifrw *ifrw;
	register int i;
	int xswapd = 0;
	int x, cc, t;
	caddr_t dp;

	ifxp = &ifu->ifu_w[n];
	ifrw = &ifxp->x_ifrw;
	cp = ifrw->ifrw_addr;
	while (m) {
		dp = mtod(m, char *);
		if (claligned(cp) && claligned(dp) && m->m_len == CLBYTES) {
			struct pte *pte; int *ip;
			pte = &Mbmap[mtocl(dp)*CLSIZE];
			x = btop(cp - ifrw->ifrw_addr);
			ip = (int *)&ifrw->ifrw_mr[x];
			for (i = 0; i < CLSIZE; i++)
				*ip++ = ifrw->ifrw_proto | pte++->pg_pfnum;
			xswapd |= 1 << (x>>(CLSHIFT-PGSHIFT));
			mp = m->m_next;
			m->m_next = ifxp->x_xtofree;
			ifxp->x_xtofree = m;
			cp += m->m_len;
		} else {
			bcopy(mtod(m, caddr_t), cp, (unsigned)m->m_len);
			cp += m->m_len;
			MFREE(m, mp);
		}
		m = mp;
	}

	/*
	 * Xswapd is the set of clusters we just mapped out.  Ifxp->x_xswapd
	 * is the set of clusters mapped out from before.  We compute
	 * the number of clusters involved in this operation in x.
	 * Clusters mapped out before and involved in this operation
	 * should be unmapped so original pages will be accessed by the device.
	 */
	cc = cp - ifrw->ifrw_addr;
	x = ((cc - ifu->ifu_hlen) + CLBYTES - 1) >> CLSHIFT;
	ifxp->x_xswapd &= ~xswapd;
	while (i = ffs(ifxp->x_xswapd)) {
		i--;
		if (i >= x)
			break;
		ifxp->x_xswapd &= ~(1<<i);
		i *= CLSIZE;
		for (t = 0; t < CLSIZE; t++) {
			ifrw->ifrw_mr[i] = ifxp->x_map[i];
			i++;
		}
	}
	ifxp->x_xswapd |= xswapd;
	return (cc);
I 33
}

/*
E 36
 * Restart after a fatal error.
 * Clear device and reinitialize.
 */
dmcrestart(unit)
	int unit;
{
	register struct dmc_softc *sc = &dmc_softc[unit];
D 45
	register struct uba_device *ui = dmcinfo[unit];
E 45
	register struct dmcdevice *addr;
D 45
	register struct ifxmt *ifxp;
E 45
	register int i;
I 45
	int s;
E 45
D 36
	register struct mbuf *m;
	struct dmcuba *ifu;
E 36
I 36
D 40
	struct ifubinfo *ifu;
E 40
E 36
	
D 45
	addr = (struct dmcdevice *)ui->ui_addr;
E 45
D 40
	ifu = &sc->sc_ifuba;
E 40
#ifdef DEBUG
	/* dump base table */
	printf("dmc%d base table:\n", unit);
	for (i = 0; i < sizeof (struct dmc_base); i++)
		printf("%o\n" ,dmc_base[unit].d_base[i]);
#endif
I 45

	dmcdown(unit);

E 45
	/*
	 * Let the DMR finish the MCLR.	 At 1 Mbit, it should do so
	 * in about a max of 6.4 milliseconds with diagnostics enabled.
	 */
D 45
	addr->bsel1 = DMC_MCLR;
E 45
I 45
	addr = (struct dmcdevice *)(dmcinfo[unit]->ui_addr);
E 45
	for (i = 100000; i && (addr->bsel1 & DMC_RUN) == 0; i--)
		;
	/* Did the timer expire or did the DMR finish? */
	if ((addr->bsel1 & DMC_RUN) == 0) {
D 40
		printf("dmc%d: M820 Test Failed\n", unit);
E 40
I 40
		log(LOG_ERR, "dmc%d: M820 Test Failed\n", unit);
E 40
		return;
	}

I 45
	/* restart DMC */
	dmcinit(unit);
	sc->sc_flag &= ~DMC_RESTART;
	s = spl5();
	dmcstart(unit);
	splx(s);
	sc->sc_if.if_collisions++;	/* why not? */
}

/*
 * Reset a device and mark down.
 * Flush output queue and drop queue limit.
 */
dmcdown(unit)
	int unit;
{
	register struct dmc_softc *sc = &dmc_softc[unit];
	register struct ifxmt *ifxp;

	((struct dmcdevice *)(dmcinfo[unit]->ui_addr))->bsel1 = DMC_MCLR;
	sc->sc_flag &= ~(DMC_RUNNING | DMC_ONLINE);

E 45
D 36
#ifdef notdef	/* tef sez why throw these packets away??? */
	/* purge send queue */
	IF_DEQUEUE(&sc->sc_if.if_snd, m);
	while (m) {
		m_freem(m);
		IF_DEQUEUE(&sc->sc_if.if_snd, m);
	}
#endif
	for (ifxp = ifu->ifu_w; ifxp < &ifu->ifu_w[NXMT]; ifxp++) {
		if (ifxp->x_xtofree) {
			(void) m_freem(ifxp->x_xtofree);
			ifxp->x_xtofree = 0;
E 36
I 36
	for (ifxp = sc->sc_ifw; ifxp < &sc->sc_ifw[NXMT]; ifxp++) {
		if (ifxp->ifw_xtofree) {
			(void) m_freem(ifxp->ifw_xtofree);
			ifxp->ifw_xtofree = 0;
E 36
		}
	}
D 45

	/* restart DMC */
	dmcinit(unit);
	sc->sc_flag &= ~DMC_RESTART;
	sc->sc_if.if_collisions++;	/* why not? */
E 45
I 45
	if_qflush(&sc->sc_if.if_snd);
E 45
}

/*
D 45
 * Check to see that transmitted packets don't
 * lose interrupts.  The device has to be active.
E 45
I 45
 * Watchdog timeout to see that transmitted packets don't
 * lose interrupts.  The device has to be online (the first
 * transmission may block until the other side comes up).
E 45
 */
D 45
dmcwatch()
E 45
I 45
dmctimeout(unit)
	int unit;
E 45
{
D 45
	register struct uba_device *ui;
E 45
	register struct dmc_softc *sc;
	struct dmcdevice *addr;
D 45
	register int i;
E 45

D 45
	for (i = 0; i < NDMC; i++) {
		sc = &dmc_softc[i];
		if ((sc->sc_flag & DMC_ACTIVE) == 0)
			continue;
		if ((ui = dmcinfo[i]) == 0 || ui->ui_alive == 0)
			continue;
		if (sc->sc_oused) {
			sc->sc_nticks++;
			if (sc->sc_nticks > dmc_timeout) {
				sc->sc_nticks = 0;
				addr = (struct dmcdevice *)ui->ui_addr;
D 40
				printd("dmc%d hung: bsel0=%b bsel2=%b\n", i,
				    addr->bsel0 & 0xff, DMC0BITS,
E 40
I 40
				log(LOG_ERR, "dmc%d hung: bsel0=%b bsel2=%b\n",
				    i, addr->bsel0 & 0xff, DMC0BITS,
E 40
				    addr->bsel2 & 0xff, DMC2BITS);
				dmcrestart(i);
			}
		}
E 45
I 45
	sc = &dmc_softc[unit];
	if (sc->sc_flag & DMC_ONLINE) {
		addr = (struct dmcdevice *)(dmcinfo[unit]->ui_addr);
		log(LOG_ERR, "dmc%d: output timeout, bsel0=%b bsel2=%b\n",
		    unit, addr->bsel0 & 0xff, DMC0BITS,
		    addr->bsel2 & 0xff, DMC2BITS);
		dmcrestart(unit);
E 45
	}
D 45
	timeout(dmcwatch, (caddr_t) 0, hz);
E 45
E 33
E 32
E 27
E 10
}
I 29
#endif
E 29
E 1
