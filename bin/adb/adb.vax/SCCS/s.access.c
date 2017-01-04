h43074
s 00003/00001/00205
d D 4.8 84/10/13 19:36:40 sam 8 7
c use definitions in <ptrace.h>
e
s 00003/00001/00203
d D 4.7 83/08/11 20:00:34 sam 7 6
c fix sccs keyword lines
e
s 00001/00001/00203
d D 4.6 82/06/27 15:53:57 wnj 6 5
c restore sccs keywords
e
s 00002/00002/00202
d D 4.5 82/06/27 15:53:09 wnj 5 4
c fix to do writes in memory properly
e
s 00001/00014/00203
d D 4.4 81/05/15 02:06:37 root 4 3
c clean out debugging prints
e
s 00171/00155/00046
d D 4.3 81/05/15 00:53:44 root 3 2
c new attempt
e
s 00071/00005/00130
d D 4.2 81/05/14 20:08:53 root 2 1
c non-working version
e
s 00135/00000/00000
d D 4.1 81/05/14 15:19:40 root 1 0
c date and time created 81/05/14 15:19:40 by root
e
u
U
t
T
I 7
#ifndef lint
static	char sccsid[] = "%W% %G%";
#endif
E 7
I 1
D 3
#
E 3
/*
I 3
 * Adb: access data in file/process address space.
E 3
 *
D 3
 *	UNIX debugger
 *
E 3
I 3
 * The routines in this file access referenced data using
 * the maps to access files, ptrace to access subprocesses,
 * or the system page tables when debugging the kernel,
 * to translate virtual to physical addresses.
E 3
 */
I 3
D 4
#define dprintf if (var[varchk('d')]) printf
E 4
E 3

I 2
D 3
#define dprintf if (0) printf

E 3
E 2
#include "defs.h"
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
D 6
static	char sccsid[] = "@(#)access.c 4.4 5/15/81";
E 6
I 6
D 7
static	char sccsid[] = "%Z% %I% %G%";
E 7
E 6
E 5

D 3
MSG		ODDADR;
MSG		BADDAT;
MSG		BADTXT;
E 3
I 3

E 3
MAP		txtmap;
MAP		datmap;
INT		wtflag;
STRING		errflg;
INT		errno;

INT		pid;

D 3
/* file handling and access routines */
E 3
I 3
/*
 * Primitives: put a value in a space, get a value from a space
 * and get a word or byte not returning if an error occurred.
 */
put(addr, space, value) 
    off_t addr; { (void) access(WT, addr, space, value); }
E 3

D 3
put(adr,space,value)
#ifndef EDDT
L_INT	adr;
{
	access(WT,adr,space,value);
}
#else
	L_INT *adr; {*adr=value;}
#endif
E 3
I 3
u_int
get(addr, space)
    off_t addr; { return (access(RD, addr, space, 0)); };
E 3

D 3
POS	get(adr, space)
#ifndef EDDT
L_INT		adr;
{
	return(access(RD,adr,space,0));
}
#else
	L_INT *adr; {return(*adr);}
#endif
E 3
I 3
u_int
chkget(addr, space)
    off_t addr; { u_int w = get(addr, space); chkerr(); return(w); }
E 3

D 3
POS	chkget(n, space)
L_INT		n;
E 3
I 3
u_int
bchkget(addr, space) 
    off_t addr; { return(chkget(addr, space) & LOBYTE); }

/*
 * Read/write according to mode at address addr in i/d space.
 * Value is quantity to be written, if write.
 *
 * This routine decides whether to get the data from the subprocess
 * address space with ptrace, or to get it from the files being
 * debugged.  
 *
 * When the kernel is being debugged with the -k flag we interpret
 * the system page tables for data space, mapping p0 and p1 addresses
 * relative to the ``current'' process (as specified by its p_addr in
 * <p) and mapping system space addresses through the system page tables.
 */
access(mode, addr, space, value)
	int mode, space, value;
	off_t addr;
E 3
{
D 3
#ifndef vax
	REG INT		w;
#else
	REG L_INT	w;
#endif
E 3
I 3
	int rd = mode == RD;
	int file, w;
E 3

D 3
	w = get(n, space);
	chkerr();
	return(w);
}
E 3
I 3
D 4
	dprintf("access(%X)\n", addr);
E 4
	if (space == NSP)
		return(0);
	if (pid) {
D 8
		int pmode = (space&DSP?(rd?RDUSER:WDUSER):(rd?RIUSER:WIUSER));
E 8
I 8
		int pmode = (space&DSP ?
		    (rd ? PT_READ_D : PT_WRITE_D) :
		    (rd ? PT_READ_I : PT_WRITE_I));
E 8
E 3

D 3
POS bchkget(n, space) 
L_INT	n;
{
	return(chkget(n, space) & LOBYTE);
E 3
I 3
		w = ptrace(pmode, pid, addr, value);
		if (errno)
			rwerr(space);
		return (w);
	}
	w = 0;
	if (mode==WT && wtflag==0)
		error("not in write mode");
D 4
	if (!chkmap(&addr, space)) {
		dprintf("chkmap failed\n");
E 4
I 4
	if (!chkmap(&addr, space))
E 4
		return (0);
D 4
	}
E 4
	file = (space&DSP) ? datmap.ufd : txtmap.ufd;
	if (kernel && space == DSP) {
D 4
		dprintf("calling vtophys(%X)... ", addr);
E 4
		addr = vtophys(addr);
		if (addr < 0)
			return (0);
D 4
		dprintf("got %X\n", addr);
E 4
	}
D 5
	if (physrw(file, addr, &w, rd) < 0)
E 5
I 5
	if (physrw(file, addr, rd ? &w : &value, rd) < 0)
E 5
		rwerr(space);
	return (w);
E 3
}

D 3
#ifndef EDDT
access(mode,adr,space,value)
D 2
L_INT	adr;
E 2
I 2
long	adr;
E 3
I 3
/*
 * When looking at kernel data space through /dev/mem or
 * with a core file, do virtual memory mapping.
 */
vtophys(addr)
	off_t addr;
E 3
E 2
{
D 3
	INT	pmode,rd,file;
	ADDR	w;
	rd = mode==RD;
E 3
I 3
	int oldaddr = addr;
	int v;
	struct pte pte;
E 3

D 3
	IF space == NSP THEN return(0); FI
E 3
I 3
	addr &= ~0xc0000000;
	v = btop(addr);
D 4
	dprintf("addr %X v %X\n", addr, v);
E 4
	switch (oldaddr&0xc0000000) {
E 3

D 3
	IF pid		/* tracing on? */
	THEN
#ifndef vax
		IF adr&01 ANDF !rd THEN error(ODDADR); FI
#endif
	     pmode = (space&DSP?(rd?RDUSER:WDUSER):(rd?RIUSER:WIUSER));
	     w = ptrace(pmode, pid, adr, value);
#ifndef vax
	     IF adr&01
	     THEN w1 = ptrace(pmode, pid, shorten(adr+1), value);
		  w = (w>>8)&LOBYTE | (w1<<8);
	     FI
#endif
	     IF errno
	     THEN errflg = (space&DSP ? BADDAT : BADTXT);
	     FI
	     return(w);
	FI
	w = 0;
	IF mode==WT ANDF wtflag==0
	THEN	error("not in write mode");
	FI
	IF !chkmap(&adr,space)
	THEN return(0);
	FI
	file=(space&DSP?datmap.ufd:txtmap.ufd);
D 2
	IF longseek(file,adr)==0 ORF
	   (rd ? read(file,&w,sizeof(w)) : write(file,&value,sizeof(w))) < 1
	THEN	errflg=(space&DSP?BADDAT:BADTXT);
E 2
I 2
	IF kernel && space == DSP THEN
	    int oadr = adr;
	    int v;
	    adr &= ~0x80000000;
	    IF oadr&0x80000000 THEN		/* system space */
		v = btop(adr);
		dprintf("system addr %X, v %X\n", adr, v);
		IF v >= slr THEN errflg="bad system space addr"; return (0); FI
		adr = vtoa(file, adr);
		IF adr == -1 THEN
		    errflg="sys page table page not valid"; return (0); FI
	    ELIF adr&0x40000000 THEN		/* p1 space */
		v = btop(adr&~0x40000000);
		dprintf("p1 addr %X, v %X, p1br %X p1lr %X\n", adr, v,
		    pcb.pcb_p1br, pcb.pcb_p1lr);
		IF v < pcb.pcb_p1lr THEN
		    errflg="bad p1 space addr"; return (0); FI
		adr = vtoa(file, pcb.pcb_p1br+v);
		IF adr == -1 THEN
		    errflg="p1 page table page not valid"; return (0); FI
		goto get;
	    ELSE				/* p0 space */
		dprintf("p0 addr %X, v %X, p0br %X p0lr %X\n", adr,
		   v, pcb.pcb_p0br, pcb.pcb_p0lr);
		IF v >= pcb.pcb_p0lr THEN
		    errflg="bad p0 space addr"; return (0); FI
		adr = vtoa(file, pcb.pcb_p0br+v);
		IF adr == -1 THEN
		    errflg="p0 page table page not valid"; return (0); FI
get:
		dprintf("addr for pt page %X\n", adr);
		IF physrw(file, adr, &adr, 1) < 0 THEN
		    errflg = "page tables botched"; return (0); FI
		dprintf("user pte value %X\n", adr);
		IF (adr & PG_V) == 0 &&
		    ((adr & PG_FOD) || (adr & PG_PFNUM) == 0) THEN
		    errflg = "user page not resident"; return (0);
		FI
		adr = ((adr & 0xfffff) << 9) | (oadr & 0x1ff);
	    FI
E 2
	FI
I 2
	IF physrw(file, adr, &w, rd) < 0 THEN
	    errflg=(space&DSP?BADDAT:BADTXT);
	FI
E 2
	return(w);
E 3
I 3
	case 0xc0000000:
	case 0x80000000:
		/*
		 * In system space get system pte.  If
		 * valid or reclaimable then physical address
		 * is combination of its page number and the page
		 * offset of the original address.
		 */
		if (v >= slr)
			goto oor;
		addr = ((long)(sbr+v)) &~ 0x80000000;
		goto simple;

	case 0x40000000:
		/*
		 * In p1 space must not be in shadow region.
		 */
		if (v < pcb.pcb_p1lr)
			goto oor;
		addr = pcb.pcb_p1br+v;
		break;

	case 0x00000000:
		/*
		 * In p0 space must not be off end of region.
		 */
		if (v >= pcb.pcb_p0lr)
			goto oor;
		addr = pcb.pcb_p0br+v;
		break;
	oor:
D 4
		dprintf("out of range\n");
E 4
		errflg = "address out of segment";
		return (-1);
	}
	/*
	 * For p0/p1 address, user-level page table should
	 * be in kernel vm.  Do second-level indirect by recursing.
	 */
	if ((addr & 0x80000000) == 0) {
		errflg = "bad p0br or p1br in pcb";
D 4
		dprintf("bad p0/p1br\n");
E 4
		return (-1);
	}
D 4
	dprintf("calling vtophys recursively(%X)\n", addr);
E 4
	addr = vtophys(addr);
D 4
	dprintf("result %X\n", addr);
E 4
simple:
	/*
	 * Addr is now address of the pte of the page we
	 * are interested in; get the pte and paste up the
	 * physical address.
	 */
	if (physrw(fcor, addr, (int *)&pte, 1) < 0) {
		errflg = "page table botch";
		return (-1);
	}
	/* SHOULD CHECK NOT I/O ADDRESS; NEED CPU TYPE! */
	if (pte.pg_v == 0 && (pte.pg_fod || pte.pg_pfnum == 0)) {
		errflg = "page not valid/reclaimable";
		return (-1);
	}
	return (ptob(pte.pg_pfnum) + (oldaddr & PGOFSET));
E 3
D 2

E 2
}
D 3
#endif
E 3

I 2
D 3
physrw(file, adr, aw, rd)
int *aw;
E 3
I 3
rwerr(space)
	int space;
E 3
{

D 3
	dprintf("physrw(%X) %s to %X\n", adr, rd ? "read" : "write", aw);
	IF longseek(file,adr)==0 ORF
	   (rd ? read(file,aw,sizeof(int)) : write(file,aw,sizeof(int))) < 1
	THEN	 return (-1);
	FI
	return (0);
E 3
I 3
	if (space & DSP)
		errflg = "data address not found";
	else
		errflg = "text address not found";
E 3
}

D 3
vtoa(file, va)
unsigned long va;
E 3
I 3
physrw(file, addr, aw, rd)
	off_t addr;
	int *aw, rd;
E 3
{
D 3
	struct pte pte;
E 3

D 3
	physrw(file, ((long)(sbr + btop(va&0x7fffffff)))&~0x80000000, &pte, 1);
	dprintf("vtoa got pte %X\n", pte);
	if (pte.pg_v || (pte.pg_fod == 0 && pte.pg_pfnum))
		return (ptob(pte.pg_pfnum) + (va & PGOFSET));
	errflg = "page not resident";
	return (-1);
E 3
I 3
D 4
	dprintf("physrw(%X)... ", addr);
E 4
	if (longseek(file,addr)==0 ||
	    (rd ? read(file,aw,sizeof(int)) : write(file,aw,sizeof(int))) < 1)
		return (-1);
D 4
	dprintf("got %X\n", *aw);
E 4
	return (0);
E 3
}
D 3
	
E 2
chkmap(adr,space)
	REG L_INT	*adr;
E 3
I 3

chkmap(addr,space)
	REG L_INT	*addr;
E 3
	REG INT		space;
{
	REG MAPPTR amap;
	amap=((space&DSP?&datmap:&txtmap));
D 3
	IF space&STAR ORF !within(*adr,amap->b1,amap->e1)
	THEN IF within(*adr,amap->b2,amap->e2)
	     THEN *adr += (amap->f2)-(amap->b2);
	     ELSE errflg=(space&DSP?BADDAT:BADTXT); return(0);
E 3
I 3
	IF space&STAR ORF !within(*addr,amap->b1,amap->e1)
	THEN IF within(*addr,amap->b2,amap->e2)
	     THEN *addr += (amap->f2)-(amap->b2);
	     ELSE rwerr(space); return(0);
E 3
	     FI
D 3
	ELSE *adr += (amap->f1)-(amap->b1);
E 3
I 3
	ELSE *addr += (amap->f1)-(amap->b1);
E 3
	FI
	return(1);
}

D 3
within(adr,lbd,ubd)
POS	adr, lbd, ubd;
{
	return(adr>=lbd && adr<ubd);
}
E 3
I 3
within(addr,lbd,ubd)
    u_int addr, lbd, ubd; { return(addr>=lbd && addr<ubd); }
E 3

longseek(f, a)
D 3
L_INT a;
{
	return(lseek(f,a,0) != -1);
}
E 3
I 3
    off_t a; { return(lseek(f, a, 0) != -1); }
E 3
E 1
