h34890
s 00002/00000/00245
d D 7.12 04/03/19 17:45:52 msokolov 27 26
c add definitions for VVAX and 78R32 SID codes for completeness
e
s 00004/00001/00241
d D 7.11 04/03/18 19:19:11 msokolov 26 25
c add BabyVAX support (beginnings thereof)
c a few other todo closures and fixes along the way
e
s 00001/00008/00241
d D 7.10 04/03/06 01:50:57 msokolov 25 24
c start knocking some sanity into VAXBI support
e
s 00000/00006/00249
d D 7.9 04/02/06 21:59:04 msokolov 24 23
c contrary to BSD and Ultrix cpu.h files MicroVAX II SID does NOT have
c hardware rev or ucode rev fields
e
s 00084/00019/00171
d D 7.8 04/01/03 18:07:34 msokolov 23 22
c new CPU ID logic
e
s 00002/00000/00188
d D 7.7 03/05/03 13:30:26 msokolov 22 21
c teach the kernel which CPUs have compatibility mode and which don't
e
s 00007/00001/00181
d D 7.6 88/08/27 07:00:54 tef 21 20
c Add support for microvax 3000.
e
s 00006/00003/00176
d D 7.5 88/07/09 13:58:36 karels 20 19
c update copyright, update 630 SID def
e
s 00053/00005/00126
d D 7.4 88/05/07 14:19:22 karels 19 18
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00005/00000/00126
d D 7.3 86/12/06 22:33:10 sam 18 17
c define null enablertclock
e
s 00020/00005/00106
d D 7.2 86/08/09 15:09:21 karels 17 16
c generalize uba code to handle Q bus more gracefully
e
s 00001/00001/00110
d D 7.1 86/06/05 00:42:20 mckusick 16 15
c 4.3BSD release version
e
s 00007/00001/00104
d D 6.8 86/04/22 10:49:43 kridle 15 14
c Added MicroVAX II Support (KA630)
e
s 00001/00001/00104
d D 6.7 86/03/29 23:06:37 karels 14 13
c touchups
e
s 00026/00017/00079
d D 6.6 86/02/23 23:05:36 karels 13 12
c rework data structures to be more flexible about I/O buses
e
s 00002/00001/00094
d D 6.5 85/09/17 23:05:08 karels 12 11
c add cpuspeed variable to adjust delay macro
e
s 00033/00007/00062
d D 6.4 85/08/05 18:06:53 bloom 11 10
c add support for 8600
e
s 00006/00001/00063
d D 6.3 85/08/05 18:05:29 bloom 10 9
c add definitions for 730 SID
e
s 00007/00001/00057
d D 6.2 85/06/08 13:41:10 mckusick 9 8
c Add copyright
e
s 00000/00000/00058
d D 6.1 83/07/29 07:19:38 sam 8 7
c 4.2 distribution
e
s 00002/00002/00056
d D 4.7 82/05/26 15:35:39 sam 7 6
c 7ZZ -> 730
e
s 00002/00002/00056
d D 4.6 81/04/03 00:09:32 root 6 5
c s/730/7ZZ
e
s 00003/00001/00055
d D 4.5 81/03/21 16:13:07 wnj 5 4
c 730 changes
e
s 00014/00002/00042
d D 4.4 81/03/13 21:49:26 wnj 4 3
c larger percpu structure
e
s 00004/00000/00040
d D 4.3 81/02/26 04:30:23 wnj 3 2
c cosmetics
e
s 00000/00000/00040
d D 4.2 81/02/19 21:39:55 wnj 2 1
c %G%->%E%
e
s 00040/00000/00000
d D 4.1 81/02/19 21:34:07 wnj 1 0
c date and time created 81/02/19 21:34:07 by wnj
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
D 16
 * Copyright (c) 1982 Regents of the University of California.
E 16
I 16
D 20
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 20
E 16
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9

I 3
#ifndef LOCORE
E 3
/*
 * Cpu identification, from SID register.
 */
union cpusid {
	int	cpusid;
	struct cpuany {
		u_int	:24,
			cp_type:8;
	} cpuany;
I 11
	struct cpu8600 {
		u_int	cp_sno:12,		/* serial number */
			cp_plant:4,		/* plant number */
			cp_eco:8,		/* eco level */
			cp_type:8;		/* VAX_8600 */
	} cpu8600;
I 19
	struct cpu8200 {
		u_int	cp_urev:8,		/* ucode rev */
			cp_secp:1,		/* secondary patch? */
			cp_patch:10,		/* patch number */
			cp_hrev:4,		/* hardware rev */
			cp_5:1,			/* true iff KA825 */
			cp_type:8;		/* VAX_8200 */
	} cpu8200;
E 19
E 11
	struct cpu780 {
		u_int	cp_sno:12,		/* serial number */
			cp_plant:3,		/* plant number */
D 19
			cp_eco:9,		/* eco level */
E 19
I 19
			cp_eco:8,		/* eco level */
			cp_5:1,			/* true iff 785 */
E 19
			cp_type:8;		/* VAX_780 */
	} cpu780;
	struct cpu750 {
		u_int	cp_hrev:8,		/* hardware rev level */
			cp_urev:8,		/* ucode rev level */
			:8,
			cp_type:8;		/* VAX_750 */
	} cpu750;
I 5
D 6
	/* need structure for 730 */
E 6
I 6
D 7
	/* need structure for 7ZZ */
E 7
I 7
D 10
	/* need structure for 730 */
E 10
I 10
	struct cpu730 {
		u_int	:8,			/* reserved */
			cp_urev:8,		/* ucode rev level */
			:8,			/* reserved */
			cp_type:8;		/* VAX_730 */
	} cpu730;
I 15
D 23
 	struct cpu630 {
E 23
I 23
D 24
	struct cpu_uv2 {
E 23
D 20
 		u_int	:24,			/* reserved */
E 20
I 20
		u_int	cp_hrev:8,		/* hardware rev level */
			cp_urev:8,		/* ucode rev level */
			:8,
E 20
D 23
 			cp_type:8;		/* VAX_630 */
 	} cpu630;
I 21
	struct cpu650 {
E 23
I 23
			cp_type:8;		/* SID_CPUTYPE_UV2 */
	} cpu_uv2;
E 24
	struct cpu_cvax {
E 23
		u_int	cp_urev:8,		/* ucode rev level */
			:16,			/* reserved */
D 23
			cp_type:8;		/* VAX_650 */
	} cpu650;
E 23
I 23
			cp_type:8;		/* SID_CPUTYPE_CVAX */
	} cpu_cvax;
E 23
E 21
E 15
E 10
E 7
E 6
E 5
};
I 3
#endif
I 13
/*
D 23
 * Vax CPU types.
 * Similar types are grouped with their earliest example.
E 23
I 23
 * Values for cp_type field above, assigned by
 * DEC Assigned Number Authority
E 23
 */
E 13
E 3
D 23
#define	VAX_780		1
#define	VAX_750		2
I 5
D 6
#define	VAX_730		3
E 6
I 6
D 7
#define	VAX_7ZZ		3
E 7
I 7
#define	VAX_730		3
I 11
D 19
#define VAX_8600	4
I 15
#define	VAX_630		8
E 19
I 19
#define	VAX_8600	4
#define	VAX_8200	5
D 20
#define	VAX_8800	6	/* not positive */
E 20
I 20
#define	VAX_8800	6
E 20
#define	VAX_8500	6	/* same as 8800, 8700 */
#define	VAX_610		7	/* uVAX I */
#define	VAX_630		8	/* uVAX II */
I 21
#define	VAX_650		10	/* uVAX 3000 */
E 23
I 23
#define	SID_CPUTYPE_780		0x01
#define	SID_CPUTYPE_750		0x02
#define	SID_CPUTYPE_730		0x03
#define	SID_CPUTYPE_8600	0x04
#define	SID_CPUTYPE_8200	0x05	/* 8200/8300 */
#define	SID_CPUTYPE_8800	0x06	/* 8500/8700/8800 */
#define	SID_CPUTYPE_UV1		0x07
#define	SID_CPUTYPE_UV2		0x08
I 27
#define	SID_CPUTYPE_VVAX	0x09	/* Virtual VAX */
E 27
#define	SID_CPUTYPE_CVAX	0x0A
#define	SID_CPUTYPE_RIGEL	0x0B
#define	SID_CPUTYPE_9000	0x0E
I 27
#define	SID_CPUTYPE_78R32	0x10	/* rtVAX can't run UNIX or VMS */
E 27
#define	SID_CPUTYPE_POLARSTAR	0x11	/* 8800 Polarstar */
#define	SID_CPUTYPE_MARIAH	0x12
#define	SID_CPUTYPE_NVAX	0x13
#define	SID_CPUTYPE_SOC		0x14
E 23
E 21
E 19
E 15
E 11
E 7
E 6
E 5

D 5
#define	VAX_MAX		2
E 5
I 5
D 11
#define	VAX_MAX		3
E 11
I 11
D 15
#define	VAX_MAX		4
E 15
I 15
D 21
#define	VAX_MAX		8
E 21
I 21
D 23
#define	VAX_MAX		10
E 23
I 23
/*
 * Newer systems have, in addition to SID, a System ID Extension (SIE) longword
 * which describes the system rather than the CPU.  It is the second longword
 * of the firmware ROM.
 */
#ifndef LOCORE
union cpusie {
	int	cpusie;
	struct sysany {
		u_int	:24,
			sys_type:8;
	} sysany;
	struct sys6xx {
		u_int	sys_license:8,		/* DEC license crap */
			sys_subtype:8,		/* which KA6xx board */
			sys_version:8,		/* system ROM version */
			sys_type:8;		/* SIE_SYSTYPE_QBUS */
	} sys6xx;
};
#endif
/*
 * Values for sys_type field above, assigned by
 * DEC Assigned Number Authority
 */
#define	SIE_SYSTYPE_QBUS	0x01
#define	SIE_SYSTYPE_XMI		0x02
#define	SIE_SYSTYPE_FIREFOX	0x03
#define	SIE_SYSTYPE_BABYVAX	0x04
/*
 * KA650 and later boards sys_subtype codes
 */
#define	SIE_SYSSUBTYPE_KA650	0x01
#define	SIE_SYSSUBTYPE_KA640	0x02
#define	SIE_SYSSUBTYPE_KA655	0x03
#define	SIE_SYSSUBTYPE_KA670	0x04
#define	SIE_SYSSUBTYPE_KA660	0x05
E 23
E 21
E 15
E 11
E 5

I 13
/*
I 23
 * VAX CPU types.
 *
 * Unfortunately with the introduction of integrated circuit VAX CPUs DEC broke
 * the rule that each VAX was identified by a unique code in the top byte of
 * SID register.  Therefore, if we want a single number to identify what VAX it
 * is, we have to invent our own VAX CPU ID codes which do NOT come from DEC.
 *
 * These codes are defined below.  They match DEC CPUTYPE codes for machines
 * supported by 4.3-Quasijarus0, but not necessarily so for new machines.
 */
#define	VAX_780		0x01
#define	VAX_750		0x02
#define	VAX_730		0x03
#define	VAX_8600	0x04
#define	VAX_8200	0x05	/* 8200/8300 */
#define	VAX_8800	0x06	/* 8500/8700/8800 */
#define	VAX_610		0x07	/* KA610 MicroVAX I */
#define	VAX_630		0x08	/* KA630 MicroVAX II */
I 26
#define	VAX_410		0x09	/* KA410 MV/VS2000 (but not KA41!) */
E 26
#define	VAX_650		0x0A	/* KA650 family */
I 26
#define	VAX_3100	0x0B	/* VS3100 (KA42) and early MV3100s (KA41) */
E 26

D 26
#define	VAX_MAX		0x0A
E 26
I 26
#define	VAX_MAX		0x0B
E 26

/*
E 23
 * Main IO backplane types.
 * This gives us a handle on how to do autoconfiguration.
 */
#define	IO_SBI780	1
#define	IO_CMI750	2
#define	IO_XXX730	3
#define IO_ABUS		4
I 15
#define IO_QBUS		5
I 19
#define	IO_BI		6
I 20
#define	IO_NMI		7
I 25
#define	IO_XMI		8
I 26
#define	IO_BABYVAX	9
E 26
E 25
E 20
E 19
E 15

E 13
I 3
#ifndef LOCORE
E 3
/*
I 19
 * CPU-dependent operations.
 */
struct	clockops {
	int	(*clkstartrt)();	/* start real time clock */
	int	(*clkread)();		/* set system time from clock */
	int	(*clkwrite)();		/* reset clock from system time */
};

struct	cpuops {
	struct	clockops *cpu_clock;	/* clock operations */
	int	(*cpu_memenable)();	/* memory error (CRD intr) enable */
	int	(*cpu_memerr)();	/* memory error handler */
	int	(*cpu_mchk)();		/* machine check handler */
	int	(*cpu_init)();		/* special initialisation, if any */
};

/* return values from cpu_mchk */
#define	MCHK_PANIC	-1
#define	MCHK_RECOVERED	0

/*
E 19
 * Per-cpu information for system.
 */
struct	percpu {
D 4
	int	(*pc_config)();
	short	pc_cputype;
E 4
I 4
	short	pc_cputype;		/* cpu type code */
I 12
	short	pc_cpuspeed;		/* relative speed of cpu */
I 22
	short	pc_compatmode;		/* has compatibility mode */
E 22
E 12
D 11
	short	pc_nnexus;		/* number of nexus slots */
	struct	nexus *pc_nexbase;	/* base of nexus space */
E 11
I 11
D 13
	short	pc_nioa;		/* number of IO adaptors/SBI's */
	caddr_t	*pc_ioaaddr;		/* phys addresses of IO adaptors */
D 12
	int	pc_ioasize;		/* size of a IO adaptor */
E 12
I 12
	int	pc_ioasize;		/* size of an IO adaptor */
E 12
	short	*pc_ioatype;		/* io adaptor types if no cfg reg */
E 13
I 13
	short	pc_nioa;		/* number of IO adaptors/nexus blocks */
	struct	iobus *pc_io;		/* descriptions of IO adaptors */
I 19
	struct	cpuops *pc_ops;		/* per-cpu operations */
E 19
E 13
};

I 17
/*
 * Generic description of an I/O "adaptor"
 * (any top-level I/O bus visible to software
 * and requiring autoconfiguration).
 * The remainder of the description
 * is pointed to by io_details.
 */
E 17
D 13
struct persbi {
E 13
I 13
struct iobus {
I 14
	int	io_type;		/* io adaptor types */
E 14
	caddr_t	io_addr;		/* phys address of IO adaptor */
	int	io_size;		/* size of an IO space */
D 14
	short	io_type;		/* io adaptor types if no cfg reg */
E 14
	caddr_t	io_details;		/* specific to adaptor types */
};

/*
 * Description of a main bus that maps "nexi", ala the 780 SBI.
 */
struct nexusconnect {
E 13
	short	psb_nnexus;		/* number of nexus slots */
	struct	nexus *psb_nexbase;	/* base of nexus space */
E 11
D 17
/* we should be able to have just one address for the unibus memories */
/* and calculate successive addresses by adding to the base, but the 750 */
/* doesn't obey the sensible rule: uba1 has a lower address than uba0! */
D 11
	caddr_t	*pc_umaddr;		/* unibus memory addresses */
	short	pc_nubabdp;		/* number of bdp's per uba */
	short	pc_haveubasr;		/* have uba status register */
E 11
I 11
	caddr_t	*psb_umaddr;		/* unibus memory addresses */
E 17
I 17
	short	psb_ubatype;		/* type of "unibus adaptor" */
E 17
	short	psb_nubabdp;		/* number of bdp's per uba */
D 17
	short	psb_haveubasr;		/* have uba status register */
E 17
I 17
D 19
	caddr_t	*psb_umaddr;		/* "unibus" memory addresses */
E 19
I 19
	caddr_t	*psb_umaddr;		/* unibus memory addresses */
E 19
E 17
E 11
/* the 750 has some slots which don't promise to tell you their types */
/* if this pointer is non-zero, then you get the type from this array */
/* rather than from the (much more sensible) low byte of the config register */
D 11
	short	*pc_nextype;		/* botch */
E 11
I 11
	short	*psb_nextype;		/* botch */
I 17
D 25
};

/*
I 19
 * Description of a BI bus configuration.
 */
struct bibus {
	struct	bi_node *pbi_base;	/* base of node space */
	/* that cannot possibly be all! */
E 25
};

/*
E 19
 * Description of a Q-bus configuration.
 */
struct qbus {
	int	qb_type;		/* type of "unibus adaptor" */
	int	qb_memsize;		/* size of (used) memory, pages */
	struct	pte *qb_map;		/* base of map registers */
	caddr_t	qb_maddr;		/* "unibus" memory address */
	caddr_t	qb_iopage;		/* "unibus" IO page address */
E 17
E 11
E 4
};

#ifdef KERNEL
int	cpu;
I 23
union	cpusid cpusid;
union	cpusie cpusie;
E 23
I 19
#if VAX8800 || VAX8200
int	mastercpu;		/* if multiple cpus, this identifies master */
#endif
E 19
I 4
struct	percpu percpu[];
I 19
struct	cpuops *cpuops;
I 22
int	cpu_has_compat_mode;
E 22
E 19
I 11
D 13
#if VAX730
struct persbi xxx730;
#endif
#if VAX750
struct persbi cmi750;
#endif
#if VAX780
struct persbi sbi780;
#endif
#if VAX8600
struct persbi sbi8600[];
#endif
E 13
E 11
E 4
I 3
#endif
I 18

/*
 * Enable realtime clock (always enabled).
 */
#define	enablertclock()
E 18
E 3
D 19
#endif
E 19
I 19
#endif /* LOCORE */
E 19
E 1
