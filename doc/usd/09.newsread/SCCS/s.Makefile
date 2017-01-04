h07421
s 00002/00002/00015
d D 6.3 2012/02/19 06:03:15 msokolov 3 2
c labels for the thumb index
e
s 00010/00009/00007
d D 6.2 04/10/23 06:00:04 msokolov 2 1
c ditroff => pstroff
e
s 00016/00000/00000
d D 6.1 04/10/23 05:53:21 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 6.1
e
u
U
t
T
I 1
D 3
#	%W% (Berkeley) %G%
E 3
I 3
#	%W% (Berkeley) %E%
E 3
#
# make the various documents

D 2
FMT=ditroff
PRINTER=-Pdp
E 2
I 2
FMT=pstroff
E 2
FMTOPTS=
D 2
LPR=
E 2

D 2
howto: howto.mn tmac.n
	$(FMT) $(PRINTER) $(FMTOPTS) tmac.n howto.mn
howto.aps: howto.mn tmac.n
	$(FMT) $(PRINTER) $(FMTOPTS) tmac.n howto.mn | $(LPR)
E 2
I 2
all:	howto.ps
E 2

D 2
copyright: copyright.mn tmac.n
	$(FMT) $(PRINTER) $(FMTOPTS) tmac.n copyright.mn
E 2
I 2
howto.ps: howto.mn tmac.n
D 3
	$(FMT) $(FMTOPTS) tmac.n howto.mn > $@
E 3
I 3
	$(FMT) $(FMTOPTS) tmac.n howto.mn | pstfinish -l USD:9-%l > $@
E 3

copyright.ps: copyright.mn tmac.n
	$(FMT) $(FMTOPTS) tmac.n copyright.mn > $@

clean:
	rm -f *.ps errs
E 2
E 1
