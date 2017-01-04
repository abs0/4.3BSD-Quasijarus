#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
#
#	@(#)Makefile	5.12 (Berkeley) 10/20/04
#
MDIR=	/usr/man/man1

all:

psman: FRC
	for i in *.1 *.1?; do echo $$i; pstroff -man $$i > $$i.ps; done

clean: FRC
	rm -f *.ps

install: FRC
	cd ${DESTDIR}${MDIR}; rm -f *.1 *.1?
	install -c -o bin -g bin -m 444 *.1 *.1? ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.1 links/*.1? ${DESTDIR}${MDIR}

FRC:
