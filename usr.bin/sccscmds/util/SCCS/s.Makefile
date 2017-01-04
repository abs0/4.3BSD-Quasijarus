h60903
s 00001/00001/00033
d D 1.8 01/05/27 20:25:13 msokolov 8 7
c add index to libPW
e
s 00002/00005/00032
d D 1.7 88/12/22 13:13:50 sam 7 6
c use syscall for doing syswrite stuff -- more portable?
e
s 00005/00002/00032
d D 1.6 87/02/15 22:34:18 lepreau 6 5
c make machine-independent by generatibg syswrite.s on the fly;
c alloca is in libc so don't need that either
e
s 00001/00001/00033
d D 1.5 87/02/15 15:34:07 lepreau 5 4
c make work for non-root and scrogged umasks
e
s 00017/00028/00017
d D 1.4 85/05/04 00:23:25 sam 4 3
c purge a bunch of crud in favor of the routines in libc; while 
c were at it, rewrite this makefile
e
s 00002/00002/00043
d D 1.3 85/05/03 00:44:36 sam 3 2
c purge fdfopen in favor of stdio fdopen
e
s 00004/00002/00041
d D 1.2 82/10/24 22:24:26 mckusick 2 1
c fully make libraries
e
s 00043/00000/00000
d D 1.1 82/05/19 17:20:43 rrh 1 0
c date and time created 82/05/19 17:20:43 by rrh
e
u
U
t
T
I 2
#	%W%	(Berkeley)	%E%
#
E 2
I 1
CFLAGS = -O -w
I 4
PWOBJS=	giveup.o lockit.o rename.o userdir.o \
	username.o xalloc.o xcreat.o xlink.o xopen.o \
	xpipe.o xunlink.o xmsg.o dname.o fatal.o setsig.o userexit.o \
D 6
	clean.o syswrite.o alloca.o anystr.o bal.o cat.o imatch.o \
E 6
I 6
D 7
	clean.o syswrite.o anystr.o bal.o cat.o imatch.o \
E 7
I 7
	clean.o anystr.o bal.o cat.o imatch.o \
E 7
E 6
	patoi.o patol.o repeat.o repl.o satoi.o sname.o substr.o trnslat.o \
	verify.o any.o zeropad.o
D 7
WROBJS=	write.o syswrite.o
E 7
I 7
WROBJS=	write.o
E 7
D 8
PW2OBJS=logname.o pexec.o
E 8
I 8
PW2OBJS=logname.o pexec.o index.o
E 8
E 4

all: libpw.a libwrt.a libPW.a
D 2

install: all
E 2
D 5
	mv libpw.a libwrt.a libPW.a ..
E 5
I 5
	mv -f libpw.a libwrt.a libPW.a ..
E 5
	ranlib ../libpw.a
	ranlib ../libwrt.a
	ranlib ../libPW.a
I 2
D 7

I 6
syswrite.s: mksyswrite.sh
	./mksyswrite.sh
E 7

E 6
install:
E 2

D 3
libpw.a:	curdir.o fdfopen.o giveup.o lockit.o rename.o userdir.o\
E 3
I 3
D 4
libpw.a:	curdir.o giveup.o lockit.o rename.o userdir.o\
E 3
	username.o xalloc.o xcreat.o xlink.o xopen.o \
	xpipe.o xunlink.o xmsg.o dname.o fatal.o setsig.o userexit.o
E 4
I 4
libpw.a: ${PWOBJS}
	rm -f libpw.a
	ar cr libpw.a ${PWOBJS}
E 4

D 4
libpw.a:	clean.o syswrite.o alloca.o anystr.o bal.o cat.o imatch.o\
	index.o move.o patoi.o \
	patol.o repeat.o repl.o satoi.o sname.o substr.o trnslat.o \
	verify.o any.o zero.o zeropad.o strend.o
E 4
I 4
libwrt.a: ${WROBJS}
	rm -f libwrt.a
	ar cr libwrt.a ${WROBJS}
E 4

D 4
libpw.a:
	-rm -f libpw.a tmp.a
D 3
	ar cr tmp.a curdir.o fdfopen.o giveup.o lockit.o rename.o userdir.o\
E 3
I 3
	ar cr tmp.a curdir.o giveup.o lockit.o rename.o userdir.o\
E 3
		username.o xalloc.o xcreat.o xlink.o xopen.o \
		xpipe.o xunlink.o xmsg.o dname.o fatal.o setsig.o userexit.o
	ar r tmp.a clean.o syswrite.o alloca.o anystr.o bal.o cat.o \
		imatch.o index.o move.o patoi.o \
		patol.o repeat.o repl.o satoi.o sname.o substr.o trnslat.o \
		verify.o any.o zero.o zeropad.o strend.o
	-chmod 644 tmp.a
	mv tmp.a libpw.a

libwrt.a:	write.o syswrite.o
	-rm -f libwrt.a tmp.a
	ar cr tmp.a write.o syswrite.o
	-chmod 644 tmp.a
	mv tmp.a libwrt.a


libPW.a:	logname.o pexec.o
	ar cr libPW.a logname.o pexec.o
E 4
I 4
libPW.a: ${PW2OBJS}
	rm -f libPW.a
	ar cr libPW.a ${PW2OBJS}
E 4

clean:
D 6
	-rm -f *.o
E 6
I 6
	-rm -f *.o syswrite.s errs
E 6
E 1
