h54068
s 00001/00001/00040
d D 6.5 88/05/19 16:48:22 karels 7 6
c add letterhead.me
e
s 00027/00022/00014
d D 6.4 88/04/22 12:16:19 bostic 6 5
c minor cleanups
e
s 00004/00005/00032
d D 6.3 87/10/03 14:46:08 bostic 5 4
c clean up directory creation
e
s 00013/00021/00024
d D 6.2 87/06/21 14:51:35 bostic 4 3
c new template
e
s 00029/00007/00016
d D 6.1 86/05/21 21:46:19 mckusick 3 2
c update from Jim McKie
e
s 00001/00001/00022
d D 1.2 86/05/15 04:19:44 lepreau 2 1
c DESTDIR; ensure mode 644
e
s 00023/00000/00000
d D 1.1 85/04/29 19:02:09 eric 1 0
c date and time created 85/04/29 19:02:09 by eric
e
u
U
f i 
t
T
I 1
#
I 3
D 4
# Copyright (c) 1980 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
D 6
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 6
I 6
# All rights reserved.
E 6
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
D 6
#	%W%	(Berkeley)	%G%
E 6
I 6
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 6
E 4
#
E 3
D 4
#  Makefile for -me macros
#
#	This makefile strips comments from the source files and
#	installs them in the expected directories.
#
D 3
#	%W%	%Y%	%E%
#
E 3
I 3
DESTDIR=
LIB =	/usr/lib/me
E 4
I 4
D 6
CFLAGS=	-O
LIBC=	/lib/libc.a
LIB=	/usr/lib/me
SRCS=	tmac.e acm.me chars.me deltext.me eqn.me float.me footnote.me \
E 6
I 6
#	%W% (Berkeley) %G%
#
MELIB=	/usr/lib/me
TMLIB=	/usr/lib/tmac
MESRCS=	acm.me chars.me deltext.me eqn.me float.me footnote.me \
E 6
D 7
	index.me local.me null.me refer.me sh.me tbl.me thesis.me
E 7
I 7
	index.me letterhead.me local.me null.me refer.me sh.me tbl.me thesis.me
E 7
I 6
TMSRCS=	tmac.e
E 6
E 4
E 3

D 3
SRCS=	tmac.e acm.me chars.me deltext.me eqn.me \
E 3
I 3
D 4
SRCS =	tmac.e acm.me chars.me deltext.me eqn.me \
E 3
	float.me footnote.me index.me local.me null.me \
	refer.me sh.me tbl.me thesis.me
D 3
GET=	sccs get
E 3
I 3
GET =	sccs get
E 4
I 4
all:
E 4
E 3

D 4
all: revisions $(SRCS)

D 3
install: revisions $(SRCS) install.csh
D 2
	csh install.csh $(SRCS)
E 2
I 2
	DEST=$(DESTDIR) csh install.csh $(SRCS)
E 3
I 3
install: revisions $(SRCS)
E 4
I 4
install: FRC
E 4
D 5
	-if [ ! -d ${DESTDIR}${LIB} ]; then \
		rm -f ${DESTDIR}${LIB}; \
		mkdir ${DESTDIR}${LIB}; \
	fi
E 5
I 5
D 6
	-[ -d ${DESTDIR}${LIB} ] || mkdir ${DESTDIR}${LIB}
	chown bin.bin ${DESTDIR}${LIB}
	chmod 755 ${DESTDIR}${LIB}
E 5
	-for i in ${SRCS}; do \
		sed -e '/%beginstrip%/{' \
		    -e 'h' \
		    -e 's/.*/.\\" This version has had comments stripped; an unstripped version is available./p' \
		    -e 'g' \
		    -e '}' \
		    -e '/%beginstrip%/,$$s/[. 	][ 	]*\\".*//' \
		    -e '/^$$/d' \
		    -e '/\\n@/d' $$i > _mac_tmp_; \
D 4
		install -m 0444 _mac_tmp_ ${DESTDIR}${LIB}/$$i; \
E 4
I 4
D 5
		install -o bin -g bin -m 644 _mac_tmp_ ${DESTDIR}${LIB}/$$i; \
E 5
I 5
		install -o bin -g bin -m 444 _mac_tmp_ ${DESTDIR}${LIB}/$$i; \
E 6
I 6
	-[ -d ${DESTDIR}${MELIB} ] || mkdir ${DESTDIR}${MELIB}
	-[ -d ${DESTDIR}${TMLIB} ] || mkdir ${DESTDIR}${TMLIB}
	chown bin.bin ${DESTDIR}${MELIB} ${DESTDIR}${TMLIB}
	chmod 755 ${DESTDIR}${MELIB} ${DESTDIR}${TMLIB}
	for i in ${MESRCS}; do \
		sed -f strip.sed < $$i > ${DESTDIR}${MELIB}/$$i; \
		chown bin.bin ${DESTDIR}${MELIB}/$$i; \
		chmod 444 ${DESTDIR}${MELIB}/$$i; \
E 6
E 5
E 4
	done
D 6
	mv ${DESTDIR}${LIB}/tmac.e ${DESTDIR}/usr/lib/tmac/tmac.e
D 4
	install -c -m 0444 revisions ${DESTDIR}${LIB}/revisions
E 4
I 4
	install -c -o bin -g bin -m 444 revisions ${DESTDIR}${LIB}/revisions
E 6
I 6
	for i in ${TMSRCS}; do \
		sed -f strip.sed < $$i > ${DESTDIR}${TMLIB}/$$i; \
		chown bin.bin ${DESTDIR}${TMLIB}/$$i; \
		chmod 444 ${DESTDIR}${TMLIB}/$$i; \
	done
	install -c -o bin -g bin -m 444 revisions ${DESTDIR}${MELIB}/revisions
E 6
E 4
E 3
E 2

clean:
D 4

D 3
revisions install.csh $(SRCS):
E 3
I 3
revisions $(SRCS):
E 3
	$(GET) SCCS/s.$@
E 4
I 4
depend:
FRC:
E 4
E 1
