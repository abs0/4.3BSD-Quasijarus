h26684
s 00010/00015/00374
d D 5.6 04/10/30 03:42:20 msokolov 6 5
c some improvements
c using a real procset
c line drawing chars done via the procset, no more raping of Symbol
e
s 00001/00000/00388
d D 5.5 04/09/17 08:44:22 msokolov 5 4
c broke down and added baseline rule to the line drawing chars
e
s 00002/00000/00386
d D 5.4 04/09/13 09:18:29 msokolov 4 3
c we are now changing the metrics of radical and radicalex in Symbol
e
s 00026/00003/00360
d D 5.3 04/09/09 08:07:29 msokolov 3 2
c do box drawing characters by adding line-drawn chars to Symbol
c (Type3-like chars added to a Type1 font)
e
s 00010/00009/00353
d D 5.2 04/09/08 16:50:34 msokolov 2 1
c TroffEncoding.ps moved from /usr/lib/psutils to /usr/lib/pstroff
c fix head comment
e
s 00362/00000/00000
d D 5.1 04/09/04 08:34:20 msokolov 1 0
c appears to work correctly
e
u
U
t
T
I 1
/*
D 2
 * This program prepares a PostScript for use with pstroff.  It takes the AFM
 * file and a command line flag indicating whether to use it with its existing
 * encoding or to recode it to TroffEncoding, and generates a simple binary
 * file with 256 character widths for the font as it will be used, and a text
 * file with PostScript code that will leave the font dictionary on the operand
 * stack.  (The latter is simply "/fontname findfont" if no recoding is needed,
 * or the code to copy the font with the change to TroffEncoding otherwise.)
E 2
I 2
 * This program prepares a PostScript font for use with pstroff.  It takes the
 * AFM file and a command line flag indicating whether to use it with its
 * existing encoding or to recode it to TroffEncoding, and generates a simple
 * binary file with 256 character widths for the font as it will be used, and a
 * text file with PostScript code that will leave the font dictionary on the
 * operand stack.  (The latter is simply "/fontname findfont" if no recoding is
 * needed, or the code to copy the font with the change to TroffEncoding
 * otherwise.)
E 2
 *
 * Usage:
 *
 * preppsfont [-r] afmfile NN
 *
 * where afmfile is the name of the AFM file, NN is the troff name this font
D 2
 * should receive (the generated width and setup file will be named fwNN and
E 2
I 2
 * should receive (the generated width and setup files will be named fwNN and
E 2
 * fsNN, respectively), and -r indicates a Roman font needing recoding to
 * TroffEncoding.
 *
 * By Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/param.h>
#include <sys/file.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

extern char *malloc();

#define	HASH_SIZE	61

struct chnamemap {
	char	name[32];
	int	code;
	int	width;
	struct	chnamemap *next;
};

D 3
int roman;
E 3
I 3
int roman, symbol;
E 3
char fontname[256];
char *fontnn;
u_short widths[256];
struct chnamemap *chnamehash[HASH_SIZE];

main(argc, argv)
	char **argv;
{
	argv++;
	argc--;
	if (argc && !strcmp(*argv, "-r")) {
		roman++;
		argv++;
		argc--;
	}
I 3
	if (argc && !strcmp(*argv, "-s")) {
		symbol++;
		argv++;
		argc--;
	}
E 3
	if (argc != 2) {
		fputs("usage: preppsfont [-r] afmfile NN\n", stderr);
		exit(1);
	}
	fontnn = argv[1];
	if (roman)
		read_troff_encoding();
	parse_afm_file(argv[0]);
	if (!fontname[0]) {
		fprintf(stderr, "FontName required property missing in %s\n",
			argv[0]);
		exit(1);
	}
	if (roman)
		set_roman_widths();
I 3
	if (symbol) {
D 6
		widths[15] = 500;
		widths[16] = 500;
		widths[17] = 0;
I 5
		widths[18] = 500;
E 6
E 5
I 4
		widths[0140] = 610;
		widths[0326] = 515;
E 4
	}
E 3
	write_fw_file();
	write_fs_file();
	return(0);
}

parse_afm_file(afmfile)
	char *afmfile;
{
	register FILE *afm;
	char line[256];			/* AFM spec limits lines to 255 chars */
	int lineno, started = 0, inchmetrics = 0;
	register char *cp, *np;
	register int i, x;
	char *chname;

	if ((afm = fopen(afmfile, "r")) == NULL) {
		perror(afmfile);
		exit(1);
	}
	for (lineno = 1; fgets(line, 256, afm); lineno++) {
		for (cp = line; isspace(*cp); cp++)
			;
		if (!*cp)
			continue;
		for (np = cp; *cp; cp++)
			if (isspace(*cp)) {
				*cp++ = '\0';
				break;
			}
		if (!started) {
			if (strcmp(np, "StartFontMetrics")) {
				fprintf(stderr, "%s is not a valid AFM file\n",
					afmfile);
				exit(1);
			}
			started = 1;
			continue;
		}
		if (inchmetrics) {
			if (!strcmp(np, "EndCharMetrics")) {
				inchmetrics = 0;
				continue;
			}
			for (i = x = -1, chname = NULL; ; ) {
				while (isspace(*cp))
					cp++;
				if (!strcmp(np, "C"))
					i = atoi(cp);
				else if (!strcmp(np, "WX"))
					x = widthtoi(cp);
				else if (!strcmp(np, "N"))
					chname = cp;
				cp = index(cp, ';');
				if (!cp)
					break;
				cp++;
				while (isspace(*cp))
					cp++;
				if (!*cp)
					break;
				for (np = cp; *cp; cp++)
					if (isspace(*cp)) {
						*cp++ = '\0';
						break;
					}
			}
			if (x < 0)
				continue;
			if (roman) {
				if ((cp = chname) == NULL)
					continue;
				for (; *cp; cp++)
					if (isspace(*cp) || *cp == ';') {
						*cp = '\0';
						break;
					}
				set_chname_width(chname, x);
			} else {
				if (i >= 0)
					widths[i] = x;
			}
			continue;
		}
		if (!strcmp(np, "EndFontMetrics")) {
			fclose(afm);
			return(0);
		}
		if (!strcmp(np, "FontName")) {
			while (isspace(*cp))
				cp++;
			if (!*cp) {
				fprintf(stderr,
					"%s: %s: FontName value missing\n",
					afmfile, lineno);
				exit(1);
			}
			for (np = cp; *cp; cp++)
				if (isspace(*cp)) {
					*cp++ = '\0';
					break;
				}
			strcpy(fontname, np);
			continue;
		}
		if (!strcmp(np, "CharWidth")) {
			while (isspace(*cp))
				cp++;
			if (!isdigit(*cp)) {
				fprintf(stderr,
					"%s: %s: CharWidth value missing\n",
					afmfile, lineno);
				exit(1);
			}
			x = widthtoi(cp);
			for (i = 0; i < 256; i++)
				widths[i] = x;
			continue;
		}
		if (!strcmp(np, "StartCharMetrics")) {
			inchmetrics = 1;
			continue;
		}
	}
	fprintf(stderr, "%s: read error or premature EOF\n", afmfile);
	exit(1);
}

read_troff_encoding()
{
	register FILE *f;
D 2
	static char filename[] = "/usr/lib/psutils/TroffEncoding.ps";
E 2
I 2
	static char filename[] = "/usr/lib/pstroff/TroffEncoding.ps";
E 2
	char line[256];
	register int code = 0;
	register char *cp, *np;

	f = fopen(filename, "r");
	if (!f) {
		perror(filename);
		exit(1);
	}
	/* skip the first 3 lines */
	fgets(line, 256, f);
	fgets(line, 256, f);
	fgets(line, 256, f);
	while (fgets(line, 256, f)) {
		for (cp = line; ; ) {
			while (isspace(*cp))
				cp++;
			switch (*cp++) {
			case '\0':
			case '%':
				goto nextline;
			case ']':
				fclose(f);
				return(0);
			case '/':
				for (np = cp; *cp; cp++) {
					if (isspace(*cp)) {
						*cp++ = '\0';
						break;
					}
					if (*cp == '%') {
						*cp = '\0';
						break;
					}
				}
				register_chname(code++, np);
				break;
			default:
				fputs("TroffEncoding.ps: parse error\n",
					stderr);
				exit(1);
			}
		}
nextline:	continue;
	}
	fputs("TroffEncoding.ps: read error or premature EOF\n", stderr);
	exit(1);
}

register_chname(code, name)
	int code;
	char *name;
{
	register struct chnamemap *map;
	register struct chnamemap *np, **npp;

	map = (struct chnamemap *) malloc(sizeof(struct chnamemap));
	if (!map) {
		perror("malloc");
		exit(1);
	}
	strcpy(map->name, name);
	map->code = code;
	map->width = -1;
	map->next = NULL;
	for (npp = chnamehash + hash_chname(name); np = *npp; npp = &np->next)
		;
	*npp = map;
}

set_chname_width(name, width)
	register char *name;
	int width;
{
	register struct chnamemap *map;

	for (map = chnamehash[hash_chname(name)]; map; map = map->next)
		if (!strcmp(map->name, name))
			map->width = width;
}

hash_chname(name)
	char *name;
{
	u_long accum;
	u_char *cp;

	for (accum = 0, cp = (u_char*)name; *cp; cp++)
		accum += *cp;
	return(accum % HASH_SIZE);
}

set_roman_widths()
{
	register struct chnamemap *map, **hb, **end;

	for (hb = chnamehash, end = hb + HASH_SIZE; map = *hb; hb++)
		for (; map; map = map->next)
			if (map->width >= 0)
				widths[map->code] = map->width;
}

write_fw_file()
{
	char filename[16];
	register int fd;

	sprintf(filename, "fw%s", fontnn);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0) {
		perror(filename);
		exit(1);
	}
	if (write(fd, widths, sizeof(widths)) != sizeof(widths)) {
		perror(filename);
		exit(1);
	}
	close(fd);
}

write_fs_file()
{
	char filename[16];
D 3
	register FILE *f;
E 3
I 3
D 6
	static char extcodefile[] = "/usr/lib/pstroff/Symbolextend.ps";
	register FILE *f, *fs;
	register int c;
E 6
I 6
	register FILE *f;
E 6
E 3

	sprintf(filename, "fs%s", fontnn);
	f = fopen(filename, "w");
	if (!f) {
		perror(filename);
		exit(1);
	}
	fprintf(f, "/%s findfont\n", fontname);
	if (roman) {
		/* code from PostScript LRM 2nd ed. section 5.6.1 */
		fputs("dup length dict begin\n", f);
		fputs("\t{1 index /FID ne {def} {pop pop} ifelse} forall\n", f);
		fputs("\t/Encoding TroffEncoding def\n", f);
		fputs("\tcurrentdict\n", f);
		fputs("end\n", f);
D 3
		fprintf(f, "/%s-troff exch definefont\n", fontname);
E 3
	}
I 3
	if (symbol) {
D 6
		fs = fopen(extcodefile, "r");
		if (!fs) {
			perror(extcodefile);
			exit(1);
		}
		while ((c = getc(fs)) != EOF)
			putc(c, f);
		fclose(fs);
E 6
I 6
		/* similar code, but in this case to add a Metrics tweak */
		fputs("dup length 1 add dict begin\n", f);
		fputs("\t{1 index /FID ne {def} {pop pop} ifelse} forall\n", f);
		fputs("\t/Metrics 2 dict\n", f);
		fputs("\tdup /radical 515 put\n", f);
		fputs("\tdup /radicalex [0 610] put\n", f);
		fputs("\tdef\n", f);
		fputs("\tcurrentdict\n", f);
		fputs("end\n", f);
E 6
	}
	if (roman || symbol)
		fprintf(f, "/%s-troff exch definefont\n", fontname);
E 3
	fclose(f);
}

widthtoi(cp)
	register char *cp;
{
	int accum;

	for (accum = 0; isdigit(*cp); cp++)
		accum = accum * 10 + (*cp - '0');
	if (*cp++ != '.')
		return(accum);
	if (*cp >= '5' && *cp <= '9')
		accum++;
	return(accum);
}
E 1
