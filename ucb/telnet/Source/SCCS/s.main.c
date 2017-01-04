h49364
s 00002/00000/00113
d D 1.6 88/05/15 12:46:54 minshall 6 5
c Make tn3270 work.
e
s 00022/00000/00091
d D 1.5 88/03/08 10:30:51 bostic 5 4
c add Berkeley specific copyright
e
s 00002/00000/00089
d D 1.4 87/10/23 15:15:36 minshall 4 3
c Try to move system dependent stuff to system dependent files.
e
s 00004/00000/00085
d D 1.3 87/10/10 14:27:12 minshall 3 2
c This is the first version to get near rings.  It compiles,
c but doesn't work.
e
s 00000/00012/00085
d D 1.2 87/09/25 14:47:28 minshall 2 1
c The right things in the right place.
e
s 00097/00000/00000
d D 1.1 87/09/11 15:40:39 minshall 1 0
c date and time created 87/09/11 15:40:39 by minshall
e
u
U
t
T
I 5
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 5
I 3
#include <sys/types.h>

#include "ring.h"

E 3
I 1
#include "externs.h"
#include "defines.h"

/*
 * Initialize variables.
 */

void
tninit()
{
D 2
#if	defined(TN3270)
    Sent3270TerminalType = 0;
    Ifrontp = Ibackp = Ibuf;
#endif	/* defined(TN3270) */

E 2
    init_terminal();

    init_network();
    
    init_telnet();
I 4

    init_sys();
I 6

    init_3270();
E 6
E 4
D 2

#if	defined(TN3270)
    init_ctlr();		/* Initialize some things */
    init_keyboard();
    init_screen();
    init_system();
#endif	/* defined(TN3270) */
E 2
}


/*
 * main.  Parse arguments, invoke the protocol or command parser.
 */


void
main(argc, argv)
	int argc;
	char *argv[];
{
    tninit();		/* Clear out things */

    TerminalSaveState();

    prompt = argv[0];
    while ((argc > 1) && (argv[1][0] == '-')) {
	if (!strcmp(argv[1], "-d")) {
	    debug = 1;
	} else if (!strcmp(argv[1], "-n")) {
	    if ((argc > 1) && (argv[2][0] != '-')) {	/* get file name */
		NetTrace = fopen(argv[2], "w");
		argv++;
		argc--;
		if (NetTrace == NULL) {
		    NetTrace = stdout;
		}
	    }
	} else {
#if	defined(TN3270) && defined(unix)
	    if (!strcmp(argv[1], "-t")) {
		if ((argc > 1) && (argv[2][0] != '-')) { /* get file name */
		    transcom = tline;
		    (void) strcpy(transcom, argv[1]);
		    argv++;
		    argc--;
		}
	    } else if (!strcmp(argv[1], "-noasynch")) {
		noasynch = 1;
	    } else
#endif	/* defined(TN3270) && defined(unix) */
	    if (argv[1][1] != '\0') {
		fprintf(stderr, "Unknown option *%s*.\n", argv[1]);
	    }
	}
	argc--;
	argv++;
    }
    if (argc != 1) {
	if (setjmp(toplevel) != 0)
	    Exit(0);
	tn(argc, argv);
    }
    setjmp(toplevel);
    for (;;) {
#if	!defined(TN3270)
	command(1);
#else	/* !defined(TN3270) */
	if (!shell_active) {
	    command(1);
	} else {
#if	defined(TN3270)
	    shell_continue();
#endif	/* defined(TN3270) */
	}
#endif	/* !defined(TN3270) */
    }
}
E 1
