/*
 * This program compiles ftXX font information files for pstroff
 * from a human-editable source form into the binary form
 * which pstroff reads and makes use of efficiently.
 *
 * Usage:
 *
 * mkfont [srcfile] ftXX
 *
 * The final argument is the name of the binary file to be written.
 * The source file may be given as srcfile ("-" for stdin);
 * if only one argument is given, the source is sought in ftXX.src
 * by default.
 *
 * This program is part of the 4.3BSD-Quasijarus PostScript troff suite
 * by Michael Spacefalcon, International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "@(#)mkfont.c	5.6 (Berkeley) 2012/09/05";
#endif

#include <sys/types.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "fontinfo.h"

extern char *malloc();

char *srcfilename, *ftfile;
FILE *srcf, *outf;
int lineno;
struct fontinfo_hdr file_header;
u_short widthtab[256];
char psname[64], setup[1024];
int setuplen;
struct chardef_section lchar_section_hdr, spchar_section_hdr;

struct charreg {
	int	charname;
	int	charcode;
	struct	charreg *next;
} *local_chars, *special_chars;

is_string_numeric(s)
	register char *s;
{
	register int c;

	if (!isdigit(*s++))
		return(0);
	while (c = *s++)
		if (!isdigit(c))
			return(0);
	return(1);
}

decode_xdigit(c)
	register int c;
{
	if (isdigit(c))
		return (c - '0');
	else if (isupper(c))
		return (c - 'A' + 10);
	else
		return (c - 'a' + 10);
}

decode_char(s, codep)
	register char *s;
	int *codep;
{
	register int l;

	l = strlen(s);
	if (s[0] == '\'' && l >= 2) {
		*codep = s[1];
		return(0);
	}
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		if (l != 4 || !isxdigit(s[2]) || !isxdigit(s[3]))
			return(-1);
		*codep = (decode_xdigit(s[2]) << 4) | decode_xdigit(s[3]);
		return(0);
	}
	if (!is_string_numeric(s) || l > 4)
		return(-1);
	if (s[0] == '0') {
		switch (l) {
		case 1:
			*codep = 0;
			return(0);
		case 3:
			break;
		case 4:
			s++;
			break;
		default:
			return(-1);
		}
		if (s[0] > '3' || s[1] > '7' || s[2] > '7')
			return(-1);
		l = ((s[0] - '0') << 6) | ((s[1] - '0') << 3) | (s[2] - '0');
	} else {
		l = atoi(s);
		if (l > 255)
			return(-1);
	}
	*codep = l;
	return(0);
}

widthtoi(cp)
	register char *cp;
{
	register int accum;

	for (accum = 0; isdigit(*cp); cp++)
		accum = accum * 10 + (*cp - '0');
	if (*cp++ != '.')
		return(accum);
	if (*cp >= '5' && *cp <= '9')
		accum++;
	return(accum);
}

handle_charwidth(args)
	char *args;
{
	register char *cp, *np;
	int charcode, width;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp) {
inv:		fprintf(stderr, "%s: line %d: invalid charwidth instruction\n",
			srcfilename, lineno);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto inv;
	*cp++ = '\0';
	if (decode_char(np, &charcode) < 0)
		goto inv;
	while (isspace(*cp))
		cp++;
	if (!isdigit(*cp))
		goto inv;
	width = widthtoi(cp);
	widthtab[charcode] = width;
}

handle_fixedwidth(args)
	char *args;
{
	register char *cp;
	register int i, width;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		fprintf(stderr, "%s: line %d: invalid fixedwidth instruction\n",
			srcfilename, lineno);
		return;
	}
	width = widthtoi(cp);
	for (i = 0; i < 256; i++)
		widthtab[i] = width;
	file_header.flags |= FONTINFO_FLAGS_CWIDTH;
}

handle_namedchar(args)
	char *args;
{
	register char *cp, *np;
	register struct charreg *reg;

	reg = (struct charreg *) malloc(sizeof(struct charreg));
	if (!reg) {
		perror("malloc");
		exit(1);
	}
	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp) {
inv:		fprintf(stderr, "%s: line %d: invalid character definition\n",
			srcfilename, lineno);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto inv;
	*cp++ = '\0';
	if (strlen(np) != 2)
		goto inv;
	reg->charname = np[0] | (np[1] << 8);
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto inv;
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if (decode_char(np, &reg->charcode) < 0)
		goto inv;
	while (isspace(*cp))
		cp++;
	if (*cp == '\0' || *cp == '#') {
		/* font-local named character */
		reg->next = local_chars;
		local_chars = reg;
		lchar_section_hdr.nchars++;
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if (strcmp(np, "special"))
		goto inv;
	/* "special" named char: like multiple special fonts in ditroff */
	reg->next = special_chars;
	special_chars = reg;
	spchar_section_hdr.nchars++;
}

handle_psname(args)
	char *args;
{
	register char *cp, *np;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp) {
		fprintf(stderr, "%s: line %d: invalid psname instruction\n",
			srcfilename, lineno);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp = '\0';
	if (strlen(np) > sizeof(psname) - 1) {
		fprintf(stderr, "%s: line %d: psname is too long\n",
			srcfilename, lineno);
		return;
	}
	strcpy(psname, np);
}

handle_encoding(args)
	char *args;
{
	register char *cp, *np;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp) {
		fprintf(stderr, "%s: line %d: invalid encoding instruction\n",
			srcfilename, lineno);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp = '\0';
	if (!strcmp(np, "TroffEncoding"))
		file_header.flags |= FONTINFO_FLAGS_ROMAN;
	else if (!strcmp(np, "CyrTroffEncoding"))
		file_header.flags |= FONTINFO_FLAGS_CYRILLIC
					| FONTINFO_FLAGS_NOLIG;
	else
		fprintf(stderr, "%s: line %d: encoding %s not known\n",
			srcfilename, lineno, np);
}

read_setup()
{
	register int c;
	register char *dp;

	dp = setup;
	while ((c = getc(srcf)) != EOF) {
		if (++setuplen >= sizeof setup) {
			fprintf(stderr,
				"mkfont: %s: setup section is too long\n",
				srcfilename);
			exit(1);
		}
		*dp++ = c;
	}
}

read_source()
{
	char linebuf[256];
	register char *cp, *np;

	for (lineno = 1; fgets(linebuf, sizeof linebuf, srcf); lineno++) {
		for (cp = linebuf; isspace(*cp); cp++)
			;
		if (*cp == '\0' || *cp == '#')
			continue;
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		if (!strcmp(np, "charwidth"))
			handle_charwidth(cp);
		else if (!strcmp(np, "fixedwidth"))
			handle_fixedwidth(cp);
		else if (!strcmp(np, "namedchar"))
			handle_namedchar(cp);
		else if (!strcmp(np, "psname"))
			handle_psname(cp);
		else if (!strcmp(np, "encoding"))
			handle_encoding(cp);
		else if (!strcmp(np, "setup:")) {
			read_setup();
			return;
		} else if (!strcmp(np, "nolig"))
			file_header.flags |= FONTINFO_FLAGS_NOLIG;
		else if (!strcmp(np, "isFixedWidth"))
			file_header.flags |= FONTINFO_FLAGS_CWIDTH;
		else if (!strcmp(np, "SymbolSpecial"))
			file_header.flags |= FONTINFO_FLAGS_SYMBOL;
		else if (!strcmp(np, "ABORT"))	/* for grokafm errors */
			exit(1);
		else
			fprintf(stderr, "mkfont: %s: line %d: not understood\n",
				srcfilename, lineno);
	}
}

fix_setup()
{
	if (setuplen) {
		setup[setuplen] = '\0';
		return;
	}
	if (!psname[0]) {
		fprintf(stderr,
			"mkfont: %s: either psname or setup must be given\n",
			srcfilename);
		exit(1);
	}
	sprintf(setup, "/%s findfont\n", psname);
	setuplen = strlen(setup);
}

calc_section_offsets()
{
	u_long offset;

	offset = sizeof file_header;
	file_header.width_offset = offset;
	offset += sizeof widthtab;
	if (local_chars) {
		file_header.lchars_offset = offset;
		offset += sizeof(struct chardef_section);
		offset += (lchar_section_hdr.nchars + 1) * sizeof(int) * 2;
	}
	if (special_chars) {
		file_header.schars_offset = offset;
		offset += sizeof(struct chardef_section);
		offset += (spchar_section_hdr.nchars + 1) * sizeof(int) * 2;
	}
	file_header.setup_offset = offset;
	file_header.setup_len = setuplen;
	file_header.magic = FONTINFO_MAGIC;
}

emit_chars_section(sectionhdr, listhead)
	struct chardef_section *sectionhdr;
	struct charreg *listhead;
{
	register struct charreg *reg;
	static int term[2] = {0, 0};

	fwrite(sectionhdr, sizeof(struct chardef_section), 1, outf);
	for (reg = listhead; reg; reg = reg->next)
		fwrite(reg, sizeof(int), 2, outf);
	fwrite(term, sizeof(int), 2, outf);
}

emit_output()
{
	outf = fopen(ftfile, "w");
	if (!outf) {
		perror(ftfile);
		exit(1);
	}
	fwrite(&file_header, sizeof file_header, 1, outf);
	fwrite(widthtab, 2, 256, outf);
	if (local_chars)
		emit_chars_section(&lchar_section_hdr, local_chars);
	if (special_chars)
		emit_chars_section(&spchar_section_hdr, special_chars);
	fwrite(setup, 1, setuplen + 1, outf);
	fclose(outf);
}

main(argc, argv)
	char **argv;
{
	if (argc == 2) {
		ftfile = argv[1];
		srcfilename = malloc(strlen(ftfile) + 5);
		if (!srcfilename) {
			perror("malloc");
			exit(1);
		}
		strcpy(srcfilename, ftfile);
		strcat(srcfilename, ".src");
	} else if (argc == 3) {
		srcfilename = argv[1];
		ftfile = argv[2];
	} else {
		fprintf(stderr, "usage: mkfont [srcfile] ftXX\n");
		exit(1);
	}
	if (strcmp(srcfilename, "-")) {
		srcf = fopen(srcfilename, "r");
		if (!srcf) {
			perror(srcfilename);
			exit(1);
		}
	} else {
		srcf = stdin;
		srcfilename = "stdin";
	}

	read_source();
	fix_setup();
	calc_section_offsets();
	emit_output();
	exit(0);
}
