h01933
s 00005/00002/00109
d D 7.6 88/07/09 14:39:58 karels 24 23
c check adaptor numbers against actual number
e
s 00001/00003/00110
d D 7.5 88/02/24 11:04:24 bostic 23 22
c let dev routines print out the error message
e
s 00014/00015/00099
d D 7.4 88/02/22 12:57:31 bostic 22 20
c change to dev(a,b,c,d) format
e
s 00013/00014/00100
d R 7.4 88/02/22 12:57:00 bostic 21 20
c change to dev(a,b,c,d) format
e
s 00012/00010/00102
d D 7.3 88/01/28 20:53:09 karels 20 19
c uvax changes; fix devsw index in confxx; header updates
e
s 00004/00002/00108
d D 7.2 87/02/21 11:41:38 karels 19 18
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00109
d D 7.1 86/06/05 01:43:52 mckusick 18 17
c 4.3BSD release version
e
s 00007/00001/00103
d D 6.2 85/06/08 13:10:11 mckusick 17 16
c Add copyright
e
s 00000/00000/00104
d D 6.1 83/07/29 07:47:22 sam 16 15
c 4.2 distribution
e
s 00013/00000/00091
d D 4.10 83/07/01 05:06:42 sam 15 14
c from ghg: must wait for mba and drive
e
s 00006/00009/00085
d D 4.9 83/02/18 05:24:33 sam 14 13
c cleanup
e
s 00003/00000/00091
d D 4.8 83/01/27 11:38:57 helge 13 11
c added skip sector inhibit
e
s 00003/00000/00091
d R 4.8 83/01/27 11:36:05 helge 12 11
c new ioctl's
e
s 00041/00003/00050
d D 4.7 83/01/16 14:41:40 helge 11 10
c added new ioctl stuff
e
s 00002/00001/00051
d D 4.6 82/12/17 17:01:03 sam 10 9
c pte.h is now in ../machine/
e
s 00004/00002/00048
d D 4.5 82/11/13 23:15:06 sam 9 8
c move includes for 4.1c directory layout
e
s 00001/00000/00049
d D 4.4 82/07/15 21:31:30 root 8 7
c new boot scheme
e
s 00022/00042/00027
d D 4.3 81/03/15 20:46:26 wnj 7 6
c 
e
s 00007/00000/00062
d D 4.2 80/12/17 12:28:51 wnj 6 5
c conditionals for 750/780
e
s 00000/00000/00062
d D 4.1 80/11/09 16:29:27 bill 5 4
c stamp for 4bsd
e
s 00003/00004/00059
d D 1.4 80/07/29 15:09:17 bill 4 3
c work w/o mba's
e
s 00014/00000/00049
d D 1.3 80/07/28 10:06:30 bill 3 2
c mbaact, etc
e
s 00001/00001/00048
d D 1.2 80/07/21 10:39:06 bill 2 1
c fixed up handling of major
e
s 00049/00000/00000
d D 1.1 80/06/28 10:42:58 bill 1 0
c date and time created 80/06/28 10:42:58 by bill
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%G%	*/
E 7
I 7
D 17
/*	%M%	%I%	%E%	*/
E 17
I 17
/*
D 18
 * Copyright (c) 1982 Regents of the University of California.
E 18
I 18
D 24
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 24
I 24
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 24
E 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 20
 *	%W% (Berkeley) %G%
E 20
I 20
D 22
 *	@(#)mba.c	7.2 (Berkeley) 2/21/87
E 22
I 22
 *	%W% (Berkeley) %G%
E 22
E 20
 */
E 17
E 7

I 10
#include "../machine/pte.h"

E 10
I 6
D 7
#if VAX==780
E 7
E 6
D 20
#include "../h/param.h"
#include "../h/inode.h"
D 10
#include "../h/pte.h"
E 10
D 7
#include "../h/mba.h"
E 7
I 7
D 9
#include "../h/mbareg.h"
E 9
I 8
#include "../h/fs.h"
E 8
E 7
D 9
#include "../h/mtpr.h"
E 9
#include "../h/vm.h"
E 20
I 20
#include "param.h"
#include "inode.h"
#include "fs.h"
#include "vm.h"
E 20
I 9

#include "../vax/mtpr.h"
#include "../vaxmba/mbareg.h"
I 11
#include "../vaxmba/hpreg.h"
E 11

E 9
#include "saio.h"
I 7
#include "savax.h"
E 7

D 7
/*
 * startup routine for MBA controllers.
 */
#define	MBAWCOM	0x30
#define	MBARCOM	0x38
#define	GO	01

I 3
struct mba_info mbainfo[] = {
	PHYSMBA0,
	PHYSMBA1,
};

E 3
mbastart(io, adcr, func)
register struct iob *io;
int *adcr;
E 7
I 7
D 22
mbastart(io, func)
E 22
I 22
mbastart(io, unit, func)
E 22
	register struct iob *io;
D 22
	int func;
E 22
I 22
	int unit, func;
E 22
E 7
{
D 7
	register int i;
E 7
I 7
D 22
	struct mba_regs *mba = mbamba(io->i_unit);
	struct mba_drv *drv = mbadrv(io->i_unit);
E 22
I 22
	struct mba_regs *mba = mbamba(io->i_adapt);
	struct mba_drv *drv = mbadrv(io->i_adapt, unit);
E 22
	register struct pte *pte = mba->mba_map;
E 7
D 22
	int npf;
	unsigned v;
D 7
	register struct pte *pte;
E 7
	int o;
	int vaddr;
E 22
I 22
	unsigned int v;
	int npf, o, vaddr;
E 22
D 7
	extern int mbanum[], *mbaloc[];
	register struct mba_regs *mbap;
E 7

D 2
	mbap = (struct mba_regs *)mbaloc[mbanum[io->i_unit]];
E 2
I 2
D 7
	mbap = (struct mba_regs *)mbaloc[mbanum[io->i_ino.i_dev]];
E 2
D 4
	pte = (struct pte *)mbap;
	pte += (MBA_MAP + 128*4)/4;
E 4
I 4
	pte = &mbap->mba_map[128];
E 7
E 4
	v = btop(io->i_ma);
	o = (int)io->i_ma & PGOFSET;
	npf = btoc(io->i_cc + o);
D 7
	vaddr = (128 << 9) | o;
	v &= 0x1fffff;		/* drop to physical addr */
E 7
I 7
	vaddr = o;
E 7
	while (--npf >= 0)
		*(int *)pte++ = v++ | PG_V;
D 7
	mbap->mba_sr = -1;	/* clear status (error) bits */
	mbap->mba_bcr = -io->i_cc;
	mbap->mba_var = vaddr;
	if (func == READ)
		*adcr = MBARCOM | GO;
	else if (func == WRITE) {
		*adcr = MBAWCOM | GO;
	}
E 7
I 7
	mba->mba_sr = -1;
	mba->mba_bcr = -io->i_cc;
	mba->mba_var = vaddr;
I 13
D 14
	if (io->i_flgs&F_SSI) {
E 14
I 14
	if (io->i_flgs&F_SSI)
E 14
		drv->mbd_of |= HPOF_SSEI;
D 14
	}
E 14
E 13
D 11
	if (func == WRITE)
		drv->mbd_cs1 = MB_WCOM | MB_GO;
E 11
I 11
	switch (io->i_flgs & F_TYPEMASK) {

	case F_RDDATA:			/* standard read */
		drv->mbd_cs1 = MB_RCOM|MB_GO;
I 15
D 22
		mbawait(io);
E 22
I 22
		mbawait(io, unit);
E 22
E 15
		return(0);

	case F_WRDATA:			/* standard write */
		drv->mbd_cs1 = MB_WCOM|MB_GO;
I 15
D 22
		mbawait(io);
E 22
I 22
		mbawait(io, unit);
E 22
E 15
		return(0);

	/* the following commands apply to disks only */

	case F_HDR|F_RDDATA:	
		drv->mbd_cs1 = HP_RHDR|HP_GO;
		break;

	case F_HDR|F_WRDATA:
		drv->mbd_cs1 = HP_WHDR|HP_GO;
		break;

	case F_CHECK|F_WRDATA:
	case F_CHECK|F_RDDATA:
		drv->mbd_cs1 = HP_WCDATA|HP_GO;
		break;

	case F_HCHECK|F_WRDATA:
	case F_HCHECK|F_RDDATA:
		drv->mbd_cs1 = HP_WCHDR|HP_GO;
		break;

	default:
D 14
error:
		io->i_error = ECMD;
		io->i_flgs &= ~F_TYPEMASK;
		return (1);
E 14
I 14
		goto error;
E 14
	}
I 15
D 22
	mbawait(io);
E 22
I 22
	mbawait(io, unit);
E 22
E 15
D 14

E 14
	if ((drv->mbd_dt & MBDT_TAP) == 0)
		return (0);
E 11
D 14
	else
D 11
		drv->mbd_cs1 = MB_RCOM | MB_GO;
E 11
I 11
		goto error;		/* if not a disk : error */
E 14
I 14
error:
	io->i_error = ECMD;
	io->i_flgs &= ~F_TYPEMASK;
	return (1);
I 15
}

D 22
mbawait(io)
E 22
I 22
mbawait(io, unit)
E 22
	register struct iob *io;
I 22
	int unit;
E 22
{
D 22
	struct mba_regs *mba = mbamba(io->i_unit);
	struct mba_drv *drv = mbadrv(io->i_unit);
E 22
I 22
	struct mba_regs *mba = mbamba(io->i_adapt);
	struct mba_drv *drv = mbadrv(io->i_adapt, unit);
E 22

	while (mba->mba_sr & MBSR_DTBUSY)
		DELAY(100);
E 15
E 14
E 11
E 7
I 3
}

mbainit(mbanum)
	int mbanum;
{
D 4
	register struct mba_regs *mbap = mbainfo[mbanum];
E 4
I 4
D 7
	register struct mba_regs *mbap = mbainfo[mbanum].mi_phys;
E 7
I 7
D 24
	register struct mba_regs *mba = mbaddr[mbanum];
E 24
I 24
	register struct mba_regs *mba;
E 24
E 7
E 4

I 24
	if (mbanum >= nmba)
		return (0);
	mba = mbaddr[mbanum];
E 24
D 4
	mbap->mba_cr = MBA_INIT;
E 4
I 4
D 7
	mbap->mba_cr = MBAINIT;
E 7
I 7
D 19
	/* SHOULD BADADDR IT */
E 19
I 19
D 20
	if (badaddr((char *)mba, sizeof(long)))
E 20
I 20
D 23
	if (badaddr((char *)mba, sizeof(long))) {
		printf("nonexistent mba");
E 23
I 23
	if (badaddr((char *)mba, sizeof(long)))
E 23
E 20
		return (0);
E 19
D 20
	if (mbaact & (1<<mbanum))
D 19
		return;
E 19
I 19
		return (1);
E 19
	mba->mba_cr = MBCR_INIT;
E 7
E 4
	mbaact |= 1<<mbanum;
E 20
I 20
D 23
	}
E 23
	if ((mbaact & (1<<mbanum)) == 0) {
		mba->mba_cr = MBCR_INIT;
		mbaact |= 1<<mbanum;
	}
E 20
I 19
	return (1);
E 19
E 3
}
I 6
D 7
#else
mbadummy()
{
	;
}
#endif
E 7
E 6
E 1
