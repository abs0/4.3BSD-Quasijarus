h36516
s 00003/00001/00178
d D 5.2 87/04/07 15:54:00 mckusick 8 7
c port to tahoe by Nir peleg of CCI
e
s 00014/00002/00165
d D 5.1 85/06/07 10:14:25 dist 7 6
c Add copyright
e
s 00000/00000/00167
d D 1.6 82/09/02 20:43:50 linton 6 5
c 
e
s 00000/00000/00167
d D 1.5 82/05/20 13:02:17 linton 5 4
c this is a test
e
s 00084/00083/00083
d D 1.4 82/05/19 20:36:11 linton 4 3
c added -i option
e
s 00060/00026/00106
d D 1.3 82/02/02 12:44:58 linton 3 2
c modified command line handling for invocation from pix, obj
e
s 00000/00004/00132
d D 1.2 82/01/19 00:10:49 linton 2 1
c prompts
e
s 00136/00000/00000
d D 1.1 82/01/18 19:20:28 linton 1 0
c date and time created 82/01/18 19:20:28 by linton
e
u
U
t
T
I 1
D 7
/* Copyright (c) 1982 Regents of the University of California */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 7

D 7
static char sccsid[] = "%Z%%M% %I% %G%";
E 7
I 7
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7

/*
 * Debugger main routine.
 */

#include "defs.h"
#include <setjmp.h>
#include <signal.h>
#include "main.h"
#include "command.h"
#include "process.h"
#include "object.h"

D 4
#define FIRST_TIME 0		/* initial value setjmp returns */
E 4
I 4
#define FIRST_TIME 0        /* initial value setjmp returns */
E 4
D 3
#define isinteractive()		(isatty(fileno(stdin)))
E 3

I 3
LOCAL int firstarg;
E 3
LOCAL jmp_buf env;
LOCAL catchintr();

main(argc, argv)
int argc;
char **argv;
{
D 4
	FILE *fp;
I 3
	int i;
E 4
I 4
    FILE *fp;
    int i;
E 4
E 3

D 3
	cmdname = argv[0];
E 3
D 4
	catcherrs();
I 3
	catchsigs();
E 3
	scanargs(argc, argv);
I 3
	cmdname = argv[0];
E 3
	if ((fp = fopen(objname, "r")) == NIL) {
		panic("can't read %s", objname);
E 4
I 4
D 8
    catcherrs();
E 8
I 8
#ifdef lint
    syserr();
#endif
E 8
    catchsigs();
    scanargs(argc, argv);
    cmdname = argv[0];
    if ((fp = fopen(objname, "r")) == NIL) {
	panic("can't read %s", objname);
    } else {
	fclose(fp);
    }
    if (option('r')) {
	if (setjmp(env) == FIRST_TIME) {
	    arginit();
	    for (i = firstarg; i < argc; i++) {
		newarg(argv[i]);
	    }
	    run();
	    /* NOTREACHED */
E 4
	} else {
D 4
		fclose(fp);
E 4
I 4
	    option('r') = FALSE;
E 4
	}
D 4
	if (option('r')) {
		if (setjmp(env) == FIRST_TIME) {
			arginit();
I 3
			for (i = firstarg; i < argc; i++) {
				newarg(argv[i]);
			}
E 3
			run();
			/* NOTREACHED */
		} else {
			option('r') = FALSE;
D 2
			if (isinteractive()) {
				printf("> ");
				fflush(stdout);
			}
E 2
		}
	} else {
D 3
		start(NIL, NIL, NIL);
E 3
I 3
		initstart();
E 3
		prompt();
		init();
	}
	setjmp(env);
D 3
	signal(SIGINT, &catchintr);
E 3
I 3
	signal(SIGINT, catchintr);
E 3
	yyparse();
	putchar('\n');
I 3
	quit(0);
E 4
I 4
    } else {
	initstart();
	prompt();
	init();
    }
    setjmp(env);
    signal(SIGINT, catchintr);
    yyparse();
    putchar('\n');
    quit(0);
E 4
E 3
}

/*
 * Initialize the world, including setting initial input file
 * if the file exists.
 */

init()
{
D 4
	initinput();
	readobj(objname);
	lexinit();
E 4
I 4
    initinput();
    readobj(objname);
    lexinit();
E 4
}

/*
 * After a non-fatal error we jump back to command parsing.
 */

erecover()
{
D 4
	gobble();
	prompt();
	longjmp(env, 1);
E 4
I 4
    gobble();
    prompt();
    longjmp(env, 1);
E 4
}

/*
 * This routine is called when an interrupt occurs.
 */

LOCAL catchintr()
{
D 4
	putchar('\n');
	prompt();
	longjmp(env, 1);
E 4
I 4
    putchar('\n');
    prompt();
    longjmp(env, 1);
E 4
}

/*
 * scan the argument list
 */

LOCAL scanargs(argc, argv)
int argc;
char **argv;
{
D 4
	register int i, j;
D 3
	BOOLEAN foundfile;
E 3
I 3
	BOOLEAN done;
E 4
I 4
    register int i, j;
    BOOLEAN done;
E 4
E 3

D 3
	foundfile = FALSE;
	for (i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			for (j = 1; argv[i][j] != '\0'; j++) {
				setoption(argv[i][j]);
			}
		} else if (!foundfile) {
			objname = argv[i];
E 3
I 3
D 4
	if (streq(argv[0], "pxhdr") || streq(argv[0], "pix")) {
		objname = argv[1];
		option('r') = TRUE;
		option('t') = TRUE;
		if (streq(argv[0], "pxhdr")) {
			setargs("pdx", argv[2]);
			firstarg = 3;
E 3
		} else {
D 3
			panic("extraneous argument %s", argv[i]);
E 3
I 3
			setargs("pix", NIL);
			firstarg = 2;
E 3
		}
I 3
		argv[0] = "pdx";
E 4
I 4
    if (streq(argv[0], "pxhdr") || streq(argv[0], "pix")) {
	objname = argv[1];
	option('r') = TRUE;
	option('t') = TRUE;
	if (streq(argv[0], "pxhdr")) {
	    setargs("pdx", argv[2]);
	    firstarg = 3;
E 4
	} else {
D 4
		done = FALSE;
		i = 1;
		while (i < argc && !done) {
			if (argv[i][0] == '-') {
				for (j = 1; argv[i][j] != '\0'; j++) {
					switch (argv[i][j]) {
						case 'r':	/* run program before accepting commands */
						case 'b':	/* (internal) trace breakpoints */
						case 'e':	/* (internal) trace execution */
						case 'h':	/* (internal) display header information */
							option(argv[i][j]) = TRUE;
							break;
E 4
I 4
	    setargs("pix", NIL);
	    firstarg = 2;
	}
	argv[0] = "pdx";
    } else {
	done = FALSE;
	i = 1;
	while (i < argc && !done) {
	    if (argv[i][0] == '-') {
		for (j = 1; argv[i][j] != '\0'; j++) {
		    switch (argv[i][j]) {
			case 'r':   /* run program before accepting commands */
			case 'i':   /* assume input is a terminal */
			case 'b':   /* (internal) trace breakpoints */
			case 'e':   /* (internal) trace execution */
			case 'h':   /* (internal) display header information */
			    option(argv[i][j]) = TRUE;
			    break;
E 4

D 4
					default:
						panic("bad option \"%c\"", argv[i]);
					}
				}
			} else {
				objname = argv[i];
				done = TRUE;
			}
			i++;
E 4
I 4
		    default:
			panic("bad option \"%c\"", argv[i]);
		    }
E 4
		}
D 4
		firstarg = i;
		setargs("pdx", objname);
E 4
I 4
	    } else {
		objname = argv[i];
		done = TRUE;
	    }
	    i++;
E 4
E 3
	}
I 4
	firstarg = i;
	setargs("pdx", objname);
    }
E 4
}

/*
D 3
 * take appropriate action for recognized command argument
E 3
I 3
 * Terminate program.  In the case of the -t option, we must remove
 * the object file because it's a tmp file.
E 3
 */

D 3
LOCAL setoption(c)
register char c;
E 3
I 3
quit(r)
int r;
E 3
{
D 3
	switch(c) {
		case 'r':	/* run program before accepting commands */
		case 'b':	/* trace internal breakpoints (for debugging) */
		case 'e':	/* trace execution (for debugging) */
			option(c) = TRUE;
			break;

		default:
			panic("unknown option '%c'", c);
E 3
I 3
D 4
	if (option('t')) {
		unlink(objname);
E 3
	}
I 3
	exit(r);
E 4
I 4
    if (option('t')) {
	unlink(objname);
    }
    exit(r);
E 4
}

LOCAL catchsigs()
{
D 4
	signal(SIGHUP, quit);
	signal(SIGQUIT, quit);
E 4
I 4
    signal(SIGHUP, quit);
    signal(SIGQUIT, quit);
E 4
E 3
}
E 1
