h02318
s 00054/00012/00907
d D 5.2 88/01/12 00:59:23 donn 19 18
c merge in latest Linton version
e
s 00008/00002/00911
d D 5.1 85/05/31 10:10:58 dist 18 17
c Add copyright
e
s 00231/00066/00682
d D 1.16 85/03/01 20:26:05 linton 17 16
c update to version 3.0
e
s 00001/00003/00747
d D 1.15 84/06/23 11:42:00 sam 16 14
i 15
c merge linton branch delta trail
e
s 00196/00548/00554
d D 1.14.1.1 84/06/23 10:47:58 sam 15 14
c branch delta of linton changes from net.sources
e
s 00002/00000/01100
d D 1.14 83/10/22 12:55:03 sam 14 13
c handle enums w/o tags as structure/union members 
e
s 00001/00000/01099
d D 1.13 83/08/16 12:19:33 linton 13 12
c added missing "skipchar" in reading ranges which was accidentally 
c removed when cleaning up rangetype stuff
e
s 00047/00056/01052
d D 1.12 83/08/16 02:16:25 linton 12 11
c added "S" type for sets, moved t_{int,char,...} to symbols 
c so that it could be initialized independent of reading in the object information
e
s 00146/00087/00962
d D 1.11 83/08/10 05:00:44 linton 11 10
c cleaned up a few things, fixed a problem with detecting "stripped" object 
c files, now complains about files linked without "-g", and put in some support 
c for unnamed blocks which contain variables
e
s 00065/00045/00984
d D 1.10 83/07/15 14:49:56 linton 10 9
c fixed a problem with addresses of globals created by handling 
c Fortran common symbols; also fixed a problem with globals defined between 
c functions being attached to the previous function; and no longer ignores 
c file entries with redundant starting addresses -- not clear what all the 
c effects of this might be
e
s 00001/00001/01028
d D 1.9 83/07/07 20:02:56 linton 9 8
c changed size of "t_real" from 4 to 8; this made printing of 
c real constants (e.g. "print 2.3") work
e
s 00124/00004/00905
d D 1.8 83/05/18 19:50:57 csvaf 8 7
c various changes to support f77 object files : N_BCOMM N_ECOMM
c rangetype stripping trailing _ etc.
e
s 00019/00006/00890
d D 1.7 83/04/08 02:16:33 linton 7 6
c now recognizes whether a function has source line information associated with it
e
s 00007/00005/00889
d D 1.6 83/03/30 02:23:39 linton 6 5
c now assigns location 2 for modules and the main program
e
s 00007/00005/00887
d D 1.5 83/03/13 15:18:47 linton 5 4
c fixed forward references of the form "typedef struct x y"
e
s 00004/00004/00888
d D 1.4 83/02/16 23:08:14 linton 4 3
c fixed handling of global symbols
e
s 00006/00000/00886
d D 1.3 82/12/18 23:23:29 linton 3 2
c now ignores old style N_LENG, used to complain about them
e
s 00001/00001/00885
d D 1.2 82/12/15 04:21:08 linton 2 1
c fixed @(#) stuff
e
s 00886/00000/00000
d D 1.1 82/12/15 04:08:11 linton 1 0
c date and time created 82/12/15 04:08:11 by linton
e
u
U
f b 
t
T
I 1
D 18
/* Copyright (c) 1982 Regents of the University of California */
E 18
I 18
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 18

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 15
static char sccsid[] = "%Z%%M% %I% %G%";
E 15
I 15
D 16
static char sccsid[] = "@(#)object.c 1.14 10/22/83";
E 15
E 2

I 15
static char rcsid[] = "$Header: object.c,v 1.4 84/03/27 10:22:25 linton Exp $";
E 16
I 16
D 18
static	char sccsid[] = "%W% (Berkeley) %G%";
E 18
I 18
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 18
E 16

I 17
D 19
static char rcsid[] = "$Header: object.c,v 1.6 84/12/26 10:40:51 linton Exp $";
E 19
I 19
static char rcsid[] = "$Header: object.c,v 1.5 87/03/26 20:24:58 donn Exp $";
E 19

E 17
E 15
/*
 * Object code interface, mainly for extraction of symbolic information.
 */

#include "defs.h"
#include "object.h"
I 15
#include "stabstring.h"
E 15
#include "main.h"
#include "symbols.h"
#include "names.h"
#include "languages.h"
#include "mappings.h"
#include "lists.h"
#include <a.out.h>
#include <stab.h>
#include <ctype.h>

#ifndef public

struct {
    unsigned int stringsize;	/* size of the dumped string table */
    unsigned int nsyms;		/* number of symbols */
    unsigned int nfiles;	/* number of files */
    unsigned int nlines;	/* number of lines */
} nlhdr;

I 15
#include "languages.h"
#include "symbols.h"

E 15
#endif

I 15
#ifndef N_MOD2
#    define N_MOD2 0x50
#endif

E 15
public String objname = "a.out";
D 15
public Integer objsize;
public char *stringtab;
E 15
I 15
public integer objsize;
E 15

D 15
private String progname = nil;
private Language curlang;
private Symbol curmodule;
private Symbol curparam;
E 15
I 15
public Language curlang;
public Symbol curmodule;
public Symbol curparam;
public Symbol curcomm;
public Symbol commchain;

private char *stringtab;
private struct nlist *curnp;
E 15
private Boolean warned;
I 8
D 15
private Symbol curcomm;
private Symbol commchain;
E 15
private Boolean strip_ = false;
E 8

private Filetab *filep;
D 7
private Linetab *linep;
E 7
I 7
private Linetab *linep, *prevlinep;
E 7
D 10
private Address curfaddr;
E 10

D 15
#define curfilename() (filep-1)->filename
E 15
I 15
public String curfilename ()
{
    return ((filep-1)->filename);
}
E 15

/*
 * Blocks are figured out on the fly while reading the symbol table.
 */

#define MAXBLKDEPTH 25

D 15
private Symbol curblock;
E 15
I 15
public Symbol curblock;

E 15
private Symbol blkstack[MAXBLKDEPTH];
D 15
private Integer curlevel;
I 11
private Integer bnum, nesting;
E 15
I 15
private integer curlevel;
private integer bnum, nesting;
E 15
private Address addrstk[MAXBLKDEPTH];
E 11

D 15
#define enterblock(b) { \
    blkstack[curlevel] = curblock; \
    ++curlevel; \
    b->level = curlevel; \
    b->block = curblock; \
    curblock = b; \
E 15
I 15
public pushBlock (b)
Symbol b;
{
    if (curlevel >= MAXBLKDEPTH) {
	fatal("nesting depth too large (%d)", curlevel);
    }
    blkstack[curlevel] = curblock;
    ++curlevel;
    curblock = b;
    if (traceblocks) {
	printf("entering block %s\n", symname(b));
    }
E 15
}

I 17
/*
 * Change the current block with saving the previous one,
 * since it is assumed that the symbol for the current one is to be deleted.
 */

public changeBlock (b)
Symbol b;
{
    curblock = b;
}

E 17
D 15
#define exitblock() { \
I 7
    if (curblock->class == FUNC or curblock->class == PROC) { \
	if (prevlinep != linep) { \
	    curblock->symvalue.funcv.src = true; \
	} \
    } \
E 7
    --curlevel; \
    curblock = blkstack[curlevel]; \
E 15
I 15
public enterblock (b)
Symbol b;
{
    if (curblock == nil) {
	b->level = 1;
    } else {
	b->level = curblock->level + 1;
    }
    b->block = curblock;
    pushBlock(b);
E 15
}

I 15
public exitblock ()
{
    if (curblock->class == FUNC or curblock->class == PROC) {
	if (prevlinep != linep) {
	    curblock->symvalue.funcv.src = true;
	}
    }
    if (curlevel <= 0) {
	panic("nesting depth underflow (%d)", curlevel);
    }
    --curlevel;
    if (traceblocks) {
	printf("exiting block %s\n", symname(curblock));
    }
    curblock = blkstack[curlevel];
}

E 15
/*
 * Enter a source line or file name reference into the appropriate table.
 * Expanded inline to reduce procedure calls.
 *
D 15
 * private enterline(linenumber, address)
E 15
I 15
 * private enterline (linenumber, address)
E 15
 * Lineno linenumber;
 * Address address;
 *  ...
 */

#define enterline(linenumber, address) \
{ \
    register Linetab *lp; \
 \
    lp = linep - 1; \
    if (linenumber != lp->line) { \
	if (address != lp->addr) { \
	    ++lp; \
	} \
	lp->line = linenumber; \
	lp->addr = address; \
	linep = lp + 1; \
    } \
}

D 15
#define NTYPES 1000

private Symbol typetable[NTYPES];

E 15
/*
 * Read in the namelist from the obj file.
 *
 * Reads and seeks are used instead of fread's and fseek's
 * for efficiency sake; there's a lot of data being read here.
 */

D 15
public readobj(file)
E 15
I 15
public readobj (file)
E 15
String file;
{
    Fileid f;
    struct exec hdr;
    struct nlist nlist;

    f = open(file, 0);
    if (f < 0) {
	fatal("can't open %s", file);
    }
    read(f, &hdr, sizeof(hdr));
D 17
    objsize = hdr.a_text;
    nlhdr.nsyms = hdr.a_syms / sizeof(nlist);
    nlhdr.nfiles = nlhdr.nsyms;
    nlhdr.nlines = nlhdr.nsyms;
E 17
I 17
    if (N_BADMAG(hdr)) {
	objsize = 0;
	nlhdr.nsyms = 0;
	nlhdr.nfiles = 0;
	nlhdr.nlines = 0;
    } else {
	objsize = hdr.a_text;
	nlhdr.nsyms = hdr.a_syms / sizeof(nlist);
	nlhdr.nfiles = nlhdr.nsyms;
	nlhdr.nlines = nlhdr.nsyms;
    }
E 17
D 11
    lseek(f, (long) N_STROFF(hdr), 0);
    read(f, &(nlhdr.stringsize), sizeof(nlhdr.stringsize));
    nlhdr.stringsize -= 4;
    stringtab = newarr(char, nlhdr.stringsize);
    read(f, stringtab, nlhdr.stringsize);
    allocmaps(nlhdr.nfiles, nlhdr.nlines);
    lseek(f, (long) N_SYMOFF(hdr), 0);
    readsyms(f);
    ordfunctab();
    setnlines();
    setnfiles();
E 11
I 11
    if (nlhdr.nsyms > 0) {
	lseek(f, (long) N_STROFF(hdr), 0);
	read(f, &(nlhdr.stringsize), sizeof(nlhdr.stringsize));
	nlhdr.stringsize -= 4;
	stringtab = newarr(char, nlhdr.stringsize);
	read(f, stringtab, nlhdr.stringsize);
	allocmaps(nlhdr.nfiles, nlhdr.nlines);
	lseek(f, (long) N_SYMOFF(hdr), 0);
	readsyms(f);
	ordfunctab();
	setnlines();
	setnfiles();
I 17
    } else {
	initsyms();
E 17
    }
E 11
    close(f);
}

/*
I 17
 * Found the beginning of the externals in the object file
 * (signified by the "-lg" or find an external), close the
 * block for the last procedure.
 */

private foundglobals ()
{
    if (curblock->class != PROG) {
	exitblock();
	if (curblock->class != PROG) {
	    exitblock();
	}
    }
    enterline(0, (linep-1)->addr + 1);
}

/*
E 17
 * Read in symbols from object file.
 */

D 15
private readsyms(f)
E 15
I 15
private readsyms (f)
E 15
Fileid f;
{
    struct nlist *namelist;
    register struct nlist *np, *ub;
D 15
    register int index;
E 15
    register String name;
D 19
    register Boolean afterlg;
E 19
I 19
    boolean afterlg, foundstab;
E 19
I 15
    integer index;
    char *lastchar;
E 15

    initsyms();
    namelist = newarr(struct nlist, nlhdr.nsyms);
    read(f, namelist, nlhdr.nsyms * sizeof(struct nlist));
    afterlg = false;
I 19
    foundstab = false;
E 19
    ub = &namelist[nlhdr.nsyms];
D 15
    for (np = &namelist[0]; np < ub; np++) {
E 15
I 15
    curnp = &namelist[0];
    np = curnp;
    while (np < ub) {
E 15
	index = np->n_un.n_strx;
	if (index != 0) {
	    name = &stringtab[index - 4];
I 8
	    /*
D 15
             *  if the program contains any .f files a trailing _ is stripped
E 15
I 15
             *  If the program contains any .f files a trailing _ is stripped
E 15
       	     *  from the name on the assumption it was added by the compiler.
	     *  This only affects names that follow the sdb N_SO entry with
             *  the .f name. 
             */
D 11
            if(strip_ && *name != '\0' ) {
                 register char *p, *q;
                 for(p=name,q=(name+1); *q != '\0'; p=q++);
                 if (*p == '_')  *p = '\0';
E 11
I 11
            if (strip_ and name[0] != '\0' ) {
D 15
		register char *p;

		p = name;
		while (*p != '\0') {
		    ++p;
E 15
I 15
		lastchar = &name[strlen(name) - 1];
		if (*lastchar == '_') {
		    *lastchar = '\0';
E 15
		}
D 15
		--p;
D 12
		if (*p == '-') {
E 12
I 12
		if (*p == '_') {
E 12
		    *p = '\0';
		}
E 15
E 11
            }
D 15

E 15
E 8
	} else {
	    name = nil;
D 8
	}
E 8
I 8
	} 
I 15

E 15
E 8
	/*
D 15
	 * assumptions:
E 15
I 15
	 * Assumptions:
E 15
	 *	not an N_STAB	==> name != nil
	 *	name[0] == '-'	==> name == "-lg"
	 *	name[0] != '_'	==> filename or invisible
	 *
	 * The "-lg" signals the beginning of global loader symbols.
I 8
         *
E 8
	 */
	if ((np->n_type&N_STAB) != 0) {
I 19
	    foundstab = true;
E 19
	    enter_nl(name, np);
	} else if (name[0] == '-') {
	    afterlg = true;
D 17
	    if (curblock->class != PROG) {
		exitblock();
		if (curblock->class != PROG) {
		    exitblock();
		}
	    }
	    enterline(0, (linep-1)->addr + 1);
E 17
I 17
	    foundglobals();
E 17
D 4
	} else if (name[0] == '_') {
	    if (afterlg) {
E 4
I 4
	} else if (afterlg) {
D 17
	    if (name[0] == '_') {
E 4
		check_global(&name[1], np);
D 4
	    } else if (curblock->name != nil) {
		check_local(&name[1], np);
E 4
	    }
E 17
I 17
	    check_global(name, np);
	} else if ((np->n_type&N_EXT) == N_EXT) {
	    afterlg = true;
	    foundglobals();
	    check_global(name, np);
E 17
I 4
	} else if (name[0] == '_') {
	    check_local(&name[1], np);
E 4
	} else if ((np->n_type&N_TEXT) == N_TEXT) {
	    check_filename(name);
	}
I 15
	++curnp;
	np = curnp;
E 15
    }
I 19
    if (not foundstab) {
	warning("no source compiled with -g");
    }
E 19
I 11
D 17
    if (not afterlg) {
D 12
	panic("not linked for debugging, use \"cc -g ...\"");
E 12
I 12
	fatal("not linked for debugging, use \"cc -g ...\"");
E 12
    }
E 17
E 11
    dispose(namelist);
}

/*
I 15
 * Get a continuation entry from the name list.
 * Return the beginning of the name.
 */

public String getcont ()
{
    register integer index;
    register String name;

    ++curnp;
    index = curnp->n_un.n_strx;
    if (index == 0) {
D 19
	panic("continuation followed by empty stab");
E 19
I 19
	name = "";
    } else {
	name = &stringtab[index - 4];
E 19
    }
D 19
    name = &stringtab[index - 4];
E 19
    return name;
}

/*
E 15
 * Initialize symbol information.
 */

D 15
private initsyms()
E 15
I 15
private initsyms ()
E 15
{
    curblock = nil;
    curlevel = 0;
I 11
    nesting = 0;
E 11
D 15
    if (progname == nil) {
	progname = strdup(objname);
	if (rindex(progname, '/') != nil) {
	    progname = rindex(progname, '/') + 1;
	}
	if (index(progname, '.') != nil) {
	    *(index(progname, '.')) = '\0';
	}
    }
    program = insert(identname(progname, true));
E 15
I 15
    program = insert(identname("", true));
E 15
    program->class = PROG;
D 6
    newfunc(program);
E 6
I 6
D 19
    program->symvalue.funcv.beginaddr = 0;
E 19
I 19
    program->language = primlang;
    program->symvalue.funcv.beginaddr = CODESTART;
E 19
I 11
    program->symvalue.funcv.inline = false;
    newfunc(program, codeloc(program));
E 11
E 6
    findbeginning(program);
I 6
D 11
    newfunc(program);
E 11
E 6
    enterblock(program);
    curmodule = program;
I 15
D 17
    t_boolean = maketype("$boolean", 0L, 1L);
    t_int = maketype("$integer", 0x80000000L, 0x7fffffffL);
    t_char = maketype("$char", 0L, 255L);
    t_real = maketype("$real", 8L, 0L);
    t_nil = maketype("$nil", 0L, 0L);
    t_open = maketype("integer", 0L, -1L);
E 17
E 15
D 12
    t_boolean = maketype("$boolean", 0L, 1L);
    t_int = maketype("$integer", 0x80000000L, 0x7fffffffL);
    t_char = maketype("$char", 0L, 127L);
D 9
    t_real = maketype("$real", 4L, 0L);
E 9
I 9
    t_real = maketype("$real", 8L, 0L);
E 9
    t_nil = maketype("$nil", 0L, 0L);
E 12
}

/*
 * Free all the object file information that's being stored.
 */

D 15
public objfree()
E 15
I 15
public objfree ()
E 15
{
    symbol_free();
D 17
    keywords_free();
    names_free();
    dispose(stringtab);
E 17
I 17
    /* keywords_free(); */
    /* names_free(); */
    /* dispose(stringtab); */
E 17
    clrfunctab();
}

/*
 * Enter a namelist entry.
 */

D 15
private enter_nl(name, np)
E 15
I 15
private enter_nl (name, np)
E 15
String name;
register struct nlist *np;
{
    register Symbol s;
D 11
    String mname, suffix;
E 11
D 7
    register Name n;
E 7
I 7
D 15
    register Name n, nn;
I 11
    char buf[100];
E 15
I 15
    register Name n;
E 15
E 11
E 7
D 6
    register Symbol *tt;
E 6

    s = nil;
D 15
    if (name == nil) {
	n = nil;
    } else {
	n = identname(name, true);
    }
E 15
    switch (np->n_type) {
I 8
D 11

D 10
/* Build a symbol for the common; all GSYMS that follow will be chained;
 * the head of this list is kept in common.offset, the tail in common.chain
 */
 	case N_BCOMM:
 	    if(curcomm) {
	    curcomm->symvalue.common.chain = commchain;
E 10
I 10
    /*
     * Build a symbol for the common; all GSYMS that follow will be chained;
     * the head of this list is kept in common.offset, the tail in common.chain
     */
E 11
I 11
	/*
	 * Build a symbol for the FORTRAN common area.  All GSYMS that follow
	 * will be chained in a list with the head kept in common.offset, and
	 * the tail in common.chain.
	 */
E 11
	case N_BCOMM:
 	    if (curcomm) {
		curcomm->symvalue.common.chain = commchain;
E 10
	    }
I 15
	    n = identname(name, true);
E 15
	    curcomm = lookup(n);
D 10
	    if (  curcomm == nil) {
		  curcomm = insert(n);
		  curcomm->class = COMMON;
		  curcomm->block = curblock;
		  curcomm->level = program->level;
		  curcomm->symvalue.common.chain = nil;
E 10
I 10
	    if (curcomm == nil) {
		curcomm = insert(n);
		curcomm->class = COMMON;
		curcomm->block = curblock;
		curcomm->level = program->level;
		curcomm->symvalue.common.chain = nil;
E 10
	    }
	    commchain = curcomm->symvalue.common.chain;
D 10
	break;
E 10
I 10
	    break;
E 10

	case N_ECOMM:
D 10
	    if(curcomm) {
	    curcomm->symvalue.common.chain = commchain;
	    curcomm = nil;
E 10
I 10
	    if (curcomm) {
		curcomm->symvalue.common.chain = commchain;
		curcomm = nil;
E 10
	    }
	    break;
D 11
				   
E 11
I 11

E 11
E 8
	case N_LBRAC:
D 11
	    s = symbol_alloc();
	    s->class = PROC;
	    enterblock(s);
E 11
I 11
	    ++nesting;
	    addrstk[nesting] = (linep - 1)->addr;
E 11
	    break;

	case N_RBRAC:
I 15
	    --nesting;
E 15
D 11
	    exitblock();
E 11
I 11
	    if (addrstk[nesting] == NOADDR) {
		exitblock();
		newfunc(curblock, (linep - 1)->addr);
I 15
		addrstk[nesting] = (linep - 1)->addr;
E 15
	    }
D 15
	    --nesting;
E 15
E 11
	    break;

	case N_SLINE:
	    enterline((Lineno) np->n_desc, (Address) np->n_value);
	    break;

	/*
D 11
	 * Compilation unit.  C associates scope with filenames
	 * so we treat them as "modules".  The filename without
	 * the suffix is used for the module name.
	 *
	 * Because there is no explicit "end-of-block" mark in
	 * the object file, we must exit blocks for the current
	 * procedure and module.
E 11
I 11
	 * Source files.
E 11
	 */
	case N_SO:
I 15
	    n = identname(name, true);
E 15
D 11
	    mname = strdup(ident(n));
	    if (rindex(mname, '/') != nil) {
		mname = rindex(mname, '/') + 1;
	    }
	    suffix = rindex(mname, '.');
	    curlang = findlanguage(suffix);
I 8
	    if(curlang == findlanguage(".f")) {
                            strip_ = true;
            } 
E 8
	    if (suffix != nil) {
		*suffix = '\0';
	    }
	    if (curblock->class != PROG) {
		exitblock();
		if (curblock->class != PROG) {
		    exitblock();
		}
	    }
D 7
	    s = insert(identname(mname, true));
E 7
I 7
	    nn = identname(mname, true);
	    if (curmodule == nil or curmodule->name != nn) {
		s = insert(nn);
		s->class = MODULE;
		s->symvalue.funcv.beginaddr = 0;
		findbeginning(s);
	    } else {
		s = curmodule;
	    }
E 7
	    s->language = curlang;
D 7
	    s->class = MODULE;
I 6
	    s->symvalue.funcv.beginaddr = 0;
	    findbeginning(s);
E 7
E 6
	    enterblock(s);
	    curmodule = s;
	    if (program->language == nil) {
		program->language = curlang;
	    }
	    warned = false;
	    enterfile(ident(n), (Address) np->n_value);
D 6
	    for (tt = &typetable[0]; tt < &typetable[NTYPES]; tt++) {
		*tt = nil;
	    }
E 6
I 6
	    bzero(typetable, sizeof(typetable));
E 11
I 11
	    enterSourceModule(n, (Address) np->n_value);
E 11
E 6
	    break;

	/*
	 * Textually included files.
	 */
	case N_SOL:
	    enterfile(name, (Address) np->n_value);
	    break;

	/*
	 * These symbols are assumed to have non-nil names.
	 */
	case N_GSYM:
	case N_FUN:
	case N_STSYM:
	case N_LCSYM:
	case N_RSYM:
	case N_PSYM:
	case N_LSYM:
	case N_SSYM:
I 11
	case N_LENG:
E 11
	    if (index(name, ':') == nil) {
		if (not warned) {
		    warned = true;
D 11
		    /*
		     * Shouldn't do this if user might be typing.
		     *
E 11
D 19
		    warning("old style symbol information found in \"%s\"",
			curfilename());
E 19
I 19
		    printf("warning: old style symbol information ");
		    printf("found in \"%s\"\n", curfilename());
E 19
D 11
		     *
		     */
E 11
		}
	    } else {
		entersym(name, np);
	    }
	    break;

	case N_PC:
I 15
	case N_MOD2:
E 15
	    break;

I 3
D 11
	case N_LENG:
E 11
I 5
	default:
E 5
D 11
	    /*
	     * Should complain out this, obviously the wrong symbol format.
D 5
	     */
	    break;

E 3
	default:
E 5
I 5
	     *
E 11
I 11
	    printf("warning:  stab entry unrecognized: ");
E 11
E 5
	    if (name != nil) {
D 11
		printf("%s, ", name);
E 11
I 11
		printf("name %s,", name);
E 11
	    }
D 11
	    printf("ntype %2x, desc %x, value %x\n",
E 11
I 11
	    printf("ntype %2x, desc %x, value %x'\n",
E 11
		np->n_type, np->n_desc, np->n_value);
I 5
D 11
	     *
	     */
E 11
E 5
	    break;
    }
}

/*
I 15
D 17
 * Try to find the symbol that is referred to by the given name.
 * Since it's an external, we may want to follow a level of indirection.
E 17
I 17
 * Try to find the symbol that is referred to by the given name.  Since it's
 * an external, we need to follow a level or two of indirection.
E 17
 */

D 17
private Symbol findsym (n)
E 17
I 17
private Symbol findsym (n, var_isextref)
E 17
Name n;
I 17
boolean *var_isextref;
E 17
{
    register Symbol r, s;

I 17
    *var_isextref = false;
E 17
    find(s, n) where
D 17
	s->level == program->level and
	    (s->class == EXTREF or s->class == VAR or
	     s->class == PROC or s->class == FUNC)
E 17
I 17
	(
	    s->level == program->level and (
		s->class == EXTREF or s->class == VAR or
		s->class == PROC or s->class == FUNC
	    )
	) or (
	    s->block == program and s->class == MODULE
	)
E 17
    endfind(s);
D 17
    if (s != nil and s->class == EXTREF) {
E 17
I 17
    if (s == nil) {
	r = nil;
    } else if (s->class == EXTREF) {
	*var_isextref = true;
E 17
	r = s->symvalue.extref;
	delete(s);
I 17

	/*
	 * Now check for another level of indirection that could come from
	 * a forward reference in procedure nesting information.  In this case
	 * the symbol has already been deleted.
	 */
	if (r != nil and r->class == EXTREF) {
	    r = r->symvalue.extref;
	}
/*
    } else if (s->class == MODULE) {
	s->class = FUNC;
	s->level = program->level;
	r = s;
 */
E 17
    } else {
	r = s;
    }
    return r;
}

/*
I 17
 * Create a symbol for a text symbol with no source information.
 * We treat it as an assembly language function.
 */

private Symbol deffunc (n)
Name n;
{
    Symbol f;

    f = insert(n);
    f->language = findlanguage(".s");
    f->class = FUNC;
    f->type = t_int;
    f->block = curblock;
    f->level = program->level;
    f->symvalue.funcv.src = false;
    f->symvalue.funcv.inline = false;
I 19
    if (f->chain != nil) {
	panic("chain not nil in deffunc");
    }
E 19
    return f;
}

/*
 * Create a symbol for a data or bss symbol with no source information.
 * We treat it as an assembly language variable.
 */

private Symbol defvar (n)
Name n;
{
    Symbol v;

    v = insert(n);
    v->language = findlanguage(".s");
I 19
    v->storage = EXT;
E 19
    v->class = VAR;
    v->type = t_int;
    v->level = program->level;
    v->block = curblock;
    return v;
}

/*
 * Update a symbol entry with a text address.
 */

private updateTextSym (s, name, addr)
Symbol s;
char *name;
Address addr;
{
    if (s->class == VAR) {
	s->symvalue.offset = addr;
    } else {
	s->symvalue.funcv.beginaddr = addr;
	if (name[0] == '_') {
	    newfunc(s, codeloc(s));
	    findbeginning(s);
	}
    }
}

/*
I 19
 * Avoid seeing Pascal labels as text symbols.
 */

private boolean PascalLabel (n)
Name n;
{
    boolean b;
    register char *p;

    b = false;
    if (curlang == findlanguage(".p")) {
	p = ident(n);
	while (*p != '\0') {
	    if (*p == '_' and *(p+1) == '$') {
		b = true;
		break;
	    }
	    ++p;
	}
    }
    return b;
}

/*
E 19
E 17
E 15
 * Check to see if a global _name is already in the symbol table,
 * if not then insert it.
 */

D 15
private check_global(name, np)
E 15
I 15
private check_global (name, np)
E 15
String name;
register struct nlist *np;
{
    register Name n;
D 8
    register Symbol t;
E 8
I 8
    register Symbol t, u;
I 17
    char buf[4096];
    boolean isextref;
    integer count;
E 17
E 8

D 17
    if (not streq(name, "end")) {
	n = identname(name, true);
E 17
I 17
    if (not streq(name, "_end")) {
	if (name[0] == '_') {
	    n = identname(&name[1], true);
	} else {
	    n = identname(name, true);
	    if (lookup(n) != nil) {
		sprintf(buf, "$%s", name);
		n = identname(buf, false);
	    }
	}
E 17
	if ((np->n_type&N_TYPE) == N_TEXT) {
D 15
	    find(t, n) where
D 11
		t->level == program->level and isblock(t)
E 11
I 11
		t->level == program->level and
		(t->class == PROC or t->class == FUNC)
E 11
	    endfind(t);
E 15
I 15
D 17
	    t = findsym(n);
E 15
	    if (t == nil) {
		t = insert(n);
		t->language = findlanguage(".s");
		t->class = FUNC;
		t->type = t_int;
		t->block = curblock;
		t->level = program->level;
I 7
		t->symvalue.funcv.src = false;
I 11
		t->symvalue.funcv.inline = false;
E 17
I 17
	    count = 0;
	    t = findsym(n, &isextref);
	    while (isextref) {
		++count;
		updateTextSym(t, name, np->n_value);
		t = findsym(n, &isextref);
E 17
E 11
E 7
	    }
D 15
	    t->symvalue.funcv.beginaddr = np->n_value;
D 11
	    newfunc(t);
E 11
I 11
	    newfunc(t, codeloc(t));
E 11
	    findbeginning(t);
E 15
I 15
D 17
	    if (t->class == VAR) {
		t->symvalue.offset = np->n_value;
	    } else {
		t->symvalue.funcv.beginaddr = np->n_value;
		newfunc(t, codeloc(t));
		findbeginning(t);
E 17
I 17
	    if (count == 0) {
		if (t == nil) {
D 19
		    t = deffunc(n);
		    updateTextSym(t, name, np->n_value);
		    if (tracesyms) {
			printdecl(t);
E 19
I 19
		    if (not PascalLabel(n)) {
			t = deffunc(n);
			updateTextSym(t, name, np->n_value);
			if (tracesyms) {
			    printdecl(t);
			}
E 19
		    }
		} else {
		    if (t->class == MODULE) {
			u = t;
			t = deffunc(n);
			t->block = u;
			if (tracesyms) {
			    printdecl(t);
			}
		    }
		    updateTextSym(t, name, np->n_value);
		}
E 17
	    }
E 15
D 8
	} else {
E 8
I 8
D 10
	}  else if ( (np->n_type&N_TYPE) == N_BSS ){
E 10
I 10
D 19
	} else if ((np->n_type&N_TYPE) == N_BSS) {
E 19
I 19
	} else if ((np->n_type&N_TYPE) == N_BSS or (np->n_type&N_TYPE) == N_DATA) {
E 19
E 10
E 8
	    find(t, n) where
I 8
D 10
		t->class  == COMMON
E 10
I 10
		t->class == COMMON
E 10
	    endfind(t);
D 10
	    if(t != nil) {
		for(u= (Symbol) t->symvalue.common.offset;
                        u != nil ;u=u->symvalue.common.chain){
		   u->symvalue.offset = u->symvalue.common.offset + np->n_value;
		   }
            }
        }
        else {
	    find(t, n) where
E 8
		t->class == VAR and t->level == program->level
	    endfind(t);
	    if (t == nil) {
		t = insert(n);
		t->language = findlanguage(".s");
		t->class = VAR;
		t->type = t_int;
		t->block = curblock;
		t->level = program->level;
E 10
I 10
	    if (t != nil) {
		u = (Symbol) t->symvalue.common.offset;
		while (u != nil) {
		    u->symvalue.offset = u->symvalue.common.offset+np->n_value;
		    u = u->symvalue.common.chain;
		}
            } else {
		check_var(np, n);
E 10
	    }
D 10
	    t->symvalue.offset = np->n_value;
E 10
I 10
        } else {
	    check_var(np, n);
E 10
	}
    }
}

/*
I 10
 * Check to see if a namelist entry refers to a variable.
 * If not, create a variable for the entry.  In any case,
 * set the offset of the variable according to the value field
 * in the entry.
I 17
 *
 * If the external name has been referred to by several other symbols,
 * we must update each of them.
E 17
 */

D 15
private check_var(np, n)
E 15
I 15
private check_var (np, n)
E 15
struct nlist *np;
register Name n;
{
D 17
    register Symbol t;
E 17
I 17
    register Symbol t, u, next;
    Symbol conflict;
E 17

D 15
    find(t, n) where
	t->class == VAR and t->level == program->level
    endfind(t);
E 15
I 15
D 17
    t = findsym(n);
E 17
I 17
    t = lookup(n);
E 17
E 15
    if (t == nil) {
D 17
	t = insert(n);
	t->language = findlanguage(".s");
	t->class = VAR;
	t->type = t_int;
	t->level = program->level;
I 15
	t->block = curblock;
E 17
I 17
	t = defvar(n);
	t->symvalue.offset = np->n_value;
	if (tracesyms) {
	    printdecl(t);
	}
    } else {
	conflict = nil;
	do {
	    next = t->next_sym;
	    if (t->name == n) {
		if (t->class == MODULE and t->block == program) {
		    conflict = t;
		} else if (t->class == EXTREF and t->level == program->level) {
		    u = t->symvalue.extref;
		    while (u != nil and u->class == EXTREF) {
			u = u->symvalue.extref;
		    }
		    u->symvalue.offset = np->n_value;
		    delete(t);
		} else if (t->level == program->level and
		    (t->class == VAR or t->class == PROC or t->class == FUNC)
		) {
		    conflict = nil;
		    t->symvalue.offset = np->n_value;
		}
	    }
	    t = next;
	} while (t != nil);
	if (conflict != nil) {
	    u = defvar(n);
	    u->block = conflict;
	    u->symvalue.offset = np->n_value;
	}
E 17
E 15
    }
D 15
    t->block = curblock;
E 15
D 17
    t->symvalue.offset = np->n_value;
E 17
}

/*
E 10
 * Check to see if a local _name is known in the current scope.
 * If not then enter it.
 */

D 15
private check_local(name, np)
E 15
I 15
private check_local (name, np)
E 15
String name;
register struct nlist *np;
{
    register Name n;
    register Symbol t, cur;

    n = identname(name, true);
    cur = ((np->n_type&N_TYPE) == N_TEXT) ? curmodule : curblock;
    find(t, n) where t->block == cur endfind(t);
    if (t == nil) {
	t = insert(n);
	t->language = findlanguage(".s");
	t->type = t_int;
	t->block = cur;
I 19
	t->storage = EXT;
E 19
	t->level = cur->level;
	if ((np->n_type&N_TYPE) == N_TEXT) {
	    t->class = FUNC;
I 7
	    t->symvalue.funcv.src = false;
I 11
	    t->symvalue.funcv.inline = false;
E 11
E 7
	    t->symvalue.funcv.beginaddr = np->n_value;
D 11
	    newfunc(t);
E 11
I 11
	    newfunc(t, codeloc(t));
E 11
	    findbeginning(t);
	} else {
	    t->class = VAR;
	    t->symvalue.offset = np->n_value;
	}
    }
}

/*
 * Check to see if a symbol corresponds to a object file name.
 * For some reason these are listed as in the text segment.
 */

D 15
private check_filename(name)
E 15
I 15
private check_filename (name)
E 15
String name;
{
    register String mname;
D 15
    register Integer i;
E 15
I 15
    register integer i;
E 15
D 17
    register Symbol s;
E 17
I 17
    Name n;
    Symbol s;
E 17

    mname = strdup(name);
    i = strlen(mname) - 2;
    if (i >= 0 and mname[i] == '.' and mname[i+1] == 'o') {
	mname[i] = '\0';
	--i;
	while (mname[i] != '/' and i >= 0) {
	    --i;
	}
D 17
	s = insert(identname(&mname[i+1], true));
	s->language = findlanguage(".s");
	s->class = MODULE;
I 6
	s->symvalue.funcv.beginaddr = 0;
	findbeginning(s);
E 17
I 17
	n = identname(&mname[i+1], true);
	find(s, n) where s->block == program and s->class == MODULE endfind(s);
	if (s == nil) {
	    s = insert(n);
	    s->language = findlanguage(".s");
	    s->class = MODULE;
	    s->symvalue.funcv.beginaddr = 0;
	    findbeginning(s);
	}
E 17
E 6
	if (curblock->class != PROG) {
	    exitblock();
	    if (curblock->class != PROG) {
		exitblock();
	    }
	}
	enterblock(s);
	curmodule = s;
    }
}

/*
I 11
 * Check to see if a symbol is about to be defined within an unnamed block.
 * If this happens, we create a procedure for the unnamed block, make it
 * "inline" so that tracebacks don't associate an activation record with it,
 * and enter it into the function table so that it will be detected
 * by "whatblock".
 */

D 15
private unnamed_block()
E 15
I 15
public chkUnnamedBlock ()
E 15
{
    register Symbol s;
    static int bnum = 0;
    char buf[100];
I 15
    Address startaddr;
E 15

D 15
    ++bnum;
    sprintf(buf, "$b%d", bnum);
    s = insert(identname(buf, false));
    s->class = PROG;
    s->symvalue.funcv.src = false;
    s->symvalue.funcv.inline = true;
    s->symvalue.funcv.beginaddr = addrstk[nesting];
    enterblock(s);
    newfunc(s, addrstk[nesting]);
    addrstk[nesting] = NOADDR;
E 15
I 15
    if (nesting > 0 and addrstk[nesting] != NOADDR) {
	startaddr = (linep - 1)->addr;
	++bnum;
	sprintf(buf, "$b%d", bnum);
	s = insert(identname(buf, false));
	s->language = curlang;
	s->class = PROC;
	s->symvalue.funcv.src = false;
	s->symvalue.funcv.inline = true;
	s->symvalue.funcv.beginaddr = startaddr;
	enterblock(s);
	newfunc(s, startaddr);
	addrstk[nesting] = NOADDR;
    }
E 15
}

/*
 * Compilation unit.  C associates scope with filenames
 * so we treat them as "modules".  The filename without
 * the suffix is used for the module name.
 *
 * Because there is no explicit "end-of-block" mark in
 * the object file, we must exit blocks for the current
 * procedure and module.
 */

D 15
private enterSourceModule(n, addr)
E 15
I 15
private enterSourceModule (n, addr)
E 15
Name n;
Address addr;
{
    register Symbol s;
    Name nn;
    String mname, suffix;

    mname = strdup(ident(n));
    if (rindex(mname, '/') != nil) {
	mname = rindex(mname, '/') + 1;
    }
    suffix = rindex(mname, '.');
I 19
    if (suffix > mname && *(suffix-1) == '.') {
	/* special hack for C++ */
	--suffix;
    }
E 19
    curlang = findlanguage(suffix);
    if (curlang == findlanguage(".f")) {
	strip_ = true;
    } 
    if (suffix != nil) {
	*suffix = '\0';
    }
D 15
    if (curblock->class != PROG) {
	exitblock();
E 15
I 15
    if (not (*language_op(curlang, L_HASMODULES))()) {
E 15
	if (curblock->class != PROG) {
	    exitblock();
I 15
	    if (curblock->class != PROG) {
		exitblock();
	    }
E 15
	}
I 15
	nn = identname(mname, true);
	if (curmodule == nil or curmodule->name != nn) {
	    s = insert(nn);
	    s->class = MODULE;
	    s->symvalue.funcv.beginaddr = 0;
	    findbeginning(s);
	} else {
	    s = curmodule;
	}
	s->language = curlang;
	enterblock(s);
	curmodule = s;
E 15
    }
D 15
    nn = identname(mname, true);
    if (curmodule == nil or curmodule->name != nn) {
	s = insert(nn);
	s->class = MODULE;
	s->symvalue.funcv.beginaddr = 0;
	findbeginning(s);
    } else {
	s = curmodule;
    }
    s->language = curlang;
    enterblock(s);
    curmodule = s;
E 15
    if (program->language == nil) {
	program->language = curlang;
    }
    warned = false;
    enterfile(ident(n), addr);
D 15
    bzero(typetable, sizeof(typetable));
E 15
I 15
    initTypeTable();
E 15
}

/*
E 11
D 15
 * Put an nlist into the symbol table.
 * If it's already there just add the associated information.
 *
 * Type information is encoded in the name following a ":".
 */

private Symbol constype();
private Char *curchar;

#define skipchar(ptr, ch) { \
    if (*ptr != ch) { \
	panic("expected char '%c', found char '%c'", ch, *ptr); \
    } \
    ++ptr; \
}

private entersym(str, np)
String str;
struct nlist *np;
{
    register Symbol s;
    register char *p;
    register int c;
    register Name n;
    register Integer i;
    Boolean knowtype, isnew;
    Symclass class;
    Integer level;

    p = index(str, ':');
    *p = '\0';
    c = *(p+1);
    n = identname(str, true);
    if (index("FfGV", c) != nil) {
	if (c == 'F' or c == 'f') {
	    class = FUNC;
	} else {
	    class = VAR;
	}
	level = (c == 'f' ? curmodule->level : program->level);
	find(s, n) where s->level == level and s->class == class endfind(s);
	if (s == nil) {
	    isnew = true;
	    s = insert(n);
	} else {
	    isnew = false;
	}
    } else {
	isnew = true;
	s = insert(n);
    }

I 11
    if (nesting > 0 and addrstk[nesting] != NOADDR) {
	unnamed_block();
    }

E 11
    /*
     * Default attributes.
     */
    s->language = curlang;
    s->class = VAR;
    s->block = curblock;
    s->level = curlevel;
    s->symvalue.offset = np->n_value;
    curchar = p + 2;
    knowtype = false;
    switch (c) {
	case 't':	/* type name */
	    s->class = TYPE;
	    i = getint();
	    if (i == 0) {
		panic("bad input on type \"%s\" at \"%s\"", symname(s),
		    curchar);
	    } else if (i >= NTYPES) {
		panic("too many types in file \"%s\"", curfilename());
	    }
	    /*
	     * A hack for C typedefs that don't create new types,
	     * e.g. typedef unsigned int Hashvalue;
I 5
	     *  or  typedef struct blah BLAH;
E 5
	     */
	    if (*curchar == '\0') {
		s->type = typetable[i];
		if (s->type == nil) {
D 5
		    panic("nil type for %d", i);
E 5
I 5
		    s->type = symbol_alloc();
		    typetable[i] = s->type;
E 5
		}
		knowtype = true;
	    } else {
		typetable[i] = s;
		skipchar(curchar, '=');
	    }
	    break;

	case 'T':	/* tag */
	    s->class = TAG;
	    i = getint();
	    if (i == 0) {
		panic("bad input on tag \"%s\" at \"%s\"", symname(s),
		    curchar);
	    } else if (i >= NTYPES) {
		panic("too many types in file \"%s\"", curfilename());
	    }
	    if (typetable[i] != nil) {
		typetable[i]->language = curlang;
		typetable[i]->class = TYPE;
		typetable[i]->type = s;
	    } else {
		typetable[i] = s;
	    }
	    skipchar(curchar, '=');
	    break;

	case 'F':	/* public function */
	case 'f':	/* private function */
	    s->class = FUNC;
	    if (curblock->class == FUNC or curblock->class == PROC) {
		exitblock();
	    }
	    enterblock(s);
	    if (c == 'F') {
		s->level = program->level;
		isnew = false;
	    }
	    curparam = s;
	    if (isnew) {
I 7
		s->symvalue.funcv.src = false;
I 11
		s->symvalue.funcv.inline = false;
E 11
E 7
		s->symvalue.funcv.beginaddr = np->n_value;
D 11
		newfunc(s);
E 11
I 11
		newfunc(s, codeloc(s));
E 11
		findbeginning(s);
	    }
	    break;

	case 'G':	/* public variable */
	    s->level = program->level;
	    break;

	case 'S':	/* private variable */
	    s->level = curmodule->level;
	    s->block = curmodule;
	    break;

I 8
/*
 *  keep global BSS variables chained so can resolve when get the start
 *  of common; keep the list in order so f77 can display all vars in a COMMON
*/
E 8
	case 'V':	/* own variable */
	    s->level = 2;
I 8
	    if (curcomm) {
	      if (commchain != nil) {
 		  commchain->symvalue.common.chain = s;
	      }			  
	      else {
		  curcomm->symvalue.common.offset = (int) s;
	      }			  
              commchain = s;
              s->symvalue.common.offset = np->n_value;
              s->symvalue.common.chain = nil;
	    }
E 8
	    break;

	case 'r':	/* register variable */
	    s->level = -(s->level);
	    break;

	case 'p':	/* parameter variable */
	    curparam->chain = s;
	    curparam = s;
	    break;

	case 'v':	/* varies parameter */
	    s->class = REF;
	    s->symvalue.offset = np->n_value;
	    curparam->chain = s;
	    curparam = s;
	    break;

	default:	/* local variable */
	    --curchar;
	    break;
    }
    if (not knowtype) {
	s->type = constype(nil);
	if (s->class == TAG) {
	    addtag(s);
	}
    }
    if (tracesyms) {
	printdecl(s);
	fflush(stdout);
    }
}

/*
 * Construct a type out of a string encoding.
 *
 * The forms of the string are
 *
 *	<number>
 *	<number>=<type>
 *	r<type>;<number>;<number>		$ subrange
 *	a<type>;<type>				$ array[index] of element
 *	s{<name>:<type>;<number>;<number>}	$ record
I 12
 *	S<type>					$ set
E 12
 *	*<type>					$ pointer
 */

I 12
private Rangetype getrangetype();

E 12
private Symbol constype(type)
Symbol type;
{
    register Symbol t, u;
    register Char *p, *cur;
    register Integer n;
    Integer b;
    Name name;
    Char class;

    b = curlevel;
    if (isdigit(*curchar)) {
	n = getint();
	if (n == 0) {
	    panic("bad type number at \"%s\"", curchar);
	} else if (n >= NTYPES) {
	    panic("too many types in file \"%s\"", curfilename());
	}
	if (*curchar == '=') {
	    if (typetable[n] != nil) {
		t = typetable[n];
	    } else {
		t = symbol_alloc();
		typetable[n] = t;
	    }
	    ++curchar;
	    constype(t);
	} else {
	    t = typetable[n];
	    if (t == nil) {
		t = symbol_alloc();
		typetable[n] = t;
	    }
	}
    } else {
	if (type == nil) {
	    t = symbol_alloc();
	} else {
	    t = type;
	}
	t->language = curlang;
	t->level = b;
I 8
	t->block = curblock;
E 8
	class = *curchar++;
	switch (class) {
I 8
D 12

E 12
E 8
	    case 'r':
		t->class = RANGE;
		t->type = constype(nil);
		skipchar(curchar, ';');
D 8
		t->symvalue.rangev.lower = getint();
E 8
I 8
D 12
                /* some letters indicate a dynamic bound, ie what follows
                   is the offset from the fp which contains the bound; this will
                   need a different encoding when pc a['A'..'Z'] is
                   added; J is a special flag to handle fortran a(*) bounds
                */
		switch(*curchar) {
			case 'A':
				t->symvalue.rangev.lowertype = R_ARG;
                  		curchar++;
			        break;

			case 'T':
				t->symvalue.rangev.lowertype = R_TEMP;
                  		curchar++;
			        break;

			case 'J': 
				t->symvalue.rangev.lowertype = R_ADJUST;
                  		curchar++;
			  	break;

			default:
				 t->symvalue.rangev.lowertype = R_CONST;
			  	 break;

		}
E 12
I 12
		t->symvalue.rangev.lowertype = getrangetype();
E 12
	        t->symvalue.rangev.lower = getint();
I 13
		skipchar(curchar, ';');
E 13
E 8
D 12
		skipchar(curchar, ';');
I 8
		switch(*curchar) {
			case 'A':
				t->symvalue.rangev.uppertype = R_ARG;
                  		curchar++;
			        break;

			case 'T':
				t->symvalue.rangev.uppertype = R_TEMP;
                  		curchar++;
			        break;

			case 'J': 
				t->symvalue.rangev.uppertype = R_ADJUST;
                  		curchar++;
			  	break;

			default:
				 t->symvalue.rangev.uppertype = R_CONST;
			  	 break;

		}
E 12
I 12
		t->symvalue.rangev.uppertype = getrangetype();
E 12
E 8
		t->symvalue.rangev.upper = getint();
		break;

	    case 'a':
		t->class = ARRAY;
		t->chain = constype(nil);
		skipchar(curchar, ';');
		t->type = constype(nil);
		break;

I 12
	    case 'S':
		t->class = SET;
		t->type = constype(nil);
		break;

E 12
	    case 's':
	    case 'u':
		t->class = (class == 's') ? RECORD : VARNT;
		t->symvalue.offset = getint();
		u = t;
		cur = curchar;
		while (*cur != ';' and *cur != '\0') {
		    p = index(cur, ':');
		    if (p == nil) {
			panic("index(\"%s\", ':') failed", curchar);
		    }
		    *p = '\0';
		    name = identname(cur, true);
		    u->chain = newSymbol(name, b, FIELD, nil, nil);
		    cur = p + 1;
		    u = u->chain;
		    u->language = curlang;
		    curchar = cur;
		    u->type = constype(nil);
		    skipchar(curchar, ',');
		    u->symvalue.field.offset = getint();
		    skipchar(curchar, ',');
		    u->symvalue.field.length = getint();
		    skipchar(curchar, ';');
		    cur = curchar;
		}
		if (*cur == ';') {
		    ++cur;
		}
		curchar = cur;
		break;

	    case 'e':
		t->class = SCAL;
		u = t;
		while (*curchar != ';' and *curchar != '\0') {
		    p = index(curchar, ':');
		    assert(p != nil);
		    *p = '\0';
		    u->chain = insert(identname(curchar, true));
		    curchar = p + 1;
		    u = u->chain;
		    u->language = curlang;
		    u->class = CONST;
		    u->level = b;
		    u->block = curblock;
		    u->type = t;
		    u->symvalue.iconval = getint();
		    skipchar(curchar, ',');
		}
I 14
		if (*curchar == ';')
			curchar++;
E 14
		break;

	    case '*':
		t->class = PTR;
		t->type = constype(nil);
		break;

	    case 'f':
		t->class = FUNC;
		t->type = constype(nil);
		break;

	    default:
		badcaseval(class);
	}
I 12
    }
    return t;
}

/*
 * Get a range type.
 *
 * Special letters indicate a dynamic bound, i.e. what follows
 * is the offset from the fp which contains the bound.
 * J is a special flag to handle fortran a(*) bounds.
 */

private Rangetype getrangetype()
{
    Rangetype t;

    switch (*curchar) {
	case 'A':
	    t = R_ARG;
	    curchar++;
	    break;

	case 'T':
	    t = R_TEMP;
	    curchar++;
	    break;

	case 'J': 
	    t = R_ADJUST;
	    curchar++;
	    break;

	default:
	    t = R_CONST;
	    break;
E 12
    }
    return t;
}

/*
 * Read an integer from the current position in the type string.
 */

private Integer getint()
{
    register Integer n;
    register char *p;
    register Boolean isneg;

    n = 0;
    p = curchar;
    if (*p == '-') {
	isneg = true;
	++p;
    } else {
	isneg = false;
    }
    while (isdigit(*p)) {
	n = 10*n + (*p - '0');
	++p;
    }
    curchar = p;
    return isneg ? (-n) : n;
}

/*
 * Add a tag name.  This is a kludge to be able to refer
 * to tags that have the same name as some other symbol
 * in the same block.
 */

private addtag(s)
register Symbol s;
{
    register Symbol t;
    char buf[100];

    sprintf(buf, "$$%.90s", ident(s->name));
    t = insert(identname(buf, false));
    t->language = s->language;
    t->class = TAG;
    t->type = s->type;
    t->block = s->block;
}

/*
E 15
 * Allocate file and line tables and initialize indices.
 */

D 15
private allocmaps(nf, nl)
Integer nf, nl;
E 15
I 15
private allocmaps (nf, nl)
integer nf, nl;
E 15
{
    if (filetab != nil) {
	dispose(filetab);
    }
    if (linetab != nil) {
	dispose(linetab);
    }
    filetab = newarr(Filetab, nf);
    linetab = newarr(Linetab, nl);
    filep = filetab;
    linep = linetab;
}

/*
 * Add a file to the file table.
I 10
 *
 * If the new address is the same as the previous file address
 * this routine used to not enter the file, but this caused some
 * problems so it has been removed.  It's not clear that this in
 * turn may not also cause a problem.
E 10
 */

D 15
private enterfile(filename, addr)
E 15
I 15
private enterfile (filename, addr)
E 15
String filename;
Address addr;
{
D 10
    if (addr != curfaddr) {
	filep->addr = addr;
	filep->filename = filename;
	filep->lineindex = linep - linetab;
	++filep;
	curfaddr = addr;
    }
E 10
I 10
    filep->addr = addr;
    filep->filename = filename;
    filep->lineindex = linep - linetab;
    ++filep;
E 10
}

/*
 * Since we only estimated the number of lines (and it was a poor
 * estimation) and since we need to know the exact number of lines
 * to do a binary search, we set it when we're done.
 */

D 15
private setnlines()
E 15
I 15
private setnlines ()
E 15
{
    nlhdr.nlines = linep - linetab;
}

/*
 * Similarly for nfiles ...
 */

D 15
private setnfiles()
E 15
I 15
private setnfiles ()
E 15
{
    nlhdr.nfiles = filep - filetab;
    setsource(filetab[0].filename);
}
E 1
