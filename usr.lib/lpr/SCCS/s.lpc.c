h27245
s 00010/00005/00234
d D 5.6 88/06/30 17:59:48 bostic 11 10
c install approved copyright notice
e
s 00010/00004/00229
d D 5.5 88/05/05 18:07:55 bostic 10 9
c written by Ralph Campbell; add Berkeley specific header
e
s 00002/00002/00231
d D 5.4 87/12/21 11:43:26 bostic 9 8
c make ANSI C compatible
e
s 00001/00001/00232
d D 5.3 87/09/14 14:52:00 bostic 8 7
c NULL dereference; bug report 4.3BSD/usr.lib/59
e
s 00002/00000/00231
d D 5.2 85/11/17 15:53:14 eric 7 6
c clean up logging
e
s 00013/00001/00218
d D 5.1 85/06/06 10:02:16 dist 6 5
c Add copyright
e
s 00000/00000/00219
d D 4.4 83/07/17 00:11:07 sam 5 4
c put sccs id's to some use
e
s 00001/00001/00218
d D 4.3 83/06/15 14:57:06 sam 4 3
c open and flock defines changed
e
s 00003/00000/00216
d D 4.2 83/05/27 11:51:51 ralph 3 1
c init global var "name" for startdaemon().
e
s 00002/00000/00216
d R 4.2 83/05/27 11:47:43 ralph 2 1
c init global variable "name" for startdaemon()
e
s 00216/00000/00000
d D 4.1 83/05/11 16:03:21 ralph 1 0
c date and time created 83/05/11 16:03:21 by ralph
e
u
U
t
T
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */

E 6
I 1
#ifndef lint
I 6
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10

#ifndef lint
E 6
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif
E 6
I 6
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10
E 6

/*
 * lpc -- line printer control program
 */
#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#include <setjmp.h>
I 7
#include <syslog.h>
E 7

#include "lpc.h"

int	fromatty;

char	cmdline[200];
int	margc;
char	*margv[20];
int	top;
int	intr();
struct	cmd *getcmd();

jmp_buf	toplevel;

main(argc, argv)
	char *argv[];
{
	register struct cmd *c;
I 3
	extern char *name;

	name = argv[0];
I 7
	openlog("lpd", 0, LOG_LPR);
E 7
E 3

	if (--argc > 0) {
		c = getcmd(*++argv);
		if (c == (struct cmd *)-1) {
			printf("?Ambiguous command\n");
			exit(1);
		}
		if (c == 0) {
			printf("?Invalid command\n");
			exit(1);
		}
		if (c->c_priv && getuid()) {
			printf("?Privileged command\n");
			exit(1);
		}
		(*c->c_handler)(argc, argv);
		exit(0);
	}
	fromatty = isatty(fileno(stdin));
	top = setjmp(toplevel) == 0;
	if (top)
D 4
		sigset(SIGINT, intr);
E 4
I 4
		signal(SIGINT, intr);
E 4
	for (;;) {
		cmdscanner(top);
		top = 1;
	}
}

intr()
{
	if (!fromatty)
		exit(0);
	longjmp(toplevel, 1);
}

/*
 * Command parser.
 */
cmdscanner(top)
	int top;
{
	register struct cmd *c;
D 9
	extern struct cmd cmdtab[];
	extern int help();
E 9

	if (!top)
		putchar('\n');
	for (;;) {
		if (fromatty) {
			printf("lpc> ");
			fflush(stdout);
		}
		if (gets(cmdline) == 0)
			quit();
		if (cmdline[0] == 0)
			break;
		makeargv();
		c = getcmd(margv[0]);
		if (c == (struct cmd *)-1) {
			printf("?Ambiguous command\n");
			continue;
		}
		if (c == 0) {
			printf("?Invalid command\n");
			continue;
		}
		if (c->c_priv && getuid()) {
			printf("?Privileged command\n");
			continue;
		}
		(*c->c_handler)(margc, margv);
	}
	longjmp(toplevel, 0);
}
I 9

extern struct cmd cmdtab[];
E 9

struct cmd *
getcmd(name)
	register char *name;
{
	register char *p, *q;
	register struct cmd *c, *found;
	register int nmatches, longest;

	longest = 0;
	nmatches = 0;
	found = 0;
	for (c = cmdtab; p = c->c_name; c++) {
		for (q = name; *q == *p++; q++)
			if (*q == 0)		/* exact match? */
				return(c);
		if (!*q) {			/* the name was a prefix */
			if (q - name > longest) {
				longest = q - name;
				nmatches = 1;
				found = c;
			} else if (q - name == longest)
				nmatches++;
		}
	}
	if (nmatches > 1)
		return((struct cmd *)-1);
	return(found);
}

/*
 * Slice a string up into argc/argv.
 */
makeargv()
{
	register char *cp;
	register char **argp = margv;

	margc = 0;
	for (cp = cmdline; *cp;) {
		while (isspace(*cp))
			cp++;
		if (*cp == '\0')
			break;
		*argp++ = cp;
		margc += 1;
		while (*cp != '\0' && !isspace(*cp))
			cp++;
		if (*cp == '\0')
			break;
		*cp++ = '\0';
	}
	*argp++ = 0;
}

#define HELPINDENT (sizeof ("directory"))

/*
 * Help command.
 */
help(argc, argv)
	int argc;
	char *argv[];
{
	register struct cmd *c;

	if (argc == 1) {
		register int i, j, w;
		int columns, width = 0, lines;
		extern int NCMDS;

		printf("Commands may be abbreviated.  Commands are:\n\n");
D 8
		for (c = cmdtab; c < &cmdtab[NCMDS]; c++) {
E 8
I 8
		for (c = cmdtab; c < &cmdtab[NCMDS - 1]; c++) {
E 8
			int len = strlen(c->c_name);

			if (len > width)
				width = len;
		}
		width = (width + 8) &~ 7;
		columns = 80 / width;
		if (columns == 0)
			columns = 1;
		lines = (NCMDS + columns - 1) / columns;
		for (i = 0; i < lines; i++) {
			for (j = 0; j < columns; j++) {
				c = cmdtab + j * lines + i;
				printf("%s", c->c_name);
				if (c + lines >= &cmdtab[NCMDS]) {
					printf("\n");
					break;
				}
				w = strlen(c->c_name);
				while (w < width) {
					w = (w + 8) &~ 7;
					putchar('\t');
				}
			}
		}
		return;
	}
	while (--argc > 0) {
		register char *arg;
		arg = *++argv;
		c = getcmd(arg);
		if (c == (struct cmd *)-1)
			printf("?Ambiguous help command %s\n", arg);
		else if (c == (struct cmd *)0)
			printf("?Invalid help command %s\n", arg);
		else
			printf("%-*s\t%s\n", HELPINDENT,
				c->c_name, c->c_help);
	}
}
E 1
