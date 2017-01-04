h19191
s 00007/00009/00017
d D 6.2 05/05/24 07:23:03 msokolov 2 1
c ditroff => pstroff
e
s 00026/00000/00000
d D 6.1 86/05/08 00:26:49 mckusick 1 0
c date and time created 86/05/08 00:26:49 by mckusick
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
SRCS=	ss.. ss0 ss1 ss2 ss3 ss4 ss5 ss6 ss7 ss8 ss9 ssA ssB ssa ssb ssc ssd
D 2
MACROS=	-msU
PRINTER=Pdp
REFER=	refer -e -p /usr/doc/run/Ind
TROFF=	ditroff -${PRINTER}
E 2
I 2
MACROS=	-ms
REFER=	refer -e
TROFF=	pstroff
E 2

D 2
paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
E 2
I 2
all:	paper.ps
E 2

D 2
paper.${PRINTER}: ${SRCS}
	${REFER} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
paper.ps: ${SRCS}
	${REFER} ${SRCS} | ${TROFF} ${MACROS} -t > paper.ps
E 2

clean:
D 2
	rm -f paper.[PT]* *.spell errs Errs make.out
E 2
I 2
	rm -f *.ps *.spell errs Errs make.out
E 2

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
