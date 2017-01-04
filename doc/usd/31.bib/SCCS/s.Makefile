h12012
s 00007/00008/00018
d D 6.2 04/10/28 08:56:15 msokolov 2 1
c ditroff => pstroff
e
s 00026/00000/00000
d D 6.1 86/06/02 17:06:24 mckusick 1 0
c date and time created 86/06/02 17:06:24 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
SRCS=	bibdoc.ms
D 2
MACROS=	-msU
PRINTER=Pdp
E 2
I 2
MACROS=	-ms
E 2
BIB=	bib
D 2
TROFF=	ditroff -${PRINTER}
E 2
I 2
TBL=	tbl
TROFF=	pstroff
E 2

D 2
paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
E 2
I 2
all:	paper.ps
E 2

D 2
paper.${PRINTER}: ${SRCS}
	${BIB} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
paper.ps: ${SRCS}
	${BIB} ${SRCS} | ${TBL} | ${TROFF} ${MACROS} -t > $@
E 2

clean:
D 2
	rm -f paper.[PT]* *.spell errs Errs make.out
E 2
I 2
	rm -f *.ps *.spell errs Errs make.out
E 2

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
