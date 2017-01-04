h11731
s 00002/00002/00034
d D 5.2 86/03/09 19:56:48 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00027
d D 5.1 85/06/05 12:36:01 mckusick 4 3
c Add copyright
e
s 00023/00020/00005
d D 4.3 85/03/11 22:33:17 mckusick 3 2
c properly track SV_INTERRUPT, SV_ONSTACK, and mask
e
s 00001/00001/00024
d D 4.2 85/01/15 15:09:47 ralph 2 1
c ENTRY macro changed.
e
s 00025/00000/00000
d D 4.1 84/05/16 15:19:24 ralph 1 0
c date and time created 84/05/16 15:19:24 by ralph
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5
E 4
I 3

E 3
/*
 * Almost backwards compatible signal.
D 3
 *	int (*signal(s, a))() int s, (*a)();
E 3
 */
D 3
#include <syscall.h>
#include "DEFS.h"
E 3
I 3
#include <signal.h>
E 3

D 2
ENTRY(signal)
E 2
I 2
D 3
ENTRY(signal, 0)
E 2
	subl2	$24,sp			# struct sigvec osv, sv;
	movl	8(ap),-24(fp)		# sv.sv_handler = a;
	clrq	-20(fp)			# sv.sv_mask = sv.sv_onstack = 0;
	pushal	-12(fp)			# &osv
	pushal	-24(fp)			# &sv
	pushl	4(ap)			# s
	moval	-4(sp),ap
	chmk	$SYS_sigvec		# sigvec(s, &sv, &osv)
	jcs	err
	movl	-12(fp),r0		# return osv.sv_handler;
	ret
err:
	.globl	_errno
	movl	r0,_errno
	mnegl	$1,r0
	ret
E 3
I 3
int (*
signal(s, a))()
	int s, (*a)();
{
	struct sigvec osv, sv;
	static int mask[NSIG];
	static int flags[NSIG];

	sv.sv_handler = a;
	sv.sv_mask = mask[s];
	sv.sv_flags = flags[s];
	if (sigvec(s, &sv, &osv) < 0)
		return (BADSIG);
	if (sv.sv_mask != osv.sv_mask || sv.sv_flags != osv.sv_flags) {
		mask[s] = sv.sv_mask = osv.sv_mask;
		flags[s] = sv.sv_flags = osv.sv_flags;
		if (sigvec(s, &sv, 0) < 0)
			return (BADSIG);
	}
	return (osv.sv_handler);
}
E 3
E 1
