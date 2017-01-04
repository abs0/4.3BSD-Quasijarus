h24119
s 00014/00003/00056
d D 5.6 88/06/18 13:58:31 bostic 14 13
c install approved copyright notice
e
s 00049/00016/00010
d D 5.5 87/11/16 11:14:13 bostic 13 9
c new template
e
s 00047/00016/00010
d R 5.5 87/06/02 23:12:54 bostic 12 9
c new template
e
s 00047/00016/00010
d R 5.5 87/06/02 21:51:19 bostic 11 9
c new template
e
s 00047/00016/00010
d R 5.5 87/06/02 20:36:11 bostic 10 9
c new template
e
s 00002/00000/00024
d D 5.4 87/05/31 20:40:10 bostic 9 8
c added depend label
e
s 00002/00002/00022
d D 5.3 85/09/07 14:57:05 mckusick 8 7
c strip when installing
e
s 00000/00002/00024
d D 5.2 85/05/28 14:52:47 dist 7 6
c Add copyright
e
s 00007/00000/00019
d D 5.1 85/05/28 14:51:29 dist 6 5
c Add copyright
e
s 00001/00001/00018
d D 4.5 83/06/12 02:46:44 sam 5 4
c new signals
e
s 00001/00001/00018
d D 4.4 83/04/03 15:13:18 sam 4 3
c move implog to /etc
e
s 00000/00005/00019
d D 4.3 82/12/25 21:16:47 sam 3 2
c no more asm.sed
e
s 00003/00002/00021
d D 4.2 82/10/21 14:34:50 sam 2 1
c DESTDIR
e
s 00023/00000/00000
d D 4.1 82/10/08 00:12:22 sam 1 0
c date and time created 82/10/08 00:12:22 by sam
e
u
U
t
T
I 6
D 7
#
E 7
D 13
# Copyright (c) 1983 Regents of the University of California.
E 13
I 13
#
# Copyright (c) 1987 Regents of the University of California.
E 13
D 14
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 14
I 14
# All rights reserved.
E 14
#
D 13
#	%W% (Berkeley) %G%
E 13
I 13
D 14
#	%W%	(Berkeley)	%G%
E 14
I 14
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
#	%W% (Berkeley) %G%
E 14
E 13
#
E 6
I 1
D 7
# %W% %G%
E 7
D 13
ALL=	implog implogd
I 2
DESTDIR=
E 2
CFLAGS=-O
E 13
I 13
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	implog.c implogd.c
OBJS1=	implog.o
OBJS2=	implogd.o
E 13

D 13
all:	${ALL}
E 13
I 13
all: implog implogd
E 13

D 3
.c.o:
	${CC} -S ${CFLAGS} $*.c
	sed -f ../asm.sed $*.s | as -o $*.o
	rm -f $*.s

E 3
D 13
implog:	implog.o
D 5
	${CC} implog.o -o implog -ljobs
E 5
I 5
	${CC} implog.o -o implog
E 13
I 13
implog: ${OBJS1} ${LIBC}
	${CC} ${OBJS1} -o $@
E 13
E 5

D 13
implogd: implogd.o
	${CC} implogd.o -o implogd
E 13
I 13
implogd: ${OBJS2} ${LIBC}
	${CC} ${OBJS2} -o $@
E 13

D 13
clean:
	rm -f ${ALL} *.o *.s errs core a.out t.?
E 13
I 13
clean: FRC
	rm -f ${OBJS1} ${OBJS2} core implog implogd
E 13

D 13
install: ${ALL}
D 2
	install implog /usr/ucb
	install implogd /etc
E 2
I 2
D 4
	install implog ${DESTDIR}/usr/ucb
E 4
I 4
D 8
	install implog ${DESTDIR}/etc
E 4
	install implogd ${DESTDIR}/etc
E 8
I 8
	install -s implog ${DESTDIR}/etc
	install -s implogd ${DESTDIR}/etc
E 13
I 13
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 13
I 9

D 13
depend:
E 13
I 13
install: FRC
	install -s -o bin -g bin -m 755 implog ${DESTDIR}/etc/implog
	install -s -o bin -g bin -m 755 implogd ${DESTDIR}/etc/implogd

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

implog.o: implog.c /usr/include/stdio.h /usr/include/signal.h
implog.o: /usr/include/machine/trap.h /usr/include/sgtty.h
implog.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
implog.o: /usr/include/sys/ttydev.h /usr/include/sys/time.h /usr/include/time.h
implog.o: /usr/include/sys/types.h /usr/include/sys/stat.h
implog.o: /usr/include/sys/socket.h /usr/include/netinet/in.h
implog.o: /usr/include/netimp/if_imp.h
implogd.o: implogd.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
implogd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
implogd.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/sys/param.h
implogd.o: /usr/include/sys/types.h /usr/include/signal.h
implogd.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
implogd.o: /usr/include/sys/socket.h /usr/include/sys/syslog.h
implogd.o: /usr/include/sys/file.h /usr/include/netinet/in.h
implogd.o: /usr/include/netimp/if_imp.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 13
E 9
E 8
E 2
E 1
