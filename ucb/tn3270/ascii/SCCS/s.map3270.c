h38786
s 00011/00021/00899
d D 3.2 88/03/28 12:54:42 bostic 10 9
c add Berkeley specific header
e
s 00000/00000/00920
d D 3.1 87/08/11 10:18:17 minshall 9 8
c New version numbering.
e
s 00002/00002/00918
d D 1.8 87/07/17 10:02:10 minshall 8 7
c Install sccs headers and copyright notices.
e
s 00001/00001/00919
d D 1.7 87/06/19 12:50:18 minshall 7 6
c directory changes, plus "GetTc" returns -1 on error.
e
s 00020/00043/00900
d D 1.6 87/05/31 17:09:45 minshall 6 5
c Version without termcodes.m4.
e
s 00001/00001/00942
d D 1.5 87/05/22 09:53:27 minshall 5 4
c New directory structure.
e
s 00025/00013/00918
d D 1.4 87/05/18 11:03:42 minshall 4 3
c For MSC compiler, make string literals short.
e
s 00000/00002/00931
d D 1.3 87/05/13 11:58:49 minshall 3 2
c We need 'uncontrol' under all circumstances.
e
s 00046/00015/00887
d D 1.2 87/05/12 14:08:37 minshall 2 1
c Remove curses.h, include strings.h or string.h depending on 
c the environment.
e
s 00902/00000/00000
d D 1.1 87/05/10 11:35:09 minshall 1 0
c date and time created 87/05/10 11:35:09 by minshall
e
u
U
t
T
I 1
/*
D 8
 *	Copyright (c) 1984, 1985, 1986 by the Regents of the
E 8
I 8
D 10
 *	Copyright (c) 1984-1987 by the Regents of the
E 8
 *	University of California and by Gregory Glenn Minshall.
E 10
I 10
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 10
 *
D 10
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 10
I 10
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
 */

D 10
#ifndef	lint
D 8
static	char	sccsid[] = "@(#)map3270.c	3.1  10/29/86";
E 8
I 8
static	char	sccsid[] = "%W% (Berkeley) %G%";
E 8
#endif	/* ndef lint */

E 10
I 10
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10

/*	This program reads a description file, somewhat like /etc/termcap,
    that describes the mapping between the current terminal's keyboard and
    a 3270 keyboard.
 */
#ifdef DOCUMENTATION_ONLY
/* here is a sample (very small) entry...

	# this table is sensitive to position on a line.  In particular,
	# a terminal definition for a terminal is terminated whenever a
	# (non-comment) line beginning in column one is found.
	#
	# this is an entry to map tvi924 to 3270 keys...
	v8|tvi924|924|televideo model 924 {
		pfk1 =	'\E1';
		pfk2 =	'\E2';
		clear = '^z';		# clear the screen
	}
 */
#endif /* DOCUMENTATION_ONLY */

#include <stdio.h>
#include <ctype.h>
D 2
#include <curses.h>
E 2
I 2
#if	defined(unix)
E 2
#include <strings.h>
I 2
#else	/* defined(unix) */
#include <string.h>
#endif	/* defined(unix) */
E 2

#define	IsPrint(c)	((isprint(c) && !isspace(c)) || ((c) == ' '))

D 6
#define	LETS_SEE_ASCII
#include "m4.out"

E 6
#include "state.h"

D 5
#include "../system/globals.h"
E 5
I 5
#include "../general/globals.h"
E 5
#include "map3270.ext"

/* this is the list of types returned by the lex processor */
D 6
#define	LEX_CHAR	TC_HIGHEST		/* plain unadorned character */
E 6
I 6
#define	LEX_CHAR	400			/* plain unadorned character */
E 6
#define	LEX_ESCAPED	LEX_CHAR+1		/* escaped with \ */
#define	LEX_CARETED	LEX_ESCAPED+1		/* escaped with ^ */
#define	LEX_END_OF_FILE LEX_CARETED+1		/* end of file encountered */
#define	LEX_ILLEGAL	LEX_END_OF_FILE+1	/* trailing escape character */

/* the following is part of our character set dependancy... */
#define	ESCAPE		0x1b
#define	TAB		0x09
#define	NEWLINE 	0x0a
#define	CARRIAGE_RETURN 0x0d

typedef struct {
    int type;		/* LEX_* - type of character */
    int value;		/* character this was */
} lexicon;

typedef struct {
    int		length;		/* length of character string */
    char	array[500];	/* character string */
} stringWithLength;

#define	panic(s)	{ fprintf(stderr, s); exit(1); }

D 6
static state firstentry = { 0, TC_NULL, 0, 0 };
E 6
I 6
static state firstentry = { 0, STATE_NULL, 0, 0 };
E 6
static state *headOfQueue = &firstentry;

/* the following is a primitive adm3a table, to be used when nothing
 * else seems to be avaliable.
 */

#ifdef	DEBUG
static int debug = 0;		/* debug flag (for debuggin tables) */
#endif	/* DEBUG */

D 6
static int doPaste = 1;			/* should we have side effects */
static int picky = 0;			/* do we complain of unknown TC's? */
static char usePointer = 0;		/* use pointer, or file */
E 6
I 6
static int (*GetTc)();
static int doPaste = 1;		/* should we have side effects */
static int picky = 0;		/* do we complain of unknown functions? */
static char usePointer = 0;	/* use pointer, or file */
E 6
static FILE *ourFile= 0;
D 6
static char *environPointer = 0;	/* if non-zero, point to input
					 * string in core.
					 */
E 6
I 6
static char *environPointer = 0;/* if non-zero, point to input
				 * string in core.
				 */
E 6
D 4
static char keys3a[] =
E 4
I 4
static char **whichkey = 0;
static char *keysgeneric[] = {
E 4
#include "default.map"		/* Define the default default */
I 4

	0,			/* Terminate list of entries */
};
E 4
			;

static	int	Empty = 1,		/* is the unget lifo empty? */
		Full = 0;		/* is the unget lifo full? */
D 2
static	lexicon	lifo[200] = 0;		/* character stack for parser */
E 2
I 2
static	lexicon	lifo[200] = { 0 };	/* character stack for parser */
E 2
static	int	rp = 0,			/* read pointer into lifo */
		wp = 0;			/* write pointer into lifo */

static int
GetC()
{
    int character;

    if (usePointer) {
D 4
	if (*environPointer) {
	    character = 0xff&*environPointer++;
	} else {
	    static char suffix = 'A';
	    char envname[9];
	    extern char *getenv();
E 4
I 4
	if ((*environPointer) == 0) {
	    /*
	     * If we have reached the end of this string, go on to
	     * the next (if there is a next).
	     */
	    if (whichkey == 0) {
		static char suffix = 'A';	/* From environment */
		char envname[9];
		extern char *getenv();
E 4

D 4
	    (void) sprintf(envname, "MAP3270%c", suffix++);
	    environPointer = getenv(envname);
	    if (*environPointer) {
	       character = 0xff&*environPointer++;
E 4
I 4
		(void) sprintf(envname, "MAP3270%c", suffix++);
		environPointer = getenv(envname);
E 4
	    } else {
D 4
	       character = EOF;
E 4
I 4
		whichkey++;			/* default map */
		environPointer = *whichkey;
E 4
	    }
	}
I 4
	if (*environPointer) {
	   character = 0xff&*environPointer++;
	} else {
	   character = EOF;
	}
E 4
    } else {
	character = getc(ourFile);
    }
    return(character);
}

static lexicon
Get()
{
    lexicon c;
    register lexicon *pC = &c;
    register int character;

    if (!Empty) {
	*pC = lifo[rp];
	rp++;
	if (rp == sizeof lifo/sizeof (lexicon)) {
	    rp = 0;
	}
	if (rp == wp) {
	    Empty = 1;
	}
	Full = 0;
    } else {
	character = GetC();
	switch (character) {
	case EOF:
	    pC->type = LEX_END_OF_FILE;
	    break;
	case '^':
	    character = GetC();
	    if (!IsPrint(character)) {
		pC->type = LEX_ILLEGAL;
	    } else {
		pC->type = LEX_CARETED;
		if (character == '?') {
		    character |= 0x40;	/* rubout */
		} else {
		    character &= 0x1f;
		}
	    }
	    break;
	case '\\':
	    character = GetC();
	    if (!IsPrint(character)) {
		pC->type = LEX_ILLEGAL;
	    } else {
		pC->type = LEX_ESCAPED;
		switch (character) {
		case 'E': case 'e':
		    character = ESCAPE;
		    break;
		case 't':
		    character = TAB;
		    break;
		case 'n':
		    character = NEWLINE;
		    break;
		case 'r':
		    character = CARRIAGE_RETURN;
		    break;
		default:
		    pC->type = LEX_ILLEGAL;
		    break;
		}
	    }
	    break;
	default:
	    if ((IsPrint(character)) || isspace(character)) {
		pC->type = LEX_CHAR;
	    } else {
		pC->type = LEX_ILLEGAL;
	    }
	    break;
	}
	pC->value = character;
    }
    return(*pC);
}

static void
UnGet(c)
lexicon c;			/* character to unget */
{
    if (Full) {
	fprintf(stderr, "attempt to put too many characters in lifo\n");
	panic("map3270");
	/* NOTREACHED */
    } else {
	lifo[wp] = c;
	wp++;
	if (wp == sizeof lifo/sizeof (lexicon)) {
	    wp = 0;
	}
	if (wp == rp) {
	    Full = 1;
	}
	Empty = 0;
    }
}

I 2
/*
 * Construct a control character sequence
 * for a special character.
 */
D 3
#if	defined(DEBUG)
E 3
char *
uncontrol(c)
	register int c;
{
	static char buf[3];

	if (c == 0x7f)
		return ("^?");
	if (c == '\377') {
		return "-1";
	}
	if (c >= 0x20) {
		buf[0] = c;
		buf[1] = 0;
	} else {
		buf[0] = '^';
		buf[1] = '@'+c;
		buf[2] = 0;
	}
	return (buf);
}
D 3
#endif	/* defined(DEBUG) */
E 3

E 2
/* compare two strings, ignoring case */

ustrcmp(string1, string2)
register char *string1;
register char *string2;
{
    register int c1, c2;

    while ((c1 = (unsigned char) *string1++) != 0) {
	if (isupper(c1)) {
	    c1 = tolower(c1);
	}
	if (isupper(c2 = (unsigned char) *string2++)) {
	    c2 = tolower(c2);
	}
	if (c1 < c2) {
	    return(-1);
	} else if (c1 > c2) {
	    return(1);
	}
    }
    if (*string2) {
	return(-1);
    } else {
	return(0);
    }
}


static stringWithLength *
GetQuotedString()
{
    lexicon lex;
    static stringWithLength output = { 0 };	/* where return value is held */
    char *pointer = output.array;

    lex = Get();
    if ((lex.type != LEX_CHAR) || (lex.value != '\'')) {
	UnGet(lex);
	return(0);
    }
    while (1) {
	lex = Get();
	if ((lex.type == LEX_CHAR) && (lex.value == '\'')) {
	    break;
	}
	if ((lex.type == LEX_CHAR) && !IsPrint(lex.value)) {
	    UnGet(lex);
	    return(0);		/* illegal character in quoted string */
	}
	if (pointer >= output.array+sizeof output.array) {
	    return(0);		/* too long */
	}
	*pointer++ = lex.value;
    }
    output.length = pointer-output.array;
    return(&output);
}

#ifdef	NOTUSED
static stringWithLength *
GetCharString()
{
    lexicon lex;
    static stringWithLength output;
    char *pointer = output.array;

    lex = Get();

    while ((lex.type == LEX_CHAR) &&
			!isspace(lex.value) && (lex.value != '=')) {
	*pointer++ = lex.value;
	lex = Get();
	if (pointer >= output.array + sizeof output.array) {
	    return(0);		/* too long */
	}
    }
    UnGet(lex);
    output.length = pointer-output.array;
    return(&output);
}
#endif	/* NOTUSED */

static
GetCharacter(character)
int	character;		/* desired character */
{
    lexicon lex;

    lex = Get();

    if ((lex.type != LEX_CHAR) || (lex.value != character)) {
	UnGet(lex);
	return(0);
    }
    return(1);
}

#ifdef	NOTUSED
static
GetString(string)
char	*string;		/* string to get */
{
    lexicon lex;

    while (*string) {
	lex = Get();
	if ((lex.type != LEX_CHAR) || (lex.value != *string&0xff)) {
	    UnGet(lex);
	    return(0);		/* XXX restore to state on entry */
	}
	string++;
    }
    return(1);
}
#endif	/* NOTUSED */


static stringWithLength *
GetAlphaMericString()
{
    lexicon lex;
    static stringWithLength output = { 0 };
    char *pointer = output.array;
#   define	IsAlnum(c)	(isalnum(c) || (c == '_') \
					|| (c == '-') || (c == '.'))

    lex = Get();

    if ((lex.type != LEX_CHAR) || !IsAlnum(lex.value)) {
	UnGet(lex);
	return(0);
    }

    while ((lex.type == LEX_CHAR) && IsAlnum(lex.value)) {
	*pointer++ = lex.value;
	lex = Get();
    }
    UnGet(lex);
    *pointer = 0;
    output.length = pointer-output.array;
    return(&output);
}


/* eat up characters until a new line, or end of file.  returns terminating
	character.
 */

static lexicon
EatToNL()
{
    lexicon lex;

    lex = Get();

    while (!((lex.type != LEX_ESCAPED) && (lex.type != LEX_CARETED) && 
		(lex.value == '\n')) && (!(lex.type == LEX_END_OF_FILE))) {
	lex = Get();
    }
    if (lex.type != LEX_END_OF_FILE) {
	return(Get());
    } else {
	return(lex);
    }
}


static void
GetWS()
{
    lexicon lex;

    lex = Get();

    while ((lex.type == LEX_CHAR) &&
			(isspace(lex.value) || (lex.value == '#'))) {
	if (lex.value == '#') {
	    lex = EatToNL();
	} else {
	    lex = Get();
	}
    }
    UnGet(lex);
}

static void
FreeState(pState)
state *pState;
{
    extern void free();

    free((char *)pState);
}


static state *
GetState()
{
    state *pState;
    extern char *malloc();

    pState = (state *) malloc(sizeof (state));

D 6
    pState->result = TC_NULL;
E 6
I 6
    pState->result = STATE_NULL;
E 6
    pState->next = 0;

    return(pState);
}


static state *
FindMatchAtThisLevel(pState, character)
state	*pState;
int	character;
{
    while (pState) {
	if (pState->match == character) {
	    return(pState);
	}
	pState = pState->next;
    }
    return(0);
}


static state *
PasteEntry(head, string, count, identifier)
state			*head;		/* points to who should point here... */
char			*string;	/* which characters to paste */
int			count;		/* number of character to do */
char			*identifier;	/* for error messages */
{
    state *pState, *other;

    if (!doPaste) {		/* flag to not have any side effects */
	return((state *)1);
    }
    if (!count) {
	return(head);	/* return pointer to the parent */
    }
D 6
    if ((head->result != TC_NULL) && (head->result != TC_GOTO)) {
E 6
I 6
    if ((head->result != STATE_NULL) && (head->result != STATE_GOTO)) {
E 6
	/* this means that a previously defined sequence is an initial
	 * part of this one.
	 */
	fprintf(stderr, "Conflicting entries found when scanning %s\n",
		identifier);
	return(0);
    }
#   ifdef	DEBUG
	if (debug) {
D 2
	    fprintf(stderr, "%s", unctrl(*string));
E 2
I 2
	    fprintf(stderr, "%s", uncontrol(*string));
E 2
	}
#   endif	/* DEBUG */
    pState = GetState();
    pState->match = *string;
D 6
    if (head->result == TC_NULL) {
	head->result = TC_GOTO;
E 6
I 6
    if (head->result == STATE_NULL) {
	head->result = STATE_GOTO;
E 6
	head->address = pState;
	other = pState;
    } else {		/* search for same character */
	if ((other = FindMatchAtThisLevel(head->address, *string)) != 0) {
	    FreeState(pState);
	} else {
	    pState->next = head->address;
	    head->address = pState;
	    other = pState;
	}
    }
    return(PasteEntry(other, string+1, count-1, identifier));
}

static
GetInput(tc, identifier)
int tc;
char *identifier;		/* entry being parsed (for error messages) */
{
    stringWithLength *outputString;
    state *head;
    state fakeQueue;

    if (doPaste) {
	head = headOfQueue;	/* always points to level above this one */
    } else {
	head = &fakeQueue;	/* don't have any side effects... */
    }

    if ((outputString = GetQuotedString()) == 0) {
	return(0);
    } else if (IsPrint(outputString->array[0])) {
	fprintf(stderr,
	 "first character of sequence for %s is not a control type character\n",
		identifier);
	return(0);
    } else {
	if ((head = PasteEntry(head, outputString->array,
				outputString->length, identifier)) == 0) {
	    return(0);
	}
	GetWS();
	while ((outputString = GetQuotedString()) != 0) {
	    if ((head = PasteEntry(head, outputString->array,
				outputString->length, identifier)) == 0) {
		return(0);
	    }
	    GetWS();
	}
    }
    if (!doPaste) {
	return(1);
    }
D 6
    if ((head->result != TC_NULL) && (head->result != tc)) {
E 6
I 6
    if ((head->result != STATE_NULL) && (head->result != tc)) {
E 6
	/* this means that this sequence is an initial part
	 * of a previously defined one.
	 */
	fprintf(stderr, "Conflicting entries found when scanning %s\n",
		identifier);
	return(0);
    } else {
	head->result = tc;
	return(1);		/* done */
    }
}

static
D 6
GetTc(string)
char *string;
{
    register TC_Ascii_t *Tc;

    for (Tc = TC_Ascii;
		Tc < TC_Ascii+sizeof TC_Ascii/sizeof (TC_Ascii_t); Tc++) {
	if (!ustrcmp(string, Tc->tc_name)) {
#	    ifdef	DEBUG
		if (debug) {
		    fprintf(stderr, "%s = ", Tc->tc_name);
		}
#	    endif	/* DEBUG */
	    return(Tc->tc_value&0xff);
	}
    }
    return(0);
}
static
E 6
GetDefinition()
{
    stringWithLength *string;
    int Tc;

    GetWS();
    if ((string = GetAlphaMericString()) == 0) {
	return(0);
    }
    string->array[string->length] = 0;
    if (doPaste) {
D 6
	if ((Tc = GetTc(string->array)) == 0) {
E 6
I 6
D 7
	if ((Tc = (*GetTc)(string->array)) == STATE_NULL) {
E 7
I 7
	if ((Tc = (*GetTc)(string->array)) == -1) {
E 7
E 6
	    if (picky) {
		fprintf(stderr, "%s: unknown 3270 key identifier\n",
							string->array);
	    }
D 6
	    Tc = TC_NULL;
	} else if (Tc < TC_LOWEST_USER) {
	    fprintf(stderr, "%s is not allowed to be specified by a user.\n",
			string->array);
	    return(0);
E 6
I 6
	    Tc = STATE_NULL;
E 6
	}
    } else {
D 6
	Tc = TC_LOWEST_USER;
E 6
I 6
	Tc = STATE_NULL;		/* XXX ? */
E 6
    }
    GetWS();
    if (!GetCharacter('=')) {
	fprintf(stderr,
		"Required equal sign after 3270 key identifier %s missing\n",
			string->array);
	return(0);
    }
    GetWS();
    if (!GetInput(Tc, string->array)) {
	fprintf(stderr, "Missing definition part for 3270 key %s\n",
				string->array);
	return(0);
    } else {
	GetWS();
	while (GetCharacter('|')) {
#	    ifdef	DEBUG
		if (debug) {
		    fprintf(stderr, " or ");
		}
#	    endif	/* DEBUG */
	    GetWS();
	    if (!GetInput(Tc, string->array)) {
		fprintf(stderr, "Missing definition part for 3270 key %s\n",
					string->array);
		return(0);
	    }
	    GetWS();
	}
    }
    GetWS();
    if (!GetCharacter(';')) {
	fprintf(stderr, "Missing semi-colon for 3270 key %s\n", string->array);
	return(0);
    }
#   ifdef	DEBUG
	if (debug) {
	    fprintf(stderr, ";\n");
	}
#   endif	/* DEBUG */
    return(1);
}


static
GetDefinitions()
{
    if (!GetDefinition()) {
	return(0);
    } else {
	while (GetDefinition()) {
	    ;
	}
    }
    return(1);
}

static
GetBegin()
{
    GetWS();
    if (!GetCharacter('{')) {
	return(0);
    }
    return(1);
}

static
GetEnd()
{
    GetWS();
    if (!GetCharacter('}')) {
	return(0);
    }
    return(1);
}

static
GetName()
{
    if (!GetAlphaMericString()) {
	return(0);
    }
    GetWS();
    while (GetAlphaMericString()) {
	GetWS();
    }
    return(1);
}

static
GetNames()
{
    GetWS();
    if (!GetName()) {
	return(0);
    } else {
	GetWS();
	while (GetCharacter('|')) {
	    GetWS();
	    if (!GetName()) {
		return(0);
	    }
	}
    }
    return(1);
}

static
GetEntry0()
{
    if (!GetBegin()) {
	fprintf(stderr, "no '{'\n");
	return(0);
    } else if (!GetDefinitions()) {
	fprintf(stderr, "unable to parse the definitions\n");
	return(0);
    } else if (!GetEnd()) {
	fprintf(stderr, "No '}' or scanning stopped early due to error.\n");
	return(0);
    } else {
	/* done */
	return(1);
    }
}


static
GetEntry()
{
    if (!GetNames()) {
	fprintf(stderr, "Invalid name field in entry.\n");
	return(0);
    } else {
	return(GetEntry0());
    }
}

/* position ourselves within a given filename to the entry for the current
 *	KEYBD (or TERM) variable
 */

Position(filename, keybdPointer)
char *filename;
char *keybdPointer;
{
    lexicon lex;
    stringWithLength *name = 0;
    stringWithLength *oldName;
#   define	Return(x) {doPaste = 1; return(x);}

    doPaste = 0;

    if ((ourFile = fopen(filename, "r")) == NULL) {
D 2
#   if !defined(msdos)
E 2
I 2
#   if !defined(MSDOS)
E 2
	fprintf(stderr, "Unable to open file %s\n", filename);
D 2
#   endif /* !defined(msdos) */
E 2
I 2
#   endif /* !defined(MSDOS) */
E 2
	Return(0);
    }
    lex = Get();
    while (lex.type != LEX_END_OF_FILE) {
	UnGet(lex);
	/* now, find an entry that is our type. */
	GetWS();
	oldName = name;
	if ((name = GetAlphaMericString()) != 0) {
	    if (!ustrcmp(name->array, keybdPointer)) {
		/* need to make sure there is a name here... */
		lex.type = LEX_CHAR;
		lex.value = 'a';
		UnGet(lex);
		Return(1);
	    }
	} else if (GetCharacter('|')) {
	    ;		/* more names coming */
	} else {
	    lex = Get();
	    UnGet(lex);
	    if (lex.type != LEX_END_OF_FILE) {
		    if (!GetEntry0()) {	/* start of an entry */
			fprintf(stderr,
			    "error was in entry for %s in file %s\n",
			    (oldName)? oldName->array:"(unknown)", filename);
		    Return(0);
		}
	    }
	}
	lex = Get();
    }
D 2
#if !defined(msdos)
E 2
I 2
#if !defined(MSDOS)
E 2
    fprintf(stderr, "Unable to find entry for %s in file %s\n", keybdPointer,
		    filename);
D 2
#endif	/* !defined(msdos) */
E 2
I 2
#endif	/* !defined(MSDOS) */
E 2
    Return(0);
}

char *
strsave(string)
char *string;
{
    char *p;
    extern char *malloc();

    p = malloc(strlen(string)+1);
    if (p != 0) {
	strcpy(p, string);
    }
    return(p);
}


/*
 * InitControl - our interface to the outside.  What we should
 *  do is figure out keyboard (or terminal) type, set up file pointer
 *  (or string pointer), etc.
 */

state *
D 6
InitControl(keybdPointer, pickyarg)
E 6
I 6
InitControl(keybdPointer, pickyarg, translator)
E 6
char	*keybdPointer;
int	pickyarg;		/* Should we be picky? */
I 6
int	(*translator)();	/* Translates ascii string to integer */
E 6
{
    extern char *getenv();
    int GotIt;

    picky = pickyarg;
I 6
    GetTc = translator;
E 6

    if (keybdPointer == 0) {
        keybdPointer = getenv("KEYBD");
    }
    if (keybdPointer == 0) {
       keybdPointer = getenv("TERM");
    }

		    /*
		     * Some environments have getenv() return
		     * out of a static area.  So, save the keyboard name.
		     */
    if (keybdPointer) {
        keybdPointer = strsave(keybdPointer);
    }
    environPointer = getenv("MAP3270");
    if (environPointer
	    && (environPointer[0] != '/')
D 2
#if	defined(msdos)
E 2
I 2
#if	defined(MSDOS)
E 2
	    && (environPointer[0] != '\\')
D 2
#endif	defined(msdos)
E 2
I 2
#endif	/* defined(MSDOS) */
E 2
	    && (strncmp(keybdPointer, environPointer,
			strlen(keybdPointer) != 0)
		|| (environPointer[strlen(keybdPointer)] != '{'))) /* } */
    {
	environPointer = 0;
    }

    if ((!environPointer)
D 2
#if	defined(msdos)
E 2
I 2
#if	defined(MSDOS)
E 2
		|| (*environPointer == '\\')
D 2
#endif	/* defined(msdos) */
E 2
I 2
#endif	/* defined(MSDOS) */
E 2
		|| (*environPointer == '/')) {
	usePointer = 0;
	GotIt = 0;
	if (!keybdPointer) {
D 2
#if !defined(msdos)
E 2
I 2
#if !defined(MSDOS)
E 2
	    fprintf(stderr, "%s%s%s%s",
		"Neither the KEYBD environment variable nor the TERM ",
		"environment variable\n(one of which is needed to determine ",
		"the type of keyboard you are using)\n",
		"is set.  To set it, say 'setenv KEYBD <type>'\n");
D 2
#endif	/* !defined(msdos) */
E 2
I 2
#endif	/* !defined(MSDOS) */
E 2
	} else {
	    if (environPointer) {
		GotIt = Position(environPointer, keybdPointer);
	    }
	    if (!GotIt) {
		GotIt = Position("/etc/map3270", keybdPointer);
	    }
	}
	if (!GotIt) {
	    if (environPointer) {
		GotIt = Position(environPointer, "unknown");
	    }
	    if (!GotIt) {
		GotIt = Position("/etc/map3270", keybdPointer);
	    }
	}
	if (!GotIt) {
D 2
#if !defined(msdos)
E 2
I 2
#if !defined(MSDOS)
E 2
	    fprintf(stderr, "Using default key mappings.\n");
D 2
#endif	/* !defined(msdos) */
E 2
I 2
#endif	/* !defined(MSDOS) */
E 2
D 4
	    environPointer = keys3a;	/* use incore table */
E 4
	    usePointer = 1;		/* flag use of non-file */
I 4
	    whichkey = keysgeneric;
	    environPointer = *whichkey;	/* use default table */
E 4
	}
    } else {
	usePointer = 1;
    }
    (void) GetEntry();
    return(firstentry.address);
}
E 1
