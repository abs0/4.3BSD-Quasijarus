h39881
s 00004/00002/01414
d D 7.15 88/06/28 16:13:20 karels 147 146
c can't use 0 for indication of failure, change hpmaptype to boolean
e
s 00012/00000/01404
d D 7.14 88/06/14 18:28:23 bostic 146 145
c The emulex sc7003 is the newer version of the older sc750/sc780 massbus
c disk controls that is fast enough to handle super eagles (the sc780
c cannot). The code in hp.c requires that emulex disk controls emulate
c RM02. The code assumes that super eagles have 64 sectors, however the
c ONLY emulation for super eagles on a sc7003 that is a RM02 uses 68 sectors.
c From: muller%sdcc7@sdcsvax.ucsd.edu (Keith Muller)
e
s 00009/00007/01395
d D 7.13 88/06/04 17:07:41 karels 145 144
c yet another disklabel change: don't "open" partition 0 in WDINFO
c until setdisklabel finishes checks
e
s 00007/00000/01395
d D 7.12 88/06/03 16:11:31 karels 144 142
c even if no compat, need to allow access to labelsector on unlabeled disk
e
s 00007/00000/01395
d R 7.12 88/06/01 18:03:42 karels 143 142
c even if no compat, need to allow access to labelsector on unlabeled disk
e
s 00024/00026/01371
d D 7.11 88/05/27 16:41:20 karels 142 141
c new diskerr routine
e
s 00001/00001/01396
d D 7.10 88/05/22 16:32:36 karels 141 140
c lint
e
s 00003/00028/01394
d D 7.9 88/05/06 17:22:58 bostic 140 139
c changes for raw{read,write} stuff
e
s 00134/00043/01288
d D 7.8 88/04/23 15:28:23 karels 139 138
c compat for old HDR I/O; on-line formatting ioctls; ioctl to set
c in-core bad-sector table; lots of disklabel cleanups
e
s 00010/00038/01321
d D 7.7 87/11/01 12:57:12 karels 138 137
c use setdisklabel, writedisklabel
e
s 00003/00003/01356
d D 7.6 87/10/31 12:02:38 karels 137 136
c misc. fixes, including reversed test for min/maxdist
e
s 00011/00009/01348
d D 7.5 87/04/17 14:12:10 karels 136 135
c correct states on multiple opens
e
s 00049/00047/01308
d D 7.4 87/04/02 16:39:01 karels 135 134
c working with pack labels, open/close
e
s 00007/00003/01348
d D 7.3 87/02/20 18:02:00 karels 134 133
c save on newlines
e
s 00688/00365/00663
d D 7.2 87/02/19 17:33:53 karels 133 132
c pack labels
e
s 00001/00001/01027
d D 7.1 86/06/05 01:28:28 mckusick 132 131
c 4.3BSD release version
e
s 00010/00002/01018
d D 6.23 86/06/03 10:23:12 karels 131 130
c yow! Emulex controllers may have wrong bcr on BSE error (4 bytes past
c start of sector)!
e
s 00049/00043/00971
d D 6.22 86/05/30 17:52:35 karels 130 129
c add double eagle, clean up Emulex configuration, drop the 9766=>9300 mapping
e
s 00001/00001/01013
d D 6.21 86/05/02 11:34:37 karels 129 128
c watch for partial sectors in hpecc
e
s 00011/00005/01003
d D 6.20 86/02/23 23:21:27 karels 128 127
c lint
e
s 00001/00003/01007
d D 6.19 86/02/20 17:20:46 karels 127 126
c lint
e
s 00022/00014/00988
d D 6.18 86/02/02 21:41:29 karels 126 125
c retries restart from start of undone transfer
e
s 00001/00001/01001
d D 6.17 85/11/20 14:50:29 karels 125 124
c how did this work? don't need recal afer soft ecc!
e
s 00008/00002/00994
d D 6.16 85/11/04 18:48:52 karels 124 123
c reduce duplicate complaints
e
s 00065/00059/00931
d D 6.15 85/10/14 18:05:27 karels 123 122
c change error recovery procedure when starting positioning rather than
c retrying transfer (so attentions from other drives don't confuse us)
e
s 00002/00002/00988
d D 6.14 85/09/17 18:35:09 eric 122 121
c facilities in syslog
e
s 00009/00005/00981
d D 6.13 85/09/16 22:08:13 karels 121 120
c off by one, and need resid
e
s 00010/00010/00976
d D 6.12 85/09/16 21:33:39 karels 120 119
c may not need all of a revectored sector, don't continue for another
c -511 bytes; try badsector table on header ecc without waiting
e
s 00032/00021/00954
d D 6.11 85/09/14 17:16:44 bloom 119 118
c get rid of interleave code, add macro to get unit number, add error
c return codes to strategy
e
s 00003/00001/00972
d D 6.10 85/08/09 10:18:16 bloom 118 117
c support partial dumps
e
s 00001/00000/00972
d D 6.9 85/08/05 20:54:24 karels 117 116
c fix block number printed by hpecc
e
s 00007/00001/00965
d D 6.8 85/06/08 14:05:23 mckusick 116 115
c Add copyright
e
s 00041/00021/00925
d D 6.7 85/03/19 16:13:15 karels 115 114
c fixes, logging
e
s 00016/00016/00930
d D 6.6 84/08/29 21:42:55 bloom 114 112
c change to includes.  no more ../h
e
s 00017/00017/00929
d R 6.6 84/08/29 20:52:28 bloom 113 112
c change to includes.  no more ../h
e
s 00045/00032/00903
d D 6.5 84/08/29 17:19:34 ralph 112 111
c retries on ecc, fix SSE, check forwarded blocks for errors.
e
s 00039/00039/00896
d D 6.4 84/07/31 16:12:45 karels 111 110
c clean up error recovery
e
s 00033/00024/00902
d D 6.3 84/03/22 15:30:47 karels 110 109
c replace rdist with mindist, maxdist; correct distance calculations;
c fix offset code; wait for drive ready after positioning
e
s 00003/00003/00923
d D 6.2 83/09/25 19:42:07 karels 109 108
c 9775 has 842 cylinders, not 843
e
s 00000/00000/00926
d D 6.1 83/07/29 07:34:24 sam 108 107
c 4.2 distribution
e
s 00009/00010/00917
d D 4.81 83/07/26 21:41:16 helge 107 106
c more fixes in error printouts
e
s 00016/00008/00911
d D 4.80 83/07/26 13:44:51 helge 106 104
c fixed sect no in hard err message
e
s 00015/00008/00911
d R 4.80 83/07/26 01:47:01 helge 105 104
c now the sector number given with the hard error msg is always correct, also 
c added minor fix in the handling of hard errors when header i/o is active.
e
s 00002/00002/00917
d D 4.79 83/06/19 16:36:19 root 104 103
c cleanup after helge
e
s 00005/00005/00914
d D 4.78 83/06/17 22:09:40 helge 103 102
c fixed partition table for 9300's
e
s 00019/00011/00900
d D 4.77 83/06/16 14:53:19 sam 102 101
c merge helge's changes and mo's changes from monet
e
s 00028/00026/00883
d D 4.76 83/05/30 20:22:27 sam 101 100
c make hpSDIST and hpRDIST a per drive attribute
e
s 00013/00000/00896
d D 4.75 83/05/18 02:23:54 sam 100 99
c add entry point for swap partition sizing at boot time
e
s 00000/00011/00896
d D 4.74 83/03/27 23:26:17 sam 99 98
c finally purged the MONET Eagle partition table
e
s 00003/00003/00904
d D 4.73 83/03/19 16:28:43 sam 98 97
c eagle partitions calculated with 843 instead of 842 cylinders
e
s 00000/00004/00907
d D 4.72 83/03/11 09:46:14 sam 97 96
c finally remove special g partition for arpa
e
s 00014/00013/00897
d D 4.71 83/02/27 18:34:55 sam 96 95
c insure sc750/sc780 is initialized before probing holding register
e
s 00034/00014/00876
d D 4.70 83/02/24 23:19:53 sam 95 94
c si shit
e
s 00078/00070/00812
d D 4.69 83/02/21 18:04:00 sam 94 92
c standard partition tables
e
s 00077/00053/00829
d R 4.69 83/02/21 17:51:17 sam 93 92
c add standard disk partitions (plus kludges until dump/restor)
e
s 00033/00035/00849
d D 4.68 83/02/21 10:25:46 sam 92 90
c cleanups
e
s 00010/00013/00871
d R 4.68 83/02/20 22:39:39 sam 91 90
c cleanup after helge; from robert
e
s 00002/00002/00882
d D 4.67 83/02/11 08:35:24 sam 90 89
c how did this ever compile before?
e
s 00016/00000/00868
d D 4.66 83/02/10 21:46:45 helge 89 86
c Now handles bad sectors on tracks with skip sectors properly, and
c also checks the bad sector table when the header is screwed up (HCRC)
e
s 00017/00001/00867
d R 4.66 83/02/10 21:41:18 helge 88 86
c Now handles bad sectors on tracks with skip sectors properly, and
c also checks the bad sector table when the header of a sector is screwed up(HCRC)
e
s 00085/00043/00825
d R 4.66 83/02/10 17:53:37 helge 87 86
c now handles bad sectors on tracks with skip sectors properly,
c also checks the bas sector table when the header is screwed up (HCRC)
e
s 00035/00030/00833
d D 4.65 83/02/10 16:38:52 sam 86 85
c consolidate random data structures
e
s 00008/00042/00855
d D 4.64 83/02/10 16:18:49 sam 85 84
c all partitions leave space for bad sectors
e
s 00078/00040/00819
d D 4.63 83/02/05 17:07:06 sam 84 83
c add 48 sector eagles; cleanup type mapping a tad
e
s 00008/00000/00851
d D 4.62 83/01/27 11:33:31 helge 83 81
c fixed hard error handling
e
s 00007/00000/00851
d R 4.62 83/01/27 11:23:48 helge 82 81
c fixed hard error handling
e
s 00000/00018/00851
d D 4.61 83/01/01 18:33:42 sam 81 80
c purge cad trash
e
s 00008/00005/00861
d D 4.60 83/01/01 18:30:32 sam 80 79
c fixes for eagle
e
s 00001/00001/00865
d D 4.59 82/12/17 12:08:53 sam 79 78
c sun merge
e
s 00019/00004/00847
d D 4.58 82/11/13 23:02:21 sam 78 77
c add eagle hacks
e
s 00001/00001/00850
d D 4.57 82/10/31 15:40:16 root 77 76
c dkio.h in vax
e
s 00013/00002/00838
d D 4.56 82/10/17 11:54:23 root 76 75
c open/ioctl routine return errors; hpopen!!!
e
s 00004/00004/00836
d D 4.55 82/10/10 17:19:09 root 75 74
c vax header files in their place
e
s 00004/00006/00836
d D 4.54 82/09/12 03:04:12 root 74 73
c physio returns errors
e
s 00003/00002/00839
d D 4.53 82/08/22 21:16:45 root 73 72
c fully uio()'d
e
s 00005/00003/00836
d D 4.52 82/08/13 00:23:24 root 72 71
c hacks for chardev uio
e
s 00004/00002/00835
d D 4.51 82/08/01 19:28:14 sam 71 70
c new ioctl's
e
s 00001/00001/00836
d D 4.50 82/06/27 14:51:43 sam 70 68
c mask bits on holding register during Capricorn check
e
s 00001/00001/00836
d R 4.50 82/06/26 22:08:40 sam 69 68
c check only low 16 bits for capricorn
e
s 00007/00000/00830
d D 4.49 82/06/05 21:24:31 wnj 68 67
c kludge for CAD
e
s 00149/00010/00681
d D 4.48 82/05/24 19:17:59 sam 67 66
c si and ampex kludges, cad cylinder tables
e
s 00008/00005/00683
d D 4.47 82/02/18 13:19:15 wnj 66 65
c more fixes for HCRC (ignore BSE)
e
s 00008/00004/00680
d D 4.46 82/02/15 13:29:57 wnj 65 64
c bug fix per kre
e
s 00113/00031/00571
d D 4.45 82/02/08 22:46:28 root 64 63
c merge decvax!shannon's ML11 code and formatting ioctl
e
s 00001/00001/00601
d D 4.44 82/02/03 19:37:08 root 63 62
c fix partition size
e
s 00003/00002/00599
d D 4.43 82/01/17 20:12:18 root 62 61
c make bio and disk drivers not do spl0 so can call from panic without trap 2's
e
s 00000/00000/00601
d D 4.42 81/11/18 15:49:30 wnj 61 60
c lint
e
s 00001/00001/00600
d D 4.41 81/07/09 04:26:17 root 60 59
c lint
e
s 00001/00000/00600
d D 4.40 81/06/03 13:55:26 root 59 58
c fix to ECC botch
e
s 00007/00007/00593
d D 4.39 81/05/11 01:21:28 root 58 57
c fix sizes allowing for bads
e
s 00010/00010/00590
d D 4.38 81/05/10 20:04:53 root 57 56
c NOBADBLOCK->NOBADSECT
e
s 00194/00075/00406
d D 4.37 81/05/09 19:48:51 root 56 55
c rp05, rp07 and bad block handling
e
s 00001/00001/00480
d D 4.36 81/04/29 22:41:42 wnj 55 54
c fix per sklower
e
s 00001/00002/00480
d D 4.35 81/04/02 15:13:00 root 54 53
c get rid of unused partition; delete comment
e
s 00002/00003/00480
d D 4.34 81/03/22 20:58:55 wnj 53 52
c compile in skip sector code
e
s 00019/00001/00464
d D 4.33 81/03/17 18:12:04 wnj 52 51
c fixes to skip offset position on WRITES, not READS!
e
s 00006/00005/00459
d D 4.32 81/03/16 00:51:11 wnj 51 50
c working autoconf version
e
s 00000/00004/00464
d D 4.31 81/03/11 18:35:20 wnj 50 49
c remove todo's
e
s 00001/00000/00467
d D 4.30 81/03/09 20:02:06 wnj 49 48
c fixes to offset recovery code
e
s 00002/00001/00465
d D 4.29 81/03/09 13:20:47 wnj 48 47
c recal fixes; fix botch with SSE in hp.c
e
s 00006/00000/00460
d D 4.28 81/03/09 12:44:09 wnj 47 46
c hacked in printfs for testing
e
s 00000/00000/00460
d D 4.27 81/03/09 01:53:07 wnj 46 45
c %G% -> %E%
e
s 00010/00013/00450
d D 4.26 81/03/09 00:33:45 wnj 45 44
c lint
e
s 00048/00031/00415
d D 4.25 81/03/08 20:12:21 wnj 44 43
c fixups just pre lint
e
s 00016/00013/00430
d D 4.24 81/03/07 14:27:38 wnj 43 42
c after attempt at ht driver at cc again; working with new 
c field names
e
s 00001/00001/00442
d D 4.23 81/03/06 18:21:51 wnj 42 41
c spelling sn%d not bn%d
e
s 00004/00006/00439
d D 4.22 81/03/06 11:30:59 wnj 41 40
c new format for error printfs
e
s 00012/00018/00433
d D 4.21 81/03/03 15:17:21 wnj 40 39
c working spin down/up
e
s 00024/00003/00427
d D 4.20 81/03/03 12:38:31 wnj 39 38
c further driver work... up now handles spin down; rest still dont
e
s 00016/00017/00414
d D 4.19 81/03/01 22:07:33 wnj 38 37
c more minor changes
e
s 00043/00031/00388
d D 4.18 81/03/01 16:58:49 wnj 37 36
c a crack at doing like up.c/rk.c
e
s 00002/00006/00417
d D 4.17 81/02/28 17:35:28 wnj 36 35
c rmalloc and related stuff
e
s 00001/00001/00422
d D 4.16 81/02/27 03:14:35 wnj 35 34
c s/HZ/hz/
e
s 00004/00003/00419
d D 4.15 81/02/25 22:26:35 wnj 34 33
c fix {} errors
e
s 00009/00004/00413
d D 4.14 81/02/25 21:02:30 wnj 33 32
c almost working versions
e
s 00004/00001/00413
d D 4.13 81/02/25 14:53:27 wnj 32 31
c put in write lock diagnostic
e
s 00060/00071/00354
d D 4.12 81/02/23 20:12:56 wnj 31 30
c new names and other cleanup
e
s 00002/00002/00423
d D 4.11 81/02/22 21:45:53 wnj 30 29
c working interlocked system
e
s 00014/00011/00411
d D 4.10 81/02/21 21:19:57 wnj 29 28
c first working uba interlockable version
e
s 00000/00000/00422
d D 4.9 81/02/15 12:08:53 kre 28 27
c bootable autoconf version
e
s 00008/00008/00414
d D 4.8 81/02/10 13:19:09 wnj 27 26
c compilable first uba autoconf version
e
s 00189/00382/00233
d D 4.7 81/02/08 18:32:31 wnj 26 25
c first working vorsion
e
s 00001/00001/00614
d D 4.6 81/02/08 01:13:51 wnj 25 24
c last pre-mba version
e
s 00076/00001/00539
d D 4.5 81/02/07 15:48:52 wnj 24 23
c added dump code
e
s 00010/00004/00530
d D 4.4 81/01/28 11:45:06 kre 23 22
c fix B_WRITE->B_READ; DCLR & NSECT in hp; dont search if static 1 drive
e
s 00010/00010/00524
d D 4.3 80/12/19 15:21:44 wnj 22 21
c DK_N -> XXDK_N
e
s 00001/00001/00533
d D 4.2 80/12/19 11:44:48 wnj 21 20
c s,../conf/,,
e
s 00000/00000/00534
d D 4.1 80/11/09 16:53:19 bill 20 19
c stamp for 4bsd
e
s 00001/00001/00533
d D 3.19 80/11/03 15:25:51 bill 19 18
c MBA0->HPMBA
e
s 00002/00002/00532
d D 3.18 80/10/21 22:04:07 bill 18 17
c adjust hpS/RDIST upS/RDIST to 2/4 from (screwy 3/6, 6/6)
e
s 00003/00007/00531
d D 3.17 80/10/19 22:16:38 bill 17 16
c ../conf/*.h
e
s 00002/00002/00536
d D 3.16 80/10/16 11:29:06 bill 16 15
c fix up iostat for new monitoring
e
s 00016/00015/00522
d D 3.15 80/10/13 10:01:43 bill 15 14
c new monitoring; mba not pre-mapped
e
s 00001/00001/00536
d D 3.14 80/09/27 18:03:27 bill 14 13
c fix previous delta which offset WRITES only not READS!!!
e
s 00001/00001/00536
d D 3.13 80/09/27 18:01:33 bill 13 12
c dont servo-offset on write retries
e
s 00004/00002/00533
d D 3.12 80/09/25 21:48:37 bill 12 11
c fix bug in very large ECC's
e
s 00067/00029/00468
d D 3.11 80/09/16 17:34:47 bill 11 10
c add rm05s
e
s 00006/00003/00491
d D 3.10 80/08/24 21:23:11 bill 10 9
c fix bad bugs in ecc code
e
s 00098/00094/00396
d D 3.9 80/07/29 09:14:55 bill 9 8
c new mba stuff
e
s 00022/00014/00468
d D 3.8 80/07/03 01:42:46 bill 8 7
c fixup DK_N stuff
e
s 00001/00001/00481
d D 3.7 80/07/02 22:20:27 bill 7 6
c first crack at 2 drives
e
s 00001/00000/00481
d D 3.6 80/06/28 10:46:35 bill 6 5
c dk.h
e
s 00021/00008/00460
d D 3.5 80/06/24 19:28:18 bill 5 4
c no swplo
e
s 00001/00001/00467
d D 3.4 80/06/07 02:45:43 bill 4 3
c %H%->%G%
e
s 00002/00002/00466
d D 3.3 80/05/08 10:21:28 bill 3 2
c VOID=>void
e
s 00001/00001/00467
d D 3.2 80/04/30 17:15:42 bill 2 1
c fixed extern buffer because of new c botch
e
s 00468/00000/00000
d D 3.1 80/04/09 16:03:14 bill 1 0
c date and time created 80/04/09 16:03:14 by bill
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%H%	*/
E 4
I 4
D 26
/*	%M%	%I%	%G%	*/
E 26
I 26
D 116
/*	%M%	%I%	%E%	*/
E 116
I 116
/*
D 132
 * Copyright (c) 1982 Regents of the University of California.
E 132
I 132
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 132
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 116
I 56

#ifdef HPDEBUG
E 56
I 52
int	hpdebug;
I 56
#endif
#ifdef HPBDEBUG
int	hpbdebug;
#endif
E 56
E 52
E 26
E 4

I 17
D 21
#include "../conf/hp.h"
E 21
I 21
#include "hp.h"
E 21
#if NHP > 0
E 17
/*
D 8
 * RP04/RP06/RM03 disk driver
E 8
I 8
D 11
 * RP06/RM03 disk driver
E 11
I 11
D 26
 * RP06/RM03/RM05 disk driver
E 26
I 26
D 31
 * RP/RM disk driver
E 31
I 31
D 56
 * HP disk driver for RP0x+RM0x
E 56
I 56
D 64
 * HP disk driver for RP0x+RMxx
E 64
I 64
 * HP disk driver for RP0x+RMxx+ML11
E 64
E 56
I 38
 *
 * TODO:
D 41
 *	Check out handling of spun-down drives and write lock
E 41
D 39
 *	Add RM80 bad sector handling
E 39
I 39
D 44
 *	Check RM80 skip sector handling, esp when ECC's occur later
E 39
 *	Add reading of bad sector information and disk layout from sector 1
 *	Add bad sector forwarding code
 *	Check interaction with tape driver on same mba
 *	Check multiple drive handling
E 44
I 44
D 56
 *	check RM80 skip sector handling, esp when ECC's occur later
E 56
I 56
D 123
 *	check RM80 skip sector handling when ECC's occur later
E 56
D 50
 *	add reading of bad sector information and disk layout from sector 1
 *	add bad sector forwarding code
 *	check interaction with tape driver on same mba
 *	check multiple drive handling
E 50
 *	check offset recovery handling
E 123
I 56
 *	see if DCLR and/or RELEASE set attention status
D 123
 *	print bits of mr && mr2 symbolically
E 123
E 56
D 54
 *	see if DCLR and/or RELEASE set attention status
E 54
E 44
E 38
E 31
E 26
E 11
E 8
 */
I 79
D 135
#include "../machine/pte.h"
E 79

E 135
D 114
#include "../h/param.h"
#include "../h/systm.h"
I 5
#include "../h/dk.h"
I 6
D 9
#include "../h/dk.h"
E 9
E 6
E 5
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/map.h"
E 114
I 114
#include "param.h"
#include "systm.h"
D 133
#include "dk.h"
E 133
I 133
#include "dkstat.h"
E 133
#include "buf.h"
#include "conf.h"
#include "dir.h"
I 133
#include "file.h"
E 133
#include "user.h"
#include "map.h"
E 114
I 9
D 79
#include "../h/pte.h"
E 79
E 9
D 43
#include "../h/mba.h"
E 43
I 43
D 75
#include "../h/mbareg.h"
#include "../h/mbavar.h"
E 43
#include "../h/mtpr.h"
E 75
I 75
#include "../vax/mtpr.h"
E 75
D 9
#include "../h/pte.h"
E 9
I 9
D 114
#include "../h/vm.h"
I 24
#include "../h/cmap.h"
I 56
#include "../h/dkbad.h"
I 71
#include "../h/ioctl.h"
E 71
I 64
D 77
#include "../h/dkio.h"
E 77
I 72
#include "../h/uio.h"
E 114
I 114
#include "vm.h"
#include "cmap.h"
#include "dkbad.h"
I 133
#include "disklabel.h"
E 133
#include "ioctl.h"
#include "uio.h"
I 115
#include "syslog.h"
I 135
#include "stat.h"
E 135
E 115
E 114
E 72
E 64
E 56
E 24
E 9

I 135
#include "../machine/pte.h"
E 135
I 77
#include "../vax/dkio.h"
E 77
D 17
#define	DK_N	0
I 8
#define	DK_NMAX	1
E 8

E 17
D 26
struct	device
{
	int	hpcs1;		/* control and Status register 1 */
	int	hpds;		/* Drive Status */
	int	hper1;		/* Error register 1 */
	int	hpmr;		/* Maintenance */ 
	int	hpas;		/* Attention Summary */
	int	hpda;		/* Desired address register */
	int	hpdt;		/* Drive type */
	int	hpla;		/* Look ahead */
	int	hpsn;		/* serial number */
	int	hpof;		/* Offset register */
	int	hpdc;		/* Desired Cylinder address register */
	int	hpcc;		/* Current Cylinder */
	int	hper2;		/* Error register 2 */
	int	hper3;		/* Error register 3 */
	int	hpec1;		/* Burst error bit position */
	int	hpec2;		/* Burst error bit pattern */
};
E 26
I 26
D 75
#include "../h/hpreg.h"
E 75
I 75
D 114
#include "../vaxmba/mbareg.h"
#include "../vaxmba/mbavar.h"
#include "../vaxmba/hpreg.h"
E 114
I 114
#include "mbareg.h"
#include "mbavar.h"
#include "hpreg.h"
E 114
E 75
E 26

D 9
#define	HPADDR	((struct device *)(MBA0 + MBA_ERB))
E 9
I 9
D 17
#define	HPMBA		MBA0
#define	HPMBANUM	0

E 9
D 7
#define	NHP	1
E 7
I 7
#define	NHP	2
E 17
E 7
D 26
#define	RP	022
#define	RM	024
I 11
#define	RM5	027
E 11
#define	NSECT	22
#define	NTRAC	19
#define	NRMSECT	32
#define	NRMTRAC	5
D 5
#define	SDIST	2
#define	RDIST	6
E 5

I 5
D 18
#define	_hpSDIST	3
#define	_hpRDIST	6
E 18
I 18
#define	_hpSDIST	2
#define	_hpRDIST	3
E 18

int	hpSDIST = _hpSDIST;
int	hpRDIST = _hpRDIST;
int	hpseek;

E 5
struct	size
{
E 26
I 26
D 133
/* THIS SHOULD BE READ OFF THE PACK, PER DRIVE */
struct	size {
E 26
	daddr_t	nblocks;
	int	cyloff;
D 26
} hp_sizes[8] =
{
E 26
I 26
D 56
} hp_sizes[8] = {
E 56
I 56
D 94
} hp6_sizes[8] = {
E 94
I 94
} rp06_sizes[8] = {
E 94
E 56
E 26
D 11
	15884,	0,		/* cyl 0 thru 37 */
	33440,	38,		/* cyl 38 thru 117 */
	8360,	98,		/* cyl 98 thru 117 */
#ifdef ERNIE
	15884,	118,		/* cyl 118 thru 155 */
	66880,	156,		/* cyl 156 thru 315 */
E 11
I 11
	15884,	0,		/* A=cyl 0 thru 37 */
	33440,	38,		/* B=cyl 38 thru 117 */
	340670,	0,		/* C=cyl 0 thru 814 */
E 11
D 94
	0,	0,
D 11
	291346,	118,		/* cyl 118 thru 814, (like distrib) */
	208582,	316,		/* cyl 316 thru 814 */
#else
E 11
	0,	0,
	0,	0,
E 94
I 94
	15884,	118,		/* D=cyl 118 thru 155 */
	55936,	156,		/* E=cyl 156 thru 289 */
	219384,	290,		/* F=cyl 290 thru 814 */
E 94
I 11
D 56
	291346,	118,		/* G=cyl 118 thru 814 */
E 56
I 56
D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
D 58
	291302,	118,		/* G=cyl 118 thru 814 */
E 58
I 58
	291280,	118,		/* G=cyl 118 thru 814 */
E 58
D 85
#else
	291346,	118,
#endif
E 85
E 56
E 11
	0,	0,
D 11
	291346,	118,		/* cyl 118 thru 814 */
	0,	0,
#endif
E 11
D 56
}, rm_sizes[8] = {
E 56
I 56
D 94
}, rm3_sizes[8] = {
E 94
I 94
}, rp05_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 37 */
	33440,	38,		/* B=cyl 38 thru 117 */
	171798,	0,		/* C=cyl 0 thru 410 */
	15884,	118,		/* D=cyl 118 thru 155 */
	55936,	156,		/* E=cyl 156 thru 289 */
	50512,	290,		/* F=cyl 290 thru 410 */
	122408,	118,		/* G=cyl 118 thru 410 */
	0,	0,
}, rm03_sizes[8] = {
E 94
E 56
D 11
	15884,	0,		/* cyl 0 thru 99 */
	33440,	100,		/* cyl 100 thru 309 */
E 11
I 11
	15884,	0,		/* A=cyl 0 thru 99 */
D 94
	33440,	100,		/* B=cyl 100 thru 309 */
E 94
I 94
	33440,	100,		/* B=cyl 100 thru 308 */
E 94
	131680,	0,		/* C=cyl 0 thru 822 */
I 24
D 54
	2720,	291,
E 54
I 54
D 94
	0,	0,
E 54
E 24
E 11
	0,	0,
	0,	0,
E 94
I 94
	15884,	309,		/* D=cyl 309 thru 408 */
	55936,	409,		/* E=cyl 409 thru 758 */
	10144,	759,		/* F=cyl 759 thru 822 */
D 97
#ifdef ARPA
E 94
D 24
	0,	0,
E 24
I 11
D 56
	82080,	310,		/* G=cyl 310 thru 822 */
E 56
I 56
D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
D 58
	82016,	310,		/* G=cyl 310 thru 822 */
E 58
I 58
	81984,	310,		/* G=cyl 310 thru 822 */
I 94
#else
E 97
	82144,	309,		/* G=cyl 309 thru 822 */
D 97
#endif
E 97
E 94
E 58
D 85
#else
	82080,	310,
#endif
E 85
E 56
E 11
	0,	0,
D 11
	82080,	310,		/* cyl 310 thru 822 */
	0,	0,
E 11
I 11
D 94
}, rm5_sizes[8] = {
E 94
I 94
}, rm05_sizes[8] = {
E 94
I 67
D 81
#ifndef CAD
E 81
E 67
	15884,	0,		/* A=cyl 0 thru 26 */
	33440,	27,		/* B=cyl 27 thru 81 */
D 51
	500992,	0,		/* C=cyl 0 thru 823 */
E 51
I 51
	500384,	0,		/* C=cyl 0 thru 822 */
E 51
	15884,	562,		/* D=cyl 562 thru 588 */
	55936,	589,		/* E=cyl 589 thru 680 */
D 51
	86944,	681,		/* F=cyl 681 thru 823 */
	159296,	562,		/* G=cyl 562 thru 823 */
E 51
I 51
D 56
	86636,	681,		/* F=cyl 681 thru 822 */
	158688,	562,		/* G=cyl 562 thru 822 */
E 56
I 56
D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
D 58
	86572,	681,		/* F=cyl 681 thru 822 */
	158624,	562,		/* G=cyl 562 thru 822 */
E 58
I 58
	86240,	681,		/* F=cyl 681 thru 822 */
	158592,	562,		/* G=cyl 562 thru 822 */
E 58
D 85
#else
D 63
	86636,	681,
E 63
I 63
	86336,	681,
E 63
	158688,	562,
#endif
E 85
E 56
E 51
	291346,	82,		/* H=cyl 82 thru 561 */
I 67
D 81
#else
	15884,	0,		/* A=cyl 0 thru 26 */
	33440,	27,		/* B=cyl 27 thru 81 */
	495520,	0,		/* C=cyl 0 thru 814 */
	15884,	562,		/* D=cyl 562 thru 588 */
	55936,	589,		/* E=cyl 589 thru 680 */
#ifndef NOBADSECT
	81376,	681,		/* F=cyl 681 thru 814 */
	153728,	562,		/* G=cyl 562 thru 814 */
#else
	81472,	681,
	153824,	562,
#endif
	291346,	82,		/* H=cyl 82 thru 561 */
#endif
E 81
E 67
I 26
}, rm80_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 36 */
	33440,	37,		/* B=cyl 37 thru 114 */
	242606,	0,		/* C=cyl 0 thru 558 */
I 94
	15884,	115,		/* D=cyl 115 thru 151 */
	55936,	152,		/* E=cyl 152 thru 280 */
	120559,	281,		/* F=cyl 281 thru 558 */
	192603,	115,		/* G=cyl 115 thru 558 */
E 94
	0,	0,
D 94
	0,	0,
	0,	0,
	82080,	115,		/* G=cyl 115 thru 304 */
D 56
	110236,	305,		/* H=cyl 305 thru 558 */
E 56
I 56
D 58
	110174,	305,		/* H=cyl 305 thru 558 */
E 58
I 58
	110143,	305,		/* H=cyl 305 thru 558 */
E 58
}, hp7_sizes[8] = {
E 94
I 94
}, rp07_sizes[8] = {
E 94
D 67
	15844,	0,		/* A=cyl 0 thru 9 */
E 67
I 67
	15884,	0,		/* A=cyl 0 thru 9 */
E 67
D 94
	64000,	10,		/* B=cyl 10 thru 49 */
	1008000,0,		/* C=cyl 0 thru 629 */
	15884,	330,		/* D=cyl 330 thru 339 */
	256000,	340,		/* E=cyl 340 thru 499 */
D 58
	207900,	500,		/* F=cyl 500 thru 629 */
	479900,	330,		/* G=cyl 330 thru 629 */
E 58
I 58
	207850,	500,		/* F=cyl 500 thru 629 */
	479850,	330,		/* G=cyl 330 thru 629 */
E 58
	448000,	50,		/* H=cyl 50 thru 329 */
I 67
}, si9775_sizes[8] = {
D 85
	16640,	  0,		/* A=cyl   0 thru  12 */
	34560,	 13,		/* B=cyl  13 thru  39 */
	1079040,  0,		/* C=cyl   0 thru 842 - whole disk */
	0,	  0,		/* D unused */
	0,	  0,		/* E unused */
	0,	  0,		/* F unused */
	513280,	 40,		/* G=cyl  40 thru 440 */
E 85
I 85
	16640,	  0,		/* A=cyl 0 thru 12 */
	34560,	 13,		/* B=cyl 13 thru 39 */
	1079040,  0,		/* C=cyl 0 thru 842 */
	0,	  0,
	0,	  0,
	0,	  0,
	513280,	 40,		/* G=cyl 40 thru 440 */
E 85
	513280,	441,		/* H=cyl 441 thru 841 */
}, si9730_sizes[8] = {
E 94
I 94
	66880,	10,		/* B=cyl 10 thru 51 */
	1008000, 0,		/* C=cyl 0 thru 629 */
	15884,	235,		/* D=cyl 235 thru 244 */
	307200,	245,		/* E=cyl 245 thru 436 */
	308650,	437,		/* F=cyl 437 thru 629 */
	631850,	235,		/* G=cyl 235 thru 629 */
	291346,	52,		/* H=cyl 52 thru 234 */
}, cdc9775_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 12 */
	66880,	13,		/* B=cyl 13 thru 65 */
D 109
	1079040, 0,		/* C=cyl 0 thru 842 */
E 109
I 109
	1077760, 0,		/* C=cyl 0 thru 841 */
E 109
	15884,	294,		/* D=cyl 294 thru 306 */
	307200,	307,		/* E=cyl 307 thru 546 */
D 109
	378784,	547,		/* F=cyl 547 thru 842 */
	702624,	294,		/* G=cyl 294 thru 842 */
E 109
I 109
	377440,	547,		/* F=cyl 547 thru 841 */
	701280,	294,		/* G=cyl 294 thru 841 */
E 109
	291346,	66,		/* H=cyl 66 thru 293 */
}, cdc9730_sizes[8] = {
E 94
	15884,	0,		/* A=cyl 0 thru 49 */
	33440,	50,		/* B=cyl 50 thru 154 */
	263360,	0,		/* C=cyl 0 thru 822 */
I 94
	15884,	155,		/* D=cyl 155 thru 204 */
	55936,	205,		/* E=cyl 205 thru 379 */
	141664,	380,		/* F=cyl 380 thru 822 */
	213664,	155,		/* G=cyl 155 thru 822 */
E 94
	0,	0,
D 94
	0,	0,
	0,	0,
	0,	0,
D 85
#ifndef NOBADSECT
E 85
	213664,	155,		/* H=cyl 155 thru 822 */
D 85
#else
	213760,	155,
#endif
E 85
}, hpam_sizes[8] = {
E 94
I 94
}, capricorn_sizes[8] = {
E 94
	15884,	0,		/* A=cyl 0 thru 31 */
	33440,	32,		/* B=cyl 32 thru 97 */
	524288,	0,		/* C=cyl 0 thru 1023 */
D 94
	27786,	668,
	27786,	723,
	125440,	778,
	181760,	668,		/* G=cyl 668 thru 1022 */
E 94
I 94
	15884,	668,		/* D=cyl 668 thru 699 */
	55936,	700,		/* E=cyl 700 thru 809 */
	109472,	810,		/* F=cyl 810 thru 1023 */
	182176,	668,		/* G=cyl 668 thru 1023 */
E 94
	291346,	98,		/* H=cyl 98 thru 667 */
I 78
D 94
}, hpfj_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 18 */
	33440,	19,		/* B=cyl 19 thru 58 */
D 80
	723991,	0,		/* C=cyl 0 thru 841 */
E 80
I 80
	724120,	0,		/* C=cyl 0 thru 841 */
E 80
	0, 0,
	0, 0,
	0, 0,
	381711, 398,		/* G=cyl 398 thru 841 */
	291346, 59,		/* H=cyl 59 thru 397 */
I 84
}, hpfj48_sizes[8] = {
E 94
I 94
}, eagle_sizes[8] = {
D 99
#ifdef MONET
E 99
E 94
	15884,	0,		/* A=cyl 0 thru 16 */
D 99
	33440,	17,		/* B=cyl 17 thru 52 */
	808176,	0,		/* C=cyl 0 thru 841 */
	0, 0,
	0, 0,
	0, 0,
	465456, 357,		/* G=cyl 357 thru 841 */
	291346, 53,		/* H=cyl 52 thru 356 */
I 94
#else
	15884,	0,		/* A=cyl 0 thru 16 */
E 99
	66880,	17,		/* B=cyl 17 thru 86 */
D 98
	809280,	0,		/* C=cyl 0 thru 842 */
E 98
I 98
	808320,	0,		/* C=cyl 0 thru 841 */
E 98
	15884,	391,		/* D=cyl 391 thru 407 */
	307200,	408,		/* E=cyl 408 thru 727 */
D 98
	110256,	728,		/* F=cyl 728 thru 842 */
	433776,	391,		/* G=cyl 391 thru 842 */
E 98
I 98
	109296,	728,		/* F=cyl 728 thru 841 */
	432816,	391,		/* G=cyl 391 thru 841 */
E 98
	291346,	87,		/* H=cyl 87 thru 390 */
D 99
#endif
E 99
I 95
D 103
}, cdc9300_sizes[8] = {
E 103
I 103
D 104
}, 9300_sizes[8] = {
E 104
I 104
}, ampex_sizes[8] = {
E 104
E 103
	15884,	0,		/* A=cyl 0 thru 26 */
	33440,	27,		/* B=cyl 27 thru 81 */
D 103
	500384,	0,		/* C=cyl 0 thru 822 */
E 103
I 103
	495520,	0,		/* C=cyl 0 thru 814 */
E 103
	15884,	562,		/* D=cyl 562 thru 588 */
	55936,	589,		/* E=cyl 589 thru 680 */
D 103
	86240,	681,		/* F=cyl 681 thru 822 */
	158592,	562,		/* G=cyl 562 thru 822 */
E 103
I 103
	81312,	681,		/* F=cyl 681 thru 814 */
	153664,	562,		/* G=cyl 562 thru 814 */
E 103
	291346,	82,		/* H=cyl 82 thru 561 */
I 130
}, fj2361_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 12 */
	66880,	13,		/* B=cyl 13 thru 65 */
	1077760, 0,		/* C=cyl 0 thru 841 */
	15884,	294,		/* D=cyl 294 thru 306 */
	307200,	307,		/* E=cyl 307 thru 546 */
	377408,	547,		/* F=cyl 547 thru 841 */
	701248,	294,		/* G=cyl 294 thru 841 */
	291346,	66,		/* H=cyl 66 thru 293 */
E 130
E 95
E 94
E 84
E 78
E 67
E 56
E 26
E 11
};
I 26
/* END OF STUFF WHICH SHOULD BE READ IN PER DISK */
E 133
I 133
#define	COMPAT_42
#define	B_FORMAT	B_XXX
E 133
E 26

D 26
#define	P400	020
#define	M400	0220
#define	P800	040
#define	M800	0240
#define	P1200	060
#define	M1200	0260
int	hp_offset[16] =
{
E 26
I 26
D 101
#define	_hpSDIST	2
#define	_hpRDIST	3

int	hpSDIST = _hpSDIST;
int	hpRDIST = _hpRDIST;

E 101
D 67
short	hptypes[] =
D 56
	{ MBDT_RM03, MBDT_RM05, MBDT_RP06, MBDT_RM80, 0 };
E 56
I 56
D 64
	{ MBDT_RM03, MBDT_RM05, MBDT_RP06, MBDT_RM80, MBDT_RP05, MBDT_RP07, 0 };
E 64
I 64
	{ MBDT_RM03, MBDT_RM05, MBDT_RP06, MBDT_RM80, MBDT_RP05, MBDT_RP07,
	  MBDT_ML11A, MBDT_ML11B, 0 };
E 67
I 67
/*
D 133
 * Table for converting Massbus drive types into
 * indices into the partition tables.  Slots are
D 130
 * left for those drives devined from other means
E 130
I 130
 * left for those drives divined from other means
E 133
I 133
 * Table of supported Massbus drive types.
 * When using unlabeled packs, slot numbers here
 * are used as indices into the partition tables.
 * Slots are left for those drives divined from other means
E 133
E 130
 * (e.g. SI, AMPEX, etc.).
 */
short	hptypes[] = {
#define	HPDT_RM03	0
	MBDT_RM03,
#define	HPDT_RM05	1
	MBDT_RM05,
#define	HPDT_RP06	2
	MBDT_RP06,
#define	HPDT_RM80	3
	MBDT_RM80,
D 102
#define	HPDT_RP05	4
E 102
I 102
#define	HPDT_RP04	4
	MBDT_RP04,
#define	HPDT_RP05	5
E 102
	MBDT_RP05,
D 102
#define	HPDT_RP07	5
E 102
I 102
#define	HPDT_RP07	6
E 102
	MBDT_RP07,
D 102
#define	HPDT_ML11A	6
E 102
I 102
#define	HPDT_ML11A	7
E 102
	MBDT_ML11A,
D 102
#define	HPDT_ML11B	7
E 102
I 102
#define	HPDT_ML11B	8
E 102
	MBDT_ML11B,
D 102
#define	HPDT_9775	8
E 102
I 102
#define	HPDT_9775	9
E 102
	-1,
D 102
#define	HPDT_9730	9
E 102
I 102
#define	HPDT_9730	10
E 102
	-1,
D 102
#define	HPDT_CAPRICORN	10
E 102
I 102
#define	HPDT_CAPRICORN	11
E 102
	-1,
D 78
#define	HPDT_RM02	11
	MBDT_RM02,		/* beware, actually capricorn */
E 78
I 78
D 102
#define HPDT_EAGLE	11
E 102
I 102
#define HPDT_EAGLE	12
E 102
	-1,
D 84
#define HPDT_RM02	12
E 84
I 84
D 94
#define	HPDT_EAGLE48	12
	-1,
#define HPDT_RM02	13
E 94
I 94
D 95
#define HPDT_RM02	12
E 95
I 95
D 102
#define	HPDT_9300	12
E 102
I 102
#define	HPDT_9300	13
E 102
	-1,
D 102
#define HPDT_RM02	13
E 102
I 102
#define HPDT_RM02	14
E 102
E 95
E 94
E 84
D 130
	MBDT_RM02,		/* beware, actually capricorn or eagle */
E 130
I 130
	MBDT_RM02,		/* beware, actually mapped */
#define HPDT_2361	15
	-1,
I 146
#define HPDT_2361A	16
	-1,
E 146
E 130
E 78
	0
};
I 133

E 133
E 67
E 64
E 56
D 43
struct	mba_info *hpinfo[NHP];
int	hpdkinit(),hpustart(),hpstart(),hpdtint();
E 43
I 43
struct	mba_device *hpinfo[NHP];
D 106
int	hpattach(),hpustart(),hpstart(),hpdtint();
E 106
I 106
D 107
int	hpattach(), hpustart(), hpstart(), hpdtint();
E 107
I 107
D 135
int	hpattach(),hpustart(),hpstart(),hpdtint();
E 135
I 135
int	hpattach(),hpustart(),hpstart(),hpdtint(),hpstrategy();
E 135
E 107
E 106
E 43
struct	mba_driver hpdriver =
D 43
	{ hpdkinit, hpustart, hpstart, hpdtint, 0, hptypes, hpinfo };
E 43
I 43
	{ hpattach, 0, hpustart, hpstart, hpdtint, 0,
	  hptypes, "hp", 0, hpinfo };
E 43

I 101
D 133
/*
D 110
 * Beware, sdist and rdist are not well tuned
E 110
I 110
 * These variable are all measured in sectors.  
 * Sdist is how much to "lead" in the search for a desired sector
 * (i.e. if want N, search for N-sdist.)
 * Maxdist and mindist define the region right before our desired sector within
 * which we don't bother searching.  We don't search when we are already less
 * then maxdist and more than mindist sectors "before" our desired sector.
 * Maxdist should be >= sdist.
 * 
 * Beware, sdist, mindist and maxdist are not well tuned
E 110
 * for many of the drives listed in this table.
 * Try patching things with something i/o intensive
 * running and watch iostat.
 */
E 101
struct hpst {
D 101
	short	nsect;
	short	ntrak;
	short	nspc;
	short	ncyl;
	struct	size *sizes;
E 101
I 101
	short	nsect;		/* # sectors/track */
	short	ntrak;		/* # tracks/cylinder */
	short	nspc;		/* # sector/cylinders */
	short	ncyl;		/* # cylinders */
	struct	size *sizes;	/* partition tables */
	short	sdist;		/* seek distance metric */
D 110
	short	rdist;		/* rotational distance metric */
E 110
I 110
	short	maxdist;	/* boundaries of non-searched area */
	short	mindist;	/* preceding the target sector */
I 130
	char	*name;		/* name of disk type */
E 130
E 110
E 101
} hpst[] = {
D 56
	32,	5,	32*5,	823,	rm_sizes,	/* RM03 */
E 56
I 56
D 94
	32,	5,	32*5,	823,	rm3_sizes,	/* RM03 */
E 56
	32,	19,	32*19,	823,	rm5_sizes,	/* RM05 */
D 56
	22,	19,	22*19,	815,	hp_sizes,	/* RP06 */
	31,	14, 	31*14,	559,	rm80_sizes	/* RM80 */
E 56
I 56
	22,	19,	22*19,	815,	hp6_sizes,	/* RP06 */
E 94
I 94
D 101
	32,	5,	32*5,	823,	rm03_sizes,	/* RM03 */
	32,	19,	32*19,	823,	rm05_sizes,	/* RM05 */
	22,	19,	22*19,	815,	rp06_sizes,	/* RP06 */
E 94
	31,	14, 	31*14,	559,	rm80_sizes,	/* RM80 */
D 94
	22,	19,	22*19,	411,	hp6_sizes,	/* RP05 */
	50,	32,	50*32,	630,	hp7_sizes,	/* RP07 */
E 94
I 94
	22,	19,	22*19,	411,	rp05_sizes,	/* RP05 */
	50,	32,	50*32,	630,	rp07_sizes,	/* RP07 */
E 94
I 64
	1,	1,	1,	1,	0,		/* ML11A */
	1,	1,	1,	1,	0,		/* ML11B */
I 67
D 94
	32,	40,	32*40,	843,	si9775_sizes,	/* 9775 */
	32,	10,	32*10,	823,	si9730_sizes,	/* 9730 */
	32,	16,	32*16,	1024,	hpam_sizes,	/* AMPEX capricorn */
I 78
D 80
	43,	20,	43*20,	843,	hpfj_sizes,	/* Fujitsu EAGLE */
E 80
I 80
	43,	20,	43*20,	842,	hpfj_sizes,	/* Fujitsu EAGLE */
I 84
	48,	20,	48*20,	842,	hpfj48_sizes,	/* 48 sector EAGLE */
E 94
I 94
	32,	40,	32*40,	843,	cdc9775_sizes,	/* 9775 */
	32,	10,	32*10,	823,	cdc9730_sizes,	/* 9730 */
D 95
	32,	16,	32*16,	1024,	capricorn_sizes,/* AMPEX capricorn */
	48,	20,	48*20,	842,	eagle_sizes,	/* Fujitsu EAGLE */
E 95
I 95
	32,	16,	32*16,	1024,	capricorn_sizes,/* Capricorn */
	48,	20,	48*20,	842,	eagle_sizes,	/* EAGLE */
	32,	19,	32*19,	815,	cdc9300_sizes,	/* 9300 */
E 101
I 101
D 110
	{ 32,	5,	32*5,	823,	rm03_sizes,	3, 4 },	/* RM03 */
	{ 32,	19,	32*19,	823,	rm05_sizes,	3, 4 },	/* RM05 */
	{ 22,	19,	22*19,	815,	rp06_sizes,	3, 4 },	/* RP06 */
	{ 31,	14, 	31*14,	559,	rm80_sizes,	3, 4 },	/* RM80 */
I 102
	{ 22,	19,	22*19,	411,	rp05_sizes,	3, 4 },	/* RP04 */
E 102
	{ 22,	19,	22*19,	411,	rp05_sizes,	3, 4 },	/* RP05 */
	{ 50,	32,	50*32,	630,	rp07_sizes,	7, 8 },	/* RP07 */
	{ 1,	1,	1,	1,	0,		0, 0 },	/* ML11A */
	{ 1,	1,	1,	1,	0,		0, 0 },	/* ML11B */
	{ 32,	40,	32*40,	843,	cdc9775_sizes,	3, 4 },	/* 9775 */
	{ 32,	10,	32*10,	823,	cdc9730_sizes,	3, 4 },	/* 9730 */
	{ 32,	16,	32*16,	1024,	capricorn_sizes,7, 8 },	/* Capricorn */
	{ 48,	20,	48*20,	842,	eagle_sizes,	7, 8 },	/* EAGLE */
D 103
	{ 32,	19,	32*19,	815,	cdc9300_sizes,	3, 4 },	/* 9300 */
E 103
I 103
D 104
	{ 32,	19,	32*19,	815,	9300_sizes,	3, 4 },	/* 9300 */
E 104
I 104
	{ 32,	19,	32*19,	815,	ampex_sizes,	3, 4 },	/* 9300 */
E 110
I 110
D 130
    { 32, 5,	32*5,	823,	rm03_sizes,	7, 4, 1 },	/* RM03 */
    { 32, 19,	32*19,	823,	rm05_sizes,	7, 4, 1 },	/* RM05 */
    { 22,19,	22*19,	815,	rp06_sizes,	7, 4, 1 },	/* RP06 */
    { 31, 14, 	31*14,	559,	rm80_sizes,	7, 4, 1 },	/* RM80 */
    { 22, 19,	22*19,	411,	rp05_sizes,	7, 4, 1 },	/* RP04 */
    { 22, 19,	22*19,	411,	rp05_sizes,	7, 4, 1 },	/* RP05 */
    { 50, 32,	50*32,	630,	rp07_sizes,    15, 8, 3 },	/* RP07 */
    { 1, 1,	1,	1,	0,		0, 0, 0 },	/* ML11A */
    { 1, 1,	1,	1,	0,		0, 0, 0 },	/* ML11B */
    { 32, 40,	32*40,	843,	cdc9775_sizes,	7, 4, 1 },	/* 9775 */
    { 32, 10,	32*10,	823,	cdc9730_sizes,	7, 4, 1 },	/* 9730 */
    { 32, 16,	32*16,	1024,	capricorn_sizes,10,4, 3 },	/* Capricorn */
    { 48, 20,	48*20,	842,	eagle_sizes,   15, 8, 3 },	/* EAGLE */
    { 32, 19,	32*19,	815,	ampex_sizes,	7, 4, 1 },	/* 9300 */
E 130
I 130
    { 32, 5,	32*5,	823,	rm03_sizes,	7, 4, 1, "RM03" },
    { 32, 19,	32*19,	823,	rm05_sizes,	7, 4, 1, "RM05" },
    { 22,19,	22*19,	815,	rp06_sizes,	7, 4, 1, "RP06"},
    { 31, 14, 	31*14,	559,	rm80_sizes,	7, 4, 1, "RM80"},
    { 22, 19,	22*19,	411,	rp05_sizes,	7, 4, 1, "RP04"},
    { 22, 19,	22*19,	411,	rp05_sizes,	7, 4, 1, "RP05"},
    { 50, 32,	50*32,	630,	rp07_sizes,    15, 8, 3, "RP07"},
    { 1, 1,	1,	1,	0,		0, 0, 0, "ML11A"},
    { 1, 1,	1,	1,	0,		0, 0, 0, "ML11B" },
    { 32, 40,	32*40,	843,	cdc9775_sizes,	7, 4, 1, "9775" },
    { 32, 10,	32*10,	823,	cdc9730_sizes,	7, 4, 1, "9730-160" },
    { 32, 16,	32*16,	1024,	capricorn_sizes,10,4, 3, "capricorn" },
    { 48, 20,	48*20,	842,	eagle_sizes,   15, 8, 3, "eagle" },
    { 32, 19,	32*19,	815,	ampex_sizes,	7, 4, 1, "9300" },
    { 64, 20,	64*20,	842,	fj2361_sizes,  15, 8, 3, "2361" },
E 130
E 110
E 104
E 103
E 101
E 95
E 94
E 84
E 80
E 78
E 67
E 64
E 56
};

E 133
D 31
int	hp_offset[16] = {
E 26
	P400, M400, P400, M400,
	P800, M800, P800, M800,
	P1200, M1200, P1200, M1200,
	0, 0, 0, 0,
E 31
I 31
u_char	hp_offset[16] = {
D 44
    HP_P400, HP_M400, HP_P400, HP_M400, HP_P800, HP_M800, HP_P800, HP_M800,
    HP_P1200, HP_M1200, HP_P1200, HP_M1200, 0, 0, 0, 0,
E 44
I 44
    HPOF_P400, HPOF_M400, HPOF_P400, HPOF_M400,
    HPOF_P800, HPOF_M800, HPOF_P800, HPOF_M800,
    HPOF_P1200, HPOF_M1200, HPOF_P1200, HPOF_M1200,
    0, 0, 0, 0,
E 44
E 31
};

D 26
struct	buf	hptab;
E 26
D 31
struct	buf	rhpbuf;
E 31
I 31
D 140
struct	buf	rhpbuf[NHP];
E 140
I 56
D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
D 133
struct	buf	bhpbuf[NHP];
E 133
I 133
struct	disklabel hplabel[NHP];
E 133
struct	dkbad	hpbad[NHP];
D 85
#endif
E 85
I 64
D 86
/* SHOULD CONSOLIDATE ALL THIS STUFF INTO A STRUCTURE */
E 64
char	hpinit[NHP];
E 56
I 40
char	hprecal[NHP];
I 64
char	hphdr[NHP];
daddr_t	mlsize[NHP];
E 86
E 64
E 40
E 31
D 26
struct	buf	hputab[NHP];
char	hp_type[NHP];	/* drive type */
E 26

I 86
struct	hpsoftc {
D 133
	u_char	sc_hpinit;	/* drive initialized */
E 133
	u_char	sc_recal;	/* recalibrate state */
D 133
	u_char	sc_hdr;		/* next i/o includes header */
E 133
	u_char	sc_doseeks;	/* perform explicit seeks */
I 139
#ifdef COMPAT_42
	u_char	sc_hdr;		/* next i/o includes header */
#endif
E 139
I 133
	int	sc_state;	/* open fsm */
I 139
	int	sc_wlabel;	/* label sector is currently writable */
E 139
D 138
	long	sc_openpart;	/* bit mask of open subunits */
I 135
	long	sc_copenpart;	/* bit mask of open character subunits */
	long	sc_bopenpart;	/* bit mask of open block subunits */
E 138
I 138
	u_long	sc_openpart;	/* bit mask of open subunits */
	u_long	sc_copenpart;	/* bit mask of open character subunits */
	u_long	sc_bopenpart;	/* bit mask of open block subunits */
E 138
E 135
E 133
	daddr_t	sc_mlsize;	/* ML11 size */
I 112
D 123
	int	sc_pgdone;	/* amount sucessfully transfered */
E 123
I 123
	int	sc_blkdone;	/* amount sucessfully transfered */
E 123
	daddr_t	sc_badbn;	/* replacement block number */
I 139
	int	sc_status;	/* copy of drive status reg. after format */
	int	sc_hpds;	/* copy of hpds reg. after format */
	int	sc_er1;		/* copy of error reg. 1 after format */
	int	sc_er2;		/* copy of error reg. 2 after format */
E 139
E 112
} hpsoftc[NHP];

I 133
/*
 * Drive states.  Used during steps of open/initialization.
 * States < OPEN (> 0) are transient, during an open operation.
 * OPENRAW is used for unlabeled disks,
 * to inhibit bad-sector forwarding or allow format operations.
 */
#define	CLOSED		0		/* disk is closed. */
#define	WANTOPEN	1		/* open requested, not started */
#define	WANTOPENRAW	2		/* open requested, no label */
#define	RDLABEL		3		/* reading pack label */
#define	RDBADTBL	4		/* reading bad-sector table */
#define	OPEN		5		/* initialized and ready */
#define	OPENRAW		6		/* open, no label or badsect */

E 133
E 86
D 26
#define	GO	01
#define	PRESET	020
#define	RTC	016
#define	OFFSET	014
I 5
#define	SEEK	04
E 5
#define	SEARCH	030
#define	RECAL	06
#define	DCLR	010
#define	WCOM	060
#define	RCOM	070

#define	IE	0100
#define	PIP	020000
#define	DRY	0200
#define	ERR	040000
#define	TRE	040000
#define	DCK	0100000
#define	WLE	04000
#define	ECH	0100
#define	VV	0100
#define	DPR	0400
#define	MOL	010000
#define	FMT22	010000

E 26
#define	b_cylin b_resid
 
I 64
/* #define ML11 0  to remove ML11 support */
D 133
#define	ML11	(hptypes[mi->mi_type] == MBDT_ML11A)
#define	RP06	(hptypes[mi->mi_type] <= MBDT_RP06)
#define	RM80	(hptypes[mi->mi_type] == MBDT_RM80)
E 133
I 133
#define	ML11(type)	((type) == HPDT_ML11A)
#define	RP06(type)	(hptypes[type] <= MBDT_RP06)
#define	RM80(type)	((type) == HPDT_RM80)
E 133

I 119
#define hpunit(dev)	(minor(dev) >> 3)
I 133
#define hppart(dev)	(minor(dev) & 07)
#define hpminor(unit, part)	(((unit) << 3) | (part))

E 133
E 119
I 92
#define	MASKREG(reg)	((reg)&0xffff)
I 128
#ifdef lint
#define HPWAIT(mi, addr) (hpwait(mi))
#else
E 128
I 115
#define HPWAIT(mi, addr) (((addr)->hpds & HPDS_DRY) || hpwait(mi))
I 128
#endif
E 128
E 115

E 92
E 64
D 119
#ifdef INTRLVE
daddr_t dkblock();
#endif
D 86
 
I 29
int	hpseek;
E 86

E 119
D 43
hpdkinit(mi)
	struct mba_info *mi;
E 43
I 43
/*ARGSUSED*/
hpattach(mi, slave)
D 84
	struct mba_device *mi;
E 84
I 84
D 133
	register struct mba_device *mi;
E 133
I 133
	struct mba_device *mi;
E 133
E 84
E 43
{
I 133
	register int unit = mi->mi_unit;
I 139
	extern int cold;
E 139
E 133
D 64
	register struct hpst *st = &hpst[mi->mi_type];
E 64
I 64
D 67
	if (hptypes[mi->mi_type] == MBDT_ML11B)
		mi->mi_type--;	/* A CHEAT - ML11B D.T. SHOULD == ML11A */
	if (ML11) {
		register struct hpdevice *hpaddr =
			(struct hpdevice *)mi->mi_drv;
E 67
I 67
D 84
	register struct hpdevice *hpaddr = (struct hpdevice *)mi->mi_drv;
I 80
	int ntracks;
E 84
E 80

D 84
	switch (mi->mi_type) {
E 84
I 84
D 133
	mi->mi_type = hpmaptype(mi);
	if (!ML11 && mi->mi_dk >= 0) {
		struct hpst *st = &hpst[mi->mi_type];
E 84

I 84
		dk_mspw[mi->mi_dk] = 1.0 / 60 / (st->nsect * 256);
	}
E 133
I 133
D 139
	/*
	 * Try to initialize device and read pack label.
	 */
	if (hpinit(hpminor(unit, 0), 0) == 0) {
D 134
		printf("hp%d: %s\n", unit, hplabel[unit].d_typename);
E 134
I 134
		printf(": %s", hplabel[unit].d_typename);
E 139
I 139
	if (cold) {
		/*
		 * Try to initialize device and read pack label.
		 */
		if (hpinit(hpminor(unit, 0), 0) == 0) {
			printf(": %s", hplabel[unit].d_typename);
E 139
E 134
#ifdef notyet
D 139
		addswap(makedev(HPMAJOR, hpminor(unit, 0)), &hplabel[unit]);
E 139
I 139
			addswap(makedev(HPMAJOR, hpminor(unit, 0)),
			    &hplabel[unit]);
E 139
#endif
D 139
	} else
D 134
		printf("hp%d: offline\n", unit);
E 134
I 134
		printf(": offline");
E 139
I 139
		} else
			printf(": offline");
	}
E 139
E 134
E 133
}

D 133
/*
 * Map apparent MASSBUS drive type into manufacturer
 * specific configuration.  For SI controllers this is done
 * based on codes in the serial number register.  For
 * EMULEX controllers, the track and sector attributes are
 * used when the drive type is an RM02 (not supported by DEC).
 */
hpmaptype(mi)
	register struct mba_device *mi;
E 133
I 133
D 135
hpopen(dev, flags)
E 135
I 135
hpopen(dev, flags, fmt)
E 135
	dev_t dev;
D 135
	int flags;
E 135
I 135
	int flags, fmt;
E 135
E 133
{
D 133
	register struct hpdevice *hpaddr = (struct hpdevice *)mi->mi_drv;
	register int type = mi->mi_type;
E 133
I 133
	register int unit = hpunit(dev);
	register struct hpsoftc *sc;
	register struct disklabel *lp;
	register struct partition *pp;
	struct mba_device *mi;
D 135
	int s, error, part = hppart(dev);
E 135
I 135
	int s, error, part = hppart(dev), mask = 1 << part;
E 135
	daddr_t start, end;
E 133

I 133
	if (unit >= NHP || (mi = hpinfo[unit]) == 0 || mi->mi_alive == 0)
		return (ENXIO);
	sc = &hpsoftc[unit];
	lp = &hplabel[unit];

	s = spl5();
	while (sc->sc_state != OPEN && sc->sc_state != OPENRAW &&
	    sc->sc_state != CLOSED)
		sleep ((caddr_t)sc, PZERO+1);
	splx(s);
	if (sc->sc_state != OPEN && sc->sc_state != OPENRAW)
		if (error = hpinit(dev, flags))
			return (error);
	if (part >= lp->d_npartitions)
		return (ENXIO);
E 133
E 84
	/*
D 95
	 * Model-byte processing for SI 9400 controllers.
E 95
I 95
D 133
	 * Model-byte processing for SI controllers.
E 95
	 * NB:  Only deals with RM03 and RM05 emulations.
E 133
I 133
	 * Warn if a partion is opened
	 * that overlaps another partition which is open
	 * unless one is the "raw" partition (whole disk).
E 133
	 */
D 84
	case HPDT_RM03:
	case HPDT_RM05: {
		register int hpsn;
E 84
I 84
D 133
	if (type == HPDT_RM03 || type == HPDT_RM05) {
		int hpsn = hpaddr->hpsn;
E 84

D 84
		hpsn = hpaddr->hpsn;
E 84
		if ((hpsn & SIMB_LU) != mi->mi_drive)
D 84
			break;
E 84
I 84
			return (type);
E 84
		switch ((hpsn & SIMB_MB) & ~(SIMB_S6|SIRM03|SIRM05)) {

		case SI9775D:
D 95
			printf("hp%d: si 9775 (direct)\n", mi->mi_unit);
E 95
I 95
			printf("hp%d: 9775 (direct)\n", mi->mi_unit);
E 95
D 84
			mi->mi_type = HPDT_9775;
E 84
I 84
			type = HPDT_9775;
E 84
			break;

		case SI9730D:
D 95
			printf("hp%d: si 9730 (direct)\n", mi->mi_unit);
E 95
I 95
			printf("hp%d: 9730 (direct)\n", mi->mi_unit);
E 95
D 84
			mi->mi_type = HPDT_9730;
E 84
I 84
			type = HPDT_9730;
E 84
			break;

D 81
#ifdef CAD
E 81
I 68
D 130
		/*
D 84
		 * AMPEX 9300, SI Combination needs a have the drive cleared
		 * before we start.  We do not know why, but tests show
		 * that the recalibrate fixes the problem.
E 84
I 84
D 95
		 * AMPEX 9300, SI Combination needs a have the
		 * drive cleared before we start.  We do not know
		 * why, but tests show that the recalibrate fixes
		 * the problem.
E 95
I 95
		 * Beware, since the only SI controller we
		 * have has a 9300 instead of a 9766, we map the
		 * drive type into the 9300.  This means that
		 * on a 9766 you lose the last 8 cylinders (argh).
E 95
E 84
		 */
E 130
E 68
		case SI9766:
D 95
			printf("hp%d: 9776/9300\n", mi->mi_unit);
D 84
			mi->mi_type = HPDT_RM05;
E 84
I 84
			type = HPDT_RM05;
E 84
I 68
			hpaddr->hpcs1 = HP_RECAL|HP_GO;
			DELAY(100000);
E 95
I 95
D 130
			printf("hp%d: 9300\n", mi->mi_unit);
			type = HPDT_9300;
E 130
I 130
			printf("hp%d: 9766\n", mi->mi_unit);
			type = HPDT_RM05;
E 130
E 95
E 68
			break;

		case SI9762:
			printf("hp%d: 9762\n", mi->mi_unit);
D 84
			mi->mi_type = HPDT_RM03;
E 84
I 84
			type = HPDT_RM03;
I 95
			break;

		case SICAPD:
			printf("hp%d: capricorn\n", mi->mi_unit);
			type = HPDT_CAPRICORN;
			break;

		case SI9751D:
			printf("hp%d: eagle\n", mi->mi_unit);
			type = HPDT_EAGLE;
E 95
E 84
			break;
E 133
I 133
#define	RAWPART		2		/* 'c' partition */	/* XXX */
D 138
	if ((sc->sc_openpart & (1 << part)) == 0 &&
	    part != RAWPART) {
E 138
I 138
	if ((sc->sc_openpart & mask) == 0 && part != RAWPART) {
E 138
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
			if (sc->sc_openpart & (1 << (pp - lp->d_partitions)))
				log(LOG_WARNING,
				    "hp%d%c: overlaps open partition (%c)\n",
				    unit, part + 'a',
				    pp - lp->d_partitions + 'a');
E 133
D 81
#endif
E 81
		}
D 84
		break;
		}
E 84
I 84
D 133
		return (type);
E 133
	}
I 133
D 135
	sc->sc_openpart |= 1 << part;
E 135
I 135
	switch (fmt) {
	case S_IFCHR:
		sc->sc_copenpart |= mask;
		break;
	case S_IFBLK:
		sc->sc_bopenpart |= mask;
		break;
	}
	sc->sc_openpart |= mask;
E 135
	return (0);
}
E 133
E 84

I 141
/* ARGSUSED */
E 141
I 133
D 135
hpclose(dev, flags)
E 135
I 135
hpclose(dev, flags, fmt)
E 135
	dev_t dev;
D 135
	int flags;
E 135
I 135
	int flags, fmt;
E 135
{
	register int unit = hpunit(dev);
	register struct hpsoftc *sc;
	struct mba_device *mi;
D 135
	int s;
E 135
I 135
	int s, mask = 1 << hppart(dev);
E 135

	sc = &hpsoftc[unit];
	mi = hpinfo[unit];
D 135
	sc->sc_openpart &= ~(1 << hppart(dev));
#ifdef notdef
E 135
I 135
	switch (fmt) {
	case S_IFCHR:
		sc->sc_copenpart &= ~mask;
		break;
	case S_IFBLK:
		sc->sc_bopenpart &= ~mask;
		break;
	}
D 139
	if (((sc->sc_copenpart | sc->sc_bopenpart) & mask) == 0)
		sc->sc_openpart &= ~mask;
E 139
I 139
	sc->sc_openpart = sc->sc_copenpart | sc->sc_bopenpart;

E 139
E 135
E 133
	/*
D 84
	 * CAPRICORN KLUDGE...poke the holding register
D 78
	 * to find out the number of tracks.  If it's 15
	 * we believe it's a Capricorn.
E 78
I 78
	 * we believe it's a Capricorn.  Otherwise assume
	 * its an Eagle.
E 84
I 84
D 133
	 * EMULEX SC750 or SC780.  Poke the holding register.
E 133
I 133
	 * Should wait for I/O to complete on this partition
	 * even if others are open, but wait for work on blkflush().
E 133
E 84
E 78
	 */
D 84
	case HPDT_RM02:
E 84
I 84
D 133
	if (type == HPDT_RM02) {
D 130
		int ntracks, nsectors;
E 130
I 130
		int nsectors, ntracks, ncyl;
E 133
I 133
	if (sc->sc_openpart == 0) {
		s = spl5();
D 135
		/* Can't sleep on b_actf, it might be async. */
E 135
		while (mi->mi_tab.b_actf)
D 135
			sleep((caddr_t)&mi->mi_tab.b_actf, PZERO - 1);
E 135
I 135
			sleep((caddr_t)sc, PZERO - 1);
E 135
		splx(s);
		sc->sc_state = CLOSED;
I 139
		sc->sc_wlabel = 0;
E 139
	}
D 135
#endif
E 135
I 135
	return (0);
E 135
}
E 133
E 130

I 96
D 133
		hpaddr->hpof = HPOF_FMT22;
		mbclrattn(mi);
E 96
E 84
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXTRAK;
D 70
		if (hpaddr->hphr == 15) {
E 70
I 70
D 80
		if ((hpaddr->hphr&0xffff) == 15) {
E 80
I 80
D 92
		ntracks = (hpaddr->hphr & 0xffff) + 1;
E 92
I 92
		ntracks = MASKREG(hpaddr->hphr) + 1;
E 92
D 130
		if (ntracks == 16) {
E 80
E 70
			printf("hp%d: capricorn\n", mi->mi_unit);
D 84
			mi->mi_type = HPDT_CAPRICORN;
I 78
D 80
		} else {
E 80
I 80
		} else if (ntracks == 20) {
E 80
			printf("hp%d: eagle\n", mi->mi_unit);
			mi->mi_type = HPDT_EAGLE;
E 78
D 80
		}
E 80
I 80
		} else
E 84
I 84
			type = HPDT_CAPRICORN;
			goto done;
		}
I 102
		if (ntracks == 19) {
			printf("hp%d: 9300\n", mi->mi_unit);
			type = HPDT_9300;
			goto done;
		}
E 130
I 130
		DELAY(100);
E 130
E 102
D 96
		if (ntracks != 20) {
E 84
			printf("hp%d: ntracks %d: unknown device\n", ntracks);
I 84
			goto done;
		}
E 96
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXSECT;
D 92
		nsectors = (hpaddr->hphr & 0xffff) + 1;
E 92
I 92
		nsectors = MASKREG(hpaddr->hphr) + 1;
E 92
D 94
		printf("hp%d: ", mi->mi_unit);
		if (nsectors == 43)
E 94
I 94
D 96
		if (nsectors == 48) {
E 96
I 96
D 130
		if (ntracks == 20 && nsectors == 48) {
E 96
E 94
			type = HPDT_EAGLE;
D 94
		else {
			type = HPDT_EAGLE48;
			printf("modified ");
E 94
I 94
			printf("hp%d: eagle\n", mi->mi_unit);
I 96
			goto done;
E 130
I 130
		DELAY(100);
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXCYL;
		ncyl = MASKREG(hpaddr->hphr) + 1;
		for (type = 0; hptypes[type] != 0; type++)
			if (hpst[type].nsect == nsectors &&
			    hpst[type].ntrak == ntracks &&
			    hpst[type].ncyl == ncyl)
				break;
E 133
I 133
hpinit(dev, flags)
	dev_t dev;
	int flags;
{
	register struct hpsoftc *sc;
	register struct buf *bp;
	register struct disklabel *lp;
D 135
	struct disklabel *dlp;
E 135
	struct mba_device *mi;
	struct hpdevice *hpaddr;
	struct dkbad *db;
I 135
	char *msg, *readdisklabel();
E 135
	int unit, i, error = 0;
I 134
D 139
	extern int cold;
E 139
E 134
E 133

D 133
		if (hptypes[type] == 0) {
	printf("hp%d: %d sectors, %d tracks, %d cylinders: unknown device\n",
				mi->mi_unit, nsectors, ntracks, ncyl);
			type = HPDT_RM02;
E 130
E 96
E 94
		}
I 96
D 130
		printf("hp%d: ntracks %d, nsectors %d: unknown device\n",
D 102
			ntracks, nsectors);
E 102
I 102
			mi->mi_unit, ntracks, nsectors);
E 102
E 96
D 94
		printf("eagle\n");
E 94
done:
E 130
I 130
		printf("hp%d: %s\n", mi->mi_unit, hpst[type].name);
E 130
E 84
E 80
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
I 96
		mbclrattn(mi);		/* conservative */
E 96
D 84
		break;
E 84
I 84
		return (type);
D 130
	} 
E 130
I 130
	}
E 133
I 133
	unit = hpunit(dev);
	sc = &hpsoftc[unit];
	lp = &hplabel[unit];
	mi = hpinfo[unit];
	hpaddr = (struct hpdevice *)mi->mi_drv;
E 133
E 130
E 84

I 133
D 136
	if (flags & O_NDELAY)
		sc->sc_state = WANTOPENRAW;
	else
		sc->sc_state = WANTOPEN;
E 136
I 136
	sc->sc_state = WANTOPEN;
E 136
E 133
D 84
	case HPDT_ML11A:
	case HPDT_ML11B: {
E 84
I 84
	/*
I 133
	 * Use the default sizes until we've read the label,
	 * or longer if there isn't one there.
	 */
D 139
	lp->d_secsize = DEV_BSIZE;
	lp->d_nsectors = 32;
	lp->d_ntracks = 20;
	lp->d_secpercyl = 32*20;
E 139
I 139
	if (lp->d_secpercyl == 0) {
		lp->d_secsize = DEV_BSIZE;
		lp->d_nsectors = 32;
		lp->d_ntracks = 20;
		lp->d_secpercyl = 32*20;
I 144
		lp->d_npartitions = 1;
		lp->d_partitions[0].p_offset = 0;
		lp->d_partitions[0].p_size = LABELSECTOR + 1;
E 144
	}
E 139
D 135
	lp->d_secperunit = 0x1fffffff;
	lp->d_npartitions = 1;
	lp->d_partitions[0].p_size = 0x1fffffff;
	lp->d_partitions[0].p_offset = 0;
E 135

I 136
	if (flags & O_NDELAY)
		goto raw;

E 136
	/*
E 133
	 * Map all ML11's to the same type.  Also calculate
	 * transfer rates based on device characteristics.
I 133
	 * Set up dummy label with all that's needed.
E 133
	 */
D 133
	if (type == HPDT_ML11A || type == HPDT_ML11B) {
E 133
I 133
	if (mi->mi_type == MBDT_ML11A || mi->mi_type == MBDT_ML11B) {
E 133
E 84
E 67
D 86
		register int trt, sz;
E 86
I 86
D 140
		register struct hpsoftc *sc = &hpsoftc[mi->mi_unit];
E 140
		register int trt;
E 86
E 64

D 64
	if (mi->mi_dk >= 0)
E 64
I 64
D 86
		sz = hpaddr->hpmr & HPMR_SZ;
E 86
I 86
		sc->sc_mlsize = hpaddr->hpmr & HPMR_SZ;
E 86
		if ((hpaddr->hpmr & HPMR_ARRTYP) == 0)
D 86
			sz >>= 2;
		mlsize[mi->mi_unit] = sz;
E 86
I 86
			sc->sc_mlsize >>= 2;
E 86
		if (mi->mi_dk >= 0) {
			trt = (hpaddr->hpmr & HPMR_TRT) >> 8;
			dk_mspw[mi->mi_dk] = 1.0 / (1<<(20-trt));
		}
D 67
	} else if (mi->mi_dk >= 0) {
E 67
I 67
D 84
		/* A CHEAT - ML11B D.T. SHOULD == ML11A */
		mi->mi_type = HPDT_ML11A;
		break;
		}
E 84
I 84
D 133
		type = HPDT_ML11A;
E 133
I 133
		mi->mi_type = MBDT_ML11A;
		lp->d_partitions[0].p_size = sc->sc_mlsize;
		lp->d_secpercyl = sc->sc_mlsize;
D 136
		sc->sc_state = WANTOPENRAW;
E 136
I 136
		goto raw;
E 136
E 133
E 84
	}
D 84
	if (!ML11 && mi->mi_dk >= 0) {
E 67
		register struct hpst *st = &hpst[mi->mi_type];

E 64
D 35
		dk_mspw[mi->mi_dk] = 1.0 / HZ / (st->nsect * 256);
E 35
I 35
		dk_mspw[mi->mi_dk] = 1.0 / 60 / (st->nsect * 256);
I 64
	}
E 84
I 84
D 133
	return (type);
E 84
E 64
E 35
}
E 133

I 76
D 133
hpopen(dev)
	dev_t dev;
{
D 119
	register int unit = minor(dev) >> 3;
E 119
I 119
	register int unit = hpunit(dev);
E 119
	register struct mba_device *mi;
E 133
I 133
	/*
	 * Preset, pack acknowledge will be done in hpstart
	 * during first read operation.
	 */
D 135
	bp = geteblk(DEV_BSIZE);		/* max sector size */
	bp->b_dev = dev;
	bp->b_blkno = LABELSECTOR;
	bp->b_bcount = DEV_BSIZE;
	bp->b_flags = B_BUSY | B_READ;
	hpstrategy(bp);
	biowait(bp);
	if (bp->b_flags & B_ERROR) {
		error = u.u_error;		/* XXX */
		u.u_error = 0;
		sc->sc_state = CLOSED;
		goto done;
	}
	if (sc->sc_state == OPENRAW)
		goto done;
E 133

D 133
	if (unit >= NHP || (mi = hpinfo[unit]) == 0 || mi->mi_alive == 0)
		return (ENXIO);
	return (0);
E 133
I 133
	dlp = (struct disklabel *)(bp->b_un.b_addr + LABELOFFSET);
	if (dlp->d_magic == DISKMAGIC &&
	    dlp->d_magic2 == DISKMAGIC && dkcksum(dlp) == 0) {
		*lp = *dlp;
	} else {
E 135
I 135
	if (msg = readdisklabel(dev, hpstrategy, lp)) {
D 136
		if (sc->sc_state == OPENRAW)
			goto done;
E 136
E 135
D 134
		log(LOG_ERR, "hp%d: no disk label\n", unit);
E 134
I 134
		if (cold)
D 135
			printf(": no disk label");
E 135
I 135
			printf(": %s", msg);
E 135
		else
D 135
			log(LOG_ERR, "hp%d: no disk label\n", unit);
E 135
I 135
			log(LOG_ERR, "hp%d: %s\n", unit, msg);
E 135
E 134
#ifdef COMPAT_42
D 139
		mi->mi_type = hpmaptype(mi, lp);
#else
D 136
		sc->sc_state = OPENRAW;
		goto done;
E 136
I 136
		goto raw;
E 139
I 139
D 147
		if ((mi->mi_type = hpmaptype(mi, lp)) == 0)
E 147
I 147
		if (hpmaptype(mi, lp) == 0)
E 147
E 139
E 136
#endif
I 139
		goto raw;
E 139
	}

	/*
	 * Seconds per word = (60 / rpm) / (nsectors * secsize/2)
	 */
	if (mi->mi_dk >= 0 && lp->d_rpm)
		dk_mspw[mi->mi_dk] = 120.0 /
		    (lp->d_rpm * lp->d_nsectors * lp->d_secsize);
	/*
	 * Read bad sector table into memory.
	 */
I 135
	bp = geteblk(DEV_BSIZE);		/* max sector size */
	bp->b_dev = dev;
E 135
	sc->sc_state = RDBADTBL;
	i = 0;
	do {
		u.u_error = 0;				/* XXX */
		bp->b_flags = B_BUSY | B_READ;
		bp->b_blkno = lp->d_secperunit - lp->d_nsectors + i;
		bp->b_bcount = lp->d_secsize;
		bp->b_cylin = lp->d_ncylinders - 1;
		hpstrategy(bp);
		biowait(bp);
	} while ((bp->b_flags & B_ERROR) && (i += 2) < 10 &&
	    i < lp->d_nsectors);
	db = (struct dkbad *)(bp->b_un.b_addr);
	if ((bp->b_flags & B_ERROR) == 0 && db->bt_mbz == 0 &&
	    db->bt_flag == 0) {
		hpbad[unit] = *db;
D 139
		sc->sc_state = OPEN;
E 139
	} else {
		log(LOG_ERR, "hp%d: %s bad-sector file\n", unit,
		    (bp->b_flags & B_ERROR) ? "can't read" : "format error in");
		u.u_error = 0;				/* XXX */
D 139
		sc->sc_state = OPENRAW;
E 139
	}
I 139
	sc->sc_state = OPEN;
E 139
D 135
done:
E 135
	bp->b_flags = B_INVAL | B_AGE;
	brelse(bp);
I 135
D 141
done:
E 141
I 136
	wakeup((caddr_t)sc);
	return (error);

raw:
D 139
	sc->sc_state = OPENRAW;
E 136
E 135
	wakeup((caddr_t)sc);
E 139
I 139
	if (cold)
		sc->sc_state = CLOSED;
	else {
		sc->sc_state = OPENRAW;
		wakeup((caddr_t)sc);
	}
E 139
	return (error);
E 133
}

E 76
E 29
hpstrategy(bp)
D 26
register struct buf *bp;
E 26
I 26
	register struct buf *bp;
E 26
{
D 26
	register struct buf *dp;
	register unit, xunit, nspc;
E 26
I 26
D 43
	register struct mba_info *mi;
E 43
I 43
	register struct mba_device *mi;
E 43
D 133
	register struct hpst *st;
E 133
I 133
	register struct disklabel *lp;
	register struct hpsoftc *sc;
E 133
	register int unit;
E 26
D 121
	long sz, bn;
E 121
I 121
D 133
	long sz;
E 121
D 26
	struct size *sizes;
E 26
I 26
	int xunit = minor(bp->b_dev) & 07;
E 133
I 133
	daddr_t sz, maxsz;
	int xunit = hppart(bp->b_dev);
E 133
I 62
	int s;
E 62
E 26

I 9
D 26
	if ((mbaact&(1<<HPMBANUM)) == 0)
		mbainit(HPMBANUM);
E 9
	xunit = minor(bp->b_dev) & 077;
E 26
D 133
	sz = bp->b_bcount;
	sz = (sz+511) >> 9;
E 133
I 133
	sz = (bp->b_bcount + DEV_BSIZE - 1) >> DEV_BSHIFT;
E 133
D 119
	unit = dkunit(bp);
D 26
	if (hp_type[unit] == 0) {
		struct device *hpaddr;
I 15
		double mspw;
E 15

		/* determine device type */
D 9
		hpaddr = (struct device *)((int*)HPADDR + 32*unit);
E 9
I 9
		hpaddr = mbadev(HPMBA, unit);
E 9
D 15
		hp_type[unit] = hpaddr->hpdt;
E 15
I 15

		/* record transfer rate (these are guesstimates secs/word) */
		switch (hp_type[unit] = hpaddr->hpdt) {
		case RM:	mspw = .0000019728; break;
		case RM5:	mspw = .0000020345; break;
		case RP:	mspw = .0000029592; break;
		}
D 22
		if (DK_N + unit <= DK_NMAX)
			dk_mspw[DK_N+unit] = mspw;
E 22
I 22
		if (HPDK_N + unit <= HPDK_NMAX)
			dk_mspw[HPDK_N+unit] = mspw;
E 22
E 15
	}
D 11
	if (hp_type[unit] == RM) {
E 11
I 11
	switch (hp_type[unit]) {

	case RM:
E 11
		sizes = rm_sizes;
		nspc = NRMSECT*NRMTRAC;
D 11
	} else {
E 11
I 11
		break;
	case RM5:
		sizes = rm5_sizes;
		nspc = NRMSECT*NTRAC;
		break;
	case RP:
E 11
		sizes = hp_sizes;
		nspc = NSECT*NTRAC;
I 11
		break;
	default:
		printf("hp: unknown device type 0%o\n", hp_type[unit]);
		u.u_error = ENXIO;
		unit = NHP+1;	/* force error */
E 11
	}
	if (unit >= NHP ||
	    bp->b_blkno < 0 ||
	    (bn = dkblock(bp))+sz > sizes[xunit&07].nblocks) {
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
	}
	bp->b_cylin = bn/nspc + sizes[xunit&07].cyloff;
	dp = &hputab[unit];
E 26
I 26
	if (unit >= NHP)
E 119
I 119
	unit = hpunit(bp->b_dev);
	if (unit >= NHP) {
		bp->b_error = ENXIO;
E 119
		goto bad;
I 119
	}
E 119
	mi = hpinfo[unit];
I 133
	sc = &hpsoftc[unit];
	lp = &hplabel[unit];
E 133
D 27
	if (mi->mi_alive == 0)
E 27
I 27
D 119
	if (mi == 0 || mi->mi_alive == 0)
E 119
I 119
	if (mi == 0 || mi->mi_alive == 0) {
		bp->b_error = ENXIO;
E 119
E 27
		goto bad;
I 119
	}
I 139
#ifdef COMPAT_42
	if (sc->sc_hdr) {				/* XXX */
		if (bp->b_bcount == 516)
			bp->b_flags |= B_FORMAT;
		sc->sc_hdr = 0;
	}
#endif
E 139
E 119
D 133
	st = &hpst[mi->mi_type];
D 64
	if (bp->b_blkno < 0 ||
	    (bn = dkblock(bp))+sz > st->sizes[xunit].nblocks)
		goto bad;
	bp->b_cylin = bn/st->nspc + st->sizes[xunit].cyloff;
E 64
I 64
	if (ML11) {
I 86
		struct hpsoftc *sc = &hpsoftc[unit];

E 86
		if (bp->b_blkno < 0 ||
D 86
		    dkblock(bp)+sz > mlsize[mi->mi_unit])
E 86
I 86
D 119
		    dkblock(bp)+sz > sc->sc_mlsize)
E 119
I 119
		    bp->b_blkno+sz > sc->sc_mlsize) {
D 121
			if (bp->b_blkno == sc->sc_mlsize + 1)
E 121
I 121
			if (bp->b_blkno == sc->sc_mlsize) {
			    bp->b_resid = bp->b_bcount;
E 121
			    goto done;
I 121
			}
E 121
			bp->b_error = EINVAL;
E 119
E 86
			goto bad;
E 133
I 133
	if (sc->sc_state < OPEN)
		goto q;
I 139
	if (sc->sc_state != OPEN && (bp->b_flags & B_READ) == 0) {
		bp->b_error = EROFS;
		goto bad;
	}
E 139
	if ((sc->sc_openpart & (1 << xunit)) == 0) {
		bp->b_error = ENODEV;
		goto bad;
	}
	maxsz = lp->d_partitions[xunit].p_size;
I 139
	if (bp->b_blkno + lp->d_partitions[xunit].p_offset <= LABELSECTOR &&
#if LABELSECTOR != 0
	    bp->b_blkno + lp->d_partitions[xunit].p_offset + sz > LABELSECTOR &&
#endif
	    (bp->b_flags & B_READ) == 0 && sc->sc_wlabel == 0) {
		bp->b_error = EROFS;
		goto bad;
	}
E 139
	if (bp->b_blkno < 0 || bp->b_blkno + sz > maxsz) {
		if (bp->b_blkno == maxsz) {
			bp->b_resid = bp->b_bcount;
			goto done;
E 133
I 119
		}
E 119
D 133
		bp->b_cylin = 0;
	} else {
		if (bp->b_blkno < 0 ||
D 119
		    (bn = dkblock(bp))+sz > st->sizes[xunit].nblocks)
E 119
I 119
D 121
		    (bn = bp->b_blkno)+sz > st->sizes[xunit].nblocks) {
			if (bp->b_blkno == st->sizes[xunit].nblocks + 1)
E 121
I 121
		    bp->b_blkno+sz > st->sizes[xunit].nblocks) {
			if (bp->b_blkno == st->sizes[xunit].nblocks) {
			    bp->b_resid = bp->b_bcount;
E 121
			    goto done;
I 121
			}
E 133
I 133
		sz = maxsz - bp->b_blkno;
		if (sz <= 0) {
E 133
E 121
			bp->b_error = EINVAL;
E 119
			goto bad;
I 119
		}
E 119
D 121
		bp->b_cylin = bn/st->nspc + st->sizes[xunit].cyloff;
E 121
I 121
D 133
		bp->b_cylin = bp->b_blkno/st->nspc + st->sizes[xunit].cyloff;
E 133
I 133
		bp->b_bcount = sz << DEV_BSHIFT;
E 133
E 121
	}
I 133
	bp->b_cylin = (bp->b_blkno + lp->d_partitions[xunit].p_offset) /
	    lp->d_secpercyl;
q:
E 133
E 64
E 26
D 3
	VOID spl5();
E 3
I 3
D 62
	(void) spl5();
E 62
I 62
	s = spl5();
E 62
E 3
D 26
	disksort(dp, bp);
	if (dp->b_active == 0) {
		hpustart(unit);
		if(hptab.b_active == 0)
			hpstart();
	}
E 26
I 26
	disksort(&mi->mi_tab, bp);
	if (mi->mi_tab.b_active == 0)
		mbustart(mi);
E 26
D 3
	VOID spl0();
E 3
I 3
D 62
	(void) spl0();
E 62
I 62
	splx(s);
E 62
I 26
	return;

bad:
	bp->b_flags |= B_ERROR;
I 119
done:
E 119
D 133
	iodone(bp);
E 133
I 133
	biodone(bp);
E 133
	return;
E 26
E 3
}

D 26
hpustart(unit)
register unit;
E 26
I 26
hpustart(mi)
D 43
	register struct mba_info *mi;
E 43
I 43
	register struct mba_device *mi;
E 43
E 26
{
D 26
	register struct buf *bp, *dp;
	register struct device *hpaddr;
E 26
I 26
D 31
	register struct device *hpaddr = (struct device *)mi->mi_drv;
E 31
I 31
	register struct hpdevice *hpaddr = (struct hpdevice *)mi->mi_drv;
E 31
	register struct buf *bp = mi->mi_tab.b_actf;
D 56
	register struct hpst *st;
E 56
I 56
D 96
	register struct hpst *st = &hpst[mi->mi_type];
E 96
I 96
D 133
	register struct hpst *st;
E 133
I 133
	register struct disklabel *lp;
E 133
E 96
I 86
	struct hpsoftc *sc = &hpsoftc[mi->mi_unit];
E 86
E 56
E 26
	daddr_t bn;
D 23
	int sn, cn, csn;
E 23
I 23
D 26
	int sn, cn, csn, ns;
E 26
I 26
D 45
	int sn, dist, flags;
E 45
I 45
D 111
	int sn, dist;
E 111
I 111
	int sn, tn, dist;
E 111
E 45
E 26
E 23

I 96
D 133
	st = &hpst[mi->mi_type];
E 133
I 133
	lp = &hplabel[mi->mi_unit];
E 133
E 96
I 56
	hpaddr->hpcs1 = 0;
E 56
D 19
	((struct mba_regs *)MBA0)->mba_cr |= MBAIE;
E 19
I 19
D 26
	((struct mba_regs *)HPMBA)->mba_cr |= MBAIE;
E 19
D 9
	HPADDR->hpas = 1<<unit;
E 9
I 9
	hpaddr = mbadev(HPMBA, 0);
	hpaddr->hpas = 1<<unit;
E 9

	if(unit >= NHP)
		return;
D 8
/*
	dk_busy &= ~(1<<(unit+DK_N));
*/
E 8
I 8
D 22
	if (unit+DK_N <= DK_NMAX)
		dk_busy &= ~(1<<(unit+DK_N));
E 22
I 22
	if (unit+HPDK_N <= HPDK_NMAX)
		dk_busy &= ~(1<<(unit+HPDK_N));
E 22
E 8
	dp = &hputab[unit];
	if((bp=dp->b_actf) == NULL)
		return;
D 9
	hpaddr = (struct device *)((int *)HPADDR + 32*unit);
E 9
I 9
	hpaddr = mbadev(HPMBA, unit);
E 9
	if((hpaddr->hpds & VV) == 0) {
E 26
I 26
D 31
	if ((hpaddr->hpcs1&DVA) == 0)
E 31
I 31
	if ((hpaddr->hpcs1&HP_DVA) == 0)
E 31
		return (MBU_BUSY);
I 123

	switch (sc->sc_recal) {

	case 1:
D 128
		HPWAIT(mi, hpaddr);
E 128
I 128
		(void)HPWAIT(mi, hpaddr);
E 128
		hpaddr->hpdc = bp->b_cylin;
		hpaddr->hpcs1 = HP_SEEK|HP_GO;
		sc->sc_recal++;
		return (MBU_STARTED);
	case 2:
		break;
	}
	sc->sc_recal = 0;
E 123
D 31
	if ((hpaddr->hpds & VV) == 0) {
E 26
I 23
		hpaddr->hpcs1 = DCLR|GO;
E 23
		hpaddr->hpcs1 = PRESET|GO;
		hpaddr->hpof = FMT22;
E 31
I 31
D 44
	if ((hpaddr->hpds & HP_VV) == 0) {
E 44
I 44
D 56
	if ((hpaddr->hpds & HPDS_VV) == 0) {
E 56
I 56
D 86
	if ((hpaddr->hpds & HPDS_VV) == 0 || hpinit[mi->mi_unit] == 0) {
E 86
I 86
D 133
	if ((hpaddr->hpds & HPDS_VV) == 0 || !sc->sc_hpinit) {
E 86
D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
		struct buf *bbp = &bhpbuf[mi->mi_unit];
D 85
#endif
E 85

D 86
		hpinit[mi->mi_unit] = 1;
E 86
I 86
		sc->sc_hpinit = 1;
E 133
I 133
	if ((hpaddr->hpds & HPDS_VV) == 0) {
		if (sc->sc_state == OPEN && lp->d_flags & D_REMOVABLE) {
			if (sc->sc_openpart)
				log(LOG_ERR, "hp%d: volume changed\n",
				    mi->mi_unit);
			sc->sc_openpart = 0;
			bp->b_flags |= B_ERROR;
			return (MBU_NEXT);
		}
E 133
E 86
E 56
E 44
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
I 47
		if (mi->mi_mba->mba_drv[0].mbd_as & (1<<mi->mi_drive))
			printf("DCLR attn\n");
E 47
		hpaddr->hpcs1 = HP_PRESET|HP_GO;
D 44
		hpaddr->hpof = HP_FMT22;
E 44
I 44
D 64
		hpaddr->hpof = HPOF_FMT22;
E 64
I 64
D 133
		if (!ML11)
E 133
I 133
		if (!ML11(mi->mi_type))
E 133
			hpaddr->hpof = HPOF_FMT22;
E 64
I 47
		mbclrattn(mi);
I 56
D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
D 64
		bbp->b_flags = B_READ|B_BUSY;
		bbp->b_dev = bp->b_dev;
		bbp->b_bcount = 512;
		bbp->b_un.b_addr = (caddr_t)&hpbad[mi->mi_unit];
		bbp->b_blkno = st->ncyl*st->nspc - st->nsect;
		bbp->b_cylin = st->ncyl - 1;
		mi->mi_tab.b_actf = bbp;
		bbp->av_forw = bp;
		bp = bbp;
E 64
I 64
D 133
		if (!ML11) {
			bbp->b_flags = B_READ|B_BUSY;
			bbp->b_dev = bp->b_dev;
			bbp->b_bcount = 512;
			bbp->b_un.b_addr = (caddr_t)&hpbad[mi->mi_unit];
			bbp->b_blkno = st->ncyl*st->nspc - st->nsect;
			bbp->b_cylin = st->ncyl - 1;
			mi->mi_tab.b_actf = bbp;
			bbp->av_forw = bp;
			bp = bbp;
E 133
I 133
		if (sc->sc_state == WANTOPENRAW) {
			sc->sc_state = OPENRAW;
			return (MBU_NEXT);
E 133
		}
I 133
		if (sc->sc_state == WANTOPEN)
			sc->sc_state = RDLABEL;
E 133
E 64
D 85
#endif
E 85
E 56
E 47
E 44
E 31
	}
D 26
	if(dp->b_active)
		goto done;
	dp->b_active++;
E 26
I 26
D 29
	if (mi->mi_tab.b_active)
E 29
I 29
D 123
	if (mi->mi_tab.b_active || mi->mi_hd->mh_ndrive == 1)
E 123
I 123
	if (mi->mi_tab.b_active || mi->mi_hd->mh_ndrive == 1) {
		if (mi->mi_tab.b_errcnt >= 16 && (bp->b_flags & B_READ)) {
			hpaddr->hpof =
			    hp_offset[mi->mi_tab.b_errcnt & 017]|HPOF_FMT22;
			hpaddr->hpcs1 = HP_OFFSET|HP_GO;
D 128
			HPWAIT(mi, hpaddr);
E 128
I 128
			(void)HPWAIT(mi, hpaddr);
E 128
			mbclrattn(mi);
		}
E 123
E 29
		return (MBU_DODATA);
I 123
	}
E 123
I 64
D 133
	if (ML11)
E 133
I 133
	if (ML11(mi->mi_type))
E 133
		return (MBU_DODATA);
E 64
E 26
D 31
	if ((hpaddr->hpds & (DPR|MOL)) != (DPR|MOL))
E 31
I 31
D 44
	if ((hpaddr->hpds & (HP_DPR|HP_MOL)) != (HP_DPR|HP_MOL))
E 44
I 44
	if ((hpaddr->hpds & HPDS_DREADY) != HPDS_DREADY)
E 44
E 31
D 26
		goto done;

I 23
#if NHP > 1
E 23
	bn = dkblock(bp);
	cn = bp->b_cylin;
D 11
	if(hp_type[unit] == RM) {
E 11
I 11
	switch (hp_type[unit]) {

	case RM:
E 11
		sn = bn%(NRMSECT*NRMTRAC);
D 5
		sn = (sn+NRMSECT-SDIST)%NRMSECT;
E 5
I 5
		sn = (sn+NRMSECT-hpSDIST)%NRMSECT;
I 23
		ns = NRMSECT;
E 23
E 5
D 11
	} else {
E 11
I 11
		break;
	case RM5:
		sn = bn%(NRMSECT*NTRAC);
		sn = (sn+NRMSECT-hpSDIST)%NRMSECT;
I 23
		ns = NRMSECT;
E 23
		break;
	case RP:
E 11
		sn = bn%(NSECT*NTRAC);
D 5
		sn = (sn+NSECT-SDIST)%NSECT;
E 5
I 5
		sn = (sn+NSECT-hpSDIST)%NSECT;
I 23
		ns = NSECT;
E 23
I 11
		break;
	default:
		panic("hpustart");
E 26
I 26
		return (MBU_DODATA);
D 27
	hpaddr->hpdc = bp->b_cylin;
	flags = mi->mi_hd->mh_flags;
E 27
D 29
	if (flags&MH_NOSEEK)
		return (MBU_DODATA);
E 29
I 27
D 30
	hpaddr->hpdc = bp->b_cylin;
E 30
D 56
	st = &hpst[mi->mi_type];
E 56
D 119
	bn = dkblock(bp);
E 119
I 119
	bn = bp->b_blkno;
E 119
D 111
	sn = bn%st->nspc;
E 111
I 111
D 133
	sn = bn % st->nspc;
	tn = sn / st->nsect;
	sn = sn % st->nsect;
E 133
I 133
	sn = bn % lp->d_secpercyl;
	tn = sn / lp->d_nsectors;
	sn = sn % lp->d_nsectors;
E 133
E 111
D 101
	sn = (sn+st->nsect-hpSDIST)%st->nsect;
E 101
I 101
D 110
	sn = (sn + st->nsect - st->sdist) % st->nsect;
E 110
E 101
D 29
	flags = mi->mi_hd->mh_flags;
E 29
E 27
D 92
	if (bp->b_cylin == (hpaddr->hpdc & 0xffff)) {
E 92
I 92
	if (bp->b_cylin == MASKREG(hpaddr->hpdc)) {
E 92
D 29
		if (flags&MH_NOSEARCH)
E 29
I 29
D 86
		if (hpseek)
E 86
I 86
D 90
		if (sc->sc_seek)
E 90
I 90
		if (sc->sc_doseeks)
E 90
E 86
E 29
			return (MBU_DODATA);
D 27
		bn = dkblock(bp);
		st = &hpst[mi->mi_type];
		sn = bn%st->nspc;
		sn = (sn+st->nsect-hpSDIST)%st->nsect;
E 27
D 92
		dist = ((hpaddr->hpla & 0xffff)>>6) - st->nsect + 1;
E 92
I 92
D 110
		dist = (MASKREG(hpaddr->hpla) >> 6) - st->nsect + 1;
E 110
I 110
		dist = sn - (MASKREG(hpaddr->hpla) >> 6) - 1;
E 110
E 92
		if (dist < 0)
D 133
			dist += st->nsect;
D 101
		if (dist > st->nsect - hpRDIST)
E 101
I 101
D 110
		if (dist > st->nsect - st->rdist)
E 110
I 110
		if (dist > st->maxdist || dist < st->mindist)
E 133
I 133
			dist += lp->d_nsectors;
D 137
		if (dist > lp->d_maxdist || dist < lp->d_mindist)
E 137
I 137
		if (dist <= lp->d_maxdist && dist >= lp->d_mindist)
E 137
E 133
E 110
E 101
			return (MBU_DODATA);
E 26
E 11
E 5
D 30
	}
E 30
I 30
	} else
		hpaddr->hpdc = bp->b_cylin;
E 30
D 26

	if(cn - (hpaddr->hpdc & 0xffff))
		goto search;
D 5
	csn = ((hpaddr->hpla & 0xffff)>>6) - sn + SDIST - 1;
E 5
I 5
	else if (hpseek)
		goto done;
	csn = ((hpaddr->hpla & 0xffff)>>6) - sn + 1;
E 5
	if(csn < 0)
D 23
		csn += NSECT;
D 5
	if(csn > NSECT-RDIST)
E 5
I 5
	if(csn > NSECT-hpRDIST)
E 23
I 23
		csn += ns;
	if(csn > ns-hpRDIST)
E 23
E 5
		goto done;

search:
	hpaddr->hpdc = cn;
D 5
	hpaddr->hpda = sn;
	hpaddr->hpcs1 = SEARCH|GO;
E 5
I 5
	if (hpseek)
E 26
I 26
D 29
	if (flags&MH_NOSEARCH)
E 29
I 29
D 86
	if (hpseek)
E 86
I 86
D 90
	if (sc->sc_seek)
E 90
I 90
	if (sc->sc_doseeks)
E 90
E 86
E 29
E 26
D 31
		hpaddr->hpcs1 = SEEK|GO;
E 31
I 31
		hpaddr->hpcs1 = HP_SEEK|HP_GO;
E 31
	else {
I 110
D 133
		sn = (sn + st->nsect - st->sdist) % st->nsect;
E 133
I 133
		sn = (sn + lp->d_nsectors - lp->d_sdist) % lp->d_nsectors;
E 133
E 110
D 111
		hpaddr->hpda = sn;
E 111
I 111
		hpaddr->hpda = (tn << 8) + sn;
E 111
D 31
		hpaddr->hpcs1 = SEARCH|GO;
E 31
I 31
		hpaddr->hpcs1 = HP_SEARCH|HP_GO;
E 31
	}
E 5
D 8
/*
E 8
D 22
	unit += DK_N;
D 8
	dk_busy |= 1<<unit;
	dk_numb[unit] += 1;
*/
E 8
I 8
D 15
	if (unit <= DK_NMAX && DK_N+NHP <= DK_NMAX) {
E 15
I 15
D 16
	if (unit <= DK_NMAX)
E 16
I 16
	if (unit <= DK_NMAX) {
E 22
I 22
D 26
	unit += HPDK_N;
	if (unit <= HPDK_NMAX) {
E 22
E 16
E 15
		dk_busy |= 1<<unit;
D 15
		dk_numb[unit]++;
	}
E 15
I 15
D 16
	if (DK_N+NHP <= DK_NMAX)
E 16
		dk_seek[unit]++;
I 16
	}
E 16
E 15
E 8
	return;
I 23
#endif
E 23

done:
	dp->b_forw = NULL;
	if(hptab.b_actf == NULL)
D 8
		hptab.b_actf = dp; else
E 8
I 8
		hptab.b_actf = dp;
	else
E 8
		hptab.b_actl->b_forw = dp;
	hptab.b_actl = dp;
E 26
I 26
	return (MBU_STARTED);
E 26
}

D 26
hpstart()
E 26
I 26
hpstart(mi)
D 43
	register struct mba_info *mi;
E 43
I 43
	register struct mba_device *mi;
E 43
E 26
{
D 26
	register struct buf *bp, *dp;
	register unit;
	register struct device *hpaddr;
E 26
I 26
D 31
	register struct device *hpaddr = (struct device *)mi->mi_drv;
E 31
I 31
	register struct hpdevice *hpaddr = (struct hpdevice *)mi->mi_drv;
E 31
	register struct buf *bp = mi->mi_tab.b_actf;
D 133
	register struct hpst *st = &hpst[mi->mi_type];
E 133
I 133
	register struct disklabel *lp = &hplabel[mi->mi_unit];
E 133
I 86
	struct hpsoftc *sc = &hpsoftc[mi->mi_unit];
E 86
E 26
	daddr_t bn;
D 26
	int dn, sn, tn, cn, nspc, ns;
E 26
I 26
D 123
	int sn, tn;
E 123
I 123
	int sn, tn, cn;
E 123
E 26

D 26
loop:
	if ((dp = hptab.b_actf) == NULL)
		return;
	if ((bp = dp->b_actf) == NULL) {
		hptab.b_actf = dp->b_forw;
		goto loop;
	}
	hptab.b_active++;
	unit = minor(bp->b_dev) & 077;
	dn = dkunit(bp);
E 26
D 112
	bn = dkblock(bp);
E 112
I 112
D 123
	if (bp->b_flags & B_BAD)
		bn = sc->sc_badbn;
	else
D 119
		bn = dkblock(bp) + sc->sc_pgdone;
E 119
I 119
		bn = bp->b_blkno + sc->sc_pgdone;
E 123
E 119
E 112
D 11
	if (hp_type[dn] == RM) {
E 11
I 11
D 26
	switch (hp_type[dn]) {
	case RM:
E 11
		nspc = NRMSECT*NRMTRAC;
		ns = NRMSECT;
		cn = rm_sizes[unit&07].cyloff;
D 11
	} else {
E 11
I 11
		break;
	case RM5:
		nspc = NRMSECT*NTRAC;
		ns = NRMSECT;
		cn = rm5_sizes[unit&07].cyloff;
		break;
	case RP:
E 11
		nspc = NSECT*NTRAC;
		ns = NSECT;
		cn = hp_sizes[unit&07].cyloff;
I 11
		break;
	default:
		panic("hpstart");
E 11
	}
	cn += bn/nspc;
	sn = bn%nspc;
	tn = sn/ns;
	sn = sn%ns;

D 9
	hpaddr =  (struct device *)((int *)HPADDR + 32*dn);
E 9
I 9
	hpaddr = mbadev(HPMBA, dn);
E 9
	if ((hpaddr->hpds & (DPR|MOL)) != (DPR|MOL)) {
		hptab.b_active = 0;
		hptab.b_errcnt = 0;
		dp->b_actf = bp->av_forw;
		bp->b_flags |= B_ERROR;
		iodone(bp);
		goto loop;
	}
D 13
	if(hptab.b_errcnt >= 16) {
E 13
I 13
D 14
	if(hptab.b_errcnt >= 16 && (bp->b_flags&B_WRITE)) {
E 14
I 14
D 23
	if(hptab.b_errcnt >= 16 && (bp->b_flags&B_WRITE) == 0) {
E 23
I 23
	if(hptab.b_errcnt >= 16 && (bp->b_flags&B_READ) != 0) {
E 23
E 14
E 13
		hpaddr->hpof = hp_offset[hptab.b_errcnt & 017] | FMT22;
D 9
		((struct mba_regs *)MBA0)->mba_cr &= ~MBAIE;
E 9
I 9
		HPMBA->mba_cr &= ~MBAIE;
E 26
I 26
D 64
	sn = bn%st->nspc;
	tn = sn/st->nsect;
D 27
	sn = sn%st->nsect;
E 27
I 27
	sn %= st->nsect;
E 27
D 44
	if (mi->mi_tab.b_errcnt >= 16 && (bp->b_flags&B_READ) != 0) {
D 31
		hpaddr->hpof = hp_offset[mi->mi_tab.b_errcnt & 017] | FMT22;
E 26
E 9
		hpaddr->hpcs1 = OFFSET|GO;
D 26
		while(hpaddr->hpds & PIP)
E 26
I 26
		while (hpaddr->hpds & PIP)
E 31
I 31
		hpaddr->hpof = hp_offset[mi->mi_tab.b_errcnt & 017] | HP_FMT22;
		hpaddr->hpcs1 = HP_OFFSET|HP_GO;
		while (hpaddr->hpds & HP_PIP)
E 31
E 26
			;
D 9
		((struct mba_regs *)MBA0)->mba_cr |= MBAIE;
E 9
I 9
D 26
		HPMBA->mba_cr |= MBAIE;
E 26
I 26
		mbclrattn(mi);
E 26
E 9
	}
E 44
D 26
	hpaddr->hpdc = cn;
E 26
I 26
	hpaddr->hpdc = bp->b_cylin;
E 26
	hpaddr->hpda = (tn << 8) + sn;
I 56
	return(0);
E 64
I 64
D 133
	if (ML11)
E 133
I 133
	if (ML11(mi->mi_type))
E 133
D 123
		hpaddr->hpda = bn;
E 123
I 123
		hpaddr->hpda = bp->b_blkno + sc->sc_blkdone;
E 123
	else {
D 123
		sn = bn%st->nspc;
		tn = sn/st->nsect;
E 123
I 123
		if (bp->b_flags & B_BAD) {
			bn = sc->sc_badbn;
D 133
			cn = bn / st->nspc;
E 133
I 133
			cn = bn / lp->d_secpercyl;
E 133
		} else {
			bn = bp->b_blkno;
			cn = bp->b_cylin;
		}
D 133
		sn = bn % st->nspc;
E 133
I 133
		sn = bn % lp->d_secpercyl;
E 133
		if ((bp->b_flags & B_BAD) == 0)
			sn += sc->sc_blkdone;
D 133
		tn = sn / st->nsect;
E 123
		sn %= st->nsect;
D 123
		hpaddr->hpdc = bp->b_cylin;
E 123
I 123
		cn += tn / st->ntrak;
		tn %= st->ntrak;
E 133
I 133
		tn = sn / lp->d_nsectors;
		sn %= lp->d_nsectors;
		cn += tn / lp->d_ntracks;
		tn %= lp->d_ntracks;
E 133
E 123
		hpaddr->hpda = (tn << 8) + sn;
I 123
		hpaddr->hpdc = cn;
E 123
	}
I 126
	mi->mi_tab.b_bdone = dbtob(sc->sc_blkdone);
E 126
D 86
	if (hphdr[mi->mi_unit]) {
E 86
I 86
D 133
	if (sc->sc_hdr) {
E 133
I 133
	if (bp->b_flags & B_FORMAT) {
E 133
E 86
		if (bp->b_flags & B_READ)
			return (HP_RHDR|HP_GO);
		else
			return (HP_WHDR|HP_GO);
	}
	return (0);
E 64
E 56
D 26
	mbastart(bp, (int *)hpaddr);

D 8
	dk_busy |= 1<<(DK_N /*+NHP*/);
	dk_numb[DK_N /*+NHP*/] += 1;
	unit = bp->b_bcount>>6;
	dk_wds[DK_N /*+NHP*/] += unit;
E 8
I 8
D 22
	unit = dn+DK_N;
D 15
	if (NHP+DK_N == DK_NMAX)
		unit = NHP+DK_N;
E 15
	if (unit <= DK_NMAX) {
E 22
I 22
	unit = dn+HPDK_N;
	if (unit <= HPDK_NMAX) {
E 22
		dk_busy |= 1<<unit;
D 15
		dk_numb[unit]++;
E 15
I 15
		dk_xfer[unit]++;
E 15
		dk_wds[unit] += bp->b_bcount>>6;
	}
E 26
E 8
}

D 26
hpintr(mbastat, as)
E 26
I 26
D 33
hpdtint(mi, mbastat)
E 33
I 33
D 45
hpdtint(mi, mbasr)
E 45
I 45
hpdtint(mi, mbsr)
E 45
E 33
D 43
	register struct mba_info *mi;
E 43
I 43
	register struct mba_device *mi;
E 43
D 33
	int mbastat;
E 33
I 33
D 45
	int mbasr;
E 45
I 45
	int mbsr;
E 45
E 33
E 26
{
D 26
	register struct buf *bp, *dp;
	register unit;
	register struct device *hpaddr;
E 26
I 26
D 31
	register struct device *hpaddr = (struct device *)mi->mi_drv;
E 31
I 31
	register struct hpdevice *hpaddr = (struct hpdevice *)mi->mi_drv;
E 31
	register struct buf *bp = mi->mi_tab.b_actf;
I 83
D 96
	register struct hpst *st = &hpst[mi->mi_type];
E 96
I 96
D 127
	register struct hpst *st;
E 127
E 96
E 83
I 65
D 66
	register int er1;
E 66
I 66
	register int er1, er2;
I 86
	struct hpsoftc *sc = &hpsoftc[mi->mi_unit];
E 86
E 66
E 65
I 37
D 115
	int retry = 0;
E 115
I 115
D 127
	int retry = 0, i;
E 127
I 127
	int retry = 0;
E 127
I 126
D 142
	int npf;
	daddr_t bn;
	int bcr;
E 142
I 142
	int npf, bcr;
E 142
E 126
E 115
E 37
E 26

I 126
	bcr = MASKREG(-mi->mi_mba->mba_bcr);
I 139
	if (bp->b_flags & B_FORMAT) {
		sc->sc_status = mbsr;
		sc->sc_hpds = hpaddr->hpds;
		sc->sc_er1 = hpaddr->hper1;
		sc->sc_er2 = hpaddr->hper2;
	}
E 139
E 126
I 56
D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
D 96
	if (bp->b_flags&B_BAD) {
		if (hpecc(mi, CONT))
D 92
			return(MBD_RESTARTED);
E 92
I 92
			return (MBD_RESTARTED);
E 92
	}
E 96
I 96
D 127
	st = &hpst[mi->mi_type];
E 127
D 112
	if (bp->b_flags&B_BAD && hpecc(mi, CONT))
		return (MBD_RESTARTED);
E 112
E 96
D 85
#endif
E 85
E 56
D 26
	if(hptab.b_active) {
D 8
		dk_busy &= ~(1<<(DK_N /*+NHP*/));
E 8
		dp = hptab.b_actf;
		bp = dp->b_actf;
		unit = dkunit(bp);
I 8
D 15
		if (DK_N+NHP == DK_NMAX)
			dk_busy &= ~(1<<(DK_N+NHP));
		else if (DK_N+unit <= DK_NMAX)
E 15
I 15
D 22
		if (DK_N+unit <= DK_NMAX)
E 15
			dk_busy &= ~(1<<(DK_N+unit));
E 22
I 22
		if (HPDK_N+unit <= HPDK_NMAX)
			dk_busy &= ~(1<<(HPDK_N+unit));
E 22
E 8
D 9
		hpaddr = (struct device *)((int *)HPADDR + 32*unit);
		if (hpaddr->hpds & ERR || mbastat & MBAEBITS) {		/* error bit */
E 9
I 9
		hpaddr = mbadev(HPMBA, unit);
		if (hpaddr->hpds & ERR || mbastat & MBAEBITS) {
E 9
			while((hpaddr->hpds & DRY) == 0)
				;
			if(++hptab.b_errcnt > 28 || hpaddr->hper1&WLE)
D 9
				bp->b_flags |= B_ERROR; else
E 9
I 9
				bp->b_flags |= B_ERROR;
			else
E 9
				hptab.b_active = 0;
			if(hptab.b_errcnt > 27)
				deverror(bp, mbastat, hpaddr->hper1);
			if ((hpaddr->hper1&0xffff) == DCK) {
				if (hpecc(hpaddr, bp))
					return;
			}
			hpaddr->hpcs1 = DCLR|GO;
			if((hptab.b_errcnt&07) == 4) {
D 9
				((struct mba_regs *)MBA0)->mba_cr &= ~MBAIE;
E 9
I 9
				HPMBA->mba_cr &= ~MBAIE;
E 9
				hpaddr->hpcs1 = RECAL|GO;
				while(hpaddr->hpds & PIP)
					;
D 9
				((struct mba_regs *)MBA0)->mba_cr |= MBAIE;
E 9
I 9
				HPMBA->mba_cr |= MBAIE;
E 9
			}
E 26
I 26
D 31
	while ((hpaddr->hpds & DRY) == 0)	/* shouldn't happen */
E 31
I 31
D 37
	while ((hpaddr->hpds & HP_DRY) == 0)	/* shouldn't happen */
E 31
		printf("hp dry not set\n");
D 31
	if (hpaddr->hpds & ERR || mbastat & MBAEBITS)
		if (++mi->mi_tab.b_errcnt < 28 && (hpaddr->hper1&WLE) == 0) {
			if ((hpaddr->hper1&0xffff) != DCK) {
				hpaddr->hpcs1 = DCLR|GO;
E 31
I 31
D 33
	if (hpaddr->hpds & HP_ERR || mbastat & MBAEBITS)
E 33
I 33
D 36
	if (hpaddr->hpds & HP_ERR || mbasr & MBAEBITS)
E 33
		if (++mi->mi_tab.b_errcnt < 28 && (hpaddr->hper1&HP_WLE) == 0) {
E 36
I 36
	if (hpaddr->hpds&HP_ERR || mbasr&MBAEBITS)
		if (++mi->mi_tab.b_errcnt < 28 && (hpaddr->hper1&HP_WLE)==0) {
E 36
			if ((hpaddr->hper1&0xffff) != HP_DCK) {
				hpaddr->hpcs1 = HP_DCLR|HP_GO;
E 31
				if ((mi->mi_tab.b_errcnt&07) == 4) {
D 31
					hpaddr->hpcs1 = RECAL|GO;
					while (hpaddr->hpds & PIP)
E 31
I 31
					hpaddr->hpcs1 = HP_RECAL|HP_GO;
					while (hpaddr->hpds & HP_PIP)
E 31
						;
					mbclrattn(mi);
				}
				return (MBD_RETRY);
			} else if (hpecc(mi))
				return (MBD_RESTARTED);
		} else {
D 32
			deverror(bp, mbastat, hpaddr->hper1);
E 32
I 32
			if (hpaddr->hper1&HP_WLE)	
				printf("hp%d is write locked\n", dkunit(bp));
D 34
			else
D 33
				deverror(bp, mbastat, hpaddr->hper1);
E 33
I 33
		harderr(bp);
		printf("hp%d mbasr %b er1 %b er2 %b\n",
E 34
I 34
			else {
				harderr(bp);
				printf("hp%d mbasr %b er1 %b er2 %b\n",
E 34
				    dkunit(bp), mbasr, mbasr_bits,
				    hpaddr->hper1, HPER1_BITS,
				    hpaddr->hper2, HPER2_BITS);
I 34
			}
E 34
			hpaddr->hpcs1 = HP_DCLR|HP_GO;
E 37
I 37
D 44
	if (hpaddr->hpds&HP_ERR || mbasr&MBAEBITS) {
D 40
		int dready = 0;

		while ((hpaddr->hpds & HP_DRY) == 0) {
			if (++dready > 32)
				break;
		}
		if ((hpaddr->hpds&HP_DREADY) != HP_DREADY) {
			printf("hp%d not ready\n", dkunit(bp));
E 37
E 33
E 32
			bp->b_flags |= B_ERROR;
I 37
		} else if (hpaddr->hper1&HP_WLE) {
E 40
I 40
		if (hpaddr->hper1&HP_WLE) {
E 44
I 44
D 45
	if (hpaddr->hpds&HPDS_ERR || mbasr&MBAEBITS) {
E 45
I 45
	if (hpaddr->hpds&HPDS_ERR || mbsr&MBSR_EBITS) {
I 107
		er1 = hpaddr->hper1;
		er2 = hpaddr->hper2;
I 126
D 142
		if (bp->b_flags & B_BAD) {
E 142
I 142
		if (bp->b_flags & B_BAD)
E 142
			npf = bp->b_error;
D 142
			bn = sc->sc_badbn;
		} else {
E 142
I 142
		else {
E 142
D 139
			npf = btop(bp->b_bcount - bcr);
E 139
I 139
			npf = btodb(bp->b_bcount + (DEV_BSIZE - 1) - bcr);
E 139
			if (er1 & (HPER1_DCK | HPER1_ECH))
				npf--;
D 142
			bn = bp->b_blkno + npf;
E 142
		}
E 126
I 115
		if (HPWAIT(mi, hpaddr) == 0)
			goto hard;
E 115
E 107
I 56
#ifdef HPDEBUG
E 56
I 52
		if (hpdebug) {
I 56
			int dc = hpaddr->hpdc, da = hpaddr->hpda;
I 142
			daddr_t bn;
E 142

I 142
			if (bp->b_flags & B_BAD)
				bn = sc->sc_badbn;
			else
				bn = bp->b_blkno + npf;
E 142
D 115
			printf("hperr: bp %x cyl %d blk %d as %o ",
				bp, bp->b_cylin, bp->b_blkno,
E 115
I 115
D 123
			printf("hperr: bp %x cyl %d blk %d pgdone %d as %o ",
				bp, bp->b_cylin, bp->b_blkno, sc->sc_pgdone,
E 115
				hpaddr->hpas&0xff);
D 92
			printf("dc %x da %x\n",dc&0xffff, da&0xffff);
E 92
I 92
			printf("dc %x da %x\n",MASKREG(dc), MASKREG(da));
E 92
E 56
			printf("errcnt %d ", mi->mi_tab.b_errcnt);
			printf("mbsr=%b ", mbsr, mbsr_bits);
D 107
			printf("er1=%b er2=%b\n",
			    hpaddr->hper1, HPER1_BITS,
			    hpaddr->hper2, HPER2_BITS);
E 107
I 107
			printf("er1=%b er2=%b\n", MASKREG(er1), HPER1_BITS,
			    MASKREG(er2), HPER2_BITS);
E 107
			DELAY(1000000);
E 123
I 123
			log(LOG_DEBUG,
		    "hperr: bp %x cyl %d blk %d blkdone %d as %o dc %x da %x\n",
D 126
				bp, bp->b_cylin, bp->b_blkno, sc->sc_blkdone,
E 126
I 126
				bp, bp->b_cylin, bn, sc->sc_blkdone,
E 126
				hpaddr->hpas&0xff, MASKREG(dc), MASKREG(da));
D 126
			log(LOG_DEBUG, "errcnt %d mbsr=%b er1=%b er2=%b\n",
E 126
I 126
			log(LOG_DEBUG,
				"errcnt %d mbsr=%b er1=%b er2=%b bcr -%d\n",
E 126
				mi->mi_tab.b_errcnt, mbsr, mbsr_bits,
				MASKREG(er1), HPER1_BITS,
D 126
				MASKREG(er2), HPER2_BITS);
E 126
I 126
				MASKREG(er2), HPER2_BITS, bcr);
E 126
E 123
		}
I 56
#endif
E 56
E 52
E 45
D 65
		if (hpaddr->hper1&HPER1_WLE) {
E 65
I 65
D 107
		er1 = hpaddr->hper1;
D 66
		if (er1 & HPER1_HCRC)
E 66
I 66
		er2 = hpaddr->hper2;
E 107
		if (er1 & HPER1_HCRC) {
E 66
			er1 &= ~(HPER1_HCE|HPER1_FER);
I 66
			er2 &= ~HPER2_BSE;
		}
E 66
D 111
		if (er1&HPER1_WLE) {
E 111
I 111
		if (er1 & HPER1_WLE) {
E 111
E 65
E 44
E 40
D 41
			printf("hp%d is write locked\n", dkunit(bp));
E 41
I 41
D 115
			printf("hp%d: write locked\n", dkunit(bp));
E 115
I 115
D 119
			log(KERN_RECOV, "hp%d: write locked\n", dkunit(bp));
E 119
I 119
D 122
			log(KERN_RECOV, "hp%d: write locked\n",
E 122
I 122
			log(LOG_WARNING, "hp%d: write locked\n",
E 122
			    hpunit(bp->b_dev));
E 119
E 115
E 41
			bp->b_flags |= B_ERROR;
I 64
D 65
		} else if ((hpaddr->hper1&0xffff) == HPER1_FER && RP06 &&
E 65
I 65
D 86
		} else if ((er1&0xffff) == HPER1_FER && RP06 &&
E 65
		    hphdr[mi->mi_unit] == 0) {
E 86
I 86
D 92
		} else if ((er1&0xffff) == HPER1_FER && RP06 && !sc->sc_hdr) {
E 92
I 92
D 111
		} else if (MASKREG(er1) == HPER1_FER && RP06 && !sc->sc_hdr) {
E 111
I 111
D 133
		} else if (sc->sc_hdr) {
E 133
I 133
		} else if (bp->b_flags & B_FORMAT) {
E 133
D 142
			goto hard;
E 142
I 142
			bp->b_flags |= B_ERROR;
E 142
I 112
D 133
		} else if (RM80 && er2&HPER2_SSE) {
E 133
I 133
		} else if (RM80(mi->mi_type) && er2&HPER2_SSE) {
E 133
			(void) hpecc(mi, SSE);
			return (MBD_RESTARTED);
E 112
D 133
		} else if ((er2 & HPER2_BSE) && !ML11) {
E 133
I 133
		} else if ((er2 & HPER2_BSE) && !ML11(mi->mi_type)) {
E 133
E 111
E 92
E 86
D 85
#ifndef NOBADSECT
E 85
			if (hpecc(mi, BSE))
D 92
				return(MBD_RESTARTED);
			else
D 85
#endif
E 85
				goto hard;
E 92
I 92
				return (MBD_RESTARTED);
			goto hard;
I 111
D 133
		} else if (MASKREG(er1) == HPER1_FER && RP06) {
E 133
I 133
		} else if (MASKREG(er1) == HPER1_FER && RP06(mi->mi_type)) {
E 133
			if (hpecc(mi, BSE))
				return (MBD_RESTARTED);
			goto hard;
D 112
		} else if (RM80 && er2&HPER2_SSE) {
			(void) hpecc(mi, SSE);
			return (MBD_RESTARTED);
		} else if ((er1 & (HPER1_DCK | HPER1_ECH)) == HPER1_DCK) {
E 112
I 112
		} else if ((er1 & (HPER1_DCK | HPER1_ECH)) == HPER1_DCK &&
D 123
		    mi->mi_tab.b_errcnt > 7) {
E 123
I 123
		    mi->mi_tab.b_errcnt >= 3) {
E 123
E 112
			if (hpecc(mi, ECC))
				return (MBD_RESTARTED);
D 124
			/* else done */
E 124
I 124
			/*
			 * ECC corrected.  Only log retries below
			 * if we got errors other than soft ECC
			 * (as indicated by additional retries).
			 */
			if (mi->mi_tab.b_errcnt == 3)
				mi->mi_tab.b_errcnt = 0;
E 124
E 111
E 92
E 64
D 120
		} else if (++mi->mi_tab.b_errcnt > 27 ||
I 111
		    (ML11 && mi->mi_tab.b_errcnt > 15) ||
E 111
D 45
		    mbasr & MBASR_HARD ||
E 45
I 45
		    mbsr & MBSR_HARD ||
E 45
D 65
		    hpaddr->hper1 & HPER1_HARD ||
E 65
I 65
		    er1 & HPER1_HARD ||
E 65
D 64
		    hpaddr->hper2 & HPER2_HARD) {
E 64
I 64
D 86
		    hphdr[mi->mi_unit] ||
E 86
I 86
D 111
		    sc->sc_hdr ||
E 111
E 86
D 66
		    (!ML11 && (hpaddr->hper2 & HPER2_HARD))) {
E 66
I 66
		    (!ML11 && (er2 & HPER2_HARD))) {
E 120
I 120
D 133
		} else if ((er1 & HPER1_HCRC) && !ML11 && hpecc(mi, BSE)) {
E 133
I 133
		} else if ((er1 & HPER1_HCRC) && !ML11(mi->mi_type) &&
		    hpecc(mi, BSE)) {
E 133
E 120
I 89
 			/*
D 106
 			 * If HCRC the header is screwed up and the sector
D 92
 			 * might be in the bad sector table,
 			 * better check..
E 92
I 92
 			 * might be in the bad sector table, better check..
			 *
E 92
			 * Note: If the header is screwed up on a skip sector
			 * track, then the appropriate replacement sector
D 92
			 * cannot be found!
E 92
I 92
			 * cannot be found.
E 106
I 106
 			 * HCRC means the header is screwed up and the sector
 			 * might well exist in the bad sector table, 
			 * better check....
E 106
E 92
 			 */
D 92
 			if (er1&HPER1_HCRC && !ML11){
 				if (hpecc(mi, BSE))
 					return(MBD_RESTARTED);
 			}
E 92
I 92
D 106
 			if (er1&HPER1_HCRC && !ML11 && hpecc(mi, BSE))
E 106
I 106
D 111
 			if ((er1&HPER1_HCRC) && 
			    !ML11 && !sc->sc_hdr && hpecc(mi, BSE))
E 111
I 111
D 120
 			if ((er1 & HPER1_HCRC) && !ML11 && hpecc(mi, BSE))
E 111
E 106
				return (MBD_RESTARTED);
E 120
I 120
			return (MBD_RESTARTED);
		} else if (++mi->mi_tab.b_errcnt > 27 ||
D 133
		    (ML11 && mi->mi_tab.b_errcnt > 15) ||
E 133
I 133
		    (ML11(mi->mi_type) && mi->mi_tab.b_errcnt > 15) ||
E 133
		    mbsr & MBSR_HARD ||
		    er1 & HPER1_HARD ||
D 133
		    (!ML11 && (er2 & HPER2_HARD))) {
E 133
I 133
		    (!ML11(mi->mi_type) && (er2 & HPER2_HARD))) {
E 133
E 120
E 92
E 89
E 66
E 64
I 56
hard:
I 83
D 112
			if (ML11)
D 92
				bp->b_blkno = hpaddr->hpda&0xffff;
E 92
I 92
				bp->b_blkno = MASKREG(hpaddr->hpda);
E 112
I 112
D 126
			if (bp->b_flags & B_BAD)
				bp->b_blkno = sc->sc_badbn;
E 112
E 92
D 115
			else
D 92
				bp->b_blkno = (hpaddr->hpdc*st->nspc)&0xffff +
					  ((hpaddr->hpda>>8)&0xffff)*st->nsect +
						(hpaddr->hpda&0x1f);
E 92
I 92
D 112
				bp->b_blkno = MASKREG(hpaddr->hpdc) * st->nspc +
				   (MASKREG(hpaddr->hpda) >> 8) * st->nsect +
D 107
				   (hpaddr->hpda&0x1f);
E 107
I 107
				   (hpaddr->hpda&0xff);
E 107
I 106
			/*
			 * If we have a data check error or a hard
			 * ecc error the bad sector has been read/written,
			 * and the controller registers are pointing to
			 * the next sector...
			 */
D 107
			 if (er1 && (HPER1_DCK|HPER1_ECH))
E 107
I 107
			 if (er1&(HPER1_DCK|HPER1_ECH) || sc->sc_hdr)
E 107
				bp->b_blkno--;
E 112
I 112
				bp->b_blkno = dkblock(bp) + sc->sc_pgdone;
 			if (hpaddr->hpof & HPOF_SSEI)
 				bp->b_blkno++;
E 115
I 115
			else {
D 119
				bp->b_blkno = dkblock(bp) + btop(bp->b_bcount -
E 119
I 119
				bp->b_blkno = bp->b_blkno + btop(bp->b_bcount -
E 119
				    MASKREG(-mi->mi_mba->mba_bcr));
				if (er1 & (HPER1_DCK | HPER1_ECH))
					bp->b_blkno--;
			}
E 126
I 126
D 142
			bp->b_blkno = bn;		/* XXX */
E 126
E 115
E 112
E 106
E 92
E 83
E 56
D 41
			harderr(bp);
D 40
			printf("hp%d mbasr=%b er1=%b er2=%b\n",
			    dkunit(bp), mbasr, mbasr_bits,
E 40
I 40
			printf("hp%d%c mbasr=%b er1=%b er2=%b\n",
			    dkunit(bp), 'a'+(minor(bp->b_dev)&07),
E 41
I 41
			harderr(bp, "hp");
E 142
I 142
			diskerr(bp, "hp", "hard error", LOG_PRINTF, npf,
			    &hplabel[mi->mi_unit]);
			if (bp->b_flags & B_BAD)
				printf(" (on replacement sector %d)",
				    sc->sc_badbn);
E 142
D 45
			printf("mbasr=%b er1=%b er2=%b\n",
E 41
			    mbasr, mbasr_bits,
E 45
I 45
D 51
			printf("mbsr=%b er1=%b er2=%b\n",
			    mbsr, mbsr_bits,
E 51
I 51
			if (mbsr & (MBSR_EBITS &~ (MBSR_DTABT|MBSR_MBEXC)))
D 142
				printf("mbsr=%b ", mbsr, mbsr_bits);
D 56
			printf("er1=%b er2=%b\n",
E 56
I 56
			printf("er1=%b er2=%b",
E 142
I 142
				printf(" mbsr=%b", mbsr, mbsr_bits);
			printf(" er1=%b er2=%b\n",
E 142
E 56
E 51
E 45
E 40
D 107
			    hpaddr->hper1, HPER1_BITS,
			    hpaddr->hper2, HPER2_BITS);
E 107
I 107
			    MASKREG(hpaddr->hper1), HPER1_BITS,
			    MASKREG(hpaddr->hper2), HPER2_BITS);
E 107
I 56
D 123
			if (hpaddr->hpmr)
D 92
				printf(" mr=%o", hpaddr->hpmr&0xffff);
E 92
I 92
				printf(" mr=%o", MASKREG(hpaddr->hpmr));
E 92
			if (hpaddr->hpmr2)
D 92
				printf(" mr2=%o", hpaddr->hpmr2&0xffff);
E 92
I 92
				printf(" mr2=%o", MASKREG(hpaddr->hpmr2));
E 123
I 106
D 133
			if (sc->sc_hdr)
E 133
I 133
D 142
			if (bp->b_flags & B_FORMAT)
E 133
D 139
				printf(" (hdr i/o)");
E 139
I 139
				printf(" (format i/o)");
E 139
E 106
E 92
			printf("\n");
E 142
E 56
			bp->b_flags |= B_ERROR;
I 112
			bp->b_flags &= ~B_BAD;
E 112
I 83
D 111
			retry = 0;
E 83
I 39
D 45
#ifdef notdef
E 45
D 44
		} else if (hpaddr->hper2&HP_SSE) {
E 44
I 44
D 48
		} else if (hpaddr->hper2&HPER2_SSE) {
E 48
I 48
D 86
			hprecal[mi->mi_unit] = 0;
E 86
I 86
			sc->sc_recal = 0;
E 86
D 56
		} else if (hptypes[mi->mi_type] == MBDT_RM80 && hpaddr->hper2&HPER2_SSE) {
E 48
E 44
			hpecc(mi, 1);
E 56
I 56
D 64
		} else if (hpaddr->hper2 & HPER2_BSE) {
E 64
I 64
D 66
		} else if ((hpaddr->hper2 & HPER2_BSE) && !ML11) {
E 66
I 66
		} else if ((er2 & HPER2_BSE) && !ML11) {
E 66
E 64
D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
			if (hpecc(mi, BSE))
D 92
				return(MBD_RESTARTED);
E 92
I 92
				return (MBD_RESTARTED);
E 92
D 96
			else
D 85
#endif
E 85
				goto hard;
E 96
I 96
			goto hard;
E 96
D 64
		} else if (hptypes[mi->mi_type] == MBDT_RM80 &&
		    hpaddr->hper2&HPER2_SSE) {
E 64
I 64
D 66
		} else if (RM80 && hpaddr->hper2&HPER2_SSE) {
E 66
I 66
		} else if (RM80 && er2&HPER2_SSE) {
E 66
E 64
D 60
			hpecc(mi, SSE);
E 60
I 60
			(void) hpecc(mi, SSE);
E 60
E 56
			return (MBD_RESTARTED);
D 45
#endif
E 45
E 39
D 44
		} else if ((hpaddr->hper1&(HP_DCK|HP_ECH)) == HP_DCK) {
E 44
I 44
D 65
		} else if ((hpaddr->hper1&(HPER1_DCK|HPER1_ECH))==HPER1_DCK) {
E 65
I 65
		} else if ((er1&(HPER1_DCK|HPER1_ECH))==HPER1_DCK) {
E 65
E 44
D 39
			if (hpecc(mi))
E 39
I 39
D 56
			if (hpecc(mi, 0))
E 56
I 56
			if (hpecc(mi, ECC))
E 56
E 39
				return (MBD_RESTARTED);
			/* else done */
E 111
		} else
			retry = 1;
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
D 64
		if ((mi->mi_tab.b_errcnt&07) == 4) {
E 64
I 64
D 111
		if (ML11) {
			if (mi->mi_tab.b_errcnt >= 16)
				goto hard;
		} else if ((mi->mi_tab.b_errcnt&07) == 4) {
E 111
I 111
D 125
		if ((mi->mi_tab.b_errcnt & 07) == 4) {
E 125
I 125
		if (retry && (mi->mi_tab.b_errcnt & 07) == 4) {
E 125
E 111
E 64
			hpaddr->hpcs1 = HP_RECAL|HP_GO;
D 40
			/* SHOULD SET AN INTERRUPT AND RETURN */
			/* AND HANDLE ALA rk.c OR up.c */
			while (hpaddr->hpds & HP_PIP)
				;
			mbclrattn(mi);
E 40
I 40
D 44
			hprecal[mi->mi_unit] = 1;
			return (MBD_RESTARTED);
E 44
I 44
D 56
			hprecal[mi->mi_unit] = 0;
			goto nextrecal;
E 56
I 56
D 86
			hprecal[mi->mi_unit] = 1;
E 86
I 86
			sc->sc_recal = 1;
E 86
D 92
			return(MBD_RESTARTED);
E 92
I 92
D 123
			return (MBD_RESTARTED);
E 123
I 123
			return (MBD_REPOSITION);
E 123
E 92
E 56
E 44
E 40
E 37
E 26
		}
I 37
D 111
		if (retry)
D 110
			return (MBD_RETRY);
E 110
I 110
			sc->sc_recal = 2;
E 111
E 110
	}
I 56
#ifdef HPDEBUG
E 56
I 52
	else
D 86
		if (hpdebug && hprecal[mi->mi_unit]) {
			printf("recal %d ", hprecal[mi->mi_unit]);
E 86
I 86
		if (hpdebug && sc->sc_recal) {
D 123
			printf("recal %d ", sc->sc_recal);
E 86
			printf("errcnt %d\n", mi->mi_tab.b_errcnt);
			printf("mbsr=%b ", mbsr, mbsr_bits);
			printf("er1=%b er2=%b\n",
E 123
I 123
			log(LOG_DEBUG,
			    "recal %d errcnt %d mbsr=%b er1=%b er2=%b\n",
			    sc->sc_recal, mi->mi_tab.b_errcnt, mbsr, mbsr_bits,
E 123
			    hpaddr->hper1, HPER1_BITS,
			    hpaddr->hper2, HPER2_BITS);
		}
I 56
#endif
I 115
D 128
	HPWAIT(mi, hpaddr);
E 128
I 128
	(void)HPWAIT(mi, hpaddr);
E 128
E 115
E 56
E 52
I 40
D 44
	if (hprecal[mi->mi_unit]) {
E 44
I 44
D 86
	switch (hprecal[mi->mi_unit]) {
E 86
I 86
D 123
	switch (sc->sc_recal) {
E 86

	case 1:
		hpaddr->hpdc = bp->b_cylin;
		hpaddr->hpcs1 = HP_SEEK|HP_GO;
D 56
		goto nextrecal;
E 56
I 56
D 86
		hprecal[mi->mi_unit]++;
E 86
I 86
		sc->sc_recal++;
E 86
		return (MBD_RESTARTED);
E 56
	case 2:
D 111
		if (mi->mi_tab.b_errcnt < 16 ||
D 52
		    (bp->b_flags & B_READ) != 0)
E 52
I 52
		    (bp->b_flags & B_READ) == 0)
E 52
			goto donerecal;
		hpaddr->hpof = hp_offset[mi->mi_tab.b_errcnt & 017]|HPOF_FMT22;
		hpaddr->hpcs1 = HP_OFFSET|HP_GO;
D 56
		goto nextrecal;
	nextrecal:
E 56
D 86
		hprecal[mi->mi_unit]++;
E 86
I 86
D 110
		sc->sc_recal++;
E 86
		return (MBD_RESTARTED);
E 110
I 110
		while ((hpaddr->hpds & (HPDS_DRY | HPDS_PIP)) != HPDS_DRY)
			;
		mbclrattn(mi);
E 110
	donerecal:
I 49
D 110
	case 3:
E 110
E 49
E 44
D 86
		hprecal[mi->mi_unit] = 0;
E 86
I 86
		sc->sc_recal = 0;
E 111
I 111
		retry = 1;
		break;
	}
	sc->sc_recal = 0;
	if (retry) {
		if (mi->mi_tab.b_errcnt >= 16 && (bp->b_flags & B_READ)) {
			hpaddr->hpof =
			    hp_offset[mi->mi_tab.b_errcnt & 017]|HPOF_FMT22;
			hpaddr->hpcs1 = HP_OFFSET|HP_GO;
D 115
			while ((hpaddr->hpds & (HPDS_DRY | HPDS_PIP)) !=
			    HPDS_DRY)
				DELAY(10);
E 115
I 115
			HPWAIT(mi, hpaddr);
E 115
			mbclrattn(mi);
		}
E 123
I 123
	if (retry)
E 123
E 111
E 86
		return (MBD_RETRY);
D 123
	}
E 123
I 64
D 86
	hphdr[mi->mi_unit] = 0;
E 86
I 86
D 112
	sc->sc_hdr = 0;
E 86
E 64
E 40
E 37
D 26
		if(hptab.b_active) {
			if(hptab.b_errcnt) {
D 9
				((struct mba_regs *)MBA0)->mba_cr &= ~MBAIE;
E 9
I 9
				HPMBA->mba_cr &= ~MBAIE;
E 9
				hpaddr->hpcs1 = RTC|GO;
				while(hpaddr->hpds & PIP)
					;
D 9
				((struct mba_regs *)MBA0)->mba_cr |= MBAIE;
E 9
I 9
				HPMBA->mba_cr |= MBAIE;
E 9
			}
			hptab.b_active = 0;
			hptab.b_errcnt = 0;
			hptab.b_actf = dp->b_forw;
			dp->b_active = 0;
			dp->b_errcnt = 0;
			dp->b_actf = bp->av_forw;
D 9
			bp->b_resid = -(((struct mba_regs *)MBA0)->mba_bcr) & 0xffff;
E 9
I 9
			bp->b_resid = -HPMBA->mba_bcr & 0xffff;
E 9
			iodone(bp);
			if(dp->b_actf)
				hpustart(unit);
		}
		as &= ~(1<<unit);
	} else {
		if(as == 0)
D 9
			((struct mba_regs *)MBA0)->mba_cr |= MBAIE;
E 9
I 9
			HPMBA->mba_cr |= MBAIE;
E 26
I 26
D 92
	bp->b_resid = -(mi->mi_mba->mba_bcr) & 0xffff;
E 92
I 92
	bp->b_resid = MASKREG(-mi->mi_mba->mba_bcr);
E 112
E 92
D 37
	if (mi->mi_tab.b_errcnt) {
E 37
I 37
D 55
	if (mi->mi_tab.b_errcnt > 16) {
E 55
I 55
	if (mi->mi_tab.b_errcnt >= 16) {
E 55
I 44
		/*
		 * This is fast and occurs rarely; we don't
		 * bother with interrupts.
		 */
E 44
E 37
D 31
		hpaddr->hpcs1 = RTC|GO;
		while (hpaddr->hpds & PIP)
E 31
I 31
		hpaddr->hpcs1 = HP_RTC|HP_GO;
D 44
		while (hpaddr->hpds & HP_PIP)
E 44
I 44
D 110
		while (hpaddr->hpds & HPDS_PIP)
E 110
I 110
D 115
		while ((hpaddr->hpds & (HPDS_DRY | HPDS_PIP)) != HPDS_DRY)
E 110
E 44
E 31
D 111
			;
E 111
I 111
			DELAY(10);
E 115
I 115
D 128
		HPWAIT(mi, hpaddr);
E 128
I 128
		(void)HPWAIT(mi, hpaddr);
E 128
E 115
E 111
		mbclrattn(mi);
E 26
E 9
	}
I 123
D 124
	if (mi->mi_tab.b_errcnt)
E 124
I 124
D 142
	if (mi->mi_tab.b_errcnt && (bp->b_flags & B_ERROR) == 0)
E 124
		log(LOG_INFO, "hp%d%c: %d retries %sing sn%d\n",
		    hpunit(bp->b_dev), 'a'+(minor(bp->b_dev)&07),
		    mi->mi_tab.b_errcnt,
		    (bp->b_flags & B_READ) ? "read" : "writ",
		    (bp->b_flags & B_BAD) ?
		    sc->sc_badbn : bp->b_blkno + sc->sc_blkdone);
E 142
I 142
	if (mi->mi_tab.b_errcnt && (bp->b_flags & B_ERROR) == 0) {
		diskerr(bp, "hp", "retries", LOG_INFO, sc->sc_blkdone,
		    &hplabel[mi->mi_unit]);
		addlog(": %d retries\n", mi->mi_tab.b_errcnt);
	}
E 142
E 123
I 112
	if ((bp->b_flags & B_BAD) && hpecc(mi, CONT))
		return (MBD_RESTARTED);
D 133
	sc->sc_hdr = 0;
E 133
D 123
	sc->sc_pgdone = 0;
E 123
I 123
	sc->sc_blkdone = 0;
E 123
D 126
	bp->b_resid = MASKREG(-mi->mi_mba->mba_bcr);
E 126
I 126
	bp->b_resid = bcr;
E 126
E 112
D 26
	for(unit=0; unit<NHP; unit++)
		if(as & (1<<unit))
			hpustart(unit);
	hpstart();
E 26
I 26
D 31
	hpaddr->hpcs1 = RELEASE|GO;
E 31
I 31
D 56
	hpaddr->hpcs1 = HP_RELEASE|HP_GO;
E 56
I 53
D 64
	hpaddr->hpof = HPOF_FMT22;
E 53
I 47
D 56
	if (mi->mi_mba->mba_drv[0].mbd_as & (1<<mi->mi_drive))
		printf("REL attn\n");
	mbclrattn(mi);
E 56
I 56
	hpaddr->hpcs1 = HP_RELEASE|HP_GO;
E 64
I 64
D 133
	if (!ML11) {
E 133
I 133
	if (!ML11(mi->mi_type)) {
E 133
		hpaddr->hpof = HPOF_FMT22;
		hpaddr->hpcs1 = HP_RELEASE|HP_GO;
	}
I 135
	if (sc->sc_openpart == 0)
		wakeup((caddr_t)sc);
E 135
E 64
E 56
E 47
E 31
	return (MBD_DONE);
E 26
}

I 115
/*
 * Wait (for a bit) for a drive to come ready;
 * returns nonzero on success.
 */
hpwait(mi)
	register struct mba_device *mi;
{
	register struct hpdevice *hpaddr = (struct hpdevice *)mi->mi_drv;
	register i = 100000;

	while ((hpaddr->hpds & HPDS_DRY) == 0 && --i)
		DELAY(10);
	if (i == 0)
		printf("hp%d: intr, not ready\n", mi->mi_unit);
	return (i);
}

E 115
D 72
hpread(dev)
E 72
I 72
D 140
hpread(dev, uio)
E 72
I 31
	dev_t dev;
I 72
	struct uio *uio;
E 72
E 31
{
I 31
D 119
	register int unit = minor(dev) >> 3;
E 119
I 119
	register int unit = hpunit(dev);
E 119
E 31

D 31
	physio(hpstrategy, &rhpbuf, dev, B_READ, minphys);
E 31
I 31
	if (unit >= NHP)
D 74
		u.u_error = ENXIO;
	else
D 72
		physio(hpstrategy, &rhpbuf[unit], dev, B_READ, minphys);
E 72
I 72
		physio(hpstrategy, &rhpbuf[unit], dev, B_READ, minphys, uio);
E 74
I 74
		return (ENXIO);
	return (physio(hpstrategy, &rhpbuf[unit], dev, B_READ, minphys, uio));
E 74
E 72
E 31
}

D 73
hpwrite(dev)
E 73
I 73
hpwrite(dev, uio)
E 73
I 31
	dev_t dev;
I 73
	struct uio *uio;
E 73
E 31
{
I 31
D 119
	register int unit = minor(dev) >> 3;
E 119
I 119
	register int unit = hpunit(dev);
E 119
E 31

D 31
	physio(hpstrategy, &rhpbuf, dev, B_WRITE, minphys);
E 31
I 31
	if (unit >= NHP)
D 74
		u.u_error = ENXIO;
	else
D 72
		physio(hpstrategy, &rhpbuf[unit], dev, B_WRITE, minphys);
E 72
I 72
D 73
		physio(hpstrategy, &rhpbuf[unit], dev, B_WRITE, minphys, 0);
E 73
I 73
		physio(hpstrategy, &rhpbuf[unit], dev, B_WRITE, minphys, uio);
E 74
I 74
		return (ENXIO);
	return (physio(hpstrategy, &rhpbuf[unit], dev, B_WRITE, minphys, uio));
E 74
E 73
E 72
I 64
}

E 140
D 133
/*ARGSUSED*/
E 133
D 71
hpioctl(dev, cmd, addr, flag)
E 71
I 71
hpioctl(dev, cmd, data, flag)
E 71
	dev_t dev;
	int cmd;
D 71
	caddr_t addr;
E 71
I 71
	caddr_t data;
E 71
	int flag;
{
I 133
	int unit = hpunit(dev);
	register struct disklabel *lp;
I 139
	register struct hpsoftc *sc = &hpsoftc[unit];
E 139
D 140
	register struct format_op *fop;
E 140
D 139
	int error = 0;
E 139
I 139
D 145
	int error = 0, wlab;
E 145
I 145
	int error = 0;
E 145
E 139
	int hpformat();
E 133

I 133
	lp = &hplabel[unit];

E 133
	switch (cmd) {
I 71

E 71
D 133
	case DKIOCHDR:	/* do header read/write */
D 86
		hphdr[minor(dev)>>3] = 1;
E 86
I 86
D 119
		hpsoftc[minor(dev) >> 3].sc_hdr = 1;
E 119
I 119
		hpsoftc[hpunit(dev)].sc_hdr = 1;
E 119
E 86
D 76
		return;
E 76
I 76
		return (0);
E 133
I 133
	case DIOCGDINFO:
		*(struct disklabel *)data = *lp;
		break;
E 133
E 76

I 133
D 135
	case DIOCGDINFOP:
		*(struct disklabel **)data = lp;
E 135
I 135
	case DIOCGPART:
		((struct partinfo *)data)->disklab = lp;
		((struct partinfo *)data)->part =
		    &lp->d_partitions[hppart(dev)];
E 135
		break;

	case DIOCSDINFO:
		if ((flag & FWRITE) == 0)
			error = EBADF;
		else
D 138
			*lp = *(struct disklabel *)data;
E 138
I 138
			error = setdisklabel(lp, (struct disklabel *)data,
D 139
			    hpsoftc[unit].sc_openpart);
E 139
I 139
			    (sc->sc_state == OPENRAW) ? 0 : sc->sc_openpart);
		if (error == 0)
			sc->sc_state = OPEN;
E 139
E 138
		break;

I 139
	case DIOCWLABEL:
		if ((flag & FWRITE) == 0)
			error = EBADF;
		else
			sc->sc_wlabel = *(int *)data;
		break;

E 139
	case DIOCWDINFO:
I 139
D 145
		/* simulate opening partition 0 so write succeeds */
		sc->sc_openpart |= (1 << 0);		/* XXX */
		wlab = sc->sc_wlabel;
		sc->sc_wlabel = 1;
E 145
E 139
D 138
		if ((flag & FWRITE) == 0) {
E 138
I 138
		if ((flag & FWRITE) == 0)
E 138
			error = EBADF;
D 138
			break;
		}
		{
		struct buf *bp;
		struct disklabel *dlp;

		*lp = *(struct disklabel *)data;
		bp = geteblk(lp->d_secsize);
D 135
		bp->b_dev = dev;
E 135
I 135
		bp->b_dev = makedev(major(dev), hpminor(hpunit(dev), 0));
E 135
		bp->b_blkno = LABELSECTOR;
		bp->b_bcount = lp->d_secsize;
		bp->b_flags = B_READ;
		dlp = (struct disklabel *)(bp->b_un.b_addr + LABELOFFSET);
		hpstrategy(bp);
		biowait(bp);
		if (bp->b_flags & B_ERROR) {
			error = u.u_error;		/* XXX */
			u.u_error = 0;
			goto bad;
		}
		*dlp = *lp;
		bp->b_flags = B_WRITE;
		hpstrategy(bp);
		biowait(bp);
		if (bp->b_flags & B_ERROR) {
			error = u.u_error;		/* XXX */
			u.u_error = 0;
		}
bad:
		brelse(bp);
		}
E 138
I 138
		else if ((error = setdisklabel(lp, (struct disklabel *)data,
D 139
			    hpsoftc[unit].sc_openpart)) == 0)
E 139
I 139
		    (sc->sc_state == OPENRAW) ? 0 : sc->sc_openpart)) == 0) {
I 145
			int wlab;

E 145
			sc->sc_state = OPEN;
I 145
			/* simulate opening partition 0 so write succeeds */
			sc->sc_openpart |= (1 << 0);		/* XXX */
			wlab = sc->sc_wlabel;
			sc->sc_wlabel = 1;
E 145
E 139
			error = writedisklabel(dev, hpstrategy, lp);
I 145
			sc->sc_openpart = sc->sc_copenpart | sc->sc_bopenpart;
			sc->sc_wlabel = wlab;
E 145
I 139
		}
D 145
		sc->sc_openpart = sc->sc_copenpart | sc->sc_bopenpart;
		sc->sc_wlabel = wlab;
E 145
E 139
E 138
		break;

D 139
#ifdef notyet
	case DIOCWFORMAT:
		if ((flag & FWRITE) == 0) {
E 139
I 139
	case DIOCSBAD:
	    {
		struct dkbad *db = (struct dkbad *)data;

		if ((flag & FWRITE) == 0)
E 139
			error = EBADF;
D 139
			break;
		}
		{
E 139
I 139
		else if (db->bt_mbz != 0 || db->bt_flag != 0)
			error = EINVAL;
		else
			hpbad[unit] = *db;
		break;
	    }

	case DIOCRFORMAT:
	case DIOCWFORMAT:
	    {
I 140
		register struct format_op *fop;
E 140
E 139
		struct uio auio;
		struct iovec aiov;

I 139
		if (cmd == DIOCWFORMAT && (flag & FWRITE) == 0) {
			error = EBADF;
			break;
		}
E 139
		fop = (struct format_op *)data;
		aiov.iov_base = fop->df_buf;
		aiov.iov_len = fop->df_count;
		auio.uio_iov = &aiov;
		auio.uio_iovcnt = 1;
		auio.uio_resid = fop->df_count;
D 139
		auio.uio_segflg = 0;
E 139
I 139
		auio.uio_segflg = UIO_USERSPACE;
E 139
		auio.uio_offset = fop->df_startblk * lp->d_secsize;
D 139
		error = physio(hpformat, &rhpbuf[unit], dev, B_WRITE,
			minphys, &auio);
E 139
I 139
		/*
		 * Don't return errors, as the format op won't get copied
		 * out if we return nonzero.  Callers must check the returned
		 * count.
		 */
D 140
		(void) physio(hpformat, &rhpbuf[unit], dev,
E 140
I 140
		(void) physio(hpformat, (struct buf *)NULL, dev,
E 140
		    (cmd == DIOCWFORMAT ? B_WRITE : B_READ), minphys, &auio);
E 139
		fop->df_count -= auio.uio_resid;
		fop->df_reg[0] = sc->sc_status;
D 139
		fop->df_reg[1] = sc->sc_error;
		}
E 139
I 139
		fop->df_reg[1] = sc->sc_hpds;
		fop->df_reg[2] = sc->sc_er1;
		fop->df_reg[3] = sc->sc_er2;
E 139
		break;
I 139
	    }

#ifdef COMPAT_42
	case DKIOCHDR:  /* do header read/write */	/* XXX */
		sc->sc_hdr = 1;
		break;
E 139
#endif

E 133
	default:
D 76
		u.u_error = ENXIO;
E 76
I 76
D 133
		return (ENXIO);
E 133
I 133
		error = ENOTTY;
		break;
E 133
E 76
	}
I 133
D 137
	return (0);
E 137
I 137
	return (error);
E 137
E 133
E 64
E 31
}

I 133
hpformat(bp)
	struct buf *bp;
{
D 140

E 140
	bp->b_flags |= B_FORMAT;
D 140
	return (hpstrategy(bp));
E 140
I 140
	hpstrategy(bp);
E 140
}

E 133
I 45
D 56
/*ARGSUSED*/
E 45
D 26
hpecc(rp, bp)
register struct device *rp;
register struct buf *bp;
E 26
I 26
D 39
hpecc(mi)
E 39
I 39
hpecc(mi, rm80sse)
E 56
I 56
hpecc(mi, flag)
E 56
E 39
D 43
	register struct mba_info *mi;
E 43
I 43
	register struct mba_device *mi;
E 43
I 39
D 56
	int rm80sse;
E 56
I 56
	int flag;
E 56
E 39
E 26
{
D 9
	register i;
	register b, n, map, mix;
	register char *cp;
	register mask;
	short piget();
E 9
I 9
D 26
	struct mba_regs *mbp = HPMBA;
E 26
I 26
	register struct mba_regs *mbp = mi->mi_mba;
D 31
	register struct device *rp = (struct device *)mi->mi_drv;
E 31
I 31
	register struct hpdevice *rp = (struct hpdevice *)mi->mi_drv;
E 31
	register struct buf *bp = mi->mi_tab.b_actf;
D 56
	register struct hpst *st;
E 26
	register int i;
	caddr_t addr;
	int reg, bit, byte, npf, mask, o;
E 56
I 56
D 133
	register struct hpst *st = &hpst[mi->mi_type];
E 133
I 133
	register struct disklabel *lp = &hplabel[mi->mi_unit];
E 133
I 112
	struct hpsoftc *sc = &hpsoftc[mi->mi_unit];
E 112
	int npf, o;
E 56
D 26
	int dn, bn, cn, tn, sn, ns, nt;
E 9
D 2
	extern char buffers[][];
E 2
I 2
	extern char buffers[NBUF][BSIZE];
E 26
I 26
	int bn, cn, tn, sn;
E 26
I 9
D 56
	struct pte mpte;
E 56
I 10
D 12
	short bcr;
E 12
I 12
	int bcr;
E 12
E 10
E 9
E 2

D 9
	b = (((((struct mba_regs *)MBA0)->mba_bcr&0xffff) +
		(bp->b_bcount) - 1)>>9)&0177;
	printf("%D ", bp->b_blkno+b);
E 9
I 9
D 31
	/*
	 * Npf is the number of sectors transferred before the sector
	 * containing the ECC error, and reg is the MBA register
	 * mapping (the first part of)the transfer.
	 * O is offset within a memory page of the first byte transferred.
	 */
E 31
D 10
	npf = btop((mbp->mba_bcr&0xffff) + bp->b_bcount) - 1;
E 10
I 10
D 12
	bcr = mbp->mba_bcr;		/* get into short so can sign extend */
E 12
I 12
D 92
	bcr = mbp->mba_bcr & 0xffff;
E 92
I 92
D 115
	bcr = MASKREG(mbp->mba_bcr);
E 92
	if (bcr)
		bcr |= 0xffff0000;		/* sxt */
E 115
I 115
	bcr = MASKREG(-mbp->mba_bcr);
E 115
E 12
D 56
	npf = btop(bcr + bp->b_bcount) - 1;
D 15
	printf("bcr %d npf %d\n", bcr, npf);
E 10
	if (bp->b_flags&B_PHYS)
		reg = 128 + npf;
	else
		reg = btop(bp->b_un.b_addr - buffers[0]) + npf;
E 15
I 15
	reg = npf;
I 39
D 45
#ifdef notdef
E 45
	if (rm80sse) {
D 44
		rp->hpof |= HP_SSEI;
E 44
I 44
		rp->hpof |= HPOF_SSEI;
E 44
D 45
		reg--;		/* compensate in advance for reg-- below */
E 45
I 45
		reg--;		/* compensate in advance for reg+1 below */
E 45
		goto sse;
	}
E 56
I 56
D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
D 112
	if (flag == CONT)
E 112
I 112
	if (bp->b_flags & B_BAD)
E 112
		npf = bp->b_error;
D 131
	else
D 85
#endif
E 85
D 115
		npf = btop(bcr + bp->b_bcount);
E 115
I 115
D 126
		npf = btop(bp->b_bcount - bcr);
E 126
I 126
D 129
		npf = btodb(bp->b_bcount - bcr);
E 129
I 129
		npf = btodb(bp->b_bcount - bcr + 511);
E 131
I 131
	else {
		npf = bp->b_bcount - bcr;
		/*
		 * Watch out for fractional sector at end of transfer;
		 * want to round up if finished, otherwise round down.
		 */
		if (bcr == 0)
			npf += 511;
		npf = btodb(npf);
	}
E 131
E 129
E 126
E 115
E 56
D 45
#endif
E 45
E 39
E 15
	o = (int)bp->b_un.b_addr & PGOFSET;
D 37
	printf("%D ", bp->b_blkno + npf);
E 9
	prdev("ECC", bp->b_dev);
E 37
I 37
D 40
	printf("SOFT ECC hp%d%c bn%d\n", dkunit(bp),
E 40
I 40
D 41
	printf("soft ecc hp%d%c bn%d\n", dkunit(bp),
E 41
I 41
D 42
	printf("hp%d%c: soft ecc bn%d\n", dkunit(bp),
E 42
I 42
D 56
	printf("hp%d%c: soft ecc sn%d\n", dkunit(bp),
E 42
E 41
E 40
	    'a'+(minor(bp->b_dev)&07), bp->b_blkno + npf);
E 37
	mask = rp->hpec2&0xffff;
D 36
	if (mask == 0) {
D 31
		rp->hpof = FMT22;
E 31
I 31
		rp->hpof = HP_FMT22;
E 31
D 9
		return(0);
E 9
I 9
		return (0);
E 9
	}
E 36
D 9
	i = (rp->hpec1&0xffff) - 1;
	n = i&017;
	i = (i&~017)>>3;
	if (bp->b_flags&B_PHYS)
		map = 128 + b;
	else
		map = ((bp->b_un.b_addr - (char *)buffers)>>9) + b;
	mix = i + ((int)bp->b_un.b_addr&0x1ff);
	i += b<<9;
	if ( i < bp->b_bcount) {
		cp = (char *)((((int *)MBA0_MAP)[map+(mix>>9)]&0x1fffff)<<9)+(mix&0x1ff);
		piput((int)cp,piget((int)cp)^(mask<<n));
E 9
I 9
D 37

E 37
D 31
	/*
	 * Compute the byte and bit position of the error.
	 * The variable i is the byte offset in the transfer,
	 * the variable byte is the offset from a page boundary
	 * in main memory.
	 */
E 31
	i = (rp->hpec1&0xffff) - 1;		/* -1 makes 0 origin */
D 10
	bit = i&017;
E 10
I 10
	bit = i&07;
E 10
	i = (i&~07)>>3;
	byte = i + o;
D 31
	/*
	 * Correct while possible bits remain of mask.  Since mask
	 * contains 11 bits, we continue while the bit offset is > -11.
	 * Also watch out for end of this block and the end of the whole
	 * transfer.
	 */
E 31
	while (i < 512 && (int)ptob(npf)+i < bp->b_bcount && bit > -11) {
		mpte = mbp->mba_map[reg+btop(byte)];
		addr = ptob(mpte.pg_pfnum) + (byte & PGOFSET);
		putmemc(addr, getmemc(addr)^(mask<<bit));
		byte++;
		i++;
		bit -= 8;
E 9
	}
D 9
	mix += 2;
	i += 2;
	if (i < bp->b_bcount) {
		cp = (char *)((((int *)MBA0_MAP)[map+(mix>>9)]&0x1fffff)<<9)+(mix&0x1ff);
		piput((int)cp,piget((int)cp)^(mask>>(16-n)));
E 9
I 9
D 26
	hptab.b_active++;		/* Either complete or continuing */
E 26
I 26
D 37
	mi->mi_hd->mh_active++;		/* Either complete or continuing */
E 37
E 26
D 10
	if (mbp->mba_bcr == 0)
E 10
I 10
	if (bcr == 0)
E 10
		return (0);
D 31
	/*
	 * Have to continue the transfer... clear the drive,
	 * and compute the position where the transfer is to continue.
	 * We have completed npf+1 sectores of the transfer already;
	 * restart at offset o of next sector (i.e. in MBA register reg+1).
	 */
	rp->hpcs1 = DCLR|GO;
E 31
I 31
#ifdef notdef
I 39
sse:
D 44
	if (rpof&HP_SSEI)
E 44
I 44
	if (rpof&HPOF_SSEI)
E 44
		rp->hpda = rp->hpda + 1;
E 39
	rp->hper1 = 0;
	rp->hpcs1 = HP_RCOM|HP_GO;
#else
I 39
sse:
E 39
	rp->hpcs1 = HP_DCLR|HP_GO;
E 56
E 31
D 26
	dn = dkunit(bp);
E 26
D 112
	bn = dkblock(bp);
E 112
I 112
D 115
	bn = dkblock(bp) + npf;
E 115
I 115
D 119
	bn = dkblock(bp);
E 119
I 119
	bn = bp->b_blkno;
E 119
E 115
E 112
D 11
	if (hp_type[dn] == RM) {
		ns = NRMSECT;
		nt = NRMTRAC;
	} else {
		ns = NSECT;
		nt = NTRAC;
E 11
I 11
D 26
	switch (hp_type[dn]) {

	case RM:
		ns = NRMSECT; nt = NRMTRAC; break;
	case RM5:
		ns = NRMSECT; nt = NTRAC; break;
	case RP:
		ns = NSECT; nt = NTRAC; break;
	default:
		panic("hpecc");
E 11
E 9
	}
E 26
I 26
D 56
	st = &hpst[mi->mi_type];
E 56
E 26
D 9
	hptab.b_active++;
	if (((struct mba_regs *)MBA0)->mba_bcr) {
		i = bp->b_blkno%(NSECT*NTRAC);
		i = ((i/NSECT)<<8)+(i%NSECT);
		i = NSECT*(i>>8) + (i&0377) + b + 1;
		if (i >= NSECT*NTRAC) {
			i -= NSECT*NTRAC;
			rp->hpdc = bp->b_cylin + 1;
		} else
			rp->hpdc = bp->b_cylin;
		rp->hpda = ((i/NSECT)<<8) + (i%NSECT);
		rp->hpcs1 = DCLR|GO;
		((struct mba_regs *)MBA0)->mba_sr = -1;
		((struct mba_regs *)MBA0)->mba_var =
			((map+1)<<9)|((int)bp->b_un.b_addr&0x1ff);
		rp->hpcs1 = RCOM|GO;
		return(1);
	} else
		return(0);
}

short
piget(pad)
{
	register b, savemap;
	register short s;

	savemap = (int)mmap;
	b = (pad>>9)&0x7fffff;
	*(int *)mmap = b|(PG_V|PG_KR);
	mtpr(TBIS, vmmap);
	s = *(short *)&vmmap[pad&0x1ff];
	*(int *)mmap = savemap;
	mtpr(TBIS, vmmap);
	return(s);
}

piput(pad, val)
{
	register b, savemap;
	register short *p;

	savemap = (int)mmap;
	b = (pad>>9)&0x7fffff;
	*(int *)mmap = b|(PG_V|PG_KW);
	mtpr(TBIS, vmmap);
	p = (short *)&vmmap[pad&0x1ff];
	*p = val;
	*(int *)mmap = savemap;
	mtpr(TBIS, vmmap);
E 9
I 9
	cn = bp->b_cylin;
D 26
	sn = bn%(ns*nt) + npf + 1;
	tn = sn/ns;
	sn %= ns;
	cn += tn/nt;
	tn %= nt;
E 26
I 26
D 56
	sn = bn%(st->nspc) + npf + 1;
E 56
I 56
D 112
	sn = bn%(st->nspc) + npf;
E 112
I 112
D 115
	sn = bn%(st->nspc);
E 115
I 115
D 133
	sn = bn%(st->nspc) + npf;
E 115
E 112
E 56
	tn = sn/st->nsect;
	sn %= st->nsect;
	cn += tn/st->ntrak;
	tn %= st->ntrak;
E 133
I 133
	sn = bn % lp->d_secpercyl + npf;
	tn = sn / lp->d_nsectors;
	sn %= lp->d_nsectors;
	cn += tn / lp->d_ntracks;
	tn %= lp->d_ntracks;
E 133
I 117
	bn += npf;
E 117
I 56
	switch (flag) {
D 85
	case ECC:
		{
E 85
I 85
	case ECC: {
E 85
		register int i;
		caddr_t addr;
		struct pte mpte;
		int bit, byte, mask;

		npf--;		/* because block in error is previous block */
I 115
D 142
		bn--;
E 142
I 142
		diskerr(bp, "hp", "soft ecc", LOG_WARNING, npf, lp);
E 142
E 115
I 112
		if (bp->b_flags & B_BAD)
D 142
			bn = sc->sc_badbn;
E 112
D 115
		printf("hp%d%c: soft ecc sn%d\n", dkunit(bp),
E 115
I 115
D 119
		log(KERN_RECOV, "hp%d%c: soft ecc sn%d\n", dkunit(bp),
E 119
I 119
D 122
		log(KERN_RECOV, "hp%d%c: soft ecc sn%d\n", hpunit(bp->b_dev),
E 122
I 122
		log(LOG_WARNING, "hp%d%c: soft ecc sn%d\n", hpunit(bp->b_dev),
E 122
E 119
E 115
D 112
		    'a'+(minor(bp->b_dev)&07), bp->b_blkno + npf);
E 112
I 112
		    'a'+(minor(bp->b_dev)&07), bn);
E 142
I 142
			addlog(" (on replacement sector %d)", sc->sc_badbn);
		addlog("\n");
E 142
E 112
D 92
		mask = rp->hpec2&0xffff;
		i = (rp->hpec1&0xffff) - 1;		/* -1 makes 0 origin */
E 92
I 92
		mask = MASKREG(rp->hpec2);
		i = MASKREG(rp->hpec1) - 1;		/* -1 makes 0 origin */
E 92
		bit = i&07;
		i = (i&~07)>>3;
		byte = i + o;
D 126
		while (i < 512 && (int)ptob(npf)+i < bp->b_bcount && bit > -11) {
E 126
I 126
		while (i < 512 && (int)dbtob(npf)+i < bp->b_bcount && bit > -11) {
E 126
			mpte = mbp->mba_map[npf+btop(byte)];
			addr = ptob(mpte.pg_pfnum) + (byte & PGOFSET);
			putmemc(addr, getmemc(addr)^(mask<<bit));
			byte++;
			i++;
			bit -= 8;
		}
D 112
		if (bcr == 0)
E 112
I 112
D 115
		if ((bp->b_flags & B_BAD) || bcr == 0)
E 115
I 115
		if (bcr == 0)
E 115
E 112
			return (0);
I 59
		npf++;
E 59
		break;
		}

	case SSE:
		rp->hpof |= HPOF_SSEI;
I 112
		if (bp->b_flags & B_BAD) {
			bn = sc->sc_badbn;
			goto fixregs;
		}
E 112
		mbp->mba_bcr = -(bp->b_bcount - (int)ptob(npf));
		break;

D 57
#ifndef NOBADBLOCK
E 57
I 57
D 85
#ifndef NOBADSECT
E 85
E 57
	case BSE:
I 133
		if (sc->sc_state == OPENRAW)
			return (0);
E 133
I 112
 		if (rp->hpof & HPOF_SSEI)
 			sn++;
E 112
#ifdef HPBDEBUG
		if (hpbdebug)
D 123
		printf("hpecc, BSE: bn %d cn %d tn %d sn %d\n", bn, cn, tn, sn);
E 123
I 123
		log(LOG_DEBUG, "hpecc, BSE: bn %d cn %d tn %d sn %d\n", bn, cn, tn, sn);
E 123
#endif
I 89
D 92
 		if (rp->hpof&HPOF_SSEI)		/* make sure isbad gets the
 						 * proper sector number to look
 			sn++;			 * up!		*/
E 92
I 92
D 112
 		if (rp->hpof&HPOF_SSEI)
 			sn++;
E 112
I 112
		if (bp->b_flags & B_BAD)
			return (0);
E 112
E 92
E 89
		if ((bn = isbad(&hpbad[mi->mi_unit], cn, tn, sn)) < 0)
D 92
			return(0);
E 92
I 92
			return (0);
E 92
		bp->b_flags |= B_BAD;
		bp->b_error = npf + 1;
I 112
 		rp->hpof &= ~HPOF_SSEI;
E 112
D 133
		bn = st->ncyl*st->nspc - st->nsect - 1 - bn;
E 133
I 133
		bn = lp->d_ncylinders * lp->d_secpercyl -
		    lp->d_nsectors - 1 - bn;
E 133
I 112
		sc->sc_badbn = bn;
	fixregs:
E 112
D 133
		cn = bn/st->nspc;
		sn = bn%st->nspc;
		tn = sn/st->nsect;
		sn %= st->nsect;
E 133
I 133
		cn = bn / lp->d_secpercyl;
		sn = bn % lp->d_secpercyl;
		tn = sn / lp->d_nsectors;
		sn %= lp->d_nsectors;
E 133
D 120
		mbp->mba_bcr = -512;
E 120
I 120
D 128
		mbp->mba_bcr = -(min(512, bp->b_bcount - (int)ptob(npf)));
E 128
I 128
		bcr = bp->b_bcount - (int)ptob(npf);
		bcr = MIN(bcr, 512);
		mbp->mba_bcr = -bcr;
E 128
E 120
I 89
D 112
 		rp->hpof &= ~HPOF_SSEI;
E 112
E 89
#ifdef HPBDEBUG
		if (hpbdebug)
D 123
		printf("revector to cn %d tn %d sn %d\n", cn, tn, sn);
E 123
I 123
		log(LOG_DEBUG, "revector to cn %d tn %d sn %d\n", cn, tn, sn);
E 123
#endif
		break;

	case CONT:
#ifdef HPBDEBUG
		if (hpbdebug)
D 123
		printf("hpecc, CONT: bn %d cn %d tn %d sn %d\n", bn,cn,tn,sn);
E 123
I 123
		log(LOG_DEBUG, "hpecc, CONT: bn %d cn %d tn %d sn %d\n", bn,cn,tn,sn);
E 123
#endif
D 112
		npf = bp->b_error;
E 112
		bp->b_flags &= ~B_BAD;
D 120
		mbp->mba_bcr = -(bp->b_bcount - (int)ptob(npf));
D 92
		if ((mbp->mba_bcr & 0xffff) == 0)
			return(0);
E 92
I 92
		if (MASKREG(mbp->mba_bcr) == 0)
E 120
I 120
		if ((int)ptob(npf) >= bp->b_bcount)
E 120
			return (0);
I 120
		mbp->mba_bcr = -(bp->b_bcount - (int)ptob(npf));
E 120
E 92
		break;
D 85
#endif
E 85
	}
	rp->hpcs1 = HP_DCLR|HP_GO;
E 56
I 39
D 53
#ifdef notdef
	if (rp->hpof&SSEI)
E 53
I 53
D 112
	if (rp->hpof&HPOF_SSEI)
E 112
I 112
	if (rp->hpof & HPOF_SSEI)
E 112
E 53
		sn++;
D 53
#endif
E 53
E 39
E 26
	rp->hpdc = cn;
	rp->hpda = (tn<<8) + sn;
	mbp->mba_sr = -1;
D 56
	mbp->mba_var = (int)ptob(reg+1) + o;
D 31
	rp->hpcs1 = RCOM|GO;
E 31
I 31
	rp->hpcs1 = HP_RCOM|HP_GO;
#endif
E 56
I 56
	mbp->mba_var = (int)ptob(npf) + o;
	rp->hpcs1 = bp->b_flags&B_READ ? HP_RCOM|HP_GO : HP_WCOM|HP_GO;
	mi->mi_tab.b_errcnt = 0;	/* error has been corrected */
I 112
D 123
	sc->sc_pgdone = npf;
E 123
I 123
	sc->sc_blkdone = npf;
E 123
E 112
E 56
E 31
	return (1);
I 24
}

#define	DBSIZE	20

hpdump(dev)
	dev_t dev;
{
I 26
D 43
	register struct mba_info *mi;
E 43
I 43
	register struct mba_device *mi;
E 43
	register struct mba_regs *mba;
E 26
D 31
	struct device *hpaddr;
E 31
I 31
	struct hpdevice *hpaddr;
E 31
	char *start;
D 26
	int num, blk, unit, nsect, ntrak, nspc;
	struct size *sizes;
E 26
I 26
	int num, unit;
D 133
	register struct hpst *st;
E 133
I 133
	register struct disklabel *lp;
E 133
E 26

	num = maxfree;
	start = 0;
D 119
	unit = minor(dev) >> 3;
E 119
I 119
	unit = hpunit(dev);
E 119
D 38
	if (unit >= NHP) {
		printf("bad unit\n");
		return (-1);
	}
E 38
I 38
	if (unit >= NHP)
		return (ENXIO);
E 38
D 26
	HPPHYSMBA->mba_cr = MBAINIT;
	hpaddr = mbadev(HPPHYSMBA, unit);
	if (hp_type[unit] == 0)
		hp_type[unit] = hpaddr->hpdt;
	if((hpaddr->hpds & VV) == 0) {
E 26
I 26
#define	phys(a,b)	((b)((int)(a)&0x7fffffff))
D 43
	mi = phys(hpinfo[unit],struct mba_info *);
E 43
I 43
	mi = phys(hpinfo[unit],struct mba_device *);
E 43
D 31
	if (mi->mi_alive == 0) {
E 31
I 31
D 38
	if (mi == 0 || mi->mi_alive == 0) {
E 31
		printf("dna\n");
		return (-1);
	}
E 38
I 38
	if (mi == 0 || mi->mi_alive == 0)
		return (ENXIO);
I 133
	lp = &hplabel[unit];
E 133
E 38
	mba = phys(mi->mi_hd, struct mba_hd *)->mh_physmba;
D 45
	mba->mba_cr = MBAINIT;
E 45
I 45
	mba->mba_cr = MBCR_INIT;
E 45
D 31
	hpaddr = (struct device *)&mba->mba_drv[mi->mi_drive];
	if ((hpaddr->hpds & VV) == 0) {
		hpaddr->hpcs1 = DCLR|GO;
E 26
		hpaddr->hpcs1 = PRESET|GO;
		hpaddr->hpof = FMT22;
E 31
I 31
	hpaddr = (struct hpdevice *)&mba->mba_drv[mi->mi_drive];
D 44
	if ((hpaddr->hpds & HP_VV) == 0) {
E 44
I 44
	if ((hpaddr->hpds & HPDS_VV) == 0) {
E 44
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
		hpaddr->hpcs1 = HP_PRESET|HP_GO;
D 44
		hpaddr->hpof = HP_FMT22;
E 44
I 44
		hpaddr->hpof = HPOF_FMT22;
E 44
E 31
	}
D 26
	switch (hp_type[unit]) {
	case RM5:
		nsect = NRMSECT; ntrak = NTRAC; sizes = rm5_sizes; break;
	case RM:
		nsect = NRMSECT; ntrak = NRMTRAC; sizes = rm_sizes; break;
	case RP:
		nsect = NSECT; ntrak = NTRAC; sizes = hp_sizes; break;
	default:
		printf("hp unknown type %x\n", hp_type[unit]);
E 26
I 26
D 133
	st = &hpst[mi->mi_type];
E 133
D 38
	if (dumplo < 0 || dumplo + num >= st->sizes[minor(dev)&07].nblocks) {
		printf("oor\n");
E 26
		return (-1);
	}
E 38
I 38
D 118
	if (dumplo < 0 || dumplo + num >= st->sizes[minor(dev)&07].nblocks)
E 118
I 118
	if (dumplo < 0)
E 118
		return (EINVAL);
I 118
D 133
	if (dumplo + num >= st->sizes[minor(dev)&07].nblocks)
		num = st->sizes[minor(dev)&07].nblocks - dumplo;
E 133
I 133
	if (dumplo + num >= lp->d_partitions[hppart(dev)].p_size)
		num = lp->d_partitions[hppart(dev)].p_size - dumplo;
E 133
E 118
E 38
D 26
	if (dumplo < 0 || dumplo + num >= sizes[minor(dev)&07].nblocks) {
		printf("dumplo+num, sizes %d %d\n", dumplo+num, sizes[minor(dev)&07].nblocks);
		return (-1);
	}
	nspc = nsect * ntrak;
E 26
	while (num > 0) {
D 26
		register struct pte *hpte = HPPHYSMBA->mba_map;
E 26
I 26
		register struct pte *hpte = mba->mba_map;
E 26
		register int i;
D 26
		int cn, sn, tn;
E 26
I 26
		int blk, cn, sn, tn;
E 26
		daddr_t bn;

		blk = num > DBSIZE ? DBSIZE : num;
D 139
		bn = dumplo + btop(start);
E 139
I 139
		bn = dumplo + btodb(start);
E 139
D 26
		cn = bn/nspc + sizes[minor(dev)&07].cyloff;
		sn = bn%nspc;
		tn = sn/nsect;
		sn = sn%nsect;
E 26
I 26
D 133
		cn = bn/st->nspc + st->sizes[minor(dev)&07].cyloff;
		sn = bn%st->nspc;
		tn = sn/st->nsect;
		sn = sn%st->nsect;
E 133
I 133
		cn = (bn + lp->d_partitions[hppart(dev)].p_offset) /
		    lp->d_secpercyl;
		sn = bn % lp->d_secpercyl;
		tn = sn / lp->d_nsectors;
		sn = sn % lp->d_nsectors;
E 133
E 26
		hpaddr->hpdc = cn;
		hpaddr->hpda = (tn << 8) + sn;
		for (i = 0; i < blk; i++)
			*(int *)hpte++ = (btop(start)+i) | PG_V;
D 26
		((struct mba_regs *)HPPHYSMBA)->mba_sr = -1;
		((struct mba_regs *)HPPHYSMBA)->mba_bcr = -(blk*NBPG);
		((struct mba_regs *)HPPHYSMBA)->mba_var = 0;
E 26
I 26
		mba->mba_sr = -1;
		mba->mba_bcr = -(blk*NBPG);
		mba->mba_var = 0;
E 26
D 31
		hpaddr->hpcs1 = WCOM | GO;
		while ((hpaddr->hpds & DRY) == 0)
E 31
I 31
		hpaddr->hpcs1 = HP_WCOM | HP_GO;
D 44
		while ((hpaddr->hpds & HP_DRY) == 0)
E 44
I 44
		while ((hpaddr->hpds & HPDS_DRY) == 0)
E 44
E 31
D 111
			;
E 111
I 111
			DELAY(10);
E 111
D 31
		if (hpaddr->hpds&ERR) {
E 31
I 31
D 38
		if (hpaddr->hpds&HP_ERR) {
E 31
D 25
			printf("hp dump dsk err: (%d,%d,%d) ds=%X er=%X\n",
E 25
I 25
D 26
			printf("hp dump dsk err: (%d,%d,%d) ds=%x er=%x\n",
E 26
I 26
			printf("dskerr: (%d,%d,%d) ds=%x er=%x\n",
E 26
E 25
			    cn, tn, sn, hpaddr->hpds, hpaddr->hper1);
			return (-1);
		}
E 38
I 38
D 44
		if (hpaddr->hpds&HP_ERR)
E 44
I 44
		if (hpaddr->hpds&HPDS_ERR)
E 44
			return (EIO);
E 38
		start += blk*NBPG;
		num -= blk;
	}
	return (0);
I 26
D 29
}

hpdkinit()
{
	/* I don't really care what this does .. kre */
E 29
E 26
E 24
E 9
}
I 100

hpsize(dev)
	dev_t dev;
{
D 119
	int unit = minor(dev) >> 3;
E 119
I 119
D 133
	int unit = hpunit(dev);
E 133
I 133
	register int unit = hpunit(dev);
E 133
E 119
	struct mba_device *mi;
D 133
	struct hpst *st;
E 133

D 133
	if (unit >= NHP || (mi = hpinfo[unit]) == 0 || mi->mi_alive == 0)
E 133
I 133
	if (unit >= NHP || (mi = hpinfo[unit]) == 0 || mi->mi_alive == 0 ||
	    hpsoftc[unit].sc_state != OPEN)
E 133
		return (-1);
D 133
	st = &hpst[mi->mi_type];
	return ((int)st->sizes[minor(dev) & 07].nblocks);
E 133
I 133
	return ((int)hplabel[unit].d_partitions[hppart(dev)].p_size);
E 133
}
I 133

#ifdef COMPAT_42
/*
 * Compatibility code to fake up pack label
 * for unlabeled disks.
 */
struct	size {
	daddr_t	nblocks;
	int	cyloff;
} rp06_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 37 */
	33440,	38,		/* B=cyl 38 thru 117 */
	340670,	0,		/* C=cyl 0 thru 814 */
	15884,	118,		/* D=cyl 118 thru 155 */
	55936,	156,		/* E=cyl 156 thru 289 */
	219384,	290,		/* F=cyl 290 thru 814 */
D 137
	291280,	118,		/* G=cyl 118 thru 814 */
E 137
I 137
	291192,	118,		/* G=cyl 118 thru 814 */
E 137
	0,	0,
}, rp05_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 37 */
	33440,	38,		/* B=cyl 38 thru 117 */
	171798,	0,		/* C=cyl 0 thru 410 */
	15884,	118,		/* D=cyl 118 thru 155 */
	55936,	156,		/* E=cyl 156 thru 289 */
	50512,	290,		/* F=cyl 290 thru 410 */
	122408,	118,		/* G=cyl 118 thru 410 */
	0,	0,
}, rm03_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 99 */
	33440,	100,		/* B=cyl 100 thru 308 */
	131680,	0,		/* C=cyl 0 thru 822 */
	15884,	309,		/* D=cyl 309 thru 408 */
	55936,	409,		/* E=cyl 409 thru 758 */
	10144,	759,		/* F=cyl 759 thru 822 */
	82144,	309,		/* G=cyl 309 thru 822 */
	0,	0,
}, rm05_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 26 */
	33440,	27,		/* B=cyl 27 thru 81 */
	500384,	0,		/* C=cyl 0 thru 822 */
	15884,	562,		/* D=cyl 562 thru 588 */
	55936,	589,		/* E=cyl 589 thru 680 */
	86240,	681,		/* F=cyl 681 thru 822 */
	158592,	562,		/* G=cyl 562 thru 822 */
	291346,	82,		/* H=cyl 82 thru 561 */
}, rm80_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 36 */
	33440,	37,		/* B=cyl 37 thru 114 */
	242606,	0,		/* C=cyl 0 thru 558 */
	15884,	115,		/* D=cyl 115 thru 151 */
	55936,	152,		/* E=cyl 152 thru 280 */
	120559,	281,		/* F=cyl 281 thru 558 */
	192603,	115,		/* G=cyl 115 thru 558 */
	0,	0,
}, rp07_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 9 */
	66880,	10,		/* B=cyl 10 thru 51 */
	1008000, 0,		/* C=cyl 0 thru 629 */
	15884,	235,		/* D=cyl 235 thru 244 */
	307200,	245,		/* E=cyl 245 thru 436 */
	308650,	437,		/* F=cyl 437 thru 629 */
	631850,	235,		/* G=cyl 235 thru 629 */
	291346,	52,		/* H=cyl 52 thru 234 */
}, cdc9775_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 12 */
	66880,	13,		/* B=cyl 13 thru 65 */
	1077760, 0,		/* C=cyl 0 thru 841 */
	15884,	294,		/* D=cyl 294 thru 306 */
	307200,	307,		/* E=cyl 307 thru 546 */
	377440,	547,		/* F=cyl 547 thru 841 */
	701280,	294,		/* G=cyl 294 thru 841 */
	291346,	66,		/* H=cyl 66 thru 293 */
}, cdc9730_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 49 */
	33440,	50,		/* B=cyl 50 thru 154 */
	263360,	0,		/* C=cyl 0 thru 822 */
	15884,	155,		/* D=cyl 155 thru 204 */
	55936,	205,		/* E=cyl 205 thru 379 */
	141664,	380,		/* F=cyl 380 thru 822 */
	213664,	155,		/* G=cyl 155 thru 822 */
	0,	0,
}, capricorn_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 31 */
	33440,	32,		/* B=cyl 32 thru 97 */
	524288,	0,		/* C=cyl 0 thru 1023 */
	15884,	668,		/* D=cyl 668 thru 699 */
	55936,	700,		/* E=cyl 700 thru 809 */
	109472,	810,		/* F=cyl 810 thru 1023 */
	182176,	668,		/* G=cyl 668 thru 1023 */
	291346,	98,		/* H=cyl 98 thru 667 */
}, eagle_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 16 */
	66880,	17,		/* B=cyl 17 thru 86 */
	808320,	0,		/* C=cyl 0 thru 841 */
	15884,	391,		/* D=cyl 391 thru 407 */
	307200,	408,		/* E=cyl 408 thru 727 */
	109296,	728,		/* F=cyl 728 thru 841 */
	432816,	391,		/* G=cyl 391 thru 841 */
	291346,	87,		/* H=cyl 87 thru 390 */
}, ampex_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 26 */
	33440,	27,		/* B=cyl 27 thru 81 */
	495520,	0,		/* C=cyl 0 thru 814 */
	15884,	562,		/* D=cyl 562 thru 588 */
	55936,	589,		/* E=cyl 589 thru 680 */
	81312,	681,		/* F=cyl 681 thru 814 */
	153664,	562,		/* G=cyl 562 thru 814 */
	291346,	82,		/* H=cyl 82 thru 561 */
}, fj2361_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 12 */
	66880,	13,		/* B=cyl 13 thru 65 */
	1077760, 0,		/* C=cyl 0 thru 841 */
	15884,	294,		/* D=cyl 294 thru 306 */
	307200,	307,		/* E=cyl 307 thru 546 */
	377408,	547,		/* F=cyl 547 thru 841 */
	701248,	294,		/* G=cyl 294 thru 841 */
	291346,	66,		/* H=cyl 66 thru 293 */
I 146
}, fj2361a_sizes[8] = {
	15884,	0,		/* A=cyl 0 thru 11 */
	66880,	12,		/* B=cyl 12 thru 61 */
	1145120, 0,		/* C=cyl 0 thru 841 */
	15884,	277,		/* D=cyl 277 thru 288 */
	307200,	289,		/* E=cyl 289 thru 514 */
	444516,	515,		/* F=cyl 515 thru 841 */
	768196,	277,		/* G=cyl 277 thru 841 */
	291346,	62,		/* H=cyl 62 thru 276 */
E 146
};

/*
 * These variable are all measured in sectors.  
 * Sdist is how much to "lead" in the search for a desired sector
 * (i.e. if want N, search for N-sdist.)
 * Maxdist and mindist define the region right before our desired sector within
 * which we don't bother searching.  We don't search when we are already less
 * then maxdist and more than mindist sectors "before" our desired sector.
 * Maxdist should be >= sdist.
 * 
 * Beware, sdist, mindist and maxdist are not well tuned
 * for many of the drives listed in this table.
 * Try patching things with something i/o intensive
 * running and watch iostat.
I 144
 *
 * The order of these entries must agree with the indices in hptypes[].
E 144
 */
struct hpst {
	short	nsect;		/* # sectors/track */
	short	ntrak;		/* # tracks/cylinder */
	short	nspc;		/* # sector/cylinders */
	short	ncyl;		/* # cylinders */
	struct	size *sizes;	/* partition tables */
	short	sdist;		/* seek distance metric */
	short	maxdist;	/* boundaries of non-searched area */
	short	mindist;	/* preceding the target sector */
	char	*name;		/* name of disk type */
} hpst[] = {
    { 32, 5,	32*5,	823,	rm03_sizes,	7, 4, 1, "RM03" },
    { 32, 19,	32*19,	823,	rm05_sizes,	7, 4, 1, "RM05" },
    { 22,19,	22*19,	815,	rp06_sizes,	7, 4, 1, "RP06"},
    { 31, 14, 	31*14,	559,	rm80_sizes,	7, 4, 1, "RM80"},
    { 22, 19,	22*19,	411,	rp05_sizes,	7, 4, 1, "RP04"},
    { 22, 19,	22*19,	411,	rp05_sizes,	7, 4, 1, "RP05"},
    { 50, 32,	50*32,	630,	rp07_sizes,    15, 8, 3, "RP07"},
    { 1, 1,	1,	1,	0,		0, 0, 0, "ML11A"},
    { 1, 1,	1,	1,	0,		0, 0, 0, "ML11B" },
    { 32, 40,	32*40,	843,	cdc9775_sizes,	7, 4, 1, "9775" },
    { 32, 10,	32*10,	823,	cdc9730_sizes,	7, 4, 1, "9730-160" },
    { 32, 16,	32*16,	1024,	capricorn_sizes,10,4, 3, "capricorn" },
    { 48, 20,	48*20,	842,	eagle_sizes,   15, 8, 3, "eagle" },
    { 32, 19,	32*19,	815,	ampex_sizes,	7, 4, 1, "9300" },
    { 64, 20,	64*20,	842,	fj2361_sizes,  15, 8, 3, "2361" },
I 146
    { 68, 20,	68*20,	842,	fj2361a_sizes, 15, 8, 3, "2361a" },
E 146
};

/*
 * Map apparent MASSBUS drive type into manufacturer
 * specific configuration.  For SI controllers this is done
 * based on codes in the serial number register.  For
 * EMULEX controllers, the track and sector attributes are
 * used when the drive type is an RM02 (not supported by DEC).
 */
hpmaptype(mi, lp)
	register struct mba_device *mi;
	register struct disklabel *lp;
{
	register struct hpdevice *hpaddr = (struct hpdevice *)mi->mi_drv;
	register int type = mi->mi_type;
	register struct hpst *st;
	register i;

	/*
	 * Model-byte processing for SI controllers.
	 * NB:  Only deals with RM03 and RM05 emulations.
	 */
	if (type == HPDT_RM03 || type == HPDT_RM05) {
		int hpsn = hpaddr->hpsn;

		if ((hpsn & SIMB_LU) == mi->mi_drive)
		switch ((hpsn & SIMB_MB) & ~(SIMB_S6|SIRM03|SIRM05)) {

		case SI9775D:
			type = HPDT_9775;
			break;

		case SI9730D:
			type = HPDT_9730;
			break;

		case SI9766:
			type = HPDT_RM05;
			break;

		case SI9762:
			type = HPDT_RM03;
			break;

		case SICAPD:
			type = HPDT_CAPRICORN;
			break;

		case SI9751D:
			type = HPDT_EAGLE;
			break;
		}
I 147
		mi->mi_type = type;
E 147
	}

	/*
	 * EMULEX SC750 or SC780.  Poke the holding register.
	 */
	if (type == HPDT_RM02) {
		int nsectors, ntracks, ncyl;

		hpaddr->hpof = HPOF_FMT22;
		mbclrattn(mi);
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXTRAK;
		ntracks = MASKREG(hpaddr->hphr) + 1;
		DELAY(100);
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXSECT;
		nsectors = MASKREG(hpaddr->hphr) + 1;
		DELAY(100);
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXCYL;
		ncyl = MASKREG(hpaddr->hphr) + 1;
		for (type = 0; hptypes[type] != 0; type++)
			if (hpst[type].nsect == nsectors &&
			    hpst[type].ntrak == ntracks &&
			    hpst[type].ncyl == ncyl)
				break;

I 139
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
		mbclrattn(mi);		/* conservative */
E 139
		if (hptypes[type] == 0) {
	printf("hp%d: %d sectors, %d tracks, %d cylinders: unknown device\n",
				mi->mi_unit, nsectors, ntracks, ncyl);
D 139
			type = HPDT_RM02;
E 139
I 139
			lp->d_nsectors = nsectors;
			lp->d_ntracks = ntracks;
			lp->d_ncylinders = ncyl;
			lp->d_secpercyl = nsectors*ntracks;
			lp->d_secperunit = lp->d_secpercyl * lp->d_ncylinders;
I 144
#ifdef notdef		/* set elsewhere */
E 144
			lp->d_npartitions = 1;
			lp->d_partitions[0].p_offset = 0;
I 144
#endif
E 144
			lp->d_partitions[0].p_size = lp->d_secperunit;
			return (0);
E 139
		}
I 147
		mi->mi_type = type;
E 147
D 139
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
		mbclrattn(mi);		/* conservative */
E 139
	}

	/*
	 * set up minimal disk label.
	 */
	st = &hpst[type];
I 135
D 139
	lp->d_secsize = 512;
E 139
E 135
	lp->d_nsectors = st->nsect;
	lp->d_ntracks = st->ntrak;
	lp->d_secpercyl = st->nspc;
	lp->d_ncylinders = st->ncyl;
	lp->d_secperunit = st->nspc * st->ncyl;
	lp->d_sdist = st->sdist;
	lp->d_mindist = st->mindist;
	lp->d_maxdist = st->maxdist;
	bcopy(hpst[type].name, lp->d_typename, sizeof(lp->d_typename));
	lp->d_npartitions = 8;
	for (i = 0; i < 8; i++) {
		lp->d_partitions[i].p_offset = st->sizes[i].cyloff *
		    lp->d_secpercyl;
		lp->d_partitions[i].p_size = st->sizes[i].nblocks;
	}
D 147
	return (type);
E 147
I 147
	return (1);
E 147
}
#endif COMPAT_42
E 133
E 100
I 17
#endif
E 17
E 1
