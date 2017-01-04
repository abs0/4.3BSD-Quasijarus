h49898
s 00010/00005/00500
d D 5.11 88/06/29 20:34:27 bostic 22 21
c install approved copyright notice
e
s 00011/00005/00494
d D 5.10 88/03/14 17:21:44 bostic 21 20
c add Berkeley specific headers
e
s 00001/00001/00498
d D 5.9 88/01/20 16:25:59 tef 20 19
c Must check for error on stdin in addition to checking for EOF.
e
s 00002/00001/00497
d D 5.8 88/01/02 23:32:51 bostic 19 18
c fix external declarations; ANSI C compatibility
e
s 00001/00001/00497
d D 5.7 87/12/22 13:46:51 bostic 18 17
c fix CTRL macro; ANSI C compatible
e
s 00028/00026/00470
d D 5.6 86/03/07 12:31:26 minshall 17 16
c Clean up for lint; change some stderr to stdout; bug fix
c (in ruserpass.c, routine rnetrc()).
e
s 00002/00006/00494
d D 5.5 86/02/05 03:10:35 lepreau 16 15
c reinstall delta 5.2
e
s 00082/00028/00418
d D 5.4 86/02/03 14:40:23 minshall 15 14
c Changes from Steve Jacobson (from <csvsj@ucbopal>).
e
s 00025/00009/00421
d D 5.3 86/01/13 19:32:31 mckusick 14 13
c numerous bug fixes from sun!gorodish!guy
e
s 00002/00006/00428
d D 5.2 86/01/10 03:28:54 lepreau 13 11
c always quit on EOF from stdin
e
s 00001/00003/00431
d R 5.2 86/01/10 02:18:55 lepreau 12 11
c always quit on EOF from stdin
e
s 00013/00001/00421
d D 5.1 85/05/31 17:08:34 dist 11 10
c Add copyright
e
s 00002/00000/00420
d D 4.10 84/07/19 16:45:30 ralph 10 9
c quit on EOF if input is not a tty.
e
s 00006/00001/00414
d D 4.9 83/07/18 20:29:34 sam 9 8
c handle EOF from tty properly
e
s 00004/00004/00411
d D 4.8 83/06/10 23:40:31 sam 8 7
c new signals; no more libjobs
e
s 00002/00001/00413
d D 4.7 83/05/11 22:03:12 sam 7 6
c split ftpd out to etc source; fix bug with sendport stuff
e
s 00010/00001/00404
d D 4.6 83/03/23 10:27:47 sam 6 5
c merge of changes from jsq@utexas-11
e
s 00015/00001/00390
d D 4.5 83/03/01 03:13:29 sam 5 4
c setup home directory for globbing
e
s 00006/00000/00385
d D 4.4 83/03/01 02:12:53 sam 4 3
c put all initializations in one place; add -g to suppress globbing
e
s 00002/00003/00383
d D 4.3 83/02/23 14:01:42 sam 3 2
c parameter problem with shutdown
e
s 00001/00000/00385
d D 4.2 83/02/22 17:11:04 sam 2 1
c missed two other things
e
s 00385/00000/00000
d D 4.1 83/01/15 16:52:41 sam 1 0
c date and time created 83/01/15 16:52:41 by sam
e
u
U
t
T
I 11
/*
D 15
 * Copyright (c) 1983 Regents of the University of California.
E 15
I 15
 * Copyright (c) 1985 Regents of the University of California.
E 15
D 21
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 21
I 21
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 22
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 22
I 22
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
E 22
E 21
 */

E 11
I 1
#ifndef lint
I 11
char copyright[] =
D 15
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 15
I 15
D 21
"@(#) Copyright (c) 1985 Regents of the University of California.\n\
E 21
I 21
"%Z% Copyright (c) 1985 Regents of the University of California.\n\
E 21
E 15
 All rights reserved.\n";
D 21
#endif not lint
E 21
I 21
#endif /* not lint */
E 21

#ifndef lint
E 11
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif
E 11
I 11
D 21
#endif not lint
E 21
I 21
#endif /* not lint */
E 21
E 11

/*
 * FTP User Program -- Command Interface.
 */
D 5
#include <sys/types.h>
E 5
I 5
D 15
#include <sys/param.h>
E 15
I 15
#include "ftp_var.h"
E 15
E 5
#include <sys/socket.h>
#include <sys/ioctl.h>
I 17
#include <sys/types.h>
E 17

I 7
#include <arpa/ftp.h>

E 7
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <netdb.h>
I 5
#include <pwd.h>
E 5

D 7
#include "ftp.h"
E 7
D 15
#include "ftp_var.h"
E 15

I 17
uid_t	getuid();
E 17
int	intr();
int	lostpeer();
I 5
extern	char *home;
I 14
char	*getlogin();
E 14
E 5

main(argc, argv)
	char *argv[];
{
	register char *cp;
	int top;
I 5
D 14
	struct passwd *pw;
E 14
I 14
	struct passwd *pw = NULL;
E 14
	char homedir[MAXPATHLEN];
E 5

	sp = getservbyname("ftp", "tcp");
	if (sp == 0) {
		fprintf(stderr, "ftp: ftp/tcp: unknown service\n");
		exit(1);
	}
I 4
	doglob = 1;
I 6
	interactive = 1;
E 6
	autologin = 1;
E 4
	argc--, argv++;
	while (argc > 0 && **argv == '-') {
		for (cp = *argv + 1; *cp; cp++)
			switch (*cp) {

			case 'd':
				options |= SO_DEBUG;
				debug++;
				break;
			
			case 'v':
				verbose++;
				break;

			case 't':
				trace++;
				break;

			case 'i':
D 6
				interactive++;
E 6
I 6
				interactive = 0;
E 6
				break;

			case 'n':
				autologin = 0;
I 4
				break;

			case 'g':
				doglob = 0;
E 4
				break;

			default:
D 17
				fprintf(stderr,
E 17
I 17
				fprintf(stdout,
E 17
				  "ftp: %c: unknown option\n", *cp);
				exit(1);
			}
		argc--, argv++;
	}
	fromatty = isatty(fileno(stdin));
	/*
	 * Set up defaults for FTP.
	 */
D 17
	strcpy(typename, "ascii"), type = TYPE_A;
	strcpy(formname, "non-print"), form = FORM_N;
	strcpy(modename, "stream"), mode = MODE_S;
	strcpy(structname, "file"), stru = STRU_F;
I 2
	strcpy(bytename, "8"), bytesize = 8;
E 17
I 17
	(void) strcpy(typename, "ascii"), type = TYPE_A;
	(void) strcpy(formname, "non-print"), form = FORM_N;
	(void) strcpy(modename, "stream"), mode = MODE_S;
	(void) strcpy(structname, "file"), stru = STRU_F;
	(void) strcpy(bytename, "8"), bytesize = 8;
E 17
E 2
	if (fromatty)
		verbose++;
I 15
	cpend = 0;           /* no pending replies */
	proxy = 0;	/* proxy not active */
	crflag = 1;    /* strip c.r. on ascii gets */
E 15
I 5
	/*
	 * Set up the home directory in case we're globbing.
	 */
D 14
	pw = getpwnam(getlogin());
E 14
I 14
	cp = getlogin();
D 15
	if (cp != NULL)
E 15
I 15
	if (cp != NULL) {
E 15
		pw = getpwnam(cp);
I 15
	}
E 15
E 14
	if (pw == NULL)
		pw = getpwuid(getuid());
	if (pw != NULL) {
		home = homedir;
D 17
		strcpy(home, pw->pw_dir);
E 17
I 17
		(void) strcpy(home, pw->pw_dir);
E 17
	}
E 5
	if (argc > 0) {
		if (setjmp(toplevel))
			exit(0);
D 8
		sigset(SIGINT, intr);
		sigset(SIGPIPE, lostpeer);
E 8
I 8
D 17
		signal(SIGINT, intr);
		signal(SIGPIPE, lostpeer);
E 17
I 17
		(void) signal(SIGINT, intr);
		(void) signal(SIGPIPE, lostpeer);
E 17
E 8
		setpeer(argc + 1, argv - 1);
	}
	top = setjmp(toplevel) == 0;
	if (top) {
D 8
		sigset(SIGINT, intr);
		sigset(SIGPIPE, lostpeer);
E 8
I 8
D 17
		signal(SIGINT, intr);
		signal(SIGPIPE, lostpeer);
E 17
I 17
		(void) signal(SIGINT, intr);
		(void) signal(SIGPIPE, lostpeer);
E 17
E 8
	}
	for (;;) {
		cmdscanner(top);
		top = 1;
	}
}

intr()
{

	longjmp(toplevel, 1);
}

lostpeer()
{
	extern FILE *cout;
	extern int data;
D 3
	int how = 1+1;
E 3

	if (connected) {
		if (cout != NULL) {
D 3
			shutdown(fileno(cout), &how);
E 3
I 3
D 17
			shutdown(fileno(cout), 1+1);
E 3
			fclose(cout);
E 17
I 17
			(void) shutdown(fileno(cout), 1+1);
			(void) fclose(cout);
E 17
			cout = NULL;
		}
		if (data >= 0) {
D 3
			shutdown(data, &how);
E 3
I 3
D 17
			shutdown(data, 1+1);
E 17
I 17
			(void) shutdown(data, 1+1);
E 17
E 3
			(void) close(data);
			data = -1;
		}
		connected = 0;
	}
D 15
	longjmp(toplevel, 1);
E 15
I 15
	pswitch(1);
	if (connected) {
		if (cout != NULL) {
D 17
			shutdown(fileno(cout), 1+1);
			fclose(cout);
E 17
I 17
			(void) shutdown(fileno(cout), 1+1);
			(void) fclose(cout);
E 17
			cout = NULL;
		}
		connected = 0;
	}
	proxflag = 0;
	pswitch(0);
E 15
}

D 17
char *
E 17
I 17
/*char *
E 17
tail(filename)
	char *filename;
{
	register char *s;
	
	while (*filename) {
		s = rindex(filename, '/');
		if (s == NULL)
			break;
		if (s[1])
			return (s + 1);
		*s = '\0';
	}
	return (filename);
}
D 17

E 17
I 17
*/
E 17
/*
 * Command parser.
 */
cmdscanner(top)
	int top;
{
	register struct cmd *c;
	struct cmd *getcmd();
D 19
	extern struct cmd cmdtab[];
E 19
	extern int help();

	if (!top)
D 17
		putchar('\n');
E 17
I 17
		(void) putchar('\n');
E 17
	for (;;) {
		if (fromatty) {
			printf("ftp> ");
D 17
			fflush(stdout);
E 17
I 17
			(void) fflush(stdout);
E 17
		}
D 9
		if (gets(line) == 0)
E 9
I 9
		if (gets(line) == 0) {
D 13
			if (feof(stdin)) {
I 10
				if (!fromatty)
					quit();
E 10
				clearerr(stdin);
				putchar('\n');
			}
E 13
I 13
D 15
			if (feof(stdin))
				quit();
E 15
I 15
D 16
			if (feof(stdin)) {
				if (!fromatty)
					quit();
				clearerr(stdin);
				putchar('\n');
			}
E 16
I 16
D 20
			if (feof(stdin))
E 20
I 20
			if (feof(stdin) || ferror(stdin))
E 20
				quit();
E 16
E 15
E 13
E 9
			break;
I 9
		}
E 9
		if (line[0] == 0)
			break;
		makeargv();
I 14
D 15
		if (margc == 0)
E 15
I 15
		if (margc == 0) {
E 15
			continue;
I 15
		}
E 15
E 14
		c = getcmd(margv[0]);
		if (c == (struct cmd *)-1) {
			printf("?Ambiguous command\n");
			continue;
		}
		if (c == 0) {
			printf("?Invalid command\n");
			continue;
		}
I 6
		if (c->c_conn && !connected) {
			printf ("Not connected.\n");
			continue;
		}
E 6
		(*c->c_handler)(margc, margv);
		if (bell && c->c_bell)
D 17
			putchar(CTRL(g));
E 17
I 17
D 18
			(void) putchar(CTRL(g));
E 18
I 18
			(void) putchar(CTRL('g'));
E 18
E 17
		if (c->c_handler != help)
			break;
	}
I 15
D 17
	signal(SIGINT, intr);
	signal(SIGPIPE, lostpeer);
E 17
I 17
	(void) signal(SIGINT, intr);
	(void) signal(SIGPIPE, lostpeer);
E 17
E 15
D 14
	longjmp(toplevel, 0);
E 14
}

struct cmd *
getcmd(name)
	register char *name;
{
I 19
	extern struct cmd cmdtab[];
E 19
	register char *p, *q;
	register struct cmd *c, *found;
	register int nmatches, longest;

	longest = 0;
	nmatches = 0;
	found = 0;
	for (c = cmdtab; p = c->c_name; c++) {
		for (q = name; *q == *p++; q++)
			if (*q == 0)		/* exact match? */
				return (c);
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
		return ((struct cmd *)-1);
	return (found);
}

/*
 * Slice a string up into argc/argv.
 */
I 15

int slrflag;

E 15
makeargv()
{
	char **argp;
	char *slurpstring();

	margc = 0;
	argp = margv;
	stringbase = line;		/* scan from first of buffer */
	argbase = argbuf;		/* store from first of buffer */
D 14
	while (*argp++ = slurpstring())
E 14
I 14
D 15
	while (*stringbase == ' ' || *stringbase == '\t')
		stringbase++;		/* skip initial white space */
	if (*stringbase == '!') {	/* handle shell escapes specially */
		stringbase++;
		*argp++ = "!";		/* command name is "!" */
E 15
I 15
	slrflag = 0;
	while (*argp++ = slurpstring())
E 15
E 14
		margc++;
I 14
D 15
		while (*stringbase == ' ' || *stringbase == '\t')
			stringbase++;		/* skip white space */
		if (*stringbase != '\0') {
			*argp++ = stringbase;	/* argument is entire command string */
			margc++;
		}
		*argp++ = NULL;
	} else {
		while (*argp++ = slurpstring())
			margc++;
	}
E 15
E 14
}

/*
 * Parse string into argbuf;
 * implemented with FSM to
 * handle quoting and strings
 */
char *
slurpstring()
{
	int got_one = 0;
	register char *sb = stringbase;
	register char *ap = argbase;
	char *tmp = argbase;		/* will return this if token found */

I 15
	if (*sb == '!' || *sb == '$') {	/* recognize ! as a token for shell */
		switch (slrflag) {	/* and $ as token for macro invoke */
			case 0:
				slrflag++;
				stringbase++;
				return ((*sb == '!') ? "!" : "$");
				break;
			case 1:
				slrflag++;
				altarg = stringbase;
				break;
			default:
				break;
		}
	}

E 15
I 6
D 14
	if (*sb == '!') {		/* recognize ! as a token for shell */
		stringbase++;
		return ("!");
	}
E 14
E 6
S0:
	switch (*sb) {

	case '\0':
		goto OUT;

	case ' ':
	case '\t':
		sb++; goto S0;

	default:
I 15
		switch (slrflag) {
			case 0:
				slrflag++;
				break;
			case 1:
				slrflag++;
				altarg = sb;
				break;
			default:
				break;
		}
E 15
		goto S1;
	}

S1:
	switch (*sb) {

	case ' ':
	case '\t':
	case '\0':
		goto OUT;	/* end of token */

	case '\\':
		sb++; goto S2;	/* slurp next character */

	case '"':
		sb++; goto S3;	/* slurp quoted string */

	default:
		*ap++ = *sb++;	/* add character to token */
		got_one = 1;
		goto S1;
	}

S2:
	switch (*sb) {

	case '\0':
		goto OUT;

	default:
		*ap++ = *sb++;
		got_one = 1;
		goto S1;
	}

S3:
	switch (*sb) {

	case '\0':
		goto OUT;

	case '"':
		sb++; goto S1;

	default:
		*ap++ = *sb++;
		got_one = 1;
		goto S3;
	}

OUT:
	if (got_one)
		*ap++ = '\0';
	argbase = ap;			/* update storage pointer */
	stringbase = sb;		/* update scan pointer */
D 15
	if (got_one)
E 15
I 15
	if (got_one) {
E 15
		return(tmp);
I 15
	}
	switch (slrflag) {
		case 0:
			slrflag++;
			break;
		case 1:
			slrflag++;
			altarg = (char *) 0;
			break;
		default:
			break;
	}
E 15
	return((char *)0);
}

#define HELPINDENT (sizeof ("directory"))

/*
 * Help command.
 * Call each command handler with argc == 0 and argv[0] == name.
 */
help(argc, argv)
	int argc;
	char *argv[];
{
I 19
	extern struct cmd cmdtab[];
E 19
	register struct cmd *c;

	if (argc == 1) {
D 15
		register int i, j, w;
E 15
I 15
		register int i, j, w, k;
E 15
		int columns, width = 0, lines;
		extern int NCMDS;

		printf("Commands may be abbreviated.  Commands are:\n\n");
		for (c = cmdtab; c < &cmdtab[NCMDS]; c++) {
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
D 14
				printf("%s", c->c_name);
E 14
I 14
D 15
				if (c->c_name)
E 15
I 15
				if (c->c_name && (!proxy || c->c_proxy)) {
E 15
					printf("%s", c->c_name);
I 15
				}
				else if (c->c_name) {
					for (k=0; k < strlen(c->c_name); k++) {
D 17
						putchar(' ');
E 17
I 17
						(void) putchar(' ');
E 17
					}
				}
E 15
E 14
				if (c + lines >= &cmdtab[NCMDS]) {
					printf("\n");
					break;
				}
				w = strlen(c->c_name);
				while (w < width) {
					w = (w + 8) &~ 7;
D 17
					putchar('\t');
E 17
I 17
					(void) putchar('\t');
E 17
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

/*
 * Call routine with argc, argv set from args (terminated by 0).
 */
D 17
/* VARARGS2 */
E 17
I 17
/*VARARGS1*/
E 17
call(routine, args)
	int (*routine)();
	int args;
{
	register int *argp;
	register int argc;

	for (argc = 0, argp = &args; *argp++ != 0; argc++)
		;
	(*routine)(argc, &args);
}
E 1
