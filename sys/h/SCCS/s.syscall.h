h14156
s 00001/00000/00158
d D 5.5 04/01/08 11:17:10 msokolov 21 20
c add sigemu
e
s 00001/00001/00157
d D 5.4 86/04/03 19:19:22 mckusick 20 19
c 147 reverts to being unused
e
s 00003/00003/00155
d D 5.3 85/07/08 12:53:16 bloom 19 18
c fix numbering
e
s 00001/00001/00157
d D 5.2 85/06/09 11:16:58 mckusick 18 17
c 140 becomes adjtime
e
s 00007/00001/00151
d D 5.1 85/05/30 09:41:18 dist 17 16
c Add copyright
e
s 00001/00001/00151
d D 4.15 85/03/11 18:24:42 mckusick 16 15
c add sigreturn()
e
s 00001/00001/00151
d D 4.14 84/08/24 16:52:00 mckusick 15 14
c add `signal' as a system call
e
s 00001/00001/00151
d D 4.13 83/08/11 23:17:14 sam 14 13
c standardize sccs keyword lines
e
s 00001/00001/00151
d D 4.12 83/07/25 18:07:46 sam 13 11
c add getpeername
e
s 00002/00002/00150
d R 4.12 83/06/13 13:54:05 sam 12 11
c missing new kill
e
s 00001/00001/00151
d D 4.11 83/06/09 11:20:45 sam 11 10
c sigrelse purged
e
s 00001/00001/00151
d D 4.10 83/06/05 17:57:40 root 10 9
c hated that name
e
s 00001/00001/00151
d D 4.9 83/06/05 16:24:04 sam 9 8
c sigunblock 
e
s 00001/00001/00151
d D 4.8 83/06/04 10:52:30 root 8 7
c add fcntl
e
s 00007/00007/00145
d D 4.7 83/05/31 00:49:13 sam 7 6
c cleanup a bit to reflect init_sysent.c
e
s 00001/00001/00151
d D 4.6 83/05/10 16:15:10 sam 6 5
c forgot umount 
e
s 00003/00003/00149
d D 4.5 83/05/10 13:24:36 sam 5 4
c some cleanup to reflect 4.2 reality
e
s 00002/00001/00150
d D 4.4 83/03/19 14:12:26 sam 4 3
c add getsockname
e
s 00001/00001/00150
d D 4.3 83/02/10 22:19:40 sam 3 2
c qquota should've been just quota
e
s 00002/00002/00149
d D 4.2 83/01/13 17:44:53 sam 2 1
c socket option stuff
e
s 00151/00000/00000
d D 4.1 82/12/28 14:45:00 sam 1 0
c date and time created 82/12/28 14:45:00 by sam
e
u
U
t
T
I 1
D 14
/*	%W%	(Berkeley)	%G%	*/
E 14
I 14
D 17
/*	%M%	%I%	%E%	*/
E 17
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 17
E 14

#define	SYS_exit	1
#define	SYS_fork	2
#define	SYS_read	3
#define	SYS_write	4
#define	SYS_open	5
#define	SYS_close	6
				/*  7 is old: wait */
D 7
				/*  8 is old: creat */
E 7
I 7
#define	SYS_creat	8
E 7
#define	SYS_link	9
#define	SYS_unlink	10
#define	SYS_execv	11
#define	SYS_chdir	12
				/* 13 is old: time */
#define	SYS_mknod	14
#define	SYS_chmod	15
#define	SYS_chown	16
				/* 17 is old: sbreak */
				/* 18 is old: stat */
#define	SYS_lseek	19
#define	SYS_getpid	20
#define	SYS_mount	21
D 6
				/* 22 is old: umount */
E 6
I 6
#define	SYS_umount	22
E 6
				/* 23 is old: setuid */
#define	SYS_getuid	24
				/* 25 is old: stime */
D 7
				/* 26 is old: ptrace */
E 7
I 7
#define	SYS_ptrace	26
E 7
				/* 27 is old: alarm */
				/* 28 is old: fstat */
				/* 29 is old: pause */
				/* 30 is old: utime */
				/* 31 is old: stty */
				/* 32 is old: gtty */
#define	SYS_access	33
				/* 34 is old: nice */
				/* 35 is old: ftime */
#define	SYS_sync	36
#define	SYS_kill	37
#define	SYS_stat	38
				/* 39 is old: setpgrp */
#define	SYS_lstat	40
#define	SYS_dup		41
#define	SYS_pipe	42
				/* 43 is old: times */
#define	SYS_profil	44
				/* 45 is unused */
				/* 46 is old: setgid */
#define	SYS_getgid	47
				/* 48 is old: sigsys */
				/* 49 is unused */
				/* 50 is unused */
#define	SYS_acct	51
				/* 52 is old: phys */
				/* 53 is old: syslock */
#define	SYS_ioctl	54
#define	SYS_reboot	55
				/* 56 is old: mpxchan */
#define	SYS_symlink	57
#define	SYS_readlink	58
#define	SYS_execve	59
#define	SYS_umask	60
#define	SYS_chroot	61
#define	SYS_fstat	62
				/* 63 is unused */
#define	SYS_getpagesize 64
#define	SYS_mremap	65
D 19
				/* 65 is old: vfork */
				/* 66 is old: vread */
				/* 67 is old: vwrite */
E 19
I 19
				/* 66 is old: vfork */
				/* 67 is old: vread */
				/* 68 is old: vwrite */
E 19
#define	SYS_sbrk	69
#define	SYS_sstk	70
#define	SYS_mmap	71
				/* 72 is old: vadvise */
#define	SYS_munmap	73
#define	SYS_mprotect	74
#define	SYS_madvise	75
D 7
				/* 76 is old: vhangup */
E 7
I 7
#define	SYS_vhangup	76
E 7
				/* 77 is old: vlimit */
#define	SYS_mincore	78
#define	SYS_getgroups	79
#define	SYS_setgroups	80
#define	SYS_getpgrp	81
#define	SYS_setpgrp	82
#define	SYS_setitimer	83
#define	SYS_wait	84
D 5
				/* 85 is old: swapon */
E 5
I 5
#define	SYS_swapon	85
E 5
#define	SYS_getitimer	86
#define	SYS_gethostname	87
#define	SYS_sethostname	88
#define	SYS_getdtablesize 89
#define	SYS_dup2	90
#define	SYS_getdopt	91
D 7
#define	SYS_wrap	92
E 7
I 7
D 8
				/* 92 will be: wrap */
E 8
I 8
#define	SYS_fcntl	92
E 8
E 7
#define	SYS_select	93
#define	SYS_setdopt	94
#define	SYS_fsync	95
#define	SYS_setpriority	96
#define	SYS_socket	97
#define	SYS_connect	98
#define	SYS_accept	99
#define	SYS_getpriority	100
#define	SYS_send	101
#define	SYS_recv	102
D 4
				/* 103 is socketaddr XXX */
E 4
I 4
D 16
				/* 103 was socketaddr */
E 16
I 16
#define	SYS_sigreturn	103
E 16
E 4
#define	SYS_bind	104
D 2
#define	SYS_domain	105
E 2
I 2
#define	SYS_setsockopt	105
E 2
#define	SYS_listen	106
D 5
#define	SYS_ovtimes	107
E 5
I 5
				/* 107 was vtimes */
E 5
#define	SYS_sigvec	108
#define	SYS_sigblock	109
#define	SYS_sigsetmask	110
#define	SYS_sigpause	111
#define	SYS_sigstack	112
#define	SYS_recvmsg	113
#define	SYS_sendmsg	114
				/* 115 is old vtrace */
#define	SYS_gettimeofday 116
#define	SYS_getrusage	117
D 2
				/* 118 is unused */
E 2
I 2
#define	SYS_getsockopt	118
E 2
				/* 119 is old resuba */
#define	SYS_readv	120
#define	SYS_writev	121
#define	SYS_settimeofday 122
#define	SYS_fchown	123
#define	SYS_fchmod	124
#define	SYS_recvfrom	125
#define	SYS_setreuid	126
#define	SYS_setregid	127
#define	SYS_rename	128
#define	SYS_truncate	129
#define	SYS_ftruncate	130
#define	SYS_flock	131
D 7
#define	SYS_portal	132
E 7
I 7
D 9
				/* 132 will be: portal */
E 9
I 9
D 10
#define	SYS_sigunblock	132
E 10
I 10
D 11
#define	SYS_sigrelse	132
E 11
I 11
				/* 132 is unused */
E 11
E 10
E 9
E 7
#define	SYS_sendto	133
#define	SYS_shutdown	134
#define	SYS_socketpair	135
#define	SYS_mkdir	136
#define	SYS_rmdir	137
#define	SYS_utimes	138
D 7
#define	SYS_getdprop	139
E 7
I 7
				/* 139 is unused */
E 7
D 18
#define	SYS_revoke	140
E 18
I 18
#define	SYS_adjtime	140
E 18
D 5
#define	SYS_unmount	141
E 5
I 5
D 13
				/* 141 is unused */
E 13
I 13
#define	SYS_getpeername	141
E 13
E 5
#define	SYS_gethostid	142
#define	SYS_sethostid	143
#define	SYS_getrlimit	144
#define	SYS_setrlimit	145
#define	SYS_killpg	146
D 7
#define	SYS_mu_msg	147
E 7
I 7
D 15
				/* 147 is unused */
E 15
I 15
D 20
#define	SYS_signal	147
E 20
I 20
				/* 147 is unused */
E 20
E 15
E 7
#define	SYS_setquota	148
D 3
#define	SYS_qquota	149
E 3
I 3
#define	SYS_quota	149
I 4
#define	SYS_getsockname	150
I 21
#define	SYS_sigemu	151
E 21
E 4
E 3
E 1
