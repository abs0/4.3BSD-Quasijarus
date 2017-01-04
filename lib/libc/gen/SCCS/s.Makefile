h18536
s 00005/00004/00248
d D 5.28 2012/06/21 01:33:49 msokolov 67 66
c a smarter way to put ctype_ and errlst into .text
e
s 00006/00012/00246
d D 5.27 2012/06/21 01:23:13 msokolov 66 65
c gen/ctime is going away to make room for the new Quasijarus version
e
s 00010/00005/00248
d D 5.26 88/06/27 17:33:59 bostic 65 64
c install approved copyright notice
e
s 00002/00002/00251
d D 5.25 88/05/24 07:45:59 bostic 64 63
c depend on source; won't find regexp files otherwise
e
s 00002/00002/00251
d D 5.24 88/05/23 20:44:13 bostic 63 62
c add setjmperr to standard source lsit
e
s 00001/00000/00252
d D 5.23 88/05/20 14:56:28 bostic 62 61
c set DEFS to compile in SCCS ids.
e
s 00061/00043/00191
d D 5.22 88/05/20 13:43:19 bostic 61 58
c restructuring libc
e
s 00060/00042/00192
d R 5.22 88/05/20 13:42:26 bostic 60 58
c restructuring libc
e
s 00013/00008/00226
d R 5.22 87/12/24 15:18:51 bostic 59 58
c remove setenv (folded into getenv); replace copyright
e
s 00004/00005/00230
d D 5.21 87/11/05 14:34:52 bostic 58 57
c move frexp.c into machine dependent areas
e
s 00064/00043/00171
d D 5.20 87/11/04 09:23:01 bostic 57 56
c break up src list based on machine; add {frexp,rindex,index}.c 
c for tahoe
e
s 00004/00001/00210
d D 5.19 87/10/06 19:19:27 bostic 56 55
c use :errfix script; so can declare sys_nerr multiple times
e
s 00013/00005/00198
d D 5.18 87/09/30 16:49:46 bostic 55 53
c added regexp directory
e
s 00012/00004/00199
d R 5.18 87/09/30 16:48:39 bostic 54 53
c added regexp directory
e
s 00050/00039/00153
d D 5.17 87/09/30 10:33:26 bostic 53 52
c add frexp.c to portability code; bug report 4.3BSD/lib/39
e
s 00001/00004/00191
d D 5.16 87/09/18 14:02:19 bostic 52 51
c use -R, not :errfix script to make errlst.o text
e
s 00001/00001/00194
d D 5.15 87/08/31 15:31:05 bostic 51 50
c spelling check
e
s 00009/00008/00186
d D 5.14 87/07/02 14:45:52 bostic 50 48
c added strcasecmp.c
e
s 00008/00008/00186
d R 5.14 87/07/02 14:43:39 bostic 49 48
c added strcasecmp.c
e
s 00010/00024/00184
d D 5.13 87/06/06 14:38:47 bostic 48 47
c new template
e
s 00005/00005/00203
d D 5.12 87/04/10 14:58:41 bostic 47 46
c remove mkstemp
e
s 00037/00035/00171
d D 5.11 87/04/01 09:59:29 bostic 46 45
c time package update
e
s 00014/00011/00192
d D 5.10 87/03/04 18:23:04 bostic 45 44
c removed ctime.[oc], timezone.[oc], added timemk.[co], 
c localtime.[co] and asctime.[co] for the new date package
e
s 00005/00006/00198
d D 5.9 87/01/28 10:14:38 mckusick 44 43
c add C versions of bstring functions
e
s 00043/00038/00161
d D 5.8 87/01/19 15:34:19 karels 43 42
c add disklabel (from ../machine/gen/disktab.c)
e
s 00002/00004/00197
d D 5.7 86/03/26 10:27:59 bloom 42 41
c header files changed in popen and syslog
e
s 00018/00009/00183
d D 5.6 86/01/09 19:26:07 mckusick 41 40
c add getusershell.c, usleep.c, and ualarm.c
e
s 00117/00001/00075
d D 5.5 85/09/05 11:49:13 bloom 40 38
c fix make clean and add make depend
e
s 00117/00001/00075
d R 5.5 85/09/05 10:10:26 bloom 39 38
c fix make clean and add make depend
e
s 00019/00002/00057
d D 5.4 85/08/23 19:52:23 mckusick 38 37
c spell out vax rewritten routines
e
s 00001/00001/00058
d D 5.3 85/06/21 16:37:25 mckusick 37 36
c errlst needs DEFS
e
s 00001/00001/00058
d D 5.2 85/06/18 22:47:37 mckusick 36 35
c add DEFS
e
s 00007/00002/00052
d D 5.1 85/06/05 12:03:14 mckusick 35 34
c Add copyright
e
s 00029/00021/00025
d D 4.33 85/05/30 22:34:52 sam 34 33
c add tags
e
s 00001/00001/00045
d D 4.32 85/03/11 22:33:48 mckusick 33 32
c signal.c returns; add siginterrupt.c
e
s 00001/00001/00045
d D 4.31 85/01/25 11:57:19 ralph 32 31
c added C version of abort.
e
s 00001/00001/00045
d D 4.30 85/01/15 14:58:28 ralph 31 30
c take out signalsym().
e
s 00001/00001/00045
d D 4.29 84/12/18 11:33:58 ralph 30 29
c added mkstemp (secure mktemp).
e
s 00001/00001/00045
d D 4.28 84/11/13 15:11:16 karels 29 28
c add fake cleanup()
e
s 00001/00001/00045
d D 4.27 84/11/04 23:03:16 mckusick 28 27
c add signal simulation routine in case signal syscall is not implemented
e
s 00001/00001/00045
d D 4.26 84/08/16 10:13:02 ralph 27 26
c signal.c moved to vax/gen/signal.s
e
s 00001/00001/00045
d D 4.25 84/04/27 10:31:33 ralph 26 25
c added getttyent.o and getttynam.o
e
s 00002/00002/00044
d D 4.24 83/12/05 16:09:05 ralph 25 24
c changed getpwnam and getpwuid to use DBM.
e
s 00002/00001/00044
d D 4.23 83/07/01 23:31:59 sam 24 23
c missing swab
e
s 00005/00003/00040
d D 4.22 83/07/01 18:32:14 sam 23 22
c reorganization
e
s 00005/00008/00038
d D 4.21 83/06/30 16:37:22 sam 22 21
c no exit -> stdio
e
s 00016/00029/00030
d D 4.20 83/06/27 18:25:14 root 21 20
c new organization
e
s 00002/00001/00057
d D 4.19 83/06/20 21:42:16 root 20 19
c add vlimit
e
s 00014/00009/00044
d D 4.18 83/06/10 23:03:00 sam 19 18
c compatibility stuff added
e
s 00002/00002/00051
d D 4.17 83/02/23 14:21:29 sam 18 17
c add compatibility calls
e
s 00004/00004/00049
d D 4.16 83/02/10 22:47:09 sam 17 16
c add psignal stuff{
e
s 00001/00001/00052
d D 4.15 83/01/04 20:51:47 sam 16 15
c add getwd
e
s 00000/00024/00053
d D 4.14 82/12/17 17:12:18 sam 15 14
c purge cruft
e
s 00004/00004/00073
d D 4.13 82/12/10 19:01:15 root 14 13
c add random and scandir
e
s 00019/00008/00058
d D 4.12 82/11/14 13:59:00 sam 13 12
c merge of 4.1b and 4.1c
e
s 00001/00001/00065
d D 4.11 82/09/11 18:01:33 mckusick 12 11
c put back in missing flag
e
s 00014/00002/00052
d D 4.10 82/08/25 21:51:01 sam 11 10
c mv network routines to separate directory
e
s 00013/00001/00041
d D 4.9 82/08/19 17:24:36 sam 10 9
c new /usr/lib/hosts database format
e
s 00001/00001/00041
d D 4.8 82/06/15 12:18:00 mckusick 9 8
c use -x instead of -X for .s files to eliminate local labels
e
s 00002/00002/00040
d D 4.7 82/05/07 21:19:52 mckusick 8 7
c get rid of l3tol.c and ltol3.c
e
s 00001/00001/00041
d D 4.6 82/04/01 10:33:19 root 7 6
c add inigrp.o
e
s 00005/00005/00037
d D 4.5 82/02/21 15:12:54 mckusic 6 5
c remove resetdir; add seekdir, telldir, rexec, rhost, and ruserpass
e
s 00004/00004/00038
d D 4.4 82/02/11 12:23:26 mckusic 5 4
c add directory accessing primatives: opendir, readdir, resetdir, closedir
e
s 00001/00001/00041
d D 4.3 82/02/11 12:05:05 root 4 3
c get rid of mpx stuff
e
s 00002/00002/00040
d D 4.2 81/11/30 14:08:41 mckusic 3 2
c use -X on profiled libraries (to retain statics); -x on regular libraries
e
s 00000/00000/00042
d D 4.1 81/11/29 23:29:46 mckusic 2 1
c bring up to version 4.1
e
s 00042/00000/00000
d D 1.1 81/11/29 23:25:04 mckusick 1 0
c date and time created 81/11/29 23:25:04 by mckusick
e
u
U
t
T
I 1
D 35
# %W% (Berkeley) %G%

E 35
I 35
#
D 55
# Copyright (c) 1980 Regents of the University of California.
E 55
I 55
D 61
# Copyright (c) 1987 Regents of the University of California.
E 55
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 61
I 61
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 61
#
D 55
#	%W% (Berkeley) %G%
E 55
I 55
D 61
#	%W%	(Berkeley)	%G%
E 61
I 61
# Redistribution and use in source and binary forms are permitted
D 65
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 65
I 65
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
E 65
E 61
E 55
#
I 61
D 66
#	%W% (Berkeley) %G%
E 66
I 66
#	%W% (Berkeley) %E%
E 66
#
E 61
I 38
D 57
# Several routines have been rewritten in assembly language for the VAX.
D 50
# If you are not running on a VAX, you should use the original C sources
D 44
# which are included in this directory. Regretably we do not have a C
# version of the bstring(3) routines.
E 44
I 44
# which are included in this directory.
E 50
I 50
# and the TAHOE.  If you are not running on one of these machines, you
# should use the original C sources, which are included in this directory.
E 50
E 44
#
D 48
#ifndef vax
E 48
I 48
#ifndef vax or tahoe
E 48
D 43
#SRCS=	${STDSRC} ${VAXSRC}
#OBJS=	${STDOBJ} ${VAXOBJ}
E 43
I 43
#SRCS=	${STDSRC} ${PORTSRC}
#OBJS=	${STDOBJ} ${PORTOBJ}
E 43
#else
SRCS=	${STDSRC}
OBJS=	${STDOBJ}
D 48
#endif not vax
E 48
I 48
#endif not vax or tahoe
E 57
I 57
# Many of these routines have been rewritten in assembly.  The assembly
D 61
# source can be found in the directory ../${MACHINE}/gen.  The macro
E 61
I 61
# source can be found in the directory gen.${MACHINE}.  The macro
E 61
# ${STDSRC} lists the files needed by all current implementations.  The
# macros ${VAXSRC} and ${TAHOESRC} are the supplemental files needed by
# the VAX and the TAHOE.  ${PORTSRC} is a list of all of the supplemental
# files.
E 57
E 48

I 55
VPATH=	regexp
I 62
DEFS=	-DLIBC_SCCS
E 62
E 55
E 38
E 35
D 36
CFLAGS=	-O
E 36
I 36
CFLAGS=	-O ${DEFS}
E 36
D 34

D 5
OBJS=	atof.o atoi.o atol.o calloc.o chrtab.o crypt.o ctime.o ctype_.o \
	ecvt.o errlst.o execvp.o frexp.o getenv.o getlogin.o \
E 5
I 5
D 13
OBJS=	atof.o atoi.o atol.o calloc.o chrtab.o closedir.o crypt.o \
D 8
	ctime.o ctype_.o ecvt.o errlst.o execvp.o frexp.o getenv.o getlogin.o \
E 5
D 6
	index.o isatty.o l3tol.o ldexp.o ltol3.o \
D 4
	malloc.o mktemp.o modf.o mpx.o nlist.o \
E 4
I 4
D 5
	malloc.o mktemp.o modf.o nlist.o \
E 4
	perror.o qsort.o rand.o regex.o rin.o rindex.o \
E 5
I 5
	malloc.o mktemp.o modf.o nlist.o opendir.o \
	perror.o qsort.o rand.o readdir.o regex.o resetdir.o rin.o rindex.o \
E 5
	sleep.o strcat.o strcatn.o strcmp.o strcmpn.o strcpy.o \
E 6
I 6
D 7
	index.o isatty.o l3tol.o ldexp.o ltol3.o malloc.o mktemp.o \
E 7
I 7
	index.o inigrp.o isatty.o l3tol.o ldexp.o ltol3.o malloc.o mktemp.o \
E 8
I 8
	ctime.o ctype_.o ecvt.o errlst.o execvp.o frexp.o getenv.o \
	getlogin.o index.o inigrp.o isatty.o ldexp.o malloc.o mktemp.o \
E 8
E 7
D 11
	modf.o nlist.o opendir.o perror.o qsort.o rand.o readdir.o \
	regex.o rexec.o rhost.o rin.o rindex.o ruserpass.o \
E 11
I 11
	modf.o nlist.o opendir.o perror.o qsort.o rand.o \
	readdir.o regex.o rin.o rindex.o \
E 11
	seekdir.o sleep.o strcat.o strcatn.o strcmp.o strcmpn.o strcpy.o \
E 6
	strcpyn.o strlen.o strncat.o strncmp.o strncpy.o stty.o swab.o \
D 6
	tell.o timezone.o ttyname.o ttyslot.o udiv.o urem.o valloc.o
E 6
I 6
	tell.o telldir.o timezone.o ttyname.o ttyslot.o udiv.o urem.o valloc.o
E 13
I 13
D 19
OBJS=	abort.o abs.o alloca.o atof.o atoi.o atol.o \
D 18
	calloc.o chrtab.o closedir.o crypt.o ctime.o ctype_.o \
E 18
I 18
	calloc.o chrtab.o closedir.o creat.o crypt.o ctime.o ctype_.o \
E 19
I 19
D 21
STD=	abort.o abs.o alloca.o atof.o atoi.o atol.o \
	calloc.o chrtab.o closedir.o crypt.o ctime.o ctype_.o \
E 19
E 18
	ecvt.o errlst.o execvp.o exit.o \
	fabs.o frexp.o \
D 16
	getenv.o getlogin.o \
E 16
I 16
	getenv.o getlogin.o getwd.o \
E 16
	index.o initgroups.o isatty.o itol.o \
	ldexp.o locv.o ltod.o ltoi.o \
	malloc.o mktemp.o modf.o \
	nargs.o nlist.o \
E 21
I 21
D 23
OBJS=	atoi.o atol.o \
E 23
I 23
D 32
OBJS=	alarm.o atoi.o atol.o \
E 32
I 32
OBJS=	abort.o alarm.o atoi.o atol.o \
E 32
E 23
	calloc.o closedir.o crypt.o ctime.o ctype_.o \
D 22
	disktab.o \
	ecvt.o errlst.o execvp.o \
	frexp.o fstab.o \
E 22
I 22
	errlst.o execvp.o \
D 29
	fstab.o \
E 29
I 29
	fakcu.o fstab.o \
E 29
E 22
	gcvt.o getenv.o getgrent.o getgrgid.o getgrnam.o getlogin.o \
D 25
	getpass.o getpwent.o getpwnam.o getpwuid.o getwd.o \
E 25
I 25
D 26
	getpass.o getpwent.o getpwnamuid.o getwd.o \
E 26
I 26
	getpass.o getpwent.o getpwnamuid.o getttyent.o getttynam.o getwd.o \
E 26
E 25
D 22
	index.o initgroups.o isatty.o \
E 22
I 22
	initgroups.o isatty.o \
E 22
D 30
	malloc.o mktemp.o \
E 30
I 30
	malloc.o mkstemp.o mktemp.o \
E 30
D 25
	nlist.o \
E 25
I 25
	ndbm.o nlist.o \
E 25
E 21
	opendir.o \
D 17
	perror.o \
E 17
I 17
D 21
	perror.o psignal.o \
E 21
I 21
	perror.o popen.o psignal.o \
E 21
E 17
	qsort.o \
D 14
	rand.o readdir.o regex.o reset.o rin.o rindex.o \
	seekdir.o setjmp.o sleep.o strcat.o strcatn.o strcmp.o strcmpn.o \
	strcpy.o strcpyn.o strlen.o strncat.o strncmp.o strncpy.o stty.o \
	swab.o \
E 14
I 14
D 19
	rand.o random.o readdir.o regex.o reset.o rin.o rindex.o \
D 17
	scandir.o seekdir.o setjmp.o sleep.o strcat.o strcatn.o strcmp.o \
	strcmpn.o strcpy.o strcpyn.o strlen.o strncat.o strncmp.o strncpy.o \
	stty.o swab.o \
E 17
I 17
	scandir.o seekdir.o setjmp.o siglist.o sleep.o strcat.o strcatn.o \
	strcmp.o strcmpn.o strcpy.o strcpyn.o strlen.o strncat.o strncmp.o \
	strncpy.o stty.o swab.o \
E 17
E 14
D 18
	tell.o telldir.o timezone.o ttyname.o ttyslot.o \
E 18
I 18
	tell.o telldir.o time.o timezone.o ttyname.o ttyslot.o \
E 19
I 19
D 21
	random.o readdir.o regex.o reset.o rin.o rindex.o \
	scandir.o seekdir.o setjmp.o siglist.o signal.o sleep.o strcat.o \
	strcatn.o strcmp.o strcmpn.o strcpy.o strcpyn.o strlen.o strncat.o \
	strncmp.o strncpy.o stty.o swab.o syslog.o \
	telldir.o time.o timezone.o ttyname.o ttyslot.o \
E 19
E 18
	udiv.o urem.o \
	valloc.o
I 19
# time should be here, but everyone uses it...
D 20
COMPAT=	alarm.o ftime.o nice.o pause.o rand.o tell.o times.o utime.o vtimes.o
E 20
I 20
COMPAT=	alarm.o ftime.o nice.o pause.o rand.o tell.o times.o utime.o \
	vlimit.o vtimes.o
E 20
OBJS=	${STD} ${COMPAT}
E 21
I 21
D 22
	random.o readdir.o regex.o rindex.o \
	scandir.o seekdir.o siglist.o signal.o sleep.o strcat.o \
	strcatn.o strcmp.o strcmpn.o strcpy.o strcpyn.o strlen.o \
	strncat.o strncmp.o strncpy.o syslog.o system.o \
E 22
I 22
	random.o readdir.o regex.o \
D 23
	scandir.o seekdir.o siglist.o signal.o sleep.o syslog.o system.o \
E 22
	telldir.o time.o timezone.o ttyname.o ttyslot.o
E 23
I 23
	scandir.o seekdir.o setgid.o setegid.o setrgid.o setuid.o \
E 34
I 34
D 38
SRCS=	abort.c alarm.c atoi.c atol.c calloc.c closedir.c crypt.c \
E 38
I 38
D 45
STDSRC=	abort.c alarm.c atoi.c atol.c calloc.c closedir.c crypt.c \
E 38
D 41
	ctime.c ctype_.c errlst.c execvp.c fakcu.c fstab.c gcvt.c \
	getenv.c getgrent.c getgrgid.c getgrnam.c getlogin.c getpass.c \
	getpwent.c getpwnamuid.c getttyent.c getttynam.c getwd.c \
E 41
I 41
D 43
	ctime.c ctype_.c errlst.c execvp.c fakcu.c fstab.c gcvt.c getenv.c \
	getgrent.c getgrgid.c getgrnam.c getlogin.c getpass.c getpwent.c \
	getpwnamuid.c getttyent.c getttynam.c getusershell.c getwd.c \
E 41
	initgroups.c isatty.c malloc.c mkstemp.c mktemp.c ndbm.c nlist.c \
	opendir.c perror.c popen.c psignal.c qsort.c random.c readdir.c \
	regex.c scandir.c seekdir.c setgid.c setegid.c setrgid.c setuid.c \
	seteuid.c setruid.c siglist.c signal.c siginterrupt.c sleep.c \
E 43
I 43
	ctime.c ctype_.c disklabel.c errlst.c execvp.c fakcu.c fstab.c gcvt.c \
E 45
I 45
D 46
STDSRC=	abort.c alarm.c asctime.c atoi.c atol.c calloc.c closedir.c crypt.c \
	ctype_.c disklabel.c errlst.c execvp.c fakcu.c fstab.c gcvt.c \
E 45
	getenv.c getgrent.c getgrgid.c getgrnam.c getlogin.c getpass.c \
	getpwent.c getpwnamuid.c getttyent.c getttynam.c getusershell.c \
D 45
	getwd.c initgroups.c isatty.c malloc.c mkstemp.c mktemp.c ndbm.c \
E 45
I 45
	getwd.c initgroups.c isatty.c localtime.c malloc.c mkstemp.c mktemp.c ndbm.c \
E 45
	nlist.c opendir.c perror.c popen.c psignal.c qsort.c random.c \
	readdir.c regex.c scandir.c seekdir.c setgid.c setegid.c setrgid.c \
	setuid.c seteuid.c setruid.c siglist.c signal.c siginterrupt.c sleep.c \
E 43
D 45
	swab.c syslog.c system.c telldir.c time.c timezone.c ttyname.c \
E 45
I 45
	swab.c syslog.c system.c telldir.c time.c timemk.c ttyname.c \
E 45
D 41
	ttyslot.c valloc.c
E 41
I 41
	ttyslot.c ualarm.c usleep.c valloc.c
E 41
D 38
OBJS=	abort.o alarm.o atoi.o atol.o calloc.o closedir.o crypt.o \
E 38
I 38
D 43
VAXSRC=	index.c rindex.c strcat.c strcmp.c strcpy.c strlen.c \
E 43
I 43
D 44
PORTSRC=index.c rindex.c strcat.c strcmp.c strcpy.c strlen.c \
E 43
	strncat.c strncmp.c strncpy.c
E 44
I 44
PORTSRC=index.c rindex.c strcat.c strcmp.c strcpy.c strlen.c strncat.c  \
	strncmp.c strncpy.c bcmp.c bcopy.c bzero.c ffs.c insque.c remque.c
E 44
D 45
STDOBJ=	abort.o alarm.o atoi.o atol.o calloc.o closedir.o crypt.o \
E 38
D 41
	ctime.o ctype_.o errlst.o execvp.o fakcu.o fstab.o gcvt.o \
	getenv.o getgrent.o getgrgid.o getgrnam.o getlogin.o getpass.o \
	getpwent.o getpwnamuid.o getttyent.o getttynam.o getwd.o \
E 41
I 41
D 43
	ctime.o ctype_.o errlst.o execvp.o fakcu.o fstab.o gcvt.o getenv.o \
	getgrent.o getgrgid.o getgrnam.o getlogin.o getpass.o getpwent.o \
	getpwnamuid.o getttyent.o getttynam.o getusershell.o getwd.o \
E 41
	initgroups.o isatty.o malloc.o mkstemp.o mktemp.o ndbm.o nlist.o \
	opendir.o perror.o popen.o psignal.o qsort.o random.o readdir.o \
	regex.o scandir.o seekdir.o setgid.o setegid.o setrgid.o setuid.o \
E 34
D 24
	seteuid.o setruid.o siglist.o signal.o sleep.o syslog.o system.o \
E 24
I 24
D 27
	seteuid.o setruid.o siglist.o signal.o sleep.o \
E 27
I 27
D 28
	seteuid.o setruid.o siglist.o sleep.o \
E 28
I 28
D 31
	seteuid.o setruid.o siglist.o signalsim.o sleep.o \
E 31
I 31
D 33
	seteuid.o setruid.o siglist.o sleep.o \
E 33
I 33
	seteuid.o setruid.o siglist.o signal.o siginterrupt.o sleep.o \
E 43
I 43
	ctime.o ctype_.o disklabel.o errlst.o execvp.o fakcu.o fstab.o gcvt.o \
E 45
I 45
STDOBJ=	abort.o alarm.o asctime.o atoi.o atol.o calloc.o closedir.o crypt.o \
	ctype_.o disklabel.o errlst.o execvp.o fakcu.o fstab.o gcvt.o \
E 45
	getenv.o getgrent.o getgrgid.o getgrnam.o getlogin.o getpass.o \
	getpwent.o getpwnamuid.o getttyent.o getttynam.o getusershell.o \
D 45
	getwd.o initgroups.o isatty.o malloc.o mkstemp.o mktemp.o ndbm.o \
E 45
I 45
	getwd.o initgroups.o isatty.o localtime.o malloc.o mkstemp.o mktemp.o ndbm.o \
E 45
	nlist.o opendir.o perror.o popen.o psignal.o qsort.o random.o \
	readdir.o regex.o scandir.o seekdir.o setgid.o setegid.o setrgid.o \
	setuid.o seteuid.o setruid.o siglist.o signal.o siginterrupt.o sleep.o \
E 43
E 33
E 31
E 28
E 27
D 34
	swab.o syslog.o system.o \
E 24
	telldir.o time.o timezone.o ttyname.o ttyslot.o \
	valloc.o
E 34
I 34
D 45
	swab.o syslog.o system.o telldir.o time.o timezone.o ttyname.o \
E 45
I 45
	swab.o syslog.o system.o telldir.o time.o timemk.o ttyname.o \
E 45
D 41
	ttyslot.o valloc.o
E 41
I 41
	ttyslot.o ualarm.o usleep.o valloc.o
E 41
I 38
D 43
VAXOBJ=	index.o rindex.o strcat.o strcmp.o strcpy.o strlen.o \
E 43
I 43
D 44
PORTOBJ=index.o rindex.o strcat.o strcmp.o strcpy.o strlen.o \
E 43
	strncat.o strncmp.o strncpy.o
E 44
I 44
PORTOBJ=index.o rindex.o strcat.o strcmp.o strcpy.o strlen.o strncat.o  \
	strncmp.o strncpy.o bcmp.o bcopy.o bzero.o ffs.o insque.o remque.o
E 46
I 46
D 57
STDSRC=	abort.c alarm.c atoi.c atol.c calloc.c closedir.c \
	crypt.c ctime.c ctype_.c disklabel.c errlst.c execvp.c fakcu.c \
	fstab.c gcvt.c getenv.c getgrent.c getgrgid.c getgrnam.c getlogin.c \
	getpass.c getpwent.c getpwnamuid.c getttyent.c getttynam.c \
	getusershell.c getwd.c initgroups.c isatty.c malloc.c \
D 47
	mkstemp.c mktemp.c ndbm.c nlist.c opendir.c perror.c popen.c \
E 47
I 47
	mktemp.c ndbm.c nlist.c opendir.c perror.c popen.c \
E 47
D 55
	psignal.c qsort.c random.c readdir.c regex.c scandir.c seekdir.c \
E 55
I 55
	psignal.c qsort.c random.c readdir.c regex.c regerror.c \
	regexp.c regsub.c scandir.c seekdir.c \
E 55
	setegid.c setenv.c seteuid.c setgid.c setrgid.c setruid.c setuid.c \
E 57
I 57
D 66
STDSRC=	abort.c alarm.c atoi.c atol.c calloc.c closedir.c crypt.c ctime.c \
E 66
I 66
STDSRC=	abort.c alarm.c atoi.c atol.c calloc.c closedir.c crypt.c \
E 66
D 61
	ctype_.c disklabel.c errlst.c execvp.c fakcu.c fstab.c gcvt.c \
E 61
I 61
	ctype_.c disklabel.c errlst.c execvp.c fakcu.c fstab.c \
E 61
	getenv.c getgrent.c getgrgid.c getgrnam.c getlogin.c getpass.c \
	getpwent.c getpwnamuid.c getttyent.c getttynam.c getusershell.c \
	getwd.c initgroups.c isatty.c malloc.c mktemp.c ndbm.c nlist.c \
	opendir.c perror.c popen.c psignal.c qsort.c random.c readdir.c \
	regerror.c regex.c regexp.c regsub.c scandir.c seekdir.c setegid.c \
D 63
	setenv.c seteuid.c setgid.c setrgid.c setruid.c setuid.c \
E 63
I 63
	setenv.c seteuid.c setgid.c setjmperr.c setrgid.c setruid.c setuid.c \
E 63
E 57
D 50
	siginterrupt.c siglist.c signal.c sleep.c swab.c syslog.c system.c \
	telldir.c time.c timezone.c ttyname.c ttyslot.c ualarm.c \
	usleep.c valloc.c
E 50
I 50
	siginterrupt.c siglist.c signal.c sleep.c strcasecmp.c swab.c \
	syslog.c system.c telldir.c time.c timezone.c ttyname.c ttyslot.c \
	ualarm.c usleep.c valloc.c
E 50
D 53
PORTSRC=bcmp.c bcopy.c bzero.c ffs.c index.c insque.c remque.c rindex.c \
	strcat.c strcmp.c strcpy.c strlen.c strncat.c strncmp.c strncpy.c
E 53
I 53
D 57
PORTSRC=bcmp.c bcopy.c bzero.c ffs.c frexp.c index.c insque.c remque.c \
	rindex.c strcat.c strcmp.c strcpy.c strlen.c strncat.c strncmp.c \
	strncpy.c
E 53
STDOBJ=	abort.o alarm.o atoi.o atol.o calloc.o closedir.o \
	crypt.o ctime.o ctype_.o disklabel.o errlst.o execvp.o fakcu.o \
	fstab.o gcvt.o getenv.o getgrent.o getgrgid.o getgrnam.o getlogin.o \
	getpass.o getpwent.o getpwnamuid.o getttyent.o getttynam.o \
	getusershell.o getwd.o initgroups.o isatty.o malloc.o \
D 47
	mkstemp.o mktemp.o ndbm.o nlist.o opendir.o perror.o popen.o \
E 47
I 47
	mktemp.o ndbm.o nlist.o opendir.o perror.o popen.o \
E 47
D 55
	psignal.o qsort.o random.o readdir.o regex.o scandir.o seekdir.o \
E 55
I 55
	psignal.o qsort.o random.o readdir.o regex.o regerror.o \
	regexp.o regsub.o scandir.o seekdir.o \
E 55
	setegid.o setenv.o seteuid.o setgid.o setrgid.o setruid.o setuid.o \
E 57
I 57
D 66
STDOBJ=	abort.o alarm.o atoi.o atol.o calloc.o closedir.o crypt.o ctime.o \
E 66
I 66
STDOBJ=	abort.o alarm.o atoi.o atol.o calloc.o closedir.o crypt.o \
E 66
D 61
	ctype_.o disklabel.o errlst.o execvp.o fakcu.o fstab.o gcvt.o \
E 61
I 61
	ctype_.o disklabel.o errlst.o execvp.o fakcu.o fstab.o \
E 61
	getenv.o getgrent.o getgrgid.o getgrnam.o getlogin.o getpass.o \
	getpwent.o getpwnamuid.o getttyent.o getttynam.o getusershell.o \
	getwd.o initgroups.o isatty.o malloc.o mktemp.o ndbm.o nlist.o \
	opendir.o perror.o popen.o psignal.o qsort.o random.o readdir.o \
	regerror.o regex.o regexp.o regsub.o scandir.o seekdir.o setegid.o \
D 63
	setenv.o seteuid.o setgid.o setrgid.o setruid.o setuid.o \
E 63
I 63
	setenv.o seteuid.o setgid.o setjmperr.o setrgid.o setruid.o setuid.o \
E 63
E 57
D 50
	siginterrupt.o siglist.o signal.o sleep.o swab.o syslog.o system.o \
	telldir.o time.o timezone.o ttyname.o ttyslot.o ualarm.o \
	usleep.o valloc.o
E 50
I 50
	siginterrupt.o siglist.o signal.o sleep.o strcasecmp.o swab.o \
	syslog.o system.o telldir.o time.o timezone.o ttyname.o ttyslot.o \
	ualarm.o usleep.o valloc.o
E 50
D 53
PORTOBJ=bcmp.o bcopy.o bzero.o ffs.o index.o insque.o remque.o rindex.o \
	strcat.o strcmp.o strcpy.o strlen.o strncat.o strncmp.o strncpy.o
E 53
I 53
D 57
PORTOBJ=bcmp.o bcopy.o bzero.o ffs.o frexp.o index.o insque.o remque.o \
	rindex.o strcat.o strcmp.o strcpy.o strlen.o strncat.o strncmp.o \
	strncpy.o
E 57
I 57
VAXSRC=
VAXOBJ=
D 58
TAHOESRC=	frexp.c index.c rindex.c
TAHOEOBJ=	frexp.o index.o rindex.o
PORTSRC=	bcmp.c bcopy.c bzero.c ffs.c frexp.c index.c insque.c \
E 58
I 58
TAHOESRC=	index.c rindex.c
TAHOEOBJ=	index.o rindex.o
PORTSRC=	bcmp.c bcopy.c bzero.c ffs.c index.c insque.c \
E 58
		remque.c rindex.c strcat.c strcmp.c strcpy.c strlen.c \
		strncat.c strncmp.c strncpy.c
D 58
PORTOBJ=	bcmp.o bcopy.o bzero.o ffs.o frexp.o index.o insque.o \
E 58
I 58
PORTOBJ=	bcmp.o bcopy.o bzero.o ffs.o index.o insque.o \
E 58
		remque.o rindex.o strcat.o strcmp.o strcpy.o strlen.o \
		strncat.o strncmp.o strncpy.o
E 57
E 53
E 46
E 44
E 38
TAGSFILE=tags
E 34
E 23
E 21
E 19
E 13
E 6

.c.o:
D 10
	${CC} -p ${CFLAGS} -c $*.c
E 10
I 10
D 12
	${CC} -p ${CFLAGS} $*.c
E 12
I 12
D 61
	${CC} -p ${CFLAGS} -c $*.c
E 12
E 10
	-ld -X -r $*.o
	mv a.out profiled/$*.o
E 61
I 61
	@${CC} -p ${CFLAGS} -c $*.c
	@-ld -X -o profiled/$*.o -r $*.o
E 61
	${CC} ${CFLAGS} -c $*.c
D 3
	-ld -X -r $*.o
E 3
I 3
D 21
	-ld -x -r $*.o
E 3
	mv a.out $*.o

.s.o:
	sed -f mcount.sed $*.s | ${AS} -o $*.o
D 9
	-ld -X -r $*.o
E 9
I 9
	-ld -x -r $*.o
E 9
	mv a.out profiled/$*.o
	${AS} -o $*.o $*.s
E 21
D 3
	-ld -X -r $*.o
E 3
I 3
D 61
	-ld -x -r $*.o
E 3
	mv a.out $*.o
E 61
I 61
	@-ld -x -r $*.o
	@mv a.out $*.o
E 61

D 57
genlib genlib_p: ${OBJS}
E 57
I 57
D 61
genlib genlib_p: lib.${MACHINE}
E 61
I 61
all: lib.${MACHINE}
E 61

I 61
link: lib.${MACHINE} link.${MACHINE}

link.vax:
	(cd ../library; rm -f  ${STDOBJ} ${VAXOBJ})
	(cd ../profiled; rm -f  ${STDOBJ} ${VAXOBJ})
	ln  ${STDOBJ} ${VAXOBJ} ../library
	(cd profiled; ln  ${STDOBJ} ${VAXOBJ} ../../profiled)

link.tahoe:
	(cd ../library; rm -f  ${STDOBJ} ${TAHOEOBJ})
	(cd ../profiled; rm -f  ${STDOBJ} ${TAHOEOBJ})
	ln  ${STDOBJ} ${TAHOEOBJ} ../library
	(cd profiled; ln  ${STDOBJ} ${TAHOEOBJ} ../../profiled)

E 61
lib.vax: ${STDOBJ} ${VAXOBJ}
E 57
D 19
	ar cru genlib ${OBJS}
	cd profiled; ar cru ../genlib_p ${OBJS}
E 19
I 19
D 61
	@echo "building profiled genlib"
D 57
	@cd profiled; ar cru ../genlib_p ${OBJS}
E 57
I 57
	@cd profiled; ar cru ../genlib_p ${STDOBJ} ${VAXOBJ}
E 57
D 51
	@echo "buiding normal genlib"
E 51
I 51
	@echo "building normal genlib"
E 51
D 57
	@ar cru genlib ${OBJS}
E 57
I 57
	@ar cru genlib ${STDOBJ} ${VAXOBJ}
E 61
E 57
E 19

I 57
lib.tahoe: ${STDOBJ} ${TAHOEOBJ}
D 61
	@echo "building profiled genlib"
	@cd profiled; ar cru ../genlib_p ${STDOBJ} ${TAHOEOBJ}
	@echo "building normal genlib"
	@ar cru genlib ${STDOBJ} ${TAHOEOBJ}
E 61

I 67
ctype_.o: ctype_.c
	${CC} ${DEFS} -R -c ctype_.c
	cp ctype_.o profiled/ctype_.o

E 67
E 57
D 34
clean:
	rm -f genlib genlib_p ${OBJS} profiled/*.o
I 10

E 34
D 15
rhost.o: rhost.c
I 11
	${CC} -p -S ${CFLAGS} $*.c
	sed -f asm.sed $*.s | as -o $*.o
	rm -f $*.s
	-ld -X -r $*.o
	mv a.out profiled/$*.o
	${CC} -S ${CFLAGS} -c $*.c
	sed -f asm.sed $*.s | as -o $*.o
	rm -f $*.s
	-ld -x -r $*.o
	mv a.out $*.o

raddr.o: raddr.c
E 11
	${CC} -p -S ${CFLAGS} $*.c
	sed -f asm.sed $*.s | as -o $*.o
	rm -f $*.s
	-ld -X -r $*.o
	mv a.out profiled/$*.o
	${CC} -S ${CFLAGS} -c $*.c
	sed -f asm.sed $*.s | as -o $*.o
	rm -f $*.s
	-ld -x -r $*.o
	mv a.out $*.o
E 10

E 15
errlst.o: errlst.c
D 37
	cc -S errlst.c
E 37
I 37
D 48
	cc -S ${DEFS} errlst.c
E 48
I 48
D 52
	${CC} -S ${DEFS} errlst.c
E 48
E 37
	ed - <:errfix errlst.s
	as -o errlst.o errlst.s
E 52
I 52
D 56
	${CC} -c -R ${DEFS} errlst.c
E 56
I 56
D 67
	${CC} -S ${DEFS} errlst.c
	ed - <:errfix errlst.s
	as -o errlst.o errlst.s
E 67
I 67
	${CC} ${DEFS} -R -c errlst.c
E 67
E 56
E 52
	cp errlst.o profiled/errlst.o
I 56
D 67
	rm -f errlst.s
E 67
E 56
D 52
	rm errlst.s
E 52
I 34

D 57
tags:
E 57
I 57
tags: tags.${MACHINE}

D 64
tags.vax:
E 64
I 64
tags.vax: ${STDSRC} ${VAXSRC}
E 64
E 57
	cwd=`pwd`; \
D 57
	for i in ${SRCS}; do \
E 57
I 57
	for i in ${STDSRC} ${VAXSRC}; do \
E 57
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

I 57
D 64
tags.tahoe:
E 64
I 64
tags.tahoe: ${STDSRC} ${TAHOESRC}
E 64
	cwd=`pwd`; \
	for i in ${STDSRC} ${TAHOESRC}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

E 57
clean:
D 40
	rm -f genlib genlib_p ${OBJS} profiled/*.o tags
E 40
I 40
D 48
	rm -f genlib genlib_p *.o profiled/*.o tags Makefile.bak
E 48
I 48
D 61
	rm -f genlib genlib_p *.o profiled/*.o tags
E 61
I 61
	rm -f *.o profiled/* a.out core ${TAGSFILE}
E 61
E 48

D 55
depend:
E 55
I 55
D 57
depend: ${SRCS}
E 55
D 48
	for i in ${SRCS}; do \
	    cc -M ${CFLAGS} $$i | awk ' { if ($$1 != prev) \
		{ if (rec != "") print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		else rec = rec " " $$2 } } \
		END { print rec } ' >> makedep; done
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 48
I 48
	mkdep ${CFLAGS} ${SRCS}
E 57
I 57
depend: depend.${MACHINE}
E 57
E 48

I 57
depend.vax: ${STDSRC} ${VAXSRC}
	mkdep ${CFLAGS} ${STDSRC} ${VAXSRC}

depend.tahoe: ${STDSRC} ${TAHOESRC}
	mkdep ${CFLAGS} ${STDSRC} ${TAHOESRC}

E 57
D 48
# DO NOT DELETE THIS LINE -- make depend uses it
E 48
I 48
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 48

D 53
abort.o: abort.c /usr/include/signal.h
E 53
I 53
abort.o: abort.c /usr/include/signal.h /usr/include/machine/trap.h
E 53
alarm.o: alarm.c /usr/include/sys/time.h /usr/include/time.h
I 45
D 46
asctime.o: asctime.c /usr/include/stdio.h /usr/include/tzfile.h
asctime.o: /usr/include/time.h
E 46
E 45
atoi.o: atoi.c
atol.o: atol.c
calloc.o: calloc.c
D 43
closedir.o: closedir.c /usr/include/sys/param.h
closedir.o: /usr/include/machine/machparam.h /usr/include/signal.h
closedir.o: /usr/include/sys/types.h /usr/include/sys/dir.h
E 43
I 43
closedir.o: closedir.c /usr/include/sys/param.h /usr/include/sys/types.h
D 53
closedir.o: /usr/include/signal.h /usr/include/machine/machparam.h
closedir.o: /usr/include/sys/dir.h
E 53
I 53
closedir.o: /usr/include/signal.h /usr/include/machine/trap.h
D 61
closedir.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
E 61
I 61
closedir.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
closedir.o: /usr/include/sys/dir.h
E 61
E 53
E 43
crypt.o: crypt.c
I 46
D 66
ctime.o: ctime.c /usr/include/sys/param.h /usr/include/sys/types.h
D 53
ctime.o: /usr/include/signal.h /usr/include/machine/machparam.h
ctime.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/tzfile.h
E 53
I 53
ctime.o: /usr/include/signal.h /usr/include/machine/trap.h
D 61
ctime.o: /usr/include/machine/machparam.h /usr/include/sys/time.h
ctime.o: /usr/include/time.h /usr/include/tzfile.h
E 61
I 61
ctime.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
ctime.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/tzfile.h
E 66
E 61
E 53
E 46
D 45
ctime.o: ctime.c /usr/include/sys/time.h /usr/include/time.h
ctime.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 45
ctype_.o: ctype_.c /usr/include/ctype.h
I 43
disklabel.o: disklabel.c /usr/include/sys/param.h /usr/include/sys/types.h
D 53
disklabel.o: /usr/include/signal.h /usr/include/machine/machparam.h
disklabel.o: /usr/include/sys/fs.h /usr/include/sys/file.h
disklabel.o: /usr/include/sys/disklabel.h /usr/include/stdio.h
D 47
disklabel.o: /usr/include/ctype.h
E 47
I 47
disklabel.o: /usr/include/strings.h /usr/include/ctype.h
E 53
I 53
disklabel.o: /usr/include/signal.h /usr/include/machine/trap.h
D 61
disklabel.o: /usr/include/machine/machparam.h /usr/include/sys/fs.h
disklabel.o: /usr/include/sys/file.h /usr/include/sys/disklabel.h
disklabel.o: /usr/include/stdio.h /usr/include/strings.h /usr/include/ctype.h
E 61
I 61
disklabel.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
disklabel.o: /usr/include/sys/fs.h /usr/include/sys/file.h
disklabel.o: /usr/include/sys/disklabel.h /usr/include/stdio.h
disklabel.o: /usr/include/strings.h /usr/include/ctype.h
E 61
E 53
E 47
E 43
errlst.o: errlst.c
execvp.o: execvp.c /usr/include/errno.h
fakcu.o: fakcu.c
fstab.o: fstab.c /usr/include/fstab.h /usr/include/stdio.h /usr/include/ctype.h
D 61
gcvt.o: gcvt.c
E 61
D 46
getenv.o: getenv.c
E 46
I 46
getenv.o: getenv.c /usr/include/stdio.h
E 46
getgrent.o: getgrent.c /usr/include/stdio.h /usr/include/grp.h
getgrgid.o: getgrgid.c /usr/include/grp.h
getgrnam.o: getgrnam.c /usr/include/grp.h
getlogin.o: getlogin.c /usr/include/utmp.h
getpass.o: getpass.c /usr/include/stdio.h /usr/include/signal.h
D 53
getpass.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
getpass.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 53
I 53
getpass.o: /usr/include/machine/trap.h /usr/include/sgtty.h
getpass.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 61
getpass.o: /usr/include/sys/ttydev.h
E 61
I 61
D 66
getpass.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
E 66
I 66
getpass.o: /usr/include/sys/ttydev.h
E 66
E 61
E 53
getpwent.o: getpwent.c /usr/include/stdio.h /usr/include/pwd.h
getpwent.o: /usr/include/ndbm.h
getpwnamuid.o: getpwnamuid.c /usr/include/stdio.h /usr/include/pwd.h
getpwnamuid.o: /usr/include/ndbm.h /usr/include/sys/file.h
getttyent.o: getttyent.c /usr/include/stdio.h /usr/include/strings.h
getttyent.o: /usr/include/ttyent.h
getttynam.o: getttynam.c /usr/include/ttyent.h
I 41
getusershell.o: getusershell.c /usr/include/sys/param.h
D 43
getusershell.o: /usr/include/machine/machparam.h /usr/include/signal.h
getusershell.o: /usr/include/sys/types.h /usr/include/sys/file.h
E 43
I 43
getusershell.o: /usr/include/sys/types.h /usr/include/signal.h
D 53
getusershell.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
E 43
getusershell.o: /usr/include/sys/stat.h /usr/include/ctype.h
getusershell.o: /usr/include/stdio.h
E 53
I 53
getusershell.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 61
getusershell.o: /usr/include/sys/file.h /usr/include/sys/stat.h
getusershell.o: /usr/include/ctype.h /usr/include/stdio.h
E 61
I 61
getusershell.o: /usr/include/machine/endian.h /usr/include/sys/file.h
getusershell.o: /usr/include/sys/stat.h /usr/include/ctype.h
getusershell.o: /usr/include/stdio.h
E 61
E 53
E 41
D 43
getwd.o: getwd.c /usr/include/sys/param.h /usr/include/machine/machparam.h
getwd.o: /usr/include/signal.h /usr/include/sys/types.h /usr/include/sys/stat.h
getwd.o: /usr/include/sys/dir.h
E 43
I 43
getwd.o: getwd.c /usr/include/sys/param.h /usr/include/sys/types.h
D 53
getwd.o: /usr/include/signal.h /usr/include/machine/machparam.h
getwd.o: /usr/include/sys/stat.h /usr/include/sys/dir.h
E 53
I 53
getwd.o: /usr/include/signal.h /usr/include/machine/trap.h
D 61
getwd.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
getwd.o: /usr/include/sys/dir.h
E 61
I 61
getwd.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
getwd.o: /usr/include/sys/stat.h /usr/include/sys/dir.h
E 61
E 53
E 43
initgroups.o: initgroups.c /usr/include/stdio.h /usr/include/sys/param.h
D 43
initgroups.o: /usr/include/machine/machparam.h /usr/include/signal.h
initgroups.o: /usr/include/sys/types.h /usr/include/grp.h
E 43
I 43
initgroups.o: /usr/include/sys/types.h /usr/include/signal.h
D 53
initgroups.o: /usr/include/machine/machparam.h /usr/include/grp.h
E 53
I 53
initgroups.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 61
initgroups.o: /usr/include/grp.h
E 61
I 61
initgroups.o: /usr/include/machine/endian.h /usr/include/grp.h
E 61
E 53
E 43
isatty.o: isatty.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 61
isatty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 61
I 61
D 66
isatty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
isatty.o: /usr/include/sys/ttydev.h
E 66
I 66
isatty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 66
E 61
I 45
D 46
localtime.o: localtime.c /usr/include/sys/param.h /usr/include/sys/types.h
localtime.o: /usr/include/signal.h /usr/include/machine/machparam.h
localtime.o: /usr/include/tzfile.h /usr/include/time.h
E 46
E 45
malloc.o: malloc.c /usr/include/sys/types.h
D 47
mkstemp.o: mkstemp.c /usr/include/sys/file.h
mktemp.o: mktemp.c
E 47
I 47
mktemp.o: mktemp.c /usr/include/sys/types.h /usr/include/sys/file.h
D 48
mktemp.o: /usr/include/ctype.h
E 48
I 48
D 53
mktemp.o: /usr/include/stdio.h /usr/include/ctype.h
E 53
I 53
mktemp.o: /usr/include/sys/stat.h /usr/include/errno.h /usr/include/stdio.h
mktemp.o: /usr/include/ctype.h
E 53
E 48
E 47
ndbm.o: ndbm.c /usr/include/sys/types.h /usr/include/sys/stat.h
ndbm.o: /usr/include/sys/file.h /usr/include/stdio.h /usr/include/errno.h
ndbm.o: /usr/include/ndbm.h
nlist.o: nlist.c /usr/include/sys/types.h /usr/include/a.out.h
nlist.o: /usr/include/sys/exec.h /usr/include/stdio.h
D 43
opendir.o: opendir.c /usr/include/sys/param.h /usr/include/machine/machparam.h
opendir.o: /usr/include/signal.h /usr/include/sys/types.h
E 43
I 43
opendir.o: opendir.c /usr/include/sys/param.h /usr/include/sys/types.h
D 53
opendir.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 43
opendir.o: /usr/include/sys/dir.h
E 53
I 53
opendir.o: /usr/include/signal.h /usr/include/machine/trap.h
D 61
opendir.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
E 61
I 61
opendir.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
opendir.o: /usr/include/sys/dir.h
E 61
E 53
perror.o: perror.c /usr/include/sys/types.h /usr/include/sys/uio.h
popen.o: popen.c /usr/include/stdio.h /usr/include/signal.h
D 42
popen.o: /usr/include/sys/param.h /usr/include/machine/machparam.h
popen.o: /usr/include/signal.h /usr/include/sys/types.h
E 42
D 53
psignal.o: psignal.c /usr/include/signal.h
E 53
I 53
popen.o: /usr/include/machine/trap.h
psignal.o: psignal.c /usr/include/signal.h /usr/include/machine/trap.h
E 53
qsort.o: qsort.c
random.o: random.c /usr/include/stdio.h
D 43
readdir.o: readdir.c /usr/include/sys/param.h /usr/include/machine/machparam.h
readdir.o: /usr/include/signal.h /usr/include/sys/types.h
E 43
I 43
readdir.o: readdir.c /usr/include/sys/param.h /usr/include/sys/types.h
D 53
readdir.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 43
readdir.o: /usr/include/sys/dir.h
E 53
I 53
readdir.o: /usr/include/signal.h /usr/include/machine/trap.h
D 61
readdir.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
E 61
I 61
readdir.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
readdir.o: /usr/include/sys/dir.h
E 61
E 53
D 57
regex.o: regex.c
E 57
I 55
regerror.o: regexp/regerror.c /usr/include/stdio.h
I 57
regex.o: regex.c
E 57
regexp.o: regexp/regexp.c /usr/include/stdio.h /usr/include/ctype.h
regexp.o: /usr/include/regexp.h regexp/regmagic.h
regsub.o: regexp/regsub.c /usr/include/stdio.h /usr/include/regexp.h
regsub.o: regexp/regmagic.h
E 55
scandir.o: scandir.c /usr/include/sys/types.h /usr/include/sys/stat.h
scandir.o: /usr/include/sys/dir.h
D 43
seekdir.o: seekdir.c /usr/include/sys/param.h /usr/include/machine/machparam.h
seekdir.o: /usr/include/signal.h /usr/include/sys/types.h
E 43
I 43
seekdir.o: seekdir.c /usr/include/sys/param.h /usr/include/sys/types.h
D 53
seekdir.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 43
seekdir.o: /usr/include/sys/dir.h
E 53
I 53
seekdir.o: /usr/include/signal.h /usr/include/machine/trap.h
D 61
seekdir.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
E 61
I 61
seekdir.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
seekdir.o: /usr/include/sys/dir.h
E 61
E 53
D 46
setgid.o: setgid.c
E 46
setegid.o: setegid.c
D 46
setrgid.o: setrgid.c
setuid.o: setuid.c
E 46
I 46
setenv.o: setenv.c /usr/include/sys/types.h /usr/include/stdio.h
E 46
seteuid.o: seteuid.c
I 46
setgid.o: setgid.c
I 66
setjmperr.o: setjmperr.c
E 66
setrgid.o: setrgid.c
E 46
setruid.o: setruid.c
I 46
setuid.o: setuid.c
siginterrupt.o: siginterrupt.c /usr/include/signal.h
E 46
D 53
siglist.o: siglist.c /usr/include/signal.h
signal.o: signal.c /usr/include/signal.h
E 53
I 53
siginterrupt.o: /usr/include/machine/trap.h
siglist.o: siglist.c /usr/include/signal.h /usr/include/machine/trap.h
signal.o: signal.c /usr/include/signal.h /usr/include/machine/trap.h
E 53
D 46
siginterrupt.o: siginterrupt.c /usr/include/signal.h
E 46
sleep.o: sleep.c /usr/include/sys/time.h /usr/include/time.h
D 53
sleep.o: /usr/include/signal.h
E 53
I 53
sleep.o: /usr/include/signal.h /usr/include/machine/trap.h
E 53
I 50
D 61
strcasecmp.o: strcasecmp.c
E 61
I 61
strcasecmp.o: strcasecmp.c /usr/include/sys/types.h
E 61
E 50
swab.o: swab.c
syslog.o: syslog.c /usr/include/sys/types.h /usr/include/sys/socket.h
D 41
syslog.o: /usr/include/sys/file.h /usr/include/syslog.h /usr/include/netdb.h
E 41
I 41
D 42
syslog.o: /usr/include/sys/file.h /usr/include/signal.h /usr/include/syslog.h
syslog.o: /usr/include/netdb.h
E 42
I 42
syslog.o: /usr/include/sys/file.h /usr/include/sys/signal.h
D 53
syslog.o: /usr/include/sys/syslog.h /usr/include/netdb.h /usr/include/strings.h
E 42
E 41
system.o: system.c /usr/include/signal.h
E 53
I 53
syslog.o: /usr/include/machine/trap.h /usr/include/sys/syslog.h
syslog.o: /usr/include/netdb.h /usr/include/strings.h
system.o: system.c /usr/include/signal.h /usr/include/machine/trap.h
E 53
D 43
telldir.o: telldir.c /usr/include/sys/param.h /usr/include/machine/machparam.h
telldir.o: /usr/include/signal.h /usr/include/sys/types.h
E 43
I 43
telldir.o: telldir.c /usr/include/sys/param.h /usr/include/sys/types.h
D 53
telldir.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 43
telldir.o: /usr/include/sys/dir.h
E 53
I 53
telldir.o: /usr/include/signal.h /usr/include/machine/trap.h
D 61
telldir.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
E 61
I 61
telldir.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
telldir.o: /usr/include/sys/dir.h
E 61
E 53
time.o: time.c /usr/include/sys/types.h /usr/include/sys/time.h
time.o: /usr/include/time.h
D 45
timezone.o: timezone.c
E 45
I 45
D 46
timemk.o: timemk.c
E 46
I 46
timezone.o: timezone.c /usr/include/sys/types.h /usr/include/sys/time.h
timezone.o: /usr/include/time.h /usr/include/stdio.h /usr/include/tzfile.h
E 46
E 45
D 43
ttyname.o: ttyname.c /usr/include/sys/param.h /usr/include/machine/machparam.h
ttyname.o: /usr/include/signal.h /usr/include/sys/types.h
E 43
I 43
ttyname.o: ttyname.c /usr/include/sys/param.h /usr/include/sys/types.h
D 53
ttyname.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 43
ttyname.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
E 53
I 53
ttyname.o: /usr/include/signal.h /usr/include/machine/trap.h
D 61
ttyname.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
ttyname.o: /usr/include/sys/stat.h
E 61
I 61
ttyname.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
ttyname.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
E 61
E 53
ttyslot.o: ttyslot.c /usr/include/ttyent.h
I 41
ualarm.o: ualarm.c /usr/include/sys/time.h /usr/include/time.h
usleep.o: usleep.c /usr/include/sys/time.h /usr/include/time.h
D 53
usleep.o: /usr/include/signal.h
E 53
I 53
usleep.o: /usr/include/signal.h /usr/include/machine/trap.h
E 53
E 41
valloc.o: valloc.c
I 57
D 58
frexp.o: frexp.c
E 58
D 66
index.o: index.c
rindex.o: rindex.c
E 66
E 57
D 48
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 48
I 48

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 48
E 40
E 34
E 1
