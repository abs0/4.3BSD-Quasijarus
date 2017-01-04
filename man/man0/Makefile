#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.3 (Berkeley) 10/21/04
#
TOCS=	toc1 toc2 toc3 toc3f toc4 toc5 toc6 toc7 toc8 \
	tocx1 tocx2 tocx3 tocx3f tocx4 tocx5 tocx6 tocx7 tocx8
URMHEAD=title.urm.ps preface.ps intro.ps toc.ps ptx.ps
MACROS=	-ms
TROFF=	pstroff

all: ${URMHEAD} urmhead.ps title.prm.ps

title.urm.ps: title.urm
	${TROFF} -t title.urm > $@

preface.ps: preface.ms
	${TROFF} ${MACROS} -t preface.ms > $@

intro.ps: intro.ms
	${TROFF} ${MACROS} -t intro.ms > $@

toc.ps: toc.in ptxx
	${TROFF} -t toc.in > $@

ptx.ps: ptx.in ptxx
	${TROFF} -t ptx.in > $@

urmhead.ps: ${URMHEAD}
	pstmerge -s ${URMHEAD} > $@

title.prm.ps: title.prm ptxx
	${TROFF} -t title.prm > $@

ptxx:
	tocrc all

clean:
	rm -f *.ps
	rm -f ${TOCS} ptxx *.spell errs Errs make.out
