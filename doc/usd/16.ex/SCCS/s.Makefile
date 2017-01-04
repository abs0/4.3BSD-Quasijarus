h32930
s 00009/00012/00018
d D 6.2 04/10/23 23:58:01 msokolov 2 1
c ditroff => pstroff
e
s 00030/00000/00000
d D 6.1 86/05/30 18:44:56 mckusick 1 0
c date and time created 86/05/30 18:44:56 by mckusick
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
SRCS=	ex.rm
D 2
MACROS=	-msU
PRINTER=Pdp
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}
E 2
I 2
MACROS=	-ms
TBL=	tbl
TROFF=	pstroff
E 2

D 2
paper:	paper.${PRINTER} summary.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
	lpr -${PRINTER} -n summary.${PRINTER}
E 2
I 2
all:	paper.ps summary.ps
E 2

D 2
paper.${PRINTER}: ${SRCS}
	${TROFF} ${MACROS} -t ${SRCS} > paper.${PRINTER}
E 2
I 2
paper.ps: ${SRCS}
	${TROFF} ${MACROS} -t ${SRCS} > $@
E 2

D 2
summary.${PRINTER}: ex.summary
	${TBL} ex.summary | ${TROFF} ${MACROS} -t > summary.${PRINTER}
E 2
I 2
summary.ps: ex.summary
	${TBL} ex.summary | ${TROFF} ${MACROS} -t > $@
E 2

clean:
D 2
	rm -f paper.[PT]* summary.[PT]* *.spell errs Errs make.out
E 2
I 2
	rm -f *.ps summary.[PT]* *.spell errs Errs make.out
E 2

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
