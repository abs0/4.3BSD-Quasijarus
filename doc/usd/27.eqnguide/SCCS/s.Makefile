h20277
s 00002/00003/00012
d D 6.5 2012/07/25 21:23:34 msokolov 5 4
c back to St for \(bs
c pstfinish label for the thumb index
e
s 00002/00002/00013
d D 6.4 10/10/10 00:52:09 msokolov 4 3
c use the new SS font
e
s 00002/00005/00013
d D 6.3 10/08/23 21:19:18 msokolov 3 2
c new pstmerge/pstfinish
e
s 00006/00002/00012
d D 6.2 04/11/05 06:11:30 msokolov 2 1
c use St font for \(bs
e
s 00014/00000/00000
d D 6.1 04/09/17 22:19:10 msokolov 1 0
c date and time created 04/09/17 22:19:10 by msokolov
e
u
U
t
T
I 1
# Makefile for eqn guide (USD:27)
#
#	%W%	(Berkeley)	%E%

SRCS=	g.mac g0 g1 g2 g3 g4 g5
I 2
D 4
TROPTS=	-fR,I,B,St
E 4
I 4
D 5
TROPTS=	-fR,I,B,S,SS
E 4
E 2
MACROS=	-ms
E 5
I 5
TROPTS=	-fR,I,B,St -ms
E 5

all:	eqnguide.ps

D 2
eqnguide.ps:	${SRCS}
	pseqn ${SRCS} | pstroff ${MACROS} - > $@
E 2
I 2
D 3
eqnguide1.ps:	${SRCS}
	pseqn ${SRCS} | pstroff ${TROPTS} ${MACROS} - > $@

eqnguide.ps:	eqnguide1.ps
	pstmerge -T eqnguide1.ps > $@
E 3
I 3
eqnguide.ps:	${SRCS}
D 4
	pseqn ${SRCS} | pstroff ${TROPTS} ${MACROS} - | pstfinish > $@
E 4
I 4
D 5
	pseqn ${SRCS} | pstroff ${TROPTS} ${MACROS} - | pstfinish -S > $@
E 5
I 5
	pseqn ${SRCS} | pstroff ${TROPTS} - | pstfinish -l USD:27-%l > $@
E 5
E 4
E 3
E 2

clean:
	rm -f *.ps errs
E 1
