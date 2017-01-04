# Makefile for USD:30
#
#	@(#)Makefile	6.1	(Berkeley)	04/10/24

MACROS=	-ms

all:	refer.ps pubuse.ps

refer.ps: refer
	refer refer | tbl | pstroff ${MACROS} - > $@

pubuse.ps: pubuse
	tbl pubuse | pstroff ${MACROS} - > $@

clean:
	rm -f *.ps errs
