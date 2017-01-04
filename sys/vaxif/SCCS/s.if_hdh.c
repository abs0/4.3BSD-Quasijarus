h01064
s 00002/00002/00668
d D 7.5 88/05/26 09:39:43 karels 12 11
c update impstart interface
e
s 00005/00003/00665
d D 7.4 88/05/14 11:10:35 karels 11 10
c impattach now takes name/unit instead of ubadevice; clean up output
c side when resetting
e
s 00032/00044/00636
d D 7.3 88/02/08 10:26:14 karels 10 9
c new IMP interface
e
s 00005/00005/00675
d D 7.2 87/08/07 10:38:01 karels 9 8
c increasing size of receive buuffer supposedly masks a bug
e
s 00000/00000/00680
d D 7.1 86/06/05 17:07:18 mckusick 8 7
c 4.3BSD release version
e
s 00001/00003/00679
d D 6.7 86/06/02 14:44:54 karels 7 6
c lint
e
s 00002/00001/00680
d D 6.6 86/02/23 23:28:52 karels 6 5
c lint
e
s 00003/00003/00678
d D 6.5 86/02/21 11:40:08 karels 5 4
c missed one
e
s 00002/00011/00679
d D 6.4 86/02/20 16:54:17 karels 4 3
c lint
e
s 00000/00000/00690
d D 6.3 85/12/19 15:45:43 karels 3 2
c rm bbnnet
e
s 00018/00015/00672
d D 6.2 85/11/11 11:09:16 karels 2 1
c now compiles under 4.3
e
s 00687/00000/00000
d D 6.1 85/09/17 23:10:33 karels 1 0
c from ACC
e
u
U
t
T
I 2
/*	%W% (Berkeley) %G% */
E 2
I 1


D 2

E 2
/************************************************************************\

     ________________________________________________________
    /                                                        \
   |          AAA          CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |
   |         AAAAA        CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |
   |        AAAAAAA       CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |
   |       AAAA AAAA      CCCC              CCCC              |
   |      AAAA   AAAA     CCCC              CCCC              |
   |     AAAA     AAAA    CCCC              CCCC              |
   |    AAAA       AAAA   CCCC              CCCC              |
   |   AAAA  AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |
   |  AAAA    AAAAAAAAAAA CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |
   | AAAA      AAAAAAAAA   CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |
    \________________________________________________________/

	Copyright (c) 1984 by Advanced Computer Communications
	720 Santa Barbara Street, Santa Barbara, California  93101
	(805) 963-9431

	This software may be duplicated and used on systems
	which are licensed to run U.C. Berkeley versions of
	the UNIX operating system.  Any duplication of any
	part of this software must include a copy of ACC's
	copyright notice.


File:
		if_hdh.c

Author:
		Art Berggreen

Project:
		4.2BSD HDH

Function:
		Device specific driver for IF-11/HDH under 4.2BSD
    		networking code.

Revision History:
I 10
		Converted to 4.3, updated, UCB.
E 10
		31-Aug-1984: V1.0 - First Implementation. A.B.
		 6-Nov-1984: V1.1 - Supress extra "LINE DOWN" msgs. A.B.
		13-Jan-1984: V1.2 - Add conditionals for TWG. A.B.

\************************************************************************/




/* $Header$ */

#include "hdh.h"
#ifdef NHDH > 0

/*
 *
 * ACC IF-11/HDH interface
 *
 */

D 10
#include "../machine/pte.h"

E 10
D 2
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/vmmac.h"
E 2
I 2
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
E 2

I 10
#include "../machine/pte.h"

E 10
#include "../net/if.h"
#include "../netimp/if_imp.h"

#include "../vax/cpu.h"
#include "../vax/mtpr.h"
D 2
#include "../vaxif/if_hdhreg.h"
#include "../vaxif/if_uba.h"
E 2
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"

I 2
#include "if_hdhreg.h"
#include "if_uba.h"

E 2
D 6
int     hdhprobe(), hdhattach(), hdhrint(), hdhxint();
E 6
I 6
int     hdhprobe(), hdhattach(), hdhintr();
E 6
struct  uba_device *hdhinfo[NHDH];
u_short hdhstd[] = { 0 };
struct  uba_driver hdhdriver =
	{ hdhprobe, 0, hdhattach, 0, hdhstd, "hdh", hdhinfo };

#define	HDHUNIT(x)	minor(x)

D 10
int	hdhinit(), hdhstart(), hdhreset();
E 10
I 10
int	hdhinit(), hdhoutput(), hdhreset();
E 10

/*
 * "Lower half" of IMP interface driver.
 *
 * Each IMP interface is handled by a common module which handles
 * the IMP-host protocol and a hardware driver which manages the
 * hardware specific details of talking with the IMP.
 *
 * The hardware portion of the IMP driver handles DMA and related
 * management of UNIBUS resources.  The IMP protocol module interprets
 * contents of these messages and "controls" the actions of the
 * hardware module during IMP resets, but not, for instance, during
 * UNIBUS resets.
 *
 * The two modules are coupled at "attach time", and ever after,
 * through the imp interface structure.  Higher level protocols,
 * e.g. IP, interact with the IMP driver, rather than the HDH.
 */

#define NHDHCH	2		/* no. of FDX channels for HDH */
#define SUPR	0		/* supervisor channel */
#define	DATA	1		/* data channel */
#define HDHSUPR	0		/* supervisor read */
#define HDHSUPW	1		/* supervisor write */
#define HDHDATR	2		/* data read */
#define HDHDATW	3		/* data write */

#define HDH_UP		2	/* HDH protocol is up */
#define HDH_STARTED	1	/* HDH has been initialized */

#define HCBUSY	1		/* HDH HDX channel busy flag */

/*
/* The IF-11/HDH has four independent dath flow channels between the
/* front-end and the host.  Two are used for reading and writing
/* control messages and two are used for data flow.  Each IF-11/HDH
/* has a device dependent data structure (hdh_softc) which contains
/* an array of four channel dependent structures (hdh_chan) to maintain
/* the context of each channel.  Channel structures can be linked into
/* a queue of I/O requests pending for the hardware interface.
/* UNIBUS mapping resources are allocated for each channel pair.
*/

struct	hdh_chan {		/* HDH HDX channel structure */
	struct hdh_chan	*hc_next;	/* link for Start I/O queuing */
	char		hc_chan;	/* HDX chan number */
	char		hc_adx;		/* extended UNIBUS address bits */
	short		hc_addr;	/* lower UNIBUS address bits */
	short		hc_cnt;		/* byte count */
	char		hc_func;	/* UMC I/O function */
	char		hc_sbfc;	/* UMC I/O subfunction */
	short		hc_flags;	/* status flags */
};

struct	hdh_sioq {		/* Start I/O queue head structure */
	struct hdh_chan *sioq_head;	/* pointer to queue head */
	struct hdh_chan *sioq_tail;	/* pointer to queue tail */
};

struct	hdh_softc {		/* HDH device dependent structure */
D 10
	struct ifnet	*hdh_if;	/* pointer to IMP's ifnet struct */
	struct impcb	*hdh_ic;	/* data structure shared with IMP */
E 10
I 10
	struct imp_softc *hdh_imp;	/* pointer to IMP's imp_softc struct */
E 10
	struct ifuba	hdh_ifuba[NHDHCH]; /* UNIBUS resources */
	struct hdh_chan hdh_chan[2*NHDHCH]; /* HDX HDH channels */
	struct hdh_sioq hdh_sioq;	/* start i/o queue */
	short		hdh_flags;	/* various status conditions */
} hdh_softc[NHDH];


/*
 * Normally, code goes here to cause the device to interrupt to determine its
 * interrupt vector.  However, since the UMC must be told its vector in order
 * to interrupt, we allocate and return an unused vector and initialize the
 * UMC.
 */
hdhprobe(reg)
caddr_t reg;
{
	register int br, cvec;
	struct hdhregs *addr = (struct hdhregs *)reg;
#ifdef lint
	br = 0; cvec = br; br = cvec;
I 6
	hdhintr(0);
E 6
#endif

	br = 0x15;			/* priority 21 (5 on UNIBUS) */

#ifdef HDHDEBUG
	cvec = 0270;			/* use constant for now ... */
#else

#ifdef VAXVMS				/* if VMS */
	cvec = 0270;			/*   we can't allocate vectors */
#else
	cvec = (uba_hd[numuba].uh_lastiv -= 4);  /* available vector */
#endif VAXVMS

#endif HDHDEBUG

	addr->ioini = (char) 0;		/* init UMC regs */
	addr->staack = (char) 0;	/*   pass vector */
	addr->ionmi = (char) 0;		/*     and kick UMC */
	addr->iochn = (char) (cvec >> 2);
	addr->csr = (short) HDH_RST;
	addr->csr = (short) (HDH_IEN|HDH_DMA|HDH_WRT); /* set enables */
	DELAY(5000);			/* give the UMC some time */
	return(1);
}

/*
 * Call the IMP module to allow it to set up its internal
 * state, then tie the two modules together by setting up
 * the back pointers to common data structures.
 */
hdhattach(ui)
D 11
	struct uba_device *ui;
E 11
I 11
	register struct uba_device *ui;
E 11
{
	register struct hdh_softc *sc = &hdh_softc[ui->ui_unit];
	register struct impcb *ip;
D 10
	struct ifimpcb {
		struct	ifnet ifimp_if;
		struct	impcb ifimp_impcb;
	} *ifimp;
E 10

D 10
	if ((ifimp = (struct ifimpcb *)impattach(ui, hdhreset)) == 0)
E 10
I 10
D 11
	if ((sc->hdh_imp = impattach(ui, hdhreset)) == 0)
E 10
D 2
		panic("hdhattach");
E 2
I 2
		return;;
E 11
I 11
	if ((sc->hdh_imp = impattach(ui->ui_driver->ud_dname, ui->ui_unit,
	    hdhreset)) == 0)
		return;
E 11
E 2
D 10
	sc->hdh_if = &ifimp->ifimp_if;
	ip = &ifimp->ifimp_impcb;
	sc->hdh_ic = ip;
E 10
I 10
	ip = &sc->hdh_imp->imp_cb;
E 10
	ip->ic_init = hdhinit;
D 10
	ip->ic_start = hdhstart;
E 10
I 10
	ip->ic_output = hdhoutput;
E 10
	sc->hdh_ifuba[ui->ui_unit].ifu_flags = UBA_CANTWAIT;
}

/*
 * Reset interface after UNIBUS reset.
 */
hdhreset(unit, uban)
int unit, uban;
{
	register struct uba_device *ui = hdhinfo[unit];
	register struct hdh_softc *sc = &hdh_softc[unit];

#ifdef HDHDEBUG
	printf("HDH RESET\n");
#endif HDHDEBUG

	if ((unit >= NHDH) || (ui == 0) || (ui->ui_alive == 0)
	    || (ui->ui_ubanum != uban))
		return;
	printf(" hdh%d", unit);
I 2
D 10
	sc->hdh_if->if_flags &= ~IFF_RUNNING;
E 10
I 10
	sc->hdh_imp->imp_if.if_flags &= ~IFF_RUNNING;
I 11
	sc->hdh_imp->imp_cb.ic_oactive = 0;
E 11
E 10
	sc->hdh_flags = 0;
E 2
D 10
	(*sc->hdh_if->if_init)(unit);
E 10
I 10
	(*sc->hdh_imp->imp_if.if_init)(sc->hdh_imp->imp_if.if_unit);
E 10
}

/*
 * Initialize the imp interface.
 */

static char init_blk[] = 
    {
	HDHINIT,		/* SYSINIT opcode			*/
	HDHRQUP & 0xff,		/* control code (LSB)			*/
	(HDHRQUP>>8) & 0xff,	/* control code (MSB)			*/
	10,			/* command extension len		*/
	0,			/* loopback mode (off)			*/
	3,			/* our address (3=DTE)			*/
	1,			/* their address (1=DCE)		*/
	3,			/* frame ack t1 timeout			*/
	3,			/* poll ack timeout			*/
	30,			/* adm wait timeout			*/
	3,			/* rej wait timeout			*/
	10,			/* max retries				*/
	3,			/* watchdog timeout			*/
	0xaa			/* baud rate (0xaa=38.4KB)		*/
				/*   (output on RS-232 pin 24,		*/
				/*    send/receive timing is always	*/
				/*    taken from pins 15/17)		*/
    };

hdhinit(unit)
int unit;
{	
	register struct hdh_softc *sc;
D 4
	register struct hdhregs *addr;
E 4
	register struct uba_device *ui;
D 4
	register struct umc_chan *up;
	register struct mbuf *m, *n;
	int i, s, ubano;
E 4
I 4
	int i;
E 4

#ifdef HDHDEBUG
	printf("HDH INIT\n");
#endif HDHDEBUG

	if (unit >= NHDH || (ui = hdhinfo[unit]) == NULL
	    || ui->ui_alive == 0) {
		printf("hdh%d: not alive\n", unit);
		return(0);
	}
D 4
	addr = (struct hdhregs *)ui->ui_addr;
E 4
	sc = &hdh_softc[unit];

D 2
	if (sc->hdh_flags & HDH_STARTED) {
		printf("hdh%d: re-init\n", unit);
E 2
I 2
	if (sc->hdh_flags & HDH_STARTED)
E 2
		return(1);
D 2
	}
E 2

	/*
	 * Alloc uba resources
	 */
D 10
	for(i=0;i<NHDHCH;i++) {
E 10
I 10
	if ((sc->hdh_imp->imp_if.if_flags & IFF_RUNNING) == 0)
	    for(i=0;i<NHDHCH;i++) {
E 10
		if (if_ubainit(&sc->hdh_ifuba[i], ui->ui_ubanum, 0,
D 9
		    (int)btoc(IMPMTU)) == 0) {
E 9
I 9
D 10
		    (int)btoc(IMPMTU + 2)) == 0) {
E 10
I 10
		    (int)btoc(IMP_RCVBUF)) == 0) {
E 10
E 9
			printf("hdh%d: cannot get chan %d uba resources\n",
				unit, i);
			ui->ui_alive = 0;
			return(0);
		}
	}

I 2
D 10
	sc->hdh_if->if_flags |= IFF_RUNNING;
E 10
I 10
	sc->hdh_imp->imp_if.if_flags |= IFF_RUNNING;
E 10
E 2
	sc->hdh_flags = HDH_STARTED;

	/*
	 * hang a supervisor read (for line status)
	 */
D 9
	hdh_iorq(unit, HDHSUPR, IMPMTU, HDHRDB);
E 9
I 9
D 10
	hdh_iorq(unit, HDHSUPR, IMPMTU + 2, HDHRDB);
E 10
I 10
	hdh_iorq(unit, HDHSUPR, IMP_RCVBUF, HDHRDB);
E 10
E 9

	/*
	 * hang a data read
	 */
D 9
	hdh_iorq(unit, HDHDATR, IMPMTU, HDHRDB+HDHSTR);
E 9
I 9
D 10
	hdh_iorq(unit, HDHDATR, IMPMTU + 2, HDHRDB+HDHSTR);
E 10
I 10
	hdh_iorq(unit, HDHDATR, IMP_RCVBUF, HDHRDB+HDHSTR);
E 10
E 9

	/*
	 * bring up line to IMP
	 */

	snd_supr(unit, init_blk, sizeof(init_blk));

	return(1);
}

/*
 * Start an output operation on an mbuf.
 */
D 10
hdhstart(dev)
dev_t dev;
E 10
I 10
hdhoutput(unit, m)
	int unit;
	struct mbuf *m;
E 10
{
D 10
	int unit = HDHUNIT(dev);
E 10
	register struct hdh_softc *sc = &hdh_softc[unit];
D 10
	register struct mbuf *m;
E 10
        int len;

	/*
	 * If output isn't active, attempt to
	 * start sending a new packet.
	 */

D 10
	if (sc->hdh_ic->ic_oactive) {
E 10
I 10
	if (sc->hdh_imp->imp_cb.ic_oactive) {
E 10
		printf("hdh%d: start on active unit\n", unit);
		return;
	}

	if ((sc->hdh_flags & HDH_UP) == 0) {
D 10
		sc->hdh_ic->ic_oactive = 0;	/* Link not up, can't xmit */
E 10
I 10
		/* Link not up, can't xmit */
E 10
		return;
	}

D 10
	IF_DEQUEUE(&sc->hdh_if->if_snd, m);
	if (m == 0) {
		sc->hdh_ic->ic_oactive = 0;
		return;
	}

E 10
	len = if_wubaput(&sc->hdh_ifuba[DATA], m);	/* copy data to mapped mem */
D 10
	sc->hdh_ic->ic_oactive = 1;
E 10
I 10
	sc->hdh_imp->imp_cb.ic_oactive = 1;
E 10

	hdh_iorq(unit, HDHDATW, len, HDHWRT+HDHEOS);
}

/*
 * Start i/o operation on a UMC logical channel
 */
hdh_iorq(unit, lcn, len, func)
int unit, lcn, len, func;
{
	register struct hdh_softc *sc = &hdh_softc[unit];
	register struct hdh_chan *hc = &sc->hdh_chan[lcn];
	register int info, s;

	/*
	 * If channel is busy (shouldn't be), drop.
	 */
	if  (hc->hc_flags & HCBUSY) {
		printf("hdh%d: channel busy lcn=%d\n", unit, lcn);
		return;
	}

 	/* get appropriate UNIBUS mapping info */

	if (lcn & 1)		/* read or write? */
		info = sc->hdh_ifuba[lcn>>1].ifu_w.ifrw_info;
	else
		info = sc->hdh_ifuba[lcn>>1].ifu_r.ifrw_info;

	/* set channel info */

	hc->hc_flags |= HCBUSY;
	hc->hc_chan = lcn;
	hc->hc_adx = (char)((info & 0x30000) >> 12);
	hc->hc_addr = (unsigned short)(info & 0xffff);
	hc->hc_cnt = len;
	hc->hc_func = (char)func;
	hc->hc_sbfc = 0;

	s = splimp();
	/*
	 * If UMC comm regs busy, queue start i/o for later.
	 */
	if (sc->hdh_sioq.sioq_head) {
		(sc->hdh_sioq.sioq_tail)->hc_next = hc;
		sc->hdh_sioq.sioq_tail = hc;
		hc->hc_next = 0;
		splx(s);
		return;
	}

	/* start i/o on channel now */

	sc->hdh_sioq.sioq_head = hc;
	sc->hdh_sioq.sioq_tail = hc;
	hc->hc_next = 0;
	start_chn(unit);
	splx(s);
}

start_chn(unit)
int unit;
{
	register struct hdh_softc *sc = &hdh_softc[unit];
	register struct hdh_chan *hc = sc->hdh_sioq.sioq_head;
	register struct hdhregs *addr = (struct hdhregs *)hdhinfo[unit]->ui_addr;

	/*
	 * Set up comm regs.
	 */
	addr->iochn = hc->hc_chan;
	addr->ioadx = hc->hc_adx;
	addr->ioadl = hc->hc_addr;
	addr->iocnt = hc->hc_cnt;
	addr->iofcn = hc->hc_func;
	addr->iosbf = hc->hc_sbfc;
	addr->ioini = 1;

	/* signal UMC if necessary */

	if (!(addr->ionmi)) {
		addr->ionmi = 1;
		addr->csr = HDH_DMA|HDH_WRT|HDH_IEN|HDH_NMI;
	}
}

/*
 * IF-11/HDH interrupt handler
 */
hdhintr(unit)
int unit;
{
	register struct hdh_softc *sc = &hdh_softc[unit];
	register struct hdh_chan *hc;
	register struct hdhregs *addr = (struct hdhregs *)hdhinfo[unit]->ui_addr;
D 4
	register struct mbuf *m;
	int lcn, type, cc, cnt, s;
E 4
I 4
	int lcn, type, cc, cnt;
E 4

	/*
	 * Check for hardware errors.
	 */
	if (addr->csr & HDH_UER) {
		printf("hdh%d: hard error csr=%b\n", unit, addr->csr, HDH_BITS);
		addr->csr = 0;		/* disable i/f */
		return;
	}
	/*
	 * Get logical channel info.
	 */
	if ((lcn = addr->stachn) >= (NHDHCH*2)) {
		printf("hdh%d: unknown channel lcn=%d\n", unit, lcn);
		return;
	}

	hc = &sc->hdh_chan[lcn];

	type = addr->statyp;
	cc = addr->stacc;
	cnt = hc->hc_cnt - addr->stacnt;

	/* Figure out what kind of interrupt it was */

	switch(type) {

	case HDHSACK:		/* start i/o accepted */
		if (hc != sc->hdh_sioq.sioq_head) {
			printf("hdh%d: STARTIO error lcn=%d hc=%x sq=%x\n",
				unit, lcn, hc, sc->hdh_sioq.sioq_head);
			return;
		}

		/* try to start any queued i/o request */

		if (sc->hdh_sioq.sioq_head = sc->hdh_sioq.sioq_head->hc_next) {
			start_chn(unit);
		}
		break;

	case HDHDONE:		/* i/o completion */
		switch (cc) {

		case HDHIOCABT:
			printf("hdh%d: I/O abort ", unit);
			goto daterr;

		case HDHIOCERR:
			printf("hdh%d: program error ", unit);
			goto daterr;

		case HDHIOCOVR:
			printf("hdh%d: overrun error ", unit);
			goto daterr;

		case HDHIOCUBE:
			printf("hdh%d: NXM timeout or UB parity error ", unit);
		
		daterr:
			printf("lcn=%d func=%x\n", lcn, hc->hc_func);
			if (hc->hc_func & HDHRDB)
D 10
				sc->hdh_if->if_ierrors++;
E 10
I 10
				sc->hdh_imp->imp_if.if_ierrors++;
E 10
			else
D 10
				sc->hdh_if->if_oerrors++;
E 10
I 10
				sc->hdh_imp->imp_if.if_oerrors++;
E 10
		}

		hc->hc_flags &= ~HCBUSY;

		/* was it supervisor or data traffic? */

		if (lcn > HDHSUPW)
			hdh_data(unit, lcn, cc, cnt);
		else
D 5
			hdh_supr(unit, lcn, cc, cnt);
E 5
I 5
			hdh_supr(unit, lcn, cc);
E 5

	}

	/*
	 * Ack the interrupt
	 */
	addr->staack = 1;
	if (!(addr->ionmi)) {
		addr->ionmi = 1;
		addr->csr = HDH_DMA|HDH_WRT|HDH_IEN|HDH_NMI;
	}	
}

/*
 * data channel interrupt completion handler
 */
hdh_data(unit, lcn, cc, rcnt)
int unit, lcn, cc, rcnt;
{
	register struct hdh_softc *sc = &hdh_softc[unit];
	register struct hdh_chan *hc = &sc->hdh_chan[lcn];
	register struct mbuf *m;


	/* was it read or write? */

	if (hc->hc_func & HDHRDB) {
		if (cc == HDHIOCOK) {
			/*
			 * Queue good packet for input 
			 */
D 10
			sc->hdh_if->if_ipackets++;
E 10
I 10
			sc->hdh_imp->imp_if.if_ipackets++;
E 10
D 2
			m = if_rubaget(&sc->hdh_ifuba[lcn>>1], rcnt, 0);
E 2
I 2
			m = if_rubaget(&sc->hdh_ifuba[lcn>>1], rcnt, 0,
D 10
				sc->hdh_if);
E 10
I 10
				&sc->hdh_imp->imp_if);
E 10
E 2
			impinput(unit, m);
		}

		/* hang a new data read */

D 9
		hdh_iorq(unit, lcn, IMPMTU, HDHRDB+HDHSTR);
E 9
I 9
D 10
		hdh_iorq(unit, lcn, IMPMTU + 2, HDHRDB+HDHSTR);
E 10
I 10
		hdh_iorq(unit, lcn, IMP_RCVBUF, HDHRDB+HDHSTR);
E 10
E 9

	} else {
		/*
		 * fire up next output
		 */
D 10
		sc->hdh_if->if_opackets++;
		sc->hdh_ic->ic_oactive = 0;
		hdhstart(unit);		
E 10
I 10
		sc->hdh_imp->imp_if.if_opackets++;
		sc->hdh_imp->imp_cb.ic_oactive = 0;
D 12
		impstart(sc->hdh_imp->imp_if.if_unit);
E 12
I 12
		impstart(sc->hdh_imp);
E 12
E 10
	}
}

/*
 * supervisor channel interrupt completion handler
 */
D 5
hdh_supr(unit, lcn, cc, rcnt)
int unit, lcn, cc, rcnt;
E 5
I 5
hdh_supr(unit, lcn, cc)
int unit, lcn, cc;
E 5
{
	register struct hdh_softc *sc = &hdh_softc[unit];
	register struct hdh_chan *hc = &sc->hdh_chan[lcn];
D 4
	register struct uba_device *ui;
E 4
	short *p;
D 4
	int i;
E 4
	

	/* was it read or write? */

	if (hc->hc_func & HDHRDB) {	
		if (cc == HDHIOCOK) {
			p = (short *)(sc->hdh_ifuba[lcn>>1].ifu_r.ifrw_addr);

			/* figure out what kind of supervisor message */

			switch (*p) {

			case HDHIACK:
			case HDHLNACK:
				break;
	
			case HDHLNUP:
				printf("hdh%d: LINE UP\n", unit);
				sc->hdh_flags |= HDH_UP;
D 10
				hdhstart(unit);
E 10
I 10
D 12
				impstart(sc->hdh_imp->imp_if.if_unit);
E 12
I 12
				impstart(sc->hdh_imp);
E 12
E 10
				break;
	
			case HDHLNDN:
				if (sc->hdh_flags & HDH_UP)
					printf("hdh%d: LINE DOWN\n", unit);
				sc->hdh_flags &= ~HDH_UP;
				break;
	
			case HDHLOOP:
				break;
	
			case HDHSQERR:
				printf("hdh%d: HOST SEQUENCE ERROR\n", unit);
				break;
	
			case HDHSQRCV:
				printf("hdh%d: IMP SEQUENCE ERROR\n", unit);
				break;
	
			case HDHDTERR:
				printf("hdh%d: HOST DATA ERROR\n", unit);
				break;
	
			case HDHTIMO:
				printf("hdh%d: TIMEOUT\n", unit);
				break;
	
			default:
				printf("hdh%d: supervisor error, code=%x\n",
					unit, *p);
			}
		}

		/* hang a new supr read */

D 9
		hdh_iorq(unit, HDHSUPR, IMPMTU, HDHRDB+HDHSTR);
E 9
I 9
D 10
		hdh_iorq(unit, HDHSUPR, IMPMTU + 2, HDHRDB+HDHSTR);
E 10
I 10
		hdh_iorq(unit, HDHSUPR, IMP_RCVBUF, HDHRDB+HDHSTR);
E 10
E 9
	} 
}

snd_supr(unit, msg, len)
int unit, len;
char *msg;
{
	register struct hdh_softc *sc = &hdh_softc[unit];
D 4
	register struct hdh_chan *hc = &sc->hdh_chan[HDHSUPW];
E 4
	register struct mbuf *m;
	register char *p;
	register int cnt;

	if ((m = m_get(M_DONTWAIT, MT_DATA)) == NULL) {
		printf("hdh%d: cannot get supervisor cmnd buffer\n", unit);
D 7
			return(0);
E 7
I 7
			return;
E 7
	}

	cnt = len;
	m->m_len = len;
	p = mtod(m, char *);

	while(cnt--) *p++ = *msg++;

	cnt = if_wubaput(&sc->hdh_ifuba[SUPR], m);

	hdh_iorq(unit, HDHSUPW, cnt, HDHWRT+HDHEOS);
D 7

	return(1);
E 7
}
D 4

E 4
#endif NHDH
E 1
