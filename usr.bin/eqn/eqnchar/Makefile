# Makefile for printing eqnchar refcard
# and for installing the eqnchar files in /usr/pub
#
#	@(#)Makefile	1.1 (Berkeley) 2012/02/16

SRCS=	eqnchar eqnchar.refcard

all:	refcard.ps

refcard.ps:	${SRCS}
	../pseqn/eqn ${SRCS} | pstroff > $@

clean:
	rm -f refcard.ps

depend:

install:
	install -c -o bin -g bin -m 444 ${SRCS} ${DESTDIR}/usr/pub
