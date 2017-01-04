h55516
s 00007/00003/00313
d D 5.1 85/06/05 14:51:47 dist 9 8
c Add copyright
e
s 00000/00000/00316
d D 2.1 84/02/08 20:48:50 aoki 8 7
c synchronize to version 2
e
s 00000/00000/00316
d D 1.7 83/09/19 07:00:44 thien 7 6
c Restoring to unlinted version
e
s 00029/00025/00287
d D 1.6 83/08/19 05:02:11 thien 6 5
c The changes were made to allow successful linting
e
s 00001/00001/00311
d D 1.5 82/08/26 18:48:39 mckusick 5 4
c convert namelist structure to use unions
e
s 00010/00005/00302
d D 1.4 82/04/01 16:04:25 peter 4 3
c pdx header files are found in ../pdx.  this for make depend.
e
s 00006/00003/00301
d D 1.3 82/02/11 23:30:56 linton 3 2
c changed relative line number and address information to be 
c two bytes wide rather than one
e
s 00029/00003/00275
d D 1.2 82/02/02 12:58:16 linton 2 1
c new for pi to dump symbolic information for pdx
e
s 00278/00000/00000
d D 1.1 82/01/18 16:43:41 linton 1 0
c date and time created 82/01/18 16:43:41 by linton
e
u
U
t
T
I 1
D 9
/* Copyright (c) 1982 Regents of the University of California */
E 9
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 9

I 6
#ifndef lint
E 6
D 9
static char sccsid[] = "%Z%%M% %I% %G%";
I 6
#endif
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 6

/*
 * savenl - routines for saving namelist and line number information
 *
 * This module contains the routines that make pi dump a namelist
 * at the end of the object file.  We do this by first creating
 * four temporary files in "startnlfile".  One temp file contains
 * the string table, one the symbol table, one the file name
 * information and one the line number information.
 *
 * Prior to generation of the code for a statement the "lineno"
 * routine is called to dump the line number and current object
 * address.  At the end of each block "savenl" is called to dump
 * the strings and symbol structures.
 *
 * At the end of execution "copynlfile" is called and it copies
 * the temp files onto the end of the obj file.
 *
 * In case of error, "removenlfile" is called to destroy the temp files.
 *
 * The only other changes to pi are in calling these routines from
 *
 * 	"main"		(main.c)
 *	"yymain"	(yymain.c)
 *	"funcend"	(fend.c)
 *	"yyget"		(yyget.c)
 *	"putline"	(stat.c)
 */

#include "whoami.h"
I 4
#ifdef OBJ
        /*
	 *	and the rest of the file
	 */
E 4
#include "0.h"
I 2
#include "objfmt.h"
E 2

#undef NIL

/*
 * pdx header files
 */

D 4
#include "defs.h"
#include "object.h"
#include "object/objsym.rep"
#include "mappings.h"
#include "mappings/filetab.h"
E 4
I 4
#include "../pdx/defs.h"
#include "../pdx/object.h"
#include "../pdx/object/objsym.rep"
#include "../pdx/mappings.h"
#include "../pdx/mappings/filetab.h"
E 4

LOCAL char *symname = "/tmp/obj.symXXXX";
LOCAL char *strname = "/tmp/obj.strXXXX";
LOCAL char *filesname = "/tmp/obj.filesXXXX";
LOCAL char *linesname = "/tmp/obj.linesXXXX";

LOCAL FILE *symfp;
LOCAL FILE *strfp;
LOCAL FILE *filesfp;
LOCAL FILE *linesfp;

I 2
LOCAL long nlsize;

I 6
extern FILE *fopen();

E 6
E 2
/*
 * create temporary files for the namelist info
 */

startnlfile()
{
I 2
	nlsize = 0;
E 2
D 6
	mktemp(symname);
	mktemp(strname);
	mktemp(filesname);
	mktemp(linesname);
E 6
I 6
	(void) mktemp(symname);
	(void) mktemp(strname);
	(void) mktemp(filesname);
	(void) mktemp(linesname);
E 6
	symfp = fopen(symname, "w");
	strfp = fopen(strname, "w");
	filesfp = fopen(filesname, "w");
	linesfp = fopen(linesname, "w");
	if (symfp==NULL || strfp==NULL || filesfp==NULL || linesfp==NULL) {
		fprintf(stderr, "can't create /tmp/obj");
		pexit(NOSTART);
	}
	newfile(filename, 1);
}

/*
 * now copy the temp files back to obj; strings, symbols, file names, and lines
 *
 * There's some efficiency garbage here that uses straight system
 * calls rather than standard I/O library calls.
 */

copynlfile()
{
	register int n;
I 6
	extern long lseek();
E 6
	int symfd, strfd, filesfd, linesfd;
	char buff[BUFSIZ];

D 6
	fclose(symfp);
	fclose(strfp);
	fclose(filesfp);
	fclose(linesfp);
E 6
I 6
	(void) fclose((FILE *) symfp);
	(void) fclose((FILE *) strfp);
	(void) fclose((FILE *) filesfp);
	(void) fclose((FILE *) linesfp);
E 6
I 2
	if (!opt('g')) {
		removenlfile();
		return;
	}
E 2
	symfd = open(symname, 0);
	strfd = open(strname, 0);
	filesfd = open(filesname, 0);
	linesfd = open(linesname, 0);
	if (symfd < 0 || strfd < 0 || filesfd < 0 || linesfd < 0) {
		fprintf(stderr, "sync error on /tmp/obj");
		pexit(ERRS);
	}
D 6
	lseek(ofil, 0L, 2);
	write(ofil, &nlhdr, sizeof(nlhdr));
E 6
I 6
	(void) lseek(ofil, 0L, 2);
	write(ofil, (char *) (&nlhdr), sizeof(nlhdr));
E 6
	n = read(strfd, buff, BUFSIZ - sizeof(nlhdr));
	write(ofil, buff, n);
	cat(strfd);
	cat(symfd);
	cat(filesfd);
	cat(linesfd);
	removenlfile();
}

cat(fd)
int fd;
{
	register int n;
	char buff[BUFSIZ];

	while ((n = read(fd, buff, BUFSIZ)) > 0) {
		write(ofil, buff, n);
	}
D 6
	close(fd);
E 6
I 6
	(void) close(fd);
E 6
}

removenlfile()
{
	unlink(symname);
	unlink(strname);
	unlink(filesname);
	unlink(linesname);
}

I 2
nlhdrsize()
{
	int r;

	if (!opt('g')) {
		r = 0;
	} else {
		r = nlsize + sizeof(nlhdr);
	}
	return r;
}

E 2
#define isblock(s)	(s->class == FUNC || s->class == PROC)
#define isbuiltin(s)	((s->nl_block&037) == 0 && isblock(s))
#define symno(p)	(p==NULL ? 0 : nloff(p))

struct nls {
	struct nl *nls_low;
	struct nl *nls_high;
};

struct nl nl[], *nlp, ntab[], *nlact;

I 6
/*VARARGS*/
E 6
savenl(to, rout)
struct nl *to;
{
	register struct nl *p;
	register OBJSYM *s;
	OBJSYM tmpsym;
	struct nls *nlsp;
D 6
	int v;
E 6

	if (to != NIL) {
D 6
		putblock(rout);
E 6
I 6
		putblock((char *) rout);
E 6
	} else {
		putblock("main program");
	}
D 6
	nlsp = nlact;
E 6
I 6
	nlsp = (struct nls *) nlact;
E 6
	s = &tmpsym;
	for (p = nlp; p != to;) {
		if (p == nlsp->nls_low) {
D 6
			if (nlsp == &ntab[0])
E 6
I 6
			if (nlsp == ((struct nls *) &ntab[0]))
E 6
				break;
			nlsp--;
			p = nlsp->nls_high;
		}
		p--;
		if (isbuiltin(p) || symno(p) == 0) {
			continue;
		}
		nlhdr.nsyms++;
I 2
		nlsize += sizeof(OBJSYM) + sizeof(int);
E 2
D 6
		putw(symno(p), symfp);
E 6
I 6
		(void) putw(symno(p), symfp);
E 6
		if (p->symbol != NULL) {
			s->strindex = nlhdr.stringsize;
			putstring(p->symbol);
		} else {
			s->strindex = 0;
		}
		s->oclass = p->class;
		s->oblkno = (p->nl_block&037);
		s->typno = symno(p->type);
		s->chno = symno(p->chain);
		s->osymvalue.orangev.lower = p->range[0];
		s->osymvalue.orangev.upper = p->range[1];
		if (isblock(p)) {
D 5
			s->osymvalue.ofuncv.codeloc = p->entloc;
E 5
I 5
			s->osymvalue.ofuncv.codeloc = p->value[NL_ENTLOC];
E 5
		} else if (p->class == RECORD || p->class == VARNT) {
			s->osymvalue.ovarnt.vtorecno = symno(p->ptr[2]);
			s->osymvalue.ovarnt.vtagno = symno(p->ptr[3]);
		}
D 6
		fwrite(s, sizeof(*s), 1, symfp);
E 6
I 6
		fwrite((char *) s, sizeof(*s), 1, symfp);
E 6
	}
}

/*
 * Dump a line number and the current object location counter.
 *
 * To save space the difference from the previous line number and offset
 * (one byte each) is dumped.
 */

LOCAL int oline = 0;
D 2
LOCAL int olc = BASEADDR;
E 2
I 2
LOCAL int olc = HEADER_BYTES;
E 2

lineno(line)
int line;
{
I 3
	OBJLINE info;

E 3
	if (line != oline) {
		nlhdr.nlines++;
I 2
D 3
		nlsize += 2;
E 2
		putc(line - oline, linesfp);
		putc(lc - olc, linesfp);
E 3
I 3
		nlsize += sizeof(OBJLINE);
		info.separate.lineincr = line - oline;
D 6
		info.separate.addrincr = lc - olc;
		putw(info.together, linesfp);
E 6
I 6
		info.separate.addrincr = ((unsigned short) (lc - olc));
		(void) putw((int) info.together, linesfp);
E 6
E 3
		oline = line;
D 6
		olc = lc;
E 6
I 6
		olc = (int) lc;
E 6
	}
}

/*
 * put out a file name entry, including:
 *
 *	the current line number for the new file
 *	the current location counter
 *	the string table address of the file name
 *	an index into the current line number information
 */

newfile(s, line)
char *s;
int line;
{
	FILETAB ft;

	nlhdr.nfiles++;
I 2
	nlsize += sizeof(FILETAB);
E 2
	ft.line = line;
	oline = line;
	if (lc == 0) {
		ft.addr = 0;
	} else {
D 2
		ft.addr = lc - BASEADDR;
E 2
I 2
D 6
		ft.addr = lc - HEADER_BYTES;
E 6
I 6
		ft.addr = ((LINENO) lc - HEADER_BYTES );
E 6
E 2
	}
	ft.filename = (char *) nlhdr.stringsize;
	putstring(s);
	ft.lineindex = nlhdr.nlines;
D 6
	fwrite(&ft, sizeof(ft), 1, filesfp);
E 6
I 6
	fwrite((char *) (&ft), sizeof(ft), 1, filesfp);
E 6
}

/*
 * put out a dummy symbol at the beginning of a block
 */

LOCAL putblock(s)
char *s;
{
D 6
	register int i;
E 6
	static OBJSYM zerosym;

	nlhdr.nsyms++;
I 2
	nlsize += sizeof(OBJSYM) + sizeof(int);
E 2
D 6
	putw(0, symfp);
E 6
I 6
	(void) putw(0, symfp);
E 6
	zerosym.strindex = nlhdr.stringsize;
	putstring(s);
D 6
	fwrite(&zerosym, sizeof(zerosym), 1, symfp);
E 6
I 6
	fwrite((char *) (&zerosym), sizeof(zerosym), 1, symfp);
E 6
}

/*
 * put out a string to the string table file
 */

LOCAL putstring(s)
char *s;
{
	register char *p;

D 2
	for (p = s; *p != '\0'; p++)
E 2
I 2
	for (p = s; *p != '\0'; p++) {
E 2
		putc(*p, strfp);
I 2
	}
E 2
	nlhdr.stringsize += (p - s + 1);
I 2
	nlsize += (p - s + 1);
E 2
	putc('\0', strfp);
}
I 4
#endif OBJ
E 4
E 1
