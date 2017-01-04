h12500
s 00001/00000/00146
d D 5.2 04/09/16 23:27:00 msokolov 2 1
c added %%Creator: DSC comment
e
s 00146/00000/00000
d D 5.1 04/09/14 09:44:39 msokolov 1 0
c date and time created 04/09/14 09:44:39 by msokolov
e
u
U
t
T
I 1
/*
 * This program turns a Varian/Versatec bitmap font into a PostScript Type 3
 * font that draws the character images with imagemask.
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/param.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <stdio.h>
#include <strings.h>
#include <vfont.h>

char vfontbuf[65536];
struct header *header;
struct dispatch *dispatch;
char *imagestart;
int ptsize;
char *psfontname;

main(argc, argv)
	char **argv;
{
	register int i;
	register struct dispatch *d;

	if (argc != 4) {
		fprintf(stderr, "usage: %s vfont ptsize psfontname\n", argv[0]);
		exit(1);
	}
	read_vfont(argv[1]);
	header = (struct header *)vfontbuf;
	if (header->magic != 0436) {
		fprintf(stderr, "%s is not a valid vfont file\n", argv[1]);
		exit(1);
	}
	dispatch = (struct dispatch *)(header + 1);
	imagestart = (char *)(dispatch + 256);
	ptsize = atoi(argv[2]);
	psfontname = argv[3];

	puts("%!PS-Adobe-3.0 Resource-Font");
I 2
	puts("%%Creator: vfont2ps converter");
E 2
	puts("%%DocumentNeededResources: encoding cHexEncoding");
	printf("%%%%BeginResource: font %s\n", psfontname);
	puts("13 dict begin");
	printf("/FontName /%s def\n", psfontname);
	puts("/FontType 3 def");
	printf("/scalefactor 72 200 %d mul div def\n", ptsize);
	puts("/FontMatrix [scalefactor 0 0 scalefactor 0 0] readonly def");
	puts("/FontBBox [0 0 0 0] readonly def");
	puts("/Encoding cHexEncoding def");
	puts("256 dict begin");
	for (i = 0; i < 256; i++) {
		d = &dispatch[i];
		if (d->nbytes)
			printf("\t/c%02X [%d 0 %d %d %d %d] readonly def\n", i,
				d->width, -d->left, -d->down, d->right, d->up);
	}
	puts("\tcurrentdict");
	puts("end");
	puts("readonly /CharMetrics exch def");
	puts("/RD {string currentfile exch readhexstring pop} bind def");
	puts("256 dict begin");
	for (i = 0; i < 256; i++) {
		d = &dispatch[i];
		if (d->nbytes) {
			printf("/c%02X %d RD\n", i, d->nbytes);
			emit_char_image(d);
			puts("readonly def");
		}
	}
	puts("currentdict end");
	puts("readonly /CharImages exch def");
	emit_buildchar();
	puts("FontName currentdict end");
	puts("definefont pop");
	puts("%%EndResource");
	return(0);
}

read_vfont(filename)
	char *filename;
{
	register int fd;
	struct stat st;

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		perror(filename);
		exit(1);
	}
	fstat(fd, &st);
	if ((st.st_mode & S_IFMT) != S_IFREG) {
		fprintf(stderr, "%s is not a regular file\n", filename);
		exit(1);
	}
	if (st.st_size > 65536) {
		fprintf(stderr, "%s is longer than 65536 bytes\n", filename);
		exit(1);
	}
	read(fd, vfontbuf, st.st_size);
	close(fd);
}

emit_char_image(d)
	register struct dispatch *d;
{
	register int w, x, y, c = 0;
	register char *cp;

	w = (d->left + d->right + 7) >> 3;
	for (y = d->up + d->down - 1; y >= 0; y--) {
		cp = imagestart + d->addr + w * y;
		for (x = 0; x < w; x++) {
			printf("%02X", *cp++ & 0xFF);
			if (++c >= 35) {
				putchar('\n');
				c = 0;
			}
		}
	}
	if (c)
		putchar('\n');
}

emit_buildchar()
{
	register FILE *f;
	static char filename[] = "/usr/lib/vfont2ps.buildchar";
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
E 1
