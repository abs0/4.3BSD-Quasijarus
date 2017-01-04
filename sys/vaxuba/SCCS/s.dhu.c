h09141
s 00010/00001/00753
d D 7.8 04/12/08 04:07:06 msokolov 18 17
c exception select for modem status changes
e
s 00001/00001/00753
d D 7.7 03/03/16 04:03:07 msokolov 17 16
c Don't interpret output high chars as delays in PASS8 mode
e
s 00001/00001/00753
d D 7.6 02/07/30 23:44:49 msokolov 16 15
c finally support FNDELAY on open
e
s 00003/00003/00751
d D 7.5 02/05/17 20:16:54 msokolov 15 14
c DHQ11 supports 38400 baud
e
s 00001/00001/00753
d D 7.4 89/01/24 17:24:00 bostic 14 13
c typo in attach routines; bug report 4.3BSD-tahoe/sys/34
e
s 00002/00002/00752
d D 7.3 88/08/27 07:20:44 tef 13 12
c Add support for microvax 3000.
e
s 00020/00011/00734
d D 7.2 86/12/19 11:46:27 karels 12 11
c correct uba reallocation on reset
e
s 00001/00001/00744
d D 7.1 86/06/05 01:06:47 mckusick 11 10
c 4.3BSD release version
e
s 00006/00000/00739
d D 4.10 86/04/22 11:06:03 kridle 10 9
c MicroVAX II Integration (KA630)
e
s 00001/00004/00738
d D 4.9 86/02/20 19:52:47 karels 9 8
c lint
e
s 00006/00005/00736
d D 4.8 86/02/17 22:58:28 karels 8 7
c correct uba allocation after reset
e
s 00001/00001/00740
d D 4.7 85/11/22 06:39:15 tef 7 6
c standard list of device addresses must be null terminated.
e
s 00007/00007/00734
d D 4.6 85/11/08 19:08:21 karels 6 5
c share unibus resources between multiplexor types
e
s 00007/00028/00734
d D 4.5 85/11/04 18:19:34 karels 5 4
c move carrier change code to line disciplines; make PORTSELECTOR
c code and configuration consistent; change default speed to 9600
e
s 00001/00001/00761
d D 4.4 85/09/17 18:34:01 eric 4 3
c facilities in syslog
e
s 00001/00001/00761
d D 4.3 85/08/13 05:09:43 lepreau 3 2
c add PASS8: pass all 8 bits of input
e
s 00007/00001/00755
d D 4.2 85/06/08 14:14:30 mckusick 2 1
c Add copyright
e
s 00756/00000/00000
d D 4.1 85/05/20 21:01:31 mckusick 1 0
c date and time created 85/05/20 21:01:31 by mckusick
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
D 11
 * Copyright (c) 1985 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1985, 1986 Regents of the University of California.
E 11
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

/*
 * based on	dh.c 6.3	84/03/15
 * and on	dmf.c	6.2	84/02/16
 *
 * Dave Johnson, Brown University Computer Science
 *	ddj%brown@csnet-relay
 */

#include "dhu.h"
#if NDHU > 0
/*
 * DHU-11 driver
 */
#include "../machine/pte.h"

#include "bk.h"
#include "param.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "ioctl.h"
#include "tty.h"
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "kernel.h"
#include "syslog.h"

#include "uba.h"
#include "ubareg.h"
#include "ubavar.h"
#include "dhureg.h"

#include "bkmac.h"
#include "clist.h"
#include "file.h"
#include "uio.h"

/*
 * Definition of the driver for the auto-configuration program.
 */
int	dhuprobe(), dhuattach(), dhurint(), dhuxint();
struct	uba_device *dhuinfo[NDHU];
D 7
u_short dhustd[] = { 160440, 160500 };	/* some common addresses */
E 7
I 7
u_short dhustd[] = { 160440, 160500, 0 };	/* some common addresses */
E 7
struct	uba_driver dhudriver =
	{ dhuprobe, 0, dhuattach, 0, dhustd, "dhu", dhuinfo };

#define	NDHULINE 	(NDHU*16)

#define	UNIT(x)	(minor(x))

#ifndef PORTSELECTOR
D 5
#define ISPEED	B300
E 5
I 5
#define ISPEED	B9600
E 5
#define IFLAGS	(EVENP|ODDP|ECHO)
#else
#define ISPEED	B4800
#define IFLAGS	(EVENP|ODDP)
#endif

/*
 * default receive silo timeout value -- valid values are 2..255
 * number of ms. to delay between first char received and receive interrupt
 *
 * A value of 20 gives same response as ABLE dh/dm with silo alarm = 0
 */
#define	DHU_DEF_TIMO	20

/*
 * Other values for silo timeout register defined here but not used:
 * receive interrupt only on modem control or silo alarm (3/4 full)
 */
#define DHU_POLL_TIMO	0
/*
 * receive interrupt immediately on receive character
 */
#define DHU_NO_TIMO	1

/*
 * Local variables for the driver
 */
/*
D 15
 * Baud rates: no 50, 200, or 38400 baud; all other rates are from "Group B".
E 15
I 15
 * Baud rates: no 50 or 200 baud; all other rates are from "Group B".
E 15
 *	EXTA => 19200 baud
D 15
 *	EXTB => 2000 baud
E 15
I 15
 *	EXTB => 38400 baud
E 15
 */
char	dhu_speeds[] =
D 15
	{ 0, 0, 1, 2, 3, 4, 0, 5, 6, 7, 8, 10, 11, 13, 14, 9 };
E 15
I 15
	{ 0, 0, 1, 2, 3, 4, 0, 5, 6, 7, 8, 10, 11, 13, 14, 15 };
E 15

short	dhusoftCAR[NDHU];

struct	tty dhu_tty[NDHULINE];
int	ndhu = NDHULINE;
int	dhuact;				/* mask of active dhu's */
int	dhustart(), ttrstrt();

/*
D 12
 * The clist space is mapped by the driver onto each UNIBUS.
E 12
I 12
 * The clist space is mapped by one terminal driver onto each UNIBUS.
 * The identity of the board which allocated resources is recorded,
 * so the process may be repeated after UNIBUS resets.
E 12
 * The UBACVT macro converts a clist space address for unibus uban
 * into an i/o space address for the DMA routine.
 */
D 12
int	dhu_ubinfo[NUBA];	/* info about allocated unibus map */
D 6
static int cbase[NUBA];		/* base address in unibus map */
E 6
I 6
int	cbase[NUBA];		/* base address in unibus map */
E 12
I 12
int	dhu_uballoc[NUBA];	/* which dhu (if any) allocated unibus map */
int	cbase[NUBA];		/* base address of clists in unibus map */
E 12
E 6
#define UBACVT(x, uban) 	(cbase[uban] + ((x)-(char *)cfree))

/*
 * Routine for configuration to force a dhu to interrupt.
 */
/*ARGSUSED*/
dhuprobe(reg)
	caddr_t reg;
{
	register int br, cvec;		/* these are ``value-result'' */
	register struct dhudevice *dhuaddr = (struct dhudevice *)reg;
	int i;

#ifdef lint
	br = 0; cvec = br; br = cvec;
	if (ndhu == 0) ndhu = 1;
	dhurint(0); dhuxint(0);
#endif
	/*
	 * The basic idea here is:
	 *	do a self-test by setting the Master-Reset bit
	 *	if this fails, then return
	 *	if successful, there will be 8 diagnostic codes in RX FIFO
	 *	therefore ask for a  Received-Data-Available interrupt
	 *	wait for it...
	 *	reset the interrupt-enable bit and flush out the diag. codes
	 */
	dhuaddr->dhucsr = DHU_CS_MCLR;
	for (i = 0; i < 1000; i++) {
		DELAY(10000);
		if ((dhuaddr->dhucsr&DHU_CS_MCLR) == 0)
			break;
	}
	if (dhuaddr->dhucsr&DHU_CS_MCLR)
		return(0);
	if (dhuaddr->dhucsr&DHU_CS_DFAIL)
		return(0);
	dhuaddr->dhucsr = DHU_CS_RIE;
	DELAY(1000);
	dhuaddr->dhucsr = 0;
	while (dhuaddr->dhurbuf < 0)
		/* void */;
	return (sizeof(struct dhudevice));
}

/*
 * Routine called to attach a dhu.
 */
dhuattach(ui)
	struct uba_device *ui;
{

	dhusoftCAR[ui->ui_unit] = ui->ui_flags;
I 8
	cbase[ui->ui_ubanum] = -1;
I 12
D 14
	dhu_uballoc[ui->ui_unit] = -1;
E 14
I 14
	dhu_uballoc[ui->ui_ubanum] = -1;
E 14
E 12
E 8
}

/*
 * Open a DHU11 line, mapping the clist onto the uba if this
 * is the first dhu on this uba.  Turn on this dhu if this is
 * the first use of it.
 */
/*ARGSUSED*/
dhuopen(dev, flag)
	dev_t dev;
{
	register struct tty *tp;
	register int unit, dhu;
	register struct dhudevice *addr;
	register struct uba_device *ui;
	int s;

	unit = UNIT(dev);
	dhu = unit >> 4;
	if (unit >= NDHULINE || (ui = dhuinfo[dhu])== 0 || ui->ui_alive == 0)
		return (ENXIO);
	tp = &dhu_tty[unit];
	if (tp->t_state & TS_XCLUDE && u.u_uid != 0)
		return (EBUSY);
	addr = (struct dhudevice *)ui->ui_addr;
	tp->t_addr = (caddr_t)addr;
	tp->t_oproc = dhustart;
	/*
	 * While setting up state for this uba and this dhu,
	 * block uba resets which can clear the state.
	 */
	s = spl5();
D 6
	if (dhu_ubinfo[ui->ui_ubanum] == 0) {
E 6
I 6
D 8
	if (cbase[ui->ui_ubanum] == 0) {
E 8
I 8
	if (cbase[ui->ui_ubanum] == -1) {
E 8
E 6
D 12
		dhu_ubinfo[ui->ui_ubanum] =
		    uballoc(ui->ui_ubanum, (caddr_t)cfree,
			nclist*sizeof(struct cblock), 0);
D 8
		cbase[ui->ui_ubanum] = dhu_ubinfo[ui->ui_ubanum]&0x3ffff;
E 8
I 8
		cbase[ui->ui_ubanum] = UBAI_ADDR(dhu_ubinfo[ui->ui_ubanum]);
E 12
I 12
		dhu_uballoc[ui->ui_ubanum] = dhu;
		cbase[ui->ui_ubanum] = UBAI_ADDR(uballoc(ui->ui_ubanum,
		    (caddr_t)cfree, nclist*sizeof(struct cblock), 0));
E 12
E 8
	}
	if ((dhuact&(1<<dhu)) == 0) {
		addr->dhucsr = DHU_SELECT(0) | DHU_IE;
		addr->dhutimo = DHU_DEF_TIMO;
		dhuact |= (1<<dhu);
		/* anything else to configure whole board */
	}
	(void) splx(s);
	/*
	 * If this is first open, initialize tty state to default.
	 */
	if ((tp->t_state&TS_ISOPEN) == 0) {
		ttychars(tp);
#ifndef PORTSELECTOR
		if (tp->t_ispeed == 0) {
#else
			tp->t_state |= TS_HUPCLS;
#endif PORTSELECTOR
			tp->t_ispeed = ISPEED;
			tp->t_ospeed = ISPEED;
			tp->t_flags = IFLAGS;
#ifndef PORTSELECTOR
		}
#endif PORTSELECTOR
		tp->t_dev = dev;
		dhuparam(unit);
	}
	/*
	 * Wait for carrier, then process line discipline specific open.
	 */
	s = spl5();
	if ((dhumctl(dev, DHU_ON, DMSET) & DHU_CAR) ||
	    (dhusoftCAR[dhu] & (1<<(unit&0xf))))
		tp->t_state |= TS_CARR_ON;
D 16
	while ((tp->t_state & TS_CARR_ON) == 0) {
E 16
I 16
	while (!(tp->t_state & TS_CARR_ON) && !(flag & FNDELAY)) {
E 16
		tp->t_state |= TS_WOPEN;
		sleep((caddr_t)&tp->t_rawq, TTIPRI);
	}
	(void) splx(s);
	return ((*linesw[tp->t_line].l_open)(dev, tp));
}

/*
 * Close a DHU11 line, turning off the modem control.
 */
/*ARGSUSED*/
dhuclose(dev, flag)
	dev_t dev;
	int flag;
{
	register struct tty *tp;
	register unit;

	unit = UNIT(dev);
	tp = &dhu_tty[unit];
	(*linesw[tp->t_line].l_close)(tp);
	(void) dhumctl(unit, DHU_BRK, DMBIC);
	if ((tp->t_state&(TS_HUPCLS|TS_WOPEN)) || (tp->t_state&TS_ISOPEN)==0)
#ifdef PORTSELECTOR
	{
		extern int wakeup();

		(void) dhumctl(unit, DHU_OFF, DMSET);
		/* Hold DTR low for 0.5 seconds */
		timeout(wakeup, (caddr_t) &tp->t_dev, hz/2);
		sleep((caddr_t) &tp->t_dev, PZERO);
	}
#else
		(void) dhumctl(unit, DHU_OFF, DMSET);
#endif PORTSELECTOR
	ttyclose(tp);
}

dhuread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register struct tty *tp = &dhu_tty[UNIT(dev)];

	return ((*linesw[tp->t_line].l_read)(tp, uio));
}

dhuwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register struct tty *tp = &dhu_tty[UNIT(dev)];

	return ((*linesw[tp->t_line].l_write)(tp, uio));
}

/*
 * DHU11 receiver interrupt.
 */
dhurint(dhu)
	int dhu;
{
	register struct tty *tp;
	register c;
	register struct dhudevice *addr;
	register struct tty *tp0;
	register struct uba_device *ui;
	register line;
	int overrun = 0;

I 10
D 13
#ifdef VAX630
E 13
I 13
#ifdef QBA
E 13
	(void) spl5();
#endif
E 10
	ui = dhuinfo[dhu];
	if (ui == 0 || ui->ui_alive == 0)
		return;
	addr = (struct dhudevice *)ui->ui_addr;
	tp0 = &dhu_tty[dhu<<4];
	/*
	 * Loop fetching characters from the silo for this
	 * dhu until there are no more in the silo.
	 */
	while ((c = addr->dhurbuf) < 0) {	/* (c & DHU_RB_VALID) == on */
		line = DHU_RX_LINE(c);
		tp = tp0 + line;
		if ((c & DHU_RB_STAT) == DHU_RB_STAT) {
			/*
			 * modem changed or diag info
			 */
			if (c & DHU_RB_DIAG) {
				/* decode diagnostic messages */
				continue;
			}
D 5
			if ((tp->t_state & TS_WOPEN) == 0 &&
			    (tp->t_flags & MDMBUF)) {
				if (c & DHU_ST_DCD) {
					tp->t_state &= ~TS_TTSTOP;
					ttstart(tp);
				} else if ((tp->t_state & TS_TTSTOP) == 0) {
					tp->t_state |= TS_TTSTOP;
					dhustop(tp, 0);
				}
			} else if ((c & DHU_ST_DCD) == 0 &&
				   (dhusoftCAR[dhu] & (1<<line)) == 0) {
				if ((tp->t_state & TS_WOPEN) == 0 &&
				    (tp->t_flags & NOHANG) == 0) {
					gsignal(tp->t_pgrp, SIGHUP);
					gsignal(tp->t_pgrp, SIGCONT);
					(void) dhumctl((dhu<<4)|line,
								DHU_OFF, DMSET);
					ttyflush(tp, FREAD|FWRITE);
				}
				tp->t_state &= ~TS_CARR_ON;
			} else {
				if ((tp->t_state & TS_CARR_ON) == 0) {
					tp->t_state |= TS_CARR_ON;
					wakeup((caddr_t)&tp->t_rawq);
				}
			}
E 5
I 5
			if (c & DHU_ST_DCD)
				(void)(*linesw[tp->t_line].l_modem)(tp, 1);
			else if ((dhusoftCAR[dhu] & (1<<line)) == 0 &&
			    (*linesw[tp->t_line].l_modem)(tp, 0) == 0)
				(void) dhumctl((dhu<<4)|line, DHU_OFF, DMSET);
I 18
			tp->t_state |= TS_MODEMCHG;
			if (tp->t_rsel) {
				selwakeup(tp->t_rsel, tp->t_state & TS_RCOLL);
				tp->t_rsel = 0;
				tp->t_state &= ~TS_RCOLL;
			}
E 18
E 5
			continue;
		}
		if ((tp->t_state&TS_ISOPEN) == 0) {
			wakeup((caddr_t)&tp->t_rawq);
#ifdef PORTSELECTOR
			if ((tp->t_state&TS_WOPEN) == 0)
#endif
D 5
			continue;
E 5
I 5
				continue;
E 5
		}
		if (c & DHU_RB_PE)
			if ((tp->t_flags&(EVENP|ODDP)) == EVENP ||
			    (tp->t_flags&(EVENP|ODDP)) == ODDP)
				continue;
		if ((c & DHU_RB_DO) && overrun == 0) {
D 4
			log(KERN_RECOV, "dhu%d: silo overflow\n", dhu);
E 4
I 4
			log(LOG_WARNING, "dhu%d: silo overflow\n", dhu);
E 4
			overrun = 1;
		}
		if (c & DHU_RB_FE)
			/*
			 * At framing error (break) generate
			 * a null (in raw mode, for getty), or a
			 * interrupt (in cooked/cbreak mode).
			 */
			if (tp->t_flags&RAW)
				c = 0;
			else
				c = tp->t_intrc;
#if NBK > 0
		if (tp->t_line == NETLDISC) {
			c &= 0x7f;
			BKINPUT(c, tp);
		} else
#endif
			(*linesw[tp->t_line].l_rint)(c, tp);
	}
}

/*
 * Ioctl for DHU11.
 */
/*ARGSUSED*/
dhuioctl(dev, cmd, data, flag)
	caddr_t data;
{
	register struct tty *tp;
	register int unit = UNIT(dev);
D 9
	register dhu = unit>>4;
	register bit = (1<<(unit&0xf));
E 9
D 18
	int error;
E 18
I 18
	int error, s;
E 18

	tp = &dhu_tty[unit];
	error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
	if (error >= 0)
		return (error);
	error = ttioctl(tp, cmd, data, flag);
	if (error >= 0) {
		if (cmd == TIOCSETP || cmd == TIOCSETN || cmd == TIOCLSET ||
		    cmd == TIOCLBIC || cmd == TIOCLBIS)
			dhuparam(unit);
		return (error);
	}

	switch (cmd) {
	case TIOCSBRK:
		(void) dhumctl(unit, DHU_BRK, DMBIS);
		break;

	case TIOCCBRK:
		(void) dhumctl(unit, DHU_BRK, DMBIC);
		break;

	case TIOCSDTR:
		(void) dhumctl(unit, DHU_DTR|DHU_RTS, DMBIS);
		break;

	case TIOCCDTR:
		(void) dhumctl(unit, DHU_DTR|DHU_RTS, DMBIC);
		break;

	case TIOCMSET:
		(void) dhumctl(dev, dmtodhu(*(int *)data), DMSET);
		break;

	case TIOCMBIS:
		(void) dhumctl(dev, dmtodhu(*(int *)data), DMBIS);
		break;

	case TIOCMBIC:
		(void) dhumctl(dev, dmtodhu(*(int *)data), DMBIC);
		break;

	case TIOCMGET:
I 18
		s = spltty();
		tp->t_state &= ~TS_MODEMCHG;
		splx(s);
E 18
		*(int *)data = dhutodm(dhumctl(dev, 0, DMGET));
		break;
	default:
		return (ENOTTY);
	}
	return (0);
}

dmtodhu(bits)
	register int bits;
{
	register int b = 0;

	if (bits & DML_RTS) b |= DHU_RTS;
	if (bits & DML_DTR) b |= DHU_DTR;
	if (bits & DML_LE) b |= DHU_LE;
	return(b);
}

dhutodm(bits)
	register int bits;
{
	register int b = 0;

	if (bits & DHU_DSR) b |= DML_DSR;
	if (bits & DHU_RNG) b |= DML_RNG;
	if (bits & DHU_CAR) b |= DML_CAR;
	if (bits & DHU_CTS) b |= DML_CTS;
	if (bits & DHU_RTS) b |= DML_RTS;
	if (bits & DHU_DTR) b |= DML_DTR;
	if (bits & DHU_LE) b |= DML_LE;
	return(b);
}


/*
 * Set parameters from open or stty into the DHU hardware
 * registers.
 */
dhuparam(unit)
	register int unit;
{
	register struct tty *tp;
	register struct dhudevice *addr;
	register int lpar;
	int s;

	tp = &dhu_tty[unit];
	addr = (struct dhudevice *)tp->t_addr;
	/*
	 * Block interrupts so parameters will be set
	 * before the line interrupts.
	 */
	s = spl5();
	if ((tp->t_ispeed) == 0) {
		tp->t_state |= TS_HUPCLS;
		(void)dhumctl(unit, DHU_OFF, DMSET);
		splx(s);
		return;
	}
	lpar = (dhu_speeds[tp->t_ospeed]<<12) | (dhu_speeds[tp->t_ispeed]<<8);
	if ((tp->t_ispeed) == B134)
		lpar |= DHU_LP_BITS6|DHU_LP_PENABLE;
D 3
	else if (tp->t_flags & (RAW|LITOUT))
E 3
I 3
	else if (tp->t_flags & (RAW|LITOUT|PASS8))
E 3
		lpar |= DHU_LP_BITS8;
	else
		lpar |= DHU_LP_BITS7|DHU_LP_PENABLE;
	if (tp->t_flags&EVENP)
		lpar |= DHU_LP_EPAR;
	if ((tp->t_ospeed) == B110)
		lpar |= DHU_LP_TWOSB;
	addr->dhucsr = DHU_SELECT(unit) | DHU_IE;
	addr->dhulpr = lpar;
	splx(s);
}

/*
 * DHU11 transmitter interrupt.
 * Restart each line which used to be active but has
 * terminated transmission since the last interrupt.
 */
dhuxint(dhu)
	int dhu;
{
	register struct tty *tp;
	register struct dhudevice *addr;
	register struct tty *tp0;
	register struct uba_device *ui;
	register int line, t;
	u_short cntr;

I 10
D 13
#ifdef VAX630
E 13
I 13
#ifdef QBA
E 13
	(void) spl5();
#endif
E 10
	ui = dhuinfo[dhu];
	tp0 = &dhu_tty[dhu<<4];
	addr = (struct dhudevice *)ui->ui_addr;
	while ((t = addr->dhucsrh) & DHU_CSH_TI) {
		line = DHU_TX_LINE(t);
		tp = tp0 + line;
		tp->t_state &= ~TS_BUSY;
		if (t & DHU_CSH_NXM) {
			printf("dhu(%d,%d): NXM fault\n", dhu, line);
			/* SHOULD RESTART OR SOMETHING... */
		}
		if (tp->t_state&TS_FLUSH)
			tp->t_state &= ~TS_FLUSH;
		else {
			addr->dhucsrl = DHU_SELECT(line) | DHU_IE;
			/*
			 * Do arithmetic in a short to make up
			 * for lost 16&17 bits.
			 */
			cntr = addr->dhubar1 -
			    UBACVT(tp->t_outq.c_cf, ui->ui_ubanum);
			ndflush(&tp->t_outq, (int)cntr);
		}
		if (tp->t_line)
			(*linesw[tp->t_line].l_start)(tp);
		else
			dhustart(tp);
	}
}

/*
 * Start (restart) transmission on the given DHU11 line.
 */
dhustart(tp)
	register struct tty *tp;
{
	register struct dhudevice *addr;
	register int car, dhu, unit, nch;
	int s;

	unit = minor(tp->t_dev);
	dhu = unit >> 4;
	unit &= 0xf;
	addr = (struct dhudevice *)tp->t_addr;

	/*
	 * Must hold interrupts in following code to prevent
	 * state of the tp from changing.
	 */
	s = spl5();
	/*
	 * If it's currently active, or delaying, no need to do anything.
	 */
	if (tp->t_state&(TS_TIMEOUT|TS_BUSY|TS_TTSTOP))
		goto out;
	/*
	 * If there are sleepers, and output has drained below low
	 * water mark, wake up the sleepers..
	 */
	if (tp->t_outq.c_cc<=TTLOWAT(tp)) {
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
	/*
	 * Now restart transmission unless the output queue is
	 * empty.
	 */
	if (tp->t_outq.c_cc == 0)
		goto out;
D 17
	if (tp->t_flags & (RAW|LITOUT))
E 17
I 17
	if (tp->t_flags & (RAW|LITOUT|PASS8))
E 17
		nch = ndqb(&tp->t_outq, 0);
	else {
		nch = ndqb(&tp->t_outq, 0200);
		/*
		 * If first thing on queue is a delay process it.
		 */
		if (nch == 0) {
			nch = getc(&tp->t_outq);
			timeout(ttrstrt, (caddr_t)tp, (nch&0x7f)+6);
			tp->t_state |= TS_TIMEOUT;
			goto out;
		}
	}
	/*
	 * If characters to transmit, restart transmission.
	 */
	if (nch) {
		car = UBACVT(tp->t_outq.c_cf, dhuinfo[dhu]->ui_ubanum);
		addr->dhucsrl = DHU_SELECT(unit) | DHU_IE;
		addr->dhulcr &= ~DHU_LC_TXABORT;
		addr->dhubcr = nch;
		addr->dhubar1 = car;
		addr->dhubar2 = ((car >> DHU_XBA_SHIFT) & DHU_BA2_XBA) |
					DHU_BA2_DMAGO;
		tp->t_state |= TS_BUSY;
	}
out:
	splx(s);
}

/*
 * Stop output on a line, e.g. for ^S/^Q or output flush.
 */
/*ARGSUSED*/
dhustop(tp, flag)
	register struct tty *tp;
{
	register struct dhudevice *addr;
	register int unit, s;

	addr = (struct dhudevice *)tp->t_addr;
	/*
	 * Block input/output interrupts while messing with state.
	 */
	s = spl5();
	if (tp->t_state & TS_BUSY) {
		/*
		 * Device is transmitting; stop output
		 * by selecting the line and setting the
		 * abort xmit bit.  We will get an xmit interrupt,
		 * where we will figure out where to continue the
		 * next time the transmitter is enabled.  If
		 * TS_FLUSH is set, the outq will be flushed.
		 * In either case, dhustart will clear the TXABORT bit.
		 */
		unit = minor(tp->t_dev);
		addr->dhucsrl = DHU_SELECT(unit) | DHU_IE;
		addr->dhulcr |= DHU_LC_TXABORT;
		if ((tp->t_state&TS_TTSTOP)==0)
			tp->t_state |= TS_FLUSH;
	}
	(void) splx(s);
}

/*
 * DHU11 modem control
 */
dhumctl(dev, bits, how)
	dev_t dev;
	int bits, how;
{
	register struct dhudevice *dhuaddr;
D 9
	register int unit, mbits, lcr;
E 9
I 9
	register int unit, mbits;
E 9
	int s;

	unit = UNIT(dev);
	dhuaddr = (struct dhudevice *)(dhu_tty[unit].t_addr);
	unit &= 0xf;
	s = spl5();
	dhuaddr->dhucsr = DHU_SELECT(unit) | DHU_IE;
	/*
	 * combine byte from stat register (read only, bits 16..23)
	 * with lcr register (read write, bits 0..15).
	 */
	mbits = dhuaddr->dhulcr | (dhuaddr->dhustat << 16);
	switch (how) {
	case DMSET:
		mbits = (mbits & 0xff0000) | bits;
		break;

	case DMBIS:
		mbits |= bits;
		break;

	case DMBIC:
		mbits &= ~bits;
		break;

	case DMGET:
		(void) splx(s);
		return(mbits);
	}
	dhuaddr->dhulcr = (mbits & 0xffff) | DHU_LC_RXEN;
	dhuaddr->dhulcr2 = DHU_LC2_TXEN;
	(void) splx(s);
	return(mbits);
}

/*
 * Reset state of driver if UBA reset was necessary.
 * Reset the line and modem control registers.
 * restart transmitters.
 */
dhureset(uban)
	int uban;
{
	register int dhu, unit;
	register struct tty *tp;
	register struct uba_device *ui;
	register struct dhudevice *addr;
	int i;
D 9
	register int s;
E 9

D 6
	if (dhu_ubinfo[uban] == 0)
		return;
	dhu_ubinfo[uban] = uballoc(uban, (caddr_t)cfree,
				    nclist*sizeof (struct cblock), 0);
	cbase[uban] = dhu_ubinfo[uban]&0x3ffff;
E 6
	for (dhu = 0; dhu < NDHU; dhu++) {
		ui = dhuinfo[dhu];
		if (ui == 0 || ui->ui_alive == 0 || ui->ui_ubanum != uban)
			continue;
		printf(" dhu%d", dhu);
I 6
D 8
		if (cbase[uban] == 0) {
E 8
I 8
D 12
		if (dhu_ubinfo[uban]) {
E 8
			dhu_ubinfo[uban] = uballoc(uban, (caddr_t)cfree,
					    nclist*sizeof (struct cblock), 0);
D 8
			cbase[uban] = dhu_ubinfo[uban]&0x3ffff;
E 8
I 8
			cbase[uban] = UBAI_ADDR(dhu_ubinfo[uban]);
E 12
I 12
		if (dhu_uballoc[uban] == dhu) {
			int info;

			info = uballoc(uban, (caddr_t)cfree,
			    nclist * sizeof(struct cblock), UBA_CANTWAIT);
			if (info)
				cbase[uban] = UBAI_ADDR(info);
			else {
				printf(" [can't get uba map]");
				cbase[uban] = -1;
			}
E 12
E 8
		}
E 6
		addr = (struct dhudevice *)ui->ui_addr;
		addr->dhucsr = DHU_SELECT(0) | DHU_IE;
		addr->dhutimo = DHU_DEF_TIMO;
		unit = dhu * 16;
		for (i = 0; i < 16; i++) {
			tp = &dhu_tty[unit];
			if (tp->t_state & (TS_ISOPEN|TS_WOPEN)) {
				dhuparam(unit);
				(void)dhumctl(unit, DHU_ON, DMSET);
				tp->t_state &= ~TS_BUSY;
				dhustart(tp);
			}
			unit++;
		}
	}
}
#endif
E 1
