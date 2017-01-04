h02660
s 00001/00001/00251
d D 7.2 88/10/22 15:13:59 karels 2 1
c use ubaalloc macros; use qbgetpri for Q-bus device probe routines
e
s 00252/00000/00000
d D 7.1 88/04/25 15:42:49 bostic 1 0
c SCCS file corrupted, and not recoverable from any dump tapes.
c SCCS/S.ik.c.corrupted contains the original SCCS file.
c attached is the SCCS change listing.
c
c D 7.1	86/06/05 01:10:50	mckusick	16	15	00001/00001/00251
c 4.3BSD release version
c 
c D 6.3	85/06/08 14:17:17	mckusick	15	14	00007/00001/00245
c Add copyright
c 
c D 6.2	84/08/29 20:08:28	bloom	14	13	00011/00011/00235
c Change to includes.  No more ../h
c 
c D 6.1	83/07/29 07:27:54	sam	13	12	00000/00000/00246
c 4.2 distribution
c 
c D 4.11	82/12/17 12:02:38	sam	12	11	00002/00001/00244
c sun merge
c 
c D 4.10	82/10/22 01:14:02	root	11	10	00001/00000/00244
c lint
c 
c D 4.9	82/10/21 21:20:14	root	10	9	00033/00024/00211
c lint
c 
c D 4.8	82/10/17 11:49:20	root	9	8	00018/00022/00217
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
c 
c D 4.7	82/10/10 17:27:35	root	8	7	00004/00003/00235
c header files for vax are in their place
c 
c D 4.6	82/09/12 03:07:35	root	7	6	00004/00006/00234
c physio returns error, not in u.u_error
c 
c D 4.5	82/08/22 21:18:29	root	6	5	00002/00002/00238
c fully uio()'d
c 
c D 4.4	82/08/13 00:15:52	root	5	4	00007/00005/00233
c changes for char dev uio'ing
c 
c D 4.3	82/08/01 19:25:26	sam	4	3	00008/00005/00230
c new ioctl's
c 
c D 4.2	82/07/15 20:02:08	kre	3	1	00001/00000/00234
c probe routines return size of unibus dev regs to reserve space
c 
c D 4.1	82/06/26 16:08:58	sam	1	0	00234/00000/00000
c date and time created 82/06/26 16:08:58 by sam
e
u
U
t
T
I 1
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

#include "ik.h"
#if NIK > 0
/*
 * Ikonas Frame Buffer Interface -- Bill Reeves.
 */
#include "../machine/pte.h"

#include "param.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "systm.h"
#include "map.h"
#include "uio.h"
#include "ioctl.h"

#include "ubareg.h"
#include "ubavar.h"
#include "ikreg.h"

#define IKBUSY 01
#define IKDMAPRI (PZERO-1)
#define IKWAITPRI (PZERO+1)

int	ikprobe(), ikattach(), ikintr();
struct	uba_device *ikdinfo[NIK];
u_short	ikstd[] = { 0772460, 0000000, 0 };
struct	uba_driver ikdriver =
	{ ikprobe, 0, ikattach, 0, ikstd, "ik", ikdinfo, 0, 0 };

struct ik_softc {
	char	ik_open;
	short	ik_uid;
	short	ik_state;
	int	ik_ubinfo;
	int	ik_count;
	struct	buf *ik_bp;
	int	ik_bufp;
	int	ik_icnt;
} ik_softc[NIK];

int	ikstrategy();
u_int	ikminphys();
struct	buf rikbuf[NIK];

#define IKUNIT(dev) (minor(dev))

ikprobe(reg)
	caddr_t reg;
{
	register int br, cvec;		/* value-result */
	register struct ikdevice *ikaddr = (struct ikdevice *) reg;

#ifdef lint
	br = 0; cvec = br; br = cvec;
	ikintr(0);
#endif
	ikaddr->ik_istat = 0;
	ikaddr->ik_xaddr = 0;
	ikaddr->ik_yaddr = 0;
	ikaddr->ik_ustat = IK_IENABLE | IK_GO;
	DELAY(10000);
	ikaddr->ik_ustat = 0;
	return (sizeof (struct ikdevice));
}

/*ARGSUSED*/
ikattach(ui)
	struct uba_device *ui;
{

}

ikopen(dev)
	dev_t dev;
{
	register struct ik_softc *ikp;
	register struct uba_device *ui;

	if (IKUNIT(dev) >= NIK || (ikp = &ik_softc[minor(dev)])->ik_open ||
	    (ui = ikdinfo[IKUNIT(dev)]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
	ikp->ik_open = 1;
	ikp->ik_icnt = 0;
	ikp->ik_state = 0;
	ikp->ik_uid = u.u_uid;
	maptouser(ui->ui_addr);
	return (0);
}

ikclose(dev)
	dev_t dev;
{

	ik_softc[minor(dev)].ik_open = 0;
	ik_softc[minor(dev)].ik_state = 0;
	unmaptouser(ikdinfo[IKUNIT(dev)]->ui_addr);
}

ikread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register int unit = IKUNIT(dev);

	if (unit >= NIK)
		return (ENXIO);
	return (physio(ikstrategy, &rikbuf[unit], dev, B_READ, ikminphys, uio));
}

ikwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register int unit = IKUNIT(dev);

	if (unit >= NIK)
		return (ENXIO);
	return (physio(ikstrategy, &rikbuf[unit], dev, B_WRITE, ikminphys, uio));
}

u_int
ikminphys(bp)
	register struct buf *bp;
{

	if (bp->b_bcount > 65536)	/* may be able to do twice as much */
		bp->b_bcount = 65536;
}

ikstrategy(bp)
	register struct buf *bp;
{
	register struct ik_softc *ikp = &ik_softc[IKUNIT(bp->b_dev)];
	register struct uba_device *ui;

	if (IKUNIT(bp->b_dev) >= NIK || (ui = ikdinfo[IKUNIT(bp->b_dev)]) == 0
				|| ui->ui_alive == 0)
		goto bad;
	(void) spl5();
	while (ikp->ik_state & IKBUSY)
		sleep((caddr_t)ikp, IKDMAPRI+1);
	ikp->ik_state |= IKBUSY;
	ikp->ik_bp = bp;
	ikp->ik_ubinfo = ubasetup(ui->ui_ubanum, bp, UBA_NEEDBDP);
D 2
	ikp->ik_bufp = ikp->ik_ubinfo & 0x3ffff;
E 2
I 2
	ikp->ik_bufp = UBAI_ADDR(ikp->ik_ubinfo);
E 2
	ikp->ik_count = -(bp->b_bcount>>1);	/* its a word count */
	ikstart(ui);
	while (ikp->ik_state&IKBUSY)
		sleep((caddr_t)ikp, IKDMAPRI);
	ikp->ik_count = 0;
	ikp->ik_bufp = 0;
	(void) spl0();
	ubarelse(ui->ui_ubanum, &ikp->ik_ubinfo);
	ikp->ik_bp = 0;
	iodone(bp);
	wakeup((caddr_t)ikp);
	return;
bad:
	bp->b_flags |= B_ERROR;
	iodone(bp);
	return;
}

ikstart(ui)
	register struct uba_device *ui;
{
	register int istat;
	register struct ikdevice *ikaddr = (struct ikdevice *) ui->ui_addr;
	register struct ik_softc *ikp = &ik_softc[IKUNIT(ui->ui_unit)];

	istat = ikaddr->ik_istat|DMAENABLE;
	ikaddr->ik_istat = istat;
	ikaddr->ik_wc =  ikp->ik_count;
	ikaddr->ik_ubaddr = ikp->ik_bufp;
	ikaddr->ik_ustat = IK_GO|IK_IENABLE|((ikp->ik_bufp>>12)&060);
}

/*ARGSUSED*/
ikioctl(dev, cmd, data, flag)
	dev_t dev;
	int cmd;
	register caddr_t data;
	int flag;
{
	register struct uba_device *ui = ikdinfo[IKUNIT(dev)];
	register struct ik_softc *ikp;

	switch (cmd) {

	case IKIOGETADDR:
		*(caddr_t *)data = ui->ui_addr;
		break;

	case IKIOWAITINT:
		ikp = &ik_softc[IKUNIT(dev)];
		ikp->ik_state |= IKBUSY;
		while (ikp->ik_state&IKBUSY)
			sleep((caddr_t)ikp, IKWAITPRI);
		break;

	default:
		return (ENOTTY);
	}
	return (0);
}

/*ARGSUSED*/
ikintr(dev)
	dev_t dev;
{
	register struct ikdevice *ikaddr =
			(struct ikdevice *) ikdinfo[IKUNIT(dev)]->ui_addr;
	register struct ik_softc *ikp = &ik_softc[IKUNIT(dev)];

	ikp->ik_icnt++;
	if (ikp->ik_state&IKBUSY) {
		ikaddr->ik_ustat = 0;
		ikp->ik_state &= ~IKBUSY;
		wakeup((caddr_t)ikp);
	}
}

ikreset(uban)
	int uban;
{
	register int i;
	register struct uba_device *ui;
	register struct ik_softc *ikp = ik_softc;

	for (i = 0; i < NIK; i++, ikp++) {
		if ((ui = ikdinfo[i]) == 0 || ui->ui_alive == 0 ||
		    ui->ui_ubanum != uban || ikp->ik_open == 0)
			continue;
		printf(" ik%d", i);
		if ((ikp->ik_state&IKBUSY) == 0)
			continue;
		ikp->ik_ubinfo =
		    ubasetup(ui->ui_ubanum, ikp->ik_bp, UBA_NEEDBDP);
		ikp->ik_count = -(ikp->ik_bp->b_bcount/2);
		ikstart(ui);
	}
}
#endif
E 1
