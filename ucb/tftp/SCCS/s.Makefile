h28437
s 00010/00005/00052
d D 5.6 88/06/29 20:49:19 bostic 11 10
c install approved copyright notice
e
s 00009/00003/00048
d D 5.5 88/03/28 13:51:41 bostic 10 9
c add Berkeley specific header
e
s 00041/00013/00010
d D 5.4 87/06/16 18:58:55 bostic 9 8
c new template
e
s 00002/00000/00021
d D 5.3 87/05/31 21:14:10 bostic 8 7
c added depend label
e
s 00002/00002/00019
d D 5.2 86/02/06 15:01:32 minshall 7 6
c Install version from Jim Guyton <guyton@rand-unix>.
e
s 00007/00001/00014
d D 5.1 85/06/06 09:21:41 dist 6 5
c Add copyright
e
s 00001/00001/00014
d D 4.5 83/06/12 01:26:35 sam 5 4
c too much to say...let's just say it seems to work now
e
s 00002/00006/00013
d D 4.4 83/05/11 22:04:24 sam 4 3
c split tftpd out to etc source directory
e
s 00000/00005/00019
d D 4.3 82/12/25 21:20:10 sam 3 2
c no more asm.sed
e
s 00003/00002/00021
d D 4.2 82/10/21 14:44:29 sam 2 1
c DESTDIR
e
s 00023/00000/00000
d D 4.1 82/10/06 10:25:08 sam 1 0
c date and time created 82/10/06 10:25:08 by sam
e
u
U
t
T
I 1
D 6
# %M% %G%
E 6
I 6
#
D 9
# Copyright (c) 1983 Regents of the University of California.
E 9
I 9
# Copyright (c) 1987 Regents of the University of California.
E 9
D 10
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 10
I 10
# All rights reserved.
E 10
#
D 9
#	%W% (Berkeley) %G%
E 9
I 9
D 10
#	%W%	(Berkeley)	%G%
E 10
I 10
# Redistribution and use in source and binary forms are permitted
D 11
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 11
I 11
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 11
#
#	%W% (Berkeley) %G%
E 10
E 9
#
E 6
D 4
ALL=	tftp tftpd
E 4
I 4
D 9
ALL=	tftp
E 4
I 2
DESTDIR=
E 2
CFLAGS=-O
E 9
I 9
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	main.c tftp.c tftpsubs.c
OBJS=	main.o tftp.o tftpsubs.o
E 9

D 9
all: ${ALL}
E 9
I 9
all: tftp
E 9

D 3
.c.o:
	${CC} -S ${CFLAGS} $*.c
	sed -f ../asm.sed $*.s | as -o $*.o
	rm -f $*.s

E 3
D 7
tftp:	main.o tftp.o
D 5
	${CC} main.o tftp.o -o tftp -ljobs
E 5
I 5
	${CC} main.o tftp.o -o tftp
E 7
I 7
D 9
tftp:	main.o tftp.o tftpsubs.o
	${CC} main.o tftp.o tftpsubs.o -o tftp
E 9
I 9
tftp:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 9
E 7
E 5

D 4
tftpd:	tftpd.o
	${CC} tftpd.o -o tftpd -ljobs

E 4
D 9
clean:
	rm -f ${ALL} *.o *.s errs core a.out t.?
E 9
I 9
clean: FRC
	rm -f ${OBJS} core tftp
E 9

I 8
D 9
depend:
E 9
I 9
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 9

E 8
D 4
install: tftp tftpd
E 4
I 4
D 9
install: 
E 4
D 2
	install -s tftp /usr/ucb
	install -s tftpd /etc
E 2
I 2
	install -s tftp ${DESTDIR}/usr/ucb
E 9
I 9
install: FRC
	install -s -o bin -g bin -m 755 tftp ${DESTDIR}/usr/ucb/tftp

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

main.o: main.c /usr/include/sys/types.h /usr/include/sys/socket.h
main.o: /usr/include/sys/file.h /usr/include/netinet/in.h /usr/include/signal.h
main.o: /usr/include/stdio.h /usr/include/errno.h /usr/include/setjmp.h
main.o: /usr/include/ctype.h /usr/include/netdb.h
tftp.o: tftp.c /usr/include/sys/types.h /usr/include/sys/socket.h
tftp.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/netinet/in.h
tftp.o: /usr/include/arpa/tftp.h /usr/include/signal.h /usr/include/stdio.h
tftp.o: /usr/include/errno.h /usr/include/setjmp.h
tftpsubs.o: tftpsubs.c /usr/include/sys/types.h /usr/include/sys/socket.h
tftpsubs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
tftpsubs.o: /usr/include/sys/ttydev.h /usr/include/netinet/in.h
tftpsubs.o: /usr/include/arpa/tftp.h /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
D 4
	install -s tftpd ${DESTDIR}/etc
E 4
E 2
E 1
