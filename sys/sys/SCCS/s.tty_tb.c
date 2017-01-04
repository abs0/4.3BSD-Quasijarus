h42935
s 00000/00006/00341
d D 7.4 87/07/27 17:12:20 mckusick 20 19
c delete unneeded header files
e
s 00024/00010/00323
d D 7.3 86/12/14 14:52:07 sam 19 18
c add new gtco types; generalize in-proximity status bit (from pixar!sam)
e
s 00001/00001/00332
d D 7.2 86/11/03 12:00:39 karels 18 17
c merge in tahoe support
e
s 00001/00001/00332
d D 7.1 86/06/05 00:10:43 mckusick 17 16
c 4.3BSD release version
e
s 00205/00088/00128
d D 6.6 85/11/06 18:25:51 sam 16 15
c bring in updated version from lfl; supports setting tablet type and 
c operating mode via ioctl's; handles ~half dozen tablet types
e
s 00007/00001/00209
d D 6.5 85/06/08 14:48:02 mckusick 15 14
c Add copyright
e
s 00000/00001/00210
d D 6.4 85/03/19 20:48:07 mckusick 14 13
c eliminate extraneous include of conf.h
e
s 00012/00012/00199
d D 6.3 84/08/29 20:24:53 bloom 13 12
c Change to includes.  no more ../h
e
s 00002/00003/00209
d D 6.2 83/09/22 07:57:04 mckusick 12 11
c fix for close bug in tablet driver (from dagobah!bill)
e
s 00000/00000/00212
d D 6.1 83/08/13 12:32:12 sam 11 10
c 4.2 distribution
e
s 00054/00044/00158
d D 4.9 83/08/13 12:31:27 sam 10 8
c update from reeves; eliminates overlaid c-list q; tested with 4.2
e
s 00000/00000/00202
d R 6.1 83/07/29 06:40:17 sam 9 8
c 4.2 distribution
e
s 00001/00001/00201
d D 4.8 83/05/27 12:49:04 sam 8 7
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00001/00000/00201
d D 4.7 82/12/05 22:01:28 sam 7 6
c include ioctl.h separate from tty.h
e
s 00004/00008/00197
d D 4.6 82/10/17 11:30:05 root 6 5
c returns error in open, ioctl
e
s 00023/00033/00182
d D 4.5 82/10/13 22:09:16 root 5 4
c return errors from ioctl routines and internal ldisc routines
e
s 00001/00001/00214
d D 4.4 82/08/22 21:19:23 root 4 3
c fully uio()'d
e
s 00006/00008/00209
d D 4.3 82/08/13 00:16:41 root 3 2
c changes for char dev uio'ing
e
s 00005/00005/00212
d D 4.2 82/08/01 19:25:49 sam 2 1
c new ioctl's
e
s 00217/00000/00000
d D 4.1 82/06/26 16:09:08 sam 1 0
c date and time created 82/06/26 16:09:08 by sam
e
u
U
t
T
I 1
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
/*
D 17
 * Copyright (c) 1982 Regents of the University of California.
E 17
I 17
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 15

#include "tb.h"
#if NTB > 0

I 16
/*
 * Line discipline for RS232 tablets;
 * supplies binary coordinate data.
 */
E 16
D 13
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
I 7
#include "../h/ioctl.h"
E 7
#include "../h/tty.h"
#include "../h/proc.h"
#include "../h/inode.h"
#include "../h/file.h"
#include "../h/conf.h"
#include "../h/buf.h"
I 3
#include "../h/uio.h"
E 13
I 13
#include "param.h"
D 20
#include "systm.h"
E 20
#include "dir.h"
#include "user.h"
D 16
#include "ioctl.h"
E 16
I 16
#include "tablet.h"
E 16
#include "tty.h"
D 20
#include "proc.h"
#include "inode.h"
#include "file.h"
D 14
#include "conf.h"
E 14
#include "buf.h"
#include "uio.h"
E 20
E 13
E 3

/*
D 16
 * Line discipline for RS232 tablets.
I 5
 * Supplies binary coordinate data.
E 5
 *
D 5
 * This supplies binary coordinate data to a user level program
 * with a minimum of fuss.
 *
 * This discipline requires that tty device drivers call
 * the line specific l_ioctl routine from their ioctl routines,
 * assigning the result to cmd so that we can refuse most tty specific
 * ioctls which are unsafe because we have ambushed the
 * teletype input queues and other data, overlaying them with
 * the following information: the tty queue header, t_un.T_CTLQ,
 * is overlaid with a MTABCHAR character buffer -- the raw input
 * chars. The local characters (t_rocount on) are overlaid with
 * the current coordinate position.
E 5
I 5
D 10
 * FIX WAY IN WHICH OVERLAYING IS DONE
E 10
 * MAKE TABLET TYPE AN ioctl TO AVOID HAVING ONE DISCIPLINE PER TABLET TYPE.
E 16
I 16
 * Tablet configuration table.
E 16
E 5
 */
I 16
struct	tbconf {
	short	tbc_recsize;	/* input record size in bytes */
	short	tbc_uiosize;	/* size of data record returned user */
	int	tbc_sync;	/* mask for finding sync byte/bit */
	int	(*tbc_decode)();/* decoding routine */
	char	*tbc_run;	/* enter run mode sequence */
	char	*tbc_point;	/* enter point mode sequence */
	char	*tbc_stop;	/* stop sequence */
	char	*tbc_start;	/* start/restart sequence */
	int	tbc_flags;
D 19
#define	TBF_POL	0x1	/* polhemus hack */
E 19
I 19
#define	TBF_POL		0x1	/* polhemus hack */
#define	TBF_INPROX	0x2	/* tablet has proximity info */
E 19
};
E 16

D 10
#define MTABCHAR 5
#define MNTABCHAR 6
E 10
I 10
D 16
#define NTBS		(16)
#define MALLTABCHAR	(8)
#define MTABCHAR 	(5)
#define MNTABCHAR	(6)
E 16
I 16
static	int tbdecode(), gtcodecode(), poldecode();
static	int tblresdecode(), tbhresdecode();
E 16
E 10
I 5

I 16
struct	tbconf tbconf[TBTYPE] = {
{ 0 },
{ 5, sizeof (struct tbpos), 0200, tbdecode, "6", "4" },
{ 5, sizeof (struct tbpos), 0200, tbdecode, "\1CN", "\1RT", "\2", "\4" },
{ 8, sizeof (struct gtcopos), 0200, gtcodecode },
{17, sizeof (struct polpos), 0200, poldecode, 0, 0, "\21", "\5\22\2\23",
D 19
 TBF_POL },
{ 5, sizeof (struct tbpos), 0100, tblresdecode, "\1CN", "\1PT", "\2", "\4"},
{ 6, sizeof (struct tbpos), 0200, tbhresdecode, "\1CN", "\1PT", "\2", "\4"},
E 19
I 19
  TBF_POL },
{ 5, sizeof (struct tbpos), 0100, tblresdecode, "\1CN", "\1PT", "\2", "\4",
  TBF_INPROX },
{ 6, sizeof (struct tbpos), 0200, tbhresdecode, "\1CN", "\1PT", "\2", "\4",
  TBF_INPROX },
{ 5, sizeof (struct tbpos), 0100, tblresdecode, "\1CL\33", "\1PT\33", 0, 0},
{ 6, sizeof (struct tbpos), 0200, tbhresdecode, "\1CL\33", "\1PT\33", 0, 0},
E 19
};

/*
 * Tablet state
 */
E 16
E 5
D 10
struct tbposition {
D 5
	int xpos;
	int ypos;
	short int status;
	short int scount;
E 5
I 5
	int	xpos;
	int	ypos;
	short	status;
	short	scount;
E 5
};
E 10
I 10
struct tb {
D 16
	short used;
	char cbuf[MALLTABCHAR];
	struct tbpos {
		int	xpos;
		int	ypos;
		short	status;
		short	scount;
	} tbpos;
E 16
I 16
	int	tbflags;		/* mode & type bits */
#define	TBMAXREC	17	/* max input record size */
	char	cbuf[TBMAXREC];		/* input buffer */
	union {
		struct	tbpos tbpos;
		struct	gtcopos gtcopos;
		struct	polpos polpos;
	} rets;				/* processed state */
#define NTBS	16
E 16
} tb[NTBS];
E 10

/*
D 16
 * Open as tablet discipline.  Called when discipline changed
 * with ioctl, and changes the interpretation of the information
 * in the tty structure.
E 16
I 16
 * Open as tablet discipline; called on discipline change.
E 16
 */
/*ARGSUSED*/
tbopen(dev, tp)
D 2
dev_t dev;
register struct tty *tp;
E 2
I 2
	dev_t dev;
	register struct tty *tp;
E 2
{
D 10
	register struct tbposition *tbp;
E 10
I 10
	register struct tb *tbp;
E 10

D 6
	if (u.u_error)
		return;		/* paranoia */
E 6
D 10
	if (tp->t_line == TABLDISC || tp->t_line == NTABLDISC) {
D 6
		u.u_error = EBUSY;
		return;	
	}
E 6
I 6
		return (EBUSY);
E 10
I 10
D 16
	if (tp->t_line == TABLDISC || tp->t_line == NTABLDISC)
E 16
I 16
	if (tp->t_line == TABLDISC)
E 16
		return (ENODEV);
E 10
E 6
D 8
	wflushtty(tp);
E 8
I 8
	ttywflush(tp);
E 8
D 10
	tp->t_cp = (char *) &tp->t_un.T_CTLQ;	/* overlay control queue */
E 10
I 10
	for (tbp = tb; tbp < &tb[NTBS]; tbp++)
D 16
		if (!tbp->used)
E 16
I 16
		if (tbp->tbflags == 0)
E 16
			break;
	if (tbp >= &tb[NTBS])
		return (EBUSY);
D 16
	tbp->used++;
E 16
I 16
	tbp->tbflags = TBTIGER|TBPOINT;		/* default */
E 16
	tp->t_cp = tbp->cbuf;
E 10
	tp->t_inbuf = 0;
D 10
	tbp = (struct tbposition *) &tp->t_rocount;
	tbp->xpos = tbp->ypos = tbp->status = tbp->scount = 0;
E 10
I 10
D 16
	tbp->tbpos.xpos = tbp->tbpos.ypos = 0;
	tbp->tbpos.status = tbp->tbpos.scount = 0;
	tp->T_LINEP = (caddr_t) tbp;
E 16
I 16
	bzero((caddr_t)&tbp->rets, sizeof (tbp->rets));
	tp->T_LINEP = (caddr_t)tbp;
	tp->t_flags |= LITOUT;
E 16
E 10
I 6
	return (0);
E 6
}

/*
D 16
 * Break down... called when discipline changed or from device
 * close routine.
E 16
I 16
 * Line discipline change or last device close.
E 16
 */
tbclose(tp)
D 6
register struct tty *tp;
E 6
I 6
	register struct tty *tp;
E 6
{
D 6
	register s;
E 6
I 6
D 16
	register int s = spl5();
E 16
I 16
	register int s;
	int modebits = TBPOINT|TBSTOP;
E 16
E 6

I 12
D 16
	((struct tb *) tp->T_LINEP)->used = 0;
E 16
I 16
	tbioctl(tp, BIOSMODE, &modebits, 0);
D 18
	s = spl5();
E 18
I 18
	s = spltty();
E 18
	((struct tb *)tp->T_LINEP)->tbflags = 0;
E 16
E 12
D 6
	s = spl5();
E 6
	tp->t_cp = 0;
	tp->t_inbuf = 0;
	tp->t_rawq.c_cc = 0;		/* clear queues -- paranoid */
	tp->t_canq.c_cc = 0;
D 10
	tp->t_un.T_CTLQ.c_cc = 0;	/* clear overlaid queue status */
	tp->t_un.T_CTLQ.c_cf = tp->t_un.T_CTLQ.c_cl = NULL;
E 10
D 12
	tp->t_line = 0;		/* paranoid: avoid races */
E 12
I 12
	tp->t_line = 0;			/* paranoid: avoid races */
E 12
	splx(s);
}

/*
 * Read from a tablet line.
D 16
 * Characters have been buffered in a buffer and
 * decoded. The coordinates are now sluffed back to the user.
E 16
I 16
 * Characters have been buffered in a buffer and decoded.
E 16
 */
D 3
tbread(tp)
register struct tty *tp;
E 3
I 3
tbread(tp, uio)
	register struct tty *tp;
	struct uio *uio;
E 3
{
D 12
	register int i;
	register s;
E 12
D 10
	struct tbposition tbposition;
E 10
I 10
D 16
	struct tbpos *tbpos;
E 16
I 16
	register struct tb *tbp = (struct tb *)tp->T_LINEP;
	register struct tbconf *tc = &tbconf[tbp->tbflags & TBTYPE];
	int ret;
E 16
E 10

D 16
	if ((tp->t_state&TS_CARR_ON)==0)
E 16
I 16
	if ((tp->t_state&TS_CARR_ON) == 0)
E 16
D 5
		return (-1);
D 3
	if (copyout(&tp->t_rocount, u.u_base, (unsigned)(sizeof tbposition))) {
		u.u_error = EFAULT;
E 3
I 3
D 4
	u.u_error = copyuout(uio, &tp->t_rocount, sizeof tbposition);
E 4
I 4
	u.u_error = iomove(&tp->t_rocount, sizeof tbposition, UIO_READ, uio);
E 4
	if (u.u_error)
E 3
		return (-1);
D 3
	}
	u.u_count -= sizeof tbposition;
	u.u_base += sizeof tbposition;
	u.u_offset += sizeof tbposition;
E 3
	return (0);
E 5
I 5
		return (EIO);
D 10
	return (iomove(&tp->t_rocount, sizeof tbposition, UIO_READ, uio));
E 10
I 10
D 16
	tbpos = &(((struct tb *) (tp->T_LINEP))->tbpos);
	return (uiomove(tbpos, sizeof *tbpos, UIO_READ, uio));
E 16
I 16
	ret = uiomove(&tbp->rets, tc->tbc_uiosize, UIO_READ, uio);
	if (tc->tbc_flags&TBF_POL)
		tbp->rets.polpos.p_key = ' ';
	return (ret);
E 16
E 10
E 5
}

/*
 * Low level character input routine.
D 16
 * Stuff the character in the buffer, and decode the it
E 16
I 16
 * Stuff the character in the buffer, and decode
E 16
 * if all the chars are there.
 *
 * This routine could be expanded in-line in the receiver
D 16
 * interrupt routine of the dh-11 to make it run as fast as possible.
E 16
I 16
 * interrupt routine to make it run as fast as possible.
E 16
 */
D 5
int LASTTABC;
E 5
I 5
D 16
int	LASTTABC;

E 16
E 5
tbinput(c, tp)
D 5
register c;
register struct tty *tp;
E 5
I 5
	register int c;
	register struct tty *tp;
E 5
{
I 10
D 16
	register struct tb *tbp = (struct tb *) tp->T_LINEP;
E 16
I 16
	register struct tb *tbp = (struct tb *)tp->T_LINEP;
	register struct tbconf *tc = &tbconf[tbp->tbflags & TBTYPE];
E 16
E 10

D 5
	if(tp->t_line == TABLDISC) {
		if((c&0200) || (tp->t_inbuf == MTABCHAR)) {
E 5
I 5
D 16
	if (tp->t_line == TABLDISC) {
		if ((c&0200) || (tp->t_inbuf == MTABCHAR)) {
E 5
D 10
			tp->t_cp = (char *) &tp->t_un.T_CTLQ;
E 10
I 10
			tp->t_cp = tbp->cbuf;
E 10
			tp->t_inbuf = 0;
		}
		*tp->t_cp++ = c&0177;
D 5
		if(++tp->t_inbuf == MTABCHAR)
E 5
I 5
		if (++tp->t_inbuf == MTABCHAR)
E 5
D 10
			tbdecode((char *) &tp->t_un.T_CTLQ,
D 5
					(struct tbposition *) &tp->t_rocount);
	} else if(tp->t_line == NTABLDISC) {
		if((c&0200) || (tp->t_inbuf == MNTABCHAR)) {
E 5
I 5
				(struct tbposition *) &tp->t_rocount);
E 10
I 10
			tbdecode(tbp->cbuf, &tbp->tbpos);
E 10
	} else if (tp->t_line == NTABLDISC) {
		if ((c&0200) || (tp->t_inbuf == MNTABCHAR)) {
E 5
D 10
			tp->t_cp = (char *) &tp->t_un.T_CTLQ;
E 10
I 10
			tp->t_cp = tbp->cbuf;
E 10
			tp->t_inbuf = 0;
		}
		*tp->t_cp++ = c&0177;
D 5
		if(++tp->t_inbuf == MNTABCHAR)
E 5
I 5
		if (++tp->t_inbuf == MNTABCHAR)
E 5
D 10
			tbndecode((char *) &tp->t_un.T_CTLQ,
					(struct tbposition *) &tp->t_rocount);
E 10
I 10
			tbndecode(tbp->cbuf, &tbp->tbpos);
E 16
I 16
	if (tc->tbc_recsize == 0 || tc->tbc_decode == 0)	/* paranoid? */
		return;
	/*
	 * Locate sync bit/byte or reset input buffer.
	 */
	if (c&tc->tbc_sync || tp->t_inbuf == tc->tbc_recsize) {
		tp->t_cp = tbp->cbuf;
		tp->t_inbuf = 0;
E 16
E 10
	}
I 16
	*tp->t_cp++ = c&0177;
	/*
	 * Call decode routine only if a full record has been collected.
	 */
	if (++tp->t_inbuf == tc->tbc_recsize)
D 19
		(*tc->tbc_decode)(tbp->cbuf, &tbp->rets);
E 19
I 19
		(*tc->tbc_decode)(tc, tbp->cbuf, &tbp->rets);
E 19
E 16
}

/*
D 16
 * Decode tablet coordinates from ascii to binary.
 *	(gtco 6 character format)
E 16
I 16
 * Decode GTCO 8 byte format (high res, tilt, and pressure).
E 16
 */
D 10
tbndecode(cp, tbposition)
E 10
I 10
D 16
tbndecode(cp, tbpos)
E 16
I 16
static
D 19
gtcodecode(cp, tbpos)
E 19
I 19
gtcodecode(tc, cp, tbpos)
	struct tbconf *tc;
E 19
E 16
E 10
	register char *cp;
D 10
	register struct tbposition *tbposition;
E 10
I 10
D 16
	register struct tbpos *tbpos;
E 16
I 16
	register struct gtcopos *tbpos;
E 16
E 10
{

D 10
	tbposition->status = *cp>>2;	/* this needs to be decoded */
	tbposition->xpos = ((*cp++)&03)<<14;
	tbposition->xpos |= (*cp++)<<7;
	tbposition->xpos |= (*cp++);
	tbposition->ypos = ((*cp++)&03)<<14;
	tbposition->ypos |= (*cp++)<<7;
	tbposition->ypos |= (*cp++);
	tbposition->scount++;
E 10
I 10
D 16
	tbpos->status = *cp>>2;	/* this needs to be decoded */
	tbpos->xpos = ((*cp++)&03)<<14;
	tbpos->xpos |= (*cp++)<<7;
	tbpos->xpos |= (*cp++);
	tbpos->ypos = ((*cp++)&03)<<14;
	tbpos->ypos |= (*cp++)<<7;
	tbpos->ypos |= (*cp++);
E 16
I 16
	tbpos->pressure = *cp >> 2;
	tbpos->status = (tbpos->pressure > 16) | TBINPROX; /* half way down */
	tbpos->xpos = (*cp++ & 03) << 14;
	tbpos->xpos |= *cp++ << 7;
	tbpos->xpos |= *cp++;
	tbpos->ypos = (*cp++ & 03) << 14;
	tbpos->ypos |= *cp++ << 7;
	tbpos->ypos |= *cp++;
	tbpos->xtilt = *cp++;
	tbpos->ytilt = *cp++;
E 16
	tbpos->scount++;
E 10
}

/*
D 16
 * Decode tablet coordinates from ascii to binary.
 *	(hitachi 5 character format)
E 16
I 16
 * Decode old Hitachi 5 byte format (low res).
E 16
 */
I 16
static
E 16
D 10
tbdecode(cp, tbposition)
E 10
I 10
D 19
tbdecode(cp, tbpos)
E 19
I 19
tbdecode(tc, cp, tbpos)
	struct tbconf *tc;
E 19
E 10
	register char *cp;
D 10
	register struct tbposition *tbposition;
E 10
I 10
	register struct tbpos *tbpos;
E 10
{
D 16
	register int status;
E 16
	register char byte;

	byte = *cp++;
D 16
	status = (byte&0100) ? 0100000 : 0;
E 16
I 16
	tbpos->status = (byte&0100) ? TBINPROX : 0;
E 16
	byte &= ~0100;
D 5
	if(byte > 036)
E 5
I 5
	if (byte > 036)
E 5
D 16
		status |= 1<<((byte-040)/2);
D 10
	tbposition->xpos = (*cp++)<<7;
	tbposition->xpos |= (*cp++);
D 5
	if(tbposition->xpos < 256)	/* tablet wraps around at 256 */
E 5
I 5
	if (tbposition->xpos < 256)	/* tablet wraps around at 256 */
E 10
I 10
	tbpos->xpos = (*cp++)<<7;
	tbpos->xpos |= (*cp++);
	if (tbpos->xpos < 256)		/* tablet wraps around at 256 */
E 10
E 5
		status &= 077777;	/* make it out of proximity */
D 10
	tbposition->ypos = (*cp++)<<7;
	tbposition->ypos |= (*cp++);
	tbposition->status  = status;
	tbposition->scount++;
E 10
I 10
	tbpos->ypos = (*cp++)<<7;
	tbpos->ypos |= (*cp++);
	tbpos->status  = status;
E 16
I 16
		tbpos->status |= 1 << ((byte-040)/2);
	tbpos->xpos = *cp++ << 7;
	tbpos->xpos |= *cp++;
	if (tbpos->xpos < 256)			/* tablet wraps around at 256 */
		tbpos->status &= ~TBINPROX;	/* make it out of proximity */
	tbpos->ypos = *cp++ << 7;
	tbpos->ypos |= *cp++;
E 16
	tbpos->scount++;
E 10
}

/*
D 16
 * This routine is called whenever a ioctl is about to be performed
 * and gets a chance to reject the ioctl.  We reject all teletype
 * oriented ioctl's except those which set the discipline, and
 * those which get parameters (gtty and get special characters).
E 16
I 16
 * Decode new Hitach 5-byte format (low res).
E 16
 */
I 16
static
D 19
tblresdecode(cp, tbpos)
E 19
I 19
tblresdecode(tc, cp, tbpos)
	struct tbconf *tc;
E 19
	register char *cp;
	register struct tbpos *tbpos;
{

	*cp &= ~0100;		/* mask sync bit */
	tbpos->status = (*cp++ >> 2) | TBINPROX;
I 19
	if (tc->tbc_flags&TBF_INPROX && tbpos->status&020)
		tbpos->status &= ~(020|TBINPROX);
E 19
	tbpos->xpos = *cp++;
	tbpos->xpos |= *cp++ << 6;
	tbpos->ypos = *cp++;
	tbpos->ypos |= *cp++ << 6;
	tbpos->scount++;
}

/*
 * Decode new Hitach 6-byte format (high res).
 */
static
D 19
tbhresdecode(cp, tbpos)
E 19
I 19
tbhresdecode(tc, cp, tbpos)
	struct tbconf *tc;
E 19
	register char *cp;
	register struct tbpos *tbpos;
{
	char byte;

	byte = *cp++;
	tbpos->xpos = (byte & 03) << 14;
	tbpos->xpos |= *cp++ << 7;
	tbpos->xpos |= *cp++;
	tbpos->ypos = *cp++ << 14;
	tbpos->ypos |= *cp++ << 7;
	tbpos->ypos |= *cp++;
	tbpos->status = (byte >> 2) | TBINPROX;
I 19
	if (tc->tbc_flags&TBF_INPROX && tbpos->status&020)
		tbpos->status &= ~(020|TBINPROX);
E 19
	tbpos->scount++;
}

/*
 * Polhemus decode.
 */
static
D 19
poldecode(cp, polpos)
E 19
I 19
poldecode(tc, cp, polpos)
	struct tbconf *tc;
E 19
	register char *cp;
	register struct polpos *polpos;
{

	polpos->p_x = cp[4] | cp[3]<<7 | (cp[9] & 0x03) << 14;
	polpos->p_y = cp[6] | cp[5]<<7 | (cp[9] & 0x0c) << 12;
	polpos->p_z = cp[8] | cp[7]<<7 | (cp[9] & 0x30) << 10;
	polpos->p_azi = cp[11] | cp[10]<<7 | (cp[16] & 0x03) << 14;
	polpos->p_pit = cp[13] | cp[12]<<7 | (cp[16] & 0x0c) << 12;
	polpos->p_rol = cp[15] | cp[14]<<7 | (cp[16] & 0x30) << 10;
	polpos->p_stat = cp[1] | cp[0]<<7;
	if (cp[2] != ' ')
		polpos->p_key = cp[2];
}

E 16
/*ARGSUSED*/
D 2
tbioctl(tp, cmd, addr)
struct tty *tp;
caddr_t addr;
E 2
I 2
tbioctl(tp, cmd, data, flag)
	struct tty *tp;
	caddr_t data;
E 2
{
I 16
	register struct tb *tbp = (struct tb *)tp->T_LINEP;
E 16

D 16
	if ((cmd>>8) != 't')
		return (cmd);
E 16
	switch (cmd) {

I 16
	case BIOGMODE:
		*(int *)data = tbp->tbflags & TBMODE;
		break;

	case BIOSTYPE:
		if (tbconf[*(int *)data & TBTYPE].tbc_recsize == 0 ||
		    tbconf[*(int *)data & TBTYPE].tbc_decode == 0)
			return (EINVAL);
		tbp->tbflags &= ~TBTYPE;
		tbp->tbflags |= *(int *)data & TBTYPE;
		/* fall thru... to set mode bits */

	case BIOSMODE: {
		register struct tbconf *tc;

		tbp->tbflags &= ~TBMODE;
		tbp->tbflags |= *(int *)data & TBMODE;
		tc = &tbconf[tbp->tbflags & TBTYPE];
		if (tbp->tbflags&TBSTOP) {
			if (tc->tbc_stop)
				ttyout(tc->tbc_stop, tp);
		} else if (tc->tbc_start)
			ttyout(tc->tbc_start, tp);
		if (tbp->tbflags&TBPOINT) {
			if (tc->tbc_point)
				ttyout(tc->tbc_point, tp);
		} else if (tc->tbc_run)
			ttyout(tc->tbc_run, tp);
		ttstart(tp);
		break;
	}

	case BIOGTYPE:
		*(int *)data = tbp->tbflags & TBTYPE;
		break;

E 16
	case TIOCSETD:
	case TIOCGETD:
	case TIOCGETP:
	case TIOCGETC:
D 16
		return (cmd);
E 16
I 16
		return (-1);		/* pass thru... */

	default:
		return (ENOTTY);
E 16
	}
D 16
	u.u_error = ENOTTY;
E 16
	return (0);
}
#endif
E 1
