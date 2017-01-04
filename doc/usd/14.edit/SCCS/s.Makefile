h45512
s 00009/00011/00023
d D 6.2 04/10/23 08:46:22 msokolov 2 1
c ditroff => pstroff
c also edittut.ms is already tbl'ed!
e
s 00034/00000/00000
d D 6.1 86/05/27 20:21:38 mckusick 1 0
c date and time created 86/05/27 20:21:38 by mckusick
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
SRCS=	edittut.ms
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
paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
E 2
I 2
all:	paper.ps
E 2

D 2
paper.${PRINTER}: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
paper.ps: ${SRCS}
	${TROFF} ${MACROS} ${SRCS} > $@
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

# index for versatec is different from the one in edit.tut
# because the fonts are different and entries reference page
# rather than section numbers.  if you have a typesetter
# you should just use the index in edit.tut, and ignore editvindex.

D 2
editvindex:
	${TROFF} ${MACROS} -n22 edit.vindex
E 2
I 2
#editvindex:
#	${TROFF} ${MACROS} -n22 edit.vindex
E 2
E 1
