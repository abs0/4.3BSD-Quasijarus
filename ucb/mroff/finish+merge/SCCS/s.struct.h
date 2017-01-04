h01774
s 00001/00000/00030
d D 5.2 10/10/09 04:30:40 msokolov 2 1
c added -F option (font embedding)
e
s 00030/00000/00000
d D 5.1 10/10/08 06:51:50 msokolov 1 0
c pstmerge.c split into several modules
e
u
U
t
T
I 1
/*
 * Pstmerge is a program for merging PostScript documents produced by pstroff;
 * it also performs some important finishing functions.
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 *
 * This header file defines a few data structures used throughout pstmerge.
 *
 *	%W%	(Berkeley)	%E%
 */

struct srcdoc {
	char *filename;
	off_t bodyoffset;
	int lineno;
	int nfonts;
	u_char fontmap[32];
};

struct fontdesc {
	char *fontname;
	struct setupline *setup;
	int special;
I 2
	char *supplying;
E 2
};

struct setupline {
	char *line;
	struct setupline *next;
};
E 1
