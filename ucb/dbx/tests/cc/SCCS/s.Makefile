h09441
s 00009/00005/00095
d D 5.2 87/07/27 17:25:08 mckusick 2 1
c reorganized for CCI
e
s 00100/00000/00000
d D 5.1 86/10/14 22:11:13 mckusick 1 0
c date and time created 86/10/14 22:11:13 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
# Makefile for testing dbx.
#

.SUFFIXES:

.SUFFIXES: .c .h .s .o .x .t .in .tst .out

#
# Suffix conventions:
#
#	.c	C source module
#	.h	C definitions file
#	.s	assembly code file
#	.o	object file
#	.x	executable file
#	.t	dummy file represented last time tested
#	.in	input for testing
#	.tst	test output
#	.out	expected output
#

CC = cc

TESTDBX = ../../tdbx
TESTS = \
D 2
    aliases.t args.t arrays.t bitfields.t call.t dump.t enum.t float.t \
    loophole.t nested.t own.t reg.t \
E 2
I 2
    aliases.t args.t arrays.t bitfields.t \
    dump.t enum.t float.t loophole.t nested.t own.t reg.t \
E 2
    same.t signal.t sleep.t stkcmds.t strings.t struct.t user.t ushort.t
I 2
#   call.t - deleted as it crashes the CCI microcode.
E 2

.c.x:
	${CC} -g $*.c -o $*.x

.c.o:
	${CC} -c -g $*.c

.in.tst:
	@rm -f $*.tst
	../runtest ${TESTDBX} $* > $*.tst

.x.t:
	@echo "    $*"
	@rm -f tmp
	@../runtest ${TESTDBX} $* > tmp
D 2
	@../check tmp $*.out
E 2
I 2
	@../check tmp out/out.`machine`/$*.out
E 2
	@rm -f tmp
	@rm -f $*.t
	@touch $*.t

passed: beforemsg ${TESTS}
	@echo "passed C tests"

beforemsg:
	@echo ""
	@echo "C tests:"

strings.x: strings.c
	cc -g -R strings.c -o strings.x

I 2
clean:
	rm -f *.x *.t *.o *.tst strings.core

E 2
aliases.t: aliases.x ${TESTDBX}
args.t: args.x ${TESTDBX}
arrays.t: arrays.x ${TESTDBX}
bitfields.t: bitfields.x ${TESTDBX}
call.t: call.x ${TESTDBX}
dump.t: dump.x ${TESTDBX}
enum.t: enum.x ${TESTDBX}
float.t: float.x ${TESTDBX}
loophole.t: loophole.x ${TESTDBX}
nested.t: nested.x ${TESTDBX}
own.t: own.x ${TESTDBX}
reg.t: reg.x ${TESTDBX}
same.t: same.x ${TESTDBX}
signal.t: signal.x ${TESTDBX}
sleep.t: sleep.x ${TESTDBX}
stkcmds.t: stkcmds.x ${TESTDBX}
struct.t: struct.x ${TESTDBX}
user.t: user.x ${TESTDBX}
ushort.t: ushort.x ${TESTDBX}

strings.t: strings.x strings.core ${TESTDBX}
	@echo "    $*"
	@rm -f tmp
	@${TESTDBX} $*.x $*.core < $*.in | tail +3 > tmp
D 2
	@../check tmp $*.out
E 2
I 2
	@../check tmp out/out.`machine`/$*.out
E 2
	@rm -f tmp
	@rm -f $*.t
	@touch $*.t

D 2
strings.core:
E 2
I 2
strings.core: strings.x
E 2
	-csh -f -c "limit coredumpsize 6m >& /dev/null; strings.x"
	mv core strings.core

aliases.x: arrays.x
	ln -s arrays.x aliases.x
E 1
