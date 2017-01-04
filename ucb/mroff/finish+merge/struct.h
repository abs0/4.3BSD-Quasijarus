/*
 * Pstmerge is a program for merging PostScript documents produced by pstroff;
 * it also performs some important finishing functions.
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 *
 * This header file defines a few data structures used throughout pstmerge.
 *
 *	@(#)struct.h	5.2	(Berkeley)	2010/10/09
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
	char *supplying;
};

struct setupline {
	char *line;
	struct setupline *next;
};
