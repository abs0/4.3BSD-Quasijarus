#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.2 (Berkeley) 11/18/04
#
SRCS=	sccs.me
MACROS=	-me
TROFF=	pstroff
NROFF=	nroff8 -Tcol8
COL=	col8 -b

all:	sccs.ps sccs.txt

sccs.ps: ${SRCS}
	${TROFF} ${MACROS} -t ${SRCS} > $@

sccs.txt: ${SRCS}
	${NROFF} ${MACROS} ${SRCS} | ${COL} > $@

clean:
	rm -f *.ps *.txt *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
