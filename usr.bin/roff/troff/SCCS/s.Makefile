h42128
s 00032/00026/00088
d D 5.2 2012/02/16 07:28:32 msokolov 2 1
c C/A/T troff becomes otroff
e
s 00114/00000/00000
d D 5.1 87/12/12 17:37:00 bostic 1 0
c date and time created 87/12/12 17:37:00 by bostic
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
D 2
#	%W%	(Berkeley)	%G%
E 2
I 2
#	%W%	(Berkeley)	%E%
E 2
#
COMMON=	../common_source
CFLAGS=	-O -DVMUNIX -I${COMMON}
VPATH=	${COMMON}
LIBC=	/lib/libc.a
SRCS=	ni.c nii.c n1.c n2.c n3.c n4.c n5.c t6.c n7.c n8.c n9.c t10.c \
	hytab.c suftab.c tab3.c
OBJS=	ni.o nii.o n1.o n2.o n3.o n4.o n5.o t6.o n7.o n8.o n9.o t10.o \
	hytab.o suftab.o tab3.o

all: troff

troff: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}

hytab.o: ${COMMON}/hytab.c
	${CC} -R -c ${COMMON}/hytab.c

suftab.o: ${COMMON}/suftab.c
	${CC} -R -c ${COMMON}/suftab.c

clean: FRC
	rm -f ${OBJS} core troff

depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 troff ${DESTDIR}/usr/bin/troff
I 2
	cd ${DESTDIR}/usr/bin; rm -f otroff; ln troff otroff
E 2

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

ni.o: ../common_source/ni.c ../common_source/tdef.h /usr/include/sys/param.h
ni.o: /usr/include/sys/types.h /usr/include/signal.h
ni.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
ni.o: /usr/include/signal.h
E 2
I 2
ni.o: /usr/include/machine/endian.h /usr/include/signal.h
E 2
nii.o: ../common_source/nii.c ../common_source/tdef.h /usr/include/sys/param.h
nii.o: /usr/include/sys/types.h /usr/include/signal.h
nii.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
nii.o: /usr/include/signal.h ../common_source/sdef.h ../common_source/d.h
nii.o: ../common_source/v.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 2
I 2
nii.o: /usr/include/machine/endian.h /usr/include/signal.h
nii.o: ../common_source/sdef.h ../common_source/d.h ../common_source/v.h
nii.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 2
nii.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
n1.o: ../common_source/n1.c ../common_source/tdef.h /usr/include/sys/param.h
n1.o: /usr/include/sys/types.h /usr/include/signal.h
n1.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
n1.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/stat.h
n1.o: /usr/include/time.h ../common_source/d.h ../common_source/v.h
n1.o: ../common_source/sdef.h /usr/include/setjmp.h /usr/include/sgtty.h
n1.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
n1.o: /usr/include/sys/ttydev.h
E 2
I 2
n1.o: /usr/include/machine/endian.h /usr/include/signal.h
n1.o: /usr/include/sys/types.h /usr/include/sys/stat.h /usr/include/time.h
n1.o: ../common_source/d.h ../common_source/v.h ../common_source/sdef.h
n1.o: /usr/include/setjmp.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
n1.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 2
n2.o: ../common_source/n2.c ../common_source/tdef.h /usr/include/sys/param.h
n2.o: /usr/include/sys/types.h /usr/include/signal.h
n2.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
n2.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
n2.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
n2.o: ../common_source/d.h ../common_source/v.h ../common_source/sdef.h
n2.o: /usr/include/setjmp.h
E 2
I 2
n2.o: /usr/include/machine/endian.h /usr/include/signal.h /usr/include/sgtty.h
n2.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
n2.o: /usr/include/sys/ttydev.h ../common_source/d.h ../common_source/v.h
n2.o: ../common_source/sdef.h /usr/include/setjmp.h
E 2
n3.o: ../common_source/n3.c ../common_source/tdef.h /usr/include/sys/param.h
n3.o: /usr/include/sys/types.h /usr/include/signal.h
n3.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
n3.o: /usr/include/signal.h ../common_source/d.h ../common_source/v.h
n3.o: ../common_source/sdef.h
E 2
I 2
n3.o: /usr/include/machine/endian.h /usr/include/signal.h ../common_source/d.h
n3.o: ../common_source/v.h ../common_source/sdef.h
E 2
n4.o: ../common_source/n4.c ../common_source/tdef.h /usr/include/sys/param.h
n4.o: /usr/include/sys/types.h /usr/include/signal.h
n4.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
n4.o: /usr/include/signal.h ../common_source/d.h ../common_source/v.h
n4.o: ../common_source/sdef.h
E 2
I 2
n4.o: /usr/include/machine/endian.h /usr/include/signal.h ../common_source/d.h
n4.o: ../common_source/v.h ../common_source/sdef.h
E 2
n5.o: ../common_source/n5.c ../common_source/tdef.h /usr/include/sys/param.h
n5.o: /usr/include/sys/types.h /usr/include/signal.h
n5.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
n5.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
n5.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
n5.o: ../common_source/d.h ../common_source/v.h ../common_source/sdef.h
E 2
I 2
n5.o: /usr/include/machine/endian.h /usr/include/signal.h /usr/include/sgtty.h
n5.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
n5.o: /usr/include/sys/ttydev.h ../common_source/d.h ../common_source/v.h
n5.o: ../common_source/sdef.h
E 2
t6.o: t6.c ../common_source/tdef.h /usr/include/sys/param.h
t6.o: /usr/include/sys/types.h /usr/include/signal.h
t6.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
t6.o: /usr/include/signal.h ../common_source/d.h ../common_source/v.h
E 2
I 2
t6.o: /usr/include/machine/endian.h /usr/include/signal.h ../common_source/d.h
t6.o: ../common_source/v.h
E 2
n7.o: ../common_source/n7.c ../common_source/tdef.h /usr/include/sys/param.h
n7.o: /usr/include/sys/types.h /usr/include/signal.h
n7.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
n7.o: /usr/include/signal.h ../common_source/d.h ../common_source/v.h
n7.o: ../common_source/sdef.h
E 2
I 2
n7.o: /usr/include/machine/endian.h /usr/include/signal.h ../common_source/d.h
n7.o: ../common_source/v.h ../common_source/sdef.h
E 2
n8.o: ../common_source/n8.c ../common_source/tdef.h /usr/include/sys/param.h
n8.o: /usr/include/sys/types.h /usr/include/signal.h
n8.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
n8.o: /usr/include/signal.h
E 2
I 2
n8.o: /usr/include/machine/endian.h /usr/include/signal.h
E 2
n9.o: ../common_source/n9.c ../common_source/tdef.h /usr/include/sys/param.h
n9.o: /usr/include/sys/types.h /usr/include/signal.h
n9.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
n9.o: /usr/include/signal.h ../common_source/d.h ../common_source/v.h
E 2
I 2
n9.o: /usr/include/machine/endian.h /usr/include/signal.h ../common_source/d.h
n9.o: ../common_source/v.h
E 2
t10.o: t10.c ../common_source/tdef.h /usr/include/sys/param.h
t10.o: /usr/include/sys/types.h /usr/include/signal.h
t10.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 2
t10.o: /usr/include/signal.h ../common_source/d.h ../common_source/v.h
E 2
I 2
t10.o: /usr/include/machine/endian.h /usr/include/signal.h ../common_source/d.h
t10.o: ../common_source/v.h
E 2
hytab.o: ../common_source/hytab.c
suftab.o: ../common_source/suftab.c
tab3.o: tab3.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
