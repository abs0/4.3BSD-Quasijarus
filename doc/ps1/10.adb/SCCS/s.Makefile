h65416
s 00005/00010/00018
d D 6.2 04/09/13 03:41:01 msokolov 2 1
c ditroff => pstroff
e
s 00028/00000/00000
d D 6.1 86/05/07 23:54:48 mckusick 1 0
c document released with 4.3BSD
e
u
U
t
T
I 1
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
D 2
PRINTER=-Pdp
TROFF=	ditroff ${PRINTER}
EQN=	deqn ${PRINTER}
TBL=	dtbl ${PRINTER}
LPR=	lpr -n ${PRINTER}
E 2
I 2
TROFF=	pstroff
E 2

SRCS=	adb.ms

D 2
paper:	adb.n
	${LPR} adb.n
E 2
I 2
all:	adb.ps
E 2

D 2
adb.n:	${SRCS}
	${EQN} ${SRCS} | ${TBL} | ${TROFF} -t -ms >adb.n
E 2
I 2
adb.ps:	${SRCS}
	${TROFF} -ms ${SRCS} > adb.ps
E 2

clean:
D 2
	rm -f adb.n
E 2
I 2
	rm -f adb.ps
E 2

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
