h06664
s 00010/00002/00209
d D 7.5 04/01/04 21:42:46 msokolov 21 20
c also need to check if the VAX CPU has compatibility mode at all!
e
s 00004/00000/00207
d D 7.4 87/12/10 18:41:49 karels 20 19
c watch out for bogus combinations of vax options with compat mode
e
s 00001/00011/00206
d D 7.3 87/01/13 10:57:26 karels 19 18
c mv machine dependent
e
s 00015/00001/00202
d D 7.2 86/11/03 12:00:18 karels 18 17
c merge in tahoe support
e
s 00001/00001/00202
d D 7.1 86/06/05 00:08:17 mckusick 17 16
c 4.3BSD release version
e
s 00012/00021/00191
d D 6.6 86/02/20 15:58:46 karels 16 15
c cleanups from Sam: format, spl's, ptrace defs
e
s 00001/00001/00211
d D 6.5 85/11/26 12:37:33 karels 15 14
c now can use XTRC again instead of IXMOD
e
s 00007/00001/00205
d D 6.4 85/06/08 14:44:13 mckusick 14 13
c Add copyright
e
s 00001/00001/00205
d D 6.3 84/11/20 11:24:04 karels 13 12
c (ugly) changes to avoid executing/writing traced text segments
c (need regions done right!)
e
s 00011/00011/00195
d D 6.2 84/08/29 20:22:16 bloom 12 11
c Change to includes.  no more ../h
e
s 00000/00000/00206
d D 6.1 83/07/29 06:37:37 sam 11 10
c 4.2 distribution
e
s 00000/00018/00206
d D 5.10 83/07/01 02:19:30 sam 10 9
c purge #if sun's
e
s 00002/00001/00222
d D 5.9 83/05/18 02:02:38 sam 9 8
c from sun
e
s 00015/00004/00208
d D 5.8 82/12/17 11:46:21 sam 8 7
c sun merge
e
s 00004/00004/00208
d D 5.7 82/10/31 14:14:42 root 7 6
c change #if to #ifdef
e
s 00001/00001/00211
d D 5.6 82/10/31 00:51:14 root 6 5
c typo
e
s 00028/00010/00184
d D 5.5 82/10/31 00:48:04 root 5 4
c fixes in merging with 68k
e
s 00000/00001/00194
d D 5.4 82/10/10 15:56:05 root 4 3
c header files to vax directories
e
s 00000/00002/00195
d D 5.3 82/09/04 09:18:12 root 3 2
c don't need vlimit.h
e
s 00178/00000/00019
d D 5.2 82/07/24 18:11:01 root 2 1
c merge with calder
e
s 00019/00000/00000
d D 5.1 82/07/15 20:22:23 root 1 0
c date and time created 82/07/15 20:22:23 by root
e
u
U
f i 
t
T
I 1
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
D 17
 * Copyright (c) 1982 Regents of the University of California.
E 17
I 17
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 14

I 19
#define IPCREG
E 19
I 8
#include "../machine/reg.h"
#include "../machine/psl.h"
#include "../machine/pte.h"

E 8
D 12
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/inode.h"
D 8
#include "../h/reg.h"
E 8
#include "../h/text.h"
#include "../h/seg.h"
D 4
#include "../h/mtpr.h"
E 4
D 8
#include "../h/pte.h"
#include "../h/psl.h"
E 8
#include "../h/vm.h"
#include "../h/buf.h"
D 3
#include "../h/vlimit.h"
E 3
#include "../h/acct.h"
E 12
I 12
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "inode.h"
#include "text.h"
#include "seg.h"
#include "vm.h"
#include "buf.h"
#include "acct.h"
I 16
#include "ptrace.h"
E 16
E 12
D 3

E 3
I 2

I 21
/* need cpu_has_compat_mode */
#ifdef vax
#include "../vax/cpu.h"
#endif

E 21
/*
 * Priority for tracing
 */
#define	IPCPRI	PZERO

/*
 * Tracing variables.
 * Used to pass trace command from
 * parent to child being traced.
 * This data base cannot be
 * shared and is locked
 * per user.
 */
struct {
	int	ip_lock;
	int	ip_req;
	int	*ip_addr;
	int	ip_data;
} ipc;

/*
 * sys-trace system call.
 */
ptrace()
{
	register struct proc *p;
	register struct a {
		int	req;
		int	pid;
		int	*addr;
		int	data;
	} *uap;

	uap = (struct a *)u.u_ap;
	if (uap->req <= 0) {
		u.u_procp->p_flag |= STRC;
		return;
	}
	p = pfind(uap->pid);
D 9
	if (p == 0 || p->p_stat != SSTOP || p->p_ppid != u.u_procp->p_pid) {
E 9
I 9
	if (p == 0 || p->p_stat != SSTOP || p->p_ppid != u.u_procp->p_pid ||
	    !(p->p_flag & STRC)) {
E 9
		u.u_error = ESRCH;
		return;
	}
	while (ipc.ip_lock)
		sleep((caddr_t)&ipc, IPCPRI);
	ipc.ip_lock = p->p_pid;
	ipc.ip_data = uap->data;
	ipc.ip_addr = uap->addr;
	ipc.ip_req = uap->req;
	p->p_flag &= ~SWTED;
	while (ipc.ip_req > 0) {
		if (p->p_stat==SSTOP)
			setrun(p);
		sleep((caddr_t)&ipc, IPCPRI);
	}
	u.u_r.r_val1 = ipc.ip_data;
	if (ipc.ip_req < 0)
		u.u_error = EIO;
	ipc.ip_lock = 0;
	wakeup((caddr_t)&ipc);
}
D 19

D 5
int ipcreg[] = {R0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,AP,FP,SP,PC};
E 5
I 5
D 7
#if vax
E 7
I 7
D 16
#ifdef vax
E 16
I 16
#if defined(vax)
E 16
E 7
#define	NIPCREG 16
D 10
#endif
D 7
#if sun
E 7
I 7
#ifdef sun
E 7
#define	NIPCREG 17
#endif
E 10
int ipcreg[NIPCREG] =
D 7
#if vax
E 7
I 7
D 10
#ifdef vax
E 10
E 7
	{R0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,AP,FP,SP,PC};
#endif
I 18
#if defined(tahoe)
#define	NIPCREG 18
int ipcreg[NIPCREG] =
	{R0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,R12,FP,SP,PC,RACH,RACL};
#endif
E 19
E 18
D 7
#if sun
E 7
I 7
D 10
#ifdef sun
E 7
	{R0,R1,R2,R3,R4,R5,R6,R7,AR0,AR1,AR2,AR3,AR4,AR5,AR6,AR7,PC};
#endif
E 10

D 6
#define	PHYSOFF(p, o)
E 6
I 6
#define	PHYSOFF(p, o) \
E 6
	((physadr)(p)+((o)/sizeof(((physadr)0)->r[0])))

E 5
/*
 * Code that the child process
 * executes to implement the command
 * of the parent process in tracing.
 */
procxmt()
{
	register int i;
	register *p;
	register struct text *xp;

	if (ipc.ip_lock != u.u_procp->p_pid)
		return (0);
	u.u_procp->p_slptime = 0;
	i = ipc.ip_req;
	ipc.ip_req = 0;
	switch (i) {

D 16
	/* read user I */
	case 1:
E 16
I 16
	case PT_READ_I:			/* read the child's text space */
E 16
		if (!useracc((caddr_t)ipc.ip_addr, 4, B_READ))
			goto error;
		ipc.ip_data = fuiword((caddr_t)ipc.ip_addr);
		break;

D 16
	/* read user D */
	case 2:
E 16
I 16
	case PT_READ_D:			/* read the child's data space */
E 16
		if (!useracc((caddr_t)ipc.ip_addr, 4, B_READ))
			goto error;
		ipc.ip_data = fuword((caddr_t)ipc.ip_addr);
		break;

D 16
	/* read u */
	case 3:
E 16
I 16
	case PT_READ_U:			/* read the child's u. */
E 16
		i = (int)ipc.ip_addr;
		if (i<0 || i >= ctob(UPAGES))
			goto error;
D 5
		ipc.ip_data = ((physadr)&u)->r[i>>2];
E 5
I 5
		ipc.ip_data = *(int *)PHYSOFF(&u, i);
E 5
		break;

D 16
	/* write user I */
	/* Must set up to allow writing */
	case 4:
E 16
I 16
	case PT_WRITE_I:		/* write the child's text space */
E 16
		/*
		 * If text, must assure exclusive use
		 */
		if (xp = u.u_procp->p_textp) {
			if (xp->x_count!=1 || xp->x_iptr->i_mode&ISVTX)
				goto error;
D 13
			xp->x_iptr->i_flag &= ~ITEXT;
E 13
I 13
D 15
			xp->x_iptr->i_flag |= IXMOD;	/* XXX */
E 15
I 15
			xp->x_flag |= XTRC;
E 15
E 13
		}
		i = -1;
D 5
		if (chgprot((caddr_t)ipc.ip_addr, RW) &&
		    chgprot((caddr_t)ipc.ip_addr+(sizeof(int)-1), RW))
			i = suiword((caddr_t)ipc.ip_addr, ipc.ip_data);
		(void) chgprot((caddr_t)ipc.ip_addr, RO);
		(void) chgprot((caddr_t)ipc.ip_addr+(sizeof(int)-1), RO);
E 5
I 5
		if ((i = suiword((caddr_t)ipc.ip_addr, ipc.ip_data)) < 0) {
			if (chgprot((caddr_t)ipc.ip_addr, RW) &&
			    chgprot((caddr_t)ipc.ip_addr+(sizeof(int)-1), RW))
				i = suiword((caddr_t)ipc.ip_addr, ipc.ip_data);
			(void) chgprot((caddr_t)ipc.ip_addr, RO);
			(void) chgprot((caddr_t)ipc.ip_addr+(sizeof(int)-1), RO);
		}
E 5
		if (i < 0)
			goto error;
D 18
		if (xp)
E 18
I 18
#if defined(tahoe)
		/* make sure the old value is not in cache */
		ckeyrelease(u.u_procp->p_ckey);
		u.u_procp->p_ckey = getcodekey();
#endif
		if (xp) {
E 18
			xp->x_flag |= XWRIT;
I 18
#if defined(tahoe)
			xp->x_ckey = u.u_procp->p_ckey;
#endif
		}
E 18
		break;

D 16
	/* write user D */
	case 5:
E 16
I 16
	case PT_WRITE_D:		/* write the child's data space */
E 16
		if (suword((caddr_t)ipc.ip_addr, 0) < 0)
			goto error;
		(void) suword((caddr_t)ipc.ip_addr, ipc.ip_data);
		break;

D 16
	/* write u */
	case 6:
E 16
I 16
	case PT_WRITE_U:		/* write the child's u. */
E 16
		i = (int)ipc.ip_addr;
D 5
		p = (int *)&((physadr)&u)->r[i>>2];
		for (i=0; i<16; i++)
E 5
I 5
		p = (int *)PHYSOFF(&u, i);
		for (i=0; i<NIPCREG; i++)
E 5
			if (p == &u.u_ar0[ipcreg[i]])
				goto ok;
		if (p == &u.u_ar0[PS]) {
D 5
			ipc.ip_data |= PSL_CURMOD|PSL_PRVMOD;
E 5
I 5
			ipc.ip_data |= PSL_USERSET;
E 5
			ipc.ip_data &=  ~PSL_USERCLR;
I 20
D 21
#ifdef PSL_CM_CLR
			if (ipc.ip_data & PSL_CM)
E 21
I 21
#ifdef vax
			if (ipc.ip_data & PSL_CM) {
				if (!cpu_has_compat_mode)
					goto error;
E 21
				ipc.ip_data &= ~PSL_CM_CLR;
I 21
			}
E 21
#endif
E 20
I 8
D 10
#ifdef sun
			if (ipc.ip_data & PSL_T)
				traceon();
			else
				traceoff();
#endif
E 10
E 8
			goto ok;
		}
		goto error;

	ok:
		*p = ipc.ip_data;
		break;

D 16
	/* set signal and continue */
	/* one version causes a trace-trap */
	case 9:
	case 7:
E 16
I 16
	case PT_STEP:			/* single step the child */
	case PT_CONTINUE:		/* continue the child */
E 16
		if ((int)ipc.ip_addr != 1)
			u.u_ar0[PC] = (int)ipc.ip_addr;
		if ((unsigned)ipc.ip_data > NSIG)
			goto error;
		u.u_procp->p_cursig = ipc.ip_data;	/* see issig */
D 8
		if (i == 9)
E 8
I 8
D 16
		if (i == 9) 
E 16
I 16
		if (i == PT_STEP) 
E 16
D 10
#ifdef sun
			traceon();
#else
E 10
E 8
			u.u_ar0[PS] |= PSL_T;
I 8
D 10
#endif
E 10
E 8
		wakeup((caddr_t)&ipc);
		return (1);

D 16
	/* force exit */
	case 8:
E 16
I 16
	case PT_KILL:			/* kill the child process */
E 16
		wakeup((caddr_t)&ipc);
		exit(u.u_procp->p_cursig);

	default:
	error:
		ipc.ip_req = -1;
	}
	wakeup((caddr_t)&ipc);
	return (0);
}
E 2
E 1
