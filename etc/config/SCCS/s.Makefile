h06074
s 00005/00002/00077
d D 5.8 04/03/02 17:48:22 msokolov 23 22
c add vaxflatten.c
e
s 00011/00006/00068
d D 5.7 88/06/18 13:42:55 bostic 22 21
c install approved copyright notice
e
s 00013/00006/00061
d D 5.6 88/04/29 13:47:54 bostic 21 20
c add Berkeley specific header; original conception by Michael Toy
e
s 00042/00039/00025
d D 5.5 87/06/02 21:46:40 bostic 20 14
c new template
e
s 00042/00039/00025
d R 5.5 87/06/02 20:28:41 bostic 19 14
c new template
e
s 00042/00039/00025
d R 5.5 87/06/02 20:12:34 bostic 18 14
c new template
e
s 00042/00039/00025
d R 5.5 87/06/02 20:01:33 bostic 17 14
c new template
e
s 00040/00037/00027
d R 5.5 87/06/02 19:17:17 bostic 16 14
c using new template
e
s 00040/00037/00027
d R 5.5 87/06/02 18:36:09 bostic 15 14
c new version
e
s 00006/00001/00058
d D 5.4 86/10/13 15:35:24 sam 14 13
c replace ancient sun support with tahoe support
e
s 00003/00005/00056
d D 5.3 86/02/18 17:54:20 sam 13 12
c mkubglue rewritten and renamed to mkglue
e
s 00001/00004/00060
d D 5.2 86/01/11 16:54:47 lepreau 12 11
c avoid uneeded y.tab.c recompilation
e
s 00007/00001/00057
d D 5.1 85/05/08 11:59:17 dist 11 10
c Add copyright
e
s 00035/00005/00023
d D 1.10 83/05/18 00:19:18 sam 10 9
c dynamically create swap configuration files
e
s 00001/00001/00027
d D 1.9 83/03/28 23:12:15 sam 9 8
c strip installed version please
e
s 00004/00004/00024
d D 1.8 82/12/09 21:34:06 sam 8 7
c somehow the -p option went away
e
s 00005/00005/00023
d D 1.7 82/10/25 00:59:01 root 7 6
c lint and cleanup
e
s 00012/00009/00016
d D 1.6 82/10/24 23:14:03 root 6 5
c fixups
e
s 00002/00001/00023
d D 1.5 82/10/19 22:59:15 mckusick 5 4
c set DESTDIR
e
s 00004/00000/00020
d D 1.4 82/06/15 14:53:51 mckusick 4 3
c add keywords
e
s 00004/00001/00016
d D 1.3 82/06/15 14:51:49 mckusick 3 2
c reorder OBJS so that yacc runs first to get y.tab.h; add install entry
e
s 00001/00001/00016
d D 1.2 82/05/10 17:40:50 sam 2 1
c missing stuff
e
s 00017/00000/00000
d D 1.1 81/02/24 15:51:25 toy 1 0
c date and time created 81/02/24 15:51:25 by toy
e
u
U
t
T
I 4
D 6
# Copyright (c) 1982 Regents of the University of California
E 6
D 10
#
E 10
D 6
#	%W%	%G%
E 6
I 6
D 11
#	%M%	%I%	%E%
E 11
I 11
#
D 20
# Copyright (c) 1980 Regents of the University of California.
E 20
I 20
D 22
# Copyright (c) 1987 Regents of the University of California.
E 22
I 22
# Copyright (c) 1988 Regents of the University of California.
E 22
E 20
D 21
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 21
I 21
# All rights reserved.
E 21
#
D 20
#	%W% (Berkeley) %G%
E 20
I 20
D 21
#	%W%	(Berkeley)	%G%
E 21
I 21
# Redistribution and use in source and binary forms are permitted
D 22
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 22
I 22
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
E 22
E 21
E 20
#
I 21
#	%W% (Berkeley) %G%
#
E 21
E 11
E 6
D 20
#
I 5
D 6
DESTDIR=
E 5
E 4
I 1
D 3
OBJS = main.o y.tab.o lex.yy.o mkioconf.o mkmakefile.o mkubglue.o mkheaders.o
E 3
I 3
OBJS = y.tab.o main.o lex.yy.o mkioconf.o mkmakefile.o mkubglue.o mkheaders.o
E 3
CFLAGS=-w
E 6
I 6
D 10
CFILES=	y.tab.c main.c lex.yy.c mkioconf.c mkmakefile.c mkubglue.c mkheaders.c
D 8
OFILES=	y.tab.o main.o lex.yy.o mkioconf.o mkmakefile.o mkubglue.o mkheaders.o
E 8
I 8
OBJS=	y.tab.o main.o lex.yy.o mkioconf.o mkmakefile.o mkubglue.o mkheaders.o
E 10
I 10
CFILES=	y.tab.c main.c lex.yy.c mkioconf.c mkmakefile.c \
E 20
I 20
CFLAGS=	-O
LIBC=	/lib/libc.a
LIBS=	-ll
SRCS=	y.tab.c main.c lex.yy.c mkioconf.c mkmakefile.c \
E 20
D 13
	mkubglue.c mkheaders.c mkswapconf.c
E 13
I 13
D 23
	mkglue.c mkheaders.c mkswapconf.c
E 23
I 23
	mkglue.c mkheaders.c mkswapconf.c vaxflatten.c
E 23
E 13
OBJS=	y.tab.o main.o lex.yy.o mkioconf.o mkmakefile.o \
D 13
	mkubglue.o mkheaders.o mkswapconf.o
E 13
I 13
D 23
	mkglue.o mkheaders.o mkswapconf.o
E 23
I 23
	mkglue.o mkheaders.o mkswapconf.o vaxflatten.o
E 23
E 13
E 10
E 8

D 7
CFLAGS=	-w
E 7
I 7
D 8
CFLAGS=
E 8
I 8
D 20
CFLAGS=-O
E 8
E 7
E 6
LDFLAGS=-ll
E 20
I 20
all: config
E 20

D 6
config: $(OBJS)
	$(CC) $(OBJS) -o config $(LDFLAGS)
E 6
I 6
D 8
config: ${OFILES}
	${CC} ${OFILES} -o config ${LDFLAGS}
E 8
I 8
D 20
config: ${OBJS}
	${CC} ${OBJS} -o config ${LDFLAGS}
E 20
I 20
config: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS} ${LIBS}
E 20
E 8
E 6

I 7
lex.yy.c: config.l
	lex config.l

E 7
D 10
y.tab.o: y.tab.c
E 10
I 10
D 12
y.tab.h: 
E 12
I 12
D 14
y.tab.h y.tab.c: config.y
E 14
I 14
y.tab.h: 
E 14
E 12
	yacc -d config.y
E 10
D 12

y.tab.c: config.y
D 10
	yacc -d config.y
E 10
I 10
	yacc config.y
E 12
E 10

I 14
y.tab.c: config.y
	yacc config.y

E 14
D 7
lex.yy.c: config.l
	lex config.l

E 7
D 20
clean:
D 2
	rm -f $(OBJS) lex.yy.c y.tab.c
E 2
I 2
D 6
	rm -f $(OBJS) lex.yy.c y.tab.c y.tab.h config
E 6
I 6
	rm -f ${OBJS} lex.yy.c y.tab.c y.tab.h config
E 20
I 20
clean: FRC
	rm -f ${OBJS} lex.yy.c y.tab.c y.tab.h config core
E 20
E 6
I 3

D 20
install:
D 5
	cp config /etc/config
E 5
I 5
D 6
	install config $(DESTDIR)/etc/config
E 6
I 6
D 9
	install config ${DESTDIR}/etc/config
E 9
I 9
	install -s config ${DESTDIR}/etc/config
E 20
I 20
D 21
depend: y.tab.c lex.yy.c y.tab.h FRC
E 21
I 21
depend: y.tab.h ${SRCS} FRC
E 21
	mkdep ${CFLAGS} ${SRCS}
E 20
E 9

D 7
lint:
E 7
I 7
D 20
lint: ${CFILES}
E 7
	lint ${CFILES}
E 20
I 20
install: FRC
	install -s -o bin -g bin -m 755 config ${DESTDIR}/etc/config
E 20
I 10

D 20
depend:
	grep '^#include' ${CFILES} | grep -v '<' | \
	sed -e 's/:[^"]*"\([^"]*\)".*/: \1/' \
	    -e 's/\.c/.o/' \
	    -e 's,../[a-zA-Z]*/,,' | \
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '$$r makedep' >>eddep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
E 20
I 20
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 20

D 20
# DO NOT DELETE THIS LINE -- make depend uses it
E 20
I 20
tags: FRC
	ctags ${SRCS}
E 20

I 14
D 20
y.tab.o: config.h
E 14
D 13
y.tab.o: config.h
E 13
main.o: y.tab.h config.h
I 14
lex.yy.o: y.tab.h config.h
E 14
D 13
lex.yy.o: y.tab.h config.h
E 13
mkioconf.o: y.tab.h config.h
mkmakefile.o: y.tab.h config.h
D 13
mkubglue.o: config.h y.tab.h
E 13
I 13
mkglue.o: config.h y.tab.h
E 13
mkheaders.o: config.h y.tab.h
mkswapconf.o: config.h
E 20
I 20
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

y.tab.o: y.tab.c config.h /usr/include/sys/types.h /usr/include/ctype.h
y.tab.o: /usr/include/stdio.h
D 21
main.o: main.c /usr/include/stdio.h /usr/include/ctype.h y.tab.h config.h
main.o: /usr/include/sys/types.h
E 21
I 21
main.o: main.c /usr/include/sys/types.h /usr/include/sys/stat.h
main.o: /usr/include/sys/file.h /usr/include/stdio.h /usr/include/ctype.h
main.o: y.tab.h config.h /usr/include/sys/types.h
E 21
lex.yy.o: lex.yy.c /usr/include/stdio.h /usr/include/ctype.h y.tab.h config.h
lex.yy.o: /usr/include/sys/types.h
mkioconf.o: mkioconf.c /usr/include/stdio.h y.tab.h config.h
mkioconf.o: /usr/include/sys/types.h
mkmakefile.o: mkmakefile.c /usr/include/stdio.h /usr/include/ctype.h y.tab.h
mkmakefile.o: config.h /usr/include/sys/types.h
mkglue.o: mkglue.c /usr/include/stdio.h config.h /usr/include/sys/types.h
mkglue.o: y.tab.h /usr/include/ctype.h
mkheaders.o: mkheaders.c /usr/include/stdio.h /usr/include/ctype.h config.h
mkheaders.o: /usr/include/sys/types.h y.tab.h
mkswapconf.o: mkswapconf.c config.h /usr/include/sys/types.h
mkswapconf.o: /usr/include/stdio.h /usr/include/ctype.h
I 23
vaxflatten.o: vaxflatten.c /usr/include/stdio.h /usr/include/vax/nexus.h
vaxflatten.o: /usr/include/vaxuba/ubavar.h y.tab.h config.h
vaxflatten.o: /usr/include/sys/types.h
E 23

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 20
E 10
E 6
E 5
E 3
E 2
E 1
