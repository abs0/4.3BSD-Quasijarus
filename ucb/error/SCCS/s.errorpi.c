h53616
s 00010/00005/00377
d D 5.3 88/06/29 18:50:56 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00373
d D 5.2 88/06/06 21:51:35 bostic 6 5
c written by Robert Henry; add Berkeley specific header
e
s 00010/00001/00366
d D 5.1 85/05/31 11:42:07 dist 5 4
c Add copyright
e
s 00002/00000/00365
d D 1.3 83/07/02 00:26:55 sam 4 2
c from sun
e
s 00002/00000/00365
d R 1.3 83/07/01 02:45:02 sam 3 2
c from sun
e
s 00005/00007/00360
d D 1.2 82/01/22 17:55:58 rrh 2 1
c Re proceduralization in errortouch for clarity.
c Added -T (terse option)
c Added typedefs, and changed textual form of structures
c changed argument to vi to begin searching from line 1, instead of line $
e
s 00367/00000/00000
d D 1.1 80/10/16 09:46:41 root 1 0
c date and time created 80/10/16 09:46:41 by root
e
u
U
t
T
I 1
D 5
static	char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6

E 5
#include <stdio.h>
#include <ctype.h>
#include "error.h"

extern	char	*currentfilename;
static	char	*c_linenumber;
static	char	*unk_hdr[] = {"In", "program", "???"};
static	char	**c_header = &unk_hdr[0];

/*
 *	Attempt to handle error messages produced by pi (and by pc)
 *
 *	problem #1:	There is no file name available when a file does not
 *			use a #include; this will have to be given to error
 *			in the command line.
 *	problem #2:	pi doesn't always tell you what line number
 *			a error refers to; for example during the tree
 *			walk phase of code generation and error detection,
 *			an error can refer to "variable foo in procedure bletch"
 *			without giving a line number
 *	problem #3:	line numbers, when available, are attached to
 *			the source line, along with the source line itself
 *			These line numbers must be extracted, and
 *			the source line thrown away.
 *	problem #4:	Some error messages produce more than one line number
 *			on the same message.
 *			There are only two (I think):
 *				%s undefined on line%s
 *				%s improperly used on line%s
 *			here, the %s makes line plural or singular.
 *
 *	Here are the error strings used in pi version 1.2 that can refer
 *	to a file name or line number:
 *
 *		Multiply defined label in case, lines %d and %d
 *		Goto %s from line %d is into a structured statement
 *		End matched %s on line %d
 *		Inserted keyword end matching %s on line %d
 *
 *	Here are the general pi patterns recognized:
 *	define piptr == -.*^-.*
 *	define msg = .*
 *	define digit = [0-9]
 *	definename = .*
 *	define date_format letter*3 letter*3 (digit | (digit digit)) 
 *			(digit | (digit digit)):digit*2 digit*4
 *
 *	{e,E} (piptr) (msg)	Encounter an error during textual scan
 *	E {digit}* - (msg)	Have an error message that refers to a new line
 *	E - msg			Have an error message that refers to current
 *					function, program or procedure
 *	(date_format) (name):	When switch compilation files
 *	... (msg)		When refer to the previous line
 *	'In' ('procedure'|'function'|'program') (name):
 *				pi is now complaining about 2nd pass errors.
 *	
 *	Here is the output from a compilation
 *
 *
 *	     2  	var	i:integer;
 *	e --------------^--- Inserted ';'
 *	E 2 - All variables must be declared in one var part
 *	E 5 - Include filename must end in .i
 *	Mon Apr 21 15:56 1980  test.h:
 *	     2  begin
 *	e ------^--- Inserted ';'
 *	Mon Apr 21 16:06 1980  test.p:
 *	E 2 - Function type must be specified
 *	     6  procedure foo(var x:real);
 *	e ------^--- Inserted ';'
 *	In function bletch:
 *	  E - No assignment to the function variable
 *	  w - variable x is never used
 *	E 6 - foo is already defined in this block
 *	In procedure foo:
 *	  w - variable x is neither used nor set
 *	     9  	z : = 23;
 *	E --------------^--- Undefined variable
 *	    10  	y = [1];
 *	e ----------------^--- Inserted ':'
 *	    13  	z := 345.;
 *	e -----------------------^--- Digits required after decimal point
 *	E 10 - Constant set involved in non set context
 *	E 11 - Type clash: real is incompatible with integer
 *	   ... Type of expression clashed with type of variable in assignment
 *	E 12 - Parameter type not identical to type of var parameter x of foo
 *	In program mung:
 *	  w - variable y is never used
 *	  w - type foo is never used
 *	  w - function bletch is never used
 *	  E - z undefined on lines 9 13
 */
char *Months[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct","Nov", "Dec",
	0
};
char *Days[] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", 0
};
char *Piroutines[] = {
		"program", "function", "procedure", 0
};


static boolean	structured, multiple;

char *pi_Endmatched[] = {"End", "matched"};
char *pi_Inserted[] = {"Inserted", "keyword", "end", "matching"};

char *pi_multiple[] = {"Mutiply", "defined", "label", "in", "case,", "line"};
char *pi_structured[] = {"is", "into", "a", "structured", "statement"};

char *pi_und1[] = {"undefined", "on", "line"};
char *pi_und2[] = {"undefined", "on", "lines"};
char *pi_imp1[] = {"improperly", "used", "on", "line"};
char *pi_imp2[] = {"improperly", "used", "on", "lines"};

boolean alldigits(string)
D 2
	register	char	*string;
E 2
I 2
	reg	char	*string;
E 2
{
	for (; *string && isdigit(*string); string++)
		continue;
	return(*string == '\0');
}
boolean instringset(member, set)
D 2
			char	*member;
	register	char	**set;
E 2
I 2
		char	*member;
	reg	char	**set;
E 2
{
	for(; *set; set++){
		if (strcmp(*set, member) == 0)
			return(TRUE);
	}
	return(FALSE);
}

boolean isdateformat(wordc, wordv)
	int	wordc;
	char	**wordv;
{
	return(
	        (wordc == 5)
	     && (instringset(wordv[0], Days))
	     && (instringset(wordv[1], Months))
	     && (alldigits(wordv[2]))
	     && (alldigits(wordv[4])) );
}

boolean piptr(string)
D 2
	register	char	*string;
E 2
I 2
	reg	char	*string;
E 2
{
D 2
	int	state = 0;
E 2
	if (*string != '-')
		return(FALSE);
	while (*string && *string == '-')
		string++;
	if (*string != '^')
		return(FALSE);
	string++;
	while (*string && *string == '-')
		string++;
	return(*string == '\0');
}

extern	int	wordc;
extern	char	**wordv;

Errorclass pi()
{
	char	**nwordv;
D 2
	char	buffer[128];
E 2

I 4
	if (wordc < 2)
		return (C_UNKNOWN);
E 4
	if (   ( strlen(wordv[1]) == 1)
	    && ( (wordv[1][0] == 'e') || (wordv[1][0] == 'E') )
	    && ( piptr(wordv[2]) )
	) {
		boolean	longpiptr = 0;
		/*
		 *	We have recognized a first pass error of the form:
		 *	letter ------^---- message
		 *
		 *	turn into an error message of the form:
		 *
		 *	file line 'pascal errortype' letter \n |---- message
		 *	or of the form:
		 *	file line letter |---- message
		 *		when there are strlen("(*[pi]") or more
		 *		preceding '-' on the error pointer.
		 *
		 *	Where the | is intended to be a down arrow, so that
		 *	the pi error messages can be inserted above the
		 *	line in error, instead of below.  (All of the other
		 *	langauges put thier messages before the source line,
		 *	instead of after it as does pi.)
		 *
		 *	where the pointer to the error has been truncated
		 *	by 6 characters to account for the fact that
		 *	the pointer points into a tab preceded input line.
		 */
		language = INPI;
D 2
		substitute(wordv[2], '^', '|');
E 2
I 2
		(void)substitute(wordv[2], '^', '|');
E 2
		longpiptr = position(wordv[2],'|') > (6+8);
		nwordv = wordvsplice(longpiptr ? 2 : 4, wordc, wordv+1);
		nwordv[0] = strsave(currentfilename);
		nwordv[1] = strsave(c_linenumber);
		if (!longpiptr){
			nwordv[2] = "pascal errortype";
			nwordv[3] = wordv[1];
			nwordv[4] = strsave("%%%\n");
			if (strlen(nwordv[5]) > (8-2))	/* this is the pointer */
				nwordv[5] += (8-2);	/* bump over 6 characters */
		}
		wordv = nwordv - 1;		/* convert to 1 based */
		wordc += longpiptr ? 2 : 4;
		return(C_TRUE);
	}
	if (   (wordc >= 4)
	    && (strlen(wordv[1]) == 1)
	    && ( (*wordv[1] == 'E') || (*wordv[1] == 'w') || (*wordv[1] == 'e') )
	    && (alldigits(wordv[2]))
	    && (strlen(wordv[3]) == 1)
	    && (wordv[3][0] == '-')
	){
		/*
		 *	Message of the form: letter linenumber - message
		 *	Turn into form: filename linenumber letter - message
		 */
		language = INPI;
		nwordv = wordvsplice(1, wordc, wordv + 1);
		nwordv[0] = strsave(currentfilename);
		nwordv[1] = wordv[2];
		nwordv[2] = wordv[1];
		c_linenumber = wordv[2];
		wordc += 1;
		wordv = nwordv - 1;
		return(C_TRUE);
	}
	if (   (wordc >= 3)
	    && (strlen(wordv[1]) == 1)
	    && ( (*(wordv[1]) == 'E') || (*(wordv[1]) == 'w') || (*(wordv[1]) == 'e') )
	    && (strlen(wordv[2]) == 1)
	    && (wordv[2][0] == '-')
	) {
		/*
		 *	Message of the form: letter - message
		 *	This happens only when we are traversing the tree
		 *	during the second pass of pi, and discover semantic
		 *	errors.
		 *
		 *	We have already (presumably) saved the header message
		 *	and can now construct a nulled error message for the
		 *	current file.
		 *
		 *	Turns into a message of the form:
		 *	filename (header) letter - message
		 *	
		 *	First, see if it is a message referring to more than
		 *	one line number.  Only of the form:
 		 *		%s undefined on line%s
 		 *		%s improperly used on line%s
		 */
		boolean undefined = 0;
		int	wordindex;

		language = INPI;
		if (    (undefined = (wordvcmp(wordv+2, 3, pi_und1) == 0) )
		     || (undefined = (wordvcmp(wordv+2, 3, pi_und2) == 0) )
		     || (wordvcmp(wordv+2, 4, pi_imp1) == 0)
		     || (wordvcmp(wordv+2, 4, pi_imp2) == 0)
		){
			for (wordindex = undefined ? 5 : 6; wordindex <= wordc;
			    wordindex++){
				nwordv = wordvsplice(2, undefined ? 2 : 3, wordv+1);
				nwordv[0] = strsave(currentfilename);
				nwordv[1] = wordv[wordindex];
				if (wordindex != wordc)
					erroradd(undefined ? 4 : 5, nwordv,
						C_TRUE, C_UNKNOWN);
			}
			wordc = undefined ? 4 : 5;
			wordv = nwordv - 1;
			return(C_TRUE);
		}

		nwordv = wordvsplice(1+3, wordc, wordv+1);
		nwordv[0] = strsave(currentfilename);
		nwordv[1] = strsave(c_header[0]);
		nwordv[2] = strsave(c_header[1]);
		nwordv[3] = strsave(c_header[2]);
		wordv = nwordv - 1;
		wordc += 1 + 3;
		return(C_THISFILE);
	}
	if (strcmp(wordv[1], "...") == 0){
		/*
		 *	have a continuation error message
		 *	of the form: ... message
		 *	Turn into form : filename linenumber message
		 */
		language = INPI;
		nwordv = wordvsplice(1, wordc, wordv+1);
		nwordv[0] = strsave(currentfilename);
		nwordv[1] = strsave(c_linenumber);
		wordv = nwordv - 1;
		wordc += 1;
		return(C_TRUE);
	}
	if(   (wordc == 6)
	   && (lastchar(wordv[6]) == ':')
	   && (isdateformat(5, wordv + 1))
	){
		/*
		 *	Have message that tells us we have changed files
		 */
		language = INPI;
		currentfilename = strsave(wordv[6]);
		clob_last(currentfilename, '\0');
		return(C_SYNC);
	}
	if(   (wordc == 3)
	   && (strcmp(wordv[1], "In") == 0)
	   && (lastchar(wordv[3]) == ':')
	   && (instringset(wordv[2], Piroutines))
	) {
		language = INPI;
		c_header = wordvsplice(0, wordc, wordv+1);
		return(C_SYNC);
	}
	/*
	 *	now, check for just the line number followed by the text
	 */
	if (alldigits(wordv[1])){
		language = INPI;
		c_linenumber = wordv[1];
		return(C_IGNORE);
	}
	/*
	 *	Attempt to match messages refering to a line number
	 *
	 *	Multiply defined label in case, lines %d and %d
	 *	Goto %s from line %d is into a structured statement
	 *	End matched %s on line %d
	 *	Inserted keyword end matching %s on line %d
	 */
	multiple = structured = 0;
	if (
	       ( (wordc == 6) && (wordvcmp(wordv+1, 2, pi_Endmatched) == 0))
	    || ( (wordc == 8) && (wordvcmp(wordv+1, 4, pi_Inserted) == 0))
	    || ( multiple = ((wordc == 9) && (wordvcmp(wordv+1,6, pi_multiple) == 0) ) )
	    || ( structured = ((wordc == 10) && (wordvcmp(wordv+6,5, pi_structured) == 0 ) ))
	){
		language = INPI;
		nwordv = wordvsplice(2, wordc, wordv+1);
		nwordv[0] = strsave(currentfilename);
		nwordv[1] = structured ? wordv [5] : wordv[wordc];
		wordc += 2;
		wordv = nwordv - 1;
		if (!multiple)
			return(C_TRUE);
		erroradd(wordc, nwordv, C_TRUE, C_UNKNOWN);
		nwordv = wordvsplice(0, wordc, nwordv);
		nwordv[1] = wordv[wordc - 2];
		return(C_TRUE);
	}
	return(C_UNKNOWN);
}
E 1
