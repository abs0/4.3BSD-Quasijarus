h15666
s 00005/00003/00054
d D 5.5 2013/01/19 23:27:04 msokolov 5 4
c parsehms.c added
c romanleap.c now includes <caldate.h> for calend_long
e
s 00004/00002/00053
d D 5.4 2012/06/23 08:38:28 msokolov 4 3
c iso8601.c is back
e
s 00003/00003/00052
d D 5.3 2012/06/23 05:42:21 msokolov 3 2
c romanmonths.c is no more, romanleap.c added
e
s 00017/00011/00038
d D 5.2 2012/06/23 05:24:27 msokolov 2 1
c new design for CTSL2
e
s 00049/00000/00000
d D 5.1 11/07/13 03:42:28 msokolov 1 0
c libctsl subset for the 4.3BSD source tree
e
u
U
t
T
I 1
D 2
# Makefile for libctsl SUBSET
E 2
I 2
# Makefile for libctsl2
E 2
#
#	%W% (Berkeley) %E%

CFLAGS=	-O
D 2
SRCS=	gregtomjd.c iso8601.c julianlin.c mjdtogreg.c \
	romanmonths.c romanver.c
OBJS=	gregtomjd.o iso8601.o julianlin.o mjdtogreg.o \
	romanmonths.o romanver.o
E 2
I 2
D 4
SRCS=	doylut.c gregtomjd.c juliantomjd.c mjdtogreg.c mjdtojulian.c \
E 4
I 4
SRCS=	doylut.c gregtomjd.c iso8601.c juliantomjd.c mjdtogreg.c mjdtojulian.c \
E 4
D 3
	roman2mjd.c romanmonths.c romanver.c
E 3
I 3
D 5
	roman2mjd.c romanleap.c romanver.c
E 5
I 5
	parsehms.c roman2mjd.c romanleap.c romanver.c
E 5
E 3
D 4
OBJS=	doylut.o gregtomjd.o juliantomjd.o mjdtogreg.o mjdtojulian.o \
E 4
I 4
OBJS=	doylut.o gregtomjd.o iso8601.o juliantomjd.o mjdtogreg.o mjdtojulian.o \
E 4
D 3
	roman2mjd.o romanmonths.o romanver.o
E 3
I 3
D 5
	roman2mjd.o romanleap.o romanver.o
E 5
I 5
	parsehms.o roman2mjd.o romanleap.o romanver.o
E 5
E 3
E 2

all: libctsl.a

.c.o:
	${CC} ${CFLAGS} -c $*.c

libctsl.a: ${OBJS}
	ar cu $@ ${OBJS}
	ranlib $@

clean: FRC
	rm -f *.[oa]

install: FRC
	install -c -o bin -g bin -m 644 libctsl.a /usr/lib
	ranlib /usr/lib/libctsl.a

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 2
gregtomjd.o: gregtomjd.c /usr/include/ctslcal.h /usr/include/calendardefs.h
iso8601.o: iso8601.c /usr/include/ctype.h /usr/include/strings.h
iso8601.o: /usr/include/ctslcal.h
julianlin.o: julianlin.c /usr/include/ctslcal.h /usr/include/calendardefs.h
mjdtogreg.o: mjdtogreg.c /usr/include/ctslcal.h /usr/include/calendardefs.h
E 2
I 2
doylut.o: doylut.c /usr/include/sys/types.h doylut.h
gregtomjd.o: gregtomjd.c /usr/include/ctslcal.h /usr/include/caldate.h
gregtomjd.o: /usr/include/calendardefs.h
I 4
iso8601.o: iso8601.c /usr/include/ctype.h /usr/include/caldate.h
iso8601.o: /usr/include/timeparse.h
E 4
juliantomjd.o: juliantomjd.c /usr/include/ctslcal.h /usr/include/caldate.h
juliantomjd.o: /usr/include/calendardefs.h
mjdtogreg.o: mjdtogreg.c /usr/include/sys/types.h /usr/include/ctslcal.h
mjdtogreg.o: /usr/include/caldate.h /usr/include/calendardefs.h doylut.h
mjdtojulian.o: mjdtojulian.c /usr/include/sys/types.h
mjdtojulian.o: /usr/include/calendardefs.h /usr/include/ctslcal.h
mjdtojulian.o: /usr/include/caldate.h doylut.h
I 5
parsehms.o: parsehms.c /usr/include/sys/types.h /usr/include/ctype.h
parsehms.o: /usr/include/mjdtime.h /usr/include/timeparse.h
E 5
roman2mjd.o: roman2mjd.c /usr/include/caldate.h
E 2
D 3
romanmonths.o: romanmonths.c
E 3
I 3
D 5
romanleap.o: romanleap.c
E 5
I 5
romanleap.o: romanleap.c /usr/include/caldate.h
E 5
E 3
D 2
romanver.o: romanver.c /usr/include/ctslcal.h
E 2
I 2
romanver.o: romanver.c /usr/include/caldate.h
E 2

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
