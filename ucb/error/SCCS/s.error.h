h13196
s 00010/00005/00202
d D 5.3 88/06/29 18:50:48 bostic 8 7
c install approved copyright notice
e
s 00008/00002/00199
d D 5.2 88/06/06 21:51:29 bostic 7 6
c written by Robert Henry; add Berkeley specific header
e
s 00007/00001/00194
d D 5.1 85/05/31 11:43:25 dist 6 5
c Add copyright
e
s 00003/00000/00192
d D 1.5 84/12/11 16:07:01 rrh 5 4
c add decwrl modula2 (this quick&dirty: the ^ pointers mod2 generates
c to point to the point of the error aren't shown in the output of error)
e
s 00002/00003/00190
d D 1.4 83/08/11 22:30:36 sam 4 3
c standardize sccs keyword lines
e
s 00003/00000/00190
d D 1.3 83/06/14 15:41:46 rrh 3 2
c add error category for troff; delimited just like pcc ccom, except
c uses ` and ' instead of "
e
s 00046/00016/00144
d D 1.2 82/01/22 17:56:40 rrh 2 1
c Re proceduralization in errortouch for clarity.
c Added -T (terse option)
c Added typedefs, and changed textual form of structures
c changed argument to vi to begin searching from line 1, instead of line $
e
s 00160/00000/00000
d D 1.1 80/10/16 09:46:29 root 1 0
c date and time created 80/10/16 09:46:29 by root
e
u
U
t
T
I 1
D 4
/*
 *  %W% (Berkeley) %G%
 */
E 4
I 4
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 *
 *	%W% (Berkeley) %G%
 */
E 6

E 4
typedef	int	boolean;
I 2
#define	reg	register
E 2

#define	TRUE	1
#define	FALSE	0
I 2

#define	true	1
#define	false	0
E 2
/*
 *	Descriptors for the various languages we know about.
 *	If you touch these, also touch lang_table
 */
#define	INUNKNOWN	0
#define	INCPP	1
#define	INCC	2
#define	INAS	3
#define	INLD	4
#define	INLINT	5
#define	INF77	6
#define	INPI	7
#define	INPC	8
#define	INFRANZ	9
#define	INLISP	10
#define	INVAXIMA	11
#define	INRATFOR	12
#define	INLEX	13
#define	INYACC	14
#define	INAPL	15
#define	INMAKE	16
#define	INRI	17
I 3
#define	INTROFF	18
I 5
#define	INMOD2	19
E 5
E 3

extern	int	language;
/*
 *	We analyze each line in the error message file, and
 *	attempt to categorize it by type, as well as language.
 *	Here are the type descriptors.
 */
typedef	int	Errorclass;

D 2
#define C_FIRST	0		/* first error category */
E 2
I 2
#define	C_FIRST	0		/* first error category */
E 2
#define	C_UNKNOWN	0	/* must be zero */
#define	C_IGNORE	1	/* ignore the message; used for pi */
#define	C_SYNC		2	/* synchronization errors */
#define	C_DISCARD	3	/* touches dangerous files, so discard */
#define	C_NONSPEC	4	/* not specific to any file */
#define	C_THISFILE	5	/* specific to this file, but at no line */
#define	C_NULLED	6	/* refers to special func; so null */
#define	C_TRUE		7	/* fits into true error format */
#define	C_DUPL		8	/* sub class only; duplicated error message */
D 2
#define C_LAST	9		/* last error category */
E 2
I 2
#define	C_LAST	9		/* last error category */
E 2

#define	SORTABLE(x)	(!(NOTSORTABLE(x)))
#define	NOTSORTABLE(x)	(x <= C_NONSPEC)
/*
 *	Resources to count and print out the error categories
 */
extern	char		*class_table[];
extern	int		class_count[];

#define	nunknown	class_count[C_UNKNOWN]
#define	nignore		class_count[C_IGNORE]
D 2
#define nsyncerrors	class_count[C_SYNC]
E 2
I 2
#define	nsyncerrors	class_count[C_SYNC]
E 2
#define	ndiscard	class_count[C_DISCARD]
#define	nnonspec	class_count[C_NONSPEC]
#define	nthisfile	class_count[C_THISFILE]
D 2
#define nnulled		class_count[C_NULLED]
#define ntrue		class_count[C_TRUE]
E 2
I 2
#define	nnulled		class_count[C_NULLED]
#define	ntrue		class_count[C_TRUE]
E 2
#define	ndupl		class_count[C_DUPL]

/* places to put the error complaints */

D 2
#define TOTHEFILE	1	/* touch the file */
E 2
I 2
#define	TOTHEFILE	1	/* touch the file */
E 2
#define	TOSTDOUT	2	/* just print them out (ho-hum) */

FILE	*errorfile;	/* where error file comes from */
FILE	*queryfile;	/* where the query responses from the user come from*/

extern	char	*currentfilename;
extern	char	*processname;
extern	char	*scriptname;

extern	boolean	query;
I 2
extern	boolean	terse;
int	inquire();			/* inquire for yes/no */
/* 
 *	codes for inquire() to return
 */
#define	Q_NO	1			/* 'N' */
#define	Q_no	2			/* 'n' */
#define	Q_YES	3			/* 'Y' */
#define	Q_yes	4			/* 'y' */

int	probethisfile();
E 2
/*
I 2
 *	codes for probethisfile to return
 */
#define	F_NOTEXIST	1
#define	F_NOTREAD	2
#define	F_NOTWRITE	3
#define	F_TOUCHIT	4

/*
E 2
 *	Describes attributes about a language
 */
struct lang_desc{
	char	*lang_name;
	char	*lang_incomment;	/* one of the following defines */
	char	*lang_outcomment;	/* one of the following defines */
};
extern struct lang_desc lang_table[];

#define	CINCOMMENT	"/*###"
#define	COUTCOMMENT	"%%%*/\n"
#define	FINCOMMENT	"C###"
#define	FOUTCOMMENT	"%%%\n"
#define	NEWLINE		"%%%\n"
#define	PIINCOMMENT	"(*###"
#define	PIOUTCOMMENT	"%%%*)\n"
#define	LISPINCOMMENT	";###"
#define	ASINCOMMENT	"####"
D 2
#define RIINCOMMENT	CINCOMMENT
E 2
I 2
#define	RIINCOMMENT	CINCOMMENT
E 2
#define	RIOUTCOMMENT	COUTCOMMENT
I 3
#define	TROFFINCOMMENT	".\\\"###"
#define	TROFFOUTCOMMENT	NEWLINE
I 5
#define	MOD2INCOMMENT	"(*###"
#define	MOD2OUTCOMMENT	"%%%*)\n"
E 5
E 3
/*
 *	Defines and resources for determing if a given line
 *	is to be discarded because it refers to a file not to
 *	be touched, or if the function reference is to a
 *	function the user doesn't want recorded.
 */
D 2
#define IG_FILE1	"llib-lc"
#define IG_FILE2	"llib-port"
E 2
I 2
#define	IG_FILE1	"llib-lc"
#define	IG_FILE2	"llib-port"
E 2
#define	IG_FILE3	"/usr/lib/llib-lc"
#define	IG_FILE4	"/usr/lib/llib-port"

D 2
#define ERRORNAME	"/.errorrc"
E 2
I 2
#define	ERRORNAME	"/.errorrc"
E 2
int	nignored;
char	**names_ignored;
/* 
 *	Structure definition for a full error
 */
D 2
struct error_desc{
	struct	error_desc *error_next;	/*linked together*/
E 2
I 2
typedef struct edesc	Edesc;
typedef	Edesc	*Eptr;

struct edesc{
	Eptr	error_next;		/*linked together*/
E 2
	int	error_lgtext;		/* how many on the right hand side*/
	char	**error_text;		/* the right hand side proper*/
	Errorclass	error_e_class;	/* error category of this error*/
	Errorclass	error_s_class;	/* sub descriptor of error_e_class*/
	int	error_language;		/* the language for this error*/
	int	error_position;		/* oridinal position */
	int	error_line;		/* discovered line number*/
	int	error_no;		/* sequence number on input */
};
/*
 *	Resources for the true errors
 */
extern	int	nerrors;
D 2
extern	struct	error_desc	*er_head;
extern	struct	error_desc	**errors;	
E 2
I 2
extern	Eptr	er_head;
extern	Eptr	*errors;	
E 2
/*
 *	Resources for each of the files mentioned
 */
extern	int	nfiles;
D 2
extern	struct	error_desc	***files;	/* array of pointers into errors*/
boolean	*touchedfiles;		/* which files we touched */
E 2
I 2
extern	Eptr	**files;	/* array of pointers into errors*/
boolean	*touchedfiles;			/* which files we touched */
E 2
/*
 *	The langauge the compilation is in, as intuited from
 *	the flavor of error messages analyzed.
 */
extern	int	langauge;
extern	char	*currentfilename;
/*
 *	Functional forwards
 */
char	*Calloc();
char	*strsave();
char	*clobberfirst();
char	lastchar();
char	firstchar();
char	next_lastchar();
char	**wordvsplice();
int	wordvcmp();
boolean	persperdexplode();
I 2
/*
 *	Printing hacks
 */
char	*plural(), *verbform();
E 2
E 1
