#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.3 (Berkeley) 10/24/04
#
SRCS=	ref.me
TROFF=	pstroff

all:	ref.ps

ref.ps: ${SRCS}
	${TROFF} -me -t ${SRCS} > ref1.ps
	psrange ref1.ps 2- > ref.ps
	rm -f ref1.ps

clean:
	rm -f *.ps *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
