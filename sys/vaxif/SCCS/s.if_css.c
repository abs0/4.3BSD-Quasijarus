h04749
s 00011/00006/00413
d D 7.6 88/06/29 17:55:26 bostic 21 20
c install approved copyright notice
e
s 00005/00005/00414
d D 7.5 88/05/26 09:39:12 karels 20 19
c finish what I was doing
e
s 00017/00005/00402
d D 7.4 88/05/14 11:10:40 karels 19 18
c impattach now takes name/unit instead of ubadevice; clean up output
c side when resetting
e
s 00072/00067/00335
d D 7.3 88/02/08 10:26:11 karels 18 17
c new IMP interface
e
s 00001/00001/00401
d D 7.2 87/12/05 15:53:20 bostic 17 16
c old assignment operator
e
s 00001/00001/00401
d D 7.1 86/06/05 17:01:39 mckusick 16 15
c 4.3BSD release version
e
s 00001/00001/00401
d D 6.7 85/11/09 17:27:37 karels 15 14
c typo
e
s 00002/00000/00400
d D 6.6 85/10/24 10:06:02 bloom 14 13
c add "#if N?? > 0" 
e
s 00005/00004/00395
d D 6.5 85/09/16 22:36:35 karels 13 12
c pas ifp to if_rubaget
e
s 00007/00001/00392
d D 6.4 85/06/08 13:51:59 mckusick 12 11
c Add copyright
e
s 00002/00000/00391
d D 6.3 85/06/03 08:42:00 karels 11 10
c now they compile at least
e
s 00009/00009/00382
d D 6.2 84/08/29 20:42:17 bloom 10 9
c change ot includes.  no more ../h
e
s 00000/00000/00391
d D 6.1 83/07/29 07:37:08 sam 9 8
c 4.2 distribution
e
s 00000/00001/00391
d D 4.8 83/05/27 13:49:42 sam 8 7
c lint
e
s 00000/00007/00392
d D 4.7 82/12/22 16:22:51 sam 7 6
c left over COUNT's from way back when
e
s 00001/00001/00398
d D 4.6 82/12/17 12:13:08 sam 6 5
c sun merge
e
s 00001/00001/00398
d D 4.5 82/10/24 14:38:00 wnj 5 4
c create netif directory
e
s 00001/00001/00398
d D 4.4 82/10/23 10:10:24 root 4 3
c impattach takes 2 arguments
e
s 00007/00005/00392
d D 4.3 82/10/10 16:58:22 root 3 2
c move vax headers into vax directories
e
s 00003/00005/00394
d D 4.2 82/10/09 06:09:16 wnj 2 1
c fix includes
e
s 00399/00000/00000
d D 4.1 82/07/20 22:39:12 sam 1 0
c date and time created 82/07/20 22:39:12 by sam
e
u
U
t
T
I 1
D 12
/*      %M%     %I%     %E%     */
E 12
I 12
/*
D 16
 * Copyright (c) 1982 Regents of the University of California.
E 16
I 16
D 18
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 16
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 18
I 18
D 21
 * Copyright (c) 1982,1986,1988 Regents of the University of California.
E 21
I 21
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 21
 * All rights reserved.
E 18
 *
I 18
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
 *
E 18
 *	%W% (Berkeley) %G%
 */
E 12

#include "css.h"
I 14
#if NCSS > 0
E 14

/*
 * DEC/CSS IMP11-A ARPAnet IMP interface driver.
 * Since "imp11a" is such a mouthful, it is called
 * "css" after the LH/DH being called "acc".
 *
 * Configuration notes:
 *
 * As delivered from DEC/CSS, it
 * is addressed and vectored as two DR11-B's.  This makes
 * Autoconfig almost IMPOSSIBLE.  To make it work, the
 * interrupt vectors must be restrapped to make the vectors
 * consecutive.  The 020 hole between the CSR addresses is
 * tolerated, althought that could be cleaned-up also.
 *
 * Additionally, the TRANSMIT side of the IMP11-A has the
 * lower address of the two subunits, so the vector ordering
 * in the CONFIG file is reversed from most other devices.
 * It should be:
 *
 * device css0 ....  cssxint cssrint
 *
 * If you get it wrong, it will still autoconfig, but will just
D 13
 * sit there with RECIEVE IDLE indicated on the front panel.
E 13
I 13
 * sit there with RECEIVE IDLE indicated on the front panel.
E 13
 */
I 6
D 18
#include "../machine/pte.h"
E 6

E 18
D 10
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
D 6
#include "../h/pte.h"
E 6
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
D 3
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/cpu.h"
#include "../h/mtpr.h"
E 3
#include "../h/vmmac.h"
E 10
I 10
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
#include "vmmac.h"
E 10
D 2
#include "../net/if_css.h"
#include "../net/in.h"
#include "../net/in_systm.h"
E 2
I 2
D 3
#include "../vaxif/if_css.h"
E 3
I 3

I 18
#include "../machine/pte.h"

E 18
E 3
E 2
#include "../net/if.h"
D 2
#include "../net/if_imp.h"
#include "../net/if_uba.h"
E 2
I 2
#include "../netimp/if_imp.h"
I 3

#include "../vax/cpu.h"
#include "../vax/mtpr.h"
D 5
#include "../vaxif/if_css.h"
E 5
I 5
D 10
#include "../vaxif/if_cssreg.h"
E 5
E 3
#include "../vaxif/if_uba.h"
E 10
I 10
#include "if_cssreg.h"
#include "if_uba.h"
E 10
I 3
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 3
E 2

int     cssprobe(), cssattach(), cssrint(), cssxint();
struct  uba_device *cssinfo[NCSS];
u_short cssstd[] = { 0 };
struct  uba_driver cssdriver =
        { cssprobe, 0, cssattach, 0, cssstd, "css", cssinfo };
D 18
#define CSSUNIT(x)      minor(x)
E 18

D 18
int     cssinit(), cssstart(), cssreset();
E 18
I 18
int     cssinit(), cssoutput(), cssdown(), cssreset();
E 18

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
 * e.g. IP, interact with the IMP driver, rather than the CSS.
 */
struct  css_softc {
D 18
        struct  ifnet *css_if;          /* pointer to IMP's ifnet struct */
        struct  impcb *css_ic;          /* data structure shared with IMP */
        struct  ifuba css_ifuba;        /* UNIBUS resources */
        struct  mbuf *css_iq;           /* input reassembly queue */
        short   css_olen;               /* size of last message sent */
        char    css_flush;              /* flush remainder of message */
E 18
I 18
	struct	imp_softc *css_imp;	/* pointer to IMP's imp_softc struct */
	struct	ifuba css_ifuba;	/* UNIBUS resources */
	struct	mbuf *css_iq;		/* input reassembly queue */
	short	css_olen;		/* size of last message sent */
	char	css_flush;		/* flush remainder of message */
E 18
} css_softc[NCSS];

/*
 * Reset the IMP and cause a transmitter interrupt by
 * performing a null DMA.
 */
cssprobe(reg)
        caddr_t reg;
{
        register int br, cvec;          /* r11, r10 value-result */
        register struct cssdevice *addr = (struct cssdevice *)reg;

D 7
COUNT(CSSPROBE);
E 7
#ifdef lint
        br = 0; cvec = br; br = cvec;
        cssrint(0); cssxint(0);
#endif

D 18

E 18
        addr->css_icsr = CSS_CLR;
        addr->css_ocsr = CSS_CLR;
        DELAY(50000);
	addr->css_icsr = 0;
	addr->css_ocsr = 0;
        DELAY(50000);

	addr->css_oba = 0;
	addr->css_owc = -1;
        addr->css_ocsr = CSS_IE | CSS_GO;	/* enable interrupts */
        DELAY(50000);
        addr->css_ocsr = 0;

        return (1);
}

/*
 * Call the IMP module to allow it to set up its internal
 * state, then tie the two modules together by setting up
 * the back pointers to common data structures.
 */
cssattach(ui)
D 19
        struct uba_device *ui;
E 19
I 19
        register struct uba_device *ui;
E 19
{
        register struct css_softc *sc = &css_softc[ui->ui_unit];
        register struct impcb *ip;
D 18
        struct ifimpcb {
                struct  ifnet ifimp_if;
                struct  impcb ifimp_impcb;
        } *ifimp;
E 18

D 7
COUNT(CSSATTACH);
E 7
D 4
        if ((ifimp = (struct ifimpcb *)impattach(ui)) == 0)
E 4
I 4
D 18
        if ((ifimp = (struct ifimpcb *)impattach(ui, cssreset)) == 0)
E 18
I 18
D 19
        if ((sc->css_imp = impattach(ui, cssreset)) == 0)
E 19
I 19
        if ((sc->css_imp = impattach(ui->ui_driver->ud_dname, ui->ui_unit,
	    cssreset)) == 0)
E 19
E 18
E 4
D 13
                panic("cssattach");             /* XXX */
E 13
I 13
                return;
E 13
D 18
        sc->css_if = &ifimp->ifimp_if;
        ip = &ifimp->ifimp_impcb;
        sc->css_ic = ip;
E 18
I 18
	ip = &sc->css_imp->imp_cb;
E 18
        ip->ic_init = cssinit;
D 18
        ip->ic_start = cssstart;
E 18
I 18
        ip->ic_output = cssoutput;
        ip->ic_down = cssdown;
E 18
	sc->css_ifuba.ifu_flags = UBA_CANTWAIT | UBA_NEED16;
#ifdef notdef
D 17
	sc->css_ifuba.ifu_flags =| UBA_NEEDBDP;
E 17
I 17
	sc->css_ifuba.ifu_flags |= UBA_NEEDBDP;
E 17
#endif
}

/*
 * Reset interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
cssreset(unit, uban)
        int unit, uban;
{
        register struct uba_device *ui;
D 18
        struct css_softc *sc;
E 18
I 18
        register struct css_softc *sc;
E 18

D 7
COUNT(CSSCLR);
E 7
        if (unit >= NCSS || (ui = cssinfo[unit]) == 0 || ui->ui_alive == 0 ||
            ui->ui_ubanum != uban)
                return;
        printf(" css%d", unit);
        sc = &css_softc[unit];
I 11
D 18
	sc->css_if->if_flags &= ~IFF_RUNNING;
E 18
I 18
	sc->css_imp->imp_if.if_flags &= ~IFF_RUNNING;
I 19
	cssoflush(unit);
E 19
E 18
E 11
        /* must go through IMP to allow it to set state */
D 18
        (*sc->css_if->if_init)(unit);
E 18
I 18
        (*sc->css_imp->imp_if.if_init)(sc->css_imp->imp_if.if_unit);
E 18
}

/*
 * Initialize interface: clear recorded pending operations,
 * and retrieve, and reinitialize UNIBUS resources.
 */
cssinit(unit)
        int unit;
{       
        register struct css_softc *sc;
        register struct uba_device *ui;
        register struct cssdevice *addr;
        int x, info;

D 7
COUNT(CSSINIT);
E 7
	if (unit >= NCSS || (ui = cssinfo[unit]) == 0 || ui->ui_alive == 0) {
		printf("css%d: not alive\n", unit);
		return(0);
	}
	sc = &css_softc[unit];

	/*
	 * Header length is 0 to if_ubainit since we have to pass
	 * the IMP leader up to the protocol interpretaion
	 * routines.  If we had the deader length as
	 * sizeof(struct imp_leader), then the if_ routines
	 * would assume we handle it on input and output.
	 */
	
D 18
        if (if_ubainit(&sc->css_ifuba, ui->ui_ubanum, 0,(int)btoc(IMPMTU)) == 0) {
E 18
I 18
        if ((sc->css_imp->imp_if.if_flags & IFF_RUNNING) == 0 &&
	    if_ubainit(&sc->css_ifuba, ui->ui_ubanum, 0,
	    (int)btoc(IMP_RCVBUF)) == 0) {
E 18
                printf("css%d: can't initialize\n", unit);
		ui->ui_alive = 0;
I 13
D 18
		sc->css_if->if_flags &= ~(IFF_UP | IFF_RUNNING);
E 18
I 18
		sc->css_imp->imp_if.if_flags &= ~(IFF_UP | IFF_RUNNING);
E 18
E 13
		return(0);
        }
I 11
D 18
	sc->css_if->if_flags |= IFF_RUNNING;
E 18
I 18
	sc->css_imp->imp_if.if_flags |= IFF_RUNNING;
E 18
E 11
        addr = (struct cssdevice *)ui->ui_addr;

        /* reset the imp interface. */
        x = spl5();
        addr->css_icsr = CSS_CLR;
        addr->css_ocsr = CSS_CLR;
	DELAY(100);
	addr->css_icsr = 0;
	addr->css_ocsr = 0;
        addr->css_icsr = IN_HRDY;       /* close the relay */
	DELAY(5000);
        splx(x);

        /*
	 * This may hang if the imp isn't really there.
	 * Will test and verify safe operation.
	 */

	x = 500;
	while (x-- > 0) {
		if ((addr->css_icsr & (IN_HRDY|IN_IMPNR)) == IN_HRDY) 
			break;
                addr->css_icsr = IN_HRDY;	/* close the relay */
                DELAY(5000);
        }

	if (x <= 0) {
		printf("css%d: imp doesn't respond, icsr=%b\n", unit,
			CSS_INBITS, addr->css_icsr);
		goto down;
	}

        /*
         * Put up a read.  We can't restart any outstanding writes
         * until we're back in synch with the IMP (i.e. we've flushed
         * the NOOPs it throws at us).
D 18
	 * Note: IMPMTU includes the leader.
E 18
I 18
	 * Note: IMP_RCVBUF includes the leader.
E 18
         */

        x = spl5();
        info = sc->css_ifuba.ifu_r.ifrw_info;
        addr->css_iba = (u_short)info;
D 18
        addr->css_iwc = -(IMPMTU >> 1);
E 18
I 18
        addr->css_iwc = -(IMP_RCVBUF >> 1);
E 18
        addr->css_icsr = 
                IN_HRDY | CSS_IE | IN_WEN | ((info & 0x30000) >> 12) | CSS_GO;
        splx(x);
	return(1);

down:
	ui->ui_alive = 0;
	return(0);
}

/*
I 18
 * Drop the host ready line to mark host down.
 * UNTESTED.
 */
cssdown(unit)
	int unit;
{
        register struct cssdevice *addr;
D 19
	int x;
E 19

	addr = (struct cssdevice *)(cssinfo[unit]->ui_addr);
        /* reset the imp interface. */
D 19
        x = spl5();
E 19
        addr->css_icsr = CSS_CLR;
        addr->css_ocsr = CSS_CLR;
	DELAY(100);
	addr->css_icsr = 0;
	addr->css_ocsr = 0;
D 19
        splx(x);
E 19
I 19
	cssoflush(unit);
E 19
	return (1);
I 19
}

cssoflush(unit)
	int unit;
{
D 20
	register struct acc_softc *sc = &acc_softc[unit];
E 20
I 20
	register struct css_softc *sc = &css_softc[unit];
E 20

D 20
	sc->acc_imp->imp_cb.ic_oactive = 0;
	if (sc->acc_ifuba.ifu_xtofree) {
		m_freem(sc->acc_ifuba.ifu_xtofree);
		sc->acc_ifuba.ifu_xtofree = 0;
E 20
I 20
	sc->css_imp->imp_cb.ic_oactive = 0;
	if (sc->css_ifuba.ifu_xtofree) {
		m_freem(sc->css_ifuba.ifu_xtofree);
		sc->css_ifuba.ifu_xtofree = 0;
E 20
	}
E 19
}

/*
E 18
 * Start output on an interface.
 */
D 18
cssstart(dev)
        dev_t dev;
E 18
I 18
cssoutput(unit, m)
        int unit;
        struct mbuf *m;
E 18
{
D 18
        int unit = CSSUNIT(dev), info;
E 18
I 18
        int info;
E 18
        struct uba_device *ui = cssinfo[unit];
        register struct css_softc *sc = &css_softc[unit];
        register struct cssdevice *addr;
D 18
        struct mbuf *m;
        u_short cmd;
E 18

D 7
COUNT(CSSSTART);
E 7
D 18
        if (sc->css_ic->ic_oactive)
                goto restart;
        
        /*
         * Not already active, deqeue a request and
         * map it onto the UNIBUS.  If no more
         * requeusts, just return.
         */
        IF_DEQUEUE(&sc->css_if->if_snd, m);
        if (m == 0) {
                sc->css_ic->ic_oactive = 0;
                return;
        }
E 18
        sc->css_olen = if_wubaput(&sc->css_ifuba, m);
D 18

restart:
E 18
        /*
         * Have request mapped to UNIBUS for transmission.
         * Purge any stale data from the BDP, and start the output.
         */
	if (sc->css_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(sc->css_ifuba.ifu_uba, sc->css_ifuba.ifu_w.ifrw_bdp);
        addr = (struct cssdevice *)ui->ui_addr;
        info = sc->css_ifuba.ifu_w.ifrw_info;
        addr->css_oba = (u_short)info;
        addr->css_owc = -((sc->css_olen + 1) >> 1);
D 18
        cmd = CSS_IE | OUT_ENLB | ((info & 0x30000) >> 12) | CSS_GO;
        addr->css_ocsr = cmd;
        sc->css_ic->ic_oactive = 1;
E 18
I 18
        addr->css_ocsr =
	    (u_short)(CSS_IE | OUT_ENLB | ((info & 0x30000) >> 12) | CSS_GO);
        sc->css_imp->imp_cb.ic_oactive = 1;
E 18
}

/*
 * Output interrupt handler.
 */
cssxint(unit)
{
        register struct uba_device *ui = cssinfo[unit];
        register struct css_softc *sc = &css_softc[unit];
        register struct cssdevice *addr;

D 7
COUNT(CSSXINT);
E 7
        addr = (struct cssdevice *)ui->ui_addr;
D 18
        if (sc->css_ic->ic_oactive == 0) {
E 18
I 18
        if (sc->css_imp->imp_cb.ic_oactive == 0) {
E 18
                printf("css%d: stray output interrupt csr=%b\n",
			unit, addr->css_ocsr, CSS_OUTBITS);
                return;
        }
D 18
        sc->css_if->if_opackets++;
        sc->css_ic->ic_oactive = 0;
E 18
I 18
        sc->css_imp->imp_if.if_opackets++;
        sc->css_imp->imp_cb.ic_oactive = 0;
E 18
        if (addr->css_ocsr & CSS_ERR){
D 18
                sc->css_if->if_oerrors++;
E 18
I 18
                sc->css_imp->imp_if.if_oerrors++;
E 18
                printf("css%d: output error, ocsr=%b icsr=%b\n", unit,
                        addr->css_ocsr, CSS_OUTBITS,
			addr->css_icsr, CSS_INBITS);
	}
	if (sc->css_ifuba.ifu_xtofree) {
		m_freem(sc->css_ifuba.ifu_xtofree);
		sc->css_ifuba.ifu_xtofree = 0;
	}
D 18
	if (sc->css_if->if_snd.ifq_head)
		cssstart(unit);
E 18
I 18
	impstart(sc->css_imp);
E 18
}

/*
 * Input interrupt handler
 */
cssrint(unit)
{
        register struct css_softc *sc = &css_softc[unit];
        register struct cssdevice *addr;
D 8
        register struct ifqueue *inq;
E 8
        struct mbuf *m;
        int len, info;

D 7
COUNT(CSSRINT);
E 7
D 18
        sc->css_if->if_ipackets++;
E 18
I 18
        sc->css_imp->imp_if.if_ipackets++;
E 18

        /*
         * Purge BDP; flush message if error indicated.
         */

        addr = (struct cssdevice *)cssinfo[unit]->ui_addr;
	if (sc->css_ifuba.ifu_flags & UBA_NEEDBDP)
		UBAPURGE(sc->css_ifuba.ifu_uba, sc->css_ifuba.ifu_r.ifrw_bdp);
        if (addr->css_icsr & CSS_ERR) {
                printf("css%d: recv error, csr=%b\n", unit,
                    addr->css_icsr, CSS_INBITS);
D 18
                sc->css_if->if_ierrors++;
E 18
I 18
                sc->css_imp->imp_if.if_ierrors++;
E 18
                sc->css_flush = 1;
        }

        if (sc->css_flush) {
                if (addr->css_icsr & IN_EOM)
                        sc->css_flush = 0;
                goto setup;
        }

D 18
        len = IMPMTU + (addr->css_iwc << 1);
	if (len < 0 || len > IMPMTU) {
E 18
I 18
        len = IMP_RCVBUF + (addr->css_iwc << 1);
	if (len < 0 || len > IMP_RCVBUF) {
E 18
		printf("css%d: bad length=%d\n", len);
D 18
		sc->css_if->if_ierrors++;
E 18
I 18
		sc->css_imp->imp_if.if_ierrors++;
E 18
		goto setup;
	}

        /*
D 13
         * The last parameter is always 0 since using
E 13
I 13
         * The offset parameter is always 0 since using
E 13
         * trailers on the ARPAnet is insane.
         */
D 13
        m = if_rubaget(&sc->css_ifuba, len, 0);
E 13
I 13
D 15
        m = if_rubaget(&sc->css_ifuba, len, 0, &sc->css_if);
E 15
I 15
D 18
        m = if_rubaget(&sc->css_ifuba, len, 0, sc->css_if);
E 18
I 18
        m = if_rubaget(&sc->css_ifuba, len, 0, &sc->css_imp->imp_if);
E 18
E 15
E 13
        if (m == 0)
                goto setup;
        if ((addr->css_icsr & IN_EOM) == 0) {
		if (sc->css_iq)
			m_cat(sc->css_iq, m);
		else
			sc->css_iq = m;
		goto setup;
	}
	if (sc->css_iq) {
		m_cat(sc->css_iq, m);
		m = sc->css_iq;
		sc->css_iq = 0;
        }
        impinput(unit, m);

setup:
        /*
         * Setup for next message.
         */
        info = sc->css_ifuba.ifu_r.ifrw_info;
        addr->css_iba = (u_short)info;
D 18
        addr->css_iwc = - (IMPMTU >> 1);
E 18
I 18
        addr->css_iwc = - (IMP_RCVBUF >> 1);
E 18
        addr->css_icsr =
                IN_HRDY | CSS_IE | IN_WEN | ((info & 0x30000) >> 12) | CSS_GO;
}
I 14
#endif
E 14
E 1
