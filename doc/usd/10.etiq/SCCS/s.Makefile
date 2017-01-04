h12574
s 00002/00002/00012
d D 6.4 2012/03/12 02:35:48 msokolov 4 3
c s/SS/ZD/ for \(rh
e
s 00003/00003/00011
d D 6.3 2012/02/19 06:19:06 msokolov 3 2
c need pstfinish to handle \(rh and labels for the thumb index
e
s 00008/00007/00006
d D 6.2 04/10/23 06:12:59 msokolov 2 1
c ditroff => pstroff
e
s 00013/00000/00000
d D 6.1 04/10/23 06:04:01 msokolov 1 0
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
D 3
FMTOPTS=
E 3
I 3
D 4
FMTOPTS=-fR,I,B,S,SS
E 4
I 4
FMTOPTS=-fR,I,B,S,ZD
E 4
E 3
D 2
LPR=
E 2

D 2
manner: manner.mn tmac.n
	$(FMT) $(PRINTER) $(FMTOPTS) tmac.n manner.mn
manner.aps: manner.mn tmac.n
	$(FMT) $(PRINTER) $(FMTOPTS) tmac.n manner.mn | $(LPR)
E 2
I 2
all:	manner.ps

manner.ps: manner.mn tmac.n
D 3
	$(FMT) $(FMTOPTS) tmac.n manner.mn > $@
E 3
I 3
D 4
	$(FMT) $(FMTOPTS) tmac.n manner.mn | pstfinish -S -l USD:10-%l > $@
E 4
I 4
	$(FMT) $(FMTOPTS) tmac.n manner.mn | pstfinish -l USD:10-%l > $@
E 4
E 3

clean:
	rm -f *.ps errs
E 2
E 1
