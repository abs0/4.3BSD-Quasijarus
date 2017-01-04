h22767
s 00003/00003/00282
d D 7.4 04/01/08 05:35:47 msokolov 66 65
c add sigemu syscall
e
s 00001/00001/00284
d D 7.3 87/07/10 16:59:14 mckusick 65 64
c syscall #65 changes from mremap to msync
e
s 00001/00001/00284
d D 7.2 87/01/15 16:36:49 bostic 64 63
c getpagesize gets 0 args.
e
s 00001/00001/00284
d D 7.1 86/06/05 00:00:58 mckusick 63 62
c 4.3BSD release version
e
s 00008/00001/00277
d D 6.10 86/02/04 17:22:07 karels 62 61
c 20 more isn't enough for SUN...
e
s 00008/00007/00270
d D 6.9 86/02/02 21:24:44 karels 61 60
c add comment reserving 151-170 for vendors; minor cleanups
e
s 00002/00002/00275
d D 6.8 85/11/28 10:52:52 bloom 60 59
c gethostid and sethostid and wrong number of args
e
s 00007/00001/00270
d D 6.7 85/06/08 14:34:10 mckusick 59 58
c Add copyright
e
s 00002/00002/00269
d D 6.6 85/03/11 16:14:50 mckusick 58 57
c formalize sigreturn() into a real system call
e
s 00002/00002/00269
d D 6.5 85/01/11 14:07:41 karels 57 56
c signal leaves again
e
s 00006/00001/00265
d D 6.4 84/11/14 10:05:17 karels 56 55
c adjtime
e
s 00002/00002/00264
d D 6.3 84/08/29 20:18:32 bloom 55 54
c Change to includes.  no more ../h
e
s 00002/00002/00264
d D 6.2 84/08/24 16:55:59 mckusick 54 53
c add `signal' as a system call
e
s 00000/00000/00266
d D 6.1 83/08/17 10:07:55 sam 53 52
c 4.2 distribution
e
s 00001/00001/00265
d D 4.47 83/08/17 10:06:31 sam 52 50
c from robert; flock has 2 params
e
s 00000/00000/00266
d R 6.1 83/07/29 06:31:54 sam 51 50
c 4.2 distribution
e
s 00002/00002/00264
d D 4.46 83/07/25 21:53:24 sam 50 49
c getpeer
e
s 00017/00017/00249
d D 4.45 83/06/30 01:12:03 sam 49 48
c cpp botch
e
s 00001/00001/00265
d D 4.44 83/06/27 22:09:47 sam 48 47
c from rws@mit-xx
e
s 00033/00027/00233
d D 4.43 83/06/21 20:35:27 sam 47 46
c change NOCOMPAT to COMPAT and make it work
e
s 00002/00002/00258
d D 4.42 83/06/13 22:40:29 sam 46 45
c lint
e
s 00002/00002/00258
d D 4.41 83/06/12 14:28:20 sam 45 44
c put flock where it belongs
e
s 00004/00009/00256
d D 4.40 83/06/02 15:56:28 sam 44 43
c new signals
e
s 00011/00013/00254
d D 4.39 83/05/27 12:45:44 sam 43 42
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00000/00014/00267
d D 4.38 83/05/21 15:29:40 sam 42 41
c purge mush; make quotas permanent
e
s 00004/00010/00277
d D 4.37 83/05/10 15:16:45 sam 41 40
c swapon, swapoff, and unmount aren't going to be implemented, 
c so purge the hooks from the system
e
s 00003/00000/00284
d D 4.36 83/03/20 17:40:45 sam 40 39
c reserve slots for quota calls
e
s 00003/00003/00281
d D 4.35 83/03/19 14:11:05 sam 39 38
c replace socketaddr with getsockname
e
s 00007/00007/00277
d D 4.34 83/01/13 17:25:19 sam 38 37
c socket options move to separate sys call
e
s 00002/00002/00282
d D 4.33 82/12/28 19:49:53 sam 37 36
c new wait (returns rusage)
e
s 00006/00004/00278
d D 4.32 82/12/23 15:58:04 sam 36 35
c make stat backwards compatiblemake stat backwards compatible
e
s 00001/00001/00281
d D 4.31 82/12/19 12:30:30 sam 35 34
c somehow mkdir showed only 1 arg
e
s 00006/00000/00276
d D 4.30 82/12/17 11:42:50 sam 34 33
c sun merge
e
s 00002/00002/00274
d D 4.29 82/12/09 23:46:06 sam 33 32
c profil returns
e
s 00026/00011/00250
d D 4.28 82/11/13 22:49:18 sam 32 31
c merge of 4.1b and 4.1c
e
s 00001/00002/00260
d D 4.27 82/11/02 11:27:36 root 31 30
c domain
e
s 00004/00001/00258
d D 4.26 82/10/22 01:13:35 root 30 29
c lint
e
s 00000/00000/00259
d D 4.25 82/10/21 20:55:58 root 29 28
c lint
e
s 00003/00001/00256
d D 4.24 82/10/20 03:09:54 root 28 27
c lint
e
s 00000/00001/00257
d D 4.23 82/10/20 02:57:45 root 27 26
c lint
e
s 00002/00001/00256
d D 4.22 82/10/16 22:59:06 root 26 25
c resurrect vfork()
e
s 00002/00001/00255
d D 4.21 82/09/12 02:56:35 root 25 24
c kill goes to okill
e
s 00001/00001/00255
d D 4.20 82/09/11 13:12:25 root 24 23
c working select()
e
s 00059/00046/00197
d D 4.19 82/09/06 22:38:30 root 23 22
c more work on timer stuff
e
s 00122/00160/00121
d D 4.18 82/09/04 09:04:30 root 22 21
c nearly a 4.2 init_sysent
e
s 00005/00006/00276
d D 4.17 82/08/24 15:04:22 root 21 20
c new groups stuff
e
s 00005/00005/00277
d D 4.16 82/08/10 16:40:25 sam 20 19
c install fchmod, fchown, rename, truncate, and ftruncate
e
s 00015/00013/00267
d D 4.15 82/08/09 17:46:30 sam 19 18
c added new file sys calls
e
s 00199/00195/00081
d D 4.14 82/07/24 18:08:41 root 18 17
c merge with calder
e
s 00021/00001/00255
d D 4.13 82/07/22 13:27:03 kre 17 16
c disc quotas / mush / renice
e
s 00115/00002/00141
d D 4.12 82/07/15 20:09:36 root 16 15
c merge with vmsysent.c
e
s 00004/00000/00139
d D 4.11 82/06/26 22:14:54 sam 15 14
c lucas nap system call
e
s 00006/00003/00133
d D 4.10 82/02/27 14:55:30 wnj 14 13
c symbolic links
e
s 00000/00001/00136
d D 4.9 81/11/20 14:44:14 wnj 13 12
c more lint
e
s 00000/00000/00137
d D 4.8 81/11/18 15:46:01 wnj 12 11
c more cleanup
e
s 00000/00000/00137
d D 4.7 81/11/16 14:21:56 wnj 11 10
c lint
e
s 00004/00006/00133
d D 4.6 81/11/08 17:07:58 wnj 10 9
c stty, gtty removed, pipe-->spipe
e
s 00003/00003/00136
d D 4.5 81/10/11 13:02:53 wnj 9 8
c first bootable version
e
s 00001/00001/00138
d D 4.4 81/03/09 01:50:01 wnj 8 7
c lint and a few minor fixed
e
s 00064/00064/00075
d D 4.3 81/02/08 01:11:42 wnj 7 6
c misc pre-mba changes (non-recursive printf, futz, resuba, %uXX...)
e
s 00001/00001/00138
d D 4.2 80/12/19 12:06:44 wnj 6 5
c fixup ../conf/ ../sys/ for new compilation strategy
e
s 00000/00000/00139
d D 4.1 80/11/09 17:33:00 bill 5 4
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00002/00001/00137
d D 3.4 80/10/02 10:41:25 bill 4 3
c first attempt at reboot stuff
e
s 00001/00001/00137
d D 3.3 80/06/07 02:48:11 bill 3 2
c %H%->%G%
e
s 00002/00001/00136
d D 3.2 80/05/18 11:36:07 bill 2 1
c add setpgrp
e
s 00137/00000/00000
d D 3.1 80/04/09 16:04:37 bill 1 0
c date and time created 80/04/09 16:04:37 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%H%	*/
E 3
I 3
D 8
/*	%M%	%I%	%G%	*/
E 8
I 8
D 59
/*	%M%	%I%	%E%	*/
E 59
I 59
/*
D 63
 * Copyright (c) 1982 Regents of the University of California.
E 63
I 63
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 63
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 59
E 8
E 3

/*
D 18
 * This table is the switch used to transfer
 * to the appropriate routine for processing a system call.
 * Each row contains the number of arguments expected
 * and a pointer to the routine.
E 18
I 18
 * System call switch table.
E 18
 */

D 55
#include "../h/param.h"
#include "../h/systm.h"
E 55
I 55
#include "param.h"
#include "systm.h"
E 55

D 18
int	alarm();
int	chdir();
int	chmod();
int	chown();
int	chroot();
int	close();
int	creat();
int	dup();
int	exec();
int	exece();
int	fork();
int	fstat();
int	getgid();
int	getpid();
int	getuid();
int	gtime();
D 10
int	gtty();
E 10
int	ioctl();
int	kill();
int	link();
I 14
int	lstat();
E 14
int	mknod();
D 9
int	mpxchan();
E 9
int	nice();
int	ftime();
E 18
int	nosys();
D 13
int	nullsys();
E 13
D 18
int	open();
int	pause();
D 10
int	pipe();
E 10
I 10
int	spipe();
E 18
I 18

/* 1.1 processes and protection */
D 21
int	getpid(),getpgrp(),getuid(),getgid(),getgrp();
int	setpgrp(),setuid(),setgid(),setgrp();
E 21
I 21
D 22
int	getpid(),getpgrp(),getuid(),getgid(),getgroups();
int	setpgrp(),setuid(),setgid(),setgroups();
E 22
I 22
int	sethostid(),gethostid(),sethostname(),gethostname(),getpid();
D 37
int	fork(),rexit(),execv(),execve();
E 37
I 37
int	fork(),rexit(),execv(),execve(),wait();
E 37
D 32
int	getuid(),setuid(),getgid(),getgroups(),setgid(),setgroups();
E 32
I 32
int	getuid(),setreuid(),getgid(),getgroups(),setregid(),setgroups();
E 32
int	getpgrp(),setpgrp();
I 47

E 47
E 22
E 21
D 32

E 32
/* 1.2 memory management */
int	sbrk(),sstk();
D 22
int	smmap(),mremap(),munmap(),mprotect(),madvise(),mincore();
E 22
I 22
int	getpagesize(),smmap(),msync(),munmap(),mprotect(),madvise(),mincore();
E 22

D 22
/* 1.3 signals */
E 22
I 22
D 44
/* 1.3 signals XXX still old XXX */
E 44
I 44
/* 1.3 signals */
E 44
E 22
D 54
int	sigvec(),sigblock(),sigsetmask(),sigpause(),sigstack();
E 54
I 54
D 57
int	sigvec(),sigblock(),sigsetmask(),sigpause(),sigstack(),signal();
E 57
I 57
D 58
int	sigvec(),sigblock(),sigsetmask(),sigpause(),sigstack();
E 58
I 58
int	sigvec(),sigblock(),sigsetmask(),sigpause(),sigstack(),sigreturn();
I 66
int	sigemu();
E 66
E 58
E 57
E 54
E 18
E 10
D 22
int	profil();
E 22
I 22
D 30
int	kill(),killpg();
E 30
I 30
D 44
#ifdef notdef
int	kill();
#endif
int	killpg();
E 44
I 44
int	kill(), killpg();
E 44
E 30
E 22
I 18

D 22
/* 1.4 descriptors */
int	dstd(),dup(),dup2(),dtype(),dwrap(),dselect(),dnblock(),dsignal();
int	close();
E 22
I 22
/* 1.4 timing and statistics */
int	gettimeofday(),settimeofday();
D 23
int	getitimer(),setitimer(),getandsetitimer();
E 23
I 23
int	getitimer(),setitimer();
I 56
int 	adjtime();
E 56
E 23
E 22

D 22
/* 1.5 timing and statistics */
int	rtime(),rusage(),itimer();
E 22
I 22
/* 1.5 descriptors */
D 43
int	getdtablesize(),getdprop(),dup(),dup2(),close();
int	select(),getdopt(),setdopt(),wrap();
E 43
I 43
int	getdtablesize(),dup(),dup2(),close();
D 45
int	select(),getdopt(),setdopt(),fcntl();
E 45
I 45
int	select(),getdopt(),setdopt(),fcntl(),flock();
E 45
E 43
E 22

/* 1.6 resource controls */
D 22
int	renice(),rlimit();
#ifdef QUOTA
int	qquota(),setquota();
#endif
#ifdef MUSH
int	mu_msg();
#endif
E 22
I 22
D 23
int	getpriority(),setpriority(),getrusage(),getlimit(),setlimit();
E 23
I 23
int	getpriority(),setpriority(),getrusage(),getrlimit(),setrlimit();
I 32
D 42
#ifdef QUOTA
E 42
int	setquota(),qquota();
D 42
#endif
#ifdef MUSH
int	mu_msg();
#endif
E 42
E 32
E 23
E 22

I 22
/* 1.7 system operation support */
D 41
int	unmount();
D 28
int	smount(),sumount();		/* XXX */
E 28
I 28
int	smount();		/* XXX */
D 32
#ifdef notdev
E 32
I 32
#ifdef notdef
E 32
E 28
int	swapon(),swapoff();
I 28
#endif
E 41
I 41
int	umount(),smount(),swapon();
E 41
E 28
D 43
int	sync(),reboot(),sysacct(),revoke();
E 43
I 43
int	sync(),reboot(),sysacct();
E 43

E 22
/* 2.1 generic operations */
D 22
int	read(),write(),readv(),writev(),ioctl(),cancel();
E 22
I 22
int	read(),write(),readv(),writev(),ioctl();
E 22

D 22
/* 2.2 communications */
int	sdomain();
int	ssocket(),sconnect(),saccept(),sdisconnect();
int	ssend(),sreceive(),ssocketaddr();
E 22
I 22
/* 2.2 file system */
int	chdir(),chroot();
int	mkdir(),rmdir();
D 43
int	open(),mknod(),portal(),unlink(),stat(),fstat(),lstat();
E 43
I 43
int	creat(),open(),mknod(),unlink(),stat(),fstat(),lstat();
E 43
int	chown(),fchown(),chmod(),fchmod(),utimes();
int	link(),symlink(),readlink(),rename();
D 32
int	lseek(),truncate(),ftruncate(),saccess(),flock();
E 32
I 32
D 45
int	lseek(),truncate(),ftruncate(),saccess(),flock(),fsync();
E 45
I 45
int	lseek(),truncate(),ftruncate(),saccess(),fsync();
E 45
E 32
E 22

I 22
/* 2.3 communications */
D 31
int	domain();
E 31
int	socket(),bind(),listen(),accept(),connect();
int	socketpair(),sendto(),send(),recvfrom(),recv();
D 38
int	sendmsg(),recvmsg(),shutdown();
E 38
I 38
int	sendmsg(),recvmsg(),shutdown(),setsockopt(),getsockopt();
E 38
E 22
D 23
int	spipe();
E 23
I 23
D 39
int	pipe();
E 39
I 39
D 50
int	getsockname(),pipe();
E 50
I 50
int	getsockname(),getpeername(),pipe();
E 50
E 39
E 23

D 22
/* 2.3 file system */
int	chdir(),chroot();
int	chown(),fchown(),chmod(),fchmod(),open(),unlink(),saccess();
int	link(),symlink(),stat(),fstat(),lstat(),readlink(),rename();
int	seek(),truncate(),ftruncate(),flock(),mknod(),portal();
E 22
I 22
D 39
int	ssocketaddr();		/* XXX */
E 39
int	umask();		/* XXX */
D 23
int	utime();		/* XXX */
E 23
E 22

D 22
int	umask();
int	utime();

E 22
/* 2.4 processes */
D 22
int	exec(),exece(),fork(),wait(),rexit(),vfork();
E 22
E 18
int	ptrace();
D 18
int	read();
I 14
int	readlink();
E 18
I 18

/* 2.5 terminals */

I 47
#ifdef COMPAT
E 47
D 22
/* 3.1 system operation support */
int	smount(),sumount();
int	syslock();
int	sysphys();
E 18
E 14
I 4
int	reboot();
I 17
D 18
int	renice();
E 17
E 4
int	rexit();
int	saccess();
int	sbreak();
int	seek();
I 9
int	select();
E 9
int	setgid();
I 2
int	setpgrp();
E 2
int	setuid();
int	smount();
int	ssig();
int	stat();
int	stime();
D 10
int	stty();
E 10
int	sumount();
I 14
int	symlink();
E 18
E 14
int	sync();
I 18
int	stime();
E 18
int	sysacct();
D 18
int	syslock();
int	sysphys();
int	times();
int	umask();
int	unlink();
int	utime();
int	wait();
int	write();
I 16
int	nosys();
E 18
I 18
int	gethostname(),sethostname();
E 18
E 16

D 16
#include "../h/vmsysent.h"
E 16
I 16
D 18
/*
 * Random.
 */
int	vfork();		/* later, just fork? */
int	vadvise();		/* later, segadvise */
E 18
I 18
int	times();
E 22
I 22
D 23
int	wait();
E 23
I 23
/* emulations for backwards compatibility */
I 47
#define	compat(n, name)	n, o/**/name

E 47
int	owait();		/* now receive message on channel */
D 43
int	ocreat();		/* now use 3 arg open */
E 43
int	otime();		/* now use gettimeofday */
D 47
int	obreak();		/* now use sbrk */
E 47
D 41
int	oumount();		/* now use unmount */
E 41
int	ostime();		/* now use settimeofday */
int	oalarm();		/* now use setitimer */
int	outime();		/* now use utimes */
D 43
int	ostty(),ogtty();	/* now use ioctl */
E 43
int	opause();		/* now use sigpause */
int	onice();		/* now use setpriority,getpriority */
int	oftime();		/* now use gettimeofday */
I 25
D 46
int	okill();
E 46
I 46
D 47
int	okill();		/* now use kill and killpg */
E 47
E 46
E 25
int	osetpgrp();		/* ??? */
int	otimes();		/* now use getrusage */
int	ossig();		/* now use sigvec, etc */
I 26
D 47
int	vfork();
E 26
int	ovadvise();		/* now use madvise */
int	ovlimit();		/* now use setlimit,getlimit */
E 47
I 47
int	ovlimit();		/* now use setrlimit,getrlimit */
E 47
D 41
int	oswapon();		/* now pass more information */
E 41
int	ovtimes();		/* now use getrusage */
I 32
int	osetuid();		/* now use setreuid */
int	osetgid();		/* now use setregid */
I 36
int	ostat();		/* now use stat */
int	ofstat();		/* now use fstat */
I 47
#else
#define	compat(n, name)	0, nosys
#endif
E 47
E 36
E 32

D 44
/* mpxchan: now emulated yields core dump */
D 33
/* profil:  should be ignored! */
E 33

E 44
/* BEGIN JUNK */
I 34
#ifdef vax
E 34
E 23
E 22
E 18
int	resuba();
I 34
D 47
#endif
E 34
I 33
int	profil();
E 33
D 27
int	futz();
E 27
int	vhangup();		/* should just do in exit() */
E 47
D 22
int	vlimit();
E 22
D 23
int	vswapon();
D 22
int	vtimes();
E 22
I 22
int	otime(), oftime();
E 23
E 22
#ifdef TRACE
int	vtrace();
#endif
I 47
#endif
int	profil();		/* 'cuz sys calls are interruptible */
int	vhangup();		/* should just do in exit() */
int	vfork();		/* awaiting fork w/ copy on write */
int	obreak();		/* awaiting new sbrk */
int	ovadvise();		/* awaiting new madvise */
E 47
I 23
/* END JUNK */
E 23
D 18
int	setgrp();
E 16

I 16
int	gethostname();
int	sethostname();

E 18
D 22
#ifdef CAD
int	chfile();
#endif
E 22

I 62
/*
 * Reserved/unimplemented system calls in the range 0-150 inclusive
 * are reserved for use in future Berkeley releases.
 * Additional system calls implemented in vendor and other
 * redistributions should be placed in the reserved range at the end
 * of the current calls.
 */
E 62
D 18
/*
 * Segmentation.
 */
int	segalloc();		/* not in yet */
int	segfree();		/* not in yet */
int	segsync();		/* not in yet */
E 18
I 18
D 23
int	ocreat();			/* obsoleted by open */
D 22
int	ogtime();			/* obsoleted by rtime */
E 22
int	onice();			/* obsoleted by renice */
D 22
int	oftime();			/* obsoleted by rtime+sysinfo */
E 22
int	osbreak();			/* replaced by sbrk */
int	oselect();			/* replaced by dselect */
int	osetpgrp();			/* replaced by setpgrp+getpgrp */
int	ossig();			/* old signal stuff */
int	ovadvise();			/* obsoleted by madvise */
int	oalarm();			/* obsoleted by itimer */
D 22
int	okill();			/* obsoleted by kill+killpg */
E 22
int	opause();			/* obsoleted by sigpause */
E 23
D 21
int	osetgrp();			/* replaced by setgrp */
E 21
E 18
D 32

E 32
D 18
/*
 * IPC/Networking.
 */
int	ssplice();
int	ssocket();
int	sconnect();
int	saccept();
int	sdisconnect();
int	ssend();
int	sreceive();
int	ssocketaddr();

I 17
/*
 * quotas & mush
 */
int	mu_msg();
int	qquota();
int	setquota();

E 17
E 16
struct sysent sysent[128] =
E 18
I 18
D 22
struct sysent sysent[] =
E 18
{
E 22
I 22
struct sysent sysent[] = {
E 22
D 7
	0, 0, nosys,			/*  0 = indir */
	1, 0, rexit,			/*  1 = exit */
	0, 0, fork,			/*  2 = fork */
	3, 0, read,			/*  3 = read */
	3, 0, write,			/*  4 = write */
	2, 0, open,			/*  5 = open */
	1, 0, close,			/*  6 = close */
	0, 0, wait,			/*  7 = wait */
	2, 0, creat,			/*  8 = creat */
	2, 0, link,			/*  9 = link */
	1, 0, unlink,			/* 10 = unlink */
	2, 0, exec,			/* 11 = exec */
	1, 0, chdir,			/* 12 = chdir */
	0, 0, gtime,			/* 13 = time */
	3, 0, mknod,			/* 14 = mknod */
	2, 0, chmod,			/* 15 = chmod */
	3, 0, chown,			/* 16 = chown; now 3 args */
	1, 0, sbreak,			/* 17 = break */
	2, 0, stat,			/* 18 = stat */
	3, 0, seek,			/* 19 = seek */
	0, 0, getpid,			/* 20 = getpid */
	3, 0, smount,			/* 21 = mount */
	1, 0, sumount,			/* 22 = umount */
	1, 0, setuid,			/* 23 = setuid */
	0, 0, getuid,			/* 24 = getuid */
	1, 0, stime,			/* 25 = stime */
	4, 0, ptrace,			/* 26 = ptrace */
	1, 0, alarm,			/* 27 = alarm */
	2, 0, fstat,			/* 28 = fstat */
	0, 0, pause,			/* 29 = pause */
	2, 0, utime,			/* 30 = utime */
	2, 0, stty,			/* 31 = stty */
	2, 0, gtty,			/* 32 = gtty */
	2, 0, saccess,			/* 33 = access */
	1, 0, nice,			/* 34 = nice */
	1, 0, ftime,			/* 35 = ftime; formally sleep;  */
	0, 0, sync,			/* 36 = sync */
	2, 0, kill,			/* 37 = kill */
	0, 0, nullsys,			/* 38 = switch; inoperative */
D 2
	0, 0, nullsys,			/* 39 = setpgrp (not in yet) */
E 2
I 2
	2, 0, setpgrp,			/* 39 = setpgrp */
E 2
	0, 0, nosys,			/* 40 = tell - obsolete */
	2, 0, dup,			/* 41 = dup */
	0, 0, pipe,			/* 42 = pipe */
	1, 0, times,			/* 43 = times */
	4, 0, profil,			/* 44 = prof */
	0, 0, nosys,			/* 45 = tiu */
	1, 0, setgid,			/* 46 = setgid */
	0, 0, getgid,			/* 47 = getgid */
	2, 0, ssig,			/* 48 = sig */
	0, 0, nosys,			/* 49 = reserved for USG */
	0, 0, nosys,			/* 50 = reserved for USG */
	1, 0, sysacct,			/* 51 = turn acct off/on */
	3, 0, sysphys,			/* 52 = set user physical addresses */
	1, 0, syslock,			/* 53 = lock user in core */
	3, 0, ioctl,			/* 54 = ioctl */
D 4
	0, 0, nosys,			/* 55 = reboot */
E 4
I 4
	1, 0, reboot,			/* 55 = reboot */
E 4
	4, 0, mpxchan,			/* 56 = creat mpx comm channel */
	0, 0, nosys,			/* 57 = reserved for USG */
	0, 0, nosys,			/* 58 = reserved for USG */
	3, 0, exece,			/* 59 = exece */
	1, 0, umask,			/* 60 = umask */
	1, 0, chroot,			/* 61 = chroot */
	0, 0, nosys,			/* 62 = reserved to local sites */
	0, 0, nosys,			/* 63 = used internally */
E 7
I 7
D 18
	0, nosys,			/*  0 = indir */
	1, rexit,			/*  1 = exit */
	0, fork,			/*  2 = fork */
	3, read,			/*  3 = read */
	3, write,			/*  4 = write */
	2, open,			/*  5 = open */
	1, close,			/*  6 = close */
	0, wait,			/*  7 = wait */
	2, creat,			/*  8 = creat */
	2, link,			/*  9 = link */
	1, unlink,			/* 10 = unlink */
	2, exec,			/* 11 = exec */
	1, chdir,			/* 12 = chdir */
	0, gtime,			/* 13 = time */
	3, mknod,			/* 14 = mknod */
	2, chmod,			/* 15 = chmod */
	3, chown,			/* 16 = chown; now 3 args */
	1, sbreak,			/* 17 = break */
	2, stat,			/* 18 = stat */
	3, seek,			/* 19 = seek */
	0, getpid,			/* 20 = getpid */
	3, smount,			/* 21 = mount */
	1, sumount,			/* 22 = umount */
	1, setuid,			/* 23 = setuid */
	0, getuid,			/* 24 = getuid */
	1, stime,			/* 25 = stime */
	4, ptrace,			/* 26 = ptrace */
	1, alarm,			/* 27 = alarm */
	2, fstat,			/* 28 = fstat */
	0, pause,			/* 29 = pause */
	2, utime,			/* 30 = utime */
D 10
	2, stty,			/* 31 = stty */
	2, gtty,			/* 32 = gtty */
E 10
I 10
	0, nosys,			/* 31 = stty - obsolete */
	0, nosys,			/* 32 = gtty - obsolete */
E 10
	2, saccess,			/* 33 = access */
	1, nice,			/* 34 = nice */
	1, ftime,			/* 35 = ftime; formally sleep;  */
	0, sync,			/* 36 = sync */
	2, kill,			/* 37 = kill */
D 9
	0, nullsys,			/* 38 = switch; inoperative */
E 9
I 9
	4, select,			/* 38 = select */
E 9
	2, setpgrp,			/* 39 = setpgrp */
D 14
	0, nosys,			/* 40 = tell - obsolete */
E 14
I 14
	2, lstat,			/* 40 = lstat */
E 14
	2, dup,				/* 41 = dup */
D 10
	0, pipe,			/* 42 = pipe */
E 10
I 10
	0, spipe,			/* 42 = pipe */
E 10
	1, times,			/* 43 = times */
	4, profil,			/* 44 = prof */
	0, nosys,			/* 45 = tiu */
	1, setgid,			/* 46 = setgid */
	0, getgid,			/* 47 = getgid */
	2, ssig,			/* 48 = sig */
	0, nosys,			/* 49 = reserved for USG */
	0, nosys,			/* 50 = reserved for USG */
	1, sysacct,			/* 51 = turn acct off/on */
	3, sysphys,			/* 52 = set user physical addresses */
	1, syslock,			/* 53 = lock user in core */
	3, ioctl,			/* 54 = ioctl */
	1, reboot,			/* 55 = reboot */
D 9
	4, mpxchan,			/* 56 = creat mpx comm channel */
E 9
I 9
	0, nosys,			/* 56 = mpxchan - obsolete */
E 9
D 14
	0, nosys,			/* 57 = reserved for USG */
	0, nosys,			/* 58 = reserved for USG */
E 14
I 14
	2, symlink,			/* 57 = symlink */
	3, readlink,			/* 58 = readlink */
E 14
	3, exece,			/* 59 = exece */
	1, umask,			/* 60 = umask */
	1, chroot,			/* 61 = chroot */
E 18
I 18
D 61
	0, nosys,			/*   0 = indir */
E 61
I 61
	0, nosys,			/*   0 = indir or out-of-range */
E 61
	1, rexit,			/*   1 = exit */
	0, fork,			/*   2 = fork */
	3, read,			/*   3 = read */
	3, write,			/*   4 = write */
D 19
	2, open,			/*   5 = open */
E 19
I 19
	3, open,			/*   5 = open */
E 19
	1, close,			/*   6 = close */
D 23
	0, wait,			/*   7 = wait */
	2, ocreat,			/*   8 = ocreat replaced by open */
E 23
I 23
D 47
	0, owait,			/*   7 = old wait */
E 47
I 47
D 49
	compat(0, wait),		/*   7 = old wait */
E 49
I 49
	compat(0,wait),			/*   7 = old wait */
E 49
E 47
D 43
	2, ocreat,			/*   8 = old creat */
E 43
I 43
	2, creat,			/*   8 = creat */
E 43
E 23
	2, link,			/*   9 = link */
	1, unlink,			/*  10 = unlink */
D 22
	2, exec,			/*  11 = exec */
E 22
I 22
	2, execv,			/*  11 = execv */
E 22
	1, chdir,			/*  12 = chdir */
D 22
	0, ogtime,			/*  13 = ogtime */
E 22
I 22
D 47
	0, otime,			/*  13 = old time */
E 47
I 47
D 49
	compat(0, time),		/*  13 = old time */
E 49
I 49
	compat(0,time),			/*  13 = old time */
E 49
E 47
E 22
	3, mknod,			/*  14 = mknod */
	2, chmod,			/*  15 = chmod */
	3, chown,			/*  16 = chown; now 3 args */
D 23
	1, osbreak,			/*  17 = obreak */
E 23
I 23
	1, obreak,			/*  17 = old break */
E 23
D 36
	2, stat,			/*  18 = stat */
E 36
I 36
D 47
	2, ostat,			/*  18 = old stat */
E 47
I 47
D 49
	compat(2, stat),		/*  18 = old stat */
E 49
I 49
	compat(2,stat),			/*  18 = old stat */
E 49
E 47
E 36
D 22
	3, seek,			/*  19 = seek */
E 22
I 22
	3, lseek,			/*  19 = lseek */
E 22
	0, getpid,			/*  20 = getpid */
	3, smount,			/*  21 = mount */
D 23
	1, sumount,			/*  22 = umount */
E 23
I 23
D 41
	1, oumount,			/*  22 = umount */
E 41
I 41
	1, umount,			/*  22 = umount */
E 41
E 23
D 32
	1, setuid,			/*  23 = setuid */
E 32
I 32
D 47
	1, osetuid,			/*  23 = old setuid */
E 47
I 47
D 49
	compat(1, setuid),		/*  23 = old setuid */
E 49
I 49
	compat(1,setuid),		/*  23 = old setuid */
E 49
E 47
E 32
	0, getuid,			/*  24 = getuid */
D 22
	1, stime,			/*  25 = stime */
E 22
I 22
D 23
	0, nosys,			/*  25 = old stime */
E 23
I 23
D 47
	1, ostime,			/*  25 = old stime */
E 47
I 47
D 49
	compat(1, stime),		/*  25 = old stime */
E 49
I 49
	compat(1,stime),		/*  25 = old stime */
E 49
E 47
E 23
E 22
	4, ptrace,			/*  26 = ptrace */
D 23
	1, oalarm,			/*  27 = oalarm */
E 23
I 23
D 47
	1, oalarm,			/*  27 = old alarm */
E 23
D 36
	2, fstat,			/*  28 = fstat */
E 36
I 36
	2, ofstat,			/*  28 = old fstat */
E 36
	0, opause,			/*  29 = opause */
D 23
	2, utime,			/*  30 = utime */
	0, nosys,			/*  31 = nosys */
	0, nosys,			/*  32 = nosys */
E 23
I 23
	2, outime,			/*  30 = old utime */
E 47
I 47
D 49
	compat(1, alarm),		/*  27 = old alarm */
	compat(2, fstat),		/*  28 = old fstat */
	compat(0, pause),		/*  29 = opause */
	compat(2, utime),		/*  30 = old utime */
E 49
I 49
	compat(1,alarm),		/*  27 = old alarm */
	compat(2,fstat),		/*  28 = old fstat */
	compat(0,pause),		/*  29 = opause */
	compat(2,utime),		/*  30 = old utime */
E 49
E 47
D 43
	2, ostty,			/*  31 = old stty */
	2, ogtty,			/*  32 = old gtty */
E 43
I 43
	0, nosys,			/*  31 = was stty */
	0, nosys,			/*  32 = was gtty */
E 43
E 23
	2, saccess,			/*  33 = access */
D 47
	1, onice,			/*  34 = old nice */
	1, oftime,			/*  35 = old ftime */
E 47
I 47
D 49
	compat(1, nice),		/*  34 = old nice */
	compat(1, ftime),		/*  35 = old ftime */
E 49
I 49
	compat(1,nice),			/*  34 = old nice */
	compat(1,ftime),		/*  35 = old ftime */
E 49
E 47
	0, sync,			/*  36 = sync */
D 22
	2, okill,			/*  37 = okill */
E 22
I 22
D 25
	2, kill,			/*  37 = kill */
E 25
I 25
D 32
	2, okill,			/*  37 = kill */
E 32
I 32
D 47
	2, okill,			/*  37 = old kill */
E 47
I 47
	2, kill,			/*  37 = kill */
E 47
E 32
E 25
E 22
D 23
	4, oselect,			/*  38 = old select */
E 23
I 23
D 36
	0, nosys,			/*  38 = nosys */
E 36
I 36
	2, stat,			/*  38 = stat */
E 36
E 23
D 47
	2, osetpgrp,			/*  39 = old setpgrp */
E 47
I 47
D 49
	compat(2, setpgrp),		/*  39 = old setpgrp */
E 49
I 49
	compat(2,setpgrp),		/*  39 = old setpgrp */
E 49
E 47
	2, lstat,			/*  40 = lstat */
	2, dup,				/*  41 = dup */
D 23
	0, spipe,			/*  42 = pipe */
D 22
	1, times,			/*  43 = times */
	4, profil,			/*  44 = prof */
	0, nosys,			/*  45 = tiu */
E 22
I 22
	0, nosys,			/*  43 = old times */
	0, nosys,			/*  44 = nosys */
E 23
I 23
	0, pipe,			/*  42 = pipe */
D 47
	1, otimes,			/*  43 = old times */
E 47
I 47
D 49
	compat(1, times),		/*  43 = old times */
E 49
I 49
	compat(1,times),		/*  43 = old times */
E 49
E 47
D 33
	0, nosys,	/*IGNORE*/	/*  44 = old profil */
E 33
I 33
	4, profil,			/*  44 = profil */
E 33
E 23
	0, nosys,			/*  45 = nosys */
E 22
D 32
	1, setgid,			/*  46 = setgid */
E 32
I 32
D 47
	1, osetgid,			/*  46 = old setgid */
E 47
I 47
D 49
	compat(1, setgid),		/*  46 = old setgid */
E 49
I 49
	compat(1,setgid),		/*  46 = old setgid */
E 49
E 47
E 32
	0, getgid,			/*  47 = getgid */
D 47
	2, ossig,			/*  48 = old sig */
E 47
I 47
D 49
	compat(2, ssig),		/*  48 = old sig */
E 49
I 49
	compat(2,ssig),			/*  48 = old sig */
E 49
E 47
	0, nosys,			/*  49 = reserved for USG */
	0, nosys,			/*  50 = reserved for USG */
	1, sysacct,			/*  51 = turn acct off/on */
D 22
	3, sysphys,			/*  52 = set user physical addresses */
	1, syslock,			/*  53 = lock user in core */
E 22
I 22
	0, nosys,			/*  52 = old set phys addr */
	0, nosys,			/*  53 = old lock in core */
E 22
	3, ioctl,			/*  54 = ioctl */
	1, reboot,			/*  55 = reboot */
D 23
	0, nosys,			/*  56 = mpxchan - obsolete */
E 23
I 23
	0, nosys,			/*  56 = old mpxchan */
E 23
	2, symlink,			/*  57 = symlink */
	3, readlink,			/*  58 = readlink */
D 22
	3, exece,			/*  59 = exece */
E 22
I 22
	3, execve,			/*  59 = execve */
E 22
	1, umask,			/*  60 = umask */
	1, chroot,			/*  61 = chroot */
E 18
I 15
D 22
#ifndef LUCAS
E 15
D 18
	0, nosys,			/* 62 = reserved to local sites */
E 18
I 18
	0, nosys,			/*  62 = reserved to local sites */
E 18
I 15
#else
D 18
	1, nap,				/* 62 = nap */
E 18
I 18
	1, nap,				/*  62 = nap */
E 18
#endif
E 22
I 22
D 36
	0, nosys,			/*  62 = nosys */
E 36
I 36
	2, fstat,			/*  62 = fstat */
E 36
E 22
E 15
D 18
	0, nosys,			/* 63 = used internally */
E 18
I 18
D 61
	0, nosys,			/*  63 = used internally */
E 61
I 61
	0, nosys,			/*  63 = reserved */
E 61
E 18
E 7
D 6
#include "vmsysent.c"
E 6
I 6
D 16
#include "../sys/vmsysent.c"
E 16
I 16
D 22

E 22
D 18
	0, nosys,			/* 64 +0 = nosys */
	0, nosys,			/* 64 +1 = nosys */
	0, vfork,			/* 64 +2 = vfork */
	3, read,			/* 64 +3 = vread; now just read */
	3, write,			/* 64 +4 = vwrite; now just write */
	3, segalloc,			/* 64 +5 = segalloc */
	1, segfree,			/* 64 +6 = segfree */
	1, segsync,			/* 64 +7 = segsync */
	1, vadvise,			/* 64 +8 = vadvise */
	0, nosys,			/* 64 +9 = nosys */
	0, nosys,			/* 64+10 = nosys */
	0, nosys,			/* 64+11 = nosys */
E 18
I 18
D 23
	0, nosys,			/*  64 = nosys */
E 23
I 23
D 64
	1, getpagesize,			/*  64 = getpagesize */
E 64
I 64
	0, getpagesize,			/*  64 = getpagesize */
E 64
E 23
D 65
	5, mremap,			/*  65 = mremap */
E 65
I 65
	2, msync,			/*  65 = msync */
E 65
D 22

	0, vfork,			/*  66 = vfork */
	3, read,			/*  67 = vread; now just read */
	3, write,			/*  68 = vwrite; now just write */

/* new memory management calls from 1.2 */
	1, sbrk,			/* 64 +5 = sbrk */
	1, sstk,			/* 64 +6 = sstk */
	6, smmap,			/* 64 +7 = mmap */
	2, vlimit,			/*  72 = vlimit */
	2, munmap,			/* 64 +9 = munmap */
	3, mprotect,			/* 64+10 = mprotect */
	3, madvise,			/* 64+11 = madvise */

E 18
	1, vhangup,			/* 64+12 = vhangup */
	2, vlimit,			/* 64+13 = vlimit */
D 18
	0, nosys,			/* 64+14 = nosys */
	0, nosys,			/* 64+15 = nosys */
	0, nosys,			/* 64+16 = nosys */
	0, nosys,			/* 64+17 = nosys */
	0, nosys,			/* 64+18 = nosys */
E 18
I 18

	3, mincore,			/* 64+14 = mincore */

/* new process/protection calls from 1.1 */
D 21
	1, getgrp,			/* 64+15 = getgrp */
	1, setgrp,			/* 64+16 = setgrp */
E 21
I 21
	2, getgroups,			/* 64+15 = getgroups */
	2, setgroups,			/* 64+16 = setgroups */
E 21
	1, getpgrp,			/* 64+17 = getpgrp */
	2, setpgrp,			/* 64+18 = setpgrp */

E 18
	0, nosys,			/* 64+19 = nosys */
	0, nosys,			/* 64+20 = nosys */
	1, vswapon,			/* 64+21 = vswapon */
D 18
	2, setgrp,			/* 64+22 = setgrp */
E 18
I 18
D 21
	2, osetgrp,			/* 64+22 = osetgrp */
E 21
I 21
	0, nosys,			/* 86 = nosys */
E 21
E 18
	2, gethostname,			/* 64+23 = gethostname */
	2, sethostname,			/* 64+24 = sethostname */
D 18
	0, nosys,			/* 64+25 = nosys */
	0, nosys,			/* 64+26 = nosys */
	0, nosys,			/* 64+27 = nosys */
	0, nosys,			/* 64+28 = nosys */
	0, nosys,			/* 64+29 = nosys */
	0, nosys,			/* 64+30 = nosys */
	0, nosys,			/* 64+31 = nosys */
E 18
I 18

/* descriptor calls from 1.4 */
	0, dstd,			/* 64+25 = dstd */
	1, dup2,			/* 64+26 = dup2 */
	2, dtype,			/* 64+27 = dtype */
	2, dwrap,			/* 64+28 = dwrap */
	4, dselect,			/* 64+29 = dselect */
	2, dnblock,			/* 64+30 = dnblock */
	2, dsignal,			/* 64+31 = dsignal */

E 18
D 17
	0, nosys,			/* 64+32 = nosys */
E 17
I 17
	3, renice,			/* 64+32 = renice */
E 17
	4, ssocket,			/* 64+33 = socket */
	2, sconnect,			/* 64+34 = connect */
	3, saccept,			/* 64+35 = accept */
	0, nosys,			/* 64+36 = nosys */
	4, ssend,			/* 64+37 = send */
	4, sreceive,			/* 64+38 = receive */
	2, ssocketaddr,			/* 64+39 = socketaddr */
	0, nosys,			/* 64+40 = nosys */
	0, nosys,			/* 64+41 = nosys */
	0, nosys,			/* 64+42 = nosys */
I 18

E 18
	2, vtimes,			/* 64+43 = vtimes */
D 18
	0, nosys,			/* 64+44 = nosys */
	0, nosys,			/* 64+45 = nosys */
	0, nosys,			/* 64+46 = nosys */
	0, nosys,			/* 64+47 = nosys */
	0, nosys,			/* 64+48 = nosys */
E 18
I 18

/* signal calls from 1.3 */
	2, sigvec,			/* 64+44 = sigvec */
	1, sigblock,			/* 64+45 = sigblock */
	1, sigsetmask,			/* 64+46 = sigsetmask */
	1, sigpause,			/* 64+47 = sigpause */
	2, sigstack,			/* 64+48 = sigstack */

E 18
	0, nosys,			/* 64+49 = nosys */
	0, nosys,			/* 64+50 = nosys */
E 22
I 22
D 23
	0, nosys,			/*  66 = old vfork */
	0, nosys,			/*  67 = old vread */
	0, nosys,			/*  68 = old vwrite */
E 23
I 23
D 26
	0, fork,			/*  66 = old vfork */
E 26
I 26
	0, vfork,			/*  66 = vfork */
E 26
	0, read,			/*  67 = old vread */
	0, write,			/*  68 = old vwrite */
E 23
	1, sbrk,			/*  69 = sbrk */
	1, sstk,			/*  70 = sstk */
	6, smmap,			/*  71 = mmap */
D 23
	0, nosys,			/*  72 = nosys */
E 23
I 23
	1, ovadvise,			/*  72 = old vadvise */
E 23
	2, munmap,			/*  73 = munmap */
	3, mprotect,			/*  74 = mprotect */
	3, madvise,			/*  75 = madvise */
	1, vhangup,			/*  76 = vhangup */
D 23
	1, getpagesize,			/*  77 = getpagesize */
E 23
I 23
D 47
	2, ovlimit,			/*  77 = old vlimit */
E 47
I 47
D 49
	compat(2, vlimit),		/*  77 = old vlimit */
E 49
I 49
	compat(2,vlimit),		/*  77 = old vlimit */
E 49
E 47
E 23
	3, mincore,			/*  78 = mincore */
	2, getgroups,			/*  79 = getgroups */
	2, setgroups,			/*  80 = setgroups */
	1, getpgrp,			/*  81 = getpgrp */
	2, setpgrp,			/*  82 = setpgrp */
D 23
	2, setitimer,			/*  83 = setitimer */
	3, getandsetitimer,		/*  84 = getandsetitimer */
	1, vswapon,			/*  85 = vswapon */
E 23
I 23
	3, setitimer,			/*  83 = setitimer */
D 37
	0, nosys,			/*  84 = nosys */
E 37
I 37
	0, wait,			/*  84 = wait */
E 37
D 41
	1, oswapon,			/*  85 = old swapon */
E 41
I 41
	1, swapon,			/*  85 = swapon */
E 41
E 23
	2, getitimer,			/*  86 = getitimer */
	2, gethostname,			/*  87 = gethostname */
	2, sethostname,			/*  88 = sethostname */
	0, getdtablesize,		/*  89 = getdtablesize */
D 48
	1, dup2,			/*  90 = dup2 */
E 48
I 48
	2, dup2,			/*  90 = dup2 */
E 48
D 23
	0, nosys,			/*  91 = nosys */
E 23
I 23
	2, getdopt,			/*  91 = getdopt */
E 23
D 43
	2, wrap,			/*  92 = wrap */
E 43
I 43
	3, fcntl,			/*  92 = fcntl */
E 43
D 23
	0, nosys,			/*  93 = nosys */
	0, nosys,			/*  94 = nosys */
E 23
I 23
D 24
	4, select,			/*  93 = select */
E 24
I 24
	5, select,			/*  93 = select */
E 24
	2, setdopt,			/*  94 = setdopt */
E 23
D 32
	0, nosys,			/*  95 = nosys */
E 32
I 32
	1, fsync,			/*  95 = fsync */
E 32
	3, setpriority,			/*  96 = setpriority */
D 38
	4, socket,			/*  97 = socket */
	4, connect,			/*  98 = connect */
	4, accept,			/*  99 = accept */
E 38
I 38
	3, socket,			/*  97 = socket */
	3, connect,			/*  98 = connect */
	3, accept,			/*  99 = accept */
E 38
	2, getpriority,			/* 100 = getpriority */
	4, send,			/* 101 = send */
	4, recv,			/* 102 = recv */
D 39
	2, ssocketaddr,			/* 103 = socketaddr */
E 39
I 39
D 58
	0, nosys,			/* 103 = old socketaddr */
E 58
I 58
	1, sigreturn,			/* 103 = sigreturn */
E 58
E 39
D 38
	4, bind,			/* 104 = bind */
D 31
	1, domain,			/* 105 = domain */
E 31
I 31
	0, nosys,			/* 105 = nosys */
E 38
I 38
	3, bind,			/* 104 = bind */
	5, setsockopt,			/* 105 = setsockopt */
E 38
E 31
	2, listen,			/* 106 = listen */
D 23
	6, recvfrom,			/* 107 = recvfrom */
E 23
I 23
D 47
	2, ovtimes,			/* 107 = old vtimes */
E 47
I 47
D 49
	compat(2, vtimes),		/* 107 = old vtimes */
E 49
I 49
	compat(2,vtimes),		/* 107 = old vtimes */
E 49
E 47
E 23
D 44
	2, sigvec,			/* 108 = sigvec */
E 44
I 44
	3, sigvec,			/* 108 = sigvec */
E 44
	1, sigblock,			/* 109 = sigblock */
	1, sigsetmask,			/* 110 = sigsetmask */
	1, sigpause,			/* 111 = sigpause */
	2, sigstack,			/* 112 = sigstack */
	3, recvmsg,			/* 113 = recvmsg */
	3, sendmsg,			/* 114 = sendmsg */
E 22
#ifdef TRACE
D 22
	2, vtrace,			/* 64+51 = vtrace */
E 22
I 22
	2, vtrace,			/* 115 = vtrace */
E 22
#else
D 22
	0, nosys,			/* 64+51 = nosys */
E 22
I 22
	0, nosys,			/* 115 = nosys */
E 22
#endif
D 18
	0, nosys,			/* 64+52 = nosys */
	0, nosys,			/* 64+53 = nosys */
	0, nosys,			/* 64+54 = nosys */
E 18
I 18
D 22

/* timing and statistics calls from 1.5 */
	1, rtime,			/* 64+52 = rtime */
	1, rusage,			/* 64+53 = rusage */
	1, itimer,			/* 64+54 = itimer */

E 18
	1, resuba,			/* 64+55 = resuba */
D 18
	0, nosys,			/* 64+56 = nosys */
	0, nosys,			/* 64+57 = nosys */
	0, nosys,			/* 64+58 = nosys */
E 18
I 18

/* new generic operations from 2.1 */
E 22
I 22
	2, gettimeofday,		/* 116 = gettimeofday */
	2, getrusage,			/* 117 = getrusage */
D 38
	0, nosys,			/* 118 = nosys */
E 38
I 38
	5, getsockopt,			/* 118 = getsockopt */
E 38
I 34
#ifdef vax
E 34
	1, resuba,			/* 119 = resuba */
I 34
#else
	0, nosys,			/* 119 = nosys */
#endif
E 34
E 22
	3, readv,			/* 120 = readv */
	3, writev,			/* 121 = writev */
D 22
	0, nosys,			/* 122 = nosys */

E 18
D 19
	5, futz,			/* 64+59 = futz */
#ifdef CAD
	3, chfile,			/* 64+60 = chfile */
#else
	0, nosys,			/* 64+60 = nosys */
#endif
E 19
I 19
/* new file system operations from 2.3 */
E 22
I 22
	2, settimeofday,		/* 122 = settimeofday */
E 22
D 20
	3, nosys,			/* 123 = fchown */
	2, nosys,			/* 124 = fchmod */
E 20
I 20
	3, fchown,			/* 123 = fchown */
	2, fchmod,			/* 124 = fchmod */
E 20
E 19
I 17
D 22
#ifdef QUOTA
D 18
	2, setquota,			/* 64+61 = setquota */
E 18
I 18
D 19
	2, setquota,			/* 64+61 = quota */
E 19
I 19
	2, setquota,			/* 125 = quota */
E 19
E 18
#else
E 22
E 17
D 19
	0, nosys,			/* 64+61 = nosys */
E 19
I 19
D 23
	0, nosys,			/* 125 = nosys */
E 23
I 23
	6, recvfrom,			/* 125 = recvfrom */
E 23
E 19
I 17
D 22
#endif
#ifdef MUSH
D 19
	3, mu_msg,			/* 64+62 = mu_msg */
E 19
I 19
	3, mu_msg,			/* 126 = mu_msg */
E 19
#else
E 22
E 17
D 19
	0, nosys,			/* 64+62 = nosys */
E 19
I 19
D 32
	0, nosys,			/* 126 = nosys */
E 19
I 17
D 22
#endif
#ifdef QUOTA
D 18
	4, qquota,			/* 64+63 = quota */
E 18
I 18
D 19
	4, qquota,			/* 64+63 = qquota */
E 19
I 19
	4, qquota,			/* 127 = qquota */
E 19
E 18
#else
E 22
E 17
D 19
	0, nosys,			/* 64+63 = nosys */
E 19
I 19
	0, nosys,			/* 127 = nosys */
E 32
I 32
	2, setreuid,			/* 126 = setreuid */
	2, setregid,			/* 127 = setregid */
E 32
E 19
I 17
D 22
#endif
E 22
I 19
D 20
	2, nosys,			/* 128 = rename */
	2, nosys,			/* 129 = truncate */
	2, nosys,			/* 130 = ftruncate */
E 20
I 20
	2, rename,			/* 128 = rename */
	2, truncate,			/* 129 = truncate */
	2, ftruncate,			/* 130 = ftruncate */
E 20
D 52
	3, flock,			/* 131 = flock */
E 52
I 52
	2, flock,			/* 131 = flock */
E 52
D 22
	0, nosys,			/* 132 = portal */
E 22
I 22
D 43
	7, portal,			/* 132 = portal */
E 43
I 43
	0, nosys,			/* 132 = nosys */
E 43
	6, sendto,			/* 133 = sendto */
	2, shutdown,			/* 134 = shutdown */
	5, socketpair,			/* 135 = socketpair */
D 35
	1, mkdir,			/* 136 = mkdir */
E 35
I 35
	2, mkdir,			/* 136 = mkdir */
E 35
	1, rmdir,			/* 137 = rmdir */
	2, utimes,			/* 138 = utimes */
D 43
	2, getdprop,			/* 139 = getdprop */
	1, revoke,			/* 140 = revoke */
E 43
I 43
D 44
	0, nosys,			/* 139 = nosys */
E 44
I 44
D 61
	0, nosys,			/* 139 = used internally */
E 61
I 61
	0, nosys,			/* 139 = internal (4.2 sigreturn) */
E 61
E 44
D 56
	0, nosys,			/* 140 = nosys */
E 56
I 56
	2, adjtime,			/* 140 = adjtime */
E 56
E 43
D 41
	2, unmount,			/* 141 = unmount */
E 41
I 41
D 50
	0, nosys,			/* 141 = nosys */
E 50
I 50
	3, getpeername,			/* 141 = getpeername */
E 50
E 41
D 60
	2, gethostid,			/* 142 = gethostid */
	2, sethostid,			/* 143 = sethostid */
E 60
I 60
	0, gethostid,			/* 142 = gethostid */
	1, sethostid,			/* 143 = sethostid */
E 60
D 23
	2, getlimit,			/* 144 = getlimit */
	2, setlimit,			/* 145 = setlimit */
E 23
I 23
	2, getrlimit,			/* 144 = getrlimit */
	2, setrlimit,			/* 145 = setrlimit */
E 23
	2, killpg,			/* 146 = killpg */
I 32
D 42
#ifdef MUSH
	3, mu_msg,			/* 147 = mu_msg */
#else
E 42
D 46
	0, nosys,			/* 147 = nosys */
E 46
I 46
D 47
	2, kill,			/* 147 = kill */
E 47
I 47
D 54
	0, nosys,			/* 147 = nosys */
E 54
I 54
D 57
	2, signal,			/* 147 = signal */
E 57
I 57
	0, nosys,			/* 147 = nosys */
E 57
E 54
E 47
E 46
D 42
#endif
#ifdef QUOTA
E 42
	2, setquota,			/* 148 = quota */
	4, qquota,			/* 149 = qquota */
I 40
D 42
#else
	0, nosys,			/* 148 = nosys */
	0, nosys,			/* 149 = nosys */
E 40
#endif
E 42
I 39
	3, getsockname,			/* 150 = getsockname */
I 56
D 61
	0, nosys,			/* 151 = nosys */
	0, nosys,			/* 152 = nosys */
	0, nosys,			/* 153 = nosys */
	0, nosys,			/* 154 = nosys */
E 61
I 61
	/*
D 62
	 * Syscalls 151-170 inclusive are reserved for vendor-specific
E 62
I 62
D 66
	 * Syscalls 151-180 inclusive are reserved for vendor-specific
E 62
	 * system calls.  (This includes various calls added for compatibity
	 * with other Unix variants.)
E 66
I 66
	 * Syscalls 151-180 inclusive are Quasijarus extensions to 4.3BSD ABI.
E 66
	 */
I 66
	3, sigemu,			/* 151 = sigemu */
E 66
E 61
E 56
E 39
E 32
E 22
E 19
E 17
E 16
E 6
};
I 18
int	nsysent = sizeof (sysent) / sizeof (sysent[0]);
E 18
E 1
