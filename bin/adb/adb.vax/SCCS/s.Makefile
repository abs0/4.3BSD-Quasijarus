h02949
s 00002/00188/00051
d D 5.2 00/08/29 22:22:44 msokolov 10 9
c remove instrs.adb on make clean, it's a generated file
e
s 00225/00040/00014
d D 5.1 87/06/05 12:31:36 bostic 9 6
c new template
e
s 00225/00040/00014
d R 5.1 87/06/03 10:17:56 bostic 8 6
c new template
e
s 00225/00040/00014
d R 4.7 87/06/02 22:55:36 bostic 7 6
c new template
e
s 00002/00000/00052
d D 4.6 87/05/31 20:30:01 bostic 6 5
c added depend label
e
s 00001/00001/00051
d D 4.5 87/05/10 14:55:41 mckusick 5 4
c use proper path
e
s 00002/00002/00050
d D 4.4 86/06/07 03:03:58 lepreau 4 3
c clean better; relative path to "as" dir
e
s 00014/00005/00038
d D 4.3 82/10/27 14:38:02 rrh 3 2
c Complete reworking of opset.c to make its operation understandable
c Allow 2 byte opcodes for extended VAX architecture (G and H numbers).
c Opset.c is shared between adb and sdb.  Use a common instruction data base
c with adb, sdb, as and c2
e
s 00001/00001/00042
d D 4.2 81/05/14 20:08:50 root 2 1
c non-working version
e
s 00043/00000/00000
d D 4.1 81/05/14 15:24:03 root 1 0
c date and time created 81/05/14 15:24:03 by root
e
u
U
t
T
I 1
#
D 9
#	%M%	%I%	%E%
E 9
I 9
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 9
#
D 9
DESTDIR= 
D 3
CFLAGS=	-O -w
E 3
I 3
DFLAGS = -DADB
E 9
I 9
#	%W%	(Berkeley)	%G%
#
LIBC=	/lib/libc.a
DFLAGS=	-DADB
E 9
CFLAGS=	-O -w ${DFLAGS}
E 3
D 9
CFILES= access.c command.c expr.c format.c input.c main.c message.c \
E 9
I 9
#	path to the directory containing as
AS =	../../as/as.vax
SRCS=	access.c command.c expr.c format.c input.c main.c message.c \
E 9
	opset.c optab.c output.c pcs.c print.c runpcs.c setup.c sym.c
D 9
OFILES= access.o command.o expr.o format.o input.o main.o message.o \
E 9
I 9
OBJS=	access.o command.o expr.o format.o input.o main.o message.o \
E 9
	opset.o optab.o output.o pcs.o print.o runpcs.o setup.o sym.o

I 3
D 9
#
#	path to the directory containing as
#
D 4
AS =	/usr/src/bin/as
E 4
I 4
D 5
AS =	../as
E 5
I 5
AS =	../../as/as.vax
E 9
I 9
all: adb
E 9
E 5
E 4

E 3
D 9
adb:	${OFILES}
	${CC} -o adb ${OFILES}
E 9
I 9
adb:	${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS}
E 9

D 9
defs.h:		mac.h mode.h
mode.h:		machine.h

access.o:	defs.h access.c
command.o:	defs.h command.c
expr.o:		defs.h expr.c
format.o:	defs.h format.c
input.o:	defs.h input.c
main.o:		defs.h main.c
message.o:	mac.h mode.h message.c
E 9
I 9
message.o:
E 9
	${CC} -c -R message.c
D 3
opset.o:	defs.h opset.c
optab.o:	defs.h optab.c
D 2
	${CC} -S -R  optab.c
E 2
I 2
	${CC} -c -R  optab.c
E 2
output.o:	defs.h output.c
E 3
D 9
pcs.o:		defs.h pcs.c
print.o:	defs.h print.c
runpcs.o:	defs.h runpcs.c
setup.o:	defs.h setup.c
sym.o:		defs.h sym.c
E 9
I 3

D 9
opset.o:	defs.h opset.c
	${CC} ${CFLAGS} -c    -I. -I$(AS) opset.c
optab.o:	defs.h optab.c instrs.adb
	${CC} ${CFLAGS} -c -R -I. -I$(AS) optab.c
instrs.adb: $(AS)/instrs
	(echo FLAVOR ADB; cat $(AS)/instrs) | awk -f $(AS)/instrs > instrs.adb
E 9
I 9
opset.o:
	${CC} ${CFLAGS} -c -I. -I${AS} opset.c
E 9
E 3

D 9
install:
	install -s adb ${DESTDIR}/bin
E 9
I 9
optab.o: instrs.adb
	${CC} ${CFLAGS} -c -R -I. -I${AS} optab.c
E 9

D 9
clean:
D 4
	rm -f adb ${OFILES}
E 4
I 4
	rm -f adb instrs.adb errs ${OFILES}
E 9
I 9
instrs.adb: ${AS}/instrs
	(echo FLAVOR ADB; cat ${AS}/instrs) | awk -f ${AS}/instrs > instrs.adb
E 9
E 4

I 6
D 9
depend:
E 9
I 9
clean: FRC
D 10
	rm -f ${OBJS} core adb
E 10
I 10
	rm -f ${OBJS} core adb instrs.adb
E 10
E 9

E 6
D 9
print:
	@ls -l | pr
	@pr -f Makefile *.h ${CFILES}
E 9
I 9
D 10
depend: FRC
E 10
I 10
depend: instrs.adb FRC
E 10
	mkdep ${CFLAGS} -I. -I${AS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 adb ${DESTDIR}/bin/adb

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
D 10

access.o: access.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
access.o: /usr/include/sys/param.h /usr/include/sys/types.h
access.o: /usr/include/signal.h /usr/include/machine/machparam.h
access.o: /usr/include/sys/dir.h /usr/include/sys/user.h
access.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
access.o: /usr/include/sys/time.h /usr/include/time.h
access.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
access.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
access.o: /usr/include/a.out.h /usr/include/sys/exec.h
access.o: /usr/include/sys/ptrace.h mac.h mode.h machine.h
access.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
access.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
access.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
command.o: command.c defs.h /usr/include/machine/psl.h
command.o: /usr/include/machine/pte.h /usr/include/sys/param.h
command.o: /usr/include/sys/types.h /usr/include/signal.h
command.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
command.o: /usr/include/sys/user.h /usr/include/machine/pcb.h
command.o: /usr/include/sys/dmap.h /usr/include/sys/time.h /usr/include/time.h
command.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
command.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
command.o: /usr/include/a.out.h /usr/include/sys/exec.h
command.o: /usr/include/sys/ptrace.h mac.h mode.h machine.h
command.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
command.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
command.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
expr.o: expr.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
expr.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
expr.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
expr.o: /usr/include/sys/user.h /usr/include/machine/pcb.h
expr.o: /usr/include/sys/dmap.h /usr/include/sys/time.h /usr/include/time.h
expr.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
expr.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
expr.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/sys/ptrace.h
expr.o: mac.h mode.h machine.h /usr/include/sys/vm.h /usr/include/sys/vmparam.h
expr.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
expr.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
format.o: format.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
format.o: /usr/include/sys/param.h /usr/include/sys/types.h
format.o: /usr/include/signal.h /usr/include/machine/machparam.h
format.o: /usr/include/sys/dir.h /usr/include/sys/user.h
format.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
format.o: /usr/include/sys/time.h /usr/include/time.h
format.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
format.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
format.o: /usr/include/a.out.h /usr/include/sys/exec.h
format.o: /usr/include/sys/ptrace.h mac.h mode.h machine.h
format.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
format.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
format.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
input.o: input.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
input.o: /usr/include/sys/param.h /usr/include/sys/types.h
input.o: /usr/include/signal.h /usr/include/machine/machparam.h
input.o: /usr/include/sys/dir.h /usr/include/sys/user.h
input.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
input.o: /usr/include/sys/time.h /usr/include/time.h
input.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
input.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
input.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/sys/ptrace.h
input.o: mac.h mode.h machine.h /usr/include/sys/vm.h
input.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
input.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
input.o: /usr/include/sys/vmsystm.h head.h
main.o: main.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
main.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
main.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
main.o: /usr/include/sys/user.h /usr/include/machine/pcb.h
main.o: /usr/include/sys/dmap.h /usr/include/sys/time.h /usr/include/time.h
main.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
main.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
main.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/sys/ptrace.h
main.o: mac.h mode.h machine.h /usr/include/sys/vm.h /usr/include/sys/vmparam.h
main.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
main.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
message.o: message.c mac.h mode.h machine.h /usr/include/sys/vm.h
message.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
message.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
message.o: /usr/include/sys/vmsystm.h
opset.o: opset.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
opset.o: /usr/include/sys/param.h /usr/include/sys/types.h
opset.o: /usr/include/signal.h /usr/include/machine/machparam.h
opset.o: /usr/include/sys/dir.h /usr/include/sys/user.h
opset.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
opset.o: /usr/include/sys/time.h /usr/include/time.h
opset.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
opset.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
opset.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/sys/ptrace.h
opset.o: mac.h mode.h machine.h /usr/include/sys/vm.h
opset.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
opset.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
opset.o: /usr/include/sys/vmsystm.h head.h ../../as/as.vax/instrs.h
opset.o: ../../as/as.vax/asnumber.h
optab.o: optab.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
optab.o: /usr/include/sys/param.h /usr/include/sys/types.h
optab.o: /usr/include/signal.h /usr/include/machine/machparam.h
optab.o: /usr/include/sys/dir.h /usr/include/sys/user.h
optab.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
optab.o: /usr/include/sys/time.h /usr/include/time.h
optab.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
optab.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
optab.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/sys/ptrace.h
optab.o: mac.h mode.h machine.h /usr/include/sys/vm.h
optab.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
optab.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
optab.o: /usr/include/sys/vmsystm.h head.h ../../as/as.vax/instrs.h instrs.adb
optab.o: ../../as/as.vax/assizetab.c
output.o: output.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
output.o: /usr/include/sys/param.h /usr/include/sys/types.h
output.o: /usr/include/signal.h /usr/include/machine/machparam.h
output.o: /usr/include/sys/dir.h /usr/include/sys/user.h
output.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
output.o: /usr/include/sys/time.h /usr/include/time.h
output.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
output.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
output.o: /usr/include/a.out.h /usr/include/sys/exec.h
output.o: /usr/include/sys/ptrace.h mac.h mode.h machine.h
output.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
output.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
output.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
output.o: /usr/include/stdio.h
pcs.o: pcs.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
pcs.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
pcs.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
pcs.o: /usr/include/sys/user.h /usr/include/machine/pcb.h
pcs.o: /usr/include/sys/dmap.h /usr/include/sys/time.h /usr/include/time.h
pcs.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
pcs.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
pcs.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/sys/ptrace.h
pcs.o: mac.h mode.h machine.h /usr/include/sys/vm.h /usr/include/sys/vmparam.h
pcs.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
pcs.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
print.o: print.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
print.o: /usr/include/sys/param.h /usr/include/sys/types.h
print.o: /usr/include/signal.h /usr/include/machine/machparam.h
print.o: /usr/include/sys/dir.h /usr/include/sys/user.h
print.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
print.o: /usr/include/sys/time.h /usr/include/time.h
print.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
print.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
print.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/sys/ptrace.h
print.o: mac.h mode.h machine.h /usr/include/sys/vm.h
print.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
print.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
print.o: /usr/include/sys/vmsystm.h head.h
runpcs.o: runpcs.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
runpcs.o: /usr/include/sys/param.h /usr/include/sys/types.h
runpcs.o: /usr/include/signal.h /usr/include/machine/machparam.h
runpcs.o: /usr/include/sys/dir.h /usr/include/sys/user.h
runpcs.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
runpcs.o: /usr/include/sys/time.h /usr/include/time.h
runpcs.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
runpcs.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
runpcs.o: /usr/include/a.out.h /usr/include/sys/exec.h
runpcs.o: /usr/include/sys/ptrace.h mac.h mode.h machine.h
runpcs.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
runpcs.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
runpcs.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
setup.o: setup.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
setup.o: /usr/include/sys/param.h /usr/include/sys/types.h
setup.o: /usr/include/signal.h /usr/include/machine/machparam.h
setup.o: /usr/include/sys/dir.h /usr/include/sys/user.h
setup.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
setup.o: /usr/include/sys/time.h /usr/include/time.h
setup.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
setup.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
setup.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/sys/ptrace.h
setup.o: mac.h mode.h machine.h /usr/include/sys/vm.h
setup.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
setup.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
setup.o: /usr/include/sys/vmsystm.h head.h /usr/include/frame.h
setup.o: /usr/include/ctype.h /usr/include/sys/stat.h /usr/include/sys/file.h
sym.o: sym.c defs.h /usr/include/machine/psl.h /usr/include/machine/pte.h
sym.o: /usr/include/sys/param.h /usr/include/sys/types.h /usr/include/signal.h
sym.o: /usr/include/machine/machparam.h /usr/include/sys/dir.h
sym.o: /usr/include/sys/user.h /usr/include/machine/pcb.h
sym.o: /usr/include/sys/dmap.h /usr/include/sys/time.h /usr/include/time.h
sym.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
sym.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
sym.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/sys/ptrace.h
sym.o: mac.h mode.h machine.h /usr/include/sys/vm.h /usr/include/sys/vmparam.h
sym.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
sym.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
sym.o: /usr/include/stab.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 10
E 9
E 1
