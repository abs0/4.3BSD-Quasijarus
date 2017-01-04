h35870
s 00014/00003/00705
d D 7.7 89/02/15 10:52:09 bostic 89 88
c add Berkeley specific copyright notice
e
s 00036/00015/00672
d D 7.6 88/10/22 15:12:51 karels 88 86
c change ubaalloc macros to allow 2047 map registers on Q-bus,
c use the macros, and add qbgetpri for Q-bus device probe routines
e
s 00040/00015/00672
d R 7.6 88/10/20 17:02:58 karels 87 86
c change ubaalloc macros to allow 2047 map registers on Q-bus,
c use the macros, and add qbgetpri for Q-bus device probe routines
e
s 00045/00014/00642
d D 7.5 88/05/14 11:34:01 karels 86 85
c DWBUA support for 8200, other changes from torek
e
s 00045/00016/00611
d D 7.4 87/10/23 11:13:01 bostic 85 84
c teach uba.c about drivers that want to keep BDP's; (Chris Torek)
e
s 00001/00001/00626
d D 7.3 87/01/14 08:48:25 karels 84 83
c rename dk.h to dkstat.h
e
s 00076/00047/00551
d D 7.2 86/08/09 15:15:02 karels 83 82
c generalize uba code to handle Q bus more gracefully
e
s 00001/00001/00597
d D 7.1 86/06/05 01:19:15 mckusick 82 81
c 4.3BSD release version
e
s 00008/00004/00590
d D 6.11 86/04/22 11:05:46 kridle 81 80
c MicroVAX II Integration (KA630)
e
s 00009/00007/00585
d D 6.10 86/02/23 23:18:46 karels 80 79
c lint
e
s 00008/00007/00584
d D 6.9 86/02/17 20:32:29 karels 79 78
c watch out for time going backward, keep zvtime per uba
e
s 00002/00001/00589
d D 6.8 85/08/30 13:51:47 jg 78 77
c map to user must be enabled for the Vs100 driver (Jim Gettys)
e
s 00003/00003/00587
d D 6.7 85/08/30 13:47:04 bloom 77 76
c 8600 support
e
s 00013/00009/00577
d D 6.6 85/08/05 19:02:41 bloom 76 75
c add support for 8600
e
s 00007/00001/00579
d D 6.5 85/06/08 14:25:19 mckusick 75 74
c Add copyright
e
s 00005/00003/00575
d D 6.4 85/03/19 17:45:01 mckusick 74 73
c speedups for ubasetup (from speck)
e
s 00107/00022/00471
d D 6.3 85/01/18 11:02:14 karels 73 72
c changes to uba mem configuration: configure before device autoconfig
c on uba, and before device resets on uba reset; change zero-vector code
c for 780 to reset only on unacceptable zero-vector interrupt rate
e
s 00013/00013/00480
d D 6.2 84/08/29 20:10:51 bloom 72 71
c Change to includes.  No more ../h
e
s 00000/00000/00493
d D 6.1 83/08/21 15:42:34 sam 71 70
c 4.2 distribution
e
s 00027/00023/00466
d D 4.62 83/08/21 15:41:50 sam 70 67
c bug fix from greg -- calling ubamem out of order can result in 
c the map register disable bits set wrong; make some sense out of feldman code
e
s 00000/00000/00489
d R 6.1 83/07/31 17:12:28 sam 69 67
c 4.2 distribution
e
s 00000/00000/00489
d R 6.1 83/07/29 07:29:34 sam 68 67
c 4.2 distribution
e
s 00001/00001/00488
d D 4.61 83/03/25 13:38:52 sam 67 66
c base end of char dev table on size, not value of d_open
e
s 00002/00001/00487
d D 4.60 82/12/22 16:48:33 sam 66 65
c yech...for the ikonas in the GENERIC system
e
s 00002/00001/00486
d D 4.59 82/12/17 12:04:19 sam 65 64
c sun merge
e
s 00004/00004/00483
d D 4.58 82/11/26 18:11:55 sam 64 63
c separate sleepers and make things jibe with ubareset
e
s 00002/00000/00485
d D 4.57 82/11/13 23:00:45 sam 63 62
c merge of 4.1b with 4.1c
e
s 00000/00001/00485
d D 4.56 82/10/23 10:35:45 root 62 61
c drop uh_hangcnt
e
s 00005/00004/00481
d D 4.55 82/10/22 00:02:34 root 61 60
c lint
e
s 00001/00114/00484
d D 4.54 82/10/21 21:20:28 root 60 59
c lint
e
s 00002/00000/00596
d D 4.53 82/10/20 01:43:12 root 59 58
c lint
e
s 00004/00003/00592
d D 4.52 82/10/17 20:19:02 root 58 57
c lint
e
s 00000/00000/00595
d D 4.51 82/10/17 11:51:39 root 57 56
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00007/00006/00588
d D 4.50 82/10/10 17:29:20 root 56 55
c header files for vax are in their place
e
s 00001/00001/00593
d D 4.49 82/08/22 21:20:55 root 55 54
c fully uio()'d
e
s 00000/00000/00594
d D 4.48 82/08/13 00:17:33 root 54 53
c changes for char dev uio'ing
e
s 00018/00007/00576
d D 4.47 82/07/21 09:43:09 feldman 53 52
c 3com updates for 780 (from Bill Reeves)
e
s 00019/00000/00564
d D 4.46 82/06/26 22:09:32 sam 52 51
c new stuff for lucas drivers
e
s 00007/00007/00557
d D 4.45 82/05/26 15:44:31 sam 51 50
c 7ZZ -> 730
e
s 00024/00000/00540
d D 4.44 82/05/19 15:34:15 wnj 50 49
c uba resets didn't free up bdp's and map registers
e
s 00028/00000/00512
d D 4.43 82/04/11 01:06:50 feldman 49 48
c support for ec driver
e
s 00013/00021/00499
d D 4.42 82/03/31 09:06:30 wnj 48 47
c clean up way pages are mapped
e
s 00003/00005/00517
d D 4.41 82/03/29 00:48:56 wnj 47 46
c fixes from lucasfilm
e
s 00001/00001/00521
d D 4.40 82/03/14 14:28:21 root 46 45
c #if 0 -> #if notdef
e
s 00003/00000/00519
d D 4.39 81/12/09 20:48:54 wnj 45 44
c stick in ifubareset
e
s 00002/00000/00517
d D 4.38 81/11/20 14:39:30 wnj 44 43
c more lint
e
s 00000/00000/00517
d D 4.37 81/11/18 15:51:14 wnj 43 42
c lint
e
s 00002/00001/00515
d D 4.36 81/11/07 10:38:32 wnj 42 41
c fixes from shannon
e
s 00010/00000/00506
d D 4.35 81/07/22 00:37:58 wnj 41 40
c put in crazy checks in uba.c
e
s 00001/00000/00505
d D 4.34 81/07/08 09:27:42 root 40 39
c clear non-error reporting bits in ubasr in watch routine
e
s 00004/00001/00501
d D 4.33 81/06/30 15:54:55 wnj 39 38
c insert missing splx(a)'s
e
s 00000/00002/00502
d D 4.32 81/06/08 17:11:31 root 38 37
c made ubaremap unconditional
e
s 00065/00000/00439
d D 4.31 81/05/12 17:19:50 root 37 36
c bbn tcp/ip
e
s 00005/00005/00434
d D 4.30 81/04/12 14:38:55 wnj 36 35
c s/730/7zz/
e
s 00002/00002/00437
d D 4.29 81/04/03 00:29:12 wnj 35 34
c print ubasr as %b
e
s 00000/00000/00439
d D 4.28 81/04/03 00:08:35 root 34 33
c s/730/7ZZ
e
s 00001/00001/00438
d D 4.27 81/03/22 21:02:36 wnj 33 32
c fix accounting of dk_words
e
s 00007/00006/00432
d D 4.26 81/03/22 21:00:10 wnj 32 31
c fixes for uba init on 730
e
s 00010/00000/00428
d D 4.25 81/03/21 15:57:42 wnj 31 30
c don't use bdp's on 730
e
s 00000/00000/00428
d D 4.24 81/03/16 00:51:25 wnj 30 29
c working autoconf version
e
s 00003/00003/00425
d D 4.23 81/03/13 21:51:43 wnj 29 28
c typos+nexflt_bits not a variable, now a constant
e
s 00001/00001/00427
d D 4.22 81/03/09 01:55:38 wnj 28 27
c %G% -> %E%
e
s 00002/00003/00426
d D 4.21 81/03/09 00:35:15 wnj 27 26
c lint
e
s 00034/00033/00395
d D 4.20 81/03/06 23:38:15 wnj 26 25
c fixed up
e
s 00014/00008/00414
d D 4.19 81/03/06 11:32:35 wnj 25 24
c new format of error prints; no more FLAKEY UP resets 
c no more delays at resets; print unit numbers at resets
e
s 00005/00003/00417
d D 4.18 81/02/28 17:36:01 wnj 24 23
c rmalloc and related stuff
e
s 00001/00001/00419
d D 4.17 81/02/27 03:15:02 wnj 23 22
c s/HZ/hz/
e
s 00022/00003/00398
d D 4.16 81/02/26 22:10:02 wnj 22 21
c added ubapurge() and fixed up some 750 conditional code
e
s 00002/00002/00399
d D 4.15 81/02/25 23:36:42 wnj 21 20
c convert VAX==??? to VAX???
e
s 00011/00001/00390
d D 4.14 81/02/23 23:44:51 wnj 20 19
c minor typos
e
s 00003/00014/00388
d D 4.13 81/02/23 20:16:02 wnj 19 18
c ud_xclu rather than ==&hkdriver
e
s 00040/00012/00362
d D 4.12 81/02/22 21:46:14 wnj 18 17
c working interlocked system
e
s 00121/00015/00253
d D 4.11 81/02/19 21:58:24 wnj 17 16
c almost working ubago version (tm.c problems)
e
s 00001/00001/00267
d D 4.10 81/02/17 17:33:51 wnj 16 15
c minor cleanups... for dh: DELAY(5)s
e
s 00003/00003/00265
d D 4.9 81/02/17 00:22:37 wnj 15 14
c bug fix to bdp
e
s 00020/00008/00248
d D 4.8 81/02/15 12:09:24 kre 14 13
c bootable autoconf version
e
s 00137/00051/00119
d D 4.7 81/02/10 13:19:33 wnj 13 12
c compilable first uba autoconf version
e
s 00001/00000/00169
d D 4.6 81/01/06 15:49:09 wnj 12 11
c fix to last fix...
e
s 00001/00001/00168
d D 4.5 80/12/30 18:57:40 wnj 11 10
c typo... s/ubafree/ubarelse
e
s 00011/00002/00158
d D 4.4 80/12/30 18:51:14 wnj 10 9
c ubafree() becomes ubarelse() to fix race conditions
e
s 00009/00001/00151
d D 4.3 80/12/17 10:44:17 wnj 9 8
c 750 changes
e
s 00001/00001/00151
d D 4.2 80/11/09 22:55:42 bill 8 7
c minor lint
e
s 00000/00000/00152
d D 4.1 80/11/09 16:52:52 bill 7 6
c stamp for 4bsd
e
s 00005/00013/00147
d D 3.6 80/09/16 17:29:23 bill 6 5
c panic on running out of map registers/bdp's (temp patch)
e
s 00002/00002/00158
d D 3.5 80/08/27 08:37:38 bill 5 4
c buffers allocated in sysmap, ioctls all take addresses
e
s 00003/00003/00157
d D 3.4 80/06/23 17:36:33 bill 4 3
c fix ipl setting in ubareset code
e
s 00021/00000/00139
d D 3.3 80/06/22 12:32:36 bill 3 2
c ubareset
e
s 00001/00001/00138
d D 3.2 80/06/07 02:48:51 bill 2 1
c %H%->%G%
e
s 00139/00000/00000
d D 3.1 80/04/09 16:04:47 bill 1 0
c date and time created 80/04/09 16:04:47 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 28
/*	%M%	%I%	%G%	*/
E 28
I 28
D 55
/*	%M%	%I%	%E%	*/
E 55
I 55
D 56
/*	uba.c	4.48	82/08/13	*/
E 56
I 56
D 75
/*	%M%	%I%	%E%	*/
E 75
I 75
/*
D 82
 * Copyright (c) 1982 Regents of the University of California.
E 82
I 82
D 89
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 82
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 89
I 89
 * Copyright (c) 1982, 1986 The Regents of the University of California.
 * All rights reserved.
 *
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
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 89
 *
 *	%W% (Berkeley) %G%
 */
E 75
E 56
E 55
E 28
E 2

I 65
D 88
#include "../machine/pte.h"

E 88
E 65
I 17
D 27
#define	DELAY(N)	{ register int d; d = N; while (--d > 0); }

E 27
E 17
D 72
#include "../h/param.h"
I 13
#include "../h/systm.h"
D 56
#include "../h/cpu.h"
E 56
E 13
#include "../h/map.h"
D 65
#include "../h/pte.h"
E 65
D 13
#include "../h/uba.h"
E 13
#include "../h/buf.h"
I 17
#include "../h/vm.h"
E 17
I 13
D 26
#include "../h/uba.h"
E 26
I 26
D 56
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 56
E 26
E 13
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
D 17
#include "../h/vm.h"
E 17
I 3
#include "../h/conf.h"
I 9
D 56
#include "../h/mtpr.h"
I 13
#include "../h/nexus.h"
E 56
I 17
#include "../h/dk.h"
I 61
#include "../h/kernel.h"
E 72
I 72
#include "param.h"
#include "systm.h"
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "conf.h"
D 84
#include "dk.h"
E 84
I 84
#include "dkstat.h"
E 84
#include "kernel.h"
E 72
E 61
I 56

I 88
#include "../vax/pte.h"
E 88
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
#include "../vax/nexus.h"
D 72
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 72
I 72
#include "ubareg.h"
#include "ubavar.h"
E 72
E 56
E 17
E 13
E 9
E 3

I 25
D 76
#if VAX780
E 76
I 76
D 83
#if defined(VAX780) || defined(VAX8600)
E 83
I 83
#ifdef DW780
E 83
E 76
char	ubasr_bits[] = UBASR_BITS;
#endif

I 80
#define	spluba	spl7		/* IPL 17 */

I 85
D 88
#define	BDPMASK	0xf0000000	/* see ubavar.h */

E 88
E 85
E 80
E 25
I 18
D 19
#include "rk.h"
#if NRK11 > 0
extern	struct uba_driver hkdriver;
#endif

E 19
E 18
/*
I 17
 * Do transfer on device argument.  The controller
 * and uba involved are implied by the device.
 * We queue for resource wait in the uba code if necessary.
 * We return 1 if the transfer was started, 0 if it was not.
D 85
 * If you call this routine with the head of the queue for a
 * UBA, it will automatically remove the device from the UBA
 * queue before it returns.  If some other device is given
 * as argument, it will be added to the request queue if the
 * request cannot be started immediately.  This means that
 * passing a device which is on the queue but not at the head
 * of the request queue is likely to be a disaster.
E 85
I 85
 *
 * The onq argument must be zero iff the device is not on the
 * queue for this UBA.  If onq is set, the device must be at the
 * head of the queue.  In any case, if the transfer is started,
 * the device will be off the queue, and if not, it will be on.
 *
 * Drivers that allocate one BDP and hold it for some time should
 * set ud_keepbdp.  In this case um_bdp tells which BDP is allocated
 * to the controller, unless it is zero, indicating that the controller
 * does not now have a BDP.
E 85
 */
D 85
ubago(ui)
E 85
I 85
ubaqueue(ui, onq)
E 85
D 26
	register struct uba_dinfo *ui;
E 26
I 26
	register struct uba_device *ui;
I 85
	int onq;
E 85
E 26
{
D 26
	register struct uba_minfo *um = ui->ui_mi;
E 26
I 26
	register struct uba_ctlr *um = ui->ui_mi;
E 26
	register struct uba_hd *uh;
I 85
	register struct uba_driver *ud;
E 85
	register int s, unit;

	uh = &uba_hd[um->um_ubanum];
I 85
	ud = um->um_driver;
E 85
D 80
	s = spl6();
E 80
I 80
	s = spluba();
E 80
I 18
D 19
#if NRK11 > 0
	if (um->um_driver == &hkdriver && uh->uh_users > 0 || uh->uh_xclu)
E 19
I 19
D 85
	if (um->um_driver->ud_xclu && uh->uh_users > 0 || uh->uh_xclu)
E 85
I 85
	/*
	 * Honor exclusive BDP use requests.
	 */
	if (ud->ud_xclu && uh->uh_users > 0 || uh->uh_xclu)
E 85
E 19
		goto rwait;
D 19
#endif
E 19
E 18
D 85
	um->um_ubinfo = ubasetup(um->um_ubanum, um->um_tab.b_actf->b_actf,
	    UBA_NEEDBDP|UBA_CANTWAIT);
E 85
I 85
	if (ud->ud_keepbdp) {
		/*
		 * First get just a BDP (though in fact it comes with
		 * one map register too).
		 */
		if (um->um_bdp == 0) {
			um->um_bdp = uballoc(um->um_ubanum,
				(caddr_t)0, 0, UBA_NEEDBDP|UBA_CANTWAIT);
			if (um->um_bdp == 0)
				goto rwait;
		}
		/* now share it with this transfer */
		um->um_ubinfo = ubasetup(um->um_ubanum,
			um->um_tab.b_actf->b_actf,
			um->um_bdp|UBA_HAVEBDP|UBA_CANTWAIT);
	} else
		um->um_ubinfo = ubasetup(um->um_ubanum,
			um->um_tab.b_actf->b_actf, UBA_NEEDBDP|UBA_CANTWAIT);
E 85
D 18
	if (um->um_ubinfo == 0) {
		if (uh->uh_actf != ui) {
			ui->ui_forw = NULL;
			if (uh->uh_actf == NULL)
				uh->uh_actf = ui;
			else
				uh->uh_actl->ui_forw = ui;
			uh->uh_actl = ui;
		}
		splx(s);
		return (0);
	}
E 18
I 18
	if (um->um_ubinfo == 0)
		goto rwait;
D 19
#if NRK11 > 0
E 19
	uh->uh_users++;
D 19
	if (um->um_driver == &hkdriver)
E 19
I 19
D 85
	if (um->um_driver->ud_xclu)
E 85
I 85
	if (ud->ud_xclu)
E 85
E 19
		uh->uh_xclu = 1;
D 19
#endif
E 19
E 18
	splx(s);
	if (ui->ui_dk >= 0) {
		unit = ui->ui_dk;
		dk_busy |= 1<<unit;
I 47
		dk_xfer[unit]++;
		dk_wds[unit] += um->um_tab.b_actf->b_actf->b_bcount>>6;
E 47
	}
D 85
	if (uh->uh_actf == ui)
E 85
I 85
	if (onq)
E 85
		uh->uh_actf = ui->ui_forw;
D 85
	(*um->um_driver->ud_dgo)(um);
E 85
I 85
	(*ud->ud_dgo)(um);
E 85
D 47
	if (ui->ui_dk >= 0) {
		dk_xfer[unit]++;
D 33
		dk_wds[unit] += um->um_tab.b_actf->b_bcount>>6;
E 33
I 33
		dk_wds[unit] += um->um_tab.b_actf->b_actf->b_bcount>>6;
E 33
	}
E 47
	return (1);
I 18
rwait:
D 85
	if (uh->uh_actf != ui) {
E 85
I 85
	if (!onq) {
E 85
		ui->ui_forw = NULL;
		if (uh->uh_actf == NULL)
			uh->uh_actf = ui;
		else
			uh->uh_actl->ui_forw = ui;
		uh->uh_actl = ui;
	}
	splx(s);
	return (0);
}

ubadone(um)
D 26
	register struct uba_minfo *um;
E 26
I 26
	register struct uba_ctlr *um;
E 26
{
	register struct uba_hd *uh = &uba_hd[um->um_ubanum];

D 19
#if NRK11 > 0
	if (um->um_driver == &hkdriver)
E 19
I 19
	if (um->um_driver->ud_xclu)
E 19
		uh->uh_xclu = 0;
	uh->uh_users--;
I 85
	if (um->um_driver->ud_keepbdp)
		um->um_ubinfo &= ~BDPMASK;	/* keep BDP for misers */
E 85
D 19
#endif
E 19
	ubarelse(um->um_ubanum, &um->um_ubinfo);
E 18
}

/*
E 17
D 13
 * Allocate as many contiguous UBA mapping registers
 * as are necessary to do transfer of bcnt bytes
 * to/from location baddr.  Wait for enough map registers.
E 13
I 13
 * Allocate and setup UBA map registers, and bdp's
 * Flags says whether bdp is needed, whether the caller can't
 * wait (e.g. if the caller is at interrupt level).
E 13
D 88
 *
D 13
 * Bdpflg is non-zero if a "buffered data path" (BDP) is
 * to be used, else 0 -> use direct data path (DDP).  Return
 *
E 13
I 13
D 17
 * Return value (cruft):
E 17
I 17
 * Return value:
E 17
E 13
 *	Bits 0-8	Byte offset
 *	Bits 9-17	Start map reg. no.
 *	Bits 18-27	No. mapping reg's
 *	Bits 28-31	BDP no.
E 88
I 88
 * Return value encodes map register plus page offset,
 * bdp number and number of map registers.
E 88
 */
D 13
ubasetup(bp, bdpflg)
struct buf *bp;
E 13
I 13
ubasetup(uban, bp, flags)
D 86
	struct buf *bp;
E 86
I 86
	int uban;
	register struct buf *bp;
	register int flags;
E 86
E 13
{
I 13
	register struct uba_hd *uh = &uba_hd[uban];
I 86
	register struct pte *pte, *io;
	register int npf;
E 86
E 13
D 58
	register int temp, i;
E 58
I 58
D 74
	register int temp;
E 74
I 74
	int pfnum, temp;
E 74
E 58
D 86
	int npf, reg, bdp;
E 86
I 86
	int reg, bdp;
E 86
	unsigned v;
D 86
	register struct pte *pte, *io;
E 86
	struct proc *rp;
	int a, o, ubinfo;

I 31
D 36
#if VAX730
	if (cpu == VAX_730)
E 36
I 36
D 51
#if VAX7ZZ
	if (cpu == VAX_7ZZ)
E 51
I 51
D 81
#if VAX730
	if (cpu == VAX_730)
E 81
I 81
D 83
#if defined(VAX730) || defined(VAX630)
	if (cpu == VAX_730 || cpu == VAX_630)
E 83
I 83
#ifdef DW730
	if (uh->uh_type == DW730)
E 83
E 81
E 51
E 36
		flags &= ~UBA_NEEDBDP;
#endif
I 83
#ifdef QBA
	if (uh->uh_type == QBA)
		flags &= ~UBA_NEEDBDP;
#endif
E 83
E 31
D 86
	v = btop(bp->b_un.b_addr);
E 86
	o = (int)bp->b_un.b_addr & PGOFSET;
	npf = btoc(bp->b_bcount + o) + 1;
I 88
	if (npf > UBA_MAXNMR)
		panic("uba xfer too big");
E 88
D 80
	a = spl6();
E 80
I 80
	a = spluba();
E 80
D 13
	while ((reg = malloc(ubamap, npf)) == 0) {
I 6
		panic("ran out of uba map");
E 6
		umrwant++;
		sleep((caddr_t)ubamap, PSWP);
E 13
I 13
D 24
	while ((reg = malloc(uh->uh_map, npf)) == 0) {
E 24
I 24
D 61
	while ((reg = rmalloc(uh->uh_map, npf)) == 0) {
E 61
I 61
	while ((reg = rmalloc(uh->uh_map, (long)npf)) == 0) {
E 61
E 24
D 39
		if (flags & UBA_CANTWAIT)
E 39
I 39
		if (flags & UBA_CANTWAIT) {
			splx(a);
E 39
			return (0);
I 39
		}
E 39
		uh->uh_mrwant++;
D 64
		sleep((caddr_t)uh->uh_map, PSWP);
E 64
I 64
		sleep((caddr_t)&uh->uh_mrwant, PSWP);
E 64
E 13
	}
I 73
	if ((flags & UBA_NEED16) && reg + npf > 128) {
		/*
		 * Could hang around and try again (if we can ever succeed).
		 * Won't help any current device...
		 */
		rmfree(uh->uh_map, (long)npf, (long)reg);
		splx(a);
		return (0);
	}
E 73
D 15
	reg--;
E 15
	bdp = 0;
D 13
	if (bdpflg)
		while ((bdp = malloc(bdpmap, 1)) == 0) {
I 6
			panic("ran out of bdp's");
E 6
			bdpwant++;
			sleep((caddr_t)bdpmap, PSWP);
E 13
I 13
	if (flags & UBA_NEEDBDP) {
D 80
		while ((bdp = ffs(uh->uh_bdpfree)) == 0) {
E 80
I 80
		while ((bdp = ffs((long)uh->uh_bdpfree)) == 0) {
E 80
			if (flags & UBA_CANTWAIT) {
D 24
				mfree(uh->uh_map, npf, reg);
E 24
I 24
D 61
				rmfree(uh->uh_map, npf, reg);
E 61
I 61
				rmfree(uh->uh_map, (long)npf, (long)reg);
E 61
I 39
				splx(a);
E 39
E 24
				return (0);
			}
			uh->uh_bdpwant++;
D 64
			sleep((caddr_t)uh->uh_map, PSWP);
E 64
I 64
			sleep((caddr_t)&uh->uh_bdpwant, PSWP);
E 64
E 13
		}
I 13
D 15
		uh->uh_bdpfree &= ~ (1<<bdp);
E 15
I 15
		uh->uh_bdpfree &= ~(1 << (bdp-1));
E 15
D 42
	}
E 42
I 42
	} else if (flags & UBA_HAVEBDP)
		bdp = (flags >> 28) & 0xf;
E 42
E 13
	splx(a);
I 15
	reg--;
E 15
D 88
	ubinfo = (bdp << 28) | (npf << 18) | (reg << 9) | o;
E 88
I 88
	ubinfo = UBAI_INFO(o, reg, npf, bdp);
E 88
D 13
	io = &(((struct uba_regs *)UBA0)->uba_map[reg]);
	temp = (bdp << 21) | MRV;
E 13
I 13
D 48
	io = &uh->uh_uba->uba_map[reg];
E 48
D 26
	temp = (bdp << 21) | UBA_MRV;
E 26
I 26
	temp = (bdp << 21) | UBAMR_MRV;
E 26
E 13
D 48
	rp = bp->b_flags&B_DIRTY ? &proc[2] : bp->b_proc;
E 48
	if (bdp && (o & 01))
D 13
		temp |= BO;
E 13
I 13
D 26
		temp |= UBA_BO;
E 26
I 26
		temp |= UBAMR_BO;
E 26
E 13
D 48
	if (bp->b_flags & B_UAREA) {
		for (i = UPAGES - bp->b_bcount / NBPG; i < UPAGES; i++) {
			if (rp->p_addr[i].pg_pfnum == 0)
				panic("uba: zero upage");
			*(int *)io++ = rp->p_addr[i].pg_pfnum | temp;
		}
	} else if ((bp->b_flags & B_PHYS) == 0) {
E 48
I 48
D 86
	rp = bp->b_flags&B_DIRTY ? &proc[2] : bp->b_proc;
E 86
	if ((bp->b_flags & B_PHYS) == 0)
E 48
D 5
		v &= 0x1fffff;			/* drop to physical addr */
E 5
I 5
D 86
		pte = &Sysmap[btop(((int)bp->b_un.b_addr)&0x7fffffff)];
E 5
D 48
		while (--npf != 0)
D 5
			*(int *)io++ = v++ | temp;
E 5
I 5
			*(int *)io++ = pte++->pg_pfnum | temp;
E 5
	} else {
		if (bp->b_flags & B_PAGET)
			pte = &Usrptmap[btokmx((struct pte *)bp->b_un.b_addr)];
		else
			pte = vtopte(rp, v);
		while (--npf != 0) {
			if (pte->pg_pfnum == 0)
				panic("uba zero uentry");
			*(int *)io++ = pte++->pg_pfnum | temp;
		}
E 48
I 48
	else if (bp->b_flags & B_UAREA)
		pte = &rp->p_addr[v];
E 86
I 86
		pte = kvtopte(bp->b_un.b_addr);
E 86
	else if (bp->b_flags & B_PAGET)
		pte = &Usrptmap[btokmx((struct pte *)bp->b_un.b_addr)];
D 86
	else
		pte = vtopte(rp, v);
E 86
I 86
	else {
		rp = bp->b_flags&B_DIRTY ? &proc[2] : bp->b_proc;
		v = btop(bp->b_un.b_addr);
		if (bp->b_flags & B_UAREA)
			pte = &rp->p_addr[v];
		else
			pte = vtopte(rp, v);
	}
E 86
D 83
	io = &uh->uh_uba->uba_map[reg];
E 83
I 83
	io = &uh->uh_mr[reg];
E 83
D 86
	while (--npf != 0) {
E 86
I 86
	while (--npf > 0) {
E 86
D 74
		if (pte->pg_pfnum == 0)
E 74
I 74
		pfnum = pte->pg_pfnum;
		if (pfnum == 0)
E 74
			panic("uba zero uentry");
D 74
		*(int *)io++ = pte++->pg_pfnum | temp;
E 74
I 74
		pte++;
		*(int *)io++ = pfnum | temp;
E 74
E 48
	}
D 86
	*(int *)io++ = 0;
E 86
I 86
	*(int *)io = 0;
E 86
	return (ubinfo);
}

D 6
struct	buf ubabuf;
E 6
/*
D 17
 * Non buffer unibus interface... set up a buffer and call ubasetup.
E 17
I 17
 * Non buffer setup interface... set up a buffer and call ubasetup.
E 17
 */
D 13
uballoc(addr, bcnt, bdpflg)
E 13
I 13
uballoc(uban, addr, bcnt, flags)
I 27
	int uban;
E 27
E 13
	caddr_t addr;
D 27
	unsigned short bcnt;
E 27
I 27
	int bcnt, flags;
E 27
{
D 6
	register int a, ubinfo;
E 6
I 6
	struct buf ubabuf;
E 6

D 6
	a = spl6();
	while (ubabuf.b_flags & B_BUSY) {
		ubabuf.b_flags |= B_WANTED;
		sleep((caddr_t)&ubabuf, PRIUBA);
	}
E 6
	ubabuf.b_un.b_addr = addr;
	ubabuf.b_flags = B_BUSY;
	ubabuf.b_bcount = bcnt;
D 6
	splx(a);
	ubinfo = ubasetup(&ubabuf, bdpflg);
	ubabuf.b_flags &= ~B_BUSY;
	if (ubabuf.b_flags & B_WANTED)
		wakeup((caddr_t)&ubabuf);
	return (ubinfo);
E 6
I 6
	/* that's all the fields ubasetup() needs */
D 13
	return (ubasetup(&ubabuf, bdpflg));
E 13
I 13
	return (ubasetup(uban, &ubabuf, flags));
E 13
E 6
}
 
D 10
ubafree(mr)
	int mr;
E 10
I 10
/*
D 17
 * Old ubafree(info) is now ubarelse(&info) to avoid races.
E 17
I 17
 * Release resources on uba uban, and then unblock resource waiters.
 * The map register parameter is by value since we need to block
 * against uba resets on 11/780's.
E 17
 */
D 11
ubafree(amr)
E 11
I 11
D 13
ubarelse(amr)
E 13
I 13
ubarelse(uban, amr)
E 13
E 11
	int *amr;
E 10
{
I 13
	register struct uba_hd *uh = &uba_hd[uban];
E 13
D 17
	register int bdp, reg, npf, a;
E 17
I 17
	register int bdp, reg, npf, s;
E 17
I 10
	int mr;
E 10
 
D 17
	a = spl6();
E 17
I 17
	/*
	 * Carefully see if we should release the space, since
	 * it may be released asynchronously at uba reset time.
	 */
D 80
	s = spl6();
E 80
I 80
	s = spluba();
E 80
E 17
I 10
	mr = *amr;
	if (mr == 0) {
D 17
		splx(a);
E 17
I 17
		/*
		 * A ubareset() occurred before we got around
		 * to releasing the space... no need to bother.
		 */
		splx(s);
E 17
		return;
	}
I 12
	*amr = 0;
I 17
D 73
	splx(s);		/* let interrupts in, we're safe for a while */
E 73
E 17
E 12
E 10
D 88
	bdp = (mr >> 28) & 0x0f;
E 88
I 88
	bdp = UBAI_BDP(mr);
E 88
	if (bdp) {
D 13
		((struct uba_regs *)UBA0)->uba_dpr[bdp] |= BNE;	/* purge */
		mfree(bdpmap, 1, bdp);
		if (bdpwant) {
			bdpwant = 0;
			wakeup((caddr_t)bdpmap);
E 13
I 13
D 14
		uh->uh_uba->uba_dpr[bdp] |= UBA_BNE;
E 14
I 14
D 22
		switch (cpu)
		{
E 22
I 22
D 83
		switch (cpu) {
E 22
D 76
#if VAX780
E 76
I 76
#if defined(VAX780) || defined(VAX8600)
		case VAX_8600:
E 76
		case VAX_780:
E 83
I 83
		switch (uh->uh_type) {
I 86
#ifdef DWBUA
		case DWBUA:
			BUA(uh->uh_uba)->bua_dpr[bdp] |= BUADPR_PURGE;
			break;
#endif
E 86
#ifdef DW780
		case DW780:
E 83
D 26
			uh->uh_uba->uba_dpr[bdp] |= UBA_BNE;
E 26
I 26
			uh->uh_uba->uba_dpr[bdp] |= UBADPR_BNE;
E 26
			break;
#endif
D 83
#if VAX750
		case VAX_750:
E 83
I 83
#ifdef DW750
		case DW750:
E 83
D 26
			uh->uh_uba->uba_dpr[bdp] |= UBA_PURGE|UBA_NXM|UBA_UCE;
E 26
I 26
			uh->uh_uba->uba_dpr[bdp] |=
			    UBADPR_PURGE|UBADPR_NXM|UBADPR_UCE;
E 26
			break;
#endif
I 83
		default:
			break;
E 83
		}
E 14
D 15
		uh->uh_bdpfree |= 1 << bdp;
E 15
I 15
D 17
		uh->uh_bdpfree |= 1 << (bdp-1);
E 17
I 17
		uh->uh_bdpfree |= 1 << (bdp-1);		/* atomic */
E 17
E 15
		if (uh->uh_bdpwant) {
			uh->uh_bdpwant = 0;
D 64
			wakeup((caddr_t)uh->uh_map);
E 64
I 64
			wakeup((caddr_t)&uh->uh_bdpwant);
E 64
E 13
		}
	}
I 17
	/*
	 * Put back the registers in the resource map.
D 73
	 * The map code must not be reentered, so we do this
	 * at high ipl.
E 73
I 73
	 * The map code must not be reentered,
	 * nor can the registers be freed twice.
	 * Unblock interrupts once this is done.
E 73
	 */
E 17
D 88
	npf = (mr >> 18) & 0x3ff;
	reg = ((mr >> 9) & 0x1ff) + 1;
E 88
I 88
	npf = UBAI_NMR(mr);
	reg = UBAI_MR(mr) + 1;
E 88
I 17
D 73
	s = spl6();
E 73
E 17
D 13
	mfree(ubamap, npf, reg);
	if (umrwant) {
		umrwant = 0;
		wakeup((caddr_t)ubamap);
E 13
I 13
D 24
	mfree(uh->uh_map, npf, reg);
E 24
I 24
D 61
	rmfree(uh->uh_map, npf, reg);
E 61
I 61
	rmfree(uh->uh_map, (long)npf, (long)reg);
E 61
E 24
I 17
	splx(s);

	/*
	 * Wakeup sleepers for map registers,
	 * and also, if there are processes blocked in dgo(),
	 * give them a chance at the UNIBUS.
	 */
E 17
	if (uh->uh_mrwant) {
		uh->uh_mrwant = 0;
D 64
		wakeup((caddr_t)uh->uh_map);
E 64
I 64
		wakeup((caddr_t)&uh->uh_mrwant);
E 64
E 13
	}
D 17
	splx(a);
E 17
I 17
D 85
	while (uh->uh_actf && ubago(uh->uh_actf))
E 85
I 85
	while (uh->uh_actf && ubaqueue(uh->uh_actf, 1))
E 85
		;
E 17
}

I 22
ubapurge(um)
D 26
	register struct uba_minfo *um;
E 26
I 26
	register struct uba_ctlr *um;
E 26
{
	register struct uba_hd *uh = um->um_hd;
D 88
	register int bdp = (um->um_ubinfo >> 28) & 0x0f;
E 88
I 88
	register int bdp = UBAI_BDP(um->um_ubinfo);
E 88

D 83
	switch (cpu) {
D 76
#if VAX780
E 76
I 76
#if defined(VAX780) || defined(VAX8600)
	case VAX_8600:
E 76
	case VAX_780:
E 83
I 83
	switch (uh->uh_type) {
I 86
#ifdef DWBUA
	case DWBUA:
		BUA(uh->uh_uba)->bua_dpr[bdp] |= BUADPR_PURGE;
		break;
#endif
E 86
#ifdef DW780
	case DW780:
E 83
D 26
		uh->uh_uba->uba_dpr[bdp] |= UBA_BNE;
E 26
I 26
		uh->uh_uba->uba_dpr[bdp] |= UBADPR_BNE;
E 26
		break;
#endif
D 83
#if VAX750
	case VAX_750:
E 83
I 83
#ifdef DW750
	case DW750:
E 83
D 26
		uh->uh_uba->uba_dpr[bdp] |= UBA_PURGE|UBA_NXM|UBA_UCE;
E 26
I 26
		uh->uh_uba->uba_dpr[bdp] |= UBADPR_PURGE|UBADPR_NXM|UBADPR_UCE;
E 26
		break;
#endif
I 83
	default:
		break;
E 83
	}
}

I 50
ubainitmaps(uhp)
	register struct uba_hd *uhp;
{

I 88
	if (uhp->uh_memsize > UBA_MAXMR)
		uhp->uh_memsize = UBA_MAXMR;
E 88
D 61
	rminit(uhp->uh_map, NUBMREG, 1, "uba", UAMSIZ);
E 61
I 61
D 83
	rminit(uhp->uh_map, (long)NUBMREG, (long)1, "uba", UAMSIZ);
E 61
	switch (cpu) {
D 76
#if VAX780
E 76
I 76
#if defined(VAX780) || defined(VAX8600)
	case VAX_8600:
E 76
	case VAX_780:
E 83
I 83
	rminit(uhp->uh_map, (long)uhp->uh_memsize, (long)1, "uba", UAMSIZ);
	switch (uhp->uh_type) {
I 86
#ifdef DWBUA
	case DWBUA:
		uhp->uh_bdpfree = (1<<NBDPBUA) - 1;
		break;
#endif
E 86
#ifdef DW780
	case DW780:
E 83
		uhp->uh_bdpfree = (1<<NBDP780) - 1;
		break;
#endif
D 83
#if VAX750
	case VAX_750:
E 83
I 83
#ifdef DW750
	case DW750:
E 83
		uhp->uh_bdpfree = (1<<NBDP750) - 1;
		break;
#endif
D 51
#if VAX7ZZ
	case VAX_7ZZ:
E 51
I 51
D 81
#if VAX730
E 81
I 81
D 83
#if defined(VAX730) || defined(VAX630)
E 81
	case VAX_730:
I 81
	case VAX_630:
E 83
I 83
	default:
E 83
E 81
E 51
		break;
D 83
#endif
E 83
	}
}

E 50
E 22
D 13
ubainit()
{

	mfree(ubamap, 496, 1);
D 9
	mfree(bdpmap, 15, 1);
E 9
I 9
	mfree(bdpmap, NUBABDP, 1);
E 9
I 3
}

E 13
D 17
#define	DELAY(N)	{ register int d; d = N; while (--d > 0); }

E 17
I 17
/*
 * Generate a reset on uba number uban.  Then
 * call each device in the character device table,
 * giving it a chance to clean up so as to be able to continue.
 */
E 17
D 13
ubareset()
E 13
I 13
ubareset(uban)
I 17
	int uban;
E 17
E 13
{
D 13
	struct uba_regs *up = (struct uba_regs *)UBA0;
E 13
I 13
D 14
	struct uba_regs *up;
E 14
E 13
	register struct cdevsw *cdp;
I 20
	register struct uba_hd *uh = &uba_hd[uban];
E 20
D 4
	int i;
E 4
I 4
D 8
	int i, s;
E 8
I 8
	int s;
E 8
E 4

D 4
	(void) spl6();
E 4
I 4
D 80
	s = spl6();
E 80
I 80
	s = spluba();
E 80
I 20
	uh->uh_users = 0;
	uh->uh_zvcnt = 0;
	uh->uh_xclu = 0;
D 62
	uh->uh_hangcnt = 0;
E 62
	uh->uh_actf = uh->uh_actl = 0;
	uh->uh_bdpwant = 0;
	uh->uh_mrwant = 0;
I 50
	ubainitmaps(uh);
E 50
	wakeup((caddr_t)&uh->uh_bdpwant);
	wakeup((caddr_t)&uh->uh_mrwant);
E 20
I 13
D 26
	switch (cpu) {
E 13
I 9
D 21
#if VAX==780
E 21
I 21
#if VAX780
E 21
E 9
E 4
D 13
	printf("UBA RESET:");
	up->uba_cr = ADINIT;
	up->uba_cr = IFS|BRIE|USEFIE|SUEFIE;
	while ((up->uba_cnfgr & UBIC) == 0)
		;
E 13
I 13
	case VAX_780:
D 25
		printf("UBA RESET %d:", uban);
E 25
I 25
		printf("uba%d: reset", uban);
E 25
D 20
		ubainit(uba_hd[uban].uh_uba);
E 20
I 20
		ubainit(uh->uh_uba);
E 20
		break;
E 13
I 9
#endif
D 21
#if VAX==750
E 21
I 21
#if VAX750
E 21
D 13
	printf("UNIBUS INIT:");
	mtpr(IUR, 1);
	DELAY(100000);
E 13
I 13
	case VAX_750:
D 25
		printf("UNIBUS INIT:");
E 25
I 25
		printf("uba0: reset");
E 25
		mtpr(IUR, 1);
D 25
		DELAY(100000);
E 25
I 25
		/* give devices time to recover from power fail */
		DELAY(5000000);
E 25
		break;
E 13
#endif
I 13
	}
E 26
I 26
	printf("uba%d: reset", uban);
	ubainit(uh->uh_uba);
I 73
	ubameminit(uban);
E 73
E 26
E 13
E 9
D 67
	for (cdp = cdevsw; cdp->d_open; cdp++)
E 67
I 67
	for (cdp = cdevsw; cdp < cdevsw + nchrdev; cdp++)
E 67
D 13
		(*cdp->d_reset)();
E 13
I 13
		(*cdp->d_reset)(uban);
I 45
D 79
#ifdef INET
E 79
	ifubareset(uban);
D 79
#endif
E 79
E 45
E 13
	printf("\n");
D 4
	(void) spl0();
E 4
I 4
	splx(s);
E 4
E 3
}
I 13

I 22
D 26
#if VAX780
E 26
E 22
D 17
/* pointer rather than number so we can be called with virt and phys addrs */
E 17
I 17
/*
 * Init a uba.  This is called with a pointer
 * rather than a virtual address since it is called
 * by code which runs with memory mapping disabled.
 * In these cases we really don't need the interrupts
 * enabled, but since we run with ipl high, we don't care
 * if they are, they will never happen anyways.
I 83
 * SHOULD GET POINTER TO UBA_HD INSTEAD OF UBA.
E 83
 */
E 17
D 14
ubainit(up)
	register struct uba_regs *up;
E 14
I 14
ubainit(uba)
	register struct uba_regs *uba;
E 14
{
I 83
	register struct uba_hd *uhp;
I 86
#ifdef QBA
E 86
	int isphys = 0;
I 86
#endif
E 86
E 83

D 14
	up->uba_cr = UBA_ADINIT;
	up->uba_cr = UBA_IFS|UBA_BRIE|UBA_USEFIE|UBA_SUEFIE;
	while ((up->uba_cnfgr & UBA_UBIC) == 0)
E 14
I 14
D 26
	uba->uba_cr = UBA_ADINIT;
	uba->uba_cr = UBA_IFS|UBA_BRIE|UBA_USEFIE|UBA_SUEFIE;
	while ((uba->uba_cnfgr & UBA_UBIC) == 0)
E 14
		;
E 26
I 26
D 83
	switch (cpu) {
D 76
#if VAX780
E 76
I 76
#if defined(VAX780) || defined(VAX8600)
	case VAX_8600:
E 76
D 29
	case VAX780:
E 29
I 29
	case VAX_780:
E 83
I 83
	for (uhp = uba_hd; uhp < uba_hd + numuba; uhp++) {
		if (uhp->uh_uba == uba)
			break;
		if (uhp->uh_physuba == uba) {
I 86
#ifdef QBA
E 86
			isphys++;
I 86
#endif
E 86
			break;
		}
	}
	if (uhp >= uba_hd + numuba) {
		printf("init unknown uba\n");
		return;
	}

	switch (uhp->uh_type) {
I 86
#ifdef DWBUA
	case DWBUA:
		BUA(uba)->bua_csr |= BUACSR_UPI;
		/* give devices time to recover from power fail */
		DELAY(500000);
		break;
#endif
E 86
#ifdef DW780
	case DW780:
E 83
E 29
		uba->uba_cr = UBACR_ADINIT;
		uba->uba_cr = UBACR_IFS|UBACR_BRIE|UBACR_USEFIE|UBACR_SUEFIE;
		while ((uba->uba_cnfgr & UBACNFGR_UBIC) == 0)
			;
		break;
#endif
D 83
#if VAX750
D 29
	case VAX750:
E 29
I 29
	case VAX_750:
E 83
I 83
#ifdef DW750
	case DW750:
E 83
E 29
D 32
		mtpr(IUR, 1);
		/* give devices time to recover from power fail */
I 31
/* THIS IS PROBABLY UNNECESSARY */
E 31
		DELAY(5000000);
I 31
/* END PROBABLY UNNECESSARY */
		break;
E 32
#endif
D 36
#if VAX730
	case VAX_730:
E 36
I 36
D 51
#if VAX7ZZ
	case VAX_7ZZ:
E 51
I 51
D 83
#if VAX730
	case VAX_730:
E 83
I 83
#ifdef DW730
	case DW730:
E 83
E 51
E 36
I 32
#endif
D 36
#if defined(VAX750) || defined(VAX730)
E 36
I 36
D 51
#if defined(VAX750) || defined(VAX7ZZ)
E 51
I 51
D 81
#if defined(VAX750) || defined(VAX730)
E 81
I 81
D 83
#if VAX630
	case VAX_630:
E 83
I 83
#ifdef QBA
	case QBA:
E 83
#endif
D 83
#if defined(VAX750) || defined(VAX730) || defined(VAX630)
E 83
I 83
#if DW750 || DW730 || QBA
E 83
E 81
E 51
E 36
		mtpr(IUR, 0);
		/* give devices time to recover from power fail */
/* THIS IS PROBABLY UNNECESSARY */
		DELAY(500000);
/* END PROBABLY UNNECESSARY */
I 83
#ifdef QBA
		/*
		 * Re-enable local memory access
		 * from the Q-bus.
		 */
		if (uhp->uh_type == QBA) {
			if (isphys)
				*((char *)QIOPAGE630 + QIPCR) = Q_LMEAE;
			else
				*(uhp->uh_iopage + QIPCR) = Q_LMEAE;
		}
#endif QBA
E 83
E 32
E 31
		break;
D 83
#endif
E 83
I 83
#endif DW750 || DW730 || QBA
E 83
	}
E 26
}
I 88

#ifdef QBA
/*
 * Determine the interrupt priority of a Q-bus
 * peripheral.  The device probe routine must spl6(),
 * attempt to make the device request an interrupt,
 * delaying as necessary, then call this routine
 * before resetting the device.
 */
qbgetpri()
{
	int pri;
	extern int cvec;

	for (pri = 0x17; pri > 0x14; ) {
		if (cvec && cvec != 0x200)	/* interrupted at pri */
			break;
		pri--;
		splx(pri - 1);
	}
	(void) spl0();
	return (pri);
}
#endif
E 88

I 59
D 60
#ifdef notdef
E 59
I 26
#if VAX780
E 26
D 22
#if VAX780
E 22
I 17
/*
 * Check to make sure the UNIBUS adaptor is not hung,
 * with an interrupt in the register to be presented,
 * but not presenting it for an extended period (5 seconds).
 */
E 17
unhang()
{
	register int uban;

	for (uban = 0; uban < numuba; uban++) {
		register struct uba_hd *uh = &uba_hd[uban];
		register struct uba_regs *up = uh->uh_uba;

		if (up->uba_sr == 0)
			return;
I 40
		up->uba_sr = UBASR_CRD|UBASR_LEB;
E 40
		uh->uh_hangcnt++;
D 23
		if (uh->uh_hangcnt > 5*HZ) {
E 23
I 23
		if (uh->uh_hangcnt > 5*hz) {
E 23
			uh->uh_hangcnt = 0;
D 25
			printf("HANG ");
E 25
I 25
			printf("uba%d: hung\n", uban);
E 25
			ubareset(uban);
		}
	}
}

D 17
/* timeout routine to decrement ``i forgot to interrupt counts */
/* this prevents the counts from growing slowly, which isn't interesting */
E 17
I 17
/*
 * This is a timeout routine which decrements the ``i forgot to
 * interrupt'' counts, on an 11/780.  This prevents slowly growing
 * counts from causing a UBA reset since we are interested only
 * in hang situations.
 */
E 17
ubawatch()
{
	register struct uba_hd *uh;
	register int uban;

I 24
	if (panicstr)
		return;
E 24
	for (uban = 0; uban < numuba; uban++) {
		uh = &uba_hd[uban];
		if (uh->uh_hangcnt)
			uh->uh_hangcnt--;
	}
}

E 60
I 60
D 77
#ifdef VAX780
E 77
I 77
D 83
#if defined(VAX780) || defined(VAX8600)
E 83
I 83
#ifdef DW780
E 83
E 77
E 60
I 41
int	ubawedgecnt = 10;
int	ubacrazy = 500;
I 73
int	zvcnt_max = 5000;	/* in 8 sec */
D 79
int	zvcnt_total;
long	zvcnt_time;
E 79
E 73
E 41
D 17
/* called from locore.s; parameters here (i.e. uvec) are value-result! */
E 17
I 17
/*
D 77
 * This routine is called by the locore code to
 * process a UBA error on an 11/780.  The arguments are passed
E 77
I 77
 * This routine is called by the locore code to process a UBA
 * error on an 11/780 or 8600.  The arguments are passed
E 77
 * on the stack, and value-result (through some trickery).
 * In particular, the uvec argument is used for further
 * uba processing so the result aspect of it is very important.
 * It must not be declared register.
 */
E 17
I 14
/*ARGSUSED*/
E 14
D 73
ubaerror(uban, uh, xx, uvec, uba)
E 73
I 73
ubaerror(uban, uh, ipl, uvec, uba)
E 73
	register int uban;
	register struct uba_hd *uh;
D 73
	int uvec;
E 73
I 73
	int ipl, uvec;
E 73
	register struct uba_regs *uba;
{
	register sr, s;

	if (uvec == 0) {
D 73
		uh->uh_zvcnt++;
		if (uh->uh_zvcnt > 250000) {
D 25
			printf("ZERO VECTOR ");
E 25
I 25
			printf("uba%d: too many zero vectors\n");
E 73
I 73
D 79
		long	dt = time.tv_sec - zvcnt_time;
		zvcnt_total++;
E 79
I 79
		/*
		 * Declare dt as unsigned so that negative values
		 * are handled as >8 below, in case time was set back.
		 */
		u_long	dt = time.tv_sec - uh->uh_zvtime;

		uh->uh_zvtotal++;
E 79
		if (dt > 8) {
D 79
			zvcnt_time = time.tv_sec;
E 79
I 79
			uh->uh_zvtime = time.tv_sec;
E 79
			uh->uh_zvcnt = 0;
		}
		if (++uh->uh_zvcnt > zvcnt_max) {
			printf("uba%d: too many zero vectors (%d in <%d sec)\n",
				uban, uh->uh_zvcnt, dt + 1);
			printf("\tIPL 0x%x\n\tcnfgr: %b  Adapter Code: 0x%x\n",
				ipl, uba->uba_cnfgr&(~0xff), UBACNFGR_BITS,
				uba->uba_cnfgr&0xff);
			printf("\tsr: %b\n\tdcr: %x (MIC %sOK)\n",
				uba->uba_sr, ubasr_bits, uba->uba_dcr,
				(uba->uba_dcr&0x8000000)?"":"NOT ");
E 73
E 25
			ubareset(uban);
		}
D 73
		uvec = 0;
E 73
		return;
	}
	if (uba->uba_cnfgr & NEX_CFGFLT) {
D 25
		printf("UBA%d SBI FAULT sr %x cnfgr %x\n",
		    uban, uba->uba_sr, uba->uba_cnfgr);
E 25
I 25
		printf("uba%d: sbi fault sr=%b cnfgr=%b\n",
		    uban, uba->uba_sr, ubasr_bits,
D 29
		    uba->uba_cnfgr, nexflt_bits);
E 29
I 29
		    uba->uba_cnfgr, NEXFLT_BITS);
E 29
E 25
		ubareset(uban);
		uvec = 0;
		return;
	}
	sr = uba->uba_sr;
D 80
	s = spl7();
E 80
I 80
	s = spluba();
E 80
D 25
	printf("UBA%d ERROR SR %x FMER %x FUBAR %o\n",
E 25
I 25
D 35
	printf("uba%d: uba error sr=%x fmer=%x fubar=%o\n",
E 25
D 14
	    uba->uba_sr, uba->uba_fmer, uba->uba_fubar);
E 14
I 14
D 16
	    uban, uba->uba_sr, uba->uba_fmer, uba->uba_fubar);
E 16
I 16
	    uban, uba->uba_sr, uba->uba_fmer, 4*uba->uba_fubar);
E 35
I 35
	printf("uba%d: uba error sr=%b fmer=%x fubar=%o\n",
	    uban, uba->uba_sr, ubasr_bits, uba->uba_fmer, 4*uba->uba_fubar);
E 35
E 16
E 14
	splx(s);
	uba->uba_sr = sr;
D 26
	uvec &= UBA_DIV;
E 26
I 26
	uvec &= UBABRRVR_DIV;
I 41
	if (++uh->uh_errcnt % ubawedgecnt == 0) {
		if (uh->uh_errcnt > ubacrazy)
			panic("uba crazy");
		printf("ERROR LIMIT ");
		ubareset(uban);
		uvec = 0;
		return;
	}
E 41
E 26
	return;
}
#endif
I 59
D 60
#endif notdef
E 60
E 59
I 37

I 44
D 46
#if 0
E 46
I 46
D 47
#if notdef
E 47
I 47
D 60
#ifdef notdef
E 60
E 47
E 46
E 44
D 38
#ifdef BBNNET
E 38
/*
I 73
 * Look for devices with unibus memory, allow them to configure, then disable
 * map registers as necessary.  Called during autoconfiguration and ubareset.
 * The device ubamem routine returns 0 on success, 1 on success if it is fully
 * configured (has no csr or interrupt, so doesn't need to be probed),
 * and -1 on failure.
 */
ubameminit(uban)
{
	register struct uba_device *ui;
	register struct uba_hd *uh = &uba_hd[uban];
	caddr_t umembase = umem[uban] + 0x3e000, addr;
#define	ubaoff(off)	((int)(off) & 0x1fff)

	uh->uh_lastmem = 0;
	for (ui = ubdinit; ui->ui_driver; ui++) {
		if (ui->ui_ubanum != uban && ui->ui_ubanum != '?')
			continue;
		if (ui->ui_driver->ud_ubamem) {
			/*
			 * During autoconfiguration, need to fudge ui_addr.
			 */
			addr = ui->ui_addr;
			ui->ui_addr = umembase + ubaoff(addr);
			switch ((*ui->ui_driver->ud_ubamem)(ui, uban)) {
			case 1:
				ui->ui_alive = 1;
				/* FALLTHROUGH */
			case 0:
				ui->ui_ubanum = uban;
				break;
			}
			ui->ui_addr = addr;
		}
	}
D 76
#if VAX780
E 76
I 76
D 83
#if defined(VAX780) || defined(VAX8600)
E 83
I 83
#ifdef DW780
E 83
E 76
	/*
D 83
	 * On a 780, throw away any map registers disabled by rounding
E 83
I 83
	 * On a DW780, throw away any map registers disabled by rounding
E 83
	 * the map disable in the configuration register
	 * up to the next 8K boundary, or below the last unibus memory.
	 */
D 76
	if (cpu == VAX_780) {
E 76
I 76
D 83
	if ((cpu == VAX_780) || (cpu == VAX_8600)) {
E 83
I 83
	if (uh->uh_type == DW780) {
E 83
E 76
		register i;

		i = btop(((uh->uh_lastmem + 8191) / 8192) * 8192);
		while (i)
			(void) rmget(uh->uh_map, 1, i--);
	}
#endif
}

/*
E 73
D 60
 * This routine allows remapping of previously
 * allocated UNIBUS bdp and map resources
 * onto different memory addresses.
 * It should only be used by routines which need
 * small fixed length mappings for long periods of time
 * (like the ARPANET ACC IMP interface).
 * It only maps kernel addresses.
 */
ubaremap(uban, ubinfo, addr)
	int uban;
	register unsigned ubinfo;
	caddr_t addr;
{
	register struct uba_hd *uh = &uba_hd[uban];
	register struct pte *pte, *io;
	register int temp, bdp;
	int npf, o;

	o = (int)addr & PGOFSET;
	bdp = (ubinfo >> 28) & 0xf;
	npf = (ubinfo >> 18) & 0x3ff;
	io = &uh->uh_uba->uba_map[(ubinfo >> 9) & 0x1ff];
	temp = (bdp << 21) | UBAMR_MRV;

	/*
	 * If using buffered data path initiate purge
	 * of old data and set byte offset bit if next
	 * transfer will be from odd address.
	 */
	if (bdp) {
		switch (cpu) {
#if VAX780
		case VAX_780:
			uh->uh_uba->uba_dpr[bdp] |= UBADPR_BNE;
			break;
#endif
#if VAX750
		case VAX_750:
			uh->uh_uba->uba_dpr[bdp] |=
			    UBADPR_PURGE|UBADPR_NXM|UBADPR_UCE;
			break;
#endif
		}
		if (o & 1)
			temp |= UBAMR_BO;
	}

	/*
	 * Set up the map registers, leaving an invalid reg
	 * at the end to guard against wild unibus transfers.
	 */
	pte = &Sysmap[btop(((int)addr)&0x7fffffff)];
	while (--npf != 0)
		*(int *)io++ = pte++->pg_pfnum | temp;
	*(int *)io = 0;

	/*
	 * Return effective UNIBUS address.
	 */
	return (ubinfo | o);
}
I 44
#endif
I 49

/*
E 60
D 70
 * This routine is called by a driver for a device with on-board Unibus
 * memory.  It removes the memory block from the Unibus resource map
 * and clears the map registers for the block.
 *
 * Arguments are the Unibus number, the Unibus address of the memory
D 53
 * block, and its size in blocks of 512 bytes.
E 53
I 53
 * block, its size in blocks of 512 bytes, and a flag indicating whether
 * to allocate the unibus space form the resource map or whether it already
 * has been.
E 53
 *
D 53
 * Returns addr if successful, 0 if not.
E 53
I 53
 * Returns > 0 if successful, 0 if not.
E 70
I 70
 * Allocate UNIBUS memory.  Allocates and initializes
 * sufficient mapping registers for access.  On a 780,
 * the configuration register is setup to disable UBA
 * response on DMA transfers to addresses controlled
 * by the disabled mapping registers.
I 73
D 83
 * On a 780, should only be called from ubameminit, or in ascending order
E 83
I 83
 * On a DW780, should only be called from ubameminit, or in ascending order
E 83
 * from 0 with 8K-sized and -aligned addresses; freeing memory that isn't
 * the last unibus memory would free unusable map registers.
 * Doalloc is 1 to allocate, 0 to deallocate.
E 73
E 70
E 53
 */
D 60

E 60
D 53
ubamem(uban, addr, size)
E 53
I 53
D 58
ubamem(uban, addr, size, alloc)
E 58
I 58
D 70
ubamem(uban, addr, size, doalloc)
	int uban, addr, size, doalloc;
E 70
I 70
ubamem(uban, addr, npg, doalloc)
	int uban, addr, npg, doalloc;
E 70
E 58
E 53
{
	register struct uba_hd *uh = &uba_hd[uban];
D 70
	register int *m;
	register int i, a, s;
E 70
I 70
	register int a;
I 73
	int s;
E 73
E 70

D 53
	s = spl6();
	a = rmget(uh->uh_map, size, addr>>9);
	splx(s);
E 53
I 53
D 58
	if (alloc) {
E 58
I 58
D 73
	if (doalloc) {
E 58
D 70
		s = spl6();
		a = rmget(uh->uh_map, size, (addr>>9)+1); /* starts at ONE! */
E 70
I 70
		int s = spl6();
		a = rmget(uh->uh_map, npg, (addr >> 9) + 1);
E 70
		splx(s);
	} else
D 70
		a = (addr>>9)+1;
E 70
I 70
		a = (addr >> 9) + 1;
E 73
I 73
	a = (addr >> 9) + 1;
D 80
	s = spl6();
E 80
I 80
	s = spluba();
E 80
	if (doalloc)
		a = rmget(uh->uh_map, npg, a);
	else
		rmfree(uh->uh_map, (long)npg, (long)a);
	splx(s);
E 73
E 70
E 53
	if (a) {
D 53
		m = (int *) &uh->uh_uba->uba_map[a];
E 53
I 53
D 70
		m = (int *) &uh->uh_uba->uba_map[a-1];
E 53
		for (i=0; i<size; i++)
E 70
I 70
		register int i, *m;

D 83
		m = (int *)&uh->uh_uba->uba_map[a - 1];
E 83
I 83
		m = (int *)&uh->uh_mr[a - 1];
E 83
		for (i = 0; i < npg; i++)
E 70
			*m++ = 0;	/* All off, especially 'valid' */
I 73
		i = addr + npg * 512;
		if (doalloc && i > uh->uh_lastmem)
			uh->uh_lastmem = i;
		else if (doalloc == 0 && i == uh->uh_lastmem)
			uh->uh_lastmem = addr;
E 73
I 53
D 76
#if VAX780
E 76
I 76
D 83
#if defined(VAX780) || defined(VAX8600)
E 83
I 83
#ifdef DW780
E 83
E 76
D 70
		if (cpu == VAX_780) {		/* map disable */
			i = (addr+size*512+8191)/8192;
			uh->uh_uba->uba_cr |= i<<26;
E 70
I 70
		/*
		 * On a 780, set up the map register disable
		 * field in the configuration register.  Beware
D 73
		 * of callers that request memory ``out of order''.
E 73
I 73
		 * of callers that request memory ``out of order''
		 * or in sections other than 8K multiples.
		 * Ubameminit handles such requests properly, however.
E 73
		 */
D 76
		if (cpu == VAX_780) {
E 76
I 76
D 83
		if ((cpu == VAX_780) || (cpu == VAX_8600)) {
E 83
I 83
		if (uh->uh_type == DW780) {
E 83
E 76
D 73
			int cr = uh->uh_uba->uba_cr;

			i = (addr + npg * 512 + 8191) / 8192;
			if (i > (cr >> 26))
				uh->uh_uba->uba_cr |= i << 26;
E 73
I 73
			i = uh->uh_uba->uba_cr &~ 0x7c000000;
			i |= ((uh->uh_lastmem + 8191) / 8192) << 26;
			uh->uh_uba->uba_cr = i;
E 73
E 70
		}
#endif
E 53
	}
D 70
	return(a);
E 70
I 70
	return (a);
E 70
}
I 52

I 63
D 66
#ifdef notdef
E 66
I 66
#include "ik.h"
D 78
#if NIK > 0
E 78
I 78
#include "vs.h"
#if NIK > 0 || NVS > 0
E 78
E 66
E 63
/*
 * Map a virtual address into users address space. Actually all we
 * do is turn on the user mode write protection bits for the particular
 * page of memory involved.
 */
maptouser(vaddress)
	caddr_t vaddress;
{

D 86
	Sysmap[(((unsigned)(vaddress))-0x80000000) >> 9].pg_prot = (PG_UW>>27);
E 86
I 86
	kvtopte(vaddress)->pg_prot = (PG_UW >> 27);
E 86
}

unmaptouser(vaddress)
	caddr_t vaddress;
{

D 86
	Sysmap[(((unsigned)(vaddress))-0x80000000) >> 9].pg_prot = (PG_KW>>27);
E 86
I 86
	kvtopte(vaddress)->pg_prot = (PG_KW >> 27);
E 86
}
I 63
#endif
E 63
E 52
E 49
E 44
D 38
#endif
E 38
E 37
E 13
E 1
