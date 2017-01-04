h13444
s 00000/00002/00351
d D 7.28 04/02/28 23:50:39 msokolov 86 85
c decboot/bootdec are here now, no more bootrd link
e
s 00002/00001/00351
d D 7.27 04/02/28 22:48:09 msokolov 85 84
c add startvmb.c
e
s 00021/00007/00331
d D 7.26 04/02/07 19:01:28 msokolov 84 83
c implemented bootdec and tons of VMB and ROM stuff to go with it
e
s 00044/00033/00294
d D 7.25 04/02/07 11:35:15 msokolov 83 82
c started standalone system revamping
e
s 00004/00000/00323
d D 7.24 03/11/16 14:30:31 msokolov 82 81
c say hello to one more console medium: rx50
e
s 00020/00006/00303
d D 7.23 01/02/14 13:08:12 msokolov 81 80
c build small bootblocks without -DCOMPAT_42
e
s 00030/00009/00279
d D 7.22 99/09/05 14:58:07 msokolov 80 79
c Build different bootxx's with different sets of supported CPUs (750 only for
c most, 750 + 8200 + MVAXen for bootra, and 8200 only for bootkra). Trying to use
c the same SMOPTS for all bootxx's no longer works.
e
s 00005/00048/00283
d D 7.21 99/01/14 18:00:32 msokolov 79 78
c Pitch the 730-only standalone programs.
c They are now totally useless since they are much larger than 12.5 KB no
c matter what you do.
c If you can't load files larger than 12.5 KB, get a ucode patch!
e
s 00001/00001/00330
d D 7.20 99/01/12 00:14:22 msokolov 78 77
c confkra.c was missing from the clean target
e
s 00007/00003/00324
d D 7.19 99/01/12 00:12:03 msokolov 77 76
c Split the install target into installint (copies to other subdirs of /sys,
c normally executed by /sys programmers) and installext (copies to /, /stand,
c and /usr/mdec, normally executed by root).
e
s 00002/00002/00325
d D 7.18 89/03/21 10:04:10 karels 76 75
c ls has private getfile
e
s 00014/00171/00313
d D 7.17 88/10/31 16:09:53 bostic 75 74
c add labels, cleanup dependencies, use ${LS} so bozos with . in front
c of $PATH don't get surprised
e
s 00002/00002/00482
d D 7.16 88/08/27 07:22:41 tef 74 73
c Add support for microvax 3000.
e
s 00011/00005/00473
d D 7.15 88/07/09 10:57:25 bostic 73 72
c install approved copyright notice
e
s 00076/00058/00402
d D 7.14 88/07/08 16:25:31 bostic 72 71
c add -DVAX8200, bootkra, kdb, MDEC macro, general cleanup
e
s 00039/00025/00421
d D 7.13 88/07/07 20:34:23 karels 71 70
c need to skip unneeded machines w/-DSMALL, truncate bootxx's
e
s 00022/00014/00424
d D 7.12 88/07/01 17:17:05 karels 70 69
c need to omit qv/qd from bootxx's
e
s 00004/00002/00434
d D 7.11 88/07/01 15:21:07 karels 69 68
c /stand; mkdir ../vaxdist/tp
e
s 00003/00003/00433
d D 7.10 88/06/18 12:35:06 bostic 68 67
c dist -> vaxdist
e
s 00026/00021/00410
d D 7.9 88/06/06 15:47:48 marc 67 66
c support for display drivers as console
e
s 00238/00194/00193
d D 7.8 88/05/24 13:27:29 bostic 66 65
c change to dev(a,b,c,d) format
e
s 00006/00018/00381
d D 7.7 88/01/28 20:52:47 karels 65 64
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00398
d D 7.6 87/12/12 21:20:24 bostic 64 63
c remove libsa.a on clean
e
s 00004/00004/00395
d D 7.5 87/09/16 13:00:54 karels 63 62
c don't optimize the drivers!
e
s 00019/00044/00380
d D 7.4 87/04/17 15:58:14 karels 62 61
c rm bootxx conversion (now all same), use CFLAGS
e
s 00001/00001/00423
d D 7.3 87/02/21 11:35:52 karels 61 60
c restore keywords
e
s 00046/00032/00378
d D 7.2 87/02/21 11:33:40 karels 60 59
c squish 750 versions as needed, other cleanups
e
s 00001/00001/00409
d D 7.1 86/06/05 01:48:09 mckusick 59 58
c 4.3BSD release version
e
s 00013/00009/00397
d D 6.13 86/05/15 10:37:10 karels 58 57
c install copy, drtest, pcs750.bin
e
s 00070/00067/00336
d D 6.12 86/04/14 10:59:58 karels 57 56
c additional dependencies
e
s 00165/00027/00238
d D 6.11 86/02/05 17:14:29 karels 56 54
c make depend
e
s 00165/00027/00238
d R 6.11 86/02/04 15:40:32 karels 55 54
c make depend
e
s 00036/00022/00229
d D 6.10 85/11/08 19:14:49 karels 54 53
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00005/00003/00246
d D 6.9 85/10/17 13:11:23 karels 53 52
c mv /tp to ../dist; install /boot, /format
e
s 00038/00036/00211
d D 6.8 85/10/11 11:50:07 karels 52 51
c move libsa.a to stand
e
s 00013/00013/00234
d D 6.7 85/09/18 03:29:14 lepreau 51 50
c make work for non-root
e
s 00004/00000/00243
d D 6.6 85/08/09 15:15:02 bloom 50 49
c set up consolerl directory as well
e
s 00001/00001/00242
d D 6.5 85/08/02 18:55:00 bloom 49 48
c add support for 8600
e
s 00007/00002/00236
d D 6.4 85/06/08 12:54:11 mckusick 48 47
c Add copyright
e
s 00001/00001/00237
d D 6.3 84/11/27 12:53:52 karels 47 46
c includes from ../h
e
s 00001/00001/00237
d D 6.2 83/09/25 13:22:27 karels 46 45
c no JUSTASK for 730boot
e
s 00000/00000/00238
d D 6.1 83/08/12 09:28:18 karels 45 44
c synchronize for 4.2
e
s 00001/00001/00237
d D 4.34 83/08/11 09:11:08 karels 44 42
c make 730boot with 730boot.o
e
s 00000/00000/00238
d R 6.1 83/07/29 07:46:22 sam 43 42
c 4.2 distribution
e
s 00004/00004/00234
d D 4.33 83/07/20 22:33:36 sam 42 40
c a bit of cleanup for making distribution cassettes
e
s 00008/00008/00230
d R 4.33 83/07/20 22:23:28 sam 41 40
c rename things a bit for making distribution cassettes
e
s 00026/00029/00212
d D 4.32 83/07/08 03:38:16 sam 40 39
c make new drivers default and only use old ones in 750 boots
e
s 00021/00006/00220
d D 4.31 83/07/06 21:31:51 sam 39 38
c cleanup for 730's and 750's
e
s 00001/00001/00225
d D 4.30 83/06/16 18:39:52 sam 38 37
c from gross
e
s 00004/00002/00222
d D 4.29 83/04/02 18:36:19 sam 37 36
c tp format made from wrong components
e
s 00033/00047/00191
d D 4.28 83/02/20 20:24:02 sam 36 35
c cleanup boot*; make 730 format and drtest smaller (too big still?)
e
s 00006/00004/00232
d D 4.27 83/02/18 01:01:43 sam 35 34
c add device type mapping routines
e
s 00064/00004/00172
d D 4.26 83/02/16 23:44:40 sam 34 33
c uda50 and rl11 boot blocks; 730 crud
e
s 00002/00001/00174
d D 4.25 83/02/12 15:39:15 sam 33 31
c add tpformat
e
s 00001/00001/00174
d R 4.25 83/02/12 15:28:20 sam 32 31
c make tpformat right
e
s 00001/00002/00174
d D 4.24 83/02/12 15:06:52 sam 31 30
c add tape version of format
e
s 00023/00028/00153
d D 4.23 83/02/04 08:58:06 sam 30 29
c merge upchk and hpchk, etc. into format and drtest
e
s 00006/00000/00175
d D 4.22 83/01/23 18:19:35 sam 29 28
c crud
e
s 00002/00001/00173
d D 4.21 83/01/20 16:43:50 sam 28 27
c remove everything
e
s 00010/00010/00164
d D 4.20 83/01/18 15:15:25 helge 27 26
c fixed typo (isbad is in file dkbad)
e
s 00011/00008/00163
d D 4.19 83/01/18 14:10:39 sam 26 24
c reference common isbad in vax directory
e
s 00003/00010/00161
d R 4.19 83/01/11 09:29:15 helge 25 24
c drtest has been merged
e
s 00027/00003/00144
d D 4.18 82/12/30 15:30:28 sam 24 23
c add ioctl's + errno; fix chk to work with new stuff
e
s 00010/00010/00137
d D 4.17 82/12/19 16:54:50 sam 23 22
c pte.h
e
s 00004/00004/00143
d D 4.16 82/11/13 23:14:58 sam 22 21
c move includes for 4.1c directory layout
e
s 00049/00044/00098
d D 4.15 82/08/01 19:35:35 sam 21 20
c bootstraps for new file system are lots different....
e
s 00102/00070/00040
d D 4.14 82/07/15 21:31:19 root 20 19
c new boot scheme
e
s 00002/00002/00108
d D 4.13 81/12/01 09:37:44 sam 19 18
c added ut.c
e
s 00002/00002/00108
d D 4.12 81/11/12 13:47:35 root 18 17
c added in uda and mt support
e
s 00002/00002/00108
d D 4.11 81/05/10 21:11:41 wnj 17 16
c add imptst
e
s 00005/00001/00105
d D 4.10 81/05/10 00:41:30 root 16 15
c add imptst
e
s 00001/00001/00105
d D 4.9 81/04/15 02:38:17 wnj 15 14
c s/730/7zz/
e
s 00004/00002/00102
d D 4.8 81/04/03 03:00:23 root 14 13
c make install does make all
e
s 00006/00006/00098
d D 4.7 81/03/22 20:52:06 wnj 13 12
c fixes
e
s 00005/00005/00099
d D 4.6 81/03/21 17:28:30 wnj 12 11
c target /tp; add 730
e
s 00004/00004/00100
d D 4.5 81/03/16 00:54:30 wnj 11 10
c fixes for generic functionality
e
s 00031/00058/00073
d D 4.4 81/03/15 20:50:24 wnj 10 9
c 
e
s 00027/00009/00104
d D 4.3 81/02/15 13:07:33 wnj 9 8
c add prconf
e
s 00012/00007/00101
d D 4.2 80/12/26 12:29:38 wnj 8 7
c cleanpu adding 750
e
s 00000/00000/00108
d D 4.1 80/11/09 16:29:25 bill 7 6
c stamp for 4bsd
e
s 00012/00003/00096
d D 1.6 80/10/22 16:48:24 bill 6 5
c fix /sys/boot
e
s 00018/00010/00081
d D 1.5 80/10/19 01:17:52 bill 5 4
c add destdin and vgrindt
e
s 00021/00003/00070
d D 1.4 80/09/30 23:03:48 bill 4 3
c misc additions (tpicheck, etc)
e
s 00001/00001/00072
d D 1.3 80/07/28 09:42:43 bill 3 2
c rm tpmkfs tprestor
e
s 00001/00001/00072
d D 1.2 80/07/21 10:38:41 bill 2 1
c reloc=70000
e
s 00073/00000/00000
d D 1.1 80/06/28 10:42:55 bill 1 0
c date and time created 80/06/28 10:42:55 by bill
e
u
U
t
T
I 1
D 10
#	%M%	%I%	%G%
E 10
I 10
D 48
#	%M%	%I%	%E%
E 10

E 48
I 48
#
D 59
# Copyright (c) 1980 Regents of the University of California.
E 59
I 59
D 60
# Copyright (c) 1980, 1986 Regents of the University of California.
E 60
I 60
D 66
# Copyright (c) 1980 Regents of the University of California.
E 60
E 59
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 66
I 66
# Copyright (c) 1980, 1988 Regents of the University of California.
# All rights reserved.
E 66
#
I 66
# Redistribution and use in source and binary forms are permitted
D 73
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 73
I 73
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 73
#
E 66
D 60
#	%W% (Berkeley) %G%
E 60
I 60
D 61
#	@(#)Makefile	6.13 (Berkeley) 5/15/86
E 61
I 61
#	%W% (Berkeley) %G%
E 61
E 60
#
I 73

E 73
E 48
I 8
D 10
CPU=	780
E 10
E 8
I 5
D 20
DESTDIR=
E 20
I 20
D 69
DESTDIR=/
E 69
I 69
DESTDIR=
D 72
STAND=/stand
E 72
I 72
STAND=	/stand
E 72
E 69
E 20
E 5
D 8
CFLAGS = -O -DSTANDALONE
E 8
I 8
D 10
CFLAGS=	-O -DSTANDALONE -DVAX=${CPU}
COPTS=	-DVAX=${CPU}
E 10
I 10
D 16
CFLAGS=	-O -DSTANDALONE ${COPTS}
E 16
I 16
D 47
CFLAGS=	-O -DSTANDALONE ${COPTS} 
E 47
I 47
D 56
CFLAGS=	-O -I../h -DSTANDALONE ${COPTS} 
E 56
I 56
D 57
INCPATH=-I..
E 57
I 57
D 66
INCPATH=-I. -I../h
E 57
D 63
CFLAGS=	-O ${INCPATH} -DSTANDALONE ${COPTS} 
E 56
E 47
E 16
D 12
COPTS=	-DVAX750 -DVAX780
E 12
I 12
D 15
COPTS=	-DVAX780 -DVAX750 -DVAX730
E 15
I 15
D 20
COPTS=	-DVAX780 -DVAX750 -DVAX7ZZ
E 20
I 20
D 49
COPTS=	-DVAX780 -DVAX750 -DVAX730
E 49
I 49
D 60
COPTS=	-DVAX780 -DVAX750 -DVAX730 -DVAX8600
E 60
I 60
COPTS=	-DCOMPAT_42 -DVAX780 -DVAX750 -DVAX730 -DVAX8600
E 60
E 49
I 34
D 40
730OPTS=-O -DVAX730
E 40
I 40
D 54
730OPTS=-O -DSTANDALONE -DVAX730
E 54
I 54
D 56
730OPTS=-O -I../h -DSTANDALONE -DVAX730
E 56
I 56
730OPTS=-O ${INCPATH} -DSTANDALONE -DVAX730
E 63
I 63
CFLAGS=	-O ${COPTS} 
E 66
I 66
INCPATH=-I. -I../stand -I../h
VPATH=	../stand:../vax
E 66
D 65
COPTS=	${INCPATH} -DSTANDALONE -DCOMPAT_42 -DVAX780 -DVAX750 -DVAX730 -DVAX8600
E 65
I 65
D 70
COPTS=	${INCPATH} -DSTANDALONE -DCOMPAT_42 \
	-DVAX8600 -DVAX780 -DVAX750 -DVAX730 -DVAX630
E 65
730OPTS=-O ${INCPATH} -DSTANDALONE -DCOMPAT_42 -DVAX730
E 63
E 56
E 54
E 40
E 34
E 20
E 15
E 12
E 10
E 8
D 2
RELOC=	50000
E 2
I 2
D 66
RELOC=	70000
E 66
I 66
CFLAGS=	-O ${COPTS} 
E 70
I 70
D 81
DEFS=	${INCPATH} -DSTANDALONE -DCOMPAT_42
E 81
I 81
DEFS=	${INCPATH} -DSTANDALONE
E 81
D 72
MACH=	-DVAX8600 -DVAX780 -DVAX750 -DVAX730 -DVAX630
E 72
I 72
D 74
MACH=	-DVAX8600 -DVAX8200 -DVAX780 -DVAX750 -DVAX730 -DVAX630
E 74
I 74
MACH=	-DVAX8600 -DVAX8200 -DVAX780 -DVAX750 -DVAX730 -DVAX630 -DVAX650
I 75
LS=	/bin/ls
E 75
E 74
E 72
I 71

# Collections of C options:
#	COPTS	device drivers/assembler, not optimized
D 80
#	SMOPTS	"small" versions for 7.5K bootxx programs
E 80
I 80
#	SMOPTS	"small" versions for 7.5K bootxx programs (750 only)
D 83
#	RAOPTS	like SMOPTS, but for bootra, which is 750 + 8200 + MVAXen
E 83
I 83
#	RAOPTS	like SMOPTS, but for bootra, which is 750 + 8200
E 83
#	KRAOPTS	like SMOPTS, but for bootkra, which is 8200 only
E 80
D 79
#	730OPTS	"small" versions for 11/730-only versions
E 79
#	CFLAGS	everything else

E 71
D 81
COPTS=	${DEFS} ${MACH}
CFLAGS=	-O ${DEFS} ${MACH}
E 81
I 81
COPTS=	${DEFS} ${MACH} -DCOMPAT_42
CFLAGS=	-O ${DEFS} ${MACH} -DCOMPAT_42
E 81
D 79
730OPTS=-O ${DEFS} -DVAX730
E 79
D 71
SMOPTS=	-O ${DEFS} -DVAX750 -DVAX630
E 71
I 71
D 74
SMOPTS=	${DEFS} -DSMALL -DVAX750 -DVAX630
E 74
I 74
D 80
SMOPTS=	${DEFS} -DSMALL -DVAX750 -DVAX630 -DVAX650
E 80
I 80
SMOPTS=	${DEFS} -DSMALL -DVAX750
D 83
RAOPTS=	${DEFS} -DSMALL -DVAX750 -DVAX8200 -DVAX630 -DVAX650
E 83
I 83
RAOPTS=	${DEFS} -DSMALL -DVAX750 -DVAX8200
E 83
KRAOPTS=${DEFS} -DSMALL -DVAX8200
E 80
E 74

E 71
E 70
RELOC=	150000
LIBSA=	libsa.a
E 66
I 52

E 52
E 2
D 8
DRIVERS=hp.o ht.o mba.o up.o uba.o
E 8
I 8
D 10
DRIVERS=hp.o ht.o mba.o rk.o tm.o up.o uba.o
E 10
I 10
D 62
SRCS=	sys.c conf.c prf.c machdep.c \
E 62
I 62
D 66
SRCS=	boot.c bootxx.c format.c copy.c drtest.c \
	sys.c conf.c prf.c machdep.c \
E 62
D 18
	autoconf.c hp.c ht.c mba.c rk.c tm.c ts.c up.c uba.c
DRIVERS=autoconf.o hp.o ht.o mba.o rk.o tm.o ts.o up.o uba.o
E 18
I 18
D 19
	autoconf.c hp.c ht.c mba.c mt.c rk.c tm.c ts.c up.c uba.c uda.c
DRIVERS=autoconf.o hp.o ht.o mba.o mt.o rk.o tm.o ts.o up.o uba.o uda.o
E 19
I 19
D 20
	autoconf.c hp.c ht.c mba.c mt.c rk.c tm.c ts.c up.c uba.c uda.c ut.c
DRIVERS=autoconf.o hp.o ht.o mba.o mt.o rk.o tm.o ts.o up.o uba.o uda.o ut.o
E 20
I 20
D 34
	autoconf.c hp.c ht.c idc.c mba.c mt.c rk.c tm.c ts.c \
E 34
I 34
D 35
	autoconf.c hp.c ht.c idc.c mba.c mt.c rk.c rl.c tm.c ts.c \
E 34
D 24
	up.c uba.c uda.c ut.c
E 24
I 24
	up.c uba.c uda.c ut.c \
E 35
I 35
	autoconf.c hp.c hpmaptype.c ht.c idc.c mba.c mt.c rk.c \
D 57
	rl.c tm.c ts.c \
	up.c upmaptype.c uba.c uda.c ut.c \
E 35
D 30
	drtest.c upchk.c up.new.c
E 30
I 30
D 40
	drtest.c format.c up.new.c
E 40
I 40
	drtest.c format.c up.old.c hp.old.c
E 57
I 57
D 65
	rl.c tm.c ts.c up.c upmaptype.c uba.c uda.c ut.c \
E 65
I 65
	rl.c tm.c tmscp.c ts.c up.c upmaptype.c uba.c uda.c ut.c \
E 65
D 60
	drtest.c format.c up.old.c hp.old.c ../vax/dkbad.c
E 60
I 60
	drtest.c format.c ../vax/dkbad.c
E 60
E 57
I 56
D 62
DUMMIES= bootxx.c confxx.c
E 62
I 62
DUMMIES= confxx.c
E 62
E 56
E 40
E 30
E 24
D 34
DRIVERS=autoconf.o hp.o ht.o idc.o mba.o mt.o rk.o tm.o ts.o \
E 34
I 34
D 35
DRIVERS=autoconf.o hp.o ht.o idc.o mba.o mt.o rk.o rl.o tm.o ts.o \
E 34
	up.o uba.o uda.o ut.o
E 35
I 35
DRIVERS=autoconf.o hp.o hpmaptype.o ht.o idc.o mba.o mt.o \
D 65
	rk.o rl.o tm.o ts.o \
E 65
I 65
	rk.o rl.o tm.o tmscp.o ts.o \
E 65
	up.o upmaptype.o uba.o uda.o ut.o
E 66
I 66
D 72
SRCS=	autoconf.c boot.c bootxx.c cat.c copy.c dev.c drtest.c drtest.c \
	format.c format.c getfile.c gets.c hp.c hpmaptype.c ht.c idc.c \
D 67
	machdep.c mba.c mt.c prf.c printn.c rk.c rl.c sys.c tm.c tmscp.c \
	ts.c uba.c uda.c up.c upmaptype.c ut.c conf.c ../vax/dkbad.c
E 67
I 67
	machdep.c mba.c mt.c prf.c printn.c qdcons.c qvcons.c qfont.c rk.c \
	rl.c sys.c tm.c tmscp.c ts.c uba.c uda.c up.c upmaptype.c ut.c conf.c \
	../vax/dkbad.c
E 72
I 72
D 84
SRCS=	autoconf.c boot.c bootxx.c cat.c copy.c dev.c drtest.c format.c \
D 83
	format.c getfile.c gets.c hp.c hpmaptype.c ht.c idc.c kdb.c \
	machdep.c mba.c mt.c prf.c printn.c qdcons.c qvcons.c qfont.c \
	rk.c rl.c sys.c tm.c tmscp.c ts.c uba.c uda.c up.c upmaptype.c \
	ut.c conf.c ../vax/dkbad.c
E 83
I 83
	getfile.c gets.c hp.c hpmaptype.c ht.c idc.c kdb.c machdep.c mba.c \
	mt.c prf.c printn.c rk.c rl.c sys.c tm.c tmscp.c ts.c uba.c uda.c \
	up.c upmaptype.c ut.c conf.c ../vax/dkbad.c
E 84
I 84
SRCS=	autoconf.c boot.c bootdec.c bootxx.c cat.c copy.c dev.c drtest.c \
	format.c getfile.c gets.c hp.c hpmaptype.c ht.c idc.c kdb.c machdep.c \
	mba.c mt.c prf.c printn.c rk.c rl.c rom.c sys.c tm.c tmscp.c ts.c \
	uba.c uda.c up.c upmaptype.c ut.c vmb.c vmberr.c vmbt.c conf.c \
	confdec.c confhpup.c  ../vax/dkbad.c
E 84
E 83
E 72
E 67
DUMMIES=confxx.c
D 67
DRIVERS=autoconf.o hp.o hpmaptype.o ht.o idc.o mba.o mt.o rk.o rl.o \
	tm.o tmscp.o ts.o up.o upmaptype.o uba.o uda.o ut.o
E 67
I 67
D 72
DRIVERS=autoconf.o hp.o hpmaptype.o ht.o idc.o mba.o mt.o qdcons.o qvcons.o \
	rk.o rl.o tm.o tmscp.o ts.o up.o upmaptype.o uba.o uda.o ut.o
E 72
I 72
D 83
DRIVERS=autoconf.o hp.o hpmaptype.o ht.o idc.o kdb.o mba.o mt.o qdcons.o \
	qvcons.o rk.o rl.o tm.o tmscp.o ts.o up.o upmaptype.o uba.o uda.o \
	ut.o
E 72
I 71
D 81
SMOBJ=	bootxx.o sm_sys.o sm_autoconf.o 
I 80
RAOBJ=	bootxx.o sm_sys.o ra_autoconf.o 
KRAOBJ=	bootxx.o sm_sys.o kra_autoconf.o 
E 81
I 81
SMOBJ=	bootxx.o sm_sys.o sm_autoconf.o
RAOBJ=	bootxx.o sm_sys.o ra_autoconf.o sm_uda.o
KRAOBJ=	bootxx.o sm_sys.o kra_autoconf.o sm_kdb.o
E 83
I 83
DRIVERS=autoconf.o hp.o hpmaptype.o ht.o idc.o kdb.o mba.o mt.o rk.o rl.o \
	tm.o tmscp.o ts.o up.o upmaptype.o uba.o uda.o ut.o
D 84
ASMS=	badaddr.o cons6xx.o scb.o strcmp.o strcpy.o strlen.o
E 84
I 84
D 85
ASMS=	badaddr.o cons6xx.o qioinit.o romio.o scb.o strcmp.o strcpy.o strlen.o
E 85
I 85
ASMS=	badaddr.o cons6xx.o qioinit.o romio.o scb.o startvmb.o strcmp.o \
	strcpy.o strlen.o
E 85
E 84
SMOBJ=	bootxx.o sm_sys.o sm_autoconf.o sm_scb.o
RAOBJ=	bootxx.o sm_sys.o ra_autoconf.o sm_scb.o sm_uda.o
KRAOBJ=	bootxx.o sm_sys.o kra_autoconf.o sm_scb.o sm_kdb.o
I 84
DECOBJ=	bootdec.o sm_sys.o sm_scb.o
E 84
E 83
E 81
E 80
E 71
E 67

E 66
E 35
I 24
D 40
NEWDRIVERS=hp.new.o up.new.o
E 40
I 40
# These drivers don't have ecc correction and bad sector forwarding;
# they are placed in the file system boot area for 750's.  If your
# root has bad sectors you can try and squeeze the newer drivers in...
D 60
ODRIVERS=hp.old.o up.old.o
E 60
I 60
ODRIVERS=sm_hp.o sm_up.o
E 60
I 52
D 66
LIBSA=	libsa.a
E 66
E 52
E 40
E 24
E 20
E 19
E 18
E 10
E 8

D 4
all:	/usr/lib/libsa.a srt0.o boot cat ls mkfs restor tpmkfs tprestor
E 4
I 4
D 6
all:	/usr/lib/libsa.a srt0.o boot cat ls icheck mkfs restor tpicheck tpmkfs tprestor
E 6
I 6
D 9
all:	/usr/lib/libsa.a srt0.o boot cat ls icheck mkfs restor \
E 9
I 9
D 10
all:	/usr/lib/libsa.a srt0.o boot cat ls icheck mkfs restor prconf \
E 10
I 10
D 14
all:	/usr/lib/libsa.a srt0.o boot cat ls icheck mkfs restor \
E 14
I 14
D 20
ALL=	/usr/lib/libsa.a srt0.o boot cat ls icheck mkfs restor \
E 14
E 10
E 9
	tpicheck tpmkfs tprestor sboot
E 20
I 20
D 24
ALL=	/usr/lib/libsa.a srt0.o boot tpboot copy tpcopy boothp boothk bootup
E 24
I 24
D 52
ALL=	/usr/lib/libsa.a srt0.o boot tpboot copy tpcopy \
E 52
I 52
D 58
ALL=	${LIBSA} srt0.o boot tpboot copy tpcopy \
E 58
I 58
D 66
ALL=	boot tpboot copy tpcopy \
E 58
E 52
D 31
	boothp boothk bootup \
D 30
	updrtest hpdrtest upchk hpchk
E 30
I 30
	format drtest
E 31
I 31
D 34
	format tpformat drtest boothp boothk bootup
E 34
I 34
	format tpformat drtest boothp boothk bootup bootra bootrl \
D 36
	730boot 730copy
E 36
I 36
	730boot 730copy 730format 730drtest
E 66
I 66
D 72
ALL=	boot tpboot cat copy tpcopy format tpformat drtest boothp boothk \
	bootup bootra bootrl 730boot 730copy 730format 730drtest ls
E 72
I 72
D 84
MDEC=	boothp boothk bootkra bootup bootra bootrl
E 84
I 84
MDEC=	boothp boothk bootkra bootup bootra bootrl bootdec
E 84
ALL=	boot tpboot cat copy tpcopy format tpformat drtest ls \
D 79
	730boot 730copy 730format 730drtest ${MDEC}
E 79
I 79
	${MDEC}
E 79
E 72
E 66
E 36
E 34
E 31
E 30
E 24
E 20
E 6
E 4

I 14
all: ${ALL}

E 14
D 8
/usr/lib/libsa.a:	sys.o conf.o hp.o ht.o mba.o up.o uba.o prf.o machdep.o 
E 8
I 8
D 9
/usr/lib/libsa.a:	sys.o conf.o ${DRIVERS} prf.o machdep.o 
E 9
I 9
D 10
/usr/lib/libsa.a:	sys.o conf.o ${DRIVERS} prf.o machdep.o chkaddr.o \
			dummyscb.o
E 10
I 10
D 40
/usr/lib/libsa.a: sys.o conf.o ${DRIVERS} prf.o machdep.o
E 40
I 40
D 52
/usr/lib/libsa.a: sys.o conf.o ${DRIVERS} prf.o machdep.o dkbad.o
E 40
E 10
E 9
E 8
D 5
	ar crv /usr/lib/libsa.a $?
E 5
I 5
D 20
	ar crv ${DESTDIR}/usr/lib/libsa.a $?
	ranlib ${DESTDIR}/usr/lib/libsa.a
E 20
I 20
	ar crv /usr/lib/libsa.a $?
	ranlib /usr/lib/libsa.a
E 52
I 52
D 66
${LIBSA}: sys.o conf.o ${DRIVERS} prf.o machdep.o dkbad.o
E 66
I 66
D 83
${LIBSA}: conf.o dev.o dkbad.o getfile.o gets.o machdep.o prf.o printn.o \
D 67
	sys.o ${DRIVERS}
E 67
I 67
	qfont.o sys.o ${DRIVERS}
E 83
I 83
${LIBSA}: conf.o cpuid.o dev.o dkbad.o getfile.o gets.o machdep.o prf.o \
D 84
	printn.o sys.o ${DRIVERS} ${ASMS}
E 84
I 84
	printn.o rom.o sys.o vmb.o vmberr.o vmbt.o ${DRIVERS} ${ASMS}
E 84
E 83
E 67
E 66
	ar crv ${LIBSA} $?
	ranlib ${LIBSA}
E 52
E 20
E 5

D 20
${DRIVERS}:
E 20
I 20
D 24
${DRIVERS}: savax.h
E 24
I 24
D 40
${NEWDRIVERS} ${DRIVERS}: savax.h
E 40
I 40
D 60
${ODRIVERS} ${DRIVERS}: savax.h
E 60
I 60
D 72
${DRIVERS}: savax.h
E 72
I 72
${DRIVERS}:
E 72
E 60
E 40
E 24
E 20
D 62
	cc -c -S ${COPTS} $*.c
E 62
I 62
D 63
	cc -c -S ${CFLAGS} $*.c
E 63
I 63
D 66
	cc -c -S ${COPTS} $*.c
E 66
I 66
	${CC} -c -S ${COPTS} $*.c
E 66
E 63
E 62
D 10
	/lib/c2 -i $*.s $*.os
	as -o $*.o $*.os
	rm $*.s $*.os
E 10
I 10
	/lib/c2 -i $*.s | as -o $*.o
D 51
	rm $*.s
E 51
I 51
	rm -f $*.s
E 51
E 10

I 83
${ASMS}:
	${CC} -E ${COPTS} $*.c | as -o $*.o

cpuid.o:	../vax/cpuid.s
	-ln -s ../vax/cpuid.s cpuid.c
	${CC} -E ${COPTS} cpuid.c | as -o cpuid.o
	rm -f cpuid.c

E 83
I 40
D 66
dkbad.o: ../vax/dkbad.c
	${CC} -c ${CFLAGS} ../vax/dkbad.c
E 66
D 62

E 62
E 40
D 5
boot:	boot.o relsrt0.o /usr/lib/libsa.a
E 5
I 5
D 20
boot:	boot.o relsrt0.o ${DESTDIR}/usr/lib/libsa.a
E 5
	ld -N -T ${RELOC} relsrt0.o boot.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=boot ibs=32 skip=1; rm b.out
E 20
I 20
# startups
E 20

I 6
D 20
sboot:	boot.c relsrt0.o ${DESTDIR}/usr/lib/libsa.a
D 13
	cp boot.c sboot.c
E 13
I 13
	cp boot.c sboot.c; chmod +w sboot.c
E 13
	cc -c -O -DJUSTASK sboot.c
	rm sboot.c
	ld -N -T ${RELOC} relsrt0.o sboot.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=sboot ibs=32 skip=1; rm b.out
E 20
I 20
D 22
srt0.o: srt0.c ../h/mtpr.h ../h/cpu.h
E 22
I 22
srt0.o: srt0.c ../vax/mtpr.h ../vax/cpu.h
E 22
D 66
	cc -E -DRELOC=0x${RELOC} ${COPTS} srt0.c | as -o srt0.o
E 66
I 66
	${CC} -E -DRELOC=0x${RELOC} ${COPTS} srt0.c | as -o srt0.o
E 66
E 20

E 6
D 5
cat:	cat.o srt0.o /usr/lib/libsa.a
E 5
I 5
D 20
cat:	cat.o srt0.o ${DESTDIR}/usr/lib/libsa.a
E 5
	ld -N srt0.o cat.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=cat ibs=32 skip=1; rm b.out
E 20
I 20
D 22
tpsrt0.o: srt0.c ../h/mtpr.h ../h/cpu.h
E 22
I 22
D 83
tpsrt0.o: srt0.c ../vax/mtpr.h ../vax/cpu.h
E 22
D 66
	cc -E -DRELOC=0x${RELOC} -DTP ${COPTS} srt0.c | as -o tpsrt0.o 
E 66
I 66
	${CC} -E -DRELOC=0x${RELOC} -DTP ${COPTS} srt0.c | as -o tpsrt0.o
E 66
E 20

E 83
D 5
ls:	ls.o srt0.o /usr/lib/libsa.a
E 5
I 5
D 20
ls:	ls.o srt0.o ${DESTDIR}/usr/lib/libsa.a
E 5
	ld -N srt0.o ls.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=ls ibs=32 skip=1; rm b.out
E 20
I 20
D 22
relsrt0.o: srt0.c ../h/mtpr.h ../h/cpu.h
E 22
I 22
relsrt0.o: srt0.c ../vax/mtpr.h ../vax/cpu.h
E 22
D 66
	cc -E -DRELOC=0x${RELOC} -DREL ${COPTS} srt0.c | as -o relsrt0.o
E 66
I 66
	${CC} -E -DRELOC=0x${RELOC} -DREL ${COPTS} srt0.c | as -o relsrt0.o
E 66
E 20
I 16

I 83
relsrt750.o: srt0.c ../vax/mtpr.h ../vax/cpu.h
	${CC} -E -DRELOC=0x${RELOC} -DREL -DOLD750BOOT ${RAOPTS} srt0.c \
	| as -o relsrt750.o

I 84
decsrt0.o: decsrt0.c ../vax/mtpr.h ../vax/cpu.h
	${CC} -E -DRELOC=0x${RELOC} ${COPTS} decsrt0.c | as -o decsrt0.o

E 84
E 83
D 17
imptst: imptest.o srt0.o 
	ld -N srt0.o imptest.o -lsa -lc
E 17
I 17
D 20
imptst: imptst.o srt0.o 
	ld -N srt0.o imptst.o -lsa -lc
E 17
	cp a.out b.out; strip b.out; dd if=b.out of=imptst ibs=32 skip=1; rm b.out
E 20
I 20
# bootable from tape
E 20
E 16

I 4
D 9
mkfs.o:	/usr/src/cmd/mkfs.c
	cc ${CFLAGS} -c /usr/src/cmd/mkfs.c
E 9
I 9
D 10
prconf.o:
	cc -S $(CFLAGS) prconf.c
	sed -f sed.prconf prconf.s | as -o prconf.o
	rm -f prconf.s
E 10
I 10
D 20
mkfs.o:	/usr/src/cmd/mkfs.c
	cc ${CFLAGS} -c /usr/src/cmd/mkfs.c
E 20
I 20
D 52
tpboot:	tpboot.o relsrt0.o /usr/lib/libsa.a
	ld -N -T ${RELOC} relsrt0.o tpboot.o -lsa -lc
E 52
I 52
D 72
tpboot:	tpboot.o relsrt0.o ${LIBSA}
E 72
I 72
tpboot: tpboot.o relsrt0.o ${LIBSA}
E 72
	ld -N -T ${RELOC} relsrt0.o tpboot.o ${LIBSA} -lc
E 52
D 51
	cp a.out b.out; strip b.out; dd if=b.out of=tpboot ibs=32 skip=1; rm b.out
E 51
I 51
D 54
	cp a.out b.out; strip b.out; dd if=b.out of=tpboot ibs=32 skip=1; rm -f b.out
E 54
I 54
	strip a.out; dd if=a.out of=tpboot ibs=32 skip=1; rm -f a.out
E 54
E 51
E 20
E 10
E 9

I 9
D 10
prconf:	prconf.o scbbase.o srt0.o ${DESTDIR}/usr/lib/libsa.a
	ld -e entry -N scbbase.o srt0.o prconf.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=prconf ibs=32 skip=1; \
	    rm b.out

xprconf: prconf
	ld -n -o xprconf -e entry scbbase.o srt0.o prconf.o -lsa -lc

mkfs.o:	/ra/src/cmd/mkfs.c
	cc ${CFLAGS} -c /ra/src/cmd/mkfs.c

E 10
E 9
E 4
D 5
mkfs:	mkfs.o srt0.o /usr/lib/libsa.a
E 5
I 5
D 20
mkfs:	mkfs.o srt0.o ${DESTDIR}/usr/lib/libsa.a
E 5
	ld -N srt0.o mkfs.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=mkfs ibs=32 skip=1; rm b.out
E 20
I 20
D 72
tpboot.o: boot.c ../h/param.h ../h/inode.h ../h/fs.h
tpboot.o: saio.h ../h/reboot.h ../h/vm.h 
	cp boot.c tpboot.c; chmod +w tpboot.c
D 62
	cc -c -O -DJUSTASK tpboot.c
E 62
I 62
D 66
	cc -c ${CFLAGS} -DJUSTASK tpboot.c
E 66
I 66
	${CC} -c ${CFLAGS} -DJUSTASK tpboot.c
E 66
E 62
D 51
	rm tpboot.c
E 51
I 51
	rm -f tpboot.c
E 72
I 72
tpboot.o: boot.o
	rm -f $*.c
	ln -s boot.c $*.c
	${CC} -c ${CFLAGS} -DJUSTASK $*.c
	rm -f $*.c
E 72
E 51
E 20

I 4
D 9
restor.o: /usr/src/cmd/restor.c
	cc ${CFLAGS} -c /usr/src/cmd/restor.c
E 9
I 9
D 10
restor.o: /ra/src/cmd/restor.c
	cc ${CFLAGS} -c /ra/src/cmd/restor.c
E 10
I 10
D 20
restor.o: /usr/src/cmd/restor.c
	cc ${CFLAGS} -c /usr/src/cmd/restor.c
E 20
I 20
D 36
tpcopy:	copy.c tpsrt0.o /usr/lib/libsa.a
	cp copy.c tpcopy.c; chmod +w tpcopy.c
	cc -c -O tpcopy.c
	rm tpcopy.c
	ld -N tpsrt0.o tpcopy.o -lsa -lc
E 36
I 36
D 52
tpcopy:	copy.o tpsrt0.o /usr/lib/libsa.a
	ld -N tpsrt0.o copy.o -lsa -lc
E 52
I 52
D 66
tpcopy:	copy.o tpsrt0.o ${LIBSA}
E 66
I 66
D 83
tpcopy: copy.o tpsrt0.o ${LIBSA}
E 66
	ld -N tpsrt0.o copy.o ${LIBSA} -lc
E 83
I 83
tpcopy: copy.o srt0.o ${LIBSA}
	ld -N srt0.o copy.o ${LIBSA} -lc
E 83
E 52
E 36
D 39
	cp a.out b.out; strip b.out; dd if=b.out of=tpcopy ibs=32 skip=1; rm b.out
E 39
I 39
D 54
	cp a.out b.out; strip b.out; \
D 51
		dd if=b.out of=tpcopy ibs=32 skip=1; rm b.out
E 51
I 51
		dd if=b.out of=tpcopy ibs=32 skip=1; rm -f b.out
E 54
I 54
	strip a.out; dd if=a.out of=tpcopy ibs=32 skip=1; rm -f a.out
E 54
E 51
E 39
E 20
E 10
E 9

I 30
D 37
tpformat: format.c tpsrt0.o /usr/lib/libsa.a
E 37
I 37
D 40
tpformat: format.o tpsrt0.o dkbad.o
tpformat: confhpup.o hp.new.o up.new.o /usr/lib/libsa.a
E 40
I 40
D 52
tpformat: format.o tpsrt0.o confhpup.o /usr/lib/libsa.a
E 52
I 52
D 72
tpformat: format.o tpsrt0.o confhpup.o ${LIBSA}
E 52
E 40
E 37
	cp format.c tpformat.c; chmod +w tpformat.c
D 33
	cc -c -O tpformat.c
E 33
I 33
D 62
	cc -c -O -DJUSTEXIT tpformat.c
E 62
I 62
D 66
	cc -c ${CFLAGS} -DJUSTEXIT tpformat.c
E 66
I 66
	${CC} -c ${CFLAGS} -DJUSTEXIT tpformat.c
E 66
E 62
E 33
D 51
	rm tpformat.c
E 51
I 51
	rm -f tpformat.c
E 72
I 72
D 83
tpformat: tpformat.o tpsrt0.o confhpup.o ${LIBSA}
E 72
E 51
D 37
	ld -N tpsrt0.o tpformat.o -lsa -lc
E 37
I 37
D 40
	ld -N tpsrt0.o tpformat.o dkbad.o confhpup.o \
		hp.new.o up.new.o -lsa -lc
E 40
I 40
D 52
	ld -N tpsrt0.o tpformat.o confhpup.o -lsa -lc
E 52
I 52
	ld -N tpsrt0.o tpformat.o confhpup.o ${LIBSA} -lc
E 83
I 83
tpformat: tpformat.o srt0.o confhpup.o ${LIBSA}
	ld -N srt0.o tpformat.o confhpup.o ${LIBSA} -lc
E 83
E 52
E 40
E 37
D 39
	cp a.out b.out; strip b.out; dd if=b.out of=tpformat ibs=32 skip=1; rm b.out
E 39
I 39
D 54
	cp a.out b.out; strip b.out; \
D 51
		dd if=b.out of=tpformat ibs=32 skip=1; rm b.out
E 51
I 51
		dd if=b.out of=tpformat ibs=32 skip=1; rm -f b.out
E 54
I 54
	strip a.out; dd if=a.out of=tpformat ibs=32 skip=1; rm -f a.out
E 54
E 51
E 39

I 72
tpformat.o: format.o
	rm -f $*.c
	ln -s format.c $*.c
	${CC} -c ${CFLAGS} -DJUSTEXIT $*.c
	rm -f $*.c

E 72
E 30
E 4
D 5
restor:	restor.o srt0.o /usr/lib/libsa.a
E 5
I 5
D 20
restor:	restor.o srt0.o ${DESTDIR}/usr/lib/libsa.a
E 5
	ld -N srt0.o restor.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=restor ibs=32 skip=1; rm b.out
E 20
I 20
# bootable from floppy or real disks
E 20

I 4
D 9
icheck.o: /usr/src/cmd/icheck.c
	cc ${CFLAGS} -c /usr/src/cmd/icheck.c
E 9
I 9
D 10
icheck.o: /ra/src/cmd/icheck.c
	cc ${CFLAGS} -c /ra/src/cmd/icheck.c
E 10
I 10
D 20
icheck.o: /usr/src/cmd/icheck.c
	cc ${CFLAGS} -c /usr/src/cmd/icheck.c
E 20
I 20
D 52
boot:	boot.o relsrt0.o bootconf.o /usr/lib/libsa.a
	ld -N -T ${RELOC} -o boot relsrt0.o boot.o bootconf.o -lsa -lc
E 52
I 52
D 72
boot:	boot.o relsrt0.o bootconf.o ${LIBSA}
	ld -N -T ${RELOC} -o boot relsrt0.o boot.o bootconf.o ${LIBSA} -lc
E 72
I 72
boot: boot.o relsrt0.o bootconf.o ${LIBSA}
	ld -N -T ${RELOC} -o $@ relsrt0.o boot.o bootconf.o ${LIBSA} -lc
E 72
E 52
E 20
E 10
E 9

D 5
icheck: icheck.o srt0.o /usr/lib/libsa.a
E 5
I 5
D 20
icheck: icheck.o srt0.o ${DESTDIR}/usr/lib/libsa.a
E 5
	ld -N srt0.o icheck.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=icheck ibs=32 skip=1; rm b.out
E 20
I 20
D 23
bootconf.o: conf.c ../h/param.h ../h/inode.h ../h/pte.h
E 23
I 23
D 56
bootconf.o: conf.c ../h/param.h ../h/inode.h ../machine/pte.h
E 23
D 22
bootconf.o: ../h/fs.h saio.h ../h/mbareg.h
E 22
I 22
bootconf.o: ../h/fs.h saio.h ../vaxmba/mbareg.h
E 56
I 56
bootconf.o: conf.o
E 56
E 22
D 72
	cp conf.c bootconf.c
D 62
	cc -c ${COPTS} -DBOOT bootconf.c
E 62
I 62
D 66
	cc -c ${CFLAGS} -DBOOT bootconf.c
E 66
I 66
	${CC} -c ${CFLAGS} -DBOOT bootconf.c
E 66
E 62
D 51
	rm bootconf.c
E 51
I 51
	rm -f bootconf.c
E 72
I 72
	rm -f $*.c
	ln -s conf.c $*.c
	${CC} -c ${CFLAGS} -DBOOT $*.c
	rm -f $*.c
E 72
E 51
E 20

E 4
D 5
tpmkfs:	mkfs.o tpsrt0.o /usr/lib/libsa.a
E 5
I 5
D 20
tpmkfs:	mkfs.o tpsrt0.o ${DESTDIR}/usr/lib/libsa.a
E 5
	ld -N tpsrt0.o mkfs.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=tpmkfs ibs=32 skip=1; rm b.out
E 20
I 20
D 52
copy:	copy.o srt0.o conf.o /usr/lib/libsa.a
	ld -N -o copy srt0.o copy.o conf.o -lsa -lc
E 52
I 52
D 66
copy:	copy.o srt0.o conf.o ${LIBSA}
	ld -N -o copy srt0.o copy.o conf.o ${LIBSA} -lc
E 66
I 66
copy: copy.o srt0.o getfile.o ${LIBSA}
	ld -N -o $@ srt0.o copy.o getfile.o ${LIBSA} -lc
E 66
E 52
I 24

D 30
# eventually we'll merge hpchk and upchk into one program
#chk:	chk.o srt0.o conf.o hp.new.o up.new.o /usr/lib/libsa.a
#	ld -N -o chk srt0.o chk.o conf.o hp.new.o up.new.o -lsa -lc
#
D 26
hpchk:	chk.o srt0.o confhp.o hp.new.o /usr/lib/libsa.a
	ld -N -o hpchk srt0.o chk.o confhp.o hp.new.o -lsa -lc
E 26
I 26
D 27
hpchk:	chk.o srt0.o confhp.o hp.new.o isbad.o /usr/lib/libsa.a
	ld -N -o hpchk srt0.o chk.o confhp.o hp.new.o isbad.o -lsa -lc
E 27
I 27
hpchk:	chk.o srt0.o confhp.o hp.new.o dkbad.o /usr/lib/libsa.a
	ld -N -o hpchk srt0.o chk.o confhp.o hp.new.o dkbad.o -lsa -lc
E 30
I 30
D 40
format:	format.o srt0.o dkbad.o
format:	confhpup.o hp.new.o up.new.o /usr/lib/libsa.a
	ld -N -o format srt0.o format.o dkbad.o confhpup.o \
		hp.new.o up.new.o -lsa -lc
E 40
I 40
D 52
format:	format.o srt0.o confhpup.o /usr/lib/libsa.a
	ld -N -o format srt0.o format.o confhpup.o -lsa -lc
E 52
I 52
D 66
format:	format.o srt0.o confhpup.o ${LIBSA}
E 66
I 66
cat: cat.o srt0.o getfile.o ${LIBSA}
	ld -N -o $@ srt0.o cat.o getfile.o ${LIBSA} -lc

D 76
ls: ls.o srt0.o getfile.o ${LIBSA}
	ld -N -o $@ srt0.o ls.o getfile.o ${LIBSA} -lc
E 76
I 76
ls: ls.o srt0.o ${LIBSA}
	ld -N -o $@ srt0.o ls.o ${LIBSA} -lc
E 76

format: format.o srt0.o confhpup.o ${LIBSA}
E 66
D 72
	ld -N -o format srt0.o format.o confhpup.o ${LIBSA} -lc
E 72
I 72
	ld -N -o $@ srt0.o format.o confhpup.o ${LIBSA} -lc
E 72
E 52
E 40
E 30
E 27
E 26

D 26
upchk:	chk.o srt0.o confup.o up.new.o /usr/lib/libsa.a
	ld -N -o upchk srt0.o chk.o confup.o up.new.o -lsa -lc
E 26
I 26
D 27
upchk:	chk.o srt0.o confup.o up.new.o isbad.o /usr/lib/libsa.a
	ld -N -o upchk srt0.o chk.o confup.o up.new.o isbad.o -lsa -lc
E 27
I 27
D 30
upchk:	chk.o srt0.o confup.o up.new.o dkbad.o /usr/lib/libsa.a
	ld -N -o upchk srt0.o chk.o confup.o up.new.o dkbad.o -lsa -lc
E 30
I 30
D 40
drtest:	drtest.o srt0.o dkbad.o
drtest:	confhpup.o hp.new.o up.new.o /usr/lib/libsa.a
	ld -N -o drtest srt0.o drtest.o dkbad.o confhpup.o \
		hp.new.o up.new.o -lsa -lc
E 40
I 40
D 52
drtest:	drtest.o srt0.o confhpup.o /usr/lib/libsa.a
	ld -N -o drtest srt0.o drtest.o confhpup.o -lsa -lc
E 52
I 52
D 66
drtest:	drtest.o srt0.o confhpup.o ${LIBSA}
E 66
I 66
drtest: drtest.o srt0.o confhpup.o ${LIBSA}
E 66
D 72
	ld -N -o drtest srt0.o drtest.o confhpup.o ${LIBSA} -lc
E 72
I 72
	ld -N -o $@ srt0.o drtest.o confhpup.o ${LIBSA} -lc
E 72
E 52
E 40
E 30
E 27
E 26

D 30
# eventually we'll merge hpdrtest and updrtest into one program
#drtest:drtest.o srt0.o conf.o hp.new.o up.new.o /usr/lib/libsa.a
#	ld -N -o drtest srt0.o drtest.o conf.o hp.new.o up.new.o -lsa -lc
#
D 26
updrtest: drtest.o srt0.o confup.o up.new.o /usr/lib/libsa.a
	ld -N -o updrtest srt0.o drtest.o confup.o up.new.o -lsa -lc
E 26
I 26
D 27
updrtest: drtest.o srt0.o confup.o up.new.o isbad.o /usr/lib/libsa.a
	ld -N -o updrtest srt0.o drtest.o confup.o up.new.o isbad.o -lsa -lc
E 27
I 27
updrtest: drtest.o srt0.o confup.o up.new.o dkbad.o /usr/lib/libsa.a
	ld -N -o updrtest srt0.o drtest.o confup.o up.new.o dkbad.o -lsa -lc
E 27
E 26

D 26
hpdrtest: drtest.o srt0.o confhp.o hp.new.o /usr/lib/libsa.a
	ld -N -o hpdrtest srt0.o drtest.o confhp.o hp.new.o -lsa -lc
E 26
I 26
D 27
hpdrtest: drtest.o srt0.o confhp.o hp.new.o isbad.o /usr/lib/libsa.a
	ld -N -o hpdrtest srt0.o drtest.o confhp.o hp.new.o isbad.o -lsa -lc
E 27
I 27
hpdrtest: drtest.o srt0.o confhp.o hp.new.o dkbad.o /usr/lib/libsa.a
	ld -N -o hpdrtest srt0.o drtest.o confhp.o hp.new.o dkbad.o -lsa -lc
E 27

E 30
D 27
isbad.o: ../vax/isbad.c
	${CC} -c ${CFLAGS} ../vax/isbad.c
E 27
I 27
D 40
dkbad.o: ../vax/dkbad.c
	${CC} -c ${CFLAGS} ../vax/dkbad.c
E 27
E 26
E 24
E 20

E 40
I 34
D 39
# for 730s minimize size so it fits on the cassette
E 39
I 39
D 79
# for 730s minimize size to avoid microcode botch
# (won't load files larger than 12.5 Kbytes)
E 39

D 39
730boot: boot.o relsrt0.o 730bootconf.o /usr/lib/libsa.a
E 39
I 39
D 56
730boot.o: boot.c ../h/param.h ../h/inode.h ../h/fs.h
730boot.o: saio.h ../h/reboot.h ../h/vm.h 
E 56
I 56
730boot.o: boot.o
E 56
D 72
	cp boot.c 730boot.c; chmod +w 730boot.c
D 46
	cc -c ${730OPTS} -DJUSTASK 730boot.c
E 46
I 46
D 66
	cc -c ${730OPTS} 730boot.c
E 66
I 66
	${CC} -c ${730OPTS} 730boot.c
E 66
E 46
D 51
	rm 730boot.c
E 51
I 51
	rm -f 730boot.c
E 72
I 72
	rm -f $*.c
	ln -s boot.c $*.c
	${CC} -c ${730OPTS} $*.c
	rm -f $*.c
E 72
E 51

D 52
730boot: 730boot.o relsrt0.o 730bootconf.o /usr/lib/libsa.a
E 39
D 44
	ld -N -T ${RELOC} -o 730boot relsrt0.o boot.o 730bootconf.o -lsa -lc
E 44
I 44
	ld -N -T ${RELOC} -o 730boot relsrt0.o 730boot.o 730bootconf.o -lsa -lc
E 52
I 52
730boot: 730boot.o relsrt0.o 730bootconf.o ${LIBSA}
	ld -N -T ${RELOC} -o 730boot relsrt0.o 730boot.o 730bootconf.o ${LIBSA} -lc
E 52
E 44

D 56
730bootconf.o: conf.c ../h/param.h ../h/inode.h ../machine/pte.h
730bootconf.o: ../h/fs.h saio.h
E 56
I 56
730bootconf.o: conf.o
E 56
D 72
	cp conf.c 730bootconf.c
D 66
	cc -c ${730OPTS} -DBOOT 730bootconf.c
E 66
I 66
	${CC} -c ${730OPTS} -DBOOT 730bootconf.c
E 66
D 36
	rm 730bootconf.c
E 36
I 36
	rm -f 730bootconf.c
E 72
I 72
	rm -f $*.c
	ln -s conf.c $*.c
	${CC} -c ${730OPTS} -DBOOT $*.c
	rm -f $*.c
E 72
E 36

D 52
730copy: copy.o srt0.o 730conf.o /usr/lib/libsa.a
	ld -N -o 730copy srt0.o copy.o 730conf.o -lsa -lc
E 52
I 52
730copy: copy.o srt0.o 730conf.o ${LIBSA}
D 72
	ld -N -o 730copy srt0.o copy.o 730conf.o ${LIBSA} -lc
E 72
I 72
	ld -N -o $@ srt0.o copy.o 730conf.o ${LIBSA} -lc
E 72
E 52

I 36
D 40
730drtest: drtest.o srt0.o confup.o up.new.o dkbad.o /usr/lib/libsa.a
	ld -N -o 730drtest srt0.o drtest.o confup.o up.new.o dkbad.o -lsa -lc
E 40
I 40
D 52
730drtest: drtest.o srt0.o confup.o /usr/lib/libsa.a
	ld -N -o 730drtest srt0.o drtest.o confup.o -lsa -lc
E 52
I 52
730drtest: drtest.o srt0.o confup.o ${LIBSA}
D 72
	ld -N -o 730drtest srt0.o drtest.o confup.o ${LIBSA} -lc
E 72
I 72
	ld -N -o $@ srt0.o drtest.o confup.o ${LIBSA} -lc
E 72
E 52
E 40

D 40
730format: format.o srt0.o confup.o up.new.o dkbad.o /usr/lib/libsa.a
	ld -N -o 730format srt0.o format.o confup.o up.new.o dkbad.o -lsa -lc
E 40
I 40
D 52
730format: format.o srt0.o confup.o /usr/lib/libsa.a
	ld -N -o 730format srt0.o format.o confup.o -lsa -lc
E 52
I 52
730format: format.o srt0.o confup.o ${LIBSA}
D 72
	ld -N -o 730format srt0.o format.o confup.o ${LIBSA} -lc
E 72
I 72
	ld -N -o $@ srt0.o format.o confup.o ${LIBSA} -lc
E 72
E 52
E 40

E 36
D 56
730conf.o: conf.c ../h/param.h ../h/inode.h ../machine/pte.h
730conf.o: ../h/fs.h saio.h
E 56
I 56
730conf.o: conf.o
E 56
D 72
	cp conf.c 730conf.c
D 40
	cc -c ${730OPTS} -DBOOT 730conf.c
E 40
I 40
D 66
	cc -c ${730OPTS} 730conf.c
E 66
I 66
	${CC} -c ${730OPTS} 730conf.c
E 66
E 40
D 36
	rm 730conf.c
E 36
I 36
	rm -f 730conf.c
E 72
I 72
	rm -f $*.c
	ln -s conf.c $*.c
	${CC} -c ${730OPTS} $*.c
	rm -f $*.c
E 72
E 36

E 79
E 34
D 5
tprestor: restor.o tpsrt0.o /usr/lib/libsa.a
E 5
I 5
D 20
tprestor: restor.o tpsrt0.o ${DESTDIR}/usr/lib/libsa.a
E 5
	ld -N tpsrt0.o restor.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=tprestor ibs=32 skip=1; rm b.out
E 20
I 20
# bootstrap from ether
E 20

I 4
D 5
tpicheck: icheck.o tpsrt0.o /usr/lib/libsa.a
E 5
I 5
D 20
tpicheck: icheck.o tpsrt0.o ${DESTDIR}/usr/lib/libsa.a
E 5
	ld -N tpsrt0.o icheck.o -lsa -lc
	cp a.out b.out; strip b.out; dd if=b.out of=tpicheck ibs=32 skip=1; rm b.out
E 20
I 20
### not yet, rosin, not yet ###
E 20

E 4
D 10
srt0.o: rel.m ../h/mtpr.m ../h/mba.m ../h/uba.m srt0.s
D 8
	as -o srt0.o rel.m ../h/mtpr.m ../h/mba.m ../h/uba.m srt0.s
E 8
I 8
	/lib/cpp -DVAX=${CPU} srt0.s >srt0.i
	as -o srt0.o rel.m ../h/mtpr.m ../h/mba.m ../h/uba.m srt0.i
E 10
I 10
D 20
srt0.o: srt0.c
D 11
	cc -E -DRELOC=${RELOC} srt0.c | as -o srt0.o
E 11
I 11
D 13
	cc -E -DRELOC=0x${RELOC} srt0.c | as -o srt0.o
E 13
I 13
	cc -E -DRELOC=0x${RELOC} ${COPTS} srt0.c | as -o srt0.o
E 13
E 11
E 10
E 8

I 9
D 10
chkaddr.o: ../h/mtpr.m chkaddr.s
	/lib/cpp -DVAX=${CPU} chkaddr.s >chkaddr.i
	as -o chkaddr.o ../h/mtpr.m chkaddr.i
E 10
I 10
D 13
tpsrt0.o: tpsrt0.c
D 11
	cc -E -DRELOC=${RELOC} tpsrt0.c | as -o tpsrt0.o 
E 11
I 11
	cc -E -DRELOC=0x${RELOC} tpsrt0.c | as -o tpsrt0.o 
E 13
I 13
tpsrt0.o: srt0.c
	cc -E -DRELOC=0x${RELOC} -DTP ${COPTS} srt0.c | as -o tpsrt0.o 
E 13
E 11
E 10

E 9
D 10
tpsrt0.o: rel.m ../h/mtpr.m ../h/mba.m ../h/uba.m tpsrt0.s
D 8
	as -o tpsrt0.o rel.m ../h/mtpr.m ../h/mba.m ../h/uba.m tpsrt0.s
E 8
I 8
	/lib/cpp -DVAX=${CPU} tpsrt0.s >tpsrt0.i
	as -o tpsrt0.o rel.m ../h/mtpr.m ../h/mba.m ../h/uba.m tpsrt0.i
E 10
I 10
D 13
relsrt0.o: relsrt0.c
D 11
	cc -E -DRELOC=${RELOC} relsrt0.c | as -o relsrt0.o
E 11
I 11
	cc -E -DRELOC=0x${RELOC} relsrt0.c | as -o relsrt0.o
E 13
I 13
relsrt0.o: srt0.c
	cc -E -DRELOC=0x${RELOC} -DREL ${COPTS} srt0.c | as -o relsrt0.o
E 13
E 11
E 10
E 8

E 20
D 10
relsrt0.o: rel.m ../h/mtpr.m ../h/mba.m ../h/uba.m relsrt0.s
D 8
	as -o relsrt0.o rel.m ../h/mtpr.m ../h/mba.m ../h/uba.m relsrt0.s
E 8
I 8
	/lib/cpp -DVAX=${CPU} relsrt0.s >relsrt0.i
	as -o relsrt0.o rel.m ../h/mtpr.m ../h/mba.m ../h/uba.m relsrt0.i
E 8

rpboot: rpboot.s
	as rpboot.s
	cp a.out b.out; strip b.out; dd if=b.out of=rpboot bs=32 skip=1; rm b.out
E 10
D 21
print:
D 10
	@pr makefile
	@/usr/ucb/ls -l | pr
	@pr *.h
	@pr *.m *.s
	@pr *.c
E 10
I 10
D 20
	@pr -f makefile
	@/usr/ucb/ls -l | pr -f
	@pr -f *.h *.c
E 20
I 20
	@pr makefile
	@ls -l | pr 
	@pr *.h *.c
E 21
I 21
# getting booted from disc
E 21
E 20
E 10
I 5

D 10
vgrindt:
	@vgrind -t -n makefile;
	@vgrind -t *.h;
	@vgrind -t -n *.m *.s;
	@vgrind -t *.c;
E 5

E 10
D 21
clean:
D 8
	rm -f *.o *.exe
E 8
I 8
	rm -f *.o *.exe *.i
E 8
D 3
	rm -f a.out b.out boot cat ls mkfs restor rpboot
E 3
I 3
D 4
	rm -f a.out b.out boot cat ls mkfs restor rpboot tpmkfs tprestor
E 4
I 4
D 6
	rm -f a.out b.out boot cat ls icheck mkfs restor rpboot tpicheck tpmkfs tprestor
E 6
I 6
D 20
	rm -f a.out b.out boot cat ls icheck mkfs restor rpboot \
	    tpicheck tpmkfs tprestor sboot
E 20
I 20
	rm -f a.out b.out boot cat tpboot tpcopy
E 20
E 6
E 4
E 3

I 10
lint:
	lint ${COPTS} -hxbn boot.c ${SRCS} | \
	    grep -v 'possible pointer alignment' | \
D 11
	    grep -v 'struct/unit .* never defined'
E 11
I 11
	    grep -v 'struct/union .* never defined'
E 11

E 10
D 14
install:
E 14
I 14
install: ${ALL}
E 14
D 12
	cp tprestor ${DESTDIR}/sys/restor
I 4
	cp tpicheck ${DESTDIR}/sys/icheck
E 4
	cp tpmkfs ${DESTDIR}/sys/mkfs
D 6
	cp boot ${DESTDIR}/sys/boot
E 6
I 6
	cp sboot ${DESTDIR}/sys/boot
E 12
I 12
D 20
	cp tprestor ${DESTDIR}/tp/restor
	cp tpicheck ${DESTDIR}/tp/icheck
	cp tpmkfs ${DESTDIR}/tp/mkfs
	cp sboot ${DESTDIR}/tp/boot
E 12
E 6
D 4
	cp boot mkfs restor cat ls ../floppy
E 4
I 4
D 9
	cp boot icheck mkfs restor cat ls ../floppy
E 9
I 9
D 10
	cp boot icheck mkfs restor cat prconf ls ../floppy
E 10
I 10
	cp boot icheck mkfs restor cat ls ../floppy
E 20
I 20
	cp tpcopy ${DESTDIR}/tp/copy
	cp tpboot ${DESTDIR}/tp/boot
	cp boot copy ../floppy
	cp bootup boothk boothp ${DESTDIR}/usr/mdec

# beware...

boothk.o: xxboot.c
	cc -c -S ${COPTS} -DBOOTRK xxboot.c
	/lib/c2 -i xxboot.s | as -o boothk.o
	rm -f xxboot.s

boothk: relsrt0.o boothk.o confrk.o
E 21
I 21
D 52
boothk: relsrt0.o boothk.o confrk.o /usr/lib/libsa.a
E 21
	ld -N -T ${RELOC} relsrt0.o boothk.o confrk.o -lsa -lc
E 52
I 52
D 54
boothk: relsrt0.o boothk.o confrk.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o boothk.o confrk.o ${LIBSA} -lc
E 52
D 21
	cp a.out b.out; strip b.out; dd if=b.out of=boothk ibs=32 skip=1; rm b.out
E 21
I 21
D 51
	cp a.out b.out;strip b.out;dd if=b.out of=boothk ibs=32 skip=1;rm b.out
E 51
I 51
	cp a.out b.out;strip b.out;dd if=b.out of=boothk ibs=32 skip=1;rm -f b.out
E 54
I 54
D 60
boothk: relsrt0.o boothk.o confrk.o smsys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o boothk.o confrk.o smsys.o ${LIBSA} -lc
E 60
I 60
D 62
boothk: relsrt0.o boothk.o confrk.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o boothk.o confrk.o sm_sys.o ${LIBSA} -lc
E 62
I 62
D 70
boothk: relsrt0.o bootxx.o confrk.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confrk.o sm_sys.o ${LIBSA} -lc
E 70
I 70
D 71
boothk: relsrt0.o bootxx.o confrk.o sm_sys.o sm_autoconf.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confrk.o sm_sys.o sm_autoconf.o ${LIBSA} -lc
E 71
I 71
D 83
boothk: relsrt0.o confrk.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o confrk.o ${SMOBJ} ${LIBSA} -lc
E 83
I 83
boothk: relsrt750.o confrk.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confrk.o ${SMOBJ} ${LIBSA} -lc
E 83
E 71
E 70
E 62
	size a.out
E 60
D 71
	strip a.out;dd if=a.out of=boothk ibs=32 skip=1;rm -f a.out
I 60
	ls -l boothk
E 71
I 71
D 72
	-rm -f $@
E 72
I 72
	rm -f $@
E 72
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
D 75
	ls -l $@
E 75
I 75
	${LS} -l $@
E 75
E 71
E 60
E 54
E 51
E 21

D 21
boothp.o: xxboot.c
	cc -c -S ${COPTS} -DBOOTHP xxboot.c
	/lib/c2 -i xxboot.s | as -o boothp.o
	rm -f xxboot.s
E 21
I 21
D 36
boothk.o: bootxx.c
	cc -c -S ${COPTS} -DBOOTRK bootxx.c
	/lib/c2 -i bootxx.s | as -o boothk.o
	rm -f bootxx.s
E 21

E 36
D 21
boothp: relsrt0.o boothp.o confhp.o
E 21
I 21
D 40
boothp: relsrt0.o boothp.o confhp.o /usr/lib/libsa.a
E 21
	ld -N -T ${RELOC} relsrt0.o boothp.o confhp.o -lsa -lc
E 40
I 40
D 52
boothp: relsrt0.o boothp.o confhp.o hp.old.o /usr/lib/libsa.a
	ld -N -T ${RELOC} relsrt0.o boothp.o confhp.o hp.old.o -lsa -lc
E 52
I 52
D 54
boothp: relsrt0.o boothp.o confhp.o hp.old.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o boothp.o confhp.o hp.old.o ${LIBSA} -lc
E 52
E 40
D 21
	cp a.out b.out; strip b.out; dd if=b.out of=boothp ibs=32 skip=1; rm b.out
E 21
I 21
D 51
	cp a.out b.out;strip b.out;dd if=b.out of=boothp ibs=32 skip=1;rm b.out
E 51
I 51
	cp a.out b.out;strip b.out;dd if=b.out of=boothp ibs=32 skip=1;rm -f b.out
E 54
I 54
D 60
boothp: relsrt0.o boothp.o confhp.o hp.old.o smsys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o boothp.o confhp.o hp.old.o smsys.o ${LIBSA} -lc
E 60
I 60
D 62
boothp: relsrt0.o boothp.o confhp.o sm_hp.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o boothp.o confhp.o sm_hp.o sm_sys.o ${LIBSA} -lc
E 62
I 62
D 70
boothp: relsrt0.o bootxx.o confhp.o sm_hp.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confhp.o sm_hp.o sm_sys.o ${LIBSA} -lc
E 70
I 70
D 71
boothp: relsrt0.o bootxx.o confhp.o sm_hp.o sm_sys.o sm_autoconf.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confhp.o sm_hp.o sm_sys.o sm_autoconf.o ${LIBSA} -lc
E 71
I 71
D 83
boothp: relsrt0.o confhp.o sm_hp.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o confhp.o sm_hp.o ${SMOBJ} ${LIBSA} -lc
E 83
I 83
boothp: relsrt750.o confhp.o sm_hp.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confhp.o sm_hp.o ${SMOBJ} ${LIBSA} -lc
E 83
E 71
E 70
E 62
	size a.out
E 60
D 71
	strip a.out;dd if=a.out of=boothp ibs=32 skip=1;rm -f a.out
I 60
	ls -l boothp
E 71
I 71
D 72
	-rm -f $@
E 72
I 72
	rm -f $@
E 72
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
D 75
	ls -l $@
E 75
I 75
	${LS} -l $@
E 75
E 71
E 60
E 54
E 51
E 21

I 72
D 80
bootkra: relsrt0.o confkra.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o confkra.o ${SMOBJ} ${LIBSA} -lc
E 80
I 80
D 83
bootkra: relsrt0.o confkra.o ${KRAOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o confkra.o ${KRAOBJ} ${LIBSA} -lc
E 83
I 83
bootkra: relsrt750.o confkra.o ${KRAOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confkra.o ${KRAOBJ} ${LIBSA} -lc
E 83
E 80
	size a.out
	rm -f $@
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
D 75
	ls -l $@
E 75
I 75
	${LS} -l $@
E 75

E 72
D 21
bootup.o: xxboot.c
	cc -c -S ${COPTS} -DBOOTUP xxboot.c
	/lib/c2 -i xxboot.s | as -o bootup.o
	/lib/c2 -i xxboot.s | as -o upboot.o
	rm -f xxboot.s
E 21
I 21
D 36
boothp.o: bootxx.c
	cc -c -S ${COPTS} -DBOOTHP bootxx.c
	/lib/c2 -i bootxx.s | as -o boothp.o
	rm -f bootxx.s
E 21

E 36
D 21
bootup: relsrt0.o bootup.o confup.o
E 21
I 21
D 40
bootup: relsrt0.o bootup.o confup.o /usr/lib/libsa.a
E 21
	ld -N -T ${RELOC} relsrt0.o bootup.o confup.o -lsa -lc
E 40
I 40
D 52
bootup: relsrt0.o bootup.o confup.o up.old.o /usr/lib/libsa.a
	ld -N -T ${RELOC} relsrt0.o bootup.o confup.o up.old.o -lsa -lc
E 52
I 52
D 54
bootup: relsrt0.o bootup.o confup.o up.old.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootup.o confup.o up.old.o ${LIBSA} -lc
E 52
E 40
D 21
	cp a.out b.out; strip b.out; dd if=b.out of=bootup ibs=32 skip=1; rm b.out
E 21
I 21
D 51
	cp a.out b.out;strip b.out;dd if=b.out of=bootup ibs=32 skip=1;rm b.out
E 51
I 51
	cp a.out b.out;strip b.out;dd if=b.out of=bootup ibs=32 skip=1;rm -f b.out
E 54
I 54
D 60
bootup: relsrt0.o bootup.o confup.o up.old.o smsys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootup.o confup.o up.old.o smsys.o ${LIBSA} -lc
E 60
I 60
D 62
bootup: relsrt0.o bootup.o confup.o sm_up.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootup.o confup.o sm_up.o sm_sys.o ${LIBSA} -lc
E 62
I 62
D 70
bootup: relsrt0.o bootxx.o confup.o sm_up.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confup.o sm_up.o sm_sys.o ${LIBSA} -lc
E 70
I 70
D 71
bootup: relsrt0.o bootxx.o confup.o sm_up.o sm_sys.o sm_autoconf.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confup.o sm_up.o sm_sys.o sm_autoconf.o ${LIBSA} -lc
E 71
I 71
D 83
bootup: relsrt0.o confup.o sm_up.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o confup.o sm_up.o ${SMOBJ} ${LIBSA} -lc
E 83
I 83
bootup: relsrt750.o confup.o sm_up.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confup.o sm_up.o ${SMOBJ} ${LIBSA} -lc
E 83
E 71
E 70
E 62
	size a.out
E 60
D 71
	strip a.out;dd if=a.out of=bootup ibs=32 skip=1;rm -f a.out
I 60
	ls -l bootup
E 71
I 71
D 72
	-rm -f $@
E 72
I 72
	rm -f $@
E 72
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
D 75
	ls -l $@
E 75
I 75
	${LS} -l $@
E 75
E 71
E 60
E 54
E 51
E 21

D 21
boothp.o: xxboot.c ../h/param.h ../h/inode.h ../h/pte.h ../h/reboot.h
E 21
I 21
D 36
bootup.o: bootxx.c
	cc -c -S ${COPTS} -DBOOTUP bootxx.c
	/lib/c2 -i bootxx.s | as -o bootup.o
	rm -f bootxx.s

E 36
I 34
D 52
bootra: relsrt0.o bootra.o confra.o /usr/lib/libsa.a
	ld -N -T ${RELOC} relsrt0.o bootra.o confra.o -lsa -lc
E 52
I 52
D 54
bootra: relsrt0.o bootra.o confra.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootra.o confra.o ${LIBSA} -lc
E 52
D 51
	cp a.out b.out;strip b.out;dd if=b.out of=bootra ibs=32 skip=1;rm b.out
E 51
I 51
	cp a.out b.out;strip b.out;dd if=b.out of=bootra ibs=32 skip=1;rm -f b.out
E 54
I 54
D 60
bootra: relsrt0.o bootra.o confra.o smsys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootra.o confra.o smsys.o ${LIBSA} -lc
E 60
I 60
D 62
bootra: relsrt0.o bootra.o confra.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootra.o confra.o sm_sys.o ${LIBSA} -lc
E 62
I 62
D 70
bootra: relsrt0.o bootxx.o confra.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confra.o sm_sys.o ${LIBSA} -lc
E 70
I 70
D 71
bootra: relsrt0.o bootxx.o confra.o sm_sys.o sm_autoconf.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confra.o sm_sys.o sm_autoconf.o ${LIBSA} -lc
E 71
I 71
D 80
bootra: relsrt0.o confra.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o confra.o ${SMOBJ} ${LIBSA} -lc
E 80
I 80
D 83
bootra: relsrt0.o confra.o ${RAOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o confra.o ${RAOBJ} ${LIBSA} -lc
E 83
I 83
bootra: relsrt750.o confra.o ${RAOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confra.o ${RAOBJ} ${LIBSA} -lc
E 83
E 80
E 71
E 70
E 62
	size a.out
E 60
D 71
	strip a.out;dd if=a.out of=bootra ibs=32 skip=1;rm -f a.out
I 60
	ls -l bootra
E 71
I 71
D 72
	-rm -f $@
E 72
I 72
	rm -f $@
E 72
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
D 75
	ls -l $@
E 75
I 75
	${LS} -l $@
E 75
E 71
E 60
E 54
E 51

D 36
bootra.o: bootxx.c
	cc -c -S ${COPTS} -DBOOTRA bootxx.c
	/lib/c2 -i bootxx.s | as -o bootra.o
	rm -f bootxx.s

E 36
D 52
bootrl: relsrt0.o bootrl.o confrl.o /usr/lib/libsa.a
D 38
	ld -N -T ${RELOC} relsrt0.o bootrl.o confra.o -lsa -lc
E 38
I 38
	ld -N -T ${RELOC} relsrt0.o bootrl.o confrl.o -lsa -lc
E 52
I 52
D 54
bootrl: relsrt0.o bootrl.o confrl.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootrl.o confrl.o ${LIBSA} -lc
E 52
E 38
D 51
	cp a.out b.out;strip b.out;dd if=b.out of=bootrl ibs=32 skip=1;rm b.out
E 51
I 51
	cp a.out b.out;strip b.out;dd if=b.out of=bootrl ibs=32 skip=1;rm -f b.out
E 54
I 54
D 60
bootrl: relsrt0.o bootrl.o confrl.o smsys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootrl.o confrl.o smsys.o ${LIBSA} -lc
E 60
I 60
D 62
bootrl: relsrt0.o bootrl.o confrl.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootrl.o confrl.o sm_sys.o ${LIBSA} -lc
E 62
I 62
D 70
bootrl: relsrt0.o bootxx.o confrl.o sm_sys.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confrl.o sm_sys.o ${LIBSA} -lc
E 70
I 70
D 71
bootrl: relsrt0.o bootxx.o confrl.o sm_sys.o sm_autoconf.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o bootxx.o confrl.o sm_sys.o sm_autoconf.o ${LIBSA} -lc
E 71
I 71
D 83
bootrl: relsrt0.o confrl.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o confrl.o ${SMOBJ} ${LIBSA} -lc
E 83
I 83
bootrl: relsrt750.o confrl.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confrl.o ${SMOBJ} ${LIBSA} -lc
E 83
E 71
E 70
E 62
	size a.out
E 60
D 71
	strip a.out;dd if=a.out of=bootrl ibs=32 skip=1;rm -f a.out
I 60
	ls -l bootrl
E 71
I 71
D 72
	-rm -f $@
E 72
I 72
	rm -f $@
E 72
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
D 75
	ls -l $@
E 75
I 75
	${LS} -l $@
E 75
E 71
E 60
E 54
E 51

I 84
bootdec: decsrt0.o confdec.o ${DECOBJ} ${LIBSA}
	ld -N -T ${RELOC} decsrt0.o confdec.o ${DECOBJ} ${LIBSA} -lc
	size a.out
	rm -f $@
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
	${LS} -l $@

E 84
D 36
bootrl.o: bootxx.c
	cc -c -S ${COPTS} -DBOOTRL bootxx.c
	/lib/c2 -i bootxx.s | as -o bootrl.o
	rm -f bootxx.s

E 34
D 23
boothp.o: bootxx.c ../h/param.h ../h/inode.h ../h/pte.h ../h/reboot.h
E 23
I 23
boothp.o: bootxx.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
I 36
D 56
boothp.o: boothp.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
E 23
E 21
boothp.o: ../h/fs.h saio.h
D 21
boothk.o: xxboot.c ../h/param.h ../h/inode.h ../h/pte.h ../h/reboot.h
E 21
I 21
D 23
boothk.o: bootxx.c ../h/param.h ../h/inode.h ../h/pte.h ../h/reboot.h
E 23
I 23
D 36
boothk.o: bootxx.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
I 36
boothk.o: boothk.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
E 23
E 21
boothk.o: ../h/fs.h saio.h
D 21
bootup.o: xxboot.c ../h/param.h ../h/inode.h ../h/pte.h ../h/reboot.h
E 21
I 21
D 23
bootup.o: bootxx.c ../h/param.h ../h/inode.h ../h/pte.h ../h/reboot.h
E 23
I 23
D 36
bootup.o: bootxx.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
I 36
bootup.o: bootup.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
I 34
bootup.o: ../h/fs.h saio.h
D 36
bootra.o: bootxx.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
I 36
bootra.o: bootra.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
bootra.o: ../h/fs.h saio.h
D 36
bootrl.o: bootxx.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
I 36
bootrl.o: bootrl.c ../h/param.h ../h/inode.h ../machine/pte.h ../h/reboot.h
E 36
bootrl.o: ../h/fs.h saio.h
E 56
I 56
D 62
boothp.o: boothp.c bootxx.o
boothk.o: boothk.c bootxx.o
bootup.o: bootup.c bootxx.o
bootra.o: bootra.c bootxx.o
bootrl.o: bootrl.c bootxx.o
E 56
E 34
E 23
E 21

I 54
D 56
smsys.o: sys.c
E 56
I 56
bootxx.o:
	touch bootxx.o

E 62
D 60
smsys.o: sys.o
E 56
	-rm -f smsys.c
	-ln -s sys.c smsys.c
	cc -c -DSMALL ${CFLAGS} smsys.c
	-rm -f smsys.c
E 60
I 60
sm_hp.o: hp.o
D 66
	-rm -f sm_hp.c
E 66
I 66
	rm -f sm_hp.c
E 66
D 72
	-ln -s hp.c sm_hp.c
E 72
I 72
	ln -s hp.c sm_hp.c
E 72
D 62
	cc -S -DSMALL ${COPTS} sm_hp.c
E 62
I 62
D 66
	cc -S -DSMALL ${CFLAGS} sm_hp.c
E 66
I 66
D 71
	${CC} -S -DSMALL ${CFLAGS} sm_hp.c
E 71
I 71
	${CC} -S ${SMOPTS} sm_hp.c
E 71
E 66
E 62
	/lib/c2 -i sm_hp.s | as -o sm_hp.o
	rm -f sm_hp.s sm_hp.c
E 60

I 60
sm_up.o: up.o
D 66
	-rm -f sm_up.c
E 66
I 66
	rm -f sm_up.c
E 66
D 72
	-ln -s up.c sm_up.c
E 72
I 72
	ln -s up.c sm_up.c
E 72
D 62
	cc -S -DSMALL ${COPTS} sm_up.c
E 62
I 62
D 66
	cc -S -DSMALL ${CFLAGS} sm_up.c
E 66
I 66
D 71
	${CC} -S -DSMALL ${CFLAGS} sm_up.c
E 71
I 71
	${CC} -S ${SMOPTS} sm_up.c
E 71
E 66
E 62
	/lib/c2 -i sm_up.s | as -o sm_up.o
	rm -f sm_up.s sm_up.c
I 81

sm_uda.o: uda.o
	rm -f sm_uda.c
	ln -s uda.c sm_uda.c
	${CC} -S ${RAOPTS} sm_uda.c
	/lib/c2 -i sm_uda.s | as -o sm_uda.o
	rm -f sm_uda.s sm_uda.c

sm_kdb.o: kdb.o
	rm -f sm_kdb.c
	ln -s kdb.c sm_kdb.c
	${CC} -S ${KRAOPTS} sm_kdb.c
	/lib/c2 -i sm_kdb.s | as -o sm_kdb.o
	rm -f sm_kdb.s sm_kdb.c
E 81

sm_sys.o: sys.o
D 66
	-rm -f sm_sys.c
E 66
I 66
	rm -f sm_sys.c
E 66
D 72
	-ln -s sys.c sm_sys.c
E 72
I 72
	ln -s sys.c sm_sys.c
E 72
D 66
	cc -c -DSMALL ${CFLAGS} sm_sys.c
	-rm -f sm_sys.c
E 66
I 66
D 71
	${CC} -c -DSMALL ${CFLAGS} sm_sys.c
E 71
I 71
D 80
	${CC} -c -O ${SMOPTS} sm_sys.c
E 80
I 80
	${CC} -c ${CFLAGS} -DSMALL sm_sys.c
E 80
E 71
	rm -f sm_sys.c
I 70

sm_autoconf.o: autoconf.o
	rm -f sm_autoconf.c
D 72
	-ln -s autoconf.c sm_autoconf.c
E 72
I 72
	ln -s autoconf.c sm_autoconf.c
E 72
D 71
	${CC} -c -DSMALL ${CFLAGS} sm_autoconf.c
E 71
I 71
D 80
	${CC} -c -O ${SMOPTS} sm_autoconf.c
E 71
	rm -f sm_autoconf.c
E 80
I 80
	${CC} -S ${SMOPTS} sm_autoconf.c
	/lib/c2 -i sm_autoconf.s | as -o sm_autoconf.o
	rm -f sm_autoconf.s sm_autoconf.c

ra_autoconf.o: autoconf.o
	rm -f ra_autoconf.c
	ln -s autoconf.c ra_autoconf.c
	${CC} -S ${RAOPTS} ra_autoconf.c
	/lib/c2 -i ra_autoconf.s | as -o ra_autoconf.o
	rm -f ra_autoconf.s ra_autoconf.c

kra_autoconf.o: autoconf.o
	rm -f kra_autoconf.c
	ln -s autoconf.c kra_autoconf.c
	${CC} -S ${KRAOPTS} kra_autoconf.c
	/lib/c2 -i kra_autoconf.s | as -o kra_autoconf.o
	rm -f kra_autoconf.s kra_autoconf.c
I 83

sm_scb.o: scb.o
	${CC} -E ${COPTS} -DSMALL scb.c | as -o sm_scb.o
E 83
E 80
E 70
E 66
D 62

E 60
E 54
I 36
boothk.c: bootxx.c
I 54
	-rm -f boothk.c
E 54
	sed -e 's/xx/hk/g' <bootxx.c >boothk.c
boothp.c: bootxx.c
I 54
	-rm -f boothp.c
E 54
	sed -e 's/xx/hp/g' <bootxx.c >boothp.c
bootup.c: bootxx.c
I 54
	-rm -f bootup.c
E 54
	sed -e 's/xx/up/g' <bootxx.c >bootup.c
bootra.c: bootxx.c
I 54
	-rm -f bootra.c
E 54
	sed -e 's/xx/ra/g' <bootxx.c >bootra.c
bootrl.c: bootxx.c
I 54
	-rm -f bootrl.c
E 54
	sed -e 's/xx/rl/g' <bootxx.c >bootrl.c
E 62

E 36
D 23
confrk.o: confrk.c ../h/param.h ../h/fs.h ../h/pte.h ../h/inode.h saio.h
	$(CC) -c $(CFLAGS) confrk.c
confhp.o: confhp.c ../h/param.h ../h/fs.h ../h/pte.h ../h/inode.h saio.h
	$(CC) -c $(CFLAGS) confhp.c
confup.o: confup.c ../h/param.h ../h/fs.h ../h/pte.h ../h/inode.h saio.h
	$(CC) -c $(CFLAGS) confup.c
E 23
I 23
D 56
confrk.o: confrk.c ../h/param.h ../h/fs.h ../machine/pte.h ../h/inode.h saio.h
D 36
	${CC} -c ${CFLAGS} confrk.c
E 36
confhp.o: confhp.c ../h/param.h ../h/fs.h ../machine/pte.h ../h/inode.h saio.h
D 36
	${CC} -c ${CFLAGS} confhp.c
E 36
confup.o: confup.c ../h/param.h ../h/fs.h ../machine/pte.h ../h/inode.h saio.h
D 36
	${CC} -c ${CFLAGS} confup.c
E 36
I 34
confra.o: confra.c ../h/param.h ../h/fs.h ../machine/pte.h ../h/inode.h saio.h
D 36
	${CC} -c ${CFLAGS} confra.c
E 36
confrl.o: confrl.c ../h/param.h ../h/fs.h ../machine/pte.h ../h/inode.h saio.h
E 56
I 56
confrk.o: confrk.c confxx.o
confhp.o: confhp.c confxx.o
I 72
confkra.o: confkra.c confxx.o
E 72
confup.o: confup.c confxx.o
confra.o: confra.c confxx.o
confrl.o: confrl.c confxx.o
E 56
D 36
	${CC} -c ${CFLAGS} confrl.c
E 36
E 34
E 23

I 56
confxx.o:
	touch confxx.o

E 56
D 66
confrk.c: confxx.c
I 54
	-rm -f confrk.c
E 54
	sed -e 's/XX/hk/' -e 's/xx/rk/g' <confxx.c >confrk.c
confhp.c: confxx.c
I 54
	-rm -f confhp.c
E 54
	sed -e 's/XX/hp/' -e 's/xx/hp/g' <confxx.c >confhp.c
confup.c: confxx.c
I 54
	-rm -f confup.c
E 54
	sed -e 's/XX/up/' -e 's/xx/up/g' <confxx.c >confup.c
I 34
confra.c: confxx.c
I 54
	-rm -f confra.c
E 54
	sed -e 's/XX/ra/' -e 's/xx/ra/g' <confxx.c >confra.c
confrl.c: confxx.c
I 54
	-rm -f confrl.c
E 54
	sed -e 's/XX/rl/' -e 's/xx/rl/g' <confxx.c >confrl.c
E 66
I 66
confrk.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confrk.c
	sed -e 's/XX/hk/' -e 's/xx/rk/g'	< confxx.c >> confrk.c
confhp.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confhp.c
	sed -e 's/XX/hp/' -e 's/xx/hp/g'	< confxx.c >> confhp.c
I 72
confkra.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confkra.c
	sed -e 's/XX/kra/' -e 's/xx/kra/g'	< confxx.c >> confkra.c
E 72
confup.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confup.c
	sed -e 's/XX/up/' -e 's/xx/up/g'	< confxx.c >> confup.c
confra.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confra.c
	sed -e 's/XX/ra/' -e 's/xx/ra/g'	< confxx.c >> confra.c
confrl.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confrl.c
	sed -e 's/XX/rl/' -e 's/xx/rl/g'	< confxx.c >> confrl.c
E 66
E 34
I 21

D 66
# utilities

print:
	@pr makefile
	@ls -l | pr 
	@pr *.h *.c

clean:
E 66
I 66
D 75
clean: FRC
E 75
I 75
clean:
E 75
E 66
D 60
	rm -f *.o *.exe *.i errs
E 60
I 60
D 64
	rm -f *.o *.exe *.i errs sm_*.c
E 64
I 64
D 72
	rm -f *.o *.exe *.i errs sm_*.c libsa.a
E 64
E 60
D 28
	rm -f a.out b.out boot cat tpboot tpcopy
E 28
I 28
D 30
	rm -f a.out b.out boot cat tpboot tpcopy copy
E 30
I 30
D 54
	rm -f a.out b.out boot cat tpboot tpcopy copy tpformat
E 54
I 54
	rm -f a.out boot cat tpboot tpcopy copy tpformat
E 54
E 30
E 28
D 36
	rm -f boot[a-z]? conf[a-wyz][a-z].c
E 36
I 36
	rm -f boot[a-z]? boot[a-wyz][a-z].c conf[a-wyz][a-z].c
E 36
I 28
D 30
	rm -f *chk *drtest core sboot bootconf.c
E 30
I 30
	rm -f format drtest core sboot bootconf.c
I 34
D 36
	rm -f 730boot 730copy
E 36
I 36
	rm -f 730boot 730copy 730drtest 730format
E 72
I 72
	rm -f *.o *.exe *.i sm_*.c libsa.a
D 78
	rm -f boot[a-wyz][a-z].c conf[a-wyz][a-z].c
E 78
I 78
	rm -f boot[a-wyz][a-z].c conf[a-wyz][a-z].c confkra.c
E 78
	rm -f ${ALL} a.out core errs sboot bootconf.c
E 72
E 36
E 34
E 30
E 28

D 66
lint:
	lint ${COPTS} -hxbn boot.c ${SRCS} | \
	    grep -v 'possible pointer alignment' | \
	    grep -v 'struct/union .* never defined'
E 66
I 66
D 75
depend: ${SRCS} FRC
E 75
I 75
cleandir: clean
	rm -f ${MAN} tags .depend

depend: ${SRCS}
E 75
	mkdep ${INCPATH} -DSTANDALONE ${SRCS} ${DUMMIES}
E 66

D 66
install: ${ALL}
D 53
	cp tpcopy ${DESTDIR}/tp/copy
	cp tpboot ${DESTDIR}/tp/boot
I 33
	cp tpformat ${DESTDIR}/tp/format
E 53
I 53
	cp boot ${DESTDIR}/boot
	cp format ${DESTDIR}/format
I 58
	cp copy ${DESTDIR}/copy
	cp drtest ${DESTDIR}/drtest
	strip ${DESTDIR}/format ${DESTDIR}/copy ${DESTDIR}/drtest
	cp pcs750.bin ${DESTDIR}/pcs750.bin
E 66
I 66
D 77
install: FRC
D 69
	install -c -s -o bin -g bin -m 644 format copy drtest ${DESTDIR}/
E 69
I 69
D 72
	install -c -s -o bin -g bin -m 644 format copy drtest ${DESTDIR}${STAND}
E 72
I 72
	install -c -s -o bin -g bin -m 644 format cat copy drtest ls ${DESTDIR}${STAND}
E 72
E 69
	install -c -o bin -g bin -m 644 boot pcs750.bin ${DESTDIR}/
E 77
I 77
install: installint installext

installint: FRC
E 77
I 69
D 72
	-mkdir ../vaxdist/tp
E 72
I 72
	[ -d ../vaxdist/tp ] || mkdir ../vaxdist/tp
E 72
E 69
E 66
E 58
D 68
	cp tpcopy ../dist/tp/copy
	cp tpboot ../dist/tp/boot
	cp tpformat ../dist/tp/format
E 68
I 68
	cp tpcopy ../vaxdist/tp/copy
	cp tpboot ../vaxdist/tp/boot
	cp tpformat ../vaxdist/tp/format
E 68
E 53
E 33
D 39
	cp copy a.out; strip a.out; dd if=a.out of=../floppy/copy bs=32 skip=1
	cp boot a.out; strip a.out; dd if=a.out of=../floppy/boot bs=32 skip=1
E 39
I 39
	cp boot a.out; strip a.out; \
D 58
		dd if=a.out of=../floppy/boot bs=32 skip=1
E 58
I 58
		dd if=a.out of=../floppy/boot bs=32 skip=1; rm a.out
E 58
E 39
I 34
D 79
	cp 730boot a.out; strip a.out; \
D 42
		dd if=a.out of=../cassette/boot bs=32 skip=1
E 42
I 42
D 58
		dd if=a.out of=../cassette/boot.730 bs=32 skip=1
E 58
I 58
		dd if=a.out of=../cassette/boot.730 bs=32 skip=1; rm a.out
E 58
E 42
I 39
	cp ../floppy/boot ../cassette/boot.750
E 79
I 79
	cp ../floppy/boot ../cassette/boot
E 79
I 50
	cp ../floppy/boot ../consolerl/boot
I 82
	cp ../floppy/boot ../rx50/boot
E 82
E 50
	cp copy a.out; strip a.out; \
D 58
		dd if=a.out of=../floppy/copy bs=32 skip=1
E 58
I 58
		dd if=a.out of=../floppy/copy bs=32 skip=1; rm a.out
E 58
E 39
D 79
	cp 730copy a.out; strip a.out; \
D 42
		dd if=a.out of=../cassette/copy bs=32 skip=1
E 42
I 42
D 58
		dd if=a.out of=../cassette/copy.730 bs=32 skip=1
E 58
I 58
		dd if=a.out of=../cassette/copy.730 bs=32 skip=1; rm a.out
E 58
E 42
I 39
	cp ../floppy/copy ../cassette/copy.750
E 79
I 79
	cp ../floppy/copy ../cassette/copy
E 79
I 50
	cp ../floppy/copy ../consolerl/copy
I 82
	cp ../floppy/copy ../rx50/copy
E 82
E 50
E 39
E 34
I 29
D 30
	cp upchk a.out; strip a.out; dd if=a.out of=../floppy/upchk bs=32 skip=1
	cp hpchk a.out; strip a.out; dd if=a.out of=../floppy/hpchk bs=32 skip=1
	cp hpdrtest a.out; strip a.out; \
		dd if=a.out of=../floppy/hpdrtest bs=32 skip=1
	cp updrtest a.out; strip a.out; \
		dd if=a.out of=../floppy/updrtest bs=32 skip=1
E 30
I 30
	cp format a.out; strip a.out; \
D 58
		dd if=a.out of=../floppy/format bs=32 skip=1
E 58
I 58
		dd if=a.out of=../floppy/format bs=32 skip=1; rm a.out
E 58
I 34
D 36
	cp ../floppy/format ../cassette/format
E 36
I 36
D 79
	cp 730format a.out; strip a.out; \
D 42
		dd if=a.out of=../cassette/format bs=32 skip=1
E 42
I 42
D 58
		dd if=a.out of=../cassette/format.730 bs=32 skip=1
E 58
I 58
		dd if=a.out of=../cassette/format.730 bs=32 skip=1; rm a.out
E 58
E 42
I 39
	cp ../floppy/format ../cassette/format.750
E 79
I 79
	cp ../floppy/format ../cassette/format
E 79
I 50
	cp ../floppy/format ../consolerl/format
I 82
	cp ../floppy/format ../rx50/format
E 82
E 50
E 39
E 36
E 34
	cp drtest a.out; strip a.out; \
D 58
		dd if=a.out of=../floppy/drtest bs=32 skip=1
E 58
I 58
		dd if=a.out of=../floppy/drtest bs=32 skip=1; rm a.out
E 58
E 30
E 29
D 34
	cp bootup boothk boothp ${DESTDIR}/usr/mdec
E 34
I 34
D 36
	cp ../floppy/drtest ../cassette/drtest
E 36
I 36
D 79
	cp 730drtest a.out; strip a.out; \
D 42
		dd if=a.out of=../cassette/drtest bs=32 skip=1
E 42
I 42
D 58
		dd if=a.out of=../cassette/drtest.730 bs=32 skip=1
E 58
I 58
		dd if=a.out of=../cassette/drtest.730 bs=32 skip=1; rm a.out
E 58
E 42
I 39
	cp ../floppy/drtest ../cassette/drtest.750
E 79
I 79
	cp ../floppy/drtest ../cassette/drtest
E 79
I 50
	cp ../floppy/drtest ../consolerl/drtest
I 82
	cp ../floppy/drtest ../rx50/drtest
E 82
I 77

installext: FRC
	install -c -s -o bin -g bin -m 644 format cat copy drtest ls ${DESTDIR}${STAND}
	install -c -o bin -g bin -m 644 boot pcs750.bin ${DESTDIR}/
E 77
I 72
	install -c -o bin -g bin -m 444 ${MDEC} ${DESTDIR}/usr/mdec
E 72
E 50
E 39
E 36
D 66
	cp bootup boothk boothp bootra bootrl ${DESTDIR}/usr/mdec
E 66
I 66
D 86
	rm -f ${DESTDIR}/usr/mdec/bootrd
D 72
	install -c -o bin -g bin -m 444 bootup boothk boothp bootra bootrl ${DESTDIR}/usr/mdec
E 72
E 66
I 65
	ln ${DESTDIR}/usr/mdec/bootra ${DESTDIR}/usr/mdec/bootrd
E 86
E 65
E 34

D 56
# beware...
E 56
I 56
D 66
depend:
D 65
	for i in ${SRCS} ${DUMMIES}; do \
	    cc -M ${INCPATH} $$i | \
	    awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		else rec = rec " " $$2 } } \
		END { print rec } ' >> makedep; done
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 65
I 65
	mkdep ${INCPATH} -DSTANDALONE ${SRCS} ${DUMMIES}
E 66
I 66
D 75
lint:
E 75
I 75
lint: ${SRCS}
E 75
	lint ${COPTS} -hxbn boot.c ${SRCS} | \
	    sed -e '/possible pointer alignment/d' \
		-e '/struct\/union .* never defined/d'
E 66
E 65

D 66
# DO NOT DELETE THIS LINE -- make depend uses it


D 57
sys.o: sys.c ./../h/param.h ../machine/machparam.h /usr/include/signal.h
E 57
I 57
sys.o: sys.c ./../h/param.h /usr/include/machine/machparam.h ../h/signal.h
E 57
sys.o: /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h ./../h/dir.h
sys.o: ./saio.h

D 57
conf.o: conf.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
conf.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h
conf.o: ./../h/fs.h ./../vaxmba/mbareg.h ./saio.h
E 57
I 57
conf.o: conf.c ./../machine/pte.h ./../h/param.h
conf.o: /usr/include/machine/machparam.h ../h/signal.h /usr/include/sys/types.h
conf.o: ./../h/inode.h ./../h/fs.h ./../vaxmba/mbareg.h ./saio.h
E 57

D 57
prf.o: prf.c ./../h/param.h ../machine/machparam.h /usr/include/signal.h
E 57
I 57
prf.o: prf.c ./../h/param.h /usr/include/machine/machparam.h ../h/signal.h
E 57
prf.o: /usr/include/sys/types.h ./../vax/mtpr.h ./../vax/cons.h

D 57
machdep.o: machdep.c ./../h/param.h ../machine/machparam.h
machdep.o: /usr/include/signal.h /usr/include/sys/types.h ./../vax/mtpr.h
E 57
I 57
machdep.o: machdep.c ./../h/param.h /usr/include/machine/machparam.h
machdep.o: ../h/signal.h /usr/include/sys/types.h ./../vax/mtpr.h
E 57

D 57
autoconf.o: autoconf.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
autoconf.o: /usr/include/signal.h /usr/include/sys/types.h ./../vax/cpu.h
autoconf.o: ./../vax/nexus.h ./../vaxuba/ubareg.h ./../vaxmba/mbareg.h
autoconf.o: ./../vax/mtpr.h ./savax.h
E 57
I 57
autoconf.o: autoconf.c ./../machine/pte.h ./../h/param.h
autoconf.o: /usr/include/machine/machparam.h ../h/signal.h
autoconf.o: /usr/include/sys/types.h ./../vax/cpu.h ./../vax/nexus.h
autoconf.o: ./../vaxuba/ubareg.h ./../vaxmba/mbareg.h ./../vax/mtpr.h ./savax.h
E 57

D 57
hp.o: hp.c ./../h/param.h ../machine/machparam.h /usr/include/signal.h
E 57
I 57
hp.o: hp.c ./../h/param.h /usr/include/machine/machparam.h ../h/signal.h
E 57
hp.o: /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h ./../h/dkbad.h
hp.o: ./../vax/pte.h ./../vaxmba/hpreg.h ./../vaxmba/mbareg.h ./saio.h
hp.o: ./savax.h
E 66
I 66
D 75
tags: ${SRCS} FRC
E 75
I 75
tags: ${SRCS}
E 75
	ctags ${SRCS} ${DUMMIES}
E 66

D 66
hpmaptype.o: hpmaptype.c ./../machine/pte.h ./../h/param.h
D 57
hpmaptype.o: ../machine/machparam.h /usr/include/signal.h
E 57
I 57
hpmaptype.o: /usr/include/machine/machparam.h ../h/signal.h
E 57
hpmaptype.o: /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
hpmaptype.o: ./../vaxmba/hpreg.h ./../vaxmba/mbareg.h ./saio.h ./savax.h
E 66
I 66
FRC:
I 84
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 84
E 66
D 75

D 57
ht.o: ht.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
ht.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
I 57
D 66
ht.o: ht.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
ht.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
ht.o: ./../vaxmba/htreg.h ./../vaxmba/mbareg.h ./saio.h ./savax.h
E 66
I 66
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 66

D 57
idc.o: idc.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
idc.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h
idc.o: ./../h/fs.h ./../vaxuba/idcreg.h ./../vaxuba/ubareg.h ./saio.h ./savax.h
E 57
I 57
D 66
idc.o: idc.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
idc.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
idc.o: ./../vaxuba/idcreg.h ./../vaxuba/ubareg.h ./saio.h ./savax.h
E 57

D 57
mba.o: mba.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
mba.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h
mba.o: ./../h/fs.h ./../h/vm.h /usr/include/sys/vmparam.h ../machine/vmparam.h
E 57
I 57
mba.o: mba.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
mba.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
mba.o: ./../h/vm.h /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
E 57
mba.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
mba.o: /usr/include/sys/vmsystm.h ./../vax/mtpr.h ./../vaxmba/mbareg.h
mba.o: ./../vaxmba/hpreg.h ./saio.h ./savax.h

D 57
mt.o: mt.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
mt.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
I 57
mt.o: mt.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
mt.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
mt.o: ./../vaxmba/mtreg.h ./../vaxmba/mbareg.h ./saio.h ./savax.h

D 57
rk.o: rk.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
rk.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
I 57
rk.o: rk.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
rk.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
rk.o: ./../vaxuba/ubareg.h ./../vaxuba/rkreg.h ./saio.h ./savax.h

D 57
rl.o: rl.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
rl.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
I 57
rl.o: rl.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
rl.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
rl.o: ./../vaxuba/rlreg.h ./../vaxuba/ubareg.h ./saio.h ./savax.h

D 57
tm.o: tm.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
tm.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
I 57
tm.o: tm.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
tm.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
tm.o: ./../vaxuba/ubareg.h ./../vaxuba/tmreg.h ./saio.h ./savax.h

D 57
ts.o: ts.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
ts.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
I 57
ts.o: ts.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
ts.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
ts.o: ./../vaxuba/tsreg.h ./../vaxuba/ubareg.h ./saio.h ./savax.h

D 57
up.o: up.c ./../h/param.h ../machine/machparam.h /usr/include/signal.h
E 57
I 57
up.o: up.c ./../h/param.h /usr/include/machine/machparam.h ../h/signal.h
E 57
up.o: /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h ./../h/dkbad.h
up.o: ./../h/vmmac.h ./../vax/pte.h ./../vaxuba/upreg.h ./../vaxuba/ubareg.h
up.o: ./saio.h ./savax.h

D 57
upmaptype.o: upmaptype.c ./../h/param.h ../machine/machparam.h
upmaptype.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h
upmaptype.o: ./../h/fs.h ./../h/dkbad.h ./../h/vmmac.h ./../vax/pte.h
upmaptype.o: ./../vaxuba/upreg.h ./../vaxuba/ubareg.h ./saio.h ./savax.h
E 57
I 57
upmaptype.o: upmaptype.c ./../h/param.h /usr/include/machine/machparam.h
upmaptype.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
upmaptype.o: ./../h/dkbad.h ./../h/vmmac.h ./../vax/pte.h ./../vaxuba/upreg.h
upmaptype.o: ./../vaxuba/ubareg.h ./saio.h ./savax.h
E 66
I 66
autoconf.o: autoconf.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h
autoconf.o: ../h/signal.h /usr/include/machine/trap.h
autoconf.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
autoconf.o: ../vax/cpu.h ../vax/nexus.h ../vaxuba/ubareg.h ../vaxmba/mbareg.h
autoconf.o: ../vax/mtpr.h savax.h
boot.o: boot.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
boot.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
boot.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/vm.h
D 67
boot.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
boot.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
boot.o: /usr/include/sys/vmsystm.h ../h/reboot.h /usr/include/a.out.h
E 67
I 67
boot.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
boot.o: ../h/vmsystm.h ../h/reboot.h /usr/include/a.out.h
E 67
boot.o: /usr/include/sys/exec.h ../stand/saio.h ../stand/saioctl.h
boot.o: ../stand/saerrno.h
bootxx.o: bootxx.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
bootxx.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
bootxx.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/vm.h
D 67
bootxx.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
bootxx.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
bootxx.o: /usr/include/sys/vmsystm.h ../h/reboot.h /usr/include/a.out.h
E 67
I 67
bootxx.o: ../h/vmparam.h ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h
bootxx.o: ../h/vmsystm.h ../h/reboot.h /usr/include/a.out.h
E 67
bootxx.o: /usr/include/sys/exec.h ../stand/saio.h ../stand/saioctl.h
bootxx.o: ../stand/saerrno.h
cat.o: ../stand/cat.c
copy.o: ../stand/copy.c
dev.o: ../stand/dev.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
dev.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
dev.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../stand/saio.h
dev.o: ../stand/saioctl.h ../stand/saerrno.h
drtest.o: drtest.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
drtest.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
drtest.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/disklabel.h
drtest.o: ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h drtest.c
drtest.o: ../h/param.h /usr/include/sys/types.h ../h/signal.h
drtest.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
drtest.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/disklabel.h
drtest.o: ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
format.o: format.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
format.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
format.o: /usr/include/machine/endian.h ../h/fs.h ../h/inode.h ../h/dkbad.h
format.o: ../h/vmmac.h ../h/disklabel.h ../vax/cpu.h ../vax/mtpr.h
format.o: ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h savax.h
format.o: format.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
format.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
format.o: /usr/include/machine/endian.h ../h/fs.h ../h/inode.h ../h/dkbad.h
format.o: ../h/vmmac.h ../h/disklabel.h ../vax/cpu.h ../vax/mtpr.h
format.o: ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h savax.h
getfile.o: ../stand/getfile.c ../h/param.h /usr/include/sys/types.h
getfile.o: ../h/signal.h /usr/include/machine/trap.h
getfile.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
getfile.o: ../h/inode.h ../h/fs.h ../stand/saio.h ../stand/saioctl.h
getfile.o: ../stand/saerrno.h
gets.o: ../stand/gets.c
hp.o: hp.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
hp.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
hp.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/dkbad.h
hp.o: ../h/disklabel.h ../vax/pte.h ../vaxmba/hpreg.h ../vaxmba/mbareg.h
hp.o: ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h savax.h
hpmaptype.o: hpmaptype.c
ht.o: ht.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h ../h/signal.h
ht.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
ht.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../vaxmba/htreg.h
ht.o: ../vaxmba/mbareg.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
ht.o: savax.h
idc.o: idc.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h
idc.o: ../h/signal.h /usr/include/machine/trap.h
idc.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
idc.o: ../h/inode.h ../h/fs.h ../vaxuba/idcreg.h ../vaxuba/ubareg.h
idc.o: ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h savax.h
machdep.o: machdep.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
machdep.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
machdep.o: /usr/include/machine/endian.h ../vax/mtpr.h
mba.o: mba.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h
mba.o: ../h/signal.h /usr/include/machine/trap.h
mba.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
D 67
mba.o: ../h/inode.h ../h/fs.h ../h/vm.h /usr/include/sys/vmparam.h
mba.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
mba.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h ../vax/mtpr.h
mba.o: ../vaxmba/mbareg.h ../vaxmba/hpreg.h ../stand/saio.h ../stand/saioctl.h
mba.o: ../stand/saerrno.h savax.h
E 67
I 67
mba.o: ../h/inode.h ../h/fs.h ../h/vm.h ../h/vmparam.h
mba.o: ../h/../machine/vmparam.h ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h
mba.o: ../vax/mtpr.h ../vaxmba/mbareg.h ../vaxmba/hpreg.h ../stand/saio.h
mba.o: ../stand/saioctl.h ../stand/saerrno.h savax.h
E 67
mt.o: mt.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h ../h/signal.h
mt.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
mt.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../vaxmba/mtreg.h
mt.o: ../vaxmba/mbareg.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
mt.o: savax.h
prf.o: prf.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
prf.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
prf.o: /usr/include/machine/endian.h ../vax/mtpr.h ../vax/cons.h
printn.o: ../stand/printn.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
printn.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
printn.o: /usr/include/machine/endian.h
I 67
qdcons.o: qdcons.c ../h/types.h ../vax/cpu.h ../ultrix/qdioctl.h
qdcons.o: ../ultrix/../h/ioctl.h ../ultrix/../h/ttychars.h
qdcons.o: ../ultrix/../h/ttydev.h ../ultrix/qevent.h ../ultrix/qduser.h
qdcons.o: ../ultrix/qevent.h ../ultrix/qdreg.h
qvcons.o: qvcons.c ../h/types.h ../ultrix/qvioctl.h ../ultrix/qevent.h
qvcons.o: ../ultrix/../h/ioctl.h ../ultrix/../h/ttychars.h
qvcons.o: ../ultrix/../h/ttydev.h ../ultrix/qvreg.h ../vax/cpu.h
qfont.o: qfont.c
E 67
rk.o: rk.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
rk.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
rk.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/disklabel.h
rk.o: ../vax/pte.h ../vaxuba/ubareg.h ../vaxuba/rkreg.h ../stand/saio.h
rk.o: ../stand/saioctl.h ../stand/saerrno.h savax.h
rl.o: rl.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h ../h/signal.h
rl.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
rl.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../vaxuba/rlreg.h
rl.o: ../vaxuba/ubareg.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
rl.o: savax.h
sys.o: ../stand/sys.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
sys.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
sys.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/dir.h
sys.o: ../h/reboot.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
tm.o: tm.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h ../h/signal.h
tm.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
tm.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../vaxuba/ubareg.h
tm.o: ../vaxuba/tmreg.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
tm.o: savax.h
tmscp.o: tmscp.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
tmscp.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
tmscp.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../vax/pte.h
tmscp.o: savax.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
tmscp.o: ../vaxuba/tmscpreg.h ../vaxuba/ubareg.h ../vax/tmscp.h
ts.o: ts.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h ../h/signal.h
ts.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
ts.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../vaxuba/tsreg.h
ts.o: ../vaxuba/ubareg.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
ts.o: savax.h
uba.o: uba.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h
uba.o: ../h/signal.h /usr/include/machine/trap.h
uba.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
D 67
uba.o: ../h/inode.h ../h/vm.h /usr/include/sys/vmparam.h
uba.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
uba.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h ../h/fs.h
uba.o: ../vax/cpu.h ../vaxuba/ubareg.h ../stand/saio.h ../stand/saioctl.h
uba.o: ../stand/saerrno.h savax.h
E 67
I 67
uba.o: ../h/inode.h ../h/vm.h ../h/vmparam.h ../h/../machine/vmparam.h
uba.o: ../h/vmmac.h ../h/vmmeter.h ../h/vmsystm.h ../h/fs.h ../vax/cpu.h
uba.o: ../vaxuba/ubareg.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
uba.o: savax.h
E 67
uda.o: uda.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h
uda.o: ../h/signal.h /usr/include/machine/trap.h
uda.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
uda.o: ../h/inode.h ../h/fs.h ../h/disklabel.h ../stand/saio.h
uda.o: ../stand/saioctl.h ../stand/saerrno.h savax.h ../vaxuba/udareg.h
uda.o: ../vaxuba/ubareg.h ../vax/mscp.h
up.o: up.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
up.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
up.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/dkbad.h
up.o: ../h/disklabel.h ../vax/pte.h ../vaxuba/upreg.h ../vaxuba/ubareg.h
up.o: ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h savax.h
upmaptype.o: upmaptype.c
ut.o: ut.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h ../h/signal.h
ut.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
ut.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../vaxuba/ubareg.h
ut.o: ../vaxuba/utreg.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
ut.o: savax.h
conf.o: conf.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
conf.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
conf.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../stand/saio.h
conf.o: ../stand/saioctl.h ../stand/saerrno.h
dkbad.o: ../vax/dkbad.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
dkbad.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
dkbad.o: /usr/include/machine/endian.h ../h/buf.h ../h/dkbad.h
confxx.o: confxx.c
E 66
E 57

D 57
uba.o: uba.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
uba.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h
uba.o: ./../h/vm.h /usr/include/sys/vmparam.h ../machine/vmparam.h
E 57
I 57
D 66
uba.o: uba.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
uba.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/vm.h
uba.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
E 57
uba.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
uba.o: /usr/include/sys/vmsystm.h ./../h/fs.h ./../vax/cpu.h
uba.o: ./../vaxuba/ubareg.h ./saio.h ./savax.h

D 57
uda.o: uda.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
uda.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h
uda.o: ./../h/fs.h ./saio.h ./savax.h ./../vaxuba/udareg.h ./../vaxuba/ubareg.h
E 57
I 57
uda.o: uda.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
uda.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
uda.o: ./saio.h ./savax.h ./../vaxuba/udareg.h ./../vaxuba/ubareg.h
E 57
uda.o: ./../vax/mscp.h

D 57
ut.o: ut.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
ut.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
I 57
ut.o: ut.c ./../machine/pte.h ./../h/param.h /usr/include/machine/machparam.h
ut.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
E 57
ut.o: ./../vaxuba/ubareg.h ./../vaxuba/utreg.h ./saio.h ./savax.h

D 57
drtest.o: drtest.c ./../h/param.h ../machine/machparam.h /usr/include/signal.h
drtest.o: /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h ./saio.h
E 57
I 57
drtest.o: drtest.c ./../h/param.h /usr/include/machine/machparam.h
drtest.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
drtest.o: ./saio.h
E 57

D 57
format.o: format.c ./../h/param.h ../machine/machparam.h /usr/include/signal.h
format.o: /usr/include/sys/types.h ./../h/fs.h ./../h/inode.h ./../h/dkbad.h
format.o: ./../h/vmmac.h ./saio.h ./savax.h
E 57
I 57
format.o: format.c ./../h/param.h /usr/include/machine/machparam.h
format.o: ../h/signal.h /usr/include/sys/types.h ./../h/fs.h ./../h/inode.h
format.o: ./../h/dkbad.h ./../h/vmmac.h ./saio.h ./savax.h
E 57
D 60

D 57
up.old.o: up.old.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
up.old.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h
up.old.o: ./../h/fs.h ./../vaxuba/upreg.h ./../vaxuba/ubareg.h ./saio.h
up.old.o: ./savax.h
E 57
I 57
up.old.o: up.old.c ./../machine/pte.h ./../h/param.h
up.old.o: /usr/include/machine/machparam.h ../h/signal.h
up.old.o: /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
up.old.o: ./../vaxuba/upreg.h ./../vaxuba/ubareg.h ./saio.h ./savax.h
E 57

D 57
hp.old.o: hp.old.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
hp.old.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h
hp.old.o: ./../h/fs.h ./../vaxmba/hpreg.h ./../vaxmba/mbareg.h ./saio.h
hp.old.o: ./savax.h
E 57
I 57
hp.old.o: hp.old.c ./../machine/pte.h ./../h/param.h
hp.old.o: /usr/include/machine/machparam.h ../h/signal.h
hp.old.o: /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
hp.old.o: ./../vaxmba/hpreg.h ./../vaxmba/mbareg.h ./saio.h ./savax.h
E 60
E 57

D 57
bootxx.o: bootxx.c ./../h/param.h ../machine/machparam.h /usr/include/signal.h
bootxx.o: /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h ./../h/vm.h
bootxx.o: /usr/include/sys/vmparam.h ../machine/vmparam.h
E 57
I 57
dkbad.o: ../vax/dkbad.c ../h/param.h /usr/include/machine/machparam.h
dkbad.o: ../h/signal.h /usr/include/sys/types.h ../h/buf.h ../h/dkbad.h

bootxx.o: bootxx.c ./../h/param.h /usr/include/machine/machparam.h
bootxx.o: ../h/signal.h /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h
bootxx.o: ./../h/vm.h /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
E 57
bootxx.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
bootxx.o: /usr/include/sys/vmsystm.h /usr/include/a.out.h
bootxx.o: /usr/include/sys/exec.h ./saio.h ./../h/reboot.h

D 57
confxx.o: confxx.c ./../machine/pte.h ./../h/param.h ../machine/machparam.h
confxx.o: /usr/include/signal.h /usr/include/sys/types.h ./../h/inode.h
confxx.o: ./../h/fs.h ./saio.h
E 57
I 57
confxx.o: confxx.c ./../machine/pte.h ./../h/param.h
confxx.o: /usr/include/machine/machparam.h ../h/signal.h
confxx.o: /usr/include/sys/types.h ./../h/inode.h ./../h/fs.h ./saio.h
E 57
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 66
I 66
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 75
E 66
E 56
E 21
E 20
E 10
E 9
E 4
E 1
