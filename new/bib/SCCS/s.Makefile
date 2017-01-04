h28974
s 00014/00000/00000
d D 2.1 88/04/08 14:50:40 mckusick 1 0
c date and time created 88/04/08 14:50:40 by mckusick
e
u
U
t
T
I 1
#	%W% (Berkeley) %G%
#
DESTDIR=

all:
	cd src; make ${MFLAGS}

install: all
	cd src; make ${MFLAGS} DESTDIR=${DESTDIR} install
	cd macs; make ${MFLAGS} DESTDIR=${DESTDIR} install
	cd man; make ${MFLAGS} DESTDIR=${DESTDIR} install

clean:
	cd src; make ${MFLAGS} clean
E 1
