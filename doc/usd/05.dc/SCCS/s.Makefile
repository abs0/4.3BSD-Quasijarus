h32137
s 00001/00001/00013
d D 6.2 2012/02/19 05:46:29 msokolov 2 1
c labels for the thumb index
e
s 00014/00000/00000
d D 6.1 04/10/23 05:21:37 msokolov 1 0
c date and time created 04/10/23 05:21:37 by msokolov
e
u
U
t
T
I 1
# Makefile for dc doc (USD:5)
#
#	%W%	(Berkeley)	%E%

SRC=	dc
MACROS=	-ms

all:	dc.ps

dc.ps:	${SRC}
D 2
	pseqn ${SRC} | pstroff ${MACROS} - > $@
E 2
I 2
	pseqn ${SRC} | pstroff ${MACROS} - | pstfinish -l USD:5-%l > $@
E 2

clean:
	rm -f *.ps errs
E 1
