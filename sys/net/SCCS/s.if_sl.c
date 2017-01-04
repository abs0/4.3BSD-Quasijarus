h44878
s 00008/00003/00670
d D 7.15 02/08/05 00:31:58 msokolov 25 24
c switching to and from network disciplines is a very delicate matter
e
s 00007/00001/00666
d D 7.14 02/08/02 23:39:42 msokolov 24 23
c notify netmon on carrier transitions
e
s 00049/00009/00618
d D 7.13 02/07/21 14:01:43 msokolov 23 22
c implement modem control like in ppp
e
s 00018/00001/00609
d D 7.12 02/07/12 19:54:55 msokolov 22 21
c Option to append CCITT FCS-16 to each IP datagram (disabled by default).
c With this non-standard extension SLIP becomes reliable for checksumless UDP,
c etc. and thus a viable alternative to the ugly PPP for asynchronous links.
e
s 00113/00064/00497
d D 7.11 02/07/08 00:12:06 msokolov 21 20
c Support configurable MTU. The receive buffer logic could only work with MTU of
c a little less than 1024, so I replaced it with a carbon copy of if_ubaget. Now
c it's a 2048 byte buffer that works like the UNIBUS ones and MTU can be anything
c from 576 to 2046, default 1500. While I was at it, made overflow handling right
c and fixed an outright bug in out-of-mbufs handling.
e
s 00034/00019/00527
d D 7.10 02/07/07 18:39:21 msokolov 20 19
c Redesign attachment logic. Now we don't just set SLIPDISC, one must explicitly
c attach an sl unit to the tty with TIOCSLATTACH. Stop abusing TIOCGETD to get
c the interface number, we now have TIOCGETIF.
e
s 00010/00005/00536
d D 7.9 88/06/27 18:59:34 bostic 19 18
c install approved copyright notice
e
s 00001/00001/00540
d D 7.8 88/05/20 12:03:30 karels 18 17
c make the code agree with the comment
e
s 00004/00004/00537
d D 7.7 88/04/07 13:20:54 karels 17 15
c CLBYTES => MCLBYTES
e
s 00001/00001/00540
d D 7.6.1.1 88/03/15 12:28:34 karels 16 15
c branch for network release (dk.h for dkstat.h XXX)
e
s 00006/00017/00535
d D 7.6 88/03/15 12:27:52 karels 15 13
c from torek, don't let OACTIVE get out of sync with BUSY/outq.c_cc
e
s 00006/00018/00534
d R 7.6 88/03/15 12:25:55 karels 14 13
c from torek
e
s 00013/00001/00539
d D 7.5 87/12/30 11:57:30 bostic 13 12
c add Berkeley header
e
s 00001/00003/00539
d D 7.4 87/08/13 13:36:39 bostic 12 11
c include mtpr.h for tahoe too
e
s 00001/00001/00541
d D 7.3 87/05/08 11:12:05 sam 11 10
c dk.h -> dkstat.h (from rusty@weyl.berkeley.edu)
e
s 00003/00000/00539
d D 7.2 86/09/04 11:35:31 karels 10 9
c MCLALLOC must be called at splimp
e
s 00000/00000/00539
d D 7.1 86/06/04 23:40:20 mckusick 9 8
c 4.3BSD release version
e
s 00001/00001/00538
d D 5.8 86/06/03 09:42:38 karels 8 7
c use the right include
e
s 00001/00001/00538
d D 5.7 86/05/15 09:27:52 karels 7 6
c I prefer this fix...
e
s 00002/00002/00537
d D 5.6 86/05/14 20:16:56 mckusick 6 5
c serial line crashes on big packets or heavy traffic (from Keith Muller)
e
s 00002/00000/00537
d D 5.5 86/05/03 08:49:46 mckusick 5 4
c make forward progress for large packets (from Keith Muller)
e
s 00004/00000/00533
d D 5.4 86/03/17 12:26:07 karels 4 3
c drop and return error if no carrier
e
s 00182/00112/00351
d D 5.3 86/02/23 23:22:46 karels 3 2
c lint
e
s 00004/00001/00459
d D 5.2 86/02/09 19:27:25 karels 2 1
c Berkelify
e
s 00460/00000/00000
d D 5.1 86/02/09 17:14:19 karels 1 0
c from Chris Torek, from Rick Adams
e
u
U
f b 
t
T
I 2
D 13
/*	%W% (Berkeley) %G% */
E 13
I 13
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
 *
 *	%W% (Berkeley) %G%
 */
E 13

E 2
I 1
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
D 3
 * Some things done here could obviously be done in a better way,
 * but they were done this way to minimize the number of files
 * that had to be changed to accomodate this device.
D 2
 * A lot of this code belongs in the tty driver.
E 2
 *
E 3
 * Pounded on heavily by Chris Torek (chris@mimsy.umd.edu, umcp-cs!chris).
D 3
 * N.B.: this belongs in netinet, not vaxif, the way it stands now.
E 3
I 3
 * N.B.: this belongs in netinet, not net, the way it stands now.
E 3
I 2
 * Should have a link-layer type designation, but wouldn't be
 * backwards-compatible.
E 2
 *
 * Converted to 4.3BSD Beta by Chris Torek.
I 3
 * Other changes made at Berkeley, based in part on code by Kirk Smith.
E 3
 */

/* $Header: if_sl.c,v 1.12 85/12/20 21:54:55 chris Exp $ */
/* from if_sl.c,v 1.11 84/10/04 12:54:47 rick Exp */

#include "sl.h"
#if NSL > 0

#include "param.h"
I 23
#include "conf.h"
E 23
#include "mbuf.h"
#include "buf.h"
I 3
D 11
#include "dk.h"
E 11
I 11
D 16
#include "dkstat.h"
E 16
I 16
#include "dk.h"
E 16
E 11
E 3
#include "socket.h"
#include "ioctl.h"
I 3
#include "file.h"
E 3
#include "tty.h"
#include "errno.h"
I 21
#include "malloc.h"
E 21

D 3
#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
E 3
I 3
#include "if.h"
#include "netisr.h"
#include "route.h"
I 22
#include "if_fcs16.h"
E 22
#if INET
E 3
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 8
#include "../netinet/in_var.h"
E 8
#include "../netinet/ip.h"
D 8
#include "../netinet/ip_var.h"
E 8
I 3
#endif
E 3

I 21
#include "../machine/pte.h"
E 21
D 12
#ifdef vax
#include "../vax/mtpr.h"
#endif vax
E 12
I 12
#include "../machine/mtpr.h"
E 12

I 24
#include "netmon.h"

E 24
D 21
/*
D 3
 * N.B.: SLMTU is now a hard limit on input packet size.  Some limit
 * is required, lest we use up all mbufs in the case of deleterious data
 * dribbling down the line.
E 3
I 3
 * N.B.: SLMTU is now a hard limit on input packet size.
D 17
 * SLMTU must be <= CLBYTES - sizeof(struct ifnet *).
E 17
I 17
 * SLMTU must be <= MCLBYTES - sizeof(struct ifnet *).
E 17
E 3
 */
#define	SLMTU	1006
E 21
I 21
#define	SLRBUF		2048	/* receive buffer where we accumulate bytes */
#define	SLMRU		(SLRBUF-2)	/* maximum receive unit */
#define	SLMAXMTU	SLMRU	/* largest MTU settable with SIOCSIFMTU */
#define	SLDEFMTU	1500	/* de facto Internet standard */
E 21
I 3
#define	SLIP_HIWAT	1000	/* don't start a new packet if HIWAT on queue */
#define	CLISTRESERVE	1000	/* Can't let clists get too low */
E 3

struct sl_softc {
	struct	ifnet sc_if;	/* network-visible interface */
	short	sc_flags;	/* see below */
	short	sc_ilen;	/* length of input-packet-so-far */
	struct	tty *sc_ttyp;	/* pointer to tty structure */
	char	*sc_mp;		/* pointer to next available buf char */
D 3
	char	sc_buf[SLMTU];	/* input buffer */
E 3
I 3
	char	*sc_buf;	/* input buffer */
E 3
} sl_softc[NSL];

/* flags */
#define	SC_ESCAPED	0x0001	/* saw a FRAME_ESCAPE */
I 21
#define	SC_OVFLO	0x0002	/* receive buffer overflow */
E 21
D 15
#define	SC_OACTIVE	0x0002	/* output tty is active */
E 15

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
D 21
		sc->sc_if.if_mtu = SLMTU;
E 21
I 21
		sc->sc_if.if_mtu = SLDEFMTU;
E 21
D 22
		sc->sc_if.if_flags = IFF_POINTOPOINT;
E 22
I 22
		sc->sc_if.if_flags = IFF_POINTOPOINT | IFF_NOFCS;
E 22
		sc->sc_if.if_ioctl = slioctl;
		sc->sc_if.if_output = sloutput;
		sc->sc_if.if_snd.ifq_maxlen = IFQ_MAXLEN;
		if_attach(&sc->sc_if);
	}
}

/*
 * Line specific open routine.
D 20
 * Attach the given tty to the first available sl unit.
E 20
I 20
 * The SLIP line discipline cannot be opened this way.
E 20
 */
I 3
/* ARGSUSED */
E 3
slopen(dev, tp)
	dev_t dev;
	register struct tty *tp;
{
D 20
	register struct sl_softc *sc;
E 20
I 20
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
E 20
	register int nsl;
I 20
{
	register struct sl_softc *sc;
I 25
	int s;
E 25
E 20

D 3
	if (tp->t_sc != NULL)
E 3
I 3
	if (!suser())
		return (EPERM);
D 20
	if (tp->t_line == SLIPDISC)
E 20
I 20
	if (nsl >= NSL)
		return (ENXIO);
	sc = &sl_softc[nsl];
	if (tp->t_line == SLIPDISC && tp->t_sc &&
	    (struct sl_softc*) tp->t_sc != sc)
E 20
E 3
		return (EBUSY);
D 20

	for (nsl = 0, sc = sl_softc; nsl < NSL; nsl++, sc++)
		if (sc->sc_ttyp == NULL) {
			sc->sc_flags = 0;
			sc->sc_ilen = 0;
D 3
			sc->sc_mp = sc->sc_buf;
E 3
I 3
			if (slinit(sc) == 0)
				return (ENOBUFS);
E 3
			tp->t_sc = (caddr_t)sc;
			sc->sc_ttyp = tp;
I 3
			ttyflush(tp, FREAD | FWRITE);
E 3
			return (0);
		}

D 3
	return (ENOSPC);
E 3
I 3
	return (ENXIO);
E 20
I 20
	if (sc->sc_ttyp && sc->sc_ttyp != tp)
		return (EBUSY);
	sc->sc_flags = 0;
	sc->sc_ilen = 0;
	if (slinit(sc) == 0)
		return (ENOBUFS);
D 23
	tp->t_line = SLIPDISC;
E 23
D 25
	tp->t_sc = (caddr_t)sc;
E 25
	sc->sc_ttyp = tp;
I 25

	s = spltty();
E 25
	ttyflush(tp, FREAD | FWRITE);
I 23
	tp->t_line = SLIPDISC;
I 25
	tp->t_sc = (caddr_t)sc;
	splx(s);

E 25
E 23
	return (0);
E 20
E 3
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

D 25
	ttywflush(tp);
	tp->t_line = 0;
E 25
	s = splimp();		/* paranoid; splnet probably ok */
	sc = (struct sl_softc *)tp->t_sc;
	if (sc != NULL) {
		if_down(&sc->sc_if);
		sc->sc_ttyp = NULL;
		tp->t_sc = NULL;
I 3
D 21
		MCLFREE((struct mbuf *)sc->sc_buf);
E 21
I 21
		free(sc->sc_buf, M_DEVBUF);
E 21
		sc->sc_buf = 0;
E 3
	}
	splx(s);
I 25
	tp->t_line = 0;
	ttywflush(tp);
E 25
}

/*
 * Line specific (tty) ioctl routine.
 * Provide a way to get the sl unit number.
 */
I 3
/* ARGSUSED */
E 3
sltioctl(tp, cmd, data, flag)
	struct tty *tp;
	caddr_t data;
{
D 20

	if (cmd == TIOCGETD) {
E 20
I 20
	if (cmd == TIOCGETIF) {
E 20
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
D 23
	if (sc->sc_ttyp == NULL) {
E 23
I 23
	if (!(ifp->if_flags & IFF_UP) || sc->sc_ttyp == NULL ||
	    !(sc->sc_ttyp->t_state & TS_CARR_ON)) {
E 23
		m_freem(m);
D 23
		return (ENETDOWN);	/* sort of */
E 23
I 23
		return (ENETDOWN);
E 23
	}
I 4
D 23
	if ((sc->sc_ttyp->t_state & TS_CARR_ON) == 0) {
		m_freem(m);
		return (EHOSTUNREACH);
	}
E 23
I 22

	if (!(ifp->if_flags & IFF_NOFCS) && ccitt_addfcs16(m)) {
		m_freem(m);
		return (ENOBUFS);
	}

E 22
E 4
	s = splimp();
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
		splx(s);
		m_freem(m);
D 3
		sc->sc_if.if_collisions++;
E 3
I 3
		sc->sc_if.if_oerrors++;
E 3
		return (ENOBUFS);
	}
	IF_ENQUEUE(&ifp->if_snd, m);
D 15
	if ((sc->sc_flags & SC_OACTIVE) == 0) {
E 15
I 15
	if (sc->sc_ttyp->t_outq.c_cc == 0) {
E 15
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
D 3
	register int c, len;
	register u_char *mcp;
	int flush;
E 3
I 3
	register int len;
	register u_char *cp;
D 15
	int flush, nd, np, n, s;
E 15
I 15
	int nd, np, n, s;
E 15
	struct mbuf *m2;
	extern int cfreecount;
E 3

D 3
	/*
	 * If there is more in the output queue, just send it now.
	 * We are being called in lieu of ttstart and must do what
	 * it would.
	 */
	if (tp->t_outq.c_cc > 0) {
		ttstart(tp);
		return;
	}
E 3
I 3
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
E 3

D 3
	/*
	 * This happens briefly when the line shuts down.
	 */
	if (sc == NULL)
		return;
E 3
I 3
		/*
		 * This happens briefly when the line shuts down.
		 */
		if (sc == NULL)
			return;
E 3

D 3
	/*
	 * Get a packet and map it to the interface.
	 */
	c = splimp();
	IF_DEQUEUE(&sc->sc_if.if_snd, m);
	if (m == NULL) {
		sc->sc_flags &= ~SC_OACTIVE;
		splx(c);
		return;
	}
	flush = !(sc->sc_flags & SC_OACTIVE);
	sc->sc_flags |= SC_OACTIVE;
	splx(c);
E 3
I 3
		/*
		 * If system is getting low on clists
		 * and we have something running already, stop here.
		 */
D 15
		if (cfreecount < CLISTRESERVE + SLMTU &&
		    sc->sc_flags & SC_OACTIVE)
E 15
I 15
D 18
		if (cfreecount < CLISTRESERVE + SLMTU && tp->t_outq.c_cc == 0)
E 18
I 18
D 21
		if (cfreecount < CLISTRESERVE + SLMTU && tp->t_outq.c_cc)
E 21
I 21
		if (cfreecount < CLISTRESERVE + sc->sc_if.if_mtu &&
		    tp->t_outq.c_cc)
E 21
E 18
E 15
			return;
E 3

D 3
	/*
	 * The extra FRAME_END will start up a new packet, and thus
	 * will flush any accumulated garbage.  We do this whenever
	 * the line may have been idle for some time.
	 */
	if (flush)
		(void) putc(FRAME_END, &tp->t_outq);
E 3
I 3
		/*
		 * Get a packet and send it to the interface.
		 */
		s = splimp();
		IF_DEQUEUE(&sc->sc_if.if_snd, m);
D 15
		if (m == NULL) {
			if (tp->t_outq.c_cc == 0)
				sc->sc_flags &= ~SC_OACTIVE;
			splx(s);
			return;
		}
		flush = !(sc->sc_flags & SC_OACTIVE);
		sc->sc_flags |= SC_OACTIVE;
E 15
		splx(s);
I 15
		if (m == NULL)
			return;
E 15
E 3

D 3
	while (m != NULL) {
		len = m->m_len;
		mcp = mtod(m, u_char *);
		while (--len >= 0) {
			c = *mcp++;
			if (c == FRAME_ESCAPE || c == FRAME_END) {
				if (putc(FRAME_ESCAPE, &tp->t_outq))
					goto full;
				c = c == FRAME_ESCAPE ? TRANS_FRAME_ESCAPE :
							TRANS_FRAME_END;
				if (putc(c, &tp->t_outq)) {
					(void) unputc(&tp->t_outq);
					goto full;
E 3
I 3
		/*
		 * The extra FRAME_END will start up a new packet, and thus
		 * will flush any accumulated garbage.  We do this whenever
		 * the line may have been idle for some time.
		 */
D 15
		if (flush)
E 15
I 15
		if (tp->t_outq.c_cc == 0)
E 15
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
I 5
					len -= n;
					cp += n;
E 5
E 3
				}
D 3
			} else
				if (putc(c, &tp->t_outq))
					goto full;
E 3
I 3
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
E 3
		}
D 3
		m = m_free(m);
E 3
I 3

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
E 3
	}
I 3
}
E 3

D 3
	if (putc(FRAME_END, &tp->t_outq)) {
full:
		/*
		 * If you get many oerrors (more than one or two a day)
		 * you probably do not have enough clists and you should 
		 * increase "nclist" in param.c.
		 */
		(void) unputc(&tp->t_outq);	/* make room */
		putc(FRAME_END, &tp->t_outq);	/* end the packet */
		sc->sc_if.if_oerrors++;
	} else
		sc->sc_if.if_opackets++;
E 3
I 3
slinit(sc)
	register struct sl_softc *sc;
{
D 21
	struct mbuf *p;
E 21
I 21
	caddr_t p;
E 21
E 3

D 3
	/*
	 * Start transmission.  Note that slstart, not ttstart, will be
	 * called when the transmission completes, be that after a single
	 * piece of what we have mapped, or be it after the entire thing
	 * has been sent.  That is why we need to check the output queue
	 * count at the top.
	 */
	ttstart(tp);
E 3
I 3
	if (sc->sc_buf == (char *) 0) {
I 10
D 15
		int s = splimp();

E 15
E 10
D 21
		MCLALLOC(p, 1);
I 10
D 15
		splx(s);
E 15
E 10
		if (p) {
			sc->sc_buf = (char *)p;
			sc->sc_mp = sc->sc_buf + sizeof(struct ifnet *);
		} else {
E 21
I 21
		p = (caddr_t) malloc(SLRBUF, M_DEVBUF, M_NOWAIT);
		if (p)
			sc->sc_buf = sc->sc_mp = p;
		else {
E 21
			printf("sl%d: can't allocate buffer\n", sc - sl_softc);
			sc->sc_if.if_flags &= ~IFF_UP;
			return (0);
		}
	}
	return (1);
E 3
}

/*
 * Copy data buffer to mbuf chain; add ifnet pointer ifp.
I 21
 * Meticulously stolen from if_ubaget.
E 21
 */
struct mbuf *
D 3
sl_btom(addr, len, ifp)
	register caddr_t addr;
E 3
I 3
D 21
sl_btom(sc, len, ifp)
E 21
I 21
sl_btom(sc, totlen, ifp)
E 21
	struct sl_softc *sc;
E 3
D 21
	register int len;
E 21
I 21
	register int totlen;
E 21
	struct ifnet *ifp;
{
I 3
D 21
	register caddr_t cp;
E 3
	register struct mbuf *m, **mp;
D 3
	register int count;
E 3
I 3
	register unsigned count;
E 3
	struct mbuf *top = NULL;
E 21
I 21
	struct mbuf *top, **mp;
	register struct mbuf *m;
	int len;
	register caddr_t cp = sc->sc_buf, pp;
E 21

I 3
D 21
	cp = sc->sc_buf + sizeof(struct ifnet *);
E 21
I 21
	top = 0;
E 21
E 3
	mp = &top;
D 21
	while (len > 0) {
E 21
I 21
	while (totlen > 0) {
E 21
		MGET(m, M_DONTWAIT, MT_DATA);
D 21
		if ((*mp = m) == NULL) {
E 21
I 21
		if (m == 0) {
E 21
			m_freem(top);
D 21
			return (NULL);
E 21
I 21
			top = 0;
			goto out;
E 21
		}
D 3
		if (ifp) {
E 3
I 3
D 21
		if (ifp)
E 3
			m->m_off += sizeof(ifp);
D 3
			count = MIN(len, MLEN - sizeof(ifp));
		} else {
			if (len >= NBPG) {
				struct mbuf *p;

				MCLGET(p, 1);
				if (p != NULL) {
					count = MIN(len, CLBYTES);
					m->m_off = (int)p - (int)m;
E 3
I 3
		/*
		 * If we have at least NBPG bytes,
		 * allocate a new page.  Swap the current buffer page
		 * with the new one.  We depend on having a space
		 * left at the beginning of the buffer
		 * for the interface pointer.
		 */
		if (len >= NBPG) {
E 21
I 21
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
E 21
			MCLGET(m);
D 17
			if (m->m_len == CLBYTES) {
E 17
I 17
D 21
			if (m->m_len == MCLBYTES) {
E 17
				cp = mtod(m, char *);
				m->m_off = (int)sc->sc_buf - (int)m;
D 6
				sc->sc_buf = mtod(m, char *);
E 6
I 6
				sc->sc_buf = cp;
E 6
				if (ifp) {
					m->m_off += sizeof(ifp);
					count = MIN(len,
D 17
					    CLBYTES - sizeof(struct ifnet *));
E 17
I 17
					    MCLBYTES - sizeof(struct ifnet *));
E 17
E 3
				} else
D 3
					count = MIN(len, MLEN);
			} else
				count = MIN(len, MLEN);
E 3
I 3
D 17
					count = MIN(len, CLBYTES);
E 17
I 17
					count = MIN(len, MCLBYTES);
E 17
				goto nocopy;
E 21
I 21
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
E 21
			}
I 21
			goto nocopy;
E 21
E 3
		}
D 3
		bcopy(addr, mtod(m, caddr_t), count);
E 3
I 3
D 21
		if (ifp)
			count = MIN(len, MLEN - sizeof(ifp));
		else
			count = MIN(len, MLEN);
		bcopy(cp, mtod(m, caddr_t), count);
E 21
I 21
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
E 21
nocopy:
E 3
D 21
		m->m_len = count;
E 21
I 21
		*mp = m;
		mp = &m->m_next;
		totlen -= m->m_len;
E 21
		if (ifp) {
D 21
			m->m_off -= sizeof(ifp);
E 21
I 21
			/*
			 * Prepend interface pointer to first mbuf.
			 */
E 21
			m->m_len += sizeof(ifp);
D 21
			*mtod(m, struct ifnet **) = ifp;
			ifp = NULL;
E 21
I 21
			m->m_off -= sizeof(ifp);
			*(mtod(m, struct ifnet **)) = ifp;
			ifp = (struct ifnet *)0;
E 21
		}
D 3
		addr += count;
E 3
I 3
D 21
		cp += count;
E 3
		len -= count;
		mp = &m->m_next;
E 21
	}
I 21
out:
E 21
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

I 3
	tk_nin++;
E 3
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
D 3
			sc->sc_mp = sc->sc_buf;
E 3
I 3
D 21
			sc->sc_mp = sc->sc_buf + sizeof(struct ifnet *);
E 21
I 21
			sc->sc_mp = sc->sc_buf;
E 21
E 3
			sc->sc_ilen = 0;
			return;
		}
	} else {
		switch (c) {

		case FRAME_END:
			if (sc->sc_ilen == 0)	/* ignore */
				return;
I 21
			if (sc->sc_flags & SC_OVFLO) {
				sc->sc_flags &= ~SC_OVFLO;
				sc->sc_if.if_ierrors++;
				sc->sc_mp = sc->sc_buf;
				sc->sc_ilen = 0;
				return;
I 22
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
E 22
			}
E 21
D 3
			m = sl_btom(sc->sc_buf, sc->sc_ilen, &sc->sc_if);
E 3
I 3
			m = sl_btom(sc, sc->sc_ilen, &sc->sc_if);
I 21
			sc->sc_mp = sc->sc_buf;
			sc->sc_ilen = 0;
E 21
E 3
			if (m == NULL) {
				sc->sc_if.if_ierrors++;
				return;
			}
D 3
			sc->sc_mp = sc->sc_buf;
E 3
I 3
D 21
			sc->sc_mp = sc->sc_buf + sizeof(struct ifnet *);
E 3
			sc->sc_ilen = 0;
E 21
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
D 6
	if (++sc->sc_ilen >= SLMTU) {
E 6
I 6
D 7
	if (sc->sc_ilen++ >= SLMTU) {
E 7
I 7
D 21
	if (++sc->sc_ilen > SLMTU) {
E 7
E 6
		sc->sc_if.if_ierrors++;
D 3
		sc->sc_mp = sc->sc_buf;
E 3
I 3
		sc->sc_mp = sc->sc_buf + sizeof(struct ifnet *);
E 3
		sc->sc_ilen = 0;
E 21
I 21
	if (sc->sc_ilen >= SLRBUF) {
		sc->sc_flags |= SC_OVFLO;
E 21
		return;
	}
	*sc->sc_mp++ = c;
I 21
	sc->sc_ilen++;
E 21
}

/*
I 23
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
D 24
		if (sc)
E 24
I 24
		if (sc) {
E 24
			sc->sc_if.if_flags |= IFF_UP;
I 24
#if NNETMON > 0
			netmon_ifevent(&sc->sc_if);
#endif
		}
E 24
	} else {
		tp->t_state &= ~TS_CARR_ON;
		if (sc)
			if_down((struct ifnet *) sc);
	}
	return(flag);
}

/*
E 23
 * Process an ioctl request.
 */
slioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
	register struct ifaddr *ifa = (struct ifaddr *)data;
I 21
	struct ifreq *ifr;
I 23
	register struct tty *tp;
E 23
E 21
	int s = splimp(), error = 0;

	switch (cmd) {

	case SIOCSIFADDR:
D 23
		if (ifa->ifa_addr.sa_family == AF_INET)
E 23
I 23
		if (ifa->ifa_addr.sa_family == AF_INET) {
E 23
			ifp->if_flags |= IFF_UP;
D 23
		else
E 23
I 23
			if (tp = ((struct sl_softc *) ifp)->sc_ttyp)
				(*cdevsw[major(tp->t_dev)].d_ioctl)
					(tp->t_dev, TIOCSDTR);
		} else
E 23
			error = EAFNOSUPPORT;
		break;

	case SIOCSIFDSTADDR:
		if (ifa->ifa_addr.sa_family != AF_INET)
			error = EAFNOSUPPORT;
I 23
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
E 23
I 21
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
E 21
		break;

	default:
		error = EINVAL;
	}
	splx(s);
	return (error);
}
#endif
E 1
