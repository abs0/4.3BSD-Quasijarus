h18503
s 00077/00027/00017
d D 5.5 87/06/02 21:53:43 bostic 17 15
c new template
e
s 00077/00027/00017
d R 5.5 87/06/02 21:14:37 bostic 16 15
c new template
e
s 00002/00000/00042
d D 5.4 87/05/31 20:41:13 bostic 15 14
c added depend label
e
s 00002/00002/00040
d D 5.3 85/09/07 14:56:17 mckusick 14 13
c strip when installing
e
s 00001/00001/00041
d D 5.2 85/06/18 21:11:08 mckusick 13 12
c dumprestor.h moves to /usr/include/protocols
e
s 00005/00002/00037
d D 5.1 85/05/28 15:17:52 dist 12 11
c Add copyright
e
s 00002/00002/00037
d D 4.11 85/01/18 22:38:10 mckusick 11 10
c reorganize to split out interactive shell
e
s 00008/00003/00031
d D 4.10 83/06/12 02:47:04 sam 10 9
c new signals
e
s 00001/00001/00033
d D 4.9 83/05/19 01:24:09 mckusick 9 8
c use RRESTORE
e
s 00002/00002/00032
d D 4.8 83/05/16 12:57:43 mckusick 8 7
c be sure to install in the correct place
e
s 00002/00000/00032
d D 4.7 83/03/23 09:00:34 mckusick 7 6
c add dependencies for OBJ files
e
s 00019/00012/00013
d D 4.6 83/02/18 00:40:55 mckusick 6 5
c update to allow incremental restores
e
s 00001/00001/00024
d D 4.5 82/12/02 18:12:59 mckusick 5 4
c rrestor needs to run as root to set up remote host
e
s 00007/00006/00018
d D 4.4 82/12/02 17:53:03 mckusick 4 3
c clean-ups
e
s 00002/00005/00022
d D 4.3 82/10/11 11:23:40 mckusick 3 2
c rcmd.o moves into libc.a
e
s 00003/00006/00024
d D 4.2 82/10/05 15:01:25 sam 2 1
c merge rrestor and restor
e
s 00030/00000/00000
d D 4.1 82/10/03 19:41:12 mckusick 1 0
c date and time created 82/10/03 19:41:12 by mckusick
e
u
U
t
T
I 1
D 12
# Copyright (c) 1982 Regents of the University of California
E 12
#
D 12
#	%W%	(Berkeley)	%G%
E 12
I 12
D 17
# Copyright (c) 1983 Regents of the University of California.
E 17
I 17
# Copyright (c) 1987 Regents of the University of California.
E 17
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 17
#	%W% (Berkeley) %G%
E 17
I 17
#	%W%	(Berkeley)	%G%
E 17
E 12
#
D 3
NETSER=	/usr/src/ucb/netser

OBJS=	dumprmt.o ${NETSER}/rcmd.o
E 3
D 4
CFLAGS=
E 4
I 4
D 17
DESTDIR=
CFLAGS= -O
I 6
D 11
FILES=	main.c restore.c dirs.c symtab.c tape.c utilities.c
OBJS=	main.o restore.o dirs.o symtab.o utilities.o
E 11
I 11
FILES=	main.c interactive.c restore.c dirs.c symtab.c tape.c utilities.c
OBJS=	main.o interactive.o restore.o dirs.o symtab.o utilities.o
E 17
I 17
VPATH=	../dump:
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	main.c interactive.c restore.c dirs.c symtab.c tape.c utilities.c \
	../dump/dumprmt.c
OBJS=	main.o interactive.o restore.o dirs.o symtab.o utilities.o tape.o
ROBJS=	main.o interactive.o restore.o dirs.o symtab.o utilities.o rtape.o \
	dumprmt.o
E 17
E 11
E 6
E 4

D 6
all: rrestor restor
E 6
I 6
all: restore rrestore
E 6

I 2
D 6
restor: restor.c
D 4
	cc -o restor restor.c
E 4
I 4
	cc ${LDFLAGS} ${CFLAGS} -o restor restor.c
E 6
I 6
D 17
restore: ${OBJS} tape.o
	cc ${LDFLAGS} ${CFLAGS} -o restore ${OBJS} tape.o
E 17
I 17
restore: ${OBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${OBJS}
E 17
E 6
E 4

E 2
D 3
rrestor: ${OBJS} rrestor.o
	cc -o rrestor ${OBJS} rrestor.o -ljobs
E 3
I 3
D 6
rrestor: dumprmt.o rrestor.o
D 4
	cc -o rrestor dumprmt.o rrestor.o -ljobs
E 4
I 4
	cc ${LDFLAGS} -o rrestor dumprmt.o rrestor.o -ljobs
E 6
I 6
D 17
rrestore: ${OBJS} rtape.o dumprmt.o
D 10
	cc ${LDFLAGS} -o rrestore ${OBJS} rtape.o dumprmt.o -ljobs
E 10
I 10
	cc ${LDFLAGS} -o rrestore ${OBJS} rtape.o dumprmt.o
E 17
I 17
rrestore: ${ROBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${ROBJS}
E 17
E 10
E 6
E 4
E 3

D 2
restor: ${OBJS} restor.o
	cc -o restor ${OBJS} restor.o -ljobs

E 2
D 6
rrestor.o: restor.c
D 4
	cc -c -DRRESTOR restor.c
E 4
I 4
	cc ${CFLAGS} -c -DRRESTOR restor.c
E 4
	mv restor.o rrestor.o
E 6
I 6
D 10
rtape.o: rtape.c
E 10
I 10
D 17
rtape.o: tape.c
	cp tape.c rtape.c
E 10
D 9
	cc ${CFLAGS} -c -DRRESTOR rtape.c
E 9
I 9
	cc ${CFLAGS} -c -DRRESTORE rtape.c
I 10
	rm -f rtape.c
E 17
I 17
rtape.o: ${LIBC} tape.c
	${CC} ${CFLAGS} -c -DRRESTORE tape.c -o rtape.o
E 17
E 10
E 9
E 6
D 2

restor.o: restor.c
	cc -c restor.c
E 2

I 10
D 17
dumprmt.o: ../dump/dumprmt.c
	cc ${CFLAGS} -c ../dump/dumprmt.c
E 17
I 17
clean: FRC
	rm -f ${ROBJS} ${OBJS} core restore rrestore
E 17

E 10
D 6
install: rrestor restor
D 4
	cp rrestor /etc
	cp restor /etc
E 4
I 4
D 5
	install rrestor ${DESTDIR}/etc/rrestor
E 5
I 5
	install -m 4755 rrestor ${DESTDIR}/etc/rrestor
E 5
	install restor ${DESTDIR}/etc/restor
E 6
I 6
D 17
install: rrestore restore
D 8
	install restore ${DESTDIR}/etc/restor
	install -m 4755 rrestore ${DESTDIR}/etc/rrestor
E 8
I 8
D 14
	install restore ${DESTDIR}/etc/restore
	install -m 4755 rrestore ${DESTDIR}/etc/rrestore
E 14
I 14
	install -s restore ${DESTDIR}/etc/restore
	install -s -m 4755 rrestore ${DESTDIR}/etc/rrestore
E 17
I 17
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 17
E 14
E 8
E 6
E 4

D 17
clean:
D 6
	rm -f restor rrestor *.o errs
E 6
I 6
D 10
	rm -f restore rrestore *.o errs
E 10
I 10
	rm -f restore rrestore *.o errs a.out core
E 17
I 17
install: FRC
	install -s -o bin -g bin -m 755 restore ${DESTDIR}/etc/restore
	install -s -o root -g bin -m 4755 rrestore ${DESTDIR}/etc/rrestore
E 17
E 10

I 15
D 17
depend:
E 17
I 17
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 17

E 15
D 17
lint:
	lint ${FILES}
E 17
I 17
tags: FRC
	ctags ${SRCS}
E 17

D 17
print:
D 13
	@pr /usr/include/dumprestor.h restore.h ${FILES}
E 13
I 13
	@pr /usr/include/protocols/dumprestore.h restore.h ${FILES}
E 17
I 17
FRC:
E 17
E 13
I 7

D 17
${OBJS}: restore.h
E 17
I 17
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

main.o: main.c restore.h /usr/include/stdio.h /usr/include/sys/param.h
main.o: /usr/include/sys/types.h /usr/include/signal.h
main.o: /usr/include/machine/machparam.h /usr/include/sys/inode.h
main.o: /usr/include/sys/fs.h /usr/include/sys/dir.h
main.o: /usr/include/protocols/dumprestore.h /usr/include/signal.h
interactive.o: interactive.c restore.h /usr/include/stdio.h
interactive.o: /usr/include/sys/param.h /usr/include/sys/types.h
interactive.o: /usr/include/signal.h /usr/include/machine/machparam.h
interactive.o: /usr/include/sys/inode.h /usr/include/sys/fs.h
interactive.o: /usr/include/sys/dir.h /usr/include/protocols/dumprestore.h
interactive.o: /usr/include/setjmp.h
restore.o: restore.c restore.h /usr/include/stdio.h /usr/include/sys/param.h
restore.o: /usr/include/sys/types.h /usr/include/signal.h
restore.o: /usr/include/machine/machparam.h /usr/include/sys/inode.h
restore.o: /usr/include/sys/fs.h /usr/include/sys/dir.h
dirs.o: dirs.c restore.h /usr/include/stdio.h /usr/include/sys/param.h
dirs.o: /usr/include/sys/types.h /usr/include/signal.h
dirs.o: /usr/include/machine/machparam.h /usr/include/sys/inode.h
dirs.o: /usr/include/sys/fs.h /usr/include/sys/dir.h
dirs.o: /usr/include/protocols/dumprestore.h /usr/include/sys/file.h
symtab.o: symtab.c restore.h /usr/include/stdio.h /usr/include/sys/param.h
symtab.o: /usr/include/sys/types.h /usr/include/signal.h
symtab.o: /usr/include/machine/machparam.h /usr/include/sys/inode.h
symtab.o: /usr/include/sys/fs.h /usr/include/sys/dir.h /usr/include/sys/stat.h
tape.o: tape.c restore.h /usr/include/stdio.h /usr/include/sys/param.h
tape.o: /usr/include/sys/types.h /usr/include/signal.h
tape.o: /usr/include/machine/machparam.h /usr/include/sys/inode.h
tape.o: /usr/include/sys/fs.h /usr/include/sys/dir.h
tape.o: /usr/include/protocols/dumprestore.h /usr/include/sys/ioctl.h
tape.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
tape.o: /usr/include/sys/mtio.h /usr/include/sys/file.h /usr/include/setjmp.h
tape.o: /usr/include/sys/stat.h
utilities.o: utilities.c restore.h /usr/include/stdio.h
utilities.o: /usr/include/sys/param.h /usr/include/sys/types.h
utilities.o: /usr/include/signal.h /usr/include/machine/machparam.h
utilities.o: /usr/include/sys/inode.h /usr/include/sys/fs.h
utilities.o: /usr/include/sys/dir.h
dumprmt.o: ../dump/dumprmt.c /usr/include/sys/param.h /usr/include/sys/types.h
dumprmt.o: /usr/include/signal.h /usr/include/machine/machparam.h
dumprmt.o: /usr/include/sys/mtio.h /usr/include/sys/ioctl.h
dumprmt.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
dumprmt.o: /usr/include/sys/socket.h /usr/include/sys/inode.h
dumprmt.o: /usr/include/netinet/in.h /usr/include/stdio.h /usr/include/pwd.h
dumprmt.o: /usr/include/netdb.h /usr/include/protocols/dumprestore.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 17
E 7
E 6
E 1
