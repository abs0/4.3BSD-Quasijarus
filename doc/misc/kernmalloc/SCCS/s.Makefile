h31434
s 00016/00007/00016
d D 1.2 88/04/22 17:38:26 mckusick 2 1
c lots of new preprocessors
e
s 00023/00000/00000
d D 1.1 88/02/20 16:46:14 mckusick 1 0
c date and time created 88/02/20 16:46:14 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
D 2
SRCS=	kernmalloc.ms
E 2
I 2
SRCS=	kernmalloc.t appendix.t
FIGS=	alloc.fig usage.tbl
E 2
MACROS=	-ms
D 2
PRINTER=Plz
EQN=	deqn -${PRINTER}
TROFF=	ditroff -${PRINTER}
E 2
I 2
PRINTER=lz
SOELIM=	soelim
TBL=	dtbl -P${PRINTER}
EQN=	deqn -P${PRINTER}
PIC=	pic -P${PRINTER}
GRIND=	vgrind -f
TROFF=	rsh vangogh ditroff -P${PRINTER} ${MACROS}
E 2

D 2
paper: ${SRCS}
	${EQN} ${SRCS} | ${TROFF} ${MACROS}
E 2
I 2
print: paper.${PRINTER}
	lpr -P${PRINTER} -n paper.${PRINTER}
E 2

I 2
paper.${PRINTER}: ${SRCS} ${FIGS}
	${SOELIM} ${SRCS} | ${TBL} | ${PIC} | ${EQN} | ${GRIND} | \
		${TROFF} -t - >paper.${PRINTER}

E 2
clean:
D 2
	rm -f paper.[PT]* *.spell errs Errs make.out
E 2
I 2
	rm -f paper.${PRINTER} paper.[PT]* *.spell errs Errs make.out
E 2

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
