h46944
s 00034/00000/00000
d D 1.1 2012/03/05 23:57:18 msokolov 1 0
c date and time created 2012/03/05 23:57:18 by msokolov
e
u
U
t
T
I 1
# Makefile for the standard font ftXX files
#
#	%W%	(Berkeley)	%E%

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
E 1
