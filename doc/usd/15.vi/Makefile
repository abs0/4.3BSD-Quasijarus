#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.2 (Berkeley) 10/23/04
#
SRCS=	vi.in vi.chars
MACROS=	-ms
TBL=	tbl
TROFF=	pstroff

all:	paper.ps summary.ps viapwh.ps

paper.ps: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > $@

summary.ps: vi.summary
	${TBL} vi.summary | ${TROFF} ${MACROS} -t > $@

viapwh.ps: vi.apwh.ms
	${TROFF} ${MACROS} -t vi.apwh.ms > $@

clean:
	rm -f *.ps *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
