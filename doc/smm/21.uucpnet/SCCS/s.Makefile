h60272
s 00027/00000/00000
d D 6.1 86/05/14 12:09:01 kjd 1 0
c date and time created 86/05/14 12:09:01 by kjd
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
SRCS=	network.ms
MACROS=	-ms
PRINTER=Pdp
REFER=	refer -p /usr/doc/run/Ind
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}

paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}

paper.${PRINTER}: ${SRCS}
	${REFER} -e ${SRCS} | ${TBL} | ${TROFF} ${MACROS} -t > paper.${PRINTER}

clean:
	rm -f paper.[PT]* *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
