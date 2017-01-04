h09988
s 00003/00002/00024
d D 6.2 86/04/25 01:34:14 cuccia 2 1
c added refer(1) to print references properly. --NHC
e
s 00026/00000/00000
d D 6.1 86/04/24 16:33:21 cuccia 1 0
c date and time created 86/04/24 16:33:21 by cuccia
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
SRCS=	p.mac p1 p2 p3 p4 p5 p6
MACROS=	-ms
PRINTER=Pdp
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}
I 2
REFER=	refer -p /usr/old/dict/papers/Ind -e
E 2

paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}

paper.${PRINTER}: ${SRCS}
D 2
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
	${REFER} ${SRCS} | ${TBL} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2

clean:
	rm -f paper.[PT]* *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
