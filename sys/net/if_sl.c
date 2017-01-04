/*
 * Copyright (c) 1987 Regents of the University of California.
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
 *
 *	@(#)if_sl.c	7.15 (Berkeley) 8/5/02
 */

/*
 * Serial Line interface
 *
 * Rick Adams
 * Center for Seismic Studies
 * 1300 N 17th Street, Suite 1450
 * Arlington, Virginia 22209
 * (703)276-7900
 * rick@seismo.ARPA
 * seismo!rick
 *
 * Pounded on heavily by Chris Torek (chris@mimsy.umd.edu, umcp-cs!chris).
 * N.B.: this belongs in netinet, not net, the way it stands now.
 * Should have a link-layer type designation, but wouldn't be
 * backwards-compatible.
 *
 * Converted to 4.3BSD Beta by Chris Torek.
 * Other changes made at Berkeley, based in part on code by Kirk Smith.
 */

/* $Header: if_sl.c,v 1.12 85/12/20 21:54:55 chris Exp $ */
/* from if_sl.c,v 1.11 84/10/04 12:54:47 rick Exp */

#include "sl.h"
#if NSL > 0

#include "param.h"
#include "conf.h"
#include "mbuf.h"
#include "buf.h"
#include "dkstat.h"
#include "socket.h"
#include "ioctl.h"
#include "file.h"
#include "tty.h"
#include "errno.h"
#include "malloc.h"

#include "if.h"
#include "netisr.h"
#include "route.h"
#include "if_fcs16.h"
#if INET
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/in_var.h"
#include "../netinet/ip.h"
#endif

#include "../machine/pte.h"
#include "../machine/mtpr.h"

#include "netmon.h"

#define	SLRBUF		2048	/* receive buffer where we accumulate bytes */
#define	SLMRU		(SLRBUF-2)	/* maximum receive unit */
#define	SLMAXMTU	SLMRU	/* largest MTU settable with SIOCSIFMTU */
#define	SLDEFMTU	1500	/* de facto Internet standard */
#define	SLIP_HIWAT	1000	/* don't start a new packet if HIWAT on queue */
#define	CLISTRESERVE	1000	/* Can't let clists get too low */

struct sl_softc {
	struct	ifnet sc_if;	/* network-visible interface */
	short	sc_flags;	/* see below */
	short	sc_ilen;	/* length of input-packet-so-far */
	struct	tty *sc_ttyp;	/* pointer to tty structure */
	char	*sc_mp;		/* pointer to next available buf char */
	char	*sc_buf;	/* input buffer */
} sl_softc[NSL];

/* flags */
#define	SC_ESCAPED	0x0001	/* saw a FRAME_ESCAPE */
#define	SC_OVFLO	0x0002	/* receive buffer overflow */

#define FRAME_END	 	0300		/* Frame End */
#define FRAME_ESCAPE		0333		/* Frame Esc */
#define TRANS_FRAME_END	 	0334		/* transposed frame end */
#define TRANS_FRAME_ESCAPE 	0335		/* transposed frame esc */

#define t_sc T_LINEP

int sloutput(), slioctl(), ttrstrt();

/*
 * Called from boot code to establish sl interfaces.
 */
slattach()
{
	register struct sl_softc *sc;
	register int i = 0;

	for (sc = sl_softc; i < NSL; sc++) {
		sc->sc_if.if_name = "sl";
		sc->sc_if.if_unit = i++;
		sc->sc_if.if_mtu = SLDEFMTU;
		sc->sc_if.if_flags = IFF_POINTOPOINT | IFF_NOFCS;
		sc->sc_if.if_ioctl = slioctl;
		sc->sc_if.if_output = sloutput;
		sc->sc_if.if_snd.ifq_maxlen = IFQ_MAXLEN;
		if_attach(&sc->sc_if);
	}
}

/*
 * Line specific open routine.
 * The SLIP line discipline cannot be opened this way.
 */
/* ARGSUSED */
slopen(dev, tp)
	dev_t dev;
	register struct tty *tp;
{
	/* Are we called by open or by TIOCSETD? */
	if (tp->t_line == SLIPDISC)	/* by open (must be already in use) */
		return (EBUSY);		/* tell them we are busy */
	else				/* by TIOCSETD */
		return (ENOTTY);	/* tell them they can't do this */
}

/*
 * Attach the given tty to the specified sl unit.
 */
/* ARGSUSED */
sltattach(dev, tp, nsl)
	dev_t dev;
	register struct tty *tp;
	register int nsl;
{
	register struct sl_softc *sc;
	int s;

	if (!suser())
		return (EPERM);
	if (nsl >= NSL)
		return (ENXIO);
	sc = &sl_softc[nsl];
	if (tp->t_line == SLIPDISC && tp->t_sc &&
	    (struct sl_softc*) tp->t_sc != sc)
		return (EBUSY);
	if (sc->sc_ttyp && sc->sc_ttyp != tp)
		return (EBUSY);
	sc->sc_flags = 0;
	sc->sc_ilen = 0;
	if (slinit(sc) == 0)
		return (ENOBUFS);
	sc->sc_ttyp = tp;

	s = spltty();
	ttyflush(tp, FREAD | FWRITE);
	tp->t_line = SLIPDISC;
	tp->t_sc = (caddr_t)sc;
	splx(s);

	return (0);
}

/*
 * Line specific close routine.
 * Detach the tty from the sl unit.
 * Mimics part of ttyclose().
 */
slclose(tp)
	struct tty *tp;
{
	register struct sl_softc *sc;
	int s;

	s = splimp();		/* paranoid; splnet probably ok */
	sc = (struct sl_softc *)tp->t_sc;
	if (sc != NULL) {
		if_down(&sc->sc_if);
		sc->sc_ttyp = NULL;
		tp->t_sc = NULL;
		free(sc->sc_buf, M_DEVBUF);
		sc->sc_buf = 0;
	}
	splx(s);
	tp->t_line = 0;
	ttywflush(tp);
}

/*
 * Line specific (tty) ioctl routine.
 * Provide a way to get the sl unit number.
 */
/* ARGSUSED */
sltioctl(tp, cmd, data, flag)
	struct tty *tp;
	caddr_t data;
{
	if (cmd == TIOCGETIF) {
		*(int *)data = ((struct sl_softc *)tp->t_sc)->sc_if.if_unit;
		return (0);
	}
	return (-1);
}

/*
 * Queue a packet.  Start transmission if not active.
 */
sloutput(ifp, m, dst)
	register struct ifnet *ifp;
	register struct mbuf *m;
	struct sockaddr *dst;
{
	register struct sl_softc *sc;
	int s;

	/*
	 * `Cannot happen' (see slioctl).  Someday we will extend
	 * the line protocol to support other address families.
	 */
	if (dst->sa_family != AF_INET) {
		printf("sl%d: af%d not supported\n", ifp->if_unit,
			dst->sa_family);
		m_freem(m);
		return (EAFNOSUPPORT);
	}

	sc = &sl_softc[ifp->if_unit];
	if (!(ifp->if_flags & IFF_UP) || sc->sc_ttyp == NULL ||
	    !(sc->sc_ttyp->t_state & TS_CARR_ON)) {
		m_freem(m);
		return (ENETDOWN);
	}

	if (!(ifp->if_flags & IFF_NOFCS) && ccitt_addfcs16(m)) {
		m_freem(m);
		return (ENOBUFS);
	}

	s = splimp();
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
		splx(s);
		m_freem(m);
		sc->sc_if.if_oerrors++;
		return (ENOBUFS);
	}
	IF_ENQUEUE(&ifp->if_snd, m);
	if (sc->sc_ttyp->t_outq.c_cc == 0) {
		splx(s);
		slstart(sc->sc_ttyp);
	} else
		splx(s);
	return (0);
}

/*
 * Start output on interface.  Get another datagram
 * to send from the interface queue and map it to
 * the interface before starting output.
 */
slstart(tp)
	register struct tty *tp;
{
	register struct sl_softc *sc = (struct sl_softc *)tp->t_sc;
	register struct mbuf *m;
	register int len;
	register u_char *cp;
	int nd, np, n, s;
	struct mbuf *m2;
	extern int cfreecount;

	for (;;) {
		/*
		 * If there is more in the output queue, just send it now.
		 * We are being called in lieu of ttstart and must do what
		 * it would.
		 */
		if (tp->t_outq.c_cc > 0)
			ttstart(tp);
		if (tp->t_outq.c_cc > SLIP_HIWAT)
			return;

		/*
		 * This happens briefly when the line shuts down.
		 */
		if (sc == NULL)
			return;

		/*
		 * If system is getting low on clists
		 * and we have something running already, stop here.
		 */
		if (cfreecount < CLISTRESERVE + sc->sc_if.if_mtu &&
		    tp->t_outq.c_cc)
			return;

		/*
		 * Get a packet and send it to the interface.
		 */
		s = splimp();
		IF_DEQUEUE(&sc->sc_if.if_snd, m);
		splx(s);
		if (m == NULL)
			return;

		/*
		 * The extra FRAME_END will start up a new packet, and thus
		 * will flush any accumulated garbage.  We do this whenever
		 * the line may have been idle for some time.
		 */
		if (tp->t_outq.c_cc == 0)
			(void) putc(FRAME_END, &tp->t_outq);

		while (m) {
			cp = mtod(m, u_char *);
			len = m->m_len;
			while (len > 0) {
				/*
				 * Find out how many bytes in the string we can
				 * handle without doing something special.
				 */
				nd = locc(FRAME_ESCAPE, len, cp);
				np = locc(FRAME_END, len, cp);
				n = len - MAX(nd, np);
				if (n) {
					/*
					 * Put n characters at once
					 * into the tty output queue.
					 */
					if (b_to_q((char *)cp, n, &tp->t_outq))
						break;
					len -= n;
					cp += n;
				}
				/*
				 * If there are characters left in the mbuf,
				 * the first one must be special..
				 * Put it out in a different form.
				 */
				if (len) {
					if (putc(FRAME_ESCAPE, &tp->t_outq))
						break;
					if (putc(*cp == FRAME_ESCAPE ?
					   TRANS_FRAME_ESCAPE : TRANS_FRAME_END,
					   &tp->t_outq)) {
						(void) unputc(&tp->t_outq);
						break;
					}
					cp++;
					len--;
				}
			}
			MFREE(m, m2);
			m = m2;
		}

		if (putc(FRAME_END, &tp->t_outq)) {
			/*
			 * Not enough room.  Remove a char to make room
			 * and end the packet normally.
			 * If you get many collisions (more than one or two
			 * a day) you probably do not have enough clists
			 * and you should increase "nclist" in param.c.
			 */
			(void) unputc(&tp->t_outq);
			(void) putc(FRAME_END, &tp->t_outq);
			sc->sc_if.if_collisions++;
		} else
			sc->sc_if.if_opackets++;
	}
}

slinit(sc)
	register struct sl_softc *sc;
{
	caddr_t p;

	if (sc->sc_buf == (char *) 0) {
		p = (caddr_t) malloc(SLRBUF, M_DEVBUF, M_NOWAIT);
		if (p)
			sc->sc_buf = sc->sc_mp = p;
		else {
			printf("sl%d: can't allocate buffer\n", sc - sl_softc);
			sc->sc_if.if_flags &= ~IFF_UP;
			return (0);
		}
	}
	return (1);
}

/*
 * Copy data buffer to mbuf chain; add ifnet pointer ifp.
 * Meticulously stolen from if_ubaget.
 */
struct mbuf *
sl_btom(sc, totlen, ifp)
	struct sl_softc *sc;
	register int totlen;
	struct ifnet *ifp;
{
	struct mbuf *top, **mp;
	register struct mbuf *m;
	int len;
	register caddr_t cp = sc->sc_buf, pp;

	top = 0;
	mp = &top;
	while (totlen > 0) {
		MGET(m, M_DONTWAIT, MT_DATA);
		if (m == 0) {
			m_freem(top);
			top = 0;
			goto out;
		}
		len = totlen;
		if (len >= CLBYTES/2) {
			struct pte *cpte, *ppte;
			int i;

			/*
			 * If doing the first mbuf and
			 * the interface pointer hasn't been put in,
			 * put it in a separate mbuf to preserve alignment.
			 */
			if (ifp) {
				len = 0;
				goto nopage;
			}
			MCLGET(m);
			if (m->m_len != CLBYTES)
				goto nopage;
			m->m_len = MIN(len, CLBYTES);
			if (!claligned(cp))
				goto copy;

			/*
			 * Switch pages mapped to the receive buffer with new
			 * page pp, as quick form of copy.
			 */
			pp = mtod(m, char *);
			cpte = kvtopte(cp);
			ppte = kvtopte(pp);
			for (i = 0; i < CLSIZE; i++) {
				struct pte t;
				t = *ppte; *ppte++ = *cpte; *cpte++ = t;
				mtpr(TBIS, cp);
				cp += NBPG;
				mtpr(TBIS, (caddr_t)pp);
				pp += NBPG;
			}
			goto nocopy;
		}
nopage:
		m->m_off = MMINOFF;
		if (ifp) {
			/*
			 * Leave room for ifp.
			 */
			m->m_len = MIN(MLEN - sizeof(ifp), len);
			m->m_off += sizeof(ifp);
		} else 
			m->m_len = MIN(MLEN, len);
copy:
		bcopy(cp, mtod(m, caddr_t), (unsigned)m->m_len);
		cp += m->m_len;
nocopy:
		*mp = m;
		mp = &m->m_next;
		totlen -= m->m_len;
		if (ifp) {
			/*
			 * Prepend interface pointer to first mbuf.
			 */
			m->m_len += sizeof(ifp);
			m->m_off -= sizeof(ifp);
			*(mtod(m, struct ifnet **)) = ifp;
			ifp = (struct ifnet *)0;
		}
	}
out:
	return (top);
}

/*
 * tty interface receiver interrupt.
 */
slinput(c, tp)
	register int c;
	register struct tty *tp;
{
	register struct sl_softc *sc;
	register struct mbuf *m;
	int s;

	tk_nin++;
	sc = (struct sl_softc *)tp->t_sc;
	if (sc == NULL)
		return;

	c &= 0xff;
	if (sc->sc_flags & SC_ESCAPED) {
		sc->sc_flags &= ~SC_ESCAPED;
		switch (c) {

		case TRANS_FRAME_ESCAPE:
			c = FRAME_ESCAPE;
			break;

		case TRANS_FRAME_END:
			c = FRAME_END;
			break;

		default:
			sc->sc_if.if_ierrors++;
			sc->sc_mp = sc->sc_buf;
			sc->sc_ilen = 0;
			return;
		}
	} else {
		switch (c) {

		case FRAME_END:
			if (sc->sc_ilen == 0)	/* ignore */
				return;
			if (sc->sc_flags & SC_OVFLO) {
				sc->sc_flags &= ~SC_OVFLO;
				sc->sc_if.if_ierrors++;
				sc->sc_mp = sc->sc_buf;
				sc->sc_ilen = 0;
				return;
			}
			if (!(sc->sc_if.if_flags & IFF_NOFCS)) {
				if (sc->sc_ilen < 3 ||
				    ccitt_fcs16check(sc->sc_buf, sc->sc_ilen)) {
					sc->sc_if.if_ierrors++;
					sc->sc_mp = sc->sc_buf;
					sc->sc_ilen = 0;
					return;
				}
				sc->sc_ilen -= 2;
			}
			m = sl_btom(sc, sc->sc_ilen, &sc->sc_if);
			sc->sc_mp = sc->sc_buf;
			sc->sc_ilen = 0;
			if (m == NULL) {
				sc->sc_if.if_ierrors++;
				return;
			}
			sc->sc_if.if_ipackets++;
			s = splimp();
			if (IF_QFULL(&ipintrq)) {
				IF_DROP(&ipintrq);
				sc->sc_if.if_ierrors++;
				m_freem(m);
			} else {
				IF_ENQUEUE(&ipintrq, m);
				schednetisr(NETISR_IP);
			}
			splx(s);
			return;

		case FRAME_ESCAPE:
			sc->sc_flags |= SC_ESCAPED;
			return;
		}
	}
	if (sc->sc_ilen >= SLRBUF) {
		sc->sc_flags |= SC_OVFLO;
		return;
	}
	*sc->sc_mp++ = c;
	sc->sc_ilen++;
}

/*
 * Handle modem control transition on a tty.
 * Flag indicates new state of carrier.
 * Returns 0 if the line should be turned off, otherwise 1.
 *
 * Supposed to be called at spltty, but we just need splnet or above.
 */
slmodem(tp, flag)
	register struct tty *tp;
	int flag;
{
	register struct sl_softc *sc;

	sc = (struct sl_softc *) tp->t_sc;
	if (flag) {
		tp->t_state |= TS_CARR_ON;
		if (sc) {
			sc->sc_if.if_flags |= IFF_UP;
#if NNETMON > 0
			netmon_ifevent(&sc->sc_if);
#endif
		}
	} else {
		tp->t_state &= ~TS_CARR_ON;
		if (sc)
			if_down((struct ifnet *) sc);
	}
	return(flag);
}

/*
 * Process an ioctl request.
 */
slioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
	register struct ifaddr *ifa = (struct ifaddr *)data;
	struct ifreq *ifr;
	register struct tty *tp;
	int s = splimp(), error = 0;

	switch (cmd) {

	case SIOCSIFADDR:
		if (ifa->ifa_addr.sa_family == AF_INET) {
			ifp->if_flags |= IFF_UP;
			if (tp = ((struct sl_softc *) ifp)->sc_ttyp)
				(*cdevsw[major(tp->t_dev)].d_ioctl)
					(tp->t_dev, TIOCSDTR);
		} else
			error = EAFNOSUPPORT;
		break;

	case SIOCSIFDSTADDR:
		if (ifa->ifa_addr.sa_family != AF_INET)
			error = EAFNOSUPPORT;
		break;

	case SIOCSIFFLAGS:
		if (ifp->if_flags & IFF_UP) {
			if (tp = ((struct sl_softc *) ifp)->sc_ttyp)
				(*cdevsw[major(tp->t_dev)].d_ioctl)
					(tp->t_dev, TIOCSDTR);
		} else {
			if (tp = ((struct sl_softc *) ifp)->sc_ttyp)
				(*cdevsw[major(tp->t_dev)].d_ioctl)
					(tp->t_dev, TIOCCDTR);
		}
		break;

	case SIOCSIFMTU:
		ifr = (struct ifreq *) data;
		if (ifr->ifr_mtu < IF_MINMTU) {
			error = EINVAL;
			break;
		}
		if (ifr->ifr_mtu > SLMAXMTU) {
			error = EINVAL;
			break;
		}
		ifp->if_mtu = ifr->ifr_mtu;
		break;

	default:
		error = EINVAL;
	}
	splx(s);
	return (error);
}
#endif
