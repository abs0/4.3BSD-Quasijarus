h19314
s 00010/00005/00134
d D 1.5 88/06/29 20:34:16 bostic 5 4
c install approved copyright notice
e
s 00009/00004/00130
d D 1.4 88/03/14 17:21:31 bostic 4 3
c add Berkeley specific headers
e
s 00001/00001/00133
d D 1.3 87/12/22 13:47:12 bostic 3 2
c fix CTRL macro; ANSI C compatible
e
s 00010/00011/00124
d D 1.2 86/03/07 12:32:52 minshall 2 1
c Clean up for lint; change some stderr to stdout; bug fix
c (in ruserpass.c, routine rnetrc()).
e
s 00135/00000/00000
d D 1.1 86/02/03 15:22:15 minshall 1 0
c date and time created 86/02/03 15:22:15 by minshall
e
u
U
t
T
I 2
D 4

E 4
E 2
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

#include "ftp_var.h"

#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <sys/ttychars.h>

D 2
jmp_buf macabort;

E 2
domacro(argc, argv)
	int argc;
	char *argv[];
{
	register int i, j;
	register char *cp1, *cp2;
D 2
	int count = 2, loopflg = 0, (*oldintr)();
	char **gargs, **cpp, line2[200];
E 2
I 2
	int count = 2, loopflg = 0;
	char line2[200];
E 2
	extern char **glob(), *globerr;
	struct cmd *getcmd(), *c;
	extern struct cmd cmdtab[];

	if (argc < 2) {
D 2
		strcat(line, " ");
E 2
I 2
		(void) strcat(line, " ");
E 2
		printf("(macro name) ");
D 2
		gets(&line[strlen(line)]);
E 2
I 2
		(void) gets(&line[strlen(line)]);
E 2
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
		printf("Usage: %s macro_name.\n", argv[0]);
		code = -1;
		return;
	}
	for (i = 0; i < macnum; ++i) {
		if (!strncmp(argv[1], macros[i].mac_name, 9)) {
			break;
		}
	}
	if (i == macnum) {
		printf("'%s' macro not found.\n", argv[1]);
		code = -1;
		return;
	}
D 2
	strcpy(line2, line);
E 2
I 2
	(void) strcpy(line2, line);
E 2
TOP:
	cp1 = macros[i].mac_start;
	while (cp1 != macros[i].mac_end) {
		while (isspace(*cp1)) {
			cp1++;
		}
		cp2 = line;
		while (*cp1 != '\0') {
		      switch(*cp1) {
		   	    case '\\':
				 *cp2++ = *++cp1;
				 break;
			    case '$':
				 if (isdigit(*(cp1+1))) {
				    j = 0;
				    while (isdigit(*++cp1)) {
					  j = 10*j +  *cp1 - '0';
				    }
				    cp1--;
				    if (argc - 2 >= j) {
D 2
					strcpy(cp2, argv[j+1]);
E 2
I 2
					(void) strcpy(cp2, argv[j+1]);
E 2
					cp2 += strlen(argv[j+1]);
				    }
				    break;
				 }
				 if (*(cp1+1) == 'i') {
					loopflg = 1;
					cp1++;
					if (count < argc) {
D 2
					   strcpy(cp2, argv[count]);
E 2
I 2
					   (void) strcpy(cp2, argv[count]);
E 2
					   cp2 += strlen(argv[count]);
					}
					break;
				}
				/* intentional drop through */
			    default:
				*cp2++ = *cp1;
				break;
		      }
		      if (*cp1 != '\0') {
			 cp1++;
		      }
		}
		*cp2 = '\0';
		makeargv();
		c = getcmd(margv[0]);
		if (c == (struct cmd *)-1) {
			printf("?Ambiguous command\n");
			code = -1;
		}
		else if (c == 0) {
			printf("?Invalid command\n");
			code = -1;
		}
		else if (c->c_conn && !connected) {
			printf("Not connected.\n");
			code = -1;
		}
		else {
			if (verbose) {
				printf("%s\n",line);
			}
			(*c->c_handler)(margc, margv);
			if (bell && c->c_bell) {
D 2
				putchar(CTRL(g));
E 2
I 2
D 3
				(void) putchar(CTRL(g));
E 3
I 3
				(void) putchar(CTRL('g'));
E 3
E 2
			}
D 2
			strcpy(line, line2);
E 2
I 2
			(void) strcpy(line, line2);
E 2
			makeargv();
			argc = margc;
			argv = margv;
		}
		if (cp1 != macros[i].mac_end) {
			cp1++;
		}
	}
	if (loopflg && ++count < argc) {
		goto TOP;
	}
}
E 1
