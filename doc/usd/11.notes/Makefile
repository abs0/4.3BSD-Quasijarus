# Makefile for the PostScript reprint of USD:11
# The pages are troffed in the wrong order and need to be reshuffled

SHORTFILES= 0.short \
	1 2.1 2.2 4.0 4.1 4.2 4.3 4.4 4.5
TROFF=	pstroff
TROPTS=
PARTS=	title.ps toc.ps body.ps

all:	finished.ps

shortman.ps: $(SHORTFILES) macros vtoc
	$(TROFF) $(TROPTS) macros $(SHORTFILES) vtoc > $@

title.ps:	shortman.ps
	psrange shortman.ps 1 > $@

body.ps:	shortman.ps
	psrange shortman.ps 2-16 > $@

toc.ps:		shortman.ps
	psrange shortman.ps 18 > $@

finished.ps:	${PARTS}
	pstmerge -s -l USD:11-%l ${PARTS} > $@

clean:
	rm -f *.ps *.out errs
