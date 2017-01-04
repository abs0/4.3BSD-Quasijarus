h56790
s 00008/00001/00262
d D 7.9 04/03/19 22:53:43 msokolov 25 24
c KA42 CPU support code is here
e
s 00032/00004/00231
d D 7.8 04/03/18 19:19:13 msokolov 24 23
c add BabyVAX support (beginnings thereof)
c a few other todo closures and fixes along the way
e
s 00006/00013/00229
d D 7.7 04/03/06 01:50:55 msokolov 23 22
c start knocking some sanity into VAXBI support
e
s 00007/00007/00235
d D 7.6 03/05/03 13:30:28 msokolov 22 21
c teach the kernel which CPUs have compatibility mode and which don't
e
s 00018/00001/00224
d D 7.5 88/08/27 07:01:17 tef 21 20
c Add support for microvax 3000.
e
s 00001/00001/00224
d D 7.4 88/07/09 14:11:39 karels 20 19
c update copyrights
e
s 00100/00005/00125
d D 7.3 88/05/07 14:19:24 karels 19 18
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00012/00021/00118
d D 7.2 86/08/09 15:09:25 karels 18 17
c generalize uba code to handle Q bus more gracefully
e
s 00001/00001/00138
d D 7.1 86/06/05 00:42:31 mckusick 17 16
c 4.3BSD release version
e
s 00019/00000/00120
d D 6.8 86/04/22 10:48:31 kridle 16 15
c Added MicroVAX II Support (KA630)
e
s 00005/00005/00115
d D 6.7 86/03/29 23:06:41 karels 15 14
c touchups
e
s 00016/00012/00104
d D 6.6 86/02/23 23:05:41 karels 14 13
c rework data structures to be more flexible about I/O buses
e
s 00004/00004/00112
d D 6.5 85/09/17 23:05:15 karels 13 12
c add cpuspeed variable to adjust delay macro
e
s 00046/00003/00070
d D 6.4 85/08/05 18:08:30 bloom 12 11
c add support for 8600
e
s 00007/00001/00066
d D 6.3 85/06/08 13:41:22 mckusick 11 10
c Add copyright
e
s 00004/00004/00063
d D 6.2 84/08/28 18:09:26 bloom 10 9
c Change to includes.  No more ../h
e
s 00000/00000/00067
d D 6.1 83/07/29 07:19:41 sam 9 8
c 4.2 distribution
e
s 00002/00001/00065
d D 4.8 82/12/17 11:55:40 sam 8 7
c sun merge
e
s 00004/00003/00062
d D 4.7 82/10/13 22:13:44 root 7 6
c rearrange header files
e
s 00007/00007/00058
d D 4.6 82/05/26 15:45:01 sam 6 5
c 7ZZ -> 730
e
s 00001/00000/00064
d D 4.5 81/04/13 12:21:12 wnj 5 4
c fix missing #endif
e
s 00002/00001/00062
d D 4.4 81/04/09 09:03:31 root 4 3
c clean up conditionals
e
s 00006/00006/00057
d D 4.3 81/04/03 00:08:46 root 3 2
c s/730/7ZZ
e
s 00013/00001/00050
d D 4.2 81/03/21 16:00:37 wnj 2 1
c add 730
e
s 00051/00000/00000
d D 4.1 81/03/13 21:45:08 wnj 1 0
c date and time created 81/03/13 21:45:08 by wnj
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 17
 * Copyright (c) 1982 Regents of the University of California.
E 17
I 17
D 20
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 20
E 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11

I 8
D 10
#include "../machine/pte.h"
E 10
I 10
#include "pte.h"
E 10

E 8
D 10
#include "../h/param.h"
E 10
I 10
#include "param.h"
E 10
D 8
#include "../h/pte.h"
E 8
D 7
#include "../h/ubareg.h"
#include "../h/nexus.h"
#include "../h/cpu.h"
E 7
I 7

D 10
#include "../vax/cpu.h"
#include "../vax/nexus.h"
E 10
I 10
#include "cpu.h"
I 24
#include "cpucond.h"
E 24
#include "nexus.h"
I 12
#include "ioa.h"
I 19
#include "../vaxbi/bireg.h"
E 19
E 12
E 10
#include "../vaxuba/ubareg.h"
E 7

/*
 * Initialization of per-cpu data structures.
 */

/*
D 18
 * These are the (fixed) addresses of the (last 8k bytes of)
 * unibus memory for each of the possible unibus adapters.  Note that the
 * unibus memory addresses are actually indexed by the unibus adapter type code.
E 18
I 18
 * These are the (fixed) physical addresses of the
 * unibus memory for each of the possible unibus adapters.
 * Note that on some machines the unibus memory addresses
 * are actually indexed by the unibus adapter type code.
E 18
 */
I 12
#if VAX8600
caddr_t umaddr8600a[4] = {
	(caddr_t) UMEMA8600(0),	(caddr_t) UMEMA8600(1),
	(caddr_t) UMEMA8600(2),	(caddr_t) UMEMA8600(3),
};
caddr_t umaddr8600b[4] = {
	(caddr_t) UMEMB8600(0),	(caddr_t) UMEMB8600(1),
	(caddr_t) UMEMB8600(2),	(caddr_t) UMEMB8600(3),
};
#endif
E 12
#if VAX780
caddr_t	umaddr780[4] = {
	(caddr_t) UMEM780(0), (caddr_t) UMEM780(1),
	(caddr_t) UMEM780(2), (caddr_t) UMEM780(3)
};
#endif
#if VAX750
caddr_t	umaddr750[2] = {
	(caddr_t) UMEM750(0), (caddr_t) UMEM750(1),
};
#endif
I 2
D 3
#if VAX730
caddr_t	umaddr730[1] = {
	(caddr_t) UMEM730
E 3
I 3
D 6
#if VAX7ZZ
caddr_t	umaddr7ZZ[1] = {
	(caddr_t) UMEM7ZZ
E 6
I 6
#if VAX730
caddr_t	umaddr730[1] = {
	(caddr_t) UMEM730
E 6
E 3
};
#endif
I 16
D 18
#if VAX630
caddr_t	umaddr630[1] = {
	(caddr_t) UMEM630
};
#endif
E 18
E 16
E 2

D 4
#if VAX750
E 4
/*
 * Information to patch around the stupidity of configuration
D 2
 * registers not returning types on some of the 11/750 slots.
E 2
I 2
 * registers not returning types on some of the processors.
E 2
 */
I 4
#if VAX750
E 4
short	nexty750[NNEX750] = {
	NEX_MEM16,	NEX_MEM16,	NEX_MEM16,	NEX_MEM16,
	NEX_MBA,	NEX_MBA,	NEX_MBA,	NEX_MBA,
	NEX_UBA0,	NEX_UBA1,	NEX_ANY,	NEX_ANY,
	NEX_ANY,	NEX_ANY,	NEX_ANY,	NEX_ANY
};
I 5
#endif
E 5
I 4
D 6
#if VAX7ZZ
E 4
I 2
D 3
short	nexty730[NNEX730] = {
E 3
I 3
short	nexty7ZZ[NNEX7ZZ] = {
E 6
I 6
#if VAX730
short	nexty730[NNEX730] = {
E 6
E 3
	NEX_MEM16,	NEX_ANY,	NEX_ANY,	NEX_ANY,
	NEX_ANY,	NEX_ANY,	NEX_ANY,	NEX_ANY,
};
E 2
#endif

I 19
#if VAX8800
D 23
/* I think this is how the thing is shaped: */
struct bibus bi8800[] = {
	{ BI_BASE(0) },
	{ BI_BASE(1) },
};
E 23
I 23
/* According to VARM implementation blurb, this is the structure: */
E 23
struct iobus io8800 = {
D 23
	{ IO_BIA, somewhere, somesize, (caddr_t)&bi8800[0] },
	{ IO_BIA, somewhere, somesize, (caddr_t)&bi8800[1] },
E 23
I 23
	{ IO_BI, 0, 0, (caddr_t) 0 },
	{ IO_BI, 0, 0, (caddr_t) 1 },
	{ IO_BI, 0, 0, (caddr_t) 2 },
	{ IO_BI, 0, 0, (caddr_t) 3 },
E 23
};
D 23
/* but you will have to make it work yourself (sorry) */
E 23
#endif

E 19
I 12
#if VAX8600
D 14
struct persbi sbi8600[2] = {
E 14
I 14
struct nexusconnect sbi8600[] = {
E 14
D 18
	{ NNEX8600, NEXA8600, umaddr8600a, NBDP8600, 1, 0 },
	{ NNEX8600, NEXB8600, umaddr8600b, NBDP8600, 1, 0 },
E 18
I 18
	{ NNEX8600, NEXA8600, DW780, NBDP8600, umaddr8600a, 0 },
	{ NNEX8600, NEXB8600, DW780, NBDP8600, umaddr8600b, 0 },
E 18
};
D 14
caddr_t ioaaddr8600[] = { IOA8600(0), IOA8600(1) };
E 14
I 14
struct iobus io8600[] = {
D 15
	{ IOA8600(0), IOAMAPSIZ, IO_ABUS, (caddr_t)&sbi8600[0] },
	{ IOA8600(1), IOAMAPSIZ, IO_ABUS, (caddr_t)&sbi8600[1] },
E 15
I 15
	{ IO_ABUS, IOA8600(0), IOAMAPSIZ, (caddr_t)&sbi8600[0] },
	{ IO_ABUS, IOA8600(1), IOAMAPSIZ, (caddr_t)&sbi8600[1] },
E 15
};
E 14
#endif
I 16
D 18
#if VAX630
short	nexty630[NNEX630] = {
	NEX_UBA0,
};
#endif
E 18
E 16

I 19
#if VAX8200
D 23
/* BEWARE, this is all limited to one BI for now */
struct bibus bi8200[] = {
	{ BI_BASE(0) },
};
E 23
struct iobus io8200[] = {
D 23
	{ IO_BI, 0, 0, (caddr_t)&bi8200[0] },
E 23
I 23
	{ IO_BI, 0, 0, (caddr_t) 0 },
E 23
};
#endif

E 19
#if VAX780
D 14
struct persbi sbi780 = {
E 14
I 14
struct nexusconnect sbi780 = {
E 14
D 18
	NNEX780, NEX780, umaddr780, NBDP780, 1, 0,
E 18
I 18
	NNEX780, NEX780, DW780, NBDP780, umaddr780, 0,
E 18
};
D 14
short ioa780[] = { IOA_SBI780 };
E 14
I 14
D 15
struct iobus io780[] = { 0, 0, IO_SBI780, (caddr_t)&sbi780 };
E 15
I 15
struct iobus io780[] = { IO_SBI780, 0, 0, (caddr_t)&sbi780 };
E 15
E 14
#endif

#if VAX750
D 14
struct persbi cmi750 = {
E 14
I 14
struct nexusconnect cmi750 = {
E 14
D 18
	NNEX750, NEX750, umaddr750, NBDP750, 0, nexty750,
E 18
I 18
	NNEX750, NEX750, DW750, NBDP750, umaddr750, nexty750,
E 18
};
D 14
short ioa750[] = { IOA_CMI750 };
E 14
I 14
D 15
struct iobus io750[] = { 0, 0, IO_CMI750, (caddr_t)&cmi750 };
E 15
I 15
struct iobus io750[] = { IO_CMI750, 0, 0, (caddr_t)&cmi750 };
E 15
E 14
#endif

#if VAX730
D 14
struct persbi xxx730 = {
E 14
I 14
struct nexusconnect xxx730 = {
E 14
D 18
	NNEX730, NEX730, umaddr730, NBDP730, 0, nexty730,
E 18
I 18
	NNEX730, NEX730, DW730, NBDP730, umaddr730, nexty730,
E 18
};
D 14
short ioa730[] = { IOA_XXX730 };
E 14
I 14
D 15
struct iobus io730[] = { 0, 0, IO_XXX730, (caddr_t)&xxx730 };
E 15
I 15
struct iobus io730[] = { IO_XXX730, 0, 0, (caddr_t)&xxx730 };
E 15
E 14
#endif
I 24

E 24
I 16
D 21
#if VAX630
E 21
I 21
#if VAX630 || VAX650
E 21
D 18
struct nexusconnect xxx630 = {
	NNEX630, NEX630, umaddr630, NBDP630, 0, nexty630,
E 18
I 18
struct qbus qbus630 = {
	QBA, QBAPAGES, QBAMAP630, (caddr_t)QMEM630, (caddr_t)QIOPAGE630
E 18
};
D 18
struct iobus io630[] = { IO_QBUS, 0, 0, (caddr_t)&xxx630 };
E 18
I 18
struct iobus io630[] = { IO_QBUS, 0, 0, (caddr_t)&qbus630 };
E 18
#endif
E 16

I 24
#if NEED_BABYVAX_SUPPORT
struct iobus iobabyvax[] = {
	{ IO_BABYVAX, 0, 0, (caddr_t) 0 },
};
#endif

E 24
I 19
/*
 * Clock info
 */
#if VAX8600 || VAX780 || VAX750 || VAX730
int vaxstd_clkstartrt(), vaxstd_clkread(), vaxstd_clkwrite();
struct clockops vaxstd_clockops = {
	vaxstd_clkstartrt, vaxstd_clkread, vaxstd_clkwrite
};
#endif
E 19
I 14

I 19
#if VAX8200
int vaxstd_clkstartrt(), ka820_clkread(), ka820_clkwrite();
struct clockops ka820_clockops = {
	vaxstd_clkstartrt, ka820_clkread, ka820_clkwrite
};
#endif

#if VAX630
D 24
int ka630_clkstartrt(), ka630_clkread(), ka630_clkwrite();
E 24
I 24
int uvax_clkstartrt(), ka630_clkread(), ka630_clkwrite();
E 24
struct clockops ka630_clockops = {
D 24
	ka630_clkstartrt, ka630_clkread, ka630_clkwrite
E 24
I 24
	uvax_clkstartrt, ka630_clkread, ka630_clkwrite
E 24
};
#endif

I 21
#if VAX650
D 24
int ka650_clkstartrt(), vaxstd_clkread(), vaxstd_clkwrite();
E 24
I 24
int uvax_clkstartrt(), vaxstd_clkread(), vaxstd_clkwrite();
E 24
struct clockops ka650_clockops = {
D 24
	ka650_clkstartrt, vaxstd_clkread, vaxstd_clkwrite
E 24
I 24
	uvax_clkstartrt, vaxstd_clkread, vaxstd_clkwrite
E 24
};
#endif

I 24
#if NEED_BABYVAX_SUPPORT
int uvax_clkstartrt(), babyvax_clkread(), babyvax_clkwrite();
struct clockops babyvax_clockops = {
	uvax_clkstartrt, babyvax_clkread, babyvax_clkwrite
};
#endif

E 24
E 21
/*
 * CPU dependent routines.
 */
#if VAX8600
int	ka860_memenable(), ka860_memerr(), ka860_mchk();
struct	cpuops ka860_ops = {
	&vaxstd_clockops, ka860_memenable, ka860_memerr, ka860_mchk, NULL
};
#endif

#if VAX8200
int	ka820_memenable(), ka820_memerr(), ka820_mchk(), ka820_init();
struct	cpuops ka820_ops = {
	&ka820_clockops, ka820_memenable, ka820_memerr, ka820_mchk, ka820_init
};
#endif

#if VAX780
int	ka780_memenable(), ka780_memerr(), ka780_mchk();
struct	cpuops ka780_ops = {
	&vaxstd_clockops, ka780_memenable, ka780_memerr, ka780_mchk, NULL
};
#endif

#if VAX750
int	ka750_memenable(), ka750_memerr(), ka750_mchk();
struct	cpuops ka750_ops = {
	&vaxstd_clockops, ka750_memenable, ka750_memerr, ka750_mchk, NULL
};
#endif

#if VAX730
int	ka730_memenable(), ka730_memerr(), ka730_mchk();
struct	cpuops ka730_ops = {
	&vaxstd_clockops, ka730_memenable, ka730_memerr, ka730_mchk, NULL
};
#endif

#if VAX630
int	ka630_memnop(), ka630_mchk(), ka630_init();
struct	cpuops ka630_ops = {
	&ka630_clockops, ka630_memnop, ka630_memnop, ka630_mchk, ka630_init
};
#endif

I 21
#if VAX650
int	ka650_memnop(), ka650_memerr(), ka650_mchk(), ka650_init();
struct	cpuops ka650_ops = {
	&ka650_clockops, ka650_memnop, ka650_memerr, ka650_mchk, ka650_init
};
#endif

I 24
#if VAX410
int	ka410_memnop(), ka410_mchk(), ka410_init();
struct	cpuops ka410_ops = {
	&babyvax_clockops, ka410_memnop, ka410_memnop, ka410_mchk, ka410_init
};
#endif

I 25
#if VAX3100
int	ka42_memnop(), ka42_memerr(), ka42_mchk(), ka42_init();
struct	cpuops ka42_ops = {
	&babyvax_clockops, ka42_memnop, ka42_memerr, ka42_mchk, ka42_init
};
#endif

E 25
E 24
E 21
E 19
E 14
E 12
struct percpu percpu[] = {
I 12
#if VAX8600
D 13
	{ VAX_8600, 2, ioaaddr8600, 512, (short *)0 },
E 13
I 13
D 14
	{ VAX_8600, 4, 2, ioaaddr8600, 512, (short *)0 },
E 14
I 14
D 19
	{ VAX_8600, 6, 2, io8600 },
E 19
I 19
D 22
	{ VAX_8600, 6, 2, io8600, &ka860_ops },
E 22
I 22
	{ VAX_8600, 6, 1, 2, io8600, &ka860_ops },
E 22
E 19
E 14
E 13
#endif
I 19
#if VAX8200
D 22
	{ VAX_8200, 2, 1, io8200, &ka820_ops },
E 22
I 22
	{ VAX_8200, 2, 0, 1, io8200, &ka820_ops },
E 22
#endif
E 19
E 12
#if VAX780
D 12
	VAX_780, NNEX780, NEX780, umaddr780, NBDP780, 1, 0,
E 12
I 12
D 13
	{ VAX_780, 1, (caddr_t *)0, 0, ioa780 },
E 13
I 13
D 14
	{ VAX_780, 2, 1, (caddr_t *)0, 0, ioa780 },
E 14
I 14
D 19
	{ VAX_780, 2, 1, io780 },
E 19
I 19
D 22
	{ VAX_780, 2, 1, io780, &ka780_ops },
E 22
I 22
	{ VAX_780, 2, 1, 1, io780, &ka780_ops },
E 22
E 19
E 14
E 13
E 12
#endif
#if VAX750
D 12
	VAX_750, NNEX750, NEX750, umaddr750, NBDP750, 0, nexty750,
E 12
I 12
D 13
	{ VAX_750, 1, (caddr_t *)0, 0, ioa750 },
E 13
I 13
D 14
	{ VAX_750, 1, 1, (caddr_t *)0, 0, ioa750 },
E 14
I 14
D 19
	{ VAX_750, 1, 1, io750 },
E 19
I 19
D 22
	{ VAX_750, 1, 1, io750, &ka750_ops },
E 22
I 22
	{ VAX_750, 1, 1, 1, io750, &ka750_ops },
E 22
E 19
E 14
E 13
E 12
I 2
#endif
D 3
#if VAX730
	VAX_730, NNEX730, NEX730, umaddr730, NBDP730, 0, nexty730,
E 3
I 3
D 6
#if VAX7ZZ
	VAX_7ZZ, NNEX7ZZ, NEX7ZZ, umaddr7ZZ, NBDP7ZZ, 0, nexty7ZZ,
E 6
I 6
#if VAX730
D 12
	VAX_730, NNEX730, NEX730, umaddr730, NBDP730, 0, nexty730,
E 12
I 12
D 13
	{ VAX_730, 1, (caddr_t *)0, 0, ioa730 },
E 13
I 13
D 14
	{ VAX_730, 1, 1, (caddr_t *)0, 0, ioa730 },
E 14
I 14
D 19
	{ VAX_730, 1, 1, io730 },
E 19
I 19
D 22
	{ VAX_730, 1, 1, io730, &ka730_ops },
E 22
I 22
	{ VAX_730, 1, 1, 1, io730, &ka730_ops },
E 22
E 19
I 16
#endif
#if VAX630
D 19
	{ VAX_630, 2, 1, io630 },
E 19
I 19
D 22
	{ VAX_630, 2, 1, io630, &ka630_ops },
E 22
I 22
	{ VAX_630, 2, 0, 1, io630, &ka630_ops },
E 22
I 21
#endif
#if VAX650
D 22
	{ VAX_650, 4, 1, io630, &ka650_ops },
E 22
I 22
	{ VAX_650, 4, 0, 1, io630, &ka650_ops },
I 24
#endif
#if VAX410
	{ VAX_410, 2, 0, 1, iobabyvax, &ka410_ops },
#endif
#if VAX3100
D 25
	{ VAX_3100, 4, 0, 1, iobabyvax, &ka410_ops },	/* XXX */
E 25
I 25
	{ VAX_3100, 4, 0, 1, iobabyvax, &ka42_ops },
E 25
E 24
E 22
E 21
E 19
E 16
E 14
E 13
E 12
E 6
E 3
E 2
#endif
	0,
};
E 1
