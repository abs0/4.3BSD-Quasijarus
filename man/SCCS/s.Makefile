h00984
s 00001/00001/00047
d D 5.8 04/10/22 06:50:51 msokolov 8 7
c clean man0 and psman too
e
s 00002/00000/00046
d D 5.7 04/10/21 08:24:56 msokolov 7 6
c finish psman
e
s 00001/00005/00045
d D 5.6 04/10/21 01:16:34 msokolov 6 5
c back to 4.3BSD whatis database
e
s 00006/00008/00044
d D 5.5 04/10/20 20:15:30 msokolov 5 4
c back to 4.3BSD /usr/man format
e
s 00001/00002/00051
d D 5.4 99/10/03 12:58:30 msokolov 4 3
c clean out the man pages on the big make clean too
e
s 00010/00005/00043
d D 5.3 88/07/09 11:25:13 bostic 3 2
c install approved copyright notice
e
s 00002/00002/00046
d D 5.2 88/02/22 08:52:07 bostic 2 1
c add man8/tahoe
e
s 00048/00000/00000
d D 5.1 87/12/12 18:29:20 bostic 1 0
c date and time created 87/12/12 18:29:20 by bostic
e
u
U
f b 
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 3
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
#
#	%W% (Berkeley) %G%
#
D 5
DIRS=	man1 man2 man3 man3f man4 man4/vax man4/tahoe man5 man6 \
D 2
	man7 man8 man8/vax
E 2
I 2
	man7 man8 man8/vax man8/tahoe
E 2
CDIRS=	cat1 cat2 cat3 cat3f cat4 cat4/vax cat4/tahoe cat5 cat6 \
D 2
	cat7 cat8 cat8/vax
E 2
I 2
	cat7 cat8 cat8/vax man8/tahoe
E 2
LCDIRS=	cat1 cat2 cat3 cat4 cat5 cat6 cat7 cat8
E 5
I 5
DIRS=	man1 man2 man3 man4 man5 man6 man7 man8
E 5

D 5
all: scriptinstall FRC
E 5
I 5
all:

psman: FRC
E 5
	for i in ${DIRS}; do \
D 5
		(cd $$i; make ${MFLAGS}); \
E 5
I 5
		(cd $$i; make ${MFLAGS} psman); \
E 5
	done
I 7
	cd man0; make ${MFLAGS}
	cd psman; make ${MFLAGS}
E 7

scriptinstall: FRC
D 6
	install -c -o bin -g bin -m 444 makewhatis.sed ${DESTDIR}/usr/man/makewhatis.sed
E 6
	install -c -o bin -g bin -m 755 manroff ${DESTDIR}/usr/man/manroff

D 5
install: FRC
E 5
I 5
install: scriptinstall FRC
E 5
	for i in ${DIRS}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done
D 6
	for file in `find /usr/man -type f -name '*.0' -print`; do \
		sed -n -f /usr/man/makewhatis.sed $$file; \
	done | sort -u > whatis.db
	install -o bin -g bin -m 444 whatis.db ${DESTDIR}/usr/man/whatis
E 6
I 6
	/usr/lib/makewhatis ${DESTDIR}/usr/man
E 6
	install -c -o bin -g bin -m 444 man.template ${DESTDIR}/usr/man/man.template

D 4
manclean: FRC
E 4
I 4
clean manclean: FRC
E 4
D 8
	for i in ${DIRS}; do \
E 8
I 8
	for i in ${DIRS} man0 psman; do \
E 8
		(cd $$i; make ${MFLAGS} clean); \
	done

D 4
clean:
E 4
depend:
lint:
tags:
FRC:
E 1
