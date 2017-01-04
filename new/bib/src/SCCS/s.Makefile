h35715
s 00001/00000/00100
d D 2.6 85/06/10 06:24:41 garrison 6 5
c line for compiling with -g (for dbx) added.
e
s 00002/00001/00098
d D 2.5 84/10/01 08:26:10 rrh 5 4
c Compile so that temporary 'files' are held INCORE
e
s 00014/00000/00085
d D 2.4 83/09/23 15:39:47 garrison 4 3
c Included changes from Arizona
e
s 00004/00004/00081
d D 2.3 83/09/09 21:35:00 garrison 3 2
c changed to install binaries in /usr/new
e
s 00001/00001/00084
d D 2.2 83/07/27 01:23:56 nicklin 2 1
c Added -f flag to rm command in clean target
e
s 00085/00000/00000
d D 2.1 83/06/22 14:41:40 garrison 1 0
c date and time created 83/06/22 14:41:40 by garrison
e
u
U
t
T
I 1
#	%W%	%G%
#
D 5
CC = cc
E 5
I 5
CFLAGS = -DINCORE
I 6
#CFLAGS = -DINCORE -g
E 6
CC = cc $(CFLAGS)
E 5
.c.o:
	$(CC) -c $*.c

INVo        = invert.o streams.o  makekey.o
INVc        = invert.c streams.c  makekey.c
LOOKo       = lookup.o locate.o alpha.seek.o streams.o makekey.o
LOOKc       = lookup.c locate.c alpha.seek.c streams.c makekey.c
NEWBIBo     = newbib.o newbibargs.o locate.o alpha.seek.o streams.o makekey.o
BIBo        = bib.o bibargs.o locate.o alpha.seek.o streams.o makekey.o
BIBc        = bib.c bibargs.c locate.c alpha.seek.c streams.c makekey.c
LISTo       = listrefs.o bibargs.o streams.o makekey.o
NEWLISTo    = listrefs.o newbibargs.o streams.o makekey.o
LISTc       = listrefs.c bibargs.c streams.c makekey.c

SRCS = \
	bib.c \
	bibargs.c \
	alpha.seek.c \
	bib.h \
	invert.c \
	listrefs.c \
	locate.c \
	lookup.c \
	makekey.c \
	streams.c \
	streams.h

all:	invert lookup listrefs bib

install: all
D 3
	install -s -c invert $(DESTDIR)/usr/local/invert
	install -s -c lookup $(DESTDIR)/usr/local/lookup
	install -s -c listrefs $(DESTDIR)/usr/local/listrefs
	install -s -c bib $(DESTDIR)/usr/local/bib
E 3
I 3
	install -s -c invert $(DESTDIR)/usr/new/invert
	install -s -c lookup $(DESTDIR)/usr/new/lookup
	install -s -c listrefs $(DESTDIR)/usr/new/listrefs
	install -s -c bib $(DESTDIR)/usr/new/bib
E 3

invert:  $(INVo)
	$(CC)   $(INVo)   -o invert

invert.lint:  $(INVc) bib.h streams.h
	lint  $(INVc) >invert.lint

lookup: $(LOOKo)
	$(CC)   $(LOOKo)  -o lookup

lookup.lint: $(LOOKc) bib.h streams.h
	lint $(LOOKc) >lookup.lint

bib: $(BIBo)
	$(CC)   $(BIBo)  -o bib

bib.lint: $(BIBc) bib.h streams.h
	lint $(BIBc) >bib.lint

listrefs: $(LISTo)
	$(CC)   $(LISTo)  -o listrefs

newlisttrefs: $(NEWLISTo)
	$(CC)   $(NEWLISTo)  -o newlistrefs

bib.o:		bib.h
bibargs.o:	bib.h
listrefs.o:	bib.h
invert.o:       streams.h bib.h

locate.o:       streams.h bib.h
makekey.o:	bib.h
alpha.seek.o:   streams.h
streams.o:      streams.h

$(SRCS) :
	sccs get $@

bibdoc:
	tbl doc/bibdoc.ms | vtroff -ms
	vtroff -man doc/invert.man
	vtroff -man doc/bib.man

doc/INDEX:	doc/testrefs
	cd doc; invert -p INDEX testrefs

I 4
styleman:
	sed -e 's/STYLE/stdn - standard numeric/' tstyles | bib -tstdn >show.stdn
	sed -e 's/STYLE/stdsn - standard sorted numeric/' tstyles | bib -tstdsn >show.stdsn
	sed -e 's/STYLE/stda - standard alphabetic/' tstyles | bib -tstda >show.stda
	sed -e 's/STYLE/opena - open alphabetic/' tstyles | bib -topena >show.opena
	sed -e 's/STYLE/openn - open numeric/' tstyles | bib -topenn >show.openn
	sed -e 's/STYLE/astro - astrophysical journal style/' tstyles | bib -tastro >show.astro
	sed -e 's/STYLE/hnf - Hanson Normal Form/' tstyles | bib -thnf >show.hnf
	sed -e 's/STYLE/list - listrefs default/' tstyles | bib -tlist >show.list
	sed -e 's/STYLE/spe - S P and E Journal style/' tstyles | bib -tspe2 >show.spe
	sed -e 's/STYLE/supn - superscripted numeric style/' tstyles | bib -tsupn >show.supn
	sed -e 's/STYLE/foot - footnoted citations/' tstyles | bib -tfoot >show.foot
	vtroff -ms styletop show.*

E 4
clean:	
D 2
	-rm *.o bib invert listrefs lookup tags
E 2
I 2
	-rm -f *.o bib invert listrefs lookup tags
E 2
E 1
