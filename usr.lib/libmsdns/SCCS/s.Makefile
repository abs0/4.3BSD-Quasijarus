h07607
s 00002/00002/00037
d D 1.2 2011/12/28 03:37:08 msokolov 2 1
c dnameread.c and dnamestr.c added
e
s 00039/00000/00000
d D 1.1 2011/12/27 02:01:49 msokolov 1 0
c beginning of libmsdns
e
u
U
t
T
I 1
# Makefile for libmsdns
#
#	%W% (Berkeley) %E%

CFLAGS=	-O
SRCS=	dnameasc.c dnamecmp.c dnamecopy.c dnamelabels.c dnameprint.c \
D 2
	dnameunder.c
E 2
I 2
	dnameread.c dnamestr.c dnameunder.c
E 2
OBJS=	dnameasc.o dnamecmp.o dnamecopy.o dnamelabels.o dnameprint.o \
D 2
	dnameunder.o
E 2
I 2
	dnameread.o dnamestr.o dnameunder.o
E 2

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
E 1
