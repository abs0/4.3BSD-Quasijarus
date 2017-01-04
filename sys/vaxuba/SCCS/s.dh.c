h20747
s 00033/00005/00780
d D 7.9 04/12/09 23:50:00 msokolov 105 104
c implemented TIOCM{SET,BIS,BIC,GET} ioctls
c support for selecting for modem status change
e
s 00001/00001/00784
d D 7.8 03/03/16 04:03:04 msokolov 104 103
c Don't interpret output high chars as delays in PASS8 mode
e
s 00003/00003/00782
d D 7.7 02/07/30 23:44:46 msokolov 103 102
c finally support FNDELAY on open
e
s 00001/00001/00784
d D 7.6 89/01/24 17:23:55 bostic 102 101
c typo in attach routines; bug report 4.3BSD-tahoe/sys/34
e
s 00000/00001/00785
d D 7.5 87/03/12 17:04:51 karels 101 100
c typo
e
s 00002/00001/00784
d D 7.4 86/12/30 12:25:37 karels 100 99
c typo
e
s 00012/00009/00773
d D 7.3 86/12/22 15:18:15 karels 99 98
c race in dmopen; bug report 4.3BSD/sys/78
e
s 00020/00011/00762
d D 7.2 86/12/19 11:46:22 karels 98 97
c correct uba reallocation on reset
e
s 00001/00001/00772
d D 7.1 86/06/05 01:05:46 mckusick 97 96
c 4.3BSD release version
e
s 00001/00000/00772
d D 6.17 86/05/14 15:34:13 karels 96 95
c missing splx
e
s 00012/00004/00760
d D 6.16 86/04/12 14:10:28 karels 95 94
c revert to "sticky" baudrate except for portselector
e
s 00005/00004/00759
d D 6.15 86/02/17 22:58:02 karels 94 93
c correct uba allocation after reset
e
s 00000/00000/00763
d D 6.14 85/11/22 06:39:25 tef 93 92
c standard list of device addresses must be null terminated.
e
s 00007/00008/00756
d D 6.13 85/11/08 19:08:03 karels 92 91
c share unibus resources between multiplexor types
e
s 00013/00039/00751
d D 6.12 85/11/04 18:18:03 karels 91 90
c move carrier change code to line disciplines; make PORTSELECTOR
c code and configuration consistent; change default speed to 9600
e
s 00001/00001/00789
d D 6.11 85/09/17 18:33:16 eric 90 89
c facilities in syslog
e
s 00001/00001/00789
d D 6.10 85/08/13 05:09:27 lepreau 89 88
c add PASS8: pass all 8 bits of input
e
s 00007/00001/00783
d D 6.9 85/06/08 14:13:49 mckusick 88 87
c Add copyright
e
s 00009/00007/00775
d D 6.8 85/06/04 11:58:24 karels 87 86
c cleanup carrier-drop code
e
s 00002/00001/00780
d D 6.7 85/03/12 14:21:29 ralph 86 85
c change silo overflow printf's to log's.
e
s 00002/00001/00779
d D 6.6 84/12/20 15:54:21 bloom 85 84
c call param routine when ioctls change hardware configuration
e
s 00019/00019/00761
d D 6.5 84/08/30 11:41:28 bloom 84 83
c changes to includes.  no more ../h
e
s 00007/00005/00773
d D 6.4 84/08/15 11:55:51 karels 83 82
c set DTR, etc, even if flags are on
e
s 00053/00011/00725
d D 6.3 84/03/15 14:43:19 karels 82 81
c use silos only when input rate is high
e
s 00003/00002/00733
d D 6.2 84/02/16 12:48:38 karels 81 80
c replace MAXNUBA by NUBA
e
s 00000/00000/00735
d D 6.1 83/07/29 07:27:00 sam 80 79
c 4.2 distribution
e
s 00001/00001/00734
d D 4.58 83/05/27 13:51:47 sam 79 78
c lint
e
s 00002/00078/00733
d D 4.57 82/12/30 14:10:26 sam 78 77
c yank definitions out
e
s 00002/00001/00809
d D 4.56 82/12/17 12:01:16 sam 77 76
c sun merge
e
s 00002/00002/00808
d D 4.55 82/12/10 16:36:29 sam 76 75
c name conflicts
e
s 00007/00006/00803
d D 4.54 82/12/05 21:47:19 sam 75 74
c reorganized tty structuer
e
s 00017/00017/00792
d D 4.53 82/10/17 11:48:07 root 74 73
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00003/00005/00806
d D 4.52 82/10/10 22:37:19 root 73 72
c minor fixes relating to u.u_error handling
e
s 00004/00002/00807
d D 4.51 82/10/10 17:26:19 root 72 71
c header files for vax are in their place
e
s 00002/00000/00807
d D 4.50 82/09/12 03:06:16 root 71 70
c physio returns error, not in u.u_error
e
s 00003/00002/00804
d D 4.49 82/08/22 21:16:49 root 70 69
c fully uio()'d
e
s 00004/00002/00802
d D 4.48 82/08/13 00:14:45 root 69 68
c changes for char dev uio'ing
e
s 00010/00005/00794
d D 4.47 82/08/01 19:24:21 sam 68 67
c new ioctl's
e
s 00001/00001/00798
d D 4.46 82/07/15 19:58:13 kre 67 66
c probe routines return size of unibus dev regs to reserve space
e
s 00002/00000/00797
d D 4.45 82/07/13 18:26:21 root 66 65
c bug fixes from ucla
e
s 00019/00003/00778
d D 4.44 82/05/04 13:37:56 sam 65 64
c CAD kludges and cleanup conf.c
e
s 00001/00001/00780
d D 4.43 82/03/31 09:05:23 wnj 64 63
c DELAY(25) --> DELAY(1000) per kridle for cs11
e
s 00002/00001/00779
d D 4.42 82/03/14 17:54:32 sam 63 62
c lint
e
s 00037/00030/00743
d D 4.41 82/01/14 17:05:05 wnj 62 61
c early non-blocking stuff
e
s 00002/00000/00771
d D 4.40 81/11/18 15:48:56 wnj 61 60
c lint
e
s 00001/00006/00770
d D 4.39 81/11/08 17:12:59 wnj 60 58
c restore berknet
e
s 00000/00010/00766
d R 4.39 81/10/11 11:47:38 wnj 59 58
c first boot with select()
e
s 00000/00008/00776
d D 4.38 81/08/31 01:15:37 root 58 57
c fix to silo and bk bug
e
s 00025/00023/00759
d D 4.37 81/07/10 10:14:13 root 57 56
c fix per sam leffler
e
s 00002/00000/00780
d D 4.36 81/06/05 11:35:53 wnj 56 55
c 
e
s 00002/00000/00778
d D 4.35 81/06/02 16:25:02 wnj 55 54
c fix to silo handling when NBK == 0
e
s 00007/00006/00771
d D 4.34 81/05/18 01:46:54 wnj 54 53
c fixes per mo
e
s 00001/00001/00776
d D 4.33 81/05/09 19:46:44 root 53 52
c llitout bug fix
e
s 00009/00003/00768
d D 4.32 81/04/22 14:31:22 root 52 49
c fix bug to fix bug in compiler bug in dh bug
e
s 00001/00001/00795
d R 4.33 81/04/09 15:13:59 root 51 50
c restore sccs line
e
s 00026/00001/00770
d R 4.32 81/04/09 15:10:40 root 50 49
c debugging code for NXM problem added
e
s 00005/00001/00766
d D 4.31 81/04/02 15:12:32 root 49 48
c conditional silos on NBK
e
s 00000/00000/00767
d D 4.30 81/03/09 01:52:35 wnj 48 47
c %G% -> %E%
e
s 00004/00005/00763
d D 4.29 81/03/09 00:33:05 wnj 47 46
c lint
e
s 00013/00012/00755
d D 4.28 81/03/07 14:27:07 wnj 46 45
c after attempt at ht driver at cc again; working with new 
c field names
e
s 00007/00004/00760
d D 4.27 81/03/06 11:30:54 wnj 45 44
c cleaner silo overrun prints; print unit number when reset
e
s 00002/00002/00762
d D 4.26 81/02/27 17:49:04 wnj 44 43
c system sized at boot version
e
s 00003/00000/00761
d D 4.25 81/02/26 22:19:44 wnj 43 42
c conditionally discard NETLDISC cruft
e
s 00001/00007/00760
d D 4.24 81/02/26 00:17:58 wnj 42 41
c eliminate delays which were for old emulex ucode only
e
s 00011/00011/00756
d D 4.23 81/02/23 23:44:02 wnj 41 40
c minor typos
e
s 00001/00000/00766
d D 4.22 81/02/23 20:13:49 wnj 40 39
c #endif
e
s 00001/00001/00765
d D 4.21 81/02/22 21:46:03 wnj 39 38
c working interlocked system
e
s 00022/00022/00744
d D 4.20 81/02/21 21:20:14 wnj 38 37
c first working uba interlockable version
e
s 00015/00012/00751
d D 4.19 81/02/19 21:57:21 wnj 37 36
c almost working ubago version (tm.c problems)
e
s 00007/00000/00756
d D 4.18 81/02/18 17:52:52 wnj 36 35
c add (not yet working on emulex) simpler debugging code
e
s 00149/00122/00607
d D 4.17 81/02/18 16:14:21 wnj 35 34
c working dm code
e
s 00275/00080/00454
d D 4.16 81/02/17 17:33:10 wnj 34 33
c minor cleanups... for dh: DELAY(5)s
e
s 00095/00109/00439
d D 4.15 81/02/16 20:55:28 wnj 33 32
c cleanup with new soft interrupts and new ctlr scheme
e
s 00043/00036/00505
d D 4.14 81/02/15 12:08:58 kre 32 31
c bootable autoconf version
e
s 00159/00134/00382
d D 4.13 81/02/10 13:19:16 wnj 31 30
c compilable first uba autoconf version
e
s 00001/00001/00515
d D 4.12 81/01/29 09:16:12 kre 30 29
c typo
e
s 00001/00001/00515
d D 4.11 81/01/28 11:42:09 wnj 29 28
c 8 bits both in raw and litout
e
s 00001/00001/00515
d D 4.10 81/01/26 21:19:01 toy 28 27
c Changed param routine to set BITS8 if LLITOUT is set
e
s 00005/00000/00511
d D 4.9 81/01/19 15:55:53 toy 27 26
c Added reset of TIOCSBRK in dhclose.  (MCT)
e
s 00001/00001/00510
d D 4.8 80/12/30 18:51:08 wnj 26 25
c ubafree() becomes ubarelse() to fix race conditions
e
s 00001/00001/00510
d D 4.7 80/12/30 18:18:25 wnj 25 24
c fix ubafree(i), i = 0 to be UBAFREECLR(i) to avoid races
e
s 00005/00000/00506
d D 4.6 80/12/19 14:45:49 wnj 24 23
c arrange for dhfdm to be #included
e
s 00001/00001/00505
d D 4.5 80/12/19 11:43:28 wnj 23 22
c s,../conf/,,
e
s 00001/00001/00505
d D 4.4 80/12/17 10:33:37 wnj 22 21
c change to ttioctl
e
s 00001/00000/00505
d D 4.3 80/11/13 19:58:24 bill 21 20
c fix to conditionals
e
s 00001/00000/00504
d D 4.2 80/11/09 23:12:40 bill 20 19
c include ../h/mx.h for lint's sake
e
s 00000/00000/00504
d D 4.1 80/11/09 16:52:09 bill 19 18
c stamp for 4bsd
e
s 00001/00001/00503
d D 3.18 80/10/19 23:25:22 bill 18 17
c fix per ghg
e
s 00009/00014/00495
d D 3.17 80/10/19 22:15:24 bill 17 16
c ../conf/*.h
e
s 00001/00001/00508
d D 3.16 80/09/27 17:59:56 bill 16 15
c 4dz's plus LOWAT and HIWAT ala speed
e
s 00001/00001/00508
d D 3.15 80/09/20 20:38:50 bill 15 14
c ttioctl
e
s 00002/00001/00507
d D 3.14 80/08/24 21:21:38 bill 14 13
c allocate an extra, spurious uba register in attempt to stop hardware bug
e
s 00014/00016/00494
d D 3.13 80/06/23 17:35:59 bill 13 12
c cleanup reset code
e
s 00051/00005/00459
d D 3.12 80/06/22 12:26:46 bill 12 11
c dhreset
e
s 00001/00001/00463
d D 3.11 80/06/07 02:44:54 bill 11 10
c %H%->%G%
e
s 00002/00001/00462
d D 3.10 80/06/04 13:53:36 bill 10 9
c reformat
e
s 00001/00001/00462
d D 3.9 80/05/18 11:32:14 bill 9 8
c send t_intrc on break
e
s 00001/00001/00462
d D 3.8 80/05/15 16:56:35 bill 8 7
c restore sccs line
e
s 00040/00040/00423
d D 3.7 80/05/15 16:53:58 bill 7 6
c iiasa fixups
e
s 00015/00000/00448
d D 3.6 80/05/09 20:55:01 bill 6 5
c run spl6 for dz SAE
e
s 00004/00001/00444
d D 3.5 80/05/09 13:50:48 bill 5 4
c silo service code protected at spl6
e
s 00022/00032/00423
d D 3.4 80/05/08 10:03:40 bill 4 3
c rint triggered by call from clock; silo frozen at 16
e
s 00030/00021/00425
d D 3.3 80/05/05 15:29:23 bill 3 2
c first working silo code
e
s 00007/00000/00439
d D 3.2 80/04/30 17:14:52 bill 2 1
c it didnt look for npr transmitters and got wedged on uba errors...
e
s 00439/00000/00000
d D 3.1 80/04/09 16:03:03 bill 1 0
c date and time created 80/04/09 16:03:03 by bill
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%H%	*/
E 7
I 7
D 8
/*	dh.c	3.6	5/9/80	*/
E 8
I 8
D 11
/*	%M%	%I%	%H%	*/
E 11
I 11
D 31
/*	%M%	%I%	%G%	*/
E 31
I 31
D 88
/*	%M%	%I%	%E%	*/
E 88
I 88
/*
D 97
 * Copyright (c) 1982 Regents of the University of California.
E 97
I 97
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 97
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 88
E 31
E 11
E 8
E 7

I 17
D 23
#include "../conf/dh.h"
E 23
I 23
#include "dh.h"
E 23
D 41
#if NDH11 > 0
E 41
I 41
#if NDH > 0
E 41
I 33
D 47
#define	DELAY(i)	{ register int j = i; while (--j > 0); }
E 47
E 33
E 17
/*
D 17
 *	DH-11 driver
 *	This driver calls on the DHDM driver.
 *	If the DH has no DM11-BB, then the latter will
 *	be fake. To insure loading of the correct DM code,
 *	lib2 should have dhdm.o, dh.o and dhfdm.o in that order.
E 17
I 17
D 35
 * DH-11 driver
E 35
I 35
 * DH-11/DM-11 driver
E 35
D 33
 *
E 33
D 32
 * Loaded with dhdm if there are DM-11's otherwise with dhfdm.
 *
 * NB: WE HAVEN'T TESTED dhdm CODE ON VAX.
E 32
I 32
D 34
 * DOESNT HANDLE EXTENDED ADDRESS BITS.
E 34
E 32
E 17
 */
I 77
#include "../machine/pte.h"

E 77
I 43
#include "bk.h"
I 81
#include "uba.h"
E 81
E 43
D 34

E 34
D 84
#include "../h/param.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
I 63
#include "../h/proc.h"
I 75
#include "../h/ioctl.h"
E 75
E 63
#include "../h/tty.h"
#include "../h/map.h"
D 77
#include "../h/pte.h"
E 77
I 31
#include "../h/buf.h"
I 37
#include "../h/vm.h"
I 82
#include "../h/kernel.h"
E 84
I 84
#include "param.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "ioctl.h"
#include "tty.h"
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "kernel.h"
I 86
#include "syslog.h"
E 86
E 84
E 82
E 37
E 31
D 46
#include "../h/uba.h"
E 46
I 46
D 72
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 72
I 72

D 84
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
I 78
#include "../vaxuba/dhreg.h"
#include "../vaxuba/dmreg.h"
E 84
I 84
#include "ubareg.h"
#include "ubavar.h"
#include "dhreg.h"
#include "dmreg.h"
E 84
E 78

E 72
E 46
I 3
D 84
#include "../h/bk.h"
I 17
#include "../h/clist.h"
I 20
D 60
#include "../h/mx.h"
E 60
I 34
#include "../h/file.h"
I 69
#include "../h/uio.h"
E 84
I 84
#include "bkmac.h"
#include "clist.h"
#include "file.h"
#include "uio.h"
E 84
E 69
E 34
E 20
E 17
E 3

I 6
D 31
/*
 * When running dz's using only SAE (silo alarm) on input
 * it is necessary to call dzrint() at clock interrupt time.
 * This is unsafe unless spl5()s in tty code are changed to
 * spl6()s to block clock interrupts.  Note that the dh driver
 * currently in use works the same way as the dz, even though
 * we could try to more intelligently manage its silo.
 * Thus don't take this out if you have no dz's unless you
 * change clock.c and dhtimer().
 */
E 31
I 31
D 33
/* This is to block the clock because we are using the silos */
/* SHOULD RATHER QUEUE SOFTWARE INTERRUPT AT CLOCK TIME */
E 31
#define	spl5	spl6
E 33
I 33
D 34
#define	UBACVT(x,uban) (cbase[uban] + ((x)-(char *)cfree))
E 34
I 34
D 35
#define	UBACVT(x, uban)		(cbase[uban] + ((x)-(char *)cfree))
E 34
E 33

E 35
I 34
/*
D 35
 * Definition of the controller for the auto-configuration program.
E 35
I 35
 * Definition of the driver for the auto-configuration program.
 * There is one definition for the dh and one for the dm.
E 35
 */
E 34
E 6
D 3
#define	q3	tp->t_outq
E 3
D 17
#define	DHADDR	((struct device *)(UBA0_DEV + 0160020))
D 12
#define	NDH11	16	/* number of lines */
E 12
I 12
#define	NDH11	32	/* number of lines */
E 12
#define UBACVT(x) (cbase + (short)((x)-(char *)cfree))
E 17
I 17
D 31
#define	UBACVT(x) (cbase + (short)((x)-(char *)cfree))
E 31
I 31
D 33
#define	UBACVT(x,uban) (cbase[uban] + (short)((x)-(char *)cfree))
E 31
E 17

E 33
D 17
struct cblock {
	struct cblock *c_next;
	char	c_info[CBSIZE];
};

E 17
D 31
struct	tty dh11[NDH11];
E 31
I 31
D 38
int	dhcntrlr(), dhslave(), dhrint(), dhxint();
E 38
I 38
D 82
int	dhprobe(), dhattach(), dhrint(), dhxint();
E 82
I 82
int	dhprobe(), dhattach(), dhrint(), dhxint(), dhtimer();
E 82
E 38
D 41
struct	uba_dinfo *dhinfo[NDH11];
E 41
I 41
D 46
struct	uba_dinfo *dhinfo[NDH];
E 46
I 46
struct	uba_device *dhinfo[NDH];
E 46
E 41
u_short	dhstd[] = { 0 };
D 32
int	(*dhivec[])() = { dhrint, dhxint, 0 };	/* note: order matters */
E 32
struct	uba_driver dhdriver =
D 32
	{ dhcntrlr, dhslave, (int (*)())0, 0, 0, dhstd, dhinfo, dhivec };
E 32
I 32
D 33
	{ dhcntrlr, dhslave, (int (*)())0, 0, 0, dhstd, "dh", dhinfo };
E 33
I 33
D 35
	{ dhcntrlr, dhslave, 0, 0, dhstd, "dh", dhinfo };
E 35
I 35
D 37
	{ dhcntrlr, dhslave, 0, 0, dhstd, "dh11", dhinfo };
E 37
I 37
D 38
	{ dhcntrlr, dhslave, 0, 0, dhstd, "dh", dhinfo };
E 38
I 38
	{ dhprobe, 0, dhattach, 0, dhstd, "dh", dhinfo };
E 38
E 37
E 35
E 33
E 32

D 35
struct	tty dh11[NDH11*16];
E 31
D 3
short	dhcc[NDH11];
E 3
D 4
int	dhchars[(NDH11+15)/16];
E 4
I 4
int	dhact;
I 12
D 33
int	dhisilo;
E 33
E 12
E 4
D 31
int	ndh11	= NDH11;
E 31
I 31
int	ndh11	= NDH11*16;
E 31
int	dhstart();
int	ttrstrt();
D 12
int cbase;
E 12
I 12
D 31
int	dh_ubinfo;
int	cbase;
int	getcbase;
E 31
I 31
D 32
int	dh_ubinfo[4];
int	cbase[4];
E 32
I 32
int	dh_ubinfo[MAXNUBA];
int	cbase[MAXNUBA];
E 35
I 35
D 38
int	dmcntrlr(), dmslave(), dmintr();
E 38
I 38
int	dmprobe(), dmattach(), dmintr();
E 38
D 41
struct	uba_dinfo *dminfo[NDH11];
E 41
I 41
D 46
struct	uba_dinfo *dminfo[NDH];
E 46
I 46
struct	uba_device *dminfo[NDH];
E 46
E 41
u_short	dmstd[] = { 0 };
struct	uba_driver dmdriver =
D 37
	{ dmcntrlr, dmslave, 0, 0, dmstd, "dm11", dminfo };
E 37
I 37
D 38
	{ dmcntrlr, dmslave, 0, 0, dmstd, "dm", dminfo };
E 38
I 38
	{ dmprobe, 0, dmattach, 0, dmstd, "dm", dminfo };
E 38
E 37
E 35
E 32
E 31
D 13
int	dhinit;
E 13
E 12
D 17
extern struct cblock cfree[];
E 17

D 34
/*
 * Hardware control bits
 */
E 34
I 34
D 35
/* Bits in dhlpr */
E 34
#define	BITS6	01
#define	BITS7	02
#define	BITS8	03
#define	TWOSB	04
#define	PENABLE	020
/* DEC manuals incorrectly say this bit causes generation of even parity. */
#define	OPAR	040
#define	HDUPLX	040000
E 35
I 35
D 78
struct dhdevice
{
	union {
		short	dhcsr;		/* control-status register */
		char	dhcsrl;		/* low byte for line select */
	} un;
	short	dhrcr;			/* receive character register */
	short	dhlpr;			/* line parameter register */
	u_short dhcar;			/* current address register */
	short	dhbcr;			/* byte count register */
	u_short	dhbar;			/* buffer active register */
	short	dhbreak;		/* break control register */
	short	dhsilo;			/* silo status register */
};
E 35

E 78
I 65
#ifndef	PORTSELECTOR
D 91
#define	ISPEED	B300
E 91
I 91
#define	ISPEED	B9600
E 91
#define	IFLAGS	(EVENP|ODDP|ECHO)
#else
#define	ISPEED	B4800
#define	IFLAGS	(EVENP|ODDP)
#endif
D 78

E 65
I 32
D 33
#define	MAINT	01000
E 32
#define	IENAB	030100
I 2
#define	NXM	02000
#define	CLRNXM	0400
E 2
#define	PERROR	010000
#define	FRERROR	020000
#define	OVERRUN	040000
#define	XINT	0100000
I 32
#define	RINT	0100
E 32
#define	SSPEED	7	/* standard speed: 300 baud */
E 33
I 33
/* Bits in dhcsr */
#define	DH_TI	0100000		/* transmit interrupt */
#define	DH_SI	0040000		/* storage interrupt */
#define	DH_TIE	0020000		/* transmit interrupt enable */
#define	DH_SIE	0010000		/* storage interrupt enable */
#define	DH_MC	0004000		/* master clear */
#define	DH_NXM	0002000		/* non-existant memory */
#define	DH_MM	0001000		/* maintenance mode */
#define	DH_CNI	0000400		/* clear non-existant memory interrupt */
#define	DH_RI	0000200		/* receiver interrupt */
#define	DH_RIE	0000100		/* receiver interrupt enable */
E 33

I 35
/* Bits in dhlpr */
#define	BITS6	01
#define	BITS7	02
#define	BITS8	03
#define	TWOSB	04
#define	PENABLE	020
/* DEC manuals incorrectly say this bit causes generation of even parity. */
#define	OPAR	040
#define	HDUPLX	040000

I 49
D 58
#if NBK == 0
#define	DH_IE	(DH_TIE|DH_RIE)
#else
E 58
E 49
E 35
I 33
#define	DH_IE	(DH_TIE|DH_SIE|DH_RIE)
I 49
D 58
#endif
E 58
E 49

/* Bits in dhrcr */
D 35
#define	DH_PE	010000		/* parity error */
#define	DH_FE	020000		/* framing error */
#define	DH_DO	040000		/* data overrun */
E 35
I 35
#define	DH_PE		0010000		/* parity error */
#define	DH_FE		0020000		/* framing error */
#define	DH_DO		0040000		/* data overrun */
E 35

I 35
struct dmdevice
{
	short	dmcsr;		/* control status register */
	short	dmlstat;	/* line status register */
	short	dmpad1[2];
};

/* bits in dm csr */
#define	DM_RF		0100000		/* ring flag */
#define	DM_CF		0040000		/* carrier flag */
#define	DM_CTS		0020000		/* clear to send */
#define	DM_SRF		0010000		/* secondary receive flag */
#define	DM_CS		0004000		/* clear scan */
#define	DM_CM		0002000		/* clear multiplexor */
#define	DM_MM		0001000		/* maintenance mode */
#define	DM_STP		0000400		/* step */
#define	DM_DONE		0000200		/* scanner is done */
#define	DM_IE		0000100		/* interrupt enable */
#define	DM_SE		0000040		/* scan enable */
#define	DM_BUSY		0000020		/* scan busy */

/* bits in dm lsr */
#define	DML_RNG		0000200		/* ring */
#define	DML_CAR		0000100		/* carrier detect */
#define	DML_CTS		0000040		/* clear to send */
#define	DML_SR		0000020		/* secondary receive */
#define	DML_ST		0000010		/* secondary transmit */
#define	DML_RTS		0000004		/* request to send */
#define	DML_DTR		0000002		/* data terminal ready */
#define	DML_LE		0000001		/* line enable */

D 54
#define	DML_ON		(DML_DTR|DML_LE)
E 54
I 54
#define	DML_ON		(DML_DTR|DML_RTS|DML_LE)
E 54
#define	DML_OFF		(DML_LE)
E 78

I 82
#define	FASTTIMER	(hz/30)		/* scan rate with silos on */

E 82
E 35
E 33
D 4
#ifdef ERNIE
#define	DHTIME	2		/* Since Berknet packets are only 100 chars */
#else
#define	DHTIME	6
#endif
extern int dhtimer();

E 4
/*
D 35
 * DM control bits
E 35
I 35
 * Local variables for the driver
E 35
 */
D 33
#define	TURNON	03	/* CD lead + line enable */
#define	TURNOFF	01	/* line enable */
I 7
#define	DTR	02	/* data terminal ready */
E 7
#define	RQS	04	/* request to send */
E 33
I 33
D 35
#define	DM_ON	03	/* CD lead + line enable */
#define	DM_OFF	01	/* line enable */
#define	DM_DTR	02	/* data terminal ready */
#define	DM_RQS	04	/* request to send */
E 35
I 35
D 41
short	dhsar[NDH11];			/* software copy of last bar */
I 37
short	dhsoftCAR[NDH11];
E 41
I 41
short	dhsar[NDH];			/* software copy of last bar */
short	dhsoftCAR[NDH];
E 41
E 37
E 35
E 33

D 34
/*
 * Software copy of last dhbar
 */
E 34
I 34
D 35
/* Software copy of last dhbar */
E 34
D 31
short	dhsar[(NDH11+15)/16];
E 31
I 31
short	dhsar[NDH11];
E 35
I 35
D 41
struct	tty dh11[NDH11*16];
int	ndh11	= NDH11*16;
E 41
I 41
struct	tty dh11[NDH*16];
int	ndh11	= NDH*16;
E 41
int	dhact;				/* mask of active dh's */
I 82
int	dhsilos;			/* mask of dh's with silo in use */
int	dhchars[NDH];			/* recent input count */
int	dhrate[NDH];			/* smoothed input count */
int	dhhighrate = 100;		/* silo on if dhchars > dhhighrate */
int	dhlowrate = 75;			/* silo off if dhrate < dhlowrate */
static short timerstarted;
E 82
int	dhstart(), ttrstrt();
E 35
E 31

D 35
struct device
{
	union {
D 33
		short	dhcsr;
		char	dhcsrl;
E 33
I 33
		short	dhcsr;		/* control-status register */
		char	dhcsrl;		/* low byte for line select */
E 33
	} un;
D 33
	short	dhnxch;
	short	dhlpr;
	unsigned short	dhcar;
	short	dhbcr;
	unsigned short	dhbar;
	short	dhbreak;
	short	dhsilo;
E 33
I 33
	short	dhrcr;			/* receive character register */
	short	dhlpr;			/* line parameter register */
	u_short dhcar;			/* current address register */
	short	dhbcr;			/* byte count register */
	u_short	dhbar;			/* buffer active register */
	short	dhbreak;		/* break control register */
	short	dhsilo;			/* silo status register */
E 33
};
E 35
I 35
/*
D 98
 * The clist space is mapped by the driver onto each UNIBUS.
E 98
I 98
 * The clist space is mapped by one terminal driver onto each UNIBUS.
 * The identity of the board which allocated resources is recorded,
 * so the process may be repeated after UNIBUS resets.
E 98
 * The UBACVT macro converts a clist space address for unibus uban
 * into an i/o space address for the DMA routine.
 */
D 81
int	dh_ubinfo[MAXNUBA];		/* info about allocated unibus map */
int	cbase[MAXNUBA];			/* base address in unibus map */
E 81
I 81
D 98
int	dh_ubinfo[NUBA];		/* info about allocated unibus map */
int	cbase[NUBA];			/* base address in unibus map */
E 98
I 98
int	dh_uballoc[NUBA];	/* which dh (if any) allocated unibus map */
int	cbase[NUBA];		/* base address of clists in unibus map */
E 98
E 81
#define	UBACVT(x, uban)		(cbase[uban] + ((x)-(char *)cfree))
E 35

I 33
/*
 * Routine for configuration to force a dh to interrupt.
 * Set to transmit at 9600 baud, and cause a transmitter interrupt.
 */
I 34
/*ARGSUSED*/
E 34
E 33
I 31
D 38
dhcntrlr(ui, reg)
	struct uba_dinfo *ui;
E 38
I 38
dhprobe(reg)
I 100
D 101
p
E 101
E 100
E 38
	caddr_t reg;
{
I 32
D 33
	struct device *dhaddr = (struct device *)reg;
E 33
I 33
D 34
	register int br, cvec;
E 34
I 34
	register int br, cvec;		/* these are ``value-result'' */
E 34
D 35
	register struct device *dhaddr = (struct device *)reg;
E 35
I 35
	register struct dhdevice *dhaddr = (struct dhdevice *)reg;
E 35
E 33
D 38
	int i;
E 38
E 32

I 38
#ifdef lint
	br = 0; cvec = br; br = cvec;
I 66
	if (ndh11 == 0) ndh11 = 1;
E 66
I 61
	dhrint(0); dhxint(0);
E 61
#endif
E 38
I 37
D 42
#ifdef notdef
E 42
I 42
#ifndef notdef
E 42
	dhaddr->un.dhcsr = DH_RIE|DH_MM|DH_RI;
D 49
	DELAY(5);
E 49
I 49
D 64
	DELAY(25);
E 64
I 64
	DELAY(1000);
I 66
	dhaddr->un.dhcsr &= ~DH_RI;
E 66
E 64
E 49
	dhaddr->un.dhcsr = 0;
#else
E 37
D 32
	((struct device *)reg)->un.dhcsr |= IENABLE;
	/* get it to interrupt */
E 32
I 32
D 33
	dhaddr->un.dhcsr = IENAB;
E 33
I 33
	dhaddr->un.dhcsr = DH_TIE;
	DELAY(5);
	dhaddr->dhlpr = (B9600 << 10) | (B9600 << 6) | BITS7|PENABLE;
E 33
	dhaddr->dhbcr = -1;
D 33
	dhaddr->dhbar = 1;
E 33
	dhaddr->dhcar = 0;
D 33
	for (i = 0; i < 1000000; i++)
		;
	/* we should have had an interrupt */
E 33
I 33
	dhaddr->dhbar = 1;
	DELAY(100000);		/* wait 1/10'th of a sec for interrupt */
E 33
	dhaddr->un.dhcsr = 0;
D 33
	asm("cmpl r10,$0x200;beql 1f;subl2 $4,r10;1:;");
E 33
I 33
	if (cvec && cvec != 0x200)
		cvec -= 4;		/* transmit -> receive */
I 36
D 37
#ifdef notdef
	dhaddr->un.dhcsr = DH_RIE|DH_MM;
	DELAY(5);
	dhaddr->un.dhcsrl |= DH_RI;
	DELAY(5);
	dhaddr->un.dhcsr = 0;
E 37
#endif
E 36
D 67
	return (1);
E 67
I 67
	return (sizeof (struct dhdevice));
E 67
E 33
E 32
}

I 33
/*
D 38
 * Routine called to init slave tables.
E 38
I 38
 * Routine called to attach a dh.
E 38
 */
E 33
D 37
dhslave(ui, reg, slaveno)
E 37
I 37
D 38
dhslave(ui, reg)
E 38
I 38
dhattach(ui)
E 38
E 37
D 46
	struct uba_dinfo *ui;
E 46
I 46
	struct uba_device *ui;
E 46
D 38
	caddr_t reg;
E 38
{

D 33
	/* could fill in local tables for the dh here */
E 33
I 33
D 37
	/* no tables to set up */
E 37
I 37
	dhsoftCAR[ui->ui_unit] = ui->ui_flags;
I 94
	cbase[ui->ui_ubanum] = -1;
I 98
D 102
	dh_uballoc[ui->ui_unit] = -1;
E 102
I 102
	dh_uballoc[ui->ui_ubanum] = -1;
E 102
E 98
E 94
E 37
E 33
}

E 31
/*
I 35
 * Configuration routine to cause a dm to interrupt.
 */
D 38
dmcntrlr(um, addr)
	struct uba_minfo *um;
	caddr_t addr;
E 38
I 38
dmprobe(reg)
	caddr_t reg;
E 38
{
	register int br, vec;			/* value-result */
D 38
	register struct dmdevice *dmaddr = (struct dmdevice *)addr;
E 38
I 38
	register struct dmdevice *dmaddr = (struct dmdevice *)reg;
E 38

I 38
#ifdef lint
D 47
	br = 0; cvec = br; br = cvec;
E 47
I 47
	br = 0; vec = br; br = vec;
I 61
D 63
	dmintr();
E 63
I 63
	dmintr(0);
E 63
E 61
E 47
#endif
E 38
	dmaddr->dmcsr = DM_DONE|DM_IE;
	DELAY(20);
	dmaddr->dmcsr = 0;
I 38
	return (1);
E 38
}

D 38
dmslave(ui, addr, slave)
E 38
I 38
/*ARGSUSED*/
dmattach(ui)
E 38
D 46
	struct uba_dinfo *ui;
E 46
I 46
	struct uba_device *ui;
E 46
D 38
	caddr_t addr;
	int slave;
E 38
{

	/* no local state to set up */
}

/*
E 35
D 34
 * Open a DH11 line.
E 34
I 34
 * Open a DH11 line, mapping the clist onto the uba if this
 * is the first dh on this uba.  Turn on this dh if this is
 * the first use of it.  Also do a dmopen to wait for carrier.
E 34
 */
/*ARGSUSED*/
dhopen(dev, flag)
I 31
	dev_t dev;
E 31
{
	register struct tty *tp;
D 31
	register d;
E 31
I 31
	register int unit, dh;
E 31
D 35
	register struct device *addr;
E 35
I 35
	register struct dhdevice *addr;
E 35
I 31
D 46
	register struct uba_dinfo *ui;
E 46
I 46
	register struct uba_device *ui;
E 46
E 31
D 4
	static	timer_on;
E 4
I 4
D 12
	static getcbase;
E 12
E 4
	int s;

D 31
	d = minor(dev) & 0177;
	if (d >= NDH11) {
E 31
I 31
	unit = minor(dev);
	dh = unit >> 4;
D 34
	if (unit >= NDH11*16 || (ui = dhinfo[dh])->ui_alive == 0) {
E 34
I 34
D 41
	if (unit >= NDH11*16 || (ui = dhinfo[dh])== 0 || ui->ui_alive == 0) {
E 41
I 41
D 74
	if (unit >= NDH*16 || (ui = dhinfo[dh])== 0 || ui->ui_alive == 0) {
E 41
E 34
E 31
		u.u_error = ENXIO;
		return;
	}
E 74
I 74
	if (unit >= NDH*16 || (ui = dhinfo[dh])== 0 || ui->ui_alive == 0)
		return (ENXIO);
E 74
D 31
	tp = &dh11[d];
	addr = DHADDR;
	addr += d>>4;
E 31
I 31
	tp = &dh11[unit];
D 34
	ui = dhinfo[dh];
E 34
I 34
D 62
	if (tp->t_state&XCLUDE && u.u_uid!=0) {
E 62
I 62
D 74
	if (tp->t_state&TS_XCLUDE && u.u_uid!=0) {
E 62
		u.u_error = EBUSY;
		return;
	}
E 74
I 74
	if (tp->t_state&TS_XCLUDE && u.u_uid!=0)
		return (EBUSY);
E 74
E 34
D 35
	addr = (struct device *)ui->ui_addr;
E 35
I 35
	addr = (struct dhdevice *)ui->ui_addr;
E 35
E 31
	tp->t_addr = (caddr_t)addr;
	tp->t_oproc = dhstart;
D 60
	tp->t_iproc = NULL;
E 60
D 62
	tp->t_state |= WOPEN;
E 62
I 62
	tp->t_state |= TS_WOPEN;
E 62
D 34
	s = spl6();
E 34
I 34
	/*
	 * While setting up state for this uba and this dh,
	 * block uba resets which can clear the state.
	 */
	s = spl5();
E 34
D 4
	if (!timer_on) {
		timer_on++;
		timeout(dhtimer, (caddr_t)0, DHTIME);
E 4
I 4
D 31
	if (!getcbase) {
		getcbase++;
E 31
I 31
D 32
	if (dh_ubinfo[ui->ui_ubanum]) {
E 32
I 32
D 92
	if (dh_ubinfo[ui->ui_ubanum] == 0) {
E 32
E 31
E 4
D 12
		cbase = (short)uballoc((caddr_t)cfree, NCLIST*sizeof(struct cblock), 0);
E 12
I 12
D 14
		dh_ubinfo = uballoc((caddr_t)cfree, NCLIST*sizeof(struct cblock), 0);
E 14
I 14
		/* 512+ is a kludge to try to get around a hardware problem */
E 92
I 92
D 94
	if (cbase[ui->ui_ubanum] == 0) {
E 94
I 94
	if (cbase[ui->ui_ubanum] == -1) {
E 94
E 92
D 31
		dh_ubinfo = uballoc((caddr_t)cfree, 512+NCLIST*sizeof(struct cblock), 0);
E 14
		cbase = (short)dh_ubinfo;
E 31
I 31
D 98
		dh_ubinfo[ui->ui_ubanum] =
D 32
		    uballoc((caddr_t)cfree,
E 32
I 32
		    uballoc(ui->ui_ubanum, (caddr_t)cfree,
E 32
D 44
			512+NCLIST*sizeof(struct cblock), 0);
E 44
I 44
D 92
			512+nclist*sizeof(struct cblock), 0);
E 92
I 92
			nclist*sizeof(struct cblock), 0);
E 92
E 44
D 33
		cbase[ui->ui_ubanum] = (short)dh_ubinfo[ui->ui_ubanum];
E 33
I 33
D 94
		cbase[ui->ui_ubanum] = dh_ubinfo[ui->ui_ubanum]&0x3ffff;
E 94
I 94
		cbase[ui->ui_ubanum] = UBAI_ADDR(dh_ubinfo[ui->ui_ubanum]);
E 98
I 98
		dh_uballoc[ui->ui_ubanum] = dh;
		cbase[ui->ui_ubanum] = UBAI_ADDR(uballoc(ui->ui_ubanum,
		    (caddr_t)cfree, nclist*sizeof(struct cblock), 0));
E 98
E 94
E 33
E 31
E 12
	}
I 82
	if (timerstarted == 0) {
		timerstarted++;
		timeout(dhtimer, (caddr_t) 0, hz);
	}
E 82
I 33
	if ((dhact&(1<<dh)) == 0) {
		addr->un.dhcsr |= DH_IE;
D 34
		addr->dhsilo = 16;
E 34
I 34
D 42
		DELAY(5);
E 42
E 34
		dhact |= (1<<dh);
I 55
D 58
#if NBK > 0
E 58
E 55
I 34
D 82
		addr->dhsilo = 16;
E 82
I 82
		addr->dhsilo = 0;
E 82
I 55
D 58
#endif
E 58
E 55
E 34
	}
E 33
	splx(s);
I 34
	/*
D 95
	 * If this is first open, initialze tty state to default.
E 95
I 95
	 * If this is first open, initialize tty state to default.
E 95
	 */
E 34
D 33
	addr->un.dhcsr |= IENAB;
I 4
D 31
	dhact |= (1<<(d>>4));
E 31
I 31
	dhact |= (1<<dh);
E 33
E 31
E 4
D 62
	if ((tp->t_state&ISOPEN) == 0) {
E 62
I 62
	if ((tp->t_state&TS_ISOPEN) == 0) {
E 62
		ttychars(tp);
I 65
D 91
#ifndef PORTSELECTOR
E 65
D 7
		tp->t_ispeed = SSPEED;
		tp->t_ospeed = SSPEED;
		tp->t_flags = ODDP|EVENP|ECHO;
E 7
I 7
		if (tp->t_ispeed == 0) {
D 33
			tp->t_ispeed = SSPEED;
			tp->t_ospeed = SSPEED;
E 33
I 33
D 65
			tp->t_ispeed = B300;
			tp->t_ospeed = B300;
E 33
			tp->t_flags = ODDP|EVENP|ECHO;
E 65
I 65
#endif
			tp->t_ispeed = ISPEED;
			tp->t_ospeed = ISPEED;
			tp->t_flags = IFLAGS;
#ifndef PORTSELECTOR
E 65
		}
I 65
#endif
E 91
I 91
D 95
		tp->t_ispeed = ISPEED;
		tp->t_ospeed = ISPEED;
		tp->t_flags = IFLAGS;
E 95
I 95
#ifndef PORTSELECTOR
		if (tp->t_ispeed == 0) {
#else
			tp->t_state |= TS_HUPCLS;
#endif PORTSELECTOR
			tp->t_ispeed = ISPEED;
			tp->t_ospeed = ISPEED;
			tp->t_flags = IFLAGS;
#ifndef PORTSELECTOR
		}
#endif PORTSELECTOR
E 95
E 91
E 65
E 7
D 31
		dhparam(d);
E 31
I 31
		dhparam(unit);
E 31
	}
D 34
	if (tp->t_state&XCLUDE && u.u_uid!=0) {
		u.u_error = EBUSY;
		return;
	}
E 34
I 34
	/*
	 * Wait for carrier, then process line discipline specific open.
	 */
E 34
D 103
	dmopen(dev);
E 103
I 103
	dmopen(dev, flag);
E 103
D 31
	(*linesw[tp->t_line].l_open)(dev,tp);
E 31
I 31
D 74
	(*linesw[tp->t_line].l_open)(dev, tp);
E 74
I 74
	return ((*linesw[tp->t_line].l_open)(dev, tp));
E 74
E 31
}

/*
D 34
 * Close a DH11 line.
E 34
I 34
 * Close a DH11 line, turning off the DM11.
E 34
 */
/*ARGSUSED*/
dhclose(dev, flag)
D 31
dev_t dev;
int  flag;
E 31
I 31
	dev_t dev;
	int flag;
E 31
{
	register struct tty *tp;
D 31
	register d;
E 31
I 31
	register unit;
E 31

D 31
	d = minor(dev) & 0177;
	tp = &dh11[d];
E 31
I 31
	unit = minor(dev);
	tp = &dh11[unit];
E 31
	(*linesw[tp->t_line].l_close)(tp);
I 27
D 33
	/*
	 * Turn of the break bit in case somebody did a TIOCSBRK without
	 * a TIOCCBRK.
	 */
E 33
D 31
	((struct device *)(tp->t_addr))->dhbreak &= ~(1<<(minor(dev)&017));
E 31
I 31
D 35
	((struct device *)(tp->t_addr))->dhbreak &= ~(1<<(unit&017));
E 35
I 35
	((struct dhdevice *)(tp->t_addr))->dhbreak &= ~(1<<(unit&017));
E 35
E 31
E 27
D 62
	if (tp->t_state&HUPCLS || (tp->t_state&ISOPEN)==0)
E 62
I 62
	if (tp->t_state&TS_HUPCLS || (tp->t_state&TS_ISOPEN)==0)
E 62
D 7
		dmctl(d, TURNOFF);
E 7
I 7
D 31
		dmctl(d, TURNOFF, DMSET);
E 31
I 31
D 33
		dmctl(unit, TURNOFF, DMSET);
E 33
I 33
D 35
		dmctl(unit, DM_OFF, DMSET);
E 35
I 35
		dmctl(unit, DML_OFF, DMSET);
E 35
E 33
E 31
E 7
	ttyclose(tp);
}

D 34
/*
 * Read from a DH11 line.
 */
E 34
D 69
dhread(dev)
E 69
I 69
dhread(dev, uio)
E 69
I 31
	dev_t dev;
I 69
	struct uio *uio;
E 69
E 31
{
D 31
register struct tty *tp;
E 31
I 31
D 73
	register struct tty *tp;
E 73
I 73
	register struct tty *tp = &dh11[minor(dev)];
E 73
E 31

D 31
	tp = &dh11[minor(dev) & 0177];
E 31
I 31
D 73
	tp = &dh11[minor(dev)];
E 73
E 31
D 69
	(*linesw[tp->t_line].l_read)(tp);
E 69
I 69
	return ((*linesw[tp->t_line].l_read)(tp, uio));
E 69
}

D 34
/*
 * write on a DH11 line
 */
E 34
D 70
dhwrite(dev)
E 70
I 70
dhwrite(dev, uio)
E 70
I 31
	dev_t dev;
I 70
	struct uio *uio;
E 70
E 31
{
D 31
register struct tty *tp;
E 31
I 31
D 73
	register struct tty *tp;
E 73
I 73
	register struct tty *tp = &dh11[minor(dev)];
E 73
E 31

D 31
	tp = &dh11[minor(dev) & 0177];
E 31
I 31
D 73
	tp = &dh11[minor(dev)];
E 31
D 70
	(*linesw[tp->t_line].l_write)(tp);
E 70
I 70
	(*linesw[tp->t_line].l_write)(tp, uio);
E 73
I 73
	return ((*linesw[tp->t_line].l_write)(tp, uio));
E 73
E 70
}

/*
 * DH11 receiver interrupt.
 */
D 31
dhrint(dev)
E 31
I 31
dhrint(dh)
	int dh;
E 31
{
	register struct tty *tp;
D 31
	register short c;
E 31
I 31
	register c;
E 31
D 35
	register struct device *addr;
E 35
I 35
	register struct dhdevice *addr;
E 35
I 4
	register struct tty *tp0;
I 31
D 46
	register struct uba_dinfo *ui;
E 46
I 46
	register struct uba_device *ui;
E 46
I 45
	int overrun = 0;
E 45
E 31
I 5
D 38
	int s;
E 38
E 5
E 4

I 5
D 33
	s = spl6();	/* see comment in clock.c */
E 33
E 5
D 31
	addr = DHADDR;
	addr += minor(dev) & 0177;
I 4
	tp0 = &dh11[((minor(dev)&0177)<<4)];
E 31
I 31
	ui = dhinfo[dh];
I 33
D 34
	if (ui == 0) {
		printf("stray dhrint %d\n", dh);
		asm("halt");
		return;
	}
E 34
E 33
D 35
	addr = (struct device *)ui->ui_addr;
E 35
I 35
	if (ui == 0 || ui->ui_alive == 0)
		return;
	addr = (struct dhdevice *)ui->ui_addr;
E 35
D 34
	tp0 = &dh11[dh*16];
E 31
E 4
D 33
	while ((c = addr->dhnxch) < 0) {	/* char. present */
E 33
I 33
	while ((c = addr->dhrcr) < 0) {	/* char. present */
E 33
D 4
		tp = &dh11[((minor(dev)&0177)<<4) + ((c>>8)&017)];
		dhchars[minor(dev)&0177]++;
E 4
I 4
		tp = tp0 + ((c>>8)&017);
E 4
D 31
		if (tp >= &dh11[NDH11])
E 31
I 31
		if (tp >= &dh11[NDH11*16])
E 31
			continue;
		if((tp->t_state&ISOPEN)==0) {
E 34
I 34
	tp0 = &dh11[dh<<4];
	/*
	 * Loop fetching characters from the silo for this
	 * dh until there are no more in the silo.
	 */
	while ((c = addr->dhrcr) < 0) {
		tp = tp0 + ((c>>8)&0xf);
I 82
		dhchars[dh]++;
E 82
I 65
D 91
#ifndef PORTSELECTOR
E 91
E 65
D 62
		if ((tp->t_state&ISOPEN)==0) {
E 62
I 62
		if ((tp->t_state&TS_ISOPEN)==0) {
I 65
D 91
#else
		if ((tp->t_state&(TS_ISOPEN|TS_WOPEN))==0) {
E 91
I 91
			wakeup((caddr_t)&tp->t_rawq);
#ifdef PORTSELECTOR
			if ((tp->t_state&TS_WOPEN) == 0)
E 91
#endif
E 65
E 62
E 34
D 91
			wakeup((caddr_t)tp);
			continue;
E 91
I 91
				continue;
E 91
		}
D 33
		if (c&PERROR)
E 33
I 33
D 34
		if (c&DH_PE)
E 34
I 34
		if (c & DH_PE)
E 34
E 33
			if ((tp->t_flags&(EVENP|ODDP))==EVENP
			 || (tp->t_flags&(EVENP|ODDP))==ODDP )
				continue;
D 33
		if (c&OVERRUN)
E 33
I 33
D 34
		if (c&DH_DO)
E 34
I 34
D 45
		if (c & DH_DO)
E 34
E 33
			printf("O");
E 45
I 45
		if ((c & DH_DO) && overrun == 0) {
D 86
			printf("dh%d: silo overflow\n", dh);
E 86
I 86
D 90
			log(KERN_RECOV, "dh%d: silo overflow\n", dh);
E 90
I 90
			log(LOG_WARNING, "dh%d: silo overflow\n", dh);
E 90
E 86
			overrun = 1;
		}
E 45
D 33
		if (c&FRERROR)		/* break */
E 33
I 33
D 34
		if (c&DH_FE)		/* break */
E 34
I 34
		if (c & DH_FE)
			/*
			 * At framing error (break) generate
			 * a null (in raw mode, for getty), or a
			 * interrupt (in cooked/cbreak mode).
			 */
E 34
E 33
			if (tp->t_flags&RAW)
D 34
				c = 0;	/* null (for getty) */
E 34
I 34
				c = 0;
E 34
			else
D 7
				c = 0177;	/* DEL (intr) */
D 3
		(*linesw[tp->t_line].l_rint)(c,tp);
E 3
I 3
#ifdef BERKNET
E 7
I 7
D 33
#ifdef IIASA
				continue;
#else
E 33
D 9
				c = 0177;	/* tun.t_intrc? */
E 9
I 9
D 75
				c = tun.t_intrc;
E 75
I 75
				c = tp->t_intrc;
E 75
I 43
#if NBK > 0
E 43
E 9
D 33
#endif
E 33
E 7
D 4
			if (tp->t_line == BNETLDIS) {
				c &= 0177;
				NETINPUT(c, tp);
			} else
E 4
I 4
D 5
		if (tp->t_line == BNETLDIS) {
E 5
I 5
		if (tp->t_line == NETLDISC) {
E 5
			c &= 0177;
D 7
			NETINPUT(c, tp);
E 7
I 7
			BKINPUT(c, tp);
E 7
		} else
I 43
#endif
E 43
E 4
D 7
#endif
E 7
D 4
				(*linesw[tp->t_line].l_rint)(c,tp);
E 4
I 4
D 34
			(*linesw[tp->t_line].l_rint)(c,tp);
E 34
I 34
			(*linesw[tp->t_line].l_rint)(c, tp);
E 34
E 4
E 3
	}
I 5
D 33
	splx(s);
E 33
E 5
}

/*
D 34
 * stty/gtty for DH11
E 34
I 34
 * Ioctl for DH11.
E 34
 */
/*ARGSUSED*/
D 68
dhioctl(dev, cmd, addr, flag)
D 31
caddr_t addr;
E 31
I 31
	caddr_t addr;
E 68
I 68
dhioctl(dev, cmd, data, flag)
	caddr_t data;
E 68
E 31
{
	register struct tty *tp;
I 31
D 74
	register unit = minor(dev);
E 74
I 74
	register int unit = minor(dev);
D 105
	int error;
E 105
I 105
	int error, s;
E 105
E 74
E 31

D 31
	tp = &dh11[minor(dev) & 0177];
E 31
I 31
	tp = &dh11[unit];
E 31
I 3
D 68
	cmd = (*linesw[tp->t_line].l_ioctl)(tp, cmd, addr);
E 68
I 68
D 74
	cmd = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
E 68
D 34
	if (cmd==0)
E 34
I 34
	if (cmd == 0)
E 34
		return;
E 3
D 15
	if (ttioccomm(cmd, tp, addr, dev)) {
E 15
I 15
D 22
	if (ttioctl(cmd, tp, addr, dev, flag)) {
E 22
I 22
D 68
	if (ttioctl(tp, cmd, addr, flag)) {
E 22
E 15
D 34
		if (cmd==TIOCSETP||cmd==TIOCSETN)
E 34
I 34
		if (cmd==TIOCSETP || cmd==TIOCSETN)
E 68
I 68
	if (ttioctl(tp, cmd, data, flag)) {
E 74
I 74
	error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
	if (error >= 0)
		return (error);
	error = ttioctl(tp, cmd, data, flag);
	if (error >= 0) {
E 74
D 85
		if (cmd == TIOCSETP || cmd == TIOCSETN)
E 85
I 85
		if (cmd == TIOCSETP || cmd == TIOCSETN || cmd == TIOCLBIS ||
		    cmd == TIOCLBIC || cmd == TIOCLSET)
E 85
E 68
E 34
D 31
			dhparam(dev);
E 31
I 31
			dhparam(unit);
E 31
D 7
	} else if (cmd==TIOCSBRK) {
		/* send a break */
		register int linebit = 1 << (dev&017);
		extern dhunbrk();

		wflushtty(tp);
		spl5();
		((struct device *)tp->t_addr)->dhbreak |= linebit;
		tp->t_state |= TIMEOUT;
		timeout(dhunbrk, (caddr_t)tp, 25);	/* 300-500 ms */
		while (((struct device *)tp->t_addr)->dhbreak & linebit)
			sleep((caddr_t)&tp->t_rawq, TTIPRI);
		tp->t_state &= ~TIMEOUT;
		spl0();
		flushtty(tp);
		return;
	} else
E 7
I 7
D 74
	} else switch(cmd) {
E 74
I 74
		return (error);
	}
	switch (cmd) {
E 74
I 68

E 68
	case TIOCSBRK:
D 31
		((struct device *)(tp->t_addr))->dhbreak |= 1<<(minor(dev)&017);
E 31
I 31
D 35
		((struct device *)(tp->t_addr))->dhbreak |= 1<<(unit&017);
E 35
I 35
		((struct dhdevice *)(tp->t_addr))->dhbreak |= 1<<(unit&017);
E 35
E 31
		break;
I 68

E 68
	case TIOCCBRK:
D 31
		((struct device *)(tp->t_addr))->dhbreak &= ~(1<<(minor(dev)&017));
E 31
I 31
D 35
		((struct device *)(tp->t_addr))->dhbreak &= ~(1<<(unit&017));
E 35
I 35
		((struct dhdevice *)(tp->t_addr))->dhbreak &= ~(1<<(unit&017));
E 35
E 31
		break;
I 68

E 68
	case TIOCSDTR:
D 31
		dmctl(minor(dev), DTR|RQS, DMBIS);
E 31
I 31
D 33
		dmctl(unit, DTR|RQS, DMBIS);
E 33
I 33
D 35
		dmctl(unit, DM_DTR|DM_RQS, DMBIS);
E 35
I 35
D 105
		dmctl(unit, DML_DTR|DML_RTS, DMBIS);
E 105
I 105
		(void) dmctl(unit, DML_DTR|DML_RTS, DMBIS);
E 105
E 35
E 33
E 31
		break;
I 68

E 68
	case TIOCCDTR:
D 31
		dmctl(minor(dev), DTR|RQS, DMBIC);
E 31
I 31
D 33
		dmctl(unit, DTR|RQS, DMBIC);
E 33
I 33
D 35
		dmctl(unit, DM_DTR|DM_RQS, DMBIC);
E 35
I 35
D 105
		dmctl(unit, DML_DTR|DML_RTS, DMBIC);
E 105
I 105
		(void) dmctl(unit, DML_DTR|DML_RTS, DMBIC);
E 105
E 35
E 33
E 31
		break;
I 68

I 105
	case TIOCMSET:
		(void) dmctl(unit, *(int *)data, DMSET);
		break;

	case TIOCMBIS:
		(void) dmctl(unit, *(int *)data, DMBIS);
		break;

	case TIOCMBIC:
		(void) dmctl(unit, *(int *)data, DMBIC);
		break;

	case TIOCMGET:
		s = spltty();
		tp->t_state &= ~TS_MODEMCHG;
		splx(s);
		*(int *)data = dmctl(unit, 0, DMGET);
		break;

E 105
E 68
	default:
E 7
D 74
		u.u_error = ENOTTY;
E 74
I 74
		return (ENOTTY);
E 74
I 7
	}
I 74
	return (0);
E 74
E 7
}

D 7
dhunbrk(tp)
register struct tty *tp;
{

	((struct device *)tp->t_addr)->dhbreak &= ~ (1 << (minor(tp->t_dev)&017));
	wakeup((caddr_t)&tp->t_rawq);
}

E 7
/*
 * Set parameters from open or stty into the DH hardware
 * registers.
 */
D 31
dhparam(dev)
E 31
I 31
dhparam(unit)
	register int unit;
E 31
{
	register struct tty *tp;
D 35
	register struct device *addr;
E 35
I 35
	register struct dhdevice *addr;
E 35
D 31
	register d;
E 31
I 31
	register int lpar;
E 31
I 13
	int s;
E 13

D 31
	d = minor(dev) & 0177;
	tp = &dh11[d];
E 31
I 31
	tp = &dh11[unit];
E 31
D 35
	addr = (struct device *)tp->t_addr;
E 35
I 35
	addr = (struct dhdevice *)tp->t_addr;
E 35
I 34
	/*
	 * Block interrupts so parameters will be set
	 * before the line interrupts.
	 */
E 34
D 13
	spl5();
E 13
I 13
	s = spl5();
E 13
D 31
	addr->un.dhcsrl = (d&017) | IENAB;
E 31
I 31
D 33
	addr->un.dhcsrl = (unit&017) | IENAB;
E 31
	/*
	 * Hang up line?
	 */
E 33
I 33
D 34
	addr->un.dhcsrl = (unit&017) | DH_IE;
E 34
I 34
	addr->un.dhcsrl = (unit&0xf) | DH_IE;
E 34
E 33
	if ((tp->t_ispeed)==0) {
D 62
		tp->t_state |= HUPCLS;
E 62
I 62
		tp->t_state |= TS_HUPCLS;
E 62
D 7
		dmctl(d, TURNOFF);
E 7
I 7
D 31
		dmctl(d, TURNOFF, DMSET);
E 31
I 31
D 33
		dmctl(unit, TURNOFF, DMSET);
E 33
I 33
D 35
		dmctl(unit, DM_OFF, DMSET);
E 35
I 35
		dmctl(unit, DML_OFF, DMSET);
I 96
		splx(s);
E 96
E 35
E 33
E 31
E 7
		return;
	}
D 31
	d = ((tp->t_ospeed)<<10) | ((tp->t_ispeed)<<6);
E 31
I 31
	lpar = ((tp->t_ospeed)<<10) | ((tp->t_ispeed)<<6);
E 31
D 34
	if ((tp->t_ispeed) == 4)		/* 134.5 baud */
E 34
I 34
	if ((tp->t_ispeed) == B134)
E 34
D 31
		d |= BITS6|PENABLE|HDUPLX;
E 31
I 31
		lpar |= BITS6|PENABLE|HDUPLX;
E 31
D 28
	else if (tp->t_flags&RAW)
E 28
I 28
D 29
	else if (tp->t_local & LLITOUT)
E 29
I 29
D 30
	else if ((tp->t_flag&RAW) || (tp->t_local&LLITOUT))
E 30
I 30
D 75
	else if ((tp->t_flags&RAW) || (tp->t_local&LLITOUT))
E 75
I 75
D 89
	else if (tp->t_flags & (RAW|LITOUT))
E 89
I 89
	else if (tp->t_flags & (RAW|LITOUT|PASS8))
E 89
E 75
E 30
E 29
E 28
D 31
		d |= BITS8;
E 31
I 31
		lpar |= BITS8;
E 31
	else
D 31
		d |= BITS7|PENABLE;
E 31
I 31
		lpar |= BITS7|PENABLE;
E 31
	if ((tp->t_flags&EVENP) == 0)
D 31
		d |= OPAR;
E 31
I 31
		lpar |= OPAR;
E 31
D 34
	if ((tp->t_ospeed) == 3)	/* 110 baud */
E 34
I 34
	if ((tp->t_ospeed) == B110)
E 34
D 31
		d |= TWOSB;
	addr->dhlpr = d;
E 31
I 31
		lpar |= TWOSB;
	addr->dhlpr = lpar;
E 31
D 13
	spl0();
E 13
I 13
	splx(s);
E 13
}

/*
 * DH11 transmitter interrupt.
 * Restart each line which used to be active but has
 * terminated transmission since the last interrupt.
 */
D 31
dhxint(dev)
E 31
I 31
dhxint(dh)
	int dh;
E 31
{
	register struct tty *tp;
D 35
	register struct device *addr;
E 35
I 35
	register struct dhdevice *addr;
E 35
D 31
	register d;
E 31
	short ttybit, bar, *sbar;
I 31
D 46
	register struct uba_dinfo *ui;
E 46
I 46
	register struct uba_device *ui;
E 46
D 34
	register unit;
E 34
I 34
	register int unit;
E 34
E 31
I 6
D 38
	int s;
I 34
	u_short cnt;
E 38
I 38
	u_short cntr;
E 38
E 34
E 6

I 6
D 33
	s = spl6();	/* block the clock */
E 33
E 6
D 31
	d = minor(dev) & 0177;
	addr = DHADDR + d;
E 31
I 31
	ui = dhinfo[dh];
D 35
	addr = (struct device *)ui->ui_addr;
E 35
I 35
	addr = (struct dhdevice *)ui->ui_addr;
E 35
E 31
D 33
	addr->un.dhcsr &= (short)~XINT;
I 2
	if (addr->un.dhcsr & NXM) {
I 32
		asm("halt");
E 32
		addr->un.dhcsr |= CLRNXM;
		printf("dh clr NXM\n");
E 33
I 33
	if (addr->un.dhcsr & DH_NXM) {
I 34
D 42
		DELAY(5);
E 42
E 34
		addr->un.dhcsr |= DH_CNI;
D 34
		printf("dh%d NXM\n", ui->ui_ctlr);
E 34
I 34
D 45
		printf("dh%d NXM\n", dh);
E 45
I 45
		printf("dh%d: NXM\n", dh);
E 45
E 34
E 33
	}
I 33
D 34
	addr->un.dhcsr &= (short)~DH_TI;
E 34
E 33
E 2
D 31
	sbar = &dhsar[d];
E 31
I 31
	sbar = &dhsar[dh];
E 31
	bar = *sbar & ~addr->dhbar;
I 12
D 13
	if (dhinit)
		bar = ~0;
E 13
E 12
D 31
	d <<= 4; ttybit = 1;

	for(; bar; d++, ttybit <<= 1) {
E 31
I 31
	unit = dh * 16; ttybit = 1;
D 34
	for(; bar; unit++, ttybit <<= 1) {
E 31
		if(bar&ttybit) {
E 34
I 34
	addr->un.dhcsr &= (short)~DH_TI;
	for (; bar; unit++, ttybit <<= 1) {
		if (bar & ttybit) {
E 34
			*sbar &= ~ttybit;
			bar &= ~ttybit;
D 31
			tp = &dh11[d];
E 31
I 31
			tp = &dh11[unit];
E 31
D 3
			if (tp->t_line) {
				(*linesw[tp->t_line].l_start)(tp);
			} else {
E 3
I 3
D 62
			tp->t_state &= ~BUSY;
			if (tp->t_state&FLUSH)
				tp->t_state &= ~FLUSH;
E 62
I 62
			tp->t_state &= ~TS_BUSY;
			if (tp->t_state&TS_FLUSH)
				tp->t_state &= ~TS_FLUSH;
E 62
			else {
E 3
D 31
				addr->un.dhcsrl = (d&017)|IENAB;
E 31
I 31
D 33
				addr->un.dhcsrl = (unit&017)|IENAB;
E 33
I 33
				addr->un.dhcsrl = (unit&017)|DH_IE;
E 33
E 31
I 12
D 13
				if (dhinit == 0)
E 13
E 12
D 3
				if (tp->t_state&FLUSH)
					tp->t_state &= ~FLUSH;
				else {
					ndflush(&q3, dhcc[d]);
				}
				tp->t_state &= ~BUSY;
				dhstart(tp);
E 3
I 3
D 7
				ndflush(&tp->t_outq, addr->dhcar-UBACVT(tp->t_outq.c_cf));
E 7
I 7
D 10
				ndflush(&tp->t_outq, (int)addr->dhcar-UBACVT(tp->t_outq.c_cf));
E 10
I 10
D 34
				ndflush(&tp->t_outq,
D 18
				    (int)addr->dhcar-UBACVT(tp->t_outq.c_cf));
E 18
I 18
D 31
				    (int)(short)addr->dhcar-UBACVT(tp->t_outq.c_cf));
E 31
I 31
D 33
				    (int)(short)addr->dhcar-
E 33
I 33
				    /* SHOULD PASTE ON 16&17 BITS HERE */
				    addr->dhcar-
E 33
					UBACVT(tp->t_outq.c_cf,ui->ui_ubanum));
E 34
I 34
D 42
				DELAY(5);
E 42
				/*
				 * Do arithmetic in a short to make up
				 * for lost 16&17 bits.
				 */
D 38
				cnt = addr->dhcar -
E 38
I 38
				cntr = addr->dhcar -
E 38
				    UBACVT(tp->t_outq.c_cf, ui->ui_ubanum);
D 38
				ndflush(&tp->t_outq, cnt);
E 38
I 38
D 47
				ndflush(&tp->t_outq, cntr);
E 47
I 47
				ndflush(&tp->t_outq, (int)cntr);
E 47
E 38
E 34
E 31
E 18
E 10
E 7
E 3
			}
I 3
			if (tp->t_line)
				(*linesw[tp->t_line].l_start)(tp);
			else
				dhstart(tp);
E 3
		}
	}
I 6
D 33
	splx(s);
E 33
E 6
}

/*
 * Start (restart) transmission on the given DH11 line.
 */
dhstart(tp)
D 31
register struct tty *tp;
E 31
I 31
	register struct tty *tp;
E 31
{
D 35
	register struct device *addr;
E 35
I 35
	register struct dhdevice *addr;
E 35
D 31
	register short nch;
	int s, d;
E 31
I 31
D 34
	register int nch, dh, unit;
E 34
I 34
	register int car, dh, unit, nch;
E 34
	int s;
E 31

D 34
	/*
	 * If it's currently active, or delaying,
	 * no need to do anything.
	 */
	s = spl5();
E 34
D 31
	d = tp-dh11;
E 31
I 31
	unit = minor(tp->t_dev);
	dh = unit >> 4;
I 34
	unit &= 0xf;
E 34
E 31
D 35
	addr = (struct device *)tp->t_addr;
E 35
I 35
	addr = (struct dhdevice *)tp->t_addr;
E 35
I 34

	/*
	 * Must hold interrupts in following code to prevent
	 * state of the tp from changing.
	 */
	s = spl5();
	/*
	 * If it's currently active, or delaying, no need to do anything.
	 */
E 34
D 62
	if (tp->t_state&(TIMEOUT|BUSY|TTSTOP))
E 62
I 62
	if (tp->t_state&(TS_TIMEOUT|TS_BUSY|TS_TTSTOP))
E 62
		goto out;
I 34
	/*
	 * If there are sleepers, and output has drained below low
	 * water mark, wake up the sleepers.
	 */
E 34
D 31

D 3

E 3
	/*
	 * If the writer was sleeping on output overflow,
	 * wake him when low tide is reached.
	 */
D 16
	if (tp->t_state&ASLEEP && tp->t_outq.c_cc<=TTLOWAT) {
E 16
I 16
	if (tp->t_state&ASLEEP && tp->t_outq.c_cc<=TTLOWAT(tp)) {
E 31
I 31
D 62
	if ((tp->t_state&ASLEEP) && tp->t_outq.c_cc<=TTLOWAT(tp)) {
E 31
E 16
		tp->t_state &= ~ASLEEP;
D 60
		if (tp->t_chan)
D 7
			mcstart(tp->t_chan, (caddr_t)&tp->t_outq); else
E 7
I 7
			mcstart(tp->t_chan, (caddr_t)&tp->t_outq);
		else
E 7
			wakeup((caddr_t)&tp->t_outq);
E 60
I 60
		wakeup((caddr_t)&tp->t_outq);
E 62
I 62
	if (tp->t_outq.c_cc<=TTLOWAT(tp)) {
		if (tp->t_state&TS_ASLEEP) {
			tp->t_state &= ~TS_ASLEEP;
			wakeup((caddr_t)&tp->t_outq);
		}
		if (tp->t_wsel) {
			selwakeup(tp->t_wsel, tp->t_state & TS_WCOLL);
			tp->t_wsel = 0;
			tp->t_state &= ~TS_WCOLL;
		}
E 62
E 60
	}
I 34
	/*
	 * Now restart transmission unless the output queue is
	 * empty.
	 */
E 34
D 31

E 31
	if (tp->t_outq.c_cc == 0)
		goto out;
D 31

D 3


E 3
	/*
	 * Find number of characters to transfer.
	 */
	if (tp->t_flags & RAW) {
E 31
I 31
D 53
	if (tp->t_flags & RAW)
E 53
I 53
D 75
	if (tp->t_flags&RAW || tp->t_local&LLITOUT)
E 75
I 75
D 104
	if (tp->t_flags & (RAW|LITOUT))
E 104
I 104
	if (tp->t_flags & (RAW|LITOUT|PASS8))
E 104
E 75
E 53
E 31
		nch = ndqb(&tp->t_outq, 0);
D 31
	} else {
E 31
I 31
	else {
E 31
		nch = ndqb(&tp->t_outq, 0200);
I 34
		/*
		 * If first thing on queue is a delay process it.
		 */
E 34
		if (nch == 0) {
			nch = getc(&tp->t_outq);
D 34
			timeout(ttrstrt, (caddr_t)tp, (nch&0177)+6);
E 34
I 34
			timeout(ttrstrt, (caddr_t)tp, (nch&0x7f)+6);
E 34
D 62
			tp->t_state |= TIMEOUT;
E 62
I 62
			tp->t_state |= TS_TIMEOUT;
E 62
			goto out;
		}
	}
I 34
	/*
	 * If characters to transmit, restart transmission.
	 */
E 34
D 31
	/*
	 * If any characters were set up, start transmission;
	 */
E 31
	if (nch) {
D 31
		addr->un.dhcsrl = (d&017)|IENAB;
		addr->dhcar = UBACVT(tp->t_outq.c_cf);
E 31
I 31
D 33
		addr->un.dhcsrl = (unit&017)|IENAB;
E 33
I 33
D 34
		/* SHOULD PASTE ON BITS 16&17 HERE */
		addr->un.dhcsrl = (unit&017)|DH_IE;
E 33
		addr->dhcar = UBACVT(tp->t_outq.c_cf, 
		    dhinfo[dh]->ui_ubanum);
E 34
I 34
		car = UBACVT(tp->t_outq.c_cf, dhinfo[dh]->ui_ubanum);
		addr->un.dhcsrl = unit|((car>>12)&0x30)|DH_IE;
D 39
		DELAY(5);
E 39
D 52
		unit = 1 << unit;
		dhsar[dh] |= unit;
E 52
I 52
		/*
		 * The following nonsense with short word
		 * is to make sure the dhbar |= word below
		 * is done with an interlocking bisw2 instruction.
		 */
		{ short word = 1 << unit;
		dhsar[dh] |= word;
E 52
		addr->dhcar = car;
I 39
D 42
		DELAY(5);
E 42
E 39
E 34
E 31
		addr->dhbcr = -nch;
D 3
		dhcc[d] = nch;
E 3
D 31
		nch = 1<<(d&017);
E 31
I 31
D 34
		nch = 1<<(unit&017);
E 31
		addr->dhbar |= nch;
D 31
		dhsar[d>>4] |= nch;
E 31
I 31
		dhsar[dh] |= nch;
E 34
I 34
D 52
		addr->dhbar |= unit;
E 52
I 52
		addr->dhbar |= word;
		}
E 52
E 34
E 31
D 62
		tp->t_state |= BUSY;
E 62
I 62
		tp->t_state |= TS_BUSY;
E 62
	}
D 31
    out:
E 31
I 31
out:
E 31
	splx(s);
}

D 7

E 7
/*
D 34
 * Stop output on a line.
E 34
I 34
 * Stop output on a line, e.g. for ^S/^Q or output flush.
E 34
D 33
 * Assume call is made at spl6.
E 33
 */
/*ARGSUSED*/
dhstop(tp, flag)
D 34
register struct tty *tp;
E 34
I 34
	register struct tty *tp;
E 34
{
D 3
	register s;
E 3
I 3
D 35
	register struct device *addr;
E 35
I 35
	register struct dhdevice *addr;
E 35
D 31
	register d, s;
E 31
I 31
	register int unit, s;
E 31
E 3

I 3
D 35
	addr = (struct device *)tp->t_addr;
E 35
I 35
	addr = (struct dhdevice *)tp->t_addr;
E 35
E 3
D 34
	s = spl6();
E 34
I 34
	/*
	 * Block input/output interrupts while messing with state.
	 */
	s = spl5();
E 34
D 3
	if (tp->t_state & BUSY)
E 3
I 3
D 62
	if (tp->t_state & BUSY) {
E 62
I 62
	if (tp->t_state & TS_BUSY) {
E 62
I 34
		/*
		 * Device is transmitting; stop output
		 * by selecting the line and setting the byte
		 * count to -1.  We will clean up later
		 * by examining the address where the dh stopped.
		 */
E 34
D 31
		d = minor(tp->t_dev);
		addr->un.dhcsrl = (d&017) | IENAB;
E 31
I 31
		unit = minor(tp->t_dev);
D 33
		addr->un.dhcsrl = (unit&017) | IENAB;
E 33
I 33
		addr->un.dhcsrl = (unit&017) | DH_IE;
I 34
D 42
		DELAY(5);
E 42
E 34
E 33
E 31
E 3
D 62
		if ((tp->t_state&TTSTOP)==0)
			tp->t_state |= FLUSH;
E 62
I 62
		if ((tp->t_state&TS_TTSTOP)==0)
			tp->t_state |= TS_FLUSH;
E 62
I 3
		addr->dhbcr = -1;
	}
E 3
	splx(s);
}

I 3
D 4
int	minsilo = 16;
E 4
I 4
D 33
int	dhsilo = 16;
E 33
I 7
/*
D 33
 * Silo control is fixed strategy
 * here, paralleling only option available
 * on DZ-11.
 */
E 7
E 4
E 3
/*ARGSUSED*/
D 7
dhtimer(dev)
E 7
I 7
dhtimer()
E 7
{
D 4
register d,cc;
register struct device *addr;
E 4
I 4
D 7
	register d,cc;
E 7
I 7
D 31
	register d;
E 31
I 31
	register int dh;
E 31
E 7
	register struct device *addr;
I 31
	register struct uba_dinfo *ui;
E 31

E 4
D 31
	addr = DHADDR; d = 0;
E 31
I 31
	dh = 0;
E 31
	do {
D 4
		cc = dhchars[d];
		dhchars[d] = 0;
		if (cc > 8*DHTIME)
			cc = 32; else
			if (cc > 3*DHTIME)
				cc = 16; else
D 3
				cc = 0;
E 3
I 3
				cc = minsilo;
E 3
		addr->dhsilo = cc;
E 4
I 4
D 31
		if (dhact & (1<<d)) {
D 12
			addr->dhsilo = dhsilo;
E 12
I 12
			if ((dhisilo & (1<<d)) == 0) {
E 31
I 31
		ui = dhinfo[dh];
		addr = (struct device *)ui->ui_addr;
		if (dhact & (1<<dh)) {
			if ((dhisilo & (1<<dh)) == 0) {
E 31
				addr->dhsilo = dhsilo;
D 31
				dhisilo |= 1<<d;
E 31
I 31
				dhisilo |= 1<<dh;
E 31
			}
E 12
D 31
			dhrint(d);
E 31
I 31
			dhrint(dh);
E 31
		}
D 31
		d++;
E 4
		addr++;
I 2
D 3
		dhxint(d);		/* in case lost interrupt */
E 3
E 2
D 4
		dhrint(d++);
E 4
	} while (d < (NDH11+15)/16);
E 31
I 31
		dh++;
	} while (dh < NDH11);
E 31
I 12
}

/*
E 33
 * Reset state of driver if UBA reset was necessary.
 * Reset the csrl and lpr registers on open lines, and
 * restart transmitters.
 */
D 31
dhreset()
E 31
I 31
dhreset(uban)
I 34
	int uban;
E 34
E 31
{
D 31
	int d;
E 31
I 31
	register int dh, unit;
E 31
	register struct tty *tp;
D 32
	register struct device *addr;
E 32
I 31
D 46
	register struct uba_dinfo *ui;
E 46
I 46
	register struct uba_device *ui;
E 46
D 32
	int uba;
E 32
I 32
	int i;
E 32
E 31

D 31
	if (getcbase == 0)
		return;
E 31
I 31
D 32
	/*** WE SHOULD LOOK TO SEE IF UBA BEING RESET IS INTERESTING ***/

E 32
I 32
D 92
	if (dh_ubinfo[uban] == 0)
		return;
E 32
E 31
D 45
	printf(" dh");
E 45
D 13
	dhinit = 1;
E 13
D 32
	dhisilo = 0;
D 25
	ubafree(dh_ubinfo);
E 25
I 25
D 26
	UBAFREECLR(dh_ubinfo);
E 26
I 26
D 31
	ubarelse(&dh_ubinfo);
E 26
E 25
	dh_ubinfo = uballoc((caddr_t)cfree, NCLIST*sizeof (struct cblock), 0);
	cbase = (short)dh_ubinfo;
D 13
	for (d = 0; d < NDH11; d++) {
		tp = &dh11[d];
		if (tp->t_state & (ISOPEN|WOPEN))
			dhparam(d);
	}
	dhtimer();
E 13
	d = 0;
E 31
I 31
	for (uba = 0; uba < numuba; uba++)
		if (dh_ubinfo[uba]) {
			ubarelse(uba, &dh_ubinfo[uba]);
			dh_ubinfo[uba] = uballoc(uba, (caddr_t)cfree,
			    512+NCLIST*sizeof (struct cblock), 0);
			cbase[uba] = (short)dh_ubinfo;
		}
E 32
I 32
D 74
	ubarelse(uban, &dh_ubinfo[uban]);
E 74
	dh_ubinfo[uban] = uballoc(uban, (caddr_t)cfree,
D 44
	    512+NCLIST*sizeof (struct cblock), 0);
E 44
I 44
	    512+nclist*sizeof (struct cblock), 0);
E 44
	cbase[uban] = dh_ubinfo[uban]&0x3ffff;
E 92
D 33
	dhisilo = 0;		/* conservative */
E 33
E 32
	dh = 0;
E 31
D 32
	do {
D 31
		addr = DHADDR + d;
D 13
		addr->un.dhcsr |= IENAB;
E 13
		if (dhact & (1<<d))
D 13
			dhxint(d<<4);
E 13
I 13
			addr->un.dhcsr |= IENAB;
E 13
		d++;
	} while (d < (NDH11+15)/16);
D 13
	dhinit = 0;
E 13
I 13
	for (d = 0; d < NDH11; d++) {
		tp = &dh11[d];
E 31
I 31
		if (dhact & (1<<dh))
			((struct device *)dhinfo[dh]->ui_addr)->un.dhcsr |=
			    IENAB;
		dh++;
	} while (dh < NDH11);
	for (unit = 0; unit < NDH11*16; unit++) {
		tp = &dh11[unit];
E 31
		if (tp->t_state & (ISOPEN|WOPEN)) {
D 31
			dhparam(d);
			dmctl(d, TURNON, DMSET);
E 31
I 31
			dhparam(unit);
			dmctl(unit, TURNON, DMSET);
E 31
			tp->t_state &= ~BUSY;
			dhstart(tp);
E 32
I 32
D 41
	for (dh = 0; dh < NDH11; dh++) {
E 41
I 41
	for (dh = 0; dh < NDH; dh++) {
E 41
		ui = dhinfo[dh];
		if (ui == 0 || ui->ui_alive == 0 || ui->ui_ubanum != uban)
			continue;
I 45
		printf(" dh%d", dh);
I 92
D 94
		if (cbase[uban] == 0) {
E 94
I 94
D 98
		if (dh_ubinfo[uban]) {
E 94
			dh_ubinfo[uban] = uballoc(uban, (caddr_t)cfree,
			    nclist*sizeof (struct cblock), 0);
D 94
			cbase[uban] = dh_ubinfo[uban]&0x3ffff;
E 94
I 94
			cbase[uban] = UBAI_ADDR(dh_ubinfo[uban]);
E 98
I 98
		if (dh_uballoc[uban] == dh) {
			int info;

			info = uballoc(uban, (caddr_t)cfree,
			    nclist * sizeof(struct cblock), UBA_CANTWAIT);
			if (info)
				cbase[uban] = UBAI_ADDR(info);
			else {
				printf(" [can't get uba map]");
				cbase[uban] = -1;
			}
E 98
E 94
		}
E 92
E 45
D 33
		((struct device *)ui->ui_addr)->un.dhcsr |= IENAB;
E 33
I 33
D 35
		((struct device *)ui->ui_addr)->un.dhcsr |= DH_IE;
E 35
I 35
		((struct dhdevice *)ui->ui_addr)->un.dhcsr |= DH_IE;
I 56
D 58
#if NBK > 0
E 58
E 56
E 35
I 34
D 42
		DELAY(5);
E 42
E 34
D 35
		((struct device *)ui->ui_addr)->dhsilo = 16;
E 35
I 35
D 82
		((struct dhdevice *)ui->ui_addr)->dhsilo = 16;
E 82
I 82
		((struct dhdevice *)ui->ui_addr)->dhsilo = 0;
E 82
I 56
D 58
#endif
E 58
E 56
E 35
E 33
		unit = dh * 16;
		for (i = 0; i < 16; i++) {
			tp = &dh11[unit];
D 62
			if (tp->t_state & (ISOPEN|WOPEN)) {
E 62
I 62
			if (tp->t_state & (TS_ISOPEN|TS_WOPEN)) {
E 62
				dhparam(unit);
D 33
				dmctl(unit, TURNON, DMSET);
E 33
I 33
D 35
				dmctl(unit, DM_ON, DMSET);
E 35
I 35
				dmctl(unit, DML_ON, DMSET);
E 35
E 33
D 62
				tp->t_state &= ~BUSY;
E 62
I 62
				tp->t_state &= ~TS_BUSY;
E 62
				dhstart(tp);
			}
			unit++;
E 32
		}
	}
D 82
	dhtimer();
E 82
I 82
	dhsilos = 0;
E 82
I 33
}

I 82
int dhtransitions, dhslowtimers, dhfasttimers;		/*DEBUG*/
E 82
I 34
/*
D 82
 * At software clock interrupt time or after a UNIBUS reset
 * empty all the dh silos.
E 82
I 82
 * At software clock interrupt time, check status.
 * Empty all the dh silos that are in use, and decide whether
 * to turn any silos off or on.
E 82
 */
E 34
dhtimer()
{
D 82
	register int dh;
I 71
	register int s = spl5();
E 82
I 82
	register int dh, s;
	static int timercalls;
E 82
E 71

D 41
	for (dh = 0; dh < NDH11; dh++)
E 41
I 41
D 82
	for (dh = 0; dh < NDH; dh++)
E 41
		dhrint(dh);
I 71
	splx(s);
E 82
I 82
	if (dhsilos) {
		dhfasttimers++;		/*DEBUG*/
		timercalls++;
		s = spl5();
		for (dh = 0; dh < NDH; dh++)
			if (dhsilos & (1 << dh))
				dhrint(dh);
		splx(s);
	}
	if ((dhsilos == 0) || ((timercalls += FASTTIMER) >= hz)) {
		dhslowtimers++;		/*DEBUG*/
		timercalls = 0;
		for (dh = 0; dh < NDH; dh++) {
		    ave(dhrate[dh], dhchars[dh], 8);
		    if ((dhchars[dh] > dhhighrate) &&
		      ((dhsilos & (1 << dh)) == 0)) {
			((struct dhdevice *)(dhinfo[dh]->ui_addr))->dhsilo =
			    (dhchars[dh] > 500? 32 : 16);
			dhsilos |= (1 << dh);
			dhtransitions++;		/*DEBUG*/
		    } else if ((dhsilos & (1 << dh)) &&
		      (dhrate[dh] < dhlowrate)) {
			((struct dhdevice *)(dhinfo[dh]->ui_addr))->dhsilo = 0;
			dhsilos &= ~(1 << dh);
		    }
		    dhchars[dh] = 0;
		}
	}
	timeout(dhtimer, (caddr_t) 0, dhsilos? FASTTIMER: hz);
E 82
E 71
E 33
E 13
E 12
D 4
	timeout(dhtimer, (caddr_t)0, DHTIME);
E 4
}
I 24
D 31
#if DHDM > 0
E 31
I 31

D 34
#if DHDM
E 31
#include "../dev/dhdm.c"
#else
#include "../dev/dhfdm.c"
#endif
E 24
I 21
#endif
E 34
I 34
/*
D 35
 * DM-11 driver.
E 35
I 35
 * Turn on the line associated with dh dev.
E 35
 */
D 35

/*
 * Definition of the controller for the auto-configuration program.
 */
int	dmcntrlr(), dmslave(), dmintr();
struct	uba_dinfo *dminfo[NDH11];
u_short	dmstd[] = { 0 };
struct	uba_driver dmdriver =
	{ dmcntrlr, dmslave, 0, 0, dmstd, "dm", dminfo };

/* hardware bits */
#define	DM_CARRTRANS	040000		/* carrier transition */
#define	DM_CLSCAN	004000		/* clear scan */
#define	DM_DONE		000200
#define	DM_CARRON	000100		/* carrier on */
#define	DM_SCENABLE	000040		/* scan enable */
#define	DM_SCBUSY	000020		/* scan busy */

struct dmdevice
{
	short	dmcsr;
	short	dmlstat;
	short	dmpad1[2];
};

dmcntrlr(um, addr)
	struct uba_minfo *um;
	caddr_t addr;
{

}

dmslave()
{

}

/*
 * Turn on the line associated with the dh device dev.
 */
E 35
D 103
dmopen(dev)
E 103
I 103
dmopen(dev, flag)
E 103
	dev_t dev;
{
	register struct tty *tp;
	register struct dmdevice *addr;
D 46
	register struct uba_dinfo *ui;
E 46
I 46
	register struct uba_device *ui;
E 46
	register int unit;
	register int dm;
I 54
	int s;
E 54

	unit = minor(dev);
D 35
	dm = unit >> 8;
E 35
I 35
	dm = unit >> 4;
E 35
	tp = &dh11[unit];
D 37
	if (dm >= NDH11 || (ui = dminfo[dm]) == 0 || ui->ui_alive == 0) {
E 37
I 37
	unit &= 0xf;
D 41
	if (dm >= NDH11 || (ui = dminfo[dm]) == 0 || ui->ui_alive == 0 ||
E 41
I 41
D 83
	if (dm >= NDH || (ui = dminfo[dm]) == 0 || ui->ui_alive == 0 ||
E 41
	    (dhsoftCAR[dm]&(1<<unit))) {
E 83
I 83
	if (dm >= NDH || (ui = dminfo[dm]) == 0 || ui->ui_alive == 0) {
E 83
E 37
D 62
		tp->t_state |= CARR_ON;
E 62
I 62
		tp->t_state |= TS_CARR_ON;
E 62
		return;
	}
	addr = (struct dmdevice *)ui->ui_addr;
D 47
	spl5();
E 47
I 47
D 54
	(void) spl5();
E 54
I 54
	s = spl5();
E 54
E 47
D 35
	addr->dmcsr &= ~DM_SCENABLE;
	while (addr->dmcsr & DM_SCBUSY)
E 35
I 35
D 99
	addr->dmcsr &= ~DM_SE;
	while (addr->dmcsr & DM_BUSY)
E 35
		;
D 37
	addr->dmcsr = unit & 0xf;
E 37
I 37
	addr->dmcsr = unit;
E 37
D 35
	addr->dmlstat = DM_ON;
	if (addr->dmlstat&DM_CARRON)
E 35
I 35
	addr->dmlstat = DML_ON;
D 83
	if (addr->dmlstat&DML_CAR)
E 83
I 83
	if ((addr->dmlstat&DML_CAR) || (dhsoftCAR[dm]&(1<<unit)))
E 83
E 35
D 62
		tp->t_state |= CARR_ON;
E 62
I 62
		tp->t_state |= TS_CARR_ON;
E 62
D 35
	addr->dmcsr = DH_IE|DM_SCENABLE;
E 35
I 35
D 54
	addr->dmcsr = DH_IE|DM_SE;
E 54
I 54
	addr->dmcsr = DM_IE|DM_SE;
E 54
E 35
D 62
	while ((tp->t_state&CARR_ON)==0)
E 62
I 62
	while ((tp->t_state&TS_CARR_ON)==0)
E 99
I 99
	for (;;) {
		addr->dmcsr &= ~DM_SE;
		while (addr->dmcsr & DM_BUSY)
			;
		addr->dmcsr = unit;
		addr->dmlstat = DML_ON;
D 100
		if ((addr->dmlstat & DML_CAR) || (dhsoftCAR[dm] & (1 < unit)))
E 100
I 100
		if ((addr->dmlstat & DML_CAR) || (dhsoftCAR[dm] & (1 << unit)))
E 100
			tp->t_state |= TS_CARR_ON;
		addr->dmcsr = DM_IE|DM_SE;
D 103
		if (tp->t_state & TS_CARR_ON)
E 103
I 103
		if (tp->t_state & TS_CARR_ON || flag & FNDELAY)
E 103
			break;
E 99
E 62
		sleep((caddr_t)&tp->t_rawq, TTIPRI);
I 99
	}
E 99
D 47
	spl0();
E 47
I 47
D 54
	(void) spl0();
E 54
I 54
	splx(s);
E 54
E 47
}

/*
 * Dump control bits into the DM registers.
 */
dmctl(dev, bits, how)
	dev_t dev;
	int bits, how;
{
D 46
	register struct uba_dinfo *ui;
E 46
I 46
	register struct uba_device *ui;
E 46
	register struct dmdevice *addr;
	register int unit, s;
	int dm;

	unit = minor(dev);
	dm = unit >> 4;
	if ((ui = dminfo[dm]) == 0 || ui->ui_alive == 0)
		return;
	addr = (struct dmdevice *)ui->ui_addr;
	s = spl5();
D 35
	addr->dmcsr &= ~DM_SCENABLE;
	while (addr->dmcsr & DM_SCBUSY)
E 35
I 35
	addr->dmcsr &= ~DM_SE;
	while (addr->dmcsr & DM_BUSY)
E 35
		;
	addr->dmcsr = unit & 0xf;
	switch(how) {
	case DMSET:
		addr->dmlstat = bits;
		break;
	case DMBIS:
		addr->dmlstat |= bits;
		break;
	case DMBIC:
		addr->dmlstat &= ~bits;
		break;
I 105
	case DMGET:
		bits = addr->dmlstat;
E 105
	}
D 35
	addr->dmcsr = DH_IE|DM_SCENABLE;
E 35
I 35
D 54
	addr->dmcsr = DH_IE|DM_SE;
E 54
I 54
	addr->dmcsr = DM_IE|DM_SE;
E 54
E 35
	splx(s);
I 105
	return(bits);
E 105
}

/*
 * DM11 interrupt; deal with carrier transitions.
 */
dmintr(dm)
	register int dm;
{
D 46
	register struct uba_dinfo *ui;
E 46
I 46
	register struct uba_device *ui;
E 46
	register struct tty *tp;
	register struct dmdevice *addr;
I 83
	int unit;
E 83

	ui = dminfo[dm];
I 35
	if (ui == 0)
		return;
E 35
	addr = (struct dmdevice *)ui->ui_addr;
D 35
	if (addr->dmcsr&DM_DONE && addr->dmcsr&DM_CARRTRANS) {
E 35
I 35
D 57
	if (addr->dmcsr&DM_DONE && addr->dmcsr&DM_CF) {
E 35
		tp = &dh11[(dm<<4)+(addr->dmcsr&0xf)];
		wakeup((caddr_t)&tp->t_rawq);
		if ((tp->t_state&WOPEN)==0 &&
		    (tp->t_local&LMDMBUF)) {
D 35
			if (addr->dmlstat & DM_CARRON) {
E 35
I 35
			if (addr->dmlstat & DML_CAR) {
E 35
				tp->t_state &= ~TTSTOP;
				ttstart(tp);
			} else if ((tp->t_state&TTSTOP) == 0) {
				tp->t_state |= TTSTOP;
				dhstop(tp, 0);
			}
D 35
		} else if ((addr->dmlstat&DM_CARRON)==0) {
E 35
I 35
		} else if ((addr->dmlstat&DML_CAR)==0) {
E 57
I 57
	if (addr->dmcsr&DM_DONE) {
I 105
		unit = addr->dmcsr & 0xf;
		tp = &dh11[(dm << 4) + unit];
E 105
		if (addr->dmcsr&DM_CF) {
D 83
			tp = &dh11[(dm<<4)+(addr->dmcsr&0xf)];
E 83
I 83
D 105
			unit = addr->dmcsr & 0xf;
			tp = &dh11[(dm << 4) + unit];
E 105
E 83
D 91
			wakeup((caddr_t)&tp->t_rawq);
E 57
E 35
D 62
			if ((tp->t_state&WOPEN)==0 &&
E 62
I 62
D 75
			if ((tp->t_state&TS_WOPEN)==0 &&
E 62
D 57
			    (tp->t_local&LNOHANG)==0) {
				gsignal(tp->t_pgrp, SIGHUP);
				gsignal(tp->t_pgrp, SIGCONT);
				addr->dmlstat = 0;
				flushtty(tp, FREAD|FWRITE);
			}
			tp->t_state &= ~CARR_ON;
		} else
			tp->t_state |= CARR_ON;
E 57
I 57
			    (tp->t_local&LMDMBUF)) {
E 75
I 75
			if ((tp->t_state&TS_WOPEN) == 0 &&
D 76
			    (tp->t_mode & MDMBUF)) {
E 76
I 76
			    (tp->t_flags & MDMBUF)) {
E 76
E 75
				if (addr->dmlstat & DML_CAR) {
D 62
					tp->t_state &= ~TTSTOP;
E 62
I 62
					tp->t_state &= ~TS_TTSTOP;
E 62
					ttstart(tp);
D 62
				} else if ((tp->t_state&TTSTOP) == 0) {
					tp->t_state |= TTSTOP;
E 62
I 62
				} else if ((tp->t_state&TS_TTSTOP) == 0) {
					tp->t_state |= TS_TTSTOP;
E 62
					dhstop(tp, 0);
				}
D 87
			} else if ((addr->dmlstat&DML_CAR)==0) {
D 62
				if ((tp->t_state&WOPEN)==0 &&
E 62
I 62
				if ((tp->t_state&TS_WOPEN)==0 &&
E 87
I 87
			} else if ((addr->dmlstat & DML_CAR)==0) {
				if ((tp->t_state & TS_CARR_ON) &&
E 87
E 62
D 75
				    (tp->t_local&LNOHANG)==0) {
E 75
I 75
D 76
				    (tp->t_mode & NOHANG) == 0) {
E 76
I 76
D 83
				    (tp->t_flags & NOHANG) == 0) {
E 83
I 83
				    (tp->t_flags & NOHANG) == 0 &&
				    (dhsoftCAR[dm] & (1<<unit)) == 0) {
E 83
E 76
E 75
D 87
					gsignal(tp->t_pgrp, SIGHUP);
					gsignal(tp->t_pgrp, SIGCONT);
					addr->dmlstat = 0;
D 79
					flushtty(tp, FREAD|FWRITE);
E 79
I 79
					ttyflush(tp, FREAD|FWRITE);
E 87
I 87
					if (tp->t_state & TS_ISOPEN) {
						gsignal(tp->t_pgrp, SIGHUP);
						gsignal(tp->t_pgrp, SIGCONT);
						addr->dmlstat = 0;
						ttyflush(tp, FREAD|FWRITE);
					}
					tp->t_state &= ~TS_CARR_ON;
E 87
E 79
				}
D 62
				tp->t_state &= ~CARR_ON;
E 62
I 62
D 87
				tp->t_state &= ~TS_CARR_ON;
E 87
E 62
			} else
D 62
				tp->t_state |= CARR_ON;
E 62
I 62
				tp->t_state |= TS_CARR_ON;
E 91
I 91
			if (addr->dmlstat & DML_CAR)
				(void)(*linesw[tp->t_line].l_modem)(tp, 1);
			else if ((dhsoftCAR[dm] & (1<<unit)) == 0 &&
			    (*linesw[tp->t_line].l_modem)(tp, 0) == 0)
				addr->dmlstat = 0;
I 105
		}
		tp->t_state |= TS_MODEMCHG;
		if (tp->t_rsel) {
			selwakeup(tp->t_rsel, tp->t_state & TS_RCOLL);
			tp->t_rsel = 0;
			tp->t_state &= ~TS_RCOLL;
E 105
E 91
E 62
		}
		addr->dmcsr = DM_IE|DM_SE;
E 57
D 35
		addr->dmcsr = DH_IE|DM_SCENABLE;
E 35
I 35
D 54
		addr->dmcsr = DH_IE|DM_SE;
E 54
E 35
	}
I 54
D 57
	addr->dmcsr = DM_IE|DM_SE;
E 57
E 54
}
I 40
#endif
E 40
E 34
E 21
E 1
