h24146
s 00011/00006/00327
d D 5.6 88/06/29 19:40:50 bostic 7 6
c install approved copyright notice
e
s 00012/00014/00321
d D 5.5 88/03/22 17:31:41 bostic 6 5
c add Berkeley and University of Illinois specific copyright
e
s 00003/00003/00332
d D 5.4 88/01/02 23:59:56 bostic 5 4
c remove trailing semi-colons from include lines; no "+ ="; for ANSI C
e
s 00000/00000/00335
d D 5.3 85/09/08 15:41:32 mckusick 4 3
c update on Sun stuff by Chris Torek
e
s 00229/00308/00106
d D 5.2 85/08/28 13:47:55 mckusick 3 2
c kernel normal form (from sun!shannon)
e
s 00009/00001/00405
d D 5.1 85/06/04 13:36:37 dist 2 1
c Add copyright
e
s 00406/00000/00000
d D 4.1 82/10/21 23:58:34 mckusick 1 0
c date and time created 82/10/21 23:58:34 by mckusick
e
u
U
t
T
I 1
D 2
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * Copyright (c) 1976 Board of Trustees of the University of Illinois.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley and the University of
 * Illinois at Urbana.  The name of either University may not be used
 * to endorse or promote products derived from this software without
 * specific prior written permission. This software is provided
 * ``as is'' without express or implied warranty.
E 7
I 7
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley and the University
 * of Illinois, Urbana.  The name of either
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
E 2

D 3
/*
E 3
I 3
D 6
/*-
 *
 *			  Copyright (C) 1976
 *				by the
 *			  Board of Trustees
 *				of the
 *			University of Illinois
 *
 *			 All rights reserved
 *
 *
E 6
I 6
/*
E 6
 * FILE NAME:
 *	parse.c
 *
 * PURPOSE:
 *	Contains the routines which keep track of the parse stack.
 *
 * GLOBALS:
 *	ps.p_stack =	The parse stack, set by both routines
 *	ps.il =		Stack of indentation levels, set by parse
 *	ps.cstk =		Stack of case statement indentation levels, set by parse
 *	ps.tos =		Pointer to top of stack, set by both routines.
 *
 * FUNCTIONS:
 *	parse
 *	reduce
 */
/*-
 * Copyright (C) 1976 by the Board of Trustees of the University of Illinois 
 *
 * All rights reserved 
 *
 *
 * NAME: parse 
 *
 * FUNCTION: Parse is given one input which is a "maxi token" just scanned
 * from input.  Maxi tokens are signifigant constructs such as else, {,
 * do, if (...), etc.  Parse works with reduce to maintain a parse stack
 * of these constructs.  Parse is responsible for the "shift" portion of
 * the parse algorithm, and reduce handles the "reduce" portion. 
 *
 * HISTORY: initial coding 	November 1976	D A Willcox of CAC 
 *
 */
E 3

D 3
			  Copyright (C) 1976
				by the
			  Board of Trustees
				of the
			University of Illinois

			 All rights reserved


FILE NAME:
	parse.c

PURPOSE:
	Contains the routines which keep track of the parse stack.

GLOBALS:
	p_stack =	The parse stack, set by both routines
	il =		Stack of indentation levels, set by parse
	cstk =		Stack of case statement indentation levels, set by parse
	tos =		Pointer to top of stack, set by both routines.

FUNCTIONS:
	parse
	reduce
*/
/*

			  Copyright (C) 1976
				by the
			  Board of Trustees
				of the
			University of Illinois

			 All rights reserved


NAME:
	parse

FUNCTION:
	Parse is given one input which is a "maxi token" just scanned from
	input.  Maxi tokens are signifigant constructs such as else, {, do,
	if (...), etc.  Parse works with reduce to maintain a parse stack
	of these constructs.  Parse is responsible for the "shift" portion
	of the parse algorithm, and reduce handles the "reduce" portion.

ALGORITHM:
	1) If there is "ifstmt" on the stack and input is anything other than
	   an else, then change the top of stack (TOS) to <stmt>.  Do a reduce.
	2) Use a switch statement to implement the following shift operations:

	   TOS___		Input_____		Stack_____		Note____
	decl		decl		nothing
	anything else	decl		decl
	"dostmt"	while (..)			Change TOS to <stmt>
	anything else	while (..)	while
	"ifstmt"	else				Change TOS to "ifelse"
	{ <stmtl>	}				Change { <stmtl> 
								to <stmtl>
			switch (..)	switch
			do		do
			for(..)		for
			;		<stmt>
			{		{ <stmt>

PARAMETERS:
	tk	An integer code for the maxi token scanned

RETURNS:
	Nothing

GLOBALS:
	break_comma =	Set to true when in a declaration but not initialization
	btype_2
	case_ind =
	cstk =
	i_l_follow =
	il =		Stack of indentation levels
	ind_level =
	p_stack =	Stack of token codes
	search_brace =	Set to true if we must look for possibility of moving a
			brace
	tos =		Pointer to top of p_stack, il, and cstk

CALLS:
	printf (lib)
	reduce

CALLED BY:
	main

HISTORY:
	initial coding 	November 1976	D A Willcox of CAC

*/

E 3
D 5
#include "./indent_globs.h";
#include "./indent_codes.h";
E 5
I 5
#include "./indent_globs.h"
#include "./indent_codes.h"
E 5


D 3
int     p_stack[50] = stmt;
 /* this is the parser's stack */
int     il[50];    /* this stack stores indentation levels */
int     cstk[50];  /* used to store case stmt indentation levels */
int     tos = 0;   /* pointer to top of stack */
E 3


D 3
parse (tk)
int     tk;	   /* the code for the construct scanned */
E 3
I 3
parse(tk)
    int         tk;		/* the code for the construct scanned */
E 3
{
D 3
    int     i;
E 3
I 3
    int         i;
E 3

#ifdef debug
D 3
    printf ("%2d - %s\n", tk, token);
E 3
I 3
    printf("%2d - %s\n", tk, token);
E 3
#endif
D 3
    while (p_stack[tos] == ifhead && tk != elselit) {
    /* true if we have an if without an else */
	p_stack[tos] = stmt;   /* apply the if(..) stmt ::= stmt reduction */
	reduce ();	       /* see if this allows any reduction */
E 3
I 3
    while (ps.p_stack[ps.tos] == ifhead && tk != elselit) {
	/* true if we have an if without an else */
	ps.p_stack[ps.tos] = stmt;	/* apply the if(..) stmt ::= stmt
				 * reduction */
	reduce();		/* see if this allows any reduction */
E 3
    }


D 3
    switch (tk) {	       /* go on and figure out what to do with the
			          input */
E 3
I 3
    switch (tk) {		/* go on and figure out what to do with
				 * the input */
E 3

D 3
	case decl: 	       /* scanned a declaration word */
	    search_brace = btype_2;
	/* indicate that following brace should be on same line */
	    if (p_stack[tos] != decl) {
	    /* only put one declaration onto stack */
		break_comma = true;
	    /* while in declaration, newline should be forced after comma */
		p_stack[++tos] = decl;
		il[tos] = i_l_follow;
E 3
I 3
	case decl: 		/* scanned a declaration word */
	    ps.search_brace = btype_2;
	    /* indicate that following brace should be on same line */
	    if (ps.p_stack[ps.tos] != decl) {	/* only put one declaration onto
					 * stack */
		break_comma = true;	/* while in declaration, newline
					 * should be forced after comma */
		ps.p_stack[++ps.tos] = decl;
		ps.il[ps.tos] = ps.i_l_follow;
E 3

D 3
		if (ljust_decl) {
		/* only do if we want left justified declarations */
		    ind_level = 0;
		    for (i = tos - 1; i > 0; --i)
			if (p_stack[i] == decl)
			    ++ind_level;
		/* indentation is number of declaration levels deep we are */
		    i_l_follow = ind_level;
E 3
I 3
		if (ps.ljust_decl) {	/* only do if we want left
					 * justified declarations */
		    ps.ind_level = 0;
		    for (i = ps.tos - 1; i > 0; --i)
			if (ps.p_stack[i] == decl)
			    ++ps.ind_level;	/* indentation is number
						 * of declaration levels
						 * deep we are */
		    ps.i_l_follow = ps.ind_level;
E 3
		}
	    }
	    break;

D 3
	case ifstmt: 	       /* scanned if (...) */
	case dolit: 	       /* 'do' */
	case forstmt: 	       /* for (...) */
	    p_stack[++tos] = tk;
	    il[tos] = ind_level = i_l_follow;
	    ++i_l_follow;      /* subsequent statements should be indented 1 */
	    search_brace = btype_2;
E 3
I 3
	case ifstmt: 		/* scanned if (...) */
	    if (ps.p_stack[ps.tos] == elsehead && ps.else_if)	/* "else if ..." */
		ps.i_l_follow = ps.il[ps.tos];
	case dolit: 		/* 'do' */
	case forstmt: 		/* for (...) */
	    ps.p_stack[++ps.tos] = tk;
	    ps.il[ps.tos] = ps.ind_level = ps.i_l_follow;
	    ++ps.i_l_follow;	/* subsequent statements should be
				 * indented 1 */
	    ps.search_brace = btype_2;
E 3
	    break;

D 3
	case lbrace: 	       /* scanned { */
	    break_comma = false;
	/* don't break comma in an initial list */
	    if (p_stack[tos] == stmt || p_stack[tos] == decl
				     || p_stack[tos] == stmtl)
		++i_l_follow;  /* it is a random, isolated stmt group or a
			          declaration */
E 3
I 3
	case lbrace: 		/* scanned { */
	    break_comma = false;/* don't break comma in an initial list */
	    if (ps.p_stack[ps.tos] == stmt || ps.p_stack[ps.tos] == decl
		    || ps.p_stack[ps.tos] == stmtl)
		++ps.i_l_follow;	/* it is a random, isolated stmt group or
				 * a declaration */
E 3
	    else {
		if (s_code == e_code) {
D 3
		/* only do this if there is nothing on the line */
		    --ind_level;
		/* it is a group as part of a while, for, etc. */
		    if (p_stack[tos] == swstmt)
			--ind_level;
		/* for a switch, brace should be two levels out from the code 
		*/
E 3
I 3
		    /* only do this if there is nothing on the line */
		    --ps.ind_level;
		    /* it is a group as part of a while, for, etc. */
		    if (ps.p_stack[ps.tos] == swstmt && ps.case_indent)
			--ps.ind_level;
		    /*
		     * for a switch, brace should be two levels out from
		     * the code 
		     */
E 3
		}
	    }

D 3
	    p_stack[++tos] = lbrace;
	    il[tos] = ind_level;
	    p_stack[++tos] = stmt;
	/* allow null stmt between braces */
	    il[tos] = i_l_follow;
E 3
I 3
	    ps.p_stack[++ps.tos] = lbrace;
	    ps.il[ps.tos] = ps.ind_level;
	    ps.p_stack[++ps.tos] = stmt;
	    /* allow null stmt between braces */
	    ps.il[ps.tos] = ps.i_l_follow;
E 3
	    break;

D 3
	case whilestmt:        /* scanned while (...) */
	    if (p_stack[tos] == dohead) {
	    /* it is matched with do stmt */
		ind_level = i_l_follow = il[tos];
		p_stack[++tos] = whilestmt;
		il[tos] = ind_level = i_l_follow;
E 3
I 3
	case whilestmt: 	/* scanned while (...) */
	    if (ps.p_stack[ps.tos] == dohead) {
		/* it is matched with do stmt */
		ps.ind_level = ps.i_l_follow = ps.il[ps.tos];
		ps.p_stack[++ps.tos] = whilestmt;
		ps.il[ps.tos] = ps.ind_level = ps.i_l_follow;
E 3
	    }
D 3
	    else {	       /* it is a while loop */
		p_stack[++tos] = whilestmt;
		il[tos] = i_l_follow;
		++i_l_follow;
		search_brace = btype_2;
E 3
I 3
	    else {		/* it is a while loop */
		ps.p_stack[++ps.tos] = whilestmt;
		ps.il[ps.tos] = ps.i_l_follow;
		++ps.i_l_follow;
		ps.search_brace = btype_2;
E 3
	    }

	    break;

D 3
	case elselit: 	       /* scanned an else */
E 3
I 3
	case elselit: 		/* scanned an else */
E 3

D 3
	    if (p_stack[tos] != ifhead) {
		printf ("%d: Unmatched else\n", line_no);
	    }
E 3
I 3
	    if (ps.p_stack[ps.tos] != ifhead)
		diag(1,"Unmatched 'else'");
E 3
	    else {
D 3
		ind_level = il[tos];
	    /* indentation for else should be same as for if */
		i_l_follow = ind_level + 1;
	    /* everything following should be in 1 level */
		p_stack[tos] = elsehead;
	    /* remember if with else */
		search_brace = btype_2;
E 3
I 3
		ps.ind_level = ps.il[ps.tos];		/* indentation for else should be same as for if */
		ps.i_l_follow = ps.ind_level + 1;	/* everything following should be in 1 level */
		ps.p_stack[ps.tos] = elsehead;
		/* remember if with else */
		ps.search_brace = btype_2;
E 3
	    }

	    break;

D 3
	case rbrace: 	       /* scanned a } */
	/* stack should have <lbrace> <stmt> or <lbrace> <stmtl> */
	    if (p_stack[tos - 1] == lbrace) {
		ind_level = i_l_follow = il[--tos];
		p_stack[tos] = stmt;
E 3
I 3
	case rbrace: 		/* scanned a } */
	    /* stack should have <lbrace> <stmt> or <lbrace> <stmtl> */
	    if (ps.p_stack[ps.tos - 1] == lbrace) {
		ps.ind_level = ps.i_l_follow = ps.il[--ps.tos];
		ps.p_stack[ps.tos] = stmt;
E 3
	    }
D 3
	    else {
		printf ("%d: Stmt nesting error\n", line_no);
	    }

E 3
I 3
	    else
		diag(1,"Stmt nesting error.");
E 3
	    break;

D 3
	case swstmt: 	       /* had switch (...) */
	    p_stack[++tos] = swstmt;
	    cstk[tos] = case_ind;
	/* save current case indent level */
	    il[tos] = i_l_follow;
	    case_ind = i_l_follow + 1;
	/* cases should be one level down from switch */
	    i_l_follow + = 2;  /* statements should be two levels in */
	    search_brace = btype_2;
E 3
I 3
	case swstmt: 		/* had switch (...) */
	    ps.p_stack[++ps.tos] = swstmt;
	    ps.cstk[ps.tos] = case_ind;
	    /* save current case indent level */
	    ps.il[ps.tos] = ps.i_l_follow;
	    case_ind = ps.i_l_follow + ps.case_indent;	/* cases should be one
							 * level down from
							 * switch */
D 5
	    ps.i_l_follow + = ps.case_indent + 1;	/* statements should be
E 5
I 5
	    ps.i_l_follow += ps.case_indent + 1;	/* statements should be
E 5
						 * two levels in */
	    ps.search_brace = btype_2;
E 3
	    break;

D 3
	case semicolon:        /* this indicates a simple stmt */
	    break_comma = false;
	/* turn off flag to break after commas in a declaration */
	    p_stack[++tos] = stmt;
	    il[tos] = ind_level;
E 3
I 3
	case semicolon: 	/* this indicates a simple stmt */
	    break_comma = false;/* turn off flag to break after commas in
				 * a declaration */
	    ps.p_stack[++ps.tos] = stmt;
	    ps.il[ps.tos] = ps.ind_level;
E 3
	    break;

D 3
	default: 	       /* this is an error */
	    printf ("%d: Unknown code to parser - %d\n", line_no, tk);
E 3
I 3
	default: 		/* this is an error */
	    diag(1,"Unknown code to parser");
E 3
	    return;


D 3
    }			       /* end of switch */
E 3
I 3
    }				/* end of switch */
E 3

D 3
    reduce ();		       /* see if any reduction can be done */
E 3
I 3
    reduce();			/* see if any reduction can be done */
E 3
#ifdef debug
D 3
    for (i = 1; i <= tos; ++i)
	printf ("(%d %d)", p_stack[i], il[i]);
    printf ("\n");
E 3
I 3
    for (i = 1; i <= ps.tos; ++i)
	printf("(%d %d)", ps.p_stack[i], ps.il[i]);
    printf("\n");
E 3
#endif
    return;
}
D 3
/*

			  Copyright (C) 1976
				by the
			  Board of Trustees
				of the
			University of Illinois

			 All rights reserved


NAME:
	reduce

FUNCTION:
	Implements the reduce part of the parsing algorithm

ALGORITHM:
	The following reductions are done.  Reductions are repeated until no
	more are possible.

	Old___ TOS___		New___ TOS___
	<stmt> <stmt>	<stmtl>
	<stmtl> <stmt>	<stmtl>
	do <stmt>	"dostmt"
	if <stmt>	"ifstmt"
	switch <stmt>	<stmt>
	decl <stmt>	<stmt>
	"ifelse" <stmt>	<stmt>
	for <stmt>	<stmt>
	while <stmt>	<stmt>
	"dostmt" while	<stmt>

	On each reduction, i_l_follow (the indentation for the following line)
	is set to the indentation level associated with the old TOS.

PARAMETERS:
	None

RETURNS:
	Nothing

GLOBALS:
	cstk
	i_l_follow =
	il
	p_stack =
	tos =

CALLS:
	None

CALLED BY:
	parse

HISTORY:
	initial coding 	November 1976	D A Willcox of CAC

*/
E 3
I 3
/* 
 * Copyright (C) 1976 by the Board of Trustees of the University of Illinois 
 *
 * All rights reserved 
 *
 *
 * NAME: reduce 
 *
 * FUNCTION: Implements the reduce part of the parsing algorithm 
 *
 * ALGORITHM: The following reductions are done.  Reductions are repeated
 * until no more are possible. 
 *
 * Old TOS		New TOS <stmt> <stmt>	<stmtl> <stmtl> <stmt>	<stmtl> do
 * <stmt>	"dostmt" if <stmt>	"ifstmt" switch <stmt>	<stmt>
 * decl <stmt>	<stmt> "ifelse" <stmt>	<stmt> for <stmt>	<stmt>
 * while <stmt>	<stmt> "dostmt" while	<stmt> 
 *
 * On each reduction, ps.i_l_follow (the indentation for the following line) is
 * set to the indentation level associated with the old TOS. 
 *
 * PARAMETERS: None 
 *
 * RETURNS: Nothing 
 *
 * GLOBALS: ps.cstk ps.i_l_follow = ps.il ps.p_stack = ps.tos = 
 *
 * CALLS: None 
 *
 * CALLED BY: parse 
 *
 * HISTORY: initial coding 	November 1976	D A Willcox of CAC 
 *
 */
E 3
/*----------------------------------------------*\
D 3
|   REDUCTION PHASE
E 3
I 3
 * |   REDUCTION PHASE
E 3
\*----------------------------------------------*/
D 3
reduce () {
E 3
I 3
reduce() {
E 3

D 3
    register int    i;
 /* local looping variable */
E 3
I 3
    register int i;
E 3

D 3
    for (;;) {		       /* keep looping until there is nothing left to
			          reduce */
E 3
I 3
    for (;;) {			/* keep looping until there is nothing
				 * left to reduce */
E 3

D 3
	switch (p_stack[tos]) {
E 3
I 3
	switch (ps.p_stack[ps.tos]) {
E 3

	    case stmt: 
D 3
		switch (p_stack[tos - 1]) {
E 3
I 3
		switch (ps.p_stack[ps.tos - 1]) {
E 3

		    case stmt: 
		    case stmtl: 
D 3
		    /* stmtl stmt or stmt stmt */
			p_stack[--tos] = stmtl;
E 3
I 3
			/* stmtl stmt or stmt stmt */
			ps.p_stack[--ps.tos] = stmtl;
E 3
			break;

D 3
		    case dolit: 
		    /* <do> <stmt> */
			p_stack[--tos] = dohead;
			i_l_follow = il[tos];
E 3
I 3
		    case dolit: /* <do> <stmt> */
			ps.p_stack[--ps.tos] = dohead;
			ps.i_l_follow = ps.il[ps.tos];
E 3
			break;

		    case ifstmt: 
D 3
		    /* <if> <stmt> */
			p_stack[--tos] = ifhead;
			for (i = tos - 1;
E 3
I 3
			/* <if> <stmt> */
			ps.p_stack[--ps.tos] = ifhead;
			for (i = ps.tos - 1;
E 3
				(
D 3
				    p_stack[i] != stmt
E 3
I 3
				    ps.p_stack[i] != stmt
E 3
				    &&
D 3
				    p_stack[i] != stmtl
E 3
I 3
				    ps.p_stack[i] != stmtl
E 3
				    &&
D 3
				    p_stack[i] != lbrace
E 3
I 3
				    ps.p_stack[i] != lbrace
E 3
				);
				--i);
D 3
			i_l_follow = il[i];
		    /* for the time being, we will assume that there is no else
		       on this if, and set the indentation level accordingly.
		       If an else is scanned, it will be fixed up later */
E 3
I 3
			ps.i_l_follow = ps.il[i];
			/*
			 * for the time being, we will assume that there
			 * is no else on this if, and set the indentation
			 * level accordingly. If an else is scanned, it
			 * will be fixed up later 
			 */
E 3
			break;

		    case swstmt: 
D 3
		    /* <switch> <stmt> */
			case_ind = cstk[tos - 1];
E 3
I 3
			/* <switch> <stmt> */
			case_ind = ps.cstk[ps.tos - 1];
E 3

D 3
		    case decl: /* finish of a declaration */
E 3
I 3
		    case decl: 	/* finish of a declaration */
E 3
		    case elsehead: 
D 3
		    /* <<if> <stmt> else> <stmt> */
E 3
I 3
			/* <<if> <stmt> else> <stmt> */
E 3
		    case forstmt: 
D 3
		    /* <for> <stmt> */
E 3
I 3
			/* <for> <stmt> */
E 3
		    case whilestmt: 
D 3
		    /* <while> <stmt> */
			p_stack[--tos] = stmt;
			i_l_follow = il[tos];
E 3
I 3
			/* <while> <stmt> */
			ps.p_stack[--ps.tos] = stmt;
			ps.i_l_follow = ps.il[ps.tos];
E 3
			break;

D 3
		    default:   /* <anything else> <stmt> */
E 3
I 3
		    default: 	/* <anything else> <stmt> */
E 3
			return;

D 3
		}	       /* end of section for <stmt> on top of stack */
E 3
I 3
		}		/* end of section for <stmt> on top of
				 * stack */
E 3
		break;

D 3
	    case whilestmt:    /* while (...) on top */
		if (p_stack[tos - 1] == dohead) {
		/* it is termination of a do while */
		    p_stack[--tos] = stmt;
E 3
I 3
	    case whilestmt: 	/* while (...) on top */
		if (ps.p_stack[ps.tos - 1] == dohead) {
		    /* it is termination of a do while */
		    ps.p_stack[--ps.tos] = stmt;
E 3
		    break;
		}
		else
		    return;

D 3
	    default: 	       /* anything else on top */
E 3
I 3
	    default: 		/* anything else on top */
E 3
		return;

D 3
	}		       /* end of big switch */

    }			       /* end of reduction phase for (;;) */
E 3
I 3
	}
    }
E 3
}
E 1
