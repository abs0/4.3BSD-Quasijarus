h50527
s 00002/00002/00149
d D 5.5 2012/03/06 06:07:30 msokolov 5 4
c more aggressive substitution of TroffEmu-Symbol
e
s 00002/00002/00149
d D 5.4 2012/02/19 05:12:21 msokolov 4 3
c -l option rethought
e
s 00006/00002/00145
d D 5.3 2012/02/17 08:29:07 msokolov 3 2
c page relabeling implemented (new -l option)
e
s 00019/00002/00128
d D 5.2 10/10/09 04:30:37 msokolov 2 1
c added -F option (font embedding)
e
s 00130/00000/00000
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
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/types.h>
#include <strings.h>
#include <stdio.h>
#include "struct.h"

extern char *malloc();

int languagelevel = 1;
int psout_omit_troffencoding;
int psout_8bit_strings;
D 5
int notfinal, symbolbugfix;
E 5
I 5
int notfinal, symbolsubst;
E 5
int sheetalign, outpagecnt;
int nsrcdocs, nfonts;
struct srcdoc *srcdocs, *curdoc;
struct fontdesc fonts[256];
FILE *srcfile;
char srcline[1024];
I 2
int Fflag;
char *Fbaseset;
I 3
D 4
char *relabel;
E 4
I 4
char *pagelabel = "%l";
E 4
E 3
E 2

char psmagic[] = "%!PS-Adobe-3.0";
char creatorcomment[] = "%%Creator: 4.3BSD-Quasijarus PostScript troff";
char beginsetupcomment[] = "%%BeginSetup";
char endsetupcomment[] = "%%EndSetup";
char fontsetopen[] = "/fontset [";
char fontsetclose[] = "] def";
char trailercomment[] = "%%Trailer";

main(argc, argv)
	char **argv;
{
	register int i;
	extern int optind;
	extern char *optarg;

D 2
	while ((i = getopt(argc, argv, "8L:NSTip:s")) != EOF) {
E 2
I 2
D 3
	while ((i = getopt(argc, argv, "8F:L:NSTip:s")) != EOF) {
E 3
I 3
	while ((i = getopt(argc, argv, "8F:L:NSTil:p:s")) != EOF) {
E 3
E 2
		switch (i) {
		case '8':
			psout_8bit_strings = 1;
			break;
I 2
		case 'F':
			Fflag = 1;
			Fbaseset = optarg;
			break;
E 2
		case 'L':
			languagelevel = atoi(optarg);
			break;
		case 'N':
			psout_omit_troffencoding = 1;
			break;
		case 'S':
D 5
			symbolbugfix = 1;
E 5
I 5
			symbolsubst = 1;
E 5
			break;
		case 'T':
			/* no longer needed, backward compat */
			break;
		case 'i':
			notfinal = 1;
			break;
I 3
		case 'l':
D 4
			relabel = optarg;
E 4
I 4
			pagelabel = optarg;
E 4
			break;
E 3
		case 'p':
			/* insert named procset: to be implemented */
			break;
		case 's':
			sheetalign = 1;
			break;
		case '?':
		default:
D 2
usage:			fprintf(stderr, "usage: %s [-8LNSps] psfiles...\n",
E 2
I 2
D 3
usage:			fprintf(stderr, "usage: %s [-8FLNSps] psfiles...\n",
E 3
I 3
usage:			fprintf(stderr, "usage: %s [-8FLNSlps] psfiles...\n",
E 3
E 2
				argv[0]);
			exit(1);
		}
	}
	if (!argv[optind])
		goto usage;
I 2
	if (Fflag) {
		if (notfinal) {
			fprintf(stderr,
			"%s: -F and -i options are mutually exclusive\n",
				argv[0]);
			exit(1);
		}
		Fflag_init();
	}
E 2

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
I 2
	if (Fflag)
		Fflag_mark_as_needed();
E 2

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
