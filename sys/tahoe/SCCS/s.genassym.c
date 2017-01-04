h61229
s 00010/00005/00120
d D 7.2 88/06/29 17:34:33 bostic 9 8
c install approved copyright notice
e
s 00022/00004/00103
d D 7.1 88/05/21 18:35:14 karels 8 7
c bring up to revision 7 for tahoe release
e
s 00001/00000/00106
d D 1.7 87/10/28 10:31:22 bostic 7 6
c fix for ANSI printf; bug report 4.3BSD/sys/164
e
s 00001/00002/00105
d D 1.6 87/06/30 23:37:28 karels 6 5
c change map allocation for vba maps, need maxphys
e
s 00003/00000/00104
d D 1.5 86/07/20 11:08:20 sam 5 4
c add stuff for new vmmeter.h and also for alignment emulation
e
s 00005/00004/00099
d D 1.4 86/01/20 23:52:30 sam 4 3
c cleanup some more of the autoconfig stuff: eliminate all page 
c maps defined in locore.s in favor of dynamically allocated entries; rename 
c some of the iospace definitions and move them into ../tahoevba/vbaparam.h 
c (will ease vme support sometime?)
e
s 00007/00000/00096
d D 1.3 86/01/12 15:38:25 sam 3 2
c 4.3- plus start of autoconfig
e
s 00014/00012/00082
d D 1.2 86/01/05 19:01:18 sam 2 1
c need pte.h for SYSPTSIZE+USRPTSIZE (remove include spec's to ../h)
e
s 00094/00000/00000
d D 1.1 86/01/05 18:47:46 sam 1 0
c date and time created 86/01/05 18:47:46 by sam
e
u
U
t
T
I 8
/*
 * Copyright (c) 1983, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 9
 */

E 8
I 1
#ifndef lint
I 8
char copyright[] =
"%Z% Copyright (c) 1983, 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 8
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif
E 8
I 8
#endif /* not lint */
E 8

D 2
#include "../h/param.h"
#include "../h/vmmeter.h"
#include "../h/vmparam.h"
#include "../h/buf.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/cmap.h"
#include "../h/map.h"
#include "../h/proc.h"
#include "../h/text.h"
#include "../h/mbuf.h"
#include "../h/msgbuf.h"
E 2
I 2
D 8
#include "../tahoe/pte.h"
I 3
#include "../tahoe/scb.h"
E 3

E 8
#include "param.h"
#include "vmmeter.h"
#include "vmparam.h"
#include "buf.h"
#include "dir.h"
#include "user.h"
#include "cmap.h"
#include "map.h"
#include "proc.h"
#include "text.h"
#include "mbuf.h"
#include "msgbuf.h"
I 8

#include "pte.h"
#include "scb.h"
E 8
E 2

I 4
#include "../tahoevba/vbaparam.h"

E 4
main()
{
	register struct user *u = (struct user *)0;
	register struct proc *p = (struct proc *)0;
	register struct vmmeter *vm = (struct vmmeter *)0;
	register struct pcb *pcb = (struct pcb *)0;
I 3
	register struct scb *scb = (struct scb *)0;
E 3

	printf("#ifdef LOCORE\n");
	printf("#define\tU_PROCP %d\n", &u->u_procp);
I 5
	printf("#define\tU_EOSYS %d\n", &u->u_eosys);
E 5
	printf("#define\tP_LINK %d\n", &p->p_link);
	printf("#define\tP_RLINK %d\n", &p->p_rlink);
	printf("#define\tP_XLINK %d\n", &p->p_xlink);
	printf("#define\tP_ADDR %d\n", &p->p_addr);
	printf("#define\tP_PRI %d\n", &p->p_pri);
	printf("#define\tP_STAT %d\n", &p->p_stat);
	printf("#define\tP_WCHAN %d\n", &p->p_wchan);
	printf("#define\tP_TSIZE %d\n", &p->p_tsize);
	printf("#define\tP_SSIZE %d\n", &p->p_ssize);
	printf("#define\tP_P0BR %d\n", &p->p_p0br);
	printf("#define\tP_SZPT %d\n", &p->p_szpt);
	printf("#define\tP_TEXTP %d\n", &p->p_textp);
	printf("#define\tP_FLAG %d\n", &p->p_flag);
	printf("#define\tP_DKEY %d\n", &p->p_dkey);
	printf("#define\tP_CKEY %d\n", &p->p_ckey);
	printf("#define\tSSLEEP %d\n", SSLEEP);
	printf("#define\tSRUN %d\n", SRUN);
	printf("#define\tV_SWTCH %d\n", &vm->v_swtch);
	printf("#define\tV_TRAP %d\n", &vm->v_trap);
	printf("#define\tV_SYSCALL %d\n", &vm->v_syscall);
	printf("#define\tV_INTR %d\n", &vm->v_intr);
I 3
	printf("#define\tV_SOFT %d\n", &vm->v_soft);
I 5
	printf("#define\tV_FPE %d\n", &vm->v_fpe);
	printf("#define\tV_ALIGN %d\n", &vm->v_align);
E 5
E 3
	printf("#define\tNBPG %d\n", NBPG);
	printf("#define\tPGSHIFT %d\n", PGSHIFT);
	printf("#define\tUPAGES %d\n", UPAGES);
	printf("#define\tCLSIZE %d\n", CLSIZE);
I 6
	printf("#define\tMAXPHYS %d\n", MAXPHYS);
E 6
	printf("#define\tSYSPTSIZE %d\n", SYSPTSIZE);
	printf("#define\tUSRPTSIZE %d\n", USRPTSIZE);
D 4
	printf("#define\tIOSIZE %d\n", IOSIZE);
	printf("#define\tMAXBPTE %d\n", MAXBPTE);
	printf("#define\tTBUFSIZ %d\n", TBUFSIZ);
	printf("#define\tACEBPTE %d\n", ACEBPTE);
E 4
I 4
	printf("#define\tVBIOSIZE %d\n", VBIOSIZE);
D 6
	printf("#define\tVBMEMSIZE %d\n", VBMEMSIZE);
	printf("#define\tVBPTSIZE %d\n", VBPTSIZE);
E 6
E 4
	printf("#define\tMSGBUFPTECNT %d\n", btoc(sizeof (struct msgbuf)));
	printf("#define\tNMBCLUSTERS %d\n", NMBCLUSTERS);
	printf("#define\tPCB_KSP %d\n", &pcb->pcb_ksp);
	printf("#define\tPCB_USP %d\n", &pcb->pcb_usp);
	printf("#define\tPCB_R0 %d\n", &pcb->pcb_r0);
	printf("#define\tPCB_R1 %d\n", &pcb->pcb_r1);
	printf("#define\tPCB_R2 %d\n", &pcb->pcb_r2);
	printf("#define\tPCB_R3 %d\n", &pcb->pcb_r3);
	printf("#define\tPCB_R4 %d\n", &pcb->pcb_r4);
	printf("#define\tPCB_R5 %d\n", &pcb->pcb_r5);
	printf("#define\tPCB_R6 %d\n", &pcb->pcb_r6);
	printf("#define\tPCB_R7 %d\n", &pcb->pcb_r7);
	printf("#define\tPCB_R8 %d\n", &pcb->pcb_r8);
	printf("#define\tPCB_R9 %d\n", &pcb->pcb_r9);
	printf("#define\tPCB_R10 %d\n", &pcb->pcb_r10);
	printf("#define\tPCB_R11 %d\n", &pcb->pcb_r11);
	printf("#define\tPCB_R12 %d\n", &pcb->pcb_r12);
	printf("#define\tPCB_R13 %d\n", &pcb->pcb_r13);
	printf("#define\tPCB_FP %d\n", &pcb->pcb_fp);
	printf("#define\tPCB_PC %d\n", &pcb->pcb_pc);
	printf("#define\tPCB_PSL %d\n", &pcb->pcb_psl);
	printf("#define\tPCB_P0BR %d\n", &pcb->pcb_p0br);
	printf("#define\tPCB_P0LR %d\n", &pcb->pcb_p0lr);
	printf("#define\tPCB_P1BR %d\n", &pcb->pcb_p1br);
	printf("#define\tPCB_P1LR %d\n", &pcb->pcb_p1lr);
	printf("#define\tPCB_P2BR %d\n", &pcb->pcb_p2br);
	printf("#define\tPCB_P2LR %d\n", &pcb->pcb_p2lr);
	printf("#define\tPCB_ACH %d\n", &pcb->pcb_ach);
	printf("#define\tPCB_ACL %d\n", &pcb->pcb_acl);
	printf("#define\tPCB_HFS %d\n", &pcb->pcb_hfs);
	printf("#define\tPCB_SAVACC %d\n", &pcb->pcb_savacc);
	printf("#define\tPCB_SZPT %d\n", &pcb->pcb_szpt);
	printf("#define\tPCB_CMAP2 %d\n", &pcb->pcb_cmap2);
	printf("#define\tPCB_SSWAP %d\n", &pcb->pcb_sswap);
	printf("#define\tPCB_SIGC %d\n", pcb->pcb_sigc);
I 3
	printf("#define\tSCB_DOADUMP %d\n", &scb->scb_doadump);
	printf("#define\tSCB_BUSERR %d\n", &scb->scb_buserr);
#define	SCB_DEVBASE	(((int)((struct scb *)0)->scb_devint)/sizeof (int))
	printf("#define\tSCB_DEVBASE %d\n", SCB_DEVBASE);
E 3
	printf("#endif\n");
I 7
	exit(0);
E 7
}
E 1
