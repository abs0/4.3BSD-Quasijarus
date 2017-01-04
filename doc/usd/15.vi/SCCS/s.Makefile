h52963
s 00011/00015/00019
d D 6.2 04/10/23 09:06:59 msokolov 2 1
c ditroff => pstroff
e
s 00034/00000/00000
d D 6.1 86/05/30 11:19:12 mckusick 1 0
c date and time created 86/05/30 11:19:12 by mckusick
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
SRCS=	vi.in vi.chars
D 2
MACROS=	-msU
PRINTER=Pdp
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}
E 2
I 2
MACROS=	-ms
TBL=	tbl
TROFF=	pstroff
E 2

D 2
paper:	paper.${PRINTER} summary.${PRINTER} viapwh.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
	lpr -${PRINTER} -n summary.${PRINTER}
	lpr -${PRINTER} -n viapwh.${PRINTER}
E 2
I 2
all:	paper.ps summary.ps viapwh.ps
E 2

D 2
paper.${PRINTER}: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 2
I 2
paper.ps: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > $@
E 2

D 2
summary.${PRINTER}: vi.summary
	${TBL} vi.summary | ${TROFF} ${MACROS} -t > summary.${PRINTER}
E 2
I 2
summary.ps: vi.summary
	${TBL} vi.summary | ${TROFF} ${MACROS} -t > $@
E 2

D 2
viapwh.${PRINTER}: vi.apwh.ms
	${TROFF} ${MACROS} -t vi.viapwh > viapwh.${PRINTER}
E 2
I 2
viapwh.ps: vi.apwh.ms
	${TROFF} ${MACROS} -t vi.apwh.ms > $@
E 2

clean:
D 2
	rm -f paper.[PT]* summary.[PT]* viapwh.[PT]* *.spell errs Errs make.out
E 2
I 2
	rm -f *.ps *.spell errs Errs make.out
E 2

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1
