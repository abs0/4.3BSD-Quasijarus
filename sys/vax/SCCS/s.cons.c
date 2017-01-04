h13494
s 00001/00001/00275
d D 7.6 03/03/16 04:03:58 msokolov 37 36
c Don't interpret output high chars as delays in PASS8 mode
e
s 00003/00003/00273
d D 7.5 88/05/07 14:19:19 karels 36 35
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00002/00002/00274
d D 7.4 88/01/28 10:09:59 karels 35 34
c good thing r11 wasn't 0 (I think)
e
s 00002/00001/00274
d D 7.3 87/04/16 17:50:22 karels 34 33
c check console window for open, carrier before redirecting
e
s 00072/00009/00203
d D 7.2 87/02/21 11:18:55 karels 33 32
c kdb (for sam; untested); misc.
e
s 00001/00001/00211
d D 7.1 86/06/05 00:41:57 mckusick 32 31
c 4.3BSD release version
e
s 00007/00001/00205
d D 6.3 85/06/08 13:40:44 mckusick 31 30
c Add copyright
e
s 00012/00012/00194
d D 6.2 84/08/28 18:09:17 bloom 30 29
c Change to includes.  No more ../h
e
s 00000/00000/00206
d D 6.1 83/07/29 07:19:32 sam 29 28
c 4.2 distribution
e
s 00005/00008/00201
d D 4.19 82/12/05 21:49:46 sam 28 27
c reorganized tty structure and delete old comment
e
s 00001/00000/00208
d D 4.18 82/10/17 15:24:46 root 27 26
c fix lint
e
s 00011/00010/00197
d D 4.17 82/10/17 12:01:37 root 26 25
c return errors from open/ioctl routines; update conf table for
e
s 00027/00033/00180
d D 4.16 82/10/13 22:13:33 root 25 24
c rearrange header files
e
s 00004/00003/00209
d D 4.15 82/08/22 21:19:22 root 24 23
c fully uio()'d
e
s 00003/00002/00209
d D 4.14 82/08/13 00:28:45 root 23 22
c read with uio
e
s 00001/00000/00210
d D 4.13 82/03/13 12:50:17 sam 22 21
c lint
e
s 00018/00011/00192
d D 4.12 82/01/14 17:04:59 wnj 21 20
c early non-blocking stuff
e
s 00001/00006/00202
d D 4.11 81/10/11 11:47:32 wnj 20 19
c first boot with select()
e
s 00001/00001/00207
d D 4.10 81/05/09 19:46:35 root 19 18
c bug fix with padding
e
s 00010/00011/00198
d D 4.9 81/05/05 21:52:38 wnj 18 17
c fix console bug which loses console when delay on output
e
s 00003/00008/00206
d D 4.8 81/03/11 18:33:29 wnj 17 16
c cleanup
e
s 00001/00001/00213
d D 4.7 81/03/09 01:52:28 wnj 16 15
c %G% -> %E%
e
s 00001/00013/00213
d D 4.6 81/03/09 00:32:53 wnj 15 14
c lint
e
s 00000/00000/00226
d D 4.5 81/02/26 22:19:40 wnj 14 13
c conditionally discard NETLDISC cruft
e
s 00009/00015/00217
d D 4.4 81/02/25 23:38:15 wnj 13 12
c fix for combined version
e
s 00019/00001/00213
d D 4.3 80/12/17 10:32:29 wnj 12 11
c changes for 750 (bad console done flag)
e
s 00001/00000/00213
d D 4.2 80/11/09 23:12:36 bill 11 10
c include ../h/mx.h for lint's sake
e
s 00000/00000/00213
d D 4.1 80/11/09 16:52:06 bill 10 9
c stamp for 4bsd
e
s 00001/00001/00212
d D 3.9 80/09/27 17:59:52 bill 9 8
c 4dz's plus LOWAT and HIWAT ala speed
e
s 00001/00001/00212
d D 3.8 80/09/20 20:38:33 bill 8 7
c ttioctl
e
s 00001/00001/00212
d D 3.7 80/09/09 20:03:05 bill 7 6
c typo
e
s 00004/00016/00209
d D 3.6 80/06/22 12:26:32 bill 6 5
c putchar is now in prf.c, cnchar here does dirty work
e
s 00001/00001/00224
d D 3.5 80/06/07 02:44:50 bill 5 4
c %H%->%G%
e
s 00001/00001/00224
d D 3.4 80/05/18 11:31:58 bill 4 3
c s/tp->t_char/tp->t_chan/
e
s 00013/00001/00212
d D 3.3 80/05/09 20:54:46 bill 3 2
c run spl6 for dz SAE
e
s 00061/00042/00152
d D 3.2 80/05/08 10:12:51 bill 2 1
c newspeak with line disciplines
e
s 00194/00000/00000
d D 3.1 80/04/09 16:03:02 bill 1 0
c date and time created 80/04/09 16:03:02 by bill
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%H%	*/
E 5
I 5
D 16
/*	%M%	%I%	%G%	*/
E 16
I 16
D 31
/*	%M%	%I%	%E%	*/
E 31
I 31
/*
D 32
 * Copyright (c) 1982 Regents of the University of California.
E 32
I 32
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 32
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 31
E 16
E 5

/*
D 3
 *   Vax console driver and floppy interface
E 3
I 3
D 28
 * Vax console driver and floppy interface
I 13
 *
D 17
 * WE AVOID USE THE READY BIT IN TXCS BECAUSE IT DOESN'T
 * WORK ON AN 11/750 WITH AN RDM PLUGGED IN.
E 17
I 17
 * Note:
 *	We avoid use the ready bit in txcs because it doesn't
 *	work on an 11/750 with an rdm plugged in.
E 28
I 28
 * VAX console driver (and floppy interface)
E 28
E 17
E 13
E 3
 */
D 30
#include "../h/param.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
I 22
#include "../h/proc.h"
I 28
#include "../h/ioctl.h"
E 28
E 22
#include "../h/tty.h"
#include "../h/systm.h"
I 27
#include "../h/uio.h"
E 30
I 30
#include "param.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "ioctl.h"
#include "tty.h"
#include "systm.h"
#include "uio.h"
E 30
E 27
D 25
#include "../h/cons.h"
#include "../h/mtpr.h"
I 11
D 20
#include "../h/mx.h"
E 20
I 13
#include "../h/cpu.h"
E 25
E 13
E 11
I 3
D 17

D 15
/*
 * When running dz's using only SAE (silo alarm) on input
 * it is necessary to call dzrint() at clock interrupt time.
 * This is unsafe unless spl5()s in tty code are changed to
 * spl6()s to block clock interrupts.  Note that the dh driver
 * currently in use works the same way as the dz, even though
 * we could try to more intelligently manage its silo.
 * Thus don't take this out if you have no dz's unless you
 * change clock.c and dhtimer().
 */
#define	spl5	spl6
E 3

E 15
#define	NL1	000400
#define	NL2	001000
#define	CR2	020000
#define	FF1	040000
#define	TAB1	002000
E 17

I 25
D 30
#include "../vax/cpu.h"
#include "../vax/cons.h"
#include "../vax/mtpr.h"
E 30
I 30
#include "cpu.h"
#include "cons.h"
#include "mtpr.h"
E 30

I 33
/*
 * On some machines (e.g. MicroVAX), a secondary console
 * such as a display may supercede the standard serial console.
 * On such machines, consops will be set to point to the cdevsw
 * entry for the secondary console, and the standard console device
 * (minor number 0) will be redirected.  Other minor numbers still
 * refer to the standard console serial line.
 *
 * Also, console output may be redirected to another tty
 * (e.g. a window); if so, constty will point to the current
 * virtual console.
 */
struct	cdevsw *consops = 0;
struct	tty *constty = 0;
E 33
E 25
struct	tty cons;
int	cnstart();
int	ttrstrt();
char	partab[];

/*ARGSUSED*/
cnopen(dev, flag)
D 25
dev_t dev;
E 25
I 25
	dev_t dev;
E 25
{
D 25
	register struct tty *tp;
E 25
I 25
	register struct tty *tp = &cons;
E 25

I 33
	if (consops && minor(dev) == 0)
		return ((*consops->d_open)(dev, flag));
E 33
D 25
	tp = &cons;
E 25
	tp->t_oproc = cnstart;
D 20
	tp->t_iproc = NULL;
E 20
D 21
	if ((tp->t_state&ISOPEN) == 0) {
E 21
I 21
	if ((tp->t_state&TS_ISOPEN) == 0) {
E 21
		ttychars(tp);
D 21
		tp->t_state = ISOPEN|CARR_ON;
E 21
I 21
		tp->t_state = TS_ISOPEN|TS_CARR_ON;
E 21
		tp->t_flags = EVENP|ECHO|XTABS|CRMOD;
	}
I 2
D 21
	if (tp->t_state&XCLUDE && u.u_uid != 0) {
E 21
I 21
D 26
	if (tp->t_state&TS_XCLUDE && u.u_uid != 0) {
E 21
		u.u_error = EBUSY;
		return;
	}
E 26
I 26
	if (tp->t_state&TS_XCLUDE && u.u_uid != 0)
		return (EBUSY);
E 26
E 2
	mtpr(RXCS, mfpr(RXCS)|RXCS_IE);
	mtpr(TXCS, mfpr(TXCS)|TXCS_IE);
D 2
	ttyopen(dev, tp);
E 2
I 2
D 26
	(*linesw[tp->t_line].l_open)(dev, tp);
E 26
I 26
	return ((*linesw[tp->t_line].l_open)(dev, tp));
E 26
E 2
}

/*ARGSUSED*/
cnclose(dev)
D 25
dev_t dev;
E 25
I 25
	dev_t dev;
E 25
{
D 25
	register struct tty *tp;
E 25
I 25
	register struct tty *tp = &cons;
E 25

I 33
	if (consops && minor(dev) == 0)
		return ((*consops->d_close)(dev));
E 33
D 25
	tp = &cons;
E 25
D 2
	wflushtty(tp);
	tp->t_state = 0;
E 2
I 2
	(*linesw[tp->t_line].l_close)(tp);
	ttyclose(tp);
I 35
	return (0);
E 35
E 2
}

/*ARGSUSED*/
D 23
cnread(dev)
E 23
I 23
cnread(dev, uio)
E 23
D 25
dev_t dev;
I 23
struct uio *uio;
E 25
I 25
	dev_t dev;
	struct uio *uio;
E 25
E 23
{
I 2
D 25
	register struct tty *tp;
E 25
I 25
	register struct tty *tp = &cons;
E 25
E 2

I 33
	if (consops && minor(dev) == 0)
		return ((*consops->d_read)(dev, uio));
E 33
D 2
	ttread(&cons);
E 2
I 2
D 25
	tp = &cons;
D 23
	(*linesw[tp->t_line].l_read)(tp);
E 23
I 23
	(*linesw[tp->t_line].l_read)(tp, uio);
E 25
I 25
	return ((*linesw[tp->t_line].l_read)(tp, uio));
E 25
E 23
E 2
}

/*ARGSUSED*/
D 24
cnwrite(dev)
dev_t dev;
E 24
I 24
cnwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
E 24
{
D 2

	ttwrite(&cons);
}

/*
 * Got a level-20 transmission interrupt -
 * the LSI wants another character.  First,
 * see if we can send something to the typewriter.
 * If not, try the floppy.
 */
/*ARGSUSED*/
cnxint(dev)
dev_t dev;
{

	if (cnxtty() == 0)
		conxfl();
}

/*
 * Formerly cnxint -
 * called by new cnxint to see if there are
 * any characters to write to the console, and,
 * if there are, to do it.
 */
cnxtty()
{
E 2
D 25
	register struct tty *tp;
E 25
I 25
	register struct tty *tp = &cons;
E 25

I 33
	if (minor(dev) == 0) {
D 34
		if (constty)
E 34
I 34
		if (constty && (constty->t_state & (TS_CARR_ON | TS_ISOPEN)) ==
		    (TS_CARR_ON | TS_ISOPEN))
E 34
			tp = constty;
		else if (consops)
			return ((*consops->d_write)(dev, uio));
	}
E 33
D 25
	tp = &cons;
D 2
	if (tp->t_outq.c_cc == 0)
		return(0);
	ttstart(tp);
	if (tp->t_outq.c_cc == 0 || tp->t_outq.c_cc == TTLOWAT)
		wakeup((caddr_t)&tp->t_outq);
	return(1);
E 2
I 2
D 24
	(*linesw[tp->t_line].l_write)(tp);
E 24
I 24
	(*linesw[tp->t_line].l_write)(tp, uio);
E 25
I 25
	return ((*linesw[tp->t_line].l_write)(tp, uio));
E 25
E 24
E 2
}

I 33
static	int cnpolling = 0;
E 33
/*
 * Got a level-20 receive interrupt -
 * the LSI wants to give us a character.
 * Catch the character, and see who it goes to.
 */
/*ARGSUSED*/
cnrint(dev)
D 25
dev_t dev;
E 25
I 25
	dev_t dev;
E 25
{
	register int c;
I 2
	register struct tty *tp;
E 2

I 33
	if (cnpolling)
		return;
E 33
	c = mfpr(RXDB);
D 2
	if ((c&RXDB_ID)==0)		/* look at source byte */
		ttyinput(c, &cons);	/* character from typewriter */
	else
		cnrfl(c);		/* character from floppy */
E 2
I 2
	if (c&RXDB_ID) {
I 12
D 13
#if VAX==780
E 12
		cnrfl(c);
E 13
I 13
#if VAX780
		if (cpu == VAX_780)
			cnrfl(c);
E 13
I 12
#endif
E 12
		return;
	}
	tp = &cons;
I 33
D 36
#ifdef KDB
E 36
I 36
#ifdef KADB
E 36
	if (!kdbrintr(c, tp))
#endif
E 33
	(*linesw[tp->t_line].l_rint)(c, tp);
E 2
}

/*ARGSUSED*/
cnioctl(dev, cmd, addr, flag)
D 25
dev_t dev;
caddr_t addr;
E 25
I 25
	dev_t dev;
	caddr_t addr;
E 25
{
D 25
	register struct tty *tp;
E 25
I 25
	register struct tty *tp = &cons;
I 26
	int error;
E 26
E 25
 
I 33
	if (consops && minor(dev) == 0)
		return ((*consops->d_ioctl)(dev, cmd, addr, flag));
E 33
D 25
	tp = &cons;
E 25
D 2
	if (ttioccom(cmd, tp, addr, dev) ==0)
E 2
I 2
D 26
	cmd = (*linesw[tp->t_line].l_ioctl)(tp, cmd, addr);
	if (cmd == 0)
		return;
D 7
	if (ttioccom(cmd, tp, addr, dev) == 0)
E 7
I 7
D 8
	if (ttioccomm(cmd, tp, addr, dev) == 0)
E 8
I 8
D 12
	if (ttioctl(cmd, tp, addr, dev, flag) == 0)
E 12
I 12
	if (ttioctl(tp, cmd, addr, flag) == 0)
E 12
E 8
E 7
E 2
		u.u_error = ENOTTY;
E 26
I 26
	error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, addr);
	if (error >= 0)
		return (error);
	error = ttioctl(tp, cmd, addr, flag);
	if (error < 0)
		error = ENOTTY;
	return (error);
E 26
}

I 12
D 13
#if VAX==750
E 13
int	consdone = 1;
D 13
#endif
E 13
E 12
I 2
/*
 * Got a level-20 transmission interrupt -
 * the LSI wants another character.  First,
 * see if we can send something to the typewriter.
 * If not, try the floppy.
 */
/*ARGSUSED*/
cnxint(dev)
D 25
dev_t dev;
E 25
I 25
	dev_t dev;
E 25
{
D 25
	register struct tty *tp;
E 25
I 25
	register struct tty *tp = &cons;
E 25

I 12
D 13
#if VAX==750
E 13
	consdone++;
D 13
#endif
E 13
E 12
D 25
	tp = &cons;
E 25
D 21
	tp->t_state &= ~BUSY;
E 21
I 21
	tp->t_state &= ~TS_BUSY;
E 21
	if (tp->t_line)
		(*linesw[tp->t_line].l_start)(tp);
	else
		cnstart(tp);
I 12
D 13
#if VAX==780
E 12
	if ((tp->t_state & BUSY) == 0)
E 13
I 13
#if VAX780
D 15
	if (vax==VAX_780 && (tp->t_state & BUSY) == 0)
E 15
I 15
D 21
	if (cpu==VAX_780 && (tp->t_state & BUSY) == 0)
E 21
I 21
	if (cpu==VAX_780 && (tp->t_state & TS_BUSY) == 0)
E 21
E 15
E 13
		conxfl();
I 12
#endif
E 12
}

E 2
cnstart(tp)
D 25
register struct tty *tp;
E 25
I 25
	register struct tty *tp;
E 25
{
D 25
	register c;
I 2
	register s;
E 25
I 25
	register int c, s;
E 25
E 2

I 2
	s = spl5();
D 21
	if (tp->t_state & (TIMEOUT|BUSY|TTSTOP))
E 21
I 21
	if (tp->t_state & (TS_TIMEOUT|TS_BUSY|TS_TTSTOP))
E 21
		goto out;
D 9
	if (tp->t_outq.c_cc <= TTLOWAT && tp->t_state&ASLEEP) {
E 9
I 9
D 21
	if (tp->t_state&ASLEEP && tp->t_outq.c_cc <= TTLOWAT(tp)) {
E 9
		tp->t_state &= ~ASLEEP;
D 20
		if (tp->t_chan)
D 4
			mcstart(tp->t_char, (caddr_t)&tp->t_outq);
E 4
I 4
			mcstart(tp->t_chan, (caddr_t)&tp->t_outq);
E 4
		else
			wakeup((caddr_t)&tp->t_outq);
E 20
I 20
		wakeup((caddr_t)&tp->t_outq);
E 21
I 21
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
E 21
E 20
	}
	if (tp->t_outq.c_cc == 0)
		goto out;
I 12
D 13
#if VAX==750
E 13
	if (consdone == 0)
D 33
		return;
D 13
#else
E 12
E 2
	if ((mfpr(TXCS)&TXCS_RDY) == 0)
		return;
I 12
#endif
E 13
E 12
D 18
	if ((c=getc(&tp->t_outq)) >= 0) {
I 12
D 13
#if VAX==750
E 13
		consdone = 0;
D 13
#endif
E 13
E 12
		if (tp->t_flags&RAW)
			mtpr(TXDB, c&0xff);
		else if (c<=0177)
			mtpr(TXDB, (c | (partab[c]&0200))&0xff);
		else {
			timeout(ttrstrt, (caddr_t)tp, (c&0177));
			tp->t_state |= TIMEOUT;
I 2
			goto out;
E 2
		}
E 18
I 18
	c = getc(&tp->t_outq);
D 19
	if (tp->t_flags&RAW)
E 19
I 19
D 28
	if (tp->t_flags&RAW || tp->t_local&LLITOUT)
E 28
I 28
	if (tp->t_flags&(RAW|LITOUT))
E 28
E 19
		mtpr(TXDB, c&0xff);
D 28
	else if (c<=0177)
E 28
I 28
	else if (c <= 0177)
E 28
		mtpr(TXDB, (c | (partab[c]&0200))&0xff);
	else {
		timeout(ttrstrt, (caddr_t)tp, (c&0177));
D 21
		tp->t_state |= TIMEOUT;
E 21
I 21
		tp->t_state |= TS_TIMEOUT;
E 33
E 21
		goto out;
I 33
	c = getc(&tp->t_outq) & 0xff;
D 37
	if ((tp->t_flags & (RAW|LITOUT)) == 0) {
E 37
I 37
	if ((tp->t_flags & (RAW|LITOUT|PASS8)) == 0) {
E 37
		if (c <= 0177)
			c |= (partab[c] & 0200);
		else {
			timeout(ttrstrt, (caddr_t)tp, (c&0177));
			tp->t_state |= TS_TIMEOUT;
			goto out;
		}
E 33
E 18
	}
I 33
	mtpr(TXDB, c);
E 33
I 18
	consdone = 0;
E 18
I 2
D 21
	tp->t_state |= BUSY;
E 21
I 21
	tp->t_state |= TS_BUSY;
E 21
D 28
    out:
E 28
I 28
out:
E 28
	splx(s);
E 2
}

D 6
char	*msgbufp = msgbuf;	/* Next saved printf character */
E 6
/*
 * Print a character on console.
 * Attempts to save and restore device
 * status.
D 6
 * If the switches are 0, all
 * printing is inhibited.
 *
 * Whether or not printing is inhibited,
 * the last MSGBUFS characters
 * are saved in msgbuf for inspection later.
E 6
 */
D 6
putchar(c)
E 6
I 6
cnputc(c)
E 6
D 25
register c;
E 25
I 25
	register int c;
E 25
{
D 25
	register s, timo;
E 25
I 25
	register int s, timo;
E 25

D 6
	if (c != '\0' && c != '\r' && c != 0177) {
		*msgbufp++ = c;
		if(msgbufp >= &msgbuf[MSGBUFS])
			msgbufp = msgbuf;
	}
E 6
	timo = 30000;
	/*
	 * Try waiting for the console tty to come ready,
	 * otherwise give up after a reasonable time.
	 */
D 25
	while((mfpr(TXCS)&TXCS_RDY) == 0)
E 25
I 25
	while ((mfpr(TXCS)&TXCS_RDY) == 0)
E 25
		if(--timo == 0)
			break;
D 25
	if(c == 0)
E 25
I 25
	if (c == 0)
E 25
		return;
	s = mfpr(TXCS);
D 6
	mtpr(TXCS,0);
E 6
I 6
	mtpr(TXCS, 0);
E 6
	mtpr(TXDB, c&0xff);
D 25
	if(c == '\n')
E 25
I 25
	if (c == '\n')
E 25
D 6
		putchar('\r');
	putchar(0);
E 6
I 6
		cnputc('\r');
	cnputc(0);
E 6
	mtpr(TXCS, s);
}
I 33

D 36
#if defined(KDB) || defined(GENERIC)
E 36
I 36
#if (defined(KADB) || defined(GENERIC)) && !defined(lint)
E 36
/*
 * Get character from console.
 */
cngetc()
{
	register int c, s;

	s = splhigh();
D 35
	while (c == 0 ||
	    (mfpr(RXCS)&RXCS_DONE) == 0 || (c = mfpr(RXDB)&0177) < 0)
E 35
I 35
	while ((mfpr(RXCS)&RXCS_DONE) == 0 || (c = mfpr(RXDB)&0177) <= 0)
E 35
		;
	if (c == '\r')
		c = '\n';
	(void) splx(s);
	return (c);
}
#endif

D 36
#ifdef KDB
E 36
I 36
#ifdef KADB
E 36
cnpoll(onoff)
	int onoff;
{

	cnpolling = onoff;
}
#endif
E 33
E 1
