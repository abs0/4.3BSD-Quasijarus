h46559
s 00422/00368/00829
d D 5.4 88/01/12 01:28:47 donn 18 17
c merge in latest Linton version
e
s 00013/00013/01184
d D 5.3 86/02/23 20:59:35 sam 17 16
c fixup
e
s 00172/00000/01025
d D 5.2 86/02/23 16:20:41 sam 16 15
c add machine-specific code from other files
e
s 00008/00002/01017
d D 5.1 85/05/31 10:03:18 dist 15 14
c Add copyright
e
s 00122/00090/00897
d D 1.13 85/03/01 20:24:35 linton 14 13
c update to version 3.0
e
s 00002/00003/00985
d D 1.12 84/08/17 22:33:56 sam 13 12
c fix recursion problem with signals: dostep looks for the next 
c line's address (when single stepping) but trips over the address of the 
c signal handler -- remedy is to take address of signal handler for pending 
c signal only once, then iteratively find the next address disregarding the 
c pending signal (got that??)
e
s 00057/00016/00931
d D 1.11 84/08/12 15:13:49 sam 12 11
c give more useful information on process status
e
s 00001/00003/00946
d D 1.10 84/06/23 11:41:20 sam 11 9
i 10
c merge linton branch delta trail
e
s 00036/00007/00913
d D 1.9.1.1 84/06/23 10:47:10 sam 10 9
c branch delta of linton changes from net.sources
e
s 00021/00008/00899
d D 1.9 83/08/05 02:56:14 linton 9 8
c a few fixes of printing float data, and now generates 
c a symbolic address when it corresponds with a procedure entry
e
s 00002/00000/00905
d D 1.8 83/04/08 02:15:22 linton 8 7
c added a call to bpact after seeing a return instruction
e
s 00010/00002/00895
d D 1.7 83/04/08 01:01:03 linton 7 6
c added some smarts to avoid single-stepping through functions 
c that have no source information
e
s 00045/00030/00852
d D 1.6 83/02/20 17:55:17 linton 6 5
c changed printing of source location, added "printvalue" routine 
c for "<address>=<format>" command
e
s 00005/00003/00877
d D 1.5 83/01/25 17:08:17 linton 5 4
c fixed dostep when no source line information is present
e
s 00001/00005/00879
d D 1.4 82/12/18 23:28:56 linton 4 3
c now assumes in printerror that source info has been calculated
e
s 00001/00001/00883
d D 1.3 82/12/15 04:29:57 linton 3 2
c changed "vaxops" to "ops"
e
s 00001/00001/00883
d D 1.2 82/12/15 04:20:35 linton 2 1
c fixed @(#) stuff
e
s 00884/00000/00000
d D 1.1 82/12/15 04:07:50 linton 1 0
c date and time created 82/12/15 04:07:50 by linton
e
u
U
f b 
t
T
I 1
D 15
/* Copyright (c) 1982 Regents of the University of California */
E 15
I 15
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 15

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 10
static char sccsid[] = "%Z%%M% %I% %G%";
E 10
I 10
D 11
static char sccsid[] = "@(#)machine.c 1.9 8/5/83";
E 10
E 2

I 10
static char rcsid[] = "$Header: machine.c,v 1.3 84/03/27 10:21:26 linton Exp $";
E 11
I 11
D 15
static	char sccsid[] = "%W% (Berkeley) %G%";
E 15
I 15
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 15
E 11

I 14
D 18
static char rcsid[] = "$Header: machine.c,v 1.5 84/12/26 10:40:05 linton Exp $";
E 18
I 18
static char rcsid[] = "$Header: machine.c,v 1.2 87/03/26 14:54:55 donn Exp $";
E 18

E 14
E 10
/*
 * Target machine dependent stuff.
 */

#include "defs.h"
#include "machine.h"
#include "process.h"
I 10
#include "runtime.h"
E 10
#include "events.h"
#include "main.h"
#include "symbols.h"
#include "source.h"
#include "mappings.h"
#include "object.h"
I 18
#include "tree.h"
#include "eval.h"
E 18
I 14
#include "keywords.h"
E 14
D 3
#include "vaxops.h"
E 3
I 3
#include "ops.h"
E 3
D 18
#include <signal.h>
E 18
I 16
D 17
#include <sys/param.h>
#include <sys/dir.h>
#include <machine/psl.h>
#include <machine/pte.h>
#include <sys/user.h>
#include <sys/vm.h>
#include <machine/reg.h>
E 17
E 16

#ifndef public
typedef unsigned int Address;
typedef unsigned char Byte;
typedef unsigned int Word;

#define NREG 16

#define ARGP 12
#define FRP 13
#define STKP 14
#define PROGCTR 15

I 18
#define CODESTART 0
#define FUNCOFFSET 2

#define nargspassed(frame) argn(0, frame)

E 18
#define BITSPERBYTE 8
#define BITSPERWORD (BITSPERBYTE * sizeof(Word))

D 18
#define nargspassed(frame) argn(0, frame)
E 18
I 16
/*
D 18
 * Extract a field's value from the integer i.  The value
 * is placed in i in such as way as the first bit of the
 * field is contained in the first byte of the integer.
E 18
I 18
 * This magic macro enables us to look at the process' registers
 * in its user structure.
E 18
 */
D 18
#define	extractfield(i, s) \
	((i >> ((s)->symvalue.field.offset mod BITSPERBYTE)) & \
	 ((1 << (s)->symvalue.field.length) - 1))
/*
 * Expand/contract the expression stack to reflect a type
 * rename operation.  We pad with zeros when expanding,
 * otherwise we just pull the stack pointer back.
 */
#define	typerename(oldsize, newsize) { \
	int len = newsize - oldsize; \
	if (len > 0) \
		bzero(sp, len); \
	sp += len; \
}
E 18
E 16

I 16
D 18
#define	SYSBASE	0x80000000		/* base of system address space */
#define	physaddr(a)	((a) & 0x7fffffff)
E 18
I 18
#define regloc(reg)	(ctob(UPAGES) + (sizeof(Word) * (reg)))
E 18

D 17
/*
 * Indices into u. for use in collecting registers values.
 */
int rloc[] =
    { R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, AP, FP, SP, PC };

E 17
E 16
#include "source.h"
#include "symbols.h"
I 18
#include <signal.h>
E 18
I 17
#include <sys/param.h>
#include <sys/dir.h>
#include <machine/psl.h>
#include <machine/pte.h>
#include <sys/user.h>
I 18
#undef DELETE /* XXX */
E 18
#include <sys/vm.h>
#include <machine/reg.h>
E 17

Address pc;
Address prtaddr;

#endif

I 18
/*
 * Indices into u. for use in collecting registers values.
 */
public int rloc[] ={
    R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, AP, FP, SP, PC
};

E 18
private Address printop();
I 17

I 18
private Optab *ioptab[256];	/* index by opcode to optab */

E 18
/*
D 18
 * Indices into u. for use in collecting registers values.
E 18
I 18
 * Initialize the opcode lookup table.
E 18
 */
D 18
public int rloc[] =
    { R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, AP, FP, SP, PC };
E 18
I 18
public optab_init()
{
	register Optab *p;
E 18
E 17

I 18
	for (p = optab; p->iname; p++)
		ioptab[p->val & 0xff] = p;
}

E 18
/*
 * Decode and print the instructions within the given address range.
 */

public printinst(lowaddr, highaddr)
Address lowaddr;
Address highaddr;
{
    register Address addr;

    for (addr = lowaddr; addr <= highaddr; ) {
	addr = printop(addr);
    }
    prtaddr = addr;
}

/*
 * Another approach:  print n instructions starting at the given address.
 */

public printninst(count, addr)
int count;
Address addr;
{
    register Integer i;
    register Address newaddr;

    if (count <= 0) {
	error("non-positive repetition count");
    } else {
	newaddr = addr;
	for (i = 0; i < count; i++) {
	    newaddr = printop(newaddr);
	}
	prtaddr = newaddr;
    }
}

I 16
D 18
optab_init()
{

}

E 18
E 16
/*
D 18
 * Hacked version of adb's VAX instruction decoder.
 */

private Address printop(addr)
Address addr;
{
    Optab op;
    VaxOpcode ins;
    unsigned char mode;
    int argtype, amode, argno, argval;
    String reg;
    Boolean indexf;
    short offset;

    argval = 0;
    indexf = false;
    printf("%08x  ", addr);
    iread(&ins, addr, sizeof(ins));
    addr += 1;
    op = optab[ins];
    printf("%s", op.iname);
    for (argno = 0; argno < op.numargs; argno++) {
	if (indexf == true) {
	    indexf = false;
	} else if (argno == 0) {
	    printf("\t");
	} else {
	    printf(",");
	}
	argtype = op.argtype[argno];
	if (is_branch_disp(argtype)) {
	    mode = 0xAF + (typelen(argtype) << 5);
	} else {
	    iread(&mode, addr, sizeof(mode));
	    addr += 1;
	}
	reg = regname[regnm(mode)];
	amode = addrmode(mode);
	switch (amode) {
	    case LITSHORT:
	    case LITUPTO31:
	    case LITUPTO47:
	    case LITUPTO63:
		if (typelen(argtype) == TYPF || typelen(argtype) ==TYPD)
		    printf("$%s", fltimm[mode]);
		else
		    printf("$%x", mode);
		argval = mode;
		break;

	    case INDEX:
		printf("[%s]", reg);
		indexf = true;
		argno--;
		break;

	    case REG:
		printf("%s", reg);
		break;

	    case REGDEF:
		printf("(%s)", reg);
		break;

	    case AUTODEC:
		printf("-(%s)", reg);
		break;

	    case AUTOINC:
		if (reg != regname[PROGCTR]) {
		    printf("(%s)+", reg);
		} else {
		    printf("$");
		    switch (typelen(argtype)) {
			case TYPB:
			    argval = printdisp(addr, 1, reg, amode);
			    addr += 1;
			    break;

			case TYPW:
			    argval = printdisp(addr, 2, reg, amode);
			    addr += 2;
			    break;

			case TYPL:
			    argval = printdisp(addr, 4, reg, amode);
			    addr += 4;
			    break;

			case TYPF:
			    iread(&argval, addr, sizeof(argval));
			    printf("%06x", argval);
			    addr += 4;
			    break;

			case TYPQ:
			case TYPD:
			    iread(&argval, addr, sizeof(argval));
			    printf("%06x", argval);
			    iread(&argval, addr+4, sizeof(argval));
			    printf("%06x", argval);
			    addr += 8;
			    break;
		    }
		}
		break;

	    case AUTOINCDEF:
		if (reg == regname[PROGCTR]) {
		    printf("*$");
		    argval = printdisp(addr, 4, reg, amode);
		    addr += 4;
		} else {
		    printf("*(%s)+", reg);
		}
		break;

	    case BYTEDISP:
		argval = printdisp(addr, 1, reg, amode);
		addr += 1;
		break;

	    case BYTEDISPDEF:
		printf("*");
		argval = printdisp(addr, 1, reg, amode);
		addr += 1;
		break;

	    case WORDDISP:
		argval = printdisp(addr, 2, reg, amode);
		addr += 2;
		break;

	    case WORDDISPDEF:
		printf("*");
		argval = printdisp(addr, 2, reg, amode);
		addr += 2;
		break;

	    case LONGDISP:
		argval = printdisp(addr, 4, reg, amode);
		addr += 4;
		break;

	    case LONGDISPDEF:
		printf("*");
		argval = printdisp(addr, 4, reg, amode);
		addr += 4;
		break;
	}
    }
    if (ins == O_CASEB || ins == O_CASEW || ins == O_CASEL) {
	for (argno = 0; argno <= argval; argno++) {
	    iread(&offset, addr, sizeof(offset));
	    printf("\n\t\t%d", offset);
	    addr += 2;
	}
    }
    printf("\n");
    return addr;
}

/*
 * Print the displacement of an instruction that uses displacement
 * addressing.
 */

private int printdisp(addr, nbytes, reg, mode)
Address addr;
int nbytes;
char *reg;
int mode;
{
    char byte;
    short hword;
    int argval;
I 9
    Symbol f;
E 9

    switch (nbytes) {
	case 1:
	    iread(&byte, addr, sizeof(byte));
	    argval = byte;
	    break;

	case 2:
	    iread(&hword, addr, sizeof(hword));
	    argval = hword;
	    break;

	case 4:
	    iread(&argval, addr, sizeof(argval));
	    break;
    }
    if (reg == regname[PROGCTR] && mode >= BYTEDISP) {
	argval += addr + nbytes;
    }
    if (reg == regname[PROGCTR]) {
D 9
	printf("%x", argval);
E 9
I 9
	f = whatblock((Address) argval + 2);
	if (codeloc(f) == argval + 2) {
	    printf("%s", symname(f));
	} else {
	    printf("%x", argval);
	}
E 9
    } else {
D 14
	printf("%d(%s)", argval, reg);
E 14
I 14
	if (varIsSet("$hexoffsets")) {
	    if (argval < 0) {
		printf("-%x(%s)", -(argval), reg);
	    } else {
		printf("%x(%s)", argval, reg);
	    }
	} else {
	    printf("%d(%s)", argval, reg);
	}
E 14
    }
    return argval;
}

/*
E 18
 * Print the contents of the addresses within the given range
 * according to the given format.
 */

typedef struct {
    String name;
    String printfstring;
    int length;
} Format;

private Format fmt[] = {
    { "d", " %d", sizeof(short) },
    { "D", " %ld", sizeof(long) },
    { "o", " %o", sizeof(short) },
    { "O", " %lo", sizeof(long) },
    { "x", " %04x", sizeof(short) },
    { "X", " %08x", sizeof(long) },
    { "b", " \\%o", sizeof(char) },
    { "c", " '%c'", sizeof(char) },
    { "s", "%c", sizeof(char) },
D 9
    { "f", " %f", sizeof(double) },
E 9
I 9
    { "f", " %f", sizeof(float) },
E 9
    { "g", " %g", sizeof(double) },
    { nil, nil, 0 }
};

I 6
private Format *findformat(s)
String s;
{
    register Format *f;

    f = &fmt[0];
    while (f->name != nil and not streq(f->name, s)) {
	++f;
    }
    if (f->name == nil) {
	error("bad print format \"%s\"", s);
    }
    return f;
}

I 18
/*
 * Retrieve and print out the appropriate data in the given format.
 * Floats have to be handled specially to allow the compiler to
 * convert them to doubles when passing to printf.
 */

private printformat (f, addr)
Format *f;
Address addr;
{
    union {
	char charv;
	short shortv;
	int intv;
	float floatv;
	double doublev;
    } value;

    value.intv = 0;
    dread(&value, addr, f->length);
    if (streq(f->name, "f")) {
	printf(f->printfstring, value.floatv);
    } else {
	printf(f->printfstring, value);
    }
}

E 18
E 6
public Address printdata(lowaddr, highaddr, format)
Address lowaddr;
Address highaddr;
String format;
{
D 18
    register int n;
E 18
I 18
    int n;
E 18
    register Address addr;
D 18
    register Format *f;
    int value;
E 18
I 18
    Format *f;
E 18

    if (lowaddr > highaddr) {
	error("first address larger than second");
    }
D 6
    f = &fmt[0];
    while (f->name != nil and not streq(f->name, format)) {
	++f;
    }
    if (f->name == nil) {
	error("bad print format \"%s\"", format);
    }
E 6
I 6
    f = findformat(format);
E 6
    n = 0;
D 18
    value = 0;
E 18
    for (addr = lowaddr; addr <= highaddr; addr += f->length) {
	if (n == 0) {
	    printf("%08x: ", addr);
	}
D 18
	dread(&value, addr, f->length);
	printf(f->printfstring, value);
E 18
I 18
	printformat(f, addr);
E 18
	++n;
	if (n >= (16 div f->length)) {
D 18
	    putchar('\n');
E 18
I 18
	    printf("\n");
E 18
	    n = 0;
	}
    }
    if (n != 0) {
D 18
	putchar('\n');
E 18
I 18
	printf("\n");
E 18
    }
    prtaddr = addr;
    return addr;
}

/*
 * The other approach is to print n items starting with a given address.
 */

public printndata(count, startaddr, format)
int count;
Address startaddr;
String format;
{
D 18
    register int i, n;
    register Address addr;
    register Format *f;
    register Boolean isstring;
E 18
I 18
    int i, n;
    Address addr;
    Format *f;
    Boolean isstring;
E 18
D 9
    int value;
E 9
I 9
    char c;
D 18
    union {
	char charv;
	short shortv;
	int intv;
	float floatv;
	double doublev;
    } value;
E 18
E 9

    if (count <= 0) {
	error("non-positive repetition count");
    }
D 6
    f = &fmt[0];
    while (f->name != nil and not streq(f->name, format)) {
	++f;
    }
    if (f->name == nil) {
	error("bad print format \"%s\"", format);
    }
E 6
I 6
    f = findformat(format);
E 6
    isstring = (Boolean) streq(f->name, "s");
    n = 0;
    addr = startaddr;
D 9
    value = 0;
E 9
I 9
D 18
    value.intv = 0;
E 18
E 9
    for (i = 0; i < count; i++) {
	if (n == 0) {
	    printf("%08x: ", addr);
	}
	if (isstring) {
D 18
	    putchar('"');
E 18
I 18
	    printf("\"");
E 18
D 9
	    dread(&value, addr, sizeof(char));
	    while (value != '\0') {
		printchar((char) value);
E 9
I 9
	    dread(&c, addr, sizeof(char));
	    while (c != '\0') {
		printchar(c);
E 9
		++addr;
D 9
		dread(&value, addr, sizeof(char));
E 9
I 9
		dread(&c, addr, sizeof(char));
E 9
	    }
D 18
	    putchar('"');
	    putchar('\n');
E 18
I 18
	    printf("\"\n");
E 18
	    n = 0;
	    addr += sizeof(String);
	} else {
D 18
	    dread(&value, addr, f->length);
	    printf(f->printfstring, value);
E 18
I 18
	    printformat(f, addr);
E 18
	    ++n;
	    if (n >= (16 div f->length)) {
D 18
		putchar('\n');
E 18
I 18
		printf("\n");
E 18
		n = 0;
	    }
	    addr += f->length;
	}
    }
    if (n != 0) {
D 18
	putchar('\n');
E 18
I 18
	printf("\n");
E 18
    }
    prtaddr = addr;
}

/*
I 6
 * Print out a value according to the given format.
 */

public printvalue(v, format)
long v;
String format;
{
    Format *f;
    char *p, *q;

    f = findformat(format);
    if (streq(f->name, "s")) {
	putchar('"');
	p = (char *) &v;
	q = p + sizeof(v);
	while (p < q) {
	    printchar(*p);
	    ++p;
	}
	putchar('"');
    } else {
	printf(f->printfstring, v);
    }
    putchar('\n');
}

/*
E 6
 * Print out an execution time error.
I 4
 * Assumes the source position of the error has been calculated.
E 4
 *
 * Have to check if the -r option was specified; if so then
 * the object file information hasn't been read in yet.
 */

public printerror()
{
    extern Integer sys_nsig;
    extern String sys_siglist[];
D 4
    String filename;
E 4
D 14
    Integer err;
E 14
I 14
    integer err;
E 14

    if (isfinished(process)) {
D 12
	printf("\"%s\" exits with code %d\n", objname, exitcode(process));
E 12
I 12
	err = exitcode(process);
D 14
	printf("\"%s\" terminated", objname);
	if (err)
	    printf("abnormally (exit code %d)", err);
	putchar('\n');
E 14
I 14
	if (err == 0) {
	    printf("\"%s\" terminated normally\n", objname);
	} else {
	    printf("\"%s\" terminated abnormally (exit code %d)\n",
		objname, err
	    );
	}
E 14
E 12
	erecover();
    }
D 18
    if (runfirst) {
D 14
	fprintf(stderr, "Entering debugger ...");
E 14
I 14
	fprintf(stderr, "Entering debugger ...\n");
E 14
	init();
D 14
	fprintf(stderr, " type 'help' for help\n");
E 14
    }
E 18
D 4
    curline = srcline(pc);
    curfunc = whatblock(pc);
    filename = srcfilename(pc);
    setsource(filename);
E 4
    err = errnum(process);
D 12
    if (err == SIGINT) {
	printf("\n\ninterrupt ");
	printloc();
    } else if (err == SIGTRAP) {
	printf("\nerror ");
	printloc();
    } else {
	if (err < 0 or err > sys_nsig) {
	    printf("\nsignal %d ", err);
	} else {
	    printf("\n%s ", sys_siglist[err]);
	}
	printloc();
    }
E 12
    putchar('\n');
I 12
    printsig(err);
I 14
    putchar(' ');
E 14
    printloc();
    putchar('\n');
E 12
    if (curline > 0) {
	printlines(curline, curline);
    } else {
	printinst(pc, pc);
    }
    erecover();
}

I 14
/*
 * Print out a signal.
 */

E 14
I 12
private String illinames[] = {
D 14
	"reserved addressing fault",
	"priviliged instruction fault",
	"reserved operand fault"
E 14
I 14
    "reserved addressing fault",
D 18
    "priviliged instruction fault",
E 18
I 18
    "privileged instruction fault",
E 18
    "reserved operand fault"
E 14
};
I 14

E 14
private String fpenames[] = {
D 14
	nil,
	"integer overflow trap",
	"integer divide by zero trap",
	"floating overflow trap",
	"floating/decimal divide by zero trap",
	"floating underflow trap",
	"decimal overflow trap",
	"subscript out of range trap",
	"floating overflow fault",
	"floating divide by zero fault",
	"floating undeflow fault"
E 14
I 14
    nil,
    "integer overflow trap",
    "integer divide by zero trap",
    "floating overflow trap",
    "floating/decimal divide by zero trap",
    "floating underflow trap",
    "decimal overflow trap",
    "subscript out of range trap",
    "floating overflow fault",
    "floating divide by zero fault",
D 18
    "floating undeflow fault"
E 18
I 18
    "floating underflow fault"
E 18
E 14
};

D 14
public printsig(signo)
    Integer signo;
E 14
I 14
public printsig (signo)
integer signo;
E 14
{
D 14
    Integer sigcode;
E 14
I 14
    integer code;
E 14

D 14
    if (0 < signo && signo < sys_nsig)
	printf("%s ", sys_siglist[signo]);
    else
	printf("signal %d ", signo);
    sigcode = errcode(process);
    switch (signo) {

    case SIGFPE:
	    if (sigcode > 0 &&
		sigcode < sizeof fpenames / sizeof fpenames[0])
		    printf("(%s) ",  fpenames[sigcode]);
	    break;

    case SIGILL:
	    if (sigcode >= 0 &&
		sigcode < sizeof illinames / sizeof illinames[0])
		    printf("(%s) ", illinames[sigcode]);
	    break;
E 14
I 14
    if (signo < 0 or signo > sys_nsig) {
	printf("[signal %d]", signo);
    } else {
	printf("%s", sys_siglist[signo]);
E 14
    }
I 14
    code = errcode(process);
    if (signo == SIGILL) {
	if (code >= 0 and code < sizeof(illinames) / sizeof(illinames[0])) {
	    printf(" (%s)", illinames[code]);
	}
    } else if (signo == SIGFPE) {
	if (code > 0 and code < sizeof(fpenames) / sizeof(fpenames[0])) {
	    printf(" (%s)", fpenames[code]);
	}
    }
E 14
}

E 12
D 6
private printloc()
{
    if (curline > 0) {
	if (nlhdr.nfiles > 1) {
	    printf("at line %d in file %s", curline, cursource);
	} else {
	    printf("at line %d", curline);
	}
    } else {
	printf("in ");
	printname(stdout, curfunc);
	printf(" at 0x%x", pc);
    }
}

E 6
/*
 * Note the termination of the program.  We do this so as to avoid
 * having the process exit, which would make the values of variables
 * inaccessible.  We do want to flush all output buffers here,
 * otherwise it'll never get done.
 */

public endprogram()
{
    Integer exitcode;

    stepto(nextaddr(pc, true));
    printnews();
    exitcode = argn(1, nil);
D 12
    printf("\nexecution completed, exit code is %d\n", exitcode);
E 12
I 12
D 14
    printf("\nexecution completed");
    if (exitcode)
	printf(" (exit code %d)", exitcode);
    putchar('\n');
E 14
I 14
    if (exitcode != 0) {
	printf("\nexecution completed (exit code %d)\n", exitcode);
    } else {
	printf("\nexecution completed\n");
    }
E 14
E 12
    getsrcpos();
    erecover();
}

/*
 * Single step the machine a source line (or instruction if "inst_tracing"
D 5
 * is true.  If "isnext" is true, skip over procedure calls.
E 5
I 5
 * is true).  If "isnext" is true, skip over procedure calls.
E 5
 */

I 13
D 14
private Address findnextaddr();
E 14
E 13
private Address getcall();

public dostep(isnext)
Boolean isnext;
{
    register Address addr;
    register Lineno line;
    String filename;
I 10
D 14
    Address startaddr, prevaddr;
E 14
I 14
    Address startaddr;
E 14
E 10

I 10
    startaddr = pc;
D 14
    prevaddr = startaddr;
E 14
E 10
    addr = nextaddr(pc, isnext);
D 5
    if (not inst_tracing) {
E 5
I 5
    if (not inst_tracing and nlhdr.nlines != 0) {
E 5
	line = linelookup(addr);
	while (line == 0) {
I 10
D 14
	    prevaddr = addr;
E 10
D 13
	    addr = nextaddr(addr, isnext);
E 13
I 13
	    addr = findnextaddr(addr, isnext);
E 14
I 14
	    addr = nextaddr(addr, isnext);
E 14
E 13
	    line = linelookup(addr);
	}
I 5
	curline = line;
    } else {
	curline = 0;
E 5
    }
I 10
D 14
    if (addr == startaddr) {
	stepto(prevaddr);
    }
E 14
E 10
    stepto(addr);
D 5
    curline = line;
E 5
    filename = srcfilename(addr);
    setsource(filename);
}

I 18
typedef char Bpinst;

#define BP_OP       O_BPT       /* breakpoint trap */

#define BP_ERRNO    SIGTRAP     /* signal received at a breakpoint */

E 18
/*
I 18
 * Setting a breakpoint at a location consists of saving
 * the word at the location and poking a BP_OP there.
 *
 * We save the locations and words on a list for use in unsetting.
 */

typedef struct Savelist *Savelist;

struct Savelist {
    Address location;
    Bpinst save;
    short refcount;
    Savelist link;
};

private Savelist savelist;

/*
 * Set a breakpoint at the given address.  Only save the word there
 * if it's not already a breakpoint.
 */

public setbp(addr)
Address addr;
{
    Bpinst w, save;
    register Savelist newsave, s;

    for (s = savelist; s != nil; s = s->link) {
	if (s->location == addr) {
	    s->refcount++;
	    return;
	}
    }
    iread(&save, addr, sizeof(save));
    newsave = new(Savelist);
    newsave->location = addr;
    newsave->save = save;
    newsave->refcount = 1;
    newsave->link = savelist;
    savelist = newsave;
    w = BP_OP;
    iwrite(&w, addr, sizeof(w));
}

/*
 * Unset a breakpoint; unfortunately we have to search the SAVELIST
 * to find the saved value.  The assumption is that the SAVELIST will
 * usually be quite small.
 */

public unsetbp(addr)
Address addr;
{
    register Savelist s, prev;

    prev = nil;
    for (s = savelist; s != nil; s = s->link) {
	if (s->location == addr) {
	    iwrite(&s->save, addr, sizeof(s->save));
	    s->refcount--;
	    if (s->refcount == 0) {
		if (prev == nil) {
		    savelist = s->link;
		} else {
		    prev->link = s->link;
		}
		dispose(s);
	    }
	    return;
	}
	prev = s;
    }
    panic("unsetbp: couldn't find address %d", addr);
}

/*
 * VAX instruction decoder, derived from adb.
 */

private Address printop(addr)
Address addr;
{
    register Optab *op;
    VaxOpcode ins;
    unsigned char mode;
    int argtype, amode, argno, argval;
    String reg;
    Boolean indexf;
    short offset;

    argval = 0;
    indexf = false;
    printf("%08x  ", addr);
    iread(&ins, addr, sizeof(ins));
    addr += 1;
    op = ioptab[ins];
    printf("%s", op->iname);
    for (argno = 0; argno < op->numargs; argno++) {
	if (indexf == true) {
	    indexf = false;
	} else if (argno == 0) {
	    printf("\t");
	} else {
	    printf(",");
	}
	argtype = op->argtype[argno];
	if (is_branch_disp(argtype)) {
	    mode = 0xAF + (typelen(argtype) << 5);
	} else {
	    iread(&mode, addr, sizeof(mode));
	    addr += 1;
	}
	reg = regname[regnm(mode)];
	amode = addrmode(mode);
	switch (amode) {
	    case LITSHORT:
	    case LITUPTO31:
	    case LITUPTO47:
	    case LITUPTO63:
		if (typelen(argtype) == TYPF || typelen(argtype) ==TYPD)
		    printf("$%s", fltimm[mode]);
		else
		    printf("$%x", mode);
		argval = mode;
		break;

	    case INDEX:
		printf("[%s]", reg);
		indexf = true;
		argno--;
		break;

	    case REG:
		printf("%s", reg);
		break;

	    case REGDEF:
		printf("(%s)", reg);
		break;

	    case AUTODEC:
		printf("-(%s)", reg);
		break;

	    case AUTOINC:
		if (reg != regname[PROGCTR]) {
		    printf("(%s)+", reg);
		} else {
		    printf("$");
		    switch (typelen(argtype)) {
			case TYPB:
			    argval = printdisp(addr, 1, reg, amode);
			    addr += 1;
			    break;

			case TYPW:
			    argval = printdisp(addr, 2, reg, amode);
			    addr += 2;
			    break;

			case TYPL:
			    argval = printdisp(addr, 4, reg, amode);
			    addr += 4;
			    break;

			case TYPF:
			    iread(&argval, addr, sizeof(argval));
			    printf("%06x", argval);
			    addr += 4;
			    break;

			case TYPQ:
			case TYPD:
			    iread(&argval, addr, sizeof(argval));
			    printf("%06x", argval);
			    iread(&argval, addr+4, sizeof(argval));
			    printf("%06x", argval);
			    addr += 8;
			    break;
		    }
		}
		break;

	    case AUTOINCDEF:
		if (reg == regname[PROGCTR]) {
		    printf("*$");
		    argval = printdisp(addr, 4, reg, amode);
		    addr += 4;
		} else {
		    printf("*(%s)+", reg);
		}
		break;

	    case BYTEDISP:
		argval = printdisp(addr, 1, reg, amode);
		addr += 1;
		break;

	    case BYTEDISPDEF:
		printf("*");
		argval = printdisp(addr, 1, reg, amode);
		addr += 1;
		break;

	    case WORDDISP:
		argval = printdisp(addr, 2, reg, amode);
		addr += 2;
		break;

	    case WORDDISPDEF:
		printf("*");
		argval = printdisp(addr, 2, reg, amode);
		addr += 2;
		break;

	    case LONGDISP:
		argval = printdisp(addr, 4, reg, amode);
		addr += 4;
		break;

	    case LONGDISPDEF:
		printf("*");
		argval = printdisp(addr, 4, reg, amode);
		addr += 4;
		break;
	}
    }
    if (ins == O_CASEB || ins == O_CASEW || ins == O_CASEL) {
	for (argno = 0; argno <= argval; argno++) {
	    iread(&offset, addr, sizeof(offset));
	    printf("\n\t\t%d", offset);
	    addr += 2;
	}
    }
    printf("\n");
    return addr;
}

/*
 * Print the displacement of an instruction that uses displacement
 * addressing.
 */

private int printdisp(addr, nbytes, reg, mode)
Address addr;
int nbytes;
char *reg;
int mode;
{
    char byte;
    short hword;
    int argval;
    Symbol f;

    switch (nbytes) {
	case 1:
	    iread(&byte, addr, sizeof(byte));
	    argval = byte;
	    break;

	case 2:
	    iread(&hword, addr, sizeof(hword));
	    argval = hword;
	    break;

	case 4:
	    iread(&argval, addr, sizeof(argval));
	    break;
    }
    if (reg == regname[PROGCTR] && mode >= BYTEDISP) {
	argval += addr + nbytes;
    }
    if (reg == regname[PROGCTR]) {
	f = whatblock((Address) argval + 2);
	if (codeloc(f) == argval + 2) {
	    printf("%s", symname(f));
	} else {
	    printf("%x", argval);
	}
    } else {
	if (varIsSet("$hexoffsets")) {
	    if (argval < 0) {
		printf("-%x(%s)", -(argval), reg);
	    } else {
		printf("%x(%s)", argval, reg);
	    }
	} else {
	    printf("%d(%s)", argval, reg);
	}
    }
    return argval;
}

/*
E 18
 * Compute the next address that will be executed from the given one.
 * If "isnext" is true then consider a procedure call as straight line code.
 *
 * We must unfortunately do much of the same work that is necessary
 * to print instructions.  In addition we have to deal with branches.
 * Unconditional branches we just follow, for conditional branches
 * we continue execution to the current location and then single step
 * the machine.  We assume that the last argument in an instruction
 * that branches is the branch address (or relative offset).
 */
D 13

I 10
private Address findnextaddr();
E 13

I 14
private Address findnextaddr();

E 14
E 10
public Address nextaddr(startaddr, isnext)
Address startaddr;
I 10
boolean isnext;
{
    Address addr;

    addr = usignal(process);
    if (addr == 0 or addr == 1) {
	addr = findnextaddr(startaddr, isnext);
    }
    return addr;
}

I 14
/*
 * Determine if it's ok to skip function f entered by instruction ins.
 * If so, we're going to compute the return address and step to it.
 * Therefore we cannot skip over a function entered by a jsb or bsb,
 * since the return address is not easily computed for them.
 */

private boolean skipfunc (ins, f)
VaxOpcode ins;
Symbol f;
{
    boolean b;

    b = (boolean) (
	ins != O_JSB and ins != O_BSBB and ins != O_BSBW and
	not inst_tracing and nlhdr.nlines != 0 and
	nosource(curfunc) and canskip(curfunc)
    );
    return b;
}

E 14
private Address findnextaddr(startaddr, isnext)
Address startaddr;
E 10
Boolean isnext;
{
    register Address addr;
D 18
    Optab op;
E 18
I 18
    register Optab *op;
E 18
    VaxOpcode ins;
    unsigned char mode;
    int argtype, amode, argno, argval;
    String r;
    Boolean indexf;
    enum { KNOWN, SEQUENTIAL, BRANCH } addrstatus;

    argval = 0;
    indexf = false;
    addr = startaddr;
    iread(&ins, addr, sizeof(ins));
    switch (ins) {
I 14
	/*
	 * It used to be that unconditional jumps and branches were handled
	 * by taking their destination address as the next address.  While
	 * saving the cost of starting up the process, this approach
	 * doesn't work when jumping indirect (since the value in the
	 * register might not yet have been set).
	 *
	 * So unconditional jumps and branches are now handled the same way
	 * as conditional jumps and branches.
	 *
E 14
	case O_BRB:
	case O_BRW:
D 10
	case O_JMP:
E 10
	    addrstatus = BRANCH;
	    break;
I 14
	 *
	 */
E 14
	    
	case O_BSBB:
	case O_BSBW:
	case O_JSB:
	case O_CALLG:
	case O_CALLS:
D 14
	    if (isnext) {
		addrstatus = SEQUENTIAL;
	    } else {
E 14
I 14
	    addrstatus = KNOWN;
	    stepto(addr);
	    pstep(process, DEFSIG);
	    addr = reg(PROGCTR);
	    pc = addr;
	    setcurfunc(whatblock(pc));
	    if (not isbperr()) {
		printstatus();
		/* NOTREACHED */
	    }
	    bpact();
	    if (isnext or skipfunc(ins, curfunc)) {
E 14
		addrstatus = KNOWN;
I 14
		addr = return_addr();
E 14
		stepto(addr);
D 10
		pstep(process);
E 10
I 10
D 14
		pstep(process, DEFSIG);
E 10
		addr = reg(PROGCTR);
		pc = addr;
D 7
		callnews(/* iscall = */ true);
E 7
I 7
D 10
		curfunc = whatblock(pc);
E 10
I 10
		setcurfunc(whatblock(pc));
E 10
E 7
		if (not isbperr()) {
		    printstatus();
I 7
		    /* NOTREACHED */
		}
E 14
		bpact();
D 14
		if (nosource(curfunc) and canskip(curfunc) and
		  nlhdr.nlines != 0) {
		    addrstatus = KNOWN;
		    addr = return_addr();
		    stepto(addr);
I 8
		    bpact();
E 8
E 7
		} else {
D 7
		    bpact();
E 7
I 7
		    callnews(/* iscall = */ true);
E 7
		}
E 14
I 14
	    } else {
		callnews(/* iscall = */ true);
E 14
	    }
	    break;

	case O_RSB:
	case O_RET:
	    addrstatus = KNOWN;
I 14
	    stepto(addr);
E 14
	    callnews(/* iscall = */ false);
D 14
	    addr = return_addr();
D 10
	    stepto(addr);
E 10
I 10
	    if (addr == pc) {	/* recursive ret to self */
		pstep(process, DEFSIG);
	    } else {
		stepto(addr);
E 14
I 14
	    pstep(process, DEFSIG);
	    addr = reg(PROGCTR);
	    pc = addr;
	    if (not isbperr()) {
		printstatus();
E 14
	    }
E 10
I 8
	    bpact();
E 8
	    break;

I 14
	case O_BRB: case O_BRW:
E 14
I 10
	case O_JMP: /* because it may be jmp (r1) */
E 10
	case O_BNEQ: case O_BEQL: case O_BGTR:
	case O_BLEQ: case O_BGEQ: case O_BLSS:
	case O_BGTRU: case O_BLEQU: case O_BVC:
	case O_BVS: case O_BCC: case O_BCS:
	case O_CASEB: case O_CASEW: case O_CASEL:
	case O_BBS: case O_BBC: case O_BBSS: case O_BBCS:
	case O_BBSC: case O_BBCC: case O_BBSSI:
	case O_BBCCI: case O_BLBS: case O_BLBC:
	case O_ACBL: case O_AOBLSS: case O_AOBLEQ:
	case O_SOBGEQ: case O_SOBGTR:
	    addrstatus = KNOWN;
	    stepto(addr);
D 10
	    pstep(process);
E 10
I 10
	    pstep(process, DEFSIG);
E 10
	    addr = reg(PROGCTR);
	    pc = addr;
	    if (not isbperr()) {
		printstatus();
	    }
	    break;

	default:
	    addrstatus = SEQUENTIAL;
	    break;
    }
    if (addrstatus != KNOWN) {
	addr += 1;
D 18
	op = optab[ins];
	for (argno = 0; argno < op.numargs; argno++) {
E 18
I 18
	op = ioptab[ins];
	for (argno = 0; argno < op->numargs; argno++) {
E 18
	    if (indexf == true) {
		indexf = false;
	    }
D 18
	    argtype = op.argtype[argno];
E 18
I 18
	    argtype = op->argtype[argno];
E 18
	    if (is_branch_disp(argtype)) {
		mode = 0xAF + (typelen(argtype) << 5);
	    } else {
		iread(&mode, addr, sizeof(mode));
		addr += 1;
	    }
	    r = regname[regnm(mode)];
	    amode = addrmode(mode);
	    switch (amode) {
		case LITSHORT:
		case LITUPTO31:
		case LITUPTO47:
		case LITUPTO63:
		    argval = mode;
		    break;

		case INDEX:
		    indexf = true;
		    --argno;
		    break;

		case REG:
		case REGDEF:
		case AUTODEC:
		    break;

		case AUTOINC:
		    if (r == regname[PROGCTR]) {
			switch (typelen(argtype)) {
			    case TYPB:
				argval = getdisp(addr, 1, r, amode);
				addr += 1;
				break;

			    case TYPW:
				argval = getdisp(addr, 2, r, amode);
				addr += 2;
				break;

			    case TYPL:
				argval = getdisp(addr, 4, r, amode);
				addr += 4;
				break;

			    case TYPF:
				iread(&argval, addr, sizeof(argval));
				addr += 4;
				break;

			    case TYPQ:
			    case TYPD:
				iread(&argval, addr+4, sizeof(argval));
				addr += 8;
				break;
			}
		    }
		    break;

		case AUTOINCDEF:
		    if (r == regname[PROGCTR]) {
			argval = getdisp(addr, 4, r, amode);
			addr += 4;
		    }
		    break;

		case BYTEDISP:
		case BYTEDISPDEF:
		    argval = getdisp(addr, 1, r, amode);
		    addr += 1;
		    break;

		case WORDDISP:
		case WORDDISPDEF:
		    argval = getdisp(addr, 2, r, amode);
		    addr += 2;
		    break;

		case LONGDISP:
		case LONGDISPDEF:
		    argval = getdisp(addr, 4, r, amode);
		    addr += 4;
		    break;
	    }
	}
	if (ins == O_CALLS or ins == O_CALLG) {
	    argval += 2;
	}
	if (addrstatus == BRANCH) {
	    addr = argval;
	}
    }
    return addr;
}

/*
 * Get the displacement of an instruction that uses displacement addressing.
 */

private int getdisp(addr, nbytes, reg, mode)
Address addr;
int nbytes;
String reg;
int mode;
{
    char byte;
    short hword;
    int argval;

    switch (nbytes) {
	case 1:
	    iread(&byte, addr, sizeof(byte));
	    argval = byte;
	    break;

	case 2:
	    iread(&hword, addr, sizeof(hword));
	    argval = hword;
	    break;

	case 4:
	    iread(&argval, addr, sizeof(argval));
	    break;
    }
    if (reg == regname[PROGCTR] && mode >= BYTEDISP) {
	argval += addr + nbytes;
    }
    return argval;
}

D 18
#define BP_OP       O_BPT       /* breakpoint trap */
#define BP_ERRNO    SIGTRAP     /* signal received at a breakpoint */

E 18
/*
D 18
 * Setting a breakpoint at a location consists of saving
 * the word at the location and poking a BP_OP there.
 *
 * We save the locations and words on a list for use in unsetting.
 */

typedef struct Savelist *Savelist;

struct Savelist {
    Address location;
    Byte save;
    Byte refcount;
    Savelist link;
};

private Savelist savelist;

/*
 * Set a breakpoint at the given address.  Only save the word there
 * if it's not already a breakpoint.
 */

public setbp(addr)
Address addr;
{
    Byte w;
    Byte save;
    register Savelist newsave, s;

    for (s = savelist; s != nil; s = s->link) {
	if (s->location == addr) {
	    s->refcount++;
	    return;
	}
    }
D 6
    iread(&save, addr, sizeof(addr));
E 6
I 6
    iread(&save, addr, sizeof(save));
E 6
    newsave = new(Savelist);
    newsave->location = addr;
    newsave->save = save;
    newsave->refcount = 1;
    newsave->link = savelist;
    savelist = newsave;
    w = BP_OP;
    iwrite(&w, addr, sizeof(w));
}

/*
 * Unset a breakpoint; unfortunately we have to search the SAVELIST
 * to find the saved value.  The assumption is that the SAVELIST will
 * usually be quite small.
 */

public unsetbp(addr)
Address addr;
{
    register Savelist s, prev;

    prev = nil;
    for (s = savelist; s != nil; s = s->link) {
	if (s->location == addr) {
	    iwrite(&s->save, addr, sizeof(s->save));
	    s->refcount--;
	    if (s->refcount == 0) {
		if (prev == nil) {
		    savelist = s->link;
		} else {
		    prev->link = s->link;
		}
		dispose(s);
	    }
	    return;
	}
	prev = s;
    }
    panic("unsetbp: couldn't find address %d", addr);
D 14
}

/*
 * Predicate to test if the reason the process stopped was because
 * of a breakpoint.
 */

public Boolean isbperr()
{
    return (Boolean) (not isfinished(process) and errnum(process) == SIGTRAP);
E 14
}

/*
E 18
 * Enter a procedure by creating and executing a call instruction.
 */

#define CALLSIZE 7	/* size of call instruction */

public beginproc(p, argc)
Symbol p;
Integer argc;
{
    char save[CALLSIZE];
    struct {
	VaxOpcode op;
	unsigned char numargs;
	unsigned char mode;
	char addr[sizeof(long)];	/* unaligned long */
    } call;
    long dest;

    pc = 2;
    iread(save, pc, sizeof(save));
    call.op = O_CALLS;
    call.numargs = argc;
    call.mode = 0xef;
    dest = codeloc(p) - 2 - (pc + 7);
    mov(&dest, call.addr, sizeof(call.addr));
    iwrite(&call, pc, sizeof(call));
    setreg(PROGCTR, pc);
D 10
    pstep(process);
E 10
I 10
    pstep(process, DEFSIG);
E 10
    iwrite(save, pc, sizeof(save));
    pc = reg(PROGCTR);
    if (not isbperr()) {
	printstatus();
    }
I 16
}

/*
 * Special variables for debugging the kernel.
 */

public integer masterpcbb;
public integer slr;
public struct pte *sbr;
D 18
public struct pcb pcb;
E 18
I 18
private struct pcb pcb;
E 18

public getpcb ()
{
D 18
    fseek(corefile, physaddr(masterpcbb), 0);
E 18
I 18
    integer i;

    fseek(corefile, masterpcbb & ~0x80000000, 0);
E 18
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

public copyregs (savreg, reg)
Word savreg[], reg[];
{
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
}

/*
 * Map a virtual address to a physical address.
 */

public Address vmap (addr)
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
I 18
}

/*
 * Extract a bit field from an integer.
 */

public integer extractField (s)
Symbol s;
{
    integer n, nbytes, r;

    n = 0;
    nbytes = size(s);
    if (nbytes > sizeof(n)) {
	printf("[bad size in extractField -- word assumed]\n");
	nbytes = sizeof(n);
    }
    popn(nbytes, &n);
    r = n >> (s->symvalue.field.offset mod BITSPERBYTE);
    r &= ((1 << s->symvalue.field.length) - 1);
    return r;
}

/*
 * Change the length of a value in memory according to a given difference
 * in the lengths of its new and old types.
 */

public loophole (oldlen, newlen)
integer oldlen, newlen;
{
    integer n, i;

    n = newlen - oldlen;
    if (n > 0) {
	for (i = 0; i < n; i++) {
	    sp[i] = '\0';
	}
    }
    sp += n;
E 18
E 16
}
E 1
