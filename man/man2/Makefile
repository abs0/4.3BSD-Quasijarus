#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#
#	@(#)Makefile	5.5 (Berkeley) 10/20/04
#
MDIR=	/usr/man/man2

all:

psman: FRC
	for i in *.2; do echo $$i; pstroff -man $$i > $$i.ps; done

clean: FRC
	rm -f *.ps

install: FRC
	cd ${DESTDIR}${MDIR}; rm -f *.2
	install -c -o bin -g bin -m 444 *.2 ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.2 ${DESTDIR}${MDIR}

FRC:
