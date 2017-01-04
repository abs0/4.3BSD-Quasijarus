h13004
s 00021/00026/00021
d D 6.3 04/10/21 08:00:40 msokolov 3 2
c ditroff => pstroff
e
s 00011/00007/00036
d D 6.2 86/05/15 09:11:30 mckusick 2 1
c add title page (with toc) for PRM
e
s 00043/00000/00000
d D 6.1 86/05/10 23:56:55 mckusick 1 0
c date and time created 86/05/10 23:56:55 by mckusick
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
TOCS=	toc1 toc2 toc3 toc3f toc4 toc5 toc6 toc7 toc8 \
	tocx1 tocx2 tocx3 tocx3f tocx4 tocx5 tocx6 tocx7 tocx8
D 3
MACROS=	-msU
PRINTER=Pdp
TROFF=	ditroff -${PRINTER}
E 3
I 3
URMHEAD=title.urm.ps preface.ps intro.ps toc.ps ptx.ps
MACROS=	-ms
TROFF=	pstroff
E 3

D 2
all: title.${PRINTER} preface.${PRINTER} intro.${PRINTER} \
     toc.${PRINTER} ptx.${PRINTER}
	lpr -${PRINTER} -n title.${PRINTER}
E 2
I 2
D 3
all: title.urm.${PRINTER} preface.${PRINTER} intro.${PRINTER} \
     toc.${PRINTER} ptx.${PRINTER} title.prm.${PRINTER}
	lpr -${PRINTER} -n title.urm.${PRINTER}
E 2
	lpr -${PRINTER} -n preface.${PRINTER}
	lpr -${PRINTER} -n intro.${PRINTER}
	lpr -${PRINTER} -n toc.${PRINTER}
	lpr -${PRINTER} -n ptx.${PRINTER}
I 2
	lpr -${PRINTER} -n title.prm.${PRINTER}
E 3
I 3
all: ${URMHEAD} urmhead.ps title.prm.ps
E 3
E 2

D 2
title.${PRINTER}: title.urm
	${TROFF} -t title.urm >title.${PRINTER}
E 2
I 2
D 3
title.urm.${PRINTER}: title.urm
	${TROFF} -t title.urm >title.urm.${PRINTER}
E 3
I 3
title.urm.ps: title.urm
	${TROFF} -t title.urm > $@
E 3
E 2

D 3
preface.${PRINTER}: preface.ms
	${TROFF} ${MACROS} -t preface.ms >preface.${PRINTER}
E 3
I 3
preface.ps: preface.ms
	${TROFF} ${MACROS} -t preface.ms > $@
E 3

D 3
intro.${PRINTER}: intro.ms
	${TROFF} ${MACROS} -t intro.ms >intro.${PRINTER}
E 3
I 3
intro.ps: intro.ms
	${TROFF} ${MACROS} -t intro.ms > $@
E 3

D 3
toc.${PRINTER}: toc.in ptxx
	${TROFF} -t toc.in >toc.${PRINTER}
E 3
I 3
toc.ps: toc.in ptxx
	${TROFF} -t toc.in > $@
E 3

D 3
ptx.${PRINTER}: ptx.in ptxx
	${TROFF} -t ptx.in >ptx.${PRINTER}
E 3
I 3
ptx.ps: ptx.in ptxx
	${TROFF} -t ptx.in > $@
E 3

I 2
D 3
title.prm.${PRINTER}: title.prm ptxx
	${TROFF} -t title.prm >title.prm.${PRINTER}
E 3
I 3
urmhead.ps: ${URMHEAD}
	pstmerge -s ${URMHEAD} > $@
E 3

I 3
title.prm.ps: title.prm ptxx
	${TROFF} -t title.prm > $@

E 3
E 2
ptxx:
	tocrc all
D 3
	tocrc t
E 3

clean:
D 2
	rm -f title.[PT]* preface.[PT]* intro.[PT]* toc.[PT]* ptx.[PT]* \
	${TOCS} ptxx *.spell errs Errs make.out
E 2
I 2
D 3
	rm -f title.urm.[PT]* preface.[PT]* intro.[PT]* toc.[PT]* ptx.[PT]* \
	title.prm.[PT]* ${TOCS} ptxx *.spell errs Errs make.out
E 3
I 3
	rm -f *.ps
	rm -f ${TOCS} ptxx *.spell errs Errs make.out
E 3
E 2
E 1
