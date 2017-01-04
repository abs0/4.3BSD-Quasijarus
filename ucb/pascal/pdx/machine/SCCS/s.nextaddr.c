h13618
s 00079/00051/00322
d D 5.2 87/04/07 15:53:29 mckusick 6 5
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00365
d D 5.1 85/06/06 08:17:16 dist 5 4
c Add copyright
e
s 00014/00000/00354
d D 1.4 82/03/08 19:31:37 linton 4 3
c added function "isendofproc" to test for END op
e
s 00004/00005/00350
d D 1.3 82/02/17 00:28:18 linton 3 2
c changed the default for the FOR operator -- now for loops are 
c traced through every iteration, this is painful but makes more sense to 
c the users
e
s 00257/00244/00098
d D 1.2 82/02/10 00:24:27 linton 2 1
c the "con" operator was being incorrectly processed
e
s 00342/00000/00000
d D 1.1 82/01/18 19:20:21 linton 1 0
c date and time created 82/01/18 19:20:21 by linton
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1982 Regents of the University of California */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5

D 5
static char sccsid[] = "%Z%%M% %I% %G%";

E 5
I 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
I 6

E 6
E 5
/*
 * Calculate the next address that will be executed from the current one.
 *
 * If the next address depends on runtime data (e.g. a conditional
 * branch will depend on the value on top of the stack),
 * we must execute up to the given address with "stepto".
 *
 * If the second argument is TRUE, we treat a CALL instruction as
 * straight line rather than following it as a branch.
 */

#include "defs.h"
#include "machine.h"
#include "process.h"
#include "breakpoint.h"
#include "sym.h"
#include "pxops.h"
#include "optab.h"
#include "mappings.h"
#include "runtime.h"
#include "process/pxinfo.h"
#include "process/process.rep"

I 6
#ifdef tahoe
#define EVEN 3
#else
#define EVEN 1
#endif

E 6
LOCAL ADDRESS docase(), dofor();

ADDRESS nextaddr(beginaddr, isnext)
ADDRESS beginaddr;
BOOLEAN isnext;
{
D 2
	register PXOP op;
	ADDRESS addr;
	short offset;
	int nextbyte;
	SYM *s;
	union {
		short word;
		char byte[2];
	} o;
E 2
I 2
    register PXOP op;
    ADDRESS addr;
    short offset;
    int nextbyte;
    SYM *s;
    union {
	short word;
	char byte[2];
    } o;
E 2

I 6
#ifdef tahoe
    doret(process);
#endif
E 6
D 2
	addr = beginaddr;
	iread(&o.word, addr, sizeof(o.word));
	op = (PXOP) o.byte[0];
	nextbyte = o.byte[1];
	addr += sizeof(short);
	switch(op) {
E 2
I 2
    addr = beginaddr;
    iread(&o.word, addr, sizeof(o.word));
    op = (PXOP) o.byte[0];
    nextbyte = o.byte[1];
    addr += sizeof(short);
    switch(op) {
E 2

D 2
#	if (isvaxpx)
	/*
	 * The version of px on the VAX assumes that the instruction
	 * at the entry point of a function is a TRA4 to the beginning
	 * of the block.
	 */
#	endif
		case O_CALL: {
			ADDRESS eaddr;
E 2
I 2
D 6
#   if (isvaxpx)
E 6
    /*
D 6
     * The version of px on the VAX assumes that the instruction
E 6
I 6
     * The version of px we are using assumes that the instruction
E 6
     * at the entry point of a function is a TRA4 to the beginning
     * of the block.
     */
D 6
#   endif
E 6
	case O_CALL: {
	    ADDRESS eaddr;
E 2

D 2
			if (isnext) {
				addr += sizeof(int);
			} else {
#				if (isvaxpx)
					iread(&eaddr, addr, sizeof(eaddr));
					addr = eaddr + sizeof(short);
					iread(&addr, addr, sizeof(addr));
#				else
					iread(&offset, addr, sizeof(offset));
					addr += offset;
#				endif
				stepto(addr);
				if (linelookup(addr) == 0) {
					bpact();
					addr = pc;
				}
				if (ss_lines && trcond()) {
					s = whatblock(addr);
					if (s == NIL) {
						panic("bad call addr");
					}
					printentry(s);
				}
			}
			break;
E 2
I 2
	    if (isnext) {
		addr += sizeof(int);
I 6
#ifdef tahoe
	        addr = (ADDRESS)(((int)addr + EVEN) & ~EVEN);
#endif
E 6
	    } else {
D 6
#               if (isvaxpx)
		    iread(&eaddr, addr, sizeof(eaddr));
		    addr = eaddr + sizeof(short);
		    iread(&addr, addr, sizeof(addr));
#               else
		    iread(&offset, addr, sizeof(offset));
		    addr += offset;
#               endif
E 6
I 6
#ifdef tahoe
		addr = (ADDRESS)(((int)addr + EVEN) & ~EVEN);
#endif
		iread(&eaddr, addr, sizeof(eaddr));
		addr = eaddr + sizeof(short);
#ifdef tahoe
		addr = (ADDRESS)(((int)addr + EVEN) & ~EVEN);
#endif
		iread(&addr, addr, sizeof(addr));
E 6
		stepto(addr);
		if (linelookup(addr) == 0) {
		    bpact();
		    addr = pc;
E 2
		}
I 2
		if (ss_lines && trcond()) {
		    s = whatblock(addr);
		    if (s == NIL) {
			panic("bad call addr");
		    }
		    printentry(s);
		}
	    }
	    break;
	}
E 2

D 2
#	if (isvaxpx)
		case O_FCALL: {
			ADDRESS eaddr;
			ADDRESS *fparam;
E 2
I 2
D 6
#   if (isvaxpx)
E 6
	case O_FCALL: {
	    ADDRESS eaddr;
	    ADDRESS *fparam;
E 2

D 2
			if (!isnext) {
				stepto(addr - sizeof(short));
				dread(&fparam, process->sp + sizeof(ADDRESS), sizeof(fparam));
				dread(&eaddr, fparam, sizeof(eaddr));
				addr = eaddr - ENDOFF;
				stepto(addr);
				if (linelookup(addr) == 0) {
					bpact();
					addr = pc;
				}
				if (ss_lines && trcond()) {
					s = whatblock(addr);
					if (s == NIL) {
						panic("bad call addr");
					}
					printentry(s);
				}
			}
			break;
E 2
I 2
	    if (!isnext) {
		stepto(addr - sizeof(short));
I 6
#ifdef tahoe
		doret(process);
#endif
E 6
		dread(&fparam, process->sp + sizeof(ADDRESS), sizeof(fparam));
		dread(&eaddr, fparam, sizeof(eaddr));
		addr = eaddr - ENDOFF;
		stepto(addr);
I 6
#ifdef tahoe
		doret(process);
#endif
E 6
		if (linelookup(addr) == 0) {
		    bpact();
		    addr = pc;
E 2
		}
D 2
#	endif
E 2
I 2
		if (ss_lines && trcond()) {
		    s = whatblock(addr);
		    if (s == NIL) {
			panic("bad call addr");
		    }
		    printentry(s);
		}
	    }
	    break;
	}
D 6
#   endif
E 6
E 2

D 2
		case O_END:
			if ((addr - sizeof(short)) == lastaddr()) {
				stepto(addr - sizeof(short));
				endprogram();
			} else {
				addr = return_addr();
				s = whatblock(pc);
				stepto(addr);
				if (ss_lines && trcond()) {
					printexit(s);
				}
				if (linelookup(addr) == 0) {
					bpact();
					addr = pc;
				}
			}
			break;
E 2
I 2
	case O_END:
	    if ((addr - sizeof(short)) == lastaddr()) {
		stepto(addr - sizeof(short));
		endprogram();
	    } else {
		addr = return_addr();
		s = whatblock(pc);
		stepto(addr);
		if (ss_lines && trcond()) {
		    printexit(s);
		}
		if (linelookup(addr) == 0) {
		    bpact();
		    addr = pc;
		}
	    }
	    break;
E 2

D 2
#	if (isvaxpx)
		case O_TRA4:
		case O_GOTO:
			iread(&addr, addr, sizeof(addr));
			break;
#	endif
E 2
I 2
D 6
#   if (isvaxpx)
E 6
	case O_TRA4:
	case O_GOTO:
I 6
#ifdef tahoe
	    addr = (ADDRESS)(((int)addr + EVEN) & ~EVEN);
#endif
E 6
	    iread(&addr, addr, sizeof(addr));
	    break;
D 6
#   endif
E 6
E 2

D 2
		case O_TRA:
			iread(&offset, addr, sizeof(offset));
			addr += offset;
			break;
E 2
I 2
	case O_TRA:
	    iread(&offset, addr, sizeof(offset));
	    addr += offset;
	    break;
E 2

D 2
		case O_CASE1OP:
			addr = docase(nextbyte, 1, addr);
			break;
E 2
I 2
	case O_CON: {
	    short consize;
E 2

D 2
		case O_CASE2OP:
			addr = docase(nextbyte, 2, addr);
			break;
E 2
I 2
	    if (nextbyte == 0) {
I 6
#ifdef tahoe
	        addr = (ADDRESS)(((int)addr + EVEN) & ~EVEN);
#endif
E 6
		iread(&consize, addr, sizeof(consize));
		addr += sizeof(consize);
	    } else {
		consize = nextbyte;
	    }
	    addr += consize;
	    break;
	}
E 2

D 2
		case O_CASE4OP:
			addr = docase(nextbyte, 4, addr);
			break;
E 2
I 2
	case O_CASE1OP:
	    addr = docase(nextbyte, 1, addr);
	    break;
E 2

D 2
		case O_FOR1U:
			addr = dofor(2, addr, nextbyte, 1);
			break;
E 2
I 2
	case O_CASE2OP:
	    addr = docase(nextbyte, 2, addr);
	    break;
E 2

D 2
		case O_FOR2U:
			addr = dofor(2, addr, nextbyte, 1);
			break;
E 2
I 2
	case O_CASE4OP:
	    addr = docase(nextbyte, 4, addr);
	    break;
E 2

D 2
		case O_FOR4U:
			addr = dofor(4, addr, nextbyte, 1);
			break;
E 2
I 2
	case O_FOR1U:
	    addr = dofor(2, addr, nextbyte, 1);
	    break;
E 2

D 2
		case O_FOR1D:
			addr = dofor(2, addr, nextbyte, -1);
			break;
E 2
I 2
	case O_FOR2U:
	    addr = dofor(2, addr, nextbyte, 1);
	    break;
E 2

D 2
		case O_FOR2D:
			addr = dofor(2, addr, nextbyte, -1);
			break;
E 2
I 2
	case O_FOR4U:
	    addr = dofor(4, addr, nextbyte, 1);
	    break;
E 2

D 2
		case O_FOR4D:
			addr = dofor(4, addr, nextbyte, -1);
			break;
E 2
I 2
	case O_FOR1D:
	    addr = dofor(2, addr, nextbyte, -1);
	    break;
E 2

D 2
		case O_IF:
			stepto(addr - sizeof(short));
			dread(&offset, process->sp, sizeof(offset));
			if (offset == 0) {
				iread(&offset, addr, sizeof(offset));
				addr += offset;
			} else {
				addr += sizeof(offset);
			}
			break;
E 2
I 2
	case O_FOR2D:
	    addr = dofor(2, addr, nextbyte, -1);
	    break;
E 2

D 2
		default: {
#	if (isvaxpx)
			int i;
E 2
I 2
	case O_FOR4D:
	    addr = dofor(4, addr, nextbyte, -1);
	    break;
E 2

D 2
			for (i = 0; optab[op].argtype[i] != 0; i++) {
				switch(optab[op].argtype[i]) {
					case ADDR4:
					case LWORD:
						addr += 4;
						break;
E 2
I 2
	case O_IF:
	    stepto(addr - sizeof(short));
I 6
#ifdef tahoe
	    doret(process);
	    dread(&offset, process->sp+sizeof(int)-sizeof(offset), sizeof(offset));
#else
E 6
	    dread(&offset, process->sp, sizeof(offset));
I 6
#endif
E 6
	    if (offset == 0) {
		iread(&offset, addr, sizeof(offset));
		addr += offset;
	    } else {
		addr += sizeof(offset);
	    }
	    break;
E 2

D 2
					case SUBOP:
						break;
E 2
I 2
	default: {
D 6
#   if (isvaxpx)
E 6
	    int i;
E 2

D 2
					case ADDR2:
					case HWORD:
					case PSUBOP:
					case DISP:
					case VLEN:
						if (i != 0 || nextbyte == 0) {
							addr += sizeof(short);
						}
						break;
E 2
I 2
	    for (i = 0; optab[op].argtype[i] != 0; i++) {
		switch(optab[op].argtype[i]) {
		    case ADDR4:
		    case LWORD:
			addr += 4;
I 6
#ifdef tahoe
		        addr = (ADDRESS)(((int)addr + EVEN) & ~EVEN);
#endif
E 6
			break;
E 2

D 2
					case STRING: {
						char c;
E 2
I 2
		    case SUBOP:
			break;
E 2

D 2
						while (nextbyte > 0) {
							iread(&c, addr, 1);
							if (c == '\0') {
								break;
							}
							nextbyte--;
							addr++;
						}
						addr++;
						if ((addr&1) != 0) {
							addr++;
						}
						break;
					}

					default:
						panic("bad argtype");
						/*NOTREACHED*/
				}
E 2
I 2
		    case ADDR2:
		    case HWORD:
		    case PSUBOP:
		    case DISP:
		    case VLEN:
			if (i != 0 || nextbyte == 0) {
			    addr += sizeof(short);
E 2
			}
D 2
#	else
			int oplen;
E 2
I 2
			break;
E 2

D 2
			oplen = optab[op].nargs;
			if (oplen < 0) {
				oplen = (-oplen) - 1;
			} else  if (oplen > 0 && nextbyte != 0) {
				oplen--;
			}
			oplen *= sizeof(int);
			switch (op) {
				case O_BEG:
				case O_NODUMP:
					oplen += 10;
					break;
E 2
I 2
		    case STRING: {
			char c;
E 2

D 2
				case O_CON:
					oplen += ((nextbyte + 1)&~1);
					break;
E 2
I 2
			while (nextbyte > 0) {
			    iread(&c, addr, 1);
			    if (c == '\0') {
				break;
			    }
			    nextbyte--;
			    addr++;
E 2
			}
D 2
			addr += oplen;
#	endif
E 2
I 2
			addr++;
D 6
			if ((addr&1) != 0) {
			    addr++;
			}
E 6
I 6
		        addr = (ADDRESS)(((int)addr + EVEN) & ~EVEN);
E 6
E 2
			break;
I 2
		    }

		    default:
			panic("bad argtype");
			/*NOTREACHED*/
E 2
		}
I 2
	    }
D 6
#   else
	    int oplen;

	    oplen = optab[op].nargs;
	    if (oplen < 0) {
		oplen = (-oplen) - 1;
	    } else  if (oplen > 0 && nextbyte != 0) {
		oplen--;
	    }
	    oplen *= sizeof(int);
	    switch (op) {
		case O_BEG:
		case O_NODUMP:
		    oplen += 10;
		    break;

		case O_CON:
		    oplen += ((nextbyte + 1)&~1);
		    break;
	    }
	    addr += oplen;
#   endif
E 6
	    break;
E 2
	}
D 2
	return addr;
E 2
I 2
    }
    return addr;
E 2
}

/*
 * Find the next address that will be executed after the
 * case statement at the given address.
 */

LOCAL ADDRESS docase(ncases, size, addr)
int ncases;
int size;
ADDRESS addr;
{
D 2
	register ADDRESS i;
	ADDRESS firstval, lastval, jmptable;
	short offset;
	long swtval, caseval;
E 2
I 2
    register ADDRESS i;
    ADDRESS firstval, lastval, jmptable;
    short offset;
    long swtval, caseval;
E 2

D 2
	stepto(addr - 2);
	if (ncases == 0) {
		iread(&ncases, addr, sizeof(ncases));
		addr += sizeof(short);
E 2
I 2
    stepto(addr - 2);
I 6
#ifdef tahoe
    doret(process);
#endif
E 6
    if (ncases == 0) {
	iread(&ncases, addr, sizeof(ncases));
	addr += sizeof(short);
    }
    jmptable = addr;
    firstval = jmptable + ncases*sizeof(short);
I 6
#ifdef tahoe
    if (size == 4) {
	firstval = (ADDRESS)(((int)firstval + EVEN) & ~EVEN);
    }
#endif
E 6
    lastval = firstval + ncases*size;
I 6
#ifdef tahoe
    if (size <= 4) {
	dread(&swtval, process->sp, 4);
#else
E 6
    if (size <= 2) {
	dread(&swtval, process->sp, 2);
I 6
#endif
E 6
    } else {
	dread(&swtval, process->sp, size);
    }
    for (i = firstval; i < lastval; i += size) {
I 6
	caseval = 0;
#ifdef tahoe
	iread((char *)&caseval + sizeof caseval - size, i, size);
	if (swtval == caseval)
#else
E 6
	iread(&caseval, i, size);
D 6
	if (cmp(&swtval, &caseval, size) == 0) {
E 6
I 6
	if (cmp(&swtval, &caseval, size) == 0)
#endif
	{
E 6
	    i = ((i - firstval) / size) * sizeof(offset);
	    iread(&offset, jmptable + i, sizeof(offset));
	    addr = jmptable + offset;
	    return addr;
E 2
	}
D 2
	jmptable = addr;
	firstval = jmptable + ncases*sizeof(short);
	lastval = firstval + ncases*size;
	if (size <= 2) {
		dread(&swtval, process->sp, 2);
	} else {
		dread(&swtval, process->sp, size);
	}
	for (i = firstval; i < lastval; i += size) {
		iread(&caseval, i, size);
		if (cmp(&swtval, &caseval, size) == 0) {
			i = ((i - firstval) / size) * sizeof(offset);
			iread(&offset, jmptable + i, sizeof(offset));
			addr = jmptable + offset;
			return addr;
		}
	}
	return((lastval+1)&~1);
E 2
I 2
    }
    return((lastval+1)&~1);
E 2
}

LOCAL ADDRESS dofor(size, addr, subop, incr)
int size;
ADDRESS addr;
short subop;
int incr;
{
D 2
	register PROCESS *p;
	long i, limit, lower;
	ADDRESS valaddr;
	short offset;
E 2
I 2
    register PROCESS *p;
D 6
    long i, limit, lower;
E 6
I 6
    long i, limit;
E 6
    ADDRESS valaddr;
D 6
    short offset;
E 6
E 2

D 2
	stepto(addr - sizeof(short));
	p = process;
	i = limit = 0;
	if (subop == 0) {
		addr += size;
	}
	dread(&valaddr, p->sp, sizeof(valaddr));
	dread(&i, valaddr, size);
	dread(&limit, p->sp + sizeof(valaddr), size);
	i += (incr << (8*(sizeof(i) - size)));
E 2
I 2
    stepto(addr - sizeof(short));
    p = process;
I 6
#ifdef tahoe
    doret(p);
#endif
E 6
    i = limit = 0;
    if (subop == 0) {
E 2
D 6
	addr += size;
E 6
I 6
	dread(&subop, addr, sizeof (short));
	addr += sizeof (short);
E 6
I 2
    }
    dread(&valaddr, p->sp, sizeof(valaddr));
I 6
#ifdef tahoe
    dread((char *)&i + sizeof i - size, valaddr, size);
#else
E 6
    dread(&i, valaddr, size);
D 6
    dread(&limit, p->sp + sizeof(valaddr), size);
    i += (incr << (8*(sizeof(i) - size)));
    addr += size;
E 6
I 6
#endif
    dread(&limit, p->sp + sizeof(valaddr), sizeof limit);
    i += incr;
E 6
I 3

E 3
E 2
/*
 * It is very slow to go through the loop again and again.
D 3
 * So for the time being, we just skip to the end.
 *
E 3
I 3
 * If it is desired to just skip to the end, the next 4 lines
 * should be skipped.
 */
E 3
D 2
	if ((incr > 0 && i < limit) || (incr < 0 && i > limit)) {
		iread(&offset, addr, sizeof(offset));
		return(addr + offset);
	} else {
E 2
I 2
    if ((incr > 0 && i < limit) || (incr < 0 && i > limit)) {
D 6
	iread(&offset, addr, sizeof(offset));
	return(addr + offset);
E 6
I 6
	return(addr + subop);
E 6
    } else {
E 2
D 3
 */
E 3
D 2
		return(addr + sizeof(short));
E 2
I 2
D 6
	return(addr + sizeof(short));
E 6
I 6
	return(addr);
E 6
E 2
D 3
/*
E 3
D 2
	}
E 2
I 2
    }
E 2
D 3
 */
E 3
}
I 4

/*
 * Determine whether or not the given address corresponds to the
 * end of a procedure.
 */

BOOLEAN isendofproc(addr)
ADDRESS addr;
{
    PXOP op;

    iread(&op, addr, sizeof(op));
    return (op == O_END);
}
E 4
E 1
