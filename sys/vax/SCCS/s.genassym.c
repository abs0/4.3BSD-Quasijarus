h21872
s 00001/00000/00093
d D 7.4 04/01/11 11:32:34 msokolov 17 16
c add U_ONSTACK for the new same mode emulator
e
s 00001/00000/00092
d D 7.3 88/08/27 07:01:19 tef 16 15
c Add support for microvax 3000.
e
s 00001/00000/00091
d D 7.2 87/10/28 10:30:49 bostic 15 14
c fix for ANSI printf; bug report 4.3BSD/sys/164
e
s 00001/00001/00090
d D 7.1 86/06/05 00:43:41 mckusick 14 13
c 4.3BSD release version
e
s 00001/00000/00090
d D 6.8 86/04/22 10:48:07 kridle 13 12
c Added MicroVAX II Support (KA630)
e
s 00007/00001/00083
d D 6.7 85/06/08 13:42:16 mckusick 12 11
c Add copyright
e
s 00002/00002/00082
d D 6.6 85/04/22 19:56:43 sam 11 10
c qsave is a structure, not an array
e
s 00005/00000/00079
d D 6.5 84/12/21 09:37:44 karels 10 9
c define KERNEL to get the right includes; define uba_hd for ld
e
s 00014/00014/00065
d D 6.4 84/08/28 18:09:41 bloom 9 8
c Change to includes.  No more ../h
e
s 00001/00000/00078
d D 6.3 84/08/21 11:11:07 karels 8 7
c add interrupt counts per device, also software interrupts
e
s 00001/00000/00077
d D 6.2 84/08/11 23:26:02 mckusick 7 6
c add P_DSIZE
e
s 00000/00000/00077
d D 6.1 83/07/29 07:19:54 sam 6 5
c 4.2 distribution
e
s 00005/00000/00072
d D 4.5 83/06/17 16:11:26 mckusick 5 4
c add fields for expanded Fastreclaim
e
s 00001/00000/00071
d D 4.4 83/05/30 16:36:32 sam 4 3
c need v_fastpgrec for Fastreclaim
e
s 00012/00000/00059
d D 4.3 83/05/29 18:23:38 sam 3 2
c define stuff for Fastreclaim
e
s 00002/00001/00057
d D 4.2 82/12/17 11:55:47 sam 2 1
c sun merge
e
s 00058/00000/00000
d D 4.1 82/12/16 19:06:52 sam 1 0
c date and time created 82/12/16 19:06:52 by sam
e
u
U
t
T
I 10
D 11
/*	%W% (Berkeley) %G% */
E 11
I 11
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12
E 11

#define KERNEL
E 10
I 1
#define	VAX780	1
#define	VAX750	1
I 3
#define	VAX730	1
I 13
#define	VAX630	1
I 16
#define	VAX650	1
E 16
E 13
E 3

I 2
D 9
#include "../machine/pte.h"
E 9
I 9
#include "pte.h"
E 9

E 2
D 9
#include "../h/param.h"
D 2
#include "../h/pte.h"
E 2
#include "../h/buf.h"
#include "../h/vmmeter.h"
#include "../h/vmparam.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/cmap.h"
#include "../h/map.h"
E 9
I 9
#include "param.h"
#include "buf.h"
#include "vmmeter.h"
#include "vmparam.h"
#include "dir.h"
#include "user.h"
#include "cmap.h"
#include "map.h"
E 9
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
D 9
#include "../h/proc.h"
I 5
#include "../h/text.h"
E 5
#include "../vax/rpb.h"
#include "../h/mbuf.h"
#include "../h/msgbuf.h"
E 9
I 9
#include "proc.h"
#include "text.h"
#include "rpb.h"
#include "mbuf.h"
#include "msgbuf.h"
I 10

struct uba_hd uba_hd[1];
E 10
E 9

main()
{
	register struct proc *p = (struct proc *)0;
	register struct uba_regs *uba = (struct uba_regs *)0;
	register struct uba_hd *uh = (struct uba_hd *)0;
	register struct vmmeter *vm = (struct vmmeter *)0;
	register struct user *up = (struct user *)0;
I 3
	register struct rusage *rup = (struct rusage *)0;
E 3
	struct rpb *rp = (struct rpb *)0;
I 5
	struct text *tp = (struct text *)0;
E 5

	printf("#ifdef LOCORE\n");
	printf("#define\tP_LINK %d\n", &p->p_link);
	printf("#define\tP_RLINK %d\n", &p->p_rlink);
I 5
	printf("#define\tP_XLINK %d\n", &p->p_xlink);
E 5
	printf("#define\tP_ADDR %d\n", &p->p_addr);
	printf("#define\tP_PRI %d\n", &p->p_pri);
	printf("#define\tP_STAT %d\n", &p->p_stat);
	printf("#define\tP_WCHAN %d\n", &p->p_wchan);
I 3
	printf("#define\tP_TSIZE %d\n", &p->p_tsize);
I 7
	printf("#define\tP_DSIZE %d\n", &p->p_dsize);
E 7
	printf("#define\tP_SSIZE %d\n", &p->p_ssize);
	printf("#define\tP_P0BR %d\n", &p->p_p0br);
	printf("#define\tP_SZPT %d\n", &p->p_szpt);
	printf("#define\tP_TEXTP %d\n", &p->p_textp);
I 5
	printf("#define\tP_FLAG %d\n", &p->p_flag);
E 5
E 3
	printf("#define\tSSLEEP %d\n", SSLEEP);
	printf("#define\tSRUN %d\n", SRUN);
	printf("#define\tUBA_BRRVR %d\n", uba->uba_brrvr);
	printf("#define\tUH_UBA %d\n", &uh->uh_uba);
	printf("#define\tUH_VEC %d\n", &uh->uh_vec);
	printf("#define\tUH_SIZE %d\n", sizeof (struct uba_hd));
	printf("#define\tRP_FLAG %d\n", &rp->rp_flag);
I 5
	printf("#define\tX_CADDR %d\n", &tp->x_caddr);
E 5
	printf("#define\tV_SWTCH %d\n", &vm->v_swtch);
	printf("#define\tV_TRAP %d\n", &vm->v_trap);
	printf("#define\tV_SYSCALL %d\n", &vm->v_syscall);
	printf("#define\tV_INTR %d\n", &vm->v_intr);
I 8
	printf("#define\tV_SOFT %d\n", &vm->v_soft);
E 8
	printf("#define\tV_PDMA %d\n", &vm->v_pdma);
I 3
	printf("#define\tV_FAULTS %d\n", &vm->v_faults);
	printf("#define\tV_PGREC %d\n", &vm->v_pgrec);
I 4
	printf("#define\tV_FASTPGREC %d\n", &vm->v_fastpgrec);
E 4
E 3
	printf("#define\tUPAGES %d\n", UPAGES);
	printf("#define\tCLSIZE %d\n", CLSIZE);
	printf("#define\tSYSPTSIZE %d\n", SYSPTSIZE);
	printf("#define\tUSRPTSIZE %d\n", USRPTSIZE);
	printf("#define\tMSGBUFPTECNT %d\n", btoc(sizeof (struct msgbuf)));
	printf("#define\tNMBCLUSTERS %d\n", NMBCLUSTERS);
I 3
	printf("#define\tU_PROCP %d\n", &up->u_procp);
I 17
	printf("#define\tU_ONSTACK %d\n", &up->u_onstack);
E 17
	printf("#define\tU_RU %d\n", &up->u_ru);
	printf("#define\tRU_MINFLT %d\n", &rup->ru_minflt);
E 3
	printf("#else\n");
	printf("asm(\".set\tU_ARG,%d\");\n", up->u_arg);
D 11
	printf("asm(\".set\tU_QSAVE,%d\");\n", up->u_qsave);
E 11
I 11
	printf("asm(\".set\tU_QSAVE,%d\");\n", &up->u_qsave);
E 11
	printf("#endif\n");
I 15
	exit(0);
E 15
}
E 1
