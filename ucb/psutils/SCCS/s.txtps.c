h47853
s 00024/00007/00466
d D 5.10 05/07/05 00:44:49 msokolov 10 9
c implemented -e option to recode the font to a different encoding vector
e
s 00002/00000/00471
d D 5.9 05/07/05 00:29:03 msokolov 9 8
c don't allow 8-bit chars without -8
e
s 00063/00004/00408
d D 5.8 04/08/04 05:19:24 msokolov 8 7
c add -r option to generate pr-like headers
e
s 00013/00015/00399
d D 5.7 04/08/04 04:20:54 msokolov 7 6
c on further thought, there is no point in trimming lines unless doing
c wraparound, since going past the edge of paper is harmless on PostScript
c printers.
c replace -m<number> and -W with -w<number>
e
s 00003/00003/00411
d D 5.6 02/12/20 11:57:08 msokolov 6 5
c doh, font names are literal, not executable!
e
s 00001/00000/00413
d D 5.5 02/12/19 15:02:57 msokolov 5 4
c fix -X (missing break in switch)
e
s 00030/00003/00383
d D 5.4 02/12/19 15:00:26 msokolov 4 3
c finally handle font requirements nicely
e
s 00046/00020/00340
d D 5.3 02/12/19 14:43:09 msokolov 3 2
c fix handling of \377, add -H
e
s 00001/00000/00359
d D 5.2 02/12/19 14:20:19 msokolov 2 1
c %%EndSetup was missing
e
s 00359/00000/00000
d D 5.1 02/12/19 14:18:01 msokolov 1 0
c date and time created 02/12/19 14:18:01 by msokolov
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/param.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
I 8
#include <time.h>
E 8

unsigned pageheight = 792;
unsigned topmargin = 36;
unsigned bottommargin = 36;
unsigned leftmargin = 54;
unsigned pointsize = 10;
unsigned linespacing;
D 10
char *basefont = "Courier";
E 10
I 10
char *basefont = "Courier", *recode;
E 10

unsigned curpage;
int pageprinting;
unsigned linesleft;
unsigned currenty;
D 4
int currentfont, pagehasbold;
E 4
I 4
int currentfont, pagehasbold, dochasbold, globalbold;
E 4

D 7
unsigned maxtextline = 80;
E 7
I 7
unsigned maxtextline = 256;
E 7
int wraparound;
u_short textline[256];
unsigned textlinelen;
int textlinetoolong;
int fmtctrl = 1, undbsund;

D 3
int eightbit, eightext, out7;
E 3
I 3
int eightbit, eightext, out7, outhex;
E 3

I 8
char *prtitle;
time_t prtime;
char *prctime;

E 8
main(argc, argv)
	char **argv;
{
	register int opt;
	register FILE *inp;
	extern int optind;
	extern char *optarg;

D 3
	while ((opt = getopt(argc, argv, "h:t:b:l:p:s:m:WNF:8XC")) != EOF) {
E 3
I 3
D 4
	while ((opt = getopt(argc, argv, "h:t:b:l:p:s:m:WNF:8XCH")) != EOF) {
E 4
I 4
D 7
	while ((opt = getopt(argc, argv, "h:t:b:l:p:s:m:WNBF:8XCH")) != EOF) {
E 7
I 7
D 8
	while ((opt = getopt(argc, argv, "h:t:b:l:p:s:w:NBF:8XCH")) != EOF) {
E 8
I 8
D 10
	while ((opt = getopt(argc, argv, "h:t:b:l:p:s:w:r:NBF:8XCH")) != EOF) {
E 10
I 10
	while ((opt = getopt(argc, argv, "h:t:b:l:p:s:w:r:NBF:8XCHe:")) != EOF){
E 10
E 8
E 7
E 4
E 3
		switch (opt) {
		case 'h':
			pageheight = atoi(optarg);
			break;
		case 't':
			topmargin = atoi(optarg);
			break;
		case 'b':
			bottommargin = atoi(optarg);
			break;
		case 'l':
			leftmargin = atoi(optarg);
			break;
		case 'p':
			pointsize = atoi(optarg);
			break;
		case 's':
			linespacing = atoi(optarg);
			break;
D 7
		case 'm':
E 7
I 7
		case 'w':
E 7
			maxtextline = atoi(optarg);
			if (maxtextline > 256) {
D 7
			  fputs(
			  "maximum line length cannot exceed 256 characters\n",
				stderr);
			  exit(1);
E 7
I 7
				fputs(
		"txtps: maximum line length cannot exceed 256 characters\n",
					stderr);
				exit(1);
E 7
			}
D 7
			break;
		case 'W':
E 7
I 7
			if (maxtextline & 7) {
				fputs(
		"txtps: wraparound line length must be a multiple of 8\n",
		      			stderr);
				exit(1);
			}
E 7
			wraparound = 1;
			break;
I 8
		case 'r':
			prtitle = optarg;
			sanity_check_prtitle();
			prtime = time(NULL);
			prctime = ctime(&prtime);
			prctime[16] = prctime[24] = '\0';
			break;
E 8
		case 'N':
			fmtctrl = 0;
			break;
I 4
		case 'B':
			globalbold = 1;
			break;
E 4
		case 'F':
			basefont = optarg;
			break;
		case '8':
			eightbit = 1;
			break;
		case 'X':
			eightbit = 1;
			eightext = 1;
I 5
			break;
E 5
		case 'C':
			out7 = 1;
			break;
I 3
		case 'H':
			outhex = 1;
			break;
I 10
		case 'e':
			recode = optarg;
			break;
E 10
E 3
		case '?':
			exit(1);
		}
	}

D 7
	if (wraparound && (maxtextline & 7)) {
		fputs(
"maximum line length must be a multiple of 8 when wraparound is enabled\n",
		      stderr);
		exit(1);
	}
E 7
	if (!linespacing)
		linespacing = pointsize;
I 4
	if (!fmtctrl)
		globalbold = 0;
E 4
I 3
	if (!eightbit)
		out7 = outhex = 0;
	if (out7 && outhex) {
		fputs("txtps: use either -C or -H\n", stderr);
		exit(1);
	}
E 3
	if (eightext && out7) {
D 3
		fputs("txtps: -C is not supported with -X\n", stderr);
E 3
I 3
		fputs("txtps: -C is not supported with -X, use -H\n", stderr);
E 3
		exit(1);
	}
D 3
	if (!eightbit)
		out7 = 0;
E 3

	puts("%!PS-Adobe-3.0");
	puts("%%Creator: txtps text to PostScript converter");
D 3
	if (!eightbit || out7)
E 3
I 3
	if (!eightbit || out7 || outhex)
E 3
		puts("%%DocumentData: Clean7Bit");
	else
		puts("%%DocumentData: Clean8Bit");
	puts("%%LanguageLevel: 1");
	puts("%%Pages: (atend)");
I 4
	if (!fmtctrl)
		printf("%%%%DocumentNeededResources: font %s\n", basefont);
	else if (globalbold)
		printf("%%%%DocumentNeededResources: font %s %s-Bold\n",
			basefont, basefont);
	else
		puts("%%DocumentNeededResources: (atend)");
E 4
	puts("%%EndComments");

	puts("%%BeginSetup");
	printf("%%%%IncludeResource: font %s\n", basefont);
I 4
	if (globalbold)
		printf("%%%%IncludeResource: font %s-Bold\n", basefont);
E 4
D 6
	printf("/FR %s findfont %u scalefont def\n", basefont, pointsize);
E 6
I 6
D 10
	printf("/FR /%s findfont %u scalefont def\n", basefont, pointsize);
E 10
I 10
	get_font("FR", "");
E 10
E 6
I 4
	if (globalbold)
D 6
		printf("/FB %s-Bold findfont %u scalefont def\n", basefont,
E 6
I 6
D 10
		printf("/FB /%s-Bold findfont %u scalefont def\n", basefont,
E 6
			pointsize);
E 10
I 10
		get_font("FB", "-Bold");
E 10
E 4
	puts("/P {3 1 roll moveto show} bind def");
	if (fmtctrl) {
		puts("/PU {3 1 roll moveto gsave dup show FR dup /FontMatrix get concat /FontInfo get");
		puts("dup /UnderlinePosition get 0 exch rmoveto /UnderlineThickness get setlinewidth");
		puts("stringwidth rlineto stroke grestore} bind def");
	}
	if (out7)
		puts("/H {0 1 2 index length 1 sub {2 copy 2 copy get 128 or put pop} for} bind def");
I 2
	puts("%%EndSetup");
E 2

	if (argv[optind])
		for (; argv[optind]; optind++) {
			inp = fopen(argv[optind], "r");
			if (inp == NULL) {
				perror(argv[optind]);
				continue;
			}
			printfile(inp);
		}
	else
		printfile(stdin);

	puts("%%Trailer");
	printf("%%%%Pages: %u\n", curpage);
I 4
	if (fmtctrl && !globalbold) {
		if (!dochasbold)
			printf("%%%%DocumentNeededResources: font %s\n",
				basefont);
		else
			printf("%%%%DocumentNeededResources: font %s %s-Bold\n",
				basefont, basefont);
	}
E 4
	puts("%%EOF");
	return(0);
}

printfile(inp)
	register FILE *inp;
{
	register int ch, lowch, oldch;
	register int bslatch = 0, koi7state = 0;

	while ((ch = getc(inp)) != EOF) {
		if (eightext && ch & 0200)
			goto print;
		lowch = ch & 0177;
I 9
		if (!eightbit)
			ch = lowch;
E 9
		if (lowch & 0100 && koi7state)
			ch |= 0200;
		if (lowch >= 040 && ch != 0177) {
print:			if (bslatch && fmtctrl && ch != ' ') {
				oldch = textline[textlinelen] & 0xFF;
				if (oldch == ch)
					ch |= 0x200;
				if (oldch == '_')
					ch |= 0x100;
				if (ch == 0x035F)
					undbsund = 1;
			}
			bslatch = 0;
			if (textlinelen == maxtextline) {
				if (wraparound) {
					printline();
					textlinelen = 0;
				} else {
					textlinetoolong = 1;
					continue;
				}
			}
			textline[textlinelen++] = ch;
			continue;
		}
		bslatch = 0;
		switch (lowch) {
		case '\t':
			do {
				if (textlinelen == maxtextline) {
					if (wraparound) {
						printline();
						textlinelen = 0;
					} else {
						textlinetoolong = 1;
						break;
					}
				}
				textline[textlinelen++] = ' ';
			} while (textlinelen & 7);
			break;
		case '\b':
			if (!textlinelen || textlinetoolong)
				break;
			textlinelen--;
			bslatch = 1;
			break;
		case '\n':
			printline();
			textlinelen = 0;
			break;
		case '\f':
			if (textlinelen) {
				printline();
				textlinelen = 0;
			}
			if (pageprinting)
				flushpage();
			break;
		case '\016':
			if (eightbit && !eightext)
				koi7state = 1;
			break;
		case '\017':
			koi7state = 0;
			break;
		}
	}
	if (textlinelen) {
		printline();
		textlinelen = 0;
	}
	if (pageprinting)
		flushpage();
}

startpage()
{
	curpage++;
	printf("%%%%Page: %u %u\nsave\n", curpage, curpage);
	if (topmargin + bottommargin > pageheight) {
D 8
		fprintf(stderr, "page %u top and bottom margins exceed the page size\n", curpage);
E 8
I 8
		fprintf(stderr,
			"page %u top and bottom margins exceed the page size\n",
			curpage);
E 8
		exit(1);
	}
	linesleft = (pageheight - topmargin - bottommargin) / linespacing;
D 8
	if (!linesleft) {
		fprintf(stderr, "page %u top and bottom margins leave no room for text\n", curpage);
E 8
I 8
	if (!linesleft || prtitle && linesleft < 4) {
		fprintf(stderr,
		    "page %u top and bottom margins leave no room for text\n",
		    curpage);
E 8
		exit(1);
	}
	currenty = pageheight - topmargin;
	pageprinting = 1;
	pagehasbold = 0;
	currentfont = -1;
I 8
	if (prtitle)
		print_pr_header();
E 8
}

flushpage()
{
	fputs("restore\nshowpage\n", stdout);
	pageprinting = 0;
I 4
	if (pagehasbold)
		dochasbold = 1;
E 4
}

printline()
{
	register int i, start, mask, mode;

	if (!pageprinting)
		startpage();
	if (!linesleft) {
		flushpage();
		startpage();
	}
	currenty -= linespacing;

	/* Here we handle the ugliness of _^H_: is it bold or underlined? */
	if (undbsund) {
		for (i = 1; i < textlinelen; i++)
			if (textline[i] == 0x035F) {
				if ((textline[i-1] & 0xFF00) == 0x100)
					textline[i] = 0x015F;
				if ((textline[i-1] & 0xFF00) == 0x200)
					textline[i] = 0x025F;
			}
		for (i = textlinelen - 2; i; i--)
			if (textline[i] == 0x035F) {
				if ((textline[i+1] & 0xFF00) == 0x100)
					textline[i] = 0x015F;
				else
					textline[i] = 0x025F;
			}
		undbsund = 0;
	}

	/*
	 * Now we have to divide our line into strings that can be printed in
	 * one mode.
	 */
	mask = out7 ? 0x0380 : 0x0300;
	start = 0;
	mode = textline[0] & mask;
	for (i = 1; i < textlinelen; i++)
		if ((textline[i] & mask) != mode) {
			printstring(start, i, mode);
			start = i;
			mode = textline[i] & mask;
		}
	if (start < textlinelen)
		printstring(start, textlinelen, mode);

	linesleft--;
}

printstring(start, end, mode)
D 3
	register int start, end, mode;
E 3
I 3
	register int start, end;
	int mode;
E 3
{
D 3
	register int fmt, i, ch;
E 3
I 3
	register int fmt, i, ch, dohex = 0;
E 3

	/* First strip leading and trailing spaces */
	while (start < end && textline[start] == ' ')
		start++;
	while (end > start && textline[end-1] == ' ')
		end--;
	/* Is there anything left? */
	if (start == end)
		return;
	/* Print it */
	fmt = mode & 0xFF00;
D 4
	if (fmt == 0x200 && !pagehasbold) {
E 4
I 4
	if (fmt == 0x200 && !pagehasbold && !globalbold) {
E 4
		printf("%%%%IncludeResource: font %s-Bold\n", basefont);
D 6
		printf("/FB %s-Bold findfont %u scalefont def\n", basefont,
E 6
I 6
D 10
		printf("/FB /%s-Bold findfont %u scalefont def\n", basefont,
E 6
			pointsize);
E 10
I 10
		get_font("FB", "-Bold");
E 10
		pagehasbold = 1;
	}
	if ((fmt == 0 || fmt == 0x100) && currentfont != 0) {
		puts("FR setfont");
		currentfont = 0;
	}
	if (fmt == 0x200 && currentfont != 1) {
		puts("FB setfont");
		currentfont = 1;
	}
	i = start * pointsize * 6;
	printf("%u", leftmargin + i / 10);
	if (i % 10)
		printf(".%u", i % 10);
D 3
	printf(" %u (", currenty);
	for (i = start; i < end; i++) {
		ch = textline[i] & (out7 ? 0x7F : 0xFF);
		if (ch == '(' || ch == ')' || ch == '\\')
			putchar('\\');
		if (ch == '\0177')
			printf("\\0177");
		else
			putchar(ch);
E 3
I 3
	printf(" %u ", currenty);
	if (outhex) {
		for (i = start; i < end; i++)
			if (textline[i] & 0x80)
				break;
		if (i < end)
			dohex++;
E 3
	}
D 3
	putchar(')');
	if (mode & 0x80)
		putchar('H');
E 3
I 3
	if (!dohex) {
		putchar('(');
		for (i = start; i < end; i++) {
			ch = textline[i] & (out7 ? 0x7F : 0xFF);
			if (ch == '\177')
				printf("\\177");
			else if (ch == '\377')
				printf("\\377");
			else {
				if (ch == '(' || ch == ')' || ch == '\\')
					putchar('\\');
				putchar(ch);
			}
		}
		putchar(')');
		if (mode & 0x80)
			putchar('H');
	} else {
		putchar('<');
		for (i = start; i < end; i++)
			printf("%02X", textline[i] & 0xFF);
		putchar('>');
	}
E 3
	if (fmt != 0x100)
		printf(" P\n");
	else
		printf(" PU\n");
I 10
}

get_font(keyname, suffix)
	char *keyname, *suffix;
{
	if (recode) {
		printf("/%s%s findfont dup length dict begin\n", basefont,
			suffix);
		printf("\t{1 index /FID ne {def} {pop pop} ifelse} forall\n");
		printf("\t/Encoding %s def\n", recode);
		printf("currentdict end\n");
		printf("/%s%s-%s exch definefont\n", basefont, suffix, recode);
		printf("/%s exch %u scalefont def\n", keyname, pointsize);
	} else
		printf("/%s /%s%s findfont %u scalefont def\n", keyname,
			basefont, suffix, pointsize);
E 10
I 8
}

sanity_check_prtitle()
{
	register int c, cnt;
	register u_char *cp;

	for (cp = (u_char *) prtitle, cnt = 0; c = *cp++; cnt++)
		if (c < ' ' || c > '~') {
			fputs(
	"txtps: -r argument can only contain printable ASCII characters\n",
				stderr);
			exit(1);
		}
	if (cnt > 128) {
		fputs("txtps: -r argument may not exceed 128 characters\n",
			stderr);
		exit(1);
	}
}

print_pr_header()
{
	char header[256];
	register char *cp;
	register int ch;

	currenty -= linespacing;
	puts("FR setfont");
	currentfont = 0;
	sprintf(header, "%s %s  %s Page %u", prctime + 4, prctime + 20,
		prtitle, curpage);
	printf("%u %u (", leftmargin, currenty);
	for (cp = header; ch = *cp; cp++) {
		if (ch == '(' || ch == ')' || ch == '\\')
			putchar('\\');
		putchar(ch);
	}
	puts(") P");
	currenty -= linespacing * 2;
	linesleft -= 3;
E 8
}
E 1
