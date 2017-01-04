h16277
s 00001/00001/00072
d D 5.2 2012/07/18 05:21:55 msokolov 2 1
c gentle wash cycle implemented
e
s 00073/00000/00000
d D 5.1 2012/07/18 04:18:57 msokolov 1 0
c date and time created 2012/07/18 04:18:57 by msokolov
e
u
U
t
T
I 1
/*
 * Pstmerge is a program for merging PostScript documents produced by pstroff;
 * it also performs some important finishing functions.  Pstfinish is a
 * variant of pstmerge intended for finishing use only: it only takes one
 * source file and can read from a pipe.  The two programs share most of
 * the code, only the main module is different.
 *
 * This module implements the pstfinish version of main.
 *
 * Written by Michael Spacefalcon, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/types.h>
#include <stdio.h>
#include "struct.h"

char progname[] = "pstfinish";

extern struct srcdoc *curdoc;
extern FILE *srcfile;
extern int Fflag;

static struct srcdoc oneinput;

usage()
{
D 2
	fprintf(stderr, "usage: pstfinish [-8FLNSlp] [srcfile]\n");
E 2
I 2
	fprintf(stderr, "usage: pstfinish [-8FLNSglp] [srcfile]\n");
E 2
	exit(1);
}

main(argc, argv)
	char **argv;
{
	extern int optind;

	process_cmdline_opts(argc, argv);
	if (argv[optind]) {
		if (argv[optind+1])
			usage();
		oneinput.filename = argv[optind];
		srcfile = fopen(oneinput.filename, "r");
		if (!srcfile) {
			perror(oneinput.filename);
			exit(1);
		}
	} else {
		srcfile = stdin;
		oneinput.filename = "stdin";
	}

	/* pstfinish pass1 */
	curdoc = &oneinput;
	pass1();
	if (Fflag)
		Fflag_mark_as_needed();

	/* Emit merged document header */
	emit_merged_header();
	emit_merged_prolog();
	emit_merged_setup();

	/* pstfinish pass 2 */
	pass2();

	/* Done! */
	emit_final_trailer();
	return(0);
}
E 1
