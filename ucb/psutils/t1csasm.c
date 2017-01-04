/*
 * Adobe Type 1 font charstring assembler.
 *
 * This program takes an Adobe Type 1 font program in an 'assembly language'
 * form, which consists of valid executable PostScript everywhere except in
 * the charstrings, which are represented in the textual form used in the
 * Adobe Type 1 Font Format manual, and turns it into fully valid executable
 * PostScript.  The charstrings are assembled and output as hex strings.
 * Per IFCTF principles no encryption is used, so lenIV must be set to -1.
 *
 * Written by Michael Sokolov <msokolov@ivan.Harhan.ORG>,
 * International Free Computing Task Force
 */

#ifndef lint
static char sccsid[] = "@(#)t1csasm.c	1.1 (IFCTF) 04/10/29";
#endif

#include <sys/param.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>

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

int in_charstring;

main(argc, argv)
	char **argv;
{
	register int ch, i;
	register u_char *cp;
	u_char name[512];

	/* We work from stdin to stdout */
	if (argc >= 2)
		if (freopen(argv[1], "r", stdin) == NULL) {
			perror(argv[1]);
			exit(1);
		}
	if (argc >= 3)
		if (freopen(argv[2], "w", stdout) == NULL) {
			perror(argv[2]);
			exit(1);
		}

	/* Here comes the meat of this program: our nano-PS interpreter */
	for (;;) {
prespc:		while (isPSspace(ch = getchar()))
			if (!in_charstring)
				putchar(ch);
		switch (ch) {
		case EOF:
			exit(0);
		case '%':
			if (!in_charstring)
				putchar(ch);
			/*
			 * comment continues until \n, then back to regular
			 * preceding whitespace processing
			 */
			while ((ch = getchar()) != EOF) {
				if (!in_charstring)
					putchar(ch);
				if (ch == '\n')
					break;
			}
			goto prespc;
		case '(':
			if (in_charstring)
				goto typecheck;
			putchar(ch);
			for (i = 1; ; ) {
				ch = getchar();
				if (ch == EOF) {
eofmidstring:				fputs("EOF in mid-string\n", stderr);
					exit(1);
				}
				putchar(ch);
				if (ch == '\\') {
					ch = getchar();
					if (ch == EOF)
						goto eofmidstring;
					putchar(ch);
					continue;
				}
				if (ch == '(')
					i++;
				if (ch == ')' && --i == 0)
					break;
			}
			break;
		case ')':
			fputs("syntaxerror: scanner hit \')\'\n", stderr);
			exit(1);
		case '<':
			/* This is a charstring */
			if (in_charstring) {
				fputs("nested charstring\n", stderr);
				exit(1);
			}
			putchar(ch);
			in_charstring = 1;
			break;
		case '>':
			if (!in_charstring) {
				fputs("\'>\' not in a charstring\n", stderr);
				exit(1);
			}
			putchar(ch);
			in_charstring = 0;
			break;
		case '[':
		case ']':
		case '{':
		case '}':
			if (in_charstring)
				goto typecheck;
			putchar(ch);
			break;
		case '/':
		default:
			cp = name;
			*cp++ = ch;
			ch = getchar();
			while (isPSreg(ch)) {
				*cp++ = ch;
				ch = getchar();
			}
			*cp = '\0';
			ungetc(ch, stdin);
			if (in_charstring) {
				if (is_integer(name))
					emit_cs_num(atoi(name));
				else
					emit_cs_cmd(name);
			} else
				fputs(name, stdout);
			break;
		typecheck:
			fprintf(stderr,
		"typecheck: object in charstring other than integer or name\n");
			exit(1);
		}
	}
}

is_integer(str)
	char *str;
{
	register char *cp;

	cp = str;
	if (*cp == '+' || *cp == '-')
		cp++;
	while (*cp)
		if (!isdigit(*cp++))
			return(0);
	return(1);
}

emit_cs_num(num)
	register int num;
{
	register int abs;

	if (num == INT_MIN)
		goto lnum;
	if (num >= 0)
		abs = num;
	else
		abs = -num;
	if (abs > 1131)
		goto lnum;
	if (abs <= 107) {
		printf("%02X", num + 139);
		return;
	}
	if (num > 0)
		num = 0xF700;
	else
		num = 0xFB00;
	abs -= 108;
	printf("%04X", num + abs);
	return;
lnum:	printf("FF%08X", num);
}

struct cmd {
	char *name;
	int twobyte;
	int code;
} cmdtab[] = {
	"hstem", 0, 1,
	"vstem", 0, 3,
	"vmoveto", 0, 4,
	"rlineto", 0, 5,
	"hlineto", 0, 6,
	"vlineto", 0, 7,
	"rrcurveto", 0, 8,
	"closepath", 0, 9,
	"callsubr", 0, 10,
	"return", 0, 11,
	"escape", 0, 12,
	"hsbw", 0, 13,
	"endchar", 0, 14,
	"rmoveto", 0, 21,
	"hmoveto", 0, 22,
	"vhcurveto", 0, 30,
	"hvcurveto", 0, 31,
	"dotsection", 1, 0,
	"vstem3", 1, 1,
	"hstem3", 1, 2,
	"seac", 1, 6,
	"sbw", 1, 7,
	"div", 1, 12,
	"callothersubr", 1, 16,
	"pop", 1, 17,
	"setcurrentpoint", 1, 33,
	NULL, 0, 0
};

emit_cs_cmd(name)
	register char *name;
{
	register struct cmd *cp;

	for (cp = cmdtab; cp->name; cp++)
		if (!strcmp(cp->name, name))
			break;
	if (!cp->name) {
		fprintf(stderr, "%s: unknown command\n", name);
		exit(1);
	}
	printf(cp->twobyte ? "0C%02X" : "%02X", cp->code);
}
