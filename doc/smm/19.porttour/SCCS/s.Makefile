h36997
s 00014/00010/00018
d D 6.3 04/11/17 07:53:53 msokolov 3 2
c format with pstroff and nroff8
e
s 00000/00000/00028
d D 6.2 04/11/17 04:23:26 msokolov 2 1
c bump it up to 6.2
e
s 00028/00000/00000
d D 6.1 04/11/17 04:23:11 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 6.2
e
u
U
t
T
I 1
#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
SRCS=	porttour1.ms porttour2.ms
D 3
MACROS=	-msU
PRINTER=Pdp
REFER=	refer -p /usr/doc/run/Ind
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}
E 3
I 3
MACROS=	-ms
REFER=	refer
TBL=	tbl
TROFF=	pstroff
NROFF=	nroff8 -Tcol8
COL=	col8 -b
E 3

D 3
paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
E 3
I 3
all:	paper.ps paper.txt
E 3

D 3
paper.${PRINTER}: ${SRCS}
E 3
I 3
paper.ps: ${SRCS}
E 3
	${REFER} -e ${SRCS} | ${TBL} | \
D 3
	${TROFF} ${MACROS} -t > paper.${PRINTER}
E 3
I 3
	${TROFF} ${MACROS} -t > $@
E 3

I 3
paper.txt: ${SRCS}
	${REFER} -e ${SRCS} | ${TBL} | \
	${NROFF} ${MACROS} | ${COL} > $@

E 3
clean:
D 3
	rm -f paper.[PT]* *.spell errs Errs make.out
E 3
I 3
	rm -f *.ps *.txt *.spell errs Errs make.out
E 3

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
