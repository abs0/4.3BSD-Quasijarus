# Makefile for awk doc (USD:19)
#
#	@(#)Makefile	6.1	(Berkeley)	04/10/24

SRC=	awk
MACROS=	-ms

all:	awk.ps

awk.ps:	${SRC}
	refer ${SRC} | tbl | pstroff ${MACROS} - > $@

clean:
	rm -f *.ps errs
