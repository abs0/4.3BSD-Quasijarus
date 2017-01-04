h54725
s 00001/00001/00202
d D 7.1 86/06/05 01:09:07 mckusick 20 19
c 4.3BSD release version
e
s 00001/00001/00202
d D 6.4 85/11/22 06:39:38 tef 19 18
c standard list of device addresses must be null terminated.
e
s 00007/00001/00196
d D 6.3 85/06/08 14:15:44 mckusick 18 17
c Add copyright
e
s 00009/00009/00188
d D 6.2 84/08/29 20:08:07 bloom 17 16
c Change to includes.  No more ../h
e
s 00000/00000/00197
d D 6.1 83/07/29 07:27:27 sam 16 15
c 4.2 distribution
e
s 00001/00001/00196
d D 4.15 82/12/17 12:01:53 sam 15 14
c sun merge
e
s 00000/00001/00197
d D 4.14 82/12/10 16:36:45 sam 14 13
c name conflicts
e
s 00002/00001/00196
d D 4.13 82/10/21 21:20:07 root 13 12
c lint
e
s 00001/00001/00196
d D 4.12 82/10/20 02:42:21 root 12 11
c lint
e
s 00002/00001/00195
d D 4.11 82/10/17 23:06:16 root 11 10
c lint
e
s 00008/00003/00188
d D 4.10 82/10/17 20:17:42 root 10 9
c lint
e
s 00010/00013/00181
d D 4.9 82/10/17 11:48:42 root 9 8
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00006/00004/00188
d D 4.8 82/10/10 22:37:38 root 8 7
c minor fixes relating to u.u_error handling
e
s 00002/00001/00190
d D 4.7 82/10/10 17:26:55 root 7 6
c header files for vax are in their place
e
s 00004/00003/00187
d D 4.6 82/08/22 21:17:41 root 6 5
c fully uio()'d
e
s 00001/00000/00189
d D 4.5 82/07/15 19:58:47 kre 5 4
c probe routines return size of unibus dev regs to reserve space
e
s 00036/00052/00153
d D 4.4 82/04/25 19:39:45 sam 4 3
c somehow a real old version snuck in
e
s 00003/00003/00202
d D 4.3 82/03/14 17:44:25 sam 3 2
c lint
e
s 00013/00007/00192
d D 4.2 81/11/18 15:49:13 wnj 2 1
c lint
e
s 00199/00000/00000
d D 4.1 81/11/04 10:44:41 wnj 1 0
c date and time created 81/11/04 10:44:41 by wnj
e
u
U
t
T
I 1
D 18
/*	%M%	%I%	%E%	*/
E 18
I 18
/*
D 20
 * Copyright (c) 1982 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 18

#include "dn.h"
#if NDN > 0
/*
 * DN-11 ACU interface
 */
I 15
#include "../machine/pte.h"
E 15

D 17
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/map.h"
D 15
#include "../h/pte.h"
E 15
D 7
#include "../h/ubavar.h"
E 7
#include "../h/conf.h"
D 14
#include "../h/ioctl.h"
E 14
I 10
#include "../h/uio.h"
E 17
I 17
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "map.h"
#include "conf.h"
#include "uio.h"
E 17
E 10
I 7

D 17
#include "../vaxuba/ubavar.h"
E 17
I 17
#include "ubavar.h"
E 17
E 7

struct dndevice {
D 4
	int	dn_reg[4];
E 4
I 4
	u_short	dn_reg[4];
E 4
};

struct uba_device *dninfo[NDN];
D 13
int dnprobe(), dnattach();
E 13
I 13
int dnprobe(), dnattach(), dnintr();
E 13
D 19
u_short dnstd[] = { 0175200 };
E 19
I 19
u_short dnstd[] = { 0175200, 0 };
E 19
struct uba_driver dndriver =
	{ dnprobe, 0, dnattach, 0, dnstd, "dn", dninfo };

D 4
#define	PWI	0100000		/* power indicate */
#define	ACR	040000		/* abandon call and retry */
#define	DLO	010000		/* data line occupied */
#define	DONE	0200		/* operation complete */
#define	IENABLE	0100		/* interrupt enable */
#define	DSS	040		/* data set status */
#define	PND	020		/* present next digit */
#define MAINT	010		/* maintenance mode */
#define	MENABLE	04		/* master enable */
#define	DPR	02		/* digit present */
#define	CRQ	01		/* call request */
E 4
I 4
#define	CRQ	0x001		/* call request */
#define	DPR	0x002		/* digit present */
#define	MENABLE	0x004		/* master enable */
#define MAINT	0x008		/* maintenance mode */
#define	PND	0x010		/* present next digit */
#define	DSS	0x020		/* data set status */
#define	IENABLE	0x040		/* interrupt enable */
#define	DONE	0x080		/* operation complete */
#define	DLO	0x1000		/* data line occupied */
#define	ACR	0x4000		/* abandon call and retry */
#define	PWI	0x8000		/* power indicate */
E 4

#define	DNPRI	(PZERO+5)
#define DNUNIT(dev)	(minor(dev)>>2)
#define DNREG(dev)	((dev)&03)

#define OBUFSIZ	40		/* largest phone # dialer can handle */

/*
 * There's no good way to determine the correct number of dialers attached
D 2
 *  to a single device (especially when dialers such as Vadic-821 MACS
 *  exist which can address four chassis, each with its own dialer), so
 *  we take the "flags" value supplied by config as the number of devices
 *  attached (see dnintr).
E 2
I 2
 * to a single device (especially when dialers such as Vadic-821 MACS
D 4
 * exist which can address four chassis, each with its own dialer), so
 * we take the "flags" value supplied by config as the number of devices
 * attached (see dnintr).
E 4
I 4
 * exist which can address four chassis, each with its own dialer).
E 4
E 2
 */
dnprobe(reg)
	caddr_t reg;
{
D 2
	register int br, cvec;	/* value-result, must be r11, r10 */
E 2
I 2
D 4
	register int br, cvec;		/* value-result */
E 4
I 4
	register int br, cvec;	/* value-result, must be r11, r10 */
E 4
E 2
	register struct dndevice *dnaddr = (struct dndevice *)reg;

I 10
#ifdef lint
	br = 0; cvec = 0; br = cvec; cvec = br;
I 13
	dnintr(0);
E 13
#endif
E 10
I 2
D 4
#ifdef lint
	br = 0; cvec = br; br = cvec;
	dnintr(0);
#endif

E 4
E 2
	/*
	 * If there's at least one dialer out there it better be
D 2
	 *  at chassis 0.
E 2
I 2
D 4
	 * at chassis 0.
E 4
I 4
D 10
	 *  at chassis 0.
E 10
I 10
	 * at chassis 0.
E 10
E 4
E 2
	 */
	dnaddr->dn_reg[0] = MENABLE|IENABLE|DONE;
	DELAY(5);
	dnaddr->dn_reg[0] = 0;
I 5
	return (sizeof (struct dndevice));
E 5
}

I 10
/*ARGSUSED*/
E 10
dnattach(ui)
	struct uba_device *ui;
D 4
{
E 4
I 4
D 9
{}
E 9
I 9
{
E 9
E 4
I 2

I 9
}

E 9
E 2
D 4
	if (ui->ui_flags == 0)	/* no flags =>'s don't care */
		ui->ui_flags = 4;
	else if (ui->ui_flags > 4 || ui->ui_flags < 0) {
		printf("dn%d: bad flags value %d (disabled)\n", ui->ui_unit,
			ui->ui_flags);
		ui->ui_flags = 0;
		ui->ui_alive = 0;
	}
}

E 4
/*ARGSUSED*/
dnopen(dev, flag)
	dev_t dev;
I 11
	int flag;
E 11
{
	register struct dndevice *dp;
D 4
	register int unit, *dnreg;
E 4
I 4
	register u_short unit, *dnreg;
E 4
	register struct uba_device *ui;
	register short dialer;

	if ((unit = DNUNIT(dev)) >= NDN || (ui = dninfo[unit]) == 0 ||
D 4
	    ui->ui_alive == 0 || (dialer = DNREG(dev)) >= ui->ui_flags ||
	    ((dp = (struct dndevice *)ui->ui_addr)->dn_reg[dialer]&PWI)) {
E 4
I 4
D 9
	    ui->ui_alive == 0) {
E 4
		u.u_error = ENXIO;
		return;
	}
E 9
I 9
	    ui->ui_alive == 0)
		return (ENXIO);
E 9
I 4
	dialer = DNREG(dev);
	dp = (struct dndevice *)ui->ui_addr;
D 9
	if (dp->dn_reg[dialer] & PWI) {
		u.u_error = ENXIO;
		return;
	}
E 9
I 9
	if (dp->dn_reg[dialer] & PWI)
		return (ENXIO);
E 9
E 4
	dnreg = &(dp->dn_reg[dialer]);
D 9
	if (*dnreg&(DLO|CRQ)) {
		u.u_error = EBUSY;
		return;
	}
E 9
I 9
	if (*dnreg&(DLO|CRQ))
		return (EBUSY);
E 9
	dp->dn_reg[0] |= MENABLE;
	*dnreg = IENABLE|MENABLE|CRQ;
I 9
	return (0);
E 9
}

/*ARGSUSED*/
dnclose(dev, flag)
	dev_t dev;
{
	register struct dndevice *dp;

	dp = (struct dndevice *)dninfo[DNUNIT(dev)]->ui_addr;
	dp->dn_reg[DNREG(dev)] = MENABLE;
}

D 6
dnwrite(dev)
E 6
I 6
dnwrite(dev, uio)
E 6
	dev_t dev;
I 6
	struct uio *uio;
E 6
{
D 4
	register int *dnreg, cc;
E 4
I 4
	register u_short *dnreg;
	register int cc;
E 4
	register struct dndevice *dp;
D 3
	char buf[OBUFSIZ];
E 3
I 3
D 4
	char digits[OBUFSIZ];
E 4
I 4
D 10
	char buf[OBUFSIZ];
E 10
I 10
	char obuf[OBUFSIZ];
E 10
E 4
E 3
	register char *cp;
	extern lbolt;
I 8
	int error;
E 8

	dp = (struct dndevice *)dninfo[DNUNIT(dev)]->ui_addr;
	dnreg = &(dp->dn_reg[DNREG(dev)]);
D 6
	cc = MIN(u.u_count, OBUFSIZ);
E 6
I 6
	cc = MIN(uio->uio_resid, OBUFSIZ);
E 6
D 3
	cp = buf;
E 3
I 3
D 4
	cp = digits;
E 4
I 4
D 10
	cp = buf;
E 10
I 10
	cp = obuf;
E 10
E 4
E 3
D 6
	iomove(cp, (unsigned)cc, B_WRITE);
E 6
I 6
D 8
	u.u_error = uiomove(cp, (unsigned)cc, UIO_WRITE, uio);
E 6
	if (u.u_error)
		return;
E 8
I 8
D 11
	error = uiomove(cp, (unsigned)cc, UIO_WRITE, uio);
E 11
I 11
	error = uiomove(cp, cc, UIO_WRITE, uio);
E 11
	if (error)
		return (error);
E 8
	while ((*dnreg & (PWI|ACR|DSS)) == 0 && cc >= 0) {
D 3
		spl4();
E 3
I 3
D 4
		(void) spl4();
E 3
		if ((*dnreg&PND) == 0 || cc == 0)
E 4
I 4
D 12
		spl4();
E 12
I 12
		(void) spl4();
E 12
		if ((*dnreg & PND) == 0 || cc == 0)
E 4
			sleep((caddr_t)dnreg, DNPRI);
		else switch(*cp) {
		
		case '-':
			sleep((caddr_t)&lbolt, DNPRI);
			sleep((caddr_t)&lbolt, DNPRI);
			break;

		case 'f':
			*dnreg &= ~CRQ;
			sleep((caddr_t)&lbolt, DNPRI);
			*dnreg |= CRQ;
			break;

		case '*': case ':':
			*cp = 012;
			goto dial;

		case '#': case ';':
			*cp = 013;
			goto dial;

		case 'e': case '<':
			*cp = 014;
			goto dial;

		case 'w': case '=':
			*cp = 015;
			goto dial;

		default:
			if (*cp < '0' || *cp > '9')
				break;
		dial:
D 4
			*dnreg = (*cp<<8)|IENABLE|MENABLE|DPR|CRQ;
E 4
I 4
			*dnreg = (*cp << 8) | (IENABLE|MENABLE|DPR|CRQ);
E 4
			sleep((caddr_t)dnreg, DNPRI);
		}
		cp++, cc--;
		spl0();
	}
D 4
	if (*dnreg&(PWI|ACR))
E 4
I 4
	if (*dnreg & (PWI|ACR))
E 4
D 8
		u.u_error = EIO;
E 8
I 8
		return (EIO);
	return (0);
E 8
}

D 4
/*
 * NOTE that the flags from the config file define the number
D 2
 *  of dialers attached to this controller.
E 2
I 2
 * of dialers attached to this controller.
E 2
 */
E 4
dnintr(dev)
	dev_t dev;
{
D 4
	register int *basereg, *dnreg, *lastreg;
E 4
I 4
	register u_short *basereg, *dnreg;
E 4

D 4
	basereg = (int *)dninfo[dev]->ui_addr;
E 4
I 4
	basereg = (u_short *)dninfo[dev]->ui_addr;
E 4
	*basereg &= ~MENABLE;
D 4
	lastreg = basereg+dninfo[dev]->ui_flags;
	for (dnreg = basereg; dnreg < lastreg; dnreg++)
		if (*dnreg&DONE) {
E 4
I 4
	for (dnreg = basereg; dnreg < basereg + 4; dnreg++)
		if (*dnreg & DONE) {
E 4
			*dnreg &= ~(DONE|DPR);
			wakeup((caddr_t)dnreg);
		}
	*basereg |= MENABLE;
}
#endif
E 1
