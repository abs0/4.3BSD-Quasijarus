/*
 * Pstmerge is a program for merging PostScript documents produced by pstroff;
 * it also performs some important finishing functions.
 *
 * Written by Michael Spacefalcon, Quasijarus Project,
 * International Free Computing Task Force.
 *
 * Pass 2 does the following work:
 * - Read the main body of each input document line by line;
 * - Handle %%Page: lines and maintain the global page count;
 * - Parse (tokenize) the actual PS code in each non-comment line;
 * - Parse each PS string and re-emit it in the most optimal form
 *   (ASCII or hex);
 * - Identify SF commands and do the necessary font renumbering;
 * - Re-emit the tokenized PS code lines with minimal white space.
 */

#ifndef lint
static char sccsid[] = "@(#)pass2.c	5.6 (Berkeley) 2012/07/18";
#endif

#include <sys/types.h>
#include <ctype.h>
#include <strings.h>
#include <stdio.h>
#include "struct.h"

/* PostScript ASCII encoding character classification */

#define	_PSS	010	/* PostScript white space */
#define _PSD	020	/* PostScript delimiter */
#define _PSR	040	/* PostScript regular */

char ps_ctype[1 + 256] = {
	0,
	_PSS,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*00*/
	_PSR,	_PSS,	_PSS,	_PSR,	_PSS,	_PSS,	_PSR,	_PSR,	/*08*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*10*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*18*/
	_PSS,	_PSR,	_PSR,	_PSR,	_PSR,	_PSD,	_PSR,	_PSR,	/*20*/
	_PSD,	_PSD,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSD,	/*28*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*30*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSD,	_PSR,	_PSD,	_PSR,	/*38*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*40*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*48*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*50*/
	_PSR,	_PSR,	_PSR,	_PSD,	_PSR,	_PSD,	_PSR,	_PSR,	/*58*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*60*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*68*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*70*/
	_PSR,	_PSR,	_PSR,	_PSD,	_PSR,	_PSD,	_PSR,	_PSR,	/*78*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*80*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*88*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*90*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*98*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*A0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*A8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*B0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*B8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*C0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*C8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*D0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*D8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*E0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*E8*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	/*F0*/
	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR,	_PSR	/*F8*/
};

#define	isPSspace(c)	((ps_ctype+1)[c]&_PSS)
#define	isPSdelim(c)	((ps_ctype+1)[c]&_PSD)
#define	isPSreg(c)	((ps_ctype+1)[c]&_PSR)

extern int psout_8bit_strings, gentlewash;
extern int sheetalign, outpagecnt;
extern char *pagelabel;
extern struct srcdoc *curdoc;
extern FILE *srcfile;
extern char srcline[];
extern char trailercomment[];

static int ps_numbuf[2], ps_numcnt, ps_lastname, ps_hadout, ps_strlen;
static u_char ps_strbuf[1024];

extern char progname[];

flush_nums()
{
	register int i;

	for (i = 0; i < ps_numcnt; i++) {
		if (ps_lastname)
			putchar(' ');
		printf("%d", ps_numbuf[i]);
		ps_lastname = 1;
		ps_hadout = 1;
	}
	ps_numcnt = 0;
}

char *
get_ascii_string(start)
	char *start;
{
	register char *cp;
	register u_char *dp;
	register int ch;
	int parcnt = 1;

	for (cp = start + 1, dp = ps_strbuf; ; ) {
		ch = *cp++;
		switch (ch) {
		case '\0':
invbrk:			fprintf(stderr,
		"%s: line %d: ASCII string spans line boundary (unsupported)\n",
				curdoc->filename, curdoc->lineno);
			exit(1);
		case '(':
			parcnt++;
			break;
		case ')':
			parcnt--;
			if (!parcnt)
				goto done;
			break;
		case '\\':
			ch = *cp++;
			switch (ch) {
			case '\0':
				goto invbrk;
			case 'b':
				*dp++ = '\b';
				break;
			case 'f':
				*dp++ = '\f';
				break;
			case 'n':
				*dp++ = '\n';
				break;
			case 'r':
				*dp++ = '\r';
				break;
			case 't':
				*dp++ = '\t';
				break;
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
				ch -= '0';
				if (*cp >= '0' && *cp <= '7')
					ch = (ch << 3) | (*cp++ - '0');
				if (*cp >= '0' && *cp <= '7')
					ch = (ch << 3) | (*cp++ - '0');
				/*FALLTHRU*/
			default:
				*dp++ = ch;
			}
			break;
		default:
			*dp++ = ch;
		}
	}
done:	ps_strlen = dp - ps_strbuf;
	return(cp);
}

char *
get_hex_string(start)
	char *start;
{
	register char *cp;
	register u_char *dp;
	register int ch, byte;

	for (cp = start + 1, dp = ps_strbuf; ; ) {
		do
			ch = *cp++;
		while (isspace(ch));
		if (ch == '>')
			break;
		if (!isxdigit(ch))
			goto inv;
		if (isdigit(ch))
			byte = ch - '0';
		else if (isupper(ch))
			byte = ch - 'A' + 10;
		else
			byte = ch - 'a' + 10;
		byte <<= 4;
		do
			ch = *cp++;
		while (isspace(ch));
		if (ch == '>') {
			ch = '0';
			cp--;
		}
		if (!isxdigit(ch))
			goto inv;
		if (isdigit(ch))
			byte |= ch - '0';
		else if (isupper(ch))
			byte |= ch - 'A' + 10;
		else
			byte |= ch - 'a' + 10;
		*dp++ = byte;
	}
	ps_strlen = dp - ps_strbuf;
	return(cp);

inv:	if (!ch)
		fprintf(stderr,
		"%s: line %d: hex string spans line boundary (unsupported)\n",
			curdoc->filename, curdoc->lineno);
	else
		fprintf(stderr, "%s: line %d: invalid hex string\n",
			curdoc->filename, curdoc->lineno);
	exit(1);
}

string_out()
{
	u_char *end = ps_strbuf + ps_strlen;
	register u_char *cp;
	register int ch;
	int asclen;

	for (cp = ps_strbuf, asclen = 0; cp < end; cp++) {
		ch = *cp;
		if (ch<0x20 || ch>=0x7F && (!psout_8bit_strings || ch<=0x9F))
			asclen += 4;
		else if (ch == '(' || ch == ')' || ch == '\\')
			asclen += 2;
		else
			asclen++;
	}
	if (asclen <= (ps_strlen << 1)) {
		/* ASCII output */
		putchar('(');
		for (cp = ps_strbuf; cp < end; cp++) {
			ch = *cp;
			if (ch<0x20 || ch>=0x7F &&
			    (!psout_8bit_strings || ch<=0x9F))
				printf("\\%03o", ch);
			else {
				if (ch == '(' || ch == ')' || ch == '\\')
					putchar('\\');
				putchar(ch);
			}
		}
		putchar(')');
	} else {
		/* hex output */
		putchar('<');
		for (cp = ps_strbuf; cp < end; cp++)
			printf("%02X", *cp);
		putchar('>');
	}
	ps_lastname = 0;
	ps_hadout = 1;
}

pass2()
{
	register char *cp, *np;
	char saved_delim = 0;

	for (;;) {
		getline();
		if (!strcmp(srcline, trailercomment))
			break;
		if (!strncmp(srcline, "%%Page:", 7)) {
			for (cp = srcline + 7; isspace(*cp); cp++)
				;
			if (!isgraph(*cp)) {
invpage:			fprintf(stderr,
				"%s: line %d: invalid %%%%Page: comment\n",
					curdoc->filename, curdoc->lineno);
				exit(1);
			}
			for (np = cp; isgraph(*cp); cp++)
				;
			if (!isspace(*cp))
				goto invpage;
			*cp = '\0';
			++outpagecnt;
			emit_page_comment(np);
			continue;
		}
		/* pass all other full line comments through as is */
		if (srcline[0] == '%') {
			puts(srcline);
			continue;
		}
		/* the gentle cycle is simple */
		if (gentlewash) {
			if (!psout_8bit_strings)
				gentlecycle_8bit_check();
			puts(srcline);
			continue;
		}
		/* The hard work begins: parse actual PS code */
		ps_numcnt = ps_lastname = ps_hadout = 0;
		for (cp = srcline; ; ) {
			/* skip preceding whitespace first */
			while (*cp && isPSspace(*cp))
				cp++;
			switch (*cp) {
			case '\0':
			case '%':
				goto endpsline;
			case '(':
				flush_nums();
				cp = get_ascii_string(cp);
				string_out();
				break;
			case ')':
				flush_nums();
				fprintf(stderr, "%s: line %d: unmatched ')'\n",
					curdoc->filename, curdoc->lineno);
				exit(1);
			case '<':
				flush_nums();
				if (cp[1] == '<') {
					putchar(*cp++);
					putchar(*cp++);
					ps_lastname = 0;
					ps_hadout = 1;
					break;
				}
				cp = get_hex_string(cp);
				string_out();
				break;
			case '>':
				flush_nums();
				if (cp[1] == '>') {
					putchar(*cp++);
					putchar(*cp++);
					ps_lastname = 0;
					ps_hadout = 1;
					break;
				}
				fprintf(stderr, "%s: line %d: unmatched '>'\n",
					curdoc->filename, curdoc->lineno);
				exit(1);
			case '[':
			case ']':
			case '{':
			case '}':
				flush_nums();
				putchar(*cp++);
				ps_lastname = 0;
				ps_hadout = 1;
				break;
			case '/':
				flush_nums();
				putchar(*cp++);
				if (!isPSreg(*cp)) {
					fprintf(stderr,
		"%s: line %d: '/' must be followed by a regular character\n",
					curdoc->filename, curdoc->lineno);
					exit(1);
				}
				while (isPSreg(*cp))
					putchar(*cp++);
				ps_lastname = 1;
				ps_hadout = 1;
				break;
			default:
				for (np = cp; isPSreg(*cp); cp++)
					;
				if (isPSspace(*cp) && *cp)
					*cp++ = '\0';
				else if (isPSdelim(*cp)) {
					saved_delim = *cp;
					*cp = '\0';
				}
				if (is_short_num(np)) {
					if (ps_numcnt == 2) {
						if (ps_lastname)
							putchar(' ');
						printf("%d", ps_numbuf[0]);
						ps_lastname = 1;
						ps_hadout = 1;
						ps_numbuf[0] = ps_numbuf[1];
						ps_numcnt = 1;
					}
					ps_numbuf[ps_numcnt++] = atoi(np);
				} else {
					if (!strcmp(np, "SF"))
						handle_SF();
					flush_nums();
					if (ps_lastname)
						putchar(' ');
					fputs(np, stdout);
					ps_lastname = 1;
					ps_hadout = 1;
				}
				if (saved_delim) {
					*cp = saved_delim;
					saved_delim = 0;
				}
			}
		}
endpsline:	flush_nums();
		if (ps_hadout)
			putchar('\n');
	}
}

is_short_num(str)
	char *str;
{
	register char *cp;
	register int len;

	for (cp = str, len = 0; *cp; cp++) {
		if (++len > 3)
			return(0);
		if (!isdigit(*cp))
			return(0);
	}
	/* If it has leading zeros, it isn't for SF and let's leave it alone */
	if (str[0] == '0' && len > 1)
		return(0);
	return(1);
}

handle_SF()
{
	if (ps_numcnt != 2) {
		fprintf(stderr,
			"%s: line %d: SF must be preceded by two numbers\n",
			curdoc->filename, curdoc->lineno);
		exit(1);
	}
	if (ps_numbuf[0] >= curdoc->nfonts) {
		fprintf(stderr,
		"%s: line %d: %d %d SF requests font number out of range\n",
			curdoc->filename, curdoc->lineno, ps_numbuf[0],
			ps_numbuf[1]);
		exit(1);
	}
	ps_numbuf[0] = curdoc->fontmap[ps_numbuf[0]];
}

emit_page_comment(oldlabel)
	char *oldlabel;
{
	register char *cp;
	register int c;

	fputs("%%Page: ", stdout);
	for (cp = pagelabel; c = *cp++; ) {
		if (c != '%') {
			putchar(c);
			continue;
		}
		c = *cp++;
		if (!c)
			break;
		switch (c) {
		case 'f':
			fputs(curdoc->filename, stdout);
			break;
		case 'l':
			fputs(oldlabel, stdout);
			break;
		case 'n':
			printf("%d", outpagecnt);
			break;
		default:
			putchar(c);
		}
	}
	printf(" %d\n", outpagecnt);
}

gentlecycle_8bit_check()
{
	register char *cp;

	for (cp = srcline; *cp; cp++)
		if (*cp & 0x80) {
			fprintf(stderr,
		"%s -g: %s contains 8-bit characters, please specify -8\n",
				progname, curdoc->filename);
			exit(1);
		}
}
