h07522
s 00002/00002/01289
d D 1.10 04/02/05 00:38:51 msokolov 10 9
c q_key and q_shift_key tables back to char, since we don't implement compose
c we have no 8-bit keyboard input
e
s 00002/00000/01289
d D 1.9 89/02/07 20:07:09 tef 9 8
c try to replace standard console on qbus machines only
e
s 00017/00004/01272
d D 1.8 88/08/09 20:35:09 bostic 8 7
c add correct Berkeley copyright
e
s 00042/00035/01234
d D 1.7 88/06/14 14:07:16 marc 7 6
c lint, code cleanup, make less yucky
e
s 00004/00006/01265
d D 1.6 88/06/03 17:54:29 marc 6 5
c tahoe release
e
s 00011/00004/01260
d D 1.5 88/05/27 20:28:37 marc 5 4
c add header
e
s 00001/00001/01263
d D 1.4 87/07/08 16:33:31 karels 4 3
c fix typo
e
s 00062/00028/01202
d D 1.3 87/07/06 19:34:58 karels 3 2
c working (I think!) with sun-style pseudo-console, many cleanups
e
s 00075/00055/01155
d D 1.2 87/07/06 19:34:09 karels 2 1
c first version working with 4.3
e
s 01210/00000/00000
d D 1.1 87/07/06 19:32:38 karels 1 0
c from Ultrix
e
u
U
t
T
I 1
D 5
#ifndef lint
D 2
static	char	*sccsid = "@(#)qv.c	1.8 (ULTRIX) 8/21/85";
E 2
I 2
static	char	*sccsid = "%W% (Berkeley) %G%";
static	char	*osccsid = "@(#)qv.c	1.8 (ULTRIX) 8/21/85";
E 2
#endif lint
E 5
I 5
/*
D 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 8
 *
D 8
 * 		%W%  Berkeley  %G%
E 8
I 8
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
E 8
 *
I 8
 *	%W% (Berkeley) %G%
 */

/*
E 8
 *	derived from: @(#)qv.c	1.8 (ULTRIX) 8/21/85
 */
E 5

/************************************************************************
 *									*
 *			Copyright (c) 1985 by				*
 *		Digital Equipment Corporation, Maynard, MA		*
 *			All rights reserved.				*
 *									*
 *   This software is furnished under a license and may be used and	*
 *   copied  only  in accordance with the terms of such license and	*
 *   with the  inclusion  of  the  above  copyright  notice.   This	*
 *   software  or  any  other copies thereof may not be provided or	*
 *   otherwise made available to any other person.  No title to and	*
 *   ownership of the software is hereby transferred.			*
 *									*
 *   This software is  derived  from  software  received  from  the	*
 *   University    of   California,   Berkeley,   and   from   Bell	*
 *   Laboratories.  Use, duplication, or disclosure is  subject  to	*
 *   restrictions  under  license  agreements  with  University  of	*
 *   California and with AT&T.						*
 *									*
 *   The information in this software is subject to change  without	*
 *   notice  and should not be construed as a commitment by Digital	*
 *   Equipment Corporation.						*
 *									*
 *   Digital assumes no responsibility for the use  or  reliability	*
 *   of its software on equipment which is not supplied by Digital.	*
 *									*
 ************************************************************************
 *
 * This driver provides glass tty functionality to the qvss. It is a strange
 * device in that it supports three subchannels. The first being the asr,
 * the second being a channel that intercepts the chars headed for the screen
 * ( like a pseudo tty ) and the third being a source of mouse state changes.
I 3
 * NOTE: the second is conditional on #ifdef CONS_HACK in this version
 * of the driver, as it's a total crock.
E 3
 *
 * There may be one and only one qvss in the system.  This restriction is based
 * on the inability to map more than one at a time.  This restriction will
 * exist until the kernel has shared memory services. This driver therefore
 * support a single unit. No attempt was made to have it service more.
I 5
 *
 * (this belongs in sccs - not here)
E 5
 *
 * 02 Aug 85 -- rjl
 *	Changed the names of the special setup routines so that the system
 *	can have a qvss or a qdss system console.
 *
 * 03 Jul 85 -- rjl
 *	Added a check for virtual mode in qvputc so that the driver
 *	doesn't crash while in a dump which is done in physical mode.
 *
 * 10 Apr 85 -- jg
 *	Well, our theory about keyboard handling was wrong; most of the 
 *	keyboard is in autorepeat, down mode.  These changes are to make
 *	the qvss work the same as the Vs100, which is not necessarily
 *	completely correct, as some chord usage may fail.  But since we
 *	can't easily change the Vs100, we might as well propagate the
 *	problem to another device.  There are also changes for screen and
 *	mouse accellaration.
 *
 * 27 Mar 85 -- rjl
 *	MicroVAX-II systems have interval timers that interrupt at ipl4.
 *	Everything else is higher and thus causes us to miss clock ticks. The
 *	problem isn't severe except in the case of a device like this one that
 *	generates lots of interrupts. We aren't willing to make this change to
 *	all device drivers but it seems acceptable in this case.
 *
 *  3 Dec 84 -- jg
 *	To continue the tradition of building a better mouse trap,  this
 * 	driver has been extended to form Vs100 style event queues.  If the
 *	mouse device is open, the keyboard events are intercepted and put
 *	into the shared memory queue.  Unfortunately, we are ending up with
 *	one of the longest Unix device drivers.  Sigh....
 *
 * 20 Nov 84 -- rjl
 *      As a further complication this driver is required to function as the
 *      virtual system console. This code runs before and during auto-
 *      configuration and therefore is require to have a second path for setup.
 *      It is futher constrained to have a character output routine that
 *      is not dependant on the interrupt system.
 *
 */


#include "qv.h"
D 2
#if NQV > 0  || defined(BINARY)
E 2
I 2
#if NQV > 0
E 2

#include "../machine/pte.h"

D 2
#include "../h/param.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../vaxuba/qvioctl.h"
#include "../h/tty.h"
#include "../h/map.h"
#include "../h/buf.h"
#include "../h/vm.h"
#include "../h/bk.h"
#include "../h/clist.h"
#include "../h/file.h"
#include "../h/uio.h"
#include "../h/kernel.h"
E 2
I 2
#include "param.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "qvioctl.h"
#include "tty.h"
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "bk.h"
#include "clist.h"
#include "file.h"
#include "uio.h"
#include "kernel.h"
#include "syslog.h"
E 2
D 6

#include "../vax/cpu.h"
#include "../vax/mtpr.h"

#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 6
I 6
#include "../machine/cpu.h"
#include "../machine/mtpr.h"
#include "ubareg.h"
#include "ubavar.h"
E 6

I 3
#define CONS_HACK

E 3
struct	uba_device *qvinfo[NQV];

struct	tty qv_tty[NQV*4];

D 3
int	nNQV = NQV;
E 3
I 3
#define	nNQV  NQV
E 3
int	nqv = NQV*4;

/*
 * Definition of the driver for the auto-configuration program.
 */
int	qvprobe(), qvattach(), qvkint(), qvvint();
u_short	qvstd[] = { 0 };
struct	uba_driver qvdriver =
	{ qvprobe, 0, qvattach, 0, qvstd, "qv", qvinfo };

I 2
extern	char qvmem[][512*NBPG];
extern	struct pte QVmap[][512];

E 2
/*
 * Local variables for the driver. Initialized for 15' screen
 * so that it can be used during the boot process.
 */

#define QVWAITPRI 	(PZERO+1)
D 2
#define QVSSMAJOR	35
E 2
I 2
#define QVSSMAJOR	40
I 3

#define QVKEYBOARD 	0	/* minor 0, keyboard/glass tty */
#define QVPCONS 	1	/* minor 1, console interceptor XXX */
#define QVMOUSECHAN 	2	/* minor 2, mouse */
#define	QVSPARE		3	/* unused */
#define QVCHAN(unit)	((unit) & 03)
E 3
E 2
/*
D 3
 * v_console is the switch that is used to redirect the console cnputc to the
 * virtual console vputc.
E 3
I 3
 * v_putc is the switch that is used to redirect the console cnputc to the
 * virtual console vputc.  consops is used to redirect the console
 * device to the qvss console.
E 3
 */
D 3
extern (*v_console)();
E 3
I 3
extern (*v_putc)();
extern struct cdevsw *consops;
E 3
/*
 * qv_def_scrn is used to select the appropriate tables. 0=15 inch 1=19 inch,
D 2
 * 2 = new display (untested).
E 2
I 2
D 3
 * 2 = uVAXII (untested).
E 3
I 3
 * 2 = uVAXII.
E 3
E 2
 */
D 2
int qv_def_scrn = 0;
E 2
I 2
int qv_def_scrn = 2;
E 2

#define QVMAXEVQ	64	/* must be power of 2 */
#define EVROUND(x)	((x) & (QVMAXEVQ - 1))

/*
 * Screen parameters 15 & 19 inch monitors. These determine the max size in
 * pixel and character units for the display and cursor positions.
 * Notice that the mouse defaults to original square algorithm, but X
 * will change to its defaults once implemented.
 */
struct qv_info *qv_scn;
struct qv_info qv_scn_defaults[] = {
	{0, {0, 0}, 0, {0, 0}, 0, 0, 30, 80, 768, 480, 768-16, 480-16,
	 0, 0, 0, 0, 0, QVMAXEVQ, 0, 0, {0, 0}, {0, 0, 0, 0}, 2, 4},
	{0, {0, 0}, 0, {0, 0}, 0, 0, 55, 120, 960, 864, 960-16, 864-16,
	 0, 0, 0, 0, 0, QVMAXEVQ, 0, 0, {0, 0}, {0, 0, 0, 0}, 2, 4},
	{0, {0, 0}, 0, {0, 0}, 0, 0, 56, 120,1024, 864,1024-16, 864-16,
	 0, 0, 0, 0, 0, QVMAXEVQ, 0, 0, {0, 0}, {0, 0, 0, 0}, 2, 4}
};

/*
 * Screen controller initialization parameters. The definations and use
 * of these parameters can be found in the Motorola 68045 crtc specs. In
 * essence they set the display parameters for the chip. The first set is
 * for the 15" screen and the second is for the 19" seperate sync. There
 * is also a third set for a 19" composite sync monitor which we have not
 * tested and which is not supported.
 */
static short qv_crt_parms[][16] = {
           { 31, 25, 27, 0142, 31, 13, 30, 31, 4, 15, 040, 0, 0, 0, 0, 0 },
/* VR100*/ { 39, 30, 32, 0262, 55, 5, 54, 54, 4, 15, 040, 0, 0, 0, 0, 0 },
/* VR260*/ { 39, 32, 33, 0264, 56, 5, 54, 54, 4, 15, 040, 0, 0, 0, 0, 0},
};
D 3
#define QVMOUSECHAN 	2
E 3

/*
 * Screen parameters
 */
struct qv_info  *qv_scn;
int maxqvmem = 254*1024 - sizeof(struct qv_info) - QVMAXEVQ*sizeof(vsEvent);
	
/*
 * Keyboard state
 */
struct qv_keyboard {
	int shift;			/* state variables	*/
	int cntrl;
	int lock;
	char last;			/* last character	*/
} qv_keyboard;

short divdefaults[15] = { LK_DOWN,	/* 0 doesn't exist */
	LK_AUTODOWN, LK_AUTODOWN, LK_AUTODOWN, LK_DOWN,
	LK_UPDOWN,   LK_UPDOWN,   LK_AUTODOWN, LK_AUTODOWN, 
	LK_AUTODOWN, LK_AUTODOWN, LK_AUTODOWN, LK_AUTODOWN, 
	LK_DOWN, LK_AUTODOWN };

short kbdinitstring[] = {		/* reset any random keyboard stuff */
	LK_AR_ENABLE,			/* we want autorepeat by default */
	LK_CL_ENABLE,			/* keyclick */
	0x84,				/* keyclick volume */
	LK_KBD_ENABLE,			/* the keyboard itself */
	LK_BELL_ENABLE,			/* keyboard bell */
	0x84,				/* bell volume */
	LK_LED_DISABLE,			/* keyboard leds */
	LED_ALL };
#define KBD_INIT_LENGTH	sizeof(kbdinitstring)/sizeof(short)

#define TOY ((time.tv_sec * 100) + (time.tv_usec / 10000))

D 7
int	qv_events;
E 7
int	qv_ipl_lo = 1;			/* IPL low flag			*/
int	mouseon = 0;			/* mouse channel is enabled when 1*/
D 7
struct proc *rsel;			/* process waiting for select */
E 7
I 7
struct proc *qvrsel;			/* process waiting for select */
E 7

int	qvstart(), qvputc(),  ttrstrt();

/*
 * Keyboard translation and font tables
 */
D 7
extern  char q_key[],q_shift_key[],*q_special[],q_font[];
extern	short q_cursor[];
E 7
I 7
D 10
extern u_short q_key[], q_shift_key[], q_cursor[];
extern char *q_special[], q_font[];
E 10
I 10
extern char q_key[], q_shift_key[], *q_special[], q_font[];
extern u_short q_cursor[];
E 10
E 7

/*
 * See if the qvss will interrupt.
 */

/*ARGSUSED*/
qvprobe(reg, ctlr)
	caddr_t reg;
	int ctlr;
{
	register int br, cvec;		/* these are ``value-result'' */
	register struct qvdevice *qvaddr = (struct qvdevice *)reg;
	static int tvec, ovec;

#ifdef lint
	br = 0; cvec = br; br = cvec;
I 7
	qvkint(0); qvvint(0);
E 7
#endif
	/*
	 * Allocate the next two vectors
	 */
	tvec = 0360;
	ovec = cvec;
	/*
	 * Turn on the keyboard and vertical interrupt vectors.
	 */
	qvaddr->qv_intcsr = 0;		/* init the interrupt controler */
	qvaddr->qv_intcsr = 0x40;	/* reset irr			*/
	qvaddr->qv_intcsr = 0x80;	/* specify individual vectors	*/
	qvaddr->qv_intcsr = 0xc0;	/* preset autoclear data	*/
	qvaddr->qv_intdata = 0xff;	/* all setup as autoclear	*/

	qvaddr->qv_intcsr = 0xe0;	/* preset vector address 1	*/
	qvaddr->qv_intdata = tvec;	/* give it the keyboard vector	*/
	qvaddr->qv_intcsr = 0x28;	/* enable tx/rx interrupt	*/

	qvaddr->qv_intcsr = 0xe1;	/* preset vector address 2	*/
	qvaddr->qv_intdata = tvec+4;	/* give it the vertical sysnc	*/
	qvaddr->qv_intcsr = 0x29;	/* enable 			*/

	qvaddr->qv_intcsr = 0xa1;	/* arm the interrupt ctrl	*/

	qvaddr->qv_uartcmd = 0x15;	/* set mode pntr/enable rx/tx	*/
	qvaddr->qv_uartmode = 0x17;	/* noparity, 8-bit		*/
	qvaddr->qv_uartmode = 0x07;	/* 1 stop bit			*/
	qvaddr->qv_uartstatus = 0x99;	/* 4800 baud xmit/recv 		*/
	qvaddr->qv_uartintstatus = 2;	/* enable recv interrupts	*/

	qvaddr->qv_csr |= QV_INT_ENABLE | QV_CUR_MODE;

	DELAY(10000);

	qvaddr->qv_csr &= ~QV_INT_ENABLE;

	/*
	 * If the qvss did interrupt it was the second vector not
	 * the first so we have to return the first so that they
	 * will be setup properly
	 */
	if( ovec == cvec ) {
		return 0;
	} else
D 2
		cvec = tvec;
	/* can't do this until we know we have memory to write in */
	qv_scn->qvaddr = qvaddr;
E 2
I 2
		cvec -= 4;
E 2
	return (sizeof (struct qvdevice));
}

/*
 * Routine called to attach a qv.
 */
qvattach(ui)
        struct uba_device *ui;
{
D 2
        register struct qvdevice *qvaddr;
        register i;
        register int *pte;
        char *qvssmem;
E 2

D 2
        qvaddr = (struct qvdevice *)ui->ui_addr;

E 2
        /*
         * If not the console then we have to setup the screen
         */
D 2
        if( v_console != qvputc ) 
                qv_setup( qvaddr );

        /*
         * Map the qvss memory for use by users.
         */
        qvssmem = (char *)((qvaddr->qv_csr & QV_MEM_BANK) << 7);
        pte = (int *)(UMEMmap[0] + btop( qvssmem ));
        for( i=0 ; i<512 ; i++, pte++ )
                *pte = (*pte & ~PG_PROT) | PG_UW | PG_V;
E 2
I 2
D 3
        if( v_console != qvputc || ui->ui_unit != 0)
E 3
I 3
D 7
        if( v_putc != qvputc || ui->ui_unit != 0)
E 3
                qv_setup((struct qvdevice *)ui->ui_addr, ui->ui_unit, 1);
E 7
I 7
        if (v_putc != qvputc || ui->ui_unit != 0)
                (void)qv_setup((struct qvdevice *)ui->ui_addr, ui->ui_unit, 1);
E 7
	else
		qv_scn->qvaddr = (struct qvdevice *)ui->ui_addr;
E 2
}


/*ARGSUSED*/
qvopen(dev, flag)
	dev_t dev;
{
	register struct tty *tp;
	register int unit, qv;
	register struct qvdevice *qvaddr;
	register struct uba_device *ui;
	register struct qv_info *qp = qv_scn;

	unit = minor(dev);
	qv = unit >> 2;
	if (unit >= nqv || (ui = qvinfo[qv])== 0 || ui->ui_alive == 0)
		return (ENXIO);
I 3
	if (QVCHAN(unit) == QVSPARE
D 4
#ifdef CONS_HACK
E 4
I 4
#ifndef CONS_HACK
E 4
	   || QVCHAN(unit) == QVPCONS
#endif
	   )
		return (ENODEV);
E 3
	tp = &qv_tty[unit];
	if (tp->t_state&TS_XCLUDE && u.u_uid!=0)
		return (EBUSY);
	qvaddr = (struct qvdevice *)ui->ui_addr;
        qv_scn->qvaddr = qvaddr;
	tp->t_addr = (caddr_t)qvaddr;
	tp->t_oproc = qvstart;

	if ((tp->t_state&TS_ISOPEN) == 0) {
		ttychars(tp);
		tp->t_state = TS_ISOPEN|TS_CARR_ON;
		tp->t_ispeed = B9600;
		tp->t_ospeed = B9600;
D 3
		if( unit == 0 ) {
E 3
I 3
		if( QVCHAN(unit) == QVKEYBOARD ) {
E 3
			/* make sure keyboard is always back to default */
			qvkbdreset();
			qvaddr->qv_csr |= QV_INT_ENABLE;
			tp->t_flags = XTABS|EVENP|ECHO|CRMOD;
		} else 
			tp->t_flags = RAW;
	}
	/*
	 * Process line discipline specific open if its not the
	 * mouse channel. For the mouse we init the ring ptr's.
	 */
D 3
	if( ( unit % 4 ) != QVMOUSECHAN )
E 3
I 3
	if( QVCHAN(unit) != QVMOUSECHAN )
E 3
		return ((*linesw[tp->t_line].l_open)(dev, tp));
	else {
		mouseon = 1;
		/* set up event queue for later */
		qp->ibuff = (vsEvent *)qp - QVMAXEVQ;
		qp->iqsize = QVMAXEVQ;
		qp->ihead = qp->itail = 0;
		return 0;
	}
}

/*
 * Close a QVSS line.
 */
/*ARGSUSED*/
qvclose(dev, flag)
	dev_t dev;
	int flag;
{
	register struct tty *tp;
	register unit;
	register struct qvdevice *qvaddr;

	unit = minor(dev);
	tp = &qv_tty[unit];

	/*
	 * If this is the keyboard unit (0) shutdown the
	 * interface.
	 */
	qvaddr = (struct qvdevice *)tp->t_addr;
D 3
	if( unit == 0 )
E 3
I 3
	if (QVCHAN(unit) == QVKEYBOARD )
E 3
		qvaddr->qv_csr &= ~QV_INT_ENABLE;

	/*
	 * If unit is not the mouse channel call the line disc.
	 * otherwise clear the state flag, and put the keyboard into down/up.
	 */
D 3
	if( ( unit % 4 ) != QVMOUSECHAN ){
E 3
I 3
	if (QVCHAN(unit) != QVMOUSECHAN) {
E 3
		(*linesw[tp->t_line].l_close)(tp);
		ttyclose(tp);
	} else {
		mouseon = 0;
		qv_init( qvaddr );
	}
	tp->t_state = 0;
}

qvread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register struct tty *tp;
	int unit = minor( dev );

D 3
	if( (unit % 4) != QVMOUSECHAN ) {
E 3
I 3
	if (QVCHAN(unit) != QVMOUSECHAN) {
E 3
		tp = &qv_tty[unit];
		return ((*linesw[tp->t_line].l_read)(tp, uio));
	}
	return (ENXIO);
}

qvwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register struct tty *tp;
	int unit = minor( dev );

	/*
	 * If this is the mouse we simply fake the i/o, otherwise
	 * we let the line disp. handle it.
	 */
D 3
	if( (unit % 4) == QVMOUSECHAN ){
E 3
I 3
	if (QVCHAN(unit) == QVMOUSECHAN) {
E 3
		uio->uio_offset = uio->uio_resid;
		uio->uio_resid = 0;
		return 0;
	}
	tp = &qv_tty[unit];
	return ((*linesw[tp->t_line].l_write)(tp, uio));
}


/*
 * Mouse activity select routine
 */
qvselect(dev, rw)
dev_t dev;
{
	register int s = spl5();
D 3
	register int unit = minor(dev);
E 3
	register struct qv_info *qp = qv_scn;

D 3
	if( (unit % 4) == QVMOUSECHAN )
E 3
I 3
	if( QVCHAN(minor(dev)) == QVMOUSECHAN )
E 3
		switch(rw) {
		case FREAD:			/* if events okay */
			if(qp->ihead != qp->itail) {
				splx(s);
				return(1);
			}
D 7
			rsel = u.u_procp;
E 7
I 7
			qvrsel = u.u_procp;
E 7
			splx(s);
			return(0);
D 7
		case FWRITE:			/* can never write */
E 7
I 7
		default:			/* can never write */
E 7
			splx(s);
D 7
			return(EACCES);
E 7
I 7
			return(0);
E 7
		}
D 7
	else
E 7
I 7
	else {
		splx(s);
E 7
		return( ttselect(dev, rw) );
I 7
	}
	/*NOTREACHED*/
E 7
}
		
/*
 * QVSS keyboard interrupt.
 */
qvkint(qv)
	int qv;
{
	struct tty *tp;
	register c;
	struct uba_device *ui;
	register int key;
D 7
	register int i,j;
	int k,l;
E 7
I 7
	register int i;
E 7

	ui = qvinfo[qv];
	if (ui == 0 || ui->ui_alive == 0)
		return;
	tp = &qv_tty[qv<<2];
	/*
	 * Get a character from the keyboard.
	 */
	key = ((struct qvdevice *)ui->ui_addr)->qv_uartdata & 0xff;
	if( mouseon == 0) {
		/*
		 * Check for various keyboard errors
		 */
		if( key == LK_POWER_ERROR || key == LK_KDOWN_ERROR ||
		    key == LK_INPUT_ERROR || key == LK_OUTPUT_ERROR) {
D 2
				mprintf("qv%d: Keyboard error, code = %x\n",qv,key);
				return;
E 2
I 2
			log(LOG_ERR,
			    "qv%d: Keyboard error, code = %x\n",qv,key);
			return;
E 2
		}
		if( key < LK_LOWEST ) return;
		/*
		 * See if its a state change key
		 */
		switch ( key ) {
		case LOCK:
			qv_keyboard.lock ^= 0xffff;	/* toggle */
			if( qv_keyboard.lock )
				qv_key_out( LK_LED_ENABLE );
			else
				qv_key_out( LK_LED_DISABLE );
			qv_key_out( LED_3 );
			return;
		case SHIFT:
			qv_keyboard.shift ^= 0xffff;
			return;	
		case CNTRL:
			qv_keyboard.cntrl ^= 0xffff;
			return;
		case ALLUP:
			qv_keyboard.cntrl = qv_keyboard.shift = 0;
			return;
		case REPEAT:
			c = qv_keyboard.last;
			break;
		default:
		/*
		 * Test for control characters. If set, see if the character
		 * is elligible to become a control character.
		 */
			if( qv_keyboard.cntrl ) {
				c = q_key[ key ];
				if( c >= ' ' && c <= '~' )
					c &= 0x1f;
			} else if( qv_keyboard.lock || qv_keyboard.shift )
				c = q_shift_key[ key ];
				else
				c = q_key[ key ];
			break;	
		}

		qv_keyboard.last = c;

		/*
		 * Check for special function keys
		 */
		if( c & 0x80 ) {
			register char *string;
			string = q_special[ c & 0x7f ];
			while( *string )
			(*linesw[tp->t_line].l_rint)(*string++, tp);
		} else
			(*linesw[tp->t_line].l_rint)(c, tp);
	} else {
		/*
		 * Mouse channel is open put it into the event queue
		 * instead.
		 */
		register struct qv_info *qp = qv_scn;
		register vsEvent *vep;

D 7
		if ((i = EVROUND(qp->itail+1)) == qp->ihead) return;
E 7
I 7
		if ((i = EVROUND(qp->itail+1)) == qp->ihead) 
			return;
E 7
		vep = &qp->ibuff[qp->itail];
		vep->vse_direction = VSE_KBTRAW;
		vep->vse_type = VSE_BUTTON;
		vep->vse_device = VSE_DKB;
		vep->vse_x = qp->mouse.x;
		vep->vse_y = qp->mouse.y;
		vep->vse_time = TOY;
		vep->vse_key = key;
		qp->itail = i;
D 7
		if(rsel) {
			selwakeup(rsel,0);
			rsel = 0;
E 7
I 7
		if(qvrsel) {
			selwakeup(qvrsel,0);
			qvrsel = 0;
E 7
		}
	}
}

/*
 * Ioctl for QVSS.
 */
/*ARGSUSED*/
qvioctl(dev, cmd, data, flag)
	dev_t dev;
	register caddr_t data;
{
	register struct tty *tp;
	register int unit = minor(dev);
	register struct qv_info *qp = qv_scn;
	register struct qv_kpcmd *qk;
	register unsigned char *cp;
	int error;
 
	/*
	 * Check for and process qvss specific ioctl's
	 */
	switch( cmd ) {
	case QIOCGINFO:					/* return screen info */
D 7
		bcopy(qp, data, sizeof (struct qv_info));
E 7
I 7
		bcopy((caddr_t)qp, data, sizeof (struct qv_info));
E 7
		break;

	case QIOCSMSTATE:				/* set mouse state */
		qp->mouse = *((vsCursor *)data);
		qv_pos_cur( qp->mouse.x, qp->mouse.y );
		break;

	case QIOCINIT:					/* init screen	*/
		qv_init( qp->qvaddr );
		break;

	case QIOCKPCMD:
		qk = (struct qv_kpcmd *)data;
		if(qk->nbytes == 0) qk->cmd |= 0200;
		if(mouseon == 0) qk->cmd |= 1;	/* no mode changes */
		qv_key_out(qk->cmd);
		cp = &qk->par[0];
		while(qk->nbytes-- > 0) {	/* terminate parameters */
			if(qk->nbytes <= 0) *cp |= 0200;
			qv_key_out(*cp++);
		}
		break;
	case QIOCADDR:					/* get struct addr */
		*(struct qv_info **) data = qp;
		break;
	default:					/* not ours ??  */
		tp = &qv_tty[unit];
		error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
		if (error >= 0)
			return (error);
		error = ttioctl(tp, cmd, data, flag);
		if (error >= 0) {
			return (error);
		}
		break;
	}
	return (0);
}
/*
 * Initialize the screen and the scanmap
 */
qv_init(qvaddr)
struct qvdevice *qvaddr;
{
	register short *scanline;
	register int i;
	register short scan;
	register char *ptr;
	register struct qv_info *qp = qv_scn;

	/*
	 * Clear the bit map
	 */
	for( i=0 , ptr = qp->bitmap ; i<240 ; i += 2 , ptr += 2048)
		bzero( ptr, 2048 );
	/*
	 * Reinitialize the scanmap
	 */
        scan = qvaddr->qv_csr & QV_MEM_BANK;
        scanline = qp->scanmap;
        for(i = 0 ; i < qp->max_y ; i++ )
                *scanline++ = scan++;

	/*
	 * Home the cursor
	 */
	qp->row = qp->col = 0;

	/*
	 * Reset the cursor to the default type.
	 */
	for( i=0 ; i<16 ; i++ )
		qp->cursorbits[i] = q_cursor[i];
	qvaddr->qv_csr |= QV_CUR_MODE;
	/*
	 * Reset keyboard to default state.
	 */
	qvkbdreset();
}

qvreset()
{
}
qvkbdreset()
{
	register int i;
	qv_key_out(LK_DEFAULTS);
	for( i=1 ; i < 15 ; i++ )
		qv_key_out( divdefaults[i] | (i<<3));
	for (i = 0; i < KBD_INIT_LENGTH; i++)
		qv_key_out(kbdinitstring[i]);
}

#define abs(x) (((x) > 0) ? (x) : (-(x)))
/*
 * QVSS vertical sync interrupt
 */
qvvint(qv)
	int qv;
{
	extern int selwait;
	register struct qvdevice *qvaddr;
	struct uba_device *ui;
	register struct qv_info *qp = qv_scn;
	int unit;
	struct tty *tp0;
	int i;
	register int j;
	/*
	 * Mouse state info
	 */
	static ushort omouse = 0, nmouse = 0;
	static char omx=0, omy=0, mx=0, my=0, om_switch=0, m_switch=0;
	register int dx, dy;

	/*
	 * Test and set the qv_ipl_lo flag. If the result is not zero then
	 * someone else must have already gotten here.
	 */
	if( --qv_ipl_lo )
		return;
D 7
	spl4();
E 7
I 7
	(void)spl4();
E 7
	ui = qvinfo[qv];
	unit = qv<<2;
	qvaddr = (struct qvdevice *)ui->ui_addr;
D 3
	tp0 = &qv_tty[(unit % 4 )+QVMOUSECHAN];
E 3
I 3
	tp0 = &qv_tty[QVCHAN(unit) + QVMOUSECHAN];
E 3
	/*
	 * See if the mouse has moved.
	 */
	if( omouse != (nmouse = qvaddr->qv_mouse) ) {
		omouse = nmouse;
		mx = nmouse & 0xff;
		my = nmouse >> 8;
		dy = my - omy; omy = my;
		dx = mx - omx; omx = mx;
		if( dy < 50 && dy > -50 && dx < 50 && dx > -50 ) {
			register vsEvent *vep;
			if( qp->mscale < 0 ) {	/* Ray Lanza's original */
				if( dy < 0 )
					dy = -( dy * dy );
				else
					dy *= dy;
				if( dx < 0 )
					dx = -( dx * dx );
				else
					dx *= dx;
			}
			else {			/* Vs100 style, see WGA spec */
			    int thresh = qp->mthreshold;
			    int scale  = qp->mscale;
			    if( abs(dx) > thresh ) {
				if ( dx < 0 )
				    dx = (dx + thresh)*scale - thresh;
				else
				    dx = (dx - thresh)*scale + thresh;
			    }
			    if( abs(dy) > thresh ) {
				if ( dy < 0 )
				    dy = (dy + thresh)*scale - thresh;
				else
				    dy = (dy - thresh)*scale + thresh;
			    }
			}
			qp->mouse.x += dx;
			qp->mouse.y -= dy;
			if( qp->mouse.x < 0 )
				qp->mouse.x = 0;
			if( qp->mouse.y < 0 )
				qp->mouse.y = 0;
			if( qp->mouse.x > qp->max_cur_x )
				qp->mouse.x = qp->max_cur_x;
			if( qp->mouse.y > qp->max_cur_y )
				qp->mouse.y = qp->max_cur_y;
			if( tp0->t_state & TS_ISOPEN )
				qv_pos_cur( qp->mouse.x, qp->mouse.y );
			if (qp->mouse.y < qp->mbox.bottom &&
			    qp->mouse.y >=  qp->mbox.top &&
			    qp->mouse.x < qp->mbox.right &&
			    qp->mouse.x >=  qp->mbox.left) goto switches;
			qp->mbox.bottom = 0;	/* trash box */
			if (EVROUND(qp->itail+1) == qp->ihead)
				goto switches;
			i = EVROUND(qp->itail - 1);
			if ((qp->itail != qp->ihead) &&	(i != qp->ihead)) {
				vep = & qp->ibuff[i];
				if(vep->vse_type == VSE_MMOTION) {
					vep->vse_x = qp->mouse.x;
					vep->vse_y = qp->mouse.y;
					goto switches;
				}
			}
			/* put event into queue and do select */
			vep = & qp->ibuff[qp->itail];
			vep->vse_type = VSE_MMOTION;
			vep->vse_time = TOY;
			vep->vse_x = qp->mouse.x;
			vep->vse_y = qp->mouse.y;
			qp->itail = EVROUND(qp->itail+1);
		}
	}
	/*
	 * See if mouse switches have changed.
	 */
switches:if( om_switch != ( m_switch = (qvaddr->qv_csr & QV_MOUSE_ANY) >> 8 ) ) {
		qp->mswitches = ~m_switch & 0x7;
		for (j = 0; j < 3; j++) {	/* check each switch */
			register vsEvent *vep;
			if ( ((om_switch>>j) & 1) == ((m_switch>>j) & 1) )
				continue;
			/* check for room in the queue */
			if ((i = EVROUND(qp->itail+1)) == qp->ihead) return;
			/* put event into queue and do select */
			vep = &qp->ibuff[qp->itail];
			vep->vse_type = VSE_BUTTON;
			vep->vse_key = 2 - j;
			vep->vse_direction = VSE_KBTDOWN;
			if ( (m_switch >> j) & 1)
				vep->vse_direction = VSE_KBTUP;
			vep->vse_device = VSE_MOUSE;
			vep->vse_time = TOY;
			vep->vse_x = qp->mouse.x;
			vep->vse_y = qp->mouse.y;
		}
		qp->itail =  i;
		om_switch = m_switch;
		qp->mswitches = m_switch;
	}
	/* if we have proc waiting, and event has happened, wake him up */
D 7
	if(rsel && (qp->ihead != qp->itail)) {
		selwakeup(rsel,0);
		rsel = 0;
E 7
I 7
	if(qvrsel && (qp->ihead != qp->itail)) {
		selwakeup(qvrsel,0);
		qvrsel = 0;
E 7
	}
	/*
	 * Okay we can take another hit now
	 */
	qv_ipl_lo = 1;
}

/*
 * Start  transmission
 */
qvstart(tp)
	register struct tty *tp;
{
	register int unit, c;
	register struct tty *tp0;
	int s;

	unit = minor(tp->t_dev);
D 3
	tp0 = &qv_tty[(unit&0xfc)+1];
	unit &= 03;
E 3
I 3
#ifdef CONS_HACK
	tp0 = &qv_tty[(unit&0xfc)+QVPCONS];
#endif
	unit = QVCHAN(unit);
E 3

	s = spl5();
	/*
	 * If it's currently active, or delaying, no need to do anything.
	 */
	if (tp->t_state&(TS_TIMEOUT|TS_BUSY|TS_TTSTOP))
		goto out;
	/*
	 * Display chars until the queue is empty, if the second subchannel
	 * is open direct them there. Drop characters from subchannels other
	 * than 0 on the floor.
	 */

	while( tp->t_outq.c_cc ) {
		c = getc(&tp->t_outq);
D 3
		if( (unit & 0x03)  == 0 )
E 3
I 3
		if (unit == QVKEYBOARD)
#ifdef CONS_HACK
E 3
			if( tp0->t_state & TS_ISOPEN ){
				(*linesw[tp0->t_line].l_rint)(c, tp0);
			} else
D 3
				qvputc( c & 0xff );
E 3
I 3
#endif
				qvputchar( c & 0xff );
E 3
	}
	/*
	 * Position the cursor to the next character location.
	 */
	qv_pos_cur( qv_scn->col*8, qv_scn->row*15 );

	/*
	 * If there are sleepers, and output has drained below low
	 * water mark, wake up the sleepers.
	 */
	if ( tp->t_outq.c_cc<=TTLOWAT(tp) ) {
		if (tp->t_state&TS_ASLEEP){
			tp->t_state &= ~TS_ASLEEP;
			wakeup((caddr_t)&tp->t_outq);
		}
	}
	tp->t_state &= ~TS_BUSY;
out:
	splx(s);
}

/*
 * Stop output on a line, e.g. for ^S/^Q or output flush.
 */
/*ARGSUSED*/
qvstop(tp, flag)
	register struct tty *tp;
{
	register int s;

	/*
	 * Block input/output interrupts while messing with state.
	 */
	s = spl5();
	if (tp->t_state & TS_BUSY) {
		if ((tp->t_state&TS_TTSTOP)==0) {
			tp->t_state |= TS_FLUSH;
		} else
			tp->t_state &= ~TS_BUSY;
	}
	splx(s);
}

I 3
qvputc(c)
char c;
{
	qvputchar(c);
	if (c == '\n')
		qvputchar('\r');
}

E 3
/*
 * Routine to display a character on the screen.  The model used is a 
 * glass tty.  It is assummed that the user will only use this emulation
 * during system boot and that the screen will be eventually controlled
 * by a window manager.
 *
 */
D 3
qvputc( c )
E 3
I 3
qvputchar( c )
E 3
register char c;
{

	register char *b_row, *f_row;
	register int i;
	register short *scanline;
	register int ote = 128;
	register struct qv_info *qp = qv_scn;

	/*
	 * This routine may be called in physical mode by the dump code
	 * so we check and punt if that's the case.
	 */
	if( (mfpr(MAPEN) & 1) == 0 )
		return;

	c &= 0x7f;

	switch ( c ) {
	case '\t':				/* tab		*/
		for( i = 8 - (qp->col & 0x7) ; i > 0 ; i-- )
D 3
			qvputc( ' ' );
E 3
I 3
			qvputchar( ' ' );
E 3
		break;

	case '\r':				/* return	*/
		qp->col = 0;
		break;

	case '\010':				/* backspace	*/
		if( --qp->col < 0 )
			qp->col = 0;
		break;

	case '\n':				/* linefeed	*/
		if( qp->row+1 >= qp->max_row )
			qvscroll();
		else
			qp->row++;
		/*
		* Position the cursor to the next character location.
		*/
		qv_pos_cur( qp->col*8, qp->row*15 );
		break;

	case '\007':				/* bell		*/
                /*
                 * We don't do anything to the keyboard until after
                 * autoconfigure.
                 */
		if( qp->qvaddr )
			qv_key_out( LK_RING_BELL );
		return;

	default:
		if( c >= ' ' && c <= '~' ) {
                        scanline = qp->scanmap;
                        b_row = qp->bitmap+(scanline[qp->row*15]&0x3ff)*128+qp->col;
			i = c - ' ';
			if( i < 0 || i > 95 )
				i = 0;
			else
				i *= 15;
			f_row = (char *)((int)q_font + i);
		
/*			for( i=0 ; i<15 ; i++ , b_row += 128, f_row++ )
				*b_row = *f_row;*/
			/* inline expansion for speed */
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;
			*b_row = *f_row++; b_row += ote;

			if( ++qp->col >= qp->max_col ) {
				qp->col = 0 ;
				if( qp->row+1 >= qp->max_row )
					qvscroll();
				else
					qp->row++;
			}
		}
		break;
	}
}

/*
 * Position the cursor to a particular spot.
 */
qv_pos_cur( x, y)
register int x,y;
{
	register struct qvdevice *qvaddr;
	register struct qv_info *qp = qv_scn;
	register index;

	if( qvaddr = qp->qvaddr ) {
		if( y < 0 || y > qp->max_cur_y )
			y = qp->max_cur_y;
		if( x < 0 || x > qp->max_cur_x )
			x = qp->max_cur_x;
		qp->cursor.x = x;		/* keep track of real cursor*/
		qp->cursor.y = y;		/* position, indep. of mouse*/

		qvaddr->qv_crtaddr = 10;	/* select cursor start reg */
		qvaddr->qv_crtdata = y & 0xf;
		qvaddr->qv_crtaddr = 11;	/* select cursor end reg */
		qvaddr->qv_crtdata = y & 0xf;
		qvaddr->qv_crtaddr = 14;	/* select cursor y pos. */
		qvaddr->qv_crtdata = y >> 4;
		qvaddr->qv_xcur = x;		/* pos x axis	*/
		/*
		 * If the mouse is being used then we change the mode of
		 * cursor display based on the pixels under the cursor
		 */
		if( mouseon ) {
			index = y*128 + x/8;
			if( qp->bitmap[ index ] && qp->bitmap[ index+128 ] )
				qvaddr->qv_csr &= ~QV_CUR_MODE;
			else
				qvaddr->qv_csr |=  QV_CUR_MODE;
		}
	}
}
/*
 * Scroll the bitmap by moving the scanline map words. This could
 * be done by moving the bitmap but it's much too slow for a full screen.
 * The only drawback is that the scanline map must be reset when the user 
 * wants to do graphics.
 */
qvscroll()
{
	short tmpscanlines[15];
	register char *b_row;
	register short *scanline;
	register struct qv_info *qp = qv_scn;

	/*
	 * If the mouse is on we don't scroll so that the bit map
	 * remains sane.
	 */
	if( mouseon ) {
		qp->row = 0;
		return;
	}
	/*
	 * Save the first 15 scanlines so that we can put them at
	 * the bottom when done.
	 */
D 7
	bcopy( qp->scanmap, tmpscanlines, sizeof tmpscanlines );
E 7
I 7
	bcopy((caddr_t)qp->scanmap, (caddr_t)tmpscanlines, sizeof tmpscanlines);
E 7

	/*
	 * Clear the wrapping line so that it won't flash on the bottom
	 * of the screen.
	 */
        scanline = qp->scanmap;
        b_row = qp->bitmap+(*scanline&0x3ff)*128;
	bzero( b_row, 1920 );

	/*
	 * Now move the scanlines down 
	 */
D 7
	bcopy( qp->scanmap+15, qp->scanmap, (qp->row * 15) * sizeof (short) );
E 7
I 7
	bcopy((caddr_t)(qp->scanmap+15), (caddr_t)qp->scanmap,
	      (qp->row * 15) * sizeof (short) );
E 7

	/*
	 * Now put the other lines back
	 */
D 7
	bcopy( tmpscanlines, qp->scanmap+(qp->row * 15), sizeof tmpscanlines );
E 7
I 7
	bcopy((caddr_t)tmpscanlines, (caddr_t)(qp->scanmap+(qp->row * 15)),
	      sizeof (tmpscanlines) );
E 7

}

/*
 * Output to the keyboard. This routine status polls the transmitter on the
 * keyboard to output a code. The timer is to avoid hanging on a bad device.
 */
D 7
qv_key_out( c )
char c;
E 7
I 7
qv_key_out(c)
	u_short c;
E 7
{
	int timer = 30000;
	register struct qv_info *qp = qv_scn;

D 7
	if( qp->qvaddr ) {
		while( (qp->qvaddr->qv_uartstatus & 0x4) == 0  && timer-- )
E 7
I 7
	if (qp->qvaddr) {
		while ((qp->qvaddr->qv_uartstatus & 0x4) == 0  && timer--)
E 7
			;
		qp->qvaddr->qv_uartdata = c;
	}
}
/*
 * Virtual console initialization. This routine sets up the qvss so that it can
 * be used as the system console. It is invoked before autoconfig and has to do
 * everything necessary to allow the device to serve as the system console. 
 * In this case it must map the q-bus and device areas and initialize the qvss 
 * screen.
 */
qvcons_init()
{
        struct percpu *pcpu;            /* pointer to percpu structure  */
I 2
	register struct qbus *qb;
E 2
        struct qvdevice *qvaddr;        /* device pointer               */
D 3
        short *devptr;                  /* vitual device space          */
E 3
I 3
        short *devptr;                  /* virtual device space         */
	extern cnputc();		/* standard serial console putc */
E 3
#define QVSSCSR 017200

I 3
	/*
	 * If secondary console already configured,
	 * don't override the previous one.
	 */
	if (v_putc != cnputc)
D 7
		return;
E 7
I 7
		return 0;
E 7
E 3
        /*
         * find the percpu entry that matches this machine.
         */
        for( pcpu = percpu ; pcpu && pcpu->pc_cputype != cpu ; pcpu++ )
                ;
        if( pcpu == NULL )
D 3
                return(0);
E 3
I 3
D 7
                return;
E 7
I 7
                return 0;
I 9
	if (pcpu->pc_io->io_type != IO_QBUS)
		return 0;
E 9
E 7
E 3

        /*
         * Found an entry for this cpu. Because this device is Microvax specific
         * we assume that there is a single q-bus and don't have to worry about
         * multiple adapters.
         *
D 2
         * Map the bus memory and device registers.
E 2
I 2
         * Map the device registers.
E 2
         */
D 2
        ubaaccess(pcpu->pc_umaddr[0], UMEMmap[0],
                pcpu->pc_umsize, PG_V|PG_KW);
        ubaaccess(pcpu->pc_devaddr[0], UMEMmap[0]+btop(pcpu->pc_umsize),
                DEVSPACESIZE ,PG_V|PG_KW);
        
E 2
I 2
	qb = (struct qbus *)pcpu->pc_io->io_details;
D 7
	ioaccess(qb->qb_iopage, UMEMmap[0] + qb->qb_memsize,
	    UBAIOPAGES * NBPG);
E 7
I 7
	ioaccess(qb->qb_iopage, UMEMmap[0] + qb->qb_memsize, UBAIOPAGES * NBPG);
E 7

E 2
        /*
         * See if the qvss is there.
         */
D 2
        devptr = (short *)((char *)umem[0]+pcpu->pc_umsize);
E 2
I 2
        devptr = (short *)((char *)umem[0] + (qb->qb_memsize * NBPG));
E 2
        qvaddr = (struct qvdevice *)((u_int)devptr + ubdevreg(QVSSCSR));
D 7
        if( badaddr( qvaddr, sizeof(short) ) )
D 3
                return(0);
E 3
I 3
                return;
E 7
I 7
        if (badaddr((caddr_t)qvaddr, sizeof(short)))
                return 0;
E 7
E 3
        /*
         * Okay the device is there lets set it up
         */
D 2
        qv_setup( qvaddr );
E 2
I 2
D 7
        qv_setup(qvaddr, 0, 0);
E 7
I 7
        if (!qv_setup(qvaddr, 0, 0))
		return 0;
E 7
E 2
D 3
	v_console = qvputc;
        cdevsw[0] = cdevsw[QVSSMAJOR];
	return(1);
E 3
I 3
	v_putc = qvputc;
        consops = &cdevsw[QVSSMAJOR];
I 7
	return 1;
E 7
E 3
}
/*
 * Do the board specific setup
 */
D 2
qv_setup( qvaddr )
E 2
I 2
qv_setup(qvaddr, unit, probed)
E 2
struct qvdevice *qvaddr;
I 2
int unit;
int probed;
E 2
{
D 2
        char *qvssmem;                  /* pointer to the display mem   */
        int i;                          /* simple index                 */
E 2
I 2
        caddr_t qvssmem;		/* pointer to the display mem   */
        register i;			/* simple index                 */
E 2
	register struct qv_info *qp;
I 2
        register int *pte;
        struct percpu *pcpu;            /* pointer to percpu structure  */
	register struct qbus *qb;
E 2

D 2
        qvssmem = (char *)
                (( (u_int)(qvaddr->qv_csr & QV_MEM_BANK) <<7 ) + (u_int)umem[0]);
        qv_scn = (struct qv_info *)
                ((u_int)qvssmem + 251*1024);
E 2
I 2
        /*
         * find the percpu entry that matches this machine.
         */
        for( pcpu = percpu ; pcpu && pcpu->pc_cputype != cpu ; pcpu++ )
                ;
        if( pcpu == NULL )
                return(0);

        /*
         * Found an entry for this cpu. Because this device is Microvax specific
         * we assume that there is a single q-bus and don't have to worry about
         * multiple adapters.
         *
         * Map the device memory.
         */
	qb = (struct qbus *)pcpu->pc_io->io_details;

        i = (u_int)(qvaddr->qv_csr & QV_MEM_BANK) << 7;
	ioaccess(qb->qb_maddr + i, QVmap[unit], 512 * NBPG);
	qvssmem = qvmem[unit];
        pte = (int *)(QVmap[unit]);
        for (i=0; i < 512; i++, pte++)
                *pte = (*pte & ~PG_PROT) | PG_UW | PG_V;

        qv_scn = (struct qv_info *)((u_int)qvssmem + 251*1024);
E 2
	qp = qv_scn;
        if( (qvaddr->qv_csr & QV_19INCH) && qv_def_scrn == 0)
                qv_def_scrn = 1;
        *qv_scn = qv_scn_defaults[ qv_def_scrn ];
I 2
	if (probed)
		qp->qvaddr = qvaddr;
E 2
 	qp->bitmap = qvssmem;
        qp->scanmap = (short *)((u_int)qvssmem + 254*1024);
        qp->cursorbits = (short *)((u_int)qvssmem + 256*1024-32);
	/* set up event queue for later */
	qp->ibuff = (vsEvent *)qp - QVMAXEVQ;
	qp->iqsize = QVMAXEVQ;
	qp->ihead = qp->itail = 0;

        /*
         * Setup the crt controller chip.
         */
        for( i=0 ; i<16 ; i++ ) {
                qvaddr->qv_crtaddr = i;
                qvaddr->qv_crtdata = qv_crt_parms[ qv_def_scrn ][ i ];
        }
        /*
         * Setup the display.
         */
        qv_init( qvaddr );

        /*
         * Turn on the video
         */
        qvaddr->qv_csr |= QV_VIDEO_ENA ;
I 7
	return 1;
E 7
}
#endif
E 1
