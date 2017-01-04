h03629
s 00017/00011/00030
d D 1.5 2012/03/06 01:43:16 msokolov 5 4
c changeover from f[ws]XX to ftXX, preppsfont => grokafm & mkfont
e
s 00003/00003/00038
d D 1.4 10/08/23 19:06:46 msokolov 4 3
c use local preppsfont for ease of bootstrapping
e
s 00007/00006/00034
d D 1.3 10/08/23 01:34:21 msokolov 3 2
c fonts now go into /usr/lib/pstroff/specialfonts
e
s 00001/00001/00039
d D 1.2 10/08/22 23:56:44 msokolov 2 1
c header comment fix
e
s 00040/00000/00000
d D 1.1 10/08/22 23:55:24 msokolov 1 0
c date and time created 10/08/22 23:55:24 by msokolov
e
u
U
t
T
I 1
D 2
# Makefile for the troffemu fonts
E 2
I 2
# Makefile for the 5lig fonts
E 2
#
#	%W%	(Berkeley)	%E%

D 3
LIBDIR=	/usr/lib/pstroff/5lig
E 3
I 3
FONTDIR=/usr/lib/pstroff/specialfonts
PSTDIR=	/usr/lib/pstroff
E 3
FONTS=	r.ps i.ps b.ps
D 5
WIDTHS=	fwLr fwLi fwLb
SETUPS=	fsLr fsLi fsLb
E 5
I 5
FTS=	ftLr ftLi ftLb
E 5

D 5
all:	${FONTS} ${WIDTHS} ${SETUPS}
E 5
I 5
all:	${FONTS} ${FTS}
E 5

.SUFFIXES:	.ps .asm

.asm.ps:
	t1csasm $*.asm $@

D 5
fwLr fsLr:	r.afm
D 4
	preppsfont r.afm Lr
E 4
I 4
	../preppsfont r.afm Lr
E 5
I 5
# Since we already have AFM files for these critters, let's
# continue using them as sources for the generation of ftL[rib].
# grokafm can exec mkfont automatically behind the scenes,
# but we want to use ../grokafm and ../mkfont which we've just
# built, not depending on installed versions, so that makes the
# incantations slightly more cumbersome.
E 5
E 4

D 5
fwLi fsLi:	i.afm
D 4
	preppsfont i.afm Li
E 4
I 4
	../preppsfont i.afm Li
E 5
I 5
ftLr:	r.afm
	../grokafm r.afm | ../mkfont - $@
E 5
E 4

D 5
fwLb fsLb:	b.afm
D 4
	preppsfont b.afm Lb
E 4
I 4
	../preppsfont b.afm Lb
E 5
I 5
ftLi:	i.afm
	../grokafm i.afm | ../mkfont - $@
E 5
E 4

I 5
ftLb:	b.afm
	../grokafm b.afm | ../mkfont - $@

E 5
install:
D 3
	if [ ! -d ${DESTDIR}${LIBDIR} ]; then mkdir ${DESTDIR}${LIBDIR}; \
E 3
I 3
	if [ ! -d ${DESTDIR}${FONTDIR} ]; then mkdir ${DESTDIR}${FONTDIR}; \
E 3
		else true; fi
	install -o bin -g bin -m 444 r.ps \
D 3
		${DESTDIR}${LIBDIR}/Troff5lig-Regular.ps
E 3
I 3
		${DESTDIR}${FONTDIR}/Troff5lig-Regular.ps
E 3
	install -o bin -g bin -m 444 i.ps \
D 3
		${DESTDIR}${LIBDIR}/Troff5lig-Italic.ps
E 3
I 3
		${DESTDIR}${FONTDIR}/Troff5lig-Italic.ps
E 3
	install -o bin -g bin -m 444 b.ps \
D 3
		${DESTDIR}${LIBDIR}/Troff5lig-Bold.ps
	install -o bin -g bin -m 444 ${WIDTHS} ${SETUPS} ${DESTDIR}${LIBDIR}
E 3
I 3
		${DESTDIR}${FONTDIR}/Troff5lig-Bold.ps
D 5
	install -o bin -g bin -m 444 ${WIDTHS} ${SETUPS} ${DESTDIR}${PSTDIR}
E 5
I 5
	install -o bin -g bin -m 444 ${FTS} ${DESTDIR}${PSTDIR}
E 5
E 3

clean:
D 5
	rm -f [rib].ps f[ws]L[rib]
E 5
I 5
	rm -f [rib].ps ftL[rib]
E 5

depend:
E 1
