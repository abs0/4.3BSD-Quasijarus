h12796
s 00204/00028/00015
d D 5.3 87/06/02 22:48:14 bostic 3 2
c new template
e
s 00002/00000/00041
d D 5.2 87/05/31 20:30:25 bostic 2 1
c added depend label
e
s 00041/00000/00000
d D 5.1 86/02/25 16:04:38 sam 1 0
c date and time created 86/02/25 16:04:38 by sam
e
u
U
t
T
I 1
D 3
#	%M%	%I%	%E%
E 3
#
D 3
DESTDIR=
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 3
CFLAGS=	-O
I 3
LIBC=	/lib/libc.a
E 3
SRCS=	access.c command.c expr.c format.c input.c main.c message.c \
	opset.c optab.c output.c pcs.c print.c runpcs.c setup.c sym.c
OBJS=	access.o command.o expr.o format.o input.o main.o message.o \
	opset.o optab.o output.o pcs.o print.o runpcs.o setup.o sym.o

D 3
adb:	${OBJS}
	${CC} -o adb ${LDFLAGS} ${OBJS}
E 3
I 3
all: adb
E 3

D 3
defs.h:		mac.h mode.h
mode.h:		machine.h
E 3
I 3
adb:	${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS}
E 3

D 3
access.o:	defs.h access.c
command.o:	defs.h command.c
expr.o:		defs.h expr.c
format.o:	defs.h format.c
input.o:	defs.h input.c
main.o:		defs.h main.c
message.o:	mac.h mode.h message.c
E 3
I 3
message.o:
E 3
	${CC} -R ${CFLAGS} -c message.c
D 3
opset.o:	defs.h optab.h opset.c
optab.o:	defs.h optab.h instrs optab.c
E 3
I 3

optab.o:
E 3
	${CC} -R ${CFLAGS} -c optab.c
D 3
output.o:	defs.h output.c
pcs.o:		defs.h pcs.c
print.o:	defs.h print.c
runpcs.o:	defs.h runpcs.c
setup.o:	defs.h setup.c
sym.o:		defs.h sym.c
E 3

D 3
clean:
	rm -f adb ${OBJS} core t.c errs
E 3
I 3
clean: FRC
	rm -f ${OBJS} core adb
E 3

I 2
D 3
depend:
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 3

E 2
D 3
lint:
	lint -bx ${SRCS}
E 3
I 3
install: FRC
	install -s -o bin -g bin -m 755 adb ${DESTDIR}/bin/adb
E 3

D 3
install: adb
	install -s adb ${DESTDIR}/bin/adb
E 3
I 3
lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

access.o: access.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
access.o: /usr/include/signal.h /usr/include/machine/machparam.h
access.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
access.o: /usr/include/machine/pte.h /usr/include/sys/user.h
access.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
access.o: /usr/include/sys/time.h /usr/include/time.h
access.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
access.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
access.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
access.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
access.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
access.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
command.o: command.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
command.o: /usr/include/signal.h /usr/include/machine/machparam.h
command.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
command.o: /usr/include/machine/pte.h /usr/include/sys/user.h
command.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
command.o: /usr/include/sys/time.h /usr/include/time.h
command.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
command.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
command.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
command.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
command.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
command.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
expr.o: expr.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
expr.o: /usr/include/signal.h /usr/include/machine/machparam.h
expr.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
expr.o: /usr/include/machine/pte.h /usr/include/sys/user.h
expr.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
expr.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/sys/resource.h
expr.o: /usr/include/sys/namei.h /usr/include/sys/uio.h /usr/include/errno.h
expr.o: /usr/include/ctype.h /usr/include/a.out.h /usr/include/sys/exec.h mac.h
expr.o: mode.h machine.h /usr/include/sys/vm.h /usr/include/sys/vmparam.h
expr.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
expr.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
format.o: format.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
format.o: /usr/include/signal.h /usr/include/machine/machparam.h
format.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
format.o: /usr/include/machine/pte.h /usr/include/sys/user.h
format.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
format.o: /usr/include/sys/time.h /usr/include/time.h
format.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
format.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
format.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
format.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
format.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
format.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
input.o: input.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
input.o: /usr/include/signal.h /usr/include/machine/machparam.h
input.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
input.o: /usr/include/machine/pte.h /usr/include/sys/user.h
input.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
input.o: /usr/include/sys/time.h /usr/include/time.h
input.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
input.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
input.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
input.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
input.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
input.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
main.o: main.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
main.o: /usr/include/signal.h /usr/include/machine/machparam.h
main.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
main.o: /usr/include/machine/pte.h /usr/include/sys/user.h
main.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
main.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/sys/resource.h
main.o: /usr/include/sys/namei.h /usr/include/sys/uio.h /usr/include/errno.h
main.o: /usr/include/ctype.h /usr/include/a.out.h /usr/include/sys/exec.h mac.h
main.o: mode.h machine.h /usr/include/sys/vm.h /usr/include/sys/vmparam.h
main.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
main.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
message.o: message.c mac.h mode.h machine.h /usr/include/sys/vm.h
message.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
message.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
message.o: /usr/include/sys/vmsystm.h
opset.o: opset.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
opset.o: /usr/include/signal.h /usr/include/machine/machparam.h
opset.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
opset.o: /usr/include/machine/pte.h /usr/include/sys/user.h
opset.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
opset.o: /usr/include/sys/time.h /usr/include/time.h
opset.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
opset.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
opset.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
opset.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
opset.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
opset.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h optab.h
optab.o: optab.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
optab.o: /usr/include/signal.h /usr/include/machine/machparam.h
optab.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
optab.o: /usr/include/machine/pte.h /usr/include/sys/user.h
optab.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
optab.o: /usr/include/sys/time.h /usr/include/time.h
optab.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
optab.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
optab.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
optab.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
optab.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
optab.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h optab.h
optab.o: instrs
output.o: output.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
output.o: /usr/include/signal.h /usr/include/machine/machparam.h
output.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
output.o: /usr/include/machine/pte.h /usr/include/sys/user.h
output.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
output.o: /usr/include/sys/time.h /usr/include/time.h
output.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
output.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
output.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
output.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
output.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
output.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
pcs.o: pcs.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
pcs.o: /usr/include/signal.h /usr/include/machine/machparam.h
pcs.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
pcs.o: /usr/include/machine/pte.h /usr/include/sys/user.h
pcs.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
pcs.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/sys/resource.h
pcs.o: /usr/include/sys/namei.h /usr/include/sys/uio.h /usr/include/errno.h
pcs.o: /usr/include/ctype.h /usr/include/a.out.h /usr/include/sys/exec.h mac.h
pcs.o: mode.h machine.h /usr/include/sys/vm.h /usr/include/sys/vmparam.h
pcs.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
pcs.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
print.o: print.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
print.o: /usr/include/signal.h /usr/include/machine/machparam.h
print.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
print.o: /usr/include/machine/pte.h /usr/include/sys/user.h
print.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
print.o: /usr/include/sys/time.h /usr/include/time.h
print.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
print.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
print.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
print.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
print.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
print.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
runpcs.o: runpcs.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
runpcs.o: /usr/include/signal.h /usr/include/machine/machparam.h
runpcs.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
runpcs.o: /usr/include/machine/pte.h /usr/include/sys/user.h
runpcs.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
runpcs.o: /usr/include/sys/time.h /usr/include/time.h
runpcs.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
runpcs.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
runpcs.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
runpcs.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
runpcs.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
runpcs.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
setup.o: setup.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
setup.o: /usr/include/signal.h /usr/include/machine/machparam.h
setup.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
setup.o: /usr/include/machine/pte.h /usr/include/sys/user.h
setup.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
setup.o: /usr/include/sys/time.h /usr/include/time.h
setup.o: /usr/include/sys/resource.h /usr/include/sys/namei.h
setup.o: /usr/include/sys/uio.h /usr/include/errno.h /usr/include/ctype.h
setup.o: /usr/include/a.out.h /usr/include/sys/exec.h mac.h mode.h machine.h
setup.o: /usr/include/sys/vm.h /usr/include/sys/vmparam.h
setup.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
setup.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
setup.o: /usr/include/frame.h /usr/include/ctype.h /usr/include/sys/stat.h
setup.o: /usr/include/sys/file.h /usr/include/machine/rpb.h
sym.o: sym.c defs.h /usr/include/sys/param.h /usr/include/sys/types.h
sym.o: /usr/include/signal.h /usr/include/machine/machparam.h
sym.o: /usr/include/sys/dir.h /usr/include/machine/psl.h
sym.o: /usr/include/machine/pte.h /usr/include/sys/user.h
sym.o: /usr/include/machine/pcb.h /usr/include/sys/dmap.h
sym.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/sys/resource.h
sym.o: /usr/include/sys/namei.h /usr/include/sys/uio.h /usr/include/errno.h
sym.o: /usr/include/ctype.h /usr/include/a.out.h /usr/include/sys/exec.h mac.h
sym.o: mode.h machine.h /usr/include/sys/vm.h /usr/include/sys/vmparam.h
sym.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
sym.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h head.h
sym.o: /usr/include/stab.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1
