h21165
s 00010/00005/00860
d D 7.2 88/06/29 17:36:09 bostic 15 14
c install approved copyright notice
e
s 00013/00001/00852
d D 7.1 88/05/21 18:30:59 karels 14 13
c bring up to revision 7 for tahoe release
e
s 00005/00001/00848
d D 1.13 87/06/30 23:38:28 karels 13 12
c vbmemalloc has a return now
e
s 00002/00002/00847
d D 1.12 86/12/15 20:25:59 sam 12 11
c lint
e
s 00003/00002/00846
d D 1.11 86/11/29 13:45:09 sam 11 10
c ci for karels; include cpu.h
e
s 00008/00015/00840
d D 1.10 86/07/16 08:29:33 sam 10 9
c use clusters if data fills >= 1/2 cluster
e
s 00039/00036/00816
d D 1.9 86/06/09 22:21:57 sam 9 8
c don't presume station address is inverted on entry to acesetaddr; 
c don't set station address at boot until told to do so with ifconfig; add 
c print at boot and each time station address is set; rearrange some crud and 
c delete other cruft
e
s 00001/00001/00851
d D 1.8 86/01/26 15:32:22 sam 8 7
c remove acestd's as autoconfig doesn't yet check for previously allocated csr's
e
s 00003/00004/00849
d D 1.7 86/01/24 01:14:58 sam 7 6
c negotiate trailer use
e
s 00005/00005/00848
d D 1.6 86/01/21 22:08:50 sam 6 5
c make xns compile
e
s 00000/00039/00853
d D 1.5 86/01/21 10:01:07 sam 5 4
c remove sizeof workarounds
e
s 00031/00048/00861
d D 1.4 86/01/20 23:56:27 sam 4 3
c eliminate built in config tables: page table are allocated at 
c boot time with ubmemalloc, dpm addresses are passed thru from config file;
c eliminate aceStart; rename aceclean to acesetup and call only at init time 
c (since we allocate dpm page tables at attach time)
e
s 00105/00047/00804
d D 1.3 86/01/12 15:46:06 sam 3 2
c 4.3- plus start of autoconfig
e
s 00103/00128/00748
d D 1.2 86/01/05 18:52:28 sam 2 1
c 1st working version (mostly)
e
s 00876/00000/00000
d D 1.1 85/07/21 21:14:28 sam 1 0
c date and time created 85/07/21 21:14:28 by sam
e
u
U
t
T
I 1
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
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
 *	%W% (Berkeley) %G%
 */
E 14

/*
 * ACC VERSAbus Ethernet controller
 */
#include "ace.h"
#if NACE > 0

D 11
#include "../machine/pte.h"

E 11
D 2
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/vmmac.h"
#include "../h/ioctl.h"
#include "../h/errno.h"
#include "../h/vmparam.h"
E 2
I 2
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "ioctl.h"
#include "errno.h"
#include "vmparam.h"
I 3
#include "syslog.h"
E 3
E 2

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
I 3
#ifdef INET
E 3
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 2
#include "../netinet/in_var.h"
E 2
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/if_ether.h"
I 3
#endif
#ifdef NS
#include "../netns/ns.h"
#include "../netns/ns_if.h"
#endif
I 11

#include "../machine/cpu.h"
#include "../machine/pte.h"
E 11
E 3
D 2
#include "../netpup/pup.h"
E 2

#include "../tahoe/mtpr.h"
#include "../tahoeif/if_acereg.h"
D 2
#include "../vba/vbavar.h"
E 2
I 2
#include "../tahoevba/vbavar.h"
E 2

D 3
#define	LONET	124

E 3
D 4
/*
 * Configuration table, for 2 units (should be defined by config)
 */
D 3
#define	ACEVECTOR	0x90
long	acestd[] = { 0x0ff0000, 0xff0100 };		/* controller */

E 3
extern	char ace0utl[], ace1utl[];			/* dpm */
char	*acemap[]= { ace0utl, ace1utl };
D 2
extern	long ACE0map[], ACE1map[];
long	*ACEmap[] = { ACE0map, ACE1map };
long	ACEmapa[] = { 0xfff80000, 0xfff90000 };
E 2
I 2
extern	struct pte ACE0map[], ACE1map[];
struct	pte *ACEmap[] = { ACE0map, ACE1map };
caddr_t	ACEmapa[] = { (caddr_t)0xfff80000, (caddr_t)0xfff90000 };
E 2

E 4
D 9
/* station address */
char	ace_station[6] = { ~0x8, ~0x0, ~0x3, ~0x0, ~0x0, ~0x1 };
/* multicast hash table initializer */
char	ace_hash[8] = { ~0xF,~0xF,~0xF,~0xF,~0xF,~0xF,~0xF,~0xF };
/* backoff table masks */
short random_mask_tbl[16] = {
	0x0040, 0x00C0, 0x01C0, 0x03C0, 0x07C0, 0x0FC0, 0x1FC0, 0x3FC0,
	0x7FC0, 0xFFC0, 0xFFC0, 0xFFC0, 0xFFC0, 0xFFC0, 0xFFC0, 0xFFC0
};

E 9
int	aceprobe(), aceattach(), acerint(), acecint();
struct	vba_device *aceinfo[NACE];
I 3
D 8
long	acestd[] = { 0x0ff0000, 0xff0100, 0 };
E 8
I 8
long	acestd[] = { 0 };
E 8
E 3
struct	vba_driver acedriver =
D 4
	{ aceprobe, 0,aceattach,0,acestd,"ace",aceinfo,"v/eiu",0 };
	
#define	ACEUNIT(x)	minor(x)
E 4
I 4
    { aceprobe, 0, aceattach, 0, acestd, "ace", aceinfo, "v/eiu", 0 };
E 4

int	aceinit(), aceoutput(), aceioctl(), acereset();
struct	mbuf *aceget();

/*
 * Ethernet software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * is_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 */
struct	ace_softc {
	struct	arpcom is_ac;		/* Ethernet common part	*/
#define	is_if	is_ac.ac_if		/* network-visible interface */
#define	is_addr	is_ac.ac_enaddr		/* hardware Ethernet address */
D 4
	char	*is_dpm;
E 4
	short	is_flags;
#define	ACEF_OACTIVE	0x1		/* output is active */
#define	ACEF_RCVPENDING	0x2		/* start rcv in acecint	*/
	short	is_promiscuous;		/* true is enabled */
	short	is_segboundry;		/* first TX Seg in dpm */
	short	is_eictr;		/* Rx segment tracking ctr */
	short	is_eoctr;		/* Tx segment tracking ctr */
	short	is_txnext;		/* Next available Tx segment */
	short	is_currnd;		/* current random backoff */
	struct	ace_stats is_stats;	/* holds board statistics */
	short	is_xcnt;		/* count xmitted segments to be acked 
					   by the controller */
I 3
	long	is_ivec;		/* autoconfig interrupt vector base */
I 4
	struct	pte *is_map;		/* pte map for dual ported memory */
	caddr_t	is_dpm;			/* address of mapped memory */
E 4
E 3
} ace_softc[NACE];
extern	struct ifnet loif;

D 3
aceprobe(reg)
E 3
I 3
aceprobe(reg, vi)
E 3
	caddr_t reg;
I 3
	struct vba_device *vi;
E 3
{
D 3
	register struct acedevice *addr = (struct acedevice *)reg;
E 3
I 3
	register br, cvec;		/* must be r12, r11 */
	struct acedevice *ap = (struct acedevice *)reg;
	struct ace_softc *is = &ace_softc[vi->ui_unit];
E 3

#ifdef lint
I 12
	br = 0; cvec = br; br = cvec;
E 12
	acerint(0); acecint(0);
#endif
	if (badaddr(reg, 2))
D 3
		return(0);
D 2
	movew((short)CSR_RESET, &addr->csr);
E 2
I 2
	movow(&addr->csr, CSR_RESET);
E 3
I 3
		return (0);
	movow(&ap->csr, CSR_RESET);
E 3
E 2
	DELAY(10000);
D 3
	return (sizeof (struct acedevice));
E 3
I 3
#ifdef notdef
	/*
	 * Select two spaces for the interrupts aligned to an
	 * eight vector boundary and fitting in 8 bits (as
	 * required by the controller) -- YECH.  The controller
	 * will be notified later at initialization time.
	 */
	if ((vi->ui_hd->vh_lastiv -= 2) > 0xff)
		vi->ui_hd->vh_lastiv  = 0x200;
	is->is_ivec = vi->ui_hd->vh_lastiv = vi->ui_hd->vh_lastiv &~ 0x7;
#else
	is->is_ivec = 0x90+vi->ui_unit*8;
#endif
	br = 0x14, cvec = is->is_ivec;		/* XXX */
	return (sizeof (*ap));
E 3
}

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.
 */
aceattach(ui)
	struct vba_device *ui;
{
	register short unit = ui->ui_unit;
	register struct ace_softc *is = &ace_softc[unit];
	register struct ifnet *ifp = &is->is_if;
	register struct acedevice *addr = (struct acedevice *)ui->ui_addr;
	register short *wp, i;
I 9
D 12
	char *cp;
E 12
E 9
D 2
	struct sockaddr_in *sin;
E 2

	ifp->if_unit = unit;
	ifp->if_name = "ace";
	ifp->if_mtu = ETHERMTU;
	/*
D 4
	 * Set station's addresses, multicast
	 * hash table, and initialize dual ported memory.
E 4
I 4
D 9
	 * Set station's addresses and multicast hash table.
E 9
I 9
	 * Get station's addresses and set multicast hash table.
E 9
E 4
	 */
D 9
	ace_station[5] = ~(unit + 1);
	acesetetaddr(unit, addr, ace_station);
E 9
I 9
	for (wp = (short *)addr->station, i = 0; i < 6; i++)
		is->is_addr[i] = ~*wp++;
	printf("ace%d: hardware address %s\n", unit,
	    ether_sprintf(is->is_addr));
E 9
	is->is_promiscuous = 0;
D 9
	wp = (short *)addr->hash;
	for (i =  0; i < 8; i++)
D 2
		movew((short)ace_hash[i], wp++); 
	movew((short)~0xffff, &addr->bcastena[0]); 
	movew((short)~0xffff, &addr->bcastena[1]);
E 2
I 2
		movow(wp++, ace_hash[i]); 
E 9
I 9
	for (wp = (short *)addr->hash, i =  0; i < 8; i++)
		movow(wp++, ~0xf); 
E 9
	movow(&addr->bcastena[0], ~0xffff); 
	movow(&addr->bcastena[1], ~0xffff);
E 2
D 4
	aceclean(unit);
E 4
I 4
	/*
	 * Allocate and map dual ported VERSAbus memory.
	 */
D 13
	vbmemalloc(32, (caddr_t)ui->ui_flags, &is->is_map, &is->is_dpm);
E 13
I 13
	if (vbmemalloc(32, (caddr_t)ui->ui_flags,
	    &is->is_map, &is->is_dpm) == 0) {
		printf("ace%d: can't allocate VERSAbus memory map\n", unit);
		return;
	}
E 13

E 4
D 2
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
E 2
	ifp->if_init = aceinit;
	ifp->if_output = aceoutput;
	ifp->if_ioctl = aceioctl;
	ifp->if_reset = acereset;
I 2
	ifp->if_flags = IFF_BROADCAST;
E 2
	if_attach(ifp);
}

D 9
acesetetaddr(unit, addr, station_addr)
	short unit;
	struct acedevice *addr;
	char *station_addr;
{
	register short *wp, i;
	register char *cp;
	struct ace_softc *is = &ace_softc[unit];

	wp = (short *)addr->station;
	cp = station_addr;
	for (i = 0; i < 6; i++)
D 2
		movew((short)*cp++, wp++); 
E 2
I 2
		movow(wp++, *cp++); 
E 2
	wp = (short *)addr->station;
D 2
	cp = (char *)&is->is_addr;
E 2
I 2
	cp = (char *)is->is_addr;
E 2
	for (i = 0; i < 6; i++)
		*cp++ = ~(*wp++);
}

E 9
/*
 * Reset of interface after "system" reset.
 */
acereset(unit, vban)
	int unit, vban;
{
	register struct vba_device *ui;

	if (unit >= NACE || (ui = aceinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_vbanum != vban)
		return;
	printf(" ace%d", unit);
	aceinit(unit);
}

/*
 * Initialization of interface; clear recorded pending operations
 */
aceinit(unit)
	int unit;
{
	register struct ace_softc *is = &ace_softc[unit];
	register struct vba_device *ui = aceinfo[unit];
	register struct acedevice *addr;
	register struct ifnet *ifp = &is->is_if;
D 2
	register struct sockaddr_in *sin;
E 2
	register short Csr;
D 2
	register int i, s;
E 2
I 2
	register int s;
E 2

D 2
	sin = (struct sockaddr_in *)&ifp->if_addr;
	if (sin->sin_addr.s_addr == 0)		/* address still unknown */
E 2
I 2
	if (ifp->if_addrlist == (struct ifaddr *)0)
E 2
		return;
	if ((ifp->if_flags & IFF_RUNNING) == 0) {
		/*
		 * Reset the controller, initialize the recieve buffers,
		 * and turn the controller on again and set board online.
		 */
		addr = (struct acedevice *)ui->ui_addr;
		s = splimp();
D 2
		movew((short)CSR_RESET, &addr->csr);
E 2
I 2
		movow(&addr->csr, CSR_RESET);
E 2
		DELAY(10000);

		/*
D 4
		 * clean up dpm since the controller might
		 * jumble dpm after reset
E 4
I 4
		 * Clean up dpm since the controller might
		 * jumble dpm after reset.
E 4
		 */
D 4
		aceclean(unit);
E 4
I 4
		acesetup(unit);
E 4
D 2
		movew((short)CSR_GO, &addr->csr);
E 2
I 2
		movow(&addr->csr, CSR_GO);
E 2
		Csr = addr->csr;
		if (Csr & CSR_ACTIVE) {
D 2
			movew((short)(ACEVECTOR + unit*8), &addr->ivct);
E 2
I 2
D 3
			movow(&addr->ivct, ACEVECTOR + unit*8);
E 3
I 3
			movow(&addr->ivct, is->is_ivec);
E 3
E 2
			Csr |= CSR_IENA | is->is_promiscuous;
I 2
D 3
#ifdef notdef
E 2
			if (ifp->if_net == LONET)
				Csr |= CSR_LOOP3;
D 2
			movew(Csr, &addr->csr);
E 2
I 2
#endif
E 3
			movow(&addr->csr, Csr);
E 2
			is->is_flags = 0;
			is->is_xcnt = 0;
D 2
			is->is_if.if_flags |= IFF_UP|IFF_RUNNING;
E 2
I 2
			is->is_if.if_flags |= IFF_RUNNING;
E 2
		}
		splx(s);
	}
D 2

	if (is->is_if.if_flags & IFF_UP) {
		if_rtinit(&is->is_if, RTF_UP);
E 2
I 2
	if (is->is_if.if_snd.ifq_head)
E 2
D 4
		aceStart(unit);
E 4
I 4
		acestart(unit);
E 4
D 2
	}
	arpwhohas(&is->is_ac, &sin->sin_addr);
E 2
}

/*
 * Start output on interface.
 * Get another datagram to send off of the interface queue,
 * and map it to the interface before starting the output.
D 10
 *
E 10
 */
D 4
acestart(dev)
	dev_t dev;
E 4
I 4
acestart(unit)
	int unit;
E 4
{
	register struct tx_segment *txs;
D 2
	register long len, x;
E 2
I 2
	register long len;
	register int s;
E 2
D 4
	int unit = ACEUNIT(dev);
E 4
D 2
	struct vba_device *ui = aceinfo[unit];
	register struct acedevice *addr = (struct acedevice *)ui->ui_addr;
E 2
	register struct ace_softc *is = &ace_softc[unit];
	struct mbuf *m;
D 2
	short retries, idx;
E 2
I 2
	short retries;
E 2

I 4
	if (is->is_flags & ACEF_OACTIVE)
		return;
	is->is_flags |= ACEF_OACTIVE;
E 4
again:
	txs = (struct tx_segment*)(is->is_dpm + (is->is_txnext << 11));
	if (txs->tx_csr & TCS_TBFULL) {
		is->is_stats.tx_busy++;
I 4
		is->is_flags &= ~ACEF_OACTIVE;
E 4
		return;
	}
D 2
	x = splimp();
E 2
I 2
	s = splimp();
E 2
	IF_DEQUEUE(&is->is_if.if_snd, m);
D 2
	splx(x);
E 2
I 2
	splx(s);
E 2
D 4
	if (m == 0)
E 4
I 4
	if (m == 0) {
		is->is_flags &= ~ACEF_OACTIVE;
E 4
		return;
I 4
	}
E 4
	len = aceput(unit, txs->tx_data, m);
	retries = txs->tx_csr & TCS_RTC;
	if (retries > 0)
		acebakoff(is, txs, retries);

	/*
	 * Ensure minimum packet length.
	 * This makes the safe assumtion that there are no virtual holes
	 * after the data.
	 * For security, it might be wise to zero out the added bytes,
	 * but we're mainly interested in speed at the moment.
	 */
D 5
#ifdef notdef
E 5
	if (len - sizeof (struct ether_header) < ETHERMIN)
		len = ETHERMIN + sizeof (struct ether_header);
D 5
#else
	if (len - 14 < ETHERMIN)
		len = ETHERMIN + 14;
#endif
E 5
	if (++is->is_txnext > SEG_MAX) 
		is->is_txnext = is->is_segboundry;
	is->is_if.if_opackets++;
	is->is_xcnt++;
	len = (len & 0x7fff) | TCS_TBFULL;
D 2
	movew((short)len, txs);
E 2
I 2
	movow(txs, len);
E 2
	goto again;
}

/*
 * Transmit done interrupt.
 */
acecint(unit)
	int unit;
{
	register struct ace_softc *is = &ace_softc[unit];
D 2
	struct vba_device *ui = aceinfo[unit];
	register struct acedevice *addr = (struct acedevice *)ui->ui_addr;
E 2
	register struct tx_segment *txseg;
D 2
	short txidx, eostat;
E 2
I 2
	short eostat;
E 2

	if (is->is_xcnt <= 0)  {
D 2
		txidx = (addr->tseg >> 11) & 0xf;
E 2
D 3
		printf("ace%d: stray xmit interrupt, xcnt %d\n",
E 3
I 3
		log(LOG_ERR, "ace%d: stray xmit interrupt, xcnt %d\n",
E 3
		    unit, is->is_xcnt);
		is->is_xcnt = 0;
D 2
		aceStart(unit);
E 2
I 2
		if (is->is_if.if_snd.ifq_head)
D 4
			aceStart(unit);
E 4
I 4
			acestart(unit);
E 4
E 2
		return;
	}
	is->is_xcnt--;
	txseg = (struct tx_segment *)((is->is_eoctr << 11) + is->is_dpm);
	eostat = txseg->tx_csr;
	if ((eostat & TCS_TBFULL) == 0) {
		is->is_stats.tx_retries += eostat & TCS_RTC;
		if (eostat & TCS_RTFAIL)  {
			is->is_stats.tx_discarded++;
			is->is_if.if_oerrors++;
		} else 
			is->is_stats.tx_datagrams++;
		if (++is->is_eoctr >= 16)
			is->is_eoctr = is->is_segboundry; 
	} 
D 2
	aceStart(unit);
E 2
I 2
	if (is->is_if.if_snd.ifq_head)
D 4
		aceStart(unit);
E 4
I 4
		acestart(unit);
E 4
E 2
}

/*
 * Ethernet interface receiver interrupt.
 * If input error just drop packet.
 * Otherwise purge input buffered data path and examine 
 * packet to determine type.  If can't determine length
 * from type, then have to drop packet.  Othewise decapsulate
 * packet based on type and pass to type specific higher-level
 * input routine.
 */
acerint(unit)
	int unit;
{
	register struct ace_softc *is = &ace_softc[unit];
	register struct ifqueue *inq;
	register struct ether_header *ace;
	register struct rx_segment *rxseg;
D 2
	struct acedevice *addr = (struct acedevice *)aceinfo[unit]->ui_addr;
E 2
	int len, s, off, resid;
	struct mbuf *m;
	short eistat;

I 2
	if ((is->is_if.if_flags&IFF_RUNNING) == 0)
		return;
E 2
again:
	rxseg = (struct rx_segment *)((is->is_eictr << 11) + is->is_dpm);
	eistat = rxseg->rx_csr;
	if ((eistat & RCS_RBFULL) == 0)
		return;
	is->is_if.if_ipackets++;
	if (++is->is_eictr >= is->is_segboundry) 
		is->is_eictr = 0;
	len = eistat & RCS_RBC;
	if ((eistat & (RCS_ROVRN | RCS_RCRC | RCS_RODD)) ||
	    len < ET_MINLEN || len > ET_MAXLEN+CRC_SIZE) {
		if (eistat & RCS_ROVRN)
			is->is_stats.rx_overruns++;
		if (eistat & RCS_RCRC)
			is->is_stats.rx_crc_errors++;
		if (eistat & RCS_RODD)
			is->is_stats.rx_align_errors++;
		if (len < ET_MINLEN)
			is->is_stats.rx_underruns++;
		if (len > ET_MAXLEN+CRC_SIZE)
			is->is_stats.rx_overruns++;
		is->is_if.if_ierrors++;
		rxseg->rx_csr = 0;
		return;
	} else
		is->is_stats.rx_datagrams++;
	ace = (struct ether_header *)rxseg->rx_data;
D 5
#ifdef notdef
E 5
	len -= sizeof (struct ether_header);
D 5
#else
	len -= 14;
#endif
E 5
	/*
D 2
	 * Deal with trailer protocol: if type is PUP trailer
E 2
I 2
	 * Deal with trailer protocol: if type is trailer
E 2
	 * get true type from first 16-bit word past data.
	 * Remember that type was trailer by setting off.
	 */
	ace->ether_type = ntohs((u_short)ace->ether_type);
D 5
#ifdef notdef
E 5
#define	acedataaddr(ace, off, type) \
    ((type)(((caddr_t)(((char *)ace)+sizeof (struct ether_header))+(off))))
D 5
#else
#define	acedataaddr(ace, off, type) \
    ((type)(((caddr_t)(((char *)ace)+14)+(off))))
#endif
E 5
D 2
	if (ace->ether_type >= ETHERPUP_TRAIL &&
	    ace->ether_type < ETHERPUP_TRAIL+ETHERPUP_NTRAILER) {
		off = (ace->ether_type - ETHERPUP_TRAIL) * 512;
E 2
I 2
	if (ace->ether_type >= ETHERTYPE_TRAIL &&
	    ace->ether_type < ETHERTYPE_TRAIL+ETHERTYPE_NTRAILER) {
		off = (ace->ether_type - ETHERTYPE_TRAIL) * 512;
E 2
		if (off >= ETHERMTU)
			goto setup;		/* sanity */
		ace->ether_type = ntohs(*acedataaddr(ace, off, u_short *));
		resid = ntohs(*(acedataaddr(ace, off+2, u_short *)));
		if (off + resid > len)
			goto setup;		/* sanity */
		len = off + resid;
	} else
		off = 0;
	if (len == 0)
		goto setup;

	/*
	 * Pull packet off interface.  Off is nonzero if packet
	 * has trailing header; aceget will then force this header
	 * information to be at the front, but we still have to drop
	 * the type and length which are at the front of any trailer data.
	 */
D 2
	m = aceget(unit, rxseg->rx_data, len, off);
E 2
I 2
D 3
	m = aceget(unit, (u_char *)rxseg->rx_data, len, off);
E 3
I 3
	m = aceget((u_char *)rxseg->rx_data, len, off, &is->is_if);
E 3
E 2
	if (m == 0)
		goto setup;
	if (off) {
I 3
		struct ifnet *ifp;

		ifp = *(mtod(m, struct ifnet **));
E 3
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
I 3
		*(mtod(m, struct ifnet **)) = ifp;
E 3
	}
	switch (ace->ether_type) {

#ifdef INET
D 2
	case ETHERPUP_IPTYPE:
E 2
I 2
	case ETHERTYPE_IP:
E 2
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;
I 3
#endif
E 3

D 2
	case ETHERPUP_ARPTYPE:
E 2
I 2
	case ETHERTYPE_ARP:
E 2
		arpinput(&is->is_ac, m);
		goto setup;
D 3
#endif
E 3
I 2
#ifdef NS
	case ETHERTYPE_NS:
		schednetisr(NETISR_NS);
		inq = &nsintrq;
		break;

#endif
E 2
	default:
		m_freem(m);
		goto setup;
	}
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		m_freem(m);
		goto setup;
	}
	s = splimp();
	IF_ENQUEUE(inq, m);
	splx(s);
setup:
	rxseg->rx_csr = 0;
	goto again;
}

/*
 * Ethernet output routine.
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
 */
aceoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
	register struct ace_softc *is = &ace_softc[ifp->if_unit];
	register struct mbuf *m = m0;
	register struct ether_header *ace;
	register int off;
	struct mbuf *mcopy = (struct mbuf *)0;
D 7
	int type, s, error;
E 7
I 7
	int type, s, error, usetrailers;
E 7
D 2
	struct ether_addr edst;
E 2
I 2
	u_char edst[6];
E 2
	struct in_addr idst;

I 3
	if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) != (IFF_UP|IFF_RUNNING)) {
		error = ENETDOWN;
		goto bad;
	}
E 3
	switch (dst->sa_family) {

#ifdef INET
	case AF_INET:
		idst = ((struct sockaddr_in *)dst)->sin_addr;
D 2
		if (!arpresolve(&is->is_ac, m, &idst, &edst))
E 2
I 2
D 7
		if (!arpresolve(&is->is_ac, m, &idst, edst))
E 7
I 7
		if (!arpresolve(&is->is_ac, m, &idst, edst, &usetrailers))
E 7
E 2
			return (0);	/* if not yet resolved */
D 2
		if (in_lnaof(idst) == INADDR_ANY)
E 2
I 2
		if (!bcmp((caddr_t)edst, (caddr_t)etherbroadcastaddr,
D 6
		    sizeof(edst)))
E 6
I 6
		    sizeof (edst)))
E 6
E 2
			mcopy = m_copy(m, 0, (int)M_COPYALL);
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
D 10
		/* need per host negotiation */
E 10
D 7
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0 && off > 0 &&
		    (off & 0x1ff) == 0 &&
E 7
I 7
		if (usetrailers && off > 0 && (off & 0x1ff) == 0 &&
E 7
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
D 2
			type = ETHERPUP_TRAIL + (off>>9);
E 2
I 2
			type = ETHERTYPE_TRAIL + (off>>9);
E 2
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
D 2
			*mtod(m, u_short *) = htons((u_short)ETHERPUP_IPTYPE);
E 2
I 2
			*mtod(m, u_short *) = htons((u_short)ETHERTYPE_IP);
E 2
			*(mtod(m, u_short *) + 1) = htons((u_short)m->m_len);
			goto gottrailertype;
		}
D 2
		type = ETHERPUP_IPTYPE;
E 2
I 2
		type = ETHERTYPE_IP;
E 2
		off = 0;
		goto gottype;
#endif
I 2
#ifdef NS
	case AF_NS:
 		bcopy((caddr_t)&(((struct sockaddr_ns *)dst)->sns_addr.x_host),
		    (caddr_t)edst, sizeof (edst));
		if (!bcmp((caddr_t)edst, (caddr_t)&ns_broadhost,sizeof(edst)))
			mcopy = m_copy(m, 0, (int)M_COPYALL);
		else if (!bcmp((caddr_t)edst, (caddr_t)&ns_thishost,
		    sizeof(edst)))
			return(looutput(&loif, m, dst));
		type = ETHERTYPE_NS;
		off = 0;
		goto gottype;
#endif
E 2
D 3

E 3
	case AF_UNSPEC:
		ace = (struct ether_header *)dst->sa_data;
D 2
#ifdef notdef
		edst = ace->ether_dhost;
#else
		bcopy((caddr_t)ace->ether_dhost, (caddr_t)&edst, 6);
#endif
E 2
I 2
		bcopy((caddr_t)ace->ether_dhost, (caddr_t)edst, sizeof (edst));
E 2
		type = ace->ether_type;
		goto gottype;

	default:
D 3
		printf("ace%d: can't handle af%d\n",
E 3
I 3
		log(LOG_ERR, "ace%d: can't handle af%d\n",
E 3
		    ifp->if_unit, dst->sa_family);
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
D 5
#ifdef notdef
E 5
	    MMINOFF + sizeof (struct ether_header) > m->m_off) { 
D 5
#else
	    MMINOFF + 14 > m->m_off) { 
#endif
E 5
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			error = ENOBUFS;
			goto bad;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
D 5
#ifdef notdef
E 5
		m->m_len = sizeof (struct ether_header);
D 5
#else
		m->m_len = 14;
#endif
E 5
	} else {
D 5
#ifdef notdef
E 5
		m->m_off -= sizeof (struct ether_header);
		m->m_len += sizeof (struct ether_header);
D 5
#else
		m->m_off -= 14;
		m->m_len += 14;
#endif
E 5
	}
	ace = mtod(m, struct ether_header *);
D 2
#ifdef notdef
	ace->ether_dhost = edst;
	ace->ether_shost = is->is_addr;
#else
	bcopy((caddr_t)&edst, (caddr_t)ace->ether_dhost, 6);
	bcopy((caddr_t)&is->is_addr, (caddr_t)ace->ether_shost, 6);
#endif
E 2
I 2
	bcopy((caddr_t)edst, (caddr_t)ace->ether_dhost, sizeof (edst));
	bcopy((caddr_t)is->is_addr, (caddr_t)ace->ether_shost,
	    sizeof (is->is_addr));
E 2
	ace->ether_type = htons((u_short)type);

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
	splx(s);
D 4
	aceStart(ifp->if_unit);
E 4
I 4
	acestart(ifp->if_unit);
E 4
	return (mcopy ? looutput(&loif, mcopy, dst) : 0);
qfull:
	m0 = m;
	splx(s);
bad:
	m_freem(m0);
	if (mcopy)
		m_freem(mcopy);
	return (error);
}

D 4
aceStart(unit)
	int unit;
{
	register struct ace_softc *is = &ace_softc[unit];

	if (is->is_flags & ACEF_OACTIVE)
		return;
	is->is_flags |= ACEF_OACTIVE;
	acestart((dev_t)unit);
	is->is_flags &= ~ACEF_OACTIVE;
}

E 4
/*
 * Routine to copy from mbuf chain to transmit buffer on the VERSAbus
 * If packet size is less than the minimum legal size,
 * the buffer is expanded.  We probably should zero out the extra
 * bytes for security, but that would slow things down.
 */
I 2
/*ARGSUSED*/
E 2
aceput(unit, txbuf, m)
D 3
	int unit;			/* for statistics collection */
E 3
I 3
	int unit;
E 3
D 2
	u_char *txbuf;
E 2
I 2
	char *txbuf;
E 2
	struct mbuf *m;
{
D 3
	register u_char *bp, *mcp;	/* known to be r12, r11 */
	register short *s1, *s2;	/* known to be r10, r9 */
E 3
I 3
	register u_char *bp, *mcp;
	register short *s1, *s2;
E 3
D 2
	register unsigned len;
E 2
I 2
	register u_int len;
E 2
	register struct mbuf *mp;
D 2
	int total, idx;
E 2
I 2
	int total;
E 2

	total = 0;
D 2
	bp = txbuf;
	for (mp = m;(mp); mp = mp->m_next) {
E 2
I 2
	bp = (u_char *)txbuf;
	for (mp = m; (mp); mp = mp->m_next) {
E 2
		len = mp->m_len;
		if (len == 0)
			continue;
		total += len;
		mcp = mtod(mp, u_char *);
		if (((int)mcp & 01) && ((int)bp & 01)) {
			/* source & destination at odd addresses */
D 2
			/* *bp++ = *mcp++; */
			asm("movob (r11),(r12)");
			bp++, mcp++;
E 2
I 2
			movob(bp++, *mcp++);
E 2
			--len;
		}
		if (len > 1 && (((int)mcp & 01)==0) && (((int)bp & 01)==0)) {
D 2
			register int l;
E 2
I 2
			register u_int l;
E 2

			s1 = (short *)bp;
			s2 = (short *)mcp;
			l = len >> 1;		/* count # of shorts */
D 2
			while (l-- > 0) {
				/* *s1++ = *s2++; */
				asm("movow (r9),(r10)");
				s1++, s2++;
			}
E 2
I 2
			while (l-- != 0)
				movow(s1++, *s2++);
E 2
			len &= 1;		/* # remaining bytes */
			bp = (u_char *)s1;
			mcp = (u_char *)s2;
		}
D 2
		while (len-- > 0) {
			/* *bp++ = *mcp++;  */
			asm("movob (r11),(r12)");
			bp++, mcp++;
		}
E 2
I 2
		while (len-- != 0)
			movob(bp++, *mcp++);
E 2
	}
	m_freem(m);
	return (total);
}

D 2
movew(data, to)
	short data, *to;
{

	asm("movow 6(fp),*8(fp)");
}

E 2
/*
 * Routine to copy from VERSAbus memory into mbufs.
 *
 * Warning: This makes the fairly safe assumption that
 * mbufs have even lengths.
 */
I 2
/*ARGSUSED*/
E 2
struct mbuf *
D 3
aceget(unit, rxbuf, totlen, off0)
	int unit;			/* for statistics collection */
E 3
I 3
aceget(rxbuf, totlen, off0, ifp)
E 3
	u_char *rxbuf;
	int totlen, off0;
I 3
	struct ifnet *ifp;
E 3
{
D 3
	register u_char *cp, *mcp;	/* known to be r12, r11 */
E 3
I 3
	register u_char *cp, *mcp;
E 3
	register int tlen;
	register struct mbuf *m;
	struct mbuf *top = 0, **mp = &top;
	int len, off = off0;

D 5
#ifdef notdef
E 5
	cp = rxbuf + sizeof (struct ether_header);
D 5
#else
	cp = rxbuf + 14;
#endif
E 5
	while (totlen > 0) {
D 2
		register int words;

E 2
		MGET(m, M_DONTWAIT, MT_DATA);
		if (m == 0)
			goto bad;
		if (off) {
			len = totlen - off;
D 5
#ifdef notdef
E 5
			cp = rxbuf + sizeof (struct ether_header) + off;
D 5
#else
			cp = rxbuf + 14 + off;
#endif
E 5
		} else
			len = totlen;
I 3
		if (ifp)
			len += sizeof(ifp);
E 3
D 10
		if (len >= CLBYTES) {
			struct mbuf *p;

			MCLGET(p, 1);
			if (p != 0) {
				m->m_len = len = CLBYTES;
				m->m_off = (int)p - (int)m;
			} else {
E 10
I 10
		if (len >= NBPG) {
			MCLGET(m);
			if (m->m_len == CLBYTES)
				m->m_len = len = MIN(len, CLBYTES);
			else
E 10
				m->m_len = len = MIN(MLEN, len);
D 10
				m->m_off = MMINOFF;
			}
E 10
		} else {
			m->m_len = len = MIN(MLEN, len);
			m->m_off = MMINOFF;
		}
		mcp = mtod(m, u_char *);
I 3
		if (ifp) {
			/*
			 * Prepend interface pointer to first mbuf.
			 */
			*(mtod(m, struct ifnet **)) = ifp;
			mcp += sizeof(ifp);
			len -= sizeof(ifp);
			ifp = (struct ifnet *)0;
		}
E 3
		/*bcopy((caddr_t)cp, (caddr_t)mcp, len);*/
		/*cp += len; mcp += len;*/
		tlen = len;
		if (((int)mcp & 01) && ((int)cp & 01)) {
			/* source & destination at odd addresses */
			*mcp++ = *cp++;
			--tlen;
		}
		if (tlen > 1 && (((int)mcp&01) == 0) && (((int)cp&01) == 0)) {
			register short *s1, *s2;
			register int l;

			s1 = (short *)mcp;
			s2 = (short *)cp;
			l = tlen >> 1;		/* count # of shorts */
			while (l-- > 0)		/* copy shorts */
				*s1++ = *s2++;
			tlen &= 1;		/* # remaining bytes */
			mcp = (u_char *)s1;
			cp = (u_char *)s2;
		}
		while (tlen-- > 0)
			*mcp++ = *cp++;
		*mp = m;
		mp = &m->m_next;
		if (off == 0) {
			totlen -= len;
			continue;
		}
		off += len;
		if (off == totlen) {
D 5
#ifdef notdef
E 5
			cp = rxbuf + sizeof (struct ether_header);
D 5
#else
			cp = rxbuf + 14;
#endif
E 5
			off = 0;
			totlen = off0;
		}
	}
	return (top);
bad:
	m_freem(top);
	return (0);
}

I 9
/* backoff table masks */
short	random_mask_tbl[16] = {
D 10
	0x0040, 0x00C0, 0x01C0, 0x03C0, 0x07C0, 0x0FC0, 0x1FC0, 0x3FC0,
	0x7FC0, 0xFFC0, 0xFFC0, 0xFFC0, 0xFFC0, 0xFFC0, 0xFFC0, 0xFFC0
E 10
I 10
	0x0040, 0x00c0, 0x01c0, 0x03c0, 0x07c0, 0x0fc0, 0x1fc0, 0x3fc0,
	0x7fc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0
E 10
};

E 9
acebakoff(is, txseg, retries)
	struct ace_softc *is;
	struct tx_segment *txseg;
	register int retries;
{
	register short *pBakNum, random_num;
	short *pMask;

	pMask = &random_mask_tbl[0];
	pBakNum = &txseg->tx_backoff[0];
	while (--retries >= 0) {
		random_num = (is->is_currnd = (is->is_currnd * 18741)-13849);
		random_num &= *pMask++;
D 10
		*pBakNum++ = random_num ^ (short)(0xFF00 | 0x00FC);
E 10
I 10
		*pBakNum++ = random_num ^ (short)(0xff00 | 0x00fc);
E 10
	}
}

/*
 * Process an ioctl request.
 */
aceioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 2
	register struct ifreq *ifr = (struct ifreq *)data;
	int s, error = 0;
E 2
I 2
	register struct ifaddr *ifa = (struct ifaddr *)data;
I 3
	struct acedevice *addr;
E 3
	int s = splimp(), error = 0;
E 2

D 2
	s = splimp();
E 2
	switch (cmd) {

	case SIOCSIFADDR:
D 2
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
		acesetaddr(ifp, (struct sockaddr_in *)&ifr->ifr_addr);
E 2
I 2
		ifp->if_flags |= IFF_UP;
E 2
D 3
		aceinit(ifp->if_unit);
I 2
		((struct arpcom *)ifp)->ac_ipaddr = IA_SIN(ifa)->sin_addr;
		arpwhohas((struct arpcom *)ifp, &IA_SIN(ifa)->sin_addr);
E 3
I 3
		switch (ifa->ifa_addr.sa_family) {
#ifdef INET
		case AF_INET:
			aceinit(ifp->if_unit);	/* before arpwhohas */
			((struct arpcom *)ifp)->ac_ipaddr =
				IA_SIN(ifa)->sin_addr;
			arpwhohas((struct arpcom *)ifp, &IA_SIN(ifa)->sin_addr);
			break;
#endif
#ifdef NS
		case AF_NS: {
D 6
			struct ns_addr *ina = &(IA_SNS(ifa)->sns_addr);
E 6
I 6
			struct ns_addr *ina = &IA_SNS(ifa)->sns_addr;
			struct ace_softc *is = &ace_softc[ifp->if_unit];
E 6

			if (!ns_nullhost(*ina)) {
				ifp->if_flags &= ~IFF_RUNNING;
D 6
				sin = (struct sockaddr_in *)&ifr->ifr_addr;
E 6
				addr = (struct acedevice *)
D 6
				    (aceinfo[ifp->if_unit]->ui_addr);
E 6
I 6
				    aceinfo[ifp->if_unit]->ui_addr;
E 6
				movow(&addr->csr, CSR_RESET);
				DELAY(10000);
				/* set station address & copy addr to arp */
D 9
				acesetetaddr(ifp->if_unit, addr, 
E 9
I 9
				acesetaddr(ifp->if_unit, addr, 
E 9
				    ina->x_host.c_host);
			} else
D 6
				ina->x_host = *(union ns_host *)(es->es_addr);
E 6
I 6
				ina->x_host = *(union ns_host *)is->is_addr;
E 6
			aceinit(ifp->if_unit);
			break;
		}
#endif
		default:
			aceinit(ifp->if_unit);
			break;
		}
E 3
E 2
		break;

D 3
#ifdef notdef
	case SIOCSETETADDR: {		/* set Ethernet station address */
		struct vba_device *ui;
		struct acedevice *addr;
		struct sockaddr_in *sin;

		ifp->if_flags &= ~IFF_RUNNING | IFF_UP;
		sin = (struct sockaddr_in *)&ifr->ifr_addr;
		ui = aceinfo[ifp->if_unit];
		addr = (struct acedevice *)ui->ui_addr;
D 2
		movew((short)CSR_RESET, &addr->csr);
E 2
I 2
		movow(&addr->csr, CSR_RESET);
E 2
		DELAY(10000);
		/* set station address and copy addr to arp struct */
		acesetetaddr(ifp->if_unit, addr, &sin->sin_zero[2]);
		aceinit(ifp->if_unit);		/* Re-initialize */
E 3
I 3
	case SIOCSIFFLAGS:
		if ((ifp->if_flags&IFF_UP) == 0 && ifp->if_flags&IFF_RUNNING) {
			addr = (struct acedevice *)
			    (aceinfo[ifp->if_unit]->ui_addr);
			movow(&addr->csr, CSR_RESET);
			ifp->if_flags &= ~IFF_RUNNING;
		} else if (ifp->if_flags&IFF_UP &&
		    (ifp->if_flags&IFF_RUNNING) == 0)
			aceinit(ifp->if_unit);
E 3
		break;
D 3
	}
#endif
E 3

	default:
		error = EINVAL;
	}
	splx(s);
	return (error);
}

I 9
/*
 * Set the on-board station address, then read it back
 * to initialize the address used by ARP (among others).
 */
acesetaddr(unit, addr, station)
	short unit;
	struct acedevice *addr;
D 12
	char *station;
E 12
I 12
	u_char *station;
E 12
{
	struct ace_softc *is = &ace_softc[unit];
	register short *wp, i;

	for (wp = (short *)addr->station, i = 0; i < 6; i++)
		movow(wp++, ~*station++); 
	for (wp = (short *)addr->station, i = 0; i < 6; i++)
		is->is_addr[i] = ~*wp++;
	printf("ace%d: hardware address %s\n", unit,
	    ether_sprintf(is->is_addr));
}

/*
 * Setup the device for use.  Initialize dual-ported memory,
 * backoff parameters, and various other software state.
 */
E 9
D 2
acesetaddr(ifp, sin)
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
}

E 2
D 4
aceclean(unit)
E 4
I 4
acesetup(unit)
E 4
	int unit;
{
	register struct ace_softc *is = &ace_softc[unit];
D 2
	register struct ifnet *ifp = &is->is_if;
E 2
D 4
	register struct vba_device *ui = aceinfo[unit];
	register struct acedevice *addr = (struct acedevice *)ui->ui_addr;
D 2
	register short i, data;
E 2
I 2
	register short i;
E 4
E 2
	register char *pData1;
I 4
	register short i;
	struct acedevice *addr;
E 4

D 3
	ioaccess(ACEmap[unit], ACEmapa[unit], ACEBPTE);
E 3
I 3
D 4
	vbaaccess(ACEmap[unit], ACEmapa[unit], ACEBPTE);
E 3
	is->is_dpm = acemap[unit];		/* init dpm */
	bzero((char *)is->is_dpm, 16384*2);

E 4
I 4
	bzero(is->is_dpm, 16384*2);
E 4
	is->is_currnd = 49123;
I 4
	addr = (struct acedevice *)aceinfo[unit]->ui_addr;
E 4
	is->is_segboundry = (addr->segb >> 11) & 0xf;
D 4
	pData1 = (char*)((int)is->is_dpm + (is->is_segboundry << 11));
E 4
I 4
	pData1 = is->is_dpm + (is->is_segboundry << 11);
E 4
	for (i = SEG_MAX + 1 - is->is_segboundry; --i >= 0;) {
		acebakoff(is, (struct tx_segment *)pData1, 15);
		pData1 += sizeof (struct tx_segment);
	}
	is->is_eictr = 0;
	is->is_eoctr = is->is_txnext = is->is_segboundry;
	bzero((char *)&is->is_stats, sizeof (is->is_stats));
}
#endif
E 1
