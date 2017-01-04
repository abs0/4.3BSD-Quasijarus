h48064
s 00164/00146/00043
d D 5.4 87/06/16 18:52:19 bostic 13 12
c new template
e
s 00015/00015/00174
d D 5.3 86/07/20 10:58:49 sam 12 11
c make depend
e
s 00001/00001/00188
d D 5.2 85/06/21 20:04:37 mckusick 11 10
c systat installs in /usr/ucb
e
s 00131/00065/00058
d D 5.1 85/05/30 16:57:52 mckusick 10 9
c Add copyright
e
s 00001/00001/00122
d D 1.9 85/05/22 23:14:11 sam 9 8
c correct install to make it setgid kmem
e
s 00002/00002/00121
d D 1.8 85/05/01 01:33:06 sam 8 7
c major rework; fixup netstat stuff; pull disk cmds into common file; change 
c everthing related to disks to use dk_ndrive and global selction; use getw where possible
e
s 00003/00003/00120
d D 1.7 85/04/29 00:42:16 sam 7 6
c add netstat
e
s 00002/00002/00121
d D 1.6 85/04/28 00:36:58 sam 6 5
c add vsta in; add help command (minimal); make loadav display something 
c which can be turned off
e
s 00018/00007/00105
d D 1.5 84/11/19 18:37:22 mckusick 5 4
c make depend
e
s 00100/00010/00012
d D 1.4 84/08/09 19:12:44 mckusick 4 3
c update to new sources from sam; weed out unnecessary #includes
e
s 00003/00001/00019
d D 1.3 83/10/02 20:45:25 sam 3 2
c reorganize window management to allow display routines to set 
c up optimal window definitions
e
s 00002/00001/00018
d D 1.2 83/10/02 14:40:12 sam 2 1
c add init routine and mbuf display; redo swap space display
e
s 00019/00000/00000
d D 1.1 83/10/01 12:20:57 sam 1 0
c date and time created 83/10/01 12:20:57 by sam
e
u
U
t
T
I 1
D 10
#       %M%     %I%     %E%
E 10
I 10
#
D 13
# Copyright (c) 1980 Regents of the University of California.
E 13
I 13
# Copyright (c) 1987 Regents of the University of California.
E 13
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 13
#	%W% (Berkeley) %G%
E 13
I 13
#	%W%	(Berkeley)	%G%
E 13
#
E 10
D 13
DESTDIR=
I 4
INCPATH=
E 4
CFLAGS= -O
D 2
OBJS=   main.o fetch.o pigs.o swap.o
E 2
I 2
D 3
OBJS=   main.o fetch.o pigs.o swap.o mbufs.o
E 3
I 3
D 4
OBJS=	cmds.o cmdtab.o fetch.o iostat.o keyboard.o main.o \
	mbufs.o pigs.o swap.o
E 4
I 4
SRCS=	cmds.c cmdtab.c disks.c fetch.c iostat.c \
D 6
	keyboard.c main.c mbufs.c pigs.c swap.c vmstat.c
E 6
I 6
D 7
	keyboard.c main.c mbufs.c pigs.c swap.c kre.c
E 7
I 7
D 8
	keyboard.c kre.c main.c mbufs.c netstat.c pigs.c swap.c
E 8
I 8
D 10
	keyboard.c kre.c main.c mbufs.c netcmds.c netstat.c pigs.c swap.c
E 10
I 10
	keyboard.c vmstat.c main.c mbufs.c netcmds.c netstat.c pigs.c swap.c
E 10
E 8
E 7
E 6
OBJS=	cmds.o cmdtab.o disks.o fetch.o iostat.o \
D 6
	keyboard.o main.o mbufs.o pigs.o swap.o vmstat.o
E 6
I 6
D 7
	keyboard.o main.o mbufs.o pigs.o swap.o kre.o
E 7
I 7
D 8
	keyboard.o kre.o main.o mbufs.o netstat.o pigs.o swap.o
E 8
I 8
D 10
	keyboard.o kre.o main.o mbufs.o netcmds.o netstat.o pigs.o swap.o
E 10
I 10
	keyboard.o vmstat.o main.o mbufs.o netcmds.o netstat.o pigs.o swap.o
E 10
E 8
E 7
E 6
E 4
E 3
E 2
LIBS=   -lcurses -ltermlib -lm
E 13
I 13
CFLAGS=	-O
LIBC=	/lib/libc.a
LIBS=	-lcurses -ltermlib -lm
SRCS=	cmds.c cmdtab.c disks.c fetch.c iostat.c keyboard.c vmstat.c main.c \
	mbufs.c netcmds.c netstat.c pigs.c swap.c
OBJS=	cmds.o cmdtab.o disks.o fetch.o iostat.o keyboard.o vmstat.o main.o \
	mbufs.o netcmds.o netstat.o pigs.o swap.o
E 13

D 13
systat: ${OBJS}
D 7
	${CC} -o systat ${OBJS} ${LIBS}
E 7
I 7
	${CC} -o systat -O ${OBJS} ${LIBS}
E 13
I 13
all: systat
E 13
E 7

D 4
main.o:	systat.h
fetch.o:systat.h
pigs.o:	systat.h
swap.o:	systat.h
I 2
mbufs.o:systat.h
I 3
iostat.o:systat.h
E 3
E 2

E 4
D 13
install: systat
D 4
	install -s systat ${DESTDIR}/usr/lfl/bin/systat
E 4
I 4
D 9
	install -s systat ${DESTDIR}/usr/local/systat
E 9
I 9
D 11
	install -s -g kmem -m 2755 systat ${DESTDIR}/usr/local/systat
E 11
I 11
	install -s -g kmem -m 2755 systat ${DESTDIR}/usr/ucb/systat
E 13
I 13
systat:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} ${LIBS}
E 13
E 11
E 9
E 4

D 13
clean:
	rm -f ${OBJS} systat core a.out errs
E 13
I 13
clean: FRC
	rm -f ${OBJS} core systat
E 13
I 4

D 13
depend:
	cc -M ${INCPATH} ${SRCS} | \
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 13
I 13
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 13

D 13
# DO NOT DELETE THIS LINE -- make depend uses it
E 13
I 13
install: FRC
	install -s -o bin -g kmem -m 2755 systat ${DESTDIR}/usr/ucb/systat
E 13

I 13
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 13

D 10
cmds.o: cmds.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
cmds.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
D 13
cmds.o: cmds.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
cmds.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
cmds.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
cmds.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
I 5
D 10
cmds.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 5
cmds.o: /usr/include/signal.h /usr/include/ctype.h
cmdtab.o: cmdtab.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
cmdtab.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
cmds.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
cmds.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/file.h
E 13
I 13
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

cmds.o: cmds.c
cmds.o:systat.h
cmds.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
cmds.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
cmds.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
cmds.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
cmds.o: /usr/include/sys/types.h /usr/include/signal.h
cmds.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
E 13
D 12
cmds.o: /usr/include/sys/dk.h /usr/include/netinet/in.h
E 12
I 12
cmds.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
E 12
cmds.o: /usr/include/arpa/inet.h /usr/include/ctype.h
D 13
cmdtab.o: cmdtab.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
cmdtab.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
cmdtab.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
cmdtab.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
I 5
D 10
cmdtab.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 5
disks.o: disks.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
disks.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
cmdtab.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
cmdtab.o: /usr/include/signal.h /usr/include/sys/types.h
D 12
cmdtab.o: /usr/include/sys/file.h /usr/include/sys/dk.h
E 12
I 12
cmdtab.o: /usr/include/sys/file.h /usr/include/sys/dkstat.h
E 12
cmdtab.o: /usr/include/netinet/in.h /usr/include/arpa/inet.h
disks.o: disks.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
disks.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
disks.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
disks.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
disks.o: /usr/include/sys/param.h /usr/include/machine/param.h
E 5
I 5
D 10
disks.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 10
disks.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
E 5
D 10
disks.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/buf.h
disks.o: /usr/include/sys/file.h /usr/include/vaxuba/ubavar.h
disks.o: /usr/include/vaxmba/mbavar.h /usr/include/ctype.h
fetch.o: fetch.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
fetch.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
disks.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/file.h
E 13
I 13
cmdtab.o: cmdtab.c
cmdtab.o:systat.h
cmdtab.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
cmdtab.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
cmdtab.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
cmdtab.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
cmdtab.o: /usr/include/sys/types.h /usr/include/signal.h
cmdtab.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
cmdtab.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
cmdtab.o: /usr/include/arpa/inet.h
disks.o: disks.c
disks.o:systat.h
disks.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
disks.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
disks.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
disks.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
disks.o: /usr/include/sys/types.h /usr/include/signal.h
disks.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
E 13
D 12
disks.o: /usr/include/sys/dk.h /usr/include/netinet/in.h
E 12
I 12
disks.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
E 12
disks.o: /usr/include/arpa/inet.h /usr/include/sys/buf.h /usr/include/ctype.h
D 12
disks.o: /usr/include/vaxuba/ubavar.h /usr/include/vaxmba/mbavar.h
E 12
I 12
disks.o: /usr/include/tahoevba/vbavar.h
E 12
D 13
fetch.o: fetch.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
fetch.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
fetch.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
fetch.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
fetch.o: /usr/include/sys/param.h /usr/include/machine/param.h
E 5
I 5
D 10
fetch.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 10
fetch.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
E 5
D 10
fetch.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/dir.h
E 10
I 10
fetch.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/file.h
E 13
I 13
fetch.o: fetch.c
fetch.o:systat.h
fetch.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
fetch.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
fetch.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
fetch.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
fetch.o: /usr/include/sys/types.h /usr/include/signal.h
fetch.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
E 13
D 12
fetch.o: /usr/include/sys/dk.h /usr/include/netinet/in.h
E 12
I 12
fetch.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
E 12
fetch.o: /usr/include/arpa/inet.h /usr/include/sys/dir.h
E 10
fetch.o: /usr/include/sys/user.h /usr/include/machine/pcb.h
D 10
fetch.o: /usr/include/sys/dmap.h /usr/include/sys/time.h
E 10
I 10
fetch.o: /usr/include/sys/dmap.h /usr/include/sys/time.h /usr/include/time.h
E 10
fetch.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
fetch.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/sys/proc.h
D 10
fetch.o: /usr/include/sys/file.h /usr/include/sys/vmmac.h
fetch.o: /usr/include/machine/pte.h /usr/include/pwd.h
iostat.o: iostat.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
iostat.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
fetch.o: /usr/include/sys/vmmac.h /usr/include/machine/pte.h /usr/include/pwd.h
D 13
iostat.o: iostat.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
iostat.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
iostat.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
iostat.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
iostat.o: /usr/include/sys/param.h /usr/include/machine/param.h
E 5
I 5
D 10
iostat.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 10
iostat.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
E 5
D 10
iostat.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/buf.h
iostat.o: /usr/include/sys/file.h /usr/include/nlist.h
keyboard.o: keyboard.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
keyboard.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
iostat.o: /usr/include/signal.h /usr/include/sys/types.h
D 12
iostat.o: /usr/include/sys/file.h /usr/include/sys/dk.h
E 12
I 12
iostat.o: /usr/include/sys/file.h /usr/include/sys/dkstat.h
E 12
iostat.o: /usr/include/netinet/in.h /usr/include/arpa/inet.h
iostat.o: /usr/include/sys/buf.h
keyboard.o: keyboard.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
keyboard.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
keyboard.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
keyboard.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
I 5
D 10
keyboard.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 5
keyboard.o: /usr/include/signal.h /usr/include/ctype.h
main.o: main.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
main.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
keyboard.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
keyboard.o: /usr/include/signal.h /usr/include/sys/types.h
D 12
keyboard.o: /usr/include/sys/file.h /usr/include/sys/dk.h
E 12
I 12
keyboard.o: /usr/include/sys/file.h /usr/include/sys/dkstat.h
E 12
keyboard.o: /usr/include/netinet/in.h /usr/include/arpa/inet.h
keyboard.o: /usr/include/ctype.h
vmstat.o: vmstat.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
vmstat.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
vmstat.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
vmstat.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
vmstat.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
vmstat.o: /usr/include/signal.h /usr/include/sys/types.h
D 12
vmstat.o: /usr/include/sys/file.h /usr/include/sys/dk.h
E 12
I 12
vmstat.o: /usr/include/sys/file.h /usr/include/sys/dkstat.h
E 12
vmstat.o: /usr/include/netinet/in.h /usr/include/arpa/inet.h
vmstat.o: /usr/include/ctype.h /usr/include/utmp.h /usr/include/sys/vm.h
vmstat.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
vmstat.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
vmstat.o: /usr/include/sys/vmsystm.h /usr/include/sys/buf.h
vmstat.o: /usr/include/sys/stat.h /usr/include/sys/dir.h
E 13
I 13
iostat.o: iostat.c
iostat.o:systat.h
iostat.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
iostat.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
iostat.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
iostat.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
iostat.o: /usr/include/sys/types.h /usr/include/signal.h
iostat.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
iostat.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
iostat.o: /usr/include/arpa/inet.h /usr/include/sys/buf.h
keyboard.o: keyboard.c
keyboard.o:systat.h
keyboard.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
keyboard.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
keyboard.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
keyboard.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
keyboard.o: /usr/include/sys/types.h /usr/include/signal.h
keyboard.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
keyboard.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
keyboard.o: /usr/include/arpa/inet.h /usr/include/ctype.h
vmstat.o: vmstat.c
vmstat.o:systat.h
vmstat.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
vmstat.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
vmstat.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vmstat.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
vmstat.o: /usr/include/sys/types.h /usr/include/signal.h
vmstat.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
vmstat.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
vmstat.o: /usr/include/arpa/inet.h /usr/include/ctype.h /usr/include/utmp.h
vmstat.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
vmstat.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
vmstat.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h
vmstat.o: /usr/include/sys/buf.h /usr/include/sys/stat.h /usr/include/sys/dir.h
E 13
vmstat.o: /usr/include/sys/user.h /usr/include/machine/pcb.h
vmstat.o: /usr/include/sys/dmap.h /usr/include/sys/time.h /usr/include/time.h
vmstat.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
vmstat.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/sys/proc.h
D 12
vmstat.o: /usr/include/sys/namei.h /usr/include/vax/pte.h
E 12
I 12
vmstat.o: /usr/include/sys/namei.h /usr/include/machine/pte.h
E 12
D 13
main.o: main.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
main.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
main.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
main.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
I 5
D 10
main.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 5
main.o: /usr/include/sys/file.h /usr/include/nlist.h /usr/include/signal.h
mbufs.o: mbufs.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
mbufs.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
main.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
main.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/file.h
E 13
I 13
main.o: main.c
main.o:systat.h
main.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
main.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
main.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
main.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
main.o: /usr/include/sys/types.h /usr/include/signal.h
main.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
E 13
D 12
main.o: /usr/include/sys/dk.h /usr/include/netinet/in.h
E 12
I 12
main.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
E 12
main.o: /usr/include/arpa/inet.h
D 13
mbufs.o: mbufs.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
mbufs.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
mbufs.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
mbufs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
mbufs.o: /usr/include/sys/param.h /usr/include/machine/param.h
E 5
I 5
D 10
mbufs.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 10
mbufs.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
E 5
D 10
mbufs.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/mbuf.h
mbufs.o: /usr/include/sys/file.h /usr/include/nlist.h
pigs.o: pigs.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
pigs.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
mbufs.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/file.h
E 13
I 13
mbufs.o: mbufs.c
mbufs.o:systat.h
mbufs.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
mbufs.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
mbufs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
mbufs.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
mbufs.o: /usr/include/sys/types.h /usr/include/signal.h
mbufs.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
E 13
D 12
mbufs.o: /usr/include/sys/dk.h /usr/include/netinet/in.h
E 12
I 12
mbufs.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
E 12
mbufs.o: /usr/include/arpa/inet.h /usr/include/sys/mbuf.h
D 13
netcmds.o: netcmds.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
netcmds.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
netcmds.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
netcmds.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
netcmds.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
netcmds.o: /usr/include/signal.h /usr/include/sys/types.h
D 12
netcmds.o: /usr/include/sys/file.h /usr/include/sys/dk.h
E 12
I 12
netcmds.o: /usr/include/sys/file.h /usr/include/sys/dkstat.h
E 12
netcmds.o: /usr/include/netinet/in.h /usr/include/arpa/inet.h
netcmds.o: /usr/include/ctype.h /usr/include/sys/socket.h
netcmds.o: /usr/include/sys/socketvar.h /usr/include/sys/mbuf.h
netcmds.o: /usr/include/sys/protosw.h /usr/include/net/route.h
netcmds.o: /usr/include/netinet/in_systm.h /usr/include/netinet/in_pcb.h
netstat.o: netstat.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
netstat.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
netstat.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
netstat.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
netstat.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
netstat.o: /usr/include/signal.h /usr/include/sys/types.h
D 12
netstat.o: /usr/include/sys/file.h /usr/include/sys/dk.h
E 12
I 12
netstat.o: /usr/include/sys/file.h /usr/include/sys/dkstat.h
E 12
netstat.o: /usr/include/netinet/in.h /usr/include/arpa/inet.h
netstat.o: /usr/include/sys/socket.h /usr/include/sys/socketvar.h
netstat.o: /usr/include/sys/mbuf.h /usr/include/sys/protosw.h
netstat.o: /usr/include/net/route.h /usr/include/netinet/in_systm.h
netstat.o: /usr/include/netinet/in_pcb.h /usr/include/netinet/ip.h
netstat.o: /usr/include/netinet/ip_icmp.h /usr/include/netinet/icmp_var.h
netstat.o: /usr/include/netinet/ip_var.h /usr/include/netinet/tcp.h
netstat.o: /usr/include/netinet/tcpip.h /usr/include/netinet/tcp_seq.h
netstat.o: /usr/include/netinet/tcp_fsm.h /usr/include/netinet/tcp_timer.h
netstat.o: /usr/include/netinet/tcp_var.h /usr/include/netinet/tcp_debug.h
netstat.o: /usr/include/netinet/udp.h /usr/include/netinet/udp_var.h
pigs.o: pigs.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
pigs.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
pigs.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
pigs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
pigs.o: /usr/include/sys/param.h /usr/include/machine/param.h
E 5
I 5
D 10
pigs.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 10
pigs.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
E 5
D 10
pigs.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/dir.h
pigs.o: /usr/include/sys/time.h /usr/include/sys/proc.h /usr/include/sys/file.h
pigs.o: /usr/include/nlist.h /usr/include/pwd.h
swap.o: swap.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
swap.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
I 10
pigs.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/file.h
E 13
I 13
netcmds.o: netcmds.c
netcmds.o:systat.h
netcmds.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
netcmds.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
netcmds.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
netcmds.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
netcmds.o: /usr/include/sys/types.h /usr/include/signal.h
netcmds.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
netcmds.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
netcmds.o: /usr/include/arpa/inet.h /usr/include/ctype.h
netcmds.o: /usr/include/sys/socket.h /usr/include/sys/socketvar.h
netcmds.o: /usr/include/sys/mbuf.h /usr/include/sys/protosw.h
netcmds.o: /usr/include/net/route.h /usr/include/netinet/in_systm.h
netcmds.o: /usr/include/netinet/in_pcb.h
netstat.o: netstat.c
netstat.o:systat.h
netstat.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
netstat.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
netstat.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
netstat.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
netstat.o: /usr/include/sys/types.h /usr/include/signal.h
netstat.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
netstat.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
netstat.o: /usr/include/arpa/inet.h /usr/include/sys/socket.h
netstat.o: /usr/include/sys/socketvar.h /usr/include/sys/mbuf.h
netstat.o: /usr/include/sys/protosw.h /usr/include/net/route.h
netstat.o: /usr/include/netinet/in_systm.h /usr/include/netinet/in_pcb.h
netstat.o: /usr/include/netinet/ip.h /usr/include/netinet/ip_icmp.h
netstat.o: /usr/include/netinet/icmp_var.h /usr/include/netinet/ip_var.h
netstat.o: /usr/include/netinet/tcp.h /usr/include/netinet/tcpip.h
netstat.o: /usr/include/netinet/tcp_seq.h /usr/include/netinet/tcp_fsm.h
netstat.o: /usr/include/netinet/tcp_timer.h /usr/include/netinet/tcp_var.h
netstat.o: /usr/include/netinet/tcp_debug.h /usr/include/netinet/udp.h
netstat.o: /usr/include/netinet/udp_var.h
pigs.o: pigs.c
pigs.o:systat.h
pigs.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
pigs.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
pigs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
pigs.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
pigs.o: /usr/include/sys/types.h /usr/include/signal.h
pigs.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
E 13
D 12
pigs.o: /usr/include/sys/dk.h /usr/include/netinet/in.h
E 12
I 12
pigs.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
E 12
pigs.o: /usr/include/arpa/inet.h /usr/include/sys/dir.h /usr/include/sys/time.h
pigs.o: /usr/include/time.h /usr/include/sys/proc.h /usr/include/pwd.h
D 13
swap.o: swap.c ./systat.h /usr/include/netdb.h /usr/include/nlist.h
swap.o: /usr/include/signal.h /usr/include/curses.h /usr/include/stdio.h
swap.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 10
swap.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
swap.o: /usr/include/sys/param.h /usr/include/machine/param.h
E 5
I 5
D 10
swap.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
E 10
swap.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
E 5
D 10
swap.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/dir.h
swap.o: /usr/include/sys/user.h /usr/include/machine/pcb.h
swap.o: /usr/include/sys/dmap.h /usr/include/sys/time.h
swap.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
swap.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/sys/proc.h
swap.o: /usr/include/sys/text.h /usr/include/sys/conf.h /usr/include/sys/file.h
E 10
I 10
swap.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/file.h
E 13
I 13
swap.o: swap.c
swap.o:systat.h
swap.o: /usr/include/netdb.h /usr/include/nlist.h /usr/include/signal.h
swap.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
swap.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
swap.o: /usr/include/sys/ttydev.h /usr/include/sys/param.h
swap.o: /usr/include/sys/types.h /usr/include/signal.h
swap.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
E 13
D 12
swap.o: /usr/include/sys/dk.h /usr/include/netinet/in.h
E 12
I 12
swap.o: /usr/include/sys/dkstat.h /usr/include/netinet/in.h
E 12
swap.o: /usr/include/arpa/inet.h /usr/include/sys/dir.h /usr/include/sys/user.h
swap.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
swap.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/sys/resource.h
swap.o: /usr/include/sys/namei.h /usr/include/sys/uio.h /usr/include/errno.h
swap.o: /usr/include/sys/proc.h /usr/include/sys/text.h /usr/include/sys/conf.h
E 10
swap.o: /usr/include/sys/vmmac.h /usr/include/machine/pte.h
D 10
swap.o: /usr/include/nlist.h
vmstat.o: vmstat.c ./systat.h /usr/include/sys/dk.h /usr/include/curses.h
vmstat.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
vmstat.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
vmstat.o: /usr/include/sys/param.h /usr/include/machine/param.h
E 5
I 5
vmstat.o: /usr/include/sys/jioctl.h /usr/include/sys/ioctl.h
vmstat.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
E 5
vmstat.o: /usr/include/signal.h /usr/include/sys/types.h
vmstat.o: /usr/include/sys/vmmeter.h /usr/include/sys/file.h
vmstat.o: /usr/include/nlist.h
E 10
D 13
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 13
I 13

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 13
E 4
E 1
