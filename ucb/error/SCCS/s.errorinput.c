h49485
s 00010/00005/00520
d D 5.3 88/06/29 18:50:52 bostic 15 14
c install approved copyright notice
e
s 00009/00003/00516
d D 5.2 88/06/06 21:51:32 bostic 14 13
c written by Robert Henry; add Berkeley specific header
e
s 00010/00001/00509
d D 5.1 85/05/31 11:41:09 dist 13 12
c Add copyright
e
s 00005/00001/00505
d D 1.12 84/12/18 10:05:44 rrh 12 11
c accept errors from both versions of decwrl powell modula2 compiler
e
s 00021/00000/00485
d D 1.11 84/12/11 16:07:14 rrh 11 10
c add decwrl modula2 (this quick&dirty: the ^ pointers mod2 generates
c to point to the point of the error aren't shown in the output of error)
e
s 00006/00000/00479
d D 1.10 84/09/25 09:21:17 ralph 10 9
c Recognize "Error No assembly" message from f77
e
s 00005/00004/00474
d D 1.9 84/05/08 21:34:06 edward 9 8
c fixed miscellaneous null pointer bugs
e
s 00027/00000/00451
d D 1.8 83/06/14 15:41:58 rrh 8 7
c add error category for troff; delimited just like pcc ccom, except
c uses ` and ' instead of "
e
s 00003/00002/00448
d D 1.7 83/02/09 15:32:05 sam 7 6
c from sun
e
s 00000/00005/00450
d D 1.6 82/05/04 12:33:56 rrh 6 5
c Preserves links by writing to /tmp and copying.  Removed #ifdef ERNIE
e
s 00003/00009/00452
d D 1.5 82/05/04 10:53:39 rrh 5 4
c Fixed categorization of assembler errors.
e
s 00011/00012/00450
d D 1.4 82/01/22 17:55:39 rrh 4 3
c Re proceduralization in errortouch for clarity.
c Added -T (terse option)
c Added typedefs, and changed textual form of structures
c changed argument to vi to begin searching from line 1, instead of line $
e
s 00001/00001/00461
d D 1.3 81/02/28 21:12:38 wnj 3 2
c restor id keywords
e
s 00040/00004/00422
d D 1.2 81/02/28 21:12:00 wnj 2 1
c added error parser for ritchie C compiler messages
e
s 00426/00000/00000
d D 1.1 80/10/16 09:46:33 root 1 0
c date and time created 80/10/16 09:46:33 by root
e
u
U
t
T
I 1
D 2
static	char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 3
static	char *sccsid = "@(#)errorinput.c	1.2 (Berkeley) 1/14/81";
E 3
I 3
D 13
static	char *sccsid = "%W% (Berkeley) %E%";
E 13
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
D 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
I 14
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 15
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
I 15
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 15
E 14
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14

E 13
E 3
E 2
#include <stdio.h>
#include <ctype.h>
#include "error.h"

int	wordc;		/* how long the current error message is */
char	**wordv;	/* the actual error message */

int	nerrors;
int	language;

Errorclass	onelong();
Errorclass	cpp();
D 2
Errorclass	ccom();
E 2
I 2
Errorclass	pccccom();	/* Portable C Compiler C Compiler */
Errorclass	richieccom();	/* Richie Compiler for 11 */
E 2
Errorclass	lint0();
Errorclass	lint1();
Errorclass	lint2();
Errorclass	lint3();
Errorclass	make();
Errorclass	f77();
Errorclass	pi();
Errorclass	ri();
I 8
Errorclass	troff();
I 11
Errorclass	mod2();
E 11
E 8
/*
 *	Eat all of the lines in the input file, attempting to categorize
 *	them by their various flavors
 */
static	char	inbuffer[BUFSIZ];

eaterrors(r_errorc, r_errorv)
	int	*r_errorc;
D 4
	struct	error_desc	***r_errorv;
E 4
I 4
	Eptr	**r_errorv;
E 4
{
	extern	boolean	piflag;
	Errorclass	errorclass = C_SYNC;

    for (;;){
	if (fgets(inbuffer, BUFSIZ, errorfile) == NULL)
		break;
	wordvbuild(inbuffer, &wordc, &wordv);
	/*
	 *	for convience, convert wordv to be 1 based, instead
	 *	of 0 based.
	 */
	wordv -= 1;
D 9
	if ( 0
D 6
#ifndef ERNIE
	   || (piflag && ( (errorclass = pi() ) != C_UNKNOWN))
#endif
E 6
	   || (( errorclass = onelong() ) != C_UNKNOWN)
E 9
I 9
	if ( wordc > 0 &&
	   ((( errorclass = onelong() ) != C_UNKNOWN)
E 9
	   || (( errorclass = cpp() ) != C_UNKNOWN)
D 2
	   || (( errorclass = ccom() ) != C_UNKNOWN)
E 2
I 2
	   || (( errorclass = pccccom() ) != C_UNKNOWN)
	   || (( errorclass = richieccom() ) != C_UNKNOWN)
E 2
	   || (( errorclass = lint0() ) != C_UNKNOWN)
	   || (( errorclass = lint1() ) != C_UNKNOWN)
	   || (( errorclass = lint2() ) != C_UNKNOWN)
	   || (( errorclass = lint3() ) != C_UNKNOWN)
	   || (( errorclass = make() ) != C_UNKNOWN)
	   || (( errorclass = f77() ) != C_UNKNOWN)
D 6
#ifdef ERNIE
E 6
	   || ((errorclass = pi() ) != C_UNKNOWN)
	   || (( errorclass = ri() )!= C_UNKNOWN)
I 11
	   || (( errorclass = mod2() )!= C_UNKNOWN)
E 11
I 8
D 9
	   || (( errorclass = troff() )!= C_UNKNOWN)
E 9
I 9
	   || (( errorclass = troff() )!= C_UNKNOWN))
E 9
E 8
D 6
#endif
E 6
	) ;
	else
		errorclass = catchall();
	if (wordc)
		erroradd(wordc, wordv+1, errorclass, C_UNKNOWN);	
    }
#ifdef FULLDEBUG
    printf("%d errorentrys\n", nerrors);
#endif
    arrayify(r_errorc, r_errorv, er_head);
}

/*
 *	create a new error entry, given a zero based array and count
 */
erroradd(errorlength, errorv, errorclass, errorsubclass)
	int		errorlength;
	char		**errorv;
	Errorclass	errorclass;
	Errorclass	errorsubclass;
{
D 4
	register	struct	error_desc	*newerror;
	register	char	*cp;
E 4
I 4
	reg	Eptr	newerror;
	reg	char	*cp;
E 4

	if (errorclass == C_TRUE){
		/* check canonicalization of the second argument*/
		for(cp = errorv[1]; *cp && isdigit(*cp); cp++)
			continue;
		errorclass = (*cp == '\0') ? C_TRUE : C_NONSPEC;
#ifdef FULLDEBUG
		if (errorclass != C_TRUE)
			printf("The 2nd word, \"%s\" is not a number.\n",
				errorv[1]);
#endif
	}
	if (errorlength > 0){
D 4
		newerror = (struct error_desc *)Calloc(1, sizeof(struct error_desc));
E 4
I 4
		newerror = (Eptr)Calloc(1, sizeof(Edesc));
E 4
		newerror->error_language = language; /* language is global */
		newerror->error_text = errorv;
		newerror->error_lgtext = errorlength;
		if (errorclass == C_TRUE)
			newerror->error_line = atoi(errorv[1]);
		newerror->error_e_class = errorclass;
		newerror->error_s_class = errorsubclass;
		switch(newerror->error_e_class = discardit(newerror)){
			case C_SYNC:		nsyncerrors++; break;
			case C_DISCARD: 	ndiscard++; break;
			case C_NULLED:		nnulled++; break;
			case C_NONSPEC:		nnonspec++; break;
			case C_THISFILE: 	nthisfile++; break;
			case C_TRUE:		ntrue++; break;
			case C_UNKNOWN:		nunknown++; break;
			case C_IGNORE:		nignore++; break;
		}
		newerror->error_next = er_head;
		er_head = newerror;
		newerror->error_no = nerrors++;
	}	/* length > 0 */
}

Errorclass onelong()
{
	char	**nwordv;
	if ( (wordc == 1) && (language != INLD) ){
		/*
		 *	We have either:
		 *	a)	file name from cc
		 *	b)	Assembler telling world that it is complaining
		 *	c)	Noise from make ("Stop.")
		 *	c)	Random noise
		 */
		wordc = 0;
D 9
		if (strcmp(wordv[2], "Stop.") == 0){
E 9
I 9
		if (strcmp(wordv[1], "Stop.") == 0){
E 9
			language = INMAKE; return(C_SYNC);
		}
		if (strcmp(wordv[1], "Assembler:") == 0){
			/* assembler always alerts us to what happened*/
			language = INAS; return(C_SYNC);
		} else 
		if (strcmp(wordv[1], "Undefined:") == 0){
			/* loader complains about unknown symbols*/
			language = INLD; return(C_SYNC);
		}
		if (lastchar(wordv[1]) == ':'){
			/* cc tells us what file we are in */
			currentfilename = wordv[1];
D 4
			substitute(currentfilename, ':', '\0');
E 4
I 4
			(void)substitute(currentfilename, ':', '\0');
E 4
			language = INCC; return(C_SYNC);
		}
	} else
	if ( (wordc == 1) && (language == INLD) ){
		nwordv = (char **)Calloc(4, sizeof(char *));
		nwordv[0] = "ld:";
		nwordv[1] = wordv[1];
		nwordv[2] = "is";
		nwordv[3] = "undefined.";
		wordc = 4;
		wordv = nwordv - 1;
		return(C_NONSPEC);
	} else
	if (wordc == 1){
		return(C_SYNC);
	}
	return(C_UNKNOWN);
}	/* end of one long */

Errorclass	cpp()
{
	/* 
	 *	Now attempt a cpp error message match
	 *	Examples:
	 *		./morse.h: 23: undefined control
	 *		morsesend.c: 229: MAGNIBBL: argument mismatch
	 *		morsesend.c: 237: MAGNIBBL: argument mismatch
	 *		test1.c: 6: undefined control
	 */
	if (   (language != INLD)		/* loader errors have almost same fmt*/
	    && (lastchar(wordv[1]) == ':')
	    && (isdigit(firstchar(wordv[2])))
	    && (lastchar(wordv[2]) == ':') ){
		language = INCPP;
		clob_last(wordv[1], '\0');
		clob_last(wordv[2], '\0');
		return(C_TRUE);
	}
	return(C_UNKNOWN);
}	/*end of cpp*/

D 2
Errorclass ccom()
E 2
I 2
Errorclass pccccom()
E 2
{
	/*
	 *	Now attempt a ccom error message match:
	 *	Examples:
	 *	  "morsesend.c", line 237: operands of & have incompatible types
	 *	  "test.c", line 7: warning: old-fashioned initialization: use =
	 *	  "subdir.d/foo2.h", line 1: illegal initialization
	 */
	if (   (firstchar(wordv[1]) == '"')
	    && (lastchar(wordv[1]) == ',')
	    && (next_lastchar(wordv[1]) == '"')
	    && (strcmp(wordv[2],"line") == 0)
	    && (isdigit(firstchar(wordv[3])))
	    && (lastchar(wordv[3]) == ':') ){
		clob_last(wordv[1], '\0');	/* drop last , */
		clob_last(wordv[1], '\0');	/* drop last " */
		wordv[1]++;			/* drop first " */
		clob_last(wordv[3], '\0');	/* drop : on line number */
		wordv[2] = wordv[1];	/* overwrite "line" */
		wordv++;		/*compensate*/
I 9
		wordc--;
E 9
D 5
		if (language == INAS){
			if (strcmp(currentfilename, "???") != 0)
				wordv[1] = currentfilename;
			return(C_NULLED);
		} else {
			currentfilename = wordv[1];
			language = INCC;
			return(C_TRUE);
		}
E 5
I 5
		currentfilename = wordv[1];
		language = INCC;
		return(C_TRUE);
E 5
	}
	return(C_UNKNOWN);
}	/* end of ccom */
I 2
/*
 *	Do the error message from the Richie C Compiler for the PDP11,
 *	which has this source:
 *
 *	if (filename[0])
 *		fprintf(stderr, "%s:", filename);
 *	fprintf(stderr, "%d: ", line);
 *
 */
Errorclass richieccom()
{
D 4
	register	char	*cp;
	register	char	**nwordv;
			char	*file;
E 4
I 4
	reg	char	*cp;
	reg	char	**nwordv;
		char	*file;

E 4
	if (lastchar(wordv[1]) == ':'){
		cp = wordv[1] + strlen(wordv[1]) - 1;
		while (isdigit(*--cp))
			continue;
		if (*cp == ':'){
			clob_last(wordv[1], '\0');	/* last : */
			*cp = '\0';			/* first : */
			file = wordv[1];
			nwordv = wordvsplice(1, wordc, wordv+1);
			nwordv[0] = file;
			nwordv[1] = cp + 1;
			wordc += 1;
			wordv = nwordv - 1;
			language = INCC;
			currentfilename = wordv[1];
			return(C_TRUE);
		}
	}
	return(C_UNKNOWN);
}
E 2

Errorclass lint0()
{
D 4
	register	char	*cp;
	register	char	**nwordv;
			char	*line, *file;
E 4
I 4
	reg	char	**nwordv;
		char	*line, *file;
E 4
	/*
	 *	Attempt a match for the new lint style normal compiler
	 *	error messages, of the form
	 *	
	 *	printf("%s(%d): %s\n", filename, linenumber, message);
	 */
	if (wordc >= 2){
		if (   (lastchar(wordv[1]) == ':')
		    && (next_lastchar(wordv[1]) == ')')
		) {
			clob_last(wordv[1], '\0'); /* colon */
			if (persperdexplode(wordv[1], &line, &file)){
				nwordv = wordvsplice(1, wordc, wordv+1);
				nwordv[0] = file;	/* file name */
				nwordv[1] = line;	/* line number */
				wordc += 1;
				wordv = nwordv - 1;
				language = INLINT;
				return(C_TRUE);
			}
			wordv[1][strlen(wordv[1])] = ':';
		}
	}
	return (C_UNKNOWN);
}

Errorclass lint1()
{
	char	*line1, *line2;
	char	*file1, *file2;
	char	**nwordv1, **nwordv2;

	/*
	 *	Now, attempt a match for the various errors that lint
	 *	can complain about.
	 *
	 *	Look first for type 1 lint errors
	 */
D 7
	if (strcmp(wordv[wordc-1], "::") == 0){
E 7
I 7
	if (wordc > 1 && strcmp(wordv[wordc-1], "::") == 0){
E 7
	 /*
  	  * %.7s, arg. %d used inconsistently %s(%d) :: %s(%d)
  	  * %.7s value used inconsistently %s(%d) :: %s(%d)
  	  * %.7s multiply declared %s(%d) :: %s(%d)
  	  * %.7s value declared inconsistently %s(%d) :: %s(%d)
  	  * %.7s function value type must be declared before use %s(%d) :: %s(%d)
	  */
		language = INLINT;
D 7
		if (    (persperdexplode(wordv[wordc], &line2, &file2))
E 7
I 7
		if (wordc > 2
		     && (persperdexplode(wordv[wordc], &line2, &file2))
E 7
		     && (persperdexplode(wordv[wordc-2], &line1, &file1)) ){
			nwordv1 = wordvsplice(2, wordc, wordv+1);
			nwordv2 = wordvsplice(2, wordc, wordv+1);
			nwordv1[0] = file1; nwordv1[1] = line1;
			erroradd(wordc+2, nwordv1, C_TRUE, C_DUPL); /* takes 0 based*/
			nwordv2[0] = file2; nwordv2[1] = line2;
			wordc = wordc + 2;
			wordv = nwordv2 - 1;	/* 1 based */
			return(C_TRUE);
		}
	}
	return(C_UNKNOWN);
} /* end of lint 1*/

Errorclass lint2()
{
	char	*file;
	char	*line;
	char	**nwordv;
	/*
	 *	Look for type 2 lint errors
	 *
	 *	%.7s used( %s(%d) ), but not defined
	 *	%.7s defined( %s(%d) ), but never used
	 *	%.7s declared( %s(%d) ), but never used or defined
	 *
	 *	bufp defined( "./metric.h"(10) ), but never used
	 */
	if (   (lastchar(wordv[2]) == '(' /* ')' */ )	
	    && (strcmp(wordv[4], "),") == 0) ){
		language = INLINT;
		if (persperdexplode(wordv[3], &line, &file)){
			nwordv = wordvsplice(2, wordc, wordv+1);
			nwordv[0] = file; nwordv[1] = line;
			wordc = wordc + 2;
			wordv = nwordv - 1;	/* 1 based */
			return(C_TRUE);
		}
	}
	return(C_UNKNOWN);
} /* end of lint 2*/

char	*Lint31[4] = {"returns", "value", "which", "is"};
char	*Lint32[6] = {"value", "is", "used,", "but", "none", "returned"};
Errorclass lint3()
{
	if (   (wordvcmp(wordv+2, 4, Lint31) == 0)
	    || (wordvcmp(wordv+2, 6, Lint32) == 0) ){
		language = INLINT;
		return(C_NONSPEC);
	}
	return(C_UNKNOWN);
}

/*
 *	Special word vectors for use by F77 recognition
 */
char	*F77_fatal[3] = {"Compiler", "error", "line"};
char	*F77_error[3] = {"Error", "on", "line"};
char	*F77_warning[3] = {"Warning", "on", "line"};
I 10
char    *F77_no_ass[3] = {"Error.","No","assembly."};
E 10
f77()
{
	char	**nwordv;
	/*
	 *	look for f77 errors:
	 *	Error messages from /usr/src/cmd/f77/error.c, with
	 *	these printf formats:
	 *
	 *		Compiler error line %d of %s: %s
	 *		Error on line %d of %s: %s
	 *		Warning on line %d of %s: %s
I 10
	 *		Error.  No assembly.
E 10
	 */
I 10
	if (wordc == 3 && wordvcmp(wordv+1, 3, F77_no_ass) == 0) {
		wordc = 0;
		return(C_SYNC);
	}
E 10
	if (wordc < 6)
		return(C_UNKNOWN);
	if (	(lastchar(wordv[6]) == ':')
	    &&(
	       (wordvcmp(wordv+1, 3, F77_fatal) == 0)
	    || (wordvcmp(wordv+1, 3, F77_error) == 0)
	    || (wordvcmp(wordv+1, 3, F77_warning) == 0) )
	){
		language = INF77;
		nwordv = wordvsplice(2, wordc, wordv+1);
		nwordv[0] = wordv[6];
		clob_last(nwordv[0],'\0');
		nwordv[1] = wordv[4];
		wordc += 2;
		wordv = nwordv - 1;	/* 1 based */
		return(C_TRUE);
	}
	return(C_UNKNOWN);
} /* end of f77 */

char	*Make_Croak[3] = {"***", "Error", "code"};
char	*Make_NotRemade[5] = {"not", "remade", "because", "of", "errors"};
Errorclass make()
{
	if (wordvcmp(wordv+1, 3, Make_Croak) == 0){
		language = INMAKE;
		return(C_SYNC);
	}
	if  (wordvcmp(wordv+2, 5, Make_NotRemade) == 0){
		language = INMAKE;
		return(C_SYNC);
	}
	return(C_UNKNOWN);
}
Errorclass ri()
{
D 4
	char	**nwordv;
E 4
/*
 *	Match an error message produced by ri; here is the
 *	procedure yanked from the distributed version of ri
 *	April 24, 1980.
 *	
 *	serror(str, x1, x2, x3)
 *		char str[];
 *		char *x1, *x2, *x3;
 *	{
 *		extern int yylineno;
 *		
 *		putc('"', stdout);
 *		fputs(srcfile, stdout);
 *		putc('"', stdout);
 *		fprintf(stdout, " %d: ", yylineno);
 *		fprintf(stdout, str, x1, x2, x3);
 *		fprintf(stdout, "\n");
 *		synerrs++;
 *	}
 */
	if (  (firstchar(wordv[1]) == '"')
	    &&(lastchar(wordv[1]) == '"')
	    &&(lastchar(wordv[2]) == ':')
	    &&(isdigit(firstchar(wordv[2]))) ){
		clob_last(wordv[1], '\0');	/* drop the last " */
		wordv[1]++;	/* skip over the first " */
		clob_last(wordv[2], '\0');
		language = INRI;
		return(C_TRUE);
	}
	return(C_UNKNOWN);
}

Errorclass catchall()
{
	/*
	 *	Catches random things.
	 */
	language = INUNKNOWN;
	return(C_NONSPEC);
} /* end of catch all*/
I 8

Errorclass troff()
{
	/*
	 *	troff source error message, from eqn, bib, tbl...
	 *	Just like pcc ccom, except uses `'
	 */
	if (   (firstchar(wordv[1]) == '`')
	    && (lastchar(wordv[1]) == ',')
	    && (next_lastchar(wordv[1]) == '\'')
	    && (strcmp(wordv[2],"line") == 0)
	    && (isdigit(firstchar(wordv[3])))
	    && (lastchar(wordv[3]) == ':') ){
		clob_last(wordv[1], '\0');	/* drop last , */
		clob_last(wordv[1], '\0');	/* drop last " */
		wordv[1]++;			/* drop first " */
		clob_last(wordv[3], '\0');	/* drop : on line number */
		wordv[2] = wordv[1];	/* overwrite "line" */
		wordv++;		/*compensate*/
		currentfilename = wordv[1];
		language = INTROFF;
I 11
		return(C_TRUE);
	}
	return(C_UNKNOWN);
}
Errorclass mod2()
{
D 12
	if (   (strcmp(wordv[1], "!!!") == 0)
E 12
I 12
	/*
	 *	for decwrl modula2 compiler (powell)
	 */
	if (   (  (strcmp(wordv[1], "!!!") == 0)	/* early version */
	        ||(strcmp(wordv[1], "File") == 0))	/* later version */
E 12
	    && (lastchar(wordv[2]) == ',')	/* file name */
	    && (strcmp(wordv[3], "line") == 0)
	    && (isdigit(firstchar(wordv[4])))	/* line number */
	    && (lastchar(wordv[4]) == ':')	/* line number */
	){
		clob_last(wordv[2], '\0');	/* drop last , on file name */
		clob_last(wordv[4], '\0');	/* drop last : on line number */
		wordv[3] = wordv[2];		/* file name on top of "line" */
		wordv += 2;
		wordc -= 2;
		currentfilename = wordv[1];
		language = INMOD2;
E 11
		return(C_TRUE);
	}
	return(C_UNKNOWN);
}
E 8
E 1
