# Makefile for the troffemu fonts
#
#	@(#)Makefile	5.12	(Berkeley)	2012/07/23

LIBDIR=	/usr/lib/pstroff
TLIBDIR=/usr/lib/pstroff/troffemu
FONTDIR=/usr/lib/pstroff/specialfonts
FONTS=	TroffEmu-Times-Roman.ps TroffEmu-Times-Italic.ps \
	TroffEmu-Times-Bold.ps TroffEmu-Symbol.ps TroffEmu-Special1.ps
CFONTS=	TroffEmu-Supplement.ps
SYMSRC=	symbol.m4 symbolchars.m4 symbolsubrs.m4 symbol.pscode bellsystem.m4
S1SRC=	special1.m4 boldvertical.m4 troff~=.m4
TFTS=	ftR ftI ftB ftS
RFTS=	ftS1 ftSS
FTS=	${TFTS} ${RFTS}

all:	${FONTS} ${FTS}

TroffEmu-Times-Roman.ps:	troffemu.m4 roman.m4 romanmetrics.m4
	m4 roman.m4 troffemu.m4 > $@

TroffEmu-Times-Italic.ps:	troffemu.m4 italic.m4 italicmetrics.m4
	m4 italic.m4 troffemu.m4 > $@

TroffEmu-Times-Bold.ps:	troffemu.m4 bold.m4 boldmetrics.m4
	m4 bold.m4 troffemu.m4 > $@

TroffEmu-Symbol.ps:	${SYMSRC}
	m4 symbol.m4 | t1csasm > $@

TroffEmu-Special1.ps:	${S1SRC}
	m4 special1.m4 | t1csasm > $@

${FTS}:
	../mkfont $@

ftR:	ftR.src
ftI:	ftI.src
ftB:	ftB.src
ftS:	ftS.src
ftS1:	ftS1.src
ftSS:	ftSS.src

install:
	if [ ! -d ${DESTDIR}${TLIBDIR} ]; then mkdir ${DESTDIR}${TLIBDIR}; \
		else true; fi
	if [ ! -d ${DESTDIR}${FONTDIR} ]; then mkdir ${DESTDIR}${FONTDIR}; \
		else true; fi
	install -o bin -g bin -m 444 ${FONTS} ${DESTDIR}${FONTDIR}
	install -c -o bin -g bin -m 444 ${CFONTS} ${DESTDIR}${FONTDIR}
	install -o bin -g bin -m 444 ${TFTS} ${DESTDIR}${TLIBDIR}
	install -o bin -g bin -m 444 ${RFTS} ${DESTDIR}${LIBDIR}
	cd ${DESTDIR}${LIBDIR}; rm -f ftSt; ln -s troffemu/ftS ftSt

clean:
	rm -f ${FONTS} ${FTS}

depend:
