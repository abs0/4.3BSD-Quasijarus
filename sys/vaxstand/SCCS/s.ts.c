h47353
s 00006/00003/00138
d D 7.5 88/07/09 14:40:06 karels 14 13
c check adaptor numbers against actual number
e
s 00022/00021/00119
d D 7.4 88/02/22 12:59:54 bostic 13 12
c change to dev(a,b,c,d) format
e
s 00001/00001/00139
d D 7.3 88/01/28 20:56:51 karels 12 11
c restore keywords
e
s 00011/00006/00129
d D 7.2 88/01/28 20:53:27 karels 11 10
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00134
d D 7.1 86/06/05 01:46:07 mckusick 10 9
c 4.3BSD release version
e
s 00007/00001/00128
d D 6.2 85/06/08 13:13:01 mckusick 9 8
c Add copyright
e
s 00000/00000/00129
d D 6.1 83/07/29 07:47:52 sam 8 7
c 4.2 distribution
e
s 00001/00001/00128
d D 4.7 82/12/17 17:01:26 sam 7 6
c pte.h is now in ../machine/
e
s 00004/00002/00125
d D 4.6 82/11/13 23:15:30 sam 6 5
c move includes for 4.1c directory layout
e
s 00004/00002/00123
d D 4.5 82/07/15 21:32:26 root 5 4
c new boot scheme
e
s 00001/00001/00124
d D 4.4 81/12/01 09:58:38 root 4 3
c fix "device" name
e
s 00005/00004/00120
d D 4.3 81/03/22 20:52:21 wnj 3 2
c fixes
e
s 00032/00022/00092
d D 4.2 81/03/21 17:29:34 wnj 2 1
c working version
e
s 00114/00000/00000
d D 4.1 81/03/15 20:52:00 wnj 1 0
c date and time created 81/03/15 20:52:00 by wnj
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
D 11
 *	%W% (Berkeley) %G%
E 11
I 11
D 12
 *	@(#)ts.c	7.1 (Berkeley) 6/5/86
E 12
I 12
 *	%W% (Berkeley) %G%
E 12
E 11
 */
E 9

/*
 * TS11 tape driver
 */
I 7
D 14
#include "../machine/pte.h"
E 14
E 7

D 11
#include "../h/param.h"
D 6
#include "../h/tsreg.h"
E 6
#include "../h/inode.h"
D 7
#include "../h/pte.h"
E 7
D 6
#include "../h/ubareg.h"
E 6
I 5
#include "../h/fs.h"
E 11
I 11
#include "param.h"
#include "inode.h"
#include "fs.h"
E 11
I 6

I 14
#include "../vax/pte.h"

E 14
#include "../vaxuba/tsreg.h"
#include "../vaxuba/ubareg.h"

E 6
E 5
#include "saio.h"
#include "savax.h"

I 13
#define	MAXCTLR		1		/* all addresses must be specified */
u_short	tsstd[MAXCTLR] = { 0772520 };
E 13

D 13
u_short	tsstd[] = { 0772520 };

E 13
struct	iob	ctsbuf;

u_short	ts_uba;			/* Unibus address of ts structure */

D 4
struct device *tsaddr = 0;
E 4
I 4
D 13
struct tsdevice *tsaddr = 0;
E 4

E 13
struct ts {
	struct ts_cmd ts_cmd;
	struct ts_char ts_char;
	struct ts_sts ts_sts;
} ts;

tsopen(io)
	register struct iob *io;
{
	static struct ts *ts_ubaddr;
I 13
	register struct tsdevice *tsaddr;
E 13
I 2
	long i = 0;
E 2

I 14
	if ((u_int)io->i_adapt >= nuba)
		return (EADAPT);
E 14
D 13
	if (tsaddr == 0)
D 5
		tsaddr = ubamem(io->i_unit, tsstd[0]);
E 5
I 5
		tsaddr = (struct tsdevice *)ubamem(io->i_unit, tsstd[0]);
I 11
	if (badaddr((char *)tsaddr, sizeof (short))) {
		printf("nonexistent device\n");
E 13
I 13
	if ((u_int)io->i_ctlr >= MAXCTLR)
		return (ECTLR);
	/* TS11 only supports one transport per formatter */
D 14
	if ((u_int)io->i_unit)
E 14
I 14
	if (io->i_unit)
E 14
		return(EUNIT);
	tsaddr = (struct tsdevice *)ubamem(io->i_adapt, tsstd[io->i_ctlr]);
	if (badaddr((char *)tsaddr, sizeof (short)))
E 13
		return (ENXIO);
D 13
	}
E 13
E 11
E 5
D 2
	if (ts_ubaddr==0 || tsaddr->tssr&(TS_OFL|TS_NBA) || (tsaddr->tssr&TS_SSR)==0) {
		long i = 0;
		tsaddr->tssr = 0;
		while ((tsaddr->tssr & TS_SSR)==0) {
			if (++i > 1000000) {
				printf("ts: not ready\n");
				return;
			}
E 2
I 2
	tsaddr->tssr = 0;
	while ((tsaddr->tssr & TS_SSR)==0) {
I 5
		DELAY(10);
E 5
		if (++i > 1000000) {
			printf("ts: not ready\n");
D 11
			return;
E 11
I 11
D 13
			return (EUNIT);
E 13
I 13
			return (ENXIO);
E 13
E 11
E 2
		}
	}
	if (tsaddr->tssr&TS_OFL) {
		printf("ts: offline\n");
D 11
		return;
E 11
I 11
D 13
		return (EUNIT);
E 13
I 13
		return (ENXIO);
E 13
E 11
	}
	if (tsaddr->tssr&TS_NBA) {
I 2
		int i;

E 2
		ctsbuf.i_ma = (caddr_t) &ts;
		ctsbuf.i_cc = sizeof(ts);
		if (ts_ubaddr == 0)
D 2
			ts_ubaddr = (struct ts *)ubasetup(&ctsbuf, 0);
		ts_uba = (u_short)((long)ts_ubaddr + (((long)ubaddr >> 16) & 03));
E 2
I 2
			ts_ubaddr = (struct ts *)ubasetup(&ctsbuf, 2);
		ts_uba = (u_short)((long)ts_ubaddr + (((long)ts_ubaddr>>16)&03));
E 2
		ts.ts_char.char_addr = (int)&ts_ubaddr->ts_sts;
		ts.ts_char.char_size = sizeof(ts.ts_sts);
D 2
		ts.ts_char.char_mode = TS_ESS;		/* Stop on 2 tape marks */
		ts.ts_cmd.c_cmd = TS_ACK|TS_SETCHR;	/* write characteristics */
		ts.ts_cmd.c_addr = (int)&ts_ubaddr->ts_char;
E 2
I 2
		ts.ts_char.char_mode = TS_ESS;
		ts.ts_cmd.c_cmd = TS_ACK|TS_SETCHR;
		i = (int)&ts_ubaddr->ts_char;
		ts.ts_cmd.c_loba = i;
		ts.ts_cmd.c_hiba = (i>>16)&3;
E 2
		ts.ts_cmd.c_size = sizeof(ts.ts_char);
		tsaddr->tsdb = ts_uba;
	}
	tsstrategy(io, TS_REW);
D 13
	if (io->i_cc = io->i_boff)
E 13
I 13
	if (io->i_cc = io->i_part)
E 13
		tsstrategy(io, TS_SFORWF);
I 11
	return (0);
E 11
}

tsclose(io)
	register struct iob *io;
{
I 2
D 13

E 13
E 2
	tsstrategy(io, TS_REW);
}

tsstrategy(io, func)
	register struct iob *io;
{
D 2
	register int errcnt, info;
E 2
I 2
D 13
	register int errcnt, info = 0;
E 13
I 13
	register struct tsdevice *tsaddr;
	register int errcnt, info;
E 13
E 2

D 13
	errcnt = 0;
E 13
I 13
	tsaddr = (struct tsdevice *)ubamem(io->i_adapt, tsstd[io->i_ctlr]);
	errcnt = info = 0;
E 13
retry:
	while ((tsaddr->tssr & TS_SSR) == 0)
D 2
		;
	info = ubasetup(io, 1);
	ts.ts_cmd.c_size = io->i_cc;
	ts.ts_cmd.c_addr = info&0777777;
E 2
I 2
		DELAY(100);
	if (func == TS_REW || func == TS_SFORWF)
		ts.ts_cmd.c_repcnt = io->i_cc;
	else {
		info = ubasetup(io, 1);
		ts.ts_cmd.c_size = io->i_cc;
		ts.ts_cmd.c_loba = info;
		ts.ts_cmd.c_hiba = (info>>16)&3;
I 13
		if (func == READ)
			func = TS_RCOM;
		else if (func == WRITE)
			func = TS_WCOM;
E 13
	}
E 2
D 13
	if (func == READ)
		func = TS_RCOM;
	else if (func == WRITE)
		func = TS_WCOM;
E 13
	ts.ts_cmd.c_cmd = TS_ACK|TS_CVC|func;
	tsaddr->tsdb = ts_uba;
D 2
	while ((tsaddr->tssr & TS_SSR) == 0)
		;
	ubafree(io, info);
	if (ts.ts_sts.s_xs0 & TS_TMK)	/* tape mark */
E 2
I 2
	do
		DELAY(100)
	while ((tsaddr->tssr & TS_SSR) == 0);
	if (info)
		ubafree(io, info);
	if (ts.ts_sts.s_xs0 & TS_TMK)
E 2
		return (0);
	if (tsaddr->tssr & TS_SC) {
D 3
		if (errcnt == 0)
			printf("ts tape error: er=%o", tsaddr->tssr);
E 3
I 3
D 5
		printf("ts tape error: er=%b, xs0=%b",
E 5
I 5
		printf("ts tape error: er=%b, xs0=%b\n",
E 5
		    tsaddr->tssr, TSSR_BITS,
		    ts.ts_sts.s_xs0, TSXS0_BITS);
E 3
D 13
		if (errcnt==10) {
E 13
I 13
		if (errcnt++ == 10) {
E 13
D 3
			printf("\n");
E 3
I 3
			printf("ts: unrecovered error\n");
E 3
			return (-1);
		}
D 13
		errcnt++;
E 13
		if (func == TS_RCOM || func == TS_WCOM)
			func |= TS_RETRY;
		goto retry;
	}
	if (errcnt)
D 3
		printf(" recovered by retry\n");
E 3
I 3
		printf("ts: recovered by retry\n");
E 3
	return (io->i_cc - ts.ts_sts.s_rbpcr);
}
E 1
