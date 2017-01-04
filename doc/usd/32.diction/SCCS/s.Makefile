h23963
s 00014/00000/00000
d D 6.1 04/10/24 03:06:45 msokolov 1 0
c date and time created 04/10/24 03:06:45 by msokolov
e
u
U
t
T
I 1
# Makefile for diction doc (USD:32)
#
#	%W%	(Berkeley)	%E%

SRCS=	rm0 rm1 rm2 ap1 ap2
MACROS=	-ms

all:	diction.ps

diction.ps: ${SRCS}
	tbl ${SRCS} | pseqn | pstroff ${MACROS} - > $@

clean:
	rm -f *.ps errs
E 1
