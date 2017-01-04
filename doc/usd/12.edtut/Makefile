# Makefile for ed tutorial (USD:12)
#
#	@(#)Makefile	6.1	(Berkeley)	04/10/23

SRCS=	e.mac e0 e1 e2 e3 e4 e5 e6 e7
MACROS=	-ms

all:	edtut.ps

edtut.ps: ${SRCS}
	pstroff ${MACROS} ${SRCS} > $@

clean:
	rm -f *.ps errs
