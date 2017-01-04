h22041
s 00041/00052/00221
d D 5.10 06/02/13 04:07:46 msokolov 32 31
c generalized subdir handling, include psfilters and psmgmt
e
s 00010/00007/00263
d D 5.9 88/06/30 17:59:32 bostic 31 30
c install approved copyright notice
e
s 00085/00066/00185
d D 5.8 88/05/05 18:07:26 bostic 30 29
c written by Ralph Campbell; add Berkeley specific header
e
s 00071/00059/00180
d D 5.7 87/12/12 17:32:11 bostic 29 28
c add vfilter directory
e
s 00205/00052/00034
d D 5.6 87/06/21 16:14:03 bostic 28 26
c new template
e
s 00205/00052/00034
d R 5.6 87/06/21 14:47:27 bostic 27 26
c new template
e
s 00001/00001/00085
d D 5.5 87/04/30 18:03:51 bostic 26 25
c lpq doesn't need termcap any more
e
s 00003/00000/00083
d D 5.4 87/04/29 15:59:27 bostic 25 24
c added make tags
e
s 00004/00004/00079
d D 5.3 86/05/07 08:56:37 bloom 24 23
c specify user when programs are setuid
e
s 00001/00001/00082
d D 5.2 86/01/12 01:56:15 lepreau 23 22
c chown -> /etc/chown
e
s 00006/00001/00077
d D 5.1 85/06/06 09:56:10 dist 22 21
c Add copyright
e
s 00005/00001/00073
d D 4.14 83/10/14 11:35:20 ralph 21 20
c added lptest program
e
s 00001/00001/00073
d D 4.13 83/08/18 17:41:11 sam 20 19
c pass DESTDIR when installing filters
e
s 00001/00001/00073
d D 4.12 83/07/27 14:40:45 ralph 19 18
c lpc no longer needs to run setuid root
e
s 00021/00017/00053
d D 4.11 83/07/02 23:48:36 root 18 17
c for ralph; also link to filters
e
s 00003/00003/00067
d D 4.10 83/06/17 14:31:29 ralph 17 16
c jobs library has gone away
e
s 00015/00091/00055
d D 4.9 83/05/13 11:53:13 ralph 16 15
c bug fixes and changes for lpc command.
e
s 00062/00040/00084
d D 4.8 83/04/29 11:52:12 ralph 15 14
c changes for new printer daemon.
e
s 00066/00019/00058
d D 4.7 83/03/09 10:44:26 ralph 14 13
c added vfontinfo vwidth pac
e
s 00003/00001/00074
d D 4.6 83/03/01 11:33:45 ralph 13 12
c fixed "make filters"
e
s 00016/00014/00059
d D 4.5 83/02/15 16:36:33 sam 12 11
c fix install
e
s 00011/00010/00062
d D 4.4 83/02/10 17:06:45 ralph 11 10
c bugs fixed and vpr options merged into lpr.
e
s 00024/00028/00048
d D 4.3 83/01/05 11:28:14 root 10 9
c Working version of remote spooling.
e
s 00004/00004/00072
d D 4.2 82/12/25 10:54:59 sam 9 8
c use install for install
e
s 00001/00000/00075
d D 4.1 82/12/03 16:40:44 mckusick 8 7
c add keywords, update to version 4
e
s 00004/00003/00071
d D 1.7 82/12/03 16:38:50 mckusick 7 6
c add DESTDIR
e
s 00010/00010/00064
d D 1.6 82/12/03 11:14:56 root 6 5
c changed the names dq and sq to lprm and lpq
e
s 00002/00002/00072
d D 1.5 82/12/03 10:33:51 ralph 5 4
c changed to make it easier to put scandir in libc.
e
s 00016/00015/00058
d D 1.4 82/12/02 11:59:18 ralph 4 3
c Updated directory scanning and sorting for new dir.h
e
s 00036/00030/00037
d D 1.3 81/11/09 11:57:06 sam 3 2
c 
e
s 00000/00002/00067
d D 1.2 81/08/05 15:04:41 sam 2 1
c strip down print object
e
s 00069/00000/00000
d D 1.1 81/05/09 16:35:26 root 1 0
c date and time created 81/05/09 16:35:26 by root
e
u
U
t
T
I 11
D 18
#	%W%	(Berkeley)	%G%
E 18
I 18
D 22
#	%M%	%I%	%E%
E 22
I 22
#
D 28
# Copyright (c) 1983 Regents of the University of California.
E 28
I 28
# Copyright (c) 1987 Regents of the University of California.
E 28
D 30
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 30
I 30
# All rights reserved.
E 30
#
D 28
#	%W% (Berkeley) %G%
E 28
I 28
D 30
#	%W%	(Berkeley)	%G%
E 30
I 30
# Redistribution and use in source and binary forms are permitted
D 31
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 31
I 31
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
E 31
E 30
E 28
E 22
E 18
E 11
I 8
D 10
#	%W%	(Berkeley)	%E%
E 10
E 8
I 1
#
I 30
#	%W% (Berkeley) %G%
D 31
#
E 30
# makefile for line printer spooling system
E 31
#
D 3
# Ownerships (see note at the top of main in lpd.c)
E 3
I 3
D 15
# Ownerships {see note at the top of main in lpd.c}
E 15
I 15
# Ownerships {see note at the top of lpd.c}
E 15
E 3
# ROOT		a user that can access any and all files
# DAEMON	someone special
# SPGRP		the group id of the spooling programs
#
I 14
D 18

E 18
E 14
D 3
CFLAGS=-O -DSYTEK
LDFLAGS=-z
E 3
I 3
D 11
CFLAGS=-O
E 11
I 11
D 12

E 12
D 15
CFLAGS=-O -DBSD41C
E 11
LDFLAGS=
E 15
I 15
D 28
CFLAGS=-O
E 15
E 3
D 7
LIBDIR=/usr/lib
D 3
BINDIR=/usr/bin
E 3
I 3
BINDIR=/usr/ucb
E 3
SPOOLDIR=/usr/spool/lpd
E 7
I 7
D 10
DESTDIR=
LIBDIR=${DESTDIR}/usr/lib
BINDIR=${DESTDIR}/usr/ucb
SPOOLDIR=${DESTDIR}/usr/spool/lpd
E 10
I 10
LIBDIR=/usr/lib
BINDIR=/usr/ucb
SPOOLDIR=/usr/spool/lpd
E 10
E 7
CXREF=/usr/ucb/ctags -x
ROOT=root
DAEMON=daemon
D 3
SPGRP=spool
E 3
I 3
SPGRP=daemon
I 12
DESTDIR=
E 12
E 3
D 18

E 18
D 3
all: lpd lpr sq dq
E 3
I 3
D 6
all: lpd lpr sq dq lpdrestart filters
E 6
I 6
D 10
all: lpd lpr lpq lprm lpdrestart filters
E 10
I 10
D 11
all: lpd rlpr lpr lpq lprm lpdrestart filters
E 11
I 11
D 12
SRCS=lpd.c rlpr.c lpr.c lpq.c lprm.c lpdrestart.c lpdchar.c getq.c printcap.c \
	lpf.c necf.c
OBJS=lpd rlpr lpr lpq lprm lpdrestart
E 12
I 12
D 15
SRCS=	lpd.c rlpr.c lpr.c lpq.c lprm.c lpdrestart.c \
D 14
	lpdchar.c getq.c printcap.c lpf.c necf.c
OBJS=	lpd rlpr lpr lpq lprm lpdrestart
E 12
D 13
filters=lpf necf
E 13
I 13
FLTRS=	lpf necf
E 14
I 14
	lpdchar.c getq.c printcap.c lpf.c necf.c \
	rvsort.c rvcat.c vsort.c vcat.c vpf.c vpsf.c \
	vpltdmp.c vfontinfo.c vwidth.c pac.c
OBJS=	lpd rlpr lpr lpq lprm lpdrestart vfontinfo vwidth pac
FLTRS=	lpf necf rvsort rvcat vsort vcat vpf vpsf vpltdmp
E 15
I 15
D 16
SRCS=	lpd.c lpr.c lpq.c lprm.c restart.c pac.c \
	startup.c printjob.c recvjob.c displayq.c rmjob.c \
	startdaemon.c common.c printcap.c lpdchar.c lpf.c necf.c \
	rvsort.c rvcat.c vsort.c vcat.c vpf.c vpsf.c vdmp.c vpltdmp.c \
	vfontinfo.c vwidth.c vfw.c fcvt.c rotate.c rotprt.c
OBJS=	lpd lpr lpq lprm restart pac
PRINTER=	lpf necf
VARIAN=	rvsort rvcat vsort vcat vpf vpsf vdmp vpltdmp vfontinfo vwidth \
	vfw fcvt rotate rotprt
E 16
I 16
SRCS=	lpd.c lpr.c lpq.c lprm.c pac.c lpd.c cmds.c cmdtab.c \
	printjob.c recvjob.c displayq.c rmjob.c \
	startdaemon.c common.c printcap.c lpdchar.c
E 28
I 28
CFLAGS=	-O
LIBDIR=	/usr/lib
BINDIR=	/usr/ucb
SPLDIR=	/usr/spool/lpd
ROOT=	root
DAEMON=	daemon
SPGRP=	daemon
LIBC=	/lib/libc.a
L1SRCS=	lpd.c printjob.c recvjob.c displayq.c rmjob.c startdaemon.c \
	lpdchar.c common.c printcap.c
L1OBJS=	lpd.o printjob.o recvjob.o displayq.o rmjob.o startdaemon.o \
	lpdchar.o common.o printcap.o
L2SRCS=	lpr.c startdaemon.c printcap.c
L2OBJS=	lpr.o startdaemon.o printcap.o
L3SRCS=	lpq.c displayq.c common.c printcap.c
L3OBJS=	lpq.o displayq.o common.o printcap.o
L4SRCS=	lprm.c rmjob.c startdaemon.c common.c printcap.c
L4OBJS=	lprm.o rmjob.o startdaemon.o common.o printcap.o
L5SRCS=	lpc.c cmds.c cmdtab.c startdaemon.c common.c printcap.c
L5OBJS=	lpc.o cmds.o cmdtab.o startdaemon.o common.o printcap.o
L6SRCS=	lptest.c
L6OBJS=	lptest.o
L7SRCS=	pac.c printcap.c
L7OBJS=	pac.o printcap.o
SRCS=	lpd.c lpr.c lpq.c lprm.c pac.c lpd.c cmds.c cmdtab.c printjob.c \
	recvjob.c displayq.c rmjob.c startdaemon.c common.c printcap.c \
	lpdchar.c
OBJS=	${L1OBJS} ${L2OBJS} ${L3OBJS} ${L4OBJS} ${L5OBJS} ${L6OBJS} ${L7OBJS}
E 28
D 18
OBJS=	lpd lpr lpq lprm pac lpc
E 18
I 18
D 21
ALL=	lpd lpr lpq lprm pac lpc
E 21
I 21
ALL=	lpd lpr lpq lprm lpc lptest pac
I 32
SUBDIR=	filters psfilters psmgmt vfilters
E 32
E 21
E 18
E 16
E 15
E 14
E 13
E 11
E 10
E 6
E 3

D 3
filters: necf lpf
E 3
I 3
D 10
filters: necf lpf laf
E 10
I 10
D 11
filters: laf lpf necf
E 11
I 11
D 18
all:	${OBJS}
E 18
I 18
D 29
all:	${ALL} FILTERS
E 29
I 29
D 32
all:	${ALL} FILTERS VFILTERS
E 32
I 32
all:	${ALL} ${SUBDIR}
E 32
E 29
E 18
I 13

D 14
filters: ${FILTERS}
E 14
I 14
D 15
filters: ${FLTRS}
E 15
I 15
D 16
printer: ${PRINTER}
E 15
E 14
E 13
E 11
E 10
E 3

D 4
lpd:	lpd.o lpdchar.o printcap.o
D 3
	$(CC) -o lpd $(LDFLAGS) lpd.o lpdchar.o printcap.o
E 3
I 3
	${CC} -o lpd ${LDFLAGS} lpd.o lpdchar.o printcap.o
E 4
I 4
D 10
lpd:	lpd.o lpdchar.o printcap.o getqueue.o
	${CC} -o lpd ${LDFLAGS} lpd.o lpdchar.o printcap.o getqueue.o
E 10
I 10
D 15
lpd:	lpd.o lpdchar.o printcap.o getq.o
D 11
	${CC} -o lpd ${LDFLAGS} lpd.o lpdchar.o printcap.o getq.o
E 11
I 11
	${CC} -o lpd ${LDFLAGS} lpd.o lpdchar.o printcap.o getq.o -ljobs
E 15
I 15
varian:	${VARIAN}
E 15
E 11
E 10
E 4
E 3

I 10
D 15
rlpr:	rlpr.o printcap.o
	${CC} -o rlpr ${LDFLAGS} rlpr.o printcap.o
E 15
I 15
lpd:	lpd.o startup.o printjob.o recvjob.o displayq.o rmjob.o \
E 16
I 16
D 18
lpd:	lpd.o printjob.o recvjob.o displayq.o rmjob.o \
E 16
	startdaemon.o lpdchar.o common.o printcap.o
E 18
I 18
D 28
lpd:	lpd.o printjob.o recvjob.o displayq.o rmjob.o
lpd:	startdaemon.o lpdchar.o common.o printcap.o
E 18
D 16
	${CC} -o lpd lpd.o startup.o printjob.o recvjob.o \
		displayq.o rmjob.o startdaemon.o lpdchar.o common.o printcap.o \
		-ljobs
E 16
I 16
	${CC} -o lpd lpd.o printjob.o recvjob.o displayq.o rmjob.o \
D 17
		startdaemon.o lpdchar.o common.o printcap.o -ljobs
E 17
I 17
		startdaemon.o lpdchar.o common.o printcap.o
E 28
I 28
lpd:	${L1OBJS} ${LIBC}
	${CC} -o $@ ${L1OBJS}
E 28
E 17
E 16
E 15

E 10
D 15
lpr:	lpr.o printcap.o
D 3
	$(CC) -o lpr $(LDFLAGS) lpr.o printcap.o
E 3
I 3
D 10
	${CC} -o lpr ${LDFLAGS} lpr.o printcap.o
E 10
I 10
D 14
	${CC} -o lpr ${LDFLAGS} lpr.o -ljobs printcap.o
E 14
I 14
	${CC} -o lpr ${LDFLAGS} lpr.o printcap.o -ljobs
E 15
I 15
D 18
lpr:	lpr.o startdaemon.o common.o printcap.o
D 17
	${CC} -o lpr lpr.o startdaemon.o common.o printcap.o -ljobs
E 17
I 17
	${CC} -o lpr lpr.o startdaemon.o common.o printcap.o
E 18
I 18
D 28
lpr:	lpr.o startdaemon.o printcap.o
	${CC} -o lpr lpr.o startdaemon.o printcap.o
E 28
I 28
lpr:	${L2OBJS} ${LIBC}
	${CC} -o $@ ${L2OBJS}
E 28
E 18
E 17
E 15
E 14
E 10
E 3

D 4
sq:	sq.o printcap.o
D 3
	$(CC) -o sq $(LDFLAGS) sq.o -ltermcap printcap.o
E 3
I 3
	${CC} -o sq ${LDFLAGS} sq.o -ltermcap printcap.o
E 4
I 4
D 6
sq:	sq.o printcap.o getqueue.o
	${CC} -o sq ${LDFLAGS} sq.o -ltermcap printcap.o getqueue.o
E 6
I 6
D 10
lpq:	lpq.o printcap.o getqueue.o
	${CC} -o lpq ${LDFLAGS} lpq.o -ltermcap printcap.o getqueue.o
E 10
I 10
D 15
lpq:	lpq.o printcap.o getq.o
D 14
	${CC} -o lpq ${LDFLAGS} lpq.o -ltermcap printcap.o getq.o
E 14
I 14
	${CC} -o lpq ${LDFLAGS} lpq.o printcap.o getq.o -ltermcap
E 15
I 15
D 28
lpq:	lpq.o displayq.o common.o printcap.o
D 26
	${CC} -o lpq lpq.o displayq.o common.o printcap.o -ltermcap
E 26
I 26
	${CC} -o lpq lpq.o displayq.o common.o printcap.o
E 28
I 28
lpq:	${L3OBJS} ${LIBC}
	${CC} -o $@ ${L3OBJS}
E 28
E 26
E 15
E 14
E 10
E 6
E 4
E 3

D 4
dq:	dq.o printcap.o
D 3
	$(CC) -o dq $(LDFLAGS) dq.o printcap.o
E 3
I 3
	${CC} -o dq ${LDFLAGS} dq.o printcap.o
E 4
I 4
D 5
dq:	dq.o printcap.o scandir.o
	${CC} -o dq ${LDFLAGS} dq.o printcap.o scandir.o
E 5
I 5
D 6
dq:	dq.o printcap.o
	${CC} -o dq ${LDFLAGS} dq.o printcap.o
E 6
I 6
D 15
lprm:	lprm.o printcap.o
	${CC} -o lprm ${LDFLAGS} lprm.o printcap.o
E 15
I 15
D 28
lprm:	lprm.o rmjob.o startdaemon.o common.o printcap.o
	${CC} -o lprm lprm.o rmjob.o startdaemon.o common.o printcap.o
E 28
I 28
lprm:	${L4OBJS} ${LIBC}
	${CC} -o $@ ${L4OBJS}
E 28
E 15
E 6
E 5
E 4
E 3

I 3
D 15
lpdrestart: lpdrestart.o
	${CC} -o lpdrestart ${LDFLAGS} lpdrestart.o
E 15
I 15
D 16
restart: restart.o startdaemon.o common.o printcap.o
	${CC} -o restart restart.o startdaemon.o common.o printcap.o
E 16
I 16
D 28
lpc:	lpc.o cmds.o cmdtab.o startdaemon.o common.o printcap.o
D 17
	${CC} -o lpc lpc.o cmds.o cmdtab.o startdaemon.o common.o printcap.o -ljobs
E 17
I 17
	${CC} -o lpc lpc.o cmds.o cmdtab.o startdaemon.o common.o printcap.o
E 28
I 28
lpc:	${L5OBJS} ${LIBC}
	${CC} -o $@ ${L5OBJS}
E 28
E 17
E 16
E 15

I 21
D 28
lptest:	lptest.c
	${CC} ${CFLAGS} -o lptest lptest.c
E 28
I 28
lptest: ${L6OBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${L6OBJS}
E 28

E 21
D 11
laf:	laf.c
	${CC} -o laf ${CFLAGS} ${LDFLAGS} laf.c

E 11
E 3
D 16
lpf:	lpf.c
D 3
	$(CC) -o lpf $(CFLAGS) $(LDFLAGS) lpf.c
E 3
I 3
D 15
	${CC} -o lpf ${CFLAGS} ${LDFLAGS} lpf.c
E 15
I 15
	${CC} -o lpf ${CFLAGS} lpf.c
E 15
E 3

necf:	necf.c
D 3
	$(CC) -o necf $(CFLAGS) $(LDFLAGS) necf.c
E 3
I 3
D 15
	${CC} -o necf ${CFLAGS} ${LDFLAGS} necf.c
E 15
I 15
	${CC} -o necf ${CFLAGS} necf.c
E 15
E 3

D 3
lpr.o lpd.o sq.o dq.o: lp.local.h
E 3
I 3
D 6
lpr.o lpd.o sq.o dq.o lpdrestart.o: lp.local.h
I 4
lpd.o sq.o getqueue.o: getqueue.h
E 6
I 6
D 10
lpr.o lpd.o lpq.o lprm.o lpdrestart.o: lp.local.h
lpd.o lpq.o getqueue.o: getqueue.h
E 10
I 10
D 14
lpd.o rlpr.o lpr.o lpq.o lprm.o lpdrestart.o: lp.local.h
E 14
I 14
rvsort:	rvsort.c
	${CC} -o rvsort ${CFLAGS} rvsort.c

rvcat:	rvcat.c
	${CC} -o rvcat ${CFLAGS} rvcat.c

vsort:	vsort.c
	${CC} -o vsort ${CFLAGS} vsort.c

vcat:	vcat.c
	${CC} -o vcat ${CFLAGS} vcat.c

vpf:	vpf.c
	${CC} -o vpf ${CFLAGS} vpf.c

vpsf:	vpsf.c
	${CC} -o vpsf ${CFLAGS} vpsf.c

I 15
vdmp: vdmp.c
	${CC} -o vdmp ${CFLAGS} vdmp.c

E 15
vpltdmp: vpltdmp.c
	${CC} -o vpltdmp ${CFLAGS} vpltdmp.c

vfontinfo: vfontinfo.c
	${CC} -o vfontinfo ${CFLAGS} vfontinfo.c

vwidth: vwidth.c
	${CC} -o vwidth ${CFLAGS} vwidth.c

I 15
vfw: vfw.c
	${CC} -o vfw ${CFLAGS} vfw.c

fcvt: fcvt.c
	${CC} -o fcvt ${CFLAGS} fcvt.c

rotate: rotate.c
	${CC} -o rotate ${CFLAGS} rotate.c

rotprt: rotprt.c
	${CC} -o rotprt ${CFLAGS} rotprt.c

E 16
E 15
D 28
pac:	pac.o printcap.o
D 15
	${CC} -o pac ${CFLAGS} pac.o printcap.o
E 15
I 15
	${CC} -o pac pac.o printcap.o
E 28
I 28
pac: ${L7OBJS} ${LIBC}
	${CC} -o $@ ${L7OBJS}
E 28
E 15

D 15
lpd.o rlpr.o lpr.o lpq.o lprm.o lpdrestart.o pac.o: lp.local.h
E 14
lpd.o lpq.o getq.o: getq.h
E 15
I 15
D 16
lpd.o lpr.o lpq.o lprm.o restart.o pac.o: lp.h lp.local.h
E 16
I 16
D 28
lpd.o lpr.o lpq.o lprm.o pac.o: lp.h lp.local.h
E 16
recvjob.o printjob.o displayq.o rmjob.o common.o: lp.h lp.local.h
I 18
startdaemon.o: lp.local.h
E 18
I 16
lpc.o cmdtab.o: lpc.h
cmds.o: lp.h lp.local.h
E 16
E 15
E 10
E 6
E 4
E 3

E 28
I 18
D 32
FILTERS:
	cd filters; make ${MFLAGS}
E 32
I 32
${SUBDIR}: FRC
	cd $@; make ${MFLAGS}
E 32

I 29
D 32
VFILTERS:
	cd vfilters; make ${MFLAGS}

E 32
E 29
E 18
D 10
install: all
D 3
	cp lpd $(LIBDIR)/lpd
	cp sq $(BINDIR)/sq
	cp dq $(BINDIR)/dq
	cp lpr $(BINDIR)/lpr
	rm -f $(BINDIR)/opr $(BINDIR)/print
	ln $(BINDIR)/lpr $(BINDIR)/print
	ln $(BINDIR)/lpr $(BINDIR)/opr
	chown $(ROOT) $(BINDIR)/lpr $(BINDIR)/sq
	chown $(DAEMON) $(BINDIR)/dq $(LIBDIR)/lpd
	chgrp $(SPGRP) $(LIBDIR)/lpd $(BINDIR)/lpr $(BINDIR)/dq $(BINDIR)/sq
	chmod 6711 $(LIBDIR)/lpd $(BINDIR)/lpr $(BINDIR)/dq
	chmod 2711 $(BINDIR)/sq
	chmod 775 $(SPOOLDIR)
	chgrp $(SPGRP) $(SPOOLDIR)
	chown $(DAEMON) $(SPOOLDIR)
E 3
I 3
D 9
	cp lpd ${LIBDIR}/lpd
D 4
	cp sq ${BINDIR}/sq
	cp dq ${BINDIR}/dq
E 4
I 4
D 6
	cp sq ${BINDIR}/lpq
	cp dq ${BINDIR}/lprm
E 6
I 6
	cp lpq ${BINDIR}/lpq
	cp lprm ${BINDIR}/lprm
E 6
E 4
	cp lpr ${BINDIR}/lpr
E 9
I 9
	install lpd ${LIBDIR}/lpd
	install lpq ${BINDIR}/lpq
	install lprm ${BINDIR}/lprm
	install lpr ${BINDIR}/lpr
E 9
#	rm -f ${BINDIR}/opr ${BINDIR}/print
#	ln ${BINDIR}/lpr ${BINDIR}/print
#	ln ${BINDIR}/lpr ${BINDIR}/opr
D 4
	chown ${ROOT} ${BINDIR}/lpr ${BINDIR}/sq
	chown ${DAEMON} ${BINDIR}/dq ${LIBDIR}/lpd
	chgrp ${SPGRP} ${LIBDIR}/lpd ${BINDIR}/lpr ${BINDIR}/dq ${BINDIR}/sq
	chmod 6711 ${LIBDIR}/lpd ${BINDIR}/lpr ${BINDIR}/dq
	chmod 2711 ${BINDIR}/sq
	chmod 775 ${SPOOLDIR}
	chgrp ${SPGRP} ${SPOOLDIR}
E 4
I 4
	chown ${ROOT} ${BINDIR}/lpr
	chown ${DAEMON} $(BINDIR)/lpq ${BINDIR}/lprm ${LIBDIR}/lpd
	chgrp ${SPGRP} ${LIBDIR}/lpd ${BINDIR}/lpr ${BINDIR}/lpq ${BINDIR}/lprm
	chmod 6711 ${LIBDIR}/lpd ${BINDIR}/lpr ${BINDIR}/lprm
	chmod 2711 ${BINDIR}/lpq
E 10
I 10
D 11
install: lpd rlpr lpr lpq lprm
E 11
I 11
D 28
install: all
E 28
I 28
clean: FRC
	rm -f ${OBJS} core ${ALL}
D 32
	cd filters; make ${MFLAGS} clean
I 29
	cd vfilters; make ${MFLAGS} clean
E 32
I 32
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 32
E 29

depend: FRC
	mkdep ${CFLAGS} ${SRCS}
I 29
D 32
	cd filters; make ${MFLAGS} depend
	cd vfilters; make ${MFLAGS} depend
E 32
I 32
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
E 32
E 29

install: FRC
E 28
E 11
D 12
	install -o ${ROOT} -m 6711 lpd ${LIBDIR}/lpd
	install -o ${DAEMON} -m 6711 rlpr ${LIBDIR}/rlpr
	install -o ${ROOT} -m 6711 lpr ${BINDIR}/lpr
	install -o ${ROOT} -m 6711 lpq ${BINDIR}/lpq
	install -o ${ROOT} -m 6711 lprm ${BINDIR}/lprm
	chgrp ${SPGRP} ${LIBDIR}/lpd ${LIBDIR}/rlpr ${BINDIR}/lpr \
		${BINDIR}/lpq ${BINDIR}/lprm
E 10
E 4
	chown ${DAEMON} ${SPOOLDIR}
I 4
	chgrp ${SPGRP} ${SPOOLDIR}
	chmod 775 ${SPOOLDIR}
E 12
I 12
D 14
	install -o ${ROOT} -m 6711 lpd ${DESTDIR}/${LIBDIR}/lpd
	install -o ${DAEMON} -m 6711 rlpr ${DESTDIR}/${LIBDIR}/rlpr
	install -o ${ROOT} -m 6711 lpr ${DESTDIR}/${BINDIR}/lpr
	install -o ${ROOT} -m 6711 lpq ${DESTDIR}/${BINDIR}/lpq
	install -o ${ROOT} -m 6711 lprm ${DESTDIR}/${BINDIR}/lprm
E 14
I 14
D 15
	install -o ${ROOT} -m 6711 lpd ${DESTDIR}${LIBDIR}/lpd
	install -o ${DAEMON} -m 6711 rlpr ${DESTDIR}${LIBDIR}/rlpr
	install -o ${ROOT} -m 6711 lpr ${DESTDIR}${BINDIR}/lpr
	install -o ${ROOT} -m 6711 lpq ${DESTDIR}${BINDIR}/lpq
	install -o ${ROOT} -m 6711 lprm ${DESTDIR}${BINDIR}/lprm
E 14
	install -s lpdrestart ${DESTDIR}/etc/lpdrestart
D 14
	chgrp ${SPGRP} ${DESTDIR}/${LIBDIR}/lpd ${DESTDIR}/${LIBDIR}/rlpr \
		${DESTDIR}/${BINDIR}/lpr ${DESTDIR}/${BINDIR}/lpq \
		${DESTDIR}/${BINDIR}/lprm
	chown ${DAEMON} ${DESTDIR}/${SPOOLDIR}
	chgrp ${SPGRP} ${DESTDIR}/${SPOOLDIR}
	chmod 775 ${DESTDIR}/${SPOOLDIR}
E 14
I 14
	chgrp ${SPGRP} ${DESTDIR}${LIBDIR}/lpd ${DESTDIR}${LIBDIR}/rlpr \
		${DESTDIR}${BINDIR}/lpr ${DESTDIR}${BINDIR}/lpq \
		${DESTDIR}${BINDIR}/lprm
E 15
I 15
D 18
	install -s -g ${SPGRP} -m 6711 lpd ${DESTDIR}${LIBDIR}/lpd
	install -s -g ${SPGRP} -m 6711 lpr ${DESTDIR}${BINDIR}/lpr
	install -s -g ${SPGRP} -m 6711 lpq ${DESTDIR}${BINDIR}/lpq
	install -s -g ${SPGRP} -m 6711 lprm ${DESTDIR}${BINDIR}/lprm
E 18
I 18
D 24
	install -s -g ${SPGRP} -m 6711 lpd ${DESTDIR}/${LIBDIR}/lpd
	install -s -g ${SPGRP} -m 6711 lpr ${DESTDIR}/${BINDIR}/lpr
	install -s -g ${SPGRP} -m 6711 lpq ${DESTDIR}/${BINDIR}/lpq
	install -s -g ${SPGRP} -m 6711 lprm ${DESTDIR}/${BINDIR}/lprm
E 24
I 24
	install -s -o ${ROOT} -g ${SPGRP} -m 6711 lpd ${DESTDIR}/${LIBDIR}/lpd
	install -s -o ${ROOT} -g ${SPGRP} -m 6711 lpr ${DESTDIR}/${BINDIR}/lpr
	install -s -o ${ROOT} -g ${SPGRP} -m 6711 lpq ${DESTDIR}/${BINDIR}/lpq
	install -s -o ${ROOT} -g ${SPGRP} -m 6711 lprm ${DESTDIR}/${BINDIR}/lprm
E 24
E 18
D 16
	install -s -g ${SPGRP} -m 6711 restart ${DESTDIR}${BINDIR}/restart
E 16
I 16
D 19
	install -s -g ${SPGRP} -m 6711 lpc ${DESTDIR}/etc/lpc
E 19
I 19
D 28
	install -s -g ${SPGRP} -m 2711 lpc ${DESTDIR}/etc/lpc
I 21
	install -s lptest ${DESTDIR}/${BINDIR}/lptest
E 21
E 19
	install -s pac ${DESTDIR}/etc/pac
E 16
E 15
D 18
	chown ${DAEMON} ${DESTDIR}${SPOOLDIR}
	chgrp ${SPGRP} ${DESTDIR}${SPOOLDIR}
	chmod 775 ${DESTDIR}${SPOOLDIR}
E 18
I 18
D 23
	chown ${DAEMON} ${DESTDIR}/${SPOOLDIR}
E 23
I 23
	/etc/chown ${DAEMON} ${DESTDIR}/${SPOOLDIR}
E 23
	chgrp ${SPGRP} ${DESTDIR}/${SPOOLDIR}
	chmod 775 ${DESTDIR}/${SPOOLDIR}
E 28
I 28
	install -s -o bin -g ${SPGRP} -m 2711 lpc ${DESTDIR}/etc/lpc
	install -s -o bin -g bin -m 755 lptest ${DESTDIR}/${BINDIR}/lptest
	install -s -o bin -g bin -m 755 pac ${DESTDIR}/etc/pac
	/etc/chown ${DAEMON} ${DESTDIR}/${SPLDIR}
	chgrp ${SPGRP} ${DESTDIR}/${SPLDIR}
	chmod 775 ${DESTDIR}/${SPLDIR}
E 28
D 20
	cd filters; make ${MFLAGS} install
E 20
I 20
D 32
	cd filters; make ${MFLAGS} DESTDIR=${DESTDIR} install
I 29
	cd vfilters; make ${MFLAGS} DESTDIR=${DESTDIR} install
E 32
I 32
	-for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done
E 32
E 29
E 20
E 18
D 15
	install -s vfontinfo ${DESTDIR}${LIBDIR}/vfontinfo
	install -s vwidth ${DESTDIR}${LIBDIR}/vwidth
E 15
D 16
	install -s pac ${DESTDIR}/etc/pac
E 16
E 14
E 12
E 4
E 3

I 14
D 15
finstall: filters
E 15
I 15
D 16
installp: filters
E 15
	install -s lpf ${DESTDIR}${LIBDIR}/lpf
	install -s necf ${DESTDIR}${LIBDIR}/necf
I 15

installv: varian
	install -s vfontinfo ${DESTDIR}${LIBDIR}/vfontinfo
	install -s vwidth ${DESTDIR}${LIBDIR}/vwidth
	install -s vfw ${DESTDIR}${LIBDIR}/vfw
	install -s fcvt ${DESTDIR}${LIBDIR}/fcvt
	install -s rotate ${DESTDIR}${LIBDIR}/rotate
	install -s rotprt ${DESTDIR}${LIBDIR}/rotprt
E 15
	install -s rvsort ${DESTDIR}${LIBDIR}/rvsort
	install -s rvcat ${DESTDIR}${LIBDIR}/rvcat
	install -s vsort ${DESTDIR}${LIBDIR}/vsort
	install -s vcat ${DESTDIR}${LIBDIR}/vcat
	install -s vpf ${DESTDIR}${LIBDIR}/vpf
	install -s vpsf ${DESTDIR}${LIBDIR}/vpsf
I 15
	install -s vdmp ${DESTDIR}${LIBDIR}/vdmp
E 15
	install -s vpltdmp ${DESTDIR}${LIBDIR}/vpltdmp

E 16
E 14
D 28
clean:
D 3
	rm -f dq sq lpd lpr necf lpf *.o
E 3
I 3
D 6
	rm -f laf dq sq lpd lpr necf lpf *.o
E 6
I 6
D 10
	rm -f laf lprm lpq lpd lpr necf lpf *.o
E 10
I 10
D 11
	rm -f lpd rlpr lpr lpq lprm lpdrestart laf lpf necf *.o
E 11
I 11
D 14
	rm -f ${OBJS} *.o
E 14
I 14
D 15
	rm -f ${OBJS} ${FLTRS} *.o
E 15
I 15
D 16
	rm -f ${OBJS} ${PRINTER} ${VARIAN} *.o
E 16
I 16
D 18
	rm -f ${OBJS} *.o
E 18
I 18
	rm -f ${ALL} *.o
	cd filters; make ${MFLAGS} clean
E 28
I 28
lint: FRC
	lint ${CFLAGS} ${L1SRCS}
	lint ${CFLAGS} ${L2SRCS}
	lint ${CFLAGS} ${L3SRCS}
	lint ${CFLAGS} ${L4SRCS}
	lint ${CFLAGS} ${L5SRCS}
	lint ${CFLAGS} ${L6SRCS}
	lint ${CFLAGS} ${L7SRCS}
E 28
E 18
E 16
E 15
E 14
E 11
E 10
E 6
E 3

I 25
D 28
tags:
	ctags ${SRCS}
E 28
I 28
tags: FRC
	ctags ${L1SRCS}
	ctags -a ${L2SRCS}
	ctags -a ${L3SRCS}
	ctags -a ${L4SRCS}
	ctags -a ${L5SRCS}
	ctags -a ${L6SRCS}
	ctags -a ${L7SRCS}
	sort -o tags tags
E 28

E 25
D 28
print:
	@pr makefile
D 2
	@size *.o | pr -h SIZES
E 2
	@${CXREF} *.c | pr -h XREF
D 2
	@ls -l | pr 
E 2
	@pr *.h *.c
E 28
I 28
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

lpd.o: lpd.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
lpd.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
lpd.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
lpd.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/sys/socket.h
lpd.o: /usr/include/sys/un.h /usr/include/netinet/in.h /usr/include/netdb.h
lpd.o: /usr/include/pwd.h /usr/include/syslog.h /usr/include/signal.h
lpd.o: /usr/include/sys/wait.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 29
I 29
lpd.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
lpd.o: /usr/include/sys/file.h /usr/include/sys/dir.h /usr/include/sys/stat.h
lpd.o: /usr/include/sys/socket.h /usr/include/sys/un.h
lpd.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
lpd.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
lpd.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 29
lpd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lpd.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
lpd.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 30
I 30
lpd.o: /usr/include/machine/endian.h /usr/include/sys/file.h
lpd.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/sys/socket.h
lpd.o: /usr/include/sys/un.h /usr/include/netinet/in.h /usr/include/netdb.h
lpd.o: /usr/include/pwd.h /usr/include/syslog.h /usr/include/signal.h
lpd.o: /usr/include/sys/wait.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 32
lpd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
lpd.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
lpd.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
lpd.o: /usr/include/ar.h
E 32
I 32
lpd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lpd.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
lpd.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 32
E 30
lpr.o: lpr.c /usr/include/stdio.h /usr/include/sys/types.h
lpr.o: /usr/include/sys/file.h /usr/include/sys/stat.h /usr/include/pwd.h
D 29
lpr.o: /usr/include/grp.h /usr/include/signal.h /usr/include/ctype.h
lpr.o: /usr/include/syslog.h lp.local.h /usr/include/a.out.h
lpr.o: /usr/include/sys/exec.h /usr/include/ar.h
E 29
I 29
lpr.o: /usr/include/grp.h /usr/include/signal.h /usr/include/machine/trap.h
lpr.o: /usr/include/ctype.h /usr/include/syslog.h lp.local.h
lpr.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 29
lpq.o: lpq.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
lpq.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
lpq.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
lpq.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/sys/socket.h
lpq.o: /usr/include/sys/un.h /usr/include/netinet/in.h /usr/include/netdb.h
lpq.o: /usr/include/pwd.h /usr/include/syslog.h /usr/include/signal.h
lpq.o: /usr/include/sys/wait.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 29
I 29
lpq.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
lpq.o: /usr/include/sys/file.h /usr/include/sys/dir.h /usr/include/sys/stat.h
lpq.o: /usr/include/sys/socket.h /usr/include/sys/un.h
lpq.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
lpq.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
lpq.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 29
lpq.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lpq.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
lpq.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 30
I 30
lpq.o: /usr/include/machine/endian.h /usr/include/sys/file.h
lpq.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/sys/socket.h
lpq.o: /usr/include/sys/un.h /usr/include/netinet/in.h /usr/include/netdb.h
lpq.o: /usr/include/pwd.h /usr/include/syslog.h /usr/include/signal.h
lpq.o: /usr/include/sys/wait.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 32
lpq.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
lpq.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
lpq.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
lpq.o: /usr/include/ar.h
E 32
I 32
lpq.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lpq.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
lpq.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 32
E 30
lprm.o: lprm.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
lprm.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
lprm.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
lprm.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
E 29
I 29
lprm.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
lprm.o: /usr/include/sys/file.h /usr/include/sys/dir.h /usr/include/sys/stat.h
E 30
I 30
lprm.o: /usr/include/machine/endian.h /usr/include/sys/file.h
lprm.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
E 30
E 29
lprm.o: /usr/include/sys/socket.h /usr/include/sys/un.h
lprm.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
lprm.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
lprm.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 30
lprm.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lprm.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
lprm.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 30
I 30
D 32
lprm.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
lprm.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
lprm.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
lprm.o: /usr/include/ar.h
E 32
I 32
lprm.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lprm.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
lprm.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 32
E 30
pac.o: pac.c /usr/include/stdio.h lp.local.h /usr/include/a.out.h
pac.o: /usr/include/sys/exec.h /usr/include/ar.h
lpd.o: lpd.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
lpd.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
lpd.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
lpd.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/sys/socket.h
lpd.o: /usr/include/sys/un.h /usr/include/netinet/in.h /usr/include/netdb.h
lpd.o: /usr/include/pwd.h /usr/include/syslog.h /usr/include/signal.h
lpd.o: /usr/include/sys/wait.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 29
I 29
lpd.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
lpd.o: /usr/include/sys/file.h /usr/include/sys/dir.h /usr/include/sys/stat.h
lpd.o: /usr/include/sys/socket.h /usr/include/sys/un.h
lpd.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
lpd.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
lpd.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 29
lpd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lpd.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
lpd.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 30
I 30
lpd.o: /usr/include/machine/endian.h /usr/include/sys/file.h
lpd.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/sys/socket.h
lpd.o: /usr/include/sys/un.h /usr/include/netinet/in.h /usr/include/netdb.h
lpd.o: /usr/include/pwd.h /usr/include/syslog.h /usr/include/signal.h
lpd.o: /usr/include/sys/wait.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 32
lpd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
lpd.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
lpd.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
lpd.o: /usr/include/ar.h
E 32
I 32
lpd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lpd.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
lpd.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 32
E 30
cmds.o: cmds.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
cmds.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
cmds.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
cmds.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
E 29
I 29
cmds.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
cmds.o: /usr/include/sys/file.h /usr/include/sys/dir.h /usr/include/sys/stat.h
E 30
I 30
cmds.o: /usr/include/machine/endian.h /usr/include/sys/file.h
cmds.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
E 30
E 29
cmds.o: /usr/include/sys/socket.h /usr/include/sys/un.h
cmds.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
cmds.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
cmds.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 30
cmds.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmds.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
cmds.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
cmds.o: /usr/include/sys/time.h /usr/include/time.h
E 30
I 30
D 32
cmds.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
cmds.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
cmds.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
cmds.o: /usr/include/ar.h /usr/include/sys/time.h /usr/include/time.h
E 32
I 32
cmds.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmds.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
cmds.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
cmds.o: /usr/include/sys/time.h /usr/include/time.h
E 32
E 30
cmdtab.o: cmdtab.c lpc.h
printjob.o: printjob.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
printjob.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
printjob.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
printjob.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
printjob.o: /usr/include/sys/socket.h /usr/include/sys/un.h
printjob.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
printjob.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
printjob.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
printjob.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
printjob.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
printjob.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 29
I 29
printjob.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
printjob.o: /usr/include/sys/file.h /usr/include/sys/dir.h
printjob.o: /usr/include/sys/stat.h /usr/include/sys/socket.h
printjob.o: /usr/include/sys/un.h /usr/include/netinet/in.h
printjob.o: /usr/include/netdb.h /usr/include/pwd.h /usr/include/syslog.h
printjob.o: /usr/include/signal.h /usr/include/sys/wait.h /usr/include/sgtty.h
printjob.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 30
I 30
printjob.o: /usr/include/machine/endian.h /usr/include/sys/file.h
printjob.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
printjob.o: /usr/include/sys/socket.h /usr/include/sys/un.h
printjob.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
printjob.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
printjob.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 32
printjob.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
E 30
printjob.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
printjob.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
printjob.o: /usr/include/ar.h
E 32
I 32
printjob.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
printjob.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
printjob.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 32
E 29
recvjob.o: recvjob.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
recvjob.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
recvjob.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
recvjob.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
recvjob.o: /usr/include/sys/socket.h /usr/include/sys/un.h
recvjob.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
recvjob.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
recvjob.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
recvjob.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
recvjob.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
recvjob.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
recvjob.o: /usr/include/sys/fs.h
E 29
I 29
recvjob.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
recvjob.o: /usr/include/sys/file.h /usr/include/sys/dir.h
recvjob.o: /usr/include/sys/stat.h /usr/include/sys/socket.h
recvjob.o: /usr/include/sys/un.h /usr/include/netinet/in.h /usr/include/netdb.h
recvjob.o: /usr/include/pwd.h /usr/include/syslog.h /usr/include/signal.h
recvjob.o: /usr/include/sys/wait.h /usr/include/sgtty.h
recvjob.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 30
I 30
recvjob.o: /usr/include/machine/endian.h /usr/include/sys/file.h
recvjob.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
recvjob.o: /usr/include/sys/socket.h /usr/include/sys/un.h
recvjob.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
recvjob.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
recvjob.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 32
recvjob.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
E 30
recvjob.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
recvjob.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
recvjob.o: /usr/include/ar.h /usr/include/sys/fs.h
E 32
I 32
recvjob.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
recvjob.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
recvjob.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
recvjob.o: /usr/include/sys/fs.h
E 32
E 29
displayq.o: displayq.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
displayq.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
displayq.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
displayq.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
displayq.o: /usr/include/sys/socket.h /usr/include/sys/un.h
displayq.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
displayq.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
displayq.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
displayq.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
displayq.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
displayq.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 29
I 29
displayq.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
displayq.o: /usr/include/sys/file.h /usr/include/sys/dir.h
displayq.o: /usr/include/sys/stat.h /usr/include/sys/socket.h
displayq.o: /usr/include/sys/un.h /usr/include/netinet/in.h
displayq.o: /usr/include/netdb.h /usr/include/pwd.h /usr/include/syslog.h
displayq.o: /usr/include/signal.h /usr/include/sys/wait.h /usr/include/sgtty.h
displayq.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 30
I 30
displayq.o: /usr/include/machine/endian.h /usr/include/sys/file.h
displayq.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
displayq.o: /usr/include/sys/socket.h /usr/include/sys/un.h
displayq.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
displayq.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
displayq.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 32
displayq.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
E 30
displayq.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
displayq.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
displayq.o: /usr/include/ar.h
E 32
I 32
displayq.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
displayq.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
displayq.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 32
E 29
rmjob.o: rmjob.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
rmjob.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
rmjob.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
rmjob.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
E 29
I 29
rmjob.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
rmjob.o: /usr/include/sys/file.h /usr/include/sys/dir.h /usr/include/sys/stat.h
E 30
I 30
rmjob.o: /usr/include/machine/endian.h /usr/include/sys/file.h
rmjob.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
E 30
E 29
rmjob.o: /usr/include/sys/socket.h /usr/include/sys/un.h
rmjob.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
rmjob.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
rmjob.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 30
rmjob.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
rmjob.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
rmjob.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 30
I 30
D 32
rmjob.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
rmjob.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
rmjob.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
rmjob.o: /usr/include/ar.h
E 32
I 32
rmjob.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
rmjob.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
rmjob.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 32
E 30
startdaemon.o: startdaemon.c /usr/include/stdio.h /usr/include/sys/types.h
startdaemon.o: /usr/include/sys/socket.h /usr/include/sys/un.h lp.local.h
startdaemon.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
common.o: common.c lp.h /usr/include/stdio.h /usr/include/sys/param.h
common.o: /usr/include/sys/types.h /usr/include/signal.h
D 29
common.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
common.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
common.o: /usr/include/sys/socket.h /usr/include/sys/un.h
common.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
common.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
common.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 29
I 29
common.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 30
common.o: /usr/include/sys/file.h /usr/include/sys/dir.h
common.o: /usr/include/sys/stat.h /usr/include/sys/socket.h
common.o: /usr/include/sys/un.h /usr/include/netinet/in.h /usr/include/netdb.h
common.o: /usr/include/pwd.h /usr/include/syslog.h /usr/include/signal.h
common.o: /usr/include/sys/wait.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 29
common.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
common.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
common.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 30
I 30
common.o: /usr/include/machine/endian.h /usr/include/sys/file.h
common.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
common.o: /usr/include/sys/socket.h /usr/include/sys/un.h
common.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/pwd.h
common.o: /usr/include/syslog.h /usr/include/signal.h /usr/include/sys/wait.h
common.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 32
common.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
common.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/errno.h
common.o: lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
common.o: /usr/include/ar.h
E 32
I 32
common.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
common.o: /usr/include/ctype.h /usr/include/errno.h lp.local.h
common.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/ar.h
E 32
E 30
printcap.o: printcap.c /usr/include/ctype.h /usr/include/stdio.h
lpdchar.o: lpdchar.c lp.local.h /usr/include/a.out.h /usr/include/sys/exec.h
lpdchar.o: /usr/include/ar.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 28
D 11

E 11
E 1
