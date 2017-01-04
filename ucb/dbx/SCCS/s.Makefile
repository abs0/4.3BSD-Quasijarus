h45095
s 00001/00001/00237
d D 5.12 88/06/10 17:33:24 bostic 27 26
c owner bin, not root
e
s 00026/00019/00212
d D 5.11 88/01/11 23:34:56 donn 26 25
c merge in latest Linton version
e
s 00001/00000/00230
d D 5.10 88/01/07 13:44:44 bostic 25 24
c clean test directory
e
s 00001/00001/00229
d D 5.9 87/12/01 20:21:06 bostic 24 22
c date.o is a binary file
e
s 00001/00001/00229
d R 5.9 87/06/16 18:15:15 bostic 23 22
c fixed install
e
s 00002/00000/00228
d D 5.8 87/05/31 21:08:22 bostic 22 21
c added depend label
e
s 00000/00001/00228
d D 5.7 87/05/24 14:40:47 bostic 21 20
c MACHINE defined in Makefile
e
s 00001/00002/00228
d D 5.6 86/10/14 21:45:58 mckusick 20 18
c must specify machine
e
s 00001/00002/00228
d R 5.6 86/10/14 21:27:27 mckusick 19 18
c must specify machine
e
s 00001/00001/00229
d D 5.5 86/02/23 20:33:14 sam 18 17
c runtime is also machine-dependent
e
s 00024/00005/00206
d D 5.4 86/02/23 16:21:58 sam 17 15
c parameterize files for machine independence
e
s 00019/00004/00207
d R 5.4 86/02/22 22:24:29 sam 16 15
c update sccsid
e
s 00002/00001/00209
d D 5.3 85/10/09 10:23:51 bloom 15 14
c add DESTDIR for installation
e
s 00008/00005/00202
d D 5.2 85/06/18 18:32:42 bloom 14 13
c Change Maintainer and use optimizer
e
s 00006/00001/00201
d D 5.1 85/05/31 09:51:54 dist 13 12
c Add copyright
e
s 00141/00036/00061
d D 4.11 85/03/01 20:18:10 linton 12 11
c update to version 3.0
e
s 00036/00133/00061
d D 4.10 84/08/17 21:25:15 sam 11 10
c cleanup some linton'isms
e
s 00003/00001/00191
d D 4.9 84/06/23 11:39:14 sam 10 8
i 9
c merge linton branch delta trail
e
s 00022/00015/00167
d D 4.7.1.1 84/06/23 10:44:20 sam 9 7
c branch delta of linton changes from net.sources
e
s 00003/00000/00182
d D 4.8 84/06/23 10:39:29 sam 8 7
c add re pattern search of source code
e
s 00001/00001/00181
d D 4.7 84/01/03 16:14:01 sam 7 6
c leave -g on for debugging, installed version should be stripped anyway
e
s 00041/00001/00141
d D 4.6 83/07/15 14:46:42 linton 6 5
c fixed "clean" so that extraneous files are now removed 
c that were not done so previously, also added "tape" for generating 
c a tar tape of the dbx source
e
s 00003/00000/00139
d D 4.5 83/05/18 18:17:51 csvaf 5 4
c Added fortran and debugger source files
e
s 00001/00001/00138
d D 4.4 83/05/17 23:04:10 linton 4 3
c now installs with symbol table (helpful for debugging dbx)
e
s 00010/00003/00129
d D 4.3 83/03/31 00:21:02 linton 3 2
c changed way "date.c" is created
e
s 00004/00004/00128
d D 4.2 83/02/21 10:57:49 linton 2 1
c changed DEST and DESTDIR interaction so installed in /usr/ucb/dbx rather than //usr/ucb/dbx
e
s 00132/00000/00000
d D 4.1 83/02/11 13:03:57 sam 1 0
c date and time created 83/02/11 13:03:57 by sam
e
u
U
f b 
t
T
I 10
D 13
#	%M%	%I%	%E%
E 13
I 13
#
# Copyright (c) 1983 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 13
E 10
I 1
D 9
#	%W% (Berkeley) %G%
E 9
#
# make file for debugger "dbx"
#
# The file "defs.h" is included by all.
#
I 11
D 12
AOUT=	tdbx
DESTDIR=
DEST=	${DESTDIR}/usr/ucb/dbx
LIBS=	
CFLAGS=	-O
YFLAGS=	-d
LDFLAGS=
HDR=	asm.h events.h c.h check.h coredump.h eval.h fortran.h keywords.h \
	languages.h lists.h machine.h main.h mappings.h modula-2.h names.h \
	object.h operators.h pascal.h printsym.h process.h re.h \
	runtime.h scanner.h source.h stabstring.h symbols.h tree.h ops.h
SRCS=	asm.c events.c c.c cerror.s check.c coredump.c debug.c eval.c \
	fortran.c keywords.c languages.c library.c lists.c machine.c main.c \
	mappings.c modula-2.c names.c object.c operators.c pascal.c printsym.c \
	process.c re.c runtime.c scanner.c source.c symbols.c tree.c ops.c
OBJS=	y.tab.o asm.o events.o c.o cerror.o check.o coredump.o \
	debug.o eval.o fortran.o keywords.o languages.o library.o \
	lists.o machine.o main.o mappings.o modula-2.o names.o \
	object.o operators.o pascal.o printsym.o process.o re.o \
	runtime.o scanner.o source.o stabstring.o symbols.o tree.o \
	ops.o
E 12
E 11
D 9
# N.B.:
#    My version of cerror automatically catches certain errors
# such as out of memory, I/O error.  If you re-make this with
# the standard cerror, the program could fault unexpectedly.
#
E 9

.SUFFIXES:
.SUFFIXES: .h .c .s .o

I 17
D 20
#MACHINE	= vax
MACHINE	= tahoe
E 20
I 20
D 21
MACHINE	= unknown
E 21
E 20
E 17
I 12
AOUT	= tdbx
I 15
DESTDIR	=
E 15
DEST	= /usr/ucb/dbx

I 14
D 26
# Install the mail address of the person maintaining dbx below
# as -DMAINTAINER.  A null string disables gripes.

E 26
E 14
CC	= cc
D 14
CFLAGS	= '-DMAINTAINER="linton@shasta"' -g
E 14
I 14
D 26
CFLAGS	= '-DMAINTAINER=""' -O
E 26
I 26
AS	= as
#
# if you want gripes
# CFLAGS = -g '-DMAINTAINER="linton@shasta.stanford.edu"'
#
CFLAGS	= -O # -g
E 26
E 14

LD = cc
D 14
LDFLAGS	= -g
E 14
I 14
D 26
LDFLAGS	= 
E 14
LIBRARIES =
E 26
I 26
LDFLAGS	= # -g
LIBRARIES = # -lPW for IRIS (System V)
E 26

D 26
# LD	= /bin/oldld
# LDFLAGS	= -X /lib/crt0.o
# LIBRARIES = -lg -lc

E 26
OBJ = \
    y.tab.o \
    asm.o \
    events.o \
    c.o \
    cerror.o \
    check.o \
    coredump.o \
    debug.o \
    eval.o \
    fortran.o \
    keywords.o \
    languages.o \
    library.o \
    lists.o \
    machine.o \
    main.o \
    mappings.o \
    modula-2.o \
    names.o \
    object.o \
    operators.o \
    pascal.o \
    printsym.o \
    process.o \
    runtime.o \
    scanner.o \
    source.o \
    stabstring.o \
    symbols.o \
    tree.o \
    ops.o

HDR = \
    asm.h \
    events.h \
    c.h \
    check.h \
    coredump.h \
    debug.h \
    eval.h \
    fortran.h \
    keywords.h \
    languages.h \
    lists.h \
    machine.h \
    main.h \
    mappings.h \
    modula-2.h \
    names.h \
    object.h \
    operators.h \
    pascal.h \
    printsym.h \
    process.h \
    runtime.h \
    scanner.h \
    source.h \
    stabstring.h \
    symbols.h \
    tree.h \
    ops.h

SRC = \
    defs.h \
    commands.y \
    asm.c \
    events.c \
    c.c \
D 17
    cerror.s \
E 17
I 17
    cerror.${MACHINE}.s \
E 17
    check.c \
    coredump.c \
    debug.c \
    eval.c \
    fortran.c \
    keywords.c \
    languages.c \
    library.c \
    lists.c \
D 17
    machine.c \
E 17
    main.c \
    mappings.c \
    modula-2.c \
    names.c \
    object.c \
    operators.c \
    pascal.c \
    printsym.c \
    process.c \
D 17
    runtime.c \
E 17
    scanner.c \
    source.c \
    stabstring.c \
    symbols.c \
    tree.c \
D 17
    ops.c
E 17
I 17
    ${MACHINE}.c \
    runtime.${MACHINE}.c \
    ops.${MACHINE}.c
E 17

E 12
D 11
AOUT	= tdbx
D 2
DEST	= /usr/ucb/dbx
DESTDIR	=
E 2
I 2
D 9
DESTDIR =
DEST	= ${DESTDIR}/usr/ucb/dbx
E 9
I 9
D 10
DEST	= /usr/local/bin/dbx
E 10
I 10
DESTDIR=
DEST	= ${DESTDIR}/usr/ucb/dbx
E 10
E 9
E 2

LIBRARIES =

CC	= cc
D 7
CFLAGS	= # -g
E 7
I 7
CFLAGS	= -g
E 7
D 2
LDFLAGS	= # -g
E 2
I 2
LDFLAGS	= -g
E 2

OBJ = \
    y.tab.o \
    asm.o \
    events.o \
    c.o \
    cerror.o \
    check.o \
    coredump.o \
I 5
    debug.o \
E 5
    eval.o \
I 5
    fortran.o \
E 5
    keywords.o \
    languages.o \
    library.o \
    lists.o \
    machine.o \
    main.o \
    mappings.o \
I 9
    modula-2.o \
E 9
    names.o \
    object.o \
    operators.o \
    pascal.o \
    printsym.o \
    process.o \
I 8
    re.o \
E 8
    runtime.o \
    scanner.o \
    source.o \
I 9
    stabstring.o \
E 9
    symbols.o \
    tree.o \
    ops.o

HDR = \
    asm.h \
    events.h \
    c.h \
    check.h \
    coredump.h \
    eval.h \
I 5
    fortran.h \
E 5
    keywords.h \
    languages.h \
    lists.h \
    machine.h \
    main.h \
    mappings.h \
I 9
    modula-2.h \
E 9
    names.h \
    object.h \
    operators.h \
    pascal.h \
    printsym.h \
    process.h \
I 8
    re.h \
E 8
    runtime.h \
D 9
    source.h \
E 9
    scanner.h \
I 9
    source.h \
    stabstring.h \
E 9
    symbols.h \
    tree.h \
    ops.h

I 6
SRC = \
    defs.h \
    commands.y \
    asm.c \
    events.c \
    c.c \
    cerror.s \
    check.c \
    coredump.c \
    debug.c \
    eval.c \
    fortran.c \
    keywords.c \
    languages.c \
    library.c \
    lists.c \
    machine.c \
    main.c \
    mappings.c \
I 9
    modula-2.c \
E 9
    names.c \
    object.c \
    operators.c \
    pascal.c \
    printsym.c \
    process.c \
I 8
    re.c \
E 8
    runtime.c \
    scanner.c \
    source.c \
    symbols.c \
    tree.c \
    ops.c

E 11
E 6
.c.o:
D 11
	@echo "compiling $*.c"
	@${CC} ${CFLAGS} -c $*.c
E 11
I 11
D 12
	${CC} ${CFLAGS} -c $*.c
E 12
I 12
	@echo "compiling $*.c"
	@${CC} ${CFLAGS} -c $*.c
E 12
E 11

.s.o:
D 11
	@echo "assembling $*.s"
	@${CC}  -c $*.s
E 11
I 11
D 12
	${CC} -c $*.s
E 12
I 12
	@echo "assembling $*.s"
D 26
	@${CC}  -c $*.s
E 26
I 26
	@rm -f tmp
	@/lib/cpp $*.s | grep -v "^#" > tmp
	@${AS} -o $*.o tmp
	@rm -f tmp
E 26
E 12
E 11

.c.h:
D 11
	./makedefs -f $*.c $*.h
E 11
I 11
D 12
	@./makedefs -f $*.c $*.h
E 12
I 12
	./makedefs -f $*.c $*.h
E 12
E 11

D 3
${AOUT}: makedefs ${HDR} ${OBJ}
E 3
I 3
D 11
${AOUT}: makedefs mkdate ${HDR} ${OBJ}
E 11
I 11
D 12
${AOUT}: makedefs mkdate ${HDR} ${OBJS}
E 12
I 12
${AOUT}: makedefs mkdate ${HDR} ${OBJ}
E 12
E 11
	@rm -f date.c
	@./mkdate > date.c
E 3
	@echo "linking"
D 3
	@${CC} ${LDFLAGS} ${OBJ} ${LIBRARIES} -o ${AOUT}
E 3
I 3
D 11
	@${CC} ${LDFLAGS} date.c ${OBJ} ${LIBRARIES} -o ${AOUT}
E 11
I 11
D 12
	@${CC} ${LDFLAGS} date.c ${OBJS} ${LIBS} -o ${AOUT}
E 12
I 12
	@${CC} ${CFLAGS} -c date.c
	@${LD} ${LDFLAGS} date.o ${OBJ} ${LIBRARIES} -o ${AOUT}
E 12
E 11
E 3

D 11
profile: ${HDR} ${OBJ}
E 11
I 11
D 12
profile: ${HDR} ${OBJS}
E 12
I 12
profile: ${HDR} ${OBJ}
E 12
E 11
I 3
	@rm -f date.c
	@./mkdate > date.c
E 3
	@echo "linking with -p"
D 3
	@${CC} ${LDFLAGS} -p ${OBJ} ${LIBRARIES} -o ${AOUT}
E 3
I 3
D 11
	@${CC} ${LDFLAGS} -p date.c ${OBJ} ${LIBRARIES} -o ${AOUT}
E 11
I 11
D 12
	@${CC} ${LDFLAGS} -p date.c ${OBJS} ${LIBS} -o ${AOUT}
E 12
I 12
	@${CC} ${LDFLAGS} -p date.c ${OBJ} ${LIBRARIES} -o ${AOUT}
E 12
E 11
E 3

y.tab.c: commands.y
I 9
	@echo "expect 2 shift/reduce conflicts"
E 9
D 11
	yacc -d commands.y
E 11
I 11
D 12
	${YACC} ${YFLAGS} commands.y
E 12
I 12
	yacc -d commands.y
E 12
E 11

I 17
cerror.s: cerror.${MACHINE}.s
	@rm -f cerror.s
	@ln -s cerror.${MACHINE}.s cerror.s

machine.c: ${MACHINE}.c
	@rm -f machine.c
	@ln -s ${MACHINE}.c machine.c

ops.c:	ops.${MACHINE}.c
	@rm -f ops.c
	@ln -s ops.${MACHINE}.c ops.c

runtime.c: runtime.${MACHINE}.c
	@rm -f runtime.c
	@ln -s runtime.${MACHINE}.c runtime.c

E 17
makedefs: makedefs.c library.o cerror.o
D 9
	${CC} makedefs.c library.o cerror.o -o makedefs
E 9
I 9
D 11
	${CC} -g makedefs.c library.o cerror.o -o makedefs
E 11
I 11
D 12
	${CC} ${CFLAGS} ${LDFLAGS} makedefs.c library.o cerror.o -o makedefs
E 12
I 12
D 14
	${CC} -g makedefs.c library.o cerror.o -o makedefs
E 14
I 14
D 26
	${CC} -O makedefs.c library.o cerror.o -o makedefs
E 26
I 26
	${CC} -g makedefs.c library.o cerror.o -o makedefs
E 26
E 14
E 12
E 11
E 9
I 3

mkdate: mkdate.c
D 9
	${CC} mkdate.c -o mkdate
E 9
I 9
D 11
	${CC} -g mkdate.c -o mkdate
E 11
I 11
D 12
	${CC} ${CFLAGS} ${LDFLAGS} mkdate.c -o mkdate
E 12
I 12
D 14
	${CC} -g mkdate.c -o mkdate
E 14
I 14
D 26
	${CC} -O mkdate.c -o mkdate
E 26
I 26
	${CC} -g ${CFLAGS} mkdate.c -o mkdate
E 26
E 14
E 12
E 11
E 9
E 3

print:
	@echo "don't print it, it's too long"

I 22
depend:

E 22
#
# Don't worry about the removal of header files, they're created from
# the source files.
#
I 12

E 12
D 11

E 11
clean:
D 6
	rm -f ${HDR} ${OBJ} y.tab.c y.tab.h ${AOUT} core
E 6
I 6
D 9
	rm -f ${HDR} ${OBJ} y.tab.c y.tab.h \
	    ${AOUT} mkdate mkdate.o makedefs makedefs.o date.c core
E 9
I 9
D 11
	rm -f ${HDR} ${OBJ} y.tab.c y.tab.h ${AOUT} \
	    mkdate mkdate.o makedefs makedefs.o date.c core mon.out prof.out
E 11
I 11
D 12
	rm -f ${HDR} ${OBJS} y.tab.c y.tab.h ${AOUT} \
	    mkdate mkdate.o makedefs makedefs.o date.c core mon.out \
	    prof.out errs
E 12
I 12
	rm -f ${HDR} ${OBJ} y.tab.c y.tab.h ${AOUT} mkdate mkdate.o \
D 17
	    makedefs makedefs.o date.c core mon.out prof.out make.out
E 17
I 17
	    makedefs makedefs.o date.c core mon.out prof.out make.out \
D 18
	    cerror.s ops.c machine.c
E 18
I 18
D 24
	    cerror.s ops.c machine.c runtime.c
E 24
I 24
	    cerror.s ops.c machine.c runtime.c date.o
I 25
	@chdir tests; make clean
E 25
E 24
E 18
E 17
E 12
E 11
E 9
E 6

I 12
cleandefs:
	rm -f ${HDR} y.tab.h

E 12
D 9
install:
E 9
I 9
testinstall: ${AOUT} test install

test:
D 26
	@chdir tests; make
E 26
I 26
	@cd tests; make
E 26

install: ${AOUT}
E 9
D 2
	install -s ${AOUT} ${DESTDIR}/${DEST}
E 2
I 2
D 4
	install -s ${AOUT} ${DEST}
E 4
I 4
D 14
	install ${AOUT} ${DEST}
E 14
I 14
D 15
	install -s ${AOUT} ${DEST}
E 15
I 15
D 26
	install -s ${AOUT} ${DESTDIR}/${DEST}
E 26
I 26
D 27
	install -s ${AOUT} ${DESTDIR}${DEST}
E 27
I 27
	install -s -o bin -g bin -m 755 ${AOUT} ${DESTDIR}${DEST}
E 27
E 26
E 15
E 14
I 6

D 11
#
# Create a tar file called "tape" containing relevant files.
#
E 11
I 11
D 12
tags:	defs.h ${SRCS}
	ctags -w defs.h ${SRCS}
E 12
I 12
#
# Create a tar file called "tape" containing relevant files.
#
E 12
E 11

I 12
D 26
TAPE = tape
E 26
I 26
TAPE = f tape
E 26

tape:
D 26
	@tar cf ${TAPE} \
	    Makefile History version READ_ME ${SRC} \
	    makedefs.c mkdate.c tests pchanges ptests
E 26
I 26
	@tar c${TAPE} Makefile History READ_ME ${SRC} \
	    makedefs.c mkdate.c tests pc0mods dbx.1 newdbx.1 dbxstab.5

#
# without tests subdirectory
#
srconlytape:
	@tar c${TAPE} Makefile History READ_ME ${SRC} \
	    makedefs.c mkdate.c dbx.1 newdbx.1 dbxstab.5
E 26

E 12
I 9
D 11
TAPE = tape

E 9
tape:
D 9
	tar cfv tape Makefile READ_ME TO_DO ${SRC} makedefs.c mkdate.c
E 9
I 9
	tar cfv ${TAPE} \
	    Makefile ${SRC} makedefs.c mkdate.c tests/ pchanges ptests
E 9
E 6
E 4
E 2

E 11
#
# Header dependencies are purposely incomplete since header files
# are "written" every time the accompanying source file changes even if
# the resulting contents of the header don't change.  The alternative is
# to force a "makedefs" to be invoked for every header file each time dbx
# is made.
#
# Also, there should be a dependency of scanner.o and keywords.o on y.tab.h
# but misfortunately silly make does a "makedefs y.tab.c y.tab.h" which
# destroys y.tab.h.
#
I 12

E 12
D 11

E 11
symbols.o tree.o check.o eval.o events.o: operators.h
E 1
