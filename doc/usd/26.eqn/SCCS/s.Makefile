h22876
s 00014/00000/00000
d D 6.1 04/09/17 22:18:21 msokolov 1 0
c date and time created 04/09/17 22:18:21 by msokolov
e
u
U
t
T
I 1
# Makefile for eqn paper (USD:26)
#
#	%W%	(Berkeley)	%E%

SRCS=	e.mac e0 e1 e2 e3 e4 e5 e6 e7
MACROS=	-ms

all:	eqn.ps

eqn.ps:	${SRCS}
	pseqn ${SRCS} | pstroff ${MACROS} - > $@

clean:
	rm -f *.ps errs
E 1
