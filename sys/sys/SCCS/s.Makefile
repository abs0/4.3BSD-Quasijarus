h04207
s 00012/00013/00049
d D 7.5 87/03/28 12:15:38 bostic 5 4
c cleanup
e
s 00010/00004/00052
d D 7.4 87/03/20 23:35:50 bostic 4 3
c added tags for assembly, fixed links
e
s 00036/00029/00020
d D 7.3 87/03/13 11:09:23 bostic 3 2
c changes to tags
e
s 00001/00001/00048
d D 7.2 87/03/13 00:55:27 bostic 2 1
c added typedefs flag to ctags args
e
s 00049/00000/00000
d D 7.1 86/06/05 21:55:03 mckusick 1 0
c first distributed with 4.3BSD
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
# Put the ../h stuff near the end so that subroutine definitions win when
# there is a struct tag with the same name (eg., vmmeter).  The real
# solution would probably be for ctags to generate "struct vmmeter" tags.
D 3
CTAGS=	ctags
SRCS =	../net/*.[ch] ../netimp/*.[ch] ../netinet/*.[ch] \
	../netns/*.[ch] ../sys/*.[ch] ../vaxif/*.[ch]  ../vaxmba/*.[ch] \
	../vaxuba/*.[ch] \
	../vax/autoconf.c ../vax/clock.c ../vax/clock.h ../vax/conf.c \
	../vax/cons.c ../vax/cons.h ../vax/cpu.h ../vax/cpudata.c \
	../vax/dkbad.c ../vax/dkio.h ../vax/flp.c ../vax/flp.h \
	../vax/frame.h \
	../vax/genassym.c ../vax/in_cksum.c ../vax/machdep.c \
	../vax/machparam.h ../vax/mem.c \
	../vax/mem.h ../vax/mscp.h ../vax/mtpr.h ../vax/nexus.h \
	../vax/pcb.h ../vax/psl.h ../vax/pte.h ../vax/pup_cksum.c \
	../vax/reg.h \
	../vax/rpb.h ../vax/rpb.s ../vax/rsp.h ../vax/scb.h \
	../vax/scb.s \
	../vax/swapgeneric.c ../vax/sys_machdep.c ../vax/trap.c \
	../vax/trap.h \
	../vax/tu.c ../vax/ufs_machdep.c ../vax/vm_machdep.c \
	../vax/vmparam.h \
	../h/*.h 
E 3
I 3
D 5
CTAGS=	/usr/ucb/ctags
E 5
E 3

D 3
DIRS =	h net netimp netinet netns vax vaxif vaxmba vaxuba
E 3
I 3
TVAX=	../vax/tags
SVAX=	../net/*.[ch] ../netimp/*.[ch] ../netinet/*.[ch] ../netns/*.[ch] \
	../sys/*.[ch] ../vaxif/*.[ch]  ../vaxmba/*.[ch] ../vaxuba/*.[ch] \
	../vax/*.[ch] ../h/*.h
AVAX=	../vax/*.s
E 3

I 3
TTAHOE=	../tahoe/tags
STAHOE=	../net/*.[ch] ../netimp/*.[ch] ../netinet/*.[ch] ../netns/*.[ch] \
	../sys/*.[ch] ../tahoeif/*.[ch]  ../tahoevba/*.[ch] ../tahoe/*.[ch] \
	../h/*.h
ATAHOE=	../tahoe/*.s

DGEN=	h sys net netimp netinet netns
DVAX=	vaxif vaxmba vaxuba
DTAHOE=	tahoeif tahoevba

E 3
all:
	@echo "make tags or links only"

tags: FRC
D 3
	mv tags tags.old
	-cp ../machine/astags tags
D 2
	${CTAGS} -a ${SRCS}
E 2
I 2
	${CTAGS} -at ${SRCS}
E 2
	sort -o tags.new tags
	mv tags.new tags
	rm -f tags.old
E 3
I 3
	-mv ${TVAX} ${TVAX}.old
D 4
	${CTAGS} -atf ${TVAX} ${SVAX}
	/usr/bin/egrep "^SCBVEC(.*)|^ENTRY(.*)|^JSBENTRY(.*)" ${AVAX} | \
E 4
I 4
D 5
	${CTAGS} -dtf ${TVAX} ${SVAX}
	/usr/bin/egrep "^SCBVEC(.*)" ${AVAX} | \
/bin/sed "s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);X\3 \1 /^\2(\3\4$$/;" \
E 5
I 5
	ctags -dtf ${TVAX} ${SVAX}
	egrep "^SCBVEC(.*)" ${AVAX} | \
sed "s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);X\3 \1 /^\2(\3\4$$/;" \
E 5
		>> ${TVAX}
D 5
	/usr/bin/egrep "^ENTRY(.*)|^JSBENTRY(.*)" ${AVAX} | \
E 4
/bin/sed "s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);\3 \1 /^\2(\3\4$$/;" \
E 5
I 5
	egrep "^ENTRY(.*)|^JSBENTRY(.*)" ${AVAX} | \
sed "s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);\3 \1 /^\2(\3\4$$/;" \
E 5
		>> ${TVAX}
D 5
	/usr/bin/sort -o ${TVAX} ${TVAX}
E 5
I 5
	sort -o ${TVAX} ${TVAX}
E 5
	rm -f ${TVAX}.old
	-mv ${TTAHOE} ${TTAHOE}.old
D 4
	${CTAGS} -atf ${TTAHOE} ${STAHOE}
	/usr/bin/egrep "^SCBVEC(.*)|^ENTRY(.*)|^JSBENTRY(.*)" ${ATAHOE} | \
E 4
I 4
D 5
	${CTAGS} -dtf ${TTAHOE} ${STAHOE}
	/usr/bin/egrep "^SCBVEC(.*)" ${ATAHOE} | \
/bin/sed "s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);X\3 \1 /^\2(\3\4$$/;" \
E 5
I 5
	ctags -dtf ${TTAHOE} ${STAHOE}
	egrep "^SCBVEC(.*)" ${ATAHOE} | \
sed "s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);X\3 \1 /^\2(\3\4$$/;" \
E 5
		>> ${TTAHOE}
D 5
	/usr/bin/egrep "^ENTRY(.*)|^JSBENTRY(.*)" ${ATAHOE} | \
E 4
/bin/sed "s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);\3 \1 /^\2(\3\4$$/;" \
E 5
I 5
	egrep "^ENTRY(.*)|^JSBENTRY(.*)" ${ATAHOE} | \
sed "s;\([^:]*\):\([^(]*\)(\([^, )]*\)\(.*\);\3 \1 /^\2(\3\4$$/;" \
E 5
		>> ${TTAHOE}
D 5
	/usr/bin/sort -o ${TTAHOE} ${TTAHOE}
E 5
I 5
	sort -o ${TTAHOE} ${TTAHOE}
E 5
	rm -f ${TTAHOE}.old
E 3

links:
D 3
	-for i in ${DIRS}; do rm -f ../$$i/tags; \
	ln -s ../sys/tags ../$$i/tags; done
E 3
I 3
	-for i in ${DVAX}; do rm -f ../$$i/tags; \
	ln -s ../vax/tags ../$$i/tags; done
	-for i in ${DTAHOE}; do rm -f ../$$i/tags; \
	ln -s ../tahoe/tags ../$$i/tags; done
	-for i in ${DGEN}; do rm -f ../$$i/tags; \
	ln -s ../machine/tags ../$$i/tags; done
E 3

FRC:
E 1
