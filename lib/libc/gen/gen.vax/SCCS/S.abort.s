h45729
s 00007/00000/00010
d D 4.3 85/01/09 14:31:10 serge 3 2
c set SIGILL to SIG_DFL and unblock it before halt'ing
e
s 00001/00001/00009
d D 4.2 84/11/01 23:51:10 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00010/00000/00000
d D 4.1 83/06/27 15:41:42 root 1 0
c date and time created 83/06/27 15:41:42 by root
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/* C library -- abort */

#include "DEFS.h"

D 2
ENTRY(abort)
E 2
I 2
ENTRY(abort, 0)
I 3
	pushl	$-1
	calls	$1,_sigblock	# sigblock(~0);
	pushl	$0
	pushl	$4
	calls	$2,_signal	# signal(SIGILL, SIG_DFL);
	pushl	$-9
	calls	$1,_sigsetmask	# sigsetmask(~sigmask(SIGILL));
E 3
E 2
	halt
	clrl	r0
	ret
E 1
