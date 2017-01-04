#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.3 (Berkeley) 2012/02/19
#
SRCS=	mail0.nr mail1.nr mail2.nr mail3.nr mail4.nr mail5.nr mail6.nr \
	mail7.nr mail8.nr mail9.nr maila.nr

MACROS=	-me
TBL=	tbl
TROFF=	pstroff

all:	paper.ps

paper.ps: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t | pstfinish -l USD:7-%l > $@

clean:
	rm -f *.ps *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
