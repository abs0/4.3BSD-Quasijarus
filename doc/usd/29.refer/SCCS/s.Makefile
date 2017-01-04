h18618
s 00006/00008/00019
d D 6.2 04/10/24 02:22:52 msokolov 2 1
c ditroff => pstroff
e
s 00027/00000/00000
d D 6.1 86/06/02 16:34:39 mckusick 1 0
c date and time created 86/06/02 16:34:39 by mckusick
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
# refer.mac should be typed on a 12 pitch Daisy wheel printer
SRCS=	refer.bib
D 2
MACROS=	-msU
PRINTER=Pdp
E 2
I 2
MACROS=	-ms
E 2
REFER=	refer -p biblio
D 2
TROFF=	ditroff -${PRINTER}
E 2
I 2
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
	${REFER} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
paper.ps: ${SRCS}
	${REFER} ${SRCS} | ${TROFF} ${MACROS} -t > $@
E 2

clean:
D 2
	rm -f paper.[PT]* *.spell errs Errs make.out
E 2
I 2
	rm -f *.ps *.spell errs Errs make.out biblio.ig
E 2

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
