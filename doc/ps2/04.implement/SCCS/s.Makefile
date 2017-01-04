h14055
s 00005/00002/00024
d D 6.2 86/06/17 20:02:56 mckusick 2 1
c add pic
e
s 00026/00000/00000
d D 6.1 86/04/29 11:47:55 cuccia 1 0
c date and time created 86/04/29 11:47:55 by cuccia
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
SRCS=	implement
I 2
PICFILES= fig1.pic fig2.pic
E 2
MACROS=	-ms
PRINTER=Pdp
TROFF=	ditroff -${PRINTER}
REFER=	refer -p /usr/old/dict/papers/Ind -e
I 2
PIC= pic -${PRINTER}
E 2

paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}

D 2
paper.${PRINTER}: ${SRCS}
	${REFER} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
paper.${PRINTER}: ${SRCS} ${PICFILES}
	soelim   ${SRCS} > paper.pic
	${REFER} paper.pic | ${PIC} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2

clean:
	rm -f paper.[PT]* *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
