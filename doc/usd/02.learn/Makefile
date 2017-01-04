#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.3 (Berkeley) 2012/02/19
#
DOCS = p0 p1 p2 p3 p4 p5 p6 p7
#
#
# Change these to change the way the document is printed out
#
FMT = pstroff
PKG = -ms
FMTOPTIONS =
TBL = tbl

all: sources learn.ps

clean:
	rm -f *.ps errs

srcs: sources
sources:  $(DOCS)
$(DOCS):
	sccs get $@



docs.raw: $(DOCS)

learn1.ps: $(DOCS)
	refer -p Refs -e $(DOCS) | $(TBL) | $(FMT) $(FMTOPTIONS) $(PKG) > $@

learn.ps: learn1.ps
	pstfinish -l USD:2-%l learn1.ps > $@
