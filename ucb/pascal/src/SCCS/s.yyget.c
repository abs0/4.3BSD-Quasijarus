h20073
s 00007/00003/00359
d D 5.1 85/06/05 15:07:29 dist 9 8
c Add copyright
e
s 00000/00000/00362
d D 2.1 84/02/08 20:45:13 aoki 8 7
c synchronize to version 2
e
s 00000/00000/00362
d D 1.6 84/02/04 20:35:53 mckusick 7 5
i 6
c merge lint by thien
e
s 00011/00005/00351
d D 1.4.1.1 84/02/04 20:34:56 mckusick 6 4
c lint (by thien)
e
s 00002/00002/00354
d D 1.5 83/07/26 09:46:48 peter 5 4
c using checksum on include files and flag day indicators on source files.
e
s 00002/00002/00354
d D 1.4 83/05/11 21:54:08 peter 4 3
c bug fix in declaration and random cleanup of extra parens.
e
s 00006/00000/00350
d D 1.3 82/02/11 23:44:08 linton 3 2
c added a call to "newfile" in uninclude
e
s 00009/00000/00341
d D 1.2 82/02/02 12:56:42 linton 2 1
c merge pdx into the Pascal system
e
s 00341/00000/00000
d D 1.1 80/08/27 19:57:06 peter 1 0
c date and time created 80/08/27 19:57:06 by peter
e
u
U
f b 
t
T
I 1
D 9
/* Copyright (c) 1979 Regents of the University of California */
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
static	char sccsid[] = "%Z%%M% %I% %G%";
I 6
#endif
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 6

#include "whoami.h"
#include "0.h"
I 6
#include "tree_ty.h"	/* must be included for yy.h */
E 6
#include "yy.h"

#ifdef PXP
int	yytokcnt;
#endif

/*
 * Readch returns the next
 * character from the current
 * input line or -1 on end-of-file.
 * It also maintains yycol for use in
 * printing error messages.
 */
readch()
{
D 6
	register i, c;
E 6
I 6
	register c;
E 6

	if (*bufp == '\n' && bufp >= charbuf) {
#ifdef PXP
		yytokcnt = 0;
#endif
		if (getline() < 0)
			return (-1);
	}
	c = *++bufp;
	if (c == '\t')
		yycol = ((yycol + 8) & ~7);
	else
		yycol++;
	return (c);
}

/*
 * Definitions of the structures used for the
 * include facility.  The variable "ibp" points
 * to the getc buffer of the current input file.
 * There are "inclev + 1" current include files,
 * and information in saved in the incs stack
 * whenever a new level of include nesting occurs.
 *
 * Ibp in the incs structure saves the pointer
 * to the previous levels input buffer;
 * filename saves the previous file name;
 * Printed saves whether the previous file name
 * had been printed before this nesting occurred;
 * and yyline is the line we were on on the previous file.
 */

#define	MAXINC	10

struct inc {
	FILE	*ibp;
	char	*filename;
	int	Printed;
	int	yyline;
	int	yyLinpt;
} incs[MAXINC];

D 4
extern	char *printed;
E 4
I 4
extern	char printed;
E 4

int	inclev	= -1;

#ifdef PXP
/*
 * These initializations survive only if
 * pxp is asked to pretty print one file.
 * Otherwise they are destroyed by the initial
 * call to getline.
 */
char	charbuf[CBSIZE]	= " program x(output);\n";
int	yycol = 8;
char	*bufp = charbuf;

#endif
/*
 * YyLinpt is the seek pointer to the beginning of the
 * next line in the file.
 */
int	yyLinpt;

/*
 * Getline places the next line
 * from the input stream in the
 * line buffer, returning -1 at YEOF.
 */
getline()
{
	register char *cp;
	register CHAR c;
#ifdef PXP
	static char ateof;
#endif
	register FILE *ib;
	int i;

	if (opt('l') && yyprtd == 0)
		yyoutline();
	yyprtd = 0;
top:
	yylinpt = yyLinpt;
	yyline++;
	yyseqid++;
	cp = charbuf;
	ib = ibp;
	i = sizeof charbuf - 1;
	for (;;) {
		c = getc(ib);
		if (c == EOF) {
			if (uninclud())
				goto top;
#ifdef PXP
			if (ateof == 0 && bracket) {
D 6
				strcpy(charbuf, "begin end.\n");
E 6
I 6
				(void) pstrcpy(charbuf, "begin end.\n");
E 6
				ateof = 1;
				goto out;
			}
#endif
			bufp = "\n";
			yyline--;
			yyseqid--;
			yyprtd = 1;
			return (-1);
		}
		*cp++ = c;
		if (c == '\n')
			break;
		if (--i == 0) {
			line = yyline;
			error("Input line too long - QUIT");
			pexit(DIED);
		}
	}
	*cp = 0;
	yyLinpt = yylinpt + cp - charbuf;
	if (includ())
		goto top;
#ifdef PXP
	if (cp == &charbuf[1])
		commnl();
	else if (cp == &charbuf[2])
		switch (charbuf[0]) {
			case ' ':
				commnlbl();
				break;
			case '\f':
				commform();
		}
#endif
	if (opt('u'))
		setuflg();
I 6
#ifdef PXP
E 6
out:
I 6
#endif
E 6
	bufp = charbuf - 1;
	yycol = 8;
	return (1);
}

/*
 * Check an input line to see if it is a "#include" pseudo-statement.
 * We allow arbitrary blanks in the line and the file name
 * may be delimited by either 's or "s.  A single semicolon
 * may be placed after the name, but nothing else is allowed
 */
includ()
{
	register char *cp, *dp;
	char ch;
	register struct inc *ip;

	cp = charbuf;
	if (*cp++ != '#')
		return (0);
	cp = skipbl(cp);
	for (dp = "include"; *dp; dp++)
		if (*dp != *cp++)
			return (0);
	line = yyline;
	cp = skipbl(cp);
	ch = *cp++;
	if (ch != '\'' && ch != '"') {
		/*
		 * This should be a yerror flagging the place
		 * but its not worth figuring out the column.
		 */
		line = yyline;
		error("Include syntax error - expected ' or \" not found - QUIT");
		pexit(DIED);
	}
	for (dp = cp; *dp != ch; dp++)
		if (*dp == 0) {
			line = yyline;
D 6
			error("Missing closing %c for include file name - QUIT", ch);
E 6
I 6
			error("Missing closing %c for include file name - QUIT", (char *) ch);
E 6
			pexit(DIED);
		}
	*dp++ = 0;
/*
 *	if (*dp == ';')
 *		dp++;
 *	dp = skipbl(dp);
 *	if (*dp != '\n') {
 *		line = yyline;
 *		error("Garbage after filename in include");
 *		pexit(DIED);
 *	}
 */
D 4
	if ((!dotted(cp, 'i')) && (!dotted(cp, 'h'))) {
E 4
I 4
	if (!dotted(cp, 'i') && !dotted(cp, 'h')) {
E 4
		line = yyline;
		error("Include filename must end in .i or .h");
	}
#ifdef PXP
	commincl(cp, ch);
	if (noinclude)
		return (1);
#endif
	inclev++;
	if (inclev > MAXINC) {
		line = yyline;
		error("Absurdly deep include nesting - QUIT");
		pexit(DIED);
	}
	ip = &incs[inclev];
	ip->filename = filename;
	filename = savestr(cp);
I 2

#ifdef OBJ
E 2
/*
I 2
 * For the debugger pdx, we need to note that we've changed files.
 */
	newfile(filename, 1);
#endif

/*
E 2
 *	left over from before stdio
 *
 *	cp = malloc(518);
 *	if (cp == -1) {
 *		error("Ran out of memory (include)");
 *		pexit(DIED);
 *	}
 *
 */
	ip->ibp = ibp;
	if ( ( ibp = fopen(filename, "r" ) ) == NULL ) {
		perror(filename);
		pexit(DIED);
	}
	if (inpflist(filename)) {
#ifdef PI
		opush('l');
#endif
#ifdef PXP
		opush('z');
#endif
	}
	ip->Printed = printed;
	printed = 0;
	ip->yyline = yyline;
	yyline = 0;
	ip->yyLinpt = yyLinpt;
	yyLinpt = 0;
/*
 *	left over from before stdio
 *
 *	ip->ibp = ibp;
 *	ibp = cp;
 *
 */
#	ifdef PC
D 5
	    stabinclude( filename );
E 5
I 5
	    stabinclude( filename , TRUE );
E 5
#	endif PC
	return (1);
}

I 6
char *
E 6
skipbl(ocp)
	char *ocp;
{
	register char *cp;

	cp = ocp;
	while (*cp == ' ' || *cp == '\t')
		cp++;
	return (cp);
}


/*
 * At the end of an include,
 * close the file, free the input buffer,
 * and restore the environment before
 * the "push", including the value of
 * the z option for pxp and the l option for pi.
 */
uninclud()
{
	register struct inc *ip;

	if (inclev < 0)
		return (0);
/*
 *	left over from before stdio: becomes fclose ( ibp )
 *
D 6
 *	close(ibp[0]);
E 6
I 6
 *	(void) close(ibp[0]);
E 6
 *	free(ibp);
 *
 */
D 6
	fclose ( ibp );
E 6
I 6
	(void) fclose ( ibp );
E 6
	ip = &incs[inclev];
	ibp = ip->ibp;
	yyline = ip->yyline;
	if (inpflist(filename)) {
#ifdef PI
		opop('l');
#endif
#ifdef PXP
		opop('z');
#endif
	}
	filename = ip->filename;
I 2

E 2
	yyLinpt = ip->yyLinpt;
	/*
	 * If we printed out the nested name,
	 * then we should print all covered names again.
	 * If we didn't print out the nested name
	 * we print the uncovered name only if it
	 * has not been printed before (unstack).
	 */
	if (printed) {
		printed = 0;
		while (ip >= incs) {
			ip->Printed = 0;
			ip--;
		}
	} else
		printed = ip->Printed;
I 3
#	ifdef OBJ
	/*
	 * For the debugger pdx, we need to note that we've changed files.
	 */
	newfile(filename, yyline);
#endif
E 3
#	ifdef PC
	    if ( inclev == 0 ) {
		stabsource( filename );
	    } else {
D 5
		stabinclude( filename );
E 5
I 5
		stabinclude( filename , FALSE );
E 5
	    }
#	endif PC
	inclev--;
	return (1);
}
E 1
