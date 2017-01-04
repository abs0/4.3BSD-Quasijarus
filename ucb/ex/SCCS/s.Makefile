h22828
s 00002/00003/00313
d D 7.22.1.1 88/08/08 18:34:08 mckusick 45 44
c delete decryption for the foreign sites (4.3BSD Tahoe)
e
s 00164/00296/00152
d D 7.22 87/11/24 15:30:37 bostic 44 43
c remove bcopy.c
e
s 00002/00003/00446
d D 7.21 87/10/07 09:29:05 bostic 43 41
c fix mkdir line
e
s 00001/00002/00447
d R 7.21 87/10/07 09:28:04 bostic 42 41
c fix mkdir line
e
s 00001/00001/00448
d D 7.20 87/09/14 11:26:35 bostic 41 40
c remove FLOCK define
e
s 00001/00001/00448
d D 7.19 87/07/22 09:46:03 bostic 40 39
c shut mkdir up
e
s 00002/00002/00447
d D 7.18 87/06/29 15:38:21 conrad 39 37
c Bill Jolitz's flock code
e
s 00118/00376/00073
d R 7.18 87/06/28 23:08:00 conrad 38 37
c Update for flock() code
e
s 00006/00002/00443
d D 7.17 87/06/27 21:04:31 karels 37 36
c watch it! exrecover and expreserve don't get xstr'd!
e
s 00373/00121/00072
d D 7.16 87/06/16 19:58:07 bostic 36 35
c new template
e
s 00002/00000/00191
d D 7.15 87/05/31 21:09:10 bostic 35 34
c added depend label
e
s 00003/00002/00188
d D 7.14 87/03/09 12:47:24 conrad 34 32
c make ex/vi work on vms
e
s 00002/00003/00187
d D 7.13.1.1 86/08/12 15:52:31 mckusick 33 32
c delete decryption for the foreign sites
e
s 00002/00002/00188
d D 7.13 86/01/22 17:43:26 mckusick 32 31
c specify owner for suid
e
s 00002/00002/00188
d D 7.12 85/09/07 16:05:10 mckusick 31 30
c strip on install
e
s 00007/00001/00183
d D 7.11 85/05/31 15:36:15 dist 30 27
c Add copyright
e
s 00007/00000/00217
d D 5.2.2.1 85/05/31 15:35:44 dist 29 13
c Add copyright
e
s 00007/00000/00217
d D 5.2.1.1 85/05/31 11:49:28 dist 28 13
c Add copyright
e
s 00003/00003/00181
d D 7.10 85/05/31 11:46:05 bloom 27 26
c Add ex_tagio for fast tag lookup
e
s 00002/00002/00182
d D 7.9 84/04/17 10:04:25 peter 26 25
c reinstating the ``make ex_vars.h'' entry.
c [why was this commented out, i wonder?]
c note that since the Makefile doesn't include dependencies
c if you make ex_vars.h you also have to make clean and then make a.out.
e
s 00002/00001/00182
d D 7.8 83/07/09 11:08:03 sam 25 24
c too much output
e
s 00001/00001/00182
d D 7.7 83/07/09 10:59:23 sam 24 23
c don't make tags by default
e
s 00029/00028/00154
d D 7.6 83/07/03 23:03:58 sam 23 22
c cleanup
e
s 00005/00007/00177
d D 7.5 83/06/10 14:36:24 ralph 22 21
c uses install instead of cp
e
s 00002/00001/00182
d D 7.4 81/08/13 14:16:15 mark 21 20
c told it to use STDIO in CFLAGS for fast tag searching
e
s 00001/00001/00182
d D 7.3 81/07/26 20:05:34 mark 20 19
c fixes for 3b
e
s 00002/00002/00181
d D 7.2 81/07/09 23:08:06 mark 19 18
c 
e
s 00005/00005/00178
d D 7.1 81/07/08 22:36:41 mark 18 17
c release 3.7 - a few bug fixes and a few new features.
e
s 00001/00003/00182
d D 6.4 80/11/03 09:11:47 mark 17 16
c final 3.6 release - took out TIMEBOMB code
e
s 00001/00001/00184
d D 6.3 80/10/23 16:20:22 mark 16 15
c fixed various bugs prior to 3.6 release
e
s 00003/00001/00182
d D 6.2 80/10/19 01:49:11 mark 15 14
c fixed version number
e
s 00012/00046/00171
d D 6.1 80/10/19 01:23:16 mark 14 13
c preliminary release 3.6 10/18/80
e
s 00004/00004/00213
d D 5.2 80/08/21 11:18:21 mark 13 12
c un-commented out pieces of make vgrind
e
s 00003/00002/00214
d D 5.1 80/08/20 16:17:23 mark 12 11
c Release 3.5, August 20, 1980
e
s 00004/00007/00212
d D 4.8 80/08/20 15:45:25 mark 11 10
c defined CRYPT in CFLAGS
e
s 00004/00013/00215
d D 4.7 80/08/03 20:22:48 bill 10 9
c use ${CC}, ${AS}; don't delete source on sccs clean
e
s 00011/00002/00217
d D 4.6 80/08/02 00:03:18 mark 9 8
c made make clean get rid of sources too
e
s 00002/00002/00217
d D 4.5 80/08/01 23:54:09 mark 8 7
c commented out ex_vars.h since you manually do makeoptions
e
s 00036/00035/00183
d D 4.4 80/08/01 23:52:34 mark 7 6
c added dependencies on headers, kludged on ex.c
e
s 00039/00000/00179
d D 4.3 80/08/01 23:12:27 mark 6 5
c added sccs since make doesn't know about it
e
s 00074/00034/00105
d D 4.2 80/08/01 20:44:55 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00006/00003/00133
d D 4.1 80/08/01 00:21:03 mark 4 3
c release 3.4, June 24, 1980
e
s 00001/00001/00135
d D 3.1 80/07/31 23:46:21 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00084/00052/00052
d D 2.1 80/07/31 23:22:36 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00104/00000/00000
d D 1.1 80/07/31 23:01:12 mark 1 0
c date and time created 80/07/31 23:01:12 by mark
e
u
U
f b 
t
T
I 29
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 29
I 28
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 28
I 23
D 30
#	%M%	%I%	%E%
E 30
I 30
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 39
#	%W% (Berkeley) %G%
E 39
I 39
D 43
#	@(#)Makefile	7.17 (Berkeley) 6/27/87
E 43
I 43
#	%W% (Berkeley) %G%
E 43
E 39
#
E 30
E 23
I 1
D 2
VERSION=3.1
E 2
I 2
D 3
VERSION=3.2
E 3
I 3
D 4
VERSION=3.3
E 4
I 4
D 12
VERSION=3.4
E 12
I 12
D 15
VERSION=3.5
E 15
I 15
D 18
VERSION=3.6
E 18
I 18
VERSION=3.7
E 18
E 15
E 12
E 4
E 3
E 2
#
D 2
# Ex skeletal makefile for Version 7
E 2
I 2
D 5
# Ex skeletal makefile for version 7
E 5
I 5
D 18
# Ex skeletal makefile for VAX VM/Unix version 7
E 18
I 18
D 23
# Ex skeletal makefile for VAX VM/Unix 4.1BSD
E 23
I 23
# Ex skeletal makefile for VAX VM/Unix 4.2BSD
E 23
E 18
E 5
E 2
#
D 37
# NB: This makefile doesn't indicate any dependencies on header files.
#
E 37
D 2
# Compiles in the LISPCODE code within the editor;
# take this out of CFLAGS to make some
# breathing room in the text space if necessary.  If you take out -DLISPCODE
# you should move ex_vars.nolisp to ex_vars.h
E 2
I 2
D 5
# Ex is very large - it may not fit on PDP-11's depending on the operating
# system and the cflags you turn on. Things that can be turned off to save
E 5
I 5
# Ex is very large - this version will not fit on PDP-11's without overlay
# software.  Things that can be turned off to save
E 5
# space include LISPCODE (-l flag, showmatch and lisp options), UCVISUAL
# (visual \ nonsense on upper case only terminals), CHDIR (the undocumented
D 5
# chdir command.)
E 5
I 5
D 12
# chdir command.)  VMUNIX makes ex considerably larger, raising many limits
E 12
I 12
D 33
D 45
# chdir command.)  CRYPT includes the code to edit encrypted files (the -x
# option, like ed.)  VMUNIX makes ex considerably larger, raising many limits
E 45
I 45
# chdir command.) VMUNIX makes ex considerably larger, raising many limits
E 45
E 33
I 33
# chdir command.)  VMUNIX makes ex considerably larger, raising many limits
E 33
E 12
# and improving speed and simplicity of maintenance.  It is suitable only
# for a VAX or other large machine, and then probably only in a paged system.
E 5
E 2
#
I 2
# Don't define VFORK unless your system has the VFORK system call,
# which is like fork but the two processes have only one data space until the
# child execs. This speeds up ex by saving the memory copy.
D 5
# -DVMUNIX makes an ex which can edit very large files (eg the w2a dictionary)
# this allows 200000 lines and about 16M byte temp files.
E 5
#
E 2
# If your system expands tabs to 4 spaces you should -DTABS=4 below
#
D 2
# Ex wants stdio only to get the doprnt.o routine; if other stdio stuff
# gets dragged in that is a mistake.
E 2
I 2
D 5
# Ex is likely to overflow the symbol table in your C compiler.
# It can use -t0 which is (purportedly) a C compiler with a larger
# symbol table.  The -t1 flag to the C compiler is for a C compiler
# which puts switch code in I space, increasing the text space size
# to the benefit of per-user data space.  If you don't have this it
# doesn't matter much. Another method, which works on v7 pdp-11's,
# is to use pcc for ex_io.c instead of cc.
E 2
#
E 5
D 2
.c.o:
	${MKSTR} - ex${VERSION}strings x $*.c
	${CC} -E ${CFLAGS} x$*.c | ${XSTR} -c -
	rm -f x$*.c
	${CC} ${CFLAGS} -O -c x.c 
	mv x.o $*.o
BINDIR=	/usr/bin
E 2
I 2
D 36
BINDIR=	/usr/ucb
NBINDIR=/usr/new
E 2
LIBDIR=	/usr/lib
D 2
FOLD=	/usr/bin/fold
CTAGS=	/usr/ucb/ctags
AS=	-as
XSTR=	/usr/ucb/xstr
CFLAGS=	-DTABS=8 -DLISPCODE
MKSTR=	/usr/ucb/mkstr
CXREF=	/usr/ucb/cxref
E 2
I 2
FOLD=	${BINDIR}/fold
CTAGS=	${BINDIR}/ctags
XSTR=	${BINDIR}/xstr
D 5
DEBUGFLAGS=	-DTRACE
NONDEBUGFLAGS=	-O
CFLAGS=	-DTABS=8 -DLISPCODE -DCHDIR -DUCVISUAL -DMACROS -DVFORK -DVMUNIX ${NONDEBUGFLAGS}
E 5
I 5
D 14
DEBUGFLAGS=	-DTRACE -g
E 14
I 14
D 16
DEBUGFLAGS=	-DMDEBUG -DTRACE -g
E 16
I 16
DEBUGFLAGS=	-DTRACE -g
E 16
E 14
D 11
#
# D O   N O T   D I S T R I B U T E   E X    W I T H   H O R S E   I N   I T!!!
NONDEBUGFLAGS=	-O -DHORSE
E 11
I 11
NONDEBUGFLAGS=	-O
E 11
DEB=	${NONDEBUGFLAGS}	# or ${DEBUGFLAGS} to to debug
I 15
D 17
# NOTE: TIMEBOMB is NOT intended for production use, or even to
# get off our vax.  It is there to help nail a bug that happens rarely.
E 15
D 11
CFLAGS=	-DTABS=8 -DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX ${DEB}
E 11
I 11
D 14
CFLAGS=	-DTABS=8 -DCRYPT -DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX ${DEB}
E 14
I 14
CFLAGS=	-DTABS=8 -DCRYPT -DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX -DTIMEBOMB ${DEB}
E 17
I 17
D 21
CFLAGS=	-DTABS=8 -DCRYPT -DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX ${DEB}
E 21
I 21
D 27
OPTIONS= -DCRYPT -DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX -DSTDIO
E 27
I 27
D 33
D 34
OPTIONS= -DCRYPT -DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX -DFASTTAG
E 34
I 34
OPTIONS= -DCRYPT -DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX -DFASTTAG\
	-DUNIX_SBRK
E 34
E 33
I 33
OPTIONS= -DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX -DFASTTAG
E 33
E 27
CFLAGS=	-DTABS=8 ${OPTIONS} ${DEB}
E 21
E 17
E 14
E 11
LDFLAGS=	-z		# or -i or -n
E 5
D 14
TERMLIB=	-ltermlib
E 14
I 14
TERMLIB=	-ltermcap
E 14
MKSTR=	${BINDIR}/mkstr
CXREF=	${BINDIR}/cxref
E 2
INCLUDE=/usr/include
PR=	pr
D 5
OBJS=	ex.o ex_addr.o ex_cmds.o ex_cmds2.o ex_cmdsub.o ex_data.o ex_get.o \
D 4
	ex_io.o ex_put.o ex_re.o ex_set.o ex_subr.o ex_temp.o ex_tty.o \
E 4
I 4
	ex_io.o ex_put.o ex_re.o ex_set.o ex_subr.o ex_temp.o ex_tty.o ex_unix.o \
E 5
I 5
OBJS=	ex.o ex_addr.o ex_cmds.o ex_cmds2.o ex_cmdsub.o \
D 18
	ex_data.o ex_get.o ex_io.o ex_put.o ex_re.o \
E 18
I 18
	ex_data.o ex_extern.o ex_get.o ex_io.o ex_put.o ex_re.o \
E 18
D 27
	ex_set.o ex_subr.o ex_temp.o ex_tty.o ex_unix.o \
E 27
I 27
	ex_set.o ex_subr.o ex_tagio.o ex_temp.o ex_tty.o ex_unix.o \
E 27
E 5
E 4
D 14
	ex_v.o ex_vadj.o ex_vget.o ex_vmain.o ex_voperate.o \
E 14
I 14
	ex_v.o ex_vadj.o ex_vget.o ex_vmain.o ex_voper.o \
E 14
	ex_vops.o ex_vops2.o ex_vops3.o ex_vput.o ex_vwind.o \
E 36
I 36
BINDIR=		/usr/ucb
NBINDIR=	/usr/new
LIBDIR=		/usr/lib
D 45
OPTIONS=	-DCRYPT -DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX \
E 45
I 45
OPTIONS=	-DLISPCODE -DCHDIR -DUCVISUAL -DVFORK -DVMUNIX \
E 45
D 39
		-DFASTTAG -DUNIX_SBRK
E 39
I 39
D 41
		-DFASTTAG -DUNIX_SBRK -DFLOCKFILE
E 41
I 41
		-DFASTTAG -DUNIX_SBRK
E 41
E 39
CFLAGS=		-DTABS=8 -O ${OPTIONS}
LDFLAGS=	-z				# or -i or -n
LIBC=		/lib/libc.a

OBJS=	ex.o ex_addr.o ex_cmds.o ex_cmds2.o ex_cmdsub.o ex_data.o ex_extern.o \
	ex_get.o ex_io.o ex_put.o ex_re.o ex_set.o ex_subr.o ex_tagio.o \
	ex_temp.o ex_tty.o ex_unix.o ex_v.o ex_vadj.o ex_vget.o ex_vmain.o \
	ex_voper.o ex_vops.o ex_vops2.o ex_vops3.o ex_vput.o ex_vwind.o \
E 36
D 5
	printf.o strings.o
E 5
I 5
D 11
	printf.o bcopy.o horse.o strings.o
E 11
I 11
D 44
	printf.o bcopy.o strings.o
E 44
I 44
	printf.o strings.o
E 44
E 11
HDRS=	ex.h ex_argv.h ex_re.h ex_temp.h ex_tty.h ex_tune.h ex_vars.h ex_vis.h
D 36
SRC1=	ex.c ex_addr.c ex_cmds.c ex_cmds2.c ex_cmdsub.c
SRC2=	ex_data.c ex_get.c ex_io.c ex_put.c ex_re.c
D 27
SRC3=	ex_set.c ex_subr.c ex_temp.c ex_tty.c ex_unix.c
E 27
I 27
SRC3=	ex_set.c ex_subr.c ex_tagio.c ex_temp.c ex_tty.c ex_unix.c
E 27
D 14
SRC4=	ex_v.c ex_vadj.c ex_vget.c ex_vmain.c ex_voperate.c
E 14
I 14
SRC4=	ex_v.c ex_vadj.c ex_vget.c ex_vmain.c ex_voper.c
E 14
SRC5=	ex_vops.c ex_vops2.c ex_vops3.c ex_vput.c ex_vwind.c
D 9
SRC6=	printf.c bcopy.c expreserve.c exrecover.c
E 9
I 9
D 11
SRC6=	printf.c horse.c bcopy.c expreserve.c exrecover.c
E 11
I 11
SRC6=	printf.c bcopy.c expreserve.c exrecover.c
E 11
E 9
D 18
MISC=	makefile READ_ME :rofix
E 18
I 18
MISC=	makefile READ_ME rofix
E 18
VGRIND=	csh /usr/ucb/vgrind
VHDR=	"Ex Version ${VERSION}"
E 36
I 36
SRCS=	ex.c ex_addr.c ex_cmds.c ex_cmds2.c ex_cmdsub.c ex_data.c ex_get.c \
	ex_io.c ex_put.c ex_re.c ex_set.c ex_subr.c ex_tagio.c ex_temp.c \
	ex_tty.c ex_unix.c ex_v.c ex_vadj.c ex_vget.c ex_vmain.c ex_voper.c \
D 44
	ex_vops.c ex_vops2.c ex_vops3.c ex_vput.c ex_vwind.c printf.c bcopy.c
E 44
I 44
	ex_vops.c ex_vops2.c ex_vops3.c ex_vput.c ex_vwind.c printf.c
E 44
E 36
E 5

D 2
all: a.out expreserve exrecover
E 2
I 2
D 5
all:	a.out exrecover expreserve tags
E 2

E 5
D 2
a.out: ${OBJS} tags
	${CC} -i ${OBJS} -ltermlib
E 2
I 2
.c.o:
D 14
#	${MKSTR} - ex${VERSION}strings x $*.c
E 14
I 14
# ifdef VMUNIX
E 14
D 36
	${CC} -E ${CFLAGS} $*.c | ${XSTR} -c -
E 36
I 36
	${CC} -E ${CFLAGS} $*.c | xstr -c -
E 36
I 14
# else
D 36
#	${MKSTR} - ex${VERSION}strings x $*.c
#	${CC} -E ${CFLAGS} x$*.c | ${XSTR} -c -
E 36
I 36
#	mkstr - ex${VERSION}strings x $*.c
#	${CC} -E ${CFLAGS} x$*.c | xstr -c -
E 36
E 14
#	rm -f x$*.c
I 14
# endif
E 14
	${CC} ${CFLAGS} -c x.c 
	mv x.o $*.o
E 2

I 23
D 24
all:	a.out exrecover expreserve tags
E 24
I 24
D 36
all:	a.out exrecover expreserve
E 36
I 36
all:	ex exrecover expreserve
E 36
E 24

E 23
I 2
D 36
a.out: ${OBJS}
D 5
	cc -i ${OBJS} ${TERMLIB}
E 5
I 5
D 10
	cc ${LDFLAGS} ${OBJS} ${TERMLIB}
E 10
I 10
D 25
	${CC} ${LDFLAGS} ${OBJS} ${TERMLIB}
E 25
I 25
	@echo loading a.out
	@${CC} ${LDFLAGS} ${OBJS} ${TERMLIB}
E 36
I 36
ex: ${OBJS} ${LIBC}
	${CC} ${LDFLAGS} ${OBJS} -ltermcap
E 36
E 25
E 10
E 5

E 2
D 5
tags:
D 2
	../bin/csh ${CTAGS} ex.c ex_*.c
E 2
I 2
	${CTAGS} -w *.h *.c
E 5
I 5
D 23
all:	a.out exrecover expreserve tags
E 5
E 2

E 23
I 5
D 36
tags:	/tmp
	${CTAGS} -w ex.[hc] ex_*.[hc]

E 5
I 2
D 22
${OBJS}: ex_vars.h
E 22
I 22
${OBJS}: ${HDRS}
E 22

D 8
ex_vars.h:
	csh makeoptions ${CFLAGS}
E 8
I 8
D 26
# ex_vars.h:
# 	csh makeoptions ${CFLAGS}
E 26
I 26
D 34
ex_vars.h:
E 34
I 34
ex_vars.h:	ex_data.c
E 36
I 36
ex_vars.h: ex_data.c
E 36
E 34
	csh makeoptions ${CFLAGS}
E 26
E 8

I 5
D 36
bcopy.o:	bcopy.c
E 36
I 36
D 44
bcopy.o: bcopy.c
E 36
D 10
	cc -c ${CFLAGS} bcopy.c
E 10
I 10
	${CC} -c ${CFLAGS} bcopy.c
E 10

E 44
# xstr: hands off!
E 5
E 2
strings.o: strings
D 36
	${XSTR}
E 36
I 36
	xstr
E 36
D 2
	${CC} -c xs.c
	mv xs.o strings.o
E 2
I 2
	${CC} -c -S xs.c
D 18
	ed - <:rofix xs.s
E 18
I 18
	ed - <rofix xs.s
E 18
D 10
	as -o strings.o xs.s
E 10
I 10
	${AS} -o strings.o xs.s
E 10
	rm xs.s
E 2
D 36
	
exrecover: exrecover.o
D 2
	${CC} -o exrecover exrecover.o
E 2
I 2
D 19
	${CC} ${CFLAGS} exrecover.o -o exrecover
E 19
I 19
	${CC} ${CFLAGS} exrecover.o ex_extern.o -o exrecover
E 36
E 19
E 2

D 2
exrecover.o:
E 2
I 2
D 36
exrecover.o: exrecover.c
E 2
	${CC} ${CFLAGS} -c -O exrecover.c
E 36
I 36
exrecover: exrecover.o ex_extern.o
	${CC} ${CFLAGS} exrecover.o ex_extern.o -o $@
E 36

I 37
exrecover.o: exrecover.c
	${CC} ${CFLAGS} -c -O exrecover.c

E 37
D 2
expreserve: expreserve.o popen.c
	${CC} -o expreserve expreserve.o
E 2
I 2
D 36
expreserve: expreserve.o
D 19
	${CC} expreserve.o -o expreserve
E 19
I 19
D 20
	${CC} expreserve.o ex_extern.o -o expreserve
E 20
I 20
	${CC} expreserve.o -o expreserve
E 36
I 36
expreserve: expreserve.c
	${CC} ${CFLAGS} expreserve.c -o $@
I 37

expreserve.o: expreserve.c
	${CC} ${CFLAGS} -c -O expreserve.c
E 37
E 36
E 20
E 19
E 2

D 36
expreserve.o:
D 2
	${CC} ${CFLAGS} -c expreserve.c
E 2
I 2
	${CC} ${CFLAGS} -c -O expreserve.c
E 2

E 36
D 9
clean:
E 9
I 9
D 10
simpclean:
E 10
I 10
clean:
E 10
E 9
D 2
	-rm a.out exrecover expreserve ex${VERSION}strings strings errs core trace
	-rm *.o x*.[cs]
E 2
I 2
D 22
#	If we dont have ex we cant make it so dont rm ex_vars.h
E 22
I 22
#	If we dont have ex we cant make it so don't rm ex_vars.h
E 22
D 5
	-rm -f a.out exrecover expreserve ex${VERSION}strings strings core trace tags
E 5
I 5
D 36
	-rm -f a.out exrecover expreserve strings core errs trace
E 5
	-rm -f *.o x*.[cs]
E 36
I 36
	rm -f a.out exrecover expreserve strings core errs trace
	rm -f *.o x*.[cs]
E 36
I 9
D 10

clean:	simpclean
	-rm -f ${HDRS}
	-rm -f ${SRC1}
	-rm -f ${SRC2}
	-rm -f ${SRC3}
	-rm -f ${SRC4}
	-rm -f ${SRC5}
	-rm -f ${SRC6}
E 10
E 9
E 2

I 35
depend:
I 36
	mkdep ${CFLAGS} ${SRCS}
E 36

E 35
I 5
D 36
# install a new version for testing in /usr/new
E 5
D 2
install: a.out installutil
	-chmod 755 ${BINDIR}/ex
	-${BINDIR}/ex </dev/null
	-rm -f ${BINDIR}/ex ${BINDIR}/edit /${BINDIR}/vi
	cp a.out ${BINDIR}/ex
	ln ${BINDIR}/ex ${BINDIR}/edit
	ln ${BINDIR}/ex ${BINDIR}/vi
	cp ex${VERSION}strings ${LIBDIR}/ex${VERSION}strings
	chmod 1755 ${BINDIR}/ex
E 2
I 2
ninstall: a.out
D 4
	-rm -f ${NBINDIR}/ex ${NBINDIR}/vi
E 4
I 4
D 5
	-rm -f ${NBINDIR}/ex ${NBINDIR}/vi ${DESTDIR}${NBINDIR}/view
E 4
	cp a.out ${NBINDIR}/ex
E 5
I 5
	-rm -f ${DESTDIR}${NBINDIR}/ex ${DESTDIR}${NBINDIR}/vi ${DESTDIR}${NBINDIR}/view
	cp a.out ${DESTDIR}${NBINDIR}/ex
E 5
#	-cp ex${VERSION}strings ${LIBDIR}/ex${VERSION}strings
D 5
	ln ${NBINDIR}/ex ${NBINDIR}/vi
E 5
I 5
	ln ${DESTDIR}${NBINDIR}/ex ${DESTDIR}${NBINDIR}/vi
E 5
I 4
	ln ${DESTDIR}${NBINDIR}/ex ${DESTDIR}${NBINDIR}/view
E 4
D 5
	chmod 1755 ${NBINDIR}/ex
E 5
I 5
	chmod 1755 ${DESTDIR}${NBINDIR}/ex
E 5
E 2

E 36
I 5
# install in standard place (/usr/ucb)
E 5
D 2
installutil: exrecover expreserve
	cp exrecover ${LIBDIR}/ex${VERSION}recover
	cp expreserve ${LIBDIR}/ex${VERSION}preserve
E 2
I 2
install: a.out exrecover expreserve
I 14
D 22
	strip a.out
E 22
E 14
D 23
	-rm -f ${DESTDIR}${BINDIR}/ex
	-rm -f ${DESTDIR}${BINDIR}/vi
I 4
	-rm -f ${DESTDIR}${BINDIR}/view
E 4
	-rm -f ${DESTDIR}${BINDIR}/edit
	-rm -f ${DESTDIR}${BINDIR}/e
E 23
I 23
D 36
	-rm -f ${DESTDIR}/${BINDIR}/ex
	-rm -f ${DESTDIR}/${BINDIR}/vi
	-rm -f ${DESTDIR}/${BINDIR}/view
	-rm -f ${DESTDIR}/${BINDIR}/edit
	-rm -f ${DESTDIR}/${BINDIR}/e
E 23
	-rm -f ${DESTDIR}/usr/bin/ex
D 22
	cp a.out ${DESTDIR}${BINDIR}/ex
E 22
I 22
D 23
	install -s -m 1755 a.out ${DESTDIR}${BINDIR}/ex
E 23
I 23
	install -s -m 1755 a.out ${DESTDIR}/${BINDIR}/ex
E 36
I 36
	rm -f ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/${BINDIR}/vi \
		${DESTDIR}/${BINDIR}/view ${DESTDIR}/${BINDIR}/edit \
		${DESTDIR}/${BINDIR}/e ${DESTDIR}/usr/bin/ex
	install -s -o bin -g bin -m 1755 a.out ${DESTDIR}/${BINDIR}/ex
	install -s -o root -m 4755 exrecover ${DESTDIR}/${LIBDIR}/ex${VERSION}recover
	install -s -o root -m 4755 expreserve ${DESTDIR}/${LIBDIR}/ex${VERSION}preserve
E 36
E 23
E 22
#	cp ex${VERSION}strings ${DESTDIR}/${LIBDIR}/ex${VERSION}strings
D 23
	ln ${DESTDIR}${BINDIR}/ex ${DESTDIR}${BINDIR}/edit
	ln ${DESTDIR}${BINDIR}/ex ${DESTDIR}${BINDIR}/e
	ln ${DESTDIR}${BINDIR}/ex ${DESTDIR}${BINDIR}/vi
I 4
	ln ${DESTDIR}${BINDIR}/ex ${DESTDIR}${BINDIR}/view
E 4
	ln ${DESTDIR}${BINDIR}/ex ${DESTDIR}/usr/bin/ex
	chmod 1755 ${DESTDIR}${BINDIR}/ex
D 22
	cp exrecover ${DESTDIR}${LIBDIR}/ex${VERSION}recover
D 5
	cp expreserve ${DESTDIR}/${LIBDIR}/ex${VERSION}preserve
E 5
I 5
	cp expreserve ${DESTDIR}${LIBDIR}/ex${VERSION}preserve
E 5
	chmod 4755 ${DESTDIR}${LIBDIR}/ex${VERSION}recover ${DESTDIR}${LIBDIR}/ex${VERSION}preserve
E 22
I 22
	install -m 4755 exrecover ${DESTDIR}${LIBDIR}/ex${VERSION}recover
	install -m 4755 expreserve ${DESTDIR}${LIBDIR}/ex${VERSION}preserve
E 23
I 23
	ln ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/${BINDIR}/edit
	ln ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/${BINDIR}/e
	ln ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/${BINDIR}/vi
	ln ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/${BINDIR}/view
	ln ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/usr/bin/ex
D 36
	chmod 1755 ${DESTDIR}/${BINDIR}/ex
D 31
	install -m 4755 exrecover ${DESTDIR}/${LIBDIR}/ex${VERSION}recover
	install -m 4755 expreserve ${DESTDIR}/${LIBDIR}/ex${VERSION}preserve
E 31
I 31
D 32
	install -s -m 4755 exrecover ${DESTDIR}/${LIBDIR}/ex${VERSION}recover
	install -s -m 4755 expreserve ${DESTDIR}/${LIBDIR}/ex${VERSION}preserve
E 32
I 32
	install -s -o root -m 4755 exrecover ${DESTDIR}/${LIBDIR}/ex${VERSION}recover
	install -s -o root -m 4755 expreserve ${DESTDIR}/${LIBDIR}/ex${VERSION}preserve
E 36
E 32
E 31
E 23
E 22
I 5
D 43
# The following line normally fails.  This is OK.
E 5
D 14
	mkdir ${DESTDIR}/usr/preserve
E 14
I 14
D 40
	-mkdir ${DESTDIR}/usr/preserve
E 40
I 40
	-mkdir ${DESTDIR}/usr/preserve > /dev/null 2>&1
E 43
I 43
	-[ -d ${DESTDIR}/usr/preserve ] || mkdir ${DESTDIR}/usr/preserve
E 43
E 40
E 14
E 2

I 5
D 36
# move from /usr/new to /usr/ucb
newucb: a.out
D 23
	-rm -f ${DESTDIR}${BINDIR}/ex
	-rm -f ${DESTDIR}${BINDIR}/vi
	-rm -f ${DESTDIR}${BINDIR}/edit
	-rm -f ${DESTDIR}${BINDIR}/e
E 23
I 23
	-rm -f ${DESTDIR}/${BINDIR}/ex
	-rm -f ${DESTDIR}/${BINDIR}/vi
	-rm -f ${DESTDIR}/${BINDIR}/edit
	-rm -f ${DESTDIR}/${BINDIR}/e
E 23
	-rm -f ${DESTDIR}/usr/bin/ex
D 23
	mv ${DESTDIR}${NBINDIR}/ex ${DESTDIR}${NBINDIR}/ex
	-rm -f ${DESTDIR}${NBINDIR}/vi
	ln ${DESTDIR}${BINDIR}/ex ${DESTDIR}${BINDIR}/edit
	ln ${DESTDIR}${BINDIR}/ex ${DESTDIR}${BINDIR}/e
	ln ${DESTDIR}${BINDIR}/ex ${DESTDIR}${BINDIR}/vi
	ln ${DESTDIR}${BINDIR}/ex ${DESTDIR}/usr/bin/ex
	chmod 1755 ${DESTDIR}${BINDIR}/ex
E 23
I 23
	mv ${DESTDIR}/${NBINDIR}/ex ${DESTDIR}/${NBINDIR}/ex
	-rm -f ${DESTDIR}/${NBINDIR}/vi
	ln ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/${BINDIR}/edit
	ln ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/${BINDIR}/e
	ln ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/${BINDIR}/vi
	ln ${DESTDIR}/${BINDIR}/ex ${DESTDIR}/usr/bin/ex
	chmod 1755 ${DESTDIR}/${BINDIR}/ex
E 23

E 5
lint:
D 5
	lint ex.c ex_?*.c
	lint -u exrecover.c
	lint expreserve.c
E 5
I 5
	lint ${CFLAGS} ex.c ex_?*.c
	lint ${CFLAGS} -u exrecover.c
E 36
I 36
lint: FRC
	lint ${CFLAGS} ${SRCS}
	lint ${CFLAGS} exrecover.c ex_extern.c
E 36
	lint ${CFLAGS} expreserve.c
E 5

D 36
print:
D 2
	@-rm x.c xs.c >/dev/null
E 2
	@${PR} READ* BUGS
D 2
	@${PR} make*
E 2
I 2
	@${PR} makefile*
	@${PR} /etc/termcap
E 2
	@(size -l a.out ; size *.o) | ${PR} -h sizes
D 2
	@${PR} termcap
E 2
	@${PR} -h errno.h ${INCLUDE}/errno.h
D 2
	@${PR} -h pwd.h ${INCLUDE}/pwd.h
E 2
	@${PR} -h setjmp.h ${INCLUDE}/setjmp.h
	@${PR} -h sgtty.h ${INCLUDE}/sgtty.h
	@${PR} -h signal.h ${INCLUDE}/signal.h
D 2
	@${PR} -h sys/dir.h ${INCLUDE}/sys/dir.h
E 2
	@${PR} -h sys/stat.h ${INCLUDE}/sys/stat.h
	@${PR} -h sys/types.h ${INCLUDE}/sys/types.h
	@ls -ls | ${PR}
	@${CXREF} *.c | ${PR} -h XREF
	@${PR} *.h *.c
I 5
vgrind:
	tee index < /dev/null
D 13
#	${VGRIND} -h ${VHDR} ${HDRS}
#	${VGRIND} -h ${VHDR} ${SRC1}
#	${VGRIND} -h ${VHDR} ${SRC2}
E 13
I 13
	${VGRIND} -h ${VHDR} ${HDRS}
	${VGRIND} -h ${VHDR} ${SRC1}
	${VGRIND} -h ${VHDR} ${SRC2}
E 13
	${VGRIND} -h ${VHDR} ${SRC3}
	${VGRIND} -h ${VHDR} ${SRC4}
	${VGRIND} -h ${VHDR} ${SRC5}
	${VGRIND} -h ${VHDR} ${SRC6}
D 13
#	${VGRIND} -n -h ${VHDR} ${MISC}
E 13
I 13
	${VGRIND} -n -h ${VHDR} ${MISC}
E 13
	${VGRIND} -i -h ${VHDR} index
E 36
I 36
tags: FRC
	ctags ${SRCS}
	ctags -a exrecover.c
	ctags -a expreserve.c
	sort -o tags tags

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 44
ex.o: ex.c
ex.o:ex.h
ex.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
E 44
I 44
ex.o: ex.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex.o: /usr/include/signal.h /usr/include/machine/trap.h
E 44
ex.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex.o: /usr/include/sys/stat.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 44
ex.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ex.o:ex_tune.h
ex.o:ex_vars.h
ex.o:ex_argv.h
ex.o:ex_temp.h
ex.o:ex_tty.h
ex_addr.o: ex_addr.c
ex_addr.o:ex.h
ex_addr.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_addr.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_addr.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_addr.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h ex_tune.h ex_vars.h
ex.o: ex_argv.h ex_temp.h ex_tty.h
ex_addr.o: ex_addr.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_addr.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_addr.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_addr.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_addr.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_addr.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_addr.o: /usr/include/sys/ttydev.h
ex_addr.o:ex_tune.h
ex_addr.o:ex_vars.h
ex_addr.o:ex_re.h
ex_cmds.o: ex_cmds.c
ex_cmds.o:ex.h
ex_cmds.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_cmds.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_cmds.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_cmds.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_addr.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_re.h
ex_cmds.o: ex_cmds.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_cmds.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_cmds.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_cmds.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_cmds.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_cmds.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_cmds.o: /usr/include/sys/ttydev.h
ex_cmds.o:ex_tune.h
ex_cmds.o:ex_vars.h
ex_cmds.o:ex_argv.h
ex_cmds.o:ex_temp.h
ex_cmds.o:ex_tty.h
ex_cmds.o:ex_vis.h
ex_cmds2.o: ex_cmds2.c
ex_cmds2.o:ex.h
ex_cmds2.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_cmds2.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_cmds2.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_cmds2.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_cmds.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_argv.h ex_temp.h
ex_cmds.o: ex_tty.h ex_vis.h
ex_cmds2.o: ex_cmds2.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_cmds2.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_cmds2.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_cmds2.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_cmds2.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_cmds2.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_cmds2.o: /usr/include/sys/ttydev.h
ex_cmds2.o:ex_tune.h
ex_cmds2.o:ex_vars.h
ex_cmds2.o:ex_argv.h
ex_cmds2.o:ex_temp.h
ex_cmds2.o:ex_tty.h
ex_cmds2.o:ex_vis.h
ex_cmdsub.o: ex_cmdsub.c
ex_cmdsub.o:ex.h
ex_cmdsub.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_cmdsub.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_cmdsub.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_cmdsub.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_cmds2.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_argv.h ex_temp.h
ex_cmds2.o: ex_tty.h ex_vis.h
ex_cmdsub.o: ex_cmdsub.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_cmdsub.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_cmdsub.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_cmdsub.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_cmdsub.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_cmdsub.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_cmdsub.o: /usr/include/sys/ttydev.h
ex_cmdsub.o:ex_tune.h
ex_cmdsub.o:ex_vars.h
ex_cmdsub.o:ex_argv.h
ex_cmdsub.o:ex_temp.h
ex_cmdsub.o:ex_tty.h
ex_cmdsub.o:ex_vis.h
ex_data.o: ex_data.c
ex_data.o:ex.h
ex_data.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_data.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_data.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_data.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_cmdsub.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_argv.h ex_temp.h
ex_cmdsub.o: ex_tty.h ex_vis.h
ex_data.o: ex_data.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_data.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_data.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_data.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_data.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_data.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_data.o: /usr/include/sys/ttydev.h
ex_data.o:ex_tune.h
ex_data.o:ex_vars.h
ex_data.o:ex_tty.h
ex_get.o: ex_get.c
ex_get.o:ex.h
ex_get.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_get.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_get.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_get.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
ex_get.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
ex_get.o: /usr/include/sys/ttydev.h
ex_get.o:ex_tune.h
ex_get.o:ex_vars.h
ex_get.o:ex_tty.h
ex_io.o: ex_io.c
ex_io.o:ex.h
ex_io.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_io.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_io.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_io.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
ex_io.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
ex_io.o: /usr/include/sys/ttydev.h
ex_io.o:ex_tune.h
ex_io.o:ex_vars.h
ex_io.o:ex_argv.h
ex_io.o:ex_temp.h
ex_io.o:ex_tty.h
ex_io.o:ex_vis.h
ex_put.o: ex_put.c
ex_put.o:ex.h
ex_put.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_put.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_put.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_put.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
ex_put.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
ex_put.o: /usr/include/sys/ttydev.h
ex_put.o:ex_tune.h
ex_put.o:ex_vars.h
ex_put.o:ex_tty.h
ex_put.o:ex_vis.h
ex_re.o: ex_re.c
ex_re.o:ex.h
ex_re.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_re.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_re.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_re.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
ex_re.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
ex_re.o: /usr/include/sys/ttydev.h
ex_re.o:ex_tune.h
ex_re.o:ex_vars.h
ex_re.o:ex_re.h
ex_set.o: ex_set.c
ex_set.o:ex.h
ex_set.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_set.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_set.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_set.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
ex_set.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
ex_set.o: /usr/include/sys/ttydev.h
ex_set.o:ex_tune.h
ex_set.o:ex_vars.h
ex_set.o:ex_temp.h
ex_set.o:ex_tty.h
ex_subr.o: ex_subr.c
ex_subr.o:ex.h
ex_subr.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_subr.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_subr.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_subr.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_data.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h
ex_get.o: ex_get.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_get.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_get.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_get.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_get.o: /usr/include/sys/stat.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ex_get.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h ex_tune.h
ex_get.o: ex_vars.h ex_tty.h
ex_io.o: ex_io.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_io.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_io.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_io.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_io.o: /usr/include/sys/stat.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ex_io.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h ex_tune.h
ex_io.o: ex_vars.h ex_argv.h ex_temp.h ex_tty.h ex_vis.h
ex_put.o: ex_put.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_put.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_put.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_put.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_put.o: /usr/include/sys/stat.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ex_put.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h ex_tune.h
ex_put.o: ex_vars.h ex_tty.h ex_vis.h
ex_re.o: ex_re.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_re.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_re.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_re.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_re.o: /usr/include/sys/stat.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ex_re.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h ex_tune.h
ex_re.o: ex_vars.h ex_re.h
ex_set.o: ex_set.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_set.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_set.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_set.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_set.o: /usr/include/sys/stat.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ex_set.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h ex_tune.h
ex_set.o: ex_vars.h ex_temp.h ex_tty.h
ex_subr.o: ex_subr.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_subr.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_subr.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_subr.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_subr.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_subr.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_subr.o: /usr/include/sys/ttydev.h
ex_subr.o:ex_tune.h
ex_subr.o:ex_vars.h
ex_subr.o:ex_re.h
ex_subr.o:ex_tty.h
ex_subr.o:ex_vis.h
ex_tagio.o: ex_tagio.c /usr/include/sys/file.h
ex_tagio.o:ex.h
ex_tagio.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_tagio.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 44
I 44
ex_subr.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_re.h ex_tty.h
ex_subr.o: ex_vis.h
ex_tagio.o: ex_tagio.c /usr/include/sys/file.h ex.h /usr/include/sys/param.h
ex_tagio.o: /usr/include/sys/types.h /usr/include/signal.h
ex_tagio.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
E 44
ex_tagio.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_tagio.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
ex_tagio.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_tagio.o: /usr/include/sys/ttydev.h
ex_tagio.o:ex_tune.h
ex_tagio.o:ex_vars.h
ex_temp.o: ex_temp.c
ex_temp.o:ex.h
ex_temp.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_temp.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_temp.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_temp.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_tagio.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h
ex_temp.o: ex_temp.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_temp.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_temp.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_temp.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_temp.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_temp.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_temp.o: /usr/include/sys/ttydev.h
ex_temp.o:ex_tune.h
ex_temp.o:ex_vars.h
ex_temp.o:ex_temp.h
ex_temp.o:ex_vis.h
ex_temp.o:ex_tty.h
ex_tty.o: ex_tty.c
ex_tty.o:ex.h
ex_tty.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_tty.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_tty.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_tty.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
ex_tty.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
ex_tty.o: /usr/include/sys/ttydev.h
ex_tty.o:ex_tune.h
ex_tty.o:ex_vars.h
ex_tty.o:ex_tty.h
ex_unix.o: ex_unix.c
ex_unix.o:ex.h
ex_unix.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_unix.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_unix.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_unix.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_temp.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_temp.h ex_vis.h
ex_temp.o: ex_tty.h
ex_tty.o: ex_tty.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_tty.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_tty.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_tty.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_tty.o: /usr/include/sys/stat.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ex_tty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h ex_tune.h
ex_tty.o: ex_vars.h ex_tty.h
ex_unix.o: ex_unix.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_unix.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_unix.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_unix.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_unix.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_unix.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_unix.o: /usr/include/sys/ttydev.h
ex_unix.o:ex_tune.h
ex_unix.o:ex_vars.h
ex_unix.o:ex_temp.h
ex_unix.o:ex_tty.h
ex_unix.o:ex_vis.h
ex_v.o: ex_v.c
ex_v.o:ex.h
ex_v.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
E 44
I 44
ex_unix.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_temp.h ex_tty.h
ex_unix.o: ex_vis.h
ex_v.o: ex_v.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_v.o: /usr/include/signal.h /usr/include/machine/trap.h
E 44
ex_v.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_v.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_v.o: /usr/include/sys/stat.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 44
ex_v.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ex_v.o:ex_tune.h
ex_v.o:ex_vars.h
ex_v.o:ex_re.h
ex_v.o:ex_tty.h
ex_v.o:ex_vis.h
ex_vadj.o: ex_vadj.c
ex_vadj.o:ex.h
ex_vadj.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_vadj.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_vadj.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_vadj.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_v.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h ex_tune.h
ex_v.o: ex_vars.h ex_re.h ex_tty.h ex_vis.h
ex_vadj.o: ex_vadj.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_vadj.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_vadj.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_vadj.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_vadj.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_vadj.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_vadj.o: /usr/include/sys/ttydev.h
ex_vadj.o:ex_tune.h
ex_vadj.o:ex_vars.h
ex_vadj.o:ex_tty.h
ex_vadj.o:ex_vis.h
ex_vget.o: ex_vget.c
ex_vget.o:ex.h
ex_vget.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_vget.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_vget.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_vget.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_vadj.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h ex_vis.h
ex_vget.o: ex_vget.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_vget.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_vget.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_vget.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_vget.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_vget.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_vget.o: /usr/include/sys/ttydev.h
ex_vget.o:ex_tune.h
ex_vget.o:ex_vars.h
ex_vget.o:ex_tty.h
ex_vget.o:ex_vis.h
ex_vmain.o: ex_vmain.c
ex_vmain.o:ex.h
ex_vmain.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_vmain.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_vmain.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_vmain.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_vget.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h ex_vis.h
ex_vmain.o: ex_vmain.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_vmain.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_vmain.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_vmain.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_vmain.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_vmain.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_vmain.o: /usr/include/sys/ttydev.h
ex_vmain.o:ex_tune.h
ex_vmain.o:ex_vars.h
ex_vmain.o:ex_tty.h
ex_vmain.o:ex_vis.h
ex_voper.o: ex_voper.c
ex_voper.o:ex.h
ex_voper.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_voper.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_voper.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_voper.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_vmain.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h ex_vis.h
ex_voper.o: ex_voper.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_voper.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_voper.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_voper.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_voper.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_voper.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_voper.o: /usr/include/sys/ttydev.h
ex_voper.o:ex_tune.h
ex_voper.o:ex_vars.h
ex_voper.o:ex_tty.h
ex_voper.o:ex_vis.h
ex_vops.o: ex_vops.c
ex_vops.o:ex.h
ex_vops.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_vops.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_vops.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_vops.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_voper.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h ex_vis.h
ex_vops.o: ex_vops.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_vops.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_vops.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_vops.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_vops.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_vops.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_vops.o: /usr/include/sys/ttydev.h
ex_vops.o:ex_tune.h
ex_vops.o:ex_vars.h
ex_vops.o:ex_tty.h
ex_vops.o:ex_vis.h
ex_vops2.o: ex_vops2.c
ex_vops2.o:ex.h
ex_vops2.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_vops2.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_vops2.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_vops2.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_vops.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h ex_vis.h
ex_vops2.o: ex_vops2.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_vops2.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_vops2.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_vops2.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_vops2.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_vops2.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_vops2.o: /usr/include/sys/ttydev.h
ex_vops2.o:ex_tune.h
ex_vops2.o:ex_vars.h
ex_vops2.o:ex_tty.h
ex_vops2.o:ex_vis.h
ex_vops3.o: ex_vops3.c
ex_vops3.o:ex.h
ex_vops3.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_vops3.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_vops3.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_vops3.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_vops2.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h ex_vis.h
ex_vops3.o: ex_vops3.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_vops3.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_vops3.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_vops3.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_vops3.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_vops3.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_vops3.o: /usr/include/sys/ttydev.h
ex_vops3.o:ex_tune.h
ex_vops3.o:ex_vars.h
ex_vops3.o:ex_tty.h
ex_vops3.o:ex_vis.h
ex_vput.o: ex_vput.c
ex_vput.o:ex.h
ex_vput.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_vput.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_vput.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_vput.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_vops3.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h ex_vis.h
ex_vput.o: ex_vput.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_vput.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_vput.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_vput.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_vput.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_vput.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_vput.o: /usr/include/sys/ttydev.h
ex_vput.o:ex_tune.h
ex_vput.o:ex_vars.h
ex_vput.o:ex_tty.h
ex_vput.o:ex_vis.h
ex_vwind.o: ex_vwind.c
ex_vwind.o:ex.h
ex_vwind.o: /usr/include/sys/param.h /usr/include/sys/types.h
ex_vwind.o: /usr/include/signal.h /usr/include/machine/machparam.h
ex_vwind.o: /usr/include/ctype.h /usr/include/errno.h /usr/include/signal.h
ex_vwind.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
I 44
ex_vput.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h ex_vis.h
ex_vwind.o: ex_vwind.c ex.h /usr/include/sys/param.h /usr/include/sys/types.h
ex_vwind.o: /usr/include/signal.h /usr/include/machine/trap.h
ex_vwind.o: /usr/include/machine/machparam.h /usr/include/ctype.h
ex_vwind.o: /usr/include/errno.h /usr/include/signal.h /usr/include/setjmp.h
ex_vwind.o: /usr/include/sys/stat.h /usr/include/sgtty.h
E 44
ex_vwind.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 44
ex_vwind.o: /usr/include/sys/ttydev.h
ex_vwind.o:ex_tune.h
ex_vwind.o:ex_vars.h
ex_vwind.o:ex_tty.h
ex_vwind.o:ex_vis.h
E 44
I 44
ex_vwind.o: /usr/include/sys/ttydev.h ex_tune.h ex_vars.h ex_tty.h ex_vis.h
E 44
printf.o: printf.c /usr/include/varargs.h
D 44
bcopy.o: bcopy.c
E 44

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 36
I 6
D 14

D 7
ex.c : SCCS/s.ex.c ; rm -f ex.c ; sccs get ex.c 
ex.h : SCCS/s.ex.h ; rm -f ex.h ; sccs get ex.h 
ex_addr.c : SCCS/s.ex_addr.c ; rm -f ex_addr.c ; sccs get ex_addr.c 
ex_argv.h : SCCS/s.ex_argv.h ; rm -f ex_argv.h ; sccs get ex_argv.h 
ex_cmds.c : SCCS/s.ex_cmds.c ; rm -f ex_cmds.c ; sccs get ex_cmds.c 
ex_cmds2.c : SCCS/s.ex_cmds2.c ; rm -f ex_cmds2.c ; sccs get ex_cmds2.c 
ex_cmdsub.c : SCCS/s.ex_cmdsub.c ; rm -f ex_cmdsub.c ; sccs get ex_cmdsub.c 
ex_data.c : SCCS/s.ex_data.c ; rm -f ex_data.c ; sccs get ex_data.c 
ex_get.c : SCCS/s.ex_get.c ; rm -f ex_get.c ; sccs get ex_get.c 
ex_io.c : SCCS/s.ex_io.c ; rm -f ex_io.c ; sccs get ex_io.c 
ex_put.c : SCCS/s.ex_put.c ; rm -f ex_put.c ; sccs get ex_put.c 
ex_re.c : SCCS/s.ex_re.c ; rm -f ex_re.c ; sccs get ex_re.c 
ex_re.h : SCCS/s.ex_re.h ; rm -f ex_re.h ; sccs get ex_re.h 
ex_set.c : SCCS/s.ex_set.c ; rm -f ex_set.c ; sccs get ex_set.c 
ex_subr.c : SCCS/s.ex_subr.c ; rm -f ex_subr.c ; sccs get ex_subr.c 
ex_temp.c : SCCS/s.ex_temp.c ; rm -f ex_temp.c ; sccs get ex_temp.c 
ex_temp.h : SCCS/s.ex_temp.h ; rm -f ex_temp.h ; sccs get ex_temp.h 
ex_tty.c : SCCS/s.ex_tty.c ; rm -f ex_tty.c ; sccs get ex_tty.c 
ex_tty.h : SCCS/s.ex_tty.h ; rm -f ex_tty.h ; sccs get ex_tty.h 
ex_tune.h : SCCS/s.ex_tune.h ; rm -f ex_tune.h ; sccs get ex_tune.h 
E 7
I 7
ex.c: SCCS/s.ex.c ${HDRS}; rm -f ex.c; sccs get ex.c 
ex.h: SCCS/s.ex.h; rm -f ex.h; sccs get ex.h 
ex_addr.c: SCCS/s.ex_addr.c; rm -f ex_addr.c; sccs get ex_addr.c 
ex_argv.h: SCCS/s.ex_argv.h; rm -f ex_argv.h; sccs get ex_argv.h 
ex_cmds.c: SCCS/s.ex_cmds.c; rm -f ex_cmds.c; sccs get ex_cmds.c 
ex_cmds2.c: SCCS/s.ex_cmds2.c; rm -f ex_cmds2.c; sccs get ex_cmds2.c 
ex_cmdsub.c: SCCS/s.ex_cmdsub.c; rm -f ex_cmdsub.c; sccs get ex_cmdsub.c 
ex_data.c: SCCS/s.ex_data.c; rm -f ex_data.c; sccs get ex_data.c 
ex_get.c: SCCS/s.ex_get.c; rm -f ex_get.c; sccs get ex_get.c 
ex_io.c: SCCS/s.ex_io.c; rm -f ex_io.c; sccs get ex_io.c 
ex_put.c: SCCS/s.ex_put.c; rm -f ex_put.c; sccs get ex_put.c 
ex_re.c: SCCS/s.ex_re.c; rm -f ex_re.c; sccs get ex_re.c 
ex_re.h: SCCS/s.ex_re.h; rm -f ex_re.h; sccs get ex_re.h 
ex_set.c: SCCS/s.ex_set.c; rm -f ex_set.c; sccs get ex_set.c 
ex_subr.c: SCCS/s.ex_subr.c; rm -f ex_subr.c; sccs get ex_subr.c 
ex_temp.c: SCCS/s.ex_temp.c; rm -f ex_temp.c; sccs get ex_temp.c 
ex_temp.h: SCCS/s.ex_temp.h; rm -f ex_temp.h; sccs get ex_temp.h 
ex_tty.c: SCCS/s.ex_tty.c; rm -f ex_tty.c; sccs get ex_tty.c 
ex_tty.h: SCCS/s.ex_tty.h; rm -f ex_tty.h; sccs get ex_tty.h 
ex_tune.h: SCCS/s.ex_tune.h; rm -f ex_tune.h; sccs get ex_tune.h 
E 7
ex_unix.c: SCCS/s.ex_unix.c; rm -f ex_unix.c; sccs get ex_unix.c
D 7
ex_v.c : SCCS/s.ex_v.c ; rm -f ex_v.c ; sccs get ex_v.c 
ex_vadj.c : SCCS/s.ex_vadj.c ; rm -f ex_vadj.c ; sccs get ex_vadj.c 
ex_vars.h : SCCS/s.ex_vars.h ; rm -f ex_vars.h ; sccs get ex_vars.h 
ex_vget.c : SCCS/s.ex_vget.c ; rm -f ex_vget.c ; sccs get ex_vget.c 
ex_vis.h : SCCS/s.ex_vis.h ; rm -f ex_vis.h ; sccs get ex_vis.h 
ex_vmain.c : SCCS/s.ex_vmain.c ; rm -f ex_vmain.c ; sccs get ex_vmain.c 
E 7
I 7
ex_v.c: SCCS/s.ex_v.c; rm -f ex_v.c; sccs get ex_v.c 
ex_vadj.c: SCCS/s.ex_vadj.c; rm -f ex_vadj.c; sccs get ex_vadj.c 
ex_vars.h: SCCS/s.ex_vars.h; rm -f ex_vars.h; sccs get ex_vars.h 
ex_vget.c: SCCS/s.ex_vget.c; rm -f ex_vget.c; sccs get ex_vget.c 
ex_vis.h: SCCS/s.ex_vis.h; rm -f ex_vis.h; sccs get ex_vis.h 
ex_vmain.c: SCCS/s.ex_vmain.c; rm -f ex_vmain.c; sccs get ex_vmain.c 
E 7
ex_voperate.c: SCCS/s.ex_voperate.c; rm -f ex_voperate.c; sccs get ex_voperate.c
D 7
ex_vops.c : SCCS/s.ex_vops.c ; rm -f ex_vops.c ; sccs get ex_vops.c 
ex_vops2.c : SCCS/s.ex_vops2.c ; rm -f ex_vops2.c ; sccs get ex_vops2.c 
ex_vops3.c : SCCS/s.ex_vops3.c ; rm -f ex_vops3.c ; sccs get ex_vops3.c 
ex_vput.c : SCCS/s.ex_vput.c ; rm -f ex_vput.c ; sccs get ex_vput.c 
ex_vwind.c : SCCS/s.ex_vwind.c ; rm -f ex_vwind.c ; sccs get ex_vwind.c 
expreserve.c : SCCS/s.expreserve.c ; rm -f expreserve.c ; sccs get expreserve.c 
exrecover.c : SCCS/s.exrecover.c ; rm -f exrecover.c ; sccs get exrecover.c 
makeoptions : SCCS/s.makeoptions ; rm -f makeoptions ; sccs get makeoptions 
E 7
I 7
ex_vops.c: SCCS/s.ex_vops.c; rm -f ex_vops.c; sccs get ex_vops.c 
ex_vops2.c: SCCS/s.ex_vops2.c; rm -f ex_vops2.c; sccs get ex_vops2.c 
ex_vops3.c: SCCS/s.ex_vops3.c; rm -f ex_vops3.c; sccs get ex_vops3.c 
ex_vput.c: SCCS/s.ex_vput.c; rm -f ex_vput.c; sccs get ex_vput.c 
ex_vwind.c: SCCS/s.ex_vwind.c; rm -f ex_vwind.c; sccs get ex_vwind.c 
expreserve.c: SCCS/s.expreserve.c; rm -f expreserve.c; sccs get expreserve.c 
exrecover.c: SCCS/s.exrecover.c; rm -f exrecover.c; sccs get exrecover.c 
makeoptions: SCCS/s.makeoptions; rm -f makeoptions; sccs get makeoptions 
E 7
bcopy.c: SCCS/s.bcopy.c; rm -f bcopy.c; sccs get bcopy.c
D 7
printf.c : SCCS/s.printf.c ; rm -f printf.c ; sccs get printf.c 
E 7
I 7
D 11
horse.c: SCCS/s.horse.c; rm -f horse.c; sccs get horse.c
E 11
printf.c: SCCS/s.printf.c; rm -f printf.c; sccs get printf.c 
E 14
E 7
E 6
E 5
E 1
