h56880
s 00063/00000/00000
d D 4.2 82/11/06 16:29:23 rrh 2 1
c Bill Jolitz @ Berkeley received this version from Lorindia Cherry
c around September 1981, as the ``most recent version''.  Deltas 
c seem to be progressive, rather than regressive, although the BTL sid for
c deroff.c is retrograde; this is probably a case of parallel development
e
s 00000/00000/00000
d D 4.1 82/11/06 16:27:51 rrh 1 0
c This was not used in oldest version available at Berkeley
e
u
U
t
T
I 2


#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%E%";
#endif not lint

#include <stdio.h>
#define ERR(s, c)       if(opterr){\
	fputs(argv[0], stderr);\
	fputs(s, stderr);\
	fputc(c, stderr);\
	fputc('\n', stderr);}

int     opterr = 1;
int     optind = 1;
int	optopt;
char    *optarg;
char    *index();

int
getopt (argc, argv, opts)
char **argv, *opts;
{
	static int sp = 1;
	register c;
	register char *cp;

	if (sp == 1)
		if (optind >= argc ||
		   argv[optind][0] != '-' || argv[optind][1] == '\0')
			return EOF;
		else if (strcmp(argv[optind], "--") == NULL) {
			optind++;
			return EOF;
		}
	optopt = c = argv[optind][sp];
	if (c == ':' || (cp=index(opts, c)) == NULL) {
		ERR (": illegal option -- ", c);
		if (argv[optind][++sp] == '\0') {
			optind++;
			sp = 1;
		}
		return '?';
	}
	if (*++cp == ':') {
		if (argv[optind][sp+1] != '\0')
			optarg = &argv[optind++][sp+1];
		else if (++optind >= argc) {
			ERR (": option requires an argument -- ", c);
			sp = 1;
			return '?';
		} else
			optarg = argv[optind++];
		sp = 1;
	} else {
		if (argv[optind][++sp] == '\0') {
			sp = 1;
			optind++;
		}
		optarg = NULL;
	}
	return c;
}
E 2
I 1
E 1
