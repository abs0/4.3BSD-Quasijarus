h52004
s 00008/00003/00053
d D 5.1 85/06/06 11:26:34 dist 3 2
c Add copyright
e
s 00030/00024/00026
d D 1.2 82/02/17 18:51:12 linton 2 1
c another multiple files bug
e
s 00050/00000/00000
d D 1.1 82/01/18 19:20:34 linton 1 0
c date and time created 82/01/18 19:20:34 by linton
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
D 2
 * lookup the object address of a given line from the given file
E 2
I 2
 * Lookup the object address of a given line from the named file.
 *
 * Potentially all files in the file table need to be checked
 * until the line is found since a particular file name may appear
 * more than once in the file table (caused by includes).
E 2
 */

#include "defs.h"
#include "mappings.h"
#include "object.h"
#include "source.h"
#include "filetab.h"
#include "linetab.h"

ADDRESS objaddr(line, name)
LINENO line;
char *name;
{
D 2
	register FILETAB *ftp;
	register LINENO i, j;
E 2
I 2
    register FILETAB *ftp;
    register LINENO i, j;
    BOOLEAN foundfile;
E 2

D 2
	if (nlhdr.nlines == 0) {
		return(-1);
	}
	if (name == NULL) {
		name = cursource;
	}
	for (ftp = &filetab[0]; ftp < &filetab[nlhdr.nfiles]; ftp++) {
		if (strcmp(ftp->filename, name) == 0) {
			break;
		}
	}
	if (ftp == &filetab[nlhdr.nfiles]) {
		error("unknown source file \"%s\"", name);
	}
	i = ftp->lineindex;
	if (ftp == &filetab[nlhdr.nfiles-1]) {
E 2
I 2
    if (nlhdr.nlines == 0) {
	return(-1);
    }
    if (name == NULL) {
	name = cursource;
    }
    foundfile = FALSE;
    for (ftp = &filetab[0]; ftp < &filetab[nlhdr.nfiles]; ftp++) {
	if (streq(ftp->filename, name)) {
	    foundfile = TRUE;
	    i = ftp->lineindex;
	    if (ftp == &filetab[nlhdr.nfiles-1]) {
E 2
		j = nlhdr.nlines;
D 2
	} else {
E 2
I 2
	    } else {
E 2
		j = (ftp + 1)->lineindex;
D 2
	}
	while (i < j) {
E 2
I 2
	    }
	    while (i < j) {
E 2
		if (linetab[i].line == line) {
D 2
			return(linetab[i].addr);
E 2
I 2
		    return linetab[i].addr;
E 2
		}
		i++;
I 2
	    }
E 2
	}
D 2
	return(-1);
E 2
I 2
    }
    if (!foundfile) {
	error("unknown source file \"%s\"", name);
    }
    return(-1);
E 2
}
E 1
