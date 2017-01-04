h41529
s 00003/00000/00243
d D 5.6 2012/07/22 01:53:51 msokolov 6 5
c setstrokeadjust insertion and -n option implemented
e
s 00004/00001/00239
d D 5.5 2012/07/22 01:42:23 msokolov 5 4
c implemented .bd procset preservation and skipping of extra setup
e
s 00028/00005/00212
d D 5.4 2012/07/18 05:48:46 msokolov 4 3
c smart recognition of TroffEncoding and CyrTroffEncoding implemented
e
s 00010/00001/00207
d D 5.3 2012/07/18 03:59:29 msokolov 3 2
c trailer generation moved here from main()
e
s 00037/00005/00171
d D 5.2 10/10/09 04:30:38 msokolov 2 1
c added -F option (font embedding)
e
s 00176/00000/00000
d D 5.1 10/10/08 06:51:48 msokolov 1 0
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
D 3
 * Written by Michael Sokolov, Quasijarus Project,
E 3
I 3
 * Written by Michael Spacefalcon, Quasijarus Project,
E 3
 * International Free Computing Task Force.
 *
 * This module handles the generation of the header, prolog and setup
 * sections of the output document.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/types.h>
I 2
#include <sys/file.h>
E 2
#include <strings.h>
#include <stdio.h>
#include "struct.h"

extern int languagelevel;
extern int psout_omit_troffencoding;
extern int psout_8bit_strings;
extern int notfinal;
I 6
extern int strokeadjust;
E 6
I 4
D 5
extern int need_troffencoding, need_cyrtroffencoding;
E 5
I 5
extern int need_troffencoding, need_cyrtroffencoding, need_bdprocset;
E 5
E 4
extern struct fontdesc fonts[];
extern int nfonts;
I 2
extern int Fflag;
I 3
extern int outpagecnt;
E 3
E 2

extern char psmagic[];
extern char creatorcomment[];
extern char beginsetupcomment[];
extern char endsetupcomment[];
extern char fontsetopen[];
extern char fontsetclose[];
I 3
extern char trailercomment[];
E 3

emit_merged_header()
{
D 4
	register int i, in_line = 0, started = 0;
E 4
I 4
	register int i, in_line = 0, started;
E 4
	register char *fname;
	int supplyingfonts = 0;

	puts(psmagic);
	puts(creatorcomment);
	if (!psout_8bit_strings)
		puts("%%DocumentData: Clean7Bit");
	else
		puts("%%DocumentData: Clean8Bit");
	printf("%%%%LanguageLevel: %d\n", languagelevel);
I 4
	if (psout_omit_troffencoding &&
	    (need_troffencoding || need_cyrtroffencoding)) {
		fputs("%%DocumentNeededResources: encoding", stdout);
		if (need_troffencoding)
			fputs(" TroffEncoding", stdout);
		if (need_cyrtroffencoding)
			fputs(" CyrTroffEncoding", stdout);
		putchar('\n');
		started = 1;
	} else
		started = 0;
E 4
	for (i = 0; i < nfonts; i++) {
D 2
		if (fonts[i].special && !notfinal) {
E 2
I 2
		if (fonts[i].special && !notfinal || fonts[i].supplying) {
E 2
			supplyingfonts = 1;
			continue;
		}
		fname = fonts[i].fontname;
		if (in_line && in_line + strlen(fname) + 1 > 80) {
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
		printf(" %s", fname);
		in_line += strlen(fname) + 1;
	}
	if (in_line)
		putchar('\n');
D 2
	if (!psout_omit_troffencoding)
E 2
I 2
D 4
	if (!psout_omit_troffencoding) {
E 2
		puts("%%DocumentSuppliedResources: encoding TroffEncoding");
E 4
I 4
	if (!psout_omit_troffencoding &&
	    (need_troffencoding || need_cyrtroffencoding)) {
		fputs("%%DocumentSuppliedResources: encoding", stdout);
		if (need_troffencoding)
			fputs(" TroffEncoding", stdout);
		if (need_cyrtroffencoding)
			fputs(" CyrTroffEncoding", stdout);
		putchar('\n');
E 4
I 2
		started = 1;
	} else
		started = 0;
E 2
	if (supplyingfonts) {
		for (i = 0, in_line = 0; i < nfonts; i++) {
D 2
			if (!fonts[i].special)
E 2
I 2
			if (!fonts[i].special && !fonts[i].supplying)
E 2
				continue;
			fname = fonts[i].fontname;
			if (in_line && in_line + strlen(fname) + 1 > 80) {
				putchar('\n');
				in_line = 0;
			}
			if (!in_line) {
D 2
				fputs("%%+ font", stdout);
				in_line = 8;
E 2
I 2
				if (!started) {
					fputs("%%DocumentSuppliedResources:",
						stdout);
					in_line = 28;
					started = 1;
				} else {
					fputs("%%+", stdout);
					in_line = 3;
				}
				fputs(" font", stdout);
				in_line += 5;
E 2
			}
			printf(" %s", fname);
			in_line += strlen(fname) + 1;
		}
		if (in_line)
			putchar('\n');
	}
	puts("%%Pages: (atend)");
	puts("%%EndComments");
}

emit_merged_prolog()
{
	register FILE *f;
	register int ch;
	static char troffprcfile[] = "/usr/lib/pstroff/TroffProcset.ps";
	static char troffencfile[] = "/usr/lib/pstroff/TroffEncoding.ps";
I 4
	static char cyrencfile[] = "/usr/lib/pstroff/CyrTroffEncoding.ps";
I 5
	static char bdprocsetfile[] = "/usr/lib/pstroff/bdprocset.ps";
E 5
E 4

	puts("%%BeginProlog");
	emit_resource_file(troffprcfile);
I 5
	if (need_bdprocset)
		emit_resource_file(bdprocsetfile);
E 5
D 4
	if (!psout_omit_troffencoding)
		emit_resource_file(troffencfile);
E 4
I 4
	if (!psout_omit_troffencoding) {
		if (need_troffencoding)
			emit_resource_file(troffencfile);
		if (need_cyrtroffencoding)
			emit_resource_file(cyrencfile);
	}
E 4
	puts("%%EndProlog");
}

emit_merged_setup()
{
	register int i;
	register struct setupline *s;

	puts(beginsetupcomment);
I 2
	if (Fflag)
		Fflag_emit_fonts();
I 6
	printf("/setstrokeadjust where {pop %s setstrokeadjust} if\n",
		strokeadjust ? "true" : "false");
E 6
E 2
	puts(fontsetopen);
	for (i = 0; i < nfonts; i++) {
		if (fonts[i].special && !notfinal)
			supply_special_font(fonts[i].fontname);
		printf("/%s findfont\n", fonts[i].fontname);
		for (s = fonts[i].setup; s; s = s->next)
			puts(s->line);
	}
	puts(fontsetclose);
	puts(endsetupcomment);
}

supply_special_font(fontname)
	char *fontname;
{
	char filename[64];

	sprintf(filename, "/usr/lib/pstroff/specialfonts/%s.ps", fontname);
	emit_resource_file(filename);
}

emit_resource_file(filename)
	char *filename;
{
	register FILE *f;
	char linebuf[512];
	int lineno;
	register int ch;

	f = fopen(filename, "r");
	if (!f) {
		perror(filename);
		exit(1);
	}
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
	while ((ch = getc(f)) >= 0)
		putchar(ch);
	fclose(f);
	return(0);
I 2
}

emit_raw_file(filename)
	char *filename;
{
	char buf[8192];
	register int fd, cc;

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		perror(filename);
		exit(1);
	}
	while ((cc = read(fd, buf, sizeof buf)) > 0)
		fwrite(buf, 1, cc, stdout);
	close(fd);
I 3
}

emit_final_trailer()
{
	puts(trailercomment);
	printf("%%%%Pages: %d\n", outpagecnt);
	puts("%%EOF");
E 3
E 2
}
E 1
