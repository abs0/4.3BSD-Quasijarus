h18560
s 00010/00005/00257
d D 5.3 88/06/29 18:50:54 bostic 8 7
c install approved copyright notice
e
s 00013/00004/00249
d D 5.2 88/06/06 21:51:34 bostic 7 6
c written by Robert Henry; add Berkeley specific header
e
s 00012/00000/00241
d D 5.1 85/05/31 11:41:41 dist 6 5
c Add copyright
e
s 00007/00005/00234
d D 1.5 84/06/05 10:53:44 ralph 5 4
c changes to allow it to work from at(1), etc. when there is no tty.
e
s 00000/00009/00239
d D 1.4 82/05/04 12:34:08 rrh 4 3
c Preserves links by writing to /tmp and copying.  Removed #ifdef ERNIE
e
s 00069/00064/00179
d D 1.3 82/01/22 17:55:48 rrh 3 2
c Re proceduralization in errortouch for clarity.
c Added -T (terse option)
c Added typedefs, and changed textual form of structures
c changed argument to vi to begin searching from line 1, instead of line $
e
s 00001/00001/00242
d D 1.2 80/10/16 09:57:03 root 2 1
c open /dev/tty instead of ttyname(2) for input
e
s 00243/00000/00000
d D 1.1 80/10/16 09:46:36 root 1 0
c date and time created 80/10/16 09:46:36 by root
e
u
U
t
T
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
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

E 6
I 1
D 7
static	char *sccsid = "%W% (Berkeley) %G%";
E 7
I 7
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 7
#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include "error.h"

int	nerrors = 0;
D 3
struct	error_desc	*er_head;
struct	error_desc	**errors;	
E 3
I 3
Eptr	er_head;
Eptr	*errors;	
E 3

int	nfiles = 0;
D 3
struct	error_desc	***files;	/* array of pointers into errors*/
E 3
I 3
Eptr	**files;	/* array of pointers into errors*/
E 3
int	language = INCC;

char	*currentfilename = "????";
char	*processname;
D 5
char	*im_on;			/* my tty name */
E 5
I 5
char	im_on[] = "/dev/tty";	/* my tty name */
E 5

boolean	query = FALSE;		/* query the operator if touch files */
boolean	notouch = FALSE;	/* don't touch ANY files */
boolean	piflag	= FALSE;	/* this is not pi */
I 3
boolean	terse	= FALSE;	/* Terse output */
E 3

char	*suffixlist = ".*";	/* initially, can touch any file */

int	errorsort();
int	onintr();
/*
 *	error [-I ignorename] [-n] [-q] [-t suffixlist] [-s] [-v] [infile]
 *	
I 3
 *	-T:	terse output
 *
E 3
 *	-I:	the following name, `ignorename' contains a list of
 *		function names that are not to be treated as hard errors.
 *		Default: ~/.errorsrc
 *
 *	-n:	don't touch ANY files!
 *
 *	-q:	The user is to be queried before touching each
 *		file; if not specified, all files with hard, non
 *		ignorable errors are touched (assuming they can be).
 *
 *	-t:	touch only files ending with the list of suffices, each
 *		suffix preceded by a dot.
 *		eg, -t .c.y.l
 *		will touch only files ending with .c, .y or .l
 *
 *	-s:	print a summary of the error's categories.
 *
 *	-v:	after touching all files, overlay vi(1), ex(1) or ed(1)
 *		on top of error, entered in the first file with
 *		an error in it, with the appropriate editor
 *		set up to use the "next" command to get the other
 *		files containing errors.
 *
 *	-p:	(obsolete: for older versions of pi without bug
 *		fix regarding printing out the name of the main file
 *		with an error in it)
 *		Take the following argument and use it as the name of
 *		the pascal source file, suffix .p
 *
 *	-E:	show the errors in sorted order; intended for
 *		debugging.
 *
 *	-S:	show the errors in unsorted order
 *		(as they come from the error file)
 *
 *	infile:	The error messages come from this file.
 *		Default: stdin
 */
main(argc, argv)
	int	argc;
	char	*argv[];
{
	char	*cp;
	char	*ignorename = 0;
	int	ed_argc;
	char	**ed_argv;		/*return from touchfiles*/
	boolean	show_errors = FALSE;
	boolean	Show_Errors = FALSE;
	boolean	pr_summary = FALSE;
	boolean	edit_files = FALSE;

	processname = argv[0];

	errorfile = stdin;
D 3
	if (argc > 1){
		for(; (argc > 1) && (argv[1][0] == '-'); argc--, argv++){
			for (cp = argv[1] + 1; *cp; cp++){
				switch(*cp){
					default:
						fprintf(stderr, "%s: -%c: Unknown flag\n",
							processname, *cp);
						break;
					case 'n':	/* no touch */
						notouch = TRUE;
						break;
					case 'q':	/* query */
						query = TRUE;
						break;
					case 'S':
						Show_Errors = TRUE;
						break;
					case 's':	/* show summary */
						pr_summary = TRUE;
						break;
					case 'v':	/* edit files */
						edit_files = TRUE;
						break;
E 3
I 3
	if (argc > 1) for(; (argc > 1) && (argv[1][0] == '-'); argc--, argv++){
		for (cp = argv[1] + 1; *cp; cp++) switch(*cp){
		default:
			fprintf(stderr, "%s: -%c: Unknown flag\n",
				processname, *cp);
			break;

		case 'n':	notouch = TRUE;	break;
		case 'q':	query = TRUE;	break;
		case 'S':	Show_Errors = TRUE;	break;
		case 's':	pr_summary = TRUE;	break;
		case 'v':	edit_files = TRUE;	break;
		case 'T':	terse = TRUE;	break;
E 3
D 4
#ifndef ERNIE
D 3
					case 'p':
						*cp-- = 0; argv++; argc--;
						if (argc > 1){
							currentfilename=argv[1];
							piflag = TRUE;
						}
						break;
E 3
I 3
		case 'p':
			*cp-- = 0; argv++; argc--;
			if (argc > 1){
				currentfilename = argv[1];
				piflag = TRUE;
			}
			break;
E 3
#endif
E 4
D 3
					case 't':
						*cp-- = 0; argv++; argc--;
						if (argc > 1){
							suffixlist = argv[1];
						}
						break;
					case 'I':	/*ignore file name*/
						*cp-- = 0; argv++; argc--;
						if (argc > 1)
							ignorename = argv[1];
						break;
				}	/*end of the argument switch*/
			}	/*end of loop to consume characters after '-'*/
		}	
	}	/* end of being at least one argument */
E 3
I 3
		case 't':
			*cp-- = 0; argv++; argc--;
			if (argc > 1){
				suffixlist = argv[1];
			}
			break;
		case 'I':	/*ignore file name*/
			*cp-- = 0; argv++; argc--;
			if (argc > 1)
				ignorename = argv[1];
			break;
		}
	}	
E 3
	if (notouch)
		suffixlist = 0;
	if (argc > 1){
		if (argc > 3){
			fprintf(stderr, "%s: Only takes 0 or 1 arguments\n",
				processname);
			exit(3);
		}
		if ( (errorfile = fopen(argv[1], "r")) == NULL){
			fprintf(stderr, "%s: %s: No such file or directory for reading errors.\n",
				processname, argv[1]);
			exit(4);
		}
	}
D 2
	im_on = (char *)ttyname(2);
E 2
I 2
D 5
	im_on = "/dev/tty";
E 5
E 2
	if ( (queryfile = fopen(im_on, "r")) == NULL){
D 5
		fprintf(stderr,"%s: Can't open \"%s\" to query the user.\n",
			processname, im_on);
		exit(9);
E 5
I 5
		if (query){
			fprintf(stderr,
				"%s: Can't open \"%s\" to query the user.\n",
				processname, im_on);
			exit(9);
		}
E 5
	}
	if (signal(SIGINT, onintr) == SIG_IGN)
		signal(SIGINT, SIG_IGN);
	if (signal(SIGTERM, onintr) == SIG_IGN)
		signal(SIGTERM, SIG_IGN);
	getignored(ignorename);
	eaterrors(&nerrors, &errors);
	if (Show_Errors)
		printerrors(TRUE, nerrors, errors);
D 3
	qsort(errors, nerrors, sizeof (struct error_desc *), errorsort);
E 3
I 3
	qsort(errors, nerrors, sizeof(Eptr), errorsort);
E 3
	if (show_errors)
		printerrors(FALSE, nerrors, errors);
	findfiles(nerrors, errors, &nfiles, &files);
#define P(msg, arg) fprintf(stdout, msg, arg)
	if (pr_summary){
	    if (nunknown)
	      P("%d Errors are unclassifiable.\n", nunknown);
	    if (nignore)
	      P("%d Errors are classifiable, but totally discarded.\n",nignore);
	    if (nsyncerrors)
	      P("%d Errors are synchronization errors.\n", nsyncerrors);
	    if (nignore)
	      P("%d Errors are discarded because they refer to sacrosinct files.\n", ndiscard);
	    if (nnulled)
	      P("%d Errors are nulled because they refer to specific functions.\n", nnulled);
	    if (nnonspec)
	      P("%d Errors are not specific to any file.\n", nnonspec);
	    if (nthisfile)
	      P("%d Errors are specific to a given file, but not to a line.\n", nthisfile);
	    if (ntrue)
	      P("%d Errors are true errors, and can be inserted into the files.\n", ntrue);
	}
	filenames(nfiles, files);
	fflush(stdout);
D 3
	if (touchfiles(nfiles, files, &ed_argc, &ed_argv) && edit_files){
		if (!query || 
			inquire("Do you still want to edit the files you touched? ")){
			/*
			 *	ed_agument's first argument is
			 *	a vi/ex compatabile search argument
			 *	to find the first occurance of ###
			 */
			try("vi", ed_argc, ed_argv);
			try("ex", ed_argc, ed_argv);
			try("ed", ed_argc-1, ed_argv+1);
			fprintf(stdout, "Can't find any editors.\n");
E 3
I 3
	if (touchfiles(nfiles, files, &ed_argc, &ed_argv) && edit_files)
		forkvi(ed_argc, ed_argv);
}

forkvi(argc, argv)
	int	argc;
	char	**argv;
{
	if (query){
		switch(inquire(terse
		    ? "Edit? "
		    : "Do you still want to edit the files you touched? ")){
		case Q_NO:
		case Q_no:
			return;
		default:
			break;
E 3
		}
	}
I 3
	/*
	 *	ed_agument's first argument is
	 *	a vi/ex compatabile search argument
	 *	to find the first occurance of ###
	 */
	try("vi", argc, argv);
	try("ex", argc, argv);
	try("ed", argc-1, argv+1);
	fprintf(stdout, "Can't find any editors.\n");
E 3
}

try(name, argc, argv)
	char	*name;
	int	argc;
	char	**argv;
{
	argv[0] = name;
	wordvprint(stdout, argc, argv);
	fprintf(stdout, "\n");
	fflush(stderr);
	fflush(stdout);
	sleep(2);
	if (freopen(im_on, "r", stdin) == NULL)
		return;
	if (freopen(im_on, "w", stdout) == NULL)
		return;
	execvp(name, argv);
}

int errorsort(epp1, epp2)
D 3
	struct	error_desc	**epp1, **epp2;
E 3
I 3
		Eptr	*epp1, *epp2;
E 3
{
D 3
	register	struct	error_desc	*ep1, *ep2;
			int	order;
E 3
I 3
	reg	Eptr	ep1, ep2;
		int	order;
E 3
	/*
	 *	Sort by:
	 *	1)	synchronization, non specific, discarded errors first;
	 *	2)	nulled and true errors last
	 *		a)	grouped by similar file names
	 *			1)	grouped in ascending line number
	 */
	ep1 = *epp1; ep2 = *epp2;
	if (ep1 == 0 || ep2 == 0)
		return(0);
	if ( (NOTSORTABLE(ep1->error_e_class)) ^ (NOTSORTABLE(ep2->error_e_class))){
		return(NOTSORTABLE(ep1->error_e_class) ? -1 : 1);
	}
	if (NOTSORTABLE(ep1->error_e_class))	/* then both are */
		return(ep1->error_no - ep2->error_no);
	order = strcmp(ep1->error_text[0], ep2->error_text[0]);
	if (order == 0){
		return(ep1->error_line - ep2->error_line);
	}
	return(order);
}
E 1
