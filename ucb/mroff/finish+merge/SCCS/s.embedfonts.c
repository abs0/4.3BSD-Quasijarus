h30779
s 00155/00000/00000
d D 5.1 10/10/09 04:29:25 msokolov 1 0
c written, compiles
e
u
U
t
T
I 1
/*
 * Pstmerge is a program for merging PostScript documents produced by pstroff;
 * it also performs some important finishing functions.
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 *
 * This module handles the embedding of fonts which aren't pstroff's own
 * "special" fonts, but which aren't standard printer ROM fonts either,
 * i.e., fonts pulled from the full Adobe Type Library or from 3rd-party
 * sources.  These fonts are sought in the /usr/lib/psfonts directory,
 * which is to be created and populated by the user who wants to use
 * this feature.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/types.h>
#include <sys/file.h>
#include <ctype.h>
#include <strings.h>
#include <stdio.h>
#include "struct.h"

extern char *malloc();

extern int Fflag;
extern char *Fbaseset;
extern struct fontdesc fonts[];
extern int nfonts;

#define	MAX_ROMFONTS	64
static char *romfonts[MAX_ROMFONTS];
static int nromfonts;

static int
strcmp_charstarstar(s1, s2)
	char **s1, **s2;
{
	return(strcmp(*s1, *s2));
}

Fflag_init()
{
	static char fontlist_pathbase[] = "/usr/lib/psutils/fontlist.";
	char *fontlist_pathname;
	register FILE *f;
	char linebuf[256];
	int lineno;
	register char *cp, *np;

	if (!strcmp(Fbaseset, "null"))
		return(0);
	fontlist_pathname = malloc(strlen(fontlist_pathbase) + strlen(Fbaseset)
					+ 1);
	if (!fontlist_pathname) {
mallocfail:	perror("malloc");
		exit(1);
	}
	strcpy(fontlist_pathname, fontlist_pathbase);
	strcat(fontlist_pathname, Fbaseset);
	f = fopen(fontlist_pathname, "r");
	if (!f) {
		perror(fontlist_pathname);
		exit(1);
	}
	for (lineno = 1; fgets(linebuf, sizeof linebuf, f); lineno++) {
		for (cp = linebuf; isspace(*cp); cp++)
			;
		if (!*cp)
			continue;
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (isspace(*cp))
			*cp = '\0';
		if (nromfonts >= MAX_ROMFONTS) {
			fprintf(stderr, "%s: too many fonts listed\n",
				fontlist_pathname);
			exit(1);
		}
		cp = malloc(strlen(np) + 1);
		if (!cp)
			goto mallocfail;
		strcpy(cp, np);
		romfonts[nromfonts++] = cp;
	}
	fclose(f);
	free(fontlist_pathname);
	if (nromfonts > 1)
		qsort(romfonts, nromfonts, sizeof(char *), strcmp_charstarstar);
	return(0);
}

/* function based on 4.4BSD bsearch() */
is_font_in_base_set(queryfont)
	register char *queryfont;
{
	register char **base = romfonts, **p;
	register int lim;
	register int cmp;

	for (lim = nromfonts; lim != 0; lim >>= 1) {
		p = base + (lim >> 1);
		cmp = strcmp(queryfont, *p);
		if (cmp == 0)
			return(1);
		if (cmp > 0) {	/* key > p: move right */
			base = p + 1;
			lim--;
		}		/* else move left */
	}
	return(0);
}

Fflag_mark_as_needed()
{
	int ft;
	register struct fontdesc *fr;
	register char *pathname;
	static char fontdir[] = "/usr/lib/psfonts/";

	for (ft = 0; ft < nfonts; ft++) {
		fr = fonts + ft;
		if (fr->special)
			continue;
		if (is_font_in_base_set(fr->fontname))
			continue;
		pathname = malloc(strlen(fontdir) + strlen(fr->fontname) + 5);
		strcpy(pathname, fontdir);
		strcat(pathname, fr->fontname);
		strcat(pathname, ".pfa");
		if (access(pathname, R_OK) >= 0)
			fr->supplying = pathname;
		else {
			fprintf(stderr,
		"warning: font %s is not standard and not found in %s either\n",
				fr->fontname, pathname);
			free(pathname);
		}
	}
}

Fflag_emit_fonts()
{
	int ft;
	register struct fontdesc *fr;

	for (ft = 0; ft < nfonts; ft++) {
		fr = fonts + ft;
		if (fr->supplying)
			emit_raw_file(fr->supplying);
	}
}
E 1
