h31445
s 00002/00002/00024
d D 6.3 2012/02/19 05:50:38 msokolov 3 2
c labels for the thumb index
e
s 00006/00008/00020
d D 6.2 04/10/23 05:44:41 msokolov 2 1
c ditroff => pstroff
e
s 00028/00000/00000
d D 6.1 86/05/23 12:06:30 kjd 1 0
c date and time created 86/05/23 12:06:30 by kjd
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
D 3
#	%W% (Berkeley) %G%
E 3
I 3
#	%W% (Berkeley) %E%
E 3
#
SRCS=	mail0.nr mail1.nr mail2.nr mail3.nr mail4.nr mail5.nr mail6.nr \
	mail7.nr mail8.nr mail9.nr maila.nr

MACROS=	-me
D 2
PRINTER=Pdp
TBL=	dtbl -${PRINTER}
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
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
paper.ps: ${SRCS}
D 3
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > $@
E 3
I 3
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t | pstfinish -l USD:7-%l > $@
E 3
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
