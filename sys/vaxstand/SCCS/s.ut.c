h64607
s 00005/00002/00131
d D 7.5 88/07/09 14:40:09 karels 14 13
c check adaptor numbers against actual number
e
s 00001/00003/00132
d D 7.4 88/02/24 11:01:37 bostic 13 12
c default to dev error, doesn't tell you anything new
e
s 00026/00022/00109
d D 7.3 88/02/22 13:00:49 bostic 12 11
c change to dev(a,b,c,d) format
e
s 00008/00003/00123
d D 7.2 88/01/28 20:53:37 karels 11 10
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00125
d D 7.1 86/06/05 01:47:54 mckusick 10 9
c 4.3BSD release version
e
s 00007/00001/00119
d D 6.2 85/06/08 13:14:13 mckusick 9 8
c Add copyright
e
s 00000/00000/00120
d D 6.1 83/07/29 07:48:13 sam 8 7
c 4.2 distribution
e
s 00003/00005/00117
d D 4.7 83/03/06 16:03:07 sam 7 6
c use FORWSF instead
e
s 00015/00007/00107
d D 4.6 83/02/20 19:20:43 sam 6 5
c handle frame count register like normal ut driver
e
s 00001/00001/00113
d D 4.5 82/12/17 17:02:01 sam 5 4
c pte.h is now in ../machine/
e
s 00004/00002/00110
d D 4.4 82/11/13 23:15:47 sam 4 3
c move includes for 4.1c directory layout
e
s 00002/00001/00110
d D 4.3 82/07/15 21:32:48 root 3 2
c new boot scheme
e
s 00002/00001/00109
d D 4.2 81/12/15 11:57:35 sam 2 1
c incorrect residual calculation
e
s 00110/00000/00000
d D 4.1 81/12/01 09:35:16 sam 1 0
c date and time created 81/12/01 09:35:16 by sam
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 10
 * Copyright (c) 1982 Regents of the University of California.
E 10
I 10
D 14
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 14
E 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9

/*
 * SI Model 9700 -- emulates TU45 on the UNIBUS
 */
I 5
D 14
#include "../machine/pte.h"
E 14
E 5

D 11
#include "../h/param.h"
#include "../h/inode.h"
D 5
#include "../h/pte.h"
E 5
D 4
#include "../h/ubareg.h"
E 4
I 3
#include "../h/fs.h"
E 11
I 11
#include "param.h"
#include "inode.h"
#include "fs.h"
E 11
I 4

I 14
#include "../vax/pte.h"

E 14
#include "../vaxuba/ubareg.h"
#include "../vaxuba/utreg.h"

E 4
E 3
#include "saio.h"
#include "savax.h"

I 6
#define	MASKREG(reg)	((reg)&0xffff)
E 6
D 4
#include "../h/utreg.h"
E 4

D 12
u_short	utstd[] = { 0172440 };		/* non-standard */
E 12
I 12
#define	MAXCTLR		1		/* all addresses must be specified */
u_short	utstd[MAXCTLR] = { 0172440 };	/* non-standard */
E 12

utopen(io)
	register struct iob *io;
{
D 7
	register skip;
E 7
I 7
D 12
	int skip;
E 12
I 12
	register int skip;
E 12
E 7

I 14
	if ((u_int)io->i_adapt >= nuba)
		return (EADAPT);
E 14
I 11
D 12
	if (badaddr((char *)ubamem(io->i_unit, utstd[0]), sizeof(short))) {
		printf("nonexistent device\n");
E 12
I 12
	if ((u_int)io->i_ctlr >= MAXCTLR)
		return (ECTLR);
D 13
	if (badaddr((char *)ubamem(io->i_unit, utstd[io->i_ctlr]), sizeof(short))) {
		printf("ut: nonexistent device\n");
E 13
I 13
	if (badaddr((char *)ubamem(io->i_unit, utstd[io->i_ctlr]), sizeof(short)))
E 13
E 12
		return (ENXIO);
D 13
	}
E 13
E 11
	utstrategy(io, UT_REW);
D 12
	skip = io->i_boff;
D 7
	while (skip--) {
		io->i_cc = 0;
		utstrategy(io, UT_SFORW);
	}
E 7
I 7
	while (skip-- > 0)
E 12
I 12
	for (skip = io->i_part; skip--;)
E 12
		utstrategy(io, UT_SFORWF);
I 11
	return (0);
E 11
E 7
}

utclose(io)
	register struct iob *io;
{
I 6
D 12

E 12
E 6
	utstrategy(io, UT_REW);
}

D 12
#define utwait(addr)	{do word=addr->utcs1; while((word&UT_RDY)==0);}
E 12
I 12
#define	UTWAIT(addr) { \
	do \
		word = addr->utcs1; \
	while((word&UT_RDY) == 0); \
}
E 12

utstrategy(io, func)
	register struct iob *io;
{
I 12
	register struct utdevice *addr;
E 12
	register u_short word;
	register int errcnt;
D 12
	register struct utdevice *addr =
	    (struct utdevice *)ubamem(io->i_unit, utstd[0]);
E 12
D 6
	int info;
E 6
I 6
	int info, resid;
E 6
	u_short dens;

D 12
	dens = (io->i_unit&07) | PDP11FMT | UT_PE;
E 12
I 12
	addr = (struct utdevice *)ubamem(io->i_unit, utstd[io->i_ctlr]);
	dens = io->i_unit | PDP11FMT | UT_PE;
E 12
	errcnt = 0;
retry:
	utquiet(addr);
	addr->uttc = dens;
	info = ubasetup(io, 1);
	addr->utwc = -((io->i_cc+1) >> 1);
	addr->utfc = -io->i_cc;
	if (func == READ) {
		addr->utba = info;
		addr->utcs1 = UT_RCOM | ((info>>8) & 0x30) | UT_GO;
	} else if (func == WRITE) {
		addr->utba = info;
		addr->utcs1 = UT_WCOM | ((info>>8) & 0x30) | UT_GO;
	} else if (func == UT_SREV) {
		addr->utcs1 = UT_SREV | UT_GO;
		return (0);
	} else
		addr->utcs1 = func | UT_GO;
D 12
	utwait(addr);
E 12
I 12
	UTWAIT(addr);
E 12
	ubafree(io, info);
	word = addr->utds;
	if (word&(UTDS_EOT|UTDS_TM)) {
		addr->utcs1 = UT_CLEAR | UT_GO;
D 6
		return(0);
E 6
I 6
		goto done;
E 6
	}
	if ((word&UTDS_ERR) || (addr->utcs1&UT_TRE)) {
D 12
		if (errcnt == 0)
			printf("tj error: cs1=%b er=%b cs2=%b ds=%b",
D 6
				addr->utcs1, UT_BITS, addr->uter, UTER_BITS,
				addr->utcs2, UTCS2_BITS, word, UTDS_BITS);
E 6
I 6
			  addr->utcs1, UT_BITS, addr->uter, UTER_BITS,
			  addr->utcs2, UTCS2_BITS, word, UTDS_BITS);
E 6
		if (errcnt == 10) {
			printf("\n");
E 12
I 12
		printf("ut error: cs1=%b er=%b cs2=%b ds=%b",
		  addr->utcs1, UT_BITS, addr->uter, UTER_BITS,
		  addr->utcs2, UTCS2_BITS, word, UTDS_BITS);
		if (errcnt++ == 10) {
			printf("ut: unrecovered error\n");
E 12
D 6
			return(-1);
E 6
I 6
			return (-1);
E 6
		}
D 12
		errcnt++;
E 12
		if (addr->utcs1&UT_TRE)
			addr->utcs2 |= UTCS2_CLR;
		addr->utcs1 = UT_CLEAR | UT_GO;
		utstrategy(io, UT_SREV);
		utquiet(addr);
		if (func == WRITE) {
			addr->utcs1 = UT_ERASE | UT_GO;
D 12
			utwait(addr);
E 12
I 12
			UTWAIT(addr);
E 12
		}
		goto retry;
	}
	if (errcnt)
D 12
		printf(" recovered by retry\n");
E 12
I 12
		printf("ut: recovered by retry\n");
E 12
D 2
	return ((-addr->utfc) & 0xffff);
E 2
I 2
D 6
	return (func == READ ?
D 3
		io->io_cc - ((-addr->utfc) & 0xffff) : -addr->utwc << 1);
E 3
I 3
		io->i_cc - ((-addr->utfc) & 0xffff) : -addr->utwc << 1);
E 6
I 6
done:
	if (func == READ) {
		resid = 0;
		if (io->i_cc > MASKREG(addr->utfc))
			resid = io->i_cc - MASKREG(addr->utfc);
	} else
		resid = MASKREG(-addr->utfc);
	return (io->i_cc - resid);
E 6
E 3
E 2
}

I 12
static
E 12
utquiet(addr)
	register struct utdevice *addr;
{
	register u_short word;

D 12
	utwait(addr);
E 12
I 12
	UTWAIT(addr);
E 12
	do
		word = addr->utds;
	while ((word&UTDS_DRY) == 0 && (word&UTDS_PIP));
}
E 1
