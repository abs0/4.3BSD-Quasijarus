h37532
s 00090/00041/00031
d D 5.6 87/06/03 10:02:02 bostic 26 20
c new template
e
s 00090/00041/00031
d R 5.6 87/06/02 21:47:39 bostic 25 20
c new template
e
s 00090/00041/00031
d R 5.6 87/06/02 20:55:56 bostic 24 20
c new template
e
s 00089/00040/00032
d R 5.6 87/06/02 20:13:08 bostic 23 20
c new template
e
s 00089/00040/00032
d R 5.6 87/06/02 20:02:15 bostic 22 20
c new template
e
s 00088/00039/00033
d R 5.6 87/06/02 19:53:49 bostic 21 20
c new template
e
s 00002/00000/00070
d D 5.5 87/05/31 20:38:18 bostic 20 19
c added depend label
e
s 00002/00002/00068
d D 5.4 86/05/28 11:08:03 mckusick 19 18
c finally no longer need setuid root
e
s 00001/00001/00069
d D 5.3 85/10/15 21:01:13 mckusick 18 17
c fix comment (from sjk@sri-spam)
e
s 00002/00002/00068
d D 5.2 85/06/18 22:06:57 mckusick 17 15
c dumprestor.h moved to /usr/include/protocols/dumprestore.h
e
s 00002/00002/00068
d R 5.2 85/06/18 21:54:33 mckusick 16 15
c restore.h moves to /usr/include/protocols/dumprestore.h
e
s 00006/00001/00064
d D 5.1 85/05/06 11:36:10 dist 15 14
c Add copyright
e
s 00009/00004/00056
d D 1.14 85/02/19 16:26:22 mckusick 14 13
c dumptape.c and dumprtape.c have been merged
e
s 00002/00002/00058
d D 1.13 84/10/05 16:04:39 mckusick 13 12
c update install mode
e
s 00002/00002/00058
d D 1.12 83/07/03 20:22:03 sam 12 11
c include fix
e
s 00001/00001/00059
d D 1.11 83/06/12 02:43:56 sam 11 10
c new signals == no libjobs
e
s 00005/00003/00055
d D 1.10 83/02/11 12:58:17 sam 10 9
c merge from sun
e
s 00001/00003/00057
d D 1.9 82/10/11 18:05:00 mckusick 9 8
c rcmd.o moves to libc.a
e
s 00018/00008/00042
d D 1.8 82/10/05 15:03:40 sam 8 7
c merge rdump with dump
e
s 00003/00001/00047
d D 1.7 82/06/05 17:14:13 mckusick 7 6
c include /usr/src/ucb/netser/rcmd.o
e
s 00007/00007/00041
d D 1.6 82/05/20 15:10:58 sam 6 5
c convert to calder
e
s 00004/00003/00044
d D 1.5 82/05/07 15:27:35 sam 5 4
c old stuff
e
s 00010/00004/00037
d D 1.4 82/02/23 12:56:29 mckusic 4 3
c convert to new directory format
e
s 00001/00001/00040
d D 1.3 81/02/20 15:58:58 wnj 3 2
c Remove -DERNIE from the makefile (by Robert Henry)
e
s 00001/00003/00040
d D 1.2 80/10/18 17:56:02 bill 2 1
c install in /etc
e
s 00043/00000/00000
d D 1.1 80/10/13 17:30:22 root 1 0
c date and time created 80/10/13 17:30:22 by root
e
u
U
t
T
I 1
D 12
# sccsid = "%W% (Berkeley) %G%"
E 12
I 12
D 15
#	%M%	%I%	%E%
E 15
I 15
#
D 26
# Copyright (c) 1980 Regents of the University of California.
E 26
I 26
# Copyright (c) 1987 Regents of the University of California.
E 26
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 26
#	%W% (Berkeley) %G%
E 26
I 26
#	%W%	(Berkeley)	%G%
E 26
E 15
E 12
#
#	dump.h			header file
D 18
#	dumpitime.c		reads /etc/ddate
E 18
I 18
#	dumpitime.c		reads /etc/dumpdates
E 18
#	dumpmain.c		driver
#	dumpoptr.c		operator interface
#	dumptape.c		handles the mag tape and opening/closing
#	dumptraverse.c		traverses the file system
#	unctime.c		undo ctime
#
#	DEBUG			use local directory to find ddate and dumpdates
#	TDEBUG			trace out the process forking
D 26
#
I 7
D 9
NETSER=	/usr/src/ucb/netser

E 9
E 7
PSRCS = \
D 4
	dump.h dumpmain.c dumptraverse.c dumptape.c dumpoptr.c dumpitime.c
E 4
I 4
D 5
	../../h/dumprestor.h dump.h \
E 5
I 5
D 17
	/usr/include/dumprestor.h dump.h \
E 17
I 17
	/usr/include/protocols/dumprestore.h dump.h \
E 17
E 5
	dumpmain.c dumptraverse.c dumptape.c dumpoptr.c dumpitime.c unctime.c
E 26
E 4

D 26
SRCS =  \
	dump.h dumpitime.c \
D 6
	dumpmain.c dumpoptr.c dumptape.c \
E 6
I 6
	dumpmain.c dumpoptr.c dumprmt.c dumprtape.c \
E 26
I 26
DFLAGS=
CFLAGS=	-O ${DFLAGS}
LIBC=	/lib/libc.a
PSRCS=	/usr/include/protocols/dumprestore.h dump.h dumpmain.c \
	dumptraverse.c dumptape.c dumpoptr.c dumpitime.c unctime.c
SRCS=	dump.h dumpitime.c dumpmain.c dumpoptr.c dumprmt.c dumptape.c \
E 26
E 6
	dumptraverse.c unctime.c
I 26
OBJS=	dumpitime.o dumpmain.o dumpoptr.o dumptape.o dumptraverse.o \
	unctime.o
ROBJS=	dumpitime.o dumprmain.o dumpoptr.o dumprmt.o dumprtape.o \
	dumptraverse.o unctime.o
E 26

D 8
OBJS = \
	dumpitime.o \
	dumpmain.o dumpoptr.o \
E 8
I 8
D 26
OBJS = dumpitime.o dumpmain.o dumpoptr.o \
	dumptape.o dumptraverse.o unctime.o
E 26
I 26
all: dump rdump
E 26

D 26
ROBJS = dumpitime.o dumprmain.o dumpoptr.o \
E 8
D 6
	dumptape.o dumptraverse.o unctime.o
E 6
I 6
D 7
	dumprmt.o dumprtape.o dumptraverse.o unctime.o
E 7
I 7
D 9
	dumprmt.o dumprtape.o dumptraverse.o unctime.o $(NETSER)/rcmd.o
E 9
I 9
	dumprmt.o dumprtape.o dumptraverse.o unctime.o
E 26
I 26
dump:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 26
E 9
E 7
E 6

D 3
DFLAGS = -DERNIE
E 3
I 3
D 26
DFLAGS =
E 3
D 4
CFLAGS = -O $(DFLAGS)
E 4
I 4
D 6
CFLAGS = -O -DKERNEL $(DFLAGS)
E 6
I 6
D 8
CFLAGS = -O $(DFLAGS) -DRDUMP
E 8
I 8
CFLAGS = -O $(DFLAGS)
E 26
I 26
rdump:	${ROBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${ROBJS}
E 26
E 8
E 6
E 4

D 6
dump:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o dump
E 6
I 6
D 8
rdump:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o rdump -ljobs
E 8
I 8
D 26
all: dump rdump
E 26
I 26
dumprmain.o: dumpmain.c
	${CC} -c -DRDUMP ${CFLAGS} dumpmain.c -o dumprmain.o
E 26
E 8
E 6
I 4

E 4
D 8
install:
E 8
I 8
D 26
rdump:	$(ROBJS)
D 11
	$(CC) $(CFLAGS) $(ROBJS) -o rdump -ljobs
E 11
I 11
	$(CC) $(CFLAGS) $(ROBJS) -o rdump
E 26
I 26
dumprtape.o: dumptape.c
	${CC} -c -DRDUMP ${CFLAGS} dumptape.c -o dumprtape.o
E 26
E 11

D 26
dump:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o dump
E 26
I 26
clean: FRC
	rm -f ${ROBJS} ${OBJS} rdump dump core
E 26

D 26
install: rdump dump
E 8
D 2
	install -s dump $(DESTDIR)/bin
/etc/dump:
	cp dump.csh $(DESTDIR)/etc/dump
E 2
I 2
D 6
	install -s dump $(DESTDIR)/etc
E 6
I 6
D 13
	install -s rdump $(DESTDIR)/etc
I 8
	install -s dump $(DESTDIR)/etc
E 13
I 13
D 19
	install -s -m 4750 -g operator rdump $(DESTDIR)/etc
	install -s -m 4750 -g operator dump $(DESTDIR)/etc
E 19
I 19
	install -s -m 6755 -g tty rdump $(DESTDIR)/etc
	install -s -m 2755 -g tty dump $(DESTDIR)/etc
E 26
I 26
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 26
E 19
E 13
E 8
E 6
I 4

I 8
D 10
dumprmain.o: dumprmain.c
	cc -c -DRDUMP dumprmain.c
E 10
I 10
D 14
dumprmain.o: dumpmain.c
	cp dumpmain.c dumprmain.c
E 14
I 14
D 26
dumprmain.c:
	ln -s dumpmain.c dumprmain.c
dumprmain.o: dumprmain.c
E 14
	${CC} -c -DRDUMP ${CFLAGS} dumprmain.c
E 26
I 26
install: FRC
	install -s -o root -g tty -m 6755 rdump ${DESTDIR}/etc/rdump
	install -s -o bin -g tty -m 2755 dump ${DESTDIR}/etc/dump
E 26
D 14
	rm -f dumprmain.c
E 14
E 10

I 14
D 26
dumprtape.c:
	ln -s dumptape.c dumprtape.c
dumprtape.o: dumprtape.c
	${CC} -c -DRDUMP ${CFLAGS} dumprtape.c
E 26
I 26
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 26

E 14
E 8
E 4
E 2
D 26
clean:
D 6
	rm -f *.o dump
E 6
I 6
D 8
	rm -f *.o rdump
E 8
I 8
D 10
	rm -f *.o rdump dump errs
E 10
I 10
D 14
	rm -f *.o rdump dump errs dumprmain.c
E 14
I 14
	rm -f *.o rdump dump errs dumprmain.c dumprtape.c
E 26
I 26
tags: FRC
	ctags ${SRCS}
E 26
E 14
E 10
E 8
E 6

I 20
D 26
depend:
E 26
I 26
FRC:
E 26

E 20
D 26
lint:
	lint $(DFLAGS) $(SRCS)
E 26
I 26
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 26

D 4
psrcs:
	echo $(PSRCS)
E 4
I 4
D 26
print:
	pr $(PSRCS) | lpr
E 26
I 26
dump.o: dump.h /usr/include/stdio.h /usr/include/ctype.h
dump.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
dump.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
dump.o: /usr/include/sys/fs.h /usr/include/sys/inode.h
dump.o: /usr/include/protocols/dumprestore.h /usr/include/sys/dir.h
dump.o: /usr/include/utmp.h /usr/include/sys/time.h /usr/include/time.h
dump.o: /usr/include/signal.h /usr/include/fstab.h
dumpitime.o: dumpitime.c dump.h /usr/include/stdio.h /usr/include/ctype.h
dumpitime.o: /usr/include/sys/param.h /usr/include/sys/types.h
dumpitime.o: /usr/include/signal.h /usr/include/machine/machparam.h
dumpitime.o: /usr/include/sys/stat.h /usr/include/sys/fs.h
dumpitime.o: /usr/include/sys/inode.h /usr/include/protocols/dumprestore.h
dumpitime.o: /usr/include/sys/dir.h /usr/include/utmp.h /usr/include/sys/time.h
dumpitime.o: /usr/include/time.h /usr/include/signal.h /usr/include/fstab.h
dumpitime.o: /usr/include/sys/file.h
dumpmain.o: dumpmain.c dump.h /usr/include/stdio.h /usr/include/ctype.h
dumpmain.o: /usr/include/sys/param.h /usr/include/sys/types.h
dumpmain.o: /usr/include/signal.h /usr/include/machine/machparam.h
dumpmain.o: /usr/include/sys/stat.h /usr/include/sys/fs.h
dumpmain.o: /usr/include/sys/inode.h /usr/include/protocols/dumprestore.h
dumpmain.o: /usr/include/sys/dir.h /usr/include/utmp.h /usr/include/sys/time.h
dumpmain.o: /usr/include/time.h /usr/include/signal.h /usr/include/fstab.h
dumpoptr.o: dumpoptr.c dump.h /usr/include/stdio.h /usr/include/ctype.h
dumpoptr.o: /usr/include/sys/param.h /usr/include/sys/types.h
dumpoptr.o: /usr/include/signal.h /usr/include/machine/machparam.h
dumpoptr.o: /usr/include/sys/stat.h /usr/include/sys/fs.h
dumpoptr.o: /usr/include/sys/inode.h /usr/include/protocols/dumprestore.h
dumpoptr.o: /usr/include/sys/dir.h /usr/include/utmp.h /usr/include/sys/time.h
dumpoptr.o: /usr/include/time.h /usr/include/signal.h /usr/include/fstab.h
dumprmt.o: dumprmt.c /usr/include/sys/param.h /usr/include/sys/types.h
dumprmt.o: /usr/include/signal.h /usr/include/machine/machparam.h
dumprmt.o: /usr/include/sys/mtio.h /usr/include/sys/ioctl.h
dumprmt.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
dumprmt.o: /usr/include/sys/socket.h /usr/include/sys/inode.h
dumprmt.o: /usr/include/netinet/in.h /usr/include/stdio.h /usr/include/pwd.h
dumprmt.o: /usr/include/netdb.h /usr/include/protocols/dumprestore.h
dumptape.o: dumptape.c /usr/include/sys/file.h dump.h /usr/include/stdio.h
dumptape.o: /usr/include/ctype.h /usr/include/sys/param.h
dumptape.o: /usr/include/sys/types.h /usr/include/signal.h
dumptape.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
dumptape.o: /usr/include/sys/fs.h /usr/include/sys/inode.h
dumptape.o: /usr/include/protocols/dumprestore.h /usr/include/sys/dir.h
dumptape.o: /usr/include/utmp.h /usr/include/sys/time.h /usr/include/time.h
dumptape.o: /usr/include/signal.h /usr/include/fstab.h
dumptraverse.o: dumptraverse.c dump.h /usr/include/stdio.h /usr/include/ctype.h
dumptraverse.o: /usr/include/sys/param.h /usr/include/sys/types.h
dumptraverse.o: /usr/include/signal.h /usr/include/machine/machparam.h
dumptraverse.o: /usr/include/sys/stat.h /usr/include/sys/fs.h
dumptraverse.o: /usr/include/sys/inode.h /usr/include/protocols/dumprestore.h
dumptraverse.o: /usr/include/sys/dir.h /usr/include/utmp.h
dumptraverse.o: /usr/include/sys/time.h /usr/include/time.h
dumptraverse.o: /usr/include/signal.h /usr/include/fstab.h
unctime.o: unctime.c /usr/include/sys/types.h /usr/include/sys/time.h
unctime.o: /usr/include/time.h /usr/include/stdio.h
E 26

D 5
$(OBJS): dump.h ../../h/param.h ../../h/stat.h ../../h/fs.h
$(OBJS): ../../h/inode.h ../../h/dumprestor.h
E 5
I 5
D 26
$(OBJS): dump.h /usr/include/sys/param.h
$(OBJS): /usr/include/sys/fs.h /usr/include/sys/inode.h
D 12
$(OBJS): /usr/include/dumprestor.h /usr/include/stat.h
E 12
I 12
D 17
$(OBJS): /usr/include/dumprestor.h /usr/include/sys/stat.h
E 17
I 17
$(OBJS): /usr/include/protocols/dumprestore.h /usr/include/sys/stat.h
E 26
I 26
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 26
E 17
E 12
E 5
E 4
E 1
