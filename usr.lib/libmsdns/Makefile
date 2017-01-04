# Makefile for libmsdns
#
#	@(#)Makefile	1.2 (Berkeley) 2011/12/28

CFLAGS=	-O
SRCS=	dnameasc.c dnamecmp.c dnamecopy.c dnamelabels.c dnameprint.c \
	dnameread.c dnamestr.c dnameunder.c
OBJS=	dnameasc.o dnamecmp.o dnamecopy.o dnamelabels.o dnameprint.o \
	dnameread.o dnamestr.o dnameunder.o

all: libmsdns.a

.c.o:
	${CC} ${CFLAGS} -c $*.c

libmsdns.a: ${OBJS}
	ar cu $@ ${OBJS}
	ranlib $@

clean: FRC
	rm -f *.[oa]

install: FRC
	install -c -o bin -g bin -m 644 libmsdns.a ${DESTDIR}/usr/lib
	ranlib ${DESTDIR}/usr/lib/libmsdns.a

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
