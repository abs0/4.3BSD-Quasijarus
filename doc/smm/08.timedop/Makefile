#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.2 (Berkeley) 8/25/05
#
SRCS=	timed.ms
MACROS=	-ms
TROFF=	pstroff

all:	paper.ps

paper.ps: ${SRCS}
	${TROFF} ${MACROS} -t ${SRCS} > $@

clean:
	rm -f *.ps *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
