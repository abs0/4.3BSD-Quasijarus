h26050
s 00016/00000/00000
d D 6.1 04/10/24 02:55:20 msokolov 1 0
c date and time created 04/10/24 02:55:20 by msokolov
e
u
U
t
T
I 1
# Makefile for USD:30
#
#	%W%	(Berkeley)	%E%

MACROS=	-ms

all:	refer.ps pubuse.ps

refer.ps: refer
	refer refer | tbl | pstroff ${MACROS} - > $@

pubuse.ps: pubuse
	tbl pubuse | pstroff ${MACROS} - > $@

clean:
	rm -f *.ps errs
E 1
