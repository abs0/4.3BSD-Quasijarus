h37114
s 00003/00143/00132
d D 1.3 99/09/07 17:36:12 msokolov 7 6
c fix SCCS ID keywords
e
s 00139/00399/00136
d D 1.2 87/10/27 07:47:10 bostic 6 1
c fix depend label
e
s 00139/00399/00136
d R 1.2 87/10/26 08:58:02 bostic 5 1
c fix depend label
e
s 00139/00399/00136
d R 1.2 87/10/26 08:54:20 bostic 4 1
c fix depend label
e
s 00138/00398/00137
d R 1.2 87/10/26 08:07:41 bostic 3 1
c fix depend label
e
s 00002/00002/00533
d R 1.2 87/10/26 07:50:23 bostic 2 1
c don't use bin/grep, it's not there
e
s 00535/00000/00000
d D 1.1 87/10/16 16:19:31 bostic 1 0
c date and time created 87/10/16 16:19:31 by bostic
e
u
U
t
T
I 1
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 7
#	@(#)pimakefile	5.2 (Berkeley) 9/7/85
E 7
I 7
#	%W% (Berkeley) %G%
E 7
#
D 7
SCCSID = "@(#)pimakefile 5.2 9/7/85"
E 7
I 7
SCCSID = "%Z%%M% %I% %G%"
E 7

INSTALLDIR = ${DESTDIR}/usr/ucb
INSTALLNAME = ${INSTALLDIR}/pi
BINDIR = ../pi
SRCDIR = ../src
I 6
VPATH = ../src
E 6
WHOAMI = pi
VERSION = 3.1
D 7
DATE = 9/7/85
E 7
I 7
DATE = %G%
E 7

MKSTR = /usr/ucb/mkstr
EYACC = ../eyacc/eyacc
RM = -rm -f
TOUCH = touch -f

CFLAGS = -O
LDFLAGS = -z

LIBDIR = ${DESTDIR}/usr/lib
TMPDIR = tmp

ERRORSTRINGS = ${WHOAMI}${VERSION}strings
OLDSTRINGS = ${WHOAMI}[0-9]*.[0-9]*strings
HOWFILE = how_${WHOAMI}

SRCS =	ato.c \
	call.c case.c clas.c const.c conv.c cset.c \
	error.c fdec.c fend.c fhdr.c flvalue.c forop.c func.c gen.c hash.c \
	lab.c lookup.c lval.c stklval.c \
	main.c nl.c proc.c put.c \
	rec.c rval.c stkrval.c\
	savenl.c \
	stat.c string.c subr.c \
	tmps.c tree.c type.c var.c \
	TRdata.c \
	treen.c yycopy.c \
	yycosts.c yyerror.c yyget.c yyid.c yylex.c yymain.c yyoptions.c \
	yypanic.c yyparse.c yyprint.c yyput.c yyrecover.c yyseman.c yytree.c \
	p2put.c stab.c pcproc.c pcfunc.c pccaseop.c pclval.c sconv.c

HDRS =	0.h OPnames.h align.h iorec.h objfmt.h pstab.h pc.h \
	send.h tree.h whoami.h yy.h config.h

OTHERS = pas.y opc.c CONFIG.c gram pic.c

OBJS =	ato.o \
	call.o case.o clas.o const.o conv.o cset.o \
	error.o fdec.o fend.o fhdr.o flvalue.o forop.o func.o gen.o hash.o \
	lab.o lookup.o lval.o stklval.o \
	main.o nl.o proc.o put.o \
	rec.o rval.o stkrval.o\
	savenl.o \
	stat.o string.o subr.o \
	tmps.o tree.o type.o var.o \
	TRdata.o \
	treen.o yycopy.o \
	yycosts.o yyerror.o yyget.o yyid.o yylex.o yymain.o yyoptions.o \
	yypanic.o yyparse.o yyprint.o yyput.o yyrecover.o yyseman.o yytree.o \
	p2put.o stab.o pcproc.o pcfunc.o pccaseop.o pclval.o sconv.o

a.out: ${OBJS} y.tab.o config.c
	${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} y.tab.o config.c

${OBJS}:
	${RM} `basename $@ .o`.c
	cd ${SRCDIR}; \
	    ${MKSTR} - ${BINDIR}/${ERRORSTRINGS} ${BINDIR}/ `basename $@ .o`.c
	${CC} ${CFLAGS} -I. -I${SRCDIR} -c `basename $@ .o`.c
	${RM} `basename $@ .o`.c

lint:
	cd ${SRCDIR}; lint -I. -I${BINDIR} ${SRCS} ${BINDIR}/*.c

y.tab.h: ${SRCDIR}/pas.y ${SRCDIR}/gram
	${RM} y.tab.h y.tab.c
	${EYACC} ${SRCDIR}/pas.y > /dev/null
	ex - y.tab.c <${SRCDIR}/gram
	@echo that makes y.tab.h and y.tab.c
y.tab.o: y.tab.c y.tab.h
	${RM} x.y.tab.c
	${MKSTR} - ${ERRORSTRINGS} x. y.tab.c
	${CC} ${CFLAGS} -I${SRCDIR} -I. -c x.y.tab.c
	mv x.y.tab.o y.tab.o
	${RM} x.y.tab.c

picture: ${SRCDIR}/OPnames.h ${SRCDIR}/pic.c
	${RM} picture
	cc ${SRCDIR}/pic.c -o pic
	pic >picture
	${RM} pic

opcode.h: ${SRCDIR}/OPnames.h ${SRCDIR}/opc.c
	${RM} opcode.h
	cc ${SRCDIR}/opc.c -o opc
	opc >opcode.h
	${RM} opc

${SRCDIR}/0.h:
	${TOUCH} ${SRCDIR}/0.h

D 6
config.c: ${SRCDIR}/CONFIG.c makefile
E 6
I 6
config.c: ${SRCDIR}/CONFIG.c
E 6
	sed -e "s?VERSION?${VERSION}?g" \
	    -e "s?DATE?${DATE}?g" \
	    -e "s?INSTALLDIR?${INSTALLDIR}?g" \
	    -e "s?LIBDIR?${LIBDIR}?g" \
	    -e "s?ERRORSTRINGS?${ERRORSTRINGS}?g" \
	    -e "s?HOWFILE?${HOWFILE}?g" \
	    < ${SRCDIR}/CONFIG.c >config.c

clean:
	${RM} *.o *.c
	${RM} y.tab.h y.tab.c y.tab.out
	${RM} ${WHOAMI}*strings
	${RM} config.c opcode.h picture
	${RM} a.out core *.list *.bak errs
	${RM} opc pic tags

install: a.out
	${RM} ${LIBDIR}/${OLDSTRINGS}
	install -c -m 664 ${ERRORSTRINGS} ${LIBDIR}/${ERRORSTRINGS}
	install -s -m 775 a.out ${INSTALLNAME}

D 6
depend:
	ls ${SRCDIR}/*.c | sed \
		-e 's;^${SRCDIR}/\([a-zA-Z0-9]*\)\.c;\1.o: &;' >makedep
	/bin/grep '^#[ 	]*include' *.h ${SRCDIR}/*.h | sed \
		-e '/<.*>/d' \
		-e 's;\(.*\):[^"]*"\([^"]*\)".*;\1: \2;' >>makedep
	/bin/grep '^#[ 	]*include' ${SRCDIR}/*.c | sed \
		-e '/<.*>/d' \
		-e 's;:[^"]*"\([^"]*\)".*;: ${SRCDIR}/\1;' \
		-e 's;^${SRCDIR}/\([a-zA-Z0-9]*\)\.c;\1.o;' \
		-e 's;: ${SRCDIR}/whoami.h;: whoami.h;' \
		-e 's;: ${SRCDIR}/opcode.h;: opcode.h;' >>makedep
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp makefile makefile.bak
	ed - makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> makefile
	echo '# see make depend above' >> makefile
E 6
I 6
depend: ${SRCS} opcode.h y.tab.h
	mkdep ${CFLAGS} -I. ${SRCS}
E 6

D 6
# DO NOT DELETE THIS LINE -- make depend uses it
E 6
I 6
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 6
D 7

D 6
CONFIG.o: ../src/CONFIG.c
TRdata.o: ../src/TRdata.c
ato.o: ../src/ato.c
call.o: ../src/call.c
case.o: ../src/case.c
clas.o: ../src/clas.c
const.o: ../src/const.c
conv.o: ../src/conv.c
cset.o: ../src/cset.c
error.o: ../src/error.c
fdec.o: ../src/fdec.c
fend.o: ../src/fend.c
fhdr.o: ../src/fhdr.c
flvalue.o: ../src/flvalue.c
forop.o: ../src/forop.c
func.o: ../src/func.c
gen.o: ../src/gen.c
hash.o: ../src/hash.c
lab.o: ../src/lab.c
lookup.o: ../src/lookup.c
lval.o: ../src/lval.c
main.o: ../src/main.c
nl.o: ../src/nl.c
opc.o: ../src/opc.c
p2put.o: ../src/p2put.c
pccaseop.o: ../src/pccaseop.c
pcfunc.o: ../src/pcfunc.c
pclval.o: ../src/pclval.c
pcproc.o: ../src/pcproc.c
pic.o: ../src/pic.c
proc.o: ../src/proc.c
put.o: ../src/put.c
rec.o: ../src/rec.c
rval.o: ../src/rval.c
savenl.o: ../src/savenl.c
sconv.o: ../src/sconv.c
stab.o: ../src/stab.c
stat.o: ../src/stat.c
stklval.o: ../src/stklval.c
stkrval.o: ../src/stkrval.c
string.o: ../src/string.c
subr.o: ../src/subr.c
tmps.o: ../src/tmps.c
tree.o: ../src/tree.c
treen.o: ../src/treen.c
type.o: ../src/type.c
var.o: ../src/var.c
yycopy.o: ../src/yycopy.c
yycosts.o: ../src/yycosts.c
yyerror.o: ../src/yyerror.c
yyget.o: ../src/yyget.c
yyid.o: ../src/yyid.c
yylex.o: ../src/yylex.c
yymain.o: ../src/yymain.c
yyoptions.o: ../src/yyoptions.c
yypanic.o: ../src/yypanic.c
yyparse.o: ../src/yyparse.c
yyprint.o: ../src/yyprint.c
yyput.o: ../src/yyput.c
yyrecover.o: ../src/yyrecover.c
yyseman.o: ../src/yyseman.c
yytree.o: ../src/yytree.c
yy.h: y.tab.h
../src/yy.h: y.tab.h
TRdata.o: whoami.h
TRdata.o: ../src/0.h
ato.o: whoami.h
ato.o: ../src/0.h
call.o: whoami.h
call.o: ../src/0.h
call.o: ../src/tree.h
call.o: opcode.h
call.o: ../src/objfmt.h
call.o: ../src/pc.h
call.o: ../src/tmps.h
call.o: ../src/tree_ty.h
case.o: whoami.h
case.o: ../src/0.h
case.o: ../src/tree.h
case.o: opcode.h
case.o: ../src/tree_ty.h
clas.o: whoami.h
clas.o: ../src/0.h
clas.o: ../src/tree.h
clas.o: ../src/tree_ty.h
const.o: whoami.h
const.o: ../src/0.h
const.o: ../src/tree.h
const.o: ../src/tree_ty.h
conv.o: whoami.h
conv.o: ../src/0.h
conv.o: opcode.h
conv.o: ../src/tree_ty.h
cset.o: whoami.h
cset.o: ../src/0.h
cset.o: ../src/tree.h
cset.o: opcode.h
cset.o: ../src/objfmt.h
E 6
I 6
ato.o: ../src/ato.c whoami.h ../src/0.h /usr/include/stdio.h
ato.o: /usr/include/sys/types.h
call.o: ../src/call.c whoami.h ../src/0.h /usr/include/stdio.h
call.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
call.o: ../src/align.h ../src/tmps.h ../src/tree_ty.h
case.o: ../src/case.c whoami.h ../src/0.h /usr/include/stdio.h
case.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/tree_ty.h
clas.o: ../src/clas.c whoami.h ../src/0.h /usr/include/stdio.h
clas.o: /usr/include/sys/types.h ../src/tree.h ../src/tree_ty.h
const.o: ../src/const.c whoami.h ../src/0.h /usr/include/stdio.h
const.o: /usr/include/sys/types.h ../src/tree.h ../src/tree_ty.h
conv.o: ../src/conv.c whoami.h ../src/0.h /usr/include/stdio.h
conv.o: /usr/include/sys/types.h opcode.h ../src/tree_ty.h
cset.o: ../src/cset.c whoami.h ../src/0.h /usr/include/stdio.h
cset.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
E 6
cset.o: ../src/tree_ty.h
D 6
cset.o: ../src/pc.h
cset.o: ../src/align.h
error.o: whoami.h
error.o: ../src/0.h
error.o: ../src/tree_ty.h
error.o: ../src/yy.h
fdec.o: whoami.h
fdec.o: ../src/0.h
fdec.o: ../src/tree.h
fdec.o: opcode.h
fdec.o: ../src/objfmt.h
fdec.o: ../src/align.h
fdec.o: ../src/tmps.h
fdec.o: ../src/pc.h
fend.o: whoami.h
fend.o: ../src/0.h
fend.o: ../src/tree.h
fend.o: opcode.h
fend.o: ../src/objfmt.h
fend.o: ../src/align.h
fend.o: ../src/tmps.h
fend.o: ../src/pc.h
fend.o: ../src/tree_ty.h
fhdr.o: whoami.h
fhdr.o: ../src/0.h
fhdr.o: ../src/tree.h
fhdr.o: opcode.h
fhdr.o: ../src/objfmt.h
fhdr.o: ../src/align.h
fhdr.o: ../src/tree_ty.h
fhdr.o: ../src/pc.h
flvalue.o: whoami.h
flvalue.o: ../src/0.h
flvalue.o: ../src/tree.h
flvalue.o: opcode.h
flvalue.o: ../src/objfmt.h
flvalue.o: ../src/tree_ty.h
flvalue.o: ../src/pc.h
flvalue.o: ../src/tmps.h
forop.o: whoami.h
forop.o: ../src/0.h
forop.o: opcode.h
forop.o: ../src/tree.h
forop.o: ../src/objfmt.h
forop.o: ../src/pc.h
forop.o: ../src/tmps.h
forop.o: ../src/tree_ty.h
func.o: whoami.h
func.o: ../src/0.h
func.o: ../src/tree.h
func.o: opcode.h
func.o: ../src/tree_ty.h
gen.o: whoami.h
gen.o: ../src/0.h
gen.o: ../src/tree.h
gen.o: opcode.h
gen.o: ../src/objfmt.h
hash.o: whoami.h
hash.o: ../src/0.h
hash.o: ../src/tree_ty.h
hash.o: ../src/yy.h
lab.o: whoami.h
lab.o: ../src/0.h
lab.o: ../src/tree.h
lab.o: opcode.h
lab.o: ../src/objfmt.h
lab.o: ../src/pc.h
E 6
I 6
error.o: ../src/error.c whoami.h ../src/0.h /usr/include/stdio.h
error.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
fdec.o: ../src/fdec.c whoami.h ../src/0.h /usr/include/stdio.h
fdec.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
fdec.o: ../src/align.h ../src/tmps.h
fend.o: ../src/fend.c whoami.h ../src/0.h /usr/include/stdio.h
fend.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
fend.o: ../src/align.h ../src/tmps.h ../src/tree_ty.h
fhdr.o: ../src/fhdr.c whoami.h ../src/0.h /usr/include/stdio.h
fhdr.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
fhdr.o: ../src/align.h ../src/tree_ty.h
flvalue.o: ../src/flvalue.c whoami.h ../src/0.h /usr/include/stdio.h
flvalue.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
flvalue.o: ../src/tree_ty.h ../src/tmps.h
forop.o: ../src/forop.c whoami.h ../src/0.h /usr/include/stdio.h
forop.o: /usr/include/sys/types.h opcode.h ../src/tree.h ../src/objfmt.h
forop.o: ../src/tmps.h ../src/tree_ty.h
func.o: ../src/func.c whoami.h ../src/0.h /usr/include/stdio.h
func.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/tree_ty.h
gen.o: ../src/gen.c whoami.h ../src/0.h /usr/include/stdio.h
gen.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
hash.o: ../src/hash.c whoami.h ../src/0.h /usr/include/stdio.h
hash.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
lab.o: ../src/lab.c whoami.h ../src/0.h /usr/include/stdio.h
lab.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
E 6
lab.o: ../src/tree_ty.h
D 6
lookup.o: whoami.h
lookup.o: ../src/0.h
lval.o: whoami.h
lval.o: ../src/0.h
lval.o: ../src/tree.h
lval.o: opcode.h
lval.o: ../src/objfmt.h
E 6
I 6
lookup.o: ../src/lookup.c whoami.h ../src/0.h /usr/include/stdio.h
lookup.o: /usr/include/sys/types.h
lval.o: ../src/lval.c whoami.h ../src/0.h /usr/include/stdio.h
lval.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
E 6
lval.o: ../src/tree_ty.h
D 6
lval.o: ../src/pc.h
main.o: whoami.h
main.o: ../src/0.h
main.o: ../src/tree_ty.h
main.o: ../src/yy.h
main.o: ../src/objfmt.h
E 6
I 6
stklval.o: ../src/stklval.c whoami.h ../src/0.h /usr/include/stdio.h
stklval.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
stklval.o: ../src/tree_ty.h
main.o: ../src/main.c whoami.h ../src/0.h /usr/include/stdio.h
main.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
main.o: /usr/include/signal.h /usr/include/machine/trap.h ../src/objfmt.h
E 6
main.o: ../src/config.h
D 6
nl.o: whoami.h
nl.o: ../src/0.h
nl.o: opcode.h
nl.o: ../src/objfmt.h
opc.o: ../src/OPnames.h
p2put.o: whoami.h
p2put.o: ../src/0.h
p2put.o: ../src/objfmt.h
p2put.o: ../src/pc.h
p2put.o: ../src/align.h
p2put.o: ../src/tmps.h
pccaseop.o: whoami.h
pccaseop.o: ../src/0.h
pccaseop.o: ../src/tree.h
pccaseop.o: ../src/objfmt.h
pccaseop.o: ../src/pc.h
pccaseop.o: ../src/tmps.h
pccaseop.o: ../src/tree_ty.h
pcfunc.o: whoami.h
pcfunc.o: ../src/0.h
pcfunc.o: ../src/tree.h
pcfunc.o: ../src/objfmt.h
pcfunc.o: opcode.h
pcfunc.o: ../src/pc.h
pcfunc.o: ../src/tmps.h
pcfunc.o: ../src/tree_ty.h
pclval.o: whoami.h
pclval.o: ../src/0.h
pclval.o: ../src/tree.h
pclval.o: opcode.h
pclval.o: ../src/objfmt.h
pclval.o: ../src/tree_ty.h
pclval.o: ../src/pc.h
pcproc.o: whoami.h
pcproc.o: ../src/0.h
pcproc.o: ../src/tree.h
pcproc.o: ../src/objfmt.h
pcproc.o: opcode.h
pcproc.o: ../src/pc.h
pcproc.o: ../src/tmps.h
pcproc.o: ../src/tree_ty.h
pic.o: ../src/OPnames.h
proc.o: whoami.h
proc.o: ../src/0.h
proc.o: ../src/tree.h
proc.o: opcode.h
proc.o: ../src/objfmt.h
proc.o: ../src/tmps.h
proc.o: ../src/tree_ty.h
put.o: whoami.h
put.o: opcode.h
put.o: ../src/0.h
put.o: ../src/objfmt.h
put.o: ../src/pc.h
put.o: ../src/align.h
put.o: ../src/OPnames.h
rec.o: whoami.h
rec.o: ../src/0.h
rec.o: ../src/tree.h
rec.o: opcode.h
rec.o: ../src/align.h
E 6
I 6
nl.o: ../src/nl.c whoami.h ../src/0.h /usr/include/stdio.h
nl.o: /usr/include/sys/types.h opcode.h ../src/objfmt.h
proc.o: ../src/proc.c whoami.h ../src/0.h /usr/include/stdio.h
proc.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
proc.o: ../src/tmps.h ../src/tree_ty.h
put.o: ../src/put.c whoami.h opcode.h ../src/0.h /usr/include/stdio.h
put.o: /usr/include/sys/types.h ../src/objfmt.h ../src/OPnames.h
rec.o: ../src/rec.c whoami.h ../src/0.h /usr/include/stdio.h
rec.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/align.h
E 6
rec.o: ../src/tree_ty.h
D 6
rval.o: whoami.h
rval.o: ../src/0.h
rval.o: ../src/tree.h
rval.o: opcode.h
rval.o: ../src/objfmt.h
rval.o: ../src/pc.h
rval.o: ../src/tmps.h
rval.o: ../src/tree_ty.h
savenl.o: whoami.h
savenl.o: ../src/0.h
savenl.o: ../src/objfmt.h
savenl.o: ../src/../pdx/defs.h
savenl.o: ../src/../pdx/object.h
savenl.o: ../src/../pdx/object/objsym.rep
savenl.o: ../src/../pdx/mappings.h
E 6
I 6
rval.o: ../src/rval.c whoami.h ../src/0.h /usr/include/stdio.h
rval.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
rval.o: ../src/tmps.h ../src/tree_ty.h
stkrval.o: ../src/stkrval.c whoami.h ../src/0.h /usr/include/stdio.h
stkrval.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
stkrval.o: ../src/align.h ../src/tree_ty.h
savenl.o: ../src/savenl.c whoami.h ../src/0.h /usr/include/stdio.h
savenl.o: /usr/include/sys/types.h ../src/objfmt.h ../src/../pdx/defs.h
savenl.o: /usr/include/stdio.h ../src/../pdx/object.h
savenl.o: ../src/../pdx/object/objsym.rep ../src/../pdx/mappings.h
E 6
savenl.o: ../src/../pdx/mappings/filetab.h
D 6
sconv.o: whoami.h
sconv.o: ../src/0.h
stab.o: whoami.h
stab.o: ../src/0.h
stab.o: ../src/objfmt.h
stab.o: ../src/yy.h
stab.o: ../src/pstab.h
stab.o: ../src/pc.h
stat.o: whoami.h
stat.o: ../src/0.h
stat.o: ../src/tree.h
stat.o: ../src/objfmt.h
stat.o: ../src/pc.h
stat.o: ../src/tmps.h
stat.o: opcode.h
stat.o: ../src/tree_ty.h
stklval.o: whoami.h
stklval.o: ../src/0.h
stklval.o: ../src/tree.h
stklval.o: opcode.h
stklval.o: ../src/objfmt.h
stklval.o: ../src/tree_ty.h
stkrval.o: whoami.h
stkrval.o: ../src/0.h
stkrval.o: ../src/tree.h
stkrval.o: opcode.h
stkrval.o: ../src/objfmt.h
stkrval.o: ../src/tree_ty.h
string.o: whoami.h
string.o: ../src/0.h
string.o: ../src/send.h
subr.o: whoami.h
subr.o: ../src/0.h
tmps.o: whoami.h
tmps.o: ../src/0.h
tmps.o: ../src/objfmt.h
tmps.o: ../src/pc.h
tmps.o: ../src/align.h
tmps.o: ../src/tmps.h
tree.o: whoami.h
tree.o: ../src/0.h
treen.o: ../src/0.h
treen.o: ../src/tree_ty.h
type.o: whoami.h
type.o: ../src/0.h
type.o: ../src/tree.h
type.o: ../src/objfmt.h
type.o: ../src/tree_ty.h
var.o: whoami.h
var.o: ../src/0.h
var.o: ../src/objfmt.h
var.o: ../src/align.h
var.o: ../src/iorec.h
var.o: ../src/pc.h
var.o: ../src/tmps.h
var.o: ../src/tree_ty.h
yycopy.o: whoami.h
yycopy.o: ../src/0.h
yycopy.o: ../src/tree_ty.h
yycopy.o: ../src/yy.h
yycosts.o: whoami.h
yycosts.o: ../src/0.h
yycosts.o: ../src/tree_ty.h
yycosts.o: ../src/yy.h
yyerror.o: whoami.h
yyerror.o: ../src/0.h
yyerror.o: ../src/tree_ty.h
yyerror.o: ../src/yy.h
yyget.o: whoami.h
yyget.o: ../src/0.h
yyget.o: ../src/tree_ty.h
yyget.o: ../src/yy.h
yyid.o: whoami.h
yyid.o: ../src/0.h
yyid.o: ../src/tree_ty.h
yyid.o: ../src/yy.h
yylex.o: whoami.h
yylex.o: ../src/0.h
yylex.o: ../src/tree_ty.h
yylex.o: ../src/yy.h
yymain.o: whoami.h
yymain.o: ../src/0.h
yymain.o: ../src/tree_ty.h
yymain.o: ../src/yy.h
yymain.o: ../src/objfmt.h
yymain.o: ../src/config.h
yyoptions.o: whoami.h
yyoptions.o: ../src/0.h
yyoptions.o: ../src/tree_ty.h
yyoptions.o: ../src/yy.h
yypanic.o: whoami.h
yypanic.o: ../src/0.h
yypanic.o: ../src/tree_ty.h
yypanic.o: ../src/yy.h
yyparse.o: whoami.h
yyparse.o: ../src/0.h
yyparse.o: ../src/tree_ty.h
yyparse.o: ../src/yy.h
yyprint.o: whoami.h
yyprint.o: ../src/0.h
yyprint.o: ../src/tree_ty.h
yyprint.o: ../src/yy.h
yyput.o: whoami.h
yyput.o: ../src/0.h
yyput.o: ../src/tree.h
yyput.o: ../src/tree_ty.h
yyput.o: ../src/yy.h
yyrecover.o: whoami.h
yyrecover.o: ../src/0.h
yyrecover.o: ../src/tree_ty.h
yyrecover.o: ../src/yy.h
yyseman.o: whoami.h
yyseman.o: ../src/0.h
yyseman.o: ../src/tree_ty.h
yyseman.o: ../src/yy.h
yytree.o: whoami.h
yytree.o: ../src/0.h
yytree.o: ../src/tree.h
yytree.o: ../src/tree_ty.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 6
I 6
stat.o: ../src/stat.c whoami.h ../src/0.h /usr/include/stdio.h
stat.o: /usr/include/sys/types.h ../src/tree.h ../src/objfmt.h ../src/tmps.h
stat.o: opcode.h ../src/tree_ty.h
string.o: ../src/string.c whoami.h ../src/align.h ../src/0.h
string.o: /usr/include/stdio.h /usr/include/sys/types.h
subr.o: ../src/subr.c whoami.h ../src/0.h /usr/include/stdio.h
subr.o: /usr/include/sys/types.h /usr/include/sys/stat.h
tmps.o: ../src/tmps.c whoami.h ../src/0.h /usr/include/stdio.h
tmps.o: /usr/include/sys/types.h ../src/objfmt.h ../src/align.h ../src/tmps.h
tree.o: ../src/tree.c whoami.h ../src/0.h /usr/include/stdio.h
tree.o: /usr/include/sys/types.h
type.o: ../src/type.c whoami.h ../src/0.h /usr/include/stdio.h
type.o: /usr/include/sys/types.h ../src/tree.h ../src/objfmt.h ../src/tree_ty.h
var.o: ../src/var.c whoami.h ../src/0.h /usr/include/stdio.h
var.o: /usr/include/sys/types.h ../src/objfmt.h ../src/align.h ../src/iorec.h
var.o: /usr/include/stdio.h ../src/tmps.h ../src/tree_ty.h
TRdata.o: ../src/TRdata.c whoami.h ../src/0.h /usr/include/stdio.h
TRdata.o: /usr/include/sys/types.h
treen.o: ../src/treen.c ../src/0.h /usr/include/stdio.h
treen.o: /usr/include/sys/types.h ../src/tree_ty.h
yycopy.o: ../src/yycopy.c whoami.h ../src/0.h /usr/include/stdio.h
yycopy.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yycosts.o: ../src/yycosts.c whoami.h ../src/0.h /usr/include/stdio.h
yycosts.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yyerror.o: ../src/yyerror.c whoami.h ../src/0.h /usr/include/stdio.h
yyerror.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yyget.o: ../src/yyget.c whoami.h ../src/0.h /usr/include/stdio.h
yyget.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yyid.o: ../src/yyid.c whoami.h ../src/0.h /usr/include/stdio.h
yyid.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yylex.o: ../src/yylex.c whoami.h ../src/0.h /usr/include/stdio.h
yylex.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yymain.o: ../src/yymain.c whoami.h ../src/0.h /usr/include/stdio.h
yymain.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yymain.o: /usr/include/a.out.h /usr/include/sys/exec.h ../src/objfmt.h
yymain.o: /usr/include/signal.h /usr/include/machine/trap.h ../src/config.h
yyoptions.o: ../src/yyoptions.c whoami.h ../src/0.h /usr/include/stdio.h
yyoptions.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yypanic.o: ../src/yypanic.c whoami.h ../src/0.h /usr/include/stdio.h
yypanic.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yyparse.o: ../src/yyparse.c whoami.h ../src/0.h /usr/include/stdio.h
yyparse.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yyprint.o: ../src/yyprint.c whoami.h ../src/0.h /usr/include/stdio.h
yyprint.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yyput.o: ../src/yyput.c whoami.h ../src/0.h /usr/include/stdio.h
yyput.o: /usr/include/sys/types.h ../src/tree.h ../src/tree_ty.h ../src/yy.h
yyput.o: y.tab.h
yyrecover.o: ../src/yyrecover.c whoami.h ../src/0.h /usr/include/stdio.h
yyrecover.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yyseman.o: ../src/yyseman.c whoami.h ../src/0.h /usr/include/stdio.h
yyseman.o: /usr/include/sys/types.h ../src/tree_ty.h ../src/yy.h y.tab.h
yytree.o: ../src/yytree.c whoami.h ../src/0.h /usr/include/stdio.h
yytree.o: /usr/include/sys/types.h ../src/tree.h ../src/tree_ty.h
p2put.o: ../src/p2put.c whoami.h
stab.o: ../src/stab.c whoami.h
pcproc.o: ../src/pcproc.c whoami.h
pcfunc.o: ../src/pcfunc.c whoami.h
pccaseop.o: ../src/pccaseop.c whoami.h
pclval.o: ../src/pclval.c whoami.h ../src/0.h /usr/include/stdio.h
pclval.o: /usr/include/sys/types.h ../src/tree.h opcode.h ../src/objfmt.h
pclval.o: ../src/tree_ty.h
sconv.o: ../src/sconv.c whoami.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 7
E 6
E 1
