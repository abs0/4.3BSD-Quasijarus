h60247
s 00001/00001/00342
d D 4.11 87/12/21 12:24:59 bostic 12 11
c make ANSI C compatible
e
s 00007/00007/00336
d D 4.10 85/05/09 22:50:09 sam 11 9
c fix panicstr printing; use KVTOPH instead of constants
e
s 00007/00007/00336
d R 4.10 85/05/09 22:47:48 sam 10 9
c fix panicstr printing; macro-ize some things that should be
e
s 00002/00002/00341
d D 4.9 85/04/26 17:15:36 mckusick 9 8
c use %x not %X
e
s 00152/00004/00191
d D 4.8 84/08/05 17:19:15 sam 8 7
c locate stack frame when debugging crash dumps
e
s 00000/00003/00195
d D 4.7 84/07/25 17:54:23 karels 7 6
c u.u_exdata is no more
e
s 00001/00001/00197
d D 4.6 82/10/28 14:51:05 rrh 6 5
c Include <sys/stat.h> instead of <stat.h>. Tracks change in an uncontrolled branch
e
s 00004/00003/00194
d D 4.5 82/04/01 06:36:33 root 5 4
c bug fixes to -w, output overflow, kernel debugging
e
s 00003/00007/00194
d D 4.4 81/05/15 02:05:05 root 4 3
c works, still with prings
e
s 00002/00003/00199
d D 4.3 81/05/15 00:54:03 root 3 2
c new attempt
e
s 00026/00002/00176
d D 4.2 81/05/14 20:09:14 root 2 1
c non-working version
e
s 00178/00000/00000
d D 4.1 81/05/14 15:19:58 root 1 0
c date and time created 81/05/14 15:19:58 by root
e
u
U
t
T
I 1
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
D 8
static	char sccsid[] = "%W% %E%";
E 8
I 8
static	char sccsid[] = "%W% (Berkeley) %E%";
E 8
E 5
/*
 * adb - routines to read a.out+core at startup
 */
#include "defs.h"
I 8
#include <frame.h>
#include <ctype.h>
E 8
D 6
#include <stat.h>
E 6
I 6
#include <sys/stat.h>
I 8
#include <sys/file.h>
#include <vax/rpb.h>
E 8
E 6

off_t	datbas;			/* offset of the base of the data segment */
off_t	stksiz;			/* stack size in the core image */
INT	sigcode;	/* belongs in head.h */

char	*symfil	= "a.out";
char	*corfil	= "core";

setsym()
{
	off_t loc;
	struct exec hdr;
	register struct nlist *sp;
	int ssiz;
	char *strtab;

	fsym = getfile(symfil, 1);
	txtmap.ufd = fsym;
	if (read(fsym, (char *)&hdr, sizeof hdr) != sizeof hdr ||
	    N_BADMAG(hdr)) {
		txtmap.e1 = MAXFILE;
		return;
	}
	filhdr = hdr;
	loc = filhdr.a_text+filhdr.a_data;
	txtmap.f1 = txtmap.f2 = N_TXTOFF(filhdr);
	txtmap.b1 = 0;
	switch (filhdr.a_magic) {

	case OMAGIC:
		txtmap.b1 = txtmap.e1 = 0;
		txtmap.b2 = datbas = 0;
		txtmap.e2 = loc;
		break;

	case ZMAGIC:
	case NMAGIC:
		txtmap.e1 = filhdr.a_text;
		txtmap.b2 = datbas = round(filhdr.a_text, PAGSIZ);
		txtmap.e2 = datbas + filhdr.a_data;
		txtmap.f2 += txtmap.e1;
	}
	loc = N_SYMOFF(filhdr);
	symtab = (struct nlist *) malloc(filhdr.a_syms);
	esymtab = &symtab[filhdr.a_syms / sizeof (struct nlist)];
	if (symtab == NULL)
		goto nospac;
D 8
	lseek(fsym, loc, 0);
E 8
I 8
	lseek(fsym, loc, L_SET);
E 8
	if (filhdr.a_syms == 0)
		goto nosymt;
	/* SHOULD SQUISH OUT STABS HERE!!! */
	if (read(fsym, symtab, filhdr.a_syms) != filhdr.a_syms)
		goto readerr;
	if (read(fsym, &ssiz, sizeof (ssiz)) != sizeof (ssiz))
		goto oldfmt;
	strtab = (char *) malloc(ssiz);
	if (strtab == 0)
		goto nospac;
	*(int *)strtab = ssiz;
	ssiz -= sizeof (ssiz);
	if (read(fsym, strtab + sizeof (ssiz), ssiz) != ssiz)
		goto readerr;
	for (sp = symtab; sp < esymtab; sp++)
D 12
		if (sp->n_strx)
E 12
I 12
		if (sp->n_un.n_strx)
E 12
			/* SHOULD PERFORM RANGE CHECK HERE */
			sp->n_un.n_name = strtab + sp->n_un.n_strx;
nosymt:
	if (INKERNEL(filhdr.a_entry)) {
		txtmap.b1 += KERNOFF;
		txtmap.e1 += KERNOFF;
		txtmap.b2 += KERNOFF;
		txtmap.e2 += KERNOFF;
	}
	return;
readerr:
	printf("Error reading symbol|string table\n");
	exit(1);
nospac:
	printf("Not enough space for symbol|string table\n");
	exit(1);
oldfmt:
	printf("Old format a.out - no string table\n");
	exit(1);
}

setcor()
{

	fcor = datmap.ufd = getfile(corfil,2);
D 5
	if (fcor != -1 && INKERNEL(filhdr.a_entry)) {
E 5
I 5
	if (kernel && fcor != -1 && INKERNEL(filhdr.a_entry)) {
E 5
		struct stat stb;

I 4
		kcore = 1;
E 4
I 2
D 3
		kernel = 1;
E 3
E 2
		fstat(fcor, &stb);
I 2
D 4
		if (stb.st_mode & S_IFREG)
			kcore = 1;
E 4
D 3
		/* this is phoney baloney... it is boogered in access.c */
E 3
E 2
		datmap.b1 = 0;
		datmap.e1 = -1;
D 2
		if ((stb.st_mode&S_IFMT) == S_IFREG)
			datmap.b1 = 0x80000000;
E 2
I 2
D 3
		/* end phoney baloney */
E 3
I 3
		if (kernel == 0 && (stb.st_mode & S_IFREG))
			datmap.b1 = 0x80000000;
E 3
		lookup("_Sysmap");
		sbr = cursym->n_value;
		lookup("_Syssize");
		slr = cursym->n_value;
D 9
		printf("sbr %X slr %X\n", sbr, slr);
E 9
I 9
		printf("sbr %x slr %x\n", sbr, slr);
E 9
D 5
		lookup("_masterpcbb");
E 5
I 5
		lookup("_masterpaddr");
E 5
D 4
		printf("masterpcbb at %X\n", cursym->n_value);
E 4
D 8
		physrw(fcor, cursym->n_value&0x7fffffff, &masterpcbb, 1);
E 8
I 8
D 11
		physrw(fcor, cursym->n_value&~0x80000000, &masterpcbb, 1);
E 8
I 5
		masterpcbb = (masterpcbb&PG_PFNUM)*512;
E 11
I 11
		physrw(fcor, KVTOPH(cursym->n_value), &masterpcbb, 1);
		masterpcbb = (masterpcbb&PG_PFNUM)*NBPG;
E 11
E 5
D 4
		printf("masterpcbb value %X\n", masterpcbb);
		var[varchk('p')] = masterpcbb;
E 4
		getpcb();
I 8
		findstackframe();
E 8
E 2
		return;
	}
	if (read(fcor, (char *)&u, ctob(UPAGES))!=ctob(UPAGES) ||
	   !INUDOT(u.u_pcb.pcb_ksp) || !INSTACK(u.u_pcb.pcb_usp)) {
		datmap.e1 = MAXFILE;
		return;
	}
	signo = u.u_arg[0];
	sigcode = u.u_code;
	filhdr.a_text = ctob(u.u_tsize);
	filhdr.a_data = ctob(u.u_dsize);
	stksiz = ctob(u.u_ssize);
	switch (filhdr.a_magic) {

	case OMAGIC:
		datmap.b1 = 0;
		datmap.e1 = filhdr.a_text+filhdr.a_data;
		datmap.f2 = ctob(UPAGES) + datmap.e1;
		break;

	case NMAGIC:
	case ZMAGIC:
		datmap.b1 = round(filhdr.a_text, PAGSIZ);
		datmap.e1 = datmap.b1 + filhdr.a_data;
		datmap.f2 = ctob(UPAGES) + filhdr.a_data;
		break;
	}
	datbas = datmap.b1;
	datmap.f1 = ctob(UPAGES);
	datmap.b2 = MAXSTOR - stksiz;
	datmap.e2 = MAXSTOR;
D 7
	if (filhdr.a_magic && u.u_exdata.ux_mag &&
	    filhdr.a_magic != u.u_exdata.ux_mag)
		printf("corefile not from this program");
E 7
I 2
}

getpcb()
{
D 4
	printf("getpcb: masterpcbb is %X\n", masterpcbb);
E 4
I 4

E 4
D 8
	lseek(fcor, masterpcbb&~0x80000000, 0);
E 8
I 8
D 11
	lseek(fcor, masterpcbb&~0x80000000, L_SET);
E 11
I 11
	lseek(fcor, KVTOPH(masterpcbb), L_SET);
E 11
E 8
	read(fcor, &pcb, sizeof (struct pcb));
I 4
	pcb.pcb_p0lr &= ~AST_CLR;
E 4
D 9
	printf("p0br %X p0lr %X p1br %X p1lr %X\n",
E 9
I 9
	printf("p0br %x p0lr %x p1br %x p1lr %x\n",
E 9
	    pcb.pcb_p0br, pcb.pcb_p0lr, pcb.pcb_p1br, pcb.pcb_p1lr);
I 8
}

caddr_t	rpb, scb;
caddr_t	intstack, eintstack;
caddr_t	ustack, eustack;
struct	frame *getframe();
struct	frame *checkintstack();

/*
 * Find the current stack frame when debugging the kernel.
 * If we're looking at a crash dump and this was not a ``clean''
 * crash, then we must search the interrupt stack carefully
 * looking for a valid frame.
 */
findstackframe()
{
	char *panicstr, buf[256];
	register struct frame *fp;
	caddr_t addr;
	register char *cp;
	int mask;

	if (lookup("_panicstr") == 0)
		return;
D 11
	lseek(fcor, cursym->n_value&~0x80000000, L_SET);
E 11
I 11
	lseek(fcor, KVTOPH(cursym->n_value), L_SET);
E 11
	read(fcor, &panicstr, sizeof (panicstr));
	if (panicstr == 0)
		return;
D 11
	lseek(fcor, ((off_t)panicstr)&~0x80000000, L_SET);
E 11
I 11
	lseek(fcor, KVTOPH((off_t)panicstr), L_SET);
E 11
	read(fcor, buf, sizeof (buf));
	for (cp = buf; cp < &buf[sizeof (buf)] && *cp; cp++)
D 11
		if (!isascii(*cp) || !isprint(*cp))
E 11
I 11
		if (!isascii(*cp) || (!isprint(*cp) && !isspace(*cp)))
E 11
			*cp = '?';
	if (*cp)
		*cp = '\0';
	printf("panic: %s\n", buf);
	/*
	 * After a panic, look at the top of the rpb stack to
	 * find a stack frame.  If this was a clean crash,
	 * i.e. one which left the interrupt and kernel stacks
	 * in a reasonable state, then we should find a pointer
	 * to the proper stack frame here (at location scb-4).
	 * If we don't find a reasonable frame here, then we
	 * must search down through the interrupt stack.
	 */
	intstack = lookup("_intstack")->n_value;
#define	NISP	3			/* from locore.s */
	eintstack = intstack + NISP*NBPG;
	rpb = lookup("_rpb")->n_value;
	scb = lookup("_scb")->n_value;
	lookup("_u");
	ustack = cursym->n_value + (int)&((struct user *)0)->u_stack[0];
	eustack = cursym->n_value + ctob(UPAGES);
D 11
	physrw(fcor, ((int)scb - sizeof (caddr_t))&~0x80000000, &addr, 1);
E 11
I 11
	physrw(fcor, KVTOPH((int)scb - sizeof (caddr_t)), &addr, 1);
E 11
	fp = getframe(fcor, addr);
	if (fp == 0)
		fp = checkintstack();
	/* search kernel stack? */
	if (fp == 0) {
		printf("can't locate stack frame\n");
		return;
	}
	/* probably shouldn't clobber pcb, but for now this is easy */
	pcb.pcb_fp = addr;
	pcb.pcb_pc = fp->fr_savpc;
	pcb.pcb_ap = addr + sizeof (struct frame) + fp->fr_spa;
	for (mask = fp->fr_mask; mask; mask >>= 1)
		if (mask & 01)
			pcb.pcb_ap += sizeof (caddr_t);
}

/*
 * Search interrupt stack for a valid frame.
 */
struct frame *
checkintstack(fcor)
{
	char stack[NISP*NBPG];
	off_t off = vtophys(intstack);
	struct frame *fp;
	register caddr_t addr;

	if (off == -1 || lseek(fcor, off, L_SET) != off ||
	    read(fcor, stack, sizeof (stack)) != sizeof (stack))
		return ((struct frame *)0);
	addr = eintstack;
	do {
		addr -= sizeof (caddr_t);
		fp = (struct frame *)&stack[addr - intstack];
	} while (addr >= intstack + sizeof (struct frame) &&
	    !checkframe(fp));
	return (addr < intstack+sizeof (struct frame) ? (struct frame *)0 : fp);
}

/*
 * Get a stack frame and verify it looks like
 * something which might be on a kernel stack.
 */
struct frame *
getframe(fcor, fp)
	int fcor;
	caddr_t fp;
{
	static struct frame frame;
	off_t off;

	if (!kstackaddr(fp) || (off = vtophys(fp)) == -1)
		return ((struct frame *)0);
	if (lseek(fcor, off, L_SET) != off ||
	    read(fcor, &frame, sizeof (frame)) != sizeof (frame))
		return ((struct frame *)0);
	if (!checkframe(&frame))
		return ((struct frame *)0);
	return (&frame);
}

/*
 * Check a call frame to see if it's ok as
 * a kernel stack frame.
 */
checkframe(fp)
	register struct frame *fp;
{

	if (fp->fr_handler != 0 || fp->fr_s == 0)
		return (0);
	if (!kstackaddr(fp->fr_savap) || !kstackaddr(fp->fr_savfp))
		return (0);
	return (within(fp->fr_savpc, txtmap.b1, txtmap.e1));
}

/*
 * Check if an address is in one of the kernel's stacks:
 * interrupt stack, rpb stack (during restart sequence),
 * or u. stack.
 */
kstackaddr(addr)
	caddr_t addr;
{

	return (within(addr, intstack, eintstack) ||
	    within(addr, rpb + sizeof (struct rpb), scb) ||
	    within(addr, ustack, eustack));
E 8
D 4
	pcb.pcb_p0lr &= ~AST_CLR;
E 4
E 2
}

create(f)
	char *f;
{
	register int fd;

	fd = creat(f, 0644);
	if (fd < 0)
		return (-1);
	close(fd);
	return (open(f, wtflag));
}

getfile(filnam, cnt)
	char *filnam;
{
	register int fsym;

	if (eqstr(filnam, "-"))
		return (-1);
	fsym = open(filnam, wtflag);
	if (fsym < 0 && xargc > cnt) {
		if (wtflag)
			fsym = create(filnam);
		if (fsym < 0)
			printf("cannot open `%s'\n", filnam);
	}
	return (fsym);
}

setvar()
{

	var[varchk('b')] = datbas;
	var[varchk('d')] = filhdr.a_data;
	var[varchk('e')] = filhdr.a_entry;
	var[varchk('m')] = filhdr.a_magic;
	var[varchk('s')] = stksiz;
	var[varchk('t')] = filhdr.a_text;
}
E 1
