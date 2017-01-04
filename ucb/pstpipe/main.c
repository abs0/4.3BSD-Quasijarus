/*
 * This program reads a set of document configuration settings from
 * special header comments in a troff source file and uses them to
 * set up a pipeline invoking pstroff with the right options, preceded
 * by the needed preprocessors and followed by pstfinish if necessary.
 * We construct the pipeline as an sh -c command and then exec /bin/sh.
 *
 * Written by Michael Spacefalcon, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "@(#)main.c	5.2 (Berkeley) 2012/07/23";
#endif

#include <stdio.h>
#include "docreq.h"

static char shell_pathname[] = "/bin/sh";

/* these options get set via pstpipe command line or auto-determined */
int use_bits;
int do_pstfinish;
char *pstfinish_minusF;
int symbolbugfix;
char **sources;
int nsources;

/* these document requirements are extracted from the header comments */
char *fontlist, *fontpath;
int languagelevel = 1;
char *macros;
char *preprocs[MAX_PREPROCS];
int npreprocs;
int pstfinish_req;
char *pstfinish_doc_opts;
int doc_text_bits = 7;

int verbose, dryrun;

extern char shellcommand[];

main(argc, argv)
	char **argv;
{
	register int i;
	extern int optind;
	extern char *optarg;

	while ((i = getopt(argc, argv, "78F:Sfnv")) != EOF) {
		switch (i) {
		case '7':
			use_bits = 7;
			break;
		case '8':
			use_bits = 8;
			break;
		case 'F':
			pstfinish_minusF = optarg;
			/* FALL THRU */
		case 'f':
			do_pstfinish = 1;
			break;
		case 'S':
			symbolbugfix = 1;
			do_pstfinish = 1;
			break;
		case 'n':
			dryrun = 1;
			break;
		case 'v':
			verbose = 1;
			break;
		case '?':
		default:
usage:			fprintf(stderr, "usage: %s [-78FSfnv] troffsrc...\n",
				argv[0]);
			exit(1);
		}
	}
	if (!argv[optind])
		goto usage;
	sources = argv + optind;
	nsources = argc - optind;

	read_header_comments();
	/* reconcile the requirements and the command line options */
	if (!use_bits)
		use_bits = doc_text_bits;
	if (pstfinish_req || languagelevel > 1)
		do_pstfinish = 1;

	build_shell_command();
	if (dryrun) {
		printf("%s\n", shellcommand);
		exit(0);
	}
	if (verbose)
		fprintf(stderr, "%s\n", shellcommand);
	execl(shell_pathname, "sh", "-c", shellcommand, NULL);
	perror(shell_pathname);
	exit(1);
}
