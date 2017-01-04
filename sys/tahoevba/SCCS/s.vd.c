h63453
s 00046/00001/01434
d D 7.7 88/07/16 14:25:34 karels 38 37
c need to ensure exclusive access for vdreset_drive/vdmaptype
c (from vdinit; otherwise are in main thread of control)
e
s 00003/00000/01432
d D 7.6 88/07/09 16:34:37 karels 37 36
c add CCI credit, update copyright
e
s 00010/00005/01422
d D 7.5 88/06/29 17:51:06 bostic 36 35
c install approved copyright notice
e
s 00010/00000/01417
d D 7.4 88/06/14 18:46:34 bostic 35 34
c support 2361 super eagles; From: muller%sdcc7@ucsd.edu (Keith Muller)
e
s 00008/00006/01409
d D 7.3 88/06/11 18:54:14 karels 34 33
c correct blkdone calculation in error-reporting routines
e
s 00009/00007/01406
d D 7.2 88/06/04 17:08:00 karels 33 32
c yet another disklabel change: don't "open" partition 0 in WDINFO
c until setdisklabel finishes checks
e
s 00000/00000/01413
d D 7.1 88/06/01 18:05:08 karels 32 31
c bring up to revision 7 for tahoe release
e
s 00003/00000/01410
d D 1.28 88/06/01 18:02:55 karels 31 29
c even if no compat, need to allow access to labelsector on unlabeled disk
e
s 00000/00000/01410
d R 7.1 88/05/31 10:23:33 karels 30 29
c bring up to revision 7 for tahoe release
e
s 00002/00001/01408
d D 1.27 88/05/31 10:22:59 karels 29 27
c missed one
e
s 00000/00000/01409
d R 7.1 88/05/31 08:42:20 karels 28 27
c bring up to revision 7 for tahoe release
e
s 00045/00040/01364
d D 1.26 88/05/27 16:21:39 karels 27 25
c lint; new diskerr routine
e
s 00013/00001/01403
d R 7.1 88/05/21 18:33:16 karels 26 25
c bring up to revision 7 for tahoe release
e
s 00146/00047/01258
d D 1.25 88/05/21 15:36:34 karels 25 24
c new vd_harderr routine; finish timeout code; on-line format support
c (untested)
e
s 00000/00023/01305
d D 1.24 88/05/14 11:40:33 karels 24 23
c raw read/write (checked in for bostic)
e
s 00050/00020/01278
d D 1.23 88/04/23 17:56:42 karels 23 22
c update disklabels
e
s 00001/00001/01297
d D 1.22 87/11/12 13:34:35 karels 22 21
c missing error return
e
s 00012/00039/01286
d D 1.21 87/11/01 12:57:29 karels 21 20
c use setdisklabel, writedisklabel
e
s 00143/00075/01182
d D 1.20 87/09/17 15:24:32 karels 20 19
c unify code to compute sector shift, fixes to SMD/E disklabel setup
c (need to set sectors >= all real drives), several other fixes
e
s 00026/00026/01231
d D 1.19 87/05/07 19:59:08 karels 19 18
c convert xsd, smd, fuj to 512-byte sectors
e
s 00127/00111/01130
d D 1.18 87/04/02 15:59:47 karels 18 17
c scatter-gather; pack label cleanups
e
s 00057/00058/01184
d D 1.17 87/03/10 18:12:24 karels 17 16
c working (I think!) with uncacheable intermediate buffers:
c add vb_buf struct and vbinit to set up, rm b_upte, remove (old)vbasetup
c and rename vbastart to vbasetup ala uba; use bcopy to kernel, double-
c mapping to user space, and purge user-space cache with dkeyinval
e
s 00065/00053/01177
d D 1.16 87/03/01 21:44:03 karels 16 15
c simplify seek queuing, give priority to drives on-cylinder
e
s 00109/00064/01121
d D 1.15 87/02/28 16:20:14 karels 15 14
c remove sector shift, get blkno as sectors instead; finish pack labels;
c fill out compat partitions; minor cleanups
e
s 00921/00716/00264
d D 1.14 87/02/18 21:58:03 sam 14 13
c rewrite; disk label support
e
s 00086/00077/00894
d D 1.13 87/01/11 21:23:09 karels 13 12
c more or less 4.3
e
s 00021/00005/00950
d D 1.12 86/11/03 12:29:03 karels 12 11
c more conversion to 4.3-ism's
e
s 00004/00003/00951
d D 1.11 86/11/03 12:06:56 karels 11 10
c mv uncache to cpu.h
e
s 00030/00015/00924
d D 1.10 86/10/28 21:03:28 karels 10 9
c fix error messages, various cleanups
e
s 00011/00013/00928
d D 1.9 86/07/16 08:30:19 sam 9 8
c change disk names to dk; print drive type always (needs more)
e
s 00003/00003/00938
d D 1.8 86/01/23 13:16:24 sam 8 7
c allocate io buffers at boot time to save space
e
s 00001/00001/00940
d D 1.7 86/01/21 00:25:26 sam 7 6
c rename
e
s 00092/00081/00849
d D 1.6 86/01/20 23:50:59 sam 6 5
c POLLTILLDONE -> vdpoll; autoconfig page map for i/o buffer; 
c print controller type at boot time; move part of vdslave into vdprobe
e
s 00005/00006/00925
d D 1.5 86/01/12 21:46:20 sam 5 4
c fix some includes and make scope points globally controlled
e
s 00002/00000/00929
d D 1.4 86/01/12 17:39:37 sam 4 3
c identify controller type at boot time
e
s 00013/00008/00916
d D 1.3 86/01/12 15:53:24 sam 3 2
c start of autoconfig
e
s 00788/00705/00136
d D 1.2 86/01/05 18:37:48 sam 2 1
c 1st working version (mostly)
e
s 00841/00000/00000
d D 1.1 85/07/21 20:36:12 sam 1 0
c date and time created 85/07/21 20:36:12 by sam
e
u
U
t
T
I 1
D 27
/*	%M%	%I%	%E%	*/
E 27
I 27
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
I 37
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
 *
E 37
 * Redistribution and use in source and binary forms are permitted
D 36
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 36
I 36
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
E 36
 *
 *	%W% (Berkeley) %G%
 */
E 27

D 9
#include "fsd.h"
E 9
I 9
#include "dk.h"
E 9
#if NVD > 0
/*
D 2
**	VDDC Driver - Versabus to SMD direct interface version.
**		Written for TAHOE vmunix, CCI-WDC 9/1/83.		
*/
E 2
I 2
D 9
 * VDDC - Versabus SMD/ESMD driver.
E 9
I 9
D 14
 * VDDC - Versabus SMD/SMDE driver.
E 14
I 14
 * Versabus VDDC/SMDE driver.
E 14
E 9
 */
I 5
D 14
#ifdef VDDCPERF
#define	DOSCOPE
#endif

E 14
E 5
D 11
#include "../tahoe/mtpr.h"
#include "../tahoe/pte.h"
E 2

E 11
D 2
#include "../h/param.h"
#include "../h/buf.h"
#include "../h/cmap.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/dk.h"
#include "../h/map.h"
#include "../machine/mtpr.h"
#include "../machine/pte.h"
#include "../h/systm.h"
#include "../vba/vbavar.h"
#include "../h/user.h"
#include "../h/vmmac.h"
#include "../h/proc.h"
#include "../h/uio.h"
#include "../vba/vddc.h"
E 2
I 2
#include "param.h"
#include "buf.h"
#include "cmap.h"
#include "conf.h"
#include "dir.h"
D 9
#include "dk.h"
E 9
I 9
#include "dkstat.h"
I 14
#include "disklabel.h"
E 14
E 9
#include "map.h"
I 14
#include "file.h"
E 14
#include "systm.h"
#include "user.h"
#include "vmmac.h"
#include "proc.h"
#include "uio.h"
I 13
#include "syslog.h"
#include "kernel.h"
I 14
#include "ioctl.h"
I 18
#include "stat.h"
E 18
E 14
E 13
I 11

#include "../tahoe/cpu.h"
#include "../tahoe/mtpr.h"
#include "../tahoe/pte.h"
E 11
E 2

D 2
int	vddebug = 1;	/* if = 1, error messages are printed on the console */
int	vdintflg = 0;	/* if = 1, interrupts are handled by the driver, 
			 * otherwise they are just ignored. (during setup) */
E 2
I 2
#include "../tahoevba/vbavar.h"
D 14
#define	VDGENDATA
E 14
D 7
#include "../tahoevba/vddcreg.h"
E 7
I 7
#include "../tahoevba/vdreg.h"
E 7
D 14
#undef VDGENDATA
I 5
#include "../tahoevba/scope.h"
E 14
E 5
E 2

I 20
#ifndef	COMPAT_42
E 20
I 14
#define	COMPAT_42
I 20
#endif
I 25
#define	B_FORMAT	B_XXX		/* XXX */
E 25
E 20

E 14
D 2
static struct size FSD[] = {
    9600,       0,	/* minor 0/ 8/16/24 = fsd0a - fsd3a - cyl   0 -  59*/
   12000,    9600,	/* minor 1/ 9/17/25 = fsd0b - fsd3b - cyl  60 - 134*/
  108480,   21600,	/* minor 2/10/18/26 = fsd0c - fsd3c - cyl 135 - 812*/
    1600,  130080,	/* minor 3/11/19/27 = fsd0d - fsd3d - cyl 813 - 822*/
  130080,       0,	/* minor 4/12/20/28 = fsd0e - fsd3e - cyl   0 - 812*/
  131680,       0,	/* minor 5/13/21/29 = fsd0f - fsd3f - cyl   0 - 822*/
       0,	0,	/* Non existent minor device */
       0,	0,	/* Non existent minor device */
       0,	0,	/* Non existent minor device */
       0,	0,	/* Non existent minor device */
       0,	0,	/* Non existent minor device */
       0,	0,	/* Non existent minor device */
       0,	0,	/* Non existent minor device */
       0,	0,	/* Non existent minor device */
       0,	0,	/* Non existent minor device */
       0,	0,	/* Non existent minor device */
};
E 2
I 2
D 6
#define	MAX_BLOCKSIZE	(MAXBPTE*NBPG)
E 6
I 6
D 17
#define	VDMAXIO		(MAXBPTE*NBPG)
E 17
I 17
D 18
#define	VDMAXIO		(VDMAXPAGES * NBPG)
E 17
E 6
D 14
#define	DUMPSIZE	64	/* controller limit */
E 14
E 2

E 18
D 2
static struct size	SMD[]= {
    20064,	0, 	/* minor 32/40/48/56 = smd0a - smd3a cyl 0- 65 */
    13680,  20064, 	/* minor 33/41/49/57 = smd0b - smd3b cyl 66- 110 */
   214928,  33744, 	/* minor 34/42/50/58 = smd0c - smd3c cyl 111-817 */
     1520, 248672, 	/* minor 35/43/51/59 = smd0d - smd3d cyl 818-822 */
   248672,	0, 	/* minor 36/44/52/60 = smd0e - smd3e cyl 0-817 */
   250192,	0, 	/* minor 37/45/53/61 = smd0f - smd3f cyl 0-822 */
	0,	0, 	/* minor 38/46/54/62 = smd0g - smd3g */
	0,	0, 	/* minor 39/47/55/63 = smd0h - smd3h */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
};

static struct size XFSD[] = {
    20352,	0, 	/* minor 64/72/80/88 = xfsd0a - xfsd3a cyl 0- 52 */
    20352,  20352, 	/* minor 65/73/81/89 = xfsd0b - xfsd3b cyl 53- 105 */
   230400,  40704, 	/* minor 66/74/82/90 = xfsd0c - xfsd3c cyl 106-705 */
     1920, 271104, 	/* minor 67/75/83/91 = xfsd0d - xfsd3d cyl 706-710 */
   271104,	0, 	/* minor 68/76/84/92 = xfsd0e - xfsd3e cyl 0-705 */
   273024,	0, 	/* minor 69/77/85/93 = xfsd0f - xfsd3f cyl 0-710 */
	0,	0, 	/* minor 70/78/86/94 = xfsd0g - xfsd3g */
	0,	0, 	/* minor 71/79/87/95 = xfsd0h - xfsd3h */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
	0,	0,	/* Non existent minor device */
};

/*
/*
/* Layout of minor number assignments for the VDDC devices.
/*
/* 	  1
/*	  5		            3 2   0
/*	 +---------------------------+-----+
/*	 |     		 Unit number | FLS |
/*	 +---------------------------+-----+
/*			      	   |    |_____ File system # ( 0-7 )
/*			      	   |__________ Unit # in the system
/*
/********************************************************/

E 2
D 14
#define VDUNIT(x)	(minor(x) >> 3)
D 2
#define FLSYS(x)	(minor(x) & 0x07)
#define PHYS(x)		( vtoph( 0, (int) (x) ) )
E 2
I 2
#define FILSYS(x)	(minor(x) & 0x07)
#define PHYS(x)		(vtoph((struct proc *)0, (unsigned)(x)))
E 14
I 14
#define vdunit(dev)	(minor(dev) >> 3)
#define vdpart(dev)	(minor(dev) & 0x07)
#define	vdminor(unit,part)	(((unit) << 3) | (part))
E 14
D 9
#define TRUE		1
#define	FALSE		0
E 9
E 2

I 2
D 14
#define CTLR_ERROR	1
#define DRIVE_ERROR	2
#define HARD_DATA_ERROR	3
#define SOFT_DATA_ERROR	4
I 10
#define	WRITE_PROTECT	5
E 10
E 2

D 2
/* Drive types should be in order of drive capacity for auto-configuration */
/* e.g: smallest capacity = drive type 0, highest capacity = type NXPDRV-1 */
E 2
I 2
#define b_cylin	b_resid
#define b_daddr	b_error
E 2

E 14
D 2
struct vdst {
	short nsect;
	short ntrak;
	short nspc;
	short ncyl;
	struct size *sizes;
	short dtype;		/* type as in byte 5 (drive) of iopb */
	char	*name;		/* drive name for autoconf */
} vdst[] = {

16,	10,	16*10,	823,	FSD,	0,	"fsd",
16,	19,	16*19,	823,	SMD,	1, 	"smd",
16,	24,	16*24,  711,   XFSD,	2,	"xfd"
};


E 2
struct	vba_ctlr *vdminfo[NVD];
D 9
struct  vba_device *vddinfo[NFSD];
E 9
I 9
struct  vba_device *vddinfo[NDK];
E 9
I 2
D 18
int	vdprobe(), vdslave(), vdattach(), vddgo();
E 18
I 18
int	vdprobe(), vdslave(), vdattach(), vddgo(), vdstrategy();
E 18
I 14
D 27
long	vdaddr[] = { 0xffff2000, 0xffff2100, 0xffff2200, 0xffff2300, 0 };
E 27
I 27
long	vdstd[] = { 0xffff2000, 0xffff2100, 0xffff2200, 0xffff2300, 0 };
E 27
E 14
struct	vba_driver vddriver =
D 9
    { vdprobe, vdslave, vdattach, vddgo, vddcaddr, "smd/fsd",
E 9
I 9
D 14
    { vdprobe, vdslave, vdattach, vddgo, vddcaddr, "dk",
E 9
      vddinfo, "vd", vdminfo };
E 14
I 14
D 27
  { vdprobe, vdslave, vdattach, vddgo, vdaddr, "dk", vddinfo, "vd", vdminfo };
E 27
I 27
  { vdprobe, vdslave, vdattach, vddgo, vdstd, "dk", vddinfo, "vd", vdminfo };
E 27
E 14
E 2

/*
I 14
 * Per-controller state.
 */
struct vdsoftc {
	u_short	vd_flags;
#define	VD_INIT		0x1	/* controller initialized */
#define	VD_STARTED	0x2	/* start command issued */
#define	VD_DOSEEKS	0x4	/* should overlap seeks */
I 18
#define	VD_SCATGATH	0x8	/* can do scatter-gather commands (correctly) */
I 38
#define	VD_LOCKED	0x10	/* locked for direct controller access */
#define	VD_WAIT		0x20	/* someone needs direct controller access */
E 38
E 18
	u_short	vd_type;	/* controller type */
	u_short	vd_wticks;	/* timeout */
D 16
	u_short	vd_offcyl;	/* off cylinder bitmask */
E 16
	struct	mdcb vd_mdcb;	/* master command block */
	u_long	vd_mdcbphys;	/* physical address of vd_mdcb */
	struct	dcb vd_dcb;	/* i/o command block */
	u_long	vd_dcbphys;	/* physical address of vd_dcb */
D 17
	struct	pte *vd_map;	/* i/o page map */
	caddr_t	vd_utl;		/* mapped i/o space */
	caddr_t	vd_rawbuf;	/* buffer for raw+swap i/o */
E 17
I 17
	struct	vb_buf vd_rbuf;	/* vba resources */
E 17
} vdsoftc[NVD];

I 25
#define	VDMAXTIME	20	/* max time for operation, sec. */

E 25
/*
E 14
D 2
**	Internal Functions
*/
int	vdopen();
int	vdclose();
int	vdprobe();		/* See if VDDC is really there */
int	vd_setup();		/* Called from vdprobe */
int	vdslave();		/* See if drive is really there */
int	vdattach();
int	vddgo();
int	vdstrategy();		/* VDDC strategy routine */
int	vdstart();		/* Top level interface to device queue */
int	vdintr();		/* Top Level ISR */
int	vdread();		/* raw i/o read routine */
int	vdwrite();		/* raw i/o write routine */
int	vddump();		/* dump routine */
int	vdsize();		/* sizes for swapconfig */
int	dskrst();		/* reset a drive after hard error */
E 2
I 2
 * Per-drive state.
 */
D 14
typedef struct {
	struct	buf raw_q_element;
	short	sec_per_blk;
	short	sec_per_cyl;
	char	status;
	struct	buf xfer_queue;
	int	drive_type;
	fs_tab	info;
} unit_tab;
E 14
I 14
struct	dksoftc {
D 23
	u_short	dk_state;	/* open fsm */
E 23
I 23
	int	dk_state;	/* open fsm */
E 23
D 18
	u_short	dk_openpart;	/* units open on this drive */
E 18
I 18
D 21
	u_short	dk_copenpart;	/* character units open on this drive */
	u_short	dk_bopenpart;	/* block units open on this drive */
	u_short	dk_openpart;	/* all units open on this drive */
E 21
#ifndef SECSIZE
	u_short	dk_bshift;	/* shift for * (DEV_BSIZE / sectorsize) XXX */
#endif SECSIZE
I 23
	int	dk_wlabel;	/* label sector is currently writable */
E 23
I 21
	u_long	dk_copenpart;	/* character units open on this drive */
	u_long	dk_bopenpart;	/* block units open on this drive */
	u_long	dk_openpart;	/* all units open on this drive */
E 21
E 18
D 15
	u_short	dk_bshift;	/* shift for * (DEV_BSIZE / sectorsize) XXX */
E 15
D 16
	u_short	dk_curdaddr;	/* last selected track & sector */
E 16
	u_int	dk_curcyl;	/* last selected cylinder */
D 18
	struct	dcb dk_dcb;	/* seek command block */
E 18
I 18
	struct	skdcb dk_dcb;	/* seek command block */
E 18
	u_long	dk_dcbphys;	/* physical address of dk_dcb */
I 25
	int	df_reg[3];	/* for formatting, in-out parameters */
E 25
} dksoftc[NDK];
E 14
E 2

D 2
long	vdstd[] = {
		0x0f2000 };

struct	vba_driver vddriver = {
	vdprobe, vdslave, vdattach, vddgo, vdstd, 
	"smd/fsd", vddinfo, "vd", vdminfo
};

struct	buf	vdutab[NFSD];
struct 	buf	rvdbuf[NFSD];
char	vdbuf[NVD][MAXBPTE * NBPG];	/* internal buffer for raw/swap i/o */
long	vdbufused[NVD];
extern char	vd0utl[],vd1utl[],vd2utl[],vd3utl[];

E 2
/*
D 2
**	Disk Address
*/
struct	dskadr	{
	char	track;		/* all 8 bits */
	char	sector;		/* low order 5 bits */
	short	cylinder;	/* low order 12 bits */
};
E 2
I 2
D 14
 * Per-controller state.
E 14
I 14
 * Drive states.  Used during steps of open/initialization.
 * States < OPEN (> 0) are transient, during an open operation.
D 23
 * OPENRAW is used for unabeled disks, to allow format operations.
E 23
I 23
 * OPENRAW is used for unlabeled disks, to allow format operations.
E 23
E 14
 */
D 14
typedef struct {
	char	ctlr_type;	/* controller type */
D 6
	char	*map;		/* i/o page map */
	char	*utl;		/* mapped i/o space */
E 6
I 6
	struct	pte *map;	/* i/o page map */
	caddr_t	utl;		/* mapped i/o space */
E 6
	u_int	cur_slave:8;	/* last active unit number */
D 10
	u_int	int_expected:1;	/* expect an interupt */
E 10
I 10
	u_int	int_expected:1;	/* expect an interrupt */
E 10
	u_int	ctlr_started:1;	/* start command was issued */
	u_int	overlap_seeks:1;/* should overlap seeks */
I 6
	u_int	initdone:1;	/* controller initialization completed */
E 6
	u_int	off_cylinder:16;/* off cylinder bit map */
	u_int	unit_type[16];	/* slave types */
	u_int	cur_cyl[16];	/* cylinder last selected */
	long	cur_trk[16];	/* track last selected */
	fmt_mdcb ctlr_mdcb;	/* controller mdcb */
	fmt_dcb	ctlr_dcb;	/* r/w dcb */
	fmt_dcb	seek_dcb[4];	/* dcbs for overlapped seeks */
D 8
	/* buffer for raw/swap i/o */
D 6
	char	rawbuf[MAX_BLOCKSIZE];
E 6
I 6
	char	rawbuf[VDMAXIO];
E 8
I 8
	caddr_t	rawbuf;		/* buffer for raw+swap i/o */
E 8
E 6
} ctlr_tab;
E 14
I 14
#define	CLOSED		0		/* disk is closed */
#define	WANTOPEN	1		/* open requested, not started */
#define	WANTOPENRAW	2		/* open requested, no label */
#define	RDLABEL		3		/* reading pack label */
#define	OPEN		4		/* intialized and ready */
#define	OPENRAW		5		/* open, no label */
E 14
E 2

D 2
/*
**	DCB Trailer Formats
**********************************/
E 2
I 2
D 6
extern char	vd0utl[];
#if NVD > 1
extern char	vd1utl[];
#endif
#if NVD > 2
extern char	vd2utl[];
#endif
#if NVD > 3
extern char	vd3utl[];
#endif
E 2

D 2
/*
**	Read / Write Trailer
*/
struct	trrw	{
	char	*memadr;			/* memory address */
	long	wcount;				/* 16 bit word count */
	struct	dskadr	disk;			/* disk address */
E 2
I 2
#define	VDCINIT(map, utl) { \
    UNKNOWN, (char *)map, utl, 0, FALSE, FALSE, TRUE, 0, \
	{ UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN, \
	  UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN } \
}
ctlr_tab vdctlr_info[NVD] = {
	VDCINIT(VD0map, vd0utl),
#if NVD > 1
	VDCINIT(VD1map, vd1utl),
#endif
#if NVD > 2
	VDCINIT(VD2map, vd2utl),
#endif
#if NVD > 3
	VDCINIT(VD3map, vd3utl),
#endif
E 2
};

E 6
I 6
D 14
ctlr_tab vdctlr_info[NVD];
E 6
D 2
/*
**	Format Trailer
*/
struct	trfmt	{
	char	*addr;			/* data buffer to be filled on sector*/
	long	nsectors;		/* # of sectors to be formatted */
	struct	dskadr	disk;
	struct	dskadr  hdr;
};
E 2
I 2
D 9
unit_tab vdunit_info[NFSD];
E 9
I 9
unit_tab vdunit_info[NDK];
E 14
I 14
D 24
struct	buf rdkbuf[NDK];	/* raw i/o buffer headers */
E 24
struct	buf dkutab[NDK];	/* i/o queue headers */
struct	disklabel dklabel[NDK];	/* pack labels */
E 14
E 9
E 2

I 14
#define b_cylin	b_resid
D 16
#define	b_daddr	b_error
E 16
I 16
#define	b_track	b_error		/* used for seek commands */
#define	b_seekf	b_forw		/* second queue on um_tab */
#define	b_seekl	b_back		/* second queue on um_tab */
E 16

int	vdwstart, vdwatch();

E 14
/*
D 2
**	Reset / Configure Trailer
*/
struct	treset	{
	long	ncyl;		/* # cylinders */
	long	nsurfaces;	/* # surfaces */
};				/* # of sectors is defined by VDDC */
				/* to be 32/track of 512 data bytes each */

/*
**	Seek Trailer
*/
struct	trseek	{
	struct	dskadr	disk;
};

/*
**	DCB Format
*/
struct	fmt_dcb	{
	struct	fmt_dcb	*nxtdcb;	/* next dcb in chain or End of Chain */
	short	intflg;			/* interrupt settings and flags */
	short	opcode;			/* DCB Command code etc... */
	long	operrsta;		/* Error & Status info */
	short	fill;			/* not used */
	char	devselect;		/* Drive selection */
	char	trailcnt;		/* Trailer Word Count */
	long	err_memadr;		/* Error memory address */
	short	fill2;
	short	err_wcount;		/* Error word count */
	short	err_track;		/* Error track/sector */
	short	err_cyl;		/* Error cylinder adr */
	union	{
		struct	trrw	rwtrail;	/* read/write trailer */
		struct	trfmt	fmtrail;	/* format trailer */
		struct	treset	resetrail;	/* reset/configure trailer */
		struct	trseek	seektrail;	/* seek trailer */
	} trail;
};

/*
**	MDCB Format
*/
struct	fmt_mdcb	{
	struct	fmt_dcb	*firstdcb;	/* first dcb in chain */
	struct	fmt_dcb	*procdcb;	/* dcb being processed */
	struct	fmt_dcb	*intdcb;	/* dcb causing interrupt */
	long	vddcstat;		/* VDDC status */
}mdcbx[NVD];

/*
**	DCB
*/

struct	fmt_dcb		dcbx[NVD];

int vdtimeout;	
#define	POLLTILLDONE(x, name) { \
	vdtimeout = 1000*(x); \
	uncache((char *)&dcb->operrsta); \
	while (! (dcb->operrsta & DCBCMP)) { \
		DELAY(1000); \
		vdtimeout--; \
		uncache((char *)&dcb->operrsta); \
		if (vdtimeout <=0) { \
			printf("vd: timeout on %s\n", name);\
			return(0); \
		} \
	} \
}

/*
**	See if the controller is really there. 
**	if TRUE - initialize the controller.
*/
vdprobe(cntrl_vaddr)
caddr_t cntrl_vaddr;
E 2
I 2
 * See if the controller is really there; if so, initialize it.
 */
D 3
vdprobe(addr)
	cdr *addr;
E 3
I 3
vdprobe(reg, vm)
	caddr_t reg;
	struct vba_ctlr *vm;
E 3
E 2
{
D 2
	if ( badaddr(cntrl_vaddr,2) ) return(0); /* no controller */
	else 
		if (vd_setup(cntrl_vaddr))	/* initialize the controller */
			return(1);
		else return(0);		/* initialization error */	
E 2
I 2
D 3
	if (badaddr((caddr_t)addr, 2))
E 3
I 3
	register br, cvec;		/* must be r12, r11 */
D 6
	register cdr *cp = (cdr *)reg;
E 6
I 6
D 14
	register cdr *addr = (cdr *)reg;
	register ctlr_tab *ci;
	int i;
E 14
I 14
	register struct vddevice *vdaddr = (struct vddevice *)reg;
	struct vdsoftc *vd;
I 15
	int s;
E 15
E 14
E 6

I 13
#ifdef lint
	br = 0; cvec = br; br = cvec;
	vdintr(0);
#endif
E 13
	if (badaddr((caddr_t)reg, 2))
E 3
		return (0);
D 3
	addr->cdr_reset = 0xffffffff;
E 3
I 3
D 6
	cp->cdr_reset = 0xffffffff;
E 6
I 6
D 14
	ci = &vdctlr_info[vm->um_ctlr];
	addr->cdr_reset = 0xffffffff;
E 14
I 14
	vd = &vdsoftc[vm->um_ctlr];
	vdaddr->vdreset = 0xffffffff;
E 14
E 6
E 3
	DELAY(1000000);
D 3
	if (addr->cdr_reset != (unsigned)0xffffffff) {
E 3
I 3
D 6
	if (cp->cdr_reset != (unsigned)0xffffffff) {
E 6
I 6
D 14
	if (addr->cdr_reset != (unsigned)0xffffffff) {
		ci->ctlr_type = SMDCTLR;
		ci->overlap_seeks = 0;
E 14
I 14
	if (vdaddr->vdreset != (unsigned)0xffffffff) {
		vd->vd_type = VDTYPE_VDDC;
		vd->vd_flags &= ~VD_DOSEEKS;
E 14
E 6
E 3
		DELAY(1000000);
	} else {
D 3
		addr->cdr_reserved = 0x0;
E 3
I 3
D 6
		cp->cdr_reserved = 0x0;
E 6
I 6
D 14
		ci->overlap_seeks = 1;
		ci->ctlr_type = SMD_ECTLR;
		addr->cdr_reserved = 0x0;
E 14
I 14
		vd->vd_type = VDTYPE_SMDE;
		vd->vd_flags |= VD_DOSEEKS;
		vdaddr->vdrstclr = 0;
E 14
E 6
E 3
		DELAY(3000000);
I 6
D 14
		addr->cdr_csr = 0;
		addr->mdcb_tcf = AM_ENPDA;
		addr->dcb_tcf = AM_ENPDA;
		addr->trail_tcf = AM_ENPDA;
		addr->data_tcf = AM_ENPDA;
D 10
		addr->cdr_ccf = CCF_STS | XMD_32BIT | BSZ_16WRD |
E 10
I 10
		addr->cdr_ccf = CCF_SEN | CCF_DER | CCF_STS |
E 14
I 14
		vdaddr->vdcsr = 0;
		vdaddr->vdtcf_mdcb = AM_ENPDA;
		vdaddr->vdtcf_dcb = AM_ENPDA;
		vdaddr->vdtcf_trail = AM_ENPDA;
		vdaddr->vdtcf_data = AM_ENPDA;
		vdaddr->vdccf = CCF_SEN | CCF_DER | CCF_STS |
E 14
		    XMD_32BIT | BSZ_16WRD |
E 10
		    CCF_ENP | CCF_EPE | CCF_EDE | CCF_ECE | CCF_ERR;
E 6
	}
I 14
	vd->vd_mdcbphys = vtoph((struct proc *)0, (unsigned)&vd->vd_mdcb);
	vd->vd_dcbphys = vtoph((struct proc *)0, (unsigned)&vd->vd_dcb);
	vm->um_addr = reg;		/* XXX */
I 15
	s = spl7();
E 15
	if (!vdcmd(vm, VDOP_INIT, 10) || !vdcmd(vm, VDOP_DIAG, 10)) {
		printf("vd%d: %s cmd failed\n", vm->um_ctlr,
		    vd->vd_dcb.opcode == VDOP_INIT ? "init" : "diag");
I 15
		splx(s);
E 15
		return (0);
	}
I 18
	if (vd->vd_type == VDTYPE_SMDE) {
		vd->vd_dcb.trail.idtrail.date = 0;
		if (vdcmd(vm, VDOP_IDENT, 10)) {
			uncache(&vd->vd_dcb.trail.idtrail.date);
			if (vd->vd_dcb.trail.idtrail.date != 0)
				vd->vd_flags |= VD_SCATGATH;
		}
	}
E 18
I 15
	splx(s);
E 15
E 14
I 6
	/*
D 8
	 * Allocate page tables.
E 8
I 8
	 * Allocate page tables and i/o buffer.
E 8
	 */
D 14
	vbmapalloc(btoc(VDMAXIO)+1, &ci->map, &ci->utl);
I 8
	ci->rawbuf = calloc(VDMAXIO);
E 8
	/*
	 * Initialize all the drives to be of an unknown type.
	 */
	for (i = 0; i < 15; i++)
		ci->unit_type[i] = UNKNOWN;
E 14
I 14
D 17
	vbmapalloc(btoc(VDMAXIO)+1, &vd->vd_map, &vd->vd_utl);
	vd->vd_rawbuf = calloc(VDMAXIO);
E 17
I 17
D 18
	vbainit(&vd->vd_rbuf, VDMAXIO,
E 18
I 18
D 20
	vbainit(&vd->vd_rbuf, MAXPHYS,
E 18
	    vd->vd_type == VDTYPE_VDDC ? VB_24BIT : VB_32BIT);
E 20
I 20
	if (vbainit(&vd->vd_rbuf, MAXPHYS,
	    vd->vd_type == VDTYPE_VDDC ? VB_24BIT : VB_32BIT) == 0) {
		printf("vd%d: vbainit failed\n", vm->um_ctlr);
		return (0);
	}
E 20
E 17
E 14
E 6
D 3
	return (sizeof (cdr));
E 3
I 3
	br = 0x17, cvec = 0xe0 + vm->um_ctlr;	/* XXX */
D 6
	return (sizeof (*cp));
E 6
I 6
D 14
	return (sizeof (*addr));
E 14
I 14
	return (sizeof (struct vddevice));
E 14
E 6
E 3
E 2
}

D 2
vd_setup(cntrl_vaddr)
caddr_t cntrl_vaddr;
{
	register struct fmt_dcb *dcb = &dcbx[0];
	register struct fmt_mdcb *mdcb = &mdcbx[0];
	int j;

	VDDC_RESET(cntrl_vaddr);		/* Reset the controller */
		/* Burn some time ...... needed after accessing reset port */
	for (j=0; j<20; j++)
		DELAY(1000);

	/* setup & issue INIT to initialize VDDC */

	dcb->opcode = INIT;
	dcb->nxtdcb = (struct fmt_dcb *)0;
	dcb->intflg = NOINT;
	mdcb->firstdcb = (struct fmt_dcb *)PHYS(dcb);
	dcb->operrsta  = 0;
	VDDC_ATTENTION(cntrl_vaddr,PHYS(mdcb) );	/* do it */
	POLLTILLDONE(1,"INIT");		/* poll till done */
	if (dcb->operrsta & HRDERR) {
		if (vddebug)
			printf("vd: init error, err=%b\n",
			    dcb->operrsta, ERRBITS);
		return(0);
	}
	/* setup & issue DIAGNOSE */

	dcb->opcode = DIAG;
	dcb->nxtdcb = (struct fmt_dcb *)0;
	dcb->intflg = NOINT;
	mdcb->firstdcb = (struct fmt_dcb *)PHYS(dcb);
	dcb->operrsta  = 0;
	VDDC_ATTENTION(cntrl_vaddr,PHYS(mdcb) )	/* do it */
	POLLTILLDONE(1,"DIAG")		/* poll till done */
	if (dcb->operrsta & HRDERR) {
		if (vddebug)
			printf("vd: diagnose error, err=%b\n",
			    dcb->operrsta, ERRBITS);
		return(0);
	}
	/* Start drives command */
#ifdef notdef
	dcb->opcode = VDSTART;
	dcb->nxtdcb = (struct fmt_dcb *)0;
	dcb->intflg = NOINT;
	mdcb->firstdcb = (struct fmt_dcb *)PHYS(dcb);
	dcb->operrsta  = 0;
	VDDC_ATTENTION(cntrl_vaddr,PHYS(mdcb) )	/* do it */
	POLLTILLDONE(20,"VDSTART")		/* poll till done */
	if (dcb->operrsta & HRDERR) {
		if (vddebug)
			printf("vd: start error, err=%b\n",
			    dcb->operrsta, ERRBITS);
		return(0);
	}
#endif
	return(1);
   }

E 2
/*
D 14
 * See if a drive is really there
D 2
 * Try to Reset/Configure the drive, then test its status.
*/
vdslave(ui,cntrl_vaddr)
register struct vba_device *ui;
register caddr_t cntrl_vaddr;
E 2
I 2
 * Try to reset/configure the drive, then test its status.
E 14
I 14
 * See if a drive is really there.
 *
 * Can't read pack label here as various data structures
 * aren't setup for doing a read in a straightforward
 * manner.  Instead just probe for the drive and leave
 * the pack label stuff to the attach routine.
E 14
 */
D 23
vdslave(vi, addr)
E 23
I 23
/* ARGSUSED */
vdslave(vi, vdaddr)
E 23
	register struct vba_device *vi;
D 14
	register cdr *addr;
E 14
I 14
	struct vddevice *vdaddr;
E 14
E 2
{
D 2
	register struct fmt_dcb	*dcb = &dcbx[0];
	register struct fmt_mdcb *mdcb = &mdcbx[ui->ui_ctlr];
	register struct vdst *st;
	int dsktype;
E 2
I 2
D 14
	register ctlr_tab *ci = &vdctlr_info[vi->ui_ctlr];
	register unit_tab *ui = &vdunit_info[vi->ui_unit];
	register fmt_mdcb *mdcb = &ci->ctlr_mdcb;
	register fmt_dcb *dcb = &ci->ctlr_dcb;
	register int type;
E 14
I 14
	register struct disklabel *lp = &dklabel[vi->ui_unit];
I 20
	register struct dksoftc *dk = &dksoftc[vi->ui_unit];
E 20
	struct vdsoftc *vd = &vdsoftc[vi->ui_ctlr];
E 14
E 2

D 2
	/*
	**  check drive status - see if drive exists. 
	*/
	dcb->opcode = VDSTATUS;
	dcb->intflg = NOINT;
	dcb->operrsta  = 0;
	dcb->devselect = (char)ui->ui_slave;
	dcb->trailcnt = (char)0;
	mdcb->firstdcb = (struct fmt_dcb *)PHYS(dcb);
	mdcb->vddcstat = 0;
	VDDC_ATTENTION(cntrl_vaddr,PHYS(mdcb))	/* do it */
	POLLTILLDONE(5,"VDSTATUS")
#ifdef notdef
	if (dcb->operrsta & HRDERR) {
		if (vddebug) 
		  printf("vd%d: status error, err=%b\n", ui->ui_unit,
		      dcb->operrsta, ERRBITS);
		return(0);
E 2
I 2
D 6
	if (ci->ctlr_type == UNKNOWN) {
		addr->cdr_reset = 0xffffffff;
		DELAY(1000000);
		if (addr->cdr_reset != (unsigned)0xffffffff) {
			ci->ctlr_type = SMDCTLR;
			ci->overlap_seeks = 0;
			DELAY(1000000);
		} else {
			ci->overlap_seeks = 1;
			ci->ctlr_type = SMD_ECTLR;
			addr->cdr_reserved = 0x0;
			DELAY(3000000);
			addr->cdr_csr = 0;
			addr->mdcb_tcf = AM_ENPDA;
			addr->dcb_tcf = AM_ENPDA;
			addr->trail_tcf = AM_ENPDA;
			addr->data_tcf = AM_ENPDA;
			addr->cdr_ccf = CCF_STS | XMD_32BIT | BSZ_16WRD |
			    CCF_ENP | CCF_EPE | CCF_EDE | CCF_ECE | CCF_ERR;
		}
I 4
		printf("vd%d: %s controller\n", vi->ui_unit,
E 6
I 6
D 14
	if (!ci->initdone) {
E 14
I 14
	if ((vd->vd_flags&VD_INIT) == 0) {
E 14
D 18
		printf("vd%d: %s controller\n", vi->ui_ctlr,
E 6
D 9
		    ci->ctlr_type == SMDCTLR ? "smd" : "xsmd");
E 9
I 9
D 13
		    ci->ctlr_type == SMDCTLR ? "smd" : "smde");
E 13
I 13
D 14
		    ci->ctlr_type == SMDCTLR ? "VDDC" : "SMDE");
E 13
E 9
E 4
D 6
		if (vdnotrailer(addr,
		    vi->ui_ctlr, vi->ui_slave, INIT, 10) & HRDERR) {
			printf("vd%d: init error\n", vi->ui_unit);
E 6
I 6
		if (vdnotrailer(addr, vi->ui_ctlr, vi->ui_slave, INIT, 10) &
		    HRDERR) {
			printf("vd%d: init error\n", vi->ui_ctlr);
E 6
			return (0);
		}
D 6
		if (vdnotrailer(addr,
		    vi->ui_ctlr, vi->ui_slave, DIAG, 10) & HRDERR) {
			printf("vd%d: diagnostic error\n", vi->ui_unit);
E 6
I 6
		if (vdnotrailer(addr, vi->ui_ctlr, vi->ui_slave, DIAG, 10) &
		    HRDERR) {
			printf("vd%d: diagnostic error\n", vi->ui_ctlr);
E 6
			return (0);
		}
I 6
		ci->initdone = 1;
E 14
I 14
		    vd->vd_type == VDTYPE_VDDC ? "VDDC" : "SMDE");
E 18
I 18
		printf("vd%d: %s controller%s\n", vi->ui_ctlr,
		    vd->vd_type == VDTYPE_VDDC ? "VDDC" : "SMDE",
		    (vd->vd_flags & VD_SCATGATH) ? " with scatter-gather" : "");
E 18
		vd->vd_flags |= VD_INIT;
E 14
E 6
E 2
	}
I 14

E 14
D 2
#endif
	uncache((char *)&mdcb->vddcstat);
	if (mdcb->vddcstat & DRVNRDY) return(0); /* not ready-> non existent */

E 2
	/*
D 2
	 * drive is alive, now get its type!
E 2
D 14
	 * Seek on all drive types starting from the largest one.
D 2
	 * a sucessful seek to the last sector/cylinder/track verifies 
E 2
I 2
	 * a successful seek to the last sector/cylinder/track verifies 
E 2
	 * the drive type connected to this port. 
E 14
I 14
	 * Initialize label enough to do a reset on
	 * the drive.  The remainder of the default
	 * label values will be filled in in vdinit
	 * at attach time.
E 14
	 */
D 2
	for (dsktype = NVDDRV-1; dsktype >= 0; dsktype--) {	
		st = &vdst[dsktype];
		dcb->opcode = RSTCFG;		/* configure drive command */
E 2
I 2
D 14
	for (type = 0; type < nvddrv; type++) {	
		/* XXX */
		if (ci->ctlr_type == SMDCTLR && vdst[type].nsec != 32)
			continue;
		/* XXX */
D 13
		if (!vdconfigure_drive(addr, vi->ui_ctlr, vi->ui_slave, type,0))
E 13
I 13
		if (!vdconfigure_drive(addr, vi->ui_ctlr, vi->ui_slave, type))
E 13
			return (0);
		dcb->opcode = (short)RD;
E 2
		dcb->intflg = NOINT;
D 2
		dcb->operrsta  = 0;
		dcb->trail.resetrail.ncyl = st->ncyl;
		dcb->trail.resetrail.nsurfaces = st->ntrak;
		dcb->devselect = (char)ui->ui_slave;
		dcb->trailcnt = (char)2;
		mdcb->firstdcb = (struct fmt_dcb *)PHYS(dcb);
		VDDC_ATTENTION(cntrl_vaddr,PHYS(mdcb) )	/* do it */
		POLLTILLDONE(3,"RSTCFG")
		if (dcb->operrsta & HRDERR) {
			if (vddebug) 
				printf("vd%d: reset error, err=%b\n", 
				    ui->ui_unit, dcb->operrsta, ERRBITS);
			return(0);
		}
		mdcb->firstdcb = (struct fmt_dcb *)PHYS(dcb);
		dcb->intflg = NOINT;
		dcb->opcode =  RD;
E 2
I 2
		dcb->nxtdcb = (fmt_dcb *)0;	/* end of chain */
E 2
		dcb->operrsta = 0;
D 2
		dcb->devselect = (char)ui->ui_slave;
		dcb->trailcnt = (char)3;
		dcb->trail.rwtrail.memadr = (char *)PHYS(vdbuf);
		dcb->trail.rwtrail.wcount = 256;
		dcb->trail.rwtrail.disk.cylinder = st->ncyl -4;
		dcb->trail.rwtrail.disk.track = st->ntrak -1;
		dcb->trail.rwtrail.disk.sector = 0;
		VDDC_ATTENTION(cntrl_vaddr,PHYS(mdcb) )	/* do it */
		POLLTILLDONE(5,"RD")
if (vddebug) 
	printf("vd%d: cyl %d, trk %d, sec %d, operrsta err=%b\n", 
	   ui->ui_unit, 
	   dcb->trail.rwtrail.disk.cylinder,
	   dcb->trail.rwtrail.disk.track,
	   dcb->trail.rwtrail.disk.sector,
	   dcb->operrsta, ERRBITS);
		if ( (dcb->operrsta & HRDERR) == 0) 
		/* found the drive type! */
E 2
I 2
		dcb->devselect = (char)(vi->ui_slave);
		dcb->trailcnt = (char)(sizeof (trrw) / sizeof (long));
		dcb->trail.rwtrail.memadr = (char *)PHYS(ci->rawbuf); 
		dcb->trail.rwtrail.wcount = vdst[type].secsize/sizeof(short);
		dcb->trail.rwtrail.disk.cylinder = vdst[type].ncyl - 2;
		dcb->trail.rwtrail.disk.track = vdst[type].ntrak - 1;
		dcb->trail.rwtrail.disk.sector = vdst[type].nsec - 1;
		mdcb->firstdcb = (fmt_dcb *)(PHYS(dcb));
		mdcb->vddcstat = 0;
		VDDC_ATTENTION(addr, (fmt_mdcb *)(PHYS(mdcb)), ci->ctlr_type);
D 6
		POLLTILLDONE(addr, dcb, 60, ci->ctlr_type);
		if (vdtimeout <= 0)
E 6
I 6
		if (!vdpoll(ci, addr, 60))
E 6
			printf(" during probe\n");
		if ((dcb->operrsta&HRDERR) == 0)
E 2
			break;
	}
D 2
	if (dsktype < 0) {
		/* If reached here, a drive which is not defined in the 
E 2
I 2
	if (type >= nvddrv) {
		/*
		 * If reached here, a drive which is not defined in the 
E 2
D 10
		 * 'vdst' tables is connected. Cannot set it's type.
E 10
I 10
		 * 'vdst' tables is connected. Cannot set its type.
E 10
		 */
D 2
		printf("vd%d: unrecognized drive type\n", ui->ui_unit);
		return(0);
E 2
I 2
D 9
		printf("vd%d: unknown drive type\n", vi->ui_unit);
E 9
I 9
		printf("dk%d: unknown drive type\n", vi->ui_unit);
E 9
		return (0);
E 2
	}
D 2
	ui->ui_type = dsktype;
	vddriver.ud_dname = st->name;
	return(1);
E 2
I 2
	ui->drive_type = type;
	ui->info = vdst[type];
	ui->sec_per_blk = DEV_BSIZE / ui->info.secsize;
	vi->ui_type = type;
 	vi->ui_dk = 1;
D 9
	vddriver.ud_dname = ui->info.type_name;
E 9
	return (1);
E 14
I 14
D 20
	lp->d_secsize = DEV_BSIZE / 2;		/* XXX */
I 17
D 18
if (vi->ui_ctlr)
lp->d_nsectors = 48;
else
E 18
E 17
	lp->d_nsectors = 32;
E 20
I 20
	if (vd->vd_type == VDTYPE_SMDE)
		lp->d_secsize = VD_MAXSECSIZE;
	else
		lp->d_secsize = VDDC_SECSIZE;
D 23
	lp->d_nsectors = 72;		/* only used on smd-e */
E 20
	lp->d_ntracks = 24;
E 23
I 23
D 25
	lp->d_nsectors = 68;		/* only used on smd-e */
E 25
I 25
	lp->d_nsectors = 66;		/* only used on smd-e */
E 25
	lp->d_ntracks = 23;
E 23
D 20
	lp->d_ncylinders = 711;
	lp->d_secpercyl = 32*24;
	return (vdreset_drive(vi));
E 14
E 2
}
E 20
I 20
D 25
	lp->d_ncylinders = 842;
D 23
	lp->d_secpercyl = 72*24;
E 23
I 23
	lp->d_secpercyl = 68*23;
E 25
I 25
	lp->d_ncylinders = 850;
	lp->d_secpercyl = 66*23;
I 31
	lp->d_npartitions = 1;
	lp->d_partitions[0].p_offset = 0;
	lp->d_partitions[0].p_size = LABELSECTOR + 1;
E 31
E 25
E 23
E 20

D 2
vdattach(ui)
struct vba_device *ui;
E 2
I 2
D 13
vdconfigure_drive(addr, ctlr, slave, type, pass)
E 13
I 13
D 14
vdconfigure_drive(addr, ctlr, slave, type)
E 13
	register cdr *addr;
D 13
	int ctlr, slave, type, pass;
E 13
I 13
	int ctlr, slave, type;
E 14
I 14
D 17
/*
 * Read pack label.
 */
E 17
D 20
vdattach(vi)
	register struct vba_device *vi;
E 14
E 13
E 2
{
D 2
	if (ui->ui_dk >= 0)
		dk_mspw[ui->ui_dk] = .0000020345;	/* BAD VALUE */
E 2
I 2
D 14
	register ctlr_tab *ci = &vdctlr_info[ctlr];
E 14
I 14
	register int unit = vi->ui_unit;
	register struct dksoftc *dk = &dksoftc[unit];
	register struct disklabel *lp;
E 14

E 20
D 14
	ci->ctlr_dcb.opcode = RSTCFG;		/* command */
	ci->ctlr_dcb.intflg = NOINT;
	ci->ctlr_dcb.nxtdcb = (fmt_dcb *)0;	/* end of chain */
	ci->ctlr_dcb.operrsta = 0;
	ci->ctlr_dcb.devselect = (char)slave;
	ci->ctlr_dcb.trail.rstrail.ncyl = vdst[type].ncyl;
	ci->ctlr_dcb.trail.rstrail.nsurfaces = vdst[type].ntrak;
	if (ci->ctlr_type == SMD_ECTLR) {
D 10
		ci->ctlr_dcb.trailcnt = (char)4;
E 10
I 10
		ci->ctlr_dcb.trailcnt = (char)5;
E 10
		ci->ctlr_dcb.trail.rstrail.nsectors = vdst[type].nsec;
		ci->ctlr_dcb.trail.rstrail.slip_sec = vdst[type].nslip;
I 10
		ci->ctlr_dcb.trail.rstrail.recovery = 0x18f;
E 10
	} else
		ci->ctlr_dcb.trailcnt = (char)2;
	ci->ctlr_mdcb.firstdcb = (fmt_dcb *)(PHYS(&ci->ctlr_dcb));
	ci->ctlr_mdcb.vddcstat = 0;
	VDDC_ATTENTION(addr, (fmt_mdcb *)(PHYS(&ci->ctlr_mdcb)), ci->ctlr_type);
D 6
	POLLTILLDONE(addr, &ci->ctlr_dcb, 5, ci->ctlr_type);
	if (vdtimeout <= 0) {
E 6
I 6
	if (!vdpoll(ci, addr, 5)) {
E 6
		printf(" during config\n");
		return (0);
E 14
I 14
D 15
	if (vdwstart == 0) {
		timeout(vdwatch, (caddr_t)0, hz);
		vdwstart++;
E 14
	}
E 15
D 14
	if (ci->ctlr_dcb.operrsta & HRDERR) {
I 13
		if (ci->ctlr_type == SMD_ECTLR &&
		    (addr->cdr_status[slave] & STA_US) == 0) /* not selected */
			return (0);
E 13
		if ((ci->ctlr_dcb.operrsta & (NOTCYLERR|DRVNRDY)) == 0)
			printf("vd%d: drive %d: config error\n", ctlr, slave);
D 13
		else if (pass == 0) {
			vdstart_drive(addr, ctlr, slave);
			return (vdconfigure_drive(addr, ctlr, slave, type, 1));
		} else if (pass == 2)
			return (vdconfigure_drive(addr, ctlr, slave, type, 3));
E 13
I 13
		else if (vdctlr_info[ctlr].ctlr_started == 0)
			return (vdstart_drives(addr, ctlr) &&
			    vdconfigure_drive(addr, ctlr, slave, type));
E 13
		return (0);
E 14
I 14
	/*
D 17
	 * Try to initialize device and read pack label.
	 */
	if (vdinit(vdminor(unit, 0), 0) != 0) {
		printf(": unknown drive type");
		return;
E 14
	}
D 14
	return (1);
E 14
I 14
	/*
E 17
	 * Initialize invariant portion of
	 * dcb used for overlapped seeks.
	 */
	dk->dk_dcb.opcode = VDOP_SEEK;
	dk->dk_dcb.intflg = DCBINT_NONE | DCBINT_PBA;
	dk->dk_dcb.devselect = vi->ui_slave;
D 18
	dk->dk_dcb.trailcnt = sizeof (trseek) / sizeof (long);
E 18
I 18
	dk->dk_dcb.trailcnt = sizeof (struct trseek) / sizeof (long);
E 18
	dk->dk_dcb.trail.sktrail.skaddr.sector = 0;
	dk->dk_dcbphys = vtoph((struct proc *)0, (unsigned)&dk->dk_dcb);
I 20
#ifndef SECSIZE
	vd_setsecsize(dk, lp);
#endif
	return (vdreset_drive(vi));
}

vdattach(vi)
	register struct vba_device *vi;
{
	register int unit = vi->ui_unit;
	register struct disklabel *lp = &dklabel[unit];

E 20
I 17
	/*
	 * Try to initialize device and read pack label.
	 */
	if (vdinit(vdminor(unit, 0), 0) != 0) {
		printf(": unknown drive type");
		return;
	}
E 17
D 20
	lp = &dklabel[unit];
	printf(": %s <ntrak %d, ncyl %d, nsec %d>",
	    lp->d_typename, lp->d_ntracks, lp->d_ncylinders, lp->d_nsectors);
E 20
I 20
	if (dksoftc[unit].dk_state == OPEN)
		printf(": %s <secsize %d, ntrak %d, ncyl %d, nsec %d>",
		    lp->d_typename, lp->d_secsize,
		    lp->d_ntracks, lp->d_ncylinders, lp->d_nsectors);
E 20
	/*
	 * (60 / rpm) / (sectors per track * (bytes per sector / 2))
	 */
	if (vi->ui_dk >= 0)
		dk_mspw[vi->ui_dk] = 120.0 /
		    (lp->d_rpm * lp->d_nsectors * lp->d_secsize);
#ifdef notyet
D 15
	addwap(makedev(VDMAJOR, vdminor(unit, 0)), &dklabel[unit]);
E 15
I 15
	addswap(makedev(VDMAJOR, vdminor(unit, 0)), lp);
E 15
#endif
E 14
E 2
}

I 2
D 13
vdstart_drive(addr, ctlr, slave)
E 13
I 13
D 14
vdstart_drives(addr, ctlr)
E 13
	cdr *addr;
D 13
	register int ctlr, slave;
E 13
I 13
	register int ctlr;
E 14
I 14
D 18
/*ARGSUSED*/
vdopen(dev, flags)
E 18
I 18
vdopen(dev, flags, fmt)
E 18
	dev_t dev;
D 18
	int flags;
E 18
I 18
	int flags, fmt;
E 18
E 14
E 13
{
D 14
	int error = 0;
E 14
I 14
	register unit = vdunit(dev);
	register struct disklabel *lp;
	register struct dksoftc *dk;
	register struct partition *pp;
	struct vba_device *vi;
D 18
	int s, error, part = vdpart(dev);
E 18
I 18
	int s, error, part = vdpart(dev), mask = 1 << part;
E 18
	daddr_t start, end;
E 14

D 13
	printf("vd%d: starting drive %d, wait...", ctlr, slave);
	if (vdctlr_info[ctlr].ctlr_started) {
I 10
#ifdef notdef
E 10
printf("DELAY(5500000)...");
		DELAY(5500000);
I 10
#endif
E 10
		goto done;
E 13
I 13
D 14
	if (vdctlr_info[ctlr].ctlr_started == 0) {
		printf("vd%d: starting drives, wait ... ", ctlr);
		vdctlr_info[ctlr].ctlr_started = 1;
		error = (vdnotrailer(addr, ctlr, 0, VDSTART, 10) & HRDERR);
		DELAY(62000000);
		printf("\n");
E 14
I 14
	if (unit >= NDK || (vi = vddinfo[unit]) == 0 || vi->ui_alive == 0)
		return (ENXIO);
	lp = &dklabel[unit];
	dk = &dksoftc[unit];

	s = spl7();
	while (dk->dk_state != OPEN && dk->dk_state != OPENRAW &&
	    dk->dk_state != CLOSED)
		sleep((caddr_t)dk, PZERO+1);
	splx(s);
	if (dk->dk_state != OPEN && dk->dk_state != OPENRAW)
		if (error = vdinit(dev, flags))
			return (error);
I 15

	if (vdwstart == 0) {
		timeout(vdwatch, (caddr_t)0, hz);
		vdwstart++;
	}
E 15
	/*
	 * Warn if a partion is opened
	 * that overlaps another partition which is open
	 * unless one is the "raw" partition (whole disk).
	 */
D 20
#define	RAWPART		2		/* 'c' partition */	/* XXX */
E 20
I 20
#define	RAWPART		8		/* 'x' partition */	/* XXX */
E 20
D 21
	if ((dk->dk_openpart & (1 << part)) == 0 &&
	    part != RAWPART) {
E 21
I 21
	if ((dk->dk_openpart & mask) == 0 && part != RAWPART) {
E 21
		pp = &lp->d_partitions[part];
		start = pp->p_offset;
		end = pp->p_offset + pp->p_size;
		for (pp = lp->d_partitions;
		     pp < &lp->d_partitions[lp->d_npartitions]; pp++) {
			if (pp->p_offset + pp->p_size <= start ||
			    pp->p_offset >= end)
				continue;
			if (pp - lp->d_partitions == RAWPART)
				continue;
			if (dk->dk_openpart & (1 << (pp - lp->d_partitions)))
				log(LOG_WARNING,
				    "dk%d%c: overlaps open partition (%c)\n",
				    unit, part + 'a',
				    pp - lp->d_partitions + 'a');
		}
E 14
E 13
	}
D 13
	vdctlr_info[ctlr].ctlr_started = 1;
	error = vdnotrailer(addr, ctlr, 0, VDSTART, (slave*6)+62) & HRDERR;
	if (!error) {
D 10
printf("DELAY(%d)...", (slave * 5500000) + 62000000);
E 10
I 10
#ifdef notdef
E 10
		DELAY((slave * 5500000) + 62000000);
I 10
#endif
E 10
	}
done:
	printf("\n");
E 13
D 14
	return (error == 0);
E 14
I 14
	if (part >= lp->d_npartitions)
		return (ENXIO);
D 18
	dk->dk_openpart |= 1 << part;
E 18
I 18
	dk->dk_openpart |= mask;
	switch (fmt) {
	case S_IFCHR:
		dk->dk_copenpart |= mask;
		break;
	case S_IFBLK:
		dk->dk_bopenpart |= mask;
		break;
	}
E 18
	return (0);
E 14
}

I 27
/* ARGSUSED */
E 27
D 13
vdnotrailer(addr, ctlr, unit, function, time)
E 13
I 13
D 14
vdnotrailer(addr, ctlr, unit, function, t)
E 13
	register cdr *addr;
D 13
	int ctlr, unit, function, time;
E 13
I 13
	int ctlr, unit, function, t;
E 14
I 14
D 18
vdclose(dev, flags)
E 18
I 18
vdclose(dev, flags, fmt)
E 18
	dev_t dev;
D 18
	int flags;
E 18
I 18
	int flags, fmt;
E 18
E 14
E 13
{
D 6
	fmt_mdcb *mdcb = &vdctlr_info[ctlr].ctlr_mdcb;
	fmt_dcb *dcb = &vdctlr_info[ctlr].ctlr_dcb;
	int type = vdctlr_info[ctlr].ctlr_type;
E 6
I 6
D 14
	register ctlr_tab *ci = &vdctlr_info[ctlr];
	fmt_mdcb *mdcb = &ci->ctlr_mdcb;
	fmt_dcb *dcb = &ci->ctlr_dcb;
E 14
I 14
	register int unit = vdunit(dev);
	register struct dksoftc *dk = &dksoftc[unit];
I 17
D 18
	int part = vdpart(dev);
E 18
I 18
	int part = vdpart(dev), mask = 1 << part;
E 18
E 17
E 14
E 6

I 18
	switch (fmt) {
	case S_IFCHR:
		dk->dk_copenpart &= ~mask;
		break;
	case S_IFBLK:
		dk->dk_bopenpart &= ~mask;
		break;
	}
	if (((dk->dk_copenpart | dk->dk_bopenpart) & mask) == 0)
		dk->dk_openpart &= ~mask;
E 18
D 14
	dcb->opcode = function;		/* command */
	dcb->intflg = NOINT;
	dcb->nxtdcb = (fmt_dcb *)0;	/* end of chain */
	dcb->operrsta = 0;
	dcb->devselect = (char)unit;
	dcb->trailcnt = (char)0;
	mdcb->firstdcb = (fmt_dcb *)(PHYS(dcb));
	mdcb->vddcstat = 0;
D 6
	VDDC_ATTENTION(addr, (fmt_mdcb *)(PHYS(mdcb)), type);
	POLLTILLDONE(addr, dcb, time, type);
	if (vdtimeout <= 0) {
E 6
I 6
	VDDC_ATTENTION(addr, (fmt_mdcb *)(PHYS(mdcb)), ci->ctlr_type);
D 13
	if (!vdpoll(ci, addr, time)) {
E 13
I 13
	if (!vdpoll(ci, addr, t)) {
E 13
E 6
		printf(" during init\n");
		return (DCBCMP|ANYERR|HRDERR|OPABRT);
E 14
I 14
D 17
	dk->dk_openpart &= ~(1 << vdpart(dev));
E 17
D 15
#ifdef notdef
E 15
	/*
	 * Should wait for i/o to complete on this partition
	 * even if others are open, but wait for work on blkflush().
	 */
	if (dk->dk_openpart == 0) {
D 15
		struct vba_device *vi = vddinfo[unit];
		int s;

		s = spl7();
		/* can't sleep on b_actf, it might be async. */
		while (vi->ui_tab.b_actf)
			sleep((caddr_t)&vi->ui_tab.b_actf, PZERO-1);
E 15
I 15
		int s = spl7();
		while (dkutab[unit].b_actf)
			sleep((caddr_t)dk, PZERO-1);
E 15
		splx(s);
		dk->dk_state = CLOSED;
I 23
		dk->dk_wlabel = 0;
E 23
E 14
	}
I 18
	return (0);
E 18
D 14
	return (dcb->operrsta);
E 14
I 14
D 15
#endif
E 15
E 14
}

I 17
D 18
/*
 * Read pack label.
 */
E 18
E 17
D 14
vdattach(vi)
	register struct vba_device *vi;
E 14
I 14
vdinit(dev, flags)
	dev_t dev;
	int flags;
E 14
{
D 14
	register unit_tab *ui = &vdunit_info[vi->ui_unit];
	register ctlr_tab *ci = &vdctlr_info[vi->ui_ctlr];
	register struct buf *cq = &vi->ui_mi->um_tab;
	register struct buf *uq = cq->b_forw;
	register struct buf *start_queue = uq;
	register fs_tab	*fs = &ui->info;
E 14
I 14
D 18
	register struct buf *bp = NULL;
E 18
	register struct disklabel *lp;
	register struct dksoftc *dk;
	struct vba_device *vi;
D 18
	struct disklabel *dlp;
E 18
	int unit = vdunit(dev), error = 0;
I 17
D 18
	char *msg = "no disk label";
E 18
I 18
	char *msg, *readdisklabel();
E 18
E 17
	extern int cold;
E 14

D 14
	ui->info = vdst[vi->ui_type];
	ui->sec_per_blk = DEV_BSIZE / ui->info.secsize;
	ui->sec_per_cyl = ui->info.nsec * ui->info.ntrak;
	ui->xfer_queue.b_dev = vi->ui_slave;
	ci->unit_type[vi->ui_slave] = vi->ui_type;
	/* load unit into controller's active unit list */
	if (uq == NULL) {
		cq->b_forw = &ui->xfer_queue;
		ui->xfer_queue.b_forw = &ui->xfer_queue;
		ui->xfer_queue.b_back = &ui->xfer_queue;
E 14
I 14
	dk = &dksoftc[unit];
I 18
D 20
#ifndef SECSIZE
	dk->dk_bshift = 1;		/* DEV_BSIZE / 512 */
#endif SECSIZE
E 20
E 18
	if (flags & O_NDELAY) {
		dk->dk_state = OPENRAW;
D 18
		goto done;
E 18
I 18
D 27
		return;
E 27
I 27
		return (0);
E 27
E 18
	}
D 18

	/*
	 * Initialize portion of the label
	 * not set up in the slave routine.
	 */
E 18
D 15
	dk->dk_bshift = 1;		/* DEV_BSIZE / 512 */
E 15
	dk->dk_state = RDLABEL;
	lp = &dklabel[unit];
D 18
	lp->d_secperunit = 0x1fffffff;
	lp->d_npartitions = 1;
	lp->d_partitions[0].p_size = 0x1fffffff;
	lp->d_partitions[0].p_offset = 0;

	bp = geteblk(DEV_BSIZE);		/* max sector size */
	bp->b_dev = dev;
	bp->b_blkno = LABELSECTOR;
	bp->b_bcount = DEV_BSIZE;
	bp->b_flags = B_BUSY | B_READ;
	bp->b_cylin = LABELSECTOR / lp->d_secpercyl;
	vdstrategy(bp);
	biowait(bp);
	if (bp->b_flags & B_ERROR) {
		error = u.u_error;		/* XXX */
		u.u_error = 0;
		dk->dk_state = CLOSED;
		goto done;
	}
E 18
	vi = vddinfo[unit];
D 18
	dlp = (struct disklabel *)(bp->b_un.b_addr + LABELOFFSET);
	if (dlp->d_magic == DISKMAGIC && dlp->d_magic2 == DISKMAGIC &&
	    dkcksum(dlp) == 0) {
		*lp = *dlp;
		/*
		 * Now that we have the label, configure
		 * the correct drive parameters.
		 */
		if (!vdreset_drive(vi))
			dk->dk_state = CLOSED;
		else
			dk->dk_state = OPEN;
E 14
	} else {
I 17
		if (dlp->d_magic == DISKMAGIC && dlp->d_magic2 == DISKMAGIC)
			msg = "disk label corrupted";
E 18
I 18
	if (msg = readdisklabel(dev, vdstrategy, lp)) {
E 18
E 17
D 14
		while (uq->b_forw != start_queue)
			uq = uq->b_forw;
		ui->xfer_queue.b_forw = start_queue;
		ui->xfer_queue.b_back = uq;
		uq->b_forw = &ui->xfer_queue;
		start_queue->b_back = &ui->xfer_queue;
E 14
I 14
D 23
		if (cold)
E 23
I 23
		if (cold) {
E 23
D 17
			printf(": no disk label");
E 17
I 17
			printf(": %s", msg);
E 17
D 23
		else
E 23
I 23
			dk->dk_state = CLOSED;
		} else {
E 23
D 17
			log(LOG_ERR, "dk%d: no disk label\n", vi->ui_unit);
E 17
I 17
D 20
			log(LOG_ERR, "dk%d: %s\n", vi->ui_unit, msg);
E 20
I 20
			log(LOG_ERR, "dk%d: %s\n", unit, msg);
E 20
D 18
printf("data %x %x %x, magic %x\n", bp->b_un.b_words[0], bp->b_un.b_words[1], bp->b_un.b_words[2], dlp->d_magic);
E 18
E 17
D 23
#ifdef COMPAT_42
D 18
		if (!vdmaptype(vi, lp)) {
			error = ENXIO;
			dk->dk_state = CLOSED;
		} else
E 18
I 18
		if (!vdmaptype(vi, lp))
E 23
			dk->dk_state = OPENRAW;
D 23
		else
E 23
I 23
		}
#ifdef COMPAT_42
I 38
		vdlock(vi->ui_ctlr);
E 38
		if (vdmaptype(vi, lp))
E 23
E 18
			dk->dk_state = OPEN;
I 38
		vdunlock(vi->ui_ctlr);
E 38
D 23
#else
		dk->dk_state = OPENRAW;
E 23
#endif
I 18
	} else {
		/*
		 * Now that we have the label, configure
		 * the correct drive parameters.
		 */
I 38
		vdlock(vi->ui_ctlr);
E 38
D 20
		if (!vdreset_drive(vi)) {
E 20
I 20
		if (vdreset_drive(vi))
			dk->dk_state = OPEN;
		else {
E 20
			dk->dk_state = CLOSED;
			error = ENXIO;
D 20
		} else
			dk->dk_state = OPEN;
E 20
I 20
		}
I 38
		vdunlock(vi->ui_ctlr);
E 38
E 20
E 18
E 14
	}
I 9
D 10
	printf("dk%d: %s\n", vi->ui_unit, fs->type_name);
E 10
I 10
D 13
	printf("dk%d: %s <ntrak %d, ncyl %d, nsec %d>\n",
	    vi->ui_unit, fs->type_name,
	    ui->info.ntrak, ui->info.ncyl, ui->info.nsec);
E 13
I 13
D 14
	printf(": %s <ntrak %d, ncyl %d, nsec %d>",
	    fs->type_name, ui->info.ntrak, ui->info.ncyl, ui->info.nsec);
E 14
I 14
D 18
done:
E 14
E 13
E 10
E 9
D 15
	/*
D 14
	 * (60 / rpm) / (number of sectors per track * (bytes per sector / 2))
E 14
I 14
	 * If open, calculate scaling shift for
	 * mapping DEV_BSIZE blocks to drive sectors.
E 14
	 */
D 14
	dk_mspw[vi->ui_unit] = 120.0 / (fs->rpm * fs->nsec * fs->secsize);
E 14
I 14
	if (dk->dk_state == OPEN || dk->dk_state == OPENRAW) {
		int mul = DEV_BSIZE / lp->d_secsize;
		dk->dk_bshift = 0;
		while ((mul >>= 1) > 0)
			dk->dk_bshift++;
	}
E 15
	if (bp) {
		bp->b_flags = B_INVAL | B_AGE;
		brelse(bp);
E 18
I 18
#ifndef SECSIZE
D 20
	/*
	 * If open, calculate scaling shift for
	 * mapping DEV_BSIZE blocks to drive sectors.
	 */
	if (dk->dk_state == OPEN || dk->dk_state == OPENRAW) {
		int mul = DEV_BSIZE / lp->d_secsize;
		dk->dk_bshift = 0;
		while ((mul >>= 1) > 0)
			dk->dk_bshift++;
E 18
	}
I 18
#endif SECSIZE
E 20
I 20
	vd_setsecsize(dk, lp);
#endif
E 20
E 18
	wakeup((caddr_t)dk);
	return (error);
E 14
}

I 20
#ifndef SECSIZE
vd_setsecsize(dk, lp)
	register struct dksoftc *dk;
	register struct disklabel *lp;
{
	int mul;

	/*
	 * Calculate scaling shift for mapping
	 * DEV_BSIZE blocks to drive sectors.
	 */
	mul = DEV_BSIZE / lp->d_secsize;
	dk->dk_bshift = 0;
	while ((mul >>= 1) > 0)
		dk->dk_bshift++;
}
#endif SECSIZE

E 20
/*ARGSUSED*/
E 2
D 14
vddgo(um)
D 2
struct vba_ctlr *um;
E 2
I 2
	struct vba_ctlr *um;
E 14
I 14
vddgo(vm)
	struct vba_device *vm;
E 14
E 2
{
I 2

E 2
}

vdstrategy(bp)
D 2
register struct buf *bp;
E 2
I 2
	register struct buf *bp;
E 2
{
D 2
	register struct vba_device *ui;
	register struct vba_ctlr *um;
	register int unit;
	register struct buf *dp;
	register struct size *sizep;
	int index, blocks, s;
E 2
I 2
D 14
	register int unit = VDUNIT(bp->b_dev);
	register struct vba_device *vi = vddinfo[unit];
	register par_tab *par;
	register unit_tab *ui;
	register fs_tab *fs;
	register int blks, bn, s;
E 14
I 14
	register struct vba_device *vi;
	register struct disklabel *lp;
	register struct dksoftc *dk;
	register int unit;
I 15
	register daddr_t sn;
E 15
	struct buf *dp;
D 15
	daddr_t sz, sn, maxsz;
E 15
I 15
	daddr_t sz, maxsz;
E 15
	int part, s;
E 14
E 2

D 2
	vdintflg = 1;		/* enable interrupts handling by the driver */
	blocks = (bp->b_bcount + DEV_BSIZE - 1) >> DEV_BSHIFT;
	unit = VDUNIT(bp->b_dev);
	ui = vddinfo[unit];
	if (ui == 0 || ui->ui_alive == 0) goto bad1;
	index = FLSYS(bp->b_dev); /* get file system index */
	sizep = vdst[ui->ui_type].sizes;
	if (bp->b_blkno < 0 ||
	 (dkblock(bp)+blocks > sizep[index].nblocks))	/* disk overflow */
		goto bad1;
	s = spl8();
	dp = &vdutab[ui->ui_unit];
	bp->b_resid = bp->b_blkno + sizep[index].block0; 
					/* block # plays same role as
					   cylinder # for disksort, as long
					   as increasing blocks correspond to
					   increasing cylinders on disk */
E 2
I 2
D 12
	if (bp->b_bcount == 0 || vi == 0 || vi->ui_alive == 0)
E 12
I 12
D 14
	if (bp->b_bcount == 0 || vi == 0 || vi->ui_alive == 0) {
E 14
I 14
D 17
	sz = bp->b_bcount;
	sz = (sz + DEV_BSIZE - 1) >> DEV_BSHIFT;
E 17
	unit = vdunit(bp->b_dev);
D 20
	if (unit > NDK) {
E 20
I 20
	if (unit >= NDK) {
E 20
E 14
		bp->b_error = ENXIO;
E 12
		goto bad;
I 12
	}
E 12
D 14
	ui = &vdunit_info[unit];
	fs = &ui->info;
	par = &fs->partition[FILSYS(bp->b_dev)];
	blks = (bp->b_bcount + DEV_BSIZE-1) >> DEV_BSHIFT;
D 12
	if (bp->b_blkno + blks >= par->par_len) {
E 12
I 12
	if ((unsigned) bp->b_blkno + blks > par->par_len) {
		if (bp->b_blkno == par->par_len) {
E 14
I 14
	vi = vddinfo[unit];
	lp = &dklabel[unit];
	if (vi == 0 || vi->ui_alive == 0) {
		bp->b_error = ENXIO;
		goto bad;
	}
I 17
D 20
	sz = (bp->b_bcount + lp->d_secsize - 1) / lp->d_secsize;
E 20
E 17
	dk = &dksoftc[unit];
	if (dk->dk_state < OPEN)
		goto q;
I 23
	if (dk->dk_state != OPEN && (bp->b_flags & B_READ) == 0) {
		bp->b_error = EROFS;
		goto bad;
	}
E 23
	part = vdpart(bp->b_dev);
	if ((dk->dk_openpart & (1 << part)) == 0) {
		bp->b_error = ENODEV;
		goto bad;
	}
I 20
	sz = (bp->b_bcount + lp->d_secsize - 1) / lp->d_secsize;
E 20
	maxsz = lp->d_partitions[part].p_size;
I 18
#ifndef SECSIZE
	sn = bp->b_blkno << dk->dk_bshift;
#else SECSIZE
E 18
D 15
	sn = bp->b_blkno << dk->dk_bshift;
E 15
I 15
	sn = bp->b_blkno;
I 18
#endif SECSIZE
I 23
	if (sn + lp->d_partitions[part].p_offset <= LABELSECTOR &&
#if LABELSECTOR != 0
	    sn + lp->d_partitions[part].p_offset + sz > LABELSECTOR &&
#endif
	    (bp->b_flags & B_READ) == 0 && dk->dk_wlabel == 0) {
		bp->b_error = EROFS;
		goto bad;
	}
E 23
E 18
E 15
	if (sn < 0 || sn + sz > maxsz) {
		if (sn == maxsz) {
E 14
			bp->b_resid = bp->b_bcount;
			goto done;
		}
D 13
#ifdef notdef
		/*
		 * I'm not sure I want to smash bp->b_bcount.
		 */
E 13
E 12
D 14
		blks = par->par_len - bp->b_blkno;
D 12
		if (blks <= 0)
E 12
I 12
		if (blks <= 0) {
			bp->b_error = EINVAL;
E 12
			goto bad;
I 12
		}
E 12
		bp->b_bcount = blks * DEV_BSIZE;
E 14
I 14
D 15
		bp->b_error = EINVAL;
		goto bad;
E 15
I 15
D 18
		sz = maxsz - bp->b_blkno;
E 18
I 18
		sz = maxsz - sn;
E 18
		if (sz <= 0) {
			bp->b_error = EINVAL;
			goto bad;
		}
		bp->b_bcount = sz * lp->d_secsize;
E 15
E 14
I 12
D 13
#else
		bp->b_error = EINVAL;
		goto bad;
#endif
E 13
E 12
	}
D 14
	bn = bp->b_blkno + par->par_start;
	bn *= ui->sec_per_blk;
	bp->b_daddr = (bn / fs->nsec) % fs->ntrak;
	bp->b_cylin = bn / ui->sec_per_cyl;
	vbasetup(bp, ui->info.secsize);
E 14
I 14
	bp->b_cylin = (sn + lp->d_partitions[part].p_offset) / lp->d_secpercyl;
I 18
#ifdef SECSIZE
if (bp->b_blksize != lp->d_secsize && (bp->b_flags & B_PGIN) == 0)
panic("vdstrat blksize");
#endif SECSIZE
E 18
q:
D 17
	vbasetup(bp, lp->d_secsize);
E 17
E 14
	s = spl7();
D 14
	if (ui->xfer_queue.av_forw == NULL) {
		register ctlr_tab *ci = &vdctlr_info[vi->ui_ctlr];
		int slave = vi->ui_slave;
E 2

D 2
	buf_setup (bp, SECTSIZ);

	disksort(dp, bp);
	if (dp->b_active == 0) {	/* unit is on controller queue */
		/* put the device on the controller queue */
		dp->b_forw = NULL;		/* end of queue indicator */
		um = ui->ui_mi;		/* get controller structure !! */
		if (um->um_tab.b_actf == NULL)	/* controller queue is empty */
			um->um_tab.b_actf = dp; 
		else
			um->um_tab.b_actl->b_forw = dp; /* add into queue */
		um->um_tab.b_actl = dp;		/* update queue tail */
		dp->b_active ++;
E 2
I 2
		if (bp->b_cylin != ci->cur_cyl[slave] ||
		    bp->b_daddr != ci->cur_trk[slave])
			ci->off_cylinder |= 1 << slave;
E 14
I 14
	dp = &dkutab[vi->ui_unit];
	disksort(dp, bp);
	if (!dp->b_active) {
		(void) vdustart(vi);
D 15
		bp = &vi->ui_mi->um_tab;
		if (bp->b_actf && !bp->b_active)
E 15
I 15
		if (!vi->ui_mi->um_tab.b_active)
E 15
			vdstart(vi->ui_mi);
E 14
E 2
	}
D 2
	bp = &ui->ui_mi->um_tab;	/* controller structure addr */
	if (bp->b_actf && 		/* cntrl queue not empty */
		bp->b_active == 0)	/* controller not active */
		(void) vdstart(ui->ui_mi);/* go start I/O */
	splx(s);
E 2
I 2
D 14
	bp->b_daddr |= (bn % fs->nsec) << 8;
	disksort(&ui->xfer_queue, bp);
	if (!vddinfo[unit]->ui_mi->um_tab.b_active++) {
		splx(s);
		vdstart(vddinfo[unit]->ui_mi);
	} else
		splx(s);
E 14
I 14
	splx(s);
E 14
E 2
	return;
D 2

bad1:
	bp->b_flags |= B_ERROR;
E 2
I 2
bad:	
D 12
	bp->b_flags |= B_ERROR, bp->b_error = ENXIO;
	bp->b_resid = bp->b_bcount;
E 12
I 12
	bp->b_flags |= B_ERROR;
done:
E 12
E 2
D 14
	iodone(bp);
E 14
I 14
	biodone(bp);
	return;
E 14
D 2
	return;
E 2
}

D 2

E 2
D 14
/*
 * Start up a transfer on a drive.
 */
D 2
vdstart(um)
register struct vba_ctlr *um;
E 2
I 2
vdstart(ci)
	register struct vba_ctlr *ci;
E 14
I 14
vdustart(vi)
	register struct vba_device *vi;
E 14
E 2
{
D 2
	register struct buf *bp, *dp;
	register struct fmt_dcb *dcb = &dcbx[um->um_ctlr];
	register struct fmt_mdcb *mdcb;
	register struct size *sizep;	/* Pointer to one of the tables */
	register struct vdst *st;
	register int index ;		/* Index in the relevant table */
	register int phadr;		/* Buffer's physical address */
	register caddr_t cntrl_vaddr = um->um_addr;
	int	sblock, unit;
	int ct;
E 2
I 2
D 14
	register struct buf *cq = &ci->um_tab;
	register struct buf *uq = cq->b_forw;
E 14
I 14
	register struct buf *bp, *dp;
	register struct vba_ctlr *vm;
	register int unit = vi->ui_unit;
	register struct dksoftc *dk;
	register struct vdsoftc *vd;
	struct disklabel *lp;
E 14
E 2

D 2
loop:
E 2
I 2
D 14
	/* search for next ready unit */
	cq->b_forw = cq->b_forw->b_forw;
	uq = cq->b_forw;
	do {
		if (uq->av_forw != NULL) {
			cq->b_forw = uq;
			vdexecute(ci, uq);
			return;
		}
		uq = uq->b_forw;
	} while (uq != cq->b_forw);
E 14
I 14
D 15
	dk_busy &= ~(1<<vi->ui_dk);
E 15
	dp = &dkutab[unit];
	/*
	 * If queue empty, nothing to do.
	 */
	if ((bp = dp->b_actf) == NULL)
		return;
	/*
D 16
	 * If drive is off-cylinder, mark unit to force
	 * overlap seek with next transfer on this controller.
E 16
I 16
	 * If drive is off-cylinder and controller supports seeks,
	 * place drive on seek queue for controller.
	 * Otherwise, place on transfer queue.
E 16
	 */
	vd = &vdsoftc[vi->ui_ctlr];
	dk = &dksoftc[unit];
I 16
	vm = vi->ui_mi;
E 16
	if (bp->b_cylin != dk->dk_curcyl && vd->vd_flags&VD_DOSEEKS) {
D 15
		int sn = bp->b_blkno << dk->dk_bshift;
E 15
		lp = &dklabel[unit];
D 15
		bp->b_daddr = (sn % lp->d_secpercyl) / lp->d_nsectors;
E 15
I 15
D 16
		bp->b_daddr = (bp->b_blkno % lp->d_secpercyl) / lp->d_nsectors;
E 15
		if (bp->b_daddr != dk->dk_curdaddr)
			vd->vd_offcyl |= 1 << vi->ui_slave;
E 16
I 16
		bp->b_track = (bp->b_blkno % lp->d_secpercyl) / lp->d_nsectors;
		if (vm->um_tab.b_seekf == NULL)
			vm->um_tab.b_seekf = dp;
		else
			vm->um_tab.b_seekl->b_forw = dp;
		vm->um_tab.b_seekl = dp;
	} else {
		if (vm->um_tab.b_actf == NULL)
			vm->um_tab.b_actf = dp;
		else
			vm->um_tab.b_actl->b_forw = dp;
		vm->um_tab.b_actl = dp;
E 16
	}
D 16
	/*
	 * If controller is not busy, place request on the
D 15
	 * controller's ready queue (unless its already there).
E 15
I 15
	 * controller's ready queue).
E 15
	 */
E 16
D 15
	if (!dp->b_active) {
		dp->b_forw = NULL;
		vm = vi->ui_mi;
		if (vm->um_tab.b_actf == NULL)
			vm->um_tab.b_actf = dp;
		else
			vm->um_tab.b_actl->b_forw = dp;
		vm->um_tab.b_actl = dp;
		dp->b_active++;
	}
E 15
I 15
	dp->b_forw = NULL;
D 16
	vm = vi->ui_mi;
	if (vm->um_tab.b_actf == NULL)
		vm->um_tab.b_actf = dp;
	else
		vm->um_tab.b_actl->b_forw = dp;
	vm->um_tab.b_actl = dp;
E 16
	dp->b_active++;
E 15
E 14
}

/*
D 14
 * Initiate seeks for all drives off-cylinder.
E 14
I 14
 * Start next transfer on a controller.
I 16
 * There are two queues of drives, the first on-cylinder
 * and the second off-cylinder from their next transfers.
 * Perform the first transfer for the first drive on the on-cylinder
 * queue, if any, otherwise the first transfer for the first drive
 * on the second queue.  Initiate seeks on remaining drives on the
 * off-cylinder queue, then move them all to the on-cylinder queue.
E 16
E 14
 */
D 14
vdload_seeks(ci, uq)
	register ctlr_tab *ci;
	register struct buf *uq;
E 14
I 14
vdstart(vm)
	register struct vba_ctlr *vm;
E 14
{
D 14
	register int unit, slave, nseeks;
	register fmt_dcb *dcb;
E 14
	register struct buf *bp;
D 14
	register struct buf *start_queue = uq;
E 14
I 14
	register struct vba_device *vi;
	register struct vdsoftc *vd;
	register struct dksoftc *dk;
	register struct disklabel *lp;
D 20
	register int slave;
E 20
	register struct dcb **dcbp;
D 27
	struct mdcb *mdcb;
E 27
	struct buf *dp;
	int sn, tn;
E 14

D 14
	nseeks = 0;
	do {
		bp = uq->av_forw;
		if (bp != NULL) {
			unit = VDUNIT(bp->b_dev);
			slave = vddinfo[unit]->ui_slave;
			if (ci->off_cylinder & (1 << slave)) {
				ci->off_cylinder &= ~(1 << slave);
				if (ci->cur_cyl[slave] != bp->b_cylin) {
					ci->cur_cyl[slave] = bp->b_cylin;
					dk_seek[unit]++;
				}
				ci->cur_trk[slave] = bp->b_daddr&0xff;
				dcb = &ci->seek_dcb[nseeks++];
				dcb->opcode = SEEK;
				dcb->intflg = NOINT | INT_PBA;
				dcb->operrsta = 0;
				dcb->devselect = (char)slave;
				dcb->trailcnt = (char)1;
				dcb->trail.sktrail.skaddr.cylinder =
				    bp->b_cylin;
				dcb->trail.sktrail.skaddr.track =
				    bp->b_daddr & 0xff;
				dcb->trail.sktrail.skaddr.sector = 0;
			}
		}
		uq = uq->b_forw;
	} while (uq != start_queue && nseeks < 4);
	return (nseeks);
}
E 14
I 14
loop:
	/*
	 * Pull a request off the controller queue.
	 */
D 16
	if ((dp = vm->um_tab.b_actf) == NULL)
E 16
I 16
	if ((dp = vm->um_tab.b_actf) == NULL &&
	    (dp = vm->um_tab.b_seekf) == NULL)
E 16
		return;
	if ((bp = dp->b_actf) == NULL) {
D 17
		vm->um_tab.b_actf = dp->b_forw;
E 17
I 17
		if (dp == vm->um_tab.b_actf)
			vm->um_tab.b_actf = dp->b_forw;
		else
			vm->um_tab.b_seekf = dp->b_forw;
E 17
		goto loop;
	}
E 14

D 14
extern	vd_int_timeout();
/*
 * Execute the next command on the unit queue uq.
 */
vdexecute(controller_info, uq)
	register struct vba_ctlr *controller_info;
	register struct buf *uq;
{
	register struct	buf *bp = uq->av_forw;
	register int ctlr = controller_info->um_ctlr;
	register ctlr_tab *ci = &vdctlr_info[ctlr];
	register int unit = VDUNIT(bp->b_dev);
	register int slave = vddinfo[unit]->ui_slave;
	register fmt_mdcb *mdcb = &ci->ctlr_mdcb; 
	register fmt_dcb *dcb = &ci->ctlr_dcb; 
	
E 14
E 2
	/*
D 2
	 * Pull a request off the controller queue
E 2
I 2
D 14
	 * If there are overlapped seeks to perform, shuffle
	 * them to the front of the queue and get them started
	 * before any data transfers (to get some parallelism).
E 14
I 14
	 * Mark controller busy, and determine
	 * destination of this request.
E 14
E 2
	 */
D 2
	if ((dp = um->um_tab.b_actf) == NULL)
		return ;
	if ((bp = dp->b_actf) == NULL) {
		dp->b_active = 0;	/* device removed from ctlr queue */
		um->um_tab.b_actf = dp->b_forw;
		goto loop;
E 2
I 2
D 14
	if ((ci->off_cylinder & ~(1<<slave)) && ci->overlap_seeks) {
		register int i, nseeks;
		
		/* setup seek requests in seek-q */
		nseeks = vdload_seeks(ci, uq);
		/* place at the front of the master q */
		mdcb->firstdcb = (fmt_dcb *)PHYS(&ci->seek_dcb[0]);
		/* shuffle any remaining seeks up in the seek-q */
		for (i = 1; i < nseeks; i++)
			ci->seek_dcb[i-1].nxtdcb = 
			    (fmt_dcb *)PHYS(&ci->seek_dcb[i]);
		ci->seek_dcb[nseeks-1].nxtdcb = (fmt_dcb *)PHYS(dcb);
	} else {
		if (bp->b_cylin != ci->cur_cyl[slave]) {
			ci->cur_cyl[slave] = bp->b_cylin;
			dk_seek[unit]++;
E 14
I 14
	vm->um_tab.b_active++;
	vi = vddinfo[vdunit(bp->b_dev)];
	dk = &dksoftc[vi->ui_unit];
I 18
#ifndef SECSIZE
	sn = bp->b_blkno << dk->dk_bshift;
#else SECSIZE
E 18
D 15
	sn = bp->b_blkno << dk->dk_bshift;
E 15
I 15
	sn = bp->b_blkno;
I 18
#endif SECSIZE
E 18
E 15
	lp = &dklabel[vi->ui_unit];
	sn %= lp->d_secpercyl;
	tn = sn / lp->d_nsectors;
	sn %= lp->d_nsectors;

	/*
	 * Construct dcb for read/write command.
	 */
	vd = &vdsoftc[vm->um_ctlr];
D 20
	slave = vi->ui_slave;
E 20
D 18
	vd->vd_dcb.opcode = (bp->b_flags & B_READ) ? VDOP_RD : VDOP_WD;
E 18
	vd->vd_dcb.intflg = DCBINT_DONE;
D 20
	vd->vd_dcb.devselect = slave;
E 20
I 20
	vd->vd_dcb.devselect = dk->dk_dcb.devselect;
E 20
	vd->vd_dcb.operrsta = 0;
	vd->vd_dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
D 18
	vd->vd_dcb.trailcnt = sizeof (trrw) / sizeof (long);
D 17
	vd->vd_dcb.trail.rwtrail.memadr = (char *)
	    vbastart(bp, vd->vd_rawbuf, (long *)vd->vd_map, vd->vd_utl);
E 17
I 17
	vd->vd_dcb.trail.rwtrail.memadr =
		vbasetup(bp, &vd->vd_rbuf, lp->d_secsize);
E 17
	vd->vd_dcb.trail.rwtrail.wcount = (bp->b_bcount+1) >> 1;
E 18
	vd->vd_dcb.trail.rwtrail.disk.cylinder = bp->b_cylin;
	vd->vd_dcb.trail.rwtrail.disk.track = tn;
	vd->vd_dcb.trail.rwtrail.disk.sector = sn;
I 16
	dk->dk_curcyl = bp->b_cylin;
	bp->b_track = 0;		/* init overloaded field */
I 18
	vd->vd_dcb.trailcnt = sizeof (struct trrw) / sizeof (long);
D 25
	if (vd->vd_flags & VD_SCATGATH &&
	    ((int)bp->b_un.b_addr & (sizeof(long) - 1)) == 0) {
E 25
I 25
	if (bp->b_flags & B_FORMAT)
		vd->vd_dcb.opcode = dk->dk_op;
	else if (vd->vd_flags & VD_SCATGATH &&
	    ((int)bp->b_un.b_addr & (sizeof(long) - 1)) == 0)
E 25
		vd->vd_dcb.opcode = (bp->b_flags & B_READ)? VDOP_RAS : VDOP_GAW;
D 25
		vd->vd_dcb.trailcnt += vba_sgsetup(bp, &vd->vd_rbuf,
		    &vd->vd_dcb.trail.sgtrail);
	} else {
E 25
I 25
	else
E 25
		vd->vd_dcb.opcode = (bp->b_flags & B_READ)? VDOP_RD : VDOP_WD;
I 25

	switch (vd->vd_dcb.opcode) {
	case VDOP_FSECT:
		vd->vd_dcb.trailcnt = sizeof (struct trrw) / sizeof (long);
		vd->vd_dcb.trail.fmtrail.nsectors = bp->b_bcount /
		    lp->d_secsize;
		vd->vd_dcb.trail.fmtrail.hdr = *(dskadr *)&dk->dk_althdr;
		vd->vd_dcb.trail.rwtrail.disk.cylinder |= dk->dk_fmtflags;
		goto setupaddr;

	case VDOP_RDRAW:
	case VDOP_RD:
	case VDOP_WD:
		vd->vd_dcb.trail.rwtrail.wcount = (bp->b_bcount+1) >> 1;
setupaddr:
E 25
		vd->vd_dcb.trail.rwtrail.memadr =
D 27
			vbasetup(bp, &vd->vd_rbuf, lp->d_secsize);
E 27
I 27
			vbasetup(bp, &vd->vd_rbuf, (int)lp->d_secsize);
E 27
D 25
		vd->vd_dcb.trail.rwtrail.wcount = (bp->b_bcount+1) >> 1;
E 25
I 25
		break;

	case VDOP_RAS:
	case VDOP_GAW:
		vd->vd_dcb.trailcnt += vba_sgsetup(bp, &vd->vd_rbuf,
		    &vd->vd_dcb.trail.sgtrail);
		break;
E 25
	}
E 18
	if (vi->ui_dk >= 0) {
		dk_busy |= 1<<vi->ui_dk;
		dk_xfer[vi->ui_dk]++;
		dk_wds[vi->ui_dk] += bp->b_bcount>>6;
	}
E 16

	/*
	 * Look for any seeks to be performed on other drives on this
	 * controller.  If overlapped seeks exist, insert seek commands
	 * on the controller's command queue before the transfer.
	 */
	dcbp = &vd->vd_mdcb.mdcb_head;
D 16
	if (vd->vd_offcyl &~ (1<<slave)) {
		register struct dksoftc *tdk;
		register struct buf *tp;
E 16

D 16
		for (dp = dp->b_forw; dp != NULL; dp = dp->b_forw) {
			if ((tp = dp->b_actf) == NULL)
				continue;
			slave = (vi = vddinfo[vdunit(tp->b_dev)])->ui_slave;
			if ((vd->vd_offcyl & (1<<slave)) == 0)
				continue;
			vd->vd_offcyl &= ~(1 << slave);
			tdk = &dksoftc[vi->ui_unit];
			if (tdk->dk_curcyl != tp->b_cylin) {
				tdk->dk_curcyl = tp->b_cylin;
				dk_seek[vi->ui_dk]++;
			}
			tdk->dk_curdaddr = tp->b_daddr;
			tdk->dk_dcb.operrsta = 0;
			tdk->dk_dcb.trail.sktrail.skaddr.cylinder = tp->b_cylin;
			tdk->dk_dcb.trail.sktrail.skaddr.track = tp->b_daddr>>8;
			tdk->dk_dcb.trail.sktrail.skaddr.sector =
			    tp->b_daddr & 0xff;
			*dcbp = (struct dcb *)tdk->dk_dcbphys;
			dcbp = &tdk->dk_dcb.nxtdcb;
E 14
		}
D 14
		ci->cur_trk[slave] = bp->b_daddr & 0xff;
		ci->off_cylinder = 0;
		mdcb->firstdcb = (fmt_dcb *)(PHYS(dcb));
E 14
I 14
	} else {
E 16
I 16
	if (dp == vm->um_tab.b_seekf)
		dp = dp->b_forw;
	else
		dp = vm->um_tab.b_seekf;
	for (; dp != NULL; dp = dp->b_forw) {
		if ((bp = dp->b_actf) == NULL)
			continue;
		vi = vddinfo[vdunit(bp->b_dev)];
		dk = &dksoftc[vi->ui_unit];
E 16
		dk->dk_curcyl = bp->b_cylin;
D 16
		dk->dk_curdaddr = (tn << 8) | sn;
		vd->vd_offcyl = 0;
E 16
I 16
		if (vi->ui_dk >= 0)
			dk_seek[vi->ui_dk]++;
		dk->dk_dcb.operrsta = 0;
		dk->dk_dcb.trail.sktrail.skaddr.cylinder = bp->b_cylin;
D 18
#ifdef notdef
		dk->dk_dcb.trail.sktrail.skaddr.track = bp->b_daddr>>8;
		dk->dk_dcb.trail.sktrail.skaddr.sector =
		    bp->b_daddr & 0xff;
#else
E 18
		dk->dk_dcb.trail.sktrail.skaddr.track = bp->b_track;
D 18
#endif
E 18
		*dcbp = (struct dcb *)dk->dk_dcbphys;
		dcbp = &dk->dk_dcb.nxtdcb;
E 16
E 14
E 2
	}
D 2
	/*
		 * Mark controller busy, and
		 * prepare a command packet for the controller.
		 */
	um->um_tab.b_active++;
	unit = VDUNIT(bp->b_dev);
	st = &vdst[vddinfo[unit]->ui_type];
	mdcb = &mdcbx[vddinfo[unit]->ui_ctlr];
	index = FLSYS(bp->b_dev);
	sizep = st->sizes;
	mdcb->firstdcb = (struct fmt_dcb *)PHYS(dcb);
	dcb->intflg = INTDUN;		/* interrupt on completion */
E 2
D 14
	dcb->opcode = (bp->b_flags & B_READ) ? RD : WD;
I 2
	dcb->intflg = INTDONE;
	dcb->nxtdcb = (fmt_dcb *)0;	/* end of chain */
E 2
	dcb->operrsta = 0;
D 2
	dcb->devselect = (char)(vddinfo[unit])->ui_slave;
	dcb->trailcnt = (char)3;
	ct = vddinfo[unit]->ui_ctlr;

	switch (ct) {
		case 0:
			phadr = get_ioadr(bp, vdbuf[0], VD0map, (caddr_t)vd0utl);
			break;
		case 1:
			phadr = get_ioadr(bp, vdbuf[1], VD1map, (caddr_t)vd1utl);
			break;
		case 2:
			phadr = get_ioadr(bp, vdbuf[2], VD2map, (caddr_t)vd2utl);
			break;
		case 3:
			phadr = get_ioadr(bp, vdbuf[3], VD3map, (caddr_t)vd3utl);
			break;
	}
/*
	phadr = get_ioadr(bp, vdbuf, IOmap, (caddr_t)ioutl);
*/

	if (vddinfo[unit]->ui_dk >= 0) {
		int dku = vddinfo[unit]->ui_dk;
		dk_busy |= 1<<dku;
		dk_xfer[dku]++;
		dk_wds[dku] += bp->b_bcount>>6;
	}
	dcb->trail.rwtrail.memadr = (char *)phadr;
	dcb->trail.rwtrail.wcount = (bp->b_bcount + 1) / 2;
	sblock = sizep[index].block0 + bp->b_blkno;
	dcb->trail.rwtrail.disk.cylinder = (short)(sblock / st->nspc);
	dcb->trail.rwtrail.disk.track = (char)((sblock % st->nspc) / st->nsect);
	dcb->trail.rwtrail.disk.sector = (char)(sblock*2 % (st->nsect*2));

E 2
I 2
	dcb->devselect = (char)slave;
	dcb->trailcnt = (char)(sizeof (trrw) / sizeof (long));
	dcb->trail.rwtrail.memadr = (char *)
	    vbastart(bp, ci->rawbuf, (long *)ci->map, ci->utl);
	dcb->trail.rwtrail.wcount = (short)((bp->b_bcount+1) / sizeof (short));
	dcb->trail.rwtrail.disk.cylinder = bp->b_cylin;
	dcb->trail.rwtrail.disk.track = bp->b_daddr & 0xff;
	dcb->trail.rwtrail.disk.sector = bp->b_daddr >> 8;
	mdcb->vddcstat = 0;
   	dk_wds[unit] += bp->b_bcount / 32;
	ci->int_expected = 1;
D 13
	timeout(vd_int_timeout, (caddr_t)ctlr, 20*60);
E 13
I 13
	timeout(vd_int_timeout, (caddr_t)ctlr, 20*hz);
E 13
  	dk_busy |= 1 << unit;
E 2
D 5
#ifdef VDDCPERF
E 5
	scope_out(1);
D 5
#endif
E 5
D 2

	VDDC_ATTENTION(cntrl_vaddr,PHYS(mdcb))	/* do it */
E 2
I 2
	VDDC_ATTENTION((cdr *)(vdminfo[ctlr]->um_addr),
	    (fmt_mdcb *)(PHYS(mdcb)), ci->ctlr_type);
E 2
}
E 14
I 14
	*dcbp = (struct dcb *)vd->vd_dcbphys;
I 16
	if (vm->um_tab.b_actf)
		vm->um_tab.b_actl->b_forw = vm->um_tab.b_seekf;
	else
		vm->um_tab.b_actf = vm->um_tab.b_seekf;
D 17
	vm->um_tab.b_actl = vm->um_tab.b_seekl;
E 17
I 17
	if (vm->um_tab.b_seekf)
		vm->um_tab.b_actl = vm->um_tab.b_seekl;
E 17
	vm->um_tab.b_seekf = 0;
D 17
	vm->um_tab.b_seekl = 0;
E 17
E 16
E 14

I 2
D 14
/*
 * Watch for lost interrupts.
 */
vd_int_timeout(ctlr)
	register int ctlr;
{
	register ctlr_tab *ci = &vdctlr_info[ctlr];
	register fmt_dcb *dcb = &ci->ctlr_dcb;
E 2

I 2
	uncache(&dcb->operrsta);
D 10
	printf("vd%d: lost interupt, status %x", ctlr, dcb->operrsta);
E 10
I 10
	printf("vd%d: lost interrupt, status %b", ctlr, dcb->operrsta, ERRBITS);
E 10
	if (ci->ctlr_type == SMD_ECTLR) {
		uncache(&dcb->err_code);
		printf(", error code %x", dcb->err_code);
E 14
I 14
	/*
	 * Initiate operation.
	 */
D 16
	bp->b_daddr = 0;		/* init overloaded field */
	if (vi->ui_dk >= 0) {
		dk_busy |= 1<<vi->ui_dk;
		dk_xfer[vi->ui_dk]++;
		dk_wds[vi->ui_dk] += bp->b_bcount>>6;
E 14
	}
E 16
D 14
	printf("\n");
	if ((dcb->operrsta&DCBCMP) == 0) { 
		VDDC_ABORT((cdr *)(vdminfo[ctlr]->um_addr), ci->ctlr_type);
		dcb->operrsta |= DCBUSC | DCBABT | ANYERR | HRDERR | CTLRERR;
	}
	vdintr(ctlr);
E 14
I 14
	vd->vd_mdcb.mdcb_status = 0;
	VDGO(vm->um_addr, vd->vd_mdcbphys, vd->vd_type);
E 14
}

I 38
/*
 * Wait for controller to finish current operation
 * so that direct controller accesses can be done.
 */
vdlock(ctlr)
{
	register struct vba_ctlr *vm = vdminfo[ctlr];
	register struct vdsoftc *vd = &vdsoftc[ctlr];
	int s;

	s = spl7();
	while (vm->um_tab.b_active || vd->vd_flags & VD_LOCKED) {
		vd->vd_flags |= VD_WAIT;
		sleep((caddr_t)vd, PRIBIO);
	}
	vd->vd_flags |= VD_LOCKED;
	splx(s);
}

/*
 * Continue normal operations after pausing for 
 * munging the controller directly.
 */
vdunlock(ctlr)
{
	register struct vba_ctlr *vm = vdminfo[ctlr];
	register struct vdsoftc *vd = &vdsoftc[ctlr];

	vd->vd_flags &= ~VD_LOCKED;
	if (vd->vd_flags & VD_WAIT) {
		vd->vd_flags &= ~VD_WAIT;
		wakeup((caddr_t)vd);
	} else if (vm->um_tab.b_actf || vm->um_tab.b_seekf)
		vdstart(vm);
}

E 38
I 14
#define	DONTCARE (DCBS_DSE|DCBS_DSL|DCBS_TOP|DCBS_TOM|DCBS_FAIL|DCBS_DONE)
E 14
E 2
/*
 * Handle a disk interrupt.
 */
D 2
vdintr(vdnum)
register vdnum;
E 2
I 2
vdintr(ctlr)
D 14
	register int ctlr;
E 14
I 14
	register ctlr;
E 14
E 2
{
D 2
	register struct buf *bp, *dp;
	register struct vba_ctlr *um = vdminfo[vdnum];	
	register struct fmt_dcb *dcb = &dcbx[vdnum];
	register struct fmt_mdcb *mdcb = &mdcbx[vdnum];
	register struct vdst *st;
	int unit;
	struct vba_device *ui;
E 2
I 2
D 14
	register ctlr_tab *ci;
	register struct buf *cq, *uq, *bp;
	register int slave, unit;
	register fmt_mdcb  *mdcb;
	register fmt_dcb *dcb;
	int code, s;
E 14
I 14
	register struct buf *bp, *dp;
	register struct vba_ctlr *vm = vdminfo[ctlr];
	register struct vba_device *vi;
	register struct vdsoftc *vd = &vdsoftc[ctlr];
	register status;
I 17
D 25
	int ecode;
E 25
I 25
D 27
	int ecode, timedout;
E 27
I 27
	int timedout;
E 27
E 25
E 17
I 15
	struct dksoftc *dk;
E 15
E 14
E 2

I 2
D 14
	untimeout(vd_int_timeout, (caddr_t)ctlr);
E 2
D 5
#ifdef VDDCPERF
E 5
	scope_out(2);
D 5
#endif
E 5
D 2
	if (intenable == 0 || vdintflg == 0) 	/* ignore all interrupts */
E 2
I 2
	ci = &vdctlr_info[ctlr];
	if (!ci->int_expected) {
E 14
I 14
D 25
	vd->vd_wticks = 0;
E 25
	if (!vm->um_tab.b_active) {
E 14
		printf("vd%d: stray interrupt\n", ctlr);
E 2
		return;
D 2
	if (um->um_tab.b_active == NULL) return;/* unexpected interrupt */
	uncache((char *)&mdcb->intdcb);
	uncache((char *)&dcb->operrsta);
	if ( mdcb->intdcb != (struct fmt_dcb *)PHYS(dcb)) {	/* dcb causing interrupt */
		printf("vd%d: bad dcb=%x (phys=%x)\n",
		    vdnum, mdcb->intdcb, PHYS(dcb));
		return;
E 2
	}
D 2
	if (! (dcb->operrsta & DCBCMP))	{ /* unexpected interrupt */
		printf("vd%d: unexpected interrupt, err=%b\n", vdnum,
		    dcb->operrsta, ERRBITS);
		return;
	}
	dp = um->um_tab.b_actf;		/* device queue head in ctlr queue */
	bp = dp->b_actf;		/* first buffer in device queue */
E 2
I 2
	/*
D 14
	 * Take first request off controller's queue.
E 14
I 14
	 * Get device and block structures, and a pointer
	 * to the vba_device for the drive.
E 14
	 */
D 14
	cq = &vdminfo[ctlr]->um_tab;
	uq = cq->b_forw;
	bp = uq->av_forw;
E 2
	unit = VDUNIT(bp->b_dev);
D 2
	ui = vddinfo[unit];
	if (ui->ui_dk >= 0)
		dk_busy &= ~(1 << ui->ui_dk);
	if (dcb->operrsta & (HRDERR|SFTERR)) {
		st = &vdst[ui->ui_type];
		if (dcb->operrsta & HRDERR) {
			harderr(bp, &st->name[7]);
			printf("status=%b\n", dcb->operrsta, ERRBITS);
			dskrst(bp);
			bp->b_flags |= B_ERROR;
		} else
#define	SECTOR(x)	((x)*2)
			printf("%s%d: soft error sn%d status=%b\n", &st->name[7], unit,
			   SECTOR(bp->b_blkno + st->sizes[FLSYS(bp->b_dev)].block0),
			   dcb->operrsta, ERRBITS);
	}
	switch (vdnum) {
		case 0:
			end_transfer(bp, vdbuf[0], VD0map, (caddr_t)vd0utl);
			break;
		case 1:
			end_transfer(bp, vdbuf[1], VD1map, (caddr_t)vd1utl);
			break;
		case 2:
			end_transfer(bp, vdbuf[2], VD2map, (caddr_t)vd2utl);
			break;
		case 3:
			end_transfer(bp, vdbuf[3], VD3map, (caddr_t)vd3utl);
			break;
	}
E 2
I 2
	dk_busy &= ~(1 << unit);
	dk_xfer[unit]++;
	ci->int_expected = 0;
	/* find associated control blocks */
	mdcb = &ci->ctlr_mdcb, uncache(&mdcb->intdcb);
	dcb = &ci->ctlr_dcb, uncache(&dcb->operrsta);
	if (ci->ctlr_type == SMD_ECTLR)
		uncache(&dcb->err_code);
	slave = uq->b_dev;
	switch (code = vddecode_error(dcb)) {
E 2

D 2
	um->um_tab.b_active = 0;
	um->um_tab.b_errcnt = 0;
	if (dp->b_forw != NULL) {		/* more than 1 unit on queue */
		um->um_tab.b_actf = dp->b_forw;	/* next device on ctlr queue */
		dp->b_forw = um->um_tab.b_actl->b_forw;	/* be last in queue */
		um->um_tab.b_actl->b_forw = dp;	/* last points now to dp */
		um->um_tab.b_actl = dp;		/* pointer in ctlr structure */
E 2
I 2
	case CTLR_ERROR:
	case DRIVE_ERROR:
D 13
		if (cq->b_errcnt >= 2)
			vdhard_error(ci, bp, dcb);
E 13
		if (code == CTLR_ERROR)
			vdreset_ctlr((cdr *)vdminfo[ctlr]->um_addr, ctlr);
D 13
		else
			reset_drive((cdr *)vdminfo[ctlr]->um_addr, ctlr,
			    slave, 2);
		if (cq->b_errcnt++ < 2) {	/* retry error */
E 13
I 13
		else if (reset_drive((cdr *)vdminfo[ctlr]->um_addr,
		    ctlr, slave) == 0)
			vddinfo[unit]->ui_alive = 0;
		/*
		 * Retry transfer once, unless reset failed.
		 */
		if (vddinfo[unit]->ui_alive && cq->b_errcnt++ < 2) {
E 13
			cq->b_forw = uq->b_back;
			vdstart(vdminfo[ctlr]);
			return;
E 14
I 14
	dp = vm->um_tab.b_actf;
	bp = dp->b_actf;
	vi = vddinfo[vdunit(bp->b_dev)];
I 27
	dk = &dksoftc[vi->ui_unit];
E 27
D 16
	dk_busy &= ~(1<<vi->ui_dk);
E 16
I 16
	if (vi->ui_dk >= 0)
		dk_busy &= ~(1<<vi->ui_dk);
I 25
	timedout = (vd->vd_wticks >= VDMAXTIME);
E 25
E 16
	/*
	 * Check for and process errors on
	 * either the drive or the controller.
	 */
	uncache(&vd->vd_dcb.operrsta);
	status = vd->vd_dcb.operrsta;
D 25
	if (status & VDERR_HARD) {
E 25
I 25
	if (bp->b_flags & B_FORMAT) {
		dk->dk_operrsta = status;
		uncache(&vd->vd_dcb.err_code);
		dk->dk_ecode = vd->vd_dcb.err_code;
	}
	if (status & VDERR_HARD || timedout) {
E 25
I 17
D 27
		if (vd->vd_type == VDTYPE_SMDE) {
E 27
I 27
		if (vd->vd_type == VDTYPE_SMDE)
E 27
			uncache(&vd->vd_dcb.err_code);
D 27
			ecode = vd->vd_dcb.err_code;
		}
E 27
E 17
		if (status & DCBS_WPT) {
			/*
			 * Give up on write locked devices immediately.
			 */
D 15
			printf("dk%d: write locked\n", vdunit(bp->b_dev));
E 15
I 15
			printf("dk%d: write locked\n", vi->ui_unit);
E 15
			bp->b_flags |= B_ERROR;
D 15
		} else if (status & VDERR_SOFT) {
E 15
I 15
D 25
		} else if (status & VDERR_RETRY) {
E 25
I 25
		} else if (status & VDERR_RETRY || timedout) {
E 25
I 20
			int endline = 1;

E 20
E 15
D 25
			if (status & VDERR_DRIVE) {
I 20
				printf("dk%d%c: drive err %b, bn %d,",
				    vi->ui_unit, 'a' + vdpart(bp->b_dev),
				    status &~ DONTCARE, VDERRBITS, bp->b_blkno);
				if (vd->vd_type == VDTYPE_SMDE)
					printf(" ecode %x,", ecode);
				printf(" resetting drive...");
E 25
I 25
			if (status & VDERR_CTLR || timedout) {
				vdharderr("controller err",
				    vd, bp, &vd->vd_dcb);
				printf("; resetting controller...");
				vdreset_ctlr(vm);
			} else if (status & VDERR_DRIVE) {
				vdharderr("drive err", vd, bp, &vd->vd_dcb);
				printf("; resetting drive...");
E 25
E 20
				if (!vdreset_drive(vi))
					vi->ui_alive = 0;
D 20
			} else if (status & VDERR_CTLR)
E 20
I 20
D 25
			} else if (status & VDERR_CTLR) {
				printf("dk%d%c: controller err %b, bn %d,",
				    vi->ui_unit, 'a' + vdpart(bp->b_dev),
				    status &~ DONTCARE, VDERRBITS, bp->b_blkno);
				if (vd->vd_type == VDTYPE_SMDE)
					printf(" ecode %x,", ecode);
				printf("resetting controller...");
E 20
				vdreset_ctlr(vm);
E 25
I 20
			} else
				endline = 0;
E 20
			/*
			 * Retry transfer once, unless reset failed.
			 */
D 20
			if (!vi->ui_alive || bp->b_errcnt++ >= 2)
E 20
I 20
D 25
			if (!vi->ui_alive || dp->b_errcnt++ >= 2) {
E 25
I 25
			if (!vi->ui_alive || dp->b_errcnt++ >= 2 ||
			    bp->b_flags & B_FORMAT) {
E 25
				if (endline)
					printf("\n");
E 20
				goto hard;
I 20
			}

			if (endline)
				printf(" retrying\n");
E 20
			vm->um_tab.b_active = 0;	/* force retry */
		} else  {
	hard:
			bp->b_flags |= B_ERROR;
D 25
			/* NEED TO ADJUST b_blkno to failed sector */
			harderr(bp, "dk");
			printf("status %x (%b)", status,
			   status &~ DONTCARE, VDERRBITS);
D 17
			if (vd->vd_type == VDTYPE_SMDE) {
				uncache(&vd->vd_dcb.err_code);
				printf(" ecode %x", vd->vd_dcb.err_code);
			}
E 17
I 17
			if (vd->vd_type == VDTYPE_SMDE)
				printf(" ecode %x", ecode);
E 25
I 25
			vdharderr("hard error", vd, bp, &vd->vd_dcb);
E 25
E 17
			printf("\n");
E 14
		}
D 13
		bp->b_resid = bp->b_bcount;
E 13
I 13
D 14
		vdhard_error(ci, bp, dcb);
E 13
		break;

	case HARD_DATA_ERROR:
I 10
	case WRITE_PROTECT:
I 13
	default:				/* shouldn't happen */
E 13
E 10
		vdhard_error(ci, bp, dcb);
E 14
I 14
	} else if (status & DCBS_SOFT)
D 27
		vdsofterr(vd, bp, &vd->vd_dcb);
E 27
I 27
		vdsofterr(bp, &vd->vd_dcb);
E 27
I 25
	vd->vd_wticks = 0;
E 25
	if (vm->um_tab.b_active) {
		vm->um_tab.b_active = 0;
D 20
		vm->um_tab.b_errcnt = 0;
E 20
		vm->um_tab.b_actf = dp->b_forw;
		dp->b_active = 0;
		dp->b_errcnt = 0;
		dp->b_actf = bp->av_forw;
E 14
		bp->b_resid = 0;
D 14
		break;

	case SOFT_DATA_ERROR:
		vdsoft_error(ci, bp, dcb);
		/* fall thru... */

D 13
	default:			/* operation completed */
E 13
I 13
	case 0:			/* operation completed */
E 13
		bp->b_error = 0;
		bp->b_resid = 0;
		break;
E 14
I 14
D 17
		vbadone(bp, vd->vd_rawbuf, (long *)vd->vd_map, vd->vd_utl);
E 17
I 17
		vbadone(bp, &vd->vd_rbuf);
E 17
		biodone(bp);
		/*
		 * If this unit has more work to do,
		 * then start it up right away.
		 */
		if (dp->b_actf)
			vdustart(vi);
I 15
D 27
		else if ((dk = &dksoftc[vi->ui_unit])->dk_openpart == 0)
E 27
I 27
		else if (dk->dk_openpart == 0)
E 27
			wakeup((caddr_t)dk);
E 15
E 14
E 2
	}
D 2
	dp->b_errcnt = 0;
	dp->b_actf = bp->av_forw;		/* remove first from queue */
	bp->b_resid = 0;	/* All data read here */
E 2
I 2
D 14
	vbadone(bp, ci->rawbuf, (long *)ci->map, ci->utl);
E 14
	/*
D 14
	 * Take next request on this unit q, or, if none,
	 * the next request on the next active unit q.
E 14
I 14
	 * If there are devices ready to
	 * transfer, start the controller.
E 14
	 */
D 14
	s = spl7();
	uq->av_forw = bp->av_forw;
	if (uq->av_back != bp) {
		register struct buf *next;
E 2

I 2
		unit = VDUNIT(uq->av_forw->b_dev);
		slave = vddinfo[unit]->ui_slave;
		next = uq->av_forw;
		if (next->b_cylin != ci->cur_cyl[slave] ||
		    (next->b_daddr & 0xff) != ci->cur_trk[slave])
			ci->off_cylinder |= 1 << slave;
	} else
		uq->av_back = NULL;
	splx(s);
	/* reset controller state */
	cq->b_errcnt = 0;
	cq->b_active--;
E 2
D 5
#ifdef VDDCPERF
E 5
	scope_out(3);
D 5
#endif
E 5
D 2

E 2
I 2
	if (bp->b_flags & B_ERROR)
		bp->b_error = EIO;
E 2
	iodone(bp);
D 2
	vdstart(um);		/* start requests for next device on queue */
E 2
I 2
	vdstart(vdminfo[ctlr]);
E 14
I 14
D 17
	if (vm->um_tab.b_actf)
E 17
I 17
D 38
	if (vm->um_tab.b_actf || vm->um_tab.b_seekf)
E 38
I 38
	if (vd->vd_flags & VD_WAIT) {
		vd->vd_flags &= ~VD_WAIT;
		wakeup((caddr_t)vd);
	} else if (vm->um_tab.b_actf || vm->um_tab.b_seekf)
E 38
E 17
		vdstart(vm);
E 14
E 2
}

I 25
vdharderr(what, vd, bp, dcb)
	char *what;
	struct vdsoftc *vd;
	register struct buf *bp;
	register struct dcb *dcb;
{
	int unit = vdunit(bp->b_dev), status = dcb->operrsta;
D 27
	int part = vdpart(bp->b_dev);
E 27
	register struct disklabel *lp = &dklabel[unit];
D 27
	char partname = 'a' + part;
	int sn;
E 27
I 27
	int blkdone;
E 27

	if (vd->vd_wticks < VDMAXTIME)
		status &= ~DONTCARE;
D 27
/* generic
	sn = bp->b_blkno + lp->d_partitions[part].p_offset;
*/
	sn = ((dcb->err_cyl & 0xfff) * lp->d_ntracks + dcb->err_trk)
	    * lp->d_nsectors + dcb->err_sec;
	printf("dk%d%c: %s bn [%d-%d) (sn %d), status %b",
	    unit, partname, what, bp->b_blkno,
	    bp->b_blkno + (bp->b_bcount - 1)/DEV_BSIZE, sn, status, VDERRBITS);
E 27
I 27
D 34
	blkdone = ((((dcb->err_cyl & 0xfff) * lp->d_ntracks + dcb->err_trk)
	    * lp->d_nsectors + dcb->err_sec) >> dksoftc[unit].dk_bshift)
	    - lp->d_partitions[vdpart(bp->b_dev)].p_offset - bp->b_blkno;
E 34
I 34
	blkdone = ((((dcb->err_cyl & 0xfff) * lp->d_ntracks + dcb->err_trk) *
	    lp->d_nsectors + dcb->err_sec -
	    lp->d_partitions[vdpart(bp->b_dev)].p_offset) >>
	    dksoftc[unit].dk_bshift) - bp->b_blkno;
E 34
	diskerr(bp, "dk", what, LOG_PRINTF, blkdone, lp);
	printf(", status %b", status, VDERRBITS);
E 27
	if (vd->vd_type == VDTYPE_SMDE)
		printf(" ecode %x", dcb->err_code);
D 27
	printf("\n(error sec %d trk %d cyl %d wcount %d)", dcb->err_sec,
	    dcb->err_trk, dcb->err_cyl, dcb->err_wcount);
E 27
}

E 25
I 2
D 14
/*
 * Convert controller status to internal operation/error code.
 */
vddecode_error(dcb)
	register fmt_dcb *dcb;
{
E 2

I 2
	if (dcb->operrsta & HRDERR) {
D 10
		if (dcb->operrsta & (HCRCERR | HCMPERR | UCDATERR | WPTERR |
E 10
I 10
		if (dcb->operrsta & WPTERR)
			return (WRITE_PROTECT);
I 13
	/* this looks wrong...
E 13
		if (dcb->operrsta & (HCRCERR | HCMPERR | UCDATERR |
E 10
D 13
		    DSEEKERR | NOTCYLERR |DRVNRDY | INVDADR))
E 13
I 13
		    DSEEKERR | NOTCYLERR | DRVNRDY | INVDADR))
	*/
		if (dcb->operrsta & (DSEEKERR | NOTCYLERR | DRVNRDY | INVDADR))
E 13
			return (DRIVE_ERROR);
		if (dcb->operrsta & (CTLRERR | OPABRT | INVCMD | DNEMEM))
			return (CTLR_ERROR);
		return (HARD_DATA_ERROR);
	}
	if (dcb->operrsta & SFTERR)
		return (SOFT_DATA_ERROR);
	return (0);
}

/*
 * Report a hard error.
 */
vdhard_error(ci, bp, dcb)
	ctlr_tab *ci; 
E 14
I 14
D 27
vdsofterr(vd, bp, dcb)
	struct vdsoftc *vd;
E 27
I 27
vdsofterr(bp, dcb)
E 27
E 14
	register struct buf *bp;
D 14
	register fmt_dcb *dcb;
E 14
I 14
	register struct dcb *dcb;
E 14
{
I 14
D 27
	int unit = vdunit(bp->b_dev), status = dcb->operrsta;
D 25
	char part = 'a' + vdpart(bp->b_dev);
E 25
I 25
	int part = vdpart(bp->b_dev);
	char partname = 'a' + part;
	int sn = (bp->b_blkno << dksoftc[unit].dk_bshift) +
	    dklabel[unit].d_partitions[part].p_offset;
E 27
I 27
D 29
	struct disklabel *lp = &dklabel[vdunit(bp->b_dev)];
E 29
I 29
	int unit = vdunit(bp->b_dev);
	struct disklabel *lp = &dklabel[unit];
E 29
	int status = dcb->operrsta;
	int blkdone;
E 27
E 25
E 14
D 13
	unit_tab *ui = &vdunit_info[VDUNIT(bp->b_dev)];
E 13

D 14
	bp->b_flags |= B_ERROR;
D 13
	harderr(bp, ui->info.type_name);
E 13
I 13
	/* NEED TO ADJUST b_blkno to failed sector */
	harderr(bp, "dk");
E 13
D 10
	printf("status %x", dcb->operrsta);
	if (ci->ctlr_type == SMD_ECTLR)
		printf(" ecode %x", dcb->err_code);
E 10
I 10
	if (dcb->operrsta & WPTERR)
		printf("write protected");
	else {
D 13
		printf("status %b", dcb->operrsta, ERRBITS);
E 13
I 13
		printf("status %x (%b)", dcb->operrsta,
		   dcb->operrsta & ~(DSERLY|DSLATE|TOPLUS|TOMNUS|DCBUSC|DCBCMP),
		   ERRBITS);
E 13
		if (ci->ctlr_type == SMD_ECTLR)
			printf(" ecode %x", dcb->err_code);
	}
E 10
	printf("\n");
}

/*
 * Report a soft error.
 */
vdsoft_error(ci, bp, dcb)
	ctlr_tab *ci; 
	register struct buf *bp;
	register fmt_dcb *dcb;
{
D 13
	unit_tab *ui = &vdunit_info[VDUNIT(bp->b_dev)];
E 13
I 13
	int unit = VDUNIT(bp->b_dev);
	char part = 'a' + FILSYS(bp->b_dev);
E 13

D 10
	printf("%s%d%c: soft error sn%d status %x", ui->info.type_name,
D 3
	    dkunit(bp), 'a'+(minor(bp->b_dev)&07), bp->b_blkno,
E 3
I 3
	    minor(bp->b_dev) >> 3, 'a'+(minor(bp->b_dev)&07), bp->b_blkno,
E 3
	    dcb->operrsta);
E 10
I 10
D 13
	printf("dk%d%c: soft error sn%d status %b", minor(bp->b_dev) >> 3,
	    'a'+(minor(bp->b_dev)&07), bp->b_blkno, dcb->operrsta, ERRBITS);
E 10
	if (ci->ctlr_type == SMD_ECTLR)
		printf(" ecode %x", dcb->err_code);
	printf("\n");
E 13
I 13
	if (dcb->operrsta == (DCBCMP | CPDCRT | SFTERR | ANYERR))
E 14
I 14
D 17
	if (status != (DCBS_DCE|DCBS_CCD|DCBS_SOFT|DCBS_ERR)) {
E 17
I 17
D 20
	if (status != (DCBS_CCD|DCBS_SOFT|DCBS_ERR|DCBS_DONE)) {
E 17
		if (vd->vd_type == VDTYPE_SMDE)
			uncache(&dcb->err_code);
E 20
I 20
D 27
	if (status != (DCBS_CCD|DCBS_SOFT|DCBS_ERR|DCBS_DONE))
E 20
D 25
		log(LOG_WARNING, "dk%d%c: soft error sn%d status %b ecode %x\n",
		    unit, part, bp->b_blkno, status, VDERRBITS, dcb->err_code);
E 25
I 25
		log(LOG_WARNING,
		    "dk%d%c: soft error sn %d bn %d, status %b ecode %x\n",
		    unit, partname, sn, bp->b_blkno, status, VDERRBITS,
E 27
I 27
D 34
	blkdone = ((((dcb->err_cyl & 0xfff) * lp->d_ntracks + dcb->err_trk)
	    * lp->d_nsectors + dcb->err_sec) >> dksoftc[unit].dk_bshift)
	    - lp->d_partitions[vdpart(bp->b_dev)].p_offset - bp->b_blkno;
E 34
I 34
	blkdone = ((((dcb->err_cyl & 0xfff) * lp->d_ntracks + dcb->err_trk) *
	    lp->d_nsectors + dcb->err_sec -
	    lp->d_partitions[vdpart(bp->b_dev)].p_offset) >>
	    dksoftc[unit].dk_bshift) - bp->b_blkno;
E 34

	if (status != (DCBS_CCD|DCBS_SOFT|DCBS_ERR|DCBS_DONE)) {
		diskerr(bp, "dk", "soft error", LOG_WARNING, blkdone, lp);
		addlog(", status %b ecode %x\n", status, VDERRBITS,
E 27
		    dcb->err_code);
E 25
D 20
	} else
E 20
I 20
D 27
	else
E 20
E 14
D 25
		log(LOG_WARNING, "dk%d%c: soft ecc sn%d\n",
		    unit, part, bp->b_blkno);
E 25
I 25
		log(LOG_WARNING, "dk%d%c: soft ecc sn %d bn %d\n",
		    unit, part, sn, bp->b_blkno);
E 27
I 27
	} else {
		diskerr(bp, "dk", "soft ecc", LOG_WARNING, blkdone, lp);
		addlog("\n");
	}
E 27
E 25
D 14
	else
		log(LOG_WARNING, "dk%d%c: soft error sn%d status %b ecode %x\n",
		    unit, part, bp->b_blkno, dcb->operrsta, ERRBITS,
		    ci->ctlr_type == SMD_ECTLR ? dcb->err_code : 0);
E 14
E 13
D 24
}

D 14
/*ARGSUSED*/
vdopen(dev, flag)
	dev_t dev;
	int flag;
{
	register unit = VDUNIT(dev);
	register struct vba_device *vi = vddinfo[unit];

	if (vi == 0 || vi->ui_alive == 0 || vi->ui_type >= nvddrv)
		return (ENXIO);
I 13
	if (vi->ui_alive == 0) {
		if (vdconfigure_drive((cdr *)vdminfo[vi->ui_ctlr]->um_addr,
		    vi->ui_ctlr, vi->ui_slave, vi->ui_type))
			vi->ui_alive = 1;
		else
			return (ENXIO);
	}
E 13
	if (vdunit_info[unit].info.partition[FILSYS(dev)].par_len == 0)
		return (ENXIO);
	return (0);
}

E 14
E 2
vdread(dev, uio)
D 2
dev_t dev;
struct uio *uio;
E 2
I 2
	dev_t dev;
	struct uio *uio;
E 2
{
D 14
	register int unit = VDUNIT(dev);
D 2
	register int error;
	register int ct;
	register int s;
E 2
I 2
	register unit_tab *ui = &vdunit_info[unit];
E 14
I 14
	register int unit = vdunit(dev);
E 14
E 2

D 9
	if (unit >= NFSD)
E 9
I 9
	if (unit >= NDK)
E 9
D 2
		error = ENXIO;
	else {
		ct = vddinfo[unit]->ui_ctlr;
		s = spl8();
		while (vdbufused[ct]) sleep (&vdbufused[ct],PRIBIO+1);
		vdbufused[ct] = 1;
		splx(s);
		error = physio(vdstrategy, &rvdbuf[unit], dev, B_READ, minphys, uio);
		vdbufused[ct] = 0;
		wakeup (&vdbufused[ct]);
	}
	return error;
E 2
I 2
		return (ENXIO);
D 14
	return (physio(vdstrategy, &ui->raw_q_element, dev, B_READ,
	    minphys, uio));
E 14
I 14
	return (physio(vdstrategy, &rdkbuf[unit], dev, B_READ, minphys, uio));
E 14
E 2
}

vdwrite(dev, uio)
D 2
dev_t dev;
struct uio *uio;
E 2
I 2
	dev_t dev;
	struct uio *uio;
E 2
{
D 14
	register int unit = VDUNIT(dev);
D 2
	register int error;
	register int ct;
	register int s;
E 2
I 2
	register unit_tab *ui = &vdunit_info[unit];
E 14
I 14
	register int unit = vdunit(dev);
E 14
E 2

D 9
	if (unit >= NFSD)
E 9
I 9
	if (unit >= NDK)
E 9
D 2
		error = ENXIO;
	else {
		ct = vddinfo[unit]->ui_ctlr;
		s = spl8();
		while (vdbufused[ct]) sleep (&vdbufused[ct],PRIBIO+1);
		vdbufused[ct] = 1;
		splx(s);
		error = physio(vdstrategy, &rvdbuf[unit], dev, B_WRITE, minphys, uio);
		vdbufused[ct] = 0;
		wakeup (&vdbufused[ct]);
	}
	return error;
E 2
I 2
		return (ENXIO);
D 14
	return (physio(vdstrategy, &ui->raw_q_element, dev, B_WRITE,
	    minphys, uio));
E 14
I 14
	return (physio(vdstrategy, &rdkbuf[unit], dev, B_WRITE, minphys, uio));
E 24
E 14
E 2
}

D 2
#define	DUMPSIZE	32	/* Up to 32k at a time - controller limit */

vddump(dev)
dev_t	dev;
E 2
D 14
/*
D 2
 * Dump the main memory to the given device.
E 2
I 2
 * Crash dump.
E 2
 */
I 2
vddump(dev)
E 14
I 14
vdioctl(dev, cmd, data, flag)
E 14
	dev_t dev;
I 14
	int cmd;
	caddr_t data;
	int flag;
E 14
E 2
{
D 2
	register struct vba_ctlr *um;
	register struct fmt_dcb *dcb = &dcbx[0];
	register struct fmt_mdcb *mdcb = &mdcbx[0];
	register struct vdst *st;
	register int unit;
	register caddr_t cntrl_vaddr ;
	register struct size *sizep;	/* Pointer to one of the tables */
	int index,sblock,blkcount,thiscount;
	int	memaddr;
E 2
I 2
D 14
	register int unit = VDUNIT(dev);
	register unit_tab *ui = &vdunit_info[unit];
	register fs_tab *fs = &ui->info;
	register int ctlr = vddinfo[unit]->ui_ctlr;
	register struct vba_ctlr *vba_vdctlr_info = vdminfo[ctlr];
	register int filsys = FILSYS(dev);
	register cdr *addr = (cdr *)(vba_vdctlr_info->um_addr);
	register int cur_blk, blkcount, blocks;
	caddr_t memaddr;
E 14
I 14
D 21
	int unit = vdunit(dev);
E 21
I 21
	register int unit = vdunit(dev);
E 21
	register struct disklabel *lp = &dklabel[unit];
D 23
	int error = 0;
E 23
I 23
	register struct dksoftc *dk = &dksoftc[unit];
D 25
	int error = 0, wlab;
E 25
I 25
D 33
	int error = 0, wlab, vdformat();
E 33
I 33
	int error = 0, vdformat();
E 33
E 25
E 23
E 14
E 2

D 2
	unit = VDUNIT(dev);
	um = (vddinfo[unit])->ui_mi;
	st = &vdst[(vddinfo[unit])->ui_type];
	dcb = &dcbx[um->um_ctlr];
	cntrl_vaddr = um->um_addr;
	memaddr = 0x0;
	index = FLSYS(dev);
	sizep = st->sizes;
E 2
I 2
D 14
	vdreset_ctlr(addr, ctlr);
E 2
	blkcount = maxfree - 2;		/* In 1k byte pages */
D 2
	if (dumplo + blkcount > sizep[index].nblocks) return(EINVAL);
	sblock = sizep[index].block0 + dumplo;
E 2
I 2
	if (dumplo + blkcount > fs->partition[filsys].par_len) {
		blkcount = fs->partition[filsys].par_len - dumplo;
D 13
		printf("vd%d: Dump truncated to %dMB\n", unit, blkcount/1024);
E 13
I 13
		printf("truncated to %dMB ", blkcount/1024);
E 14
I 14
	switch (cmd) {

	case DIOCGDINFO:
		*(struct disklabel *)data = *lp;
		break;

D 15
	case DIOCGDINFOP:
		*(struct disklabel **)data = lp;
E 15
I 15
	case DIOCGPART:
		((struct partinfo *)data)->disklab = lp;
		((struct partinfo *)data)->part =
		    &lp->d_partitions[vdpart(dev)];
E 15
		break;

	case DIOCSDINFO:
		if ((flag & FWRITE) == 0)
			error = EBADF;
		else
D 21
			*lp = *(struct disklabel *)data;
E 21
I 21
			error = setdisklabel(lp, (struct disklabel *)data,
D 23
			    dksoftc[unit].dk_openpart);
E 23
I 23
			    (dk->dk_state == OPENRAW) ? 0 : dk->dk_openpart);
D 25
		if (error == 0)
E 25
I 25
		if (error == 0 && dk->dk_state == OPENRAW &&
		    vdreset_drive(vddinfo[unit]))
E 25
			dk->dk_state = OPEN;
E 23
E 21
		break;

I 23
	case DIOCWLABEL:
		if ((flag & FWRITE) == 0)
			error = EBADF;
		else
			dk->dk_wlabel = *(int *)data;
		break;

E 23
D 21
	case DIOCWDINFO: {
		struct buf *bp;
		struct disklabel *dlp;

		if ((flag & FWRITE) == 0) {
E 21
I 21
	case DIOCWDINFO:
I 23
D 33
		/* simulate opening partition 0 so write succeeds */
		dk->dk_openpart |= (1 << 0);		/* XXX */
		wlab = dk->dk_wlabel;
		dk->dk_wlabel = 1;
E 33
E 23
		if ((flag & FWRITE) == 0)
E 21
			error = EBADF;
D 21
			break;
		}
		*lp = *(struct disklabel *)data;
		bp = geteblk(lp->d_secsize);
D 18
		bp->b_dev = dev;
E 18
I 18
		bp->b_dev = makedev(major(dev), vdminor(vdunit(dev), 0));
E 18
		bp->b_blkno = LABELSECTOR;
		bp->b_bcount = lp->d_secsize;
		bp->b_flags = B_READ;
		dlp = (struct disklabel *)(bp->b_un.b_addr + LABELOFFSET);
		vdstrategy(bp);
		biowait(bp);
		if (bp->b_flags & B_ERROR) {
			error = u.u_error;		/* XXX */
			u.u_error = 0;
			goto bad;
		}
		*dlp = *lp;
		bp->b_flags = B_WRITE;
		vdstrategy(bp);
		biowait(bp);
		if (bp->b_flags & B_ERROR) {
			error = u.u_error;		/* XXX */
			u.u_error = 0;
		}
bad:
		brelse(bp);
E 21
I 21
		else if ((error = setdisklabel(lp, (struct disklabel *)data,
D 23
			    dksoftc[unit].dk_openpart)) == 0)
E 23
I 23
		    (dk->dk_state == OPENRAW) ? 0 : dk->dk_openpart)) == 0) {
I 33
			int wlab;

E 33
			dk->dk_state = OPEN;
I 33
			/* simulate opening partition 0 so write succeeds */
			dk->dk_openpart |= (1 << 0);		/* XXX */
			wlab = dk->dk_wlabel;
			dk->dk_wlabel = 1;
E 33
E 23
			error = writedisklabel(dev, vdstrategy, lp);
I 33
			dk->dk_openpart = dk->dk_copenpart | dk->dk_bopenpart;
			dk->dk_wlabel = wlab;
E 33
I 23
		}
D 33
		dk->dk_openpart = dk->dk_copenpart | dk->dk_bopenpart;
		dk->dk_wlabel = wlab;
E 33
E 23
E 21
		break;
E 14
E 13
D 21
	}
E 21
D 14
	cur_blk = fs->partition[filsys].par_start + dumplo;
	memaddr = 0;
E 2
	while (blkcount > 0) {
D 2
		thiscount = MIN (blkcount, DUMPSIZE);
		mdcb->firstdcb = (struct fmt_dcb *)PHYS(dcb);
		dcb->intflg = NOINT;
		dcb->opcode = WD;
		dcb->operrsta = 0;
		dcb->devselect = (char)(vddinfo[unit])->ui_slave;
		dcb->trailcnt = (char)3;
		dcb->trail.rwtrail.memadr = (char *)memaddr;
		dcb->trail.rwtrail.wcount = thiscount*512;
		dcb->trail.rwtrail.disk.cylinder= (short)(sblock/st->nspc);
		dcb->trail.rwtrail.disk.track = (char)((sblock % st->nspc) 
			/ st->nsect);
		dcb->trail.rwtrail.disk.sector = (char)(sblock*2 % (st->nsect*2));
		VDDC_ATTENTION(cntrl_vaddr,PHYS(mdcb) )	/* do it */
		POLLTILLDONE(5,"WD");
		if (dcb->operrsta & HRDERR) {
			if (vddebug)
				printf("vd%d: i/o error, err=%b\n", unit,
				    dcb->operrsta, ERRBITS);
			return(EIO);
		};
		blkcount -= thiscount;
		memaddr += thiscount*NBPG;
		sblock += thiscount;
E 2
I 2
		blocks = MIN(blkcount, DUMPSIZE);
		if (!vdwrite_block(addr, ctlr, unit, memaddr, cur_blk, blocks))
			return (EIO);
		blkcount -= blocks;
		memaddr += blocks * NBPG;
		cur_blk += blocks;
E 14
I 14

I 25
	case DIOCWFORMAT:
	    {
		register struct format_op *fop;
		struct uio auio;
		struct iovec aiov;

		if ((flag & FWRITE) == 0) {
			error = EBADF;
			break;
		}
		fop = (struct format_op *)data;
		aiov.iov_base = fop->df_buf;
		aiov.iov_len = fop->df_count;
		auio.uio_iov = &aiov;
		auio.uio_iovcnt = 1;
		auio.uio_resid = fop->df_count;
		auio.uio_segflg = UIO_USERSPACE;
		auio.uio_offset = fop->df_startblk * lp->d_secsize;
		dk->dk_operrsta = fop->dk_operrsta;
		dk->dk_ecode = fop->dk_ecode;
		/*
		 * Don't return errors, as the format op won't get copied
		 * out if we return nonzero.  Callers must check the returned
		 * count.
		 */
		(void) physio(vdformat, (struct buf *)NULL, dev,
		    (cmd == DIOCWFORMAT ? B_WRITE : B_READ), minphys, &auio);
		fop->df_count -= auio.uio_resid;
		fop->dk_operrsta = dk->dk_operrsta;
		fop->dk_ecode = dk->dk_ecode;
		break;
	    }

E 25
	default:
		error = ENOTTY;
		break;
E 14
E 2
	}
D 2
	return(0);
E 2
I 2
D 22
	return (0);
E 22
I 22
	return (error);
E 22
E 2
}

I 25
vdformat(bp)
	struct buf *bp;
{
	bp->b_flags |= B_FORMAT;
	vdstrategy(bp);
}

E 25
D 2
vdopen(dev, flag)
register dev_t dev;
int flag;
E 2
I 2
/*
D 14
 * Write a block to disk during a crash dump.
E 14
I 14
 * Watch for lost interrupts.
E 14
 */
D 14
vdwrite_block(caddr, ctlr, unit, addr, block, blocks)
	register cdr *caddr;
E 14
I 14
vdwatch()
{
	register struct vdsoftc *vd;
	register struct vba_ctlr *vm;
E 14
D 27
	register int ctlr, unit;
E 27
I 27
	register int ctlr;
E 27
I 25
	int s;
E 25
D 14
	register caddr_t addr;
	register int block, blocks;
E 14
I 14

	timeout(vdwatch, (caddr_t)0, hz);
	for (ctlr = 0; ctlr < NVD; ctlr++) {
		vm = vdminfo[ctlr];
		if (vm == 0 || vm->um_alive == 0)
			continue;
		vd = &vdsoftc[ctlr];
D 17
		if (!vm->um_tab.b_active) {
			for (unit = 0; unit < NDK; unit++)
				if (dkutab[unit].b_active &&
				    vddinfo[unit]->ui_mi == vm)
					goto active;
E 17
I 17
D 25
		if (vm->um_tab.b_active && vd->vd_wticks++ >= 20) {
E 17
			vd->vd_wticks = 0;
E 25
I 25
		s = spl7();
		if (vm->um_tab.b_active && vd->vd_wticks++ >= VDMAXTIME) {
E 25
D 17
			continue;
		}
active:
		vd->vd_wticks++;
		if (vd->vd_wticks >= 20) {
			vd->vd_wticks = 0;
E 17
			printf("vd%d: lost interrupt\n", ctlr);
D 25
			/* abort pending dcb's and restart controller */
E 25
I 25
#ifdef maybe
			VDABORT((struct vddevice *)vm->um_addr, vd->vd_type);
#endif
			vdintr(ctlr);
E 25
		}
I 25
		splx(s);
E 25
	}
}

#define	DBSIZE	64	/* controller limit with 1K sectors */
/*
 * Crash dump.
 */
vddump(dev)
	dev_t dev;
E 14
E 2
{
D 2
	register struct vba_device *ui;
	register unit = VDUNIT(dev);
E 2
I 2
D 6
	register fmt_mdcb *mdcb = &vdctlr_info[ctlr].ctlr_mdcb;
	register fmt_dcb *dcb = &vdctlr_info[ctlr].ctlr_dcb;
E 6
I 6
D 14
	register ctlr_tab *ci = &vdctlr_info[ctlr];
	register fmt_mdcb *mdcb = &ci->ctlr_mdcb;
	register fmt_dcb *dcb = &ci->ctlr_dcb;
E 6
	register unit_tab *ui = &vdunit_info[unit];
	register fs_tab	 *fs = &ui->info;
E 14
I 14
	register struct vba_device *vi;
	register struct vba_ctlr *vm;
	register struct disklabel *lp;
	register struct vdsoftc *vd;
	struct dksoftc *dk;
	int part, unit, num;
D 17
	caddr_t start;
E 17
I 17
	u_long start;
E 17
E 14
E 2

D 2
	ui = vddinfo[unit];
	if (ui == 0 || ui->ui_alive == 0 || ui->ui_type >= NVDDRV)
		return ENXIO;
	return 0;
E 2
I 2
D 14
	block *= (int)ui->sec_per_blk;
	blocks *= (int)ui->sec_per_blk;
	mdcb->firstdcb = (fmt_dcb *)(PHYS(dcb));
	dcb->intflg = NOINT;
	dcb->opcode = WD;
	dcb->operrsta = 0;
	dcb->devselect = (char)(vddinfo[unit])->ui_slave;
	dcb->trailcnt = (char)(sizeof (trrw) / sizeof (long));
	dcb->trail.rwtrail.memadr = addr;
	dcb->trail.rwtrail.wcount = (short)
	    ((blocks * fs->secsize)/ sizeof (short));
	dcb->trail.rwtrail.disk.cylinder = (short)(block / ui->sec_per_cyl);
	dcb->trail.rwtrail.disk.track = (char)((block / fs->nsec) % fs->ntrak);
	dcb->trail.rwtrail.disk.sector = (char)(block % fs->nsec);
D 6
	VDDC_ATTENTION(caddr, (fmt_mdcb *)(PHYS(mdcb)),
	    vdctlr_info[ctlr].ctlr_type);
	POLLTILLDONE(caddr, dcb, 5, vdctlr_info[ctlr].ctlr_type);
	if (vdtimeout <= 0) {
E 6
I 6
	VDDC_ATTENTION(caddr, (fmt_mdcb *)(PHYS(mdcb)), ci->ctlr_type);
	if (!vdpoll(ci, caddr, 5)) {
E 6
		printf(" during dump\n");
		return (0);
E 14
I 14
	start = 0;
	unit = vdunit(dev);
	if (unit > NDK || (vi = vddinfo[unit]) == 0 || vi->ui_alive == 0)
		return (ENXIO);
	dk = &dksoftc[unit];
D 23
	if (dk->dk_state != OPEN && dk->dk_state != OPENRAW)
E 23
I 23
	if (dk->dk_state != OPEN && dk->dk_state != OPENRAW &&
	    vdinit(vdminor(unit, 0), 0) != 0)
E 23
		return (ENXIO);
	lp = &dklabel[unit];
	part = vdpart(dev);
	if (part >= lp->d_npartitions)
		return (ENXIO);
D 20
	vm = vdminfo[vi->ui_ctlr];
E 20
I 20
	vm = vi->ui_mi;
E 20
	vdreset_ctlr(vm);
	if (dumplo < 0)
		return (EINVAL);
	/*
D 15
	 * Dumplo and maxfree are in pages;
	 * dumplo will change soon (XXX).
E 15
I 15
D 18
	 * Dumplo and maxfree are in pages.
E 18
I 18
	 * Maxfree is in pages, dumplo is in DEV_BSIZE units.
E 18
E 15
	 */
	num = maxfree * (NBPG / lp->d_secsize);
D 15
	dumplo *= NBPG / lp->d_secsize;		/* XXX */
E 15
I 15
D 18
	dumplo *= NBPG / lp->d_secsize;
E 18
I 18
	dumplo *= DEV_BSIZE / lp->d_secsize;
E 18
E 15
	if (dumplo + num >= lp->d_partitions[vdpart(dev)].p_size)
		num = lp->d_partitions[vdpart(dev)].p_size - dumplo;
	vd = &vdsoftc[vm->um_ctlr];
	vd->vd_dcb.intflg = DCBINT_NONE;
	vd->vd_dcb.opcode = VDOP_WD;
D 20
	vd->vd_dcb.devselect = vi->ui_slave;
E 20
I 20
	vd->vd_dcb.devselect = dk->dk_dcb.devselect;
E 20
D 18
	vd->vd_dcb.trailcnt = sizeof (trrw) / sizeof (long);
E 18
I 18
	vd->vd_dcb.trailcnt = sizeof (struct trrw) / sizeof (long);
E 18
	while (num > 0) {
		int nsec, cn, sn, tn;

		nsec = MIN(num, DBSIZE);
D 17
		sn = dumplo + (unsigned)start / lp->d_secsize;
E 17
I 17
		sn = dumplo + start / lp->d_secsize;
E 17
		cn = (sn + lp->d_partitions[vdpart(dev)].p_offset) /
		    lp->d_secpercyl;
		sn %= lp->d_secpercyl;
		tn = sn / lp->d_nsectors;
		sn %= lp->d_nsectors;
		vd->vd_mdcb.mdcb_head = (struct dcb *)vd->vd_dcbphys;
		vd->vd_dcb.trail.rwtrail.memadr = start;
		vd->vd_dcb.trail.rwtrail.wcount = (nsec * lp->d_secsize) >> 1;
		vd->vd_dcb.trail.rwtrail.disk.cylinder = cn;
		vd->vd_dcb.trail.rwtrail.disk.track = tn;
		vd->vd_dcb.trail.rwtrail.disk.sector = sn;
		vd->vd_dcb.operrsta = 0;
		VDGO(vm->um_addr, vd->vd_mdcbphys, vd->vd_type);
		if (!vdpoll(vm, 5)) {
			printf(" during dump\n");
			return (EIO);
		}
		if (vd->vd_dcb.operrsta & VDERR_HARD) {
			printf("dk%d: hard error, status=%b\n", unit,
			    vd->vd_dcb.operrsta, VDERRBITS);
			return (EIO);
		}
		start += nsec * lp->d_secsize;
		num -= nsec;
E 14
	}
D 14
	if (dcb->operrsta & HRDERR) {
D 10
		printf("vd%d: hard error, status %x\n", unit, dcb->operrsta);
E 10
I 10
		printf("dk%d: hard error, status=%b\n", unit,
		    dcb->operrsta, ERRBITS);
E 10
		return (0);
	}
	return (1);
E 14
I 14
	return (0);
E 14
E 2
}

vdsize(dev)
D 2
register dev_t dev;
E 2
I 2
	dev_t dev;
E 2
{
D 2
	register struct vba_device *ui;
	register unit = VDUNIT(dev);
E 2
I 2
D 14
	struct vba_device *vi = vddinfo[VDUNIT(dev)];
E 14
I 14
	register int unit = vdunit(dev);
	register struct dksoftc *dk;
	struct vba_device *vi;
	struct disklabel *lp;
E 14
E 2

D 2
	ui = vddinfo[unit];
	if (ui == 0 || ui->ui_alive == 0 || ui->ui_type >= NVDDRV)
		return -1;
	return vdst[ui->ui_type].sizes[FLSYS(dev)].nblocks;
E 2
I 2
D 14
	if (vi == 0 || vi->ui_alive == 0 || vi->ui_type >= nvddrv)
E 14
I 14
	if (unit >= NDK || (vi = vddinfo[unit]) == 0 || vi->ui_alive == 0 ||
	    (dk = &dksoftc[unit])->dk_state != OPEN)
E 14
		return (-1);
D 14
	return (vdunit_info[VDUNIT(dev)].info.partition[FILSYS(dev)].par_len);
E 14
I 14
	lp = &dklabel[unit];
I 18
#ifdef SECSIZE
E 18
D 15
	return ((int)lp->d_partitions[vdpart(dev)].p_size >> dk->dk_bshift);
E 15
I 15
	return ((int)lp->d_partitions[vdpart(dev)].p_size);
I 18
#else SECSIZE
	return ((int)lp->d_partitions[vdpart(dev)].p_size >> dk->dk_bshift);
#endif SECSIZE
E 18
E 15
E 14
E 2
}

D 2
/* reset a drive after a hard error */
dskrst(bp)
	register struct buf *bp;
E 2
I 2
/*
 * Perform a controller reset.
 */
D 14
vdreset_ctlr(addr, ctlr)
	register cdr *addr;
	register int ctlr;
E 14
I 14
vdreset_ctlr(vm)
	register struct vba_ctlr *vm;
E 14
E 2
{
D 2
	register struct vdst *st;
	register struct fmt_dcb *dcb;
	register struct fmt_mdcb *mdcb;
	register struct vba_device *ui;
	register caddr_t cntrl_vaddr ;
	int unit;
E 2
I 2
D 14
	register struct buf *cq = &vdminfo[ctlr]->um_tab;
	register struct buf *uq = cq->b_forw;
	register ctlr_tab *ci = &vdctlr_info[ctlr];
E 14
I 14
	register struct vddevice *vdaddr = (struct vddevice *)vm->um_addr;
	register struct vdsoftc *vd = &vdsoftc[vm->um_ctlr];
	register int unit;
	struct vba_device *vi;
E 14
	
D 14
	VDDC_RESET(addr, ci->ctlr_type);
	ci->ctlr_started = 0;
	if (ci->ctlr_type == SMD_ECTLR) {
		addr->cdr_csr = 0;
		addr->mdcb_tcf = AM_ENPDA;
		addr->dcb_tcf = AM_ENPDA;
		addr->trail_tcf = AM_ENPDA;
		addr->data_tcf = AM_ENPDA;
		addr->cdr_ccf = CCF_STS | XMD_32BIT | BSZ_16WRD |
E 14
I 14
	VDRESET(vdaddr, vd->vd_type);
	if (vd->vd_type == VDTYPE_SMDE) {
		vdaddr->vdcsr = 0;
		vdaddr->vdtcf_mdcb = AM_ENPDA;
		vdaddr->vdtcf_dcb = AM_ENPDA;
		vdaddr->vdtcf_trail = AM_ENPDA;
		vdaddr->vdtcf_data = AM_ENPDA;
		vdaddr->vdccf = CCF_STS | XMD_32BIT | BSZ_16WRD |
E 14
		    CCF_ENP | CCF_EPE | CCF_EDE | CCF_ECE | CCF_ERR;
	}
D 14
	if (vdnotrailer(addr, ctlr, 0, INIT, 10) & HRDERR) {
		printf("failed to init\n");
E 14
I 14
	if (!vdcmd(vm, VDOP_INIT, 10) || !vdcmd(vm, VDOP_DIAG, 10)) {
		printf("%s cmd failed\n",
		    vd->vd_dcb.opcode == VDOP_INIT ? "init" : "diag");
E 14
D 13
		return (0);
E 13
I 13
		return;
E 13
	}
D 14
	if (vdnotrailer(addr, ctlr, 0, DIAG, 10) & HRDERR) {
		printf("diagnostic error\n");
D 13
		return (0);
E 13
I 13
		return;
E 14
I 14
	for (unit = 0; unit < NDK; unit++)
		if ((vi = vddinfo[unit])->ui_mi == vm && vi->ui_alive)
			(void) vdreset_drive(vi);
}

vdreset_drive(vi)
	register struct vba_device *vi;
{
	register struct disklabel *lp = &dklabel[vi->ui_unit];
	struct vba_ctlr *vm = vdminfo[vi->ui_ctlr];
	struct vddevice *vdaddr = (struct vddevice *)vm->um_addr;
D 20
	struct vdsoftc *vd = &vdsoftc[vi->ui_ctlr];
E 20
I 20
	register struct vdsoftc *vd = &vdsoftc[vi->ui_ctlr];
	register struct dksoftc *dk = &dksoftc[vi->ui_unit];
E 20

top:
	vd->vd_dcb.opcode = VDOP_CONFIG;		/* command */
	vd->vd_dcb.intflg = DCBINT_NONE;
	vd->vd_dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
	vd->vd_dcb.operrsta = 0;
D 20
	vd->vd_dcb.devselect = vi->ui_slave;
E 20
I 20
	vd->vd_dcb.devselect = vi->ui_slave | lp->d_devflags;
E 20
	vd->vd_dcb.trail.rstrail.ncyl = lp->d_ncylinders;
	vd->vd_dcb.trail.rstrail.nsurfaces = lp->d_ntracks;
	if (vd->vd_type == VDTYPE_SMDE) {
D 18
		vd->vd_dcb.trailcnt = sizeof (treset) / sizeof (long);
E 18
I 18
		vd->vd_dcb.trailcnt = sizeof (struct treset) / sizeof (long);
E 18
		vd->vd_dcb.trail.rstrail.nsectors = lp->d_nsectors;
D 17
		vd->vd_dcb.trail.rstrail.slip_sec = lp->d_trackskew;
E 17
I 17
		vd->vd_dcb.trail.rstrail.slip_sec = lp->d_sparespertrack;
E 17
D 20
		vd->vd_dcb.trail.rstrail.recovery = 0x18f;
E 20
I 20
		vd->vd_dcb.trail.rstrail.recovery = VDRF_NORMAL;
E 20
	} else
		vd->vd_dcb.trailcnt = 2;		/* XXX */
	vd->vd_mdcb.mdcb_head = (struct dcb *)vd->vd_dcbphys;
	vd->vd_mdcb.mdcb_status = 0;
	VDGO(vdaddr, vd->vd_mdcbphys, vd->vd_type);
	if (!vdpoll(vm, 5)) {
		printf(" during config\n");
		return (0);
E 14
E 13
	}
D 14
	/*  reset all units attached to controller */
	uq = cq->b_forw;
	do {
D 13
		reset_drive(addr, ctlr, uq->b_dev, 0);
E 13
I 13
		(void) reset_drive(addr, ctlr, uq->b_dev);
E 13
		uq = uq->b_forw;
	} while (uq != cq->b_forw);
E 14
I 14
	if (vd->vd_dcb.operrsta & VDERR_HARD) {
D 20
		if (vd->vd_type == VDTYPE_SMDE &&
		    (vdaddr->vdstatus[vi->ui_slave]&STA_US) == 0)
			return (0);
E 20
I 20
		if (vd->vd_type == VDTYPE_SMDE) {
			if (lp->d_devflags == 0) {
				lp->d_devflags = VD_ESDI;
				goto top;
			}
#ifdef notdef
			/* this doesn't work, STA_US isn't set(?) */
			if ((vdaddr->vdstatus[vi->ui_slave] & STA_US) == 0)
				return (0);
#endif
		}
E 20
		if ((vd->vd_dcb.operrsta & (DCBS_OCYL|DCBS_NRDY)) == 0)
D 20
			printf("dk%d: config error\n", vi->ui_unit);
		else if ((vd->vd_flags&VD_STARTED) == 0) {
E 20
I 20
			printf("dk%d: config error %b ecode %x\n", vi->ui_unit,
D 25
			   vd->vd_dcb.operrsta, VDERRBITS, vd->vd_dcb.err_code);
E 25
I 25
			   vd->vd_dcb.operrsta, VDERRBITS,
			   (u_char) vd->vd_dcb.err_code);
E 25
		else if ((vd->vd_flags & VD_STARTED) == 0) {
E 20
			int started;

D 20
			printf("vd%d: starting drives, wait ... ", vm->um_ctlr);
E 20
I 20
			printf(" starting drives, wait ... ");
E 20
			vd->vd_flags |= VD_STARTED;
			started = (vdcmd(vm, VDOP_START, 10) == 1);
			DELAY(62000000);
D 20
			printf("\n");
E 20
I 20
			printf("done");
			lp->d_devflags = 0;
E 20
			if (started)
				goto top;
		}
		return (0);
	}
I 20
	dk->dk_dcb.devselect |= lp->d_devflags;
E 20
	return (1);
E 14
D 13
	return (1);
E 13
}
E 2

D 2
	unit = VDUNIT(bp->b_dev);
	ui = vddinfo[unit];
	mdcb = &mdcbx[ui->ui_ctlr];
	dcb = &dcbx[ui->ui_ctlr];
	cntrl_vaddr = (ui->ui_mi)->um_addr;
	st = &vdst[vddinfo[unit]->ui_type];
	dcb->opcode = RSTCFG;		/* configure drive command */
	dcb->intflg = NOINT;
	dcb->operrsta  = 0;
	dcb->trail.resetrail.ncyl = st->ncyl;
	dcb->trail.resetrail.nsurfaces = st->ntrak;
	dcb->devselect = (char)ui->ui_slave;
	dcb->trailcnt = (char)2;
	mdcb->firstdcb = (struct fmt_dcb *)PHYS(dcb);
	VDDC_ATTENTION(cntrl_vaddr,PHYS(mdcb) )	/* do it */
	POLLTILLDONE(3,"reset")
	if (dcb->operrsta & HRDERR) {
		if (vddebug) {
			harderr(bp, &st->name[7]);
			printf("reset failed, err=%b\n", dcb->operrsta,ERRBITS);
		}
E 2
I 2
/*
D 14
 * Perform a reset on a drive.
E 14
I 14
 * Perform a command w/o trailer.
E 14
 */
D 13
reset_drive(addr, ctlr, slave, start)
	register cdr *addr;
	register int ctlr, slave, start;
E 13
I 13
D 14
reset_drive(addr, ctlr, slave)
	cdr *addr;
	int ctlr, slave;
E 14
I 14
vdcmd(vm, cmd, t)
	register struct vba_ctlr *vm;
E 14
E 13
{
D 13
	register int type = vdctlr_info[ctlr].unit_type[slave];
E 13
I 13
D 14
	int type = vdctlr_info[ctlr].unit_type[slave];
E 14
I 14
	register struct vdsoftc *vd = &vdsoftc[vm->um_ctlr];
E 14
E 13

D 14
	if (type == UNKNOWN)
E 14
I 14
	vd->vd_dcb.opcode = cmd;		/* command */
	vd->vd_dcb.intflg = DCBINT_NONE;
	vd->vd_dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
	vd->vd_dcb.operrsta = 0;
	vd->vd_dcb.devselect = 0;
	vd->vd_dcb.trailcnt = 0;
	vd->vd_mdcb.mdcb_head = (struct dcb *)vd->vd_dcbphys;
	vd->vd_mdcb.mdcb_status = 0;
	VDGO(vm->um_addr, vd->vd_mdcbphys, vd->vd_type);
	if (!vdpoll(vm, t)) {
		printf(" during init\n");
E 14
D 13
		return;
	if (!vdconfigure_drive(addr, ctlr, slave, type, start))
E 13
I 13
		return (0);
D 14
	if (!vdconfigure_drive(addr, ctlr, slave, type)) {
E 13
		printf("vd%d: drive %d: couldn't reset\n", ctlr, slave);
I 13
		return (0);
E 14
	}
D 14
	return (1);
E 14
I 14
	return ((vd->vd_dcb.operrsta&VDERR_HARD) == 0);
E 14
E 13
I 6
}

/*
D 14
 * Poll controller until operation completes
 * or timeout expires.
E 14
I 14
 * Poll controller until operation
 * completes or timeout expires.
E 14
 */
D 14
vdpoll(ci, addr, t)
	register ctlr_tab *ci;
	register cdr *addr;
E 14
I 14
vdpoll(vm, t)
	register struct vba_ctlr *vm;
E 14
	register int t;
{
D 14
	register fmt_dcb *dcb = &ci->ctlr_dcb;
E 14
I 14
	register struct vdsoftc *vd = &vdsoftc[vm->um_ctlr];
	register struct vddevice *vdaddr = (struct vddevice *)vm->um_addr;
E 14

	t *= 1000;
D 13
	uncache(&dcb->operrsta);
	while ((dcb->operrsta&(DCBCMP|DCBABT)) == 0) {
		DELAY(1000);
E 13
I 13
	for (;;) {
E 13
D 14
		uncache(&dcb->operrsta);
I 13
		if (dcb->operrsta & (DCBCMP|DCBABT))
E 14
I 14
		uncache(&vd->vd_dcb.operrsta);
		if (vd->vd_dcb.operrsta & (DCBS_DONE|DCBS_ABORT))
E 14
			break;
E 13
		if (--t <= 0) {
D 14
			printf("vd%d: controller timeout", ci-vdctlr_info);
			VDDC_ABORT(addr, ci->ctlr_type);
E 14
I 14
			printf("vd%d: controller timeout", vm->um_ctlr);
			VDABORT(vdaddr, vd->vd_type);
E 14
D 25
			DELAY(30000);
E 25
D 14
			uncache(&dcb->operrsta);
E 14
			return (0);
		}
I 13
		DELAY(1000);
E 13
	}
D 14
	if (ci->ctlr_type == SMD_ECTLR) {
D 13
		uncache(&addr->cdr_csr);
		while (addr->cdr_csr&CS_GO) {
			DELAY(50);
E 13
I 13
		for (;;) {
E 13
			uncache(&addr->cdr_csr);
I 13
			if ((addr->cdr_csr & CS_GO) == 0)
				break;
E 14
I 14
	if (vd->vd_type == VDTYPE_SMDE) {
		do {
E 14
			DELAY(50);
E 13
D 14
		}
E 14
I 14
			uncache(&vdaddr->vdcsr);
		} while (vdaddr->vdcsr & CS_GO);
E 14
D 20
		DELAY(300);
E 20
I 20
	 	DELAY(300);
		uncache(&vd->vd_dcb.err_code);
E 20
	}
	DELAY(200);
D 14
	uncache(&dcb->operrsta);
E 14
I 14
	uncache(&vd->vd_dcb.operrsta);
E 14
	return (1);
E 6
}

D 14
#ifdef notdef
E 14
I 14
#ifdef COMPAT_42
struct	vdst {
	int	nsec;		/* sectors/track */
	int	ntrack;		/* tracks/cylinder */
	int	ncyl;		/* cylinders */
I 20
	int	secsize;	/* sector size */
E 20
	char	*name;		/* type name */
	struct {
		int	off;	/* partition offset in sectors */
		int	size;	/* partition size in sectors */
D 15
	} parts[3];
E 15
I 15
	} parts[8];
E 15
} vdst[] = {
D 15
	{ 48, 24, 711, "xsd", {0,61056}, {61056,61056}, {122112,691200} },
	{ 44, 20, 842, "egl", {0,52800}, {52800,66000}, {118800,617760} },
	{ 64, 10, 823, "fuj", {0,38400}, {38400,48000}, { 86400,437120} },
	{ 32, 24, 711, "xfd", {0,40704}, {40704,40704}, { 81408,460800} },
	{ 32, 19, 823, "smd", {0,40128}, {40128,27360}, { 67488,429856} },
	{ 32, 10, 823, "fsd", {0,19200}, {19200,24000}, { 43200,218560} }
E 15
I 15
D 20
	{ 48, 24, 711, "xsd",
E 20
I 20
	{ 66, 23, 850, 512, "NEC 800",
		{0,	 1290300},	/* a cyl   0 - 849 */
	},
I 35
	{ 64, 20, 842, 512, "2361a",
		{0,	 61440},	/* a cyl   0 - 47 */
		{61440,	 67840},	/* b cyl  48 - 100 */
		{129280, 942080}, 	/* c cyl 101 - 836 */
		{0,      1071360}, 	/* d cyl   0 - 836 */
		{449280, 311040},	/* e cyl 351 - 593 */
		{760320, 311040}, 	/* f cyl 594 - 836 */
		{449280, 622080},	/* g cyl 351 - 836 */
		{129280, 320000}	/* h cyl 101 - 350 */
	},
E 35
	{ 48, 24, 711, 512, "xsd",
E 20
D 19
		{0,	 30528},	/* a cyl   0 - 52 */
		{30528,	 30528},	/* b cyl  53 - 105 */
		{61056,	 345600}, 	/* c cyl 106 - 705 */
		{118656, 288000}, 	/* d cyl 206 - 705 */
		{176256, 230400},	/* e cyl 306 - 705 */
		{233856, 172800}, 	/* f cyl 406 - 705 */
		{291456, 115200},	/* g cyl 506 - 705 */
		{349056, 57600}		/* h cyl 606 - 705 */
E 19
I 19
		{0,	 61056},	/* a cyl   0 - 52 */
		{61056,	 61056},	/* b cyl  53 - 105 */
		{122112, 691200}, 	/* c cyl 106 - 705 */
		{237312, 576000}, 	/* d cyl 206 - 705 */
		{352512, 460800},	/* e cyl 306 - 705 */
		{467712, 345600}, 	/* f cyl 406 - 705 */
		{582912, 230400},	/* g cyl 506 - 705 */
		{698112, 115200}	/* h cyl 606 - 705 */
E 19
	},
D 20
	{ 44, 20, 842, "egl",
E 20
I 20
	{ 44, 20, 842, 512, "eagle",
E 20
D 17
		{0,	 26400},	/* egl0a cyl   0 - 59 */
		{26400,	 33000},	/* egl0b cyl  60 - 134 */
		{59400,	 308880}, 	/* egl0c cyl 135 - 836 */
		{368280, 2640}, 	/* egl0d cyl 837 - 842 */
		{0, 368280},		/* egl0e cyl 0 - 836 */
		{0, 370920}, 		/* egl0f cyl 0 - 842 */
		{59400, 155320},	/* egl0g cyl 135 - 487 */
		{214720, 153560}	/* egl0h cyl 488 - 836 */
E 17
I 17
		{0,	 52800},	/* egl0a cyl   0 - 59 */
		{52800,	 66000},	/* egl0b cyl  60 - 134 */
		{118800, 617760}, 	/* egl0c cyl 135 - 836 */
D 18
		{736560, 5280}, 	/* egl0d cyl 837 - 842 */
E 18
I 18
		{736560, 4400}, 	/* egl0d cyl 837 - 841 */
E 18
D 19
		{0, 	 736560},	/* egl0e cyl 0 - 836 */
D 18
		{0, 	 741840}, 	/* egl0f cyl 0 - 842 */
E 18
I 18
		{0, 	 740960}, 	/* egl0f cyl 0 - 841 */
E 19
I 19
		{0, 	 736560},	/* egl0e cyl   0 - 836 */
		{0, 	 740960}, 	/* egl0f cyl   0 - 841 */
E 19
E 18
		{118800, 310640},	/* egl0g cyl 135 - 487 */
		{429440, 307120}	/* egl0h cyl 488 - 836 */
E 17
	},
D 20
	{ 64, 10, 823, "fuj",
E 20
I 20
	{ 64, 10, 823, 512, "fuj",
E 20
D 19
		{0,	 19200},	/* fuj0a cyl   0 - 59 */
		{19200,	 24000},	/* fuj0b cyl  60 - 134 */
		{43200,	 218560}, 	/* fuj0c cyl 135 - 817 */
		{79680,	 182080}, 	/* fuj0d cyl 249 - 817 */
		{116160, 145600},	/* fuj0e cyl 363 - 817 */
		{152640, 109120}, 	/* fuj0f cyl 477 - 817 */
		{189120, 72640},	/* fuj0g cyl 591 - 817 */
		{225600, 36160}		/* fug0h cyl 705 - 817 */
E 19
I 19
		{0,	 38400},	/* fuj0a cyl   0 - 59 */
		{38400,	 48000},	/* fuj0b cyl  60 - 134 */
		{86400,	 437120}, 	/* fuj0c cyl 135 - 817 */
		{159360, 364160}, 	/* fuj0d cyl 249 - 817 */
		{232320, 291200},	/* fuj0e cyl 363 - 817 */
		{305280, 218240}, 	/* fuj0f cyl 477 - 817 */
		{378240, 145280},	/* fuj0g cyl 591 - 817 */
		{451200, 72320}		/* fug0h cyl 705 - 817 */
E 19
D 23
	},
D 20
	{ 32, 24, 711, "xfd",
E 20
I 20
	{ 32, 23, 850, 1024, "NEC 800-1024",
		{0,	 703800},	/* a cyl   0 - 849 */
E 23
	},
	{ 32, 24, 711, 512, "xfd",
E 20
D 18
		{ 0,	 20352 },	/* a cyl   0 - 52 */
		{ 20352, 20352 },	/* b cyl  53 - 105 */
		{ 40704, 230400 },	/* c cyl 106 - 705 */
		{ 0,	 40704 },	/* d cyl 709 - 710 (a & b) */
		{ 0,	 271104 },	/* e cyl   0 - 705 */
		{ 20352, 250752 },	/* f cyl  53 - 705 (b & c) */
		{ 40704, 115200 },	/* g cyl 106 - 405 (1/2 of c) */
		{ 155904,115200 }	/* h cyl 406 - 705 (1/2 of c) */
E 18
I 18
		{ 0,	 40704 },	/* a cyl   0 - 52 */
		{ 40704, 40704 },	/* b cyl  53 - 105 */
		{ 81408, 460800 },	/* c cyl 106 - 705 */
		{ 0,	 81408 },	/* d cyl 709 - 710 (a & b) */
		{ 0,	 542208 },	/* e cyl   0 - 705 */
		{ 40704, 501504 },	/* f cyl  53 - 705 (b & c) */
		{ 81408, 230400 },	/* g cyl 106 - 405 (1/2 of c) */
		{ 311808,230400 }	/* h cyl 406 - 705 (1/2 of c) */
E 18
	},
D 20
	{ 32, 19, 823, "smd",
E 20
I 20
	{ 32, 19, 823, 512, "smd",
E 20
D 19
		{0,	 20064},	/* a cyl   0-65 */
		{20064, 13680},		/* b cyl  66-110 */
		{33744, 214928},	/* c cyl 111-817 */
		{69616,	 179056},	/* d cyl 229 - 817 */
		{105488, 143184},	/* e cyl 347 - 817 */
		{141360, 107312},	/* f cyl 465 - 817 */
		{177232, 71440},	/* g cyl 583 - 817 */
		{213104, 35568}		/* h cyl 701 - 817 */
E 19
I 19
		{0,	 40128},	/* a cyl   0-65 */
		{40128,  27360},	/* b cyl  66-110 */
		{67488,  429856},	/* c cyl 111-817 */
		{139232, 358112},	/* d cyl 229 - 817 */
		{210976, 286368},	/* e cyl 347 - 817 */
		{282720, 214624},	/* f cyl 465 - 817 */
		{354464, 142880},	/* g cyl 583 - 817 */
		{426208, 71136}		/* h cyl 701 - 817 */
E 19
	},
D 20
	{ 32, 10, 823, "fsd",
E 20
I 20
	{ 18, 15, 1224, 1024, "mxd",
		{0,	 21600},	/* a cyl   0-79 */
		{21600,  22410},	/* b cyl  80-162 */
		{44010,  285120},	/* c cyl 163-1217 */
#ifdef notyet
		{x, 237600},	/* d cyl y - 1217 */
		{x, 190080},	/* e cyl y - 1217 */
		{x, 142560},	/* f cyl y - 1217 */
		{x, 95040},	/* g cyl y - 1217 */
		{x, 47520}		/* h cyl 701 - 817 */
#endif
	},
	{ 32, 10, 823, 512, "fsd",
E 20
D 18
		{0,	 9600},		/* a cyl   0 -  59 */
		{9600,	 12000},	/* b cyl  60 - 134 */
		{21600,	 109280},	/* c cyl 135 - 817 */
		{39840,	 91040},	/* d cyl 249 - 817 */
		{58080,	 72800},	/* e cyl 363 - 817 */
		{76320,	 54560},	/* f cyl 477 - 817 */
		{94560,  36320},	/* g cyl 591 - 817 */
		{112800, 18080}		/* h cyl 705 - 817 */
E 18
I 18
		{0,	 19200},	/* a cyl   0 -  59 */
		{19200,	 24000},	/* b cyl  60 - 134 */
		{43200,	 218560},	/* c cyl 135 - 817 */
E 18
	}
E 15
};
#define	NVDST	(sizeof (vdst) / sizeof (vdst[0]))

E 14
/*
D 14
 * Dump the mdcb and DCB for diagnostic purposes.
E 14
I 14
 * Construct a label for an unlabeled pack.  We
 * deduce the drive type by reading from the last
 * track on successively smaller drives until we
 * don't get an error.
E 14
 */
D 14
vdprintdcb(lp)
	register long *lp;
E 14
I 14
vdmaptype(vi, lp)
	register struct vba_device *vi;
	register struct disklabel *lp;
E 14
{
D 14
	register int i, dcb, tc;
E 14
I 14
	register struct vdsoftc *vd;
	register struct vdst *p;
D 20
	struct vba_ctlr *vm = vdminfo[vi->ui_ctlr];
E 20
I 20
	struct vba_ctlr *vm = vi->ui_mi;
E 20
	int i;
E 14

D 14
	for (dcb = 0; lp; lp = (long *)(*lp), dcb++) {
		lp = (long *)((long)lp | 0xc0000000);
		printf("\nDump of dcb%d@%x:", dcb, lp);
		for (i = 0, tc = lp[3] & 0xff; i < tc+7; i++)
			printf(" %lx", lp[i]);
		printf("\n");
E 14
I 14
	vd = &vdsoftc[vi->ui_ctlr];
	for (p = vdst; p < &vdst[NVDST]; p++) {
		if (vd->vd_type == VDTYPE_VDDC && p->nsec != 32)
			continue;
		lp->d_nsectors = p->nsec;
		lp->d_ntracks = p->ntrack;
		lp->d_ncylinders = p->ncyl;
I 20
		lp->d_secsize = p->secsize;
E 20
		if (!vdreset_drive(vi))
			return (0);
		vd->vd_dcb.opcode = VDOP_RD;
		vd->vd_dcb.intflg = DCBINT_NONE;
		vd->vd_dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
D 20
		vd->vd_dcb.devselect = vi->ui_slave;
E 20
I 20
		vd->vd_dcb.devselect = dksoftc[vi->ui_unit].dk_dcb.devselect;
E 20
D 18
		vd->vd_dcb.trailcnt = sizeof (trrw) / sizeof (long);
E 18
I 18
		vd->vd_dcb.trailcnt = sizeof (struct trrw) / sizeof (long);
E 18
D 17
		vd->vd_dcb.trail.rwtrail.memadr = (char *)
		    vtoph((struct proc *)0, (unsigned)vd->vd_rawbuf);
E 17
I 17
		vd->vd_dcb.trail.rwtrail.memadr =
		    vtoph((struct proc *)0, (unsigned)vd->vd_rbuf.vb_rawbuf);
E 17
D 20
		vd->vd_dcb.trail.rwtrail.wcount = 512 / sizeof(short);
E 20
I 20
		vd->vd_dcb.trail.rwtrail.wcount = lp->d_secsize / sizeof(short);
E 20
		vd->vd_dcb.operrsta = 0;
		vd->vd_dcb.trail.rwtrail.disk.cylinder = p->ncyl - 2;
		vd->vd_dcb.trail.rwtrail.disk.track = p->ntrack - 1;
		vd->vd_dcb.trail.rwtrail.disk.sector = p->nsec - 1;
		vd->vd_mdcb.mdcb_head = (struct dcb *)vd->vd_dcbphys;
		vd->vd_mdcb.mdcb_status = 0;
		VDGO(vm->um_addr, vd->vd_mdcbphys, vd->vd_type);
		if (!vdpoll(vm, 60))
			printf(" during probe\n");
		if ((vd->vd_dcb.operrsta & VDERR_HARD) == 0)
			break;
E 14
E 2
	}
I 2
D 14
	DELAY(1750000);
E 14
I 14
D 20
	if (p >= &vdst[NVDST]) {
		printf("dk%d: unknown drive type\n", vi->ui_unit);
E 20
I 20
	if (p >= &vdst[NVDST])
E 20
		return (0);
D 20
	}
E 20
I 20

E 20
D 15
	for (i = 0; i < 3; i++) {
E 15
I 15
	for (i = 0; i < 8; i++) {
E 15
		lp->d_partitions[i].p_offset = p->parts[i].off;
		lp->d_partitions[i].p_size = p->parts[i].size;
	}
D 15
	lp->d_npartitions = 3;
E 15
I 15
	lp->d_npartitions = 8;
E 15
	lp->d_secpercyl = lp->d_nsectors * lp->d_ntracks;
	lp->d_rpm = 3600;
D 20
	lp->d_secsize = 512;
E 20
	bcopy(p->name, lp->d_typename, 4);
	return (1);
E 14
E 2
}
I 2
D 14
#endif
E 14
I 14
#endif COMPAT_42
E 14
E 2
#endif
E 1
