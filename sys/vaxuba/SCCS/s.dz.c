h32473
s 00001/00001/00662
d D 7.4 04/12/09 23:56:31 msokolov 85 84
c FNDELAY support
e
s 00001/00001/00662
d D 7.3 03/03/16 04:03:10 msokolov 84 83
c Don't interpret output high chars as delays in PASS8 mode
e
s 00002/00000/00661
d D 7.2 87/01/14 08:47:33 karels 83 82
c don't need to wait for dzscan if softCAR is set
e
s 00001/00001/00660
d D 7.1 86/06/05 01:09:25 mckusick 82 81
c 4.3BSD release version
e
s 00011/00003/00650
d D 6.11 86/04/12 14:10:45 karels 81 80
c revert to "sticky" baudrate except for portselector
e
s 00012/00033/00641
d D 6.10 85/11/04 18:20:30 karels 80 79
c move carrier change code to line disciplines; make PORTSELECTOR
c code and configuration consistent; change default speed to 9600
e
s 00001/00001/00673
d D 6.9 85/09/17 18:34:53 eric 79 78
c facilities in syslog
e
s 00001/00001/00673
d D 6.8 85/08/13 05:10:03 lepreau 78 77
c add PASS8: pass all 8 bits of input
e
s 00007/00001/00667
d D 6.7 85/06/08 14:16:02 mckusick 77 76
c Add copyright
e
s 00002/00001/00666
d D 6.6 85/03/12 14:23:31 ralph 76 75
c change silo overflow printf's to log's.
e
s 00002/00001/00665
d D 6.5 84/12/20 15:55:21 bloom 75 74
c call param routine when ioctls change hardware configuration
e
s 00018/00018/00648
d D 6.4 84/08/30 11:42:36 bloom 74 73
c changes to includes.  no more ../h
e
s 00002/00002/00664
d D 6.3 84/04/16 14:47:54 sam 73 72
c dzpdma structures indexed by line, not controller
e
s 00040/00009/00626
d D 6.2 84/03/15 14:43:44 karels 72 71
c use silos only when input rate is high
e
s 00000/00000/00635
d D 6.1 83/07/29 07:27:30 sam 71 70
c 4.2 distribution
e
s 00002/00002/00633
d D 4.51 83/05/27 13:52:16 sam 70 69
c lint
e
s 00001/00000/00634
d D 4.50 83/02/10 18:43:43 sam 69 68
c hz not in systm.h anymore
e
s 00012/00094/00622
d D 4.49 82/12/30 14:10:56 sam 68 67
c yank definitions out
e
s 00003/00001/00713
d D 4.48 82/12/17 12:02:01 sam 67 66
c sun merge
e
s 00005/00004/00709
d D 4.47 82/12/05 21:48:11 sam 66 65
c reorganized tty structuer
e
s 00016/00015/00697
d D 4.46 82/10/17 11:48:48 root 65 64
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00001/00001/00711
d D 4.45 82/10/13 22:42:05 root 64 63
c l_write returns a value; pass it on
e
s 00003/00002/00709
d D 4.44 82/10/10 17:27:02 root 63 62
c header files for vax are in their place
e
s 00003/00001/00708
d D 4.43 82/09/12 03:06:44 root 62 61
c physio returns error, not in u.u_error
e
s 00003/00002/00706
d D 4.42 82/08/22 21:17:48 root 61 60
c fully uio()'d
e
s 00004/00002/00704
d D 4.41 82/08/13 00:15:20 root 60 59
c changes for char dev uio'ing
e
s 00017/00021/00689
d D 4.40 82/08/01 19:24:47 sam 59 58
c new ioctl's
e
s 00002/00002/00708
d D 4.39 82/07/15 19:55:50 kre 58 57
c probe routines return size of unibus dev regs to reserve space
e
s 00001/00001/00709
d D 4.38 82/05/19 00:53:58 wnj 57 56
c fixes for close when never opened (from research!ark)
e
s 00001/00001/00709
d D 4.37 82/05/12 17:31:39 wnj 56 55
c allow 19200 baud
e
s 00013/00002/00697
d D 4.36 82/05/04 13:38:16 sam 55 54
c CAD kludges and cleanup conf.c
e
s 00013/00012/00686
d D 4.35 82/03/13 12:50:23 sam 54 53
c lint
e
s 00001/00001/00697
d D 4.34 82/03/12 16:19:11 sam 53 52
c lint
e
s 00257/00056/00441
d D 4.33 82/02/08 23:01:13 root 52 51
c now supports DZ32 -- from decvax!shannon
e
s 00035/00028/00462
d D 4.32 82/01/14 17:05:25 wnj 51 50
c early non-blocking stuff
e
s 00002/00001/00488
d D 4.31 81/11/18 15:49:18 wnj 50 49
c lint
e
s 00001/00006/00488
d D 4.30 81/11/08 17:13:30 wnj 49 47
c restore berknet
e
s 00002/00015/00479
d R 4.30 81/10/11 11:47:57 wnj 48 47
c first boot with select()
e
s 00000/00004/00494
d D 4.29 81/08/31 01:15:53 root 47 46
c fix to silo and bk bug
e
s 00001/00001/00497
d D 4.28 81/07/25 21:40:46 wnj 46 45
c restore id keywords
e
s 00001/00002/00497
d D 4.27 81/07/25 21:39:50 wnj 45 44
c remove spurious return(1) from dzattach
e
s 00001/00001/00498
d D 4.26 81/05/29 17:02:57 wnj 44 43
c bug fix per shannon
e
s 00001/00001/00498
d D 4.25 81/05/09 19:47:10 root 43 42
c llitout fix
e
s 00005/00001/00494
d D 4.24 81/04/02 15:12:18 root 42 41
c conditional silos on NBK
e
s 00001/00001/00494
d D 4.23 81/03/09 01:52:50 wnj 41 40
c %G% -> %E%
e
s 00001/00002/00494
d D 4.22 81/03/09 00:33:30 wnj 40 39
c lint
e
s 00004/00004/00492
d D 4.21 81/03/07 14:27:27 wnj 39 38
c after attempt at ht driver at cc again; working with new 
c field names
e
s 00007/00007/00489
d D 4.20 81/03/06 11:30:44 wnj 38 37
c cleaner silo overrun prints; print unit number when reset
e
s 00002/00002/00494
d D 4.19 81/02/27 03:14:25 wnj 37 36
c s/HZ/hz/
e
s 00003/00000/00493
d D 4.18 81/02/26 22:20:04 wnj 36 35
c conditionally discard NETLDISC cruft
e
s 00011/00011/00482
d D 4.17 81/02/23 23:44:31 wnj 35 34
c minor typos
e
s 00006/00004/00487
d D 4.16 81/02/23 20:14:53 wnj 34 33
c check for dzaddr 0 during scan... init timer at configure time
e
s 00011/00015/00480
d D 4.15 81/02/21 21:20:35 wnj 33 32
c first working uba interlockable version
e
s 00005/00006/00490
d D 4.14 81/02/19 21:57:55 wnj 32 31
c almost working ubago version (tm.c problems)
e
s 00076/00050/00420
d D 4.13 81/02/17 17:33:36 wnj 31 30
c minor cleanups... for dh: DELAY(5)s
e
s 00058/00073/00412
d D 4.12 81/02/16 20:55:57 wnj 30 29
c cleanup with new soft interrupts and new ctlr scheme
e
s 00026/00035/00459
d D 4.11 81/02/15 12:09:10 kre 29 28
c bootable autoconf version
e
s 00132/00115/00362
d D 4.10 81/02/10 13:19:24 wnj 28 27
c compilable first uba autoconf version
e
s 00001/00001/00476
d D 4.9 81/02/08 01:13:33 wnj 27 26
c last pre-mba version
e
s 00001/00001/00476
d D 4.8 81/01/28 11:42:17 wnj 26 25
c 8 bits both in raw and litout
e
s 00001/00001/00476
d D 4.7 81/01/26 21:19:15 toy 25 24
c Changed param routine to set BITS8 if LLITOUT is set
e
s 00007/00001/00470
d D 4.6 81/01/19 15:56:26 toy 24 23
c Added reset of TIOCSBRK in dzclose.  (MCT)
e
s 00001/00001/00470
d D 4.5 80/12/19 11:43:44 wnj 23 22
c s,../conf/,,
e
s 00001/00001/00470
d D 4.4 80/12/17 10:35:21 wnj 22 21
c change to ttioctl arguments per greg
e
s 00000/00001/00471
d D 4.3 80/11/10 00:27:31 bill 21 20
c remove more lint
e
s 00001/00000/00471
d D 4.2 80/11/09 23:12:47 bill 20 19
c include ../h/mx.h for lint's sake
e
s 00000/00000/00471
d D 4.1 80/11/09 16:52:19 bill 19 18
c stamp for 4bsd
e
s 00003/00003/00468
d D 3.18 80/10/22 08:21:19 bill 18 17
c s/NDZ/NDZ11/ if #if's for pdma
e
s 00003/00006/00468
d D 3.17 80/10/19 22:15:40 bill 17 16
c ../conf/*.h
e
s 00002/00002/00472
d D 3.16 80/09/27 18:00:04 bill 16 15
c 4dz's plus LOWAT and HIWAT ala speed
e
s 00001/00001/00473
d D 3.15 80/09/20 20:39:07 bill 15 14
c ttioctl
e
s 00035/00009/00439
d D 3.14 80/09/16 17:28:19 bill 14 13
c fix break bug and other minor iiasa fixes
e
s 00002/00001/00446
d D 3.13 80/09/14 13:14:16 bill 13 12
c flushtty w/2 args
e
s 00004/00010/00443
d D 3.12 80/06/23 17:36:11 bill 12 11
c cleanup reset code
e
s 00030/00001/00423
d D 3.11 80/06/22 12:27:11 bill 11 10
c dzreset
e
s 00001/00001/00423
d D 3.10 80/06/07 02:45:18 bill 10 9
c %H%->%G%
e
s 00002/00002/00422
d D 3.9 80/06/02 12:38:35 bill 9 8
c 
e
s 00001/00004/00423
d D 3.8 80/05/24 19:43:30 bill 8 7
c bug fix
e
s 00005/00001/00422
d D 3.7 80/05/18 11:32:31 bill 7 6
c send t_intrc on break
e
s 00028/00009/00395
d D 3.6 80/05/15 16:57:46 bill 6 5
c iiasa fixup
e
s 00015/00000/00389
d D 3.5 80/05/09 20:55:23 bill 5 4
c run spl6 for dz SAE
e
s 00004/00001/00385
d D 3.4 80/05/09 13:51:14 bill 4 3
c silo service code protected at spl6
e
s 00040/00020/00346
d D 3.3 80/05/08 10:04:55 bill 3 2
c code which doesn't take receiver interrupts
e
s 00014/00004/00352
d D 3.2 80/05/06 19:47:55 bill 2 1
c first working networked version
e
s 00356/00000/00000
d D 3.1 80/04/09 16:03:08 bill 1 0
c date and time created 80/04/09 16:03:08 by bill
e
u
U
t
T
I 1
D 10
/*	%M%	%I%	%H%	*/
E 10
I 10
D 41
/*	%M%	%I%	%G%	*/
E 41
I 41
D 45
/*	%M%	%I%	%E%	*/
E 45
I 45
D 46
/*	dz.c	4.26	81/05/29	*/
E 46
I 46
D 77
/*	%M%	%I%	%E%	*/
E 77
I 77
/*
D 82
 * Copyright (c) 1982 Regents of the University of California.
E 82
I 82
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 82
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 77
E 46
E 45
E 41
E 10

I 17
D 23
#include "../conf/dz.h"
E 23
I 23
#include "dz.h"
E 23
D 35
#if NDZ11 > 0
E 35
I 35
#if NDZ > 0
E 35
I 30
D 40
#define	DELAY(i)	{ register int j = i; while (--j > 0); }
E 40
E 30
E 17
/*
D 50
 *  DZ-11 Driver
E 50
I 50
D 52
 * DZ-11 Driver
E 52
I 52
D 68
 *  DZ-11 and DZ32 Driver
E 68
I 68
 *  DZ-11/DZ-32 Driver
E 68
E 52
E 50
I 31
 *
 * This driver mimics dh.c; see it for explanation of common code.
E 31
 */
I 36
#include "bk.h"
I 67

#include "../machine/pte.h"

E 67
E 36
D 74
#include "../h/param.h"
#include "../h/systm.h"
I 66
#include "../h/ioctl.h"
E 66
#include "../h/tty.h"
#include "../h/dir.h"
#include "../h/user.h"
I 54
#include "../h/proc.h"
E 54
#include "../h/map.h"
D 67
#include "../h/pte.h"
E 67
I 28
#include "../h/buf.h"
I 32
#include "../h/vm.h"
E 32
E 28
D 39
#include "../h/uba.h"
E 39
I 39
D 63
#include "../h/ubavar.h"
E 63
E 39
#include "../h/conf.h"
D 63
#include "../h/pdma.h"
E 63
I 2
#include "../h/bk.h"
I 13
#include "../h/file.h"
I 60
#include "../h/uio.h"
I 69
#include "../h/kernel.h"
E 74
I 74
#include "param.h"
#include "systm.h"
#include "ioctl.h"
#include "tty.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "conf.h"
#include "bkmac.h"
#include "file.h"
#include "uio.h"
#include "kernel.h"
I 76
#include "syslog.h"
E 76
E 74
E 69
I 63

D 74
#include "../vaxuba/pdma.h"
#include "../vaxuba/ubavar.h"
I 68
#include "../vaxuba/dzreg.h"
E 74
I 74
#include "pdma.h"
#include "ubavar.h"
#include "dzreg.h"
E 74
E 68
E 63
E 60
I 20
D 49
#include "../h/mx.h"
E 49
E 20
E 13
I 5

I 31
/*
 * Driver information for auto-configuration stuff.
 */
E 31
D 30
/*
 * When running dz's using only SAE (silo alarm) on input
 * it is necessary to call dzrint() at clock interrupt time.
 * This is unsafe unless spl5()s in tty code are changed to
 * spl6()s to block clock interrupts.  Note that the dh driver
 * currently in use works the same way as the dz, even though
 * we could try to more intelligently manage its silo.
 * Thus don't take this out if you have no dz's unless you
 * change clock.c and dhtimer().
I 28
 *
 * SHOULD RATHER QUEUE SOFTWARE INTERRUPT AT CLOCK TIME.
E 28
 */
#define	spl5	spl6
E 5
E 2
 
E 30
I 28
D 33
int	dzcntrlr(), dzslave(), dzrint();
E 33
I 33
int	dzprobe(), dzattach(), dzrint();
E 33
D 35
struct	uba_dinfo *dzinfo[NDZ11];
E 35
I 35
D 39
struct	uba_dinfo *dzinfo[NDZ];
E 39
I 39
struct	uba_device *dzinfo[NDZ];
E 39
E 35
u_short	dzstd[] = { 0 };
D 29
int	(*dzivec[])() = { dzrint, 0 }; /* omit dzxint so we can do it here */
E 29
struct	uba_driver dzdriver =
D 29
	{ dzcntrlr, dzslave, (int (*)())0, 0, 0, dzstd, dzinfo, dzivec };
E 29
I 29
D 30
	{ dzcntrlr, dzslave, (int (*)())0, 0, 0, dzstd, "dz", dzinfo };
E 30
I 30
D 33
	{ dzcntrlr, dzslave, 0, 0, dzstd, "dz", dzinfo };
E 33
I 33
	{ dzprobe, 0, dzattach, 0, dzstd, "dz", dzinfo };
E 33
E 30
E 29

E 28
D 17
#define DZADDR  (UBA0_DEV + 0160100)
D 14
#ifdef ERNIE
#define NDZ 	(3*8)
E 14
I 14
#ifdef DISTRIB
#define	NDZ11	1
E 14
#else
D 14
#define	NDZ	(8)
E 14
I 14
D 16
#define NDZ11	3
E 16
I 16
#define NDZ11	4
E 16
E 14
#endif
E 17
I 14
D 30
#define NDZ 	(NDZ11*8)
E 30
I 30
D 35
#define	NDZ 	(NDZ11*8)
E 35
I 35
#define	NDZLINE 	(NDZ*8)
I 72
#define	FASTTIMER	(hz/30)		/* rate to drain silos, when in use */
E 72
E 35
E 30
E 14
D 68
 
I 31
/*
 * Registers and bits
 */
E 68

D 52
/* Bits in dzlpr */
E 31
D 30
#define BITS7	020
#define BITS8	030
#define TWOSB	040
#define PENABLE	0100
#define OPAR	0200
E 30
I 30
#define	BITS7	020
#define	BITS8	030
#define	TWOSB	040
E 52
I 52
D 68
/* bits in dzlpr */
#define	BITS7	0020
#define	BITS8	0030
#define	TWOSB	0040
E 52
#define	PENABLE	0100
#define	OPAR	0200
E 30
I 29
D 31
#define	CLR	020		/* Reset dz */
E 29
D 30
#define MSE	040		/* Master Scan Enable */
#define RIE	0100		/* Receiver Interrupt Enable */
E 30
I 30
#define	MSE	040		/* Master Scan Enable */
#define	RIE	0100		/* Receiver Interrupt Enable */
E 30
D 3
#define TIE	040000		/* Transmit interrupt enable */
#define DZ_IEN	(MSE+RIE+TIE)
E 3
I 3
#define	SAE	010000		/* Silo Alarm Enable */
D 30
#define TIE	040000		/* Transmit Interrupt Enable */
#define DZ_IEN	(MSE+RIE+TIE+SAE)
E 3
#define PERROR	010000
#define FRERROR	020000
E 30
I 30
#define	TIE	040000		/* Transmit Interrupt Enable */
#define	DZ_IEN	(MSE+RIE+TIE+SAE)
#define	PERROR	010000
#define	FRERROR	020000
E 30
I 3
#define	OVERRUN	040000
E 3
D 30
#define SSPEED	7		/* std speed = 300 baud */
E 30
I 30
#define	SSPEED	7		/* std speed = 300 baud */
E 31
E 30

D 28
 
E 28
D 31
#define	dzlpr	dzrbuf
D 30
#define dzmsr	dzbrk
#define ON	1
#define OFF	0
E 30
I 30
#define	dzmsr	dzbrk
#define	ON	1
#define	OFF	0
E 31
I 31
D 52
/* Bits in dzrbuf */
E 52
I 52
/* bits in dzrbuf */
E 52
#define	DZ_PE	010000
#define	DZ_FE	020000
#define	DZ_DO	040000

D 52
/* Bits in dzcsr */
#define	DZ_CLR	020		/* Reset dz */
#define	DZ_MSE	040		/* Master Scan Enable */
#define	DZ_RIE	0100		/* Receiver Interrupt Enable */
E 52
I 52
/* bits in dzcsr */
#define	DZ_32	000001		/* DZ32 mode */
#define	DZ_MIE	000002		/* Modem Interrupt Enable */
#define	DZ_CLR	000020		/* Reset dz */
#define	DZ_MSE	000040		/* Master Scan Enable */
#define	DZ_RIE	000100		/* Receiver Interrupt Enable */
#define DZ_MSC	004000		/* Modem Status Change */
E 52
#define	DZ_SAE	010000		/* Silo Alarm Enable */
#define	DZ_TIE	040000		/* Transmit Interrupt Enable */
D 42
#define	DZ_IEN	(DZ_MSE+DZ_RIE+DZ_TIE+DZ_SAE)
E 42
I 42
D 47
#if NBK == 0
#define	DZ_IEN	(DZ_MSE|DZ_RIE|DZ_TIE)
#else
E 47
D 52
#define	DZ_IEN	(DZ_MSE|DZ_RIE|DZ_TIE|DZ_SAE)
E 52
I 52
#define	DZ_IEN	(DZ_32|DZ_MIE|DZ_MSE|DZ_RIE|DZ_TIE|DZ_SAE)
E 52
D 47
#endif
E 47
E 42

D 52
/* Flags for modem-control */
#define	DZ_ON	1
E 52
I 52
/* flags for modem-control */
#define	DZ_ON	DZ_DTR
E 52
#define	DZ_OFF	0
I 52

/* bits in dzlcs */
#define DZ_ACK	0100000		/* ACK bit in dzlcs */
#define DZ_RTS	0010000		/* Request To Send */
#define	DZ_ST	0004000		/* Secondary Transmit */
#define	DZ_BRK	0002000		/* Break */
#define DZ_DTR	0001000		/* Data Terminal Ready */
#define	DZ_LE	0000400		/* Line Enable */
#define	DZ_DSR	0000200		/* Data Set Ready */
#define	DZ_RI	0000100		/* Ring Indicate */
#define DZ_CD	0000040		/* Carrier Detect */
#define	DZ_CTS	0000020		/* Clear To Send */
#define	DZ_SR	0000010		/* Secondary Receive */
E 52
E 31
E 30
 
I 52
/* bits in dm lsr, copied from dh.c */
#define	DML_DSR		0000400		/* data set ready, not a real DM bit */
#define	DML_RNG		0000200		/* ring */
#define	DML_CAR		0000100		/* carrier detect */
#define	DML_CTS		0000040		/* clear to send */
#define	DML_SR		0000020		/* secondary receive */
#define	DML_ST		0000010		/* secondary transmit */
#define	DML_RTS		0000004		/* request to send */
#define	DML_DTR		0000002		/* data terminal ready */
#define	DML_LE		0000001		/* line enable */

E 68
E 52
D 31
int	dzstart();
int	dzxint();
I 28
int	dzdma();
E 31
I 31
int	dzstart(), dzxint(), dzdma();
E 31
E 28
I 2
int	ttrstrt();
E 2
D 35
struct	tty dz_tty[NDZ];
int	dz_cnt = { NDZ };
E 35
I 35
struct	tty dz_tty[NDZLINE];
int	dz_cnt = { NDZLINE };
E 35
I 3
int	dzact;
I 72
int	dzsilos;			/* mask of dz's with silo in use */
int	dzchars[NDZ];			/* recent input count */
int	dzrate[NDZ];			/* smoothed input count */
int	dztimerintvl;			/* time interval for dztimer */
int	dzhighrate = 100;		/* silo on if dzchars > dzhighrate */
int	dzlowrate = 75;			/* silo off if dzrate < dzlowrate */
E 72
I 11
D 21
int	dzinit;
E 21
D 12
int	dzdtr[(NDZ+7)/8];
E 12
E 11
E 3

D 68
struct device {
D 31
	short	dzcsr;
	short	dzrbuf;
	char	dztcr;
	char	dzdtr;
	char	dztbuf;
	char	dzbrk;
E 31
I 31
D 52
	short	dzcsr;		/* control-status register */
	short	dzrbuf;		/* receiver buffer */
#define	dzlpr	dzrbuf		/* line parameter reg is write of dzrbuf */
	char	dztcr;		/* transmit control register */
	char	dzdtr;		/* data terminal ready */
	char	dztbuf;		/* transmit buffer */
	char	dzbrk;		/* break control */
#define	dzmsr	dzbrk		/* modem status register */
E 52
I 52
	short dzcsr;
	short dzrbuf;
	union {
		struct {
			char	dztcr0;
			char	dzdtr0;
			char	dztbuf0;
			char	dzbrk0;
		} dz11;
		struct {
			short	dzlcs0;
			char	dztbuf0;
			char	dzlnen0;
		} dz32;
	} dzun;
E 52
E 31
};
I 52

#define dzlpr	dzrbuf
#define dzmsr	dzun.dz11.dzbrk0
#define dztcr	dzun.dz11.dztcr0
#define dzdtr	dzun.dz11.dzdtr0
#define dztbuf	dzun.dz11.dztbuf0
#define dzlcs	dzun.dz32.dzlcs0
#define	dzbrk	dzmsr
#define dzlnen	dzun.dz32.dzlnen0
D 58
#define dzmtsr	dzun.dz32.dztbuf0;
E 58
I 58
#define dzmtsr	dzun.dz32.dztbuf0
E 58

E 68
#define dzwait(x)	while (((x)->dzlcs & DZ_ACK) == 0)

E 52
I 31
/*
 * Software copy of dzbrk since it isn't readable
 */
D 35
char	dz_brk[NDZ11];
I 32
char	dzsoftCAR[NDZ11];
E 35
I 35
char	dz_brk[NDZ];
char	dzsoftCAR[NDZ];
I 52
char	dz_lnen[NDZ];	/* saved line enable bits for DZ32 */
E 52
E 35
E 32
E 31

I 31
/*
D 52
 * The dz doesn't interrupt on carrier transitions, so
E 52
I 52
 * The dz11 doesn't interrupt on carrier transitions, so
E 52
 * we have to use a timer to watch it.
 */
char	dz_timer;		/* timer started? */

/*
 * Pdma structures for fast output code
 */
E 31
D 28
struct pdma dzpdma[] = {
	(struct device *)(DZADDR), NULL, NULL, (int)&dz_tty[0], dzxint,
	(struct device *)(DZADDR), NULL, NULL, (int)&dz_tty[1], dzxint,
	(struct device *)(DZADDR), NULL, NULL, (int)&dz_tty[2], dzxint,
	(struct device *)(DZADDR), NULL, NULL, (int)&dz_tty[3], dzxint,
	(struct device *)(DZADDR), NULL, NULL, (int)&dz_tty[4], dzxint,
	(struct device *)(DZADDR), NULL, NULL, (int)&dz_tty[5], dzxint,
	(struct device *)(DZADDR), NULL, NULL, (int)&dz_tty[6], dzxint,
	(struct device *)(DZADDR), NULL, NULL, (int)&dz_tty[7], dzxint,
D 14
#ifdef ERNIE
E 14
I 14
D 18
#if NDZ >= 2
E 18
I 18
#if NDZ11 >= 2
E 18
E 14
	(struct device *)(DZADDR+010), NULL, NULL, (int)&dz_tty[8], dzxint,
	(struct device *)(DZADDR+010), NULL, NULL, (int)&dz_tty[9], dzxint,
	(struct device *)(DZADDR+010), NULL, NULL, (int)&dz_tty[10], dzxint,
	(struct device *)(DZADDR+010), NULL, NULL, (int)&dz_tty[11], dzxint,
	(struct device *)(DZADDR+010), NULL, NULL, (int)&dz_tty[12], dzxint,
	(struct device *)(DZADDR+010), NULL, NULL, (int)&dz_tty[13], dzxint,
	(struct device *)(DZADDR+010), NULL, NULL, (int)&dz_tty[14], dzxint,
	(struct device *)(DZADDR+010), NULL, NULL, (int)&dz_tty[15], dzxint,
I 14
#endif
D 18
#if NDZ >= 3
E 18
I 18
#if NDZ11 >= 3
E 18
E 14
	(struct device *)(DZADDR+020), NULL, NULL, (int)&dz_tty[16], dzxint,
	(struct device *)(DZADDR+020), NULL, NULL, (int)&dz_tty[17], dzxint,
	(struct device *)(DZADDR+020), NULL, NULL, (int)&dz_tty[18], dzxint,
	(struct device *)(DZADDR+020), NULL, NULL, (int)&dz_tty[19], dzxint,
	(struct device *)(DZADDR+020), NULL, NULL, (int)&dz_tty[20], dzxint,
	(struct device *)(DZADDR+020), NULL, NULL, (int)&dz_tty[21], dzxint,
	(struct device *)(DZADDR+020), NULL, NULL, (int)&dz_tty[22], dzxint,
	(struct device *)(DZADDR+020), NULL, NULL, (int)&dz_tty[23], dzxint,
#endif
I 14
D 18
#if NDZ >= 4
E 18
I 18
#if NDZ11 >= 4
E 18
	(struct device *)(DZADDR+030), NULL, NULL, (int)&dz_tty[24], dzxint,
	(struct device *)(DZADDR+030), NULL, NULL, (int)&dz_tty[25], dzxint,
	(struct device *)(DZADDR+030), NULL, NULL, (int)&dz_tty[26], dzxint,
	(struct device *)(DZADDR+030), NULL, NULL, (int)&dz_tty[27], dzxint,
	(struct device *)(DZADDR+030), NULL, NULL, (int)&dz_tty[28], dzxint,
	(struct device *)(DZADDR+030), NULL, NULL, (int)&dz_tty[29], dzxint,
	(struct device *)(DZADDR+030), NULL, NULL, (int)&dz_tty[30], dzxint,
	(struct device *)(DZADDR+030), NULL, NULL, (int)&dz_tty[31], dzxint,
#endif
E 14
};
E 28
I 28
D 35
struct	pdma dzpdma[NDZ];
E 35
I 35
struct	pdma dzpdma[NDZLINE];
E 35
E 28
D 31
char	dz_timer;
E 31
I 31

E 31
D 28
char	dz_speeds[] = {
	0, 020 , 021 , 022 , 023 , 024 , 0, 025,
	026 , 027 , 030 , 032 , 034 , 036 , 0 , 0,
};
I 24
char dz_brk[NDZ11];
E 28
I 28
char	dz_speeds[] =
D 56
	{ 0,020,021,022,023,024,0,025,026,027,030,032,034,036,0,0 };
E 56
I 56
	{ 0,020,021,022,023,024,0,025,026,027,030,032,034,036,037,0 };
E 56
D 31
char	dz_brk[NDZ11];
E 31
E 28
E 24
 
I 55
D 80
#ifndef PORTSELECTOR
#define	ISPEED	B300
E 80
I 80
#ifndef	PORTSELECTOR
#define	ISPEED	B9600
E 80
#define	IFLAGS	(EVENP|ODDP|ECHO)
#else
#define	ISPEED	B4800
#define	IFLAGS	(EVENP|ODDP)
#endif

E 55
I 28
D 33
dzcntrlr(ui, reg)
	struct uba_dinfo *ui;
E 33
I 33
dzprobe(reg)
E 33
	caddr_t reg;
{
I 29
D 30
	int	i;		/* NB: NOT REGISTER */
	struct	device *dzaddr = (struct device *)reg;
E 30
I 30
	register int br, cvec;
D 68
	register struct device *dzaddr = (struct device *)reg;
E 68
I 68
	register struct dzdevice *dzaddr = (struct dzdevice *)reg;
E 68
E 30
E 29

I 33
#ifdef lint
D 40
	br = 0; br = cvec; cvec = br;
E 40
I 40
	br = 0; cvec = br; br = cvec;
I 50
	dzrint(0); dzxint((struct tty *)0);
E 50
E 40
#endif
E 33
D 29
	((struct device *)reg)->dzcsr |= IENABLE;
	/* get it to interrupt */
E 29
I 29
D 31
	dzaddr->dzcsr = TIE|MSE;
E 31
I 31
D 52
	dzaddr->dzcsr = DZ_TIE|DZ_MSE;
E 31
	dzaddr->dztcr = 1;		/* enable any line */
E 52
I 52
	dzaddr->dzcsr = DZ_TIE|DZ_MSE|DZ_32;
	if (dzaddr->dzcsr & DZ_32)
		dzaddr->dzlnen = 1;
	else
		dzaddr->dztcr = 1;		/* enable any line */
E 52
D 30
	for (i = 0; i < 1000000; i++)
		;
E 30
I 30
	DELAY(100000);
E 30
D 31
	dzaddr->dzcsr = CLR;		/* reset everything */
E 31
I 31
D 52
	dzaddr->dzcsr = DZ_CLR;		/* reset everything */
E 52
I 52
	dzaddr->dzcsr = DZ_CLR|DZ_32;		/* reset everything */
E 52
E 31
D 30
	asm("cmpl r10,$0x200;beql 1f;subl2 $4,r10;1:;");
	return(1);
E 30
I 30
	if (cvec && cvec != 0x200)
		cvec -= 4;
D 58
	return (1);
E 58
I 58
D 68
	return (sizeof (struct device));
E 68
I 68
	return (sizeof (struct dzdevice));
E 68
E 58
E 30
E 29
}

I 31
D 33
/*
 * Called by auto-configure to initialize good dz's;
 * set up pdma structures.
 */
E 31
D 32
dzslave(ui, reg, slaveno, uban)
E 32
I 32
dzslave(ui, reg)
E 33
I 33
dzattach(ui)
E 33
E 32
D 39
	register struct uba_dinfo *ui;
E 39
I 39
	register struct uba_device *ui;
E 39
D 33
	caddr_t reg;
E 33
{
	register struct pdma *pdp = &dzpdma[ui->ui_unit*8];
	register struct tty *tp = &dz_tty[ui->ui_unit*8];
D 33
	register int cnt;
E 33
I 33
	register int cntr;
I 35
	extern dzscan();
E 35
E 33
D 29
	register int *urk = (int *)(&reg - 24);	/* white magic */
E 29
D 31
	caddr_t cp;
E 31
D 29
	int urk2;
E 29

D 33
	for (cnt = 0; cnt < 8; cnt++) {
		pdp->p_addr = (struct device *)reg;
E 33
I 33
	for (cntr = 0; cntr < 8; cntr++) {
D 68
		pdp->p_addr = (struct device *)ui->ui_addr;
E 68
I 68
		pdp->p_addr = (struct dzdevice *)ui->ui_addr;
E 68
E 33
		pdp->p_arg = (int)tp;
		pdp->p_fcn = dzxint;
		pdp++, tp++;
	}
I 32
	dzsoftCAR[ui->ui_unit] = ui->ui_flags;
I 34
	if (dz_timer == 0) {
		dz_timer++;
D 37
		timeout(dzscan, (caddr_t)0, HZ);
E 37
I 37
		timeout(dzscan, (caddr_t)0, hz);
I 72
		dztimerintvl = FASTTIMER;
E 72
E 37
	}
E 34
E 32
D 29
	if ((cp = calloc(12)) == 0)
		panic("dz iv nm\n");
	uba_hd[uban].uh_vec[*urk] = (int (*)())cp;	/* more white magic */
	*cp++ = 0xbb; *cp++ = 0xff; *cp++ = 0xd0;	/* black magic */
	*cp++ = ui->ui_unit&0x3f; *cp++ = 0x50;
	*cp++ = 0x17; *cp++ = 0x9f;
	urk2 = (int)dzdma;
	for (cnt = 0; cnt < 4; cnt++)
		*cp++ = urk2, urk2 >>= 4;		/* the spell ends */
E 29
D 45
	return (1);
E 45
}

E 28
/*ARGSUSED*/
D 28
dzopen(d, flag)
E 28
I 28
dzopen(dev, flag)
	dev_t dev;
E 28
{
	register struct tty *tp;
D 28
	register dev;
E 28
I 28
	register int unit;
E 28
D 35
	extern dzscan();
E 35
 
D 28
	dev = minor(d);
	if (dev >= dz_cnt) {
E 28
I 28
	unit = minor(dev);
D 65
	if (unit >= dz_cnt || dzpdma[unit].p_addr == 0) {
E 28
		u.u_error = ENXIO;
		return;
	}
E 65
I 65
	if (unit >= dz_cnt || dzpdma[unit].p_addr == 0)
		return (ENXIO);
E 65
D 34
	if (dz_timer == 0) {
		dz_timer++;
D 31
		timeout(dzscan, (caddr_t)0, 60);
E 31
I 31
		timeout(dzscan, (caddr_t)0, HZ);
E 31
	}
E 34
D 28
	tp = &dz_tty[dev];
	tp->t_addr = (caddr_t)&dzpdma[dev];
E 28
I 28
	tp = &dz_tty[unit];
	tp->t_addr = (caddr_t)&dzpdma[unit];
E 28
	tp->t_oproc = dzstart;
D 49
	tp->t_iproc = NULL;
E 49
D 51
	tp->t_state |= WOPEN;
	if ((tp->t_state & ISOPEN) == 0) {
E 51
I 51
D 72
	tp->t_state |= TS_WOPEN;
E 72
	if ((tp->t_state & TS_ISOPEN) == 0) {
E 51
		ttychars(tp);
D 31
		tp->t_ospeed = tp->t_ispeed = SSPEED;
E 31
I 31
D 55
		tp->t_ospeed = tp->t_ispeed = B300;
E 31
		tp->t_flags = ODDP|EVENP|ECHO;
E 55
I 55
D 81
		tp->t_ospeed = tp->t_ispeed = ISPEED;
		tp->t_flags = IFLAGS;
E 55
D 31
		/*tp->t_state |= HUPCLS;*/
E 31
I 31
D 51
		/* tp->t_state |= HUPCLS; */
E 51
I 51
		/* tp->t_state |= TS_HUPCLS; */
E 81
I 81
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
E 81
E 51
E 31
D 28
		dzparam(dev);
E 28
I 28
		dzparam(unit);
E 28
D 51
	} else if (tp->t_state&XCLUDE && u.u_uid != 0) {
E 51
I 51
D 65
	} else if (tp->t_state&TS_XCLUDE && u.u_uid != 0) {
E 51
		u.u_error = EBUSY;
		return;
	}
E 65
I 65
	} else if (tp->t_state&TS_XCLUDE && u.u_uid != 0)
		return (EBUSY);
E 65
D 28
	dzmodem(dev, ON);
E 28
I 28
D 31
	dzmodem(unit, ON);
E 31
I 31
D 52
	dzmodem(unit, DZ_ON);
E 52
I 52
D 54
	dzmctl(dev, DZ_ON, DMSET);
E 54
I 54
	(void) dzmctl(dev, DZ_ON, DMSET);
E 54
E 52
E 31
E 28
D 2
	VOID spl5();
E 2
I 2
	(void) spl5();
E 2
D 51
	while ((tp->t_state & CARR_ON) == 0) {
		tp->t_state |= WOPEN;
E 51
I 51
D 85
	while ((tp->t_state & TS_CARR_ON) == 0) {
E 85
I 85
	while ((tp->t_state & TS_CARR_ON) == 0 && !(flag & FNDELAY)) {
E 85
		tp->t_state |= TS_WOPEN;
E 51
		sleep((caddr_t)&tp->t_rawq, TTIPRI);
	}
D 2
	VOID spl0();
E 2
I 2
	(void) spl0();
E 2
D 28
	(*linesw[tp->t_line].l_open)(d, tp);
E 28
I 28
D 65
	(*linesw[tp->t_line].l_open)(dev, tp);
E 65
I 65
	return ((*linesw[tp->t_line].l_open)(dev, tp));
E 65
E 28
}
 
D 28
dzclose(d)
E 28
I 28
/*ARGSUSED*/
dzclose(dev, flag)
	dev_t dev;
E 28
{
	register struct tty *tp;
D 28
	register dev;
E 28
I 28
	register int unit;
D 52
	int dz;
E 52
I 52
D 68
	register struct device *dzaddr;
E 68
I 68
	register struct dzdevice *dzaddr;
E 68
D 53
	int dz, s;
E 53
I 53
	int dz;
E 53
E 52
E 28
 
D 28
	dev = minor(d);
	tp = &dz_tty[dev];
E 28
I 28
	unit = minor(dev);
	dz = unit >> 3;
	tp = &dz_tty[unit];
E 28
	(*linesw[tp->t_line].l_close)(tp);
I 24
D 28
	/*
	 * Turn the break bit off in case it was left on by a TIOCSBRK
	 * but not turned off by TIOCCBRK
	 */
E 28
D 52
	((struct pdma *)(tp->t_addr))->p_addr->dzbrk =
D 28
		(dz_brk[minor(dev)>>3] &= ~(1 << (dev&07)));
E 28
I 28
	    (dz_brk[dz] &= ~(1 << (unit&07)));
E 28
E 24
D 51
	if (tp->t_state & HUPCLS)
E 51
I 51
	if (tp->t_state & TS_HUPCLS)
E 51
D 28
		dzmodem(dev, OFF);
E 28
I 28
D 31
		dzmodem(unit, OFF);
E 31
I 31
		dzmodem(unit, DZ_OFF);
E 52
I 52
	dzaddr = dzpdma[unit].p_addr;
	if (dzaddr->dzcsr&DZ_32)
D 54
		dzmctl(dev, DZ_BRK, DMBIC);
E 54
I 54
		(void) dzmctl(dev, DZ_BRK, DMBIC);
E 54
	else
		dzaddr->dzbrk = (dz_brk[dz] &= ~(1 << (unit&07)));
D 57
	if ((tp->t_state&TS_HUPCLS) || (tp->t_state&TS_ISOPEN) == 0)
E 57
I 57
	if ((tp->t_state&(TS_HUPCLS|TS_WOPEN)) || (tp->t_state&TS_ISOPEN) == 0)
E 57
D 54
		dzmctl(dev, DZ_OFF, DMSET);
E 54
I 54
		(void) dzmctl(dev, DZ_OFF, DMSET);
E 54
E 52
E 31
E 28
	ttyclose(tp);
}
 
D 28
dzread(d)
E 28
I 28
D 60
dzread(dev)
E 60
I 60
dzread(dev, uio)
E 60
	dev_t dev;
I 60
	struct uio *uio;
E 60
E 28
{
	register struct tty *tp;
 
D 28
	tp = &dz_tty[minor(d)];
E 28
I 28
	tp = &dz_tty[minor(dev)];
E 28
D 60
	(*linesw[tp->t_line].l_read)(tp);
E 60
I 60
	return ((*linesw[tp->t_line].l_read)(tp, uio));
E 60
}
 
D 28
dzwrite(d)
E 28
I 28
D 61
dzwrite(dev)
E 61
I 61
dzwrite(dev, uio)
E 61
	dev_t dev;
I 61
	struct uio *uio;
E 61
E 28
{
	register struct tty *tp;
 
D 28
	tp = &dz_tty[minor(d)];
E 28
I 28
	tp = &dz_tty[minor(dev)];
E 28
D 61
	(*linesw[tp->t_line].l_write)(tp);
E 61
I 61
D 64
	(*linesw[tp->t_line].l_write)(tp, uio);
E 64
I 64
	return ((*linesw[tp->t_line].l_write)(tp, uio));
E 64
E 61
}
 
I 3
/*ARGSUSED*/
E 3
D 28
dzrint(dev)
E 28
I 28
dzrint(dz)
	int dz;
E 28
{
	register struct tty *tp;
	register int c;
D 68
	register struct device *dzaddr;
E 68
I 68
	register struct dzdevice *dzaddr;
E 68
I 3
	register struct tty *tp0;
I 28
	register int unit;
I 38
	int overrun = 0;
E 38
E 28
I 4
D 33
	int s;
E 33
E 4
E 3
 
I 4
D 30
	s = spl6();	/* see comment in clock.c */
E 4
D 3
	dzaddr = dzpdma[dev*8].p_addr;
	while ((c = dzaddr->dzrbuf) < 0) {	/* char present */
		tp = &dz_tty[((c>>8)&07)|(dev<<3)];
		if (tp >= &dz_tty[dz_cnt])
E 3
I 3
	/* as long as we are here, service them all */
D 28
	for (dev = 0; dev < NDZ; dev += 8) {
		if ((dzact & (1<<(dev>>3))) == 0)
E 28
I 28
	for (unit = 0; unit < NDZ; unit += 8) {
		if ((dzact & (1<<(unit>>3))) == 0)
E 30
I 30
	if ((dzact & (1<<dz)) == 0)
		return;
	unit = dz * 8;
	dzaddr = dzpdma[unit].p_addr;
	tp0 = &dz_tty[unit];
I 52
	dzaddr->dzcsr &= ~(DZ_RIE|DZ_MIE);	/* the manual says this song */
	dzaddr->dzcsr |= DZ_RIE|DZ_MIE;		/*   and dance is necessary */
	while (dzaddr->dzcsr & DZ_MSC) {	/* DZ32 modem change interrupt */
		c = dzaddr->dzmtsr;
		tp = tp0 + (c&7);
		if (tp >= &dz_tty[dz_cnt])
			break;
		dzaddr->dzlcs = c&7;	/* get status of modem lines */
		dzwait(dzaddr);		/* wait for them */
		if (c & DZ_CD)		/* carrier status change? */
		if (dzaddr->dzlcs & DZ_CD) {	/* carrier up? */
D 80
			if ((tp->t_state&TS_CARR_ON) == 0) {
				wakeup((caddr_t)&tp->t_rawq);
				tp->t_state |= TS_CARR_ON;
			}
		} else {	/* no carrier */
			if (tp->t_state&TS_CARR_ON) {
				gsignal(tp->t_pgrp, SIGHUP);
				gsignal(tp->t_pgrp, SIGCONT);
				dzaddr->dzlcs = DZ_ACK|(c&7);
D 70
				flushtty(tp, FREAD|FWRITE);
E 70
I 70
				ttyflush(tp, FREAD|FWRITE);
E 70
			}
			tp->t_state &= ~TS_CARR_ON;
		}
E 80
I 80
			/* carrier present */
			(void)(*linesw[tp->t_line].l_modem)(tp, 1);
		} else if ((*linesw[tp->t_line].l_modem)(tp, 0) == 0)
			dzaddr->dzlcs = DZ_ACK|(c&7);
E 80
	}
E 52
	while ((c = dzaddr->dzrbuf) < 0) {	/* char present */
I 72
		dzchars[dz]++;
E 72
		tp = tp0 + ((c>>8)&07);
		if (tp >= &dz_tty[dz_cnt])
E 30
E 28
E 3
			continue;
D 3
		if ((tp->t_state & ISOPEN) == 0) {
			wakeup((caddr_t)&tp->t_rawq);
			continue;
		}
		if (c & FRERROR)
			/* framing error = break */
			if (tp->t_flags & RAW)
				c = 0;		/* null for getty */
			else
				c = 0177;	/* DEL = interrupt */
		if (c & PERROR)	
			/* parity error */
			if (((tp->t_flags & (EVENP|ODDP)) == EVENP)
			  || ((tp->t_flags & (EVENP|ODDP)) == ODDP))
E 3
I 3
D 28
		dzaddr = dzpdma[dev].p_addr;
		tp0 = &dz_tty[dev];
E 28
I 28
D 30
		dzaddr = dzpdma[unit].p_addr;
		tp0 = &dz_tty[unit];
E 28
		while ((c = dzaddr->dzrbuf) < 0) {	/* char present */
			tp = tp0 + ((c>>8)&07);
			if (tp >= &dz_tty[dz_cnt])
E 3
				continue;
I 3
			if ((tp->t_state & ISOPEN) == 0) {
				wakeup((caddr_t)&tp->t_rawq);
				continue;
			}
			if (c&FRERROR)
				/* framing error = break */
				if (tp->t_flags & RAW)
					c = 0;		/* null for getty */
				else
D 6
					c = 0177;	/* DEL = interrupt */
E 6
I 6
D 29
#ifdef IIASA
					continue;
#else
E 29
D 7
					c = 0177;	/* tun.t_intrc? */
E 7
I 7
					c = tun.t_intrc;
E 7
D 29
#endif
E 29
E 6
			if (c&OVERRUN)
				printf("o");
			if (c&PERROR)	
				/* parity error */
				if (((tp->t_flags & (EVENP|ODDP)) == EVENP)
				  || ((tp->t_flags & (EVENP|ODDP)) == ODDP))
					continue;
E 3
D 2
		(*linesw[tp->t_line].l_rint)(c, tp);
E 2
I 2
D 6
#ifdef BERKNET
E 6
D 4
			if (tp->t_line == BNETLDIS) {
E 4
I 4
			if (tp->t_line == NETLDISC) {
E 4
				c &= 0177;
D 6
				NETINPUT(c, tp);
E 6
I 6
				BKINPUT(c, tp);
E 6
			} else
D 6
#endif
E 6
				(*linesw[tp->t_line].l_rint)(c, tp);
E 30
I 30
D 51
		if ((tp->t_state & ISOPEN) == 0) {
E 51
I 51
		if ((tp->t_state & TS_ISOPEN) == 0) {
E 51
			wakeup((caddr_t)&tp->t_rawq);
I 55
#ifdef PORTSELECTOR
			if ((tp->t_state&TS_WOPEN) == 0)
#endif
E 55
D 80
			continue;
E 80
I 80
				continue;
E 80
E 30
I 3
		}
I 30
D 31
		if (c&FRERROR)
			/* framing error = break */
E 31
I 31
		if (c&DZ_FE)
E 31
			if (tp->t_flags & RAW)
D 31
				c = 0;		/* null for getty */
E 31
I 31
				c = 0;
E 31
			else
D 66
				c = tun.t_intrc;
E 66
I 66
				c = tp->t_intrc;
E 66
D 31
		if (c&OVERRUN)
E 31
I 31
D 38
		if (c&DZ_DO)
E 31
			printf("o");
E 38
I 38
		if (c&DZ_DO && overrun == 0) {
D 52
			printf("dz%d: silo overflow\n", dz);
E 52
I 52
D 76
			/* printf("dz%d,%d: silo overflow\n", dz, (c>>8)&7); */
E 76
I 76
D 79
			log(KERN_RECOV, "dz%d,%d: silo overflow\n", dz, (c>>8)&7);
E 79
I 79
			log(LOG_WARNING, "dz%d,%d: silo overflow\n", dz, (c>>8)&7);
E 79
E 76
E 52
			overrun = 1;
		}
E 38
D 31
		if (c&PERROR)	
			/* parity error */
E 31
I 31
		if (c&DZ_PE)	
E 31
			if (((tp->t_flags & (EVENP|ODDP)) == EVENP)
			  || ((tp->t_flags & (EVENP|ODDP)) == ODDP))
				continue;
I 36
#if NBK > 0
E 36
		if (tp->t_line == NETLDISC) {
			c &= 0177;
			BKINPUT(c, tp);
		} else
I 36
#endif
E 36
			(*linesw[tp->t_line].l_rint)(c, tp);
E 30
E 3
E 2
	}
I 4
D 30
	splx(s);
E 30
E 4
}
 
/*ARGSUSED*/
D 59
dzioctl(dev, cmd, addr, flag)
E 59
I 59
dzioctl(dev, cmd, data, flag)
E 59
D 28
caddr_t addr;
dev_t dev;
E 28
I 28
	dev_t dev;
D 59
	caddr_t addr;
E 59
I 59
	caddr_t data;
E 59
E 28
{
	register struct tty *tp;
I 28
	register int unit = minor(dev);
	register int dz = unit >> 3;
I 52
D 68
	register struct device *dzaddr;
E 68
I 68
	register struct dzdevice *dzaddr;
E 68
I 65
	int error;
E 65
D 59
	int temp;
E 59
E 52
E 28
I 14
D 24
	static char dz_brk[NDZ11];
E 24
E 14
 
D 28
	tp = &dz_tty[minor(dev)];
E 28
I 28
	tp = &dz_tty[unit];
E 28
I 2
D 59
	cmd = (*linesw[tp->t_line].l_ioctl)(tp, cmd, addr);
E 59
I 59
D 65
	cmd = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
E 59
	if (cmd == 0)
		return;
E 2
D 15
	if (ttioccomm(cmd, tp, addr, dev)) {
E 15
I 15
D 22
	if (ttioctl(cmd, tp, addr, dev, flag)) {
E 22
I 22
D 59
	if (ttioctl(tp, cmd, addr, flag)) {
E 22
E 15
		if (cmd==TIOCSETP || cmd==TIOCSETN)
E 59
I 59
	if (ttioctl(tp, cmd, data, flag)) {
E 65
I 65
	error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
	if (error >= 0)
		return (error);
	error = ttioctl(tp, cmd, data, flag);
	if (error >= 0) {
E 65
D 75
		if (cmd == TIOCSETP || cmd == TIOCSETN)
E 75
I 75
		if (cmd == TIOCSETP || cmd == TIOCSETN || cmd == TIOCLBIS ||
		    cmd == TIOCLBIC || cmd == TIOCLSET)
E 75
E 59
D 28
			dzparam(minor(dev));
E 28
I 28
			dzparam(unit);
E 28
D 6
	} else
E 6
I 6
D 65
	} else switch(cmd) {
E 65
I 65
		return (error);
	}
	switch (cmd) {
E 65
I 28

E 28
	case TIOCSBRK:
D 14
		((struct device *)(tp->t_addr))->dzbrk |= 1 << (dev&07);
E 14
I 14
D 52
		((struct pdma *)(tp->t_addr))->p_addr->dzbrk =
D 28
			(dz_brk[minor(dev)>>3] |= 1 << (dev&07));
E 28
I 28
			(dz_brk[dz] |= 1 << (unit&07));
E 52
I 52
		dzaddr = ((struct pdma *)(tp->t_addr))->p_addr;
		if (dzaddr->dzcsr&DZ_32)
D 54
			dzmctl(dev, DZ_BRK, DMBIS);
E 54
I 54
			(void) dzmctl(dev, DZ_BRK, DMBIS);
E 54
		else
			dzaddr->dzbrk = (dz_brk[dz] |= 1 << (unit&07));
E 52
E 28
E 14
		break;
I 59

E 59
	case TIOCCBRK:
D 14
		((struct device *)(tp->t_addr))->dzbrk &= ~(1 << (dev&07));
E 14
I 14
D 52
		((struct pdma *)(tp->t_addr))->p_addr->dzbrk =
D 28
			(dz_brk[minor(dev)>>3] &= ~(1 << (dev&07)));
E 28
I 28
			(dz_brk[dz] &= ~(1 << (unit&07)));
E 52
I 52
		dzaddr = ((struct pdma *)(tp->t_addr))->p_addr;
		if (dzaddr->dzcsr&DZ_32)
D 54
			dzmctl(dev, DZ_BRK, DMBIC);
E 54
I 54
			(void) dzmctl(dev, DZ_BRK, DMBIC);
E 54
		else
			dzaddr->dzbrk = (dz_brk[dz] &= ~(1 << (unit&07)));
E 52
E 28
E 14
		break;
I 59

E 59
	case TIOCSDTR:
D 9
		dzmodem(dev, ON);
E 9
I 9
D 28
		dzmodem(minor(dev), ON);
E 28
I 28
D 31
		dzmodem(unit, ON);
E 31
I 31
D 52
		dzmodem(unit, DZ_ON);
E 52
I 52
D 54
		dzmctl(dev, DZ_DTR|DZ_RTS, DMBIS);
E 54
I 54
		(void) dzmctl(dev, DZ_DTR|DZ_RTS, DMBIS);
E 54
E 52
E 31
E 28
E 9
		break;
I 59

E 59
	case TIOCCDTR:
D 9
		dzmodem(dev, OFF);
E 9
I 9
D 28
		dzmodem(minor(dev), OFF);
E 28
I 28
D 31
		dzmodem(unit, OFF);
E 31
I 31
D 52
		dzmodem(unit, DZ_OFF);
E 52
I 52
D 54
		dzmctl(dev, DZ_DTR|DZ_RTS, DMBIC);
E 54
I 54
		(void) dzmctl(dev, DZ_DTR|DZ_RTS, DMBIC);
E 54
E 52
E 31
E 28
E 9
		break;
I 59

E 59
I 52
	case TIOCMSET:
D 59
		if (copyin(addr, (caddr_t) &temp, sizeof(temp)))
			u.u_error = EFAULT;
		else
D 54
			dzmctl(dev, dmtodz(temp), DMSET);
E 54
I 54
			(void) dzmctl(dev, dmtodz(temp), DMSET);
E 59
I 59
		(void) dzmctl(dev, dmtodz(*(int *)data), DMSET);
E 59
E 54
		break;
I 59

E 59
	case TIOCMBIS:
D 59
		if (copyin(addr, (caddr_t) &temp, sizeof(temp)))
			u.u_error = EFAULT;
		else
D 54
			dzmctl(dev, dmtodz(temp), DMBIS);
E 54
I 54
			(void) dzmctl(dev, dmtodz(temp), DMBIS);
E 59
I 59
		(void) dzmctl(dev, dmtodz(*(int *)data), DMBIS);
E 59
E 54
		break;
I 59

E 59
	case TIOCMBIC:
D 59
		if (copyin(addr, (caddr_t) &temp, sizeof(temp)))
			u.u_error = EFAULT;
		else
D 54
			dzmctl(dev, dmtodz(temp), DMBIC);
E 54
I 54
			(void) dzmctl(dev, dmtodz(temp), DMBIC);
E 59
I 59
		(void) dzmctl(dev, dmtodz(*(int *)data), DMBIC);
E 59
E 54
		break;
I 59

E 59
	case TIOCMGET:
D 59
		temp = dztodm(dzmctl(dev, 0, DMGET));
		if (copyout((caddr_t) &temp, addr, sizeof(temp)))
			u.u_error = EFAULT;
E 59
I 59
		*(int *)data = dztodm(dzmctl(dev, 0, DMGET));
E 59
		break;
I 59

E 59
E 52
	default:
E 6
D 65
		u.u_error = ENOTTY;
E 65
I 65
		return (ENOTTY);
E 65
I 6
	}
I 65
	return (0);
E 65
E 6
}
I 52

dmtodz(bits)
	register int bits;
{
	register int b;

	b = (bits >>1) & 0370;
	if (bits & DML_ST) b |= DZ_ST;
	if (bits & DML_RTS) b |= DZ_RTS;
	if (bits & DML_DTR) b |= DZ_DTR;
	if (bits & DML_LE) b |= DZ_LE;
	return(b);
}

dztodm(bits)
	register int bits;
{
	register int b;

	b = (bits << 1) & 0360;
	if (bits & DZ_DSR) b |= DML_DSR;
	if (bits & DZ_DTR) b |= DML_DTR;
	if (bits & DZ_ST) b |= DML_ST;
	if (bits & DZ_RTS) b |= DML_RTS;
	return(b);
}
E 52
 
D 28
dzparam(dev)
E 28
I 28
dzparam(unit)
	register int unit;
E 28
{
	register struct tty *tp;
D 68
	register struct device *dzaddr;
E 68
I 68
	register struct dzdevice *dzaddr;
E 68
D 28
	register short lpr;
E 28
I 28
	register int lpr;
E 28
 
D 28
	tp = &dz_tty[dev];
	dzaddr = dzpdma[dev].p_addr;
E 28
I 28
	tp = &dz_tty[unit];
	dzaddr = dzpdma[unit].p_addr;
E 28
D 72
	dzaddr->dzcsr = DZ_IEN;
E 72
I 72
	if (dzsilos & (1 << (unit >> 3)))
		dzaddr->dzcsr = DZ_IEN | DZ_SAE;
	else
		dzaddr->dzcsr = DZ_IEN;
E 72
I 3
D 28
	dzact |= (1<<(dev>>3));
E 28
I 28
	dzact |= (1<<(unit>>3));
E 28
E 3
	if (tp->t_ispeed == 0) {
D 28
		dzmodem(dev, OFF);		/* hang up line */
E 28
I 28
D 31
		dzmodem(unit, OFF);		/* hang up line */
E 31
I 31
D 52
		dzmodem(unit, DZ_OFF);		/* hang up line */
E 52
I 52
D 54
		dzmctl(unit, DZ_OFF, DMSET);	/* hang up line */
E 54
I 54
		(void) dzmctl(unit, DZ_OFF, DMSET);	/* hang up line */
E 54
E 52
E 31
E 28
		return;
	}
D 28
	lpr = (dz_speeds[tp->t_ispeed]<<8) | (dev & 07);
E 28
I 28
	lpr = (dz_speeds[tp->t_ispeed]<<8) | (unit & 07);
E 28
I 14
D 29
#ifndef IIASA
E 29
E 14
D 25
	if (tp->t_flags & RAW)
E 25
I 25
D 26
	if (tp->t_local & LLITOUT)
E 26
I 26
D 66
	if ((tp->t_local&LLITOUT) || (tp->t_flags&RAW))
E 66
I 66
D 78
	if (tp->t_flags & (RAW|LITOUT))
E 78
I 78
	if (tp->t_flags & (RAW|LITOUT|PASS8))
E 78
E 66
E 26
E 25
		lpr |= BITS8;
	else
		lpr |= (BITS7|PENABLE);
	if ((tp->t_flags & EVENP) == 0)
		lpr |= OPAR;
I 14
D 29
#else IIASA
	if ((tp->t_flags & (EVENP|ODDP)) == (EVENP|ODDP))
		lpr |= BITS8;
	else if (tp->t_flags & EVENP)
		lpr |= (BITS7|PENABLE);
	else if (tp->t_flags & ODDP)
		lpr |= (BITS7|OPAR|PENABLE);
	else
		lpr |= BITS7;
#endif IIASA
E 29
E 14
D 31
	if (tp->t_ispeed == 3)
		lpr |= TWOSB; 			/* 110 baud: 2 stop bits */
E 31
I 31
	if (tp->t_ispeed == B110)
		lpr |= TWOSB;
E 31
	dzaddr->dzlpr = lpr;
}
 
dzxint(tp)
D 28
register struct tty *tp;
E 28
I 28
	register struct tty *tp;
E 28
{
	register struct pdma *dp;
I 5
D 52
	register s;
E 52
I 52
D 72
	register s, dz, unit;
E 72
I 72
	register dz, unit;
E 72
E 52
D 30
	s = spl6();	/* block the clock */
E 30
E 5
 
I 30
D 31
	s = spl5();
E 31
I 31
D 72
	s = spl5();		/* block pdma interrupts */
E 72
E 31
E 30
D 28
	dp = &dzpdma[tp-dz_tty];
E 28
I 28
	dp = (struct pdma *)tp->t_addr;
E 28
D 51
	tp->t_state &= ~BUSY;
	if (tp->t_state & FLUSH)
		tp->t_state &= ~FLUSH;
E 51
I 51
	tp->t_state &= ~TS_BUSY;
	if (tp->t_state & TS_FLUSH)
		tp->t_state &= ~TS_FLUSH;
E 51
D 52
	else
E 52
I 52
	else {
E 52
D 11
		ndflush(&tp->t_outq, dp->p_end-tp->t_outq.c_cf);
E 11
I 11
		ndflush(&tp->t_outq, dp->p_mem-tp->t_outq.c_cf);
I 52
		dp->p_end = dp->p_mem = tp->t_outq.c_cf;
	}
E 52
E 11
	if (tp->t_line)
		(*linesw[tp->t_line].l_start)(tp);
	else
		dzstart(tp);
I 52
	dz = minor(tp->t_dev) >> 3;
	unit = minor(tp->t_dev) & 7;
E 52
D 51
	if (tp->t_outq.c_cc == 0 || (tp->t_state&BUSY)==0)
E 51
I 51
	if (tp->t_outq.c_cc == 0 || (tp->t_state&TS_BUSY)==0)
E 51
D 28
		dp->p_addr->dztcr &= ~(1 << ((tp-dz_tty) % 8));
E 28
I 28
D 52
		dp->p_addr->dztcr &= ~(1 << (minor(tp->t_dev)&07));
E 52
I 52
		if (dp->p_addr->dzcsr & DZ_32)
			dp->p_addr->dzlnen = (dz_lnen[dz] &= ~(1<<unit));
		else
			dp->p_addr->dztcr &= ~(1<<unit);
E 52
E 28
I 5
D 72
	splx(s);
E 72
E 5
}

dzstart(tp)
D 28
register struct tty *tp;
E 28
I 28
	register struct tty *tp;
E 28
{
	register struct pdma *dp;
D 68
	register struct device *dzaddr;
E 68
I 68
	register struct dzdevice *dzaddr;
E 68
D 28
	register cc;
	int sps;
E 28
I 28
	register int cc;
D 52
	int s;
E 52
I 52
	int s, dz, unit;
E 52
E 28
D 2
	extern ttrstrt();
E 2
 
D 28
	dp = &dzpdma[tp-dz_tty];
E 28
I 28
	dp = (struct pdma *)tp->t_addr;
E 28
	dzaddr = dp->p_addr;
D 28
	sps = spl5();
E 28
I 28
	s = spl5();
E 28
D 51
	if (tp->t_state & (TIMEOUT|BUSY|TTSTOP))
E 51
I 51
	if (tp->t_state & (TS_TIMEOUT|TS_BUSY|TS_TTSTOP))
E 51
		goto out;
D 16
	if (tp->t_outq.c_cc <= TTLOWAT && tp->t_state&ASLEEP) {
E 16
I 16
D 51
	if (tp->t_state&ASLEEP && tp->t_outq.c_cc <= TTLOWAT(tp)) {
E 16
		tp->t_state &= ~ASLEEP;
D 49
		if (tp->t_chan)
			mcstart(tp->t_chan, (caddr_t)&tp->t_outq);
		else
			wakeup((caddr_t)&tp->t_outq);
E 49
I 49
		wakeup((caddr_t)&tp->t_outq);
E 51
I 51
	if (tp->t_outq.c_cc <= TTLOWAT(tp)) {
		if (tp->t_state&TS_ASLEEP) {
			tp->t_state &= ~TS_ASLEEP;
			wakeup((caddr_t)&tp->t_outq);
		}
		if (tp->t_wsel) {
			selwakeup(tp->t_wsel, tp->t_state & TS_WCOLL);
			tp->t_wsel = 0;
			tp->t_state &= ~TS_WCOLL;
		}
E 51
E 49
	}
	if (tp->t_outq.c_cc == 0)
		goto out;
D 43
	if (tp->t_flags&RAW)
E 43
I 43
D 44
	if (tp->t_flags&RAW || tp->t_flags&LLITOUT)
E 44
I 44
D 52
	if (tp->t_flags&RAW || tp->t_local&LLITOUT)
E 52
I 52
D 66
	if ((tp->t_flags&RAW) || (tp->t_local&LLITOUT))
E 66
I 66
D 84
	if (tp->t_flags & (RAW|LITOUT))
E 84
I 84
	if (tp->t_flags & (RAW|LITOUT|PASS8))
E 84
E 66
E 52
E 44
E 43
		cc = ndqb(&tp->t_outq, 0);
	else {
		cc = ndqb(&tp->t_outq, 0200);
		if (cc == 0) {
			cc = getc(&tp->t_outq);
D 31
			timeout(ttrstrt, (caddr_t)tp, (cc&0177) + 6);
E 31
I 31
			timeout(ttrstrt, (caddr_t)tp, (cc&0x7f) + 6);
E 31
D 51
			tp->t_state |= TIMEOUT;
E 51
I 51
			tp->t_state |= TS_TIMEOUT;
E 51
			goto out;
		}
	}
D 51
	tp->t_state |= BUSY;
E 51
I 51
	tp->t_state |= TS_BUSY;
E 51
	dp->p_end = dp->p_mem = tp->t_outq.c_cf;
	dp->p_end += cc;
D 28
	dzaddr->dztcr |= 1 << ((tp-dz_tty) % 8);
   out:
	splx(sps);
E 28
I 28
D 31
	dzaddr->dztcr |= 1 << (minor(tp->t_dev) & 07);
E 31
I 31
D 52
	dzaddr->dztcr |= 1 << (minor(tp->t_dev) & 07);	/* force intr */
E 52
I 52
	dz = minor(tp->t_dev) >> 3;
	unit = minor(tp->t_dev) & 7;
	if (dzaddr->dzcsr & DZ_32)
		dzaddr->dzlnen = (dz_lnen[dz] |= (1<<unit));
	else
		dzaddr->dztcr |= (1<<unit);
E 52
E 31
out:
	splx(s);
E 28
}
 
/*
 * Stop output on a line.
D 29
 * Assume call is made at spl6.
E 29
 */
/*ARGSUSED*/
dzstop(tp, flag)
D 28
register struct tty *tp;
E 28
I 28
	register struct tty *tp;
E 28
{
	register struct pdma *dp;
	register int s;

D 28
	dp = &dzpdma[tp-dz_tty];
E 28
I 28
	dp = (struct pdma *)tp->t_addr;
E 28
D 30
	s = spl6();
E 30
I 30
	s = spl5();
E 30
D 51
	if (tp->t_state & BUSY) {
E 51
I 51
	if (tp->t_state & TS_BUSY) {
E 51
		dp->p_end = dp->p_mem;
D 28
		if ((tp->t_state&TTSTOP)==0) {
E 28
I 28
D 51
		if ((tp->t_state&TTSTOP)==0)
E 28
			tp->t_state |= FLUSH;
E 51
I 51
		if ((tp->t_state&TS_TTSTOP)==0)
			tp->t_state |= TS_FLUSH;
E 51
D 28
		}
E 28
	}
	splx(s);
}
 
D 28
dzmodem(dev, flag)
register int dev;
E 28
I 28
D 52
dzmodem(unit, flag)
	register int unit;
E 52
I 52
dzmctl(dev, bits, how)
	dev_t dev;
	int bits, how;
E 52
E 28
{
D 68
	register struct device *dzaddr;
E 68
I 68
	register struct dzdevice *dzaddr;
E 68
D 52
	register char bit;
 
E 52
I 52
	register int unit, mbits;
	int b, s;

	unit = minor(dev);
	b = 1<<(unit&7);
E 52
D 28
	dzaddr = dzpdma[dev].p_addr;
	bit = 1<<(dev&07);
E 28
I 28
	dzaddr = dzpdma[unit].p_addr;
D 52
	bit = 1<<(unit&07);
E 28
D 31
	if (flag == OFF)
E 31
I 31
	if (flag == DZ_OFF)
E 31
		dzaddr->dzdtr &= ~bit;
	else
		dzaddr->dzdtr |= bit;
E 52
I 52
	s = spl5();
	if (dzaddr->dzcsr & DZ_32) {
		dzwait(dzaddr)
		DELAY(100);		/* IS 100 TOO MUCH? */
		dzaddr->dzlcs = unit&7;
		DELAY(100);
		dzwait(dzaddr)
		DELAY(100);
		mbits = dzaddr->dzlcs;
		mbits &= 0177770;
	} else {
		mbits = (dzaddr->dzdtr & b) ? DZ_DTR : 0;
		mbits |= (dzaddr->dzmsr & b) ? DZ_CD : 0;
		mbits |= (dzaddr->dztbuf & b) ? DZ_RI : 0;
	}
	switch (how) {
	case DMSET:
		mbits = bits;
		break;

	case DMBIS:
		mbits |= bits;
		break;

	case DMBIC:
		mbits &= ~bits;
		break;

	case DMGET:
		(void) splx(s);
		return(mbits);
	}
	if (dzaddr->dzcsr & DZ_32) {
		mbits |= DZ_ACK|(unit&7);
		dzaddr->dzlcs = mbits;
	} else {
		if (mbits & DZ_DTR)
			dzaddr->dzdtr |= b;
		else
			dzaddr->dzdtr &= ~b;
	}
I 83
	if (mbits & DZ_DTR && dzsoftCAR[unit >> 3] & b)
		dz_tty[unit].t_state |= TS_CARR_ON;
E 83
	(void) splx(s);
	return(mbits);
E 52
I 11
D 12
	dzdtr[minor(dev)>>3] = dzaddr->dzdtr;
E 12
E 11
}
 
I 72
int dztransitions, dzfasttimers;		/*DEBUG*/
E 72
dzscan()
{
	register i;
D 68
	register struct device *dzaddr;
E 68
I 68
	register struct dzdevice *dzaddr;
E 68
	register bit;
	register struct tty *tp;
I 52
	register car;
I 72
	int olddzsilos = dzsilos;
	int dztimer();
E 72
E 52
 
	for (i = 0; i < dz_cnt ; i++) {
		dzaddr = dzpdma[i].p_addr;
I 34
		if (dzaddr == 0)
			continue;
E 34
		tp = &dz_tty[i];
		bit = 1<<(i&07);
D 27
		if (dzaddr->dzmsr & bit) {
E 27
I 27
D 29
		if (dzaddr->dzmsr & bit || (i == 6 || i == 7)) {
E 29
I 29
D 32
#ifdef BERT
		if (dzaddr->dzmsr & bit || i == 6 || i == 7) {
#else
		if (dzaddr->dzmsr & bit) {
#endif
E 32
I 32
D 33
		if ((dzsoftCAR[i]&bit) || (dzaddr->dzmsr&bit)) {
E 33
I 33
D 52
		if ((dzsoftCAR[i>>3]&bit) || (dzaddr->dzmsr&bit)) {
E 52
I 52
		car = 0;
		if (dzsoftCAR[i>>3]&bit)
			car = 1;
		else if (dzaddr->dzcsr & DZ_32) {
			dzaddr->dzlcs = i&07;
			dzwait(dzaddr);
			car = dzaddr->dzlcs & DZ_CD;
		} else
			car = dzaddr->dzmsr&bit;
		if (car) {
E 52
E 33
E 32
E 29
E 27
			/* carrier present */
D 51
			if ((tp->t_state & CARR_ON) == 0) {
E 51
I 51
D 80
			if ((tp->t_state & TS_CARR_ON) == 0) {
E 51
				wakeup((caddr_t)&tp->t_rawq);
D 51
				tp->t_state |= CARR_ON;
E 51
I 51
				tp->t_state |= TS_CARR_ON;
E 51
			}
		} else {
D 14
			if ((tp->t_state & CARR_ON)) {
E 14
I 14
D 28
			if ((tp->t_state&CARR_ON) && (tp->t_local&LNOHANG) == 0) {
E 28
I 28
D 31
			if ((tp->t_state&CARR_ON) && (tp->t_local&LNOHANG)==0) {
E 31
I 31
D 51
			if ((tp->t_state&CARR_ON) &&
E 51
I 51
			if ((tp->t_state&TS_CARR_ON) &&
E 51
D 66
			    (tp->t_local&LNOHANG)==0) {
E 66
I 66
			    (tp->t_flags&NOHANG) == 0) {
E 66
E 31
E 28
E 14
				/* carrier lost */
I 7
D 8
/*
E 8
E 7
D 6
				signal(tp->t_pgrp, SIGHUP);
				dzaddr->dzdtr &= ~bit;
				flushtty(tp);
E 6
I 6
D 14
				if (tp->t_state&ISOPEN &&
				    (tp->t_local&LNOHANG) == 0) {
E 14
I 14
D 51
				if (tp->t_state&ISOPEN) {
E 51
I 51
				if (tp->t_state&TS_ISOPEN) {
E 51
E 14
I 7
D 8
 */
E 8
E 7
					gsignal(tp->t_pgrp, SIGHUP);
I 8
					gsignal(tp->t_pgrp, SIGCONT);
E 8
					dzaddr->dzdtr &= ~bit;
I 11
D 12
					dzdtr[i>>3] = dzaddr->dzdtr;
E 12
E 11
D 13
					flushtty(tp);
E 13
I 13
D 70
					flushtty(tp, FREAD|FWRITE);
E 70
I 70
					ttyflush(tp, FREAD|FWRITE);
E 70
E 13
I 7
D 8
/*
E 8
E 7
				}
I 7
D 8
 */
E 8
E 7
D 51
				tp->t_state &= ~CARR_ON;
E 51
I 51
				tp->t_state &= ~TS_CARR_ON;
E 51
E 6
			}
D 6
			tp->t_state &= ~CARR_ON;
E 6
		}
E 80
I 80
			if ((tp->t_state & TS_CARR_ON) == 0)
				(void)(*linesw[tp->t_line].l_modem)(tp, 1);
		} else if ((tp->t_state&TS_CARR_ON) &&
		    (*linesw[tp->t_line].l_modem)(tp, 0) == 0)
			dzaddr->dzdtr &= ~bit;
E 80
	}
D 37
	timeout(dzscan, (caddr_t)0, 2*HZ);
E 37
I 37
D 72
	timeout(dzscan, (caddr_t)0, 2*hz);
E 72
I 72
	for (i = 0; i < NDZ; i++) {
		ave(dzrate[i], dzchars[i], 8);
		if (dzchars[i] > dzhighrate && ((dzsilos & (1 << i)) == 0)) {
D 73
			dzpdma[i].p_addr->dzcsr = DZ_IEN | DZ_SAE;
E 73
I 73
			dzpdma[i << 3].p_addr->dzcsr = DZ_IEN | DZ_SAE;
E 73
			dzsilos |= (1 << i);
			dztransitions++;		/*DEBUG*/
		} else if ((dzsilos & (1 << i)) && (dzrate[i] < dzlowrate)) {
D 73
			dzpdma[i].p_addr->dzcsr = DZ_IEN;
E 73
I 73
			dzpdma[i << 3].p_addr->dzcsr = DZ_IEN;
E 73
			dzsilos &= ~(1 << i);
		}
		dzchars[i] = 0;
	}
	if (dzsilos && !olddzsilos)
		timeout(dztimer, (caddr_t)0, dztimerintvl);
	timeout(dzscan, (caddr_t)0, hz);
E 72
E 37
I 3
}

dztimer()
{
I 30
D 62
	int dz;
E 62
I 62
	register int dz;
D 72
	register int s = spl5();
E 72
I 72
	register int s;
E 72
E 62
E 30

I 72
	if (dzsilos == 0)
		return;
	s = spl5();
	dzfasttimers++;		/*DEBUG*/
E 72
D 30
	dzrint(0);
E 30
I 30
D 35
	for (dz = 0; dz < NDZ11; dz++)
E 35
I 35
	for (dz = 0; dz < NDZ; dz++)
E 35
D 72
		dzrint(dz);
E 72
I 72
		if (dzsilos & (1 << dz))
		    dzrint(dz);
E 72
I 62
	splx(s);
I 72
	timeout(dztimer, (caddr_t) 0, dztimerintvl);
E 72
E 62
E 30
I 11
}

/*
 * Reset state of driver if UBA reset was necessary.
D 12
 * Reset all the dzdtr registers, then the csr and lpr
 * registers, then restart all pending transmissions.
E 12
I 12
 * Reset parameters and restart transmission on open lines.
E 12
 */
D 28
dzreset()
E 28
I 28
dzreset(uban)
I 29
	int uban;
E 29
E 28
{
D 28
	int d;
E 28
I 28
	register int unit;
E 28
	register struct tty *tp;
I 29
D 39
	register struct uba_dinfo *ui;
E 39
I 39
	register struct uba_device *ui;
E 39
D 38
	int any = 0;
E 38
E 29

I 28
D 29
	/*** WE SHOULD LOOK TO SEE IF WE CARE ABOUT UBA BEING RESET ***/

E 28
	printf(" dz");
E 29
D 12
	dzinit = 1;
	for (d = 0; d < NDZ; d += 8)
		dzpdma[d].p_addr->dzdtr = dzdtr[d>>3];
E 12
D 28
	for (d = 0; d < NDZ; d++) {
		tp = &dz_tty[d];
E 28
I 28
D 35
	for (unit = 0; unit < NDZ; unit++) {
E 35
I 35
	for (unit = 0; unit < NDZLINE; unit++) {
E 35
I 29
		ui = dzinfo[unit >> 3];
		if (ui == 0 || ui->ui_ubanum != uban || ui->ui_alive == 0)
			continue;
D 38
		if (any == 0) {
			printf(" dz");
			any++;
		}
E 38
I 38
		if (unit%8 == 0)
			printf(" dz%d", unit>>3);
E 38
E 29
		tp = &dz_tty[unit];
E 28
D 51
		if (tp->t_state & (ISOPEN|WOPEN)) {
E 51
I 51
		if (tp->t_state & (TS_ISOPEN|TS_WOPEN)) {
E 51
D 28
			dzparam(d);
D 12
			dzxint(tp);
E 12
I 12
			dzmodem(d, ON);
E 28
I 28
			dzparam(unit);
D 31
			dzmodem(unit, ON);
E 31
I 31
D 52
			dzmodem(unit, DZ_ON);
E 52
I 52
D 54
			dzmctl(unit, DZ_ON, DMSET);
E 54
I 54
			(void) dzmctl(unit, DZ_ON, DMSET);
E 54
E 52
E 31
E 28
D 51
			tp->t_state &= ~BUSY;
E 51
I 51
			tp->t_state &= ~TS_BUSY;
E 51
			dzstart(tp);
E 12
		}
	}
D 72
	dztimer();
E 72
D 12
	dzinit = 0;
E 12
E 11
E 3
}
I 17
#endif
E 17
E 1
