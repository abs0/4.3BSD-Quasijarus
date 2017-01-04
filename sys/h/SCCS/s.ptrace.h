h24891
s 00001/00001/00022
d D 7.1 86/06/04 23:26:54 mckusick 3 2
c 4.3BSD release version
e
s 00007/00001/00016
d D 5.1 85/05/30 09:39:19 dist 2 1
c Add copyright
e
s 00017/00000/00000
d D 4.1 84/04/11 09:15:04 ralph 1 0
c date and time created 84/04/11 09:15:04 by ralph
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
D 3
 * Copyright (c) 1980 Regents of the University of California.
E 3
I 3
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

#ifndef _PTRACE_
#define _PTRACE_

#define PT_TRACE_ME	0	/* child declares it's being traced */
#define PT_READ_I	1	/* read word in child's I space */
#define PT_READ_D	2	/* read word in child's D space */
#define PT_READ_U	3	/* read word in child's user structure */
#define PT_WRITE_I	4	/* write word in child's I space */
#define PT_WRITE_D	5	/* write word in child's D space */
#define PT_WRITE_U	6	/* write word in child's user structure */
#define PT_CONTINUE	7	/* continue the child */
#define PT_KILL		8	/* kill the child process */
#define PT_STEP		9	/* single step the child */

#endif
E 1
