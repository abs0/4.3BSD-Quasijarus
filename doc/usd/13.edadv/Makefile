# Makefile for ed advanced manual (USD:13)
#
#	@(#)Makefile	6.1	(Berkeley)	04/10/23

SRCS=	ae.mac ae0 ae1 ae2 ae3 ae4 ae5 ae6 ae7 ae9
MACROS=	-ms

all:	edadv.ps

edadv.ps: ${SRCS}
	pstroff ${MACROS} ${SRCS} > $@

clean:
	rm -f *.ps errs
