# Makefile for -ms doc (USD:20)
#
#	@(#)Makefile	6.1	(Berkeley)	04/10/24

SRC=	ms
MACROS=	-ms

all:	ms.ps

ms.ps:	${SRC}
	tbl ${SRC} | pstroff ${MACROS} - > $@

clean:
	rm -f *.ps errs
