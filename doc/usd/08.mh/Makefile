# Makefile for the PostScript reprint of the MH doc USD:8
# The pages are troffed in the wrong order and need to be reshuffled

MERGE1=	title.ps toc.ps front.ps
MERGE2=	prepend.ps body.ps

all:	mhdoc.ps

# uses \(rh, so we need to add ZapfDingbats to the font list
MH.ps:	MH.me
	pstroff -me -fR,I,B,S,ZD MH.me > $@

body.ps: MH.ps
	psrange MH.ps 2-110 > $@

front.ps: MH.ps
	psrange MH.ps 112-116 > $@

toc.ps:	MH.ps
	psrange MH.ps 117-119 > $@

title.ps: MH.ps
	psrange MH.ps 120 > $@

prepend.ps:	${MERGE1}
	pstmerge ${MERGE1} > $@

mhdoc.ps:	${MERGE2}
	pstmerge -s -l USD:8-%l ${MERGE2} > $@

clean:
	rm -f *.ps *.out errs
