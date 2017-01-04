#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.2 (Berkeley) 9/13/04
#
SRCS=	kdebug.ms
MACROS=	-ms
TBL=	tbl
TROFF=	pstroff

all:	paper.ps

paper.ps: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} > paper.ps

clean:
	rm -f paper.ps *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
