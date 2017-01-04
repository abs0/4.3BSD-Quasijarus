# Makefile for shell doc (USD:3)
#
#	@(#)Makefile	6.2	(Berkeley)	2012/02/19

SRCS=	t.mac t1 t2 t3 t4
MACROS=	-ms

all:	shell.ps

shell.ps: ${SRCS}
	refer ${SRCS} | pstroff ${MACROS} - | pstfinish -l USD:3-%l > $@

clean:
	rm -f *.ps errs
