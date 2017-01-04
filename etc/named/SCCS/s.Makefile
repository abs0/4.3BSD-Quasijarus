h08864
s 00016/00001/00061
d D 4.16 99/09/29 17:44:07 msokolov 16 15
c build and install nsquery and nslookup too!
e
s 00000/00000/00062
d D 4.15 99/09/29 17:38:13 msokolov 15 14
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.14 99/09/29 17:38:12 msokolov 14 13
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.13 99/09/29 17:38:10 msokolov 13 12
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.12 99/09/29 17:38:09 msokolov 12 11
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.11 99/09/29 17:38:08 msokolov 11 10
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.10 99/09/29 17:38:07 msokolov 10 9
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.9 99/09/29 17:38:06 msokolov 9 8
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.8 99/09/29 17:38:04 msokolov 8 7
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.7 99/09/29 17:38:03 msokolov 7 6
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.6 99/09/29 17:38:02 msokolov 6 5
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.5 99/09/29 17:38:01 msokolov 5 4
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.4 99/09/29 17:38:00 msokolov 4 3
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.3 99/09/29 17:37:58 msokolov 3 2
c bump it up to 4.15
e
s 00000/00000/00062
d D 4.2 99/09/29 17:37:57 msokolov 2 1
c bump it up to 4.15
e
s 00062/00000/00000
d D 4.1 99/09/29 17:37:17 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 4.15
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
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
#	%W% (Berkeley) %G%
#
RES=
DEFINES= -DDEBUG -DSTATS
### -DALLOW_T_UNSPEC -Dmalloc=rt_malloc -Dfree=rt_free
### ALLOC=storage.o
CFLAGS=	-O ${DEFINES}
LDFLAGS= ${RES}
LIBC=	/lib/libc.a
SRCS=	db_dump.c db_load.c db_lookup.c db_reload.c db_save.c db_update.c \
	ns_forw.c ns_init.c ns_main.c ns_maint.c ns_req.c ns_resp.c \
	ns_sort.c ns_stats.c
HDRS=	db.h ns.h
OBJS=	db_dump.o db_load.o db_lookup.o db_reload.o db_save.o db_update.o \
	ns_forw.o ns_init.o ns_main.o ns_maint.o ns_req.o ns_resp.o \
	ns_sort.o ns_stats.o $(ALLOC)
SUBDIR=	tools

D 16
all: named
E 16
I 16
all: named ${SUBDIR}
E 16

named:	${OBJS} ${LIBC}
	sh newvers.sh
	${CC} -o $@ version.c ${OBJS} ${LDFLAGS}

I 16
tools: FRC
	cd tools; make ${MFLAGS} RES=${RES}

E 16
clean: FRC
	rm -f ${OBJS} core named version.o version.c
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} clean); \
	done

depend: FRC
	mkdep ${CFLAGS} ${SRCS}
I 16
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} depend); \
	done
E 16

install: FRC
	install -s -o bin -g bin -m 755 named ${DESTDIR}/etc/named
I 16
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} install); \
	done
E 16

lint: FRC
	lint -Dlint ${CFLAGS} ${SRCS}
I 16
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} lint); \
	done
E 16

tags: FRC
	ctags -t ${SRCS} ${HDRS}
I 16
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} tags); \
	done
E 16

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 1
