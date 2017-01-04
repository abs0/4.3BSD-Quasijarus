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
 *	@(#)if_pppasync.c	7.4 (Berkeley) 4/15/07
 */

/*
 * Asynchronous PPP
 *
 * This module implements the asynchronous PPP framing defined in RFC 1662 by
 * attaching a ppp interface to a tty line as a line discipline.
 *
 * Based on the sl module by Rick Adams, Chris Torek, Kirk Smith, and others.
 */

#include "ppp.h"
#if NPPP > 0

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
#include "if_hdlc.h"
#include "if_fcs16.h"
#include "if_ppp.h"
#include "if_pppvar.h"

#include "../machine/pte.h"
#include "../machine/mtpr.h"

#define	PPPASYNC_RBUF	2048	/* receive buffer where we accumulate bytes */
#define	PPPASYNC_MRU	(PPPASYNC_RBUF-2)	/* physical MRU and MTU we */
#define	PPPASYNC_MTU	PPPASYNC_MRU		/* declare to the ppp moduile */
#define	PPPASYNC_HIWAT	1000	/* don't start a new packet if HIWAT on queue */
#define	CLISTRESERVE	1000	/* Can't let clists get too low */

#define t_pp T_LINEP

struct ppp_hw pppasync_phw;
int pppasync_dtr_hack;

int pppasync_output(), pppasync_up(), pppasync_down(), pppasync_check();

/*
 * Called from pppattach at boot time to initialise the pppasync module.
 */
pppasync_init()
{
	pppasync_phw.phw_mtu = PPPASYNC_MTU;
	pppasync_phw.phw_mru = PPPASYNC_MRU;
	pppasync_phw.phw_caps = PPP_PHYCAPS_OKSENDACCM | PPP_PHYCAPS_OKRECVACCM
				| PPP_PHYCAPS_OKSENDACCOMP
				| PPP_PHYCAPS_WANTSENDACCOMP
				| PPP_PHYCAPS_OKRECVACCOMP
				| PPP_PHYCAPS_WANTRECVACCOMP
				| PPP_PHYCAPS_OKSENDPROTCOMP
				| PPP_PHYCAPS_WANTSENDPROTCOMP
				| PPP_PHYCAPS_OKRECVPROTCOMP
				| PPP_PHYCAPS_WANTRECVPROTCOMP;
	pppasync_phw.phw_output = pppasync_output;
	pppasync_phw.phw_up = pppasync_up;
	pppasync_phw.phw_down = pppasync_down;
	pppasync_phw.phw_check = pppasync_check;
}

/*
 * Line specific open routine.
 * The PPP line discipline cannot be opened this way.
 */
/* ARGSUSED */
pppasync_topen(dev, tp)
	dev_t dev;
	register struct tty *tp;
{
	/* Are we called by open or by TIOCSETD? */
	if (tp->t_line == PPPDISC)	/* by open (must be already in use) */
		return (EBUSY);		/* tell them we are busy */
	else				/* by TIOCSETD */
		return (ENOTTY);	/* tell them they can't do this */
}

/*
 * Attach the given tty to the specified ppp unit.
 * called at spltty.
 */
/* ARGSUSED */
pppasync_attach(dev, tp, nppp)
	dev_t dev;
	register struct tty *tp;
	register int nppp;
{
	register struct ppp_softc *pp;
	int s;

	if (!suser())
		return (EPERM);
	if (nppp >= NPPP)
		return (ENXIO);
	pp = &ppp_softc[nppp];
	if (tp->t_line == PPPDISC && (struct ppp_softc*) tp->t_pp == pp)
		return (0);
	if (tp->t_line == PPPDISC)
		return (EBUSY);
	if (pp->pp_hw)
		return (EBUSY);

	pp->pp_asbuf = (caddr_t) malloc(PPPASYNC_RBUF, M_DEVBUF, M_NOWAIT);
	if (!pp->pp_asbuf) {
		printf("ppp%d: can't allocate async receive buffer\n",
			pp - ppp_softc);
		return (ENOBUFS);
	}
	pp->pp_asstate = PPPASYNC_RXSTATE_ADDR;
	pp->pp_asfcs = CCITT_FCS16_INIT;

	pp->pp_hw = &pppasync_phw;
	pp->pp_hwhnd = (u_long) tp;

	s = spltty();
	ttyflush(tp, FREAD | FWRITE);
	tp->t_line = PPPDISC;
	tp->t_pp = (caddr_t) pp;
	splx(s);

	pp->pp_desmtu = pppasync_phw.phw_mtu;
	pp->pp_desmru = pppasync_phw.phw_mru;
	return (0);
}

/*
 * Line specific close routine.
 * Detach the tty from the ppp unit.
 * Mimics part of ttyclose().
 *
 * May be called at spl0 or spltty.
 * We spltty() ourselves just in case.
 */
pppasync_tclose(tp)
	struct tty *tp;
{
	register struct ppp_softc *pp;
	int s;

	s = spltty();
	pp = (struct ppp_softc *) tp->t_pp;
	pppreset(pp);
	pp->pp_hw = 0;
	tp->t_pp = 0;
	free(pp->pp_asbuf, M_DEVBUF);

	tp->t_line = 0;
	ttywflush(tp);
	splx(s);
}

/*
 * Line specific (tty) ioctl routine.
 * Provide a way to get the ppp unit number.
 */
/* ARGSUSED */
pppasync_tioctl(tp, cmd, data, flag)
	struct tty *tp;
	caddr_t data;
{
	if (cmd == TIOCGETIF) {
		*(int *)data = ((struct ppp_softc *)tp->t_pp)->pp_if.if_unit;
		return (0);
	}
	return (-1);
}

/*
 * Queue a packet.  Start transmission if not active.
 */
pppasync_output(pp, m, proto)
	register struct ppp_softc *pp;
	register struct mbuf *m;
	int proto;
{
	register struct tty *tp;
	register struct mbuf *n;
	int s;

	tp = (struct tty *) pp->pp_hwhnd;
	if ((tp->t_state & TS_CARR_ON) == 0) {
		m_freem(m);
		return (ENETDOWN);
	}

	/* Prepend (possibly compressed) HDLC header */
	if (m->m_off < MMINOFF + sizeof(struct hdlc_header) || M_HASCL(m)) {
		MGET(n, M_DONTWAIT, MT_HEADER);
		if (n == 0) {
			m_freem(m);
			pp->pp_if.if_oerrors++;
			return (ENOBUFS);
		}
		n->m_off = MMINOFF + sizeof(struct hdlc_header);
		n->m_len = 0;
		n->m_next = m;
		m = n;
	}
	*((char *) m + --m->m_off) = proto & 0xFF;
	m->m_len++;
	/* The condition below automagically catches LCP */
	if (proto & 0xFF00 || !(pp->pp_peerconf & PEERCONF_OKPROTCOMP)) {
		*((char *) m + --m->m_off) = proto >> 8;
		m->m_len++;
	}
	if (proto == PPPPROTO_LCP || !(pp->pp_peerconf & PEERCONF_OKACCOMP)) {
		*((char *) m + --m->m_off) = PPP_FRAME_CONTROL;
		*((char *) m + --m->m_off) = PPP_FRAME_ADDR;
		m->m_len += 2;
	}
	if (ccitt_addfcs16(m)) {
		m_freem(m);
		pp->pp_if.if_oerrors++;
		return (ENOBUFS);
	}

	s = splimp();
	if (IF_QFULL(&pp->pp_if.if_snd)) {
		IF_DROP(&pp->pp_if.if_snd);
		splx(s);
		m_freem(m);
		pp->pp_if.if_oerrors++;
		return (ENOBUFS);
	}
	IF_ENQUEUE(&pp->pp_if.if_snd, m);
	if (tp->t_outq.c_cc == 0) {
		splx(s);
		pppasync_start(tp);
	} else
		splx(s);
	return (0);
}

/*
 * Start output on interface. Get another packet to send from the interface
 * queue and map it to the interface before starting output.
 *
 * Compared to the original SLIP version, this async PPP version has additional
 * ugliness to deal with ACCM. We use a trick. This routine is written for
 * ACCM = 0. If ACCM != 0 an assistant routine is called to crawl one byte at a
 * time. We also have to check for LCP (requires ACCM of all ones, argh!), but
 * we have a trick for it too, which is below.
 */
#if BYTE_ORDER == BIG_ENDIAN
#define	LCPHDR	0xFF03C021
#endif
#if BYTE_ORDER == LITTLE_ENDIAN
#define	LCPHDR	0x21C003FF
#endif
pppasync_start(tp)
	register struct tty *tp;
{
	register struct ppp_softc *pp = (struct ppp_softc *) tp->t_pp;
	register struct mbuf *m;
	register int len;
	register u_char *cp;
	int nd, np, n, s;
	struct mbuf *m2;
	u_long accm;
	extern int cfreecount;

	for (;;) {
		/*
		 * If there is more in the output queue, just send it now.
		 * We are being called in lieu of ttstart and must do what
		 * it would.
		 */
		if (tp->t_outq.c_cc > 0)
			ttstart(tp);
		if (tp->t_outq.c_cc > PPPASYNC_HIWAT)
			return;

		/*
		 * This happens briefly when the line shuts down.
		 */
		if (pp == NULL)
			return;

		/*
		 * If system is getting low on clists
		 * and we have something running already, stop here.
		 */
		if (cfreecount < CLISTRESERVE + PPPASYNC_MTU && tp->t_outq.c_cc)
			return;

		/*
		 * Get a packet and send it to the interface.
		 */
		s = splimp();
		IF_DEQUEUE(&pp->pp_if.if_snd, m);
		splx(s);
		if (m == NULL)
			return;

		/*
		 * The extra flag char will start up a new packet, and thus
		 * will flush any accumulated garbage.  We do this whenever
		 * the line may have been idle for some time.
		 */
		if (tp->t_outq.c_cc == 0)
			(void) putc(PPP_OCTFRM_FLAG, &tp->t_outq);

		/* Check ACCM. If ACCM != 0 call ugliness assist routine. */
		if (*mtod(m, u_long *) == LCPHDR)
			accm = 0xFFFFFFFF;
		else
			accm = pp->pp_raccm;
		if (accm) {
			pppasync_ugly_accm(m, tp, accm);
			goto endframe;
		}

		/* ACCM = 0 */
		while (m) {
			cp = mtod(m, u_char *);
			len = m->m_len;
			while (len > 0) {
				/*
				 * Find out how many bytes in the string we can
				 * handle without doing something special.
				 */
				nd = locc(PPP_OCTFRM_ESCAPE, len, cp);
				np = locc(PPP_OCTFRM_FLAG, len, cp);
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
					if (putc(PPP_OCTFRM_ESCAPE,&tp->t_outq))
						break;
					if (putc(*cp ^ 0x20, &tp->t_outq)) {
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

endframe:	if (putc(PPP_OCTFRM_FLAG, &tp->t_outq)) {
			/*
			 * Not enough room.  Remove a char to make room
			 * and end the packet normally.
			 * If you get many collisions (more than one or two
			 * a day) you probably do not have enough clists
			 * and you should increase "nclist" in param.c.
			 */
			(void) unputc(&tp->t_outq);
			(void) putc(PPP_OCTFRM_FLAG, &tp->t_outq);
			pp->pp_if.if_collisions++;
		} else
			pp->pp_if.if_opackets++;
	}
}

/* Put the packet out on the character send queue respecting the ugly ACCM */
pppasync_ugly_accm(m, tp, accm)
	register struct mbuf *m;
	register struct tty *tp;
	register u_long accm;
{
	register u_char *cp;
	register int len, ch;
	struct mbuf *m2;

	while (m) {
		cp = mtod(m, u_char *);
		len = m->m_len;
		while (len > 0) {
			ch = *cp++;
			if (ch < 0x20 && accm & (1 << ch) ||
			    ch == PPP_OCTFRM_FLAG || ch == PPP_OCTFRM_ESCAPE) {
				if (putc(PPP_OCTFRM_ESCAPE, &tp->t_outq))
					break;
				if (putc(ch ^ 0x20, &tp->t_outq)) {
					(void) unputc(&tp->t_outq);
					break;
				}
			} else {
				if (putc(ch, &tp->t_outq))
					break;
			}
			len--;
		}
		MFREE(m, m2);
		m = m2;
	}
}

/*
 * Copy data buffer to mbuf chain. In this PPP version we do NOT prepend ifp.
 * Meticulously stolen from if_ubaget.
 */
struct mbuf *
pppasync_btom(buf, totlen)
	caddr_t buf;
	register int totlen;
{
	struct mbuf *top, **mp;
	register struct mbuf *m;
	int len;
	register caddr_t cp = buf, pp;

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
		m->m_len = MIN(MLEN, len);
copy:
		bcopy(cp, mtod(m, caddr_t), (unsigned)m->m_len);
		cp += m->m_len;
nocopy:
		*mp = m;
		mp = &m->m_next;
		totlen -= m->m_len;
	}
out:
	return (top);
}

/*
 * tty interface receiver interrupt.
 */
pppasync_input(c, tp)
	register int c;
	register struct tty *tp;
{
	register struct ppp_softc *pp;
	register struct mbuf *m;
	int s;

	tk_nin++;
	pp = (struct ppp_softc *) tp->t_pp;
	if (pp == NULL)
		return;

	c &= 0xFF;

	if (c == PPP_OCTFRM_FLAG) {
		if (pp->pp_asstate == PPPASYNC_RXSTATE_ADDR)	/* null frame */
			return;
		if (pp->pp_asstate != PPPASYNC_RXSTATE_DATA ||
		    pp->pp_ascnt < 3 || pp->pp_asfcs != CCITT_FCS16_GOOD) {
			pp->pp_asstate = PPPASYNC_RXSTATE_ADDR;
			pp->pp_asfcs = CCITT_FCS16_INIT;
			pp->pp_if.if_ierrors++;
			return;
		}
		m = pppasync_btom(pp->pp_asbuf, pp->pp_ascnt - 2);
		pp->pp_asstate = PPPASYNC_RXSTATE_ADDR;
		pp->pp_asfcs = CCITT_FCS16_INIT;
		if (m == NULL) {
			pp->pp_if.if_ierrors++;
			return;
		}
		pp->pp_if.if_ipackets++;
		pppinput(pp, m, pp->pp_asproto);
		return;
	}

	if (pp->pp_asstate & PPPASYNC_RXSTATE_ESCAPE) {
		pp->pp_asstate &= ~PPPASYNC_RXSTATE_ESCAPE;
		c ^= 0x20;
	} else if (c == PPP_OCTFRM_ESCAPE) {
		pp->pp_asstate |= PPPASYNC_RXSTATE_ESCAPE;
		return;
	}
	pp->pp_asfcs = (pp->pp_asfcs >> 8) ^
				ccitt_fcs16tab[(pp->pp_asfcs ^ c) & 0xFF];

	switch (pp->pp_asstate) {
	case PPPASYNC_RXSTATE_ADDR:
		if (c == PPP_FRAME_ADDR) {
			pp->pp_asstate = PPPASYNC_RXSTATE_CTRL;
			return;
		}
		/* FALL THRU */
	case PPPASYNC_RXSTATE_PROTOHI:
		if (c & 1)
			pp->pp_asproto = 0;
		else {
			pp->pp_asproto = c << 8;
			pp->pp_asstate = PPPASYNC_RXSTATE_PROTOLO;
			return;
		}
		/* FALL THRU */
	case PPPASYNC_RXSTATE_PROTOLO:
		pp->pp_asproto |= c;
		pp->pp_asstate = PPPASYNC_RXSTATE_DATA;
		pp->pp_asptr = pp->pp_asbuf;
		pp->pp_ascnt = 0;
		return;
	case PPPASYNC_RXSTATE_DATA:
		if (pp->pp_ascnt >= PPPASYNC_RBUF) {
			pp->pp_asstate = PPPASYNC_RXSTATE_DROP;
			return;
		}
		*pp->pp_asptr++ = c;
		pp->pp_ascnt++;
		return;
	case PPPASYNC_RXSTATE_CTRL:
		if (c == PPP_FRAME_CONTROL)
			pp->pp_asstate = PPPASYNC_RXSTATE_PROTOHI;
		else
			pp->pp_asstate = PPPASYNC_RXSTATE_DROP;
		return;
	}
}

/* Bring the physical layer up (assert DTR) */
pppasync_up(pp)
	register struct ppp_softc *pp;
{
	register struct tty *tp;

	tp = (struct tty *) pp->pp_hwhnd;
	(*cdevsw[major(tp->t_dev)].d_ioctl)(tp->t_dev, TIOCSDTR);
}

/* Bring the physical layer down (negate DTR) */
pppasync_down(pp)
	register struct ppp_softc *pp;
{
	register struct tty *tp;

	if (pppasync_dtr_hack) {
		pppasync_dtr_hack = 0;
		return;
	}
	tp = (struct tty *) pp->pp_hwhnd;
	(*cdevsw[major(tp->t_dev)].d_ioctl)(tp->t_dev, TIOCCDTR);
}

/* is the physical layer up? (check carrier) */
pppasync_check(pp)
	register struct ppp_softc *pp;
{
	register struct tty *tp;

	tp = (struct tty *) pp->pp_hwhnd;
	return(tp->t_state & TS_CARR_ON);
}

/*
 * Handle modem control transition on a tty.
 * Flag indicates new state of carrier.
 * Returns 0 if the line should be turned off, otherwise 1.
 *
 * Supposed to be called at spltty, but we just need splnet or above.
 */
pppasync_modem(tp, flag)
	register struct tty *tp;
	int flag;
{
	if (flag) {
		tp->t_state |= TS_CARR_ON;
		if (tp->t_pp)
			pppup(tp->t_pp);
	} else {
		tp->t_state &= ~TS_CARR_ON;
		pppasync_dtr_hack = 1;
		if (tp->t_pp)
			pppdown(tp->t_pp);
		else
			pppasync_dtr_hack = 0;
		flag = pppasync_dtr_hack;
		pppasync_dtr_hack = 0;
	}
	return(flag);
}
#endif
