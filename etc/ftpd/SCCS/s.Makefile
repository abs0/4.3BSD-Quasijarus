h59147
s 00004/00002/00080
d D 5.11 11/04/16 00:35:54 msokolov 14 13
c added support for multiple guest accounts
e
s 00007/00002/00075
d D 5.10 05/01/12 06:47:12 msokolov 13 12
c added eps.c
e
s 00032/00002/00045
d D 5.9 05/01/11 06:00:10 msokolov 12 11
c use compiled-in ls instead of /bin/ls
c in preparation for EPS with chroot
e
s 00001/00001/00046
d D 5.8 03/06/10 21:11:02 msokolov 11 10
c make auto gzcompat feature conditional on -DGZCOMPAT for portability
e
s 00002/00033/00045
d D 5.7 99/07/13 22:47:50 msokolov 10 9
c "version" means when the code was written, not when it was compiled!
c make the version string based on ftpd.c SCCS ID and get rid of vers.c kludge
e
s 00010/00005/00068
d D 5.6 88/06/18 13:46:45 bostic 9 8
c install approved copyright notice
e
s 00020/00011/00053
d D 5.5 88/03/14 17:27:45 bostic 8 7
c add Berkeley specific header
e
s 00052/00013/00012
d D 5.4 87/06/02 21:48:55 bostic 7 5
c new template
e
s 00052/00013/00012
d R 5.4 87/06/02 20:20:04 bostic 6 5
c new template
e
s 00002/00000/00023
d D 5.3 87/05/31 20:38:40 bostic 5 4
c added depend label
e
s 00000/00000/00023
d D 5.2 86/02/03 14:32:49 minshall 4 3
c Steve Jacobson's changes (from <csvsj@ucbopal>).
e
s 00006/00001/00017
d D 5.1 85/06/06 11:08:25 dist 3 2
c Add copyright
e
s 00004/00006/00014
d D 4.2 83/06/12 02:45:42 sam 2 1
c new signals == no libjobs
e
s 00020/00000/00000
d D 4.1 83/05/03 16:37:57 sam 1 0
c date and time created 83/05/03 16:37:57 by sam
e
u
U
t
T
I 1
D 3
#	%W%	%G%
E 3
I 3
#
D 7
# Copyright (c) 1983 Regents of the University of California.
E 7
I 7
D 8
# Copyright (c) 1987 Regents of the University of California.
E 7
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 8
I 8
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 8
#
D 7
#	%W% (Berkeley) %G%
E 7
I 7
D 8
#	%W%	(Berkeley)	%G%
E 8
I 8
# Redistribution and use in source and binary forms are permitted
D 9
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
E 7
E 3
#
I 8
#	%W% (Berkeley) %G%
#
E 8
D 2
ALL=	ftpd
E 2
I 2
D 7
ALL=	ftpd.o ftpcmd.o glob.o vers.o
E 2
DESTDIR=
E 7
D 11
CFLAGS=	-O
E 11
I 11
CFLAGS=	-O -DGZCOMPAT
E 11
I 7
LIBC=	/lib/libc.a
D 10
SRCS=	ftpd.c ftpcmd.c glob.c vers.c
OBJS=	ftpd.o ftpcmd.o glob.o vers.o
E 10
I 10
D 12
SRCS=	ftpd.c ftpcmd.c glob.c
OBJS=	ftpd.o ftpcmd.o glob.o
E 12
I 12
D 13
SRCS=	ftpd.c ftpcmd.c glob.c ls.c
OBJS=	ftpd.o ftpcmd.o glob.o ls.o
E 13
I 13
D 14
SRCS=	ftpd.c ftpcmd.c glob.c ls.c eps.c
OBJS=	ftpd.o ftpcmd.o glob.o ls.o eps.o
E 14
I 14
SRCS=	ftpd.c ftpcmd.c glob.c ls.c eps.c specialguests.c
OBJS=	ftpd.o ftpcmd.o glob.o ls.o eps.o specialguests.o
E 14
E 13
E 12
E 10
E 7

D 2
all:	${ALL}
E 2
I 2
D 7
ftpd:	${ALL}
	${CC} -o ftpd ${ALL}
E 7
I 7
all: ftpd
E 7
E 2

D 2
ftpd:	ftpd.o ftpcmd.o vers.o glob.o
	${CC} ftpd.o ftpcmd.o glob.o -o ftpd vers.o -ljobs

E 2
D 7
vers.o:	ftpd.c ftpcmd.y
E 7
I 7
ftpd: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS}

D 10
vers.o: ftpd.c ftpcmd.y
E 7
	sh newvers.sh
D 7
	${CC} -c vers.c
E 7
I 7
	${CC} ${CFLAGS} -c vers.c
E 7

E 10
D 7
install:
	install -s ftpd ${DESTDIR}/etc/ftpd
E 7
I 7
clean: FRC
	rm -f ${OBJS} ftpd core ftpcmd.c
E 7

D 7
clean:
D 2
	rm -f ${ALL} *.o *.s errs core a.out t.? yacc.* y.tab.c
E 2
I 2
	rm -f ftpd *.o *.s errs core a.out t.? yacc.* y.tab.c
E 7
I 7
D 8
depend: ftpcmd.c FRC
E 8
I 8
depend: ${SRCS} FRC
E 8
	mkdep ${CFLAGS} ${SRCS}
E 7
I 5

D 7
depend:
E 7
I 7
install: FRC
	install -s -o bin -g bin -m 755 ftpd ${DESTDIR}/etc/ftpd

D 8
lint: ftpcmd.c FRC
E 8
I 8
lint: ${SRCS} FRC
E 8
	lint ${CFLAGS} ${SRCS}

D 8
tags: ftpcmd.c FRC
E 8
I 8
tags: ${SRCS} FRC
E 8
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
I 12

ftpd.o: ftpd.c /usr/include/sys/param.h /usr/include/sys/types.h
ftpd.o: /usr/include/signal.h /usr/include/machine/trap.h
ftpd.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
ftpd.o: /usr/include/sys/stat.h /usr/include/sys/ioctl.h
ftpd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ftpd.o: /usr/include/sys/socket.h /usr/include/sys/file.h
ftpd.o: /usr/include/sys/wait.h /usr/include/netinet/in.h
ftpd.o: /usr/include/arpa/ftp.h /usr/include/arpa/inet.h
ftpd.o: /usr/include/arpa/telnet.h /usr/include/stdio.h /usr/include/signal.h
ftpd.o: /usr/include/pwd.h /usr/include/setjmp.h /usr/include/netdb.h
ftpd.o: /usr/include/errno.h /usr/include/strings.h /usr/include/syslog.h
ftpd.o: /usr/include/utmp.h
ftpcmd.o: ftpcmd.c /usr/include/sys/types.h /usr/include/sys/stat.h
ftpcmd.o: /usr/include/sys/socket.h /usr/include/netinet/in.h
ftpcmd.o: /usr/include/arpa/ftp.h /usr/include/stdio.h /usr/include/signal.h
ftpcmd.o: /usr/include/machine/trap.h /usr/include/errno.h /usr/include/ctype.h
ftpcmd.o: /usr/include/pwd.h /usr/include/setjmp.h /usr/include/syslog.h
ftpcmd.o: /usr/include/arpa/telnet.h
glob.o: glob.c /usr/include/sys/param.h /usr/include/sys/types.h
glob.o: /usr/include/signal.h /usr/include/machine/trap.h
glob.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
glob.o: /usr/include/sys/dir.h /usr/include/stdio.h
ls.o: ls.c /usr/include/sys/param.h /usr/include/sys/types.h
ls.o: /usr/include/signal.h /usr/include/machine/trap.h
ls.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
ls.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/stdio.h
ls.o: /usr/include/pwd.h /usr/include/grp.h /usr/include/utmp.h
I 13
eps.o: eps.c /usr/include/sys/param.h /usr/include/sys/types.h
eps.o: /usr/include/signal.h /usr/include/machine/trap.h
eps.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
eps.o: /usr/include/ctype.h /usr/include/stdio.h /usr/include/strings.h
eps.o: /usr/include/pwd.h
I 14
specialguests.o: specialguests.c /usr/include/stdio.h /usr/include/ctype.h
specialguests.o: /usr/include/strings.h
E 14
E 13

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 12
D 10

ftpd.o: ftpd.c /usr/include/sys/param.h /usr/include/sys/types.h
D 8
ftpd.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 8
I 8
ftpd.o: /usr/include/signal.h /usr/include/machine/trap.h
ftpd.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
E 8
ftpd.o: /usr/include/sys/stat.h /usr/include/sys/ioctl.h
ftpd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ftpd.o: /usr/include/sys/socket.h /usr/include/sys/file.h
ftpd.o: /usr/include/sys/wait.h /usr/include/netinet/in.h
ftpd.o: /usr/include/arpa/ftp.h /usr/include/arpa/inet.h
ftpd.o: /usr/include/arpa/telnet.h /usr/include/stdio.h /usr/include/signal.h
ftpd.o: /usr/include/pwd.h /usr/include/setjmp.h /usr/include/netdb.h
ftpd.o: /usr/include/errno.h /usr/include/strings.h /usr/include/syslog.h
ftpd.o: /usr/include/utmp.h
ftpcmd.o: ftpcmd.c /usr/include/sys/types.h /usr/include/sys/socket.h
ftpcmd.o: /usr/include/netinet/in.h /usr/include/arpa/ftp.h
D 8
ftpcmd.o: /usr/include/stdio.h /usr/include/signal.h /usr/include/ctype.h
ftpcmd.o: /usr/include/pwd.h /usr/include/setjmp.h /usr/include/syslog.h
E 8
I 8
ftpcmd.o: /usr/include/stdio.h /usr/include/signal.h
ftpcmd.o: /usr/include/machine/trap.h /usr/include/ctype.h /usr/include/pwd.h
ftpcmd.o: /usr/include/setjmp.h /usr/include/syslog.h
E 8
ftpcmd.o: /usr/include/arpa/telnet.h
glob.o: glob.c /usr/include/sys/param.h /usr/include/sys/types.h
D 8
glob.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 8
I 8
glob.o: /usr/include/signal.h /usr/include/machine/trap.h
glob.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
E 8
glob.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/stdio.h
glob.o: /usr/include/errno.h /usr/include/pwd.h
vers.o: vers.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 10
E 7
E 5
E 2
E 1
