h17037
s 00010/00007/00018
d D 6.2 04/11/18 01:53:58 msokolov 2 1
c format with pstroff and nroff8
e
s 00025/00000/00000
d D 6.1 86/04/20 17:45:07 mckusick 1 0
c date and time created 86/04/20 17:45:07 by mckusick
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
SRCS=	sccs.me
MACROS=	-me
D 2
PRINTER=Pdp
TROFF=	ditroff -${PRINTER}
E 2
I 2
TROFF=	pstroff
NROFF=	nroff8 -Tcol8
COL=	col8 -b
E 2

D 2
paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
E 2
I 2
all:	sccs.ps sccs.txt
E 2

D 2
paper.${PRINTER}: ${SRCS}
	${TROFF} ${MACROS} -t ${SRCS} > paper.${PRINTER}
E 2
I 2
sccs.ps: ${SRCS}
	${TROFF} ${MACROS} -t ${SRCS} > $@
E 2

I 2
sccs.txt: ${SRCS}
	${NROFF} ${MACROS} ${SRCS} | ${COL} > $@

E 2
clean:
D 2
	rm -f paper.${PRINTER} *.spell errs Errs make.out
E 2
I 2
	rm -f *.ps *.txt *.spell errs Errs make.out
E 2

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
