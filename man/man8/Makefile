#
# Copyright (c) 1988 Regents of the University of California.
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
#	@(#)Makefile	5.8 (Berkeley) 10/20/04
#
MDIR=	/usr/man/man8
SUBDIR=	tahoe vax

all:

psman: FRC
	for i in *.8 *.8c; do echo $$i; pstroff -man $$i > $$i.ps; done
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} psman); done

clean: FRC
	rm -f *.ps
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done

install: FRC
	cd ${DESTDIR}${MDIR}; rm -f *
	install -c -o bin -g bin -m 444 *.8 *.8c ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.8 links/*.8c ${DESTDIR}${MDIR}
	cd ${MACHINE}; make ${MFLAGS} DESTDIR=${DESTDIR} install

FRC:
