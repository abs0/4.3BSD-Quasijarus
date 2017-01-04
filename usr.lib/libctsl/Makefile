# Makefile for libctsl2
#
#	@(#)Makefile	5.5 (Berkeley) 2013/01/19

CFLAGS=	-O
SRCS=	doylut.c gregtomjd.c iso8601.c juliantomjd.c mjdtogreg.c mjdtojulian.c \
	parsehms.c roman2mjd.c romanleap.c romanver.c
OBJS=	doylut.o gregtomjd.o iso8601.o juliantomjd.o mjdtogreg.o mjdtojulian.o \
	parsehms.o roman2mjd.o romanleap.o romanver.o

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

doylut.o: doylut.c /usr/include/sys/types.h doylut.h
gregtomjd.o: gregtomjd.c /usr/include/ctslcal.h /usr/include/caldate.h
gregtomjd.o: /usr/include/calendardefs.h
iso8601.o: iso8601.c /usr/include/ctype.h /usr/include/caldate.h
iso8601.o: /usr/include/timeparse.h
juliantomjd.o: juliantomjd.c /usr/include/ctslcal.h /usr/include/caldate.h
juliantomjd.o: /usr/include/calendardefs.h
mjdtogreg.o: mjdtogreg.c /usr/include/sys/types.h /usr/include/ctslcal.h
mjdtogreg.o: /usr/include/caldate.h /usr/include/calendardefs.h doylut.h
mjdtojulian.o: mjdtojulian.c /usr/include/sys/types.h
mjdtojulian.o: /usr/include/calendardefs.h /usr/include/ctslcal.h
mjdtojulian.o: /usr/include/caldate.h doylut.h
parsehms.o: parsehms.c /usr/include/sys/types.h /usr/include/ctype.h
parsehms.o: /usr/include/mjdtime.h /usr/include/timeparse.h
roman2mjd.o: roman2mjd.c /usr/include/caldate.h
romanleap.o: romanleap.c /usr/include/caldate.h
romanver.o: romanver.c /usr/include/caldate.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
