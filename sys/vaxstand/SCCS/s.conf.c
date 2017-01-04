h04667
s 00017/00002/00143
d D 7.7 04/02/07 19:01:31 msokolov 31 30
c implemented bootdec and tons of VMB and ROM stuff to go with it
e
s 00010/00005/00135
d D 7.6 88/06/29 18:04:50 bostic 30 29
c install approved copyright notice
e
s 00076/00132/00064
d D 7.5 88/02/22 12:51:51 bostic 29 28
c move dev routines into machine independent file; clean up ioctl
c routine declarations
e
s 00046/00031/00150
d D 7.4 88/01/28 20:52:58 karels 28 27
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00180
d D 7.3 87/08/03 11:37:13 karels 27 26
c typo in ut name
e
s 00078/00027/00103
d D 7.2 87/02/21 11:41:30 karels 26 25
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00129
d D 7.1 86/06/05 01:40:47 mckusick 25 24
c 4.3BSD release version
e
s 00006/00006/00124
d D 6.3 85/08/02 19:01:27 bloom 24 23
c add 8600 support
e
s 00007/00001/00123
d D 6.2 85/06/08 13:07:14 mckusick 23 22
c Add copyright
e
s 00000/00000/00124
d D 6.1 83/07/29 07:46:39 sam 22 21
c 4.2 distribution
e
s 00006/00004/00118
d D 4.19 83/07/06 21:32:03 sam 21 20
c cleanup for 730's and 750's
e
s 00004/00000/00118
d D 4.18 83/04/30 17:39:18 edward 20 19
c rl driver no longer in 730
e
s 00004/00002/00114
d D 4.17 83/02/16 23:44:54 sam 19 18
c uda50 and rl11 boot blocks; 730 crud
e
s 00008/00006/00108
d D 4.16 83/02/16 21:49:49 sam 18 17
c read and write should return transfer count, not errno
e
s 00051/00020/00063
d D 4.15 82/12/30 15:30:43 sam 17 16
c add ioctl's + errno; fix chk to work with new stuff
e
s 00002/00001/00081
d D 4.14 82/12/17 16:59:59 sam 16 15
c pte.h is now in ../machine/
e
s 00003/00001/00079
d D 4.13 82/11/13 23:14:31 sam 15 14
c move includes for 4.1c directory layout
e
s 00001/00000/00079
d D 4.12 82/07/15 21:30:59 root 14 13
c new boot scheme
e
s 00013/00009/00066
d D 4.11 82/06/25 21:30:14 wnj 13 12
c upgrade boot code
e
s 00011/00001/00064
d D 4.10 82/05/27 17:15:01 sam 12 11
c add idc and remove massbus drivers for 730 (need space)
e
s 00002/00000/00063
d D 4.9 81/12/01 09:40:16 sam 11 10
c added ut
e
s 00005/00001/00058
d D 4.8 81/11/12 13:47:32 root 10 9
c added in uda and mt support
e
s 00001/00001/00058
d D 4.7 81/03/16 00:54:23 wnj 9 8
c fixes for generic functionality
e
s 00017/00026/00042
d D 4.6 81/03/15 20:45:56 wnj 8 7
c 
e
s 00001/00001/00067
d D 4.5 80/12/18 00:20:13 wnj 7 6
c fix spelling error
e
s 00008/00000/00060
d D 4.4 80/12/17 12:11:15 wnj 6 5
c fix for 750 (add rk, dont compile hp, ht)
e
s 00002/00002/00058
d D 4.3 80/11/14 01:26:19 bill 5 4
c typo
e
s 00002/00000/00058
d D 4.2 80/11/14 01:23:25 bill 4 3
c add tm
e
s 00000/00000/00058
d D 4.1 80/11/09 16:29:11 bill 3 2
c stamp for 4bsd
e
s 00001/00000/00057
d D 1.2 80/07/29 15:08:47 bill 2 1
c work w/o mba's
e
s 00057/00000/00000
d D 1.1 80/06/28 10:42:47 bill 1 0
c date and time created 80/06/28 10:42:47 by bill
e
u
U
t
T
I 1
D 8
/*	%M%	%I%	%G%	*/
E 8
I 8
D 23
/*	%M%	%I%	%E%	*/
E 23
I 23
/*
D 25
 * Copyright (c) 1982 Regents of the University of California.
E 25
I 25
D 29
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 25
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 29
I 29
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.
E 29
 *
I 29
 * Redistribution and use in source and binary forms are permitted
D 30
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 30
I 30
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
E 30
 *
E 29
 *	%W% (Berkeley) %G%
 */
E 23
E 8

I 16
D 29
#include "../machine/pte.h"

E 29
E 16
D 28
#include "../h/param.h"
#include "../h/inode.h"
I 2
D 16
#include "../h/pte.h"
E 16
E 2
D 8
#include "../h/mba.h"
E 8
I 8
D 15
#include "../h/mbareg.h"
E 15
I 14
#include "../h/fs.h"
E 28
I 28
#include "param.h"
#include "inode.h"
#include "fs.h"
E 28
I 15
D 29

E 29
D 28
#include "../vaxmba/mbareg.h"

E 28
E 15
E 14
E 8
#include "saio.h"

D 29
devread(io)
D 8
register struct iob *io;
E 8
I 8
	register struct iob *io;
E 8
{
I 17
D 18
	int error;
E 18
I 18
	int cc;
E 29
I 29
extern int	nullsys(), nodev(), noioctl();
E 29
E 18
E 17

D 8
	return( (*devsw[io->i_ino.i_dev].dv_strategy)(io,READ) );
E 8
I 8
D 17
	return( (*devsw[io->i_ino.i_dev].dv_strategy)(io, READ) );
E 17
I 17
D 29
	io->i_flgs |= F_RDDATA;
D 18
	error = (*devsw[io->i_ino.i_dev].dv_strategy)(io, READ);
E 18
I 18
	io->i_error = 0;
	cc = (*devsw[io->i_ino.i_dev].dv_strategy)(io, READ);
E 18
	io->i_flgs &= ~F_TYPEMASK;
D 18
	return (error);
E 18
I 18
	return (cc);
E 18
E 17
E 8
}

devwrite(io)
D 8
register struct iob *io;
E 8
I 8
	register struct iob *io;
E 8
{
I 17
D 18
	int error;
E 18
I 18
	int cc;
E 18
E 17
I 8

E 8
D 17
	return( (*devsw[io->i_ino.i_dev].dv_strategy)(io, WRITE) );
E 17
I 17
	io->i_flgs |= F_WRDATA;
D 18
	error = (*devsw[io->i_ino.i_dev].dv_strategy)(io, WRITE);
E 18
I 18
	io->i_error = 0;
	cc = (*devsw[io->i_ino.i_dev].dv_strategy)(io, WRITE);
E 18
	io->i_flgs &= ~F_TYPEMASK;
D 18
	return (error);
E 18
I 18
	return (cc);
E 18
E 17
}

devopen(io)
D 8
register struct iob *io;
E 8
I 8
	register struct iob *io;
E 8
{
I 8

E 8
D 26
	(*devsw[io->i_ino.i_dev].dv_open)(io);
E 26
I 26
	return (*devsw[io->i_ino.i_dev].dv_open)(io);
E 26
}

devclose(io)
D 8
register struct iob *io;
E 8
I 8
	register struct iob *io;
E 8
{
I 8

E 8
	(*devsw[io->i_ino.i_dev].dv_close)(io);
}

D 17
nullsys()
E 17
I 17
devioctl(io, cmd, arg)
	register struct iob *io;
	int cmd;
	caddr_t arg;
E 17
D 8
{ ; }
E 8
I 8
{
E 8

I 17
	return ((*devsw[io->i_ino.i_dev].dv_ioctl)(io, cmd, arg));
}

/*ARGSUSED*/
nullsys(io)
	struct iob *io;
{

E 17
I 8
	;
}

E 8
D 17
int	nullsys();
E 17
I 17
/*ARGSUSED*/
D 26
nullioctl(io, cmd, arg)
E 26
I 26
nodev(io)
E 26
	struct iob *io;
I 26
{

	errno = EBADF;
}

/*ARGSUSED*/
noioctl(io, cmd, arg)
	struct iob *io;
E 26
	int cmd;
	caddr_t arg;
{

	return (ECMD);
}

E 29
D 26
int	nullsys(), nullioctl();
E 26
E 17
I 12
D 24
#if defined(VAX780) || defined(VAX750)
E 24
I 24
#if defined(VAX780) || defined(VAX750) || defined(VAX8600)
I 26
#define	HP		"hp"
E 26
E 24
E 12
I 6
D 8
#if VAX==780
E 8
E 6
D 17
int	hpstrategy(), hpopen();
E 17
I 17
D 29
int	hpstrategy(), hpopen(), hpioctl();
E 29
I 29
int	hpstrategy(), hpopen();
#ifdef SMALL
#define	hpioctl		noioctl
E 29
I 26
#else
I 29
int	hpioctl();
#endif
#else
E 29
D 28
#define	HP		""
E 28
I 28
#define	HP		0
E 28
#define	hpstrategy	nodev
#define	hpopen		nodev
#define	hpioctl		noioctl
E 26
E 17
D 13
int	htstrategy(), htopen(), htclose();
E 13
I 12
#endif
I 21
D 24
#if defined(VAX780) || defined(VAX750)
E 24
I 24
D 26
#if defined(VAX780) || defined(VAX750) || defined(VAX8600)
E 26
E 24
E 21
E 12
I 6
D 8
#endif
E 8
E 6
D 17
int	upstrategy(), upopen();
I 13
int	rkstrategy(), rkopen();
int	udstrategy(), udopen();
int	idcstrategy(), idcopen();
E 17
I 17
D 29
int	upstrategy(), upopen(), upioctl();
I 21
D 26
#endif
E 26
E 21
int	rkstrategy(), rkopen(), rkioctl();
D 19
int	udstrategy(), udopen(), udioctl();
E 19
I 19
int	rastrategy(), raopen(), raioctl();
E 29
I 29

int	upstrategy(), upopen();
#ifdef SMALL
#define	upioctl		noioctl
#else
int	upioctl();
#endif

int	rkstrategy(), rkopen();
int	rastrategy(), raopen();

E 29
I 21
#if defined(VAX730)
I 26
#define	RB		"rb"
E 26
E 21
E 19
D 29
int	idcstrategy(), idcopen(), idcioctl();
E 29
I 29
int	idcstrategy(), idcopen();
E 29
I 26
#else
D 28
#define	RB		""
E 28
I 28
#define	RB		0
E 28
#define	idcstrategy	nodev
#define	idcopen		nodev
D 29
#define	idcioctl	noioctl
E 29
E 26
I 20
D 21
#if defined(VAX780) || defined(VAX750)
E 20
I 19
int	rlstrategy(), rlopen(), rlioctl();
E 21
I 20
#endif
I 21
D 29
int	rlstrategy(), rlopen(), rlioctl();
E 29
I 26

E 26
E 21
E 20
E 19
E 17
D 29
#ifndef BOOT
I 26
#define	TM		"tm"
E 26
E 13
I 4
D 5
int	tmstragety(), tmopen(), tmclose();
E 5
I 5
int	tmstrategy(), tmopen(), tmclose();
I 26
#define	TS		"ts"
E 26
I 8
int	tsstrategy(), tsopen(), tsclose();
I 12
D 24
#if defined(VAX780) || defined(VAX750)
E 24
I 24
#if defined(VAX780) || defined(VAX750) || defined(VAX8600)
I 26
#define	HT		"ht"
E 26
E 24
I 13
int	htstrategy(), htopen(), htclose();
I 26
#define	MT		"mt"
E 26
E 13
E 12
E 8
I 6
D 10
int	rkopen(),rkstrategy();
E 10
I 10
int	mtstrategy(), mtopen(), mtclose();
E 29
I 29
int	rlstrategy(), rlopen();
E 29
I 12
D 26
#endif
E 26
I 26

D 29
#else massbus vax
D 28
#define	HT		""
E 28
I 28
#define	HT		0
E 28
#define	htstrategy	nodev
#define	htopen		nodev
#define	htclose		nodev
D 28
#define	MT		""
E 28
I 28
#define	MT		0
E 28
#define	mtstrategy	nodev
#define	mtopen		nodev
#define	mtclose		nodev
#endif massbus vax

D 27
#define	UT		""
E 27
I 27
#define	UT		"ut"
E 27
E 26
E 12
D 13
int	rkstrategy(), rkopen();
int	udstrategy(), udopen();
E 13
I 11
int	utstrategy(), utopen(), utclose();
I 28
#define	TMSCP		"tms"
int	tmscpstrategy(), tmscpopen(), tmscpclose();
E 28
I 26
#else BOOT
E 29
I 29
#ifdef BOOT
E 29
D 28
#define	TM		""
E 28
I 28
#define	TM		0
E 28
#define	tmstrategy	nodev
#define	tmopen		nodev
#define	tmclose		nodev
D 28
#define	TS		""
E 28
I 28
#define	TS		0
E 28
#define	tsstrategy	nodev
#define	tsopen		nodev
#define	tsclose		nodev
D 28
#define	HT		""
E 28
I 28
#define	HT		0
E 28
#define	htstrategy	nodev
#define	htopen		nodev
#define	htclose		nodev
D 28
#define	MT		""
E 28
I 28
#define	MT		0
E 28
#define	mtstrategy	nodev
#define	mtopen		nodev
#define	mtclose		nodev
D 28
#define	UT		""
E 28
I 28
#define	UT		0
E 28
#define	utstrategy	nodev
#define	utopen		nodev
#define	utclose		nodev
I 28
#define	TMSCP		0
#define	tmscpstrategy	nodev
#define	tmscpopen	nodev
#define	tmscpclose	nodev
D 29
#endif BOOT
E 29
I 29
#else /* !BOOT */
#define	TM		"tm"
int	tmstrategy(), tmopen(), tmclose();
#define	TS		"ts"
int	tsstrategy(), tsopen(), tsclose();
E 29

I 29
#if defined(VAX780) || defined(VAX750) || defined(VAX8600)
#define	HT		"ht"
int	htstrategy(), htopen(), htclose();
#define	MT		"mt"
int	mtstrategy(), mtopen(), mtclose();
#else /* massbus vax */
#define	HT		0
#define	htstrategy	nodev
#define	htopen		nodev
#define	htclose		nodev
#define	MT		0
#define	mtstrategy	nodev
#define	mtopen		nodev
#define	mtclose		nodev
#endif /* massbus vax */

#define	UT		"ut"
int	utstrategy(), utopen(), utclose();
#define	TMSCP		"tms"
int	tmscpstrategy(), tmscpopen(), tmscpclose();
#endif /* BOOT */

E 29
#ifdef VAX8200
#define	KRA		"kra"
D 29
int	krastrategy(), kraopen(), kraioctl();
E 29
I 29
int	krastrategy(), kraopen();
E 29
#else
#define	KRA		0
#define	krastrategy	nodev
#define	kraopen		nodev
D 29
#define	kraioctl	noioctl
E 29
E 28
E 26
I 12
D 13
int	idcstrategy(), idcopen();
E 13
I 13
#endif
E 13
E 12
E 11
E 10
E 6
E 5
E 4

I 31
int	vmbopen(), vmbstrategy();
#ifdef BOOT
#define	VMBT		0
#define	vmbtopen	nodev
#define	vmbtclose	nodev
#else
#define	VMBT		"vmbt"
int	vmbtopen(), vmbtclose();
#endif

/*
 * We overload major numbers 12 and 13 for vmb and vmbt standalone-only drivers.
 * The kernel uses these major numbers for uu and rx, which are not used or
 * supported by the standalone system.
 */
E 31
struct devsw devsw[] = {
I 12
D 24
#if defined(VAX780) || defined(VAX750)
E 24
I 24
D 26
#if defined(VAX780) || defined(VAX750) || defined(VAX8600)
E 24
E 12
I 6
D 8
#if VAX==780
E 8
E 6
D 17
	"hp",	hpstrategy,	hpopen,		nullsys,
E 17
I 17
	{ "hp",	hpstrategy,	hpopen,		nullsys,	hpioctl },
E 17
D 13
	"ht",	htstrategy,	htopen,		htclose,
E 13
I 12
#endif
I 21
D 24
#if defined(VAX780) || defined(VAX750)
E 24
I 24
#if defined(VAX780) || defined(VAX750) || defined(VAX8600)
E 24
E 21
E 12
I 6
D 8
#endif
E 8
E 6
D 17
	"up",	upstrategy,	upopen,		nullsys,
I 4
D 5
	"tm",	tmstragety,	tmopen,		tmclose,
E 5
I 5
D 13
	"tm",	tmstrategy,	tmopen,		tmclose,
E 13
I 6
D 7
	"rk",	rkstrategy,	rkopen,		ullsys,
E 7
I 7
D 8
	"rk",	rkstrategy,	rkopen,		nullsys,
E 8
I 8
	"hk",	rkstrategy,	rkopen,		nullsys,
I 13
	"ra",	udstrategy,	udopen,		nullsys,
	"rb",	idcstrategy,	idcopen,	nullsys,
E 17
I 17
	{ "up",	upstrategy,	upopen,		nullsys,	upioctl },
I 21
#endif
E 21
	{ "hk",	rkstrategy,	rkopen,		nullsys,	rkioctl },
D 19
	{ "ra",	udstrategy,	udopen,		nullsys,	udioctl },
E 19
I 19
	{ "ra",	rastrategy,	raopen,		nullsys,	raioctl },
E 19
#if defined(VAX730)
	{ "rb",	idcstrategy,	idcopen,	nullsys,	idcioctl },
#endif
I 20
D 21
#if defined(VAX780) || defined(VAX750)
E 21
E 20
I 19
	{ "rl",	rlstrategy,	rlopen,		nullsys,	rlioctl },
I 20
D 21
#endif
E 21
E 20
E 19
E 17
#ifndef BOOT
E 13
D 9
	"ts",	tsstragety,	tsopen,		tsclose,
E 9
I 9
D 17
	"ts",	tsstrategy,	tsopen,		tsclose,
E 17
I 17
	{ "ts",	tsstrategy,	tsopen,		tsclose,	nullioctl },
E 17
I 12
D 24
#if defined(VAX780) || defined(VAX750)
E 24
I 24
#if defined(VAX780) || defined(VAX750) || defined(VAX8600)
E 24
I 13
D 17
	"ht",	htstrategy,	htopen,		htclose,
E 13
E 12
I 10
	"mt",	mtstrategy,	mtopen,		mtclose,
E 17
I 17
	{ "ht",	htstrategy,	htopen,		htclose,	nullioctl },
	{ "mt",	mtstrategy,	mtopen,		mtclose,	nullioctl },
E 17
I 12
#endif
E 12
D 13
	"ra",	udstrategy,	udopen,		nullsys,
I 11
D 12
	"ut",	utstrategy,	utopen,		utclose,
E 12
I 12
	"ut",	utstrategy,	utopen		utclose,
	"rb",	idcstrategy,	idcopen,	nullsys,
E 13
I 13
D 17
	"tm",	tmstrategy,	tmopen,		tmclose,
	"ut",	utstrategy,	utopen,		utclose,
E 17
I 17
	{ "tm",	tmstrategy,	tmopen,		tmclose,	nullioctl },
	{ "ut",	utstrategy,	utopen,		utclose,	nullioctl },
E 17
#endif
E 26
I 26
D 28
	{ HP,	hpstrategy,	hpopen,	nullsys,	hpioctl }, /* 0 = hp */
	{ HT,	htstrategy,	htopen,	htclose,	noioctl }, /* 1 = ht */
	{ "up",	upstrategy,	upopen,	nullsys,	upioctl }, /* 2 = up */
	{ "hk",	rkstrategy,	rkopen,	nullsys,	rkioctl }, /* 3 = hk */
	{ "",	nodev,		nodev,	nullsys,	noioctl }, /* 4 = sw */
	{ TM,	tmstrategy,	tmopen,	tmclose,	noioctl }, /* 5 = tm */
	{ TS,	tsstrategy,	tsopen,	tsclose,	noioctl }, /* 6 = ts */
	{ MT,	mtstrategy,	mtopen,	mtclose,	noioctl }, /* 7 = mt */
	{ "",	nodev,		nodev,	nullsys,	noioctl }, /* 8 = tu */
	{ "ra",	rastrategy,	raopen,	nullsys,	raioctl }, /* 9 = ra */
	{ UT,	utstrategy,	utopen,	utclose,	noioctl }, /* 10 = ut */
	{ RB,	idcstrategy,	idcopen,nullsys,	idcioctl },/* 11 = rb */
	{ "",	nodev,		nodev,	nullsys,	noioctl }, /* 12 = uu */
	{ "",	nodev,		nodev,	nullsys,	noioctl }, /* 13 = rx */
	{ "rl",	rlstrategy,	rlopen,	nullsys,	rlioctl }, /* 14 = rl */
E 26
E 13
E 12
E 11
E 10
E 9
E 8
E 7
E 6
E 5
E 4
D 17
	0,0,0,0
E 17
I 17
	{ 0, 0, 0, 0, 0 },
E 28
I 28
D 29
	{ HP,	hpstrategy,	hpopen,	nullsys, hpioctl }, /* 0 = hp */
	{ HT,	htstrategy,	htopen,	htclose, noioctl }, /* 1 = ht */
	{ "up",	upstrategy,	upopen,	nullsys, upioctl }, /* 2 = up */
	{ "hk",	rkstrategy,	rkopen,	nullsys, rkioctl }, /* 3 = hk */
	{ 0,	nodev,		nodev,	nullsys, noioctl }, /* 4 = sw */
	{ TM,	tmstrategy,	tmopen,	tmclose, noioctl }, /* 5 = tm */
	{ TS,	tsstrategy,	tsopen,	tsclose, noioctl }, /* 6 = ts */
	{ MT,	mtstrategy,	mtopen,	mtclose, noioctl }, /* 7 = mt */
	{ 0,	nodev,		nodev,	nullsys, noioctl }, /* 8 = tu */
	{ "ra",	rastrategy,	raopen,	nullsys, raioctl }, /* 9 = ra */
	{ UT,	utstrategy,	utopen,	utclose, noioctl }, /* 10 = ut */
	{ RB,	idcstrategy,	idcopen,nullsys, idcioctl },/* 11 = rb */
	{ 0,	nodev,		nodev,	nullsys, noioctl }, /* 12 = uu */
	{ 0,	nodev,		nodev,	nullsys, noioctl }, /* 13 = rx */
	{ "rl",	rlstrategy,	rlopen,	nullsys, rlioctl }, /* 14 = rl */
	{ TMSCP,tmscpstrategy,tmscpopen,tmscpclose,noioctl},/* 15 = tmscp */
	{ KRA,	krastrategy,	kraopen,nullsys, kraioctl}, /* 16 = kra */
E 29
I 29
	{ HP,	hpstrategy,	hpopen,	nullsys, hpioctl },  /*  0 = hp */
	{ HT,	htstrategy,	htopen,	htclose, noioctl },  /*  1 = ht */
	{ "up",	upstrategy,	upopen,	nullsys, upioctl },  /*  2 = up */
	{ "hk",	rkstrategy,	rkopen,	nullsys, noioctl },  /*  3 = hk */
	{ 0,	nodev,		nodev,	nullsys, noioctl },  /*  4 = sw */
	{ TM,	tmstrategy,	tmopen,	tmclose, noioctl },  /*  5 = tm */
	{ TS,	tsstrategy,	tsopen,	tsclose, noioctl },  /*  6 = ts */
	{ MT,	mtstrategy,	mtopen,	mtclose, noioctl },  /*  7 = mt */
	{ 0,	nodev,		nodev,	nullsys, noioctl },  /*  8 = tu */
	{ "ra",	rastrategy,	raopen,	nullsys, noioctl },  /*  9 = ra */
	{ UT,	utstrategy,	utopen,	utclose, noioctl },  /* 10 = ut */
	{ RB,	idcstrategy,	idcopen,nullsys, noioctl },  /* 11 = rb */
D 31
	{ 0,	nodev,		nodev,	nullsys, noioctl },  /* 12 = uu */
	{ 0,	nodev,		nodev,	nullsys, noioctl },  /* 13 = rx */
E 31
I 31
	{ "vmb",vmbstrategy,	vmbopen,nullsys, noioctl },  /* 12 = uu */
	{ VMBT,	vmbstrategy,	vmbtopen,vmbtclose,noioctl}, /* 13 = rx */
E 31
	{ "rl",	rlstrategy,	rlopen,	nullsys, noioctl },  /* 14 = rl */
	{ TMSCP,tmscpstrategy,tmscpopen,tmscpclose,noioctl}, /* 15 = tmscp */
	{ KRA,	krastrategy,	kraopen,nullsys, noioctl},   /* 16 = kra */
E 29
E 28
E 17
};
I 26

D 28
int	ndevs = (sizeof(devsw) / sizeof(devsw[0]) - 1);
E 28
I 28
D 29
int	ndevs = (sizeof(devsw) / sizeof(devsw[0]));
E 29
I 29
int	ndevs = (sizeof(devsw)/sizeof(devsw[0]));
E 29
E 28
E 26
D 8

I 6
#if VAX==780
E 6
int mbanum[] = {	/* mba number of major device */
	0,		/* disk */
	1,		/* tape */
	-1,		/* unused */
};

int *mbaloc[] = { 	/* physical location of mba */
	(int *)PHYSMBA0,
	(int *)PHYSMBA1,
};
I 6
#endif
E 8
E 6
E 1
