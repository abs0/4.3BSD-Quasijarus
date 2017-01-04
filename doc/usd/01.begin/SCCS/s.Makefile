h33794
s 00001/00001/00013
d D 6.2 2012/02/19 05:35:00 msokolov 2 1
c label for the thumb index
e
s 00014/00000/00000
d D 6.1 04/10/22 08:31:20 msokolov 1 0
c date and time created 04/10/22 08:31:20 by msokolov
e
u
U
t
T
I 1
# Makefile for USD:1
#
#	%W%	(Berkeley)	%E%

SRCS=	u.mac u0 u1 u2 u3 u4 u5
MACROS=	-ms

all:	begin.ps

begin.ps: ${SRCS}
D 2
	pseqn ${SRCS} | pstroff ${MACROS} - > $@
E 2
I 2
	pseqn ${SRCS} | pstroff ${MACROS} - | pstfinish -l USD:1-%l > $@
E 2

clean:
	rm -f *.ps errs
E 1
