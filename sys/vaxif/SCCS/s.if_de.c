h17613
s 00014/00002/00838
d D 7.5 88/08/04 15:15:04 bostic 22 21
c add Berkeley specific copyright notice
e
s 00002/00002/00838
d D 7.4 88/05/26 09:39:23 karels 21 20
c lint
e
s 00002/00000/00838
d D 7.3 87/11/23 15:02:08 karels 20 19
c DEUNA needs reset after uba reset! (from torek)
e
s 00038/00001/00800
d D 7.2 86/07/18 17:48:10 karels 19 18
c fixes from donn for delua
e
s 00001/00001/00800
d D 7.1 86/06/05 17:02:40 mckusick 18 17
c 4.3BSD release version
e
s 00005/00009/00796
d D 6.17 86/01/24 18:33:52 karels 17 16
c use per-host trailer option from ARP
e
s 00000/00003/00805
d D 6.16 85/12/19 15:41:45 karels 16 15
c rm bbnnet
e
s 00035/00056/00773
d D 6.15 85/12/19 15:24:17 karels 15 14
c collapse common code for command waits; more attempts to reset properly
e
s 00050/00026/00779
d D 6.14 85/11/08 19:46:33 karels 14 13
c ifconfig down resets interface, ifconfig up reinitializes;
c error when trying to output packets on down interface; fix address set
c routine, and save the new address for arp; still not working with uba reset
e
s 00034/00313/00771
d D 6.13 85/09/16 22:24:40 karels 13 12
c generalized if_uba support for multiple rcv/xmt buffers per device
e
s 00004/00003/01080
d D 6.12 85/06/22 23:44:01 sklower 12 11
c version from nesheim@cornell doesn't hang the system.
e
s 00038/00005/01045
d D 6.11 85/06/19 09:07:27 sklower 11 10
c check in for 4.3 beta -- known problems with 2nd xns interfaces.
e
s 00041/00001/01009
d D 6.10 85/06/16 13:41:40 sklower 10 9
c first pass at xns additions.  More to come from nesheim@cornell.
e
s 00002/00000/01008
d D 6.9 85/05/04 22:56:50 bloom 9 8
c ifdef PUP include files
e
s 00031/00044/00977
d D 6.8 85/05/01 09:07:00 karels 8 7
c move interface addresses into protocols; remove struct ether_addr again
e
s 00011/00011/01010
d D 6.7 84/08/29 20:42:25 bloom 7 6
c change ot includes.  no more ../h
e
s 00004/00000/01017
d D 6.6 84/07/16 10:45:52 bloom 6 5
c Add spl's around queue manipulation
e
s 00001/00001/01016
d D 6.5 84/04/04 21:39:33 karels 5 4
c debug off
e
s 00006/00008/01011
d D 6.4 84/03/27 13:21:29 karels 4 3
c new address resolution protocol; struct ether_addr
e
s 00085/00052/00934
d D 6.3 84/03/20 15:01:40 karels 3 2
c new version from lou; don't swap the pages!
e
s 00015/00009/00971
d D 6.2 84/02/02 11:04:39 karels 2 1
c fixes from salkind
e
s 00980/00000/00000
d D 6.1 83/11/02 08:47:48 karels 1 0
c From salkind@nyu
e
u
U
t
T
I 1
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
/*
D 18
 * Copyright (c) 1982 Regents of the University of California.
E 18
I 18
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 18
D 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 22
I 22
 * All rights reserved.
E 22
 *
I 22
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
 *
E 22
 *	%W% (Berkeley) %G%
 */
I 22

E 22
D 11

E 11
E 10
#include "de.h"
#if NDE > 0

/*
 * DEC DEUNA interface
 *
 *	Lou Salkind
 *	New York University
 *
 * TODO:
 *	timeout routine (get statistics)
D 2
 *	generalize UNIBUS routines
E 2
 */
#include "../machine/pte.h"

D 7
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/vmmac.h"
#include "../h/ioctl.h"
#include "../h/errno.h"
E 7
I 7
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "ioctl.h"
#include "errno.h"
I 14
#include "syslog.h"
E 14
E 7

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
I 10

I 13
D 16
#ifdef	BBNNET
#define	INET
#endif
E 16
E 13
#ifdef INET
E 10
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 8
#include "../netinet/in_var.h"
E 8
#include "../netinet/ip.h"
D 13
#include "../netinet/ip_var.h"
E 13
#include "../netinet/if_ether.h"
I 10
#endif

E 10
I 9
D 14
#ifdef PUP
E 9
#include "../netpup/pup.h"
I 9
#endif
E 9

E 14
I 10
#ifdef NS
#include "../netns/ns.h"
#include "../netns/ns_if.h"
#endif

E 10
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
D 7
#include "../vaxif/if_dereg.h"
#include "../vaxif/if_uba.h"
E 7
I 7
#include "if_dereg.h"
#include "if_uba.h"
E 7
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"

D 11
#define	NXMT	2	/* number of transmit buffers */
#define	NRCV	4	/* number of receive buffers (must be > 1) */
E 11
I 11
#define	NXMT	3	/* number of transmit buffers */
#define	NRCV	7	/* number of receive buffers (must be > 1) */
E 11
D 13
#define	NTOT	(NXMT + NRCV)
E 13

I 2
D 4
int	dedebug = 0;
E 4
I 4
D 5
int	dedebug = 1;
E 5
I 5
int	dedebug = 0;
E 5
E 4

E 2
int	deprobe(), deattach(), deintr();
struct	uba_device *deinfo[NDE];
u_short destd[] = { 0 };
struct	uba_driver dedriver =
	{ deprobe, 0, deattach, 0, destd, "de", deinfo };
D 8
#define	DEUNIT(x)	minor(x)
E 8
int	deinit(),deoutput(),deioctl(),dereset();
D 13
struct	mbuf *deget();
E 13


/*
D 3
 * The following generalizes the ifuba structure
 * to an arbitrary number of receive and transmit
 * buffers.
E 3
I 3
D 13
 * The deuba structures generalizes the ifuba structure
 * to an arbitrary number of receive and transmit buffers.
E 3
 */
I 3
struct	ifxmt {
	struct	ifrw x_ifrw;			/* mapping information */
	struct	pte x_map[IF_MAXNUBAMR];	/* output base pages */
	short	x_xswapd;			/* mask of clusters swapped */
	struct	mbuf *x_xtofree;		/* pages being dma'ed out */
};

E 3
struct	deuba {
	short	ifu_uban;		/* uba number */
	short	ifu_hlen;		/* local net header length */
	struct	uba_regs *ifu_uba;	/* uba regs, in vm */
	struct	ifrw ifu_r[NRCV];	/* receive information */
D 3
	struct	ifrw ifu_w[NXMT];	/* transmit information */
				/* these should only be pointers */
E 3
I 3
	struct	ifxmt ifu_w[NXMT];	/* transmit information */
E 3
	short	ifu_flags;		/* used during uballoc's */
};

/*
E 13
 * Ethernet software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * ds_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 * We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
struct	de_softc {
	struct	arpcom ds_ac;		/* Ethernet common part */
#define	ds_if	ds_ac.ac_if		/* network-visible interface */
#define	ds_addr	ds_ac.ac_enaddr		/* hardware Ethernet address */
	int	ds_flags;
#define	DSF_LOCK	1		/* lock out destart */
I 2
D 14
#define	DSF_RUNNING	2
E 14
I 14
#define	DSF_RUNNING	2		/* board is enabled */
#define	DSF_SETADDR	4		/* physical address is changed */
E 14
E 2
	int	ds_ubaddr;		/* map info for incore structs */
D 13
	struct	deuba ds_deuba;		/* unibus resource structure */
E 13
I 13
	struct	ifubinfo ds_deuba;	/* unibus resource structure */
	struct	ifrw ds_ifr[NRCV];	/* unibus receive maps */
	struct	ifxmt ds_ifw[NXMT];	/* unibus xmt maps */
E 13
	/* the following structures are always mapped in */
	struct	de_pcbb ds_pcbb;	/* port control block */
	struct	de_ring ds_xrent[NXMT];	/* transmit ring entrys */
	struct	de_ring ds_rrent[NRCV];	/* receive ring entrys */
	struct	de_udbbuf ds_udbbuf;	/* UNIBUS data buffer */
	/* end mapped area */
#define	INCORE_BASE(p)	((char *)&(p)->ds_pcbb)
#define	RVAL_OFF(n)	((char *)&de_softc[0].n - INCORE_BASE(&de_softc[0]))
#define	LVAL_OFF(n)	((char *)de_softc[0].n - INCORE_BASE(&de_softc[0]))
#define	PCBB_OFFSET	RVAL_OFF(ds_pcbb)
#define	XRENT_OFFSET	LVAL_OFF(ds_xrent)
#define	RRENT_OFFSET	LVAL_OFF(ds_rrent)
#define	UDBBUF_OFFSET	RVAL_OFF(ds_udbbuf)
#define	INCORE_SIZE	RVAL_OFF(ds_xindex)
	int	ds_xindex;		/* UNA index into transmit chain */
	int	ds_rindex;		/* UNA index into receive chain */
	int	ds_xfree;		/* index for next transmit buffer */
	int	ds_nxmit;		/* # of transmits in progress */
} de_softc[NDE];

deprobe(reg)
	caddr_t reg;
{
	register int br, cvec;		/* r11, r10 value-result */
	register struct dedevice *addr = (struct dedevice *)reg;
	register i;

#ifdef lint
	br = 0; cvec = br; br = cvec;
	i = 0; derint(i); deintr(i);
#endif

I 19
	/*
	 * Make sure self-test is finished before we screw with the board.
	 * Self-test on a DELUA can take 15 seconds (argh).
	 */
	for (i = 0;
	     i < 160 &&
	     (addr->pcsr0 & PCSR0_FATI) == 0 &&
	     (addr->pcsr1 & PCSR1_STMASK) == STAT_RESET;
	     ++i)
		DELAY(100000);
	if ((addr->pcsr0 & PCSR0_FATI) != 0 ||
	    (addr->pcsr1 & PCSR1_STMASK) != STAT_READY)
		return(0);

	addr->pcsr0 = 0;
	DELAY(100);
E 19
	addr->pcsr0 = PCSR0_RSET;
	while ((addr->pcsr0 & PCSR0_INTR) == 0)
		;
	/* make board interrupt by executing a GETPCBB command */
	addr->pcsr0 = PCSR0_INTE;
	addr->pcsr2 = 0;
	addr->pcsr3 = 0;
	addr->pcsr0 = PCSR0_INTE|CMD_GETPCBB;
	DELAY(100000);
	return(1);
}

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.  We get the ethernet address here.
 */
deattach(ui)
	struct uba_device *ui;
{
	register struct de_softc *ds = &de_softc[ui->ui_unit];
	register struct ifnet *ifp = &ds->ds_if;
	register struct dedevice *addr = (struct dedevice *)ui->ui_addr;
I 19
	int csr1;
E 19
D 8
	struct sockaddr_in *sin;
E 8
D 15
	int csr0;
E 15

	ifp->if_unit = ui->ui_unit;
	ifp->if_name = "de";
	ifp->if_mtu = ETHERMTU;
I 8
	ifp->if_flags = IFF_BROADCAST;
E 8

	/*
I 19
	 * What kind of a board is this?
	 * The error bits 4-6 in pcsr1 are a device id as long as
	 * the high byte is zero.
	 */
	csr1 = addr->pcsr1;
	if (csr1 & 0xff60)
		printf("de%d: broken\n", ui->ui_unit);
	else if (csr1 & 0x10)
		printf("de%d: delua\n", ui->ui_unit);
	else
		printf("de%d: deuna\n", ui->ui_unit);

	/*
E 19
	 * Reset the board and temporarily map
	 * the pcbb buffer onto the Unibus.
	 */
I 19
	addr->pcsr0 = 0;		/* reset INTE */
	DELAY(100);
E 19
	addr->pcsr0 = PCSR0_RSET;
D 15
	while ((addr->pcsr0 & PCSR0_INTR) == 0)
		;
	csr0 = addr->pcsr0;
	addr->pchigh = csr0 >> 8;
	if (csr0 & PCSR0_PCEI)
		printf("de%d: reset failed, csr0=%b csr1=%b\n", ui->ui_unit,
		    csr0, PCSR0_BITS, addr->pcsr1, PCSR1_BITS);
E 15
I 15
	(void)dewait(ui, "reset");

E 15
	ds->ds_ubaddr = uballoc(ui->ui_ubanum, (char *)&ds->ds_pcbb,
		sizeof (struct de_pcbb), 0);
	addr->pcsr2 = ds->ds_ubaddr & 0xffff;
	addr->pcsr3 = (ds->ds_ubaddr >> 16) & 0x3;
	addr->pclow = CMD_GETPCBB;
D 15
	while ((addr->pcsr0 & PCSR0_INTR) == 0)
		;
	csr0 = addr->pcsr0;
	addr->pchigh = csr0 >> 8;
	if (csr0 & PCSR0_PCEI)
		printf("de%d: pcbb failed, csr0=%b csr1=%b\n", ui->ui_unit,
		    csr0, PCSR0_BITS, addr->pcsr1, PCSR1_BITS);
E 15
I 15
	(void)dewait(ui, "pcbb");

E 15
	ds->ds_pcbb.pcbb0 = FC_RDPHYAD;
	addr->pclow = CMD_GETCMD;
D 15
	while ((addr->pcsr0 & PCSR0_INTR) == 0)
		;
	csr0 = addr->pcsr0;
	addr->pchigh = csr0 >> 8;
	if (csr0 & PCSR0_PCEI)
D 14
		printf("de%d: rdphyad failed, csr0=%b csr1=%b\n", ui->ui_unit,
E 14
I 14
		printf("de%d: read addr failed, csr0=%b csr1=%b\n", ui->ui_unit,
E 14
		    csr0, PCSR0_BITS, addr->pcsr1, PCSR1_BITS);
E 15
I 15
	(void)dewait(ui, "read addr ");

E 15
	ubarelse(ui->ui_ubanum, &ds->ds_ubaddr);
D 2
	printf("de%d: addr=%d:%d:%d:%d:%d:%d\n",
		ui->ui_unit,
		ds->ds_pcbb.pcbb2&0xff, (ds->ds_pcbb.pcbb2>>8)&0xff,
		ds->ds_pcbb.pcbb4&0xff, (ds->ds_pcbb.pcbb4>>8)&0xff,
		ds->ds_pcbb.pcbb6&0xff, (ds->ds_pcbb.pcbb6>>8)&0xff);
E 2
I 2
D 17
	if (dedebug)
		printf("de%d: addr=%d:%d:%d:%d:%d:%d\n", ui->ui_unit,
		    ds->ds_pcbb.pcbb2&0xff, (ds->ds_pcbb.pcbb2>>8)&0xff,
		    ds->ds_pcbb.pcbb4&0xff, (ds->ds_pcbb.pcbb4>>8)&0xff,
		    ds->ds_pcbb.pcbb6&0xff, (ds->ds_pcbb.pcbb6>>8)&0xff);
E 17
E 2
D 4
	bcopy((caddr_t)&ds->ds_pcbb.pcbb2, (caddr_t)ds->ds_addr,
E 4
I 4
D 8
	bcopy((caddr_t)&ds->ds_pcbb.pcbb2, (caddr_t)&ds->ds_addr,
E 8
I 8
 	bcopy((caddr_t)&ds->ds_pcbb.pcbb2, (caddr_t)ds->ds_addr,
E 8
E 4
	    sizeof (ds->ds_addr));
I 17
	printf("de%d: hardware address %s\n", ui->ui_unit,
		ether_sprintf(ds->ds_addr));
E 17
D 8
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
E 8
D 4
	sin->sin_addr = arpmyaddr((struct arpcom *)0);
E 4
	ifp->if_init = deinit;
	ifp->if_output = deoutput;
	ifp->if_ioctl = deioctl;
	ifp->if_reset = dereset;
D 13
	ds->ds_deuba.ifu_flags = UBA_CANTWAIT;
E 13
I 13
	ds->ds_deuba.iff_flags = UBA_CANTWAIT;
E 13
#ifdef notdef
	/* CAN WE USE BDP's ??? */
D 13
	ds->ds_deuba.ifu_flags |= UBA_NEEDBDP;
E 13
I 13
	ds->ds_deuba.iff_flags |= UBA_NEEDBDP;
E 13
#endif
	if_attach(ifp);
}

/*
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
dereset(unit, uban)
	int unit, uban;
{
	register struct uba_device *ui;

	if (unit >= NDE || (ui = deinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_ubanum != uban)
		return;
	printf(" de%d", unit);
I 8
	de_softc[unit].ds_if.if_flags &= ~IFF_RUNNING;
I 14
	de_softc[unit].ds_flags &= ~(DSF_LOCK | DSF_RUNNING);
I 20
	((struct dedevice *)ui->ui_addr)->pcsr0 = PCSR0_RSET;
	(void)dewait(ui, "reset");
E 20
E 14
E 8
I 2
D 3
	/* NEED TO RESET IFF_RUNNING AND DSF_RUNNING? */
E 3
E 2
	deinit(unit);
}

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 */
deinit(unit)
	int unit;
{
	register struct de_softc *ds = &de_softc[unit];
	register struct uba_device *ui = deinfo[unit];
	register struct dedevice *addr;
	register struct ifrw *ifrw;
I 3
	register struct ifxmt *ifxp;
	struct ifnet *ifp = &ds->ds_if;
D 8
	struct sockaddr_in *sin;
E 8
E 3
	int s;
D 3
	register struct ifnet *ifp = &ds->ds_if;
	register struct sockaddr_in *sin;
E 3
	struct de_ring *rp;
	int incaddr;
D 15
	int csr0;
E 15

D 8
	sin = (struct sockaddr_in *)&ifp->if_addr;
	if (sin->sin_addr.s_addr == 0)	/* if address still unknown */
E 8
I 8
	/* not yet, if address still unknown */
	if (ifp->if_addrlist == (struct ifaddr *)0)
E 8
		return;

D 14
	if (ifp->if_flags & IFF_RUNNING)
E 14
I 14
	if (ds->ds_flags & DSF_RUNNING)
E 14
D 8
		goto justarp;
E 8
I 8
		return;
E 8
D 13
	if (de_ubainit(&ds->ds_deuba, ui->ui_ubanum,
	    sizeof (struct ether_header), (int)btoc(ETHERMTU)) == 0) { 
E 13
I 13
D 14
	if (if_ubaminit(&ds->ds_deuba, ui->ui_ubanum,
	    sizeof (struct ether_header), (int)btoc(ETHERMTU),
	    ds->ds_ifr, NRCV, ds->ds_ifw, NXMT) == 0) { 
E 13
		printf("de%d: can't initialize\n", unit);
		ds->ds_if.if_flags &= ~IFF_UP;
		return;
E 14
I 14
	if ((ifp->if_flags & IFF_RUNNING) == 0) {
		if (if_ubaminit(&ds->ds_deuba, ui->ui_ubanum,
		    sizeof (struct ether_header), (int)btoc(ETHERMTU),
		    ds->ds_ifr, NRCV, ds->ds_ifw, NXMT) == 0) { 
			printf("de%d: can't initialize\n", unit);
			ds->ds_if.if_flags &= ~IFF_UP;
			return;
		}
		ds->ds_ubaddr = uballoc(ui->ui_ubanum, INCORE_BASE(ds),
			INCORE_SIZE, 0);
E 14
	}
D 14
	ds->ds_ubaddr = uballoc(ui->ui_ubanum, INCORE_BASE(ds), INCORE_SIZE,0);
E 14
	addr = (struct dedevice *)ui->ui_addr;

	/* set the pcbb block address */
	incaddr = ds->ds_ubaddr + PCBB_OFFSET;
	addr->pcsr2 = incaddr & 0xffff;
	addr->pcsr3 = (incaddr >> 16) & 0x3;
I 19
	addr->pclow = 0;	/* reset INTE */
	DELAY(100);
E 19
	addr->pclow = CMD_GETPCBB;
D 15
	while ((addr->pcsr0 & PCSR0_INTR) == 0)
		;
	csr0 = addr->pcsr0;
	addr->pchigh = csr0 >> 8;
	if (csr0 & PCSR0_PCEI)
		printf("de%d: pcbb failed, csr0=%b csr1=%b\n", ui->ui_unit,
		    csr0, PCSR0_BITS, addr->pcsr1, PCSR1_BITS);
E 15
I 15
	(void)dewait(ui, "pcbb");
E 15

	/* set the transmit and receive ring header addresses */
	incaddr = ds->ds_ubaddr + UDBBUF_OFFSET;
	ds->ds_pcbb.pcbb0 = FC_WTRING;
	ds->ds_pcbb.pcbb2 = incaddr & 0xffff;
	ds->ds_pcbb.pcbb4 = (incaddr >> 16) & 0x3;

	incaddr = ds->ds_ubaddr + XRENT_OFFSET;
	ds->ds_udbbuf.b_tdrbl = incaddr & 0xffff;
	ds->ds_udbbuf.b_tdrbh = (incaddr >> 16) & 0x3;
	ds->ds_udbbuf.b_telen = sizeof (struct de_ring) / sizeof (short);
	ds->ds_udbbuf.b_trlen = NXMT;
	incaddr = ds->ds_ubaddr + RRENT_OFFSET;
	ds->ds_udbbuf.b_rdrbl = incaddr & 0xffff;
	ds->ds_udbbuf.b_rdrbh = (incaddr >> 16) & 0x3;
	ds->ds_udbbuf.b_relen = sizeof (struct de_ring) / sizeof (short);
	ds->ds_udbbuf.b_rrlen = NRCV;

	addr->pclow = CMD_GETCMD;
D 15
	while ((addr->pcsr0 & PCSR0_INTR) == 0)
		;
	csr0 = addr->pcsr0;
	addr->pchigh = csr0 >> 8;
	if (csr0 & PCSR0_PCEI)
		printf("de%d: wtring failed, csr0=%b csr1=%b\n", ui->ui_unit,
		    csr0, PCSR0_BITS, addr->pcsr1, PCSR1_BITS);
E 15
I 15
	(void)dewait(ui, "wtring");
E 15

	/* initialize the mode - enable hardware padding */
	ds->ds_pcbb.pcbb0 = FC_WTMODE;
	/* let hardware do padding - set MTCH bit on broadcast */
	ds->ds_pcbb.pcbb2 = MOD_TPAD|MOD_HDX;
	addr->pclow = CMD_GETCMD;
D 15
	while ((addr->pcsr0 & PCSR0_INTR) == 0)
		;
	csr0 = addr->pcsr0;
	addr->pchigh = csr0 >> 8;
	if (csr0 & PCSR0_PCEI)
		printf("de%d: wtmode failed, csr0=%b csr1=%b\n", ui->ui_unit,
		    csr0, PCSR0_BITS, addr->pcsr1, PCSR1_BITS);
E 15
I 15
	(void)dewait(ui, "wtmode");
E 15

	/* set up the receive and transmit ring entries */
D 3
	ifrw = &ds->ds_deuba.ifu_w[0];
E 3
I 3
D 13
	ifxp = &ds->ds_deuba.ifu_w[0];
E 13
I 13
	ifxp = &ds->ds_ifw[0];
E 13
E 3
	for (rp = &ds->ds_xrent[0]; rp < &ds->ds_xrent[NXMT]; rp++) {
D 3
		rp->r_segbl = ifrw->ifrw_info & 0xffff;
		rp->r_segbh = (ifrw->ifrw_info >> 16) & 0x3;
E 3
I 3
D 13
		rp->r_segbl = ifxp->x_ifrw.ifrw_info & 0xffff;
		rp->r_segbh = (ifxp->x_ifrw.ifrw_info >> 16) & 0x3;
E 13
I 13
		rp->r_segbl = ifxp->ifw_info & 0xffff;
		rp->r_segbh = (ifxp->ifw_info >> 16) & 0x3;
E 13
E 3
		rp->r_flags = 0;
D 3
		ifrw++;
E 3
I 3
		ifxp++;
E 3
	}
D 13
	ifrw = &ds->ds_deuba.ifu_r[0];
E 13
I 13
	ifrw = &ds->ds_ifr[0];
E 13
	for (rp = &ds->ds_rrent[0]; rp < &ds->ds_rrent[NRCV]; rp++) {
		rp->r_slen = sizeof (struct de_buf);
		rp->r_segbl = ifrw->ifrw_info & 0xffff;
		rp->r_segbh = (ifrw->ifrw_info >> 16) & 0x3;
		rp->r_flags = RFLG_OWN;		/* hang receive */
		ifrw++;
	}

	/* start up the board (rah rah) */
	s = splimp();
D 14
	ds->ds_rindex = ds->ds_xindex = ds->ds_xfree = 0;
E 14
I 14
	ds->ds_rindex = ds->ds_xindex = ds->ds_xfree = ds->ds_nxmit = 0;
E 14
D 2
	destart(unit);		/* queue output packets */
E 2
I 2
D 8
	ds->ds_if.if_flags |= IFF_UP|IFF_RUNNING;
E 8
I 8
	ds->ds_if.if_flags |= IFF_RUNNING;
I 15
D 19
	destart(unit);				/* queue output packets */
E 19
E 15
E 8
D 14
	destart(unit);				/* queue output packets */
E 14
E 2
	addr->pclow = PCSR0_INTE;		/* avoid interlock */
I 19
	destart(unit);				/* queue output packets */
E 19
D 15
	addr->pclow = CMD_START | PCSR0_INTE;
D 2
	ds->ds_if.if_flags |= IFF_UP|IFF_RUNNING;	/* after destart */
E 2
I 2
	ds->ds_flags |= DSF_RUNNING;
E 15
I 15
	ds->ds_flags |= DSF_RUNNING;		/* need before de_setaddr */
E 15
I 14
	if (ds->ds_flags & DSF_SETADDR)
		de_setaddr(ds->ds_addr, unit);
D 15
	destart(unit);				/* queue output packets */
E 15
I 15
	addr->pclow = CMD_START | PCSR0_INTE;
E 15
E 14
E 2
	splx(s);
D 8
justarp:
	if_rtinit(&ds->ds_if, RTF_UP);
D 4
	arpattach(&ds->ds_ac);
E 4
	arpwhohas(&ds->ds_ac, &sin->sin_addr);
E 8
}

/*
 * Setup output on interface.
 * Get another datagram to send off of the interface queue,
 * and map it to the interface before starting the output.
 */
destart(unit)
	int unit;
{
        int len;
	struct uba_device *ui = deinfo[unit];
	struct dedevice *addr = (struct dedevice *)ui->ui_addr;
	register struct de_softc *ds = &de_softc[unit];
	register struct de_ring *rp;
	struct mbuf *m;
	register int nxmit;

	/*
	 * the following test is necessary, since
	 * the code is not reentrant and we have
	 * multiple transmission buffers.
	 */
	if (ds->ds_flags & DSF_LOCK)
		return;
	for (nxmit = ds->ds_nxmit; nxmit < NXMT; nxmit++) {
		IF_DEQUEUE(&ds->ds_if.if_snd, m);
		if (m == 0)
			break;
		rp = &ds->ds_xrent[ds->ds_xfree];
		if (rp->r_flags & XFLG_OWN)
			panic("deuna xmit in progress");
D 3
		len = deput(&ds->ds_deuba.ifu_w[ds->ds_xfree], m);
E 3
I 3
D 13
		len = deput(&ds->ds_deuba, ds->ds_xfree, m);
E 3
		if (ds->ds_deuba.ifu_flags & UBA_NEEDBDP)
			UBAPURGE(ds->ds_deuba.ifu_uba,
D 3
			ds->ds_deuba.ifu_w[ds->ds_xfree].ifrw_bdp);
E 3
I 3
			ds->ds_deuba.ifu_w[ds->ds_xfree].x_ifrw.ifrw_bdp);
E 13
I 13
		len = if_ubaput(&ds->ds_deuba, &ds->ds_ifw[ds->ds_xfree], m);
		if (ds->ds_deuba.iff_flags & UBA_NEEDBDP)
			UBAPURGE(ds->ds_deuba.iff_uba,
			ds->ds_ifw[ds->ds_xfree].ifw_bdp);
E 13
E 3
		rp->r_slen = len;
		rp->r_tdrerr = 0;
		rp->r_flags = XFLG_STP|XFLG_ENP|XFLG_OWN;

		ds->ds_xfree++;
		if (ds->ds_xfree == NXMT)
			ds->ds_xfree = 0;
	}
	if (ds->ds_nxmit != nxmit) {
		ds->ds_nxmit = nxmit;
D 2
		if (ds->ds_if.if_flags & IFF_UP)
E 2
I 2
		if (ds->ds_flags & DSF_RUNNING)
E 2
			addr->pclow = PCSR0_INTE|CMD_PDMD;
	}
}

/*
 * Command done interrupt.
 */
deintr(unit)
	int unit;
{
	struct uba_device *ui = deinfo[unit];
	register struct dedevice *addr = (struct dedevice *)ui->ui_addr;
	register struct de_softc *ds = &de_softc[unit];
	register struct de_ring *rp;
I 3
	register struct ifxmt *ifxp;
E 3
	short csr0;

	/* save flags right away - clear out interrupt bits */
	csr0 = addr->pcsr0;
	addr->pchigh = csr0 >> 8;


	ds->ds_flags |= DSF_LOCK;	/* prevent entering destart */
	/*
	 * if receive, put receive buffer on mbuf
	 * and hang the request again
	 */
	derecv(unit);

	/*
	 * Poll transmit ring and check status.
	 * Be careful about loopback requests.
	 * Then free buffer space and check for
	 * more transmit requests.
	 */
	for ( ; ds->ds_nxmit > 0; ds->ds_nxmit--) {
		rp = &ds->ds_xrent[ds->ds_xindex];
		if (rp->r_flags & XFLG_OWN)
			break;
		ds->ds_if.if_opackets++;
I 3
D 13
		ifxp = &ds->ds_deuba.ifu_w[ds->ds_xindex];
E 13
I 13
		ifxp = &ds->ds_ifw[ds->ds_xindex];
E 13
E 3
		/* check for unusual conditions */
		if (rp->r_flags & (XFLG_ERRS|XFLG_MTCH|XFLG_ONE|XFLG_MORE)) {
			if (rp->r_flags & XFLG_ERRS) {
				/* output error */
				ds->ds_if.if_oerrors++;
I 2
				if (dedebug)
E 2
			printf("de%d: oerror, flags=%b tdrerr=%b (len=%d)\n",
				    unit, rp->r_flags, XFLG_BITS,
				    rp->r_tdrerr, XERR_BITS, rp->r_slen);
			} else if (rp->r_flags & XFLG_ONE) {
				/* one collision */
				ds->ds_if.if_collisions++;
			} else if (rp->r_flags & XFLG_MORE) {
				/* more than one collision */
				ds->ds_if.if_collisions += 2;	/* guess */
			} else if (rp->r_flags & XFLG_MTCH) {
				/* received our own packet */
				ds->ds_if.if_ipackets++;
D 3
				deread(ds, &ds->ds_deuba.ifu_w[ds->ds_xindex],
E 3
I 3
D 13
				deread(ds, &ifxp->x_ifrw,
E 13
I 13
				deread(ds, &ifxp->ifrw,
E 13
E 3
				    rp->r_slen - sizeof (struct ether_header));
			}
		}
I 3
D 13
		if (ifxp->x_xtofree) {
			m_freem(ifxp->x_xtofree);
			ifxp->x_xtofree = 0;
E 13
I 13
		if (ifxp->ifw_xtofree) {
			m_freem(ifxp->ifw_xtofree);
			ifxp->ifw_xtofree = 0;
E 13
		}
E 3
		/* check if next transmit buffer also finished */
		ds->ds_xindex++;
		if (ds->ds_xindex == NXMT)
			ds->ds_xindex = 0;
	}
	ds->ds_flags &= ~DSF_LOCK;
	destart(unit);

	if (csr0 & PCSR0_RCBI) {
D 14
		printf("de%d: buffer unavailable\n", unit);
E 14
I 14
D 15
		log(LOG_WARNING, "de%d: buffer unavailable\n", unit);
E 15
I 15
		if (dedebug)
			log(LOG_WARNING, "de%d: buffer unavailable\n", unit);
E 15
E 14
		addr->pclow = PCSR0_INTE|CMD_PDMD;
	}
}

/*
 * Ethernet interface receiver interface.
 * If input error just drop packet.
 * Otherwise purge input buffered data path and examine 
 * packet to determine type.  If can't determine length
 * from type, then have to drop packet.  Othewise decapsulate
 * packet based on type and pass to type specific higher-level
 * input routine.
 */
derecv(unit)
	int unit;
{
	register struct de_softc *ds = &de_softc[unit];
	register struct de_ring *rp;
	int len;

	rp = &ds->ds_rrent[ds->ds_rindex];
	while ((rp->r_flags & RFLG_OWN) == 0) {
		ds->ds_if.if_ipackets++;
D 13
		if (ds->ds_deuba.ifu_flags & UBA_NEEDBDP)
			UBAPURGE(ds->ds_deuba.ifu_uba,
			ds->ds_deuba.ifu_r[ds->ds_rindex].ifrw_bdp);
E 13
I 13
		if (ds->ds_deuba.iff_flags & UBA_NEEDBDP)
			UBAPURGE(ds->ds_deuba.iff_uba,
			ds->ds_ifr[ds->ds_rindex].ifrw_bdp);
E 13
		len = (rp->r_lenerr&RERR_MLEN) - sizeof (struct ether_header)
			- 4;	/* don't forget checksum! */
		/* check for errors */
		if ((rp->r_flags & (RFLG_ERRS|RFLG_FRAM|RFLG_OFLO|RFLG_CRC)) ||
		    (rp->r_flags&(RFLG_STP|RFLG_ENP)) != (RFLG_STP|RFLG_ENP) ||
		    (rp->r_lenerr & (RERR_BUFL|RERR_UBTO|RERR_NCHN)) ||
		    len < ETHERMIN || len > ETHERMTU) {
			ds->ds_if.if_ierrors++;
I 2
			if (dedebug)
E 2
			printf("de%d: ierror, flags=%b lenerr=%b (len=%d)\n",
				unit, rp->r_flags, RFLG_BITS, rp->r_lenerr,
				RERR_BITS, len);
		} else
D 13
			deread(ds, &ds->ds_deuba.ifu_r[ds->ds_rindex], len);
E 13
I 13
			deread(ds, &ds->ds_ifr[ds->ds_rindex], len);
E 13

		/* hang the receive buffer again */
		rp->r_lenerr = 0;
		rp->r_flags = RFLG_OWN;

		/* check next receive buffer */
		ds->ds_rindex++;
		if (ds->ds_rindex == NRCV)
			ds->ds_rindex = 0;
		rp = &ds->ds_rrent[ds->ds_rindex];
	}
}

/*
 * Pass a packet to the higher levels.
 * We deal with the trailer protocol here.
 */
deread(ds, ifrw, len)
	register struct de_softc *ds;
	struct ifrw *ifrw;
	int len;
{
	struct ether_header *eh;
    	struct mbuf *m;
	int off, resid;
I 6
	int s;
E 6
	register struct ifqueue *inq;

	/*
D 8
	 * Deal with trailer protocol: if type is PUP trailer
E 8
I 8
	 * Deal with trailer protocol: if type is trailer type
E 8
	 * get true type from first 16-bit word past data.
	 * Remember that type was trailer by setting off.
	 */
	eh = (struct ether_header *)ifrw->ifrw_addr;
	eh->ether_type = ntohs((u_short)eh->ether_type);
#define	dedataaddr(eh, off, type)	((type)(((caddr_t)((eh)+1)+(off))))
D 8
	if (eh->ether_type >= ETHERPUP_TRAIL &&
	    eh->ether_type < ETHERPUP_TRAIL+ETHERPUP_NTRAILER) {
		off = (eh->ether_type - ETHERPUP_TRAIL) * 512;
E 8
I 8
	if (eh->ether_type >= ETHERTYPE_TRAIL &&
	    eh->ether_type < ETHERTYPE_TRAIL+ETHERTYPE_NTRAILER) {
		off = (eh->ether_type - ETHERTYPE_TRAIL) * 512;
E 8
		if (off >= ETHERMTU)
			return;		/* sanity */
		eh->ether_type = ntohs(*dedataaddr(eh, off, u_short *));
		resid = ntohs(*(dedataaddr(eh, off+2, u_short *)));
		if (off + resid > len)
			return;		/* sanity */
		len = off + resid;
	} else
		off = 0;
	if (len == 0)
		return;

	/*
	 * Pull packet off interface.  Off is nonzero if packet
D 13
	 * has trailing header; deget will then force this header
E 13
I 13
	 * has trailing header; if_ubaget will then force this header
E 13
	 * information to be at the front, but we still have to drop
	 * the type and length which are at the front of any trailer data.
	 */
D 13
	m = deget(&ds->ds_deuba, ifrw, len, off);
E 13
I 13
	m = if_ubaget(&ds->ds_deuba, ifrw, len, off, &ds->ds_if);
E 13
	if (m == 0)
		return;
	if (off) {
I 13
		struct ifnet *ifp;

		ifp = *(mtod(m, struct ifnet **));
E 13
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
I 13
		*(mtod(m, struct ifnet **)) = ifp;
E 13
	}
	switch (eh->ether_type) {

#ifdef INET
D 8
	case ETHERPUP_IPTYPE:
E 8
I 8
	case ETHERTYPE_IP:
E 8
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;

D 8
	case ETHERPUP_ARPTYPE:
E 8
I 8
	case ETHERTYPE_ARP:
E 8
		arpinput(&ds->ds_ac, m);
		return;
#endif
I 10
#ifdef NS
	case ETHERTYPE_NS:
		schednetisr(NETISR_NS);
		inq = &nsintrq;
		break;

#endif
E 10
	default:
		m_freem(m);
		return;
	}

I 6
	s = splimp();
E 6
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
I 6
		splx(s);
E 6
		m_freem(m);
		return;
	}
	IF_ENQUEUE(inq, m);
I 6
	splx(s);
E 6
}

/*
 * Ethernet output routine.
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
 */
deoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
	int type, s, error;
D 4
	u_char edst[6];
E 4
I 4
D 8
	struct ether_addr edst;
E 8
I 8
 	u_char edst[6];
E 8
E 4
	struct in_addr idst;
	register struct de_softc *ds = &de_softc[ifp->if_unit];
	register struct mbuf *m = m0;
	register struct ether_header *eh;
	register int off;
I 17
	int usetrailers;
E 17

I 14
	if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) != (IFF_UP|IFF_RUNNING)) {
		error = ENETDOWN;
		goto bad;
	}
E 14
	switch (dst->sa_family) {

#ifdef INET
	case AF_INET:
		idst = ((struct sockaddr_in *)dst)->sin_addr;
D 4
		if (!arpresolve(&ds->ds_ac, m, &idst, edst))
E 4
I 4
D 8
		if (!arpresolve(&ds->ds_ac, m, &idst, &edst))
E 8
I 8
D 17
 		if (!arpresolve(&ds->ds_ac, m, &idst, edst))
E 17
I 17
 		if (!arpresolve(&ds->ds_ac, m, &idst, edst, &usetrailers))
E 17
E 8
E 4
			return (0);	/* if not yet resolved */
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
D 17
		/* need per host negotiation */
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
		if (off > 0 && (off & 0x1ff) == 0 &&
E 17
I 17
		if (usetrailers && off > 0 && (off & 0x1ff) == 0 &&
E 17
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
D 8
			type = ETHERPUP_TRAIL + (off>>9);
E 8
I 8
			type = ETHERTYPE_TRAIL + (off>>9);
E 8
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
D 8
			*mtod(m, u_short *) = htons((u_short)ETHERPUP_IPTYPE);
E 8
I 8
			*mtod(m, u_short *) = htons((u_short)ETHERTYPE_IP);
E 8
			*(mtod(m, u_short *) + 1) = htons((u_short)m->m_len);
			goto gottrailertype;
		}
D 8
		type = ETHERPUP_IPTYPE;
E 8
I 8
		type = ETHERTYPE_IP;
E 8
		off = 0;
		goto gottype;
#endif
I 10
#ifdef NS
	case AF_NS:
		type = ETHERTYPE_NS;
 		bcopy((caddr_t)&(((struct sockaddr_ns *)dst)->sns_addr.x_host),
		(caddr_t)edst, sizeof (edst));
		off = 0;
		goto gottype;
#endif
E 10

	case AF_UNSPEC:
		eh = (struct ether_header *)dst->sa_data;
D 4
		bcopy((caddr_t)eh->ether_dhost, (caddr_t)edst, sizeof (edst));
E 4
I 4
D 8
		edst = eh->ether_dhost;
E 8
I 8
 		bcopy((caddr_t)eh->ether_dhost, (caddr_t)edst, sizeof (edst));
E 8
E 4
		type = eh->ether_type;
		goto gottype;

	default:
		printf("de%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
		error = EAFNOSUPPORT;
		goto bad;
	}

gottrailertype:
	/*
	 * Packet to be sent as trailer: move first packet
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
	 * Add local net header.  If no space in first mbuf,
	 * allocate another.
	 */
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof (struct ether_header) > m->m_off) {
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			error = ENOBUFS;
			goto bad;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
		m->m_len = sizeof (struct ether_header);
	} else {
		m->m_off -= sizeof (struct ether_header);
		m->m_len += sizeof (struct ether_header);
	}
	eh = mtod(m, struct ether_header *);
	eh->ether_type = htons((u_short)type);
D 4
	bcopy((caddr_t)edst, (caddr_t)eh->ether_dhost, sizeof (edst));
E 4
I 4
D 8
	eh->ether_dhost = edst;
E 8
I 8
 	bcopy((caddr_t)edst, (caddr_t)eh->ether_dhost, sizeof (edst));
E 8
E 4
	/* DEUNA fills in source address */

	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
	s = splimp();
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
		splx(s);
		m_freem(m);
		return (ENOBUFS);
	}
	IF_ENQUEUE(&ifp->if_snd, m);
	destart(ifp->if_unit);
	splx(s);
	return (0);

bad:
	m_freem(m0);
	return (error);
}

/*
D 13
 * Routines supporting UNIBUS network interfaces.
 */

/*
 * Init UNIBUS for interface on uban whose headers of size hlen are to
 * end on a page boundary.  We allocate a UNIBUS map register for the page
 * with the header, and nmr more UNIBUS map registers for i/o on the adapter,
 * doing this for each receive and transmit buffer.  We also
 * allocate page frames in the mbuffer pool for these pages.
 */
de_ubainit(ifu, uban, hlen, nmr)
	register struct deuba *ifu;
	int uban, hlen, nmr;
{
	register caddr_t cp, dp;
	register struct ifrw *ifrw;
D 3
	int ncl;
E 3
I 3
	register struct ifxmt *ifxp;
	int i, ncl;
E 3

	ncl = clrnd(nmr + CLSIZE) / CLSIZE;
	if (ifu->ifu_r[0].ifrw_addr)
		/*
		 * If the first read buffer has a non-zero
		 * address, it means we have already allocated core
		 */
		cp = ifu->ifu_r[0].ifrw_addr - (CLBYTES - hlen);
	else {
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
D 3
		for (ifrw = ifu->ifu_w; ifrw < &ifu->ifu_w[NXMT]; ifrw++) {
			ifrw->ifrw_addr = dp;
E 3
I 3
		for (ifxp = ifu->ifu_w; ifxp < &ifu->ifu_w[NXMT]; ifxp++) {
			ifxp->x_ifrw.ifrw_addr = dp;
E 3
			dp += ncl * CLBYTES;
		}
	}
	/* allocate for receive ring */
	for (ifrw = ifu->ifu_r; ifrw < &ifu->ifu_r[NRCV]; ifrw++) {
		if (de_ubaalloc(ifu, ifrw, nmr) == 0) {
D 3
			struct ifrw *if2;
E 3
I 3
			struct ifrw *rw;
E 3

D 3
			for (if2 = ifu->ifu_r; if2 < ifrw; if2++)
				ubarelse(ifu->ifu_uban, &if2->ifrw_info);
E 3
I 3
			for (rw = ifu->ifu_r; rw < ifrw; rw++)
				ubarelse(ifu->ifu_uban, &rw->ifrw_info);
E 3
			goto bad;
		}
	}
	/* and now transmit ring */
D 3
	for (ifrw = ifu->ifu_w; ifrw < &ifu->ifu_w[NXMT]; ifrw++) {
E 3
I 3
	for (ifxp = ifu->ifu_w; ifxp < &ifu->ifu_w[NXMT]; ifxp++) {
		ifrw = &ifxp->x_ifrw;
E 3
		if (de_ubaalloc(ifu, ifrw, nmr) == 0) {
D 3
			struct ifrw *if2;
E 3
I 3
			struct ifxmt *xp;
E 3

D 3
			for (if2 = ifu->ifu_w; if2 < ifrw; if2++)
				ubarelse(ifu->ifu_uban, &if2->ifrw_info);
			for (if2 = ifu->ifu_r; if2 < &ifu->ifu_r[NRCV]; if2++)
				ubarelse(ifu->ifu_uban, &if2->ifrw_info);
E 3
I 3
			for (xp = ifu->ifu_w; xp < ifxp; xp++)
				ubarelse(ifu->ifu_uban, &xp->x_ifrw.ifrw_info);
			for (ifrw = ifu->ifu_r; ifrw < &ifu->ifu_r[NRCV]; ifrw++)
				ubarelse(ifu->ifu_uban, &ifrw->ifrw_info);
E 3
			goto bad;
		}
I 3
		for (i = 0; i < nmr; i++)
			ifxp->x_map[i] = ifrw->ifrw_mr[i];
		ifxp->x_xswapd = 0;
E 3
	}
	return (1);
bad:
	m_pgfree(cp, NTOT * ncl);
	ifu->ifu_r[0].ifrw_addr = 0;
	return(0);
}

/*
 * Setup either a ifrw structure by allocating UNIBUS map registers,
 * possibly a buffered data path, and initializing the fields of
 * the ifrw structure to minimize run-time overhead.
 */
static
de_ubaalloc(ifu, ifrw, nmr)
	struct deuba *ifu;
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
deget(ifu, ifrw, totlen, off0)
	register struct deuba *ifu;
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
D 3
 *
 * This routine is unlike if_wubaput in that pages are
 * actually switched, rather than the UNIBUS maps temporarily
 * remapped.
E 3
 */
D 3
deput(ifrw, m)
	register struct ifrw *ifrw;
E 3
I 3
deput(ifu, n, m)
	struct deuba *ifu;
	int n;
E 3
	register struct mbuf *m;
{
	register struct mbuf *mp;
	register caddr_t cp;
D 3
	int cc;
	register caddr_t dp;
E 3
I 3
	register struct ifxmt *ifxp;
	register struct ifrw *ifrw;
E 3
	register int i;
D 3
	int x;
E 3
I 3
	int xswapd = 0;
	int x, cc, t;
	caddr_t dp;
E 3

I 3
	ifxp = &ifu->ifu_w[n];
	ifrw = &ifxp->x_ifrw;
E 3
	cp = ifrw->ifrw_addr;
	while (m) {
		dp = mtod(m, char *);
		if (claligned(cp) && claligned(dp) && m->m_len == CLBYTES) {
D 3
			struct pte *cpte, *ppte;
			int *ip;

			cpte = &Mbmap[mtocl(cp)*CLSIZE];
			ppte = &Mbmap[mtocl(dp)*CLSIZE];
E 3
I 3
			struct pte *pte; int *ip;
			pte = &Mbmap[mtocl(dp)*CLSIZE];
E 3
			x = btop(cp - ifrw->ifrw_addr);
			ip = (int *)&ifrw->ifrw_mr[x];
D 3
			for (i = 0; i < CLSIZE; i++) {
				struct pte t;
				t = *ppte; *ppte++ = *cpte; *cpte = t;
E 3
I 3
			for (i = 0; i < CLSIZE; i++)
E 3
				*ip++ =
D 3
				    cpte++->pg_pfnum|ifrw->ifrw_proto;
				mtpr(TBIS, cp);
				cp += NBPG;
				mtpr(TBIS, dp);
				dp += NBPG;
			}
E 3
I 3
				    ifrw->ifrw_proto | pte++->pg_pfnum;
			xswapd |= 1 << (x>>(CLSHIFT-PGSHIFT));
			mp = m->m_next;
			m->m_next = ifxp->x_xtofree;
			ifxp->x_xtofree = m;
			cp += m->m_len;
E 3
		} else {
			bcopy(mtod(m, caddr_t), cp, (unsigned)m->m_len);
			cp += m->m_len;
I 3
			MFREE(m, mp);
E 3
		}
D 3
		MFREE(m, mp);
E 3
		m = mp;
	}

I 3
	/*
	 * Xswapd is the set of clusters we just mapped out.  Ifxp->x_xswapd
	 * is the set of clusters mapped out from before.  We compute
	 * the number of clusters involved in this operation in x.
	 * Clusters mapped out before and involved in this operation
	 * should be unmapped so original pages will be accessed by the device.
	 */
E 3
	cc = cp - ifrw->ifrw_addr;
I 3
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
E 3
	return (cc);
}
D 3
#endif
E 3

/*
E 13
 * Process an ioctl request.
 */
deioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 8
	register struct ifreq *ifr = (struct ifreq *)data;
E 8
I 8
	register struct ifaddr *ifa = (struct ifaddr *)data;
I 14
	register struct de_softc *ds = &de_softc[ifp->if_unit];
E 14
E 8
	int s = splimp(), error = 0;

	switch (cmd) {

	case SIOCSIFADDR:
D 8
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
		desetaddr(ifp, (struct sockaddr_in *)&ifr->ifr_addr);
E 8
I 8
		ifp->if_flags |= IFF_UP;
E 8
		deinit(ifp->if_unit);
I 8

		switch (ifa->ifa_addr.sa_family) {
I 10
#ifdef INET
E 10
		case AF_INET:
			((struct arpcom *)ifp)->ac_ipaddr =
				IA_SIN(ifa)->sin_addr;
			arpwhohas((struct arpcom *)ifp, &IA_SIN(ifa)->sin_addr);
			break;
I 10
#endif
#ifdef NS
		case AF_NS:
D 11
			IA_SNS(ifa)->sns_addr.x_host =
				* (union ns_host *)
E 11
I 11
		    {
			register struct ns_addr *ina = &(IA_SNS(ifa)->sns_addr);
			
D 14
			if (ns_nullhost(*ina)) {
				ina->x_host = * (union ns_host *) 
E 11
				     (de_softc[ifp->if_unit].ds_addr);
I 11
			} else {
E 14
I 14
			if (ns_nullhost(*ina))
				ina->x_host = *(union ns_host *)(ds->ds_addr);
			else
E 14
				de_setaddr(ina->x_host.c_host,ifp->if_unit);
D 14
			}
E 14
E 11
			break;
I 11
		    }
E 11
#endif
E 10
		}
E 8
		break;

I 14
	case SIOCSIFFLAGS:
		if ((ifp->if_flags & IFF_UP) == 0 &&
		    ds->ds_flags & DSF_RUNNING) {
I 19
			((struct dedevice *)
			   (deinfo[ifp->if_unit]->ui_addr))->pclow = 0;
			DELAY(100);
E 19
			((struct dedevice *)
			   (deinfo[ifp->if_unit]->ui_addr))->pclow = PCSR0_RSET;
			ds->ds_flags &= ~(DSF_LOCK | DSF_RUNNING);
		} else if (ifp->if_flags & IFF_UP &&
		    (ds->ds_flags & DSF_RUNNING) == 0)
			deinit(ifp->if_unit);
		break;

E 14
	default:
		error = EINVAL;
	}
	splx(s);
	return (error);
D 8
}

desetaddr(ifp, sin)
	register struct ifnet *ifp;
	register struct sockaddr_in *sin;
{

	ifp->if_addr = *(struct sockaddr *)sin;
	ifp->if_net = in_netof(sin->sin_addr);
	ifp->if_host[0] = in_lnaof(sin->sin_addr);
	sin = (struct sockaddr_in *)&ifp->if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags |= IFF_BROADCAST;
E 8
}
I 11

/*
 * set ethernet address for unit
 */
de_setaddr(physaddr, unit)
D 14
u_char *physaddr;
int unit;
E 14
I 14
	u_char *physaddr;
	int unit;
E 14
{
	register struct de_softc *ds = &de_softc[unit];
D 15
	register struct uba_device *ui = deinfo[unit];
E 15
I 15
	struct uba_device *ui = deinfo[unit];
E 15
	register struct dedevice *addr= (struct dedevice *)ui->ui_addr;
D 15
	int csr0;
E 15
	
I 12
	if (! (ds->ds_flags & DSF_RUNNING))
		return;
		
E 12
D 21
	bcopy(physaddr, &ds->ds_pcbb.pcbb2, 6);
E 21
I 21
	bcopy((caddr_t) physaddr, (caddr_t) &ds->ds_pcbb.pcbb2, 6);
E 21
	ds->ds_pcbb.pcbb0 = FC_WTPHYAD;
D 12
	addr->pclow = CMD_GETCMD;
	while ((addr->pcsr0 & PCSR0_INTR) == 0)
			;
E 12
I 12
D 14
	addr->pclow = PCSR0_INTE|CMD_PDMD;
E 14
I 14
	addr->pclow = PCSR0_INTE|CMD_GETCMD;
I 15
	if (dewait(ui, "address change") == 0) {
		ds->ds_flags |= DSF_SETADDR;
D 21
		bcopy(physaddr, ds->ds_addr, 6);
E 21
I 21
		bcopy((caddr_t) physaddr, (caddr_t) ds->ds_addr, 6);
E 21
	}
}

/*
 * Await completion of the named function
 * and check for errors.
 */
dewait(ui, fn)
	register struct uba_device *ui;
	char *fn;
{
	register struct dedevice *addr = (struct dedevice *)ui->ui_addr;
	register csr0;

E 15
	while ((addr->pcsr0 & PCSR0_INTR) == 0)
		;
E 14
E 12
	csr0 = addr->pcsr0;
	addr->pchigh = csr0 >> 8;
	if (csr0 & PCSR0_PCEI)
D 14
		printf("de%d: wtphyad failed, csr0=%b csr1=%b\n", 
E 14
I 14
D 15
		printf("de%d: address change failed, csr0=%b csr1=%b\n", 
E 14
		    ui->ui_unit, csr0, PCSR0_BITS, 
E 15
I 15
		printf("de%d: %s failed, csr0=%b csr1=%b\n", 
		    ui->ui_unit, fn, csr0, PCSR0_BITS, 
E 15
		    addr->pcsr1, PCSR1_BITS);
I 14
D 15
	else {
		ds->ds_flags |= DSF_SETADDR;
		bcopy(physaddr, ds->ds_addr, 6);
	}
E 15
I 15
	return (csr0 & PCSR0_PCEI);
E 15
E 14
}
D 13

E 13
E 11
I 3
#endif
I 11
D 13

E 13
E 11
E 3
E 1
