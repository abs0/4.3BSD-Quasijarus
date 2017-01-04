/*
 * This module contains global variables and functions which are
 * common between pstmerge and pstfinish.
 *
 * Written by Michael Spacefalcon, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "@(#)common.c	5.5 (Berkeley) 2012/07/22";
#endif

#include <sys/types.h>
#include <strings.h>
#include <stdio.h>
#include "struct.h"

int languagelevel = 1;
int psout_omit_troffencoding;
int psout_8bit_strings;
int notfinal, symbolsubst, gentlewash;
int strokeadjust = 1;
int sheetalign, outpagecnt;
int nfonts;
struct fontdesc fonts[256];
int need_troffencoding, need_cyrtroffencoding, need_bdprocset;
struct srcdoc *curdoc;
FILE *srcfile;
char srcline[1024];
int Fflag;
char *Fbaseset;
char *pagelabel = "%l";

char psmagic[] = "%!PS-Adobe-3.0";
char creatorcomment[] = "%%Creator: 4.3BSD-Quasijarus PostScript troff";
char beginsetupcomment[] = "%%BeginSetup";
char endsetupcomment[] = "%%EndSetup";
char fontsetopen[] = "/fontset [";
char fontsetclose[] = "] def";
char trailercomment[] = "%%Trailer";

extern char progname[];

process_cmdline_opts(argc, argv)
	char **argv;
{
	register int i;
	extern char *optarg;

	while ((i = getopt(argc, argv, "8F:L:NSTgil:np:s")) != EOF) {
		switch (i) {
		case '8':
			psout_8bit_strings = 1;
			break;
		case 'F':
			Fflag = 1;
			Fbaseset = optarg;
			break;
		case 'L':
			languagelevel = atoi(optarg);
			break;
		case 'i':
			notfinal = 1;
			/* FALL THRU */
		case 'N':
			psout_omit_troffencoding = 1;
			break;
		case 'S':
			symbolsubst = 1;
			break;
		case 'T':
			/* no longer needed, backward compat */
			break;
		case 'g':
			gentlewash = 1;
			break;
		case 'l':
			pagelabel = optarg;
			break;
		case 'n':
			strokeadjust = 0;
			break;
		case 'p':
			/* insert named procset: to be implemented */
			break;
		case 's':
			sheetalign = 1;
			break;
		case '?':
		default:
			usage();
			exit(1);
		}
	}
	if (Fflag) {
		if (notfinal) {
			fprintf(stderr,
			"%s: -F and -i options are mutually exclusive\n",
				progname);
			exit(1);
		}
		Fflag_init();
	}
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
