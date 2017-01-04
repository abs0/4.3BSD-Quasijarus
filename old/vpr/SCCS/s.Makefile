h09867
s 00001/00001/00087
d D 5.9 87/12/31 17:56:37 bostic 10 9
c add man make, install
e
s 00081/00054/00007
d D 5.8 87/12/12 17:23:49 bostic 9 7
c new template
e
s 00081/00054/00007
d R 5.8 87/11/04 21:14:46 bostic 8 7
c new template
e
s 00011/00011/00050
d D 5.7 82/11/18 20:09:46 mckusick 7 6
c clean-ups
e
s 00003/00000/00058
d D 5.6 81/07/12 00:55:12 sklower 6 5
c put vdmp in makefile
e
s 00007/00002/00051
d D 5.5 81/07/12 00:47:38 sklower 5 4
c Include vfontinfo in Makefile
e
s 00002/00014/00051
d D 5.4 81/02/25 23:07:36 root 4 3
c I moved vgrind to another directory so I took out the
c vgrind stuff -- presotto
e
s 00008/00004/00057
d D 5.3 81/02/14 13:26:15 root 3 2
c just made it more convenient.  Simplified the vfontedpr entry.
c --- presotto
e
s 00006/00003/00055
d D 5.2 81/01/20 00:52:05 root 2 1
c includes new table driven vgrind rules -- presotto
e
s 00058/00000/00000
d D 5.1 80/11/30 15:56:42 root 1 0
c date and time created 80/11/30 15:56:42 by root
e
u
U
t
T
I 9
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
E 9
I 7
#	%W%	(Berkeley)	%G%
#
E 7
I 1
D 9
DESTDIR=
CFLAGS=-O 
D 2
SOURCES=sidebyside.c vcat.c vfontedpr.c vpac.c vpd.c vpf.c vpq.c vpr.c vprm.c vsort.c
E 2
I 2
D 4
SOURCES=sidebyside.c vcat.c vfontedpr.c vgrindefs.c regexp.c vpac.c vpd.c vpf.c vpq.c vpr.c vprm.c vsort.c
E 2
OBJS=sidebyside vcat vfontedpr vpac vad vpd vpf vpq vpr vprm vsort rvcat rvsort
E 4
I 4
D 5
SOURCES=sidebyside.c vcat.c vpac.c vpd.c vpf.c vpq.c vpr.c vprm.c vsort.c
OBJS=sidebyside vcat vpac vad vpd vpf vpq vpr vprm vsort rvcat rvsort
E 5
I 5
D 7
SOURCES=sidebyside.c vcat.c vpac.c vpd.c vpf.c \
	vfontinfo.c vpq.c vpr.c vprm.c vsort.c
OBJS=sidebyside vcat vpac vad vpd vpf \
	vfontinfo vpq vpr vprm vsort rvcat rvsort
E 7
I 7
SOURCES=sidebyside.c vcat.c vpac.c vpd.c vpf.c vfontinfo.c \
	vpq.c vpr.c vprm.c vsort.c rvcat.c rvsort.c vdmp.c
OBJS=sidebyside vcat vpac vad vpd vpf vfontinfo \
	vpq vpr vprm vsort rvcat rvsort vdmp
E 9
I 9
CFLAGS=	-O
LIBC=	/lib/libc.a
D 10
SUBDIR=	vtools vtools/fed
E 10
I 10
SUBDIR=	vtools vtools/fed man
E 10
SHELLS=	rvtroff.sh vprint.sh vtroff.sh vpq.sh vpr.sh vprm.sh
SRCS=	vpac.c vpd.c vpq.c vpr.c vprm.c
OBJS=	vpac.o vpd.o vpq.o vpr.o vprm.o
ALL=	vpac vpd vpq vpr vprm
E 9
E 7
E 5
E 4

D 9
all:	$(OBJS)
E 9
I 9
all: ${ALL} subdir
E 9

D 9
sidebyside: sidebyside.c
	cc -O -o sidebyside sidebyside.c
I 5
vfontinfo: vfontinfo.c
	cc -O -o vfontinfo vfontinfo.c
E 5
vcat: vcat.c
	cc -O -o vcat vcat.c
D 2
vfontedpr: vfontedpr.c
	cc -O -o vfontedpr vfontedpr.c
E 2
I 2
D 3
vfontedpr: vfontedpr.c vgrindefs.c regexp.c
	cc -O -o vfontedpr vfontedpr.c vgrindefs.c regexp.c
retest: retest.c regexp.c
	cc -g -o retest retest.c regexp.c
E 3
I 3
D 4
vfontedpr: vfontedpr.c vgrindefs.o regexp.o
	cc -O -o vfontedpr vfontedpr.c vgrindefs.o regexp.o
retest: retest.c regexp.o
	cc -g -o retest retest.c regexp.o
vgrindefs.o: vgrindefs.c
	cc -O -c vgrindefs.c
regexp.o: regexp.c
	cc -O -c regexp.c
E 4
E 3
E 2
vpac: vpac.c
	cc -O -o vpac vpac.c
vad: vpd.c
	cc -DVARIAN -O -o vad vpd.c
vpd: vpd.c
	cc -DVERSATEC -O -o vpd vpd.c
vpf: vpf.c
	cc -O -o vpf vpf.c
vpq: vpq.c
	cc -O -o vpq vpq.c
vpr: vpr.c
	cc -O -o vpr vpr.c
vprm: vprm.c
	cc -O -o vprm vprm.c
vsort: vsort.c
	cc -O -o vsort vsort.c
rvsort: rvsort.c
	cc -O -o rvsort rvsort.c
rvcat: rvcat.c
	cc -O -o rvcat rvcat.c
I 6
vdmp: vdmp.c
	cc -O -o vdmp vdmp.c
E 9
I 9
subdir:
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS}); done
E 9
E 6

D 9
install: all
	install -s sidebyside ${DESTDIR}/usr/lib/sidebyside
	install -s vcat ${DESTDIR}/usr/lib/vcat
D 4
	install -s vfontedpr ${DESTDIR}/usr/lib/vfontedpr
	install -c vgrind.sh ${DESTDIR}/usr/ucb/vgrind
I 2
	install -c vgrindefs.src ${DESTDIR}/usr/lib/vgrindefs
E 4
E 2
D 7
	install -s vpac ${DESTDIR}/etc
E 7
I 7
	install -s vpac ${DESTDIR}/etc/vpac
E 7
	install -s vad ${DESTDIR}/usr/lib/vad
	install -s vpd ${DESTDIR}/usr/lib/vpd
	install -s vpf ${DESTDIR}/usr/lib/vpf
D 7
	install -s vpq ${DESTDIR}/usr/ucb/vpq
	install -s vpr ${DESTDIR}/usr/ucb/vpr
	install -c vprint.sh ${DESTDIR}/usr/ucb/vprint
D 4
	install -c tmac.vgrind ${DESTDIR}/usr/lib/tmac/tmac.vgrind
E 4
	install -s vprm ${DESTDIR}/usr/ucb/vprm
E 7
I 7
	install -s vpq ${DESTDIR}/usr/lib/vpq
	install -s vpr ${DESTDIR}/usr/lib/vpr
	install -s vprm ${DESTDIR}/usr/lib/vprm
E 7
	install -s vsort ${DESTDIR}/usr/lib/vsort
D 7
	install -c vtroff.sh ${DESTDIR}/usr/ucb/vtroff
E 7
	install -s rvsort ${DESTDIR}/usr/lib/rvsort
	install -s rvcat ${DESTDIR}/usr/lib/rvcat
I 6
	install -s vdmp ${DESTDIR}/usr/lib/vdmp
E 6
I 5
	install -s vfontinfo ${DESTDIR}/usr/lib/vfontinfo
E 9
I 9
vpac: ${LIBC}
	${CC} -O -o $@ vpac.c
vpd: ${LIBC}
	${CC} -DVERSATEC -O -o $@ vpd.c
vpq: ${LIBC}
	${CC} -O -o $@ vpq.c
vpr: ${LIBC}
	${CC} -O -o $@ vpr.c
vprm: ${LIBC}
	${CC} -O -o $@ vprm.c
E 9
E 5

D 9
clean:
D 7
	rm -f ${OBJS}
E 7
I 7
	rm -f ${OBJS} *.o
E 9
I 9
clean: FRC
	rm -f ${OBJS} core ${ALL}
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 9
E 7

D 9
vprintall:
	csh /usr/ucb/vprint ${SOURCES}
E 9
I 9
depend: FRC ldepend
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done

ldepend:
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} install); done
	install -s -o bin -g bin -m 755 vpac ${DESTDIR}/usr/old/vpac
	install -s -o bin -g bin -m 755 vpd ${DESTDIR}/usr/lib/vpd
	install -s -o bin -g bin -m 755 vpq ${DESTDIR}/usr/lib/vpq
	install -s -o bin -g bin -m 755 vpr ${DESTDIR}/usr/lib/vpr
	install -s -o bin -g bin -m 755 vprm ${DESTDIR}/usr/lib/vprm
	install -c -o bin -g bin -m 755 vprint.sh ${DESTDIR}/usr/old/vprint
	install -c -o bin -g bin -m 755 vtroff.sh ${DESTDIR}/usr/old/vtroff
	install -c -o bin -g bin -m 755 vpq.sh ${DESTDIR}/usr/old/vpq
	install -c -o bin -g bin -m 755 vpr.sh ${DESTDIR}/usr/old/vpr
	install -c -o bin -g bin -m 755 vprm.sh ${DESTDIR}/usr/old/vprm

lint: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} lint); done
	lint ${CFLAGS} ${SRCS}

tags: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} tags); done
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

vpac: vpac.c /usr/include/stdio.h
vpd: vpd.c /usr/include/stdio.h /usr/include/sys/param.h
vpd: /usr/include/sys/types.h /usr/include/signal.h /usr/include/machine/trap.h
vpd: /usr/include/machine/machparam.h /usr/include/sys/dir.h
vpd: /usr/include/signal.h /usr/include/sys/stat.h /usr/include/sgtty.h
vpd: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vpd: /usr/include/sys/ttydev.h /usr/include/errno.h /usr/include/sys/vcmd.h
vpd: /usr/include/sys/wait.h
vpq: vpq.c /usr/include/sys/param.h /usr/include/sys/types.h
vpq: /usr/include/signal.h /usr/include/machine/trap.h
vpq: /usr/include/machine/machparam.h /usr/include/sys/dir.h
vpq: /usr/include/sys/stat.h /usr/include/stdio.h /usr/include/errno.h
vpr: vpr.c /usr/include/signal.h /usr/include/machine/trap.h
vpr: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
vpr: /usr/include/machine/machparam.h
vprm: vprm.c /usr/include/sys/param.h /usr/include/sys/types.h
vprm: /usr/include/signal.h /usr/include/machine/trap.h
vprm: /usr/include/machine/machparam.h /usr/include/sys/dir.h
vprm: /usr/include/sys/stat.h /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
E 1
