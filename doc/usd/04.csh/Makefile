# Makefile for csh doc (USD:4)
#
#	@(#)Makefile	6.2	(Berkeley)	2012/02/19

SRCS=	csh.1 csh.2 csh.3 csh.4 csh.a csh.g
MACROS=	-ms

all:	csh.ps

csh.ps: ${SRCS}
	pstroff ${MACROS} ${SRCS} | pstfinish -l USD:4-%l > $@

clean:
	rm -f *.ps errs
