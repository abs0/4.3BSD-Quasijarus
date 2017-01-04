h35395
s 00002/00002/00071
d D 5.2 86/03/09 19:24:42 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00064
d D 5.1 85/05/30 10:30:28 dist 2 1
c Add copyright
e
s 00065/00000/00000
d D 4.1 83/05/31 00:28:51 sam 1 0
c date and time created 83/05/31 00:28:51 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3
E 2

#include <sys/time.h>
#include <sys/resource.h>

/*
 * Backwards compatible vtimes.
 */
struct vtimes {
	int	vm_utime;		/* user time (60'ths) */
	int	vm_stime;		/* system time (60'ths) */
	/* divide next two by utime+stime to get averages */
	unsigned vm_idsrss;		/* integral of d+s rss */
	unsigned vm_ixrss;		/* integral of text rss */
	int	vm_maxrss;		/* maximum rss */
	int	vm_majflt;		/* major page faults */
	int	vm_minflt;		/* minor page faults */
	int	vm_nswap;		/* number of swaps */
	int	vm_inblk;		/* block reads */
	int	vm_oublk;		/* block writes */
};

vtimes(par, chi)
	register struct vtimes *par, *chi;
{
	struct rusage ru;

	if (par) {
		if (getrusage(RUSAGE_SELF, &ru) < 0)
			return (-1);
		getvtimes(&ru, par);
	}
	if (chi) {
		if (getrusage(RUSAGE_CHILDREN, &ru) < 0)
			return (-1);
		getvtimes(&ru, chi);
	}
	return (0);
}

static
getvtimes(aru, avt)
	register struct rusage *aru;
	register struct vtimes *avt;
{

	avt->vm_utime = scale60(&aru->ru_utime);
	avt->vm_stime = scale60(&aru->ru_stime);
	avt->vm_idsrss = ((aru->ru_idrss+aru->ru_isrss) / 100) * 60;
	avt->vm_ixrss = aru->ru_ixrss / 100 * 60;
	avt->vm_maxrss = aru->ru_maxrss;
	avt->vm_majflt = aru->ru_majflt;
	avt->vm_minflt = aru->ru_minflt;
	avt->vm_nswap = aru->ru_nswap;
	avt->vm_inblk = aru->ru_inblock;
	avt->vm_oublk = aru->ru_oublock;
}

static
scale60(tvp)
	register struct timeval *tvp;
{

	return (tvp->tv_sec * 60 + tvp->tv_usec / 16667);
}
E 1
