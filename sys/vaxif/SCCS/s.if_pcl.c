h50118
s 00013/00002/00485
d D 7.2 88/08/04 15:28:53 bostic 14 13
c add Berkeley specific copyright
e
s 00001/00001/00486
d D 7.1 86/06/05 17:09:58 mckusick 13 12
c 4.3BSD release version
e
s 00003/00000/00484
d D 6.8 86/06/02 14:45:04 karels 12 11
c lint
e
s 00001/00000/00483
d D 6.7 86/02/20 20:43:48 karels 11 10
c lint
e
s 00000/00003/00483
d D 6.6 85/12/19 15:47:22 karels 10 9
c rm bbnnet
e
s 00006/00003/00480
d D 6.5 85/09/16 22:21:37 karels 9 8
c pass ifp to if_{r,}ubaget, shuffle it up if receiving trailer
e
s 00007/00001/00476
d D 6.4 85/06/08 13:58:52 mckusick 8 7
c Add copyright
e
s 00010/00023/00467
d D 6.3 85/06/03 08:40:39 karels 7 6
c now they compile at least
e
s 00011/00011/00479
d D 6.2 84/08/29 20:44:11 bloom 6 5
c change ot includes.  no more ../h
e
s 00000/00000/00490
d D 6.1 83/07/29 07:38:23 sam 5 4
c 4.2 distribution
e
s 00031/00012/00459
d D 4.4 83/07/06 14:12:06 sam 4 3
c from muus -- broadcasting support
e
s 00005/00007/00466
d D 4.3 83/06/13 22:46:50 sam 3 2
c lint
e
s 00042/00010/00431
d D 4.2 83/06/13 00:00:29 sam 2 1
c someday I'll get all this correct (sigh)
e
s 00441/00000/00000
d D 4.1 83/03/31 21:08:09 sam 1 0
c date and time created 83/03/31 21:08:09 by sam
e
u
U
t
T
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
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
E 8

#include "pcl.h"
#if NPCL > 0
/*
 * DEC CSS PCL-11B Parallel Communications Interface
 *
D 4
 * Written by Mike Muuss.
E 4
I 4
 * Written by Mike Muuss and Jeff Schwab.
E 4
 */
#include "../machine/pte.h"

D 6
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/vmmac.h"
I 2
#include "../h/ioctl.h"
E 2
#include "../h/errno.h"
E 6
I 6
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "ioctl.h"
#include "errno.h"
E 6

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
I 9

I 12
#ifdef INET
E 12
D 10
#ifdef	BBNNET
#define	INET
#endif
E 10
E 9
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 12
#include "../netinet/in_var.h"
E 12
#include "../netinet/ip.h"
I 12
#endif
E 12
D 9
#include "../netinet/ip_var.h"
E 9

#include "../vax/cpu.h"
#include "../vax/mtpr.h"
D 6
#include "../vaxif/if_pclreg.h"
#include "../vaxif/if_uba.h"
E 6
I 6
#include "if_pclreg.h"
#include "if_uba.h"
E 6
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"

/* The MTU has been carefully selected to prevent fragmentation <-> ArpaNet */
D 4
#define	PCLMTU	(1006)		/* Max transmission unit (bytes) */
E 4
I 4
#define	PCLMTU		(1006)	/* Max transmission unit (bytes) */
#define	PCLMAXTDM	7	/* Max unit number on TDM bus */
E 4

int	pclprobe(), pclattach(), pclrint(), pclxint();
D 2
int	pclinit(),pcloutput(),pclreset();
E 2
I 2
int	pclinit(), pclioctl(), pcloutput(), pclreset();
E 2

struct	uba_device	*pclinfo[NPCL];
u_short pclstd[] = { 0 };
#define	PCLUNIT(x)	minor(x)
struct	uba_driver pcldriver =
	{ pclprobe, 0, pclattach, 0, pclstd, "pcl", pclinfo };

/*
 * PCL software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * sc_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 * We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
struct	pcl_softc {
	struct	ifnet sc_if;		/* network-visible interface */
	struct	ifuba sc_ifuba;		/* UNIBUS resources */
	short	sc_oactive;		/* is output active? */
	short	sc_olen;		/* length of last output */
	short	sc_lastdest;		/* previous destination */
	short	sc_odest;		/* current xmit destination */
I 4
	short	sc_bdest;		/* buffer's stated destination */
E 4
	short	sc_pattern;		/* identification pattern */
} pcl_softc[NPCL];

/*
 * Structure of "local header", which only goes between
 * pcloutput and pclstart.
 */
struct pcl_header {
	short	pcl_dest;		/* Destination PCL station */
};

/*
 * Do non-DMA output of 1 word to determine presence of interface,
 * and to find the interupt vector.  1 word messages are a special
 * case in the receiver routine, and will be discarded.
 */
pclprobe(reg)
	caddr_t reg;
{
	register int br, cvec;		/* r11, r10 value-result */
	register struct pcldevice *addr = (struct pcldevice *)reg;

#ifdef lint
	br = 0; cvec = br; br = cvec;
	pclrint(0); pclxint(0);
#endif
	addr->pcl_rcr = PCL_RCINIT;
	addr->pcl_tcr = PCL_TXINIT;
	addr->pcl_tsba = 0xFFFE;
	/* going for 01777776 */
	addr->pcl_tsbc = -4;		/* really short */
	addr->pcl_tcr =
	 ((1 & 0xF) << 8) | PCL_TXNPR | PCL_SNDWD | PCL_STTXM | PCL_IE | 0x0030;
	DELAY(100000);
	addr->pcl_tcr = PCL_TXINIT;
	return (sizeof (struct pcldevice));
}

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.
 */
pclattach(ui)
	struct uba_device *ui;
{
	register struct pcl_softc *sc = &pcl_softc[ui->ui_unit];
D 3
	register struct sockaddr_in *sin;
E 3

	sc->sc_if.if_unit = ui->ui_unit;
	sc->sc_if.if_name = "pcl";
	sc->sc_if.if_mtu = PCLMTU;
D 2
	/* copy network addr from flags long */
	sc->sc_if.if_net = in_netof(htonl(ui->ui_flags));
	sc->sc_if.if_host[0] = in_lnaof(htonl(ui->ui_flags));

	sin = (struct sockaddr_in *)&sc->sc_if.if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr.s_addr = htonl(ui->ui_flags);

E 2
	sc->sc_if.if_init = pclinit;
	sc->sc_if.if_output = pcloutput;
I 2
	sc->sc_if.if_ioctl = pclioctl;
E 2
	sc->sc_if.if_reset = pclreset;
I 7
	sc->sc_if.if_flags = IFF_BROADCAST;
E 7
	sc->sc_ifuba.ifu_flags = UBA_NEEDBDP;
	if_attach(&sc->sc_if);
}

/*
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
pclreset(unit, uban)
	int unit, uban;
{
	register struct uba_device *ui;

	if (unit >= NPCL || (ui = pclinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_ubanum != uban)
		return;
	printf(" pcl%d", unit);
	pclinit(unit);
}

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 */
pclinit(unit)
	int unit;
{
	register struct pcl_softc *sc = &pcl_softc[unit];
	register struct uba_device *ui = pclinfo[unit];
	register struct pcldevice *addr;
I 2
D 7
	struct sockaddr_in *sin;
E 7
E 2
	int s;

I 2
D 3
	sin = &sc->sc_if.if_addr;
E 3
I 3
D 7
	sin = (struct sockaddr_in *)&sc->sc_if.if_addr;
E 3
	if (sin->sin_addr.s_addr == 0)
E 7
I 7
	if (sc->sc_if.if_addrlist == (struct ifaddr *)0)
E 7
		return;
E 2
	if (if_ubainit(&sc->sc_ifuba, ui->ui_ubanum, 0,
	    (int)btoc(PCLMTU)) == 0) { 
		printf("pcl%d: can't init\n", unit);
D 7
		sc->sc_if.if_flags &= ~IFF_UP;
E 7
I 7
		sc->sc_if.if_flags &= ~(IFF_UP | IFF_RUNNING);
E 7
		return;
	}
I 7
	sc->sc_if.if_flags |= IFF_RUNNING;
E 7
	addr = (struct pcldevice *)ui->ui_addr;
	addr->pcl_rcr = PCL_RCINIT;
	addr->pcl_tcr = PCL_TXINIT;

	/*
	 * Hang a receive and start any
	 * pending writes by faking a transmit complete.
	 */
	s = splimp();
	addr->pcl_rdba = (short) sc->sc_ifuba.ifu_r.ifrw_info;
	addr->pcl_rdbc = -PCLMTU;
	addr->pcl_rcr = (((int)(sc->sc_ifuba.ifu_r.ifrw_info>>12))&0x0030) |
		PCL_RCNPR | PCL_RCVWD | PCL_RCVDAT | PCL_IE;
	sc->sc_oactive = 0;
D 2
	sc->sc_if.if_flags |= IFF_UP;		/* Mark interface up */
E 2
I 2
D 7
	sc->sc_if.if_flags |= IFF_UP|IFF_RUNNING;
E 7
E 2
	pclstart(unit);
	splx(s);
D 7
	/* Set up routing table entry */
	if_rtinit(&sc->sc_if, RTF_UP);
E 7
}

/*
 * PCL output routine.
 */
pcloutput(ifp, m, dst)
	struct ifnet *ifp;
	struct mbuf *m;
	struct sockaddr *dst;
{
D 3
	int type, dest, s, error;
E 3
I 3
	int dest, s, error;
E 3
	struct pcl_header *pclp;
	struct mbuf *m2;

	switch (dst->sa_family) {

#ifdef INET
	case AF_INET:
D 4
		dest = ((struct sockaddr_in *)dst)->sin_addr.s_addr;
D 3
		dest = ntohl(dest);	/* ??? */
E 3
I 3
		dest = ntohl((u_long)dest);	/* ??? */
E 3
		dest = dest & 0xff;
E 4
I 4
D 7
		dest = in_lnaof(((struct sockaddr_in *)dst)->sin_addr);
E 7
I 7
		if (in_broadcast(((struct sockaddr_in *)dst)->sin_addr))
			dest = 0;
		else
			dest = in_lnaof(((struct sockaddr_in *)dst)->sin_addr);
E 7
		if (dest > PCLMAXTDM) {
			error = EHOSTUNREACH;
			goto bad;
		}
E 4
		break;
#endif
	default:
		printf("pcl%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
		error = EAFNOSUPPORT;
		goto bad;
	}

	/*
	 * Add pseudo local net header.
	 * Actually, it does not get transmitted, but merely stripped
	 * off and used by the START routine to route the packet.
	 * If no space in first mbuf, allocate another.
	 */
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof (struct pcl_header) > m->m_off) {
		m2 = m_get(M_DONTWAIT, MT_HEADER);
		if (m2 == 0) {
			error = ENOBUFS;
			goto bad;
		}
		m2->m_next = m;
		m2->m_off = MMINOFF;
		m2->m_len = sizeof (struct pcl_header);
		m = m2;
	} else {
		m->m_off -= sizeof (struct pcl_header);
		m->m_len += sizeof (struct pcl_header);
	}
	pclp = mtod(m, struct pcl_header *);
	pclp->pcl_dest = dest;

	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
	s = splimp();
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
		error = ENOBUFS;
		goto qfull;
	}
	IF_ENQUEUE(&ifp->if_snd, m);
	if (pcl_softc[ifp->if_unit].sc_oactive == 0)
		pclstart(ifp->if_unit);
	splx(s);
	return (0);
qfull:
	splx(s);
bad:
	m_freem(m);
	return (error);
}

/*
 * Start or restart output on interface.
 * If interface is already active, then this is a retransmit.
 * If interface is not already active, get another datagram
 * to send off of the interface queue, and map it to the interface
 * before starting the output.
 */
pclstart(dev)
	dev_t dev;
{
        int unit = PCLUNIT(dev);
	struct uba_device *ui = pclinfo[unit];
	register struct pcl_softc *sc = &pcl_softc[unit];
	register struct pcldevice *addr;
	struct mbuf *m;

	if (sc->sc_oactive)
		goto restart;

	/*
	 * Not already active: dequeue another request
	 * and map it to the UNIBUS.  If no more requests,
	 * just return.
	 */
	IF_DEQUEUE(&sc->sc_if.if_snd, m);
	if (m == 0) {
		sc->sc_oactive = 0;
		return;
	}

	/*
	 * Pull destination node out of pseudo-local net header.
	 * remove it from outbound data.
	 * Note that if_wubaput calls m_bcopy, which is prepared for
	 * m_len to be 0 in the first mbuf in the chain.
	 */
D 4
	sc->sc_odest = mtod(m, struct pcl_header *)->pcl_dest;
E 4
I 4
	sc->sc_bdest = mtod(m, struct pcl_header *)->pcl_dest;
	sc->sc_odest = sc->sc_bdest? sc->sc_bdest: 1;
E 4
	m->m_off += sizeof (struct pcl_header);
	m->m_len -= sizeof (struct pcl_header);

	/* Map out to the DMA area */
	sc->sc_olen = if_wubaput(&sc->sc_ifuba, m);

restart:
	/*
	 * Have request mapped to UNIBUS for transmission.
D 4
	 * Purge any stale data from this BDP, and start the otput.
E 4
I 4
	 * Purge any stale data from this BDP, and start the output.
E 4
	 */
	if (sc->sc_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(sc->sc_ifuba.ifu_uba, sc->sc_ifuba.ifu_w.ifrw_bdp);
	addr = (struct pcldevice *)ui->ui_addr;
	addr->pcl_tcr = PCL_TXINIT;
	addr->pcl_tsba = (int)sc->sc_ifuba.ifu_w.ifrw_info;
	addr->pcl_tsbc = -sc->sc_olen;

	/*
	 * RIB (retry if busy) is used on the second and subsequent packets
	 * to a single host, because TCP often wants to transmit multiple
	 * buffers in a row,
	 * and if they are all going to the same place, the second and
	 * subsequent ones may be lost due to receiver not ready again yet.
	 * This can cause serious problems, because the TCP will resend the
	 * whole window, which just repeats the problem.  The result is that
	 * a perfectly good link appears not to work unless we take steps here.
	 */
	addr->pcl_tcr = (((int)(sc->sc_ifuba.ifu_w.ifrw_info>>12))&0x0030) |
		((sc->sc_odest & 0xF)<<8) |
		PCL_TXNPR | PCL_SNDWD | PCL_STTXM | PCL_IE |
		(sc->sc_odest == sc->sc_lastdest ? PCL_RIB : 0);
	sc->sc_lastdest = sc->sc_odest;
	sc->sc_oactive = 1;
}

/*
 * PCL transmitter interrupt.
 * Start another output if more data to send.
 */
pclxint(unit)
	int unit;
{
	register struct uba_device *ui = pclinfo[unit];
	register struct pcl_softc *sc = &pcl_softc[unit];
	register struct pcldevice *addr = (struct pcldevice *)ui->ui_addr;

	if (sc->sc_oactive == 0) {
		printf ("pcl%d: stray interrupt\n", unit);
		return;
	}
	if (addr->pcl_tsr & PCL_ERR) {
		sc->sc_lastdest = 0;		/* don't bother with RIB */
		if (addr->pcl_tsr & PCL_MSTDWN) {
			addr->pcl_tmmr = PCL_MASTER|PCL_AUTOADDR;
			pclstart(unit);	/* Retry */
			printf("pcl%d: master\n", unit );
			return;
		}
D 4
		if (addr->pcl_tsr & PCL_RESPB) {
E 4
I 4
#ifndef PCL_TESTING
		if ((addr->pcl_tsr & (PCL_ERR|PCL_RESPB)) == (PCL_ERR|0))  {
			;	/* Receiver Offline -- not exactly an error */
		}  else  {
#else
		{
#endif
E 4
			/* Log as an error */
			printf("pcl%d: send error, tcr=%b tsr=%b\n",
				unit, addr->pcl_tcr, PCL_TCSRBITS,
				addr->pcl_tsr, PCL_TERRBITS);
			sc->sc_if.if_oerrors++;
		}
	} else
		sc->sc_if.if_opackets++;
D 4
	sc->sc_oactive = 0;
	if (sc->sc_ifuba.ifu_xtofree) {
		m_freem(sc->sc_ifuba.ifu_xtofree);
		sc->sc_ifuba.ifu_xtofree = 0;
E 4
I 4
	if (sc->sc_bdest == 0 && sc->sc_odest < PCLMAXTDM) {
		sc->sc_odest++;		/* do next host (broadcast) */
	} else {
		sc->sc_oactive = 0;
		if (sc->sc_ifuba.ifu_xtofree) {
			m_freem(sc->sc_ifuba.ifu_xtofree);
			sc->sc_ifuba.ifu_xtofree = 0;
		}
E 4
	}
	pclstart(unit);
}

/*
 * PCL interface receiver interrupt.
 * If input error just drop packet.
 */
pclrint(unit)
	int unit;
{
	register struct pcl_softc *sc = &pcl_softc[unit];
	struct pcldevice *addr = (struct pcldevice *)pclinfo[unit]->ui_addr;
    	struct mbuf *m;
D 3
	int len, plen; short resid;
E 3
I 3
	int len;
E 3
	register struct ifqueue *inq;
D 3
	int off;
E 3

	sc->sc_if.if_ipackets++;
	/*
	 * Purge BDP; drop if input error indicated.
	 */
	if (sc->sc_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(sc->sc_ifuba.ifu_uba, sc->sc_ifuba.ifu_r.ifrw_bdp);
	if (addr->pcl_rsr & PCL_ERR) {
		printf("pcl%d: rcv error, rcr=%b rsr=%b\n",
			unit, addr->pcl_rcr, PCL_RCSRBITS,
			addr->pcl_rsr, PCL_RERRBITS);
		sc->sc_if.if_ierrors++;
		goto setup;
	}
	len = PCLMTU + addr->pcl_rdbc;
	if (len <= 0 || len > PCLMTU) {
		printf("pcl%d: bad len=%d.\n", unit, len);
		sc->sc_if.if_ierrors++;
		goto setup;
	}

	/* Really short packets will be part of the startup sequence */
	if (len <= 4) {
		/* Later, do comming-up processing here */
		goto setup;	/* drop packet */
	}

	/*
	 * Pull packet off interface.
	 */
D 9
	m = if_rubaget(&sc->sc_ifuba, len, 0);
E 9
I 9
	m = if_rubaget(&sc->sc_ifuba, len, 0, &sc->sc_if);
E 9
	if (m == 0)
		goto setup;

	schednetisr(NETISR_IP);
	inq = &ipintrq;

	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		m_freem(m);
	} else
		IF_ENQUEUE(inq, m);
setup:
	/*
	 * Reset for next packet.
	 */
	addr->pcl_rcr = PCL_RCINIT;
	addr->pcl_rdba = (int)sc->sc_ifuba.ifu_r.ifrw_info;
	addr->pcl_rdbc = -PCLMTU;
	addr->pcl_rcr = (((int)(sc->sc_ifuba.ifu_w.ifrw_info>>12))&0x0030) |
		PCL_RCNPR | PCL_RCVWD | PCL_RCVDAT | PCL_IE;
I 2
}

/*
 * Process an ioctl request.
 */
I 11
/* ARGSUSED */
E 11
pclioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 7
	struct ifreq *ifr = (struct ifreq *)data;
	struct sockaddr_in *sin;
E 7
	int s = splimp(), error = 0;

	switch (cmd) {

	case SIOCSIFADDR:
I 9
		ifp->if_flags |= IFF_UP;
E 9
D 7
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
		sin = (struct sockaddr_in *)&ifr->ifr_addr;
D 3
		ifp->if_addr = *sin;
E 3
I 3
		ifp->if_addr = *(struct sockaddr *)sin;
E 3
		ifp->if_net = in_netof(sin->sin_addr);
		ifp->if_host[0] = in_lnaof(sin->sin_addr);
I 4
		ifp->if_broadaddr = *(struct sockaddr *)sin;
		sin = (struct sockaddr_in *)&ifp->if_broadaddr;
		sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
		ifp->if_flags |= IFF_BROADCAST;
E 4
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, RTF_UP);
		else
E 7
I 7
		if ((ifp->if_flags & IFF_RUNNING) == 0)
E 7
			pclinit(ifp->if_unit);
I 7
D 9
		ifp->if_flags |= IFF_UP;
E 9
E 7
		break;

	default:
		error = EINVAL;
	}
	splx(s);
	return (error);
E 2
}
#endif
E 1
