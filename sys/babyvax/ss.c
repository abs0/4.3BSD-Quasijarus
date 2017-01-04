/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)ss.c	7.1 (Berkeley) 3/22/04
 */

#include "ss.h"
#if NSS > 0
/*
 * ss (BabyVAX dz) driver
 *
 * Based on the regular DZ-11/DZ-32 Driver
 *
 * The latter driver mimicked dh.c; see it for explanation of common code.
 */
#include "bk.h"

#include "../machine/pte.h"

#include "param.h"
#include "systm.h"
#include "ioctl.h"
#include "tty.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "conf.h"
#include "bkmac.h"
#include "file.h"
#include "uio.h"
#include "kernel.h"
#include "syslog.h"

#include "../vax/scb.h"
#include "../vaxuba/pdma.h"
#include "../vaxuba/ubavar.h"
#include "bvreg.h"
#include "ssreg.h"
#include "ssvar.h"

/*
 * Driver information for auto-configuration stuff.
 */
int	ssprobe(), ssattach(), ssrint();
struct	uba_device *ssinfo[NSS];
u_short	ssstd[] = { 0 };
struct	uba_driver ssdriver =
	{ ssprobe, 0, ssattach, 0, ssstd, "ss", ssinfo };

#define	NSSLINE 	(NSS*8)
#define	FASTTIMER	(hz/30)		/* rate to drain silos, when in use */

int	ssstart(), ssxint();
int	ttrstrt();
struct	tty ss_tty[NSSLINE];
int	ss_cnt = { NSSLINE };
int	ssact;
int	sssilos;			/* mask of dz's with silo in use */
int	sschars[NSS];			/* recent input count */
int	ssrate[NSS];			/* smoothed input count */
int	sstimerintvl;			/* time interval for sstimer */
int	sshighrate = 100;		/* silo on if sschars > sshighrate */
int	sslowrate = 75;			/* silo off if ssrate < sslowrate */

/*
 * Software copy of dzbrk since it isn't readable
 */
char	ss_brk[NSS];
char	sssoftCAR[NSS];

/*
 * The dz11 doesn't interrupt on carrier transitions, so
 * we have to use a timer to watch it.
 */
char	ss_timer;		/* timer started? */

/*
 * Pdma structures for fast output code
 */
struct	pdma sspdma[NSSLINE];

char	ss_speeds[] =
	{ 0,020,021,022,023,024,0,025,026,027,030,032,034,036,037,0 };
 
#ifndef	PORTSELECTOR
#define	ISPEED	B9600
#define	IFLAGS	(EVENP|ODDP|ECHO)
#else
#define	ISPEED	B4800
#define	IFLAGS	(EVENP|ODDP)
#endif

ssprobe(ui)
	struct uba_device *ui;
{
	/* ss is present on all BabyVAXen */
	ui->ui_addr = (caddr_t) 0x200A0000; /* just for "ss0 at ..." scribble */
	return (1);
}

ssattach(ui)
	register struct uba_device *ui;
{
	register struct pdma *pdp = sspdma;
	register struct tty *tp = ss_tty;
	register int cntr;
	extern ssscan();

	for (cntr = 0; cntr < 4; cntr++) {
		pdp->p_addr = (struct dzdevice *)&bv_regs.bvr_sercsr;
		pdp->p_arg = (int)tp;
		pdp->p_fcn = ssxint;
		pdp++, tp++;
	}
	sssoftCAR[ui->ui_unit] = ui->ui_flags | 0xFB;	/* modemctl only on 2 */
	if (ss_timer == 0) {
		ss_timer++;
		timeout(ssscan, (caddr_t)0, hz);
		sstimerintvl = FASTTIMER;
	}
	((int (**)())scb)[SS_RINT_VEC/4] = scbentry(ui->ui_intr[0], SCB_ISTACK);
	((int (**)())scb)[SS_TINT_VEC/4] = scbentry(ui->ui_intr[1], SCB_ISTACK);
}

/*ARGSUSED*/
ssopen(dev, flag)
	dev_t dev;
{
	register struct tty *tp;
	register int unit;
 
	unit = minor(dev);
	if (unit >= ss_cnt || sspdma[unit].p_addr == 0)
		return (ENXIO);
	tp = &ss_tty[unit];
	tp->t_addr = (caddr_t)&sspdma[unit];
	tp->t_oproc = ssstart;
	if ((tp->t_state & TS_ISOPEN) == 0) {
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
		ssparam(unit);
	} else if (tp->t_state&TS_XCLUDE && u.u_uid != 0)
		return (EBUSY);
	if (unit == 2)
		bv_regs.bvr_sermctl = SSMCTL_DTR | SSMCTL_RTS;
	(void) spl5();
	while ((tp->t_state & TS_CARR_ON) == 0) {
		tp->t_state |= TS_WOPEN;
		sleep((caddr_t)&tp->t_rawq, TTIPRI);
	}
	(void) spl0();
	return ((*linesw[tp->t_line].l_open)(dev, tp));
}
 
/*ARGSUSED*/
ssclose(dev, flag)
	dev_t dev;
{
	register struct tty *tp;
	register int unit;
	int ss;
 
	unit = minor(dev);
	ss = unit >> 2;
	tp = &ss_tty[unit];
	(*linesw[tp->t_line].l_close)(tp);
	bv_regs.bvr_serbrk = (ss_brk[ss] &= ~(1 << (unit&03)));
	if ((tp->t_state&(TS_HUPCLS|TS_WOPEN)) || (tp->t_state&TS_ISOPEN) == 0)
		bv_regs.bvr_sermctl = 0;
	ttyclose(tp);
}
 
ssread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register struct tty *tp;
 
	tp = &ss_tty[minor(dev)];
	return ((*linesw[tp->t_line].l_read)(tp, uio));
}
 
sswrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register struct tty *tp;
 
	tp = &ss_tty[minor(dev)];
	return ((*linesw[tp->t_line].l_write)(tp, uio));
}
 
/*ARGSUSED*/
ssrint(ss)
	int ss;
{
	register struct tty *tp;
	register int c;
	register struct tty *tp0;
	register int unit;
	int overrun = 0;
 
	if ((ssact & (1<<ss)) == 0)
		return;
	unit = ss * 4;
	tp0 = &ss_tty[unit];
	while ((c = bv_regs.bvr_serrbuf) < 0) {	/* char present */
		sschars[ss]++;
		tp = tp0 + ((c>>8)&03);
		if (tp >= &ss_tty[ss_cnt])
			continue;
		if ((tp->t_state & TS_ISOPEN) == 0) {
			wakeup((caddr_t)&tp->t_rawq);
#ifdef PORTSELECTOR
			if ((tp->t_state&TS_WOPEN) == 0)
#endif
				continue;
		}
		if (c&SSRBUF_FE)
			if (tp->t_flags & RAW)
				c = 0;
			else
				c = tp->t_intrc;
		if (c&SSRBUF_DO && overrun == 0) {
			log(LOG_WARNING, "ss%d,%d: silo overflow\n", ss, (c>>8)&3);
			overrun = 1;
		}
		if (c&SSRBUF_PE)	
			if (((tp->t_flags & (EVENP|ODDP)) == EVENP)
			  || ((tp->t_flags & (EVENP|ODDP)) == ODDP))
				continue;
#if NBK > 0
		if (tp->t_line == NETLDISC) {
			c &= 0177;
			BKINPUT(c, tp);
		} else
#endif
			(*linesw[tp->t_line].l_rint)(c, tp);
	}
}
 
/*ARGSUSED*/
ssioctl(dev, cmd, data, flag)
	dev_t dev;
	caddr_t data;
{
	register struct tty *tp;
	register int unit = minor(dev);
	register int ss = unit >> 2;
	int error;
 
	tp = &ss_tty[unit];
	error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
	if (error >= 0)
		return (error);
	error = ttioctl(tp, cmd, data, flag);
	if (error >= 0) {
		if (cmd == TIOCSETP || cmd == TIOCSETN || cmd == TIOCLBIS ||
		    cmd == TIOCLBIC || cmd == TIOCLSET)
			ssparam(unit);
		return (error);
	}
	switch (cmd) {

	case TIOCSBRK:
		bv_regs.bvr_serbrk = (ss_brk[ss] |= 1 << (unit&03));
		break;

	case TIOCCBRK:
		bv_regs.bvr_serbrk = (ss_brk[ss] &= ~(1 << (unit&03)));
		break;

	case TIOCSDTR:
		if (unit != 2)
			goto nomodem;
		bv_regs.bvr_sermctl |= SSMCTL_DTR | SSMCTL_RTS;
		break;

	case TIOCCDTR:
		if (unit != 2)
			goto nomodem;
		bv_regs.bvr_sermctl &= ~(SSMCTL_DTR | SSMCTL_RTS);
		break;

	case TIOCMSET:
		if (unit != 2)
			goto nomodem;
		(void) ssmctl(dev, dmtoss(*(int *)data), DMSET);
		break;

	case TIOCMBIS:
		if (unit != 2)
			goto nomodem;
		(void) ssmctl(dev, dmtoss(*(int *)data), DMBIS);
		break;

	case TIOCMBIC:
		if (unit != 2)
			goto nomodem;
		(void) ssmctl(dev, dmtoss(*(int *)data), DMBIC);
		break;

	case TIOCMGET:
		if (unit != 2)
			goto nomodem;
		*(int *)data = sstodm(ssmctl(dev, 0, DMGET));
		break;

	default:
	nomodem:
		return (ENOTTY);
	}
	return (0);
}

dmtoss(bits)
	register int bits;
{
	register int b;

	b = 0;
	if (bits & DML_RTS) b |= SSL_RTS;
	if (bits & DML_DTR) b |= SSL_DTR;
	return(b);
}

sstodm(bits)
	register int bits;
{
	register int b;

	b = 0;
	if (bits & SSL_DTR) b |= DML_DTR;
	if (bits & SSL_RTS) b |= DML_RTS;
	if (bits & SSL_CD)  b |= DML_CAR;
	if (bits & SSL_DSR) b |= DML_DSR;
	if (bits & SSL_CTS) b |= DML_CTS;
	if (bits & SSL_RI)  b |= DML_RNG;
	return(b);
}
 
ssparam(unit)
	register int unit;
{
	register struct tty *tp;
	register int lpr;
 
	tp = &ss_tty[unit];
	if (sssilos & (1 << (unit >> 2)))
		bv_regs.bvr_sercsr = SSCSR_MSE | SSCSR_SAE;
	else
		bv_regs.bvr_sercsr = SSCSR_MSE;
	ssact |= (1<<(unit>>2));
	bv_regs.bvr_intmsk |= BVINT_SR | BVINT_ST;
	if (tp->t_ispeed == 0) {
		if (unit == 2)
			bv_regs.bvr_sermctl = 0;
		return;
	}
	lpr = (ss_speeds[tp->t_ispeed]<<8) | (unit & 03);
	if (tp->t_flags & (RAW|LITOUT|PASS8))
		lpr |= SSLPR_BITS8;
	else
		lpr |= (SSLPR_BITS7|SSLPR_PENABLE);
	if ((tp->t_flags & EVENP) == 0)
		lpr |= SSLPR_OPAR;
	if (tp->t_ispeed == B110)
		lpr |= SSLPR_TWOSB;
	bv_regs.bvr_serlpr = lpr;
}
 
ssxint(tp)
	register struct tty *tp;
{
	register struct pdma *dp;
	register ss, unit;
 
	dp = (struct pdma *)tp->t_addr;
	tp->t_state &= ~TS_BUSY;
	if (tp->t_state & TS_FLUSH)
		tp->t_state &= ~TS_FLUSH;
	else {
		ndflush(&tp->t_outq, dp->p_mem-tp->t_outq.c_cf);
		dp->p_end = dp->p_mem = tp->t_outq.c_cf;
	}
	if (tp->t_line)
		(*linesw[tp->t_line].l_start)(tp);
	else
		ssstart(tp);
	ss = minor(tp->t_dev) >> 2;
	unit = minor(tp->t_dev) & 3;
	if (tp->t_outq.c_cc == 0 || (tp->t_state&TS_BUSY)==0)
		bv_regs.bvr_sertcr &= ~(1<<unit);
}

ssstart(tp)
	register struct tty *tp;
{
	register struct pdma *dp;
	register int cc;
	int s, ss, unit;
 
	dp = (struct pdma *)tp->t_addr;
	s = spl5();
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
	if (tp->t_flags & (RAW|LITOUT|PASS8))
		cc = ndqb(&tp->t_outq, 0);
	else {
		cc = ndqb(&tp->t_outq, 0200);
		if (cc == 0) {
			cc = getc(&tp->t_outq);
			timeout(ttrstrt, (caddr_t)tp, (cc&0x7f) + 6);
			tp->t_state |= TS_TIMEOUT;
			goto out;
		}
	}
	tp->t_state |= TS_BUSY;
	dp->p_end = dp->p_mem = tp->t_outq.c_cf;
	dp->p_end += cc;
	ss = minor(tp->t_dev) >> 2;
	unit = minor(tp->t_dev) & 3;
	bv_regs.bvr_sertcr |= (1<<unit);
out:
	splx(s);
}
 
/*
 * Stop output on a line.
 */
/*ARGSUSED*/
ssstop(tp, flag)
	register struct tty *tp;
{
	register struct pdma *dp;
	register int s;

	dp = (struct pdma *)tp->t_addr;
	s = spl5();
	if (tp->t_state & TS_BUSY) {
		dp->p_end = dp->p_mem;
		if ((tp->t_state&TS_TTSTOP)==0)
			tp->t_state |= TS_FLUSH;
	}
	splx(s);
}
 
ssmctl(dev, bits, how)
	dev_t dev;
	int bits, how;
{
	register int mbits;
	int s;

	s = spl5();
	mbits = (bv_regs.bvr_sermctl << 16) | bv_regs.bvr_sermsr;
	switch (how) {
	case DMSET:
		mbits = bits;
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
	bv_regs.bvr_sermctl = mbits >> 16;
	(void) splx(s);
	return(mbits);
}
 
int sstransitions, ssfasttimers;		/*DEBUG*/
ssscan()
{
	register i;
	register bit;
	register struct tty *tp;
	register car;
	int oldsssilos = sssilos;
	int sstimer();
 
	for (i = 0; i < ss_cnt ; i++) {
		if (sspdma[i].p_addr == 0)
			continue;
		tp = &ss_tty[i];
		bit = 1<<(i&03);
		car = 0;
		if (sssoftCAR[i>>2]&bit)
			car = 1;
		else
			car = bv_regs.bvr_sermsr&bit;
		if (car) {
			/* carrier present */
			if ((tp->t_state & TS_CARR_ON) == 0)
				(void)(*linesw[tp->t_line].l_modem)(tp, 1);
		} else if ((tp->t_state&TS_CARR_ON) &&
		    (*linesw[tp->t_line].l_modem)(tp, 0) == 0 && i == 2)
			bv_regs.bvr_sermctl = 0;
	}
	for (i = 0; i < NSS; i++) {
		ave(ssrate[i], sschars[i], 8);
		if (sschars[i] > sshighrate && ((sssilos & (1 << i)) == 0)) {
			bv_regs.bvr_sercsr = SSCSR_MSE | SSCSR_SAE;
			sssilos |= (1 << i);
			sstransitions++;		/*DEBUG*/
		} else if ((sssilos & (1 << i)) && (ssrate[i] < sslowrate)) {
			bv_regs.bvr_sercsr = SSCSR_MSE;
			sssilos &= ~(1 << i);
		}
		sschars[i] = 0;
	}
	if (sssilos && !oldsssilos)
		timeout(sstimer, (caddr_t)0, sstimerintvl);
	timeout(ssscan, (caddr_t)0, hz);
}

sstimer()
{
	register int ss;
	register int s;

	if (sssilos == 0)
		return;
	s = spl5();
	ssfasttimers++;		/*DEBUG*/
	for (ss = 0; ss < NSS; ss++)
		if (sssilos & (1 << ss))
		    ssrint(ss);
	splx(s);
	timeout(sstimer, (caddr_t) 0, sstimerintvl);
}
#endif
