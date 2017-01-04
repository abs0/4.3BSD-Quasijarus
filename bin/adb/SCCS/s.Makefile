h56569
s 00010/00005/00028
d D 5.3 88/07/09 11:22:56 bostic 3 2
c install approved copyright notice
e
s 00010/00007/00023
d D 5.2 88/03/30 16:12:16 bostic 2 1
c clean up scripts; clean out /usr/lib/adb
e
s 00030/00000/00000
d D 5.1 88/03/30 14:27:35 bostic 1 0
c date and time created 88/03/30 14:27:35 by bostic
e
u
U
t
T
I 1
#
# Copyright (c) 1988 Regents of the University of California.
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
D 2
DESTDIR= 
E 2
I 2
SUBDIR=	scripts scripts.${MACHINE} adb.${MACHINE}
E 2

all: FRC
D 2
	cd adb.${MACHINE}; make ${MFLAGS}
E 2
I 2
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS}); done
E 2

depend: FRC
D 2
	cd adb.${MACHINE}; make ${MFLAGS} depend
E 2
I 2
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
E 2

I 2
SCRIPTDIR=	/usr/lib/adb
E 2
install: FRC
D 2
	cd adb.${MACHINE}; make DESTDIR=${DESTDIR} install
	cd scripts; make DESTDIR=${DESTDIR} install
	cd scripts.${MACHINE}; make DESTDIR=${DESTDIR} install
E 2
I 2
	rm -rf ${SCRIPTDIR}
	mkdir ${DESTDIR}/${SCRIPTDIR}
	chown bin.bin ${DESTDIR}/${SCRIPTDIR}
	chmod 755 ${DESTDIR}/${SCRIPTDIR}
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} install); done
E 2

clean: FRC
D 2
	cd adb.${MACHINE}; make ${MFLAGS} clean
E 2
I 2
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 2

FRC:
E 1
