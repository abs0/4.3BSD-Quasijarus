#
# Special Makefile for formatting the historic 4.3BSD version of USD:24
# with Quasijarus pstroff tools.
#
INTRO=	m0
TUTOR=	m0a
PAPER=	m1 m2 m3 m4
APNDX1=	m5
APNDX2=	table1
APNDX3=	table2
MACROS=	m.mac
ALLSRC=	${MACROS} ${INTRO} ${TUTOR} ${PAPER} ${APNDX1} ${APNDX2} ${APNDX3}
ORIGSRC=/fs1/4.3man/doc/usd/24.troff
TBL=	tbl
TROFF=	pstroff -T '-b*6,S-'
PARTS=	intro.ps tutor.ps paper.ps apndx1.ps apndx2.ps apndx3.ps

all:	fulldoc.ps

fulldoc.ps: ${PARTS}
	pstmerge ${PARTS} > $@

# The psrange in each of the following stanzas is necessary because
# troff is producing an extra page for each part.

intro.ps: ${INTRO}
	${TROFF} -t ${MACROS} ${INTRO} | psrange 1-2 > intro.ps

tutor.ps: ${TUTOR}
	${TBL} ${TUTOR} | ${TROFF} -t ${MACROS} - | psrange 1-5 > tutor.ps

paper.ps: ${PAPER}
	${TBL} ${PAPER} | ${TROFF} -t ${MACROS} - | psrange 1-18 > paper.ps

apndx1.ps: ${APNDX1}
	${TROFF} -t ${MACROS} ${APNDX1} | psrange 1-4 > apndx1.ps

apndx2.ps: ${APNDX2}
	${TROFF} -t ${MACROS} ${APNDX2} | psrange 1 > apndx2.ps

apndx3.ps: ${APNDX3}
	${TROFF} -t ${MACROS} ${APNDX3} | psrange 1-2 > apndx3.ps

clean:
	rm -f *.ps *.spell errs Errs make.out

spell:	${INTRO} ${TUTOR} ${PAPER} ${APNDX1} ${APNDX2} ${APNDX3}
	@for i in ${INTRO} ${TUTOR} ${PAPER} ${APNDX1} ${APNDX2} ${APNDX3}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done

diff:
	-for i in ${ALLSRC}; do diff -c ${ORIGSRC}/$$i $$i; done > 4.3-diff
