h17413
s 00011/00009/00010
d D 6.3 87/06/21 14:51:23 bostic 4 2
c new template
e
s 00011/00010/00009
d R 6.3 87/06/21 14:48:59 bostic 3 2
c new template
e
s 00001/00001/00018
d D 6.2 85/05/28 18:37:30 mckusick 2 1
c syntax
e
s 00019/00000/00000
d D 6.1 85/05/28 15:08:53 mckusick 1 0
c man macros distributed with 4.3BSD beta
e
u
U
f b 
t
T
I 1
#
D 4
# Copyright (c) 1985 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
#	%W%	(Berkeley)	%G%
E 4
#
D 4
#
#  Makefile for -man macros
#

E 4
I 4
CFLAGS=	-O
LIBC=	/lib/libc.a
E 4
SRCS=	tmac.an tmac.an.new tmac.an6n tmac.an6t

D 4
all:	${SRCS}
E 4
I 4
all:
E 4

D 4
install:${SRCS}
D 2
	for i in ${SRCS} do (install -c $$i ${DESTDIR}/usr/lib/tmac/$$i); done
E 2
I 2
	for i in ${SRCS}; do (install -c $$i ${DESTDIR}/usr/lib/tmac/$$i); done
E 4
I 4
install: FRC
	for i in ${SRCS}; do \
		(install -c -o bin -g bin -m 644 $$i ${DESTDIR}/usr/lib/tmac/$$i); \
	done
E 4
E 2

clean:
I 4
depend:
FRC:
E 4
E 1
