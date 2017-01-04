/*
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)cpu.h	7.12 (Berkeley) 3/19/04
 */

#ifndef LOCORE
/*
 * Cpu identification, from SID register.
 */
union cpusid {
	int	cpusid;
	struct cpuany {
		u_int	:24,
			cp_type:8;
	} cpuany;
	struct cpu8600 {
		u_int	cp_sno:12,		/* serial number */
			cp_plant:4,		/* plant number */
			cp_eco:8,		/* eco level */
			cp_type:8;		/* VAX_8600 */
	} cpu8600;
	struct cpu8200 {
		u_int	cp_urev:8,		/* ucode rev */
			cp_secp:1,		/* secondary patch? */
			cp_patch:10,		/* patch number */
			cp_hrev:4,		/* hardware rev */
			cp_5:1,			/* true iff KA825 */
			cp_type:8;		/* VAX_8200 */
	} cpu8200;
	struct cpu780 {
		u_int	cp_sno:12,		/* serial number */
			cp_plant:3,		/* plant number */
			cp_eco:8,		/* eco level */
			cp_5:1,			/* true iff 785 */
			cp_type:8;		/* VAX_780 */
	} cpu780;
	struct cpu750 {
		u_int	cp_hrev:8,		/* hardware rev level */
			cp_urev:8,		/* ucode rev level */
			:8,
			cp_type:8;		/* VAX_750 */
	} cpu750;
	struct cpu730 {
		u_int	:8,			/* reserved */
			cp_urev:8,		/* ucode rev level */
			:8,			/* reserved */
			cp_type:8;		/* VAX_730 */
	} cpu730;
	struct cpu_cvax {
		u_int	cp_urev:8,		/* ucode rev level */
			:16,			/* reserved */
			cp_type:8;		/* SID_CPUTYPE_CVAX */
	} cpu_cvax;
};
#endif
/*
 * Values for cp_type field above, assigned by
 * DEC Assigned Number Authority
 */
#define	SID_CPUTYPE_780		0x01
#define	SID_CPUTYPE_750		0x02
#define	SID_CPUTYPE_730		0x03
#define	SID_CPUTYPE_8600	0x04
#define	SID_CPUTYPE_8200	0x05	/* 8200/8300 */
#define	SID_CPUTYPE_8800	0x06	/* 8500/8700/8800 */
#define	SID_CPUTYPE_UV1		0x07
#define	SID_CPUTYPE_UV2		0x08
#define	SID_CPUTYPE_VVAX	0x09	/* Virtual VAX */
#define	SID_CPUTYPE_CVAX	0x0A
#define	SID_CPUTYPE_RIGEL	0x0B
#define	SID_CPUTYPE_9000	0x0E
#define	SID_CPUTYPE_78R32	0x10	/* rtVAX can't run UNIX or VMS */
#define	SID_CPUTYPE_POLARSTAR	0x11	/* 8800 Polarstar */
#define	SID_CPUTYPE_MARIAH	0x12
#define	SID_CPUTYPE_NVAX	0x13
#define	SID_CPUTYPE_SOC		0x14

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

/*
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
#define	VAX_410		0x09	/* KA410 MV/VS2000 (but not KA41!) */
#define	VAX_650		0x0A	/* KA650 family */
#define	VAX_3100	0x0B	/* VS3100 (KA42) and early MV3100s (KA41) */

#define	VAX_MAX		0x0B

/*
 * Main IO backplane types.
 * This gives us a handle on how to do autoconfiguration.
 */
#define	IO_SBI780	1
#define	IO_CMI750	2
#define	IO_XXX730	3
#define IO_ABUS		4
#define IO_QBUS		5
#define	IO_BI		6
#define	IO_NMI		7
#define	IO_XMI		8
#define	IO_BABYVAX	9

#ifndef LOCORE
/*
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
 * Per-cpu information for system.
 */
struct	percpu {
	short	pc_cputype;		/* cpu type code */
	short	pc_cpuspeed;		/* relative speed of cpu */
	short	pc_compatmode;		/* has compatibility mode */
	short	pc_nioa;		/* number of IO adaptors/nexus blocks */
	struct	iobus *pc_io;		/* descriptions of IO adaptors */
	struct	cpuops *pc_ops;		/* per-cpu operations */
};

/*
 * Generic description of an I/O "adaptor"
 * (any top-level I/O bus visible to software
 * and requiring autoconfiguration).
 * The remainder of the description
 * is pointed to by io_details.
 */
struct iobus {
	int	io_type;		/* io adaptor types */
	caddr_t	io_addr;		/* phys address of IO adaptor */
	int	io_size;		/* size of an IO space */
	caddr_t	io_details;		/* specific to adaptor types */
};

/*
 * Description of a main bus that maps "nexi", ala the 780 SBI.
 */
struct nexusconnect {
	short	psb_nnexus;		/* number of nexus slots */
	struct	nexus *psb_nexbase;	/* base of nexus space */
	short	psb_ubatype;		/* type of "unibus adaptor" */
	short	psb_nubabdp;		/* number of bdp's per uba */
	caddr_t	*psb_umaddr;		/* unibus memory addresses */
/* the 750 has some slots which don't promise to tell you their types */
/* if this pointer is non-zero, then you get the type from this array */
/* rather than from the (much more sensible) low byte of the config register */
	short	*psb_nextype;		/* botch */
};

/*
 * Description of a Q-bus configuration.
 */
struct qbus {
	int	qb_type;		/* type of "unibus adaptor" */
	int	qb_memsize;		/* size of (used) memory, pages */
	struct	pte *qb_map;		/* base of map registers */
	caddr_t	qb_maddr;		/* "unibus" memory address */
	caddr_t	qb_iopage;		/* "unibus" IO page address */
};

#ifdef KERNEL
int	cpu;
union	cpusid cpusid;
union	cpusie cpusie;
#if VAX8800 || VAX8200
int	mastercpu;		/* if multiple cpus, this identifies master */
#endif
struct	percpu percpu[];
struct	cpuops *cpuops;
int	cpu_has_compat_mode;
#endif

/*
 * Enable realtime clock (always enabled).
 */
#define	enablertclock()
#endif /* LOCORE */
