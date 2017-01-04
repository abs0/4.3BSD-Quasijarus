h38054
s 00023/00009/00219
d D 5.3 88/01/12 00:22:38 donn 11 10
c merge in latest Linton version
e
s 00006/00150/00222
d D 5.2 86/02/23 16:19:44 sam 10 9
c move machine dependent portions to machine file
e
s 00008/00002/00364
d D 5.1 85/05/31 11:25:39 dist 9 8
c Add copyright
e
s 00271/00047/00095
d D 1.7 85/03/01 20:20:49 linton 8 7
c update to version 3.0
e
s 00000/00011/00142
d D 1.6 84/08/12 00:10:07 sam 7 6
c checked in for karels; u.u_exdata no longer exists
e
s 00001/00003/00152
d D 1.5 84/06/23 11:39:55 sam 6 4
i 5
c merge linton branch delta trail
e
s 00008/00004/00147
d D 1.4.1.1 84/06/23 10:45:22 sam 5 4
c branch delta of linton changes from net.sources
e
s 00001/00001/00150
d D 1.4 83/01/25 17:05:20 linton 4 3
c fixed fclose(coredump) which should have been fclose(corefile)
e
s 00003/00003/00148
d D 1.3 82/12/18 23:06:54 linton 3 2
c changed several include <sys/...> to <machine/...>
e
s 00001/00001/00150
d D 1.2 82/12/15 04:19:48 linton 2 1
c fixed @(#) stuff
e
s 00151/00000/00000
d D 1.1 82/12/15 04:07:19 linton 1 0
c date and time created 82/12/15 04:07:19 by linton
e
u
U
f b 
t
T
I 1
D 9
/* Copyright (c) 1982 Regents of the University of California */
E 9
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 9

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 5
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
D 6
static char sccsid[] = "@(#)coredump.c 1.4 1/25/83";
E 5
E 2

I 5
static char rcsid[] = "$Header: coredump.c,v 1.3 84/03/27 10:20:10 linton Exp $";
E 6
I 6
D 9
static	char sccsid[] = "%W% (Berkeley) %G%";
E 9
I 9
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 6

I 8
D 11
static char rcsid[] = "$Header: coredump.c,v 1.5 84/12/26 10:38:56 linton Exp $";
E 11
I 11
static char rcsid[] = "$Header: coredump.c,v 1.4 87/04/15 03:25:22 donn Exp $";
E 11

E 8
E 5
/*
 * Deal with the core dump anachronism.
D 5
 *
 * If I understood this code, I'd try to make it readable.
E 5
 */

#include "defs.h"
#include "coredump.h"
#include "machine.h"
#include "object.h"
#include "main.h"
D 10
#include <sys/param.h>
#include <sys/dir.h>
D 3
#include <sys/psl.h>
#include <sys/pte.h>
E 3
I 3
#include <machine/psl.h>
#include <machine/pte.h>
E 3
#include <sys/user.h>
#include <sys/vm.h>
D 3
#include <sys/reg.h>
E 3
I 3
#include <machine/reg.h>
E 10
E 3
#include <a.out.h>

#ifndef public
#define coredump_readin(m, r, s) coredump_xreadin(&(m), r, &(s))

#include "machine.h"
#endif

D 10
#define MAXSTKADDR (0x80000000 - ctob(UPAGES))	/* highest stack address */

E 10
typedef struct {
    Address begin;
    Address end;
    Address seekaddr;
} Map;

private Map datamap, stkmap;
private File objfile;
private struct exec hdr;

D 10
/*
D 8
 * Read the user area information from the core dump.
E 8
I 8
 * Special variables for debugging the kernel.
E 8
 */

D 8
public coredump_xreadin(mask, reg, signo)
int *mask;
Word reg[];
int *signo;
E 8
I 8
private integer masterpcbb;
private integer slr;
private struct pte *sbr;
private struct pcb pcb;

private getpcb ()
E 8
{
D 8
    register struct user *up;
    register Word *savreg;
    union {
	struct user u;
	char dummy[ctob(UPAGES)];
    } ustruct;
E 8
I 8
    fseek(corefile, masterpcbb & ~0x80000000, 0);
    get(corefile, pcb);
    pcb.pcb_p0lr &= ~AST_CLR;
    printf("p0br %lx p0lr %lx p1br %lx p1lr %lx\n",
	pcb.pcb_p0br, pcb.pcb_p0lr, pcb.pcb_p1br, pcb.pcb_p1lr
    );
    setreg(0, pcb.pcb_r0);
    setreg(1, pcb.pcb_r1);
    setreg(2, pcb.pcb_r2);
    setreg(3, pcb.pcb_r3);
    setreg(4, pcb.pcb_r4);
    setreg(5, pcb.pcb_r5);
    setreg(6, pcb.pcb_r6);
    setreg(7, pcb.pcb_r7);
    setreg(8, pcb.pcb_r8);
    setreg(9, pcb.pcb_r9);
    setreg(10, pcb.pcb_r10);
    setreg(11, pcb.pcb_r11);
    setreg(ARGP, pcb.pcb_ap);
    setreg(FRP, pcb.pcb_fp);
    setreg(STKP, pcb.pcb_ksp);
    setreg(PROGCTR, pcb.pcb_pc);
}
E 8

E 10
D 8
    objfile = fopen(objname, "r");
    if (objfile == nil) {
	fatal("can't read \"%s\"", objname);
E 8
I 8
public coredump_getkerinfo ()
{
    Symbol s;

    s = lookup(identname("Sysmap", true));
    if (s == nil) {
	panic("can't find 'Sysmap'");
E 8
    }
D 8
    get(objfile, hdr);
    up = &(ustruct.u);
    fread(up, ctob(UPAGES), 1, corefile);
    savreg = (Word *) &(ustruct.dummy[ctob(UPAGES)]);
    *mask = savreg[PS];
E 8
I 8
    sbr = (struct pte *) (s->symvalue.offset);
    s = lookup(identname("Syssize", true));
    if (s == nil) {
	panic("can't find 'Syssize'");
    }
    slr = (integer) (s->symvalue.offset);
    printf("sbr %lx slr %lx\n", sbr, slr);
    s = lookup(identname("masterpaddr", true));
    if (s == nil) {
	panic("can't find 'masterpaddr'");
    }
D 10
    fseek(
	corefile,
	datamap.seekaddr + s->symvalue.offset&0x7fffffff - datamap.begin,
	0
    );
E 10
I 10
D 11
    fseek(corefile,
	datamap.seekaddr + physaddr(s->symvalue.offset) - datamap.begin, 0);
E 11
I 11
    fseek(
	corefile,
	datamap.seekaddr + s->symvalue.offset&0x7fffffff - datamap.begin,
	0
    );
E 11
E 10
    get(corefile, masterpcbb);
D 10
    masterpcbb = (masterpcbb&PG_PFNUM)*512;
E 10
I 10
    masterpcbb = (masterpcbb&PG_PFNUM)*NBPG;
E 10
    getpcb();
}

D 10
private copyregs (savreg, reg)
Word savreg[], reg[];
{
E 8
    reg[0] = savreg[R0];
    reg[1] = savreg[R1];
    reg[2] = savreg[R2];
    reg[3] = savreg[R3];
    reg[4] = savreg[R4];
    reg[5] = savreg[R5];
    reg[6] = savreg[R6];
    reg[7] = savreg[R7];
    reg[8] = savreg[R8];
    reg[9] = savreg[R9];
    reg[10] = savreg[R10];
    reg[11] = savreg[R11];
    reg[ARGP] = savreg[AP];
    reg[FRP] = savreg[FP];
    reg[STKP] = savreg[SP];
    reg[PROGCTR] = savreg[PC];
D 8
    *signo = up->u_arg[0];
    datamap.seekaddr = ctob(UPAGES);
    stkmap.begin = MAXSTKADDR - ctob(up->u_ssize);
    stkmap.end = MAXSTKADDR;
    stkmap.seekaddr = datamap.seekaddr + ctob(up->u_dsize);
    switch (hdr.a_magic) {
	case OMAGIC:
	    datamap.begin = 0;
	    datamap.end = ctob(up->u_tsize) + ctob(up->u_dsize);
	    break;
E 8
I 8
}
E 8

E 10
D 8
	case NMAGIC:
	case ZMAGIC:
	    datamap.begin = (Address) ptob(btop(ctob(up->u_tsize) - 1) + 1);
	    datamap.end = datamap.begin + ctob(up->u_dsize);
	    break;
E 8
I 8
/*
 * Read the user area information from the core dump.
 */
E 8

D 8
	default:
	    fatal("bad magic number 0x%x", hdr.a_magic);
E 8
I 8
public coredump_xreadin(mask, reg, signo)
int *mask;
Word reg[];
D 10
int *signo;
E 10
I 10
short *signo;
E 10
{
    register struct user *up;
    register Word *savreg;
    union {
	struct user u;
	char dummy[ctob(UPAGES)];
    } ustruct;
    Symbol s;

    objfile = fopen(objname, "r");
    if (objfile == nil) {
	fatal("can't read \"%s\"", objname);
E 8
    }
I 8
    get(objfile, hdr);
    if (vaddrs) {
	datamap.begin = 0;
	datamap.end = 0xffffffff;
	stkmap.begin = 0xffffffff;
	stkmap.end = 0xffffffff;
    } else {
	up = &(ustruct.u);
	fread(up, ctob(UPAGES), 1, corefile);
D 11
	savreg = (Word *) &(ustruct.dummy[ctob(UPAGES)]);
	*mask = savreg[PS];
E 11
I 11
#	if vax || tahoe
	    savreg = (Word *) &(ustruct.dummy[ctob(UPAGES)]);
#	else ifdef mc68000
	    savreg = (Word *) (
		&ustruct.dummy[ctob(UPAGES) - 10] - (NREG * sizeof(Word))
	    );
#	endif
#       ifdef IRIS
	    *mask = savreg[RPS];
#       else
	    *mask = savreg[PS];
#       endif
E 11
	copyregs(savreg, reg);
	*signo = up->u_arg[0];
	datamap.seekaddr = ctob(UPAGES);
D 10
	stkmap.begin = MAXSTKADDR - ctob(up->u_ssize);
	stkmap.end = MAXSTKADDR;
E 10
I 10
	stkmap.begin = USRSTACK - ctob(up->u_ssize);
	stkmap.end = USRSTACK;
E 10
	stkmap.seekaddr = datamap.seekaddr + ctob(up->u_dsize);
	switch (hdr.a_magic) {
	    case OMAGIC:
D 11
		datamap.begin = 0;
		datamap.end = ctob(up->u_tsize) + ctob(up->u_dsize);
E 11
I 11
		datamap.begin = CODESTART;
		datamap.end = CODESTART + ctob(up->u_tsize) + ctob(up->u_dsize);
E 11
		break;

	    case NMAGIC:
	    case ZMAGIC:
D 11
		datamap.begin = (Address) ptob(btop(ctob(up->u_tsize) - 1) + 1);
E 11
I 11
		datamap.begin = (Address)
		    ptob(btop(ctob(up->u_tsize) - 1) + 1) + CODESTART;
E 11
		datamap.end = datamap.begin + ctob(up->u_dsize);
		break;

	    default:
		fatal("bad magic number 0x%x", hdr.a_magic);
	}
#ifdef UXMAG
	/*
	 * Core dump not from this object file?
	 */
	if (hdr.a_magic != 0 and up->u_exdata.ux_mag  != 0 and
	  hdr.a_magic != up->u_exdata.ux_mag) {
	    warning("core dump ignored");
	    coredump = false;
	    fclose(corefile);
	    fclose(objfile);
	    start(nil, nil, nil);
	}
#endif
    }
E 8
D 7
    /*
     * Core dump not from this object file?
     */
    if (hdr.a_magic != 0 and up->u_exdata.ux_mag  != 0 and
      hdr.a_magic != up->u_exdata.ux_mag) {
	warning("core dump ignored");
	coredump = false;
D 4
	fclose(coredump);
E 4
I 4
	fclose(corefile);
E 4
	fclose(objfile);
	start(nil, nil, nil);
    }
E 7
}

public coredump_close()
{
    fclose(objfile);
}

public coredump_readtext(buff, addr, nbytes)
char *buff;
Address addr;
int nbytes;
{
D 8
    if (hdr.a_magic == OMAGIC) {
E 8
I 8
    if (hdr.a_magic == OMAGIC or vaddrs) {
E 8
	coredump_readdata(buff, addr, nbytes);
    } else {
D 11
	fseek(objfile, N_TXTOFF(hdr) + addr, 0);
E 11
I 11
	fseek(objfile, N_TXTOFF(hdr) + addr - CODESTART, 0);
E 11
	fread(buff, nbytes, sizeof(Byte), objfile);
    }
D 10
}

I 8
/*
 * Map a virtual address to a physical address.
 */

private Address vmap (addr)
Address addr;
{
    Address r;
    integer v, n;
    struct pte pte;

    r = addr & ~0xc0000000;
    v = btop(r);
    switch (addr&0xc0000000) {
	case 0xc0000000:
	case 0x80000000:
	    /*
	     * In system space, so get system pte.
	     * If it is valid or reclaimable then the physical address
	     * is the combination of its page number and the page offset
	     * of the original address.
	     */
	    if (v >= slr) {
		error("address %x out of segment", addr);
	    }
	    r = ((long) (sbr + v)) & ~0x80000000;
	    goto simple;

	case 0x40000000:
	    /*
	     * In p1 space, must not be in shadow region.
	     */
	    if (v < pcb.pcb_p1lr) {
		error("address %x out of segment", addr);
	    }
	    r = (Address) (pcb.pcb_p1br + v);
	    break;

	case 0x00000000:
	    /*
	     * In p0 space, must not be off end of region.
	     */
	    if (v >= pcb.pcb_p0lr) {
		error("address %x out of segment", addr);
	    }
	    r = (Address) (pcb.pcb_p0br + v);
	    break;

	default:
	    /* do nothing */
	    break;
    }
    /*
     * For p0/p1 address, user-level page table should be in
     * kernel virtual memory.  Do second-level indirect by recursing.
     */
    if ((r & 0x80000000) == 0) {
	error("bad p0br or p1br in pcb");
    }
    r = vmap(r);
simple:
    /*
     * "r" is now the address of the pte of the page
     * we are interested in; get the pte and paste up the physical address.
     */
    fseek(corefile, r, 0);
    n = fread(&pte, sizeof(pte), 1, corefile);
    if (n != 1) {
	error("page table botch (fread at %x returns %d)", r, n);
    }
    if (pte.pg_v == 0 and (pte.pg_fod != 0 or pte.pg_pfnum == 0)) {
	error("page no valid or reclamable");
    }
    return (addr&PGOFSET) + ((Address) ptob(pte.pg_pfnum));
E 10
}

E 8
public coredump_readdata(buff, addr, nbytes)
char *buff;
Address addr;
int nbytes;
{
D 8
    if (addr < datamap.begin) {
E 8
I 8
    Address a;

    a = addr;
    if (a < datamap.begin) {
E 8
D 5
	error("data address 0x%x too low (lb = 0x%x)", addr, datamap.begin);
E 5
I 5
	if (hdr.a_magic == OMAGIC) {
D 8
	    error("data address 0x%x too low (lb = 0x%x)", addr, datamap.begin);
E 8
I 8
	    error("[data address 0x%x too low (lb = 0x%x)]", a, datamap.begin);
E 8
	} else {
D 8
	    coredump_readtext(buff, addr, nbytes);
E 8
I 8
	    coredump_readtext(buff, a, nbytes);
E 8
	}
E 5
D 8
    } else if (addr > stkmap.end) {
	error("data address 0x%x too high (ub = 0x%x)", addr, stkmap.end);
    } else if (addr < stkmap.begin) {
	fseek(corefile, datamap.seekaddr + addr - datamap.begin, 0);
	fread(buff, nbytes, sizeof(Byte), corefile);
E 8
I 8
    } else if (a > stkmap.end) {
	error("data address 0x%x too high (ub = 0x%x)", a, stkmap.end);
E 8
    } else {
D 8
	fseek(corefile, stkmap.seekaddr + addr - stkmap.begin, 0);
	fread(buff, nbytes, sizeof(Byte), corefile);
E 8
I 8
	if (vaddrs) {
	    vreadfromfile(corefile, a, buff, nbytes);
	} else {
	    readfromfile(corefile, a, buff, nbytes);
	}
E 8
    }
I 8
}

/*
 * Read a block of data from a memory image, mapping virtual addresses.
 * Have to watch out for page boundaries.
 */

private vreadfromfile (corefile, v, buff, nbytes)
File corefile;
Address v;
char *buff;
integer nbytes;
{
    Address a;
    integer i, remainder, pagesize;
    char *bufp;

    a = v;
    pagesize = (integer) ptob(1);
    remainder = pagesize - (a mod pagesize);
    if (remainder >= nbytes) {
	readfromfile(corefile, vmap(a), buff, nbytes);
    } else {
	readfromfile(corefile, vmap(a), buff, remainder);
	a += remainder;
	i = nbytes - remainder;
	bufp = buff + remainder;
	while (i > pagesize) {
	    readfromfile(corefile, vmap(a), bufp, pagesize);
	    a += pagesize;
	    bufp += pagesize;
	    i -= pagesize;
	}
	readfromfile(corefile, vmap(a), bufp, i);
    }
}

private readfromfile (f, a, buff, nbytes)
File f;
Address a;
char *buff;
integer nbytes;
{
    integer fileaddr;

    if (a < stkmap.begin) {
	fileaddr = datamap.seekaddr + a - datamap.begin;
    } else {
	fileaddr = stkmap.seekaddr + a - stkmap.begin;
    }
    fseek(f, fileaddr, 0);
    fread(buff, nbytes, sizeof(Byte), f);
E 8
}
E 1
