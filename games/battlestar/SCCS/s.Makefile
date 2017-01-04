h28618
s 00010/00005/00077
d D 5.2 88/06/19 14:10:43 bostic 16 15
c install approved copyright notice
e
s 00009/00003/00073
d D 5.1 88/05/08 15:49:08 bostic 15 14
c add Berkeley header; yank to 5.1
e
s 00003/00002/00073
d D 1.10 87/09/21 11:25:49 bostic 14 10
c integrate with dm
e
s 00005/00002/00073
d R 1.10 87/09/19 17:02:53 bostic 13 10
c integrate iwth dm
e
s 00005/00002/00073
d R 1.10 87/09/19 13:51:59 bostic 12 10
c integrate with dm
e
s 00004/00002/00073
d R 1.10 87/09/19 13:06:48 bostic 11 10
c integrate with dm
e
s 00063/00032/00012
d D 1.9 87/06/05 16:11:26 bostic 10 8
c new template
e
s 00065/00032/00012
d R 1.9 87/06/03 11:18:31 bostic 9 8
c new template
e
s 00002/00000/00042
d D 1.8 87/05/31 20:58:10 bostic 8 7
c added depend label
e
s 00002/00000/00040
d D 1.7 85/04/25 20:45:35 edward 7 6
c depend on externs.h
e
s 00006/00000/00034
d D 1.6 85/04/24 15:29:06 edward 6 5
c copyright messages
e
s 00008/00039/00026
d D 1.5 85/04/23 10:03:17 edward 5 4
c reorganized, data files removed
e
s 00001/00001/00064
d D 1.4 85/04/22 02:36:11 edward 4 3
c don't install with -c
e
s 00002/00002/00063
d D 1.3 84/12/03 17:29:12 edward 3 2
c DEST to DESTDIR
e
s 00006/00002/00059
d D 1.2 84/12/03 17:25:58 edward 2 1
c remove dayfile.c and nightfile.c after compiling, save space
e
s 00061/00000/00000
d D 1.1 84/11/20 17:53:58 edward 1 0
c date and time created 84/11/20 17:53:58 by edward
e
u
U
t
T
I 6
#
D 10
# Copyright (c) 1983 Regents of the University of California,
# All rights reserved.  Redistribution permitted subject to
# the terms of the Berkeley Software License Agreement.
E 10
I 10
# Copyright (c) 1987 Regents of the University of California.
D 15
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 15
I 15
# All rights reserved.
E 15
E 10
#
I 10
D 15
#	%W%	(Berkeley)	%G%
E 15
I 15
# Redistribution and use in source and binary forms are permitted
D 16
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
#
#	%W% (Berkeley) %G%
E 15
#
CFLAGS=	-O
LIBC=	/lib/libc.a
LIBS=	-lcurses -ltermlib
OBJS=	battlestar.o com1.o com2.o com3.o com4.o com5.o com6.o com7.o \
	init.o cypher.o getcom.o parse.o room.o save.o fly.o misc.o \
	globals.o dayfile.o nightfile.o dayobjs.o nightobjs.o words.o
SRCS=	battlestar.c com1.c com2.c com3.c com4.c com5.c com6.c com7.c \
	init.c cypher.c getcom.c parse.c room.c save.c fly.c misc.c \
	globals.c dayfile.c nightfile.c dayobjs.c nightobjs.c words.c
E 10

E 6
I 1
D 10
# %W% %G%
E 10
I 10
all: battlestar
E 10

D 10
CFLAGS=		-O
OBJS=		battlestar.o com1.o com2.o com3.o com4.o com5.o com6.o com7.o \
		init.o cypher.o getcom.o parse.o room.o save.o fly.o misc.o \
D 5
		globals.o \
		wlist.o dayfile.o nightfile.o dayobjs.o nightobjs.o
E 5
I 5
		globals.o dayfile.o nightfile.o dayobjs.o nightobjs.o words.o
E 5
CFILES=		battlestar.c com1.c com2.c com3.c com4.c com5.c com6.c com7.c \
		init.c cypher.c getcom.c parse.c room.c save.c fly.c misc.c \
D 5
		globals.c
E 5
I 5
		globals.c dayfile.c nightfile.c dayobjs.c nightobjs.c words.c
E 5
LIBS=		-lcurses -ltermlib
LINTFLAGS=	-h
D 5
JUNKFILES=	battlestar tags mkfile mkwlist mkobjs \
		wlist.c dayfile.c nightfile.c dayobjs.c nightobjs.c
DATAFILES=	dayfile nightfile battlewords dayobjs nightobjs
E 5
I 5
JUNKFILES=	battlestar tags
E 5
D 3
DIR=		$(DEST)/usr/games
E 3
I 3
DIR=		$(DESTDIR)/usr/games
E 3
LOGFILE=	$(DIR)/lib/battlestar.log
D 3
MAN=		$(DEST)/usr/man/man6/battlestar.6
E 3
I 3
MAN=		$(DESTDIR)/usr/man/man6/battlestar.6
E 10
I 10
battlestar: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} ${LIBS}
E 10
E 3

D 5
battlestar: ${OBJS}
	cc ${OBJS} ${LIBS} -o battlestar
E 5
I 5
D 10
battlestar: $(OBJS)
	cc -o battlestar $(OBJS) $(LIBS)
E 10
I 10
clean: FRC
	rm -f ${OBJS} core battlestar
E 10
E 5

I 7
D 10
$(OBJS): externs.h
E 10
I 10
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 10

E 7
D 5
mkfile: mkfile.c
	$(CC) $(CFLAGS) -o mkfile mkfile.c
E 5
I 5
D 10
lint: $(CFILES) 
	lint $(LINTFLAGS) $(CFILES) $(LIBS) 
E 10
I 10
install: FRC
D 14
	install -s -o bin -g bin -m 755 battlestar ${DESTDIR}/usr/games/battlestar
	install -c -o bin -g bin -m 666 /dev/null ${DESTDIR}/usr/games/lib/battlestar.log
E 14
I 14
	install -s -o games -g bin -m 4700 battlestar ${DESTDIR}/usr/games/hide/battlestar
	install -c -o games -g bin -m 600 /dev/null ${DESTDIR}/usr/games/lib/battlestar.log
	(cd ${DESTDIR}/usr/games; rm -f battlestar; ln -s dm battlestar; chown games.bin battlestar)
E 14
E 10
E 5

D 2
dayfile.c: dayfile mkfile
E 2
I 2
D 5
dayfile.o: dayfile mkfile
E 2
	mkfile dayfile
I 2
	$(CC) $(CFLAGS) -c dayfile.c
	rm dayfile.c
E 2

D 2
nightfile.c: nightfile mkfile
E 2
I 2
nightfile.o: nightfile mkfile
E 2
	mkfile nightfile
I 2
	$(CC) $(CFLAGS) -c nightfile.c
	rm nightfile.c
E 2

mkwlist: mkwlist.c
	$(CC) $(CFLAGS) -o mkwlist mkwlist.c

wlist.c: battlewords mkwlist
	mkwlist battlewords

mkobjs: mkobjs.c
	$(CC) $(CFLAGS) -o mkobjs mkobjs.c

dayobjs.c: dayobjs mkobjs
	mkobjs dayobjs

nightobjs.c: nightobjs mkobjs
	mkobjs nightobjs

lint: ${CFILES} 
	lint ${LINTFLAGS} ${CFILES} ${LIBS} 

E 5
D 10
install: battlestar $(MAN) $(LOGFILE)
D 4
	install -s -c battlestar $(DIR)/battlestar
E 4
I 4
	install -s battlestar $(DIR)/battlestar
E 10
I 10
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 10
E 4

D 10
logfile $(LOGFILE):
	cp /dev/null $(LOGFILE)
	chmod 666 $(LOGFILE)
E 10
I 10
tags: FRC
	ctags ${SRCS}
E 10

D 10
man $(MAN):
	install -c battlestar.6 $(MAN)
E 10
I 10
FRC:
E 10

D 10
clean:
D 5
	rm -f ${OBJS} ${JUNKFILES}
E 5
I 5
	rm -f $(OBJS) $(JUNKFILES)
E 10
I 10
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 10
I 8

D 10
depend:
E 10
I 10
battlestar.o: battlestar.c externs.h /usr/include/sys/signal.h
battlestar.o: /usr/include/stdio.h
com1.o: com1.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
com2.o: com2.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
com3.o: com3.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
com4.o: com4.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
com5.o: com5.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
com6.o: com6.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
com6.o: /usr/include/sys/time.h /usr/include/time.h
com7.o: com7.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
init.o: init.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
init.o: /usr/include/pwd.h
cypher.o: cypher.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
getcom.o: getcom.c /usr/include/stdio.h /usr/include/ctype.h
parse.o: parse.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
room.o: room.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
save.o: save.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
fly.o: fly.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
fly.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
fly.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
fly.o: /usr/include/sys/ttydev.h
misc.o: misc.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
globals.o: globals.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
dayfile.o: dayfile.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
nightfile.o: nightfile.c externs.h /usr/include/sys/signal.h
nightfile.o: /usr/include/stdio.h
dayobjs.o: dayobjs.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h
nightobjs.o: nightobjs.c externs.h /usr/include/sys/signal.h
nightobjs.o: /usr/include/stdio.h
words.o: words.c externs.h /usr/include/sys/signal.h /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 10
E 8
E 5
E 1
