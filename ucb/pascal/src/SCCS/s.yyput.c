h42593
s 00007/00003/00277
d D 5.1 85/06/05 15:14:58 dist 6 5
c Add copyright
e
s 00000/00000/00280
d D 2.1 84/02/08 20:44:46 aoki 5 4
c synchronize to version 2
e
s 00000/00000/00280
d D 1.4 83/09/19 07:02:24 thien 4 3
c Restoring to unlinted version
e
s 00007/00003/00273
d D 1.3 83/08/19 05:05:01 thien 3 2
c The changes were made to allow successful linting
e
s 00003/00003/00273
d D 1.2 81/03/08 19:30:45 mckusic 2 1
c merge in onyx changes
e
s 00276/00000/00000
d D 1.1 80/08/27 19:57:28 peter 1 0
c date and time created 80/08/27 19:57:28 by peter
e
u
U
t
T
I 1
D 6
/* Copyright (c) 1979 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6

I 3
#ifndef lint
E 3
D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
D 6
static char sccsid[] = "%Z%%M% %I% %G%";
I 3
#endif
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
E 3
E 2

#include "whoami.h"
#include "0.h"
#include "tree.h"
I 3
#include "tree_ty.h"	/* must be included for yy.h */
E 3
#include "yy.h"

/*
 * Structure describing queued listing lines during the forward move
 * of error recovery.  These lines will be stroed by yyoutline during
 * the forward move and flushed by yyoutfl or yyflush when an
 * error occurs or a program termination.
 */
struct	B {
	int	Bmagic;
	int	Bline;
	int	Bseekp;
	char	*Bfile;
	int	Bseqid;
	struct	B *Bnext;
} *bottled;

/*
 * Filename gives the current input file, lastname is
 * the last filename we printed, and lastid is the seqid of the last line
 * we printed, to help us avoid printing
 * multiple copies of lines.
 */
extern	char *filename;
char	*lastname;
int	lastid;

char	hadsome;
char	holdbl;

/*
 * Print the current line in the input line
 * buffer or, in a forward move of the recovery, queue it for printing.
 */
yyoutline()
{
	register struct B *bp;

	if (Recovery) {
D 3
		bp = tree(6, T_BOTTLE, yyline, yylinpt, filename, yyseqid);
E 3
I 3
		bp = (struct B *) tree(6, T_BOTTLE, yyline, yylinpt, filename,
				yyseqid);
E 3
		if (bottled != NIL)
			bp->Bnext = bottled->Bnext, bottled->Bnext = bp;
		else
			bp->Bnext = bp;
		bottled = bp;
		return;
	}
	yyoutfl(yyseqid);
	if (yyseqid != lastid)
		yyprline(charbuf, yyline, filename, yyseqid);
}

/*
 * Flush all the bottled output.
 */
yyflush()
{

	yyoutfl(32767);
}

/*
 * Flush the listing to the sequence id toseqid
 */
yyoutfl(toseqid)
	int toseqid;
{
	register struct B *bp;

	bp = bottled;
	if (bp == NIL)
		return;
	bp = bp->Bnext;
	while (bp->Bseqid <= toseqid) {
		yygetline(bp->Bfile, bp->Bseekp, bp->Bline, bp->Bseqid);
		if (bp->Bnext == bp) {
			bottled = NIL;
			break;
		}
		bp = bp->Bnext;
		bottled->Bnext = bp;
	}
}

FILE	*yygetunit = NULL;
char	*yygetfile;

/*
 * Yysync guarantees that the line associated
 * with the current token was the last line
 * printed for a syntactic error message.
 */
yysync()
{

	yyoutfl(yyeseqid);
	if (lastid != yyeseqid)
		yygetline(yyefile, yyseekp, yyeline, yyeseqid);
}

yySsync()
{

	yyoutfl(OY.Yyeseqid);
}

/*
 * Yygetline gets a line from a file after we have
 * lost it.  The pointer efile gives the name of the file,
 * seekp its offset in the file, and eline its line number.
 * If this routine has been called before the last file
 * it worked on will be open in yygetunit, with the files
 * name being given in yygetfile.  Note that this unit must
 * be opened independently of the unit in use for normal i/o
 * to this file; if it were a dup seeks would seek both files.
 */
yygetline(efile, seekp, eline, eseqid)
	char *efile;
	int seekp, eline, eseqid;
{
	register int cnt;
	register char *bp;
	char buf[CBSIZE + 1];

	if (lastid == eseqid)
		return;
	if (eseqid == yyseqid) {
		bp = charbuf;
		yyprtd++;
	} else {
		bp = buf;
		if (efile != yygetfile) {
			if ( yygetunit != NULL )
D 3
			    fclose( yygetunit );
E 3
I 3
			    (void) fclose( yygetunit );
E 3
			yygetfile = efile;
			yygetunit = fopen( yygetfile , "r" );
			if (yygetunit < 0)
oops:
				perror(yygetfile), pexit(DIED);
		} 
		if ( fseek( yygetunit , (long) seekp , 0 ) < 0)
			goto oops;
		cnt = fread( bp , sizeof( * bp ) , CBSIZE , yygetunit );
		if (cnt < 0)
			goto oops;
		bp[cnt] = 0;
	}
	yyprline(bp, eline, efile, eseqid);
}

yyretrieve()
{

	yygetline(OY.Yyefile, OY.Yyseekp, OY.Yyeline, OY.Yyeseqid);
}

/*
 * Print the line in the character buffer which has
 * line number line.  The buffer may be terminated by a new
 * line character or a null character.  We process
 * form feed directives, lines with only a form feed character, and
 * suppress numbering lines which are empty here.
 */
yyprline(buf, line, file, id)
	register char *buf;
	int line;
	char *file;
	int id;
{

	lastid = id;
	if (buf[0] == '\f' && buf[1] == '\n') {
		printf("\f\n");
		hadsome = 0;
		holdbl = 0;
		return;
	}
	if (holdbl) {
		pchr('\n');
		holdbl = 0;
	}
	if (buf[0] == '\n')
		holdbl = 1;
	else {
		yysetfile(file);
		yyprintf(buf, line);
	}
	hadsome = 1;
}

yyprintf(cp, line)
	register char *cp;
	int line;
{

	printf("%6d  ", line);
	while (*cp != 0 && *cp != '\n')
		pchr(graphic(*cp++));
	pchr('\n');
}

graphic(ch)
	register CHAR ch;
{

	switch (ch) {
		default:
			if (ch >= ' ')
				return (ch);
		case 0177:
			return ('?');
		case '\n':
		case '\t':
			return (ch);
	}
}

extern	int nopflg;

D 2
char	printed 1;
E 2
I 2
char	printed = 1;
E 2
/*
 * Set the current file name to be file,
 * printing the name, or a header on a new
 * page if required.
 * there is another yysetfile in error.c
 * this one is for PI and PXP that one is for PI1
 */
yysetfile(file)
	register char *file;
{

#ifdef PXP
	if (nopflg == 1)
		return;
#endif

	if (lastname == file)
		return;
	if (file == filename && opt('n') && (printed & 02) == 0) {
D 2
		printed =| 02;
E 2
I 2
		printed |= 02;
E 2
		header();
	} else
		yyputfn(file);
	lastname = file;
}

/*
 * Put out an include file name
 * if an error occurs but the name has
 * not been printed (or if another name
 * has been printed since it has).
 */
yyputfn(cp)
	register char *cp;
{
	extern int outcol;

	if (cp == lastname && printed)
		return;
	lastname = cp;
	printed = 1;
#ifdef PXP
	if (outcol)
		pchr('\n');
#endif
	gettime( cp );
D 3
	printf("%s  %s:\n" , myctime( &tvec ) , cp );
E 3
I 3
	printf("%s  %s:\n" , myctime( (int *) (&tvec) ) , cp );
E 3
	hadsome = 1;
}
E 1
