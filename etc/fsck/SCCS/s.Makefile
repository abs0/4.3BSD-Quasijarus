h59163
s 00075/00094/00035
d D 5.9 87/06/02 21:48:17 bostic 15 12
c new template
e
s 00075/00094/00035
d R 5.9 87/06/02 20:14:54 bostic 14 12
c new template
e
s 00075/00094/00035
d R 5.9 87/06/02 20:09:07 bostic 13 12
c new template
e
s 00001/00001/00128
d D 5.8 85/09/07 19:59:22 mckusick 12 11
c strip on install
e
s 00006/00001/00123
d D 5.7 85/06/05 08:59:13 dist 11 10
c Add copyright
e
s 00003/00004/00121
d D 5.6 85/05/31 00:19:08 mckusick 10 9
c check for improper directory offsets; recover gracefully from read errors
e
s 00002/00005/00123
d D 5.5 85/02/08 19:14:49 mckusick 9 8
c merge passes 5 and 6 into a single pass
e
s 00002/00005/00126
d D 5.4 85/02/07 17:51:20 mckusick 8 7
c code reorganization and cleanup
e
s 00038/00035/00093
d D 5.3 85/02/07 12:41:04 mckusick 7 6
c rebuild dependencies
e
s 00001/00001/00127
d D 5.2 84/08/06 20:30:29 mckusick 6 5
c must install in /etc
e
s 00102/00036/00026
d D 5.1 84/03/31 21:02:56 mckusick 5 4
c break up into managable pieces
e
s 00015/00010/00047
d D 4.4 83/09/10 14:28:57 mckusick 4 3
c add lint entry; fix depend entry
e
s 00038/00007/00019
d D 4.3 83/01/09 00:42:41 mckusick 3 2
c get rid of asm.sed script
e
s 00007/00000/00019
d D 4.2 82/11/15 13:07:49 mckusick 2 1
c add clean and install entries
e
s 00019/00000/00000
d D 4.1 82/11/15 12:59:08 mckusick 1 0
c date and time created 82/11/15 12:59:08 by mckusick
e
u
U
t
T
I 1
D 11
#	%W%	(Berkeley)	%E%
E 11
I 11
#
D 15
# Copyright (c) 1980 Regents of the University of California.
E 15
I 15
# Copyright (c) 1987 Regents of the University of California.
E 15
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 15
#	%W% (Berkeley) %G%
E 15
I 15
#	%W%	(Berkeley)	%G%
E 15
E 11
#
D 5
COPT=
CFLAGS=-O
E 5
I 5
D 15
DESTDIR=
E 15
CFLAGS=	-O
D 7
INCPATH=
E 7
I 7
D 10
INCPATH= -I/usr/include/sys
E 10
E 7
D 15
LFLAGS=	
E 5

D 5
fsck: fsck.o ufs_subr.o ufs_tables.o
	cc ${COPT} -o fsck fsck.o ufs_subr.o ufs_tables.o
E 5
I 5
# The program itself
#
PROG=	fsck
E 5

D 3
fsck.o: fsck.c
	cc ${COPT} ${CFLAGS} -S fsck.c
	/lib/c2 fsck.s | sed -f asm.sed | as -o tmp.o
	ld -r -o fsck.o tmp.o -lc
	rm tmp.o
E 3
I 3
D 5
fscklc.o: fsck.c
	cc ${COPT} ${CFLAGS} -c fsck.c
	ld -r -o fscklc.o fsck.o -lc
E 5
I 5
# Sources
#
D 8
SRCS=	dir.c fsck.c inode.c main.c pass1.c pass1b.c pass2.c \
E 8
I 8
SRCS=	dir.c inode.c main.c pass1.c pass1b.c pass2.c \
E 8
D 9
	pass3.c pass4.c pass5.c pass6.c setup.c utilities.c \
E 9
I 9
	pass3.c pass4.c pass5.c setup.c utilities.c \
E 9
	/sys/sys/ufs_subr.c /sys/sys/ufs_tables.c
E 5
E 3

D 5
ufs_subr.o: /sys/sys/ufs_subr.c
	cc ${COPT} -c /sys/sys/ufs_subr.c
E 5
I 5
# Objects
#
OBJS=	${LOCOBJS} ${SYSOBJS}
E 15
I 15
LIBC=	/lib/libc.a
SRCS=	dir.c inode.c main.c pass1.c pass1b.c pass2.c pass3.c \
	pass4.c pass5.c setup.c utilities.c /sys/sys/ufs_subr.c \
	/sys/sys/ufs_tables.c
E 15
D 8
LOCOBJS=dir.o fsck.o inode.o main.o pass1.o pass1b.o pass2.o \
E 8
I 8
LOCOBJS=dir.o inode.o main.o pass1.o pass1b.o pass2.o \
E 8
D 9
	pass3.o pass4.o pass5.o pass6.o setup.o utilities.o
E 9
I 9
	pass3.o pass4.o pass5.o setup.o utilities.o
E 9
SYSOBJS=ufs_subr.o ufs_tables.o
I 15
OBJS=	${LOCOBJS} ${SYSOBJS}
E 15
E 5

D 5
ufs_tables.o: /sys/sys/ufs_tables.c
	cc ${COPT} -c /sys/sys/ufs_tables.c
E 5
I 5
D 15
# Header files
#
HDRS=	fsck.h
E 15
I 15
all: fsck
E 15
E 5
I 2

I 4
D 5
lint:
	lint fsck.c
E 5
I 5
D 15
${PROG}: ${OBJS} ${HDRS}
	cc ${LFLAGS} -o ${PROG} ${OBJS}
E 15
I 15
fsck:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 15
E 5

E 4
D 5
install: fsck
	install fsck ${DESTDIR}/etc/fsck
E 5
I 5
${LOCOBJS}:
D 10
	cc ${CFLAGS} ${INCPATH} -c $*.c
E 10
I 10
D 15
	cc ${CFLAGS} -c $*.c
E 15
I 15
	${CC} ${CFLAGS} -c $*.c
E 15
E 10
E 5

I 5
ufs_subr.o:
D 10
	cc ${CFLAGS} ${INCPATH} -c /sys/sys/ufs_subr.c
E 10
I 10
D 15
	cc ${CFLAGS} -c /sys/sys/ufs_subr.c
E 15
I 15
	${CC} ${CFLAGS} -c /sys/sys/ufs_subr.c
E 15
E 10

ufs_tables.o:
D 10
	cc ${CFLAGS} ${INCPATH} -c /sys/sys/ufs_tables.c
E 10
I 10
D 15
	cc ${CFLAGS} -I/usr/include/sys -c /sys/sys/ufs_tables.c
E 15
I 15
	${CC} ${CFLAGS} -I/usr/include/sys -c /sys/sys/ufs_tables.c
E 15
E 10

D 15
install: ${PROG}
D 6
	install ${PROG} ${DESTDIR}/usr/local/${PROG}
E 6
I 6
D 12
	install ${PROG} ${DESTDIR}/etc/${PROG}
E 12
I 12
	install -s ${PROG} ${DESTDIR}/etc/${PROG}
E 15
I 15
clean: FRC
	rm -f ${OBJS} fsck core
E 15
E 12
E 6

E 5
D 15
clean:
D 3
	rm -f fsck fsck.o ufs_subr.o ufs_tables.o
	rm -f fsck.s tmp.o errs a.out core
E 3
I 3
D 5
	rm -f fsck fscklc.o fsck.o ufs_subr.o ufs_tables.o
	rm -f errs a.out core
E 5
I 5
	rm -f a.out core ${OBJS} ${PROG}
E 15
I 15
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 15
E 5

I 5
D 15
lint:
	lint ${INCPATH} ${SRCS}
E 15
I 15
install: FRC
	install -s -o bin -g bin -m 755 fsck ${DESTDIR}/etc/fsck
E 15

E 5
D 15
depend:
I 4
D 5
	echo >x.c
E 4
	for i in fsck; do \
		(echo $$i: $$i.c >>makedep; \
D 4
		/bin/grep '^#[ 	]*include' $$i.c | sed \
E 4
I 4
		/bin/grep '^#[ 	]*include' x.c $$i.c | sed \
E 4
			-e '/\.\.\/h/d' \
			-e 's,<\(.*\)>,"/usr/include/\1",' \
			-e 's/:[^"]*"\([^"]*\)".*/: \1/' \
			-e 's/\.c//' >>makedep); done
E 5
I 5
	cc -M ${INCPATH} ${SRCS} | \
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
E 5
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
D 4
	rm eddep makedep
E 4
I 4
D 5
	rm eddep makedep x.c
E 5
I 5
	rm eddep makedep
E 5
E 4
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 15
I 15
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 15

D 15
# DO NOT DELETE THIS LINE -- make depend uses it
E 15
I 15
tags: FRC
	ctags ${SRCS}
E 15

I 15
FRC:
E 15
D 5
fsck: fsck.c
D 4
#include "/usr/include/stdio.h"
#include "/usr/include/ctype.h"
#include "/usr/include/sys/param.h"
#include "/usr/include/sys/fs.h"
#include "/usr/include/sys/inode.h"
#include "/usr/include/dir.h"
#include "/usr/include/sys/stat.h"
#include "/usr/include/fstab.h"
E 4
I 4
fsck: /usr/include/stdio.h
fsck: /usr/include/ctype.h
fsck: /usr/include/sys/param.h
fsck: /usr/include/sys/fs.h
fsck: /usr/include/sys/inode.h
fsck: /usr/include/sys/dir.h
fsck: /usr/include/sys/stat.h
fsck: /usr/include/sys/wait.h
fsck: /usr/include/fstab.h
E 5
I 5

D 7
dir.o: dir.c /usr/include/sys/param.h /usr/include/machine/param.h
dir.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/inode.h
dir.o: /usr/include/sys/fs.h /usr/include/sys/dir.h ./fsck.h
fsck.o: fsck.c /usr/include/sys/param.h /usr/include/machine/param.h
fsck.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/inode.h
fsck.o: /usr/include/sys/fs.h ./fsck.h
inode.o: inode.c /usr/include/sys/param.h /usr/include/machine/param.h
inode.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
D 15
dir.o: dir.c /usr/include/sys/param.h /usr/include/machine/machparam.h
dir.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 15
I 15
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

dir.o: dir.c /usr/include/sys/param.h /usr/include/sys/types.h
dir.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 15
dir.o: /usr/include/sys/inode.h /usr/include/sys/fs.h /usr/include/sys/dir.h
D 15
dir.o: ./fsck.h
D 8
fsck.o: fsck.c /usr/include/sys/param.h /usr/include/machine/machparam.h
fsck.o: /usr/include/sys/signal.h /usr/include/sys/types.h
fsck.o: /usr/include/sys/inode.h /usr/include/sys/fs.h ./fsck.h
E 8
inode.o: inode.c /usr/include/sys/param.h /usr/include/machine/machparam.h
inode.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 7
inode.o: /usr/include/sys/inode.h /usr/include/sys/fs.h /usr/include/sys/dir.h
inode.o: ./fsck.h
D 7
main.o: main.c /usr/include/sys/param.h /usr/include/machine/param.h
main.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/inode.h
main.o: /usr/include/sys/fs.h /usr/include/sys/stat.h /usr/include/sys/wait.h
main.o: /usr/include/fstab.h /usr/include/strings.h ./fsck.h
pass1.o: pass1.c /usr/include/sys/param.h /usr/include/machine/param.h
pass1.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
main.o: main.c /usr/include/sys/param.h /usr/include/machine/machparam.h
main.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 15
I 15
dir.o: fsck.h
inode.o: inode.c /usr/include/pwd.h /usr/include/sys/param.h
inode.o: /usr/include/sys/types.h /usr/include/signal.h
inode.o: /usr/include/machine/machparam.h /usr/include/sys/inode.h
inode.o: /usr/include/sys/fs.h /usr/include/sys/dir.h fsck.h
main.o: main.c /usr/include/sys/param.h /usr/include/sys/types.h
main.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 15
main.o: /usr/include/sys/inode.h /usr/include/sys/fs.h /usr/include/sys/stat.h
main.o: /usr/include/sys/wait.h /usr/include/fstab.h /usr/include/strings.h
D 15
main.o: ./fsck.h
pass1.o: pass1.c /usr/include/sys/param.h /usr/include/machine/machparam.h
pass1.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 7
pass1.o: /usr/include/sys/inode.h /usr/include/sys/fs.h ./fsck.h
D 7
pass1b.o: pass1b.c /usr/include/sys/param.h /usr/include/machine/param.h
pass1b.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
pass1b.o: pass1b.c /usr/include/sys/param.h /usr/include/machine/machparam.h
pass1b.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 7
pass1b.o: /usr/include/sys/inode.h /usr/include/sys/fs.h ./fsck.h
D 7
pass2.o: pass2.c /usr/include/sys/param.h /usr/include/machine/param.h
pass2.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
pass2.o: pass2.c /usr/include/sys/param.h /usr/include/machine/machparam.h
pass2.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 15
I 15
main.o: fsck.h
pass1.o: pass1.c /usr/include/sys/param.h /usr/include/sys/types.h
pass1.o: /usr/include/signal.h /usr/include/machine/machparam.h
pass1.o: /usr/include/sys/inode.h /usr/include/sys/fs.h fsck.h
pass1b.o: pass1b.c /usr/include/sys/param.h /usr/include/sys/types.h
pass1b.o: /usr/include/signal.h /usr/include/machine/machparam.h
pass1b.o: /usr/include/sys/inode.h /usr/include/sys/fs.h fsck.h
pass2.o: pass2.c /usr/include/sys/param.h /usr/include/sys/types.h
pass2.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 15
E 7
pass2.o: /usr/include/sys/inode.h /usr/include/sys/fs.h /usr/include/sys/dir.h
D 15
pass2.o: /usr/include/strings.h ./fsck.h
D 7
pass3.o: pass3.c /usr/include/sys/param.h /usr/include/machine/param.h
pass3.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
pass3.o: pass3.c /usr/include/sys/param.h /usr/include/machine/machparam.h
pass3.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 7
pass3.o: /usr/include/sys/inode.h /usr/include/sys/fs.h ./fsck.h
D 7
pass4.o: pass4.c /usr/include/sys/param.h /usr/include/machine/param.h
pass4.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
pass4.o: pass4.c /usr/include/sys/param.h /usr/include/machine/machparam.h
pass4.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 7
pass4.o: /usr/include/sys/inode.h /usr/include/sys/fs.h ./fsck.h
D 7
pass5.o: pass5.c /usr/include/sys/param.h /usr/include/machine/param.h
pass5.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
pass5.o: pass5.c /usr/include/sys/param.h /usr/include/machine/machparam.h
pass5.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 7
pass5.o: /usr/include/sys/inode.h /usr/include/sys/fs.h ./fsck.h
D 7
pass6.o: pass6.c /usr/include/sys/param.h /usr/include/machine/param.h
pass6.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
D 9
pass6.o: pass6.c /usr/include/sys/param.h /usr/include/machine/machparam.h
pass6.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 7
pass6.o: /usr/include/sys/inode.h /usr/include/sys/fs.h ./fsck.h
E 9
D 7
setup.o: setup.c /usr/include/sys/param.h /usr/include/machine/param.h
setup.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
setup.o: setup.c /usr/include/sys/param.h /usr/include/machine/machparam.h
setup.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 15
I 15
pass2.o: /usr/include/strings.h fsck.h
pass3.o: pass3.c /usr/include/sys/param.h /usr/include/sys/types.h
pass3.o: /usr/include/signal.h /usr/include/machine/machparam.h
pass3.o: /usr/include/sys/inode.h /usr/include/sys/fs.h fsck.h
pass4.o: pass4.c /usr/include/sys/param.h /usr/include/sys/types.h
pass4.o: /usr/include/signal.h /usr/include/machine/machparam.h
pass4.o: /usr/include/sys/inode.h /usr/include/sys/fs.h fsck.h
pass5.o: pass5.c /usr/include/sys/param.h /usr/include/sys/types.h
pass5.o: /usr/include/signal.h /usr/include/machine/machparam.h
pass5.o: /usr/include/sys/inode.h /usr/include/sys/fs.h fsck.h
setup.o: setup.c /usr/include/sys/param.h /usr/include/sys/types.h
setup.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 15
E 7
setup.o: /usr/include/sys/inode.h /usr/include/sys/fs.h /usr/include/sys/stat.h
D 15
setup.o: ./fsck.h
E 15
I 15
setup.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
setup.o: /usr/include/sys/ttydev.h /usr/include/sys/disklabel.h
setup.o: /usr/include/sys/file.h /usr/include/ctype.h fsck.h
E 15
utilities.o: utilities.c /usr/include/stdio.h /usr/include/ctype.h
D 7
utilities.o: /usr/include/sys/param.h /usr/include/machine/param.h
utilities.o: /usr/include/signal.h /usr/include/sys/types.h
E 7
I 7
D 15
utilities.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
utilities.o: /usr/include/sys/signal.h /usr/include/sys/types.h
E 7
utilities.o: /usr/include/sys/inode.h /usr/include/sys/fs.h ./fsck.h
E 15
I 15
utilities.o: /usr/include/sys/param.h /usr/include/sys/types.h
utilities.o: /usr/include/signal.h /usr/include/machine/machparam.h
utilities.o: /usr/include/sys/inode.h /usr/include/sys/fs.h
utilities.o: /usr/include/sys/dir.h fsck.h
E 15
ufs_subr.o: /sys/sys/ufs_subr.c /usr/include/sys/param.h
D 7
ufs_subr.o: /usr/include/machine/param.h /usr/include/signal.h
E 7
I 7
D 15
ufs_subr.o: /usr/include/machine/machparam.h /usr/include/sys/signal.h
E 7
ufs_subr.o: /usr/include/sys/types.h /usr/include/sys/systm.h
E 15
I 15
ufs_subr.o: /usr/include/sys/types.h /usr/include/signal.h
ufs_subr.o: /usr/include/machine/machparam.h /usr/include/sys/systm.h
E 15
ufs_subr.o: /usr/include/sys/mount.h /usr/include/sys/fs.h
D 15
ufs_subr.o: /usr/include/sys/conf.h /usr/include/sys/buf.h
ufs_subr.o: /usr/include/sys/inode.h /usr/include/sys/dir.h
ufs_subr.o: /usr/include/sys/user.h /usr/include/machine/pcb.h
ufs_subr.o: /usr/include/sys/dmap.h /usr/include/sys/time.h
E 15
I 15
ufs_subr.o: /usr/include/sys/buf.h /usr/include/sys/inode.h
ufs_subr.o: /usr/include/sys/dir.h /usr/include/sys/user.h
ufs_subr.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
ufs_subr.o: /usr/include/sys/time.h /usr/include/time.h
E 15
D 7
ufs_subr.o: /usr/include/sys/resource.h /usr/include/errno.h
E 7
I 7
ufs_subr.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
D 15
ufs_subr.o: /usr/include/sys/uio.h /usr/include/sys/errno.h
E 15
I 15
ufs_subr.o: /usr/include/sys/uio.h /usr/include/errno.h
E 15
E 7
ufs_subr.o: /usr/include/sys/quota.h
D 7
ufs_tables.o: /sys/sys/ufs_tables.c /sys/sys/../h/param.h
ufs_tables.o: /usr/include/machine/param.h /usr/include/signal.h
E 7
I 7
ufs_tables.o: /sys/sys/ufs_tables.c /usr/include/sys/param.h
D 15
ufs_tables.o: /usr/include/machine/machparam.h /usr/include/sys/signal.h
E 7
ufs_tables.o: /usr/include/sys/types.h
E 5
E 4
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 15
I 15
ufs_tables.o: /usr/include/sys/types.h /usr/include/signal.h
ufs_tables.o: /usr/include/machine/machparam.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 15
E 3
E 2
E 1
