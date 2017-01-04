h63022
s 00008/00006/00012
d D 1.2 87/08/05 17:05:14 mckusick 2 1
c use pic for figure 2
e
s 00018/00000/00000
d D 1.1 84/05/21 18:02:44 mckusick 1 0
c date and time created 84/05/21 18:02:44 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1984 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
SRCS=	0.t 1.t 2.t 3.t 4.t
D 2
TBL=	tbl
EQN=	eqn
TROFF=	itroff
TYPE=	-t
E 2
I 2
PIC=	pic ${PRINTER}
TBL=	dtbl ${PRINTER}
EQN=	deqn ${PRINTER}
TROFF=	ditroff ${PRINTER}
PRINTER=-Plz
TYPE=	-n
E 2

paper:	perf
D 2
	lpr -Pimagen ${TYPE} perf
E 2
I 2
	lpr ${PRINTER} ${TYPE} perf
E 2

perf:	${SRCS} Makefile
D 2
	${TBL} ${SRCS} | ${EQN} | ${TROFF} -ms -t > perf
E 2
I 2
	soelim ${SRCS} | ${PIC} | ${TBL} | ${EQN} | ${TROFF} -ms -t > perf
E 2
E 1
