#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.3 (Berkeley) 11/17/04
#
SRCS=	porttour1.ms porttour2.ms
MACROS=	-ms
REFER=	refer
TBL=	tbl
TROFF=	pstroff
NROFF=	nroff8 -Tcol8
COL=	col8 -b

all:	paper.ps paper.txt

paper.ps: ${SRCS}
	${REFER} -e ${SRCS} | ${TBL} | \
	${TROFF} ${MACROS} -t > $@

paper.txt: ${SRCS}
	${REFER} -e ${SRCS} | ${TBL} | \
	${NROFF} ${MACROS} | ${COL} > $@

clean:
	rm -f *.ps *.txt *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
