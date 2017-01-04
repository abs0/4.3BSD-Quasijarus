#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
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
#
#	@(#)Makefile	5.11 (Berkeley) 4/16/11
#
CFLAGS=	-O -DGZCOMPAT
LIBC=	/lib/libc.a
SRCS=	ftpd.c ftpcmd.c glob.c ls.c eps.c specialguests.c
OBJS=	ftpd.o ftpcmd.o glob.o ls.o eps.o specialguests.o

all: ftpd

ftpd: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS}

clean: FRC
	rm -f ${OBJS} ftpd core ftpcmd.c

depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 ftpd ${DESTDIR}/etc/ftpd

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

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
eps.o: eps.c /usr/include/sys/param.h /usr/include/sys/types.h
eps.o: /usr/include/signal.h /usr/include/machine/trap.h
eps.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
eps.o: /usr/include/ctype.h /usr/include/stdio.h /usr/include/strings.h
eps.o: /usr/include/pwd.h
specialguests.o: specialguests.c /usr/include/stdio.h /usr/include/ctype.h
specialguests.o: /usr/include/strings.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
