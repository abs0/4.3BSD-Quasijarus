h38692
s 00002/00002/00012
d D 6.2 2012/07/26 02:07:20 msokolov 2 1
c BI font used; added pstfinish for the thumb index label
e
s 00014/00000/00000
d D 6.1 04/09/17 22:36:23 msokolov 1 0
c date and time created 04/09/17 22:36:23 by msokolov
e
u
U
t
T
I 1
# Makefile for tbl doc (USD:28)
#
#	%W%	(Berkeley)	%E%

SRC=	tbl
D 2
MACROS=	-ms
E 2
I 2
TROPTS=	-fR,I,B,BI,S -ms
E 2

all:	tbl.ps

tbl.ps:	${SRC}
D 2
	tbl ${SRC} | pseqn | pstroff ${MACROS} - > $@
E 2
I 2
	tbl ${SRC} | pseqn | pstroff ${TROPTS} - | pstfinish -l USD:28-%l > $@
E 2

clean:
	rm -f *.ps errs
E 1
