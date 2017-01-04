h12870
s 00019/00015/00191
d D 5.2 87/04/07 15:53:33 mckusick 4 3
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00198
d D 5.1 85/06/06 08:19:06 dist 3 2
c Add copyright
e
s 00126/00122/00075
d D 1.2 82/02/10 00:24:42 linton 2 1
c the "con" operator was being incorrectly processed
e
s 00197/00000/00000
d D 1.1 82/01/18 19:20:24 linton 1 0
c date and time created 82/01/18 19:20:24 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 3

D 3
static char sccsid[] = "%Z%%M% %I% %G%";

E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3
/*
 * decode and print the instructions
 */

#include "defs.h"
#include "machine.h"
#include "process.h"
#include "pxops.h"
#include "optab.h"
#include "object.h"
I 4
#include "process/process.rep"
#include "process/pxinfo.h"
E 4

LOCAL ADDRESS printop(), docase();

/*
 * print instructions within the given address range
 */

printinst(lowaddr, highaddr)
ADDRESS lowaddr;
ADDRESS highaddr;
{
D 2
	register ADDRESS addr;
E 2
I 2
    register ADDRESS addr;
E 2

D 2
	for (addr = lowaddr; addr <= highaddr; ) {
		addr = printop(addr);
	}
E 2
I 2
    for (addr = lowaddr; addr <= highaddr; ) {
	addr = printop(addr);
    }
E 2
}

/*
D 4
 * print count instructions from given address
 */

printninst(count, addr)
int count;
ADDRESS addr;
{
D 2
	int i;
E 2
I 2
    int i;
E 2

D 2
	for (i = 0; i < count; i++) {
		addr = printop(addr);
	}
E 2
I 2
    for (i = 0; i < count; i++) {
	addr = printop(addr);
    }
E 2
}

/*
E 4
 * print the opcode at the given address, return the address
 * of the next instruction
 */

LOCAL ADDRESS printop(addr)
register ADDRESS addr;
{
D 2
	int i;
	PXOP op;
	OPTAB *o;
	char subop;
	short arg;
	long longarg;
	union {
		short i;
		struct { char c1, c2; } opword;
	} u;
E 2
I 2
    int i;
    PXOP op;
    OPTAB *o;
    char subop;
    short arg;
    long longarg;
    union {
	short i;
	struct { char c1, c2; } opword;
    } u;
E 2

D 2
	iread(&u.i, addr, sizeof(u.i));
	op = (PXOP) u.opword.c1;
	subop = u.opword.c2;
	o = &optab[op];
	printf("%5d   %s", addr, o->opname);
	addr += sizeof(u);
	for (i = 0; o->argtype[i] != 0; i++) {
		if (i == 0) {
			putchar('\t');
E 2
I 2
    iread(&u.i, addr, sizeof(u.i));
    op = (PXOP) u.opword.c1;
    subop = u.opword.c2;
    o = &optab[op];
    printf("%5d   %s", addr, o->opname);
    addr += sizeof(u);
    for (i = 0; o->argtype[i] != 0; i++) {
	if (i == 0) {
	    putchar('\t');
	} else {
	    putchar(',');
	}
	switch(o->argtype[i]) {
	    case ADDR4:
	    case LWORD:
I 4
#ifdef tahoe
		addr = (ADDRESS)(((int)addr + 3) & ~3);
#endif
E 4
		iread(&longarg, addr, sizeof(longarg));
		printf("%d", longarg);
		addr += sizeof(long);
		break;

	    case SUBOP:
		printf("%d", subop);
		break;

	    case ADDR2:
	    case DISP:
	    case PSUBOP:
	    case VLEN:
	    case HWORD:
		if (i != 0 || subop == 0) {
		    iread(&arg, addr, sizeof(arg));
		    addr += sizeof(short);
E 2
		} else {
D 2
			putchar(',');
E 2
I 2
		    arg = subop;
E 2
		}
D 2
		switch(o->argtype[i]) {
			case ADDR4:
			case LWORD:
				iread(&longarg, addr, sizeof(longarg));
				printf("%d", longarg);
				addr += sizeof(long);
				break;
E 2
I 2
		printf("%d", arg);
		break;
E 2

D 2
			case SUBOP:
				printf("%d", subop);
				break;
E 2
I 2
	    case STRING: {
		char c;
E 2

D 2
			case ADDR2:
			case DISP:
			case PSUBOP:
			case VLEN:
			case HWORD:
				if (i != 0 || subop == 0) {
					iread(&arg, addr, sizeof(arg));
					addr += sizeof(short);
				} else {
					arg = subop;
				}
				printf("%d", arg);
				break;

			case STRING: {
				char c;

				putchar('\'');
				while (subop > 0) {
					iread(&c, addr, sizeof(c));
					if (c == '\0') {
						break;
					}
					putchar(c);
					subop--;
					addr++;
				}
				addr++;
				putchar('\'');
				if ((addr&1) != 0) {
					addr++;
				}
				break;
			}

			default:
				panic("bad argtype %d", o->argtype[i]);
				/*NOTREACHED*/
E 2
I 2
		putchar('\'');
		while (subop > 0) {
		    iread(&c, addr, sizeof(c));
		    if (c == '\0') {
			break;
		    }
		    putchar(c);
		    subop--;
		    addr++;
E 2
		}
I 2
		addr++;
		putchar('\'');
I 4
#ifdef tahoe
		addr = (ADDRESS)(((int)addr + 3) & ~3);
#else
E 4
		if ((addr&1) != 0) {
		    addr++;
		}
I 4
#endif
E 4
		break;
	    }

	    default:
		panic("bad argtype %d", o->argtype[i]);
		/*NOTREACHED*/
E 2
	}
D 2
	switch(op) {
		case O_CASE1OP:
			addr = docase(addr, 1, subop);
			break;
E 2
I 2
    }
    switch(op) {
	case O_CON:
	    addr += arg;
I 4
#ifdef tahoe
	    addr = (ADDRESS)(((int)addr + 3) & ~3);
#endif
E 4
	    break;
E 2

D 2
		case O_CASE2OP:
			addr = docase(addr, 2, subop);
			break;
E 2
I 2
	case O_CASE1OP:
	    addr = docase(addr, 1, subop);
	    break;
E 2

D 2
		case O_CASE4OP:
			addr = docase(addr, 4, subop);
			break;
	}
	putchar('\n');
	return(addr);
E 2
I 2
	case O_CASE2OP:
	    addr = docase(addr, 2, subop);
	    break;

	case O_CASE4OP:
	    addr = docase(addr, 4, subop);
	    break;
    }
    putchar('\n');
    return(addr);
E 2
}

/*
 * print out the destinations and cases
 */

LOCAL ADDRESS docase(addr, size, n)
ADDRESS addr;
int size;
int n;
{
D 2
	register int i;
	char c;
	short arg;
	long longarg;
E 2
I 2
    register int i;
    char c;
    short arg;
    long longarg;
E 2

I 2
    iread(&arg, addr, sizeof(arg));
    printf("\n\t%5d", arg);
    addr += 2;
    for (i = 1; i < n; i++) {
E 2
	iread(&arg, addr, sizeof(arg));
D 2
	printf("\n\t%5d", arg);
E 2
I 2
	printf(", %5d", arg);
E 2
	addr += 2;
D 2
	for (i = 1; i < n; i++) {
E 2
I 2
    }
    printf("\n\t");
    for (i = 0; i < n; i++) {
	switch(size) {
	    case 1:
		iread(&c, addr, sizeof(c));
		printf("%5d", c);
		break;

	    case 2:
E 2
		iread(&arg, addr, sizeof(arg));
D 2
		printf(", %5d", arg);
		addr += 2;
	}
	printf("\n\t");
	for (i = 0; i < n; i++) {
		switch(size) {
			case 1:
				iread(&c, addr, sizeof(c));
				printf("%5d", c);
				break;
E 2
I 2
		printf("%5d", arg);
		break;
E 2

D 2
			case 2:
				iread(&arg, addr, sizeof(arg));
				printf("%5d", arg);
				break;

			case 4:
				iread(&longarg, addr, sizeof(longarg));
				printf("%5d", longarg);
				break;
		}
		addr += size;
		if (i < n - 1) {
			printf(", ");
		}
E 2
I 2
	    case 4:
I 4
#ifdef tahoe
		addr = (ADDRESS)(((int)addr + 3) & ~3);
#endif
E 4
		iread(&longarg, addr, sizeof(longarg));
		printf("%5d", longarg);
		break;
E 2
	}
D 2
	if ((addr&01) == 01) {
		addr++;
E 2
I 2
	addr += size;
	if (i < n - 1) {
	    printf(", ");
E 2
	}
D 2
	return(addr);
E 2
I 2
    }
I 4
#ifdef tahoe
    addr = (ADDRESS)(((int)addr + 3) & ~3);
#else
E 4
    if ((addr&01) == 01) {
	addr++;
    }
I 4
#endif
E 4
    return(addr);
E 2
}
E 1
