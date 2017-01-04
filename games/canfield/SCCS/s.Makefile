h64801
s 00010/00005/00054
d D 5.3 88/06/18 19:49:11 bostic 3 2
c install approved copyright notice
e
s 00011/00005/00048
d D 5.2 88/05/06 10:36:34 bostic 2 1
c add Berkeley header
e
s 00053/00000/00000
d D 5.1 87/12/12 17:21:52 bostic 1 0
c date and time created 87/12/12 17:21:52 by bostic
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
D 2
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 2
I 2
# All rights reserved.
E 2
#
D 2
#	%W%	(Berkeley)	%G%
E 2
I 2
# Redistribution and use in source and binary forms are permitted
D 3
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
E 2
#
I 2
#	%W% (Berkeley) %G%
#
E 2
CFLAGS=	-O
LIBC=	/lib/libc.a
CSRCS=	canfield.c
CFSRCS=	cfscores.c

all: canfield cfscores

canfield: ${LIBC}
	${CC} -o $@ ${CFLAGS} ${CSRCS} -lcurses -ltermcap

cfscores: ${LIBC}
	${CC} -o $@ ${CFLAGS} ${CFSRCS}

clean: FRC
	rm -f core canfield cfscores

depend: FRC
	mkdep -p ${CFLAGS} ${CSRCS} ${CFSRCS}

install: FRC
	install -s -o games -g bin -m 700 canfield ${DESTDIR}/usr/games/hide
	install -s -o games -g bin -m 700 cfscores ${DESTDIR}/usr/games/hide
	(cd ${DESTDIR}/usr/games; rm -f canfield; ln -s dm canfield; chown games.bin canfield)
	(cd ${DESTDIR}/usr/games; rm -f cfscores; ln -s dm cfscores; chown games.bin cfscores)
	-[ -f ${DESTDIR}/usr/games/lib/cfscores ] || install -c -o games -g bin -m 600 /dev/null ${DESTDIR}/usr/games/lib/cfscores

lint: FRC
	lint ${CFLAGS} ${CSRCS}
	lint ${CFLAGS} ${CFSRCS}

tags: FRC
	ctags ${CSRCS} ${CFSRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

canfield: canfield.c /usr/include/curses.h /usr/include/stdio.h
canfield: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 2
canfield: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
canfield: /usr/include/ctype.h /usr/include/signal.h
E 2
I 2
canfield: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
canfield: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/signal.h
E 2
canfield: /usr/include/machine/trap.h /usr/include/sys/types.h
cfscores: cfscores.c /usr/include/pwd.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
