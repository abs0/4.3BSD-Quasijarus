h35095
s 00019/00000/00000
d D 1.1 2012/02/16 05:24:39 msokolov 1 0
c date and time created 2012/02/16 05:24:39 by msokolov
e
u
U
t
T
I 1
# Makefile for printing eqnchar refcard
# and for installing the eqnchar files in /usr/pub
#
#	%W% (Berkeley) %E%

SRCS=	eqnchar eqnchar.refcard

all:	refcard.ps

refcard.ps:	${SRCS}
	../pseqn/eqn ${SRCS} | pstroff > $@

clean:
	rm -f refcard.ps

depend:

install:
	install -c -o bin -g bin -m 444 ${SRCS} ${DESTDIR}/usr/pub
E 1
