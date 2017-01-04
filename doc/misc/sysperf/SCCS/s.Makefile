h10992
s 00001/00001/00032
d D 1.2 85/11/30 12:08:06 mckusick 2 1
c use dp instead of ip by default
e
s 00033/00000/00000
d D 1.1 85/07/27 19:43:14 mckusick 1 0
c date and time created 85/07/27 19:43:14 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1985 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
D 2
PRINTER=-Pip
E 2
I 2
PRINTER=-Pdp
E 2
TYPE=	-n
SRCS=	0.t 1.t 2.t 3.t 4.t 5.t 6.t 7.t
OBJS=	perf.t appendix.t
TBL=	dtbl
EQN=	deqn
TROFF=	ditroff
GRIND=	igrind

paper:	perf
	lpr ${PRINTER} ${TYPE} perf

perf:	${OBJS}
	${TROFF} -ms -t ${PRINTER} ${OBJS} > perf

perf.t:	${SRCS}
	${TBL} ${PRINTER} ${SRCS} | ${EQN} ${PRINTER} > perf.t

appendix.t: a1.t a2.t
	${GRIND} -f a1.t |  awk '/\.\(\)/{ cnt = 2 } \
	   { if (cnt) cnt -= 1; else print $$0; } ' > appendix.t
	${GRIND} -f -lcsh a2.t |  awk '/\.\(\)/{ cnt = 2 } \
	   { if (cnt) cnt -= 1; else print $$0; } ' >> appendix.t

clean:
	rm -f perf ${OBJS}
E 1
