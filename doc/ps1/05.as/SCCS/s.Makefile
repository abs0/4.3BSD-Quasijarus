h29787
s 00010/00006/00037
d D 1.2 86/04/15 13:42:52 mckusick 2 1
c from mis
e
s 00043/00000/00000
d D 1.1 83/02/11 12:34:37 rrh 1 0
c date and time created 83/02/11 12:34:37 by rrh
e
u
U
t
T
I 1
#
# Copyright (c) 1983 Regents of the University of California
#
#	%W%	(Berkeley)	%G%
#
MAN = as.man.1
DOC = asdocs0.me asdocs1.me asdocs2.me asdocs3.me asdocs4.me
#
# Change these to change the way the document is printed out;
# the document is written using -me, which always must be present
#
D 2
FMT = vtroff -me
FMTOPTIONS = -t
E 2
I 2
FMT = ditroff
PKG = -me
PRINTER = -Pdp
# FMTOPTIONS = -t
FMTOPTIONS =
E 2
FMTDST = docs.t.out
D 2

E 2
I 2
EQN = deqn
TBL = dtbl
E 2
all: sources fmt

clean:
	-rm *.TME $(FMTDST)

srcs: sources
sources:  $(DOC) $(MAN)
$(DOC) $(MAN):
	sccs get $@
#
# Constructing the assembler documentation:
#	assembler reference manual
#	assembler manual page
#
.SUFFIXES: .me .TME .tbl

DOCS = asdocs0.me asdocs1.TME asdocs2.TME asdocs3.TME asdocs4.TME

docs.raw: $(DOCS)

fmt: $(DOCS)
D 2
	cat $(DOCS) | $(FMT) $(FMTOPTIONS) > $(FMTDST)
E 2
I 2
	cat $(DOCS) | $(FMT) $(FMTOPTIONS) $(PKG) $(PRINTER)
E 2
	-rm *.TME

.me.TME:
D 2
	soelim $*.me | tbl > $*.tmp
	eqn /usr/pub/eqnchar $*.tmp > $*.TME
E 2
I 2
	soelim $*.me | $(TBL) $(PRINTER) > $*.tmp
	$(EQN) $(PRINTER) /usr/pub/eqnchar $*.tmp > $*.TME
E 2
	rm $*.tmp
E 1
