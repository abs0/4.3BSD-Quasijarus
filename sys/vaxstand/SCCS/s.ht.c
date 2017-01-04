h36014
s 00020/00022/00105
d D 7.3 88/02/22 12:55:37 bostic 20 19
c change to dev(a,b,c,d) format
e
s 00009/00006/00118
d D 7.2 88/01/28 20:53:02 karels 19 18
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00123
d D 7.1 86/06/05 01:42:52 mckusick 18 17
c 4.3BSD release version
e
s 00007/00001/00117
d D 6.2 85/06/08 13:09:05 mckusick 17 16
c Add copyright
e
s 00000/00000/00118
d D 6.1 83/07/29 07:47:10 sam 16 13
c 4.2 distribution
e
s 00001/00001/00117
d R 4.11 83/02/18 05:26:20 sam 15 13
c frame count query wrong
e
s 00001/00001/00117
d R 4.11 83/02/18 01:00:29 sam 14 13
c residual calculated wrong
e
s 00002/00003/00116
d D 4.10 83/02/10 17:45:26 sam 13 12
c cleanup
e
s 00001/00001/00118
d D 4.9 82/12/17 17:00:29 sam 12 11
c pte.h is now in ../machine/
e
s 00004/00002/00115
d D 4.8 82/11/13 23:14:40 sam 11 10
c move includes for 4.1c directory layout
e
s 00001/00000/00116
d D 4.7 82/03/07 19:13:20 mckusic 10 9
c change header names
e
s 00015/00009/00101
d D 4.6 81/12/01 10:41:54 root 9 8
c bug fix from shannon
e
s 00016/00005/00094
d D 4.5 81/03/22 20:52:03 wnj 8 7
c fixes
e
s 00001/00001/00098
d D 4.4 81/03/16 00:54:26 wnj 7 6
c fixes for generic functionality
e
s 00050/00117/00049
d D 4.3 81/03/15 20:46:14 wnj 6 5
c 
e
s 00007/00000/00159
d D 4.2 80/12/17 12:10:59 wnj 5 4
c fix for 750 (add rk, dont compile hp, ht)
e
s 00000/00000/00159
d D 4.1 80/11/09 16:29:19 bill 4 3
c stamp for 4bsd
e
s 00020/00016/00139
d D 1.3 80/07/29 15:09:04 bill 3 2
c work w/o mba's
e
s 00003/00000/00152
d D 1.2 80/07/28 10:03:33 bill 2 1
c mbaact, etc
e
s 00152/00000/00000
d D 1.1 80/06/28 10:42:51 bill 1 0
c date and time created 80/06/28 10:42:51 by bill
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%G%	*/
E 6
I 6
D 17
/*	%M%	%I%	%E%	*/
E 17
I 17
/*
D 18
 * Copyright (c) 1982 Regents of the University of California.
E 18
I 18
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 17
E 6

/*
D 6
 * TJU16 tape driver
E 6
I 6
 * TM03/TU?? tape driver
E 6
 */
I 12
#include "../machine/pte.h"
E 12

I 5
D 6
#if VAX==780
E 6
I 6
D 11
#include "../h/htreg.h"
E 11
E 6
E 5
D 19
#include "../h/param.h"
#include "../h/inode.h"
I 3
D 12
#include "../h/pte.h"
E 12
E 3
D 6
#include "../h/mba.h"
E 6
I 6
D 11
#include "../h/mbareg.h"
E 11
I 10
#include "../h/fs.h"
E 19
I 19
#include "param.h"
#include "inode.h"
#include "fs.h"
E 19
I 11

#include "../vaxmba/htreg.h"
#include "../vaxmba/mbareg.h"

E 11
E 10
E 6
#include "saio.h"
I 6
#include "savax.h"
E 6

I 8
short	httypes[] =
	{ MBDT_TM03, MBDT_TE16, MBDT_TU45, MBDT_TU77, 0 };

#define	MASKREG(reg)	((reg)&0xffff)

E 8
D 6
struct	device
{
	int	htcs1;
	int	htds;
	int	hter;
	int	htmr;
	int	htas;
	int	htfc;
	int	htdt;
	int	htck;
	int	htsn;
	int	httc;
};

D 3
#define	HTADDR	((struct device *)(PHYSMBA1 + MBA_ERB))
I 2
#define	HTMBA	1
E 3
I 3
#define	HTMBA		PHYSMBA1
#define	HTMBANUM	1
E 3
E 2

#define	GO	01
#define	WCOM	060
#define	RCOM	070
#define	NOP	0
#define	WEOF	026
#define	SFORW	030
#define	SREV	032
#define	ERASE	024
#define	REW	06
#define	DCLR	010
#define P800	01700		/* 800 + pdp11 mode */
#define	P1600	02300		/* 1600 + pdp11 mode */
#define	IENABLE	0100
#define	RDY	0200
#define	TM	04
#define	DRY	0200
#define EOT	02000
#define CS	02000
#define COR	0100000
#define PES	040
#define WRL	04000
#define MOL	010000
#define ERR	040000
#define FCE	01000
#define	TRE	040000
#define HARD	064023	/* UNS|OPI|NEF|FMT|RMR|ILR|ILF */

#define	SIO	1
#define	SSFOR	2
#define	SSREV	3
#define SRETRY	4
#define SCOM	5
#define SOK	6

E 6
htopen(io)
D 6
register struct iob *io;
E 6
I 6
	register struct iob *io;
E 6
{
D 6
	register skip;
E 6
I 6
D 20
	register int skip;
D 13
	register struct htdevice *htaddr = (struct htdevice *)mbadrv(io->i_unit);
E 13
I 13
	register struct htdevice *htaddr =
	   (struct htdevice *)mbadrv(io->i_unit);
E 13
E 6
D 19
	int i;
E 19
I 19
	register int i;
E 20
I 20
	register struct htdevice *htaddr;
	register int i, skip;
E 20
E 19

I 19
D 20
	if (mbainit(UNITTOMBA(io->i_unit)) == 0)
		return (ENXIO);
E 19
I 8
	for (i = 0; httypes[i]; i++)
E 20
I 20
	htaddr = (struct htdevice *)mbadrv(io->i_adapt, io->i_ctlr);
	if (mbainit(io->i_adapt) == 0)
		return (EADAPT);
	for (i = 0;; i++) {
		if (!httypes[i]) {
			printf("ht: not a tape\n");
			return (ENXIO);
		}
E 20
		if (httypes[i] == (htaddr->htdt&MBDT_TYPE))
D 20
			goto found;
D 19
	_stop("not a tape\n");
E 19
I 19
	printf("not a tape\n");
	return (ENXIO);
E 19
found:
E 20
I 20
			break;
	}
E 20
E 8
I 2
D 3
	if ((mbaact&(1<<HTMBA)) == 0)
		mbainit(HTMBA);
E 3
I 3
D 6
	if ((mbaact&(1<<HTMBANUM)) == 0)
		mbainit(HTMBANUM);
E 3
E 2
	htinit();
	htstrategy(io, REW);
E 6
I 6
D 19
	mbainit(UNITTOMBA(io->i_unit));
E 19
	htaddr->htcs1 = HT_DCLR|HT_GO;
	htstrategy(io, HT_REW);
E 6
D 20
	skip = io->i_boff;
	while (skip--) {
E 20
I 20
	for (skip = io->i_part; skip--;) {
E 20
		io->i_cc = -1;
D 6
		while (htstrategy(io, SFORW))
E 6
I 6
D 20
		while (htstrategy(io, HT_SFORW))
E 6
			;
E 20
I 20
		while (htstrategy(io, HT_SFORW));
E 20
D 6
		i = 65536;
		while (--i)
			;
		htstrategy(io, NOP);
E 6
I 6
		DELAY(65536);
		htstrategy(io, HT_SENSE);
E 6
	}
I 19
	return (0);
E 19
}

htclose(io)
D 6
register struct iob *io;
E 6
I 6
	register struct iob *io;
E 6
{
D 6
	htstrategy(io, REW);
E 6
I 6
D 20

E 20
	htstrategy(io, HT_REW);
E 6
}

htstrategy(io, func)
D 6
register struct iob *io;
E 6
I 6
	register struct iob *io;
	int func;
E 6
{
I 20
	register struct htdevice *htaddr;
E 20
D 6
	register int unit, den, errcnt, ds;
E 6
I 6
	register int den, errcnt, ds;
I 9
	int er;
E 9
E 6
	short fc;
I 3
D 6
	register struct device *htp = mbadev(HTMBA,0);
E 6
I 6
D 20
	register struct htdevice *htaddr =
	    (struct htdevice *)mbadrv(io->i_unit);
E 20
E 6
E 3

D 6
	unit = io->i_unit;
E 6
	errcnt = 0;
I 20
	htaddr = (struct htdevice *)mbadrv(io->i_adapt, io->i_ctlr);
E 20
retry:
D 6
	if(unit & 1)
		den = P1600;
	else
		den = P800;
	htquiet();
D 3
	if((HTADDR->httc&03777) != den)
		HTADDR->httc = den;
	HTADDR->htfc = -io->i_cc;
E 3
I 3
	if((htp->httc&03777) != den)
		htp->httc = den;
	htp->htfc = -io->i_cc;
E 3
	if (func == SREV) {
D 3
		HTADDR->htfc = -1;
		HTADDR->htcs1 = SREV | GO;
E 3
I 3
		htp->htfc = -1;
		htp->htcs1 = SREV | GO;
E 3
		return(0);
E 6
I 6
D 20
	den = HTTC_1600BPI|HTTC_PDP11;
E 20
I 20
	den = HTTC_1600BPI | HTTC_PDP11 | io->i_unit;
E 20
	htquiet(htaddr);
I 8
	htaddr->htcs1 = HT_DCLR|HT_GO;
E 8
	htaddr->httc = den;
	htaddr->htfc = -io->i_cc;
	if (func == HT_SREV) {
		htaddr->htfc = -1;
		htaddr->htcs1 = HT_SREV|HT_GO;
		return (0);
E 6
	}
D 6
	if (func == READ || func == WRITE)
D 3
		mbastart(io, HTADDR, func);
E 3
I 3
		mbastart(io, htp, func);
E 6
I 6
D 7
	if (func == HT_RCOM || func == HT_WCOM)
E 7
I 7
	if (func == READ || func == WRITE)
E 7
D 20
		mbastart(io, func);
E 20
I 20
		mbastart(io, io->i_ctlr, func);
E 20
E 6
E 3
	else
D 3
		HTADDR->htcs1 = func | GO;
E 3
I 3
D 6
		htp->htcs1 = func | GO;
E 3
	htquiet();
D 3
	ds = HTADDR->htds & TM;
E 3
I 3
	ds = htp->htds & TM;
E 3
	if (ds&TM) {
		htinit();
		return(0);
E 6
I 6
		htaddr->htcs1 = func|HT_GO;
	htquiet(htaddr);
	ds = htaddr->htds;
I 9
	er = htaddr->hter;
E 9
	if (ds & HTDS_TM) {
		htaddr->htcs1 = HT_DCLR|HT_GO;
		return (0);
E 6
	}
D 6
	if (ds&ERR) {
E 6
I 6
	if (ds & HTDS_ERR) {
E 6
D 8
		if (errcnt == 0)
D 6
			printf("tape error: ds=%x, er=%x, mbasr=%x",
D 3
			    HTADDR->htds, HTADDR->hter, PHYSMBA1->mba_sr);
E 3
I 3
			    htp->htds, htp->hter,
			    HTMBA->mba_sr);
E 3
		htinit();
E 6
I 6
			printf("tape error: ds=%x, er=%x",
			    htaddr->htds, htaddr->hter);
E 8
I 8
D 9
		printf("ht error: ds=%b, er=%b\n",
		    MASKREG(htaddr->htds), HTDS_BITS,
		    MASKREG(htaddr->hter), HTER_BITS);
E 9
E 8
		htaddr->htcs1 = HT_DCLR|HT_GO;
E 6
D 9
		if (errcnt == 10) {
D 8
			printf("\n");
E 8
I 8
			printf("ht: unrecovered error\n");
E 8
D 6
			return(-1);
E 6
I 6
			return (-1);
E 9
I 9
		if ((er & HTER_CORCRC) == 0) {
			printf("ht error: ds=%b, er=%b\n",
			    MASKREG(ds), HTDS_BITS,
			    MASKREG(er), HTER_BITS);
D 20
			if (errcnt == 10) {
E 20
I 20
			if (errcnt++ == 10) {
E 20
				printf("ht: unrecovered error\n");
				return (-1);
			}
D 20
			errcnt++;
E 20
			htstrategy(io, HT_SREV);
			goto retry;
E 9
E 6
		}
D 9
		errcnt++;
D 6
		htstrategy(io, SREV);
E 6
I 6
		htstrategy(io, HT_SREV);
E 6
		goto retry;
E 9
	}
	if (errcnt)
D 8
		printf(" recovered by retry\n");
E 8
I 8
		printf("ht: recovered by retry\n");
E 8
D 3
	fc = HTADDR->htfc;
E 3
I 3
D 6
	fc = htp->htfc;
E 3
	return(io->i_cc+fc);
E 6
I 6
	fc = htaddr->htfc;
	return (io->i_cc+fc);
E 6
}

I 20
static
E 20
D 6
htinit()
E 6
I 6
htquiet(htaddr)
	register struct htdevice *htaddr;
E 6
{
D 6

D 3
	HTADDR->htcs1 = DCLR|GO;
E 3
I 3
	mbadev(HTMBA,0)->htcs1 = DCLR|GO;
E 3
}

htquiet()
{
E 6
	register int s;
I 3
D 6
	register struct device *htp = mbadev(HTMBA,0);
E 6
E 3

	do
D 3
		s = HTADDR->htds;
E 3
I 3
D 6
		s = htp->htds;
E 3
	while ((s & RDY) == 0);
E 6
I 6
		s = htaddr->htds;
	while ((s & HTDS_DRY) == 0);
E 6
}
I 9
D 13


E 13
E 9
I 5
D 6
#else
htdummy()
{
	;
}
#endif
E 6
E 5
E 1
