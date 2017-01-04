h40622
s 00009/00003/00309
d D 7.4 02/09/15 00:53:36 msokolov 50 49
c knock some sense into T_SEGFLT handling wrt stack expansion
e
s 00001/00001/00311
d D 7.3 88/05/19 15:21:52 karels 49 48
c rename KDB => KADB
e
s 00006/00003/00306
d D 7.2 87/02/21 11:19:14 karels 48 47
c kdb (for sam; untested); misc.
e
s 00001/00001/00308
d D 7.1 86/06/05 00:48:46 mckusick 47 46
c 4.3BSD release version
e
s 00002/00002/00307
d D 6.8 86/02/23 23:07:19 karels 46 45
c lint
e
s 00012/00005/00297
d D 6.7 86/02/02 23:36:40 karels 45 43
c 63 has been special for too long
e
s 00012/00005/00297
d R 6.7 86/02/02 21:09:29 karels 44 43
c 63 has been special too long
e
s 00007/00001/00295
d D 6.6 85/06/08 13:46:29 mckusick 43 42
c Add copyright
e
s 00023/00034/00273
d D 6.5 85/03/12 00:36:23 mckusick 42 41
c cleanup syscall dispatcher; formalize sigreturn()
e
s 00013/00013/00294
d D 6.4 84/08/28 18:10:49 bloom 41 40
c Change to includes.  No more ../h
e
s 00000/00001/00307
d D 6.3 84/07/08 16:24:10 mckusick 40 39
c rework `namei' interface to eliminate global variables
e
s 00001/00001/00307
d D 6.2 84/06/10 01:11:46 sam 39 38
c don't clear C bit in the wrong place (return through signal 
c handler can cause restarted wait3 to turn into wait) -- should make 
c wait3 a separate system call.
e
s 00000/00000/00308
d D 6.1 83/08/18 15:04:15 sam 38 37
c 4.2 distribution
e
s 00001/00001/00307
d D 4.30 83/08/18 15:03:28 sam 37 35
c improper bounds check on indirect sys call numbers (from kre)
e
s 00000/00000/00308
d R 6.1 83/07/29 07:21:21 sam 36 35
c 4.2 distribution
e
s 00001/00001/00307
d D 4.29 83/06/26 21:59:45 sam 35 34
c handled indirect sys calls wrong
e
s 00007/00000/00301
d D 4.28 83/06/02 16:00:05 sam 34 33
c new signals
e
s 00001/00001/00300
d D 4.27 83/01/22 23:42:45 sam 33 32
c purge SDLYU from proc structure
e
s 00004/00003/00297
d D 4.26 82/12/17 11:56:52 sam 32 31
c sun merge
e
s 00027/00000/00273
d D 4.25 82/12/09 23:45:36 sam 31 30
c profil returns
e
s 00025/00000/00248
d D 4.24 82/11/13 22:58:57 sam 30 29
c merge of 4.1b with 4.1c
e
s 00016/00016/00232
d D 4.23 82/10/31 15:15:10 root 29 28
c change to T_... names for trap codes
e
s 00001/00001/00247
d D 4.22 82/10/21 23:57:08 root 28 27
c lint
e
s 00001/00001/00247
d D 4.21 82/10/21 20:58:53 root 27 26
c lint
e
s 00003/00001/00245
d D 4.20 82/10/20 01:37:41 root 26 25
c lint
e
s 00004/00000/00242
d D 4.19 82/10/17 15:25:06 root 25 24
c fix lint
e
s 00008/00006/00234
d D 4.18 82/10/13 22:14:56 root 24 23
c rearrange header files
e
s 00001/00001/00239
d D 4.17 82/09/12 03:24:46 root 23 22
c qsav->qsave
e
s 00003/00013/00237
d D 4.16 82/09/04 09:32:45 root 22 21
c no more addupc; different counter names; changed timer stuff
e
s 00001/00001/00249
d D 4.15 82/07/24 18:24:12 root 21 20
c restore id keywords
e
s 00006/00005/00244
d D 4.14 82/07/24 18:23:46 root 20 19
c remove constant number of system calls 
e
s 00031/00003/00218
d D 4.13 82/07/12 17:03:05 kre 19 18
c make the message "panic: trap" more intelligent;
c Also, set accounting flag whenever have compat mode fault
e
s 00001/00000/00220
d D 4.12 82/03/31 09:09:14 wnj 18 17
c include assym.s
e
s 00000/00008/00220
d D 4.11 81/11/20 14:44:19 wnj 17 16
c more lint
e
s 00001/00001/00227
d D 4.10 81/07/09 04:30:18 root 16 15
c lint
e
s 00000/00006/00228
d D 4.9 81/04/15 12:35:53 wnj 15 14
c see if resched needed after page-fault in user mode
e
s 00001/00001/00233
d D 4.8 81/03/09 01:50:14 wnj 14 13
c lint and a few minor fixed
e
s 00001/00001/00233
d D 4.7 81/03/09 00:33:36 wnj 13 12
c lint
e
s 00001/00000/00233
d D 4.6 81/03/05 01:29:59 wnj 12 11
c handle floating point/ ill instr with u.u_code
e
s 00011/00010/00222
d D 4.5 81/03/03 12:13:55 wnj 11 10
c pass floating point codes
e
s 00009/00001/00223
d D 4.4 81/02/15 20:26:30 wnj 10 9
c ASTFLT stuff
e
s 00001/00002/00223
d D 4.3 80/12/16 15:58:59 wnj 9 8
c comet changes
e
s 00002/00002/00223
d D 4.2 80/11/09 23:35:17 bill 8 7
c function results (void)'ed for minor lint
e
s 00000/00000/00225
d D 4.1 80/11/09 17:33:05 bill 7 6
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00000/00003/00225
d D 3.6 80/10/02 23:01:14 bill 6 5
c remove halt on trap from kernel mode
e
s 00001/00001/00227
d D 3.5 80/06/07 02:48:25 bill 5 4
c %H%->%G%
e
s 00001/00001/00227
d D 3.4 80/05/24 19:45:36 bill 4 3
c new signal stuff
e
s 00001/00000/00227
d D 3.3 80/05/18 11:37:42 bill 3 2
c replace sccs id
e
s 00032/00065/00195
d D 3.2 80/05/18 11:36:58 bill 2 1
c first stab
e
s 00260/00000/00000
d D 3.1 80/04/09 16:04:41 bill 1 0
c date and time created 80/04/09 16:04:41 by bill
e
u
U
f b 
t
T
I 3
D 5
/*	%M%	%I%	%H%	*/
E 5
I 5
D 14
/*	%M%	%I%	%G%	*/
E 14
I 14
D 20
/*	%M%	%I%	%E%	*/
E 20
I 20
D 21
/*	trap.c	4.14	82/07/18	*/
E 21
I 21
D 43
/*	%M%	%I%	%E%	*/
E 43
I 43
/*
D 47
 * Copyright (c) 1982 Regents of the University of California.
E 47
I 47
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 47
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 43
E 21
E 20
E 14
E 5
E 3
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2

I 32
D 41
#include "../machine/psl.h"
#include "../machine/reg.h"
#include "../machine/pte.h"
E 41
I 41
#include "psl.h"
#include "reg.h"
#include "pte.h"
I 50
#include "vmparam.h"
E 50
E 41

E 32
I 2
D 9

E 9
E 2
D 41
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
E 41
I 41
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
E 41
I 18
#include "assym.s"
E 18
D 41
#include "../h/proc.h"
D 32
#include "../h/reg.h"
E 32
#include "../h/seg.h"
D 24
#include "../h/trap.h"
E 24
I 24
#include "../vax/trap.h"
E 24
D 32
#include "../h/psl.h"
#include "../h/pte.h"
E 32
I 2
D 24
#include "../h/inline.h"
I 10
#include "../h/mtpr.h"
E 24
I 19
#include "../h/acct.h"
I 31
#include "../h/kernel.h"
E 41
I 41
#include "proc.h"
#include "seg.h"
#include "trap.h"
#include "acct.h"
#include "kernel.h"
E 41
E 31
I 30
#ifdef SYSCALLTRACE
#include "../sys/syscalls.c"
#endif
E 30
E 19
E 10
E 2

I 24
D 41
#include "../vax/mtpr.h"
E 41
I 41
#include "mtpr.h"
E 41

E 24
#define	USER	040		/* user-mode flag added to type */

D 20
struct	sysent	sysent[128];
E 20
I 20
struct	sysent	sysent[];
int	nsysent;
E 20

I 19
char	*trap_type[] = {
	"Reserved addressing mode",
	"Privileged instruction",
	"Reserved operand",
	"Breakpoint",
	"Xfc trap",
	"Syscall trap",
	"Arithmetic fault",
	"Ast trap",
	"Segmentation fault",
	"Protection fault",
	"Trace trap",
	"Compatibility mode trap",
D 24
/**					these never get to "default" case
E 24
I 24
D 48
#ifdef notdef
E 48
E 24
	"Page fault",
	"Page table fault",
D 24
**/
E 24
I 24
D 48
#endif
E 48
I 48
	"Kernel debugger trap",
E 48
E 24
};
D 48
#define	TRAP_TYPES	(sizeof trap_type / sizeof trap_type[0])
E 48
I 48
int	TRAP_TYPES = (sizeof trap_type / sizeof trap_type[0]);
E 48

E 19
/*
 * Called from the trap handler when a processor trap occurs.
 */
/*ARGSUSED*/
trap(sp, type, code, pc, psl)
D 24
unsigned code;
E 24
I 24
D 50
	int sp, type;
E 50
I 50
	unsigned sp;
	int type;
E 50
	unsigned code;
	int pc, psl;
E 24
{
	register int *locr0 = ((int *)&psl)-PS;
	register int i;
	register struct proc *p;
I 31
	struct timeval syst;
E 31
D 22
	time_t syst;
E 22

I 31
	syst = u.u_ru.ru_stime;
E 31
D 22
	syst = u.u_vm.vm_stime;
E 22
	if (USERMODE(locr0[PS])) {
		type |= USER;
		u.u_ar0 = locr0;
	}
	switch (type) {

	default:
I 48
D 49
#ifdef KDB
E 49
I 49
#ifdef KADB
E 49
		if (kdb_trap(&psl))
			return;
#endif
E 48
D 9
		printf("trap type %d, code = %x\n", type, code);
E 9
I 9
		printf("trap type %d, code = %x, pc = %x\n", type, code, pc);
I 19
		type &= ~USER;
		if ((unsigned)type < TRAP_TYPES)
			panic(trap_type[type]);
E 19
E 9
D 6
#ifdef ERNIE
		asm("halt");
#endif
E 6
		panic("trap");

D 29
	case PROTFLT + USER:	/* protection fault */
E 29
I 29
	case T_PROTFLT+USER:	/* protection fault */
E 29
		i = SIGBUS;
		break;

D 29
	case PRIVINFLT + USER:	/* privileged instruction fault */
	case RESADFLT + USER:	/* reserved addressing fault */
	case RESOPFLT + USER:	/* resereved operand fault */
E 29
I 29
	case T_PRIVINFLT+USER:	/* privileged instruction fault */
	case T_RESADFLT+USER:	/* reserved addressing fault */
	case T_RESOPFLT+USER:	/* resereved operand fault */
E 29
I 12
		u.u_code = type &~ USER;
E 12
D 2
		i = SIGINS;
E 2
I 2
		i = SIGILL;
E 2
		break;

D 10
	case RESCHED + USER:	/* Allow process switch */
E 10
I 10
D 22
	case ASTFLT + USER:	/* Allow process switch */
E 22
I 22
D 29
	case ASTFLT + USER:
E 29
I 29
	case T_ASTFLT+USER:
E 29
E 22
		astoff();
I 31
		if ((u.u_procp->p_flag & SOWEUPC) && u.u_prof.pr_scale) {
			addupc(pc, &u.u_prof, 1);
			u.u_procp->p_flag &= ~SOWEUPC;
		}
E 31
D 22
		if ((u.u_procp->p_flag & SOWEUPC) && u.u_prof.pr_scale) {
			addupc(pc, &u.u_prof, 1);
			u.u_procp->p_flag &= ~SOWEUPC;
		}
E 22
D 15
		if (runrun == 0)
			return;
E 15
E 10
		goto out;

D 2
/* OLD CODE... see syscall() below
	case SYSCALL + USER:
		params = (caddr_t)locr0[AP] + NBPW;
		u.u_error = 0;
		callp = &sysent[code&0177];
		if (callp == sysent) {
			i = fuword(params);
			params += NBPW;
			callp = &sysent[i&0177];
		}
		if (i = callp->sy_narg)
			if (copyin(params, &u.u_arg[0], i*NBPW)) {
				u.u_error = EFAULT;
				goto bad;
			}
		u.u_ap = u.u_arg;
		locr0[PS] &= ~PSL_C;
		u.u_dirp = (caddr_t)u.u_arg[0];
		u.u_r.r_val1 = 0;
		u.u_r.r_val2 = locr0[R1];
		if (setjmp(u.u_qsav)) {
			if (u.u_error==0)
				u.u_error = EINTR;
		} else
			(*(callp->sy_call))();
		if(u.u_error) {
			locr0[R0] = u.u_error;
			locr0[PS] |= PSL_C;
		} else {
			locr0[R0] = u.u_r.r_val1;
			locr0[R1] = u.u_r.r_val2;
		}
		goto out;
END OF OLD CODE REPLACED BY syscall() */

E 2
D 29
	case ARITHTRAP + USER:
E 29
I 29
	case T_ARITHTRAP+USER:
E 29
I 11
		u.u_code = code;
E 11
D 2
		i = SIGFPT;
E 2
I 2
		i = SIGFPE;
E 2
		break;

	/*
	 * If the user SP is above the stack segment,
	 * grow the stack automatically.
	 */
D 11
	case SEGFLT + USER: /* segmentation exception */
		if(grow((unsigned)locr0[SP]) || grow(code))
E 11
I 11
D 29
	case SEGFLT + USER:
E 29
I 29
	case T_SEGFLT+USER:
E 29
D 50
		if (grow((unsigned)locr0[SP]) || grow(code))
E 11
			goto out;
E 50
I 50
		if (code >= P1LOW && code < USRSTACK) {
			if (sp < code && grow(sp))
				goto out;
			if (grow(code))
				goto out;
		}
E 50
D 2
		i = SIGSEG;
E 2
I 2
		i = SIGSEGV;
E 2
		break;

D 29
	case TABLEFLT:		/* allow page table faults in kernel mode */
	case TABLEFLT + USER:   /* page table fault */
E 29
I 29
	case T_TABLEFLT:	/* allow page table faults in kernel mode */
	case T_TABLEFLT+USER:   /* page table fault */
E 29
D 11
		panic("page table fault");
E 11
I 11
		panic("ptable fault");
E 11

D 29
	case PAGEFLT:		/* allow page faults in kernel mode */
	case PAGEFLT + USER:	/* page fault */
E 29
I 29
	case T_PAGEFLT:		/* allow page faults in kernel mode */
	case T_PAGEFLT+USER:	/* page fault */
E 29
		i = u.u_error;
D 11
		pagein(code);   /* bring in page containing virtual addr */
E 11
I 11
D 33
		pagein(code);
E 33
I 33
		pagein(code, 0);
E 33
E 11
		u.u_error = i;
D 11
/*
E 11
I 11
D 15
#ifdef notdef
E 15
E 11
D 29
		if (type == PAGEFLT)
E 29
I 29
		if (type == T_PAGEFLT)
E 29
D 11
*/
E 11
			return;
D 11
/*
E 11
		goto out;
D 11
*/
E 11
I 11
D 15
#else
		return;
#endif
E 15
E 11

D 29
	case BPTFLT + USER:	/* bpt instruction fault */
	case TRCTRAP + USER:	/* trace trap */
E 29
I 29
	case T_BPTFLT+USER:	/* bpt instruction fault */
	case T_TRCTRAP+USER:	/* trace trap */
E 29
D 11
		locr0[PS] &= ~PSL_T;	/* turn off trace bit */
E 11
I 11
		locr0[PS] &= ~PSL_T;
E 11
D 2
		i = SIGTRC;
E 2
I 2
		i = SIGTRAP;
E 2
		break;

D 29
	case XFCFLT + USER:	/* xfc instruction fault */
E 29
I 29
	case T_XFCFLT+USER:	/* xfc instruction fault */
E 29
		i = SIGEMT;
		break;

D 29
	case COMPATFLT + USER:	/* compatibility mode fault */
E 29
I 29
	case T_COMPATFLT+USER:	/* compatibility mode fault */
E 29
I 19
		u.u_acflag |= ACOMPAT;
E 19
D 11
		u.u_cfcode = code;
E 11
I 11
		u.u_code = code;
E 11
D 2
		i = SIGINS;
E 2
I 2
		i = SIGILL;
E 2
		break;
	}
	psignal(u.u_procp, i);
out:
	p = u.u_procp;
D 2
	if(p->p_sig && issig())		/* check p_sig to save time */
E 2
I 2
	if (p->p_cursig || ISSIG(p))
E 2
		psig();
	p->p_pri = p->p_usrpri;
	if (runrun) {
		/*
		 * Since we are u.u_procp, clock will normally just change
		 * our priority without moving us from one queue to another
		 * (since the running process is not on a queue.)
		 * If that happened after we setrq ourselves but before we
		 * swtch()'ed, we might not be on the queue indicated by
		 * our priority.
		 */
D 8
		spl6();
E 8
I 8
D 46
		(void) spl6();
E 46
I 46
		(void) splclock();
E 46
E 8
		setrq(p);
I 22
		u.u_ru.ru_nivcsw++;
E 22
		swtch();
	}
I 31
	if (u.u_prof.pr_scale) {
		int ticks;
		struct timeval *tv = &u.u_ru.ru_stime;

		ticks = ((tv->tv_sec - syst.tv_sec) * 1000 +
			(tv->tv_usec - syst.tv_usec) / 1000) / (tick / 1000);
		if (ticks)
			addupc(locr0[PC], &u.u_prof, ticks);
	}
E 31
D 22
	if (u.u_prof.pr_scale && (syst -= u.u_vm.vm_stime))
D 13
		addupc((caddr_t)locr0[PC], &u.u_prof, (int)-syst);
E 13
I 13
		addupc(locr0[PC], &u.u_prof, (int)-syst);
E 22
E 13
	curpri = p->p_pri;
}

I 30
#ifdef SYSCALLTRACE
int syscalltrace = 0;
#endif
E 30
D 2
#ifdef FASTVAX
asm(".globl _eintr");
#endif

E 2
/*
 * Called from the trap handler when a system call occurs
 */
/*ARGSUSED*/
syscall(sp, type, code, pc, psl)
D 20
unsigned code;
E 20
I 20
	unsigned code;
E 20
{
	register int *locr0 = ((int *)&psl)-PS;
	register caddr_t params;		/* known to be r10 below */
	register int i;				/* known to be r9 below */
	register struct sysent *callp;
	register struct proc *p;
D 22
	time_t syst;
E 22
I 2
	int opc;
I 31
	struct timeval syst;
E 31
E 2

I 31
	syst = u.u_ru.ru_stime;
E 31
D 22
	syst = u.u_vm.vm_stime;
E 22
	if (!USERMODE(locr0[PS]))
		panic("syscall");
	u.u_ar0 = locr0;
I 34
D 42
	if (code == 139) {			/* XXX */
		sigcleanup();			/* XXX */
		goto done;			/* XXX */
	}
E 42
I 42
	if (code == 139) {			/* XXX 4.2 COMPATIBILITY */
		osigcleanup();			/* XXX 4.2 COMPATIBILITY */
		goto done;			/* XXX 4.2 COMPATIBILITY */
	}					/* XXX 4.2 COMPATIBILITY */
E 42
E 34
	params = (caddr_t)locr0[AP] + NBPW;
	u.u_error = 0;
I 2
D 4
	opc = u.u_ar0[PC] - 2;
E 4
I 4
	opc = pc - 2;
E 4
	if (code > 63)
		opc -= 2;
E 2
D 20
	callp = &sysent[code&0177];
E 20
I 20
D 45
	callp = (code >= nsysent) ? &sysent[63] : &sysent[code];
E 20
	if (callp == sysent) {
		i = fuword(params);
		params += NBPW;
D 20
		callp = &sysent[i&0177];
E 20
I 20
D 35
		callp = (code >= nsysent) ? &sysent[63] : &sysent[code];
E 35
I 35
D 37
		callp = (code >= nsysent) ? &sysent[63] : &sysent[i];
E 37
I 37
		callp = ((unsigned)i >= nsysent) ? &sysent[63] : &sysent[i];
E 45
I 45
	if (code >= nsysent)
		callp = &sysent[0];		/* indir (illegal) */
	else {
		callp = &sysent[code];
		if (callp == sysent) {		/* indir */
			i = fuword(params);
			params += NBPW;
			if ((unsigned)i >= nsysent)
				callp = &sysent[0];
			else
				callp = &sysent[i];
		}
E 45
E 37
E 35
E 20
	}
D 42
	if (i = callp->sy_narg * sizeof (int)) {
I 25
#ifndef lint
E 25
D 2
		asm("prober $3,r9,(r10)");
		asm("bnequ ok");
		u.u_error = EFAULT;
		goto bad;
asm("ok:");
		asm("movc3 r9,(r10),_u+U_ARG");
E 2
I 2
		asm("prober $3,r9,(r10)");		/* GROT */
		asm("bnequ ok");			/* GROT */
		u.u_error = EFAULT;			/* GROT */
		goto bad;				/* GROT */
asm("ok:");						/* GROT */
		asm("movc3 r9,(r10),_u+U_ARG");		/* GROT */
I 25
#else
D 26
		bcopy(params, u.u_arg, i);
E 26
I 26
D 27
		bcopy(params, u.u_arg, (u_int)i);
E 27
I 27
D 28
		bcopy(params, (caddr_)u.u_arg, (u_int)i);
E 28
I 28
		bcopy(params, (caddr_t)u.u_arg, (u_int)i);
E 28
E 27
E 26
#endif
E 42
I 42
	if ((i = callp->sy_narg * sizeof (int)) &&
	    (u.u_error = copyin(params, (caddr_t)u.u_arg, (u_int)i)) != 0) {
		locr0[R0] = u.u_error;
		locr0[PS] |= PSL_C;	/* carry bit */
		goto done;
E 42
E 25
E 2
	}
D 42
	u.u_ap = u.u_arg;
E 42
D 2
	locr0[PS] &= ~PSL_C;
E 2
D 40
	u.u_dirp = (caddr_t)u.u_arg[0];
E 40
	u.u_r.r_val1 = 0;
	u.u_r.r_val2 = locr0[R1];
D 2
	/*
	 * INLINE EXPANSION OF setjmp().  NOTE THAT THIS ONLY
	 * RESTORES fp,sp, and r11=locr0 ON INTERRRUPTS (MATCHING
	 * CODE IN slp.c).
	 */
	asm("movl fp,_u+U_QSAV");
	asm("movl sp,_u+U_QSAV+4");
	asm("movl r11,_u+U_QSAV+8");
	(*(callp->sy_call))();
asm("_eintr:");
	if(u.u_error) {
E 2
I 2
D 23
	if (setjmp(u.u_qsav)) {
E 23
I 23
	if (setjmp(&u.u_qsave)) {
E 23
D 42
		if (u.u_error == 0 && u.u_eosys == JUSTRETURN)
E 42
I 42
		if (u.u_error == 0 && u.u_eosys != RESTARTSYS)
E 42
			u.u_error = EINTR;
	} else {
D 42
		u.u_eosys = JUSTRETURN;
E 42
I 42
		u.u_eosys = NORMALRETURN;
E 42
I 30
#ifdef SYSCALLTRACE
		if (syscalltrace) {
			register int i;
			char *cp;

			if (code >= nsysent)
				printf("0x%x", code);
			else
				printf("%s", syscallnames[code]);
			cp = "(";
			for (i= 0; i < callp->sy_narg; i++) {
				printf("%s%x", cp, u.u_arg[i]);
				cp = ", ";
			}
			if (i)
				putchar(')', 0);
			putchar('\n', 0);
		}
#endif
E 30
		(*(callp->sy_call))();
	}
D 39
	locr0[PS] &= ~PSL_C;
E 39
D 42
	if (u.u_eosys == RESTARTSYS)
E 42
I 42
	if (u.u_eosys == NORMALRETURN) {
		if (u.u_error) {
			locr0[R0] = u.u_error;
			locr0[PS] |= PSL_C;	/* carry bit */
		} else {
			locr0[R0] = u.u_r.r_val1;
			locr0[R1] = u.u_r.r_val2;
			locr0[PS] &= ~PSL_C;
		}
	} else if (u.u_eosys == RESTARTSYS)
E 42
		pc = opc;
I 34
D 42
#ifdef notdef
E 34
	else if (u.u_eosys == SIMULATERTI)
		dorti();
I 34
#endif
E 34
	else if (u.u_error) {
I 26
#ifndef lint
E 26
E 2
bad:
I 26
#endif
E 26
		locr0[R0] = u.u_error;
		locr0[PS] |= PSL_C;	/* carry bit */
	} else {
		locr0[R0] = u.u_r.r_val1;
		locr0[R1] = u.u_r.r_val2;
I 39
		locr0[PS] &= ~PSL_C;
E 39
	}
E 42
I 42
	/* else if (u.u_eosys == JUSTRETURN) */
		/* nothing to do */
E 42
I 34
done:
E 34
	p = u.u_procp;
D 2
	if(p->p_sig && issig())		/* check p_sig to save time */
E 2
I 2
	if (p->p_cursig || ISSIG(p))
E 2
		psig();
	p->p_pri = p->p_usrpri;
	if (runrun) {
		/*
		 * Since we are u.u_procp, clock will normally just change
		 * our priority without moving us from one queue to another
		 * (since the running process is not on a queue.)
		 * If that happened after we setrq ourselves but before we
		 * swtch()'ed, we might not be on the queue indicated by
		 * our priority.
		 */
D 8
		spl6();
E 8
I 8
D 46
		(void) spl6();
E 46
I 46
		(void) splclock();
E 46
E 8
		setrq(p);
I 22
		u.u_ru.ru_nivcsw++;
E 22
		swtch();
I 31
	}
	if (u.u_prof.pr_scale) {
		int ticks;
		struct timeval *tv = &u.u_ru.ru_stime;

		ticks = ((tv->tv_sec - syst.tv_sec) * 1000 +
			(tv->tv_usec - syst.tv_usec) / 1000) / (tick / 1000);
		if (ticks)
			addupc(locr0[PC], &u.u_prof, ticks);
E 31
	}
D 22
	if (u.u_prof.pr_scale && (syst -= u.u_vm.vm_stime))
D 16
		addupc((caddr_t)locr0[PC], &u.u_prof, (int)-syst);
E 16
I 16
		addupc(locr0[PC], &u.u_prof, (int)-syst);
E 22
E 16
	curpri = p->p_pri;
}

/*
D 19
 * nonexistent system call-- set fatal error code.
E 19
I 19
 * nonexistent system call-- signal process (may want to handle it)
 * flag error if process won't see signal immediately
 * Q: should we do that all the time ??
E 19
 */
nosys()
{
D 19

	u.u_error = 100;
E 19
I 19
	if (u.u_signal[SIGSYS] == SIG_IGN || u.u_signal[SIGSYS] == SIG_HOLD)
		u.u_error = EINVAL;
	psignal(u.u_procp, SIGSYS);
E 19
}
D 17

/*
 * Ignored system call
 */
nullsys()
{

}
E 17
E 1
