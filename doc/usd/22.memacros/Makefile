#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.3 (Berkeley) 10/24/04
#
SRCS=	intro.me
TROFF=	pstroff

all:	intro.ps

intro.ps: ${SRCS}
	${TROFF} -me -t ${SRCS} > intro1.ps
	psrange intro1.ps 2- > intro.ps
	rm -f intro1.ps

clean:
	rm -f *.ps *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
