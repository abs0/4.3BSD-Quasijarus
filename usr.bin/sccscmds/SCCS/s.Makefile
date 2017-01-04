h34456
s 00001/00001/00017
d D 4.8 99/01/07 01:23:43 msokolov 8 7
c SCCS is not "local" any more. /usr/local/lib => /usr/lib
e
s 00000/00001/00018
d D 4.7 99/01/03 20:14:11 msokolov 7 6
c no more doc, the man pages are now in their standard location
e
s 00001/00001/00018
d D 4.6 89/05/10 22:43:13 bostic 6 5
c add cleandir label
e
s 00002/00000/00017
d D 4.5 88/02/03 08:44:53 bostic 5 4
c add depend label
e
s 00001/00000/00016
d D 4.4 87/07/27 10:39:47 bostic 4 3
c make docs too
e
s 00002/00001/00014
d D 4.3 87/02/15 21:10:25 lepreau 3 2
c clean better; fix mode of sccs.hf
e
s 00001/00001/00014
d D 4.2 86/01/02 16:11:15 mckusick 2 1
c use -c flag
e
s 00015/00000/00000
d D 4.1 82/10/25 01:14:49 mckusick 1 0
c date and time created 82/10/25 01:14:49 by mckusick
e
u
U
t
T
I 1
#	%W%	(Berkeley)	%E%
#
all:
	cd util; make $(MFLAGS)
	cd com; make $(MFLAGS)
	cd cmd; make $(MFLAGS)

install:
	cd cmd; make $(MFLAGS) DESTDIR=$(DESTDIR) install
I 4
D 7
	cd doc; make ${MFLAGS} DESTDIR=${DESTDIR} install
E 7
E 4
D 2
	install sccs.hf ${DESTDIR}/usr/local/lib/sccs.hf
E 2
I 2
D 3
	install -c sccs.hf ${DESTDIR}/usr/local/lib/sccs.hf
E 3
I 3
D 8
	install -c -m 644 sccs.hf ${DESTDIR}/usr/local/lib/sccs.hf
E 8
I 8
	install -c -m 644 sccs.hf ${DESTDIR}/usr/lib/sccs.hf
E 8
E 3
E 2

D 6
clean:
E 6
I 6
clean cleandir:
E 6
I 3
	rm -f lib*.a errs
E 3
	cd util; make $(MFLAGS) clean
	cd com; make $(MFLAGS) clean
	cd cmd; make $(MFLAGS) clean
I 5

depend:
E 5
E 1
