h04716
s 00016/00026/00087
d D 5.2 2012/07/23 01:12:17 msokolov 2 1
c updated for the recent changes to pstroff and pstfinish
e
s 00113/00000/00000
d D 5.1 10/10/09 18:56:51 msokolov 1 0
c written, compiles
e
u
U
t
T
I 1
/*
 * This program reads a set of document configuration settings from
 * special header comments in a troff source file and uses them to
 * set up a pipeline invoking pstroff with the right options, preceded
 * by the needed preprocessors and followed by pstfinish if necessary.
 * We construct the pipeline as an sh -c command and then exec /bin/sh.
 *
D 2
 * Written by Michael Sokolov, Quasijarus Project,
E 2
I 2
 * Written by Michael Spacefalcon, Quasijarus Project,
E 2
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <stdio.h>
#include "docreq.h"

static char shell_pathname[] = "/bin/sh";

D 2
/* these options get set via pstpipe command line */
int eightbit_output;
E 2
I 2
/* these options get set via pstpipe command line or auto-determined */
int use_bits;
E 2
int do_pstfinish;
char *pstfinish_minusF;
int symbolbugfix;
char **sources;
int nsources;

/* these document requirements are extracted from the header comments */
D 2
char *fontlist;
int notroffencoding;
E 2
I 2
char *fontlist, *fontpath;
E 2
int languagelevel = 1;
char *macros;
char *preprocs[MAX_PREPROCS];
int npreprocs;
int pstfinish_req;
I 2
char *pstfinish_doc_opts;
int doc_text_bits = 7;
E 2

int verbose, dryrun;

extern char shellcommand[];

main(argc, argv)
	char **argv;
{
	register int i;
	extern int optind;
	extern char *optarg;

D 2
	while ((i = getopt(argc, argv, "8F:Sfnv")) != EOF) {
E 2
I 2
	while ((i = getopt(argc, argv, "78F:Sfnv")) != EOF) {
E 2
		switch (i) {
I 2
		case '7':
			use_bits = 7;
			break;
E 2
		case '8':
D 2
			eightbit_output = 1;
E 2
I 2
			use_bits = 8;
E 2
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
D 2
usage:			fprintf(stderr, "usage: %s [-8FSfnv] troffsrc...\n",
E 2
I 2
usage:			fprintf(stderr, "usage: %s [-78FSfnv] troffsrc...\n",
E 2
				argv[0]);
			exit(1);
		}
	}
	if (!argv[optind])
		goto usage;
	sources = argv + optind;
	nsources = argc - optind;

	read_header_comments();
D 2
	/* check the doc requirements for self-consistency */
	if (languagelevel > 1) {
		if (pstfinish_req < 0) {
			fprintf(stderr,
			"%s specifies self-contradictory requirements\n",
				sources[0]);
			exit(1);
		}
		pstfinish_req = 1;
	}
	/* now reconcile against the command line options */
	if (do_pstfinish && pstfinish_req < 0) {
		fprintf(stderr,
	"pstpipe: %s disallows pstfinish, but the command line requests it\n",
			sources[0]);
		exit(1);
	}
	if (pstfinish_req > 0)
E 2
I 2
	/* reconcile the requirements and the command line options */
	if (!use_bits)
		use_bits = doc_text_bits;
	if (pstfinish_req || languagelevel > 1)
E 2
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
E 1
