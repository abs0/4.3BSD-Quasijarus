#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.2 (Berkeley) 10/24/04
#
# refer.mac should be typed on a 12 pitch Daisy wheel printer
SRCS=	refer.bib
MACROS=	-ms
REFER=	refer -p biblio
TROFF=	pstroff

all:	paper.ps

paper.ps: ${SRCS}
	${REFER} ${SRCS} | ${TROFF} ${MACROS} -t > $@

clean:
	rm -f *.ps *.spell errs Errs make.out biblio.ig

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
