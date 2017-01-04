h39178
s 00001/00002/00340
d D 5.2 11/07/04 18:22:06 msokolov 6 5
c bugfix: skipping horizontal pixels in the default zoom mode
e
s 00017/00004/00325
d D 5.1 87/11/04 19:11:39 bostic 5 4
c merged version from ralph; add copyright
e
s 00077/00025/00252
d D 4.4 81/05/30 01:15:47 mark 4 3
c added -m message option
e
s 00151/00021/00126
d D 4.3 81/05/30 01:14:07 mark 3 2
c added -z option from Steve Stone
e
s 00012/00005/00135
d D 4.2 81/02/28 22:08:12 wnj 2 1
c improve aspect ratio
e
s 00140/00000/00000
d D 4.1 80/10/01 17:29:21 bill 1 0
c date and time created 80/10/01 17:29:21 by bill
e
u
U
t
T
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 3
static	char *sccsid = "%W% (Berkeley) %E%";
E 3
I 3
D 4
static char *sccsid = "@(#)vfontinfo.c	4.1 (Berkeley) 10/1/80";
E 4
I 4
D 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 5
E 4
E 3
E 2
/* Font Information for VCat-style fonts
D 3
 *      AJH  4/79
E 3
I 3
 *      Andy Hertzfeld  4/79
E 3
 *
 *	Modified to print Ascii chars 1/80 by Mark Horton
I 2
D 3
 *	Modified to use ,'| 1/81 by Mark Horton using an idea
 *		from Eric Scott of CalTech.
E 3
I 3
 *	Zoom option added 5/81 by Steve Stone with tables from Mark Horton.
I 4
 *	Message option added 5/31 by Mark Horton
E 4
E 3
E 2
 */
#include <stdio.h>
#include <ctype.h>
#include <vfont.h>

struct header FontHeader;
D 5
struct dispatch disptable[256] ;
E 5
I 5
struct dispatch disptable[256];
E 5

char	IName[100];
char *	rdchar();
long	fbase;

char	defascii[256];
char	*charswanted = defascii;
int	verbose;
char	charbits[4000];
D 4
int	H, W, WB;
I 3
int 	zoom = -1;
E 4
I 4
int	H, W, WB, base;
int 	zoom = 1;
E 4
E 3

I 4
char msgout[24][80];
int msgflag = 0;
int curline, curcol;	/* cursor, numbered from lower left corner */
int minline=24, maxline=0, maxcol=0;

E 4
main(argc,argv)
int argc;
char **argv;

{
	int FID,i,j;

D 3
	if (argc > 1 && argv[1][0] == '-') {
E 3
I 3
	while (argc > 1 && argv[1][0] == '-') {
E 3
		switch(argv[1][1]) {
		case 'v':
			verbose++;
			break;
I 3
		case 'z':
			zoom = argv[1][2] - '0';
			break;
I 4
		case 'm':
			msgflag = 1;
			zoom = 2;
			for (i=0; i<24; i++)
				for (j=0; j<80; j++)
					msgout[i][j] = ' ';
			curline = 5; curcol = 0;
			break;
E 4
E 3
		default:
			printf("Bad flag: %s\n", argv[1]);
		}
		argc--; argv++;
	}
	if (argc < 2) {
		fprintf(stderr,"Usage: %s filename", argv[0]);
		exit(2);
	}

	for (i=0; i<128; i++)
		defascii[i] = i;
	if (argc >= 3)
		charswanted = argv[2];

	sprintf(IName,"/usr/lib/vfont/%s",argv[1]);
	if ((FID = open(argv[1],0)) < 0)
		if ((FID = open(IName,0)) < 0) { 
			printf("Can't find %s\n",argv[1]);
			exit(8); 
		};

	if (read(FID,&FontHeader,sizeof FontHeader) != sizeof FontHeader)
		error("Bad header in Font file.");

	if (read(FID,&disptable[0],sizeof disptable) != sizeof disptable)
		error("Bad dispatch table in Font file");

	fbase = sizeof FontHeader + sizeof disptable;

	if (FontHeader.magic != 0436)
D 4
	printf("Magic number %o wrong\n", FontHeader.magic);
	printf("Font %s, ",argv[1]);
	printf("raster size %d, ",FontHeader.size);
	printf("max width %d, max height %d, xtend %d\n",
		FontHeader.maxx, FontHeader.maxy,FontHeader.xtend);
D 2
	printf("\n ASCII     offset    size  left    right   up     down    width \n");
E 2
I 2
D 3
	if (!verbose)
		printf("\n ASCII     offset    size  left    right   up     down    width \n");
E 3
I 3
	printf("\n ASCII     offset    size  left    right   up     down    width \n");
E 4
I 4
		printf("Magic number %o wrong\n", FontHeader.magic);
	if (!msgflag) {
		printf("Font %s, ",argv[1]);
		printf("raster size %d, ",FontHeader.size);
		printf("max width %d, max height %d, xtend %d\n",
			FontHeader.maxx, FontHeader.maxy,FontHeader.xtend);
D 5
		printf("\n ASCII     offset    size  left    right   up     down    width \n");
E 5
I 5
		printf("\n");
		for (i = strlen(argv[1]) + 1; i > 0; --i)
			printf(" ");
		printf("ASCII     offset    size  left    right   up     down    width \n");
E 5
	}
E 4
E 3
E 2

	for (i=0; i<256; i++) {
		j = charswanted[i];
		if (i>0 && j==0)
			break;
		if (disptable[j].nbytes != 0) {
D 2
			printf("  %3o %2s     %4d   %4d   %4d   %4d   %4d   %4d   %5d\n",
E 2
I 2
D 3
			printf(!verbose ?
				"  %3o %2s     %4d   %4d   %4d   %4d   %4d   %4d   %5d\n" :
				"  %3o %2s  a=%d, n=%d, l=%d, r=%d, u=%d, d=%d, w=%d\n",
E 3
I 3
D 4
			printf("  %3o %2s     %4d   %4d   %4d   %4d   %4d   %4d   %5d\n",
E 3
E 2
				j, rdchar(j),
				disptable[j].addr,
				disptable[j].nbytes,
				disptable[j].left,
				disptable[j].right,
				disptable[j].up,
				disptable[j].down,
				disptable[j].width);
			if (verbose) {
E 4
I 4
			if (!msgflag)
D 5
				printf("  %3o %2s     %4d   %4d   %4d   %4d   %4d   %4d   %5d\n",
E 5
I 5
				printf("%s  %3o %2s     %4d   %4d   %4d   %4d   %4d   %4d   %5d\n",
					argv[1],
E 5
					j, rdchar(j),
					disptable[j].addr,
					disptable[j].nbytes,
					disptable[j].left,
					disptable[j].right,
					disptable[j].up,
					disptable[j].down,
					disptable[j].width);
			if (verbose || msgflag) {
E 4
				int len = disptable[j].nbytes;
				int k, l, last;

				lseek(FID, fbase+disptable[j].addr, 0);
				read(FID, charbits, len);
				H = (disptable[j].up) + (disptable[j].down);
				W = (disptable[j].left) + (disptable[j].right);
I 4
				base = disptable[j].up;
E 4
				WB = (W+7)/8;
D 2
				for (k=0; k<H; k++) {
E 2
I 2
D 3
				for (k=0; k<H; k+=2) {
E 2
					for (last=W-1; last >= 0; last--)
						if (fbit(k, last))
							break;
					for (l=0; l<=last; l++) {
D 2
						printf("%c", fbit(k,l)?'M':' ');
E 2
I 2
						printf("%c", " ',|"[fbit(k,l)+2*fbit(k+1,l)]);
E 3
I 3
				if (zoom < 0) {
I 4
					/*
					 * Old 1 for 1 code.  The aspect ratio
					 * is awful, so we don't use it.
					 */
E 4
					for (k=0; k<H; k++) {
						for (last=W-1; last >= 0; last--)
							if (fbit(k, last))
								break;
D 6
						for (l=0; l<=W-1; l++) {
E 6
I 6
						for (l=0; l<=last; l++) {
E 6
							printf("%c", fbit(k,l)?'M':' ');
						}
						printf("\n");
E 3
E 2
					}
					printf("\n");
D 3
				}
				printf("\n");
E 3
I 3
D 4
				} else
E 4
I 4
				} else {
E 4
					shozoom();
I 4
					if (msgflag) {
						k = disptable[j].width;
						if (zoom == 0) k *= 2;
						else if (zoom == 2) k /= 2;
						curcol += k;
					}
				}
E 4
E 3
			}
		}
D 3
	};
E 3
I 3
	}
I 4
	if (msgflag) {
		for (i=maxline; i>=minline; i--) {
			for (j=0; j<maxcol; j++)
				putchar(msgout[i][j]);
			putchar('\n');
		}
	}
E 4
E 3
}

error(string)
char *string;

{ 
	printf("\nvfontinfo: %s\n",string);
	exit(8);
};

char *rdchar(c)
char c;
{
	static char ret[3];
	ret[0] = isprint(c) ? ' ' : '^';
	ret[1] = isprint(c) ?  c  : c^0100;
	ret[2] = 0;
	return (ret);
}

int
fbit(row, col)
int row, col;
{
	int thisbyte, thisbit, ret;

I 2
D 3
	if (row >= H)
		return 0;
E 3
I 3
D 4
	if (row>=H || col>=W) return(0);
E 4
I 4
	if (row<0 || row>=H || col>=W) return(0);
E 4
E 3
E 2
	thisbyte = charbits[row*WB + (col>>3)] & 0xff;
	thisbit = 0x80 >> (col&7);
	ret = thisbyte & thisbit;
	return (ret != 0);
I 3
}


/*
The implementation would work like this:
	zoom level	method
	0		2 chars/pixel, 1 is "[]", 0 is "  ".
	1		2 pixels/char 2x1, using " " "," "'" "|"
	2		8 pixels/char 4x2, using 16x16 table
	3		32 pixels/char 8x4, mapped into (2)
	4 and up	similar, mapped into (2)

The 16x16 table maps a 4x2 pattern into a printing ascii character which
most closely approximates that pattern, e.g. the pattern
	|'
	''
would be represented by the character "[".  I have such a table worked out.

Grainer zoom levels would take the rule of reducing it into a smaller bitmap,
or-ing the bits together.  (e.g. level 3 would take a 2x2 chunk and map it
into a single pixel: 0 if all 4 are 0, 1 otherwise.)  These pixels would be
displayed as in 2.
*/

/*
 * graphtab: a table for rudimentary graphics on ordinary terminals.
 * For each 4x2 bit pattern of the form:
 *	ae
 *	bf
 *	cg
 *	dh
 * form the 4 bit quantities abcd and efgh and get table entry
 *	graphtab[abcd][efgh]
 * to display in that character position.
 *
 * General philosophies: the dh bits are intended for descenders where
 * possible.  Characters with radically different appearance on different
 * terminals (e.g. _ and ^) are avoided.
 *
 * Version 1.0, March 1981, Mark Horton.
 */

char tab1[4] = {
	' ', ',', '\'', '|'
};

char graphtab[16][16] = {
' ', '.', '.', ',', '.', ';', ':', 'j', '\'', ':', ':', ';', '\'', ';', '!', '|',
'.', '.', ':', ',', ';', ';', ';', 'j', '/', ';', ';', ';', 'j', 'j', 'j', 'j',
'.', ',', '~', ',', 'r', '<', 'j', 'q', '/', ';', 'I', ';', '/', '|', 'I', '|',
',', ',', 'r', 'x', '/', '/', '/', 'd', '/', '/', '/', 'd', '/', '/', '/', 'd',
'.', ':', '\\', ';', '-', '=', 'v', 'q', '\'', ':', '<', '|', '\'', ':', '+', '+',
';', ';', '>', ';', '=', '=', 'g', 'g', '\'', ':', 'S', 'S', '/', '/', '/', '+',
':', '\\', '\\', '\\', 'r', '<', 'w', 'q', '/', '<', '6', '4', '/', '/', 'd', '+',
'l', 'L', '+', 'b', 'y', '[', 'p', 'g', '/', '<', '/', '6', '/', '/', '/', '+',
'`', ':', ':', ';', '`', '\\', '\\', '\\', '"', ':', ':', ';', '`', '\\', 'Y', 'T',
';', ';', ';', ';', '`', '2', '>', '\\', ':', '=', ';', ';', '?', '?', ']', ']',
':', ';', ';', ';', '>', '2', '>', '\\', 'F', ';', 'O', ';', '7', '?', ']', '7',
';', ';', ';', ';', '?', '2', '>', 'b', ';', ';', ';', ';', '?', '?', ']', '#',
'\'', '\\', '\\', '\\', '`', '\\', '\\', '\\', '\'', '\'', '<', '5', '"', '"', 'v', 'q',
';', '\\', '\\', '\\', '`', '=', '\\', '\\', '\'', '\'', '5', '5', '"', '?', 'g', 'g',
'I', 'L', 'L', 'L', 'D', '\\', 'b', 'f', 'F', '[', '[', '[', 'P', '?', '#', 'M',
'|', '|', '|', '|', '|', '#', '+', '#', 'T', '[', 'F', 'F', 'P', '?', 'P', 'M'
};


shozoom()
{
	register i;

	if (zoom == 0) 
		sho0();
	else if (zoom == 1)
		sho1();
	else if (zoom == 2)
		sho2();
}

sho0()
{
	register k,l;

	for (k=0; k<H; k++) {
		for (l=0; l<W; l++)
			printf("%s", fbit(k,l)?"[]": "  ");
		printf("\n");
	}
	printf("\n");
}

sho1()
{
	register i,k,l;

	k = 0;
	while (k < H) {
		for(l=0;l<W;l++) {
			i = fbit(k,l)*2 + fbit(k+1,l);
			printf("%c",tab1[i]);
D 6
			l++;
E 6
		}
		printf("\n");
		k += 2;
	}
	printf("\n");
}

sho2()
{
	register i,j,k,l;
I 4
	int line = curline + (base+3)/4;
	int col;
E 4

D 4
	k = 0;
E 4
I 4
	k = base%4;
	if (k > 0) k -= 4;
E 4
	while (k < H) {
		l = 0;
I 4
		col = curcol;
E 4
		while (l<W) {
			i = fbit(k,l)*8 + fbit(k+1,l)*4 + 
			    fbit(k+2,l)*2 + fbit(k+3,l);
			l++;
			j = fbit(k,l)*8 + fbit(k+1,l)*4 + 
			    fbit(k+2,l)*2 + fbit(k+3,l);

D 4
			printf("%c",graphtab[i][j]);
E 4
I 4
			if (msgflag) {
				if (graphtab[i][j] != ' ') {
					if (line > maxline) maxline = line;
					if (line < minline) minline = line;
					if (col > maxcol)   maxcol  = col;
				}
				msgout[line][col] = graphtab[i][j];
			} else
				printf("%c",graphtab[i][j]);
E 4
			l++;
I 4
			col++;
E 4
		}
D 4
		printf("\n");
E 4
I 4
		if (msgflag == 0)
			printf("\n");
E 4
		k += 4;
I 4
		line--;
E 4
	}
D 4
	printf("\n");
E 4
I 4
	if (msgflag == 0)
		printf("\n");
E 4
E 3
}
E 1
