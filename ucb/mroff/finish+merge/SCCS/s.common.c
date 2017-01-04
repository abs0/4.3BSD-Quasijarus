h02614
s 00005/00001/00122
d D 5.5 2012/07/22 01:53:49 msokolov 5 4
c setstrokeadjust insertion and -n option implemented
e
s 00001/00001/00122
d D 5.4 2012/07/22 01:42:26 msokolov 4 3
c implemented .bd procset preservation and skipping of extra setup
e
s 00004/00003/00119
d D 5.3 2012/07/18 05:48:49 msokolov 3 2
c smart recognition of TroffEncoding and CyrTroffEncoding implemented
e
s 00005/00002/00117
d D 5.2 2012/07/18 05:21:56 msokolov 2 1
c gentle wash cycle implemented
e
s 00119/00000/00000
d D 5.1 2012/07/18 03:56:30 msokolov 1 0
c pstmerge main.c split into common.c and mergemain.c
e
u
U
t
T
I 1
/*
 * This module contains global variables and functions which are
 * common between pstmerge and pstfinish.
 *
 * Written by Michael Spacefalcon, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/types.h>
#include <strings.h>
#include <stdio.h>
#include "struct.h"

int languagelevel = 1;
int psout_omit_troffencoding;
int psout_8bit_strings;
D 2
int notfinal, symbolsubst;
E 2
I 2
int notfinal, symbolsubst, gentlewash;
I 5
int strokeadjust = 1;
E 5
E 2
int sheetalign, outpagecnt;
int nfonts;
struct fontdesc fonts[256];
I 3
D 4
int need_troffencoding, need_cyrtroffencoding;
E 4
I 4
int need_troffencoding, need_cyrtroffencoding, need_bdprocset;
E 4
E 3
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

D 2
	while ((i = getopt(argc, argv, "8F:L:NSTil:p:s")) != EOF) {
E 2
I 2
D 5
	while ((i = getopt(argc, argv, "8F:L:NSTgil:p:s")) != EOF) {
E 5
I 5
	while ((i = getopt(argc, argv, "8F:L:NSTgil:np:s")) != EOF) {
E 5
E 2
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
I 3
		case 'i':
			notfinal = 1;
			/* FALL THRU */
E 3
		case 'N':
			psout_omit_troffencoding = 1;
			break;
		case 'S':
			symbolsubst = 1;
			break;
		case 'T':
			/* no longer needed, backward compat */
I 2
			break;
		case 'g':
			gentlewash = 1;
E 2
D 3
			break;
		case 'i':
			notfinal = 1;
E 3
			break;
		case 'l':
			pagelabel = optarg;
I 5
			break;
		case 'n':
			strokeadjust = 0;
E 5
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
E 1
