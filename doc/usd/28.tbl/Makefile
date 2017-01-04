# Makefile for tbl doc (USD:28)
#
#	@(#)Makefile	6.2	(Berkeley)	2012/07/26

SRC=	tbl
TROPTS=	-fR,I,B,BI,S -ms

all:	tbl.ps

tbl.ps:	${SRC}
	tbl ${SRC} | pseqn | pstroff ${TROPTS} - | pstfinish -l USD:28-%l > $@

clean:
	rm -f *.ps errs
