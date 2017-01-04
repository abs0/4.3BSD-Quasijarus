h60641
s 00005/00002/00479
d D 4.3 83/08/11 20:56:52 sam 4 3
c standardize sccs keyword lines
e
s 00027/00114/00454
d D 4.2 83/03/24 09:29:45 ralph 3 2
c Fixed vplot to versatec.
e
s 00378/00186/00190
d D 4.1 83/03/10 15:30:22 ralph 2 1
c uses remote spooling line printer and plain raster files.
e
s 00376/00000/00000
d D 1.1 83/03/10 15:25:08 ralph 1 0
c date and time created 83/03/10 15:25:08 by ralph
e
u
U
t
T
I 1
D 2
/*
 * Reads standard graphics input
 * Makes a plot on a 200 dot-per-inch 11" wide
 * Versatek plotter.
E 2
I 2
D 4
/*  VPLOT: version %I%				updated %G%
E 2
 *
E 4
I 4
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

/*
E 4
D 2
 * Creates and leaves /usr/tmp/raster (1000 blocks)
 * which is the bitmap
E 2
I 2
 *  Reads standard graphics input and produces a plot on the
 *  Varian or Versatec
D 3
 *  -- creates in /usr/tmp a raster file of 500 1K-blocks.
E 3
E 2
 */
D 2
#include "stdio.h"
E 2
I 2
#include <stdio.h>
E 2
#include <signal.h>
I 2
#include <vfont.h>
E 2

D 2
#define	NB	88
#define BSIZ	512
#define	mapx(x)	((1536*((x)-botx)/del)+centx)
#define	mapy(y)	((1536*(del-(y)+boty)/del)-centy)
E 2
I 2
#define LPR "/usr/ucb/lpr"
D 3
#define VAX		/* Machine Flag (don't simulate VM on vax) */
E 3

D 3
#ifdef VAX
#define NB	1024		/* Number of blocks in virtual memory */
#else
#define	NB	88		/* Number of blocks kept in memory */
#endif
#define BSIZ	512		/* Size of blocks */
#define LOGBSIZ	9		/* log base 2 of BSIZ */

E 3
#define	mapx(x)	((DevRange*((x)-botx)/del)+centx)
#define	mapy(y)	((DevRange*(del-(y)+boty)/del)-centy)
E 2
#define SOLID -1
#define DOTTED 014
#define SHORTDASHED 034
#define DOTDASHED 054
#define LONGDASHED 074
D 2
#define	SETSTATE	(('v'<<8)+1)
E 2

I 2
char *Sid = "%Z%\t%G%";

E 2
int	linmod	= SOLID;
D 2
int	again;
E 2
int	done1;
char	chrtab[][16];
D 2
int	plotcom[]	= { 0200, 0, 0};
int	eotcom[]		= { 0210, 0, 0};
char	blocks	[NB][BSIZ];
int	obuf[264];
E 2
I 2
D 3
char	blocks[NB][BSIZ];
E 3
I 3
char	*obuf;
int	bufsize;
E 3
E 2
int	lastx;
int	lasty;
D 2
double	topx	= 1536;
double	topy	= 1536;
double	botx	= 0;
double	boty	= 0;
int	centx;
int	centy;
double	delx	= 1536;
double	dely	= 1536;
double	del	= 1536;
E 2
I 2
int	radius, startx, starty, endx, endy;
double	topx;
double	topy;
double	botx;
double	boty;
int	centx = 0;
int	centy = 0;
double	delx;
double	dely;
double	del;
E 2

I 2
int	warned = 0;	/* Indicates whether the warning message about
			 * unimplemented routines has been printed */

D 3
#ifdef VAX
char	dirty[NB];		/* marks if a block has been written into */
#else
E 2
struct	buf {
	int	bno;
	char	*block;
D 2
};
struct	buf	bufs[NB];
E 2
I 2
} bufs[NB];
#endif
E 2

E 3
D 2
int	in, out;
char *picture = "/usr/tmp/raster";
E 2
I 2
FILE	*infile;
D 3
int	fd;
E 3
I 3
FILE	*pfp;			/* output file */
E 3
char	picture[] = "/usr/tmp/rastAXXXXXX";
int	run = 13;		/* index of 'a' in picture[] */
int	DevRange = 1536;	/* output array size (square) in pixels */
I 3
int	DevRange8 = 1536/8;	/* output array size in bytes */
E 3
int	BytesPerLine = 264;	/* Bytes per raster line (physical) */
int	lparg = 7;		/* index into lpargs */
E 2

I 2
char	*lpargs[50] = { "lpr", "-Pvarian", "-v", "-s", "-r", "-J", "vplot" };

/* variables for used to print from font file */
int	fontSet = 0;		/* Has the font file been read */
struct	header header;
struct	dispatch dispatch[256];
char	*bits;
char	*fontFile = "/usr/lib/vfont/R.6";

E 2
main(argc, argv)
I 2
int argc;
E 2
char **argv;
{
D 2
	extern int onintr();
	register i;
E 2
I 2
	extern int cleanup();
D 3
	extern char *malloc();
	register i, j;
	register char *arg;
E 3
I 3
	register char *cp1, *arg;
	register i;
E 3
	int again;
E 2

D 2
	if (argc>1) {
		in = open(argv[1], 0);
		putpict();
		exit(0);
E 2
I 2
	infile = stdin;
	while (argc > 1 && argv[1][0] == '-') {
		argc--;
		arg = *++argv;
		switch (*++arg) {
		case 'W':
D 3
			DevRange = 2047;
E 3
I 3
			DevRange = 2048;
			DevRange8 = 2048/8;
E 3
			BytesPerLine = 880;
			lpargs[1] = "-Pversatec";
			break;
		case 'V':
			DevRange = 1536;
I 3
			DevRange8 = 1536/8;
E 3
			BytesPerLine = 264;
			lpargs[1] = "-Pvarian";
			break;
		case 'b':
			if (argc-- > 1)
				lpargs[lparg-1] = *++argv;
			break;
		default:
			fprintf(stderr, "vplot: %s option unknown\n", *argv);
			break;
		}
E 2
	}
D 2
	signal(SIGTERM, onintr);
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, onintr);
another:
	for (i=0; i<NB; i++) {
		bufs[i].bno = -1;
		bufs[i].block = blocks[i];
	}
	out = creat(picture, 0666);
	in = open(picture, 0);
	zseek(out, 32*32);
	write(out, blocks[0], BSIZ);
/*delete following code when filsys deals properly with
holes in files*/
	for(i=0;i<512;i++)
		blocks[0][i] = 0;
	zseek(out, 0);
	for(i=0;i<32*32;i++)
		write(out,blocks[0],512);
/**/
	getpict();
	for (i=0; i<NB; i++)
		if (bufs[i].bno != -1) {
			zseek(out, bufs[i].bno);
			write(out, bufs[i].block, BSIZ);
E 2
I 2
	if (argc > 1) {
		if ((infile = fopen(*++argv, "r")) == NULL) {
			perror(*argv);
			cleanup();
E 2
		}
D 2
	putpict();
	if (again) {
		close(in);
		close(out);
		goto another;
E 2
	}
D 2
	exit(0);
E 2
I 2

	/* init constants for scaling */
	topx = topy = DevRange;
	botx = boty = 0;
	delx = dely = del = DevRange;
	centx = (DevRange - mapx(topx))/2;
	centy = mapy(topy)/2;
	signal(SIGTERM, cleanup);
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, cleanup);
	mktemp(picture);
I 3
	if ((obuf = (char *) malloc(bufsize = DevRange * DevRange8)) == NULL) {
		fprintf(stderr, "vplot: ran out of memory\n");
		cleanup();
	}
E 3
	do {
D 3
		if ((fd = creat(picture, 0666)) < 0) {
			fprintf(stderr, "can't create %s\n", picture);
E 3
I 3
		if ((pfp = fopen(picture, "w")) == NULL) {
			fprintf(stderr, "vplot: can't create %s\n", picture);
E 3
			cleanup();
		}
D 3
#ifndef VAX
		close(fd);
		if ((fd = open(picture, 2)) < 0) {
			fprintf(stderr, "can't reopen %s\n", picture);
			cleanup();
		}
#endif
E 3
		i = strlen(picture) + 1;
D 3
		if ((arg = malloc(i)) == NULL) {
E 3
I 3
		if ((arg = (char *) malloc(i)) == NULL) {
E 3
			fprintf(stderr, "ran out of memory\n");
			cleanup();
		}
		strcpy(arg, picture);
		lpargs[lparg++] = arg;
		picture[run]++;
D 3
		for (i=0; i<NB; i++) {
#ifdef VAX
			dirty[i] = 0;
			for (j=0; j<BSIZ; ++j)
				blocks[i][j] = 0;
#else
			bufs[i].bno = -1;
			bufs[i.block = blocks[i];
#endif
		}
#ifdef NOHOLES
		/* clear the entire file */
		for (i=0; i<BSIZ; i++)
			blocks[0][i] = '\0';
		for (i=0; i<1024; i++)
			write(fd, blocks[0], BSIZ);
#endif
E 3
I 3
		arg = &obuf[bufsize];
		for (cp1 = obuf; cp1 < arg; )
			*cp1++ = 0;
E 3

		again = getpict();

D 3
		for (i=0; i<NB; i++) {
#ifdef VAX
			if (dirty[i]) {		/* write out non-zero blocks */
				zseek(fd, i);
				write(fd, blocks[i], BSIZ);
			}
#else
			if (bufs[i].bno != -1) {
				zseek(fd, bufs[i].bno);
				write(fd, bufs[i].blocks[i], BSIZ);
			}
#endif
E 3
I 3
		for (cp1 = obuf; cp1 < arg; cp1 += DevRange8) {
			fwrite(cp1, sizeof(char), DevRange8, pfp);
			fseek(pfp, (long) BytesPerLine - DevRange8, 1);
E 3
		}
D 3
		close(fd);
E 3
I 3
		fclose(pfp);
E 3
	} while (again);
	lpargs[lparg] = 0;
	execv(LPR, lpargs);
	fprintf(stderr, "can't exec %s\n", LPR);
	cleanup();
E 2
}

getpict()
{
	register x1, y1;

D 2
	again = 0;
	for (;;) switch (x1 = getc(stdin)) {
E 2
I 2
	for (;;) switch (x1 = getc(infile)) {
E 2

I 2
	case '\n':
		continue;

E 2
	case 's':
D 2
		botx = getw(stdin);
		boty = getw(stdin);
		topx = getw(stdin);
		topy = getw(stdin);
E 2
I 2
		botx = getinteger(infile);
		boty = getinteger(infile);
		topx = getinteger(infile);
		topy = getinteger(infile);
E 2
		delx = topx-botx;
		dely = topy-boty;
		if (dely/delx > 1536./2048.)
			del = dely;
		else
D 2
			del = delx * (1566./2048.);
E 2
I 2
			del = delx;
E 2
		centx = 0;
D 2
		centx = (2048 - mapx(topx)) / 2;
E 2
I 2
		centx = (DevRange - mapx(topx))/2;
E 2
		centy = 0;
		centy = mapy(topy) / 2;
		continue;

I 2
	case 'b':
		x1 = getc(infile);
		continue;

E 2
	case 'l':
		done1 |= 01;
D 2
		x1 = mapx(getw(stdin));
		y1 = mapy(getw(stdin));
		lastx = mapx(getw(stdin));
		lasty = mapy(getw(stdin));
E 2
I 2
		x1 = mapx(getinteger(infile));
		y1 = mapy(getinteger(infile));
		lastx = mapx(getinteger(infile));
		lasty = mapy(getinteger(infile));
E 2
		line(x1, y1, lastx, lasty);
		continue;

I 2
	case 'c':
		x1 = mapx(getinteger(infile));
		y1 = mapy(getinteger(infile));
		radius = mapx(getinteger(infile));
		if (!warned) {
			fprintf(stderr,"Circles are Implemented\n");
			warned++;
		}
		circle(x1, y1, radius);
		continue;
		
	case 'a':
		x1 = mapx(getinteger(infile));
		y1 = mapy(getinteger(infile));
		startx = mapx(getinteger(infile));
		starty = mapy(getinteger(infile));
		endx = mapx(getinteger(infile));
		endy = mapy(getinteger(infile));
		if (!warned) {
			fprintf(stderr,"Circles and Arcs are unimplemented\n");
			warned++;
		}
		continue;

E 2
	case 'm':
D 2
		lastx = mapx(getw(stdin));
		lasty = mapy(getw(stdin));
E 2
I 2
		lastx = mapx(getinteger(infile));
		lasty = mapy(getinteger(infile));
E 2
		continue;

	case 't':
I 2
		lastx = lastx - 6;
		lasty = lasty + 6;
E 2
		done1 |= 01;
D 2
		while ((x1 = getc(stdin)) != '\n')
E 2
I 2
		while ((x1 = getc(infile)) != '\n')
E 2
			plotch(x1);
		continue;

	case 'e':
D 2
		if (done1) {
			again++;
			return;
		}
E 2
I 2
		if (done1)
			return(1);
E 2
		continue;

	case 'p':
		done1 |= 01;
D 2
		lastx = mapx(getw(stdin));
		lasty = mapy(getw(stdin));
E 2
I 2
		lastx = mapx(getinteger(infile));
		lasty = mapy(getinteger(infile));
E 2
		point(lastx, lasty);
		point(lastx+1, lasty);
		point(lastx, lasty+1);
		point(lastx+1, lasty+1);
		continue;

	case 'n':
		done1 |= 01;
D 2
		x1 = mapx(getw(stdin));
		y1 = mapy(getw(stdin));
E 2
I 2
		x1 = mapx(getinteger(infile));
		y1 = mapy(getinteger(infile));
E 2
		line(lastx, lasty, x1, y1);
		lastx = x1;
		lasty = y1;
		continue;

	case 'f':
D 2
		getw(stdin);
		getc(stdin);
		switch(getc(stdin)) {
E 2
I 2
		getinteger(infile);
		getc(infile);
		switch (getc(infile)) {
E 2
		case 't':
			linmod = DOTTED;
			break;
		default:
		case 'i':
			linmod = SOLID;
			break;
		case 'g':
			linmod = LONGDASHED;
			break;
		case 'r':
			linmod = SHORTDASHED;
			break;
		case 'd':
			linmod = DOTDASHED;
			break;
		}
D 2
		while((x1=getc(stdin))!='\n')
			if(x1==-1) return;
E 2
I 2
		while ((x1 = getc(infile)) != '\n')
			if (x1 == EOF)
				return(0);
E 2
		continue;

	case 'd':
D 2
		getw(stdin);
		getw(stdin);
		getw(stdin);
		x1 = getw(stdin);
E 2
I 2
		getinteger(infile);
		getinteger(infile);
		getinteger(infile);
		x1 = getinteger(infile);
E 2
		while (--x1 >= 0)
D 2
			getw(stdin);
E 2
I 2
			getinteger(infile);
E 2
		continue;

D 2
	case -1:
		return;
E 2
I 2
	case 0:		/* ignore null characters */
		continue;
E 2

I 2
	case 255:
	case EOF:
		return(0);

E 2
	default:
D 2
		printf("Botch\n");
		return;
E 2
I 2
		fprintf(stderr, "Input format error %c(%o)\n",x1,x1);
		cleanup();
E 2
	}
}

D 2
plotch(c)
register c;
E 2
I 2
plotch(ch)
char ch;
E 2
{
D 2
	register j;
	register char *cp;
	int i;
E 2
I 2
	register int i,j,k;
	register char *ptr,c;
	int nbytes;
E 2

D 2
	if (c<' ' || c >0177)
		return;
	cp = chrtab[c-' '];
	for (i = -16; i<16; i += 2) {
		c = *cp++;
		for (j=7; j>=0; --j)
			if ((c>>j)&1) {
				point(lastx+6-j*2, lasty+i);
				point(lastx+7-j*2, lasty+i);
				point(lastx+6-j*2, lasty+i+1);
				point(lastx+7-j*2, lasty+i+1);
			}
E 2
I 2
	if (!fontSet)
		InitFont();	/* Read font if not already read */

	ptr = bits + dispatch[ch].addr;

	for (i = dispatch[ch].up; i > -dispatch[ch].down; --i) {
		nbytes = (dispatch[ch].right + dispatch[ch].left + 7)/8;
		for (j = 0; j < nbytes; j++) {
			c = *ptr++;
			for (k = 7; k >= 0; k--)
				if ((c >> k) & 1)
					point(lastx+7-k+j*8-dispatch[ch].left, lasty-i);
		}
E 2
	}
D 2
	lastx += 16;
E 2
I 2
	if (ch != ' ')
		lastx += dispatch[ch].width;
	else
		lastx += dispatch['a'].width;
E 2
}

D 2
int	f; /* versatec file number */
putpict()
E 2
I 2
InitFont()
E 2
{
D 2
	register x, *ip, *op;
	int y;
E 2
I 2
	char *s;
	int fonts;
	int i;
E 2

D 2
	if (f==0){
		f = open("/dev/vp0", 1);
		if (f < 0) {
			printf("Cannot open vp\n");
			exit(1);
		}
		ioctl(f, SETSTATE, plotcom);
E 2
I 2
	fontSet = 1;
	/* Get the font file */
	s = fontFile;
	if ((fonts = open(s, 0)) == -1) {
		perror(s);
		fprintf(stderr, "Can't get font file");
		cleanup();
E 2
	}
D 2
	op = obuf;
	lseek(in, 0L, 0);
	for (y=0; y<2048; y++) {
		if ((y&077) == 0)
			read(in, blocks[0], 32*BSIZ);
		for (x=0; x<32; x++)  {
			ip = (int *)&blocks[x][(y&077)<<3];
			*op++ = *ip++;
			*op++ = *ip++;
			*op++ = *ip++;
			*op++ = *ip++;
		}
		*op++ = 0;
		*op++ = 0;
		*op++ = 0;
		*op++ = 0;
		if (y&1) {
			write(f, (char *)obuf, sizeof(obuf));
			op = obuf;
		}
E 2
I 2
	/* Get the header and check magic number */
	if (read(fonts, &header, sizeof(header)) != sizeof(header)) {
		perror(s);
		fprintf(stderr, "Bad read in font file");
		cleanup();
E 2
	}
I 2
	if (header.magic != 0436) {
		fprintf(stderr,"Bad magic numer in font file");
		cleanup();
	}
	/* Get dispatches */
	if (read(fonts, dispatch, sizeof(dispatch)) != sizeof(dispatch)) {
		perror(s);
		fprintf(stderr, "Bad read in font file");
		cleanup();
	}
	/* Allocate space for bit map and read in bits */
	bits = (char *) malloc(header.size);
	if (read(fonts, bits, header.size) != header.size) {
		perror(s);
		fprintf(stderr,"Can't read bit map in font file");
		cleanup();
	}
	/* Close font file */
	if (close(fonts) != 0) {
		perror(s);
		fprintf(stderr,"Can't close font file");
		cleanup();
	}
E 2
}

line(x0, y0, x1, y1)
register x0, y0;
{
	int dx, dy;
	int xinc, yinc;
	register res1;
	int res2;
	int slope;

	xinc = 1;
	yinc = 1;
	if ((dx = x1-x0) < 0) {
		xinc = -1;
		dx = -dx;
	}
	if ((dy = y1-y0) < 0) {
		yinc = -1;
		dy = -dy;
	}
	slope = xinc*yinc;
	res1 = 0;
	res2 = 0;
	if (dx >= dy) while (x0 != x1) {
D 2
	if((x0+slope*y0)&linmod)
	if (((x0>>6) + ((y0&~077)>>1)) == bufs[0].bno)
		bufs[0].block[((y0&077)<<3)+((x0>>3)&07)] |= 1 << (7-(x0&07));
	else
		point(x0, y0);
E 2
I 2
		if ((x0+slope*y0) & linmod)
			point(x0, y0);
E 2
		if (res1 > res2) {
			res2 += dx - res1;
			res1 = 0;
			y0 += yinc;
		}
		res1 += dy;
		x0 += xinc;
	} else while (y0 != y1) {
D 2
	if((x0+slope*y0)&linmod)
	if (((x0>>6) + ((y0&~077)>>1)) == bufs[0].bno)
		bufs[0].block[((y0&077)<<3)+((x0>>3)&07)] |= 1 << (7-(x0&07));
	else
E 2
I 2
		if ((x0+slope*y0) & linmod)
E 2
		point(x0, y0);
		if (res1 > res2) {
			res2 += dy - res1;
			res1 = 0;
			x0 += xinc;
		}
		res1 += dx;
		y0 += yinc;
	}
D 2
	if((x1+slope*y1)&linmod)
	if (((x1>>6) + ((y1&~077)>>1)) == bufs[0].bno)
		bufs[0].block[((y1&077)<<3)+((x1>>3)&07)] |= 1 << (7-(x1&07));
	else
E 2
I 2
	if ((x1+slope*y1) & linmod)
E 2
		point(x1, y1);
}

I 2
#define labs(a) (a >= 0 ? a : -a)

circle(x,y,c)
{
	register dx, dy;
	long ep;
	int de;

	dx = 0;
	ep = 0;
	for (dy=c; dy>=dx; dy--) {
		for (;;) {
			point(x+dx, y+dy);
			point(x-dx, y+dy);
			point(x+dx, y-dy);
			point(x-dx, y-dy);
			point(x+dy, y+dx);
			point(x-dy, y+dx);
			point(x+dy, y-dx);
			point(x-dy, y-dx);
			ep += 2*dx + 1;
			de = -2*dy + 1;
			dx++;
			if (labs(ep) >= labs(ep+de)) {
				ep += de;
				break;
			}
		}
	}
}

/*
 * Points should be in the range 0 <= x (or y) <= DevRange.
 * The origin is the top left-hand corner with increasing x towards the
 * right and increasing y going down.
 */
E 2
point(x, y)
D 2
register x, y;
E 2
I 2
register int x, y;
E 2
{
D 2
	register bno;
E 2
I 2
D 3
	register unsigned bno, byte;
E 3
I 3
	register unsigned byte;
E 3
E 2

D 2
	bno = ((x&03700)>>6) + ((y&03700)>>1);
	if (bno != bufs[0].bno) {
		if (bno < 0 || bno >= 1024)
			return;
E 2
I 2
D 3
	byte = y * BytesPerLine + (x >> 3);
	bno = byte >> LOGBSIZ;
	byte &= BSIZ - 1;
	if (bno >= 1024)
		return;
#ifndef VAX
	if (bno != bufs[0].bno)
E 2
		getblk(bno);
D 2
	}
	bufs[0].block[((y&077)<<3)+((x>>3)&07)] |= 1 << (7-(x&07));
E 2
I 2
	bufs[0].block[byte] |= 1 << (7 - (x & 07));
#else
	blocks[bno][byte] |= 1 << (7 - (x & 07));
	dirty[bno] = 1;
#endif
E 3
I 3
	byte = y * DevRange8 + (x >> 3);
	if (byte < bufsize)
		obuf[byte] |= 1 << (7 - (x & 07));
E 3
E 2
}

I 2
D 3
#ifndef VAX
E 2
getblk(b)
register b;
{
D 2
	register struct buf *bp1, *bp2;
E 2
I 2
	register struct buf *bp1;
E 2
	register char *tp;

loop:
	for (bp1 = bufs; bp1 < &bufs[NB]; bp1++) {
		if (bp1->bno == b || bp1->bno == -1) {
			tp = bp1->block;
D 2
			for (bp2 = bp1; bp2>bufs; --bp2) {
				bp2->bno = (bp2-1)->bno;
				bp2->block = (bp2-1)->block;
E 2
I 2
			while (bp1 > bufs) {
				bp1->bno = (bp1-1)->bno;
				bp1->block = (bp1-1)->block;
				bp1--;
E 2
			}
D 2
			bufs[0].bno = b;
			bufs[0].block = tp;
E 2
I 2
			bp1->bno = b;
			bp1->block = tp;
E 2
			return;
		}
	}
D 2
	zseek(out, bufs[NB-1].bno);
	write(out, bufs[NB-1].block, BSIZ);
	zseek(in, b);
	read(in, bufs[NB-1].block, BSIZ);
E 2
I 2
	zseek(fd, bufs[NB-1].bno);
	write(fd, bufs[NB-1].block, BSIZ);
	zseek(fd, b);
	read(fd, bufs[NB-1].block, BSIZ);
E 2
	bufs[NB-1].bno = b;
	goto loop;
}
I 2
#endif
E 2

E 3
D 2
onintr()
E 2
I 2
cleanup()
E 2
{
I 2
	while (picture[run] != 'a') {
		unlink(picture);
		picture[run]--;
	}
E 2
	exit(1);
D 3
}

zseek(a, b)
{
D 2
	return(lseek(a, (long)b*512, 0));
E 2
I 2
	return(lseek(a, (long)b*BSIZ, 0));
E 3
}

getinteger(f)
FILE *f;
{
	register int low, high, result;

	low = getc(f);
	high = getc(f);
	result = ((high << 8) | low);
	if (high > 127)
		result |= ~0xffff;
	return(result);
E 2
}
E 1
