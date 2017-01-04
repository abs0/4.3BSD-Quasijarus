# Makefile for the standard font ftXX files
#
#	@(#)Makefile	1.1	(Berkeley)	2012/03/05

PSTDIR=	/usr/lib/pstroff
FTS=	ftR ftI ftB ftBI ftH ftHO ftHB ftHQ ftC ftCO ftCB ftCQ ftS ftZD

all:	${FTS}

${FTS}:
	../mkfont $@

ftR:	ftR.src
ftI:	ftI.src
ftB:	ftB.src
ftBI:	ftBI.src
ftH:	ftH.src
ftHO:	ftHO.src
ftHB:	ftHB.src
ftHQ:	ftHQ.src
ftC:	ftC.src
ftCO:	ftCO.src
ftCB:	ftCB.src
ftCQ:	ftCQ.src
ftS:	ftS.src
ftZD:	ftZD.src

install:
	install -o bin -g bin -m 444 ${FTS} ${DESTDIR}${PSTDIR}

clean:
	rm -f ${FTS}

depend:
