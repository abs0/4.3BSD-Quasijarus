h48150
s 00000/00025/00373
d D 7.14 04/02/07 11:35:18 msokolov 24 23
c started standalone system revamping
e
s 00001/00000/00397
d D 7.13 99/09/05 14:08:54 msokolov 23 22
c recognize BI KLESI as a DWBUA in disguise
e
s 00016/00003/00381
d D 7.12 88/08/27 07:22:45 tef 22 21
c Add support for microvax 3000.
e
s 00001/00001/00383
d D 7.11 88/07/10 10:23:27 karels 21 20
c I'm impatient
e
s 00199/00076/00185
d D 7.10 88/07/09 14:39:27 karels 20 19
c real autoconfiguration for 780/8600, based on code from kre
e
s 00008/00008/00253
d D 7.9 88/07/01 18:31:08 karels 19 18
c don't look for consoles except on 630
e
s 00008/00003/00253
d D 7.8 88/07/01 17:17:10 karels 18 17
c need to omit qv/qd from bootxx's
e
s 00002/00001/00254
d D 7.7 88/06/29 19:26:35 bostic 17 16
c The original version used the uba memory space; now it is supposed
c to point directly to I/O space, but that never got changed.
c from Chris Torek
e
s 00001/00001/00254
d D 7.6 88/06/29 19:24:12 bostic 16 15
c vax/bireg.h -> vaxbi/bireg.h
e
s 00019/00000/00236
d D 7.5 88/06/06 15:47:53 marc 15 14
c support for display drivers as console
e
s 00004/00000/00232
d D 7.4 88/02/06 12:30:42 karels 14 13
c init cpuspeed
e
s 00130/00023/00102
d D 7.3 88/01/28 20:52:52 karels 13 12
c uvax changes; fix devsw index in confxx; header updates
e
s 00030/00007/00095
d D 7.2 87/02/21 11:41:26 karels 12 11
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00101
d D 7.1 86/06/05 01:40:05 mckusick 11 10
c 4.3BSD release version
e
s 00002/00001/00100
d D 6.3 85/08/02 18:58:20 bloom 10 9
c add 8600 support
e
s 00007/00001/00094
d D 6.2 85/06/08 13:06:27 mckusick 9 8
c Add copyright
e
s 00000/00000/00095
d D 6.1 83/07/29 07:46:30 sam 8 7
c 4.2 distribution
e
s 00002/00001/00093
d D 4.7 82/12/17 16:59:54 sam 7 6
c pte.h is now in ../machine/
e
s 00007/00005/00087
d D 4.6 82/11/13 23:14:26 sam 6 5
c move includes for 4.1c directory layout
e
s 00011/00007/00081
d D 4.5 82/07/15 21:30:48 root 5 4
c new boot scheme
e
s 00007/00007/00081
d D 4.4 81/04/03 00:10:36 root 4 3
c s/730/7ZZ
e
s 00018/00000/00070
d D 4.3 81/03/22 20:47:11 wnj 3 2
c adapter init at boot
e
s 00015/00003/00055
d D 4.2 81/03/21 17:28:13 wnj 2 1
c fix 750, add 730
e
s 00058/00000/00000
d D 4.1 81/03/15 20:49:24 wnj 1 0
c date and time created 81/03/15 20:49:24 by wnj
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
D 11
 * Copyright (c) 1982 Regents of the University of California.
E 11
I 11
D 20
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 20
E 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9

I 7
D 20
#include "../machine/pte.h"

E 20
E 7
D 13
#include "../h/param.h"
E 13
I 13
#include "param.h"
I 20
#include "reboot.h"
E 20
E 13
D 6
#include "../h/cpu.h"
#include "../h/nexus.h"
E 6
D 7
#include "../h/pte.h"
E 7
D 6
#include "../h/ubareg.h"
#include "../h/mbareg.h"
#include "../h/mtpr.h"
E 6
I 6

#include "../vax/cpu.h"
#include "../vax/nexus.h"
I 20
#include "../vax/pte.h"
#include "../vax/mtpr.h"
E 20
#include "../vaxuba/ubareg.h"
#include "../vaxmba/mbareg.h"
D 20
#include "../vax/mtpr.h"
E 20

E 6
#include "savax.h"

I 13
#ifdef VAX8200
D 16
#include "../vax/bireg.h"
E 16
I 16
#include "../vaxbi/bireg.h"
I 20
#endif

#if VAX8600 || VAX8200 || VAX780
E 20
E 16
/*
D 20
 * These are found during configuration, rather than being compiled in
 * statically.
E 20
I 20
 * These are used on CPU's that do configuration.
E 20
 */
D 20
struct	uba_regs *ubaddr8200[MAXNUBA];
caddr_t	uioaddr8200[MAXNUBA];
E 20
I 20
struct	uba_regs *ubaddrspace[MAXNUBA];
caddr_t	uioaddrspace[MAXNUBA];
struct	mba_regs *mbaddrspace[MAXNMBA];
E 20
#endif

D 20
#if VAX8600 || VAX780
E 13
#define	UTR(i)	((struct uba_regs *)(NEX780+(i)))
D 13
#define	UMA(i)	((caddr_t)UMEM780(i))
E 13
I 13
#define	UMA(i)	((caddr_t)UMEM780(i)+UBAIOADDR)
E 13
#define	MTR(i)	((struct mba_regs *)(NEX780+(i)))
I 12
#define	UTRB(i)	((struct uba_regs *)(NEXB8600+(i)))
D 13
#define	UMAB(i)	((caddr_t)UMEMB8600(i))
E 13
I 13
#define	UMAB(i)	((caddr_t)UMEMB8600(i)+UBAIOADDR)
E 13
#define	MTRB(i)	((struct mba_regs *)(NEXB8600+(i)))
E 12

D 12
struct	uba_regs *ubaddr780[] = { UTR(3), UTR(4), UTR(5), UTR(6) };
caddr_t	umaddr780[] = { UMA(0), UMA(1), UMA(2), UMA(3) };
struct	mba_regs *mbaddr780[] = { MTR(8), MTR(9), MTR(10), MTR(11) };
E 12
I 12
struct	uba_regs *ubaddr780[] = {
	UTR(3), UTR(4), UTR(5), UTR(6),
#if VAX8600
	UTRB(3), UTRB(4), UTRB(5), UTRB(6),
#endif
};
D 13
caddr_t	umaddr780[] = {
E 13
I 13
caddr_t	uioaddr780[] = {
E 13
	UMA(0), UMA(1), UMA(2), UMA(3),
#if VAX8600
	UMAB(0), UMAB(1), UMAB(2), UMAB(3),
#endif
};
struct	mba_regs *mbaddr780[] = {
	MTR(8), MTR(9), MTR(10), MTR(11),
#if VAX8600
	MTRB(8), MTRB(9), MTRB(10), MTRB(11),
#endif
};
E 12

#undef	UTR
#undef	UMA
#undef	MTR
I 13
#endif
E 13

E 20
I 13
#if VAX750
E 13
#define	UTR(i)	((struct uba_regs *)(NEX750+(i)))
D 13
#define	UMA(i)	((caddr_t)UMEM750(i))
E 13
I 13
#define	UMA(i)	((caddr_t)UMEM750(i)+UBAIOADDR)
E 13
#define	MTR(i)	((struct mba_regs *)(NEX750+(i)))

struct	uba_regs *ubaddr750[] = { UTR(8), UTR(9) };
D 13
caddr_t	umaddr750[] = { UMA(0), UMA(1) };
E 13
I 13
caddr_t	uioaddr750[] = { UMA(0), UMA(1) };
E 13
D 2
struct	mba_regs *mbaddr750[] = { MTR(3), MTR(4), MTR(5), MTR(6) };
E 2
I 2
struct	mba_regs *mbaddr750[] = { MTR(4), MTR(5), MTR(6), MTR(7) };
E 2

#undef	UTR
#undef	UMA
#undef	MTR
I 13
#endif
E 13

I 13
#if VAX730
E 13
I 2
D 4
#define	UTR(i)	((struct uba_regs *)(NEX730+(i)))
#define	UMA	((caddr_t)UMEM730)
E 4
I 4
D 5
#define	UTR(i)	((struct uba_regs *)(NEX7ZZ+(i)))
#define	UMA	((caddr_t)UMEM7ZZ)
E 5
I 5
#define	UTR(i)	((struct uba_regs *)(NEX730+(i)))
D 13
#define	UMA	((caddr_t)UMEM730)
E 13
I 13
#define	UMA	((caddr_t)UMEM730+UBAIOADDR)
E 13
E 5
E 4

D 4
struct	uba_regs *ubaddr730[] = { UTR(3) };
caddr_t	umaddr730[] = { UMA };
E 4
I 4
D 5
struct	uba_regs *ubaddr7ZZ[] = { UTR(3) };
caddr_t	umaddr7ZZ[] = { UMA };
E 5
I 5
struct	uba_regs *ubaddr730[] = { UTR(3) };
D 13
caddr_t	umaddr730[] = { UMA };
E 13
I 13
caddr_t	uioaddr730[] = { UMA };
E 13
E 5
E 4

#undef	UTR
#undef	UMA
I 13
#endif
E 13

I 13
D 22
#if VAX630
E 22
I 22
#if VAX630 || VAX650
E 22
/*
 * The map registers start at 20088000 on the ka630, so
 * subtract a 2k offset to make things work.
 *
 * This could stand serious cleanup.
 */
struct	uba_regs *ubaddr630[] =
	{ (struct uba_regs *)((caddr_t)QBAMAP630 - 0x800) };
caddr_t	uioaddr630[] = { (caddr_t)QIOPAGE630 };
I 18
D 24

D 20
int (*v_getc)()=0,
    (*v_putc)()=0;
E 20
I 20
int (*v_getc)(), (*v_putc)();
E 20

#ifndef SMALL
E 18
I 15
/*
 * Virtual console configuration tables.
 */
extern qv_init(),qd_init();

int (*vcons_init[])() = {
	qd_init,
	qv_init,
	0
};
E 24
D 18
int (*v_getc)()=0,
    (*v_putc)()=0;
E 18
E 15
#endif
I 18
D 24
#endif
E 24
E 18

I 20
#ifndef SMALL
extern int boothowto;
int debug = 0;
#endif
E 20
I 14
int cpuspeed = 1;

E 14
E 13
E 2
configure()
{
D 24
	union cpusid cpusid;
E 24
I 3
D 13
	int nmba, nuba, i;
E 13
I 13
D 20
	register int nmba, nuba, i;
E 20
I 20
	register int i;
E 20
E 13
E 3

I 20
#ifndef SMALL
	if (boothowto & RB_KDB)		/* XXX */
		debug = 1;
#endif
E 20
D 24
	cpusid.cpusid = mfpr(SID);
	cpu = cpusid.cpuany.cp_type;
E 24
	switch (cpu) {

I 13
#if VAX8600
E 13
I 10
	case VAX_8600:
I 13
D 20
		nmba = sizeof (mbaddr780) / sizeof (mbaddr780[0]);
		nuba = sizeof (ubaddr780) / sizeof (ubaddr780[0]);
		mbaddr = mbaddr780;
		ubaddr = ubaddr780;
		uioaddr = uioaddr780;
E 20
I 20
#ifndef SMALL
		if (debug)
			printf("cpu: 8600\nsbia 0:\n");
#endif
E 20
I 14
		cpuspeed = 6;
I 20
		probenexi(NEXA8600, (caddr_t)UMEMA8600(0)+UBAIOADDR, 0);
		probenexi(NEXB8600, (caddr_t)UMEMB8600(0)+UBAIOADDR, 1);
E 20
E 14
		break;
#endif

#if VAX780
E 13
E 10
	case VAX_780:
I 13
D 20
		nmba = 4;
		nuba = 4;
E 13
		mbaddr = mbaddr780;
		ubaddr = ubaddr780;
D 2
/*###47 [cc] warning: illegal pointer combination %%%*/
E 2
D 13
		umaddr = umaddr780;
I 3
D 12
		nmba = sizeof (mbaddr780) / sizeof (mbaddr780[0]);
		nuba = sizeof (ubaddr780) / sizeof (ubaddr780[0]);
E 12
I 12
		if (cpu == VAX_8600) {
			nmba = sizeof (mbaddr780) / sizeof (mbaddr780[0]);
			nuba = sizeof (ubaddr780) / sizeof (ubaddr780[0]);
		} else {
			nmba = 4;
			nuba = 4;
E 13
I 13
		uioaddr = uioaddr780;
E 20
I 20
#ifndef SMALL
		if (debug)
			printf("cpu: 780\n");
#endif
E 20
I 14
		cpuspeed = 2;
I 20
		probenexi(NEX780, (caddr_t)UMEM780(0)+UBAIOADDR, 0);
E 20
E 14
		break;
#endif

#if VAX8200
	case VAX_8200: {
		register struct bi_node *bi;

D 20
		nmba = 0;
		nuba = 0;
E 20
I 20
		cpuspeed = 2;
E 20
		for (i = 0, bi = BI_BASE(0); i < NNODEBI; i++, bi++) {
			if (badaddr((caddr_t)bi, sizeof (long)))
				continue;
#ifdef notdef
			/* clear bus errors */
			bi->biic.bi_ber = ~(BIBER_MBZ|BIBER_NMR|BIBER_UPEN);
#endif
I 20
#ifndef SMALL
			if (debug)
				printf("node%d: ", i);
#endif
E 20
			switch (bi->biic.bi_dtype) {

			case BIDT_DWBUA:
I 23
			case BIDT_KLESI:
E 23
				if (nuba >= MAXNUBA)	/* sorry */
					break;
D 20
				ubaddr8200[nuba] = (struct uba_regs *)bi;
D 17
				uioaddr8200[nuba] = (caddr_t)UMEM8200(i);
E 17
I 17
				uioaddr8200[nuba] = (caddr_t)UMEM8200(i) +
E 20
I 20
#ifndef SMALL
				if (debug)
					printf("uba%d\n", nuba);
#endif
				ubaddrspace[nuba] = (struct uba_regs *)bi;
				uioaddrspace[nuba] = (caddr_t)UMEM8200(i) +
E 20
				    UBAIOADDR;
E 17
				((struct dwbua_regs *)bi)->bua_csr |=
				    BUACSR_UPI;
				nuba++;
				break;

			case BIDT_KDB50:
D 20
				if (nkdb < MAXNKDB)
E 20
I 20
				if (nkdb < MAXNKDB) {
E 20
					kdbaddr[nkdb++] = (caddr_t)bi;
I 20
#ifndef SMALL
					if (debug)
						printf("kdb%d\n", nkdb);
#endif
				}
E 20
				break;
I 20
#ifndef SMALL
			default:
				if (debug)
					printf("unknown type %x\n",
					    bi->biic.bi_dtype);
				break;
#endif
E 20
			}
E 13
		}
I 13
D 20
		ubaddr = ubaddr8200;
		uioaddr = uioaddr8200;
E 20
I 20
		ubaddr = ubaddrspace;
		uioaddr = uioaddrspace;
E 20
	}
E 13
E 12
E 3
		break;
I 13
#endif
E 13

I 13
#if VAX750
E 13
	case VAX_750:
I 20
#ifndef SMALL
		if (debug)
			printf("cpu: 750 -- assuming standard config\n");
#endif
E 20
		mbaddr = mbaddr750;
		ubaddr = ubaddr750;
D 2
/*###53 [cc] warning: illegal pointer combination %%%*/
E 2
D 13
		umaddr = umaddr750;
E 13
I 13
		uioaddr = uioaddr750;
E 13
I 3
		nmba = sizeof (mbaddr750) / sizeof (mbaddr750[0]);
D 20
		nuba = 0;
E 20
I 20
		nuba = 2;
E 20
E 3
I 2
		break;
I 13
#endif
E 13

I 13
#if VAX730
E 13
D 4
	case VAX_730:
		ubaddr = ubaddr730;
		umaddr = umaddr730;
E 4
I 4
D 5
	case VAX_7ZZ:
		ubaddr = ubaddr7ZZ;
		umaddr = umaddr7ZZ;
E 5
I 5
	case VAX_730:
I 20
#ifndef SMALL
		if (debug)
			printf("cpu: 730 -- assuming standard config\n");
#endif
E 20
		ubaddr = ubaddr730;
D 13
		umaddr = umaddr730;
E 5
E 4
I 3
		nmba = nuba = 0;
E 13
I 13
		uioaddr = uioaddr730;
D 20
		nmba = 0;
		nuba = 0;
E 20
I 20
		nuba = 1;
E 20
E 13
E 3
E 2
		break;
I 13
#endif

#if VAX630
	case VAX_630:
I 20
#ifndef SMALL
		if (debug)
			printf("cpu: uVAX II\n");
#endif
E 20
		ubaddr = ubaddr630;
		uioaddr = uioaddr630;
D 20
		nmba = 0;
		nuba = 0;
E 20
I 20
		nuba = 1;
E 20
		break;
#endif
I 22

#if VAX650
	case VAX_650:
#ifndef SMALL
		if (debug)
			printf("cpu: uVAX 3000\n");
#endif
		ubaddr = ubaddr630;
		uioaddr = uioaddr630;
		nuba = 1;
		break;
#endif
E 22
E 13
	}
I 13

E 13
I 3
	/*
	 * Forward into the past...
	 */
I 5
/*
E 5
	for (i = 0; i < nmba; i++)
D 12
		if (!badloc(mbaddr[i]))
E 12
I 12
		if (!badaddr(mbaddr[i], sizeof(long)))
E 12
			mbaddr[i]->mba_cr = MBCR_INIT;
I 5
*/
I 20

E 20
E 5
D 13
	for (i = 0; i < nuba; i++)
D 12
		if (!badloc(ubaddr[i]))
E 12
I 12
		if (!badaddr(ubaddr[i], sizeof(long)))
E 12
			ubaddr[i]->uba_cr = UBACR_ADINIT;
I 5
D 10
	if (cpu != VAX_780)
E 10
I 10
	if ((cpu != VAX_780) && (cpu != VAX_8600))
E 13
I 13
	switch (cpu) {

D 20
#if VAX8600 || VAX780
	case VAX_8600:
	case VAX_780:
		for (i = 0; i < nuba; i++)
			if (!badaddr(ubaddr[i], sizeof(long)))
				ubaddr[i]->uba_cr = UBACR_ADINIT;
		break;
#endif

E 20
#if VAX750 || VAX730
	case VAX_750:
	case VAX_730:
E 13
E 10
		mtpr(IUR, 0);
I 13
		break;
#endif

D 22
#if VAX630
E 22
I 22
#if VAX630 || VAX650
E 22
	case VAX_630:
I 22
	case VAX_650:
E 22
		mtpr(IUR, 0);
		*((char *)QIOPAGE630 + QIPCR) = Q_LMEAE;
I 19
D 20

E 20
D 24
#if !defined(SMALL)
		/*
		 * configure the console
		 */
		for(i = 0; vcons_init[i] && !(*vcons_init[i])(); i++)
			;
#endif
E 24
E 19
		break;
D 20
#endif
E 20
I 20
D 22
#endif /* VAX630 */
E 22
I 22
#endif
E 22
E 20
	}

E 13
E 5
	/* give unibus devices a chance to recover... */
	if (nuba > 0)
D 21
		DELAY(2000000);
E 21
I 21
		DELAY(500000);
E 21
I 15
D 18
#if VAX630
E 18
I 18
D 19

#if defined(VAX630) && !defined(SMALL)
E 18
	/*
	 * configure the console
	 */
	for(i = 0; vcons_init[i] && !(*vcons_init[i])(); i++)
		;
#endif
E 19
E 15
E 3
}
I 20

#if VAX8600 || VAX780
probenexi(nxp, umembase, sbia)
	register struct nexus *nxp;
	caddr_t umembase;
	int sbia;
{
	register int i;
	union nexcsr nexcsr;
	int first = 1;

	for (i = 0; i < 16; i++, nxp++) {
		if (badaddr(nxp, sizeof(long)))
			continue;
		nexcsr = nxp->nexcsr;
		if (nexcsr.nex_csr & NEX_APD)
			continue;
#ifndef SMALL
		if (debug) {
			if (first && sbia != 0)
				printf("sbia %d:\n", sbia);
			printf("tr%d: ", i);
			first = 0;
		}
#endif
		switch (nexcsr.nex_type) {
		default:
#ifndef SMALL
			if (debug)
				printf("nexid %2x\n", nexcsr.nex_type);
#endif
			break;

		case NEX_MEM4:
		case NEX_MEM4I:
		case NEX_MEM16:
		case NEX_MEM16I:
		case NEX_MEM64L:
		case NEX_MEM64LI:
		case NEX_MEM64U:
		case NEX_MEM64UI:
		case NEX_MEM64I:
#ifndef SMALL
			if (debug)
				printf("mem\n");
#endif
			break;

		case NEX_CI:
#ifndef SMALL
			if (debug)
				printf("ci\n");
#endif
			break;

		case NEX_DR32:
#ifndef SMALL
			if (debug)
				printf("dr32\n");
#endif
			break;

		case NEX_MPM0:
		case NEX_MPM1:
		case NEX_MPM2:
		case NEX_MPM3:
#ifndef SMALL
			if (debug)
				printf("mpm\n");
#endif
			break;

		case NEX_MBA:
			if (nmba >= MAXNMBA) {
#ifndef SMALL
				if (debug)
					printf("unsupported mba\n");
#endif
				break;
			}
#ifndef SMALL
			if (debug)
				printf("mba%d\n", nmba);
#endif
			mbaddrspace[nmba] = (struct mba_regs *)nxp;
			nmba++;
			break;

		case NEX_UBA0:
		case NEX_UBA1:
		case NEX_UBA2:
		case NEX_UBA3:
			if (nuba >= MAXNUBA) {
#ifndef SMALL
				if (debug)
					printf("unsupported uba\n");
#endif
				break;
			}
#ifndef SMALL
			if (debug)
				printf("uba%d umem%d", nuba,
				    nexcsr.nex_type&3);
#endif
			ubaddrspace[nuba] = (struct uba_regs *)nxp;
			uioaddrspace[nuba] = umembase +
			    (nexcsr.nex_csr & 3) * (512*NBPG);
#ifndef SMALL
			if (debug)
				printf(" (%x)\n", uioaddrspace[nuba]);
#endif
			nuba++;
			((struct uba_regs *)nxp)->uba_cr = UBACR_ADINIT;
			break;
		}
	}
	mbaddr = mbaddrspace;
	ubaddr = ubaddrspace;
	uioaddr = uioaddrspace;
#undef	UTR
#undef	UMA
#undef	MTR
}
#endif /* VAX780 || VAX8600 */
E 20
E 1
