h39946
s 00001/00001/00144
d D 7.1 86/06/05 01:31:49 mckusick 25 24
c 4.3BSD release version
e
s 00002/00000/00143
d D 6.4 86/02/02 21:41:13 karels 24 23
c retries restart from start of undone transfer
e
s 00001/00000/00142
d D 6.3 85/10/14 18:06:59 karels 23 22
c change error recovery procedure when starting positioning rather than
c retrying transfer (so attentions from other drives don't confuse us)
e
s 00007/00001/00135
d D 6.2 85/06/08 14:08:51 mckusick 22 21
c Add copyright
e
s 00000/00000/00136
d D 6.1 83/07/29 07:35:08 sam 21 20
c 4.2 distribution
e
s 00001/00001/00135
d D 4.15 81/04/08 18:38:19 root 20 19
c move nummba to a place where it is defined
c even if there are no mba's.
e
s 00000/00001/00136
d D 4.14 81/03/09 00:27:10 wnj 19 18
c lint
e
s 00064/00145/00073
d D 4.13 81/03/08 16:17:13 wnj 18 17
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
D 22
/*	%M%	%I%	%E%	*/
E 22
I 22
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
E 22
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
 * This file contains definitions related to the kernel structures
 * for dealing with the massbus adapters.
 *
 * Each mba has a mba_hd structure.
 * Each massbus device has a mba_device structure.
 * Each massbus slave has a mba_slave structure.
 *
 * At boot time we prowl the structures and fill in the pointers
 * for devices which we find.
E 18
 */

I 8
D 9
struct mba_drv
E 9
I 9
D 18
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

E 18
E 9
/*
D 9
 * Bits in mbd_dt.
E 9
I 9
D 18
 * Bits in mba_cr
E 18
I 18
 * Per-mba structure.
 *
 * The initialization routine uses the information in the mbdinit table
 * to initialize the what is attached to each massbus slot information.
 * It counts the number of devices on each mba (to see if bothering to
 * search/seek is appropriate).
 *
 * During normal operation, the devices attached to the mba which wish
 * to transfer are queued on the mh_act? links.
E 18
E 9
 */
I 9
D 18
#define	MBAINIT		0x1		/* init mba */
#define	MBAIE		0x4		/* enable mba interrupts */
E 18
I 18
struct	mba_hd {
	short	mh_active;		/* set if mba is active */
	short	mh_ndrive;		/* number of devices, to avoid seeks */
	struct	mba_regs *mh_mba;	/* virt addr of mba */
	struct	mba_regs *mh_physmba;	/* phys addr of mba */
	struct	mba_device *mh_mbip[8];	/* what is attached to each dev */
	struct	mba_device *mh_actf;	/* head of queue to transfer */
	struct	mba_device *mh_actl;	/* tail of queue to transfer */
};
E 18

/*
D 18
 * Bits in mba_sr
E 18
I 18
 * Per-device structure
 * (one for each RM/RP disk, and one for each tape formatter).
 *
 * This structure is used by the device driver as its argument
 * to the massbus driver, and by the massbus driver to locate
 * the device driver for a particular massbus slot.
 *
 * The device drivers hang ready buffers on this structure,
 * and the massbus driver will start i/o on the first such buffer
 * when appropriate.
E 18
 */
D 18
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

I 14
#define MBASR_BITS \
"\20\40DTBUSY\37NRCONF\36CRD\30CBHUNG\24PGE\23NED\22MCPE\21ATTN\
\17SPE\16DTCMP\15DTABT\14DLT\13WCKUP\12WCKLWR\11MXF\10MBEXC\7MDPE\
\6MAPPE\5INVMAP\4ERRCONF\3RDS\2ISTIMO\1RDTIMO"
I 17

#define	MBASR_HARD	(MBS_PGE|MBS_ERRCONF|MBS_ISTIMO|MBS_RDTIMO)

E 17
E 14
#define MBAEBITS	(~(MBS_DTBUSY|MBS_CRD|MBS_ATTN|MBS_DTCMP))
I 17

E 17
I 14
extern	char	mbasr_bits[];
E 14

/*
 * Commands for mbd_cs1
 */
#define	MBD_WCOM	0x30
#define	MBD_RCOM	0x38
#define	MBD_GO		0x1

/*
 * Bits in mbd_ds.
 */
#define	MBD_DRY		0x80		/* drive ready */
#define	MBD_MOL		0x1000		/* medium on line */
#define	MBD_DPR		0x100		/* drive present */
#define	MBD_ERR		0x4000		/* error in drive */

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
#define	MBDT_RM03	024
#define	MBDT_RM05	027
#define	MBDT_RM80	026

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
#define	MBDT_TU78	0140		/* can't handle these (yet) */
E 9

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
E 18
I 18
struct	mba_device {
E 18
	struct	mba_driver *mi_driver;
D 18
	short	mi_name;	/* two character generic name */
E 18
	short	mi_unit;	/* unit number to the system */
	short	mi_mbanum;	/* the mba it is on */
	short	mi_drive;	/* controller on mba */
D 18
	short	mi_slave;	/* slave to controller (TM03/TU16) */
E 18
I 11
	short	mi_dk;		/* driver number for iostat */
E 11
	short	mi_alive;	/* device exists */
	short	mi_type;	/* driver specific unit type */
D 11
	short	mi_dk;		/* driver number for iostat */
E 11
	struct	buf mi_tab;	/* head of queue for this device */
D 18
	struct	mba_info *mi_forw;
E 18
I 18
	struct	mba_device *mi_forw;
E 18
/* we could compute these every time, but hereby save time */
	struct	mba_regs *mi_mba;
	struct	mba_drv *mi_drv;
	struct	mba_hd *mi_hd;
};
E 9

I 24
#define	b_bdone	b_bufsize		/* redefinition for mi_tab XXX */

E 24
D 9
#define	MBD_WCOM	0x30
#define	MBD_RCOM	0x38
#define	MBD_GO		0x1
E 9
I 9
/*
D 18
 * The initialization routine uses the information in the mbinit table
 * to initialize the drive type routines in the drivers and the
 * mbahd array summarizing which devices are hooked to which massbus slots.
E 18
I 18
 * Tape formatter slaves are specified by
 * the following information which is used
 * at boot time to initialize the tape driver
 * internal tables.
E 18
 */
D 18
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
E 18
I 18
struct	mba_slave {
	struct	mba_driver *ms_driver;
	short	ms_ctlr;		/* which of several formatters */
	short	ms_unit;		/* which unit to system */
	short	ms_slave;		/* which slave to formatter */
	short	ms_alive;
E 18
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
D 18
/*
 * Values for flags; normally MH_NOSEEK will be set when there is
 * only a single drive on an massbus.
 */
#define	MH_NOSEEK	1
#define	MH_NOSEARCH	2
E 18
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
D 18
 * Each massbus driver defines entries for a set of routines
 * as well as an array of types which are acceptable to it.
E 18
I 18
 * Per device-type structure.
 *
 * Each massbus driver defines entries for a set of routines used
 * by the massbus driver, as well as an array of types which are
 * acceptable to it.
E 18
 */
struct mba_driver {
D 18
	int	(*md_dkinit)();		/* setup dk info (mspw) */
E 18
I 18
	int	(*md_attach)();		/* attach a device */
	int	(*md_slave)();		/* attach a slave */
E 18
	int	(*md_ustart)();		/* unit start routine */
	int	(*md_start)();		/* setup a data transfer */
	int	(*md_dtint)();		/* data transfer complete */
	int	(*md_ndint)();		/* non-data transfer interrupt */
	short	*md_type;		/* array of drive type codes */
D 18
	struct	mba_info **md_info;	/* backpointers to mbinit structs */
E 18
I 18
	char	*md_dname, *md_sname;	/* device, slave names */
	struct	mba_device **md_info;	/* backpointers to mbinit structs */
E 18
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
I 23
#define	MBD_REPOSITION	3		/* driver started unit, not transfer */
E 23
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
I 18
#define	MBN_SKIP	2		/* don't do anything */
D 19
#define	MBN_CONT	3		/* operation continues */
E 19
E 18
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
D 18
 * Clear attention status for specified drive.
E 18
I 18
 * Clear attention status for specified device.
E 18
 */
#define	mbclrattn(mi)	((mi)->mi_mba->mba_drv[0].mbd_as = 1 << (mi)->mi_drive)
I 11

/*
 * Kernel definitions related to mba.
 */
#ifdef KERNEL
I 20
int	nummba;
E 20
I 15
#if NMBA > 0
I 16
struct	mba_hd mba_hd[NMBA];
E 16
E 15
extern	Xmba0int(), Xmba1int(), Xmba2int(), Xmba3int();
D 18
extern	struct	mba_info mbinit[];	/* blanks for filling mba_info */
E 18
I 18

extern	struct	mba_device mbdinit[];
extern	struct	mba_slave mbsinit[];
E 18
D 20
int	nummba;
E 20
I 15
#endif
E 15
#endif
E 11
E 9
E 4
D 2

E 2
E 1
