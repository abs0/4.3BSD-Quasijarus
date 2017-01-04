h31499
s 00020/00001/00340
d D 5.4 2012/09/05 03:42:56 msokolov 4 3
c turn IsFixedPitch true into the new isFixedWidth instruction
e
s 00028/00025/00313
d D 5.3 2012/07/14 20:34:35 msokolov 3 2
c new TroffEncoding/CyrTroffEncoding support
e
s 00000/00003/00338
d D 5.2 2012/03/05 07:53:13 msokolov 2 1
c system includes not needed
e
s 00341/00000/00000
d D 5.1 2012/03/05 07:48:54 msokolov 1 0
c written, compiles
e
u
U
t
T
I 1
/*
 * This program reads a standard AFM file for a PostScript font,
 * extracts the information of use to pstroff (the character widths
 * and FontName) and spits it out in the format that serves as input
 * to mkfont.  Normally this would have been a job for sed or awk,
 * but we also have to handle the recoding of standard Roman fonts:
 * the character codes given in AFM files are for StandardEncoding,
 * whereas we need the ones for TroffEncoding.  This program does
 * the dirty work.
 *
D 4
 * grokafm can exec mkfont automatically, passing the intermediate
E 4
I 4
 * grokafm can exec mkfont transparently, passing the intermediate
E 4
 * language via a pipe, or you can save the output from grokafm,
 * tweak it manually as necessary, and then feed it to mkfont.
 *
D 3
 * This program is part of the 4.3BSD-Quasijarus PostScript troff
 * suite by Michael Sokolov, International Free Computing Task Force.
E 3
I 3
 * This program is part of the 4.3BSD-Quasijarus PostScript troff suite
 * by Michael Spacefalcon, International Free Computing Task Force.
E 3
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

D 2
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
E 2
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

extern char *malloc();

char *ftout;
FILE *outf;

D 3
int roman;
E 3
I 3
char *recode;
E 3
char fontname[256];
char *troffencoding[256];

main(argc, argv)
	char **argv;
{
	register int i;
	extern int optind;
	extern char *optarg;

D 3
	while ((i = getopt(argc, argv, "o:r")) != EOF) {
E 3
I 3
	while ((i = getopt(argc, argv, "o:rk")) != EOF) {
E 3
		switch (i) {
		case 'o':
			ftout = optarg;
			break;
		case 'r':
D 3
			roman = 1;
E 3
I 3
			recode = "TroffEncoding";
E 3
			break;
I 3
		case 'k':
			recode = "CyrTroffEncoding";
			break;
E 3
		case '?':
		default:
D 3
usage:			fprintf(stderr, "usage: %s [-o ftXX] [-r] afm\n",
E 3
I 3
usage:			fprintf(stderr, "usage: %s [-o ftXX] [-r|-k] afm\n",
E 3
				argv[0]);
			exit(1);
		}
	}
	if (!argv[optind] || argv[optind+1])
		goto usage;

D 3
	if (roman)
E 3
I 3
	if (recode)
E 3
		read_troff_encoding();
	parse_afm_file(argv[optind]);
	if (!fontname[0]) {
		fprintf(stderr, "FontName required property missing in %s\n",
			argv[0]);
		fprintf(outf, "ABORT\n");
		exit(1);
	}
D 3
	if (roman)
		roman_setup();
E 3
I 3
	if (recode)
		recode_setup();
E 3
	if (ftout && pclose(outf))
		exit(1);
	exit(0);
}

parse_afm_file(afmfile)
	char *afmfile;
{
	FILE *afm;
	char line[256];			/* AFM spec limits lines to 255 chars */
	int lineno, started = 0, inchmetrics = 0;
	register char *cp, *np;
	int code;
	char *chname, *width;

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
			start_output(afmfile);
			started = 1;
			continue;
		}
		if (inchmetrics) {
			if (!strcmp(np, "EndCharMetrics")) {
				inchmetrics = 0;
				continue;
			}
			for (code = -1, chname = width = NULL; ; ) {
				while (isspace(*cp))
					cp++;
				if (!strcmp(np, "C"))
					code = atoi(cp);
				else if (!strcmp(np, "WX"))
					width = cp;
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
			if (!chname) {
				fprintf(stderr,
				"%s: line %d: char metric line has no N\n",
					afmfile, lineno);
				fprintf(outf, "ABORT\n");
				exit(1);
			}
			for (cp = chname; *cp; cp++)
				if (isspace(*cp) || *cp == ';') {
					*cp = '\0';
					break;
				}
			if (!width) {
				fprintf(stderr,
				"%s: line %d: char metric line has no WX\n",
					afmfile, lineno);
				fprintf(outf, "ABORT\n");
				exit(1);
			}
			for (cp = width; *cp; cp++)
				if (isspace(*cp) || *cp == ';') {
					*cp = '\0';
					break;
				}
D 3
			if (roman)
				emit_roman_width(chname, width);
E 3
I 3
			if (recode)
				recode_width(chname, width);
E 3
			else if (code >= 0) {
				if (code > 255) {
					fprintf(stderr,
					"%s: line %d: invalid C value\n",
						afmfile, lineno);
					fprintf(outf, "ABORT\n");
					exit(1);
				}
				fprintf(outf, "charwidth\t%d\t%s\t# %s\n",
					code, width, chname);
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
					"%s: line %d: FontName value missing\n",
					afmfile, lineno);
				fprintf(outf, "ABORT\n");
				exit(1);
			}
			for (np = cp; *cp; cp++)
				if (isspace(*cp)) {
					*cp++ = '\0';
					break;
				}
			strcpy(fontname, np);
			fprintf(outf, "psname %s\n", np);
			continue;
		}
		if (!strcmp(np, "CharWidth")) {
			while (isspace(*cp))
				cp++;
			if (!isdigit(*cp)) {
				fprintf(stderr,
				"%s: line %d: CharWidth value missing\n",
					afmfile, lineno);
				fprintf(outf, "ABORT\n");
				exit(1);
			}
			for (np = cp; *cp; cp++)
				if (isspace(*cp)) {
					*cp++ = '\0';
					break;
				}
			fprintf(outf, "fixedwidth %s\n", np);
I 4
			continue;
		}
		if (!strcmp(np, "IsFixedPitch")) {
			while (isspace(*cp))
				cp++;
			if (!*cp) {
				fprintf(stderr,
				"%s: line %d: IsFixedPitch value missing\n",
					afmfile, lineno);
				fprintf(outf, "ABORT\n");
				exit(1);
			}
			for (np = cp; *cp; cp++)
				if (isspace(*cp)) {
					*cp++ = '\0';
					break;
				}
			if (!strcmp(np, "true"))
				fputs("isFixedWidth\nnolig\n", outf);
E 4
			continue;
		}
		if (!strcmp(np, "StartCharMetrics")) {
			inchmetrics = 1;
			continue;
		}
	}
	fprintf(stderr, "%s: read error or premature EOF\n", afmfile);
	if (started)
		fprintf(outf, "ABORT\n");
	exit(1);
}

start_output(afmfile)
{
	char *cmd;

	if (ftout) {
		cmd = malloc(strlen(ftout) + 10);
		if (!cmd) {
			perror("malloc");
			exit(1);
		}
		sprintf(cmd, "mkfont - %s", ftout);
		outf = popen(cmd, "w");
		if (!outf) {
			perror("popen");
			exit(1);
		}
	} else
		outf = stdout;
	fprintf(outf, "# Generated by grokafm from %s\n", afmfile);
D 3
	if (roman)
		fprintf(outf, "# recoded to TroffEncoding\n");
E 3
I 3
	if (recode)
		fprintf(outf, "# recoded to %s\n", recode);
E 3
	else
		fprintf(outf,
			"# character code points unchanged from the AFM\n");
	putc('\n', outf);
}

read_troff_encoding()
{
	register FILE *f;
D 3
	static char filename[] = "/usr/lib/pstroff/TroffEncoding.ps";
E 3
	char line[256];
	register int code = 0;
	register char *cp, *np, *mp;

D 3
	f = fopen(filename, "r");
E 3
I 3
	sprintf(line, "/usr/lib/pstroff/%s.ps", recode);
	f = fopen(line, "r");
E 3
	if (!f) {
D 3
		perror(filename);
E 3
I 3
		perror(line);
E 3
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
				mp = malloc(strlen(np) + 1);
				if (!mp) {
					perror("malloc");
					exit(1);
				}
				strcpy(mp, np);
				troffencoding[code++] = mp;
				break;
			default:
D 3
				fputs("TroffEncoding.ps: parse error\n",
					stderr);
E 3
I 3
				fprintf(stderr, "%s.ps: parse error\n", recode);
E 3
				exit(1);
			}
		}
nextline:	continue;
	}
D 3
	fputs("TroffEncoding.ps: read error or premature EOF\n", stderr);
E 3
I 3
	fprintf(stderr, "%s.ps: read error or premature EOF\n", recode);
E 3
	exit(1);
}

D 3
emit_roman_width(name, width)
E 3
I 3
recode_width(name, width)
E 3
	register char *name;
	char *width;
{
	register int code;

	for (code = 0; code < 256; code++)
		if (!strcmp(troffencoding[code], name))
			fprintf(outf, "charwidth\t%d\t%s\t# %s\n",
				code, width, name);
}

D 3
roman_setup()
E 3
I 3
recode_setup()
E 3
{
I 3
	fprintf(outf, "\nencoding %s\n", recode);
E 3
	fputs("\nsetup:\n", outf);
	fprintf(outf, "/%s findfont\n", fontname);
	/* code from PostScript LRM 2nd ed. section 5.6.1 */
D 3
	fputs("dup length dict begin\n", outf);
	fputs("\t{1 index /FID ne {def} {pop pop} ifelse} forall\n", outf);
	fputs("\t/Encoding TroffEncoding def\n", outf);
	fputs("currentdict end\n", outf);
E 3
I 3
	fprintf(outf, "dup length dict begin\n");
	fprintf(outf, "\t{1 index /FID ne {def} {pop pop} ifelse} forall\n");
	fprintf(outf, "\t/Encoding %s def\n", recode);
	fprintf(outf, "currentdict end\n");
E 3
	fprintf(outf, "/%s-troff exch definefont\n", fontname);
}
E 1
