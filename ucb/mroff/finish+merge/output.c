/*
 * Pstmerge is a program for merging PostScript documents produced by pstroff;
 * it also performs some important finishing functions.
 *
 * Written by Michael Spacefalcon, Quasijarus Project,
 * International Free Computing Task Force.
 *
 * This module handles the generation of the header, prolog and setup
 * sections of the output document.
 */

#ifndef lint
static char sccsid[] = "@(#)output.c	5.6 (Berkeley) 2012/07/22";
#endif

#include <sys/types.h>
#include <sys/file.h>
#include <strings.h>
#include <stdio.h>
#include "struct.h"

extern int languagelevel;
extern int psout_omit_troffencoding;
extern int psout_8bit_strings;
extern int notfinal;
extern int strokeadjust;
extern int need_troffencoding, need_cyrtroffencoding, need_bdprocset;
extern struct fontdesc fonts[];
extern int nfonts;
extern int Fflag;
extern int outpagecnt;

extern char psmagic[];
extern char creatorcomment[];
extern char beginsetupcomment[];
extern char endsetupcomment[];
extern char fontsetopen[];
extern char fontsetclose[];
extern char trailercomment[];

emit_merged_header()
{
	register int i, in_line = 0, started;
	register char *fname;
	int supplyingfonts = 0;

	puts(psmagic);
	puts(creatorcomment);
	if (!psout_8bit_strings)
		puts("%%DocumentData: Clean7Bit");
	else
		puts("%%DocumentData: Clean8Bit");
	printf("%%%%LanguageLevel: %d\n", languagelevel);
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
	for (i = 0; i < nfonts; i++) {
		if (fonts[i].special && !notfinal || fonts[i].supplying) {
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
	if (!psout_omit_troffencoding &&
	    (need_troffencoding || need_cyrtroffencoding)) {
		fputs("%%DocumentSuppliedResources: encoding", stdout);
		if (need_troffencoding)
			fputs(" TroffEncoding", stdout);
		if (need_cyrtroffencoding)
			fputs(" CyrTroffEncoding", stdout);
		putchar('\n');
		started = 1;
	} else
		started = 0;
	if (supplyingfonts) {
		for (i = 0, in_line = 0; i < nfonts; i++) {
			if (!fonts[i].special && !fonts[i].supplying)
				continue;
			fname = fonts[i].fontname;
			if (in_line && in_line + strlen(fname) + 1 > 80) {
				putchar('\n');
				in_line = 0;
			}
			if (!in_line) {
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
	static char cyrencfile[] = "/usr/lib/pstroff/CyrTroffEncoding.ps";
	static char bdprocsetfile[] = "/usr/lib/pstroff/bdprocset.ps";

	puts("%%BeginProlog");
	emit_resource_file(troffprcfile);
	if (need_bdprocset)
		emit_resource_file(bdprocsetfile);
	if (!psout_omit_troffencoding) {
		if (need_troffencoding)
			emit_resource_file(troffencfile);
		if (need_cyrtroffencoding)
			emit_resource_file(cyrencfile);
	}
	puts("%%EndProlog");
}

emit_merged_setup()
{
	register int i;
	register struct setupline *s;

	puts(beginsetupcomment);
	if (Fflag)
		Fflag_emit_fonts();
	printf("/setstrokeadjust where {pop %s setstrokeadjust} if\n",
		strokeadjust ? "true" : "false");
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
}

emit_final_trailer()
{
	puts(trailercomment);
	printf("%%%%Pages: %d\n", outpagecnt);
	puts("%%EOF");
}
