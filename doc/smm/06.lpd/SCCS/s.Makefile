h02575
s 00001/00001/00026
d D 6.2 04/08/24 20:24:35 msokolov 2 1
c add a.t
e
s 00027/00000/00000
d D 6.1 86/04/17 16:36:06 mckusick 1 0
c date and time created 86/04/17 16:36:06 by mckusick
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
D 2
SRCS=	0.t 1.t 2.t 3.t 4.t 5.t 6.t 7.t
E 2
I 2
SRCS=	0.t 1.t 2.t 3.t 4.t 5.t 6.t 7.t a.t
E 2
MACROS=	-ms
PRINTER=Pdp
EQN=	deqn -${PRINTER}
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}

paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}

paper.${PRINTER}: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}

clean:
	rm -f paper.${PRINTER} *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
