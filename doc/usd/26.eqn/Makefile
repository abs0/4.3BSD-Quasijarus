# Makefile for eqn paper (USD:26)
#
# The document uses \(bv as a general-purpose vertical bar.
# S1 font added to make it look the way it did in the olde days.
#
#	%W%	(Berkeley)	%E%

SRCS=	e.mac e0 e1 e2 e3 e4 e5 e6 e7
TROPTS=	-fR,I,B,S,S1 -ms

all:	eqn.ps

eqn.ps:	${SRCS}
	pseqn ${SRCS} | pstroff ${TROPTS} - | pstfinish -l USD:26-%l > $@

clean:
	rm -f *.ps errs
