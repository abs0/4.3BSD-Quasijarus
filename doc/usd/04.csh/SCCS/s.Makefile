h33751
s 00001/00001/00013
d D 6.2 2012/02/19 05:44:57 msokolov 2 1
c labels for the thumb index
e
s 00014/00000/00000
d D 6.1 04/10/23 05:02:15 msokolov 1 0
c date and time created 04/10/23 05:02:15 by msokolov
e
u
U
t
T
I 1
# Makefile for csh doc (USD:4)
#
#	%W%	(Berkeley)	%E%

SRCS=	csh.1 csh.2 csh.3 csh.4 csh.a csh.g
MACROS=	-ms

all:	csh.ps

csh.ps: ${SRCS}
D 2
	pstroff ${MACROS} ${SRCS} > $@
E 2
I 2
	pstroff ${MACROS} ${SRCS} | pstfinish -l USD:4-%l > $@
E 2

clean:
	rm -f *.ps errs
E 1
