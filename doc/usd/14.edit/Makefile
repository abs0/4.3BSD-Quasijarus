#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.2 (Berkeley) 10/23/04
#
SRCS=	edittut.ms
MACROS=	-ms
TBL=	tbl
TROFF=	pstroff

all:	paper.ps

paper.ps: ${SRCS}
	${TROFF} ${MACROS} ${SRCS} > $@

clean:
	rm -f *.ps *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done

# index for versatec is different from the one in edit.tut
# because the fonts are different and entries reference page
# rather than section numbers.  if you have a typesetter
# you should just use the index in edit.tut, and ignore editvindex.

#editvindex:
#	${TROFF} ${MACROS} -n22 edit.vindex
