h01317
s 00011/00006/00248
d D 7.3 88/06/29 17:30:01 bostic 14 13
c install approved copyright notice
e
s 00004/00007/00250
d D 7.2 88/05/26 09:03:41 karels 13 12
c include mp.h!, convert cy to rawread/write
e
s 00013/00001/00244
d D 7.1 88/05/21 18:35:01 karels 12 11
c bring up to revision 7 for tahoe release
e
s 00042/00044/00203
d D 1.11 88/05/14 12:15:33 karels 11 10
c raw read/write mods from torek (checked in for bostic)
e
s 00023/00028/00224
d D 1.10 87/11/17 21:04:40 sam 10 9
c install mpcc driver in place of bisync
e
s 00001/00001/00251
d D 1.9 87/03/28 15:58:27 karels 9 8
c add vdclose for cdev
e
s 00010/00008/00242
d D 1.8 87/03/26 18:04:33 karels 8 7
c add bdev ioctl
e
s 00003/00002/00247
d D 1.7 87/02/19 17:04:46 karels 7 6
c add vdioctl
e
s 00044/00007/00205
d D 1.6 86/11/25 16:41:58 sam 6 5
c add dr, ik, and enpr devices
e
s 00009/00035/00203
d D 1.5 86/07/16 08:26:21 sam 5 4
c purege nonexistent drivers; change disk names
e
s 00001/00001/00237
d D 1.4 86/01/26 14:18:08 sam 4 3
c cy.h -> yc.h
e
s 00000/00031/00238
d D 1.3 86/01/26 14:15:29 sam 3 2
c purge ps and efs entries for now
e
s 00014/00013/00255
d D 1.2 86/01/05 18:42:19 sam 2 1
c 1st working version
e
s 00268/00000/00000
d D 1.1 85/07/26 13:37:37 sam 1 0
c date and time created 85/07/26 13:37:37 by sam
e
u
U
t
T
I 1
D 2
/*	conf.c	1.3	85/04/25	*/
/*	conf.c	6.1	83/07/29	*/
E 2
I 2
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
 *
 *	%W% (Berkeley) %G%
 */
E 12
E 2

D 2
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/ioctl.h"
#include "../h/tty.h"
#include "../h/conf.h"
E 2
I 2
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "ioctl.h"
#include "tty.h"
#include "conf.h"
E 2

D 11
int	nulldev();
int	nodev();
E 11
I 11
int nulldev(), nodev(), rawread(), rawwrite(), swstrategy();
E 11

D 5
/*   #include "ud.h" */
#if NUD > 0
int	udopen(),udstrategy(),udread(),udwrite(),uddump(),udioctl(),udsize();
#else
#define	udopen		nodev
#define	udstrategy	nodev
#define	udread		nodev
#define	udwrite		nodev
#define	uddump		nodev
#define	udioctl		nodev
#define	udsize		0
#endif

#include "fsd.h"
E 5
I 5
#include "dk.h"
E 5
#if NVD > 0
D 7
int	vdopen(),vdstrategy(),vdread(),vdwrite(),vddump(),vdsize();
E 7
I 7
D 8
int	vdopen(),vdstrategy(),vdread(),vdwrite(),vdioctl(),vddump(),vdsize();
E 8
I 8
D 13
int	vdopen(),vdclose(),vdstrategy(),vdread(),vdwrite(),vdioctl();
E 13
I 13
int	vdopen(),vdclose(),vdstrategy(),vdioctl();
E 13
int	vddump(),vdsize();
E 8
E 7
#else
#define	vdopen		nodev
I 8
#define	vdclose		nodev
E 8
#define	vdstrategy	nodev
D 13
#define	vdread		nodev
#define	vdwrite		nodev
E 13
I 7
#define	vdioctl		nodev
E 7
#define	vddump		nodev
#define	vdsize		0
#endif

D 5
#define	NXP	0
#if NXP > 0
int	xpopen(),xpstrategy(),xpread(),xpwrite(),xpdump(),xpioctl(),xpsize();
#else
#define	xpopen		nodev
#define	xpstrategy	nodev
#define	xpread		nodev
#define	xpwrite		nodev
#define	xpdump		nodev
#define	xpioctl		nodev
#define	xpsize		0
#endif

E 5
D 4
#include "cy.h"
E 4
I 4
#include "yc.h"
E 4
#if NCY > 0
D 11
int	cyopen(),cyclose(),cystrategy(),cyread(),cywrite(),cydump(),cyioctl(),cyreset();
E 11
I 11
D 13
int	cyopen(),cyclose(),cystrategy(),cyread(),cywrite(),cydump();
E 13
I 13
int	cyopen(),cyclose(),cystrategy(),cydump();
E 13
int	cyioctl(),cyreset();
E 11
#else
#define	cyopen		nodev
#define	cyclose		nodev
#define	cystrategy	nodev
D 13
#define	cyread		nodev
#define	cywrite		nodev
E 13
#define	cydump		nodev
#define	cyioctl		nodev
#define	cyreset		nulldev
#endif

D 11
int	swstrategy(),swread(),swwrite();

E 11
struct bdevsw	bdevsw[] =
{
D 5
	{ udopen,	nulldev,	udstrategy,	uddump,		/*0*/
	  udsize,	0 },
E 5
I 5
	{ nodev,	nulldev,	nodev,		nodev,		/*0*/
D 8
	  0,		0 },
E 5
	{ vdopen,	nulldev,	vdstrategy,	vddump,		/*1*/
	  vdsize,	0 },
E 8
I 8
	  nodev,	0,		0 },
	{ vdopen,	vdclose,	vdstrategy,	vdioctl,	/*1*/
	  vddump,	vdsize,		0 },
E 8
D 5
	{ xpopen,	nulldev,	xpstrategy,	xpdump,		/*2*/
	  xpsize,	0 },
E 5
I 5
	{ nodev,	nulldev,	nodev,		nodev,		/*2*/
D 8
	  0,		0 },
E 5
	{ cyopen,	cyclose,	cystrategy,	cydump,		/*3*/
	  0,		B_TAPE },
E 8
I 8
	  nodev,	0,		0 },
	{ cyopen,	cyclose,	cystrategy,	cyioctl,	/*3*/
	  cydump,	0,		B_TAPE },
E 8
	{ nodev,	nodev,		swstrategy,	nodev,		/*4*/
D 8
	  0,		0 },
E 8
I 8
	  nodev,	0,		0 },
E 8
};
int	nblkdev = sizeof (bdevsw) / sizeof (bdevsw[0]);

int	cnopen(),cnclose(),cnread(),cnwrite(),cnioctl();
D 2
struct tty cons[];
E 2
I 2
extern	struct tty cons;
E 2

#include "vx.h"
#if NVX == 0
#define	vxopen	nodev
#define	vxclose	nodev
#define	vxread	nodev
#define	vxwrite	nodev
#define	vxioctl	nodev
#define	vxstop	nodev
#define	vxreset	nulldev
#define	vx_tty	0
#else
int	vxopen(),vxclose(),vxread(),vxwrite(),vxioctl(),vxstop(),vxreset();
struct	tty vx_tty[];
#endif

int	syopen(),syread(),sywrite(),syioctl(),syselect();

int 	mmread(),mmwrite();
#define	mmselect	seltrue

#include "pty.h"
#if NPTY > 0
int	ptsopen(),ptsclose(),ptsread(),ptswrite(),ptsstop();
int	ptcopen(),ptcclose(),ptcread(),ptcwrite(),ptcselect();
int	ptyioctl();
struct	tty pt_tty[];
#else
#define ptsopen		nodev
#define ptsclose	nodev
#define ptsread		nodev
#define ptswrite	nodev
#define ptcopen		nodev
#define ptcclose	nodev
#define ptcread		nodev
#define ptcwrite	nodev
#define ptyioctl	nodev
#define	pt_tty		0
#define	ptcselect	nodev
#define	ptsstop		nulldev
#endif

I 13
#include "mp.h"
E 13
D 10
#include "vbsc.h"
#if NVBSC > 0
int	bscopen(), bscclose(), bscread(), bscwrite(), bscioctl();
int	bsmopen(),bsmclose(),bsmread(),bsmwrite(),bsmioctl();
int	bstopen(),bstclose(),bstread(),bstioctl();
E 10
I 10
#if NMP > 0
int	mpopen(), mpclose(), mpread(), mpwrite(), mpioctl(), mpstop();
int	mpdlopen(), mpdlclose(), mpdlwrite(), mpdlioctl();
extern	struct tty mp_tty[];
E 10
#else
D 10
#define bscopen		nodev
#define bscclose	nodev
#define bscread		nodev
#define bscwrite	nodev
#define bscioctl	nodev
#define bsmopen		nodev
#define bsmclose	nodev
#define bsmread		nodev
#define bsmwrite	nodev
#define bsmioctl	nodev
#define bstopen		nodev
#define bstclose	nodev
#define bstread		nodev
#define bstwrite	nodev
#define bstioctl	nodev
E 10
I 10
#define	mpopen		nodev
#define	mpclose		nodev
#define	mpread		nodev
#define	mpwrite		nodev
#define	mpioctl		nodev
#define	mpstop		nodev
#define	mpdlopen	nodev
#define	mpdlclose	nodev
#define	mpdlwrite	nodev
#define	mpdlioctl	nodev
#define	mp_tty		0
E 10
#endif

#if NII > 0
int	iiioctl(), iiclose(), iiopen();
#else
#define	iiopen	nodev
#define	iiclose	nodev
#define	iiioctl	nodev
#endif

I 6
#include "enp.h"
#if NENP > 0
int	enpr_open(), enpr_close(), enpr_read(), enpr_write(), enpr_ioctl();
#else
#define enpr_open	nodev
#define enpr_close	nodev
#define enpr_read	nodev
#define enpr_write	nodev
#define enpr_ioctl	nodev
#endif

#include "dr.h"
#if NDR > 0
int     dropen(),drclose(),drread(),drwrite(),drioctl(),drreset();
#else
#define dropen nodev
#define drclose nodev
#define drread nodev
#define drwrite nodev
#define drioctl nodev
#define drreset nodev
#endif

#include "ik.h"
#if NIK > 0
int     ikopen(),ikclose(),ikread(),ikwrite(),ikioctl();
#else
#define ikopen nodev
#define ikclose nodev
#define ikread nodev
#define ikwrite nodev
#define ikioctl nodev
#endif

E 6
D 3
#include "ps.h"
#if NPS > 0
int	psopen(),psclose(),psread(),pswrite(),psioctl(),psreset();
#else
#define psopen nodev
#define psclose nodev
#define psread nodev
#define pswrite nodev
#define psopen nodev
#define psioctl nodev
#define psreset nodev
#endif

#include "efs.h"
#if NEFS > 0
int	efsopen(),efsfgen(),efsread(),efswrite(),efsioctl(),efsreset();
#else
#define efsopen nodev
#define efsfgen nodev
#define efsread nodev
#define efswrite nodev
#define efsioctl nodev
#define efsreset nodev
#endif

E 3
I 2
int	logopen(),logclose(),logread(),logioctl(),logselect();

E 2
int	ttselect(), seltrue();

struct cdevsw	cdevsw[] =
{
	cnopen,		cnclose,	cnread,		cnwrite,	/*0*/
D 2
	cnioctl,	nulldev,	nulldev,	cons,
E 2
I 2
	cnioctl,	nulldev,	nulldev,	&cons,
E 2
D 11
	ttselect,	nodev,
E 11
I 11
	ttselect,	nodev,		NULL,
E 11
	vxopen,		vxclose,	vxread,		vxwrite,	/*1*/
	vxioctl,	vxstop,		vxreset,	vx_tty,
D 11
	ttselect,	nodev,
E 11
I 11
	ttselect,	nodev,		NULL,
E 11
	syopen,		nulldev,	syread,		sywrite,	/*2*/
D 11
	syioctl,	nulldev,	nulldev,	0,
	syselect,	nodev,
E 11
I 11
	syioctl,	nulldev,	nulldev,	NULL,
	syselect,	nodev,		NULL,
E 11
	nulldev,	nulldev,	mmread,		mmwrite,	/*3*/
D 11
	nodev,		nulldev,	nulldev,	0,
	mmselect,	nodev,
E 11
I 11
	nodev,		nulldev,	nulldev,	NULL,
	mmselect,	nodev,		NULL,
E 11
D 5
	udopen,		nulldev,	udread,		udwrite,	/*4*/
	udioctl,	nodev,		nulldev,	0,
E 5
I 5
	nodev,		nulldev,	nodev,		nodev,		/*4*/
D 11
	nodev,		nodev,		nulldev,	0,
E 5
	seltrue,	nodev,
D 9
	vdopen,		nulldev,	vdread,		vdwrite,	/*5*/
E 9
I 9
	vdopen,		vdclose,	vdread,		vdwrite,	/*5*/
E 9
D 7
	nodev,		nodev,		nulldev,	0,
E 7
I 7
	vdioctl,	nodev,		nulldev,	0,
E 7
	seltrue,	nodev,
E 11
I 11
	nodev,		nodev,		nulldev,	NULL,
	seltrue,	nodev,		NULL,
	vdopen,		vdclose,	rawread,	rawwrite,	/*5*/
	vdioctl,	nodev,		nulldev,	NULL,
	seltrue,	nodev,		vdstrategy,
E 11
D 5
	xpopen,		nulldev,	xpread,		xpwrite,	/*6*/
	xpioctl,	nodev,		nulldev,	0,
E 5
I 5
	nodev,		nulldev,	nodev,		nodev,		/*6*/
D 11
	nodev,		nodev,		nulldev,	0,
E 5
	seltrue,	nodev,
E 11
I 11
	nodev,		nodev,		nulldev,	NULL,
	seltrue,	nodev,		NULL,
E 11
D 13
	cyopen,		cyclose,	cyread,		cywrite,	/*7*/
E 13
I 13
	cyopen,		cyclose,	rawread,	rawwrite,	/*7*/
E 13
D 11
	cyioctl,	nodev,		cyreset,	0,
	seltrue,	nodev,
	nulldev,	nulldev,	swread,		swwrite,	/*8*/
	nodev,		nodev,		nulldev,	0,
	nodev,		nodev,
E 11
I 11
	cyioctl,	nodev,		cyreset,	NULL,
D 14
	seltrue,	nodev,		NULL,
E 14
I 14
	seltrue,	nodev,		cystrategy,
E 14
	nulldev,	nulldev,	rawread,	rawwrite,	/*8*/
	nodev,		nodev,		nulldev,	NULL,
	nodev,		nodev,		swstrategy,
E 11
	ptsopen,	ptsclose,	ptsread,	ptswrite,	/*9*/
	ptyioctl,	ptsstop,	nodev,		pt_tty,
D 11
	ttselect,	nodev,
E 11
I 11
	ttselect,	nodev,		NULL,
E 11
	ptcopen,	ptcclose,	ptcread,	ptcwrite,	/*10*/
	ptyioctl,	nulldev,	nodev,		pt_tty,
D 11
	ptcselect,	nodev,
E 11
I 11
	ptcselect,	nodev,		NULL,
E 11
D 10
	bscopen,	bscclose,	bscread,	bscwrite,	/*11*/
	bscioctl,	nodev,		nulldev,	0,
	nodev,		nodev,
	bsmopen,	bsmclose,	bsmread,	bsmwrite,	/*12*/
	bsmioctl,	nodev,		nulldev,	0,
	nodev,		nodev,
	bstopen,	bstclose,	bstread,	nodev,		/*13*/
	bstioctl,	nodev,		nulldev,	0,
E 10
I 10
	mpdlopen,	mpdlclose,	nodev,		mpdlwrite,	/*11*/
D 11
	mpdlioctl,	nodev,		nulldev,	0,
	seltrue,	nodev,
E 11
I 11
	mpdlioctl,	nodev,		nulldev,	NULL,
	seltrue,	nodev,		NULL,
E 11
	mpopen,		mpclose,	mpread,		mpwrite,	/*12*/
	mpioctl,	mpstop,		nulldev,	mp_tty,
D 11
	ttselect,	nodev,
E 11
I 11
	ttselect,	nodev,		NULL,
E 11
	nodev,		nodev,		nodev,		nodev,		/*13*/
D 11
	nodev,		nodev,		nulldev,	0,
E 10
	nodev,		nodev,
E 11
I 11
	nodev,		nodev,		nulldev,	NULL,
	nodev,		nodev,		NULL,
E 11
	iiopen,		iiclose,	nulldev,	nulldev,	/*14*/
D 11
	iiioctl,	nulldev,	nulldev,	0,
	seltrue,	nodev,
E 11
I 11
	iiioctl,	nulldev,	nulldev,	NULL,
	seltrue,	nodev,		NULL,
E 11
D 2
	nodev,		nodev,		nulldev,	nulldev,	/*15*/
	nodev,		nodev,		nulldev,	0,
	nodev,		nodev,
E 2
I 2
	logopen,	logclose,	logread,	nodev,		/*15*/
D 11
	logioctl,	nodev,		nulldev,	0,
	logselect,	nodev,
E 11
I 11
	logioctl,	nodev,		nulldev,	NULL,
	logselect,	nodev,		NULL,
E 11
E 2
D 6
	nodev,		nodev,		nulldev,	nulldev,	/*16*/
E 6
I 6
	enpr_open,	enpr_close,	enpr_read,	enpr_write,	/*16*/
D 11
	enpr_ioctl,	nodev,		nulldev,	0,
	nodev,		nodev,		
E 11
I 11
	enpr_ioctl,	nodev,		nulldev,	NULL,
	nodev,		nodev,		NULL,
E 11
	nodev,		nodev,		nodev,		nodev,		/*17*/
E 6
D 11
	nodev,		nodev,		nulldev,	0,
	nodev,		nodev,
E 11
I 11
	nodev,		nodev,		nulldev,	NULL,
	nodev,		nodev,		NULL,
E 11
D 6
	nodev,		nodev,		nulldev,	nulldev,	/*17*/
	nodev,		nodev,		nulldev,	0,
E 6
I 6
	dropen,		drclose,	drread,		drwrite,	/*18*/
D 11
	drioctl,	nodev,		drreset,	0,
E 6
	nodev,		nodev,
E 11
I 11
	drioctl,	nodev,		drreset,	NULL,
	nodev,		nodev,		NULL,
E 11
D 6
	nodev,		nodev,		nulldev,	nulldev,	/*18*/
E 6
I 6
	nodev,		nodev,		nodev,		nodev,		/*19*/
E 6
D 11
	nodev,		nodev,		nulldev,	0,
	nodev,		nodev,
E 11
I 11
	nodev,		nodev,		nulldev,	NULL,
	nodev,		nodev,		NULL,
E 11
D 6
	nodev,		nodev,		nulldev,	nulldev,	/*19*/
	nodev,		nodev,		nulldev,	0,
	nodev,		nodev,
E 6
/* 20-30 are reserved for local use */
I 6
	ikopen,		ikclose,	ikread,		ikwrite,	/*20*/
D 11
	ikioctl,	nodev,		nulldev,	0,
	nodev,		nodev,
E 11
I 11
	ikioctl,	nodev,		nulldev,	NULL,
	nodev,		nodev,		NULL,
E 11
E 6
D 3
	psopen,		psclose,	psread,		pswrite,	/*20*/
	psioctl,	nodev,		psreset,	0,
	seltrue,	nodev,
	efsopen,	efsfgen,	efsread,	efswrite,	/*21*/
	efsioctl,	nodev,		efsreset,	0,
	seltrue,	nodev,
E 3
};
int	nchrdev = sizeof (cdevsw) / sizeof (cdevsw[0]);

int	mem_no = 3; 	/* major device number of memory special file */

/*
 * Swapdev is a fake device implemented
 * in sw.c used only internally to get to swstrategy.
 * It cannot be provided to the users, because the
 * swstrategy routine munches the b_dev and b_blkno entries
 * before calling the appropriate driver.  This would horribly
 * confuse, e.g. the hashing routines. Instead, /dev/drum is
 * provided as a character (raw) device.
 */
dev_t	swapdev = makedev(4, 0);
E 1
