/*
 * Pstmerge is a program for merging PostScript documents produced by pstroff;
 * it also performs some important finishing functions.
 *
 * Written by Michael Spacefalcon, Quasijarus Project,
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
static char sccsid[] = "@(#)pass1.c	5.10 (Berkeley) 2012/09/10";
#endif

#include <sys/types.h>
#include <strings.h>
#include <stdio.h>
#include "struct.h"

extern char *malloc();

static struct specialfont {
	char *fontname;
	char *prereq_roman;
	char *prereq_special;
	char *prereq_misc;
} special_fonts[] = {
	{"Troff5lig-Regular", NULL, NULL, NULL},
	{"Troff5lig-Italic", NULL, NULL, NULL},
	{"Troff5lig-Bold", NULL, NULL, NULL},
	{"TroffEmu-Times-Roman", "Times-Roman", "Troff5lig-Regular", NULL},
	{"TroffEmu-Times-Italic", "Times-Italic", "Troff5lig-Italic", NULL},
	{"TroffEmu-Times-Bold", "Times-Bold", "Troff5lig-Bold", NULL},
	{"TroffEmu-Symbol", NULL, NULL, NULL},
	{"TroffEmu-Special1", NULL, NULL, NULL},
	{"TroffEmu-Supplement", NULL, NULL, "ZapfDingbats"},
	{NULL, NULL, NULL, NULL}
};

extern int need_troffencoding, need_cyrtroffencoding, need_bdprocset;
extern int notfinal, symbolsubst, gentlewash;
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

extern char progname[];

static char bdprocset_magic[] =
		"%%BeginResource: procset (troff procedures for .bd)";

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

pass1()
{
	int bdprocset_magic_len;
	register struct setupline *sl, **tail;
	int skipsetup;
	register char *cp;
	register int i;
	register struct specialfont *sf;
	int special;

	curdoc->lineno = 0;
	getline();
	if (strcmp(srcline, psmagic)) {
		fprintf(stderr, "%s: %s is not a valid PostScript file\n",
			progname, curdoc->filename);
		exit(1);
	}
	getline();
	if (strcmp(srcline, creatorcomment)) {
		fprintf(stderr, "%s: %s is not pstroff output\n", progname,
			curdoc->filename);
		exit(1);
	}
	/*
	 * Skip the rest of comments and prolog, look for the setup section.
	 * While here, check for the .bd procset and for any
	 * %%LanguageLevel: comments.
	 */
	bdprocset_magic_len = strlen(bdprocset_magic);
	do {
		getline();
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
			fprintf(stderr, "%s: %s uses more than 32 fonts\n",
				progname, curdoc->filename);
			exit(1);
		}
		skipsetup = 0;
		if (symbolsubst && !strcmp(cp, "Symbol")) {
			strcpy(cp, "TroffEmu-Symbol");
			skipsetup = 1;
		}
		for (i = 0; i < nfonts; i++)
			if (!strcmp(fonts[i].fontname, cp)) {
				gentle_cycle_check();
				tail = NULL;
				skipsetup = 1;
				goto definefont;
			}
repeatadd:	if (i >= 256) {
			fprintf(stderr,
		"%s: the merged document uses more than 256 different fonts\n",
				progname);
			exit(1);
		}
		for (sf = special_fonts; sf->fontname; sf++)
			if (!strcmp(cp, sf->fontname))
				break;
		if (sf->fontname) {
			if (sf->prereq_roman &&
			    font_prereq_roman(sf->prereq_roman)) {
				i = nfonts;
				goto repeatadd;
			}
			if (sf->prereq_special &&
			    font_prereq_special(sf->prereq_special)) {
				i = nfonts;
				goto repeatadd;
			}
			if (sf->prereq_misc &&
			    font_prereq_misc(sf->prereq_misc)) {
				i = nfonts;
				goto repeatadd;
			}
			special = 1;
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
		fonts[i].supplying = 0;
		nfonts++;
		tail = &fonts[i].setup;
definefont:	curdoc->fontmap[curdoc->nfonts++] = i;
		continue;
		/* a setup line for a font */
setupline:	if (skipsetup)
			continue;
		if (tail == NULL)
			goto invalid;
		setupline_check_encoding();
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
}

/*
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
	static char cline4[] = "currentdict end";

	for (i = 0; i < nfonts; i++)
		if (!strcmp(fonts[i].fontname, fontname))
			return(0);
	gentle_cycle_check();
	fonts[i].fontname = fontname;
	fonts[i].special = 0;
	fonts[i].supplying = 0;
	cp = malloc(sizeof(struct setupline) * 5 + strlen(fontname) + 24);
	if (!cp) {
		perror("malloc");
		exit(1);
	}
	sl = (struct setupline *)cp;
	cp += sizeof(struct setupline) * 5;
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
	sl[4].line = cp;
	sl[4].next = NULL;
	nfonts++;
	need_troffencoding = 1;
	return(1);
}

font_prereq_special(fontname)
	register char *fontname;
{
	register int i;

	for (i = 0; i < nfonts; i++)
		if (!strcmp(fonts[i].fontname, fontname))
			return(0);
	gentle_cycle_check();
	fonts[i].fontname = fontname;
	fonts[i].special = 1;
	fonts[i].supplying = 0;
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
	gentle_cycle_check();
	fonts[i].fontname = fontname;
	fonts[i].special = 0;
	fonts[i].supplying = 0;
	fonts[i].setup = NULL;
	nfonts++;
	return(1);
}

static char troffencoding_magic[] = "\t/Encoding TroffEncoding def";
static char cyrtroffencoding_magic[] = "\t/Encoding CyrTroffEncoding def";

setupline_check_encoding()
{
	if (!strcmp(srcline, troffencoding_magic))
		need_troffencoding = 1;
	else if (!strcmp(srcline, cyrtroffencoding_magic))
		need_cyrtroffencoding = 1;
}
