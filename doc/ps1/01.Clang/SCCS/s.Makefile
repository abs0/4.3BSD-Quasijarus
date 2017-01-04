h13261
s 00007/00010/00017
d D 6.2 04/11/22 05:09:54 msokolov 2 1
c ditroff => pstroff
e
s 00027/00000/00000
d D 6.1 86/05/26 15:42:50 mckusick 1 0
c date and time created 86/05/26 15:42:50 by mckusick
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
SRCS=	Clang.ms
D 2
MACROS=	-msU
PRINTER=Pdp
EQN=	deqn -${PRINTER}
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
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > $@
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
