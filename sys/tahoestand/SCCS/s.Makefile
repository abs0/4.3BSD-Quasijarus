h15183
s 00011/00005/00168
d D 7.9 88/07/09 11:00:13 bostic 9 8
c install approved copyright notice
e
s 00103/00088/00070
d D 7.8 88/05/24 13:34:38 bostic 8 7
c cleanup; change to dev(a,b,c,d) format
e
s 00050/00043/00108
d D 7.7 87/11/03 15:30:26 bostic 7 6
c added hdc support
e
s 00013/00014/00138
d D 7.6 87/02/23 11:44:19 karels 6 5
c cleanups
e
s 00001/00001/00151
d D 7.5 86/11/16 19:18:23 sam 5 4
c fix /boot installation
e
s 00002/00001/00150
d D 7.4 86/11/16 19:14:39 sam 4 3
c make /stand/directory
e
s 00045/00073/00106
d D 7.3 86/11/04 21:21:58 karels 3 2
c cleanup and conversion to 4.3
e
s 00005/00003/00174
d D 7.2 86/01/21 11:38:14 sam 2 1
c make things compile again after changing vdreg.h and creatng vbparam.h
e
s 00177/00000/00000
d D 7.1 86/01/12 18:04:55 sam 1 0
c date and time created 86/01/12 18:04:55 by sam
e
u
U
t
T
I 1
D 8
#	%M%	%I%	%E%
E 8
#
I 8
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 9
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
#
#	%W% (Berkeley) %G%
#
I 9

E 9
RELOC=		800
MTBOOTRELOC=	e0000
BOOTRELOC=	e0000
LDT1MBSYSOPT=	-T ${MTBOOTRELOC} -x
LDTSYSOPT=	-T ${BOOTRELOC} -x
LDTOPT=		-T ${RELOC} -e _entry -x

E 8
DESTDIR=
I 8
VPATH=	../stand
E 8
LIBS=	libsa.a ${DESTDIR}/lib/libc.a
D 6
COPTS=	-O -I. -I../h
CFLAGS=	-DSTANDALONE -DTAHOE ${COPTS}
E 6
D 3
RELOC=	70000
MTARELOC=98000
BOOTRELOC=100000
E 3
I 3
D 8
RELOC=	800
MTBOOTRELOC=e0000
D 6
BOOTRELOC=2e0000
E 6
I 6
BOOTRELOC=e0000
COPTS=	-O -I. -I../h
CFLAGS=	-DSTANDALONE -DTAHOE -DRELOC=0x${RELOC} ${COPTS}
E 6
E 3
SRCS=	sys.c conf.c prf.c machdep.c 
D 3
DRIVERS=udc.o cy.o vddc.o
LDT1MBSYSOPT=-T ${MTARELOC} -x
E 3
I 3
D 7
DRIVERS=udc.o cy.o vd.o
E 7
I 7
DRIVERS=udc.o cy.o vd.o hdc.o
E 7
LDT1MBSYSOPT=-T ${MTBOOTRELOC} -x
E 3
LDTSYSOPT=-T ${BOOTRELOC} -x
LDTOPT=	-T ${RELOC} -e _entry -x
D 3
LDTSF=	-N -x
CFILES=	boot.c cat.c conf.c ls.c prf.c srt0.c sys.c vdformat.c ls.c \
	fastcopy.c devcopy.c cat.c  vddc.c cy.c
ALL=	boot.fsd boot.smd boot.xfd boot.xsd \
	boot1mb.fsd boot1mb.smd boot1mb.xfd boot1mb.xsd \
	cat ls devcopy fastcopy vdformat
E 3
I 3
CFILES=	boot.c cat.c conf.c ls.c prf.c srt0.c sys.c ls.c \
D 6
	fastcopy.c devcopy.c cat.c  vd.c cy.c
E 6
I 6
D 7
	fastcopy.c devcopy.c copy.c cat.c  vd.c cy.c
E 7
I 7
	fastcopy.c devcopy.c copy.c cat.c vd.c cy.c hdc.c
E 8
I 8
COPTS=	-O -I. -I../stand -I../h
CFLAGS=	-DSTANDALONE -DCOMPAT_42 -DTAHOE -DRELOC=0x${RELOC} ${COPTS}
E 8
E 7
E 6
SUBDIR=	vdformat
D 6
ALL=	boot boot1mb cat ls devcopy fastcopy
E 6
I 6
D 8
ALL=	boot cat copy ls devcopy fastcopy
E 8
I 8
ALL=	boot cat copy ls
E 8
E 6
E 3

D 3
all:	srt0.o libsa.a ${ALL}
E 3
I 3
D 8
all:	srt0.o libsa.a ${ALL} ${SUBDIR}
E 8
I 8
SRCS=	boot.c cat.c conf.c copy.c dev.c getfile.c gets.c ls.c prf.c \
	srt0.c sys.c vd.c cy.c hdc.c
DRIVERS=cy.o vd.o hdc.o
E 8
E 3

D 8
install: all
I 4
	-mkdir ${DESTDIR}/stand
E 4
D 6
	install -c -m 644 libsa.a ${DESTDIR}/usr/lib/libsa.a
E 6
D 3
	for i in ${ALL}; do install -m 644 $$i ${DESTDIR}/stand; done
E 3
I 3
	for i in ${ALL}; do \
D 4
		install -m 644 $$i ${DESTDIR}/stand; \
E 4
I 4
		install -m 644 $$i ${DESTDIR}/stand/$$i; \
E 4
	done
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install) \
	done
E 3
D 5
	rm -f ${DESTDIR}/boot; cp ${DESTDIR}/stand/boot.fsd ${DESTDIR}/boot
E 5
I 5
	rm -f ${DESTDIR}/boot; cp ${DESTDIR}/stand/boot ${DESTDIR}/boot
E 8
I 8
#all: srt0.o libsa.a ${ALL} ${SUBDIR}
all: srt0.o libsa.a ${ALL}
E 8
E 5

D 8
clean:
	rm -f ${ALL} *.o *.map *.bak a.out ncy.c libsa.a
I 3
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} clean) \
	done
E 8
I 8
${SUBDIR}: FRC
	cd $@; make ${MFLAGS}
E 8
E 3

machdep.o: machdep.c ../tahoe/mtpr.h ../tahoe/mem.h ../tahoe/SYS.h
	${CC} -E ${CFLAGS} machdep.c | ${AS}  -o machdep.o

D 8
libsa.a: sys.o conf.o ${DRIVERS} prf.o machdep.o 
E 8
I 8
libsa.a: conf.o dev.o getfile.o gets.o machdep.o prf.o printn.o sys.o \
	${DRIVERS}
E 8
	ar crv $@ $?
	ranlib $@

D 3
boot.fsd: boot.fsd.o bootsrt0.o ${LIBS}
	ld ${LDTSYSOPT} bootsrt0.o boot.fsd.o ${LIBS}
	dd if=a.out of=boot.fsd ibs=1024 skip=1
E 3
I 3
D 8
boot:	boot.o bootsrt0.o ${LIBS}
E 8
I 8
boot: boot.o bootsrt0.o ${LIBS}
E 8
	ld ${LDTSYSOPT} bootsrt0.o boot.o ${LIBS}
	nm -u a.out
	size a.out
	dd if=a.out of=boot ibs=1024 skip=1
	-rm -f a.out
E 3

D 3
boot.smd: boot.smd.o bootsrt0.o ${LIBS}
	ld ${LDTSYSOPT} bootsrt0.o boot.smd.o ${LIBS}
	dd if=a.out of=boot.smd ibs=1024 skip=1
E 3
I 3
boot1mb: boot.o boot1mbsrt0.o ${LIBS}
	ld ${LDT1MBSYSOPT} boot1mbsrt0.o boot.o ${LIBS}
	nm -u a.out
	size a.out
	dd if=a.out of=boot1mb ibs=1024 skip=1
	-rm -f a.out
E 3

D 3
boot.xfd: boot.xfd.o bootsrt0.o ${LIBS}
	ld ${LDTSYSOPT} bootsrt0.o boot.xfd.o ${LIBS}
	dd if=a.out of=boot.xfd ibs=1024 skip=1

boot.xsd: boot.xsd.o bootsrt0.o ${LIBS}
	ld ${LDTSYSOPT} bootsrt0.o boot.xsd.o ${LIBS}
	dd if=a.out of=boot.xsd ibs=1024 skip=1

boot1mb.fsd: boot.fsd.o boot1mbsrt0.o ${LIBS}
	ld ${LDT1MBSYSOPT} boot1mbsrt0.o boot.fsd.o ${LIBS}
	dd if=a.out of=boot1mb.fsd ibs=1024 skip=1

boot1mb.smd: boot.smd.o boot1mbsrt0.o ${LIBS}
	ld ${LDT1MBSYSOPT} boot1mbsrt0.o boot.smd.o ${LIBS}
	dd if=a.out of=boot1mb.smd ibs=1024 skip=1

boot1mb.xfd: boot.xfd.o boot1mbsrt0.o ${LIBS}
	ld ${LDT1MBSYSOPT} boot1mbsrt0.o boot.xfd.o ${LIBS}
	dd if=a.out of=boot1mb.xfd ibs=1024 skip=1

boot1mb.xsd: boot.xsd.o boot1mbsrt0.o ${LIBS}
	ld ${LDT1MBSYSOPT} boot1mbsrt0.o boot.xsd.o ${LIBS}
	dd if=a.out of=boot1mb.xsd ibs=1024 skip=1

E 3
D 8
cat:	cat.o srt0.o ${LIBS}
	ld ${LDTOPT} -o cat -s srt0.o cat.o ${LIBS}
E 8
I 8
cat: cat.o srt0.o ${LIBS}
	ld ${LDTOPT} -o $@ -s srt0.o cat.o ${LIBS}
E 8

D 8
devcopy: devcopy.o srt0.o ${LIBS}
	ld ${LDTOPT} -o devcopy -s srt0.o devcopy.o ${LIBS}
E 8
I 8
copy: copy.o srt0.o ncy.o ${LIBS}
	ld ${LDTOPT} -o $@ srt0.o copy.o ncy.o ${LIBS}
E 8

I 6
D 8
copy:	copy.o srt0.o ncy.o ${LIBS}
	ld ${LDTOPT} -o copy srt0.o copy.o ncy.o ${LIBS}

E 6
fastcopy: fastcopy.o srt0.o ncy.o ${LIBS}
	ld ${LDTOPT} -o fastcopy -s srt0.o fastcopy.o ncy.o ${LIBS}

E 8
xpformat: xpformat.o srt0.o ${LIBS}
D 8
	ld ${LDTOPT} -o xpformat srt0.o xpformat.o ${LIBS}
E 8
I 8
	ld ${LDTOPT} -o $@ srt0.o xpformat.o ${LIBS}
E 8

D 3
vdformat: vdformat.o srt0.o ${LIBS}
	ld ${LDTOPT} -o vdformat -s srt0.o vdformat.o ${LIBS}
E 3
I 3
D 8
vdformat: FRC
	cd vdformat; make ${MFLAGS}
E 8
I 8
ls: ls.o srt0.o ${LIBS}
	ld ${LDTOPT} -o $@ -s srt0.o ls.o ${LIBS}
E 8
E 3

I 3
D 8
FRC:

E 3
ls:	ls.o srt0.o ${LIBS}
	ld ${LDTOPT} -o ls -s srt0.o ls.o ${LIBS}

E 8
D 3
boot.fsd.o: boot.c
	${CC} -c $(COPTS) -DFSD boot.c
	mv boot.o $@

boot.smd.o: boot.c
	${CC} -c $(COPTS) -DSMD boot.c
	mv boot.o $@

boot.xfd.o: boot.c
	${CC} -c $(COPTS) -DXFD boot.c
	mv boot.o $@

boot.xsd.o: boot.c
	${CC} -c $(COPTS) -DXFD boot.c
	mv boot.o $@

E 3
srt0.o: srt0.c
D 6
	${CC} -E -DRELOC=0x${RELOC} ${CFLAGS} srt0.c | ${AS} -o srt0.o
E 6
I 6
	${CC} -E ${CFLAGS} srt0.c | ${AS} -o srt0.o
E 6

bootsrt0.o: srt0.c
D 3
	${CC} -E -DRELOC=0x${BOOTRELOC} -DREL ${CFLAGS} srt0.c | ${AS} -o bootsrt0.o
E 3
I 3
D 6
	${CC} -E -DRELOC=0x${BOOTRELOC} -DREL ${CFLAGS} srt0.c | \
E 6
I 6
	${CC} -E -DBOOTRELOC=0x${BOOTRELOC} -DREL ${CFLAGS} srt0.c | \
E 6
	    ${AS} -o bootsrt0.o
E 3

boot1mbsrt0.o: srt0.c
D 3
	${CC} -E -DRELOC=0x${MTARELOC} -DREL ${CFLAGS} srt0.c | ${AS} -o boot1mbsrt0.o
E 3
I 3
D 6
	${CC} -E -DRELOC=0x${MTBOOTRELOC} -DREL ${CFLAGS} srt0.c | \
E 6
I 6
	${CC} -E -DBOOTRELOC=0x${MTBOOTRELOC} -DREL ${CFLAGS} srt0.c | \
E 6
	    ${AS} -o boot1mbsrt0.o
E 3

D 6
sfrt0.o: sfrt0.c
D 3
	${CC} -E -DRELOC=0x${RELOC} -DREL ${CFLAGS} sfrt0.c | ${AS} -o sfrt0.o
E 3
I 3
	${CC} -E -DRELOC=0x${RELOC} -DREL ${CFLAGS} sfrt0.c | \
	    ${AS} -o sfrt0.o
E 3

E 6
D 8
ncy.c:	cy.c
E 8
I 8
ncy.c: cy.c
E 8
I 6
	rm -f ncy.c
E 6
	ln cy.c ncy.c

D 8
ncy.o:	ncy.c
E 8
I 8
ncy.o: ncy.c
E 8
	${CC} -DNOBLOCK ${CFLAGS} -c ncy.c

D 8
print:
	@pr -f makefile
D 6
	@/usr/ucb/ls -l | pr -f
E 6
I 6
	@ls -l | pr -f
E 6
	@pr -f *.h *.c *.lst
E 8
I 8
clean: FRC
	rm -f ${ALL} *.o *.map *.bak a.out ncy.c libsa.a
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 8

D 7
depend:
	${CC} -M ${COPTS} ${CFILES} | \
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
E 7
I 7
D 8
tags: FRC
	ctags ${CFILES}
E 8
I 8
depend: ${SRCS} FRC
	mkdep ${COPTS} ${SRCS}
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
E 8
E 7

D 7
# DO NOT DELETE THIS LINE -- make depend uses it
E 7
I 7
D 8
depend: FRC
	mkdep ${COPTS} ${CFILES}
E 8
I 8
install: FRC
	-mkdir ${DESTDIR}/stand
	for i in ${ALL}; do \
		install -o bin -g bin -m 644 $$i ${DESTDIR}/stand/$$i; \
	done
	rm -f ${DESTDIR}/boot;
	cp ${DESTDIR}/stand/boot ${DESTDIR}/boot
	for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install) \
	done
E 8
E 7

I 8
tags: ${SRCS} FRC
	ctags ${SRCS}
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} tags); done

E 8
D 7
boot.o: boot.c ./../machine/mtpr.h ../h/param.h
boot.o: /usr/include/machine/machparam.h ../h/signal.h /usr/include/sys/types.h
boot.o: ../h/inode.h ../h/fs.h ../h/vm.h /usr/include/sys/vmparam.h
boot.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
boot.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h ./saio.h
boot.o: ../h/reboot.h /usr/include/a.out.h /usr/include/sys/exec.h
E 7
I 7
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

boot.o: boot.c ../machine/mtpr.h ../h/param.h /usr/include/sys/types.h
boot.o: ../h/signal.h /usr/include/machine/trap.h
D 8
boot.o: /usr/include/machine/machparam.h ../h/inode.h ../h/fs.h ../h/vm.h
boot.o: /usr/include/sys/vmparam.h /usr/include/machine/vmparam.h
boot.o: /usr/include/sys/vmmac.h /usr/include/sys/vmmeter.h
boot.o: /usr/include/sys/vmsystm.h saio.h ../h/reboot.h /usr/include/a.out.h
boot.o: /usr/include/sys/exec.h
E 7
cat.o: cat.c
D 7
conf.o: conf.c ./../machine/pte.h ../h/param.h /usr/include/machine/machparam.h
conf.o: ../h/signal.h /usr/include/sys/types.h ../h/inode.h ../h/fs.h ./saio.h
ls.o: ls.c ../h/param.h /usr/include/machine/machparam.h ../h/signal.h
ls.o: /usr/include/sys/types.h ../h/inode.h ../h/dir.h ../h/fs.h ./saio.h
prf.o: prf.c ./../machine/mtpr.h ../h/param.h /usr/include/machine/machparam.h
prf.o: ../h/signal.h /usr/include/sys/types.h ./../tahoe/cp.h
srt0.o: srt0.c ./../machine/mtpr.h
sys.o: sys.c ./../machine/mtpr.h ../h/param.h /usr/include/machine/machparam.h
sys.o: ../h/signal.h /usr/include/sys/types.h ../h/inode.h ../h/fs.h ../h/dir.h
sys.o: ./saio.h
D 3
vdformat.o: vdformat.c ./../machine/mtpr.h ../h/param.h
vdformat.o: /usr/include/machine/machparam.h ../h/signal.h
vdformat.o: /usr/include/sys/types.h ../h/inode.h ../h/fs.h ./saio.h
D 2
vdformat.o: ./../tahoevba/vddcreg.h /usr/include/setjmp.h
E 2
I 2
vdformat.o: ./../tahoevba/vbaparam.h ./../tahoevba/vdreg.h
vdformat.o: /usr/include/setjmp.h
E 3
E 2
ls.o: ls.c ../h/param.h /usr/include/machine/machparam.h ../h/signal.h
ls.o: /usr/include/sys/types.h ../h/inode.h ../h/dir.h ../h/fs.h ./saio.h
E 7
I 7
conf.o: conf.c ../machine/pte.h ../h/param.h /usr/include/sys/types.h
conf.o: ../h/signal.h /usr/include/machine/trap.h
conf.o: /usr/include/machine/machparam.h ../h/inode.h ../h/fs.h saio.h
ls.o: ls.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
ls.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h ../h/inode.h
ls.o: ../h/dir.h ../h/fs.h saio.h
E 8
I 8
boot.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
boot.o: ../h/inode.h ../h/fs.h ../h/vm.h /usr/include/sys/vmparam.h
boot.o: /usr/include/machine/vmparam.h /usr/include/sys/vmmac.h
boot.o: /usr/include/sys/vmmeter.h /usr/include/sys/vmsystm.h ../stand/saio.h
boot.o: ../stand/saioctl.h ../stand/saerrno.h ../h/reboot.h
boot.o: /usr/include/a.out.h /usr/include/sys/exec.h
cat.o: ../stand/cat.c
conf.o: conf.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
conf.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
conf.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../stand/saio.h
conf.o: ../stand/saioctl.h ../stand/saerrno.h
copy.o: ../stand/copy.c
dev.o: ../stand/dev.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
dev.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
dev.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../stand/saio.h
dev.o: ../stand/saioctl.h ../stand/saerrno.h
getfile.o: ../stand/getfile.c ../h/param.h /usr/include/sys/types.h
getfile.o: ../h/signal.h /usr/include/machine/trap.h
getfile.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
getfile.o: ../h/inode.h ../h/fs.h ../stand/saio.h ../stand/saioctl.h
getfile.o: ../stand/saerrno.h
gets.o: ../stand/gets.c
ls.o: ../stand/ls.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
ls.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
ls.o: /usr/include/machine/endian.h ../h/inode.h ../h/dir.h ../h/fs.h
ls.o: ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
E 8
prf.o: prf.c ../machine/mtpr.h ../h/param.h /usr/include/sys/types.h
prf.o: ../h/signal.h /usr/include/machine/trap.h
D 8
prf.o: /usr/include/machine/machparam.h ../tahoe/cp.h
E 8
I 8
prf.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
prf.o: ../tahoe/cp.h
E 8
srt0.o: srt0.c ../machine/mtpr.h
D 8
sys.o: sys.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
E 8
I 8
sys.o: ../stand/sys.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
E 8
sys.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
D 8
sys.o: ../h/inode.h ../h/fs.h ../h/dir.h ../h/reboot.h saio.h ../machine/mtpr.h
ls.o: ls.c ../h/param.h /usr/include/sys/types.h ../h/signal.h
ls.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h ../h/inode.h
ls.o: ../h/dir.h ../h/fs.h saio.h
E 7
fastcopy.o: fastcopy.c
devcopy.o: devcopy.c
I 7
copy.o: copy.c
E 7
cat.o: cat.c
E 8
I 8
sys.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/dir.h
sys.o: ../h/reboot.h ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h
E 8
D 3
vddc.o: vddc.c ./../machine/mtpr.h ../h/param.h
vddc.o: /usr/include/machine/machparam.h ../h/signal.h /usr/include/sys/types.h
D 2
vddc.o: ../h/inode.h ../h/fs.h ./../tahoevba/vddcreg.h ./saio.h
E 2
I 2
vddc.o: ../h/inode.h ../h/fs.h ./../tahoevba/vdreg.h ./../tahoevba/vbaparam.h
vddc.o: ./saio.h
E 3
I 3
D 7
vd.o: vd.c ./../machine/mtpr.h ../h/param.h
vd.o: /usr/include/machine/machparam.h ../h/signal.h /usr/include/sys/types.h
vd.o: ../h/inode.h ../h/fs.h ./../tahoevba/vdreg.h ./../tahoevba/vbaparam.h
vd.o: ./saio.h
E 3
E 2
cy.o: cy.c ./../machine/pte.h ./../machine/mtpr.h ../h/param.h
cy.o: /usr/include/machine/machparam.h ../h/signal.h /usr/include/sys/types.h
D 2
cy.o: ../h/inode.h ../h/fs.h ./saio.h ./cyvar.h
E 2
I 2
cy.o: ../h/inode.h ../h/fs.h ./saio.h ./cyvar.h ./../tahoevba/vbaparam.h
E 7
I 7
vd.o: vd.c ../machine/mtpr.h ../h/param.h /usr/include/sys/types.h
vd.o: ../h/signal.h /usr/include/machine/trap.h
D 8
vd.o: /usr/include/machine/machparam.h ../h/inode.h ../h/fs.h ../h/buf.h
vd.o: ../h/disklabel.h saio.h ../tahoevba/vdreg.h ../tahoevba/vbaparam.h
E 8
I 8
vd.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
vd.o: ../h/inode.h ../h/fs.h ../h/buf.h ../h/disklabel.h ../stand/saio.h
vd.o: ../stand/saioctl.h ../stand/saerrno.h ../tahoevba/vdreg.h
vd.o: ../tahoevba/vbaparam.h
E 8
cy.o: cy.c ../machine/pte.h ../machine/mtpr.h ../h/param.h
cy.o: /usr/include/sys/types.h ../h/signal.h /usr/include/machine/trap.h
D 8
cy.o: /usr/include/machine/machparam.h ../h/inode.h ../h/fs.h saio.h
cy.o: ../tahoevba/cyreg.h ../tahoevba/vbaparam.h
E 8
I 8
cy.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
cy.o: ../h/inode.h ../h/fs.h ../stand/saio.h ../stand/saioctl.h
cy.o: ../stand/saerrno.h ../tahoevba/cyreg.h ../tahoevba/vbaparam.h
E 8
hdc.o: hdc.c /usr/include/machine/mtpr.h ../h/param.h ../h/types.h
hdc.o: ../h/signal.h /usr/include/machine/trap.h ../h/../machine/machparam.h
D 8
hdc.o: ../h/inode.h ../h/fs.h ../h/buf.h ../h/ioctl.h ../h/ttychars.h
hdc.o: ../h/ttydev.h ../h/disklabel.h saio.h ../tahoevba/dsk.h
hdc.o: ../tahoevba/dskio.h ../tahoevba/hdc.h
E 8
I 8
hdc.o: /usr/include/machine/endian.h ../h/inode.h ../h/fs.h ../h/buf.h
hdc.o: ../h/ioctl.h ../h/ttychars.h ../h/ttydev.h ../h/disklabel.h
hdc.o: ../stand/saio.h ../stand/saioctl.h ../stand/saerrno.h ../tahoevba/hdc.h
E 8

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 7
E 2
E 1
