h54006
s 00011/00006/00046
d D 5.4 04/12/07 20:01:21 msokolov 7 6
c add smgetty
e
s 00039/00015/00013
d D 5.3 87/06/02 21:49:26 bostic 6 4
c new template
e
s 00039/00015/00013
d R 5.3 87/06/02 20:23:04 bostic 5 4
c new template
e
s 00002/00000/00026
d D 5.2 87/05/31 20:39:21 bostic 4 3
c added depend label
e
s 00006/00001/00020
d D 5.1 85/04/29 12:04:52 dist 3 2
c Add copyright
e
s 00002/00001/00019
d D 4.2 85/02/05 08:45:48 ralph 2 1
c added get_date() for putting date in login banner (%d).
e
s 00020/00000/00000
d D 4.1 83/07/06 00:11:14 sam 1 0
c date and time created 83/07/06 00:11:14 by sam
e
u
U
t
T
I 1
D 3
#	%M%	%I%	%E%
E 3
I 3
#
D 6
# Copyright (c) 1980 Regents of the University of California.
E 6
I 6
# Copyright (c) 1987 Regents of the University of California.
E 6
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 6
#	%W% (Berkeley) %G%
E 6
I 6
#	%W%	(Berkeley)	%G%
E 6
E 3
#
D 6
DESTDIR=
E 6
CFLAGS=	-O
I 6
LIBC=	/lib/libc.a
SRCS=	main.c init.c subr.c gettytab.c get_date.c
E 6
D 2
OBJS=	main.o init.o subr.o gettytab.o
E 2
I 2
OBJS=	main.o init.o subr.o gettytab.o get_date.o
I 7
PROGS=	getty smgetty
E 7
E 2

D 6
all:	getty
E 6
I 6
D 7
all: getty
E 7
I 7
all: ${PROGS}
E 7
E 6

D 6
getty:	${OBJS}
	${CC} -o getty ${OBJS}
E 6
I 6
getty:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 6

I 7
smgetty: smgetty.c
	${CC} -o $@ ${CFLAGS} smgetty.c

E 7
D 6
install: all
	install -s getty ${DESTDIR}/etc/getty
I 2
	install -c -m 444 gettytab ${DESTDIR}/etc/gettytab
E 6
I 6
clean: FRC
D 7
	rm -f ${OBJS} core getty
E 7
I 7
	rm -f ${OBJS} ${PROGS} core a.out errs
E 7
E 6
E 2

D 6
clean:
	rm -f getty ${OBJS} a.out core errs
E 6
I 6
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 6

I 4
D 6
depend:
E 6
I 6
install: FRC
D 7
	install -s -o bin -g bin -m 755 getty ${DESTDIR}/etc/getty
	install -c -o bin -g bin -m 444 gettytab ${DESTDIR}/etc/gettytab
E 7
I 7
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/etc
	install -c -o bin -g bin -m 444 gettytab ${DESTDIR}/etc
E 7
E 6

E 4
D 6
main.o: gettytab.h
init.o: gettytab.h
subr.o: gettytab.h
E 6
I 6
lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

main.o: main.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
main.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 7
main.o: /usr/include/signal.h /usr/include/ctype.h /usr/include/setjmp.h
main.o: /usr/include/syslog.h /usr/include/sys/file.h gettytab.h
E 7
I 7
main.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/ctype.h
main.o: /usr/include/setjmp.h /usr/include/syslog.h /usr/include/sys/file.h
main.o: gettytab.h
E 7
init.o: init.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
init.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h gettytab.h
subr.o: subr.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
subr.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h gettytab.h
subr.o: /usr/include/sys/time.h /usr/include/time.h
gettytab.o: gettytab.c /usr/include/ctype.h
get_date.o: get_date.c /usr/include/stdio.h /usr/include/sys/time.h
get_date.o: /usr/include/time.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 6
E 1
