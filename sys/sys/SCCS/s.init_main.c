h45194
s 00004/00000/00306
d D 7.7 02/07/12 15:33:55 msokolov 91 90
c attach ppp interfaces at boot time like sl and lo
e
s 00005/00001/00301
d D 7.6 88/05/26 09:01:30 karels 90 89
c lint
e
s 00002/00013/00300
d D 7.5 87/02/26 18:09:36 karels 89 88
c mv more tahoe stuff to machdep; clk_enable was dup;
c allow root to be mounted readonly
e
s 00021/00018/00292
d D 7.4 87/02/19 17:28:47 karels 88 87
c rearrange initialization of buffers so can be used during configure
e
s 00002/00001/00308
d D 7.3 86/12/06 22:33:55 sam 87 86
c hide tahoe-ism in enablertclock(); call startrtclock so tahoe can set interval timer
e
s 00015/00002/00294
d D 7.2 86/11/03 11:59:26 karels 86 85
c merge in tahoe support
e
s 00001/00001/00295
d D 7.1 86/06/05 00:00:38 mckusick 85 84
c 4.3BSD release version
e
s 00001/00001/00295
d D 6.15 86/02/23 23:08:32 karels 84 83
c lint
e
s 00004/00000/00292
d D 6.14 86/02/11 17:11:15 karels 83 82
c slattach
e
s 00001/00000/00291
d D 6.13 85/11/09 16:37:07 karels 82 81
c keep text free list, cache all texts as sticky
e
s 00000/00006/00291
d D 6.12 85/09/16 20:50:56 karels 81 80
c INET || BBNNET; ctlinput now takes sockaddr as arg
e
s 00009/00002/00288
d D 6.11 85/06/18 18:45:51 karels 80 78
c adjust maxpgio for number of swap devices after counting them,
c using something between what was used and what was attempted in binit
e
s 00006/00005/00285
d R 6.11 85/06/17 22:56:55 karels 79 78
c must calculate maxpgio after binit; nswdev * maxpgio in binit
c is unused
e
s 00007/00001/00283
d D 6.10 85/06/08 14:33:46 mckusick 78 77
c Add copyright
e
s 00003/00005/00281
d D 6.9 85/05/27 19:54:51 karels 77 76
c implement high-water mark on file descriptors in use;
c cleanup old comments
e
s 00007/00007/00279
d D 6.8 85/03/08 15:24:29 mckusick 76 75
c u.u_ap now set up once in process 0; limits are initialized in vminit()
e
s 00001/00006/00285
d D 6.7 85/03/03 16:20:31 mckusick 75 74
c setup of paging constants and p_maxrss is now done in the paging daemon.
e
s 00019/00019/00272
d D 6.6 84/08/29 20:18:22 bloom 74 73
c Change to includes.  no more ../h
e
s 00017/00023/00274
d D 6.5 84/08/01 11:42:54 karels 73 70
c reverse order of process creation, so we don't have to screw with
c mpid and proc order; move default umask into global so can be patched
e
s 00017/00023/00274
d R 6.5 84/08/01 11:17:10 karels 72 70
c reorder initial process creation so we don't have to screw with mpid
c and proc order; put default umask in global for patching
e
s 00017/00023/00274
d R 6.5 84/07/31 17:57:54 karels 71 70
c start init before pagedaemon; put umask in global for patching
e
s 00009/00000/00288
d D 6.4 84/07/08 16:11:58 mckusick 70 69
c rework namei interface to eliminate global variables
e
s 00007/00002/00281
d D 6.3 84/05/22 11:44:02 karels 69 68
c linked lists of active, zombie and free procs; avoid linear proc
c searches wherever possible
e
s 00001/00000/00282
d D 6.2 84/01/03 23:41:43 mckusick 68 67
c add system wide cacheing of path names in namei() (from kre)
e
s 00000/00000/00282
d D 6.1 83/07/29 06:31:46 sam 67 66
c 4.2 distribution
e
s 00000/00027/00282
d D 4.53 83/07/01 02:17:25 sam 66 65
c purge #if sun's
e
s 00002/00001/00307
d D 4.52 83/05/30 17:44:37 sam 65 64
c cleanup
e
s 00000/00018/00308
d D 4.51 83/05/21 15:28:58 sam 64 63
c purge mush
e
s 00007/00003/00319
d D 4.50 83/05/18 01:57:55 sam 63 62
c changes from sun to do swapping on variable sized devices
e
s 00000/00006/00322
d D 4.49 83/04/04 06:12:21 sam 62 61
c no more NOPAGING (yeah)
e
s 00001/00001/00327
d D 4.48 83/03/31 13:46:30 sam 61 60
c add NOGROUP identifier; add groupmember function; tighten group 
c lookup loop to stop at first NOGROUP entry
e
s 00003/00000/00325
d D 4.47 83/03/01 13:28:35 mckusick 60 59
c add startup for profiling clock
e
s 00002/00005/00323
d D 4.46 83/01/23 17:42:49 sam 59 58
c this screws up make depend otherwise
e
s 00007/00001/00321
d D 4.45 83/01/16 15:48:46 mckusick 58 57
c more intelligent buffer pool page allocation
e
s 00018/00007/00304
d D 4.44 82/12/17 11:42:36 sam 57 56
c sun merge
e
s 00013/00003/00298
d D 4.43 82/11/13 22:49:09 sam 56 55
c merge of 4.1b and 4.1c
e
s 00003/00004/00298
d D 4.42 82/11/02 23:38:47 root 55 54
c remove crud
e
s 00030/00002/00272
d D 4.41 82/10/31 14:40:48 root 54 53
c combine with 68k
e
s 00001/00010/00273
d D 4.40 82/10/17 11:28:40 root 53 52
c compute nchrdev nblkdev
e
s 00004/00004/00279
d D 4.39 82/10/10 15:01:56 root 52 51
c split header files over to vax directories
e
s 00003/00001/00280
d D 4.38 82/09/12 02:55:10 root 51 50
c fix limits initialization
e
s 00009/00001/00272
d D 4.37 82/09/06 22:38:20 root 50 49
c more work on timer stuff
e
s 00010/00019/00263
d D 4.36 82/09/04 09:02:10 root 49 48
c limits and clock startup new style
e
s 00002/00000/00280
d D 4.35 82/08/24 15:04:10 root 48 47
c new groups stuff
e
s 00001/00001/00279
d D 4.34 82/08/22 20:29:12 root 47 46
c get rid of some lint
e
s 00021/00000/00259
d D 4.33 82/07/22 13:12:23 kre 46 45
c disc quotas / mush
e
s 00003/00000/00256
d D 4.32 82/07/15 20:07:18 root 45 44
c profiling stuff
e
s 00014/00057/00242
d D 4.31 82/06/14 23:00:02 root 44 43
c fixes to interactions of new fs and buffer cache with partial blocks
c including removal of superblocks from cache and refined readahead and
c brealloc routine
e
s 00014/00000/00285
d D 4.30 82/05/31 17:51:46 mckusick 43 42
c fix time initialization; move bhinit() from bio.c to main.c
e
s 00032/00018/00253
d D 4.29 82/04/19 19:36:05 mckusic 42 41
c merge into new file system
e
s 00001/00001/00270
d D 4.28 82/03/28 14:26:48 sam 41 40
c move pfinit after ifinit so ip can init ifinet (see ip_init)
e
s 00000/00007/00271
d D 4.27 82/03/14 14:11:51 root 40 39
c flush BBN code
e
s 00001/00001/00277
d D 4.26 82/03/11 23:44:33 wnj 39 38
c fix for shannon
e
s 00003/00003/00275
d D 4.25 82/02/15 13:28:31 wnj 38 37
c new multiple-group stuff
e
s 00005/00004/00273
d D 4.24 81/12/09 20:53:24 wnj 37 36
c ifinit and loattach
e
s 00004/00000/00273
d D 4.23 81/12/03 17:27:14 wnj 36 35
c cleanup
e
s 00000/00001/00273
d D 4.22 81/11/18 15:44:59 wnj 35 34
c more cleanup
e
s 00000/00000/00274
d D 4.21 81/11/16 14:20:42 wnj 34 33
c lint
e
s 00001/00001/00273
d D 4.20 81/11/14 16:43:32 wnj 33 32
c before header overlay
e
s 00009/00004/00265
d D 4.19 81/11/08 16:53:40 wnj 32 31
c add mbinit, prinit, remove ptinit
e
s 00001/00001/00268
d D 4.18 81/08/24 12:37:39 root 31 30
c change netinit() to netmain()
e
s 00002/00000/00267
d D 4.17 81/08/13 11:06:29 ecc 30 29
c interleave swap fix
e
s 00007/00001/00260
d D 4.16 81/05/12 17:18:45 root 29 28
c add tcp/ip
e
s 00001/00000/00260
d D 4.15 81/04/28 02:53:51 root 28 27
c port init call
e
s 00005/00002/00255
d D 4.14 81/04/23 02:59:30 wnj 27 26
c call setupclock
e
s 00001/00000/00256
d D 4.13 81/04/13 20:34:16 root 26 25
c maxrss stuff
e
s 00001/00001/00255
d D 4.12 81/03/09 01:47:38 wnj 25 24
c lint and a few minor fixed
e
s 00004/00000/00252
d D 4.11 81/03/03 11:06:40 wnj 24 23
c put root name in s_fsmnt
e
s 00005/00017/00247
d D 4.10 81/02/27 17:44:57 wnj 23 22
c dynamic allocation kernel
e
s 00008/00007/00256
d D 4.9 81/02/27 02:39:32 wnj 22 21
c before compiling dynamic version
e
s 00023/00000/00240
d D 4.8 81/02/26 23:57:32 wnj 21 20
c add cinit
e
s 00000/00002/00240
d D 4.7 81/02/26 04:24:48 wnj 20 19
c FASTVAX xxx or -> UNFAST
e
s 00010/00008/00232
d D 4.6 81/02/16 20:48:52 wnj 19 18
c red zone for kernel stack
e
s 00002/00008/00238
d D 4.5 81/02/15 12:21:12 kre 18 17
c get rid of d_tab
e
s 00000/00001/00246
d D 4.4 81/02/08 18:34:44 wnj 17 16
c first working autoconf version
e
s 00013/00011/00234
d D 4.3 81/01/31 23:24:15 wnj 16 15
c changes for array of buffer queues
e
s 00001/00001/00244
d D 4.2 80/11/09 23:34:52 bill 15 14
c function results (void)'ed for minor lint
e
s 00000/00000/00245
d D 4.1 80/11/09 17:32:09 bill 14 13
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00001/00001/00244
d D 3.13 80/09/16 17:10:51 bill 13 12
c s/limit/vlimit
e
s 00013/00009/00232
d D 3.12 80/09/14 13:09:09 bill 12 11
c fixup limit initialization (1/2M stack, max possible data) and clock init
e
s 00003/00002/00238
d D 3.11 80/08/27 08:36:24 bill 11 10
c buffers allocated in sysmap
e
s 00000/00000/00240
d D 3.10 80/07/16 13:44:07 bill 10 9
c limit code
e
s 00001/00000/00239
d D 3.9 80/07/12 19:17:12 bill 9 8
c include vlimit.h for INFINITY
e
s 00003/00000/00236
d D 3.8 80/07/12 17:45:54 bill 8 7
c initialize limits
e
s 00002/00000/00234
d D 3.7 80/07/06 11:20:39 bill 7 6
c first cached version
e
s 00014/00000/00220
d D 3.6 80/06/24 19:28:31 bill 6 5
c no swplo
e
s 00001/00001/00219
d D 3.5 80/06/07 02:46:07 bill 5 4
c %H%->%G%
e
s 00001/00001/00219
d D 3.4 80/05/08 10:29:39 bill 4 3
c VOID=>void
e
s 00001/00001/00219
d D 3.3 80/04/30 17:17:04 bill 3 2
c get rid of BSLOP
e
s 00001/00000/00219
d D 3.2 80/04/13 12:36:13 bill 2 1
c call bhinit
e
s 00219/00000/00000
d D 3.1 80/04/09 16:03:25 bill 1 0
c date and time created 80/04/09 16:03:25 by bill
e
u
U
f b 
t
T
I 1
D 5
/*	%M%	%I%	%H%	*/
E 5
I 5
D 25
/*	%M%	%I%	%G%	*/
E 25
I 25
D 78
/*	%M%	%I%	%E%	*/
E 78
I 78
/*
D 85
 * Copyright (c) 1982 Regents of the University of California.
E 85
I 85
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 85
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 78
E 25
E 5

I 57
#include "../machine/pte.h"

E 57
D 74
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
I 49
#include "../h/kernel.h"
E 49
D 42
#include "../h/filsys.h"
E 42
I 42
#include "../h/fs.h"
E 42
#include "../h/mount.h"
#include "../h/map.h"
#include "../h/proc.h"
#include "../h/inode.h"
#include "../h/seg.h"
#include "../h/conf.h"
#include "../h/buf.h"
D 52
#include "../h/mtpr.h"
E 52
D 57
#include "../h/pte.h"
E 57
D 49
#include "../h/clock.h"
E 49
#include "../h/vm.h"
#include "../h/cmap.h"
I 7
#include "../h/text.h"
I 9
D 13
#include "../h/limit.h"
E 13
I 13
D 49
#include "../h/vlimit.h"
E 49
I 23
#include "../h/clist.h"
E 74
I 74
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "fs.h"
#include "mount.h"
#include "map.h"
#include "proc.h"
#include "inode.h"
#include "seg.h"
#include "conf.h"
#include "buf.h"
#include "vm.h"
#include "cmap.h"
#include "text.h"
#include "clist.h"
E 74
I 32
D 81
#ifdef INET
E 81
D 35
#include "../h/protocol.h"
E 35
D 74
#include "../h/protosw.h"
E 74
I 74
#include "protosw.h"
E 74
D 81
#endif
E 81
I 46
D 74
#include "../h/quota.h"
E 74
I 74
#include "quota.h"
I 89
#include "reboot.h"
E 89
E 74
E 46
E 32
E 23
E 13
E 9
E 7
D 59

I 57
#ifdef sun
#include "../sun/reg.h"
#include "../sun/cpu.h"
#endif
E 59
I 59
#include "../machine/reg.h"
#include "../machine/cpu.h"
E 59

E 57
I 52
D 73
extern	struct user u;		/* have to declare it somewhere! */
E 73
I 73
int	cmask = CMASK;
E 73
E 52
/*
 * Initialization code.
 * Called from cold start routine as
 * soon as a stack and segmentation
 * have been established.
 * Functions:
 *	clear and free user core
 *	turn on clock
 *	hand craft 0th process
 *	call all initialization routines
 *	fork - process 0 to schedule
D 77
 *	     - process 2 to page out
E 77
 *	     - process 1 execute bootstrap
D 77
 *
D 54
 * loop at loc 13 (0xd) in user mode -- /etc/init
E 54
I 54
D 56
 * loop at loc something in user mode -- /etc/init
E 56
I 56
 * loop at loc 13 (0xd) in user mode -- /etc/init
E 56
E 54
 *	cannot be executed.
E 77
I 77
 *	     - process 2 to page out
E 77
 */
I 54
D 66
#ifdef vax
E 66
E 54
main(firstaddr)
I 54
	int firstaddr;
D 66
#endif
#ifdef sun
main(regs)
	struct regs regs;
#endif
E 66
E 54
{
I 8
	register int i;
I 19
	register struct proc *p;
I 42
D 44
	struct fs *fsp;
E 44
I 44
	struct fs *fs;
I 56
	int s;
E 56
E 44
E 42
E 19
E 8

D 17
	cpusid = mfpr(SID);		/* get system identification */
E 17
D 20
#ifdef FASTVAX
E 20
	rqinit();
I 37
#include "loop.h"
I 54
D 66
#ifdef vax
E 66
E 54
D 38
#if NLOOP > 0
	loattach();			/* XXX */
#endif
E 38
E 37
D 20
#endif
E 20
	startup(firstaddr);
I 54
D 66
#endif
#ifdef sun
	startup();
#endif
E 66
E 54
D 27
	if (lotsfree == 0)
		lotsfree = LOTSFREE;
E 27

	/*
	 * set up system process 0 (swapper)
	 */
D 19

	proc[0].p_p0br = (struct pte *)mfpr(P0BR);
	proc[0].p_szpt = 1;
	proc[0].p_addr = uaddr(&proc[0]);
	proc[0].p_stat = SRUN;
	proc[0].p_flag |= SLOAD|SSYS;
	proc[0].p_nice = NZERO;
	u.u_procp = &proc[0];
E 19
I 19
	p = &proc[0];
I 86
D 89
#if defined(tahoe)
#ifndef lint
#define	initkey(which, p, index) \
    which/**/_cache[index] = 1, which/**/_cnt[index] = 1; \
    p->p_/**/which = index;
	initkey(ckey, p, MAXCKEY);
	initkey(dkey, p, MAXDKEY);
#endif
#endif
E 89
E 86
D 52
	p->p_p0br = (struct pte *)mfpr(P0BR);
E 52
I 52
	p->p_p0br = u.u_pcb.pcb_p0br;
E 52
	p->p_szpt = 1;
	p->p_addr = uaddr(p);
	p->p_stat = SRUN;
	p->p_flag |= SLOAD|SSYS;
	p->p_nice = NZERO;
	setredzone(p->p_addr, (caddr_t)&u);
	u.u_procp = p;
I 70
D 86
#ifdef vax
E 86
	/*
D 76
	 * This assumes that the u. area is always mapped 
	 * to the same physical address. Otherwise must be
E 76
I 76
	 * These assume that the u. area is always mapped 
	 * to the same virtual address. Otherwise must be
E 76
	 * handled when copying the u. area in newproc().
	 */
	u.u_nd.ni_iov = &u.u_nd.ni_iovec;
I 76
	u.u_ap = u.u_arg;
E 76
D 86
#endif
E 86
	u.u_nd.ni_iovcnt = 1;
I 86

E 86
E 70
I 54
D 66
#ifdef sun
D 57
	u.u_ar0 = &regs.r0;
E 57
I 57
	u.u_ar0 = &regs.r_r0;
E 57
#endif
E 66
E 54
E 19
D 73
	u.u_cmask = CMASK;
E 73
I 73
	u.u_cmask = cmask;
I 77
	u.u_lastfile = -1;
E 77
E 73
I 48
	for (i = 1; i < NGROUPS; i++)
D 61
		u.u_groups[i] = -1;
E 61
I 61
		u.u_groups[i] = NOGROUP;
E 61
E 48
I 8
D 49
	for (i = 1; i < sizeof(u.u_limit)/sizeof(u.u_limit[0]); i++)
D 12
		u.u_limit[i] = INFINITY;
E 12
I 12
		switch (i) {

		case LIM_STACK:
			u.u_limit[i] = 512*1024;
			continue;
		case LIM_DATA:
			u.u_limit[i] = ctob(MAXDSIZ);
			continue;
		default:
			u.u_limit[i] = INFINITY;
			continue;
		}
I 26
	p->p_maxrss = INFINITY/NBPG;
E 49
I 49
	for (i = 0; i < sizeof(u.u_rlimit)/sizeof(u.u_rlimit[0]); i++)
		u.u_rlimit[i].rlim_cur = u.u_rlimit[i].rlim_max = 
		    RLIM_INFINITY;
D 76
	u.u_rlimit[RLIMIT_STACK].rlim_cur = 512*1024;
D 51
	u.u_rlimit[RLIMIT_DATA].rlim_cur = ctob(MAXDSIZ);
E 51
I 51
D 69
	u.u_rlimit[RLIMIT_STACK].rlim_max = ctob(MAXDSIZ);
E 69
I 69
	u.u_rlimit[RLIMIT_STACK].rlim_max = ctob(MAXSSIZ);
E 69
	u.u_rlimit[RLIMIT_DATA].rlim_max =
	    u.u_rlimit[RLIMIT_DATA].rlim_cur = ctob(MAXDSIZ);
E 51
D 75
	p->p_maxrss = RLIM_INFINITY/NBPG;
E 75
I 75
	/* p_maxrss is set later, in pageout (process 2) */
E 76
I 76
	/*
D 80
	 * Virtual memory limits get set in vminit().
E 80
I 80
	 * configure virtual memory system,
	 * set vm rlimits
E 80
	 */
	vminit();
I 80

E 80
E 76
E 75
E 49
I 46
D 69
#ifdef QUOTA
E 69
I 69
#if defined(QUOTA)
E 69
	qtinit();
	p->p_quota = u.u_quota = getquota(0, 0, Q_NDQ);
#endif
I 86
D 87
#if defined(vax)
E 87
E 86
E 46
E 26
E 12
E 8
D 49
	clkstart();
E 49
I 49
D 55
	clockstart();
E 55
I 55
	startrtclock();
I 87
#if defined(vax)
E 87
I 60
D 65
#ifdef KGCLOCK
E 65
I 65
#include "kg.h"
#if NKG > 0
E 65
	startkgclock();
#endif
I 86
#endif
E 86
E 60
E 55
E 49

	/*
D 32
	 * Initialize devices and
	 * set up 'known' i-nodes
E 32
I 32
	 * Initialize tables, protocols, and set up well-known inodes.
E 32
	 */
D 32

E 32
I 32
	mbinit();
I 39
D 77
	cinit();			/* needed by dmc-11 driver */
E 77
I 77
	cinit();
I 83
#include "sl.h"
#if NSL > 0
	slattach();			/* XXX */
#endif
I 91
#include "ppp.h"
#if NPPP > 0
	pppattach();			/* XXX */
#endif
E 91
E 83
E 77
E 39
D 81
#ifdef INET
E 81
D 33
	prinit();
E 33
I 33
D 41
	pfinit();
E 41
I 38
#if NLOOP > 0
	loattach();			/* XXX */
#endif
I 56
	/*
	 * Block reception of incoming packets
	 * until protocols have been initialized.
	 */
	s = splimp();
E 56
E 38
E 33
D 37
#endif
I 36
#include "lo.h"
#if NLOOP > 0
	loattach();
E 37
I 37
	ifinit();
I 41
D 54
	pfinit();			/* must follow interfaces */
E 54
E 41
E 37
D 81
#endif
E 81
I 54
	domaininit();
I 56
D 81
#ifdef INET
E 81
	splx(s);
D 81
#endif
E 81
I 69
	pqinit();
I 82
	xinit();
E 82
E 69
E 56
E 54
E 36
E 32
	ihinit();
I 2
D 88
	bhinit();
E 2
D 39
	cinit();
E 39
	binit();
	bswinit();
E 88
I 88
	swapinit();
E 88
I 68
	nchinit();
E 68
I 45
#ifdef GPROF
	kmstartup();
#endif
E 45
D 44
	iinit();
I 28
D 32
	ptinit();
E 32
E 28
D 42
	rootdir = iget(rootdev, (ino_t)ROOTINO);
E 42
I 42
	fsp = getfs(rootdev);
	rootdir = iget(rootdev, fsp, (ino_t)ROOTINO);
E 42
	rootdir->i_flag &= ~ILOCK;
D 42
	u.u_cdir = iget(rootdev, (ino_t)ROOTINO);
E 42
I 42
	u.u_cdir = iget(rootdev, fsp, (ino_t)ROOTINO);
E 42
	u.u_cdir->i_flag &= ~ILOCK;
E 44
I 44

D 47
	fs = mountfs(rootdev, 0, 0);
E 47
I 47
D 89
	fs = mountfs(rootdev, 0, (struct inode *)0);
E 89
I 89
	fs = mountfs(rootdev, boothowto & RB_RDONLY, (struct inode *)0);
E 89
E 47
	if (fs == 0)
		panic("iinit");
	bcopy("/", fs->fs_fsmnt, 2);
I 50

D 55
/* initialize wall clock */
E 50
D 49
	clkinit(fs->fs_time);
	bootime = time;
E 49
I 49
	clockinit(fs->fs_time);
E 55
I 55
	inittodr(fs->fs_time);
E 55
	boottime = time;
E 49

I 50
/* kick off timeout driven events by calling first time */
	roundrobin();
	schedcpu();
	schedpaging();

/* set up the root file system */
E 50
	rootdir = iget(rootdev, fs, (ino_t)ROOTINO);
	iunlock(rootdir);
	u.u_cdir = iget(rootdev, fs, (ino_t)ROOTINO);
	iunlock(u.u_cdir);
D 50

E 50
E 44
	u.u_rdir = NULL;
I 50

E 50
	u.u_dmap = zdmap;
	u.u_smap = zdmap;
I 27
D 75

	/*
	 * Set the scan rate and other parameters of the paging subsystem.
	 */
	setupclock();
E 75
E 27

I 87
	enablertclock();		/* enable realtime clock interrupts */
E 87
I 86
D 89
#if defined(tahoe)
	clk_enable = 1;			/* enable clock interrupt */
#endif
E 89
E 86
	/*
I 73
	 * make init process
	 */

	proc[0].p_szpt = CLSIZE;
	if (newproc(0)) {
		expand(clrnd((int)btoc(szicode)), 0);
D 84
		(void) swpexpand(u.u_dsize, 0, &u.u_dmap, &u.u_smap);
E 84
I 84
		(void) swpexpand(u.u_dsize, (size_t)0, &u.u_dmap, &u.u_smap);
E 84
		(void) copyout((caddr_t)icode, (caddr_t)0, (unsigned)szicode);
		/*
		 * Return goes to loc. 0 of user init
		 * code just copied out.
		 */
		return;
	}
	/*
E 73
	 * make page-out daemon (process 2)
D 22
	 * the daemon has ctopt(NSWBUF*CLSIZE*KLMAX) pages of page
E 22
I 22
	 * the daemon has ctopt(nswbuf*CLSIZE*KLMAX) pages of page
E 22
	 * table so that it can map dirty pages into
	 * its address space during asychronous pushes.
	 */
D 29

E 29
D 73
	mpid = 1;
E 73
D 22
	proc[0].p_szpt = clrnd(ctopt(NSWBUF*CLSIZE*KLMAX + UPAGES));
E 22
I 22
	proc[0].p_szpt = clrnd(ctopt(nswbuf*CLSIZE*KLMAX + UPAGES));
E 22
D 73
	proc[1].p_stat = SZOMB;		/* force it to be in proc slot 2 */
I 69
	p = freeproc;
	freeproc = p->p_nxt;
E 73
E 69
	if (newproc(0)) {
		proc[2].p_flag |= SLOAD|SSYS;
D 22
		proc[2].p_dsize = u.u_dsize = NSWBUF*CLSIZE*KLMAX; 
E 22
I 22
		proc[2].p_dsize = u.u_dsize = nswbuf*CLSIZE*KLMAX; 
I 54
D 62
#ifdef NOPAGING
		for (;;)
			sleep((caddr_t)&u, PSLEP);
I 57
		/*NOTREACHED*/
E 57
#else
E 62
E 54
E 22
		pageout();
I 54
D 55
#endif
E 55
		/*NOTREACHED*/
I 55
D 62
#endif
E 62
E 55
E 54
	}

	/*
D 73
	 * make init process and
E 73
	 * enter scheduling loop
	 */
D 73

	mpid = 0;
	proc[1].p_stat = 0;
	proc[0].p_szpt = CLSIZE;
I 69
	p->p_nxt = freeproc;
	freeproc = p;
E 69
	if (newproc(0)) {
I 54
D 66
#ifdef vax
E 66
E 54
D 52
		expand(clrnd((int)btoc(szicode)), P0BR);
E 52
I 52
		expand(clrnd((int)btoc(szicode)), 0);
E 52
I 7
D 15
		swpexpand(u.u_dsize, 0, &u.u_dmap, &u.u_smap);
E 15
I 15
		(void) swpexpand(u.u_dsize, 0, &u.u_dmap, &u.u_smap);
E 15
E 7
D 4
		VOID copyout((caddr_t)icode, (caddr_t)0, (unsigned)szicode);
E 4
I 4
		(void) copyout((caddr_t)icode, (caddr_t)0, (unsigned)szicode);
I 54
D 66
#endif
#ifdef sun
		icode();
		usetup();
D 63
		regs.r_context = u.u_pcb.pcb_ctx->ctx_context;
E 63
I 63
		regs.r_context = u.u_procp->p_ctx->ctx_context;
E 63
#endif
E 66
E 54
E 4
		/*
		 * Return goes to loc. 0 of user init
		 * code just copied out.
		 */
		return;
	}
E 73
I 46
D 64
#ifdef MUSH
	/*
	 * start MUSH daemon
	 *			pid == 3
	 */
	if (newproc(0)) {
I 57
#ifdef vax
E 57
D 52
		expand(clrnd((int)btoc(szmcode)), P0BR);
E 52
I 52
		expand(clrnd((int)btoc(szmcode)), 0);
E 52
		(void) swpexpand(u.u_dsize, 0, &u.u_dmap, &u.u_smap);
		(void) copyout((caddr_t)mcode, (caddr_t)0, (unsigned)szmcode);
		/*
		 * Return goes to loc. 0 of user mush
		 * code just copied out.
		 */
		return;
I 57
#endif
E 57
	}
#endif
E 64
E 46
I 29
D 40

#ifdef BBNNET 
	/*
	 * Initialize bbn network.
	 */
D 31
	netinit();
E 31
I 31
	netmain();
E 31
#endif BBNNET
E 40
E 29
	proc[0].p_szpt = 1;
	sched();
D 44
}

/*
 * iinit is called once (from main)
 * very early in initialization.
 * It reads the root's super block
 * and initializes the current date
 * from the last modified date.
 *
 * panic: iinit -- cannot read the super
 * block. Usually because of an IO error.
 */
iinit()
{
D 18
	register struct buf *cp, *bp;
E 18
I 18
	register struct buf *bp;
E 18
D 42
	register struct filsys *fp;
E 42
I 42
	register struct fs *fp;
E 42
I 24
	register int i;
I 42
	int blks;
E 42
E 24
D 12
	register unsigned i, j;
E 12

	(*bdevsw[major(rootdev)].d_open)(rootdev, 1);
D 42
	bp = bread(rootdev, SUPERB);
E 42
I 42
	bp = bread(rootdev, SBLOCK, SBSIZE);
E 42
D 16
	cp = geteblk();
E 16
	if(u.u_error)
		panic("iinit");
D 16
	bcopy(bp->b_un.b_addr, cp->b_un.b_addr, sizeof(struct filsys));
E 16
I 16
	bp->b_flags |= B_LOCKED;		/* block can never be re-used */
E 16
	brelse(bp);
D 16
	mount[0].m_bufp = cp;
E 16
	mount[0].m_dev = rootdev;
D 16
	fp = cp->b_un.b_filsys;
E 16
I 16
	mount[0].m_bufp = bp;
D 42
	fp = bp->b_un.b_filsys;
E 16
	fp->s_flock = 0;
	fp->s_ilock = 0;
	fp->s_ronly = 0;
	fp->s_lasti = 1;
	fp->s_nbehind = 0;
I 24
	fp->s_fsmnt[0] = '/';
	for (i = 1; i < sizeof(fp->s_fsmnt); i++)
		fp->s_fsmnt[i] = 0;
E 24
D 12
	/* on boot, read VAX TODR register (GMT 10 ms.
	*	clicks into current year) and set software time
	*	in 'int time' (GMT seconds since year YRREF)
	*/
	for (i = 0 , j = YRREF ; j < YRCURR ; j++)
		i += (SECYR + (j%4?0:SECDAY)) ;
	time = udiv(mfpr(TODR),100) + i ;
E 12
I 12
	clkinit(fp->s_time);
E 12
	bootime = time;
E 42
I 42
	fp = bp->b_un.b_fs;
	if (fp->fs_magic != FS_MAGIC)
		panic("root bad magic number");
	if (fp->fs_bsize > MAXBSIZE)
		panic("root fs_bsize too big");
	fp->fs_ronly = 0;
	fp->fs_fsmnt[0] = '/';
	for (i = 1; i < sizeof(fp->fs_fsmnt); i++)
		fp->fs_fsmnt[i] = 0;
	blks = howmany(fp->fs_cssize, fp->fs_fsize);
	for (i = 0; i < blks; i += fp->fs_frag) {
		bp = bread(rootdev, fsbtodb(fp, fp->fs_csaddr + i),
		    blks - i < fp->fs_frag ?
			(blks - i) * fp->fs_fsize :
			fp->fs_bsize);
		if (u.u_error)
			panic("root can't read csum");
		fp->fs_csp[i / fp->fs_frag] = bp->b_un.b_cs;
		bp->b_flags |= B_LOCKED;
		brelse(bp);
	}
I 43
	clkinit(fp->fs_time);
	bootime = time;
E 44
}

/*
 * Initialize hash links for buffers.
 */
bhinit()
{
	register int i;
	register struct bufhd *bp;

	for (bp = bufhash, i = 0; i < BUFHSZ; i++, bp++)
		bp->b_forw = bp->b_back = (struct buf *)bp;
E 43
E 42
}

/*
D 23
 * This is the set of buffers proper, whose heads
 * were declared in buf.h.  There can exist buffer
 * headers not pointing here that are used purely
 * as arguments to the I/O routines to describe
 * I/O to be done-- e.g. swap headers swbuf[] for
 * swapping.
I 11
 *
 * These are actually allocated kernel map slots and space is
 * allocated in locore.s for them.
E 11
 */
D 3
char	buffers[NBUF][BSIZE+BSLOP];
E 3
I 3
char	buffers[NBUF][BSIZE];
E 3

/*
E 23
 * Initialize the buffer I/O system by freeing
 * all buffers and setting all device buffer lists to empty.
D 11
 *
 * SHOULD USE MEMALL HERE!!!
E 11
 */
binit()
{
D 53
	register struct buf *bp;
	register struct buf *dp;
E 53
I 53
	register struct buf *bp, *dp;
E 53
	register int i;
D 53
	struct bdevsw *bdp;
E 53
I 6
D 88
	struct swdevt *swp;
E 88
I 58
	int base, residual;
E 58
E 6

D 16
	bfreelist.b_forw = bfreelist.b_back =
	    bfreelist.av_forw = bfreelist.av_back = &bfreelist;
E 16
I 16
	for (dp = bfreelist; dp < &bfreelist[BQUEUES]; dp++) {
		dp->b_forw = dp->b_back = dp->av_forw = dp->av_back = dp;
		dp->b_flags = B_HEAD;
	}
I 58
	base = bufpages / nbuf;
	residual = bufpages % nbuf;
E 58
D 56
	dp--;				/* dp = &bfreelist[BQUEUES-1]; */
E 56
I 56
D 57
	dp = &bfreelist[BQ_AGE];
E 57
E 56
E 16
D 23
	for (i=0; i<NBUF; i++) {
E 23
I 23
D 42
	for (i=0; i<nbuf; i++) {
E 42
I 42
	for (i = 0; i < nbuf; i++) {
E 42
E 23
		bp = &buf[i];
		bp->b_dev = NODEV;
I 56
		bp->b_bcount = 0;
I 57
D 66
#ifndef sun
E 66
E 57
E 56
D 23
		bp->b_un.b_addr = buffers[i];
E 23
I 23
D 42
		bp->b_un.b_addr = buffers + i * BSIZE;
E 42
I 42
		bp->b_un.b_addr = buffers + i * MAXBSIZE;
D 56
		bp->b_bcount = MAXBSIZE;
E 56
I 56
D 58
		bp->b_bufsize = 2 * CLBYTES;
E 58
I 58
		if (i < residual)
			bp->b_bufsize = (base + 1) * CLBYTES;
		else
			bp->b_bufsize = base * CLBYTES;
E 58
E 56
E 42
E 23
D 16
		bp->b_back = &bfreelist;
		bp->b_forw = bfreelist.b_forw;
		bfreelist.b_forw->b_back = bp;
		bfreelist.b_forw = bp;
		bp->b_flags = B_BUSY;
E 16
I 16
D 57
		bp->b_back = dp;
		bp->b_forw = dp->b_forw;
		dp->b_forw->b_back = bp;
		dp->b_forw = bp;
E 57
I 57
		binshash(bp, &bfreelist[BQ_AGE]);
D 66
#else
		bp->b_un.b_addr = (char *)0;
		bp->b_bufsize = 0;
		binshash(bp, &bfreelist[BQ_EMPTY]);
#endif
E 66
E 57
		bp->b_flags = B_BUSY|B_INVAL;
E 16
		brelse(bp);
	}
I 88
}

/*
 * Set up swap devices.
 * Initialize linked list of free swap
 * headers. These do not actually point
 * to buffers, but rather to pages that
 * are being swapped in and out.
 */
swapinit()
{
	register int i;
	register struct buf *sp = swbuf;
	struct swdevt *swp;
I 90
	int error;
E 90

E 88
D 18
	for (bdp = bdevsw; bdp->d_open; bdp++) {
		dp = bdp->d_tab;
		if(dp) {
			dp->b_forw = dp;
			dp->b_back = dp;
		}
E 18
I 18
D 53
	for (bdp = bdevsw; bdp->d_open; bdp++)
E 18
		nblkdev++;
E 53
D 18
	}
E 18
I 6
	/*
	 * Count swap devices, and adjust total swap space available.
D 88
	 * Some of this space will not be available until a vswapon()
E 88
I 88
	 * Some of this space will not be available until a swapon()
E 88
	 * system is issued, usually when the system goes multi-user.
	 */
	nswdev = 0;
D 63
	for (swp = swdevt; swp->sw_dev; swp++)
E 63
I 63
	nswap = 0;
	for (swp = swdevt; swp->sw_dev; swp++) {
E 63
		nswdev++;
I 63
		if (swp->sw_nblks > nswap)
			nswap = swp->sw_nblks;
	}
E 63
	if (nswdev == 0)
D 88
		panic("binit");
E 88
I 88
		panic("swapinit");
E 88
I 30
	if (nswdev > 1)
D 63
		nswap = (nswap/DMMAX)*DMMAX;
E 63
I 63
		nswap = ((nswap + dmmax - 1) / dmmax) * dmmax;
E 63
E 30
	nswap *= nswdev;
D 80
	maxpgio *= nswdev;
E 80
I 80
	/*
	 * If there are multiple swap areas,
	 * allow more paging operations per second.
	 */
	if (nswdev > 1)
		maxpgio = (maxpgio * (2 * nswdev - 1)) / 2;
E 80
D 90
	swfree(0);
E 90
I 90
	if (error = swfree(0)) {
		printf("swfree errno %d\n", error);	/* XXX */
		panic("swapinit swfree 0");
	}
E 90
E 6
D 88
}
E 88

D 88
/*
 * Initialize linked list of free swap
 * headers. These do not actually point
 * to buffers, but rather to pages that
 * are being swapped in and out.
 */
bswinit()
{
	register int i;
I 22
D 23
	register struct buf *sp
E 23
I 23
	register struct buf *sp = swbuf;
E 23
E 22

E 88
I 88
	/*
	 * Now set up swap buffer headers.
	 */
E 88
D 22
	bswlist.av_forw = &swbuf[0];
	for (i=0; i<NSWBUF-1; i++)
		swbuf[i].av_forw = &swbuf[i+1];
	swbuf[NSWBUF-1].av_forw = NULL;
E 22
I 22
	bswlist.av_forw = sp;
D 23
	for (i=0; i<NSWBUF-1; i++, sp++)
E 23
I 23
	for (i=0; i<nswbuf-1; i++, sp++)
E 23
		sp->av_forw = sp+1;
	sp->av_forw = NULL;
E 22
}
I 21

/*
 * Initialize clist by freeing all character blocks, then count
 * number of character devices. (Once-only routine)
 */
cinit()
{
	register int ccp;
	register struct cblock *cp;
D 53
	register struct cdevsw *cdp;
E 53

	ccp = (int)cfree;
	ccp = (ccp+CROUND) & ~CROUND;
	for(cp=(struct cblock *)ccp; cp < &cfree[nclist-1]; cp++) {
		cp->c_next = cfreelist;
		cfreelist = cp;
		cfreecount += CBSIZE;
	}
D 53
	ccp = 0;
	for(cdp = cdevsw; cdp->d_open; cdp++)
		ccp++;
	nchrdev = ccp;
E 53
}
E 21
E 1
