h37610
s 00000/00000/00890
d D 7.1 86/06/05 17:10:57 mckusick 2 1
c 4.3BSD release version
e
s 00890/00000/00000
d D 6.1 86/04/22 11:59:48 kridle 1 0
c MicroVAX II Integration (KA630)
e
u
U
t
T
I 1

/*
 *	%W% (Berkeley) %G%
 */
#include "qn.h"
#if	NQN > 0
/*
 * DEQNA Ethernet Communications Controller interface
 * Uses multiple buffers defined by NXMT and NRCV. If you make these
 * numbers large, you may have to increase UAMSIZ in ubavar.h.
 * qnwatchdog looks for a hung controller and qntimer is called from
 * softclock to prod the receiver when it runs out of buffers. why
 * isn't there an interrupt when it runs out of buffers??
 * qntimer is not currently used, but qnxtimer is sometimes scheduled
 * in the callout queue to help xmit along.
 * rick macklem, univ. of guelph, guelph, can.
 */
#include "../machine/pte.h"

#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
#include "ioctl.h"
#include "errno.h"

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
#ifdef BBNNET
#define INET
#endif
#ifdef INET
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/in_var.h"
#include "../netinet/ip.h"
#include "../netinet/if_ether.h"
#endif
#ifdef PUP
#include "../netpup/pup.h"
#endif
#ifdef NS
#include "../netns/ns.h"
#include "../netns/ns_if.h"
#endif

#include "../vax/cpu.h"
#include "../vax/mtpr.h"
#include "if_qnreg.h"
#include "if_uba.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"

#define	NXMT	2	/* number of transmit buffers */
#define	NRCV	4	/* number of receive buffers (must be > 1) */
#define	NTOT	(NRCV+NXMT)
#define	QNMRU	1582		/* Maximum packet received before trunc. */
#define	QNTICKS	4		/* # of seconds between probes */
#define	QNHADMSK	0x3
#define	QNADDRMSK	0x3ffff

#define	FLAG	04		/* Flag for ->flag field */
#define	STAT	010		/* Flag for ->stat field */

int	qnprobe(), qnattach(), qnintr();
struct	uba_device *qninfo[NQN];
u_short qnstd[] = { 0774440, 0774460, 0 };
struct	uba_driver qndriver =
	{ qnprobe, 0, qnattach, 0, qnstd, "qn", qninfo };
#define	QNUNIT(x)	minor(x)
int	qnioctl(),qninit(),qnoutput(),qnreset(),qnwatchdog();
extern struct ifnet loif;
void qnxtimer();

/*
 * Ethernet software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * qs_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 * ifscat used to save bus info and mbuf address for output mbufs.
 */
struct	qn_buf {
	struct ether_header db_head;	/* header */
	char	db_data[QNMRU];	/* packet data */
};

struct	qn_softc {
	struct	arpcom qs_ac;		/* Ethernet common part */
#define	qs_if	qs_ac.ac_if		/* network-vqsible interface */
#define	qs_addr	qs_ac.ac_enaddr		/* hardware Ethernet address */
	struct	ifubinfo qs_qnuba;	/* bus interface info. */
	struct	ifrw qs_ifr[NRCV];	/* receive buf info. */
	struct	ifxmt qs_ifw[NXMT];	/* xmit buf info. */
	int	qs_qnubaddr;		/* info. on comm. area */
	struct qn_cbuf *qs_qncp;	/* bus addr. of qn_cbuf */
	int	qs_xsp;			/* Start pnt. of xbdl q */
	int	qs_xep;			/* End pnt. of xmit bdl q */
	u_char	qs_xready;		/* the xbdl is ready to be assigned */
	u_char	qs_xtimer;		/* timeout to start output is set */
	u_char	qs_probe;		/* check for a hung controller */
	int	qs_rsp;			/* start position in receive bdl */
	short	qs_ivec;		/* software settable intr. vec. */
} qn_softc[NQN];

struct qn_bdl {
	u_short b_flag;
	u_short b_haddr;
	u_short b_laddr;
	u_short b_len;
	u_short b_stat1;
	u_short b_stat2;
};

struct qn_cbuf {
	u_char qn_pea[2][256];
	struct qn_bdl qn_xbdl[NXMT+1];
	struct qn_bdl qn_rbdl[NRCV+1];
} qn_cbuf[NQN];

qnprobe(reg)
	caddr_t reg;
{
	register int br, cvec;		/* r11, r10 value-result */
	register struct qn_softc *qs;

#ifdef lint
	br = 0; cvec = br; br = cvec;
	qnintr(0); qnwatchdog(0);
#endif

	br = 0x15;
	qs = &qn_softc[(((int)reg)>>4)&01];
	cvec = qs->qs_ivec = (uba_hd[numuba].uh_lastiv -= 4);
	return(sizeof (struct qndevice));
}

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets. 
 */
qnattach(ui)
	struct uba_device *ui;
{
	register struct qn_softc *qs = &qn_softc[ui->ui_unit];
	register struct ifnet *ifp = &qs->qs_if;
	register struct qndevice *addr = (struct qndevice *)ui->ui_addr;

	ifp->if_unit = ui->ui_unit;
	ifp->if_name = "qn";
	ifp->if_mtu = ETHERMTU;
	ifp->if_flags = IFF_BROADCAST;

	/*
	 * Set the default physical address.
	 */
	qs->qs_addr[0] = (addr->ad0 & 0377);
	qs->qs_addr[1] = (addr->ad1 & 0377);
	qs->qs_addr[2] = (addr->rbl & 0377);
	qs->qs_addr[3] = (addr->rbh & 0377);
	qs->qs_addr[4] = (addr->xbl & 0377);
	qs->qs_addr[5] = (addr->xbh & 0377);
	printf("qn%d: addr=%d:%d:%d:%d:%d:%d\n", ui->ui_unit,
		qs->qs_addr[0]&0377, qs->qs_addr[1]&0377, qs->qs_addr[2]&0377,
		qs->qs_addr[3]&0377, qs->qs_addr[4]&0377, qs->qs_addr[5]&0377);
	ifp->if_init = qninit;
	ifp->if_output = qnoutput;
	ifp->if_ioctl = qnioctl;
	ifp->if_reset = qnreset;
	ifp->if_watchdog = qnwatchdog;
	qs->qs_qnuba.iff_flags = UBA_CANTWAIT;
	if_attach(ifp);
}

/*
 * Reset of interface after UNIBUS reset.
 * If interface qs on specified uba, reset its state.
 */
qnreset(unit, uban)
	int unit, uban;
{
	register struct uba_device *ui;

	if (unit >= NQN || (ui = qninfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_ubanum != uban)
		return;
	printf(" qn%d", unit);
	qn_softc[unit].qs_if.if_flags &= ~IFF_RUNNING;
	qninit(unit);
}

/*
 * Reinit the deqna. Necessary after an NMI or controller hang.
 * Will this ever happen??
 */
qnreinit(unit)
	int unit;
{
	register int i;
	register struct qn_softc *qs = &qn_softc[unit];
	register struct uba_device *ui = qninfo[unit];
	register struct ifnet *ifp = &qs->qs_if;

	ifp->if_flags &= ~IFF_RUNNING;
	printf("qn%d: reinit\n",unit);
	for (i = 0; i < NRCV; i++)
		if (qs->qs_ifr[i].ifrw_info != 0)
			ubarelse(ui->ui_ubanum,&qs->qs_ifr[i].ifrw_info);
	for (i = 0; i < NXMT; i++)
		if (qs->qs_ifw[i].ifw_info != 0)
			ubarelse(ui->ui_ubanum,&qs->qs_ifw[i].ifw_info);
	if (qs->qs_qnubaddr != 0)
		ubarelse(ui->ui_ubanum, &qs->qs_qnubaddr);
	qninit(unit);
}

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 */
qninit(unit)
	int unit;
{
	register u_short *ptr;
	register int i;
	register struct qn_cbuf *qp = &qn_cbuf[unit];
	register struct qn_softc *qs = &qn_softc[unit];
	register struct uba_device *ui = qninfo[unit];
	register struct qndevice *addr;
	register struct ifnet *ifp = &qs->qs_if;
	register struct ifrw *ifrw;
	int s;
	u_long taddr;

	if (ifp->if_addrlist == (struct ifaddr *)0)
		return;

	if (ifp->if_flags & IFF_RUNNING)
		return;
	qs->qs_probe = 0;
	if (if_ubaminit(&qs->qs_qnuba,ui->ui_ubanum,sizeof(struct ether_header),
		(int)btoc(QNMRU),qs->qs_ifr,NRCV,qs->qs_ifw,NXMT) == 0) {
		printf("qn%d: can't initialize\n",unit);
		qs->qs_if.if_flags &= ~IFF_UP;
		return(0);
	}
	addr = (struct qndevice *)ui->ui_addr;
	/* Set up initialization packet */
	for (i = 0; i < 128; i++)
		if ((i & 07) == 0 || (i & 060) == 060)
			qp->qn_pea[0][i] = 0;
		else
			qp->qn_pea[0][i] = qs->qs_addr[(i>>3)&07];
	qp->qn_pea[0][2]=qp->qn_pea[0][10]=qp->qn_pea[0][18]=qp->qn_pea[0][26]
		= qp->qn_pea[0][34] = qp->qn_pea[0][42] = 0xff;
	addr->csr = SR;
	addr->csr = 0;
	addr->vec = qs->qs_ivec;
	qs->qs_qnubaddr = uballoc(ui->ui_ubanum, (caddr_t)qp,
		sizeof(struct qn_cbuf), 0);
	qs->qs_qncp = (struct qn_cbuf *)(qs->qs_qnubaddr & QNADDRMSK);
	for (i = 0; i < 4; i++) {
		ptr = (u_short *)qp->qn_xbdl;
		*ptr++ = BINIT;
		taddr = (u_long)(&qs->qs_qncp->qn_pea[0][0]);
		*ptr++ = VALID|EOM|SETUP|((taddr>>16)&QNHADMSK);
		*ptr++ = taddr & 0xffff;
		*ptr++ = -((0200|(i<<2))>>1);
		*ptr++ = BINIT;
		*ptr++ = 0;
		*ptr++ = 0;
		*ptr = 0;
		taddr = (u_long)(&qs->qs_qncp->qn_xbdl[0]);
		addr->xbl = taddr&0xffff;
		addr->xbh = ((taddr>>16)&QNHADMSK);
		while ((addr->csr & RL) == 0)
			;
		if (i != 3) {
			ptr = (u_short *)qp->qn_rbdl;
			*ptr++ = BINIT;
			taddr = (u_long)(&qs->qs_qncp->qn_pea[1][0]);
			*ptr++ = VALID|((taddr>>16)&QNHADMSK);
			*ptr++ = taddr & 0xffff;
			*ptr++ = -(256>>1);	/* 2's comp. of struct size */
			*ptr++ = BINIT;
			*ptr++ = 01;
			*ptr++ = 0;
			*ptr = 0;
			taddr = (u_long)(&qs->qs_qncp->qn_rbdl[0]);
			addr->rbl = taddr&0xffff;
			addr->rbh = ((taddr>>16)&QNHADMSK);
			while((qp->qn_rbdl[0].b_stat1&LASTNOT)!=0 
				&& (addr->csr&NMI)==0)
				;
		}
	}
	qs->qs_xsp = qs->qs_xep = qs->qs_xready = qs->qs_xtimer = 0;
	/* set up receive list */
	ifrw = &qs->qs_ifr[0];
	ptr = (u_short *)&qn_cbuf[unit].qn_rbdl[0];
	for(i = 0; i < NRCV; i++) {
		*ptr++ = BINIT;
		*ptr++ = ((ifrw->ifrw_info>>16)&QNHADMSK)|VALID;
		*ptr++ = ifrw->ifrw_info&0xffff;
		*ptr++ = -((sizeof(struct qn_buf))>>1);
		*ptr++ = BINIT;
		*ptr++ = 01;
		ifrw++;
	}
	taddr = (u_long)(&qs->qs_qncp->qn_rbdl[0]);
	/* make the bdl circular */
	*ptr++ = BINIT;
	*ptr++ = ((taddr>>16)&QNHADMSK)|VALID|CHAIN;
	*ptr++ = taddr&0xffff;
	qs->qs_rsp = 0;
	s = splimp();
	addr->csr = RI|XI|IE|RE|ILDIS;
	addr->rbl = taddr&0xffff;
	addr->rbh = ((taddr>>16)&QNHADMSK);
	qs->qs_if.if_flags |= IFF_RUNNING;
	if (qs->qs_if.if_snd.ifq_head)
		qnstart(unit);
	qs->qs_if.if_timer = 1;
	splx(s);
	return(1);
}

/*
 * Start output on interface.
 * Get another datagram to send off of the interface queue,
 * and map it to the interface before starting the output.
 */
qnstart(dev)
	dev_t dev;
{
        int unit = QNUNIT(dev);
	register int pos;
	register u_short *ptr;
	register struct qn_softc *qs = &qn_softc[unit];
	register u_long taddr;
	register struct mbuf *m;
	int len;
	struct qndevice *addr = (struct qndevice *)qninfo[unit]->ui_addr;
	int olen;
	u_short ord;

	if (qs->qs_xep > 0)
		return;
	ptr = (u_short *)qn_cbuf[unit].qn_xbdl;
	for (pos = 0; pos < NXMT; pos++) {
		IF_DEQUEUE(&qs->qs_if.if_snd, m);
		if (m == 0)
			break;
		len = if_ubaput(&qs->qs_qnuba,&qs->qs_ifw[pos],m);
		if (qs->qs_qnuba.iff_flags & UBA_NEEDBDP)
			UBAPURGE(qs->qs_qnuba.iff_uba,
				qs->qs_ifw[pos].ifw_bdp);
		if (len < (sizeof(struct ether_header)+ETHERMIN))
			len = ETHERMIN+sizeof(struct ether_header);
		taddr = (qs->qs_ifw[pos].ifw_info & QNADDRMSK);
		ord = VALID|EOM;
		olen = len;
		if ((taddr & 01) != 0) {
			ord |= HIGHS;
			olen++;
		}
		if (((taddr+len) & 01) != 0) {
			ord |= LOWT;
			olen++;
		}
		*ptr++ = BINIT;
		*ptr++ = ((taddr>>16)&QNHADMSK)|ord;
		*ptr++ = taddr & 0xffff;
		*ptr++ = -(olen>>1);
		*ptr++ = BINIT;
		*ptr++ = 0;
		qs->qs_xep = pos+1;
	}
	if (qs->qs_xep <= 0)
		return;
	ptr = &qn_cbuf[unit].qn_xbdl[qs->qs_xep].b_flag;
	*ptr++ = 0;
	*ptr = 0;
	if (addr->csr & XL) {
		taddr = (u_long)(&qs->qs_qncp->qn_xbdl[0]);
		addr->xbl = taddr&0xffff;
		addr->xbh = ((taddr>>16)&QNHADMSK);
	} else {
		qs->qs_xready = 1;
		if (qs->qs_xtimer == 0) {
			qs->qs_xtimer = 1;
			timeout(qnxtimer, (caddr_t)unit, 1);
		}
	}
}

/*
 * Transmit done interrupt.
 */
qnxint(unit)
	int unit;
{
	register int pos;
	register u_short *ptr;
	register struct qn_softc *qs = &qn_softc[unit];
	register struct ifnet *ifp = &qs->qs_if;
	struct qndevice *addr=(struct qndevice *)qninfo[unit]->ui_addr;

	if (addr->csr & XI)
		addr->csr = XI|IE|RE|ILDIS;
	if (qs->qs_xep <= 0)
		return;
	ptr = &qn_cbuf[unit].qn_xbdl[qs->qs_xsp].b_stat1;
	while (qs->qs_xsp < qs->qs_xep) {
		if ((*ptr & (LASTNOT|UERR)) == LASTNOT)
			break;
		if ((*ptr & LASTNOT) == 0) {
			if (*ptr & ABORT)
				ifp->if_collisions += 16;
			else
				ifp->if_collisions += ((*ptr>>4)&0xf);
			if (*ptr & UERR) {
				ifp->if_oerrors++;
				while (*(ptr+1) == 0)
					;
				printf("qn%d:err csr=%o stat=%o tdr=%d\n",
					unit, addr->csr, *ptr, (*(ptr+1))-5);
			}
			ifp->if_opackets++;
		}
		qs->qs_xsp++;
		ptr += 6;
	}
	qs->qs_probe = 0;
	if (qs->qs_xsp >= qs->qs_xep) {
		qs->qs_xsp = qs->qs_xep = 0;
		qnstart(unit);
	}
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
qnrint(unit)
	int unit;
{
	register int i;
	register u_short *ptr, *ptr2;
	register struct qn_softc *qs = &qn_softc[unit];
	register struct qndevice *addr=(struct qndevice *)qninfo[unit]->ui_addr;
	int rlen, invalid;
	u_short stat1, stat2;
	u_long taddr;

	if (addr->csr & RI)
		addr->csr = RI|IE|RE|ILDIS;
	invalid = (addr->csr & RL);
oncemore:
	if (invalid != 0)
		i = qs->qs_rsp = 0;
	else
		i = qs->qs_rsp;
	ptr = &qn_cbuf[unit].qn_rbdl[i].b_stat1;
	do {
		stat1 = *ptr;
		if ((stat1&0xc000) != BINIT || invalid != 0) {
			if ((stat1&0xc000) != BINIT && (stat1&RESETUP) == 0) {
				qs->qs_if.if_ipackets++;
				stat2 = *(ptr+1);
				while (((stat2>>8)&0xff) != (stat2&0xff))
					stat2 = *(ptr+1);
				rlen = ((stat1&0x700)|(stat2&0xff))+60-sizeof(struct
					ether_header);
				if (stat1&UERR || rlen<ETHERMIN || rlen>ETHERMTU) {
					qs->qs_if.if_ierrors++;
				} else
					qnread(qs,&qs->qs_ifr[i],rlen);
			}
			ptr2 = ptr+1;
			*ptr2-- = 01;
			*ptr2-- = BINIT;
			*ptr2-- = -((sizeof(struct qn_buf))>>1);
			taddr = qs->qs_ifr[i].ifrw_info;
			*ptr2-- = taddr&0xffff;
			*ptr2-- = ((taddr>>16)&QNHADMSK)|VALID;
			*ptr2 = BINIT;
		} else
			break;
		if (++i >= NRCV) {
			i = 0;
			if (*(ptr+2) != BINIT || invalid != 0) {
				taddr = (u_long)(&qs->qs_qncp->qn_rbdl[0]);
				ptr += 4;
				*ptr-- = taddr&0xffff;
				*ptr-- = ((taddr>>16)&QNHADMSK)|VALID|CHAIN;
				*ptr = BINIT;
			}
			ptr = &qn_cbuf[unit].qn_rbdl[0].b_stat1;
		} else {
			ptr += 6;
		}
	} while (i != qs->qs_rsp);
	qs->qs_rsp = i;
	if (invalid != 0) {
		qs->qs_rsp = 0;
		taddr = (u_long)(&qs->qs_qncp->qn_rbdl[0]);
		addr->rbl = taddr&0xffff;
		addr->rbh = ((taddr>>16)&QNHADMSK);
	} else if ((invalid = (addr->csr & RL)) != 0)
		goto oncemore;
}

/*
 * Ethernet output routine.
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
 */
qnoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
	int type, s, error;
 	u_char edst[6];
	struct in_addr idst;
	register struct qn_softc *qs = &qn_softc[ifp->if_unit];
	register struct mbuf *m = m0;
	register struct ether_header *eh;
	register int off;

	switch (dst->sa_family) {

#ifdef INET
	case AF_INET:
		idst = ((struct sockaddr_in *)dst)->sin_addr;
 		if (!arpresolve(&qs->qs_ac, m, &idst, edst))
			return (0);	/* if not yet resolved */
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
		/* need per host negotiation */
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
		if (off > 0 && (off & 0x1ff) == 0 &&
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
			type = ETHERTYPE_TRAIL + (off>>9);
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
			*mtod(m, u_short *) = htons((u_short)ETHERTYPE_IP);
			*(mtod(m, u_short *) + 1) = htons((u_short)m->m_len);
			goto gottrailertype;
		}
		type = ETHERTYPE_IP;
		off = 0;
		goto gottype;
#endif
#ifdef NS
	case AF_NS:
		type = ETHERTYPE_NS;
 		bcopy((caddr_t)&(((struct sockaddr_ns *)dst)->sns_addr.x_host),
		(caddr_t)edst, sizeof (edst));
		off = 0;
		goto gottype;
#endif

	case AF_UNSPEC:
		eh = (struct ether_header *)dst->sa_data;
 		bcopy((caddr_t)eh->ether_dhost, (caddr_t)edst, sizeof (edst));
		type = eh->ether_type;
		goto gottype;

	default:
		printf("qn%d: can't handle af%d\n", ifp->if_unit,
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
 	bcopy((caddr_t)edst, (caddr_t)eh->ether_dhost, sizeof (edst));
	bcopy((caddr_t)qs->qs_addr,(caddr_t)eh->ether_shost,6);

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
	qnstart(ifp->if_unit);
	splx(s);
	return (0);

bad:
	m_freem(m0);
	return (error);
}

/* qn interrupt service routine: simply calls qnrint, qnxint as required */
qnintr(unit)
	int unit;
{
	register struct qndevice *addr = (struct qndevice *)qninfo[unit]->ui_addr;

#ifdef VAX630
	splimp();
#endif
	if (addr->csr & NMI) {
		qnreinit(unit);
		return;
	}
	if (addr->csr & (RI|RL))
		qnrint(unit);
	if (addr->csr & XI)
		qnxint(unit);
}

/*
 * A watchdog to probe the transmit interrupt and detect a hung controller?
 * Also reinit an invalid rbdl, can happen if interrupt latency is really
 * high.
 * probe the interrupt routine. The deqna doesn't queue interrupts
 * and can loose one if latency is high.
 */
qnwatchdog(unit)
	int unit;
{
	register struct qndevice *addr=(struct qndevice *)qninfo[unit]->ui_addr;
	register struct qn_softc *qs = &qn_softc[unit];
	int s;

	s = splimp();
	if (qs->qs_if.if_flags & IFF_UP) {
		if (addr->csr & RL)
			qnrint(unit);
		if (qs->qs_xep > 0)
			if (qs->qs_probe++ > QNTICKS)
				qnreinit(unit);
	}
	qs->qs_if.if_timer = 1;
	splx(s);
}

/*
 * This routine is called via. a timeout if the xbdl is ready and needs
 * to be assigned to the deqna.
 */
void qnxtimer(unit)
	caddr_t unit;
{
	register struct qndevice *addr=(struct qndevice *)qninfo[(int)unit]->ui_addr;
	register struct qn_softc *qs = &qn_softc[(int)unit];
	register u_long taddr;
	int s;

	s = splimp();
	qs->qs_xtimer = 0;
	if (qs->qs_xready) {
		if (addr->csr & XL) {
			qs->qs_xready = 0;
			taddr = (u_long)(&qs->qs_qncp->qn_xbdl[0]);
			addr->xbl = taddr&0xffff;
			addr->xbh = ((taddr>>16)&QNHADMSK);
		} else {
			qs->qs_xtimer = 1;
			timeout(qnxtimer, (caddr_t)unit, 1);
		}
	}
	splx(s);
}

#ifdef notdef
/*
 * At software clock interrupt time 
 * probe the interrupt routine. The deqna doesn't queue interrupts
 * and can loose one if latency is high.
 * NOT CURRENTLY USED!!
 */
qntimer()
{
	int qn;
	struct qndevice *addr = (struct qndevice *)qninfo[0]->ui_addr;
	struct qn_softc *qs = qn_softc;
	int s;

	s = splimp();
#if	NQN == 1
	if ((qs->qs_if.if_flags & IFF_UP) != 0)
		if (addr->csr & RL)
			qnrint(0);
#else
	for (qn = 0; qn < NQN; qn++) {
		qs = &qn_softc[qn];
		if ((qs->qs_if.if_flags & IFF_UP) == 0)
			continue;
		addr = (struct qndevice *)qninfo[qn]->ui_addr;
		if (addr->csr & RL)
			qnrint(qn);
	}
#endif
	splx(s);
}
#endif

/*
 * Pass a packet to the higher levels.
 * We deal with the trailer protocol here.
 */
qnread(qs, ifrw, len)
	register struct qn_softc *qs;
	struct ifrw *ifrw;
	int len;
{
	struct ether_header *eh;
    	struct mbuf *m;
	int off, resid;
	int s;
	register struct ifqueue *inq;

	/*
	 * Deal with trailer protocol: if type is PUP trailer
	 * get true type from first 16-bit word past data.
	 * Remember that type was trailer by setting off.
	 */
	eh = (struct ether_header *)ifrw->ifrw_addr;
	eh->ether_type = ntohs((u_short)eh->ether_type);
#define	dedataaddr(eh, off, type)	((type)(((caddr_t)((eh)+1)+(off))))
	if (eh->ether_type >= ETHERTYPE_TRAIL &&
	    eh->ether_type < ETHERTYPE_TRAIL+ETHERTYPE_NTRAILER) {
		off = (eh->ether_type - ETHERTYPE_TRAIL) * 512;
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
	 * has trailing header; if_ubaget will then force this header
	 * information to be at the front, but we still have to drop
	 * the type and length which are at the front of any trailer data.
	 */
	m = if_ubaget(&qs->qs_qnuba,ifrw,len,off,&qs->qs_if);
	if (m == 0)
		return;
	if (off) {
		struct ifnet *ifp;
		ifp = *(mtod(m, struct ifnet **));
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
		*(mtod(m, struct ifnet **)) = ifp;
	}
	switch (eh->ether_type) {

#ifdef INET
	case ETHERTYPE_IP:
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;

	case ETHERTYPE_ARP:
		arpinput(&qs->qs_ac, m);
		return;
#endif
#ifdef	NS
	case ETHERTYPE_NS:
		schednetisr(NETISR_NS);
		inq = &nsintrq;
		break;
#endif
	default:
		m_freem(m);
		return;
	}

	s = splimp();
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		splx(s);
		m_freem(m);
		return;
	}
	IF_ENQUEUE(inq, m);
	splx(s);
}

/*
 * Process an ioctl request.
 */
qnioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
	register struct ifaddr *ifa = (struct ifaddr *)data;
	int s = splimp(), error = 0;

	switch (cmd) {

	case SIOCSIFADDR:
		ifp->if_flags |= IFF_UP;

		switch (ifa->ifa_addr.sa_family) {
#ifdef INET
		case AF_INET:
			qninit(ifp->if_unit);
			((struct arpcom *)ifp)->ac_ipaddr =
				IA_SIN(ifa)->sin_addr;
			arpwhohas((struct arpcom *)ifp, &IA_SIN(ifa)->sin_addr);
			break;
#endif
#ifdef NS
		case AF_NS:
		    {
			register struct ns_addr *ina = &(IA_SNS(ifa)->sns_addr);
			
			if (ns_nullhost(*ina)) {
				ina->x_host = * (union ns_host *) 
				     (qn_softc[ifp->if_unit].qs_addr);
			} else {
				bcopy((caddr_t)ina->x_host.c_host,
				     (caddr_t)qn_softc[ifp->if_unit].qs_addr,6);
			}
			qninit(ifp->if_unit);
			break;
		    }
#endif
		}
		break;

	default:
		error = EINVAL;
	}
	splx(s);
	return (error);
}

#endif
E 1
