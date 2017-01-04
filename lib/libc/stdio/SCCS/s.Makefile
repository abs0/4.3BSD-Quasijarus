h09939
s 00010/00005/00132
d D 5.9 88/06/27 17:49:55 bostic 22 21
c install approved copyright notice
e
s 00004/00002/00133
d D 5.8 88/05/24 18:57:25 bostic 21 20
c add vfprintf.c, vprintf.c vsprintf.c
e
s 00002/00001/00133
d D 5.7 88/05/20 14:58:57 bostic 20 19
c set DEFS to compile in SCCS ids.
e
s 00079/00049/00055
d D 5.6 88/05/20 13:44:24 bostic 19 18
c restructuring libc
e
s 00009/00023/00095
d D 5.5 87/06/06 14:40:10 bostic 18 17
c new template
e
s 00059/00001/00059
d D 5.4 85/09/05 11:41:39 bloom 17 15
c fix make clean and add make depend
e
s 00059/00001/00059
d R 5.4 85/09/05 10:34:12 bloom 16 15
c fix make clean and add make depend
e
s 00022/00009/00038
d D 5.3 85/08/23 19:52:58 mckusick 15 14
c spell out vax rewritten routines
e
s 00001/00001/00046
d D 5.2 85/06/18 22:49:31 mckusick 14 13
c add DEFS
e
s 00006/00001/00041
d D 5.1 85/06/05 13:29:28 mckusick 13 12
c Add copyright
e
s 00014/00001/00028
d D 4.12 85/05/30 22:35:19 sam 12 11
c add tags
e
s 00002/00002/00027
d D 4.11 85/02/13 15:48:19 serge 11 10
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00003/00003/00026
d D 4.10 84/07/19 14:07:54 ralph 10 9
c rdwr.c split into fread.c and fwrite.c
e
s 00001/00001/00028
d D 4.9 84/05/15 16:53:26 ralph 9 8
c added sibuf and sobuf
e
s 00001/00001/00028
d D 4.8 83/06/30 16:37:50 sam 8 7
c add exit
e
s 00002/00002/00027
d D 4.7 83/06/30 15:17:08 sam 7 6
c from sun
e
s 00009/00019/00020
d D 4.6 83/06/27 18:25:49 root 6 5
c new organization
e
s 00005/00003/00034
d D 4.5 83/06/10 23:04:19 sam 5 4
c quiet please
e
s 00002/00002/00035
d D 4.4 82/10/05 22:43:48 mckusick 4 3
c utilize st_blksize field to optimize size of reads and writes
e
s 00001/00009/00036
d D 4.3 81/12/09 14:48:33 mckusic 3 2
c ld doprnt with -x to get rid of local labels that look like static functions
e
s 00003/00003/00042
d D 4.2 81/11/30 14:11:25 mckusic 2 1
c use -X on profiled libraries (to retain statics); -x on regular libraries
e
s 00045/00000/00000
d D 4.1 81/11/29 23:27:46 mckusick 1 0
c date and time created 81/11/29 23:27:46 by mckusick
e
u
U
t
T
I 1
D 6
# %W% (Berkeley) %G%

E 6
I 6
D 13
#	%M%	%I%	%E%
E 13
I 13
#
D 19
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 19
I 19
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 19
#
I 19
# Redistribution and use in source and binary forms are permitted
D 22
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 22
I 22
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
E 22
#
E 19
#	%W% (Berkeley) %G%
E 13
#
D 7
# printf & co are not here because they are machine dependent
E 7
I 7
D 15
# doprnt is not here because it is machine dependent
E 15
I 15
D 19
# Several routines have been rewritten in assembly language for the VAX.
# If you are not running on a VAX, you should use the original C sources
# which are included in this directory. Regretably we do not have a C
# version of doprnt().
E 15
E 7
#
I 15
D 18
#ifndef vax
E 18
I 18
#ifndef vax or tahoe
E 18
#SRCS=	${STDSRC} ${VAXSRC}
#OBJS=	${STDOBJ} ${VAXOBJ}
#else
SRCS=	${STDSRC}
OBJS=	${STDOBJ}
D 18
#endif not vax
E 18
I 18
#endif not vax or tahoe
E 19
I 19
# Many of these routines have been rewritten in assembly.  The assembly
D 20
# source can be found in the directory ../${MACHINE}/stdio.  The macro
E 20
I 20
# source can be found in the directory stdio.${MACHINE}.  The macro
E 20
# ${STDSRC} lists the files needed by all current implementations.  The
# macros ${VAXSRC} and ${TAHOESRC} are the supplemental files needed by
# the VAX and the TAHOE.  ${PORTSRC} is a list of all of the supplemental
# files.
E 19
E 18

I 20
DEFS=	-DLIBC_SCCS
E 20
E 15
E 6
D 14
CFLAGS=	-O
E 14
I 14
CFLAGS=	-O ${DEFS}
E 14
D 19

I 12
D 15
SRCS=	clrerr.c doscan.c \
	exit.c fdopen.c fgetc.c fgets.c filbuf.c findiop.c flsbuf.c fopen.c \
	fprintf.c fputc.c fputs.c fread.c freopen.c fseek.c ftell.c \
	fwrite.c getchar.c gets.c getw.c printf.c putchar.c puts.c \
E 15
I 15
STDSRC=	clrerr.c doscan.c \
	exit.c fdopen.c fgetc.c filbuf.c findiop.c flsbuf.c fopen.c \
	fprintf.c fputc.c fread.c freopen.c fseek.c ftell.c \
	fwrite.c getchar.c getw.c printf.c putchar.c \
E 15
	putw.c rew.c scanf.c setbuf.c setbuffer.c sibuf.c sobuf.c \
	sprintf.c strout.c ungetc.c
E 12
D 5
OBJS=	clrerr.o data.o doprnt.o doscan.o error.o \
E 5
I 5
D 6
OBJS=	clrerr.o data.o disktab.o doprnt.o doscan.o error.o \
E 6
I 6
D 11
OBJS=	clrerr.o data.o doscan.o \
E 6
E 5
D 8
	fdopen.o fgetc.o fgets.o filbuf.o flsbuf.o fopen.o \
E 8
I 8
	exit.o fdopen.o fgetc.o fgets.o filbuf.o flsbuf.o fopen.o \
E 11
I 11
D 15
OBJS=	clrerr.o doscan.o \
	exit.o fdopen.o fgetc.o fgets.o filbuf.o findiop.o flsbuf.o fopen.o \
E 11
E 8
D 6
	fprintf.o fputc.o fputs.o freopen.o fseek.o fstab.o ftell.o \
	gcvt.o getchar.o getgrent.o getgrgid.o getgrnam.o \
	getpass.o getpw.o getpwent.o getpwnam.o getpwuid.o gets.o getw.o \
D 4
	intss.o popen.o printf.o putchar.o puts.o putw.o \
	rdwr.o rew.o scanf.o setbuf.o sprintf.o strout.o stuff.o system.o \
E 4
I 4
	intss.o popen.o printf.o putchar.o puts.o putw.o rdwr.o rew.o \
	scanf.o setbuf.o setbuffer.o sprintf.o strout.o stuff.o system.o \
E 4
	tmpnam.o ungetc.o
E 6
I 6
D 10
	fprintf.o fputc.o fputs.o freopen.o fseek.o ftell.o \
D 7
	getchar.o gets.o getw.o putchar.o puts.o \
E 7
I 7
	getchar.o gets.o getw.o printf.o putchar.o puts.o \
E 7
D 9
	putw.o rdwr.o rew.o scanf.o setbuf.o setbuffer.o \
E 9
I 9
	putw.o rdwr.o rew.o scanf.o setbuf.o setbuffer.o sibuf.o sobuf.o \
E 10
I 10
	fprintf.o fputc.o fputs.o fread.o freopen.o fseek.o ftell.o \
	fwrite.o getchar.o gets.o getw.o printf.o putchar.o puts.o \
E 15
I 15
VAXSRC=	fgets.c fputs.c gets.c puts.c
STDOBJ=	clrerr.o doscan.o \
	exit.o fdopen.o fgetc.o filbuf.o findiop.o flsbuf.o fopen.o \
	fprintf.o fputc.o fread.o freopen.o fseek.o ftell.o \
	fwrite.o getchar.o getw.o printf.o putchar.o \
E 15
	putw.o rew.o scanf.o setbuf.o setbuffer.o sibuf.o sobuf.o \
E 10
E 9
	sprintf.o strout.o ungetc.o
I 15
VAXOBJ=	fgets.o fputs.o gets.o puts.o
E 19
I 19
STDSRC=	clrerr.c doprnt.c doscan.c exit.c fdopen.c fgetc.c filbuf.c \
	findiop.c flsbuf.c fopen.c fprintf.c fputc.c fread.c freopen.c \
	fseek.c ftell.c fwrite.c getchar.c getw.c printf.c putchar.c \
D 21
	putw.c rew.c scanf.c setbuf.c setbuffer.c sprintf.c ungetc.c
E 21
I 21
	putw.c rew.c scanf.c setbuf.c setbuffer.c sprintf.c ungetc.c \
	vfprintf.c vprintf.c vsprintf.c
E 21
STDOBJ=	clrerr.o doprnt.o doscan.o exit.o fdopen.o fgetc.o filbuf.o \
	findiop.o flsbuf.o fopen.o fprintf.o fputc.o fread.o freopen.o \
	fseek.o ftell.o fwrite.o getchar.o getw.o printf.o putchar.o \
D 21
	putw.o rew.o scanf.o setbuf.o setbuffer.o sprintf.o ungetc.o
E 21
I 21
	putw.o rew.o scanf.o setbuf.o setbuffer.o sprintf.o ungetc.o \
	vfprintf.o vprintf.o vsprintf.o
E 21
VAXSRC=
VAXOBJ=
TAHOESRC=	fgets.c fputs.c gets.c puts.c
TAHOEOBJ=	fgets.o fputs.o gets.o puts.o
PORTSRC=	fgets.c fputs.c gets.c puts.c
PORTOBJ=	fgets.o fputs.o gets.o puts.o
E 19
E 15
I 12
TAGSFILE=tags
E 12
E 6

.c.o:
D 19
	${CC} -p ${CFLAGS} -c $*.c
	-ld -X -r $*.o
	mv a.out profiled/$*.o
E 19
I 19
	@${CC} -p ${CFLAGS} -c $*.c
	@-ld -X -o profiled/$*.o -r $*.o
E 19
	${CC} ${CFLAGS} -c $*.c
D 2
	-ld -X -r $*.o
E 2
I 2
D 19
	-ld -x -r $*.o
E 2
	mv a.out $*.o
E 19
I 19
	@-ld -x -r $*.o
	@mv a.out $*.o
E 19

D 3
.s.o:
	sed -f ../mcount.sed $*.s | ${AS} -o $*.o
	-ld -X -r $*.o
	mv a.out profiled/$*.o
	${AS} -o $*.o $*.s
D 2
	-ld -X -r $*.o
E 2
I 2
	-ld -x -r $*.o
E 2
	mv a.out $*.o

E 3
D 19
stdiolib stdiolib_p: ${OBJS}
D 5
	ar cru stdiolib ${OBJS}
	cd profiled; ar cru ../stdiolib_p ${OBJS}
E 5
I 5
	@echo "building profiled stdiolib"
	@cd profiled; ar cru ../stdiolib_p ${OBJS}
	@echo "building normal stdiolib"
	@ar cru stdiolib ${OBJS}
E 19
I 19
all: lib.${MACHINE}
E 19
E 5

I 12
D 19
tags:
E 19
I 19
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


lib.vax: ${STDOBJ} ${VAXOBJ}

lib.tahoe: ${STDOBJ} ${TAHOEOBJ}

tags: tags.${MACHINE}

tags.vax:
E 19
	cwd=`pwd`; \
D 19
	for i in ${SRCS}; do \
E 19
I 19
	for i in ${STDSRC} ${VAXSRC}; do \
E 19
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

I 19
tags.tahoe:
	cwd=`pwd`; \
	for i in ${STDSRC} ${TAHOESRC}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

E 19
E 12
clean:
D 12
	rm -f stdiolib stdiolib_p ${OBJS} profiled/*.o
E 12
I 12
D 17
	rm -f stdiolib stdiolib_p ${OBJS} profiled/*.o tags
E 17
I 17
D 18
	rm -f stdiolib stdiolib_p *.o profiled/*.o tags Makefile.bak
E 18
I 18
D 19
	rm -f stdiolib stdiolib_p *.o profiled/*.o tags
E 19
I 19
	rm -f *.o profiled/* a.out core ${TAGSFILE}
E 19
E 18

D 19
depend:
D 18
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
E 18
I 18
	mkdep ${CFLAGS} ${SRCS}
E 19
I 19
depend: depend.${MACHINE}
E 19
E 18

I 19
depend.vax: ${STDSRC} ${VAXSRC}
	mkdep ${CFLAGS} ${STDSRC} ${VAXSRC}

depend.tahoe: ${STDSRC} ${TAHOESRC}
	mkdep ${CFLAGS} ${STDSRC} ${TAHOESRC}

E 19
D 18
# DO NOT DELETE THIS LINE -- make depend uses it
E 18
I 18
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 18

clrerr.o: clrerr.c /usr/include/stdio.h
I 19
doprnt.o: doprnt.c /usr/include/sys/types.h /usr/include/varargs.h
doprnt.o: /usr/include/stdio.h /usr/include/ctype.h
E 19
doscan.o: doscan.c /usr/include/stdio.h /usr/include/ctype.h
exit.o: exit.c
fdopen.o: fdopen.c /usr/include/sys/types.h /usr/include/sys/file.h
fdopen.o: /usr/include/stdio.h
fgetc.o: fgetc.c /usr/include/stdio.h
filbuf.o: filbuf.c /usr/include/stdio.h /usr/include/sys/types.h
filbuf.o: /usr/include/sys/stat.h
D 18
findiop.o: findiop.c /usr/include/stdio.h
E 18
I 18
findiop.o: findiop.c /usr/include/stdio.h /usr/include/errno.h
E 18
flsbuf.o: flsbuf.c /usr/include/stdio.h /usr/include/sys/types.h
flsbuf.o: /usr/include/sys/stat.h
fopen.o: fopen.c /usr/include/sys/types.h /usr/include/sys/file.h
fopen.o: /usr/include/stdio.h
fprintf.o: fprintf.c /usr/include/stdio.h
fputc.o: fputc.c /usr/include/stdio.h
fread.o: fread.c /usr/include/stdio.h
freopen.o: freopen.c /usr/include/sys/types.h /usr/include/sys/file.h
freopen.o: /usr/include/stdio.h
fseek.o: fseek.c /usr/include/stdio.h
ftell.o: ftell.c /usr/include/stdio.h
fwrite.o: fwrite.c /usr/include/stdio.h
getchar.o: getchar.c /usr/include/stdio.h
getw.o: getw.c /usr/include/stdio.h
printf.o: printf.c /usr/include/stdio.h
putchar.o: putchar.c /usr/include/stdio.h
putw.o: putw.c /usr/include/stdio.h
D 19
rew.o: rew.c /usr/include/stdio.h
E 19
I 19
rew.o: rew.c /usr/include/sys/types.h /usr/include/sys/file.h
rew.o: /usr/include/stdio.h
E 19
scanf.o: scanf.c /usr/include/stdio.h
setbuf.o: setbuf.c /usr/include/stdio.h
setbuffer.o: setbuffer.c /usr/include/stdio.h
D 19
sibuf.o: sibuf.c /usr/include/stdio.h
sobuf.o: sobuf.c /usr/include/stdio.h
E 19
sprintf.o: sprintf.c /usr/include/stdio.h
D 19
strout.o: strout.c /usr/include/stdio.h
E 19
ungetc.o: ungetc.c /usr/include/stdio.h
I 19
fgets.o: fgets.c /usr/include/stdio.h
fputs.o: fputs.c /usr/include/stdio.h
gets.o: gets.c /usr/include/stdio.h
puts.o: puts.c /usr/include/stdio.h
E 19
D 18
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 18
I 18

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 18
E 17
E 12
D 6

doprnt.o: doprnt.s
	cp doprnt.s doprnt.c
	cc -E doprnt.c | sed -f mcount.sed | as -o doprnt.o
D 3
	-ld -X -r doprnt.o
E 3
I 3
	-ld -x -r doprnt.o
E 3
	mv a.out profiled/doprnt.o
	cc -E doprnt.c | as -o doprnt.o
D 2
	-ld -X -r doprnt.o
E 2
I 2
	-ld -x -r doprnt.o
E 2
	mv a.out doprnt.o
	rm -f doprnt.c
E 6
E 1
