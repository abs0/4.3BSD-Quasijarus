# Makefile for sed doc (USD:18)
#
#	@(#)Makefile	6.1	(Berkeley)	04/10/24

SRC=	sed
MACROS=	-ms

all:	sed.ps

sed.ps:	${SRC}
	pstroff ${MACROS} ${SRC} > $@

clean:
	rm -f *.ps errs
