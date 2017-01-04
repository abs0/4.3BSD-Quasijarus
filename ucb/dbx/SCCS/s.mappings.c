h48025
s 00018/00008/00356
d D 5.3 88/01/12 00:55:55 donn 10 9
c merge in latest Linton version
e
s 00003/00001/00361
d D 5.2 86/02/19 02:12:58 donn 9 8
c If we aren't looking for an exact addr vs. line match in findline(), and
c the addr is before the first source addr, let's assume it's legit and
c return the first source line.  This prevents the obnoxious 'second number
c must be greater than first' message after 'func foo; list' and function foo
c is the first function in the file.
e
s 00008/00002/00354
d D 5.1 85/05/31 10:06:05 dist 8 7
c Add copyright
e
s 00073/00021/00283
d D 1.6 85/03/01 20:25:46 linton 7 6
c update to version 3.0
e
s 00001/00003/00303
d D 1.5 84/06/23 11:41:46 sam 6 4
i 5
c merge linton branch delta trail
e
s 00003/00001/00303
d D 1.4.1.1 84/06/23 10:47:43 sam 5 4
c branch delta of linton changes from net.sources
e
s 00031/00027/00273
d D 1.4 83/08/10 03:47:05 linton 4 3
c changed functab to have an explicit address rather than being 
c the start of a procedure or function, this allows inline blocks to be 
c treated as functions
e
s 00015/00000/00285
d D 1.3 83/05/18 19:45:41 csvaf 3 2
c added dumpfunctab
e
s 00001/00001/00284
d D 1.2 82/12/15 04:20:57 linton 2 1
c fixed @(#) stuff
e
s 00285/00000/00000
d D 1.1 82/12/15 04:08:03 linton 1 0
c date and time created 82/12/15 04:08:03 by linton
e
u
U
f b 
t
T
I 1
D 8
/* Copyright (c) 1982 Regents of the University of California */
E 8
I 8
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 8

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 5
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
D 6
static char sccsid[] = "@(#)mappings.c 1.4 8/10/83";

static char rcsid[] = "$Header: mappings.c,v 1.3 84/03/27 10:21:54 linton Exp $";
E 6
I 6
D 8
static	char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8
E 6
E 5
E 2

I 7
D 10
static char rcsid[] = "$Header: mappings.c,v 1.4 84/12/26 10:40:25 linton Exp $";
E 10
I 10
static char rcsid[] = "$Header: mappings.c,v 1.3 87/03/26 19:41:55 donn Exp $";
E 10

E 7
/*
 * Source-to-object and vice versa mappings.
 */

#include "defs.h"
#include "mappings.h"
#include "symbols.h"
#include "source.h"
#include "object.h"
#include "machine.h"

#ifndef public
#include "machine.h"
#include "source.h"
#include "symbols.h"

typedef struct {
    Address addr;
    String filename;
    Lineno lineindex;		/* index to first linetab entry */
} Filetab;

typedef struct {
    Lineno line;
    Address addr;
} Linetab;

Filetab *filetab;
Linetab *linetab;

#define NOADDR ((Address) -1)	/* no address for line or procedure */

#endif

/*
 * Get the source file name associated with a given address.
 */

public String srcfilename(addr)
Address addr;
{
    register Address i, j, k;
    Address a;
    Filetab *ftp;
    String s;

    s = nil;
    if (nlhdr.nfiles != 0 and addr >= filetab[0].addr) {
	i = 0;
	j = nlhdr.nfiles - 1;
	while (i < j) {
	    k = (i + j) / 2;
	    ftp = &filetab[k];
	    a = ftp->addr;
	    if (a == addr) {
		s = ftp->filename;
		break;
	    } else if (addr > a) {
		i = k + 1;
	    } else {
		j = k - 1;
	    }
	}
	if (s == nil) {
	    if (addr >= filetab[i].addr) {
		s = filetab[i].filename;
	    } else {
		s = filetab[i-1].filename;
	    }
	}
    }
    return s;
}

/*
 * Find the line associated with the given address.
 * If the second parameter is true, then the address must match
 * a source line exactly.  Otherwise the nearest source line
D 7
 * below the given address is returned.  In any case, if no suitable
 * line exists, 0 is returned.
E 7
I 7
 * below the given address is returned.
 *
 * Return the index of the line table entry or -1 if none suitable.
E 7
 */

D 7
private Lineno findline(addr, exact)
E 7
I 7
private integer findline (addr, exact)
E 7
Address addr;
Boolean exact;
{
    register Address i, j, k;
    register Lineno r;
    register Address a;

D 9
    if (nlhdr.nlines == 0 or addr < linetab[0].addr) {
E 9
I 9
D 10
    if (nlhdr.nlines == 0) {
E 10
I 10
    if (nlhdr.nlines == 0 or addr < linetab[0].addr) {
E 10
E 9
D 7
	r = 0;
E 7
I 7
	r = -1;
I 9
D 10
    } else if (addr < linetab[0].addr) {
	r = exact ? -1 : 0;
E 10
E 9
E 7
    } else {
	i = 0;
	j = nlhdr.nlines - 1;
	if (addr == linetab[i].addr) {
D 7
	    r = linetab[i].line;
E 7
I 7
	    r = i;
E 7
	} else if (addr == linetab[j].addr) {
D 7
	    r = linetab[j].line;
E 7
I 7
	    r = j;
E 7
	} else if (addr > linetab[j].addr) {
D 7
	    r = exact ? 0 : linetab[j].line;
E 7
I 7
	    r = exact ? -1 : j;
E 7
	} else {
	    do {
		k = (i + j) div 2;
		a = linetab[k].addr;
	    if (a == addr) break;
		if (addr > a) {
		    i = k + 1;
		} else {
		    j = k - 1;
		}
	    } while (i <= j);
	    if (a == addr) {
D 7
		r = linetab[k].line;
E 7
I 7
		r = k;
E 7
	    } else if (exact) {
D 7
		r = 0;
E 7
I 7
		r = -1;
E 7
	    } else if (addr > linetab[i].addr) {
D 7
		r = linetab[i].line;
E 7
I 7
		r = i;
E 7
	    } else {
D 7
		r = linetab[i-1].line;
E 7
I 7
		r = i - 1;
E 7
	    }
	}
    }
    return r;
}

/*
D 7
 * Lookup the source line number nearest from below to an address.
E 7
I 7
 * Lookup the source line number nearest (from below) to an address.
 *
 * It is possible (unfortunately) that the compiler will generate
 * code before line number for a procedure.  Therefore we check
 * to see that the found line is in the same procedure as the given address.
 * If it isn't, then we walk forward until the first suitable line is found.
E 7
 */

D 10
public Lineno srcline(addr)
E 10
I 10
public Lineno srcline (addr)
E 10
Address addr;
{
D 7
    return findline(addr, false);
E 7
I 7
D 10
    integer i;
    Lineno r;
E 10
I 10
    Lineno i, r;
E 10
    Symbol f1, f2;
I 10
    Address a;
E 10

    i = findline(addr, false);
    if (i == -1) {
D 10
	r = 0;
E 10
I 10
	f1 = whatblock(addr);
	if (f1 == nil or nosource(f1)) {
	    r = 0;
	} else {
	    a = codeloc(f1);
	    for (;;) {
		r = linelookup(a);
		if (r != 0 or a >= CODESTART + objsize) {
		    break;
		}
		++a;
	    }
	}
E 10
    } else {
	r = linetab[i].line;
	if (linetab[i].addr != addr) {
	    f1 = whatblock(addr);
	    if (nosource(f1)) {
		r = 0;
	    } else {
		f2 = whatblock(linetab[i].addr + 1);
		if (f1 != f2) {
		    do {
			++i;
		    } while (linetab[i].addr < addr and i < nlhdr.nlines);
		    r = linetab[i].line;
		}
	    }
	}
    }
    return r;
E 7
}

/*
 * Look for a line exactly corresponding to the given address.
 */

public Lineno linelookup(addr)
Address addr;
{
D 7
    return findline(addr, true);
E 7
I 7
    integer i;
    Lineno r;

    i = findline(addr, true);
    if (i == -1) {
	r = 0;
    } else {
	r = linetab[i].line;
    }
    return r;
E 7
}

/*
 * Lookup the object address of a given line from the named file.
 *
 * Potentially all files in the file table need to be checked
 * until the line is found since a particular file name may appear
 * more than once in the file table (caused by includes).
 */

public Address objaddr(line, name)
Lineno line;
String name;
{
    register Filetab *ftp;
    register Lineno i, j;
    Boolean foundfile;

    if (nlhdr.nlines == 0) {
	return NOADDR;
    }
    if (name == nil) {
	name = cursource;
    }
    foundfile = false;
    for (ftp = &filetab[0]; ftp < &filetab[nlhdr.nfiles]; ftp++) {
	if (streq(ftp->filename, name)) {
	    foundfile = true;
	    i = ftp->lineindex;
	    if (ftp == &filetab[nlhdr.nfiles-1]) {
		j = nlhdr.nlines;
	    } else {
		j = (ftp + 1)->lineindex;
	    }
	    while (i < j) {
		if (linetab[i].line == line) {
		    return linetab[i].addr;
		}
		i++;
	    }
	}
    }
    if (not foundfile) {
D 7
	error("unknown source file \"%s\"", name);
E 7
I 7
	error("source file \"%s\" not compiled with -g", name);
E 7
    }
    return NOADDR;
}

/*
 * Table for going from object addresses to the functions in which they belong.
 */

D 7
#define MAXNFUNCS 1001      /* maximum number of functions allowed */
E 7
I 7
#define NFUNCS 500	/* initial size of function table */
E 7

D 4
private Symbol functab[MAXNFUNCS];
E 4
I 4
typedef struct {
    Symbol func;
    Address addr;
} AddrOfFunc;

D 7
private AddrOfFunc functab[MAXNFUNCS];
E 4
private int nfuncs;
E 7
I 7
private AddrOfFunc *functab;
private int nfuncs = 0;
private int functablesize = 0;
E 7

/*
 * Insert a new function into the table.
D 7
 * The table is ordered by object address.
E 7
 */

D 4
public newfunc(f)
E 4
I 4
public newfunc(f, addr)
E 4
Symbol f;
I 4
Address addr;
E 4
{
I 4
    register AddrOfFunc *af;
I 7
    register int i;
    AddrOfFunc *newfunctab;
E 7

E 4
D 7
    if (nfuncs >= MAXNFUNCS) {
	panic("too many procedures/functions");
E 7
I 7
    if (nfuncs >= functablesize) {
	if (functablesize == 0) {
	    functab = newarr(AddrOfFunc, NFUNCS);
	    functablesize = NFUNCS;
	} else {
	    functablesize *= 2;
	    newfunctab = newarr(AddrOfFunc, functablesize);
	    bcopy(functab, newfunctab, nfuncs * sizeof(AddrOfFunc));
	    dispose(functab);
	    functab = newfunctab;
	}
E 7
    }
D 4
    functab[nfuncs] = f;
E 4
I 4
    af = &functab[nfuncs];
    af->func = f;
    af->addr = addr;
E 4
    ++nfuncs;
}

/*
 * Return the function that begins at the given address.
 */

public Symbol whatblock(addr)
Address addr;
{
    register int i, j, k;
    Address a;

    i = 0;
    j = nfuncs - 1;
D 4
    if (addr < codeloc(functab[i])) {
E 4
I 4
    if (addr < functab[i].addr) {
E 4
	return program;
D 4
    } else if (addr == codeloc(functab[i])) {
	return functab[i];
    } else if (addr >= codeloc(functab[j])) {
	return functab[j];
E 4
I 4
    } else if (addr == functab[i].addr) {
	return functab[i].func;
    } else if (addr >= functab[j].addr) {
	return functab[j].func;
E 4
    }
    while (i <= j) {
	k = (i + j) / 2;
D 4
	a = codeloc(functab[k]);
E 4
I 4
	a = functab[k].addr;
E 4
	if (a == addr) {
D 4
	    return functab[k];
E 4
I 4
	    return functab[k].func;
E 4
	} else if (addr > a) {
	    i = k+1;
	} else {
	    j = k-1;
	}
    }
D 4
    if (addr > codeloc(functab[i])) {
	return functab[i];
E 4
I 4
    if (addr > functab[i].addr) {
	return functab[i].func;
E 4
    } else {
D 4
	return functab[i-1];
E 4
I 4
	return functab[i-1].func;
E 4
    }
    /* NOTREACHED */
}

/*
 * Order the functab.
 */

private int cmpfunc(f1, f2)
D 4
Symbol *f1, *f2;
E 4
I 4
AddrOfFunc *f1, *f2;
E 4
{
    register Address a1, a2;

D 4
    a1 = codeloc(*f1);
    a2 = codeloc(*f2);
E 4
I 4
    a1 = (*f1).addr;
    a2 = (*f2).addr;
E 4
    return ( (a1 < a2) ? -1 : ( (a1 == a2) ? 0 : 1 ) );
}

public ordfunctab()
{
D 4
    qsort(functab, nfuncs, sizeof(Symbol), cmpfunc);
E 4
I 4
    qsort(functab, nfuncs, sizeof(AddrOfFunc), cmpfunc);
E 4
}

/*
 * Clear out the functab, used when re-reading the object information.
 */

public clrfunctab()
{
    nfuncs = 0;
}
I 3

public dumpfunctab()
{
D 4
Symbol s;
int i;
E 4
I 4
    int i;
E 4

D 4
  for(i=0;i<nfuncs;i++) { 
	s=functab[i];
	printf( "%s %s %s %lx \n",
	classname(s),
	symname(s),
	(s->block == nil ? "noblock" : symname(s->block) ),
	codeloc(s) );
   }
E 4
I 4
    for (i = 0; i < nfuncs; i++) { 
	psym(functab[i].func);
    }
E 4
}
E 3
E 1
