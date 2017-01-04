h16479
s 00074/00008/00022
d D 5.3 87/06/18 23:46:29 bostic 4 3
c new template
e
s 00003/00001/00027
d D 5.2 86/04/03 16:47:10 donn 3 2
c Add Kirk Smith's USR Courier driver.
e
s 00006/00001/00022
d D 5.1 85/06/06 09:48:46 dist 2 1
c Add copyright
e
s 00023/00000/00000
d D 1.1 85/04/11 16:54:03 miriam 1 0
c date and time created 85/04/11 16:54:03 by miriam
e
u
U
t
T
I 1
D 2
#	%M%	%I%	%E%
E 2
I 2
#
D 4
# Copyright (c) 1983 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
#	%W%	(Berkeley)	%G%
E 4
E 2
#
# make file for tip device drivers
#
# Current drivers:
#	BIZCOMP
I 3
#	USR COURIER (2400 baud)
E 3
#	DEC DF02-AC, DF03-AC
#	DEC DN-11/Able Quadracall
I 3
#	HAYES and Hayes emulators
E 3
#	VENTEL 212+ (w/o echo)
#	VADIC 831 RS232 adaptor
#	VADIC 3451
D 4

CFLAGS=	-O -I../
E 4
I 4
CFLAGS=	-O -I..
LIBC=	/lib/libc.a
SRCS=	biz22.c biz31.c courier.c df.c dn11.c hayes.c ventel.c v831.c v3451.c
E 4
D 3
OBJS=	biz22.o biz31.o df.o dn11.o hayes.o ventel.o v831.o v3451.o
E 3
I 3
OBJS=	biz22.o biz31.o courier.o df.o dn11.o hayes.o ventel.o v831.o v3451.o
E 3

I 4
all: aculib.a

E 4
aculib.a: ${OBJS}
D 4
	ar cu aculib.a *.o
E 4
I 4
	ar cu aculib.a ${OBJS}
E 4
	ranlib aculib.a

D 4
${OBJS}: ../tip.h
E 4
I 4
clean: FRC
	rm -f ${OBJS} core aculib.a
E 4

D 4
clean:
	rm -f aculib.a *.o core errs a.out
E 4
I 4
depend: FRC
	mkdep ${CFLAGS} ${SRCS}

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

install:
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

biz22.o: biz22.c ../tip.h /usr/include/sys/types.h /usr/include/sys/file.h
biz22.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
biz22.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
biz22.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
biz22.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
biz31.o: biz31.c ../tip.h /usr/include/sys/types.h /usr/include/sys/file.h
biz31.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
biz31.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
biz31.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
biz31.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
courier.o: courier.c ../tip.h /usr/include/sys/types.h /usr/include/sys/file.h
courier.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
courier.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
courier.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
courier.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
courier.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
df.o: df.c ../tip.h /usr/include/sys/types.h /usr/include/sys/file.h
df.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
df.o: /usr/include/sys/ttydev.h /usr/include/signal.h /usr/include/stdio.h
df.o: /usr/include/pwd.h /usr/include/ctype.h /usr/include/setjmp.h
df.o: /usr/include/errno.h
dn11.o: dn11.c ../tip.h /usr/include/sys/types.h /usr/include/sys/file.h
dn11.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
dn11.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
dn11.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
dn11.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
hayes.o: hayes.c ../tip.h /usr/include/sys/types.h /usr/include/sys/file.h
hayes.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
hayes.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
hayes.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
hayes.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
ventel.o: ventel.c ../tip.h /usr/include/sys/types.h /usr/include/sys/file.h
ventel.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
ventel.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ventel.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
ventel.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
v831.o: v831.c /usr/include/sys/time.h /usr/include/time.h ../tip.h
v831.o: /usr/include/sys/types.h /usr/include/sys/file.h /usr/include/sgtty.h
v831.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
v831.o: /usr/include/sys/ttydev.h /usr/include/signal.h /usr/include/stdio.h
v831.o: /usr/include/pwd.h /usr/include/ctype.h /usr/include/setjmp.h
v831.o: /usr/include/errno.h
v3451.o: v3451.c ../tip.h /usr/include/sys/types.h /usr/include/sys/file.h
v3451.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
v3451.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
v3451.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
v3451.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1
