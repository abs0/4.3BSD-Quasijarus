# Makefile for USD:1
#
#	@(#)Makefile	6.2	(Berkeley)	2012/02/19

SRCS=	u.mac u0 u1 u2 u3 u4 u5
MACROS=	-ms

all:	begin.ps

begin.ps: ${SRCS}
	pseqn ${SRCS} | pstroff ${MACROS} - | pstfinish -l USD:1-%l > $@

clean:
	rm -f *.ps errs
