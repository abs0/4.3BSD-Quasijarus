h04824
s 00000/00000/00677
d D 7.1 88/05/26 09:09:53 karels 23 22
c bring up to revision 7 for tahoe release
e
s 00008/00010/00669
d D 1.19 88/05/26 09:05:17 karels 22 20
c lint, header cleanups
e
s 00008/00008/00671
d R 7.1 88/05/21 18:35:48 karels 21 20
c bring up to revision 7 for tahoe release
e
s 00001/00001/00678
d D 1.18 88/05/21 17:07:18 karels 20 19
c rename KDB => KADB
e
s 00003/00017/00676
d D 1.17 88/05/02 20:15:23 karels 19 16
c add msgbufmapped for printf; rm physstrat
e
s 00000/00000/00689
d D 1.16.1.1 87/11/24 16:09:21 karels 18 16
x 14
c tahoe distribution (no malloc)
e
s 00000/00000/00689
d R 1.17 87/11/24 16:08:35 karels 17 16
x 14
c tahoe distribution (no malloc)
e
s 00007/00001/00686
d D 1.16 87/11/24 16:07:16 karels 16 15
c copyright and sccsid
e
s 00003/00001/00684
d D 1.15 87/06/30 23:34:59 karels 15 14
c don't trip over locked inodes, etc, freeing text
e
s 00004/00000/00681
d D 1.14 87/06/06 13:21:28 mckusick 14 13
c allocation of malloc map and usage structure; kmem initialization
e
s 00028/00020/00653
d D 1.13 87/03/26 18:06:09 karels 13 12
c fix up boot (again?); allocate cy buffer here (yech)
e
s 00023/00004/00650
d D 1.12 87/02/26 18:06:55 karels 12 11
c mv key initialization to machdep; reboot flags set even on halt;
c do reboot more flexibly
e
s 00001/00000/00653
d D 1.11 87/02/21 11:17:18 karels 11 10
c try to get the kernel printfs out before console starts reboot
e
s 00010/00004/00643
d D 1.10 87/02/16 19:22:34 karels 10 9
c init buffer headers before configure, so can read pack labels;
c pass boot flags; resynch with cons.c
e
s 00001/00002/00646
d D 1.9 86/12/15 20:27:49 sam 9 8
c lint
e
s 00002/00000/00646
d D 1.8 86/11/25 18:26:53 sam 8 7
c for karels; avoid dumps during generic boot
e
s 00004/00001/00642
d D 1.7 86/11/25 16:44:25 sam 7 6
c kdb additions
e
s 00004/00004/00639
d D 1.6 86/11/03 12:05:45 karels 6 5
c move key stats, etc. to cpu.h
e
s 00002/00002/00641
d D 1.5 86/07/16 08:27:23 sam 5 4
c bug fix for sendsig (correct user access check); name cache name change
e
s 00018/00000/00625
d D 1.4 86/01/24 01:14:34 sam 4 3
c add microtime and release cached text inodes before update on boot/crash
e
s 00002/00003/00623
d D 1.3 86/01/12 15:38:34 sam 3 2
c 4.3- plus start of autoconfig
e
s 00281/00274/00345
d D 1.2 86/01/05 18:42:33 sam 2 1
c 1st working version
e
s 00619/00000/00000
d D 1.1 85/07/21 18:14:01 sam 1 0
c date and time created 85/07/21 18:14:01 by sam
e
u
U
f b 
t
T
I 1
D 2
/*	machdep.c	1.4	85/05/15	*/
E 2
I 2
D 16
/*	%M%	%I%	%E%	*/
E 16
I 16
/*
D 22
 * Copyright (c) 1982,1987 Regents of the University of California.
E 22
I 22
 * Copyright (c) 1982,1987,1988 Regents of the University of California.
E 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 16
E 2

D 2
#include "../machine/reg.h"
#include "../machine/pte.h"
#include "../machine/psl.h"
E 2
I 2
D 6
#include "../tahoe/reg.h"
#include "../tahoe/pte.h"
#include "../tahoe/psl.h"
E 2

E 6
D 2
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/nami.h"
#include "../h/kernel.h"
#include "../h/map.h"
#include "../h/vm.h"
#include "../h/proc.h"
#include "../h/buf.h"
#include "../h/reboot.h"
#include "../h/conf.h"
#include "../h/inode.h"
#include "../h/file.h"
#include "../h/text.h"
#include "../h/clist.h"
#include "../h/callout.h"
#include "../h/cmap.h"
#include "../h/mbuf.h"
#include "../h/msgbuf.h"
#include "../h/quota.h"
E 2
I 2
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "map.h"
#include "vm.h"
#include "proc.h"
#include "buf.h"
#include "reboot.h"
#include "conf.h"
#include "inode.h"
#include "file.h"
#include "text.h"
#include "clist.h"
#include "callout.h"
#include "cmap.h"
I 19
#include "malloc.h"
E 19
#include "mbuf.h"
#include "msgbuf.h"
#include "quota.h"
I 14
D 19
#include "malloc.h"
E 19
E 14

I 6
D 22
#include "../tahoe/cpu.h"
#include "../tahoe/reg.h"
#include "../tahoe/pte.h"
#include "../tahoe/psl.h"
E 22
I 22
#include "cpu.h"
#include "reg.h"
#include "pte.h"
#include "psl.h"
#include "mem.h"
#include "mtpr.h"
#include "cp.h"
E 22
I 7

E 7
E 6
E 2
D 22
#include "../tahoe/mem.h"
#include "../tahoe/mtpr.h"
#include "../tahoe/cp.h"
E 22
D 2
#include "../vba/vbavar.h"
E 2
I 2
#include "../tahoevba/vbavar.h"
E 2

D 2
int	icode[] = {
	0xf9af19f9,	/*	pushab	argp */
	0xaf09dd02,	/*	pushab	file */
	0xe96e5dcf,	/*	pushl	$2 */
	0x0b11fe2f,	/*	movab	(sp),fp */
	0x6574632f,	/*	kcall	$exec */
	0x696e6974,	/* here:brb	here */
	0x00000000,	/*.file:.ascii	"/etc/" */
	0x00000014,	/* args:.ascii	"init\0" */
	0x00000000,	/*	.align	2 */
			/* argp:.long	args, 0 */
};
int	szicode = sizeof(icode);
 
E 2
/*
 * Declare these as initialized data so we can patch them.
 */
D 2
int	nbuf = 0;
E 2
int	nswbuf = 0;
I 2
#ifdef	NBUF
int	nbuf = NBUF;
#else
int	nbuf = 0;
#endif
#ifdef	BUFPAGES
int	bufpages = BUFPAGES;
#else
E 2
int	bufpages = 0;
I 2
#endif
I 13
#include "yc.h"
#if NCY > 0
#include "../tahoevba/cyreg.h"
#endif
I 19
int	msgbufmapped;		/* set when safe to use msgbuf */
E 19
E 13
E 2

/*
 * Machine-dependent startup code
 */
startup(firstaddr)
	int firstaddr;
{
	register int unixsize;
	register unsigned i;
	register struct pte *pte;
D 2
	register int mapaddr, j;
E 2
I 2
	int mapaddr, j;
E 2
	register caddr_t v;
D 2
	register int maxbufs, base, residual;
E 2
I 2
	int maxbufs, base, residual;
E 2
D 9
	extern char etext;
E 9

	/*
	 * Initialize error message buffer (at end of core).
	 */
	maxmem -= btoc(sizeof (struct msgbuf));
	pte = msgbufmap;
	for (i = 0; i < btoc(sizeof (struct msgbuf)); i++)
		*(int *)pte++ = PG_V | PG_KW | (maxmem + i);
D 2
	mtpr(1,TBIA);
E 2
I 2
	mtpr(TBIA, 1);
I 19
	msgbufmapped = 1;
E 19
E 2
D 7

E 7
I 7
D 20
#ifdef KDB
E 20
I 20
#ifdef KADB
E 20
	kdb_init();			/* startup kernel debugger */
#endif
E 7
	/*
	 * Good {morning,afternoon,evening,night}.
	 */
	printf(version);
D 2
	printf("real mem  = %d\n", ctob(maxmem));
	
	/*
	 * Determine how many buffers to allocate.
	 * Use 10% of memory, with min of 16.
	 * We allocate 1/2 as many swap buffer headers as file i/o buffers.
	 */
	maxbufs = ((SYSPTSIZE * NBPG) - (5 * (int)(&etext - 0xc0000000))) /
	    MAXBSIZE;
	if (bufpages == 0)
		bufpages = (physmem * NBPG) / 10 / CLBYTES;
	if (nbuf == 0) {
		nbuf = bufpages / 2;
		if (nbuf < 16)
			nbuf = 16;
		if (nbuf > maxbufs)
			nbuf = maxbufs;
	}
	if (bufpages > nbuf * (MAXBSIZE / CLBYTES))
		bufpages = nbuf * (MAXBSIZE / CLBYTES);
	if (nswbuf == 0) {
		nswbuf = (nbuf / 2) &~ 1;	/* force even */
		if (nswbuf > 256)
			nswbuf = 256;		/* sanity */
	}
E 2
I 2
	printf("real mem  = %d\n", ctob(physmem));
E 2

	/*
	 * Allocate space for system data structures.
	 * The first available real memory address is in "firstaddr".
D 2
	 * As pages of memory are allocated, "firstaddr" is incremented.
E 2
	 * The first available kernel virtual address is in "v".
	 * As pages of kernel virtual memory are allocated, "v" is incremented.
I 2
	 * As pages of memory are allocated and cleared,
	 * "firstaddr" is incremented.
E 2
	 * An index into the kernel page table corresponding to the
	 * virtual memory address maintained in "v" is kept in "mapaddr".
	 */
D 2
	mapaddr = firstaddr;
E 2
	v = (caddr_t)(0xc0000000 | (firstaddr * NBPG));
#define	valloc(name, type, num) \
D 2
	    (name) = (type *)(v); (v) = (caddr_t)((name)+(num))
E 2
I 2
	    (name) = (type *)v; v = (caddr_t)((name)+(num))
E 2
#define	valloclim(name, type, num, lim) \
D 2
	    (name) = (type *)(v); (v) = (caddr_t)((lim) = ((name)+(num)))
	valloc(buffers, char, MAXBSIZE * nbuf);
	base = bufpages / nbuf;
	residual = bufpages % nbuf;
	for (i = 0; i < residual; i++) {
		for (j = 0; j < (base + 1) * CLSIZE; j++) {
			*(int *)(&Sysmap[mapaddr+j]) = PG_V | PG_KW | firstaddr;
			clearseg((unsigned)firstaddr);
			firstaddr++;
		}
		mapaddr += MAXBSIZE / NBPG;
	}
	for (i = residual; i < nbuf; i++) {
		for (j = 0; j < base * CLSIZE; j++) {
			*(int *)(&Sysmap[mapaddr+j]) = PG_V | PG_KW | firstaddr;
			clearseg((unsigned)firstaddr);
			firstaddr++;
		}
		mapaddr += MAXBSIZE / NBPG;
	}
	valloc(buf, struct buf, nbuf);
	valloc(swbuf, struct buf, nswbuf);
E 2
I 2
	    (name) = (type *)v; v = (caddr_t)((lim) = ((name)+(num)))
I 13
#if NCY > 0
	/*
	 * Allocate raw buffers for tapemaster controllers
	 * first, as they need buffers in the first megabyte.
	 */
	valloc(cybuf, char, NCY * CYMAXIO);
#endif
E 13
E 2
	valloclim(inode, struct inode, ninode, inodeNINODE);
	valloclim(file, struct file, nfile, fileNFILE);
	valloclim(proc, struct proc, nproc, procNPROC);
	valloclim(text, struct text, ntext, textNTEXT);
	valloc(cfree, struct cblock, nclist);
	valloc(callout, struct callout, ncallout);
	valloc(swapmap, struct map, nswapmap = nproc * 2);
	valloc(argmap, struct map, ARGMAPSIZE);
	valloc(kernelmap, struct map, nproc);
	valloc(mbmap, struct map, nmbclusters/4);
D 5
	valloc(nch, struct nch, nchsize);
E 5
I 5
	valloc(namecache, struct namecache, nchsize);
I 14
	valloc(kmemmap, struct map, ekmempt - kmempt);
	valloc(kmemusage, struct kmemusage, ekmempt - kmempt);
E 14
E 5
#ifdef QUOTA
	valloclim(quota, struct quota, nquota, quotaNQUOTA);
	valloclim(dquot, struct dquot, ndquot, dquotNDQUOT);
#endif
I 2
	
E 2
	/*
D 2
	 * Now allocate space for core map
E 2
I 2
	 * Determine how many buffers to allocate.
	 * Use 10% of memory for the first 2 Meg, 5% of the remaining
	 * memory. Insure a minimum of 16 buffers.
	 * We allocate 1/2 as many swap buffer headers as file i/o buffers.
	 */
	if (bufpages == 0)
		if (physmem < (2 * 1024 * 1024))
			bufpages = physmem / 10 / CLSIZE;
		else
D 3
			bufpages =
			    ((2 * 1024 * 1024) / 5 + physmem / 5) / CLSIZE;
E 3
I 3
			bufpages = ((2 * 1024 * 1024 + physmem) / 20) / CLSIZE;
E 3
	if (nbuf == 0) {
		nbuf = bufpages / 2;
		if (nbuf < 16)
			nbuf = 16;
	}
	if (nswbuf == 0) {
		nswbuf = (nbuf / 2) &~ 1;	/* force even */
		if (nswbuf > 256)
			nswbuf = 256;		/* sanity */
	}
	valloc(swbuf, struct buf, nswbuf);

	/*
	 * Now the amount of virtual memory remaining for buffers
	 * can be calculated, estimating needs for the cmap.
	 */
	ncmap = (maxmem*NBPG - ((int)v &~ 0xc0000000)) /
		(CLBYTES + sizeof(struct cmap)) + 2;
	maxbufs = ((SYSPTSIZE * NBPG) -
	    ((int)(v + ncmap * sizeof(struct cmap)) - 0xc0000000)) /
		(MAXBSIZE + sizeof(struct buf));
	if (maxbufs < 16)
		panic("sys pt too small");
	if (nbuf > maxbufs) {
		printf("SYSPTSIZE limits number of buffers to %d\n", maxbufs);
		nbuf = maxbufs;
	}
	if (bufpages > nbuf * (MAXBSIZE / CLBYTES))
		bufpages = nbuf * (MAXBSIZE / CLBYTES);
	valloc(buf, struct buf, nbuf);

	/*
	 * Allocate space for core map.
E 2
	 * Allow space for all of phsical memory minus the amount 
	 * dedicated to the system. The amount of physical memory
	 * dedicated to the system is the total virtual memory of
D 2
	 * the system minus the space in the buffers which is not
	 * allocated real memory.
E 2
I 2
	 * the system thus far, plus core map, buffer pages,
	 * and buffer headers not yet allocated.
	 * Add 2: 1 because the 0th entry is unused, 1 for rounding.
E 2
	 */
D 2
	ncmap = (physmem*NBPG - ((int)v &~ 0xc0000000) +
		(nbuf * MAXBSIZE - bufpages * CLBYTES)) /
		    (NBPG*CLSIZE + sizeof (struct cmap));
E 2
I 2
	ncmap = (maxmem*NBPG - ((int)(v + bufpages*CLBYTES) &~ 0xc0000000)) /
		(CLBYTES + sizeof(struct cmap)) + 2;
E 2
	valloclim(cmap, struct cmap, ncmap, ecmap);
D 2
	if ((((int)(ecmap+1))&~0xc0000000) > SYSPTSIZE*NBPG)
		panic("sys pt too small");
E 2

	/*
D 2
	 * Clear allocated space, and make r/w entries
E 2
I 2
	 * Clear space allocated thus far, and make r/w entries
E 2
	 * for the space in the kernel map.
	 */
D 2
	unixsize = btoc((int)(ecmap+1) &~ 0xc0000000);
	for (i = mapaddr; i < unixsize; i++) {
		*(int *)(&Sysmap[i]) = PG_V | PG_KW | firstaddr;
E 2
I 2
	unixsize = btoc((int)v &~ 0xc0000000);
	while (firstaddr < unixsize) {
		*(int *)(&Sysmap[firstaddr]) = PG_V | PG_KW | firstaddr;
E 2
		clearseg((unsigned)firstaddr);
		firstaddr++;
	}
I 2

	/*
	 * Now allocate buffers proper.  They are different than the above
	 * in that they usually occupy more virtual memory than physical.
	 */
	v = (caddr_t) ((int)(v + PGOFSET) &~ PGOFSET);
	valloc(buffers, char, MAXBSIZE * nbuf);
	base = bufpages / nbuf;
	residual = bufpages % nbuf;
	mapaddr = firstaddr;
	for (i = 0; i < residual; i++) {
		for (j = 0; j < (base + 1) * CLSIZE; j++) {
			*(int *)(&Sysmap[mapaddr+j]) = PG_V | PG_KW | firstaddr;
			clearseg((unsigned)firstaddr);
			firstaddr++;
		}
		mapaddr += MAXBSIZE / NBPG;
	}
	for (i = residual; i < nbuf; i++) {
		for (j = 0; j < base * CLSIZE; j++) {
			*(int *)(&Sysmap[mapaddr+j]) = PG_V | PG_KW | firstaddr;
			clearseg((unsigned)firstaddr);
			firstaddr++;
		}
		mapaddr += MAXBSIZE / NBPG;
	}

	unixsize = btoc((int)v &~ 0xc0000000);
E 2
	if (firstaddr >= physmem - 8*UPAGES)
		panic("no memory");
D 2
	mtpr(1,TBIA);
E 2
I 2
	mtpr(TBIA, 1);			/* After we just cleared it all! */
E 2

	/*
	 * Initialize callouts
	 */
	callfree = callout;
	for (i = 1; i < ncallout; i++)
		callout[i-1].c_next = &callout[i];

	/*
	 * Initialize memory allocator and swap
	 * and user page table maps.
	 *
	 * THE USER PAGE TABLE MAP IS CALLED ``kernelmap''
	 * WHICH IS A VERY UNDESCRIPTIVE AND INCONSISTENT NAME.
	 */
	meminit(firstaddr, maxmem);
	maxmem = freemem;
	printf("avail mem = %d\n", ctob(maxmem));
	printf("using %d buffers containing %d bytes of memory\n",
		nbuf, bufpages * CLBYTES);
	rminit(kernelmap, (long)USRPTSIZE, (long)1,
	    "usrpt", nproc);
D 3
	rminit(mbmap, (long)((nmbclusters - 1) * CLSIZE), (long)CLSIZE,
E 3
I 3
	rminit(mbmap, (long)(nmbclusters * CLSIZE), (long)CLSIZE,
E 3
	    "mbclusters", nmbclusters/4);
I 14
	kmeminit();		/* now safe to do malloc/free */
E 14
	intenable = 1;		/* Enable interrupts from now on */
I 2

E 2
	/*
I 12
	 * Set up CPU-specific registers, cache, etc.
	 */
	initcpu();

	/*
E 12
I 10
	 * Set up buffers, so they can be used to read disk labels.
	 */
	bhinit();
	binit();

	/*
E 10
	 * Configure the system.
	 */
	configure();
}

#ifdef PGINPROF
/*
 * Return the difference (in microseconds)
 * between the  current time and a previous
 * time as represented  by the arguments.
 * If there is a pending clock interrupt
 * which has not been serviced due to high
 * ipl, return error code.
 */
I 2
/*ARGSUSED*/
E 2
vmtime(otime, olbolt, oicr)
	register int otime, olbolt, oicr;
{
D 2
	return(((time.tv_sec-otime)*60 + lbolt-olbolt)*16667);
E 2
I 2

	return (((time.tv_sec-otime)*60 + lbolt-olbolt)*16667);
E 2
}
#endif

/*
 * Send an interrupt to process.
 *
 * Stack is set up to allow sigcode stored
D 2
 * in u. to call routine, followed by chmk
 * to sigcleanup routine below.  After sigcleanup
 * resets the signal mask and the stack, it
 * returns to user who then unwinds with the
 * rei at the bottom of sigcode.
E 2
I 2
 * in u. to call routine, followed by kcall
 * to sigreturn routine below.  After sigreturn
 * resets the signal mask, the stack, and the
 * frame pointer, it returns to the user
 * specified pc, psl.
E 2
 */
sendsig(p, sig, mask)
	int (*p)(), sig, mask;
{
D 2
	register struct sigcontext *scp;	/* know to be r12 */
E 2
I 2
	register struct sigcontext *scp;
E 2
	register int *regs;
	register struct sigframe {
		int	sf_signum;
		int	sf_code;
		struct	sigcontext *sf_scp;
		int	(*sf_handler)();
D 2
		int	r1;
		int 	r0;
E 2
I 2
		int	sf_regs[6];		/* r0-r5 */
E 2
		struct	sigcontext *sf_scpcopy;
D 2
	} *fp;					/* known to be r10 */
E 2
I 2
	} *fp;
E 2
	int oonstack;

	regs = u.u_ar0;
	oonstack = u.u_onstack;
D 2
	scp = (struct sigcontext *)regs[SP] - 1;
E 2
I 2
	/*
	 * Allocate and validate space for the signal handler
	 * context. Note that if the stack is in P0 space, the
	 * call to grow() is a nop, and the useracc() check
	 * will fail if the process has not already allocated
	 * the space with a `brk'.
	 */
E 2
	if (!u.u_onstack && (u.u_sigonstack & sigmask(sig))) {
D 2
		fp = (struct sigframe *)u.u_sigsp - 1;
E 2
I 2
		scp = (struct sigcontext *)u.u_sigsp - 1;
E 2
		u.u_onstack = 1;
	} else
D 2
		fp = (struct sigframe *)scp - 1;
	/*
	 * Must build signal handler context on stack to be returned to
	 * so that rei instruction in sigcode will pop ps and pc
	 * off correct stack.  The remainder of the signal state
	 * used in calling the handler must be placed on the stack
	 * on which the handler is to operate so that the calls
	 * in sigcode will save the registers and such correctly.
	 */
	if (!oonstack && (int)fp <= USRSTACK - ctob(u.u_ssize)) 
E 2
I 2
		scp = (struct sigcontext *)regs[SP] - 1;
	fp = (struct sigframe *)scp - 1;
	if ((int)fp <= USRSTACK - ctob(u.u_ssize)) 
E 2
D 9
		grow((unsigned)fp);
E 9
I 9
		(void) grow((unsigned)fp);
E 9
D 2
	;
#ifndef lint
	asm("probew $1,(r10),$7*4");
	asm("jeql bad");
#else
	if (useracc((caddr_t)fp, sizeof (struct sigframe), 1))
		goto bad;
#endif
	if (!u.u_onstack && (int)scp <= USRSTACK - ctob(u.u_ssize))
		grow((unsigned)scp);
	;			/* Avoid asm() label botch */
#ifndef lint
	asm("probew $1,(r12),$5*4");
	asm("beql bad");
#else
	if (useracc((caddr_t)scp, sizeof (struct sigcontext), 1))
		goto bad;
#endif
E 2
I 2
D 5
	if (useracc((caddr_t)fp, sizeof (*fp) + sizeof (*scp), 1) == 0) {
E 5
I 5
	if (useracc((caddr_t)fp, sizeof (*fp) + sizeof (*scp), B_WRITE) == 0) {
E 5
		/*
		 * Process has trashed its stack; give it an illegal
		 * instruction to halt it in its tracks.
		 */
		u.u_signal[SIGILL] = SIG_DFL;
		sig = sigmask(SIGILL);
		u.u_procp->p_sigignore &= ~sig;
		u.u_procp->p_sigcatch &= ~sig;
		u.u_procp->p_sigmask &= ~sig;
		psignal(u.u_procp, SIGILL);
		return;
	}
	/* 
	 * Build the argument list for the signal handler.
	 */
E 2
	fp->sf_signum = sig;
	if (sig == SIGILL || sig == SIGFPE) {
		fp->sf_code = u.u_code;
		u.u_code = 0;
	} else
		fp->sf_code = 0;
	fp->sf_scp = scp;
	fp->sf_handler = p;
D 2
	fp->r1 = regs[R1];	/* These are not saved by the C compiler */
	fp->r0 = regs[R0];
E 2
	/*
D 2
	 * Duplicate the pointer to the sigcontext structure.
	 * This one doesn't get popped by the ret, and is used 
	 * by sigcleanup to reset the signal state on inward return.
E 2
I 2
	 * Build the callf argument frame to be used to call sigreturn.
E 2
	 */
	fp->sf_scpcopy = scp;
D 2
	/* sigcontext goes on previous stack */
E 2
I 2
	/*
	 * Build the signal context to be used by sigreturn.
	 */
E 2
	scp->sc_onstack = oonstack;
	scp->sc_mask = mask;
D 2
	/* setup rei */
	scp->sc_sp = (int)&scp->sc_pc;
E 2
I 2
	scp->sc_sp = regs[SP];
	scp->sc_fp = regs[FP];
E 2
	scp->sc_pc = regs[PC];
	scp->sc_ps = regs[PS];
	regs[SP] = (int)fp;
	regs[PC] = (int)u.u_pcb.pcb_sigc;
D 2
	return;

asm("bad:");
bad:
	/*
	 * Process has trashed its stack; give it an illegal
	 * instruction to halt it in its tracks.
	 */
	u.u_signal[SIGILL] = SIG_DFL;
	sig = sigmask(SIGILL);
	u.u_procp->p_sigignore &= ~sig;
	u.u_procp->p_sigcatch &= ~sig;
	u.u_procp->p_sigmask &= ~sig;
	psignal(u.u_procp, SIGILL);
E 2
}

/*
D 2
 * Routine to cleanup state after a signal
E 2
I 2
 * System call to cleanup state after a signal
E 2
 * has been taken.  Reset signal mask and
 * stack state from context left by sendsig (above).
D 2
 * Pop these values in preparation for rei which
 * follows return from this routine.
E 2
I 2
 * Return to previous pc and psl as specified by
 * context left by sendsig. Check carefully to
 * make sure that the user has not modified the
 * psl to gain improper priviledges or to cause
 * a machine fault.
E 2
 */
D 2
sigcleanup()
E 2
I 2
sigreturn()
E 2
{
D 2
	register struct sigcontext *scp;	/* known as R12 */
E 2
I 2
	struct a {
		struct sigcontext *sigcntxp;
	};
	register struct sigcontext *scp;
	register int *regs = u.u_ar0;
E 2

D 2
	scp = (struct sigcontext *)fuword((caddr_t)u.u_ar0[SP]);
E 2
I 2
	scp = ((struct a *)(u.u_ap))->sigcntxp;
	if (useracc((caddr_t)scp, sizeof (*scp), 0) == 0) {
		u.u_error = EINVAL;
		return;
	}
	if ((scp->sc_ps & (PSL_MBZ|PSL_IPL|PSL_IS)) != 0 ||
	    (scp->sc_ps & (PSL_PRVMOD|PSL_CURMOD)) != (PSL_PRVMOD|PSL_CURMOD)) {
		u.u_error = EINVAL;
		return;
	}
	u.u_eosys = JUSTRETURN;
	u.u_onstack = scp->sc_onstack & 01;
	u.u_procp->p_sigmask = scp->sc_mask &~
	    (sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP));
	regs[FP] = scp->sc_fp;
	regs[SP] = scp->sc_sp;
	regs[PC] = scp->sc_pc;
	regs[PS] = scp->sc_ps;
}

/* XXX - BEGIN 4.2 COMPATIBILITY */
/*
 * Compatibility with 4.2 kcall $139 used by longjmp()
 */
osigcleanup()
{
	register struct sigcontext *scp;
	register int *regs = u.u_ar0;

	scp = (struct sigcontext *)fuword((caddr_t)regs[SP]);
E 2
	if ((int)scp == -1)
		return;
D 2
#ifndef lint
	;			/* Avoid asm() label botch */
	/* only probe 12 here because that's all we need */
	asm("prober $1,(r12),$12");
	asm("bnequ 1f; ret; 1:");
#else
	if (useracc((caddr_t)scp, sizeof (*scp), 0))
E 2
I 2
	if (useracc((caddr_t)scp, 3 * sizeof (int), 0) == 0)
E 2
		return;
D 2
#endif
E 2
	u.u_onstack = scp->sc_onstack & 01;
D 2
	u.u_procp->p_sigmask =
	   scp->sc_mask &~ (sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP));
	u.u_ar0[SP] = scp->sc_sp;
E 2
I 2
	u.u_procp->p_sigmask = scp->sc_mask &~
	    (sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP));
	regs[SP] = scp->sc_sp;
E 2
}
I 2
/* XXX - END 4.2 COMPATIBILITY */
E 2

int	waittime = -1;

D 12
boot(paniced, arghowto)
	int paniced, arghowto;
E 12
I 12
boot(arghowto)
	int arghowto;
E 12
{
D 2
	register long dummy;
E 2
I 2
	register long dummy;		/* r12 is reserved */
E 2
	register int howto;		/* r11 == how to boot */
	register int devtype;		/* r10 == major of root dev */
I 15
	extern char *panicstr;
E 15

D 13
#ifdef lint
D 2
	howto = 0; devtype = 0;
E 2
I 2
	howto = 0; devtype = 0; dummy = 0; dummy = dummy;
E 2
	printf("howto %d, devtype %d\n", arghowto, devtype);
#endif
	(void) spl1();
E 13
	howto = arghowto;
D 2
	if ((howto&RB_NOSYNC)==0 && waittime < 0 && bfreelist[0].b_forw) {
E 2
I 2
	if ((howto&RB_NOSYNC) == 0 && waittime < 0 && bfreelist[0].b_forw) {
I 13
		register struct buf *bp;
		int iter, nbusy;

E 13
E 2
		waittime = 0;
D 13
		update();
E 13
I 13
		(void) splnet();
E 13
		printf("syncing disks... ");
I 4
		/*
		 * Release inodes held by texts before update.
		 */
D 15
		xumount(NODEV);
E 15
I 15
		if (panicstr == 0)
			xumount(NODEV);
E 15
E 4
D 2
#ifdef notdef
		DELAY(10000000);
#else
E 2
D 13
		{ register struct buf *bp;
		  int iter, nbusy, oldnbusy;
E 13
I 13
		update();
E 13

D 2
		  printf ("\tBlocks to sync : ");
E 2
D 13
		  oldnbusy = 0;
D 2
		  for (iter = 0; /* iter < 20 */; iter++) {
E 2
I 2
		  for (iter = 0; iter < 1000; iter++) {
E 2
			DELAY(1000);
E 13
I 13
		for (iter = 0; iter < 20; iter++) {
E 13
			nbusy = 0;
			for (bp = &buf[nbuf]; --bp >= buf; )
				if ((bp->b_flags & (B_BUSY|B_INVAL)) == B_BUSY)
					nbusy++;
			if (nbusy == 0)
				break;
D 13
			if (nbusy != oldnbusy) {
				printf("%d ", nbusy);
				oldnbusy = nbusy;
			}
D 2
			if (iter >= 100) {
				printf (" - disk I/O stopped (?), giving up\n");
				DELAY(10000);
				break;
			}
E 2
		  }
I 2
		  if (iter >= 1000 && nbusy)
			printf("- i/o timeout, giving up...");
E 13
I 13
			printf("%d ", nbusy);
			DELAY(40000 * iter);
E 13
E 2
		}
D 2
#endif
		printf("done\n\n");
E 2
I 2
D 13
		printf("done\n");
E 13
I 13
		if (nbusy)
			printf("giving up\n");
		else
			printf("done\n");
E 13
I 11
		DELAY(10000);			/* wait for printf to finish */
E 11
E 2
	}
D 2
	splx(0x1f);			/* extreme priority */
E 2
I 2
	mtpr(IPL, 0x1f);			/* extreme priority */
E 2
	devtype = major(rootdev);
I 12
	*(int *)CPBFLG = howto;
E 12
	if (howto&RB_HALT) {
		printf("halting (in tight loop); hit ~h\n\n");
D 2
		mtpr(0x1f,IPL);
E 2
I 2
		mtpr(IPL, 0x1f);
E 2
		for (;;)
			;
	} else {
D 12
		if (paniced == RB_PANIC) {
E 12
I 12
		if (howto & RB_DUMP) {
E 12
D 13
			doadump();		/* TXDB_BOOT's itsself */
E 13
I 13
			doadump();		/* CPBOOT's itsself */
E 13
			/*NOTREACHED*/
		}
I 10
D 12
		*(int *)CPBFLG = howto;
E 12
E 10
		tocons(CPBOOT);
	}
I 13
#ifdef lint
	dummy = 0; dummy = dummy;
	printf("howto %d, devtype %d\n", arghowto, devtype);
#endif
E 13
	for (;;)
		asm("halt");
	/*NOTREACHED*/
}

I 2
D 10
struct	cphdr *lasthdr;		/* defined in cons.c */
E 10
struct	cpdcb_o cpcontrol;
E 2

D 2

E 2
/*
 * Send the given comand ('c') to the console processor.
 * Assumed to be one of the last things the OS does before
 *  halting or rebooting.
 */
D 2

struct cphdr *lasthdr;	/* Available in "dev/cons.c" */

struct	cpdcb_o cpcontrol;

tocons(command)
int command;
E 2
I 2
tocons(c)
E 2
{
D 2

E 2
D 10
	int timeout;
E 10
I 10
	register timeout;
E 10

	cpcontrol.cp_hdr.cp_unit = CPUNIT;
D 2
	cpcontrol.cp_hdr.cp_comm =  (char) command;
	if (command != CPBOOT) 
E 2
I 2
	cpcontrol.cp_hdr.cp_comm =  (char)c;
	if (c != CPBOOT) 
E 2
		cpcontrol.cp_hdr.cp_count = 1;	/* Just for sanity */
	else {
		cpcontrol.cp_hdr.cp_count = 4;
		*(int *)cpcontrol.cp_buf = 0;	/* r11 value for reboot */
	}
	timeout = 100000;				/* Delay loop */
D 2
	while (timeout-- && !(lasthdr->cp_unit & CPDONE))
E 2
I 2
D 10
	while (timeout-- && (lasthdr->cp_unit&CPDONE) == 0)
E 2
		uncache(&lasthdr->cp_unit);
E 10
I 10
	while (timeout-- && (cnlast->cp_unit&CPDONE) == 0)
		uncache(&cnlast->cp_unit);
E 10
D 2
					/* Give up, force it to listen */
	mtpr ( vtoph(0, &cpcontrol), CPMDCB);
E 2
I 2
	/* give up, force it to listen */
	mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)&cpcontrol));
E 2
}

I 2
#if CLSIZE != 1
E 2
/*
 * Invalidate single all pte's in a cluster
 */
tbiscl(v)
	unsigned v;
{
	register caddr_t addr;		/* must be first reg var */
	register int i;

	addr = ptob(v);
	for (i = 0; i < CLSIZE; i++) {
D 2
		mtpr(addr, TBIS);
E 2
I 2
		mtpr(TBIS, addr);
E 2
		addr += NBPG;
	}
}
I 2
#endif
E 2

int	dumpmag = 0x8fca0101;	/* magic number for savecore */
int	dumpsize = 0;		/* also for savecore */
/*
 * Doadump comes here after turning off memory management and
 * getting on the dump stack, either when called above, or by
 * the auto-restart code.
 */
dumpsys()
{

I 8
	if (dumpdev == NODEV)
		return;
E 8
#ifdef notdef
	if ((minor(dumpdev)&07) != 1)
		return;
#endif
	dumpsize = physmem;
	printf("\ndumping to dev %x, offset %d\n", dumpdev, dumplo);
	printf("dump ");
	switch ((*bdevsw[major(dumpdev)].d_dump)(dumpdev)) {

	case ENXIO:
		printf("device bad\n");
		break;

	case EFAULT:
		printf("device not ready\n");
		break;

	case EINVAL:
		printf("area improper\n");
		break;

	case EIO:
		printf("i/o error\n");
		break;

	default:
		printf("succeeded\n");
		break;
	}
D 2
	printf("Rebooting the system ...\n\n");
E 2
I 2
	printf("\n\n");
	DELAY(1000);
E 2
	tocons(CPBOOT);
}

D 2

E 2
/*
 * Bus error 'recovery' code.
 * Print out the buss frame and then give up.
 * (More information from special registers can be printed here.)
D 2
 * 
E 2
 */

/*
 * Frame for bus error
 */
struct buserframe {
	int	which_bus;		/* primary or secondary */
	int	memerreg;		/* memory error register */
	int	trp_pc;			/* trapped pc */
	int	trp_psl;		/* trapped psl */
};

D 2
buserror(busef)
	caddr_t busef;
E 2
I 2
char	*mem_errcd[8] = {
	"Unknown error code 0",
	"Address parity error",		/* APE */
	"Data parity error",		/* DPE */
	"Data check error",		/* DCE */
	"Versabus timeout",		/* VTO */
	"Versabus error",		/* VBE */
	"Non-existent memory",		/* NEM */
	"Unknown error code 7",
};

buserror(v)
	caddr_t v;
E 2
{
D 2
	register struct buserframe *frameptr;
	register long 	hardreg;
E 2
I 2
	register struct buserframe *busef = (struct buserframe *)v;
	register long reg;
E 2

D 2

	frameptr = (struct buserframe *)busef;
	printf("bus error at address %x, psl = %x\n",
		frameptr->trp_pc,frameptr->trp_psl);
	hardreg =  frameptr->memerreg;
	printf("\tMEAR = %x\n",((hardreg&MEAR)>>16)&0xffff);
	switch (hardreg & ERRCD){
		case (APE): 	printf("\tAdress parity error.Should not reach this point!! \n");
				break;
		case (DPE): 	printf("\tData parity error.\n");
				break;
		case (DCE):	printf("\tData check error.\n");
				break;
		case (VTO):	printf("\tVersabus timeout.\n");
				break;
		case (VBE):	printf("\tVersabus error.Should not reach this point!! \n");
				break;
		case (NEM):	printf("\tNon existent memory.\n");
				break;
		default:	printf("\tUnknown error code: %x\n",
					hardreg&ERRCD);
	}
	if (hardreg&AXE) printf("\tAdapter external error\n");
	printf ("\tError master : ");
	if (hardreg&ERM) printf("Versabus\n");
	else printf ("Tahoe\n");
	if (hardreg&IVV)
		printf("\tIllegal interrupt vector, from ipl %d\n",
		    (hardreg >> 2) & 7);

	hardreg = frameptr->which_bus;
	printf("\tMCBR = %x\n", ((hardreg&MCBR)>>16)&0xffff);
	printf("\tVersabus type : %x\n", hardreg&0xffc3);
	if (frameptr->memerreg&IVV) return;
	panic("buserror");
E 2
I 2
	printf("bus error, address %x, psl %x\n",
	    busef->trp_pc, busef->trp_psl);
	reg =  busef->memerreg;
	printf("mear %x %s\n",
	    ((reg&MEAR)>>16)&0xffff, mem_errcd[reg & ERRCD]);
	if (reg&AXE)
		printf("adapter external error\n");
	printf("error master: %s\n", reg&ERM ? "versabus" : "tahoe");
	if (reg&IVV)
		printf("illegal interrupt vector from ipl %d\n", (reg>>2)&7);
	reg = busef->which_bus;
	printf("mcbr %x versabus type %x\n",
	    ((reg&MCBR)>>16)&0xffff, reg & 0xffc3);
	if ((busef->memerreg&IVV) == 0)
		panic("buserror");
I 4
}

microtime(tvp)
	register struct timeval *tvp;
{
	int s = splhigh();

	*tvp = time;
	tvp->tv_usec += tick;
	while (tvp->tv_usec > 1000000) {
		tvp->tv_sec++;
		tvp->tv_usec -= 1000000;
	}
D 19
	splx(s);
E 4
E 2
}

D 2

E 2
physstrat(bp, strat, prio)
	struct buf *bp;
	int (*strat)(), prio;
{
	int s;

	(*strat)(bp);
	/* pageout daemon doesn't wait for pushed pages */
	if (bp->b_flags & B_DIRTY)
		return;
	s = spl8();
	while ((bp->b_flags & B_DONE) == 0)
		sleep((caddr_t)bp, prio);
E 19
	splx(s);
I 12
}

initcpu()
{
	register struct proc *p;

	p = &proc[0];
D 22
#ifndef lint
E 22
#define	initkey(which, p, index) \
    which/**/_cache[index] = 1, which/**/_cnt[index] = 1; \
    p->p_/**/which = index;
	initkey(ckey, p, MAXCKEY);
	initkey(dkey, p, MAXDKEY);
D 22
#endif
E 22
E 12
}

D 2

/*ARGSUSED*/
mtpr (value, regno)
E 2
I 2
/*
 * Clear registers on exec
 */
setregs(entry)
	u_long entry;
E 2
{
D 2
	asm("mtpr 4(fp), 8(fp)");
}
E 2

D 2
/*ARGSUSED*/
int
mfpr (regno)
{
	asm("mfpr 4(fp),r0");
#ifdef lint
	return(0);
E 2
I 2
#ifdef notdef
	/* should pass args to init on the stack */
	for (rp = &u.u_ar0[0]; rp < &u.u_ar0[16];)
		*rp++ = 0;
E 2
#endif
I 2
	u.u_ar0[FP] = 0;	/* bottom of the fp chain */
	u.u_ar0[PC] = entry + 2;
E 2
}
D 2

E 2
E 1
