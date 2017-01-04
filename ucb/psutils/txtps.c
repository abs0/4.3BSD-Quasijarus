#ifndef lint
static char sccsid[] = "@(#)txtps.c	5.10 (Berkeley) 7/5/05";
#endif

#include <sys/param.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <time.h>

unsigned pageheight = 792;
unsigned topmargin = 36;
unsigned bottommargin = 36;
unsigned leftmargin = 54;
unsigned pointsize = 10;
unsigned linespacing;
char *basefont = "Courier", *recode;

unsigned curpage;
int pageprinting;
unsigned linesleft;
unsigned currenty;
int currentfont, pagehasbold, dochasbold, globalbold;

unsigned maxtextline = 256;
int wraparound;
u_short textline[256];
unsigned textlinelen;
int textlinetoolong;
int fmtctrl = 1, undbsund;

int eightbit, eightext, out7, outhex;

char *prtitle;
time_t prtime;
char *prctime;

main(argc, argv)
	char **argv;
{
	register int opt;
	register FILE *inp;
	extern int optind;
	extern char *optarg;

	while ((opt = getopt(argc, argv, "h:t:b:l:p:s:w:r:NBF:8XCHe:")) != EOF){
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
		case 'w':
			maxtextline = atoi(optarg);
			if (maxtextline > 256) {
				fputs(
		"txtps: maximum line length cannot exceed 256 characters\n",
					stderr);
				exit(1);
			}
			if (maxtextline & 7) {
				fputs(
		"txtps: wraparound line length must be a multiple of 8\n",
		      			stderr);
				exit(1);
			}
			wraparound = 1;
			break;
		case 'r':
			prtitle = optarg;
			sanity_check_prtitle();
			prtime = time(NULL);
			prctime = ctime(&prtime);
			prctime[16] = prctime[24] = '\0';
			break;
		case 'N':
			fmtctrl = 0;
			break;
		case 'B':
			globalbold = 1;
			break;
		case 'F':
			basefont = optarg;
			break;
		case '8':
			eightbit = 1;
			break;
		case 'X':
			eightbit = 1;
			eightext = 1;
			break;
		case 'C':
			out7 = 1;
			break;
		case 'H':
			outhex = 1;
			break;
		case 'e':
			recode = optarg;
			break;
		case '?':
			exit(1);
		}
	}

	if (!linespacing)
		linespacing = pointsize;
	if (!fmtctrl)
		globalbold = 0;
	if (!eightbit)
		out7 = outhex = 0;
	if (out7 && outhex) {
		fputs("txtps: use either -C or -H\n", stderr);
		exit(1);
	}
	if (eightext && out7) {
		fputs("txtps: -C is not supported with -X, use -H\n", stderr);
		exit(1);
	}

	puts("%!PS-Adobe-3.0");
	puts("%%Creator: txtps text to PostScript converter");
	if (!eightbit || out7 || outhex)
		puts("%%DocumentData: Clean7Bit");
	else
		puts("%%DocumentData: Clean8Bit");
	puts("%%LanguageLevel: 1");
	puts("%%Pages: (atend)");
	if (!fmtctrl)
		printf("%%%%DocumentNeededResources: font %s\n", basefont);
	else if (globalbold)
		printf("%%%%DocumentNeededResources: font %s %s-Bold\n",
			basefont, basefont);
	else
		puts("%%DocumentNeededResources: (atend)");
	puts("%%EndComments");

	puts("%%BeginSetup");
	printf("%%%%IncludeResource: font %s\n", basefont);
	if (globalbold)
		printf("%%%%IncludeResource: font %s-Bold\n", basefont);
	get_font("FR", "");
	if (globalbold)
		get_font("FB", "-Bold");
	puts("/P {3 1 roll moveto show} bind def");
	if (fmtctrl) {
		puts("/PU {3 1 roll moveto gsave dup show FR dup /FontMatrix get concat /FontInfo get");
		puts("dup /UnderlinePosition get 0 exch rmoveto /UnderlineThickness get setlinewidth");
		puts("stringwidth rlineto stroke grestore} bind def");
	}
	if (out7)
		puts("/H {0 1 2 index length 1 sub {2 copy 2 copy get 128 or put pop} for} bind def");
	puts("%%EndSetup");

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
	if (fmtctrl && !globalbold) {
		if (!dochasbold)
			printf("%%%%DocumentNeededResources: font %s\n",
				basefont);
		else
			printf("%%%%DocumentNeededResources: font %s %s-Bold\n",
				basefont, basefont);
	}
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
		if (!eightbit)
			ch = lowch;
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
		fprintf(stderr,
			"page %u top and bottom margins exceed the page size\n",
			curpage);
		exit(1);
	}
	linesleft = (pageheight - topmargin - bottommargin) / linespacing;
	if (!linesleft || prtitle && linesleft < 4) {
		fprintf(stderr,
		    "page %u top and bottom margins leave no room for text\n",
		    curpage);
		exit(1);
	}
	currenty = pageheight - topmargin;
	pageprinting = 1;
	pagehasbold = 0;
	currentfont = -1;
	if (prtitle)
		print_pr_header();
}

flushpage()
{
	fputs("restore\nshowpage\n", stdout);
	pageprinting = 0;
	if (pagehasbold)
		dochasbold = 1;
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
	register int start, end;
	int mode;
{
	register int fmt, i, ch, dohex = 0;

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
	if (fmt == 0x200 && !pagehasbold && !globalbold) {
		printf("%%%%IncludeResource: font %s-Bold\n", basefont);
		get_font("FB", "-Bold");
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
	printf(" %u ", currenty);
	if (outhex) {
		for (i = start; i < end; i++)
			if (textline[i] & 0x80)
				break;
		if (i < end)
			dohex++;
	}
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
	if (fmt != 0x100)
		printf(" P\n");
	else
		printf(" PU\n");
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
}
