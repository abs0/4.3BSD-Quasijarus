# Makefile for diction doc (USD:32)
#
#	@(#)Makefile	6.1	(Berkeley)	04/10/24

SRCS=	rm0 rm1 rm2 ap1 ap2
MACROS=	-ms

all:	diction.ps

diction.ps: ${SRCS}
	tbl ${SRCS} | pseqn | pstroff ${MACROS} - > $@

clean:
	rm -f *.ps errs
