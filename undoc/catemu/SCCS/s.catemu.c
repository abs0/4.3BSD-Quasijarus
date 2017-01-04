h34434
s 00342/00000/00000
d D 5.1 04/09/10 23:19:12 msokolov 1 0
c date and time created 04/09/10 23:19:12 by msokolov
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

/*
 * Cat Simulator for PostScript
 */ 

#include <sys/param.h>
#include <stdio.h>
#include <strings.h>

extern char *optarg;
extern int optind;

struct point_sizes {
	int	stupid_code;
	int	real_code;
} point_sizes[] = {
	010, 6,
	0, 7,
	01, 8,
	07, 9,
	02, 10,
	03, 11,
	04, 12,
	05, 14,
	0211, 16,
	06, 18,
	0212, 20,
	0213, 22,
	0214, 24,
	0215, 28,
	0216, 36,
	0, 0
};

#define	PAGELENGTH	4752
int	last_ssize = 02;
int	xpos, ypos = PAGELENGTH;
int	esc, lead, back, verd, mcase, railmag, pts = 10;
int	psfont, pspts, pageopen, pagenum, nc;
int	includersrc, finalstatus;

main(argc, argv) 
	int argc;
	char *argv[];
{
	register int opt;

	while ((opt = getopt(argc, argv, "is")) != EOF) {
		switch (opt) {
		case 'i':
			includersrc++;
			break;
		case 's':
			finalstatus++;
			break;
		case '?':
			exit(1);
		}
	}

	if (argv[optind])
		if (!freopen(argv[optind], "r", stdin)) {
			perror(argv[optind]);
			exit(1);
		}

	puts("%!PS-Adobe-3.0");
	puts("%%Creator: cat emulator");
	puts("%%DocumentData: Clean7Bit");
	puts("%%LanguageLevel: 2");
	puts("%%Pages: (atend)");
	puts("%%DocumentNeededResources: font Times-Roman Times-Italic Times-Bold Symbol");
	if (includersrc)
		puts("%%+ font Special");
	else
		puts("%%DocumentSuppliedResources: font Special");
	puts("%%+ encoding CatemuEncoding");
	puts("%%+ procset (catemu procedures) 0 0");
	puts("%%EndComments");

	puts("%%BeginProlog");
	if (includersrc) {
		puts("%%IncludeResource: procset (catemu procedures) 0 0");
		puts("%%IncludeResource: encoding CatemuEncoding");
		puts("%%IncludeResource: font Special");
	} else {
		includefile("/usr/lib/catemu/CatemuProcset.ps");
		includefile("/usr/lib/catemu/CatemuEncoding.ps");
		includefile("/usr/lib/catemu/SpecialFont.ps");
	}
	puts("%%EndProlog");

	puts("%%BeginSetup");
	puts("/railmag [");
	prepromanfont("Times-Roman");
	prepromanfont("Times-Italic");
	prepromanfont("Times-Bold");
	puts("/Special findfont");
	puts("] def");
	puts("%%EndSetup");

	ofile();
	if (finalstatus)
		fprintf(stderr, "Finished with page %s at y=%d\n",
			pageopen ? "open" : "closed", ypos);
	if (pageopen)
		closepage();

	puts("%%Trailer");
	printf("%%%%Pages: %d\n", pagenum);
	puts("%%EOF");
	return(0);
}

includefile(filename)
	char *filename;
{
	register FILE *f;
	register int c;

	f = fopen(filename, "r");
	if (!f) {
		perror(filename);
		exit(1);
	}
	while ((c = getc(f)) != EOF)
		putchar(c);
	fclose(f);
}

prepromanfont(fontname)
	char *fontname;
{
	printf("/%s findfont\n", fontname);
	puts("dup dup length 1 add dict begin");
	puts("\t{1 index /FID ne {def} {pop pop} ifelse} forall");
	puts("\t1000 scalefont /Recurse exch def");
	puts("\textendroman");
	puts("\t/Encoding CatemuEncoding def");
	puts("\tcurrentdict");
	puts("end");
	printf("/%s-catemu exch definefont\n", fontname);
}

ofile()
{
	register int c;

	while ((c = getchar()) != EOF) {
		if (!c)
			continue;
		if (c & 0200) {
			esc += (~c) & 0177;
			continue;
		}
		if (esc) {
			if (back)
				esc = -esc;
			xpos += esc;
			esc = 0;
		}
		if ((c & 0377) < 0100)	/*  Purely for efficiency  */
			goto normal_char;
		switch (c) {

		case 0100:
			/* no initialization needed */
			break;

		case 0101:	/* lower rail */
			railmag &= ~01;
			break;

		case 0102:	/* upper rail */
			railmag |= 01;
			break;

		case 0103:	/* upper mag */
			railmag |= 02;
			break;

		case 0104:	/* lower mag */
			railmag &= ~02;
			break;

		case 0105:	/* lower case */
			mcase = 0;
			break;

		case 0106:	/* upper case */
			mcase = 0100;
			break;

		case 0107:	/* escape forward */
			back = 0;
			break;

		case 0110:	/* escape backwards */
			back = 1;
			break;

		case 0111:	/* stop */
			break;

		case 0112:	/* lead forward */
			verd = 0;
			break;

		case 0113:	/* undefined */
			break;

		case 0114:	/* lead backward */
			verd = 1;
			break;

		case 0115:	/* undefined */
		case 0116:
		case 0117:
			break;

		default:
			if ((c & 0340) == 0140)	/* leading */ {
				lead = (~c) & 037;
				if (verd)
					lead = -lead;
				ypos -= lead * 3;
				if (ypos < 0) {
					if (pageopen)
						closepage();
					else
						fprintf(stderr,
		"Warning: lead through empty page (after %d), not printed\n",
							pagenum);
					ypos += PAGELENGTH;
				}
				continue;
			}
			if ((c & 0360) == 0120)	/* size change */ {
				pts = findsize(c & 017);
				continue;
			}
			if (c & 0300)
				continue;

normal_char:
			c = (c & 077) | mcase;
			outc(c);
		}
	}
}

findsize(code)
	register int code;
{
	register struct point_sizes *psp;

	psp = point_sizes;
	while (psp->real_code != 0) {
		if ((psp->stupid_code & 017) == code)
			break;
		psp++;
	}
	code = 0;
	if (!(last_ssize & 0200) && (psp->stupid_code & 0200))
		code = -55;
	else if ((last_ssize & 0200) && !(psp->stupid_code & 0200))
		code = 55;
	if (back)
		code = -code;
	esc += code;
	last_ssize = psp->stupid_code;
	return(psp->real_code);
}

openpage()
{
	pagenum++;
	printf("%%Page: %d %d\n", pagenum, pagenum);
	puts("save 1 6 div dup scale");
	pageopen = 1;
	psfont = pspts = 0;
}

closepage()
{
	if (nc) {
		putchar('\n');
		nc = 0;
	}
	puts("restore showpage");
	pageopen = 0;
}

outc(c)
	int c;
{
	if (!pageopen)
		openpage();
	if (railmag != psfont || pts != pspts) {
		if (nc) {
			putchar('\n');
			nc = 0;
		}
		printf("%d %d SF\n", railmag, pts);
		psfont = railmag;
		pspts = pts;
	}
	if (nc)
		putchar(' ');
	printf("%d %d <%02X> P", xpos, ypos, c);
	nc++;
	if (nc >= 4) {
		putchar('\n');
		nc = 0;
	}
}
E 1
