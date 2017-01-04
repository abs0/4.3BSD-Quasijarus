h06127
s 00005/00007/00018
d D 6.2 05/08/25 02:37:38 msokolov 2 1
c ditroff => pstroff
e
s 00025/00000/00000
d D 6.1 86/05/23 18:31:31 mckusick 1 0
c first draft of document for 4.3BSD
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
SRCS=	timed.ms
MACROS=	-ms
D 2
PRINTER=Pdp
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
