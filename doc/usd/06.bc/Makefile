# Makefile for bc doc (USD:6)
#
#	@(#)Makefile	6.2	(Berkeley)	2012/02/19

SRC=	bc
MACROS=	-ms

all:	bc.ps

bc.ps:	${SRC}
	pstroff ${MACROS} ${SRC} | pstfinish -l USD:6-%l > $@

clean:
	rm -f *.ps errs
