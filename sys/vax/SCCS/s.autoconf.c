h05629
s 00077/00000/01430
d D 7.26 04/03/20 02:15:16 msokolov 109 108
c add BabyVAX probing
e
s 00008/00000/01422
d D 7.25 04/03/18 19:12:52 msokolov 108 107
c need to provide a dummy uba_hd[] for sans-UBA machines since vaxuba/ubavar.h
c externs it and we use that header everywhere
e
s 00007/00002/01415
d D 7.24 04/03/06 20:22:25 msokolov 107 106
c pnexus devices:	on further thought, munge ui_ctlr before calling ud_slave
c just like before
e
s 00142/00095/01275
d D 7.23 04/03/06 01:50:50 msokolov 106 105
c start knocking some sanity into VAXBI support
e
s 00005/00001/01365
d D 7.22 04/01/04 11:19:14 msokolov 105 104
c be more informative when punting that a cpu is unknown or unsupported
e
s 00004/00015/01362
d D 7.21 04/01/03 18:11:18 msokolov 104 103
c new CPU ID logic
c move printing of "MicroVAX ..." banner to cpu_init routines in ka6??.c
e
s 00001/00000/01376
d D 7.20 03/05/03 13:30:29 msokolov 103 102
c teach the kernel which CPUs have compatibility mode and which don't
e
s 00001/00000/01375
d D 7.19 99/09/05 14:02:52 msokolov 102 101
c recognize BI KLESI as a DWBUA in disguise
e
s 00015/00012/01360
d D 7.18 99/01/09 23:04:30 msokolov 101 100
c put interrupt br, cvec in globals for qbus code
e
s 00003/00003/01369
d D 7.17 88/09/02 11:53:41 tef 100 99
c must use 8600 SID defs on an 8600 cpu
e
s 00006/00001/01366
d D 7.16 88/08/27 07:01:10 tef 99 98
c Add support for microvax 3000.
e
s 00004/00004/01363
d D 7.15 88/05/26 09:37:20 karels 98 97
c lint
e
s 00345/00080/01022
d D 7.14 88/05/07 14:19:03 karels 97 96
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00008/00006/01094
d D 7.13 88/02/08 13:40:35 karels 96 95
c new bootdev macros, check controller; off by one
e
s 00001/00001/01099
d D 7.12 88/01/22 08:34:31 karels 95 94
c it compiles better when spelled correctly (karels)
e
s 00003/00000/01097
d D 7.11 87/11/24 12:12:05 mckusick 94 93
c check for malloc failure znd zero memory (from jim%wind@bellcore.com)
e
s 00001/00000/01096
d D 7.10 87/10/28 15:59:36 mckusick 93 92
c break after a match is made (4.3BSD/sys/163 alex@cca.cca.com)
e
s 00002/00002/01094
d D 7.9 87/10/22 19:49:08 kre 92 91
c 4Mb of unibus device space is more than usually present
e
s 00005/00003/01092
d D 7.8 87/06/22 10:57:09 mckusick 91 90
c zmemall => malloc
e
s 00005/00003/01090
d D 7.7 87/06/06 15:10:36 mckusick 90 88
c calloc => malloc
e
s 00004/00003/01090
d R 7.7 87/06/06 15:07:12 mckusick 89 88
c calloc => malloc
e
s 00003/00007/01090
d D 7.6 87/04/02 16:36:24 karels 88 86
c working with pack labels
e
s 00066/00007/01090
d D 7.5.1.1 87/04/02 16:35:55 karels 87 86
c ifdefs for dev_bsize (almost working_
e
s 00002/00001/01095
d D 7.5 87/02/20 18:02:20 karels 86 85
c save on newlines
e
s 00005/00004/01091
d D 7.4 87/02/19 17:04:20 karels 85 84
c enable mba interrupts before probing slaves, for disklabels;
c kdb
e
s 00027/00002/01068
d D 7.3 86/12/01 16:43:54 karels 84 83
c mark unibus mass storage devices csr addresses as used;
c check for and warn about overlaps.
e
s 00145/00083/00925
d D 7.2 86/08/09 15:08:56 karels 83 82
c generalize uba code to handle Q bus more gracefully
e
s 00000/00000/01008
d D 7.1 86/06/06 19:19:09 karels 82 81
c 4.3BSD release version
e
s 00011/00011/00997
d D 6.27 86/06/06 19:18:21 karels 81 79
c need to set swap even if setroot works on generic
e
s 00000/00000/01008
d R 7.1 86/06/05 00:40:24 mckusick 80 79
c 4.3BSD release version
e
s 00043/00015/00965
d D 6.26 86/05/27 19:32:04 karels 79 78
c remap massbus unit numbers when choosing root (not necessarily 1:1)
e
s 00027/00003/00953
d D 6.25 86/04/22 10:50:42 kridle 78 77
c Added MicroVAX II Support (KA630)
e
s 00002/00002/00954
d D 6.24 86/03/30 19:02:29 karels 77 76
c fix cleanups
e
s 00010/00028/00946
d D 6.23 86/03/29 23:06:11 karels 76 75
c touchups
e
s 00004/00001/00970
d D 6.22 86/03/20 14:30:42 karels 75 74
c setroot needs conditional for NMBA
e
s 00004/00003/00967
d D 6.21 86/03/13 20:44:10 karels 74 73
c add device magic field so can tell whether boot left us a bootdev
e
s 00003/00002/00967
d D 6.20 86/03/12 18:46:38 karels 73 72
c say so when changing rootdev; lint
e
s 00004/00002/00965
d D 6.19 86/03/12 15:17:00 karels 72 71
c say so when changing rootdev
e
s 00108/00001/00859
d D 6.18 86/03/12 11:13:28 karels 71 70
c save r10 (boot device); use it to set rootdev and maybe swap, arg and dump devs
e
s 00076/00074/00784
d D 6.17 86/02/23 23:05:05 karels 70 69
c rework data structures to be more flexible about I/O buses
e
s 00002/00002/00856
d D 6.16 86/02/05 17:32:34 bloom 69 68
c get correct virtual address for second sbi
e
s 00002/00000/00856
d D 6.15 85/09/17 23:04:09 karels 68 67
c add cpuspeed variable to adjust delay macro
e
s 00007/00001/00849
d D 6.14 85/09/07 23:12:56 bloom 67 66
c add support for 256K memory chips (from ghg@purdue)
e
s 00006/00008/00844
d D 6.13 85/09/04 08:22:13 karels 66 65
c avoid those uninitialized variables; dump all of memory if it fits
e
s 00123/00030/00729
d D 6.12 85/08/05 17:56:06 bloom 65 64
c add support for 8600
e
s 00007/00001/00752
d D 6.11 85/06/08 13:39:18 mckusick 64 63
c Add copyright
e
s 00002/00002/00751
d D 6.10 85/04/17 23:25:27 sam 63 62
c checking wrong device (potentially) in calculating dumplo
e
s 00000/00013/00753
d D 6.9 85/03/08 15:47:05 mckusick 62 61
c calculation of maximum vm size is now done by vminit() in vm_page.c
e
s 00008/00003/00758
d D 6.8 85/03/07 20:24:03 karels 61 60
c configure unibus memory before others; let the probe routines
c see who they're probing
e
s 00014/00014/00747
d D 6.7 84/08/28 18:08:13 bloom 60 59
c Change to includes.  No more ../h
e
s 00016/00012/00745
d D 6.6 84/02/16 12:20:13 karels 59 57
c consistency checks and data structures based on NUBA, not half MAXNUBA
e
s 00016/00012/00745
d R 6.6 84/02/15 11:51:11 karels 58 57
c consistency checks and data structures based on NUBA, not half MAXNUBA
e
s 00002/00000/00755
d D 6.5 84/02/03 08:42:36 karels 57 56
c allow DMMAX to be defined externally
e
s 00035/00002/00720
d D 6.4 84/02/02 11:31:39 karels 56 55
c support for M780E (from salkind@nyu)
e
s 00001/00000/00721
d D 6.3 83/08/11 19:30:21 sam 55 54
c must include uba.h for NUBA to work
e
s 00001/00001/00720
d D 6.2 83/08/01 19:01:10 sam 54 53
c didn't get the last page of UNIBUS vectors
e
s 00000/00000/00721
d D 6.1 83/08/01 12:07:49 sam 53 51
c 4.2 distribution
e
s 00000/00000/00721
d R 4.50 83/08/01 12:04:40 sam 52 51
c 4.2 distribution
e
s 00028/00006/00693
d D 4.49 83/08/01 12:02:41 sam 51 49
c add support for second uba on 750; move rpb in front of 
c scb, otherwise it would be at variable location; add nexi numbers 
c for 64K chip controllers and ci
e
s 00000/00000/00699
d R 6.1 83/07/29 07:19:04 sam 50 49
c 4.2 distribution
e
s 00004/00005/00695
d D 4.48 83/06/28 19:33:00 sam 49 48
c avoid people specifying page areas larger than partition size
e
s 00043/00000/00657
d D 4.47 83/05/18 02:09:07 sam 48 47
c support multiple variable sized swap areas (some from shannon)
e
s 00002/00002/00655
d D 4.46 83/01/01 18:08:22 sam 47 46
c second arg to probe routine for uba mass storage devies is um_ctlr
e
s 00002/00001/00655
d D 4.45 82/12/17 11:55:18 sam 46 45
c sun merge
e
s 00001/00000/00655
d D 4.44 82/10/31 15:21:56 root 45 44
c declare catcher here
e
s 00000/00004/00655
d D 4.43 82/10/23 10:08:20 root 44 43
c more lint
e
s 00010/00009/00649
d D 4.42 82/10/13 22:12:42 root 43 42
c rearrange header files
e
s 00002/00001/00656
d D 4.41 82/07/21 09:42:34 feldman 42 41
c 3com updates for 780 (from Bill Reeves)
e
s 00090/00018/00567
d D 4.40 82/07/15 20:24:40 kre 41 40
c allow '?' for spec of slave of mba device
c don't double allocate unibus i/o addr space
c make use of xxstd addr arrays in unibus drivers
e
s 00003/00000/00582
d D 4.39 82/07/13 16:22:11 root 40 39
c si mba kludge (avoid recognition of non-existant devices)
e
s 00003/00020/00579
d D 4.38 82/05/19 15:34:25 wnj 39 38
c uba resets didn't free up bdp's and map registers
e
s 00003/00002/00596
d D 4.37 82/05/06 19:44:03 feldman 38 37
c fixed setting uba device physical address (from hpda!Jskud)
e
s 00012/00007/00586
d D 4.36 82/04/11 19:37:52 sam 37 36
c mods from shannon to autoconfigure mba devices after boot
e
s 00017/00005/00576
d D 4.35 82/04/11 01:06:37 feldman 36 35
c support for ec driver
e
s 00002/00000/00579
d D 4.34 82/03/31 09:03:41 wnj 35 34
c massbus check for DPR
e
s 00001/00005/00578
d D 4.33 82/02/08 23:10:54 root 34 33
c bring up to date regarding mba configurations
e
s 00008/00005/00575
d D 4.32 81/11/07 10:37:42 wnj 33 32
c fixes from shannon
e
s 00004/00003/00576
d D 4.31 81/07/05 23:07:18 bugs 32 30
c fix to strange multi-uba's per kre
e
s 00004/00003/00576
d R 4.31 81/07/05 23:02:58 bugs 31 30
c fix per kre when uba's not at normal tr's
e
s 00002/00002/00577
d D 4.30 81/04/03 00:08:24 root 30 29
c s/730/7ZZ
e
s 00009/00001/00570
d D 4.29 81/03/21 15:50:37 wnj 29 28
c add 730
e
s 00011/00003/00560
d D 4.28 81/03/16 00:50:46 wnj 28 27
c working autoconf version
e
s 00018/00097/00545
d D 4.27 81/03/13 21:47:29 wnj 27 26
c cleaned up new cpu.h
e
s 00000/00000/00642
d D 4.26 81/03/09 01:51:42 wnj 26 25
c %G% -> %E%
e
s 00030/00020/00612
d D 4.25 81/03/09 00:32:00 wnj 25 24
c lint
e
s 00082/00027/00550
d D 4.24 81/03/08 20:12:09 wnj 24 23
c fixups just pre lint
e
s 00044/00030/00533
d D 4.23 81/03/07 14:26:35 wnj 23 22
c after attempt at ht driver at cc again; working with new 
c field names
e
s 00001/00001/00562
d D 4.22 81/03/06 23:28:50 wnj 22 21
c speeling error
e
s 00010/00004/00553
d D 4.21 81/03/06 10:29:28 wnj 21 20
c print slave numbers on mba tapes
e
s 00002/00001/00555
d D 4.20 81/03/03 12:38:08 wnj 20 19
c further driver work... up now handles spin down; rest still dont
e
s 00001/00001/00555
d D 4.19 81/02/28 17:36:42 wnj 19 18
c rmalloc and related stuff
e
s 00001/00000/00555
d D 4.18 81/02/27 17:49:29 wnj 18 17
c system sized at boot version
e
s 00001/00001/00554
d D 4.17 81/02/27 03:16:09 wnj 17 16
c HZ->hz
e
s 00010/00006/00545
d D 4.16 81/02/27 02:41:19 wnj 16 15
c correct message to say mbas not configd not not supported
e
s 00020/00003/00531
d D 4.15 81/02/26 21:59:49 wnj 15 14
c elim code when no mba's
e
s 00000/00000/00534
d D 4.14 81/02/26 12:48:35 wnj 14 13
c stamp send to dec
e
s 00000/00001/00534
d D 4.13 81/02/26 04:28:59 wnj 13 12
c cosmetic for new config and 750/780
e
s 00001/00001/00534
d D 4.12 81/02/25 23:36:52 wnj 12 11
c convert VAX==??? to VAX???
e
s 00011/00005/00524
d D 4.11 81/02/23 20:10:25 wnj 11 10
c print out mcr's... prints for 750... write protect sysmap...
e
s 00001/00001/00528
d D 4.10 81/02/22 21:46:41 wnj 10 9
c working interlocked system
e
s 00015/00010/00514
d D 4.9 81/02/21 21:21:16 wnj 9 8
c first working uba interlockable version
e
s 00054/00160/00470
d D 4.8 81/02/19 21:59:09 wnj 8 7
c almost working ubago version (tm.c problems)
e
s 00000/00000/00630
d D 4.7 81/02/18 16:14:36 wnj 7 6
c working dm code
e
s 00000/00001/00630
d D 4.6 81/02/17 17:34:42 wnj 6 5
c minor cleanups... for dh: DELAY(5)s
e
s 00292/00156/00339
d D 4.5 81/02/16 20:58:41 wnj 5 4
c new strategy
e
s 00002/00001/00493
d D 4.4 81/02/15 20:31:43 wnj 4 3
c ubawatch timeout
e
s 00079/00076/00415
d D 4.3 81/02/15 12:09:58 kre 3 2
c bootable autoconf version
e
s 00170/00128/00321
d D 4.2 81/02/10 13:19:53 wnj 2 1
c compilable first uba autoconf version
e
s 00449/00000/00000
d D 4.1 81/02/08 18:39:41 wnj 1 0
c date and time created 81/02/08 18:39:41 by wnj
e
u
U
f b 
t
T
I 1
D 64
/*	%M%	%I%	%E%	*/
E 64
I 64
/*
D 71
 * Copyright (c) 1982 Regents of the University of California.
E 71
I 71
 * Copyright (c) 1982,1986 Regents of the University of California.
E 71
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 64

D 2
#define	dprintf printf
E 2
I 2
D 5
#define	dprintf	printf

E 5
E 2
/*
D 2
 * discover whatever we can about the machine we are running on
E 2
I 2
D 3
 * Configure the system for your own VAX.
 * Mostly used for distribution systems,
 * but parts of this run always.
E 3
I 3
D 20
 * Configure the system for the current machine.
E 20
I 20
D 24
 * Initialize the devices for the current machine.
E 24
I 24
 * Setup the system to run on the current machine.
 *
 * Configure() is called at boot time and initializes the uba and mba
 * device tables and the memory controller monitoring.  Available
 * devices are determined (from possibilities mentioned in ioconf.c),
 * and the drivers are initialized.
D 70
 *
 * N.B.: A lot of the conditionals based on processor type say
 *	#if VAX780
 * and
 *	#if VAX750
 * which may be incorrect after more processors are introduced if they
D 27
 * are like either of these machines.  Thus the exact form of these
 * lines may change.  Will future machines have configuration registers
 * in the adapters and probable nexus space (like the 780), or wired
 * addresses (like the 750)?  It remains to be seen.
E 27
I 27
 * are like either of these machines.
I 29
 *
 * TODO:
 *	use pcpu info about whether a ubasr exists
E 70
E 29
E 27
E 24
E 20
E 3
D 5
 *
 *	kre/wnj		Berkeley, February 1981
E 5
E 2
 */

I 15
#include "mba.h"
I 55
#include "uba.h"
I 97
D 106
#include "kra.h"		/* XXX wrong file */
E 106
I 106
#include "vaxbi.h"
I 109
#include "bva.h"
E 109
E 106
E 97
E 55

I 46
D 60
#include "../machine/pte.h"
E 60
I 60
D 87
D 88
#include "pte.h"
E 60

E 88
E 87
E 46
E 15
D 5
 /*** NOT DONE YET 
D 3
	- unibus map & bdp map setup
	- SCB setup (init mba intr vecs, uba intr vecs, & (750) uba dev vecs)
	  stray interrupt setup in scb
	- ctrlr, & slave routines in uba drivers (+ other fixups)
		(nb: the cntrlr routines must have no reg vars)
	- unibus intr vec setup
	- (probably) lots more wrt UBA's
E 3
I 3
	- stray interrupt setup in scb and uba vectors
E 3
	- 750 main loop
D 2
	- arrange permission to write SCB & give it back
E 2
I 2
D 3
	- arrange permission to write SCB & give it back  (KLUDGED)
E 3
I 3
	- write protect scb
E 3
E 2
	- set up dk fields in structs
D 3
	- make locore.s compatible (incl Scbbase -> _Scbbase)
E 3
  ***/

E 5
D 60
#include "../h/param.h"
D 2
#include "../h/ino.h"
#include "../h/inode.h"
E 2
I 2
#include "../h/systm.h"
E 2
#include "../h/map.h"
D 43
#include "../h/nexus.h"
E 43
D 46
#include "../h/pte.h"
E 46
#include "../h/buf.h"
D 23
#include "../h/mba.h"
E 23
I 23
D 43
#include "../h/mbareg.h"
#include "../h/mbavar.h"
E 43
E 23
I 8
#include "../h/dk.h"
#include "../h/vm.h"
I 48
#include "../h/conf.h"
#include "../h/dmap.h"
E 60
I 60
#include "param.h"
#include "systm.h"
#include "map.h"
#include "buf.h"
D 85
#include "dk.h"
E 85
I 85
#include "dkstat.h"
E 85
#include "vm.h"
I 90
#include "malloc.h"
E 90
#include "conf.h"
#include "dmap.h"
I 71
#include "reboot.h"
I 87
#ifdef SECSIZE
#include "file.h"
#include "ioctl.h"
#include "disklabel.h"
#endif SECSIZE
E 87
E 71
E 60
E 48
E 8
D 2
#include "../bert/uba.h"			/*** TEMPORARY ***/
E 2
I 2
D 23
#include "../h/uba.h"
E 23
I 23
D 43
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 23
E 2
#include "../h/mtpr.h"
#include "../h/cpu.h"
#include "../h/scb.h"
D 8
#include "../h/vmparam.h"
#include "../h/vmmac.h"
E 8
I 2
#include "../h/mem.h"
E 43
I 43

I 88
#include "pte.h"
E 88
I 87
#include "pte.h"
E 87
D 60
#include "../vax/cpu.h"
#include "../vax/mem.h"
#include "../vax/mtpr.h"
#include "../vax/nexus.h"
#include "../vax/scb.h"
E 60
I 60
#include "cpu.h"
#include "mem.h"
#include "mtpr.h"
#include "nexus.h"
#include "scb.h"
I 65
#include "ioa.h"
I 97
#include "../vaxbi/bireg.h"
I 106
#include "../vaxbi/bivar.h"
E 106
E 97
E 65
E 60
#include "../vaxmba/mbareg.h"
#include "../vaxmba/mbavar.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
I 109
#include "../babyvax/bvvar.h"
E 109
E 43
E 2

I 8
D 24
int	cold;
E 24
I 24
/*
 * The following several variables are related to
 * the configuration process, and are used in initializing
 * the machine.
 */
int	cold;		/* if 1, still working on cold-start */
E 24
E 8
D 3
int	mbanum;		/* counts MBA's as we see them */
D 2
#if	VAX==780 || VAX==ANY
int	ubanum;		/* same for UBA's */
#endif
int	memctl;		/* and memory controllers */
E 2
I 2
int	numuba;		/* same for UBA's */
E 3
E 2
D 83
int	nexnum;		/* current nexus number */
I 65
int	nsbi;		/* current sbi number */
E 83
E 65
I 8
D 24
int	dkn;		/* number of dk numbers assigned so far */
E 24
I 24
int	dkn;		/* number of iostat dk numbers assigned so far */
I 68
int	cpuspeed = 1;	/* relative cpu speed */
E 68
E 24
E 8

I 24
/*
 * Addresses of the (locore) routines which bootstrap us from
 * hardware traps to C code.  Filled into the system control block
 * as necessary.
I 97
 *
 * RIDICULOUS!  CONFIG SHOULD GENERATE AN ioconf.h FOR US, with
 * mba glue also in `glue.s'.  (Unibus adapter glue is special, though.)
E 97
 */
E 24
I 15
#if NMBA > 0
E 15
D 2
extern cpu;
struct	nexus *nxtemp();
extern struct scb Scbbase;
struct uba_regs *curuba;
extern struct pte Nexmap[16][16];
extern struct nexus nexus[16];
E 2
I 2
D 8
struct	uba_regs *curuba;
I 5

/*
 * Definitions for uba's and mba's.
 */

/*
 * Catcher is 1k bytes of memory where we write in stray
 * UNIBUS interrupt decoding code.
 */
E 5
E 2
D 3
int	catcher[129];
I 2
extern	caddr_t	umaddr[];
extern	struct pte UMEMmap[4][16];
extern	char	umem[4][16*128*512];
E 3
I 3
extern	int catcher[256];
I 5

/*
 * UMEMmap maps the UNIBUS memory for the portion accessible
 * as device registers and umem is the corresponding virtual space.
 */
E 5
extern	struct pte UMEMmap[MAXNUBA][16];
extern	char umem[MAXNUBA][16*NBPG];
E 3
E 2

D 2
extern	mba0int(), mba1int(), mba2int(), mba3int();
extern	ua0int(),  ua1int(),  ua2int(),  ua3int();
E 2
I 2
D 3
/* I somehow don't think this will work on a 750 */
E 3
D 5
#define	C (caddr_t)
E 5
I 5
/*
 * The umaddr* arrays give the physical addresses of the UNIBUS
 * register space.
 */
E 8
I 8
int	(*mbaintv[4])() =	{ Xmba0int, Xmba1int, Xmba2int, Xmba3int };
I 65
#if NMBA > 4
	Need to expand the table for more than 4 massbus adaptors
E 65
I 15
#endif
E 15
E 8
E 5
D 3
caddr_t	umaddr[4] = {
E 3
I 3
D 65
#if VAX780
I 8
int	(*ubaintv[4])() =	{ Xua0int, Xua1int, Xua2int, Xua3int };
E 65
I 24
D 27
/*
 * These are the (fixed) addresses of the (last 8k bytes of) unibus memory for
 * each of the 4 possible unibus adapters.  Note that the unibus memory
 * addresses are actually indexed by the unibus adapter type code,
 * and are unrelated to tr (nexus) number.
 */
E 24
E 8
caddr_t	umaddr780[4] = {
E 3
D 5
	C 0x2013e000, C 0x2017e000, C 0x201be000, C 0x201fe000
E 5
I 5
	(caddr_t) 0x2013e000, (caddr_t) 0x2017e000,
	(caddr_t) 0x201be000, (caddr_t) 0x201fe000
E 5
};
E 27
I 3
#endif
I 65
#if defined(VAX780) || defined(VAX8600)
int	(*ubaintv[])() =
{
	Xua0int, Xua1int, Xua2int, Xua3int,
#if NUBA > 4
	Xua4int, Xua5int, Xua6int, Xua7int,
#endif
#if NUBA > 8
	Need to expand the table for more than 8 unibus adaptors
#endif
};
#endif
I 97
D 106
#if NKDB > 0
/* kdb50 driver does not appear in udminit[] (not without csr!) */
int	Xkdbintr0();		/* generated by autoconf */
int	(*kdbintv[])() = { Xkdbintr0 };
#if NKDB > 1
	Need to expand the table for more than 1 KDB adapter
#endif
#endif
E 106
E 97
E 65
I 24

I 108
#if NUBA
E 108
/*
 * This allocates the space for the per-uba information,
 * such as buffered data path usage.
 */
E 24
I 23
D 59
struct	uba_hd uba_hd[MAXNUBA];
E 59
I 59
struct	uba_hd uba_hd[NUBA];
I 108
#else
/*
 * vaxuba/ubavar.h externs uba_hd and we use that header file even if we have
 * no UBAs.  The kludge below allows the kernel to build.
 */
struct	uba_hd uba_hd[1];
#endif
E 108
E 59
E 23
D 8
#if VAX750
caddr_t	umaddr750[1] = {
D 5
	C 0xffe000
E 5
I 5
	(caddr_t) 0xffe000
E 5
};
#endif
E 8
E 3
E 2

I 24
/*
D 27
 * The bits which decode the fault bits in the configuration register
 * of nexus's are reusable per nexus-type, so we declare them once here
 * to avoid replication.
 */
E 24
I 5
D 8
/*
 * The ?baintv arrays give the addresses of the UNIBUS and
 * MASSBUS interrupt handling routines.
 */
E 5
I 2
D 3
extern	Xmba0int(), Xmba1int(), Xmba2int(), Xmba3int();
extern	Xua0int(),  Xua1int(),  Xua2int(),  Xua3int();

E 2
int	(*mbaintv[4])() = {
D 2
	mba0int, mba1int, mba2int
#if	VAX==780 || VAX==ANY
	    , mba3int
E 2
I 2
	Xmba0int, Xmba1int, Xmba2int,
E 3
I 3
extern	Xmba0int(),	Xmba1int(),	Xmba2int(),	Xmba3int();
extern	Xua0int();
E 3
#if VAX780
D 3
				   Xmba3int
E 3
I 3
extern			Xua1int(),	Xua2int(),	Xua3int();
E 3
E 2
#endif
I 3

D 5
int	(*mbaintv[])() = {
E 5
I 5
int	(*mbaintv[4])() = {
E 5
	Xmba0int,	Xmba1int,	Xmba2int,	Xmba3int
E 3
};
D 5

D 2
#if	VAX==780 || VAX == ANY
E 2
I 2
D 3
#if VAX780
E 3
E 2
int	(*ubaintv[4])() = {
E 5
I 5
int	(*ubaintv[])() = {
E 5
D 2
	ua0int, ua1int, ua2int, ua3int
E 2
I 2
D 3
	Xua0int, Xua1int, Xua2int, Xua3int
E 3
I 3
#if VAX780
	Xua0int,	Xua1int,	Xua2int,	Xua3int
#endif
#if VAX750
	Xua0int
#endif
E 3
E 2
};

I 5
/*
 * UNIvec is permanently allocated in scb.s.  On an 750, it is
 * where the hardware sends the interrupts; on a 780 we use the
 * space for the first UNIBUS adaptor.
 */
E 5
extern	int	(*UNIvec[])();
D 3
#endif
E 3

I 2
D 5
int	c780();
int	c750();
int	c7ZZ();
D 3
int	c8ZZ();
E 3
I 3
int	c980();
E 5
I 5
/*
 * Structure per cpu type giving address of configuration routine
 */
E 8
D 15
int	c780(), c750();
E 15
I 15
#if VAX780
I 21
char	nexflt_bits[] = NEXFLT_BITS;
#endif

I 24
/*
 * Per-processor type initialization routines and data.
 * It would be nice to parameterize initialization more,
 * but the 780 and 750 are really quite different at this
 * level.  We await future machines before attempting 
 * any significant parameterization.
 */
E 24
#if VAX780
E 21
int	c780();
#endif
#if VAX750
int	c750();
#endif
E 15
E 5
E 3

struct percpu percpu[] = {
#if VAX780
D 3
	c780,	VAX_780,	4,	1,	4,
E 3
I 3
D 5
	c780,	VAX_780,	4,	4,	4,	umaddr780,
E 5
I 5
	c780, VAX_780,
E 5
E 3
#endif
#if VAX750
D 3
	c750,	VAX_750,	3,	0,	1,
E 3
I 3
D 5
	c750,	VAX_750,	3,	0,	1,	umaddr750,
E 5
I 5
	c750, VAX_750,
E 5
E 3
#endif
D 5
#if VAX7ZZ
D 3
	c7ZZ,	VAX_7ZZ,	0,	0,	1,
E 3
I 3
	c7ZZ,	VAX_7ZZ,	0,	0,	1,	umaddr7ZZ,
E 3
#endif
D 3
#if VAX8ZZ
	c8ZZ,	VAX_8ZZ,	4,	4,	4,
E 3
I 3
#if VAX980
	c980,	VAX_980,	4,	4,	4,	umaddr980,
E 3
#endif
E 5
};
#define	NCPU	(sizeof(percpu)/sizeof(struct percpu))

E 2
/*
E 27
 * Determine mass storage and memory configuration for a machine.
 * Get cpu type, and then switch out to machine specific procedures
 * which will probe adaptors to see what is out there.
 */
configure()
{
D 104
	union cpusid cpusid;
E 104
I 2
	register struct percpu *ocp;
I 3
D 5
	int catcher0 = catcher[0];
	int catcher1 = catcher[1];
E 5
D 11
	register int i;
E 11
I 11
D 25
	register int i, *ip;
E 25
I 25
D 97
	register int *ip;
E 97
I 97
	register struct pte *ip;
E 97
E 25
D 98
	extern char Sysbase[];
E 98
E 11
E 3
E 2

D 104
	cpusid.cpusid = mfpr(SID);
I 97
	switch (cpusid.cpuany.cp_type) {
E 104
I 104
	switch (cpu) {
E 104
#if VAX8600
	case VAX_8600:
		printf("VAX 8600, serial# %d(%d), hardware ECO level %d(%d)\n",
D 100
			cpusid.cpu780.cp_sno, cpusid.cpu780.cp_plant,
			cpusid.cpu780.cp_eco >> 4, cpusid.cpu780.cp_eco);
E 100
I 100
			cpusid.cpu8600.cp_sno, cpusid.cpu8600.cp_plant,
			cpusid.cpu8600.cp_eco >> 4, cpusid.cpu8600.cp_eco);
E 100
		break;
#endif
#if VAX8200
	case VAX_8200:
		printf("\
VAX 82%c0, hardware rev %d, ucode patch rev %d, sec patch %d, ucode rev %d\n",
			cpusid.cpu8200.cp_5 ? '5' : '0',
			cpusid.cpu8200.cp_hrev, cpusid.cpu8200.cp_patch,
			cpusid.cpu8200.cp_secp, cpusid.cpu8200.cp_urev);
		mastercpu = mfpr(BINID);
		break;
#endif
#if VAX780
	case VAX_780:
		printf("\
VAX 11/78%c, serial# %d(%d), hardware ECO level %d(%d)\n",
			cpusid.cpu780.cp_5 ? '5' : '0',
			cpusid.cpu780.cp_sno, cpusid.cpu780.cp_plant,
			cpusid.cpu780.cp_eco >> 4, cpusid.cpu780.cp_eco);
		break;
#endif
#if VAX750
	case VAX_750:
		printf("VAX 11/750, hardware rev %d, ucode rev %d\n",
			cpusid.cpu750.cp_hrev, cpusid.cpu750.cp_urev);
		break;
#endif
#if VAX730
	case VAX_730:
		printf("VAX 11/730, ucode rev %d\n", cpusid.cpu730.cp_urev);
		break;
#endif
D 104
#if VAX630
	case VAX_630:
		printf("MicroVAX-II\n");
		break;
#endif
I 99
#if VAX650
	case VAX_650:
		printf("MicroVAX 3000, ucode rev %d\n", cpusid.cpu650.cp_urev);
		break;
#endif
E 104
I 104
/* for other CPUs the cpu_init routines print the banners */
E 104
E 99
	}
E 97
D 2
	switch (cpusid.cpuany.cp_type) {

#if	VAX==780 || VAX==ANY
	case VAX_780: cpu = 780; c780(); break;
#endif
#if	VAX==750 || VAX==ANY
	case VAX_750: cpu = 750; c750(); break;
#endif

	default:
		printf("cpu type %d unsupported\n", cpusid.cpuany.cp_type);
		panic("config");
	}
E 2
I 2
D 27
	for (ocp = percpu; ocp < &percpu[NCPU]; ocp++)
E 27
I 27
	for (ocp = percpu; ocp->pc_cputype; ocp++)
E 27
D 104
		if (ocp->pc_cputype == cpusid.cpuany.cp_type) {
E 104
I 104
		if (ocp->pc_cputype == cpu) {
E 104
I 68
			cpuspeed = ocp->pc_cpuspeed;
I 97
			cpuops = ocp->pc_ops;
I 103
			cpu_has_compat_mode = ocp->pc_compatmode;
E 103
			if (cpuops->cpu_init != NULL)
				(*cpuops->cpu_init)();
E 97
E 68
D 13
			cpu = ocp->pc_cputype;
E 13
D 27
			(*ocp->pc_config)(ocp);
E 27
I 27
D 65
			probenexus(ocp);
E 65
I 65
D 70
			probeioa(ocp);
E 70
I 70
			probeio(ocp);
E 70
E 65
E 27
D 3
			/*** SET CATCHER FOR STRAY INTERRUPTS HERE ***/
			/*** NB: NOT VECTORS: JUST HANDLER CODE ***/
			panic("config done\n");
E 3
I 3
D 5
			for (i = 0; i < 256; i += 2) {
				catcher[i] = catcher0;
				catcher[i+1] = catcher1 - i*4;
E 5
I 5
D 8
			for (i = 2; i < 256; i += 2) {
				catcher[i] = catcher[0];
				catcher[i+1] = catcher[1] - i*4;
E 5
			}
E 8
D 5
#if VAXANY
			/*** SET CONFIGURATION ***/
E 5
I 5
D 11
#if GENERIC
E 11
I 11
D 12
#if VAX==ANY
E 12
I 12
D 24
#if VAXANY
E 12
E 11
			setconf();
E 5
#endif
E 24
I 24
			/*
D 51
			 * Write protect the scb.  It is strange
			 * that this code is here, but this is as soon
			 * as we are done mucking with it, and the
E 51
I 51
			 * Write protect the scb and UNIBUS interrupt vectors.
			 * It is strange that this code is here, but this is
			 * as soon as we are done mucking with it, and the
E 51
			 * write-enable was done in assembly language
			 * to which we will never return.
			 */
E 24
D 5
			asm("halt");
E 5
I 5
D 11
			/* WRITE PROTECT SCB */
E 11
I 11
D 54
			ip = (int *)Sysmap; *ip &= ~PG_PROT; *ip |= PG_KR;
E 54
I 54
D 97
			ip = (int *)Sysmap + 1; *ip &= ~PG_PROT; *ip |= PG_KR;
E 54
I 51
			ip++; *ip &= ~PG_PROT; *ip |= PG_KR;
#if NUBA > 1
			ip++; *ip &= ~PG_PROT; *ip |= PG_KR;
#endif
E 51
			mtpr(TBIS, Sysbase);
E 97
I 97
			for (ip = kvtopte(scb); ip < kvtopte(eUNIvec); ip++) {
				*(int *)ip &= ~PG_PROT;
				*(int *)ip |= PG_KR;
			}
			mtpr(TBIA, 0);
E 97
I 24
#if GENERIC
D 79
			setconf();
E 79
I 79
D 81
			if ((boothowto & RB_ASKNAME) || setroot() == 0)
				setconf();
E 81
I 81
			if ((boothowto & RB_ASKNAME) == 0)
				setroot();
			setconf();
E 81
#else
D 81
			(void) setroot();
E 81
I 81
			setroot();
E 81
E 79
I 71
D 73
#else
E 73
I 73
#endif
D 79
#if !GENERIC || lint
E 73
			setroot();
E 71
#endif
E 79
I 48
			/*
			 * Configure swap area and related system
			 * parameter based on device(s) used.
			 */
			swapconf();
E 48
E 24
E 11
I 8
			cold = 0;
I 20
			memenable();
E 20
E 8
E 5
E 3
			return;
		}
D 24
	printf("cpu type %d unsupported\n", cpusid.cpuany.cp_type);
E 24
I 24
D 104
	printf("cpu type %d not configured\n", cpusid.cpuany.cp_type);
E 104
I 104
D 105
	printf("cpu type 0x%x not configured\n", cpu);
E 105
I 105
	if (cpu)
		printf("cpu type %x not configured\n", cpu);
	else
		printf("cannot identify cpu, SID=%x SIE=%x\n", cpusid.cpusid,
			cpusie.cpusie);
E 105
E 104
E 24
E 2
	asm("halt");
}

I 83
#if VAX8600 || VAX780 || VAX750 || VAX730
int	nexnum;		/* current nexus number */
int	nsbi;		/* current sbi number */
#endif
I 97
D 106
#if VAX8200
int	numkdb;		/* current ``kdb'' number */
int	bi_nodes;	/* XXX remembers found bi nodes */
#endif
E 106
E 97

E 83
I 65
D 70
probeioa(pcpu)
register struct percpu *pcpu;
E 70
I 70
/*
 * Probe the main IO bus(es).
 * The percpu structure gives us a handle on the addresses and/or types.
 */
probeio(pcpu)
	register struct percpu *pcpu;
E 70
{
D 70
	register struct ioa *ioap;
	struct sbia_regs *sbiaregs;
	caddr_t ioa_paddr;
	union ioacsr ioacsr;
	int type;
E 70
I 70
	register struct iobus *iob;
E 70
	int ioanum;

	ioanum = 0;
D 70
	ioap = ioa;
	for (;ioanum < pcpu->pc_nioa; ioanum++,
	    ioap = (struct ioa *)((caddr_t)ioap + pcpu->pc_ioasize)) {
		if (pcpu->pc_ioaaddr) {
			ioa_paddr = pcpu->pc_ioaaddr[ioanum];
			nxaccess(ioa_paddr, Ioamap[ioanum], pcpu->pc_ioasize);
			if (badaddr(ioap, 4))
				continue;
			if (pcpu->pc_ioatype)
				type = (int)pcpu->pc_ioatype[ioanum];
			else {
				ioacsr.ioa_csr = ioap->ioacsr.ioa_csr;
				type = ioacsr.ioa_type & IOA_TYPMSK;
			}
		} else
			type = (int)pcpu->pc_ioatype[ioanum];
		switch (type) {
#if VAX780
		case IOA_SBI780:
			probesbi(&sbi780);
E 70
I 70
	for (iob = pcpu->pc_io; ioanum < pcpu->pc_nioa; ioanum++, iob++) {

		switch (iob->io_type) {

D 78
#if VAX780 || VAX750 || VAX730
E 78
I 78
D 83
#if VAX780 || VAX750 || VAX730 || VAX630
E 83
I 83
D 99
#if VAX630
E 99
I 99
#if VAX630 || VAX650
E 99
		case IO_QBUS:
			probeqbus((struct qbus *)iob->io_details);
			break;
#endif

#if VAX780 || VAX750 || VAX730
E 83
E 78
		case IO_SBI780:
		case IO_CMI750:
		case IO_XXX730:
I 78
D 83
		case IO_QBUS:
E 83
E 78
			probenexi((struct nexusconnect *)iob->io_details);
E 70
			break;
#endif
D 70
#if VAX750
		case IOA_CMI750:
			probesbi(&cmi750);
			break;
#endif
#if VAX730
		case IOA_XXX730:
			probesbi(&xxx730);
			break;
#endif
E 70
I 70

E 70
#if VAX8600
D 70
		case IOA_SBIA:
			printf("SBIA%d at IO adaptor %d address 0x%x\n",
			    nsbi, ioanum, ioa_paddr);
			probesbi(&sbi8600[nsbi]);
			nsbi++;
			sbiaregs = (struct sbia_regs *)ioap;
			sbiaregs->sbi_errsum = -1;
			sbiaregs->sbi_error = 0x1000;
			sbiaregs->sbi_fltsts = 0xc0000;
E 70
I 70
		case IO_ABUS:
			probe_Abus(ioanum, iob);
E 70
			break;
#endif
I 97

#if VAX8200
		case IO_BI:
D 106
			probe_bi((struct bibus *)iob->io_details);
E 106
I 106
			probe_bi((int)iob->io_details);
E 106
			break;
#endif

I 109
#if NBVA
		case IO_BABYVAX:
			probe_babyvax();
			break;
#endif

E 109
E 97
		default:
D 70
			if (pcpu->pc_ioaaddr) {
				printf(
			"IOA%d at address 0x%x is unsupported (type = 0x%x)\n",
				    ioanum, ioa_paddr, ioacsr.ioa_type);
E 70
I 70
			if (iob->io_addr) {
			    printf(
		"IO adaptor %d, type %d, at address 0x%x is unsupported\n",
				ioanum, iob->io_type, iob->io_addr);
E 70
			} else
D 70
				printf("IOA%d type 0x%x unknown\n", ioanum,
					type);
E 70
I 70
			    printf("IO adaptor %d, type %d, is unsupported\n",
				ioanum, iob->io_type);
			break;
E 70
		}
	}
}

I 70
#if VAX8600
probe_Abus(ioanum, iob)
	register struct iobus *iob;
{
	register struct ioa *ioap;
	union ioacsr ioacsr;
	int type;
	struct sbia_regs *sbiaregs;
I 97
#ifdef notyet
	int sbi1fail(), sbi1alert(), sbi1fault(), sbi1err();
#endif
E 97

	ioap = &ioa[ioanum];
D 76
	nxaccess(iob->io_addr, Ioamap[ioanum], iob->io_size);
E 76
I 76
	ioaccess(iob->io_addr, Ioamap[ioanum], iob->io_size);
E 76
	if (badaddr((caddr_t)ioap, 4))
		return;
	ioacsr.ioa_csr = ioap->ioacsr.ioa_csr;
	type = ioacsr.ioa_type & IOA_TYPMSK;

	switch (type) {

	case IOA_SBIA:
		printf("SBIA%d at IO adaptor %d address 0x%x\n",
		    nsbi, ioanum, iob->io_addr);
I 97
#ifdef notyet
		/* I AM NOT SURE THESE ARE IN THE SAME PLACES */
		if (nscb == 1) {
			scb[1].scb_sbifail = scbentry(sbi1fail, SCB_ISTACK);
			/* maybe not sbifail, maybe scb1.scb_cmrd */
			/* but how can I find out without a broken SBIA1? */
			scb[1].scb_sbialert = scbentry(sbi1alert, SCB_ISTACK);
			scb[1].scb_sbifault = scbentry(sbi1fault, SCB_ISTACK);
			scb[1].scb_sbierr = scbentry(sbi1err, SCB_ISTACK);
		}
#endif
E 97
		probenexi((struct nexusconnect *)iob->io_details);
		nsbi++;
		sbiaregs = (struct sbia_regs *)ioap;
		sbiaregs->sbi_errsum = -1;
		sbiaregs->sbi_error = 0x1000;
		sbiaregs->sbi_fltsts = 0xc0000;
		break;

	default:
		printf("IOA%d at address 0x%x is unsupported (type = 0x%x)\n",
		    ioanum, iob->io_addr, ioacsr.ioa_type);
		break;
	}
}
#endif

I 83
#if VAX8600 || VAX780 || VAX750 || VAX730
E 83
E 70
E 65
D 2
#if	VAX==750 || VAX==ANY
c750()
E 2
I 2
D 5
#if VAX750
c750(ocp)
	register struct percpu *ocp;
E 2
{
	printf("not yet, sad to say\n");
	asm("halt");
}
#endif

E 5
D 2
#if	VAX==780 || VAX==ANY
E 2
I 2
D 27
#if VAX780
E 27
E 2
/*
D 27
 * Build configuration table for a 780, by looking
 * at the things (mbas and ubas) in the nexus slots
 * and initialzing each appropriately.
E 27
I 27
 * Probe nexus space, finding the interconnects
 * and setting up and probing mba's and uba's for devices.
E 27
 */
I 25
D 97
/*ARGSUSED*/
E 97
E 25
D 2
c780()
E 2
I 2
D 27
c780(pcpu)
E 27
I 27
D 65
probenexus(pcpu)
E 27
	register struct percpu *pcpu;
E 65
I 65
D 70
probesbi(psbi)
	register struct persbi *psbi;
E 70
I 70
probenexi(pnc)
	register struct nexusconnect *pnc;
E 70
E 65
E 2
{
	register struct nexus *nxv;
I 3
D 25
	register struct uba_hd *uhp;
E 25
E 3
D 5
	struct nexus *nxp = NEXBASE;
E 5
I 5
D 27
	struct nexus *nxp = NEX780;
E 27
I 27
D 65
	struct nexus *nxp = pcpu->pc_nexbase;
E 65
I 65
D 70
	struct nexus *nxp = psbi->psb_nexbase;
E 70
I 70
	struct nexus *nxp = pnc->psb_nexbase;
E 70
E 65
E 27
E 5
	union nexcsr nexcsr;
D 4
	int i;
E 4
I 4
D 28
	int i, ubawatch();
E 28
I 28
	int i;
E 28
E 4
D 97
	
D 5
	for (nexnum = 0, nxv = nexus; nexnum < NNEXUS; nexnum++, nxp++, nxv++) {
E 5
I 5
D 27
	for (nexnum = 0,nxv = nexus; nexnum < NNEX780; nexnum++,nxp++,nxv++) {
E 27
I 27
D 69
	nexnum = 0, nxv = nexus;
E 69
I 69
D 76
	nexnum = 0, nxv = &nexus[nsbi * 16];
E 76
I 76
D 77
	nexnum = 0, nxv = &nexus[nsbi * NNEX8600];
E 77
I 77
	nexnum = 0, nxv = &nexus[nsbi * NNEXSBI];
E 77
E 76
E 69
D 65
	for (; nexnum < pcpu->pc_nnexus; nexnum++, nxp++, nxv++) {
E 27
E 5
D 25
		nxaccess((caddr_t)nxp, Nexmap[nexnum]);
E 25
I 25
		nxaccess(nxp, Nexmap[nexnum]);
E 65
I 65
D 70
	for (; nexnum < psbi->psb_nnexus; nexnum++, nxp++, nxv++) {
E 70
I 70
	for (; nexnum < pnc->psb_nnexus; nexnum++, nxp++, nxv++) {
E 70
D 76
			/*
			 * the 16 below shouldn't be there, but the constant
D 69
			 * is used at other points (vax/Locore.c)
E 69
I 69
			 * is used at other points (vax/locore.s)
E 69
			 */
D 70
		nxaccess(nxp, Nexmap[nsbi * 16 + nexnum], sizeof(struct nexus));
E 70
I 70
		nxaccess((caddr_t)nxp, Nexmap[nsbi * 16 + nexnum],
E 76
I 76
D 77
		ioaccess((caddr_t)nxp, Nexmap[nsbi * 16 + nexnum],
E 77
I 77
		ioaccess((caddr_t)nxp, Nexmap[nsbi * NNEXSBI + nexnum],
E 77
E 76
		     sizeof(struct nexus));
E 97
I 97

	ioaccess((caddr_t)nxp, Nexmap[nsbi * NNEXSBI],
	    pnc->psb_nnexus * sizeof(struct nexus));
	nxv = &nexus[nsbi * NNEXSBI];
	for (nexnum = 0; nexnum < pnc->psb_nnexus; nexnum++, nxp++, nxv++) {
E 97
E 70
E 65
E 25
		if (badaddr((caddr_t)nxv, 4))
			continue;
D 27
		nexcsr = nxv->nexcsr;
E 27
I 27
D 65
		if (pcpu->pc_nextype && pcpu->pc_nextype[nexnum] != NEX_ANY)
			nexcsr.nex_csr = pcpu->pc_nextype[nexnum];
E 65
I 65
D 70
		if (psbi->psb_nextype && psbi->psb_nextype[nexnum] != NEX_ANY)
			nexcsr.nex_csr = psbi->psb_nextype[nexnum];
E 70
I 70
		if (pnc->psb_nextype && pnc->psb_nextype[nexnum] != NEX_ANY)
			nexcsr.nex_csr = pnc->psb_nextype[nexnum];
E 70
E 65
		else
			nexcsr = nxv->nexcsr;
E 27
		if (nexcsr.nex_csr&NEX_APD)
			continue;
D 2
		dprintf("nexus %d\n", nexnum);
E 2
		switch (nexcsr.nex_type) {

		case NEX_MBA:
I 15
D 24
#if NMBA > 0
E 24
E 15
D 2
			mba_hd[mbanum].mh_mba = (struct mba_regs *)nxv;
			mba_hd[mbanum].mh_physmba = (struct mba_regs *)nxp;
			mbafind(nxv);
			setscbnex(nexnum, mbaintv[mbanum]);
			((struct mba_regs *)nxv)->mba_cr = MBAINIT;
			((struct mba_regs *)nxv)->mba_cr = MBAIE;
E 2
I 2
D 3
			if (mbanum >= pcpu->pc_maxmba) {
E 3
I 3
D 5
			if (nummba >= pcpu->pc_maxmba) {
E 3
				printf("%d mba's", pcpu->pc_maxmba+1);
E 5
I 5
D 16
			if (nummba >= 4) {
				printf("5 mba's");
E 5
				goto unsupp;
			}
E 16
I 8
			printf("mba%d at tr%d\n", nummba, nexnum);
I 16
			if (nummba >= NMBA) {
D 24
				printf("%d mba's not configured\n", nummba+1);
				continue;
E 24
I 24
D 59
				printf("%d mba's", nummba);
E 59
I 59
D 97
				printf("%d mba's", nummba++);
E 97
I 97
				printf("%d mba's", ++nummba);
E 97
E 59
D 25
				goto notconfig;
E 25
I 25
				goto unconfig;
E 25
E 24
			}
I 24
#if NMBA > 0
E 24
E 16
E 8
			mbafind(nxv, nxp);
E 2
D 3
			mbanum++;
E 3
I 3
			nummba++;
I 18
D 24
			break;
E 18
E 3
D 15
			break;
E 15
I 15
#else
			printf("mba's");
			goto unsupp;
E 24
#endif
I 24
			break;
E 24
E 15

		case NEX_UBA0:
		case NEX_UBA1:
		case NEX_UBA2:
		case NEX_UBA3:
I 24
			printf("uba%d at tr%d\n", numuba, nexnum);
I 97
			if (numuba >= NUBA) {
				printf("%d uba's", ++numuba);
				goto unconfig;
			}
#if NUBA > 0
E 97
E 24
D 2
			uba_hd[ubanum].uh_uba = (struct uba_regs *)nxv;
			uba_hd[ubanum].uh_physuba = (struct uba_regs *)nxp;
			ubafind(nxv, nexcsr.nex_type - NEX_UBA0);
			setscbnex(nexnum, ubaintv[ubanum]);
			if (ubanum == 0)
E 2
I 2
D 5
			if (numuba >= pcpu->pc_maxuba) {
				printf("%d uba's", pcpu->pc_maxuba+1);
E 5
I 5
D 59
			if (numuba >= 4) {
				printf("5 uba's");
E 59
I 59
D 61
#if VAX_750
E 61
I 61
#if VAX750
E 61
			if (numuba >= 2 && cpu == VAX_750) {
				printf("More than 2 UBA's");
E 59
E 5
				goto unsupp;
			}
I 59
#endif
D 97
			if (numuba >= NUBA) {
D 65
				printf("%d uba's", numuba++);
E 65
I 65
				printf("%d uba's", ++numuba);
E 65
				goto unconfig;
			}
E 97
E 59
I 8
D 24
			printf("uba%d at tr%d\n", numuba, nexnum);
E 24
D 25
			setscbnex(nexnum, ubaintv[numuba]);
E 25
I 25
D 28
			setscbnex(ubaintv[numuba]);
E 28
I 28
D 65
#if VAX780
			if (cpu == VAX_780)
E 65
I 65
#if defined(VAX780) || defined(VAX8600)
D 97
			if ((cpu == VAX_780) || (cpu == VAX_8600))
E 97
I 97
			if (cpu == VAX_780 || cpu == VAX_8600)
E 97
E 65
				setscbnex(ubaintv[numuba]);
#endif
E 28
E 25
E 8
D 3
			uba_hd[numuba].uh_bdpfree = 0x7fff;	/* 15 bdp's */
			uba_hd[numuba].uh_uba = (struct uba_regs *)nxv;
			uba_hd[numuba].uh_physuba = (struct uba_regs *)nxp;
E 3
I 3
D 5
			/* THIS BELONGS IN unifind() */
			uhp = &uba_hd[numuba];
			mfree(uhp->uh_map, NUBMREG, 1);
			uhp->uh_bdpfree = 0x7fff;	/* 15 bdp's */
			uhp->uh_uba = (struct uba_regs *)nxv;
			uhp->uh_physuba = (struct uba_regs *)nxp;
E 3
			if (numuba == 0)
E 2
D 3
				uba_hd[0].uh_vec = UNIvec;
D 2
#ifdef	notyet
E 2
			else {
D 2
				uba_hd[ubanum].uh_vec =
				    (int (**)())memall(NBPG);	/*?????*/
		/*** FILL IN uh_vec with something useful !!! */
E 2
I 2
				/** WE JUST KNOW THIS WON'T HAPPEN **/
				uba_hd[numuba].uh_vec = 0;
				/* mapinit() */
E 2
			}
E 3
I 3
				uhp->uh_vec = UNIvec;
			else
				uhp->uh_vec = (int(**)())calloc(512);
			for (i = 0; i < 128; i++)
				uhp->uh_vec[i] =
				    scbentry(&catcher[i*2], SCB_ISTACK);
E 5
E 3
D 2
			mapinit(/* some parameters I suppose*/);
#endif
			ubanum++;
E 2
I 2
			i = nexcsr.nex_type - NEX_UBA0;
D 3
			nxaccess(umaddr[i], UMEMmap[numuba]);
			unifind((struct uba_regs *)nxv, umaddr[i], umem[i]);
E 3
I 3
D 5
			nxaccess(pcpu->pc_umaddr[i], UMEMmap[numuba]);
			unifind((struct uba_regs *)nxv, pcpu->pc_umaddr[i],
			    umem[i]);
			ubainit((struct uba_regs *)nxv);
			/* END OF CODE WHICH BELONGS IN unifind() */
E 5
I 5
D 83
			unifind((struct uba_regs *)nxv, (struct uba_regs *)nxp,
D 27
			    umem[i], umaddr780[i]);
E 5
E 3
D 8
			setscbnex(nexnum, ubaintv[numuba]);
E 8
I 5
			((struct uba_regs *)nxv)->uba_cr =
D 23
			    UBA_IFS|UBA_BRIE|UBA_USEFIE|UBA_SUEFIE;
E 23
I 23
			    UBACR_IFS|UBACR_BRIE|UBACR_USEFIE|UBACR_SUEFIE;
E 27
I 27
D 32
			    umem[i], pcpu->pc_umaddr[i]);
E 32
I 32
D 65
			    umem[i], pcpu->pc_umaddr[i], UMEMmap[i]);
E 32
I 28
#if VAX780
E 28
			if (cpu == VAX_780)
E 65
I 65
D 70
			    umem[numuba], psbi->psb_umaddr[i], UMEMmap[numuba],
			    psbi->psb_haveubasr);
E 70
I 70
			    umem[numuba], pnc->psb_umaddr[i], UMEMmap[numuba],
			    pnc->psb_haveubasr);
E 70
#if defined(VAX780) || defined(VAX8600)
			if ((cpu == VAX_780) || (cpu == VAX_8600))
E 65
				((struct uba_regs *)nxv)->uba_cr =
				    UBACR_IFS|UBACR_BRIE|
D 42
				    UBACR_USEFIE|UBACR_SUEFIE;
E 42
I 42
				    UBACR_USEFIE|UBACR_SUEFIE|
				    (((struct uba_regs *)nxv)->uba_cr&0x7c000000);
E 42
I 28
#endif
E 28
E 27
E 23
E 5
			numuba++;
E 83
I 83
			probeuba((struct uba_regs *)nxv, (struct uba_regs *)nxp,
			    pnc->psb_umaddr[i]);
I 97
#endif /* NUBA */
E 97
E 83
E 2
			break;

		case NEX_DR32:
I 3
		/* there can be more than one... are there other codes??? */
E 3
			printf("dr32");
			goto unsupp;

		case NEX_MEM4:
		case NEX_MEM4I:
		case NEX_MEM16:
		case NEX_MEM16I:
I 56
			printf("mcr%d at tr%d\n", nmcr, nexnum);
D 97
			if (nmcr >= 4) {
				printf("5 mcr's");
				goto unsupp;
E 97
I 97
			if (nmcr >= MAXNMCR) {
				printf("%d mcr's", ++nmcr);
				goto unconfig;
E 97
			}
			switch (cpu) {
I 97
#if VAX780
E 97
			case VAX_780:
I 97
				/* only ka780 code looks at type */
E 97
				mcrtype[nmcr] = M780C;
				break;
D 97
			case VAX_750:
				mcrtype[nmcr] = M750;
E 97
I 97
#endif
			default:
E 97
				break;
D 97
			case VAX_730:
				mcrtype[nmcr] = M730;
				break;
E 97
			}
D 97
			mcraddr[nmcr++] = (struct mcr *)nxv;
E 97
I 97
			mcraddr[nmcr++] = (caddr_t)nxv;
E 97
			break;

I 97
#if VAX780
E 97
		case NEX_MEM64I:
E 56
I 51
		case NEX_MEM64L:
		case NEX_MEM64LI:
I 67
		case NEX_MEM256I:
		case NEX_MEM256L:
		case NEX_MEM256LI:
E 67
I 56
			printf("mcr%d (el) at tr%d\n", nmcr, nexnum);
D 97
			if (nmcr >= 4) {
				printf("5 mcr's");
				goto unsupp;
E 97
I 97
			if (nmcr >= MAXNMCR) {
				printf("%d mcr's", ++nmcr);
				goto unconfig;
E 97
			}
D 97
			if (cpu == VAX_780)
				mcrtype[nmcr] = M780EL;
			mcraddr[nmcr++] = (struct mcr *)nxv;
E 97
I 97
			mcrtype[nmcr] = M780EL;
			mcraddr[nmcr++] = (caddr_t)nxv;
E 97
D 67
			if (nexcsr.nex_type != NEX_MEM64I)
E 67
I 67
			if (nexcsr.nex_type != NEX_MEM64I && 
D 97
			  nexcsr.nex_type != NEX_MEM256I)
E 97
I 97
			    nexcsr.nex_type != NEX_MEM256I)
E 97
E 67
				break;
			/* fall into ... */

E 56
		case NEX_MEM64U:
		case NEX_MEM64UI:
I 67
		case NEX_MEM256U:
		case NEX_MEM256UI:
E 67
D 56
		case NEX_MEM64I:
E 51
I 24
			printf("mcr%d at tr%d\n", nmcr, nexnum);
E 56
I 56
			printf("mcr%d (eu) at tr%d\n", nmcr, nexnum);
E 56
E 24
D 2
				/* What is memfind supposed to do ???? */
#ifdef	notyet
			memfind(memctl++);
#endif
E 2
I 2
D 5
			if (nmcr >= pcpu->pc_maxmcr) {
				printf("%d mcr's", pcpu->pc_maxmcr+1);
E 5
I 5
D 97
			if (nmcr >= 4) {
D 24
				printf("%d mcr's", 4);
E 24
I 24
				printf("5 mcr's");
E 24
E 5
				goto unsupp;
E 97
I 97
			if (nmcr >= MAXNMCR) {
				printf("%d mcr's", ++nmcr);
				goto unconfig;
E 97
			}
I 56
D 97
			if (cpu == VAX_780)
				mcrtype[nmcr] = M780EU;
E 56
I 11
D 24
			printf("mcr%d at tr%d\n", nmcr, nexnum);
E 24
E 11
			mcraddr[nmcr++] = (struct mcr *)nxv;
E 97
I 97
			mcrtype[nmcr] = M780EU;
			mcraddr[nmcr++] = (caddr_t)nxv;
E 97
E 2
			break;
I 97
#endif
E 97

		case NEX_MPM0:
		case NEX_MPM1:
		case NEX_MPM2:
		case NEX_MPM3:
			printf("mpm");
			goto unsupp;

I 51
		case NEX_CI:
			printf("ci");
			goto unsupp;

E 51
		default:
			printf("nexus type %x", nexcsr.nex_type);
D 5
    unsupp:
E 5
I 5
unsupp:
E 5
D 2
			printf(" at tr %d unsupported\n", nexnum);
E 2
I 2
			printf(" unsupported (at tr %d)\n", nexnum);
E 2
			continue;
I 24
unconfig:
			printf(" not configured\n");
			continue;
E 24
		}
	}
I 59
	if (nummba > NMBA)
		nummba = NMBA;
	if (numuba > NUBA)
		numuba = NUBA;
I 97
	if (nmcr > MAXNMCR)
		nmcr = MAXNMCR;
E 97
E 59
I 4
D 17
	timeout(ubawatch, 0, HZ);
E 17
I 17
D 25
	timeout(ubawatch, 0, hz);
E 25
I 25
D 28
	timeout(ubawatch, (caddr_t)0, hz);
E 28
I 28
D 44
#if VAX780
D 29
	{ int ubawatch(); timeout(ubawatch, (caddr_t)0, hz); }
E 29
I 29
	if (cpu == VAX_780)
		{ int ubawatch(); timeout(ubawatch, (caddr_t)0, hz); }
E 29
#endif
E 44
E 28
E 25
E 17
E 4
}
D 27
#endif

I 5
#if VAX750
E 5
/*
I 5
 * Configure a 750.  There are four possible mba's,
 * one standard UNIBUS, and a memory controller.
 */
c750(pcpu)
	struct percpu *pcpu;
{
	register struct nexus *nxv = nexus;
	struct nexus *nxp = NEX750;

I 11
	printf("mcr at %x\n", MCR_750);
D 25
	nxaccess((caddr_t)MCR_750, Nexmap[nexnum]);
E 25
I 25
	nxaccess((struct nexus *)MCR_750, Nexmap[nexnum]);
E 25
D 15
	mcraddr[nmcr++] = nxv;
E 15
I 15
	mcraddr[nmcr++] = (struct mcr *)nxv;
D 24
#if NMBA > 0
E 24
E 15
E 11
	for (nexnum = 0; nexnum < NNEX750; nexnum++, nxp++, nxv++) {
D 25
		nxaccess((caddr_t)nxp, Nexmap[nexnum]);
E 25
I 25
		nxaccess(nxp, Nexmap[nexnum]);
E 25
		if (badaddr((caddr_t)nxv, 4))
			continue;
I 11
		printf("mba%d at %x\n", nummba, nxp);
E 11
D 16
		mbafind(nxv, nxp);
		nummba++;
E 16
I 16
D 24
		if (nummba >= NMBA)
			printf("%d mba's not configured\n", nummba+1);
		else {
			mbafind(nxv, nxp);
			nummba++;
E 24
I 24
		if (nummba >= NMBA) {
			printf("%d mba(s) not configured\n", nummba+1);
			continue;
E 24
		}
E 16
D 24
	}
E 24
I 24
#if NMBA > 0
		mbafind(nxv, nxp);
		nummba++;
E 24
I 15
#endif
I 24
	}
E 24
E 15
I 11
	printf("uba at %x\n", nxp);
E 11
D 25
	nxaccess((caddr_t)nxp, Nexmap[nexnum++]);
E 25
I 25
	nxaccess(nxp, Nexmap[nexnum++]);
E 25
D 24
	unifind((struct uba_regs *)nxv++, (struct uba_regs *)nxp,
E 24
I 24
	unifind((struct uba_regs *)nxv, (struct uba_regs *)nxp,
E 24
D 8
	    umem[0], umaddr750[0]);
E 8
I 8
	    umem[0], UMEM750);
E 8
	numuba = 1;
D 11
	nxaccess((caddr_t)MCR_750, Nexmap[nexnum]);
	mcraddr[nmcr++] = nxv;
E 11
}
#endif
E 27

I 83
setscbnex(fn)
	int (*fn)();
{
D 97
	register struct scb *scbp = &scb;
E 97
I 97
	register struct scb *scbp = &scb[nsbi];
E 97

D 97
	scbp = (struct scb *)((caddr_t)scbp + nsbi * 512);
E 97
	scbp->scb_ipl14[nexnum] = scbp->scb_ipl15[nexnum] =
	    scbp->scb_ipl16[nexnum] = scbp->scb_ipl17[nexnum] =
		scbentry(fn, SCB_ISTACK);
}
#endif

I 97
D 106
#include "bi.h"
#if NBI > 0
E 106
I 106
#if NVAXBI > 0
E 106
/*
 * Probe BI node space.
 *
D 106
 * THIS DEPENDS ON BI SPACE == NEXUS SPACE
 * THIS WILL NOT WORK FOR MULTIPLE BIs
E 106
I 106
 * We map VAXBI nodespace using Nexmap, treating vaxbi<m> node n as nexus
 * m*16+n.  This works as long as all nexus buses are BIs, but we'll probably
 * need to use more complex mapping when we start supporting XMI.
E 106
 */
D 106
probe_bi(p)
	register struct bibus *p;
E 106
I 106
probe_bi(binum)
	register int binum;
E 106
{
	register struct bi_node *biv, *bip;
	register int node;
	short dtype;
I 106
	register struct bi_devtab *bidt;
E 106

	/* must ignore BI errors while configuring */
D 106
	bip = p->pbi_base;
	ioaccess((caddr_t)bip, Nexmap[0], sizeof(*bip) * NNODEBI);/* XXX */
	printf("vaxbi0 at address 0x%x\n", bip);
	biv = (struct bi_node *) &nexus[0];	/* XXX */
E 106
I 106
	bip = BI_BASE(binum);
	ioaccess((caddr_t)bip, Nexmap[binum*NNODEBI], sizeof(*bip) * NNODEBI);
	printf("vaxbi%d at address 0x%x\n", binum, bip);
	biv = (struct bi_node *) &nexus[binum*NNODEBI];
E 106
	for (node = 0; node < NNODEBI; node++, bip++, biv++) {
		if (badaddr((caddr_t)biv, 4))
			continue;
D 106
		bi_nodes |= 1 << node;		/* XXX */
E 106
		dtype = biv->biic.bi_dtype;
		/* clear bus errors */
		biv->biic.bi_ber = ~(BIBER_MBZ|BIBER_NMR|BIBER_UPEN);
		switch (dtype) {

		case BIDT_KA820: {
			/* is this right?? */
			int cp5 = biv->biic.bi_revs & 0x8000 ? '5' : '0';

			if (node != mastercpu) {
				printf("slave ka82%c cpu", cp5);
				goto unsupp;
			}
			printf("ka82%c cpu at node %x\n", cp5, node);
			biv->biic.bi_intrdes = 1 << mastercpu;
			biv->biic.bi_csr |= BICSR_SEIE | BICSR_HEIE;
			break;
		}

		case BIDT_DWBUA:
I 102
		case BIDT_KLESI:
E 102
D 106
			if (numuba >= NUBA || /*XXX*/numuba > 2) {
E 106
I 106
			if (numuba >= NUBA) {
E 106
				printf("%d uba's", ++numuba);
				goto unconfig;
			}
#if NUBA > 0
			printf("uba%d at node %x\n", numuba, node);

			/*
			 * Run a self test reset to drop any `old' errors,
			 * so that they cannot cause a BI bus error.
			 */
			(void) bi_selftest(&biv->biic);

			/*
			 * Enable interrupts.  DWBUAs must have
			 * high priority.
			 */
			biv->biic.bi_intrdes = 1 << mastercpu;
			biv->biic.bi_csr = (biv->biic.bi_csr&~BICSR_ARB_MASK) |
				BICSR_ARB_HIGH;
			probeuba((struct uba_regs *)biv, (struct uba_regs *)bip,
				(caddr_t)UMEM8200(node));
#endif /* NUBA */
			break;

		case BIDT_MS820:
			printf("mcr%d at node %x\n", nmcr, node);
			if (nmcr >= MAXNMCR) {
				printf("%d mcr's", ++nmcr);
				goto unconfig;
			}
			mcraddr[nmcr++] = (caddr_t)biv;
			biv->biic.bi_intrdes = 1 << mastercpu;
			biv->biic.bi_csr |= BICSR_SEIE | BICSR_HEIE;
			break;

D 106
		case BIDT_KDB50:
			if (numkdb >= NKDB) {
				printf("%d kdb's", ++numkdb);
				goto unconfig;
			}
#if NKDB > 0
			printf("kdb%d at node %x\n", numkdb, node);
			kdbconfig(numkdb, (struct biiregs *)biv,
				(struct biiregs *)bip,
				(int)&scb[0].scb_ipl15[node] - (int)&scb[0]);
			scb[0].scb_ipl15[node] =
				scbentry(kdbintv[numkdb], SCB_ISTACK);
			kdbfind(numkdb);
#endif
			numkdb++;
			break;

E 106
		case BIDT_DEBNA:
		case BIDT_DEBNK:
			printf("debna/debnk ethernet");
			goto unsupp;

		default:
D 106
			printf("node type 0x%x ", dtype);
E 106
I 106
			for (bidt = bi_devtab; bidt->bidt_driver; bidt++)
				if (bidt->bidt_dtype == dtype)
					break;
			if (!bidt->bidt_driver) {
				printf("node type 0x%x ", dtype);
				goto unsupp;
			}
			if (bidt->bidt_isctlr) {
				if (pnexus_match_ctlr(bidt->bidt_driver,
						NEXCLASS_VAXBI, binum, node)) {
			printf("%s at vaxbi%d node %d not configured\n",
				bidt->bidt_driver->ud_mname, binum, node);
					continue;
				}
				break;
			} else {
				if (pnexus_match_device(bidt->bidt_driver,
						NEXCLASS_VAXBI, binum, node)) {
			printf("%s at vaxbi%d node %d not configured\n",
				bidt->bidt_driver->ud_dname, binum, node);
					continue;
				}
				break;
			}

E 106
unsupp:
			printf(" unsupported (at node %x)\n", node);
D 106
			break;
E 106
I 106
			continue;
E 106
unconfig:
			printf(" not configured (at node %x)\n", node);
			continue;
		}
#ifdef DO_EINTRCSR
		biv->biic.bi_eintrcsr = BIEIC_IPL17 |
			(int)&scb[0].scb_bierr - (int)&scb[0];
		/* but bi reset will need to restore this */
#endif
	}
	if (numuba > NUBA)
		numuba = NUBA;
D 106
	if (numkdb > NKDB)
		numkdb = NKDB;
E 106
	if (nmcr > MAXNMCR)
		nmcr = MAXNMCR;
}
I 106
#endif /* NVAXBI > 0 */
E 106

D 106
#if NKDB > 0
/*
 * Find drives attached to a particular KDB50.
 */
kdbfind(kdbnum)
	int kdbnum;
{
	extern struct uba_driver kdbdriver;
	register struct uba_device *ui;
	register struct uba_driver *udp = &kdbdriver;
	int t;

	for (ui = ubdinit; ui->ui_driver; ui++) {
		/* ui->ui_ubanum is trash */
		if (ui->ui_driver != udp || ui->ui_alive ||
		    ui->ui_ctlr != kdbnum && ui->ui_ctlr != '?')
			continue;
		t = ui->ui_ctlr;
		ui->ui_ctlr = kdbnum;
		if ((*udp->ud_slave)(ui) == 0) {
			ui->ui_ctlr = t;
			continue;
		}
		ui->ui_alive = 1;
		ui->ui_ubanum = -1;

		/* make these invalid so we can see if someone uses them */
		/* might as well make each one different too */
		ui->ui_hd = (struct uba_hd *)0xc0000010;
		ui->ui_addr = (caddr_t)0xc0000014;
		ui->ui_physaddr = (caddr_t)0xc0000018;
		ui->ui_mi = (struct uba_ctlr *)0xc000001c;

		if (ui->ui_dk && dkn < DK_NDRIVE)
			ui->ui_dk = dkn++;
		else
			ui->ui_dk = -1;
		/* ui_type comes from driver */
		udp->ud_dinfo[ui->ui_unit] = ui;
		printf("%s%d at %s%d slave %d\n",
		    udp->ud_dname, ui->ui_unit,
		    udp->ud_mname, ui->ui_ctlr, ui->ui_slave);
		(*udp->ud_attach)(ui);
	}
}
#endif /* NKDB > 0 */
#endif /* NBI > 0 */

E 106
E 97
E 83
I 15
#if NMBA > 0
I 23
struct	mba_device *mbaconfig();
E 23
E 15
/*
E 5
 * Find devices attached to a particular mba
 * and look for each device found in the massbus
 * initialization tables.
 */
D 2
mbafind(nxp)
E 2
I 2
mbafind(nxv, nxp)
D 5
	struct nexus *nxv;
E 2
	struct nexus *nxp;
E 5
I 5
	struct nexus *nxv, *nxp;
E 5
{
	register struct mba_regs *mdp;
	register struct mba_drv *mbd;
I 23
	register struct mba_device *mi;
	register struct mba_slave *ms;
E 23
D 25
	int dn, dt, sn, ds;
D 23
	struct mba_info	fnd;
E 23
I 23
	struct mba_device	fnd;
E 25
I 25
D 41
	int dn, dt;
E 41
I 41
	int dn, dt, sn;
E 41
	struct mba_device fnd;
E 25
E 23

D 2
	mdp = (struct mba_regs *)nxp;
E 2
I 2
	mdp = (struct mba_regs *)nxv;
D 3
	mba_hd[mbanum].mh_mba = mdp;
	mba_hd[mbanum].mh_physmba = (struct mba_regs *)nxp;
	setscbnex(nexnum, mbaintv[mbanum]);
E 3
I 3
	mba_hd[nummba].mh_mba = mdp;
	mba_hd[nummba].mh_physmba = (struct mba_regs *)nxp;
D 25
	setscbnex(nexnum, mbaintv[nummba]);
E 25
I 25
	setscbnex(mbaintv[nummba]);
I 85
	mdp->mba_cr = MBCR_INIT;
	mdp->mba_cr = MBCR_IE;
E 85
E 25
E 3
E 2
	fnd.mi_mba = mdp;
D 3
	fnd.mi_mbanum = mbanum;
E 3
I 3
	fnd.mi_mbanum = nummba;
E 3
	for (mbd = mdp->mba_drv, dn = 0; mbd < &mdp->mba_drv[8]; mbd++, dn++) {
I 35
		if ((mbd->mbd_ds&MBDS_DPR) == 0)
			continue;
I 40
		mdp->mba_sr |= MBSR_NED;		/* si kludge */
E 40
E 35
		dt = mbd->mbd_dt & 0xffff;
		if (dt == 0)
			continue;
I 40
		if (mdp->mba_sr&MBSR_NED)
			continue;			/* si kludge */
E 40
D 3
		ds = mbd->mbd_ds;
E 3
D 33
		if ((dt&MBDT_TYPE) == MBDT_TU78) {
			printf("tm04/tu78 unsupported\n");
			continue;
		}
E 33
		if (dt == MBDT_MOH)
			continue;
		fnd.mi_drive = dn;
D 23
		if (dt & MBDT_TAP) {
			for (sn = 0; sn < 8; sn++) {
				mbd->mbd_tc = sn;
E 23
I 23
D 41
		if ((mi = mbaconfig(&fnd, dt)) && (dt & MBDT_TAP)) {
			for (ms = mbsinit; ms->ms_driver; ms++)
			if (ms->ms_driver == mi->mi_driver && ms->ms_alive == 0 && 
			    (ms->ms_ctlr == mi->mi_unit || ms->ms_ctlr=='?')) {
D 34
				mbd->mbd_tc = ms->ms_slave;
E 23
				dt = mbd->mbd_dt;
D 23
				if ((dt & MBDT_SPR) == 0)
					continue;
D 21
				dt &= MBDT_TYPE;
E 21
				fnd.mi_slave = sn;
				mbaconfig(&fnd, dt);
E 23
I 23
D 24
				ms->ms_alive = 1;
				ms->ms_ctlr = mi->mi_unit;
E 24
				if (dt & MBDT_SPR) {
E 34
I 34
				if ((*ms->ms_driver->md_slave)(mi, ms)) {
E 34
					printf("%s%d at %s%d slave %d\n",
					    ms->ms_driver->md_sname,
					    ms->ms_unit,
					    mi->mi_driver->md_dname,
					    mi->mi_unit,
					    ms->ms_slave);
E 41
I 41
#define	qeq(a, b)	( a == b || a == '?' )
		if ((mi = mbaconfig(&fnd, dt)) && (dt & MBDT_TAP))
		    for (sn = 0; sn < 8; sn++) {
			mbd->mbd_tc = sn;
		        for (ms = mbsinit; ms->ms_driver; ms++)
			    if (ms->ms_driver == mi->mi_driver &&
				ms->ms_alive == 0 && 
				qeq(ms->ms_ctlr, mi->mi_unit) &&
				qeq(ms->ms_slave, sn) &&
				(*ms->ms_driver->md_slave)(mi, ms, sn)) {
					printf("%s%d at %s%d slave %d\n"
					    , ms->ms_driver->md_sname
					    , ms->ms_unit
					    , mi->mi_driver->md_dname
					    , mi->mi_unit
					    , sn
					);
E 41
I 24
					ms->ms_alive = 1;
					ms->ms_ctlr = mi->mi_unit;
I 41
					ms->ms_slave = sn;
I 93
					break;
E 93
E 41
E 24
D 34
					(*ms->ms_driver->md_slave)
					    (mi, ms);
E 34
				}
E 23
D 41
			}
D 23
		} else {
			fnd.mi_slave = -1;
D 21
			mbaconfig(&fnd, dt&MBDT_TYPE);
E 21
I 21
			mbaconfig(&fnd, dt);
E 23
E 21
		}
E 41
I 41
		    }
E 41
	}
I 2
D 25
	mdp->mba_cr = MBAINIT;
	mdp->mba_cr = MBAIE;
E 25
I 25
D 85
	mdp->mba_cr = MBCR_INIT;
	mdp->mba_cr = MBCR_IE;
E 85
E 25
E 2
}

/*
 * Have found a massbus device;
 * see if it is in the configuration table.
 * If so, fill in its data.
 */
I 23
struct mba_device *
E 23
mbaconfig(ni, type)
D 23
	register struct mba_info *ni;
E 23
I 23
	register struct mba_device *ni;
E 23
	register int type;
{
D 23
	register struct mba_info *mi;
E 23
I 23
	register struct mba_device *mi;
E 23
	register short *tp;
I 9
	register struct mba_hd *mh;
E 9

D 2
	dprintf("mbaconfig %x\n", type);
E 2
D 23
	for (mi = mbinit; mi->mi_driver; mi++) {
E 23
I 23
	for (mi = mbdinit; mi->mi_driver; mi++) {
E 23
		if (mi->mi_alive)
			continue;
		tp = mi->mi_driver->md_type;
		for (mi->mi_type = 0; *tp; tp++, mi->mi_type++)
D 21
			if (*tp == type)
E 21
I 21
			if (*tp == (type&MBDT_TYPE))
E 21
				goto found;
		continue;
found:
#define	match(fld)	(ni->fld == mi->fld || mi->fld == '?')
D 23
		if (!match(mi_slave) || !match(mi_drive) || !match(mi_mbanum))
E 23
I 23
		if (!match(mi_drive) || !match(mi_mbanum))
E 23
			continue;
I 5
D 8
		printf("%c at mba%d drive %d ",
		    mi->mi_name, ni->mi_mbanum, ni->mi_drive);
		if (ni->mi_slave >= 0)
			printf("slave %d ", ni->mi_slave);
		printf("is unit %d\n", mi->mi_unit);
E 8
I 8
D 21
		printf("%c%d at mba%d drive %d\n",
E 21
I 21
D 23
		printf("%c%d at mba%d drive %d",
E 21
		    mi->mi_name, mi->mi_unit, ni->mi_mbanum, ni->mi_drive);
I 21
		if (type & MBDT_TAP)
D 22
			printf(" slave %d", ni->ni_slave);
E 22
I 22
			printf(" slave %d", ni->mi_slave);
E 23
I 23
D 37
		printf("%s%d at mba%d drive %d",
E 37
I 37
D 86
		printf("%s%d at mba%d drive %d\n",
E 86
I 86
		printf("%s%d at mba%d drive %d",
E 86
E 37
		    mi->mi_driver->md_dname, mi->mi_unit,
		    ni->mi_mbanum, ni->mi_drive);
E 23
E 22
D 37
		printf("\n");
E 37
E 21
E 8
E 5
		mi->mi_alive = 1;
D 9
		mi->mi_hd = &mba_hd[ni->mi_mbanum];
		mba_hd[ni->mi_mbanum].mh_mbip[ni->mi_drive] = mi;
E 9
I 9
		mh = &mba_hd[ni->mi_mbanum];
		mi->mi_hd = mh;
		mh->mh_mbip[ni->mi_drive] = mi;
		mh->mh_ndrive++;
E 9
		mi->mi_mba = ni->mi_mba;
		mi->mi_drv = &mi->mi_mba->mba_drv[ni->mi_drive];
D 37
		mi->mi_driver->md_info[mi->mi_unit] = mi;
E 37
		mi->mi_mbanum = ni->mi_mbanum;
		mi->mi_drive = ni->mi_drive;
D 23
		mi->mi_slave = ni->mi_slave;
E 23
I 8
D 37
		if (mi->mi_dk && dkn < DK_NDRIVE)
			mi->mi_dk = dkn++;
		else
			mi->mi_dk = -1;
E 37
I 37
		/*
		 * If drive has never been seen before,
		 * give it a dkn for statistics.
		 */
		if (mi->mi_driver->md_info[mi->mi_unit] == 0) {
			mi->mi_driver->md_info[mi->mi_unit] = mi;
			if (mi->mi_dk && dkn < DK_NDRIVE)
				mi->mi_dk = dkn++;
			else
				mi->mi_dk = -1;
		}
E 37
I 9
D 23
		(*mi->mi_driver->md_dkinit)(mi);
E 23
I 23
		(*mi->mi_driver->md_attach)(mi);
I 86
		printf("\n");
E 86
		return (mi);
E 23
E 9
E 8
	}
I 23
	return (0);
E 23
}
I 15
#endif
E 15

D 2
ubafind(nxp, i)
	struct nexus *nxp;
E 2
I 2
/*
D 5
 * Find mass storage devices on a UNIBUS.
E 5
I 5
 * Fixctlrmask fixes the masks of the driver ctlr routines
 * which otherwise save r10 and r11 where the interrupt and br
 * level are passed through.
E 5
 */
D 5
unifind(ubp, puba, vuba)
	struct uba_regs *ubp;
	caddr_t puba;
	caddr_t vuba;
E 5
I 5
fixctlrmask()
E 5
E 2
{
D 5
	register br, cvec;			/* MUST BE r11, r10 */
E 5
I 5
D 23
	register struct uba_minfo *um;
E 5
D 2
	register struct uba_regs *ubp = (struct uba_regs *)nxp;
	register short *uba;
	register struct uba_info *ui;
	register u_short *sp;
E 2
I 2
	register struct uba_dinfo *ui;
E 23
I 23
	register struct uba_ctlr *um;
	register struct uba_device *ui;
E 23
D 5
	register u_short *uba = (u_short *)vuba, *sp;
E 5
I 5
	register struct uba_driver *ud;
#define	phys(a,b) ((b)(((int)(a))&0x7fffffff))

	for (um = ubminit; ud = phys(um->um_driver, struct uba_driver *); um++)
D 9
		*phys(ud->ud_cntrlr, short *) &= ~0xc00;
E 9
I 9
		*phys(ud->ud_probe, short *) &= ~0xc00;
E 9
	for (ui = ubdinit; ud = phys(ui->ui_driver, struct uba_driver *); ui++)
D 9
		*phys(ud->ud_cntrlr, short *) &= ~0xc00;
E 9
I 9
		*phys(ud->ud_probe, short *) &= ~0xc00;
E 9
D 6
	asm("halt");
E 6
}

I 83
D 97
#if VAX630
E 97
I 97
#ifdef QBA
E 97
E 83
/*
I 83
 * Configure a Q-bus.
 */
probeqbus(qb)
	struct qbus *qb;
{
	register struct uba_hd *uhp = &uba_hd[numuba];

D 97
	ioaccess(qb->qb_map, Nexmap[0], qb->qb_memsize * sizeof (struct pte));
E 97
I 97
	ioaccess((caddr_t)qb->qb_map, Nexmap[0],
		qb->qb_memsize * sizeof (struct pte));
E 97
	uhp->uh_type = qb->qb_type;
	uhp->uh_uba = (struct uba_regs *)0xc0000000;   /* no uba adaptor regs */
	uhp->uh_mr = (struct pte *)&nexus[0];
	/*
	 * The map registers start right at 20088000 on the
	 * ka630, so we have to subtract out the 2k offset to make the
	 * pointers work..
	 */
	uhp->uh_physuba = (struct uba_regs *)(((u_long)qb->qb_map)-0x800);

	uhp->uh_memsize = qb->qb_memsize;
	ioaccess(qb->qb_maddr, UMEMmap[numuba], uhp->uh_memsize * NBPG);
	uhp->uh_mem = umem[numuba];

	/*
	 * The I/O page is mapped to the 8K of the umem address space
	 * immediately after the memory section that is mapped.
	 */
	ioaccess(qb->qb_iopage, UMEMmap[numuba] + uhp->uh_memsize,
	    UBAIOPAGES * NBPG);
	uhp->uh_iopage = umem[numuba] + (uhp->uh_memsize * NBPG);

	unifind(uhp, qb->qb_iopage);
}
#endif

I 97
#if NUBA > 0
E 97
probeuba(vubp, pubp, pumem)
	struct uba_regs *vubp, *pubp;
	caddr_t pumem;
{
	register struct uba_hd *uhp = &uba_hd[numuba];
D 97
	caddr_t vumem;
E 97

	/*
	 * Save virtual and physical addresses of adaptor.
	 */
	switch (cpu) {
#ifdef DW780
	case VAX_8600:
	case VAX_780:
		uhp->uh_type = DW780;
		break;
#endif
#ifdef DW750
	case VAX_750:
		uhp->uh_type = DW750;
		break;
#endif
#ifdef DW730
	case VAX_730:
		uhp->uh_type = DW730;
		break;
#endif
I 97
#ifdef DWBUA
	case VAX_8200:
		uhp->uh_type = DWBUA;
		break;
#endif
E 97
	default:
		panic("unknown UBA type");
		/*NOTREACHED*/
	}
	uhp->uh_uba = vubp;
	uhp->uh_physuba = pubp;
	uhp->uh_mr = vubp->uba_map;
	uhp->uh_memsize = UBAPAGES;

	ioaccess(pumem, UMEMmap[numuba], (UBAPAGES + UBAIOPAGES) * NBPG);
	uhp->uh_mem = umem[numuba];
	uhp->uh_iopage = umem[numuba] + (uhp->uh_memsize * NBPG);

	unifind(uhp, pumem + (uhp->uh_memsize * NBPG));
}

/*
E 83
 * Find devices on a UNIBUS.
 * Uses per-driver routine to set <br,cvec> into <r11,r10>,
 * and then fills in the tables, with help from a per-driver
 * slave initialization routine.
 */
D 32
unifind(vubp, pubp, vumem, pumem)
E 32
I 32
D 65
unifind(vubp, pubp, vumem, pumem, memmap)
E 65
I 65
D 83
unifind(vubp, pubp, vumem, pumem, memmap, haveubasr)
E 65
E 32
	struct uba_regs *vubp, *pubp;
	caddr_t vumem, pumem;
I 32
	struct pte *memmap;
I 65
	int haveubasr;
E 83
I 83
unifind(uhp0, pumem)
	struct uba_hd *uhp0;
	caddr_t pumem;
E 83
E 65
E 32
{
I 25
#ifndef lint
E 25
D 101
	register int br, cvec;			/* MUST BE r11, r10 */
E 101
I 101
	register int rbr, rcvec;			/* MUST BE r11, r10 */
E 101
I 25
#else
	/*
	 * Lint doesn't realize that these
	 * can be initialized asynchronously
	 * when devices interrupt.
	 */
D 101
	register int br = 0, cvec = 0;
E 101
I 101
	register int rbr = 0, rcvec = 0;
E 101
#endif
E 25
D 23
	register struct uba_dinfo *ui;
	register struct uba_minfo *um;
E 23
I 23
	register struct uba_device *ui;
	register struct uba_ctlr *um;
I 83
	register struct uba_hd *uhp = uhp0;
E 83
E 23
D 25
	u_short *umem = (u_short *)vumem, *sp, *reg, addr;
E 25
I 25
D 41
	u_short *reg, addr;
E 41
I 41
	u_short *reg, *ap, addr;
E 41
E 25
D 83
	struct uba_hd *uhp;
E 83
E 5
E 2
	struct uba_driver *udp;
D 2
	short *reg;
	int i;
E 2
I 2
D 5
	u_short *reg;
	register i;
	u_short addr;
E 5
I 5
D 8
	int i, (**ivec)();
E 8
I 8
D 39
	int i, (**ivec)(), haveubasr = 0;
E 39
I 39
D 65
	int i, (**ivec)(), haveubasr;
E 65
I 65
	int i, (**ivec)();
E 65
I 41
D 91
	caddr_t ualloc, zmemall();
E 91
I 91
	caddr_t ualloc;
E 91
I 45
D 97
	extern int catcher[256];
I 83
#ifdef DW780
E 97
I 97
	extern quad catcher[128];
I 101
	extern int br, cvec;
E 101
#if DW780 || DWBUA
E 97
	struct uba_regs *vubp = uhp->uh_uba;
#endif
E 83
E 45
E 41
E 39
E 8
E 5
E 2

I 78
D 83
#if VAX630
E 83
E 78
I 5
	/*
I 78
D 83
	 * The map registers start right at 20088000 on the
	 * ka630, so we have to subtract out the 2k offset to make the
	 * pointers work..
	 */
	if (cpu == VAX_630) {
		vubp = (struct uba_regs *)(((u_long)vubp)-0x800);
		pubp = (struct uba_regs *)(((u_long)pubp)-0x800);
	}
#endif
	/*
E 83
E 78
	 * Initialize the UNIBUS, by freeing the map
	 * registers and the buffered data path registers
	 */
D 83
	uhp = &uba_hd[numuba];
E 83
D 90
	uhp->uh_map = (struct map *)calloc(UAMSIZ * sizeof (struct map));
E 90
I 90
	uhp->uh_map = (struct map *)
D 98
		malloc(UAMSIZ * sizeof (struct map), M_DEVBUF, M_NOWAIT);
E 98
I 98
		malloc((u_long)(UAMSIZ * sizeof (struct map)), M_DEVBUF,
		    M_NOWAIT);
E 98
I 94
	if (uhp->uh_map == 0)
		panic("no mem for unibus map");
D 95
	bzero(uhp->uh_map, UNAMSIZ * sizeof (struct map));
E 95
I 95
D 98
	bzero(uhp->uh_map, UAMSIZ * sizeof (struct map));
E 98
I 98
	bzero((caddr_t)uhp->uh_map, (unsigned)(UAMSIZ * sizeof (struct map)));
E 98
E 95
E 94
E 90
D 19
	mfree(uhp->uh_map, NUBMREG, 1);
E 19
I 19
D 39
	rminit(uhp->uh_map, NUBMREG, 1, "uba", UAMSIZ);
E 19
	switch (cpu) {
E 5
D 2
	uba = (short *)(PHYSUDEV0 + i * PHYSUDEVSZ - 0160000);
	return;			/******** ZZZZZZZZZZZ *******/
#if	VAX==ANY || VAX==780
	if (cpu == 780) {
E 2
I 2
#if VAX780
D 5
	if (ubp) {
E 2
		ubp->uba_sr = ubp->uba_sr;
		curuba = ubp;
E 5
I 5
	case VAX_780:
D 8
		uhp->uh_bdpfree = (1<<15) - 1;		/* 15 bdp's */
E 8
I 8
		uhp->uh_bdpfree = (1<<NBDP780) - 1;
		haveubasr = 1;
E 8
		break;
#endif
#if VAX750
	case VAX_750:
D 8
		uhp->uh_bdpfree = (1<<3) - 1;		/* 3 bdp's */
E 8
I 8
		uhp->uh_bdpfree = (1<<NBDP750) - 1;
I 29
		break;
#endif
D 30
#if VAX730
	case VAX_730:
E 30
I 30
#if VAX7ZZ
	case VAX_7ZZ:
E 30
E 29
E 8
		break;
#endif
E 5
	}
E 39
I 39
	ubainitmaps(uhp);
D 65
	haveubasr = cpu == VAX_780;
E 65
E 39
I 5

	/*
D 83
	 * Save virtual and physical addresses
	 * of adaptor, and allocate and initialize
	 * the UNIBUS interrupt vector.
	 */
	uhp->uh_uba = vubp;
	uhp->uh_physuba = pubp;
I 76
	/*
E 83
I 83
D 97
	 * Allocate and initialize space
	 * for the UNIBUS interrupt vectors.
E 83
	 * On the 8600, can't use UNIvec;
	 * the vectors for the second SBI overlap it.
E 97
I 97
	 * Initialize space for the UNIBUS interrupt vectors.
	 * On the 8600, can't use first slot in UNIvec
	 * (the vectors for the second SBI overlap it);
	 * move each set of vectors forward.
E 97
	 */
I 83
#if	VAX8600
E 83
E 76
I 28
D 51
/* HAVE TO DO SOMETHING SPECIAL FOR SECOND UNIBUS ON COMETS HERE */
E 51
E 28
D 65
	if (numuba == 0)
E 65
I 65
	if (cpu == VAX_8600)
D 90
		uhp->uh_vec = (int(**)())calloc(512);
E 90
I 90
D 97
		uhp->uh_vec = (int(**)())malloc(512, M_DEVBUF, M_NOWAIT);
E 97
I 97
		uhp->uh_vec = UNIvec[numuba + 1];
E 97
E 90
D 83
	else if (numuba == 0)
E 83
I 83
	else
#endif
D 97
	if (numuba == 0)
E 83
E 65
		uhp->uh_vec = UNIvec;
D 51
	else
		uhp->uh_vec = (int(**)())calloc(512);
E 51
I 51
#if NUBA > 1
	else if (numuba == 1)
		uhp->uh_vec = UNI1vec;
D 59
	else {
#if defined(VAX_750)
		if (cpu == VAX_750)
			printf("More than 2 UBA's not supported\n");
		else
#endif
			uhp->uh_vec = (int(**)())calloc(512);
	}
E 59
I 59
	else
D 90
		uhp->uh_vec = (int(**)())calloc(512);
E 90
I 90
		uhp->uh_vec = (int(**)())malloc(512, M_DEVBUF, M_NOWAIT);
E 90
E 59
#endif
E 97
I 97
		uhp->uh_vec = UNIvec[numuba];
E 97
E 51
	for (i = 0; i < 128; i++)
D 97
		uhp->uh_vec[i] =
		    scbentry(&catcher[i*2], SCB_ISTACK);
E 97
I 97
		uhp->uh_vec[i] = scbentry(&catcher[i], SCB_ISTACK);
E 97
I 33
	/*
	 * Set last free interrupt vector for devices with
	 * programmable interrupt vectors.  Use is to decrement
	 * this number and use result as interrupt vector.
	 */
	uhp->uh_lastiv = 0x200;

I 97
#ifdef DWBUA
	if (uhp->uh_type == DWBUA)
		BUA(vubp)->bua_offset = (int)uhp->uh_vec - (int)&scb[0];
#endif

E 97
E 33
I 25
D 36
	/* THIS IS A CHEAT: USING THE FACT THAT UMEM and NEXI ARE SAME SIZE */
E 25
D 32
	nxaccess((struct nexus *)pumem, UMEMmap[numuba]);
E 32
I 32
	nxaccess((struct nexus *)pumem, memmap);
E 36
I 36
D 65
	ubaaccess(pumem, memmap);
E 36
E 32
#if VAX780
E 65
I 65
D 76
	ubaaccess(pumem, memmap, UBAPAGES * NBPG);
E 76
I 76
D 78
	ioaccess(pumem, memmap, UBAPAGES * NBPG);
E 78
I 78
D 83
#if VAX630
	/*
	 * Kludge time again. The q22 memory and device reg. address spaces
	 * are not physically contiguous, so we need 2 loops to map them
	 * into contiguous virtual space.
	 */
	if (cpu == VAX_630) {
		ioaccess(pumem, memmap, (UBAPAGES-16)*NBPG);
		ioaccess(0x20000000, memmap+(UBAPAGES-16), 16*NBPG);
	} else
#endif
		ioaccess(pumem, memmap, UBAPAGES * NBPG);
E 78
E 76
#if defined(VAX780) || defined(VAX8600)
E 65
D 8
	if (cpu == VAX_780) {
E 8
I 8
	if (haveubasr) {
E 83
I 83
#ifdef DW780
	if (uhp->uh_type == DW780) {
E 83
E 8
		vubp->uba_sr = vubp->uba_sr;
D 8
		curuba = vubp;
E 8
I 8
D 23
		vubp->uba_cr = UBA_IFS|UBA_BRIE;
E 23
I 23
		vubp->uba_cr = UBACR_IFS|UBACR_BRIE;
E 23
E 8
	}
E 5
#endif
D 2
#if	VAX==ANY || VAX==750
	setvecs();
E 2
I 2
D 8
#if VAX750
D 5
	if (ubp == 0)
E 5
I 5
	if (cpu != VAX_780)
E 5
		setvecs();
E 2
#endif
E 8
D 2
	for (ui = ubinit; udp = ui->ui_driver; ui++) {
		if (ui->ui_ubanum != ubanum && ui->ui_ubanum != '?')
E 2
I 2
D 5
	for (ui = ubdinit; udp = ui->ui_driver; ui++) {
		if (ui->ui_ubanum != numuba && ui->ui_ubanum != '?')
E 5
I 5
	/*
I 61
	 * First configure devices that have unibus memory,
	 * allowing them to allocate the correct map registers.
	 */
	ubameminit(numuba);
	/*
E 61
I 41
	 * Grab some memory to record the umem address space we allocate,
	 * so we can be sure not to place two devices at the same address.
	 *
	 * We could use just 1/8 of this (we only want a 1 bit flag) but
	 * we are going to give it back anyway, and that would make the
	 * code here bigger (which we can't give back), so ...
	 *
	 * One day, someone will make a unibus with something other than
	 * an 8K i/o address space, & screw this totally.
	 */
D 91
	ualloc = zmemall(memall, 8*1024);
E 91
I 91
D 92
	ualloc = (caddr_t)malloc(ctob(8*1024), M_TEMP, M_NOWAIT);
E 92
I 92
D 98
	ualloc = (caddr_t)malloc(8*1024, M_TEMP, M_NOWAIT);
E 98
I 98
	ualloc = (caddr_t)malloc((u_long)(8 * 1024), M_TEMP, M_NOWAIT);
E 98
E 92
E 91
	if (ualloc == (caddr_t)0)
		panic("no mem for unifind");
I 91
D 92
	bzero(ualloc, ctob(8*1024));
E 92
I 92
	bzero(ualloc, 8*1024);
E 92
E 91

	/*
E 41
	 * Map the first page of UNIBUS i/o
	 * space to the first page of memory
	 * for devices which will need to dma
	 * output to produce an interrupt.
	 */
D 23
	*(int *)(&vubp->uba_map[0]) = UBA_MRV;
E 23
I 23
D 83
	*(int *)(&vubp->uba_map[0]) = UBAMR_MRV;
E 83
I 83
	*(int *)(&uhp->uh_mr[0]) = UBAMR_MRV;
E 83
E 23

D 36
#define	ubaddr(off)	(u_short *)((int)vumem + ((off)&0x1fff))
E 36
I 36
D 41
#define	ubaddr(off)	(u_short *)((int)vumem + ((off)&0x3ffff))
E 41
I 41
D 83
#define	ubaoff(off)	((off)&0x1fff)
#define	ubaddr(off)	(u_short *)((int)vumem + (ubaoff(off)|0x3e000))
E 83
I 83
#define	ubaddr(uhp, off)    (u_short *)((int)(uhp)->uh_iopage + ubdevreg(off))
E 83
E 41
I 38
D 39
#define	ubdevreg(addr)	(addr&0x1fff|0760000)
E 39
E 38
E 36
	/*
	 * Check each unibus mass storage controller.
	 * For each one which is potentially on this uba,
	 * see if it is really there, and if it is record it and
	 * then go looking for slaves.
	 */
	for (um = ubminit; udp = um->um_driver; um++) {
D 97
		if (um->um_ubanum != numuba && um->um_ubanum != '?')
E 97
I 97
		if (um->um_ubanum != numuba && um->um_ubanum != '?' ||
		    um->um_alive)
E 97
E 5
E 2
			continue;
D 2
		for (sp = udp->ud_addr; *sp; sp++) {
#define	ubaddr(i)	(short *)((int)uba + (i))
			reg = ubaddr(*sp);
E 2
I 2
D 5
		addr = (u_short)ui->ui_addr;
		sp = udp->ud_addr;
		for (; addr || *sp; addr = 0) {
#define	ubaddr(off)	(u_short *)((int)uba + ((off)&0x1fff))
			if (addr == 0)
				addr = *sp++;
			reg = ubaddr(addr);
E 2
			if (badaddr((caddr_t)reg, 2))
				continue;
E 5
I 5
		addr = (u_short)um->um_addr;
D 36
		reg = ubaddr(addr);
E 36
I 36
D 41
		reg = ubaddr(addr|0x3e000);
E 41
I 41
		/*
		 * use the particular address specified first,
		 * or if it is given as "0", of there is no device
		 * at that address, try all the standard addresses
		 * in the driver til we find it
		 */
	    for (ap = udp->ud_addr; addr || (addr = *ap++); addr = 0) {

D 83
		if (ualloc[ubaoff(addr)])
E 83
I 83
		if (ualloc[ubdevreg(addr)])
E 83
			continue;
D 83
		reg = ubaddr(addr);
E 83
I 83
		reg = ubaddr(uhp, addr);
E 83
E 41
E 36
		if (badaddr((caddr_t)reg, 2))
			continue;
E 5
D 2
#if	VAX==780 || VAX==ANY
			if (cpu == 780) {
E 2
I 2
D 65
#if VAX780
E 65
I 65
D 83
#if defined(VAX780) || defined(VAX8600)
E 65
D 5
			if (ubp) {
E 2
				if (ubp->uba_sr) {
					ubp->uba_sr = ubp->uba_sr;
					continue;
				}
				ubatstvec(ubp);
E 5
I 5
D 8
		if (vax == VAX_780) {
			if (vubp->uba_sr) {
				vubp->uba_sr = vubp->uba_sr;
				continue;
E 5
			}
I 5
			ubatstvec(vubp);
E 8
I 8
		if (haveubasr && vubp->uba_sr) {
E 83
I 83
#ifdef DW780
		if (uhp->uh_type == DW780 && vubp->uba_sr) {
E 83
			vubp->uba_sr = vubp->uba_sr;
			continue;
E 8
		}
E 5
#endif
D 5
			cvec = 0x200;
I 3
			*(int *)(&ubp->uba_map[0]) = UBA_MRV;
E 3
			i = (*udp->ud_cntrlr)(ui, reg);
E 5
I 5
		cvec = 0x200;
I 101
		rcvec = 0x200;
E 101
D 9
		i = (*udp->ud_cntrlr)(um, reg);
E 9
I 9
D 47
		i = (*udp->ud_probe)(reg);
E 47
I 47
D 61
		i = (*udp->ud_probe)(reg, um->um_ctlr);
E 61
I 61
		i = (*udp->ud_probe)(reg, um->um_ctlr, um);
E 61
E 47
E 9
E 5
D 2
#if	VAX==780 || VAX==ANY
			if (cpu == 780) {
E 2
I 2
D 65
#if VAX780
E 65
I 65
D 83
#if defined(VAX780) || defined(VAX8600)
E 65
D 5
			if (ubp) {
E 2
				ubp->uba_cr = 0;
				if (ubp->uba_sr) {
I 3
					dprintf("uba_sr %x\n", ubp->uba_sr);
E 3
					ubp->uba_sr = ubp->uba_sr;
					continue;
				}
E 5
I 5
D 8
		if (vax == VAX_780) {
			if (vubp->uba_sr) {
				vubp->uba_sr = vubp->uba_sr;
				continue;
E 5
			}
E 8
I 8
		if (haveubasr && vubp->uba_sr) {
E 83
I 83
#ifdef DW780
		if (uhp->uh_type == DW780 && vubp->uba_sr) {
E 83
			vubp->uba_sr = vubp->uba_sr;
			continue;
E 8
I 5
		}
E 5
#endif
D 5
			if (i == 0)
E 5
I 5
		if (i == 0)
			continue;
D 8
		printf("%s %d at uba%d %o ",
		    udp->ud_pname, um->um_ctlr, numuba, addr);
E 8
I 8
		printf("%s%d at uba%d csr %o ",
		    udp->ud_mname, um->um_ctlr, numuba, addr);
E 8
D 101
		if (cvec == 0) {
E 101
I 101
		if (rcvec == 0) {
E 101
			printf("zero vector\n");
			continue;
		}
D 101
		if (cvec == 0x200) {
E 101
I 101
		if (rcvec == 0x200) {
E 101
			printf("didn't interrupt\n");
			continue;
		}
D 8
		printf("vector %o, ipl %x\n", cvec, br);
E 8
I 8
D 101
		printf("vec %o, ipl %x\n", cvec, br);
E 101
I 101
		printf("vec %o, ipl %x\n", rcvec, rbr);
E 101
I 84
		csralloc(ualloc, addr, i);
E 84
E 8
		um->um_alive = 1;
		um->um_ubanum = numuba;
D 97
		um->um_hd = &uba_hd[numuba];
E 97
I 97
		um->um_hd = uhp;
E 97
		um->um_addr = (caddr_t)reg;
		udp->ud_minfo[um->um_ctlr] = um;
D 97
		for (ivec = um->um_intr; *ivec; ivec++) {
			um->um_hd->uh_vec[cvec/4] =
			    scbentry(*ivec, SCB_ISTACK);
			cvec += 4;
		}
E 97
I 97
D 101
		for (cvec /= 4, ivec = um->um_intr; *ivec; cvec++, ivec++)
			uhp->uh_vec[cvec] = scbentry(*ivec, SCB_ISTACK);
E 101
I 101
		for (rcvec /= 4, ivec = um->um_intr; *ivec; rcvec++, ivec++)
			uhp->uh_vec[rcvec] = scbentry(*ivec, SCB_ISTACK);
E 101
E 97
		for (ui = ubdinit; ui->ui_driver; ui++) {
I 97
			int t;

E 97
			if (ui->ui_driver != udp || ui->ui_alive ||
			    ui->ui_ctlr != um->um_ctlr && ui->ui_ctlr != '?' ||
			    ui->ui_ubanum != numuba && ui->ui_ubanum != '?')
E 5
				continue;
D 2
			printf("\tLocated %c at %o ", ui->ui_name, *sp);
E 2
I 2
D 3
			dprintf("\tLocated %c at %o ",
			    ui->ui_name, addr);
E 3
I 3
D 5
			dprintf("\tLocated %s at %o ",
			    ui->ui_driver->ud_pname, addr);
E 3
E 2
			if (cvec == 0) {
D 2
				printf("zero uba vector\n");
E 2
I 2
				dprintf("zero uba vector\n");
E 2
				continue;
E 5
I 5
D 8
			if ((*udp->ud_slave)(ui, reg, ui->ui_slave)) {
E 8
I 8
D 97
			if ((*udp->ud_slave)(ui, reg)) {
E 97
I 97
			t = ui->ui_ctlr;
			ui->ui_ctlr = um->um_ctlr;
			if ((*udp->ud_slave)(ui, reg) == 0)
				ui->ui_ctlr = t;
			else {
E 97
E 8
				ui->ui_alive = 1;
D 97
				ui->ui_ctlr = um->um_ctlr;
E 97
				ui->ui_ubanum = numuba;
D 97
				ui->ui_hd = &uba_hd[numuba];
E 97
I 97
				ui->ui_hd = uhp;
E 97
				ui->ui_addr = (caddr_t)reg;
D 38
				ui->ui_physaddr = pumem + (addr&0x1fff);
E 38
I 38
				ui->ui_physaddr = pumem + ubdevreg(addr);
E 38
D 8
				ui->ui_dk = 0;
E 8
I 8
				if (ui->ui_dk && dkn < DK_NDRIVE)
D 10
					ui->ui_dk = dkn;
E 10
I 10
					ui->ui_dk = dkn++;
E 10
				else
					ui->ui_dk = -1;
E 8
				ui->ui_mi = um;
				/* ui_type comes from driver */
				udp->ud_dinfo[ui->ui_unit] = ui;
D 8
				printf("%s%d slave %d is unit %d\n",
				    udp->ud_pname, um->um_ctlr,
				    ui->ui_slave, ui->ui_unit);
E 8
I 8
D 97
				printf("%s%d at %s%d slave %d\n",
E 97
I 97
				printf("%s%d at %s%d slave %d",
E 97
				    udp->ud_dname, ui->ui_unit,
				    udp->ud_mname, um->um_ctlr, ui->ui_slave);
I 9
				(*udp->ud_attach)(ui);
I 97
				printf("\n");
E 97
E 9
E 8
E 5
			}
D 5
			if (cvec == 0x200) {
D 2
				printf("didn't interrupt\n");
E 2
I 2
				dprintf("didn't interrupt\n");
E 5
I 5
		}
I 41
		break;
	    }
E 41
	}
	/*
	 * Now look for non-mass storage peripherals.
	 */
	for (ui = ubdinit; udp = ui->ui_driver; ui++) {
		if (ui->ui_ubanum != numuba && ui->ui_ubanum != '?' ||
		    ui->ui_alive || ui->ui_slave != -1)
			continue;
		addr = (u_short)ui->ui_addr;
D 36
		reg = ubaddr(addr);
E 36
I 36
D 41
		reg = ubaddr(addr|0x3e000);
E 41
I 41

	    for (ap = udp->ud_addr; addr || (addr = *ap++); addr = 0) {
		
D 83
		if (ualloc[ubaoff(addr)])
E 83
I 83
		if (ualloc[ubdevreg(addr)])
E 83
			continue;
D 83
		reg = ubaddr(addr);
E 83
I 83
		reg = ubaddr(uhp, addr);
E 83
E 41
E 36
		if (badaddr((caddr_t)reg, 2))
			continue;
D 65
#if VAX780
E 65
I 65
D 83
#if defined(VAX780) || defined(VAX8600)
E 65
D 8
		if (vax == VAX_780) {
			if (vubp->uba_sr) {
				vubp->uba_sr = vubp->uba_sr;
E 5
E 2
				continue;
			}
D 2
			printf("vector %o, ipl %x\n", cvec, br);
			if (ui->ui_slave == -1)
				goto ubdevfnd;
E 2
I 2
D 5
			dprintf("vector %o, ipl %x\n", cvec, br);
E 2
			if (ui->ui_slave != '?') {
				if ((*udp->ud_slave)(ui, reg, ui->ui_slave))
					goto ubdevfnd;
I 3
				dprintf("slave %d refused\n", ui->ui_slave);
E 5
I 5
			ubatstvec(vubp);
E 8
I 8
		if (haveubasr && vubp->uba_sr) {
E 83
I 83
#ifdef DW780
		if (uhp->uh_type == DW780 && vubp->uba_sr) {
E 83
			vubp->uba_sr = vubp->uba_sr;
			continue;
E 8
		}
#endif
I 101
		rcvec = 0x200;
E 101
		cvec = 0x200;
D 9
		i = (*udp->ud_cntrlr)(ui, reg);
E 9
I 9
D 33
		i = (*udp->ud_probe)(reg);
E 33
I 33
D 47
		i = (*udp->ud_probe)(reg, um->um_ctlr);
E 47
I 47
D 61
		i = (*udp->ud_probe)(reg);
E 61
I 61
		i = (*udp->ud_probe)(reg, ui);
E 61
E 47
E 33
E 9
D 65
#if VAX780
E 65
I 65
D 83
#if defined(VAX780) || defined(VAX8600)
E 65
D 8
		if (vax == VAX_780) {
			if (vubp->uba_sr) {
				vubp->uba_sr = vubp->uba_sr;
E 5
E 3
				continue;
			}
E 8
I 8
		if (haveubasr && vubp->uba_sr) {
E 83
I 83
#ifdef DW780
		if (uhp->uh_type == DW780 && vubp->uba_sr) {
E 83
			vubp->uba_sr = vubp->uba_sr;
			continue;
E 8
D 5
			for (i = 0; i < udp->ud_maxslave; i++) {
				if ((*udp->ud_slave)(ui, reg, i)) {
I 2
D 3
					int	(**ivec)();
E 3
I 3
					register int	(**ivec)();
E 3

E 2
					ui->ui_slave = i;
    ubdevfnd:
					ui->ui_alive = 1;
D 2
					ui->ui_ubanum = ubanum;
					ui->ui_hd = &uba_hd[ubanum];
E 2
I 2
					ui->ui_ubanum = numuba;
					ui->ui_hd = &uba_hd[numuba];
E 2
					ui->ui_addr = (caddr_t)reg;
D 2
					/* there must be more, surely !!! */
					/* NB: it is drivers responsibility  */
					/* to fill in ui_type if it wants it */
E 2
I 2
					ui->ui_physaddr = puba + (addr&0x1fff);
					ui->ui_dk = 0;
					/* ui_type comes from driver */
					udp->ud_info[ui->ui_unit] = ui;
					dprintf("\tslave %d\n", ui->ui_slave);
D 3
					for (ivec=udp->ud_intr; *ivec; ivec++) {
						caddr_t cp;
						int fn;

						if ((cp = calloc(12)) == 0)
							panic("nm/iv\n");
						ui->ui_hd->uh_vec[cvec] =
						    scbentry((int (*)()) cp,
							SCB_ISTACK);
						*cp++ = 0xbb; *cp++ = 0xff;
						*cp++ = 0xdd;
						*cp++ = ui->ui_unit&0x3f;
						*cp++ = 1; *cp++ = 0x9f;
						fn = (int)*ivec;
						for (i=0; i<4; i++)
							*cp++ = fn, fn >>= 4;
						*cp = 0x02;
E 3
I 3
					for (ivec=ui->ui_intr; *ivec; ivec++) {
						ui->ui_hd->uh_vec[cvec/4] =
						    scbentry(*ivec, SCB_ISTACK);
						cvec += 4;
E 3
					}
E 2
					break;
				}
I 3
				dprintf("slave %d refused\n", i);
E 3
			}
E 5
		}
I 5
#endif
		if (i == 0)
			continue;
D 8
		printf("%s at uba%d %o ",
		    ui->ui_driver->ud_pname, numuba, addr);
E 8
I 8
		printf("%s%d at uba%d csr %o ",
		    ui->ui_driver->ud_dname, ui->ui_unit, numuba, addr);
E 8
D 101
		if (cvec == 0) {
E 101
I 101
		if (rcvec == 0) {
E 101
			printf("zero vector\n");
			continue;
		}
D 101
		if (cvec == 0x200) {
E 101
I 101
		if (rcvec == 0x200) {
E 101
			printf("didn't interrupt\n");
			continue;
		}
D 8
		printf("vector %o, ipl %x\n", cvec, br);
E 8
I 8
D 101
		printf("vec %o, ipl %x\n", cvec, br);
E 101
I 101
		printf("vec %o, ipl %x\n", rcvec, rbr);
E 101
I 41
D 84
		while (--i >= 0)
D 83
			ualloc[ubaoff(addr+i)] = 1;
E 83
I 83
			ualloc[ubdevreg(addr+i)] = 1;
E 84
I 84
		csralloc(ualloc, addr, i);
E 84
E 83
E 41
E 8
D 97
		ui->ui_hd = &uba_hd[numuba];
		for (ivec = ui->ui_intr; *ivec; ivec++) {
			ui->ui_hd->uh_vec[cvec/4] =
			    scbentry(*ivec, SCB_ISTACK);
			cvec += 4;
		}
E 97
I 97
		ui->ui_hd = uhp;
D 101
		for (cvec /= 4, ivec = ui->ui_intr; *ivec; cvec++, ivec++)
			uhp->uh_vec[cvec] = scbentry(*ivec, SCB_ISTACK);
E 101
I 101
		for (rcvec /= 4, ivec = ui->ui_intr; *ivec; rcvec++, ivec++)
			uhp->uh_vec[rcvec] = scbentry(*ivec, SCB_ISTACK);
E 101
E 97
		ui->ui_alive = 1;
		ui->ui_ubanum = numuba;
		ui->ui_addr = (caddr_t)reg;
D 38
		ui->ui_physaddr = pumem + (addr&0x1fff);
E 38
I 38
		ui->ui_physaddr = pumem + ubdevreg(addr);
E 38
D 8
		ui->ui_dk = 0;
E 8
I 8
		ui->ui_dk = -1;
E 8
		/* ui_type comes from driver */
		udp->ud_dinfo[ui->ui_unit] = ui;
D 9
		(*udp->ud_slave)(ui, reg);
E 9
I 9
		(*udp->ud_attach)(ui);
I 41
		break;
	    }
E 41
E 9
E 5
	}
I 41

I 83
#ifdef DW780
	if (uhp->uh_type == DW780)
		uhp->uh_uba->uba_cr = UBACR_IFS | UBACR_BRIE |
		    UBACR_USEFIE | UBACR_SUEFIE |
		    (uhp->uh_uba->uba_cr & 0x7c000000);
#endif
	numuba++;

E 83
#ifdef	AUTO_DEBUG
	printf("Unibus allocation map");
	for (i = 0; i < 8*1024; ) {
		register n, m;

		if ((i % 128) == 0) {
			printf("\n%6o:", i);
			for (n = 0; n < 128; n++)
				if (ualloc[i+n])
					break;
			if (n == 128) {
				i += 128;
				continue;
			}
		}

		for (n = m = 0; n < 16; n++) {
			m <<= 1;
			m |= ualloc[i++];
		}

		printf(" %4x", m);
	}
	printf("\n");
#endif

D 91
	wmemfree(ualloc, 8*1024);
E 91
I 91
	free(ualloc, M_TEMP);
E 91
I 84
}
I 97
#endif /* NUBA */
E 97

/*
 * Mark addresses starting at "addr" and continuing
 * "size" bytes as allocated in the map "ualloc".
 * Warn if the new allocation overlaps a previous allocation.
 */
static
csralloc(ualloc, addr, size)
	caddr_t ualloc;
	u_short addr;
	register int size;
{
	register caddr_t p;
	int warned = 0;

	p = &ualloc[ubdevreg(addr+size)];
	while (--size >= 0) {
		if (*--p && !warned) {
			printf(
	"WARNING: device registers overlap those for a previous device!\n");
			warned = 1;
		}
		*p = 1;
	}
I 106
}

/*
 * Peripheral-nexus controller and device matching.
 * The following routines match pnexus controllers and devices found by nexus
 * bus autoconfiguration with those configured into the kernel.
 *
 * The arguments are a pointer a uba_driver for the pnexus device we've found
 * and the nexus location ({nexclass,bus,node} triple) at which it was found.
 */
pnexus_match_ctlr(driver, nexclass, bus, node)
	register struct uba_driver *driver;
	int nexclass, bus, node;
{
	register int tie;
	register struct uba_ctlr *um;
	register struct uba_device *ui;

	/* First look for exact match */
	tie = PNEXUS_TIE(nexclass, bus, node);
	for (um = pnexminit; um->um_driver; um++)
		if (um->um_driver == driver && um->um_ubanum == tie &&
		    !um->um_alive)
			break;
	/* If no exact match, try looking for a wildcard match */
	if (!um->um_driver) {
		for (um = pnexminit; um->um_driver; um++)
			if (um->um_driver == driver && um->um_ubanum == -1 &&
			    !um->um_alive)
				break;
		/* If still no match, give up */
		if (!um->um_driver)
			return(-1);
	}
	/*
	 * We've got the controller, attach it.
	 * On UNIBUS we had no controller attach routine, but here we have the
	 * chance to do it right.  We overload the controller attach routine on
	 * ud_probe (pnexus devices need no problng).
	 * The attach routine sets um_alive.
	 */
	driver->ud_minfo[um->um_ctlr] = um;
	(*driver->ud_probe)(um, nexclass, bus, node);
	/* Now look for its slaves */
	for (ui = ubdinit; ui->ui_driver; ui++) {
I 107
		int t;

E 107
		if (ui->ui_driver != driver || ui->ui_alive ||
		    ui->ui_ctlr != um->um_ctlr && ui->ui_ctlr != '?')
			continue;
D 107
		if ((*driver->ud_slave)(ui, um)) {
E 107
I 107
		t = ui->ui_ctlr;
		ui->ui_ctlr = um->um_ctlr;
		if ((*driver->ud_slave)(ui, um) == 0)
			ui->ui_ctlr = t;
		else {
E 107
			ui->ui_alive = 1;
D 107
			ui->ui_ctlr = um->um_ctlr;
E 107
			if (ui->ui_dk && dkn < DK_NDRIVE)
				ui->ui_dk = dkn++;
			else
				ui->ui_dk = -1;
			ui->ui_mi = um;
			/* ui_type comes from driver */
			driver->ud_dinfo[ui->ui_unit] = ui;
			printf("%s%d at %s%d slave %d",
			    driver->ud_dname, ui->ui_unit,
			    driver->ud_mname, um->um_ctlr, ui->ui_slave);
			(*driver->ud_attach)(ui);
			printf("\n");
		}
	}
	return(0);
}

pnexus_match_device(driver, nexclass, bus, node)
	register struct uba_driver *driver;
	int nexclass, bus, node;
{
	register int tie;
	register struct uba_device *ui;

	/* First look for exact match */
	tie = PNEXUS_TIE(nexclass, bus, node);
	for (ui = pnexdinit; ui->ui_driver; ui++)
		if (ui->ui_driver == driver && ui->ui_ubanum == tie &&
		    !ui->ui_alive)
			break;
	/* If no exact match, try looking for a wildcard match */
	if (!ui->ui_driver) {
		for (ui = pnexdinit; ui->ui_driver; ui++)
			if (ui->ui_driver == driver && ui->ui_ubanum == -1 &&
			    !ui->ui_alive)
				break;
		/* If still no match, give up */
		if (!ui->ui_driver)
			return(-1);
	}
	/*
	 * We've got the device, attach it.
	 */
	ui->ui_dk = -1;
	/* ui_type comes from driver */
	driver->ud_dinfo[ui->ui_unit] = ui;
	/* ui_alive is set by the attach routine */
	(*driver->ud_attach)(ui, nexclass, bus, node);
	return(0);
E 106
E 84
E 41
}
I 109

#if NBVA
/*
 * Find devices on a BabyVAX.
 */
probe_babyvax()
{
	register struct uba_device *ui;
	register struct uba_ctlr *um;
	register struct uba_driver *udp;
	register int i;

	/*
	 * Probe the mass storage controller list first.
	 */
	for (um = bvaxminit; udp = um->um_driver; um++) {
		i = (*udp->ud_probe)(um);
		if (i == 0)
			continue;
		printf("%s%d at 0x%x\n",
			udp->ud_mname, um->um_ctlr, um->um_addr);
		um->um_alive = 1;
		udp->ud_minfo[um->um_ctlr] = um;
		for (ui = bvaxdinit; ui->ui_driver; ui++) {
			int t;

			if (ui->ui_driver != udp || ui->ui_alive ||
			    ui->ui_ctlr != um->um_ctlr && ui->ui_ctlr != '?')
				continue;
			t = ui->ui_ctlr;
			ui->ui_ctlr = um->um_ctlr;
			if ((*udp->ud_slave)(ui) == 0)
				ui->ui_ctlr = t;
			else {
				ui->ui_alive = 1;
				if (ui->ui_dk && dkn < DK_NDRIVE)
					ui->ui_dk = dkn++;
				else
					ui->ui_dk = -1;
				ui->ui_mi = um;
				/* ui_type comes from driver */
				udp->ud_dinfo[ui->ui_unit] = ui;
				printf("%s%d at %s%d slave %d",
				    udp->ud_dname, ui->ui_unit,
				    udp->ud_mname, um->um_ctlr, ui->ui_slave);
				(*udp->ud_attach)(ui);
				printf("\n");
			}
		}
	}
	/*
	 * Now look for non-mass storage peripherals.
	 */
	for (ui = bvaxdinit; udp = ui->ui_driver; ui++) {
		if (ui->ui_alive || ui->ui_slave != -1)
			continue;
		i = (*udp->ud_probe)(ui);
		if (i == 0)
			continue;
		printf("%s%d at 0x%x\n",
			ui->ui_driver->ud_dname, ui->ui_unit, ui->ui_addr);
		ui->ui_alive = 1;
		ui->ui_dk = -1;
		/* ui_type comes from driver */
		udp->ud_dinfo[ui->ui_unit] = ui;
		(*udp->ud_attach)(ui);
	}
}
#endif
E 109

D 2
#if	VAX==750 || VAX==ANY
E 2
I 2
D 8
#if VAX750
E 2
/*
 * For machines which vector unibus interrupts directly,
 * we must spray the unibus vector with pointers to distinct
 * functions.  We use the space normally used to catch stray
 * interrupts (which hasn't been set up) as a subroutine
 * with a number of entry points, with increment register
 * instructions between entry points to tell where we entered.
 */
setvecs()
{
	register int i;

D 2
	if (cpu == 780)
		return;
E 2
	for (i = 0; i < 128; i++) {
		catcher[i] = 0x015a04c2;	/* subl2 $4,r10; nop */
		Scbbase.scb_ubaint[i] = 
		    scbentry((int (*)())&catcher[i], SCB_ISTACK);
D 2
		    /**** WHAT IS scbentry() ???? ****/
E 2
	}
	catcher[i] = 0x025b12db;		/* mfpr $IPL,r11; rei */
}
#endif

D 2
#if	VAX==780 || VAX==ANY
E 2
I 2
#if VAX780
E 2
/*
D 2
 * The routine used to catch br 4/5/6/7 interrupts
 * on vaxen with unibus adaptors.  This looks at the
 * resulting vector register to tell where the interrupt
 * occurred.
 */
ubaintr()
{
	register int br, cvec;		/* MUST BE r11, r10 */
	int ubaintr0();

asm(".align 2");
asm(".globl _ubaintr0");
asm("_ubaintr0:");
	br = mfpr(IPL);
	cvec = curuba->uba_brrvr[br-0x14] & 0xffff;
	{ asm("rei"); }
}

/*
E 2
 * Init for testing vector addresses on a
D 2
 * machine where interrupts are vectored through a uba.
E 2
I 2
 * machine that has a UNIBUS adaptor to recieve interrupts
E 2
 */
ubatstvec(ubp)
	register struct uba_regs *ubp;
{
	register struct scb *sp = &Scbbase;
I 2
	extern int Xconfuaint();
E 2
	
	sp->scb_ipl14[nexnum] = sp->scb_ipl15[nexnum] =
	    sp->scb_ipl16[nexnum] = sp->scb_ipl17[nexnum] =
D 2
		scbentry(ubaintr0, SCB_ISTACK);
	ubp->uba_cr = IFS|BRIE;
E 2
I 2
		scbentry(Xconfuaint, SCB_ISTACK);
	ubp->uba_cr = UBA_IFS|UBA_BRIE;
E 2
}
#endif

E 8
D 25
setscbnex(nexnum, fn)
D 8
	int	(*fn)();
E 8
I 8
	int nexnum, (*fn)();
E 25
I 25
D 83
setscbnex(fn)
	int (*fn)();
E 25
E 8
{
D 8
	register struct scb *sp = &Scbbase;
E 8
I 8
D 9
	register struct scb *scb = &Scbbase;
E 9
I 9
	register struct scb *scbp = &scb;
E 9
E 8

I 65
D 76
	scbp = (struct scb *)((caddr_t)scbp + nsbi * IOAMAPSIZ);
E 76
I 76
	scbp = (struct scb *)((caddr_t)scbp + nsbi * 512);
E 76
E 65
D 8
	sp->scb_ipl14[nexnum] = sp->scb_ipl15[nexnum] =
	    sp->scb_ipl16[nexnum] = sp->scb_ipl17[nexnum] =
E 8
I 8
D 9
	scb->scb_ipl14[nexnum] = scb->scb_ipl15[nexnum] =
	    scb->scb_ipl16[nexnum] = scb->scb_ipl17[nexnum] =
E 9
I 9
	scbp->scb_ipl14[nexnum] = scbp->scb_ipl15[nexnum] =
	    scbp->scb_ipl16[nexnum] = scbp->scb_ipl17[nexnum] =
E 9
E 8
		scbentry(fn, SCB_ISTACK);
}

E 83
/*
D 70
 * Make a nexus accessible at physical address phys
E 70
I 70
 * Make an IO register area accessible at physical address physa
E 70
 * by mapping kernel ptes starting at pte.
D 76
 *
 * WE LEAVE ALL NEXI MAPPED; THIS IS PERHAPS UNWISE
 * SINCE MISSING NEXI DONT RESPOND.  BUT THEN AGAIN
 * PRESENT NEXI DONT RESPOND TO ALL OF THEIR ADDRESS SPACE.
E 76
 */
D 5
nxaccess(phys, pte)
	caddr_t phys;
E 5
I 5
D 65
nxaccess(physa, pte)
E 65
I 65
D 76
nxaccess(physa, pte, size)
E 76
I 76
ioaccess(physa, pte, size)
E 76
E 65
D 25
	caddr_t physa;
E 25
I 25
D 70
	struct nexus *physa;
E 70
I 70
	caddr_t physa;
E 70
E 25
E 5
	register struct pte *pte;
I 65
	int size;
E 65
{
D 25
	register int cnt = btop(sizeof (struct nexus));
E 25
I 25
D 65
	register int i = btop(sizeof (struct nexus));
E 65
I 65
D 83
	register int i = btop(size);
E 83
I 83
	register int i = btoc(size);
E 83
E 65
E 25
D 5
	register unsigned v = btop(phys);
E 5
I 5
	register unsigned v = btop(physa);
I 36
D 76
	
	do
		*(int *)pte++ = PG_V|PG_KW|v++;
	while (--i > 0);
	mtpr(TBIA, 0);
}

D 65
ubaaccess(pumem, pte)
E 65
I 65
ubaaccess(pumem, pte, size)
E 65
	caddr_t pumem;
	register struct pte *pte;
I 65
	int size;
E 65
{
D 65
	register int i = 512;
E 65
I 65
	register int i = btop(size);
E 65
	register unsigned v = btop(pumem);
E 76
E 36
E 5
	
	do
		*(int *)pte++ = PG_V|PG_KW|v++;
D 25
	while (--cnt > 0);
E 25
I 25
	while (--i > 0);
E 25
	mtpr(TBIA, 0);
I 48
}

I 65
D 66
#ifndef MAXDUMP
E 65
D 62
#define	DMMIN	32
I 57
#ifndef	DMMAX
E 57
#define	DMMAX	1024
I 57
#endif
E 57
#define	DMTEXT	1024
E 62
#define	MAXDUMP	(10*2048)
I 65
#endif
E 66
E 65
/*
 * Configure swap space and related parameters.
 */
I 87
#ifndef SECSIZE
E 87
swapconf()
{
	register struct swdevt *swp;
I 49
	register int nblks;
E 49

D 87
D 88
	for (swp = swdevt; swp->sw_dev; swp++) {
E 88
I 88
	for (swp = swdevt; swp->sw_dev; swp++)
E 88
E 87
I 87
	for (swp = swdevt; swp->sw_dev; swp++)
E 87
D 49
		if (swp->sw_nblks != 0)
			continue;
E 49
D 66
		if (bdevsw[major(swp->sw_dev)].d_psize)
E 66
I 66
		if (bdevsw[major(swp->sw_dev)].d_psize) {
E 66
D 49
			swp->sw_nblks =
E 49
I 49
			nblks =
E 49
D 66
			  (*bdevsw[major(swp->sw_dev)].d_psize)(swp->sw_dev);
D 49
		if (swp->sw_nblks < 0)
			swp->sw_nblks = 0;
E 49
I 49
		if (swp->sw_nblks == 0 || swp->sw_nblks > nblks)
			swp->sw_nblks = nblks;
E 66
I 66
D 87
D 88
			    (*bdevsw[major(swp->sw_dev)].d_psize)(swp->sw_dev);
E 88
I 88
			  (*bdevsw[major(swp->sw_dev)].d_psize)(swp->sw_dev);
E 88
E 87
I 87
			  (*bdevsw[major(swp->sw_dev)].d_psize)(swp->sw_dev);
E 87
D 85
			if (swp->sw_nblks == 0 || swp->sw_nblks > nblks)
E 85
I 85
			if (nblks != -1 &&
			    (swp->sw_nblks == 0 || swp->sw_nblks > nblks))
E 85
				swp->sw_nblks = nblks;
		}
E 66
E 49
D 87
D 88
	}
	if (!cold)			/* in case called for mba device */
		return;
E 88
E 87
D 63
	if (dumplo == 0)
		dumplo = swdevt[0].sw_nblks - MAXDUMP;
E 63
I 63
D 100
	if (dumplo == 0 && bdevsw[major(dumpdev)].d_psize)
E 100
I 100
	if (dumplo == 0 && dumpdev != NODEV && bdevsw[major(dumpdev)].d_psize)
E 100
D 66
		dumplo = (*bdevsw[major(dumpdev)].d_psize)(dumpdev) - MAXDUMP;
E 66
I 66
		dumplo = (*bdevsw[major(dumpdev)].d_psize)(dumpdev) - physmem;
E 66
E 63
	if (dumplo < 0)
		dumplo = 0;
I 71
}
I 87
#else SECSIZE
swapconf()
{
	register struct swdevt *swp;
	register int nblks;
	register int bsize;
	struct partinfo dpart;

	for (swp = swdevt; swp->sw_dev; swp++)
		if ((nblks = psize(swp->sw_dev, &swp->sw_blksize,
		    &swp->sw_bshift)) != -1 &&
		    (swp->sw_nblks == 0 || swp->sw_nblks > nblks))
			swp->sw_nblks = nblks;

	if (!cold)	/* In case called for addition of another drive */
		return;
	if (dumplo == 0) {
		nblks = psize(dumpdev, (int *)0, (int *)0);
		if (nblks == -1 || nblks < ctod(physmem))
			dumplo = 0;
		else
			dumplo = nblks - ctod(physmem);
	}
}

/*
 * Return size of disk partition in DEV_BSIZE units.
 * If needed, return sector size.
 */
psize(dev, psize, pshift)
	register dev_t dev;
	int *psize, *pshift;
{
	register int nblks, bsize, bshift;
	struct partinfo dpart;

	if ((*bdevsw[major(dev)].d_ioctl)(dev, DIOCGPART,
	    (caddr_t)&dpart, FREAD) == 0)
		bsize = dpart.disklab->d_secsize;
	else
		bsize = DEV_BSIZE;
	if (psize)
		*psize = bsize;
	bshift = 0;
	for (nblks = DEV_BSIZE / bsize; nblks > 1; nblks >>= 1)
		bshift++;
	if (pshift)
		*pshift = bshift;
	nblks = -1;
	if (bdevsw[major(dev)].d_psize) {
		nblks = (*bdevsw[major(dev)].d_psize)(dev);
		if (nblks != -1)
			nblks >>= bshift;
	}
	return (nblks);
}
#endif SECSIZE
E 87

#define	DOSWAP			/* Change swdevt, argdev, and dumpdev too */
u_long	bootdev;		/* should be dev_t, but not until 32 bits */

static	char devname[][2] = {
	'h','p',	/* 0 = hp */
	0,0,		/* 1 = ht */
	'u','p',	/* 2 = up */
	'r','k',	/* 3 = hk */
	0,0,		/* 4 = sw */
	0,0,		/* 5 = tm */
	0,0,		/* 6 = ts */
	0,0,		/* 7 = mt */
	0,0,		/* 8 = tu */
	'r','a',	/* 9 = ra */
	0,0,		/* 10 = ut */
	'r','b',	/* 11 = rb */
	0,0,		/* 12 = uu */
	0,0,		/* 13 = rx */
	'r','l',	/* 14 = rl */
I 97
	0,0,		/* 15 = tmscp */
	'k','r',	/* 16 = ra on kdb50 */
E 97
};

#define	PARTITIONMASK	0x7
#define	PARTITIONSHIFT	3

/*
 * Attempt to find the device from which we were booted.
 * If we can do so, and not instructed not to do so,
 * change rootdev to correspond to the load device.
 */
setroot()
{
D 73
	int  majdev, mindev, unit, part, adaptor, i;
E 73
I 73
D 96
	int  majdev, mindev, unit, part, adaptor;
E 96
I 96
	int  majdev, mindev, unit, part, controller, adaptor;
E 96
E 73
	dev_t temp, orootdev;
	struct swdevt *swp;

D 74
	if (boothowto & RB_DFLTROOT)
E 74
I 74
D 78
	if (boothowto & RB_DFLTROOT || (bootdev & B_MAGICMASK) != B_DEVMAGIC)
E 78
I 78
	if (boothowto & RB_DFLTROOT ||
	    (bootdev & B_MAGICMASK) != (u_long)B_DEVMAGIC)
E 78
E 74
D 79
		return;
E 79
I 79
D 81
		return (0);
E 81
I 81
		return;
E 81
E 79
D 96
	majdev = (bootdev >> B_TYPESHIFT) & B_TYPEMASK;
	if (majdev > sizeof(devname) / sizeof(devname[0]))
E 96
I 96
	majdev = B_TYPE(bootdev);
	if (majdev >= sizeof(devname) / sizeof(devname[0]))
E 96
D 79
		return;
E 79
I 79
D 81
		return (0);
E 81
I 81
		return;
E 81
E 79
D 96
	adaptor = (bootdev >> B_ADAPTORSHIFT) & B_ADAPTORMASK;
	part = (bootdev >> B_PARTITIONSHIFT) & B_PARTITIONMASK;
	unit = (bootdev >> B_UNITSHIFT) & B_UNITMASK;
E 96
I 96
	adaptor = B_ADAPTOR(bootdev);
	controller = B_CONTROLLER(bootdev);
	part = B_PARTITION(bootdev);
	unit = B_UNIT(bootdev);
E 96
I 75
D 79
#if NMBA > 0
E 79
E 75
	if (majdev == 0) {	/* MBA device */
I 79
#if NMBA > 0
E 79
		register struct mba_device *mbap;
I 79
		int mask;
E 79

I 79
/*
 * The MBA number used at boot time is not necessarily the same as the
 * MBA number used by the kernel.  In order to change the rootdev we need to
 * convert the boot MBA number to the kernel MBA number.  The address space
 * for an MBA used by the boot code is 0x20010000 + 0x2000 * MBA_number
 * on the 78? and 86?0, 0xf28000 + 0x2000 * MBA_number on the 750.
 * Therefore we can search the mba_hd table for the MBA that has the physical
 * address corresponding to the boot MBA number.
 */
#define	PHYSADRSHFT	13
#define	PHYSMBAMASK780	0x7
#define	PHYSMBAMASK750	0x3

		switch (cpu) {

		case VAX_780:
		case VAX_8600:
		default:
			mask = PHYSMBAMASK780;
			break;

		case VAX_750:
			mask = PHYSMBAMASK750;
			break;
		}
E 79
		for (mbap = mbdinit; mbap->mi_driver; mbap++)
			if (mbap->mi_alive && mbap->mi_drive == unit &&
D 79
			    mbap->mi_mbanum == adaptor &&
			    mbap->mi_drive == unit)
E 79
I 79
			    (((long)mbap->mi_hd->mh_physmba >> PHYSADRSHFT)
			      & mask) == adaptor)
E 79
			    	break;
		if (mbap->mi_driver == 0)
D 79
			return;
E 79
I 79
D 81
			return (0);
E 81
I 81
			return;
E 81
E 79
		mindev = mbap->mi_unit;
D 75
	} else {
E 75
I 75
D 79
	} else
E 79
I 79
#else
D 81
		return (0);
E 81
I 81
		return;
E 81
E 79
#endif
D 79
	{
E 79
I 79
	} else {
E 79
E 75
		register struct uba_device *ubap;

		for (ubap = ubdinit; ubap->ui_driver; ubap++)
			if (ubap->ui_alive && ubap->ui_slave == unit &&
I 96
			   ubap->ui_ctlr == controller &&
E 96
			   ubap->ui_ubanum == adaptor &&
			   ubap->ui_driver->ud_dname[0] == devname[majdev][0] &&
			   ubap->ui_driver->ud_dname[1] == devname[majdev][1])
			    	break;

		if (ubap->ui_driver == 0)
D 79
			return;
E 79
I 79
D 81
			return (0);
E 81
I 81
			return;
E 81
E 79
		mindev = ubap->ui_unit;
	}
	mindev = (mindev << PARTITIONSHIFT) + part;
	orootdev = rootdev;
	rootdev = makedev(majdev, mindev);
D 72

#ifdef DOSWAP
E 72
	/*
	 * If the original rootdev is the same as the one
	 * just calculated, don't need to adjust the swap configuration.
	 */
	if (rootdev == orootdev)
D 79
		return;
E 79
I 79
D 81
		return (1);
E 81
I 81
		return;
E 81
E 79

I 72
D 74
	printf("Changing root device to %c%c(%d, %d)\n",
		devname[majdev][0], devname[majdev][1], majdev, mindev);
E 74
I 74
	printf("Changing root device to %c%c%d%c\n",
		devname[majdev][0], devname[majdev][1],
		mindev >> PARTITIONSHIFT, part + 'a');
E 74

#ifdef DOSWAP
E 72
	mindev &= ~PARTITIONMASK;
	for (swp = swdevt; swp->sw_dev; swp++) {
		if (majdev == major(swp->sw_dev) &&
		    mindev == (minor(swp->sw_dev) & ~PARTITIONMASK)) {
			temp = swdevt[0].sw_dev;
			swdevt[0].sw_dev = swp->sw_dev;
			swp->sw_dev = temp;
			break;
		}
	}
	if (swp->sw_dev == 0)
D 79
		return;
E 79
I 79
D 81
		return (1);
E 81
I 81
		return;
E 81
E 79

	/*
	 * If argdev and dumpdev were the same as the old primary swap
	 * device, move them to the new primary swap device.
	 */
	if (temp == dumpdev)
		dumpdev = swdevt[0].sw_dev;
	if (temp == argdev)
		argdev = swdevt[0].sw_dev;
#endif
I 79
D 81
	return (1);
E 81
E 79
E 71
D 62
	if (dmmin == 0)
		dmmin = DMMIN;
	if (dmmax == 0)
		dmmax = DMMAX;
	if (dmtext == 0)
		dmtext = DMTEXT;
	if (dmtext > dmmax)
		dmtext = dmmax;
E 62
E 48
}
E 1
