h16631
s 00001/00003/00031
d D 6.2 86/05/06 17:09:46 mckusick 2 1
c cannot vgrind with -me
e
s 00034/00000/00000
d D 6.1 86/05/04 16:35:06 mckusick 1 0
c date and time created 86/05/04 16:35:06 by mckusick
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
SRCS=	tutor.me
GSRCS=	gremlins
MACROS=	-me
PRINTER=Pdp
SOELIM=	soelim
D 2
GRIND=	vgrind -f
E 2
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}

paper:	paper.${PRINTER} pics.Pip
	lpr -${PRINTER} -n paper.${PRINTER}
	lpr -Pip -n pics.Pip

paper.${PRINTER}: ${SRCS}
D 2
	${SOELIM} ${SRCS} | ${GRIND} | ${TBL} | \
	${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2

pics.Pip: ${GSRCS}
	grn -Pip ${GSRCS} | ditroff -Pip -t >pics.Pip

clean:
	rm -f paper.[PT]* *.spell errs Errs make.out

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
