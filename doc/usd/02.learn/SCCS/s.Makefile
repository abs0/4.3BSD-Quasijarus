h39959
s 00005/00002/00031
d D 6.3 2012/02/19 05:39:18 msokolov 3 2
c labels for the thumb index
e
s 00007/00015/00026
d D 6.2 04/10/22 08:42:39 msokolov 2 1
c ditroff => pstroff
e
s 00041/00000/00000
d D 6.1 86/05/23 09:26:30 kjd 1 0
c date and time created 86/05/23 09:26:30 by kjd
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
D 3
#	%W% (Berkeley) %G%
E 3
I 3
#	%W% (Berkeley) %E%
E 3
#
DOCS = p0 p1 p2 p3 p4 p5 p6 p7
#
#
# Change these to change the way the document is printed out
#
D 2
FMT = ditroff
PKG = -msU
PRINTER = -Pdp
E 2
I 2
FMT = pstroff
PKG = -ms
E 2
FMTOPTIONS =
D 2
TBL = dtbl
E 2
I 2
TBL = tbl
E 2

D 2
all: sources fmt
E 2
I 2
all: sources learn.ps
E 2

clean:
D 2
	-rm $(FMTDST)
E 2
I 2
	rm -f *.ps errs
E 2

srcs: sources
sources:  $(DOCS)
$(DOCS):
	sccs get $@



docs.raw: $(DOCS)

D 2
fmt: $(DOCS)
	refer -p Refs -e $(DOCS) | $(TBL) $(PRINTER) | $(FMT) $(FMTOPTIONS) $(PKG) $(PRINTER)

aps: $(DOCS)
	refer -p Refs -e $(DOCS) | $(TBL) $(PRINTER) | $(FMT) $(FMTOPTIONS) $(PKG) $(PRINTER) | $(LPR)

indexable: $(DOCS)
	refer -p Refs -e $(DOCS) | $(TBL) $(PRINTER) | sed -f ../pre.sed | $(FMT) $(FMTOPTIONS) $(PKG) $(PRINTER) | sed -f ../post.sed >../learn.a

E 2
I 2
D 3
learn.ps: $(DOCS)
E 3
I 3
learn1.ps: $(DOCS)
E 3
	refer -p Refs -e $(DOCS) | $(TBL) | $(FMT) $(FMTOPTIONS) $(PKG) > $@
I 3

learn.ps: learn1.ps
	pstfinish -l USD:2-%l learn1.ps > $@
E 3
E 2
E 1
