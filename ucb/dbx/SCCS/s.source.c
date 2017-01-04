h33643
s 00024/00010/00463
d D 5.2 88/01/12 01:17:54 donn 15 14
c merge in latest Linton version, plus $listwindow changes
e
s 00008/00002/00465
d D 5.1 85/05/31 10:17:03 dist 14 13
c Add copyright
e
s 00149/00059/00318
d D 1.12 85/03/01 20:31:22 linton 13 12
c update to version 3.0
e
s 00001/00003/00376
d D 1.11 84/06/23 11:43:44 sam 12 10
i 11
c merge linton branch delta trail
e
s 00003/00001/00312
d D 1.9.1.1 84/06/23 10:50:17 sam 11 9
c branch delta of linton changes from net.sources
e
s 00068/00004/00309
d D 1.10 84/06/23 10:39:45 sam 10 9
c add re pattern search of source code
e
s 00075/00010/00238
d D 1.9 83/08/05 02:54:59 linton 9 8
c moved edit procedure here, changed it to use "sourcepath", 
c this in turn suggested some cleanup of this stuff
e
s 00010/00006/00238
d D 1.8 83/05/20 10:58:40 linton 8 7
c fixed problem with opening absolute pathnames
e
s 00000/00002/00244
d D 1.7 83/04/25 18:44:13 linton 7 6
c changed an inaccurate comment
e
s 00003/00001/00243
d D 1.6 83/04/04 11:52:44 linton 6 5
c fixed setting of cursrcline so it doesn't become 0
e
s 00002/00002/00242
d D 1.5 83/02/16 23:09:08 linton 5 4
c changed "pc - 1" to "pc" in getsrcpos, the source module has no business 
c knowing what's going on here and besides it was wrong
e
s 00003/00003/00241
d D 1.4 83/01/24 14:28:15 linton 4 3
c fixed large line number / seek address bug
e
s 00004/00002/00240
d D 1.3 82/12/18 23:27:39 linton 3 2
c uses srcline(pc - 1) rather than srcline(pc) since pc is address 
c of next instruction
e
s 00001/00001/00241
d D 1.2 82/12/15 04:22:13 linton 2 1
c fixed @(#) stuff
e
s 00242/00000/00000
d D 1.1 82/12/15 04:08:46 linton 1 0
c date and time created 82/12/15 04:08:46 by linton
e
u
U
f b 
t
T
I 1
D 14
/* Copyright (c) 1982 Regents of the University of California */
E 14
I 14
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 14

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 11
static char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
D 12
static char sccsid[] = "@(#)source.c 1.9 8/5/83";

static char rcsid[] = "$Header: source.c,v 1.3 84/03/27 10:23:58 linton Exp $";
E 12
I 12
D 14
static	char sccsid[] = "%W% (Berkeley) %G%";
E 14
I 14
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 14
E 12
E 11
E 2

I 13
D 15
static char rcsid[] = "$Header: source.c,v 1.4 84/06/07 16:29:38 linton Exp $";
E 15
I 15
static char rcsid[] = "$Header: source.c,v 1.3 87/08/19 15:19:40 mike Exp $";
E 15

E 13
/*
 * Source file management.
 */

#include "defs.h"
#include "source.h"
#include "object.h"
#include "mappings.h"
#include "machine.h"
I 13
#include "keywords.h"
#include "tree.h"
#include "eval.h"
E 13
I 10
D 15
#include <sys/file.h>
E 15
I 15
#ifdef IRIS
#   define R_OK 04	/* read access */
#   define L_SET 01	/* absolute offset for seek */
#else
#   include <sys/file.h>
#endif
E 15
E 10

#ifndef public
typedef int Lineno;

String cursource;
Lineno curline;
Lineno cursrcline;

#define LASTLINE 0		/* recognized by printlines */

#include "lists.h"

List sourcepath;
#endif

I 15
#ifdef IRIS
#   define re_comp regcmp
#   define re_exec(buf) (regex(buf) != NULL)
#endif

E 15
I 13
extern char *re_comp();

E 13
private Lineno lastlinenum;
private String prevsource = nil;

/*
 * Data structure for indexing source seek addresses by line number.
 *
 * The constraints are:
 *
 *  we want an array so indexing is fast and easy
 *  we don't want to waste space for small files
 *  we don't want an upper bound on # of lines in a file
 *  we don't know how many lines there are
 *
 * The solution is a "dirty" hash table.  We have NSLOTS pointers to
 * arrays of NLINESPERSLOT addresses.  To find the source address of
 * a particular line we find the slot, allocate space if necessary,
 * and then find its location within the pointed to array.
 */

D 4
typedef int Seekaddr;
E 4
I 4
typedef long Seekaddr;
E 4

D 13
#define NSLOTS 20
E 13
I 13
#define NSLOTS 40
E 13
#define NLINESPERSLOT 500

#define slotno(line)    ((line) div NLINESPERSLOT)
#define index(line)	((line) mod NLINESPERSLOT)
#define slot_alloc()    newarr(Seekaddr, NLINESPERSLOT)
#define srcaddr(line)	seektab[slotno(line)][index(line)]

private File srcfp;
private Seekaddr *seektab[NSLOTS];

/*
I 13
 * Determine if the current source file is available.
 */

public boolean canReadSource ()
{
    boolean b;

    if (cursource == nil) {
	b = false;
    } else if (cursource != prevsource) {
	skimsource();
	b = (boolean) (lastlinenum != 0);
    } else {
	b = true;
    }
    return b;
}

/*
E 13
 * Print out the given lines from the source.
 */

public printlines(l1, l2)
Lineno l1, l2;
{
    register int c;
    register Lineno i, lb, ub;
    register File f;

    if (cursource == nil) {
	beginerrmsg();
	fprintf(stderr, "no source file\n");
    } else {
	if (cursource != prevsource) {
	    skimsource();
	}
	if (lastlinenum == 0) {
	    beginerrmsg();
	    fprintf(stderr, "couldn't read \"%s\"\n", cursource);
	} else {
D 13
	    lb = (l1 == 0) ? lastlinenum : l1;
	    ub = (l2 == 0) ? lastlinenum : l2;
E 13
I 13
	    lb = (l1 == LASTLINE) ? lastlinenum : l1;
	    ub = (l2 == LASTLINE) ? lastlinenum : l2;
E 13
	    if (lb < 1) {
		beginerrmsg();
		fprintf(stderr, "line number must be positive\n");
	    } else if (lb > lastlinenum) {
		beginerrmsg();
		if (lastlinenum == 1) {
		    fprintf(stderr, "\"%s\" has only 1 line\n", cursource);
		} else {
		    fprintf(stderr, "\"%s\" has only %d lines\n",
			cursource, lastlinenum);
		}
	    } else if (ub < lb) {
		beginerrmsg();
		fprintf(stderr, "second number must be greater than first\n");
	    } else {
		if (ub > lastlinenum) {
		    ub = lastlinenum;
		}
		f = srcfp;
D 4
		fseek(f, (long) srcaddr(lb), 0);
E 4
I 4
		fseek(f, srcaddr(lb), 0);
E 4
		for (i = lb; i <= ub; i++) {
		    printf("%5d   ", i);
		    while ((c = getc(f)) != '\n') {
			putchar(c);
		    }
		    putchar('\n');
		}
		cursrcline = ub + 1;
	    }
	}
    }
}

/*
D 9
 * Open a source file looking in the appropriate places.
E 9
I 9
 * Search the sourcepath for a file.
E 9
 */

D 9
public File opensource(filename)
E 9
I 9
static char fileNameBuf[1024];

public String findsource(filename)
E 9
String filename;
{
D 9
    register String dir;
    char buf[256];
    File f;
E 9
I 9
D 10
    register File f;
E 10
    register String src, dir;
E 9

D 9
    f = nil;
E 9
D 8
    foreach (String, dir, sourcepath)
	sprintf(buf, "%s/%s", dir, filename);
	f = fopen(buf, "r");
	if (f != nil) {
	    break;
E 8
I 8
    if (filename[0] == '/') {
D 9
	f = fopen(filename, "r");
E 9
I 9
	src = filename;
E 9
    } else {
I 9
	src = nil;
E 9
	foreach (String, dir, sourcepath)
D 9
	    sprintf(buf, "%s/%s", dir, filename);
	    f = fopen(buf, "r");
E 9
I 9
	    sprintf(fileNameBuf, "%s/%s", dir, filename);
D 10
	    f = fopen(fileNameBuf, "r");
E 9
	    if (f != nil) {
I 9
		fclose(f);
E 10
I 10
	    if (access(fileNameBuf, R_OK) == 0) {
E 10
		src = fileNameBuf;
E 9
		break;
E 8
D 9
	}
E 9
I 9
	    }
E 9
D 8
    endfor
E 8
I 8
	endfor
    }
I 9
    return src;
}

/*
 * Open a source file looking in the appropriate places.
 */

public File opensource(filename)
String filename;
{
    String s;
    File f;

    s = findsource(filename);
    if (s == nil) {
	f = nil;
    } else {
	f = fopen(s, "r");
    }
E 9
E 8
    return f;
}

/*
 * Set the current source file.
 */

public setsource(filename)
String filename;
{
    if (filename != nil and filename != cursource) {
	prevsource = cursource;
	cursource = filename;
	cursrcline = 1;
    }
}

/*
 * Read the source file getting seek pointers for each line.
 */

private skimsource()
{
    register int c;
D 4
    register Lineno count;
E 4
I 4
    register Seekaddr count;
E 4
    register File f;
    register Lineno linenum;
    register Seekaddr lastaddr;
    register int slot;

    f = opensource(cursource);
    if (f == nil) {
	lastlinenum = 0;
    } else {
	if (prevsource != nil) {
	    free_seektab();
	    if (srcfp != nil) {
		fclose(srcfp);
	    }
	}
	prevsource = cursource;
	linenum = 0;
	count = 0;
	lastaddr = 0;
	while ((c = getc(f)) != EOF) {
	    ++count;
	    if (c == '\n') {
		slot = slotno(++linenum);
		if (slot >= NSLOTS) {
		    panic("skimsource: too many lines");
		}
		if (seektab[slot] == nil) {
		    seektab[slot] = slot_alloc();
		}
		seektab[slot][index(linenum)] = lastaddr;
		lastaddr = count;
	    }
	}
	lastlinenum = linenum;
	srcfp = f;
    }
}

/*
 * Erase information and release space in the current seektab.
 * This is in preparation for reading in seek pointers for a
 * new file.  It is possible that seek pointers for all files
 * should be kept around, but the current concern is space.
 */

private free_seektab()
{
    register int slot;

    for (slot = 0; slot < NSLOTS; slot++) {
	if (seektab[slot] != nil) {
	    dispose(seektab[slot]);
	}
    }
}

/*
 * Figure out current source position.
I 3
D 7
 * Have to use "pc - 1" because pc is the address of the next instruction
 * rather than the current one.
E 7
E 3
 */

public getsrcpos()
{
    String filename;

D 3
    curline = srcline(pc);
    filename = srcfilename(pc);
E 3
I 3
D 5
    curline = srcline(pc - 1);
    filename = srcfilename(pc - 1);
E 5
I 5
    curline = srcline(pc);
    filename = srcfilename(pc);
E 5
E 3
    setsource(filename);
D 6
    cursrcline = curline;
E 6
I 6
    if (curline != 0) {
	cursrcline = curline;
    }
E 6
}

/*
 * Print out the current source position.
 */

public printsrcpos()
{
    printf("at line %d", curline);
    if (nlhdr.nfiles > 1) {
	printf(" in file \"%s\"", cursource);
    }
I 9
}

#define DEF_EDITOR  "vi"

/*
 * Invoke an editor on the given file.  Which editor to use might change
 * installation to installation.  For now, we use "vi".  In any event,
 * the environment variable "EDITOR" overrides any default.
 */

public edit(filename)
String filename;
{
    extern String getenv();
    String ed, src, s;
    Symbol f;
    Address addr;
    char lineno[10];

    ed = getenv("EDITOR");
    if (ed == nil) {
	ed = DEF_EDITOR;
    }
    src = findsource((filename != nil) ? filename : cursource);
    if (src == nil) {
	f = which(identname(filename, true));
	if (not isblock(f)) {
	    error("can't read \"%s\"", filename);
	}
	addr = firstline(f);
	if (addr == NOADDR) {
	    error("no source for \"%s\"", filename);
	}
	src = srcfilename(addr);
	s = findsource(src);
	if (s != nil) {
	    src = s;
	}
	sprintf(lineno, "+%d", srcline(addr));
    } else {
	sprintf(lineno, "+1");
    }
D 13
    call(ed, stdin, stdout, lineno, src, nil);
E 13
I 13
    if (streq(ed, "vi") or streq(ed, "ex")) {
	call(ed, stdin, stdout, lineno, src, nil);
    } else {
	call(ed, stdin, stdout, src, nil);
    }
E 13
I 10
}

D 13
#include "re.h"
E 13
/*
D 13
 * Search the current file with
 * a regular expression.
E 13
I 13
 * Strip away portions of a given pattern not part of the regular expression.
E 13
 */
D 13
public search(forward, re)
	Boolean forward;
	String re;
E 13
I 13

private String getpattern (pattern)
String pattern;
E 13
{
D 13
	register String p;
	register File f;
	register Lineno line;
	Lineno l1, l2;
	Boolean matched;
	Char buf[512];
	
	if (cursource == nil) {
		beginerrmsg();
		fprintf(stderr, "No source file.\n");
		return;
E 13
I 13
    register char *p, *r;

    p = pattern;
    while (*p == ' ' or *p == '\t') {
	++p;
    }
    r = p;
    while (*p != '\0') {
	++p;
    }
    --p;
    if (*p == '\n') {
	*p = '\0';
	--p;
    }
    if (*p == *r) {
	*p = '\0';
	--p;
    }
    return r + 1;
}

/*
 * Search the current file for a regular expression.
 */

public search (direction, pattern)
char direction;
String pattern;
{
    register String p;
    register File f;
    String re, err;
    Lineno line;
    boolean matched;
    char buf[512];
    
    if (cursource == nil) {
	beginerrmsg();
	fprintf(stderr, "no source file\n");
    } else {
	if (cursource != prevsource) {
	    skimsource();
E 13
	}
D 13
	if (cursource != prevsource)
		skimsource();
E 13
	if (lastlinenum == 0) {
D 13
		beginerrmsg();
		fprintf(stderr, "Couldn't read \"%s\"\n", cursource);
		return;
	}
	circf = 0;
	if (re != nil && *re != '\0')
		recompile(re);
	matched = false;
	f = srcfp;
	line = cursrcline;
	do {
		if (forward) {
			line++;
			if (line > lastlinenum)
				line = 1;
E 13
I 13
	    beginerrmsg();
	    fprintf(stderr, "couldn't read \"%s\"\n", cursource);
	} else {
	    re = getpattern(pattern);
	    /* circf = 0; */
	    if (re != nil and *re != '\0') {
		err = re_comp(re);
		if (err != nil) {
		    error(err);
		}
	    }
	    matched = false;
	    f = srcfp;
	    line = cursrcline;
	    do {
		if (direction == '/') {
		    ++line;
		    if (line > lastlinenum) {
			line = 1;
		    }
E 13
		} else {
D 13
			line--;
			if (line < 1)
				line = lastlinenum;
E 13
I 13
		    --line;
		    if (line < 1) {
			line = lastlinenum;
		    }
E 13
		}
		fseek(f, srcaddr(line), L_SET);
D 13
		for (p = buf; (*p = getc(f)) != '\n'; p++)
			if (*p == EOF)
				error("Unexpected EOF.");
E 13
I 13
		p = buf;
		*p = getc(f);
		while ((*p != '\n') and (*p != EOF)) {
		    ++p;
		    *p = getc(f);
		}
E 13
		*p = '\0';
D 13
		matched = (Boolean)rematch(buf);
		if (matched)
			break;
	} while (line != cursrcline);
	if (!matched)
		error("No match");
#define	WINDOW	10		/* should be used globally */
	l1 = line - WINDOW / 2;
	if (l1 < 1)
		l1 = 1;
	l2 = line + WINDOW / 2;
	if (l2 > lastlinenum)
		l2 = lastlinenum;
	printlines(l1, l2);
	cursrcline = line;	/* override printlines */
E 13
I 13
		matched = (boolean) re_exec(buf);
	    } while (not matched and line != cursrcline);
	    if (not matched) {
		beginerrmsg();
		fprintf(stderr, "no match\n");
	    } else {
		printlines(line, line);
		cursrcline = line;
	    }
	}
    }
}

I 15
public integer srcwindowlen ()
{
    Node s;

    s = findvar(identname("$listwindow", true));
    if (s == nil)
	return 10;
    eval(s);
    return pop(integer);
}

E 15
/*
 * Compute a small window around the given line.
 */

public getsrcwindow (line, l1, l2)
Lineno line, *l1, *l2;
{
D 15
    Node s;
E 15
    integer size;

D 15
    s = findvar(identname("$listwindow", true));
    if (s == nil) {
	size = 10;
    } else {
	eval(s);
	size = pop(integer);
    }
E 15
I 15
    size = srcwindowlen();
E 15
    *l1 = line - (size div 2);
    if (*l1 < 1) {
	*l1 = 1;
    }
    *l2 = *l1 + size;
    if (lastlinenum != LASTLINE and *l2 > lastlinenum) {
	*l2 = lastlinenum;
    }
E 13
E 10
E 9
}
E 1
