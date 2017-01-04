h56822
s 00092/00042/00390
d D 5.4 88/01/12 00:46:10 donn 17 16
c merge in latest Linton version
e
s 00069/00092/00363
d D 5.3 87/05/01 16:32:05 bostic 16 15
c fix argument processing
e
s 00001/00000/00454
d D 5.2 86/02/22 23:08:25 sam 15 14
c introduce routine for initializing op code table
e
s 00014/00002/00440
d D 5.1 85/05/31 10:04:37 dist 14 13
c Add copyright
e
s 00067/00028/00375
d D 1.11 85/03/01 20:25:22 linton 13 12
c update to version 3.0
e
s 00021/00003/00382
d D 1.10 84/12/18 10:01:17 ralph 12 11
c save & restore all tty settings
e
s 00000/00002/00385
d D 1.9 84/09/17 10:58:05 ralph 11 9
c don't call setbuf.
e
s 00000/00000/00387
d R 1.9 84/09/17 10:56:24 ralph 10 9
c don't call setbuf.
e
s 00009/00006/00378
d D 1.8 84/08/12 13:20:49 sam 9 8
c remove stty/gtty (so can type ahead); line buffer stderr; changes for aliases
e
s 00001/00003/00383
d D 1.7 84/06/23 11:41:34 sam 8 6
i 7
c merge linton branch delta trail
e
s 00021/00009/00365
d D 1.6.1.1 84/06/23 10:47:30 sam 7 6
c branch delta of linton changes from net.sources
e
s 00002/00001/00372
d D 1.6 83/08/16 02:18:58 linton 6 5
c added call to "symbols_init", and fixed problem with argument 
c scanning that had dbx checking past "-r file" and therefore looking at 
c the processes arguments, possibly complaining
e
s 00007/00001/00366
d D 1.5 83/05/17 23:00:39 linton 5 4
c changed way curfunc is set to handle core dumps appropriately
e
s 00033/00000/00334
d D 1.4 83/04/08 01:23:05 linton 4 3
c prints some more information before prompting now
e
s 00001/00001/00333
d D 1.3 83/01/23 16:30:23 linton 3 2
c fixed recognizing of core dump arguments
e
s 00001/00001/00333
d D 1.2 82/12/15 04:20:47 linton 2 1
c fixed @(#) stuff
e
s 00334/00000/00000
d D 1.1 82/12/15 04:07:55 linton 1 0
c date and time created 82/12/15 04:07:55 by linton
e
u
U
f b 
t
T
I 1
D 14
/* Copyright (c) 1982 Regents of the University of California */
E 14
I 14
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 14

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 7
static char sccsid[] = "%Z%%M% %I% %G%";
E 7
I 7
D 8
static char sccsid[] = "@(#)main.c 1.5 5/17/83";
E 7
E 2

I 7
static char rcsid[] = "$Header: main.c,v 1.3 84/03/27 10:21:40 linton Exp $";
E 8
I 8
D 14
static	char sccsid[] = "%W% (Berkeley) %G%";
E 14
I 14
#ifndef lint
char copyright[] =
D 17
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 17
I 17
"@(#) Copyright (c) 1983 Regents of the University of California.\n\
E 17
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 14
E 8

I 13
D 17
static char rcsid[] = "$Header: main.c,v 1.5 84/12/26 10:40:16 linton Exp $";
E 17
I 17
static char rcsid[] = "$Header: main.c,v 1.4 87/07/08 21:31:27 donn Exp $";
E 17

E 13
E 7
/*
 * Debugger main routine.
 */

#include "defs.h"
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include "main.h"
I 17
#include "tree.h"
E 17
I 13
#include "eval.h"
#include "debug.h"
E 13
I 5
#include "symbols.h"
E 5
#include "scanner.h"
I 13
#include "keywords.h"
E 13
#include "process.h"
I 7
#include "runtime.h"
E 7
#include "source.h"
#include "object.h"
I 5
#include "mappings.h"
I 13
#include "coredump.h"
E 13
E 5

#ifndef public

#define isterm(file)	(interactive or isatty(fileno(file)))

I 4
D 17
#include <sgtty.h>
I 12
#include <fcntl.h>
E 17
I 17
#ifdef IRIS
#   include <termio.h>
E 17
E 12

D 12
typedef struct sgttyb Ttyinfo;
E 12
I 12
D 17
typedef struct {
D 13
	struct sgttyb	sg;		/* standard sgttyb structure */
	struct tchars	tc;		/* terminal characters */
	struct ltchars	ltc;		/* local special characters */
	int		ldisc;		/* line discipline */
	int		local;		/* TIOCLGET */
	int		fcflags;	/* fcntl(2) F_GETFL, F_SETFL */
E 13
I 13
    struct sgttyb sg;		/* standard sgttyb structure */
    struct tchars tc;		/* terminal characters */
    struct ltchars ltc;		/* local special characters */
    integer ldisc;		/* line discipline */
    integer local;		/* TIOCLGET */
    integer fcflags;		/* fcntl(2) F_GETFL, F_SETFL */
E 13
} Ttyinfo;
E 17
I 17
    typedef struct termio Ttyinfo;
#else
#   include <sgtty.h>
#   include <fcntl.h>
E 17
E 12

I 17
    typedef struct {
	struct sgttyb sg;		/* standard sgttyb structure */
	struct tchars tc;		/* terminal characters */
	struct ltchars ltc;		/* local special characters */
	integer ldisc;			/* line discipline */
	integer local;			/* TIOCLGET */
	integer fcflags;		/* fcntl(2) F_GETFL, F_SETFL */
    } Ttyinfo;
E 17
E 4
#endif

I 17
#endif

E 17
D 13
public Boolean coredump;		/* true if using a core dump */
public Boolean runfirst;		/* run program immediately */
public Boolean interactive;		/* standard input IS a terminal */
public Boolean lexdebug;		/* trace yylex return values */
public Boolean tracebpts;		/* trace create/delete breakpoints */
public Boolean traceexec;		/* trace process execution */
public Boolean tracesyms;		/* print symbols as their read */
I 7
public Boolean traceblocks;		/* trace blocks while reading symbols */
E 13
I 13
public boolean coredump;		/* true if using a core dump */
public boolean runfirst;		/* run program immediately */
public boolean interactive;		/* standard input IS a terminal */
public boolean lexdebug;		/* trace scanner return values */
public boolean tracebpts;		/* trace create/delete breakpoints */
public boolean traceexec;		/* trace execution */
public boolean tracesyms;		/* print symbols are they are read */
public boolean traceblocks;		/* trace blocks while reading symbols */
public boolean vaddrs;			/* map addresses through page tables */
I 17
public boolean quiet;			/* don't print heading */
public boolean autostrip;		/* strip C++ prefixes */
E 17
E 13
E 7

public File corefile;			/* File id of core dump */

I 17
public integer versionNumber = 4;

E 17
#define FIRST_TIME 0			/* initial value setjmp returns */

private Boolean initdone = false;	/* true if initialization done */
private jmp_buf env;			/* setjmp/longjmp data */
I 13
private char outbuf[BUFSIZ];		/* standard output buffer */
E 13
D 11
private char outbuf[BUFSIZ];		/* standard output buffer */
E 11
private char namebuf[512];		/* possible name of object file */
D 16
private int firstarg;			/* first program argument (for -r) */
E 16

I 4
private Ttyinfo ttyinfo;
I 13
private String corename;		/* name of core file */
E 13

E 4
private catchintr();
I 17
private char **scanargs();
E 17

/*
 * Main program.
 */

main(argc, argv)
int argc;
String argv[];
{
D 7
    register Integer i;
E 7
I 7
D 17
    register integer i;
E 7
I 4
    extern String date;
E 17
I 7
    extern integer versionNumber;
I 16
    char **scanargs();
E 16
E 7
E 4

D 16
    cmdname = argv[0];
E 16
I 16
    if (!(cmdname = rindex(*argv, '/')))
	cmdname = *argv;
    else
	++cmdname;

E 16
    catcherrs();
    onsyserr(EINTR, nil);
I 17
    onsyserr(EADDRINUSE, nil);
    onsyserr(ENXIO, nil);
E 17
D 11
    setbuf(stdout, outbuf);
E 11
I 9
D 13
    setlinebuf(stderr);
E 9
I 4
D 7
    printf("dbx version of %s.\nType 'help' for help.\n", date);
E 7
I 7
    printf("dbx version %d of %s.\nType 'help' for help.\n",
E 13
I 13
    setbuf(stdout, outbuf);
D 17
    printf("dbx version 3.%d of %s.\nType 'help' for help.\n",
E 13
	versionNumber, date);
E 7
    fflush(stdout);
E 17
E 4
D 16
    scanargs(argc, argv);
E 16
I 16
    argv = scanargs(argc, argv);
I 17
    if (not runfirst and not quiet) {
	printheading();
    }
    openfiles();
E 17
E 16
    language_init();
I 13
    symbols_init();
E 13
I 6
D 7
    symbols_init();
E 7
E 6
    process_init();
I 15
    optab_init();
E 15
    if (runfirst) {
	if (setjmp(env) == FIRST_TIME) {
	    arginit();
D 16
	    for (i = firstarg; i < argc; i++) {
		newarg(argv[i]);
	    }
E 16
I 16
	    while (*argv)
		newarg(*argv++);
E 16
	    run();
	    /* NOTREACHED */
	} else {
	    runfirst = false;
	}
    } else {
	init();
    }
D 7
    setjmp(env);
I 4
    restoretty(stdout, &ttyinfo);
E 7
I 7
    if (setjmp(env) != FIRST_TIME) {
	restoretty(stdout, &ttyinfo);
    }
E 7
E 4
    signal(SIGINT, catchintr);
I 9
D 13
    if (isterm(stdin)) {
	    printf("(%s) ", cmdname);
	    fflush(stdout);
    }
    endshellmode();		/* after an error longjmp */
    startaliasing();
E 13
E 9
    yyparse();
    putchar('\n');
    quit(0);
}

I 17
public printheading ()
{
    extern String date;

    printf("dbx version 3.%d of %s.\nType 'help' for help.\n",
	versionNumber, date
    );
    fflush(stdout);
}

E 17
/*
 * Initialize the world, including setting initial input file
 * if the file exists.
 */

public init()
{
    File f;
    String home;
    char buf[100];
    extern String getenv();

I 4
    savetty(stdout, &ttyinfo);
E 4
    enterkeywords();
    scanner_init();
    if (not coredump and not runfirst) {
	start(nil, nil, nil);
    }
I 4
    printf("reading symbolic information ...");
    fflush(stdout);
E 4
    readobj(objname);
I 4
    printf("\n");
    fflush(stdout);
E 4
D 5
    curfunc = program;
E 5
I 5
    if (coredump) {
I 13
	printf("[using memory image in %s]\n", corename);
	if (vaddrs) {
	    coredump_getkerinfo();
	}
I 17
	getsrcpos();
E 17
E 13
D 7
	curfunc = whatblock(pc);
E 7
I 7
	setcurfunc(whatblock(pc));
E 7
    } else {
D 7
	curfunc = program;
E 7
I 7
	setcurfunc(program);
E 7
    }
E 5
    bpinit();
    f = fopen(initfile, "r");
    if (f != nil) {
	fclose(f);
	setinput(initfile);
    } else {
	home = getenv("HOME");
	if (home != nil) {
	    sprintf(buf, "%s/%s", home, initfile);
	    f = fopen(buf, "r");
	    if (f != nil) {
		fclose(f);
		setinput(strdup(buf));
	    }
	}
    }
    initdone = true;
}

/*
 * Re-initialize the world, first de-allocating all storage.
 * This is necessary when the symbol information must be re-read
 * from the object file when it has changed.
 *
 * Before "forgetting" things, we save the current tracing/breakpoint
 * information to a temp file.  Then after re-creating the world,
 * we read the temp file as commands.  This isn't always the right thing;
 * if a procedure that was being traced is deleted, an error message
 * will be generated.
 *
 * If the argument vector is not nil, then this is re-initialize is being
 * done in preparation for running the program.  Since we want to process
 * the commands in the temp file before running the program, we add the
 * run command at the end of the temp file.  In this case, reinit longjmps
 * back to parsing rather than returning.
 */

public reinit(argv, infile, outfile)
String *argv;
String infile;
String outfile;
{
    register Integer i;
    String tmpfile;
    extern String mktemp();

    tmpfile = mktemp("/tmp/dbxXXXX");
    setout(tmpfile);
    status();
D 13
    print_alias(nil);
E 13
I 13
    alias(nil, nil, nil);
E 13
    if (argv != nil) {
	printf("run");
	for (i = 1; argv[i] != nil; i++) {
	    printf(" %s", argv[i]);
	}
	if (infile != nil) {
	    printf(" < %s", infile);
	}
	if (outfile != nil) {
	    printf(" > %s", outfile);
	}
	putchar('\n');
    }
    unsetout();
    bpfree();
    objfree();
I 13
    symbols_init();
E 13
    process_init();
    enterkeywords();
    scanner_init();
    readobj(objname);
    bpinit();
    fflush(stdout);
    setinput(tmpfile);
    unlink(tmpfile);
    if (argv != nil) {
	longjmp(env, 1);
	/* NOTREACHED */
    }
}

/*
D 13
 * After a non-fatal error we jump back to command parsing.
E 13
I 13
 * After a non-fatal error we skip the rest of the current input line, and
 * jump back to command parsing.
E 13
 */

public erecover()
{
    if (initdone) {
	gobble();
	longjmp(env, 1);
    }
}

/*
 * This routine is called when an interrupt occurs.
 */

private catchintr()
{
I 13
    if (isredirected()) {
	fflush(stdout);
	unsetout();
    }
E 13
    putchar('\n');
    longjmp(env, 1);
}

/*
 * Scan the argument list.
 */

D 16
private scanargs(argc, argv)
E 16
I 16
D 17
private char **scanargs(argc, argv)
E 17
I 17
private char **scanargs (argc, argv)
E 17
E 16
int argc;
String argv[];
{
I 16
    extern char *optarg;
D 17
    extern int optind;
E 16
    register int i, j;
    register Boolean foundfile;
    register File f;
I 16
    int ch;
E 16
    char *tmp;
E 17
I 17
    extern integer optind;
    integer ch;
E 17

    runfirst = false;
    interactive = false;
    lexdebug = false;
    tracebpts = false;
    traceexec = false;
    tracesyms = false;
I 7
    traceblocks = false;
I 13
    vaddrs = false;
E 13
E 7
D 17
    foundfile = false;
E 17
I 17
    quiet = false;
    autostrip = true;
E 17
    corefile = nil;
    coredump = true;
    sourcepath = list_alloc();
    list_append(list_item("."), nil, sourcepath);
D 16
    i = 1;
D 3
    while (i < argc and not foundfile and corefile == nil) {
E 3
I 3
D 6
    while (i < argc and (not foundfile or corefile == nil)) {
E 6
I 6
D 7
    while (i < argc and (not foundfile or (corefile == nil and not runfirst))) {
E 7
I 7
D 13
    while (i < argc and (not foundfile or corefile == nil)) {
E 13
I 13
    while (i < argc and (not foundfile or (coredump and corefile == nil))) {
E 13
E 7
E 6
E 3
	if (argv[i][0] == '-') {
	    if (streq(argv[i], "-I")) {
		++i;
		if (i >= argc) {
		    fatal("missing directory for -I");
		}
		list_append(list_item(argv[i]), nil, sourcepath);
I 13
	    } else if (streq(argv[i], "-c")) {
		++i;
		if (i >= argc) {
		    fatal("missing command file name for -c");
		}
		initfile = argv[i];
E 13
	    } else {
		for (j = 1; argv[i][j] != '\0'; j++) {
		    setoption(argv[i][j]);
		}
	    }
	} else if (not foundfile) {
	    objname = argv[i];
	    foundfile = true;
	} else if (coredump and corefile == nil) {
	    corefile = fopen(argv[i], "r");
I 13
	    corename = argv[i];
E 13
	    if (corefile == nil) {
E 16
I 16

D 17
    while ((ch = getopt(argc, argv, "I:bc:eiklnrs")) != EOF)
E 17
I 17
    while ((ch = getopt(argc, argv, "I:abc:eiklnqrs")) != EOF)
E 17
    switch((char)ch) {
	case 'I':
		list_append(list_item(optarg), nil, sourcepath);
		break;
I 17
	case 'a':
		autostrip = false;
		break;
E 17
	case 'b':
		tracebpts = true;
		break;
	case 'c':
		initfile = optarg;
		break;
	case 'e':
		traceexec = true;
		break;
	case 'i':
		interactive = true;
		break;
	case 'k':
		vaddrs = true;
		break;
	case 'l':
#ifdef LEXDEBUG
		lexdebug = true;
#else
		fatal("\"-l\" only applicable when compiled with LEXDEBUG");
#endif
		break;
	case 'n':
		traceblocks = true;
		break;
I 17
	case 'q':
		quiet = true;
		break;
E 17
	case 'r':	/* run program before accepting commands */
		runfirst = true;
E 16
		coredump = false;
D 16
	    }
E 16
I 16
		break;
	case 's':
		tracesyms = true;
		break;
	case '?':
	default:
		fatal("unknown option");
    }
    argv += optind;
    if (*argv) {
	objname = *argv;
D 17
	foundfile = true;
E 17
	if (*++argv && coredump) {
		corename = *argv;
		corefile = fopen(*argv, "r");
		if (corefile == nil)
			coredump = false;
		++argv;
E 16
	}
D 16
	++i;
E 16
    }
D 16
    if (i < argc and not runfirst) {
	fatal("extraneous argument %s", argv[i]);
    }
    firstarg = i;
E 16
I 16
D 17
    if (*argv and not runfirst)
E 17
I 17
    if (*argv and not runfirst) {
E 17
	fatal("extraneous argument %s", *argv);
E 16
D 17
    if (not foundfile and isatty(0)) {
E 17
I 17
    }
    return argv;
}

private openfiles ()
{
    File f;
    char *tmp;

    if (objname == nil and isatty(0)) {
E 17
	printf("enter object file name (default is `%s'): ", objname);
	fflush(stdout);
	gets(namebuf);
	if (namebuf[0] != '\0') {
	    objname = namebuf;
	}
    }
    f = fopen(objname, "r");
    if (f == nil) {
	fatal("can't read %s", objname);
    } else {
	fclose(f);
    }
    if (rindex(objname, '/') != nil) {
	tmp = strdup(objname);
	*(rindex(tmp, '/')) = '\0';
	list_append(list_item(tmp), nil, sourcepath);
    }
    if (coredump and corefile == nil) {
D 13
	corefile = fopen("core", "r");
	if (corefile == nil) {
	    coredump = false;
E 13
I 13
	if (vaddrs) {
D 16
	    corefile = fopen("/dev/mem", "r");
E 16
	    corename = "/dev/mem";
I 16
	    corefile = fopen(corename, "r");
E 16
	    if (corefile == nil) {
		panic("can't open /dev/mem");
	    }
	} else {
D 16
	    corefile = fopen("core", "r");
E 16
	    corename = "core";
I 16
	    corefile = fopen(corename, "r");
E 16
	    if (corefile == nil) {
		coredump = false;
	    }
E 13
	}
    }
D 16
}

/*
 * Take appropriate action for recognized command argument.
 */

private setoption(c)
char c;
{
    switch (c) {
	case 'r':   /* run program before accepting commands */
	    runfirst = true;
	    coredump = false;
	    break;

	case 'i':
	    interactive = true;
	    break;

	case 'b':
	    tracebpts = true;
	    break;

	case 'e':
	    traceexec = true;
	    break;

	case 's':
	    tracesyms = true;
	    break;

I 7
	case 'n':
	    traceblocks = true;
	    break;

I 13
	case 'k':
	    vaddrs = true;
	    break;

E 13
E 7
	case 'l':
I 13
#   	    ifdef LEXDEBUG
E 13
D 9
#   	    ifdef LEXDEBUG
E 9
		lexdebug = true;
I 13
#	    else
		fatal("\"-l\" only applicable when compiled with LEXDEBUG");
#	    endif
E 13
D 9
#	    else
		fatal("\"-l\" only applicable when compiled with LEXDEBUG");
#	    endif
E 9
	    break;

	default:
	    fatal("unknown option '%c'", c);
    }
E 16
I 16
D 17
    return(argv);
E 17
E 16
I 4
}

/*
 * Save/restore the state of a tty.
 */

public savetty(f, t)
File f;
Ttyinfo *t;
{
D 9
    gtty(fileno(f), t);
E 9
I 9
D 12
    ioctl(fileno(f), TIOCGETP, t);
E 12
I 12
D 17
    ioctl(fileno(f), TIOCGETP, &(t->sg));
    ioctl(fileno(f), TIOCGETC, &(t->tc));
    ioctl(fileno(f), TIOCGLTC, &(t->ltc));
    ioctl(fileno(f), TIOCGETD, &(t->ldisc));
    ioctl(fileno(f), TIOCLGET, &(t->local));
    t->fcflags = fcntl(fileno(f), F_GETFL, 0);
E 17
I 17
#   ifdef IRIS
	ioctl(fileno(f), TCGETA, t);
#   else
	ioctl(fileno(f), TIOCGETP, &(t->sg));
	ioctl(fileno(f), TIOCGETC, &(t->tc));
	ioctl(fileno(f), TIOCGLTC, &(t->ltc));
	ioctl(fileno(f), TIOCGETD, &(t->ldisc));
	ioctl(fileno(f), TIOCLGET, &(t->local));
	t->fcflags = fcntl(fileno(f), F_GETFL, 0);
	if ((t->fcflags&FASYNC) != 0) {
	    /* fprintf(stderr, "[async i/o found set -- reset]\n"); */
	    t->fcflags &= ~FASYNC;
	}
#   endif
E 17
E 12
E 9
}

public restoretty(f, t)
File f;
Ttyinfo *t;
{
D 9
    stty(fileno(f), t);
E 9
I 9
D 12
    ioctl(fileno(f), TIOCSETN, t);
E 12
I 12
D 17
    ioctl(fileno(f), TIOCSETN, &(t->sg));
    ioctl(fileno(f), TIOCSETC, &(t->tc));
    ioctl(fileno(f), TIOCSLTC, &(t->ltc));
    ioctl(fileno(f), TIOCSETD, &(t->ldisc));
    ioctl(fileno(f), TIOCLSET, &(t->local));
    (void) fcntl(fileno(f), F_SETFL, t->fcflags);
E 17
I 17
#   ifdef IRIS
	ioctl(fileno(f), TCSETA, t);
#   else
	ioctl(fileno(f), TIOCSETN, &(t->sg));
	ioctl(fileno(f), TIOCSETC, &(t->tc));
	ioctl(fileno(f), TIOCSLTC, &(t->ltc));
	ioctl(fileno(f), TIOCSETD, &(t->ldisc));
	ioctl(fileno(f), TIOCLSET, &(t->local));
	if ((t->fcflags&FASYNC) != 0) {
	    /* fprintf(stderr, "[async i/o not set]\n"); */
	    t->fcflags &= ~FASYNC;
	}
	(void) fcntl(fileno(f), F_SETFL, t->fcflags);
#   endif
E 17
E 12
E 9
E 4
}

/*
 * Exit gracefully.
 */

public quit(r)
Integer r;
{
I 7
    pterm(process);
E 7
    exit(r);
}
E 1
