h36705
s 00007/00002/00023
d D 6.3 04/11/28 23:32:29 msokolov 3 2
c add plain text version
e
s 00006/00008/00019
d D 6.2 04/11/28 22:18:48 msokolov 2 1
c ditroff => pstroff
e
s 00027/00000/00000
d D 6.1 86/05/08 00:06:17 mckusick 1 0
c date and time created 86/05/08 00:06:17 by mckusick
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
SRCS=	0.t 1.0.t 1.1.t 1.2.t 1.3.t 1.4.t 1.5.t 1.6.t 1.7.t \
	2.0.t 2.1.t 2.2.t 2.3.t 2.4.t 2.5.t a.t
MACROS=	-ms
D 2
PRINTER=Pdp
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}
E 2
I 2
TBL=	tbl
TROFF=	pstroff
I 3
NROFF=	nroff8 -Tcol8
COL=	col8 -b
E 3
E 2

D 2
paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
E 2
I 2
D 3
all:	paper.ps
E 3
I 3
all:	paper.ps paper.txt
E 3
E 2

D 2
paper.${PRINTER}: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
paper.ps: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > $@
E 2

I 3
paper.txt: ${SRCS}
	${TBL} ${SRCS} | ${NROFF} ${MACROS} | ${COL} > $@

E 3
clean:
D 2
	rm -f paper.[PT]* *.spell errs Errs make.out
E 2
I 2
D 3
	rm -f *.ps *.spell errs Errs make.out
E 3
I 3
	rm -f *.ps *.txt *.spell errs Errs make.out
E 3
E 2

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
