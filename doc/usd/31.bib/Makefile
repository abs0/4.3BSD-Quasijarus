#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.2 (Berkeley) 10/28/04
#
SRCS=	bibdoc.ms
MACROS=	-ms
BIB=	bib
TBL=	tbl
TROFF=	pstroff

all:	paper.ps

paper.ps: ${SRCS}
	${BIB} ${SRCS} | ${TBL} | ${TROFF} ${MACROS} -t > $@

clean:
	rm -f *.ps *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
