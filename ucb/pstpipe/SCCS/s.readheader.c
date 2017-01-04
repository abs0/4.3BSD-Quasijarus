h37389
s 00035/00015/00176
d D 5.3 2012/07/23 01:12:18 msokolov 3 2
c updated for the recent changes to pstroff and pstfinish
e
s 00001/00001/00190
d D 5.2 10/10/10 01:22:55 msokolov 2 1
c fgets arguments: brown paper bag
e
s 00191/00000/00000
d D 5.1 10/10/09 18:56:51 msokolov 1 0
c written, compiles
e
u
U
t
T
I 1
/*
 * This program reads a set of document configuration settings from
 * special header comments in a troff source file and uses them to
 * set up a pipeline invoking pstroff with the right options, preceded
 * by the needed preprocessors and followed by pstfinish if necessary.
 * We construct the pipeline as an sh -c command and then exec /bin/sh.
 *
D 3
 * Written by Michael Sokolov, Quasijarus Project,
E 3
I 3
 * Written by Michael Spacefalcon, Quasijarus Project,
E 3
 * International Free Computing Task Force.
 *
 * This module handles the reading and parsing of the header comments
 * which denote the document's formatting requirements.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "docreq.h"

extern char *malloc();

extern char **sources;

static char hdrline[256];
static int lineno;

char *
copystr(orig)
	char *orig;
{
	register char *s;

	s = malloc(strlen(orig) + 1);
	if (!s) {
		perror("malloc");
		exit(1);
	}
	strcpy(s, orig);
	return(s);
}

static void
set_fonts(arg)
	char *arg;
{
	register char *cp;

	for (cp = arg; *cp && !isspace(*cp); cp++)
		;
	if (*cp) {
		*cp++ = '\0';
		while (isspace(*cp))
			cp++;
D 3
		if (strcmp(cp, "NoTroffEncoding")) {
			fprintf(stderr,
				"%s: line %d: invalid Fonts: declaration\n",
				sources[0], lineno);
			exit(1);
		}
		notroffencoding = 1;
E 3
I 3
		fontpath = copystr(cp);
E 3
	}
	fontlist = copystr(arg);
}

static void
set_languagelevel(arg)
	char *arg;
{
	languagelevel = atoi(arg);
}

static void
set_macros(arg)
	char *arg;
{
	macros = copystr(arg);
}

static void
add_preproc(arg)
	char *arg;
{
	register char *s;

	if (npreprocs >= MAX_PREPROCS) {
		fprintf(stderr,
			"%s: line %d: too many preprocessors requested\n",
			sources[0], lineno);
		exit(1);
	}
	if (!strcmp(arg, "eqn"))
		s = "pseqn";
	else
		s = copystr(arg);
	preprocs[npreprocs++] = s;
}

static void
set_pstfinish_req(arg)
	register char *arg;
{
D 3
	if (!strcmp(arg, "required"))
		pstfinish_req = 1;
	else if (!strcmp(arg, "optional"))
		pstfinish_req = 0;
	else if (!strcmp(arg, "no"))
		pstfinish_req = -1;
	else
E 3
I 3
	register char *cp;

	for (cp = arg; *cp && !isspace(*cp); cp++)
		;
	if (*cp) {
		*cp++ = '\0';
		while (isspace(*cp))
			cp++;
		pstfinish_doc_opts = copystr(cp);
	}
	if (!strcmp(arg, "full"))
		pstfinish_req = PSTFINISH_FULL;
	else if (!strcmp(arg, "gentle"))
		pstfinish_req = PSTFINISH_GENTLE;
	else {
E 3
		fprintf(stderr,
			"%s: line %d: Pstfinish: %s directive not understood\n",
			sources[0], lineno, arg);
I 3
		exit(1);
	}
E 3
}

I 3
static void
set_textbits(arg)
	char *arg;
{
	register int i;

	i = atoi(arg);
	if (i == 7 || i == 8)
		doc_text_bits = i;
	else
		fprintf(stderr,
			"%s: line %d: invalid Textbits setting \"%s\"\n",
			sources[0], lineno, arg);
}

E 3
static struct comment_type {
	char *keyword;
	void (*func)();
} comment_table[] = {
	{"Fonts", set_fonts},
	{"LanguageLevel", set_languagelevel},
	{"Macros", set_macros},
	{"Preproc", add_preproc},
	{"Procset", NULL},
	{"Pstfinish", set_pstfinish_req},
I 3
	{"Textbits", set_textbits},
E 3
	{NULL, NULL}
};

read_header_comments()
{
	register FILE *f;
	register char *cp, *np;
	register struct comment_type *ct;

	f = fopen(sources[0], "r");
	if (!f) {
		perror(sources[0]);
		exit(1);
	}
D 2
	for (lineno = 1; fgets(f, hdrline, sizeof hdrline); lineno++) {
E 2
I 2
	for (lineno = 1; fgets(hdrline, sizeof hdrline, f); lineno++) {
E 2
		cp = hdrline;
		if (*cp++ != '.')	/* comments are over */
			break;
		while (isspace(*cp))
			cp++;
		if (*cp++ != '\\' || *cp++ != '"')	/* ditto */
			break;
		/*
		 * It *is* a comment: don't break from lines-loop
		 * from this point onward.
		 */
		while (isspace(*cp))
			cp++;
		if (!isupper(*cp))
			continue;
		np = cp;
		cp = index(cp, ':');
		if (!cp)
			continue;
		*cp++ = '\0';
		for (ct = comment_table; ct->keyword; ct++)
			if (!strcmp(ct->keyword, np))
				break;
		if (!ct->func)
			continue;
		while (isspace(*cp))
			cp++;
		if (!*cp) {
			fprintf(stderr, "%s: line %d: empty %s: comment\n",
				sources[0], lineno, ct->keyword);
			continue;
		}
		strip_trailing_whitespace(cp);
		ct->func(cp);
	}
	fclose(f);
	return(0);
}

strip_trailing_whitespace(arg)
	char *arg;
{
	register char *cp;

	cp = index(arg, '\0');
	while (isspace(cp[-1]))
		--cp;
	*cp = '\0';
}
E 1
