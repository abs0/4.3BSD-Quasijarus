# Makefile for the 5lig fonts
#
#	@(#)Makefile	1.5	(Berkeley)	2012/03/06

FONTDIR=/usr/lib/pstroff/specialfonts
PSTDIR=	/usr/lib/pstroff
FONTS=	r.ps i.ps b.ps
FTS=	ftLr ftLi ftLb

all:	${FONTS} ${FTS}

.SUFFIXES:	.ps .asm

.asm.ps:
	t1csasm $*.asm $@

# Since we already have AFM files for these critters, let's
# continue using them as sources for the generation of ftL[rib].
# grokafm can exec mkfont automatically behind the scenes,
# but we want to use ../grokafm and ../mkfont which we've just
# built, not depending on installed versions, so that makes the
# incantations slightly more cumbersome.

ftLr:	r.afm
	../grokafm r.afm | ../mkfont - $@

ftLi:	i.afm
	../grokafm i.afm | ../mkfont - $@

ftLb:	b.afm
	../grokafm b.afm | ../mkfont - $@

install:
	if [ ! -d ${DESTDIR}${FONTDIR} ]; then mkdir ${DESTDIR}${FONTDIR}; \
		else true; fi
	install -o bin -g bin -m 444 r.ps \
		${DESTDIR}${FONTDIR}/Troff5lig-Regular.ps
	install -o bin -g bin -m 444 i.ps \
		${DESTDIR}${FONTDIR}/Troff5lig-Italic.ps
	install -o bin -g bin -m 444 b.ps \
		${DESTDIR}${FONTDIR}/Troff5lig-Bold.ps
	install -o bin -g bin -m 444 ${FTS} ${DESTDIR}${PSTDIR}

clean:
	rm -f [rib].ps ftL[rib]

depend:
