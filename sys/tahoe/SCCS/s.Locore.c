h49240
s 00003/00000/00294
d D 7.2 88/05/27 16:41:46 karels 9 8
c lint
e
s 00000/00000/00294
d D 7.1 88/05/26 09:09:49 karels 8 7
c bring up to revision 7 for tahoe release
e
s 00025/00023/00269
d D 1.6 88/05/26 09:05:09 karels 7 5
c lint, header cleanups
e
s 00017/00018/00274
d R 7.1 88/05/21 18:34:49 karels 6 5
c bring up to revision 7 for tahoe release
e
s 00000/00001/00292
d D 1.5 87/06/06 15:13:09 mckusick 5 4
c calloc is gone
e
s 00002/00002/00291
d D 1.4 87/06/06 13:16:20 mckusick 4 3
c camap is replaced by kmempt
e
s 00014/00048/00279
d D 1.3 86/12/15 20:27:43 sam 3 2
c lint
e
s 00175/00133/00152
d D 1.2 86/01/05 18:42:13 sam 2 1
c 1st working version
e
s 00285/00000/00000
d D 1.1 85/07/21 20:20:49 sam 1 0
c date and time created 85/07/21 20:20:49 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

D 2
#include "dz.h"
#include "mba.h"
#include "uba.h"
E 2
I 2
D 7
#include "../tahoe/mtpr.h"
#include "../tahoe/trap.h"
#include "../tahoe/psl.h"
#include "../tahoe/pte.h"
#include "../tahoe/cp.h"
#include "../tahoe/mem.h"
#include "../tahoemath/fp.h"
E 2

E 7
D 2
#include "../machine/pte.h"
E 2
I 2
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "vm.h"
#include "ioctl.h"
#include "tty.h"
#include "proc.h"
#include "buf.h"
#include "msgbuf.h"
#include "mbuf.h"
#include "protosw.h"
#include "domain.h"
#include "map.h"
E 2

I 3
D 7
#include "../tahoe/cpu.h"
E 7
I 7
#include "cpu.h"
#include "mtpr.h"
#include "trap.h"
#include "psl.h"
#include "pte.h"
#include "scb.h"
#include "cp.h"
#include "mem.h"
E 7

I 7
#include "../tahoemath/fp.h"

E 7
E 3
D 2
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/vm.h"
#include "../h/tty.h"
#include "../h/proc.h"
#include "../h/buf.h"
#include "../h/msgbuf.h"
#include "../h/mbuf.h"
#include "../h/protosw.h"
#include "../h/domain.h"

#include "../vax/nexus.h"
#include "../vaxuba/ubavar.h"
#include "../vaxuba/ubareg.h"

E 2
/*
 * Pseudo file for lint to show what is used/defined in locore.s.
 */

struct	scb scb;
D 2
int	(*UNIvec[128])();
#if NUBA > 1
int	(*UNI1vec[128])();
#endif
E 2
struct	rpb rpb;
D 2
int	intstack[3*128];

E 2
I 2
int	dumpflag;
int	intstack[3*NBPG];
E 2
int	masterpaddr;		/* p_addr of current process on master cpu */
D 2

E 2
struct	user u;
I 2
int	icode[8];
int	szicode = sizeof (icode);
I 3
D 7
long	catcher[191];
E 7
I 7
quad	catcher[SCB_LASTIV];
E 7
E 3
/*
 * Variables declared for savecore, or
 * implicitly, such as by config or the loader.
 */
D 7
char	version[] = "4.2 BSD UNIX ....";
E 7
I 7
char	version[] = "4.3 BSD UNIX ....";
E 7
int	etext;
I 3
D 7
int	end;
E 7
E 3
E 2

doadump() { dumpsys(); }

D 2
Xmba3int() { }
Xmba2int() { }
Xmba1int() { }
Xmba0int() { }

E 2
lowinit()
{
I 7
#if !defined(GPROF)
E 7
I 2
	caddr_t cp;
I 7
#endif
E 7
E 2
	extern int dumpmag;
I 2
	extern int rthashsize;
	extern int arptab_size;
	extern int dk_ndrive;
E 2
	extern struct domain unixdomain;
D 7
#ifdef PUP
	extern struct domain pupdomain;
#endif
E 7
#ifdef INET
	extern struct domain inetdomain;
#endif
#include "imp.h"
#if NIMP > 0
	extern struct domain impdomain;
#endif
I 2
#ifdef NS
	extern struct domain nsdomain;
#endif
D 3
	extern int nport;
	extern short *swsize;
	extern int *swpf;
E 3
E 2

	/* cpp messes these up for lint so put them here */
	unixdomain.dom_next = domains;
	domains = &unixdomain;
D 7
#ifdef PUP
	pupdomain.dom_next = domains;
	domains = &pupdomain;
#endif
E 7
#ifdef INET
	inetdomain.dom_next = domains;
	domains = &inetdomain;
#endif
#if NIMP > 0
	impdomain.dom_next = domains;
	domains = &impdomain;
#endif
I 2
#ifdef NS
	nsdomain.dom_next = domains;
	domains = &nsdomain;
#endif
E 2
	dumpmag = 0;			/* used only by savecore */
I 2
	rthashsize = rthashsize;	/* used by netstat, etc. */
	arptab_size = arptab_size;	/* used by arp command */
	dk_ndrive = dk_ndrive;		/* used by vmstat, iostat, etc. */
E 2

	/*
	 * Pseudo-uses of globals.
	 */
	lowinit();
	intstack[0] = intstack[1];
	rpb = rpb;
	scb = scb;
	maxmem = physmem = freemem = 0;
	u = u;
I 3
	fixctlrmask();
E 3
D 2
	fixctlrmask();
E 2
	main(0);
D 2
	Xustray();
E 2
I 2
D 3
	swsize = swsize;		/* XXX */
	swpf = swpf;			/* XXX */
	nport = nport;			/* XXX */
E 3
E 2

	/*
	 * Routines called from interrupt vectors.
	 */
I 2
	buserror((caddr_t)0);
E 2
	panic("Machine check");
	printf("Write timeout");
D 2
	(*UNIvec[0])();
#if NUBA > 1
	(*UNI1vec[0])();
E 2
I 2
	rawintr();
#ifdef INET
	ipintr();
E 2
#endif
D 2
	ubaerror(0, (struct uba_hd *)0, 0, 0, (struct uba_regs *)0);
E 2
I 2
#ifdef NS
	nsintr();
#endif
E 2
	cnrint(0);
	cnxint(0);
D 2
	consdin();
	consdout();
#if NDZ > 0
	dzdma();
#endif
#if NMBA > 0
	mbintr(0);
#endif
E 2
	hardclock((caddr_t)0, 0);
	softclock((caddr_t)0, 0);
D 2
	trap(0, 0, (unsigned)0, 0, 0);
	syscall(0, 0, (unsigned)0, 0, 0);
	ipintr();
	rawintr();
E 2
I 2
	fpemulate(0, 0, 0, 0, 0, 0, 0, 0, 0);
	trap(0, 0, 0, 0, 0, 0, (unsigned)0, 0, 0);
	syscall(0, 0, 0, 0, 0, 0, (unsigned)0, 0, 0);
E 2

	if (vmemall((struct pte *)0, 0, (struct proc *)0, 0))
		return;		/* use value */
D 2
	machinecheck((caddr_t)0);
	memerr();
E 2
I 2
D 3
	if (zmemall((int (*)())0, 0) == (caddr_t)0)
		return;		/* use value */
E 3
E 2
	boothowto = 0;
I 2
D 3
/* the following are not currently used but will soon */
E 3
	if (rmget((struct map *)0, 0, 0) == 0)
		return;
D 5
	cp = calloc(0); cfreemem(cp, 0);
E 5
D 3
/* end not currently used */
E 3
	dumpflag = 0; dumpflag = dumpflag;
I 9
#ifdef KADB
	bootesym = 0; bootesym = bootesym;
#endif
E 9
#if !defined(GPROF)
	cp = (caddr_t)&etext;
I 7
	cp = cp;
E 7
#endif
E 2
}

D 2
consdin() { }
consdout() { }
#if NDZ > 0
dzdma() { dzxint((struct tty *)0); }
#endif

int	catcher[256];
int	cold = 1;

Xustray() { }

E 2
struct	pte Sysmap[6*NPTEPG];
D 2
char	Sysbase[6*NPTEPG*NBPG];
int	umbabeg;
struct	pte Nexmap[16][16];
struct	nexus nexus[MAXNNEXUS];
struct	pte UMEMmap[MAXNUBA][512];
char	umem[MAXNUBA][512*NBPG];
int	umbaend;
E 2
I 2
caddr_t	Sysbase;
struct	pte VMEMmap[1];
D 3
int	vmembeg, vmemend;
E 3
I 3
caddr_t	vmem, vmembeg, vmemend;
struct	pte VMEMmap1[1];
caddr_t	vmem1;
struct	pte VBmap[1];
caddr_t	vbbase, vbend;
E 3
E 2
struct	pte Usrptmap[USRPTSIZE];
struct	pte usrpt[USRPTSIZE*NPTEPG];
struct	pte Forkmap[UPAGES];
struct	user forkutl;
struct	pte Xswapmap[UPAGES];
struct	user xswaputl;
struct	pte Xswap2map[UPAGES];
struct	user xswap2utl;
struct	pte Swapmap[UPAGES];
struct	user swaputl;
struct	pte Pushmap[UPAGES];
struct	user pushutl;
struct	pte Vfmap[UPAGES];
struct	user vfutl;
D 2
struct	pte CMAP1;
char	CADDR1[NBPG];
struct	pte CMAP2;
char	CADDR2[NBPG];
E 2
I 2
D 3
#include "fsd.h"
#if NVD > 0
struct	pte VD0map[MAXBPTE+1];
char	vd0utl[1];
#endif
#if NVD > 1
struct	pte VD1map[MAXBPTE+1];
char	vd1utl[1];
#endif
#if NVD > 2
struct	pte VD2map[MAXBPTE+1];
char	vd2utl[1];
#endif
#if NVD > 3
struct	pte VD3map[MAXBPTE+1];
char	vd3utl[1];
#endif
#include "cy.h"
#if NCY > 0
struct	pte CY0map[TBUFSIZ+1];
char	cy0utl[1];
#endif
#if NCY > 1
struct	pte CY1map[TBUFSIZ+1];
char	cy1utl[1];
#endif
#include "ace.h"
#if NACE > 0
struct	pte ACE0map[1], ACE1map[1];
char	ace0utl[1], ace1utl[1];
#endif
E 3
struct	pte CMAP1[1], CMAP2[1];
caddr_t	CADDR1, CADDR2;
E 2
struct	pte mmap[1];
D 2
char	vmmap[NBPG];
E 2
I 2
char	vmmap[1];
struct	pte msgbufmap[3*NBPG];
struct	msgbuf msgbuf;
D 4
struct	pte camap[16];
int	cabase, calimit;
E 4
I 4
D 7
struct	pte kmempt[100];
int	kmembase, kmemlimit;
E 7
I 7
struct	pte kmempt[100], ekmempt[1];
char	kmembase[100*NBPG];
E 7
E 4
E 2
struct	pte Mbmap[NMBCLUSTERS/CLSIZE];
struct	mbuf mbutl[NMBCLUSTERS*CLBYTES/sizeof (struct mbuf)];
D 2
struct	pte msgbufmap[CLSIZE];
struct	msgbuf msgbuf;
struct	pte camap[32];
int	cabase;
#ifdef unneeded
char	caspace[32*NBPG];
#endif
int	calimit;
E 2

/*ARGSUSED*/
badaddr(addr, len) caddr_t addr; int len; { return (0); }
D 2

E 2
I 2
D 3
#if NCY > 0
E 3
E 2
/*ARGSUSED*/
D 2
copyin(udaddr, kaddr, n) caddr_t udaddr, kaddr; unsigned n; { return (0); }

E 2
I 2
D 3
badcyaddr(addr) caddr_t addr; { return (0); }
#endif
E 2
/*ARGSUSED*/
E 3
D 2
copyout(kaddr, udaddr, n) caddr_t kaddr, udaddr; unsigned n; { return (0); }

E 2
I 2
ovbcopy(from, to, len) caddr_t from, to; unsigned len; { }
copyinstr(udaddr, kaddr, maxlength, lencopied)
    caddr_t udaddr, kaddr; u_int maxlength, *lencopied;
{ *kaddr = *udaddr; *lencopied = maxlength; return (0); }
copyoutstr(kaddr, udaddr, maxlength, lencopied)
    caddr_t kaddr, udaddr; u_int maxlength, *lencopied;
{ *kaddr = *udaddr; *lencopied = maxlength; return (0); }
copystr(kfaddr, kdaddr, maxlength, lencopied)
    caddr_t kfaddr, kdaddr; u_int maxlength, *lencopied;
{ *kdaddr = *kfaddr; *lencopied = maxlength; return (0); }
E 2
/*ARGSUSED*/
D 2
setjmp(lp) label_t *lp; { return (0); }
E 2
I 2
copyin(udaddr, kaddr, n) caddr_t udaddr, kaddr; u_int n; { return (0); }
/*ARGSUSED*/
copyout(kaddr, udaddr, n) caddr_t kaddr, udaddr; u_int n; { return (0); }
E 2

/*ARGSUSED*/
longjmp(lp) label_t *lp; { /*NOTREACHED*/ }

/*ARGSUSED*/
I 2
savectx(lp) label_t *lp; { return (0); }

/*ARGSUSED*/
E 2
setrq(p) struct proc *p; { }

/*ARGSUSED*/
remrq(p) struct proc *p; { }

swtch() { if (whichqs) whichqs = 0; if (masterpaddr) masterpaddr = 0; }

/*ARGSUSED*/
resume(pcbpf) unsigned pcbpf; { }

/*ARGSUSED*/
fubyte(base) caddr_t base; { return (0); }
D 2

E 2
/*ARGSUSED*/
subyte(base, i) caddr_t base; { return (0); }
D 2

E 2
/*ARGSUSED*/
D 2
suibyte(base, i) caddr_t base; { return (0); }
E 2
I 2
fuword(base) caddr_t base; { return (0); }
/*ARGSUSED*/
suword(base, i) caddr_t base; { return (0); }
E 2

/*ARGSUSED*/
D 2
fuword(base) caddr_t base; { return (0); }
E 2
I 2
copyseg(udaddr, pf)
    caddr_t udaddr; unsigned pf;
{ CMAP1[0] = CMAP1[0]; CADDR1[0] = CADDR1[0]; }
E 2

/*ARGSUSED*/
D 2
fuiword(base) caddr_t base; { return (0); }
E 2
I 2
clearseg(pf) unsigned pf; { CMAP2[0] = CMAP2[0]; CADDR2[0] = CADDR2[0]; }
E 2

/*ARGSUSED*/
D 2
suword(base, i) caddr_t base; { return (0); }
E 2
I 2
useracc(udaddr, bcnt, rw) caddr_t udaddr; unsigned bcnt; { return (0); }
E 2

/*ARGSUSED*/
D 2
suiword(base, i) caddr_t base; { return (0); }
E 2
I 2
kernacc(addr, bcnt, rw) caddr_t addr; unsigned bcnt; { return (0); }
E 2

/*ARGSUSED*/
D 2
copyseg(udaddr, pf) caddr_t udaddr; unsigned pf; {
    CMAP1 = CMAP1; CADDR1[0] = CADDR1[0];
}
E 2
I 2
addupc(pc, prof, counts) int pc; struct uprof *prof; int counts; { }
E 2

/*ARGSUSED*/
D 2
clearseg(pf) unsigned pf; { CMAP2 = CMAP2; CADDR2[0] = CADDR2[0]; }
E 2
I 2
scanc(size, cp, table, mask)
D 7
    unsigned size; char *cp, table[]; int mask;
E 7
I 7
    unsigned size; u_char *cp, table[]; u_char mask;
E 7
{ return (0); }
E 2

/*ARGSUSED*/
D 2
useracc(udaddr, bcnt, rw) caddr_t udaddr; unsigned bcnt; { return (0); }
E 2
I 2
D 3
skpc(mask, size, cp) int mask; char *cp; unsigned size; { return (0); }
E 3
I 3
skpc(mask, size, cp) int mask; int size; char *cp; { return (0); }
E 3
E 2

I 2
#ifdef notdef
E 2
/*ARGSUSED*/
D 2
kernacc(addr, bcnt, rw) caddr_t addr; unsigned bcnt; { return (0); }
E 2
I 2
D 3
locc(mask, size, cp) int mask; char *cp; unsigned size; { return (0); }
E 3
I 3
locc(mask, size, cp) int mask; int size; char *cp; { return (0); }
E 3
#endif
E 2

/*
D 2
 * Routines handled by asm.sed script.
E 2
I 2
 * Routines expanded by inline.
E 2
 */
I 2
#ifdef notdef
fuibyte(base) caddr_t base; { return (fubyte(base)); }
#endif
fuiword(base) caddr_t base; { return (fuword(base)); }
suibyte(base, i) caddr_t base; { return (subyte(base, i)); }
suiword(base, i) caddr_t base; { return (suword(base, i)); }
E 2

D 2
/*VARARGS1*/
E 2
/*ARGSUSED*/
D 2
mtpr(reg, value) int reg, value; { }
E 2
I 2
setjmp(lp) label_t *lp; { return (0); }
E 2

/*ARGSUSED*/
D 2
mfpr(reg) int reg; { return (0); }


spl0() { }
spl4() { return (0); }
spl5() { return (0); }
spl6() { return (0); }
spl7() { return (0); }

E 2
I 2
_insque(p, q) caddr_t p, q; { }
E 2
/*ARGSUSED*/
D 2
splx(s) int s; { }
E 2
I 2
_remque(p) caddr_t p; { }
E 2

/*ARGSUSED*/
D 2
bcopy(from, to, count) caddr_t from, to; unsigned count; { ; }

E 2
I 2
bcopy(from, to, len) caddr_t from, to; unsigned len; { }
E 2
/*ARGSUSED*/
D 2
bzero(base, count) caddr_t base; unsigned count; { ; }
E 2
I 2
bzero(base, count) caddr_t base; unsigned count; { }
/*ARGSUSED*/
blkclr(base, count) caddr_t base; unsigned count; { }
E 2

/*ARGSUSED*/
D 2
bcmp(s1, s2, count) caddr_t s1, s2; unsigned count; { return (0); }
E 2
I 2
/*VARARGS1*/
mtpr(reg, v) int reg; { }
/*ARGSUSED*/
mfpr(reg) int reg; { return (0); }
E 2

/*ARGSUSED*/
D 2
scanc(size, cp, table, mask)
unsigned size; caddr_t cp, table; int mask; { return (0); }
E 2
I 2
_movow(dst, v) u_short *dst, v; { }
/*ARGSUSED*/
_movob(dst, v) u_char *dst, v; { }
E 2

/*ARGSUSED*/
D 2
ffs(i) { return (0); }
E 2
I 2
ffs(v) long v; { return (0); }
E 2

D 2
ntohs(s) u_short s; { return ((int)s); }

htons(s) u_short s; { return ((int)s); }

/*
 * Variables declared for savecore, or
 * implicitly, such as by config or the loader.
 */
char	version[] = "4.2 BSD UNIX ....";
char	etext;
E 2
I 2
imin(a, b) int a, b; { return (a < b ? a : b); }
imax(a, b) int a, b; { return (a > b ? a : b); }
I 3
#ifdef notdef
E 3
unsigned min(a, b) u_int a, b; { return (a < b ? a : b); }
unsigned max(a, b) u_int a, b; { return (a > b ? a : b); }
I 3
#endif
E 3
E 2
E 1
