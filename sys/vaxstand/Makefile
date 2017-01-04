#
# Copyright (c) 1980, 1988 Regents of the University of California.
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
#	@(#)Makefile	7.28 (Berkeley) 2/28/04
#

DESTDIR=
STAND=	/stand
INCPATH=-I. -I../stand -I../h
VPATH=	../stand:../vax
DEFS=	${INCPATH} -DSTANDALONE
MACH=	-DVAX8600 -DVAX8200 -DVAX780 -DVAX750 -DVAX730 -DVAX630 -DVAX650
LS=	/bin/ls

# Collections of C options:
#	COPTS	device drivers/assembler, not optimized
#	SMOPTS	"small" versions for 7.5K bootxx programs (750 only)
#	RAOPTS	like SMOPTS, but for bootra, which is 750 + 8200
#	KRAOPTS	like SMOPTS, but for bootkra, which is 8200 only
#	CFLAGS	everything else

COPTS=	${DEFS} ${MACH} -DCOMPAT_42
CFLAGS=	-O ${DEFS} ${MACH} -DCOMPAT_42
SMOPTS=	${DEFS} -DSMALL -DVAX750
RAOPTS=	${DEFS} -DSMALL -DVAX750 -DVAX8200
KRAOPTS=${DEFS} -DSMALL -DVAX8200

RELOC=	150000
LIBSA=	libsa.a

SRCS=	autoconf.c boot.c bootdec.c bootxx.c cat.c copy.c dev.c drtest.c \
	format.c getfile.c gets.c hp.c hpmaptype.c ht.c idc.c kdb.c machdep.c \
	mba.c mt.c prf.c printn.c rk.c rl.c rom.c sys.c tm.c tmscp.c ts.c \
	uba.c uda.c up.c upmaptype.c ut.c vmb.c vmberr.c vmbt.c conf.c \
	confdec.c confhpup.c  ../vax/dkbad.c
DUMMIES=confxx.c
DRIVERS=autoconf.o hp.o hpmaptype.o ht.o idc.o kdb.o mba.o mt.o rk.o rl.o \
	tm.o tmscp.o ts.o up.o upmaptype.o uba.o uda.o ut.o
ASMS=	badaddr.o cons6xx.o qioinit.o romio.o scb.o startvmb.o strcmp.o \
	strcpy.o strlen.o
SMOBJ=	bootxx.o sm_sys.o sm_autoconf.o sm_scb.o
RAOBJ=	bootxx.o sm_sys.o ra_autoconf.o sm_scb.o sm_uda.o
KRAOBJ=	bootxx.o sm_sys.o kra_autoconf.o sm_scb.o sm_kdb.o
DECOBJ=	bootdec.o sm_sys.o sm_scb.o

# These drivers don't have ecc correction and bad sector forwarding;
# they are placed in the file system boot area for 750's.  If your
# root has bad sectors you can try and squeeze the newer drivers in...
ODRIVERS=sm_hp.o sm_up.o

MDEC=	boothp boothk bootkra bootup bootra bootrl bootdec
ALL=	boot tpboot cat copy tpcopy format tpformat drtest ls \
	${MDEC}

all: ${ALL}

${LIBSA}: conf.o cpuid.o dev.o dkbad.o getfile.o gets.o machdep.o prf.o \
	printn.o rom.o sys.o vmb.o vmberr.o vmbt.o ${DRIVERS} ${ASMS}
	ar crv ${LIBSA} $?
	ranlib ${LIBSA}

${DRIVERS}:
	${CC} -c -S ${COPTS} $*.c
	/lib/c2 -i $*.s | as -o $*.o
	rm -f $*.s

${ASMS}:
	${CC} -E ${COPTS} $*.c | as -o $*.o

cpuid.o:	../vax/cpuid.s
	-ln -s ../vax/cpuid.s cpuid.c
	${CC} -E ${COPTS} cpuid.c | as -o cpuid.o
	rm -f cpuid.c

# startups

srt0.o: srt0.c ../vax/mtpr.h ../vax/cpu.h
	${CC} -E -DRELOC=0x${RELOC} ${COPTS} srt0.c | as -o srt0.o

relsrt0.o: srt0.c ../vax/mtpr.h ../vax/cpu.h
	${CC} -E -DRELOC=0x${RELOC} -DREL ${COPTS} srt0.c | as -o relsrt0.o

relsrt750.o: srt0.c ../vax/mtpr.h ../vax/cpu.h
	${CC} -E -DRELOC=0x${RELOC} -DREL -DOLD750BOOT ${RAOPTS} srt0.c \
	| as -o relsrt750.o

decsrt0.o: decsrt0.c ../vax/mtpr.h ../vax/cpu.h
	${CC} -E -DRELOC=0x${RELOC} ${COPTS} decsrt0.c | as -o decsrt0.o

# bootable from tape

tpboot: tpboot.o relsrt0.o ${LIBSA}
	ld -N -T ${RELOC} relsrt0.o tpboot.o ${LIBSA} -lc
	strip a.out; dd if=a.out of=tpboot ibs=32 skip=1; rm -f a.out

tpboot.o: boot.o
	rm -f $*.c
	ln -s boot.c $*.c
	${CC} -c ${CFLAGS} -DJUSTASK $*.c
	rm -f $*.c

tpcopy: copy.o srt0.o ${LIBSA}
	ld -N srt0.o copy.o ${LIBSA} -lc
	strip a.out; dd if=a.out of=tpcopy ibs=32 skip=1; rm -f a.out

tpformat: tpformat.o srt0.o confhpup.o ${LIBSA}
	ld -N srt0.o tpformat.o confhpup.o ${LIBSA} -lc
	strip a.out; dd if=a.out of=tpformat ibs=32 skip=1; rm -f a.out

tpformat.o: format.o
	rm -f $*.c
	ln -s format.c $*.c
	${CC} -c ${CFLAGS} -DJUSTEXIT $*.c
	rm -f $*.c

# bootable from floppy or real disks

boot: boot.o relsrt0.o bootconf.o ${LIBSA}
	ld -N -T ${RELOC} -o $@ relsrt0.o boot.o bootconf.o ${LIBSA} -lc

bootconf.o: conf.o
	rm -f $*.c
	ln -s conf.c $*.c
	${CC} -c ${CFLAGS} -DBOOT $*.c
	rm -f $*.c

copy: copy.o srt0.o getfile.o ${LIBSA}
	ld -N -o $@ srt0.o copy.o getfile.o ${LIBSA} -lc

cat: cat.o srt0.o getfile.o ${LIBSA}
	ld -N -o $@ srt0.o cat.o getfile.o ${LIBSA} -lc

ls: ls.o srt0.o ${LIBSA}
	ld -N -o $@ srt0.o ls.o ${LIBSA} -lc

format: format.o srt0.o confhpup.o ${LIBSA}
	ld -N -o $@ srt0.o format.o confhpup.o ${LIBSA} -lc

drtest: drtest.o srt0.o confhpup.o ${LIBSA}
	ld -N -o $@ srt0.o drtest.o confhpup.o ${LIBSA} -lc

# bootstrap from ether

### not yet, rosin, not yet ###

# getting booted from disc

boothk: relsrt750.o confrk.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confrk.o ${SMOBJ} ${LIBSA} -lc
	size a.out
	rm -f $@
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
	${LS} -l $@

boothp: relsrt750.o confhp.o sm_hp.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confhp.o sm_hp.o ${SMOBJ} ${LIBSA} -lc
	size a.out
	rm -f $@
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
	${LS} -l $@

bootkra: relsrt750.o confkra.o ${KRAOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confkra.o ${KRAOBJ} ${LIBSA} -lc
	size a.out
	rm -f $@
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
	${LS} -l $@

bootup: relsrt750.o confup.o sm_up.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confup.o sm_up.o ${SMOBJ} ${LIBSA} -lc
	size a.out
	rm -f $@
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
	${LS} -l $@

bootra: relsrt750.o confra.o ${RAOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confra.o ${RAOBJ} ${LIBSA} -lc
	size a.out
	rm -f $@
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
	${LS} -l $@

bootrl: relsrt750.o confrl.o ${SMOBJ} ${LIBSA}
	ld -N -T ${RELOC} relsrt750.o confrl.o ${SMOBJ} ${LIBSA} -lc
	size a.out
	rm -f $@
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
	${LS} -l $@

bootdec: decsrt0.o confdec.o ${DECOBJ} ${LIBSA}
	ld -N -T ${RELOC} decsrt0.o confdec.o ${DECOBJ} ${LIBSA} -lc
	size a.out
	rm -f $@
	strip a.out;dd if=a.out of=$@ ibs=32 skip=1;rm -f a.out
	${LS} -l $@

sm_hp.o: hp.o
	rm -f sm_hp.c
	ln -s hp.c sm_hp.c
	${CC} -S ${SMOPTS} sm_hp.c
	/lib/c2 -i sm_hp.s | as -o sm_hp.o
	rm -f sm_hp.s sm_hp.c

sm_up.o: up.o
	rm -f sm_up.c
	ln -s up.c sm_up.c
	${CC} -S ${SMOPTS} sm_up.c
	/lib/c2 -i sm_up.s | as -o sm_up.o
	rm -f sm_up.s sm_up.c

sm_uda.o: uda.o
	rm -f sm_uda.c
	ln -s uda.c sm_uda.c
	${CC} -S ${RAOPTS} sm_uda.c
	/lib/c2 -i sm_uda.s | as -o sm_uda.o
	rm -f sm_uda.s sm_uda.c

sm_kdb.o: kdb.o
	rm -f sm_kdb.c
	ln -s kdb.c sm_kdb.c
	${CC} -S ${KRAOPTS} sm_kdb.c
	/lib/c2 -i sm_kdb.s | as -o sm_kdb.o
	rm -f sm_kdb.s sm_kdb.c

sm_sys.o: sys.o
	rm -f sm_sys.c
	ln -s sys.c sm_sys.c
	${CC} -c ${CFLAGS} -DSMALL sm_sys.c
	rm -f sm_sys.c

sm_autoconf.o: autoconf.o
	rm -f sm_autoconf.c
	ln -s autoconf.c sm_autoconf.c
	${CC} -S ${SMOPTS} sm_autoconf.c
	/lib/c2 -i sm_autoconf.s | as -o sm_autoconf.o
	rm -f sm_autoconf.s sm_autoconf.c

ra_autoconf.o: autoconf.o
	rm -f ra_autoconf.c
	ln -s autoconf.c ra_autoconf.c
	${CC} -S ${RAOPTS} ra_autoconf.c
	/lib/c2 -i ra_autoconf.s | as -o ra_autoconf.o
	rm -f ra_autoconf.s ra_autoconf.c

kra_autoconf.o: autoconf.o
	rm -f kra_autoconf.c
	ln -s autoconf.c kra_autoconf.c
	${CC} -S ${KRAOPTS} kra_autoconf.c
	/lib/c2 -i kra_autoconf.s | as -o kra_autoconf.o
	rm -f kra_autoconf.s kra_autoconf.c

sm_scb.o: scb.o
	${CC} -E ${COPTS} -DSMALL scb.c | as -o sm_scb.o

confrk.o: confrk.c confxx.o
confhp.o: confhp.c confxx.o
confkra.o: confkra.c confxx.o
confup.o: confup.c confxx.o
confra.o: confra.c confxx.o
confrl.o: confrl.c confxx.o

confxx.o:
	touch confxx.o

confrk.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confrk.c
	sed -e 's/XX/hk/' -e 's/xx/rk/g'	< confxx.c >> confrk.c
confhp.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confhp.c
	sed -e 's/XX/hp/' -e 's/xx/hp/g'	< confxx.c >> confhp.c
confkra.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confkra.c
	sed -e 's/XX/kra/' -e 's/xx/kra/g'	< confxx.c >> confkra.c
confup.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confup.c
	sed -e 's/XX/up/' -e 's/xx/up/g'	< confxx.c >> confup.c
confra.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confra.c
	sed -e 's/XX/ra/' -e 's/xx/ra/g'	< confxx.c >> confra.c
confrl.c: confxx.c dev.c
	sed -e 's/io->i_ino.i_dev/0/g'		< dev.c > confrl.c
	sed -e 's/XX/rl/' -e 's/xx/rl/g'	< confxx.c >> confrl.c

clean:
	rm -f *.o *.exe *.i sm_*.c libsa.a
	rm -f boot[a-wyz][a-z].c conf[a-wyz][a-z].c confkra.c
	rm -f ${ALL} a.out core errs sboot bootconf.c

cleandir: clean
	rm -f ${MAN} tags .depend

depend: ${SRCS}
	mkdep ${INCPATH} -DSTANDALONE ${SRCS} ${DUMMIES}

install: installint installext

installint: FRC
	[ -d ../vaxdist/tp ] || mkdir ../vaxdist/tp
	cp tpcopy ../vaxdist/tp/copy
	cp tpboot ../vaxdist/tp/boot
	cp tpformat ../vaxdist/tp/format
	cp boot a.out; strip a.out; \
		dd if=a.out of=../floppy/boot bs=32 skip=1; rm a.out
	cp ../floppy/boot ../cassette/boot
	cp ../floppy/boot ../consolerl/boot
	cp ../floppy/boot ../rx50/boot
	cp copy a.out; strip a.out; \
		dd if=a.out of=../floppy/copy bs=32 skip=1; rm a.out
	cp ../floppy/copy ../cassette/copy
	cp ../floppy/copy ../consolerl/copy
	cp ../floppy/copy ../rx50/copy
	cp format a.out; strip a.out; \
		dd if=a.out of=../floppy/format bs=32 skip=1; rm a.out
	cp ../floppy/format ../cassette/format
	cp ../floppy/format ../consolerl/format
	cp ../floppy/format ../rx50/format
	cp drtest a.out; strip a.out; \
		dd if=a.out of=../floppy/drtest bs=32 skip=1; rm a.out
	cp ../floppy/drtest ../cassette/drtest
	cp ../floppy/drtest ../consolerl/drtest
	cp ../floppy/drtest ../rx50/drtest

installext: FRC
	install -c -s -o bin -g bin -m 644 format cat copy drtest ls ${DESTDIR}${STAND}
	install -c -o bin -g bin -m 644 boot pcs750.bin ${DESTDIR}/
	install -c -o bin -g bin -m 444 ${MDEC} ${DESTDIR}/usr/mdec

lint: ${SRCS}
	lint ${COPTS} -hxbn boot.c ${SRCS} | \
	    sed -e '/possible pointer alignment/d' \
		-e '/struct\/union .* never defined/d'

tags: ${SRCS}
	ctags ${SRCS} ${DUMMIES}

FRC:
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
