h30888
s 00011/00006/01098
d D 5.8 88/06/29 19:40:31 bostic 9 8
c install approved copyright notice
e
s 00014/00015/01090
d D 5.7 88/03/22 17:31:27 bostic 8 7
c add Berkeley and University of Illinois specific copyright
e
s 00002/00002/01103
d D 5.6 88/01/02 23:55:46 bostic 7 6
c remove trailing semi-colons from include lines; fix for ANSI C
e
s 00002/00001/01103
d D 5.5 87/04/29 18:25:25 bostic 6 5
c indent exits improperly; bug report 4.2BSD/ucb/197
e
s 00003/00000/01101
d D 5.4 85/09/10 14:41:39 mckusick 5 4
c further updates from Chris Torek
e
s 00060/00275/01041
d D 5.3 85/09/08 15:40:38 mckusick 4 3
c update on Sun stuff by Chris Torek
e
s 01021/00896/00295
d D 5.2 85/08/28 13:46:25 mckusick 3 2
c kernel normal form (from sun!shannon)
e
s 00015/00001/01176
d D 5.1 85/06/04 13:34:51 dist 2 1
c Add copyright
e
s 01177/00000/00000
d D 4.1 82/10/21 23:58:06 mckusick 1 0
c date and time created 82/10/21 23:58:06 by mckusick
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
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * Copyright (c) 1976 Board of Trustees of the University of Illinois.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley and the University of
 * Illinois at Urbana.  The name of either University may not be used
 * to endorse or promote products derived from this software without
 * specific prior written permission. This software is provided
 * ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
I 8
Copyright (c) 1976 Board of Trustees of the University of Illinois.\n\
E 8
 All rights reserved.\n";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8
E 2

D 3
/*

			  Copyright (C) 1976
				by the
			  Board of Trustees
				of the
			University of Illinois

			 All rights reserved


E 3
I 3
D 8
/*-
  
	Copyright (C) 1976
		by the
	Board of Trustees
		of the
	University of Illinois
  
	All rights reserved
  
  
E 8
I 8
/*
E 8
E 3
NAME:
D 3
	indent main program

E 3
I 3
indent main program
  
E 3
FUNCTION:
D 3
	This is the main program of the indent program.  Indent will take a C
	program source and reformat it into a semi-reasonable form.

E 3
I 3
This is the main program of the indent program.  Indent will take a C
program source and reformat it into a semi-reasonable form.
  
E 3
ALGORITHM:
D 3
	The routine lexi scans tokens and passes them back one at a time to the
	main routine.  The subroutine parse takes care of much of the work of
	figuring indentation level.  
E 3
I 3
The routine lexi scans tokens and passes them back one at a time to the
main routine.  The subroutine parse takes care of much of the work of
figuring indentation level.  
  
1) Call lexi
2) Enter a monster switch statement on the code returned by lexi.  If 
the indentation level for the line yet to be printed should be 
changed, set the variable ps.ind_level.  If the indentation level for
the following line should be changed, set the variable ps.i_l_follow.
E 3

D 3
	1) Call lexi
	2) Enter a monster switch statement on the code returned by lexi.  If 
	   the indentation level for the line yet to be printed should be 
	   changed, set the variable ind_level.  If the indentation level for
	   the following line should be changed, set the variable i_l_follow.

PARAMETERS:
	None

RETURNS:
	Nothing

GLOBALS:
	be_save =
	break_comma
	bp_save =
	btype_2 =
	code_lines
	com_ind =
	com_lines
	dec_nest =
	decl_com_ind =
	decl_on_line =
	i_l_follow =
	in_decl =
	ind_level =
	ind_size =
	ind_stmt =
	last_u_d =
	leave_comma =
	line_no =
	ljust_decl =
	max_col =
	out_coms
	out_lines
	p_l_follow =
	paren_level =
	pcase =
	sc_end =
	unindent_displace =
	use_ff =
	verbose =

CALLS:
	atoi (lib)
	cmp
	creat (lib)
	dump_line
	eqin
	fill_buffer
	lexi
	open (lib)
	parse
	pr_comment
	printf (lib)
	seek (lib)
	time (lib)

CALLED BY:
	No one (main routine)

HISTORY:
	November 1976	D A Willcox of CAC	Initial coding
	12/9/76		D A Willcox of CAC	Fixed defaults for decl_com_ind
						to be 8 less than com_ind if 
						left justifying declarations
	12/9/76		D A Willcox of CAC	Fixed processing of nested
						<c>?<s>:<s> constructs
	1/7/77		D A Willcox of CAC	Added check for overwrite of
						input file
						Added code to handle -br and -bl
						parameters
*/
E 3
I 3
*/
E 3
D 7
#include "indent_globs.h";
#include "indent_codes.h";
E 7
I 7
#include "indent_globs.h"
#include "indent_codes.h"
E 7

D 3
/* #define dolog 1	/* if this define is removed, then the code to
			   produce a log file will be removed */
E 3
I 3
char       *in_name = "Standard Input";	/* will always point to name of
					 * input file */
char       *out_name = "Standard Output";	/* will always point to
						 * name of output file */
char        bakfile[32] = "";
E 3

D 3
struct templ {		       /* this is a template for the list of
			          command line args */
    char   *str;	       /* pointer to string which is a valid
			          command line arg */
    int     code;	       /* code to be used in switch for processing
			          this arg */
};


struct templ    options[] =
{			       /* warning - because of the way that this
			          table is scanned, if one entry is an
			          initial substring of another, then the
			          longer entry should occur first */
    "-cd", 4,
    "-c", 2,
    "-l", 1,
    "-i", 3,
    "-v", 5,
    "-nv", 6,
    "-dj", 7,
    "-d", 13,		       /* unindented comment placement */
    "-ndj", 8,
    "-bc", 10,		       /* break after command in decl */
    "-nbc", 9,		       /* don't break after comma */
    "-br", 14,		       /* put brace on right of stmt */
    "-bl", 15,		       /* put brace on left by itself */
    "-st", 16,		       /* use the standard input and output
				  files */
    0, 0
};


char   *in_name = "Standard Input";
			       /* will always point to name of input file 
			       */
char   *out_name = "Standard Output";
			       /* will always point to name of output file
			          */
char    bakfile[32] = "";

main (argc, argv)
int     argc;
char  **argv;
E 3
I 3
main(argc, argv)
    int         argc;
    char      **argv;
E 3
{
I 6
    extern int	found_err;	/* if any error occurred */
E 6

D 3
    int     dec_ind;	       /* current indentation for declarations */
    int     di_stack[20];      /* a stack of structure indentation levels 
			       */
    int     flushed_nl;	       /* used when buffering up comments to
			          remember that a newline was passed over 
			       */
    int     force_nl;	       /* when true, code must be broken */
    int     hd_type;	       /* used to store type of stmt for if (...),
			          for (...), etc */
    register int    i;	       /* local loop counter */
    int     in_or_st;	       /* Will be true iff there has been a
			          declarator (e.g. int or char) and no
			          left paren since the last semicolon.
			          When true, a { is starting a structure
			          definition or an initialization list */
    register int    j;	       /* local loop counter */
    int     scase;	       /* set to true when we see a case, so we
			          will know what to do with the following
			          colon */
    int     sp_sw;	       /* when true, we are in the expressin of
			          if(...), while(...), etc. */
    int     squest;	       /* when this is positive, we have seen a ?
			          without the matching : in a <c>?<s>:<s>
			          construct */
    register char  *t_ptr;     /* used for copying tokens */
    int     type_code;	       /* the type of token, returned by lexi */
    int     want_blank;	       /* set to true when the following token
			          should be prefixed by a blank. (Said
			          prefixing is ignored in some cases.) */
E 3
I 3
    int         dec_ind;	/* current indentation for declarations */
    int         di_stack[20];	/* a stack of structure indentation levels */
    int         flushed_nl;	/* used when buffering up comments to
				 * remember that a newline was passed over */
    int         force_nl;	/* when true, code must be broken */
    int         hd_type;	/* used to store type of stmt for if
				 * (...), for (...), etc */
    register int i;		/* local loop counter */
    register int j;		/* local loop counter */
    int         scase;		/* set to true when we see a case, so we
				 * will know what to do with the following
				 * colon */
    int         sp_sw;		/* when true, we are in the expressin of
				 * if(...), while(...), etc. */
    int         squest;		/* when this is positive, we have seen a ?
				 * without the matching : in a <c>?<s>:<s>
				 * construct */
    register char *t_ptr;	/* used for copying tokens */
    int         type_code;	/* the type of token, returned by lexi */
E 3

D 3
#ifdef dolog		       /* include declarations needed for log */
    int     log_fid;	       /* fid of log file */
E 3
I 3
    int         last_else = 0;	/* true iff last keyword was an else */
E 3

D 3
    struct logtmpl {	       /* structure of a log entry */
	int     tvec[2];       /* time of execution */
	char    inp;	       /* input fid */
	char    outp;	       /* output fid */
	int     nout;	       /* # output lines */
	int     ncom;	       /* # comments */
	int     wcom;	       /* # lines w/ comments */
	int     wcode;	       /* # lines w/code */
	char    mc;	       /* max line size */
	char    ci;	       /* comment indentation */
	char    inds;	       /* indent size */
	char    dci;	       /* decl comment indentation */
	char    verb;	       /* verbose */
	char    ljus;	       /* left just */
	char    lvcom;	       /* leave commas */
	char    unin;	       /* unindented comment indentation */
	char    uid;	       /* the user id */
	char    bropt;	       /* btype_2 */
	int     reserved[2];
    };
E 3

D 3
    struct logtmpl  logent;
#endif

/*-----------------------------------------------*\
|    INITIALIZATION
E 3
I 3
    /*-----------------------------------------------*\
D 4
|		      INITIALIZATION		      |
E 3
\*-----------------------------------------------*/
E 4
I 4
    |		      INITIALIZATION		      |
    \*-----------------------------------------------*/
E 4


D 3
    combuf[0] = codebuf[0] = labbuf[0] = ' ';
 /* set up code, label, and comment buffers */
E 3
I 3
    ps.p_stack[0] = stmt;	/* this is the parser's stack */
    ps.last_nl = true;		/* this is true if the last thing scanned
				 * was a newline */
    ps.last_token = semicolon;
    combuf[0] = codebuf[0] = labbuf[0] = ' ';	/* set up code, label, and
						 * comment buffers */
E 3
    combuf[1] = codebuf[1] = labbuf[1] = '\0';
I 3
D 4
    ps.else_if = 1;		/* Default else-if special processing to
				 * on */
E 4
E 3
    s_lab = e_lab = labbuf + 1;
    s_code = e_code = codebuf + 1;
    s_com = e_com = combuf + 1;

    buf_ptr = buf_end = in_buffer;
    line_no = 1;
D 3
    had_eof = in_decl = decl_on_line = break_comma = false;
E 3
I 3
    had_eof = ps.in_decl = ps.decl_on_line = break_comma = false;
E 3
    sp_sw = force_nl = false;
D 3
    in_or_st = false;
    bl_line = true;
E 3
I 3
    ps.in_or_st = false;
    ps.bl_line = true;
E 3
    dec_ind = 0;
D 3
    di_stack[dec_nest = 0] = 0;
    want_blank = in_stmt = ind_stmt = false;
E 3
I 3
    di_stack[ps.dec_nest = 0] = 0;
    ps.want_blank = ps.in_stmt = ps.ind_stmt = false;
E 3


D 3
    scase = pcase = false;
E 3
I 3
    scase = ps.pcase = false;
E 3
    squest = 0;
    sc_end = 0;
    bp_save = 0;
    be_save = 0;

D 3
    input = -1;
    output = -1;
    ljust_decl = d_ljust;
E 3
I 3
    output = 0;
E 3



D 3
/*--------------------------------------------------*\
E 3
I 3
    /*--------------------------------------------------*\
E 3
D 4
|   COMMAND LINE SCAN
D 3
\*--------------------------------------------------*/
E 3
I 3
\*--------------------------------------------------
*/
E 4
I 4
    |   COMMAND LINE SCAN
    \*--------------------------------------------------*/
E 4
E 3

D 3
    max_col = d_max_col;       /* set up some default values */
    com_ind = d_com_ind;
    ind_size = d_ind_size;
    verbose = d_verbose;
    decl_com_ind = 0;	       /* if this is not set to some positive
			          value by an arg, we will set this equal
			          to com_ind */
    btype_2 = d_btype_2;
    unindent_displace = d_unindent;
    leave_comma = d_leave_comma;
E 3
I 3
D 4
    max_col = 78;		/* -l78 */
    lineup_to_parens = 1;	/* -lp */
    ps.ljust_decl = 0;		/* -ndj */
    ps.com_ind = 33;		/* -c33 */
    star_comment_cont = 1;	/* -sc */
    ps.ind_size = 8;		/* -i8 */
    verbose = 0;
    ps.decl_indent = 16;	/* -di16 */
    ps.indent_parameters = 1;	/* -ip */
    ps.decl_com_ind = 0;	/* if this is not set to some positive
				 * value by an arg, we will set this equal
				 * to ps.com_ind */
    btype_2 = 1;		/* -br */
    cuddle_else = 1;		/* -ce */
    ps.unindent_displace = 0;	/* -d0 */
    ps.case_indent = 0;		/* -cli0 */
    format_col1_comments = 1;	/* -fc1 */
    procnames_start_line = 1;	/* -psl */
    proc_calls_space = 0;	/* -npcs */
    comment_delimiter_on_blankline = 1;	/* -cdb */
    ps.leave_comma = 1;		/* -nbc */
E 4
I 4
    set_defaults();
E 4
E 3

I 4
    /*
     * Unfortunately, we must look for -npro here because the profiles
     * are read before the command line arguments.
     */
E 4
D 3
    set_profile ();
E 3
I 3
    for (i = 1; i < argc; ++i)
	if (strcmp(argv[i], "-npro") == 0)
	    break;
    if (i >= argc)
	set_profile();
E 3

I 4
    input = 0;			/* cancel -st if it was in the profiles, */
    output = 0;			/* as it doesn't make any sense there. */

E 4
    for (i = 1; i < argc; ++i) {
D 3
    /* look thru args (if any) for changes to defaults */
E 3
I 3

	/*
	 * look thru args (if any) for changes to defaults 
	 */
E 3
	if (argv[i][0] != '-') {/* no flag on parameter */
D 3
	    if (input < 0) {   /* we must have the input file */
		in_name = argv[i];	/* remember name of input
					   file */
		input = open (in_name, 0);
		if (input < 0) {	/* check for open error */
		    printf ("Can't open %s\n", argv[i]);
		    exit ();
E 3
I 3
	    if (input == 0) {	/* we must have the input file */
		in_name = argv[i];	/* remember name of input file */
		input = fopen(in_name, "r");
		if (input == 0) {	/* check for open error */
D 4
		    printf("Can't open %s\n", argv[i]);
		    exit();
E 4
I 4
		    fprintf(stderr, "indent: can't open %s\n", argv[i]);
		    exit(1);
E 4
E 3
		}
		continue;
D 3
	    }
	    else
		if (output < 0) {	/* we have the output file */
		    out_name = argv[i];	/* remember name of output file */
		    if (cmp (in_name, out_name) == 0) {	 /* attempt to
					   overwright the file */
			printf ("Input and output files must be different\n");
			exit ();
		    }
		    output = creat (out_name, 0644);
		    if (output < 0) {   /* check for create error */
			printf ("Can't create %s\n", argv[i]);
			exit ();
		    }
		    continue;
E 3
I 3
	    } else if (output == 0) {	/* we have the output file */
		out_name = argv[i];	/* remember name of output file */
		if (strcmp(in_name, out_name) == 0) {	/* attempt to overwrite
							 * the file */
D 4
		    printf("Input and output files must be different\n");
		    exit();
E 4
I 4
		    fprintf(stderr, "indent: input and output files must be different\n");
		    exit(1);
E 4
E 3
		}
I 3
		output = fopen(out_name, "w");
		if (output == 0) {	/* check for create error */
D 4
		    printf("Can't create %s\n", argv[i]);
		    exit();
E 4
I 4
		    fprintf(stderr, "indent: can't create %s\n", argv[i]);
		    exit(1);
E 4
		}
		continue;
	    }
D 4
	    printf("Unknown parameter: %s\n", argv[i]);
	    exit();
E 4
I 4
	    fprintf(stderr, "indent: unknown parameter: %s\n", argv[i]);
	    exit(1);
E 4
	} else
	    set_option(argv[i]);
E 3

D 3
	    printf ("Unknown parameter: %s\n", argv[i]);
	    exit ();
E 3
I 3
    }				/* end of for */
    if (input == 0) {
	printf("Usage: indent file [ outfile ] [ options ]\n");
D 4
	exit();
E 4
I 4
	exit(1);
E 4
    }
    if (output == 0)
	if (troff)
	    output = stdout;
	else {
	    out_name = in_name;
	    bakcopy();
E 3
	}
I 4

    /*
     * Adjust parameters that are out of range, or set defaults if
     * no values were specified.
     */
E 4
D 3
	else
	    set_option (argv[i]);
E 3
I 3
    if (ps.com_ind <= 1)
	ps.com_ind = 2;		/* dont put normal comments before column
				 * 2 */
    if (block_comment_max_col <= 0)
	block_comment_max_col = max_col;
    if (ps.decl_com_ind <= 0)	/* if not specified by user, set this */
D 4
	ps.decl_com_ind = ps.ljust_decl ? (ps.com_ind <= 10 ? 2 : ps.com_ind - 8) : ps.com_ind;
E 4
I 4
	ps.decl_com_ind = ps.ljust_decl ? ps.com_ind - 8 : ps.com_ind;
    if (ps.decl_com_ind <= 1)
	ps.decl_com_ind = 2;
E 4
    if (continuation_indent == 0)
	continuation_indent = ps.ind_size;
    fill_buffer();		/* get first batch of stuff into input
				 * buffer */
E 3

D 3
    }			       /* end of for */
E 3
I 3
    parse(semicolon);
    {
	register char *p = buf_ptr;
	register    col = 1;
E 3

D 3
    if (input < 0) {
	printf ("Usage: indent file [ outfile ] [ options ]\n");
	exit ();
E 3
I 3
	while (1) {
	    if (*p == ' ')
		col++;
	    else if (*p == '\t')
		col = ((col - 1) & ~7) + 9;
	    else
		break;
	    p++;
	};
	if (col > ps.ind_size)
	    ps.ind_level = ps.i_l_follow = col / ps.ind_size;
E 3
    }
D 3
    if (output < 0) {
	out_name = in_name;
	bakcopy ();
E 3
I 3
    if (troff) {
	register char *p = in_name,
	           *beg = in_name;

	while (*p)
	    if (*p++ == '/')
		beg = p;
	fprintf(output, ".Fn \"%s\"\n", beg);
E 3
    }

D 3
    if (com_ind <= 1)
	com_ind = 2;	       /* don't put normal comments before column
			          2 */
E 3
I 3
    /*
     * START OF MAIN LOOP 
     */
E 3

D 3
    if (decl_com_ind <= 0)     /* if not specified by user, set this */
	decl_com_ind = ljust_decl ? (com_ind <= 10 ? 2 : com_ind - 8) : com_ind;
E 3
I 3
    while (1) {			/* this is the main loop.  it will go
				 * until we reach eof */
	int         is_procname;
E 3

D 3
    fill_buffer ();	       /* get first batch of stuff into input
			          buffer */
E 3
I 3
	type_code = lexi();	/* lexi reads one token.  The actual
				 * characters read are stored in "token".
				 * lexi returns a code indicating the type
				 * of token */
	is_procname = ps.procname[0];
E 3

D 3
    parse (semicolon);
/*-----------------------------------------------------
|   START OF MAIN LOOP
\*----------------------------------------------------*/
E 3
I 3
	/*
	 * The following code moves everything following an if (), while
	 * (), else, etc. up to the start of the following stmt to a
	 * buffer.  This allows proper handling of both kinds of brace
	 * placement. 
	 */
E 3

D 3
    while (1) {		       /* this is the main loop.  it will go until
			          we reach eof */
	type_code = lexi ();   /* lexi reads one token.  The actual
			          characters read are stored in "token".
			          lexi returns a code indicating the type
			          of token */

    /* 
     * The following code moves everything following an if (), while (),
     * else, etc. up to the start of the following stmt to a buffer.  This
     * allows proper handling of both kinds of brace placement.
     */

E 3
	flushed_nl = false;
D 3
	while (search_brace) { /* if we scanned an if(), while(), etc., we
			          might need to copy stuff into a buffer 
	*//* we must loop, copying stuff into save_com, until we find the
	   start of the stmt which follows the if, or whatever */
E 3
I 3
	while (ps.search_brace) {	/* if we scanned an if(), while(),
					 * etc., we might need to copy
					 * stuff into a buffer we must
					 * loop, copying stuff into
					 * save_com, until we find the
					 * start of the stmt which follows
					 * the if, or whatever */
E 3
	    switch (type_code) {
D 3
		case newline: 
E 3
I 3
		case newline:
E 3
		    ++line_no;
		    flushed_nl = true;
D 3
		case form_feed: 
		    break;     /* form feeds and newlines found here will
			          be ignored */
E 3
I 3
		case form_feed:
		    break;	/* form feeds and newlines found here will
				 * be ignored */
E 3

D 3
		case lbrace:   /* this is a brace that starts the compound
			          stmt */
		    if (sc_end == 0) {
		    /* ignore buffering if a comment wasn't stored up */
			search_brace = false;
E 3
I 3
		case lbrace:	/* this is a brace that starts the
				 * compound stmt */
		    if (sc_end == 0) {	/* ignore buffering if a comment
					 * wasnt stored up */
			ps.search_brace = false;
E 3
			goto check_type;
		    }
D 3

E 3
		    if (btype_2) {
D 3
			save_com[0] = '{';
		    /* we either want to put the brace right after the if 
		    */
			goto sw_buffer;
		    /* go to common code to get out of this loop */
E 3
I 3
			save_com[0] = '{';	/* we either want to put
						 * the brace right after
						 * the if */
			goto sw_buffer;	/* go to common code to get out of
					 * this loop */
E 3
		    }
I 3
		case comment:	/* we have a comment, so we must copy it
				 * into the buffer */
		    if (!flushed_nl) {
			if (sc_end == 0) {	/* if this is the first
						 * comment, we must set up
						 * the buffer */
			    save_com[0] = save_com[1] = ' ';
			    sc_end = &(save_com[2]);
			} else {
			    *sc_end++ = '\n';	/* add newline between
						 * comments */
			    *sc_end++ = ' ';
			    --line_no;
			}
			*sc_end++ = '/';	/* copy in start of
						 * comment */
			*sc_end++ = '*';
E 3

D 3
		default:       /* it is the start of a normal statment */
		    if (flushed_nl)
			       /* if we flushed a newline, make sure it is
			          put back */
E 3
I 3
			for (;;) {	/* loop until we get to the end of
					 * the comment */
			    *sc_end = *buf_ptr++;
			    if (buf_ptr >= buf_end)
				fill_buffer();

			    if (*sc_end++ == '*' && *buf_ptr == '/')
				break;	/* we are at end of comment */

			    if (sc_end >= &(save_com[sc_size])) {	/* check for temp buffer
									 * overflow */
				diag(1, "Internal buffer overflow - Move big comment from right after if, while, or whatever.");
				fflush(output);
D 4
				exit();
E 4
I 4
				exit(1);
E 4
			    }
			}
			*sc_end++ = '/';	/* add ending slash */
			if (++buf_ptr >= buf_end)	/* get past / in buffer */
			    fill_buffer();
			break;
		    }
		default:	/* it is the start of a normal statment */
		    if (flushed_nl)	/* if we flushed a newline, make
					 * sure it is put back */
E 3
			force_nl = true;
I 3
		    if (type_code == sp_paren && *token == 'i'
			&& last_else && ps.else_if
			|| type_code == sp_nparen && *token == 'e'
			&& e_code != s_code && e_code[-1] == '}')
			force_nl = false;
E 3

D 3
		    if (sc_end == 0) {
		    /* ignore buffering if comment wasn't saved up */
			search_brace = false;
E 3
I 3
		    if (sc_end == 0) {	/* ignore buffering if comment
					 * wasnt saved up */
			ps.search_brace = false;
E 3
			goto check_type;
		    }
D 3

		    if (force_nl) {
		    /* if we should insert a nl here, put it into the
		       buffer */
E 3
I 3
		    if (force_nl) {	/* if we should insert a nl here,
					 * put it into the buffer */
E 3
			force_nl = false;
D 3
			--line_no;
		    /* this will be re-increased when the nl is read from
		       the buffer */
E 3
I 3
			--line_no;	/* this will be re-increased when
					 * the nl is read from the buffer */
E 3
			*sc_end++ = '\n';
			*sc_end++ = ' ';
D 3
			if (verbose && !flushed_nl)
			       /* print error msg if the line was not
			          already broken */
			    printf ("%d: Line broken\n", line_no);
E 3
I 3
			if (verbose && !flushed_nl)	/* print error msg if
							 * the line was not
							 * already broken */
			    diag(0, "Line broken");
E 3
			flushed_nl = false;
		    }
D 3

E 3
		    for (t_ptr = token; *t_ptr; ++t_ptr)
D 3
			*sc_end++ = *t_ptr;
		/* copy token into temp buffer */
E 3
I 3
			*sc_end++ = *t_ptr;	/* copy token into temp
						 * buffer */
E 3

D 3
	    sw_buffer: 
		    search_brace = false;
		/* stop looking for start of stmt */
		    bp_save = buf_ptr;
		/* save current input buffer */
E 3
I 3
	    sw_buffer:
		    ps.search_brace = false;	/* stop looking for start
						 * of stmt */
		    bp_save = buf_ptr;	/* save current input buffer */
E 3
		    be_save = buf_end;
D 3
		    buf_ptr = save_com;
		/* fix so that subsequent calls to lexi will take tokens
		   out of save_com */
		    *sc_end++ = ' ';
		/* add trailing blank, just in case */
E 3
I 3
		    buf_ptr = save_com;	/* fix so that subsequent calls to
					 * lexi will take tokens out of
					 * save_com */
		    *sc_end++ = ' ';	/* add trailing blank, just in
					 * case */
E 3
		    buf_end = sc_end;
		    sc_end = 0;
		    break;
D 3

		case comment:  /* we have a comment, so we must copy it
			          into the buffer */
		    if (sc_end == 0) {
		    /* if this is the first comment, we must set up the
		       buffer */
			save_com[0] = save_com[1] = ' ';
			sc_end = &(save_com[2]);
		    }
		    else {
			*sc_end++ = '\n';
		    /* add newline between comments */
			*sc_end++ = ' ';
			--line_no;
		    }

		    *sc_end++ = '/';
		/* copy in start of comment */
		    *sc_end++ = '*';

		    for (;;) { /* loop until we get to the end of the
			          comment */
			*sc_end = *buf_ptr++;
			if (buf_ptr >= buf_end)
			    fill_buffer ();

			if (*sc_end++ == '*' && *buf_ptr == '/')
			    break;
		    /* we are at end of comment */

			if (sc_end >= &(save_com[sc_size])) {
			/* check for temp buffer overflow */
			    printf ("%d: Internal buffer overflow.\n",
				    line_no);
			    printf ("Move big comment from right after if,\
 while, or whatever.\n");
			    exit ();
			}
		    }

		    *sc_end++ = '/';
		/* add ending slash */
		    if (++buf_ptr >= buf_end)/* get past / in buffer */
			fill_buffer ();
		    break;
	    }		       /* end of switch */

	    if (type_code != 0)/* we must make this check, just in case
			          there was an unexpected EOF */
		type_code = lexi ();
	/* read another token */
	}		       /* end of while (serach_brace) */
check_type: 

	if (type_code == 0) {  /* we got eof */
E 3
I 3
	    }			/* end of switch */
	    if (type_code != 0)	/* we must make this check, just in case
				 * there was an unexpected EOF */
		type_code = lexi();	/* read another token */
	    is_procname = ps.procname[0];
	}			/* end of while (serach_brace) */
	last_else = 0;
check_type:
	if (type_code == 0) {	/* we got eof */
E 3
	    if (s_lab != e_lab || s_code != e_code
D 3
		    || s_com != e_com)/* must dump end of line */
		dump_line ();
	    if (i_l_follow != 0)/* check for balanced braces */
		printf ("%d too few }'s\n", i_l_follow);
E 3
I 3
		|| s_com != e_com)	/* must dump end of line */
		dump_line();
	    if (ps.tos > 1)	/* check for balanced braces */
		diag(1, "Stuff missing from end of file.");
E 3

D 3
#ifdef dolog		       /* only include this stuff if we want to
			          keep a log */
	    log_fid = open ("/mnt/net/willcox/indent/indent_log", 1);
	/* open the log file */
	    if (log_fid >= 0) {
		seek (log_fid, 0, 2);
	    /* point to end of log */
		time (logent.tvec);
	    /* get current time */
		logent.inp = input;
	    /* set up the log entry */
		logent.outp = output;
		logent.nout = out_lines;
		logent.ncom = out_coms;
		logent.wcom = com_lines;
		logent.wcode = code_lines;
		logent.mc = max_col;
		logent.ci = com_ind;
		logent.inds = ind_size;
		logent.dci = decl_com_ind;
		logent.verb = verbose;
		logent.ljus = ljust_decl;
		logent.lvcom = leave_comma;
		logent.unin = unindent_displace;
		logent.uid = getuid ();
		logent.bropt = btype_2;
		write (log_fid, &logent, sizeof logent);
	    }
#endif
E 3
	    if (verbose) {
D 3
		printf ("There were %d output lines and %d comments\n",
			out_lines, out_coms);
		printf ("(Lines with comments)/(Lines with code): %6.3f\n",
			(1.0 * com_lines) / code_lines);
E 3
I 3
		printf("There were %d output lines and %d comments\n",
		       ps.out_lines, ps.out_coms);
		printf("(Lines with comments)/(Lines with code): %6.3f\n",
		       (1.0 * ps.com_lines) / code_lines);
E 3
	    }
D 3

	    exit ();
E 3
I 3
	    fflush(output);
D 4
	    exit();
E 4
I 4
D 6
	    exit(ps.tos <= 1);
E 6
I 6
	    exit(ps.tos > 1 || found_err);
E 6
E 4
E 3
	}
D 3

E 3
	if (
D 3
		(type_code != comment) &&
		(type_code != newline) &&
		(type_code != preesc) &&
		(type_code != form_feed)) {
E 3
I 3
	    (type_code != comment) &&
	    (type_code != newline) &&
	    (type_code != preesc) &&
	    (type_code != form_feed)) {
E 3
	    if (
D 3
		    force_nl
		    &&
		    (type_code != semicolon) &&
		    (
			type_code != lbrace
			||
			!btype_2
		    )) {       /* we should force a broken line here */
E 3
I 3
		force_nl
		&&
		(type_code != semicolon) &&
		(
		 type_code != lbrace
		 ||
		 !btype_2
		 )) {		/* we should force a broken line here */
E 3
		if (verbose && !flushed_nl)
D 3
		    printf ("%d: Line broken\n", line_no);
E 3
I 3
		    diag(0, "Line broken");
E 3
		flushed_nl = false;
D 3
		dump_line ();
		want_blank = false;
	    /* don't insert blank at line start */
E 3
I 3
		dump_line();
		ps.want_blank = false;	/* dont insert blank at line start */
E 3
		force_nl = false;
	    }
D 3

	    in_stmt = true;    /* turn on flag which causes an extra level
			          of indentation. this is turned off by a
			          ; or } */
	    if (s_com != e_com) {
	    /* the turkey has embedded a comment in a line. fix it */
E 3
I 3
	    ps.in_stmt = true;	/* turn on flag which causes an extra
				 * level of indentation. this is turned
				 * off by a ; or '}' */
	    if (s_com != e_com) {	/* the turkey has embedded a
					 * comment in a line. fix it */
E 3
		*e_code++ = ' ';
		for (t_ptr = s_com; *t_ptr; ++t_ptr)
		    *e_code++ = *t_ptr;
		*e_code++ = ' ';
D 3
		*e_code = '\0';/* null terminate code sect */
		want_blank = false;
E 3
I 3
		*e_code = '\0';	/* null terminate code sect */
		ps.want_blank = false;
E 3
		e_com = s_com;
	    }
D 3
	}
	else
	    if (type_code != comment)
			       /* preserve force_nl thru a comment */
		force_nl = false;
    /* cancel forced newline after newline, form feed, etc */
E 3
I 3
	} else if (type_code != comment)	/* preserve force_nl thru
						 * a comment */
	    force_nl = false;
E 3

I 3
	/*
	 * cancel forced newline after newline, form feed, etc 
	 */
E 3


D 3
    /*----------------------------------------------------*\
    |   do switch on type of token scanned
    \*----------------------------------------------------*/
	switch (type_code) {   /* now, decide what to do with the token */
E 3

D 3
	    case form_feed:    /* found a form feed in line */
		use_ff = true; /* a form feed is treated much like a
			          newline */
		dump_line ();
		want_blank = false;
E 3
I 3
	/*----------------------------------------------------*\
D 4
|   do switch on type of token scanned
\*----------------------------------------------------*/
E 4
I 4
	|   do switch on type of token scanned
	\*----------------------------------------------------*/
E 4
	switch (type_code) {	/* now, decide what to do with the token */

	    case form_feed:	/* found a form feed in line */
		ps.use_ff = true;	/* a form feed is treated much
					 * like a newline */
		dump_line();
		ps.want_blank = false;
E 3
		break;

D 3
	    case newline: 
		dump_line ();
		++line_no;     /* keep track of input line number */
		want_blank = false;
E 3
I 3
	    case newline:
		if (ps.last_token != comma || ps.p_l_follow > 0
		    || !ps.leave_comma || !break_comma || s_com != e_com) {
		    dump_line();
		    ps.want_blank = false;
		}
		++line_no;	/* keep track of input line number */
E 3
		break;

D 3
	    case lparen:       /* got a ( or [ */
		++p_l_follow;  /* count parens to make Healy happy */
		if (want_blank && *token != '[')
			       /* don't put space in front of square
			          bracket */
E 3
I 3
	    case lparen:	/* got a '(' or '[' */
		++ps.p_l_follow;/* count parens to make Healy happy */
		if (ps.want_blank && *token != '[' &&
		    (ps.last_token != ident || proc_calls_space
		     || (ps.its_a_keyword && !ps.sizeof_keyword)))
E 3
		    *e_code++ = ' ';
I 3
		if (ps.in_decl && !ps.block_init)
		    if (troff && !ps.dumped_decl_indent) {
			ps.dumped_decl_indent = 1;
			sprintf(e_code, "\\c\n.Du %dp+\200p \"%s\"\n", dec_ind * 7, token);
			e_code += strlen(e_code);
		    } else {
			while ((e_code - s_code) < dec_ind)
			    *e_code++ = ' ';
			*e_code++ = token[0];
		} else
		    *e_code++ = token[0];
		ps.paren_indents[ps.p_l_follow - 1] = e_code - s_code;
		ps.want_blank = false;
		if (ps.in_or_st && *token == '(') {
E 3

D 3
		if (in_decl)
		    while ((e_code - s_code) < dec_ind)
			*e_code++ = ' ';

		*e_code++ = token[0];
		want_blank = false;
		if (in_or_st && *token == '(') {
		/* this is a kluge to make sure that declarations will be
		   aaigned right if proc decl has an explicit type on it,
		   i.e. "int a(x) {..." */
		    parse (semicolon);
		/* I said this was a kluge... */
		    in_or_st = false;
		/* turn off flag for structure decl or initialization */
E 3
I 3
		    /*
		     * this is a kluge to make sure that declarations will
		     * be aligned right if proc decl has an explicit type
		     * on it, i.e. "int a(x) {..." 
		     */
		    parse(semicolon);	/* I said this was a kluge... */
		    ps.in_or_st = false;	/* turn off flag for
						 * structure decl or
						 * initialization */
E 3
		}
D 3

E 3
I 3
		if (ps.sizeof_keyword) ps.sizeof_mask |= 1<<ps.p_l_follow;
E 3
		break;

D 3
	    case rparen:       /* got a ) or ] */
		if (--p_l_follow < 0) {
		    p_l_follow = 0;
		    printf ("%d: Extra %c\n", line_no, *token);
E 3
I 3
	    case rparen:	/* got a ')' or ']' */
		if (ps.cast_mask & (1 << ps.p_l_follow) & ~ps.sizeof_mask) {
		    ps.last_u_d = true;
		    ps.cast_mask &= (1 << ps.p_l_follow) - 1;
E 3
		}
I 3
		ps.sizeof_mask &= (1 << ps.p_l_follow) - 1;
		if (--ps.p_l_follow < 0) {
		    ps.p_l_follow = 0;
		    diag(0, "Extra %c", *token);
		}
		if (e_code == s_code)	/* if the paren starts the line */
		    ps.paren_level = ps.p_l_follow;	/* then indent it */
E 3

D 3
		if (e_code == s_code)/* if the paren starts the line */
		    paren_level = p_l_follow;
	    /*    then indent it */

E 3
		*e_code++ = token[0];
D 3
		want_blank = true;
E 3
I 3
		ps.want_blank = true;
E 3

D 3
		if (sp_sw && (p_l_follow == 0)) {
		/* check for end of if (...), or some such */
E 3
I 3
		if (sp_sw && (ps.p_l_follow == 0)) {	/* check for end of if
							 * (...), or some such */
E 3
		    sp_sw = false;
D 3
		    force_nl = true;
		/* must force newline after if */
		    last_u_d = true;
		/* inform lexi that a following operator is unary */
		    in_stmt = false;
		/* don't use stmt continuation indentation */
E 3
I 3
		    force_nl = true;	/* must force newline after if */
		    ps.last_u_d = true;	/* inform lexi that a following
					 * operator is unary */
		    ps.in_stmt = false;	/* dont use stmt continuation
					 * indentation */
E 3

D 3
		    parse (hd_type);
		/* let parser worry about if, or whatever */
E 3
I 3
		    parse(hd_type);	/* let parser worry about if, or
					 * whatever */
E 3
		}
D 3

		search_brace = btype_2;
	    /* this should insure that constructs such as main(){... and
	       int[]{... have their braces put in the right place */
E 3
I 3
		ps.search_brace = btype_2;	/* this should insure that
						 * constructs such as
						 * main(){...} and
						 * int[]{...} have their
						 * braces put in the right
						 * place */
E 3
		break;

D 3
	    case unary_op:     /* this could be any unary operation */
		if (want_blank)
E 3
I 3
	    case unary_op:	/* this could be any unary operation */
		if (ps.want_blank)
E 3
		    *e_code++ = ' ';

D 3
		if (in_decl) { /* if this is a unary op in a *//*
			          declaration, we should indent this token
			          */
		    for (i = 0; token[i]; ++i);
		/* find length of token */
		    while ((e_code - s_code) < (dec_ind - i))
			*e_code++ = ' ';
		/* pad it */
		}
E 3
I 3
		if (troff && !ps.dumped_decl_indent && ps.in_decl) {
		    sprintf(e_code, "\\c\n.Du %dp+\200p \"%s\"\n", dec_ind * 7, token);
		    ps.dumped_decl_indent = 1;
		    e_code += strlen(e_code);
		} else {
		    char       *res = token;
E 3

D 3
		for (t_ptr = token; *t_ptr; ++t_ptr)
		    *e_code++ = *t_ptr;
	    /* move the token to buffer */
		want_blank = false;
E 3
I 3
		    if (ps.in_decl && !ps.block_init) {	/* if this is a unary op
							 * in a declaration, we
							 * should indent this
							 * token */
			for (i = 0; token[i]; ++i);	/* find length of token */
			while ((e_code - s_code) < (dec_ind - i))
			    *e_code++ = ' ';	/* pad it */
		    }
		    if (troff && token[0] == '-' && token[1] == '>')
			res = "\\(->";
		    for (t_ptr = res; *t_ptr; ++t_ptr)
			*e_code++ = *t_ptr;
		}
		ps.want_blank = false;
E 3
		break;

D 3
	    case binary_op:    /* any binary operation */
	do_binary: 
		if (want_blank)
E 3
I 3
	    case binary_op:	/* any binary operation */
	do_binary:
		if (ps.want_blank)
E 3
		    *e_code++ = ' ';
D 3
		for (t_ptr = token; *t_ptr; ++t_ptr)
		    *e_code++ = *t_ptr;
	    /* move the operator */
		want_blank = true;
E 3
I 3
		{
		    char       *res = token;

		    if (troff)
			switch (token[0]) {
			    case '<':
				if (token[1] == '=')
				    res = "\\(<=";
				break;
			    case '>':
				if (token[1] == '=')
				    res = "\\(>=";
				break;
			    case '!':
				if (token[1] == '=')
				    res = "\\(!=";
				break;
			    case '|':
				if (token[1] == '|')
				    res = "\\(br\\(br";
				else if (token[1] == 0)
				    res = "\\(br";
				break;
I 5
			    case '-':
				if (token[1] == '>')
				    res = "\\(->";
E 5
			}
		    for (t_ptr = res; *t_ptr; ++t_ptr)
			*e_code++ = *t_ptr;	/* move the operator */
		}
		ps.want_blank = true;
E 3
		break;

D 3
	    case postop:       /* got a trailing ++ or -- */
E 3
I 3
	    case postop:	/* got a trailing ++ or -- */
E 3
		*e_code++ = token[0];
		*e_code++ = token[1];
D 3
		want_blank = true;
E 3
I 3
		ps.want_blank = true;
E 3
		break;

D 3
	    case question:     /* got a ? */
		squest++;      /* this will be used when a later colon
			          appears so we can distinguish the
			          <c>?<n>:<n> construct */
		if (want_blank)
E 3
I 3
	    case question:	/* got a ? */
		squest++;	/* this will be used when a later colon
				 * appears so we can distinguish the
				 * <c>?<n>:<n> construct */
		if (ps.want_blank)
E 3
		    *e_code++ = ' ';
		*e_code++ = '?';
D 3
		want_blank = true;
E 3
I 3
		ps.want_blank = true;
E 3
		break;

D 3
	    case casestmt:     /* got word 'case' or 'default' */
		scase = true;  /* so we can process the later colon
			          properly */
		if (want_blank)
		    *e_code++ = ' ';
		for (t_ptr = token; *t_ptr; ++t_ptr)
		    *e_code++ = *t_ptr;
		want_blank = true;
		break;
E 3
I 3
	    case casestmt:	/* got word 'case' or 'default' */
		scase = true;	/* so we can process the later colon
				 * properly */
		goto copy_id;
E 3

D 3
	    case colon:        /* got a ':' */
		if (squest > 0) {
		/* it is part of the <c>?<n>: <n> construct */
E 3
I 3
	    case colon:	/* got a ':' */
		if (squest > 0) {	/* it is part of the <c>?<n>: <n>
					 * construct */
E 3
		    --squest;
D 3
		    if (want_blank)
E 3
I 3
		    if (ps.want_blank)
E 3
			*e_code++ = ' ';
		    *e_code++ = ':';
D 3
		    want_blank = true;
E 3
I 3
		    ps.want_blank = true;
E 3
		    break;
		}
D 3

		in_stmt = false;
	    /* seeing a label does not imply we are in a stmt */
E 3
I 3
		if (ps.in_decl) {
		    *e_code++ = ':';
		    ps.want_blank = false;
		    break;
		}
		ps.in_stmt = false;	/* seeing a label does not imply
					 * we are in a stmt */
E 3
		for (t_ptr = s_code; *t_ptr; ++t_ptr)
D 3
		    *e_lab++ = *t_ptr;
	    /* turn everything so far into a label */
E 3
I 3
		    *e_lab++ = *t_ptr;	/* turn everything so far into a
					 * label */
E 3
		e_code = s_code;
		*e_lab++ = ':';
		*e_lab++ = ' ';
		*e_lab = '\0';

D 3
		force_nl = pcase = scase;
	    /* pcase will be used by dump_line to decide how to indent the
	       label. force_nl will force a case n: to be on a line by
	       itself */
E 3
I 3
		force_nl = ps.pcase = scase;	/* ps.pcase will be used
						 * by dump_line to decide
						 * how to indent the
						 * label. force_nl will
						 * force a case n: to be
						 * on a line by itself */
E 3
		scase = false;
D 3
		want_blank = false;
E 3
I 3
		ps.want_blank = false;
E 3
		break;

D 3
	    case semicolon:    /* got a ';' */
		in_or_st = false;
	    /* we are not in an initialization or structure declaration */
		scase = false; /* these will only need resetting in a
			          error */
E 3
I 3
	    case semicolon:	/* got a ';' */
		ps.in_or_st = false;	/* we are not in an initialization
					 * or structure declaration */
		scase = false;	/* these will only need resetting in a
				 * error */
E 3
		squest = 0;
I 3
		if (ps.last_token == rparen)
		    ps.in_parameter_declaration = 0;
		ps.cast_mask = 0;
		ps.sizeof_mask = 0;
		ps.block_init = 0;
		ps.just_saw_decl--;
E 3

D 3
		if (in_decl && s_code == e_code)
			       /* align this in a declaration */
E 3
I 3
		if (ps.in_decl && s_code == e_code && !ps.block_init)
E 3
		    while ((e_code - s_code) < (dec_ind - 1))
			*e_code++ = ' ';

D 3
		in_decl = (dec_nest > 0);
	    /* if we were in a first level structure declaration, we
	       aren't any more */
E 3
I 3
		ps.in_decl = (ps.dec_nest > 0);	/* if we were in a first
						 * level structure
						 * declaration, we arent
						 * any more */
E 3

D 3
		if ((!sp_sw || hd_type != forstmt) && p_l_follow > 0) {
		/* This should be true iff there were unbalanced parens in
		   the stmt.  It is a bit complicated, because the
		   semicolon might be in a for stmt */
		    printf ("%d: Unbalanced parens\n", line_no);
		    p_l_follow = 0;
		    if (sp_sw) {
		    /* this is a check for a if, while, etc. with
		       unbalanced parens */
E 3
I 3
		if ((!sp_sw || hd_type != forstmt) && ps.p_l_follow > 0) {

		    /*
		     * This should be true iff there were unbalanced
		     * parens in the stmt.  It is a bit complicated,
		     * because the semicolon might be in a for stmt 
		     */
		    diag(1, "Unbalanced parens");
		    ps.p_l_follow = 0;
		    if (sp_sw) {/* this is a check for a if, while, etc.
				 * with unbalanced parens */
E 3
			sp_sw = false;
D 3
			parse (hd_type);
		    /* don't lose the if, or whatever */
E 3
I 3
			parse(hd_type);	/* dont lose the if, or whatever */
E 3
		    }
		}
D 3

E 3
		*e_code++ = ';';
D 3
		want_blank = true;
		in_stmt = (p_l_follow > 0);
	    /* we are no longer in the middle of a stmt */
E 3
I 3
		ps.want_blank = true;
		ps.in_stmt = (ps.p_l_follow > 0);	/* we are no longer in
							 * the middle of a stmt */
E 3

D 3
		if (!sp_sw) {  /* if not if for (;;) */
		    parse (semicolon);
		/* let parser know about end of stmt */
		    force_nl = true;
		/* force newline after a end of stmt */
E 3
I 3
		if (!sp_sw) {	/* if not if for (;;) */
		    parse(semicolon);	/* let parser know about end of
					 * stmt */
		    force_nl = true;	/* force newline after a end of
					 * stmt */
E 3
		}
D 3

E 3
		break;

D 3
	    case lbrace:       /* got a { */
		in_stmt = false;
	    /* don't indent the { */
		force_nl = true;
	    /* force other stuff on same line as { onto new line */
E 3
I 3
	    case lbrace:	/* got a '{' */
		ps.in_stmt = false;	/* dont indent the {} */
		if (!ps.block_init)
		    force_nl = true;	/* force other stuff on same line
					 * as '{' onto new line */
E 3

D 3
		if (s_code != e_code && !btype_2) {
		/* bracket is not alone on line */
		    if (verbose)
			printf ("%d: Line broken\n", line_no);
		    dump_line ();
		    want_blank = false;
E 3
I 3
		if (s_code != e_code && !ps.block_init) {
		    if (!btype_2) {
			dump_line();
			ps.want_blank = false;
		    } else if (ps.in_parameter_declaration && !ps.in_or_st) {
			ps.i_l_follow = 0;
			dump_line();
			ps.want_blank = false;
		    }
E 3
		}
I 3
		if (ps.in_parameter_declaration)
		    prefix_blankline_requested = 0;
E 3

D 3
		if (p_l_follow > 0) {
		/* check for preceeding unbalanced parens */
		    printf ("%d: Unbalanced parens\n", line_no);
		    p_l_follow = 0;
		    if (sp_sw) {
		    /* check for unclosed if, for, etc. */
E 3
I 3
D 4
		if (ps.p_l_follow > 0) {	/* check for preceeding
E 4
I 4
		if (ps.p_l_follow > 0) {	/* check for preceding
E 4
						 * unbalanced parens */
		    diag(1, "Unbalanced parens");
		    ps.p_l_follow = 0;
		    if (sp_sw) {/* check for unclosed if, for, etc. */
E 3
			sp_sw = false;
D 3
			parse (hd_type);
			ind_level = i_l_follow;
E 3
I 3
			parse(hd_type);
			ps.ind_level = ps.i_l_follow;
E 3
		    }
		}
D 3

E 3
		if (s_code == e_code)
D 3
		    ind_stmt = false;
	    /* don't put extra indentation on line with '{' */
		if (in_decl && in_or_st) {
		/* this is either a structure declaration or an init */
		    di_stack[dec_nest++] = dec_ind;
E 3
I 3
		    ps.ind_stmt = false;	/* dont put extra
						 * indentation on line
						 * with '{' */
		if (ps.in_decl && ps.in_or_st) {	/* this is either a
							 * structure declaration
							 * or an init */
		    di_stack[ps.dec_nest++] = dec_ind;
E 3
		    dec_ind = 0;
I 3
		} else {
		    ps.decl_on_line = false;	/* we cant be in the
						 * middle of a
						 * declaration, so dont do
						 * special indentation of
						 * comments */
		    ps.in_parameter_declaration = 0;
E 3
		}
D 3
		else
		    decl_on_line = false;
	    /* we can't be in the middle of a declaration, so don't do
	       special indentation of comments */

		parse (lbrace);/* let parser know about this */
		if (want_blank)/* put a blank before { if { is not at
			          start of line */
E 3
I 3
		parse(lbrace);	/* let parser know about this */
		if (ps.want_blank)	/* put a blank before '{' if '{'
					 * is not at start of line */
E 3
		    *e_code++ = ' ';
D 3
		want_blank = false;
E 3
I 3
		ps.want_blank = false;
E 3
		*e_code++ = '{';
I 3
		ps.just_saw_decl = 0;
E 3
		break;

D 3
	    case rbrace:       /* got a } */
		if (p_l_follow) {
		/* check for unclosed if, for, else. */
		    printf ("%d: Unbalanced parens\n", line_no);
		    p_l_follow = 0;
E 3
I 3
	    case rbrace:	/* got a '}' */
		if (ps.p_l_follow) {	/* check for unclosed if, for,
					 * else. */
		    diag(1, "Unbalanced parens");
		    ps.p_l_follow = 0;
E 3
		    sp_sw = false;
		}
D 3

		if (s_code != e_code) {
		/* } must be first on line */
E 3
I 3
		ps.just_saw_decl = 0;
		if (s_code != e_code && !ps.block_init) {	/* '}' must be first on
								 * line */
E 3
		    if (verbose)
D 3
			printf ("%d: Line broken\n", line_no);
		    dump_line ();
E 3
I 3
			diag(0, "Line broken");
		    dump_line();
E 3
		}
D 3

E 3
		*e_code++ = '}';
D 3
		want_blank = true;
		in_stmt = ind_stmt = false;

		if (dec_nest > 0) {
		/* we are in multi-level structure declaration */
		    dec_ind = di_stack[--dec_nest];
		    in_decl = true;
E 3
I 3
		ps.want_blank = true;
		ps.in_stmt = ps.ind_stmt = false;
		if (ps.dec_nest > 0) {	/* we are in multi-level structure
					 * declaration */
		    dec_ind = di_stack[--ps.dec_nest];
		    if (ps.dec_nest == 0 && !ps.in_parameter_declaration)
			ps.just_saw_decl = 2;
		    ps.in_decl = true;
E 3
		}
D 3

		parse (rbrace);/*   let parser know about this */
E 3
I 3
		prefix_blankline_requested = 0;
		parse(rbrace);	/* let parser know about this */
		ps.search_brace = cuddle_else && ps.p_stack[ps.tos] == ifhead && ps.il[ps.tos] >= ps.ind_level;
		if (ps.tos <= 1 && blanklines_after_procs && ps.dec_nest <= 0)
		    postfix_blankline_requested = 1;
E 3
		break;

D 3
	    case swstmt:       /* got keyword "switch" */
E 3
I 3
	    case swstmt:	/* got keyword "switch" */
E 3
		sp_sw = true;
D 3
		hd_type = swstmt;
	    /* keep this for when we have seen the expression */
		goto copy_id;  /* go move the token into buffer */
E 3
I 3
		hd_type = swstmt;	/* keep this for when we have seen
					 * the expression */
		goto copy_id;	/* go move the token into buffer */
E 3

D 3
	    case sp_paren:     /* token is if, while, for */
		sp_sw = true;  /* the interesting stuff is done after the
			          expression is scanned */
E 3
I 3
	    case sp_paren:	/* token is if, while, for */
		sp_sw = true;	/* the interesting stuff is done after the
				 * expression is scanned */
E 3
		hd_type = (*token == 'i' ? ifstmt :
D 3
			(*token == 'w' ? whilestmt : forstmt));
	    /* remember the type of header for later use by parser */
		goto copy_id;  /* copy the token into line */
E 3
I 3
			   (*token == 'w' ? whilestmt : forstmt));
E 3

D 3
	    case sp_nparen:    /* got else, do */
		in_stmt = false;
		if (e_code != s_code) {
		/* make sure this starts a line */
		    if (verbose)
			printf ("%d: Line broken\n", line_no);
		    dump_line ();
		    want_blank = false;
E 3
I 3
		/*
		 * remember the type of header for later use by parser 
		 */
		goto copy_id;	/* copy the token into line */

	    case sp_nparen:	/* got else, do */
		ps.in_stmt = false;
		if (*token == 'e') {
		    if (e_code != s_code && (!cuddle_else || e_code[-1] != '}')) {
			if (verbose)
			    diag(0, "Line broken");
			dump_line();	/* make sure this starts a line */
			ps.want_blank = false;
		    }
		    force_nl = true;	/* also, following stuff must go
					 * onto new line */
		    last_else = 1;
		    parse(elselit);
		} else {
		    if (e_code != s_code) {	/* make sure this starts a
						 * line */
			if (verbose)
			    diag(0, "Line broken");
			dump_line();
			ps.want_blank = false;
		    }
		    force_nl = true;	/* also, following stuff must go
					 * onto new line */
		    last_else = 0;
		    parse(dolit);
E 3
		}
I 3
		goto copy_id;	/* move the token into line */
E 3

D 3
		force_nl = true;
	    /* also, following stuff must go onto new line */
		parse (*token == 'e' ? elselit : dolit);
	    /* pass token on to parser */
		goto copy_id;  /* move the token into line */
E 3
I 3
	    case decl:		/* we have a declaration type (int,
				 * register, etc.) */
		parse(decl);	/* let parser worry about indentation */
		if (ps.last_token == rparen && ps.tos <= 1)
		    ps.in_parameter_declaration = 1;
		if (ps.in_parameter_declaration && ps.indent_parameters && ps.dec_nest == 0) {
		    ps.ind_level = ps.i_l_follow = 1;
		    ps.ind_stmt = 0;
		}
		ps.in_or_st = true;	/* this might be a structure or
					 * initialization declaration */
		ps.in_decl = ps.decl_on_line = true;
		if ( /* !ps.in_or_st && */ ps.dec_nest <= 0)
		    ps.just_saw_decl = 2;
		prefix_blankline_requested = 0;
		for (i = 0; token[i++];);	/* get length of token */
E 3

D 3
	    case decl: 	       /* we have a declaration type (int,
			          register, etc.) */
		parse (decl);  /* let parser worry about indentation */
		in_or_st = true;
	    /* this might be a structure or initialization declaration */
		in_decl = decl_on_line = true;
		for (i = 0; token[i++];);
	    /* get length of token */

		if (i <= 3)
		    i = 4;

		dec_ind = ((e_code - s_code + i) / ind_size + 1) * ind_size;
	    /* this will tell us how far to indent subsequent identifiers 
	    */
E 3
I 3
		/*
		 * dec_ind = e_code - s_code + (ps.decl_indent>i ?
		 * ps.decl_indent : i); 
		 */
		dec_ind = ps.decl_indent > 0 ? ps.decl_indent : i;
E 3
		goto copy_id;

D 3
	    case ident:        /* got an identifier or constant */
		if (in_decl) { /* if we are in a declaration, we must
			          indent identifier */
		    if (want_blank)
E 3
I 3
	    case ident:	/* got an identifier or constant */
		if (ps.in_decl) {	/* if we are in a declaration, we
					 * must indent identifier */
		    if (ps.want_blank)
E 3
			*e_code++ = ' ';
D 3
		    want_blank = false;

		    while ((e_code - s_code) < dec_ind)
			*e_code++ = ' ';
		}
		else
		    if (sp_sw && p_l_follow == 0) {
		    /* check for if expr w/o parens *//* this will make
		       JRM's obsurd "for ever" statements work */
			sp_sw = false;
			force_nl = true;
			last_u_d = true;
			in_stmt = false;
			parse (hd_type);
E 3
I 3
		    ps.want_blank = false;
		    if (is_procname == 0 || !procnames_start_line) {
			if (!ps.block_init)
			    if (troff && !ps.dumped_decl_indent) {
				sprintf(e_code, "\\c\n.De %dp+\200p\n", dec_ind * 7);
				ps.dumped_decl_indent = 1;
				e_code += strlen(e_code);
			    } else
				while ((e_code - s_code) < dec_ind)
				    *e_code++ = ' ';
		    } else {
			if (dec_ind && s_code != e_code)
			    dump_line();
			dec_ind = 0;
			ps.want_blank = false;
E 3
		    }
D 3

	copy_id: 
		if (want_blank)
E 3
I 3
		} else if (sp_sw && ps.p_l_follow == 0) {
		    sp_sw = false;
		    force_nl = true;
		    ps.last_u_d = true;
		    ps.in_stmt = false;
		    parse(hd_type);
		}
	copy_id:
		if (ps.want_blank)
E 3
		    *e_code++ = ' ';
I 3
		if (troff && ps.its_a_keyword) {
		    *e_code++ = BACKSLASH;
		    *e_code++ = 'f';
		    *e_code++ = 'B';
		}
E 3
		for (t_ptr = token; *t_ptr; ++t_ptr)
		    *e_code++ = *t_ptr;
D 3
		want_blank = true;
E 3
I 3
		if (troff && ps.its_a_keyword) {
		    *e_code++ = BACKSLASH;
		    *e_code++ = 'f';
		    *e_code++ = 'R';
		}
		ps.want_blank = true;
E 3
		break;

D 3
	    case period:       /* treat a period kind of like a binary
			          operation */
		*e_code++ = '.';
	    /* move the period into line */
		want_blank = false;
	    /* don't put a blank after a period */
E 3
I 3
	    case period:	/* treat a period kind of like a binary
				 * operation */
		*e_code++ = '.';/* move the period into line */
		ps.want_blank = false;	/* dont put a blank after a period */
E 3
		break;

D 3
	    case comma: 
		want_blank = (s_code != e_code);
	    /* only put blank after comma if comma does not start the line
	       */
		if (in_decl)   /* align these in a declaration */
E 3
I 3
	    case comma:
		ps.want_blank = (s_code != e_code);	/* only put blank after
							 * comma if comma does
							 * not start the line */
		if (ps.in_decl && is_procname == 0 && !ps.block_init)
E 3
		    while ((e_code - s_code) < (dec_ind - 1))
			*e_code++ = ' ';

		*e_code++ = ',';
D 3

		if (break_comma && p_l_follow == 0 && !leave_comma)
		    force_nl = true;

E 3
I 3
		if (ps.p_l_follow == 0) {
		    ps.block_init = 0;
		    if (break_comma && !ps.leave_comma)
			force_nl = true;
		}
E 3
		break;

D 3
	    case preesc:       /* got the character '#' */
		if (
			(s_com != e_com) ||
			(s_lab != e_lab) ||
			(s_code != e_code)) {
		/* true iff the '#' was not at start of the line */
		    printf ("%d: What is this # doing here?\n", line_no);
		    goto do_binary;
		/* treat it as a binary operator */
		}
E 3
I 3
	    case preesc:	/* got the character '#' */
		if ((s_com != e_com) ||
		    (s_lab != e_lab) ||
		    (s_code != e_code))
		    dump_line();
		*e_lab++ = '#';	/* move whole line to 'label' buffer */
		{
		    int         in_comment = 0;
		    char       *com_start = 0;
		    char        quote = 0;
		    char       *com_end = 0;
E 3

D 3
		*e_lab++ = '#';/* move whole line to 'label' buffer */
		while (*buf_ptr != '\n') {
		    *e_lab = *buf_ptr++;
		    if (buf_ptr >= buf_end)
			fill_buffer ();

		    if (*e_lab++ == '/' && *buf_ptr == '*') {
		    /* check for comment on preprocessor line */
			e_lab - = 2;
		    /* skip back over slash */
			while (*e_lab == '\t' || *e_lab == ' ')
			    --e_lab;
		    /* strip off trailing blanks and tabs */
			*(++e_lab) = '\0';
		    /* null terminate the line */
			if (++buf_ptr >= buf_end)
			       /* space past start of comment */
			    fill_buffer ();
			col_1 = false;
		    /* don't let pr_comment think that this comment starts
		       in column 1 */
			decl_on_line = true;
		    /* treat this as a declaration for comment placement
		       purposes */
			goto proc_comment;
		    /* go process the comment */
E 3
I 3
		    while (*buf_ptr != '\n' || in_comment) {
			*e_lab = *buf_ptr++;
			if (buf_ptr >= buf_end)
			    fill_buffer();
			switch (*e_lab++) {
			    case BACKSLASH:
				if (troff)
				    *e_lab++ = BACKSLASH;
				if (!in_comment) {
				    *e_lab++ = *buf_ptr++;
				    if (buf_ptr >= buf_end)
					fill_buffer();
				}
				break;
			    case '/':
				if (*buf_ptr == '*' && !in_comment && !quote) {
				    in_comment = 1;
				    *e_lab++ = *buf_ptr++;
				    com_start = e_lab - 2;
				}
				break;
			    case '"':
				if (quote == '"')
				    quote = 0;
				break;
			    case '\'':
				if (quote == '\'')
				    quote = 0;
				break;
			    case '*':
				if (*buf_ptr == '/' && in_comment) {
				    in_comment = 0;
				    *e_lab++ = *buf_ptr++;
				    com_end = e_lab;
				}
				break;
			}
E 3
		    }
I 3
		    while (e_lab > s_lab && (e_lab[-1] == ' ' || e_lab[-1] == '\t'))
			e_lab--;
		    if (e_lab == com_end && bp_save == 0) {	/* comment on
								 * preprocessor line */
			if (sc_end == 0)	/* if this is the first
						 * comment, we must set up
						 * the buffer */
			    sc_end = &(save_com[0]);
			else {
			    *sc_end++ = '\n';	/* add newline between
						 * comments */
			    *sc_end++ = ' ';
			    --line_no;
			}
			bcopy(com_start, sc_end, com_end - com_start);
			sc_end += com_end - com_start;
			e_lab = com_start;
			while (e_lab > s_lab && (e_lab[-1] == ' ' || e_lab[-1] == '\t'))
			    e_lab--;
			bp_save = buf_ptr;	/* save current input
						 * buffer */
			be_save = buf_end;
			buf_ptr = save_com;	/* fix so that subsequent
						 * calls to lexi will take
						 * tokens out of save_com */
			*sc_end++ = ' ';	/* add trailing blank,
						 * just in case */
			buf_end = sc_end;
			sc_end = 0;
		    }
		    *e_lab = '\0';	/* null terminate line */
		    ps.pcase = false;
E 3
		}
I 3
		if (strncmp(s_lab, "#if", 3) == 0)
		    if (ifdef_level < sizeof state_stack / sizeof state_stack[0]) {
			match_state[ifdef_level].tos = -1;
			state_stack[ifdef_level++] = ps;
		    } else
			diag(1, "#if stack overflow");
		else if (strncmp(s_lab, "#else", 5) == 0)
		    if (ifdef_level <= 0)
			diag(1, "Unmatched #else");
		    else {
			match_state[ifdef_level - 1] = ps;
			ps = state_stack[ifdef_level - 1];
		} else if (strncmp(s_lab, "#endif", 6) == 0)
		    if (ifdef_level <= 0)
			diag(1, "Unmatched #endif");
		    else {
			ifdef_level--;
#ifdef undef
E 3

D 3
		*e_lab = '\0'; /* null terminate line */
		pcase = false;
		break;	       /* subsequent processing of the newline
			          character will cause the line to be
			          printed */
E 3
I 3
			/*
			 * This match needs to be more intelligent before
			 * the message is useful 
			 */
			if (match_state[ifdef_level].tos >= 0
			    && bcmp(&ps, &match_state[ifdef_level], sizeof ps))
			    diag(0, "Syntactically inconsistant #ifdef alternatives.");
#endif
		    }
		break;		/* subsequent processing of the newline
				 * character will cause the line to be
				 * printed */
E 3

D 3
	    case comment:      /* we have gotten a /*  this is a biggie */
	proc_comment: 
		pr_comment ();
E 3
I 3
	    case comment:	/* we have gotten a /*  this is a biggie */
	proc_comment:
		if (flushed_nl) {	/* we should force a broken line
					 * here */
		    flushed_nl = false;
		    dump_line();
		    ps.want_blank = false;	/* dont insert blank at
						 * line start */
		    force_nl = false;
		}
		pr_comment();
E 3
		break;
D 3
	}		       /* end of big switch stmt */

	*e_code = '\0';	       /* make sure code section is null
			          terminated */

    }			       /* end of main while (1) loop */
E 3
I 3
	}			/* end of big switch stmt */
	*e_code = '\0';		/* make sure code section is null
				 * terminated */
	if (type_code != comment && type_code != newline && type_code != preesc)
	    ps.last_token = type_code;
    }				/* end of main while (1) loop */
E 3
};

/*
D 3
 * copy input file to backup file
 * if in_name is /blah/blah/blah/file, then backup file
 * will be ".Bfile"
 * then make the backup file the input and original
 * input file the output
E 3
I 3
D 4
 * copy input file to backup file if in_name is /blah/blah/blah/file, then
 * backup file will be ".Bfile" then make the backup file the input and
 * original input file the output 
E 4
I 4
 * copy input file to backup file.  If in_name is /blah/blah/blah/file, then
 * backup file will be "file.BAK".  Then make the backup file the input and
 * original input file the output.
E 4
E 3
 */
D 3
bakcopy () {
    int     n,
            bakchn;
    char    buff[512];
    register char  *p;
E 3
I 3
bakcopy()
{
    int         n,
                bakchn;
D 4
    char        buff[512];
E 4
I 4
    char        buff[BUFSIZ];
E 4
    register char *p;
I 4
    char *rindex();
E 4
E 3

D 3
 /* construct file name .Bfile */
    for (p = in_name; *p; p++);/* skip to end of string */
    while (p > in_name && *p != '/')/* find last '/' */
E 3
I 3
D 4
    /* construct file name .Bfile */
    for (p = in_name; *p; p++);	/* skip to end of string */
    while (p > in_name && *p != '/')	/* find last '/' */
E 3
	p--;
    if (*p == '/')
E 4
I 4
    if ((p = rindex(in_name, '/')) != NULL)
E 4
	p++;
I 4
    else
	p = in_name;
E 4
D 3
    sprintf (bakfile, ".B%s", p);
E 3
I 3
    sprintf(bakfile, "%s.BAK", p);
E 3

D 3
 /* copy in_name to backup file */
    bakchn = creat (bakfile, 0600);
E 3
I 3
    /* copy in_name to backup file */
    bakchn = creat(bakfile, 0600);
E 3
    if (bakchn < 0) {
D 3
	printf ("can't create backup file \"%s\"\n", bakfile);
	exit ();
E 3
I 3
D 4
	printf("can't create backup file \"%s\"\n", bakfile);
	exit();
E 4
I 4
	fprintf(stderr, "indent: can't create backup file \"%s\"\n", bakfile);
	exit(1);
E 4
E 3
    }
D 3
    while (n = read (input, buff, 512))
	write (bakchn, buff, n);
    close (bakchn);
    close (input);
E 3
I 3
D 4
    while (n = read(fileno(input), buff, 512))
	write(bakchn, buff, n);
E 4
I 4
    while ((n = read(fileno(input), buff, sizeof buff)) > 0)
	if (write(bakchn, buff, n) != n) {
	    fprintf(stderr, "indent: error writing backup file \"%s\"\n",
		bakfile);
	    exit(1);
	}
    if (n < 0) {
	fprintf(stderr, "indent: error reading input file \"%s\"\n", in_name);
	exit(1);
    }
E 4
    close(bakchn);
    fclose(input);
E 3

D 3
 /* re-open backup file as the input file */
    input = open (bakfile, 0);
E 3
I 3
    /* re-open backup file as the input file */
    input = fopen(bakfile, "r");
E 3
D 4
    if (input < 0) {
D 3
	printf ("can't re-open backup file\n");
	exit ();
E 3
I 3
	printf("can't re-open backup file\n");
	exit();
E 4
I 4
    if (input == NULL) {
	fprintf(stderr, "indent: can't re-open backup file\n");
	exit(1);
E 4
E 3
    }
D 3

 /* now the original input file will be the output */
    output = creat (in_name, 0644);
    if (output < 0) {
	printf ("can't create %s\n", in_name);
	unlink (bakfile);
	exit ();
E 3
I 3
    /* now the original input file will be the output */
    output = fopen(in_name, "w");
D 4
    if (output == 0) {
	printf("can't create %s\n", in_name);
E 4
I 4
    if (output == NULL) {
	fprintf(stderr, "indent: can't create %s\n", in_name);
E 4
	unlink(bakfile);
D 4
	exit();
E 4
I 4
	exit(1);
E 4
E 3
    }
D 4
}


D 3
set_option (arg)
char   *arg;
E 3
I 3
char       *param_start;

eqin(s1, s2)
    register char *s1;
    register char *s2;
E 3
{
D 3
    register    j;
    for (j = 0; options[j].str != 0; ++j) {
			       /* look thru list of possible options */
	if (eqin (options[j].str, arg)) {
	    set_var (j, arg);
	    break;	       /* get out of for loop */
	}
E 3
I 3
    while (*s1) {
	if (*s1++ != *s2++)
	    return (false);
E 3
    }
D 3

    if (options[j].str == 0) { /* illegal arg given */
	printf ("Unknown parameter: %s\n", arg);
	exit ();
    }
E 3
I 3
    param_start = s2;
    return (true);
E 3
}


D 3
set_var (j, arg)
char   *arg;
E 3
I 3
set_option(arg)
    char       *arg;
E 3
{
D 3
    switch (options[j].code) {
	case 1: 	       /* have -lnnn */
	    max_col = atoi (&arg[2]);
	    break;
	case 2: 	       /* have -cnnn */
	    com_ind = atoi (&arg[2]);
	    break;
	case 3: 	       /* have -innn */
	    ind_size = atoi (&arg[2]);
	    break;
	case 4: 	       /* have -cdnnn */
	    decl_com_ind = atoi (&arg[3]);
	    break;
	case 5: 	       /* have -v */
E 3
I 3
    if (!eqin("-npro", arg))
	if (eqin("-lc", arg))	/* comment line length */
	    block_comment_max_col = atoi(param_start);
	else if (eqin("-lp", arg))
	    lineup_to_parens = 1;
	else if (eqin("-nlp", arg))
	    lineup_to_parens = 0;
	else if (eqin("-l", arg))	/* line length */
	    max_col = atoi(param_start);
	else if (eqin("-psl", arg))	/* if true, the names of
					 * procedures being defined get
					 * placed in column 1 (ie. a
					 * newline is placed between the
					 * type of the procedure and its
					 * name) */
	    procnames_start_line = 1;
	else if (eqin("-npsl", arg))
	    procnames_start_line = 0;
	else if (eqin("-fc1", arg))
	    format_col1_comments = 1;
	else if (eqin("-nfc1", arg))
	    format_col1_comments = 0;
	else if (eqin("-pcs", arg))	/* If true, procedure calls look
					 * like: foo(bar) rather than foo
					 * (bar) */
	    proc_calls_space = 1;
	else if (eqin("-npcs", arg))
	    proc_calls_space = 0;
	else if (eqin("-ip", arg))	/* indent parameters */
	    ps.indent_parameters = 1;
	else if (eqin("-nip", arg))	/* no indent parameters */
	    ps.indent_parameters = 0;
	else if (eqin("-cli", arg)) {	/* case label indent */
	    extern float atof();

	    ps.case_indent = atof(param_start);
	}
	else if (eqin("-ci",arg))
	    continuation_indent = atoi(param_start);
	else if (eqin("-cdb", arg))	/* comment delimiters should be on
					 * lines by themselves */
	    comment_delimiter_on_blankline = 1;
	else if (eqin("-ncdb", arg))	/* comment delimiters shouldnt be
					 * on lines by themselves */
	    comment_delimiter_on_blankline = 0;
	else if (eqin("-i", arg))	/* indent width */
	    ps.ind_size = atoi(param_start);
	else if (eqin("-cd", arg))	/* indent for comments on
					 * declarations */
	    ps.decl_com_ind = atoi(param_start);
	else if (eqin("-ce", arg))	/* true iff 'else' should cuddle
					 * up to '}' */
	    cuddle_else = 1;
	else if (eqin("-c", arg))	/* comment indent */
	    ps.com_ind = atoi(param_start);
	else if (eqin("-v", arg))	/* spew out rubbish */
E 3
	    verbose = true;
D 3
	    break;
	case 6: 	       /* have -nv */
E 3
I 3
	else if (eqin("-nv", arg))	/* keep quiet */
E 3
	    verbose = false;
D 3
	    break;
	case 7: 	       /* have -dj */
	    ljust_decl = true;
	    break;
	case 8: 	       /* have -ndj */
	    ljust_decl = false;
	    break;
	case 9: 	       /* -nbc */
	    leave_comma = true;
	    break;
	case 10: 	       /* -bc */
	    leave_comma = false;
	    break;
	case 13: 	       /* -dnnn */
	    unindent_displace = atoi (&arg[2]);
	    break;
	case 14: 	       /* -br */
E 3
I 3
	else if (eqin("-dj", arg))
	    ps.ljust_decl = true;
	else if (eqin("-ndj", arg))
	    ps.ljust_decl = false;
	else if (eqin("-nbc", arg))	/* dont break after commas in
					 * declarations */
	    ps.leave_comma = true;
	else if (eqin("-bc", arg))	/* break after commas in
					 * declarations */
	    ps.leave_comma = false;
	else if (eqin("-di", arg))	/* indent from type to varname in
					 * a declaration */
	    ps.decl_indent = atoi(param_start);
	else if (eqin("-d", arg))
	    ps.unindent_displace = atoi(param_start);
	else if (eqin("-br", arg))
E 3
	    btype_2 = true;
D 3
	    break;
	case 15: 	       /* -bl */
E 3
I 3
	else if (eqin("-bl", arg))
E 3
	    btype_2 = false;
D 3
	    break;
	case 16:
	    if(input<0) input = 0;
	    if(output<0) output = 1;
	    break;
    }
E 3
I 3
	else if (eqin("-st", arg)) {	/* input and output on standard IO */
	    if (input == 0)
		input = stdin;
	    if (output == 0)
		output = stdout;
	} else if (eqin("-ei", arg))	/* else-ifs should be stuck
					 * together */
	    ps.else_if = 1;
	else if (eqin("-nei", arg))	/* else-ifs should be broken apart */
	    ps.else_if = 0;
	else if (eqin("-nce", arg))	/* else should always start a line */
	    cuddle_else = 0;
	else if (eqin("-sc", arg))	/* comment continuations should
					 * start with a * */
	    star_comment_cont = 1;
	else if (eqin("-nsc", arg))
	    star_comment_cont = 0;	/* comments shouldnt start with a
					 * star */
	else if (eqin("-bap", arg))	/* blanklines after procedures */
	    blanklines_after_procs = 1;
	else if (eqin("-nbap", arg))	/* blanklines after procedures */
	    blanklines_after_procs = 0;
	else if (eqin("-sob", arg))	/* swallow optional blanklines */
	    swallow_optional_blanklines = 1;
	else if (eqin("-nsob", arg))	/* swallow optional blanklines */
	    swallow_optional_blanklines = 0;
	else if (eqin("-bad", arg))	/* blanklines after declarations */
	    blanklines_after_declarations = 1;
	else if (eqin("-nbad", arg))	/* blanklines after declarations */
	    blanklines_after_declarations = 0;
	else if (eqin("-bbb", arg))	/* blanklines before blockcomments */
	    blanklines_before_blockcomments = 1;
	else if (eqin("-nbbb", arg))	/* blanklines before blockcomments */
	    blanklines_before_blockcomments = 0;
	else if (eqin("-troff", arg))
	    troff = 1;
	else if (arg[0] == '-' && arg[1] == 'T')	/* -Ttypename */
	    addkey(arg + 2, 4);
	else {			/* illegal arg given */
	    printf("Unknown parameter: %s\n", arg);
	    exit();
	}
E 3
}


/*
D 3
 * GETPRO - get profile file
 * profile file is max 127 characters
E 3
I 3
 * GETPRO - get profile file profile file is max 127 characters 
E 3
 */
D 3
getpro (name, buf)
char   *name,		       /* profile file name, as in '.indent.pro' 
			       */
       *buf;		       /* will receive contents of .pro file */
E 3
I 3
getpro(name, buf, len)
    char       *name,		/* profile file name, as in '.indent.pro' */
               *buf;		/* will receive contents of .pro file */
E 3
{
    register    chn,
                n;
D 3
    char    file[32];
E 3
I 3
    char        file[100];
E 3

    file[0] = 0;
D 3
    strcat (file, getenv ("HOME"));
    strcat (file, "/");
    strcat (file, name);
    chn = open (file, 0);
E 3
I 3
    strcat(file, getenv("HOME"));
    strcat(file, "/");
    strcat(file, name);
    if ((chn = open(name, 0)) < 0)
	chn = open(file, 0);
E 3
    if (chn < 0)
	return (-1);
D 3
    n = read (chn, buf, 127);
E 3
I 3
    n = read(chn, buf, len);
E 3
    if (n < 0)
	return (-1);
D 3
    buf[n--] = 0;	       /* null terminate line */
E 3
I 3
    buf[n--] = 0;		/* null terminate line */
E 3
    if (buf[n] == '\n')
	buf[n] = 0;
D 3
    close (chn);
E 3
I 3
    close(chn);
E 3
    return (0);
}


/*
D 3
 * strip off arguments in a string:
 * p is address of a character pointer
 * nextchr returns pointer to front of first arg
 * arg is null terminated.
 * p is reset to after arg for subsequent calls
E 3
I 3
 * strip off arguments in a string: p is address of a character pointer
 * nextchr returns pointer to front of first arg arg is null terminated. p
 * is reset to after arg for subsequent calls 
E 3
 */
D 3
char   *nxtarg (p)
char  **p;
E 3
I 3
char       *
nxtarg(p)
    char      **p;
E 3
{
D 3
    register char  *f,
                   *b;
    f = b = *p;
    while (*f && (*f == ' ' || *f == '\t'))
E 3
I 3
    register char *f,
               *b;

    f = *p;
    while (*f && *f <= ' ')
E 3
	f++;
D 3
    while (*b && (*b != ' ' && *b != '\t'))
E 3
I 3
    b = f;
    while (*b > ' ')
E 3
	b++;
    if (*b != 0)
	*b++ = 0;
    *p = b;
    return (f);
}


D 3
set_profile () {
    char    line[128],
           *b;
    register char  *f;
    extern char *nxtarg ();
E 3
I 3
set_profile()
{
    char        line[1000],
               *b;
    register char *f;
    extern char *nxtarg();
E 3

D 3
    if (getpro (".indent.pro", line) < 0)
E 3
I 3
    if (getpro(".indent.pro", line, sizeof line) < 0)
E 3
	return;
    b = line;
D 3
    if(verbose) printf ("profile: %s\n", b);
    while (*(f = nxtarg (&b)))
	set_option (f);
E 3
I 3
    if (verbose)
	printf("profile: %s\n", b);
    while (*(f = nxtarg(&b)))
	set_option(f);
E 4
E 3
}
E 1
