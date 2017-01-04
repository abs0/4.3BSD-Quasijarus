h34513
s 00001/00001/00013
d D 6.2 2012/02/19 05:41:44 msokolov 2 1
c labels for the thumb index
e
s 00014/00000/00000
d D 6.1 04/10/22 09:17:10 msokolov 1 0
c date and time created 04/10/22 09:17:10 by msokolov
e
u
U
t
T
I 1
# Makefile for shell doc (USD:3)
#
#	%W%	(Berkeley)	%E%

SRCS=	t.mac t1 t2 t3 t4
MACROS=	-ms

all:	shell.ps

shell.ps: ${SRCS}
D 2
	refer ${SRCS} | pstroff ${MACROS} - > $@
E 2
I 2
	refer ${SRCS} | pstroff ${MACROS} - | pstfinish -l USD:3-%l > $@
E 2

clean:
	rm -f *.ps errs
E 1
