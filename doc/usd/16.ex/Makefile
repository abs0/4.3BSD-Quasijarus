#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.2 (Berkeley) 10/23/04
#
SRCS=	ex.rm
MACROS=	-ms
TBL=	tbl
TROFF=	pstroff

all:	paper.ps summary.ps

paper.ps: ${SRCS}
	${TROFF} ${MACROS} -t ${SRCS} > $@

summary.ps: ex.summary
	${TBL} ex.summary | ${TROFF} ${MACROS} -t > $@

clean:
	rm -f *.ps summary.[PT]* *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
