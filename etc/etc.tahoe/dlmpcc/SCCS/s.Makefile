h26471
s 00002/00001/00032
d D 5.2 87/11/23 18:31:43 bostic 2 1
c add firmware
e
s 00033/00000/00000
d D 5.1 87/11/15 14:33:53 sam 1 0
c date and time created 87/11/15 14:33:53 by sam
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a

all:	dlmpcc

dlmpcc: dlmpcc.c ${LIBC}
	${CC} ${CFLAGS} -o $@ $@.c

clean:
	rm -f dlmpcc core a.out errs

depend:
	mkdep -p ${CFLAGS} dlmpcc.c

D 2
install: dlmpcc
E 2
I 2
install:
E 2
	install -s -o bin -g bin -m 755 dlmpcc ${DESTDIR}/etc/dlmpcc
I 2
	install -c -o bin -g bin -m 444 firmware/* ${DESTDIR}/etc
E 2

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

dlmpcc: dlmpcc.c /usr/include/stdio.h /usr/include/ctype.h /usr/include/fcntl.h
dlmpcc: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
dlmpcc: /usr/include/sys/ttydev.h /usr/include/errno.h /usr/include/sys/types.h
dlmpcc: /usr/include/tahoevba/mpreg.h /usr/include/stdio.h scnhdr.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
