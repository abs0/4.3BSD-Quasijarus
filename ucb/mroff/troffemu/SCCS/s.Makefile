h21223
s 00010/00006/00048
d D 5.12 2012/07/23 07:38:41 msokolov 12 11
c SymbolBV/Sv => Special1/S1
e
s 00013/00007/00041
d D 5.11 2012/03/10 04:18:24 msokolov 11 10
c TroffEmu fonts restructured once again
e
s 00011/00019/00037
d D 5.10 2012/03/06 02:55:04 msokolov 10 9
c converted to the new font and charset model
e
s 00011/00012/00045
d D 5.9 10/10/07 01:57:48 msokolov 9 8
c yet another rethinking of the f[ws] file arrangement
e
s 00004/00004/00053
d D 5.8 10/10/06 06:53:05 msokolov 8 7
c s/BS/SS/
e
s 00018/00014/00039
d D 5.7 10/09/28 15:22:04 msokolov 7 6
c changes for the new handling of \(bs
e
s 00005/00001/00048
d D 5.6 10/08/23 01:34:45 msokolov 6 5
c fonts now go into /usr/lib/pstroff/specialfonts
e
s 00004/00000/00045
d D 5.5 04/11/05 05:52:24 msokolov 5 4
c symlink /usr/lib/pstroff/f[ws][RIBS]t to troffemu/f[ws][RIBS]
e
s 00009/00007/00036
d D 5.4 04/10/31 08:25:13 msokolov 4 3
c use a different font directory instead of different font names
e
s 00020/00002/00023
d D 5.3 04/10/31 05:37:30 msokolov 3 2
c pstroff files are here
e
s 00007/00001/00018
d D 5.2 04/10/30 19:55:15 msokolov 2 1
c generate TroffEmu-Symbol.ps
e
s 00019/00000/00000
d D 5.1 04/10/30 09:15:19 msokolov 1 0
c works
e
u
U
t
T
I 1
# Makefile for the troffemu fonts
#
#	%W%	(Berkeley)	%E%

I 3
D 4
LIBDIR=	/usr/lib/pstroff
E 4
I 4
D 7
LIBDIR=	/usr/lib/pstroff/troffemu
E 7
I 7
LIBDIR=	/usr/lib/pstroff
TLIBDIR=/usr/lib/pstroff/troffemu
E 7
I 6
FONTDIR=/usr/lib/pstroff/specialfonts
E 6
E 4
E 3
D 2
FONTS=	TroffEmu-Times-Roman.ps TroffEmu-Times-Italic.ps TroffEmu-Times-Bold.ps
E 2
I 2
FONTS=	TroffEmu-Times-Roman.ps TroffEmu-Times-Italic.ps \
D 11
	TroffEmu-Times-Bold.ps TroffEmu-Symbol.ps
I 3
D 4
WIDTHS=	fwRt fwIt fwBt fwSt
SETUPS=	fsRt fsIt fsBt fsSt
E 4
I 4
D 7
WIDTHS=	fwR fwI fwB fwS
SETUPS=	fsR fsI fsB fsS
E 7
I 7
D 8
CFONTS=	TroffEmu-BellSystem.ps
WIDTHS=	fwBS
SETUPS=	fsBS
E 8
I 8
CFONTS=	TroffEmu-SuperSpecial.ps
D 9
WIDTHS=	fwSS
SETUPS=	fsSS
E 8
TWIDTHS=fwR fwI fwB fwS
TSETUPS=fsR fsI fsB fsS
E 9
I 9
D 10
WIDTHS=	fwR fwI fwB fwS fwSS
SETUPS=	fsR fsI fsB fsS fsSS
E 10
I 10
FTS=	ftR ftI ftB ftSS
E 11
I 11
D 12
	TroffEmu-Times-Bold.ps TroffEmu-Symbol.ps TroffEmu-SymbolBV.ps
E 12
I 12
	TroffEmu-Times-Bold.ps TroffEmu-Symbol.ps TroffEmu-Special1.ps
E 12
CFONTS=	TroffEmu-Supplement.ps
SYMSRC=	symbol.m4 symbolchars.m4 symbolsubrs.m4 symbol.pscode bellsystem.m4
D 12
FTS=	ftR ftI ftB ftS ftSv ftSS
E 12
I 12
S1SRC=	special1.m4 boldvertical.m4 troff~=.m4
TFTS=	ftR ftI ftB ftS
RFTS=	ftS1 ftSS
FTS=	${TFTS} ${RFTS}
E 12
E 11
E 10
E 9
E 7
E 4
E 3
E 2

D 3
all:	${FONTS}
E 3
I 3
D 7
all:	${FONTS} ${WIDTHS}
E 7
I 7
D 9
all:	${FONTS} ${WIDTHS} ${TWIDTHS}
E 9
I 9
D 10
all:	${FONTS} ${WIDTHS}
E 10
I 10
all:	${FONTS} ${FTS}
E 10
E 9
E 7
E 3

TroffEmu-Times-Roman.ps:	troffemu.m4 roman.m4 romanmetrics.m4
	m4 roman.m4 troffemu.m4 > $@

TroffEmu-Times-Italic.ps:	troffemu.m4 italic.m4 italicmetrics.m4
	m4 italic.m4 troffemu.m4 > $@

TroffEmu-Times-Bold.ps:	troffemu.m4 bold.m4 boldmetrics.m4
	m4 bold.m4 troffemu.m4 > $@

I 2
D 11
TroffEmu-Symbol.ps:	TroffEmu-Symbol.asm
	t1csasm TroffEmu-Symbol.asm > $@
E 11
I 11
TroffEmu-Symbol.ps:	${SYMSRC}
	m4 symbol.m4 | t1csasm > $@
E 11

I 11
D 12
TroffEmu-SymbolBV.ps:	symbolbv.m4 boldvertical.m4
	m4 symbolbv.m4 | t1csasm > $@
E 12
I 12
TroffEmu-Special1.ps:	${S1SRC}
	m4 special1.m4 | t1csasm > $@
E 12

E 11
I 3
D 7
${WIDTHS}:
E 7
I 7
D 9
${WIDTHS} ${TWIDTHS}:
E 9
I 9
D 10
${WIDTHS}:
E 9
E 7
	cp $@.o a.out
	strip a.out
	dd if=a.out of=$@ bs=32 skip=1
	rm -f a.out
E 10
I 10
${FTS}:
	../mkfont $@
E 10

D 4
fwRt: fwRt.o
fwIt: fwIt.o
fwBt: fwBt.o
fwSt: fwSt.o
E 4
I 4
D 7
fwR: fwR.o
fwI: fwI.o
fwB: fwB.o
fwS: fwS.o
E 7
I 7
D 10
fwR:	fwR.o
fwI:	fwI.o
fwB:	fwB.o
fwS:	fwS.o
D 8
fwBS:	fwBS.o
E 8
I 8
fwSS:	fwSS.o
E 10
I 10
ftR:	ftR.src
ftI:	ftI.src
ftB:	ftB.src
I 11
ftS:	ftS.src
D 12
ftSv:	ftSv.src
E 12
I 12
ftS1:	ftS1.src
E 12
E 11
ftSS:	ftSS.src
E 10
E 8
E 7
E 4

install:
I 4
D 9
	if [ ! -d ${DESTDIR}${LIBDIR} ]; then mkdir ${DESTDIR}${LIBDIR}; \
E 9
I 9
	if [ ! -d ${DESTDIR}${TLIBDIR} ]; then mkdir ${DESTDIR}${TLIBDIR}; \
E 9
		else true; fi
E 4
D 6
	install -o bin -g bin -m 444 ${FONTS} ${WIDTHS} ${DESTDIR}${LIBDIR}
E 6
I 6
	if [ ! -d ${DESTDIR}${FONTDIR} ]; then mkdir ${DESTDIR}${FONTDIR}; \
		else true; fi
	install -o bin -g bin -m 444 ${FONTS} ${DESTDIR}${FONTDIR}
I 7
	install -c -o bin -g bin -m 444 ${CFONTS} ${DESTDIR}${FONTDIR}
E 7
D 9
	install -o bin -g bin -m 444 ${WIDTHS} ${DESTDIR}${LIBDIR}
E 6
	install -c -o bin -g bin -m 444 ${SETUPS} ${DESTDIR}${LIBDIR}
I 5
D 7
	cd ${DESTDIR}/usr/lib/pstroff; rm -f f[ws][RIBS]t; for i in ${WIDTHS} \
	${SETUPS}; \
		do ln -s troffemu/$$i $${i}t; \
	done
E 7
I 7
	install -o bin -g bin -m 444 ${TWIDTHS} ${DESTDIR}${TLIBDIR}
	install -c -o bin -g bin -m 444 ${TSETUPS} ${DESTDIR}${TLIBDIR}
E 9
I 9
D 10
	install -o bin -g bin -m 444 ${WIDTHS} ${DESTDIR}${TLIBDIR}
	install -c -o bin -g bin -m 444 ${SETUPS} ${DESTDIR}${TLIBDIR}
	cd ${DESTDIR}${LIBDIR}; rm -f f[ws]SS; for i in fwSS fsSS; \
		do ln -s troffemu/$$i $$i; \
	done
E 10
I 10
D 11
	install -o bin -g bin -m 444 ftR ftI ftB ${DESTDIR}${TLIBDIR}
	install -o bin -g bin -m 444 ftSS ${DESTDIR}${LIBDIR}
E 11
I 11
D 12
	install -o bin -g bin -m 444 ${FTS} ${DESTDIR}${TLIBDIR}
E 12
I 12
	install -o bin -g bin -m 444 ${TFTS} ${DESTDIR}${TLIBDIR}
	install -o bin -g bin -m 444 ${RFTS} ${DESTDIR}${LIBDIR}
E 12
	cd ${DESTDIR}${LIBDIR}; rm -f ftSt; ln -s troffemu/ftS ftSt
E 11
E 10
E 9
E 7
E 5

E 3
E 2
clean:
D 3
	rm -f *.ps
E 3
I 3
D 7
	rm -f *.o *.ps ${WIDTHS}
E 7
I 7
D 9
	rm -f *.o ${FONTS} ${WIDTHS} ${TWIDTHS}
E 9
I 9
D 10
	rm -f *.o ${FONTS} ${WIDTHS}
E 10
I 10
	rm -f ${FONTS} ${FTS}
E 10
E 9
E 7
E 3
I 2

depend:
E 2
E 1
