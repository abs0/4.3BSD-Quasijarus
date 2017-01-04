h22751
s 00014/00000/00000
d D 6.1 04/10/23 08:07:19 msokolov 1 0
c date and time created 04/10/23 08:07:19 by msokolov
e
u
U
t
T
I 1
# Makefile for ed tutorial (USD:12)
#
#	%W%	(Berkeley)	%E%

SRCS=	e.mac e0 e1 e2 e3 e4 e5 e6 e7
MACROS=	-ms

all:	edtut.ps

edtut.ps: ${SRCS}
	pstroff ${MACROS} ${SRCS} > $@

clean:
	rm -f *.ps errs
E 1
