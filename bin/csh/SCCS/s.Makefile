h60636
s 00008/00014/00282
d D 5.10 88/05/19 15:38:24 bostic 19 18
c install C version of _doprnt
e
s 00001/00001/00295
d D 5.9 88/04/24 14:58:03 bostic 18 17
c ANSI C preprocessor doesn't like single apostrophes, so use cpp
e
s 00001/00001/00295
d D 5.8 87/11/30 21:21:26 bostic 17 16
c add strings.o to clean: label
e
s 00137/00080/00159
d D 5.7 87/06/05 11:58:51 bostic 16 15
c remove ifdef's for vax
e
s 00138/00024/00101
d D 5.6 87/06/02 23:59:47 bostic 15 14
c new template
e
s 00002/00000/00123
d D 5.5 87/05/31 20:32:36 bostic 14 13
c added depend label
e
s 00007/00002/00116
d D 5.4 86/10/13 16:46:33 sam 13 12
c doprnt.o is needed only on vax (need better way than this)
e
s 00028/00026/00090
d D 5.3 86/03/29 07:24:22 lepreau 12 11
c make sh.char.o shared text; sh.h now includes sh.local.h so fix dependencies;
c random cleanup
e
s 00001/00001/00115
d D 5.2 85/06/06 13:12:04 edward 11 10
c cleaning up after bozos
e
s 00004/00000/00112
d D 5.1 85/06/04 11:14:52 dist 10 9
c Add copyright
e
s 00019/00116/00093
d D 4.8 85/05/03 18:02:13 edward 9 7
c check in for karels, removed dependencies on standard include files
e
s 00001/00001/00208
d R 4.8 85/04/23 18:41:56 karels 8 7
c !$%#@ builtin paths
e
s 00137/00030/00072
d D 4.7 84/12/13 14:43:48 edward 7 6
c performance
e
s 00009/00009/00093
d D 4.6 84/09/02 17:01:40 sam 6 5
c a bit of a cleanup
e
s 00007/00002/00095
d D 4.5 84/08/31 09:33:59 ralph 5 4
c use new signals.
e
s 00010/00009/00087
d D 4.4 84/07/06 22:42:46 sam 4 3
c fix up profiling
e
s 00005/00005/00091
d D 4.3 83/06/11 16:48:45 sam 3 2
c different approach, try signal compatibility package
e
s 00001/00001/00095
d D 4.2 83/06/11 00:00:52 sam 2 1
c new signals; no libjobs
e
s 00096/00000/00000
d D 4.1 80/10/09 12:40:13 bill 1 0
c date and time created 80/10/09 12:40:13 by bill
e
u
U
t
T
I 1
#
I 10
# Copyright (c) 1980 Regents of the University of California.
D 11
# All rights reserved.  The Berkeley software License Agreement
E 11
I 11
# All rights reserved.  The Berkeley Software License Agreement
E 11
# specifies the terms and conditions for redistribution.
#
E 10
D 7
#	%M%	%I%	%G%
E 7
I 7
#	%W% (Berkeley) %G%
E 7
#
# C Shell with process control; VM/UNIX VAX Makefile
# Bill Joy UC Berkeley; Jim Kulp IIASA, Austria
#
D 4
CFLAGS=	-O -DTELL -DVMUNIX -Ddebug -DVFORK
E 4
I 4
D 5
CFLAGS=	-O -DTELL -DVMUNIX -Ddebug -DVFORK -pg
E 5
I 5
D 7
CFLAGS=	-O -DTELL -DVMUNIX -DVFORK
E 7
I 7
# To profile, put -DPROF in DEFS and -pg in CFLAGS, and recompile.

DEFS=	-DTELL -DVFORK -DFILEC
D 15
CFLAGS=	$(DEFS) -O
E 15
I 15
CFLAGS=	${DEFS} -O
E 15
E 7
E 5
E 4
XSTR=	/usr/ucb/xstr
D 7
ED=	-ed
AS=	-as
E 7
I 7
D 19
AS=	as
E 19
E 7
D 16
RM=	-rm
CXREF=	/usr/ucb/cxref
E 16
D 12
VGRIND=	csh /usr/ucb/vgrind
E 12
I 12
VGRIND=	/usr/ucb/vgrind
E 12
D 16
CTAGS=	/usr/ucb/ctags
D 2
LIBES=	-ljobs
E 2
I 2
LIBES=
E 2
D 9
SCCS=	/usr/local/sccs
E 9
I 9
SCCS=	sccs
E 16
E 9

D 7
# strings.o must be last in OBJS since it can change when previous files compile
D 3
OBJS=	sh.o sh.dol.o sh.err.o sh.exec.o sh.exp.o sh.func.o sh.glob.o \
	sh.hist.o sh.lex.o sh.misc.o sh.parse.o sh.print.o sh.sem.o sh.set.o \
	sh.proc.o sh.dir.o sh.time.o alloc.o sh.init.o printf.o \
	strings.o doprnt.o
E 3
I 3
D 4
OBJS=	alloc.o doprnt.o printf.o sh.o sh.dir.o sh.dol.o sh.err.o sh.exec.o \
E 4
I 4
OBJS=	alloc.o doprnt.o printf.o sh.dir.o sh.dol.o sh.err.o sh.exec.o \
E 4
	sh.exp.o sh.func.o sh.glob.o sh.hist.o sh.init.o sh.lex.o sh.misc.o \
D 5
	sh.parse.o sh.print.o sh.proc.o sh.sem.o sh.set.o sh.sig.o sh.time.o \
E 5
I 5
	sh.parse.o sh.print.o sh.proc.o sh.sem.o sh.set.o sh.time.o \
E 5
	strings.o
E 7
I 7
D 13
OBJS=	alloc.o doprnt.o printf.o sh.o sh.char.o sh.dir.o sh.dol.o sh.err.o \
E 13
I 13
D 16
#ifdef vax
#MACHOBJS=doprnt.o
I 15
#MACHSRCS=doprnt.c
E 15
#else
MACHOBJS=
I 15
MACHSRCS=
E 15
#endif
E 16
I 15
D 19
SRCS=	alloc.c printf.c sh.c sh.char.c sh.dir.c sh.dol.c sh.err.c \
	sh.exec.c sh.exp.c sh.file.c sh.func.c sh.glob.c sh.hist.c sh.init.c \
	sh.lex.c sh.misc.c sh.parse.c sh.print.c sh.proc.c sh.sem.c sh.set.c \
D 16
	sh.time.c ${MACHOBJS}
E 16
I 16
	sh.time.c
E 16
E 15
OBJS=	alloc.o printf.o sh.o sh.char.o sh.dir.o sh.dol.o sh.err.o \
E 13
	sh.exec.o sh.exp.o sh.file.o sh.func.o sh.glob.o sh.hist.o sh.init.o \
	sh.lex.o sh.misc.o sh.parse.o sh.print.o sh.proc.o sh.sem.o sh.set.o \
D 13
	sh.time.o
E 13
I 13
D 16
	sh.time.o ${MACHOBJS}
E 16
I 16
	sh.time.o doprnt.o
E 19
I 19
SRCS=	alloc.c doprnt.c sh.c sh.char.c sh.dir.c sh.dol.c sh.err.c \
	sh.exec.c sh.exp.c sh.file.c sh.func.c sh.glob.c sh.hist.c \
	sh.init.c sh.lex.c sh.misc.c sh.parse.c sh.print.c sh.proc.c \
	sh.sem.c sh.set.c sh.time.c
OBJS=	alloc.o doprnt.o sh.o sh.char.o sh.dir.o sh.dol.o sh.err.o \
	sh.exec.o sh.exp.o sh.file.o sh.func.o sh.glob.o sh.hist.o \
	sh.init.o sh.lex.o sh.misc.o sh.parse.o sh.print.o sh.proc.o \
	sh.sem.o sh.set.o sh.time.o
E 19
E 16
E 13
E 7
E 3

# Special massaging of C files for sharing of strings
.c.o:
	${CC} -E ${CFLAGS} $*.c | ${XSTR} -c -
	${CC} -c ${CFLAGS} x.c 
D 6
	mv x.o $*.o
E 6
I 6
	mv -f x.o $*.o
E 6
I 5
	rm -f x.c
E 5

D 4
csh: ${OBJS} sh.local.h
E 4
I 4
D 7
csh: sh.o ${OBJS} sh.local.h
E 7
I 7
# strings.o must be last since it can change when previous files compile
csh: ${OBJS} strings.o
E 7
E 4
D 16
	rm -f csh
D 4
	cc ${OBJS} -o csh ${LIBES}
E 4
I 4
D 6
	cc sh.o ${OBJS} -o csh ${LIBES}
E 6
I 6
D 7
	${CC} sh.o ${OBJS} -o csh ${LIBES}
E 7
I 7
D 12
	${CC} ${OBJS} strings.o -o csh ${LIBES}
E 12
I 12
	${CC} ${CFLAGS} ${OBJS} strings.o -o csh ${LIBES}
E 16
I 16
	${CC} ${CFLAGS} ${OBJS} strings.o -o $@
E 16
E 12
E 7
E 6
E 4

I 5
D 7
# To make csh.prof: put -pg in CFLAGS, make clean, make csh.prof
E 5
D 4
csh.prof: ${OBJS} sh.prof.o sh.local.h mcrt0.o
E 4
I 4
csh.prof: sh.prof.o ${OBJS} sh.local.h
E 4
	rm -f csh.prof
D 4
	ld -X mcrt0.o ${OBJS} -o csh.prof ${LIBES} -lc
E 4
I 4
D 6
	cc -pg sh.prof.o ${OBJS} ${LIBES} -o csh.prof
E 6
I 6
	${CC} -pg sh.prof.o ${OBJS} ${LIBES} -o csh.prof
E 6
E 4

D 4
sh.o.prof:
	cp sh.c sh.prof.c
	cc -c ${CFLAGS} -DPROF sh.prof.c
E 4
I 4
sh.prof.o: sh.c
	${CC} -E ${CFLAGS} -DPROF sh.c | ${XSTR} -c -
D 6
	cc -c ${CFLAGS} -DPROF x.c
	mv x.o sh.prof.o
E 6
I 6
	${CC} -c ${CFLAGS} -DPROF x.c
	mv -f x.o sh.prof.o
E 6
I 5
	rm -f x.c
E 5
E 4

E 7
D 16
.DEFAULT:
	${SCCS} get $<

E 16
D 19
# need an old doprnt, whose output we can trap
doprnt.o: doprnt.c
D 6
	cc -E doprnt.c > doprnt.s
	as -o doprnt.o doprnt.s
E 6
I 6
D 7
	${CC} -E doprnt.c > doprnt.s
	${AS} -o doprnt.o doprnt.s
E 6
	rm -f doprnt.s
E 7
I 7
D 18
	${CC} -E doprnt.c | ${AS} -o doprnt.o
E 18
I 18
	/lib/cpp doprnt.c | ${AS} -o doprnt.o
E 18
E 7

E 19
D 12
# strings.o and sh.init.o are specially processed to be shared
E 12
I 12
# strings.o, sh.init.o, and sh.char.o are specially processed to be shared
E 12
strings.o: strings
	${XSTR}
	${CC} -c -R xs.c
D 6
	mv xs.o strings.o
E 6
I 6
	mv -f xs.o strings.o
E 6
I 5
	rm -f xs.c
E 5

D 12
sh.init.o:
	${CC} -E ${CFLAGS} sh.init.c | ${XSTR} -c -
E 12
I 12
sh.char.o sh.init.o:
	${CC} -E ${CFLAGS} $*.c | ${XSTR} -c -
E 12
	${CC} ${CFLAGS} -c -R x.c
D 6
	mv x.o sh.init.o
E 6
I 6
D 12
	mv -f x.o sh.init.o
E 12
I 12
	mv -f x.o $*.o
E 12
E 6
I 5
	rm -f x.c
E 5
D 15
	
E 15
I 15

I 16
.DEFAULT:
	sccs get $<

clean:
D 17
	rm -f a.out strings x.c xs.c csh errs
E 17
I 17
	rm -f a.out strings strings.o x.c xs.c csh errs
E 17
	rm -f ${OBJS}
	rm -rf vgrind

depend:
	mkdep ${CFLAGS} ${SRCS}

E 16
E 15
lint:
D 7
	lint ${CFLAGS} sh*.c
E 7
I 7
D 16
	lint -z ${DEFS} sh*.c alloc.c
E 16
I 16
	lint ${CFLAGS} ${SRCS}
E 16
E 7

I 16
install: csh
	install -s -o bin -g bin -m 755 csh ${DESTDIR}/bin/csh

tags:
	ctags ${SRCS}

E 16
print:
	@pr READ_ME
D 12
	@pr makefile makefile.*
E 12
I 12
	@pr Makefile Makefile.*
E 12
	@(size -l a.out; size *.o) | pr -h SIZES
	@${CXREF} sh*.c | pr -h XREF
	@ls -l | pr 
	@pr sh*.h [a-rt-z]*.h sh*.c alloc.c

vprint:
	@pr -l84 READ_ME TODO
D 12
	@pr -l84 makefile makefile.*
E 12
I 12
	@pr -l84 Makefile Makefile.*
E 12
	@(size -l a.out; size *.o) | pr -l84 -h SIZES
	@${CXREF} sh*.c | pr -l84 -h XREF
	@ls -l | pr -l84
	@${CXREF} sh*.c | pr -l84 -h XREF
	@pr -l84 sh*.h [a-rt-z]*.h sh*.c alloc.c

vgrind:
	@cp /dev/null index
D 12
	@for i in *.h; do vgrind -t -h "C Shell" $$i >/crp/bill/csh/$$i.t; done
	@for i in *.c; do vgrind -t -h "C Shell" $$i >/crp/bill/csh/$$i.t; done
	@vgrind -t -x -h Index index >/crp/bill/csh/index.t
E 12
I 12
	@-mkdir grind
	for i in *.h; do ${VGRIND} -t -h "C Shell" $$i >grind/$$i.t; done
	for i in *.c; do ${VGRIND} -t -h "C Shell" $$i >grind/$$i.t; done
	${VGRIND} -t -x -h Index index >grind/index.t
E 12

D 7
install: csh sh.local.h
E 7
I 7
D 16
install: csh
E 7
D 15
	install -s csh ${DESTDIR}/bin/csh
E 15
I 15
	install -s -o bin -g bin -m 755 csh ${DESTDIR}/bin/csh
E 15

I 14
depend:
I 15
	mkdep ${CFLAGS} ${SRCS}
E 15

E 14
clean:
D 3
	${RM} -f a.out strings x.c xs.c csh
E 3
I 3
	${RM} -f a.out strings x.c xs.c csh errs
E 3
D 7
	${RM} -f *.o sh.prof.c
E 7
I 7
D 15
	${RM} -f *.o
E 15
I 15
	${RM} -f ${OBJS}
E 15
I 12
	${RM} -rf vgrind
E 12
E 7

D 7
tags:	/tmp
	${CTAGS} sh*.c
E 7
I 7
tags:
D 12
	${CTAGS} *.h sh*.c
E 12
I 12
	${CTAGS} -t *.h sh*.c
E 12

E 16
D 9
###
alloc.o: /usr/include/sys/types.h
sh.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h \
	/usr/include/sys/ioctl.h /usr/include/sys/ttychars.h \
	/usr/include/sys/ttydev.h /usr/include/sys/jioctl.h \
	/usr/include/fcntl.h /usr/include/pwd.h
E 9
I 9
D 12
sh.o: sh.h sh.local.h
E 12
I 12
D 15
sh.o: sh.h sh.local.h sh.char.h
E 12
E 9
sh.char.o: sh.char.h
D 9
sh.dir.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h sh.dir.h
sh.dol.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h sh.char.h
sh.err.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h \
	/usr/include/sys/ioctl.h /usr/include/sys/ttychars.h \
	/usr/include/sys/ttydev.h /usr/include/sys/jioctl.h
sh.exec.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h \
	/usr/include/sys/dir.h
sh.exp.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h
sh.file.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/sys/jioctl.h /usr/include/sys/dir.h /usr/include/pwd.h
sh.func.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h \
	/usr/include/sys/ioctl.h /usr/include/sys/ttychars.h \
	/usr/include/sys/ttydev.h /usr/include/sys/jioctl.h
sh.glob.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h sh.char.h \
	/usr/include/sys/dir.h
sh.hist.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h
E 9
I 9
sh.dir.o: sh.h sh.local.h sh.dir.h
sh.dol.o: sh.h sh.local.h sh.char.h
D 12
sh.err.o: sh.h sh.local.h
sh.exec.o: sh.h sh.local.h
sh.exp.o: sh.h sh.local.h
sh.file.o: sh.h sh.local.h
sh.func.o: sh.h sh.local.h
E 12
I 12
sh.err.o: sh.h sh.local.h sh.char.h
sh.exec.o: sh.h sh.local.h sh.char.h
sh.exp.o: sh.h sh.local.h sh.char.h
sh.file.o: sh.h sh.local.h sh.char.h
sh.func.o: sh.h sh.local.h sh.char.h
E 12
sh.glob.o: sh.h sh.local.h sh.char.h
D 12
sh.hist.o: sh.h sh.local.h
E 12
I 12
sh.hist.o: sh.h sh.local.h sh.char.h
E 12
E 9
sh.init.o: sh.local.h
D 9
sh.lex.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h sh.char.h \
	/usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/sys/jioctl.h
sh.misc.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h
sh.parse.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h
sh.print.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h \
	/usr/include/sys/ioctl.h /usr/include/sys/ttychars.h \
	/usr/include/sys/ttydev.h /usr/include/sys/jioctl.h
sh.proc.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h sh.dir.h \
	sh.proc.h /usr/include/sys/wait.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/sys/jioctl.h
sh.sem.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h sh.proc.h \
	/usr/include/sys/ioctl.h /usr/include/sys/ttychars.h \
	/usr/include/sys/ttydev.h /usr/include/sys/jioctl.h \
	/usr/include/fcntl.h
sh.set.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h
sh.time.o: sh.h /usr/include/sys/time.h /usr/include/sys/resource.h \
	/usr/include/sys/param.h /usr/include/machine/machparam.h \
	/usr/include/signal.h /usr/include/signal.h /usr/include/sys/types.h \
	/usr/include/sys/stat.h /usr/include/sys/signal.h \
	/usr/include/errno.h /usr/include/setjmp.h sh.local.h
E 9
I 9
sh.lex.o: sh.h sh.local.h sh.char.h
D 12
sh.misc.o: sh.h sh.local.h
sh.parse.o: sh.h sh.local.h
sh.print.o: sh.h sh.local.h
sh.proc.o: sh.h sh.local.h sh.dir.h sh.proc.h
sh.sem.o: sh.h sh.local.h sh.proc.h
sh.set.o: sh.h sh.local.h
sh.time.o: sh.h sh.local.h
E 12
I 12
sh.misc.o: sh.h sh.local.h sh.char.h
sh.parse.o: sh.h sh.local.h sh.char.h
sh.print.o: sh.h sh.local.h sh.char.h
sh.proc.o: sh.h sh.local.h sh.dir.h sh.proc.h sh.char.h
sh.sem.o: sh.h sh.local.h sh.proc.h sh.char.h
sh.set.o: sh.h sh.local.h sh.char.h
sh.time.o: sh.h sh.local.h sh.char.h
E 15
I 15
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

alloc.o: alloc.c /usr/include/sys/types.h
D 19
printf.o: printf.c
E 19
D 16
sh.o: sh.c sh.h /usr/include/sys/time.h /usr/include/time.h
sh.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.o: /usr/include/sys/types.h /usr/include/signal.h
E 16
I 16
sh.o: sh.c
sh.o:sh.h
sh.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/sys/resource.h
sh.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
E 16
sh.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.o: sh.local.h sh.char.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 16
I 16
sh.o:sh.local.h
sh.o:sh.char.h
sh.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 16
sh.o: /usr/include/sys/ttydev.h /usr/include/pwd.h
D 16
sh.char.o: sh.char.c sh.char.h
sh.dir.o: sh.dir.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.char.o: sh.char.c
sh.char.o:sh.char.h
sh.dir.o: sh.dir.c
sh.dir.o:sh.h
sh.dir.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.dir.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.dir.o: /usr/include/sys/types.h /usr/include/signal.h
sh.dir.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.dir.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.dir.o: sh.local.h sh.char.h sh.dir.h
sh.dol.o: sh.dol.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.dir.o:sh.local.h
sh.dir.o:sh.char.h
sh.dir.o:sh.dir.h
sh.dol.o: sh.dol.c
sh.dol.o:sh.h
sh.dol.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.dol.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.dol.o: /usr/include/sys/types.h /usr/include/signal.h
sh.dol.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.dol.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.dol.o: sh.local.h sh.char.h
sh.err.o: sh.err.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.dol.o:sh.local.h
sh.dol.o:sh.char.h
sh.err.o: sh.err.c
sh.err.o:sh.h
sh.err.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.err.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.err.o: /usr/include/sys/types.h /usr/include/signal.h
sh.err.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.err.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.err.o: sh.local.h sh.char.h /usr/include/sys/ioctl.h
sh.err.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
sh.exec.o: sh.exec.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.err.o:sh.local.h
sh.err.o:sh.char.h
sh.err.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
sh.err.o: /usr/include/sys/ttydev.h
sh.exec.o: sh.exec.c
sh.exec.o:sh.h
sh.exec.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.exec.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.exec.o: /usr/include/sys/types.h /usr/include/signal.h
sh.exec.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.exec.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.exec.o: sh.local.h sh.char.h /usr/include/sys/dir.h
sh.exp.o: sh.exp.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.exec.o:sh.local.h
sh.exec.o:sh.char.h
sh.exec.o: /usr/include/sys/dir.h
sh.exp.o: sh.exp.c
sh.exp.o:sh.h
sh.exp.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.exp.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.exp.o: /usr/include/sys/types.h /usr/include/signal.h
sh.exp.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.exp.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.exp.o: sh.local.h sh.char.h
sh.file.o: sh.file.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.exp.o:sh.local.h
sh.exp.o:sh.char.h
sh.file.o: sh.file.c
sh.file.o:sh.h
sh.file.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.file.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.file.o: /usr/include/sys/types.h /usr/include/signal.h
sh.file.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.file.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.file.o: sh.local.h sh.char.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 16
I 16
sh.file.o:sh.local.h
sh.file.o:sh.char.h
sh.file.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 16
sh.file.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
sh.file.o: /usr/include/sys/dir.h /usr/include/pwd.h
D 16
sh.func.o: sh.func.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.func.o: sh.func.c
sh.func.o:sh.h
sh.func.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.func.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.func.o: /usr/include/sys/types.h /usr/include/signal.h
sh.func.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.func.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.func.o: sh.local.h sh.char.h /usr/include/sys/ioctl.h
sh.func.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
sh.glob.o: sh.glob.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.func.o:sh.local.h
sh.func.o:sh.char.h
sh.func.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
sh.func.o: /usr/include/sys/ttydev.h
sh.glob.o: sh.glob.c
sh.glob.o:sh.h
sh.glob.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.glob.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.glob.o: /usr/include/sys/types.h /usr/include/signal.h
sh.glob.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.glob.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.glob.o: sh.local.h sh.char.h /usr/include/sys/dir.h
sh.hist.o: sh.hist.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.glob.o:sh.local.h
sh.glob.o:sh.char.h
sh.glob.o: /usr/include/sys/dir.h
sh.hist.o: sh.hist.c
sh.hist.o:sh.h
sh.hist.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.hist.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.hist.o: /usr/include/sys/types.h /usr/include/signal.h
sh.hist.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.hist.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.hist.o: sh.local.h sh.char.h
sh.init.o: sh.init.c sh.local.h
sh.lex.o: sh.lex.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.hist.o:sh.local.h
sh.hist.o:sh.char.h
sh.init.o: sh.init.c
sh.init.o:sh.local.h
sh.lex.o: sh.lex.c
sh.lex.o:sh.h
sh.lex.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.lex.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.lex.o: /usr/include/sys/types.h /usr/include/signal.h
sh.lex.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.lex.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.lex.o: sh.local.h sh.char.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 16
I 16
sh.lex.o:sh.local.h
sh.lex.o:sh.char.h
sh.lex.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 16
sh.lex.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 16
sh.misc.o: sh.misc.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.misc.o: sh.misc.c
sh.misc.o:sh.h
sh.misc.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.misc.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.misc.o: /usr/include/sys/types.h /usr/include/signal.h
sh.misc.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.misc.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.misc.o: sh.local.h sh.char.h
sh.parse.o: sh.parse.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.misc.o:sh.local.h
sh.misc.o:sh.char.h
sh.parse.o: sh.parse.c
sh.parse.o:sh.h
sh.parse.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.parse.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.parse.o: /usr/include/sys/types.h /usr/include/signal.h
sh.parse.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.parse.o: /usr/include/sys/signal.h /usr/include/errno.h
D 16
sh.parse.o: /usr/include/setjmp.h sh.local.h sh.char.h
sh.print.o: sh.print.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.parse.o: /usr/include/setjmp.h
sh.parse.o:sh.local.h
sh.parse.o:sh.char.h
sh.print.o: sh.print.c
sh.print.o:sh.h
sh.print.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.print.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.print.o: /usr/include/sys/types.h /usr/include/signal.h
sh.print.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.print.o: /usr/include/sys/signal.h /usr/include/errno.h
D 16
sh.print.o: /usr/include/setjmp.h sh.local.h sh.char.h /usr/include/sys/ioctl.h
sh.print.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
sh.proc.o: sh.proc.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.print.o: /usr/include/setjmp.h
sh.print.o:sh.local.h
sh.print.o:sh.char.h
sh.print.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
sh.print.o: /usr/include/sys/ttydev.h
sh.proc.o: sh.proc.c
sh.proc.o:sh.h
sh.proc.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.proc.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.proc.o: /usr/include/sys/types.h /usr/include/signal.h
sh.proc.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.proc.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.proc.o: sh.local.h sh.char.h sh.dir.h sh.proc.h /usr/include/sys/wait.h
sh.proc.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
sh.proc.o: /usr/include/sys/ttydev.h
sh.sem.o: sh.sem.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.proc.o:sh.local.h
sh.proc.o:sh.char.h
sh.proc.o:sh.dir.h
sh.proc.o:sh.proc.h
sh.proc.o: /usr/include/sys/wait.h /usr/include/sys/ioctl.h
sh.proc.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
sh.sem.o: sh.sem.c
sh.sem.o:sh.h
sh.sem.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.sem.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.sem.o: /usr/include/sys/types.h /usr/include/signal.h
sh.sem.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.sem.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.sem.o: sh.local.h sh.char.h sh.proc.h /usr/include/sys/ioctl.h
sh.sem.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
sh.set.o: sh.set.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.sem.o:sh.local.h
sh.sem.o:sh.char.h
sh.sem.o:sh.proc.h
sh.sem.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
sh.sem.o: /usr/include/sys/ttydev.h
sh.set.o: sh.set.c
sh.set.o:sh.h
sh.set.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.set.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.set.o: /usr/include/sys/types.h /usr/include/signal.h
sh.set.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.set.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.set.o: sh.local.h sh.char.h
sh.time.o: sh.time.c sh.h /usr/include/sys/time.h /usr/include/time.h
E 16
I 16
sh.set.o:sh.local.h
sh.set.o:sh.char.h
sh.time.o: sh.time.c
sh.time.o:sh.h
sh.time.o: /usr/include/sys/time.h /usr/include/time.h
E 16
sh.time.o: /usr/include/sys/resource.h /usr/include/sys/param.h
sh.time.o: /usr/include/sys/types.h /usr/include/signal.h
sh.time.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
sh.time.o: /usr/include/sys/signal.h /usr/include/errno.h /usr/include/setjmp.h
D 16
sh.time.o: sh.local.h sh.char.h
E 16
I 16
sh.time.o:sh.local.h
sh.time.o:sh.char.h
E 16

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 15
E 12
E 9
E 7
E 1
