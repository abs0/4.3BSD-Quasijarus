h06018
s 00001/00003/00025
d D 6.2 86/05/10 14:14:19 bloom 2 1
c final working copy
e
s 00028/00000/00000
d D 6.1 86/04/25 02:24:06 cuccia 1 0
c date and time created 86/04/25 02:24:06 by cuccia
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
SRCS=	p0 p1 p2 p3 p4 p5 p6 p8 p9
MAC = p.mac
D 2
SEDFILES=cwscript
E 2
MACROS=	-ms
PRINTER=Pdp
D 2
SED = sed -f
E 2
TROFF=	ditroff -${PRINTER}

paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}

paper.${PRINTER}: ${SRCS}
D 2
	${SED} ${SEDFILES} ${SRCS} | ${TROFF} ${MACROS} ${MAC} -t > paper.${PRINTER}
E 2
I 2
	${TROFF} -t ${MACROS} ${MAC} ${SRCS} > paper.${PRINTER}
E 2

clean:
	rm -f paper.[PT]* *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
