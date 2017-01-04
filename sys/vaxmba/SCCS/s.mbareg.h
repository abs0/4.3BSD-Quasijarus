h64450
s 00001/00001/00134
d D 7.1 86/06/05 01:31:34 mckusick 25 24
c 4.3BSD release version
e
s 00007/00001/00128
d D 6.2 85/06/08 14:08:28 mckusick 24 23
c Add copyright
e
s 00000/00000/00129
d D 6.1 83/07/29 07:35:04 sam 23 22
c 4.2 distribution
e
s 00001/00000/00128
d D 4.17 82/05/20 15:07:26 sam 22 21
c si and capricorn kludges
e
s 00003/00001/00125
d D 4.16 82/02/08 22:51:46 root 21 20
c ML11 definitions
e
s 00001/00001/00125
d D 4.15 81/05/03 18:58:36 wnj 20 19
c fix MBDT_TU78 per shannon
e
s 00040/00036/00086
d D 4.14 81/03/09 00:27:05 wnj 19 18
c lint
e
s 00001/00097/00121
d D 4.13 81/03/08 16:16:20 wnj 18 17
c split header files in 2 and rename structures for sanity
e
s 00004/00000/00214
d D 4.12 81/03/03 12:39:00 wnj 17 16
c add MBASR_HARD
e
s 00002/00001/00212
d D 4.11 81/02/26 23:19:50 wnj 16 15
c formatting
e
s 00002/00000/00211
d D 4.10 81/02/26 22:07:12 wnj 15 14
c fixes for 750/780
e
s 00005/00000/00206
d D 4.9 81/02/25 23:29:49 wnj 14 13
c functional version with %b printf, etc
e
s 00001/00001/00205
d D 4.8 81/02/21 21:29:38 wnj 13 12
c misc changes for first working interlockable version
e
s 00001/00001/00205
d D 4.7 81/02/19 21:41:06 wnj 12 11
c %G%->%E%
e
s 00010/00005/00196
d D 4.6 81/02/19 21:30:08 wnj 11 10
c added defs removed from autoconf.c
e
s 00001/00000/00200
d D 4.5 81/02/15 12:14:10 wnj 10 9
c bootable autoconf version
e
s 00158/00061/00042
d D 4.4 81/02/08 18:38:17 wnj 9 8
c new mba.h, all nice and pretty
e
s 00059/00002/00044
d D 4.3 81/02/03 23:09:43 wnj 8 7
c added some more defs (still pre autoconfig
e
s 00002/00000/00044
d D 4.2 80/12/17 11:46:08 wnj 7 6
c combined 750/780
e
s 00000/00000/00044
d D 4.1 80/11/09 17:01:12 bill 6 5
c stamp for 4bsd
e
s 00004/00004/00040
d D 3.5 80/10/09 00:07:25 bill 5 4
c minor typos
e
s 00024/00014/00020
d D 3.4 80/08/08 23:21:44 bill 4 3
c uses types now
e
s 00001/00001/00033
d D 3.3 80/06/07 02:58:28 bill 3 2
c %H%->%G%
e
s 00002/00003/00032
d D 3.2 80/04/11 10:20:31 bill 2 1
c 6pages kmap
e
s 00035/00000/00000
d D 3.1 80/04/09 16:24:15 bill 1 0
c date and time created 80/04/09 16:24:15 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%H%	*/
E 3
I 3
D 12
/*	%M%	%I%	%G%	*/
E 12
I 12
D 24
/*	%M%	%I%	%E%	*/
E 24
I 24
/*
D 25
 * Copyright (c) 1982 Regents of the University of California.
E 25
I 25
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 25
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 24
E 12
E 3

I 7
D 9
#if VAX==780
E 9
E 7
/*
D 18
 * VAX Massbus adapter registers
E 18
I 18
 * VAX MASSBUS adapter registers
E 18
 */

I 8
D 9
struct mba_drv
E 9
I 9
struct mba_regs
E 9
{
D 9
	int	mbd_cs1;
	int	mbd_ds;
	int	mbd_er1;
	int	mbd_mr1;
	int	mbd_as;
	int	mbd_da;
#define	mbd_fc	mbd_da
	int	mbd_dt;
	int	mbd_la;
#define	mbd_ck	mbd_la
	int	mbd_sn;
	int	mbd_of;
#define	mbd_tc	mbd_of
	int	mbd_fill[22];
E 9
I 9
	int	mba_csr;		/* configuration register */
	int	mba_cr;			/* control register */
	int	mba_sr;			/* status register */
	int	mba_var;		/* virtual address register */
	int	mba_bcr;		/* byte count register */
	int	mba_dr;
	int	mba_pad1[250];
	struct mba_drv {		/* per drive registers */
		int	mbd_cs1;		/* control status */
		int	mbd_ds;			/* drive status */
		int	mbd_er1;		/* error register */
		int	mbd_mr1;		/* maintenance register */
		int	mbd_as;			/* attention status */
		int	mbd_da;			/* desired address (disks) */
#define	mbd_fc	mbd_da				/* frame count (tapes) */
		int	mbd_dt;			/* drive type */
		int	mbd_la;			/* look ahead (disks) */
#define	mbd_ck	mbd_la				/* ??? (tapes) */
		int	mbd_sn;			/* serial number */
		int	mbd_of;			/* ??? */
#define	mbd_tc	mbd_of				/* ??? */
		int	mbd_fill[22];
	} mba_drv[8];
	struct	pte mba_map[256];	/* io space virtual map */
	int	mba_pad2[256*5];	/* to size of a nexus */
E 9
};
I 9

E 9
/*
D 9
 * Bits in mbd_dt.
E 9
I 9
 * Bits in mba_cr
E 9
 */
I 9
D 19
#define	MBAINIT		0x1		/* init mba */
#define	MBAIE		0x4		/* enable mba interrupts */
E 19
I 19
#define	MBCR_INIT	0x1		/* init mba */
#define	MBCR_IE		0x4		/* enable mba interrupts */
E 19

/*
 * Bits in mba_sr
 */
D 19
#define	MBS_DTBUSY	0x80000000	/* data transfer busy */
#define	MBS_NRCONF	0x40000000	/* no response confirmation */
#define	MBS_CRD		0x20000000	/* corrected read data */
#define	MBS_CBHUNG	0x00800000	/* control bus hung */
#define	MBS_PGE		0x00080000	/* programming error */
#define	MBS_NED		0x00040000	/* non-existant drive */
#define	MBS_MCPE	0x00020000	/* massbus control parity error */
#define	MBS_ATTN	0x00010000	/* attention from massbus */
#define	MBS_SPE		0x00004000	/* silo parity error */
#define	MBS_DTCMP	0x00002000	/* data transfer completed */
#define	MBS_DTABT	0x00001000	/* data transfer aborted */
#define	MBS_DLT		0x00000800	/* data late */
#define	MBS_WCKUP	0x00000400	/* write check upper */
#define	MBS_WCKLWR	0x00000200	/* write check lower */
#define	MBS_MXF		0x00000100	/* miss transfer error */
#define	MBS_MBEXC	0x00000080	/* massbus exception */
#define	MBS_MDPE	0x00000040	/* massbus data parity error */
#define	MBS_MAPPE	0x00000020	/* page frame map parity error */
#define	MBS_INVMAP	0x00000010	/* invalid map */
#define	MBS_ERRCONF	0x00000008	/* error confirmation */
#define	MBS_RDS		0x00000004	/* read data substitute */
#define	MBS_ISTIMO	0x00000002	/* interface sequence timeout */
#define	MBS_RDTIMO	0x00000001	/* read data timeout */
E 19
I 19
#define	MBSR_DTBUSY	0x80000000	/* data transfer busy */
#define	MBSR_NRCONF	0x40000000	/* no response confirmation */
#define	MBSR_CRD	0x20000000	/* corrected read data */
#define	MBSR_CBHUNG	0x00800000	/* control bus hung */
#define	MBSR_PGE	0x00080000	/* programming error */
#define	MBSR_NED	0x00040000	/* non-existant drive */
#define	MBSR_MCPE	0x00020000	/* massbus control parity error */
#define	MBSR_ATTN	0x00010000	/* attention from massbus */
#define	MBSR_SPE	0x00004000	/* silo parity error */
#define	MBSR_DTCMP	0x00002000	/* data transfer completed */
#define	MBSR_DTABT	0x00001000	/* data transfer aborted */
#define	MBSR_DLT	0x00000800	/* data late */
#define	MBSR_WCKUP	0x00000400	/* write check upper */
#define	MBSR_WCKLWR	0x00000200	/* write check lower */
#define	MBSR_MXF	0x00000100	/* miss transfer error */
#define	MBSR_MBEXC	0x00000080	/* massbus exception */
#define	MBSR_MDPE	0x00000040	/* massbus data parity error */
#define	MBSR_MAPPE	0x00000020	/* page frame map parity error */
#define	MBSR_INVMAP	0x00000010	/* invalid map */
#define	MBSR_ERRCONF	0x00000008	/* error confirmation */
#define	MBSR_RDS	0x00000004	/* read data substitute */
#define	MBSR_ISTIMO	0x00000002	/* interface sequence timeout */
#define	MBSR_RDTIMO	0x00000001	/* read data timeout */
E 19

I 14
D 19
#define MBASR_BITS \
E 19
I 19
#define MBSR_BITS \
E 19
"\20\40DTBUSY\37NRCONF\36CRD\30CBHUNG\24PGE\23NED\22MCPE\21ATTN\
\17SPE\16DTCMP\15DTABT\14DLT\13WCKUP\12WCKLWR\11MXF\10MBEXC\7MDPE\
\6MAPPE\5INVMAP\4ERRCONF\3RDS\2ISTIMO\1RDTIMO"
I 17

D 19
#define	MBASR_HARD	(MBS_PGE|MBS_ERRCONF|MBS_ISTIMO|MBS_RDTIMO)
E 19
I 19
#define	MBSR_HARD	(MBSR_PGE|MBSR_ERRCONF|MBSR_ISTIMO|MBSR_RDTIMO)
E 19

E 17
E 14
D 19
#define MBAEBITS	(~(MBS_DTBUSY|MBS_CRD|MBS_ATTN|MBS_DTCMP))
E 19
I 19
#define MBSR_EBITS	(~(MBSR_DTBUSY|MBSR_CRD|MBSR_ATTN|MBSR_DTCMP))
E 19
I 17

E 17
I 14
D 19
extern	char	mbasr_bits[];
E 19
I 19
#ifdef KERNEL
extern	char	mbsr_bits[];
#endif
E 19
E 14

/*
 * Commands for mbd_cs1
 */
D 19
#define	MBD_WCOM	0x30
#define	MBD_RCOM	0x38
#define	MBD_GO		0x1
E 19
I 19
#define	MB_WCOM		0x30
#define	MB_RCOM		0x38
#define	MB_GO		0x1
E 19

/*
 * Bits in mbd_ds.
 */
D 19
#define	MBD_DRY		0x80		/* drive ready */
#define	MBD_MOL		0x1000		/* medium on line */
#define	MBD_DPR		0x100		/* drive present */
#define	MBD_ERR		0x4000		/* error in drive */
E 19
I 19
#define	MBDS_ERR	0x00004000	/* error in drive */
#define	MBDS_MOL	0x00001000	/* medium on line */
#define	MBDS_DPR	0x00000100	/* drive present */
#define	MBDS_DRY	0x00000080	/* drive ready */

#define	MBDS_DREADY	(MBDS_MOL|MBDS_DPR|MBDS_DRY)
E 19

/*
 * Bits in mbd_dt
 */
E 9
#define	MBDT_NSA	0x8000		/* not sector addressible */
#define	MBDT_TAP	0x4000		/* is a tape */
#define	MBDT_MOH	0x2000		/* moving head */
#define	MBDT_7CH	0x1000		/* 7 channel */
#define	MBDT_DRQ	0x800		/* drive request required */
#define	MBDT_SPR	0x400		/* slave present */

#define	MBDT_TYPE	0x1ff
#define	MBDT_MASK	(MBDT_NSA|MBDT_TAP|MBDT_TYPE)

I 9
/* type codes for disk drives */
E 9
#define	MBDT_RP04	020
#define	MBDT_RP05	021
#define	MBDT_RP06	022
#define	MBDT_RP07	042
I 22
#define	MBDT_RM02	025
E 22
#define	MBDT_RM03	024
#define	MBDT_RM05	027
#define	MBDT_RM80	026
I 21
#define	MBDT_ML11A	0110
#define	MBDT_ML11B	0111
E 21

I 9
/* type codes for tape drives */
E 9
#define	MBDT_TM03	050
#define	MBDT_TE16	051
#define	MBDT_TU45	052
#define	MBDT_TU77	054
D 9
#define	MBDT_TU78	0140
E 9
I 9
D 20
#define	MBDT_TU78	0140		/* can't handle these (yet) */
E 20
I 20
D 21
#define	MBDT_TU78	0101		/* can't handle these (yet) */
E 21
I 21
#define	MBDT_TU78	0101
E 21
E 20
E 9
D 18

/*
D 9
 * Bits in mbd_ds.
E 9
I 9
 * Each driver has an array of pointers to these structures, one for
 * each device it is willing to handle.  At bootstrap time, the
 * driver tables are filled in;
E 9
 */
D 9
#define	MBD_DRY		0x80
#define	MBD_MOL		0x1000
#define	MBD_DPR		0x100
#define	MBD_ERR		0x4000
E 9
I 9
struct	mba_info {
	struct	mba_driver *mi_driver;
	short	mi_name;	/* two character generic name */
	short	mi_unit;	/* unit number to the system */
	short	mi_mbanum;	/* the mba it is on */
	short	mi_drive;	/* controller on mba */
	short	mi_slave;	/* slave to controller (TM03/TU16) */
I 11
	short	mi_dk;		/* driver number for iostat */
E 11
	short	mi_alive;	/* device exists */
	short	mi_type;	/* driver specific unit type */
D 11
	short	mi_dk;		/* driver number for iostat */
E 11
	struct	buf mi_tab;	/* head of queue for this device */
	struct	mba_info *mi_forw;
/* we could compute these every time, but hereby save time */
	struct	mba_regs *mi_mba;
	struct	mba_drv *mi_drv;
	struct	mba_hd *mi_hd;
};
E 9

D 9
#define	MBD_WCOM	0x30
#define	MBD_RCOM	0x38
#define	MBD_GO		0x1
E 9
I 9
/*
 * The initialization routine uses the information in the mbinit table
 * to initialize the drive type routines in the drivers and the
 * mbahd array summarizing which devices are hooked to which massbus slots.
 */
struct	mba_hd {
	short	mh_active;
D 13
	short	mh_flags;
E 13
I 13
	short	mh_ndrive;
E 13
	struct	mba_regs *mh_mba;	/* virt addr of mba */
	struct	mba_regs *mh_physmba;	/* phys addr of mba */
	struct	mba_info *mh_mbip[8];	/* what is attached */
	struct	mba_info *mh_actf;	/* head of queue to transfer */
	struct	mba_info *mh_actl;	/* tail of queue to transfer */
D 16
} mba_hd[4];
E 16
I 16
};
E 16
D 11
#ifdef KERNEL
extern	struct	mba_info mbinit[];	/* blanks for filling mba_info */
I 10
int	nummba;
E 10
#endif
E 11
/*
 * Values for flags; normally MH_NOSEEK will be set when there is
 * only a single drive on an massbus.
 */
#define	MH_NOSEEK	1
#define	MH_NOSEARCH	2
E 9

E 8
D 9
struct mba_regs
{
	int	mba_csr;
	int	mba_cr;
	int	mba_sr;
	int	mba_var;
	int	mba_bcr;
I 4
	int	mba_dr;
	int	mba_pad1[250];
D 8
	int	mba_erb[8][32];		/* external register base */
E 8
I 8
	struct	mba_drv mba_drv[8];
E 8
	struct	pte mba_map[256];
I 8
	int	mba_pad2[256*5];
E 9
I 9
/*
 * Each massbus driver defines entries for a set of routines
 * as well as an array of types which are acceptable to it.
 */
struct mba_driver {
	int	(*md_dkinit)();		/* setup dk info (mspw) */
	int	(*md_ustart)();		/* unit start routine */
	int	(*md_start)();		/* setup a data transfer */
	int	(*md_dtint)();		/* data transfer complete */
	int	(*md_ndint)();		/* non-data transfer interrupt */
	short	*md_type;		/* array of drive type codes */
	struct	mba_info **md_info;	/* backpointers to mbinit structs */
E 9
E 8
E 4
};

D 4
/*
 * NOTE:
 *	mba_erb at displacement 0x400
 *	mba_as at displacement 0x410
 *	mba_map at displacement 0x800
 */
E 4
I 4
D 9
#define	MBAINIT		0x1
D 5
#define MBAIE		0x4
E 5
I 5
#define	MBAIE		0x4
E 9
I 9
/*
 * Possible return values from unit start routines.
 */
#define	MBU_NEXT	0		/* skip to next operation */
#define	MBU_BUSY	1		/* dual port busy; wait for intr */
#define	MBU_STARTED	2		/* non-data transfer started */
#define	MBU_DODATA	3		/* data transfer ready; start mba */
E 9
E 5
E 4

D 2
#define MBA0		0x80044000
#define MBA1		0x80046000
E 2
I 2
D 4
#define MBA0		0x80064000
#define MBA1		0x80066000
E 4
I 4
D 5
#define MBAEBITS	0xe0770
E 5
I 5
D 9
#define	MBAEBITS	0xe0770
E 9
I 9
/*
 * Possible return values from data transfer interrupt handling routines
 */
#define	MBD_DONE	0		/* data transfer complete */
#define	MBD_RETRY	1		/* error occurred, please retry */
#define	MBD_RESTARTED	2		/* driver restarted i/o itself */
E 9
E 5
E 4
E 2

D 4
#define MBA_ERB		0x400
#define MBA_MAP		0x800
E 4
I 4
D 9
#define	PHYSMBA0	((struct mba_regs *)0x20010000)
#define	PHYSMBA1	((struct mba_regs *)0x20012000)
E 9
I 9
/*
 * Possible return values from non-data-transfer interrupt handling routines
 */
#define	MBN_DONE	0		/* non-data transfer complete */
#define	MBN_RETRY	1		/* failed; retry the operation */
E 9
E 4

D 4
#define MBA0_MAP	(MBA0 + 0x800)
#define MBA1_MAP	(MBA1 + 0x800)
E 4
I 4
D 8
#define	mbadev(mba,unit)	((struct device *)mba->mba_erb[unit])
E 8
I 8
D 9
#define	mbadev(mba,unit)	((struct device *)&mba->mba_drv[unit])
E 8
E 4

D 4
#define MBAEBITS	0xe0770
E 4
I 4
#ifdef KERNEL
struct mba_info
{
	struct	mba_regs *mi_loc;	/* virtual mba */
	struct	mba_regs *mi_phys;	/* physical mba */
	struct	pte *mi_map;		/* page table base for nexus */
};
E 4

D 4
#define MBAIE		0x4
E 4
I 4
D 5
#define MBA0		((struct mba_regs *)0x80064000)
#define MBA1		((struct mba_regs *)0x80066000)
E 5
I 5
#define	MBA0		((struct mba_regs *)0x80064000)
#define	MBA1		((struct mba_regs *)0x80066000)
E 5

int	mbanum[];
struct	mba_info mbainfo[];
int	mbaact;
I 7
#endif
E 7
#endif
E 9
I 9
/*
 * Clear attention status for specified drive.
 */
#define	mbclrattn(mi)	((mi)->mi_mba->mba_drv[0].mbd_as = 1 << (mi)->mi_drive)
I 11

/*
 * Kernel definitions related to mba.
 */
#ifdef KERNEL
I 15
#if NMBA > 0
I 16
struct	mba_hd mba_hd[NMBA];
E 16
E 15
extern	Xmba0int(), Xmba1int(), Xmba2int(), Xmba3int();
extern	struct	mba_info mbinit[];	/* blanks for filling mba_info */
int	nummba;
I 15
#endif
E 15
#endif
E 18
E 11
E 9
E 4
D 2

E 2
E 1
