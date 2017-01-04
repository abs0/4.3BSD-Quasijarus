h51296
s 00008/00006/00069
d D 6.2 86/04/28 17:36:40 mckusick 4 3
c generalize and make -Pdp the default
e
s 00015/00015/00060
d D 6.1 86/04/23 23:56:54 mckusick 3 2
c document distributed with 4.3BSD
e
s 00006/00005/00069
d D 5.1 86/04/23 23:54:57 mckusick 2 1
c document distributed with 4.2BSD
e
s 00074/00000/00000
d D 4.1 86/04/23 23:53:38 mckusick 1 0
c document distributed with 4.1BSD
e
u
U
t
T
I 1
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
#	makefile for screen package documentation
#
NROFF=	nroff
D 3
TROFF=	vtroff
E 3
I 3
TROFF=	ditroff
I 4
TBL=	dtbl -Pdp
E 4
E 3
D 2
#	VFONT=	vfontedpr
E 2
I 2
VFONT=	/usr/lib/vfontedpr
E 2
NFLAGS=	-Tcrt
D 3
TFLAGS=
E 3
I 3
TFLAGS= -Pdp
E 3
CFLAGS=	-O -n -s
D 3
BINDIR=	/usr/doc/curses
TARFILE=cf curdoc.tar
E 3
I 3
BINDIR=	/usr/doc/ps1/18.curses
E 3

DOCS=	doc.I doc.II doc.III doc.IV
D 3
RAW=	macros c_macros appen.B appen.A appen.C disclaim intro.0 intro.1 \
	intro.2 intro.3 intro.4 intro.5 ${DOCS} curses.3
E 3
I 3
RAW=	macros c_macros appen.B appen.A appen.C intro.0 intro.1 \
	intro.2 intro.3 intro.4 intro.5 ${DOCS} curses.3x
E 3

CRAW=	win_st.c twinkle1.c twinkle2.c life.c
CSOURCE=win_st.gr twinkle1.gr twinkle2.gr life.gr
D 3
SOURCE=	macros appen.A.tbl appen.B appen.C disclaim intro.0 intro.1 \
E 3
I 3
SOURCE=	macros appen.A.tbl appen.B appen.C intro.0 intro.1 \
E 3
	intro.2.tbl intro.3 intro.4 intro.5

D 2
.SUFFIXES:
.SUFFIXES: .c .gr
E 2
I 2
D 3
#.SUFFIXES:
#.SUFFIXES: .c .gr
E 3
I 3
.SUFFIXES:
.SUFFIXES: .c .gr
E 3
E 2

#
# this section formats C input source into nice troffable (or nroffable)
# versions.  It uses the capabilites of "vgrind", which sets keywords in
# bold font, and comments in italics.
#

D 4
Curses.doc: ${VFONT} Master macros ${SOURCE}
	${NROFF} -me ${NFLAGS} Master > Curses.doc

E 4
D 2
.c.gr:
	${VFONT} $*.c > $*.gr
E 2
I 2
# Don't re-run vgrind unless you want to patch the output files.
D 3
#.c.gr:
#	${VFONT} $*.c > $*.gr
E 3
I 3
.c.gr:
	${VFONT} $*.c | grep -v "^'wh" > $*.gr
E 3
E 2

D 3
${CSOURCE}: ${VFONT}
E 3
troff: Master macros ${SOURCE}
	${TROFF} -me ${TFLAGS} Master ;

I 4
Curses.doc: ${VFONT} Master macros ${SOURCE}
	${NROFF} -me ${NFLAGS} Master > Curses.doc

E 4
I 3
${CSOURCE}: ${VFONT}

E 3
intro.5: ${DOCS}
appen.B: win_st.gr
appen.C: twinkle1.gr life.gr twinkle2.gr

intro.2.tbl: intro.2
D 4
	tbl intro.2 > intro.2.tbl
E 4
I 4
	${TBL} intro.2 > intro.2.tbl
E 4

appen.A.tbl: appen.A
D 4
	tbl appen.A > appen.A.tbl
E 4
I 4
	${TBL} appen.A > appen.A.tbl
E 4

vfontedpr: vfontedpr.c
	${CC} ${CFLAGS} -o vfontedpr vfontedpr.c

spell: ${SOURCE}
	/bin/csh ./Spellit ${SOURCE} ${DOCS}

install:
	cp Makefile ${RAW} ${BINDIR}

D 3
tar:
	tar rv${TARFILE} Master ${RAW} ${CRAW} Makefile vfontedpr.c
E 3
I 3
ar:
	ar crv curdoc.ar Master ${RAW} ${CRAW} Makefile
E 3

lpr: Curses
	-lpr Curses ; lpq
	-lpq

clean:
D 3
	rm -f ${CSOURCE} appen.A.tbl intro.2.tbl curses.tar vfontedpr
E 3
I 3
D 4
	rm -f ${CSOURCE} appen.A.tbl intro.2.tbl curses.tar vfontedpr Curses.doc
E 4
I 4
	rm -f ${CSOURCE} appen.A.tbl intro.2.tbl curses.tar vfontedpr \
		Curses.doc errs Errs
E 4
E 3
E 1
