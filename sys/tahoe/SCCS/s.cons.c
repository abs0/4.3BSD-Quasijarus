h49006
s 00013/00007/00464
d D 7.1 88/05/21 18:35:03 karels 11 10
c bring up to revision 7 for tahoe release
e
s 00004/00007/00467
d D 1.10 87/05/27 16:59:27 karels 10 9
c simplify for us
e
s 00008/00003/00466
d D 1.9 87/04/16 17:50:53 karels 9 8
c check console window for open, carrier before redirecting;
c redirect writes instead of reads!
e
s 00012/00008/00457
d D 1.8 87/03/04 20:06:35 karels 8 7
c resolve name conflict
e
s 00137/00116/00328
d D 1.7 87/02/21 11:14:45 karels 7 6
c cleanups; don't waste the machine trying to start a wedged console
e
s 00008/00007/00436
d D 1.6 86/12/23 20:51:25 sam 6 5
c CPMDCB takes physical address; had been working because CP only 
c uses 24-bits (or maybe 30) and physical == virtual when address is in data 
c segment (as command buffers are)
e
s 00039/00049/00404
d D 1.5 86/12/06 22:34:34 sam 5 4
c set interval timer value at boot time according to hz
e
s 00096/00022/00357
d D 1.4 86/11/25 16:42:17 sam 4 3
c kdb additions 
e
s 00001/00000/00378
d D 1.3 86/11/03 12:05:42 karels 3 2
c move key stats, etc. to cpu.h
e
s 00156/00156/00222
d D 1.2 86/01/05 18:42:21 sam 2 1
c 1st working version
e
s 00378/00000/00000
d D 1.1 85/07/21 20:20:51 sam 1 0
c date and time created 85/07/21 20:20:51 by sam
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11
D 4
/*	Minor device 0 is the CP itself.
/*	  No real read/writes can be done to him.
/*	Minor 1 is the console terminal.
/*	Minor 2 is the remote line trminal.
/**/
E 4

/*
 * Tahoe console processor driver
 *
I 4
 * Minor device 0 is the CP itself.
 *	  No real read/writes can be done to him.
 * Minor 1 is the console terminal.
 * Minor 2 is the remote line trminal.
E 4
 */
D 2
#include "../h/param.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/ioctl.h"
#include "../h/user.h"
#include "../h/tty.h"
#include "../h/uio.h"
#include "../h/callout.h"
#include "../h/systm.h"
#include "../machine/cp.h"
#include "../machine/mtpr.h"
E 2
I 2
#include "param.h"
#include "conf.h"
#include "dir.h"
#include "ioctl.h"
#include "user.h"
#include "proc.h"
#include "tty.h"
#include "uio.h"
#include "callout.h"
#include "systm.h"
I 7
#include "kernel.h"
#include "syslog.h"
E 7
E 2

D 2
#define FALSE 0
#define TRUE  1
E 2
I 2
D 11
#include "../tahoe/cp.h"
I 3
#include "../tahoe/cpu.h"
E 3
#include "../tahoe/mtpr.h"
E 11
I 11
#include "cp.h"
#include "cpu.h"
#include "mtpr.h"
E 11
E 2

D 2
int	cnrestart() ;
int	timeout() ;
E 2
I 2
int	cnrestart();
int	timeout();
E 2

D 2
struct	tty cons[3];	/* One for each unit on CP */
struct	cons_info {
	char	last_one;	/* Last char sent - possibly repeat
				 * If zero, timeout has nothing to do
				 */
	int	active_timeout;	/* There is an active timeout for this line
				 * Set by 'cnputc' when a timeout is initiated.
				 * Reset by the routine  called at timeout.
			 	 */
	int	try_later;	/* If true, timeout has nothing to do.
				 * Set by 'cnputc' every time a char is sent.
				 * Reset by the timeout arrival. If next time
				 * the timeout comes it's zero, then it may
				 * have something to do.
				 */
	} cons_info[3];
E 2
I 2
D 7
struct	tty cons;
E 7
struct	tty CPtty;
I 7
struct	tty cons;
E 7
struct	tty RLtty;
D 8
struct	tty *constty[3] = { &CPtty, &cons, &RLtty };
E 8
I 8
struct	tty *cntty[3] = { &CPtty, &cons, &RLtty };
E 8
I 7

I 8
struct	tty *constty = 0;	/* virtual console */

E 8
E 7
struct	consoftc {
D 7
	char	cs_lastc;	/* last char sent */
	int	cs_flags;
E 7
I 7
	char	cs_flags;
E 7
#define	CSF_ACTIVE	0x1	/* timeout active */
D 7
#define	CSF_RETRY	0x2	/* try again at a later time */
I 4
#define	CSF_POLLING	0x4	/* polling for input */
E 7
I 7
#define	CSF_POLLING	0x2	/* polling for input */
	char	cs_lastc;	/* last char sent */
	int	cs_timo;	/* timeouts since interrupt */
	u_long	cs_wedgecnt;	/* times restarted */
E 7
E 4
} consoftc[3];
I 7

/*
 * We check the console periodically to make sure
 * that it hasn't wedged.  Unfortunately, if an XOFF
 * is typed on the console, that can't be distinguished
 * from more catastrophic failure.
 */
#define	CN_TIMERVAL	(hz)		/* frequency at which to check cons */
#define	CN_TIMO		(2*60)		/* intervals to allow for output char */

E 7
E 2
struct	cpdcb_o consout[3] = { 
D 2
			/* 	unit,		cmd,count, buf */
			{(char)(CPTAKE | CPDONE),0,   0 },
			{(char)(CPTAKE | CPDONE),0,   0 },
			{(char)(CPTAKE | CPDONE),0,   0 }
			};
E 2
I 2
D 5
	/* 	unit,		cmd,count, buf */
	{ (char)(CPTAKE | CPDONE),0,   0 },
	{ (char)(CPTAKE | CPDONE),0,   0 },
	{ (char)(CPTAKE | CPDONE),0,   0 }
E 5
I 5
	{ CPTAKE|CPDONE }, { CPTAKE|CPDONE }, { CPTAKE|CPDONE }
E 5
};
E 2
struct	cpdcb_i consin[3] = {
D 2
			/* 	unit,		cmd,count, buf */
			{(char)(CPTAKE | CPDONE),0,   0 },
			{(char)(CPTAKE | CPDONE),0,   0 },
			{(char)(CPTAKE | CPDONE),0,   0 }
			};
E 2
I 2
D 5
	/* 	unit,		cmd,count, buf */
	{ (char)(CPTAKE | CPDONE),0,   0 },
	{ (char)(CPTAKE | CPDONE),0,   0 },
	{ (char)(CPTAKE | CPDONE),0,   0 }
E 5
I 5
	{ CPTAKE|CPDONE }, { CPTAKE|CPDONE }, { CPTAKE|CPDONE }
E 5
};
E 2
D 5
struct	cphdr *lasthdr;
E 5
I 5
struct	cphdr *cnlast;
E 5

int	cnstart();
int	ttrstrt();
char	partab[];

I 7
/*
 * Wait for CP to accept last CP command sent
 * before setting up next command.
 */
#define	waitforlast(timo) { \
	if (cnlast) { \
		(timo) = 10000; \
		do \
			uncache((char *)&cnlast->cp_unit); \
		while ((cnlast->cp_unit&CPTAKE) == 0 && --(timo)); \
	} \
}

E 7
I 2
/*ARGSUSED*/
E 2
cnopen(dev, flag)
D 2
dev_t dev;
E 2
I 2
	dev_t dev;
E 2
{
D 4
	register struct cpdcb_i *cin;
E 4
	register struct tty *tp;
D 2
	register int timo;
E 2
I 2
	int unit = minor(dev);
E 2

D 2
	if (minor(dev) > CPREMOT) 
		return EEXIST;
	tp = &cons[minor(dev)];
E 2
I 2
	if (unit > CPREMOT) 
D 7
		return (EEXIST);
E 7
I 7
		return (ENXIO);
E 7
D 8
	tp = constty[unit];
E 8
I 8
	tp = cntty[unit];
E 8
E 2
	if (tp->t_state&TS_XCLUDE && u.u_uid != 0)
D 2
		return EBUSY;
E 2
I 2
		return (EBUSY);
I 4
	cnpostread(unit);		/* post request for input */
	tp->t_oproc = cnstart;
	tp->t_dev = dev;
	if ((tp->t_state&TS_ISOPEN) == 0) {
		ttychars(tp);
		tp->t_state = TS_ISOPEN|TS_CARR_ON;
		tp->t_flags = EVENP|ECHO|XTABS|CRMOD;
	}
	return ((*linesw[tp->t_line].l_open)(dev, tp));
}

cnpostread(unit)
	int unit;
{
	register struct cpdcb_i *cin;
I 7
	register int timo;
E 7

E 4
E 2
D 5
	if (lasthdr != (struct cphdr *)0) {
I 2
		register int timo;

E 2
		timo = 10000;
D 2
		uncache((char *)&lasthdr->cp_unit);
		while ((lasthdr->cp_unit & CPTAKE)==0 && --timo )
			uncache((char *)&lasthdr->cp_unit);
	}	/* Here we give up waiting */
	cin = &consin[minor(dev)];
	cin->cp_hdr.cp_unit = (char)(minor(dev));
	cin->cp_hdr.cp_comm = (char)CPREAD;
E 2
I 2
		uncache(&lasthdr->cp_unit);
		while ((lasthdr->cp_unit&CPTAKE) == 0 && --timo)
			uncache(&lasthdr->cp_unit);
E 5
I 5
D 7
	if (cnlast != (struct cphdr *)0) {
		register int timo = 10000;
		do
			uncache(&cnlast->cp_unit);
		while ((cnlast->cp_unit&CPTAKE) == 0 && --timo);
E 5
	}
E 7
I 7
	waitforlast(timo);
E 7
	cin = &consin[unit];
	cin->cp_hdr.cp_unit = unit;
	cin->cp_hdr.cp_comm = CPREAD;
E 2
	cin->cp_hdr.cp_count = 1;	/* Get ready for input */
D 2
	mtpr (cin, CPMDCB);
E 2
I 2
D 6
	mtpr(CPMDCB, cin);
E 6
I 6
	mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)cin));
E 6
E 2
D 5
	lasthdr = (struct cphdr *)cin;
E 5
I 5
D 7
	cnlast = (struct cphdr *)cin;
E 7
I 7
	cnlast = &cin->cp_hdr;
E 7
E 5
D 4
	tp->t_oproc = cnstart;
	tp->t_dev = dev;
	if ((tp->t_state&TS_ISOPEN) == 0) {
		ttychars(tp);
		tp->t_state = TS_ISOPEN|TS_CARR_ON;
		tp->t_flags = EVENP|ECHO|XTABS|CRMOD;
	}
D 2
	(*linesw[tp->t_line].l_open)(dev, tp);
E 2
I 2
	return ((*linesw[tp->t_line].l_open)(dev, tp));
E 4
E 2
}

cnclose(dev)
D 2
dev_t dev;
E 2
I 2
	dev_t dev;
E 2
{
D 2
	register struct tty *tp = &cons[minor(dev)];
E 2
I 2
D 8
	register struct tty *tp = constty[minor(dev)];
E 8
I 8
	register struct tty *tp = cntty[minor(dev)];
E 8
E 2

	(*linesw[tp->t_line].l_close)(tp);
	ttyclose(tp);
}

/*ARGSUSED*/
cnread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
D 2
	register struct tty *tp = &cons[minor(dev)];
E 2
I 2
D 8
	struct tty *tp = constty[minor(dev)];
E 8
I 8
	struct tty *tp = cntty[minor(dev)];
E 8
E 2

I 8
D 9
	if (constty && minor(dev) == CPCONS)
		tp = constty;
E 9
E 8
	return ((*linesw[tp->t_line].l_read)(tp, uio));
}

/*ARGSUSED*/
cnwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
D 2
	register struct tty *tp = &cons[minor(dev)];
E 2
I 2
D 8
	struct tty *tp = constty[minor(dev)];
E 8
I 8
D 9
	struct tty *tp = cntty[minor(dev)];
E 9
I 9
	register struct tty *tp = cntty[minor(dev)];
E 9
E 8
E 2

I 9
D 10
	if (tp == &cntty[CPCONS]) {
		if (constty && (constty->t_state & (TS_CARR_ON | TS_ISOPEN)) ==
		    (TS_CARR_ON | TS_ISOPEN))
			tp = constty;
		else if (consops)
			return ((*consops->d_write)(dev, uio));
	}
E 10
I 10
	if (tp == &cons && constty &&
	    (constty->t_state & (TS_CARR_ON | TS_ISOPEN)) ==
	    (TS_CARR_ON | TS_ISOPEN))
		tp = constty;
E 10
E 9
	return ((*linesw[tp->t_line].l_write)(tp, uio));
}

/*
 * Got a console receive interrupt -
 * the console processor wants to give us a character.
 * Catch the character, and see who it goes to.
 */
cnrint(dev)
D 2
dev_t dev;
E 2
I 2
	dev_t dev;
E 2
{
D 7
	register int c, timo;
E 7
I 7
	register int unit, timo;
E 7
	register struct tty *tp;
I 2
D 7
	int unit;
E 7
I 7
	int c;
E 7
E 2

D 2
	if (intenable == 0) return;
E 2
I 2
D 4
	if (intenable == 0)
		return;
E 4
	unit = minor(dev);
I 4
	if (!intenable || consoftc[unit].cs_flags&CSF_POLLING)
		return;
E 4
E 2
	/* make sure we dont take it from cache */
D 2
	uncache((char *)&consin[minor(dev)].cpi_buf[0]);
	c = consin[minor(dev)].cpi_buf[0];
E 2
I 2
	uncache(&consin[unit].cpi_buf[0]);
	c = consin[unit].cpi_buf[0];
E 2
D 4
/*
/* Wait about 5 milli for last CPMDCB to be read by CP,
/* otherwise give up
/**/
E 4
I 4
D 7
	/*
	 * Wait about 5 milli for last CPMDCB to be read by CP,
	 * otherwise give up
	 */
E 4
	timo = 10000;
D 2
	uncache((char *)&lasthdr->cp_unit);
	while ((lasthdr->cp_unit & CPTAKE)==0  && --timo  )
		uncache((char *)&lasthdr->cp_unit);
	uncache((char *)&lasthdr->cp_unit);
	if (lasthdr->cp_unit & CPTAKE)
	{
		consin[minor(dev)].cp_hdr.cp_unit = (char)(minor(dev));
E 2
I 2
D 5
	uncache(&lasthdr->cp_unit);
	while ((lasthdr->cp_unit&CPTAKE) == 0  && --timo)
		uncache(&lasthdr->cp_unit);
	uncache(&lasthdr->cp_unit);
	if (lasthdr->cp_unit&CPTAKE) {
E 5
I 5
	do
		uncache(&cnlast->cp_unit);
	while ((cnlast->cp_unit&CPTAKE) == 0  && --timo);
	if (cnlast->cp_unit&CPTAKE) {
I 6
		/* This resets status bits */
E 6
E 5
		consin[unit].cp_hdr.cp_unit = unit;
E 2
D 6
			/* This resets status bits */
D 2
		mtpr (&consin[minor(dev)], CPMDCB); /* Ready for new character */
		lasthdr = (struct cphdr *)&consin[minor(dev)];
		tp = &cons[minor(dev)];
E 2
I 2
		mtpr(CPMDCB, &consin[unit]); /* Ready for new character */
E 6
I 6
		/* Ready for new character */
		mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)&consin[unit]));
E 6
D 5
		lasthdr = (struct cphdr *)&consin[unit];
E 5
I 5
		cnlast = (struct cphdr *)&consin[unit];
E 5
		tp = constty[unit];
E 7
I 7
	waitforlast(timo);
	/* This resets status bits */
	consin[unit].cp_hdr.cp_unit = unit;
	/* Ready for new character */
	mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)&consin[unit]));
	cnlast = &consin[unit].cp_hdr;

D 8
	tp = constty[unit];
E 8
I 8
	tp = cntty[unit];
E 8
E 7
I 4
D 11
#ifdef KDB
E 11
I 11
#ifdef KADB
E 11
D 7
		if (unit == CPCONS && kdbrintr(c, tp))
			return;
E 7
I 7
	if (unit == CPCONS && kdbrintr(c, tp))
		return;
E 7
#endif
E 4
E 2
D 7
		(*linesw[tp->t_line].l_rint)(c, tp);
	}
E 7
I 7
	(*linesw[tp->t_line].l_rint)(c, tp);
E 7
}

cnioctl(dev, cmd, addr, flag)
D 2
dev_t dev;
caddr_t addr;
E 2
I 2
	dev_t dev;
	caddr_t addr;
E 2
{
D 2
	register struct tty *tp = &cons[minor(dev)];
E 2
I 2
D 8
	register struct tty *tp = constty[minor(dev)];
E 8
I 8
	register struct tty *tp = cntty[minor(dev)];
E 8
E 2
	register error;
 
	error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, addr);
	if (error >= 0)
		return error;
	if ((error = ttioctl(tp, cmd, addr, flag)) < 0)
		error = ENOTTY;
D 2
	else if(cmd==TIOCSETP || cmd==TIOCSETN)
E 2
I 2
	else if (cmd == TIOCSETP || cmd == TIOCSETN)
E 2
		cnparams(tp);
D 2
	return error;
E 2
I 2
	return (error);
E 2
}

int	consintr = 1;
/*
 * Got a console transmission interrupt -
 * the console processor wants another character.
 */
cnxint(dev)
D 2
dev_t dev;
E 2
I 2
	dev_t dev;
E 2
{
	register struct tty *tp;
D 2
	register int line_no;
E 2
I 2
	register int unit;
E 2

D 2
	if (intenable == 0 || consintr == 0) return;
#ifdef	CPPERF
	if (minor(dev)==CPCONS) scope_in(1);
	else scope_in(2);
E 2
I 2
D 4
	if (intenable == 0 || consintr == 0)
E 4
I 4
	if (!intenable || !consintr)
E 4
		return;
	unit = minor(dev);
#ifdef CPPERF
	scope_in(unit == CPCONS ? 1 : 2);
E 2
#endif
D 2
	line_no = minor(dev);
	tp = &cons[line_no];
E 2
I 2
D 8
	tp = constty[unit];
E 8
I 8
	tp = cntty[unit];
E 8
E 2
	tp->t_state &= ~TS_BUSY;
D 2
	cons_info[line_no].last_one = (char)0;
E 2
I 2
D 7
	consoftc[unit].cs_lastc = (char)0;
E 7
I 7
	consoftc[unit].cs_timo = 0;
E 7
E 2
	if (tp->t_line)
		(*linesw[tp->t_line].l_start)(tp);
	else
		cnstart(tp);
}

cnstart(tp)
D 2
register struct tty *tp;
E 2
I 2
	register struct tty *tp;
E 2
{
D 2
	register c;
	register s;
E 2
I 2
	register c, s;
E 2

#ifdef	CPPERF
D 2
	if (minor(tp->t_dev)==CPCONS) scope_in(3);
	else scope_in(4);
E 2
I 2
	scope_in(minor(tp->t_dev) == CPCONS ? 3 : 4);
E 2
#endif
	s = spl8();
	if (tp->t_state & (TS_TIMEOUT|TS_BUSY|TS_TTSTOP))
		goto out;
	if (tp->t_outq.c_cc <= TTLOWAT(tp)) {
		if (tp->t_state&TS_ASLEEP) {
			tp->t_state &= ~TS_ASLEEP;
			wakeup((caddr_t)&tp->t_outq);
		}
		if (tp->t_wsel) {
			selwakeup(tp->t_wsel, tp->t_state & TS_WCOLL);
			tp->t_wsel = 0;
			tp->t_state &= ~TS_WCOLL;
		}
	}
	if (tp->t_outq.c_cc == 0)
		goto out;
	c = getc(&tp->t_outq) & 0xff;
D 7
	if (tp->t_flags&(RAW|LITOUT))
D 2
		cnputc(c,tp);
	else if (c<=0177)
		cnputc ((c | (partab[c]&0200))&0xff,tp);
E 2
I 2
		cnputchar(c, tp);
	else if (c <= 0177)
		cnputchar((c | (partab[c]&0200))&0xff, tp);
E 2
	else {
		timeout(ttrstrt, (caddr_t)tp, (c&0177));
		tp->t_state |= TS_TIMEOUT;
		goto out;
E 7
I 7
	if ((tp->t_flags & (RAW|LITOUT)) == 0) {
		if (c <= 0177)
			c |= partab[c] & 0200;
		else {
			timeout(ttrstrt, (caddr_t)tp, (c&0177));
			tp->t_state |= TS_TIMEOUT;
			goto out;
		}
E 7
	}
I 7
	cnputchar(c, tp);
E 7
	tp->t_state |= TS_BUSY;
D 2
    out:
E 2
I 2
out:
E 2
	splx(s);
}

I 2
cnputc(c)
	char c;
{

	if (c == '\n')
		cnputchar('\r', (struct tty *)0);
	cnputchar(c, (struct tty *)0);
}

E 2
/*
 * Print a character on console.
 */
D 2
cnputc(c,tp)
register char c;
register struct tty *tp;
E 2
I 2
D 4
cnputchar(c,tp)
E 4
I 4
cnputchar(c, tp)
E 4
D 7
	register char c;
E 7
I 7
	char c;
E 7
	register struct tty *tp;
E 2
{
D 2
	register timo , line_no, s;
E 2
I 2
D 7
	register timo, unit;
E 7
I 7
	register timo;
E 7
E 2
	register struct cpdcb_o *current;
I 7
	register struct consoftc *cs;
	int unit;
E 7

	/* tp == 0 only in system error messages */
	if (tp == 0) {
D 7
		current = &consout[CPCONS];
D 2
		line_no = CPCONS;
		if(lasthdr == 0)	/* not done anythig yet */
E 2
I 2
		unit = CPCONS;
D 5
		if (lasthdr == 0)	/* not done anythig yet */
E 2
			lasthdr = (struct cphdr *)current;
E 5
I 5
		if (cnlast == 0)	/* not done anythig yet */
			cnlast = (struct cphdr *)current;
E 7
I 7
		tp = &cons;
		tp->t_dev = CPCONS;		/* may not be open */
E 7
E 5
		c |= partab[c&0177]&0200;
D 2
	}
	else {
E 2
I 2
D 7
	} else {
E 2
		current = &consout[minor(tp->t_dev)];
D 2
		line_no = minor(tp->t_dev);
E 2
I 2
		unit = minor(tp->t_dev);
E 7
E 2
	}
I 7
	unit = minor(tp->t_dev);
	current = &consout[unit];
E 7
	timo = 30000;
	/*
D 7
	 * Try waiting for the console tty to come ready,
	 * otherwise give up after a reasonable time.
E 7
I 7
	 * Try waiting for the console tty to finish previous command
	 * on this unit, otherwise give up after a reasonable time.
E 7
D 5
	 * make sure we dont test this bit in cache!
E 5
	 */
D 2
	uncache((char *)&current->cp_hdr.cp_unit);
	while ((current->cp_hdr.cp_unit & CPDONE) == 0 && --timo )
		uncache((char *)&current->cp_hdr.cp_unit);
	current->cp_hdr.cp_comm = (char)CPWRITE;
E 2
I 2
D 5
	uncache(&current->cp_hdr.cp_unit);
	while ((current->cp_hdr.cp_unit&CPDONE) == 0 && --timo)
E 5
I 5
	do
E 5
		uncache(&current->cp_hdr.cp_unit);
I 5
	while ((current->cp_hdr.cp_unit&CPDONE) == 0 && --timo);
I 7

E 7
E 5
	current->cp_hdr.cp_comm = CPWRITE;
E 2
	current->cp_hdr.cp_count = 1;
D 2
	current->cp_buf[0] = (char)(c & 0xff);
E 2
I 2
D 7
	current->cp_buf[0] = c & 0xff;
E 2
	timo = 10000;
E 7
I 7
	current->cp_buf[0] = c;
E 7
	/*
D 7
	 * Try waiting for the console tty to come ready,
	 * otherwise give up after a reasonable time.
E 7
I 7
	 * Try waiting for the console tty
	 * to accept previous command.
E 7
	 */
D 2
	uncache((char *)&lasthdr->cp_unit);
	while ((lasthdr->cp_unit & CPTAKE)==0 && --timo )
		uncache((char *)&lasthdr->cp_unit);
E 2
I 2
D 5
	uncache(&lasthdr->cp_unit);
	while ((lasthdr->cp_unit&CPTAKE) == 0 && --timo)
		uncache(&lasthdr->cp_unit);
E 5
I 5
D 7
	do
		uncache(&cnlast->cp_unit);
	while ((cnlast->cp_unit&CPTAKE) == 0 && --timo);
E 7
I 7
	waitforlast(timo);

E 7
E 5
E 2
	/* Reset done bit */
D 2
	current->cp_hdr.cp_unit = (char)line_no; 
E 2
I 2
	current->cp_hdr.cp_unit = (char)unit;
E 2
D 5
	lasthdr = (struct cphdr *)current;
E 5
I 5
D 7
	cnlast = (struct cphdr *)current;
E 7
E 5
#ifdef	CPPERF
D 2
	if (intenable != 0) scope_in(5);
E 2
I 2
	if (intenable != 0)
		scope_in(5);
E 2
#endif
D 2
	cons_info[line_no].last_one = c;
	if ( !cons_info[line_no].active_timeout && clk_enable) {
		cons_info[line_no].active_timeout = TRUE;
		timeout (cnrestart, (caddr_t)tp, 10);
E 2
I 2
D 7
	consoftc[unit].cs_lastc = c;
	if ((consoftc[unit].cs_flags&CSF_ACTIVE) == 0 && clk_enable) {
		consoftc[unit].cs_flags |= CSF_ACTIVE;
		timeout(cnrestart, (caddr_t)tp, 10);
E 7
I 7
	cs = &consoftc[unit];
	cs->cs_lastc = c;
	cs->cs_timo = CN_TIMO;
	if ((cs->cs_flags&CSF_ACTIVE) == 0 && clk_enable) {
		cs->cs_flags |= CSF_ACTIVE;
		timeout(cnrestart, (caddr_t)tp, CN_TIMERVAL);
E 7
E 2
	}
D 2
	cons_info[line_no].try_later = TRUE; /* For timeout-means wait some more */
	mtpr (current, CPMDCB);
E 2
I 2
D 7
	consoftc[unit].cs_flags |= CSF_RETRY;	/* wait some more */
E 7
D 6
	mtpr(CPMDCB, current);
E 6
I 6
	mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)current));
I 7
	cnlast = &current->cp_hdr;
E 7
E 6
E 2
}

I 4
D 11
#if defined(KDB) || defined(GENERIC)
E 11
I 11
#if defined(KADB) || defined(GENERIC)
E 11
cngetc()
{
	register int c, s;

	s = spl8();		/* block cnrint while we poll */
D 7
	c = cngetchar((struct tty *)0);
E 7
I 7
	c = cngetchar(&cons);
E 7
	if (c == '\r')
		c = '\n';
	splx(s);
	return (c);
}

cngetchar(tp)
	register struct tty *tp;
{
	register timo, unit;
	register struct cpdcb_i *current;
	char c;

D 7
	/* tp == 0 only in system error messages */
	if (tp == 0) {
		current = &consin[CPCONS];
		unit = CPCONS;
D 5
		if (lasthdr == 0)	/* not done anything yet */
			lasthdr = (struct cphdr *)current;
E 5
I 5
		if (cnlast == 0)	/* not done anything yet */
			cnlast = (struct cphdr *)current;
E 5
	} else {
		current = &consin[minor(tp->t_dev)];
		unit = minor(tp->t_dev);
	}
	timo = 10000;
D 5
	uncache((char *)&lasthdr->cp_unit);
	while ((lasthdr->cp_unit&CPTAKE) == 0 && --timo)
		uncache(&lasthdr->cp_unit);
E 5
I 5
	do
		uncache((char *)&cnlast->cp_unit);
	while ((cnlast->cp_unit&CPTAKE) == 0 && --timo);
E 7
I 7
	unit = minor(tp->t_dev);
	current = &consin[unit];
	waitforlast(timo);
E 7
E 5
	current->cp_hdr.cp_unit = unit;		/* Resets done bit */
	current->cp_hdr.cp_comm = CPREAD;
	current->cp_hdr.cp_count = 1;
D 6
	mtpr(CPMDCB, current);
E 6
I 6
	mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)current));
E 6
D 5
	while ((current->cp_hdr.cp_unit & CPDONE) == 0) 
E 5
I 5
	while ((current->cp_hdr.cp_unit&CPDONE) == 0) 
E 5
		uncache(&current->cp_hdr.cp_unit);
	uncache(&current->cpi_buf[0]);
	c = current->cpi_buf[0] & 0x7f;
D 5
	lasthdr = (struct cphdr *)current;
E 5
I 5
D 7
	cnlast = (struct cphdr *)current;
E 7
I 7
	cnlast = &current->cp_hdr;
E 7
E 5
	return (c);
}
#endif

E 4
/*
 * Restart (if necessary) transfer to CP line.
D 7
 * This way, lost 'transmit' interrupts don't break the chain.
E 7
I 7
 * This way, lost transmit interrupts don't wedge output.
E 7
 */
D 2
cnrestart (tp)
struct tty *tp;
E 2
I 2
cnrestart(tp)
	struct tty *tp;
E 2
{
D 2
	register line_no, s;
E 2
I 2
	register struct consoftc *cs;
E 2

D 2
	if (tp == 0) {
		line_no = CPCONS;
	} else
		line_no = minor(tp->t_dev);
	if (cons_info[line_no].try_later) {
		cons_info[line_no].try_later = FALSE;
		timeout (cnrestart, (caddr_t)tp, 10);
E 2
I 2
D 7
	cs = &consoftc[tp == 0 ? CPCONS : minor(tp->t_dev)];
	if (cs->cs_flags&CSF_RETRY) {
		cs->cs_flags &= ~CSF_RETRY;
		timeout(cnrestart, (caddr_t)tp, 10);
		return;
E 2
	}
E 7
I 7
	cs = &consoftc[minor(tp->t_dev)];
E 7
D 2
	else {
		cons_info[line_no].active_timeout = FALSE;
		if (cons_info[line_no].last_one != (char)0)
			cnputc (cons_info[line_no].last_one, tp);
	}
E 2
I 2
	cs->cs_flags &= ~CSF_ACTIVE;
D 7
	if (cs->cs_lastc != (char)0)
		cnputchar(cs->cs_lastc, tp);
E 7
I 7
	if (cs->cs_timo) {
		if (--cs->cs_timo == 0) {
			cs->cs_wedgecnt++;
			cnreset(tp);
			cnputchar(cs->cs_lastc, tp);
		} else {
			cs->cs_flags |= CSF_ACTIVE;
			timeout(cnrestart, (caddr_t)tp, CN_TIMERVAL);
		}
	}
E 7
E 2
}

/*
I 7
 * Reset console.
 */
cnreset(tp)
	register struct tty *tp;
{
	register timo;
	register struct cpdcb_o *current;
	register unit;
	static int failed;

	unit = minor(tp->t_dev);
	current = &consout[unit];
	current->cp_hdr.cp_comm = CPRESET;
	current->cp_hdr.cp_count = 0;
	current->cp_hdr.cp_unit = unit; 
	mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)current));
	cnlast = &current->cp_hdr;
	timo = 10000;
	do
		uncache(&current->cp_hdr.cp_unit);
	while ((current->cp_hdr.cp_unit&CPTAKE) == 0 && --timo);
	if (current->cp_hdr.cp_unit & CPTAKE) {
		cnparams(tp);
		failed = 0;
	} else if (failed++ == 0)
		log(LOG_ERR, "Console wedged, reset failed.\n");
}

/*
E 7
 * Set line parameters
 */
cnparams(tp)
D 2
register struct tty *tp;
E 2
I 2
	register struct tty *tp;
E 2
{
D 2
	register timo ;
E 2
I 2
	register timo;
E 2
	register struct cpdcb_o *current;
D 7
	register struct cpdcb_i *cin;
E 7
I 7
	int unit;
E 7

D 7
	current = &consout[minor(tp->t_dev)];
E 7
I 7
	unit = minor(tp->t_dev);
	current = &consout[unit];
E 7
	timo = 30000;
	/*
D 7
	 * Try waiting for the console tty to come ready,
E 7
I 7
	 * Try waiting for the console tty to finish any output,
E 7
	 * otherwise give up after a reasonable time.
D 7
	 * make sure we dont test this bit in cache!
E 7
	 */
D 2
	uncache((char *)&current->cp_hdr.cp_unit);
	while ((current->cp_hdr.cp_unit & CPDONE) == 0 && --timo )
		uncache((char *)&current->cp_hdr.cp_unit);
	current->cp_hdr.cp_comm = (char)CPSTTY;
E 2
I 2
D 5
	uncache(&current->cp_hdr.cp_unit);
	while ((current->cp_hdr.cp_unit&CPDONE) == 0 && --timo)
E 5
I 5
	do
E 5
		uncache(&current->cp_hdr.cp_unit);
I 5
	while ((current->cp_hdr.cp_unit&CPDONE) == 0 && --timo);
E 5
	current->cp_hdr.cp_comm = CPSTTY;
E 2
	current->cp_hdr.cp_count = 4;
	current->cp_buf[0] = tp->t_ispeed;
	/* the rest are defaults */
	current->cp_buf[1] = 0;	/* no parity */
D 2
	current->cp_buf[2] = 0; /* stop bits */
	current->cp_buf[3] = 8; /* data bits */
E 2
I 2
	current->cp_buf[2] = 0;	/* stop bits */
	current->cp_buf[3] = 8;	/* data bits */
E 2
D 7
	timo = 10000;
	/*
	 * Try waiting for the console tty to come ready,
	 * otherwise give up after a reasonable time.
	 */
D 2
	uncache((char *)&lasthdr->cp_unit);
	while ((lasthdr->cp_unit & CPTAKE)==0 && --timo )
		uncache((char *)&lasthdr->cp_unit);
E 2
I 2
D 5
	uncache(&lasthdr->cp_unit);
	while ((lasthdr->cp_unit&CPTAKE) == 0 && --timo)
		uncache(&lasthdr->cp_unit);
E 5
I 5
	do
		uncache(&cnlast->cp_unit);
	while ((cnlast->cp_unit&CPTAKE) == 0 && --timo);
E 7
E 5
E 2
	/* Reset done bit */
D 7
	current->cp_hdr.cp_unit = (char)minor(tp->t_dev); 
D 5
	lasthdr = (struct cphdr *)current;
E 5
I 5
	cnlast = (struct cphdr *)current;
E 7
I 7
	current->cp_hdr.cp_unit = unit; 

	waitforlast(timo);
E 7
E 5
D 2
	mtpr (current, CPMDCB);
E 2
I 2
D 6
	mtpr(CPMDCB, current);
E 6
I 6
	mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)current));
I 7
	cnlast = &current->cp_hdr;
E 7
E 6
E 2

D 7
	timo = 10000;
D 2
	uncache((char *)&lasthdr->cp_unit);
	while ((lasthdr->cp_unit & CPTAKE)==0 && --timo )
		uncache((char *)&lasthdr->cp_unit);
E 2
I 2
D 5
	uncache(&lasthdr->cp_unit);
	while ((lasthdr->cp_unit&CPTAKE) == 0 && --timo)
		uncache(&lasthdr->cp_unit);
E 5
I 5
	do
		uncache(&cnlast->cp_unit);
	while ((cnlast->cp_unit&CPTAKE) == 0 && --timo);
E 5
E 2
	cin = &consin[minor(tp->t_dev)];
D 2
	cin->cp_hdr.cp_unit = (char)(minor(tp->t_dev));
	cin->cp_hdr.cp_comm = (char)CPREAD;
E 2
I 2
	cin->cp_hdr.cp_unit = minor(tp->t_dev);
	cin->cp_hdr.cp_comm = CPREAD;
E 2
	cin->cp_hdr.cp_count = 1;	/* Get ready for input */
D 2
	mtpr (cin, CPMDCB);
E 2
I 2
D 6
	mtpr(CPMDCB, cin);
E 6
I 6
	mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)cin));
E 6
E 2
D 5
	lasthdr = (struct cphdr *)cin;
E 5
I 5
	cnlast = (struct cphdr *)cin;
E 7
I 7
	cnpostread(unit);
E 7
E 5
D 2

E 2
}
I 4

D 11
#ifdef KDB
E 11
I 11
#ifdef KADB
E 11
/*
 * Turn input polling on/off (used by debugger).
 */
cnpoll(onoff)
	int onoff;
{

	if (!onoff) {
		consoftc[CPCONS].cs_flags &= ~CSF_POLLING;
		cnpostread(CPCONS);		/* restart input */
	} else
		consoftc[CPCONS].cs_flags |= CSF_POLLING;
}
#endif
E 4
E 1
