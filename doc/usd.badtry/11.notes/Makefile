#	@(#)Makefile	6.2 (Berkeley) 10/23/04
#
#	Makefile for the notesfile reference manual
#	March 29, 1982
#	Ray Essick, University of Illinois
#	uiucdcs!essick     uiucdcs!notes
#
#	Note that the macros are set up for two-sided copying.
#	The page numbers alternate between the left and right 
#	sides of the page.
#	See the file "macros" and the macro "hh" to modify this
#
#	This copy of everything has been modified to run with troff
#	and a typesetter. Hopefully the only changes to make it
#	run again under nroff will be in page length/width statements.
#
#

DISTDIR	= p:/usr/src/uiuc/notesfiles
DCP=	rcp
NROPTS	= -Tcol8
TROPTS	= 
TROFF	= pstroff
NROFF	= nroff8
COL	= col8 -b
FILES=	0.long 0.short \
	1 2.1 2.2 3.1 3.2 \
	4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 \
	5 \
	a.checklist b.interface c.changes
LONGFILES= 0.long \
	1 2.1 2.2 3.1 3.2 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 \
	5 a.checklist b.interface c.changes
SHORTFILES= 0.short \
	1 2.1 2.2 4.0 4.1 4.2 4.3 4.4 4.5
OTHERS	= macros vtoc Makefile acks

all:	longman.ps longman.txt shortman.ps shortman.txt

longman.ps: $(LONGFILES) macros vtoc acks
	$(TROFF) $(TROPTS) macros $(LONGFILES) vtoc acks > $@

shortman.ps: $(SHORTFILES) macros vtoc
	$(TROFF) $(TROPTS) macros $(SHORTFILES) vtoc > $@

longman.txt: $(LONGFILES) macros vtoc acks
	$(NROFF) $(NROPTS) macros $(LONGFILES) vtoc acks | ${COL} > $@

shortman.txt: $(SHORTFILES) macros vtoc
	$(NROFF) $(NROPTS) macros $(SHORTFILES) vtoc | ${COL} > $@

help:
	@echo "make longman.ps/shortman.ps for long/abridged user man in PS"
	@echo "make longman.txt/shortman.txt for long/abridged user man in text"

#
#	Maintainence.
#

spell:	$(FILES)
	sp $?
	touch spell

diction: out
	diction out > diction

style:	out
	style out > style

dist:	$(FILES) $(OTHERS)
	${DCP} $? $(DISTDIR)/doc/.
	touch dist

clean:
	rm -f *.ps *.txt man out Make.errs
	rm -f diction style spell sp.*

install:
