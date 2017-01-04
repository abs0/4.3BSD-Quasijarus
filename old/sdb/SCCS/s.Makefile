h53251
s 00028/00010/00054
d D 4.4 82/10/27 15:30:03 rrh 4 3
c use opset/optab in adb
e
s 00009/00002/00055
d D 4.3 82/02/14 15:57:42 root 3 2
c (by rrh) Upgraded to use files opset.c and optab.c in
c adb's directory.
e
s 00001/00001/00056
d D 4.2 81/07/08 10:18:02 root 2 1
c fixes per ker
e
s 00057/00000/00000
d D 4.1 80/10/09 23:58:44 bill 1 0
c date and time created 80/10/09 23:58:44 by bill
e
u
U
t
T
I 1
#
#	sdb	%M%	%I%	%G%
#
# Conditional compilation flags:
I 3
#	SDB	this is sdb
E 3
#	STD - Distribution systems UNIX/32V, VM/UNIX 2.n
#	VMUNIX - virtual memory system - keep namelist in VM.
#	VFORK - Use vfork call of VM/UNIX Berkeley version
#	FLEXNAMES - New a.out format with string table (VMUNIX Version 4)
#
# The files old.c and old.h contain routines and definitions peculiar
# to old versions of the system.
#
D 2
CFLAGS=	-R -DVMUNIX -DVFORK -DFLEXNAMES -g
E 2
I 2
D 3
CFLAGS=	-R -DVMUNIX -DVFORK -DFLEXNAMES
E 3
I 3
CFLAGS=	-R -DSDB -DVMUNIX -DVFORK -DFLEXNAMES
E 3
E 2

I 4
ADB = /usr/src/bin/adb
AS = /usr/src/bin/as
SHARE = $(ADB)

E 4
SRCS=	access.c decode.c display.c docomm.c fio.c main.c message.c \
D 3
	old.c opset.c optab.c pcs.c prvar.c re.c runpcs.c \
E 3
I 3
D 4
	old.c ../adb/opset.c ../adb/optab.c pcs.c prvar.c re.c runpcs.c \
E 3
	setup.c sub.c symt.c udef.c version.c xeq.c
E 4
I 4
	old.c $(SHARE)/opset.c $(SHARE)/optab.c pcs.c prvar.c re.c runpcs.c \
	setup.c sub.c symt.c udef.c version.c xeq.c reginit.c
E 4
OBJS=	access.o decode.o display.o docomm.o fio.o main.o message.o \
	old.o opset.o optab.o pcs.o prvar.o re.o runpcs.o \
D 4
	setup.o sub.o symt.o udef.o version.o xeq.o
E 4
I 4
	setup.o sub.o symt.o udef.o version.o xeq.o reginit.o
E 4
HDRS=	cdefs.h defs.h head.h mac.h machine.h mode.h old.h

sdb: sources ${OBJS}
	cc -o sdb *.o

I 3
D 4
opset.o: ../adb/opset.c
	$(CC) $(CFLAGS) -c ../adb/opset.c
optab.o: ../adb/optab.c ../adb/instrs.adb
	$(CC) $(CFLAGS) -c ../adb/optab.c
../adb/instrs.adb: ../as/instrs
	(cd ../adb; make instrs.adb)
E 4
I 4
#
#	An apparent bug in /lib/cpp prevents us from compiling
#	directly from $(SHARE)/{opset,optab}.c; the wrong
#	version of head.h is included (cpp gets $(SHARE)/head.h;
#	we want head.h).  Consequently, the copy
#
opset.c: $(SHARE)/opset.c
	cp $(SHARE)/opset.c opset.c
optab.c: $(SHARE)/optab.c
	cp $(SHARE)/optab.c optab.c
instrs.adb: $(SHARE)/instrs.adb
	cp $(SHARE)/instrs.adb instrs.adb
#
#	Now, compile them
#
opset.o: opset.c
	$(CC) -I. -I$(AS) $(CFLAGS) -c opset.c
optab.o: optab.c instrs.adb
	$(CC) -I. -I$(AS) $(CFLAGS) -c optab.c
$(SHARE)/instrs.adb: $(AS)/instrs
	cd $(SHARE); make instrs.adb
E 4
E 3
install:
	cp sdb sdb.temp
	install -s sdb $(DESTDIR)/usr/bin
	mv sdb.temp sdb
D 4

E 4
clean:
	rm -f *.o sdb

print:
	ls -l Makefile | pr
	pr -f *.h *.c

sources: ${SRCS} ${HDRS}
${SRCS} ${HDRS}:
	sccs get $@

depend:
	/bin/grep '^#[ 	]*include' ${SRCS} \
		| sed '/<.*>/d' \
		| sed 's/:[^"]*"\([^"]*\)".*/: \1/' \
		| sed 's/\.c/.o/' >>makedep
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile

# DO NOT DELETE THIS LINE -- make depend uses it
E 1
