h19932
s 00014/00000/00000
d D 6.1 04/10/24 00:21:59 msokolov 1 0
c date and time created 04/10/24 00:21:59 by msokolov
e
u
U
t
T
I 1
# Makefile for sed doc (USD:18)
#
#	%W%	(Berkeley)	%E%

SRC=	sed
MACROS=	-ms

all:	sed.ps

sed.ps:	${SRC}
	pstroff ${MACROS} ${SRC} > $@

clean:
	rm -f *.ps errs
E 1
