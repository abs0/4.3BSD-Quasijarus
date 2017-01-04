h30496
s 00001/00001/00013
d D 6.2 2012/02/19 05:48:11 msokolov 2 1
c labels for the thumb index
e
s 00014/00000/00000
d D 6.1 04/10/23 05:27:42 msokolov 1 0
c date and time created 04/10/23 05:27:42 by msokolov
e
u
U
t
T
I 1
# Makefile for bc doc (USD:6)
#
#	%W%	(Berkeley)	%E%

SRC=	bc
MACROS=	-ms

all:	bc.ps

bc.ps:	${SRC}
D 2
	pstroff ${MACROS} ${SRC} > $@
E 2
I 2
	pstroff ${MACROS} ${SRC} | pstfinish -l USD:6-%l > $@
E 2

clean:
	rm -f *.ps errs
E 1
