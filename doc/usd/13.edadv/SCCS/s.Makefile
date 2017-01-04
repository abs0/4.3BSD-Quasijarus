h24444
s 00014/00000/00000
d D 6.1 04/10/23 08:18:22 msokolov 1 0
c date and time created 04/10/23 08:18:22 by msokolov
e
u
U
t
T
I 1
# Makefile for ed advanced manual (USD:13)
#
#	%W%	(Berkeley)	%E%

SRCS=	ae.mac ae0 ae1 ae2 ae3 ae4 ae5 ae6 ae7 ae9
MACROS=	-ms

all:	edadv.ps

edadv.ps: ${SRCS}
	pstroff ${MACROS} ${SRCS} > $@

clean:
	rm -f *.ps errs
E 1
