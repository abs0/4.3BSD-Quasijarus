h03724
s 00005/00002/00117
d D 7.5 88/07/09 14:40:04 karels 18 17
c check adaptor numbers against actual number
e
s 00001/00003/00118
d D 7.4 88/02/24 11:01:02 bostic 17 16
c default to dev error, doesn't tell you anything new
e
s 00020/00023/00101
d D 7.3 88/02/22 12:59:41 bostic 16 15
c change to dev(a,b,c,d) format
e
s 00008/00003/00116
d D 7.2 88/01/28 20:53:24 karels 15 14
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00118
d D 7.1 86/06/05 01:45:43 mckusick 14 13
c 4.3BSD release version
e
s 00007/00001/00112
d D 6.2 85/06/08 13:12:49 mckusick 13 12
c Add copyright
e
s 00000/00000/00113
d D 6.1 83/07/29 07:47:49 sam 12 11
c 4.2 distribution
e
s 00003/00000/00110
d D 4.11 83/07/01 05:06:17 sam 11 10
c fropm ghg: don't keep controller busy
e
s 00012/00008/00098
d D 4.10 83/03/02 14:48:40 sam 10 9
c didn't handle EOF marks properly
e
s 00001/00001/00105
d D 4.9 82/12/17 17:01:21 sam 9 8
c pte.h is now in ../machine/
e
s 00004/00002/00102
d D 4.8 82/11/13 23:15:25 sam 8 7
c move includes for 4.1c directory layout
e
s 00001/00000/00103
d D 4.7 82/07/15 21:32:21 root 7 6
c new boot scheme
e
s 00003/00003/00100
d D 4.6 81/12/01 09:53:21 root 6 5
c fix "device" name
e
s 00000/00001/00103
d D 4.5 81/04/03 03:01:55 root 5 4
c remove debug prf
e
s 00003/00004/00101
d D 4.4 81/04/03 03:01:39 root 4 3
c change error messages; make fsf work
e
s 00037/00060/00068
d D 4.3 81/03/15 20:46:52 wnj 3 2
c 
e
s 00035/00023/00093
d D 4.2 80/12/18 00:22:08 wnj 2 1
c it works now
e
s 00116/00000/00000
d D 4.1 80/11/14 01:24:02 bill 1 0
c date and time created 80/11/14 01:24:02 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%G%	*/
E 3
I 3
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
D 18
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 18
I 18
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 18
E 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 13

E 3
/*
D 3
 * TM tape driver
E 3
I 3
 * TM11/TE??
E 3
 */
I 9
D 18
#include "../machine/pte.h"
E 18
E 9

D 15
#include "../h/param.h"
#include "../h/inode.h"
D 9
#include "../h/pte.h"
E 9
D 3
#include "../h/uba.h"
E 3
I 3
D 8
#include "../h/ubareg.h"
E 8
I 7
#include "../h/fs.h"
E 15
I 15
#include "param.h"
#include "inode.h"
#include "fs.h"
E 15
I 8

I 18
#include "../vax/pte.h"

E 18
#include "../vaxuba/ubareg.h"
#include "../vaxuba/tmreg.h"

E 8
E 7
E 3
#include "saio.h"
I 3
#include "savax.h"
E 3

I 16
#define	MAXCTLR		1		/* all addresses must be specified */
u_short	tmstd[MAXCTLR] = { 0172520 };
E 16
D 3
struct device {
	short	tmer;
	short	tmcs;
	short	tmbc;
	u_short	tmba;
	short	tmdb;
	short	tmrd;
};
E 3
I 3
D 8
#include "../h/tmreg.h"
E 8
E 3

D 3
#define TMADDR ((struct device *)(PHYSUMEM + 0772520 - UNIBASE))
E 3
I 3
D 16
u_short	tmstd[] = { 0172520 };
E 3

E 16
D 3
#define GO	01
#define RCOM	02
#define WCOM	04
D 2
#define WEOF	06
E 2
I 2
#define WEOT	06
E 2
#define SFORW	010
#define SREV	012
#define WIRG	014
#define REW	016
D 2
#define DENS	060000		/* 9-channel */
#define IENABLE 0100
#define CRDY	0200
#define GAPSD	010000
#define TUR	1
#define SDWN	010
#define HARD	0102200 /* ILC, EOT, NXM */
#define EOF	0040000
E 2

I 2
#define DENS	0		/* 1600 bpi */

#define CRDY	0200		/* tmcs: control unit ready */
#define TUR	1		/* tmer: tape unit ready */
#define SDWN	010		/* tmer: tape settle down */
#define HARD	0102200		/* tmer: ILC, EOT, NXM */
#define EOT	0040000		/* tmer: at end of tape */

E 2
#define SSEEK	1
#define SIO	2

E 3
tmopen(io)
D 2
register struct iob *io;
E 2
I 2
	register struct iob *io;
E 2
{
D 16
	register skip;
E 16
I 16
	register int skip;
E 16

I 18
	if ((u_int)io->i_adapt >= nuba)
		return (EADAPT);
E 18
I 15
D 16
	if (badaddr((char *)ubamem(io->i_unit, tmstd[0]), sizeof (short))) {
		printf("nonexistent device\n");
E 16
I 16
	if ((u_int)io->i_ctlr >= MAXCTLR)
		return (ECTLR);
D 17
	if (badaddr((char *)ubamem(io->i_adapt, tmstd[io->i_ctlr]), sizeof(short))) {
		printf("tm: nonexistent device\n");
E 17
I 17
	if (badaddr((char *)ubamem(io->i_adapt, tmstd[io->i_ctlr]), sizeof(short)))
E 17
E 16
		return (ENXIO);
D 17
	}
E 17
E 15
D 3
	tmstrategy(io, REW);
E 3
I 3
	tmstrategy(io, TM_REW);
E 3
D 16
	skip = io->i_boff;
	while (skip--) {
E 16
I 16
	for (skip = io->i_part; skip--;) {
E 16
		io->i_cc = 0;
D 3
		while (tmstrategy(io, SFORW))
E 3
I 3
D 4
		while (tmstrategy(io, TM_SFORW))
E 3
			;
E 4
I 4
		tmstrategy(io, TM_SFORW);
E 4
	}
I 15
	return (0);
E 15
}

tmclose(io)
D 2
register struct iob *io;
E 2
I 2
	register struct iob *io;
E 2
{
I 2
D 16

E 16
E 2
D 3
	tmstrategy(io, REW);
E 3
I 3
	tmstrategy(io, TM_REW);
E 3
}

tmstrategy(io, func)
D 2
register struct iob *io;
E 2
I 2
	register struct iob *io;
E 2
{
D 16
	register int com, unit, errcnt;
I 2
D 3
	int word;
E 2
	int info;
E 3
I 3
D 6
	register struct device *tmaddr =
	    (struct device *)ubamem(io->i_unit, tmstd[0]);
E 6
I 6
	register struct tmdevice *tmaddr =
	    (struct tmdevice *)ubamem(io->i_unit, tmstd[0]);
E 16
I 16
	register int com, errcnt;
	register struct tmdevice *tmaddr;
E 16
E 6
	int word, info;
E 3

D 16
	unit = io->i_unit;
E 16
I 16
	tmaddr = (struct tmdevice *)ubamem(io->i_adapt, tmstd[io->i_ctlr]);
E 16
	errcnt = 0;
retry:
D 3
	tmquiet();
	com = (unit<<8)|DENS;
E 3
I 3
	tmquiet(tmaddr);
D 16
	com = (unit<<8);
E 16
E 3
	info = ubasetup(io, 1);
D 3
	TMADDR->tmbc = -io->i_cc;
	TMADDR->tmba = info;
E 3
I 3
	tmaddr->tmbc = -io->i_cc;
	tmaddr->tmba = info;
I 16
	com = (io->i_unit<<8) | TM_GO;
E 16
E 3
	if (func == READ)
D 3
		TMADDR->tmcs = com | RCOM | GO;
E 3
I 3
D 16
		tmaddr->tmcs = com | TM_RCOM | TM_GO;
E 16
I 16
		tmaddr->tmcs = com | TM_RCOM;
E 16
E 3
	else if (func == WRITE)
D 3
		TMADDR->tmcs = com | WCOM | GO;
	else if (func == SREV) {
		TMADDR->tmbc = -1;
		TMADDR->tmcs = com | SREV | GO;
E 3
I 3
D 16
		tmaddr->tmcs = com | TM_WCOM | TM_GO;
E 16
I 16
		tmaddr->tmcs = com | TM_WCOM;
E 16
	else if (func == TM_SREV) {
		tmaddr->tmbc = -1;
D 16
		tmaddr->tmcs = com | TM_SREV | TM_GO;
E 16
I 16
		tmaddr->tmcs = com | TM_SREV;
E 16
E 3
D 2
		return(0);
E 2
I 2
		return (0);
E 2
	} else
D 3
		TMADDR->tmcs = com | func | GO;
E 3
I 3
D 16
		tmaddr->tmcs = com | func | TM_GO;
E 16
I 16
		tmaddr->tmcs = com | func;
E 16
E 3
D 2
	while ((TMADDR->tmcs&CRDY) == 0)
E 2
I 2
	for (;;) {
D 3
		word = TMADDR->tmcs;
		if (word&CRDY)
E 3
I 3
		word = tmaddr->tmcs;
I 11
		DELAY(100);
E 11
D 10
		if (word&TM_CUR)
E 10
I 10
		if (word & TM_CUR)
E 10
E 3
			break;
	}
E 2
D 4
		;
E 4
D 3
	ubafree(info);
D 2
	if (TMADDR->tmer&EOF)
E 2
I 2
	word = TMADDR->tmer;
	if (word&EOT)
E 3
I 3
	ubafree(io, info);
	word = tmaddr->tmer;
I 4
D 5
	printf("tmer %b\n", word, TMER_BITS);
E 5
E 4
D 10
	if (word&TMER_EOT)
E 3
E 2
		return(0);
D 2
	if (TMADDR->tmer < 0) {
E 2
I 2
	if (word < 0) {
E 10
I 10
	if (word & TMER_EOT)
		return (0);
	if (word & TM_ERR) {
		if (word & TMER_EOF)
			return (0);
E 10
E 2
D 16
		if (errcnt == 0)
D 3
			printf("tape error: er=%o", TMADDR->tmer);
E 3
I 3
D 4
			printf("te error: er=%o", tmaddr->tmer);
E 4
I 4
D 10
			printf("te error: er=%b", tmaddr->tmer, TMER_BITS);
E 4
E 3
		if (errcnt==10) {
E 10
I 10
			printf("te error: er=%b", word, TMER_BITS);
		if (errcnt == 10) {
E 10
			printf("\n");
E 16
I 16
		printf("tm tape error: er=%b\n", word, TMER_BITS);
		if (errcnt++ == 10) {
			printf("tm: unrecovered error\n");
E 16
D 10
			return(-1);
E 10
I 10
			return (-1);
E 10
		}
D 16
		errcnt++;
E 16
D 3
		tmstrategy(io, SREV);
E 3
I 3
		tmstrategy(io, TM_SREV);
E 3
		goto retry;
	}
	if (errcnt)
D 16
		printf(" recovered by retry\n");
E 16
I 16
		printf("tm: recovered by retry\n");
E 16
D 2
	return( io->i_cc+TMADDR->tmbc );
E 2
I 2
D 3
	return (io->i_cc+TMADDR->tmbc);
E 3
I 3
D 10
	return (io->i_cc+tmaddr->tmbc);
E 10
I 10
	if (word & TMER_EOF)
		return (0);
	return (io->i_cc + tmaddr->tmbc);
E 10
E 3
E 2
}

D 3
tmquiet()
E 3
I 3
tmquiet(tmaddr)
D 6
	register struct device *tmaddr;
E 6
I 6
	register struct tmdevice *tmaddr;
E 6
E 3
{
D 2
	while ((TMADDR->tmcs&CRDY) == 0)
		;
	while ((TMADDR->tmer&TUR) == 0)
		;
	while ((TMADDR->tmer&SDWN) != 0)
		;
E 2
I 2
	register word;
	for (;;) {
D 3
		word = TMADDR->tmcs;
		if (word&CRDY)
E 3
I 3
		word = tmaddr->tmcs;
I 11
		DELAY(100);
E 11
		if (word&TM_CUR)
E 3
			break;
	}
	for (;;) {
D 3
		word = TMADDR->tmer;
		if ((word&TUR) && (word&SDWN)==0)
E 3
I 3
		word = tmaddr->tmer;
I 11
		DELAY(100);
E 11
		if ((word&TMER_TUR) && (word&TMER_SDWN)==0)
E 3
			break;
	}
E 2
}
E 1
