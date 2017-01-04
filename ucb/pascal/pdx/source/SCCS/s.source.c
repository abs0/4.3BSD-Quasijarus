h05740
s 00008/00003/00150
d D 5.1 85/06/06 11:51:38 dist 5 4
c Add copyright
e
s 00006/00006/00147
d D 1.4 83/03/24 17:52:59 linton 4 3
c fixed seek addresses for large files
e
s 00001/00001/00152
d D 1.3 83/03/24 16:40:52 linton 3 2
c upped some limits for large programs (> 10000 lines)
e
s 00079/00070/00074
d D 1.2 82/02/11 23:54:28 linton 2 1
c changed skimsource so that it just returns if the given filename 
c is the same as the current source filename ... this way routines from the 
c outside needn't test this
e
s 00144/00000/00000
d D 1.1 82/01/18 19:21:09 linton 1 0
c date and time created 82/01/18 19:21:09 by linton
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
E 5
/*
D 2
 * source file management
E 2
I 2
 * Source file management.
E 2
 */

#include "defs.h"
#include "source.h"

/*
D 2
 * data structure for indexing source seek addresses by line number
E 2
I 2
 * Seektab is the data structure used for indexing source
 * seek addresses by line number.
E 2
 *
 * The constraints are:
 *
D 2
 *	we want an array so indexing is fast and easy
 *	we don't want to waste space for small files
 *	we don't want an upper bound on # of lines in a file
 *	we don't know how many lines there are
E 2
I 2
 *  we want an array so indexing is fast and easy
 *  we don't want to waste space for small files
 *  we don't want an upper bound on # of lines in a file
 *  we don't know how many lines there are
E 2
 *
D 4
 * The solution is a "dirty" hash table.  We have NSLOTS pointers to
E 4
I 4
 * The solution is a sparse array. We have NSLOTS pointers to
E 4
 * arrays of NLINESPERSLOT addresses.  To find the source address of
 * a particular line we find the slot, allocate space if necessary,
 * and then find its location within the pointed to array.
I 2
 *
 * As a result, there is a limit of NSLOTS*NLINESPERSLOT lines per file
 * but this is plenty high and still fairly inexpensive.
 *
 * This implementation maintains only one source file at any given
 * so as to avoid consuming too much memory.  In an environment where
 * memory is less constrained and one expects to be changing between
 * files often enough, it would be reasonable to have multiple seek tables.
E 2
 */

typedef int SEEKADDR;

D 3
#define NSLOTS 20
E 3
I 3
#define NSLOTS 40
E 3
#define NLINESPERSLOT 500

D 2
#define slotno(line)	((line)/NLINESPERSLOT)
#define index(line)	((line)%NLINESPERSLOT)
#define slot_alloc()	alloc(NLINESPERSLOT, SEEKADDR)
#define srcaddr(line)	seektab[(line)/NLINESPERSLOT][(line)%NLINESPERSLOT]
E 2
I 2
D 4
#define slotno(line)    ((line)/NLINESPERSLOT)
#define index(line) ((line)%NLINESPERSLOT)
#define slot_alloc()    alloc(NLINESPERSLOT, SEEKADDR)
#define srcaddr(line)   seektab[(line)/NLINESPERSLOT][(line)%NLINESPERSLOT]
E 4
I 4
#define slotno(line)	((line)/NLINESPERSLOT)
#define index(line)	((line)%NLINESPERSLOT)
#define slot_alloc()	alloc(NLINESPERSLOT, SEEKADDR)
#define srcaddr(line)	seektab[(line)/NLINESPERSLOT][(line)%NLINESPERSLOT]
E 4
E 2

LOCAL SEEKADDR *seektab[NSLOTS];

LOCAL FILE *srcfp;

/*
 * check to make sure a source line number is valid
 */

chkline(linenum)
register LINENO linenum;
{
D 2
	if (linenum < 1) {
		error("line number must be positive");
	}
	if (linenum > lastlinenum) {
		error("not that many lines");
	}
E 2
I 2
    if (linenum < 1) {
	error("line number must be positive");
    }
    if (linenum > lastlinenum) {
	error("not that many lines");
    }
E 2
}

/*
 * print out the given lines from the source
 */

printlines(l1, l2)
LINENO l1, l2;
{
D 2
	register int c;
	register LINENO i;
	register FILE *fp;
E 2
I 2
    register int c;
    register LINENO i;
    register FILE *fp;
E 2

D 2
	chkline(l1);
	chkline(l2);
	if (l2 < l1) {
		error("second line number less than first");
E 2
I 2
    chkline(l1);
    chkline(l2);
    if (l2 < l1) {
	error("second line number less than first");
    }
    fp = srcfp;
    fseek(fp, (long) srcaddr(l1), 0);
    for (i = l1; i <= l2; i++) {
	printf("%5d   ", i);
	while ((c = getc(fp)) != '\n') {
	    putchar(c);
E 2
	}
D 2
	fp = srcfp;
	fseek(fp, (long) srcaddr(l1), 0);
	for (i = l1; i <= l2; i++) {
		printf("%5d   ", i);
		while ((c = getc(fp)) != '\n') {
			putchar(c);
		}
		putchar('\n');
	}
E 2
I 2
	putchar('\n');
    }
E 2
}

/*
 * read the source file getting seek pointers for each line
 */

skimsource(file)
char *file;
{
D 2
	register int c;
	register LINENO count;
	register FILE *fp;
	register LINENO linenum;
	register SEEKADDR lastaddr;
	register int slot;
E 2
I 2
    register int c;
D 4
    register LINENO count;
E 4
I 4
    register SEEKADDR count;
E 4
    register FILE *fp;
    register LINENO linenum;
    register SEEKADDR lastaddr;
    register int slot;
E 2

D 2
	if (file == NIL) {
		return;
E 2
I 2
    if (file == NIL || file == cursource) {
	return;
    }
    if ((fp = fopen(file, "r")) == NULL) {
	panic("can't open \"%s\"", file);
    }
    if (cursource != NIL) {
	free_seektab();
    }
    cursource = file;
    linenum = 0, count = 0, lastaddr = 0;
    while ((c = getc(fp)) != EOF) {
	count++;
	if (c == '\n') {
	    slot = slotno(++linenum);
	    if (slot >= NSLOTS) {
		panic("skimsource: too many lines");
	    }
	    if (seektab[slot] == NIL) {
		seektab[slot] = slot_alloc();
	    }
	    seektab[slot][index(linenum)] = lastaddr;
	    lastaddr = count;
E 2
	}
D 2
	if ((fp = fopen(file, "r")) == NULL) {
		panic("can't open \"%s\"", file);
	}
	if (cursource != NIL) {
		free_seektab();
	}
	cursource = file;
	linenum = 0, count = 0, lastaddr = 0;
	while ((c = getc(fp)) != EOF) {
		count++;
		if (c == '\n') {
			slot = slotno(++linenum);
			if (slot >= NSLOTS) {
				panic("skimsource: too many lines");
			}
			if (seektab[slot] == NIL) {
				seektab[slot] = slot_alloc();
			}
			seektab[slot][index(linenum)] = lastaddr;
			lastaddr = count;
		}
	}
	lastlinenum = linenum;
	srcfp = fp;
E 2
I 2
    }
    lastlinenum = linenum;
    srcfp = fp;
E 2
}

/*
 * Erase information and release space in the current seektab.
 * This is in preparation for reading in seek pointers for a
 * new file.  It is possible that seek pointers for all files
 * should be kept around, but the current concern is space.
 */

LOCAL free_seektab()
{
D 2
	register int slot;
E 2
I 2
    register int slot;
E 2

D 2
	for (slot = 0; slot < NSLOTS; slot++) {
		if (seektab[slot] != NIL) {
			free(seektab[slot]);
			seektab[slot] = NIL;
		}
E 2
I 2
    for (slot = 0; slot < NSLOTS; slot++) {
	if (seektab[slot] != NIL) {
	    free(seektab[slot]);
	    seektab[slot] = NIL;
E 2
	}
I 2
    }
E 2
}
E 1
