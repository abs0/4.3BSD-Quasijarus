h58622
s 00010/00005/00094
d D 5.6 88/06/29 20:34:09 bostic 14 13
c install approved copyright notice
e
s 00010/00004/00089
d D 5.5 88/03/14 17:21:23 bostic 13 12
c add Berkeley specific headers
e
s 00081/00017/00012
d D 5.4 87/07/22 09:48:02 bostic 12 10
c new template
e
s 00081/00017/00012
d R 5.4 87/06/16 18:24:34 bostic 11 10
c new template
e
s 00002/00000/00027
d D 5.3 87/05/31 21:10:24 bostic 10 9
c added depend label
e
s 00003/00003/00024
d D 5.2 86/02/03 14:41:08 minshall 9 8
c Changes from Steve Jacobson (from <csvsj@ucbopal>).
e
s 00006/00001/00021
d D 5.1 85/05/31 16:55:42 dist 8 7
c Add copyright
e
s 00002/00002/00020
d D 4.6 83/06/15 14:13:58 sam 7 6
c getpass required
e
s 00001/00001/00021
d D 4.5 83/06/10 23:40:28 sam 6 5
c new signals; no more libjobs
e
s 00004/00012/00018
d D 4.4 83/05/11 22:02:14 sam 5 3
c split ftpd out to etc source; fix bug with sendport stuff
e
s 00004/00012/00018
d R 4.4 83/05/03 16:19:15 sam 4 3
c ftpd moved to /usr/src/etc
e
s 00002/00002/00028
d D 4.3 83/03/01 02:11:31 sam 3 2
c globbing now in use
e
s 00008/00002/00022
d D 4.2 83/01/15 16:56:53 sam 2 1
c oops, forgot install
e
s 00024/00000/00000
d D 4.1 83/01/15 16:54:57 sam 1 0
c date and time created 83/01/15 16:54:57 by sam
e
u
U
t
T
I 1
D 2
# %W% %G%
E 2
I 2
D 8
#	%W%	%G%
E 8
I 8
#
D 9
# Copyright (c) 1980 Regents of the University of California.
E 9
I 9
D 12
# Copyright (c) 1985 Regents of the University of California.
E 12
I 12
D 13
# Copyright (c) 1987 Regents of the University of California.
E 12
E 9
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 13
I 13
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 13
#
D 12
#	%W% (Berkeley) %G%
E 12
I 12
D 13
#	%W%	(Berkeley)	%G%
E 13
I 13
# Redistribution and use in source and binary forms are permitted
D 14
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
#
#	%W% (Berkeley) %G%
E 13
E 12
E 8
#
E 2
D 5
ALL=	ftp ftpd
E 5
I 5
D 12
ALL=	ftp
E 5
D 2
CFLAGS=-O
E 2
I 2
DESTDIR=
E 12
CFLAGS=	-O
I 12
LIBC=	/lib/libc.a
SRCS=	cmds.c cmdtab.c ftp.c getpass.c glob.c main.c pclose.c ruserpass.c              domacro.c
OBJS=	cmds.o cmdtab.o ftp.o getpass.o glob.o main.o pclose.o ruserpass.o              domacro.o
E 12
E 2

D 12
all:	${ALL}
E 12
I 12
all: ftp
E 12

D 3
ftp:	cmds.o cmdtab.o ftp.o main.o
	${CC} cmds.o cmdtab.o ftp.o main.o -o ftp -ljobs
E 3
I 3
D 7
ftp:	cmds.o cmdtab.o ftp.o glob.o main.o
D 6
	${CC} cmds.o cmdtab.o ftp.o glob.o main.o -o ftp -ljobs
E 6
I 6
	${CC} cmds.o cmdtab.o ftp.o glob.o main.o -o ftp 
E 7
I 7
D 9
ftp:	cmds.o cmdtab.o ftp.o getpass.o glob.o main.o
	${CC} cmds.o cmdtab.o ftp.o getpass.o glob.o main.o -o ftp 
E 9
I 9
D 12
ftp:	cmds.o cmdtab.o ftp.o getpass.o glob.o main.o pclose.o ruserpass.o              domacro.o
	${CC} cmds.o cmdtab.o ftp.o getpass.o glob.o main.o pclose.o ruserpass.o         domacro.o -o ftp 
E 12
I 12
ftp:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 12
E 9
E 7
E 6
E 3

D 5
ftp.o:	ftp.h ftp_var.h
cmds.o:	ftp.h ftp_var.h
E 5
I 5
D 12
ftp.o:	/usr/include/arpa/ftp.h ftp_var.h
cmds.o:	/usr/include/arpa/ftp.h ftp_var.h
E 5
cmdtab.o: ftp_var.h
ftp.o:	ftp_var.h
main.o: ftp_var.h
E 12
I 12
clean: FRC
	rm -f ${OBJS} core ftp
E 12

D 5
ftpd:	ftpd.o ftpcmd.o vers.o glob.o
	${CC} ftpd.o ftpcmd.o glob.o -o ftpd vers.o -ljobs

vers.o:	ftpd.c ftpcmd.y
	sh newvers.sh
	${CC} -c vers.c
I 2

E 5
D 12
install:
	install -s ftp ${DESTDIR}/usr/ucb/ftp
E 12
I 12
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 12
D 5
	install -s ftpd ${DESTDIR}/etc/ftpd
E 5
E 2

D 12
clean:
D 5
	rm -f ${ALL} *.o *.s errs core a.out t.? yacc.* y.tab.c
E 5
I 5
	rm -f ${ALL} *.o *.s errs core a.out t.?
E 12
I 12
install: FRC
	install -s -o bin -g bin -m 755 ftp ${DESTDIR}/usr/ucb/ftp
E 12
I 10

D 12
depend:
E 12
I 12
lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

cmds.o: cmds.c
cmds.o:ftp_var.h
cmds.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
cmds.o: /usr/include/machine/machparam.h /usr/include/setjmp.h
cmds.o: /usr/include/sys/socket.h /usr/include/arpa/ftp.h /usr/include/signal.h
cmds.o: /usr/include/stdio.h /usr/include/errno.h /usr/include/netdb.h
cmds.o: /usr/include/ctype.h /usr/include/sys/wait.h
cmdtab.o: cmdtab.c
cmdtab.o:ftp_var.h
cmdtab.o: /usr/include/sys/param.h /usr/include/sys/types.h
cmdtab.o: /usr/include/signal.h /usr/include/machine/machparam.h
cmdtab.o: /usr/include/setjmp.h
ftp.o: ftp.c
ftp.o:ftp_var.h
ftp.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
ftp.o: /usr/include/machine/machparam.h /usr/include/setjmp.h
ftp.o: /usr/include/sys/stat.h /usr/include/sys/ioctl.h
ftp.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ftp.o: /usr/include/sys/socket.h /usr/include/sys/time.h /usr/include/time.h
ftp.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
ftp.o: /usr/include/machine/machparam.h /usr/include/netinet/in.h
ftp.o: /usr/include/arpa/ftp.h /usr/include/arpa/telnet.h /usr/include/stdio.h
ftp.o: /usr/include/signal.h /usr/include/errno.h /usr/include/netdb.h
ftp.o: /usr/include/fcntl.h /usr/include/pwd.h /usr/include/ctype.h
getpass.o: getpass.c /usr/include/stdio.h /usr/include/signal.h
getpass.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
getpass.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
glob.o: glob.c /usr/include/sys/param.h /usr/include/sys/types.h
glob.o: /usr/include/signal.h /usr/include/machine/machparam.h
glob.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/stdio.h
glob.o: /usr/include/errno.h /usr/include/pwd.h
main.o: main.c
main.o:ftp_var.h
main.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
main.o: /usr/include/machine/machparam.h /usr/include/setjmp.h
main.o: /usr/include/sys/socket.h /usr/include/sys/ioctl.h
main.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
main.o: /usr/include/sys/types.h /usr/include/arpa/ftp.h /usr/include/signal.h
main.o: /usr/include/stdio.h /usr/include/errno.h /usr/include/ctype.h
main.o: /usr/include/netdb.h /usr/include/pwd.h
pclose.o: pclose.c /usr/include/stdio.h /usr/include/signal.h
pclose.o: /usr/include/sys/param.h /usr/include/sys/types.h
pclose.o: /usr/include/signal.h /usr/include/machine/machparam.h
pclose.o: /usr/include/sys/wait.h
ruserpass.o: ruserpass.c /usr/include/stdio.h /usr/include/utmp.h
ruserpass.o: /usr/include/ctype.h /usr/include/sys/types.h
ruserpass.o: /usr/include/sys/stat.h /usr/include/errno.h
domacro.o: domacro.c
domacro.o:ftp_var.h
domacro.o: /usr/include/sys/param.h /usr/include/sys/types.h
domacro.o: /usr/include/signal.h /usr/include/machine/machparam.h
domacro.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/stdio.h
domacro.o: /usr/include/errno.h /usr/include/ctype.h
domacro.o: /usr/include/sys/ttychars.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 12
E 10
E 5
E 1
