h38423
s 00003/00001/00048
d D 7.5 88/07/09 14:40:03 karels 13 12
c check adaptor numbers against actual number
e
s 00022/00031/00027
d D 7.4 88/03/04 13:35:35 bostic 12 11
c handle x(adapt, ctrl, unit, part) format; move stuff to ../stand
e
s 00010/00003/00048
d D 7.3 88/01/28 20:53:17 karels 11 10
c uvax changes; fix devsw index in confxx; header updates
e
s 00004/00008/00047
d D 7.2 87/02/21 11:41:42 karels 10 9
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00054
d D 7.1 86/06/05 01:45:03 mckusick 9 8
c 4.3BSD release version
e
s 00008/00000/00047
d D 6.4 85/11/08 19:15:57 karels 8 7
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00007/00001/00040
d D 6.3 85/06/08 13:11:55 mckusick 7 6
c Add copyright
e
s 00001/00000/00040
d D 6.2 84/08/07 12:47:48 karels 6 5
c MAXNUBA not defined by system headers now
e
s 00000/00000/00040
d D 6.1 83/07/29 07:47:39 sam 5 4
c 4.2 distribution
e
s 00005/00000/00035
d D 4.4 83/03/01 22:41:13 sam 4 3
c add stuff from saio.h
e
s 00001/00001/00034
d D 4.3 82/07/15 21:31:53 root 3 2
c new boot scheme
e
s 00001/00002/00034
d D 4.2 81/03/16 00:54:39 wnj 2 1
c fixes for generic functionality
e
s 00036/00000/00000
d D 4.1 81/03/15 20:49:50 wnj 1 0
c date and time created 81/03/15 20:49:50 by wnj
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
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
D 12
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 12
I 12
D 13
 * Copyright (c) 1982, 1986, 1988, Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 13
E 12
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

/*
D 12
 * Standalone definitions peculiar to vaxen
 * The mba devices in the standalone system are addressed as 
 *	xx(unit,section)
 * where unit is
 *	8*mbanum+drive
E 12
I 12
 * Standalone definitions peculiar to vaxen:
 *
 * The mba devices in the standalone system are addressed as
 *	type(mba, 0, drive, partition)		(disks)
 *	type(mba, formatter, transport, file)	(tapes)
 *
E 12
 * The mbadrv macro gives the address of the device registers
D 12
 * for the specified unit; the mbamba macro gives the address of the
 * mba registers themselves.
E 12
I 12
 * for the specified unit.
E 12
 *
D 12
 * The uba devices are also addressed by giving, as unit,
 *	8*ubanum+drive
E 12
I 12
 * The uba devices in the standalone system are addressed as
 *	type(uba, ctlr, drive, partition)	(disks)
 *	type(uba, formatter, transport, file)	(tapes)
 *
E 12
 * The ubamem macro converts a specified unibus address (ala pdp-11)
 * into a unibus memory address space address.
 */

D 12
int	cpu;		/* see <sys/cpu.h> */
E 12
I 12
#define	mbadrv(mba, unit) 	(&mbamba(mba)->mba_drv[unit])
/* compute an I/O page physical address from a 16/18/22-bit bus address */
#define	ubamem(uba, off)	(uioaddr[uba] + ubdevreg(off))
E 12

I 12
#define	mbamba(mba)		(mbaddr[mba])
#define	ubauba(uba)		(ubaddr[uba])

E 12
D 10
#define	MAXNMBA	4
I 6
#define	MAXNUBA	4
E 10
I 10
#define	MAXNMBA	8
#define	MAXNUBA	8
I 11
D 12
#define	MAXNKDB 2
E 12
I 12
#define	MAXNKDB	2

E 12
E 11
E 10
E 6
struct	mba_regs **mbaddr;
int	mbaact;
I 13
int	nmba;
E 13
I 12

E 12
D 11
caddr_t	*umaddr;
E 11
I 11
caddr_t	*uioaddr;
E 11
struct	uba_regs **ubaddr;
I 13
int	nuba;
E 13

I 11
#ifdef VAX8200
caddr_t	kdbaddr[MAXNKDB];
int	nkdb;
#endif

E 11
D 12
#define	UNITTOMBA(unit)		((unit)>>3)
#define	UNITTODRIVE(unit)	((unit)&07)

#define	mbamba(unit)		(mbaddr[UNITTOMBA(unit)])
#define	mbadrv(unit) 		(&mbamba(unit)->mba_drv[UNITTODRIVE(unit)])

#define	UNITTOUBA(unit)		((unit)>>3)
#define	ubauba(unit)		(ubaddr[UNITTOUBA(unit)])
D 2
#define	ubamem(unit, off)	\
	((struct device *)(umaddr[UNITTOUBA(unit)]+(off&017777)))
E 2
I 2
D 3
#define	ubamem(unit, off)	((umaddr[UNITTOUBA(unit)]+(off&017777)))
E 3
I 3
D 10
#define	ubamem(unit, off)	((umaddr[UNITTOUBA(unit)]+ubdevreg(off)))
I 4

#define	PHYSUBA0	0x20006000
#define	PHYSMBA0	0x20010000
#define	PHYSMBA1	0x20012000
#define	PHYSUMEM	0x2013e000
E 10
I 10
D 11
#define	ubamem(unit, off)	(umaddr[UNITTOUBA(unit)] + \
					(0760000 | ubdevreg(off)))
E 11
I 11

/* compute an I/O page physical address from a 16/18/22-bit bus address */
#define	ubamem(unit, off)	(uioaddr[UNITTOUBA(unit)] + ubdevreg(off))
E 11
E 10
I 8

/*
 * RM03/5 (4-byte header plus CRC) format information:
 * codes for sector header word 1
 */
#define	HDR1_FMT22	0x1000	/* standard 16 bit format */
#define	HDR1_OKSCT	0xc000	/* sector ok */
#define	HDR1_SSF	0x2000	/* skip sector flag */
E 12
I 12
int	cpu;				/* see ../vax/cpu.h */
E 12
E 8
E 4
E 3
E 2
E 1
