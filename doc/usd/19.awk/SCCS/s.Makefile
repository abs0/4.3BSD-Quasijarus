h21266
s 00014/00000/00000
d D 6.1 04/10/24 00:34:45 msokolov 1 0
c date and time created 04/10/24 00:34:45 by msokolov
e
u
U
t
T
I 1
# Makefile for awk doc (USD:19)
#
#	%W%	(Berkeley)	%E%

SRC=	awk
MACROS=	-ms

all:	awk.ps

awk.ps:	${SRC}
	refer ${SRC} | tbl | pstroff ${MACROS} - > $@

clean:
	rm -f *.ps errs
E 1
