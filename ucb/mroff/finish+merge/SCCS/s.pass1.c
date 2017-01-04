h24239
s 00018/00010/00316
d D 5.10 2012/09/10 04:28:51 msokolov 10 9
c ad hoc setup code for Times-{Roman,Italic,Bold} made to match
c the current "official" version in ../stdfonts/ft[RIB].src
e
s 00001/00001/00325
d D 5.9 2012/07/23 17:47:22 msokolov 9 8
c TroffEmu-SymbolBV => TroffEmu-Special1
e
s 00029/00009/00297
d D 5.8 2012/07/22 01:42:25 msokolov 8 7
c implemented .bd procset preservation and skipping of extra setup
e
s 00014/00009/00292
d D 5.7 2012/07/18 05:48:47 msokolov 7 6
c smart recognition of TroffEncoding and CyrTroffEncoding implemented
e
s 00033/00009/00268
d D 5.6 2012/07/18 05:21:52 msokolov 6 5
c gentle wash cycle implemented
e
s 00001/00008/00276
d D 5.5 2012/07/18 03:58:02 msokolov 5 4
c file opening and closing moved to mergemain.c
c in preparation for a native implementation of pstfinish
e
s 00010/00029/00274
d D 5.4 2012/03/10 03:12:45 msokolov 4 3
c TroffEmu fonts restructured once again
e
s 00035/00015/00268
d D 5.3 2012/03/06 06:07:31 msokolov 3 2
c more aggressive substitution of TroffEmu-Symbol
e
s 00006/00000/00277
d D 5.2 10/10/09 04:30:39 msokolov 2 1
c added -F option (font embedding)
e
s 00277/00000/00000
d D 5.1 10/10/08 06:51:49 msokolov 1 0
c pstmerge.c split into several modules
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
D 5
 * Written by Michael Sokolov, Quasijarus Project,
E 5
I 5
 * Written by Michael Spacefalcon, Quasijarus Project,
E 5
 * International Free Computing Task Force.
 *
 * Pass 1 does the following work:
 * - Scan the header section of each input document and verify that it
 *   is indeed pstroff output;
 * - Skip the rest of the header section and the prolog section;
 * - Parse the setup section and extract each document's font list;
 * - Merge each document's fonts into the global font list;
 * - Handle the special fonts.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/types.h>
#include <strings.h>
#include <stdio.h>
#include "struct.h"

extern char *malloc();

static struct specialfont {
	char *fontname;
	char *prereq_roman;
D 3
	char *prereq_expert;
E 3
I 3
	char *prereq_special;
E 3
	char *prereq_misc;
I 3
D 4
	int symbol_subst;
E 4
E 3
} special_fonts[] = {
D 3
	{"Troff5lig-Regular", NULL, NULL, NULL},
	{"Troff5lig-Italic", NULL, NULL, NULL},
	{"Troff5lig-Bold", NULL, NULL, NULL},
	{"TroffEmu-Times-Roman", "Times-Roman", "Troff5lig-Regular", NULL},
	{"TroffEmu-Times-Italic", "Times-Italic", "Troff5lig-Italic", NULL},
	{"TroffEmu-Times-Bold", "Times-Bold", "Troff5lig-Bold", NULL},
	{"TroffEmu-Symbol", NULL, NULL, NULL},
	{"TroffEmu-SuperSpecial", NULL, "TroffEmu-Symbol", "ZapfDingbats"},
E 3
I 3
D 4
	{"Troff5lig-Regular", NULL, NULL, NULL, 0},
	{"Troff5lig-Italic", NULL, NULL, NULL, 0},
	{"Troff5lig-Bold", NULL, NULL, NULL, 0},
	{"TroffEmu-Times-Roman", "Times-Roman", "Troff5lig-Regular", NULL, 0},
	{"TroffEmu-Times-Italic", "Times-Italic", "Troff5lig-Italic", NULL, 0},
	{"TroffEmu-Times-Bold", "Times-Bold", "Troff5lig-Bold", NULL, 0},
	{"TroffEmu-Symbol", NULL, NULL, NULL, 1},
	{"TroffEmu-SuperSpecial", NULL, "TroffEmu-Symbol", "ZapfDingbats", 1},
E 4
I 4
	{"Troff5lig-Regular", NULL, NULL, NULL},
	{"Troff5lig-Italic", NULL, NULL, NULL},
	{"Troff5lig-Bold", NULL, NULL, NULL},
	{"TroffEmu-Times-Roman", "Times-Roman", "Troff5lig-Regular", NULL},
	{"TroffEmu-Times-Italic", "Times-Italic", "Troff5lig-Italic", NULL},
	{"TroffEmu-Times-Bold", "Times-Bold", "Troff5lig-Bold", NULL},
	{"TroffEmu-Symbol", NULL, NULL, NULL},
D 9
	{"TroffEmu-SymbolBV", NULL, "TroffEmu-Symbol", NULL},
E 9
I 9
	{"TroffEmu-Special1", NULL, NULL, NULL},
E 9
	{"TroffEmu-Supplement", NULL, NULL, "ZapfDingbats"},
E 4
E 3
	{NULL, NULL, NULL, NULL}
};

D 7
extern int psout_omit_troffencoding;
E 7
I 7
D 8
extern int need_troffencoding, need_cyrtroffencoding;
E 8
I 8
extern int need_troffencoding, need_cyrtroffencoding, need_bdprocset;
E 8
E 7
D 3
extern int notfinal, symbolbugfix;
E 3
I 3
D 6
extern int notfinal, symbolsubst;
E 6
I 6
extern int notfinal, symbolsubst, gentlewash;
E 6
E 3
extern struct srcdoc *curdoc;
extern struct fontdesc fonts[256];
extern int nfonts;
extern FILE *srcfile;
extern char srcline[];

extern char psmagic[];
extern char creatorcomment[];
extern char beginsetupcomment[];
extern char endsetupcomment[];
extern char fontsetopen[];
extern char fontsetclose[];

I 6
extern char progname[];

I 8
static char bdprocset_magic[] =
		"%%BeginResource: procset (troff procedures for .bd)";

E 8
static
gentle_cycle_check()
{
	if (!gentlewash)
		return;
	fprintf(stderr,
"%s: %s requires font manipulations incompatible with the gentle cycle\n",
		progname, curdoc->filename);
	exit(1);
}

E 6
pass1()
{
I 8
	int bdprocset_magic_len;
E 8
	register struct setupline *sl, **tail;
	int skipsetup;
	register char *cp;
	register int i;
	register struct specialfont *sf;
	int special;

D 5
	srcfile = fopen(curdoc->filename, "r");
	if (!srcfile) {
		perror(curdoc->filename);
		exit(1);
	}
E 5
	curdoc->lineno = 0;
	getline();
	if (strcmp(srcline, psmagic)) {
D 6
		fprintf(stderr, "%s is not a valid PostScript file\n",
			curdoc->filename);
E 6
I 6
		fprintf(stderr, "%s: %s is not a valid PostScript file\n",
			progname, curdoc->filename);
E 6
		exit(1);
	}
	getline();
	if (strcmp(srcline, creatorcomment)) {
D 6
		fprintf(stderr, "%s is not pstroff output\n", curdoc->filename);
E 6
I 6
		fprintf(stderr, "%s: %s is not pstroff output\n", progname,
			curdoc->filename);
E 6
		exit(1);
	}
D 8
	do
E 8
I 8
	/*
	 * Skip the rest of comments and prolog, look for the setup section.
	 * While here, check for the .bd procset and for any
	 * %%LanguageLevel: comments.
	 */
	bdprocset_magic_len = strlen(bdprocset_magic);
	do {
E 8
		getline();
D 8
	while (strcmp(srcline, beginsetupcomment));
	getline();
	if (strcmp(srcline, fontsetopen)) {
D 6
invalid:	fprintf(stderr, "%s: invalid setup section (line %d)\n",
			curdoc->filename, curdoc->lineno);
E 6
I 6
invalid:	fprintf(stderr, "%s: %s: invalid setup section (line %d)\n",
			progname, curdoc->filename, curdoc->lineno);
E 6
		exit(1);
	}
E 8
I 8
		if (!strncmp(srcline, bdprocset_magic, bdprocset_magic_len))
			need_bdprocset = 1;
	} while (strcmp(srcline, beginsetupcomment));
	/*
	 * In the setup section: skip -F fonts, setstrokeadjust,
	 * whatever else we may come up with,
	 * and look for the /fontset [ line.
	 */
	do {
		getline();
		if (!strncmp(srcline, endsetupcomment, 10)) {
invalid:		fprintf(stderr,
				"%s: %s: invalid setup section (line %d)\n",
				progname, curdoc->filename, curdoc->lineno);
			exit(1);
		}
	} while (strcmp(srcline, fontsetopen));
E 8
	curdoc->nfonts = 0;
	for (tail = NULL, skipsetup = 0; ; ) {
		getline();
		if (srcline[0] == ']')
			break;
		if (!strncmp(srcline, "%%BeginResource:", 16)) {
			/*
			 * an embedded resource, probably from a prior pstmerge
			 * skip it
			 */
			do
				getline();
			while (strcmp(srcline, "%%EndResource"));
			continue;
		}
		if (srcline[0] != '/')
			goto setupline;
		cp = index(srcline + 1, ' ');
		if (cp == NULL)
			goto setupline;
		if (strcmp(cp + 1, "findfont"))
			goto setupline;
		/* new font */
		*cp = '\0';
		cp = srcline + 1;
		if (curdoc->nfonts >= 32) {
D 6
			fprintf(stderr, "%s uses more than 32 fonts\n",
				curdoc->filename);
E 6
I 6
			fprintf(stderr, "%s: %s uses more than 32 fonts\n",
				progname, curdoc->filename);
E 6
			exit(1);
		}
		skipsetup = 0;
D 3
		if (symbolbugfix && !strcmp(cp, "Symbol")) {
E 3
I 3
		if (symbolsubst && !strcmp(cp, "Symbol")) {
E 3
			strcpy(cp, "TroffEmu-Symbol");
			skipsetup = 1;
		}
D 3
		for (i = 0; i < nfonts; i++)
E 3
I 3
D 4
symrepeat:	for (i = 0; i < nfonts; i++)
E 4
I 4
		for (i = 0; i < nfonts; i++)
E 4
E 3
			if (!strcmp(fonts[i].fontname, cp)) {
I 6
				gentle_cycle_check();
E 6
				tail = NULL;
				skipsetup = 1;
				goto definefont;
			}
repeatadd:	if (i >= 256) {
D 6
fputs("the merged document uses more than 256 different fonts\n", stderr);
E 6
I 6
			fprintf(stderr,
		"%s: the merged document uses more than 256 different fonts\n",
				progname);
E 6
			exit(1);
		}
		for (sf = special_fonts; sf->fontname; sf++)
			if (!strcmp(cp, sf->fontname))
				break;
		if (sf->fontname) {
I 3
D 4
			if (sf->symbol_subst && !symbolsubst) {
				symbolsubst = 1;
				retroactive_symbol_subst();
				goto symrepeat;
			}
E 4
E 3
			if (sf->prereq_roman &&
			    font_prereq_roman(sf->prereq_roman)) {
				i = nfonts;
				goto repeatadd;
			}
D 3
			if (sf->prereq_expert &&
			    font_prereq_expert(sf->prereq_expert)) {
E 3
I 3
			if (sf->prereq_special &&
			    font_prereq_special(sf->prereq_special)) {
E 3
				i = nfonts;
				goto repeatadd;
			}
			if (sf->prereq_misc &&
			    font_prereq_misc(sf->prereq_misc)) {
				i = nfonts;
				goto repeatadd;
			}
			special = 1;
I 2
D 7
#if 0
E 2
			if (psout_omit_troffencoding) {
				fprintf(stderr,
				"%s uses special fonts, -N not allowed\n",
					curdoc->filename);
				exit(1);
			}
I 2
#endif
E 7
E 2
		} else
			special = 0;
		cp = malloc(strlen(cp) + 1);
		if (!cp) {
mallocfail:		perror("malloc");
			exit(1);
		}
		strcpy(cp, srcline + 1);
		fonts[i].fontname = cp;
		fonts[i].setup = NULL;
		fonts[i].special = special;
I 2
		fonts[i].supplying = 0;
E 2
		nfonts++;
		tail = &fonts[i].setup;
definefont:	curdoc->fontmap[curdoc->nfonts++] = i;
		continue;
		/* a setup line for a font */
setupline:	if (skipsetup)
			continue;
		if (tail == NULL)
			goto invalid;
I 7
		setupline_check_encoding();
E 7
		sl = (struct setupline *)malloc(sizeof(struct setupline) +
			strlen(srcline) + 1);
		if (!sl)
			goto mallocfail;
		sl->line = (char *)(sl + 1);
		sl->next = NULL;
		strcpy(sl->line, srcline);
		*tail = sl;
		tail = &sl->next;
	}
	if (strcmp(srcline, fontsetclose))
		goto invalid;
	getline();
	if (strcmp(srcline, endsetupcomment))
		goto invalid;
D 5
	curdoc->bodyoffset = ftell(srcfile);
	fclose(srcfile);
E 5
}

/*
D 10
 * XXX the following kludge is just plain ugly: we are effectively
 * replicating an ad hoc version of preppsfont here
E 10
I 10
 * The 3 "basic" Roman text fonts Times-Roman, Times-Italic and Times-Bold
 * can enter the merged font set in two ways:
 *
 * 1: They can come from a source document in which they were used
 *	directly in the troff session;
 * 2: They can be "auto-filled" by the font_prereq_roman() function below
 *	if a document uses the TroffEmu family and the basic Times versions
 *	haven't been seen yet.
 *
 * The font setup code which has been hard-coded in font_prereq_roman() below
 * takes effect if case 2 happens first.  It needs to match the setup code
 * given in the ../stdfonts/ft[RIB].src files; the latter is in effect
 * if case 1 happens first in a merge.
E 10
 */

font_prereq_roman(fontname)
	register char *fontname;
{
	register int i;
	register char *cp;
	register struct setupline *sl;
	static char cline1[] = "dup length dict begin";
	static char cline2[] =
			"\t{1 index /FID ne {def} {pop pop} ifelse} forall";
	static char cline3[] = "\t/Encoding TroffEncoding def";
D 10
	static char cline4[] = "\tcurrentdict";
	static char cline5[] = "end";
E 10
I 10
	static char cline4[] = "currentdict end";
E 10

	for (i = 0; i < nfonts; i++)
		if (!strcmp(fonts[i].fontname, fontname))
			return(0);
I 6
	gentle_cycle_check();
E 6
	fonts[i].fontname = fontname;
	fonts[i].special = 0;
I 2
	fonts[i].supplying = 0;
E 2
D 10
	cp = malloc(sizeof(struct setupline) * 6 + strlen(fontname) + 24);
E 10
I 10
	cp = malloc(sizeof(struct setupline) * 5 + strlen(fontname) + 24);
E 10
I 6
	if (!cp) {
		perror("malloc");
		exit(1);
	}
E 6
	sl = (struct setupline *)cp;
D 10
	cp += sizeof(struct setupline) * 6;
E 10
I 10
	cp += sizeof(struct setupline) * 5;
E 10
	fonts[i].setup = sl;
	sprintf(cp, "/%s-troff exch definefont", fontname);
	sl[0].line = cline1;
	sl[0].next = sl + 1;
	sl[1].line = cline2;
	sl[1].next = sl + 2;
	sl[2].line = cline3;
	sl[2].next = sl + 3;
	sl[3].line = cline4;
	sl[3].next = sl + 4;
D 10
	sl[4].line = cline5;
	sl[4].next = sl + 5;
	sl[5].line = cp;
	sl[5].next = NULL;
E 10
I 10
	sl[4].line = cp;
	sl[4].next = NULL;
E 10
	nfonts++;
I 7
	need_troffencoding = 1;
E 7
	return(1);
}

D 3
font_prereq_expert(fontname)
E 3
I 3
font_prereq_special(fontname)
E 3
	register char *fontname;
{
	register int i;

	for (i = 0; i < nfonts; i++)
		if (!strcmp(fonts[i].fontname, fontname))
			return(0);
I 6
	gentle_cycle_check();
E 6
	fonts[i].fontname = fontname;
	fonts[i].special = 1;
I 2
	fonts[i].supplying = 0;
E 2
	fonts[i].setup = NULL;
	nfonts++;
	return(1);
}

font_prereq_misc(fontname)
	register char *fontname;
{
	register int i;

	for (i = 0; i < nfonts; i++)
		if (!strcmp(fonts[i].fontname, fontname))
			return(0);
I 6
	gentle_cycle_check();
E 6
	fonts[i].fontname = fontname;
	fonts[i].special = 0;
I 2
	fonts[i].supplying = 0;
E 2
	fonts[i].setup = NULL;
	nfonts++;
	return(1);
I 7
}

static char troffencoding_magic[] = "\t/Encoding TroffEncoding def";
static char cyrtroffencoding_magic[] = "\t/Encoding CyrTroffEncoding def";

setupline_check_encoding()
{
	if (!strcmp(srcline, troffencoding_magic))
		need_troffencoding = 1;
	else if (!strcmp(srcline, cyrtroffencoding_magic))
		need_cyrtroffencoding = 1;
E 7
I 3
D 4
}

retroactive_symbol_subst()
{
	register int i;

	for (i = 0; i < nfonts; i++)
		if (!strcmp(fonts[i].fontname, "Symbol"))
			break;
	if (i >= nfonts)
		return;
	fonts[i].fontname = "TroffEmu-Symbol";
	fonts[i].special = 1;
	fonts[i].setup = NULL;
E 4
E 3
}
E 1
