h63681
s 00005/00010/00264
d D 5.3 87/10/27 07:47:03 bostic 20 17
c fix depend label
e
s 00078/00195/00079
d R 5.3 87/10/26 08:23:37 bostic 19 17
c fix depend label
e
s 00003/00003/00271
d R 5.3 87/10/26 07:53:15 bostic 18 17
c don't use bin/grep, it's not there
e
s 00002/00002/00272
d D 5.2 85/09/07 15:52:09 mckusick 17 16
c eyacc moves; strip on install
e
s 00007/00000/00267
d D 5.1 85/06/05 15:59:32 dist 16 15
c Add copyright
e
s 00000/00004/00267
d D 2.3 85/01/10 18:01:56 mckusick 15 14
c make depend
e
s 00031/00009/00240
d D 2.2 85/01/09 18:15:00 mckusick 14 13
c share subr.c and string.c with pi/pc
e
s 00000/00000/00249
d D 2.1 84/02/08 20:22:37 aoki 13 12
c synchronizing at version 2
e
s 00001/00001/00248
d D 1.12 83/09/12 17:16:01 karels 12 11
c install uses install
e
s 00000/00003/00249
d D 1.11 83/05/31 20:08:05 peter 11 10
c oops.  make depend after nl.c moves to ../src to be common with pi/pc0.
e
s 00008/00003/00244
d D 1.10 83/05/31 18:39:05 peter 10 9
c nl.c becomes common with pi/pc0.
e
s 00005/00002/00242
d D 1.9 83/05/12 13:58:00 peter 9 8
c add rmothers and make depend.
e
s 00021/00008/00223
d D 1.8 83/05/11 21:49:53 peter 8 7
c yyget.c becomes shared with pi.  make depend.
e
s 00162/00085/00069
d D 1.7 83/02/06 13:37:27 mckusick 7 6
c update to split out shared sources
e
s 00103/00001/00051
d D 1.6 82/09/09 21:07:11 peter 6 5
c make depend and y.tab.h entries; plus the result of a make depend.
e
s 00001/00001/00051
d D 1.5 82/08/29 23:36:27 mckusick 5 4
c output of eyacc to /dev/null
e
s 00006/00001/00046
d D 1.4 82/08/13 15:32:22 peter 4 3
c use new char version[]; add `make newversion' entry.
e
s 00006/00007/00041
d D 1.3 82/08/11 23:15:44 mckusick 3 2
c restore creation of y.tab.c
e
s 00001/00001/00047
d D 1.2 81/03/05 20:16:27 peter 2 1
c install depends on a.out
e
s 00048/00000/00000
d D 1.1 81/03/02 21:28:26 peter 1 0
c date and time created 81/03/02 21:28:26 by peter
e
u
U
t
T
I 16
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 16
I 1
SCCSID = "%W% (Berkeley) %G%"
DESTDIR=
D 3
ED=	-ed
E 3
I 3
ED=	-ex
E 3
AS=	-as
I 7
RM=	rm -f
E 7
D 4
VERSION= version
E 4
D 17
EYACC=	/usr/ucb/eyacc
E 17
I 17
EYACC=	../eyacc/eyacc
E 17
D 7
CFLAGS=	-O -DPXP -w
OBJS=	call.o case.o const.o cset.o \
	error.o fdec.o func.o hash.o lab.o lval.o \
	main.o nl.o pmon.o pp.o proc.o rec.o rval.o \
	stat.o string.o subr.o tree.o type.o var.o y.tab.o \
	yycomm.o yycosts.o yyerror.o yyget.o yyid.o yylex.o yymain.o \
	yypanic.o yyparse.o yyprint.o yyput.o yyrecover.o \
	yyseman.o yytree.o
OBJS2=	doprnt.o printf.o treen.o yycopy.o TRdata.o Version.o
E 7
I 7
D 9
CFLAGS=	-O -I. -I${SRCDIR} -w
E 9
I 9
CFLAGS=	-O -I. -I${SRCDIR} -w -DRMOTHERS
E 9
SRCDIR=	../src
BINDIR=	../pxp
#
# Files which are specific to PXP
#
LOCOBJ=	Version.o call.o case.o const.o cset.o error.o fdec.o func.o \
D 10
	lab.o lval.o main.o nl.o pmon.o pp.o proc.o rec.o rval.o stat.o \
E 10
I 10
	lab.o lval.o main.o pmon.o pp.o proc.o rec.o rval.o stat.o \
E 10
D 8
	string.o subr.o type.o var.o y.tab.o yycomm.o yyerror.o yyget.o \
E 8
I 8
D 14
	string.o subr.o type.o var.o y.tab.o yycomm.o yyerror.o \
E 14
I 14
	type.o var.o y.tab.o yycomm.o yyerror.o \
E 14
E 8
D 9
	yymain.o yyput.o
E 9
I 9
	yymain.o yyput.o rmothers.o
E 9
#
# Files which are shared with pi and pc0
#
D 8
SRCOBJ=	TRdata.o hash.o tree.o treen.o yycopy.o yycosts.o yyid.o yylex.o \
	yypanic.o yyparse.o yyprint.o yyrecover.o yyseman.o yytree.o
SRCSRC=	TRdata.c hash.c tree.c treen.c yycopy.c yycosts.c yyid.c yylex.c \
	yypanic.c yyparse.c yyprint.c yyrecover.c yyseman.c yytree.c
E 8
I 8
D 10
SRCOBJ=	TRdata.o hash.o tree.o treen.o yycopy.o yycosts.o yyget.o \
E 10
I 10
D 14
SRCOBJ=	TRdata.o hash.o nl.o tree.o treen.o yycopy.o yycosts.o yyget.o \
E 10
	yyid.o yylex.o yypanic.o yyparse.o yyprint.o yyrecover.o \
	yyseman.o yytree.o
D 10
SRCSRC=	TRdata.c hash.c tree.c treen.c yycopy.c yycosts.c yyget.c \
E 10
I 10
SRCSRC=	TRdata.c hash.c nl.c tree.c treen.c yycopy.c yycosts.c yyget.c \
E 10
	yyid.c yylex.c yypanic.c yyparse.c yyprint.c yyrecover.c \
	yyseman.c yytree.c
E 14
I 14
SRCOBJ=	TRdata.o hash.o nl.o string.o subr.o tree.o treen.o yycopy.o \
	yycosts.o yyget.o yyid.o yylex.o yypanic.o yyparse.o yyprint.o \
	yyrecover.o yyseman.o yytree.o
SRCSRC=	TRdata.c hash.c nl.c string.c subr.c tree.c treen.c yycopy.c \
	yycosts.c yyget.c yyid.c yylex.c yypanic.c yyparse.c yyprint.c \
	yyrecover.c yyseman.c yytree.c
E 14
E 8
E 7

all: a.out

D 7
a.out:	${OBJS} ${OBJS2}
D 3
	${CC} ${CFLAGS} -i ${OBJS} ${OBJS2}
E 3
I 3
	${CC} ${CFLAGS} ${OBJS} ${OBJS2}
E 7
I 7
a.out:	${LOCOBJ} ${SRCOBJ}
	${CC} ${CFLAGS} ${LOCOBJ} ${SRCOBJ}
E 7
E 3

D 7
doprnt.o: doprnt.c
	${CC} ${CFLAGS} -E doprnt.c > doprnt.s
	${AS} -o doprnt.o doprnt.s
	-rm -f doprnt.s
E 7
I 7
${SRCOBJ}:
	-ln ${SRCDIR}/$*.c $*.c
	${CC} ${CFLAGS} -c $*.c
	${RM} $*.c
E 7

D 3
#y.tab.c: pas.y
#	${EYACC} pas.y
#	${ED} - y.tab.c < gram
E 3
I 3
D 6
y.tab.c: pas.y
E 6
I 6
D 7
y.tab.h y.tab.c: pas.y
E 6
D 5
	${EYACC} pas.y
E 5
I 5
	${EYACC} pas.y >/dev/null
E 5
	${ED} - y.tab.c < gram
E 7
I 7
y.tab.h y.tab.c: ${SRCDIR}/pas.y
	${EYACC} ${SRCDIR}/pas.y >/dev/null
	${ED} - y.tab.c < ${SRCDIR}/gram
E 7
I 4

I 7
newversion: version
	version > Version.c

E 7
version: version.c Version.o
	cc -o version version.c Version.o

D 7
newversion: version
	version > Version.c
E 7
I 7
opcode.h: ${SRCDIR}/OPnames.h ${SRCDIR}/opc.c
	${RM} opcode.h
	cc ${SRCDIR}/opc.c -o opc
	./opc >opcode.h
	${RM} opc
E 7
E 4
E 3

clean:
D 7
	-rm -f pi1:2strings a.out core
D 3
	-echo dont rm y.tab.c
	-rm -f *.o x*
E 3
I 3
	-rm -f *.o x* y.tab.c y.tab.h
E 7
I 7
	-rm -f a.out core errs version *.bak
	-rm -f *.o x* y.tab.c y.tab.h opcode.h
E 7
E 3

D 2
install:
E 2
I 2
install: a.out
E 2
D 12
	cp a.out ${DESTDIR}/usr/ucb/pxp
E 12
I 12
D 17
	install a.out ${DESTDIR}/usr/ucb/pxp
E 17
I 17
	install -s a.out ${DESTDIR}/usr/ucb/pxp
E 17
E 12
#	cp a.outNOID /usr/ucb/pxp34

print:
D 7
	@pr makefile READ_ME
E 7
I 7
	@pr Makefile READ_ME
E 7
	@ls -ls | pr
	@size a.out *.o | pr
#	@cxref *.c | pr
D 7
	@pr 0.h main.c pas.y
E 7
I 7
	@pr 0.h main.c ${SRCDIR}/pas.y
E 7
	@pr yy.h yy*.c
	@pr [a-ln-x]*.c
#	@pr putn.s treen.s yycopy.s
I 6

D 20
depend:	
E 20
I 20
depend:
E 20
D 7
	/bin/grep '^#[ 	]*include' *.h \
		| sed '/<.*>/d' \
		| sed 's/\(.*\):[^"]*"\([^"]*\)".*/\1: \2/' >makedep
	/bin/grep '^#[ 	]*include' *.c \
		| sed '/<.*>/d' \
		| sed 's/:[^"]*"\([^"]*\)".*/: \1/' \
		| sed 's/\.c/.o/' >>makedep
E 7
I 7
	ls *.c | sed 's;^\([a-zA-Z0-9.]*\)\.c;\1.o: &;' >makedep
	cd ${SRCDIR}; ls ${SRCSRC} | sed \
		-e 's;^\([a-zA-Z0-9.]*\)\.c;\1.o: ${SRCDIR}/&;' \
		>>${BINDIR}/makedep
D 20
	/bin/grep '^#[ 	]*include' *.h ${SRCDIR}/*.h | sed \
E 20
I 20
	grep '^#[ 	]*include' *.h ${SRCDIR}/*.h | sed \
E 20
		-e '/<.*>/d' \
		-e 's;\(.*\):[^"]*"\([^"]*\)".*;\1: \2;' >>makedep
D 20
	cd ${SRCDIR}; /bin/grep '^#[ 	]*include' ${SRCSRC} | sed \
E 20
I 20
	cd ${SRCDIR}; grep '^#[ 	]*include' ${SRCSRC} | sed \
E 20
		-e '/<.*>/d' \
		-e 's;:[^"]*"\([^"]*\)".*;: ${SRCDIR}/\1;' \
		-e 's;^\([a-zA-Z0-9.]*\)\.c;\1.o;' \
		-e 's;: ${SRCDIR}/0.h;: 0.h;' \
		-e 's;: ${SRCDIR}/whoami.h;: whoami.h;' \
		-e 's;: ${SRCDIR}/opcode.h;: opcode.h;' >>${BINDIR}/makedep
D 20
	/bin/grep '^#[ 	]*include' *.c | sed \
E 20
I 20
	grep '^#[ 	]*include' *.c | sed \
E 20
		-e '/<.*>/d' \
		-e 's;:[^"]*"\([^"]*\)".*;: ${SRCDIR}/\1;' \
		-e 's;^\([a-zA-Z0-9.]*\)\.c;\1.o;' \
		-e 's;: ${SRCDIR}/0.h;: 0.h;' \
		-e 's;: ${SRCDIR}/whoami.h;: whoami.h;' \
		-e 's;: ${SRCDIR}/opcode.h;: opcode.h;' >>makedep
E 7
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
D 7
	cp makefile makefile.bak
	ed - makefile < eddep
E 7
I 7
	cp Makefile Makefile.bak
	ed - Makefile < eddep
E 7
	rm eddep makedep
D 7
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> makefile
	echo '# see make depend above' >> makefile
E 7
I 7
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 7

# DO NOT DELETE THIS LINE
# DEPENDENCIES MUST END AT END OF FILE
D 7
yy.h: y.tab.h
E 7
I 7
Version.o: Version.c
call.o: call.c
case.o: case.c
const.o: const.c
cset.o: cset.c
error.o: error.c
fdec.o: fdec.c
func.o: func.c
lab.o: lab.c
lval.o: lval.c
main.o: main.c
D 11
nl.o: nl.c
E 11
pmon.o: pmon.c
pp.o: pp.c
proc.o: proc.c
rec.o: rec.c
I 9
rmothers.o: rmothers.c
E 9
rval.o: rval.c
stat.o: stat.c
D 15
string.o: string.c
E 15
D 14
subr.o: subr.c
E 14
type.o: type.c
var.o: var.c
version.o: version.c
I 8
D 20
y.tab.o: y.tab.c
E 20
E 8
yycomm.o: yycomm.c
yyerror.o: yyerror.c
D 8
yyget.o: yyget.c
E 8
yymain.o: yymain.c
yyput.o: yyput.c
TRdata.o: ../src/TRdata.c
hash.o: ../src/hash.c
I 10
nl.o: ../src/nl.c
I 14
string.o: ../src/string.c
subr.o: ../src/subr.c
E 14
E 10
tree.o: ../src/tree.c
treen.o: ../src/treen.c
yycopy.o: ../src/yycopy.c
yycosts.o: ../src/yycosts.c
I 8
yyget.o: ../src/yyget.c
E 8
yyid.o: ../src/yyid.c
yylex.o: ../src/yylex.c
yypanic.o: ../src/yypanic.c
yyparse.o: ../src/yyparse.c
yyprint.o: ../src/yyprint.c
yyrecover.o: ../src/yyrecover.c
yyseman.o: ../src/yyseman.c
yytree.o: ../src/yytree.c
../src/yy.h: y.tab.h
E 7
TRdata.o: whoami.h
TRdata.o: 0.h
I 7
hash.o: whoami.h
hash.o: 0.h
I 14
hash.o: ../src/tree_ty.h
E 14
hash.o: ../src/yy.h
I 10
nl.o: whoami.h
nl.o: 0.h
nl.o: opcode.h
nl.o: ../src/objfmt.h
I 14
string.o: whoami.h
I 20
string.o: ../src/align.h
E 20
string.o: 0.h
string.o: ../src/send.h
subr.o: whoami.h
subr.o: 0.h
E 14
E 10
tree.o: whoami.h
tree.o: 0.h
I 14
treen.o: 0.h
treen.o: ../src/tree_ty.h
E 14
I 8
yycopy.o: whoami.h
E 8
yycopy.o: 0.h
I 14
yycopy.o: ../src/tree_ty.h
E 14
yycopy.o: ../src/yy.h
yycosts.o: whoami.h
yycosts.o: 0.h
I 14
yycosts.o: ../src/tree_ty.h
E 14
yycosts.o: ../src/yy.h
I 8
yyget.o: whoami.h
yyget.o: 0.h
I 14
yyget.o: ../src/tree_ty.h
E 14
yyget.o: ../src/yy.h
E 8
yyid.o: whoami.h
yyid.o: 0.h
I 14
yyid.o: ../src/tree_ty.h
E 14
yyid.o: ../src/yy.h
yylex.o: whoami.h
yylex.o: 0.h
I 14
yylex.o: ../src/tree_ty.h
E 14
yylex.o: ../src/yy.h
yypanic.o: whoami.h
yypanic.o: 0.h
I 14
yypanic.o: ../src/tree_ty.h
E 14
yypanic.o: ../src/yy.h
yyparse.o: whoami.h
yyparse.o: 0.h
I 14
yyparse.o: ../src/tree_ty.h
E 14
yyparse.o: ../src/yy.h
yyprint.o: whoami.h
yyprint.o: 0.h
I 14
yyprint.o: ../src/tree_ty.h
E 14
yyprint.o: ../src/yy.h
yyrecover.o: whoami.h
yyrecover.o: 0.h
I 14
yyrecover.o: ../src/tree_ty.h
E 14
yyrecover.o: ../src/yy.h
yyseman.o: whoami.h
yyseman.o: 0.h
I 14
yyseman.o: ../src/tree_ty.h
E 14
yyseman.o: ../src/yy.h
yytree.o: whoami.h
yytree.o: 0.h
yytree.o: ../src/tree.h
I 14
yytree.o: ../src/tree_ty.h
E 14
E 7
call.o: 0.h
D 7
call.o: tree.h
E 7
I 7
call.o: ../src/tree.h
E 7
case.o: 0.h
D 7
case.o: tree.h
E 7
I 7
case.o: ../src/tree.h
E 7
const.o: 0.h
D 7
const.o: tree.h
E 7
I 7
const.o: ../src/tree.h
E 7
cset.o: 0.h
D 7
cset.o: tree.h
E 7
I 7
cset.o: ../src/tree.h
I 8
error.o: whoami.h
E 8
E 7
error.o: 0.h
D 7
error.o: yy.h
E 7
I 7
error.o: ../src/yy.h
E 7
fdec.o: 0.h
D 7
fdec.o: tree.h
E 7
I 7
fdec.o: ../src/tree.h
E 7
func.o: 0.h
D 7
func.o: tree.h
hash.o: whoami.h
hash.o: 0.h
hash.o: yy.h
E 7
I 7
func.o: ../src/tree.h
E 7
lab.o: 0.h
lval.o: 0.h
D 7
lval.o: tree.h
E 7
I 7
lval.o: ../src/tree.h
E 7
main.o: 0.h
D 11
nl.o: 0.h
nl.o: opcode.h
E 11
pmon.o: 0.h
pp.o: 0.h
proc.o: 0.h
D 7
proc.o: tree.h
E 7
I 7
proc.o: ../src/tree.h
E 7
rec.o: 0.h
I 9
rmothers.o: 0.h
rmothers.o: ../src/tree.h
E 9
rval.o: 0.h
D 7
rval.o: tree.h
E 7
I 7
rval.o: ../src/tree.h
E 7
stat.o: 0.h
D 7
stat.o: tree.h
E 7
I 7
stat.o: ../src/tree.h
I 14
D 15
string.o: whoami.h
E 14
E 7
string.o: 0.h
D 14
subr.o: 0.h
E 14
I 14
string.o: ../src/send.h
E 15
E 14
D 7
tree.o: 0.h
E 7
type.o: 0.h
D 7
type.o: tree.h
E 7
I 7
type.o: ../src/tree.h
E 7
var.o: 0.h
D 7
var.o: tree.h
y.tab.o: whoami.h
y.tab.o: 0.h
y.tab.o: yy.h
y.tab.o: tree.h
E 7
I 7
var.o: ../src/tree.h
I 8
D 20
y.tab.o: whoami.h
y.tab.o: 0.h
I 14
y.tab.o: ../src/tree_ty.h
E 14
y.tab.o: ../src/yy.h
y.tab.o: ../src/tree.h
E 20
E 8
yycomm.o: whoami.h
E 7
yycomm.o: 0.h
D 7
yycomm.o: yy.h
yycopy.o: 0.h
yycopy.o: yy.h
yycosts.o: whoami.h
yycosts.o: 0.h
yycosts.o: yy.h
E 7
I 7
yycomm.o: ../src/yy.h
I 8
yyerror.o: whoami.h
E 8
E 7
yyerror.o: 0.h
D 7
yyerror.o: yy.h
E 7
I 7
yyerror.o: ../src/yy.h
E 7
D 8
yyget.o: 0.h
D 7
yyget.o: yy.h
yyid.o: 0.h
yyid.o: yy.h
yylex.o: 0.h
yylex.o: yy.h
E 7
I 7
yyget.o: ../src/yy.h
E 8
I 8
yymain.o: whoami.h
E 8
E 7
yymain.o: 0.h
D 7
yymain.o: yy.h
yypanic.o: 0.h
yypanic.o: yy.h
yyparse.o: 0.h
yyparse.o: yy.h
yyprint.o: 0.h
yyprint.o: yy.h
E 7
I 7
yymain.o: ../src/yy.h
I 8
yyput.o: whoami.h
E 8
E 7
yyput.o: 0.h
D 7
yyput.o: tree.h
yyput.o: yy.h
yyrecover.o: 0.h
yyrecover.o: yy.h
yyseman.o: 0.h
yyseman.o: yy.h
yytree.o: 0.h
yytree.o: tree.h
E 7
I 7
yyput.o: ../src/tree.h
yyput.o: ../src/yy.h
E 7
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 6
E 1
