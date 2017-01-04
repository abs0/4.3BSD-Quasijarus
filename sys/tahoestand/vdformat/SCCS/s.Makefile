h25947
s 00011/00005/00175
d D 1.8 88/07/09 11:01:12 bostic 8 7
c install approved copyright notice
e
s 00002/00004/00178
d D 1.7 88/06/07 14:32:57 karels 7 6
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00005/00002/00177
d D 1.6 88/05/31 08:46:30 karels 6 5
c add rule for libsa.a; don't delete tags; -DTAHOE is gone
e
s 00117/00105/00062
d D 1.5 87/12/04 16:08:50 bostic 5 4
c standard template
e
s 00098/00077/00069
d D 1.4 87/11/23 15:27:45 karels 4 3
c working again, I think
e
s 00004/00000/00142
d D 1.3 86/11/16 19:13:57 sam 3 2
c add install
e
s 00004/00005/00138
d D 1.2 86/11/04 21:24:02 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00143/00000/00000
d D 1.1 86/07/05 17:37:45 sam 1 0
c date and time created 86/07/05 17:37:45 by sam
e
u
U
t
T
I 1
D 5
#	%M%	%I%	%E%
E 5
#
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 8
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
#
#	%W% (Berkeley) %G%
#
I 8

E 8
E 5
I 3
DESTDIR=
E 3
D 6
COPTS=	-DSTANDALONE -DTAHOE -I../../h -I../..
E 6
I 6
COPTS=	-DSTANDALONE -I../../h -I../..
E 6
CFLAGS=	-O ${COPTS}
D 2
RELOC=	70000
E 2
I 2
RELOC=	800
E 2
LDTOPT= -T ${RELOC} -e _entry -x
D 2
SRCS=	cmd.c config.c correct.c delete.c exercise.c format.c help.c \
E 2
I 2
D 4
SRCS=	cmd.c cons.c config.c correct.c delete.c exercise.c format.c help.c \
E 2
	info.c io.c list.c maps.c proc_cmd.c profile.c relocate.c \
E 4
I 4
SRCS=	cmd.c cons.c config.c correct.c delete.c disklabel.c exercise.c help.c \
	format.c info.c io.c list.c maps.c proc_cmd.c profile.c relocate.c \
E 4
D 7
	reset.c smd.c smd_e.c start.c status.c strpbrk.c strspn.c strtok.c \
	util.c vdfmt.c verify.c
E 7
I 7
	reset.c smd.c smd_e.c start.c status.c util.c vdfmt.c verify.c
E 7
D 2
OBJS=	cmd.o config.o correct.o delete.o exercise.o format.o help.o \
E 2
I 2
D 4
OBJS=	cmd.o cons.o config.o correct.o delete.o exercise.o format.o help.o \
E 2
	info.o io.o list.o maps.o proc_cmd.o profile.o relocate.o \
E 4
I 4
OBJS=	cmd.o cons.o config.o correct.o delete.o disklabel.o exercise.o help.o \
	format.o info.o io.o list.o maps.o proc_cmd.o profile.o relocate.o \
E 4
D 7
	reset.o smd.o smd_e.o start.o status.o strpbrk.o strspn.o strtok.o \
	util.o vdfmt.o verify.o
E 7
I 7
	reset.o smd.o smd_e.o start.o status.o util.o vdfmt.o verify.o
E 7
ALL=	vdformat

all: ${ALL}

vdformat: ${OBJS} ../srt0.o ../libsa.a
D 2
	ld ${LDTOPT} ../srt0.o ${OBJS} ../libsa.a -lc
	mv a.out vdformat
E 2
I 2
	ld -o vdformat ${LDTOPT} ../srt0.o ${OBJS} ../libsa.a -lc
E 2

clean:
D 5
	rm -f ${OBJS} ${ALL} a.out core t.c errs tags Makefile.bak
E 5
I 5
D 6
	rm -f ${OBJS} ${ALL} a.out core t.c errs tags
E 6
I 6
	rm -f ${OBJS} ${ALL} a.out core t.c errs
E 6
E 5

../srt0.o: 
	@(cd ..; make srt0.o)
I 6

../libsa.a: 
	@(cd ..; make libsa.a)
E 6
I 3

install:
D 5
	install -m 644 vdformat ${DESTDIR}/stand/vdformat
E 5
I 5
	install -o bin -g bin -m 644 vdformat ${DESTDIR}/stand/vdformat
E 5
E 3

depend:
D 5
	${CC} -M ${COPTS} ${SRCS} | \
	sed -e ':loop' \
	    -e 's/\.\.\/[^ /]*\/\.\./../' \
	    -e 't loop' | \
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ex - Makefile < eddep
	rm eddep makedep
E 5
I 5
	mkdep ${COPTS} ${SRCS}
E 5

D 5
# DO NOT DELETE THIS LINE -- make depend uses it
E 5
I 5
tags:
	ctags ${SRCS}
E 5

D 5
cmd.o: cmd.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
D 4
cmd.o: ../../machine/machparam.h ../../h/signal.h /usr/include/sys/types.h
cmd.o: ../../h/buf.h ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
cmd.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
E 4
I 4
cmd.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/machparam.h
cmd.o: ../../h/buf.h ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
cmd.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
cmd.o: ./cmd.h
cons.o: cons.c ../../machine/mtpr.h ../../h/param.h /usr/include/sys/types.h
cons.o: ../../h/signal.h ../../machine/machparam.h ../../tahoe/cp.h
E 4
config.o: config.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

cmd.o: cmd.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
cmd.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/trap.h
cmd.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
cmd.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
cmd.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h cmd.h
cons.o: cons.c ../../h/../machine/mtpr.h ../../h/param.h
cons.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/trap.h
cons.o: ../../machine/machparam.h ../../h/../tahoe/cp.h
config.o: config.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
config.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
config.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
config.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
config.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
config.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
config.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
config.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
correct.o: correct.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
config.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
config.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
config.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
correct.o: correct.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
correct.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
correct.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
correct.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
correct.o: ./cmd.h
E 4
I 4
correct.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
correct.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
correct.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
correct.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
E 4
delete.o: delete.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
correct.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
correct.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
correct.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
correct.o: cmd.h
delete.o: delete.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
delete.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
delete.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
delete.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
delete.o: ./cmd.h
E 4
I 4
delete.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
delete.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
delete.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
delete.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
disklabel.o: disklabel.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
delete.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
delete.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
delete.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
delete.o: cmd.h
disklabel.o: disklabel.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
disklabel.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
disklabel.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
disklabel.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
disklabel.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
E 4
exercise.o: exercise.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
disklabel.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
disklabel.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
disklabel.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
disklabel.o: cmd.h
exercise.o: exercise.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
exercise.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
exercise.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
exercise.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
format.o: format.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
format.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
format.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
format.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
exercise.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
exercise.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
exercise.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
exercise.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
help.o: help.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
D 4
help.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
help.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
help.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
help.o: ./cmd.h
E 4
I 4
help.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
E 5
I 5
exercise.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
exercise.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
exercise.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
help.o: help.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
help.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/trap.h
E 5
help.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
help.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
D 5
help.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
format.o: format.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
help.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h cmd.h
format.o: format.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
format.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
format.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
format.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
format.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
info.o: info.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
D 4
info.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
info.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
info.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
info.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
E 5
I 5
format.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
format.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
format.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
info.o: info.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
info.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/trap.h
E 5
info.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
info.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
info.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
D 5
io.o: io.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
D 4
io.o: ../../machine/machparam.h ../../h/signal.h /usr/include/sys/types.h
io.o: ../../h/buf.h ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
io.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
E 4
I 4
io.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/machparam.h
io.o: ../../h/buf.h ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
io.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
E 4
list.o: list.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
D 4
list.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
list.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
list.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
list.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
E 5
I 5
io.o: io.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
io.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/trap.h
io.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
io.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
io.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h cmd.h
list.o: list.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
list.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/trap.h
E 5
list.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
list.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
list.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
D 5
maps.o: maps.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
D 4
maps.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
maps.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
maps.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
maps.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
E 5
I 5
maps.o: maps.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
maps.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/trap.h
E 5
maps.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
maps.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
maps.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
D 5
proc_cmd.o: proc_cmd.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
proc_cmd.o: proc_cmd.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
proc_cmd.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
proc_cmd.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
proc_cmd.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
proc_cmd.o: ./cmd.h
E 4
I 4
proc_cmd.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
proc_cmd.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
proc_cmd.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
proc_cmd.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
E 4
profile.o: profile.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
proc_cmd.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
proc_cmd.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
proc_cmd.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
proc_cmd.o: cmd.h
profile.o: profile.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
profile.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
profile.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
profile.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
profile.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
profile.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
profile.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
profile.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
relocate.o: relocate.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
profile.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
profile.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
profile.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
relocate.o: relocate.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
relocate.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
relocate.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
relocate.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
relocate.o: ./cmd.h
E 4
I 4
relocate.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
relocate.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
relocate.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
relocate.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
E 4
reset.o: reset.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
relocate.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
relocate.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
relocate.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
relocate.o: cmd.h
reset.o: reset.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
reset.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
reset.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
reset.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
reset.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
reset.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
reset.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
reset.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
smd.o: smd.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
D 4
smd.o: ../../machine/machparam.h ../../h/signal.h /usr/include/sys/types.h
smd.o: ../../h/buf.h ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
smd.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
smd.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/machparam.h
smd.o: ../../h/buf.h ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
smd.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
smd_e.o: smd_e.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
reset.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
reset.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
reset.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
smd.o: smd.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
smd.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/trap.h
smd.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
smd.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
smd.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
smd_e.o: smd_e.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
smd_e.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
smd_e.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
smd_e.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
smd_e.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
smd_e.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
smd_e.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
smd_e.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
start.o: start.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
smd_e.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
smd_e.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
smd_e.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
start.o: start.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
start.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
start.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
start.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
start.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
start.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
start.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
start.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
status.o: status.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
start.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
start.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
start.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
status.o: status.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
status.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
status.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
status.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
status.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
status.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
status.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
status.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 5
I 5
status.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
status.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
status.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 5
E 4
strpbrk.o: strpbrk.c
strspn.o: strspn.c
strtok.o: strtok.c
D 5
util.o: util.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
D 4
util.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
util.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
util.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
util.o: ./cmd.h
E 4
I 4
util.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
E 5
I 5
util.o: util.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h ../../h/param.h
util.o: /usr/include/sys/types.h ../../h/signal.h ../../machine/trap.h
E 5
util.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
util.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
D 5
util.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h ./cmd.h
E 4
vdfmt.o: vdfmt.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
util.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h cmd.h
vdfmt.o: vdfmt.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
vdfmt.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
vdfmt.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
vdfmt.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
vdfmt.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
vdfmt.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
vdfmt.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
vdfmt.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
verify.o: verify.c ./vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
I 5
vdfmt.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
vdfmt.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
vdfmt.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
verify.o: verify.c vdfmt.h /usr/include/setjmp.h ../../tahoe/mtpr.h
E 5
D 4
verify.o: ../../h/param.h ../../machine/machparam.h ../../h/signal.h
verify.o: /usr/include/sys/types.h ../../h/buf.h ../../h/inode.h ../../h/fs.h
verify.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 4
I 4
verify.o: ../../h/param.h /usr/include/sys/types.h ../../h/signal.h
D 5
verify.o: ../../machine/machparam.h ../../h/buf.h ../../h/disklabel.h
verify.o: ../../h/inode.h ../../h/fs.h ../../tahoevba/vbaparam.h
verify.o: ../../tahoevba/vdreg.h ../../tahoe/cp.h
E 5
I 5
verify.o: ../../machine/trap.h ../../machine/machparam.h ../../h/buf.h
verify.o: ../../h/disklabel.h ../../h/inode.h ../../h/fs.h
verify.o: ../../tahoevba/vbaparam.h ../../tahoevba/vdreg.h ../../tahoe/cp.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 4
E 1
