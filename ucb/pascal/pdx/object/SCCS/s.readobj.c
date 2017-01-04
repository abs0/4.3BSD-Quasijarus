h48117
s 00008/00002/00245
d D 5.1 85/06/07 20:12:20 mckusick 7 6
c Add copyright
e
s 00002/00002/00245
d D 1.6 83/03/24 16:40:06 linton 6 5
c upped some limits for large programs (> 10000 lines)
e
s 00006/00004/00241
d D 1.5 82/05/19 17:45:13 linton 5 4
c fixed problem with file lineindex pointing after last line table entry
e
s 00140/00142/00105
d D 1.4 82/02/10 00:23:36 linton 4 3
c Uses new objsym.rep to read raw line number information
e
s 00021/00002/00226
d D 1.3 82/02/02 12:46:08 linton 3 2
c added -h option for debugging to print out header sizes
e
s 00006/00003/00222
d D 1.2 82/01/19 01:35:59 linton 2 1
c replaced use of SIZELOC and BASEADDR with info in "objfmt.h"
e
s 00225/00000/00000
d D 1.1 82/01/18 19:20:41 linton 1 0
c date and time created 82/01/18 19:20:41 by linton
e
u
U
t
T
I 1
D 7
/* Copyright (c) 1982 Regents of the University of California */
E 7
I 7
/*
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 7

D 7
static char sccsid[] = "%Z%%M% %I% %G%";
E 7
I 7
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7

/*
 * Read in the namelist from the obj file.
 */

#include "defs.h"
#include "sym.h"
#include "symtab.h"
#include "object.h"
I 2
#include "objfmt.h"
I 3
#include "main.h"
E 3
E 2
#include "mappings.h"
#include "mappings/filetab.h"
#include "mappings/linetab.h"
I 4
#include "objsym.rep"
E 4

D 6
#define MAXSYMNO 2000
E 6
I 6
#define MAXSYMNO 6000
E 6

char *objname = "obj";

LOCAL SYM *sym[MAXSYMNO];

readobj(file)
char *file;
{
D 4
	register FILE *fp;
I 2
	struct pxhdr hdr;
E 4
I 4
    register FILE *fp;
    struct pxhdr hdr;
E 4
E 2

D 4
	if ((fp = fopen(file, "r")) == NIL) {
		panic("can't open %s", file);
	}
E 4
I 4
    if ((fp = fopen(file, "r")) == NIL) {
	panic("can't open %s", file);
    }
    get(fp, hdr);
    if (hdr.magicnum != MAGICNUM) {
	fseek(fp, (long) (HEADER_BYTES - sizeof(struct pxhdr)), 0);
E 4
D 2
	fseek(fp, (long) SIZELOC, 0);
	objsize = getw(fp);
	fseek(fp, (long) objsize + 4, 1);
E 2
I 2
D 3
	fseek(fp, (long) (HEADER_BYTES - sizeof(struct pxhdr)), 0);
E 3
	get(fp, hdr);
I 3
	if (hdr.magicnum != MAGICNUM) {
D 4
		fseek(fp, (long) (HEADER_BYTES - sizeof(struct pxhdr)), 0);
		get(fp, hdr);
		if (hdr.magicnum != MAGICNUM) {
			fatal("%s is not a Pascal object file", file);
		}
E 4
I 4
	    fatal("%s is not a Pascal object file", file);
E 4
	}
D 4
	if (hdr.symtabsize == 0) {
		fatal("%s doesn't have symbolic information", file);
	}
E 3
	objsize = hdr.objsize;
	fseek(fp, (long) objsize, 1);
E 2
	if (get(fp, nlhdr) != 1) {
D 3
		panic("readobj:  get failed");
E 3
I 3
		panic("can't read nlhdr");
	}
	if (option('h')) {
		printf("\nHeader information:\n");
		printf("\tobject size %d\n", objsize);
		printf("\tsymtab size %d\n", hdr.symtabsize);
		printf("\tstringsize  %d\n", nlhdr.stringsize);
		printf("\tnsyms       %d\n", nlhdr.nsyms);
		printf("\tnfiles      %d\n", nlhdr.nfiles);
		printf("\tnlines      %d\n", nlhdr.nlines);
E 3
	}
	stringtab = alloc(nlhdr.stringsize, char);
	fread(stringtab, sizeof(char), nlhdr.stringsize, fp);
	readsyms(fp);
	readfiles(fp);
	readlines(fp);
	fclose(fp);
E 4
I 4
    }
    if (hdr.symtabsize == 0) {
	fatal("%s doesn't have symbolic information", file);
    }
    objsize = hdr.objsize;
    fseek(fp, (long) objsize, 1);
    if (get(fp, nlhdr) != 1) {
	panic("can't read nlhdr");
    }
    if (option('h')) {
	printf("\nHeader information:\n");
	printf("\tobject size %d\n", objsize);
	printf("\tsymtab size %d\n", hdr.symtabsize);
	printf("\tstringsize  %d\n", nlhdr.stringsize);
	printf("\tnsyms       %d\n", nlhdr.nsyms);
	printf("\tnfiles      %d\n", nlhdr.nfiles);
	printf("\tnlines      %d\n", nlhdr.nlines);
    }
    stringtab = alloc(nlhdr.stringsize, char);
    fread(stringtab, sizeof(char), nlhdr.stringsize, fp);
    readsyms(fp);
    readfiles(fp);
    readlines(fp);
    fclose(fp);
E 4
}

/*
D 5
 * allocate and read in file name information table
E 5
I 5
 * Allocate and read in file name information table.
E 5
 */

LOCAL readfiles(fp)
register FILE *fp;
{
D 4
	register int i;
	register FILETAB *ftp;
	FILETAB temp;
	ADDRESS prevaddr;
E 4
I 4
    register int i;
    register FILETAB *ftp;
    FILETAB temp;
    ADDRESS prevaddr;
E 4

D 4
	filetab = alloc(nlhdr.nfiles, FILETAB);
	ftp = &filetab[0];
	prevaddr = 0;
	for (i = 0; i < nlhdr.nfiles; i++) {
		fread(&temp, sizeof(FILETAB), 1, fp);
		if (temp.addr != prevaddr) {
			ftp++;
		}
		*ftp = temp;
		ftp->filename += (int) stringtab;
		prevaddr = ftp->addr;
E 4
I 4
    filetab = alloc(nlhdr.nfiles, FILETAB);
    ftp = &filetab[0];
    prevaddr = 0;
    for (i = 0; i < nlhdr.nfiles; i++) {
	fread(&temp, sizeof(FILETAB), 1, fp);
	if (temp.addr != prevaddr) {
	    ftp++;
E 4
	}
D 4
	nlhdr.nfiles = (ftp - &filetab[0]) + 1;
	skimsource(filetab[0].filename);
	dotpfile = filetab[0].filename;
E 4
I 4
	*ftp = temp;
	ftp->filename += (int) stringtab;
	prevaddr = ftp->addr;
    }
    nlhdr.nfiles = (ftp - &filetab[0]) + 1;
    skimsource(filetab[0].filename);
    dotpfile = filetab[0].filename;
E 4
}

/*
D 5
 * allocate and read in line number information table
E 5
I 5
 * Allocate and read in line number information table.
E 5
 */

LOCAL readlines(fp)
FILE *fp;
{
D 4
	register LINENO oline;
	register ADDRESS oaddr;
	register LINETAB *lp;
	FILETAB *ftp;
	short lineincr;
E 4
I 4
    register LINENO oline;
    register ADDRESS oaddr;
    register LINETAB *lp;
    FILETAB *ftp;
    OBJLINE info;
E 4

D 4
	if (nlhdr.nlines == 0) {
		return;
E 4
I 4
    if (nlhdr.nlines == 0) {
	return;
    }
    linetab = alloc(nlhdr.nlines, LINETAB);
    for (lp = &linetab[0]; lp < &linetab[nlhdr.nlines]; lp++) {
	lp->line = 0;
    }
    for (ftp = &filetab[0]; ftp < &filetab[nlhdr.nfiles]; ftp++) {
D 5
	linetab[ftp->lineindex].line = ftp->line;
E 5
I 5
	if (ftp->lineindex < nlhdr.nlines) {
	    linetab[ftp->lineindex].line = ftp->line;
	}
E 5
    }
    oline = 0;
    oaddr = 0;
    for (lp = &linetab[0]; lp < &linetab[nlhdr.nlines]; lp++) {
	if (lp->line != 0) {
	    oline = lp->line;
E 4
	}
D 4
	linetab = alloc(nlhdr.nlines, LINETAB);
	for (lp = &linetab[0]; lp < &linetab[nlhdr.nlines]; lp++) {
		lp->line = 0;
	}
	for (ftp = &filetab[0]; ftp < &filetab[nlhdr.nfiles]; ftp++) {
		linetab[ftp->lineindex].line = ftp->line;
	}
	oline = 0;
	oaddr = 0;
	for (lp = &linetab[0]; lp < &linetab[nlhdr.nlines]; lp++) {
		if (lp->line != 0) {
			oline = lp->line;
		}
		lineincr = (unsigned) getc(fp);
		if (lineincr > 127) {
			lineincr -= 256;
		}
		oline += lineincr;
		oaddr += (unsigned) getc(fp);
		lp->line = oline;
		lp->addr = oaddr;
	}
E 4
I 4
	info.together = getw(fp);
	oline += info.separate.lineincr;
	oaddr += info.separate.addrincr;
	lp->line = oline;
	lp->addr = oaddr;
    }
E 4
}

/*
D 5
 * read in the symbols
E 5
I 5
 * Read in the symbols.
E 5
 */

readsyms(fp)
FILE *fp;
{
D 4
	register int i;
	int symno;
E 4
I 4
    register int i;
    int symno;
E 4

D 4
	symtab = st_creat(nlhdr.nsyms);
	for (i = 0; i < nlhdr.nsyms; i++) {
		symno = getw(fp);
		if (symno >= MAXSYMNO) {
			panic("symbol number too large");
		}
		sym[symno] = readsym(fp);
E 4
I 4
    symtab = st_creat(nlhdr.nsyms);
    for (i = 0; i < nlhdr.nsyms; i++) {
	symno = getw(fp);
	if (symno >= MAXSYMNO) {
D 6
	    panic("symbol number too large");
E 6
I 6
	    panic("symbol number too large (%d)", symno);
E 6
E 4
	}
D 4
	if (backpatch() != 0) {
		panic("patchlist not empty after reading namelist");
	}
	if (program == NIL) {
		panic("no program");
	}
	maketypes();
E 4
I 4
	sym[symno] = readsym(fp);
    }
    if (backpatch() != 0) {
	panic("patchlist not empty after reading namelist");
    }
    if (program == NIL) {
	panic("no program");
    }
    maketypes();
E 4
}

typedef struct patchinfo {
D 4
	SYM **patchsym;
	struct patchinfo *next_patch;
E 4
I 4
    SYM **patchsym;
    struct patchinfo *next_patch;
E 4
} PATCH;

LOCAL PATCH *phead;

/*
 * Go through patchlist looking for symbol numbers for which the
 * sym array now has a non-NIL entry.
 *
 * Afterwards, zap the sym array.
 */

int backpatch()
{
D 4
	register PATCH *p, *last, *next;
	register SYM *s, **t;
	int count;
E 4
I 4
    register PATCH *p, *last, *next;
    register SYM *s, **t;
    int count;
E 4

D 4
	last = NIL;
	count = 0;
	for (p = phead; p != NIL; p = next) {
		next = p->next_patch;
		t = p->patchsym;
		if ((s = sym[(int) *t]) != NIL) {
			*t = s;
			if (last == NIL) {
				phead = next;
			} else {
				last->next_patch = next;
			}
			dispose(p);
		} else {
			last = p;
			count++;
		}
E 4
I 4
    last = NIL;
    count = 0;
    for (p = phead; p != NIL; p = next) {
	next = p->next_patch;
	t = p->patchsym;
	if ((s = sym[(int) *t]) != NIL) {
	    *t = s;
	    if (last == NIL) {
		phead = next;
	    } else {
		last->next_patch = next;
	    }
	    dispose(p);
	} else {
	    last = p;
	    count++;
E 4
	}
D 4
	for (t = &sym[0]; t < &sym[MAXSYMNO]; t++) {
		*t = NIL;
	}
	return(count);
E 4
I 4
    }
    for (t = &sym[0]; t < &sym[MAXSYMNO]; t++) {
	*t = NIL;
    }
    return(count);
E 4
}

/*
 * Check to see if the given pointer (really symbol number) should
 * be added to the patch list.  The argument is double indirect
 * to do call by reference passing.
 */

chkpatch(p)
SYM **p;
{
D 4
	register SYM *s, *t;
	register PATCH *patch;
E 4
I 4
    register SYM *s, *t;
    register PATCH *patch;
E 4

D 4
	if ((s = *p) != NIL) {
		if ((t = sym[(int) s]) != NIL) {
			*p = t;
		} else {
			patch = alloc(1, PATCH);
			patch->patchsym = p;
			patch->next_patch = phead;
			phead = patch;
		}
E 4
I 4
    if ((s = *p) != NIL) {
	if ((t = sym[(int) s]) != NIL) {
	    *p = t;
	} else {
	    patch = alloc(1, PATCH);
	    patch->patchsym = p;
	    patch->next_patch = phead;
	    phead = patch;
E 4
	}
I 4
    }
E 4
}

/*
 * Free all the object information.
 */

objfree()
{
D 4
	register int i;
E 4
I 4
    register int i;
E 4

D 4
	st_destroy(symtab);
	dispose(stringtab);
	dispose(filetab);
	dispose(linetab);
	clrfunctab();
	for (i = 0; i < MAXSYMNO; i++) {
		sym[i] = NIL;
	}
E 4
I 4
    st_destroy(symtab);
    dispose(stringtab);
    dispose(filetab);
    dispose(linetab);
    clrfunctab();
    for (i = 0; i < MAXSYMNO; i++) {
	sym[i] = NIL;
    }
E 4
}
E 1
