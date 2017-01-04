h45755
s 00000/00000/00500
d D 7.1 88/05/26 09:09:50 karels 22 21
c bring up to revision 7 for tahoe release
e
s 00011/00005/00489
d D 1.18 88/05/26 09:05:11 karels 21 19
c lint, header cleanups
e
s 00007/00001/00493
d R 7.1 88/05/21 18:34:54 karels 20 19
c bring up to revision 7 for tahoe release
e
s 00013/00005/00481
d D 1.17 88/05/02 20:13:11 karels 19 18
c perhaps a megabyte of tmp space is a bit excessive
e
s 00008/00006/00478
d D 1.16 88/02/08 13:39:58 karels 18 17
c new bootdev macros, check controller; off by one
e
s 00006/00004/00478
d D 1.15 87/06/30 23:36:07 karels 17 16
c change panics in vbmap allocation to return failure
e
s 00005/00003/00477
d D 1.14 87/06/22 10:56:32 mckusick 16 15
c zmemall => malloc
e
s 00007/00007/00473
d D 1.13 87/04/02 15:57:29 karels 15 13
c working with pack labels
e
s 00070/00007/00473
d D 1.12.1.1 87/04/02 15:57:03 karels 14 13
c ifdef for dev_bsize (almost working)
e
s 00006/00003/00474
d D 1.12 87/02/18 21:59:57 sam 13 12
c set controller number for for attach routine; add swapconf 
c check for error return from size routine
e
s 00001/00001/00476
d D 1.11 87/01/04 17:22:08 root 12 11
c rm spaces in printfs
e
s 00002/00001/00475
d D 1.10 86/12/18 23:53:36 karels 11 10
c consolidate printfs
e
s 00006/00005/00470
d D 1.9 86/12/15 20:57:17 sam 10 8
c lint
e
s 00004/00003/00472
d R 1.9 86/12/15 20:27:45 sam 9 8
c lint
e
s 00071/00027/00404
d D 1.8 86/12/08 19:08:18 sam 8 7
c support devices w/o interrupt vectors; track and check for 
c overlapping devices in mapped region of VERSAbus; use 32-bit i/o 
c addresses to allow devices outside mapped region to be specified in 
c configuration files
e
s 00000/00004/00431
d D 1.7 86/11/25 16:41:41 sam 7 6
c remove kludge for device names
e
s 00100/00001/00335
d D 1.6 86/07/16 08:25:47 sam 6 5
c add setroot stuff from vax 4.3; handle new boot stuff; change disk names
e
s 00056/00010/00280
d D 1.5 86/01/20 23:52:28 sam 5 4
c cleanup some more of the autoconfig stuff: eliminate all page 
c maps defined in locore.s in favor of dynamically allocated entries; rename 
c some of the iospace definitions and move them into ../tahoevba/vbaparam.h 
c (will ease vme support sometime?)
e
s 00002/00002/00288
d D 1.4 86/01/12 16:26:59 sam 4 3
c add casts to silence compiler warnings
e
s 00118/00029/00172
d D 1.3 86/01/12 15:38:21 sam 3 2
c 4.3- plus start of autoconfig
e
s 00036/00048/00165
d D 1.2 86/01/05 18:42:15 sam 2 1
c 1st working version
e
s 00213/00000/00000
d D 1.1 85/07/21 20:20:50 sam 1 0
c date and time created 85/07/21 20:20:50 by sam
e
u
U
f b 
t
T
I 1
D 21
/*	%M%	%I%	%E%	*/
E 21
I 21
/*
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 21

/*
 * Setup the system to run on the current machine.
 *
 * Configure() is called at boot time and initializes the vba 
 * device tables and the memory controller monitoring.  Available
 * devices are determined (from possibilities mentioned in ioconf.c),
 * and the drivers are initialized.
D 3
 *
E 3
 */
I 2
D 14
D 15
#include "../tahoe/pte.h"
#include "../tahoe/mem.h"
#include "../tahoe/mtpr.h"
I 3
#include "../tahoe/scb.h"
E 3
E 2

I 3
#include "vba.h"

E 15
E 14
E 3
D 2
#include "../machine/pte.h"
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/map.h"
#include "../h/buf.h"
#include "../h/dk.h"
#include "../h/vm.h"
#include "../h/conf.h"
#include "../h/dmap.h"
#include "../machine/mem.h"
#include "../machine/mtpr.h"
#include "../vba/vbavar.h"
E 2
I 2
#include "param.h"
#include "systm.h"
#include "map.h"
#include "buf.h"
D 6
#include "dk.h"
E 6
I 6
#include "dkstat.h"
E 6
#include "vm.h"
#include "conf.h"
#include "dmap.h"
I 6
#include "reboot.h"
I 16
#include "malloc.h"
E 16
I 15

#include "pte.h"
#include "mem.h"
#include "mtpr.h"
#include "scb.h"

#include "vba.h"
E 15
I 14
#ifdef SECSIZE
#include "file.h"
#include "ioctl.h"
#include "disklabel.h"
#endif SECSIZE
E 14
E 6
E 2

I 14
#include "pte.h"
#include "mem.h"
#include "mtpr.h"
#include "scb.h"

#include "vba.h"

E 14
I 2
#include "../tahoevba/vbavar.h"
I 5
#include "../tahoevba/vbaparam.h"
E 5

E 2
/*
 * The following several variables are related to
 * the configuration process, and are used in initializing
 * the machine.
 */
int	dkn;		/* number of iostat dk numbers assigned so far */
I 3
int	cold;		/* cold start flag initialized in locore.s */
E 3

/*
I 3
D 5
 * This allocates the space for the per-uba information,
 * such as buffered data path usage.
E 5
I 5
 * This allocates the space for the per-vba information.
E 5
 */
struct	vba_hd vba_hd[NVBA];

/*
E 3
D 8
 * Determine mass storage configuration for a machine.
E 8
I 8
 * Determine i/o configuration for a machine.
E 8
 */
configure()
{
	register int *ip;
D 2
	extern char Sysbase[];
E 2
I 2
	extern caddr_t Sysbase;
E 2

D 2
	printf("vba%d at 0x%x\n", numvba, IOBASE);
	vbafind((char *)vmem,(struct pte *)VMEMmap);
E 2
I 2
D 3
	printf("vba%d at %x\n", numvba-1, IOBASE);
	vbafind(numvba-1, (char *)vmem,(struct pte *)VMEMmap);
E 3
I 3
D 5
	printf("vba%d at %x\n", numvba, IOBASE);
	vbafind(numvba, (char *)vmem,(struct pte *)VMEMmap);
E 5
I 5
D 8
	printf("vba%d at %x\n", numvba, VBIOBASE);
E 8
D 10
	vbafind(numvba, vmem, VMEMmap);
E 10
I 10
	vbafind(numvba, (caddr_t)&vmem, VMEMmap);
E 10
E 5
	numvba++;
E 3
E 2
	/*
	 * Write protect the scb.  It is strange
	 * that this code is here, but this is as soon
	 * as we are done mucking with it, and the
	 * write-enable was done in assembly language
	 * to which we will never return.
	 */
	ip = (int *)&Sysmap[2]; *ip &= ~PG_PROT; *ip |= PG_KR;
D 2
	mtpr(Sysbase+0x800, TBIS);
E 2
I 2
	mtpr(TBIS, Sysbase+2*NBPG);
E 2
#if GENERIC
I 6
	if ((boothowto & RB_ASKNAME) == 0)
		setroot();
E 6
	setconf();
I 6
#else
	setroot();
E 6
#endif
I 6
	/*
	 * Configure swap area and related system
	 * parameter based on device(s) used.
	 */
E 6
	swapconf();
I 3
	cold = 0;
E 3
}

D 3

E 3
/*
 * Make the controllers accessible at physical address phys
 * by mapping kernel ptes starting at pte.
 */
D 2

ioaccess(pte,iobase,iosize)
E 2
I 2
D 3
ioaccess(pte, iobase, n)
E 3
I 3
D 5
vbaaccess(pte, iobase, n)
E 5
I 5
vbaccess(pte, iobase, n)
E 5
E 3
E 2
	register struct pte *pte;
D 2
	register caddr_t iobase;
	register int	iosize;
E 2
I 2
	caddr_t iobase;
	register int n;
E 2
{
D 2
	register int i = iosize;	/* number of ptes to map */
E 2
	register unsigned v = btop(iobase);
	
	do
		*(int *)pte++ = PG_V|PG_KW|v++;
D 2
	while (--i > 0);
	mtpr(0, TBIA);
E 2
I 2
	while (--n > 0);
	mtpr(TBIA, 0);
E 2
}

I 3
/*
 * Fixctlrmask fixes the masks of the driver ctlr routines
 * which otherwise save r11 and r12 where the interrupt and br
 * level are passed through.
 */
fixctlrmask()
{
	register struct vba_ctlr *vm;
	register struct vba_device *vi;
	register struct vba_driver *vd;
#define	phys(a,b) ((b)(((int)(a))&~0xc0000000))
E 3

I 3
	vm = phys(vbminit, struct vba_ctlr *);
	for (; vd = phys(vm->um_driver, struct vba_driver *); vm++)
		*phys(vd->ud_probe, short *) &= ~0x1800;
	vi = phys(vbdinit, struct vba_device *);
	for (; vd = phys(vi->ui_driver, struct vba_driver *); vi++)
		*phys(vd->ud_probe, short *) &= ~0x1800;
}

E 3
/*
D 3
 * Find devices on the BUS.
E 3
I 3
 * Find devices on the VERSAbus.
E 3
 * Uses per-driver routine to see who is on the bus
 * and then fills in the tables, with help from a per-driver
 * slave initialization routine.
 */
D 3

int	iospace_mapped = 0;

E 3
D 2
vbafind(vumem, memmap)
E 2
I 2
vbafind(vban, vumem, memmap)
	int vban;
E 2
D 5
	char *vumem;
	struct pte *memmap;
E 5
I 5
	caddr_t vumem;
	struct pte memmap[];
E 5
{
I 3
	register int br, cvec;			/* must be r12, r11 */
E 3
	register struct vba_device *ui;
	register struct vba_ctlr *um;
	u_short *reg;
D 3
	long  addr;
E 3
I 3
	long addr, *ap;
	struct vba_hd *vhp;
E 3
	struct vba_driver *udp;
D 3
	int i;
E 3
I 3
D 13
	int i, (**ivec)();
E 13
I 13
	int i, octlr, (**ivec)();
E 13
I 8
D 16
	caddr_t valloc, zmemall();
E 16
I 16
	caddr_t valloc;
E 16
E 8
D 10
	extern long cold, catcher[SCB_LASTIV*2];
E 10
I 10
D 21
	extern long catcher[SCB_LASTIV*2];
E 21
I 21
	extern quad catcher[SCB_LASTIV];
E 21
E 10
E 3

I 3
#ifdef lint
	br = 0; cvec = 0;
#endif
	vhp = &vba_hd[vban];
E 3
	/*
	 * Make the controllers accessible at physical address phys
	 * by mapping kernel ptes starting at pte.
	 */
D 2
	ioaccess(memmap,IOBASE,IOSIZE);
E 2
I 2
D 3
	ioaccess(memmap, IOBASE, (int)IOSIZE);
E 2
	iospace_mapped = 1;
#define	vbaddr(off)	(u_short *)((int)vumem + ((off) & 0x0fffff))
E 3
I 3
D 5
	vbaaccess(memmap, IOBASE, (int)IOSIZE);
E 5
I 5
D 10
	vbaccess(memmap, VBIOBASE, VBIOSIZE);
E 10
I 10
D 21
	vbaccess(memmap, (caddr_t)VBIOBASE, VBIOSIZE);
E 21
I 21
	vbaccess(memmap, (caddr_t)VBIOBASE, (int)VBIOSIZE);
E 21
E 10
I 8
	printf("vba%d at %x\n", vban, VBIOBASE);
E 8
E 5
	/*
	 * Setup scb device entries to point into catcher array.
	 */
	for (i = 0; i < SCB_LASTIV; i++)
D 21
		scb.scb_devint[i] = (int (*)())&catcher[i*2];
E 21
I 21
		scb.scb_devint[i] = (int (*)())((int)&catcher[i]);
E 21
	/*
	 * Set last free interrupt vector for devices with
	 * programmable interrupt vectors.  Use is to decrement
	 * this number and use result as interrupt vector.
	 */
	vhp->vh_lastiv = SCB_LASTIV;
I 8
	/*
	 * Grab some memory to record the address space we allocate,
	 * so we can be sure not to place two devices at the same address.
I 19
	 * Register I/O space is allocated in 256-byte sections,
	 * and memory I/O space is in 4Kb sections.  We record allocations
	 * in 256-byte sections.
E 19
	 *
	 * We could use just 1/8 of this (we only want a 1 bit flag) but
	 * we are going to give it back anyway, and that would make the
	 * code here bigger (which we can't give back), so ...
	 */
D 16
	valloc = zmemall(memall, ctob(VBIOSIZE));
E 16
I 16
D 19
	valloc = (caddr_t)malloc(ctob(VBIOSIZE), M_TEMP, M_NOWAIT);
E 19
I 19
#define	VSECT(a)	((a) / 0x100)
#define	VSIZE(s)	(((s) + 0xff) / 0x100)
#define	VALLOC(a)	(valloc[VSECT(vboff(a))])
#define	VMAPSIZE	VSIZE(ctob(VBIOSIZE))
D 21
	valloc = (caddr_t)malloc(VMAPSIZE, M_TEMP, M_NOWAIT);
E 21
I 21
	valloc = (caddr_t)malloc((u_long)(VMAPSIZE), M_TEMP, M_NOWAIT);
E 21
E 19
E 16
	if (valloc == (caddr_t)0)
		panic("no mem for vbafind");
I 16
D 19
	bzero(valloc, ctob(VBIOSIZE));
E 19
I 19
	bzero(valloc, VMAPSIZE);
E 19
E 16
E 8
E 3

D 2

E 2
	/*
	 * Check each VERSAbus mass storage controller.
	 * For each one which is potentially on this vba,
	 * see if it is really there, and if it is record it and
	 * then go looking for slaves.
	 */
I 3
D 8
#define	vbaddr(off)	(u_short *)((int)vumem + ((off) & 0x0fffff))
E 8
I 8
D 10
#define	vbaddr(off)	(u_short *)((int)vumem + vboff(off))
E 10
I 10
#define	vbaddr(off)	(u_short *)(vumem + vboff(off))
E 10
E 8
E 3
	for (um = vbminit; udp = um->um_driver; um++) {
D 2
		if (um->um_vbanum != numvba && um->um_vbanum != '?')
E 2
I 2
		if (um->um_vbanum != vban && um->um_vbanum != '?')
E 2
			continue;
I 3
		/*
		 * Use the particular address specified first,
		 * or if it is given as "0", if there is no device
		 * at that address, try all the standard addresses
		 * in the driver until we find it.
		 */
E 3
		addr = (long)um->um_addr;
I 3
	    for (ap = udp->ud_addr; addr || (addr = *ap++); addr = 0) {
D 8
#ifdef notdef
		if (vballoc[vbaoff(addr)])
			continue;
#endif
E 3
		reg = vbaddr(addr);
E 8
I 8
		if (VBIOMAPPED(addr)) {
D 19
			if (valloc[vboff(addr)])
E 19
I 19
			if (VALLOC(addr))
E 19
				continue;
			reg = vbaddr(addr);
		} else
			reg = (u_short *)addr;
E 8
D 3
		i = (*udp->ud_probe)(reg);
E 3
I 3
		um->um_hd = vhp;
		cvec = SCB_LASTIV, cold &= ~0x2;
		i = (*udp->ud_probe)(reg, um);
		cold |= 0x2;
E 3
		if (i == 0)
			continue;
D 2
		printf("%s%d at csr 0x%x\n",
		    udp->ud_mname, um->um_ctlr, addr);
E 2
I 2
D 3
		printf("%s%d at vba%d csr %x\n",
E 3
I 3
		printf("%s%d at vba%d csr %x ",
E 3
		    udp->ud_mname, um->um_ctlr, vban, addr);
I 3
		if (cvec < 0 && vhp->vh_lastiv == cvec) {
			printf("no space for vector(s)\n");
			continue;
		}
		if (cvec == SCB_LASTIV) {
			printf("didn't interrupt\n");
			continue;
		}
		printf("vec %x, ipl %x\n", cvec, br);
I 8
		csralloc(valloc, addr, i);
E 8
E 3
E 2
		um->um_alive = 1;
D 2
		um->um_vbanum = numvba;
E 2
I 2
		um->um_vbanum = vban;
E 2
		um->um_addr = (caddr_t)reg;
		udp->ud_minfo[um->um_ctlr] = um;
I 3
		for (ivec = um->um_intr; *ivec; ivec++)
D 4
			((long *)&scb)[cvec++] = *ivec;
E 4
I 4
			((long *)&scb)[cvec++] = (long)*ivec;
E 4
E 3
		for (ui = vbdinit; ui->ui_driver; ui++) {
			if (ui->ui_driver != udp || ui->ui_alive ||
			    ui->ui_ctlr != um->um_ctlr && ui->ui_ctlr != '?' ||
D 2
			    ui->ui_vbanum != numvba && ui->ui_vbanum != '?')
E 2
I 2
			    ui->ui_vbanum != vban && ui->ui_vbanum != '?')
E 2
				continue;
I 13
			octlr = ui->ui_ctlr, ui->ui_ctlr = um->um_ctlr;
E 13
			if ((*udp->ud_slave)(ui, reg)) {
				ui->ui_alive = 1;
				ui->ui_ctlr = um->um_ctlr;
D 2
				ui->ui_vbanum = numvba;
E 2
I 2
				ui->ui_vbanum = vban;
E 2
				ui->ui_addr = (caddr_t)reg;
D 3
				ui->ui_physaddr = (caddr_t)IOBASE + (addr&0x0fffff);
E 3
I 3
D 8
				ui->ui_physaddr =
D 5
				    (caddr_t)IOBASE + (addr&0x0fffff);
E 5
I 5
				    (caddr_t)VBIOBASE + (addr&0x0fffff);
E 8
I 8
				ui->ui_physaddr = (caddr_t)addr;
E 8
E 5
E 3
				if (ui->ui_dk && dkn < DK_NDRIVE)
					ui->ui_dk = dkn++;
				else
					ui->ui_dk = -1;
				ui->ui_mi = um;
I 3
				ui->ui_hd = vhp;
E 3
				/* ui_type comes from driver */
				udp->ud_dinfo[ui->ui_unit] = ui;
D 11
				printf("%s%d at %s%d slave %d\n",
E 11
I 11
D 12
				printf("    %s%d at %s%d slave %d",
E 12
I 12
				printf("%s%d at %s%d slave %d",
E 12
E 11
				    udp->ud_dname, ui->ui_unit,
				    udp->ud_mname, um->um_ctlr,
				    ui->ui_slave);
				(*udp->ud_attach)(ui);
I 11
				printf("\n");
E 11
D 13
			}
E 13
I 13
			} else
				ui->ui_ctlr = octlr;
E 13
		}
I 3
		break;
	    }
E 3
	}
	/*
	 * Now look for non-mass storage peripherals.
	 */
	for (ui = vbdinit; udp = ui->ui_driver; ui++) {
D 2
		if (ui->ui_vbanum != numvba && ui->ui_vbanum != '?' ||
E 2
I 2
		if (ui->ui_vbanum != vban && ui->ui_vbanum != '?' ||
E 2
		    ui->ui_alive || ui->ui_slave != -1)
			continue;
		addr = (long)ui->ui_addr;
I 3
	    for (ap = udp->ud_addr; addr || (addr = *ap++); addr = 0) {
E 3
D 8
		reg = vbaddr(addr);
E 8
I 8
		if (VBIOMAPPED(addr)) {
D 19
			if (valloc[vboff(addr)])
E 19
I 19
			if (VALLOC(addr))
E 19
				continue;
			reg = vbaddr(addr);
		} else
			reg = (u_short *)addr;
E 8
D 3
		if (badaddr((caddr_t)reg, 2))
			continue;
		i = (*udp->ud_probe)(reg);
E 3
I 3
		ui->ui_hd = vhp;
		cvec = SCB_LASTIV, cold &= ~0x2;
		i = (*udp->ud_probe)(reg, ui);
		cold |= 0x2;
E 3
		if (i == 0)
			continue;
D 2
		printf("%s%d at csr 0x%x\n",
		    ui->ui_driver->ud_dname, ui->ui_unit, addr);
E 2
I 2
D 3
		printf("%s%d at vba%d csr %x\n",
E 3
I 3
		printf("%s%d at vba%d csr %x ",
E 3
		    ui->ui_driver->ud_dname, ui->ui_unit, vban, addr);
I 3
D 8
		if (cvec < 0 && vhp->vh_lastiv == cvec) {
			printf("no space for vector(s)\n");
			continue;
		}
		if (cvec == SCB_LASTIV) {
			printf("didn't interrupt\n");
			continue;
		}
		printf("vec %x, ipl %x\n", cvec, br);
#ifdef notdef
		while (--i >= 0)
			vballoc[vbaoff(addr+i)] = 1;
#endif
		for (ivec = ui->ui_intr; *ivec; ivec++)
D 4
			((long *)&scb)[cvec++] = *ivec;
E 4
I 4
			((long *)&scb)[cvec++] = (long)*ivec;
E 8
I 8
		if (ui->ui_intr) {
			if (cvec < 0 && vhp->vh_lastiv == cvec) {
				printf("no space for vector(s)\n");
				continue;
			}
			if (cvec == SCB_LASTIV) {
				printf("didn't interrupt\n");
				continue;
			}
			printf("vec %x, ipl %x\n", cvec, br);
			for (ivec = ui->ui_intr; *ivec; ivec++)
				((long *)&scb)[cvec++] = (long)*ivec;
		} else
			printf("no interrupts\n");
		csralloc(valloc, addr, i);
E 8
E 4
E 3
E 2
		ui->ui_alive = 1;
D 2
		ui->ui_vbanum = numvba;
E 2
I 2
		ui->ui_vbanum = vban;
E 2
		ui->ui_addr = (caddr_t)reg;
D 5
		ui->ui_physaddr = (caddr_t)IOBASE + (addr&0x0fffff);
E 5
I 5
D 8
		ui->ui_physaddr = (caddr_t)VBIOBASE + (addr&0x0fffff);
E 8
I 8
		ui->ui_physaddr = (caddr_t)addr;
E 8
E 5
		ui->ui_dk = -1;
		/* ui_type comes from driver */
		udp->ud_dinfo[ui->ui_unit] = ui;
		(*udp->ud_attach)(ui);
I 3
		break;
	    }
I 8
	}
D 16
	wmemfree(valloc, ctob(VBIOSIZE));
E 16
I 16
	free(valloc, M_TEMP);
E 16
}

/*
 * Mark addresses starting at addr and continuing
 * size bytes as allocated in the map.
 * Warn if the new allocation overlaps a previous allocation.
 */
csralloc(valloc, addr, size)
D 10
	caddr_t valloc, addr;
E 10
I 10
	caddr_t valloc;
	long addr;
E 10
	register int size;
{
	register caddr_t p;
	int warned = 0;

	if (!VBIOMAPPED(addr))
		return;
D 19
	p = &valloc[vboff(addr+size)];
E 19
I 19
	size = VSIZE(size);
	p = &VALLOC(addr) + size;
E 19
	while (--size >= 0) {
		if (*--p && !warned) {
			printf(
	"WARNING: device registers overlap those for a previous device\n");
			warned = 1;
		}
		*p = 1;
E 8
E 3
	}
I 5
}

/*
 * Tahoe VERSAbus adapator support routines.
 */

caddr_t	vbcur = (caddr_t)&vbbase;
int	vbx = 0;
/*
 * Allocate page tables for mapping intermediate i/o buffers.
 * Called by device drivers during autoconfigure.
 */
vbmapalloc(npf, ppte, putl)
	int npf;
	struct pte **ppte;
	caddr_t *putl;
{

D 17
	if (vbcur + npf*NBPG >= (caddr_t)&vbend)
		panic("vbmapalloc");
E 17
I 17
	if (vbcur + npf*NBPG > (caddr_t)&vbend)
		return (0);
E 17
	*ppte = &VBmap[vbx];
	*putl = vbcur;
	vbx += npf;
	vbcur += npf*NBPG;
I 17
	return (1);
E 17
}

caddr_t	vbmcur = (caddr_t)&vmem1;
int	vbmx = 0;
/*
 * Allocate page tables and map VERSAbus i/o space.
 * Called by device drivers during autoconfigure.
 */
vbmemalloc(npf, addr, ppte, putl)
	int npf;
	caddr_t addr;
	struct pte **ppte;
	caddr_t *putl;
{

D 17
	if (vbmcur + npf*NBPG >= (caddr_t)&vmemend)
		panic("vbmemalloc");
E 17
I 17
	if (vbmcur + npf*NBPG > (caddr_t)&vmemend)
		return (0);
E 17
	*ppte = &VMEMmap1[vbmx];
	*putl = vbmcur;
	vbmx += npf;
	vbmcur += npf*NBPG;
	vbaccess(*ppte, addr, npf);		/* map i/o space */
I 17
	return (1);
E 17
E 5
}

D 3

D 2
#define	DMMIN	32
#define	DMMAX	1024
#define	DMTEXT	1024
#define	MAXDUMP	(10*2048)
E 2
I 2
#define	MAXDUMP	(8*1024)
E 3
E 2
/*
 * Configure swap space and related parameters.
 */
I 14
#ifndef SECSIZE
E 14
swapconf()
{
	register struct swdevt *swp;
	register int nblks;

D 3
	for (swp = swdevt; swp->sw_dev; swp++) {
		if (bdevsw[major(swp->sw_dev)].d_psize)
E 3
I 3
	for (swp = swdevt; swp->sw_dev; swp++)
		if (bdevsw[major(swp->sw_dev)].d_psize) {
E 3
			nblks =
			  (*bdevsw[major(swp->sw_dev)].d_psize)(swp->sw_dev);
D 3
		if (swp->sw_nblks == 0 || swp->sw_nblks > nblks)
			swp->sw_nblks = nblks;
	}
E 3
I 3
D 13
			if (swp->sw_nblks == 0 || swp->sw_nblks > nblks)
E 13
I 13
			if (nblks != -1 &&
			    (swp->sw_nblks == 0 || swp->sw_nblks > nblks))
E 13
				swp->sw_nblks = nblks;
		}
E 3
	if (dumplo == 0 && bdevsw[major(dumpdev)].d_psize)
D 3
		dumplo = (*bdevsw[major(dumpdev)].d_psize)(dumpdev) - MAXDUMP;
E 3
I 3
		dumplo = (*bdevsw[major(dumpdev)].d_psize)(dumpdev) - physmem;
E 3
	if (dumplo < 0)
		dumplo = 0;
I 6
}
I 14
#else SECSIZE
swapconf()
{
	register struct swdevt *swp;
	register int nblks;
	register int bsize;
	struct partinfo dpart;

	for (swp = swdevt; swp->sw_dev; swp++)
		if ((nblks = psize(swp->sw_dev, &swp->sw_blksize,
		    &swp->sw_bshift)) != -1 &&
		    (swp->sw_nblks == 0 || swp->sw_nblks > nblks))
			swp->sw_nblks = nblks;

	if (!cold)	/* In case called for addition of another drive */
		return;
	if (dumplo == 0) {
		nblks = psize(dumpdev, (int *)0, (int *)0);
		if (nblks == -1 || nblks < ctod(physmem))
			dumplo = 0;
		else
			dumplo = nblks - ctod(physmem);
	}
}

/*
 * Return size of disk partition in DEV_BSIZE units.
 * If needed, return sector size.
 */
psize(dev, psize, pshift)
	register dev_t dev;
	int *psize, *pshift;
{
	register int nblks, bsize, bshift;
	struct partinfo dpart;

	if ((*bdevsw[major(dev)].d_ioctl)(dev, DIOCGPART,
	    (caddr_t)&dpart, FREAD) == 0)
		bsize = dpart.disklab->d_secsize;
	else
		bsize = DEV_BSIZE;
	if (psize)
		*psize = bsize;
	bshift = 0;
	for (nblks = DEV_BSIZE / bsize; nblks > 1; nblks >>= 1)
		bshift++;
	if (pshift)
		*pshift = bshift;
	nblks = -1;
	if (bdevsw[major(dev)].d_psize) {
		nblks = (*bdevsw[major(dev)].d_psize)(dev);
		if (nblks != -1)
			nblks >>= bshift;
	}
	return (nblks);
}
#endif SECSIZE
E 14

#define	DOSWAP			/* change swdevt, argdev, and dumpdev too */
u_long	bootdev;		/* should be dev_t, but not until 32 bits */

static	char devname[][2] = {
	0,0,		/* 0 = ud */
	'd','k',	/* 1 = vd */
	0,0,		/* 2 = xp */
};

#define	PARTITIONMASK	0x7
#define	PARTITIONSHIFT	3

/*
 * Attempt to find the device from which we were booted.
 * If we can do so, and not instructed not to do so,
 * change rootdev to correspond to the load device.
 */
setroot()
{
D 18
	int  majdev, mindev, unit, part, adaptor;
E 18
I 18
	int  majdev, mindev, unit, part, controller, adaptor;
E 18
	dev_t temp, orootdev;
	struct swdevt *swp;

	if (boothowto & RB_DFLTROOT ||
	    (bootdev & B_MAGICMASK) != (u_long)B_DEVMAGIC)
		return;
D 18
	majdev = (bootdev >> B_TYPESHIFT) & B_TYPEMASK;
	if (majdev > sizeof(devname) / sizeof(devname[0]))
E 18
I 18
	majdev = B_TYPE(bootdev);
	if (majdev >= sizeof(devname) / sizeof(devname[0]))
E 18
		return;
D 18
	adaptor = (bootdev >> B_ADAPTORSHIFT) & B_ADAPTORMASK;
	part = (bootdev >> B_PARTITIONSHIFT) & B_PARTITIONMASK;
	unit = (bootdev >> B_UNITSHIFT) & B_UNITMASK;
E 18
I 18
	adaptor = B_ADAPTOR(bootdev);
	controller = B_CONTROLLER(bootdev);
	part = B_PARTITION(bootdev);
	unit = B_UNIT(bootdev);
E 18
	/*
	 * Search Versabus devices.
	 *
	 * WILL HAVE TO DISTINGUISH VME/VERSABUS SOMETIME
	 */
	{
		register struct vba_device *vbap;

		for (vbap = vbdinit; vbap->ui_driver; vbap++)
			if (vbap->ui_alive && vbap->ui_slave == unit &&
I 18
			   vbap->ui_ctlr == controller &&
E 18
			   vbap->ui_vbanum == adaptor &&
D 7
#ifdef notdef
E 7
			   vbap->ui_driver->ud_dname[0] == devname[majdev][0] &&
			   vbap->ui_driver->ud_dname[1] == devname[majdev][1])
D 7
#else
			   1)	/* can't match names 'cuz of driver bogosity */
#endif
E 7
				break;
		if (vbap->ui_driver == 0)
			return;
		mindev = vbap->ui_unit;
	}
	mindev = (mindev << PARTITIONSHIFT) + part;
	orootdev = rootdev;
	rootdev = makedev(majdev, mindev);
	/*
	 * If the original rootdev is the same as the one
	 * just calculated, don't need to adjust the swap configuration.
	 */
	if (rootdev == orootdev)
		return;
	printf("changing root device to %c%c%d%c\n",
		devname[majdev][0], devname[majdev][1],
		mindev >> PARTITIONSHIFT, part + 'a');
#ifdef DOSWAP
	mindev &= ~PARTITIONMASK;
	for (swp = swdevt; swp->sw_dev; swp++) {
		if (majdev == major(swp->sw_dev) &&
		    mindev == (minor(swp->sw_dev) & ~PARTITIONMASK)) {
			temp = swdevt[0].sw_dev;
			swdevt[0].sw_dev = swp->sw_dev;
			swp->sw_dev = temp;
			break;
		}
	}
	if (swp->sw_dev == 0)
		return;
	/*
	 * If argdev and dumpdev were the same as the old primary swap
	 * device, move them to the new primary swap device.
	 */
	if (temp == dumpdev)
		dumpdev = swdevt[0].sw_dev;
	if (temp == argdev)
		argdev = swdevt[0].sw_dev;
#endif
E 6
D 2
	if (dmmin == 0)
		dmmin = DMMIN;
	if (dmmax == 0)
		dmmax = DMMAX;
	if (dmtext == 0)
		dmtext = DMTEXT;
	if (dmtext > dmmax)
		dmtext = dmmax;
E 2
}
E 1
