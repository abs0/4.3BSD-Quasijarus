h09284
s 00037/00007/02387
d D 7.34 03/11/24 01:49:42 msokolov 87 86
c add RF35, RF36, and RF74
c new partitions for RA/RF73
e
s 00030/00000/02364
d D 7.33 03/11/16 21:19:37 msokolov 86 85
c reinstate 4.3BSD RD52 and RD53
c add correct RD54
e
s 00011/00000/02353
d D 7.32 01/02/13 08:19:24 msokolov 85 84
c add RA73 and RF73
e
s 00040/00000/02313
d D 7.31 01/02/10 22:16:25 msokolov 84 83
c add RF30, RF31, RF71, and RF72
e
s 00016/00003/02297
d D 7.30 00/02/09 15:26:17 msokolov 83 82
c Workaround for broken controllers that return zeros for the geometry
e
s 00002/00002/02298
d D 7.29 99/09/06 21:42:24 msokolov 82 81
c round the number of cylinders up, not down
e
s 00068/00073/02232
d D 7.28 99/09/06 21:41:40 msokolov 81 80
c it's the total size that's reported by the drive, not the number of cylinders,
c so use that to map types instead of the geometry
e
s 00000/00020/02305
d D 7.27 99/09/06 20:47:52 msokolov 80 78
c In accordance with the Quasijarus Project policy on the shipment of standard
c disk tables, remove RD52 and RD53
e
s 00000/00030/02295
d R 7.27 99/09/06 20:41:25 msokolov 79 78
c In accordance with the Quasijarus Project policy on the shipment of standard
c disk tables, remove RD52, RD53, and RX50
e
s 00003/00003/02322
d D 7.26 99/09/05 20:58:40 msokolov 78 77
c RA92 only has 2940951 blocks
e
s 00056/00016/02269
d D 7.25 99/09/04 16:58:37 msokolov 77 76
c add RA71, RA72, RA90, and RA92
c list partition sizes as "to end" wherever possible to make life easier for
c folks with third-party controllers faking RA disks
e
s 00002/00002/02283
d D 7.24 99/09/04 10:38:24 msokolov 76 75
c wait for 2 minutes for disks to spin up, 10 seconds was WAY too short
e
s 00028/00008/02257
d D 7.23 99/09/04 08:40:47 msokolov 75 74
c Put drives in the new ONLINE state instead of the OPENRAW state when they come
c on-line. This fixes the bug that caused a drive to become completely
c inaccessible if it came on-line on its own when there is no one waiting for it
c to do so.
e
s 00001/00005/02264
d D 7.22 99/09/04 00:58:33 msokolov 74 73
c qbgetpri is just as problematic for KDA50 as it is for TQK50
c see uda.c delta 7.8
e
s 00044/00056/02225
d D 7.21 88/10/22 15:14:13 karels 73 72
c use ubaalloc macros; use qbgetpri for Q-bus device probe routines;
c don't use wrong partitions on QD33 just because everything is "RA81"
e
s 00003/00003/02278
d D 7.20 88/08/27 07:20:56 tef 72 71
c Add support for microvax 3000.
e
s 00017/00004/02264
d D 7.19 88/07/09 13:37:10 bostic 71 70
c install approved copyright notice
e
s 00001/00016/02267
d D 7.18 88/06/06 11:12:19 karels 70 69
c put udaattach back together
e
s 00009/00007/02274
d D 7.17 88/06/04 17:07:20 karels 69 68
c yet another disklabel change: don't "open" partition 0 in WDINFO
c until setdisklabel finishes checks
e
s 00001/00001/02280
d D 7.16 88/05/27 16:10:37 karels 68 67
c new diskerr routine
e
s 00000/00001/02281
d D 7.15 88/05/24 11:08:01 karels 67 66
c lint
e
s 00030/00038/02252
d D 7.14 88/05/14 11:33:40 karels 66 65
c disklabel updates, remove ubapurge log(), change autoconfig printfs
e
s 00228/00130/02062
d D 7.13 88/02/06 13:56:25 bostic 65 64
c update from Chris Torek
e
s 00036/00010/02156
d D 7.12 88/02/06 13:51:33 karels 64 63
c update disklabel ioctls
e
s 00013/00000/02153
d D 7.11 88/01/02 13:44:46 bostic 63 62
c fix for slow uVAX boots; from Chris Torek
e
s 00000/00001/02153
d D 7.10 87/11/12 17:31:55 bostic 62 61
c extraneous assignment to pp; fix from Chris Torek
e
s 00008/00055/02146
d D 7.9 87/11/01 12:56:59 karels 61 60
c use setdisklabel, writedisklabel
e
s 01667/01215/00534
d D 7.8 87/10/23 11:16:24 bostic 60 59
c new driver; (Chris Torek)
e
s 00000/00004/01749
d D 7.7 87/06/05 12:27:40 karels 59 58
c rm wrong, unneeded crap
e
s 00004/00000/01749
d D 7.6 87/06/04 19:01:23 karels 58 57
c skip the alternate label crap
e
s 00002/00001/01747
d D 7.5 87/05/04 11:08:55 karels 57 56
c finish again
e
s 00064/00049/01684
d D 7.4 87/04/17 12:49:54 karels 56 55
c finish what I was doing
e
s 00052/00046/01681
d D 7.3 87/04/02 16:39:17 karels 55 54
c working with pack labels, open/close
e
s 00517/00216/01210
d D 7.2 87/02/19 17:35:13 karels 54 53
c pack labels
e
s 00000/00000/01426
d D 7.1 86/06/05 01:20:20 mckusick 53 52
c 4.3BSD release version
e
s 00003/00000/01423
d D 6.23 86/05/30 19:12:15 karels 52 49
c change default dma burst per little bird
e
s 00005/00000/01423
d R 6.23 86/05/30 18:57:03 karels 51 49
c change default dma burst per little bird
e
s 00003/00000/01423
d R 6.23 86/05/30 14:01:48 karels 50 49
c change default dma burst per little bird
e
s 00022/00010/01401
d D 6.22 86/05/16 14:27:02 karels 49 47
c add rd53
e
s 00014/00002/01409
d R 6.22 86/05/16 14:00:45 karels 48 47
c add rd52
e
s 00023/00000/01388
d D 6.21 86/04/22 11:05:07 kridle 47 46
c MicroVAX II Integration (KA630)
e
s 00000/00001/01388
d D 6.20 86/03/04 19:20:43 karels 46 45
c What do we care about quotas?!? (Especially if we don't know what they are!)
e
s 00013/00026/01376
d D 6.19 86/02/23 23:19:02 karels 45 44
c lint
e
s 00015/00014/01387
d D 6.18 86/02/20 19:54:23 karels 44 43
c lint
e
s 00004/00002/01397
d D 6.17 86/01/31 14:21:30 karels 43 42
c fix patchable burst
e
s 00004/00002/01395
d D 6.16 86/01/13 17:55:39 karels 42 41
c add patchable uda dma burst size (for what it's worth)
e
s 00009/00013/01388
d D 6.15 85/12/19 17:38:33 karels 41 40
c bug fixes for 750 bdp handling; COMPAT_42 => RA_COMPAT (for config)
e
s 00001/00000/01400
d D 6.14 85/10/13 19:45:03 karels 40 39
c missing splx
e
s 00053/00024/01347
d D 6.13 85/10/11 18:20:55 mckusick 39 38
c standardize partition sizes
e
s 00003/00001/01368
d D 6.12 85/09/16 22:10:06 karels 38 37
c off by one, and need resid
e
s 00022/00011/01347
d D 6.11 85/09/14 17:20:27 bloom 37 36
c get rid of interleave code, add macro to get unit number, add error return
c codes to strategy, reading last block after end of partition returns size = 0
e
s 00002/00016/01356
d D 6.10 85/08/22 12:11:53 karels 36 35
c from rich
e
s 00003/00001/01369
d D 6.9 85/08/08 13:53:10 bloom 35 34
c support partial dumps for large memory
e
s 00002/00001/01368
d D 6.8 85/08/05 19:36:24 bloom 34 33
c add support for 8600
e
s 00000/00006/01369
d D 6.7 85/06/09 09:30:06 mckusick 33 32
c delete Berkeley copyright
e
s 00008/00002/01367
d D 6.6 85/06/08 14:26:09 mckusick 32 31
c Add copyright
e
s 00001/00001/01368
d D 6.5 85/05/17 19:53:20 karels 31 30
c misplaced splx()
e
s 00007/00056/01362
d D 6.4 85/01/03 16:46:58 karels 30 29
c mark unused or truncated partitions correctly; unifdef binary
c still the same partitions for RA60/80/81
e
s 00719/00190/00699
d D 6.3 84/12/20 15:40:32 karels 29 28
c from rich
e
s 00005/00005/00884
d D 6.2 83/11/15 16:40:27 karels 28 27
c new partitions, for ra81 mostly (need separate partition tables!)
e
s 00000/00000/00889
d D 6.1 83/07/29 07:29:53 sam 27 26
c 4.2 distribution
e
s 00004/00013/00885
d D 4.25 83/07/09 01:32:08 sam 26 25
c back to old partition tables; have to handle all drive types
e
s 00001/00001/00897
d D 4.24 83/05/27 13:52:42 sam 25 24
c lint
e
s 00012/00000/00886
d D 4.23 83/05/18 05:41:43 sam 24 22
c add entry point to find partition size; for new swap stuff
e
s 00014/00000/00886
d R 4.23 83/05/18 02:21:21 sam 23 22
c add entry point for swap partition sizing at boot time
e
s 00001/00001/00885
d D 4.22 83/05/14 16:41:44 sam 22 21
c doesn't set transfer rate up properly
e
s 00041/00020/00845
d D 4.21 83/05/12 15:08:53 sam 21 20
c new from obrien@rand-unix; supposed to fix bdp management 
c problem on 750's; also kludge partition tables for ra81 for statvax
e
s 00001/00001/00864
d D 4.20 83/02/23 19:41:36 sam 20 19
c I give up on trying to figure out the correct address, supply many
e
s 00001/00003/00864
d D 4.19 83/02/23 13:29:10 sam 19 18
c kludge up for now
e
s 00001/00001/00866
d D 4.18 83/02/20 19:36:16 sam 18 17
c will someone please decide what the default address is!!!!!
e
s 00001/00001/00866
d D 4.17 82/12/18 14:31:40 sam 17 16
c fix standard address (for reference)
e
s 00001/00001/00866
d D 4.16 82/12/17 12:04:34 sam 16 15
c sun merge
e
s 00001/00001/00866
d D 4.15 82/11/13 23:01:02 sam 15 14
c merge of 4.1b with 4.1c
e
s 00001/00000/00866
d D 4.14 82/10/21 21:20:39 root 14 13
c lint
e
s 00000/00001/00866
d D 4.13 82/10/17 22:53:28 root 13 12
c lint
e
s 00006/00009/00861
d D 4.12 82/10/17 20:19:17 root 12 11
c lint
e
s 00006/00009/00864
d D 4.11 82/10/17 11:51:47 root 11 10
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00006/00005/00867
d D 4.10 82/10/10 17:29:34 root 10 9
c header files for vax are in their place
e
s 00004/00006/00868
d D 4.9 82/09/12 03:10:09 root 9 8
c 
e
s 00004/00003/00870
d D 4.8 82/08/22 21:21:30 root 8 7
c fully uio()'d
e
s 00006/00004/00867
d D 4.7 82/08/13 00:17:41 root 7 6
c changes for char dev uio'ing
e
s 00001/00001/00870
d D 4.6 82/07/15 19:58:57 kre 6 5
c probe routines return size of unibus dev regs to reserve space
e
s 00028/00018/00843
d D 4.5 82/05/27 16:13:46 sam 5 4
c mods from shannon
e
s 00001/00001/00860
d D 4.4 82/05/26 15:44:44 sam 4 3
c 7ZZ -> 730
e
s 00025/00016/00836
d D 4.3 82/03/14 17:55:42 sam 3 2
c lint
e
s 00006/00004/00846
d D 4.2 82/01/17 20:12:49 root 2 1
c make bio and disk drivers not do spl0 so can call from panic without trap 2's
e
s 00850/00000/00000
d D 4.1 81/11/04 11:03:14 wnj 1 0
c date and time created 81/11/04 11:03:14 by wnj
e
u
U
f b 
t
T
I 1
D 29
/*	%M%	%I%	%E%	*/
E 29
I 29
D 32
#ifndef lint
static	char	*sccsid = "%W%	(Berkeley) %G%";
E 32
I 32
/*
I 60
D 71
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 71
I 71
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 71
 *
E 60
D 33
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
E 33
D 71
 *	%W% (Berkeley) %G%
E 71
I 71
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
E 71
I 60
 *
I 71
 * Redistribution and use in source and binary forms are permitted
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
 *
 *	%W% (Berkeley) %G%
E 71
E 60
 */
D 33

E 32
#endif lint
E 33
E 29

I 29
D 60
/************************************************************************
 *									*
 *			Copyright (c) 1983 by				*
 *		Digital Equipment Corporation, Maynard, MA		*
 *			All rights reserved.				*
 *									*
 ************************************************************************/
/* 
 * uda.c - UDA50A Driver
D 41
 * 
 * Date:        Jan  30 1984
E 41
 *
D 41
 * This thing has been beaten beyound belief.  It still has two main features.
 * 1) When this device is on the same unibus as another DMA device
 * like a versatec or a rk07. the Udstrat routine complains that it still
 * has a buffered data path that it shouldn't.  I don't know why.
 *
 * decvax!rich.
 *
E 41
I 41
 * decvax!rich
E 60
I 60
/*
 * UDA50/MSCP device driver
E 60
E 41
 */

I 54
D 60
#define	COMPAT_42
E 54
#define	DEBUG
#define	UDADEVNUM	(9)		/* entry in bdevsw */
E 60
I 60
#define	POLLSTATS

/*
 * TODO
 *	write bad block forwarding code
 */

E 60
E 29
#include "ra.h"
I 60

E 60
D 29
#if NUDA > 0
E 29
I 29
D 30
#if NUDA > 0 || defined(BINARY)
E 30
I 30
#if NUDA > 0
I 60

E 60
E 30
E 29
/*
D 60
 * UDA50/RAxx disk device driver
E 60
I 60
 * CONFIGURATION OPTIONS.  The next three defines are tunable -- tune away!
E 60
 *
D 60
 * Restrictions:
D 29
 *	Unit numbers must be less than 8.
 *
 * TO DO:
 *	write dump code
E 29
I 29
 *      Unit numbers must be less than 8.
E 60
I 60
 * COMPAT_42 enables 4.2/4.3 compatibility (label mapping)
 *
 * NRSPL2 and NCMDL2 control the number of response and command
 * packets respectively.  They may be any value from 0 to 7, though
 * setting them higher than 5 is unlikely to be of any value.
 * If you get warnings about your command ring being too small,
 * try increasing the values by one.
 *
 * MAXUNIT controls the maximum unit number (number of drives per
 * controller) we are prepared to handle.
 *
 * DEFAULT_BURST must be at least 1.
E 60
D 39
 *      Partitions A and B must be the same size on all RA drives.
E 39
E 29
D 21
 *	test on 750
E 21
 */
I 60
#define	COMPAT_42

#define	NRSPL2	5		/* log2 number of response packets */
#define NCMDL2	5		/* log2 number of command packets */
#define	MAXUNIT	8		/* maximum allowed unit number */
#define	DEFAULT_BURST	4	/* default DMA burst size */

E 60
I 16
D 66
#include "../machine/pte.h"
E 16

E 66
D 29
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
D 16
#include "../h/pte.h"
E 16
#include "../h/map.h"
#include "../h/vm.h"
D 10
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 10
#include "../h/dk.h"
D 10
#include "../h/cpu.h"
E 10
#include "../h/cmap.h"
I 7
#include "../h/uio.h"
E 29
I 29
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
I 54
#include "file.h"
#include "ioctl.h"
E 54
#include "user.h"
#include "map.h"
#include "vm.h"
D 54
#include "dk.h"
E 54
I 54
#include "dkstat.h"
E 54
#include "cmap.h"
D 60
#include "uio.h"
E 60
I 54
#include "disklabel.h"
#include "syslog.h"
I 55
#include "stat.h"
E 55
E 54
E 29
E 7

I 66
#include "../machine/pte.h"

E 66
I 10
#include "../vax/cpu.h"
D 29
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 29
I 29
#include "ubareg.h"
#include "ubavar.h"
D 60
#include "../vax/mtpr.h"
E 60
E 29
I 12

D 29
#define	NRSPL2	3		/* log2 number of response packets */
#define	NCMDL2	3		/* log2 number of command packets */
#define	NRSP	(1<<NRSPL2)
#define	NCMD	(1<<NCMDL2)
E 29
I 29
D 60
#define TENSEC	(1000)
 
#define NRSPL2  3               /* log2 number of response packets */
#define NCMDL2  3               /* log2 number of command packets */
#define NRSP    (1<<NRSPL2)
#define NCMD    (1<<NCMDL2)
I 52
#define	UDABURST	4	/* default for DMA burst size */
E 60
I 60
#define	NRSP	(1 << NRSPL2)
#define	NCMD	(1 << NCMDL2)
E 60
E 52
E 29

E 12
D 60
#include "../vaxuba/udareg.h"
E 60
I 60
#include "udareg.h"
E 60
D 21

E 10
int udadebug;
#define	printd	if(udadebug&1)printf

I 5
int udaerror = 0;	/* set to cause hex dump of error log packets */
D 12

E 5
/*
 * Parameters for the communications area
 */

D 5
#define	NRSPL2	3
#define	NCMDL2	3
E 5
I 5
#define	NRSPL2	3		/* log2 number of response packets */
#define	NCMDL2	3		/* log2 number of command packets */
E 5
#define	NRSP	(1<<NRSPL2)
#define	NCMD	(1<<NCMDL2)
E 12

E 21
D 10
#include "../h/udareg.h"
#include "../h/mscp.h"
E 10
I 10
#include "../vax/mscp.h"
I 60
#include "../vax/mscpvar.h"
#include "../vax/mtpr.h"
E 60
E 10

I 60
/*
D 66
 * Backwards compatibility:  Reuse the old names.  Should fix someday.
 */
#define	udaprobe	udprobe
#define	udaslave	udslave
#define	udaattach	udattach
#define	udaopen		udopen
#define	udaclose	udclose
#define	udastrategy	udstrategy
#define	udaread		udread
#define	udawrite	udwrite
#define	udaioctl	udioctl
#define	udareset	udreset
#define	udaintr		udintr
#define	udadump		uddump
#define	udasize		udsize
E 60
D 29
struct uda_softc {
	short	sc_state;	/* state of controller */
	short	sc_mapped;	/* Unibus map allocated for uda struct? */
	int	sc_ubainfo;	/* Unibus mapping info */
	struct uda *sc_uda;	/* Unibus address of uda struct */
	int	sc_ivec;	/* interrupt vector address */
	short	sc_credits;	/* transfer credits */
	short	sc_lastcmd;	/* pointer into command ring */
	short	sc_lastrsp;	/* pointer into response ring */
} uda_softc[NUDA];
E 29
I 29
D 30
#ifdef	BINARY
E 30
E 29

D 29
/*
 * Controller states
 */
#define	S_IDLE	0		/* hasn't been initialized */
#define	S_STEP1	1		/* doing step 1 init */
#define	S_STEP2	2		/* doing step 2 init */
#define	S_STEP3	3		/* doing step 3 init */
#define	S_SCHAR	4		/* doing "set controller characteristics" */
#define	S_RUN	5		/* running */
E 29
I 29
D 30
extern	struct uda_softc {
	short   sc_state;       /* state of controller */
	short   sc_mapped;      /* Unibus map allocated for uda struct? */
	int     sc_ubainfo;     /* Unibus mapping info */
	struct uda *sc_uda;     /* Unibus address of uda struct */
	int     sc_ivec;        /* interrupt vector address */
	short   sc_credits;     /* transfer credits */
	short   sc_lastcmd;     /* pointer into command ring */
	short   sc_lastrsp;     /* pointer into response ring */
} uda_softc[];
struct uda {
	struct udaca    uda_ca;         /* communications area */
	struct mscp     uda_rsp[NRSP];  /* response packets */
	struct mscp     uda_cmd[NCMD];  /* command packets */
} uda[];
E 29

I 29
/* THIS SHOULD BE READ OFF THE PACK, PER DRIVE */
extern struct size {
	daddr_t nblocks;
	daddr_t blkoff;
}  ra25_sizes[], ra60_sizes[], ra80_sizes[], ra81_sizes[];


/* END OF STUFF WHICH SHOULD BE READ IN PER DISK */

struct	ra_info {
	struct  size    *ra_sizes;	/* Partion tables for drive */
	daddr_t		radsize;	/* Max user size form online pkt */
	unsigned	ratype;		/* Drive type int field  */
	unsigned	rastatus;	/* Command status from */
					/* last onlin or GTUNT */
} ra_info[];

extern struct  uba_ctlr *udminfo[];
extern	struct  uba_device *uddinfo[];
extern struct  uba_device *udip[][8];      /* 8 == max number of drives */
extern	struct  buf rudbuf[];
extern	struct  buf udutab[];		/* Drive queue */
extern struct  buf udwtab[];               /* I/O wait queue, per controller */
extern int     udamicro[];         /* to store microcode level */

extern	int     nNRA;
extern int     nNUDA;

#else

E 30
D 60
struct uda_softc {
	short   sc_state;       /* state of controller */
	short   sc_mapped;      /* Unibus map allocated for uda struct? */
	int     sc_ubainfo;     /* Unibus mapping info */
	struct uda *sc_uda;     /* Unibus address of uda struct */
	int     sc_ivec;        /* interrupt vector address */
	short   sc_credits;     /* transfer credits */
	short   sc_lastcmd;     /* pointer into command ring */
	short   sc_lastrsp;     /* pointer into response ring */
} uda_softc[NUDA];
E 29
struct uda {
D 29
	struct udaca	uda_ca;		/* communications area */
	struct mscp	uda_rsp[NRSP];	/* response packets */
	struct mscp	uda_cmd[NCMD];	/* command packets */
E 29
I 29
	struct udaca    uda_ca;         /* communications area */
	struct mscp     uda_rsp[NRSP];  /* response packets */
	struct mscp     uda_cmd[NCMD];  /* command packets */
E 60
I 60
/*
E 66
 * UDA communications area and MSCP packet pools, per controller.
 */
struct	uda {
	struct	udaca uda_ca;		/* communications area */
	struct	mscp uda_rsp[NRSP];	/* response packets */
	struct	mscp uda_cmd[NCMD];	/* command packets */
E 60
E 29
} uda[NUDA];

I 37
D 60
#define udunit(dev)	(minor(dev) >> 3)
I 54
#define udpart(dev)	(minor(dev) & 07)
#define udminor(unit, part)	(((unit) << 3) | (part))
E 60
I 60
/*
 * Software status, per controller.
 */
struct	uda_softc {
	struct	uda *sc_uda;	/* Unibus address of uda struct */
	short	sc_state;	/* UDA50 state; see below */
	short	sc_flags;	/* flags; see below */
	int	sc_micro;	/* microcode revision */
	int	sc_ivec;	/* interrupt vector address */
I 73
	short	sc_ipl;		/* interrupt priority, Q-bus */
E 73
	struct	mscp_info sc_mi;/* MSCP info (per mscpvar.h) */
#ifndef POLLSTATS
	int	sc_wticks;	/* watchdog timer ticks */
#else
	short	sc_wticks;
	short	sc_ncmd;
#endif
} uda_softc[NUDA];
E 60
E 54

E 37
D 54
/* THIS SHOULD BE READ OFF THE PACK, PER DRIVE */
struct size {
D 29
	daddr_t	nblocks;
	daddr_t	blkoff;
} ra_sizes[8] ={
E 29
I 29
	daddr_t nblocks;
	daddr_t blkoff;
}  ra25_sizes[8] = {
E 29
I 21
D 26
#ifdef notdef
E 26
E 21
	15884,	0,		/* A=blk 0 thru 15883 */
I 29
	10032,	15884,		/* B=blk 15884 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
	0,	0,		/* D=blk 340670 thru 356553 */
	0,	0,		/* E=blk 356554 thru 412489 */
	0,	0,		/* F=blk 412490 thru end */
	-1,	25916,		/* G=blk 49324 thru 131403 */
	0,	0,		/* H=blk 131404 thru end */
I 47
D 49
}, ra53_sizes[8] = {
	15884,	0,
	33440,	15884,
	-1,	0,
	0,	0,
	33440,	0,
	-1,	33440,
	-1,	15884,
	-1,	49324,
E 49
I 49
}, rd52_sizes[8] = {
	15884,	0,		/* A=blk 0 thru 15883 */
	9766,	15884,		/* B=blk 15884 thru 25649 */
	-1,	0,		/* C=blk 0 thru end */
	0,	0,		/* D=unused */
	0,	0,		/* E=unused */
	0,	0,		/* F=unused */
	-1,	25650,		/* G=blk 25650 thru end */
	0,	0,		/* H=unused */
}, rd53_sizes[8] = {
	15884,	0,		/* A=blk 0 thru 15883 */
	33440,	15884,		/* B=blk 15884 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
	0,	0,		/* D=unused */
	33440,	0,		/* E=blk 0 thru 33439 */
	-1,	33440,		/* F=blk 33440 thru end */
	-1,	49324,		/* G=blk 49324 thru end */
	-1,	15884,		/* H=blk 15884 thru end */
E 49
E 47
}, ra60_sizes[8] = {
D 39
	15884,	0,		/* A=blk 0 thru 15883 */
E 29
	33440,	15884,		/* B=blk 15884 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
D 5
	0,	0,		/* D reserved for RA81 */
	0,	0,		/* E reserved for RA81 */
	0,	0,		/* F reserved for RA81 */
E 5
I 5
D 28
	15884,	340670,		/* D=blk 340670 thru 356553 */
	55936,	356554,		/* E=blk 356554 thru 412489 */
	-1,	412490,		/* F=blk 412490 thru end */
E 5
	82080,	49324,		/* G=blk 49324 thru 131403 */
	-1,	131404,		/* H=blk 131404 thru end */
E 28
I 28
	15884,	242606,		/* D=blk 242606 thru 258489 */
D 30
	307200,	258490,		/* E=blk 258490 thru 565689 */
	-1,	565690,		/* F=blk 565690 thru end */
E 30
I 30
	-1,	258490,		/* E=blk 258490 thru end */
	0,	0,		/* F=unused */
E 30
	-1,	242606,		/* G=blk 242606 thru end */
	193282,	49324,		/* H=blk 49324 thru 242605 */
E 39
I 39
	15884,	0,		/* A=sectors 0 thru 15883 */
	33440,	15884,		/* B=sectors 15884 thru 49323 */
	400176,	0,		/* C=sectors 0 thru 400175 */
	82080,	49324,		/* 4.2 G => D=sectors 49324 thru 131403 */
	268772,	131404,		/* 4.2 H => E=sectors 131404 thru 400175 */
	350852,	49324,		/* F=sectors 49324 thru 400175 */
	157570,	242606,		/* UCB G => G=sectors 242606 thru 400175 */
	193282,	49324,		/* UCB H => H=sectors 49324 thru 242605 */
E 39
I 29
}, ra80_sizes[8] = {
D 39
	15884,	0,		/* A=blk 0 thru 15883 */
	33440,	15884,		/* B=blk 15884 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
E 39
I 39
	15884,	0,		/* A=sectors 0 thru 15883 */
	33440,	15884,		/* B=sectors 15884 thru 49323 */
	242606,	0,		/* C=sectors 0 thru 242605 */
E 39
D 30
	15884,	242606,		/* D=blk 242606 thru 258489 */
	307200,	258490,		/* E=blk 258490 thru 565689 */
	-1,	565690,		/* F=blk 565690 thru end */
	-1,	242606,		/* G=blk 242606 thru end */
E 30
I 30
	0,	0,		/* D=unused */
D 39
	0,	0,		/* E=unused */
	0,	0,		/* F=unused */
	0,	0,		/* G=unused */
E 30
	193282,	49324,		/* H=blk 49324 thru 242605 */
E 39
I 39
	193282,	49324,		/* UCB H => E=sectors 49324 thru 242605 */
	82080,	49324,		/* 4.2 G => F=sectors 49324 thru 131403 */
	192696,	49910,		/* G=sectors 49910 thru 242605 */
	111202,	131404,		/* 4.2 H => H=sectors 131404 thru 242605 */
E 39
}, ra81_sizes[8] ={
D 39
	15884,	0,		/* A=blk 0 thru 15883 */
	33440,	15884,		/* B=blk 15884 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
	15884,	242606,		/* D=blk 242606 thru 258489 */
	307200,	258490,		/* E=blk 258490 thru 565689 */
	-1,	565690,		/* F=blk 565690 thru end */
	-1,	242606,		/* G=blk 242606 thru end */
	193282,	49324,		/* H=blk 49324 thru 242605 */
E 39
I 39
/*
 * These are the new standard partition sizes for ra81's.
D 41
 * A COMPAT_42 system is compiled with D, E, and F corresponding
E 41
I 41
 * An RA_COMPAT system is compiled with D, E, and F corresponding
E 41
 * to the 4.2 partitions for G, H, and F respectively.
 */
#ifndef	UCBRA
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16422,		/* B=sectors 16422 thru 83301 */
	891072,	0,		/* C=sectors 0 thru 891071 */
D 41
#ifdef COMPAT_42
E 41
I 41
#ifdef RA_COMPAT
E 41
	82080,	49324,		/* 4.2 G => D=sectors 49324 thru 131403 */
	759668,	131404,		/* 4.2 H => E=sectors 131404 thru 891071 */
	478582,	412490,		/* 4.2 F => F=sectors 412490 thru 891071 */
#else
	15884,	375564,		/* D=sectors 375564 thru 391447 */
	307200,	391986,		/* E=sectors 391986 thru 699185 */
	191352,	699720,		/* F=sectors 699720 thru 891071 */
D 41
#endif COMPAT_42
E 41
I 41
#endif RA_COMPAT
E 41
	515508,	375564,		/* G=sectors 375564 thru 891071 */
	291346,	83538,		/* H=sectors 83538 thru 374883 */

/*
 * These partitions correspond to the sizes used by sites at Berkeley,
 * and by those sites that have received copies of the Berkeley driver
 * with deltas 6.2 or greater (11/15/83).
 */
#else UCBRA

	15884,	0,		/* A=sectors 0 thru 15883 */
	33440,	15884,		/* B=sectors 15884 thru 49323 */
	891072,	0,		/* C=sectors 0 thru 891071 */
	15884,	242606,		/* D=sectors 242606 thru 258489 */
	307200,	258490,		/* E=sectors 258490 thru 565689 */
	325382,	565690,		/* F=sectors 565690 thru 891071 */
	648466,	242606,		/* G=sectors 242606 thru 891071 */
	193282,	49324,		/* H=sectors 49324 thru 242605 */

#endif UCBRA
E 39
E 29
E 28
I 21
D 26
} ra81_sizes[8] = {
#endif
	15884,	0,		/* A=cyl 0 thru 22 */
	66880,	16422,		/* B=cyl 23 thru 116 */
	-1,	0,		/* C=cyl 0 thru end */
	15884,	375564,		/* D=cyl 526 thru 548 */
	307200,	391986,		/* E=cyl 549 thru 979 */
	-1,	699720,		/* F=cyl 980 thru end */
	-1,	375564,		/* G=cyl 526 thru end */
	291346,	83538,		/* H=cyl 117 thru 525 */
E 26
E 21
};
I 29

E 54
D 60
struct	ra_info {
D 54
	struct  size    *ra_sizes;	/* Partion tables for drive */
E 54
	daddr_t		radsize;	/* Max user size form online pkt */
	unsigned	ratype;		/* Drive type int field  */
	unsigned	rastatus;	/* Command status from */
					/* last onlin or GTUNT */
I 54
	int		rastate;   	/* open/closed state */
	u_long		openpart;	/* partitions open */
I 55
	u_long		bopenpart;	/* block partitions open */
	u_long		copenpart;	/* characters partitions open */
E 55
E 54
} ra_info[NRA];
E 60
I 60
#ifdef POLLSTATS
struct udastats {
	int	ncmd;
	int	cmd[NCMD + 1];
} udastats = { NCMD + 1 };
#endif
E 60

D 54

E 29
/* END OF STUFF WHICH SHOULD BE READ IN PER DISK */
E 54
I 29
D 60
struct  uba_ctlr *udminfo[NUDA];
struct  uba_device *uddinfo[NRA];
struct  uba_device *udip[NUDA][8];      /* 8 == max number of drives */
I 54
struct  disklabel udlabel[NRA];
E 54
struct  buf rudbuf[NRA];
struct  buf udutab[NRA];
struct  buf udwtab[NUDA];               /* I/O wait queue, per controller */
E 60
I 60
/*
 * Controller states
 */
#define	ST_IDLE		0	/* uninitialised */
#define	ST_STEP1	1	/* in `STEP 1' */
#define	ST_STEP2	2	/* in `STEP 2' */
#define	ST_STEP3	3	/* in `STEP 3' */
#define	ST_SETCHAR	4	/* in `Set Controller Characteristics' */
#define	ST_RUN		5	/* up and running */
E 60
E 29

I 60
/*
 * Flags
 */
#define	SC_MAPPED	0x01	/* mapped in Unibus I/O space */
#define	SC_INSTART	0x02	/* inside udastart() */
#define	SC_GRIPED	0x04	/* griped about cmd ring too small */
#define	SC_INSLAVE	0x08	/* inside udaslave() */
#define	SC_DOWAKE	0x10	/* wakeup when ctlr init done */
#define	SC_STARTPOLL	0x20	/* need to initiate polling */
E 60
I 21
D 29
int	udaerror = 0;			/* causes hex dump of packets */
int	udadebug = 0;
#define	printd	if (udadebug) printf
E 29

E 21
D 29
daddr_t	radsize[NRA];			/* disk size, from ONLINE end packet */
E 29
I 29
D 45
int     nNRA = NRA;
int     nNUDA = NUDA;
E 45
D 60
int     udamicro[NUDA];         /* to store microcode level */
I 42
int     udaburst[NUDA] = { 0 };	/* DMA burst size, 0 is default */
E 60
I 60
/*
 * Device to unit number and partition and back
 */
#define	UNITSHIFT	3
#define	UNITMASK	7
#define	udaunit(dev)	(minor(dev) >> UNITSHIFT)
#define	udapart(dev)	(minor(dev) & UNITMASK)
#define	udaminor(u, p)	(((u) << UNITSHIFT) | (p))
E 60
E 42
E 29

D 29
int	udprobe(), udslave(), udattach(), udintr();
struct	mscp *udgetcp();
struct	uba_ctlr *udminfo[NUDA];
struct	uba_device *uddinfo[NRA];
struct	uba_device *udip[NUDA][8];	/* 8 == max number of drives */
E 29
D 30

D 5
u_short	udstd[] = { 0777550, 0 };
E 5
I 5
D 17
u_short	udstd[] = { 0772150, 0 };
E 17
I 17
D 18
u_short	udstd[] = { 0772550, 0 };
E 18
I 18
D 20
u_short	udstd[] = { 0772150, 0 };
E 20
I 20
D 29
u_short	udstd[] = { 0772150, 0772550, 0777550, 0 };
E 20
E 18
E 17
E 5
struct	uba_driver udadriver =
E 29
I 29
#endif
E 30
D 60

E 60
/*
D 60
 * Controller states
E 60
I 60
 * Drive status, per drive
E 60
 */
D 60
#define S_IDLE  0               /* hasn't been initialized */
#define S_STEP1 1               /* doing step 1 init */
#define S_STEP2 2               /* doing step 2 init */
#define S_STEP3 3               /* doing step 3 init */
#define S_SCHAR 4               /* doing "set controller characteristics" */
#define S_RUN   5               /* running */
E 60
I 60
struct ra_info {
	daddr_t	ra_dsize;	/* size in sectors */
D 65
	u_long	ra_type;	/* drive type */
E 65
I 65
/*	u_long	ra_type;	/* drive type */
E 65
I 63
D 70
#define	RA_TYPE_RX50	7	/* special: see udaopen */
E 70
E 63
	u_long	ra_mediaid;	/* media id */
	int	ra_state;	/* open/closed state */
	struct	ra_geom {	/* geometry information */
		u_short	rg_nsectors;	/* sectors/track */
		u_short	rg_ngroups;	/* track groups */
		u_short	rg_ngpc;	/* groups/cylinder */
		u_short	rg_ntracks;	/* ngroups*ngpc */
		u_short	rg_ncyl;	/* ra_dsize/ntracks/nsectors */
#ifdef notyet
		u_short	rg_rctsize;	/* size of rct */
		u_short	rg_rbns;	/* replacement blocks per track */
		u_short	rg_nrct;	/* number of rct copies */
#endif
	} ra_geom;
I 64
	int	ra_wlabel;	/* label sector is currently writable */
E 64
	u_long	ra_openpart;	/* partitions open */
	u_long	ra_bopenpart;	/* block partitions open */
	u_long	ra_copenpart;	/* character partitions open */
} ra_info[NRA];
E 60

I 54
/*
D 75
 * Software state, per drive
E 75
I 75
 * Software state, per drive. The CLOSED, WANTOPEN, RDLABEL, OPEN, and OPENRAW
 * states are just like in the other drivers, but the ONLINE state doesn't
 * exist in other drivers and didn't exist in earlier versions of this driver.
 * In other drivers, the OPEN and OPENRAW states are entered in a routine like
 * hpinit or upinit, which is only called synchronously, when either attaching
 * or opening a drive. In our case, however, a drive comes on-line
 * asynchronously, at interrupt time in udaonline. Earlier versions of this
 * entered the OPENRAW state in udaonline. This was a disaster. udaonline
 * doesn't really open the drive, the state it puts the drive in is really just
 * a slightly different form of the CLOSED state. Declaring it to be open, even
 * raw, when it really isn't, was a horrible bug. udaopen would treat it as
 * being already open and wouldn't try to call uda_rainit to read the label,
 * but since it really isn't open and has no partitions defined, trying to open
 * any partition resulted in ENXIO, rendering the disk completely inaccessible.
 *
 * The ONLINE state has been added to solve this problem. It is a stable state
 * like CLOSED, OPEN, or OPENRAW, and udaopen treats it the same way as CLOSED,
 * i.e., calls uda_rainit to read the label.
E 75
 */
#define	CLOSED		0
#define	WANTOPEN	1
D 75
#define	RDLABEL		2
#define	OPEN		3
#define	OPENRAW		4
E 75
I 75
#define ONLINE		2
#define	RDLABEL		3
#define	OPEN		4
#define	OPENRAW		5
E 75
E 54

D 60
int     udaerror = 0;                   /* causes hex dump of packets */
int     udadebug = 0;
int	uda_cp_wait = 0;		/* Something to wait on for command */
					/* packets and or credits. */
int	wakeup();
extern	int	hz;			/* Should find the right include */
#ifdef	DEBUG
#define printd  if (udadebug) printf
#define	printd10	if(udadebug >= 10) printf
#endif 
#define mprintf printf			/* temporary JG hack until Rich fixes*/
E 60
I 60
/*
 * Definition of the driver for autoconf.
 */
int	udaprobe(), udaslave(), udaattach(), udadgo(), udaintr();
struct	uba_ctlr *udaminfo[NUDA];
struct	uba_device *udadinfo[NRA];
struct	disklabel udalabel[NRA];
E 60

D 55
int     udprobe(), udslave(), udattach(), udintr();
E 55
I 55
D 60
int     udprobe(), udslave(), udattach(), udintr(), udstrategy();
E 55
struct  mscp *udgetcp();
E 60
I 60
u_short	udastd[] = { 0772150, 0772550, 0777550, 0 };
struct	uba_driver udadriver =
 { udaprobe, udaslave, udaattach, udadgo, udastd, "ra", udadinfo, "uda",
   udaminfo };
E 60

D 60
u_short udstd[] = { 0772150, 0772550, 0777550, 0 };
struct  uba_driver udadriver =
E 29
 { udprobe, udslave, udattach, 0, udstd, "ra", uddinfo, "uda", udminfo, 0 };
E 60
I 60
/*
 * More driver definitions, for generic MSCP code.
 */
int	udadgram(), udactlrdone(), udaunconf(), udaiodone();
int	udaonline(), udagotstatus(), udaioerror(), udareplace(), udabb();
E 60
D 29
struct	buf rudbuf[NRA];
struct	buf udutab[NRA];
struct	buf udwtab[NUDA];		/* I/O wait queue, per controller */
E 29

D 29
#define	b_qsize		b_resid		/* queue size per drive, in udutab */
#define	b_ubinfo	b_resid		/* Unibus mapping info, per buffer */
E 29
I 29
D 60
#define b_qsize         b_resid         /* queue size per drive, in udutab */
#define b_ubinfo        b_resid         /* Unibus mapping info, per buffer */
E 60
I 60
struct	buf udautab[NRA];	/* per drive transfer queue */
E 60
E 29

D 60
udprobe(reg, ctlr)
E 60
I 60
struct	mscp_driver udamscpdriver =
D 68
 { MAXUNIT, NRA, UNITSHIFT, udautab, udadinfo,
E 68
I 68
 { MAXUNIT, NRA, UNITSHIFT, udautab, udalabel, udadinfo,
E 68
   udadgram, udactlrdone, udaunconf, udaiodone,
   udaonline, udagotstatus, udareplace, udaioerror, udabb,
   "uda", "ra" };

/*
 * Miscellaneous private variables.
 */
char	udasr_bits[] = UDASR_BITS;

struct	uba_device *udaip[NUDA][MAXUNIT];
				/* inverting pointers: ctlr & unit => Unibus
				   device pointer */

int	udaburst[NUDA] = { 0 };	/* burst size, per UDA50, zero => default;
				   in data space so patchable via adb */

struct	mscp udaslavereply;	/* get unit status response packet, set
				   for udaslave by udaunconf, via udaintr */

static struct uba_ctlr *probeum;/* this is a hack---autoconf should pass ctlr
				   info to slave routine; instead, we remember
				   the last ctlr argument to probe */

int	udawstart, udawatch();	/* watchdog timer */

/*
 * Externals
 */
int	wakeup();
int	hz;

/*
 * Poke at a supposed UDA50 to see if it is there.
 * This routine duplicates some of the code in udainit() only
 * because autoconf has not set up the right information yet.
 * We have to do everything `by hand'.
 */
udaprobe(reg, ctlr, um)
E 60
	caddr_t reg;
	int ctlr;
I 60
	struct uba_ctlr *um;
E 60
{
	register int br, cvec;
D 60
	register struct uda_softc *sc = &uda_softc[ctlr];
I 29
	struct udadevice *udaddr;
E 60
I 60
	register struct uda_softc *sc;
	register struct udadevice *udaddr;
	register struct mscp_info *mi;
D 73
	int timeout, tries;
E 73
I 73
	int timeout, tries, s;
E 73
E 60
E 29

I 29
D 60
	int	cur_time;
E 60
I 60
#ifdef VAX750
	/*
	 * The UDA50 wants to share BDPs on 750s, but not on 780s or
	 * 8600s.  (730s have no BDPs anyway.)  Toward this end, we
	 * here set the `keep bdp' flag in the per-driver information
	 * if this is a 750.  (We just need to do it once, but it is
	 * easiest to do it now, for each UDA50.)
	 */
	if (cpu == VAX_750)
		udadriver.ud_keepbdp = 1;
#endif
E 60

I 60
	probeum = um;			/* remember for udaslave() */
E 60
E 29
#ifdef lint
D 3
	br = 0; cvec = br; br = cvec;
E 3
I 3
D 29
	br = 0; cvec = br; br = cvec; reg = reg;
E 29
I 29
D 60
	br = 0; cvec = br; br = cvec;
E 29
I 14
D 21
	udintr(0);
E 21
I 21
D 25
	udread(0); udwrite(0); udreset(0); udintr(0);
E 25
I 25
	udreset(0); udintr(0);
E 60
I 60
	br = 0; cvec = br; br = cvec; udaintr(0);
E 60
E 25
E 21
E 14
D 7
	udread(0); udwrite(0); udreset(0); udintr(0);
E 7
I 7
D 8
	udread(0, 0); udwrite(0); udreset(0); udintr(0);
E 8
I 8
D 13
	udread(0, 0); udwrite(0, 0); udreset(0); udintr(0);
E 13
E 8
E 7
E 3
#endif
D 29
	/* SHOULD CHECK THAT IT REALLY IS A UDA */
	br = 0x15;
	cvec = sc->sc_ivec = (uba_hd[numuba].uh_lastiv -= 4);
E 29
I 29
D 60
	udaddr = (struct udadevice *) reg;
E 60
I 60
	/*
	 * Set up the controller-specific generic MSCP driver info.
	 * Note that this should really be done in the (nonexistent)
	 * controller attach routine.
	 */
	sc = &uda_softc[ctlr];
	mi = &sc->sc_mi;
	mi->mi_md = &udamscpdriver;
	mi->mi_ctlr = um->um_ctlr;
	mi->mi_tab = &um->um_tab;
	mi->mi_ip = udaip[ctlr];
	mi->mi_cmd.mri_size = NCMD;
	mi->mi_cmd.mri_desc = uda[ctlr].uda_ca.ca_cmddsc;
	mi->mi_cmd.mri_ring = uda[ctlr].uda_cmd;
	mi->mi_rsp.mri_size = NRSP;
	mi->mi_rsp.mri_desc = uda[ctlr].uda_ca.ca_rspdsc;
	mi->mi_rsp.mri_ring = uda[ctlr].uda_rsp;
	mi->mi_wtab.av_forw = mi->mi_wtab.av_back = &mi->mi_wtab;
E 60

I 60
	/*
	 * More controller specific variables.  Again, this should
	 * be in the controller attach routine.
	 */
	if (udaburst[ctlr] == 0)
		udaburst[ctlr] = DEFAULT_BURST;
		
	/*
	 * Get an interrupt vector.  Note that even if the controller
	 * does not respond, we keep the vector.  This is not a serious
	 * problem; but it would be easily fixed if we had a controller
	 * attach routine.  Sigh.
	 */
E 60
	sc->sc_ivec = (uba_hd[numuba].uh_lastiv -= 4);
I 47
D 60
#if VAX630
	if (cpu == VAX_630) {
		br = 0x15;
		cvec = sc->sc_ivec;
 		return(sizeof (struct udadevice));
	}
#endif
E 47
	udaddr->udaip = 0;              /* start initialization */
E 60
I 60
	udaddr = (struct udadevice *) reg;
E 60

D 60
	cur_time = mfpr(TODR);			/* Time of day */
	while(cur_time + TENSEC > mfpr(TODR)){	/* wait for at most 10 secs */
		if((udaddr->udasa & UDA_STEP1) != 0)
			break;
	}
	if(cur_time + TENSEC <= mfpr(TODR))
		return(0);		/* Not a uda or it won't init as it  */
					/* should within ten seconds.  */
	udaddr->udasa=UDA_ERR|(NCMDL2<<11)|(NRSPL2<<8)|UDA_IE|(sc->sc_ivec/4);
	while((udaddr->udasa&UDA_STEP2)==0)
		DELAY(1000);		/* intr should have */
					/*   have happened by now */
	
E 29
D 6
	return(1);
E 6
I 6
	return(sizeof (struct udadevice));
E 60
I 60
	/*
	 * Initialise the controller (partially).  The UDA50 programmer's
	 * manual states that if initialisation fails, it should be retried
	 * at least once, but after a second failure the port should be
	 * considered `down'; it also mentions that the controller should
	 * initialise within ten seconds.  Or so I hear; I have not seen
	 * this manual myself.
	 */
I 73
D 74
#ifdef QBA
	s = spl6();
#endif
E 74
E 73
	tries = 0;
again:
	udaddr->udaip = 0;		/* start initialisation */
	timeout = todr() + 1000;	/* timeout in 10 seconds */
	while ((udaddr->udasa & UDA_STEP1) == 0)
		if (todr() > timeout)
			goto bad;
	udaddr->udasa = UDA_ERR | (NCMDL2 << 11) | (NRSPL2 << 8) | UDA_IE |
		(sc->sc_ivec >> 2);
	while ((udaddr->udasa & UDA_STEP2) == 0)
		if (todr() > timeout)
			goto bad;

	/* should have interrupted by now */
D 72
#ifdef VAX630
	if (cpu == VAX_630)
E 72
I 72
#ifdef QBA
D 73
	if (cpu == VAX_630 || cpu == VAX_650)
E 72
		br = 0x15;	/* screwy interrupt structure */
E 73
I 73
D 74
	sc->sc_ipl = br = qbgetpri();
E 74
I 74
	sc->sc_ipl = br = 0x15;
E 74
E 73
#endif
	return (sizeof (struct udadevice));
bad:
	if (++tries < 2)
		goto again;
I 73
D 74
	splx(s);
E 74
E 73
	return (0);
E 60
E 6
}

I 44
D 60
/* ARGSUSED */
E 44
udslave(ui, reg)
	struct uba_device *ui;
E 60
I 60
/*
 * Find a slave.  We allow wildcard slave numbers (something autoconf
 * is not really prepared to deal with); and we need to know the
 * controller number to talk to the UDA.  For the latter, we keep
 * track of the last controller probed, since a controller probe
 * immediately precedes all slave probes for that controller.  For the
 * former, we simply put the unit number into ui->ui_slave after we
 * have found one.
 *
 * Note that by the time udaslave is called, the interrupt vector
 * for the UDA50 has been set up (so that udaunconf() will be called).
 */
udaslave(ui, reg)
	register struct uba_device *ui;
E 60
	caddr_t reg;
{
D 29
	/*
	 * TOO HARD TO FIND OUT IF DISK IS THERE UNTIL
	 * INITIALIZED.  WE'LL FIND OUT WHEN WE FIRST
	 * TRY TO ACCESS IT.
	 */
E 29
I 29
D 60
	register struct uba_ctlr *um = udminfo[ui->ui_ctlr];
	register struct uda_softc *sc = &uda_softc[ui->ui_ctlr];
	struct udadevice *udaddr;
	struct	mscp	*mp;
	int	i;			/* Something to write into to start */
					/* the uda polling */
E 60
I 60
	register struct uba_ctlr *um = probeum;
	register struct mscp *mp;
	register struct uda_softc *sc;
D 67
	register struct ra_info *ra;
E 67
D 64
	int next = 0, type, timeout, tries, i;
E 64
I 64
	int next = 0, timeout, tries, i;
E 64
E 60

I 60
#ifdef lint
	i = 0; i = i;
#endif
	/*
	 * Make sure the controller is fully initialised, by waiting
	 * for it if necessary.
	 */
	sc = &uda_softc[um->um_ctlr];
	if (sc->sc_state == ST_RUN)
		goto findunit;
	tries = 0;
again:
	if (udainit(ui->ui_ctlr))
		return (0);
	timeout = todr() + 1000;		/* 10 seconds */
	while (todr() < timeout)
		if (sc->sc_state == ST_RUN)	/* made it */
			goto findunit;
	if (++tries < 2)
		goto again;
	printf("uda%d: controller hung\n", um->um_ctlr);
	return (0);
E 60

E 29
I 3
D 44
#ifdef lint
D 29
	ui = ui; reg = reg;
E 29
I 29
	ui = ui; reg = reg; i = i;
E 29
#endif
E 44
E 3
D 29
	return(1);
E 29
I 29
D 60
	udaddr = (struct udadevice *)um->um_addr;
	if(sc->sc_state != S_RUN){
		if(!udinit(ui->ui_ctlr))
			return(0);
E 60
I 60
	/*
	 * The controller is all set; go find the unit.  Grab an
	 * MSCP packet and send out a Get Unit Status command, with
	 * the `next unit' modifier if we are looking for a generic
	 * unit.  We set the `in slave' flag so that udaunconf()
	 * knows to copy the response to `udaslavereply'.
	 */
findunit:
	udaslavereply.mscp_opcode = 0;
	sc->sc_flags |= SC_INSLAVE;
	if ((mp = mscp_getcp(&sc->sc_mi, MSCP_DONTWAIT)) == NULL)
		panic("udaslave");		/* `cannot happen' */
	mp->mscp_opcode = M_OP_GETUNITST;
	if (ui->ui_slave == '?') {
		mp->mscp_unit = next;
		mp->mscp_modifier = M_GUM_NEXTUNIT;
	} else {
		mp->mscp_unit = ui->ui_slave;
		mp->mscp_modifier = 0;
E 60
	}
D 60
	/* Here we will wait for the controller */
	/* to come into the run state or go idle.  If we go idle we are in */
	/* touble and I don't yet know what to do so I will punt */
	while(sc->sc_state != S_RUN && sc->sc_state != S_IDLE);	/* spin */
	if(sc->sc_state == S_IDLE){	/* The Uda failed to initialize */
		printf("UDA failed to init\n");
		return(0);
E 60
I 60
	*mp->mscp_addr |= MSCP_OWN | MSCP_INT;
	i = ((struct udadevice *) reg)->udaip;	/* initiate polling */
	mp = &udaslavereply;
	timeout = todr() + 1000;
	while (todr() < timeout)
		if (mp->mscp_opcode)
			goto gotit;
	printf("uda%d: no response to Get Unit Status request\n",
		um->um_ctlr);
	sc->sc_flags &= ~SC_INSLAVE;
	return (0);

gotit:
	sc->sc_flags &= ~SC_INSLAVE;

	/*
	 * Got a slave response.  If the unit is there, use it.
	 */
	switch (mp->mscp_status & M_ST_MASK) {

	case M_ST_SUCCESS:	/* worked */
	case M_ST_AVAILABLE:	/* found another drive */
		break;		/* use it */

	case M_ST_OFFLINE:
		/*
		 * Figure out why it is off line.  It may be because
		 * it is nonexistent, or because it is spun down, or
		 * for some other reason.
		 */
		switch (mp->mscp_status & ~M_ST_MASK) {

		case M_OFFLINE_UNKNOWN:
			/*
			 * No such drive, and there are none with
			 * higher unit numbers either, if we are
			 * using M_GUM_NEXTUNIT.
			 */
			return (0);

		case M_OFFLINE_UNMOUNTED:
			/*
			 * The drive is not spun up.  Use it anyway.
			 *
			 * N.B.: this seems to be a common occurrance
			 * after a power failure.  The first attempt
			 * to bring it on line seems to spin it up
			 * (and thus takes several minutes).  Perhaps
			 * we should note here that the on-line may
			 * take longer than usual.
			 */
			break;

		default:
			/*
			 * In service, or something else equally unusable.
			 */
			printf("uda%d: unit %d off line: ", um->um_ctlr,
				mp->mscp_unit);
			mscp_printevent(mp);
			goto try_another;
		}
		break;

	default:
		printf("uda%d: unable to get unit status: ", um->um_ctlr);
		mscp_printevent(mp);
		return (0);
E 60
	}
D 60
	/* The controller is up so let see if the drive is there! */
	if(0 == (mp = udgetcp(um))){	/* ditto */
		printf("UDA can't get command packet\n");
		return(0);
E 60
I 60

	/*
	 * Does this ever happen?  What (if anything) does it mean?
	 */
	if (mp->mscp_unit < next) {
		printf("uda%d: unit %d, next %d\n",
			um->um_ctlr, mp->mscp_unit, next);
		return (0);
E 60
	}
D 60
	mp->mscp_opcode = M_OP_GTUNT;	/* This should give us the drive type*/
	mp->mscp_unit = ui->ui_slave;
	mp->mscp_cmdref = (long) ui->ui_slave;
#ifdef	DEBUG
	printd("uda%d Get unit status slave %d\n",ui->ui_ctlr,ui->ui_slave);
#endif	
	ra_info[ui->ui_unit].rastatus = 0;	/* set to zero */
	udip[ui->ui_ctlr][ui->ui_slave] = ui;
	*((long *) mp->mscp_dscptr ) |= UDA_OWN | UDA_INT;/* maybe we should poll*/
	i = udaddr->udaip;
I 44
#ifdef lint
	i = i;
#endif
E 44
	while(!ra_info[ui->ui_unit].rastatus);  /* Wait for some status */
	udip[ui->ui_ctlr][ui->ui_slave] = 0;
	if(!ra_info[ui->ui_unit].ratype)	/* packet from a GTUNT */
		return(0);		/* Failed No such drive */
	else
		return(1);		/* Got it and it is there */
E 60
I 60

	if (mp->mscp_unit >= MAXUNIT) {
		printf("uda%d: cannot handle unit number %d (max is %d)\n",
			um->um_ctlr, mp->mscp_unit, MAXUNIT - 1);
		return (0);
	}

	/*
	 * See if we already handle this drive.
	 * (Only likely if ui->ui_slave=='?'.)
	 */
	if (udaip[um->um_ctlr][mp->mscp_unit] != NULL) {
try_another:
		if (ui->ui_slave != '?')
			return (0);
		next = mp->mscp_unit + 1;
		goto findunit;
	}

	/*
	 * Voila!
	 */
	uda_rasave(ui->ui_unit, mp, 0);
	ui->ui_flags = 0;	/* not on line, nor anything else */
	ui->ui_slave = mp->mscp_unit;
	return (1);
E 60
E 29
}

D 60
udattach(ui)
E 60
I 60
/*
 * Attach a found slave.  Make sure the watchdog timer is running.
 * If this disk is being profiled, fill in the `mspw' value (used by
 * what?).  Set up the inverting pointer, and attempt to bring the
 * drive on line and read its label.
 */
udaattach(ui)
E 60
	register struct uba_device *ui;
{
D 29

E 29
I 29
D 60
	register struct uba_ctlr *um = ui->ui_mi ;
	struct udadevice *udaddr = (struct udadevice *) um->um_addr;
D 54
	struct	mscp	*mp;
E 54
I 54
	register struct	mscp	*mp;
	register unit = ui->ui_unit;
E 54
	int	i;			/* Something to write into to start */
					/* the uda polling */
D 44
#ifdef	lint
	i = i;
#endif
E 44
E 29
D 22
	if (ui->ui_dk > 0)
E 22
I 22
	if (ui->ui_dk >= 0)
E 22
D 29
		dk_mspw[ui->ui_dk] = 1.0 / (60 * 31 * 256);	/* approx */
E 29
I 29
		dk_mspw[ui->ui_dk] = 1.0 / (60 * 31 * 256);     /* approx */
E 29
	ui->ui_flags = 0;
	udip[ui->ui_ctlr][ui->ui_slave] = ui;
D 29
	radsize[ui->ui_unit] = (daddr_t)0xffffff;	/* max possible size */
E 29
I 29
	/* check to see if the drive is a available if it is bring it online */
	/* if not then just return.  open will try an online later */
D 54
	if(ra_info[ui->ui_unit].rastatus != M_ST_AVLBL)
E 54
I 54
	if(ra_info[unit].rastatus != M_ST_AVLBL)
E 54
		return;			/* status was set by a GTUNT */
	if(0 == (mp = udgetcp(um))){	/* ditto */
		printf("UDA can't get command packet\n");
		return;
E 60
I 60
	register int unit = ui->ui_unit;

	if (udawstart == 0) {
		timeout(udawatch, (caddr_t) 0, hz);
		udawstart++;
E 60
	}
D 60
	mp->mscp_opcode = M_OP_ONLIN;
	mp->mscp_unit = ui->ui_slave;
	mp->mscp_cmdref = (long) ui->ui_slave;
#ifdef	DEBUG
	printd("uda%d ONLIN slave %d\n",ui->ui_ctlr,ui->ui_slave);
#endif	
	*((long *) mp->mscp_dscptr ) |= UDA_OWN | UDA_INT;
	i = udaddr->udaip;
I 44
#ifdef	lint
	i = i;
E 60
I 60
D 70
	if (ui->ui_dk >= 0)
E 70
I 65

	/*
	 * Floppies cannot be brought on line unless there is
	 * a disk in the drive.  Since an ONLINE while cold
	 * takes ten seconds to fail, and (when notyet becomes now)
	 * no sensible person will swap to one, we just
	 * defer the ONLINE until someone tries to use the drive.
	 *
	 * THIS ASSUMES THAT DRIVE TYPES ?X? ARE FLOPPIES
	 */
	if (MSCP_MID_ECH(1, ra_info[unit].ra_mediaid) == 'X' - '@') {
D 66
		printf("ra%d: floppy\n", unit);
E 66
I 66
		printf(": floppy");
E 66
		return;
	}
I 70
	if (ui->ui_dk >= 0)
E 70
E 65
		dk_mspw[ui->ui_dk] = 1.0 / (60 * 31 * 256);	/* approx */
	udaip[ui->ui_ctlr][ui->ui_slave] = ui;
I 63

I 66
D 70
#ifdef notdef
E 66
	/*
	 * RX50s cannot be brought on line unless there is
	 * a floppy in the drive.  Since an ONLINE while cold
	 * takes ten seconds to fail, and (when notyet becomes now)
	 * no sensible person will swap to an RX50, we just
	 * defer the ONLINE until someone tries to use the drive.
	 */
	if (ra_info[unit].ra_type == RA_TYPE_RX50) {
D 66
		printf("ra%d: rx50\n", unit);
E 66
I 66
		printf(": rx50");
E 66
		return;
	}
I 66
#endif
E 70
E 66
E 63
	if (uda_rainit(ui, 0))
D 61
		printf("ra%d: offline", unit);
E 61
I 61
D 66
		printf("ra%d: offline\n", unit);
E 66
I 66
		printf(": offline");
E 66
E 61
D 73
	else {
E 73
I 73
	else if (ra_info[unit].ra_state == OPEN) {
E 73
D 66
		printf("ra%d: %s\n", unit, udalabel[unit].d_typename);
E 66
I 66
		printf(": %s, size = %d sectors",
		    udalabel[unit].d_typename, ra_info[unit].ra_dsize);
E 66
#ifdef notyet
		addswap(makedev(UDADEVNUM, udaminor(unit, 0)), &udalabel[unit]);
E 60
#endif
E 44
D 54
	while(ui->ui_flags == 0 && ra_info[ui->ui_unit].ratype != 0);
E 54
I 54
D 60
	for (i = 1000; ui->ui_flags == 0 && ra_info[unit].ratype != 0; ) {
		if (--i == 0)
			break;
		DELAY(1000);
E 60
	}
I 60
}

/*
 * Initialise a UDA50.  Return true iff something goes wrong.
 */
udainit(ctlr)
	int ctlr;
{
	register struct uda_softc *sc;
	register struct udadevice *udaddr;
	struct uba_ctlr *um;
	int timo, ubinfo;

	sc = &uda_softc[ctlr];
	um = udaminfo[ctlr];
	if ((sc->sc_flags & SC_MAPPED) == 0) {
		/*
		 * Map the communication area and command and
		 * response packets into Unibus space.
		 */
		ubinfo = uballoc(um->um_ubanum, (caddr_t) &uda[ctlr],
			sizeof (struct uda), UBA_CANTWAIT);
		if (ubinfo == 0) {
			printf("uda%d: uballoc map failed\n", ctlr);
			return (-1);
		}
D 73
		sc->sc_uda = (struct uda *) (ubinfo & 0x3ffff);
E 73
I 73
		sc->sc_uda = (struct uda *) UBAI_ADDR(ubinfo);
E 73
		sc->sc_flags |= SC_MAPPED;
	}

E 60
	/*
D 60
	 * Try to read pack label.
E 60
I 60
	 * While we are thinking about it, reset the next command
	 * and response indicies.
E 60
	 */
D 60
	if (rainit(ui, 0) == 0) {
		printf("ra%d: %s\n", unit, udlabel[unit].d_typename);
#ifdef notyet
		addswap(makedev(UDADEVNUM, udminor(unit, 0)), &udlabel[unit]);
#endif
	} else
		printf("ra%d: offline\n", unit);
E 60
I 60
	sc->sc_mi.mi_cmd.mri_next = 0;
	sc->sc_mi.mi_rsp.mri_next = 0;

	/*
	 * Start up the hardware initialisation sequence.
	 */
#define	STEP0MASK	(UDA_ERR | UDA_STEP4 | UDA_STEP3 | UDA_STEP2 | \
			 UDA_STEP1 | UDA_NV)

	sc->sc_state = ST_IDLE;	/* in case init fails */
D 65
	udaddr = (struct udadevice *) um->um_addr;
E 65
I 65
	udaddr = (struct udadevice *)um->um_addr;
E 65
	udaddr->udaip = 0;
	timo = todr() + 1000;
	while ((udaddr->udasa & STEP0MASK) == 0) {
		if (todr() > timo) {
			printf("uda%d: timeout during init\n", ctlr);
			return (-1);
		}
	}
	if ((udaddr->udasa & STEP0MASK) != UDA_STEP1) {
		printf("uda%d: init failed, sa=%b\n", ctlr,
			udaddr->udasa, udasr_bits);
I 65
		udasaerror(um, 0);
E 65
		return (-1);
	}

	/*
	 * Success!  Record new state, and start step 1 initialisation.
	 * The rest is done in the interrupt handler.
	 */
	sc->sc_state = ST_STEP1;
	udaddr->udasa = UDA_ERR | (NCMDL2 << 11) | (NRSPL2 << 8) | UDA_IE |
	    (sc->sc_ivec >> 2);
	return (0);
E 60
E 54
E 29
}

/*
D 60
 * Open a UDA.  Initialize the device and
 * set the unit online.
E 60
I 60
 * Open a drive.
E 60
 */
I 44
D 54
/* ARGSUSED */
E 54
E 44
D 55
udopen(dev, flag)
E 55
I 55
D 60
udopen(dev, flag, fmt)
E 60
I 60
/*ARGSUSED*/
udaopen(dev, flag, fmt)
E 60
E 55
	dev_t dev;
D 55
	int flag;
E 55
I 55
	int flag, fmt;
E 55
{
D 56
	register int unit;
E 56
I 56
D 60
	int unit;
E 60
I 60
	register int unit;
E 60
E 56
	register struct uba_device *ui;
	register struct uda_softc *sc;
I 2
D 29
	int s;
E 2

E 29
I 29
D 54
	register struct mscp *mp;
	register struct uba_ctlr *um;
	struct udadevice *udaddr;
	int s,i;
D 46
	extern quota;
E 46
	
E 54
I 54
	register struct disklabel *lp;
	register struct partition *pp;
D 55
	int s, i, part;
E 55
I 55
D 56
	struct ra_info *ra = &ra_info[unit];
	int s, i, part, mask = 1 << part;
E 56
I 56
	register struct ra_info *ra;
D 60
	int s, i, part, mask, error;
E 60
I 60
	int s, i, part, mask, error = 0;
E 60
E 56
E 55
	daddr_t start, end;

E 54
E 29
I 3
D 44
#ifdef lint
D 29
	flag = flag;
E 29
I 29
	flag = flag; i = i;
E 29
#endif
E 44
E 3
D 37
	unit = minor(dev) >> 3;
E 37
I 37
D 60
	unit = udunit(dev);
I 54
	part = udpart(dev);
I 56
	mask = 1 << part;
	ra = &ra_info[unit];
E 56
E 54
E 37
D 11
	if (unit >= NRA || (ui = uddinfo[unit]) == 0 || ui->ui_alive == 0) {
		u.u_error = ENXIO;
		return;
	}
E 11
I 11
D 29
	if (unit >= NRA || (ui = uddinfo[unit]) == 0 || ui->ui_alive == 0)
E 29
I 29
D 45
	if (unit >= nNRA || (ui = uddinfo[unit]) == 0 || ui->ui_alive == 0)
E 45
I 45
	if (unit >= NRA || (ui = uddinfo[unit]) == 0 || ui->ui_alive == 0)
E 60
I 60
	/*
	 * Make sure this is a reasonable open request.
	 */
	unit = udaunit(dev);
	if (unit >= NRA || (ui = udadinfo[unit]) == 0 || ui->ui_alive == 0)
E 60
E 45
E 29
		return (ENXIO);
I 60

	/*
	 * Make sure the controller is running, by (re)initialising it if
	 * necessary.
	 */
E 60
E 11
	sc = &uda_softc[ui->ui_ctlr];
I 54
D 60
	lp = &udlabel[unit];
E 60
E 54
D 2
	(void) spl5();
E 2
I 2
	s = spl5();
E 2
D 60
	if (sc->sc_state != S_RUN) {
		if (sc->sc_state == S_IDLE)
D 29
			udinit(ui->ui_ctlr);
E 29
I 29
			if(!udinit(ui->ui_ctlr)){
				printf("uda: Controller failed to init\n");
I 40
				(void) splx(s);
E 40
				return(ENXIO);
			}
E 29
D 3
		sleep(ui->ui_mi, 0); /* wait for initialization to complete */
E 3
I 3
		/* wait for initialization to complete */
I 29
		timeout(wakeup,(caddr_t)ui->ui_mi,11*hz);	/* to be sure*/
E 29
		sleep((caddr_t)ui->ui_mi, 0);
E 3
D 11
		if (sc->sc_state != S_RUN) {
			u.u_error = EIO;
			return;
		}
E 11
I 11
		if (sc->sc_state != S_RUN)
I 29
		{
			(void) splx(s); /* added by Rich */
E 60
I 60
	if (sc->sc_state != ST_RUN) {
		if (sc->sc_state == ST_IDLE && udainit(ui->ui_ctlr)) {
			splx(s);
E 60
E 29
			return (EIO);
I 29
		}
I 60
		/*
		 * In case it does not come up, make sure we will be
		 * restarted in 10 seconds.  This corresponds to the
		 * 10 second timeouts in udaprobe() and udaslave().
		 */
		sc->sc_flags |= SC_DOWAKE;
		timeout(wakeup, (caddr_t) sc, 10 * hz);
		sleep((caddr_t) sc, PRIBIO);
		if (sc->sc_state != ST_RUN) {
			splx(s);
			printf("uda%d: controller hung\n", ui->ui_ctlr);
			return (EIO);
		}
		untimeout(wakeup, (caddr_t) sc);
E 60
E 29
E 11
	}
D 2
	(void) spl0();
E 2
I 2
D 29
	splx(s);
E 2
	/* SHOULD PROBABLY FORCE AN ONLINE ATTEMPT
	   TO SEE IF DISK IS REALLY THERE */
E 29
I 29
D 54
	/* check to see if the device is really there. */
	/* this code was taken from Fred Canters 11 driver */
	um = ui->ui_mi;
	udaddr = (struct udadevice *) um->um_addr;
E 54
D 56
	(void) splx(s);
D 54
	if(ui->ui_flags == 0){
		s = spl5();
		while(0 ==(mp = udgetcp(um))){
			uda_cp_wait++;
D 45
			sleep(&uda_cp_wait,PSWP+1);
E 45
I 45
			sleep((caddr_t)&uda_cp_wait,PSWP+1);
E 45
			uda_cp_wait--;
E 54
I 54
	if (ui->ui_flags == 0)
		rainit(ui, flag);
	if (ui->ui_flags == 0)
		return(ENXIO);  /* Didn't go online */
E 56
I 56
D 60
	while (ra->rastate != OPEN && ra->rastate != OPENRAW &&
	    ra->rastate != CLOSED)
		sleep((caddr_t)ra, PZERO+1);
E 60
I 60

	/*
	 * Wait for the state to settle
	 */
	ra = &ra_info[unit];
	while (ra->ra_state != OPEN && ra->ra_state != OPENRAW &&
D 75
	    ra->ra_state != CLOSED)
E 75
I 75
	    ra->ra_state != CLOSED && ra->ra_state != ONLINE)
E 75
		sleep((caddr_t)ra, PZERO + 1);

	/*
	 * If not on line, or we are not sure of the label, reinitialise
	 * the drive.
	 */
	if ((ui->ui_flags & UNIT_ONLINE) == 0 ||
	    (ra->ra_state != OPEN && ra->ra_state != OPENRAW))
		error = uda_rainit(ui, flag);
E 60
	splx(s);
D 60
	if (ui->ui_flags == 0 ||
	    (ra->rastate != OPEN && ra->rastate != OPENRAW))
		if (error = rainit(ui, flag))
			return (error);
E 60
I 60
	if (error)
		return (error);
E 60
E 56

I 60
	part = udapart(dev);
	lp = &udalabel[unit];
E 60
	if (part >= lp->d_npartitions)
		return (ENXIO);
	/*
D 60
	 * Warn if a partion is opened
	 * that overlaps another partition which is open
	 * unless one is the "raw" partition (whole disk).
E 60
I 60
	 * Warn if a partition is opened that overlaps another
	 * already open, unless either is the `raw' partition
	 * (whole disk).
E 60
	 */
D 60
#define	RAWPART		2		/* 'c' partition */	/* XXX */
D 55
	if ((ra_info[unit].openpart & (1 << part)) == 0 &&
E 55
I 55
	if ((ra->openpart & mask) == 0 &&
E 55
	    part != RAWPART) {
E 60
I 60
#define	RAWPART		2	/* 'c' partition */	/* XXX */
	mask = 1 << part;
	if ((ra->ra_openpart & mask) == 0 && part != RAWPART) {
E 60
		pp = &lp->d_partitions[part];
		start = pp->p_offset;
		end = pp->p_offset + pp->p_size;
D 60
		for (pp = lp->d_partitions;
		     pp < &lp->d_partitions[lp->d_npartitions]; pp++) {
E 60
I 60
		for (pp = lp->d_partitions, i = 0;
		     i < lp->d_npartitions; pp++, i++) {
E 60
			if (pp->p_offset + pp->p_size <= start ||
D 60
			    pp->p_offset >= end)
E 60
I 60
			    pp->p_offset >= end || i == RAWPART)
E 60
				continue;
D 60
			if (pp - lp->d_partitions == RAWPART)
				continue;
D 55
			if (ra_info[unit].openpart &
E 55
I 55
			if (ra->openpart &
E 55
			    (1 << (pp - lp->d_partitions)))
E 60
I 60
			if (ra->ra_openpart & (1 << i))
E 60
				log(LOG_WARNING,
				    "ra%d%c: overlaps open partition (%c)\n",
D 60
				    unit, part + 'a',
				    pp - lp->d_partitions + 'a');
E 60
I 60
				    unit, part + 'a', i + 'a');
E 60
E 54
		}
D 31
		(void) splx(s);
E 31
D 54
		mp->mscp_opcode = M_OP_ONLIN;
		mp->mscp_unit = ui->ui_slave;
		mp->mscp_cmdref = (long) & ra_info[ui->ui_unit].ratype;
			/* need to sleep on something */
#ifdef	DEBUG
		printd("uda: bring unit %d online\n",ui->ui_unit);
#endif	
		*((long *) mp->mscp_dscptr ) |= UDA_OWN | UDA_INT ;
		i = udaddr->udaip;
I 44
#ifdef	lint
		i = i;
#endif
E 44
		timeout(wakeup,(caddr_t) mp->mscp_cmdref,10 * hz);
			/* make sure we wake up */
		sleep((caddr_t) mp->mscp_cmdref,PSWP+1); /*wakeup in udrsp() */
I 31
		(void) splx(s);
E 54
E 31
	}
D 54
	if(ui->ui_flags == 0){
		return(ENXIO);  /* Didn't go online */
	}
E 54
I 54
D 55
	ra_info[unit].openpart |= (1 << part);
E 55
I 55
	switch (fmt) {
	case S_IFCHR:
D 60
		ra->copenpart |= mask;
E 60
I 60
		ra->ra_copenpart |= mask;
E 60
		break;
	case S_IFBLK:
D 60
		ra->bopenpart |= mask;
E 60
I 60
		ra->ra_bopenpart |= mask;
E 60
		break;
	}
D 60
	ra->openpart |= mask;
E 60
I 60
	ra->ra_openpart |= mask;
E 60
E 55
E 54
E 29
I 11
	return (0);
E 11
}

I 65
/* ARGSUSED */
E 65
I 64
D 70
/*ARGSUSED*/
E 70
E 64
I 54
D 60
/* ARGSUSED */
D 55
udclose(dev, flags)
E 55
I 55
udclose(dev, flags, fmt)
E 60
I 60
udaclose(dev, flags, fmt)
E 60
E 55
	dev_t dev;
D 55
	int flags;
E 55
I 55
	int flags, fmt;
E 55
{
D 60
	register int unit = udunit(dev);
E 60
I 60
	register int unit = udaunit(dev);
E 60
D 59
	register struct uda_softc *sc;
	struct uba_ctlr *um;
E 59
D 55
	int s;
E 55
I 55
	register struct ra_info *ra = &ra_info[unit];
D 60
	int s, mask = (1 << udpart(dev));
E 60
I 60
	int s, mask = (1 << udapart(dev));
E 60
E 55

D 59
	um = udminfo[unit];
	sc = &uda_softc[um->um_ctlr];
E 59
D 55
	ra_info[unit].openpart &= ~(1 << udpart(dev));
#ifdef notdef
E 55
I 55
	switch (fmt) {
	case S_IFCHR:
D 60
		ra->copenpart &= ~mask;
E 60
I 60
		ra->ra_copenpart &= ~mask;
E 60
		break;
	case S_IFBLK:
D 60
		ra->bopenpart &= ~mask;
E 60
I 60
		ra->ra_bopenpart &= ~mask;
E 60
		break;
	}
D 60
	if (((ra->copenpart | ra->bopenpart) & mask) == 0)
		ra->openpart &= ~mask;
E 60
I 60
	ra->ra_openpart = ra->ra_copenpart | ra->ra_bopenpart;

E 60
E 55
	/*
D 60
	 * Should wait for I/O to complete on this partition
	 * even if others are open, but wait for work on blkflush().
E 60
I 60
	 * Should wait for I/O to complete on this partition even if
	 * others are open, but wait for work on blkflush().
E 60
	 */
D 55
	if (ra_info[unit].openpart == 0) {
E 55
I 55
D 60
	if (ra->openpart == 0) {
E 60
I 60
	if (ra->ra_openpart == 0) {
E 60
E 55
		s = spl5();
D 55
		/* Can't sleep on b_actf, it might be async. */
		while (um->um_tab.b_actf)
			sleep((caddr_t)&um->um_tab.b_actf, PZERO - 1);
E 55
I 55
D 60
		while (udutab[unit].b_actf)
			sleep((caddr_t)&udutab[unit], PZERO - 1);
E 60
I 60
		while (udautab[unit].b_actf)
			sleep((caddr_t)&udautab[unit], PZERO - 1);
E 60
E 55
		splx(s);
D 55
		ra_info[unit].rastate = CLOSED;
E 55
I 55
D 60
		ra->rastate = CLOSED;
E 60
I 60
		ra->ra_state = CLOSED;
I 64
		ra->ra_wlabel = 0;
E 64
E 60
E 55
	}
D 55
#endif
E 55
I 55
	return (0);
E 55
}

E 54
/*
D 60
 * Initialize a UDA.  Set up UBA mapping registers,
 * initialize data structures, and start hardware
 * initialization sequence.
E 60
I 60
 * Initialise a drive.  If it is not already, bring it on line,
 * and set a timeout on it in case it fails to respond.
 * When on line, read in the pack label.
E 60
 */
D 60
udinit(d)
	int d;
{
	register struct uda_softc *sc;
	register struct uda *ud;
	struct udadevice *udaddr;
	struct uba_ctlr *um;

	sc = &uda_softc[d];
	um = udminfo[d];
	um->um_tab.b_active++;
	ud = &uda[d];
	udaddr = (struct udadevice *)um->um_addr;
	if (sc->sc_mapped == 0) {
		/*
		 * Map the communications area and command
		 * and response packets into Unibus address
		 * space.
		 */
		sc->sc_ubainfo = uballoc(um->um_ubanum, (caddr_t)ud,
		    sizeof (struct uda), 0);
		sc->sc_uda = (struct uda *)(sc->sc_ubainfo & 0x3ffff);
		sc->sc_mapped = 1;
	}

	/*
	 * Start the hardware initialization sequence.
	 */
D 29
	udaddr->udaip = 0;		/* start initialization */
	while ((udaddr->udasa & UDA_STEP1) == 0)
		;
	udaddr->udasa = UDA_ERR|(NCMDL2<<11)|(NRSPL2<<8)|UDA_IE|(sc->sc_ivec/4);
E 29
I 29

I 52
	if (udaburst[d] == 0)
		udaburst[d] = UDABURST;
E 52
 	udaddr->udaip = 0;              /* start initialization */

	while((udaddr->udasa & UDA_STEP1) == 0){
		if(udaddr->udasa & UDA_ERR)
			return(0);	/* CHECK */
	}
	udaddr->udasa=UDA_ERR|(NCMDL2<<11)|(NRSPL2<<8)|UDA_IE|(sc->sc_ivec/4);
E 29
	/*
	 * Initialization continues in interrupt routine.
	 */
	sc->sc_state = S_STEP1;
	sc->sc_credits = 0;
I 29
	return(1);
E 29
}

I 54
/*
 * Initialize a drive:
 * bring on line and read in pack label.
 */
rainit(ui, flags)
E 60
I 60
uda_rainit(ui, flags)
E 60
	register struct uba_device *ui;
I 60
	int flags;
E 60
{
D 60
	register struct mscp *mp;
E 60
I 60
	register struct uda_softc *sc = &uda_softc[ui->ui_ctlr];
I 66
	register struct disklabel *lp;
E 66
E 60
D 55
	register struct buf *bp;
E 55
D 65
	register struct disklabel *lp;
E 65
D 60
	register struct uda_softc *sc;
	register unit = ui->ui_unit;
I 56
	register struct ra_info *ra = &ra_info[unit];
E 56
D 55
	struct disklabel *dlp;
E 55
	struct udadevice *udaddr;
E 60
I 60
	register struct mscp *mp;
	register int unit = ui->ui_unit;
	register struct ra_info *ra;
E 60
I 55
	char *msg, *readdisklabel();
E 55
D 56
	int s, i, error = 0;
E 56
I 56
D 60
	int s, i;
E 60
I 60
	int s, i, udastrategy();
E 60
E 56
	extern int cold;

D 60
	lp = &udlabel[unit];
	sc = &uda_softc[ui->ui_ctlr];

D 56
	/* check to see if the device is really there. */
	/* this code was taken from Fred Canters 11 driver */
	udaddr = (struct udadevice *) ui->ui_mi->um_addr;
E 56
I 56
	if (ui->ui_flags == 0) {
		/* check to see if the device is really there. */
		/* this code was taken from Fred Canters 11 driver */
		udaddr = (struct udadevice *) ui->ui_mi->um_addr;
E 56

D 56
	ra_info[unit].rastate = WANTOPEN;
	s = spl5();
	while(0 ==(mp = udgetcp(ui->ui_mi))){
		uda_cp_wait++;
		sleep((caddr_t)&uda_cp_wait,PSWP+1);
		uda_cp_wait--;
	}
	mp->mscp_opcode = M_OP_ONLIN;
	mp->mscp_unit = ui->ui_slave;
		/* need to sleep on something */
	mp->mscp_cmdref = (long) & ra_info[unit].ratype;
E 56
I 56
		ra->rastate = WANTOPEN;
		s = spl5();
		while(0 ==(mp = udgetcp(ui->ui_mi))){
			uda_cp_wait++;
			sleep((caddr_t)&uda_cp_wait,PSWP+1);
			uda_cp_wait--;
		}
		mp->mscp_opcode = M_OP_ONLIN;
E 60
I 60
	ra = &ra_info[unit];
	if ((ui->ui_flags & UNIT_ONLINE) == 0) {
		mp = mscp_getcp(&sc->sc_mi, MSCP_WAIT);
		mp->mscp_opcode = M_OP_ONLINE;
E 60
		mp->mscp_unit = ui->ui_slave;
D 60
			/* need to sleep on something */
		mp->mscp_cmdref = (long)ra;
E 56
#ifdef	DEBUG
D 56
	printd("uda: bring unit %d online\n",unit);
E 56
I 56
		printd("uda: bring unit %d online\n",unit);
E 56
#endif	
D 56
	*((long *) mp->mscp_dscptr ) |= UDA_OWN | UDA_INT ;
	i = udaddr->udaip;
E 56
I 56
		*((long *) mp->mscp_dscptr ) |= UDA_OWN | UDA_INT ;
		i = udaddr->udaip;
E 56
#ifdef	lint
D 56
	i = i;
E 56
I 56
		i = i;
E 56
#endif
D 56
		/* make sure we wake up */
	if (cold) {
		(void) splx(s);
		for (i = 10*1000; ra_info[unit].rastate == WANTOPEN && --i; )
			DELAY(1000);
	} else {
		timeout(wakeup,(caddr_t) mp->mscp_cmdref,10 * hz);
		sleep((caddr_t) mp->mscp_cmdref,PSWP+1); /*wakeup in udrsp() */
		(void) splx(s);
E 56
I 56
			/* make sure we wake up */
E 60
I 60
		mp->mscp_cmdref = (long)&ui->ui_flags;
		*mp->mscp_addr |= MSCP_OWN | MSCP_INT;
		ra->ra_state = WANTOPEN;
		if (!cold)
			s = spl5();
		i = ((struct udadevice *)ui->ui_addr)->udaip;

E 60
		if (cold) {
D 60
			(void) splx(s);
			for (i = 10*1000; ra->rastate == WANTOPEN && --i; )
				DELAY(1000);
E 60
I 60
D 76
			i = todr() + 1000;
E 76
I 76
			i = todr() + 12000;
E 76
			while ((ui->ui_flags & UNIT_ONLINE) == 0)
				if (todr() > i)
					break;
E 60
		} else {
D 60
			timeout(wakeup, (caddr_t)ra, 10 * hz);
			sleep((caddr_t)ra, PSWP+1);
			/*wakeup in udrsp() */
			(void) splx(s);
E 60
I 60
D 76
			timeout(wakeup, (caddr_t)&ui->ui_flags, 10 * hz);
E 76
I 76
			timeout(wakeup, (caddr_t)&ui->ui_flags, 120 * hz);
E 76
			sleep((caddr_t)&ui->ui_flags, PSWP + 1);
			splx(s);
			untimeout(wakeup, (caddr_t)&ui->ui_flags);
E 60
		}
D 60
		if (ra->rastate != OPENRAW) {
			ra->rastate = CLOSED;
E 60
I 60
D 75
		if (ra->ra_state != OPENRAW) {
E 75
I 75
		if (ra->ra_state != ONLINE) {
E 75
			ra->ra_state = CLOSED;
			wakeup((caddr_t)ra);
E 60
			return (EIO);
		}
E 56
	}
D 56
	if (ra_info[unit].rastate != OPENRAW)
		return (EIO);
E 56

I 60
	lp = &udalabel[unit];
E 60
I 56
	lp->d_secsize = DEV_BSIZE;
D 60
	lp->d_secperunit = ra->radsize;
E 60
I 60
	lp->d_secperunit = ra->ra_dsize;
E 60

E 56
D 75
	if (flags & O_NDELAY)
E 75
I 75
	if (flags & O_NDELAY) {
		ra->ra_state = OPENRAW;
E 75
		return (0);
I 75
	}
E 75
D 56
	ra_info[unit].rastate = RDLABEL;
E 56
I 56
D 60
	ra->rastate = RDLABEL;
E 60
I 60
	ra->ra_state = RDLABEL;
E 60
E 56
	/*
D 60
	 * Set up default sizes until we've read the label,
	 * or longer if there isn't one there.
I 56
	 * Set secpercyl, as readdisklabel wants to compute b_cylin
	 * (although we don't need it).
E 60
I 60
	 * Set up default sizes until we have the label, or longer
	 * if there is none.  Set secpercyl, as readdisklabel wants
	 * to compute b_cylin (although we do not need it).
E 60
E 56
	 */
D 56
	lp->d_secsize = DEV_BSIZE;
	lp->d_secperunit = ra_info[unit].radsize;
E 56
I 56
	lp->d_secpercyl = 1;
E 56
	lp->d_npartitions = 1;
I 73
	lp->d_secsize = 512;
	lp->d_secperunit = ra->ra_dsize;
E 73
	lp->d_partitions[0].p_size = lp->d_secperunit;
	lp->d_partitions[0].p_offset = 0;
I 60

E 60
	/*
	 * Read pack label.
	 */
D 55
	bp = geteblk(DEV_BSIZE);		/* max sector size */
	bp->b_dev = udminor(unit, 0);
	bp->b_blkno = LABELSECTOR;
	bp->b_bcount = DEV_BSIZE;
	bp->b_flags = B_BUSY | B_READ;
	udstrategy(bp);
	biowait(bp);
	if (bp->b_flags & B_ERROR) {
		error = u.u_error;		/* XXX */
		u.u_error = 0;
		ra_info[unit].rastate = CLOSED;
		goto done;
	}

	dlp = (struct disklabel *)(bp->b_un.b_addr + LABELOFFSET);
	if (dlp->d_magic == DISKMAGIC &&
	    dlp->d_magic2 == DISKMAGIC && dkcksum(dlp) == 0) {
		*lp = *dlp;
		ra_info[unit].rastate = OPEN;
	} else {
E 55
I 55
D 60
	if (msg = readdisklabel(udminor(unit, 0), udstrategy, lp)) {
E 60
I 60
	if ((msg = readdisklabel(udaminor(unit, 0), udastrategy, lp)) != NULL) {
E 60
E 55
D 56
		log(LOG_ERR, "ra%d: no disk label\n", unit);
E 56
I 56
D 66
		log(LOG_ERR, "ra%d: %s\n", unit, msg);
E 66
I 66
		if (cold)
			printf(": %s", msg);
		else
D 73
			log(LOG_ERR, "ra%d: %s\n", unit, msg);
E 73
I 73
			log(LOG_ERR, "ra%d: %s", unit, msg);
E 73
E 66
E 56
#ifdef COMPAT_42
D 60
		if (udmaptype(unit, lp))
D 56
			ra_info[unit].rastate = OPEN;
E 56
I 56
			ra->rastate = OPEN;
E 60
I 60
		if (udamaptype(unit, lp))
			ra->ra_state = OPEN;
E 60
E 56
		else
I 55
D 56
#else
			ra_info[unit].rastate = OPENRAW;
E 56
I 56
D 60
			ra->rastate = OPENRAW;
E 60
I 60
			ra->ra_state = OPENRAW;
E 60
E 56
E 55
D 57
#endif
E 57
I 57
#else
E 57
D 56
		ra_info[unit].rastate = OPENRAW;
E 56
I 56
D 60
		ra->rastate = OPENRAW;
E 60
I 60
		ra->ra_state = OPENRAW;
D 73
		/* uda_makefakelabel(ra, lp); */
E 73
I 73
		uda_makefakelabel(ra, lp);
E 73
E 60
I 57
#endif
E 57
E 56
D 55
	}
done:
	brelse(bp);
E 55
I 55
	} else
D 56
		ra_info[unit].rastate = OPEN;
E 55
	return (error);
E 56
I 56
D 60
		ra->rastate = OPEN;
E 60
I 60
		ra->ra_state = OPEN;
E 60
	wakeup((caddr_t)ra);
	return (0);
E 56
}

E 54
D 60
udstrategy(bp)
E 60
I 60
/*
 * Copy the geometry information for the given ra from a
 * GET UNIT STATUS response.  If check, see if it changed.
 */
uda_rasave(unit, mp, check)
	int unit;
	register struct mscp *mp;
	int check;
{
	register struct ra_info *ra = &ra_info[unit];

D 65
	if (check && ra->ra_type != mp->mscp_guse.guse_drivetype) {
E 65
I 65
D 66
	if (check && ra->ra_type != mp->mscp_guse.guse_mediaid) {
E 66
I 66
	if (check && ra->ra_mediaid != mp->mscp_guse.guse_mediaid) {
E 66
E 65
D 64
		printf("ra%d: changed types! was %d now %d\n",
E 64
I 64
		printf("ra%d: changed types! was %d now %d\n", unit,
E 64
D 65
			ra->ra_type, mp->mscp_guse.guse_drivetype);
E 65
I 65
D 66
			ra->ra_type, mp->mscp_guse.guse_mediaid);
E 66
I 66
			ra->ra_mediaid, mp->mscp_guse.guse_mediaid);
E 66
E 65
		ra->ra_state = CLOSED;	/* ??? */
	}
D 65
	ra->ra_type = mp->mscp_guse.guse_drivetype;
E 65
I 65
	/* ra->ra_type = mp->mscp_guse.guse_drivetype; */
E 65
	ra->ra_mediaid = mp->mscp_guse.guse_mediaid;
	ra->ra_geom.rg_nsectors = mp->mscp_guse.guse_nspt;
	ra->ra_geom.rg_ngroups = mp->mscp_guse.guse_group;
	ra->ra_geom.rg_ngpc = mp->mscp_guse.guse_ngpc;
	ra->ra_geom.rg_ntracks = ra->ra_geom.rg_ngroups * ra->ra_geom.rg_ngpc;
	/* ra_geom.rg_ncyl cannot be computed until we have ra_dsize */
#ifdef notyet
	ra->ra_geom.rg_rctsize = mp->mscp_guse.guse_rctsize;
	ra->ra_geom.rg_rbns = mp->mscp_guse.guse_nrpt;
	ra->ra_geom.rg_nrct = mp->mscp_guse.guse_nrct;
#endif
}

/*
 * Queue a transfer request, and if possible, hand it to the controller.
 *
 * This routine is broken into two so that the internal version
 * udastrat1() can be called by the (nonexistent, as yet) bad block
 * revectoring routine.
 */
udastrategy(bp)
E 60
	register struct buf *bp;
{
I 60
	register int unit;
E 60
	register struct uba_device *ui;
D 60
	register struct uba_ctlr *um;
	register struct buf *dp;
E 60
I 54
D 64
	register struct disklabel *lp;
E 64
E 54
D 60
	register int unit;
I 29
D 54
	register struct size    *rasizes;
E 29
	int xunit = minor(bp->b_dev) & 07;
E 54
I 54
	struct uda_softc *sc;
	int xunit = udpart(bp->b_dev);
E 60
I 60
	register struct ra_info *ra;
	struct partition *pp;
	int p;
E 60
E 54
	daddr_t sz, maxsz;
I 2
D 60
	int s;
E 60
E 2

D 54
	sz = (bp->b_bcount+511) >> 9;
E 54
D 37
	unit = dkunit(bp);
D 29
	if (unit >= NRA)
E 29
I 29
	if (unit >= nNRA)
E 37
I 37
D 60
	unit = udunit(bp->b_dev);
D 45
	if (unit >= nNRA) {
E 45
I 45
	if (unit >= NRA) {
E 60
I 60
	/*
	 * Make sure this is a reasonable drive to use.
	 */
	if ((unit = udaunit(bp->b_dev)) >= NRA ||
	    (ui = udadinfo[unit]) == NULL || ui->ui_alive == 0 ||
	    (ra = &ra_info[unit])->ra_state == CLOSED) {
E 60
E 45
		bp->b_error = ENXIO;
E 37
E 29
		goto bad;
I 37
	}
E 37
I 29
D 54
	rasizes = ra_info[unit].ra_sizes;
E 54
E 29
D 60
	ui = uddinfo[unit];
I 54
	lp = &udlabel[unit];
	sc = &uda_softc[ui->ui_ctlr];
E 54
	um = ui->ui_mi;
D 37
	if (ui == 0 || ui->ui_alive == 0)
E 37
I 37
D 54
	if (ui == 0 || ui->ui_alive == 0) {
E 54
I 54
	if (ui == 0 || ui->ui_alive == 0 || ra_info[unit].rastate == CLOSED) {
E 54
		bp->b_error = ENXIO;
E 37
		goto bad;
E 60
I 60

	/*
	 * If drive is open `raw' or reading label, let it at it.
	 */
	if (ra->ra_state < OPEN) {
		udastrat1(bp);
		return;
E 60
I 37
	}
E 37
D 29
	if ((maxsz = ra_sizes[xunit].nblocks) < 0)
		maxsz = radsize[unit] - ra_sizes[xunit].blkoff;
E 29
I 29
D 54
	if ((maxsz = rasizes[xunit].nblocks) < 0)
		maxsz = ra_info[unit].radsize - rasizes[xunit].blkoff;
E 29
	if (bp->b_blkno < 0 || bp->b_blkno+sz > maxsz ||
D 29
	    ra_sizes[xunit].blkoff >= radsize[unit])
E 29
I 29
D 37
	    rasizes[xunit].blkoff >= ra_info[unit].radsize)
E 37
I 37
	    rasizes[xunit].blkoff >= ra_info[unit].radsize) {
E 54
I 54
D 60
	if (ra_info[unit].rastate < OPEN)
		goto q;
	if ((ra_info[unit].openpart & (1 << xunit)) == 0) {
		bp->b_error = ENODEV;
		goto bad;
	}
	maxsz = lp->d_partitions[xunit].p_size; 
E 60
I 60
	p = udapart(bp->b_dev);
D 64
	if ((ra->ra_openpart & (1 << p)) == 0)	/* can't happen? */
		panic("udastrategy");
		/* alternatively, ENODEV */
E 64
I 64
	if ((ra->ra_openpart & (1 << p)) == 0) {
		bp->b_error = ENODEV;
		goto bad;
	}
E 64

	/*
	 * Determine the size of the transfer, and make sure it is
	 * within the boundaries of the partition.
	 */
	pp = &udalabel[unit].d_partitions[p];
	maxsz = pp->p_size;
	if (pp->p_offset + pp->p_size > ra->ra_dsize)
		maxsz = ra->ra_dsize - pp->p_offset;
E 60
	sz = (bp->b_bcount + DEV_BSIZE - 1) >> DEV_BSHIFT;
I 64
	if (bp->b_blkno + pp->p_offset <= LABELSECTOR &&
#if LABELSECTOR != 0
	    bp->b_blkno + pp->p_offset + sz > LABELSECTOR &&
#endif
	    (bp->b_flags & B_READ) == 0 && ra->ra_wlabel == 0) {
		bp->b_error = EROFS;
		goto bad;
	}
E 64
	if (bp->b_blkno < 0 || bp->b_blkno + sz > maxsz) {
I 60
		/* if exactly at end of disk, return an EOF */
E 60
E 54
D 38
		if (bp->b_blkno == maxsz +1)
E 38
I 38
		if (bp->b_blkno == maxsz) {
			bp->b_resid = bp->b_bcount;
E 38
D 54
		        goto done;
E 54
I 54
D 60
			goto done;
E 60
I 60
			biodone(bp);
			return;
E 60
E 54
I 38
		}
I 60
		/* or truncate if part of it fits */
E 60
E 38
D 54
		bp->b_error = EINVAL;
E 37
E 29
		goto bad;
E 54
I 54
		sz = maxsz - bp->b_blkno;
		if (sz <= 0) {
D 60
			bp->b_error = EINVAL;
E 60
I 60
			bp->b_error = EINVAL;	/* or hang it up */
E 60
			goto bad;
		}
		bp->b_bcount = sz << DEV_BSHIFT;
E 54
I 37
	}
I 54
D 60
q:
E 54
E 37
D 2
	(void) spl5();
E 2
I 2
	s = spl5();
E 60
I 60
	udastrat1(bp);
	return;
bad:
	bp->b_flags |= B_ERROR;
	biodone(bp);
}

/*
 * Work routine for udastrategy.
 */
udastrat1(bp)
	register struct buf *bp;
{
	register int unit = udaunit(bp->b_dev);
	register struct uba_ctlr *um;
	register struct buf *dp;
	struct uba_device *ui;
	int s = spl5();

E 60
E 2
	/*
D 60
	 * Link the buffer onto the drive queue
E 60
I 60
	 * Append the buffer to the drive queue, and if it is not
	 * already there, the drive to the controller queue.  (However,
	 * if the drive queue is marked to be requeued, we must be
	 * awaiting an on line or get unit status command; in this
	 * case, leave it off the controller queue.)
E 60
	 */
D 60
	dp = &udutab[ui->ui_unit];
	if (dp->b_actf == 0)
		dp->b_actf = bp;
	else
		dp->b_actl->av_forw = bp;
	dp->b_actl = bp;
	bp->av_forw = 0;
E 60
I 60
	um = (ui = udadinfo[unit])->ui_mi;
	dp = &udautab[unit];
	APPEND(bp, dp, av_forw);
	if (dp->b_active == 0 && (ui->ui_flags & UNIT_REQUEUE) == 0) {
		APPEND(dp, &um->um_tab, b_forw);
		dp->b_active++;
	}

E 60
	/*
D 60
	 * Link the drive onto the controller queue
E 60
I 60
	 * Start activity on the controller.  Note that unlike other
	 * Unibus drivers, we must always do this, not just when the
	 * controller is not active.
E 60
	 */
D 60
	if (dp->b_active == 0) {
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
		dp->b_active = 1;
	}
	if (um->um_tab.b_active == 0) {
#if defined(VAX750)
D 21
		if (cpu == VAX_750) {
E 21
I 21
		if (cpu == VAX_750
		    && udwtab[um->um_ctlr].av_forw == &udwtab[um->um_ctlr]) {
E 21
D 29
			if (um->um_ubinfo != 0)
D 21
				printf("uda: ubinfo %x\n",um->um_ubinfo);
E 21
I 21
				printf("udastrat: ubinfo 0x%x\n",um->um_ubinfo);
E 21
			else
E 29
I 29
			if (um->um_ubinfo != 0) {
				printd("udastrat: ubinfo 0x%x\n",um->um_ubinfo);
			} else
E 29
				um->um_ubinfo =
D 3
				uballoc(um->um_ubanum, 0, 0, UBA_NEEDBDP);
E 3
I 3
D 21
				uballoc(um->um_ubanum, (caddr_t)0, 0,
E 21
I 21
				   uballoc(um->um_ubanum, (caddr_t)0, 0,
E 21
					UBA_NEEDBDP);
E 3
		}
#endif
		(void) udstart(um);
	}
E 60
I 60
	udastart(um);
E 60
D 2
	(void) spl0();
E 2
I 2
	splx(s);
E 2
D 60
	return;

bad:
	bp->b_flags |= B_ERROR;
I 37
done:
E 37
	iodone(bp);
	return;
E 60
}

D 60
udstart(um)
E 60
I 60
/*
 * Start up whatever transfers we can find.
 * Note that udastart() must be called at spl5().
 */
udastart(um)
E 60
	register struct uba_ctlr *um;
{
I 60
	register struct uda_softc *sc = &uda_softc[um->um_ctlr];
E 60
	register struct buf *bp, *dp;
	register struct mscp *mp;
D 60
	register struct uda_softc *sc;
	register struct uba_device *ui;
I 29
D 54
	struct  size    *rasizes;
E 54
I 54
	struct disklabel *lp;
E 60
I 60
	struct uba_device *ui;
E 60
E 54
E 29
	struct udadevice *udaddr;
I 29
D 54
	struct  uda     *ud = &uda[um->um_ctlr];
E 54
I 54
D 60
	struct uda *ud = &uda[um->um_ctlr];
	daddr_t sz;
E 54
E 29
	int i;
E 60
I 60
	struct partition *pp;
	int i, sz;
E 60

D 60
	sc = &uda_softc[um->um_ctlr];
	
loop:
	if ((dp = um->um_tab.b_actf) == NULL) {
D 54
		/*
		 * Release uneeded UBA resources and return
		 */
E 54
I 54

E 54
		um->um_tab.b_active = 0;
I 29
		/* Check for response ring transitions lost in the
		 * Race condition
		 */
		for (i = sc->sc_lastrsp;; i++) {
			i %= NRSP;
			if (ud->uda_ca.ca_rspdsc[i]&UDA_OWN)
				break;
			udrsp(um, ud, sc, i);
			ud->uda_ca.ca_rspdsc[i] |= UDA_OWN;
		}
		sc->sc_lastrsp = i;
E 29
D 21
#if defined(VAX750)
		if (cpu == VAX_750) {
D 19
			if (um->um_ubinfo == 0)
				printf("uda: um_ubinfo == 0\n");
			else
E 19
I 19
			if (um->um_ubinfo != 0)
E 19
				ubarelse(um->um_ubanum, &um->um_ubinfo);
		}
#endif
E 21
D 3
		return(0);
E 3
I 3
		return (0);
E 60
I 60
#ifdef lint
	i = 0; i = i;
#endif
	/*
	 * If it is not running, try (again and again...) to initialise
	 * it.  If it is currently initialising just ignore it for now.
	 */
	if (sc->sc_state != ST_RUN) {
		if (sc->sc_state == ST_IDLE && udainit(um->um_ctlr))
			printf("uda%d: still hung\n", um->um_ctlr);
		return;
E 60
E 3
	}
I 60

	/*
	 * If um_cmd is nonzero, this controller is on the Unibus
	 * resource wait queue.  It will not help to try more requests;
	 * instead, when the Unibus unblocks and calls udadgo(), we
	 * will call udastart() again.
	 */
	if (um->um_cmd)
		return;

	sc->sc_flags |= SC_INSTART;
	udaddr = (struct udadevice *) um->um_addr;

loop:
	/*
	 * Service the drive at the head of the queue.  It may not
	 * need anything, in which case it might be shutting down
	 * in udaclose().
	 */
	if ((dp = um->um_tab.b_actf) == NULL)
		goto out;
E 60
	if ((bp = dp->b_actf) == NULL) {
D 60
		/*
		 * No more requests for this drive, remove
		 * from controller queue and look at next drive.
		 * We know we're at the head of the controller queue.
		 */
E 60
		dp->b_active = 0;
		um->um_tab.b_actf = dp->b_forw;
I 55
D 60
		if (ra_info[dp - udutab].openpart == 0)
			wakeup((caddr_t)dp);
E 55
D 29
		goto loop;
E 29
I 29
		goto loop;		/* Need to check for loop */
E 60
I 60
		if (ra_info[dp - udautab].ra_openpart == 0)
			wakeup((caddr_t)dp); /* finish close protocol */
		goto loop;
E 60
E 29
	}
D 60
	um->um_tab.b_active++;
	udaddr = (struct udadevice *)um->um_addr;
	if ((udaddr->udasa&UDA_ERR) || sc->sc_state != S_RUN) {
		harderr(bp, "ra");
D 29
		printf("udasa %o, state %d\n", udaddr->udasa&0xffff, sc->sc_state);
E 29
I 29
		mprintf("Uda%d udasa %o, state %d\n",um->um_ctlr , udaddr->udasa&0xffff, sc->sc_state);
E 29
D 45
		udinit(um->um_ctlr);
E 45
I 45
		(void)udinit(um->um_ctlr);
E 45
		/* SHOULD REQUEUE OUTSTANDING REQUESTS, LIKE UDRESET */
D 3
		return;
E 3
I 3
		return (0);
E 60
I 60

	if (udaddr->udasa & UDA_ERR) {	/* ctlr fatal error */
D 65
		udasaerror(um);
E 65
I 65
		udasaerror(um, 1);
E 65
		goto out;
E 60
E 3
	}
D 37
	ui = uddinfo[dkunit(bp)];
E 37
I 37
D 60
	ui = uddinfo[udunit(bp->b_dev)];
E 37
D 29
	/*
	 * If no credits, can't issue any commands
	 * until some outstanding commands complete.
	 */
	if (sc->sc_credits < 2)
D 3
		return(0);
E 3
I 3
		return (0);
E 3
	if ((mp = udgetcp(um)) == NULL)
D 3
		return(0);
E 3
I 3
		return (0);
E 3
	sc->sc_credits--;	/* committed to issuing a command */
	if (ui->ui_flags == 0) {	/* not online */
E 29
I 29
D 54
	rasizes = ra_info[ui->ui_unit].ra_sizes;
E 54
I 54
	lp = &udlabel[ui->ui_unit];
E 54
	if (ui->ui_flags == 0) {        /* not online */
		if ((mp = udgetcp(um)) == NULL){
			return (0);
E 60
I 60

	/*
	 * Get an MSCP packet, then figure out what to do.  If
	 * we cannot get a command packet, the command ring may
	 * be too small:  We should have at least as many command
	 * packets as credits, for best performance.
	 */
	if ((mp = mscp_getcp(&sc->sc_mi, MSCP_DONTWAIT)) == NULL) {
		if (sc->sc_mi.mi_credits > MSCP_MINCREDITS &&
		    (sc->sc_flags & SC_GRIPED) == 0) {
			log(LOG_NOTICE, "uda%d: command ring too small\n",
				um->um_ctlr);
			sc->sc_flags |= SC_GRIPED;/* complain only once */
E 60
		}
E 29
D 60
		mp->mscp_opcode = M_OP_ONLIN;
		mp->mscp_unit = ui->ui_slave;
		dp->b_active = 2;
D 29
		um->um_tab.b_actf = dp->b_forw;	/* remove from controller q */
E 29
I 29
		um->um_tab.b_actf = dp->b_forw; /* remove from controller q */
#ifdef	DEBUG
E 29
		printd("uda: bring unit %d online\n", ui->ui_slave);
I 29
#endif		
E 29
		*((long *)mp->mscp_dscptr) |= UDA_OWN|UDA_INT;
I 29
		if (udaddr->udasa&UDA_ERR)
			printf("Uda (%d) Error (%x)\n",um->um_ctlr , udaddr->udasa&0xffff);
E 29
		i = udaddr->udaip;
		goto loop;
E 60
I 60
		goto out;
E 60
	}
D 60
	switch (cpu) {
I 34
	case VAX_8600:
E 34
	case VAX_780:
		i = UBA_NEEDBDP|UBA_CANTWAIT;
		break;
E 60

D 60
	case VAX_750:
		i = um->um_ubinfo|UBA_HAVEBDP|UBA_CANTWAIT;
		break;

D 4
	case VAX_7ZZ:
E 4
I 4
	case VAX_730:
I 47
	case VAX_630:
E 47
E 4
		i = UBA_CANTWAIT;
		break;
E 60
I 60
	/*
	 * Bring the drive on line if it is not already.  Get its status
	 * if we do not already have it.  Otherwise just start the transfer.
	 */
	ui = udadinfo[udaunit(bp->b_dev)];
	if ((ui->ui_flags & UNIT_ONLINE) == 0) {
		mp->mscp_opcode = M_OP_ONLINE;
		goto common;
E 60
	}
D 36
	if ((i = ubasetup(um->um_ubanum, bp, i)) == 0) {
I 29
		if(dp->b_qsize != 0){
			return(0); /* When a command completes and */
				   /* frees a bdp udstart will be called */
		}
		if ((mp = udgetcp(um)) == NULL){
			return (0);
		}
E 29
		mp->mscp_opcode = M_OP_GTUNT;
		mp->mscp_unit = ui->ui_slave;
		*((long *)mp->mscp_dscptr) |= UDA_OWN|UDA_INT;
D 29
		i = udaddr->udaip;	/* initiate polling */
		return(1);		/* wait for interrupt */
E 29
I 29
		if (udaddr->udasa&UDA_ERR)
			printf("Uda(%d) udasa (%x)\n",um->um_ctlr, udaddr->udasa&0xffff);
		i = udaddr->udaip;      /* initiate polling */
		return(1);              /* wait for interrupt */
E 29
	}
E 36
I 36
D 60
	if ((i = ubasetup(um->um_ubanum, bp, i)) == 0)
		return(1);
E 36
D 29
	mp->mscp_cmdref = (long)bp;	/* pointer to get back */
E 29
I 29
	if ((mp = udgetcp(um)) == NULL) {
I 41
#if defined(VAX750)
		if (cpu == VAX_750)
			i &= 0xfffffff;         /* mask off bdp */
E 60
I 60
	if ((ui->ui_flags & UNIT_HAVESTATUS) == 0) {
		mp->mscp_opcode = M_OP_GETUNITST;
common:
if (ui->ui_flags & UNIT_REQUEUE) panic("udastart");
		/*
		 * Take the drive off the controller queue.  When the
		 * command finishes, make sure the drive is requeued.
		 */
		um->um_tab.b_actf = dp->b_forw;
		dp->b_active = 0;
		ui->ui_flags |= UNIT_REQUEUE;
		mp->mscp_unit = ui->ui_slave;
		*mp->mscp_addr |= MSCP_OWN | MSCP_INT;
		sc->sc_flags |= SC_STARTPOLL;
#ifdef POLLSTATS
		sc->sc_ncmd++;
E 60
#endif
E 41
D 60
		ubarelse(um->um_ubanum,&i);
		return(0);
E 60
I 60
		goto loop;
E 60
	}
D 60
	mp->mscp_cmdref = (long)bp;     /* pointer to get back */
E 29
	mp->mscp_opcode = bp->b_flags&B_READ ? M_OP_READ : M_OP_WRITE;
E 60
I 60

	pp = &udalabel[ui->ui_unit].d_partitions[udapart(bp->b_dev)];
	mp->mscp_opcode = (bp->b_flags & B_READ) ? M_OP_READ : M_OP_WRITE;
E 60
	mp->mscp_unit = ui->ui_slave;
D 29
	mp->mscp_lbn = bp->b_blkno + ra_sizes[minor(bp->b_dev)&7].blkoff;
E 29
I 29
D 54
	mp->mscp_lbn = bp->b_blkno + rasizes[minor(bp->b_dev)&7].blkoff;
E 29
	mp->mscp_bytecnt = bp->b_bcount;
E 54
D 60
	mp->mscp_buffer = (i & 0x3ffff) | (((i>>28)&0xf)<<24);
#if defined(VAX750)
	if (cpu == VAX_750)
D 29
		i &= 0xfffffff;		/* mask off bdp */
E 29
I 29
		i &= 0xfffffff;         /* mask off bdp */
E 29
#endif
D 29
	bp->b_ubinfo = i;		/* save mapping info */
E 29
I 29
	bp->b_ubinfo = i;               /* save mapping info */
I 54
	i = udpart(bp->b_dev);
	mp->mscp_lbn = bp->b_blkno +
	    lp->d_partitions[i].p_offset;
E 60
I 60
	mp->mscp_seq.seq_lbn = bp->b_blkno + pp->p_offset;
D 62
	pp = &udalabel[ui->ui_unit].d_partitions[udapart(bp->b_dev)];
E 62
E 60
	sz = (bp->b_bcount + DEV_BSIZE - 1) >> DEV_BSHIFT;
D 60
	if (bp->b_blkno + sz > lp->d_partitions[i].p_size)
		mp->mscp_bytecnt = (lp->d_partitions[i].p_size - bp->b_blkno) >>
		    DEV_BSHIFT;
	else
		mp->mscp_bytecnt = bp->b_bcount;
E 54
E 29
	*((long *)mp->mscp_dscptr) |= UDA_OWN|UDA_INT;
D 29
	i = udaddr->udaip;		/* initiate polling */
E 29
I 29
	if (udaddr->udasa&UDA_ERR) 
		printf("Uda(%d) udasa (%x)\n",um->um_ctlr , udaddr->udasa&0xffff);
	i = udaddr->udaip;              /* initiate polling */
	dp->b_qsize++;
E 29
	if (ui->ui_dk >= 0) {
		dk_busy |= 1<<ui->ui_dk;
D 29
		dp->b_qsize++;
E 29
		dk_xfer[ui->ui_dk]++;
		dk_wds[ui->ui_dk] += bp->b_bcount>>6;
	}
E 60
I 60
	mp->mscp_seq.seq_bytecount = bp->b_blkno + sz > pp->p_size ?
		(pp->p_size - bp->b_blkno) >> DEV_BSHIFT : bp->b_bcount;
	/* mscp_cmdref is filled in by mscp_go() */
E 60

	/*
D 60
	 * Move drive to the end of the controller queue
E 60
I 60
	 * Drop the packet pointer into the `command' field so udadgo()
	 * can tell what to start.  If ubago returns 1, we can do another
	 * transfer.  If not, um_cmd will still point at mp, so we will
	 * know that we are waiting for resources.
E 60
	 */
D 60
	if (dp->b_forw != NULL) {
		um->um_tab.b_actf = dp->b_forw;
		um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
		dp->b_forw = NULL;
	}
E 60
I 60
	um->um_cmd = (int)mp;
	if (ubago(ui))
		goto loop;

E 60
	/*
D 60
	 * Move buffer to I/O wait queue
E 60
I 60
	 * All done, or blocked in ubago().  If we managed to
	 * issue some commands, start up the beast.
E 60
	 */
D 60
	dp->b_actf = bp->av_forw;
	dp = &udwtab[um->um_ctlr];
	bp->av_forw = dp;
	bp->av_back = dp->av_back;
	dp->av_back->av_forw = bp;
	dp->av_back = bp;
	goto loop;
E 60
I 60
out:
	if (sc->sc_flags & SC_STARTPOLL) {
#ifdef POLLSTATS
		udastats.cmd[sc->sc_ncmd]++;
		sc->sc_ncmd = 0;
#endif
D 65
		i = ((struct udadevice *) um->um_addr)->udaip;
E 65
I 65
		i = ((struct udadevice *)um->um_addr)->udaip;
E 65
	}
	sc->sc_flags &= ~(SC_INSTART | SC_STARTPOLL);
E 60
}

/*
D 60
 * UDA interrupt routine.
E 60
I 60
 * Start a transfer.
 *
 * If we are not called from within udastart(), we must have been
 * blocked, so call udastart to do more requests (if any).  If
 * this calls us again immediately we will not recurse, because
 * that time we will be in udastart().  Clever....
E 60
 */
D 60
udintr(d)
D 54
	int d;
E 54
I 54
	register d;
E 60
I 60
udadgo(um)
	register struct uba_ctlr *um;
E 60
E 54
{
D 54
	register struct uba_ctlr *um = udminfo[d];
E 54
I 54
D 60
	struct uba_ctlr *um = udminfo[d];
E 54
	register struct udadevice *udaddr = (struct udadevice *)um->um_addr;
E 60
I 60
	struct uda_softc *sc = &uda_softc[um->um_ctlr];
	struct mscp *mp = (struct mscp *)um->um_cmd;

	um->um_tab.b_active++;	/* another transfer going */

	/*
	 * Fill in the MSCP packet and move the buffer to the
	 * I/O wait queue.  Mark the controller as no longer on
	 * the resource queue, and remember to initiate polling.
	 */
D 73
	mp->mscp_seq.seq_buffer = (um->um_ubinfo & 0x3ffff) |
E 73
I 73
	mp->mscp_seq.seq_buffer = UBAI_ADDR(um->um_ubinfo) |
E 73
		(UBAI_BDP(um->um_ubinfo) << 24);
	mscp_go(&sc->sc_mi, mp, um->um_ubinfo);
	um->um_cmd = 0;	
	um->um_ubinfo = 0;	/* tyke it awye */
	sc->sc_flags |= SC_STARTPOLL;
#ifdef POLLSTATS
	sc->sc_ncmd++;
#endif
	if ((sc->sc_flags & SC_INSTART) == 0)
		udastart(um);
}

udaiodone(mi, bp, info)
	register struct mscp_info *mi;
E 60
	struct buf *bp;
D 60
	register int i;
	register struct uda_softc *sc = &uda_softc[d];
	register struct uda *ud = &uda[d];
	struct uda *uud;
E 60
I 60
	int info;
{
	register struct uba_ctlr *um = udaminfo[mi->mi_ctlr];

	um->um_ubinfo = info;
	ubadone(um);
	biodone(bp);
	if (um->um_bdp && mi->mi_wtab.av_forw == &mi->mi_wtab)
		ubarelse(um->um_ubanum, &um->um_bdp);
	um->um_tab.b_active--;	/* another transfer done */
}

I 65
static struct saerr {
	int	code;		/* error code (including UDA_ERR) */
	char	*desc;		/* what it means: Efoo => foo error */
} saerr[] = {
	{ 0100001, "Eunibus packet read" },
	{ 0100002, "Eunibus packet write" },
	{ 0100003, "EUDA ROM and RAM parity" },
	{ 0100004, "EUDA RAM parity" },
	{ 0100005, "EUDA ROM parity" },
	{ 0100006, "Eunibus ring read" },
	{ 0100007, "Eunibus ring write" },
	{ 0100010, " unibus interrupt master failure" },
	{ 0100011, "Ehost access timeout" },
	{ 0100012, " host exceeded command limit" },
	{ 0100013, " unibus bus master failure" },
	{ 0100014, " DM XFC fatal error" },
	{ 0100015, " hardware timeout of instruction loop" },
	{ 0100016, " invalid virtual circuit id" },
	{ 0100017, "Eunibus interrupt write" },
	{ 0104000, "Efatal sequence" },
	{ 0104040, " D proc ALU" },
	{ 0104041, "ED proc control ROM parity" },
	{ 0105102, "ED proc w/no BD#2 or RAM parity" },
	{ 0105105, "ED proc RAM buffer" },
	{ 0105152, "ED proc SDI" },
	{ 0105153, "ED proc write mode wrap serdes" },
	{ 0105154, "ED proc read mode serdes, RSGEN & ECC" },
	{ 0106040, "EU proc ALU" },
	{ 0106041, "EU proc control reg" },
	{ 0106042, " U proc DFAIL/cntl ROM parity/BD #1 test CNT" },
	{ 0106047, " U proc const PROM err w/D proc running SDI test" },
	{ 0106055, " unexpected trap" },
	{ 0106071, "EU proc const PROM" },
	{ 0106072, "EU proc control ROM parity" },
	{ 0106200, "Estep 1 data" },
	{ 0107103, "EU proc RAM parity" },
	{ 0107107, "EU proc RAM buffer" },
	{ 0107115, " test count wrong (BD 12)" },
	{ 0112300, "Estep 2" },
	{ 0122240, "ENPR" },
	{ 0122300, "Estep 3" },
	{ 0142300, "Estep 4" },
	{ 0, " unknown error code" }
};

E 65
/*
D 65
 * The error bit was set in the controller status register.  Gripe,
 * reset the controller, requeue pending transfers.
E 65
I 65
 * If the error bit was set in the controller status register, gripe,
 * then (optionally) reset the controller and requeue pending transfers.
E 65
 */
D 65
udasaerror(um)
E 65
I 65
udasaerror(um, doreset)
E 65
	register struct uba_ctlr *um;
I 65
	int doreset;
E 65
{
I 65
	register int code = ((struct udadevice *)um->um_addr)->udasa;
	register struct saerr *e;
E 65

D 65
	printf("uda%d: controller error, sa=%b\n", um->um_ctlr,
		((struct udadevice *) um->um_addr)->udasa, udasr_bits);
	mscp_requeue(&uda_softc[um->um_ctlr].sc_mi);
	(void) udainit(um->um_ctlr);
E 65
I 65
	if ((code & UDA_ERR) == 0)
		return;
	for (e = saerr; e->code; e++)
		if (e->code == code)
			break;
	printf("uda%d: controller error, sa=0%o (%s%s)\n",
		um->um_ctlr, code, e->desc + 1,
		*e->desc == 'E' ? " error" : "");
	if (doreset) {
		mscp_requeue(&uda_softc[um->um_ctlr].sc_mi);
		(void) udainit(um->um_ctlr);
	}
E 65
}

/*
 * Interrupt routine.  Depending on the state of the controller,
 * continue initialisation, or acknowledge command and response
 * interrupts, and process responses.
 */
udaintr(ctlr)
	int ctlr;
{
	register struct uba_ctlr *um = udaminfo[ctlr];
	register struct uda_softc *sc = &uda_softc[ctlr];
D 65
	register struct udadevice *udaddr = (struct udadevice *) um->um_addr;
E 65
I 65
	register struct udadevice *udaddr = (struct udadevice *)um->um_addr;
E 65
	register struct uda *ud;
E 60
D 54
	struct mscp *mp;
E 54
I 54
	register struct mscp *mp;
I 60
	register int i;
E 60
E 54

D 29
	printd("udintr: state %d, udasa %o\n", sc->sc_state, udaddr->udasa);
E 29
I 29
D 60
#ifdef	DEBUG
	printd10("udintr: state %d, udasa %o\n", sc->sc_state, udaddr->udasa);
#endif	
E 60
I 47
D 72
#ifdef VAX630
E 72
I 72
#ifdef QBA
E 72
D 60
	(void) spl5();
E 60
I 60
D 73
	(void) spl5();		/* Qbus interrupt protocol is odd */
E 73
I 73
	splx(sc->sc_ipl);	/* Qbus interrupt protocol is odd */
E 73
E 60
#endif
I 60
	sc->sc_wticks = 0;	/* reset interrupt watchdog */

	/*
	 * Combinations during steps 1, 2, and 3: STEPnMASK
	 * corresponds to which bits should be tested;
	 * STEPnGOOD corresponds to the pattern that should
	 * appear after the interrupt from STEPn initialisation.
	 * All steps test the bits in ALLSTEPS.
	 */
#define	ALLSTEPS	(UDA_ERR|UDA_STEP4|UDA_STEP3|UDA_STEP2|UDA_STEP1)

#define	STEP1MASK	(ALLSTEPS | UDA_IE | UDA_NCNRMASK)
#define	STEP1GOOD	(UDA_STEP2 | UDA_IE | (NCMDL2 << 3) | NRSPL2)

#define	STEP2MASK	(ALLSTEPS | UDA_IE | UDA_IVECMASK)
#define	STEP2GOOD	(UDA_STEP3 | UDA_IE | (sc->sc_ivec >> 2))

#define	STEP3MASK	ALLSTEPS
#define	STEP3GOOD	UDA_STEP4

E 60
E 47
E 29
	switch (sc->sc_state) {
D 60
	case S_IDLE:
		printf("uda%d: random interrupt ignored\n", d);
E 60
I 60

	case ST_IDLE:
		/*
		 * Ignore unsolicited interrupts.
		 */
		log(LOG_WARNING, "uda%d: stray intr\n", ctlr);
E 60
		return;

D 60
	case S_STEP1:
I 5
D 29
#define	STEP1MASK	0174377
E 5
#define	STEP1GOOD	(UDA_STEP2|UDA_IE|(NCMDL2<<3)|NRSPL2)
E 29
I 29
#define STEP1MASK       0174377
#define STEP1GOOD       (UDA_STEP2|UDA_IE|(NCMDL2<<3)|NRSPL2)
E 29
D 5
		if ((udaddr->udasa&(UDA_ERR|STEP1GOOD)) != STEP1GOOD) {
E 5
I 5
		if ((udaddr->udasa&STEP1MASK) != STEP1GOOD) {
E 5
			sc->sc_state = S_IDLE;
D 3
			wakeup(um);
E 3
I 3
			wakeup((caddr_t)um);
E 60
I 60
	case ST_STEP1:
		/*
		 * Begin step two initialisation.
		 */
		if ((udaddr->udasa & STEP1MASK) != STEP1GOOD) {
			i = 1;
initfailed:
			printf("uda%d: init step %d failed, sa=%b\n",
				ctlr, i, udaddr->udasa, udasr_bits);
I 65
			udasaerror(um, 0);
E 65
			sc->sc_state = ST_IDLE;
			if (sc->sc_flags & SC_DOWAKE) {
				sc->sc_flags &= ~SC_DOWAKE;
D 65
				wakeup((caddr_t) sc);
E 65
I 65
				wakeup((caddr_t)sc);
E 65
			}
E 60
E 3
			return;
		}
D 60
		udaddr->udasa = ((int)&sc->sc_uda->uda_ca.ca_ringbase)|
D 34
		    (cpu == VAX_780 ? UDA_PI : 0);
E 34
I 34
		    ((cpu == VAX_780) || (cpu == VAX_8600) ? UDA_PI : 0);
E 34
		sc->sc_state = S_STEP2;
E 60
I 60
D 65
		udaddr->udasa = (int) &sc->sc_uda->uda_ca.ca_rspdsc[0] |
E 65
I 65
		udaddr->udasa = (int)&sc->sc_uda->uda_ca.ca_rspdsc[0] |
E 65
			(cpu == VAX_780 || cpu == VAX_8600 ? UDA_PI : 0);
		sc->sc_state = ST_STEP2;
E 60
		return;

D 60
	case S_STEP2:
I 5
D 29
#define	STEP2MASK	0174377
E 5
#define	STEP2GOOD	(UDA_STEP3|UDA_IE|(sc->sc_ivec/4))
E 29
I 29
#define STEP2MASK       0174377
#define STEP2GOOD       (UDA_STEP3|UDA_IE|(sc->sc_ivec/4))
E 29
D 5
		if ((udaddr->udasa&(UDA_ERR|STEP2GOOD)) != STEP2GOOD) {
E 5
I 5
		if ((udaddr->udasa&STEP2MASK) != STEP2GOOD) {
E 5
			sc->sc_state = S_IDLE;
D 3
			wakeup(um);
E 3
I 3
			wakeup((caddr_t)um);
E 3
			return;
E 60
I 60
	case ST_STEP2:
		/*
		 * Begin step 3 initialisation.
		 */
		if ((udaddr->udasa & STEP2MASK) != STEP2GOOD) {
			i = 2;
			goto initfailed;
E 60
		}
D 60
		udaddr->udasa = ((int)&sc->sc_uda->uda_ca.ca_ringbase)>>16;
		sc->sc_state = S_STEP3;
E 60
I 60
D 65
		udaddr->udasa = ((int) &sc->sc_uda->uda_ca.ca_rspdsc[0]) >> 16;
E 65
I 65
		udaddr->udasa = ((int)&sc->sc_uda->uda_ca.ca_rspdsc[0]) >> 16;
E 65
		sc->sc_state = ST_STEP3;
E 60
		return;

D 60
	case S_STEP3:
I 5
D 29
#define	STEP3MASK	0174000
E 5
#define	STEP3GOOD	UDA_STEP4
E 29
I 29
#define STEP3MASK       0174000
#define STEP3GOOD       UDA_STEP4
E 29
D 5
		if ((udaddr->udasa&(UDA_ERR|STEP3GOOD)) != STEP3GOOD) {
E 5
I 5
		if ((udaddr->udasa&STEP3MASK) != STEP3GOOD) {
E 5
			sc->sc_state = S_IDLE;
D 3
			wakeup(um);
E 3
I 3
			wakeup((caddr_t)um);
E 3
			return;
E 60
I 60
	case ST_STEP3:
		/*
		 * Set controller characteristics (finish initialisation).
		 */
		if ((udaddr->udasa & STEP3MASK) != STEP3GOOD) {
			i = 3;
			goto initfailed;
E 60
		}
I 29
D 60
		udamicro[d] = udaddr->udasa;
D 54
#ifdef	DEBUG
		printd("Uda%d Version %d model %d\n",d,udamicro[d]&0xF,
			(udamicro[d]>>4) & 0xF);
I 42
#endif
E 54
I 54
		log(LOG_INFO, "uda%d: version %d model %d\n", d,
		    udamicro[d] & 0xf, (udamicro[d] >> 4) & 0xf);
E 60
I 60
		i = udaddr->udasa & 0xff;
		if (i != sc->sc_micro) {
			sc->sc_micro = i;
			printf("uda%d: version %d model %d\n",
				ctlr, i & 0xf, i >> 4);
		}

E 60
E 54
E 42
		/*
D 60
		 * Requesting the error status (|= 2)
		 * may hang older controllers.
E 60
I 60
		 * Present the burst size, then remove it.  Why this
		 * should be done this way, I have no idea.
		 *
		 * Note that this assumes udaburst[ctlr] > 0.
E 60
		 */
D 42
		udaddr->udasa = UDA_GO | (udaerror? 2 : 0);
#endif
E 42
I 42
D 43
		udaddr->udasa = UDA_GO | ((udaburst[d] - 1) << 2) |
		     (udaerror? 2 : 0);
E 43
I 43
D 60
		i = UDA_GO | (udaerror? 2 : 0);
		if (udaburst[d])
			i |= (udaburst[d] - 1) << 2;
		udaddr->udasa = i;
E 60
I 60
		udaddr->udasa = UDA_GO | (udaburst[ctlr] - 1) << 2;
E 60
E 43
E 42
E 29
		udaddr->udasa = UDA_GO;
D 60
		sc->sc_state = S_SCHAR;
E 60
I 60
		printf("uda%d: DMA burst size set to %d\n",
			ctlr, udaburst[ctlr]);
E 60

I 60
		udainitds(ctlr);	/* initialise data structures */

E 60
		/*
D 60
		 * Initialize the data structures.
E 60
I 60
		 * Before we can get a command packet, we need some
		 * credits.  Fake some up to keep mscp_getcp() happy,
		 * get a packet, and cancel all credits (the right
		 * number should come back in the response to the
		 * SCC packet).
E 60
		 */
D 60
		uud = sc->sc_uda;
		for (i = 0; i < NRSP; i++) {
			ud->uda_ca.ca_rspdsc[i] = UDA_OWN|UDA_INT|
				(long)&uud->uda_rsp[i].mscp_cmdref;
			ud->uda_rsp[i].mscp_dscptr = &ud->uda_ca.ca_rspdsc[i];
D 29
			ud->uda_rsp[i].mscp_header.uda_msglen = sizeof (struct mscp);
E 29
I 29
			ud->uda_rsp[i].mscp_header.uda_msglen = mscp_msglen;
E 29
		}
		for (i = 0; i < NCMD; i++) {
			ud->uda_ca.ca_cmddsc[i] = UDA_INT|
				(long)&uud->uda_cmd[i].mscp_cmdref;
			ud->uda_cmd[i].mscp_dscptr = &ud->uda_ca.ca_cmddsc[i];
D 29
			ud->uda_cmd[i].mscp_header.uda_msglen = sizeof (struct mscp);
E 29
I 29
			ud->uda_cmd[i].mscp_header.uda_msglen = mscp_msglen;
E 29
		}
		bp = &udwtab[d];
		bp->av_forw = bp->av_back = bp;
D 29
		sc->sc_lastcmd = 0;
E 29
I 29
		sc->sc_lastcmd = 1;
E 29
		sc->sc_lastrsp = 0;
D 29
		if ((mp = udgetcp(um)) == NULL) {
			sc->sc_state = S_IDLE;
D 3
			wakeup(um);
E 3
I 3
			wakeup((caddr_t)um);
E 3
			return;
		}
E 29
I 29
		mp = &uda[um->um_ctlr].uda_cmd[0];
		mp->mscp_unit = mp->mscp_modifier = 0;
		mp->mscp_flags = 0;
		mp->mscp_bytecnt = mp->mscp_buffer = 0;
		mp->mscp_errlgfl = mp->mscp_copyspd = 0;
E 29
		mp->mscp_opcode = M_OP_STCON;
		mp->mscp_cntflgs = M_CF_ATTN|M_CF_MISC|M_CF_THIS;
		*((long *)mp->mscp_dscptr) |= UDA_OWN|UDA_INT;
D 29
		i = udaddr->udaip;	/* initiate polling */
E 29
I 29
		i = udaddr->udaip;      /* initiate polling */
E 60
I 60
		sc->sc_mi.mi_credits = MSCP_MINCREDITS + 1;
		mp = mscp_getcp(&sc->sc_mi, MSCP_DONTWAIT);
		if (mp == NULL)	/* `cannot happen' */
			panic("udaintr");
		sc->sc_mi.mi_credits = 0;
		mp->mscp_opcode = M_OP_SETCTLRC;
		mp->mscp_unit = 0;
		mp->mscp_sccc.sccc_ctlrflags = M_CF_ATTN | M_CF_MISC |
			M_CF_THIS;
		*mp->mscp_addr |= MSCP_OWN | MSCP_INT;
		i = udaddr->udaip;
		sc->sc_state = ST_SETCHAR;
E 60
E 29
		return;

D 60
	case S_SCHAR:
	case S_RUN:
E 60
I 60
	case ST_SETCHAR:
	case ST_RUN:
		/*
		 * Handle Set Ctlr Characteristics responses and operational
		 * responses (via mscp_dorsp).
		 */
E 60
		break;

	default:
D 60
		printf("uda%d: interrupt in unknown state %d ignored\n",
			d, sc->sc_state);
		return;
E 60
I 60
		printf("uda%d: driver bug, state %d\n", ctlr, sc->sc_state);
		panic("udastate");
E 60
	}

D 60
	if (udaddr->udasa&UDA_ERR) {
D 29
		printf("uda%d: fatal error (%o)\n", d, udaddr->udasa&0xffff);
E 29
I 29
		printf("uda(%d): fatal error (%o)\n", d, udaddr->udasa&0xffff);
E 29
		udaddr->udaip = 0;
D 3
		wakeup(um);
E 3
I 3
		wakeup((caddr_t)um);
E 60
I 60
	if (udaddr->udasa & UDA_ERR) {	/* ctlr fatal error */
D 65
		udasaerror(um);
E 65
I 65
		udasaerror(um, 1);
E 65
		return;
E 60
E 3
	}

I 60
	ud = &uda[ctlr];

E 60
	/*
D 60
	 * Check for a buffer purge request.
E 60
I 60
	 * Handle buffer purge requests.
D 66
	 * I have never seen these to work usefully, thus the log().
E 66
E 60
	 */
	if (ud->uda_ca.ca_bdp) {
D 45
		/*
		 * THIS IS A KLUDGE.
		 * Maybe we should change the entire
		 * UBA interface structure.
		 */
D 29
		int s = spl7();

E 29
I 29
		int s = spl6();		/* was spl7 but I don't like turning */
					/* off machine checks */
E 29
		i = um->um_ubinfo;
E 45
I 29
D 60
#ifdef	DEBUG
E 29
		printd("uda: purge bdp %d\n", ud->uda_ca.ca_bdp);
I 29
#endif		
E 60
I 60
D 66
		log(LOG_DEBUG, "uda%d: purge bdp %d\n",
			ctlr, ud->uda_ca.ca_bdp);
E 66
E 60
E 29
D 45
		um->um_ubinfo = ud->uda_ca.ca_bdp<<28;
		ubapurge(um);
		um->um_ubinfo = i;
		(void) splx(s);
E 45
I 45
		UBAPURGE(um->um_hd->uh_uba, ud->uda_ca.ca_bdp);
E 45
		ud->uda_ca.ca_bdp = 0;
D 29
		udaddr->udasa = 0;	/* signal purge complete */
E 29
I 29
D 60
		udaddr->udasa = 0;      /* signal purge complete */
E 60
I 60
		udaddr->udasa = 0;	/* signal purge complete */
E 60
E 29
	}

	/*
D 60
	 * Check for response ring transition.
E 60
I 60
	 * Check for response and command ring transitions.
E 60
	 */
	if (ud->uda_ca.ca_rspint) {
		ud->uda_ca.ca_rspint = 0;
D 60
		for (i = sc->sc_lastrsp;; i++) {
			i %= NRSP;
			if (ud->uda_ca.ca_rspdsc[i]&UDA_OWN)
				break;
			udrsp(um, ud, sc, i);
			ud->uda_ca.ca_rspdsc[i] |= UDA_OWN;
		}
		sc->sc_lastrsp = i;
E 60
I 60
		mscp_dorsp(&sc->sc_mi);
E 60
	}
D 60

	/*
	 * Check for command ring transition.
	 */
E 60
	if (ud->uda_ca.ca_cmdint) {
I 29
D 60
#ifdef	DEBUG
E 29
		printd("uda: command ring transition\n");
I 29
#endif		
E 60
E 29
		ud->uda_ca.ca_cmdint = 0;
I 60
		MSCP_DOCMD(&sc->sc_mi);
E 60
	}
I 29
D 60
	if(uda_cp_wait)
D 45
		wakeup(&uda_cp_wait);
E 45
I 45
		wakeup((caddr_t)&uda_cp_wait);
E 45
E 29
D 3
	udstart(um);
E 3
I 3
	(void) udstart(um);
E 60
I 60
	udastart(um);
E 60
E 3
}

I 60
D 65
#ifndef GENERIC_RAW
struct buf rudabuf[NRA];

E 65
E 60
/*
D 60
 * Process a response packet
E 60
I 60
D 65
 * Read and write.
E 60
 */
D 60
udrsp(um, ud, sc, i)
	register struct uba_ctlr *um;
	register struct uda *ud;
	register struct uda_softc *sc;
	int i;
E 60
I 60
udaread(dev, uio)
	dev_t dev;
	struct uio *uio;
E 60
{
D 60
	register struct mscp *mp;
D 54
	struct uba_device *ui;
D 29
	struct buf *dp, *bp;
E 29
I 29
	struct buf *dp, *bp,nullbp;
E 54
I 54
	register struct uba_device *ui;
	register int unit;
	struct buf *dp, *bp, nullbp;
E 54
E 29
	int st;
E 60

D 60
	mp = &ud->uda_rsp[i];
D 29
	mp->mscp_header.uda_msglen = sizeof (struct mscp);
	sc->sc_credits += mp->mscp_header.uda_credits & 0xf;
	if ((mp->mscp_header.uda_credits & 0xf0) > 0x10)
E 29
I 29
	mp->mscp_header.uda_msglen = mscp_msglen;
	sc->sc_credits += mp->mscp_header.uda_credits & 0xf;  /* just 4 bits?*/
	if ((mp->mscp_header.uda_credits & 0xf0) > 0x10)	/* Check */
E 29
		return;
I 29
#ifdef	DEBUG
	printd10("udarsp, opcode 0x%x status 0x%x\n",mp->mscp_opcode,mp->mscp_status);
#endif	
E 29
	/*
	 * If it's an error log message (datagram),
	 * pass it on for more extensive processing.
	 */
D 29
	if ((mp->mscp_header.uda_credits & 0xf0) == 0x10) {
E 29
I 29
	if ((mp->mscp_header.uda_credits & 0xf0) == 0x10) {	/* check */
E 29
		uderror(um, (struct mslg *)mp);
		return;
	}
D 29
	if (mp->mscp_unit >= 8)
		return;
	if ((ui = udip[um->um_ctlr][mp->mscp_unit]) == 0)
		return;
E 29
	st = mp->mscp_status&M_ST_MASK;
D 29
	switch (mp->mscp_opcode) {
	case M_OP_STCON|M_OP_END:
E 29
I 29
	/* The controller interrupts as drive 0 */
	/* this means that you must check for controller interrupts */
	/* before you check to see if there is a drive 0 */
	if((M_OP_STCON|M_OP_END) == mp->mscp_opcode){
E 29
		if (st == M_ST_SUCC)
			sc->sc_state = S_RUN;
		else
			sc->sc_state = S_IDLE;
		um->um_tab.b_active = 0;
D 3
		wakeup(um);
E 3
I 3
		wakeup((caddr_t)um);
E 3
D 29
		break;
E 29
I 29
		return;
	}
	if (mp->mscp_unit >= 8)
		return;
	if ((ui = udip[um->um_ctlr][mp->mscp_unit]) == 0)
		return;
I 54
	unit = ui->ui_unit;
E 54
	switch (mp->mscp_opcode) {
E 60
I 60
	return (physio(udastrategy, &rudabuf[udaunit(dev)], dev, B_READ,
		minphys, uio));
}
E 60
E 29

D 60
	case M_OP_ONLIN|M_OP_END:
D 29
		/*
		 * Link the drive onto the controller queue
		 */
E 29
I 29
D 54
		ra_info[ui->ui_unit].rastatus = st;
		ra_info[ui->ui_unit].ratype =  mp->mscp_mediaid;
E 29
		dp = &udutab[ui->ui_unit];
E 54
I 54
		ra_info[unit].rastatus = st;
		ra_info[unit].ratype =  mp->mscp_mediaid;
		dp = &udutab[unit];
E 54
D 29
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
E 29
		if (st == M_ST_SUCC) {
D 29
			ui->ui_flags = 1;	/* mark it online */
			radsize[ui->ui_unit] = (daddr_t)mp->mscp_untsize;
E 29
I 29
			/*
			 * Link the drive onto the controller queue
			 */
			dp->b_forw = NULL;
			if (um->um_tab.b_actf == NULL)
				um->um_tab.b_actf = dp;
			else
				um->um_tab.b_actl->b_forw = dp;
			um->um_tab.b_actl = dp;
			ui->ui_flags = 1;       /* mark it online */
D 54
			ra_info[ui->ui_unit].radsize=(daddr_t)mp->mscp_untsize;
E 54
I 54
D 56
			ra_info[unit].radsize=(daddr_t)mp->mscp_untsize;
E 56
			ra_info[unit].rastate = OPENRAW;
I 56
			ra_info[unit].radsize=(daddr_t)mp->mscp_untsize;
E 56
E 54
#ifdef	DEBUG
E 29
			printd("uda: unit %d online\n", mp->mscp_unit);
I 21
D 26
/*** New for ***/       printf("uda%d: online, size=%d\n",
/*** debugging **/              mp->mscp_unit, (daddr_t)mp->mscp_untsize);
E 26
I 26
D 29
#ifdef notdef
			printf("uda%d: online, size=%d\n",
			      mp->mscp_unit, (daddr_t)mp->mscp_untsize);
#endif
E 29
I 29
#endif			
#define F_to_C(x,i)     ( ((x)->mscp_mediaid) >> (i*5+7) & 0x1f ? ( ( (((x)->mscp_mediaid) >>( i*5 + 7)) & 0x1f) + 'A' - 1): ' ')
		/* this mess decodes the Media type identifier */
#ifdef	DEBUG
			printd("uda: unit %d online %x %c%c %c%c%c%d\n"
				,mp->mscp_unit, mp->mscp_mediaid
				,F_to_C(mp,4),F_to_C(mp,3),F_to_C(mp,2)
				,F_to_C(mp,1),F_to_C(mp,0)
				,mp->mscp_mediaid & 0x7f);
#endif				
D 44
			switch(mp->mscp_mediaid & 0x7f){
E 44
I 44
D 54
			switch((int)(mp->mscp_mediaid & 0x7f)){
E 44
			case    25:
				ra_info[ui->ui_unit].ra_sizes = ra25_sizes;
I 47
				break;
I 49
			case    52:
				ra_info[ui->ui_unit].ra_sizes = rd52_sizes;
				break;
E 49
			case    53:
D 49
				ra_info[ui->ui_unit].ra_sizes = ra53_sizes;
E 49
I 49
				ra_info[ui->ui_unit].ra_sizes = rd53_sizes;
E 49
E 47
				break;
			case    60:
				ra_info[ui->ui_unit].ra_sizes = ra60_sizes;
				break;
			case    80:
				ra_info[ui->ui_unit].ra_sizes = ra80_sizes;
				break;
			case    81:
				ra_info[ui->ui_unit].ra_sizes = ra81_sizes;
				break;
			default:
				ui->ui_flags = 0;       /* mark it offline */
				ra_info[ui->ui_unit].ratype = 0;
				printf("Don't have a parition table for ");
				printf("a %c%c %c%c%c%d\n"
				,F_to_C(mp,4),F_to_C(mp,3),F_to_C(mp,2)
				,F_to_C(mp,1),F_to_C(mp,0)
				,mp->mscp_mediaid & 0x7f);
				while (bp = dp->b_actf) {
					dp->b_actf = bp->av_forw;
					bp->b_flags |= B_ERROR;
					iodone(bp);
				}
			}
E 54
			dp->b_active = 1;
E 29
E 26
E 21
		} else {
D 29
			harderr(dp->b_actf, "ra");
E 29
I 29
			if(dp->b_actf){
				harderr(dp->b_actf,"ra");
			} else {
				nullbp.b_blkno = 0;
D 54
				nullbp.b_dev = makedev(UDADEVNUM,ui->ui_unit);
E 54
I 54
				nullbp.b_dev = makedev(UDADEVNUM,unit);
E 54
				harderr(&nullbp, "ra");
			}
E 29
			printf("OFFLINE\n");
			while (bp = dp->b_actf) {
				dp->b_actf = bp->av_forw;
				bp->b_flags |= B_ERROR;
				iodone(bp);
			}
I 54
			ra_info[unit].rastate = CLOSED;
E 54
		}
D 29
		dp->b_active = 1;
E 29
I 29
		if(mp->mscp_cmdref!=NULL){/* Seems to get lost sometimes */
D 45
			wakeup((caddr_t *) mp->mscp_cmdref);
E 45
I 45
			wakeup((caddr_t)mp->mscp_cmdref);
E 45
		}
E 29
		break;
E 60
I 60
udawrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
E 60

I 29
D 60
/*
 * The AVAILABLE ATTENTION messages occurs when the
 * unit becomes available after spinup,
 * marking the unit offline will force an online command
 * prior to using the unit.
 */
E 29
	case M_OP_AVATN:
I 29
#ifdef	DEBUG
E 29
		printd("uda: unit %d attention\n", mp->mscp_unit);
D 29
		ui->ui_flags = 0;	/* it went offline and we didn't notice */
E 29
I 29
#endif		
		ui->ui_flags = 0;       /* it went offline and we didn't notice */
D 54
		ra_info[ui->ui_unit].ratype =  mp->mscp_mediaid;
E 54
I 54
		ra_info[unit].ratype =  mp->mscp_mediaid;
E 54
E 29
		break;
E 60
I 60
	return (physio(udastrategy, &rudabuf[udaunit(dev)], dev, B_WRITE,
		minphys, uio));
}
#endif /* GENERIC_RAW */
E 60

I 29
D 60
	case M_OP_END:
E 60
/*
E 65
D 60
 * An endcode without an opcode (0200) is an invalid command.
 * The mscp specification states that this would be a protocol
 * type error, such as illegal opcodes. The mscp spec. also
 * states that parameter error type of invalid commands should
 * return the normal end message for the command. This does not appear
 * to be the case. An invalid logical block number returned an endcode
 * of 0200 instead of the 0241 (read) that was expected.
E 60
I 60
 * Initialise the various data structures that control the UDA50.
E 60
 */
D 60
	
		printf("endcd=%o, stat=%o\n", mp->mscp_opcode, mp->mscp_status);
		break;
E 29
	case M_OP_READ|M_OP_END:
	case M_OP_WRITE|M_OP_END:
		bp = (struct buf *)mp->mscp_cmdref;
D 3
		ubarelse(um->um_ubanum, &bp->b_resid);
E 3
I 3
D 5
		ubarelse(um->um_ubanum, (int *)&bp->b_resid);
E 5
I 5
		ubarelse(um->um_ubanum, (int *)&bp->b_ubinfo);
E 5
E 3
		/*
		 * Unlink buffer from I/O wait queue.
		 */
		bp->av_back->av_forw = bp->av_forw;
		bp->av_forw->av_back = bp->av_back;
I 21
#if defined(VAX750)
D 41
		if (cpu == VAX_750
E 41
I 41
		if (cpu == VAX_750 && um->um_tab.b_active == 0
E 41
		    && udwtab[um->um_ctlr].av_forw == &udwtab[um->um_ctlr]) {
			if (um->um_ubinfo == 0)
				printf("udintr: um_ubinfo == 0\n");
			else
				ubarelse(um->um_ubanum, &um->um_ubinfo);
		}
#endif
E 21
D 54
		dp = &udutab[ui->ui_unit];
E 54
I 54
		dp = &udutab[unit];
E 54
I 29
		dp->b_qsize--;
E 29
		if (ui->ui_dk >= 0)
D 29
			if (--dp->b_qsize == 0)
E 29
I 29
			if (dp->b_qsize == 0)
E 29
				dk_busy &= ~(1<<ui->ui_dk);
		if (st == M_ST_OFFLN || st == M_ST_AVLBL) {
D 29
			ui->ui_flags = 0;	/* mark unit offline */
E 29
I 29
			ui->ui_flags = 0;       /* mark unit offline */
E 29
			/*
			 * Link the buffer onto the front of the drive queue
			 */
			if ((bp->av_forw = dp->b_actf) == 0)
				dp->b_actl = bp;
			dp->b_actf = bp;
			/*
			 * Link the drive onto the controller queue
			 */
			if (dp->b_active == 0) {
				dp->b_forw = NULL;
				if (um->um_tab.b_actf == NULL)
					um->um_tab.b_actf = dp;
				else
					um->um_tab.b_actl->b_forw = dp;
				um->um_tab.b_actl = dp;
				dp->b_active = 1;
			}
I 21
#if defined(VAX750)
			if (cpu == VAX750 && um->um_ubinfo == 0)
				um->um_ubinfo =
				   uballoc(um->um_ubanum, (caddr_t)0, 0,
					UBA_NEEDBDP);
#endif
E 21
			return;
		}
		if (st != M_ST_SUCC) {
			harderr(bp, "ra");
D 29
			printf("status %o\n", mp->mscp_status);
E 29
I 29
#ifdef	DEBUG
			printd("status %o\n", mp->mscp_status);
#endif
E 29
			bp->b_flags |= B_ERROR;
		}
		bp->b_resid = bp->b_bcount - mp->mscp_bytecnt;
		iodone(bp);
		break;
E 60
I 60
udainitds(ctlr)
	int ctlr;
{
	register struct uda *ud = &uda[ctlr];
	register struct uda *uud = uda_softc[ctlr].sc_uda;
	register struct mscp *mp;
	register int i;
E 60

D 60
	case M_OP_GTUNT|M_OP_END:
I 29
#ifdef	DEBUG
		printd("GTUNT end packet status = 0x%x media id 0x%x\n"
			,st,mp->mscp_mediaid);
#endif		
D 54
		ra_info[ui->ui_unit].rastatus = st;
		ra_info[ui->ui_unit].ratype =  mp->mscp_mediaid;
E 54
I 54
		ra_info[unit].rastatus = st;
		ra_info[unit].ratype = mp->mscp_mediaid;
E 54
E 29
		break;

	default:
		printf("uda: unknown packet\n");
I 29
		uderror(um, (struct mslg *)mp);
E 60
I 60
	for (i = 0, mp = ud->uda_rsp; i < NRSP; i++, mp++) {
		ud->uda_ca.ca_rspdsc[i] = MSCP_OWN | MSCP_INT |
			(long)&uud->uda_rsp[i].mscp_cmdref;
		mp->mscp_addr = &ud->uda_ca.ca_rspdsc[i];
		mp->mscp_msglen = MSCP_MSGLEN;
E 60
E 29
	}
I 60
	for (i = 0, mp = ud->uda_cmd; i < NCMD; i++, mp++) {
		ud->uda_ca.ca_cmddsc[i] = MSCP_INT |
			(long)&uud->uda_cmd[i].mscp_cmdref;
		mp->mscp_addr = &ud->uda_ca.ca_cmddsc[i];
		mp->mscp_msglen = MSCP_MSGLEN;
	}
E 60
}

D 60

E 60
/*
D 60
 * Process an error log message
 *
 * For now, just log the error on the console.
 * Only minimal decoding is done, only "useful"
 * information is printed.  Eventually should
 * send message to an error logger.
E 60
I 60
D 65
 * Handle an error datagram.  All we do now is decode it.
E 65
I 65
 * Handle an error datagram.
E 65
E 60
 */
D 60
uderror(um, mp)
	register struct uba_ctlr *um;
	register struct mslg *mp;
E 60
I 60
udadgram(mi, mp)
	struct mscp_info *mi;
	struct mscp *mp;
E 60
{
D 5
	printf("uda%d:%d: %s error, ", um->um_ctlr, mp->mslg_seqnum,
E 5
I 5
D 29
	printf("uda%d: %s error, ", um->um_ctlr,
E 5
		mp->mslg_flags&M_LF_SUCC ? "soft" : "hard");
E 29
I 29
D 60
	register	i;
E 60

I 60
	mscp_decodeerror(mi->mi_md->md_mname, mi->mi_ctlr, mp);
I 65
	/*
	 * SDI status information bytes 10 and 11 are the microprocessor
	 * error code and front panel code respectively.  These vary per
	 * drive type and are printed purely for field service information.
	 */
	if (mp->mscp_format == M_FM_SDI)
		printf("\tsdi uproc error code 0x%x, front panel code 0x%x\n",
			mp->mscp_erd.erd_sdistat[10],
			mp->mscp_erd.erd_sdistat[11]);
E 65
}
E 60

D 60
	if(!(mp->mslg_flags & (M_LF_SUCC | M_LF_CONT)))
		printf("uda%d: hard error\n");
E 60
I 60
/*
 * The Set Controller Characteristics command finished.
 * Record the new state of the controller.
 */
udactlrdone(mi, mp)
	register struct mscp_info *mi;
	struct mscp *mp;
{
	register struct uda_softc *sc = &uda_softc[mi->mi_ctlr];
E 60

D 60
	mprintf("uda%d: %s error, ", um->um_ctlr,
		mp->mslg_flags & ( M_LF_SUCC | M_LF_CONT ) ? "soft" : "hard");
E 29
	switch (mp->mslg_format) {
	case M_FM_CNTERR:
D 29
		printf("controller error, event 0%o\n", mp->mslg_event);
E 29
I 29
		mprintf("controller error, event 0%o\n", mp->mslg_event);
E 29
		break;

	case M_FM_BUSADDR:
D 29
		printf("host memory access error, event 0%o, addr 0%o\n",
E 29
I 29
		mprintf("host memory access error, event 0%o, addr 0%o\n",
E 29
D 15
			mp->mslg_event, *((long *)&mp->mslg_busaddr[0]));
E 15
I 15
			mp->mslg_event, mp->mslg_busaddr);
E 15
		break;

	case M_FM_DISKTRN:
D 5
		printf("disk transfer error, unit %d, grp %d, cyl %d, sec %d, ",
			mp->mslg_unit, mp->mslg_group, mp->mslg_cylinder,
			mp->mslg_sector);
		printf("trk %d, lbn %d, retry %d, level %d\n", mp->mslg_track,
			mp->mslg_lbn, mp->mslg_retry, mp->mslg_level);
E 5
I 5
D 21
		printf("disk transfer error, unit %d\n", mp->mslg_unit);
E 21
I 21
D 29
		printf("disk transfer error, unit %d, grp 0x%x, hdr 0x%x\n",
			mp->mslg_unit, mp->mslg_group, mp->mslg_hdr);
E 29
I 29
		mprintf("disk transfer error, unit %d, grp 0x%x, hdr 0x%x, event 0%o\n",
			mp->mslg_unit, mp->mslg_group, mp->mslg_hdr,
mp->mslg_event);
E 29
E 21
E 5
		break;

	case M_FM_SDI:
D 5
		printf("SDI error, unit %d, event 0%o, cyl %d\n", mp->mslg_unit,
			mp->mslg_event, mp->mslg_cylinder);
E 5
I 5
D 21
		printf("SDI error, unit %d, event 0%o\n", mp->mslg_unit,
			mp->mslg_event);
E 21
I 21
D 29
		printf("SDI error, unit %d, event 0%o, hdr 0x%x\n",
E 29
I 29
		mprintf("SDI error, unit %d, event 0%o, hdr 0x%x\n",
E 29
			mp->mslg_unit, mp->mslg_event, mp->mslg_hdr);
I 29
		for(i = 0; i < 12;i++)
			mprintf("\t0x%x",mp->mslg_sdistat[i] & 0xff);
		mprintf("\n");
E 29
E 21
E 5
		break;

	case M_FM_SMLDSK:
D 29
		printf("small disk error, unit %d, event 0%o, cyl %d\n",
E 29
I 29
		mprintf("small disk error, unit %d, event 0%o, cyl %d\n",
E 29
			mp->mslg_unit, mp->mslg_event, mp->mslg_sdecyl);
		break;

	default:
D 29
		printf("unknown error, unit %d, format 0%o, event 0%o\n",
E 29
I 29
		mprintf("unknown error, unit %d, format 0%o, event 0%o\n",
E 29
			mp->mslg_unit, mp->mslg_format, mp->mslg_event);
E 60
I 60
	if ((mp->mscp_status & M_ST_MASK) == M_ST_SUCCESS)
		sc->sc_state = ST_RUN;
	else {
		printf("uda%d: SETCTLRC failed: ",
			mi->mi_ctlr, mp->mscp_status);
		mscp_printevent(mp);
		sc->sc_state = ST_IDLE;
E 60
I 5
	}
D 60

	if (udaerror) {
		register long *p = (long *)mp;
D 29
		register int i;
E 29

		for (i = 0; i < mp->mslg_header.uda_msglen; i += sizeof(*p))
			printf("%x ", *p++);
		printf("\n");
E 60
I 60
	if (sc->sc_flags & SC_DOWAKE) {
		sc->sc_flags &= ~SC_DOWAKE;
		wakeup((caddr_t)sc);
E 60
E 5
	}
}

D 60

E 60
/*
D 60
 * Find an unused command packet
E 60
I 60
 * Received a response from an as-yet unconfigured drive.  Configure it
 * in, if possible.
E 60
 */
D 60
struct mscp *
udgetcp(um)
	struct uba_ctlr *um;
{
E 60
I 60
udaunconf(mi, mp)
	struct mscp_info *mi;
E 60
	register struct mscp *mp;
D 60
	register struct udaca *cp;
	register struct uda_softc *sc;
	register int i;
I 29
	int	s;
E 60
I 60
{
E 60
E 29

I 29
D 60
	s = spl5();
E 29
	cp = &uda[um->um_ctlr].uda_ca;
	sc = &uda_softc[um->um_ctlr];
E 60
I 29
	/*
D 60
	 * If no credits, can't issue any commands
	 * until some outstanding commands complete.
E 60
I 60
	 * If it is a slave response, copy it to udaslavereply for
	 * udaslave() to look at.
E 60
	 */
E 29
D 60
	i = sc->sc_lastcmd;
D 29
	if ((cp->ca_cmddsc[i] & (UDA_OWN|UDA_INT)) == UDA_INT) {
E 29
I 29
	if(((cp->ca_cmddsc[i]&(UDA_OWN|UDA_INT))==UDA_INT)&&
	    (sc->sc_credits >= 2)) {
		sc->sc_credits--;       /* committed to issuing a command */
E 29
		cp->ca_cmddsc[i] &= ~UDA_INT;
		mp = &uda[um->um_ctlr].uda_cmd[i];
		mp->mscp_unit = mp->mscp_modifier = 0;
		mp->mscp_opcode = mp->mscp_flags = 0;
		mp->mscp_bytecnt = mp->mscp_buffer = 0;
		mp->mscp_errlgfl = mp->mscp_copyspd = 0;
		sc->sc_lastcmd = (i + 1) % NCMD;
I 29
		(void) splx(s);
E 29
		return(mp);
E 60
I 60
	if (mp->mscp_opcode == (M_OP_GETUNITST | M_OP_END) &&
	    (uda_softc[mi->mi_ctlr].sc_flags & SC_INSLAVE) != 0) {
		udaslavereply = *mp;
		return (MSCP_DONE);
E 60
	}
I 29
D 60
	(void) splx(s);
E 29
	return(NULL);
}
E 60

D 7
udread(dev)
E 7
I 7
D 60
udread(dev, uio)
E 7
	dev_t dev;
I 7
	struct uio *uio;
E 7
{
D 37
	register int unit = minor(dev) >> 3;
E 37
I 37
	register int unit = udunit(dev);
E 60
I 60
	/*
	 * Otherwise, it had better be an available attention response.
	 */
	if (mp->mscp_opcode != M_OP_AVAILATTN)
		return (MSCP_FAILED);
E 60
E 37

D 29
	if (unit >= NRA)
E 29
I 29
D 45
	if (unit >= nNRA)
E 45
I 45
D 60
	if (unit >= NRA)
E 45
E 29
D 9
		u.u_error = ENXIO;
	else
D 7
		physio(udstrategy, &rudbuf[unit], dev, B_READ, minphys);
E 7
I 7
		physio(udstrategy, &rudbuf[unit], dev, B_READ, minphys, uio);
E 9
I 9
		return (ENXIO);
	return (physio(udstrategy, &rudbuf[unit], dev, B_READ, minphys, uio));
E 60
I 60
	/* do what autoconf does */
	return (MSCP_FAILED);	/* not yet, arwhite, not yet */
E 60
E 9
E 7
}

D 8
udwrite(dev)
E 8
I 8
D 60
udwrite(dev, uio)
E 8
	dev_t dev;
I 8
	struct uio *uio;
E 60
I 60
/*
 * A drive came on line.  Check its type and size.  Return DONE if
 * we think the drive is truly on line.  In any case, awaken anyone
 * sleeping on the drive on-line-ness.
 */
udaonline(ui, mp)
	register struct uba_device *ui;
	struct mscp *mp;
E 60
E 8
{
D 37
	register int unit = minor(dev) >> 3;
E 37
I 37
D 60
	register int unit = udunit(dev);
E 60
I 60
	register struct ra_info *ra = &ra_info[ui->ui_unit];
E 60
E 37

D 29
	if (unit >= NRA)
E 29
I 29
D 45
	if (unit >= nNRA)
E 45
I 45
D 60
	if (unit >= NRA)
E 45
E 29
D 9
		u.u_error = ENXIO;
	else
D 7
		physio(udstrategy, &rudbuf[unit], dev, B_WRITE, minphys);
E 7
I 7
D 8
		physio(udstrategy, &rudbuf[unit], dev, B_WRITE, minphys, 0);
E 8
I 8
		physio(udstrategy, &rudbuf[unit], dev, B_WRITE, minphys, uio);
E 9
I 9
		return (ENXIO);
	return (physio(udstrategy, &rudbuf[unit], dev, B_WRITE, minphys, uio));
E 60
I 60
	wakeup((caddr_t)&ui->ui_flags);
	if ((mp->mscp_status & M_ST_MASK) != M_ST_SUCCESS) {
D 73
		printf("uda%d: attempt to bring ra%d on line failed: ",
			ui->ui_ctlr, ui->ui_unit);
E 73
I 73
		if (!cold)
			printf("uda%d: ra%d", ui->ui_ctlr, ui->ui_unit);
		printf(": attempt to bring on line failed: ");
E 73
		mscp_printevent(mp);
		ra->ra_state = CLOSED;
		return (MSCP_FAILED);
	}

D 75
	ra->ra_state = OPENRAW;
E 75
I 75
	ra->ra_state = ONLINE;
E 75
	ra->ra_dsize = (daddr_t)mp->mscp_onle.onle_unitsize;
D 66
	printf("ra%d: uda%d, unit %d, size = %d sectors\n", ui->ui_unit,
		ui->ui_ctlr, mp->mscp_unit, ra->ra_dsize);
E 66
I 66
	if (!cold)
		printf("ra%d: uda%d, unit %d, size = %d sectors\n", ui->ui_unit,
		    ui->ui_ctlr, mp->mscp_unit, ra->ra_dsize);
E 66
D 83
	/* can now compute ncyl */
D 82
	ra->ra_geom.rg_ncyl = ra->ra_dsize / ra->ra_geom.rg_ntracks /
		ra->ra_geom.rg_nsectors;
E 82
I 82
	ra->ra_geom.rg_ncyl = howmany(ra->ra_dsize, ra->ra_geom.rg_ntracks *
		ra->ra_geom.rg_nsectors);
E 83
I 83
	/*
	 * can now compute ncyl
	 *
	 * There are some broken controllers that return zeros for the geometry
	 * parameters (observed on Emulex QD21 and UC06), causing the ncyl
	 * calculation below to blow up with a division by zero. We work around
	 * this by faking nsectors = 1, ntracks = 1, and ncyl = 1 when faced
	 * with such garbage. Of course this is only usable if one uses pack
	 * labels, but they are required for third-party disks anyway.
	 */
	if (ra->ra_geom.rg_nsectors && ra->ra_geom.rg_ntracks)
		ra->ra_geom.rg_ncyl = howmany(ra->ra_dsize,
			ra->ra_geom.rg_ntracks * ra->ra_geom.rg_nsectors);
	else
		ra->ra_geom.rg_nsectors = ra->ra_geom.rg_ntracks =
			ra->ra_geom.rg_ncyl = 1;
E 83
E 82
	return (MSCP_DONE);
E 60
E 9
E 8
E 7
}

D 60
udreset(uban)
	int uban;
{
	register struct uba_ctlr *um;
E 60
I 60
/*
 * We got some (configured) unit's status.  Return DONE if it succeeded.
 */
udagotstatus(ui, mp)
E 60
	register struct uba_device *ui;
D 60
	register struct buf *bp, *dp;
	register int unit;
	struct buf *nbp;
	int d;
E 60
I 60
	register struct mscp *mp;
{
E 60

D 60
	for (d = 0; d < NUDA; d++) {
		if ((um = udminfo[d]) == 0 || um->um_ubanum != uban ||
		    um->um_alive == 0)
			continue;
		printf(" uda%d", d);
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
		uda_softc[d].sc_state = S_IDLE;
D 29
		for (unit = 0; unit < NRA; unit++) {
E 29
I 29
		uda_softc[d].sc_mapped = 0;	/* Rich */
D 45
		for (unit = 0; unit < nNRA; unit++) {
E 45
I 45
		for (unit = 0; unit < NRA; unit++) {
E 45
E 29
			if ((ui = uddinfo[unit]) == 0)
				continue;
			if (ui->ui_alive == 0 || ui->ui_mi != um)
				continue;
			udutab[unit].b_active = 0;
			udutab[unit].b_qsize = 0;
		}
		for (bp = udwtab[d].av_forw; bp != &udwtab[d]; bp = nbp) {
			nbp = bp->av_forw;
D 3
			ubarelse(uban, &bp->b_ubinfo);
E 3
I 3
D 11
			ubarelse(uban, (int *)&bp->b_ubinfo);
E 11
I 11
			bp->b_ubinfo = 0;
E 11
E 3
			/*
			 * Link the buffer onto the drive queue
			 */
D 37
			dp = &udutab[dkunit(bp)];
E 37
I 37
			dp = &udutab[udunit(bp->b_dev)];
E 37
			if (dp->b_actf == 0)
				dp->b_actf = bp;
			else
				dp->b_actl->av_forw = bp;
			dp->b_actl = bp;
			bp->av_forw = 0;
			/*
			 * Link the drive onto the controller queue
			 */
			if (dp->b_active == 0) {
				dp->b_forw = NULL;
				if (um->um_tab.b_actf == NULL)
					um->um_tab.b_actf = dp;
				else
					um->um_tab.b_actl->b_forw = dp;
				um->um_tab.b_actl = dp;
				dp->b_active = 1;
			}
		}
D 45
		udinit(d);
E 45
I 45
		(void)udinit(d);
E 60
I 60
	if ((mp->mscp_status & M_ST_MASK) != M_ST_SUCCESS) {
		printf("uda%d: attempt to get status for ra%d failed: ",
			ui->ui_ctlr, ui->ui_unit);
		mscp_printevent(mp);
		return (MSCP_FAILED);
E 60
E 45
	}
I 60
	/* record for (future) bad block forwarding and whatever else */
	uda_rasave(ui->ui_unit, mp, 1);
	return (MSCP_DONE);
E 60
}

D 29
uddump()
E 29
I 29
D 60
#define DBSIZE 32

#define ca_Rspdsc       ca_rspdsc[0]
#define ca_Cmddsc       ca_rspdsc[1]
#define uda_Rsp         uda_rsp[0]
#define uda_Cmd         uda_cmd[0]

struct  uda     udad[NUDA];

uddump(dev)
	dev_t dev;
E 29
{
D 29
	return(ENXIO);
E 29
I 29
	struct udadevice *udaddr;
	struct uda *ud_ubaddr;
	char *start;
	int num, blk, unit;
	int maxsz;
	int blkoff;
	register struct uba_regs *uba;
E 60
I 60
/*
 * A transfer failed.  We get a chance to fix or restart it.
 * Need to write the bad block forwaring code first....
 */
/*ARGSUSED*/
udaioerror(ui, mp, bp)
E 60
	register struct uba_device *ui;
D 60
	register struct uda *udp;
	register struct pte *io;
	register int i;
D 54
	struct  size    *rasizes;
E 54
I 54
	struct disklabel *lp;
E 54
D 37
	unit = minor(dev) >> 3;
E 37
I 37
	unit = udunit(dev);
E 37
D 45
	if (unit >= nNRA)
E 45
I 45
	if (unit >= NRA)
E 45
		return (ENXIO);
#define phys(cast, addr) ((cast)((int)addr & 0x7fffffff))
	ui = phys(struct uba_device *, uddinfo[unit]);
	if (ui->ui_alive == 0)
		return (ENXIO);
	uba = phys(struct uba_hd *, ui->ui_hd)->uh_physuba;
	ubainit(uba);
	udaddr = (struct udadevice *)ui->ui_physaddr;
	DELAY(2000000);
	udp = phys(struct uda *, &udad[ui->ui_ctlr]);
I 54
	lp = &udlabel[unit];
E 60
I 60
	register struct mscp *mp;
	struct buf *bp;
{
E 60
E 54

D 60
	num = btoc(sizeof(struct uda)) + 1;
	io = &uba->uba_map[NUBMREG-num];
	for(i = 0; i<num; i++)
		*(int *)io++ = UBAMR_MRV|(btop(udp)+i);
	ud_ubaddr = (struct uda *)(((int)udp & PGOFSET)|((NUBMREG-num)<<9));

	udaddr->udaip = 0;
	while ((udaddr->udasa & UDA_STEP1) == 0)
		if(udaddr->udasa & UDA_ERR) return(EFAULT);
	udaddr->udasa = UDA_ERR;
	while ((udaddr->udasa & UDA_STEP2) == 0)
		if(udaddr->udasa & UDA_ERR) return(EFAULT);
	udaddr->udasa = (short)&ud_ubaddr->uda_ca.ca_ringbase;
	while ((udaddr->udasa & UDA_STEP3) == 0)
		if(udaddr->udasa & UDA_ERR) return(EFAULT);
	udaddr->udasa = (short)(((int)&ud_ubaddr->uda_ca.ca_ringbase) >> 16);
	while ((udaddr->udasa & UDA_STEP4) == 0)
		if(udaddr->udasa & UDA_ERR) return(EFAULT);
	udaddr->udasa = UDA_GO;
	udp->uda_ca.ca_Rspdsc = (long)&ud_ubaddr->uda_Rsp.mscp_cmdref;
	udp->uda_ca.ca_Cmddsc = (long)&ud_ubaddr->uda_Cmd.mscp_cmdref;
	udp->uda_Cmd.mscp_cntflgs = 0;
	udp->uda_Cmd.mscp_version = 0;
	if (udcmd(M_OP_STCON, udp, udaddr) == 0) {
		return(EFAULT);
E 60
I 60
	if (mp->mscp_flags & M_EF_BBLKR) {
		/*
		 * A bad block report.  Eventually we will
		 * restart this transfer, but for now, just
		 * log it and give up.
		 */
		log(LOG_ERR, "ra%d: bad block report: %d%s\n",
			ui->ui_unit, mp->mscp_seq.seq_lbn,
			mp->mscp_flags & M_EF_BBLKU ? " + others" : "");
	} else {
		/*
		 * What the heck IS a `serious exception' anyway?
		 * IT SURE WOULD BE NICE IF DEC SOLD DOCUMENTATION
		 * FOR THEIR OWN CONTROLLERS.
		 */
		if (mp->mscp_flags & M_EF_SEREX)
			log(LOG_ERR, "ra%d: serious exception reported\n",
				ui->ui_unit);
E 60
	}
D 60
	udp->uda_Cmd.mscp_unit = ui->ui_slave;
	if (udcmd(M_OP_ONLIN, udp, udaddr) == 0) {
		return(EFAULT);
	}

	num = maxfree;
	start = 0;
D 54
	rasizes = ra_info[ui->ui_unit].ra_sizes;
	maxsz = rasizes[minor(dev)&07].nblocks;
	blkoff = rasizes[minor(dev)&07].blkoff;
	if(maxsz < 0)
		maxsz = ra_info[unit].radsize-blkoff;
E 54
I 54
	blkoff = lp->d_partitions[udpart(dev)].p_offset;
	maxsz = lp->d_partitions[udpart(dev)].p_size;
E 54
D 35
	if (dumplo < 0 || dumplo + num >= maxsz)
E 35
I 35
	if (dumplo < 0)
E 35
		return (EINVAL);
I 35
	if (dumplo + num >= maxsz)
		num = maxsz - dumplo;
E 35
	blkoff += dumplo;
	while (num > 0) {
		blk = num > DBSIZE ? DBSIZE : num;
		io = uba->uba_map;
		for (i = 0; i < blk; i++)
			*(int *)io++ = (btop(start)+i) | UBAMR_MRV;
		*(int *)io = 0;
		udp->uda_Cmd.mscp_lbn = btop(start) + blkoff;
		udp->uda_Cmd.mscp_unit = ui->ui_slave;
		udp->uda_Cmd.mscp_bytecnt = blk*NBPG;
		udp->uda_Cmd.mscp_buffer = 0;
		if (udcmd(M_OP_WRITE, udp, udaddr) == 0) {
			return(EIO);
		}
		start += blk*NBPG;
		num -= blk;
	}
	return (0);
E 60
I 60
	return (MSCP_FAILED);
E 60
E 29
}
I 24
D 29
 
E 29
I 29

I 60
/*
 * A replace operation finished.
 */
/*ARGSUSED*/
udareplace(ui, mp)
	struct uba_device *ui;
	struct mscp *mp;
{
E 60

D 60
udcmd(op, udp, udaddr)
	int op;
	register struct uda *udp;
	struct udadevice *udaddr;
E 60
I 60
	panic("udareplace");
}

/*
 * A bad block related operation finished.
 */
/*ARGSUSED*/
udabb(ui, mp, bp)
	struct uba_device *ui;
	struct mscp *mp;
	struct buf *bp;
E 60
{
D 60
	int i;
E 60

D 44
#ifdef	lint
	i = i;
#endif

E 44
D 60
	udp->uda_Cmd.mscp_opcode = op;
	udp->uda_Rsp.mscp_header.uda_msglen = mscp_msglen;
	udp->uda_Cmd.mscp_header.uda_msglen = mscp_msglen;
	udp->uda_ca.ca_Rspdsc |= UDA_OWN|UDA_INT;
	udp->uda_ca.ca_Cmddsc |= UDA_OWN|UDA_INT;
	if (udaddr->udasa&UDA_ERR)
		printf("Udaerror udasa (%x)\n", udaddr->udasa&0xffff);
	i = udaddr->udaip;
I 44
#ifdef	lint
	i = i;
#endif
E 44
	for (;;) {
		if (udp->uda_ca.ca_cmdint)
			udp->uda_ca.ca_cmdint = 0;
		if (udp->uda_ca.ca_rspint)
			break;
	}
	udp->uda_ca.ca_rspint = 0;
	if (udp->uda_Rsp.mscp_opcode != (op|M_OP_END) ||
	    (udp->uda_Rsp.mscp_status&M_ST_MASK) != M_ST_SUCC) {
		printf("error: com %d opc 0x%x stat 0x%x\ndump ",
			op,
			udp->uda_Rsp.mscp_opcode,
			udp->uda_Rsp.mscp_status);
		return(0);
	}
	return(1);
E 60
I 60
	panic("udabb");
E 60
}

E 29
D 54
udsize(dev)
E 54
I 54
D 60
udioctl(dev, cmd, data, flag)
E 60
I 60

/*
 * I/O controls.
 */
udaioctl(dev, cmd, data, flag)
E 60
E 54
	dev_t dev;
I 54
	int cmd;
	caddr_t data;
	int flag;
E 54
{
D 37
	int unit = minor(dev) >> 3;
E 37
I 37
D 60
	int unit = udunit(dev);
E 60
I 60
	register int unit = udaunit(dev);
E 60
E 37
D 54
	struct uba_device *ui;
I 29
	struct	size	*rasizes;
E 54
I 54
	register struct disklabel *lp;
D 64
	int error = 0;
E 64
I 64
	register struct ra_info *ra = &ra_info[unit];
D 69
	int error = 0, wlab;
E 69
I 69
	int error = 0;
E 69
E 64
E 54
E 29

D 29
	if (unit >= NRA || (ui = uddinfo[unit]) == 0 || ui->ui_alive == 0)
E 29
I 29
D 45
	if (unit >= nNRA || (ui = uddinfo[unit]) == 0 || ui->ui_alive == 0
E 45
I 45
D 54
	if (unit >= NRA || (ui = uddinfo[unit]) == 0 || ui->ui_alive == 0
E 45
		 || ui->ui_flags == 0)
E 54
I 54
D 60
	lp = &udlabel[unit];
E 60
I 60
	lp = &udalabel[unit];
E 60

	switch (cmd) {

	case DIOCGDINFO:
		*(struct disklabel *)data = *lp;
		break;

D 55
	case DIOCGDINFOP:
		*(struct disklabel **)data = lp;
E 55
I 55
	case DIOCGPART:
		((struct partinfo *)data)->disklab = lp;
		((struct partinfo *)data)->part =
D 60
		    &lp->d_partitions[udpart(dev)];
E 60
I 60
		    &lp->d_partitions[udapart(dev)];
E 60
E 55
		break;

	case DIOCSDINFO:
		if ((flag & FWRITE) == 0)
			error = EBADF;
		else
D 61
			*lp = *(struct disklabel *)data;
E 61
I 61
			error = setdisklabel(lp, (struct disklabel *)data,
D 64
			    ra_info[unit].ra_openpart);
E 64
I 64
D 66
			    ra->ra_openpart);
E 66
I 66
			    (ra->ra_state == OPENRAW) ? 0 : ra->ra_openpart);
E 66
E 64
E 61
		break;

I 64
	case DIOCWLABEL:
		if ((flag & FWRITE) == 0)
			error = EBADF;
		else
			ra->ra_wlabel = *(int *)data;
		break;

E 64
D 60
	case DIOCWDINFO:
		if ((flag & FWRITE) == 0) {
			error = EBADF;
			break;
		}
		{
E 60
I 60
D 61
	case DIOCWDINFO: {
E 60
		struct buf *bp;
		struct disklabel *dlp;
I 58
#ifdef notdef
E 58
		daddr_t alt, end;
I 58
#endif
E 58

I 60
		if ((flag & FWRITE) == 0) {
E 61
I 61
	case DIOCWDINFO:
I 64
D 69
		/* simulate opening partition 0 so write succeeds */
		ra->ra_openpart |= (1 << 0);		/* XXX */
		wlab = ra->ra_wlabel;
		ra->ra_wlabel = 1;
E 69
E 64
		if ((flag & FWRITE) == 0)
E 61
			error = EBADF;
D 61
			break;
		}
E 60
		*lp = *(struct disklabel *)data;
		bp = geteblk(lp->d_secsize);
D 55
		bp->b_dev = dev;
E 55
I 55
D 60
		bp->b_dev = makedev(major(dev), udminor(udunit(dev), 0));
E 60
I 60
		bp->b_dev = makedev(major(dev), udaminor(udaunit(dev), 0));
E 60
E 55
		bp->b_bcount = lp->d_secsize;
		bp->b_blkno = LABELSECTOR;
		bp->b_flags = B_READ;
		dlp = (struct disklabel *)(bp->b_un.b_addr + LABELOFFSET);
D 60
		udstrategy(bp);
E 60
I 60
		udastrategy(bp);
E 60
		biowait(bp);
		if (bp->b_flags & B_ERROR) {
			error = u.u_error;		/* XXX */
			u.u_error = 0;
			goto bad;
		}
		*dlp = *lp;
I 58
#ifdef notdef
E 58
		alt = lp->d_ncylinders * lp->d_secpercyl - lp->d_ntracks + 1;
		end = alt + 8;
		for (;;) {
			bp->b_flags = B_WRITE;
D 60
			udstrategy(bp);
E 60
I 60
			udastrategy(bp);
E 60
			biowait(bp);
			if (bp->b_flags & B_ERROR) {
				error = u.u_error;	/* XXX */
				u.u_error = 0;
			}
			if (bp->b_blkno >= end)
				break;
			bp->b_blkno = alt;
			alt += 2;
		}
I 60
#else
		bp->b_flags = B_WRITE;
		udastrategy(bp);
		biowait(bp);
		if (bp->b_flags & B_ERROR) {
			error = u.u_error;		/* XXX */
			u.u_error = 0;
		}
E 60
I 58
#endif
E 58
bad:
		brelse(bp);
		}
E 61
I 61
		else if ((error = setdisklabel(lp, (struct disklabel *)data,
D 64
			    ra_info[unit].ra_openpart)) == 0)
E 64
I 64
D 66
			    ra->ra_openpart)) == 0)
E 66
I 66
		    (ra->ra_state == OPENRAW) ? 0 : ra->ra_openpart)) == 0) {
I 69
			int wlab;

E 69
			ra->ra_state = OPEN;
I 69
			/* simulate opening partition 0 so write succeeds */
			ra->ra_openpart |= (1 << 0);		/* XXX */
			wlab = ra->ra_wlabel;
			ra->ra_wlabel = 1;
E 69
E 66
E 64
			error = writedisklabel(dev, udastrategy, lp);
I 69
			ra->ra_openpart = ra->ra_copenpart | ra->ra_bopenpart;
			ra->ra_wlabel = wlab;
E 69
I 66
		}
E 66
I 64
D 69
		ra->ra_openpart = ra->ra_copenpart | ra->ra_bopenpart;
D 66
		if (error == 0)
			ra->ra_state = OPEN;
E 66
		ra->ra_wlabel = wlab;
E 69
E 64
E 61
		break;

I 60
#ifdef notyet
	case UDAIOCREPLACE:
		/*
		 * Initiate bad block replacement for the given LBN.
		 * (Should we allow modifiers?)
		 */
		error = EOPNOTSUPP;
		break;

	case UDAIOCGMICRO:
		/*
		 * Return the microcode revision for the UDA50 running
		 * this drive.
		 */
D 65
		*(int *) data = uda_softc[uddinfo[unit]->ui_ctlr].sc_micro;
E 65
I 65
		*(int *)data = uda_softc[uddinfo[unit]->ui_ctlr].sc_micro;
E 65
		break;
#endif

E 60
	default:
		error = ENOTTY;
		break;
	}
I 60
	return (error);
}

/*
 * A Unibus reset has occurred on UBA uban.  Reinitialise the controller(s)
 * on that Unibus, and requeue outstanding I/O.
 */
udareset(uban)
	int uban;
{
	register struct uba_ctlr *um;
	register struct uda_softc *sc;
	register int ctlr;

	for (ctlr = 0, sc = uda_softc; ctlr < NUDA; ctlr++, sc++) {
		if ((um = udaminfo[ctlr]) == NULL || um->um_ubanum != uban ||
		    um->um_alive == 0)
			continue;
		printf(" uda%d", ctlr);

		/*
		 * Our BDP (if any) is gone; our command (if any) is
		 * flushed; the device is no longer mapped; and the
		 * UDA50 is not yet initialised.
		 */
		if (um->um_bdp) {
			printf("<%d>", UBAI_BDP(um->um_bdp));
			um->um_bdp = 0;
		}
		um->um_ubinfo = 0;
		um->um_cmd = 0;
		sc->sc_flags &= ~SC_MAPPED;
		sc->sc_state = ST_IDLE;

		/* reset queues and requeue pending transfers */
		mscp_requeue(&sc->sc_mi);

		/*
		 * If it fails to initialise we will notice later and
		 * try again (and again...).  Do not call udastart()
		 * here; it will be done after the controller finishes
		 * initialisation.
		 */
		if (udainit(ctlr))
			printf(" (hung)");
	}
}

/*
 * Watchdog timer:  If the controller is active, and no interrupts
 * have occurred for 30 seconds, assume it has gone away.
 */
udawatch()
{
	register int i;
	register struct uba_ctlr *um;
	register struct uda_softc *sc;

	timeout(udawatch, (caddr_t) 0, hz);	/* every second */
	for (i = 0, sc = uda_softc; i < NUDA; i++, sc++) {
		if ((um = udaminfo[i]) == 0 || !um->um_alive)
			continue;
		if (sc->sc_state == ST_IDLE)
			continue;
		if (sc->sc_state == ST_RUN && !um->um_tab.b_active)
			sc->sc_wticks = 0;
		else if (++sc->sc_wticks >= 30) {
			sc->sc_wticks = 0;
			printf("uda%d: lost interrupt\n", i);
			ubareset(um->um_ubanum);
		}
	}
}

/*
 * Do a panic dump.  We set up the controller for one command packet
 * and one response packet, for which we use `struct uda1'.
 */
struct	uda1 {
	struct	uda1ca uda1_ca;	/* communications area */
	struct	mscp uda1_rsp;	/* response packet */
	struct	mscp uda1_cmd;	/* command packet */
} uda1;

#define	DBSIZE	32		/* dump 16K at a time */

udadump(dev)
	dev_t dev;
{
	struct udadevice *udaddr;
	struct uda1 *ud_ubaddr;
	char *start;
	int num, blk, unit, maxsz, blkoff, reg;
	struct partition *pp;
	register struct uba_regs *uba;
	register struct uba_device *ui;
	register struct uda1 *ud;
	register struct pte *io;
	register int i;

	/*
	 * Make sure the device is a reasonable place on which to dump.
	 */
	unit = udaunit(dev);
	if (unit >= NRA)
		return (ENXIO);
D 65
#define	phys(cast, addr)	((cast) ((int) addr & 0x7fffffff))
E 65
I 65
#define	phys(cast, addr)	((cast) ((int)addr & 0x7fffffff))
E 65
	ui = phys(struct uba_device *, udadinfo[unit]);
	if (ui == NULL || ui->ui_alive == 0)
		return (ENXIO);

	/*
	 * Find and initialise the UBA; get the physical address of the
	 * device registers, and of communications area and command and
	 * response packet.
	 */
	uba = phys(struct uba_hd *, ui->ui_hd)->uh_physuba;
	ubainit(uba);
	udaddr = (struct udadevice *)ui->ui_physaddr;
	ud = phys(struct uda1 *, &uda1);

	/*
	 * Map the ca+packets into Unibus I/O space so the UDA50 can get
	 * at them.  Use the registers at the end of the Unibus map (since
	 * we will use the registers at the beginning to map the memory
	 * we are dumping).
	 */
	num = btoc(sizeof(struct uda1)) + 1;
	reg = NUBMREG - num;
	io = &uba->uba_map[reg];
	for (i = 0; i < num; i++)
		*(int *)io++ = UBAMR_MRV | (btop(ud) + i);
	ud_ubaddr = (struct uda1 *)(((int)ud & PGOFSET) | (reg << 9));

	/*
	 * Initialise the controller, with one command and one response
	 * packet.
	 */
	udaddr->udaip = 0;
	if (udadumpwait(udaddr, UDA_STEP1))
		return (EFAULT);
	udaddr->udasa = UDA_ERR;
	if (udadumpwait(udaddr, UDA_STEP2))
		return (EFAULT);
	udaddr->udasa = (int)&ud_ubaddr->uda1_ca.ca_rspdsc;
	if (udadumpwait(udaddr, UDA_STEP3))
		return (EFAULT);
	udaddr->udasa = ((int)&ud_ubaddr->uda1_ca.ca_rspdsc) >> 16;
	if (udadumpwait(udaddr, UDA_STEP4))
		return (EFAULT);
	uda_softc[ui->ui_ctlr].sc_micro = udaddr->udasa & 0xff;
	udaddr->udasa = UDA_GO;

	/*
	 * Set up the command and response descriptor, then set the
	 * controller characteristics and bring the drive on line.
	 * Note that all uninitialised locations in uda1_cmd are zero.
	 */
	ud->uda1_ca.ca_rspdsc = (long)&ud_ubaddr->uda1_rsp.mscp_cmdref;
	ud->uda1_ca.ca_cmddsc = (long)&ud_ubaddr->uda1_cmd.mscp_cmdref;
	/* ud->uda1_cmd.mscp_sccc.sccc_ctlrflags = 0; */
	/* ud->uda1_cmd.mscp_sccc.sccc_version = 0; */
	if (udadumpcmd(M_OP_SETCTLRC, ud, ui))
		return (EFAULT);
	ud->uda1_cmd.mscp_unit = ui->ui_slave;
	if (udadumpcmd(M_OP_ONLINE, ud, ui))
		return (EFAULT);

	pp = phys(struct partition *,
	    &udalabel[unit].d_partitions[udapart(dev)]);
	maxsz = pp->p_size;
	blkoff = pp->p_offset;

	/*
	 * Dump all of physical memory, or as much as will fit in the
	 * space provided.
	 */
	start = 0;
	num = maxfree;
	if (dumplo < 0)
		return (EINVAL);
	if (dumplo + num >= maxsz)
		num = maxsz - dumplo;
	blkoff += dumplo;

	/*
	 * Write out memory, DBSIZE pages at a time.
	 * N.B.: this code depends on the fact that the sector
	 * size == the page size.
	 */
	while (num > 0) {
		blk = num > DBSIZE ? DBSIZE : num;
		io = uba->uba_map;
		/*
		 * Map in the pages to write, leaving an invalid entry
		 * at the end to guard against wild Unibus transfers.
		 * Then do the write.
		 */
		for (i = 0; i < blk; i++)
D 65
			*(int *) io++ = UBAMR_MRV | (btop(start) + i);
		*(int *) io = 0;
E 65
I 65
			*(int *)io++ = UBAMR_MRV | (btop(start) + i);
		*(int *)io = 0;
E 65
		ud->uda1_cmd.mscp_unit = ui->ui_slave;
		ud->uda1_cmd.mscp_seq.seq_lbn = btop(start) + blkoff;
		ud->uda1_cmd.mscp_seq.seq_bytecount = blk << PGSHIFT;
		if (udadumpcmd(M_OP_WRITE, ud, ui))
			return (EIO);
		start += blk << PGSHIFT;
		num -= blk;
	}
	return (0);		/* made it! */
}

/*
 * Wait for some of the bits in `bits' to come on.  If the error bit
 * comes on, or ten seconds pass without response, return true (error).
 */
udadumpwait(udaddr, bits)
	register struct udadevice *udaddr;
	register int bits;
{
	register int timo = todr() + 1000;

	while ((udaddr->udasa & bits) == 0) {
		if (udaddr->udasa & UDA_ERR) {
			printf("udasa=%b\ndump ", udaddr->udasa, udasr_bits);
			return (1);
		}
		if (todr() >= timo) {
			printf("timeout\ndump ");
			return (1);
		}
	}
E 60
	return (0);
}

D 60
udsize(dev)
E 60
I 60
/*
 * Feed a command to the UDA50, wait for its response, and return
 * true iff something went wrong.
 */
udadumpcmd(op, ud, ui)
	int op;
	register struct uda1 *ud;
	struct uba_device *ui;
{
	register struct udadevice *udaddr;
	register int n;
#define mp (&ud->uda1_rsp)

D 65
	udaddr = (struct udadevice *) ui->ui_physaddr;
E 65
I 65
	udaddr = (struct udadevice *)ui->ui_physaddr;
E 65
	ud->uda1_cmd.mscp_opcode = op;
	ud->uda1_cmd.mscp_msglen = MSCP_MSGLEN;
	ud->uda1_rsp.mscp_msglen = MSCP_MSGLEN;
	ud->uda1_ca.ca_rspdsc |= MSCP_OWN | MSCP_INT;
	ud->uda1_ca.ca_cmddsc |= MSCP_OWN | MSCP_INT;
	if (udaddr->udasa & UDA_ERR) {
		printf("udasa=%b\ndump ", udaddr->udasa, udasr_bits);
		return (1);
	}
	n = udaddr->udaip;
	n = todr() + 1000;
	for (;;) {
		if (todr() > n) {
			printf("timeout\ndump ");
			return (1);
		}
		if (ud->uda1_ca.ca_cmdint)
			ud->uda1_ca.ca_cmdint = 0;
		if (ud->uda1_ca.ca_rspint == 0)
			continue;
		ud->uda1_ca.ca_rspint = 0;
		if (mp->mscp_opcode == (op | M_OP_END))
			break;
		printf("\n");
		switch (MSCP_MSGTYPE(mp->mscp_msgtc)) {

		case MSCPT_SEQ:
			printf("sequential");
			break;

		case MSCPT_DATAGRAM:
			mscp_decodeerror("uda", ui->ui_ctlr, mp);
			printf("datagram");
			break;

		case MSCPT_CREDITS:
			printf("credits");
			break;

		case MSCPT_MAINTENANCE:
			printf("maintenance");
			break;

		default:
			printf("unknown (type 0x%x)",
				MSCP_MSGTYPE(mp->mscp_msgtc));
			break;
		}
		printf(" ignored\ndump ");
		ud->uda1_ca.ca_rspdsc |= MSCP_OWN | MSCP_INT;
	}
	if ((mp->mscp_status & M_ST_MASK) != M_ST_SUCCESS) {
		printf("error: op 0x%x => 0x%x status 0x%x\ndump ", op,
			mp->mscp_opcode, mp->mscp_status);
		return (1);
	}
	return (0);
#undef mp
}

/*
 * Return the size of a partition, if known, or -1 if not.
 */
udasize(dev)
E 60
	dev_t dev;
{
D 60
	register int unit = udunit(dev);
E 60
I 60
	register int unit = udaunit(dev);
E 60
	register struct uba_device *ui;
I 60
D 64
	register struct size *st;
E 64
E 60

D 60
	if (unit >= NRA || (ui = uddinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_flags == 0 || ra_info[unit].rastate != OPEN)
E 60
I 60
	if (unit >= NRA || (ui = udadinfo[unit]) == NULL ||
	    ui->ui_alive == 0 || (ui->ui_flags & UNIT_ONLINE) == 0 ||
	    ra_info[unit].ra_state != OPEN)
E 60
E 54
E 29
		return (-1);
D 29
	return (ra_sizes[minor(dev) & 07].nblocks);	/* XXX */
E 29
I 29
D 54
	rasizes = ra_info[ui->ui_unit].ra_sizes;
	return (rasizes[minor(dev) & 07].nblocks);
E 54
I 54
D 60
	return ((int)udlabel[unit].d_partitions[udpart(dev)].p_size);
E 60
I 60
	return ((int)udalabel[unit].d_partitions[udapart(dev)].p_size);
E 60
E 54
E 29
}
I 29

I 54
#ifdef COMPAT_42
I 60
/*
 * Tables mapping unlabelled drives.
 */
E 60
struct size {
	daddr_t nblocks;
	daddr_t blkoff;
D 60
}  ra25_sizes[8] = {
E 60
I 60
D 65
} ra25_sizes[8] = {
E 60
	15884,	0,		/* A=blk 0 thru 15883 */
	10032,	15884,		/* B=blk 15884 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
	0,	0,		/* D=blk 340670 thru 356553 */
	0,	0,		/* E=blk 356554 thru 412489 */
	0,	0,		/* F=blk 412490 thru end */
	-1,	25916,		/* G=blk 49324 thru 131403 */
	0,	0,		/* H=blk 131404 thru end */
I 60
}, rx50_sizes[8] = {
	800,	0,		/* A=blk 0 thru 799 */
	0,	0,
	-1,	0,		/* C=blk 0 thru end */
	0,	0,
	0,	0,
	0,	0,
	0,	0,
	0,	0,
E 60
}, rd52_sizes[8] = {
	15884,	0,		/* A=blk 0 thru 15883 */
	9766,	15884,		/* B=blk 15884 thru 25649 */
	-1,	0,		/* C=blk 0 thru end */
	0,	0,		/* D=unused */
	0,	0,		/* E=unused */
	0,	0,		/* F=unused */
	-1,	25650,		/* G=blk 25650 thru end */
	0,	0,		/* H=unused */
}, rd53_sizes[8] = {
	15884,	0,		/* A=blk 0 thru 15883 */
	33440,	15884,		/* B=blk 15884 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
	0,	0,		/* D=unused */
	33440,	0,		/* E=blk 0 thru 33439 */
	-1,	33440,		/* F=blk 33440 thru end */
	-1,	49324,		/* G=blk 49324 thru end */
	-1,	15884,		/* H=blk 15884 thru end */
}, ra60_sizes[8] = {
E 65
I 65
} ra60_sizes[8] = {
E 65
	15884,	0,		/* A=sectors 0 thru 15883 */
	33440,	15884,		/* B=sectors 15884 thru 49323 */
D 77
	400176,	0,		/* C=sectors 0 thru 400175 */
E 77
I 77
D 81
	-1,	0,		/* C=sectors 0 thru 400175 */
E 81
I 81
	400176,	0,		/* C=sectors 0 thru 400175 */
E 81
E 77
	82080,	49324,		/* 4.2 G => D=sectors 49324 thru 131403 */
D 77
	268772,	131404,		/* 4.2 H => E=sectors 131404 thru 400175 */
	350852,	49324,		/* F=sectors 49324 thru 400175 */
	157570,	242606,		/* UCB G => G=sectors 242606 thru 400175 */
E 77
I 77
D 81
	-1,	131404,		/* 4.2 H => E=sectors 131404 thru 400175 */
	-1,	49324,		/* F=sectors 49324 thru 400175 */
	-1,	242606,		/* UCB G => G=sectors 242606 thru 400175 */
E 81
I 81
	268772,	131404,		/* 4.2 H => E=sectors 131404 thru 400175 */
	350852,	49324,		/* F=sectors 49324 thru 400175 */
	157570,	242606,		/* UCB G => G=sectors 242606 thru 400175 */
E 81
E 77
	193282,	49324,		/* UCB H => H=sectors 49324 thru 242605 */
I 65
}, ra70_sizes[8] = {
D 81
	15884,	0,		/* A=blk 0 thru 15883 */
	33440,	15972,		/* B=blk 15972 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
	15884,	341220,		/* D=blk 341220 thru 357103 */
	55936,	357192,		/* E=blk 357192 thru 413127 */
	-1,	413457,		/* F=blk 413457 thru end */
	-1,	341220,		/* G=blk 341220 thru end */
	291346,	49731,		/* H=blk 49731 thru 341076 */
E 81
I 81
	15884,	0,		/* A=sectors 0 thru 15883 */
	33440,	15972,		/* B=sectors 15972 thru 49411 */
	547041,	0,		/* C=sectors 0 thru 547040 */
	15884,	341220,		/* D=sectors 341220 thru 357103 */
	55936,	357192,		/* E=sectors 357192 thru 413127 */
	133584,	413457,		/* F=sectors 413457 thru 547040 */
	205821,	341220,		/* G=sectors 341220 thru 547040 */
	291346,	49731,		/* H=sectors 49731 thru 341076 */
E 81
I 77
}, ra71_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16422,		/* B=sectors 16422 thru 83301 */
D 81
	-1,	0,		/* C=sectors 0 thru 1367309 */
E 81
I 81
	1367310,0,		/* C=sectors 0 thru 1367309 */
E 81
	15884,	375564,		/* D=sectors 375564 thru 391447 */
	307200,	391986,		/* E=sectors 391986 thru 699185 */
D 81
	-1,	699720,		/* F=sectors 699720 thru 1367309 */
	-1,	375564,		/* G=sectors 375564 thru 1367309 */
E 81
I 81
	667590,	699720,		/* F=sectors 699720 thru 1367309 */
	991746,	375564,		/* G=sectors 375564 thru 1367309 */
E 81
	291346,	83538,		/* H=sectors 83538 thru 374883 */
}, ra72_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16320,		/* B=sectors 16320 thru 83199 */
D 81
	-1,	0,		/* C=sectors 0 thru 1953299 */
E 81
I 81
	1953300,0,		/* C=sectors 0 thru 1953299 */
E 81
	15884,	375360,		/* D=sectors 375360 thru 391243 */
	307200,	391680,		/* E=sectors 391680 thru 698879 */
D 81
	-1,	699720,		/* F=sectors 699720 thru 1953299 */
	-1,	375360,		/* G=sectors 375360 thru 1953299 */
E 81
I 81
	1253580,699720,		/* F=sectors 699720 thru 1953299 */
	1577940,375360,		/* G=sectors 375360 thru 1953299 */
E 81
	291346,	83640,		/* H=sectors 83640 thru 374985 */
I 85
}, ra73_sizes[8] = {
D 87
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16170,		/* B=sectors 16170 thru 83049 */
E 87
I 87
	32768,	0,		/* A=sectors 0 thru 32767 */
	131072,	33810,		/* B=sectors 33810 thru 164881 */
E 87
	3920490,0,		/* C=sectors 0 thru 3920489 */
D 87
	15884,	376320,		/* D=sectors 376320 thru 392203 */
	307200,	392490,		/* E=sectors 392490 thru 699689 */
	3220770,699720,		/* F=sectors 699720 thru 3920489 */
	3544170,376320,		/* G=sectors 376320 thru 3920489 */
	291346,	83790,		/* H=sectors 83790 thru 375135 */
E 87
I 87
	131072,	458640,		/* D=sectors 458640 thru 589711 */
	1638400,590940,		/* E=sectors 590940 thru 2229339 */
	1690500,2229990,	/* F=sectors 2229990 thru 3920489 */
	3461850,458640,		/* G=sectors 458640 thru 3920489 */
	291346,	166110,		/* H=sectors 166110 thru 457455 */
E 87
E 85
E 77
E 65
}, ra80_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	33440,	15884,		/* B=sectors 15884 thru 49323 */
D 77
	242606,	0,		/* C=sectors 0 thru 242605 */
E 77
I 77
D 81
	-1,	0,		/* C=sectors 0 thru 242605 */
E 81
I 81
	242606,	0,		/* C=sectors 0 thru 242605 */
E 81
E 77
	0,	0,		/* D=unused */
D 77
	193282,	49324,		/* UCB H => E=sectors 49324 thru 242605 */
E 77
I 77
D 81
	-1,	49324,		/* UCB H => E=sectors 49324 thru 242605 */
E 81
I 81
	187640,	49324,		/* UCB H => E=sectors 49324 thru 242605 */
E 81
E 77
	82080,	49324,		/* 4.2 G => F=sectors 49324 thru 131403 */
D 77
	192696,	49910,		/* G=sectors 49910 thru 242605 */
	111202,	131404,		/* 4.2 H => H=sectors 131404 thru 242605 */
E 77
I 77
D 81
	-1,	49910,		/* G=sectors 49910 thru 242605 */
	-1,	131404,		/* 4.2 H => H=sectors 131404 thru 242605 */
E 81
I 81
	187054,	49910,		/* G=sectors 49910 thru 242605 */
	105560,	131404,		/* 4.2 H => H=sectors 131404 thru 242605 */
E 81
E 77
}, ra81_sizes[8] ={
I 65
D 73
#ifdef MARYLAND
#ifdef ENEEVAX
	30706,	0,		/* A=cyl    0 thru   42 + 2 sectors */
	40696,	30706,		/* B=cyl   43 thru   99 - 2 sectors */
	-1,	0,		/* C=cyl    0 thru 1247 */
	-1,	71400,		/* D=cyl  100 thru 1247 */

	15884,	0,		/* E=blk      0 thru  15883 */
	33440,	15884,		/* F=blk  15884 thru  49323 */
	82080,	49324,		/* G=blk  49324 thru 131403 */
	-1,	131404,		/* H=blk 131404 thru    end */
#else
	67832,	0,		/* A=cyl    0 thru   94 + 2 sectors */
	67828,	67832,		/* B=cyl   95 thru  189 - 2 sectors */
	-1,	0,		/* C=cyl    0 thru 1247 */
	-1,	135660,		/* D=cyl  190 thru 1247 */
	0,	0,
	0,	0,
	0,	0,
	0,	0,
#endif ENEEVAX
#else
E 73
E 65
/*
 * These are the new standard partition sizes for ra81's.
 * An RA_COMPAT system is compiled with D, E, and F corresponding
 * to the 4.2 partitions for G, H, and F respectively.
 */
#ifndef	UCBRA
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16422,		/* B=sectors 16422 thru 83301 */
D 77
	891072,	0,		/* C=sectors 0 thru 891071 */
E 77
I 77
D 81
	-1,	0,		/* C=sectors 0 thru 891071 */
E 81
I 81
	891072,	0,		/* C=sectors 0 thru 891071 */
E 81
E 77
#ifdef RA_COMPAT
	82080,	49324,		/* 4.2 G => D=sectors 49324 thru 131403 */
D 77
	759668,	131404,		/* 4.2 H => E=sectors 131404 thru 891071 */
	478582,	412490,		/* 4.2 F => F=sectors 412490 thru 891071 */
E 77
I 77
D 81
	-1,	131404,		/* 4.2 H => E=sectors 131404 thru 891071 */
	-1,	412490,		/* 4.2 F => F=sectors 412490 thru 891071 */
E 81
I 81
	759668,	131404,		/* 4.2 H => E=sectors 131404 thru 891071 */
	478582,	412490,		/* 4.2 F => F=sectors 412490 thru 891071 */
E 81
E 77
#else
	15884,	375564,		/* D=sectors 375564 thru 391447 */
	307200,	391986,		/* E=sectors 391986 thru 699185 */
D 77
	191352,	699720,		/* F=sectors 699720 thru 891071 */
E 77
I 77
D 81
	-1,	699720,		/* F=sectors 699720 thru 891071 */
E 81
I 81
	191352,	699720,		/* F=sectors 699720 thru 891071 */
E 81
E 77
#endif RA_COMPAT
D 77
	515508,	375564,		/* G=sectors 375564 thru 891071 */
E 77
I 77
D 81
	-1,	375564,		/* G=sectors 375564 thru 891071 */
E 81
I 81
	515508,	375564,		/* G=sectors 375564 thru 891071 */
E 81
E 77
	291346,	83538,		/* H=sectors 83538 thru 374883 */

/*
 * These partitions correspond to the sizes used by sites at Berkeley,
 * and by those sites that have received copies of the Berkeley driver
 * with deltas 6.2 or greater (11/15/83).
 */
#else UCBRA

	15884,	0,		/* A=sectors 0 thru 15883 */
	33440,	15884,		/* B=sectors 15884 thru 49323 */
D 77
	891072,	0,		/* C=sectors 0 thru 891071 */
E 77
I 77
D 81
	-1,	0,		/* C=sectors 0 thru 891071 */
E 81
I 81
	891072,	0,		/* C=sectors 0 thru 891071 */
E 81
E 77
	15884,	242606,		/* D=sectors 242606 thru 258489 */
	307200,	258490,		/* E=sectors 258490 thru 565689 */
D 77
	325382,	565690,		/* F=sectors 565690 thru 891071 */
	648466,	242606,		/* G=sectors 242606 thru 891071 */
E 77
I 77
D 81
	-1,	565690,		/* F=sectors 565690 thru 891071 */
	-1,	242606,		/* G=sectors 242606 thru 891071 */
E 81
I 81
	325382,	565690,		/* F=sectors 565690 thru 891071 */
	648466,	242606,		/* G=sectors 242606 thru 891071 */
E 81
E 77
	193282,	49324,		/* H=sectors 49324 thru 242605 */

#endif UCBRA
I 65
D 73
#endif MARYLAND
E 73
}, ra82_sizes[8] = {
D 81
	15884,	0,		/* A=blk 0 thru 15883 */
	66880,	16245,		/* B=blk 16245 thru 83124 */
	-1,	0,		/* C=blk 0 thru end */
	15884,	375345,		/* D=blk 375345 thru 391228 */
	307200,	391590,		/* E=blk 391590 thru 698789 */
	-1,	699390,		/* F=blk 699390 thru end */
	-1,	375345,		/* G=blk 375345 thru end */
	291346,	83790,		/* H=blk 83790 thru 375135 */
E 81
I 81
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16245,		/* B=sectors 16245 thru 83124 */
	1216665,0,		/* C=sectors 0 thru 1216664 */
	15884,	375345,		/* D=sectors 375345 thru 391228 */
	307200,	391590,		/* E=sectors 391590 thru 698789 */
	517275,	699390,		/* F=sectors 699390 thru 1216664 */
	841320,	375345,		/* G=sectors 375345 thru 1216664 */
	291346,	83790,		/* H=sectors 83790 thru 375135 */
E 81
I 77
}, ra90_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16146,		/* B=sectors 16146 thru 83025 */
D 81
	-1,	0,		/* C=sectors 0 thru 2376152 */
E 81
I 81
	2376153,0,		/* C=sectors 0 thru 2376152 */
E 81
	15884,	374946,		/* D=sectors 374946 thru 390829 */
	307200,	391092,		/* E=sectors 391092 thru 698291 */
D 81
	-1,	698763,		/* F=sectors 698763 thru 2376152 */
	-1,	374946,		/* G=sectors 374946 thru 2376152 */
E 81
I 81
	1677390,698763,		/* F=sectors 698763 thru 2376152 */
	2001207,374946,		/* G=sectors 374946 thru 2376152 */
E 81
	291346,	83421,		/* H=sectors 83421 thru 374766 */
}, ra92_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16146,		/* B=sectors 16146 thru 83025 */
D 78
	-1,	0,		/* C=sectors 0 thru 2941262 */
E 78
I 78
D 81
	-1,	0,		/* C=sectors 0 thru 2940950 */
E 81
I 81
	2940951,0,		/* C=sectors 0 thru 2940950 */
E 81
E 78
	15884,	374946,		/* D=sectors 374946 thru 390829 */
	307200,	391092,		/* E=sectors 391092 thru 698291 */
D 78
	-1,	698763,		/* F=sectors 698763 thru 2941262 */
	-1,	374946,		/* G=sectors 374946 thru 2941262 */
E 78
I 78
D 81
	-1,	698763,		/* F=sectors 698763 thru 2940950 */
	-1,	374946,		/* G=sectors 374946 thru 2940950 */
E 81
I 81
	2242188,698763,		/* F=sectors 698763 thru 2940950 */
	2566005,374946,		/* G=sectors 374946 thru 2940950 */
E 81
E 78
	291346,	83421,		/* H=sectors 83421 thru 374766 */
I 84
}, rf30_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	33440,	15984,		/* B=sectors 15984 thru 49423 */
	293040,	0,		/* C=sectors 0 thru 293039 */
	15884,	49506,		/* D=sectors 49506 thru 65389 */
	55936,	65490,		/* E=sectors 65490 thru 121425 */
	171606,	121434,		/* F=sectors 121434 thru 293039 */
	243534,	49506,		/* G=sectors 49506 thru 293039 */
	0,	0,
}, rf31_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16000,		/* B=sectors 16000 thru 82879 */
	744400,	0,		/* C=sectors 0 thru 744399 */
	15884,	374800,		/* D=sectors 374800 thru 390683 */
	307200,	390800,		/* E=sectors 390800 thru 697999 */
	46400,	698000,		/* F=sectors 698000 thru 744399 */
	369600,	374800,		/* G=sectors 374800 thru 744399 */
	291346,	83200,		/* H=sectors 83200 thru 374545 */
I 87
}, rf35_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	15960,		/* B=sectors 15960 thru 82839 */
	1664628,0,		/* C=sectors 0 thru 1664627 */
	15884,	375060,		/* D=sectors 375060 thru 390943 */
	307200,	391020,		/* E=sectors 391020 thru 698219 */
	966378,	698250,		/* F=sectors 698250 thru 1664627 */
	1289568,375060,		/* G=sectors 375060 thru 1664627 */
	291346,	82992,		/* H=sectors 82992 thru 374337 */
}, rf36_sizes[8] = {
	32768,	0,		/* A=sectors 0 thru 32767 */
	131072,	32768,		/* B=sectors 32768 thru 163839 */
	3125408,0,		/* C=sectors 0 thru 3125407 */
	131072,	455186,		/* D=sectors 455186 thru 586257 */
	1638400,586258,		/* E=sectors 586258 thru 2224657 */
	900750,	2224658,	/* F=sectors 2224658 thru 3125407 */
	2670222,455186,		/* G=sectors 455186 thru 3125407 */
	291346,	163840,		/* H=sectors 163840 thru 455185 */
E 87
}, rf71_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	15984,		/* B=sectors 15984 thru 82863 */
	781440,	0,		/* C=sectors 0 thru 781439 */
	15884,	374736,		/* D=sectors 374736 thru 390619 */
	307200,	390720,		/* E=sectors 390720 thru 697919 */
	83472,	697968,		/* F=sectors 697968 thru 781439 */
	406704,	374736,		/* G=sectors 374736 thru 781439 */
	291346,	82880,		/* H=sectors 82880 thru 374225 */
}, rf72_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	66880,	16800,		/* B=sectors 16800 thru 83679 */
	1954050,0,		/* C=sectors 0 thru 1954049 */
	15884,	375900,		/* D=sectors 375900 thru 391783 */
	307200,	392700,		/* E=sectors 392700 thru 699899 */
	1253700,700350,		/* F=sectors 700350 thru 1954049 */
	1578150,375900,		/* G=sectors 375900 thru 1954049 */
	291346,	84000,		/* H=sectors 84000 thru 375345 */
I 87
}, rf74_sizes[8] = {
	32768,	0,		/* A=sectors 0 thru 32767 */
	131072,	32768,		/* B=sectors 32768 thru 163839 */
	6976375,0,		/* C=sectors 0 thru 6976374 */
	131072,	455186,		/* D=sectors 455186 thru 586257 */
	3276800,586258,		/* E=sectors 586258 thru 3863057 */
	3113317,3863058,	/* F=sectors 3863058 thru 6976374 */
	6521189,455186,		/* G=sectors 455186 thru 6976374 */
	291346,	163840,		/* H=sectors 163840 thru 455185 */
E 87
E 84
E 77
}, rc25_sizes[8] = {
	15884,	0,		/* A=blk 0 thru 15883 */
D 81
	10032,	15884,		/* B=blk 15884 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
	0,	0,		/* D=blk 340670 thru 356553 */
	0,	0,		/* E=blk 356554 thru 412489 */
	0,	0,		/* F=blk 412490 thru end */
	-1,	25916,		/* G=blk 49324 thru 131403 */
	0,	0,		/* H=blk 131404 thru end */
E 81
I 81
	10032,	15884,		/* B=blk 15884 thru 25915 */
	50736,	0,		/* C=blk 0 thru 50735 */
	0,	0,
	0,	0,
	0,	0,
	24820,	25916,		/* G=blk 25916 thru 50735 */
	0,	0,
I 86
}, rd52_sizes[8] = {
	15884,	0,		/* A=blk 0 thru 15883 */
	9766,	15884,		/* B=blk 15884 thru 25649 */
	60480,	0,		/* C=blk 0 thru 60479 */
	0,	0,		/* D=unused */
	0,	0,		/* E=unused */
	0,	0,		/* F=unused */
	34830,	25650,		/* G=blk 25650 thru 60479 */
	0,	0,		/* H=unused */
}, rd53_sizes[8] = {
	15884,	0,		/* A=blk 0 thru 15883 */
	33440,	15884,		/* B=blk 15884 thru 49323 */
	138672,	0,		/* C=blk 0 thru 138671 */
	0,	0,		/* D=unused */
	33440,	0,		/* E=blk 0 thru 33439 */
	105232,	33440,		/* F=blk 33440 thru 138671 */
	89348,	49324,		/* G=blk 49324 thru 138671 */
	122788,	15884,		/* H=blk 15884 thru 138671 */
}, rd54_sizes[8] = {
	15884,	0,		/* A=sectors 0 thru 15883 */
	33440,	16065,		/* B=sectors 16065 thru 49504 */
	311200,	0,		/* C=sectors 0 thru 311199 */
	15884,	49725,		/* D=sectors 49725 thru 65608 */
	55936,	65790,		/* E=sectors 65790 thru 121725 */
	189310,	121890,		/* F=sectors 121890 thru 311199 */
	261475,	49725,		/* G=sectors 49725 thru 311199 */
	0,	0,
E 86
E 81
D 80
}, rd52_sizes[8] = {
	15884,	0,		/* A=blk 0 thru 15883 */
	9766,	15884,		/* B=blk 15884 thru 25649 */
	-1,	0,		/* C=blk 0 thru end */
	0,	0,		/* D=unused */
	0,	0,		/* E=unused */
	0,	0,		/* F=unused */
	-1,	25650,		/* G=blk 25650 thru end */
	0,	0,		/* H=unused */
}, rd53_sizes[8] = {
	15884,	0,		/* A=blk 0 thru 15883 */
	33440,	15884,		/* B=blk 15884 thru 49323 */
	-1,	0,		/* C=blk 0 thru end */
	0,	0,		/* D=unused */
	33440,	0,		/* E=blk 0 thru 33439 */
	-1,	33440,		/* F=blk 33440 thru end */
	-1,	49324,		/* G=blk 49324 thru end */
	-1,	15884,		/* H=blk 15884 thru end */
E 80
}, rx50_sizes[8] = {
	800,	0,		/* A=blk 0 thru 799 */
	0,	0,
D 81
	-1,	0,		/* C=blk 0 thru end */
E 81
I 81
	800,	0,		/* C=blk 0 thru 799 */
E 81
	0,	0,
	0,	0,
	0,	0,
	0,	0,
	0,	0,
E 65
};

D 60
udmaptype(unit, lp)
	register unit;
E 60
I 60
/*
D 65
 * Drive type index decoding table.  `ut_name' is null iff the
 * type is not known.
E 65
I 65
 * Media ID decoding table.
E 65
 */
struct	udatypes {
I 65
	u_long	ut_id;		/* media drive ID */
E 65
	char	*ut_name;	/* drive type name */
	struct	size *ut_sizes;	/* partition tables */
D 81
	int	ut_nsectors, ut_ntracks, ut_ncylinders;
E 81
} udatypes[] = {
D 65
	NULL,		NULL,
		0, 0, 0,
	"ra80",		ra80_sizes,	/* 1 = ra80 */
		31, 14, 559,
	"rc25-removable", ra25_sizes,	/* 2 = rc25-r */
		42, 4, 302,
	"rc25-fixed",	ra25_sizes,	/* 3 = rc25-f */
		42, 4, 302,
	"ra60",		ra60_sizes,	/* 4 = ra60 */
		42, 4, 2382,
	"ra81",		ra81_sizes,	/* 5 = ra81 */
		51, 14, 1248,
	NULL,		NULL,		/* 6 = ? */
		0, 0, 0,
	"rx50",		rx50_sizes,	/* 7 = rx50 */
		10, 1, 80,
	"rd52",		rd52_sizes,	/* 8 = rd52 */
		18, 7, 480,
	"rd53",		rd53_sizes,	/* 9 = rd53 */
		18, 8, 963,
E 65
I 65
D 81
	{ MSCP_MKDRIVE2('R', 'A', 60), "ra60", ra60_sizes, 42, 4, 2382 },
	{ MSCP_MKDRIVE2('R', 'A', 70), "ra70", ra70_sizes, 33, 11, 1507 },
I 77
	{ MSCP_MKDRIVE2('R', 'A', 71), "ra71", ra71_sizes, 51, 14, 1915 },
	{ MSCP_MKDRIVE2('R', 'A', 72), "ra72", ra72_sizes, 51, 20, 1915 },
E 77
	{ MSCP_MKDRIVE2('R', 'A', 80), "ra80", ra80_sizes, 31, 14, 559 },
	{ MSCP_MKDRIVE2('R', 'A', 81), "ra81", ra81_sizes, 51, 14, 1248 },
	{ MSCP_MKDRIVE2('R', 'A', 82), "ra82", ra82_sizes, 57, 14, 1423 },
I 77
	{ MSCP_MKDRIVE2('R', 'A', 90), "ra90", ra90_sizes, 69, 13, 2649 },
	{ MSCP_MKDRIVE2('R', 'A', 92), "ra92", ra92_sizes, 69, 13, 3279 },
E 77
	{ MSCP_MKDRIVE2('R', 'C', 25), "rc25-removable",
						rc25_sizes, 42, 4, 302 },
	{ MSCP_MKDRIVE3('R', 'C', 'F', 25), "rc25-fixed",
						rc25_sizes, 42, 4, 302 },
D 80
	{ MSCP_MKDRIVE2('R', 'D', 52), "rd52", rd52_sizes, 18, 7, 480 },
	{ MSCP_MKDRIVE2('R', 'D', 53), "rd53", rd53_sizes, 18, 8, 963 },
E 80
	{ MSCP_MKDRIVE2('R', 'X', 50), "rx50", rx50_sizes, 10, 1, 80 },
E 81
I 81
	{ MSCP_MKDRIVE2('R', 'A', 60), "ra60", ra60_sizes },
	{ MSCP_MKDRIVE2('R', 'A', 70), "ra70", ra70_sizes },
	{ MSCP_MKDRIVE2('R', 'A', 71), "ra71", ra71_sizes },
	{ MSCP_MKDRIVE2('R', 'A', 72), "ra72", ra72_sizes },
I 85
	{ MSCP_MKDRIVE2('R', 'A', 73), "ra73", ra73_sizes },
E 85
	{ MSCP_MKDRIVE2('R', 'A', 80), "ra80", ra80_sizes },
	{ MSCP_MKDRIVE2('R', 'A', 81), "ra81", ra81_sizes },
	{ MSCP_MKDRIVE2('R', 'A', 82), "ra82", ra82_sizes },
	{ MSCP_MKDRIVE2('R', 'A', 90), "ra90", ra90_sizes },
	{ MSCP_MKDRIVE2('R', 'A', 92), "ra92", ra92_sizes },
I 84
	{ MSCP_MKDRIVE2('R', 'F', 30), "rf30", rf30_sizes },
	{ MSCP_MKDRIVE2('R', 'F', 31), "rf31", rf31_sizes },
I 87
	{ MSCP_MKDRIVE2('R', 'F', 35), "rf35", rf35_sizes },
	{ MSCP_MKDRIVE2('R', 'F', 36), "rf36", rf36_sizes },
E 87
	{ MSCP_MKDRIVE2('R', 'F', 71), "rf71", rf71_sizes },
	{ MSCP_MKDRIVE2('R', 'F', 72), "rf72", rf72_sizes },
I 85
	{ MSCP_MKDRIVE2('R', 'F', 73), "rf73", ra73_sizes },
I 87
	{ MSCP_MKDRIVE2('R', 'F', 74), "rf74", rf74_sizes },
E 87
E 85
E 84
	{ MSCP_MKDRIVE2('R', 'C', 25), "rc25-removable", rc25_sizes },
	{ MSCP_MKDRIVE3('R', 'C', 'F', 25), "rc25-fixed", rc25_sizes },
I 86
	{ MSCP_MKDRIVE2('R', 'D', 52), "rd52", rd52_sizes },
	{ MSCP_MKDRIVE2('R', 'D', 53), "rd53", rd53_sizes },
	{ MSCP_MKDRIVE2('R', 'D', 54), "rd54", rd54_sizes },
E 86
	{ MSCP_MKDRIVE2('R', 'X', 50), "rx50", rx50_sizes },
E 81
	0
E 65
};

#define NTYPES (sizeof(udatypes) / sizeof(*udatypes))

udamaptype(unit, lp)
	int unit;
E 60
	register struct disklabel *lp;
{
D 60
	register struct size *rasizes;
E 60
I 60
	register struct udatypes *ut;
	register struct size *sz;
E 60
	register struct partition *pp;
D 60
	register type;
E 60
I 60
	register char *p;
	register int i;
	register struct ra_info *ra = &ra_info[unit];
E 60

D 60
	lp->d_secperunit = ra_info[unit].radsize;
	type = ra_info[unit].ratype & 0x7f;
	lp->d_typename[0] = 'r';
	lp->d_typename[1] = 'a';
	lp->d_typename[2] = '0' + type/10;
	lp->d_typename[3] = '0' + type%10;
	switch (type) {
	case    25:
		rasizes = ra25_sizes;
		lp->d_nsectors = 42;
		lp->d_ntracks = 4;
		lp->d_ncylinders = 302;
		break;
	case    52:
		lp->d_typename[1] = 'd';
		rasizes = rd52_sizes;
		lp->d_nsectors = 18;
		lp->d_ntracks = 7;
		lp->d_ncylinders = 480;
		break;
	case    53:
		rasizes = rd53_sizes;
		lp->d_typename[1] = 'd';
		lp->d_nsectors = 18;
		lp->d_ntracks = 8;
		lp->d_ncylinders = 963;
		break;
	case    60:
		rasizes = ra60_sizes;
		lp->d_nsectors = 42;
		lp->d_ntracks = 4;
		lp->d_ncylinders = 2382;
		break;
	case    80:
		rasizes = ra80_sizes;
		lp->d_nsectors = 31;
		lp->d_ntracks = 14;
		lp->d_ncylinders = 559;
		break;
	case    81:
		rasizes = ra81_sizes;
		lp->d_nsectors = 51;
		lp->d_ntracks = 14;
		lp->d_ncylinders = 1248;
		break;
	default:
		printf("Don't have a partition table for an ra%d\n", type);
E 60
I 60
D 73
	lp->d_secsize = 512;
	lp->d_secperunit = ra->ra_dsize;
E 73
D 65
	if ((u_long)ra->ra_type >= NTYPES) {
		printf("ra%d: don't have a partition table for", unit);
		mscp_printmedia(ra->ra_mediaid);
		lp->d_nsectors = ra->ra_geom.rg_nsectors;
		lp->d_ntracks = ra->ra_geom.rg_ntracks;
		lp->d_ncylinders = ra->ra_geom.rg_ncyl;
		printf(";\nusing (t,s,c)=(%d,%d,%d)\n", lp->d_nsectors,
			lp->d_ntracks, lp->d_ncylinders);
		lp->d_secpercyl = lp->d_nsectors * lp->d_ntracks;
		lp->d_typename[0] = 'r';
		lp->d_typename[1] = 'a';
		lp->d_typename[2] = '?';
		lp->d_typename[3] = '?';
		lp->d_typename[4] = 0;
E 60
		lp->d_npartitions = 1;
		lp->d_partitions[0].p_offset = 0;
		lp->d_partitions[0].p_size = lp->d_secperunit;
		return (0);
	}
I 55
D 60
	lp->d_secsize = 512;
E 60
I 60
	ut = &udatypes[ra->ra_type];
E 65
I 65
	i = MSCP_MEDIA_DRIVE(ra->ra_mediaid);
	for (ut = udatypes; ut->ut_id; ut++)
D 73
		if (ut->ut_id == i)
E 73
I 73
		if (ut->ut_id == i &&
D 81
		    ut->ut_nsectors == ra->ra_geom.rg_nsectors &&
		    ut->ut_ntracks == ra->ra_geom.rg_ntracks &&
		    ut->ut_ncylinders == ra->ra_geom.rg_ncyl)
E 81
I 81
		    ut->ut_sizes[2].nblocks == ra->ra_dsize)
E 81
E 73
			goto found;

	/* not one we know; fake up a label for the whole drive */
D 73
	lp->d_nsectors = ra->ra_geom.rg_nsectors;
	lp->d_ntracks = ra->ra_geom.rg_ntracks;
	lp->d_ncylinders = ra->ra_geom.rg_ncyl;
E 73
I 73
	uda_makefakelabel(ra, lp);
E 73
	i = ra->ra_mediaid;	/* print the port type too */
D 66
	printf("ra%d: don't have a partition table for %c%c %c%c%c%d;\n\
using (s,t,c)=(%d,%d,%d)\n",
		unit, MSCP_MID_CHAR(4, i), MSCP_MID_CHAR(3, i),
E 66
I 66
D 73
	if (!cold)
		log(LOG_ERR, "ra%d", unit);
	addlog(": don't have a partition table for %c%c %c%c%c%d;\n\
E 73
I 73
	addlog(": no partition table for %c%c %c%c%c%d, size %d;\n\
E 73
using (s,t,c)=(%d,%d,%d)",
		MSCP_MID_CHAR(4, i), MSCP_MID_CHAR(3, i),
E 66
		MSCP_MID_CHAR(2, i), MSCP_MID_CHAR(1, i),
D 73
		MSCP_MID_CHAR(0, i), MSCP_MID_CHAR(0, i),
		MSCP_MID_NUM(i), lp->d_nsectors,
		lp->d_ntracks, lp->d_ncylinders);
E 73
I 73
		MSCP_MID_CHAR(0, i), MSCP_MID_NUM(i), lp->d_secperunit,
		lp->d_nsectors, lp->d_ntracks, lp->d_ncylinders);
E 73
I 66
	if (!cold)
		addlog("\n");
E 66
D 73
	lp->d_secpercyl = lp->d_nsectors * lp->d_ntracks;
	lp->d_typename[0] = 'r';
	lp->d_typename[1] = 'a';
	lp->d_typename[2] = '?';
	lp->d_typename[3] = '?';
	lp->d_typename[4] = 0;
	lp->d_npartitions = 1;
	lp->d_partitions[0].p_offset = 0;
	lp->d_partitions[0].p_size = lp->d_secperunit;
E 73
	return (0);
found:
E 65
	p = ut->ut_name;
	for (i = 0; i < sizeof(lp->d_typename) - 1 && *p; i++)
		lp->d_typename[i] = *p++;
	lp->d_typename[i] = 0;
	sz = ut->ut_sizes;
D 73
	/* GET nsectors, ntracks, ncylinders FROM SAVED GEOMETRY? */
E 73
D 81
	lp->d_nsectors = ut->ut_nsectors;
	lp->d_ntracks = ut->ut_ntracks;
	lp->d_ncylinders = ut->ut_ncylinders;
E 81
I 81
	lp->d_nsectors = ra->ra_geom.rg_nsectors;
	lp->d_ntracks = ra->ra_geom.rg_ntracks;
	lp->d_ncylinders = ra->ra_geom.rg_ncyl;
E 81
E 60
E 55
	lp->d_npartitions = 8;
	lp->d_secpercyl = lp->d_nsectors * lp->d_ntracks;
D 60
	for (pp = lp->d_partitions; pp < &lp->d_partitions[8];
	    pp++, rasizes++) {
		pp->p_offset = rasizes->blkoff;
		if ((pp->p_size = rasizes->nblocks) == (u_long)-1)
			pp->p_size = ra_info[unit].radsize - rasizes->blkoff;
E 60
I 60
	for (pp = lp->d_partitions; pp < &lp->d_partitions[8]; pp++, sz++) {
		pp->p_offset = sz->blkoff;
		if ((pp->p_size = sz->nblocks) == (u_long)-1)
			pp->p_size = ra->ra_dsize - sz->blkoff;
E 60
	}
	return (1);
}
D 60
#endif COMPAT_42
E 54
E 29
#endif
E 60
I 60
#endif /* COMPAT_42 */
I 73

/*
 * Construct a label for a drive from geometry information
 * if we have no better information.
 */
uda_makefakelabel(ra, lp)
	register struct ra_info *ra;
	register struct disklabel *lp;
{
	lp->d_nsectors = ra->ra_geom.rg_nsectors;
	lp->d_ntracks = ra->ra_geom.rg_ntracks;
	lp->d_ncylinders = ra->ra_geom.rg_ncyl;
	lp->d_secpercyl = lp->d_nsectors * lp->d_ntracks;
	bcopy("ra??", lp->d_typename, sizeof("ra??"));
	lp->d_npartitions = 1;
	lp->d_partitions[0].p_offset = 0;
	lp->d_partitions[0].p_size = lp->d_secperunit;
}
E 73
#endif /* NUDA > 0 */
E 60
E 24
E 1
