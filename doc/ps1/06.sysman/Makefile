#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.3 (Berkeley) 11/28/04
#
SRCS=	0.t 1.0.t 1.1.t 1.2.t 1.3.t 1.4.t 1.5.t 1.6.t 1.7.t \
	2.0.t 2.1.t 2.2.t 2.3.t 2.4.t 2.5.t a.t
MACROS=	-ms
TBL=	tbl
TROFF=	pstroff
NROFF=	nroff8 -Tcol8
COL=	col8 -b

all:	paper.ps paper.txt

paper.ps: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > $@

paper.txt: ${SRCS}
	${TBL} ${SRCS} | ${NROFF} ${MACROS} | ${COL} > $@

clean:
	rm -f *.ps *.txt *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
