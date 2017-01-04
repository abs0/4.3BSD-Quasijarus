h07991
s 00006/00008/00017
d D 6.2 04/10/24 00:56:26 msokolov 2 1
c ditroff => pstroff
e
s 00025/00000/00000
d D 6.1 86/06/02 15:52:05 mckusick 1 0
c date and time created 86/06/02 15:52:05 by mckusick
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
SRCS=	ms.diffs
D 2
MACROS=	-msU
PRINTER=Pdp
TROFF=	ditroff -${PRINTER}
E 2
I 2
MACROS=	-ms
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
	${TROFF} ${MACROS} -t ${SRCS} > paper.${PRINTER}
E 2
I 2
paper.ps: ${SRCS}
	${TROFF} ${MACROS} -t ${SRCS} > $@
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
