h33163
s 00008/00088/00026
d D 5.5 04/10/20 08:07:13 msokolov 5 4
c back to 4.3BSD /usr/man format
e
s 00023/00002/00091
d D 5.4 04/10/20 05:09:47 msokolov 4 3
c PostScript
e
s 00002/00002/00091
d D 5.3 99/05/31 17:47:44 msokolov 3 2
c Put vadvise back in! Long live VAX BSD!
e
s 00000/00000/00093
d D 5.2 99/05/31 17:43:48 msokolov 2 1
c bump it up to 5.2
e
s 00093/00000/00000
d D 5.1 99/05/31 17:42:17 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 5.2
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
D 5
MDIR=	/usr/man/cat2
SRCS=	accept.2 access.2 acct.2 adjtime.2 bind.2 brk.2 chdir.2 chmod.2 \
	chown.2 chroot.2 close.2 connect.2 creat.2 dup.2 execve.2 exit.2 \
	fcntl.2 flock.2 fork.2 fsync.2 getdtablesize.2 getgid.2 getgroups.2 \
	gethostid.2 gethostname.2 getitimer.2 getpagesize.2 getpeername.2 \
	getpgrp.2 getpid.2 getpriority.2 getrlimit.2 getrusage.2 \
	getsockname.2 getsockopt.2 gettimeofday.2 getuid.2 intro.2 ioctl.2 \
	kill.2 killpg.2 link.2 listen.2 lseek.2 mkdir.2 mknod.2 mount.2 \
	open.2 pipe.2 profil.2 ptrace.2 quota.2 read.2 readlink.2 reboot.2 \
	recv.2 rename.2 rmdir.2 select.2 send.2 setgroups.2 setpgrp.2 \
	setquota.2 setregid.2 setreuid.2 shutdown.2 sigblock.2 sigpause.2 \
	sigreturn.2 sigsetmask.2 sigstack.2 sigvec.2 socket.2 socketpair.2 \
	stat.2 swapon.2 symlink.2 sync.2 syscall.2 truncate.2 umask.2 \
D 3
	unlink.2 utimes.2 vfork.2 vhangup.2 wait.2 write.2
E 3
I 3
	unlink.2 utimes.2 vadvise.2 vfork.2 vhangup.2 wait.2 write.2
E 3
OBJS=	accept.0 access.0 acct.0 adjtime.0 bind.0 brk.0 chdir.0 chmod.0 \
	chown.0 chroot.0 close.0 connect.0 creat.0 dup.0 execve.0 exit.0 \
	fcntl.0 flock.0 fork.0 fsync.0 getdtablesize.0 getgid.0 getgroups.0 \
	gethostid.0 gethostname.0 getitimer.0 getpagesize.0 getpeername.0 \
	getpgrp.0 getpid.0 getpriority.0 getrlimit.0 getrusage.0 \
	getsockname.0 getsockopt.0 gettimeofday.0 getuid.0 intro.0 ioctl.0 \
	kill.0 killpg.0 link.0 listen.0 lseek.0 mkdir.0 mknod.0 mount.0 \
	open.0 pipe.0 profil.0 ptrace.0 quota.0 read.0 readlink.0 reboot.0 \
	recv.0 rename.0 rmdir.0 select.0 send.0 setgroups.0 setpgrp.0 \
	setquota.0 setregid.0 setreuid.0 shutdown.0 sigblock.0 sigpause.0 \
	sigreturn.0 sigsetmask.0 sigstack.0 sigvec.0 socket.0 socketpair.0 \
	stat.0 swapon.0 symlink.0 sync.0 syscall.0 truncate.0 umask.0 \
D 3
	unlink.0 utimes.0 vfork.0 vhangup.0 wait.0 write.0
E 3
I 3
	unlink.0 utimes.0 vadvise.0 vfork.0 vhangup.0 wait.0 write.0
E 3
LINKS=	dup2.0 sbrk.0 fstat.0 lstat.0 readv.0 recvfrom.0 recvmsg.0 errno.0 \
	sendmsg.0 sendto.0 wait3.0 fchmod.0 fchown.0 umount.0 writev.0 \
	getegid.0 geteuid.0 getppid.0 ftruncate.0 sethostid.0 setitimer.0 \
	setrlimit.0 setsockopt.0 sethostname.0 setpriority.0 settimeofday.0 \
	seek.0
I 4
PSMANS=	intro.ps accept.ps access.ps acct.ps adjtime.ps bind.ps brk.ps \
	chdir.ps chmod.ps chown.ps chroot.ps close.ps connect.ps creat.ps \
	dup.ps execve.ps exit.ps fcntl.ps flock.ps fork.ps fsync.ps \
	getdtablesize.ps getgid.ps getgroups.ps gethostid.ps gethostname.ps \
	getitimer.ps getpagesize.ps getpeername.ps getpgrp.ps getpid.ps \
	getpriority.ps getrlimit.ps getrusage.ps getsockname.ps getsockopt.ps \
	gettimeofday.ps getuid.ps ioctl.ps kill.ps killpg.ps link.ps listen.ps \
	lseek.ps mkdir.ps mknod.ps mount.ps open.ps pipe.ps profil.ps \
	ptrace.ps quota.ps read.ps readlink.ps reboot.ps recv.ps rename.ps \
	rmdir.ps select.ps send.ps setgroups.ps setpgrp.ps setquota.ps \
	setregid.ps setreuid.ps shutdown.ps sigblock.ps sigpause.ps \
	sigreturn.ps sigsetmask.ps sigstack.ps sigvec.ps socket.ps \
	socketpair.ps stat.ps swapon.ps symlink.ps sync.ps syscall.ps \
	truncate.ps umask.ps unlink.ps utimes.ps vadvise.ps vfork.ps \
	vhangup.ps wait.ps write.ps
E 5
I 5
MDIR=	/usr/man/man2
E 5
E 4

D 4
.SUFFIXES: .2 .0
E 4
I 4
D 5
.SUFFIXES: .2 .0 .ps
E 5
I 5
all:
E 5
E 4

D 5
.2.0:
	${DESTDIR}/usr/man/manroff $*.2 > $*.0
E 5
I 5
psman: FRC
	for i in *.2; do echo $$i; pstroff -man $$i > $$i.ps; done
E 5

I 4
D 5
.2.ps:
	pstroff -man $*.2 > $*.ps

E 4
all: ${OBJS}

I 4
man2.ps: ${PSMANS}
	pstmerge ${PSMANS} > $@

E 5
E 4
clean: FRC
D 4
	rm -f ${OBJS}
E 4
I 4
D 5
	rm -f *.0 *.ps
E 5
I 5
	rm -f *.ps
E 5
E 4

install: FRC
D 5
	cd ${DESTDIR}${MDIR}; rm -f *.0
	install -c -o bin -g bin -m 444 ${OBJS} ${DESTDIR}${MDIR}
	ln ${DESTDIR}${MDIR}/dup.0 ${DESTDIR}${MDIR}/dup2.0
	ln ${DESTDIR}${MDIR}/brk.0 ${DESTDIR}${MDIR}/sbrk.0
	ln ${DESTDIR}${MDIR}/intro.0 ${DESTDIR}/${MDIR}/errno.0
	ln ${DESTDIR}${MDIR}/stat.0 ${DESTDIR}${MDIR}/fstat.0
	ln ${DESTDIR}${MDIR}/stat.0 ${DESTDIR}${MDIR}/lstat.0
	ln ${DESTDIR}${MDIR}/read.0 ${DESTDIR}${MDIR}/readv.0
	ln ${DESTDIR}${MDIR}/recv.0 ${DESTDIR}${MDIR}/recvfrom.0
	ln ${DESTDIR}${MDIR}/recv.0 ${DESTDIR}${MDIR}/recvmsg.0
	ln ${DESTDIR}${MDIR}/send.0 ${DESTDIR}${MDIR}/sendmsg.0
	ln ${DESTDIR}${MDIR}/send.0 ${DESTDIR}${MDIR}/sendto.0
	ln ${DESTDIR}${MDIR}/wait.0 ${DESTDIR}${MDIR}/wait3.0
	ln ${DESTDIR}${MDIR}/chmod.0 ${DESTDIR}${MDIR}/fchmod.0
	ln ${DESTDIR}${MDIR}/chown.0 ${DESTDIR}${MDIR}/fchown.0
	ln ${DESTDIR}${MDIR}/mount.0 ${DESTDIR}${MDIR}/umount.0
	ln ${DESTDIR}${MDIR}/write.0 ${DESTDIR}${MDIR}/writev.0
	ln ${DESTDIR}${MDIR}/getgid.0 ${DESTDIR}${MDIR}/getegid.0
	ln ${DESTDIR}${MDIR}/getuid.0 ${DESTDIR}${MDIR}/geteuid.0
	ln ${DESTDIR}${MDIR}/getpid.0 ${DESTDIR}${MDIR}/getppid.0
	ln ${DESTDIR}${MDIR}/truncate.0 ${DESTDIR}${MDIR}/ftruncate.0
	ln ${DESTDIR}${MDIR}/gethostid.0 ${DESTDIR}${MDIR}/sethostid.0
	ln ${DESTDIR}${MDIR}/getitimer.0 ${DESTDIR}${MDIR}/setitimer.0
	ln ${DESTDIR}${MDIR}/getrlimit.0 ${DESTDIR}${MDIR}/setrlimit.0
	ln ${DESTDIR}${MDIR}/getsockopt.0 ${DESTDIR}${MDIR}/setsockopt.0
	ln ${DESTDIR}${MDIR}/gethostname.0 ${DESTDIR}${MDIR}/sethostname.0
	ln ${DESTDIR}${MDIR}/getpriority.0 ${DESTDIR}${MDIR}/setpriority.0
	ln ${DESTDIR}${MDIR}/gettimeofday.0 ${DESTDIR}${MDIR}/settimeofday.0
	ln ${DESTDIR}${MDIR}/lseek.0 ${DESTDIR}${MDIR}/seek.0
E 5
I 5
	cd ${DESTDIR}${MDIR}; rm -f *.2
	install -c -o bin -g bin -m 444 *.2 ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.2 ${DESTDIR}${MDIR}
E 5

FRC:
E 1
