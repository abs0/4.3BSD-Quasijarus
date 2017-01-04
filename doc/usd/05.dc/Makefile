# Makefile for dc doc (USD:5)
#
#	@(#)Makefile	6.2	(Berkeley)	2012/02/19

SRC=	dc
MACROS=	-ms

all:	dc.ps

dc.ps:	${SRC}
	pseqn ${SRC} | pstroff ${MACROS} - | pstfinish -l USD:5-%l > $@

clean:
	rm -f *.ps errs
