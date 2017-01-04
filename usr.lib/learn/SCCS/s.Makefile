h57781
s 00001/00001/00028
d D 4.5 99/10/02 21:42:00 msokolov 7 6
c group bin, not staff
e
s 00003/00002/00026
d D 4.4 87/10/03 14:37:02 bostic 6 5
c get rid of ignored exit on install
e
s 00015/00017/00013
d D 4.3 87/07/24 07:08:05 bostic 5 2
c new template
e
s 00014/00011/00019
d R 4.3 87/07/22 09:04:59 bostic 4 2
c new template
e
s 00011/00008/00022
d R 4.3 87/06/19 09:16:35 bostic 3 2
c new template
e
s 00001/00001/00029
d D 4.2 83/07/08 00:15:11 sam 2 1
c bin is created at install time
e
s 00030/00000/00000
d D 4.1 83/07/08 00:13:23 sam 1 0
c date and time created 83/07/08 00:13:23 by sam
e
u
U
t
T
I 1
D 5
#	%M%	%I%	%E%
E 5
#
D 5
# Make install will build the learn lesson libraries
# from this directory. 
E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 5
#
I 5
#	%W%	(Berkeley)	%G%
#
E 5
D 2
LESSONS=C bin editor eqn files macros morefiles
E 2
I 2
LESSONS=C editor eqn files macros morefiles
E 2
FILES=	Linfo Xinfo
D 5
DESTDIR=
E 5

all:

D 5
install: ${LESSONS} ${FILES}
E 5
I 5
install: FRC
E 5
D 6
	-mkdir ${DESTDIR}/usr/lib/learn ${DESTDIR}/usr/lib/learn/log \
D 5
		${DESTDIR}/usr/lib/learn/bin
E 5
I 5
		${DESTDIR}/usr/lib/learn/bin > /dev/null 2>&1
E 6
I 6
	-[ -d ${DESTDIR}/usr/lib/learn ] || mkdir ${DESTDIR}/usr/lib/learn
	-[ -d ${DESTDIR}/usr/lib/learn/log ] || mkdir ${DESTDIR}/usr/lib/learn/log
	-[ -d ${DESTDIR}/usr/lib/learn/bin ] || mkdir ${DESTDIR}/usr/lib/learn/bin
E 6
E 5
	chmod 755 ${DESTDIR}/usr/lib/learn ${DESTDIR}/usr/lib/learn/log \
		${DESTDIR}/usr/lib/learn/bin
D 5
	chown root ${DESTDIR}/usr/lib/learn ${DESTDIR}/usr/lib/learn/log \
E 5
I 5
D 7
	chown root.staff ${DESTDIR}/usr/lib/learn ${DESTDIR}/usr/lib/learn/log \
E 7
I 7
	chown root.bin ${DESTDIR}/usr/lib/learn ${DESTDIR}/usr/lib/learn/log \
E 7
E 5
		${DESTDIR}/usr/lib/learn/bin
D 5
	chgrp staff ${DESTDIR}/usr/lib/learn ${DESTDIR}/usr/lib/learn/log \
		${DESTDIR}/usr/lib/learn/bin
	@for i in ${FILES}; do \
		echo copy $$i; \
		install -c -m 644 $$i ${DESTDIR}/usr/lib/learn/$$i; \
	done
	@for i in ${LESSONS}; do \
		echo tar $$i lessons; \
		tar cf - $$i | (cd ${DESTDIR}/usr/lib/learn; tar xpf -); \
	done
E 5
I 5
	install -c -o bin -g bin -m 644 Linfo ${DESTDIR}/usr/lib/learn/Linfo
	install -c -o bin -g bin -m 644 Xinfo ${DESTDIR}/usr/lib/learn/Xinfo
	tar cf - ${LESSONS} | (cd ${DESTDIR}/usr/lib/learn; tar xpf -);
E 5

clean:
I 5
depend:
lint:
tags:
FRC:
E 5
E 1
