/*
 * Program for extracting page ranges from DSC-conforming PostScript documents.
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "@(#)psrange.c	5.3 (Berkeley) 10/23/04";
#endif

#include <sys/param.h>
#include <ctype.h>
#include <strings.h>
#include <stdio.h>

struct range {
	int start, end;
};

#define	MAXRANGES	32
struct range ranges[MAXRANGES];
int nranges;

int outpagecnt;
char *srcname;
FILE *srcfile;
int srclineno;
char srcline[1024];
int print = 1, header = 1, trailer = 0;

main(argc, argv)
	char **argv;
{
	if (argc == 2) {
		srcname = "stdin";
		srcfile = stdin;
		setranges(argv[1]);
	} else if (argc == 3) {
		srcname = argv[1];
		srcfile = fopen(srcname, "r");
		if (!srcfile) {
			perror(srcname);
			exit(1);
		}
		setranges(argv[2]);
	} else {
		fprintf(stderr, "usage: psrange [infile] range\n");
		exit(1);
	}

	if (getline() || strncmp(srcline, "%!PS-Adobe-", 10)) {
		fprintf(stderr,
			"%s is not a DSC-conforming PostScript document\n",
			srcname);
		exit(1);
	}
	puts(srcline);
	for (;;) {
		if (getline()) {
eof:			if (!trailer) {
				fprintf(stderr,
					"%s: missing %%%%Trailer (got EOF)\n",
					srcname);
				exit(1);
			}
			puts("%%EOF");
			exit(0);
		}
		if (srcline[0] != '%') {
regline:		endheader();
			goto out;
		}
		if (srcline[1] == ' ' || srcline[1] == '\t' || !srcline[1])
			goto regline;
		/* it's a DSC line */
		if (!strncmp(srcline, "%%Page:", 7)) {
			endheader();
			if (trailer) {
				fprintf(stderr,
				"%s: line %d: %%%%Page: in the trailer\n",
					srcname, srclineno);
				exit(1);
			}
			handle_page();
			continue;
		}
		if (!strcmp(srcline, "%%EndComments")) {
			endheader();
			goto out;
		}
		if (!strncmp(srcline, "%%Pages:", 8))
			continue;	/* delete old page count */
		if (!strcmp(srcline, "%%Trailer")) {
			endheader();
			if (trailer) {
				fprintf(stderr,
				"%s: line %d: second %%%%Trailer comment\n",
					srcname, srclineno);
				exit(1);
			}
			trailer = 1;
			puts(srcline);
			printf("%%%%Pages: %d\n", outpagecnt);
			print = 1;
			continue;
		}
		if (!strcmp(srcline, "%%EOF"))
			goto eof;
out:		if (print)
			puts(srcline);
	}
}

setranges(rangestr)
	char *rangestr;
{
	register char *cp;
	register int i;

	for (cp = rangestr, i = 0; *cp; i++) {
		if (i >= MAXRANGES) {
			fprintf(stderr,
		"psrange: too many ranges specified (compiled limit %d)\n",
				MAXRANGES);
			exit(1);
		}
		if (isdigit(*cp)) {
			ranges[i].start = atoi(cp);
			while (isdigit(*cp))
				cp++;
			if (*cp == '\0' || *cp == ',') {
				ranges[i].end = ranges[i].start;
				goto next;
			}
		} else
			ranges[i].start = 1;
		if (*cp++ != '-') {
inv:			fputs("psrange: invalid range specification\n", stderr);
			exit(1);
		}
		if (isdigit(*cp)) {
			ranges[i].end = atoi(cp);
			while (isdigit(*cp))
				cp++;
		} else
			ranges[i].end = 0;
next:		if (*cp && *cp++ != ',')
			goto inv;
	}
	nranges = i;
}

getline()
{
	register char *cp;

	fgets(srcline, sizeof(srcline), srcfile);
	if (ferror(srcfile)) {
		perror(srcname);
		exit(1);
	}
	if (feof(srcfile))
		return(1);
	srclineno++;
	cp = index(srcline, '\n');
	if (cp == NULL) {
		fprintf(stderr, "%s: line %d is too long\n", srcname,
			srclineno);
		exit(1);
	}
	*cp = '\0';
	return(0);
}

endheader()
{
	if (header) {
		puts("%%Pages: (atend)");
		header = 0;
	}
}

handle_page()
{
	register char *cp, *label;
	register int i, oldnum;

	for (cp = srcline + 7; isspace(*cp); cp++)
		;
	if (!isgraph(*cp)) {
inv:		fprintf(stderr, "%s: line %d: invalid %%%%Page: comment\n",
			srcname, srclineno);
		exit(1);
	}
	for (label = cp; isgraph(*cp); cp++)
		;
	if (!isspace(*cp))
		goto inv;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!isdigit(*cp))
		goto inv;
	oldnum = atoi(cp);
	for (i = 0; i < nranges; i++)
		if (oldnum >= ranges[i].start &&
		    (oldnum <= ranges[i].end || !ranges[i].end)) {
			printf("%%%%Page: %s %d\n", label, ++outpagecnt);
			print = 1;
			return;
		}
	print = 0;
}
