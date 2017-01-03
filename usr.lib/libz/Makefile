# Makefile for libz
#
#	@(#)Makefile	5.2 (Berkeley) 1/19/99

CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	adler32.c compress.c crc32.c gzio.c uncompr.c deflate.c trees.c \
	zutil.c inflate.c infblock.c inftrees.c infcodes.c infutil.c \
	inffast.c compressio.c
OBJS=	adler32.o compress.o crc32.o gzio.o uncompr.o deflate.o trees.o \
	zutil.o inflate.o infblock.o inftrees.o infcodes.o infutil.o \
	inffast.o compressio.o

all: libz libz_p

.c.o:
	@${CC} -c -pg ${CFLAGS} $*.c
	@ld -x -o profiled/$*.o -r $*.o
	${CC} ${CFLAGS} -c $*.c
	@ld -x -r $*.o
	@mv a.out $*.o

# trees.c and infblock.c are compiled without -O, otherwise the generated code
# dumps core when executed. Sorry, can't troubleshoot this problem, gotta learn
# some VAX assembly first...

trees.o: trees.c
	@${CC} -c -pg trees.c
	@ld -x -o profiled/trees.o -r trees.o
	${CC} -c trees.c
	@ld -x -r trees.o
	@mv a.out trees.o

infblock.o: infblock.c
	@${CC} -c -pg infblock.c
	@ld -x -o profiled/infblock.o -r infblock.o
	${CC} -c infblock.c
	@ld -x -r infblock.o
	@mv a.out infblock.o

libz libz_p: ${OBJS}
	@echo building profiled libz
	@cd profiled; ar cu ../libz_p ${OBJS}
	ranlib libz_p
	@echo building normal libz
	@ar cu libz ${OBJS}
	ranlib libz

clean: FRC
	rm -f ${OBJS} profiled/*.o libz libz_p

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -o bin -g bin -m 644 libz ${DESTDIR}/usr/lib/libz.a
	ranlib ${DESTDIR}/usr/lib/libz.a
	install -o bin -g bin -m 644 libz_p ${DESTDIR}/usr/lib/libz_p.a
	ranlib ${DESTDIR}/usr/lib/libz_p.a

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

adler32.o: adler32.c /usr/include/zlib.h /usr/include/zconf.h
compress.o: compress.c /usr/include/zlib.h /usr/include/zconf.h
crc32.o: crc32.c /usr/include/zlib.h /usr/include/zconf.h
gzio.o: gzio.c /usr/include/stdio.h zutil.h /usr/include/zlib.h
gzio.o: /usr/include/zconf.h
uncompr.o: uncompr.c /usr/include/zlib.h /usr/include/zconf.h
deflate.o: deflate.c deflate.h zutil.h /usr/include/zlib.h /usr/include/zconf.h
trees.o: trees.c deflate.h zutil.h /usr/include/zlib.h /usr/include/zconf.h
zutil.o: zutil.c /usr/include/stdio.h zutil.h /usr/include/zlib.h
zutil.o: /usr/include/zconf.h
inflate.o: inflate.c zutil.h /usr/include/zlib.h /usr/include/zconf.h
inflate.o: infblock.h
infblock.o: infblock.c zutil.h /usr/include/zlib.h /usr/include/zconf.h
infblock.o: infblock.h inftrees.h infcodes.h infutil.h
inftrees.o: inftrees.c zutil.h /usr/include/zlib.h /usr/include/zconf.h
inftrees.o: inftrees.h
infcodes.o: infcodes.c zutil.h /usr/include/zlib.h /usr/include/zconf.h
infcodes.o: inftrees.h infblock.h infcodes.h infutil.h inffast.h
infutil.o: infutil.c zutil.h /usr/include/zlib.h /usr/include/zconf.h
infutil.o: infblock.h inftrees.h infcodes.h infutil.h
inffast.o: inffast.c zutil.h /usr/include/zlib.h /usr/include/zconf.h
inffast.o: inftrees.h infblock.h infcodes.h infutil.h inffast.h
compressio.o: compressio.c /usr/include/stdio.h zutil.h /usr/include/zlib.h
compressio.o: /usr/include/zconf.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
