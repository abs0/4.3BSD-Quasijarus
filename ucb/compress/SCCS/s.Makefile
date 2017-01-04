h43706
s 00010/00006/00034
d D 5.11 99/01/21 00:43:01 msokolov 11 10
c add gzcompat
e
s 00003/00002/00037
d D 5.10 99/01/19 20:16:37 msokolov 10 9
c add strong compression mode
e
s 00002/00017/00037
d D 5.9 99/01/19 15:34:07 msokolov 9 8
c Get rid of all that USERMEM crap and set BITS=16 directly.
c The distributed compress binary must not depend on how much memory does the
c system builder have on his machine.
e
s 00002/00002/00052
d D 5.8 87/06/18 15:29:14 mckusick 8 7
c must put back USERMEM
e
s 00041/00015/00013
d D 5.7 87/06/16 17:27:42 bostic 7 6
c new template
e
s 00002/00000/00026
d D 5.6 87/05/31 21:07:27 bostic 6 5
c added depend labels
e
s 00004/00001/00022
d D 5.5 85/09/18 05:07:59 lepreau 5 4
c temp hack since usermem fails when chroot'ed to nbsd: don't clean USERMEM
e
s 00002/00003/00021
d D 5.4 85/09/17 16:15:50 lepreau 4 3
c compress 4.0 deleted warning about -O
e
s 00001/00001/00023
d D 5.3 85/06/17 17:57:12 edward 3 2
c use install -s
e
s 00001/00001/00023
d D 5.2 85/06/06 18:51:14 mckusick 2 1
c moves from local to ucb
e
s 00024/00000/00000
d D 5.1 85/06/06 18:46:10 mckusick 1 0
c 4.3 beta version
e
u
U
t
T
I 1
#
D 7
#	%W% (Berkeley) %G%
E 7
I 7
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 7
#
D 4
# if you have bugs in your C compiler dont use -O
E 4
D 7
COMFLAGS=-DBSD4_2 -O -DSACREDMEM=256000
D 2
BIN=${DESTDIR}/usr/local
E 2
I 2
BIN=${DESTDIR}/usr/ucb
E 7
I 7
#	%W%	(Berkeley)	%G%
#
D 8
CFLAGS=	-O -DBSD4_2 -DSACREDMEM=256000
E 8
I 8
D 9
CFLAGS=	-O -DBSD4_2 -DSACREDMEM=256000 -DUSERMEM=`cat USERMEM` 
E 9
I 9
CFLAGS=	-O -DBSD4_2 -DBITS=16
E 9
E 8
LIBC=	/lib/libc.a
I 10
LIBZ=	/usr/lib/libz.a
E 10
D 11
SRCS=	compress.c
OBJS=	compress.o
E 11
I 11
SRCS=	compress.c gzcompat.c
OBJS=	compress.o gzcompat.o
E 11
E 7
E 2

D 4
compress : compress.c USERMEM
E 4
I 4
D 7
compress: compress.c USERMEM
E 4
	cc $(COMFLAGS) -DUSERMEM=`cat USERMEM` -o compress compress.c
E 7
I 7
D 11
all: compress
E 11
I 11
all: compress gzcompat
E 11
E 7

I 7
D 9
compress: USERMEM ${OBJS} ${LIBC}
E 9
I 9
D 10
compress: ${OBJS} ${LIBC}
E 9
D 8
	${CC} ${CFLAGS} -DUSERMEM=`cat USERMEM` -o $@ ${OBJS}
E 8
I 8
	${CC} ${CFLAGS} -o $@ ${OBJS}
E 10
I 10
D 11
compress: ${OBJS} ${LIBC} ${LIBZ}
	${CC} ${CFLAGS} -o $@ ${OBJS} -lz
E 11
I 11
compress: compress.o ${LIBC} ${LIBZ}
	${CC} ${CFLAGS} -o $@ compress.o -lz
E 11
E 10
E 8

I 11
gzcompat: gzcompat.o ${LIBC}
	${CC} ${CFLAGS} -o $@ gzcompat.o

E 11
E 7
D 9
# USERMEM may have to be set by hand.  It should contain the amount of
# available user memory in bytes.  Set it to zero, for physical memory
# less than 1 Meg.
USERMEM:
	sh usermem.sh > USERMEM

D 7
install: compress
D 3
	cp compress $(BIN)
E 3
I 3
	install -s compress $(BIN)
E 3
	rm -f $(BIN)/uncompress $(BIN)/zcat
	ln $(BIN)/compress $(BIN)/uncompress
	ln $(BIN)/compress $(BIN)/zcat

E 7
I 5
# Temporarily don't delete USERMEM.  When chroot'ed to /nbsd, usermem.sh
# fails totally.
E 9
E 5
D 7
clean:
D 4
	rm -f compress USERMEM
E 4
I 4
D 5
	rm -f compress USERMEM core errs
E 5
I 5
	rm -f compress core errs
#	rm -f compress USERMEM core errs
E 7
I 7
clean: FRC
D 11
	rm -f ${OBJS} core compress
E 11
I 11
	rm -f ${OBJS} core compress gzcompat
E 11
D 9
#	rm -f ${OBJS} core compress USERMEM
E 9
E 7
I 6

D 7
depend:
E 7
I 7
depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 compress ${DESTDIR}/usr/ucb/compress
	rm -f ${DESTDIR}/usr/ucb/uncompress ${DESTDIR}/usr/ucb/zcat
	ln ${DESTDIR}/usr/ucb/compress ${DESTDIR}/usr/ucb/uncompress
	ln ${DESTDIR}/usr/ucb/compress ${DESTDIR}/usr/ucb/zcat
I 11
	install -s -o bin -g bin -m 755 gzcompat ${DESTDIR}/usr/ucb/gzcompat
E 11

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
D 9

compress.o: compress.c /usr/include/stdio.h /usr/include/ctype.h
compress.o: /usr/include/signal.h /usr/include/sys/types.h
compress.o: /usr/include/sys/stat.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
E 7
E 6
E 5
E 4
E 1
