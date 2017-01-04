h23351
s 00001/00001/00155
d D 5.2 87/04/07 15:57:56 mckusick 6 5
c port to tahoe by Nir peleg of CCI
e
s 00008/00002/00148
d D 5.1 85/06/06 15:56:23 dist 5 4
c Add copyright
e
s 00001/00001/00149
d D 1.4 83/05/26 17:43:25 linton 4 3
c changed csvax:linton to linton@ucbvax
e
s 00002/00000/00148
d D 1.3 82/01/20 20:57:49 linton 3 2
c added "list" and "edit" commands to help summary
e
s 00016/00000/00132
d D 1.2 82/01/19 00:09:46 linton 2 1
c gripe command
e
s 00132/00000/00000
d D 1.1 82/01/18 19:21:39 linton 1 0
c date and time created 82/01/18 19:21:39 by linton
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1982 Regents of the University of California */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5

D 5
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5

/*
 * Miscellaneous commands "edit" and "help".
 * Also, output redirection routine "setout" and "unsetout".
 */

#include "defs.h"
#include "tree.h"
#include "command.h"
#include "object.h"
#include "mappings.h"
#include "sym.h"
#include "symtab.h"

extern char *getenv();

#define DEF_EDITOR	"vi"

/*
 * Invoke an editor on the given file.  Which editor to use might change
 * installation to installation.  For now, we use "vi".  In any event,
 * the environment variable "EDITOR" overrides any default.
 */

edit(filename)
char *filename;
{
	char *ed;
	FILE *fp;
	SYM *s;
	ADDRESS addr;
	char buff[10];

	if ((ed = getenv("EDITOR")) == NIL) {
		ed = DEF_EDITOR;
	}
	fp = fopen(filename, "r");
	if (fp == NIL) {
		s = st_lookup(symtab, filename);
		if (s == NIL) {
			error("can't read \"%s\"", filename);
		}
		s = which(s);
		if (!isblock(s)) {
			error("can't read \"%s\"", filename);
		}
		addr = firstline(s);
		filename = srcfilename(addr);
		sprintf(buff, "+%d", srcline(addr));
		call(ed, stdin, stdout, buff, filename, NIL);
	} else {
		fclose(fp);
		call(ed, stdin, stdout, filename, NIL);
	}
}

/*
I 2
 * Send some nasty mail to the current pdx support person.
 */

gripe()
{
D 4
	char *maintainer = "csvax:linton";
E 4
I 4
D 6
	char *maintainer = "linton@ucbvax";
E 6
I 6
	char *maintainer = "4bsd-bugs@Berkeley.EDU";
E 6
E 4

	puts("Type control-D to end your message.  Be sure to include");
	puts("your name and the name of the file you are debugging.");
	putchar('\n');
	call("Mail", stdin, stdout, maintainer, NIL);
	puts("Thank you.");
}

/*
E 2
 * Give the user some help.
 */

help()
{
	puts("pdx command subset summary:");
	putchar('\n');
	puts("run                    - begin execution of the program");
	puts("cont                   - continue execution");
	puts("step                   - single step one line");
	puts("next                   - step to next line (skip over calls)");
	puts("trace <line#>          - trace execution of the line");
	puts("trace <proc>           - trace calls to the procedure");
	puts("trace <var>            - trace changes to the variable");
	puts("trace <exp> at <line#> - print <exp> when <line> is reached");
	puts("stop at <line>         - suspend execution at the line");
	puts("stop in <proc>         - suspend execution when <proc> is called");
	puts("status                 - print trace/stop's in effect");
	puts("delete <number>        - remove trace or stop of given number");
	puts("call <proc>            - call the procedure");
	puts("where                  - print currently active procedures");
	puts("print <exp>            - print the value of the expression");
	puts("whatis <name>          - print the declaration of the name");
I 3
	puts("list <line>, <line>    - list source lines");
	puts("edit <proc>            - edit file containing <proc>");
E 3
I 2
	puts("gripe                  - send mail to the person in charge of pdx");
E 2
	puts("quit                   - exit pdx");
}

/*
 * Divert output to the given file name.
 * Cannot redirect to an existing file.
 */

LOCAL int so_fd;
LOCAL BOOLEAN notstdout;

setout(filename)
char *filename;
{
	FILE *fp;

	if ((fp = fopen(filename, "r")) != NIL) {
		fclose(fp);
		error("%s: file already exists", filename);
	} else {
		so_fd = dup(1);
		close(1);
		if (creat(filename, 0666) == NIL) {
			unsetout();
			error("can't create %s", filename);
		}
		notstdout = TRUE;
	}
}

/*
 * Revert output to standard output.
 */

unsetout()
{
	fflush(stdout);
	close(1);
	if (dup(so_fd) != 1) {
		panic("standard out dup failed");
	}
	close(so_fd);
	notstdout = FALSE;
}

BOOLEAN isredirected()
{
	return(notstdout);
}
E 1
