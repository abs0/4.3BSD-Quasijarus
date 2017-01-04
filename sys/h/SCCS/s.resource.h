h40719
s 00001/00001/00063
d D 7.1 86/06/04 23:27:23 mckusick 4 3
c 4.3BSD release version
e
s 00007/00001/00057
d D 6.2 85/06/08 15:06:30 mckusick 3 2
c Add copyright
e
s 00000/00000/00058
d D 6.1 83/07/29 06:13:50 sam 2 1
c 4.2 distribution
e
s 00058/00000/00000
d D 4.1 83/02/10 21:42:10 sam 1 0
c date and time created 83/02/10 21:42:10 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
D 4
 * Copyright (c) 1982 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

/*
 * Process priority specifications to get/setpriority.
 */
#define	PRIO_MIN	-20
#define	PRIO_MAX	20

#define	PRIO_PROCESS	0
#define	PRIO_PGRP	1
#define	PRIO_USER	2

/*
 * Resource utilization information.
 */

#define	RUSAGE_SELF	0
#define	RUSAGE_CHILDREN	-1

struct	rusage {
	struct timeval ru_utime;	/* user time used */
	struct timeval ru_stime;	/* system time used */
	long	ru_maxrss;		/* max resident set size */
#define	ru_first	ru_ixrss
	long	ru_ixrss;		/* integral shared memory size */
	long	ru_idrss;		/* integral unshared data " */
	long	ru_isrss;		/* integral unshared stack " */
	long	ru_minflt;		/* page reclaims */
	long	ru_majflt;		/* page faults */
	long	ru_nswap;		/* swaps */
	long	ru_inblock;		/* block input operations */
	long	ru_oublock;		/* block output operations */
	long	ru_msgsnd;		/* messages sent */
	long	ru_msgrcv;		/* messages received */
	long	ru_nsignals;		/* signals received */
	long	ru_nvcsw;		/* voluntary context switches */
	long	ru_nivcsw;		/* involuntary " */
#define	ru_last		ru_nivcsw
};

/*
 * Resource limits
 */
#define	RLIMIT_CPU	0		/* cpu time in milliseconds */
#define	RLIMIT_FSIZE	1		/* maximum file size */
#define	RLIMIT_DATA	2		/* data size */
#define	RLIMIT_STACK	3		/* stack size */
#define	RLIMIT_CORE	4		/* core file size */
#define	RLIMIT_RSS	5		/* resident set size */

#define	RLIM_NLIMITS	6		/* number of resource limits */

#define	RLIM_INFINITY	0x7fffffff

struct rlimit {
	int	rlim_cur;		/* current (soft) limit */
	int	rlim_max;		/* maximum value for rlim_cur */
};
E 1
