h64551
s 00006/00005/01078
d D 7.12 03/01/19 23:03:38 msokolov 17 16
c fix uba reset bug and other goo
e
s 00104/00102/00979
d D 7.11 89/02/17 10:25:26 karels 16 15
c QNIVERT ifdef, reduce number of input buffers; fix reset for delqa;
c remove trailing blanks
e
s 00031/00032/01050
d D 7.10 88/10/22 14:00:57 karels 15 14
c use uballoc macros, new qbus autoconf (old mbufs)
e
s 00000/00000/01082
d D 7.9 88/10/12 15:15:44 karels 14 13
c (by sklower) checkpoint before var length sockaddrs.
e
s 00005/00001/01077
d D 7.8 88/10/04 11:45:09 karels 13 11
c changes for delqa (from tef)
e
s 00046/00001/01077
d R 7.8 88/10/04 11:41:57 karels 12 11
c changes for delqa (from tef)
e
s 00021/00002/01057
d D 7.7 88/08/04 15:30:05 bostic 11 10
c add Berkeley specific copyright
e
s 00001/00001/01058
d D 7.6 88/05/28 17:10:38 marc 10 9
c double oops - (fix typo)
e
s 00001/00001/01058
d D 7.5 88/05/27 17:31:30 karels 9 8
c oops
e
s 00044/00064/01015
d D 7.4 88/05/27 16:39:48 karels 8 7
c use if_timer instead of private timeout; print hardware address
c during autoconfig; force priority
e
s 00009/00007/01070
d D 7.3 87/08/31 11:13:16 karels 7 6
c don't count board braindamage as input errors; was reading
c too much from receive buffer
e
s 00007/00003/01070
d D 7.2 87/03/10 20:16:45 karels 6 5
c fewer buffers if running 2 qe's; don't restart if not started
c and some fool does "ifconfig up"
e
s 00000/00000/01073
d D 7.1 86/06/05 17:10:22 mckusick 5 4
c 4.3BSD release version
e
s 00029/00027/01044
d D 6.3 86/06/02 14:45:18 karels 4 3
c lint
e
s 00016/00019/01055
d D 6.2 86/05/31 21:16:47 karels 3 2
c lint
e
s 00265/00657/00809
d D 6.1 86/05/09 16:22:23 karels 2 1
c rework for 4.3: rm decnet, binary stuff, add ns, use new if_uba
e
s 01466/00000/00000
d D 1.1 86/04/28 13:41:52 kjd 1 0
c date and time created 86/04/28 13:41:52 by kjd
e
u
U
t
T
I 1
D 11
/*	%W% (Berkeley) %G% */
E 11
I 11
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Digital Equipment Corp.
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
 *
 *	%W% (Berkeley) %G%
 */
E 11

D 2
#ifndef lint
static	char	*sccsid = "@(#)if_qe.c	1.15	(ULTRIX)	4/16/86";
#endif lint
E 2
I 2
/* from  @(#)if_qe.c	1.15	(ULTRIX)	4/16/86 */
E 2
D 11
 
E 11
D 16
 
E 16
I 16

E 16
/****************************************************************
 *								*
 *        Licensed from Digital Equipment Corporation 		*
 *                       Copyright (c) 				*
 *               Digital Equipment Corporation			*
 *                   Maynard, Massachusetts 			*
 *                         1985, 1986 				*
 *                    All rights reserved. 			*
 *								*
 *        The Information in this software is subject to change *
 *   without notice and should not be construed as a commitment *
 *   by  Digital  Equipment  Corporation.   Digital   makes  no *
 *   representations about the suitability of this software for *
 *   any purpose.  It is supplied "As Is" without expressed  or *
 *   implied  warranty. 					*
 *								*
 *        If the Regents of the University of California or its *
 *   licensees modify the software in a manner creating  	*
D 2
 *   diriviative copyright rights, appropriate copyright  	*
 *   legends may be placed on  the drivative work in addition   *
E 2
I 2
 *   derivative copyright rights, appropriate copyright  	*
 *   legends may be placed on the derivative work in addition   *
E 2
 *   to that set forth above. 					*
 *								*
 ****************************************************************/
/* ---------------------------------------------------------------------
D 16
 * Modification History 
E 16
I 16
 * Modification History
E 16
 *
 * 15-Apr-86  -- afd
 *	Rename "unused_multi" to "qunused_multi" for extending Generic
 *	kernel to MicroVAXen.
 *
 * 18-mar-86  -- jaw     br/cvec changed to NOT use registers.
 *
 * 12 March 86 -- Jeff Chase
 *	Modified to handle the new MCLGET macro
 *	Changed if_qe_data.c to use more receive buffers
 *	Added a flag to poke with adb to log qe_restarts on console
 *
 * 19 Oct 85 -- rjl
 *	Changed the watch dog timer from 30 seconds to 3.  VMS is using
 * 	less than 1 second in their's. Also turned the printf into an
 *	mprintf.
 *
 *  09/16/85 -- Larry Cohen
D 16
 * 		Add 43bsd alpha tape changes for subnet routing		
E 16
I 16
 * 		Add 43bsd alpha tape changes for subnet routing
E 16
 *
 *  1 Aug 85 -- rjl
 *	Panic on a non-existent memory interrupt and the case where a packet
D 16
 *	was chained.  The first should never happen because non-existant 
E 16
I 16
 *	was chained.  The first should never happen because non-existant
E 16
 *	memory interrupts cause a bus reset. The second should never happen
 *	because we hang 2k input buffers on the device.
 *
 *  1 Aug 85 -- rich
 *      Fixed the broadcast loopback code to handle Clusters without
 *      wedging the system.
 *
 *  27 Feb. 85 -- ejf
 *	Return default hardware address on ioctl request.
 *
 *  12 Feb. 85 -- ejf
 *	Added internal extended loopback capability.
 *
 *  27 Dec. 84 -- rjl
 *	Fixed bug that caused every other transmit descriptor to be used
 *	instead of every descriptor.
 *
 *  21 Dec. 84 -- rjl
 *	Added watchdog timer to mask hardware bug that causes device lockup.
 *
 *  18 Dec. 84 -- rjl
 *	Reworked driver to use q-bus mapping routines.  MicroVAX-I now does
 *	copying instead of m-buf shuffleing.
 *	A number of deficencies in the hardware/firmware were compensated
 *	for. See comments in qestart and qerint.
 *
 *  14 Nov. 84 -- jf
 *	Added usage counts for multicast addresses.
 *	Updated general protocol support to allow access to the Ethernet
 *	header.
 *
 *  04 Oct. 84 -- jf
 *	Added support for new ioctls to add and delete multicast addresses
 *	and set the physical address.
 *	Add support for general protocols.
 *
 *  14 Aug. 84 -- rjl
 *	Integrated Shannon changes. (allow arp above 1024 and ? )
 *
 *  13 Feb. 84 -- rjl
 *
 *	Initial version of driver. derived from IL driver.
D 16
 * 
E 16
I 16
 *
E 16
 * ---------------------------------------------------------------------
 */
D 16
 
E 16
I 16

E 16
#include "qe.h"
D 2
#if	NQE > 0 || defined(BINARY)
E 2
I 2
#if	NQE > 0
E 2
/*
 * Digital Q-BUS to NI Adapter
 */
I 2
D 8
#include "../machine/pte.h"

E 8
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "ioctl.h"
#include "errno.h"
#include "syslog.h"
#include "time.h"
#include "kernel.h"

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"

#ifdef INET
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/in_var.h"
#include "../netinet/ip.h"
#include "../netinet/if_ether.h"
#endif

#ifdef NS
#include "../netns/ns.h"
#include "../netns/ns_if.h"
#endif

I 8
#include "../vax/pte.h"
E 8
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
#include "if_qereg.h"
#include "if_uba.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 2
D 16
 
D 2
#include "../data/if_qe_data.c"
extern struct protosw *iftype_to_proto(), *iffamily_to_proto();
E 2
I 2
D 6
#define NRCV	25	 		/* Receive descriptors		*/
E 6
I 6
#if NQE > 1
E 16
I 16

#if NQE == 1 && !defined(QNIVERT)
E 16
#define NRCV	15	 		/* Receive descriptors		*/
#else
D 16
#define NRCV	20	 		/* Receive descriptors		*/
E 16
I 16
#define NRCV	10	 		/* Receive descriptors		*/
E 16
#endif
E 6
#define NXMT	5	 		/* Transmit descriptors		*/
#define NTOT	(NXMT + NRCV)
I 8

#define	QETIMEOUT	2		/* transmit timeout, must be > 1 */
E 8
D 16
 
E 16
I 16

E 16
/*
 * This constant should really be 60 because the qna adds 4 bytes of crc.
 * However when set to 60 our packets are ignored by deuna's , 3coms are
 * okay ??????????????????????????????????????????
 */
#define MINDATA 64
D 16
 
E 16
I 16

E 16
/*
 * Ethernet software status per interface.
 *
 * Each interface is referenced by a network interface structure,
D 8
 * is_if, which the routing code uses to locate the interface.
E 8
I 8
 * qe_if, which the routing code uses to locate the interface.
E 8
 * This structure contains the output queue for the interface, its address, ...
 */
struct	qe_softc {
D 8
	struct	arpcom is_ac;		/* Ethernet common part 	*/
#define	is_if	is_ac.ac_if		/* network-visible interface 	*/
#define	is_addr	is_ac.ac_enaddr		/* hardware Ethernet address 	*/
E 8
I 8
	struct	arpcom qe_ac;		/* Ethernet common part 	*/
#define	qe_if	qe_ac.ac_if		/* network-visible interface 	*/
#define	qe_addr	qe_ac.ac_enaddr		/* hardware Ethernet address 	*/
E 8
	struct	ifubinfo qe_uba;	/* Q-bus resources 		*/
	struct	ifrw qe_ifr[NRCV];	/*	for receive buffers;	*/
	struct	ifxmt qe_ifw[NXMT];	/*	for xmit buffers;	*/
	int	qe_flags;		/* software state		*/
#define	QEF_RUNNING	0x01
#define	QEF_SETADDR	0x02
	int	setupaddr;		/* mapping info for setup pkts  */
I 15
	int	ipl;			/* interrupt priority		*/
E 15
	struct	qe_ring *rringaddr;	/* mapping info for rings	*/
	struct	qe_ring *tringaddr;	/*       ""			*/
	struct	qe_ring rring[NRCV+1];	/* Receive ring descriptors 	*/
	struct	qe_ring tring[NXMT+1];	/* Transmit ring descriptors 	*/
	u_char	setup_pkt[16][8];	/* Setup packet			*/
	int	rindex;			/* Receive index		*/
	int	tindex;			/* Transmit index		*/
	int	otindex;		/* Old transmit index		*/
	int	qe_intvec;		/* Interrupt vector 		*/
	struct	qedevice *addr;		/* device addr			*/
	int 	setupqueued;		/* setup packet queued		*/
	int	nxmit;			/* Transmits in progress	*/
D 8
	int	timeout;		/* watchdog			*/
E 8
	int	qe_restarts;		/* timeouts			*/
} qe_softc[NQE];

struct	uba_device *qeinfo[NQE];
D 16
 
E 16
I 16

E 16
E 2
extern struct timeval time;
D 8
extern timeout();
E 8
D 16
 
E 16
I 16

E 16
D 4
int	qeprobe(), qeattach(), qeint(), qewatch();
E 4
I 4
D 8
int	qeprobe(), qeattach(), qeintr(), qewatch();
E 4
int	qeinit(),qeoutput(),qeioctl(),qereset(),qewatch();
E 8
I 8
int	qeprobe(), qeattach(), qeintr(), qetimeout();
int	qeinit(), qeoutput(), qeioctl(), qereset();
E 8
D 2
struct mbuf *qeget();
E 2
D 16
 
E 16
I 16

E 16
u_short qestd[] = { 0 };
struct	uba_driver qedriver =
	{ qeprobe, 0, qeattach, 0, qestd, "qe", qeinfo };
D 16
 
D 2
u_char qunused_multi[6] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
 
E 2
#define QE_TIMEO	(15)
E 16
I 16

E 16
#define	QEUNIT(x)	minor(x)
D 15
static int mask = 0x3ffff;		/* address mask		*/
E 15
D 8
int qewatchrun = 0;			/* watchdog running	*/
E 8
/*
D 2
 * The deqna shouldn't recieve more than ETHERMTU + sizeof(struct ether_header)
E 2
I 2
 * The deqna shouldn't receive more than ETHERMTU + sizeof(struct ether_header)
E 2
 * but will actually take in up to 2048 bytes. To guard against the receiver
D 16
 * chaining buffers (which we aren't prepared to handle) we allocate 2kb 
E 16
I 16
 * chaining buffers (which we aren't prepared to handle) we allocate 2kb
E 16
 * size buffers.
 */
#define MAXPACKETSIZE 2048		/* Should really be ETHERMTU	*/
/*
 * Probe the QNA to see if it's there
 */
D 15
qeprobe(reg)
E 15
I 15
qeprobe(reg, ui)
E 15
	caddr_t reg;
I 15
	struct uba_device *ui;
E 15
{
D 2
 
E 2
I 2
	register int br, cvec;		/* r11, r10 value-result */
E 2
	register struct qedevice *addr = (struct qedevice *)reg;
D 16
	register struct qe_ring *rp; 
E 16
I 16
	register struct qe_ring *rp;
E 16
	register struct qe_ring *prp; 	/* physical rp 		*/
D 3
	register int i, j, ncl;
E 3
I 3
D 15
	register int i, j;
E 3
	static int next=0;		/* softc index		*/
	register struct qe_softc *sc = &qe_softc[next++];
E 15
I 15
	register int i;
	register struct qe_softc *sc = &qe_softc[ui->ui_unit];
E 15
D 16
 
E 16
I 16

E 16
I 3
#ifdef lint
	br = 0; cvec = br; br = cvec;
D 4
	qeintr(i);
E 4
I 4
	qeintr(0);
E 4
#endif
E 3
D 15
	/*
	 * Set the address mask for the particular cpu
	 */
D 2
	if( cpu == MVAX_I )
		mask = 0x3fffff;
	else
		mask = 0x3ffff;
E 2
I 2
	mask = 0x3ffff;
E 15
E 2
D 16
 
E 16
I 16

E 16
	/*
D 16
	 * The QNA interrupts on i/o operations. To do an I/O operation 
E 16
I 16
	 * The QNA interrupts on i/o operations. To do an I/O operation
E 16
	 * we have to setup the interface by transmitting a setup  packet.
	 */
	addr->qe_csr = QE_RESET;
I 13
	addr->qe_csr &= ~QE_RESET;
E 13
	addr->qe_vector = (uba_hd[numuba].uh_lastiv -= 4);
D 16
 
E 16
I 16

E 16
	/*
	 * Map the communications area and the setup packet.
	 */
	sc->setupaddr =
D 4
		uballoc(0, sc->setup_pkt, sizeof(sc->setup_pkt), 0);
	sc->rringaddr = (struct qe_ring *)
D 2
		uballoc(0, sc->rring, sizeof(struct qe_ring)*(nNTOT+2),0);
E 2
I 2
		uballoc(0, sc->rring, sizeof(struct qe_ring) * (NTOT+2), 0);
E 4
I 4
		uballoc(0, (caddr_t)sc->setup_pkt, sizeof(sc->setup_pkt), 0);
	sc->rringaddr = (struct qe_ring *) uballoc(0, (caddr_t)sc->rring,
		sizeof(struct qe_ring) * (NTOT+2), 0);
E 4
E 2
D 15
	prp = (struct qe_ring *)((int)sc->rringaddr & mask);
E 15
I 15
	prp = (struct qe_ring *)UBAI_ADDR((int)sc->rringaddr);
E 15
D 16
 
E 16
I 16

E 16
	/*
	 * The QNA will loop the setup packet back to the receive ring
D 16
	 * for verification, therefore we initialize the first 
E 16
I 16
	 * for verification, therefore we initialize the first
E 16
	 * receive & transmit ring descriptors and link the setup packet
	 * to them.
	 */
D 4
	qeinitdesc( sc->tring, sc->setupaddr & mask, sizeof(sc->setup_pkt));
	qeinitdesc( sc->rring, sc->setupaddr & mask, sizeof(sc->setup_pkt));
E 4
I 4
D 15
	qeinitdesc(sc->tring, (caddr_t)(sc->setupaddr & mask),
E 15
I 15
	qeinitdesc(sc->tring, (caddr_t)UBAI_ADDR(sc->setupaddr),
E 15
	    sizeof(sc->setup_pkt));
D 15
	qeinitdesc(sc->rring, (caddr_t)(sc->setupaddr & mask),
E 15
I 15
	qeinitdesc(sc->rring, (caddr_t)UBAI_ADDR(sc->setupaddr),
E 15
	    sizeof(sc->setup_pkt));
E 4
D 16
 
E 16
I 16

E 16
	rp = (struct qe_ring *)sc->tring;
	rp->qe_setup = 1;
	rp->qe_eomsg = 1;
	rp->qe_flag = rp->qe_status1 = QE_NOTYET;
	rp->qe_valid = 1;
D 16
 
E 16
I 16

E 16
	rp = (struct qe_ring *)sc->rring;
	rp->qe_flag = rp->qe_status1 = QE_NOTYET;
	rp->qe_valid = 1;
D 16
 
E 16
I 16

E 16
	/*
	 * Get the addr off of the interface and place it into the setup
	 * packet. This code looks strange due to the fact that the address
D 16
	 * is placed in the setup packet in col. major order. 
E 16
I 16
	 * is placed in the setup packet in col. major order.
E 16
	 */
	for( i = 0 ; i < 6 ; i++ )
		sc->setup_pkt[i][1] = addr->qe_sta_addr[i];
D 16
 
E 16
I 16

E 16
	qesetup( sc );
	/*
	 * Start the interface and wait for the packet.
	 */
D 15
	j = cvec;
E 15
I 15
	(void) spl6();
E 15
	addr->qe_csr = QE_INT_ENABLE | QE_XMIT_INT | QE_RCV_INT;
	addr->qe_rcvlist_lo = (short)prp;
	addr->qe_rcvlist_hi = (short)((int)prp >> 16);
D 2
	prp += nNRCV+1;
E 2
I 2
	prp += NRCV+1;
E 2
	addr->qe_xmtlist_lo = (short)prp;
	addr->qe_xmtlist_hi = (short)((int)prp >> 16);
	DELAY(10000);
	/*
D 2
	 * All done with the bus resources. If it's a uVAX-I they weren't
	 * really allocated otherwise deallocated them.
E 2
I 2
	 * All done with the bus resources.
E 2
	 */
D 2
	if( cpu != MVAX_I ) {
		ubarelse(0, &sc->setupaddr);
		ubarelse(0, &sc->rringaddr);
	}
E 2
I 2
	ubarelse(0, &sc->setupaddr);
D 4
	ubarelse(0, &sc->rringaddr);
E 4
I 4
	ubarelse(0, (int *)&sc->rringaddr);
E 4
E 2
D 15
	if( cvec == j ) 
		return 0;		/* didn't interrupt	*/
D 8
 
E 8
I 8

	br = 0x15;			/* q-bus doesn't get level */
E 15
I 15
	sc->ipl = br = qbgetpri();
E 15
E 8
D 2
	/*
	 * Allocate page size buffers now. If we wait until the network
	 * is setup they have already fragmented. By doing it here in
	 * conjunction with always coping on uVAX-I processors we obtain
	 * physically contigous buffers for dma transfers.
	 */
	ncl = clrnd((int)btoc(MAXPACKETSIZE) + CLSIZE) / CLSIZE;
	sc->buffers = m_clalloc(nNTOT * ncl, MPG_SPACE);
E 2
	return( sizeof(struct qedevice) );
}
D 16
 
E 16
I 16

E 16
/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.
 */
qeattach(ui)
	struct uba_device *ui;
{
	register struct qe_softc *sc = &qe_softc[ui->ui_unit];
D 8
	register struct ifnet *ifp = &sc->is_if;
E 8
I 8
	register struct ifnet *ifp = &sc->qe_if;
E 8
	register struct qedevice *addr = (struct qedevice *)ui->ui_addr;
	register int i;
D 2
	struct sockaddr_in *sin;
E 2
D 16
 
E 16
I 16

E 16
	ifp->if_unit = ui->ui_unit;
	ifp->if_name = "qe";
	ifp->if_mtu = ETHERMTU;
D 2
	ifp->if_flags |= IFF_BROADCAST | IFF_DYNPROTO;
E 2
I 2
	ifp->if_flags = IFF_BROADCAST;
E 2
D 16
 
E 16
I 16

E 16
	/*
	 * Read the address from the prom and save it.
	 */
	for( i=0 ; i<6 ; i++ )
D 8
		sc->setup_pkt[i][1] = sc->is_addr[i] = addr->qe_sta_addr[i] & 0xff;  
E 8
I 8
D 16
		sc->setup_pkt[i][1] = sc->qe_addr[i] = addr->qe_sta_addr[i] & 0xff;  
E 16
I 16
		sc->setup_pkt[i][1] = sc->qe_addr[i] = addr->qe_sta_addr[i] & 0xff;
E 16
D 13
	printf("qe%d: hardware address %s\n", ui->ui_unit,
E 13
I 13
	addr->qe_vector |= 1;
	printf("qe%d: %s, hardware address %s\n", ui->ui_unit,
		addr->qe_vector&01 ? "delqa":"deqna",
E 13
D 9
		ether_sprintf(is->is_addr));
E 9
I 9
D 10
		ether_sprintf(c->qe_addr));
E 10
I 10
		ether_sprintf(sc->qe_addr));
I 13
	addr->qe_vector &= ~1;
E 13
E 10
E 9
E 8
D 16
 
E 16
I 16

E 16
	/*
	 * Save the vector for initialization at reset time.
	 */
	sc->qe_intvec = addr->qe_vector;
D 16
 
E 16
I 16

E 16
D 2
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
E 2
	ifp->if_init = qeinit;
	ifp->if_output = qeoutput;
	ifp->if_ioctl = qeioctl;
	ifp->if_reset = qereset;
I 8
	ifp->if_watchdog = qetimeout;
E 8
I 2
	sc->qe_uba.iff_flags = UBA_CANTWAIT;
E 2
	if_attach(ifp);
}
D 16
 
E 16
I 16

E 16
/*
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
qereset(unit, uban)
	int unit, uban;
{
	register struct uba_device *ui;
D 16
 
E 16
I 16

E 16
D 2
	if (unit >= nNQE || (ui = qeinfo[unit]) == 0 || ui->ui_alive == 0 ||
E 2
I 2
	if (unit >= NQE || (ui = qeinfo[unit]) == 0 || ui->ui_alive == 0 ||
E 2
		ui->ui_ubanum != uban)
		return;
	printf(" qe%d", unit);
I 2
D 8
	qe_softc[unit].is_if.if_flags &= ~IFF_RUNNING;
E 8
I 8
	qe_softc[unit].qe_if.if_flags &= ~IFF_RUNNING;
I 17
	qe_softc[unit].qe_flags &= ~QEF_RUNNING;
E 17
E 8
E 2
	qeinit(unit);
}
D 16
 
E 16
I 16

E 16
/*
D 16
 * Initialization of interface. 
E 16
I 16
 * Initialization of interface.
E 16
 */
qeinit(unit)
	int unit;
{
	register struct qe_softc *sc = &qe_softc[unit];
	register struct uba_device *ui = qeinfo[unit];
	register struct qedevice *addr = (struct qedevice *)ui->ui_addr;
D 8
	register struct ifnet *ifp = &sc->is_if;
E 8
I 8
	register struct ifnet *ifp = &sc->qe_if;
E 8
	register i;
	int s;
D 16
 
E 16
I 16

E 16
	/* address not known */
D 2
	/* DECnet must set this somewhere to make device happy */
E 2
	if (ifp->if_addrlist == (struct ifaddr *)0)
			return;
D 2
	if (ifp->if_flags & IFF_RUNNING)
E 2
I 2
	if (sc->qe_flags & QEF_RUNNING)
E 2
		return;
D 16
 
E 16
I 16

E 16
D 2
	/*
	 * map the communications area onto the device 
	 */
	sc->rringaddr = (struct qe_ring *)((int)uballoc(0,
		sc->rring, sizeof(struct qe_ring)*(nNTOT+2),0)&mask);
	sc->tringaddr = sc->rringaddr+nNRCV+1;
	sc->setupaddr =	uballoc(0, sc->setup_pkt, sizeof(sc->setup_pkt), 0) & mask;
	/*
	 * init buffers and maps
	 */
	if (qe_ubainit(&sc->qeuba, ui->ui_ubanum,
	    sizeof (struct ether_header), (int)btoc(MAXPACKETSIZE), sc->buffers) == 0) { 
		printf("qe%d: can't initialize\n", unit);
		sc->is_if.if_flags &= ~IFF_UP;
		return;
E 2
I 2
	if ((ifp->if_flags & IFF_RUNNING) == 0) {
		/*
D 16
		 * map the communications area onto the device 
E 16
I 16
		 * map the communications area onto the device
E 16
		 */
D 4
		sc->rringaddr = (struct qe_ring *)((int)uballoc(0, sc->rring,
E 4
I 4
D 15
		sc->rringaddr = (struct qe_ring *)
		    ((int) uballoc(0, (caddr_t)sc->rring,
E 4
		    sizeof(struct qe_ring) * (NTOT+2), 0) & mask);
E 15
I 15
		i = uballoc(0, (caddr_t)sc->rring,
		    sizeof(struct qe_ring) * (NTOT+2), 0);
		if (i == 0)
			goto fail;
		sc->rringaddr = (struct qe_ring *)UBAI_ADDR(i);
E 15
		sc->tringaddr = sc->rringaddr + NRCV + 1;
D 4
		sc->setupaddr =	uballoc(0, sc->setup_pkt,
E 4
I 4
D 15
		sc->setupaddr =	uballoc(0, (caddr_t)sc->setup_pkt,
E 4
		    sizeof(sc->setup_pkt), 0) & mask;
E 15
I 15
		i = uballoc(0, (caddr_t)sc->setup_pkt,
		    sizeof(sc->setup_pkt), 0);
		if (i == 0)
			goto fail;
		sc->setupaddr =	UBAI_ADDR(i);
E 15
		/*
		 * init buffers and maps
		 */
		if (if_ubaminit(&sc->qe_uba, ui->ui_ubanum,
		    sizeof (struct ether_header), (int)btoc(MAXPACKETSIZE),
		    sc->qe_ifr, NRCV, sc->qe_ifw, NXMT) == 0) {
I 15
	fail:
E 15
D 16
			printf("qe%d: can't initialize\n", unit);
E 16
I 16
			printf("qe%d: can't allocate uba resources\n", unit);
E 16
D 8
			sc->is_if.if_flags &= ~IFF_UP;
E 8
I 8
			sc->qe_if.if_flags &= ~IFF_UP;
E 8
			return;
		}
E 2
	}
	/*
	 * Init the buffer descriptors and indexes for each of the lists and
	 * loop them back to form a ring.
	 */
D 2
	for( i = 0 ; i < nNRCV ; i++ ){
E 2
I 2
	for (i = 0; i < NRCV; i++) {
E 2
		qeinitdesc( &sc->rring[i],
D 2
			sc->qeuba.ifu_r[i].ifrw_info & mask, MAXPACKETSIZE);
E 2
I 2
D 4
			sc->qe_ifr[i].ifrw_info & mask, MAXPACKETSIZE);
E 4
I 4
D 15
		    (caddr_t)(sc->qe_ifr[i].ifrw_info & mask), MAXPACKETSIZE);
E 15
I 15
		    (caddr_t)UBAI_ADDR(sc->qe_ifr[i].ifrw_info), MAXPACKETSIZE);
E 15
E 4
E 2
		sc->rring[i].qe_flag = sc->rring[i].qe_status1 = QE_NOTYET;
		sc->rring[i].qe_valid = 1;
	}
D 4
	qeinitdesc( &sc->rring[i], NULL, 0 );
E 4
I 4
	qeinitdesc(&sc->rring[i], (caddr_t)NULL, 0);
E 4
D 16
 
E 16
I 16

E 16
	sc->rring[i].qe_addr_lo = (short)sc->rringaddr;
	sc->rring[i].qe_addr_hi = (short)((int)sc->rringaddr >> 16);
	sc->rring[i].qe_chain = 1;
	sc->rring[i].qe_flag = sc->rring[i].qe_status1 = QE_NOTYET;
	sc->rring[i].qe_valid = 1;
D 16
 
E 16
I 16

E 16
D 2
	for( i = 0 ; i <= nNXMT ; i++ )
E 2
I 2
	for( i = 0 ; i <= NXMT ; i++ )
E 2
D 4
		qeinitdesc( &sc->tring[i], NULL, 0 );
E 4
I 4
		qeinitdesc(&sc->tring[i], (caddr_t)NULL, 0);
E 4
	i--;
D 16
 
E 16
I 16

E 16
	sc->tring[i].qe_addr_lo = (short)sc->tringaddr;
	sc->tring[i].qe_addr_hi = (short)((int)sc->tringaddr >> 16);
	sc->tring[i].qe_chain = 1;
	sc->tring[i].qe_flag = sc->tring[i].qe_status1 = QE_NOTYET;
	sc->tring[i].qe_valid = 1;
D 16
 
E 16
I 16

E 16
	sc->nxmit = sc->otindex = sc->tindex = sc->rindex = 0;
D 16
 
E 16
I 16

E 16
	/*
D 16
	 * Take the interface out of reset, program the vector, 
E 16
I 16
	 * Take the interface out of reset, program the vector,
E 16
	 * enable interrupts, and tell the world we are up.
	 */
	s = splimp();
	addr->qe_vector = sc->qe_intvec;
	sc->addr = addr;
D 2
	if ( ifp->if_flags & IFF_LOOPBACK )
		addr->qe_csr = QE_RCV_ENABLE | QE_INT_ENABLE | QE_XMIT_INT | QE_RCV_INT | QE_ELOOP;
	else
		addr->qe_csr = QE_RCV_ENABLE | QE_INT_ENABLE | QE_XMIT_INT | QE_RCV_INT | QE_ILOOP;
E 2
I 2
	addr->qe_csr = QE_RCV_ENABLE | QE_INT_ENABLE | QE_XMIT_INT |
	    QE_RCV_INT | QE_ILOOP;
E 2
	addr->qe_rcvlist_lo = (short)sc->rringaddr;
	addr->qe_rcvlist_hi = (short)((int)sc->rringaddr >> 16);
	ifp->if_flags |= IFF_UP | IFF_RUNNING;
I 2
	sc->qe_flags |= QEF_RUNNING;
E 2
	qesetup( sc );
	qestart( unit );
D 2
	sc->ztime = time.tv_sec;
E 2
	splx( s );
D 16
 
E 16
}
D 16
 
E 16
I 16

E 16
/*
 * Start output on interface.
 *
 */
D 8
qestart(dev)
	dev_t dev;
E 8
I 8
qestart(unit)
	int unit;
E 8
{
D 8
	int unit = QEUNIT(dev);
E 8
	struct uba_device *ui = qeinfo[unit];
	register struct qe_softc *sc = &qe_softc[unit];
	register struct qedevice *addr;
	register struct qe_ring *rp;
	register index;
D 3
	struct mbuf *m, *m0;
	int buf_addr, len, j,  s;
E 3
I 3
	struct mbuf *m;
	int buf_addr, len, s;
E 3
D 16
 
	 
E 16
I 16


E 16
	s = splimp();
	addr = (struct qedevice *)ui->ui_addr;
	/*
	 * The deqna doesn't look at anything but the valid bit
	 * to determine if it should transmit this packet. If you have
	 * a ring and fill it the device will loop indefinately on the
	 * packet and continue to flood the net with packets until you
	 * break the ring. For this reason we never queue more than n-1
D 16
	 * packets in the transmit ring. 
E 16
I 16
	 * packets in the transmit ring.
E 16
	 *
	 * The microcoders should have obeyed their own defination of the
	 * flag and status words, but instead we have to compensate.
	 */
D 16
	for( index = sc->tindex; 
E 16
I 16
	for( index = sc->tindex;
E 16
D 2
		sc->tring[index].qe_valid == 0 && sc->nxmit < (nNXMT-1) ;
		sc->tindex = index = ++index % nNXMT){
E 2
I 2
		sc->tring[index].qe_valid == 0 && sc->nxmit < (NXMT-1) ;
		sc->tindex = index = ++index % NXMT){
E 2
		rp = &sc->tring[index];
		if( sc->setupqueued ) {
			buf_addr = sc->setupaddr;
			len = 128;
			rp->qe_setup = 1;
			sc->setupqueued = 0;
		} else {
D 8
			IF_DEQUEUE(&sc->is_if.if_snd, m);
E 8
I 8
			IF_DEQUEUE(&sc->qe_if.if_snd, m);
E 8
			if( m == 0 ){
				splx(s);
				return;
			}
D 2
			buf_addr = sc->qeuba.ifu_w[index].x_ifrw.ifrw_info;
			len = qeput(&sc->qeuba, index, m);
E 2
I 2
			buf_addr = sc->qe_ifw[index].ifw_info;
			len = if_ubaput(&sc->qe_uba, &sc->qe_ifw[index], m);
E 2
		}
		/*
D 16
		 *  Does buffer end on odd byte ? 
E 16
I 16
		 *  Does buffer end on odd byte ?
E 16
		 */
		if( len & 1 ) {
			len++;
			rp->qe_odd_end = 1;
		}
		if( len < MINDATA )
			len = MINDATA;
		rp->qe_buf_len = -(len/2);
D 15
		buf_addr &= mask;
E 15
I 15
		buf_addr = UBAI_ADDR(buf_addr);
E 15
		rp->qe_flag = rp->qe_status1 = QE_NOTYET;
		rp->qe_addr_lo = (short)buf_addr;
		rp->qe_addr_hi = (short)(buf_addr >> 16);
		rp->qe_eomsg = 1;
		rp->qe_flag = rp->qe_status1 = QE_NOTYET;
		rp->qe_valid = 1;
D 16
		sc->nxmit++;
D 8
		/*
		 * If the watchdog time isn't running kick it.
		 */
		sc->timeout=1;
D 4
		if( !qewatchrun++ ) 
			timeout(qewatch,0,QE_TIMEO);
E 4
I 4
		if (qewatchrun == 0) { 
			qewatchrun++; 
			timeout(qewatch, (caddr_t)0, QE_TIMEO);
		}
E 8
I 8
		sc->qe_if.if_timer = QETIMEOUT;
E 8
E 4
			
E 16
I 16
		if (sc->nxmit++ == 0)
			sc->qe_if.if_timer = QETIMEOUT;

E 16
		/*
		 * See if the xmit list is invalid.
		 */
		if( addr->qe_csr & QE_XL_INVALID ) {
			buf_addr = (int)(sc->tringaddr+index);
			addr->qe_xmtlist_lo = (short)buf_addr;
			addr->qe_xmtlist_hi = (short)(buf_addr >> 16);
		}
D 2
		/*
		 * Accumulate statistics for DECnet
		 */
		if ((sc->ctrblk.est_bytesent + len) > sc->ctrblk.est_bytesent)
			sc->ctrblk.est_bytesent += len;
		if (sc->ctrblk.est_bloksent != 0xffffffff)
			sc->ctrblk.est_bloksent++;
E 2
	}
	splx( s );
}
D 16
 
E 16
I 16

E 16
/*
 * Ethernet interface interrupt processor
 */
qeintr(unit)
	int unit;
{
	register struct qe_softc *sc = &qe_softc[unit];
D 3
	register struct ifnet *ifp = &sc->is_if;
E 3
	struct qedevice *addr = (struct qedevice *)qeinfo[unit]->ui_addr;
D 15
	int s, buf_addr, csr;
E 15
I 15
	int buf_addr, csr;
E 15
D 16
 
E 16
I 16

/*
E 16
D 15
	s = splimp();
E 15
I 15
	splx(sc->ipl);
I 16
*/
	(void) splimp();
E 16
E 15
	csr = addr->qe_csr;
D 2
	if ( ifp->if_flags & IFF_LOOPBACK )
		addr->qe_csr = QE_RCV_ENABLE | QE_INT_ENABLE | QE_XMIT_INT | QE_RCV_INT | QE_ELOOP;
	else
		addr->qe_csr = QE_RCV_ENABLE | QE_INT_ENABLE | QE_XMIT_INT | QE_RCV_INT | QE_ILOOP;
E 2
I 2
	addr->qe_csr = QE_RCV_ENABLE | QE_INT_ENABLE | QE_XMIT_INT | QE_RCV_INT | QE_ILOOP;
E 2
D 16
	if( csr & QE_RCV_INT ) 
E 16
I 16
	if( csr & QE_RCV_INT )
E 16
		qerint( unit );
	if( csr & QE_XMIT_INT )
		qetint( unit );
	if( csr & QE_NEX_MEM_INT )
D 16
		panic("qe: Non existant memory interrupt");
	
E 16
I 16
D 17
		printf("qe%d: Nonexistent memory interrupt\n", unit);
E 17
I 17
		log(LOG_ERR, "qe%d: Nonexistent memory interrupt\n", unit);
E 17

E 16
	if( addr->qe_csr & QE_RL_INVALID && sc->rring[sc->rindex].qe_status1 == QE_NOTYET ) {
		buf_addr = (int)&sc->rringaddr[sc->rindex];
		addr->qe_rcvlist_lo = (short)buf_addr;
		addr->qe_rcvlist_hi = (short)(buf_addr >> 16);
	}
D 15
	splx( s );
E 15
}
D 16
 
E 16
I 16

E 16
/*
 * Ethernet interface transmit interrupt.
 */
D 16
 
E 16
I 16

E 16
qetint(unit)
	int unit;
{
	register struct qe_softc *sc = &qe_softc[unit];
D 3
	register struct mbuf *mp, *mp0;
	register first, index;
E 3
	register struct qe_ring *rp;
D 2
	register struct ifrw *ifrw;
E 2
	register struct ifxmt *ifxp;
D 2
	struct ether_header *eh;
E 2
D 3
	int i, status1, status2, setupflag;
E 3
I 3
	int status1, setupflag;
E 3
	short len;
D 16
 
 
E 16
I 16


E 16
	while( sc->otindex != sc->tindex && sc->tring[sc->otindex].qe_status1 != QE_NOTYET && sc->nxmit > 0 ) {
		/*
		 * Save the status words from the descriptor so that it can
		 * be released.
		 */
		rp = &sc->tring[sc->otindex];
		status1 = rp->qe_status1;
D 4
		status2 = rp->qe_status2;
E 4
		setupflag = rp->qe_setup;
		len = (-rp->qe_buf_len) * 2;
		if( rp->qe_odd_end )
			len++;
		/*
		 * Init the buffer descriptor
		 */
D 4
		bzero( rp, sizeof(struct qe_ring));
E 4
I 4
		bzero((caddr_t)rp, sizeof(struct qe_ring));
E 4
		if( --sc->nxmit == 0 )
D 8
			sc->timeout = 0;
E 8
I 8
			sc->qe_if.if_timer = 0;
E 8
		if( !setupflag ) {
			/*
			 * Do some statistics.
			 */
D 8
			sc->is_if.if_opackets++;
			sc->is_if.if_collisions += ( status1 & QE_CCNT ) >> 4;
E 8
I 8
			sc->qe_if.if_opackets++;
			sc->qe_if.if_collisions += ( status1 & QE_CCNT ) >> 4;
E 8
D 2
			/*
			 * Accumulate DECnet statistics
			 */
			if (status1 & QE_CCNT) {
				if (((status1 & QE_CCNT) >> 4) == 1) {
					if (sc->ctrblk.est_single != 0xffffffff)
						sc->ctrblk.est_single++;
				} else {
					if (sc->ctrblk.est_multiple != 0xffffffff)
						sc->ctrblk.est_multiple++;
				}
			}
			if (status1 & QE_FAIL)
				if (sc->ctrblk.est_collis != 0xffff)
					sc->ctrblk.est_collis++;
			if( status1 & QE_ERROR ) { 
E 2
I 2
			if (status1 & QE_ERROR)
E 2
D 8
				sc->is_if.if_oerrors++;
E 8
I 8
				sc->qe_if.if_oerrors++;
E 8
D 2
				if (sc->ctrblk.est_sendfail != 0xffff) {
					sc->ctrblk.est_sendfail++;
					if (status1 & QE_ABORT)
						sc->ctrblk.est_sendfail_bm |= 1;
					if (status1 & QE_NOCAR)
						sc->ctrblk.est_sendfail_bm |= 2;
				}
			}
E 2
			/*
			 * If this was a broadcast packet loop it
D 2
			 * back because the hardware can't hear it's own
			 * transmits and the rwho deamon expects to see them.
			 * This code will have to be expanded to include multi-
			 * cast if the same situation developes.
E 2
I 2
			 * back because the hardware can't hear its own
			 * transmits.
E 2
			 */
D 2
			ifxp = &sc->qeuba.ifu_w[sc->otindex];
			ifrw = &sc->qeuba.ifu_w[sc->otindex].x_ifrw;
			eh = (struct ether_header *)ifrw->ifrw_addr;
 
/*
 * This is a Kludge to do a fast check to see if the ethernet
 * address is all 1's, the ethernet broadcast addr, and loop the
 * packet back.
 */
 
#define QUAD(x) (*(long *)((x)->ether_dhost))
#define ESHORT(x)	(*(short *)(&((x)->ether_dhost[4])))
 
			if(QUAD(eh) == -1 && ESHORT(eh) == -1){
				qeread(sc, ifrw, len, ifxp->x_xtofree);
				ifxp->x_xtofree =0;
			}else if( ifxp->x_xtofree ) {
				m_freem( ifxp->x_xtofree );
				ifxp->x_xtofree = 0;
E 2
I 2
			ifxp = &sc->qe_ifw[sc->otindex];
D 7
			if (bcmp((caddr_t)ifxp->ifw_addr,
			    (caddr_t)etherbroadcastaddr,
			    sizeof(etherbroadcastaddr)) == 0)
				qeread(sc, &ifxp->ifrw, len);
E 7
I 7
			if (bcmp((caddr_t)((struct ether_header *)ifxp->ifw_addr)->ether_dhost,
			   (caddr_t)etherbroadcastaddr,
			   sizeof(etherbroadcastaddr)) == 0)
				qeread(sc, &ifxp->ifrw,
				    len - sizeof(struct ether_header));
E 7
			if (ifxp->ifw_xtofree) {
				m_freem(ifxp->ifw_xtofree);
				ifxp->ifw_xtofree = 0;
E 2
			}
		}
D 2
		sc->otindex = ++sc->otindex % nNXMT;
E 2
I 2
		sc->otindex = ++sc->otindex % NXMT;
E 2
	}
	qestart( unit );
}
D 16
 
E 16
I 16

E 16
/*
 * Ethernet interface receiver interrupt.
D 16
 * If can't determine length from type, then have to drop packet.  
 * Othewise decapsulate packet based on type and pass to type specific 
E 16
I 16
 * If can't determine length from type, then have to drop packet.
 * Othewise decapsulate packet based on type and pass to type specific
E 16
 * higher-level input routine.
 */
qerint(unit)
	int unit;
{
	register struct qe_softc *sc = &qe_softc[unit];
D 3
	register struct ifnet *ifp = &sc->is_if;
E 3
	register struct qe_ring *rp;
	int len, status1, status2;
	int bufaddr;
D 3
	struct ether_header *eh;
E 3
D 16
 
E 16
I 16

E 16
	/*
	 * Traverse the receive ring looking for packets to pass back.
	 * The search is complete when we find a descriptor not in use.
	 *
	 * As in the transmit case the deqna doesn't honor it's own protocols
	 * so there exists the possibility that the device can beat us around
	 * the ring. The proper way to guard against this is to insure that
	 * there is always at least one invalid descriptor. We chose instead
	 * to make the ring large enough to minimize the problem. With a ring
	 * size of 4 we haven't been able to see the problem. To be safe we
	 * doubled that to 8.
	 *
	 */
D 2
	for( ; sc->rring[sc->rindex].qe_status1 != QE_NOTYET ; sc->rindex = ++sc->rindex % nNRCV ){
E 2
I 2
	for( ; sc->rring[sc->rindex].qe_status1 != QE_NOTYET ; sc->rindex = ++sc->rindex % NRCV ){
E 2
		rp = &sc->rring[sc->rindex];
		status1 = rp->qe_status1;
		status2 = rp->qe_status2;
D 4
		bzero( rp, sizeof(struct qe_ring));
E 4
I 4
		bzero((caddr_t)rp, sizeof(struct qe_ring));
E 4
		if( (status1 & QE_MASK) == QE_MASK )
			panic("qe: chained packet");
D 2
		len = ((status1 & QE_RBL_HI) | (status2 & QE_RBL_LO));
		if( ! (ifp->if_flags & IFF_LOOPBACK) ) 
			len += 60;
E 2
I 2
		len = ((status1 & QE_RBL_HI) | (status2 & QE_RBL_LO)) + 60;
E 2
D 8
		sc->is_if.if_ipackets++;
E 8
I 8
		sc->qe_if.if_ipackets++;
E 8
D 16
 
E 16
I 16

E 16
D 2
		if( ! (ifp->if_flags & IFF_LOOPBACK) ) {
			if( status1 & QE_ERROR ) {
				sc->is_if.if_ierrors++;
				if ((status1 & (QE_OVF | QE_CRCERR | QE_FRAME)) &&
					(sc->ctrblk.est_recvfail != 0xffff)) {
					sc->ctrblk.est_recvfail++;
					if (status1 & QE_OVF)
						sc->ctrblk.est_recvfail_bm |= 4;
					if (status1 & QE_CRCERR)
						sc->ctrblk.est_recvfail_bm |= 1;
					if (status1 & QE_FRAME)
						sc->ctrblk.est_recvfail_bm |= 2;
				}
			} else {
				/*
				 * We don't process setup packets.
				 */
				if( !(status1 & QE_ESETUP) )
					qeread(sc, &sc->qeuba.ifu_r[sc->rindex],
						len - sizeof(struct ether_header),0);
			}
		} else {
			eh = (struct ether_header *)sc->qeuba.ifu_r[sc->rindex].ifrw_addr;
			if ( bcmp(eh->ether_dhost, sc->is_addr, 6) == NULL )
					qeread(sc, &sc->qeuba.ifu_r[sc->rindex],
						len - sizeof(struct ether_header),0);
E 2
I 2
D 7
		if (status1 & QE_ERROR)
			sc->is_if.if_ierrors++;
		else {
E 7
I 7
		if (status1 & QE_ERROR) {
			if ((status1 & QE_RUNT) == 0)
D 8
				sc->is_if.if_ierrors++;
E 8
I 8
				sc->qe_if.if_ierrors++;
E 8
		} else {
E 7
			/*
			 * We don't process setup packets.
			 */
			if( !(status1 & QE_ESETUP) )
				qeread(sc, &sc->qe_ifr[sc->rindex],
					len - sizeof(struct ether_header));
E 2
		}
		/*
		 * Return the buffer to the ring
		 */
D 2
		bufaddr = sc->qeuba.ifu_r[sc->rindex].ifrw_info & mask;
E 2
I 2
D 15
		bufaddr = (int)sc->qe_ifr[sc->rindex].ifrw_info & mask;
E 15
I 15
		bufaddr = (int)UBAI_ADDR(sc->qe_ifr[sc->rindex].ifrw_info);
E 15
E 2
		rp->qe_buf_len = -((MAXPACKETSIZE)/2);
		rp->qe_addr_lo = (short)bufaddr;
		rp->qe_addr_hi = (short)((int)bufaddr >> 16);
		rp->qe_flag = rp->qe_status1 = QE_NOTYET;
		rp->qe_valid = 1;
	}
}
/*
 * Ethernet output routine.
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
 */
qeoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
	int type, s, error;
	u_char edst[6];
	struct in_addr idst;
D 3
	struct protosw *pr;
E 3
	register struct qe_softc *is = &qe_softc[ifp->if_unit];
	register struct mbuf *m = m0;
	register struct ether_header *eh;
	register int off;
I 2
	int usetrailers;
E 2
D 16
 
E 16
I 16

E 16
I 2
	if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) != (IFF_UP|IFF_RUNNING)) {
		error = ENETDOWN;
		goto bad;
	}

E 2
	switch (dst->sa_family) {
D 16
 
E 16
I 16

E 16
#ifdef INET
	case AF_INET:
D 2
		if (nINET == 0) {
			printf("qe%d: can't handle af%d\n", ifp->if_unit,
				dst->sa_family);
			error = EAFNOSUPPORT;
			goto bad;
		}
E 2
		idst = ((struct sockaddr_in *)dst)->sin_addr;
D 2
		if (!arpresolve(&is->is_ac, m, &idst, edst))
E 2
I 2
D 8
		if (!arpresolve(&is->is_ac, m, &idst, edst, &usetrailers))
E 8
I 8
		if (!arpresolve(&is->qe_ac, m, &idst, edst, &usetrailers))
E 8
E 2
			return (0);	/* if not yet resolved */
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
D 2
		/* need per host negotiation */
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
		if (off > 0 && (off & 0x1ff) == 0 &&
			m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
E 2
I 2
		if (usetrailers && off > 0 && (off & 0x1ff) == 0 &&
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
E 2
			type = ETHERTYPE_TRAIL + (off>>9);
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
			*mtod(m, u_short *) = htons((u_short)ETHERTYPE_IP);
			*(mtod(m, u_short *) + 1) = htons((u_short)m->m_len);
D 2
			goto gottraqeertype;
E 2
I 2
			goto gottrailertype;
E 2
		}
		type = ETHERTYPE_IP;
		off = 0;
		goto gottype;
#endif
I 2
#ifdef NS
	case AF_NS:
		type = ETHERTYPE_NS;
 		bcopy((caddr_t)&(((struct sockaddr_ns *)dst)->sns_addr.x_host),
		    (caddr_t)edst, sizeof (edst));
		off = 0;
		goto gottype;
#endif

E 2
D 16
 
E 16
I 16

E 16
	case AF_UNSPEC:
		eh = (struct ether_header *)dst->sa_data;
 		bcopy((caddr_t)eh->ether_dhost, (caddr_t)edst, sizeof (edst));
		type = eh->ether_type;
		goto gottype;
D 16
 
E 16
I 16

E 16
	default:
D 2
		/*
		 * Try to find other address families and call protocol
		 * specific output routine.
		 */
		if (pr = iffamily_to_proto(dst->sa_family)) {
			(*pr->pr_ifoutput)(ifp, m0, dst, &type, (char *)edst);
			goto gottype;
		} else {
			printf("qe%d: can't handle af%d\n", ifp->if_unit,
				dst->sa_family);
			error = EAFNOSUPPORT;
			goto bad;
		}
E 2
I 2
		printf("qe%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
		error = EAFNOSUPPORT;
		goto bad;
E 2
	}
D 16
 
E 16
I 16

E 16
D 2
gottraqeertype:
E 2
I 2
gottrailertype:
E 2
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
D 16
 
E 16
I 16

E 16
gottype:
	/*
	 * Add local net header.  If no space in first mbuf,
	 * allocate another.
	 */
D 2
	if (m->m_off > MMAXOFF || MMINOFF + sizeof (struct ether_header) > m->m_off) {
E 2
I 2
	if (m->m_off > MMAXOFF ||
	    MMINOFF + sizeof (struct ether_header) > m->m_off) {
E 2
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
 	bcopy((caddr_t)edst, (caddr_t)eh->ether_dhost, sizeof (edst));
D 8
 	bcopy((caddr_t)is->is_addr, (caddr_t)eh->ether_shost, sizeof (is->is_addr));
E 8
I 8
 	bcopy((caddr_t)is->qe_addr, (caddr_t)eh->ether_shost, sizeof (is->qe_addr));
E 8
D 16
 
E 16
I 16

E 16
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
	qestart(ifp->if_unit);
	splx(s);
	return (0);
D 16
 
E 16
I 16

E 16
bad:
	m_freem(m0);
	return (error);
}
D 16
 
 
E 16
I 16


E 16
/*
 * Process an ioctl request.
 */
qeioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
	struct qe_softc *sc = &qe_softc[ifp->if_unit];
D 2
	struct uba_device *ui = qeinfo[ifp->if_unit];
	struct qedevice *addr = (struct qedevice *)ui->ui_addr;
	struct sockaddr *sa;
	struct sockaddr_in *sin;
	struct ifreq *ifr = (struct ifreq *)data;
	struct ifdevea *ifd = (struct ifdevea *)data;
	struct ctrreq *ctr = (struct ctrreq *)data;
	struct protosw *pr;
E 2
	struct ifaddr *ifa = (struct ifaddr *)data;
D 2
	int i,j = -1,s = splimp(), error = 0;
E 2
I 2
D 3
	int i, s = splimp(), error = 0;
E 3
I 3
	int s = splimp(), error = 0;
E 3
E 2
D 16
 
E 16
I 16

E 16
	switch (cmd) {
D 16
 
E 16
I 16

E 16
D 2
	case SIOCENABLBACK:
		printf("qe%d: internal loopback enable requested\n", ifp->if_unit);
                ifp->if_flags |= IFF_LOOPBACK;
#ifdef notdef
		if((ifp->if_flags |= IFF_LOOPBACK) & IFF_RUNNING)
			if_rtinit(ifp, -1);
#endif
		qerestart( sc );
		break;
 
	case SIOCDISABLBACK:
		printf("qe%d: internal loopback disable requested\n", ifp->if_unit);
                ifp->if_flags &= ~IFF_LOOPBACK;
#ifdef notdef
		if((ifp->if_flags &= ~IFF_LOOPBACK) & IFF_RUNNING)
			if_rtinit(ifp, -1);
#endif
		qerestart( sc );
		qeinit( ifp->if_unit );
		break;
 
	case SIOCRPHYSADDR:
		bcopy(sc->is_addr, ifd->current_pa, 6);
		for( i = 0; i < 6; i++ )
			ifd->default_pa[i] = addr->qe_sta_addr[i] & 0xff;
		break;
 
	case SIOCSPHYSADDR:
		bcopy(ifr->ifr_addr.sa_data,sc->is_addr,MULTISIZE);
		for ( i = 0; i < 6; i++ )
			sc->setup_pkt[i][1] = sc->is_addr[i];
		if (ifp->if_flags & IFF_RUNNING) {
			qesetup( sc );
#ifdef notdef
			if_rtinit(ifp, -1);
#endif
		}
		qeinit(ifp->if_unit);
		break;
 
	case SIOCDELMULTI:
	case SIOCADDMULTI:
		if (cmd == SIOCDELMULTI) {
			for (i = 0; i < NMULTI; i++)
				if (bcmp(&sc->multi[i],ifr->ifr_addr.sa_data,MULTISIZE) == 0) {
					if (--sc->muse[i] == 0)
						bcopy(qunused_multi,&sc->multi[i],MULTISIZE);
				}
		} else {
			for (i = 0; i < NMULTI; i++) {
				if (bcmp(&sc->multi[i],ifr->ifr_addr.sa_data,MULTISIZE) == 0) {
					sc->muse[i]++;
					goto done;
				}
				if (bcmp(&sc->multi[i],qunused_multi,MULTISIZE) == 0)
					j = i;
			}
			if (j == -1) {
				printf("qe%d: SIOCADDMULTI failed, multicast list full: %d\n",ui->ui_unit,NMULTI);
				error = ENOBUFS;
				goto done;
			}
			bcopy(ifr->ifr_addr.sa_data, &sc->multi[j], MULTISIZE);
			sc->muse[j]++;
		}
		for ( i = 0; i < 6; i++ )
			sc->setup_pkt[i][1] = sc->is_addr[i];
		if (ifp->if_flags & IFF_RUNNING) {
			qesetup( sc );
		}
		break;
 
	case SIOCRDCTRS:
	case SIOCRDZCTRS:
		ctr->ctr_ether = sc->ctrblk;
		ctr->ctr_type = CTR_ETHER;
		ctr->ctr_ether.est_seconds = (time.tv_sec - sc->ztime) > 0xfffe ? 0xffff : (time.tv_sec - sc->ztime);
		if (cmd == SIOCRDZCTRS) {
			sc->ztime = time.tv_sec;
			bzero(&sc->ctrblk, sizeof(struct estat));
		}
		break;
 
E 2
	case SIOCSIFADDR:
		ifp->if_flags |= IFF_UP;
		qeinit(ifp->if_unit);
		switch(ifa->ifa_addr.sa_family) {
#ifdef INET
		case AF_INET:
			((struct arpcom *)ifp)->ac_ipaddr =
				IA_SIN(ifa)->sin_addr;
			arpwhohas((struct arpcom *)ifp, &IA_SIN(ifa)->sin_addr);
			break;
#endif
D 2
 
		default:
			if (pr=iffamily_to_proto(ifa->ifa_addr.sa_family)) {
				error = (*pr->pr_ifioctl)(ifp, cmd, data);
			}
E 2
I 2
#ifdef NS
		case AF_NS:
		    {
			register struct ns_addr *ina = &(IA_SNS(ifa)->sns_addr);
D 16
			
E 16
I 16

E 16
			if (ns_nullhost(*ina))
D 8
				ina->x_host = *(union ns_host *)(sc->is_addr);
E 8
I 8
				ina->x_host = *(union ns_host *)(sc->qe_addr);
E 8
			else
				qe_setaddr(ina->x_host.c_host, ifp->if_unit);
E 2
			break;
I 2
		    }
#endif
E 2
		}
		break;
I 2

	case SIOCSIFFLAGS:
		if ((ifp->if_flags & IFF_UP) == 0 &&
		    sc->qe_flags & QEF_RUNNING) {
			((struct qedevice *)
			   (qeinfo[ifp->if_unit]->ui_addr))->qe_csr = QE_RESET;
			sc->qe_flags &= ~QEF_RUNNING;
D 6
		} else if (ifp->if_flags & IFF_UP &&
		    (sc->qe_flags & QEF_RUNNING) == 0)
E 6
I 6
D 17
		} else if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) ==
		    IFF_RUNNING && (sc->qe_flags & QEF_RUNNING) == 0)
E 6
D 4
			qerestart(ifp->if_unit);
E 4
I 4
			qerestart(sc);
E 17
I 17
		} else if (ifp->if_flags & IFF_UP &&
		    (sc->qe_flags & QEF_RUNNING) == 0)
			qeinit(ifp->if_unit);
E 17
E 4
		break;

E 2
	default:
		error = EINVAL;
D 16
 
E 16
I 16

E 16
	}
D 3
done:	splx(s);
E 3
I 3
	splx(s);
E 3
	return (error);
}
D 16
 
E 16
I 16

E 16
I 2
/*
 * set ethernet address for unit
 */
qe_setaddr(physaddr, unit)
	u_char *physaddr;
	int unit;
{
	register struct qe_softc *sc = &qe_softc[unit];
D 4
	struct uba_device *ui = qeinfo[unit];
	struct qedevice *addr = (struct qedevice *)ui->ui_addr;
E 4
	register int i;

	for (i = 0; i < 6; i++)
D 8
		sc->setup_pkt[i][1] = sc->is_addr[i] = physaddr[i];
E 8
I 8
		sc->setup_pkt[i][1] = sc->qe_addr[i] = physaddr[i];
E 8
	sc->qe_flags |= QEF_SETADDR;
D 8
	if (sc->is_if.if_flags & IFF_RUNNING)
E 8
I 8
D 17
	if (sc->qe_if.if_flags & IFF_RUNNING)
E 17
I 17
	if (sc->qe_flags & QEF_RUNNING)
E 17
E 8
		qesetup(sc);
	qeinit(unit);
}
E 2
D 16
 
 
E 16
I 16


E 16
/*
 * Initialize a ring descriptor with mbuf allocation side effects
 */
D 4
qeinitdesc( rp, buf, len )
E 4
I 4
qeinitdesc(rp, addr, len)
E 4
	register struct qe_ring *rp;
D 3
	char *buf; 			/* mapped address	*/
E 3
I 3
D 4
	char *addr; 			/* mapped address	*/
E 4
I 4
	caddr_t addr; 			/* mapped address */
E 4
E 3
	int len;
{
	/*
	 * clear the entire descriptor
	 */
D 4
	bzero( rp, sizeof(struct qe_ring));
E 4
I 4
	bzero((caddr_t)rp, sizeof(struct qe_ring));
E 4
D 16
 
E 16
I 16

E 16
	if( len ) {
		rp->qe_buf_len = -(len/2);
D 3
		rp->qe_addr_lo = (short)buf;
		rp->qe_addr_hi = (short)((int)buf >> 16);
E 3
I 3
		rp->qe_addr_lo = (short)addr;
		rp->qe_addr_hi = (short)((int)addr >> 16);
E 3
	}
}
/*
 * Build a setup packet - the physical address will already be present
 * in first column.
 */
qesetup( sc )
struct qe_softc *sc;
{
D 3
	int i, j, offset = 0, next = 3;
E 3
I 3
	register i, j;
E 3
D 16
 
E 16
I 16

E 16
	/*
	 * Copy the target address to the rest of the entries in this row.
	 */
	 for ( j = 0; j < 6 ; j++ )
		for ( i = 2 ; i < 8 ; i++ )
			sc->setup_pkt[j][i] = sc->setup_pkt[j][1];
	/*
	 * Duplicate the first half.
	 */
D 4
	bcopy(sc->setup_pkt, sc->setup_pkt[8], 64);
E 4
I 4
	bcopy((caddr_t)sc->setup_pkt[0], (caddr_t)sc->setup_pkt[8], 64);
E 4
	/*
	 * Fill in the broadcast address.
	 */
	for ( i = 0; i < 6 ; i++ )
		sc->setup_pkt[i][2] = 0xff;
D 2
	/*
	 * If the device structure is available fill in the multicast address
	 * in the rest of the setup packet.
	 */
	for ( i = 0; i < NMULTI; i++ ) {
		if (bcmp(&sc->multi[i],qunused_multi,MULTISIZE) != 0) {
			for ( j = 0; j < 6; j++ )
				sc->setup_pkt[offset+j][next] = sc->multi[i].qm_char[j];
			if (++next == 8) {
				next = 1;
				offset = 8;
			}
		}
	}
E 2
	sc->setupqueued++;
}
I 2

E 2
/*
D 2
 * Routines supporting Q-BUS network interfaces.
 */
 
/*
 * Init Q-BUS for interface on uban whose headers of size hlen are to
 * end on a page boundary.  We allocate a Q-BUS map register for the page
 * with the header, and nmr more Q-BUS map registers for i/o on the adapter,
 * doing this for each receive and transmit buffer.  We also
 * allocate page frames in the mbuffer pool for these pages.
 */
qe_ubainit(ifu, uban, hlen, nmr, mptr)
	register struct qeuba *ifu;
	int uban, hlen, nmr;
	char *mptr;
{
	register caddr_t cp, dp;
	register struct ifrw *ifrw;
	register struct ifxmt *ifxp;
	int i, ncl;
 
	ncl = clrnd(nmr + CLSIZE) / CLSIZE;
	if (ifu->ifu_r[0].ifrw_addr)
		/*
		 * If the first read buffer has a non-zero
		 * address, it means we have already allocated core
		 */
		cp = ifu->ifu_r[0].ifrw_addr - (CLBYTES - hlen);
	else {
		cp = mptr;
		if (cp == 0)
			return (0);
		ifu->ifu_hlen = hlen;
		ifu->ifu_uban = uban;
		ifu->ifu_uba = uba_hd[uban].uh_uba;
		dp = cp + CLBYTES - hlen;
		for (ifrw = ifu->ifu_r; ifrw < &ifu->ifu_r[nNRCV]; ifrw++) {
			ifrw->ifrw_addr = dp;
			dp += ncl * CLBYTES;
		}
		for (ifxp = ifu->ifu_w; ifxp < &ifu->ifu_w[nNXMT]; ifxp++) {
			ifxp->x_ifrw.ifrw_addr = dp;
			dp += ncl * CLBYTES;
		}
	}
	/* allocate for receive ring */
	for (ifrw = ifu->ifu_r; ifrw < &ifu->ifu_r[nNRCV]; ifrw++) {
		if (qe_ubaalloc(ifu, ifrw, nmr) == 0) {
			struct ifrw *rw;
 
			for (rw = ifu->ifu_r; rw < ifrw; rw++)
				ubarelse(ifu->ifu_uban, &rw->ifrw_info);
			goto bad;
		}
	}
	/* and now transmit ring */
	for (ifxp = ifu->ifu_w; ifxp < &ifu->ifu_w[nNXMT]; ifxp++) {
		ifrw = &ifxp->x_ifrw;
		if (qe_ubaalloc(ifu, ifrw, nmr) == 0) {
			struct ifxmt *xp;
 
			for (xp = ifu->ifu_w; xp < ifxp; xp++)
				ubarelse(ifu->ifu_uban, &xp->x_ifrw.ifrw_info);
			for (ifrw = ifu->ifu_r; ifrw < &ifu->ifu_r[nNRCV]; ifrw++)
				ubarelse(ifu->ifu_uban, &ifrw->ifrw_info);
			goto bad;
		}
		for (i = 0; i < nmr; i++)
			ifxp->x_map[i] = ifrw->ifrw_mr[i];
		ifxp->x_xswapd = 0;
	}
	return (1);
bad:
	m_pgfree(cp, nNTOT * ncl);
	ifu->ifu_r[0].ifrw_addr = 0;
	return(0);
}
 
/*
 * Setup either a ifrw structure by allocating Q-BUS map registers,
 * possibly a buffered data path, and initializing the fields of
 * the ifrw structure to minimize run-time overhead.
 */
static
qe_ubaalloc(ifu, ifrw, nmr)
	struct qeuba *ifu;
	register struct ifrw *ifrw;
	int nmr;
{
	register int info;
 
	info = uballoc(ifu->ifu_uban, ifrw->ifrw_addr,
			nmr*NBPG + ifu->ifu_hlen, ifu->ifu_flags);
	if (info == 0){
		return (0);
	}
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
qeget(ifu, ifrw, totlen, off0)
	register struct qeuba *ifu;
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
 
			MCLGET(m, p);
			if (p == 0)
				goto nopage;
			len = m->m_len = CLBYTES;
			if(cpu == MVAX_I || !claligned(cp))
				goto copy;
 
			/*
			 * Switch pages mapped to Q-BUS with new page p,
			 * as quick form of copy.  Remap Q-BUS and invalidate.
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
qeput(ifu, n, m)
	struct qeuba *ifu;
	int n;
	register struct mbuf *m;
{
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
	ifxp->x_xtofree = m;
	while (m) {
		dp = mtod(m, char *);
		if (cpu != MVAX_I && claligned(cp) && claligned(dp) && m->m_len == CLBYTES) {
			struct pte *pte; int *ip;
			pte = &Mbmap[mtocl(dp)*CLSIZE];
			x = btop(cp - ifrw->ifrw_addr);
			ip = (int *)&ifrw->ifrw_mr[x];
			for (i = 0; i < CLSIZE; i++)
				*ip++ =
				    ifrw->ifrw_proto | pte++->pg_pfnum;
			xswapd |= 1 << (x>>(CLSHIFT-PGSHIFT));
			cp += m->m_len;
		} else {
			bcopy(mtod(m, caddr_t), cp, (unsigned)m->m_len);
			cp += m->m_len;
		}
		m = m->m_next;
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
}
/*
E 2
 * Pass a packet to the higher levels.
 * We deal with the trailer protocol here.
 */
D 2
qeread(sc, ifrw, len, swloop)
E 2
I 2
qeread(sc, ifrw, len)
E 2
	register struct qe_softc *sc;
	struct ifrw *ifrw;
	int len;
D 2
	struct mbuf *swloop;
E 2
{
D 3
	struct ether_header *eh, swloop_eh;
    	struct mbuf *m, *swloop_tmp1, *swloop_tmp2;
	struct protosw *pr;
E 3
I 3
	struct ether_header *eh;
    	struct mbuf *m;
E 3
D 15
	int off, resid;
E 15
I 15
	int off, resid, s;
E 15
	struct ifqueue *inq;
D 16
 
E 16
I 16

E 16
	/*
	 * Deal with trailer protocol: if type is INET trailer
	 * get true type from first 16-bit word past data.
	 * Remember that type was trailer by setting off.
	 */
D 16
 
E 16
I 16

E 16
D 2
 
	if (swloop) {
		eh = mtod(swloop, struct ether_header *);
		swloop_eh = *eh;
		eh = &swloop_eh;
		if ( swloop->m_len > sizeof(struct ether_header))
			m_adj(swloop, sizeof(struct ether_header));
		else {
			MFREE(swloop, swloop_tmp1);
			if ( ! swloop_tmp1 )
				return;
			else
				swloop = swloop_tmp1;
		}
	} else 
		eh = (struct ether_header *)ifrw->ifrw_addr;
 
 
E 2
	eh = (struct ether_header *)ifrw->ifrw_addr;
	eh->ether_type = ntohs((u_short)eh->ether_type);
#define	qedataaddr(eh, off, type)	((type)(((caddr_t)((eh)+1)+(off))))
	if (eh->ether_type >= ETHERTYPE_TRAIL &&
	    eh->ether_type < ETHERTYPE_TRAIL+ETHERTYPE_NTRAILER) {
		off = (eh->ether_type - ETHERTYPE_TRAIL) * 512;
		if (off >= ETHERMTU)
			return;		/* sanity */
D 2
		if (swloop) {
			struct mbuf *mprev, *m0 = swloop;
/* need to check this against off */
			mprev = m0;
			while (swloop->m_next){/*real header at end of chain*/
				mprev = swloop;
				swloop = swloop->m_next;
			}
			/* move to beginning of chain */
			mprev->m_next = 0;
			swloop->m_next = m0;
			eh->ether_type = ntohs( *mtod(swloop, u_short *));
		} else {
		        eh->ether_type = ntohs(*qedataaddr(eh,off, u_short *));
			resid = ntohs(*(qedataaddr(eh, off+2, u_short *)));
			if (off + resid > len)
			     return;		/* sanity */
			len = off + resid;
		}
	} else {
E 2
I 2
		eh->ether_type = ntohs(*qedataaddr(eh,off, u_short *));
		resid = ntohs(*(qedataaddr(eh, off+2, u_short *)));
		if (off + resid > len)
		     return;		/* sanity */
		len = off + resid;
	} else
E 2
		off = 0;
D 2
	}
E 2
	if (len == 0)
		return;
D 16
 
E 16
I 16

E 16
	/*
	 * Pull packet off interface.  Off is nonzero if packet
	 * has trailing header; qeget will then force this header
	 * information to be at the front, but we still have to drop
	 * the type and length which are at the front of any trailer data.
	 */
D 2
	if (swloop) {
		m = m_copy(swloop, 0, M_COPYALL);
		m_freem(swloop);
	} else {
		m = qeget(&sc->qeuba, ifrw, len, off);
	}
E 2
I 2
D 8
	m = if_ubaget(&sc->qe_uba, ifrw, len, off, &sc->is_if);
E 8
I 8
	m = if_ubaget(&sc->qe_uba, ifrw, len, off, &sc->qe_if);
E 8
E 2
D 16
 
E 16
I 16

E 16
	if (m == 0)
		return;
D 16
 
E 16
I 16

E 16
	if (off) {
I 2
		struct ifnet *ifp;

		ifp = *(mtod(m, struct ifnet **));
E 2
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
I 2
		*(mtod(m, struct ifnet **)) = ifp;
E 2
	}
D 2
 
 
	/*
	 * Accumulate stats for DECnet
	 */
	sc->ctrblk.est_bytercvd += m->m_len;
	sc->ctrblk.est_blokrcvd++;
 
 
E 2
	switch (eh->ether_type) {
D 2
 
E 2
I 2

E 2
#ifdef INET
	case ETHERTYPE_IP:
D 2
		if (nINET==0) {
			m_freem(m);
			return;
		}
E 2
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;
D 2
 
E 2
I 2

E 2
	case ETHERTYPE_ARP:
D 2
		if (nETHER==0) {
			m_freem(m);
			return;
		}
E 2
D 8
		arpinput(&sc->is_ac, m);
E 8
I 8
		arpinput(&sc->qe_ac, m);
E 8
		return;
#endif
I 2
#ifdef NS
	case ETHERTYPE_NS:
		schednetisr(NETISR_NS);
		inq = &nsintrq;
		break;

#endif
D 16
 
E 16
I 16

E 16
E 2
	default:
D 2
		/*
		 * see if other protocol families defined
		 * and call protocol specific routines.
		 * If no other protocols defined then dump message.
		 */
		if (pr=iftype_to_proto(eh->ether_type))  {
			if ((m = (struct mbuf *)(*pr->pr_ifinput)(m, &sc->is_if, &inq, eh)) == 0)
				return;
		} else {
			if (sc->ctrblk.est_unrecog != 0xffff)
				sc->ctrblk.est_unrecog++;
			m_freem(m);
			return;
		}
E 2
I 2
		m_freem(m);
		return;
E 2
	}
D 16
 
E 16
I 16

E 16
I 15
	s = splimp();
E 15
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		m_freem(m);
D 15
		return;
	}
	IF_ENQUEUE(inq, m);
E 15
I 15
	} else
		IF_ENQUEUE(inq, m);
	splx(s);
E 15
}
I 2

E 2
/*
D 8
 * Watchdog timer routine. There is a condition in the hardware that
E 8
I 8
 * Watchdog timeout routine. There is a condition in the hardware that
E 8
 * causes the board to lock up under heavy load. This routine detects
 * the hang up and restarts the device.
 */
D 8
qewatch()
E 8
I 8
qetimeout(unit)
	int unit;
E 8
{
	register struct qe_softc *sc;
D 8
	register int i;
	int inprogress=0;
E 8
D 16
 
E 16
I 16

E 16
D 2
	for( i=0 ; i<nNQE ; i++ ) {
E 2
I 2
D 8
	for (i = 0; i < NQE; i++) {
E 2
		sc = &qe_softc[i];
D 2
		if( sc->timeout ) 
			if( ++sc->timeout > 3 )
				qerestart( sc );
			else
E 2
I 2
		if (sc->timeout) 
			if (++sc->timeout > 3 ) {
				log(LOG_ERR,
				     "qerestart: restarted qe%d %d\n",
				     i, ++sc->qe_restarts);
				qerestart(sc);
			} else
E 2
				inprogress++;
	}
D 4
	if( inprogress ){
		timeout(qewatch, 0, QE_TIMEO);
E 4
I 4
	if (inprogress) {
		timeout(qewatch, (caddr_t)0, QE_TIMEO);
E 4
		qewatchrun++;
	} else
		qewatchrun=0;
E 8
I 8
	sc = &qe_softc[unit];
	log(LOG_ERR, "qe%d: transmit timeout, restarted %d\n",
D 16
	     unit, ++sc->qe_restarts);
E 16
I 16
	     unit, sc->qe_restarts++);
E 16
	qerestart(sc);
E 8
}
/*
 * Restart for board lockup problem.
 */
D 2
int qe_restarts;
int qe_show_restarts = 0;	/* 1 ==> log with printf, 0 ==> mprintf */
qerestart( sc )
E 2
I 2
qerestart(sc)
E 2
	register struct qe_softc *sc;
{
D 8
	register struct ifnet *ifp = &sc->is_if;
E 8
I 8
	register struct ifnet *ifp = &sc->qe_if;
E 8
	register struct qedevice *addr = sc->addr;
	register struct qe_ring *rp;
	register i;
D 16
 
E 16
I 16

E 16
D 2
	qe_restarts++;
E 2
	addr->qe_csr = QE_RESET;
I 16
	addr->qe_csr &= ~QE_RESET;
E 16
D 8
	sc->timeout = 0;
E 8
	qesetup( sc );
D 2
	for(i = 0, rp = sc->tring; i<nNXMT ; rp++, i++ ){
E 2
I 2
	for (i = 0, rp = sc->tring; i < NXMT; rp++, i++) {
E 2
		rp->qe_flag = rp->qe_status1 = QE_NOTYET;
		rp->qe_valid = 0;
	}
	sc->nxmit = sc->otindex = sc->tindex = sc->rindex = 0;
D 2
	if ( ifp->if_flags & IFF_LOOPBACK )
		addr->qe_csr = QE_RCV_ENABLE | QE_INT_ENABLE | QE_XMIT_INT | QE_RCV_INT | QE_ELOOP;
	else
		addr->qe_csr = QE_RCV_ENABLE | QE_INT_ENABLE | QE_XMIT_INT | QE_RCV_INT | QE_ILOOP;
E 2
I 2
	addr->qe_csr = QE_RCV_ENABLE | QE_INT_ENABLE | QE_XMIT_INT |
	    QE_RCV_INT | QE_ILOOP;
E 2
	addr->qe_rcvlist_lo = (short)sc->rringaddr;
	addr->qe_rcvlist_hi = (short)((int)sc->rringaddr >> 16);
D 2
	for( i = 0 ; sc != &qe_softc[i] ; i++ )
		;
	qestart( i );
	if (qe_show_restarts)
		printf("qerestart: restarted qe%d %d\n", i, qe_restarts);
	else
		mprintf("qerestart: restarted qe%d %d\n", i, qe_restarts);
E 2
I 2
	sc->qe_flags |= QEF_RUNNING;
	qestart(ifp->if_unit);
E 2
}
#endif
E 1
