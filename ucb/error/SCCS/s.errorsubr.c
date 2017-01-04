h49703
s 00010/00005/00395
d D 5.3 88/06/29 18:50:58 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00391
d D 5.2 88/06/06 21:51:37 bostic 8 7
c written by Robert Henry; add Berkeley specific header
e
s 00010/00001/00384
d D 5.1 85/05/31 11:42:30 dist 7 6
c Add copyright
e
s 00003/00000/00382
d D 1.6 84/12/11 16:07:07 rrh 6 5
c add decwrl modula2 (this quick&dirty: the ^ pointers mod2 generates
c to point to the point of the error aren't shown in the output of error)
e
s 00007/00005/00375
d D 1.5 83/07/01 02:53:12 sam 5 4
c nil pointers
e
s 00003/00000/00377
d D 1.4 83/06/14 15:41:52 rrh 4 3
c add error category for troff; delimited just like pcc ccom, except
c uses ` and ' instead of "
e
s 00019/00007/00358
d D 1.3 83/02/09 15:32:16 sam 3 2
c from sun
e
s 00050/00032/00315
d D 1.2 82/01/22 17:56:10 rrh 2 1
c Re proceduralization in errortouch for clarity.
c Added -T (terse option)
c Added typedefs, and changed textual form of structures
c changed argument to vi to begin searching from line 1, instead of line $
e
s 00347/00000/00000
d D 1.1 80/10/16 09:46:45 root 1 0
c date and time created 80/10/16 09:46:45 by root
e
u
U
t
T
I 1
D 7
static	char *sccsid = "%W% (Berkeley) %G%";
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8

E 7
#include <stdio.h>
#include <ctype.h>
#include "error.h"
/*
D 2
 *	go through and arrayify a list of rules
E 2
I 2
 *	Arrayify a list of rules
E 2
 */
arrayify(e_length, e_array, header)
D 2
	int			*e_length;
	struct	error_desc	***e_array;
	struct	error_desc	*header;
E 2
I 2
	int	*e_length;
	Eptr	**e_array;
	Eptr	header;
E 2
{
D 2
	register	struct	error_desc	*errorp;
	register	struct	error_desc	**array;
	register	int	listlength;
	register	int	listindex;
E 2
I 2
	reg	Eptr	errorp;
	reg	Eptr	*array;
	reg	int	listlength;
	reg	int	listindex;
E 2

	for (errorp = header, listlength = 0;
	     errorp; errorp = errorp->error_next, listlength++)
		continue;
D 2
	array = (struct error_desc **)Calloc(listlength+1,sizeof (struct error_desc*));
E 2
I 2
	array = (Eptr*)Calloc(listlength+1, sizeof (Eptr));
E 2
	for(listindex = 0, errorp = header;
	    listindex < listlength;
	    listindex++, errorp = errorp->error_next){
		array[listindex] = errorp;
		errorp->error_position = listindex;
	}
D 2
	array[listindex] = (struct error_desc *)0;
E 2
I 2
	array[listindex] = (Eptr)0;
E 2
	*e_length = listlength;
	*e_array = array;
}

/*VARARGS1*/
error(msg, a1, a2, a3)
	char	*msg;
{
	fprintf(stderr, "Error: ");
	fprintf(stderr, msg, a1, a2, a3);
	fprintf(stderr, "\n");
	fflush(stdout);
	fflush(stderr);
	exit(6);
}
/*ARGSUSED*/
char *Calloc(nelements, size)
	int	nelements;
	int	size;
{
	char	*back;
	if ( (back = (char *)calloc(nelements, size)) == (char *)NULL){
		error("Ran out of memory.\n");
		exit(1);
	}
	return(back);
}

char *strsave(instring)
	char	*instring;
{
	char	*outstring;
D 2
	strcpy(outstring = (char *)Calloc(1, strlen(instring) + 1), instring);
E 2
I 2
	(void)strcpy(outstring = (char *)Calloc(1, strlen(instring) + 1),
		instring);
E 2
	return(outstring);
}
/*
 *	find the position of a given character in a string
 *		(one based)
 */
int position(string, ch)
D 2
	register	char	*string;
	register	char	ch;
E 2
I 2
	reg	char	*string;
	reg	char	ch;
E 2
{
D 2
	register	int	i;
E 2
I 2
	reg	int	i;
I 3
	if (string)
E 3
E 2
	for (i=1; *string; string++, i++){
		if (*string == ch)
			return(i);
	}
	return(-1);
}
/*
 *	clobber the first occurance of ch in string by the new character
 */
char *substitute(string, chold, chnew)
	char	*string;
	char	chold, chnew;
{
D 2
	register	char	*cp = string;
E 2
I 2
	reg	char	*cp = string;
E 2

I 3
	if (cp)
E 3
	while (*cp){
		if (*cp == chold){
			*cp = chnew;
			break;
		}
		cp++;
	}
	return(string);
}

char lastchar(string)
	char	*string;
{
	int	length;
I 3
	if (string == 0) return('\0');
E 3
	length = strlen(string);
	if (length >= 1)
		return(string[length-1]);
	else
		return('\0');
}

char firstchar(string)
	char	*string;
{
D 3
	return(string[0]);
E 3
I 3
	if (string)
		return(string[0]);
	else
		return('\0');
E 3
}

char	next_lastchar(string)
	char	*string;
{
	int	length;
I 3
	if (string == 0) return('\0');
E 3
	length = strlen(string);
	if (length >= 2)
		return(string[length - 2]);
	else
		return('\0');
}

clob_last(string, newstuff)
	char	*string, newstuff;
{
D 3
	int	length;
	length = strlen(string);
E 3
I 3
	int	length = 0;
	if (string)
		length = strlen(string);
E 3
	if (length >= 1)
		string[length - 1] = newstuff;
}

/*
 *	parse a string that is the result of a format %s(%d)
 *	return TRUE if this is of the proper format
 */
boolean persperdexplode(string, r_perd, r_pers)
	char	*string;
	char	**r_perd, **r_pers;
{
D 2
	register	char	*cp;
	int		length;
E 2
I 2
	reg	char	*cp;
D 3
		int	length;
E 3
I 3
		int	length = 0;
E 3
E 2

D 3
	length = strlen(string);
E 3
I 3
	if (string)
		length = strlen(string);
E 3
	if (   (length >= 4)
	    && (string[length - 1] == ')' ) ){
		for (cp = &string[length - 2];
		     (isdigit(*cp)) && (*cp != '(');
		     --cp)
			continue;
		if (*cp == '('){
			string[length - 1] = '\0';	/* clobber the ) */
			*r_perd = strsave(cp+1);
			string[length - 1] = ')';
			*cp = '\0';			/* clobber the ( */
			*r_pers = strsave(string);
			*cp = '(';
			return(TRUE);
		} 
	}
	return(FALSE);
}
/*
 *	parse a quoted string that is the result of a format \"%s\"(%d)
 *	return TRUE if this is of the proper format
 */
boolean qpersperdexplode(string, r_perd, r_pers)
	char	*string;
	char	**r_perd, **r_pers;
{
D 2
	register	char	*cp;
	int		length;
E 2
I 2
	reg	char	*cp;
D 3
		int	length;
E 3
I 3
		int	length = 0;
E 3
E 2

D 3
	length = strlen(string);
E 3
I 3
	if (string)
		length = strlen(string);
E 3
	if (   (length >= 4)
	    && (string[length - 1] == ')' ) ){
		for (cp = &string[length - 2];
		     (isdigit(*cp)) && (*cp != '(');
		     --cp)
			continue;
		if (*cp == '(' && *(cp - 1) == '"'){
			string[length - 1] = '\0';
			*r_perd = strsave(cp+1);
			string[length - 1] = ')';
			*(cp - 1) = '\0';		/* clobber the " */
			*r_pers = strsave(string + 1);
			*(cp - 1) = '"';
			return(TRUE);
		} 
	}
	return(FALSE);
}

static	char	cincomment[] = CINCOMMENT;
static	char	coutcomment[] = COUTCOMMENT;
static	char	fincomment[] = FINCOMMENT;
static	char	foutcomment[] = FOUTCOMMENT;
static	char	newline[] = NEWLINE;
static	char	piincomment[] = PIINCOMMENT;
static	char	pioutcomment[] = PIOUTCOMMENT;
static	char	lispincomment[] = LISPINCOMMENT;
static	char	riincomment[] = RIINCOMMENT;
static	char	rioutcomment[] = RIOUTCOMMENT;
I 4
static	char	troffincomment[] = TROFFINCOMMENT;
static	char	troffoutcomment[] = TROFFOUTCOMMENT;
I 6
static	char	mod2incomment[] = MOD2INCOMMENT;
static	char	mod2outcomment[] = MOD2OUTCOMMENT;
E 6
E 4

struct	lang_desc lang_table[] = {
	/*INUNKNOWN	0*/	"unknown", cincomment,	coutcomment,
	/*INCPP		1*/	"cpp",	cincomment,    coutcomment,
	/*INCC		2*/	"cc",	cincomment,    coutcomment,
	/*INAS		3*/	"as",	ASINCOMMENT,   newline,
	/*INLD		4*/	"ld",	cincomment,    coutcomment,
	/*INLINT	5*/	"lint",	cincomment,    coutcomment,
	/*INF77		6*/	"f77",	fincomment,    foutcomment,
	/*INPI		7*/	"pi",	piincomment,   pioutcomment,
	/*INPC		8*/	"pc",	piincomment,   pioutcomment,
	/*INFRANZ	9*/	"franz",lispincomment, newline,
	/*INLISP	10*/	"lisp",	lispincomment, newline,
	/*INVAXIMA	11*/	"vaxima",lispincomment,newline,
	/*INRATFOR	12*/	"ratfor",fincomment,   foutcomment,
	/*INLEX		13*/	"lex",	cincomment,    coutcomment,
	/*INYACC	14*/	"yacc",	cincomment,    coutcomment,
	/*INAPL		15*/	"apl",	".lm",	       newline,
	/*INMAKE	16*/	"make",	ASINCOMMENT,   newline,
	/*INRI		17*/	"ri",	riincomment,   rioutcomment,
I 4
	/*INTROFF	18*/	"troff",troffincomment,troffoutcomment,
I 6
	/*INMOD2	19*/	"mod2",	mod2incomment, mod2outcomment,
E 6
E 4
				0,	0,	     0
};

printerrors(look_at_subclass, errorc, errorv)
	boolean	look_at_subclass;
	int	errorc;
D 2
	struct	error_desc	*errorv[];
E 2
I 2
	Eptr	errorv[];
E 2
{
D 2
	register	int	i;
	register	struct	error_desc	*errorp;
E 2
I 2
	reg	int	i;
	reg	Eptr	errorp;

E 2
	for (errorp = errorv[i = 0]; i < errorc; errorp = errorv[++i]){
		if (errorp->error_e_class == C_IGNORE)
			continue;
		if (look_at_subclass && errorp->error_s_class == C_DUPL)
			continue;
		printf("Error %d, (%s error) [%s], text = \"",
			i,
			class_table[errorp->error_e_class],
			lang_table[errorp->error_language].lang_name);
		wordvprint(stdout,errorp->error_lgtext,errorp->error_text);
		printf("\"\n");
	}
}

wordvprint(fyle, wordc, wordv)
	FILE	*fyle;
	int	wordc;
	char	*wordv[];
{
	int	i;
D 5
	for(i = 0; i < wordc; i++){
		fprintf(fyle, "%s",wordv[i]);
		if (i != wordc - 1)
			fprintf(fyle, " ");
	}
E 5
I 5
	char *sep = "";

	for(i = 0; i < wordc; i++)
		if (wordv[i]) {
			fprintf(fyle, "%s%s",sep,wordv[i]);
			sep = " ";
		}
E 5
}

/*
 *	Given a string, parse it into a number of words, and build
 *	a wordc wordv combination pointing into it.
 */
wordvbuild(string, r_wordc, r_wordv)
	char	*string;
	int	*r_wordc;
	char	***r_wordv;
{
D 2
	register	char 	*cp;
			char	*saltedbuffer;
			char	**wordv;
			int	wordcount;
			int	wordindex;
E 2
I 2
	reg	char 	*cp;
		char	*saltedbuffer;
		char	**wordv;
		int	wordcount;
		int	wordindex;
E 2

	saltedbuffer = strsave(string);
	for (wordcount = 0, cp = saltedbuffer; *cp; wordcount++){
		while (*cp  && isspace(*cp))
			cp++;
		if (*cp == 0)
			break;
		while (!isspace(*cp))
			cp++;
	}
	wordv = (char **)Calloc(wordcount + 1, sizeof (char *));
	for (cp=saltedbuffer,wordindex=0; wordcount; wordindex++,--wordcount){
		while (*cp && isspace(*cp))
			cp++;
		if (*cp == 0)
			break;
		wordv[wordindex] = cp;
		while(!isspace(*cp))
			cp++;
		*cp++ = '\0';
	}
	if (wordcount != 0)
		error("Initial miscount of the number of words in a line\n");
	wordv[wordindex] = (char *)0;
#ifdef FULLDEBUG
	for (wordcount = 0; wordcount < wordindex; wordcount++)
		printf("Word %d = \"%s\"\n", wordcount, wordv[wordcount]);
	printf("\n");
#endif
	*r_wordc = wordindex;
	*r_wordv = wordv;
}
/*
 *	Compare two 0 based wordvectors
 */
int wordvcmp(wordv1, wordc, wordv2)
	char	**wordv1;
	int	wordc;
	char	**wordv2;
{
D 2
	register	int i;
			int	back;
E 2
I 2
	reg	int i;
		int	back;
E 2
	for (i = 0; i < wordc; i++){
I 3
		if (wordv1[i] == 0 || wordv2[i] == 0)
				return(-1);
E 3
		if (back = strcmp(wordv1[i], wordv2[i])){
			return(back);
		}
	}
	return(0);	/* they are equal */
}
		
/*
 *	splice a 0 basedword vector onto the tail of a
 *	new wordv, allowing the first emptyhead slots to be empty
 */
char	**wordvsplice(emptyhead, wordc, wordv)
	int	emptyhead;
	int	wordc;
	char	**wordv;
{
D 2
	register	char	**nwordv;
	int	nwordc = emptyhead + wordc;
	register	int	i;
E 2
I 2
	reg	char	**nwordv;
		int	nwordc = emptyhead + wordc;
	reg	int	i;
E 2

	nwordv = (char **)Calloc(nwordc, sizeof (char *));
	for (i = 0; i < emptyhead; i++)
		nwordv[i] = 0;
	for(i = emptyhead; i < nwordc; i++){
		nwordv[i] = wordv[i-emptyhead];
	}
	return(nwordv);
}
I 2
/*
 *	plural'ize and verb forms
 */
static	char	*S = "s";
static	char	*N = "";
char *plural(n)
	int	n;
{
	return( n > 1 ? S : N);
}
char *verbform(n)
	int	n;
{
	return( n > 1 ? N : S);
}

E 2
E 1
