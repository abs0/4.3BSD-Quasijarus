h23016
s 00001/00001/00016
d D 4.6 85/06/25 19:03:36 kre 8 7
c install this (old) version as libodbm.a (-lodbm)
e
s 00004/00000/00013
d D 4.5 85/05/30 22:50:52 sam 7 6
c add tags
e
s 00000/00002/00013
d D 4.4 83/12/02 15:55:00 ralph 6 3
c dbm.h is now in /usr/src/include.
e
s 00000/00001/00014
d R 4.4 83/12/02 15:43:04 ralph 5 3
c dbm.h is now in /usr/src/include.
e
s 00001/00001/00014
d R 4.4 83/11/12 11:05:23 sam 4 3
c from sjk@sri-spam
e
s 00002/00001/00013
d D 4.3 83/10/17 09:19:40 karels 3 2
c need to do cc -c (or will try to load)
e
s 00005/00006/00009
d D 4.2 83/08/20 12:27:15 sam 2 1
c cleanup
e
s 00015/00000/00000
d D 4.1 83/06/27 14:01:04 sam 1 0
c date and time created 83/06/27 14:01:04 by sam
e
u
U
t
T
I 1
#	%M%	%I%	%E%
#
CFLAGS=-O
I 7
TAGSFILE=tags
E 7

D 2
libdbm.a: dbm.o
	mv dbm.o libdbm.a
E 2
I 2
libdbm.a: dbm.c
D 6
libdbm.a: dbm.h
E 6
D 3
	${CC} -o libdbm.a ${CFLAGS} dbm.c
E 3
I 3
	${CC} -c ${CFLAGS} dbm.c
	mv dbm.o libdbm.a
E 3
E 2

D 2
dbm.o : dbm.h

E 2
install:
D 2
	install -c libdbm.a $(DESTDIR)/usr/lib
E 2
I 2
D 8
	install -m 644 libdbm.a $(DESTDIR)/usr/lib
E 8
I 8
	install -m 644 libdbm.a $(DESTDIR)/usr/lib/libodbm.a
E 8
I 7

tags:
	ctags -a -f ${TAGSFILE} `pwd`/dbm.c
E 7
E 2
D 6
	install -c dbm.h $(DESTDIR)/usr/include
E 6

clean:
D 2
	rm -f libdbm.a
E 2
I 2
	rm -f libdbm.a errs a.out core
E 2
E 1
