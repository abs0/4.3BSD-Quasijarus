h20179
s 00014/00000/00000
d D 6.1 04/10/24 00:47:01 msokolov 1 0
c date and time created 04/10/24 00:47:01 by msokolov
e
u
U
t
T
I 1
# Makefile for -ms doc (USD:20)
#
#	%W%	(Berkeley)	%E%

SRC=	ms
MACROS=	-ms

all:	ms.ps

ms.ps:	${SRC}
	tbl ${SRC} | pstroff ${MACROS} - > $@

clean:
	rm -f *.ps errs
E 1
