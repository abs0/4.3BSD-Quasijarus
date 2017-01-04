h01165
s 00010/00005/00808
d D 7.2 88/06/29 17:36:12 bostic 9 8
c install approved copyright notice
e
s 00000/00000/00813
d D 7.1 88/05/31 08:42:52 karels 8 7
c bring up to revision 7 for tahoe release
e
s 00013/00001/00800
d D 1.6 88/05/26 09:42:44 karels 7 5
c lint
e
s 00013/00001/00800
d R 7.1 88/05/21 18:31:03 karels 6 5
c bring up to revision 7 for tahoe release
e
s 00049/00058/00752
d D 1.5 87/04/29 20:36:31 sam 5 4
c working driver
e
s 00001/00001/00809
d D 1.4 86/12/15 20:52:53 sam 4 3
c std addresses must be 32-bit
e
s 00052/00047/00758
d D 1.3 86/12/15 20:26:03 sam 3 2
c lint
e
s 00452/00804/00353
d D 1.2 86/11/29 13:45:34 sam 2 1
c massive rewrites; must debug when hardware shows up
e
s 01157/00000/00000
d D 1.1 86/07/20 11:25:41 sam 1 0
c date and time created 86/07/20 11:25:41 by sam
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
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
 *
 *	%W% (Berkeley) %G%
 */
E 7

#include "enp.h"
D 2
#define ENPBPTE 128
E 2
#if NENP > 0
D 2

E 2
/*
D 2
 * Modified 3 Com Ethernet Controller interface
E 2
I 2
D 5
 * Modified 3Com Ethernet Controller interface
E 2
 * enp modifications added S. F. Holmgren
I 2
 *
 * UNTESTED WITH 4.3
E 5
I 5
 * CMC ENP-20 Ethernet Controller.
E 5
E 2
 */
D 2

E 2
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
I 2
#include "ioctl.h"
E 2
#include "errno.h"
D 2
#include "time.h"
#include "kernel.h"
E 2
I 2
#include "vmparam.h"
#include "syslog.h"
E 2
#include "uio.h"

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
I 2
#ifdef INET
E 2
#include "../netinet/in.h"
D 2
#include "../h/ioctl.h"

E 2
#include "../netinet/in_systm.h"
I 2
#include "../netinet/in_var.h"
E 2
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/if_ether.h"
I 2
#endif
#ifdef NS
#include "../netns/ns.h"
#include "../netns/ns_if.h"
#endif
E 2

I 2
#include "../tahoe/cpu.h"
#include "../tahoe/pte.h"
#include "../tahoe/mtpr.h"

E 2
#include "../tahoevba/vbavar.h"
D 2
#include "../tahoeif/if_enp.h"
#include "../machine/mtpr.h"
#include "../tahoeif/if_debug.h"
E 2
I 2
#include "../tahoeif/if_enpreg.h"
E 2

D 2
#define ENP0_PHYSADDR	0xf40000	/* board # 0 physical base addr */
#define ENP1_PHYSADDR	0xf60000	/* board # 1 physical base addr */
#define ENPSTART	0xf02000	/* standard enp start addr 	*/
E 2
I 2
D 5
#define	ENPVEC	0xc1
E 5
#define ENPSTART	0xf02000	/* standard enp start addr */
#define	ENPUNIT(dev)	(minor(dev))	/* for enp ram devices */
I 5
/* macros for dealing with longs in i/o space */
#define	ENPGETLONG(a)	((((u_short *)(a))[0] << 16)|(((u_short *)(a))[1]))
#define	ENPSETLONG(a,v) \
   { register u_short *wp = (u_short *)(a); \
     wp[0] = ((u_short *)&(v))[0]; wp[1] = ((u_short *)&(v))[1];}
E 5
E 2

int	enpprobe(), enpattach(), enpintr();
D 2
extern	nulldev();
caddr_t	vtoph();
struct  mbuf *m_tofree();
struct  vba_device *enpinfo[ NENP ];

/*	Maximun 2 controllers per system supported			*/

long  enpstd[] = { ENP0_PHYSADDR+0x1000,ENP1_PHYSADDR+0x1000, 0 };
extern	char	enp0utl[], enp1utl[];	/* enp accessible ram map	*/
char	*enpmap[]= { enp0utl, enp1utl };
extern	long	ENP0map[], ENP1map[];
long	*ENPmap[] = {ENP0map, ENP1map};
long	ENPmapa[] = {0xfff41000, 0xfff61000};
long	enpismapped[NENP];

unsigned short intvec[4] = 
	{ 0xc1, 0xc2, 0xc3, 0xc4 };	/* intrvec of upto 4 enps	*/

E 2
I 2
D 4
long	enpstd[] = { 0xf41000, 0xf61000, 0 };
E 4
I 4
long	enpstd[] = { 0xfff41000, 0xfff61000, 0 };
E 4
struct  vba_device *enpinfo[NENP];
E 2
struct  vba_driver enpdriver = 
D 2
{
/* use of prom based version 
	enpprobe, 0, enpattach, 0, 0,	enpintr,
*/
	enpprobe, 0, nulldev, 0, 
	enpstd,   "enp", enpinfo, "ENP 20", 0
};
E 2
I 2
    { enpprobe, 0, enpattach, 0, enpstd, "enp", enpinfo, "enp-20", 0 };
E 2

D 2
int     enpinit(),
	enpioctl(),
	enpoutput(),
	enpreset(),
	enpbroadcast(),
	enptimeout();

int	enpcopy();

E 2
I 2
int	enpinit(), enpioctl(), enpreset(), enpoutput();
E 2
struct  mbuf *enpget();

D 2
extern  struct ifnet loif;

E 2
/*
 * Ethernet software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * es_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 */
I 2
struct  enp_softc {
	struct  arpcom es_ac;           /* common ethernet structures */
#define es_if		es_ac.ac_if
D 5
#define es_enaddr	es_ac.ac_enaddr
	short	es_flags;		/* flags for devices */
E 5
I 5
#define es_addr	es_ac.ac_enaddr
E 5
	short	es_ivec;		/* interrupt vector */
D 5
	struct	pte *es_map;		/* map for dual ported memory */
	caddr_t	es_ram;			/* virtual address of mapped memory */
E 5
} enp_softc[NENP]; 
extern	struct ifnet loif;
E 2

D 2
struct 	enp_softc	enp_softc[NENP];
long	stat_addr[NENP];	/* enp statistic addr (for nstat use) */
long	ring_addr[NENP];	/* enp dev ring addresses (for nstat use) */
int 	numenp = NENP;
int	enp_intr = 0, 		/* no. of enp_to_host interrupts */
	host_intr = 0;		/* no. of host_to_enp interrupts */
short	enpram[NENP];		/* open/close flags for enp devices */
/*	Debugging tools, used to trace input packets */
extern 	int	printerror;	/* error print flag, from if_ace.c */
int	save_enp_inpkt = 0;
#define	ENPTRACE(X)	if (save_enp_inpkt) X;

struct 	inp_err 	enperr[NENP];

/*
 * Probe for device.
 */

enpprobe(reg)
caddr_t reg;
E 2
I 2
enpprobe(reg, vi)
	caddr_t reg;
	struct vba_device *vi;
E 2
{
D 2
	static	int 	unit=0;
	register ENPDEVICE	*addr = (ENPDEVICE *)reg;
E 2
I 2
	register br, cvec;		/* must be r12, r11 */
	register struct enpdevice *addr = (struct enpdevice *)reg;
	struct enp_softc *es = &enp_softc[vi->ui_unit];
E 2

D 2
	if( (badaddr( addr, 2 ) ) || (badaddr( &addr->enp_ram[0], 2 ) ) )
		return( 0 );
	addr->enp_state = S_ENPRESET; /* controller is reset by vbus reset */
	/* save address of statistic area for nstat uses	*/

	stat_addr[unit] = (long) &(addr->enp_stat); 
	ring_addr[unit++] = (long) &(addr->enp_toenp); 

	return( ENPSIZE );
E 2
I 2
#ifdef lint
I 3
	br = 0; cvec = br; br = cvec;
E 3
	enpintr(0);
#endif
D 3
	if (badaddr(addr, 2) || badaddr(&addr->enp_ram[0], 2))
E 3
I 3
	if (badaddr((caddr_t)addr, 2) || badaddr((caddr_t)&addr->enp_ram[0], 2))
E 3
		return (0);
	es->es_ivec = --vi->ui_hd->vh_lastiv;
	addr->enp_state = S_ENPRESET;		/* reset by VERSAbus reset */
	br = 0x14, cvec = es->es_ivec;		/* XXX */
	return (sizeof (struct enpdevice));
E 2
}

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets. 
 */
D 2

enpattach( md )
register struct vba_device *md;
E 2
I 2
enpattach(ui)
	register struct vba_device *ui;
E 2
{
D 2
	struct enp_softc 	*es = &enp_softc[md->ui_unit];
	register struct ifnet 	*ifp = &es->es_if;
	register ENPDEVICE 	*addr = (ENPDEVICE *)md->ui_addr;
	struct sockaddr_in 	*sin;
E 2
I 2
	struct enp_softc *es = &enp_softc[ui->ui_unit];
	register struct ifnet *ifp = &es->es_if;
D 5
	register struct enpdevice *addr = (struct enpdevice *)ui->ui_addr;
E 5
E 2

D 2
	enpgetaddr( md->ui_unit );

	ifp->if_unit = md->ui_unit;
E 2
I 2
	ifp->if_unit = ui->ui_unit;
E 2
	ifp->if_name = "enp";
	ifp->if_mtu = ETHERMTU;
I 2
D 5
	/*
	 * Get station's addresses.
	 */
D 3
	enpcopy(&addr->enp_addr.e_baseaddr, es->es_enaddr,
E 3
I 3
	enpcopy((u_char *)&addr->enp_addr.e_baseaddr, es->es_enaddr,
E 3
	    sizeof (es->es_enaddr));
	printf("enp%d: hardware address %s\n", ui->ui_unit,
	    ether_sprintf(es->es_enaddr));
	/*
	 * Allocate and map ram.
	 */
	vbmemalloc(128, ((caddr_t)addr)+0x1000, &es->es_map, &es->es_ram);
E 2

E 5
D 2
/*	bcopy(&es->es_boardaddr, es->es_enaddr, sizeof(es->es_enaddr)); */

	sin = (struct sockaddr_in *)&es->es_if.if_addr;
	sin->sin_family = AF_INET;

E 2
	ifp->if_init = enpinit;
	ifp->if_ioctl = enpioctl;
	ifp->if_output = enpoutput;
	ifp->if_reset = enpreset;
I 2
	ifp->if_flags = IFF_BROADCAST;
E 2
	if_attach(ifp);
}

D 2

E 2
/*
D 2
 * Reset of interface after UNIBUS reset.
E 2
I 2
 * Reset of interface after "system" reset.
E 2
 */
D 2
enpreset(unit)
int unit;
E 2
I 2
enpreset(unit, vban)
	int unit, vban;
E 2
{
D 2
	register struct vba_device *md;
E 2
I 2
	register struct vba_device *ui;
E 2

D 2
	if (unit >= NENP || (md = enpinfo[unit]) == 0 || md->ui_alive == 0)
		return(ENODEV);

E 2
I 2
	if (unit >= NENP || (ui = enpinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_vbanum != vban)
		return;
	printf(" enp%d", unit);
E 2
	enpinit(unit);
}

/*
D 2
 * Initialization of interface; clear recorded pending
 * operations.
E 2
I 2
 * Initialization of interface; clear recorded pending operations.
E 2
 */
D 2

enpinit( unit )
int unit;
E 2
I 2
enpinit(unit)
	int unit;
E 2
{
D 2
	struct enp_softc 	*es = &enp_softc[unit];
	ENPDEVICE 		*addr;
	int i, s;
	u_char *cp, *ap;
	register struct ifnet 	*ifp = &es->es_if;
	register struct sockaddr_in *sin, *sinb;

	sin = (struct sockaddr_in *)&ifp->if_addr;

	if ( !enpismapped[unit] ) {
		ioaccess(ENPmap[unit],ENPmapa[unit],ENPBPTE);
		++enpismapped[unit];
	}
	if ((addr = (ENPDEVICE *)enpinfo[unit]->ui_addr) == (ENPDEVICE *)0)
		return(ENODEV);
	s = splimp();
	RESET_ENP( addr );
	DELAY( 200000 );
E 2
I 2
	struct enp_softc *es = &enp_softc[unit];
	register struct vba_device *ui = enpinfo[unit];
	struct enpdevice *addr;
	register struct ifnet *ifp = &es->es_if;
	int s;
E 2

D 2
#ifdef notdef
/* only needed if not downloading ( ie, ROM-resident ENP code) */
	addr->enp_intrvec = intvec[unit];
	ENP_GO( addr,ENPSTART );
	DELAY( 200000 );
/* end of ROM-resident */
#endif notdef

	es->es_if.if_flags |= IFF_UP|IFF_RUNNING; /* open for business*/
	splx(s);

	if_rtinit( &es->es_if,RTF_UP );
	arpwhohas(&es->es_ac, &sin->sin_addr);
E 2
I 2
	if (ifp->if_addrlist == (struct ifaddr *)0)
		return;
	if ((ifp->if_flags & IFF_RUNNING) == 0) {
		addr = (struct enpdevice *)ui->ui_addr;
		s = splimp();
		RESET_ENP(addr);
		DELAY(200000);
D 5
		addr->enp_intrvec = es->es_ivec;
E 5
		es->es_if.if_flags |= IFF_RUNNING;
		splx(s);
	}
E 2
}

D 2

E 2
/*
 * Ethernet interface interrupt.
 */
D 2

enpintr( unit )
E 2
I 2
enpintr(unit)
	int unit;
E 2
{
D 2
	register ENPDEVICE 		*addr;
	register BCB			*bcbp;
	register struct vba_device	 *md;
E 2
I 2
	register struct enpdevice *addr;
	register BCB *bcbp;
E 2

D 2
	enp_intr++;

	if (unit >= NENP || (md = enpinfo[unit]) == 0)
E 2
I 2
	addr = (struct enpdevice *)enpinfo[unit]->ui_addr;
I 3
#if ENP == 30
E 3
	if (!IS_ENP_INTR(addr))
E 2
		return;
D 2

	addr = (ENPDEVICE *)md->ui_addr;

	if( IS_ENP_INTR(addr) == 0 )
		return;

	ACK_ENP_INTR( addr );

	while( (bcbp = (BCB *)ringget( &addr->enp_tohost )) != 0 )
	{
		enpread( &enp_softc[ unit ],bcbp, unit );
		ringput( &addr->enp_enpfree,bcbp ); 
E 2
I 2
	ACK_ENP_INTR(addr);
D 3
	while ((bcbp = (BCB *)ringget(&addr->enp_tohost )) != 0) {
		(void) enpread(&enp_softc[unit], bcbp, unit);
		ringput(&addr->enp_enpfree, bcbp); 
E 3
I 3
#endif
	while ((bcbp = (BCB *)ringget((RING *)&addr->enp_tohost )) != 0) {
		(void) enpread(&enp_softc[unit], bcbp);
		(void) ringput((RING *)&addr->enp_enpfree, bcbp); 
E 3
E 2
	}
D 2
	return(0);
E 2
}

D 2
#define	MAXBLEN	1500
char	errpkt[MAXBLEN];
int	bufptr = 0;
int	maxl_tosave = 200;		/* save only the first 200 bytes */

saverrpkt(errbuf, errtype, len)
register u_char *errbuf;
int errtype, len;
{
	int remain, newptr;

	remain = MAXBLEN - bufptr;
	if (remain < 50)		/* if too small			*/
		return;			/* no space avail		*/
	len = (len > maxl_tosave || len <= 0) ? maxl_tosave : len;
	len = len > remain ? (remain - 2*sizeof(len)): len;
	newptr = bufptr + len + 2*sizeof(len);
	if (newptr <= MAXBLEN) {
		enpcopy((char *)&len, &errpkt[bufptr], sizeof(len));
		enpcopy((char *)&errtype, &errpkt[bufptr+sizeof(len)],
			sizeof(errtype));
		enpcopy(errbuf, &errpkt[bufptr+(2*sizeof(len))], len);
	}
	bufptr = newptr;
}

E 2
/*
 * Read input packet, examine its packet type, and enqueue it.
 */
D 2

enpread( es, bcbp, unit )
struct	enp_softc *es;
register BCB *bcbp;
int	unit;
E 2
I 2
D 3
enpread(es, bcbp, unit)
E 3
I 3
enpread(es, bcbp)
E 3
	struct enp_softc *es;
	register BCB *bcbp;
D 3
	int unit;
E 3
E 2
{
	register struct ether_header *enp;
	struct mbuf *m;
D 2
	long int  s, v;
	register short *vp = (short *)&v,
			*sp;
E 2
I 2
D 3
	long int s;
E 2
	int len, off, resid, enptype;
E 3
I 3
	int s, len, off, resid;
E 3
	register struct ifqueue *inq;

	es->es_if.if_ipackets++; 
D 2

E 2
	/*
	 * Get input data length.
	 * Get pointer to ethernet header (in input buffer).
	 * Deal with trailer protocol: if type is PUP trailer
	 * get true type from first 16-bit word past data.
	 * Remember that type was trailer by setting off.
	 */
D 2

	len = bcbp->b_msglen - SIZEOF_ETHEADER;
#ifdef TAHOE
	sp = (short *)&bcbp->b_addr;
	*vp = *sp; vp[1] = sp[1];
	enp = (struct ether_header *) v;
#else
E 2
I 2
	len = bcbp->b_msglen - sizeof (struct ether_header);
E 2
D 5
	enp = (struct ether_header *)bcbp->b_addr;
E 5
I 5
	enp = (struct ether_header *)ENPGETLONG(&bcbp->b_addr);
E 5
D 2
#endif TAHOE

#define enpdataaddr(enp, off, type) ((type)(((caddr_t)(((char *)enp)+SIZEOF_ETHEADER)+(off))))

	enptype = enp->ether_type;
	if (enptype >= ETHERPUP_TRAIL && enptype < ETHERPUP_TRAIL+ETHERPUP_NTRAILER) 
	{
		off = (enptype - ETHERPUP_TRAIL) * 512;
		if (off >= ETHERMTU) {
			enperr[unit].bad_offset++;
			ENPTRACE(saverrpkt((char *)enp, B_OFFSET, bcbp->b_msglen)); 

			goto badinput;
		}
		enptype = *enpdataaddr(enp, off, u_short *);
		resid = *(enpdataaddr(enp, off+2, u_short *));

		if (off + resid > len) {
			enperr[unit].bad_length++;
			ENPTRACE(saverrpkt((char *)enp, B_LENGTH, bcbp->b_msglen)); 
			goto badinput;
		}
E 2
I 2
#define enpdataaddr(enp, off, type) \
    ((type)(((caddr_t)(((char *)enp)+sizeof (struct ether_header))+(off))))
	enp->ether_type = ntohs((u_short)enp->ether_type);
	if (enp->ether_type >= ETHERTYPE_TRAIL &&
	    enp->ether_type < ETHERTYPE_TRAIL+ETHERTYPE_NTRAILER) {
		off = (enp->ether_type - ETHERTYPE_TRAIL) * 512;
		if (off >= ETHERMTU)
			goto setup;
		enp->ether_type = ntohs(*enpdataaddr(enp, off, u_short *));
		resid = ntohs(*(enpdataaddr(enp, off+2, u_short *)));
		if (off + resid > len)
			goto setup;
E 2
		len = off + resid;
D 2
	} 
	else
E 2
I 2
	} else
E 2
		off = 0;
I 2
	if (len == 0)
		goto setup;
E 2

D 2
	if( len == 0 ) {
		enperr[unit].bad_length++;
		ENPTRACE(saverrpkt((char *)enp, B_LENGTH, bcbp->b_msglen)); 
		goto badinput;
	}
E 2
	/*
	 * Pull packet off interface.  Off is nonzero if packet
	 * has trailing header; enpget will then force this header
	 * information to be at the front, but we still have to drop
	 * the type and length which are at the front of any trailer data.
	 */
I 2
D 5
	m = enpget(bcbp->b_addr, len, off, &es->es_if);
E 5
I 5
	m = enpget((u_char *)enp, len, off, &es->es_if);
E 5
	if (m == 0)
		goto setup;
	if (off) {
		struct ifnet *ifp;
E 2

D 2
	m = enpget(bcbp, len, off);
	if( m == 0 )  {
		enperr[unit].h_nobuffer++; /* host runs out of buf */
		goto badinput;
	}
	if( off )
	{
E 2
I 2
		ifp = *(mtod(m, struct ifnet **));
E 2
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
I 2
		*(mtod(m, struct ifnet **)) = ifp;
E 2
	}
I 2
	switch (enp->ether_type) {
E 2

D 2
	switch (enptype) 
	{
E 2
#ifdef INET
D 2
	case ETHERPUP_IPTYPE:
#ifdef notdef
		arpipin(enp, m);
#endif notdef
E 2
I 2
	case ETHERTYPE_IP:
E 2
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;
D 2

	case ETHERPUP_ARPTYPE:
E 2
I 2
#endif
	case ETHERTYPE_ARP:
E 2
		arpinput(&es->es_ac, m);
D 2
		return(0);
E 2
I 2
		goto setup;

#ifdef NS
	case ETHERTYPE_NS:
		schednetisr(NETISR_NS);
		inq = &nsintrq;
		break;
E 2
#endif
D 2
	default:	/* unrecognized ethernet header */
		enperr[unit].bad_packetype++;
		if (printerror) { 
			printf("\nenp%d: Undefined packet type 0x%x ", unit,
				enp->ether_type);
			printf("from host: %x.%x.%x.%x.%x.%x\n", 
				enp->ether_shost[0], enp->ether_shost[1], 
				enp->ether_shost[2], enp->ether_shost[3],
				enp->ether_shost[4], enp->ether_shost[5]);
		}	/* end debugging aid	*/
		ENPTRACE(saverrpkt((char *)enp, B_PACKETYPE, bcbp->b_msglen)); 
E 2
I 2
	default:
E 2
		m_freem(m);
D 2
		goto badinput;
E 2
I 2
		goto setup;
E 2
	}
D 2

	if (IF_QFULL(inq)) 
	{
		enperr[unit].inq_full++;
E 2
I 2
	if (IF_QFULL(inq)) {
E 2
		IF_DROP(inq);
		m_freem(m);
D 2
		return(0);
E 2
I 2
		goto setup;
E 2
	}
	s = splimp();
	IF_ENQUEUE(inq, m);
	splx(s);
D 2
badinput:
	return(0);         /* sanity */
E 2
I 2
setup:
	return (0);
E 2
}

/*
 * Ethernet output routine. (called by user)
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
 * If destination is this address or broadcast, send packet to
 * loop device to kludge around the fact that 3com interfaces can't
 * talk to themselves.
 */
D 2

E 2
enpoutput(ifp, m0, dst)
D 2
struct ifnet *ifp;
struct mbuf *m0;
struct sockaddr *dst;
E 2
I 2
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
E 2
{
D 2
	int type, s, error;
	struct ether_addr edst;
	struct in_addr idst;

E 2
	register struct enp_softc *es = &enp_softc[ifp->if_unit];
	register struct mbuf *m = m0;
	register struct ether_header *enp;
D 3
	register int off, i;
E 3
I 3
	register int off;
E 3
I 2
	struct mbuf *mcopy = (struct mbuf *)0;
	int type, s, error, usetrailers;
	u_char edst[6];
	struct in_addr idst;
E 2

D 2
	struct mbuf *mcopy = (struct mbuf *) 0;         /* Null */
	int unit = ifp->if_unit;

	switch( dst->sa_family )
	{
E 2
I 2
	if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) != (IFF_UP|IFF_RUNNING)) {
		error = ENETDOWN;
		goto bad;
	}
	switch (dst->sa_family) {
E 2
#ifdef INET
	case AF_INET:
		idst = ((struct sockaddr_in *)dst)->sin_addr;
D 2

		/* translate internet to ethernet address */

		switch(arpresolve(&es->es_ac, m, &idst, &edst)) {

		   	case ARPRESOLVE_WILLSEND:
				return (0);	/* if not yet resolved */
		   	case ARPRESOLVE_BROADCAST:
				mcopy = m_copy(m, 0, (int)M_COPYALL);
				if (mcopy)
					looutput(&loif, mcopy, dst);

				/* falls through ... */
		   	case ARPRESOLVE_OK:
				break;
E 2
I 2
		if (!arpresolve(&es->es_ac, m, &idst, edst, &usetrailers))
			return (0);	/* if not yet resolved */
		if (!bcmp((caddr_t)edst, (caddr_t)etherbroadcastaddr,
		    sizeof (edst)))
			mcopy = m_copy(m, 0, (int)M_COPYALL);
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
		if (usetrailers && off > 0 && (off & 0x1ff) == 0 &&
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
			type = ETHERTYPE_TRAIL + (off>>9);
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
D 5
			*mtod(m, u_short *) = ETHERTYPE_IP;
			*(mtod(m, u_short *) + 1) = m->m_len;
E 5
I 5
			*mtod(m, u_short *) = htons((u_short)ETHERTYPE_IP);
			*(mtod(m, u_short *) + 1) = htons((u_short)m->m_len);
E 5
			goto gottrailertype;
E 2
		}
D 2
		off = ((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
			if (off > 0 && (off & 0x1ff) == 0 &&
			    m->m_off >= MMINOFF + 2 * sizeof (u_short)) 
			{
				type = ETHERPUP_TRAIL + (off>>9);
				m->m_off -= 2 * sizeof (u_short);
				m->m_len += 2 * sizeof (u_short);
				*mtod(m, u_short *) = ETHERPUP_IPTYPE;
				*(mtod(m, u_short *) + 1) = m->m_len;
				goto gottrailertype;
			}

		type = ETHERPUP_IPTYPE;
E 2
I 2
		type = ETHERTYPE_IP;
E 2
		off = 0;
		goto gottype;
#endif
D 2

#ifdef notdef
	case AF_RAW:
		enp = mtod(m, struct ether_header *);
		if (m->m_len < sizeof *enp) 
		{
			error = EMSGSIZE;
			goto bad;
		}
		goto gotheader;
E 2
I 2
#ifdef NS
	case AF_NS:
		bcopy((caddr_t)&(((struct sockaddr_ns *)dst)->sns_addr.x_host),
		    (caddr_t)edst, sizeof (edst));
		if (!bcmp((caddr_t)edst, (caddr_t)&ns_broadhost, sizeof (edst)))
			mcopy = m_copy(m, 0, (int)M_COPYALL);
		else if (!bcmp((caddr_t)edst, (caddr_t)&ns_thishost,
		    sizeof (edst)))
			return (looutput(&loif, m, dst));
		type = ETHERTYPE_NS;
		off = 0;
		goto gottype;
E 2
#endif
D 2

E 2
	case AF_UNSPEC:
		enp = (struct ether_header *)dst->sa_data;
D 2
		bcopy( enp->ether_dhost, &edst, sizeof(edst));
E 2
I 2
		bcopy((caddr_t)enp->ether_dhost, (caddr_t)edst, sizeof (edst));
E 2
		type = enp->ether_type;
		goto gottype;

	default:
D 2
		if (printerror)
		    printf("enp%d: can't handle af%d\n", unit,dst->sa_family);
E 2
I 2
		log(LOG_ERR, "enp%d: can't handle af%d\n",
		    ifp->if_unit, dst->sa_family);
E 2
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
D 2
	    MMINOFF + SIZEOF_ETHEADER > m->m_off) 
	{
E 2
I 2
	    MMINOFF + sizeof (struct ether_header) > m->m_off) {
E 2
		m = m_get(M_DONTWAIT, MT_HEADER);
D 2
		if (m == 0) 
		{
			enperr[unit].h_nobuffer++; /* host runs out of buf */
E 2
I 2
		if (m == 0) {
E 2
			error = ENOBUFS;
			goto bad;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
D 2
		m->m_len = SIZEOF_ETHEADER;
	} 
	else
	{
		m->m_off -= SIZEOF_ETHEADER;
		m->m_len += SIZEOF_ETHEADER;
E 2
I 2
		m->m_len = sizeof (struct ether_header);
	} else {
		m->m_off -= sizeof (struct ether_header);
		m->m_len += sizeof (struct ether_header);
E 2
	}
	enp = mtod(m, struct ether_header *);
D 2
	bcopy( &edst, enp->ether_dhost, sizeof(enp->ether_dhost) );
	enp->ether_type = type;
gotheader:
	bcopy( es->es_enaddr, enp->ether_shost, sizeof(enp->ether_shost));
E 2
I 2
	bcopy((caddr_t)edst, (caddr_t)enp->ether_dhost, sizeof (edst));
D 5
	bcopy((caddr_t)es->es_enaddr, (caddr_t)enp->ether_shost,
	    sizeof (es->es_enaddr));
E 5
I 5
	bcopy((caddr_t)es->es_addr, (caddr_t)enp->ether_shost,
	    sizeof (es->es_addr));
E 5
	enp->ether_type = htons((u_short)type);
E 2

	/*
	 * Queue message on interface if possible 
	 */
D 2

E 2
	s = splimp();	
D 2
	if( enpput( unit,m ) )
	{
E 2
I 2
	if (enpput(ifp->if_unit, m)) {
E 2
		error = ENOBUFS;
D 2
		enperr[unit].c_nobuffer++; /* controller runs out of buf */
E 2
		goto qfull;
	}
D 2
	splx( s );	
E 2
I 2
	splx(s);	
E 2
	es->es_if.if_opackets++; 
D 2
	return(0);
E 2
I 2
	return (mcopy ? looutput(&loif, mcopy, dst) : 0);
E 2
qfull:
D 2
	splx( s );	
E 2
I 2
	splx(s);	
E 2
	m0 = m;
bad:
	m_freem(m0);
D 2
	return(error);
E 2
I 2
	if (mcopy)
		m_freem(mcopy);
	return (error);
E 2
}

/*
D 2
 * Routine to copy from mbuf chain to transmitter
 * buffer in Multibus memory.
E 2
I 2
 * Routine to copy from mbuf chain to transmitter buffer on the VERSAbus.
E 2
 */
D 2

enpput( unit,m )
int unit;
struct mbuf *m;
E 2
I 2
enpput(unit, m)
	int unit;
	struct mbuf *m;
E 2
{
	register BCB *bcbp;
D 2
	register ENPDEVICE *addr;
E 2
I 2
	register struct enpdevice *addr;
E 2
	register struct mbuf *mp;
	register u_char *bp;
D 2
	int	 ctr = 0;
	long int	v;
	register short *vp = (short *)&v,
			*sp;
E 2
I 2
	register u_int len;
	u_char *mcp;
E 2

D 2
	addr = (ENPDEVICE *)enpinfo[ unit ]->ui_addr;

	if ( ringempty( &addr->enp_hostfree ) ) 
			return( 1 );	

	bcbp = (BCB *)ringget( &addr->enp_hostfree );
E 2
I 2
	addr = (struct enpdevice *)enpinfo[unit]->ui_addr;
D 3
	if (ringempty(&addr->enp_hostfree)) 
E 3
I 3
	if (ringempty((RING *)&addr->enp_hostfree)) 
E 3
		return (1);	
D 3
	bcbp = (BCB *)ringget(&addr->enp_hostfree);
E 3
I 3
	bcbp = (BCB *)ringget((RING *)&addr->enp_hostfree);
E 3
E 2
	bcbp->b_len = 0;
D 2
#ifdef TAHOE
	sp = (short *)&bcbp->b_addr;
	*vp = *sp; vp[1] = sp[1];
	bp = (u_char *)v;
#else
E 2
D 5
	bp = (u_char *)bcbp->b_addr;
E 5
I 5
	bp = (u_char *)ENPGETLONG(&bcbp->b_addr);
E 5
D 2
#endif TAHOE
	for (mp = m; mp; mp = mp->m_next) 
	{
		register unsigned len;
		u_char *mcp;

E 2
I 2
	for (mp = m; mp; mp = mp->m_next) {
E 2
		len = mp->m_len;
D 2
		if( len == 0 )
E 2
I 2
		if (len == 0)
E 2
			continue;
D 2
		mcp = mtod( mp,u_char * );
		enpcopy( mcp,bp,len );
E 2
I 2
		mcp = mtod(mp, u_char *);
		enpcopy(mcp, bp, len);
E 2
		bp += len;
		bcbp->b_len += len;
	}
D 2
	bcbp->b_len = max( MINPKTSIZE,bcbp->b_len );
E 2
I 2
D 3
	bcbp->b_len = max(ETHERMIN, bcbp->b_len);
E 3
I 3
D 5
	bcbp->b_len = MAX(ETHERMIN, bcbp->b_len);
E 5
I 5
	bcbp->b_len = MAX(ETHERMIN+sizeof (struct ether_header), bcbp->b_len);
E 5
E 3
E 2
	bcbp->b_reserved = 0;
D 2
	if ( ringput( &addr->enp_toenp,bcbp ) == 1 ) {
		host_intr++;
		INTR_ENP( addr );
	}
E 2
I 2
D 3
	if (ringput(&addr->enp_toenp, bcbp) == 1)
E 3
I 3
	if (ringput((RING *)&addr->enp_toenp, bcbp) == 1)
E 3
		INTR_ENP(addr);
E 2
	m_freem(m);
D 2
	return( 0 );
E 2
I 2
	return (0);
E 2
}

/*
D 2
 * Routine to copy from Multibus memory into mbufs.
E 2
I 2
 * Routine to copy from VERSAbus memory into mbufs.
E 2
 *
 * Warning: This makes the fairly safe assumption that
 * mbufs have even lengths.
 */
struct mbuf *
D 2
enpget( bcbp, totlen, off0 )
register BCB *bcbp;
int totlen, off0;
E 2
I 2
enpget(rxbuf, totlen, off0, ifp)
	u_char *rxbuf;
	int totlen, off0;
	struct ifnet *ifp;
E 2
{
I 2
	register u_char *cp, *mcp;
E 2
	register struct mbuf *m;
D 2
	register int off = off0;
	register unsigned char *cp;
	long int	v;
	register short *vp = (short *)&v,
			*sp;
E 2
I 2
	struct mbuf *top = 0, **mp = &top;
	int len, off = off0;
E 2

D 2
	int len;
	struct mbuf *top = 0;
	struct mbuf **mp = &top;

#ifdef TAHOE
	sp = (short *)&bcbp->b_addr;
	*vp = *sp; vp[1] = sp[1];
	cp = (unsigned char *)v + SIZEOF_ETHEADER;
#else
	cp = (unsigned char *)bcbp->b_addr + SIZEOF_ETHEADER;
#endif TAHOE

	while( totlen > 0 )
	{
		u_char *mcp;

E 2
I 2
	cp = rxbuf + sizeof (struct ether_header);
	while (totlen > 0) {
E 2
		MGET(m, M_DONTWAIT, MT_DATA);
		if (m == 0) 
			goto bad;
D 2
		if( off )
		{
E 2
I 2
		if (off) {
E 2
			len = totlen - off;
D 2
#ifdef TAHOE
			sp = (short *)&bcbp->b_addr;
			*vp = *sp; vp[1] = sp[1];
			cp = (unsigned char *)v + SIZEOF_ETHEADER
				+ off;
#else
			cp = (unsigned char *)bcbp->b_addr + 
				SIZEOF_ETHEADER + off;
#endif TAHOE
		} 
		else
E 2
I 2
			cp = rxbuf + sizeof (struct ether_header) + off;
		} else
E 2
			len = totlen;
D 2


		if (len >= CLBYTES) {
E 2
I 2
		if (len >= NBPG) {
E 2
D 3
			struct mbuf *p;

E 3
D 2
			MCLGET(p, 1);
			if (p != 0) {
				m->m_len = len = CLBYTES;
				m->m_off = (int)p - (int)m;
			} else  {
E 2
I 2
			MCLGET(m);
			if (m->m_len == CLBYTES)
				m->m_len = len = MIN(len, CLBYTES);
			else
E 2
				m->m_len = len = MIN(MLEN, len);
D 2
				m->m_off = MMINOFF;
				}
		} else  { 
E 2
I 2
		} else {
E 2
			m->m_len = len = MIN(MLEN, len);
			m->m_off = MMINOFF;
		}
D 2

E 2
		mcp = mtod(m, u_char *);
I 2
		if (ifp) {
			/*
			 * Prepend interface pointer to first mbuf.
			 */
			*(mtod(m, struct ifnet **)) = ifp;
			mcp += sizeof (ifp);
			len -= sizeof (ifp);
			ifp = (struct ifnet *)0;
		}
E 2
D 3
		enpcopy(cp, mcp, len);
E 3
I 3
		enpcopy(cp, mcp, (u_int)len);
E 3
		cp += len;
		*mp = m;
		mp = &m->m_next;
D 2
		if (off == 0) 
		{
E 2
I 2
		if (off == 0) {
E 2
			totlen -= len;
			continue;
		}
		off += len;
D 2
		if (off == totlen) 
		{
#ifdef TAHOE
			sp = (short *)&bcbp->b_addr;
			*vp = *sp; vp[1] = sp[1];
			cp = (unsigned char *)v + SIZEOF_ETHEADER;
#else
			cp = (unsigned char *)bcbp->b_addr + SIZEOF_ETHEADER;
#endif TAHOE
E 2
I 2
		if (off == totlen) {
			cp = rxbuf + sizeof (struct ether_header);
E 2
			off = 0;
			totlen = off0;
		}
	}
	return (top);
bad:
	m_freem(top);
	return (0);
}

I 2
enpcopy(from, to, cnt)
D 3
	register char *from, *to;
	register cnt;
E 3
I 3
	register u_char *from, *to;
	register u_int cnt;
E 3
{
	register c;
	register short *f, *t;

	if (((int)from&01) && ((int)to&01)) {
		/* source & dest at odd addresses */
		*to++ = *from++;
		--cnt;
	}
	if (cnt > 1 && (((int)to&01) == 0) && (((int)from&01) == 0)) {
		t = (short *)to;
		f = (short *)from;
		for (c = cnt>>1; c; --c)	/* even address copy */
			*t++ = *f++;
		cnt &= 1;
		if (cnt) {			/* odd len */
D 3
			from = (char *)f;
			to = (char *)t;
E 3
I 3
			from = (u_char *)f;
			to = (u_char *)t;
E 3
			*to = *from;
		}
	}
D 3
	while (cnt-- > 0)	/* one of the address(es) must be odd */
E 3
I 3
	while ((int)cnt-- > 0)	/* one of the address(es) must be odd */
E 3
		*to++ = *from++;
}

E 2
/*
 * Process an ioctl request.
D 2
 *    this can be called via the "socket" route for SIOCSIFADDR or
 *	by the cdev/inode route for SIOCSIFCCFWR/RD
 *
E 2
 */
D 2

E 2
enpioctl(ifp, cmd, data)
D 2
register struct ifnet *ifp;
int cmd;
caddr_t data;
E 2
I 2
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
E 2
{
D 2
	register int	unit = ifp->if_unit;
	register struct vba_device *md;
	int s, error = 0;
	struct sockaddr_in	*sin;
	struct sockaddr		*sa;
	struct enp_softc	*es = &enp_softc[ifp->if_unit];
	ENPDEVICE		*addr;
	struct config_entry	*cf;
	struct ifreq *ifr	= (struct ifreq *)data;
	struct sockaddr_in	*et_addr;
	int code, i;
E 2
I 2
	register struct ifaddr *ifa = (struct ifaddr *)data;
	struct enpdevice *addr;
	int s = splimp(), error = 0;
E 2

D 2

	if (unit >= NENP || (md = enpinfo[unit]) == 0 || md->ui_alive == 0)
		return(ENODEV);

E 2
	switch (cmd) {

	case SIOCSIFADDR:
D 2
		s = splimp();
		sa = (struct sockaddr *)&ifr->ifr_addr;
		if (sa->sa_family == AF_UNSPEC ) {
			if (sa->sa_data[0] & 1){ /*broad or multi-cast*/
				splx( s );
				return( EINVAL );
			}
			bcopy(sa->sa_data,es->es_enaddr,sizeof(es->es_enaddr));
			enpinit( ifp->if_unit);
E 2
I 2
		ifp->if_flags |= IFF_UP;
		switch (ifa->ifa_addr.sa_family) {
#ifdef INET
		case AF_INET:
			enpinit(ifp->if_unit);
			((struct arpcom *)ifp)->ac_ipaddr =
			    IA_SIN(ifa)->sin_addr;
			arpwhohas((struct arpcom *)ifp, &IA_SIN(ifa)->sin_addr);
E 2
			break;
I 2
#endif
#ifdef NS
		case AF_NS: {
			struct ns_addr *ina = &IA_SNS(ifa)->sns_addr;
			struct enp_softc *es = &enp_softc[ifp->if_unit];

			if (!ns_nullhost(*ina)) {
				ifp->if_flags &= ~IFF_RUNNING;
				addr = (struct enpdevice *)
				    enpinfo[ifp->if_unit]->ui_addr;
				enpsetaddr(ifp->if_unit, addr,
				    ina->x_host.c_host);
			} else
D 5
				ina->x_host = *(union ns_host *)es->es_enaddr;
E 5
I 5
				ina->x_host = *(union ns_host *)es->es_addr;
E 5
			enpinit(ifp->if_unit);
			break;
E 2
		}
D 2
		sin = (struct sockaddr_in *)&ifr->ifr_addr;
		if (sin->sin_family != AF_INET){
			splx( s );
			return( EINVAL );
E 2
I 2
#endif
		default:
			enpinit(ifp->if_unit);
			break;
E 2
		}
D 2
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);     /* delete previous route */
		enpsetaddr(ifp, sin);
		enpinit(ifp->if_unit);
		enpgetaddr( ifp->if_unit );
		splx(s);
E 2
		break;

D 2

	case SIOCSETETADDR:	/* Set Ethernet station address */
		s = splimp();
		ifp->if_flags &= (~IFF_RUNNING | IFF_UP);
		et_addr = (struct sockaddr_in *)&ifr->ifr_addr;
		addr = (ENPDEVICE *)enpinfo[ifp->if_unit]->ui_addr;

		/* Set station address and reset controller board */
		{
		u_char	*to = &addr->enp_addr.e_baseaddr.ea_addr[0];
		char	*from = &et_addr->sin_zero[2];
		int	i;

		for (i = 0 ; i < ETHADDR_SIZE; i++) 
			*to++ = (u_char) (~(*from++ & 0xff));
		}
		enpcopy(&addr->enp_addr.e_listsize, &code, sizeof(code)); 
		code |= E_ADDR_SUPP;
		enpcopy(&code, &addr->enp_addr.e_listsize, sizeof(code)); 
		enpreset(ifp->if_unit);		/* Re-initialize */
		enpgetaddr(ifp->if_unit);
		splx(s);
E 2
I 2
	case SIOCSIFFLAGS:
		if ((ifp->if_flags&IFF_UP) == 0 && ifp->if_flags&IFF_RUNNING) {
			enpinit(ifp->if_unit);		/* reset board */
			ifp->if_flags &= ~IFF_RUNNING;
		} else if (ifp->if_flags&IFF_UP &&
		     (ifp->if_flags&IFF_RUNNING) == 0)
			enpinit(ifp->if_unit);
E 2
		break;

D 2
	case SIOCGETETADDR:	/* Get Foreign Hosts' Ethernet addresses */
		arpwhohas(&es->es_ac, (struct in_addr *)ifr->ifr_data);
		break;

E 2
	default:
		error = EINVAL;
	}
D 2
	return(error);
E 2
I 2
	splx(s);
	return (error);
E 2
}

D 2
enpsetaddr(ifp, sin)
register struct ifnet *ifp;
register struct sockaddr_in *sin;
E 2
I 2
enpsetaddr(unit, addr, enaddr)
	int unit;
	struct enpdevice *addr;
	u_char *enaddr;
E 2
{
I 2
D 5
	u_char *cp;
	int i, code;
E 5
E 2

D 2
	ifp->if_addr = *(struct sockaddr *)sin;
	ifp->if_net = in_netof(sin->sin_addr);
	ifp->if_host[0] = in_lnaof(sin->sin_addr);
	sin = (struct sockaddr_in *)&ifp->if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags |= IFF_BROADCAST;
E 2
I 2
D 5
	cp = &addr->enp_addr.e_baseaddr.ea_addr[0];
	for (i = 0; i < 6; i++)
		*cp++ = ~*enaddr++;
D 3
	enpcopy(&addr->enp_addr.e_listsize, &code, sizeof (code)); 
E 3
I 3
	enpcopy((u_char *)&addr->enp_addr.e_listsize, (u_char *)&code,
	    sizeof (code)); 
E 3
	code |= E_ADDR_SUPP;
D 3
	enpcopy(&code, &addr->enp_addr.e_listsize, sizeof (code)); 
E 3
I 3
	enpcopy((u_char *)&code, (u_char *)&addr->enp_addr.e_listsize,
	    sizeof (code)); 
E 5
I 5
	enpcopy(enaddr, addr->enp_addr.e_baseaddr.ea_addr,
	    sizeof (struct ether_addr));
E 5
E 3
	enpinit(unit);
I 5
	enpgetaddr(unit, addr);
E 5
E 2
}

I 5
enpgetaddr(unit, addr)
	int unit;
	struct enpdevice *addr;
{
	struct enp_softc *es = &enp_softc[unit];

	enpcopy(addr->enp_addr.e_baseaddr.ea_addr, es->es_addr,
	    sizeof (struct ether_addr));
	printf("enp%d: hardware address %s\n",
	    unit, ether_sprintf(es->es_addr));
}

E 5
D 2

/*
 * Get the ethernet addr, store it and print it
 * Read the ethernet address off the board, one byte at a time.
 *	put it in enp_softc
 */


enpgetaddr( unit )
int unit;
{
	register struct enp_softc	*es = &enp_softc[unit];
	register ENPDEVICE *addr =(ENPDEVICE *)enpinfo[unit]->ui_addr;
	int i;
	
#ifdef TAHOE
	enpcopy(&addr->enp_addr.e_baseaddr, &es->es_boardaddr, sizeof(es->es_boardaddr));
#else
	es->es_boardaddr = addr->enp_addr.e_baseaddr;
#endif TAHOE
	bcopy(&es->es_boardaddr, es->es_enaddr, ETHADDR_SIZE);
	return( 1 );
}

/*
 * enpram device
 *
 */

enpr_open( dev )
{
	register int	unit = minor(dev);
	register struct vba_device *md;
	register ENPDEVICE	*addr;

	if (unit >= NENP || (md = enpinfo[unit]) == 0 || md->ui_alive == 0 ||
	    (addr = (ENPDEVICE *)md->ui_addr) == (ENPDEVICE *)0)
		return(ENODEV);
	if (addr->enp_state != S_ENPRESET)
		return(EACCES);  /* enp is not in reset state, don't open  */
	if ( !enpismapped[unit] ) {
		ioaccess(ENPmap[unit],ENPmapa[unit],ENPBPTE);
		++enpismapped[unit];
	}
	enpram[unit] = ENP_OPEN;
	return( 0 );
}

enpr_close(dev)
{
	enpram[minor(dev)] = ENP_CLOSE;
	return( 0 );
}

enpr_read( dev,uio )
int dev;
register struct uio *uio;
{
	register ENPDEVICE *addr;
	register struct iovec *iov;
	register r=0;

	if (enpram[minor(dev)] != ENP_OPEN)
		return(EACCES);
	if ( uio->uio_offset > RAM_SIZE )
		return( ENODEV );
	if ( uio->uio_offset + iov->iov_len > RAM_SIZE )
		iov->iov_len = RAM_SIZE - uio->uio_offset;
	addr = (ENPDEVICE *)enpinfo[ minor( dev ) ]->ui_addr;
	iov  = uio->uio_iov;

	if( r = enpcopyout( &addr->enp_ram[ uio->uio_offset ], iov->iov_base,
			 iov->iov_len ) )
		 return( r );

	uio->uio_resid -= iov->iov_len;
	iov->iov_len = 0;

	return( 0 );
}

enpr_write( dev,uio )
int dev;
register struct uio *uio;
{
	register ENPDEVICE *addr;
	register struct iovec *iov;
	register r=0;

	if (enpram[minor(dev)] != ENP_OPEN)
		return(EACCES);
	addr = (ENPDEVICE *)enpinfo[ minor( dev ) ]->ui_addr;
	iov  = uio->uio_iov;

	if ( uio->uio_offset > RAM_SIZE )
		return( ENODEV );
	if ( uio->uio_offset + iov->iov_len > RAM_SIZE )
		iov->iov_len = RAM_SIZE - uio->uio_offset;
	if( r = enpcopyin( iov->iov_base, &addr->enp_ram[ uio->uio_offset ],
			iov->iov_len ) )
		return( r );

	uio->uio_resid -= iov->iov_len;
	iov->iov_len = 0;

	return( 0 );
}

enpr_ioctl( dev,cmd,arg,fflag )
dev_t dev;
caddr_t *arg;
{
	register ENPDEVICE *addr;
	long int	v;
	register short	*vp = (short *)&v, *sp;
	register unit = minor(dev);
	register struct vba_device *md;

	if (unit >= NENP || (md = enpinfo[unit]) == 0 || md->ui_alive == 0 ||
	    (addr = (ENPDEVICE *)md->ui_addr) == (ENPDEVICE *)0)
		return(ENODEV);
	switch( cmd )
	{
		case ENPIOGO:
/* not needed if prom based version */
#ifdef TAHOE
			sp = (short *)&addr->enp_base;
			v = (int)addr;
			*sp = *vp; sp[1] = vp[1];
#else
			addr->enp_base = (int)addr;
#endif TAHOE
			addr->enp_intrvec = intvec[ unit ];
			ENP_GO( addr, ENPSTART );
			DELAY( 200000 );
			enpattach( enpinfo[ unit ] );
			enpinit( unit );
			addr->enp_state = S_ENPRUN;  /* it is running now */
/* end of not needed */

			break;

		case ENPIORESET:
			RESET_ENP( addr );
			addr->enp_state = S_ENPRESET;  /* it is reset now */
			DELAY( 100000 );
			break;
	}
	return( 0 );
}

E 2
/* 
D 2
 * routines to synchronize enp and host 
E 2
I 2
 * Routines to synchronize enp and host.
E 2
 */
I 3
#ifdef notdef
E 3
D 2

E 2
static
D 2
ringinit( rp,size )
register RING *rp;
E 2
I 2
ringinit(rp, size)
	register RING *rp;
E 2
{
D 2
	register int	i;
E 2
I 2
D 3
	register int i;
E 2
	register short *sp; 
E 3

	rp->r_rdidx = rp->r_wrtidx = 0;
	rp->r_size = size;
}

static
D 2
ringempty( rp )
register RING *rp;
E 2
I 2
D 3
ringempty(rp)
E 3
I 3
ringfull(rp)
E 3
	register RING *rp;
E 2
{
I 3
	register short idx;
E 3
D 2
	return( rp->r_rdidx == rp->r_wrtidx );
E 2
I 2

D 3
	return (rp->r_rdidx == rp->r_wrtidx);
E 3
I 3
	idx = (rp->r_wrtidx + 1) & (rp->r_size-1);
	return (idx == rp->r_rdidx);
E 3
E 2
}

static
D 2
ringfull( rp )
register RING *rp;
E 2
I 2
D 3
ringfull(rp)
E 3
I 3
fir(rp)
E 3
	register RING *rp;
E 2
{
D 3
	register short idx;
E 3

D 3
	idx = (rp->r_wrtidx + 1) & (rp->r_size-1);
D 2
	return( idx == rp->r_rdidx );
E 2
I 2
	return (idx == rp->r_rdidx);
E 3
I 3
	return (rp->r_rdidx != rp->r_wrtidx ? rp->r_slot[rp->r_rdidx] : 0);
E 3
E 2
}
I 3
#endif
E 3

static
I 3
ringempty(rp)
	register RING *rp;
{

	return (rp->r_rdidx == rp->r_wrtidx);
}

static
E 3
D 2
ringput( rp,v )
register RING *rp;
E 2
I 2
ringput(rp, v)
	register RING *rp;
I 3
	BCB *v;
E 3
E 2
{
	register int idx;
D 2
	register short *vp = (short *)&v,
		       *sp;
E 2

	idx = (rp->r_wrtidx + 1) & (rp->r_size-1);
D 2
	if( idx != rp->r_rdidx )
	{
#ifdef TAHOE
		sp = (short *)&rp->r_slot[ rp->r_wrtidx ];
		*sp = *vp; sp[1] = vp[1];
#else
		rp->r_slot[ rp->r_wrtidx ] = v;
#endif TAHOE
E 2
I 2
	if (idx != rp->r_rdidx) {
D 3
		rp->r_slot[rp->r_wrtidx] = v;
E 3
I 3
D 5
		rp->r_slot[rp->r_wrtidx] = (int)v;
E 5
I 5
		ENPSETLONG(&rp->r_slot[rp->r_wrtidx], v);
E 5
E 3
E 2
		rp->r_wrtidx = idx;
D 2
		if( (idx -= rp->r_rdidx) < 0 )
E 2
I 2
		if ((idx -= rp->r_rdidx) < 0)
E 2
			idx += rp->r_size;
D 2
		return( idx );			/* num ring entries */
E 2
I 2
		return (idx);			/* num ring entries */
E 2
	}
D 2
	return( 0 );
E 2
I 2
	return (0);
E 2
}

static
D 2
ringget( rp )
register RING *rp;
E 2
I 2
ringget(rp)
	register RING *rp;
E 2
{
	register int i = 0;
D 2
	long int v;
	register short *vp = (short *)&v,
		       *sp;
E 2

D 2
	if( rp->r_rdidx != rp->r_wrtidx )
	{
#ifdef TAHOE
		sp = (short *)&rp->r_slot[ rp->r_rdidx ];
		*vp = *sp; vp[1] = sp[1];
		i = v;
#else
		i = rp->r_slot[ rp->r_rdidx ];
#endif TAHOE
E 2
I 2
	if (rp->r_rdidx != rp->r_wrtidx) {
D 5
		i = rp->r_slot[rp->r_rdidx];
E 5
I 5
		i = ENPGETLONG(&rp->r_slot[rp->r_rdidx]);
E 5
E 2
		rp->r_rdidx = (++rp->r_rdidx) & (rp->r_size-1);
	}
D 2
	return( i );
E 2
I 2
	return (i);
E 2
}

D 2
#ifdef notdef
struct mbuf *
m_tofree( rp )
register RING *rp;
E 2
I 2
D 3
static
fir(rp)
	register RING *rp;
E 2
{
D 2
	long int v = 0;
	register short *vp = (short *)&v,
		       *sp;
E 2

D 2
	if( rp->r_rdidx != rp->r_wrtidx )
	{
#ifdef TAHOE
		sp = (short *)&rp->r_slot[ rp->r_rdidx ];
		*vp = *sp; vp[1] = sp[1];
		/* *sp = 0xffff; sp[1] = 0xffff; */
#else
		v = rp->r_slot[ rp->r_rdidx ];
#endif TAHOE
	  	rp->r_rdidx = (++rp->r_rdidx) & (rp->r_size-1);
	}
	return( (struct mbuf *)v );
E 2
I 2
	return (rp->r_rdidx != rp->r_wrtidx ? rp->r_slot[rp->r_rdidx] : 0);
E 2
}
D 2
#endif
static
fir( rp )
register RING *rp;
E 2
I 2

E 3
/*
 * ENP Ram device.
 */
enpr_open(dev)
	dev_t dev;
E 2
{
D 2
	long int v;
	register short *vp = (short *)&v,
		       *sp;
E 2
I 2
	register int unit = ENPUNIT(dev);
	struct vba_device *ui;
	struct enpdevice *addr;
E 2

D 2
	if( rp->r_rdidx != rp->r_wrtidx )
#ifdef TAHOE
	{
		sp = (short *)&rp->r_slot[ rp->r_rdidx ];
		*vp = *sp; vp[1] = sp[1];
		return( v );
	}
#else
		return( rp->r_slot[ rp->r_rdidx ] );
#endif TAHOE
	else   
		return( 0 );
E 2
I 2
	if (unit >= NENP || (ui = enpinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    (addr = (struct enpdevice *)ui->ui_addr) == 0)
		return (ENODEV);
	if (addr->enp_state != S_ENPRESET)
		return (EACCES);  /* enp is not in reset state, don't open  */
	return (0);
E 2
}

I 3
/*ARGSUSED*/
E 3
D 2

static
prtbytes( addr )
register char *addr;
E 2
I 2
enpr_close(dev)
	dev_t dev;
E 2
{
D 2
	register int i;
E 2

D 2
	for( i = 0; i < 12; i++ )
	{
		printf("%X ",*addr&0377);
		addr++;
	}
	printf("\n");
E 2
I 2
	return (0);
E 2
}

D 2
static
enpcopy(from, to, cnt)
register char *from, *to;
register cnt;
E 2
I 2
enpr_read(dev, uio)
	dev_t dev;
	register struct uio *uio;
E 2
{
D 2
	register c;
	register short *f, *t;
E 2
I 2
	register struct iovec *iov;
	struct enpdevice *addr;
D 5
	int error;
E 5
E 2

D 2
	if (((int)from & 01) && ((int)to & 01)) {
					/* source & dest at odd addresses */
		*to++ = *from++;
		--cnt;
	}
	if (cnt > 1 && (((int)to & 01)==0) && (((int)from & 01)==0)) {
		t = (short *) to;
		f = (short *) from;
		for( c = cnt>>1; c; --c)	/* even address copy */
			*t++ = *f++;
		cnt &= 1;
		if ( cnt ) {			/* odd len */
			from = (char *) f;
			to   = (char *) t;
			*to = *from;
		}
	}
	while (cnt-- > 0)	/* one of the address(es) must be odd */
		*to++ = *from++;

E 2
I 2
	if (uio->uio_offset > RAM_SIZE)
		return (ENODEV);
I 3
	iov = uio->uio_iov;
E 3
	if (uio->uio_offset + iov->iov_len > RAM_SIZE)
		iov->iov_len = RAM_SIZE - uio->uio_offset;
	addr = (struct enpdevice *)enpinfo[ENPUNIT(dev)]->ui_addr;
D 3
	iov = uio->uio_iov;
	error = useracc(iov->iov_base, iov->iov_len, 0);
E 3
I 3
D 5
	error = useracc(iov->iov_base, (unsigned)iov->iov_len, 0);
E 3
	if (error)
		return (error);
E 5
I 5
	if (useracc(iov->iov_base, (unsigned)iov->iov_len, 0) == 0)
		return (EFAULT);
E 5
D 3
	enpcopy(&addr->enp_ram[uio->uio_offset], iov->iov_base, iov->iov_len);
E 3
I 3
	enpcopy((u_char *)&addr->enp_ram[uio->uio_offset],
	    (u_char *)iov->iov_base, (u_int)iov->iov_len);
E 3
	uio->uio_resid -= iov->iov_len;
	iov->iov_len = 0;
	return (0);
E 2
}

D 2
static
enpcopyin(userv, kernv, cnt)
E 2
I 2
enpr_write(dev, uio)
	dev_t dev;
	register struct uio *uio;
E 2
{
I 2
	register struct enpdevice *addr;
	register struct iovec *iov;
D 5
	register error;
E 5
E 2

D 2
	if (useracc(userv, cnt, 1)) {
		enpcopy( userv, kernv, cnt );
		return( 0 );
	}
	else	return( EFAULT );
E 2
I 2
	addr = (struct enpdevice *)enpinfo[ENPUNIT(dev)]->ui_addr;
	iov = uio->uio_iov;
	if (uio->uio_offset > RAM_SIZE)
		return (ENODEV);
	if (uio->uio_offset + iov->iov_len > RAM_SIZE)
		iov->iov_len = RAM_SIZE - uio->uio_offset;
D 3
	error =  useracc(iov->iov_base, iov->iov_len, 1);
E 3
I 3
D 5
	error =  useracc(iov->iov_base, (unsigned)iov->iov_len, 1);
E 3
	if (error)
		return (error);
E 5
I 5
	if (useracc(iov->iov_base, (unsigned)iov->iov_len, 1) == 0)
		return (EFAULT);
E 5
D 3
	enpcopy(iov->iov_base, &addr->enp_ram[uio->uio_offset], iov->iov_len);
E 3
I 3
	enpcopy((u_char *)iov->iov_base,
	    (u_char *)&addr->enp_ram[uio->uio_offset], (u_int)iov->iov_len);
E 3
	uio->uio_resid -= iov->iov_len;
	iov->iov_len = 0;
	return (0);
E 2
}

I 3
/*ARGSUSED*/
E 3
D 2

static
enpcopyout(kernv, userv, cnt)
E 2
I 2
enpr_ioctl(dev, cmd, data)
	dev_t dev;
	caddr_t data;
E 2
{
I 2
D 5
	register struct enpdevice *addr;
E 5
	register unit = ENPUNIT(dev);
I 5
	struct enpdevice *addr;
E 5
D 3
	register struct vba_device *ui;
E 3
E 2

D 2
	if (useracc(userv, cnt, 0)) {
		enpcopy( kernv, userv, cnt );
		return( 0 );
E 2
I 2
	addr = (struct enpdevice *)enpinfo[unit]->ui_addr;
	switch(cmd) {

	case ENPIOGO:
D 5
/* not needed if prom based version */
		addr->enp_base = (int)addr;
E 5
I 5
		ENPSETLONG(&addr->enp_base, addr);
E 5
		addr->enp_intrvec = enp_softc[unit].es_ivec;
		ENP_GO(addr, ENPSTART);
		DELAY(200000);
		enpinit(unit);
D 5
		addr->enp_state = S_ENPRUN;  /* it is running now */
/* end of not needed */
E 5
I 5
		/*
		 * Fetch Ethernet address after link level
		 * is booted (firmware copies manufacturer's
		 * address from on-board ROM).
		 */
		enpgetaddr(unit, addr);
		addr->enp_state = S_ENPRUN;
E 5
		break;

	case ENPIORESET:
		RESET_ENP(addr);
D 5
		addr->enp_state = S_ENPRESET;  /* it is reset now */
E 5
I 5
		addr->enp_state = S_ENPRESET;
E 5
		DELAY(100000);
		break;
I 5
	default:
		return (EINVAL);
E 5
E 2
	}
D 2
	else	return( EFAULT );
E 2
I 2
	return (0);
E 2
}
#endif
E 1
