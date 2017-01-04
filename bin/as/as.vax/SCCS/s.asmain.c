h50046
s 00001/00001/00711
d D 5.6 04/02/07 05:22:56 msokolov 21 20
c "Caution: absolute origins" is a warning, don't screw people with yyerror
e
s 00005/00002/00707
d D 5.5 03/11/08 22:34:03 msokolov 20 19
c bring back -d124, without affecting 3-way relaxing of branches
e
s 00006/00008/00703
d D 5.4 00/08/29 22:10:47 msokolov 19 18
c Complete jxxx relaxation overhaul. We now relax three-way without -J!
c -J is now ignored. We now also relax SOBs, AOBs, and ACBs. See the comments in
c addsob() in c2 for the motivation.
c As a side effect, we now require -d4.
c As yet another side effect, the handling of branches in instrs has been
c significantly cleaned up for c2.
e
s 00001/00001/00710
d D 5.3 87/10/22 10:05:25 bostic 18 17
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00710
d D 5.2 85/10/21 19:24:13 mckusick 17 16
c 0 != "" for some machines Robert
e
s 00011/00002/00700
d D 5.1 85/04/23 14:45:07 dist 16 15
c add copyright
e
s 00006/00000/00696
d D 4.15 84/02/17 15:38:35 ralph 15 14
c use optimal block size.
e
s 00010/00000/00686
d D 4.14 83/11/21 14:43:28 rrh 14 13
c -a flag allows alignment to be specified; defaults to 2
e
s 00001/00002/00685
d D 4.13 83/06/30 19:19:25 rrh 13 12
c bye bye fixed names (eg, FLEXNAMES is not set)
e
s 00003/00024/00684
d D 4.12 83/06/30 19:11:28 rrh 12 11
c bye bye VMS: UNIX only.  All the preceeding changes to the symbol
c table stuff were never tested under VMS
e
s 00060/00027/00648
d D 4.11 83/06/30 19:02:24 rrh 11 10
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00034/00000/00641
d D 4.10 82/04/17 17:07:43 rrh 10 9
c Added -v (version) option to assembler.
e
s 00028/00009/00613
d D 4.9 82/02/14 16:32:41 rrh 9 8
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00007/00007/00615
d D 4.8 80/08/20 12:09:18 henry 8 7
c Partial backout of previous delta; align to no more than full word
e
s 00007/00007/00615
d D 4.7 80/08/20 10:05:05 henry 7 6
c Round text and data segments to Double Word so that .align 3 always works
e
s 00002/00000/00620
d D 4.6 80/08/16 17:29:01 henry 6 5
c Fix construction of tmp file directory name
e
s 00007/00010/00613
d D 4.5 80/08/16 15:43:38 bill 5 4
c fix sccsing in version, arb # infiles, 
c 
e
s 00012/00002/00611
d D 4.4 80/08/16 14:54:50 bill 4 3
c -R option
e
s 00005/00000/00608
d D 4.3 80/08/15 18:33:28 henry 3 2
c -J option: use jmp instead of brw for jxxx resolution
e
s 00013/00015/00595
d D 4.2 80/08/15 18:03:12 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 00610/00000/00000
d D 4.1 80/08/13 18:55:16 bill 1 0
c date and time created 80/08/13 18:55:16 by bill
e
u
U
t
T
I 1
D 9
/* Copyright (c) 1980 Regents of the University of California */
static	char sccsid[] = "%Z%%M% %I% %G%";
E 9
I 9
/*
D 16
 *	Copyright (c) 1982 Regents of the University of California
E 16
I 16
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 16
 */
I 16

E 16
#ifndef lint
D 16
static char sccsid[] = "%Z%%M% %I% %G%";
E 16
I 16
char copyright[] =
"%Z% Copyright (c) 1982 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
E 16
#endif not lint

E 9
#include <stdio.h>
#include <ctype.h>
D 2
#include <sys/types.h>
E 2
#include <signal.h>
D 2
#include <a.out.h>
E 2

#include "as.h"
#include "assyms.h"
D 9
#include "asexpr.h"
E 9
#include "asscan.h"
I 9
#include "asexpr.h"
E 9

I 15
#include <sys/stat.h>

E 15
D 12
#ifdef UNIX
E 12
D 2
#define	unix_lang_name "VAX/UNIX Assembler V3.0"
E 2
I 2
D 5
#define	unix_lang_name "VAX/UNIX Assembler V%M%"
E 5
I 5
#define	unix_lang_name "VAX/UNIX Assembler V%G% %I%"
E 5
E 2
D 12
#endif

#ifdef VMS
D 2
#define vms_lang_name "VAX/VMS C assembler V1.00"
E 2
I 2
#define vms_lang_name "VAX/VMS C Assembler V1.00"
E 2
#endif VMS

E 12
/*
 *	variables to manage reading the assembly source files
 */
char	*dotsname;	/*the current file name; managed by the parser*/
int	lineno;		/*current line number; managed by the parser*/
D 5
char	*innames[32];	/*names of the files being assembled*/
E 5
I 5
char	**innames;	/*names of the files being assembled*/
E 5
int	ninfiles;	/*how many interesting files there are*/
/*
 *	Flags settable from the argv process argument list
 */
int	silent = 0;	/*don't complain about any errors*/
int	savelabels = 0;	/*write the labels to the a.out file*/
I 20
int 	d124 = 4;	/*default allocate 4 bytes for unknown pointers*/
E 20
D 19
int 	d124 = 4;	/*default allocate 4 bytes for unknown pointers*/
E 19
I 14
int 	maxalign = 2;	/*default .align maximum*/
E 14
int	anyerrs = 0;	/*no errors yet*/
I 9
int	anywarnings=0;	/*no warnings yet*/
E 9
int	orgwarn = 0;	/*Bad origins*/
int	passno = 1;	/* current pass*/
I 3
D 19
int	jxxxJUMP = 0;	/* in jxxxes that branch too far, use jmp instead of brw */
E 19
I 4
int	readonlydata = 0;	/* initialzed data -> text space */
E 4
E 3

I 9
int	nGHnumbers = 0;		/* GH numbers used */
int	nGHopcodes = 0;		/* GH opcodes used */
int	nnewopcodes = 0;	/* new opcodes used */

E 9
#ifdef DEBUG
int 	debug = 0;
int	toktrace = 0;
#endif

D 12
int	useVM =		/*put the temp file in virtual memory*/
#ifdef VMS
	1;		/*VMS has virtual memory (duh)*/
#endif VMS
#ifdef UNIX
 	0;
#endif
E 12
I 12
int	useVM =	0;
E 12

char	*endcore;	/*where to get more symbol space*/

/*
 *	Managers of the a.out file.
 */
struct	exec	hdr;
D 4
#define	MAGIC	0410
E 4
I 4
#define	MAGIC	0407
E 4
u_long	tsize;		/* total text size */
u_long	dsize;		/* total data size */
u_long	datbase;	/* base of the data segment */
u_long	trsize;		/* total text relocation size */
u_long	drsize;		/* total data relocation size */

/*
 *	Information about the current segment is accumulated in
 *	usedot; the most important information stored is the
 *	accumulated size of each of the text and data segments
 *
 *	dotp points to the correct usedot expression for the current segment
 */
struct	exp	usedot[NLOC+NLOC];	/* info about all segments */
struct	exp	*dotp;			/* data/text location pointer */
/*
D 11
 *	The inter pass temporary file is opened and closed by stdio, but
E 11
I 11
 *	The inter pass temporary token file is opened and closed by stdio, but
E 11
 *	is written to using direct read/write, as the temporary file
 *	is composed of buffers exactly BUFSIZ long.
 */
D 11
FILE	*tmpfil;			/* interpass communication file */
E 11
I 11
FILE	*tokfile;			/* interpass communication file */
char	tokfilename[TNAMESIZE];
E 11
/*
I 11
 *	The string file is the string table
 *	cat'ed to the end of the built up a.out file
 */
FILE	*strfile;			/* interpass string file */
char	strfilename[TNAMESIZE];
int	strfilepos = 0;			/* position within the string file */
/*
E 11
 *	a.out is created during the second pass.
 *	It is opened by stdio, but is filled with the parallel
 *	block I/O library
 */
char	*outfile = "a.out";
FILE	*a_out_file;			
off_t	a_out_off;			/* cumulative offsets for segments */
/*
 *	The logical files containing the assembled data for each of
 *	the text and data segments are
 *	managed by the parallel block I/O library.
 *	a.out is logically opened in many places at once to
 *	receive the assembled data from the various segments as
 *	it all trickles in, but is physically opened only once
 *	to minimize file overhead.
 */
BFILE	*usefile[NLOC+NLOC];		/* text/data files */
BFILE	*txtfil;			/* current text/data file */
/*
 *	Relocation information is accumulated seperately for each
 *	segment.  This is required by the old loader (from BTL),
 *	but not by the new loader (Bill Joy).  
 *
 *	However, the size of the relocation information can not be computed
 *	during or after the 1st pass because the ''absoluteness' of values
 *	is unknown until all locally declared symbols have been seen.
 *	Thus, the size of the relocation information is only
 *	known after the second pass is finished.
 *	This obviates the use of the block I/O
 *	library, which requires knowing the exact offsets in a.out.
 *
 *	So, we save the relocation information internally (we don't
 *	go to internal files to minimize overhead).
 *
 *	Empirically, we studied 259 files composing the system,
 *	two compilers and a compiler generator: (all of which have
 *	fairly large source files)
 *	
 *	Number of files = 259
 *		Number of non zero text reloc files: 233
 *		Number of non zero data reloc files: 53
 *	Average text relocation = 889
 *	Average data relocation = 346
 *	Number of files > BUFSIZ text relocation = 71
 *	Number of files > BUFSIZ data relocation = 6
 *	
 *	For compiled C code, there is usually one text segment and two
 *	data segments; we see that allocating our own buffers and
 *	doing our internal handling of relocation information will,
 *	on the average, not use more memory than taken up by the buffers
 *	allocated for doing file I/O in parallel to a number of file.
 *	
 *	If we are assembling with the -V option, we
 *	use the left over token buffers from the 2nd pass,
 *	otherwise, we create our own.
 *
 *	When the 2nd pass is complete, closeoutrel flushes the token
 *	buffers out to a BFILE.
 *
 *	The internals to relbufdesc are known only in assyms.c
 *
 *	outrel constructs the relocation information.
 *	closeoutrel flushes the relocation information to relfil.
 */
struct	relbufdesc	*rusefile[NLOC+NLOC];	
struct	relbufdesc 	*relfil;	/* un concatnated relocation info */
BFILE	*relocfile;			/* concatnated relocation info */
/*
 *	Once the relocation information has been written,
 *	we can write out the symbol table using the Block I/O
 *	mechanisms, as we once again know the offsets into
 *	the a.out file.
 *
 *	We use relfil to output the symbol table information.
 */
D 12

char	*tmpdirprefix =
#ifdef UNIX
			"/tmp/";
#else VMS
			"/usr/tmp/";
#endif

D 11
#define		TMP_SUFFIX	"asXXXXXX"
char		tmpn1[TNAMESIZE];
E 11

E 12
I 12
char	*tmpdirprefix = "/tmp/";
E 12
int delexit();

main(argc, argv)
	int	argc;
	char 	**argv;
{
I 9
	char	*sbrk();
E 9

D 11
	tmpn1[0] = 0;
E 11
I 11
	tokfilename[0] = 0;
	strfilename[0] = 0;
E 11
D 9
	endcore = (char *)sbrk(0);
E 9
I 9
	endcore = sbrk(0);
E 9

	argprocess(argc, argv);		/* process argument lists */
	if (anyerrs) exit(1);

	initialize();
	zeroorigins();			/* set origins to zero */
	zerolocals();			/* fix local label counters */

	i_pass1();			/* open temp files, etc */
	pass1();			/* first pass through .s files */
	testlocals();			/* check for undefined locals */
	if (anyerrs) delexit();

	pass1_5();			/* resolve jxxx */
	if (anyerrs) delexit();

	open_a_out();			/* open a.out */
D 7
	roundsegments();		/* round segments to FW */
E 7
I 7
D 8
	roundsegments();		/* round segments to DW */
E 8
I 8
	roundsegments();		/* round segments to FW */
E 8
E 7
	build_hdr();			/* build initial header, and output */
	
	i_pass2();			/* reopen temporary file, etc */
	pass2();			/* second pass through the virtual .s */
	if (anyerrs) delexit();

D 7
	fillsegments();			/* fill segments with 0 to FW */
E 7
I 7
D 8
	fillsegments();			/* fill segments with 0 to DW */
E 8
I 8
	fillsegments();			/* fill segments with 0 to FW */
E 8
E 7
	reloc_syms();			/* dump relocation and symbol table */

	delete();			/* remove tmp file */
	bflush();			/* close off block I/O view of a.out */
	fix_a_out();			/* add in text and data reloc counts */

	if (anyerrs == 0 && orgwarn)
D 21
		yyerror("Caution: absolute origins.\n");
E 21
I 21
		yywarning("Caution: absolute origins.\n");
E 21
I 9

	if (nGHnumbers)
		yywarning("Caution: G or H format floating point numbers");
	if (nGHopcodes)
		yywarning("Caution: G or H format floating point operators");
	if (nnewopcodes)
		yywarning("Caution: New Opcodes");
	if (nGHnumbers || nGHopcodes || nnewopcodes)
		yywarning("These are not defined for all implementations of the VAX architecture.\n");

E 9
	exit(anyerrs != 0);
D 12
}	/*end of UNIX main*/
E 12
I 12
}
E 12

argprocess(argc, argv)
	int	argc;
	char	*argv[];
{
	register	char	*cp;

	ninfiles = 0;
	silent = 0;
#ifdef DEBUG
	debug = 0;
#endif
I 5
	innames = (char **)ClearCalloc(argc+1, sizeof (innames[0]));
E 5
	dotsname = "<argv error>";
	while (argc > 1) {
D 5
		if (argv[1][0] == '-'){
E 5
I 5
		if (argv[1][0] != '-')
			innames[ninfiles++] = argv[1];
		else {
E 5
			cp = argv[1] + 1;
			/*
			 *	We can throw away single minus signs, so
			 *	that make scripts for the PDP 11 assembler work
			 *	on this assembler too
			 */
			while (*cp){	
				switch(*cp++){
				 default:
					yyerror("Unknown flag: %c", *--cp);
					cp++;
					break;
I 10
				 case 'v':
					selfwhat(stdout);
					exit(1);
E 10
				 case 'd':
D 19
					d124 = *cp++ - '0';
					if ( (d124 != 1) && (d124 != 2) && 
					     (d124 != 4)){
						yyerror("-d[124] only");
E 19
I 19
D 20
					if (*cp++ != '4') {
						yyerror("only -d4 is supported now");
E 20
I 20
					d124 = *cp++ - '0';
					if ( (d124 != 1) && (d124 != 2) && 
					     (d124 != 4)){
						yyerror("-d[124] only");
E 20
E 19
I 14
						exit(1);
					}
					break;
				 case 'a':
					maxalign = atoi(cp+1);
					for (cp++; isdigit(*cp); cp++)
						/*VOID*/;
					if ( (maxalign > 16) || (maxalign < 0)){
						yyerror("-a: 0<=align<=16");
E 14
						exit(1);
					}
					break;
				 case 'o':
					if (argc < 3){
						yyerror("-o what???");
						exit(1);
					}
					outfile = argv[2];
				   bumpone:
					argc -= 2;
					argv += 2;
					goto nextarg;

				 case 't':
					if (argc < 3){
						yyerror("-t what???");
						exit(1);
					}
					tmpdirprefix = argv[2];
					goto bumpone;
				 
				 case 'V':
					useVM = 1;
					break;
				 case 'W':
					silent = 1;
					break;
				 case 'L':
					savelabels = 1;
					break;
I 3
				 case 'J':
D 19
					jxxxJUMP = 1;
E 19
I 19
					/*
					 * Ignore -J, we now have real
					 * relaxation!
					 */
E 19
					break;
E 3
#ifdef DEBUG
				 case 'D':
					debug = 1;
					break;
				 case 'T':
					toktrace = 1;
					break;
#endif
I 4
				 case 'R':
					readonlydata = 1;
					break;
E 4
				}	/*end of the switch*/
			}	/*end of pulling out all arguments*/
		}	/*end of a flag argument*/
D 5
		else {	/*file name*/
			if (ninfiles > 32){
				yyerror("More than 32 file names");
				exit(3);
			}
			innames[ninfiles++] = argv[1];
		}
E 5
		--argc; ++argv;
	   nextarg:;
	}
I 5
	/* innames[ninfiles] = 0; */
I 10
}
/*
 *	poke through the data space and find all sccs identifiers.
 *	We assume:
 *	a) that extern char **environ; is the first thing in the bss
 *	segment (true, if one is using the new version of cmgt.crt0.c)
 *	b) that the sccsid's have not been put into text space.
 */
selfwhat(place)
	FILE	*place;
{
	extern	char **environ;
	register	char	*ub;
	register	char *cp;
	register	char	*pat;
	char	*sbrk();

	for (cp = (char *)&environ, ub = sbrk(0); cp < ub; cp++){
		if (cp[0] != '@') continue;
		if (cp[1] != '(') continue;
		if (cp[2] != '#') continue;
		if (cp[3] != ')') continue;
		fputc('\t', place);
		for (cp += 4; cp < ub; cp++){
			if (*cp == 0) break;
			if (*cp == '>') break;
			if (*cp == '\n') break;
			fputc(*cp, place);
		}
		fputc('\n', place);
	}
E 10
E 5
}

initialize()
{
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, delexit);
	/*
	 *	Install symbols in the table
	 */
	symtabinit();
	syminstall();
	/*
	 *	Build the expression parser accelerator token sets
	 */
	buildtokensets();		
}

zeroorigins()
{
	register	int	locindex;
	/*
	 *	Mark usedot: the first NLOC slots are for named text segments,
	 *	the next for named data segments.
	 */
	for (locindex = 0; locindex < NLOC; locindex++){
D 2
		usedot[locindex].xtype = XTEXT;
		usedot[NLOC + locindex].xtype = XDATA;
		usedot[locindex].xvalue = 0;
		usedot[NLOC + locindex].xvalue = 0;
		usedot[locindex].yvalue = 0;
		usedot[NLOC + locindex].yvalue = 0;
E 2
I 2
		usedot[locindex].e_xtype = XTEXT;
		usedot[NLOC + locindex].e_xtype = XDATA;
		usedot[locindex].e_xvalue = 0;
		usedot[NLOC + locindex].e_xvalue = 0;
D 9
		usedot[locindex].e_yvalue = 0;
		usedot[NLOC + locindex].e_yvalue = 0;
E 9
E 2
	}
}

zerolocals()
{
	register	int	i;

	for (i = 0; i <= 9; i++) {
		lgensym[i] = 1;
		genref[i] = 0;
	}
}

i_pass1()
{
D 11
	if (useVM == 0){
		strcat(tmpn1, tmpdirprefix);
I 6
		if (tmpdirprefix[strlen(tmpdirprefix)-1] != '/')
			strcat(tmpn1, "/");
E 6
D 9
		strcat(tmpn1, TMP_SUFFIX);
		mktemp(tmpn1);
E 9
I 9
		(void)strcat(tmpn1, TMP_SUFFIX);
		(void)mktemp(tmpn1);
E 9
		tmpfil = fopen(tmpn1, "w");
		if (tmpfil==NULL) {
		  yyerror("Bad pass 1 temporary file for writing %s", tmpn1);
		  delexit();
		}
	}
E 11
I 11
	FILE	*tempopen();
	if (useVM == 0)
		tokfile = tempopen(tokfilename, "T");
	strfile = tempopen(strfilename, "S");
	/*
	 *	write out the string length.
	 *	This will be overwritten when the
	 *	strings are tacked onto the growing a.out file
	 */
	strfilepos = sizeof(int);
	fwrite(&strfilepos, sizeof(int), 1, strfile);
E 11

D 11
	inittmpfile();
E 11
I 11
	inittokfile();
E 11
I 3
D 19
	initijxxx();
E 19
E 3
}

I 11
FILE *tempopen(tname, part)
	char	*tname;
	char	*part;
{
	FILE	*file;
D 18
	sprintf(tname, "%s%sas%s%05d",
E 18
I 18
	(void)sprintf(tname, "%s%sas%s%05d",
E 18
		tmpdirprefix,
D 17
		(tmpdirprefix[strlen(tmpdirprefix)-1] != '/') ? "/" : 0,
E 17
I 17
		(tmpdirprefix[strlen(tmpdirprefix)-1] != '/') ? "/" : "",
E 17
		part,
		getpid());
	file = fopen(tname, "w");
	if (file == NULL) {
		yyerror("Bad pass 1 temporary file for writing %s", tname);
		delexit();
	}
	return(file);
}

E 11
pass1()
{
	register	int	i;

	passno = 1;
	dotp = &usedot[0];
	txtfil = (BFILE *)0;
	relfil = (struct relbufdesc *)0;

	if (ninfiles == 0){		/*take the input from stdin directly*/
		lineno = 1;
		dotsname = "<stdin>";

		yyparse();
	} else {		/*we have the names tanked*/
		for (i = 0; i < ninfiles; i++){
			new_dot_s(innames[i]);
			if (freopen(innames[i], "r", stdin) == NULL) {
				yyerror( "Can't open source file %s\n",
					innames[i]);
				exit(2);
			}
			/* stdio is NOT used to read the input characters */
			/* we use read directly, into our own buffers */
			yyparse();
		}
	}

D 11
	closetmpfile();		/*kick out the last buffered intermediate text*/
E 11
I 11
	closetokfile();		/*kick out the last buffered intermediate text*/
E 11
}

testlocals()
{
	register	int	i;
	for (i = 0; i <= 9; i++) {
		if (genref[i])
			yyerror("Reference to undefined local label %df", i);
		lgensym[i] = 1;
		genref[i] = 0;
	}
}

pass1_5()
{
	sortsymtab();
#ifdef DEBUG
	if (debug) dumpsymtab();
#endif
	jxxxfix();
#ifdef DEBUG
	if (debug) dumpsymtab();
#endif
}

open_a_out()
{
I 15
	struct stat stb;

E 15
	/*
	 *	Open up the a.out file now, and get set to build
	 *	up offsets into it for all of the various text,data
	 *	text relocation and data relocation segments.
	 */
	a_out_file = fopen(outfile, "w");
	if (a_out_file == NULL) {
		yyerror("Cannot create %s", outfile);
		delexit();
	}
	biofd = a_out_file->_file;
I 15
	fstat(biofd, &stb);
	biobufsize = stb.st_blksize;
E 15
	a_out_off = 0;
}

roundsegments()
{
	register	int	locindex;
	register	long	v;
	/*
	 *	round and assign text segment origins
	 *	the exec header always goes in usefile[0]
	 */
	tsize = 0;
	for (locindex=0; locindex<NLOC; locindex++) {
D 2
		v = round(usedot[locindex].xvalue, FW);
		usedot[locindex].xvalue = tsize;
E 2
I 2
D 7
		v = round(usedot[locindex].e_xvalue, FW);
E 7
I 7
D 8
		v = round(usedot[locindex].e_xvalue, DW);
E 8
I 8
		v = round(usedot[locindex].e_xvalue, FW);
E 8
E 7
		usedot[locindex].e_xvalue = tsize;
E 2
		if ((locindex == 0) || (v != 0) ){
			usefile[locindex] = (BFILE *)Calloc(1, sizeof(BFILE));
			bopen(usefile[locindex], a_out_off);
			if (locindex == 0)
				a_out_off = sizeof (struct exec);
		} else {
			usefile[locindex] = (BFILE *)-1;
		}
		tsize += v;
		a_out_off += v;
	}
	/*
	 *		Round and assign data segment origins.
	 */
D 4
	datbase = round(tsize, PAGRND);
E 4
I 4
D 7
	datbase = round(tsize, FW);
E 7
I 7
D 8
	datbase = round(tsize, DW);
E 8
I 8
	datbase = round(tsize, FW);
E 8
E 7
E 4
	for (locindex=0; locindex<NLOC; locindex++) {
D 2
		v = round(usedot[NLOC+locindex].xvalue, FW);
		usedot[NLOC+locindex].xvalue = datbase + dsize;
E 2
I 2
D 7
		v = round(usedot[NLOC+locindex].e_xvalue, FW);
E 7
I 7
D 8
		v = round(usedot[NLOC+locindex].e_xvalue, DW);
E 8
I 8
		v = round(usedot[NLOC+locindex].e_xvalue, FW);
E 8
E 7
		usedot[NLOC+locindex].e_xvalue = datbase + dsize;
E 2
		if (v != 0){
			usefile[NLOC + locindex] = (BFILE *)Calloc(1,sizeof(BFILE));
			bopen(usefile[NLOC + locindex], a_out_off);
		} else {
			usefile[NLOC + locindex] = (BFILE *)-1;
		}
		dsize += v;
		a_out_off += v;
	}
	/*
	 *	Assign final values to symbols
	 */
	hdr.a_bss = dsize;
	freezesymtab();		/* this touches hdr.a_bss */
	stabfix();
	/*
	 *	Set up the relocation information "files" to
	 *	be zero; outrel takes care of the rest
	 */
	for (locindex = 0; locindex < NLOC + NLOC; locindex++){
		rusefile[locindex] = (struct relbufdesc *)0;
	}
}

build_hdr()
{
	/*
	 *	Except for the text and data relocation sizes,
	 *	calculate the final values for the header
	 *	
	 *	Write out the initial copy; we to come 
	 *	back later and patch up a_trsize and a_drsize,
	 *	and overwrite this first version of the header.
	 */
	hdr.a_magic = MAGIC;
	hdr.a_text = tsize;
	hdr.a_data = dsize;
	hdr.a_bss -= dsize;
	hdr.a_syms = sizesymtab();	/* Does not include string pool length */
	hdr.a_entry = 0;
	hdr.a_trsize = 0;
	hdr.a_drsize = 0;

	bwrite((char *)&hdr, sizeof(hdr), usefile[0]);
}

i_pass2()
{
	if (useVM == 0) {
D 11
		fclose(tmpfil);
		tmpfil = fopen(tmpn1, "r");
		if (tmpfil==NULL) {
		   yyerror("Bad pass 2 temporary file for reading %s", tmpn1);
E 11
I 11
		fclose(tokfile);
		tokfile = fopen(tokfilename, "r");
		if (tokfile==NULL) {
		   yyerror("Bad pass 2 temporary file for reading %s", tokfilename);
E 11
		   delexit();
		}
	}
I 11
	fclose(strfile);
	strfile = fopen(strfilename, "r");
E 11
}

pass2()
{
#ifdef DEBUG
	if (debug)
		printf("\n\n\n\t\tPASS 2\n\n\n\n");
#endif DEBUG
	passno = 2;
	lineno = 1;
	dotp = &usedot[0];
	txtfil = usefile[0];	/* already opened (always!) */
	relfil = 0;		/* outrel takes care of the rest */
	initoutrel();

D 11
	inittmpfile();
E 11
I 11
	inittokfile();
E 11

	yyparse();

D 11
	closetmpfile();
E 11
I 11
	closetokfile();
E 11
}

fillsegments()
{
	int	locindex;
	/*
D 7
	 *	Round text and data segments to FW by appending zeros
E 7
I 7
D 8
	 *	Round text and data segments to DW by appending zeros
E 8
I 8
	 *	Round text and data segments to FW by appending zeros
E 8
E 7
	 */
	for (locindex = 0; locindex < NLOC + NLOC; locindex++) {
		if (usefile[locindex]) {
			txtfil = usefile[locindex];
			dotp = &usedot[locindex];
D 2
			while (usedot[locindex].xvalue & FW)
E 2
I 2
D 7
			while (usedot[locindex].e_xvalue & FW)
E 7
I 7
D 8
			while (usedot[locindex].e_xvalue & DW)
E 8
I 8
			while (usedot[locindex].e_xvalue & FW)
E 8
E 7
E 2
				outb(0);
		}
	}
}

reloc_syms()
{
	u_long	closerelfil();
	/*
	 *	Move the relocation information to a.out
	 *	a_out_off is the offset so far:
	 *	exec + text segments + data segments
	 */
	relocfile = (BFILE *)Calloc(1,sizeof(BFILE));
	bopen(relocfile, a_out_off);
	a_out_off += closeoutrel(relocfile);

	hdr.a_trsize = trsize;
	hdr.a_drsize = drsize;
I 4
	if (readonlydata) {
		hdr.a_text += hdr.a_data;
		hdr.a_data = 0;
		hdr.a_trsize += hdr.a_drsize;
		hdr.a_drsize = 0;
	}
E 4
	/*
D 13
	 *	Output the symbol table
	 *	and if FLEXNAMES is set, the string pool
E 13
I 13
	 *	Output the symbol table and the string pool
E 13
I 11
	 *
	 *	We must first rewind the string pool file to its beginning,
	 *	in case it was seek'ed into for fetching ascii and asciz
	 *	strings.
E 11
	 */
I 11
	fseek(strfile, 0, 0);
E 11
	symwrite(relocfile);
}

fix_a_out()
{
D 9
	if (lseek(a_out_file->_file, 0L, 0) < 0)
E 9
I 9
	if (lseek(a_out_file->_file, 0L, 0) < 0L)
E 9
		yyerror("Reposition for header rewrite fails");
	if (write(a_out_file->_file, (char *)&hdr, sizeof (struct exec)) < 0)
		yyerror("Rewrite of header fails");
}

delexit()
{
	delete();
	if (passno == 2){
		unlink(outfile);
	}
	exit(1);
}

delete()
{
D 11
	if (useVM == 0 || tmpn1[0])
		unlink(tmpn1);
E 11
I 11
	if (useVM == 0 || tokfilename[0])
		unlink(tokfilename);
	if (strfilename[0])
		unlink(strfilename);
E 11
}

sawabort()
{
	char	*fillinbuffer();
	while (fillinbuffer() != (char *)0)
		continue;
	delete();
	exit(1);	/*although the previous pass will also exit non zero*/
}

panic(fmt, a1, a2, a3, a4)
	char	*fmt;
	/*VARARGS 1*/
{
	yyerror("Assembler panic: bad internal data structure.");
	yyerror(fmt, a1, a2, a3, a4);
	delete();
	abort();
}
E 1
