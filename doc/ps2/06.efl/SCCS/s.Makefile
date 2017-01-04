h58900
s 00027/00000/00000
d D 6.1 86/04/29 11:57:26 cuccia 1 0
c date and time created 86/04/29 11:57:26 by cuccia
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
SRCS=	efl
MACROS=	-msU
PRINTER=Pdp
EQN=	deqn -${PRINTER}
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}

paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}

paper.${PRINTER}: ${SRCS}
	${TBL} ${SRCS} | ${EQN} | ${TROFF} ${MACROS} -t > paper.${PRINTER}

clean:
	rm -f paper.[PT]* *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
