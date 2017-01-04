h50069
s 00027/00000/00000
d D 6.1 86/05/05 16:25:27 mckusick 1 0
c date and time created 86/05/05 16:25:27 by mckusick
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
PRINTER=-Pdp
TROFF=	ditroff ${PRINTER}
TBL=	dtbl ${PRINTER}
LPR=	lpr -n ${PRINTER}

SRCS=	dbx.ms

paper:	dbx.n
	${LPR} dbx.n

dbx.n:	${SRCS}
	${TBL} ${SRCS} | ${TROFF} -t -msU >dbx.n

clean:
	rm -f dbx.n

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
