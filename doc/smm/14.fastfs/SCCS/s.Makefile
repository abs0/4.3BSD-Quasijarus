h19796
s 00016/00010/00012
d D 5.2 86/05/20 16:36:40 kjd 2 1
c fixes for typesetting
e
s 00022/00000/00000
d D 5.1 86/05/14 16:52:39 kjd 1 0
c date and time created 86/05/14 16:52:39 by kjd
e
u
U
t
T
I 1
#
D 2
# Copyright (c) 1980 Regents of the University of California.
E 2
I 2
# Copyright (c) 1986 Regents of the University of California.
E 2
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
D 2
SRCS=	input.me
MACROS=	-me
E 2
I 2
SRCS=	0.t 1.t 2.t 3.t 4.t 5.t 6.t
MACROS=	-ms
E 2
PRINTER=Pdp
I 2
EQN=	deqn -${PRINTER}
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}
E 2

I 2
paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
E 2

I 2
paper.${PRINTER}: ${SRCS}
	${TBL} ${SRCS} | ${EQN} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2

I 2
clean:
	rm -f paper.[PT]* *.spell errs Errs make.out
E 2

D 2
SRCS=	0.t 1.t 2.t 3.t 4.t 5.t 6.t
TROFF=	itroff
E 2
I 2
spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 2

D 2
fs:	${SRCS}
	eqn ${SRCS} | tbl | ${TROFF} -ms -t > fs

paper:	fs
	lpr -Pimagen -t fs
E 2
E 1
