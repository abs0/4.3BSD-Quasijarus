#	@(#)Makefile	5.2 (IFCTF) 2012/06/21
#
DEFS=	-DLIBC_SCCS
CFLAGS=	-O -R ${DEFS}
SRCS=	asctime.c ctime.c gmtime.c localtime.c mjd2greg.c sexatime.c
OBJS=	asctime.o ctime.o gmtime.o localtime.o mjd2greg.o sexatime.o
TAGSFILE=tags

.c.o:
	@${CC} -p -c ${CFLAGS} $*.c
	@-ld -X -o profiled/$*.o -r $*.o
	${CC} ${CFLAGS} -c $*.c
	@-ld -x -r $*.o
	@mv a.out $*.o

all: ${OBJS}

link: ${OBJS}
	(cd ../library; rm -f ${OBJS})
	(cd ../profiled; rm -f ${OBJS})
	ln ${OBJS} ../library
	(cd profiled; ln ${OBJS} ../../profiled)

tags:
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

clean:
	rm -f *.o profiled/* a.out core ${TAGSFILE}

depend:
	mkdep ${CFLAGS} ${SRCS}

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

asctime.o: asctime.c /usr/include/stdio.h /usr/include/time.h
ctime.o: ctime.c /usr/include/sys/types.h /usr/include/time.h
gmtime.o: gmtime.c /usr/include/sys/types.h /usr/include/mjdtime.h
gmtime.o: /usr/include/time.h
localtime.o: localtime.c /usr/include/sys/types.h /usr/include/mjdtime.h
localtime.o: /usr/include/time.h
mjd2greg.o: mjd2greg.c /usr/include/sys/types.h /usr/include/calendardefs.h
mjd2greg.o: /usr/include/time.h
sexatime.o: sexatime.c /usr/include/sys/types.h /usr/include/mjdtime.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
