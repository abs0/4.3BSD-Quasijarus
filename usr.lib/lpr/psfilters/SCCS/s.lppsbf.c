h07776
s 00117/00000/00000
d D 5.1 04/08/21 19:22:07 msokolov 1 0
c works
e
u
U
t
T
I 1
/*
 * lpd PostScript banner filter - takes advantage of PostScript graphics
 * to produce nice banner pages.  Configure lpd to use this filter for banners
 * instead of sending its standard plain text banners (which won't work on a
 * PostScript printer).  lpd will then invoke this program with banner
 * information on stdin in a format similar to the control file, one info item
 * per line.
 *
 * This program consumes the input lines from lpd and converts them to userdict
 * definitions, then appends the standard banner page drawing code.  All this
 * is stored in a temporary file, and then lppsjf -b is execed with this temp
 * file on stdin.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/param.h>
#include <sys/file.h>
#include <stdio.h>
#include <ctype.h>

extern int optind;
extern char *optarg;

char *printer = "lp", *options, *width, *height;
char tmpfile[] = "bannerXXXXXX";
char drawcode[] = "/usr/lib/lppsbanner";

main(argc, argv)
	char **argv;
{
	register int c;
	int fd;
	register FILE *f, *tf;
	char line[256];
	register char *cp;
	char *av[16];
	register char **avp;

	while ((c = getopt(argc, argv, "P:O:x:y:")) > 0)
		switch (c) {
		case 'P':
			printer = optarg;
			continue;
		case 'O':
			options = optarg;
			continue;
		case 'x':
			width = optarg;
			continue;
		case 'y':
			height = optarg;
			continue;
		case '?':
			exit(2);
		}
	if (!width || !height) {
		fputs("lppsbf: must specify page size with -x and -y\n",
			stderr);
		exit(2);
	}
	fd = mkstemp(tmpfile);
	f = fdopen(fd, "w");
	fputs("%!\n", f);
	fprintf(f, "/width %s def\n", width);
	fprintf(f, "/height %s def\n", height);
	while (fgets(line, 256, stdin)) {
		if (!isupper(line[0]) || line[1] != ' ') {
			fclose(f);
			unlink(tmpfile);
			fputs("lppsbf: invalid input line\n", stderr);
			exit(2);
		}
		fprintf(f, "/%c (", line[0]);
		for (cp = line + 2; c = *cp++; ) {
			if (c == '\n')
				break;
			if (c == '(' || c == ')' || c == '\\')
				putc('\\', f);
			putc(c, f);
		}
		fputs(") def\n", f);
	}
	tf = fopen(drawcode, "r");
	if (!tf) {
		perror(drawcode);
		fclose(f);
		unlink(tmpfile);
		exit(2);
	}
	while ((c = getc(tf)) >= 0)
		putc(c, f);
	fclose(tf);
	dup2(fd, 0);
	fclose(f);
	lseek(0, 0L, L_SET);
	avp = av;
	*avp++ = "lppsjf";
	*avp++ = "-b";
	*avp++ = "-P";
	*avp++ = printer;
	if (options) {
		*avp++ = "-O";
		*avp++ = options;
	}
	*avp++ = "-x";
	*avp++ = width;
	*avp++ = "-y";
	*avp++ = height;
	*avp = NULL;
	unlink(tmpfile);		/* it's still open on 0 */
	execv("/usr/lib/lppsjf", av);
	perror("lppsjf");
	_exit(2);
}
E 1
