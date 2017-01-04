# Makefile for eqn guide (USD:27)
#
#	@(#)Makefile	6.5	(Berkeley)	2012/07/25

SRCS=	g.mac g0 g1 g2 g3 g4 g5
TROPTS=	-fR,I,B,St -ms

all:	eqnguide.ps

eqnguide.ps:	${SRCS}
	pseqn ${SRCS} | pstroff ${TROPTS} - | pstfinish -l USD:27-%l > $@

clean:
	rm -f *.ps errs
