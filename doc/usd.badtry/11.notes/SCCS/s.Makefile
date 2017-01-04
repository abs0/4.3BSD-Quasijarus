h38347
s 00016/00026/00062
d D 6.2 04/10/23 07:51:31 msokolov 2 1
c convert to pstroff and nroff8
e
s 00088/00000/00000
d D 6.1 04/10/23 06:21:36 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 6.1
e
u
U
t
T
I 1
#	%W% (Berkeley) %G%
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
D 2
NROPTS	= 
E 2
I 2
NROPTS	= -Tcol8
E 2
TROPTS	= 
D 2
PRINTER	= -Pdp
#	ditroff actually prints the mother
TROFF	= ditroff
NROFF	= nroff
NOUT	= qprx
E 2
I 2
TROFF	= pstroff
NROFF	= nroff8
COL	= col8 -b
E 2
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

D 2
man:	shortman
all:	longman shortman
E 2
I 2
all:	longman.ps longman.txt shortman.ps shortman.txt
E 2

D 2
longman:	$(LONGFILES) macros vtoc acks
	$(TROFF) $(TROPTS) $(PRINTER) macros $(LONGFILES) vtoc acks
E 2
I 2
longman.ps: $(LONGFILES) macros vtoc acks
	$(TROFF) $(TROPTS) macros $(LONGFILES) vtoc acks > $@
E 2

D 2
shortman: $(SHORTFILES) macros vtoc
	$(TROFF) $(TROPTS) $(PRINTER) macros $(SHORTFILES) vtoc
E 2
I 2
shortman.ps: $(SHORTFILES) macros vtoc
	$(TROFF) $(TROPTS) macros $(SHORTFILES) vtoc > $@
E 2

D 2
longout: $(LONGFILES) macros vtoc acks
	$(NROFF) $(NROPTS) macros $(LONGFILES) vtoc acks > longout
E 2
I 2
longman.txt: $(LONGFILES) macros vtoc acks
	$(NROFF) $(NROPTS) macros $(LONGFILES) vtoc acks | ${COL} > $@
E 2

D 2
shortout: $(SHORTFILES) macros vtoc
	$(NROFF) $(NROPTS) macros $(SHORTFILES) vtoc > shortout
E 2
I 2
shortman.txt: $(SHORTFILES) macros vtoc
	$(NROFF) $(NROPTS) macros $(SHORTFILES) vtoc | ${COL} > $@
E 2

D 2
print: longout
	$(NOUT) longout

printsh: shortout
	$(NOUT) shortout

E 2
help:
D 2
	@echo "make longman/shortman for long/abridged user man via ditroff"
	@echo "make longout/shortout for long/abridged user man via nroff"
	@echo "make print prints long nroff output"
E 2
I 2
	@echo "make longman.ps/shortman.ps for long/abridged user man in PS"
	@echo "make longman.txt/shortman.txt for long/abridged user man in text"
E 2

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
D 2
	rm -f man out Make.errs
E 2
I 2
	rm -f *.ps *.txt man out Make.errs
E 2
	rm -f diction style spell sp.*

install:
E 1
