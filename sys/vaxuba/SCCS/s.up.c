h25422
s 00001/00001/01079
d D 7.6 88/10/22 15:14:33 karels 127 126
c use ubaalloc macros; use qbgetpri for Q-bus device probe routines
e
s 00001/00001/01079
d D 7.5 88/06/28 15:36:48 kre 126 125
c deleted stray printf arg
e
s 00008/00004/01072
d D 7.4 88/05/27 16:10:47 karels 125 124
c new diskerr routine
e
s 00001/00024/01075
d D 7.3 88/05/06 17:17:22 bostic 124 123
c changes for raw{read,write} stuff
e
s 00001/00001/01098
d D 7.2 87/01/14 08:48:05 karels 123 122
c rename dk.h to dkstat.h
e
s 00001/00001/01098
d D 7.1 86/06/05 01:21:09 mckusick 122 121
c 4.3BSD release version
e
s 00005/00005/01094
d D 6.11 86/05/02 11:45:11 karels 121 120
c watch for partial sectors in ecc routine, correct ptob=>dbtob
e
s 00001/00001/01098
d D 6.10 86/02/23 23:19:44 karels 120 119
c lint
e
s 00001/00001/01098
d D 6.9 85/09/17 19:14:28 eric 119 118
c facilities in syslog
e
s 00003/00001/01096
d D 6.8 85/09/16 22:10:37 karels 118 117
c off by one, and need resid
e
s 00029/00022/01068
d D 6.7 85/09/14 17:21:11 bloom 117 116
c get rid of interleave code, add macro to get unit number, add error return
c codes to strategy, reading last block after end of partition returns size = 0
e
s 00003/00001/01087
d D 6.6 85/08/08 13:53:33 bloom 116 115
c support partial dumps for large memory
e
s 00007/00001/01081
d D 6.5 85/06/08 14:27:19 mckusick 115 114
c Add copyright
e
s 00013/00002/01069
d D 6.4 85/06/04 14:05:16 bloom 114 113
c add support for eagle on sc31 and fix spl's
e
s 00002/00001/01069
d D 6.3 85/03/12 15:31:48 ralph 113 112
c change softecc printf's to log's.
e
s 00016/00016/01054
d D 6.2 84/08/29 20:11:03 bloom 112 111
c Change to includes.  No more ../h
e
s 00000/00000/01070
d D 6.1 83/07/29 07:30:05 sam 111 110
c 4.2 distribution
e
s 00010/00000/01060
d D 4.77 83/07/20 12:39:52 sam 110 109
c add dm980 for robert
e
s 00004/00002/01056
d D 4.76 83/07/09 14:36:50 sam 109 107
c use longword aligned access to keep 730's happy
e
s 00003/00002/01056
d R 4.76 83/07/09 01:09:21 sam 108 107
c insure longword aligned access to uba map for 730's
e
s 00014/00022/01044
d D 4.75 83/05/30 20:24:02 sam 107 106
c made upSDIST and upRDIST a per drive-type attribute
e
s 00001/00001/01065
d D 4.74 83/05/27 13:52:58 sam 106 105
c lint
e
s 00013/00000/01053
d D 4.73 83/05/18 02:21:28 sam 105 104
c add entry point for swap partition sizing at boot time
e
s 00000/00002/01053
d D 4.72 83/03/23 09:40:49 helge 104 103
c removed leftover code in upattach
e
s 00022/00013/01033
d D 4.71 83/02/21 18:00:25 sam 103 102
c standard disk partitions
e
s 00022/00008/01024
d D 4.70 83/02/17 13:57:27 sam 102 100
c modularize type mapping; handle 9300 separate from 9766
e
s 00021/00008/01024
d R 4.70 83/02/17 12:02:06 sam 101 100
c modularize type mapping
e
s 00008/00002/01024
d D 4.69 83/02/17 08:50:11 helge 100 98
c code to recognize 9300, should give cdc's new partition table
e
s 00008/00002/01024
d R 4.69 83/02/16 19:10:23 helge 99 98
c hack for 9300s, new partition table should be made for cdc
e
s 00007/00000/01019
d D 4.68 83/02/10 22:59:58 helge 98 97
c always search bad sector table on hard HCRC errors
e
s 00001/00000/01018
d D 4.67 83/02/10 18:44:18 sam 97 96
c hz not in systm.h anymore
e
s 00003/00030/01015
d D 4.66 83/02/10 16:50:14 sam 96 95
c everybody has space reserved for bad sectors
e
s 00000/00002/01045
d D 4.65 82/12/17 16:58:57 helge 95 94
c removed extraneous `ecc soft err'  message
e
s 00001/00001/01046
d D 4.64 82/12/17 12:04:49 sam 94 93
c sun merge
e
s 00001/00000/01046
d D 4.63 82/12/08 09:48:24 helge 93 92
c missed a line in last merge
e
s 00158/00059/00888
d D 4.62 82/12/05 21:45:08 sam 92 91
c merge back in bad block code after screwey branch delta
e
s 00001/00001/00946
d D 4.61 82/11/26 18:17:54 sam 91 89
c don't call ubadone at ubareset time
e
s 00189/00077/00845
d D 4.45.1.1 82/10/10 21:21:15 root 90 74
c bad block handling
e
s 00006/00006/00941
d D 4.60 82/10/10 21:13:07 root 89 88
c vax headers
e
s 00004/00006/00943
d D 4.59 82/09/12 03:11:25 root 88 87
c 
e
s 00003/00002/00946
d D 4.58 82/08/22 21:22:02 root 87 86
c fully uio()'d
e
s 00005/00003/00943
d D 4.57 82/08/13 00:17:58 root 86 85
c changes for char dev uio'ing
e
s 00001/00001/00945
d D 4.56 82/07/15 20:00:28 kre 85 84
c probe routines return size of unibus dev regs to reserve space
e
s 00006/00003/00940
d D 4.55 82/06/14 22:42:51 root 84 83
c fixes to ecc code
e
s 00001/00000/00942
d D 4.54 82/06/05 21:26:21 wnj 83 82
c debugging printf
e
s 00003/00002/00939
d D 4.53 82/05/27 08:57:09 wnj 82 81
c fix to reeves fix of dgo handling (reset b_active to 1)
e
s 00002/00002/00939
d D 4.52 82/05/19 15:29:42 sam 81 80
c typos
e
s 00002/00002/00939
d D 4.51 82/05/19 01:21:31 sam 80 79
c name conflict with sc750 related tables in hp.c
e
s 00023/00009/00918
d D 4.50 82/05/19 01:16:33 sam 79 78
c change dump code to mimic mdec/upboot.s
e
s 00001/00000/00926
d D 4.49 82/05/19 00:54:52 wnj 78 77
c fix from tef to use UP_NOP so dont get spurious drives which arent there
e
s 00001/00001/00925
d D 4.48 82/04/30 13:06:27 sam 77 76
c missing sccs keywords
e
s 00003/00003/00923
d D 4.47 82/04/30 13:01:34 sam 76 75
c new sizes for capricorn drives (d,e, and f)
e
s 00005/00001/00921
d D 4.46 82/04/01 18:40:01 wnj 75 74
c fix for ernie
e
s 00003/00002/00919
d D 4.45 82/03/31 09:07:43 wnj 74 73
c fix for fujis with 8 units
e
s 00010/00005/00911
d D 4.44 82/03/29 00:48:06 wnj 73 72
c fixes from lucasfilm
e
s 00001/00001/00915
d D 4.43 82/03/24 22:11:41 root 72 71
c restore id keywords
e
s 00016/00005/00900
d D 4.42 82/03/24 22:09:34 root 71 70
c ampex hack
e
s 00003/00002/00902
d D 4.41 82/01/17 20:13:01 root 70 69
c make bio and disk drivers not do spl0 so can call from panic without trap 2's
e
s 00001/00000/00903
d D 4.40 81/11/18 15:51:21 wnj 69 68
c lint
e
s 00012/00003/00891
d D 4.39 81/05/11 01:26:44 root 68 67
c fix sizes and NOBADSECT
e
s 00001/00001/00893
d D 4.38 81/04/18 11:52:30 wnj 67 66
c s/10/9/ in fuji kludge
e
s 00012/00008/00882
d D 4.37 81/04/09 15:12:09 root 66 65
c rmhr reading hack for fujitsu added (sc21 only)
e
s 00030/00025/00860
d D 4.36 81/04/02 15:15:20 root 65 64
c fixup ecc code to work
e
s 00010/00004/00875
d D 4.35 81/04/01 01:57:39 wnj 64 63
c ecc fixes and some extra prints for a while
e
s 00001/00001/00878
d D 4.34 81/03/10 16:56:34 wnj 63 62
c ht typos; mba maintain dk_busy for seeks; up minor fixes; va and vp new working versions
e
s 00039/00025/00840
d D 4.33 81/03/09 20:02:31 wnj 62 61
c fixes to offset recovery code
e
s 00000/00000/00865
d D 4.32 81/03/09 01:55:48 wnj 61 60
c %G% -> %E%
e
s 00002/00003/00863
d D 4.31 81/03/09 00:35:23 wnj 60 59
c lint
e
s 00032/00032/00834
d D 4.30 81/03/07 14:28:55 wnj 59 58
c after attempt at ht driver at cc again; working with new 
c field names
e
s 00013/00027/00853
d D 4.29 81/03/06 11:35:04 wnj 58 57
c new formats... new !RDY code... no more FLAKEY up 
c no delay after ubareset
e
s 00024/00027/00856
d D 4.28 81/03/03 12:39:30 wnj 57 56
c further driver work... up now handles spin down; rest still dont
e
s 00004/00007/00879
d D 4.27 81/02/28 17:36:13 wnj 56 55
c rmalloc and related stuff
e
s 00002/00002/00884
d D 4.26 81/02/27 03:15:07 wnj 55 54
c s/HZ/hz/
e
s 00001/00002/00885
d D 4.25 81/02/26 21:58:26 wnj 54 53
c call ubapurge() which works on 750's
e
s 00001/00001/00886
d D 4.24 81/02/26 04:28:43 wnj 53 52
c cosmetic for new config and 750/780
e
s 00021/00008/00866
d D 4.23 81/02/25 22:27:24 wnj 52 51
c fix to handle drive not ready
e
s 00216/00066/00658
d D 4.22 81/02/25 21:02:55 wnj 51 50
c almost working versions
e
s 00008/00010/00716
d D 4.21 81/02/23 23:44:57 wnj 50 49
c minor typos
e
s 00093/00098/00633
d D 4.20 81/02/23 20:28:52 wnj 49 48
c new names and also recursive upstart check
e
s 00019/00014/00712
d D 4.19 81/02/22 21:46:22 wnj 48 47
c working interlocked system
e
s 00053/00048/00673
d D 4.18 81/02/21 21:20:55 wnj 47 46
c first working uba interlockable version
e
s 00019/00033/00702
d D 4.17 81/02/19 21:58:37 wnj 46 45
c almost working ubago version (tm.c problems)
e
s 00058/00059/00677
d D 4.16 81/02/17 17:33:56 wnj 45 44
c minor cleanups... for dh: DELAY(5)s
e
s 00020/00052/00716
d D 4.15 81/02/16 20:57:56 wnj 44 43
c new minfo strategy
e
s 00014/00022/00754
d D 4.14 81/02/15 12:09:40 kre 43 42
c bootable autoconf version
e
s 00350/00379/00426
d D 4.13 81/02/10 13:19:38 wnj 42 41
c compilable first uba autoconf version
e
s 00087/00066/00718
d D 4.12 81/02/08 01:13:37 wnj 41 40
c last pre-mba version
e
s 00004/00001/00780
d D 4.11 81/01/28 11:45:14 kre 40 39
c fix B_WRITE->B_READ; DCLR & NSECT in hp; dont search if static 1 drive
e
s 00003/00003/00778
d D 4.10 80/12/30 18:51:18 wnj 39 38
c ubafree() becomes ubarelse() to fix race conditions
e
s 00003/00003/00778
d D 4.9 80/12/30 18:18:31 wnj 38 37
c fix ubafree(i), i = 0 to be UBAFREECLR(i) to avoid races
e
s 00011/00011/00770
d D 4.8 80/12/19 15:21:15 wnj 37 36
c DK_N -> XXDK_N
e
s 00001/00001/00780
d D 4.7 80/12/19 11:44:08 wnj 36 35
c s,../conf/,,
e
s 00002/00002/00779
d D 4.6 80/12/19 11:34:00 wnj 35 34
c SC11 > 0 rather than ifdef SC11
e
s 00004/00000/00777
d D 4.5 80/12/17 10:45:07 wnj 34 33
c use up.c.SC11 #ifdef SC11
e
s 00011/00000/00766
d D 4.4 80/11/22 14:45:59 bill 33 32
c handle NEM and MXF errors; delay in uba reset routine
e
s 00002/00000/00764
d D 4.3 80/11/13 19:59:21 bill 32 31
c add conditional on #if NUP > 0
e
s 00004/00004/00760
d D 4.2 80/11/09 22:56:43 bill 31 30
c minor lint
e
s 00000/00000/00764
d D 4.1 80/11/09 16:53:02 bill 30 29
c stamp for 4bsd
e
s 00015/00086/00749
d D 3.29 80/11/09 16:07:34 bill 29 28
c cleanup for reasonable controllers
e
s 00002/00002/00833
d D 3.28 80/10/21 22:04:46 bill 28 27
c adjust hpS/RDIST upS/RDIST to 2/4 from (screwy 3/6, 6/6)
e
s 00001/00001/00834
d D 3.27 80/10/21 21:23:50 bill 27 26
c upSDIST=3, not 6
e
s 00001/00010/00834
d D 3.26 80/10/19 22:16:00 bill 26 25
c ../conf/*.h
e
s 00008/00018/00836
d D 3.25 80/10/13 10:01:09 bill 25 24
c new monitoring; mba not pre-mapped
e
s 00001/00001/00853
d D 3.24 80/09/27 18:03:46 bill 24 23
c fix previous delta which offset WRITES only not READS!!!
e
s 00001/00001/00853
d D 3.23 80/09/27 18:01:42 bill 23 22
c dont servo-offset on write retries
e
s 00014/00009/00840
d D 3.22 80/09/20 18:30:10 bill 22 21
c patch
e
s 00011/00008/00838
d D 3.21 80/09/16 17:33:48 bill 21 20
c fix comments; check cs1&TRE
e
s 00001/00001/00845
d D 3.20 80/07/29 09:15:08 bill 20 19
c new mba stuff
e
s 00001/00003/00845
d D 3.19 80/07/19 19:56:36 bill 19 18
c get rid of OLDUCODE for olducode; fix sccs line
e
s 00014/00018/00834
d D 3.18 80/07/12 19:17:51 bill 18 17
c patchable olducode varable
e
s 00002/00002/00850
d D 3.17 80/07/03 01:43:08 bill 17 16
c RDY 020 -> 0200
e
s 00036/00038/00816
d D 3.16 80/07/01 09:48:40 bill 16 15
c minor fixups
e
s 00041/00000/00813
d D 3.15 80/06/26 00:49:33 bill 15 14
c watchdog
e
s 00019/00019/00794
d D 3.14 80/06/24 19:29:23 bill 14 13
c no swplo
e
s 00025/00000/00788
d D 3.13 80/06/22 12:34:57 bill 13 12
c new driver seems to work now with upreset
e
s 00005/00009/00783
d D 3.12 80/06/21 09:31:08 bill 12 11
c this hangs occasionally when oo 0 vectors
e
s 00089/00068/00703
d D 3.11 80/06/20 15:32:48 bill 11 10
c this works
e
s 00000/00005/00771
d D 3.10 80/06/19 19:06:49 bill 10 9
c clear out junk
e
s 00007/00104/00769
d D 3.9 80/06/19 16:03:07 bill 9 8
c clean up with no content change
e
s 00111/00002/00762
d D 3.8 80/06/19 15:42:33 bill 8 7
c seems to work with csdel0 and csdel2 set to 500
e
s 00001/00091/00763
d D 3.7 80/06/19 10:14:39 bill 7 6
c this doesnt work
e
s 00037/00029/00817
d D 3.6 80/06/19 09:43:17 bill 6 5
c this works when csdel0 is 30 and csdel1 csdel2 are 0
e
s 00085/00015/00761
d D 3.5 80/06/19 07:35:10 bill 5 4
c with tracing, it works!?!
e
s 00028/00016/00748
d D 3.4 80/06/18 14:30:23 bill 4 3
c still has problem with !DRY and hanging, but better with as.
e
s 00013/00016/00751
d D 3.3 80/06/18 10:03:50 bill 3 2
c still get !RDY and as in upintr, but just added as = 1<<unit to fix
e
s 00283/00101/00484
d D 3.2 80/06/18 09:01:30 bill 2 1
c this works when cs1del is set to 1
e
s 00585/00000/00000
d D 3.1 80/06/16 12:32:33 bill 1 0
c date and time created 80/06/16 12:32:33 by bill
e
u
U
t
T
I 8
D 10
int	trc = -1;
int	trcw = 0;
E 10
D 9
#define	D(i)	if (trc&(1<<i)) { if (trcw&(1<<i)) DELAY(1000); } else
E 9
E 8
I 5
D 6
#define	UTRACE
E 6
I 6
D 7
int	trc = -1;
int	trcw = 0;
#define	D(i)	if (trc&(1<<i)) { if (trcw&(1<<i)) DELAY(1000); } else
int	csdel0 = 0;
int	csdel1 = 1000;
int	csdel2 = 2000;
E 7
I 7
D 11
int	csdel0 = 30;
I 8
D 10
int	csdel1 = 0;
E 10
int	csdel2 = 0;
E 8
E 7
E 6
E 5
I 4
int	asdel = 500;
I 8
D 10
int	csdel3 = 100;
E 10
int	softas;
E 11
E 8
E 4
I 2
D 3
int	cs1del;
E 3
I 3
D 7
int	csdel3 = 100;
E 7
E 3
E 2
I 1
D 5
int	printsw;
E 5
D 2
int	slow1 = 1;
int	slow2 = 1;
int	slow3 = 1;
int	slow4 = 1;
E 2
D 19
/*	%H%	%I%	%G%	*/
E 19
I 19
D 42
/*	%M%	%I%	%G%	*/
E 42
I 42
D 71
/*	%M%	%I%	%E%	*/
E 71
I 71
D 73
#define UPECCDEBUG
E 73
D 72
/*	up.c	4.39	81/05/11	*/
E 72
I 72
D 75
/*	%M%	%I%	%E%	*/
E 75
I 75
D 77
/*	up.c	4.45	82/03/31	*/
E 77
I 77
D 115
/*	%M%	%I%	%E%	*/
E 115
I 115
/*
D 122
 * Copyright (c) 1982 Regents of the University of California.
E 122
I 122
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 122
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 115
I 89
D 92
.f
E 92
E 89
E 77
E 75
E 72
E 71
E 42
E 19

I 26
D 36
#include "../conf/up.h"
E 36
I 36
#include "up.h"
E 36
I 32
D 42
#if NUP > 0
E 42
I 42
D 50
#if NSC21 > 0
E 50
I 50
#if NSC > 0
E 50
E 42
I 34
D 35
#ifdef SC11
#include "up.c.SC11"
E 35
I 35
D 41
#if SC11 > 0
#include "../dev/up.c.SC11"
E 35
#else
E 41
E 34
E 32
E 26
I 12
D 14
#define	spl5	spl6
E 14
I 14
D 16
#define	spl5	spl6		/* block clock, for delay loop's sake */
E 16
E 14
E 12
/*
D 21
 * Emulex UNIBUS disk driver with overlapped seeks and ECC recovery.
E 21
I 21
D 90
D 92
 * UNIBUS disk driver with overlapped seeks and ECC recovery.
E 92
I 92
 * UNIBUS disk driver with:
 *	overlapped seeks,
 *	ECC recovery, and
 *	bad sector forwarding.
E 92
E 90
I 90
 * UNIBUS disk driver with:
 *	overlapped seeks,
 *	ECC recovery, and
 *	bad sector forwarding.
E 90
I 57
 *
 * TODO:
D 59
 *	Check out handling of spun-down drives and write lock
E 59
D 65
 *	Add reading of bad sector information and disk layout from sector 1
E 65
D 90
D 92
 *	Add bad sector forwarding code
E 92
E 90
D 65
 *	Check multiple drive handling
D 59
 *	Check dump code
E 59
 *	Check unibus reset code
I 59
 *	Check that offset recovery code, etc works
E 65
I 65
 *	Check that offset recovery code works
E 65
E 59
E 57
E 21
D 29
 *
I 2
D 16
 * NB: This device is very sensitive: be aware that the code is the way
 *     it is for good reason and that there are delay loops here which may
 *     have to be lengthened if your processor is faster and which should
 *     probably be shortened if your processor is slower.
E 16
I 16
D 21
 * NB: This driver works reliably only on an SC-11B controller with
 *     rev. level at least J (in particular rev. level H will not work well).
D 18
 *     If you have an older controller you may be able to get by if you
 *		#define	OLDUCODE
 *     which implements larger delays for slow ucode.
E 18
I 18
 *     If you have an newer controller you should change olducode below to:
 *		int	olducode = 0;
 *     which saves time by stalling less in the system.
E 21
I 21
 * This driver works marginally on an Emulex SC-11B controller with rev
 * level J microcode, defining:
 *	int	olducode = 1;
 * to force CPU stalling delays.
E 21
E 18
E 16
 *
E 2
D 16
 * This driver has been tested on a SC-11B Controller, configured
 * with the following internal switch settings:
E 16
I 16
D 21
 * Controller switch settings:
E 21
I 21
 * It has worked with no delays and no problems on a prototype
 * SC-21 controller.  Emulex intends to upgrade all SC-11s on VAXes to SC-21s.
 * You should get a SC-21 to replace any SC-11 on a VAX.
 *
 * SC-11B Controller switch settings:
E 21
E 16
 *	SW1-1	5/19 surfaces	(off, 19 surfaces on Ampex 9300)
 *	SW1-2	chksum enable	(off, checksum disabled)
 *	SW1-3	volume select	(off, 815 cylinders)
 *	SW1-4	sector select	(on, 32 sectors)
 *	SW1-5	unused		(off)
 *	SW1-6	port select	(on, single port)
 *	SW1-7	npr delay	(off, disable)
 *	SW1-8	ecc test mode	(off, disable)
 * and top mounted switches:
 *	SW2-1	extend opcodes	(off=open, disable)
 *	SW2-2	extend diag	(off=open, disable)
D 16
 *	SW2-3	4 wd dma burst	(off=open, disable)
E 16
I 16
 *	SW2-3	4 wd dma burst	(on=closed, enable)
E 16
 *	SW2-4	unused		(off=open)
E 29
D 16
 *
 * The controller transfers data much more rapidly with SW2-3 set,
 * but we have previously experienced problems with it set this way.
 * We intend to try this again in the near future.
 *
D 14
 *	wnj	June 14, 1980
E 14
I 14
 * NB: OUR SYSTEM CURRENTLY GETS UBA ERRORS WHEN RUNNING THIS DRIVER
 *     AND THE BUS OCCASIONALLY HANGS, NECESSITATING THE DEVIE RESET
 *     CODE WHICH RE-INITS THE UNIBUS.  YECHHH.
E 16
E 14
 */
I 94
#include "../machine/pte.h"
E 94
I 29
D 60
#define	DELAY(N)		{ register int d; d = N; while (--d > 0); }
E 60
E 29

D 112
#include "../h/param.h"
#include "../h/systm.h"
I 42
D 89
#include "../h/cpu.h"
#include "../h/nexus.h"
E 89
E 42
I 14
#include "../h/dk.h"
I 92
#include "../h/dkbad.h"
E 92
E 14
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/map.h"
I 20
D 94
#include "../h/pte.h"
E 94
E 20
D 54
#include "../h/mba.h"
E 54
D 89
#include "../h/mtpr.h"
E 89
D 20
#include "../h/pte.h"
E 20
D 46
#include "../h/uba.h"
E 46
#include "../h/vm.h"
I 46
D 59
#include "../h/uba.h"
E 59
I 59
D 89
#include "../h/ubavar.h"
#include "../h/ubareg.h"
E 89
E 59
E 46
I 41
#include "../h/cmap.h"
I 86
#include "../h/uio.h"
I 97
#include "../h/kernel.h"
E 112
I 112
#include "param.h"
#include "systm.h"
D 123
#include "dk.h"
E 123
I 123
#include "dkstat.h"
E 123
#include "dkbad.h"
I 125
#include "ioctl.h"
#include "disklabel.h"
E 125
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "map.h"
#include "vm.h"
#include "cmap.h"
#include "uio.h"
#include "kernel.h"
I 113
#include "syslog.h"
E 113
E 112
E 97
E 86
E 41
D 90

E 90
I 90
#include "../h/dkbad.h"
E 90
D 26
/*
D 25
 * Define number of drives, and range of sampling information to be used.
 *
 * Normally, DK_N .. DK_N+NUP-1 gather individual drive stats,
 * and DK_N+NUP gathers controller transferring stats.
 *
 * If DK_N+NUP > DK_NMAX, then transfer stats are divided per drive.
 * If DK_NMAX is yet smaller, some drives are not monitored.
E 25
I 25
 * Drive stats are gathered in dk_*[DK_N].. dk_*[DK_NMAX]
E 25
 */
D 14
#define	DK_N	1
#define	DK_NMAX	2
E 14
I 14
#define	DK_N	2
#define	DK_NMAX	3
E 14

E 26
D 41
#define	ushort	unsigned short
E 41
I 41
D 89
#include "../h/upreg.h"
E 89
I 89
#include "../vax/cpu.h"
#include "../vax/nexus.h"
D 112
#include "../vaxuba/ubavar.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/upreg.h"
E 112
I 112
#include "ubavar.h"
#include "ubareg.h"
#include "upreg.h"
E 112
E 89
E 41

D 41
struct	device
{
	ushort	upcs1;		/* control and status register 1 */
	short	upwc;		/* word count register */
	ushort	upba;		/* UNIBUS address register */
	ushort	upda;		/* desired address register */
	ushort	upcs2;		/* control and status register 2 */
	ushort	upds;		/* drive Status */
	ushort	uper1;		/* error register 1 */
	ushort	upas;		/* attention summary */
	ushort	upla;		/* look ahead */
	ushort	updb;		/* data buffer */
	ushort	upmr;		/* maintenance */ 
	ushort	updt;		/* drive type */
	ushort	upsn;		/* serial number */
	ushort	upof;		/* offset register */
	ushort	updc;		/* desired cylinder address register */
	ushort	upcc;		/* current cylinder */
	ushort	uper2;		/* error register 2 */
	ushort	uper3;		/* error register 3 */
	ushort	upec1;		/* burst error bit position */
	ushort	upec2;		/* burst error bit pattern */
};

E 41
I 11
D 42
/*
 * Software extension to the upas register, so we can
 * postpone starting SEARCH commands until the controller
 * is not transferring.
 */
D 16
int	softas;
E 16
I 16
int	upsoftas;
E 42
I 42
struct	up_softc {
	int	sc_softas;
D 47
	int	sc_seek;
E 47
I 47
	int	sc_ndrive;
E 47
D 46
	int	sc_info;
E 46
	int	sc_wticks;
I 51
	int	sc_recal;
E 51
I 43
D 47
	/* struct uba_minfo sc_minfo; */
E 47
E 43
D 50
} up_softc[NSC21];
E 50
I 50
} up_softc[NSC];
E 50
E 42
E 16

I 117
#define upunit(dev)	(minor(dev) >> 3)

E 117
D 42
/*
 * If upseek then we don't issue SEARCH commands but rather just
 * settle for a SEEK to the correct cylinder.
 */
int	upseek;
D 26

E 11
#define	UPADDR	((struct device *)(UBA0_DEV + 0176700))

#define	NUP	2		/* Number of drives this installation */
E 26

#define	NSECT	32
#define	NTRAC	19

/*
 * Constants controlling on-cylinder SEARCH usage.
 *
D 11
 * We assume that it takes SDIST sectors of time to set up a transfer.
 * If a drive is on-cylinder, and between SDIST and SDIST+RDIST sectors
 * from the first sector to be transferred, then we just perform the
 * transfer.  SDIST represents interrupt latency, RDIST the amount
 * of rotation which is tolerable to avoid another interrupt.
E 11
I 11
D 14
 * 	SDIST/2 msec		time needed to start transfer
 * 	IDIST/2 msec		slop for interrupt latency
 * 	RDIST/2 msec		tolerable rotational latency when on-cylinder
E 14
I 14
 * 	upSDIST/2 msec		time needed to start transfer
 * 	upRDIST/2 msec		tolerable rotational latency when on-cylinder
E 14
 *
D 14
 * If we are no closer than SDIST sectors and no further than SDIST+RDIST
E 14
I 14
 * If we are no closer than upSDIST sectors and no further than upSDIST+upRDIST
E 14
 * and in the driver then we take it as it is.  Otherwise we do a SEARCH
D 14
 * requesting an interrupt SDIST+IDIST sectors in advance.
E 14
I 14
 * requesting an interrupt upSDIST sectors in advance.
E 14
E 11
 */
D 2
#define	SDIST	4		/* 4 sectors ~~= 2 msec */
#define	RDIST	6		/* 6 sectors ~~= 3 msec */
E 2
I 2
D 11
#define	SDIST	3		/* 2-3 sectors 1-1.5 msec */
#define	RDIST	6		/* 5-6 sectors 2.5-3 msec */
E 11
I 11
D 14
#define	_SDIST	6		/* 3.0 msec */
#define	_RDIST	6		/* 2.5 msec */
#define	_IDIST	1		/* 0.5 msec */
E 14
I 14
D 27
#define	_upSDIST	6		/* 3.0 msec */
E 27
I 27
D 28
#define	_upSDIST	3		/* 1.5 msec */
E 27
#define	_upRDIST	6		/* 3.0 msec */
E 28
I 28
#define	_upSDIST	2		/* 1.0 msec */
#define	_upRDIST	4		/* 2.0 msec */
E 28
E 14
E 11
E 2

I 11
D 14
int	SDIST = _SDIST;
int	RDIST = _RDIST;
int	IDIST = _IDIST;
E 14
I 14
int	upSDIST = _upSDIST;
int	upRDIST = _upRDIST;
E 14

E 11
/*
 * To fill a 300M drive:
 *	A is designed to be used as a root.
 *	B is suitable for a swap area.
 *	H is the primary storage area.
 * On systems with RP06'es, we normally use only 291346 blocks of the H
 * area, and use DEF or G to cover the rest of the drive.  The C system
 * covers the whole drive and can be used for pack-pack copying.
I 29
 *
 * Note: sizes here are for AMPEX drives with 815 cylinders.
 * CDC drives can make the F,G, and H areas larger as they have 823 cylinders.
E 29
 */
E 42
I 42
/* THIS SHOULD BE READ OFF THE PACK, PER DRIVE */
E 42
D 96
struct	size
{
E 96
I 96
struct	size {
E 96
	daddr_t	nblocks;
	int	cyloff;
D 103
} up_sizes[8] = {
E 103
I 103
} up9300_sizes[8] = {
E 103
I 90
#ifdef ERNIE
	49324,	0,		/* A=cyl 0 thru 26 */
#else
E 90
I 75
D 96
#ifdef ERNIE
	49324,	0,		/* A=cyl 0 thru 26 */
#else
E 96
E 75
	15884,	0,		/* A=cyl 0 thru 26 */
I 90
#endif
E 90
I 75
D 96
#endif
E 96
E 75
	33440,	27,		/* B=cyl 27 thru 81 */
D 16
	494912,	0,		/* C=cyl 0 thru 814 */
E 16
I 16
	495520,	0,		/* C=cyl 0 thru 814 */
E 16
	15884,	562,		/* D=cyl 562 thru 588 */
	55936,	589,		/* E=cyl 589 thru 680 */
D 68
	81472,	681,		/* F=cyl 681 thru 814 */
	153824,	562,		/* G=cyl 562 thru 814 */
E 68
I 68
D 96
#ifndef NOBADSECT
E 96
	81376,	681,		/* F=cyl 681 thru 814 */
	153728,	562,		/* G=cyl 562 thru 814 */
D 96
#else
	81472,	681,
	153824,	562,
#endif
E 96
E 68
D 29
	445664,	82,		/* H=cyl 82 thru 814 */
/* Later, and more safely for H area...
E 29
	291346,	82,		/* H=cyl 82 thru 561 */
I 42
D 103
}, fj_sizes[8] = {
E 103
I 103
}, up9766_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 26 */
	33440,	27,		/* B=cyl 27 thru 81 */
	500384,	0,		/* C=cyl 0 thru 822 */
	15884,	562,		/* D=cyl 562 thru 588 */
	55936,	589,		/* E=cyl 589 thru 680 */
	86240,	681,		/* F=cyl 681 thru 822 */
	158592,	562,		/* G=cyl 562 thru 822 */
	291346,	82,		/* H=cyl 82 thru 561 */
}, up160_sizes[8] = {
E 103
	15884,	0,		/* A=cyl 0 thru 49 */
	33440,	50,		/* B=cyl 50 thru 154 */
	263360,	0,		/* C=cyl 0 thru 822 */
I 103
	15884,	155,		/* D=cyl 155 thru 204 */
	55936,	205,		/* E=cyl 205 thru 379 */
	141664,	380,		/* F=cyl 380 thru 822 */
	213664,	155,		/* G=cyl 155 thru 822 */
E 103
	0,	0,
D 103
	0,	0,
	0,	0,
	0,	0,
D 68
	213760,	155,		/* H=cyl 155 thru 822 */
E 68
I 68
D 96
#ifndef NOBADSECT
E 96
	213664,	155,		/* H=cyl 155 thru 822 */
E 103
D 96
#else
	213760,	155,
#endif
E 96
I 71
D 80
D 90
}, am_sizes[8] = {
E 90
I 90
}, upam_sizes[8] = {
E 90
E 80
I 80
}, upam_sizes[8] = {
E 80
	15884,	0,		/* A=cyl 0 thru 31 */
	33440,	32,		/* B=cyl 32 thru 97 */
	524288,	0,		/* C=cyl 0 thru 1023 */
D 76
D 90
	0,	0,
	0,	0,
	0,	0,
E 90
I 90
	27786,	668,
	27786,	723,
	125440,	778,
E 90
E 76
I 76
D 103
	27786,	668,
	27786,	723,
	125440,	778,
E 76
	181760,	668,		/* G=cyl 668 thru 1022 */
E 103
I 103
	15884,	668,		/* D=cyl 668 thru 699 */
	55936,	700,		/* E=cyl 700 thru 809 */
	109472,	810,		/* F=cyl 810 thru 1023 */
	182176,	668,		/* G=cyl 668 thru 1023 */
E 103
	291346,	98,		/* H=cyl 98 thru 667 */
I 110
}, up980_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 99 */
	33440,	100,		/* B=cyl 100 thru 308 */
	131680,	0,		/* C=cyl 0 thru 822 */
	15884,	309,		/* D=cyl 309 thru 408 */
	55936,	409,		/* E=cyl 409 thru 758 */
	10080,	759,		/* F=cyl 759 thru 822 */
	82080,	309,		/* G=cyl 309 thru 822 */
	0,	0,
I 114
}, upeagle_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 16 */
	66880,	17,		/* B=cyl 17 thru 86 */
	808320,	0,		/* C=cyl 0 thru 841 */
	15884,	391,		/* D=cyl 391 thru 407 */
	307200,	408,		/* E=cyl 408 thru 727 */
	109296,	728,		/* F=cyl 728 thru 841 */
	432816,	391,		/* G=cyl 391 thru 841 */
	291346,	87,		/* H=cyl 87 thru 390 */
E 114
E 110
E 71
E 68
E 42
};
I 42
/* END OF STUFF WHICH SHOULD BE READ IN PER DISK */
E 42

D 42
/*
 * The following defines are used in offset positioning
 * when trying to recover disk errors, with the constants being
 * +/- microinches.  Note that header compare inhibit (HCI) is not
 * tried (this makes sense only during read, in any case.)
 *
D 16
 * ARE ALL THESE IMPLEMENTED ON 9300?
E 16
I 16
D 29
 * NOT ALL OF THESE ARE IMPLEMENTED ON 9300!?!
E 29
I 29
 * NB: Not all drives/controllers emulate all of these.
E 29
E 16
 */
#define	P400	020
#define	M400	0220
#define	P800	040
#define	M800	0240
#define	P1200	060
#define	M1200	0260
#define	HCI	020000
E 42
I 42
D 73
#define	_upSDIST	2		/* 1.0 msec */
E 73
I 73
D 107
/*
 * On a 780 upSDIST could be 2, but
 * in the interest of 750's...
 */
#define	_upSDIST	3		/* 1.5 msec */
E 73
#define	_upRDIST	4		/* 2.0 msec */
E 42

I 42
int	upSDIST = _upSDIST;
int	upRDIST = _upRDIST;

E 107
D 47
int	upcntrlr(), upslave(), updgo(), upintr();
E 47
I 47
int	upprobe(), upslave(), upattach(), updgo(), upintr();
E 47
D 50
struct	uba_minfo *upminfo[NSC21];
E 50
I 50
D 59
struct	uba_minfo *upminfo[NSC];
E 50
struct	uba_dinfo *updinfo[NUP];
I 47
D 50
struct	uba_dinfo *upip[NSC21][4];
E 50
I 50
struct	uba_dinfo *upip[NSC][4];
E 59
I 59
struct	uba_ctlr *upminfo[NSC];
struct	uba_device *updinfo[NUP];
D 74
struct	uba_device *upip[NSC][4];
E 74
I 74
#define	UPIPUNITS	8
struct	uba_device *upip[NSC][UPIPUNITS]; /* fuji w/fixed head gives n,n+4 */
E 74
E 59
E 50
E 47
D 44
struct	uba_minfo up_minfo[NSC21];
	/* there is no reason for this to be a global structure, it
	   is only known/used locally, it would be better combined
	   with up_softc - but that would mean I would have to alter
	   more than I want to just now. Similarly, there is no longer
	   any real need for upminfo, but the code still uses it so ...
	*/
E 44

D 43
u_short	upstd[] = { 0 };
int	(*upivec[])() = { upintr, 0 };
E 43
I 43
D 44
extern	u_short	upstd[];
E 44
I 44
D 47
u_short	upstd[] = { 0776700, 0774400, 0776300 };
E 47
I 47
u_short	upstd[] = { 0776700, 0774400, 0776300, 0 };
E 47
E 44
E 43
D 48
struct	uba_driver updriver =
E 48
I 48
struct	uba_driver scdriver =
E 48
D 43
	{ upcntrlr, upslave, updgo, 4, 0, upstd, updinfo, upivec };
E 43
I 43
D 44
	{ upcntrlr, upslave, updgo, 4, 0, upstd, "up", updinfo };
E 44
I 44
D 46
	{ upcntrlr, upslave, updgo, 0, upstd, "up", updinfo, upminfo };
E 46
I 46
D 47
	{ upcntrlr, upslave, updgo, 0, upstd, "up", updinfo, "sc", upminfo };
E 47
I 47
    { upprobe, upslave, upattach, updgo, upstd, "up", updinfo, "sc", upminfo };
E 47
E 46
E 44
E 43
struct	buf	uputab[NUP];
I 92
char upinit[NUP];
E 92
I 90
char upinit[NUP];
E 90

struct	upst {
D 107
	short	nsect;
	short	ntrak;
	short	nspc;
	short	ncyl;
	struct	size *sizes;
E 107
I 107
	short	nsect;		/* # sectors/track */
	short	ntrak;		/* # tracks/cylinder */
	short	nspc;		/* # sectors/cylinder */
	short	ncyl;		/* # cylinders */
	struct	size *sizes;	/* partition tables */
	short	sdist;		/* seek distance metric */
	short	rdist;		/* rotational distance metric */
E 107
} upst[] = {
D 47
	32,	19,	32*19,	815,	up_sizes,	/* 9300 */
	32,	19,	32*19,	823,	up_sizes,	/* so cdc will boot */
E 47
I 47
D 100
	32,	19,	32*19,	823,	up_sizes,	/* 9300/cdc */
/* 9300 actually has 815 cylinders... */
E 100
I 100
D 103
	32,	19,	32*19,	815,	up_sizes,	/* 9300 */
I 102
	32,	19,	32*19,	823,	up_sizes,	/* 9766 */
E 102
E 100
E 47
	32,	10,	32*10,	823,	fj_sizes,	/* fujitsu 160m */
E 103
I 103
D 107
	32,	19,	32*19,	815,	up9300_sizes,	/* 9300 */
	32,	19,	32*19,	823,	up9766_sizes,	/* 9766 */
	32,	10,	32*10,	823,	up160_sizes,	/* fujitsu 160m */
E 103
I 71
D 73
	32,	16,	32*16,	1024,	am_sizes,	/* fujitsu 160m */
E 73
I 73
D 80
D 90
	32,	16,	32*16,	1024,	am_sizes,	/* ampex capricorn */
E 90
I 90
	32,	16,	32*16,	1024,	upam_sizes,	/* ampex capricorn */
E 90
E 80
I 80
	32,	16,	32*16,	1024,	upam_sizes,	/* ampex capricorn */
I 100
D 102
/* should make a new partition table for cdc drives */
	32,	19,	32*19,	823,	up_sizes,	/* cdc */
E 102
I 102
	0,	0,	0,	0,	0
E 107
I 107
	{ 32,	19,	32*19,	815,	up9300_sizes,	3, 4 },	/* 9300 */
	{ 32,	19,	32*19,	823,	up9766_sizes,	3, 4 },	/* 9766 */
	{ 32,	10,	32*10,	823,	up160_sizes,	3, 4 },	/* fuji 160m */
	{ 32,	16,	32*16,	1024,	upam_sizes,	7, 8 },	/* Capricorn */
I 110
	{ 32,	5,	32*5,	823,	up980_sizes,	3, 4 }, /* DM980 */
I 114
        { 48,	20,	48*20,	842,	upeagle_sizes, 15, 8 },	/* EAGLE */
E 114
E 110
	{ 0,	0,	0,	0,	0,		0, 0 }
E 107
E 102
E 100
E 80
E 73
E 71
};

E 42
D 48
int	up_offset[16] =
{
	P400, M400, P400, M400,
	P800, M800, P800, M800,
	P1200, M1200, P1200, M1200,
	0, 0, 0, 0,
};
E 48
I 48
D 49
u_char	up_offset[16] =
  { P400,M400,P400,M400,P800,M800,P800,M800,P1200,M1200,P1200,M1200,0,0,0,0 };
E 49
I 49
u_char	up_offset[16] = {
D 65
    UP_P400, UP_M400, UP_P400, UP_M400, UP_P800, UP_M800, UP_P800, UP_M800, 
    UP_P1200, UP_M1200, UP_P1200, UP_M1200, 0, 0, 0, 0
E 65
I 65
D 90
D 92
    UPOF_P400, UPOF_M400, UPOF_P400, UPOF_M400,
    UPOF_P800, UPOF_M800, UPOF_P800, UPOF_M800, 
    UPOF_P1200, UPOF_M1200, UPOF_P1200, UPOF_M1200,
    0, 0, 0, 0
E 92
I 92
	UPOF_P400, UPOF_M400, UPOF_P400, UPOF_M400,
	UPOF_P800, UPOF_M800, UPOF_P800, UPOF_M800, 
	UPOF_P1200, UPOF_M1200, UPOF_P1200, UPOF_M1200,
	0, 0, 0, 0
E 92
E 90
I 90
	UPOF_P400, UPOF_M400, UPOF_P400, UPOF_M400,
	UPOF_P800, UPOF_M800, UPOF_P800, UPOF_M800, 
	UPOF_P1200, UPOF_M1200, UPOF_P1200, UPOF_M1200,
	0, 0, 0, 0
E 90
E 65
};
E 49
E 48

D 42
/*
 * Each drive has a table uputab[i].  On this table are sorted the
 * pending requests implementing an elevator algorithm (see dsort.c.)
 * In the upustart() routine, each drive is independently advanced
 * until it is on the desired cylinder for the next transfer and near
 * the desired sector.  The drive is then chained onto the uptab
 * table, and the transfer is initiated by the upstart() routine.
 * When the transfer is completed the driver reinvokes the upustart()
 * routine to set up the next transfer.
 */
struct	buf	uptab;
struct	buf	uputab[NUP];
E 42
I 42
D 48
struct	buf	rupbuf;			/* GROT */
E 48
I 48
D 124
struct	buf	rupbuf[NUP];
E 124
I 92
D 96
#ifndef NOBADSECT
E 96
struct 	buf	bupbuf[NUP];
struct	dkbad	upbad[NUP];
D 96
#endif
E 96
E 92
I 90
#ifndef NOBADSECT
struct 	buf	bupbuf[NUP];
struct	dkbad	upbad[NUP];
#endif
E 90
E 48
E 42

D 42
struct	buf	rupbuf;			/* Buffer for raw i/o */

E 42
D 41
/* Drive commands, placed in upcs1 */
#define	GO	01		/* Go bit, set in all commands */
#define	PRESET	020		/* Preset drive at init or after errors */
#define	OFFSET	014		/* Offset heads to try to recover error */
#define	RTC	016		/* Return to center-line after OFFSET */
#define	SEARCH	030		/* Search for cylinder+sector */
I 11
#define	SEEK	04		/* Seek to cylinder */
E 11
#define	RECAL	06		/* Recalibrate, needed after seek error */
#define	DCLR	010		/* Drive clear, after error */
#define	WCOM	060		/* Write */
#define	RCOM	070		/* Read */

/* Other bits of upcs1 */
#define	IE	0100		/* Controller wide interrupt enable */
#define	TRE	040000		/* Transfer error */
I 2
D 17
#define	RDY	020		/* Transfer terminated */
E 17
I 17
#define	RDY	0200		/* Transfer terminated */
E 17
E 2

/* Drive status bits of upds */
#define	PIP	020000		/* Positioning in progress */
#define	ERR	040000		/* Error has occurred, DCLR necessary */
#define	VV	0100		/* Volume is valid, set by PRESET */
#define	DPR	0400		/* Drive has been preset */
#define	MOL	010000		/* Drive is online, heads loaded, etc */
#define	DRY	0200		/* Drive ready */

I 15
/* Bits of upcs2 */
#define	CLR	040		/* Controller clear */
I 33
#define	MXF	01000
#define	NEM	04000

E 33
E 15
/* Bits of uper1 */
#define	DCK	0100000		/* Ecc error occurred */
#define	ECH	0100		/* Ecc error was unrecoverable */
#define	WLE	04000		/* Attempt to write read-only drive */

/* Bits of upof; the offset bits above are also in this register */
#define	FMT22	010000		/* 16 bits/word, must be always set */

E 41
#define	b_cylin b_resid

D 42
int	up_ubinfo;		/* Information about UBA usage saved here */
D 29
/*
 * The EMULEX controller balks if accessed quickly after
D 16
 * certain operations.  The exact timing has not yet been
 * determined, but delays are known to be needed when changing
 * the selected drive (by writing in upcs2), and thought to be
 * needed after operations like PRESET and DCLR.  The following
 * variables control the delay, DELAY(n) is approximately n usec.
E 16
I 16
 * certain operations.  With rev J delays seem to be needed only
 * when selecting a new unit, and in drive initialization type
 * like PRESET and DCLR.  The following variables control the delay
 * DELAY(n) is approximately n usec.
E 16
 */
I 18
int	olducode = 1;
E 18
int	idelay = 500;		/* Delay after PRESET or DCLR */
I 16
D 18
#ifdef OLDUCODE
E 16
D 3
int	sdelay = 500;		/* Delay after selecting drive in upcs2 */
E 3
I 3
D 4
int	sdelay = 125;		/* Delay after selecting drive in upcs2 */
E 3
I 2
int	iedel1 = 500;
int	iedel2 = 500;
int	iedel3 = 0;
int	iedel4 = 500;
E 4
I 4
int	sdelay = 150;		/* Delay after selecting drive in upcs2 */
I 11
int	rdelay = 100;		/* Delay after SEARCH */
int	asdel = 100;		/* Delay after clearing bit in upas */
I 16
#else
int	sdelay = 25;
#endif
E 18
I 18
int	osdelay = 150;		/* Old delay after selecting drive in upcs2 */
int	ordelay = 100;		/* Old delay after SEARCH */
int	oasdel = 100;		/* Old delay after clearing bit in upas */
int	nsdelay = 25;
E 29
E 18
E 16
E 11
E 4
E 2

I 11
D 16
int	csdel2 = 0;		/* ??? Delay in upstart ??? */

E 16
E 11
D 29
#define	DELAY(N)		{ register int d; d = N; while (--d > 0); }
 
int	nwaitcs2;		/* How many sdelay loops ? */
int	neasycs2;		/* How many sdelay loops not needed ? */

E 29
I 15
int	up_wticks;		/* Ticks waiting for interrupt */
int	upwstart;		/* Have started guardian */
int	upwatch();

E 42
E 15
D 117
#ifdef INTRLVE
daddr_t dkblock();
#endif
D 42
 
/*
 * Queue an i/o request for a drive, checking first that it is in range.
 *
 * A unit start is issued if the drive is inactive, causing
 * a SEARCH for the correct cylinder/sector.  If the drive is
 * already nearly on the money and the controller is not transferring
 * we kick it to start the transfer.
 */
upstrategy(bp)
register struct buf *bp;
E 42
I 42

E 117
int	upwstart, upwatch();		/* Have started guardian */
I 45
int	upseek;
I 51
D 52
int	updrydel;
E 52
I 52
int	upwaitdry;
E 52
E 51
E 45

/*ARGSUSED*/
D 47
upcntrlr(um, reg)
	struct uba_minfo *um;
E 47
I 47
upprobe(reg)
E 47
	caddr_t reg;
E 42
{
I 44
	register int br, cvec;

E 44
D 42
	register struct buf *dp;
	register unit, xunit;
	long sz, bn;
E 42
I 42
D 47
	((struct device *)reg)->upcs1 |= (IE|RDY);
E 47
I 47
#ifdef lint	
D 106
	br = 0; cvec = br; br = cvec;
E 106
I 106
	br = 0; cvec = br; br = cvec; upintr(0);
E 106
I 69
D 71
	upintr(0);
E 71
E 69
#endif
D 49
	((struct device *)reg)->upcs1 = (IE|RDY);
E 49
I 49
	((struct updevice *)reg)->upcs1 = UP_IE|UP_RDY;
E 49
	DELAY(10);
D 49
	((struct device *)reg)->upcs1 = 0;
E 49
I 49
	((struct updevice *)reg)->upcs1 = 0;
E 49
E 47
D 44
	return(1);			/* just assume it is us (for now) */
E 44
I 44
D 85
	return (1);
E 85
I 85
	return (sizeof (struct updevice));
E 85
E 44
}
E 42

I 42
D 44
upslave(ui, reg, slaveno, uban)
E 44
I 44
D 47
upslave(ui, reg, slaveno)
E 47
I 47
upslave(ui, reg)
E 47
E 44
D 59
	struct uba_dinfo *ui;
E 59
I 59
	struct uba_device *ui;
E 59
	caddr_t reg;
{
D 49
	register struct device *upaddr = (struct device *)reg;
E 49
I 49
	register struct updevice *upaddr = (struct updevice *)reg;
E 49
D 44
	register struct uba_minfo *um;
	register int sc21;
E 44

	upaddr->upcs1 = 0;		/* conservative */
D 47
	upaddr->upcs2 = slaveno;
E 47
I 47
	upaddr->upcs2 = ui->ui_slave;
I 90
	upaddr->upcs1 = UP_NOP|UP_GO;
E 90
I 78
	upaddr->upcs1 = UP_NOP|UP_GO;
E 78
E 47
D 49
	if (upaddr->upcs2&NED) {
		upaddr->upcs1 = DCLR|GO;
E 49
I 49
D 65
	if (upaddr->upcs2&UP_NED) {
E 65
I 65
	if (upaddr->upcs2&UPCS2_NED) {
E 65
		upaddr->upcs1 = UP_DCLR|UP_GO;
E 49
		return (0);
	}
I 47
	return (1);
}

upattach(ui)
D 59
	register struct uba_dinfo *ui;
E 59
I 59
	register struct uba_device *ui;
E 59
{
I 49
D 66
#ifdef notdef
E 66
D 104
	register struct updevice *upaddr;
E 104
D 66
#endif
E 66
E 49

E 47
D 44
	/*** we should check device type (return 0 if we don't like it) ***/
	/*** and set type index in ui->ui_type, but we KNOW all we are  ***/
	/*** going to see at the minute is a 9300, and the index for a  ***/
	/*** 9300 is 0, which is the value already in ui->ui_type, so ..***/

	um = &up_minfo[0];
	for (sc21 = 0; sc21 < NSC21; sc21++) {
		if (um->um_alive == 0) {	/* this is a new ctrlr */
			um->um_addr = reg;
			um->um_ubanum = uban;
			um->um_num = sc21;	/* not needed after up_softc
						   combined with um ???  */
			um->um_alive = 1;
			upminfo[sc21] = um;	/* just till upminfo vanishes */
			goto found;
		}
		if (um->um_addr == reg && um->um_ubanum == uban)
			goto found;
		um++;
	}
	return(0);				/* too many sc21's */

    found:
	ui->ui_mi = um;

E 44
E 42
I 15
	if (upwstart == 0) {
D 31
		timeout((caddr_t)upwatch, 0, HZ);
E 31
I 31
D 55
		timeout(upwatch, (caddr_t)0, HZ);
E 55
I 55
		timeout(upwatch, (caddr_t)0, hz);
E 55
E 31
		upwstart++;
	}
I 46
	if (ui->ui_dk >= 0)
		dk_mspw[ui->ui_dk] = .0000020345;
E 46
E 15
D 42
	xunit = minor(bp->b_dev) & 077;
E 42
I 42
D 47
	return (1);
E 47
I 47
	upip[ui->ui_ctlr][ui->ui_slave] = ui;
	up_softc[ui->ui_ctlr].sc_ndrive++;
I 49
D 66
#ifdef notdef
E 66
D 104
	upaddr = (struct updevice *)ui->ui_addr;
E 104
I 102
	ui->ui_type = upmaptype(ui);
}

upmaptype(ui)
	register struct uba_device *ui;
{
	register struct updevice *upaddr = (struct updevice *)ui->ui_addr;
	int type = ui->ui_type;
	register struct upst *st;

E 102
	upaddr->upcs1 = 0;
	upaddr->upcs2 = ui->ui_slave;
D 66
	upaddr->uphr = -1;
	/* ... */
	if (upaddr-> ... == 10)
		ui->ui_type = 1;
#endif
E 66
I 66
	upaddr->uphr = UPHR_MAXTRAK;
D 67
	if (upaddr->uphr == 10)
E 67
I 67
D 102
	if (upaddr->uphr == 9)
E 67
		ui->ui_type = 1;		/* fujitsu hack */
I 71
	else if (upaddr->uphr == 15)
		ui->ui_type = 2;		/* ampex hack */
I 100
	else {
E 102
I 102
	for (st = upst; st->nsect != 0; st++)
		if (upaddr->uphr == st->ntrak - 1) {
			type = st - upst;
			break;
		}
	if (st->nsect == 0)
D 124
		printf("up%d: uphr=%x\n", ui->ui_slave, upaddr->uphr);
E 124
I 124
D 126
		printf(": uphr=%x", ui->ui_slave, upaddr->uphr);
E 126
I 126
		printf(": uphr=%x", upaddr->uphr);
E 126
E 124
	if (type == 0) {
E 102
		upaddr->uphr = UPHR_MAXCYL;
		if (upaddr->uphr == 822)
D 102
			ui->ui_type = 3;	/* cdc hack */
E 102
I 102
			type++;
E 102
	}
E 100
E 71
	upaddr->upcs2 = UPCS2_CLR;
I 102
	return (type);
E 102
D 90
D 92
/*
	upaddr->uphr = UPHR_MAXCYL;
	printf("maxcyl %d\n", upaddr->uphr);
	upaddr->uphr = UPHR_MAXTRAK;
	printf("maxtrak %d\n", upaddr->uphr);
	upaddr->uphr = UPHR_MAXSECT;
	printf("maxsect %d\n", upaddr->uphr);
*/
E 92
E 90
E 66
E 49
E 47
}
 
I 92
upopen(dev)
	dev_t dev;
{
D 117
	register int unit = minor(dev) >> 3;
E 117
I 117
	register int unit = upunit(dev);
E 117
	register struct uba_device *ui;

	if (unit >= NUP || (ui = updinfo[unit]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
	return (0);
}

E 92
D 46
/*
	dk_mspw[UPDK_N+unit] = .0000020345;
*/

E 46
upstrategy(bp)
	register struct buf *bp;
{
D 59
	register struct uba_dinfo *ui;
E 59
I 59
	register struct uba_device *ui;
E 59
D 45
	register struct uba_minfo *um;
E 45
	register struct upst *st;
	register int unit;
I 45
	register struct buf *dp;
E 45
	int xunit = minor(bp->b_dev) & 07;
D 45
	long sz, bn;
E 45
I 45
	long bn, sz;
I 114
	int s;
E 114
I 70
D 71
	int s;
E 71
E 70
E 45

E 42
D 45
	sz = bp->b_bcount;
	sz = (sz+511) >> 9;		/* transfer size in 512 byte sectors */
E 45
I 45
	sz = (bp->b_bcount+511) >> 9;
E 45
D 117
	unit = dkunit(bp);
D 42
	if (unit >= NUP ||
	    bp->b_blkno < 0 ||
	    (bn = dkblock(bp))+sz > up_sizes[xunit&07].nblocks) {
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
	}
I 25
D 37
	if (DK_N+unit <= DK_NMAX)
		dk_mspw[DK_N+unit] = .0000020345;
E 37
I 37
	if (UPDK_N+unit <= UPDK_NMAX)
		dk_mspw[UPDK_N+unit] = .0000020345;
E 37
E 25
	bp->b_cylin = bn/(NSECT*NTRAC) + up_sizes[xunit&07].cyloff;
	dp = &uputab[unit];
E 42
I 42
	if (unit >= NUP)
E 117
I 117
	unit = upunit(bp->b_dev);
	if (unit >= NUP) {
		bp->b_error = ENXIO;
E 117
		goto bad;
I 117
	}
E 117
	ui = updinfo[unit];
D 117
	if (ui == 0 || ui->ui_alive == 0)
E 117
I 117
	if (ui == 0 || ui->ui_alive == 0) {
		bp->b_error = ENXIO;
E 117
		goto bad;
I 117
	}
E 117
	st = &upst[ui->ui_type];
	if (bp->b_blkno < 0 ||
D 117
	    (bn = dkblock(bp))+sz > st->sizes[xunit].nblocks)
E 117
I 117
	    (bn = bp->b_blkno)+sz > st->sizes[xunit].nblocks) {
D 118
		if (bp->b_blkno == st->sizes[xunit].nblocks + 1)
E 118
I 118
		if (bp->b_blkno == st->sizes[xunit].nblocks) {
			bp->b_resid = bp->b_bcount;
E 118
			goto done;
I 118
		}
E 118
		bp->b_error = EINVAL;
E 117
		goto bad;
I 117
	}
E 117
	bp->b_cylin = bn/st->nspc + st->sizes[xunit].cyloff;
E 42
D 70
	(void) spl5();
E 70
I 70
D 71
	s = spl5();
E 71
I 71
D 114
	(void) spl5();
E 114
I 114
	s = spl5();
E 114
E 71
E 70
D 42
	disksort(dp, bp);
I 8
D 9
#ifdef UTRACE
D(1)	ttime();
D(2)	trace("upstrat bn %d unit %d\n", bp->b_blkno, unit);
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
	ttime();
	trace("upstrat bn %d unit %d\n", bp->b_blkno, unit);
E 6
I 6
D(1)	ttime();
D(2)	trace("upstrat bn %d unit %d\n", bp->b_blkno, unit);
E 6
#endif
E 7
E 5
	if (dp->b_active == 0) {
D 4
		upustart(unit);
E 4
I 4
		(void) upustart(unit);
E 4
		if (uptab.b_actf && uptab.b_active == 0)
D 4
			upstart();
E 4
I 4
			(void) upstart();
E 42
I 42
D 45
	disksort(&uputab[ui->ui_unit], bp);
	if (uputab[ui->ui_unit].b_active == 0) {
E 45
I 45
	dp = &uputab[ui->ui_unit];
	disksort(dp, bp);
	if (dp->b_active == 0) {
E 45
		(void) upustart(ui);
		bp = &ui->ui_mi->um_tab;
		if (bp->b_actf && bp->b_active == 0)
			(void) upstart(ui->ui_mi);
E 42
E 4
	}
D 70
	(void) spl0();
E 70
I 70
D 71
	splx(s);
E 71
I 71
D 114
	(void) spl0();
E 114
I 114
	splx(s);
E 114
E 71
E 70
I 42
	return;

bad:
	bp->b_flags |= B_ERROR;
I 117
done:
E 117
	iodone(bp);
	return;
E 42
}

I 51
/*
 * Unit start routine.
 * Seek the drive to be where the data is
 * and then generate another interrupt
 * to actually start the transfer.
 * If there is only one drive on the controller,
 * or we are very close to the data, don't
 * bother with the search.  If called after
 * searching once, don't bother to look where
 * we are, just queue for transfer (to avoid
 * positioning forever without transferrring.)
 */
E 51
D 42
/*
 * Start activity on specified drive; called when drive is inactive
 * and new transfer request arrives and also when upas indicates that
 * a SEARCH command is complete.
 */
upustart(unit)
register unit;
E 42
I 42
upustart(ui)
D 59
	register struct uba_dinfo *ui;
E 59
I 59
	register struct uba_device *ui;
E 59
E 42
{
	register struct buf *bp, *dp;
D 42
	register struct device *upaddr = UPADDR;
E 42
I 42
D 51
	register struct uba_minfo *um;
E 51
I 51
D 59
	register struct uba_minfo *um = ui->ui_mi;
E 59
I 59
	register struct uba_ctlr *um;
E 59
E 51
D 49
	register struct device *upaddr;
E 49
I 49
	register struct updevice *upaddr;
E 49
	register struct upst *st;
E 42
	daddr_t bn;
D 51
	int sn, cn, csn;
I 4
	int didie = 0;
E 4

D 5
	if (printsw&1) printf("upustart\n");
E 5
D 2
	if (slow1) DELAY(idelay);
	upaddr->upas = 1<<unit;
	if (slow4) DELAY(idelay);
	upaddr->upcs1 = IE;
	if (slow4) DELAY(idelay);
	if (unit >= NUP) {
		printf("stray upustart\n");		/* can't happen */
E 2
I 2
D 11
	if (unit >= NUP)
E 2
D 4
		return;
E 4
I 4
		goto out;
I 8
	if (uptab.b_active) {
		softas |= 1<<unit;
		return;
	}
E 11
D 9
#ifdef UTRACE
D(3)	ttime();
D(4)	trace("upustart %d active %d", unit, uputab[unit].b_active);
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
	ttime();
	trace("upustart %d active %d", unit, uputab[unit].b_active);
E 6
I 6
D(3)	ttime();
D(4)	trace("upustart %d active %d", unit, uputab[unit].b_active);
E 6
#endif
E 7
E 5
E 4
D 2
	}

E 2
I 2
D 42
	/*
D 11
	 * Whether or not it was before, this unit is no longer busy.
	 * Check to see if there is (still or now) a request in this
	 * drives queue, and if there is, select this unit.
E 11
I 11
	 * Other drivers tend to say something like
	 *	upaddr->upcs1 = IE;
	 *	upaddr->upas = 1<<unit;
D 29
	 * here, but the SC-11B will cancel a command which
E 29
I 29
	 * here, but some controllers will cancel a command
E 29
	 * happens to be sitting in the cs1 if you clear the go
D 29
	 * bit by storing there (so the first is not safe),
	 * and it also does not like being bothered with operations
	 * such as clearing upas when a transfer is active (as
	 * it may well be.)
E 29
I 29
	 * bit by storing there (so the first is not safe).
E 29
	 *
	 * Thus we keep careful track of when we re-enable IE
	 * after an interrupt and do it only if we didn't issue
	 * a command which re-enabled it as a matter of course.
	 * We clear bits in upas in the interrupt routine, when
	 * no transfers are active.
E 11
	 */
I 11
	if (unit >= NUP)
		goto out;
E 11
E 2
D 37
	if (unit+DK_N <= DK_NMAX)
		dk_busy &= ~(1<<(unit+DK_N));
E 37
I 37
	if (unit+UPDK_N <= UPDK_NMAX)
		dk_busy &= ~(1<<(unit+UPDK_N));
E 37
	dp = &uputab[unit];
E 42
I 42
D 47
	/* SC21 cancels commands if you say cs1 = IE, so dont */
	/* being ultra-cautious, we clear as bits only in upintr() */
E 47
I 47
	if (ui == 0)
		return (0);
E 51
I 51
	int sn, csn;
E 51
	/*
	 * The SC21 cancels commands if you just say
D 49
	 *	cs1 = IE
E 49
I 49
	 *	cs1 = UP_IE
E 49
	 * so we are cautious about handling of cs1.
	 * Also don't bother to clear as bits other than in upintr().
	 */
I 51
	int didie = 0;

	if (ui == 0)
		return (0);
I 59
	um = ui->ui_mi;
E 59
E 51
E 47
	dk_busy &= ~(1<<ui->ui_dk);
	dp = &uputab[ui->ui_unit];
E 42
D 2
	if((bp=dp->b_actf) == NULL)
E 2
I 2
	if ((bp = dp->b_actf) == NULL)
E 2
D 4
		return;
E 4
I 4
		goto out;
I 11
D 42
	/*
D 29
	 * The SC-11B doesn't start SEARCH commands when transfers are
	 * in progress.  In fact, it tends to get confused when given
E 29
I 29
	 * Most controllers don't start SEARCH commands when transfers are
	 * in progress.  In fact, some tend to get confused when given
E 29
	 * SEARCH'es during transfers, generating interrupts with neither
	 * RDY nor a bit in the upas register.  Thus we defer
	 * until an interrupt when a transfer is pending.
	 */
	if (uptab.b_active) {
D 16
		softas |= 1<<unit;
E 16
I 16
		upsoftas |= 1<<unit;
E 42
I 42
D 51
	/* dont confuse controller by giving SEARCH while dt in progress */
	um = ui->ui_mi;
E 51
I 51
	/*
	 * If the controller is active, just remember
	 * that this device would like to be positioned...
	 * if we tried to position now we would confuse the SC21.
	 */
E 51
	if (um->um_tab.b_active) {
D 44
		up_softc[um->um_num].sc_softas |= 1<<ui->ui_slave;
E 44
I 44
		up_softc[um->um_ctlr].sc_softas |= 1<<ui->ui_slave;
E 44
E 42
E 16
		return (0);
	}
I 51
	/*
	 * If we have already positioned this drive,
	 * then just put it on the ready queue.
	 */
E 51
I 12
	if (dp->b_active)
		goto done;
	dp->b_active = 1;
E 12
E 11
E 4
D 2
	if (slow1) DELAY(idelay);
E 2
D 29
	if ((upaddr->upcs2 & 07) != unit) {
E 29
I 29
D 42
	if ((upaddr->upcs2 & 07) != unit)
E 29
		upaddr->upcs2 = unit;
D 18
		DELAY(sdelay);
E 18
I 18
D 29
		DELAY(olducode ? osdelay : nsdelay);
E 18
		nwaitcs2++;
	} else
		neasycs2++;
E 29
D 2
	if (slow2) DELAY(idelay);
	if((upaddr->upds & VV) == 0) {
E 2
I 2
	/*
	 * If we have changed packs or just initialized,
D 11
	 * the the volume will not be valid; if so, clear
E 11
I 11
	 * then the volume will not be valid; if so, clear
E 11
	 * the drive, preset it and put in 16bit/word mode.
	 */
E 42
I 42
D 49
	upaddr = (struct device *)um->um_addr;
E 49
I 49
	upaddr = (struct updevice *)um->um_addr;
E 49
	upaddr->upcs2 = ui->ui_slave;
I 51
	/*
	 * If drive has just come up,
	 * setup the pack.
	 */
E 51
E 42
D 49
	if ((upaddr->upds & VV) == 0) {
E 49
I 49
D 65
	if ((upaddr->upds & UP_VV) == 0) {
E 65
I 65
D 90
D 92
	if ((upaddr->upds & UPDS_VV) == 0) {
E 92
I 92
	if ((upaddr->upds & UPDS_VV) == 0 || upinit[ui->ui_unit] == 0) {
D 96
#ifndef NOBADSECT
E 96
		struct buf *bbp = &bupbuf[ui->ui_unit];
D 96
#endif
E 96
I 96

E 96
E 92
E 90
I 90
	if ((upaddr->upds & UPDS_VV) == 0 || upinit[ui->ui_unit] == 0) {
#ifndef NOBADSECT
		struct buf *bbp = &bupbuf[ui->ui_unit];
#endif
E 90
E 65
E 49
I 47
		/* SHOULD WARN SYSTEM THAT THIS HAPPENED */
I 92
		upinit[ui->ui_unit] = 1;
E 92
I 90
		upinit[ui->ui_unit] = 1;
E 90
E 47
I 8
D 9
#ifdef UTRACE
D(5)		trace(" not VV");
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
		trace(" not VV");
E 6
I 6
D(5)		trace(" not VV");
E 6
#endif
E 7
E 5
D 49
		upaddr->upcs1 = IE|DCLR|GO;
D 29
		DELAY(idelay);
E 29
E 2
		upaddr->upcs1 = IE|PRESET|GO;
D 29
		DELAY(idelay);
E 29
		upaddr->upof = FMT22;
E 49
I 49
		upaddr->upcs1 = UP_IE|UP_DCLR|UP_GO;
		upaddr->upcs1 = UP_IE|UP_PRESET|UP_GO;
D 65
		upaddr->upof = UP_FMT22;
E 65
I 65
		upaddr->upof = UPOF_FMT22;
E 65
E 49
I 11
D 16
		printf("VV done ds %o, er? %o %o %o\n", upaddr->upds, upaddr->uper1, upaddr->uper2, upaddr->uper3);
E 16
E 11
I 4
		didie = 1;
I 92
D 96
#ifndef NOBADSECT
E 96
		st = &upst[ui->ui_type];
		bbp->b_flags = B_READ|B_BUSY;
		bbp->b_dev = bp->b_dev;
		bbp->b_bcount = 512;
		bbp->b_un.b_addr = (caddr_t)&upbad[ui->ui_unit];
		bbp->b_blkno = st->ncyl * st->nspc - st->nsect;
		bbp->b_cylin = st->ncyl - 1;
		dp->b_actf = bbp;
		bbp->av_forw = bp;
		bp = bbp;
D 96
#endif
E 96
E 92
I 90
#ifndef NOBADSECT
		st = &upst[ui->ui_type];
		bbp->b_flags = B_READ|B_BUSY;
		bbp->b_dev = bp->b_dev;
		bbp->b_bcount = 512;
		bbp->b_un.b_addr = (caddr_t)&upbad[ui->ui_unit];
		bbp->b_blkno = st->ncyl * st->nspc - st->nsect;
		bbp->b_cylin = st->ncyl - 1;
		dp->b_actf = bbp;
		bbp->av_forw = bp;
		bp = bbp;
#endif
E 90
E 4
	}
I 51
	/*
	 * If drive is offline, forget about positioning.
	 */
E 51
D 11
	/*
D 2
	 * Don't SEARCH twice on same drive; avoids looping.
E 2
I 2
	 * We are called from upstrategy when a new request arrives
	 * if we are not already active (with dp->b_active == 0),
	 * and we then set dp->b_active to 1 if we are to SEARCH
	 * for the desired cylinder, or 2 if we are on-cylinder.
	 * If we SEARCH then we will later be called from upintr()
	 * when the search is complete, and will link this disk onto
	 * the uptab.  We then set dp->b_active to 2 so that upintr()
	 * will not call us again.
	 *
	 * NB: Other drives clear the bit in the attention status
	 * (i.e. upas) register corresponding to the drive when they
	 * place the drive on the ready (i.e. uptab) queue.  This does
	 * not work with the Emulex, as the controller hangs the UBA
	 * of the VAX shortly after the upas register is set, for
	 * reasons unknown.  This only occurs in multi-spindle configurations,
	 * but to avoid the problem we use the fact that dp->b_active is
	 * 2 to replace the clearing of the upas bit.
E 2
	 */
E 11
D 2
	if(dp->b_active)
E 2
I 2
D 12
	if (dp->b_active)
E 2
		goto done;
D 2
	dp->b_active++;
E 2
I 2
	dp->b_active = 1;
E 12
E 2
D 49
	if ((upaddr->upds & (DPR|MOL)) != (DPR|MOL))
E 49
I 49
D 65
	if ((upaddr->upds & (UP_DPR|UP_MOL)) != (UP_DPR|UP_MOL))
E 65
I 65
	if ((upaddr->upds & (UPDS_DPR|UPDS_MOL)) != (UPDS_DPR|UPDS_MOL))
E 65
E 49
D 2
		goto done;
E 2
I 2
D 11
		goto done;	/* Will redetect error in upstart() soon */
E 2

E 11
I 11
		goto done;
I 51
	/*
	 * If there is only one drive,
	 * dont bother searching.
	 */
E 51
I 47
	if (up_softc[um->um_ctlr].sc_ndrive == 1)
		goto done;
I 51
	/*
	 * Figure out where this transfer is going to
	 * and see if we are close enough to justify not searching.
	 */
E 51
E 47
I 40
D 42

#if NUP > 1
E 40
E 11
I 2
	/*
	 * Do enough of the disk address decoding to determine
	 * which cylinder and sector the request is on.
D 11
	 * Then compute the number of the sector SDIST sectors before
	 * the one where the transfer is to start, this being the
	 * point where we wish to attempt to begin the transfer,
	 * allowing approximately SDIST/2 msec for interrupt latency
	 * and preparation of the request.
	 *
E 11
	 * If we are on the correct cylinder and the desired sector
D 14
	 * lies between SDIST and SDIST+RDIST sectors ahead of us, then
E 14
I 14
	 * lies between upSDIST and upSDIST+upRDIST sectors ahead of us, then
E 14
	 * we don't bother to SEARCH but just begin the transfer asap.
I 11
D 14
	 * Otherwise ask for a interrupt SDIST+IDIST sectors ahead.
E 14
I 14
	 * Otherwise ask for a interrupt upSDIST sectors ahead.
E 14
E 11
	 */
E 42
I 42
	st = &upst[ui->ui_type];
E 42
E 2
D 117
	bn = dkblock(bp);
E 117
I 117
	bn = bp->b_blkno;
E 117
D 51
	cn = bp->b_cylin;
E 51
D 42
	sn = bn%(NSECT*NTRAC);
D 14
	sn = (sn+NSECT-SDIST)%NSECT;
E 14
I 14
	sn = (sn+NSECT-upSDIST)%NSECT;
E 14

E 42
I 42
	sn = bn%st->nspc;
D 107
	sn = (sn + st->nsect - upSDIST) % st->nsect;
E 107
I 107
	sn = (sn + st->nsect - st->sdist) % st->nsect;
E 107
E 42
D 2
	if(cn - upaddr->updc)
		goto search;
E 2
I 2
D 51
	if (cn - upaddr->updc)
E 51
I 51
	if (bp->b_cylin - upaddr->updc)
E 51
		goto search;		/* Not on-cylinder */
I 42
D 45
/****				WHAT SHOULD THIS BE NOW ???
E 45
E 42
I 11
	else if (upseek)
		goto done;		/* Ok just to be on-cylinder */
E 11
E 2
	csn = (upaddr->upla>>6) - sn - 1;
D 2
	if(csn < 0)
E 2
I 2
	if (csn < 0)
E 2
D 42
		csn += NSECT;
D 2
	if(csn > NSECT-RDIST)
E 2
I 2
D 14
	if (csn > NSECT-RDIST)
E 14
I 14
	if (csn > NSECT-upRDIST)
E 42
I 42
		csn += st->nsect;
D 107
	if (csn > st->nsect - upRDIST)
E 107
I 107
	if (csn > st->nsect - st->rdist)
E 107
E 42
E 14
E 2
		goto done;
D 42

E 42
search:
I 8
D 9
#ifdef UTRACE
D(6)	trace(" search %d@%d to %d@%d", upaddr->updc, (upaddr->upla>>6),
	    cn, sn);
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
	trace(" search %d@%d to %d@%d", upaddr->updc, (upaddr->upla>>6),
E 6
I 6
D(6)	trace(" search %d@%d to %d@%d", upaddr->updc, (upaddr->upla>>6),
E 6
	    cn, sn);
#endif
E 7
E 5
D 51
	upaddr->updc = cn;
E 51
I 51
	upaddr->updc = bp->b_cylin;
	/*
	 * Not on cylinder at correct position,
	 * seek/search.
	 */
E 51
I 42
D 45
/***				ANOTHER OCCURRENCE
E 45
E 42
D 11
	upaddr->upda = sn;
I 2
D 3
	if (cs1del&8) DELAY(500);
E 3
E 2
	upaddr->upcs1 = IE|SEARCH|GO;
E 11
I 11
	if (upseek)
D 49
		upaddr->upcs1 = IE|SEEK|GO;
E 49
I 49
		upaddr->upcs1 = UP_IE|UP_SEEK|UP_GO;
E 49
D 42
	else {
E 42
I 42
D 45
	else  ****/   {
E 45
I 45
	else {
E 45
E 42
		upaddr->upda = sn;
D 49
		upaddr->upcs1 = IE|SEARCH|GO;
E 49
I 49
		upaddr->upcs1 = UP_IE|UP_SEARCH|UP_GO;
E 49
	}
E 11
I 4
	didie = 1;
I 51
	/*
	 * Mark unit busy for iostat.
	 */
E 51
E 4
I 2
D 3
	if (cs1del&8) DELAY(500);
E 3
D 42
	/*
	 * Mark this unit busy.
	 */
E 2
D 37
	unit += DK_N;
D 17
	if (unit <= DK_NMAX) {
E 17
I 17
D 25
	if (unit <= DK_NMAX && DK_N+NUP <= DK_NMAX) {
E 25
I 25
	if (unit <= DK_NMAX) {
E 37
I 37
	unit += UPDK_N;
	if (unit <= UPDK_NMAX) {
E 37
E 25
E 17
		dk_busy |= 1<<unit;
D 25
		dk_numb[unit]++;
E 25
I 25
		dk_seek[unit]++;
E 42
I 42
	if (ui->ui_dk >= 0) {
		dk_busy |= 1<<ui->ui_dk;
		dk_seek[ui->ui_dk]++;
E 42
E 25
	}
I 16
D 18
#ifdef OLDUCODE
E 16
I 6
D 11
	if (csdel0) DELAY(csdel0);
E 11
I 11
	DELAY(rdelay);
I 16
#endif
E 18
I 18
D 29
	if (olducode)
		DELAY(ordelay);
E 29
E 18
E 16
E 11
E 6
D 4
	return;
E 4
I 4
	goto out;
I 40
D 42
#endif
E 40
E 4

E 42
done:
I 51
	/*
	 * Device is ready to go.
	 * Put it on the ready queue for the controller
	 * (unless its already there.)
	 */
E 51
I 2
D 42
	/*
D 11
	 * This unit is ready to go.  Make active == 2 so
	 * we won't get called again (by upintr() because upas&(1<<unit))
	 * and link us onto the chain of ready disks.
E 11
I 11
	 * This unit is ready to go so
	 * link it onto the chain of ready disks.
E 11
	 */
E 42
I 8
D 9
#ifdef UTRACE
D(7)	trace(" done");
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
	trace(" done");
E 6
I 6
D(7)	trace(" done");
E 6
#endif
E 7
E 5
D 11
	dp->b_active = 2;
E 11
E 2
D 49
	dp->b_forw = NULL;
D 2
	if(uptab.b_actf == NULL)
E 2
I 2
D 42
	if (uptab.b_actf == NULL)
E 2
		uptab.b_actf = dp;
E 42
I 42
	if (um->um_tab.b_actf == NULL)
		um->um_tab.b_actf = dp;
E 42
	else
D 42
		uptab.b_actl->b_forw = dp;
	uptab.b_actl = dp;
I 4

E 42
I 42
		um->um_tab.b_actl->b_forw = dp;
	um->um_tab.b_actl = dp;
E 49
I 49
	if (dp->b_active != 2) {
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
		dp->b_active = 2;
	}
E 49
E 42
out:
I 8
D 10
	if (csdel1) DELAY(csdel1);
E 10
D 9
#ifdef UTRACE
D(8)	trace("\n");
#endif
E 9
E 8
I 6
D 7
	if (csdel1) DELAY(csdel1);
E 6
I 5
#ifdef UTRACE
D 6
	trace("\n");
E 6
I 6
D(8)	trace("\n");
E 6
#endif
E 7
E 5
	return (didie);
E 4
}

I 51
/*
 * Start up a transfer on a drive.
 */
E 51
D 42
/*
 * Start a transfer; call from top level at spl5() or on interrupt.
D 2
 *
 * Pick a drive off the queue of ready drives and perform
 * the first transfer in its queue.
E 2
 */
upstart()
E 42
I 42
upstart(um)
D 59
	register struct uba_minfo *um;
E 59
I 59
	register struct uba_ctlr *um;
E 59
E 42
{
	register struct buf *bp, *dp;
I 42
D 59
	register struct uba_dinfo *ui;
E 59
I 59
	register struct uba_device *ui;
E 59
E 42
D 47
	register unit;
E 47
D 49
	register struct device *upaddr;
E 49
I 49
	register struct updevice *upaddr;
E 49
I 42
D 45
	register struct upst *st;
E 45
I 45
	struct upst *st;
D 47
	struct up_softc *sc = &up_softc[um->um_ctlr];
E 47
E 45
E 42
	daddr_t bn;
D 2
	int dn, sn, tn, cn;
E 2
I 2
D 43
	int dn, sn, tn, cn, cmd;
E 43
I 43
D 52
	int dn, sn, tn, cmd;
E 52
I 52
	int dn, sn, tn, cmd, waitdry;
E 52
E 43
E 2

D 5
	if (printsw&2) printf("upstart\n");
E 5
loop:
I 51
	/*
	 * Pull a request off the controller queue
	 */
E 51
I 8
D 16
	if (csdel2) DELAY(csdel2);
E 16
D 9
#ifdef UTRACE
D(9)	ttime();
D(10)	trace("upstart");
#endif
E 9
E 8
I 6
D 7
	if (csdel2) DELAY(csdel2);
E 6
I 5
#ifdef UTRACE
D 6
	ttime();
	trace("upstart");
E 6
I 6
D(9)	ttime();
D(10)	trace("upstart");
E 6
#endif
E 7
E 5
I 2
D 42
	/*
	 * Pick a drive off the queue of ready drives, and
	 * perform the first transfer on its queue.
	 *
	 * Looping here is completely for the sake of drives which
	 * are not present and on-line, for which we completely clear the
	 * request queue.
	 */
E 2
D 5
	if ((dp = uptab.b_actf) == NULL)
E 5
I 5
D 9
	if ((dp = uptab.b_actf) == NULL) {
I 8
#ifdef UTRACE
D(11)		trace("\n");
#endif
E 9
I 9
	if ((dp = uptab.b_actf) == NULL)
E 42
I 42
	if ((dp = um->um_tab.b_actf) == NULL)
E 42
E 9
E 8
D 7
#ifdef UTRACE
D 6
		trace("\n");
E 6
I 6
D(11)		trace("\n");
E 6
#endif
E 7
E 5
D 4
		return;
E 4
I 4
		return (0);
I 5
D 9
	}
E 9
E 5
E 4
	if ((bp = dp->b_actf) == NULL) {
D 42
		uptab.b_actf = dp->b_forw;
E 42
I 42
		um->um_tab.b_actf = dp->b_forw;
E 42
		goto loop;
	}
I 51
	/*
	 * Mark controller busy, and
	 * determine destination of this request.
	 */
E 51
I 2
D 49
	/*
	 * Mark the controller busy, and multi-part disk address.
	 * Select the unit on which the i/o is to take place.
	 */
E 49
E 2
D 42
	uptab.b_active++;
	unit = minor(bp->b_dev) & 077;
	dn = dkunit(bp);
E 42
I 42
	um->um_tab.b_active++;
D 117
	ui = updinfo[dkunit(bp)];
E 42
	bn = dkblock(bp);
E 117
I 117
	ui = updinfo[upunit(bp->b_dev)];
	bn = bp->b_blkno;
E 117
D 42
	cn = up_sizes[unit&07].cyloff;
	cn += bn/(NSECT*NTRAC);
	sn = bn%(NSECT*NTRAC);
	tn = sn/NSECT;
D 2
	sn = sn%NSECT;

E 2
I 2
	sn %= NSECT;
E 2
	upaddr = UPADDR;
E 42
I 42
	dn = ui->ui_slave;
	st = &upst[ui->ui_type];
	sn = bn%st->nspc;
	tn = sn/st->nsect;
	sn %= st->nsect;
D 49
	upaddr = (struct device *)ui->ui_addr;
E 49
I 49
	upaddr = (struct updevice *)ui->ui_addr;
E 49
E 42
I 8
D 9
#ifdef UTRACE
D(12)	trace(" unit %d", dn);
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
	trace(" unit %d", dn);
E 6
I 6
D(12)	trace(" unit %d", dn);
E 6
#endif
E 7
E 5
D 2
	if (slow3) DELAY(idelay);
E 2
D 29
	if ((upaddr->upcs2 & 07) != dn) {
E 29
I 29
D 47
	if ((upaddr->upcs2 & 07) != dn)
E 29
I 8
D 9
#ifdef UTRACE
D(13)		trace(" select");
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
		trace(" select");
E 6
I 6
D(13)		trace(" select");
E 6
#endif
E 7
E 5
		upaddr->upcs2 = dn;
E 47
I 47
D 51
	upaddr->upcs2 = dn;
E 51
I 51
	/*
	 * Select drive if not selected already.
	 */
	if ((upaddr->upcs2&07) != dn)
		upaddr->upcs2 = dn;
	/*
	 * Check that it is ready and online
	 */
E 51
E 47
D 11
		DELAY(sdelay);
E 11
I 11
D 29
		/* DELAY(sdelay);		Provided by ubasetup() */
E 11
		nwaitcs2++;
	} else
		neasycs2++;
D 2
	up_ubinfo = ubasetup(bp, 1);
E 2
I 2
D 11
	up_ubinfo = ubasetup(bp, 1);	/* In a funny place for delay... */
E 11
I 11
	up_ubinfo = ubasetup(bp, 1);	/* Providing delay */
E 29
I 29
D 42
	up_ubinfo = ubasetup(bp, 1);
E 42
I 42
D 44
	up_softc[um->um_num].sc_info =
E 44
I 44
D 45
	up_softc[um->um_ctlr].sc_info =
E 45
I 45
D 46
	sc->sc_info =
E 45
E 44
	    ubasetup(ui->ui_ubanum, bp, UBA_NEEDBDP|UBA_CANTWAIT);
E 46
E 42
E 29
E 11
D 49
	/*
	 * If drive is not present and on-line, then
	 * get rid of this with an error and loop to get
	 * rid of the rest of its queued requests.
	 * (Then on to any other ready drives.)
	 */
E 2
	if ((upaddr->upds & (DPR|MOL)) != (DPR|MOL)) {
E 49
I 49
D 52
	if ((upaddr->upds & (UP_DPR|UP_MOL)) != (UP_DPR|UP_MOL)) {
E 52
I 52
	waitdry = 0;
D 65
	while ((upaddr->upds&UP_DRY) == 0) {
E 65
I 65
	while ((upaddr->upds&UPDS_DRY) == 0) {
I 90
		printf("up%d: ds wait ds=%o\n",dkunit(bp),upaddr->upds);
E 90
I 83
D 117
		printf("up%d: ds wait ds=%o\n",dkunit(bp),upaddr->upds);
E 117
I 117
		printf("up%d: ds wait ds=%o\n",upunit(bp->b_dev),upaddr->upds);
E 117
E 83
E 65
		if (++waitdry > 512)
			break;
		upwaitdry++;
	}
D 65
	if ((upaddr->upds & UP_DREADY) != UP_DREADY) {
E 65
I 65
	if ((upaddr->upds & UPDS_DREADY) != UPDS_DREADY) {
E 65
E 52
E 49
I 11
D 22
		printf("!DPR || !MOL, unit %d, ds %o\n", dn, upaddr->upds);
E 11
I 8
D 9
#ifdef UTRACE
D(14)		trace(" !(DPR && MOL)");
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
		trace(" !(DPR && MOL)");
E 6
I 6
D(14)		trace(" !(DPR && MOL)");
E 6
#endif
E 7
E 5
		uptab.b_active = 0;
		uptab.b_errcnt = 0;
		dp->b_actf = bp->av_forw;
I 2
		dp->b_active = 0;
E 2
		bp->b_flags |= B_ERROR;
		iodone(bp);
D 2
		ubafree(up_ubinfo), up_ubinfo = 0;
E 2
I 2
		ubafree(up_ubinfo), up_ubinfo = 0;	/* A funny place ... */
E 2
		goto loop;
E 22
I 22
D 47
		printf("!DPR || !MOL, unit %d, ds %o", dn, upaddr->upds);
E 47
I 47
D 58
		printf("up%d not ready", dkunit(bp));
E 58
I 58
D 117
		printf("up%d: not ready", dkunit(bp));
E 117
I 117
		printf("up%d: not ready", upunit(bp->b_dev));
E 117
E 58
E 47
D 49
		if ((upaddr->upds & (DPR|MOL)) != (DPR|MOL)) {
E 49
I 49
D 52
		if ((upaddr->upds & (UP_DPR|UP_MOL)) != (UP_DPR|UP_MOL)) {
E 52
I 52
D 65
		if ((upaddr->upds & UP_DREADY) != UP_DREADY) {
E 65
I 65
		if ((upaddr->upds & UPDS_DREADY) != UPDS_DREADY) {
E 65
E 52
E 49
D 47
			printf("-- hard\n");
E 47
I 47
			printf("\n");
E 47
D 42
			uptab.b_active = 0;
			uptab.b_errcnt = 0;
E 42
I 42
			um->um_tab.b_active = 0;
			um->um_tab.b_errcnt = 0;
E 42
			dp->b_actf = bp->av_forw;
			dp->b_active = 0;
			bp->b_flags |= B_ERROR;
			iodone(bp);
D 46
			/* A funny place to do this ... */
D 38
			ubafree(up_ubinfo), up_ubinfo = 0;
E 38
I 38
D 39
			UBAFREECLR(up_ubinfo);
E 39
I 39
D 42
			ubarelse(&up_ubinfo);
E 42
I 42
D 43
			ubarelse(&up_softc[um->um_num].sc_info);
E 43
I 43
D 44
			ubarelse(ui->ui_ubanum, &up_softc[um->um_num].sc_info);
E 44
I 44
D 45
			ubarelse(ui->ui_ubanum, &up_softc[um->um_ctlr].sc_info);
E 45
I 45
			ubarelse(ui->ui_ubanum, &sc->sc_info);
E 46
E 45
E 44
E 43
E 42
E 39
E 38
			goto loop;
		}
I 51
		/*
		 * Oh, well, sometimes this
		 * happens, for reasons unknown.
		 */
E 51
D 47
		printf("-- came back\n");
E 47
I 47
D 49
		printf(" (flakey... it came back)\n");
E 49
I 49
		printf(" (flakey)\n");
E 49
E 47
E 22
	}
I 51
	/*
D 62
	 * After 16th retry, do offset positioning
	 */
E 51
D 2
	if(uptab.b_errcnt >= 16) {
E 2
I 2
D 49
	/*
	 * If this is a retry, then with the 16'th retry we
	 * begin to try offsetting the heads to recover the data.
	 */
E 49
D 23
	if (uptab.b_errcnt >= 16) {
E 23
I 23
D 24
	if (uptab.b_errcnt >= 16 && (bp->b_flags&B_WRITE)) {
E 24
I 24
D 40
	if (uptab.b_errcnt >= 16 && (bp->b_flags&B_WRITE) == 0) {
E 40
I 40
D 42
	if (uptab.b_errcnt >= 16 && (bp->b_flags&B_READ) != 0) {
E 40
E 24
E 23
I 8
D 9
#ifdef UTRACE
D(15)		trace(" offset");
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
		trace(" offset");
E 6
I 6
D(15)		trace(" offset");
E 6
#endif
E 7
E 5
E 2
		upaddr->upof = up_offset[uptab.b_errcnt & 017] | FMT22;
E 42
I 42
	if (um->um_tab.b_errcnt >= 16 && (bp->b_flags&B_READ) != 0) {
D 49
		upaddr->upof = up_offset[um->um_tab.b_errcnt & 017] | FMT22;
E 42
D 2
		upaddr->upcs1 = OFFSET|GO;
E 2
I 2
		upaddr->upcs1 = IE|OFFSET|GO;
E 2
D 29
		DELAY(idelay);
E 29
D 2
		while(upaddr->upds & PIP)
E 2
I 2
		while (upaddr->upds & PIP)
E 49
I 49
		upaddr->upof = up_offset[um->um_tab.b_errcnt & 017] | UP_FMT22;
		upaddr->upcs1 = UP_IE|UP_OFFSET|UP_GO;
		while (upaddr->upds & UP_PIP)
E 49
E 2
			DELAY(25);
	}
I 51
	/*
E 62
	 * Setup for the transfer, and get in the
	 * UNIBUS adaptor queue.
	 */
E 51
I 2
D 49
	/*
	 * Now set up the transfer, retrieving the high
	 * 2 bits of the UNIBUS address from the information
	 * returned by ubasetup() for the cs1 register bits 8 and 9.
	 */
E 49
I 8
D 9
#ifdef UTRACE
D(16)	trace(" %s %d.%d@%d cnt %d ba %x\n",
	    (bp->b_flags&B_READ) ? "read" : "write",
	    cn, tn, sn, bp->b_bcount, up_ubinfo & 0x3ffff);
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
	trace(" %s %d.%d@%d cnt %d ba %x\n",
E 6
I 6
D(16)	trace(" %s %d.%d@%d cnt %d ba %x\n",
E 6
	    (bp->b_flags&B_READ) ? "read" : "write",
	    cn, tn, sn, bp->b_bcount, up_ubinfo & 0x3ffff);
#endif
E 7
E 5
E 2
D 43
	upaddr->updc = cn;
E 43
I 43
	upaddr->updc = bp->b_cylin;
E 43
	upaddr->upda = (tn << 8) + sn;
D 42
	upaddr->upba = up_ubinfo;
E 42
I 42
D 44
	upaddr->upba = up_softc[um->um_num].sc_info;
E 44
I 44
D 45
	upaddr->upba = up_softc[um->um_ctlr].sc_info;
E 45
I 45
D 46
	upaddr->upba = sc->sc_info;
E 46
E 45
E 44
E 42
I 2
D 3
	if (cs1del&1) DELAY(500);
E 3
E 2
	upaddr->upwc = -bp->b_bcount / sizeof (short);
I 2
D 42
	cmd = (up_ubinfo >> 8) & 0x300;
E 42
I 42
D 44
	cmd = (up_softc[um->um_num].sc_info >> 8) & 0x300;
E 44
I 44
D 45
	cmd = (up_softc[um->um_ctlr].sc_info >> 8) & 0x300;
E 45
I 45
D 46
	cmd = (sc->sc_info >> 8) & 0x300;
E 46
E 45
E 44
E 42
E 2
	if (bp->b_flags & B_READ)
D 2
		upaddr->upcs1 = IE|GO|RCOM;
E 2
I 2
D 46
		cmd |= IE|RCOM|GO;
E 46
I 46
D 49
		cmd = IE|RCOM|GO;
E 49
I 49
		cmd = UP_IE|UP_RCOM|UP_GO;
E 49
E 46
E 2
	else
D 2
		upaddr->upcs1 = IE|GO|WCOM;

E 2
I 2
D 46
		cmd |= IE|WCOM|GO;
D 3
	if (cs1del&1) DELAY(500);
E 3
	upaddr->upcs1 = cmd;
I 8
D 9
#ifdef notdef
	if (csdel3) DELAY(csdel3);
#endif
E 9
E 8
I 4
D 7
#ifdef notdef
E 4
D 3
	if (cs1del&1) DELAY(500);
E 3
I 3
	if (csdel3) DELAY(csdel3);
I 4
#endif
E 7
E 4
E 3
	/*
D 45
	 * This is a controller busy situation.
D 37
	 * Record in dk slot NUP+DK_N (after last drive)
E 37
I 37
	 * Record in dk slot NUP+UPDK_N (after last drive)
E 37
	 * unless there aren't that many slots reserved for
	 * us in which case we record this as a drive busy
	 * (if there is room for that).
E 45
I 45
	 * Mark i/o in progress
E 45
	 */
E 2
D 37
	unit = dn+DK_N;
D 25
	if (NUP+DK_N == DK_NMAX)
		unit = NUP+DK_N;
E 25
	if (unit <= DK_NMAX) {
E 37
I 37
D 42
	unit = dn+UPDK_N;
	if (unit <= UPDK_NMAX) {
E 37
		dk_busy |= 1<<unit;
D 25
		dk_numb[unit]++;
E 25
I 25
		dk_xfer[unit]++;
E 25
		dk_wds[unit] += bp->b_bcount>>6;
	}
E 42
I 42
D 45
	unit = ui->ui_dk;
	dk_busy |= 1<<unit;
	dk_xfer[unit]++;
	dk_wds[unit] += bp->b_bcount>>6;
E 45
I 45
	if (ui->ui_dk >= 0) {
		unit = ui->ui_dk;
		dk_busy |= 1<<unit;
		dk_xfer[unit]++;
		dk_wds[unit] += bp->b_bcount>>6;
	}
E 46
I 46
D 49
		cmd = IE|WCOM|GO;
E 49
I 49
		cmd = UP_IE|UP_WCOM|UP_GO;
E 49
	um->um_cmd = cmd;
D 60
	ubago(ui);
E 60
I 60
	(void) ubago(ui);
E 60
E 46
E 45
E 42
I 4
	return (1);
E 4
}

I 51
/*
 * Now all ready to go, stuff the registers.
 */
E 51
I 42
D 46
updgo()
E 46
I 46
updgo(um)
D 59
	struct uba_minfo *um;
E 59
I 59
	struct uba_ctlr *um;
E 59
E 46
{
I 46
D 49
	register struct device *upaddr = (struct device *)um->um_addr;
E 49
I 49
	register struct updevice *upaddr = (struct updevice *)um->um_addr;
E 49
E 46
I 45

I 73
D 82
D 90
	um->um_tab.b_active++;	/* should now be 2 */
E 90
I 90
	um->um_tab.b_active = 2;	/* should now be 2 */
E 90
E 82
I 82
	um->um_tab.b_active = 2;	/* should now be 2 */
E 82
E 73
I 46
	upaddr->upba = um->um_ubinfo;
	upaddr->upcs1 = um->um_cmd|((um->um_ubinfo>>8)&0x300);
E 46
E 45
}

I 51
/*
 * Handle a disk interrupt.
 */
E 51
E 42
D 49
/*
 * Handle a device interrupt.
 *
 * If the transferring drive needs attention, service it
 * retrying on error or beginning next transfer.
 * Service all other ready drives, calling ustart to transfer
D 42
 * their blocks to the ready queue in uptab, and then restart
E 42
I 42
 * their blocks to the ready queue in um->um_tab, and then restart
E 42
 * the controller if there is anything to do.
 */
E 49
D 42
upintr()
E 42
I 42
D 48
upintr(sc21)
E 48
I 48
D 53
scintr(sc21)
E 53
I 53
upintr(sc21)
E 53
E 48
	register sc21;
E 42
{
	register struct buf *bp, *dp;
I 42
D 59
	register struct uba_minfo *um = upminfo[sc21];
	register struct uba_dinfo *ui;
E 59
I 59
	register struct uba_ctlr *um = upminfo[sc21];
	register struct uba_device *ui;
E 59
D 49
	register struct device *upaddr = (struct device *)um->um_addr;
E 49
I 49
	register struct updevice *upaddr = (struct updevice *)um->um_addr;
E 49
E 42
	register unit;
I 45
	struct up_softc *sc = &up_softc[um->um_ctlr];
E 45
D 42
	register struct device *upaddr = UPADDR;
E 42
D 47
	int as = upaddr->upas & 0377;
E 47
I 47
	int as = (upaddr->upas & 0377) | sc->sc_softas;
E 47
I 8
D 16
	int osoftas;
E 16
I 16
D 42
	int oupsoftas;
E 42
E 16
E 8
I 4
D 52
	int needie = 1;
E 52
I 52
	int needie = 1, waitdry;
E 52
E 4

I 16
D 19
#ifdef OLDUCODE
E 19
E 16
I 12
D 46
	(void) spl6();
E 46
I 16
D 19
#endif
E 19
E 16
I 15
D 42
	up_wticks = 0;
E 15
E 12
I 8
D 9
#ifdef UTRACE
D(17)	ttime();
D(18)	trace("upintr as %d act %d %d %d;", as, uptab.b_active, uputab[0].b_active, uputab[1].b_active);
#endif
E 9
E 8
D 2
	if (printsw&4) printf("upintr\n");
	if(uptab.b_active) {
E 2
I 2
D 5
	if (printsw&4) printf("upintr as=%d act %d %d %d\n", as, uptab.b_active, uputab[0].b_active, uputab[1].b_active);
E 5
I 5
D 7
#ifdef UTRACE
D 6
	ttime();
	trace("upintr as %d act %d %d %d;", as, uptab.b_active, uputab[0].b_active, uputab[1].b_active);
E 6
I 6
D(17)	ttime();
D(18)	trace("upintr as %d act %d %d %d;", as, uptab.b_active, uputab[0].b_active, uputab[1].b_active);
E 6
#endif
E 7
E 5
	if (uptab.b_active) {
		/*
		 * The drive is transferring, thus the hardware
		 * (say the designers) will only interrupt when the transfer
		 * completes; check for it anyways.
		 */
E 42
I 42
D 44
	up_softc[um->um_num].sc_wticks = 0;
E 44
I 44
D 45
	up_softc[um->um_ctlr].sc_wticks = 0;
E 45
I 45
	sc->sc_wticks = 0;
I 47
	sc->sc_softas = 0;
E 47
E 45
E 44
D 51
	if (um->um_tab.b_active) {
E 42
D 45
		if ((upaddr->upcs1 & RDY) == 0) {
I 5
D 7
#ifdef UTRACE
D 6
			trace(" !RDY");
E 6
I 6
D(19)			trace(" !RDY");
E 6
#endif
E 7
E 5
D 3
			printf("upintr b_active && !RDY\n");
			goto out;
		}
E 3
I 3
D 8
			printf("!RDY in upintr: cs1 %o\n", upaddr->upcs1);
E 8
I 8
D 9
#ifdef UTRACE
D(19)			trace(" !RDY");
#endif
E 9
			printf("!RDY: cs1 %o, ds %o, wc %d\n", upaddr->upcs1,
			    upaddr->upds, upaddr->upwc);
E 8
D 16
printf("as=%d act %d %d %d\n", as, uptab.b_active, uputab[0].b_active, uputab[1].b_active);
E 16
I 16
D 42
			printf("as=%d act %d %d %d\n", as, uptab.b_active,
E 42
I 42
			printf("as=%d act %d %d %d\n", as, um->um_tab.b_active,
E 42
			    uputab[0].b_active, uputab[1].b_active);
E 16
D 5
}
E 5
I 5
		}
E 45
I 45
D 49
		if ((upaddr->upcs1 & RDY) == 0)
E 49
I 49
		if ((upaddr->upcs1 & UP_RDY) == 0)
E 49
			printf("upintr !RDY\n");
E 45
E 5
E 3
D 42
		/*
D 25
		 * Mark controller or drive not busy, and check for an
E 25
I 25
		 * Mark drive not busy, and check for an
E 25
		 * error condition which may have resulted from the transfer.
		 */
E 2
		dp = uptab.b_actf;
E 42
I 42
		dp = um->um_tab.b_actf;
E 42
		bp = dp->b_actf;
D 42
		unit = dkunit(bp);
D 25
		if (DK_N+NUP == DK_NMAX)
			dk_busy &= ~(1<<(DK_N+NUP));
		else if (DK_N+unit <= DK_NMAX)
E 25
I 25
D 37
		if (DK_N+unit <= DK_NMAX)
E 25
			dk_busy &= ~(1<<(DK_N+unit));
E 37
I 37
		if (UPDK_N+unit <= UPDK_NMAX)
			dk_busy &= ~(1<<(UPDK_N+unit));
E 37
D 11
		if (upaddr->upcs1 & TRE) {
E 11
I 11
D 29
		if ((upaddr->upcs2 & 07) != unit) {
E 29
I 29
		if ((upaddr->upcs2 & 07) != unit)
E 29
			upaddr->upcs2 = unit;
E 42
I 42
		ui = updinfo[dkunit(bp)];
		dk_busy &= ~(1 << ui->ui_dk);
E 51
I 51
	/*
	 * If controller wasn't transferring, then this is an
	 * interrupt for attention status on seeking drives.
	 * Just service them.
	 */
D 73
	if (um->um_tab.b_active == 0) {
E 73
I 73
	if (um->um_tab.b_active != 2 && !sc->sc_recal) {
E 73
		if (upaddr->upcs1 & UP_TRE)
			upaddr->upcs1 = UP_TRE;
		goto doattn;
	}
I 90
	um->um_tab.b_active = 1;
E 90
I 82
	um->um_tab.b_active = 1;
E 82
D 58
	if ((upaddr->upcs1 & UP_RDY) == 0)
		printf("upintr !RDY\n");		/* shouldn't happen */
E 58
	/*
I 62
D 64
	 * Release unibus resources and flush data paths.
	 */
	ubadone(um);
	/*
E 64
E 62
	 * Get device and block structures, and a pointer
D 59
	 * to the uba_dinfo for the drive.  Select the drive.
E 59
I 59
	 * to the uba_device for the drive.  Select the drive.
E 59
	 */
	dp = um->um_tab.b_actf;
	bp = dp->b_actf;
D 117
	ui = updinfo[dkunit(bp)];
E 117
I 117
	ui = updinfo[upunit(bp->b_dev)];
E 117
	dk_busy &= ~(1 << ui->ui_dk);
	if ((upaddr->upcs2&07) != ui->ui_slave)
E 51
		upaddr->upcs2 = ui->ui_slave;
I 92
D 96
#ifndef NOBADSECT
E 96
	if (bp->b_flags&B_BAD) {
		if (upecc(ui, CONT))
			return;
	}
D 96
#endif
E 96
E 92
I 90
#ifndef NOBADSECT
	if (bp->b_flags&B_BAD) {
		if (upecc(ui, CONT))
			return;
	}
#endif
E 90
E 42
D 18
			DELAY(sdelay);
E 18
I 18
D 29
			DELAY(olducode ? osdelay : nsdelay);
E 18
			nwaitcs2++;
		} else
			neasycs2++;
E 29
D 21
		if (upaddr->upds & ERR) {
E 21
I 21
D 49
		if ((upaddr->upds&ERR) || (upaddr->upcs1&TRE)) {
E 49
I 49
D 51
		if ((upaddr->upds&UP_ERR) || (upaddr->upcs1&UP_TRE)) {
E 49
I 33
			int cs2;
E 33
E 21
E 11
I 8
D 9
#ifdef UTRACE
D(20)			trace(" TRE");
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
			trace(" TRE");
E 6
I 6
D(20)			trace(" TRE");
E 6
#endif
E 7
E 5
I 2
D 42
			/*
			 * An error occurred, indeed.  Select this unit
			 * to get at the drive status (a SEARCH may have
			 * intervened to change the selected unit), and
			 * wait for the command which caused the interrupt
			 * to complete (DRY).
D 11
			 *
			 * WHY IS THE WAIT NECESSARY?
E 11
			 */
E 42
E 2
D 11
			if ((upaddr->upcs2 & 07) != unit) {
				upaddr->upcs2 = unit;
				DELAY(sdelay);
				nwaitcs2++;
			} else
				neasycs2++;
E 11
D 2
			while((upaddr->upds & DRY) == 0)
E 2
I 2
D 49
			while ((upaddr->upds & DRY) == 0)
E 49
I 49
			while ((upaddr->upds & UP_DRY) == 0)
E 49
E 2
				DELAY(25);
I 47
D 49
			if (upaddr->uper1&WLE)	
E 49
I 49
			if (upaddr->uper1&UP_WLE)	
E 49
				printf("up%d is write locked\n", dkunit(bp));
E 47
D 2
			if(++uptab.b_errcnt > 28 || upaddr->uper1&WLE)
E 2
I 2
D 42
			/*
			 * After 28 retries (16 w/o servo offsets, and then
			 * 12 with servo offsets), or if we encountered
			 * an error because the drive is write-protected,
			 * give up.  Print an error message on the last 2
			 * retries before a hard failure.
			 */
			if (++uptab.b_errcnt > 28 || upaddr->uper1&WLE)
E 42
I 42
D 49
			if (++um->um_tab.b_errcnt > 28 || upaddr->uper1&WLE)
E 49
I 49
			if (++um->um_tab.b_errcnt > 28 || upaddr->uper1&UP_WLE)
E 49
E 42
E 2
				bp->b_flags |= B_ERROR;
			else
D 2
				uptab.b_active = 0;
			if(uptab.b_errcnt > 27)
E 2
I 2
D 42
				uptab.b_active = 0;	/* To force retry */
			if (uptab.b_errcnt > 27)
E 42
I 42
				um->um_tab.b_active = 0; /* force retry */
			if (um->um_tab.b_errcnt > 27) {
E 42
I 33
				cs2 = (int)upaddr->upcs2;
E 33
E 2
D 31
				deverror(bp, upaddr->upcs2, upaddr->uper1);
E 31
I 31
D 42
				deverror(bp, (int)upaddr->upcs2,
				    (int)upaddr->uper1);
E 31
D 2
			if ((upaddr->uper1&(DCK|ECH)) == DCK) {
				if (upecc(upaddr, bp))
					return;
			}
E 2
I 2
			/*
			 * If this was a correctible ECC error, let upecc
			 * do the dirty work to correct it.  If upecc
			 * starts another READ for the rest of the data
			 * then it returns 1 (having set uptab.b_active).
			 * Otherwise we are done and fall through to
			 * finish up.
			 */
			if ((upaddr->uper1&(DCK|ECH))==DCK && upecc(upaddr, bp))
E 42
I 42
				deverror(bp, cs2, (int)upaddr->uper1);
E 51
I 51
	/*
	 * Check for and process errors on
	 * either the drive or the controller.
	 */
D 65
	if ((upaddr->upds&UP_ERR) || (upaddr->upcs1&UP_TRE)) {
E 65
I 65
	if ((upaddr->upds&UPDS_ERR) || (upaddr->upcs1&UP_TRE)) {
E 65
D 52
		while ((upaddr->upds & UP_DRY) == 0)
			updrydel++;
		if (upaddr->uper1&UP_WLE) {
E 52
I 52
		waitdry = 0;
D 65
		while ((upaddr->upds & UP_DRY) == 0) {
E 65
I 65
		while ((upaddr->upds & UPDS_DRY) == 0) {
E 65
			if (++waitdry > 512)
				break;
			upwaitdry++;
		}
D 58
		if ((upaddr->upds&UP_DREADY) != UP_DREADY) {
			printf("up%d not ready", dkunit(bp));
			bp->b_flags |= B_ERROR;
		} else if (upaddr->uper1&UP_WLE) {
E 58
I 58
D 65
		if (upaddr->uper1&UP_WLE) {
E 65
I 65
		if (upaddr->uper1&UPER1_WLE) {
E 65
E 58
E 52
			/*
			 * Give up on write locked devices
			 * immediately.
			 */
D 58
			printf("up%d is write locked\n", dkunit(bp));
E 58
I 58
D 117
			printf("up%d: write locked\n", dkunit(bp));
E 117
I 117
			printf("up%d: write locked\n", upunit(bp->b_dev));
E 117
E 58
			bp->b_flags |= B_ERROR;
		} else if (++um->um_tab.b_errcnt > 27) {
			/*
			 * After 28 retries (16 without offset, and
			 * 12 with offset positioning) give up.
I 98
			 * If the error was header CRC, the header is 
			 * screwed up, and the sector may in fact exist
			 * in the bad sector table, better check...
E 98
			 */
I 98
			if (upaddr->uper1&UPER1_HCRC) {
				if (upecc(ui, BSE))
					return;
			}
E 98
I 92
	hard:
E 92
I 90
	hard:
E 90
D 58
			if (upaddr->upcs2&(UP_NEM|UP_MXF)) {
				printf("FLAKEY UP ");
				ubareset(um->um_ubanum);
				return;
E 51
			}
I 51
			harderr(bp);
D 56
			printf("up%d cs2 %b er1 %b er2 %b\n",
			    dkunit(bp), upaddr->upcs2, UPCS2_BITS, upaddr->uper1,
			    UPER1_BITS, upaddr->uper2, UPER2_BITS);
E 56
I 56
			printf("up%d cs2=%b er1=%b er2=%b\n", dkunit(bp),
E 58
I 58
D 125
			harderr(bp, "up");
D 90
D 92
			printf("cs2=%b er1=%b er2=%b\n",
E 58
			    upaddr->upcs2, UPCS2_BITS,
			    upaddr->uper1, UPER1_BITS,
			    upaddr->uper2, UPER2_BITS);
E 92
I 92
			printf("cn=%d tn=%d sn=%d cs2=%b er1=%b er2=%b\n",
E 125
I 125
			diskerr(bp, "up", "hard error", LOG_PRINTF, -1,
			    (struct disklabel *)0);
			printf(" cn=%d tn=%d sn=%d cs2=%b er1=%b er2=%b\n",
E 125
			        upaddr->updc, ((upaddr->upda)>>8)&077,
			        (upaddr->upda)&037,
				upaddr->upcs2, UPCS2_BITS,
				upaddr->uper1, UPER1_BITS,
				upaddr->uper2, UPER2_BITS);
E 92
E 90
I 90
			printf("cn=%d tn=%d sn=%d cs2=%b er1=%b er2=%b\n",
			        upaddr->updc, ((upaddr->upda)>>8)&077,
			        (upaddr->upda)&037,
				upaddr->upcs2, UPCS2_BITS,
				upaddr->uper1, UPER1_BITS,
				upaddr->uper2, UPER2_BITS);
E 90
E 56
			bp->b_flags |= B_ERROR;
I 92
		} else if (upaddr->uper2 & UPER2_BSE) {
D 96
#ifndef NOBADSECT
E 96
			if (upecc(ui, BSE))
				return;
			else
D 96
#endif
E 96
				goto hard;
E 92
I 90
		} else if (upaddr->uper2 & UPER2_BSE) {
#ifndef NOBADSECT
			if (upecc(ui, BSE))
				return;
			else
#endif
				goto hard;
E 90
		} else {
			/*
			 * Retriable error.
			 * If a soft ecc, correct it (continuing
			 * by returning if necessary.
			 * Otherwise fall through and retry the transfer
			 */
D 84
D 90
			um->um_tab.b_active = 0;	 /* force retry */
E 51
D 49
			if ((upaddr->uper1&(DCK|ECH))==DCK && upecc(ui))
E 42
				return;
D 42
			/*
			 * Clear the drive and, every 4 retries, recalibrate
			 * to hopefully help clear up seek positioning problems.
			 */
E 42
E 2
			upaddr->upcs1 = TRE|IE|DCLR|GO;
E 49
I 49
D 65
			if ((upaddr->uper1&(UP_DCK|UP_ECH))==UP_DCK)
E 65
I 65
			if ((upaddr->uper1&(UPER1_DCK|UPER1_ECH))==UPER1_DCK)
E 84
I 84
			if ((upaddr->uper1&(UPER1_DCK|UPER1_ECH))==UPER1_DCK) {
E 84
E 65
D 92
				if (upecc(ui))
E 92
I 92
				if (upecc(ui, ECC))
E 92
E 90
I 90
			if ((upaddr->uper1&(UPER1_DCK|UPER1_ECH))==UPER1_DCK) {
				if (upecc(ui, ECC))
E 90
					return;
I 90
			} else
				um->um_tab.b_active = 0; /* force retry */
E 90
I 84
			} else
				um->um_tab.b_active = 0; /* force retry */
E 84
D 51
			upaddr->upcs1 = UP_TRE|UP_IE|UP_DCLR|UP_GO;
E 51
I 51
		}
		/*
		 * Clear drive error and, every eight attempts,
		 * (starting with the fourth)
		 * recalibrate to clear the slate.
		 */
		upaddr->upcs1 = UP_TRE|UP_IE|UP_DCLR|UP_GO;
		needie = 0;
D 63
		if ((um->um_tab.b_errcnt&07) == 4) {
E 63
I 63
		if ((um->um_tab.b_errcnt&07) == 4 && um->um_tab.b_active == 0) {
E 63
			upaddr->upcs1 = UP_RECAL|UP_IE|UP_GO;
D 62
			um->um_tab.b_active = 1;
			sc->sc_recal = 1;
			return;
E 62
I 62
			sc->sc_recal = 0;
			goto nextrecal;
E 62
		}
	}
	/*
D 62
	 * Done retrying transfer... release
	 * resources... if we were recalibrating,
	 * then retry the transfer.
	 * Mathematical note: 28%8 != 4.
E 62
I 62
	 * Advance recalibration finite state machine
	 * if recalibrate in progress, through
	 *	RECAL
	 *	SEEK
	 *	OFFSET (optional)
	 *	RETRY
E 62
	 */
D 62
	ubadone(um);
	if (sc->sc_recal) {
E 62
I 62
	switch (sc->sc_recal) {

	case 1:
		upaddr->updc = bp->b_cylin;
		upaddr->upcs1 = UP_SEEK|UP_IE|UP_GO;
		goto nextrecal;
	case 2:
		if (um->um_tab.b_errcnt < 16 || (bp->b_flags&B_READ) == 0)
			goto donerecal;
D 65
		upaddr->upof = up_offset[um->um_tab.b_errcnt & 017] | UP_FMT22;
E 65
I 65
		upaddr->upof = up_offset[um->um_tab.b_errcnt & 017] | UPOF_FMT22;
E 65
		upaddr->upcs1 = UP_IE|UP_OFFSET|UP_GO;
		goto nextrecal;
	nextrecal:
		sc->sc_recal++;
		um->um_tab.b_active = 1;
		return;
	donerecal:
	case 3:
E 62
		sc->sc_recal = 0;
D 62
		um->um_tab.b_active = 0;	/* force retry */
E 62
I 62
		um->um_tab.b_active = 0;
		break;
E 62
	}
	/*
	 * If still ``active'', then don't need any more retries.
	 */
	if (um->um_tab.b_active) {
		/*
		 * If we were offset positioning,
		 * return to centerline.
		 */
		if (um->um_tab.b_errcnt >= 16) {
D 65
			upaddr->upof = UP_FMT22;
E 65
I 65
			upaddr->upof = UPOF_FMT22;
E 65
			upaddr->upcs1 = UP_RTC|UP_GO|UP_IE;
D 65
			while (upaddr->upds & UP_PIP)
E 65
I 65
			while (upaddr->upds & UPDS_PIP)
E 65
				DELAY(25);
E 51
E 49
D 29
			DELAY(idelay);
E 29
I 4
			needie = 0;
E 4
D 2
			if((uptab.b_errcnt&07) == 4) {
E 2
I 2
D 42
			if ((uptab.b_errcnt&07) == 4) {
E 42
I 42
D 51
			if ((um->um_tab.b_errcnt&07) == 4) {
E 42
E 2
D 49
				upaddr->upcs1 = RECAL|GO|IE;
D 29
				DELAY(idelay);
E 29
				while(upaddr->upds & PIP)
E 49
I 49
				upaddr->upcs1 = UP_RECAL|UP_IE|UP_GO;
				while(upaddr->upds & UP_PIP)
E 49
					DELAY(25);
			}
I 33
D 42
			if (uptab.b_errcnt == 28 && cs2&(NEM|MXF)) {
E 42
I 42
D 49
			if (um->um_tab.b_errcnt == 28 && cs2&(NEM|MXF)) {
E 49
I 49
			if (um->um_tab.b_errcnt == 28 && cs2&(UP_NEM|UP_MXF)) {
E 49
E 42
				printf("FLAKEY UP ");
D 42
				ubareset();
E 42
I 42
				ubareset(um->um_ubanum);
E 42
				return;
			}
E 51
E 33
		}
I 46
D 48
		ubarelse(ui->ui_ubanum, &um->um_ubinfo);
E 48
I 48
D 51
		ubadone(um);
E 48
E 46
D 2
		if(uptab.b_active) {
			if(uptab.b_errcnt) {
				upaddr->upcs1 = RTC|GO;
E 2
I 2
D 42
		/*
		 * If we are still noted as active, then no
		 * (further) retries are necessary.  
		 *
		 * Make sure the correct unit is selected,
		 * return it to centerline if necessary, and mark
		 * this i/o complete, starting the next transfer
		 * on this drive with the upustart routine (if any).
		 */
		if (uptab.b_active) {
I 8
D 9
#ifdef UTRACE
D(21)			trace(" unit %d", unit);
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
			trace(" unit %d", unit);
E 6
I 6
D(21)			trace(" unit %d", unit);
E 6
#endif
E 7
E 5
D 12
			if ((upaddr->upcs2 & 07) != unit) {
I 8
D 9
#ifdef UTRACE
D(22)				trace(" select");
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
				trace(" select");
E 6
I 6
D(22)				trace(" select");
E 6
#endif
E 7
E 5
				upaddr->upcs2 = unit;
				DELAY(sdelay);
				nwaitcs2++;
			} else
				neasycs2++;
E 12
			if (uptab.b_errcnt >= 16) {
E 42
I 42
		if (um->um_tab.b_active) {
			if (um->um_tab.b_errcnt >= 16) {
E 42
I 8
D 9
#ifdef UTRACE
D(23)				trace(" rtc");
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
				trace(" rtc");
E 6
I 6
D(23)				trace(" rtc");
E 6
#endif
E 7
E 5
D 49
				upaddr->upcs1 = RTC|GO|IE;
E 2
D 29
				DELAY(idelay);
E 29
D 2
				while(upaddr->upds & PIP)
E 2
I 2
				while (upaddr->upds & PIP)
E 49
I 49
				upaddr->upcs1 = UP_RTC|UP_GO|UP_IE;
				while (upaddr->upds & UP_PIP)
E 49
E 2
					DELAY(25);
E 51
I 51
		um->um_tab.b_active = 0;
		um->um_tab.b_errcnt = 0;
		um->um_tab.b_actf = dp->b_forw;
		dp->b_active = 0;
		dp->b_errcnt = 0;
		dp->b_actf = bp->av_forw;
		bp->b_resid = (-upaddr->upwc * sizeof(short));
		iodone(bp);
		/*
		 * If this unit has more work to do,
		 * then start it up right away.
		 */
		if (dp->b_actf)
			if (upustart(ui))
E 51
I 4
				needie = 0;
E 4
D 51
			}
D 42
			uptab.b_active = 0;
			uptab.b_errcnt = 0;
			uptab.b_actf = dp->b_forw;
E 42
I 42
			um->um_tab.b_active = 0;
			um->um_tab.b_errcnt = 0;
			um->um_tab.b_actf = dp->b_forw;
E 42
			dp->b_active = 0;
			dp->b_errcnt = 0;
			dp->b_actf = bp->av_forw;
D 2
			bp->b_resid = (-upaddr->upwc * 2);
E 2
I 2
			bp->b_resid = (-upaddr->upwc * sizeof(short));
I 45
D 47
			/* CHECK FOR WRITE LOCK HERE... */
E 45
I 11
			if (bp->b_resid)
D 16
				printf("resid %d ds %o er? %o %o %o\n", bp->b_resid, upaddr->upds,
E 16
I 16
				printf("resid %d ds %o er? %o %o %o\n",
				    bp->b_resid, upaddr->upds,
E 16
				    upaddr->uper1, upaddr->uper2, upaddr->uper3);
E 47
E 11
D 3
			if (cs1del&2) DELAY(500);
E 3
D 4
			upaddr->upcs1 = IE;
E 4
D 3
			if (cs1del&2) DELAY(500);
E 3
E 2
			iodone(bp);
D 42
			if(dp->b_actf)
D 4
				upustart(unit);
E 4
I 4
				if (upustart(unit))
E 42
I 42
			if (dp->b_actf)
				if (upustart(ui))
E 42
					needie = 0;
E 4
		}
D 42
		as &= ~(1<<unit);
I 8
D 16
		softas &= ~(1<<unit);
E 16
I 16
		upsoftas &= ~(1<<unit);
E 16
E 8
D 38
		ubafree(up_ubinfo), up_ubinfo = 0;
E 38
I 38
D 39
		UBAFREECLR(up_ubinfo);
E 39
I 39
		ubarelse(&up_ubinfo);
E 42
I 42
D 44
		up_softc[um->um_num].sc_softas &= ~(1<<ui->ui_slave);
D 43
		ubarelse(&up_softc[um->um_num].sc_info);
E 43
I 43
		ubarelse(ui->ui_ubanum, &up_softc[um->um_num].sc_info);
E 44
I 44
D 45
		up_softc[um->um_ctlr].sc_softas &= ~(1<<ui->ui_slave);
		ubarelse(ui->ui_ubanum, &up_softc[um->um_ctlr].sc_info);
E 45
I 45
D 47
		sc->sc_softas &= ~(1<<ui->ui_slave);
E 47
I 47
		as &= ~(1<<ui->ui_slave);
E 47
D 46
		ubarelse(ui->ui_ubanum, &sc->sc_info);
E 46
E 45
E 44
E 43
E 42
E 39
E 38
D 2
	} else {
E 2
I 2
D 9
	}
#ifndef notdef
	else {
E 9
I 9
	} else {
E 9
D 5
		if (printsw&64) printf("cs1 %o\n", upaddr->upcs1);
E 5
E 2
D 29
		if (upaddr->upcs1 & TRE) {
E 29
I 29
D 49
		if (upaddr->upcs1 & TRE)
E 29
I 8
D 9
#ifdef UTRACE
D(24)			trace(" TRE");
#endif
E 9
E 8
I 3
D 5
			printf("TRE in upintr: cs1 %o\n", upaddr->upcs1);
printf("as=%d act %d %d %d\n", as, uptab.b_active, uputab[0].b_active, uputab[1].b_active);
E 5
I 5
D 7
#ifdef UTRACE
D 6
			trace(" TRE");
E 6
I 6
D(24)			trace(" TRE");
E 6
#endif
E 7
E 5
E 3
			upaddr->upcs1 = TRE;
E 49
I 49
		if (upaddr->upcs1 & UP_TRE)
			upaddr->upcs1 = UP_TRE;
E 51
E 49
D 29
			DELAY(idelay);
I 2
D 5
			if (printsw&64) printf("after TRE cs1 %o\n", upaddr->upcs1);
E 5
E 2
		}
E 29
D 2
		if (slow4) DELAY(idelay);
		if(as == 0)
			upaddr->upcs1 = IE;
		if (slow4) DELAY(idelay);
E 2
	}
I 51
	as &= ~(1<<ui->ui_slave);
I 64
	/*
	 * Release unibus resources and flush data paths.
	 */
	ubadone(um);
E 64
doattn:
	/*
	 * Process other units which need attention.
	 * For each unit which needs attention, call
	 * the unit start routine to place the slave
	 * on the controller device queue.
	 */
E 51
D 2
	for(unit=0; unit<NUP; unit++)
		if(as & (1<<unit))
			upustart(unit);
	upstart();
E 2
I 2
D 9
#endif
E 9
D 42
	/*
	 * If we have a unit with an outstanding SEARCH,
	 * and the hardware indicates the unit requires attention,
	 * the bring the drive to the ready queue.
	 * Finally, if the controller is not transferring
	 * start it if any drives are now ready to transfer.
	 */
I 8
D 9
#ifdef UTRACE
D(25)	trace("\n");
#endif
E 9
D 16
	as |= softas;
	osoftas = softas;
	softas = 0;
E 16
I 16
	as |= upsoftas;
	oupsoftas = upsoftas;
	upsoftas = 0;
E 16
E 8
I 5
D 7
#ifdef UTRACE
D 6
	trace("\n");
E 6
I 6
D(25)	trace("\n");
E 6
#endif
E 7
E 5
	for (unit = 0; unit < NUP; unit++)
D 8
		if (as & (1<<unit))
E 8
I 8
D 9
		if ((as|osoftas) & (1<<unit))
/*
E 8
D 3
			if (uputab[unit].b_active == 1)
E 3
I 3
			if (uputab[unit].b_active == 1) {
I 8
*/
			{
				if (as & (1<<unit)) {
E 9
I 9
D 16
		if ((as|osoftas) & (1<<unit)) {
E 16
I 16
		if ((as|oupsoftas) & (1<<unit)) {
E 42
I 42
D 44
	as |= up_softc[um->um_num].sc_softas;
E 44
I 44
D 45
	as |= up_softc[um->um_ctlr].sc_softas;
E 45
I 45
D 47
	as |= sc->sc_softas;
	sc->sc_softas = 0;
E 45
E 44
	for (unit = 0; unit < NUP; unit++) {
		if ((ui = updinfo[unit]) == 0 || ui->ui_mi != um)
			continue;
		if (as & (1<<unit)) {
E 47
I 47
D 62
	for (unit = 0; as; as >>= 1, unit++)
		if (as & 1) {
E 47
E 42
E 16
D 29
			if (as & (1<<unit)) {
E 29
I 29
D 45
			if (as & (1<<unit))
E 29
E 9
E 8
				upaddr->upas = 1<<unit;
E 45
I 45
			upaddr->upas = 1<<unit;
E 45
I 8
D 9
#ifdef UTRACE
D(26)				trace("as clear %d\n", unit);
#endif
E 9
E 8
I 5
D 7
#ifdef UTRACE
D 6
				trace("as clear %d\n", unit);
E 6
I 6
D(26)				trace("as clear %d\n", unit);
E 6
#endif
E 7
E 5
E 3
D 4
				upustart(unit);
E 4
I 4
D 16
				if (asdel) DELAY(asdel);
E 16
I 16
D 18
#ifdef OLDUCODE
				DELAY(asdel);
#endif
E 18
I 18
D 29
				if (olducode)
					DELAY(oasdel);
E 18
E 16
I 8
D 9
				}
E 8
				if (upustart(unit))
					needie = 0;
E 9
I 8
			}
E 29
D 9
/*
E 8
E 4
D 3
			else {
E 3
I 3
			} else {
D 5
			printf("as in upintr: cs1 %o\n", upaddr->upcs1);
printf("as=%d act %d %d %d\n", as, uptab.b_active, uputab[0].b_active, uputab[1].b_active);
E 5
E 3
				upaddr->upas = 1<<unit;
I 8
#ifdef UTRACE
D(27)				trace("spurious as clear %d\n", unit);
#endif
E 8
I 5
D 7
#ifdef UTRACE
D 6
				trace("spurious as clear %d\n", unit);
E 6
I 6
D(27)				trace("spurious as clear %d\n", unit);
E 6
#endif
E 7
E 5
				DELAY(1000);
			}
I 8
*/
E 9
I 9
D 42
			if (upustart(unit))
E 42
I 42
D 47
			if (upustart(ui))
E 47
I 47
			if (upustart(upip[sc21][unit]))
E 47
E 42
				needie = 0;
		}
E 62
I 62
D 120
	while (unit = ffs(as)) {
E 120
I 120
	while (unit = ffs((long)as)) {
E 120
		unit--;		/* was 1 origin */
		as &= ~(1<<unit);
		upaddr->upas = 1<<unit;
D 74
		if (upustart(upip[sc21][unit]))
E 74
I 74
		if (unit < UPIPUNITS && upustart(upip[sc21][unit]))
E 74
			needie = 0;
	}
E 62
I 51
	/*
	 * If the controller is not transferring, but
	 * there are devices ready to transfer, start
	 * the controller.
	 */
E 51
E 9
E 8
D 42
	if (uptab.b_actf && uptab.b_active == 0)
D 4
		upstart();
E 4
I 4
		if (upstart())
E 42
I 42
D 47
	}
E 47
	if (um->um_tab.b_actf && um->um_tab.b_active == 0)
		if (upstart(um))
E 42
			needie = 0;
E 4
D 31
out:
E 31
D 3
	if (cs1del&4) DELAY(500);
E 3
D 4
	if ((upaddr->upcs1&IE) == 0)
E 4
I 4
D 5
	if (needie)
E 5
I 5
D 11
	if (needie) {
E 11
I 11
	if (needie)
E 11
I 8
D 9
#ifdef UTRACE
D(28)		trace("upintr set IE\n");
#endif
E 9
E 8
D 7
#ifdef UTRACE
D 6
		trace("upintr set IE\n");
E 6
I 6
D(28)		trace("upintr set IE\n");
E 6
#endif
E 7
E 5
E 4
D 49
		upaddr->upcs1 = IE;
E 49
I 49
		upaddr->upcs1 = UP_IE;
E 49
D 3
	if (cs1del&4) DELAY(500);
E 3
D 5
	if (printsw&128) printf("exit cs1 %o\n", upaddr->upcs1);
E 5
I 5
D 11
	}
E 11
E 5
E 2
D 124
}

D 86
upread(dev)
E 86
I 86
upread(dev, uio)
E 86
I 48
	dev_t dev;
I 86
	struct uio *uio;
E 86
E 48
{
I 48
D 117
	register int unit = minor(dev) >> 3;
E 117
I 117
	register int unit = upunit(dev);
E 117
E 48
I 45

E 45
D 42

E 42
D 48
	physio(upstrategy, &rupbuf, dev, B_READ, minphys);
E 48
I 48
	if (unit >= NUP)
D 88
		u.u_error = ENXIO;
	else
D 86
		physio(upstrategy, &rupbuf[unit], dev, B_READ, minphys);
E 86
I 86
		physio(upstrategy, &rupbuf[unit], dev, B_READ, minphys, uio);
E 88
I 88
		return (ENXIO);
	return (physio(upstrategy, &rupbuf[unit], dev, B_READ, minphys, uio));
E 88
E 86
E 48
}

D 87
upwrite(dev)
E 87
I 87
upwrite(dev, uio)
E 87
I 48
	dev_t dev;
I 87
	struct uio *uio;
E 87
E 48
{
I 48
D 117
	register int unit = minor(dev) >> 3;
E 117
I 117
	register int unit = upunit(dev);
E 117
E 48
I 45

E 45
D 42

E 42
D 48
	physio(upstrategy, &rupbuf, dev, B_WRITE, minphys);
E 48
I 48
	if (unit >= NUP)
D 88
		u.u_error = ENXIO;
	else
D 86
		physio(upstrategy, &rupbuf[unit], dev, B_WRITE, minphys);
E 86
I 86
D 87
		physio(upstrategy, &rupbuf[unit], dev, B_WRITE, minphys, 0);
E 87
I 87
		physio(upstrategy, &rupbuf[unit], dev, B_WRITE, minphys, uio);
E 88
I 88
		return (ENXIO);
	return (physio(upstrategy, &rupbuf[unit], dev, B_WRITE, minphys, uio));
E 124
E 88
E 87
E 86
E 48
}

I 2
/*
 * Correct an ECC error, and restart the i/o to complete
 * the transfer if necessary.  This is quite complicated because
 * the transfer may be going to an odd memory address base and/or
 * across a page boundary.
 */
E 2
D 42
upecc(up, bp)
register struct device *up;
register struct buf *bp;
E 42
I 42
D 90
D 92
upecc(ui)
E 92
I 92
upecc(ui, flag)
E 92
E 90
I 90
upecc(ui, flag)
E 90
D 59
	register struct uba_dinfo *ui;
E 59
I 59
	register struct uba_device *ui;
I 92
	int flag;
E 92
I 90
	int flag;
E 90
E 59
E 42
{
D 42
	struct uba_regs *ubp = (struct uba_regs *)UBA0;
E 42
I 42
D 49
	register struct device *up = (struct device *)ui->ui_addr;
E 49
I 49
	register struct updevice *up = (struct updevice *)ui->ui_addr;
E 49
	register struct buf *bp = uputab[ui->ui_unit].b_actf;
D 59
	register struct uba_minfo *um = ui->ui_mi;
E 59
I 59
	register struct uba_ctlr *um = ui->ui_mi;
E 59
	register struct upst *st;
I 45
D 47
	struct up_softc *sc = &up_softc[um->um_ctlr];
E 47
E 45
	struct uba_regs *ubp = ui->ui_hd->uh_uba;
E 42
D 2
	register int i, off;
E 2
I 2
	register int i;
E 2
	caddr_t addr;
D 2
	int reg, bit, byte, npf, mask, o;
	extern char buffers[NBUF][BSIZE];
E 2
I 2
	int reg, bit, byte, npf, mask, o, cmd, ubaddr;
E 2
	int bn, cn, tn, sn;

D 5
	if (printsw&8) printf("upecc\n");
E 5
	/*
D 2
	 * Npf is number of page frames (= disk blocks) completed before ecc.
E 2
I 2
	 * Npf is the number of sectors transferred before the sector
	 * containing the ECC error, and reg is the UBA register
	 * mapping (the first part of) the transfer.
	 * O is offset within a memory page of the first byte transferred.
E 2
	 */
D 2
	npf = btop((UPADDR->upwc * sizeof(short)) + bp->b_bcount) - 1;
	reg = btop(up_ubinfo&0xffff) + npf;
E 2
I 2
D 90
D 92
	npf = btop((up->upwc * sizeof(short)) + bp->b_bcount) - 1;
E 92
I 92
D 96
#ifndef NOBADSECT
E 96
	if (flag == CONT)
		npf = bp->b_error;
	else
D 96
#endif
	npf = btop((up->upwc * sizeof(short)) + bp->b_bcount);
E 96
I 96
D 121
		npf = btop((up->upwc * sizeof(short)) + bp->b_bcount);
E 121
I 121
		npf = btodb(bp->b_bcount + (up->upwc * sizeof(short)) + 511);
E 121
E 96
E 92
E 90
I 90
#ifndef NOBADSECT
	if (flag == CONT)
		npf = bp->b_error;
	else
#endif
	npf = btop((up->upwc * sizeof(short)) + bp->b_bcount);
E 90
D 42
	reg = btop(up_ubinfo&0x3ffff) + npf;
E 42
I 42
D 44
	reg = btop(up_softc[um->um_num].sc_info&0x3ffff) + npf;
E 44
I 44
D 45
	reg = btop(up_softc[um->um_ctlr].sc_info&0x3ffff) + npf;
E 45
I 45
D 46
	reg = btop(sc->sc_info&0x3ffff) + npf;
E 46
I 46
D 127
	reg = btop(um->um_ubinfo&0x3ffff) + npf;
E 127
I 127
	reg = btop(UBAI_ADDR(um->um_ubinfo)) + npf;
E 127
E 46
E 45
E 44
E 42
E 2
	o = (int)bp->b_un.b_addr & PGOFSET;
D 57
	printf("%D ", bp->b_blkno+npf);
	prdev("ECC", bp->b_dev);
E 57
I 57
D 58
	printf("SOFT ECC up%d%c bn%d\n", dkunit(bp),
E 58
I 58
D 59
	printf("up%d%c: soft ecc bn%d\n", dkunit(bp),
E 59
I 59
D 95
	printf("up%d%c: soft ecc sn%d\n", dkunit(bp),
E 59
E 58
	    'a'+(minor(bp->b_dev)&07), bp->b_blkno + npf);
E 95
E 57
	mask = up->upec2;
I 65
#ifdef UPECCDEBUG
E 65
I 64
	printf("npf %d reg %x o %d mask %o pos %d\n", npf, reg, o, mask,
	    up->upec1);
I 65
#endif
E 65
E 64
D 56
	if (mask == 0) {
D 2
		up->upof = FMT22;
E 2
I 2
D 49
		up->upof = FMT22;		/* == RTC ???? */
E 49
I 49
		up->upof = UP_FMT22;		/* == RTC ???? */
E 49
E 2
D 29
		DELAY(idelay);
E 29
		return (0);
	}
E 56
D 2
	i = up->upec1 - 1;
	bit = i&017;
	i = (i&~017)>>3;
E 2
I 2
D 90
D 92
	/*
	 * Flush the buffered data path, and compute the
	 * byte and bit position of the error.  The variable i
	 * is the byte offset in the transfer, the variable byte
	 * is the offset from a page boundary in main memory.
	 */
E 92
I 92
D 117
	bn = dkblock(bp);
E 117
I 117
	bn = bp->b_blkno;
E 117
	st = &upst[ui->ui_type];
	cn = bp->b_cylin;
	sn = bn%st->nspc + npf;
	tn = sn/st->nsect;
	sn %= st->nsect;
	cn += tn/st->ntrak;
	tn %= st->ntrak;
E 92
E 90
I 90
	bn = dkblock(bp);
	st = &upst[ui->ui_type];
	cn = bp->b_cylin;
	sn = bn%st->nspc + npf;
	tn = sn/st->nsect;
	sn %= st->nsect;
	cn += tn/st->ntrak;
	tn %= st->ntrak;
E 90
D 42
	ubp->uba_dpr[(up_ubinfo>>28)&0x0f] |= BNE;
E 42
I 42
D 44
	ubp->uba_dpr[(up_softc[um->um_num].sc_info>>28)&0x0f] |= UBA_BNE;
E 44
I 44
D 45
	ubp->uba_dpr[(up_softc[um->um_ctlr].sc_info>>28)&0x0f] |= UBA_BNE;
E 45
I 45
D 46
	ubp->uba_dpr[(sc->sc_info>>28)&0x0f] |= UBA_BNE;
E 46
I 46
D 54
	ubp->uba_dpr[(um->um_ubinfo>>28)&0x0f] |= UBA_BNE;
E 54
I 54
	ubapurge(um);
E 54
E 46
E 45
E 44
E 42
D 90
D 92
	i = up->upec1 - 1;		/* -1 makes 0 origin */
	bit = i&07;
	i = (i&~07)>>3;
E 2
	byte = i + o;
E 92
I 92
	um->um_tab.b_active=2;
E 92
E 90
I 90
	um->um_tab.b_active=2;
E 90
D 2
	if (byte & 1) {
		byte--;
		bit += 8;
E 2
I 2
	/*
D 90
D 92
	 * Correct while possible bits remain of mask.  Since mask
	 * contains 11 bits, we continue while the bit offset is > -11.
	 * Also watch out for end of this block and the end of the whole
	 * transfer.
E 92
I 92
	 * action taken depends on the flag
E 92
E 90
I 90
	 * action taken depends on the flag
E 90
	 */
D 90
D 92
	while (i < 512 && (int)ptob(npf)+i < bp->b_bcount && bit > -11) {
		addr = ptob(ubp->uba_map[reg+btop(byte)].pg_pfnum)+
		    (byte & PGOFSET);
E 92
I 92
	switch(flag){
	case ECC:
		npf--;
		reg--;
		mask = up->upec2;
D 113
		printf("up%d%c: soft ecc sn%d\n", dkunit(bp),
E 113
I 113
D 117
		log(KERN_RECOV, "up%d%c: soft ecc sn%d\n", dkunit(bp),
E 117
I 117
D 119
		log(KERN_RECOV, "up%d%c: soft ecc sn%d\n", upunit(bp->b_dev),
E 119
I 119
D 125
		log(LOG_WARNING, "up%d%c: soft ecc sn%d\n", upunit(bp->b_dev),
E 119
E 117
E 113
			'a'+(minor(bp->b_dev)&07), bp->b_blkno + npf);
E 125
I 125
		diskerr(bp, "up", "soft ecc", LOG_WARNING, npf,
		    (struct disklabel *)0);
		addlog("\n");
E 125
		/*
		 * Flush the buffered data path, and compute the
		 * byte and bit position of the error.  The variable i
		 * is the byte offset in the transfer, the variable byte
		 * is the offset from a page boundary in main memory.
		 */
		i = up->upec1 - 1;		/* -1 makes 0 origin */
		bit = i&07;
		i = (i&~07)>>3;
		byte = i + o;
		/*
		 * Correct while possible bits remain of mask.  Since mask
		 * contains 11 bits, we continue while the bit offset is > -11.
		 * Also watch out for end of this block and the end of the whole
		 * transfer.
		 */
D 121
		while (i < 512 && (int)ptob(npf)+i < bp->b_bcount && bit > -11) {
E 121
I 121
		while (i < 512 && (int)dbtob(npf)+i < bp->b_bcount && bit > -11) {
E 121
D 109
			addr = ptob(ubp->uba_map[reg+btop(byte)].pg_pfnum)+
				(byte & PGOFSET);
E 109
I 109
			struct pte pte;

			pte = ubp->uba_map[reg + btop(byte)];
			addr = ptob(pte.pg_pfnum) + (byte & PGOFSET);
E 109
E 92
E 90
I 90
	switch(flag){
	case ECC:
		npf--;
		reg--;
		mask = up->upec2;
		printf("up%d%c: soft ecc sn%d\n", dkunit(bp),
			'a'+(minor(bp->b_dev)&07), bp->b_blkno + npf);
		/*
		 * Flush the buffered data path, and compute the
		 * byte and bit position of the error.  The variable i
		 * is the byte offset in the transfer, the variable byte
		 * is the offset from a page boundary in main memory.
		 */
		i = up->upec1 - 1;		/* -1 makes 0 origin */
		bit = i&07;
		i = (i&~07)>>3;
		byte = i + o;
		/*
		 * Correct while possible bits remain of mask.  Since mask
		 * contains 11 bits, we continue while the bit offset is > -11.
		 * Also watch out for end of this block and the end of the whole
		 * transfer.
		 */
		while (i < 512 && (int)ptob(npf)+i < bp->b_bcount && bit > -11) {
			addr = ptob(ubp->uba_map[reg+btop(byte)].pg_pfnum)+
				(byte & PGOFSET);
E 90
I 65
#ifdef UPECCDEBUG
E 65
I 64
D 90
D 92
		printf("addr %x map reg %x\n",
		    addr, *(int *)(&ubp->uba_map[reg+btop(byte)]));
		printf("old: %x, ", getmemc(addr));
E 92
I 92
			printf("addr %x map reg %x\n",
				addr, *(int *)(&ubp->uba_map[reg+btop(byte)]));
			printf("old: %x, ", getmemc(addr));
E 92
E 90
I 90
			printf("addr %x map reg %x\n",
				addr, *(int *)(&ubp->uba_map[reg+btop(byte)]));
			printf("old: %x, ", getmemc(addr));
E 90
I 65
#endif
E 65
E 64
D 90
D 92
		putmemc(addr, getmemc(addr)^(mask<<bit));
E 92
I 92
			putmemc(addr, getmemc(addr)^(mask<<bit));
E 92
E 90
I 90
			putmemc(addr, getmemc(addr)^(mask<<bit));
E 90
I 65
#ifdef UPECCDEBUG
E 65
I 64
D 90
D 92
		printf("new: %x\n", getmemc(addr));
E 92
I 92
			printf("new: %x\n", getmemc(addr));
E 92
E 90
I 90
			printf("new: %x\n", getmemc(addr));
E 90
I 65
#endif
E 65
E 64
D 90
D 92
		byte++;
		i++;
		bit -= 8;
E 92
I 92
			byte++;
			i++;
I 93
			bit -= 8;
E 93
		}
		if (up->upwc == 0)
			return (0);
		npf++;
		reg++;
		break;
D 96
#ifndef NOBADSECT
E 96
	case BSE:
		/*
		 * if not in bad sector table, return 0
		 */
		if ((bn = isbad(&upbad[ui->ui_unit], cn, tn, sn)) < 0)
			return(0);
		/*
		 * flag this one as bad
		 */
		bp->b_flags |= B_BAD;
		bp->b_error = npf + 1;
#ifdef UPECCDEBUG
		printf("BSE: restart at %d\n",npf+1);
#endif
		bn = st->ncyl * st->nspc -st->nsect - 1 - bn;
		cn = bn / st->nspc;
		sn = bn % st->nspc;
		tn = sn / st->nsect;
		sn %= st->nsect;
		up->upwc = -(512 / sizeof (short));
#ifdef UPECCDEBUG
		printf("revector to cn %d tn %d sn %d\n", cn, tn, sn);
#endif
		break;
	case CONT:
#ifdef UPECCDEBUG
		printf("upecc, CONT: bn %d cn %d tn %d sn %d\n", bn, cn, tn, sn);
#endif
		bp->b_flags &= ~B_BAD;
D 121
		up->upwc = -((bp->b_bcount - (int)ptob(npf)) / sizeof(short));
		if (up->upwc == 0)
			return(0);
E 121
I 121
		if ((int)dbtob(npf) >= bp->b_bcount)
			return (0);
		up->upwc = -((bp->b_bcount - (int)dbtob(npf)) / sizeof(short));
E 121
		break;
D 96
#endif
E 96
E 92
E 90
I 90
			byte++;
			i++;
		}
		if (up->upwc == 0)
			return (0);
		npf++;
		reg++;
		break;
#ifndef NOBADSECT
	case BSE:
		/*
		 * if not in bad sector table, return 0
		 */
		if ((bn = isbad(&upbad[ui->ui_unit], cn, tn, sn)) < 0)
			return(0);
		/*
		 * flag this one as bad
		 */
		bp->b_flags |= B_BAD;
		bp->b_error = npf + 1;
#ifdef UPECCDEBUG
		printf("BSE: restart at %d\n",npf+1);
#endif
		bn = st->ncyl * st->nspc -st->nsect - 1 - bn;
		cn = bn / st->nspc;
		sn = bn % st->nspc;
		tn = sn / st->nsect;
		sn %= st->nsect;
		up->upwc = -(512 / sizeof (short));
#ifdef UPECCDEBUG
		printf("revector to cn %d tn %d sn %d\n", cn, tn, sn);
#endif
		break;
	case CONT:
#ifdef UPECCDEBUG
		printf("upecc, CONT: bn %d cn %d tn %d sn %d\n", bn, cn, tn, sn);
#endif
		bp->b_flags &= ~B_BAD;
		up->upwc = -((bp->b_bcount - (int)ptob(npf)) / sizeof(short));
		if (up->upwc == 0)
			return(0);
		break;
#endif
E 90
E 2
	}
D 2
	i += (int)ptob(reg);
	for (off = 0; off <= 32; off += 16) {
		if (i <= bp->b_bcount) {
			addr = ptob(ubp->uba_map[reg+btop(byte)].pg_pfnum)+
			    (byte & PGOFSET);
			putmemw(addr, getmemw(addr)^(mask<<bit));
		}
		byte += sizeof (short);
		i += sizeof (short);
		bit -= 16;
	}
	uptab.b_active++;
E 2
I 2
D 42
	uptab.b_active++;	/* Either complete or continuing... */
E 42
I 42
D 73
	um->um_tab.b_active++;	/* Either complete or continuing... */
E 73
I 73
D 82
D 90
	um->um_tab.b_active = 2;	/* Either complete or continuing... */
E 82
E 73
E 42
E 2
D 84
	if (up->upwc == 0)
E 90
I 90
	if (up->upwc == 0) {
		um->um_tab.b_active = 0;
E 90
E 84
I 84
	if (up->upwc == 0) {
		um->um_tab.b_active = 0;
E 84
		return (0);
I 90
	}
E 90
I 84
	}
E 84
D 2
	up->upcs1 = DCLR|GO;
E 2
I 2
	/*
	 * Have to continue the transfer... clear the drive,
	 * and compute the position where the transfer is to continue.
	 * We have completed npf+1 sectors of the transfer already;
	 * restart at offset o of next sector (i.e. in UBA register reg+1).
	 */
D 49
	up->upcs1 = TRE|IE|DCLR|GO;
E 49
I 49
#ifdef notdef
	up->uper1 = 0;
	up->upcs1 |= UP_GO;
#else
	up->upcs1 = UP_TRE|UP_IE|UP_DCLR|UP_GO;
E 49
E 2
D 29
	DELAY(idelay);
E 29
D 90
D 92
	bn = dkblock(bp);
I 42
	st = &upst[ui->ui_type];
E 42
	cn = bp->b_cylin;
D 2
	sn = bn%(NSECT*NTRAC);
E 2
I 2
D 42
	sn = bn%(NSECT*NTRAC) + npf + 1;
E 2
	tn = sn/NSECT;
	sn %= NSECT;
D 2
	sn += npf + 1;
	cn += sn/NSECT;
	sn %= NSECT;
E 2
I 2
	cn += tn/NTRAC;
	tn %= NTRAC;
E 42
I 42
	sn = bn%st->nspc + npf + 1;
	tn = sn/st->nsect;
	sn %= st->nsect;
	cn += tn/st->ntrak;
	tn %= st->ntrak;
E 92
E 90
E 42
E 2
	up->updc = cn;
D 2
	up->upda = ((i/NSECT)<<8) + (i%NSECT);
	up->upba = (int)ptob(reg+1)|((int)bp->b_un.b_addr&PGOFSET);
	up->upcs1 = IE|GO|RCOM;
E 2
I 2
	up->upda = (tn << 8) | sn;
D 90
D 92
	ubaddr = (int)ptob(reg+1) + o;
E 92
I 92
	ubaddr = (int)ptob(reg) + o;
E 92
E 90
I 90
	ubaddr = (int)ptob(reg) + o;
E 90
	up->upba = ubaddr;
	cmd = (ubaddr >> 8) & 0x300;
D 49
	cmd |= IE|GO|RCOM;
E 49
I 49
D 90
D 92
	cmd |= UP_IE|UP_GO|UP_RCOM;
E 90
I 90
	cmd |= ((bp->b_flags&B_READ)?UP_RCOM:UP_WCOM)|UP_IE|UP_GO;
	um->um_tab.b_errcnt = 0;
E 90
I 82
	um->um_tab.b_active = 2;	/* continuing transfer ... */
E 92
I 92
	cmd |= ((bp->b_flags&B_READ)?UP_RCOM:UP_WCOM)|UP_IE|UP_GO;
	um->um_tab.b_errcnt = 0;
E 92
E 82
E 49
	up->upcs1 = cmd;
I 49
#endif
E 49
E 2
	return (1);
}
I 13

/*
 * Reset driver after UBA init.
 * Cancel software state of all pending transfers
 * and restart all units and the controller.
 */
D 42
upreset()
E 42
I 42
upreset(uban)
I 58
	int uban;
E 58
E 42
{
D 42
	int unit;
E 42
I 42
D 59
	register struct uba_minfo *um;
	register struct uba_dinfo *ui;
E 59
I 59
	register struct uba_ctlr *um;
	register struct uba_device *ui;
E 59
	register sc21, unit;
I 45
D 47
	struct up_softc *sc;
E 47
E 45
I 43
D 58
	int any = 0;
E 58
E 43
E 42

I 42
D 43
	/* we should really delay the printf & DELAY till we know
	 * that there is at least one sc21 on this UBA, but then
	 * we would have to remember we had done it before, or the
	 * msg would come twice(or whatever) - but perhaps that
	 * wouldn't be such a bad thing - too many delays would
	 * be annoying however
	 */
E 42
	printf(" up");
I 33
	DELAY(15000000);		/* give it time to self-test */
E 43
E 33
D 42
	uptab.b_active = 0;
	uptab.b_actf = uptab.b_actl = 0;
D 25
	if (DK_N+NUP == DK_NMAX)
		dk_busy &= ~(1<<(DK_N+NUP));
E 25
	if (up_ubinfo) {
		printf("<%d>", (up_ubinfo>>28)&0xf);
D 38
		ubafree(up_ubinfo), up_ubinfo = 0;
E 38
I 38
D 39
		UBAFREECLR(up_ubinfo);
E 39
I 39
		ubarelse(&up_ubinfo);
E 42
I 42
D 50
	for (sc21 = 0; sc21 < NSC21; sc21++) {
E 50
I 50
	for (sc21 = 0; sc21 < NSC; sc21++) {
E 50
D 45
		if ((um = upminfo[sc21]) == 0)
E 45
I 45
		if ((um = upminfo[sc21]) == 0 || um->um_ubanum != uban ||
		    um->um_alive == 0)
E 45
			continue;
D 45
		if (um->um_ubanum != uban)
			continue;
		if (!um->um_alive)
			continue;
E 45
I 45
D 47
		sc = &up_softc[um->um_ctlr];
E 47
E 45
I 43
D 58
		if (any == 0) {
			printf(" up");
D 45
			DELAY(15000000);	/* give it time to self-test */
E 45
I 45
			DELAY(10000000);	/* give it time to self-test */
E 45
			any++;
		}
E 58
I 58
		printf(" sc%d", sc21);
E 58
E 43
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
I 58
		up_softc[sc21].sc_recal = 0;
I 73
		up_softc[sc21].sc_wticks = 0;
E 73
E 58
D 44
		if (up_softc[um->um_num].sc_info) {
			printf("<%d>", (up_softc[um->um_num].sc_info>>28)&0xf);
D 43
			ubarelse(&up_softc[um->um_num].sc_info);
E 43
I 43
			ubarelse(um->um_ubanum, &up_softc[um->um_num].sc_info);
E 44
I 44
D 45
		if (up_softc[um->um_ctlr].sc_info) {
			printf("<%d>", (up_softc[um->um_ctlr].sc_info>>28)&0xf);
			ubarelse(um->um_ubanum, &up_softc[um->um_ctlr].sc_info);
E 45
I 45
D 46
		if (sc->sc_info) {
			printf("<%d>", (sc->sc_info>>28)&0xf);
			ubarelse(um->um_ubanum, &sc->sc_info);
E 46
I 46
		if (um->um_ubinfo) {
			printf("<%d>", (um->um_ubinfo>>28)&0xf);
D 48
			ubarelse(um->um_ubanum, &um->um_ubinfo);
E 48
I 48
D 91
			ubadone(um);
E 91
I 91
			um->um_ubinfo = 0;
E 91
E 48
E 46
E 45
E 44
E 43
		}
D 49
		((struct device *)(um->um_addr))->upcs2 = CLR;
E 49
I 49
D 65
		((struct updevice *)(um->um_addr))->upcs2 = UP_CLR;
E 65
I 65
		((struct updevice *)(um->um_addr))->upcs2 = UPCS2_CLR;
E 65
E 49
		for (unit = 0; unit < NUP; unit++) {
			if ((ui = updinfo[unit]) == 0)
				continue;
D 58
			if (ui->ui_alive == 0)
E 58
I 58
			if (ui->ui_alive == 0 || ui->ui_mi != um)
E 58
				continue;
			uputab[unit].b_active = 0;
			(void) upustart(ui);
		}
		(void) upstart(um);
E 42
E 39
E 38
	}
I 15
D 42
	UPADDR->upcs2 = CLR;		/* clear controller */
D 29
	DELAY(idelay);
E 29
E 15
	for (unit = 0; unit < NUP; unit++) {
		uputab[unit].b_active = 0;
		(void) upustart(unit);
	}
	(void) upstart();
E 42
I 15
}

/*
 * Wake up every second and if an interrupt is pending
 * but nothing has happened increment a counter.
D 58
 * If nothing happens for 20 seconds, reset the controller
E 58
I 58
 * If nothing happens for 20 seconds, reset the UNIBUS
E 58
 * and begin anew.
 */
upwatch()
{
D 42
	int i;
E 42
I 42
D 59
	register struct uba_minfo *um;
E 59
I 59
	register struct uba_ctlr *um;
E 59
	register sc21, unit;
I 45
	register struct up_softc *sc;
E 45
E 42

D 31
	timeout((caddr_t)upwatch, 0, HZ);
E 31
I 31
D 55
	timeout(upwatch, (caddr_t)0, HZ);
E 55
I 55
	timeout(upwatch, (caddr_t)0, hz);
E 55
E 31
D 42
	if (uptab.b_active == 0) {
		for (i = 0; i < NUP; i++)
			if (uputab[i].b_active)
				goto active;
		up_wticks = 0;		/* idling */
		return;
E 42
I 42
D 50
	for (sc21 = 0; sc21 < NSC21; sc21++) {
E 50
I 50
	for (sc21 = 0; sc21 < NSC; sc21++) {
E 50
		um = upminfo[sc21];
I 45
		if (um == 0 || um->um_alive == 0)
			continue;
		sc = &up_softc[sc21];
E 45
		if (um->um_tab.b_active == 0) {
			for (unit = 0; unit < NUP; unit++)
D 49
				if (updinfo[unit]->ui_mi == um &&
				    uputab[unit].b_active)
E 49
I 49
				if (uputab[unit].b_active &&
				    updinfo[unit]->ui_mi == um)
E 49
					goto active;
D 45
			up_softc[sc21].sc_wticks = 0;
E 45
I 45
			sc->sc_wticks = 0;
E 45
			continue;
		}
D 58
    active:
E 58
I 58
active:
E 58
D 45
		up_softc[sc21].sc_wticks++;
		if (up_softc[sc21].sc_wticks >= 20) {
			up_softc[sc21].sc_wticks = 0;
E 45
I 45
		sc->sc_wticks++;
		if (sc->sc_wticks >= 20) {
			sc->sc_wticks = 0;
E 45
D 50
			printf("LOST INTERRUPT RESET");
I 45
			/* SHOULD JUST RESET ONE CTLR, NOT ALL ON UBA */
E 45
			upreset(um->um_ubanum);
			printf("\n");
E 50
I 50
D 58
			printf("LOST upintr ");
E 58
I 58
			printf("sc%d: lost interrupt\n", sc21);
E 58
			ubareset(um->um_ubanum);
E 50
		}
E 42
	}
D 42
active:
	up_wticks++;
	if (up_wticks >= 20) {
		up_wticks = 0;
		printf("LOST INTERRUPT RESET");
		upreset();
		printf("\n");
	}
E 42
E 15
}
I 41

#define	DBSIZE	20

updump(dev)
	dev_t dev;
{
D 49
	struct device *upaddr;
E 49
I 49
	struct updevice *upaddr;
E 49
	char *start;
D 47
	int num, blk, unit, nsect, ntrak, nspc;
E 47
I 47
D 57
	int num, blk, unit;
E 57
I 57
D 60
	int num, blk, unit, i;
E 60
I 60
	int num, blk, unit;
E 60
E 57
E 47
	struct size *sizes;
D 42
#if VAX==780
	register struct uba_regs *up = (struct uba_regs *)PHYSUBA0;
E 42
I 42
	register struct uba_regs *uba;
D 59
	register struct uba_dinfo *ui;
E 59
I 59
	register struct uba_device *ui;
E 59
E 42
	register short *rp;
I 42
	struct upst *st;
I 90
	register int retry;
E 90
I 79
	register int retry;
E 79
E 42
D 43
	int bdp;
E 43

D 42
	up->uba_cr = ADINIT;
	up->uba_cr = IFS|BRIE|USEFIE|SUEFIE;
	while ((up->uba_cnfgr & UBIC) == 0)
		;
E 41
I 34
#endif
I 41
	DELAY(1000000);
	while ((UPADDR->upcs1&DVA) == 0)
		;
	num = maxfree;
	start = 0;
E 42
D 117
	unit = minor(dev) >> 3;
E 117
I 117
	unit = upunit(dev);
E 117
D 57
	if (unit >= NUP) {
		printf("bad unit\n");
		return (-1);
	}
E 57
I 57
	if (unit >= NUP)
		return (ENXIO);
E 57
D 42
	upaddr = UPPHYS;
E 42
I 42
D 45
#define	phys1(cast, addr) ((cast)((int)addr & 0x7fffffff))
#define	phys(cast, addr) phys1(cast, phys1(cast *, &addr))
E 45
I 45
#define	phys(cast, addr) ((cast)((int)addr & 0x7fffffff))
E 45
D 59
	ui = phys(struct uba_dinfo *, updinfo[unit]);
E 59
I 59
	ui = phys(struct uba_device *, updinfo[unit]);
E 59
D 57
	if (ui->ui_alive == 0) {
		printf("dna\n");
		return(-1);
	}
E 57
I 57
	if (ui->ui_alive == 0)
		return (ENXIO);
E 57
	uba = phys(struct uba_hd *, ui->ui_hd)->uh_physuba;
D 59
#if VAX780
D 45
	if (cpu == VAX_780) {
		uba->uba_cr = UBA_ADINIT;
		uba->uba_cr = UBA_IFS|UBA_BRIE|UBA_USEFIE|UBA_SUEFIE;
		while ((uba->uba_cnfgr & UBA_UBIC) == 0)
			;
	}
E 45
I 45
	if (cpu == VAX_780)
		ubainit(uba);
E 45
#endif
E 59
I 59
	ubainit(uba);
E 59
D 57
	DELAY(1000000);
E 57
I 57
D 58
	DELAY(2000000);
E 58
E 57
D 49
	upaddr = (struct device *)ui->ui_physaddr;
	while ((upaddr->upcs1&DVA) == 0)
E 49
I 49
	upaddr = (struct updevice *)ui->ui_physaddr;
D 57
	while ((upaddr->upcs1&UP_DVA) == 0)
E 49
		;
E 57
I 57
D 59
	if ((upaddr->upcs1&UP_DVA) == 0)
		return (EFAULT);
E 59
I 59
D 79
D 90
	DELAY(2000000);
E 90
I 90
	DELAY(5000000);
E 90
E 79
I 79
	DELAY(5000000);
E 79
E 59
E 57
	num = maxfree;
D 79
D 90
	start = 0;
E 90
E 79
E 42
	upaddr->upcs2 = unit;
I 59
	DELAY(100);
D 79
D 90
	if ((upaddr->upcs1&UP_DVA) == 0)
		return (EFAULT);
E 59
D 49
	if ((upaddr->upds & VV) == 0) {
		upaddr->upcs1 = DCLR|GO;
		upaddr->upcs1 = PRESET|GO;
		upaddr->upof = FMT22;
E 49
I 49
D 65
	if ((upaddr->upds & UP_VV) == 0) {
E 65
I 65
	if ((upaddr->upds & UPDS_VV) == 0) {
E 65
		upaddr->upcs1 = UP_DCLR|UP_GO;
		upaddr->upcs1 = UP_PRESET|UP_GO;
D 65
		upaddr->upof = UP_FMT22;
E 65
I 65
		upaddr->upof = UPOF_FMT22;
E 65
E 49
	}
E 90
I 90
	upaddr->upcs1 = UP_DCLR|UP_GO;
	upaddr->upcs1 = UP_PRESET|UP_GO;
	upaddr->upof = UPOF_FMT22;
	retry = 0;
	do {
		DELAY(25);
		if (++retry > 527)
			break;
	} while ((upaddr->upds & UP_RDY) == 0);
E 90
E 79
I 79
	upaddr->upcs1 = UP_DCLR|UP_GO;
	upaddr->upcs1 = UP_PRESET|UP_GO;
	upaddr->upof = UPOF_FMT22;
	retry = 0;
	do {
		DELAY(25);
		if (++retry > 527)
			break;
D 81
	} while ((upaddr->upds & UPDS_RDY) == 0) {
E 81
I 81
	} while ((upaddr->upds & UP_RDY) == 0);
E 81
E 79
D 49
	if ((upaddr->upds & (DPR|MOL)) != (DPR|MOL)) {
		printf("up !DPR || !MOL\n");
E 49
I 49
D 57
	if ((upaddr->upds & (UP_DPR|UP_MOL)) != (UP_DPR|UP_MOL)) {
		printf("dna\n");
E 49
		return (-1);
	}
E 57
I 57
D 65
	if ((upaddr->upds & UP_DREADY) != UP_DREADY)
E 65
I 65
	if ((upaddr->upds & UPDS_DREADY) != UPDS_DREADY)
E 65
		return (EFAULT);
I 79
	start = 0;
E 79
E 57
D 42
	nsect = NSECT; ntrak = NTRAC; sizes = up_sizes;
E 42
I 42
D 45
	st = phys1(struct upst *, &upst[ui->ui_type]);
E 45
I 45
	st = &upst[ui->ui_type];
I 90
	start = 0;
E 90
E 45
D 47
	nsect = st->nsect;
	ntrak = st->ntrak;
E 47
	sizes = phys(struct size *, st->sizes);
E 42
D 57
	if (dumplo < 0 || dumplo + num >= sizes[minor(dev)&07].nblocks) {
D 42
		printf("dumplo+num, sizes %d %d\n", dumplo+num, sizes[minor(dev)&07].nblocks);
E 42
I 42
		printf("oor\n");
E 42
		return (-1);
	}
E 57
I 57
D 116
	if (dumplo < 0 || dumplo + num >= sizes[minor(dev)&07].nblocks)
E 116
I 116
	if (dumplo < 0)
E 116
		return (EINVAL);
I 116
	if (dumplo + num >= sizes[minor(dev)&07].nblocks)
		num = sizes[minor(dev)&07].nblocks - dumplo;
E 116
E 57
D 42
	nspc = nsect * ntrak;
E 42
I 42
D 47
	nspc = st->nspc;
E 47
E 42
	while (num > 0) {
		register struct pte *io;
		register int i;
		int cn, sn, tn;
		daddr_t bn;

		blk = num > DBSIZE ? DBSIZE : num;
D 43
		bdp = 1;		/* trick pcc */
D 42
		((struct uba_regs *)PHYSUBA0)->uba_dpr[bdp] |= BNE;
		io = ((struct uba_regs *)PHYSUBA0)->uba_map;
E 42
I 42
		uba->uba_dpr[bdp] |= UBA_BNE;
E 43
		io = uba->uba_map;
E 42
		for (i = 0; i < blk; i++)
D 42
			*(int *)io++ = (btop(start)+i) | (1<<21) | MRV;
E 42
I 42
D 59
			*(int *)io++ = (btop(start)+i) | (1<<21) | UBA_MRV;
E 59
I 59
			*(int *)io++ = (btop(start)+i) | (1<<21) | UBAMR_MRV;
E 59
E 42
		*(int *)io = 0;
		bn = dumplo + btop(start);
D 47
		cn = bn/nspc + sizes[minor(dev)&07].cyloff;
		sn = bn%nspc;
		tn = sn/nsect;
		sn = sn%nsect;
E 47
I 47
		cn = bn/st->nspc + sizes[minor(dev)&07].cyloff;
		sn = bn%st->nspc;
		tn = sn/st->nsect;
		sn = sn%st->nsect;
E 47
		upaddr->updc = cn;
		rp = (short *) &upaddr->upda;
		*rp = (tn << 8) + sn;
		*--rp = 0;
		*--rp = -blk*NBPG / sizeof (short);
D 49
		*--rp = GO|WCOM;
E 49
I 49
		*--rp = UP_GO|UP_WCOM;
I 90
		retry = 0;
E 90
I 79
		retry = 0;
E 79
E 49
		do {
			DELAY(25);
I 90
			if (++retry > 527)
				break;
E 90
I 79
			if (++retry > 527)
				break;
E 79
D 49
		} while ((upaddr->upcs1 & RDY) == 0);
		if (upaddr->upcs1&ERR) {
E 49
I 49
		} while ((upaddr->upcs1 & UP_RDY) == 0);
I 90
		if ((upaddr->upds & UPDS_DREADY) != UPDS_DREADY) {
			printf("up%d: not ready", unit);
			if ((upaddr->upds & UPDS_DREADY) != UPDS_DREADY) {
				printf("\n");
				return (EIO);
			}
			printf(" (flakey)\n");
		}
E 90
I 79
		if ((upaddr->upds & UPDS_DREADY) != UPDS_DREADY) {
D 81
			printf("up%d: not ready", dkunit(bp));
E 81
I 81
			printf("up%d: not ready", unit);
E 81
			if ((upaddr->upds & UPDS_DREADY) != UPDS_DREADY) {
				printf("\n");
				return (EIO);
			}
			printf(" (flakey)\n");
		}
E 79
D 57
		if (upaddr->upcs1&UP_ERR) {
E 49
			printf("up dump dsk err: (%d,%d,%d) cs1=%x, er1=%x\n",
			    cn, tn, sn, upaddr->upcs1, upaddr->uper1);
			return (-1);
		}
E 57
I 57
D 65
		if (upaddr->upcs1&UP_ERR)
E 65
I 65
		if (upaddr->upds&UPDS_ERR)
E 65
			return (EIO);
E 57
		start += blk*NBPG;
		num -= blk;
	}
D 43
	bdp = 1;		/* crud to fool c compiler */
D 42
	((struct uba_regs *)PHYSUBA0)->uba_dpr[bdp] |= BNE;
E 42
I 42
	uba->uba_dpr[bdp] |= UBA_BNE;
E 43
E 42
	return (0);
}
I 105

upsize(dev)
	dev_t dev;
{
D 117
	int unit = minor(dev) >> 3;
E 117
I 117
	int unit = upunit(dev);
E 117
	struct uba_device *ui;
	struct upst *st;

	if (unit >= NUP || (ui = updinfo[unit]) == 0 || ui->ui_alive == 0)
		return (-1);
	st = &upst[ui->ui_type];
	return (st->sizes[minor(dev) & 07].nblocks);
}
E 105
E 41
E 34
I 32
#endif
E 32
E 13
E 1
