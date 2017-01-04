h12110
s 00020/00022/00121
d D 7.3 88/02/22 12:57:52 bostic 10 9
c change to dev(a,b,c,d) format
e
s 00009/00006/00134
d D 7.2 88/01/28 20:53:11 karels 9 8
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00139
d D 7.1 86/06/05 01:44:04 mckusick 8 7
c 4.3BSD release version
e
s 00007/00001/00133
d D 6.2 85/06/08 13:10:22 mckusick 7 6
c Add copyright
e
s 00000/00000/00134
d D 6.1 83/07/29 07:47:24 sam 6 5
c 4.2 distribution
e
s 00028/00012/00106
d D 4.5 83/02/08 23:26:52 sam 5 4
c fixes from purdue
e
s 00001/00001/00117
d D 4.4 82/12/17 17:01:07 sam 4 3
c pte.h is now in ../machine/
e
s 00005/00003/00113
d D 4.3 82/11/13 23:15:09 sam 3 2
c move includes for 4.1c directory layout
e
s 00001/00000/00115
d D 4.2 82/07/15 21:31:37 root 2 1
c new boot scheme
e
s 00115/00000/00000
d D 4.1 81/12/01 09:35:13 sam 1 0
c date and time created 81/12/01 09:35:13 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

/*
 * TM78/TU78 tape driver
I 5
 * Made to work reliably by by Jeffrey R. Schwab (Purdue)
E 5
 */
I 4
#include "../machine/pte.h"
E 4

D 3
#include "../h/mtreg.h"
E 3
D 9
#include "../h/param.h"
D 3
#include "../h/inode.h"
E 3
D 4
#include "../h/pte.h"
E 4
D 3
#include "../h/mbareg.h"
E 3
I 3
#include "../h/inode.h"
E 3
I 2
#include "../h/fs.h"
E 9
I 9
#include "param.h"
#include "inode.h"
#include "fs.h"
E 9
I 3

#include "../vaxmba/mtreg.h"
#include "../vaxmba/mbareg.h"

E 3
E 2
#include "saio.h"
#include "savax.h"

short	mttypes[] =
	{ MBDT_TU78, 0 };

#define	MASKREG(reg)	((reg)&0xffff)

mtopen(io)
	register struct iob *io;
{
D 10
	register int skip;
D 5
	register struct mtdevice *mtaddr = (struct mtdevice *)mbadrv(io->i_unit);
E 5
I 5
	register struct mtdevice *mtaddr =
		(struct mtdevice *)mbadrv(io->i_unit);
E 5
D 9
	int i;
E 9
I 9
	register int i;
E 10
I 10
	register struct mtdevice *mtaddr;
	register int i, skip;
E 10
E 9

I 9
D 10
	if (mbainit(UNITTOMBA(io->i_unit)) == 0)
		return (ENXIO);
E 9
	for (i = 0; mttypes[i]; i++)
E 10
I 10
	if (mbainit(io->i_adapt) == 0)
		return (EADAPT);
	mtaddr = (struct mtdevice *)mbadrv(io->i_adapt, io->i_ctlr);
	for (i = 0;; i++) {
		if (!mttypes[i]) {
			printf("mt: not a tape\n");
			return (ENXIO);
		}
E 10
		if (mttypes[i] == (mtaddr->mtdt&MBDT_TYPE))
D 10
			goto found;
D 9
	_stop("not a tape\n");
E 9
I 9
	printf("not a tape\n");
	return (ENXIO);
E 9
found:
E 10
I 10
			break;
	}
E 10
D 9
	mbainit(UNITTOMBA(io->i_unit));
E 9
	mtaddr->mtid = MTID_CLR;
	DELAY(250);
D 10
	while ((mtaddr->mtid & MTID_RDY) == 0)
		;
E 10
I 10
	while ((mtaddr->mtid & MTID_RDY) == 0);
E 10
I 5

	/* clear any attention bits present on open */
	i = mtaddr->mtner;
	mtaddr->mtas = mtaddr->mtas;

E 5
	mtstrategy(io, MT_REW);
D 10
	skip = io->i_boff;
	while (skip--) {
E 10
I 10
	for (skip = io->i_part; skip--;) {
E 10
		io->i_cc = -1;
		mtstrategy(io, MT_SFORWF);
	}
I 9
	return (0);
E 9
}

mtclose(io)
	register struct iob *io;
{
D 10

E 10
	mtstrategy(io, MT_REW);
}

mtstrategy(io, func)
	register struct iob *io;
	int func;
{
	register int errcnt, s, ic;
D 10
	register struct mtdevice *mtaddr =
	    (struct mtdevice *)mbadrv(io->i_unit);
I 5
	struct mba_regs *mba = mbamba(io->i_unit);
E 10
I 10
	register struct mtdevice *mtaddr;
	struct mba_regs *mba;
E 10
E 5

	errcnt = 0;
I 10
	mtaddr = (struct mtdevice *)mbadrv(io->i_adapt, io->i_ctlr);
	mba = mbamba(io->i_adapt);
E 10
retry:
I 5
	/* code to trap for attention up prior to start of command */
	if ((mtaddr->mtas & 0xffff) != 0) {
		printf("mt unexpected attention er=%x - continuing\n",
			MASKREG(mtaddr->mtner));
		mtaddr->mtas = mtaddr->mtas;
	}

E 5
	if (func == READ || func == WRITE) {
		mtaddr->mtca = 1<<2;	/* 1 record */
		mtaddr->mtbc = io->i_cc;
D 5
		mtaddr->mter = 0;
E 5
D 10
		mbastart(io, func);
E 10
I 10
		mbastart(io, io->i_ctlr, func);
E 10
D 5
		do
			s = mtaddr->mter & MTER_INTCODE;
		while (s == 0);
		ic = s;
		DELAY(2000);
E 5
I 5
		/* wait for mba to go idle and read result status */
		while((mba->mba_sr & MBSR_DTBUSY) != 0)
			;
		ic = mtaddr->mter & MTER_INTCODE;
E 5
	} else {
D 5
		mtaddr->mtas = -1;
E 5
		mtaddr->mtncs[0] = (-io->i_cc << 8)|func|MT_GO;
	rwait:
		do
			s = mtaddr->mtas&0xffff;
		while (s == 0);
D 5
		mtaddr->mtas = mtaddr->mtas;	/* clear attention */
E 5
		ic = mtaddr->mtner & MTER_INTCODE;
I 5
		mtaddr->mtas = mtaddr->mtas;	/* clear attention */
E 5
	}
	switch (ic) {
	case MTER_TM:
	case MTER_EOT:
	case MTER_LEOT:
		return (0);

	case MTER_DONE:
I 5
		/* make sure a record was read */
		if ((mtaddr->mtca & (1 << 2)) != 0) {
			printf("mt record count not decremented - retrying\n");
			goto retry;
		}
E 5
		break;

	case MTER_RWDING:
		goto rwait;
	default:
D 5
		printf("mt hard error: er=%b\n",
E 5
I 5
		printf("mt hard error: er=%x\n",
E 5
		    MASKREG(mtaddr->mter));
		mtaddr->mtid = MTID_CLR;
		DELAY(250);
		while ((mtaddr->mtid & MTID_RDY) == 0)
			;
		return (-1);

	case MTER_RETRY:
D 5
		printf("mt error: er=%b\n",
		    MASKREG(mtaddr->mter));
E 5
I 5
		printf("mt error: er=%x\n", MASKREG(mtaddr->mter));
E 5
D 10
		if (errcnt == 10) {
E 10
I 10
		if (errcnt++ == 10) {
E 10
			printf("mt: unrecovered error\n");
			return (-1);
		}
D 10
		errcnt++;
E 10
		goto retry;
	}
	if (errcnt)
		printf("mt: recovered by retry\n");
	return (io->i_cc);	/* NO PARTIAL RECORD READS!!! */
}
E 1
