h49361
s 00011/00005/00203
d D 5.3 88/01/22 00:30:19 donn 8 7
c Fixes for '#ifndef file_h' -- trim off the path prefix and translate all
c the dots to underscores, in the event there is more than one.
e
s 00027/00006/00181
d D 5.2 88/01/12 00:53:41 donn 7 6
c merge in latest Linton version
e
s 00014/00002/00173
d D 5.1 85/05/31 10:05:18 dist 6 5
c Add copyright
e
s 00002/00000/00173
d D 1.4 85/03/01 20:25:41 linton 5 4
c update to version 3.0
e
s 00001/00003/00172
d D 1.3 84/06/23 11:41:41 sam 4 2
i 3
c merge linton branch delta trail
e
s 00003/00001/00172
d D 1.2.1.1 84/06/23 10:47:39 sam 3 2
c branch delta of linton changes from net.sources
e
s 00001/00001/00172
d D 1.2 82/12/15 04:20:53 linton 2 1
c fixed @(#) stuff
e
s 00173/00000/00000
d D 1.1 82/12/15 04:07:59 linton 1 0
c date and time created 82/12/15 04:07:59 by linton
e
u
U
f b 
t
T
I 1
D 6
/* Copyright (c) 1982 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 3
static char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
D 4
static char sccsid[] = "@(#)makedefs.c 1.2 12/15/82";

static char rcsid[] = "$Header: makedefs.c,v 1.3 84/03/27 10:21:50 linton Exp $";
E 4
I 4
D 6
static	char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
#ifndef lint
char copyright[] =
D 7
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 7
I 7
"@(#) Copyright (c) 1983 Regents of the University of California.\n\
E 7
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
E 4
E 3
E 2

I 5
D 7
static char rcsid[] = "$Header: makedefs.c,v 1.4 84/12/26 10:40:22 linton Exp $";
E 7
I 7
static char rcsid[] = "$Header: makedefs.c,v 1.2 87/03/26 19:14:02 donn Exp $";
E 7

E 5
/*
 * Create a definitions file (e.g. .h) from an implementation file (e.g. .c).
 *
 * Usage is "makedefs source.c source.h" where source.h is to be created.
 *
 * Lines beginning with "public" or within a "#ifndef public ... #endif"
 * block are copied to the new file.  Initializations (e.g. "int x = 3") are
 * omitted ("int x;" is output).
 *
 * Normally a temporary definitions file is created and compared to
 * the given destination.  If they are different, the temporary file
 * is copied on top of the destination.  This is so that dependencies
 * when using "make" are not triggered.
 *
 * The "-f" option overrides this and forces the destination file to be created.
 */

#include "defs.h"
#include <signal.h>

#define procedure void

I 7
#define streqn(s1, s2, n) (strncmp(s1, s2, n) == 0)

E 7
Boolean force;
Boolean copytext;

String tmpname;
String modulename();
procedure abnorm();

main(argc, argv)
int argc;
String argv[];
{
    extern String mktemp();
    String name;
    File tmp;
    Integer r;
    Integer index;

    if (streq(argv[1], "-f")) {
	force = true;
	index = 2;
    } else {
	force = false;
	index = 1;
    }
    if (argc - index > 2) {
	fatal("usage: makedefs [ -f ] file.c [ file.h ]\n");
    }
    tmp = nil;
    if (freopen(argv[index], "r", stdin) == NULL) {
	fatal("can't read %s", argv[index]);
    }
    signal(SIGINT, abnorm);
    signal(SIGQUIT, abnorm);
    if (index + 1 < argc) {
	if (force) {
	    tmpname = argv[index + 1];
	} else {
	    tmpname = mktemp("/tmp/makedefsXXXXXX");
	}
	tmp = freopen(tmpname, "w", stdout);
	if (tmp == nil) {
	    fatal("can't write %s", tmpname);
	}
    }
    copytext = false;
    name = modulename(argv[index]);
    printf("#ifndef %s\n", name);
    printf("#define %s\n", name);
    copy();
    printf("#endif\n");
    if (tmp != NULL and not force) {
	fclose(tmp);
	r = call("cmp", stdin, stderr, "-s", tmpname, argv[2], nil);
	if (r != 0) {
	    r = call("cp", stdin, stderr, tmpname, argv[2], nil);
	    if (r != 0) {
		fprintf(stderr, "can't create %s\n", argv[2]);
	    }
	}
	unlink(tmpname);
    }
    quit(0);
}

String modulename(s)
String s;
{
    String r, i, j;
    static char buf[256];

    strcpy(buf, s);
    i = rindex(buf, '/');
    if (i == nil) {
	i = buf;
I 8
    } else {
	++i;
E 8
    }
D 8
    for (j = i; *j != '.'; j++);
    *j++ = '_';
    *j++ = 'h';
    *j = '\0';
    return buf;
E 8
I 8
    for (j = i; *j; j++) {
	if (*j == '.') {
	    *j = '_';
	}
    }
    if (j > i && *--j == 'c') {
	*j = 'h';
    }
    return i;
E 8
}

copy()
{
    register char *p;
I 7
    integer nesting;
E 7
    char line[1024];

    while (gets(line) != NULL) {
D 7
	if (strncmp(line, "#ifndef public", 14) == 0) {
E 7
I 7
	if (streqn(line, "#ifndef public", 14)) {
E 7
	    copytext = true;
D 7
	} else if (strncmp(line, "#endif", 6) == 0) {
	    copytext = false;
	} else if (strncmp(line, "public", 6) == 0) {
E 7
I 7
	    nesting = 1;
	} else if (streqn(line, "public", 6)) {
E 7
	    copydef(line);
	} else if (copytext) {
I 7
	    if (streqn(line, "#ifdef", 6) or streqn(line, "#ifndef", 7)) {
		++nesting;
		printf("%s\n", line);
	    } else if (streqn(line, "#endif", 6)) {
		--nesting;
		if (nesting <= 0) {
		    copytext = false;
		} else {
		    printf("%s\n", line);
		}
	    } else {
		printf("%s\n", line);
	    }
	} else if (
	    streqn(line, "#ifdef", 6) or
	    streqn(line, "#ifndef", 7) or
	    streqn(line, "#else", 5) or
	    streqn(line, "#endif", 6)
	) {
E 7
	    printf("%s\n", line);
	}
    }
}

copydef(s)
String s;
{
    register char *p;
    register Boolean isproc;

    isproc = false;
    for (p = &s[7]; *p != '\0' and *p != '='; p++) {
	if (*p == '(') {
	    isproc = true;
	    printf("(/* ");
	} else if (*p == ')' and isproc and *(p+1) == '\0') {
	    printf(" */)");
	} else {
	    putchar(*p);
	}
    }
    if (isproc or *p == '=') {
	putchar(';');
    }
    putchar('\n');
}

/*
 * Terminate program.
 */

procedure abnorm(signo)
int signo;
{
    unlink(tmpname);
    quit(signo);
}

quit(r)
int r;
{
    exit(r);
}

/*
 * No special error recovery strategy.
 */

erecover()
{
}
E 1
