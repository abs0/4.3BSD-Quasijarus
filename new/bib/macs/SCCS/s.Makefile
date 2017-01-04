h40856
s 00001/00000/00044
d D 1.7 87/11/16 17:00:38 garrison 7 6
c added bib.compsurv
e
s 00001/00001/00043
d D 1.6 85/09/10 12:35:35 mckusick 6 5
c bmac moves to /usr/new/lib
e
s 00005/00001/00039
d D 1.5 85/06/25 20:12:50 kre 5 4
c make /usr/lib/bmac if it doesn't exist
e
s 00001/00001/00039
d D 1.4 85/06/11 12:48:37 garrison 4 3
c put keywords back in
e
s 00002/00002/00038
d D 1.3 85/06/11 12:46:54 garrison 3 2
c Changed install command to reduce problems with access rights.
e
s 00004/00000/00036
d D 1.2 84/01/21 09:36:05 rrh 2 1
c add stdafull
e
s 00036/00000/00000
d D 1.1 84/01/21 09:33:51 rrh 1 0
c date and time created 84/01/21 09:33:51 by rrh
e
u
U
t
T
I 2
#
D 3
#	%W%	(Berkeley)	%E%
E 3
I 3
D 4
#	@(#)Makefile	1.2	(Berkeley)	84/01/21
E 4
I 4
#	%W%	%E%
E 4
E 3
#
E 2
I 1
D 6
DEST	      = $(DESTDIR)/usr/lib/bmac
E 6
I 6
DEST	      = $(DESTDIR)/usr/new/lib/bmac
E 6

MAKEFILE      = Makefile

PRINT	      = vtroff

SRCS	      = bib.astro \
I 7
		bib.compsurv \
E 7
		bib.foot \
		bib.hnf \
		bib.list \
		bib.opena \
		bib.openn \
		bib.spe \
		bib.spe2 \
		bib.stda \
I 2
		bib.stdafull \
E 2
		bib.stdn \
		bib.stdsn \
		bib.supn \
		bibinc.fullnames \
		bibinc.publishers \
		bibinc.shortnames \
		bibmac.me \
		bmac.open \
		bmac.std \
		common

all:;

clean:;

depend:;	@mkmf -f $(MAKEFILE)

D 5
install:;	@echo Installing $(SRCS) in $(DEST)
E 5
I 5
install:	$(DEST)
		@echo Installing $(SRCS) in $(DEST)
E 5
D 3
		@for i in $(SRCS); do cp $$i $(DEST)/$$i; done
E 3
I 3
		-for i in $(SRCS); do rm -f $(DEST)/$$i; cp $$i $(DEST)/$$i; done
I 5

$(DEST):
		mkdir $(DEST)
E 5
E 3

update:;
E 1
