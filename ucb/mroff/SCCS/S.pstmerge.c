h21745
s 00018/00003/00910
d D 5.12 10/10/07 05:31:56 msokolov 12 11
c preliminary implementation of -L and -p
e
s 00030/00008/00883
d D 5.11 10/10/07 03:37:02 msokolov 11 10
c support for TroffEmu-SuperSpecial
e
s 00011/00001/00880
d D 5.10 10/08/23 17:52:25 msokolov 10 9
c should now handle merge chains with embedded resources
e
s 00113/00077/00768
d D 5.9 10/08/23 06:56:33 msokolov 9 8
c overhaul of special font handling
e
s 00010/00003/00835
d D 5.8 04/11/05 02:46:55 msokolov 8 7
c added -S option to work around the PostScript interpreter bug
c that breaks our use of Symbol with altered metrics
e
s 00138/00006/00700
d D 5.7 04/10/31 08:46:16 msokolov 7 6
c troffemu support
e
s 00015/00015/00691
d D 5.6 04/10/30 03:53:38 msokolov 6 5
c pstroff now uses a real procset!
e
s 00003/00000/00703
d D 5.5 04/10/26 22:40:17 msokolov 5 4
c don't strip leading zeros, it can break the spilled last byte of hex data
e
s 00000/00042/00703
d D 5.4 04/10/20 01:25:04 msokolov 4 3
c remove the ugly #ifdef DEBUG's
e
s 00048/00004/00697
d D 5.3 04/10/20 01:23:39 msokolov 3 2
c works
e
s 00004/00005/00697
d D 5.2 04/10/20 00:21:32 msokolov 2 1
c compiles
e
s 00702/00000/00000
d D 5.1 04/10/20 00:16:28 msokolov 1 0
c written
e
u
U
t
T
I 1
/*
 * Program for merging PostScript documents produced by pstroff.
I 9
 * Also performs some important finishing functions.
E 9
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/param.h>
#include <ctype.h>
#include <strings.h>
#include <stdio.h>

extern char *malloc();

/* PostScript ASCII encoding character classification */

#define	_PSS	010	/* PostScript white space */
#define _PSD	020	/* PostScript delimiter */
#define _PSR	040	/* PostScript regular */

char ps_ctype[1 + 256] = {
	0,
	_PSS,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*00*/
	_PSR,	_PSS,	_PSS,	_PSR,	_PSS,	_PSS,	_PSR,	_PSR,	/*08*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*10*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*18*/
	_PSS,	_PSR,	_PSR,	_PSR,	_PSR,	_PSD,	_PSR,	_PSR,	/*20*/
	_PSD,	_PSD,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSD,	/*28*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*30*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSD,	_PSR,	_PSD,	_PSR,	/*38*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*40*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*48*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*50*/
	_PSR,	_PSR,	_PSR,	_PSD,	_PSR,	_PSD,	_PSR,	_PSR,	/*58*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*60*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*68*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*70*/
	_PSR,	_PSR,	_PSR,	_PSD,	_PSR,	_PSD,	_PSR,	_PSR,	/*78*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*80*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*88*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*90*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*98*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*A0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*A8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*B0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*B8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*C0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*C8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*D0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*D8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*E0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*E8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*F0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR	/*F8*/
};

#define	isPSspace(c)	((ps_ctype+1)[c]&_PSS)
#define	isPSdelim(c)	((ps_ctype+1)[c]&_PSD)
#define	isPSreg(c)	((ps_ctype+1)[c]&_PSR)

struct srcdoc {
	char *filename;
	off_t bodyoffset;
	int lineno;
	int nfonts;
	u_char fontmap[32];
};

struct fontdesc {
	char *fontname;
	struct setupline *setup;
I 7
D 9
	int supplying;
	char *expertfont;
E 9
I 9
	int special;
E 9
E 7
};

struct setupline {
	char *line;
	struct setupline *next;
};

I 9
struct specialfont {
	char *fontname;
	char *prereq_roman;
	char *prereq_expert;
I 11
	char *prereq_misc;
E 11
} special_fonts[] = {
D 11
	{"Troff5lig-Regular", NULL, NULL},
	{"Troff5lig-Italic", NULL, NULL},
	{"Troff5lig-Bold", NULL, NULL},
	{"TroffEmu-Times-Roman", "Times-Roman", "Troff5lig-Regular"},
	{"TroffEmu-Times-Italic", "Times-Italic", "Troff5lig-Italic"},
	{"TroffEmu-Times-Bold", "Times-Bold", "Troff5lig-Bold"},
	{"TroffEmu-Symbol", NULL, NULL},
	{NULL, NULL, NULL}
E 11
I 11
	{"Troff5lig-Regular", NULL, NULL, NULL},
	{"Troff5lig-Italic", NULL, NULL, NULL},
	{"Troff5lig-Bold", NULL, NULL, NULL},
	{"TroffEmu-Times-Roman", "Times-Roman", "Troff5lig-Regular", NULL},
	{"TroffEmu-Times-Italic", "Times-Italic", "Troff5lig-Italic", NULL},
	{"TroffEmu-Times-Bold", "Times-Bold", "Troff5lig-Bold", NULL},
	{"TroffEmu-Symbol", NULL, NULL, NULL},
	{"TroffEmu-SuperSpecial", NULL, "TroffEmu-Symbol", "ZapfDingbats"},
	{NULL, NULL, NULL, NULL}
E 11
};

I 12
struct procsetdesc {
	char *pathname;
	struct procsetdesc *next;
};
struct procsetdesc *procsetlist_head;
struct procsetdesc **procsetlist_tail = &procsetlist_head;
int languagelevel = 1;

E 12
E 9
int psout_omit_troffencoding;
int psout_8bit_strings;
I 7
D 8
int troffemu, supplyingfonts;
E 8
I 8
D 9
int troffemu, symbolbugfix, supplyingfonts;
E 9
I 9
int notfinal, symbolbugfix;
E 9
E 8
E 7
int sheetalign, outpagecnt;
int nsrcdocs, nfonts;
struct srcdoc *srcdocs, *curdoc;
struct fontdesc fonts[256];
FILE *srcfile;
char srcline[1024];
int ps_numbuf[2], ps_numcnt, ps_lastname, ps_hadout, ps_strlen;
u_char ps_strbuf[1024];

char psmagic[] = "%!PS-Adobe-3.0";
char creatorcomment[] = "%%Creator: 4.3BSD-Quasijarus PostScript troff";
char beginsetupcomment[] = "%%BeginSetup";
char endsetupcomment[] = "%%EndSetup";
char fontsetopen[] = "/fontset [";
char fontsetclose[] = "] def";
D 6
char SFdef[] =
D 3
	"/SF {exch fontset exch get exch 60 mul scalefont setfont} bind def\n";
char Pdef[] = "/P {3 1 roll moveto show} bind def\n";
E 3
I 3
	"/SF {exch fontset exch get exch 60 mul scalefont setfont} bind def";
char Pdef[] = "/P {3 1 roll moveto show} bind def";
E 6
E 3
char trailercomment[] = "%%Trailer";

main(argc, argv)
	char **argv;
{
	register int i;
	extern int optind;
	extern char *optarg;

D 7
	while ((i = getopt(argc, argv, "8Ns")) != EOF) {
E 7
I 7
D 8
	while ((i = getopt(argc, argv, "8NTs")) != EOF) {
E 8
I 8
D 9
	while ((i = getopt(argc, argv, "8NSTs")) != EOF) {
E 9
I 9
D 12
	while ((i = getopt(argc, argv, "8NSTis")) != EOF) {
E 12
I 12
	while ((i = getopt(argc, argv, "8L:NSTip:s")) != EOF) {
E 12
E 9
E 8
E 7
		switch (i) {
		case '8':
			psout_8bit_strings = 1;
			break;
I 12
		case 'L':
			languagelevel = atoi(optarg);
			break;
E 12
		case 'N':
			psout_omit_troffencoding = 1;
			break;
I 8
		case 'S':
			symbolbugfix = 1;
			break;
E 8
I 7
		case 'T':
D 9
			troffemu = 1;
E 9
I 9
			/* no longer needed, backward compat */
E 9
			break;
I 9
		case 'i':
			notfinal = 1;
			break;
I 12
		case 'p':
			/* insert named procset: to be implemented */
			break;
E 12
E 9
E 7
		case 's':
			sheetalign = 1;
			break;
		case '?':
D 7
usage:			fprintf(stderr, "usage: %s [-8Ns] psfiles...\n",
E 7
I 7
D 9
usage:			fprintf(stderr, "usage: %s [-8NTs] psfiles...\n",
E 9
I 9
D 10
usage:			fprintf(stderr, "usage: %s [-8Nis] psfiles...\n",
E 10
I 10
D 12
usage:			fprintf(stderr, "usage: %s [-8Ns] psfiles...\n",
E 12
I 12
		default:
usage:			fprintf(stderr, "usage: %s [-8LNSps] psfiles...\n",
E 12
E 10
E 9
E 7
				argv[0]);
			exit(1);
		}
	}
	if (!argv[optind])
		goto usage;
I 7
D 9
	if (troffemu && psout_omit_troffencoding) {
		fprintf(stderr, "%s: -N cannot be used with -T\n", argv[0]);
		exit(1);
	}
E 9
E 7

	nsrcdocs = argc - optind;
	srcdocs = (struct srcdoc *)malloc(sizeof(struct srcdoc) * nsrcdocs);
	if (!srcdocs) {
		perror("malloc");
		exit(1);
	}
	/* Go through the source files and figure out their fonts */
	for (i = optind, curdoc = srcdocs; i < argc; i++, curdoc++) {
		curdoc->filename = argv[i];
		pass1();
	}

	/* Emit merged document header */
	emit_merged_header();
	emit_merged_prolog();
	emit_merged_setup();

	for (i = 0, curdoc = srcdocs; i < nsrcdocs; i++, curdoc++)
		pass2();

	/* Done! */
	puts(trailercomment);
	printf("%%%%Pages: %d\n", outpagecnt);
	puts("%%EOF");
	return(0);
}

pass1()
{
D 2
	register setupline **tail;
E 2
I 2
	register struct setupline *sl, **tail;
E 2
D 9
	register int skipsetup;
E 9
I 9
	int skipsetup;
E 9
	register char *cp;
	register int i;
I 7
D 9
	int supplying;
	char *expertfont;
E 9
I 9
	register struct specialfont *sf;
	int special;
E 9
E 7
D 2
	register struct setupline *sl;
E 2

	srcfile = fopen(curdoc->filename, "r");
	if (!srcfile) {
		perror(curdoc->filename);
		exit(1);
	}
	curdoc->lineno = 0;
	getline();
	if (strcmp(srcline, psmagic)) {
		fprintf(stderr, "%s is not a valid PostScript file\n",
			curdoc->filename);
		exit(1);
	}
	getline();
	if (strcmp(srcline, creatorcomment)) {
		fprintf(stderr, "%s is not pstroff output\n", curdoc->filename);
		exit(1);
	}
	do
		getline();
	while (strcmp(srcline, beginsetupcomment));
	getline();
	if (strcmp(srcline, fontsetopen)) {
invalid:	fprintf(stderr, "%s: invalid setup section (line %d)\n",
			curdoc->filename, curdoc->lineno);
		exit(1);
	}
	curdoc->nfonts = 0;
	for (tail = NULL, skipsetup = 0; ; ) {
		getline();
		if (srcline[0] == ']')
			break;
I 10
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
E 10
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
			fprintf(stderr, "%s uses more than 32 fonts\n",
				curdoc->filename);
			exit(1);
		}
I 8
		skipsetup = 0;
		if (symbolbugfix && !strcmp(cp, "Symbol")) {
			strcpy(cp, "TroffEmu-Symbol");
			skipsetup = 1;
		}
E 8
		for (i = 0; i < nfonts; i++)
			if (!strcmp(fonts[i].fontname, cp)) {
				tail = NULL;
				skipsetup = 1;
				goto definefont;
			}
D 7
		if (i >= 256) {
E 7
I 7
D 9
		supplying = 0;
		expertfont = NULL;
E 9
repeatadd:	if (i >= 256) {
E 7
fputs("the merged document uses more than 256 different fonts\n", stderr);
			exit(1);
		}
I 7
D 9
		if (troffemu) {
			if (!strcmp(cp, "TroffEmu-Times-Roman")) {
				if (font_prerequisite("Times-Roman")) {
					i = nfonts;
					goto repeatadd;
				}
				supplying = 1;
				supplyingfonts = 1;
				expertfont = "AGaramondExp-Regular";
			} else if (!strcmp(cp, "TroffEmu-Times-Italic")) {
				if (font_prerequisite("Times-Italic")) {
					i = nfonts;
					goto repeatadd;
				}
				supplying = 1;
				supplyingfonts = 1;
				expertfont = "AGaramondExp-Italic";
			} else if (!strcmp(cp, "TroffEmu-Times-Bold")) {
				if (font_prerequisite("Times-Bold")) {
					i = nfonts;
					goto repeatadd;
				}
				supplying = 1;
				supplyingfonts = 1;
				expertfont = "AGaramondExp-Bold";
			} else if (!strcmp(cp, "TroffEmu-Symbol")) {
				supplying = 1;
				supplyingfonts = 1;
E 9
I 9
		for (sf = special_fonts; sf->fontname; sf++)
			if (!strcmp(cp, sf->fontname))
				break;
		if (sf->fontname) {
			if (sf->prereq_roman &&
			    font_prereq_roman(sf->prereq_roman)) {
				i = nfonts;
				goto repeatadd;
			}
			if (sf->prereq_expert &&
			    font_prereq_expert(sf->prereq_expert)) {
				i = nfonts;
				goto repeatadd;
			}
I 11
			if (sf->prereq_misc &&
			    font_prereq_misc(sf->prereq_misc)) {
				i = nfonts;
				goto repeatadd;
			}
E 11
			special = 1;
			if (psout_omit_troffencoding) {
				fprintf(stderr,
				"%s uses special fonts, -N not allowed\n",
					curdoc->filename);
				exit(1);
E 9
			}
D 9
		}
E 9
I 9
		} else
			special = 0;
E 9
E 7
		cp = malloc(strlen(cp) + 1);
		if (!cp) {
mallocfail:		perror("malloc");
			exit(1);
		}
		strcpy(cp, srcline + 1);
		fonts[i].fontname = cp;
		fonts[i].setup = NULL;
I 7
D 9
		fonts[i].supplying = supplying;
		fonts[i].expertfont = expertfont;
E 9
I 9
		fonts[i].special = special;
E 9
E 7
		nfonts++;
		tail = &fonts[i].setup;
D 8
		skipsetup = 0;
E 8
definefont:	curdoc->fontmap[curdoc->nfonts++] = i;
		continue;
		/* a setup line for a font */
setupline:	if (skipsetup)
			continue;
		if (tail == NULL)
			goto invalid;
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
D 6
	if (strcmp(srcline, SFdef))
		goto invalid;
	getline();
	if (strcmp(srcline, Pdef))
		goto invalid;
	getline();
E 6
	if (strcmp(srcline, endsetupcomment))
		goto invalid;
	curdoc->bodyoffset = ftell(srcfile);
	fclose(srcfile);
}

getline()
{
	register char *cp;

	fgets(srcline, sizeof(srcline), srcfile);
	if (ferror(srcfile)) {
		perror(curdoc->filename);
		exit(1);
	}
	if (feof(srcfile)) {
		fprintf(stderr, "%s: premature EOF\n", curdoc->filename);
		exit(1);
	}
	curdoc->lineno++;
	cp = index(srcline, '\n');
	if (cp == NULL) {
		fprintf(stderr, "%s: line %d is too long\n", curdoc->filename,
			curdoc->lineno);
		exit(1);
	}
	*cp = '\0';
}

I 7
D 9
font_prerequisite(fontname)
E 9
I 9
/*
 * XXX the following kludge is just plain ugly: we are effectively
 * replicating an ad hoc version of preppsfont here
 */

font_prereq_roman(fontname)
E 9
	register char *fontname;
{
	register int i;
	register char *cp;
	register struct setupline *sl;
	static char cline1[] = "dup length dict begin";
	static char cline2[] =
			"\t{1 index /FID ne {def} {pop pop} ifelse} forall";
	static char cline3[] = "\t/Encoding TroffEncoding def";
	static char cline4[] = "\tcurrentdict";
	static char cline5[] = "end";

	for (i = 0; i < nfonts; i++)
		if (!strcmp(fonts[i].fontname, fontname))
			return(0);
	fonts[i].fontname = fontname;
D 9
	fonts[i].supplying = 0;
	fonts[i].expertfont = NULL;
E 9
I 9
	fonts[i].special = 0;
E 9
	cp = malloc(sizeof(struct setupline) * 6 + strlen(fontname) + 24);
	sl = (struct setupline *)cp;
	cp += sizeof(struct setupline) * 6;
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
	sl[4].line = cline5;
	sl[4].next = sl + 5;
	sl[5].line = cp;
	sl[5].next = NULL;
	nfonts++;
	return(1);
}

I 9
font_prereq_expert(fontname)
	register char *fontname;
{
	register int i;

	for (i = 0; i < nfonts; i++)
		if (!strcmp(fonts[i].fontname, fontname))
			return(0);
	fonts[i].fontname = fontname;
	fonts[i].special = 1;
I 11
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
	fonts[i].fontname = fontname;
	fonts[i].special = 0;
E 11
	fonts[i].setup = NULL;
	nfonts++;
	return(1);
}

E 9
E 7
emit_merged_header()
{
	register int i, in_line = 0, started = 0;
I 7
	register char *fname;
I 9
	int supplyingfonts = 0;
E 9
E 7

	puts(psmagic);
	puts(creatorcomment);
	if (!psout_8bit_strings)
		puts("%%DocumentData: Clean7Bit");
	else
		puts("%%DocumentData: Clean8Bit");
D 12
	puts("%%LanguageLevel: 1");
E 12
I 12
	printf("%%%%LanguageLevel: %d\n", languagelevel);
E 12
	for (i = 0; i < nfonts; i++) {
D 7
		if (in_line && in_line + strlen(fonts[i].fontname) + 1 > 80) {
E 7
I 7
D 9
		if (!fonts[i].supplying)
			fname = fonts[i].fontname;
		else
			fname = fonts[i].expertfont;
		if (!fname)
E 9
I 9
		if (fonts[i].special && !notfinal) {
			supplyingfonts = 1;
E 9
			continue;
I 9
		}
		fname = fonts[i].fontname;
E 9
		if (in_line && in_line + strlen(fname) + 1 > 80) {
E 7
			putchar('\n');
			in_line = 0;
		}
		if (!in_line) {
			if (!started) {
				fputs("%%DocumentNeededResources:", stdout);
				in_line = 26;
				started = 1;
			} else {
				fputs("%%+", stdout);
				in_line = 3;
			}
			fputs(" font", stdout);
			in_line += 5;
		}
D 7
		printf(" %s", fonts[i].fontname);
		in_line += strlen(fonts[i].fontname) + 1;
E 7
I 7
		printf(" %s", fname);
		in_line += strlen(fname) + 1;
E 7
	}
	if (in_line)
		putchar('\n');
I 6
	if (!psout_omit_troffencoding)
		puts("%%DocumentSuppliedResources: encoding TroffEncoding");
I 7
	if (supplyingfonts) {
		for (i = 0, in_line = 0; i < nfonts; i++) {
D 9
			if (!fonts[i].supplying)
E 9
I 9
			if (!fonts[i].special)
E 9
				continue;
			fname = fonts[i].fontname;
			if (in_line && in_line + strlen(fname) + 1 > 80) {
				putchar('\n');
				in_line = 0;
			}
			if (!in_line) {
				fputs("%%+ font", stdout);
				in_line = 8;
			}
			printf(" %s", fname);
			in_line += strlen(fname) + 1;
		}
		if (in_line)
			putchar('\n');
	}
E 7
E 6
	puts("%%Pages: (atend)");
	puts("%%EndComments");
}

emit_merged_prolog()
{
D 2
	register FILE f;
E 2
I 2
	register FILE *f;
E 2
	register int ch;
I 6
	static char troffprcfile[] = "/usr/lib/pstroff/TroffProcset.ps";
E 6
	static char troffencfile[] = "/usr/lib/pstroff/TroffEncoding.ps";

D 6
	if (psout_omit_troffencoding)
		return;
E 6
	puts("%%BeginProlog");
D 6
	f = fopen(troffencfile, "r");
E 6
I 6
D 9
	f = fopen(troffprcfile, "r");
E 6
	if (!f) {
D 6
		perror(troffencfile);
E 6
I 6
		perror(troffprcfile);
E 6
		exit(1);
	}
D 2
	for ((ch = getc(f)) >= 0)
E 2
I 2
	while ((ch = getc(f)) >= 0)
E 2
		putchar(ch);
	fclose(f);
I 6
	if (!psout_omit_troffencoding) {
		f = fopen(troffencfile, "r");
		if (!f) {
			perror(troffencfile);
			exit(1);
		}
		while ((ch = getc(f)) >= 0)
			putchar(ch);
		fclose(f);
	}
E 9
I 9
	emit_resource_file(troffprcfile);
	if (!psout_omit_troffencoding)
		emit_resource_file(troffencfile);
E 9
E 6
	puts("%%EndProlog");
}

emit_merged_setup()
{
	register int i;
	register struct setupline *s;

	puts(beginsetupcomment);
	puts(fontsetopen);
	for (i = 0; i < nfonts; i++) {
I 7
D 9
		if (fonts[i].supplying)
			supply_font(fonts[i].fontname);
E 9
I 9
		if (fonts[i].special && !notfinal)
			supply_special_font(fonts[i].fontname);
E 9
E 7
		printf("/%s findfont\n", fonts[i].fontname);
		for (s = fonts[i].setup; s; s = s->next)
			puts(s->line);
	}
	puts(fontsetclose);
D 6
	puts(SFdef);
	puts(Pdef);
E 6
	puts(endsetupcomment);
I 7
}

D 9
supply_font(fontname)
E 9
I 9
supply_special_font(fontname)
E 9
	char *fontname;
{
	char filename[64];
I 9

	sprintf(filename, "/usr/lib/pstroff/specialfonts/%s.ps", fontname);
	emit_resource_file(filename);
}

emit_resource_file(filename)
	char *filename;
{
E 9
	register FILE *f;
I 9
	char linebuf[512];
	int lineno;
E 9
	register int ch;

D 9
	sprintf(filename, "/usr/lib/pstroff/troffemu/%s.ps", fontname);
E 9
	f = fopen(filename, "r");
	if (!f) {
		perror(filename);
		exit(1);
	}
I 9
	for (lineno = 1; ; lineno++) {
		if (!fgets(linebuf, sizeof linebuf, f)) {
			fprintf(stderr, "%s: EOF before %%%%BeginResource\n",
				filename);
			exit(1);
		}
		if (!strncmp(linebuf, "%%BeginResource:", 16))
			break;
		if (linebuf[0] != '%') {
			fprintf(stderr,
		"%s: line %d: non-comment line before %%%%BeginResource\n",
				filename, lineno);
			exit(1);
		}
		/* discard comment line */
	}
	/* emit the %%BeginResource line and everything thereafter */
	fputs(linebuf, stdout);
E 9
	while ((ch = getc(f)) >= 0)
		putchar(ch);
	fclose(f);
I 9
	return(0);
E 9
E 7
}

flush_nums()
{
	register int i;

	for (i = 0; i < ps_numcnt; i++) {
I 3
D 4
#ifdef DEBUG
		fprintf(stderr, "flushing num: %d\n", ps_numbuf[i]);
#endif
E 4
E 3
		if (ps_lastname)
			putchar(' ');
		printf("%d", ps_numbuf[i]);
		ps_lastname = 1;
		ps_hadout = 1;
	}
	ps_numcnt = 0;
}

char *
get_ascii_string(start)
	char *start;
{
	register char *cp;
	register u_char *dp;
	register int ch;
	int parcnt = 1;

I 3
D 4
#ifdef DEBUG
	fprintf(stderr, "entered get_ascii_string()\n");
#endif
E 4
E 3
	for (cp = start + 1, dp = ps_strbuf; ; ) {
		ch = *cp++;
		switch (ch) {
		case '\0':
invbrk:			fprintf(stderr,
		"%s: line %d: ASCII string spans line boundary (unsupported)\n",
				curdoc->filename, curdoc->lineno);
			exit(1);
		case '(':
			parcnt++;
			break;
		case ')':
			parcnt--;
			if (!parcnt)
				goto done;
			break;
		case '\\':
			ch = *cp++;
			switch (ch) {
			case '\0':
				goto invbrk;
			case 'b':
				*dp++ = '\b';
				break;
			case 'f':
				*dp++ = '\f';
				break;
			case 'n':
				*dp++ = '\n';
				break;
			case 'r':
				*dp++ = '\r';
				break;
			case 't':
				*dp++ = '\t';
				break;
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
				ch -= '0';
				if (*cp >= '0' && *cp <= '7')
					ch = (ch << 3) | (*cp++ - '0');
				if (*cp >= '0' && *cp <= '7')
					ch = (ch << 3) | (*cp++ - '0');
				/*FALLTHRU*/
			default:
				*dp++ = ch;
			}
			break;
		default:
			*dp++ = ch;
		}
	}
done:	ps_strlen = dp - ps_strbuf;
	return(cp);
}

char *
get_hex_string(start)
	char *start;
{
	register char *cp;
	register u_char *dp;
	register int ch, byte;

I 3
D 4
#ifdef DEBUG
	fprintf(stderr, "entered get_hex_string()\n");
#endif
E 4
E 3
	for (cp = start + 1, dp = ps_strbuf; ; ) {
		do
			ch = *cp++;
		while (isspace(ch));
		if (ch == '>')
			break;
		if (!isxdigit(ch))
			goto inv;
		if (isdigit(ch))
			byte = ch - '0';
		else if (isupper(ch))
			byte = ch - 'A' + 10;
		else
			byte = ch - 'a' + 10;
		byte <<= 4;
		do
			ch = *cp++;
		while (isspace(ch));
		if (ch == '>') {
			ch = '0';
			cp--;
		}
		if (!isxdigit(ch))
			goto inv;
		if (isdigit(ch))
			byte |= ch - '0';
		else if (isupper(ch))
			byte |= ch - 'A' + 10;
		else
			byte |= ch - 'a' + 10;
		*dp++ = byte;
	}
	ps_strlen = dp - ps_strbuf;
	return(cp);

inv:	if (!ch)
		fprintf(stderr,
		"%s: line %d: hex string spans line boundary (unsupported)\n",
			curdoc->filename, curdoc->lineno);
	else
		fprintf(stderr, "%s: line %d: invalid hex string\n",
			curdoc->filename, curdoc->lineno);
	exit(1);
}

string_out()
{
	u_char *end = ps_strbuf + ps_strlen;
	register u_char *cp;
	register int ch;
	int asclen;

I 3
D 4
#ifdef DEBUG
	fprintf(stderr, "entered string_out()\n");
#endif
E 4
E 3
	for (cp = ps_strbuf, asclen = 0; cp < end; cp++) {
		ch = *cp;
		if (ch<0x20 || ch>=0x7F && (!psout_8bit_strings || ch<=0x9F))
			asclen += 4;
		else if (ch == '(' || ch == ')' || ch == '\\')
			asclen += 2;
		else
			asclen++;
	}
	if (asclen <= (ps_strlen << 1)) {
		/* ASCII output */
I 3
D 4
#ifdef DEBUG
		fprintf(stderr, "emitting ASCII string\n");
#endif
E 4
E 3
		putchar('(');
		for (cp = ps_strbuf; cp < end; cp++) {
			ch = *cp;
			if (ch<0x20 || ch>=0x7F &&
			    (!psout_8bit_strings || ch<=0x9F))
D 3
				printf("%03o", ch);
E 3
I 3
				printf("\\%03o", ch);
E 3
			else {
				if (ch == '(' || ch == ')' || ch == '\\')
					putchar('\\');
				putchar(ch);
			}
		}
		putchar(')');
	} else {
		/* hex output */
I 3
D 4
#ifdef DEBUG
		fprintf(stderr, "emitting hex string\n");
#endif
E 4
E 3
		putchar('<');
		for (cp = ps_strbuf; cp < end; cp++)
			printf("%02X", *cp);
		putchar('>');
	}
	ps_lastname = 0;
	ps_hadout = 1;
}

pass2()
{
	register char *cp, *np;
	char saved_delim = 0;

	if (sheetalign && (outpagecnt & 1))
		printf("%%%%Page: blank %d\nshowpage\n", ++outpagecnt);
	srcfile = fopen(curdoc->filename, "r");
	if (!srcfile) {
		perror(curdoc->filename);
		exit(1);
	}
D 2
	fseek(srcfile, srcdoc->bodyoffset, 0);
E 2
I 2
	fseek(srcfile, curdoc->bodyoffset, 0);
E 2
	for (;;) {
		getline();
		if (!strcmp(srcline, trailercomment))
			break;
		if (!strncmp(srcline, "%%Page:", 7)) {
			for (cp = srcline + 7; isspace(*cp); cp++)
				;
			if (!isgraph(*cp)) {
invpage:			fprintf(stderr,
				"%s: line %d: invalid %%%%Page: comment\n",
					curdoc->filename, curdoc->lineno);
				exit(1);
			}
			for (np = cp; isgraph(*cp); cp++)
				;
			if (!isspace(*cp))
				goto invpage;
			*cp = '\0';
			printf("%%%%Page: %s %d\n", np, ++outpagecnt);
			continue;
		}
		/* pass all other full line comments through as is */
		if (srcline[0] == '%') {
			puts(srcline);
			continue;
		}
		/* The hard work begins: parse actual PS code */
I 3
D 4
#ifdef DEBUG
		fprintf(stderr, "processing PS code line %d\n", curdoc->lineno);
#endif
E 4
E 3
		ps_numcnt = ps_lastname = ps_hadout = 0;
		for (cp = srcline; ; ) {
I 3
D 4
#ifdef DEBUG
			fprintf(stderr, "start of token loop\n");
#endif
E 4
E 3
			/* skip preceding whitespace first */
			while (*cp && isPSspace(*cp))
				cp++;
			switch (*cp) {
			case '\0':
			case '%':
				goto endpsline;
			case '(':
				flush_nums();
				cp = get_ascii_string(cp);
				string_out();
				break;
			case ')':
				flush_nums();
				fprintf(stderr, "%s: line %d: unmatched ')'\n",
					curdoc->filename, curdoc->lineno);
				exit(1);
			case '<':
				flush_nums();
				cp = get_hex_string(cp);
				string_out();
				break;
			case '>':
				flush_nums();
				fprintf(stderr, "%s: line %d: unmatched '>'\n",
					curdoc->filename, curdoc->lineno);
				exit(1);
			case '[':
			case ']':
			case '{':
			case '}':
				flush_nums();
I 3
D 4
#ifdef DEBUG
				fprintf(stderr, "emitting %c token\n", *cp);
#endif
E 4
E 3
				putchar(*cp++);
				ps_lastname = 0;
				ps_hadout = 1;
				break;
			case '/':
				flush_nums();
I 3
D 4
#ifdef DEBUG
				fprintf(stderr, "emitting literal name\n");
#endif
E 4
E 3
				putchar(*cp++);
				if (!isPSreg(*cp)) {
					fprintf(stderr,
		"%s: line %d: '/' must be followed by a regular character\n",
					curdoc->filename, curdoc->lineno);
					exit(1);
				}
				while (isPSreg(*cp))
					putchar(*cp++);
				ps_lastname = 1;
				ps_hadout = 1;
				break;
			default:
				for (np = cp; isPSreg(*cp); cp++)
					;
				if (isPSspace(*cp) && *cp)
					*cp++ = '\0';
				else if (isPSdelim(*cp)) {
					saved_delim = *cp;
					*cp = '\0';
				}
				if (is_short_num(np)) {
I 3
D 4
#ifdef DEBUG
	fprintf(stderr, "got number\n");
#endif
E 4
E 3
					if (ps_numcnt == 2) {
						if (ps_lastname)
							putchar(' ');
						printf("%d", ps_numbuf[0]);
						ps_lastname = 1;
						ps_hadout = 1;
						ps_numbuf[0] = ps_numbuf[1];
						ps_numcnt = 1;
					}
					ps_numbuf[ps_numcnt++] = atoi(np);
				} else {
I 3
D 4
#ifdef DEBUG
	fprintf(stderr, "got name\n");
#endif
E 4
E 3
					if (!strcmp(np, "SF"))
						handle_SF();
					flush_nums();
I 3
D 4
#ifdef DEBUG
	fprintf(stderr, "emitting name %s\n", np);
#endif
E 4
E 3
					if (ps_lastname)
						putchar(' ');
					fputs(np, stdout);
					ps_lastname = 1;
					ps_hadout = 1;
				}
D 3
				if (saved_delim)
E 3
I 3
				if (saved_delim) {
E 3
					*cp = saved_delim;
I 3
					saved_delim = 0;
				}
E 3
			}
		}
endpsline:	flush_nums();
I 3
D 4
#ifdef DEBUG
		fprintf(stderr, "closing line %d\n", curdoc->lineno);
#endif
E 4
E 3
		if (ps_hadout)
			putchar('\n');
	}
	fclose(srcfile);
}

is_short_num(str)
	char *str;
{
	register char *cp;
	register int len;

	for (cp = str, len = 0; *cp; cp++) {
		if (++len > 3)
			return(0);
		if (!isdigit(*cp))
			return(0);
	}
I 5
	/* If it has leading zeros, it isn't for SF and let's leave it alone */
	if (str[0] == '0' && len > 1)
		return(0);
E 5
	return(1);
}

handle_SF()
{
	if (ps_numcnt != 2) {
		fprintf(stderr,
			"%s: line %d: SF must be preceded by two numbers\n",
			curdoc->filename, curdoc->lineno);
		exit(1);
	}
	if (ps_numbuf[0] >= curdoc->nfonts) {
		fprintf(stderr,
		"%s: line %d: %d %d SF requests font number out of range\n",
			curdoc->filename, curdoc->lineno, ps_numbuf[0],
			ps_numbuf[1]);
		exit(1);
	}
	ps_numbuf[0] = curdoc->fontmap[ps_numbuf[0]];
}
E 1
