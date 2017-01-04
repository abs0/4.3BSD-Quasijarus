h00620
s 00001/00001/00604
d D 7.1 86/06/05 01:12:01 mckusick 14 13
c 4.3BSD release version
e
s 00007/00007/00598
d D 6.4 86/02/23 23:17:23 karels 13 12
c lint
e
s 00007/00001/00598
d D 6.3 85/06/08 14:18:08 mckusick 12 11
c Add copyright
e
s 00008/00008/00591
d D 6.2 84/08/29 20:08:47 bloom 11 10
c Change to includes.  No more ../h
e
s 00000/00000/00599
d D 6.1 83/07/29 07:28:07 sam 10 9
c 4.2 distribution
e
s 00005/00002/00594
d D 4.9 82/10/20 02:08:37 root 9 8
c lint
e
s 00009/00022/00587
d D 4.8 82/10/17 11:49:37 root 8 7
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00064/00125/00545
d D 4.7 82/10/10 22:37:56 root 7 6
c minor fixes relating to u.u_error handling
e
s 00003/00001/00667
d D 4.6 82/10/10 17:27:51 root 6 5
c header files for vax are in their place
e
s 00027/00025/00641
d D 4.5 82/08/22 21:18:45 root 5 4
c fully uio()'d
e
s 00004/00002/00662
d D 4.4 82/08/13 00:15:58 root 4 3
c changes for char dev uio'ing
e
s 00009/00013/00655
d D 4.3 82/08/01 19:25:31 sam 3 2
c new ioctl's
e
s 00001/00001/00667
d D 4.2 82/07/15 19:59:52 kre 2 1
c probe routines return size of unibus dev regs to reserve space
e
s 00668/00000/00000
d D 4.1 82/05/27 17:02:06 sam 1 0
c date and time created 82/05/27 17:02:06 by sam
e
u
U
t
T
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12
I 6

E 6
#include "lpa.h"
#if NLPA > 0

D 11
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
D 6
#include "../h/ubavar.h"
E 6
#include "../h/proc.h"
#include "../h/ioctl.h"
I 4
#include "../h/uio.h"
E 11
I 11
#include "param.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "proc.h"
#include "ioctl.h"
#include "uio.h"
E 11
I 6

D 11
#include "../vaxuba/ubavar.h"
E 11
I 11
#include "ubavar.h"
E 11
E 6
E 4

/*
D 7
 *	LPA driver for 4.1BSD
 *	Asa Romberger
 * method of usage:
E 7
I 7
 * LPA driver for -- Asa Romberger
 *
E 7
 *	open
 *	write microcode
 *	write dedicated mode dispatch table
 *	ioctl TIOCSETP to set parameters
 *		struct iocb {
 *			short *baddr;	buffer address
 *			short rate;	- 1,000,000 / frequency in Hz
 *			short wc;	15-13 = number of buffers - 1
 *					12-0 = buffer size in words
 *		} iocb;
 *	read - 1 character indicating buffer index
 *		fill or empty buffer
 * minor device number = DDCCCCCC where:
 *	DD	= 00 for analog input
 *		= 01 for analog output
 *	CCCCCC	= channel number
 */
D 7
/*
 *	define TRACELPA to get trace printouts on the console
E 7
 *	define NOMCODE to eliminate the microcode download check
 */
D 7
/*	#define	NOMCODE		*/
E 7
I 7
/* #define TRACELPA */
/* #define NOMCODE */
E 7

#ifdef TRACELPA
#	define TRACER(x)	printf(x)
#	define TRACERN(x, d)	printf(x, d)
#else
#	define TRACER(x)
#	define TRACERN(x, d)
#endif

	/* PRIORITY AT WHICH PROGRAM SHOULD RUN */
	/* THIS SHOULD EVENTUALLY  TELL UNIX THIS IS A REAL-TIME DEVICE */

#define NICE	0

D 7
	/* WAKEUP PRIORITY */
E 7
I 7
#define inc(v)		(sc->v = ((sc->v + 1) % sc->sc_nbuf))
E 7

D 7
#define LPAPRI	(PZERO + 0)

	/* MACRO DEFINITIONS */
#define inc(v)	(sc->v = ((sc->v + 1) % sc->sc_nbuf))
E 7
I 7
#define LPAPRI		(PZERO + 0)
E 7
#define LPAUNIT(dev)	0
#define LPADEVICE(dev)	(((dev) >> 6) & 03)
#define LPACHANNEL(dev)	((dev) & 077)

D 7
	/* DEFINITIONS FOR INTERACTION WITH UNIX I/O */

int lpaprobe(), /*lpaslave(),*/ lpaattach() /*,lpadgo()*/;
int lpaiintr(), lpaointr();
u_short lpastd[] = {0170460, 0};
struct uba_device *lpadinfo[NLPA];
/*struct uba_ctlr *lpaminfo[Ndevice name];*/
E 7
I 7
int	lpaprobe(), lpaattach(), lpaiintr(), lpaointr();
u_short	lpastd[] = {0170460, 0};
struct	uba_device *lpadinfo[NLPA];
E 7
struct uba_driver lpadriver =
D 7
	{lpaprobe, 0/*lpaslave*/, lpaattach, 0/*lpadgo*/, lpastd,
	"lpa", lpadinfo, 0/*"device name"*/, 0/*lpaminfo*/, 0/*exclusive use*/};
E 7
I 7
  {lpaprobe, 0, lpaattach, 0, lpastd, "lpa", lpadinfo, 0, 0, 0 };
E 7

D 7

	/* LPA SOFTWARE OPERATION FLAGS */

E 7
struct lpa_softc {
	int	sc_flag;	/* flags, as defined below */
	int	sc_device;	/* device: 0 = analog in, 1 = analog out */
	int	sc_channel;	/* device channel number */
	struct buf sc_ubuffer;	/* user buffer header */
	int	sc_ubabuf;	/* uba allocation pointer for buffer */
	int	sc_ubufn;	/* present buffer that user is accessing */
	int	sc_lbufn;	/* present buffer that lpa is accessing */
	int	sc_lbufnx;	/* next buffer for lpa (value in ustat) */
	int	sc_nbuf;	/* number of buffers */
	int	sc_count;	/* buffer size in words */
	short	sc_ustat;	/* user status word */
	struct buf sc_ustatbuf;	/* dummy user status word buffer for ubasetup */
	int	sc_ubaustat;	/* uba allocation pointer for ustat */
	struct buf *sc_buffer;	/* scratch buffer header */
	int	sc_start;	/* 0 if lpa operation has been started */
} lpa_softc[NLPA];
D 7
    /* flag bits */
E 7
I 7

/* flags for sc_flag */
E 7
#define OPEN	01		/* device is open */
#define MCODE	02		/* microcode has been loaded */
#define DMDT	04		/* dedicated mode dispatch table loaded */
#define STTY	010		/* stty call and device initialized */
#define SLEEP	020		/* sleeping */
D 7
    /* ustat bits */
E 7
I 7

/* bits for ustat */
E 7
#define DONE	0100000		/* done */
#define STOP	0040000		/* stop data transfer */
#define NBI	0003400		/* next buffer index */
#define LBI	0000003		/* last buffer index */

D 7
	/* DEVICE REGISTER DESCRIPTION AREA */

E 7
struct lpadevice {
	short	lcim;		/* control in and maintenance */
	short	lcos;		/* control and status out */
	short	lrda;		/* request description array address word */
	short	lms;		/* maintenance status */
};
D 7
    /* control in and maintenance register bits */
E 7
I 7

/* control in and maintenance register bits */
E 7
#define	READYI	0000200		/* ready in */
#define IIE	0000100		/* in interrupt enable */
#define RDAEXT	0000014		/* rda address extension */
#define RDAEXTOFFSET	2	/* offset of RDAEXT from right side */
#define GO	0000001		/* go */
#define RUN	0100000		/* run */
#define RESET	0040000		/* reset */
#define CWRITE	0020000		/* cram write */
#define EA	0004000		/* enable arbitration */
#define ROMO	0002000		/* rom O */
#define ROMI	0001000		/* rom I */
#define SMICRO	0000400		/* step microprocessor */
D 7
    /* control and status out register bits */
E 7
I 7

/* control and status out register bits */
E 7
#define READYO	0200		/* ready out */
#define OIE	0100		/* out interrupt enable */
#define UINDEX	0007		/* user index */
#define ERROR	0100000		/* error */
#define ESTAT	0060000		/* error status */
#define ESCODE	0017400		/* error sub code */
#define ECODE	0077400		/* error status + error sub code */
#define OVERRUN	0243		/* overrun error */

D 7
	/* LPA COMMAND DESCRIPTION AREA */
E 7
I 7
/* LPA COMMAND DESCRIPTION AREA */
E 7

D 7
	/* INIT COMMAND */
E 7
I 7
/* INIT COMMAND */
E 7
#define INIT	0		/* mode */
#define MCVERS	4		/* microcode version */
#define ACLOCKA	0170404		/* LPA bus addresses */
#define ACLOCKB	0170432
#define AAD1	0170400
#define AAD2	1		/* 0170440 - DOES NOT EXIST */
#define ADA	0170420
#define ADIO1	1		/* 0167770 - DOES NOT EXIST */
#define ADIO2	1		/* 0167760 - DOES NOT EXIST */
#define ADIO3	1		/* 0167750 - DOES NOT EXIST */
#define ADIO4	1		/* 0167740 - DOES NOT EXIST */
#define ADIO5	1		/* 0167730 - DOES NOT EXIST */
D 7
	/* CLOCK START COMMAND */
E 7
I 7

/* CLOCK START COMMAND */
E 7
#define CLOCK	1		/* mode */
#define CLOCKA	0<<4		/* clock A */
D 7
		/* clock status word */
E 7
I 7
	/* clock status word */
E 7
#define ENACTR	1		/* enable counter */
#define R1M	1<<1		/* 1 MHz rate */
#define R100K	2<<1		/* 100 KHz rate */
#define R10K	3<<1		/* 10 KHz rate */
#define R1K	4<<1		/* 1 KHz rate */
#define R100	5<<1		/* 100 Hz rate */
#define REXT	6<<1		/* external rate (from st1 input) */
#define R60	7<<1		/* line frequency rate */
#define MFIE	0100		/* mode flag interrupt enable */
#define MSI	0<<8		/* single interval mode */
#define MRI	1<<8		/* repeat interval mode */
#define MEET	2<<8		/* external event time mode */
#define MEETZ	3<<8		/* external event time mode from zero base */
#define ST1EC	020000		/* st1 enable counter */
#define ST1IE	040000		/* st1 interrupt enable */
D 7
	/* DATA TRANSFER START COMMAND */
E 7
I 7

/* DATA TRANSFER START COMMAND */
E 7
#define DTS	2		/* mode */
#define SCHAN	1<<8		/* single channel */

D 7
	/* THE ROUTINES THEMSELVES */

/*
 *	probe lpa to get br level and interrupt vector
 */
E 7
lpaprobe(reg)
D 7
caddr_t reg;
E 7
I 7
	caddr_t reg;
E 7
{
D 7
	register int br, cvec;	/* value result (required for UNIX) */
	register struct lpadevice *lpaaddr = (struct lpadevice *) reg;
E 7
I 7
	register int br, cvec;	/* value result */
	register struct lpadevice *lpaaddr = (struct lpadevice *)reg;
E 7

#ifdef lint
	br = 0; cvec = br; br = cvec;
#endif
	/* this should force an interrupt, stall, clear the lpa */
	br = 0x15;
	cvec = 0330;
TRACER("PROBE\n");
D 2
	return (1);
E 2
I 2
	return (sizeof (struct lpadevice));
E 2
}

D 7
/*
 *	attach the specified controller
 */
E 7
lpaattach(ui)
D 7
register struct upa_device *ui;
E 7
I 7
	register struct upa_device *ui;
E 7
{
D 7
	/* any stuff necessary for initialization can go here */
E 7
I 7

E 7
}

D 7
/*
 *	open the device
 */
E 7
lpaopen(dev, flag)
D 7
dev_t dev;
int flag;
E 7
I 7
	dev_t dev;
	int flag;
E 7
{
	register int unit = LPAUNIT(dev);
	register struct lpa_softc *sc = &lpa_softc[unit];
	register struct uba_device *ui = lpadinfo[unit];
	register struct lpadevice *lpaaddr = (struct lpadevice *) ui->ui_addr;

TRACER("OPEN\n");
	if (unit >= NLPA || sc->sc_flag & OPEN || ui == 0 ||
D 8
	    ui->ui_alive == 0) {
		u.u_error = ENXIO;
		return;
	}
E 8
I 8
	    ui->ui_alive == 0)
		return (ENXIO);
E 8
D 13
	(void) spl7();
E 13
I 13
	(void) splhigh();
E 13
	lpaaddr->lcim = RESET;
	lpaaddr->lcim = 0;
	(void) spl0();
	lpaaddr->lcos = 0;	/* clear the registers as a precaution */
	lpaaddr->lrda = 0;
	lpaaddr->lms = 0;
	sc->sc_flag = OPEN;
	sc->sc_device = LPADEVICE(dev);
	sc->sc_channel = LPACHANNEL(dev);
	sc->sc_buffer = geteblk();
	sc->sc_buffer->b_error = 0;
	sc->sc_buffer->b_proc = u.u_procp;
	sc->sc_ubufn = -1;
	/* THIS SHOULD EVENTUALLY SPECIFY "REAL-TIME" */
	u.u_procp->p_nice = NICE;
I 8
	return (0);
E 8
}

D 7
/*
 *	close the device
 */
E 7
lpaclose(dev, flag)
D 7
dev_t dev;
int flag;
E 7
I 7
	dev_t dev;
	int flag;
E 7
{
	register int unit = LPAUNIT(dev);
	register struct lpa_softc *sc = &lpa_softc[unit];
	register struct uba_device *ui = lpadinfo[unit];
	register struct lpadevice *lpaaddr = (struct lpadevice *) ui->ui_addr;

	if (sc->sc_device && sc->sc_ubufn >= 0 && (sc->sc_flag & ERROR) == 0) {
		if (sc->sc_start)
			lpacmd(sc->sc_buffer, lpaaddr, sc, ui->ui_ubanum);
		sc->sc_flag |= STOP;
		(void) spl5();
		while (sc->sc_flag & STOP) {
TRACER("SLEEP\n");
			sc->sc_flag |= SLEEP;
			sleep((caddr_t)sc, LPAPRI);
		}
	}
D 13
	(void) spl7();
E 13
I 13
	(void) splhigh();
E 13
	lpaaddr->lcim = RESET;
	lpaaddr->lcim = 0;
	(void) spl0();
	if (sc->sc_ubabuf) {
		ubarelse(ui->ui_ubanum, &sc->sc_ubabuf);
		sc->sc_ubabuf = 0;
D 13
		(void) spl6();
E 13
I 13
		(void) splclock();
E 13
		vsunlock(sc->sc_ubuffer.b_un.b_addr, sc->sc_ubuffer.b_bcount,
			(sc->sc_device)? B_READ : B_WRITE);
		u.u_procp->p_flag &= ~SPHYSIO;
		(void) spl0();
	}
	if (sc->sc_ubaustat) {
		ubarelse(ui->ui_ubanum, &sc->sc_ubaustat);
		sc->sc_ubaustat = 0;
	}
	if (sc->sc_buffer) {
		brelse(sc->sc_buffer);
		sc->sc_buffer = 0;
	}
	sc->sc_flag = 0;
TRACER("CLOSE\n");
}

D 7
/*
 *	write
 *		first write is the microcode
 *		second write is the dispatch table
 */
E 7
D 5
lpawrite(dev)
dev_t dev;
E 5
I 5
lpawrite(dev, uio)
	dev_t dev;
	struct uio *uio;
E 5
{
	register int unit = LPAUNIT(dev);
	register struct lpa_softc *sc = &lpa_softc[unit];
	register struct uba_device *ui = lpadinfo[unit];
	register struct lpadevice *lpaaddr = (struct lpadevice *) ui->ui_addr;
	register int f;

TRACER("WRITE\n");
	f = sc->sc_flag;
D 7
	if ((f & OPEN) == 0) {
		u.u_error = ENXIO;
		return;
	}
	if ((f & MCODE) == 0) {
D 5
		lpamcode(lpaaddr, sc);
E 5
I 5
		lpamcode(lpaaddr, sc, uio);
E 5
		return;
	}
	if ((f & DMDT) == 0) {
D 5
		lpadmdt(lpaaddr, sc, ui->ui_ubanum);
E 5
I 5
		lpadmdt(lpaaddr, sc, ui->ui_ubanum, uio);
E 5
		return;
	}
	/* writes are only for microcode and dedicated mode dispatch table */
	u.u_error = ENXIO;
E 7
I 7
	if ((f & OPEN) == 0)
		return (ENXIO);
	if ((f & MCODE) == 0)		/* first write is the microcode */
		return (lpamcode(lpaaddr, sc, uio));
	if ((f & DMDT) == 0)		/* second write is the dispatch table */
		return (lpadmdt(lpaaddr, sc, ui->ui_ubanum, uio));
	return (ENXIO);
E 7
}

D 5
lpamcode(lpaaddr, sc)
register struct lpadevice *lpaaddr;
register struct lpa_softc *sc;
E 5
I 5
lpamcode(lpaaddr, sc, uio)
	register struct lpadevice *lpaaddr;
	register struct lpa_softc *sc;
	struct uio *uio;
E 5
{
	short v, r;
	register int mcaddr;
I 9
	int error;
E 9

	mcaddr = 0;
D 5
	while (u.u_count) {
		iomove(&v, 2, B_WRITE);		/* get next microcode word */
E 5
I 5
	while (uio->uio_resid) {
D 9
		uiomove(&v, 2, UIO_WRITE, uio);	/* get next microcode word */
E 9
I 9
		error = uiomove(&v, 2, UIO_WRITE, uio);
		if (error)
			break;
E 9
E 5
		lpaaddr->lcim = 0;		/* load microcode word */
		lpaaddr->lrda = mcaddr;
		lpaaddr->lms = v;
		lpaaddr->lcim = ROMO;
		lpaaddr->lcim |= CWRITE;
		lpaaddr->lcim = 0;		/* verify microcode word */
		lpaaddr->lrda = mcaddr;
		lpaaddr->lcim = ROMO;
		if ((r = lpaaddr->lms) != v) {
			/* download failure */
			printf("LPA MICROCODE FAIL: exp:%o got:%o\n", v, r);
D 7
			u.u_error = ENXIO;
			return;
E 7
I 7
			return (ENXIO);
E 7
		}
		mcaddr++;
	}
	lpaaddr->lcim = RUN | EA;	/* turn it on */
	sc->sc_flag |= MCODE;
	lpaaddr->lcim |= IIE;
	lpaaddr->lcos |= OIE;
I 7
D 9
	return (0);
E 9
I 9
	return (error);
E 9
E 7
TRACER("MCODE\n");
}

D 5
lpadmdt(lpaaddr, sc, ubanum)
register struct lpadevice *lpaaddr;
register struct lpa_softc *sc;
register short ubanum;
E 5
I 5
lpadmdt(lpaaddr, sc, ubanum, uio)
	register struct lpadevice *lpaaddr;
	register struct lpa_softc *sc;
	register short ubanum;
	struct uio *uio;
E 5
{
	register short *p;
	register int n;
I 7
	int error;
E 7

	p = (short *) sc->sc_buffer->b_un.b_addr;		/* INIT */
	*p++ = (MCVERS << 8) | INIT;	/* mode */
	*p++ = ACLOCKA;		/* LPA bus device addresses */
	*p++ = ACLOCKB;
	*p++ = AAD1;
	*p++ = AAD2;
	*p++ = ADA;
	*p++ = ADIO1;
	*p++ = ADIO2;
	*p++ = ADIO3;
	*p++ = ADIO4;
	*p++ = ADIO5;
D 5
	n = min(u.u_count, 256);	/* dedicated mode dispatch table */
	iomove((char *) p, n, B_WRITE);
E 5
I 5
D 13
	n = min(uio->uio_resid, 256);	/* dedicated mode dispatch table */
E 13
I 13
	n = MIN(uio->uio_resid, 256);	/* dedicated mode dispatch table */
E 13
D 7
	uiomove((char *)p, n, UIO_WRITE, uio);
E 7
I 7
	error = uiomove((char *)p, n, UIO_WRITE, uio);
	if (error)
		return (error);
E 7
E 5
	n >>= 1;
	p += n;
	while (n++ < 128)
		*p++ = 0;
	lpacmd(sc->sc_buffer, lpaaddr, sc, ubanum);
	sc->sc_flag |= DMDT;
I 7
	return (0);
E 7
TRACER("DMDT\n");
}

D 3
lpaioctl(dev, cmd, addr, flag)
dev_t dev;
caddr_t *addr;
E 3
I 3
lpaioctl(dev, cmd, data, flag)
	dev_t dev;
	caddr_t data;
E 3
{
	register int unit = LPAUNIT(dev);
	register struct lpa_softc *sc = &lpa_softc[unit];
	register struct uba_device *ui = lpadinfo[unit];
	register struct lpadevice *lpaaddr = (struct lpadevice *) ui->ui_addr;
	register short *p;
	register int i;
	register int v;
	struct iocb {
		short *baddr;
		short rate;
		short wc;
D 3
	} iocb;
E 3
I 3
	} *iocb;
E 3

TRACER("IOCTL IN\n");
D 8
	if (cmd != TIOCSETP) {
TRACER("NOT TIOCSETP\n");
		/* not valid */
		u.u_error = ENXIO;
		return;
	}
#ifndef NOMCODE
	if ((sc->sc_flag & DMDT) == 0) {
TRACER("NO DMDT\n");
		u.u_error = ENXIO;
		return;
	}
#endif
E 8
I 8
	if (cmd != TIOCSETP || (sc->sc_flag & DMDT) == 0)
		return (ENXIO);
E 8
D 3
	if (copyin(addr, (caddr_t)&iocb, sizeof(iocb))) {
TRACER("COPYIN FAULT\n");
		u.u_error = EFAULT;
		return;
	}
E 3
I 3
	iocb = (struct iocb *)data;
E 3
	p = (short *) sc->sc_buffer->b_un.b_addr;	/* CLOCK START */
	*p++ = CLOCK | CLOCKA;			/* mode */
	*p++ = ENACTR | R1M | MFIE | MRI;	/* clock status */
D 3
	*p = iocb.rate;				/* clock preset */
E 3
I 3
	*p = iocb->rate;			/* clock preset */
E 3
	lpacmd(sc->sc_buffer, lpaaddr, sc, ui->ui_ubanum);
TRACER("CLOCK STARTED\n");
	p = (short *) sc->sc_buffer->b_un.b_addr;	/* DATA TRANSFER START*/
	*p++ = (sc->sc_device << 7) | DTS | SCHAN;	/* mode */
D 3
	sc->sc_count = iocb.wc & 017777;	/* word count per buffer */
E 3
I 3
	sc->sc_count = iocb->wc & 017777;	/* word count per buffer */
E 3
	*p++ = sc->sc_count;
							/* user status word */
	sc->sc_ustatbuf.b_un.b_addr = (caddr_t) &sc->sc_ustat;
	sc->sc_ustatbuf.b_flags = 0;
	sc->sc_ustatbuf.b_bcount = 2;
	sc->sc_ustatbuf.b_proc = u.u_procp;
	sc->sc_ubaustat = ubasetup(ui->ui_ubanum, &sc->sc_ustatbuf, 0);
	v = sc->sc_ubaustat;
	*p++ = v;
	*p = (v >> 16) & 03;		/* into low portion of word */
D 3
	sc->sc_nbuf = (iocb.wc >> 13) & 07;	/* number of buffers */
E 3
I 3
	sc->sc_nbuf = (iocb->wc >> 13) & 07;	/* number of buffers */
E 3
	*p++ |= sc->sc_nbuf++ << 8;		/* into high portion of word */
					/* buffer addresses */
D 3
	if (useracc(sc->sc_ubuffer.b_un.b_addr = (caddr_t) iocb.baddr,
E 3
I 3
	if (useracc(sc->sc_ubuffer.b_un.b_addr = (caddr_t) iocb->baddr,
E 3
D 8
		    sc->sc_ubuffer.b_bcount = sc->sc_count * sc->sc_nbuf * 2,
		    (i = (sc->sc_device)? B_READ : B_WRITE) ) == NULL) {
E 8
I 8
	    sc->sc_ubuffer.b_bcount = sc->sc_count * sc->sc_nbuf * 2,
	    (i = (sc->sc_device)? B_READ : B_WRITE) ) == NULL) {
E 8
TRACER("USER BUFFER FAULT\n");
D 8
			u.u_error = EFAULT;
			return;
E 8
I 8
		return (EFAULT);
E 8
	}
	sc->sc_ubuffer.b_flags = B_PHYS | B_BUSY | i;
	sc->sc_ubuffer.b_proc = u.u_procp;
	u.u_procp->p_flag |= SPHYSIO;
	vslock(sc->sc_ubuffer.b_un.b_addr, sc->sc_ubuffer.b_bcount);
D 8
/*	sc->sc_ubabuf = ubasetup(ui->ui_ubanum, &sc->sc_ubuffer, UBA_NEEDBDP);*/
E 8
	sc->sc_ubabuf = ubasetup(ui->ui_ubanum, &sc->sc_ubuffer, 0);
	v = sc->sc_ubabuf;
	for (i = 0; i < sc->sc_nbuf; i++) {
		*p++ = v;
		*p++ = (v >> 16) & 03;
		v += sc->sc_count * 2;
	}
	for ( ; i <= 7; i++) {
		*p++ = 0;
		*p++ = 0;
	}
	*p++ = 0; *p++ = 0;		/* random channel list address */
	*p++ = 0;			/* delay */
	*p++ = sc->sc_channel;		/* start channel, channel inc */
	*p++ = 1;			/* number of samples in a sequence */
	*p++ = 0;			/* dwell */
	*p++ = 0;			/* start word no., event mark word */
	*p++ = 0;			/* start word mask */
	*p = 0;				/* event mark mask */
	sc->sc_ustat = 0;
	sc->sc_start = (sc->sc_device)? sc->sc_nbuf+1 : 1;
	sc->sc_lbufn = 0;
	sc->sc_lbufnx = 0;
	sc->sc_flag |= STTY;
TRACER("IOCTL OUT\n");
I 8
	return (0);
E 8
}

D 7
/*
D 5
 *	read
 *		read 1 character only - the next available buffer number
E 5
I 5
 * Lparead reads 1 character only -- the next available buffer number.
E 5
 */
E 7
D 4
lparead(dev)
E 4
I 4
lparead(dev, uio)
E 4
D 5
dev_t dev;
I 4
struct uio *uio;
E 5
I 5
	dev_t dev;
	struct uio *uio;
E 5
E 4
{
	register int unit = LPAUNIT(dev);
	register struct lpa_softc *sc = &lpa_softc[unit];
	register struct uba_device *ui = lpadinfo[unit];
	register struct lpadevice *lpaaddr = (struct lpadevice *) ui->ui_addr;

TRACER("READ\n");
D 7
	if ((sc->sc_flag & STTY) == 0) {
		u.u_error = ENXIO;
		return;
	}
	if (sc->sc_flag & ERROR) {
		u.u_error = ENXIO;
		return;
	}
E 7
I 7
	if ((sc->sc_flag & STTY) == 0)
		return (ENXIO);
	if (sc->sc_flag & ERROR)
		return (ENXIO);
E 7
	if (sc->sc_start)
		if (--sc->sc_start == 0) {
			lpacmd(sc->sc_buffer, lpaaddr, sc, ui->ui_ubanum);
TRACER("START\n");
		}
	inc(sc_ubufn);
	if (sc->sc_start == 0) {
		(void) spl5();
		while (sc->sc_ubufn == sc->sc_lbufn) {
D 7
			if (sc->sc_flag & ERROR) {
				u.u_error = ENXIO;
				return;
			}
E 7
I 7
			if (sc->sc_flag & ERROR)
				return (ENXIO);
E 7
TRACER("SLEEP\n");
			sc->sc_flag |= SLEEP;
			sleep(sc, LPAPRI);
		}
		(void) spl0();
	}
TRACERN("READ %d\n", sc->sc_ubufn);
D 4
	iomove(&sc->sc_ubufn, 1, B_READ);
E 4
I 4
D 5
	uiomove(&sc->sc_ubufn, 1, B_READ, uio);
E 5
I 5
D 7
	uiomove(&sc->sc_ubufn, 1, UIO_READ, uio);
E 7
I 7
	return (uiomove(&sc->sc_ubufn, 1, UIO_READ, uio));
E 7
E 5
E 4
}

D 7
/*
D 5
 *	execute a command and wait for completion
E 5
I 5
 * Execute a lpa command and wait for completion.
E 5
 */
E 7
lpacmd(bp, lpaaddr, sc, ubanum)
D 5
register struct buf *bp;
register struct lpadevice *lpaaddr;
register struct lpa_softc *sc;
register short ubanum;
E 5
I 5
	register struct buf *bp;
	register struct lpadevice *lpaaddr;
	register struct lpa_softc *sc;
	register short ubanum;
E 5
{
	int ubareg;

TRACER("CMD\n");
D 7
/*	bp->b_flags |= B_BUSY|B_WRITE;		*/
E 7
	ubareg = ubasetup(ubanum, bp, UBA_NEEDBDP);
	lpawait(lpaaddr, sc);
	lpaaddr->lrda = ubareg;
	lpaaddr->lcim &= ~RDAEXT;
	lpaaddr->lcim |= ((ubareg >> (16-RDAEXTOFFSET)) & RDAEXT) | GO;
	lpawait(lpaaddr, sc);
	ubarelse(ubanum, &ubareg);
D 7
/*	bp->b_flags &= ~(B_BUSY|B_WRITE);		*/
E 7
}

D 7
/*
 *	wait for completion (ready input)
 */
E 7
lpawait(lpaaddr, sc)
D 7
register struct lpadevice *lpaaddr;
register struct lpa_softc *sc;
E 7
I 7
	register struct lpadevice *lpaaddr;
	register struct lpa_softc *sc;
E 7
{
I 7

E 7
	(void) spl5();
	while ((lpaaddr->lcim & READYI) == 0) {
TRACER("SLEEP\n");
		sc->sc_flag |= SLEEP;
		sleep((caddr_t)sc, LPAPRI);
	}
	(void) spl0();
}

D 7
/*
 *	lpaiintr
 *		in interrupt
 *		LPA is now ready to accept a user request
 */
E 7
lpaiintr(unit)
D 7
int unit;
E 7
I 7
	int unit;
E 7
{
	register struct lpa_softc *sc = &lpa_softc[unit];

TRACER("{I");
	if (sc->sc_flag & SLEEP) {
TRACER("<WAKEUP>");
		wakeup((caddr_t)sc);
		sc->sc_flag &= ~SLEEP;
	}
TRACER("}");
}

D 7
/*
 *	lpaointr
 *		out interrupt
 *		LPA has status information
 */
E 7
lpaointr(unit)
D 7
int unit;
E 7
I 7
	int unit;
E 7
{
	register int c, m;
	register struct lpa_softc *sc = &lpa_softc[unit];
	register struct uba_device *ui = lpadinfo[unit];
	register struct lpadevice *lpaaddr = (struct lpadevice *) ui->ui_addr;
	int spx;

TRACER("{O");
	if (sc->sc_flag & SLEEP) {
TRACER("<WAKEUP>");
		wakeup(sc);
		sc->sc_flag &= ~SLEEP;
	}
	c = lpaaddr->lcos;
	m = lpaaddr->lms;
	lpaaddr->lcos &= ~READYO;
	if (c & ERROR) {
TRACER("<ERROR>");
		c = (c >> 8) & 0377;
		if ((sc->sc_flag & STOP) == 0 || (c != OVERRUN)) {
			printf("LPA ERROR %o %o\n", c, m&0177777);
			sc->sc_flag |= ERROR;
		}
		sc->sc_flag &= ~STOP;
TRACER("}\n");
		return;
	}
TRACERN("<LPA %d>", sc->sc_lbufnx);
	sc->sc_lbufn = sc->sc_lbufnx;
	if (sc->sc_ubufn == sc->sc_lbufnx && c & ECODE) {
TRACER("<STOP?>");
		if (sc->sc_flag & STOP)
			return;
		printf("LPA OVERRUN\n");
		sc->sc_flag |= ERROR;
	}
	inc(sc_lbufnx);
TRACERN("<USTAT %o>", sc->sc_ustat);
D 13
	spx = spl7();
E 13
I 13
	spx = splhigh();
E 13
	sc->sc_ustat &= ~NBI;
	sc->sc_ustat |= sc->sc_lbufnx << 8;
	sc->sc_ustat &= ~DONE;
D 13
	(void) splx(spx);
E 13
I 13
	splx(spx);
E 13
TRACERN("<LPAN %d>}", sc->sc_lbufnx);
}

D 7
/*
 *	reset called for a unibus reset
 */
E 7
lpareset(uban)
D 7
int uban;
E 7
I 7
	int uban;
E 7
{
	register struct uba_device *ui;
	register struct lpadevice *lpaaddr;
	register struct lpa_softc *sc;
	register int unit;

TRACER("LPA RESET\n");
	for (unit = 0; unit < NLPA; unit++) {
D 7
		if (	(ui = lpadinfo[unit]) == 0 ||
			ui->ui_ubanum != uban ||
			ui->ui_alive == 0)
				continue;
E 7
I 7
		if ((ui = lpadinfo[unit]) == 0 ||
		    ui->ui_ubanum != uban || ui->ui_alive == 0)
			continue;
E 7
		printf(" lpa%d", unit);
		lpaaddr = (struct lpadevice *)ui->ui_addr;
		sc = &lpa_softc[unit];
		sc->sc_flag |= ERROR;
D 13
		(void) spl7();
E 13
I 13
		(void) splhigh();
E 13
		lpaaddr->lcim = RESET;
		lpaaddr->lcim = 0;
		(void) spl0();
		if (sc->sc_flag & SLEEP) {
			wakeup((caddr_t)sc);
			sc->sc_flag &= ~SLEEP;
		}
	}
}
#endif NLPA
E 1
