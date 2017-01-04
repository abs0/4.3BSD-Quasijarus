h49246
s 00236/00000/00000
d D 5.1 2012/03/04 05:29:16 msokolov 1 0
c troffchar written, compiles
e
u
U
t
T
I 1
/*
 * This program compiles fcNN files for pstroff character set extension
 * from a human-editable source form into the binary form
 * which pstroff reads and makes use of efficiently.
 *
 * Usage:
 *
 * troffchar srcfile binfile
 *
 * where srcfile is the pathname of the ASCII source file to be read
 * and binfile is the pathname of the binary file to be written.
 * Naming conventions are up to the user.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/types.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "chardef.h"

extern char *malloc();

char *srcfilename;
int lineno;
struct chardef_hdr file_header;
struct chardef_section local_section_hdr, spec_section_hdr;

struct charreg {
	int	charname;
	int	charcode;
	struct	charreg *next;
} *local_chars, *spec_chars;

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
		case 3:
			break;
		case 4:
			s++;
			break;
		default:
			return(-1);
		}
		if (s[0] > '7' || s[1] > '7' || s[2] > '7')
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

parse_char_def(args, sectionhdr, listheadp)
	char *args;
	struct chardef_section *sectionhdr;
	struct charreg **listheadp;
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
	reg->next = *listheadp;
	*listheadp = reg;
	sectionhdr->nchars++;
}

read_source()
{
	FILE *srcf;
	char linebuf[256];
	register char *cp, *np;

	srcf = fopen(srcfilename, "r");
	if (!srcf) {
		perror(srcfilename);
		exit(1);
	}
	for (lineno = 1; fgets(linebuf, sizeof linebuf, srcf); lineno++) {
		for (cp = linebuf; isspace(*cp); cp++)
			;
		if (*cp == '\0' || *cp == '#')
			continue;
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		if (!strcmp(np, "local"))
			parse_char_def(cp, &local_section_hdr, &local_chars);
		else if (!strcmp(np, "special"))
			parse_char_def(cp, &spec_section_hdr, &spec_chars);
		else if (!strcmp(np, "Symbol"))
			file_header.flags |= CHARDEF_FLAGS_SYMBOL;
		else
			fprintf(stderr, "%s: line %d: not understood\n",
				srcfilename, lineno);
	}
	fclose(srcf);
}

calc_section_offsets()
{
	u_long offset;

	offset = sizeof(struct chardef_hdr);
	if (local_chars) {
		file_header.lchars_offset = offset;
		offset += sizeof(struct chardef_section);
		offset += local_section_hdr.nchars * sizeof(int) * 2;
	}
	if (spec_chars)
		file_header.schars_offset = offset;
	file_header.magic = CHARDEF_MAGIC;
}

emit_section(outf, sectionhdr, listhead)
	FILE *outf;
	struct chardef_section *sectionhdr;
	struct charreg *listhead;
{
	register struct charreg *reg;

	fwrite(sectionhdr, sizeof(struct chardef_section), 1, outf);
	for (reg = listhead; reg; reg = reg->next)
		fwrite(reg, sizeof(int), 2, outf);
}

emit_output(outfilename)
	char *outfilename;
{
	FILE *outf;

	outf = fopen(outfilename, "w");
	if (!outf) {
		perror(outfilename);
		exit(1);
	}
	fwrite(&file_header, sizeof file_header, 1, outf);
	if (local_chars)
		emit_section(outf, &local_section_hdr, local_chars);
	if (spec_chars)
		emit_section(outf, &spec_section_hdr, spec_chars);
	fclose(outf);
}

main(argc, argv)
	char **argv;
{
	if (argc != 3) {
		fprintf(stderr, "usage: %s srcfile binfile\n", argv[0]);
		exit(1);
	}
	srcfilename = argv[1];
	read_source();
	calc_section_offsets();
	emit_output(argv[2]);
	exit(0);
}
E 1
