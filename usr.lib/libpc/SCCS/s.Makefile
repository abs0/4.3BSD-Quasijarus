h58093
s 00138/00149/00043
d D 1.23 87/12/01 21:03:18 bostic 28 25
c new template
e
s 00138/00149/00043
d R 1.23 87/06/19 15:29:58 bostic 27 25
c new template
e
s 00141/00148/00044
d R 1.23 87/06/19 15:04:15 bostic 26 25
c new template
e
s 00009/00001/00183
d D 1.22 85/05/30 23:03:31 sam 25 24
c add tags
e
s 00001/00001/00183
d D 1.21 83/04/08 19:09:44 mckusick 24 23
c remove unneeded -f flag (used to specify floating point package)
e
s 00017/00025/00167
d D 1.20 83/01/10 18:15:10 mckusick 23 22
c get rid of last of the .s files, yea!
e
s 00011/00012/00181
d D 1.19 82/11/12 18:56:53 mckusick 22 21
c GOTO and UNWIND replaced with setjmp/longjmp; NEWZ subsumed 
c into NEW and blkclr; ASRTS broken out of ASRT
e
s 00002/00002/00191
d D 1.18 82/09/09 14:33:36 peter 21 20
c `make' should make libpc, not sources.
e
s 00030/00022/00163
d D 1.17 82/08/29 21:33:07 mckusick 20 19
c remove restriction on files in dynamic structures
e
s 00008/00008/00177
d D 1.16 82/04/02 17:07:41 mckusick 19 18
c use tmp.o instead of tmp as intermediate name for linking
e
s 00010/00008/00175
d D 1.15 82/02/08 20:41:32 mckusic 18 17
c add ATAN.c, COS.c, EXP.c, and SIN.c to allow for runtime checking
e
s 00004/00003/00179
d D 1.14 82/02/02 23:38:20 mckusic 17 16
c add EXCEPT()
e
s 00002/00002/00180
d D 1.13 82/02/02 16:01:36 mckusic 16 15
c break out case range error into CASERNG
e
s 00002/00002/00180
d D 1.12 81/11/30 14:06:50 mckusic 15 14
c use -X on profiled .o files (to retain statics) and -x on regular .o files
e
s 00017/00014/00165
d D 1.11 81/11/29 23:06:37 mckusic 14 13
c change ld -x to ld -X, clean up profiled creation
e
s 00002/00005/00177
d D 1.10 81/11/23 23:10:53 mckusic 13 11
c fix install code
e
s 00001/00004/00178
d R 1.10 81/11/23 22:56:28 mckusic 12 11
c fix install code
e
s 00019/00006/00163
d D 1.9 81/11/23 22:50:22 mckusic 11 10
c mods for gprof to produce profiled library
e
s 00010/00064/00159
d D 1.8 81/06/10 00:45:22 mckusic 10 9
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00015/00015/00208
d D 1.7 81/03/18 23:58:15 mckusic 9 7
c mods for new formal routine syntax
e
s 00014/00014/00209
d R 1.7 81/03/18 15:01:42 mckusic 8 7
c mods for new formal routine syntax
e
s 00008/00004/00215
d D 1.6 81/03/07 16:07:16 mckusic 7 6
c merge in onyx changes
e
s 00147/00014/00072
d D 1.5 81/01/16 17:04:06 mckusic 6 4
c Installed new random number generator
e
s 00146/00013/00073
d R 1.5 81/01/16 16:36:18 mckusic 5 4
c Rewrite the random number generator
e
s 00002/00002/00084
d D 1.4 81/01/15 18:05:14 mckusic 4 3
c add CATCHERR and TELL
e
s 00016/00021/00070
d D 1.3 81/01/13 13:34:16 mckusic 3 2
c break out extension routines into EXTN; get rid of sccs get
e
s 00040/00017/00051
d D 1.2 80/10/31 14:48:49 mckusic 2 1
c add SCCS stuff
e
s 00068/00000/00000
d D 1.1 80/10/31 14:39:48 mckusick 1 0
c date and time created 80/10/31 14:39:48 by mckusick
e
u
U
t
T
I 1
D 28
SCCSID = "%Z%%M% %I% %G%"
I 14

E 14
D 23
CFLAGS = -O
E 23
I 23
D 24
CFLAGS = -O -f
E 24
I 24
CFLAGS = -O
E 24
E 23
I 14

E 14
LIB = ${DESTDIR}/usr/lib
I 6
D 7
SRCDIR = /usr/ucb
E 7
I 7
SRCDIR = ${DESTDIR}/usr/ucb
D 22
PASDIR = ${DESTDIR}/usr/src/cmd/pascal
E 22
I 22
PASDIR = ${DESTDIR}/usr/src/ucb/pascal
I 25
TAGSFILE=tags
E 25
E 22
E 7
E 6
D 14
LD= ld
E 14
I 14

D 22
INSTALL= /bin/cp
E 22
I 22
INSTALL= install
E 22
LD= /bin/ld
E 14
RM = /bin/rm -f
RANLIB= ranlib
D 14
AR= ar
E 14
I 14
AR= /bin/ar
E 14
D 2
LORDER= lorder
E 2
D 6
GRIND = vgrind
PRINT = vprint
VPR = vpr
E 6
I 2
D 3
GET = sccs get
E 3
E 2

D 2
CMDS =	ACTFILE.o ADDT.o ARGV.o ASRT.o BUFF.o CARD.o CHR.o CLCK.o CTTOT.o\
	DATE.o DEFNAME.o DISPOSE.o EXPO.o FCALL.o FLUSH.o FNIL.o\
E 2
I 2
D 3
CMDS =	ACTFILE.c ADDT.c APPEND.c ARGV.c ASRT.c BUFF.c CARD.c CHR.c CLCK.c \
E 3
I 3
D 16
CMDS =	ACTFILE.c ADDT.c ARGV.c ASRT.c BUFF.c CARD.c CHR.c CLCK.c \
E 16
I 16
D 18
CMDS =	ACTFILE.c ADDT.c ARGV.c ASRT.c BUFF.c CARD.c CASERNG.c CHR.c CLCK.c \
E 16
E 3
D 9
	CTTOT.c DATE.c DEFNAME.c DISPOSE.c EXPO.c FCALL.c FLUSH.c FNIL.c \
	FRTN.c FSAV.c GET.c GOTO.s HALT.c IN.c INCT.c LINO.c LLIMIT.c \
	LN.c MAX.c MULT.c NAM.c NARGCHK.s NEW.c NEWZ.c NIL.c PACK.c \
E 9
I 9
D 17
	CTTOT.c DATE.c DEFNAME.c DISPOSE.c EXPO.c FCALL.c FLUSH.c \
E 17
I 17
	CTTOT.c DATE.c DEFNAME.c DISPOSE.c EXCEPT.c EXPO.c FCALL.c FLUSH.c \
E 17
	FNIL.c FRTN.c FSAV.c GET.c GOTO.s HALT.c IN.c INCT.c LINO.c \
E 18
I 18
D 22
CMDS =	ACTFILE.c ADDT.c ARGV.c ASRT.c ATAN.c BUFF.c CARD.c \
E 22
I 22
CMDS =	ACTFILE.c ADDT.c ARGV.c ASRT.c ASRTS.c ATAN.c BUFF.c CARD.c \
E 28
I 28
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
CMDS=	ACTFILE.c ADDT.c ARGV.c ASRT.c ASRTS.c ATAN.c BUFF.c CARD.c \
E 28
E 22
	CASERNG.c CHR.c CLCK.c COS.c CTTOT.c DATE.c DEFNAME.c \
D 20
	DISPOSE.c EXCEPT.c EXP.c EXPO.c FCALL.c FLUSH.c FNIL.c \
	FRTN.c FSAV.c GET.c GOTO.s HALT.c IN.c INCT.c LINO.c \
E 20
I 20
	DFDISPOSE.c DISPOSE.c EXCEPT.c EXP.c EXPO.c FCALL.c FLUSH.c \
D 22
	FNIL.c FRTN.c FSAV.c GET.c GOTO.s HALT.c IN.c INCT.c LINO.c \
E 20
E 18
	LLIMIT.c LN.c MAX.c MULT.c NAM.c NEW.c NEWZ.c NIL.c PACK.c \
E 22
I 22
	FNIL.c FRTN.c FSAV.c GET.c HALT.c IN.c INCT.c LINO.c \
	LLIMIT.c LN.c MAX.c MULT.c NAM.c NEW.c NIL.c PACK.c \
E 22
E 9
	PAGE.c PRED.c PUT.c RANDOM.c RANG4.c READ4.c READ8.c READC.c \
	READE.c READLN.c RELEQ.c RELNE.c RELSGE.c RELSGT.c RELSLE.c \
	RELSLT.c RELTGE.c RELTGT.c RELTLE.c RELTLT.c REMOVE.c RESET.c \
D 3
	REWRITE.c ROUND.c RSNG4.c SCLCK.c SEED.c SEEK.c SQRT.c STLIM.c \
E 3
I 3
D 18
	REWRITE.c ROUND.c RSNG4.c SCLCK.c SEED.c SQRT.c STLIM.c \
E 18
I 18
	REWRITE.c ROUND.c RSNG4.c SCLCK.c SEED.c SIN.c SQRT.c STLIM.c \
E 18
E 3
	SUBSC.c SUBSCZ.c SUBT.c SUCC.c TEOF.c TEOLN.c TIME.c TRUNC.c \
	UNIT.c UNPACK.c WRITEC.c WRITEF.c WRITES.c WRITLN.c
D 28

D 10
SYS =	ERROR.c GETNAME.c IOSYNC.c PCEXIT.c PCLOSE.c PCSTART.c PFLUSH.c \
D 3
	PMFLUSH.c SETRACE.s UNSYNC.c UNWIND.c ZFRAME.c
E 3
I 3
D 6
	PMFLUSH.c SETRACE.s UNSYNC.c UNWIND.c
E 6
I 6
D 7
	PMFLUSH.c RAND.s SETRACE.s UNSYNC.c UNWIND.c
E 7
I 7
	PMFLUSH.c RAND.s SETRACE.s UNSYNC.c UNWIND.c blkclr.c blkcpy.c
E 10
I 10
D 20
SYS =	ERROR.c GETNAME.c IOSYNC.c PCEXIT.c PCLOSE.c PCSTART.c PERROR.c \
	PFLUSH.c PMFLUSH.c RAND.s SETRACE.s UNSYNC.c UNWIND.c blkclr.c blkcpy.c
E 20
I 20
SYS =	ERROR.c GETNAME.c IOSYNC.c PCEXIT.c PCLOSE.c PCSTART.c \
E 28
I 28
SYS=	ERROR.c GETNAME.c IOSYNC.c PCEXIT.c PCLOSE.c PCSTART.c \
E 28
D 23
	PFCLOSE.c PERROR.c PFLUSH.c PMFLUSH.c RAND.s SETRACE.s \
D 22
	UNSYNC.c UNWIND.c blkclr.c blkcpy.c
E 22
I 22
	UNSYNC.c blkclr.c blkcpy.c
E 23
I 23
	PFCLOSE.c PERROR.c PFLUSH.c PMFLUSH.c UNSYNC.c \
	blkclr.c blkcpy.c
E 23
E 22
E 20
E 10
E 7
E 6
E 3
D 28

I 3
D 10
EXTN =	APPEND.c CATCHERR.c SEEK.c TELL.c
E 10
I 10
EXTN =	APPEND.c SEEK.c TELL.c
E 28
I 28
EXTN=	APPEND.c SEEK.c TELL.c
E 28
I 25
SRCS=	${CMDS} ${SYS} ${EXTN}
E 25
E 10
D 28

E 3
D 7
HDRS =	h00vars.h ashdr.s errdata make.ed1
E 7
I 7
D 9
HDRS =	whoami.h h00vars.h ashdr.s errdata make.ed1
E 9
I 9
D 10
HDRS =	whoami.h h00vars.h errdata make.ed1
E 10
I 10
HDRS =	whoami.h h00vars.h
E 10
E 9
E 7

D 3
OBJS =	ACTFILE.o ADDT.o APPEND.o ARGV.o ASRT.o BUFF.o CARD.o CHR.o CLCK.o\
E 3
I 3
D 16
OBJS =	ACTFILE.o ADDT.o ARGV.o ASRT.o BUFF.o CARD.o CHR.o CLCK.o\
E 16
I 16
D 18
OBJS =	ACTFILE.o ADDT.o ARGV.o ASRT.o BUFF.o CARD.o CASERNG.o CHR.o CLCK.o\
E 16
E 3
D 9
	CTTOT.o DATE.o DEFNAME.o DISPOSE.o EXPO.o FCALL.o FLUSH.o FNIL.o\
E 2
	FRTN.o FSAV.o GET.o GOTO.o HALT.o IN.o INCT.o LINO.o LLIMIT.o\
	LN.o MAX.o MULT.o NAM.o NARGCHK.o NEW.o NEWZ.o NIL.o PACK.o PAGE.o\
	PRED.o PUT.o RANDOM.o RANG4.o READ4.o READ8.o READC.o\
E 9
I 9
D 17
	CTTOT.o DATE.o DEFNAME.o DISPOSE.o EXPO.o FCALL.o FLUSH.o\
E 17
I 17
	CTTOT.o DATE.o DEFNAME.o DISPOSE.o EXCEPT.o EXPO.o FCALL.o FLUSH.o\
E 17
	FNIL.o FRTN.o FSAV.o GET.o GOTO.o HALT.o IN.o INCT.o LINO.o \
E 18
I 18
D 22
OBJS =	ACTFILE.o ADDT.o ARGV.o ASRT.o ATAN.o BUFF.o CARD.o \
E 22
I 22
OBJS =	ACTFILE.o ADDT.o ARGV.o ASRT.o ASRTS.o ATAN.o BUFF.o CARD.o \
E 28
I 28
COBJS=	ACTFILE.o ADDT.o ARGV.o ASRT.o ASRTS.o ATAN.o BUFF.o CARD.o \
E 28
E 22
	CASERNG.o CHR.o CLCK.o COS.o CTTOT.o DATE.o DEFNAME.o \
D 20
	DISPOSE.o EXCEPT.o EXP.o EXPO.o FCALL.o FLUSH.o FNIL.o \
	FRTN.o FSAV.o GET.o GOTO.o HALT.o IN.o INCT.o LINO.o \
E 20
I 20
	DFDISPOSE.o DISPOSE.o EXCEPT.o EXP.o EXPO.o FCALL.o FLUSH.o \
D 22
	FNIL.o FRTN.o FSAV.o GET.o GOTO.o HALT.o IN.o INCT.o LINO.o \
E 20
E 18
	LLIMIT.o LN.o MAX.o MULT.o NAM.o NEW.o NEWZ.o NIL.o PACK.o\
E 22
I 22
	FNIL.o FRTN.o FSAV.o GET.o HALT.o IN.o INCT.o LINO.o \
	LLIMIT.o LN.o MAX.o MULT.o NAM.o NEW.o NIL.o PACK.o\
E 22
	PAGE.o PRED.o PUT.o RANDOM.o RANG4.o READ4.o READ8.o READC.o\
E 9
	READE.o READLN.o RELEQ.o RELNE.o RELSGE.o RELSGT.o RELSLE.o\
	RELSLT.o RELTGE.o RELTGT.o RELTLE.o RELTLT.o REMOVE.o RESET.o\
D 3
	REWRITE.o ROUND.o RSNG4.o SCLCK.o SEED.o SEEK.o SQRT.o\
E 3
I 3
D 9
	REWRITE.o ROUND.o RSNG4.o SCLCK.o SEED.o SQRT.o\
E 3
	STLIM.o SUBSC.o SUBSCZ.o SUBT.o SUCC.o TEOF.o TEOLN.o TIME.o\
	TRUNC.o UNIT.o UNPACK.o WRITEC.o WRITEF.o WRITES.o WRITLN.o
E 9
I 9
D 18
	REWRITE.o ROUND.o RSNG4.o SCLCK.o SEED.o SQRT.o STLIM.o\
E 18
I 18
	REWRITE.o ROUND.o RSNG4.o SCLCK.o SEED.o SIN.o SQRT.o STLIM.o\
E 18
	SUBSC.o SUBSCZ.o SUBT.o SUCC.o TEOF.o TEOLN.o TIME.o TRUNC.o\
	UNIT.o UNPACK.o WRITEC.o WRITEF.o WRITES.o WRITLN.o
E 9
D 28

E 28
D 2
SYOBJ =	GETNAME.o IOSYNC.o PCLOSE.o PCSTART.o ERROR.o PFLUSH.o\
E 2
I 2
D 10
SYOBJ =	ERROR.o GETNAME.o IOSYNC.o PCEXIT.o PCLOSE.o PCSTART.o PFLUSH.o\
E 2
D 3
	PMFLUSH.o SETRACE.o UNSYNC.o UNWIND.o ZFRAME.o
E 3
I 3
D 6
	PMFLUSH.o SETRACE.o UNSYNC.o UNWIND.o
E 6
I 6
D 7
	PMFLUSH.o RAND.o SETRACE.o UNSYNC.o UNWIND.o
E 7
I 7
	PMFLUSH.o RAND.o SETRACE.o UNSYNC.o UNWIND.o blkclr.o blkcpy.o
E 10
I 10
D 20
SYOBJ =	ERROR.o GETNAME.o IOSYNC.o PCEXIT.o PCLOSE.o PCSTART.o PERROR.o\
	PFLUSH.o PMFLUSH.o RAND.o SETRACE.o UNSYNC.o UNWIND.o blkclr.o blkcpy.o
E 20
I 20
SYOBJ =	ERROR.o GETNAME.o IOSYNC.o PCEXIT.o PCLOSE.o PCSTART.o \
D 23
	PFCLOSE.o PERROR.o PFLUSH.o PMFLUSH.o RAND.o SETRACE.o \
D 22
	UNSYNC.o UNWIND.o blkclr.o blkcpy.o
E 22
I 22
	UNSYNC.o blkclr.o blkcpy.o
E 23
I 23
	PFCLOSE.o PERROR.o PFLUSH.o PMFLUSH.o UNSYNC.o \
	blkclr.o blkcpy.o
E 23
E 22
E 20
E 10
E 7
E 6
E 3
D 28

E 28
I 2
D 3
sources: ${CMDS} ${SYS} ${HDRS}
${CMDS} ${SYS}: ${HDRS}
	${GET} ${REL} $@
${HDRS}:
	${GET} ${REL} $@
E 3
I 3
D 10
EXOBJ =	APPEND.o CATCHERR.o SEEK.o TELL.o
E 10
I 10
EXOBJ =	APPEND.o SEEK.o TELL.o
I 28
OBJS=	${COBJS} ${SYOBJ} ${EXOBJ}
E 28
E 10
E 3

I 3
D 21
sources: ${CMDS} ${SYS} ${EXTN} ${HDRS}
D 6
${CMDS} ${SYS} ${EXTN}: ${HDRS}
E 6

E 21
E 3
E 2
D 23
.s.o:
D 9
	cat ashdr.s $*.s | ${AS} -o tmp
E 9
I 9
D 14
	${AS} -o tmp $*.s
I 11
	-${LD} -x -r -o normal/$@ tmp
E 14
D 19
	sed -f mcount.sed $*.s | ${AS} -o tmp
E 11
E 9
D 14
	-${LD} -x -r -o $@ tmp
E 14
I 14
	-${LD} -X -r -o profiled/$@ tmp
	${AS} -o tmp $*.s
D 15
	-${LD} -X -r -o $@ tmp
E 15
I 15
	-${LD} -x -r -o $@ tmp
E 19
I 19
	sed -f mcount.sed $*.s | ${AS} -o tmp.o
	-${LD} -X -r -o profiled/$@ tmp.o
	${AS} -o tmp.o $*.s
	-${LD} -x -r -o $@ tmp.o
E 19
E 15
E 14

E 23
.c.o:
D 14
	${CC} ${CFLAGS} -c $*.c
	mv $@ tmp
I 11
	-${LD} -x -r -o normal/$@ tmp
E 14
	${CC} -p ${CFLAGS} -c $*.c
D 19
	mv $@ tmp
E 11
D 14
	-${LD} -x -r -o $@ tmp
E 14
I 14
	-${LD} -X -r -o profiled/$@ tmp
E 19
I 19
	mv $@ tmp.o
D 28
	-${LD} -X -r -o profiled/$@ tmp.o
E 28
I 28
	-ld -X -r -o profiled/$@ tmp.o
E 28
E 19
	${CC} ${CFLAGS} -c $*.c
D 19
	mv $@ tmp
D 15
	-${LD} -X -r -o $@ tmp
E 15
I 15
	-${LD} -x -r -o $@ tmp
E 19
I 19
	mv $@ tmp.o
D 28
	-${LD} -x -r -o $@ tmp.o
E 28
I 28
	-ld -x -r -o $@ tmp.o
E 28
E 19
E 15
E 14

I 3
D 11
install: libpc
E 11
I 11
D 13
libpc libpc_p: normal ${OBJS} ${SYOBJ} ${EXOBJ}
E 13
I 13
D 28
libpc libpc_p: ${OBJS} ${SYOBJ} ${EXOBJ}
E 13
D 14
	${AR} cru libpc_p ${OBJS} ${SYOBJ} ${EXOBJ}
E 14
I 14
	cd profiled; ${AR} cru ../libpc_p ${OBJS} ${SYOBJ} ${EXOBJ}
E 14
	${RANLIB} libpc_p
D 14
	mv normal/* .
E 14
	${AR} cru libpc ${OBJS} ${SYOBJ} ${EXOBJ}
	${RANLIB} libpc
E 28
I 28
all: libpc libpc_p
E 28

D 28
install: libpc libpc_p
D 14
	cp libpc_p ${LIB}/libpc_p.a
E 14
I 14
	${INSTALL} libpc_p ${LIB}/libpc_p.a
E 14
	${RANLIB} ${LIB}/libpc_p.a
E 11
D 14
	cp libpc ${LIB}/libpc.a
E 14
I 14
	${INSTALL} libpc ${LIB}/libpc.a
E 14
	${RANLIB} ${LIB}/libpc.a
E 28
I 28
libpc libpc_p: ${OBJS}
	cd profiled; ar cru ../libpc_p ${OBJS}
	ranlib libpc_p
	ar cru libpc ${OBJS}
	ranlib libpc
E 28
I 21

D 28
sources: ${CMDS} ${SYS} ${EXTN} ${HDRS}
E 28
I 28
clean: FRC
	rm -f ${OBJS} core libpc libpc_p profiled/*.o tmp tmp.o
E 28
E 21

E 3
D 2
pclib: h01errs.h PCEXIT.o ${CMDS} ${SYOBJ}
	${RM} pclib
	${AR} cr pclib PCEXIT.o `${LORDER} ${CMDS} ${SYOBJ} | tsort`
	${RANLIB} pclib
E 2
I 2
D 4
libpc: h01errs.h ${OBJS} ${SYOBJ}
E 4
I 4
D 10
libpc: h01errs.h ${OBJS} ${SYOBJ} ${EXOBJ}
E 10
I 10
D 11
libpc: ${OBJS} ${SYOBJ} ${EXOBJ}
E 10
E 4
	${RM} libpc
D 4
	${AR} cr libpc ${OBJS} ${SYOBJ}
E 4
I 4
	${AR} cr libpc ${OBJS} ${SYOBJ} ${EXOBJ}
E 4
	${RANLIB} libpc
E 11
I 11
D 13
normal:
	mkdir normal
E 11
E 2

E 13
D 2
h01errs.h: errdata
	ed - <make.ed1
E 2
I 2
D 9
h01errs.h: errdata make.ed1 ashdr.s
E 9
I 9
D 10
h01errs.h: errdata make.ed1
E 9
	ed - errdata <make.ed1
E 2
	${RM} E.s *.o
I 7

E 10
D 28
whoami.h:
	cp ${PASDIR}/whoami.h whoami.h
E 28
I 28
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 28
E 7

D 2
install: pclib
	cp pclib ${LIB}/libpc.a
E 2
I 2
D 3
install: libpc
	cp libpc ${LIB}/libpc.a
E 2
	${RANLIB} ${LIB}/libpc.a

D 2
new: pclib
	cp pclib ${NEWLIB}/libpc.a
E 2
I 2
new: libpc
	cp libpc ${NEWLIB}/libpc.a
E 2
	${RANLIB} ${NEWLIB}/libpc.a

E 3
D 28
clean:
D 2
	${RM} pclib *.o a.out lpr tmp core errs
E 2
I 2
D 13
	${RM} libpc *.o a.out lpr tmp core errs
E 13
I 13
D 14
	${RM} libpc libpc_p *.o a.out lpr tmp core errs
E 14
I 14
D 25
	${RM} libpc libpc_p *.o profiled/*.o a.out lpr tmp core errs
E 25
I 25
	${RM} libpc libpc_p *.o profiled/*.o a.out lpr tmp core errs tags
E 28
I 28
install: FRC
	install -o bin -g bin -m 644 libpc_p ${DESTDIR}/usr/lib/libpc_p.a
	ranlib ${DESTDIR}/usr/lib/libpc_p.a
	install -o bin -g bin -m 644 libpc ${DESTDIR}/usr/lib/libpc.a
	ranlib ${DESTDIR}/usr/lib/libpc.a
E 28
E 25
E 14
E 13
D 3
	sccs clean
E 3
E 2

D 28
print:
	ls -l >lst
D 6
	${PRINT} lst makefile *.h [A-Z][A-Z]*.[cs] [a-z][a-z]*.[cs]
E 6
I 6
D 23
	${SRCDIR}/vprint lst makefile *.h [A-Z][A-Z]*.[cs] [a-z][a-z]*.[cs]
E 23
I 23
	${SRCDIR}/vprint lst Makefile *.h [A-Z][A-Z]*.[cs] [a-z][a-z]*.[cs]
E 23
E 6
	${RM} lst
E 28
I 28
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 28

D 2
grind:
E 2
I 2
D 28
grind: sources
E 2
D 6
	${VGRIND} -t -n makefile >lpr
	cat </dev/null >index
	${VGRIND} -t *.h *.c >>lpr
	${VGRIND} -t -x index >lindex
D 2
	${VGRIND} -t -n ashdr.s GOTO.s SETRACE.s >>lpr
E 2
I 2
	${VGRIND} -t -n ashdr.s GOTO.s SETRACE.s NARGCHK.s >>lpr
E 2
	${VPR} -t lindex lpr
	${RM} lpr lindex index
E 6
I 6
D 23
	${SRCDIR}/ctags -v *.h *.c *.s | sort -f >index
E 23
I 23
	${SRCDIR}/ctags -v *.h *.c | sort -f >index
E 23
	${SRCDIR}/vgrind -t -x index >lpr
D 9
	${SRCDIR}/vgrind -t -n makefile >lpr
E 9
I 9
D 23
	${SRCDIR}/vgrind -t -n makefile >>lpr
E 23
I 23
	${SRCDIR}/vgrind -t -n Makefile >>lpr
E 23
E 9
	${RM} index
	${SRCDIR}/vgrind -t *.h *.c >>lpr
D 9
	${SRCDIR}/vgrind -t -n ashdr.s GOTO.s NARGCHK.s RAND.s SETRACE.s >>lpr
E 9
I 9
D 22
	${SRCDIR}/vgrind -t -n GOTO.s RAND.s SETRACE.s >>lpr
E 22
I 22
D 23
	${SRCDIR}/vgrind -t -n RAND.s SETRACE.s >>lpr
E 23
E 22
E 9
	${SRCDIR}/vpr -t lpr
E 28
I 28
tags: FRC
	ctags ${SRCS}
E 28
I 25

D 28
tags:
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done
E 28
I 28
FRC:
E 28
E 25

D 28
depend:	sources
D 20
	/bin/grep '^#[ 	]*include' *.c \
E 20
I 20
D 23
	/bin/grep '^#[ 	]*include' ${CMDS} ${SYS} ${EXTN} \
E 20
		| sed '/<.*>/d' \
		| sed 's/:[^"]*"\([^"]*\)".*/: \1/' \
		| sed 's/\.c/.o/' >makedep
E 23
I 23
	/bin/grep '^#[ 	]*include' ${CMDS} ${SYS} ${EXTN} | sed \
		-e '/<.*>/d' \
		-e 's/:[^"]*"\([^"]*\)".*/: \1/' \
		-e 's/\.c/.o/' >makedep
E 23
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
D 23
	cp makefile makefile.bak
	ed - makefile < eddep
E 23
I 23
	cp Makefile Makefile.bak
	ed - Makefile < eddep
E 23
	rm eddep makedep
D 23
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> makefile
	echo '# see make depend above' >> makefile
E 23
I 23
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 28
I 28
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 28
E 23

D 28
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
ACTFILE.o: h00vars.h
D 20
APPEND.o: h00vars.h
E 20
D 10
APPEND.o: h01errs.h
E 10
ARGV.o: h00vars.h
D 10
ARGV.o: h01errs.h
ASRT.o: h01errs.h
E 10
BUFF.o: h00vars.h
D 11
CATCHERR.o: h00vars.h
E 11
D 10
CHR.o: h01errs.h
E 10
I 10
CTTOT.o: whoami.h
E 10
CTTOT.o: h00vars.h
D 10
CTTOT.o: h01errs.h
E 10
DEFNAME.o: h00vars.h
I 20
DFDISPOSE.o: h00vars.h
DFDISPOSE.o: libpc.h
E 20
DISPOSE.o: h00vars.h
D 10
DISPOSE.o: h01errs.h
E 10
D 17
ERROR.o: h00vars.h
E 17
I 17
EXCEPT.o: whoami.h
E 17
D 10
ERROR.o: h01errs.h
E 10
FCALL.o: h00vars.h
FLUSH.o: h00vars.h
D 10
FLUSH.o: h01errs.h
E 10
FNIL.o: h00vars.h
D 10
FNIL.o: h01errs.h
E 10
FRTN.o: h00vars.h
FSAV.o: h00vars.h
GET.o: h00vars.h
D 10
GET.o: h01errs.h
E 10
D 20
GETNAME.o: h00vars.h
E 20
I 11
HALT.o: h00vars.h
E 11
D 10
GETNAME.o: h01errs.h
HALT.o: h01errs.h
E 10
IN.o: h00vars.h
INCT.o: h00vars.h
D 20
IOSYNC.o: h00vars.h
E 20
D 10
IOSYNC.o: h01errs.h
E 10
LINO.o: h00vars.h
D 10
LINO.o: h01errs.h
E 10
LLIMIT.o: h00vars.h
D 10
LLIMIT.o: h01errs.h
LN.o: h01errs.h
E 10
MAX.o: h00vars.h
D 10
MAX.o: h01errs.h
E 10
NAM.o: h00vars.h
D 10
NAM.o: h01errs.h
E 10
NEW.o: h00vars.h
D 10
NEW.o: h01errs.h
E 10
D 22
NEWZ.o: h00vars.h
E 22
D 10
NEWZ.o: h01errs.h
E 10
NIL.o: h00vars.h
D 10
NIL.o: h01errs.h
PACK.o: h01errs.h
E 10
PAGE.o: h00vars.h
D 10
PAGE.o: h01errs.h
E 10
D 20
PCEXIT.o: h00vars.h
PCLOSE.o: h00vars.h
D 10
PCLOSE.o: h01errs.h
E 10
PCSTART.o: h00vars.h
I 17
PCSTART.o: libpc.h
E 17
I 10
PERROR.o: h00vars.h
E 10
PFLUSH.o: h00vars.h
PMFLUSH.o: h00vars.h
E 20
D 10
PRED.o: h01errs.h
E 10
PUT.o: h00vars.h
D 10
PUT.o: h01errs.h
E 10
RANDOM.o: h00vars.h
D 10
RANG4.o: h01errs.h
E 10
READ4.o: h00vars.h
D 10
READ4.o: h01errs.h
E 10
READ8.o: h00vars.h
D 10
READ8.o: h01errs.h
E 10
READC.o: h00vars.h
D 10
READC.o: h01errs.h
E 10
READE.o: h00vars.h
D 10
READE.o: h01errs.h
E 10
READLN.o: h00vars.h
D 10
READLN.o: h01errs.h
E 10
RELEQ.o: h00vars.h
RELNE.o: h00vars.h
RELSGE.o: h00vars.h
RELSGT.o: h00vars.h
RELSLE.o: h00vars.h
I 11
RELSLT.o: h00vars.h
E 11
D 10
RELSLT.o: h00vars.h
E 10
RELTGE.o: h00vars.h
RELTGT.o: h00vars.h
RELTLE.o: h00vars.h
RELTLT.o: h00vars.h
REMOVE.o: h00vars.h
D 10
REMOVE.o: h01errs.h
E 10
RESET.o: h00vars.h
D 10
RESET.o: h01errs.h
E 10
REWRITE.o: h00vars.h
D 10
REWRITE.o: h01errs.h
RSNG4.o: h01errs.h
E 10
SEED.o: h00vars.h
D 20
SEEK.o: h00vars.h
E 20
D 10
SEEK.o: h01errs.h
SQRT.o: h01errs.h
E 10
STLIM.o: h00vars.h
D 10
STLIM.o: h01errs.h
SUBSC.o: h01errs.h
SUBSCZ.o: h01errs.h
SUCC.o: h01errs.h
E 10
D 20
TELL.o: h00vars.h
E 20
TEOF.o: h00vars.h
D 10
TEOF.o: h01errs.h
E 10
TEOLN.o: h00vars.h
D 10
TEOLN.o: h01errs.h
E 10
UNIT.o: h00vars.h
D 10
UNIT.o: h01errs.h
UNPACK.o: h01errs.h
E 10
D 20
UNSYNC.o: h00vars.h
E 20
D 10
UNSYNC.o: h01errs.h
E 10
WRITEC.o: h00vars.h
D 10
WRITEC.o: h01errs.h
E 10
WRITEF.o: h00vars.h
D 10
WRITEF.o: h01errs.h
E 10
WRITES.o: h00vars.h
D 10
WRITES.o: h01errs.h
E 10
WRITLN.o: h00vars.h
I 20
GETNAME.o: h00vars.h
GETNAME.o: libpc.h
IOSYNC.o: h00vars.h
PCEXIT.o: h00vars.h
PCLOSE.o: h00vars.h
PCLOSE.o: libpc.h
PCSTART.o: h00vars.h
PCSTART.o: libpc.h
PFCLOSE.o: h00vars.h
PFCLOSE.o: libpc.h
D 23
PERROR.o: h00vars.h
E 23
PFLUSH.o: h00vars.h
PMFLUSH.o: h00vars.h
UNSYNC.o: h00vars.h
APPEND.o: h00vars.h
SEEK.o: h00vars.h
TELL.o: h00vars.h
E 20
D 10
WRITLN.o: h01errs.h
E 10
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 28
I 28
ACTFILE.o: ACTFILE.c h00vars.h /usr/include/stdio.h whoami.h
ADDT.o: ADDT.c
ARGV.o: ARGV.c h00vars.h /usr/include/stdio.h whoami.h
ASRT.o: ASRT.c
ASRTS.o: ASRTS.c
ATAN.o: ATAN.c /usr/include/math.h
BUFF.o: BUFF.c h00vars.h /usr/include/stdio.h whoami.h
CARD.o: CARD.c
CASERNG.o: CASERNG.c
CHR.o: CHR.c
CLCK.o: CLCK.c
COS.o: COS.c /usr/include/math.h
CTTOT.o: CTTOT.c whoami.h h00vars.h /usr/include/stdio.h whoami.h
DATE.o: DATE.c
DEFNAME.o: DEFNAME.c h00vars.h /usr/include/stdio.h whoami.h
DFDISPOSE.o: DFDISPOSE.c h00vars.h /usr/include/stdio.h whoami.h libpc.h
DISPOSE.o: DISPOSE.c h00vars.h /usr/include/stdio.h whoami.h
EXCEPT.o: EXCEPT.c /usr/include/signal.h
EXP.o: EXP.c /usr/include/math.h
EXPO.o: EXPO.c
FCALL.o: FCALL.c h00vars.h /usr/include/stdio.h whoami.h
FLUSH.o: FLUSH.c h00vars.h /usr/include/stdio.h whoami.h
FNIL.o: FNIL.c h00vars.h /usr/include/stdio.h whoami.h
FRTN.o: FRTN.c h00vars.h /usr/include/stdio.h whoami.h
FSAV.o: FSAV.c h00vars.h /usr/include/stdio.h whoami.h
GET.o: GET.c h00vars.h /usr/include/stdio.h whoami.h
HALT.o: HALT.c h00vars.h /usr/include/stdio.h whoami.h
IN.o: IN.c h00vars.h /usr/include/stdio.h whoami.h
INCT.o: INCT.c h00vars.h /usr/include/stdio.h whoami.h
LINO.o: LINO.c h00vars.h /usr/include/stdio.h whoami.h
LLIMIT.o: LLIMIT.c h00vars.h /usr/include/stdio.h whoami.h
LN.o: LN.c /usr/include/math.h
MAX.o: MAX.c h00vars.h /usr/include/stdio.h whoami.h
MULT.o: MULT.c
NAM.o: NAM.c h00vars.h /usr/include/stdio.h whoami.h
NEW.o: NEW.c h00vars.h /usr/include/stdio.h whoami.h
NIL.o: NIL.c h00vars.h /usr/include/stdio.h whoami.h
PACK.o: PACK.c
PAGE.o: PAGE.c h00vars.h /usr/include/stdio.h whoami.h
PRED.o: PRED.c
PUT.o: PUT.c h00vars.h /usr/include/stdio.h whoami.h
RANDOM.o: RANDOM.c h00vars.h /usr/include/stdio.h whoami.h
RANG4.o: RANG4.c
READ4.o: READ4.c h00vars.h /usr/include/stdio.h whoami.h /usr/include/errno.h
READ8.o: READ8.c h00vars.h /usr/include/stdio.h whoami.h /usr/include/errno.h
READC.o: READC.c h00vars.h /usr/include/stdio.h whoami.h
READE.o: READE.c h00vars.h /usr/include/stdio.h whoami.h
READLN.o: READLN.c h00vars.h /usr/include/stdio.h whoami.h
RELEQ.o: RELEQ.c h00vars.h /usr/include/stdio.h whoami.h
RELNE.o: RELNE.c h00vars.h /usr/include/stdio.h whoami.h
RELSGE.o: RELSGE.c h00vars.h /usr/include/stdio.h whoami.h
RELSGT.o: RELSGT.c h00vars.h /usr/include/stdio.h whoami.h
RELSLE.o: RELSLE.c h00vars.h /usr/include/stdio.h whoami.h
RELSLT.o: RELSLT.c h00vars.h /usr/include/stdio.h whoami.h
RELTGE.o: RELTGE.c h00vars.h /usr/include/stdio.h whoami.h
RELTGT.o: RELTGT.c h00vars.h /usr/include/stdio.h whoami.h
RELTLE.o: RELTLE.c h00vars.h /usr/include/stdio.h whoami.h
RELTLT.o: RELTLT.c h00vars.h /usr/include/stdio.h whoami.h
REMOVE.o: REMOVE.c h00vars.h /usr/include/stdio.h whoami.h
RESET.o: RESET.c h00vars.h /usr/include/stdio.h whoami.h
REWRITE.o: REWRITE.c h00vars.h /usr/include/stdio.h whoami.h
ROUND.o: ROUND.c
RSNG4.o: RSNG4.c
SCLCK.o: SCLCK.c
SEED.o: SEED.c h00vars.h /usr/include/stdio.h whoami.h
SIN.o: SIN.c /usr/include/math.h
SQRT.o: SQRT.c /usr/include/math.h
STLIM.o: STLIM.c h00vars.h /usr/include/stdio.h whoami.h
SUBSC.o: SUBSC.c
SUBSCZ.o: SUBSCZ.c
SUBT.o: SUBT.c
SUCC.o: SUCC.c
TEOF.o: TEOF.c h00vars.h /usr/include/stdio.h whoami.h
TEOLN.o: TEOLN.c h00vars.h /usr/include/stdio.h whoami.h
TIME.o: TIME.c
TRUNC.o: TRUNC.c
UNIT.o: UNIT.c h00vars.h /usr/include/stdio.h whoami.h
UNPACK.o: UNPACK.c
WRITEC.o: WRITEC.c h00vars.h /usr/include/stdio.h whoami.h
WRITEF.o: WRITEF.c h00vars.h /usr/include/stdio.h whoami.h
WRITES.o: WRITES.c h00vars.h /usr/include/stdio.h whoami.h
WRITLN.o: WRITLN.c h00vars.h /usr/include/stdio.h whoami.h
ERROR.o: ERROR.c /usr/include/stdio.h /usr/include/signal.h
GETNAME.o: GETNAME.c h00vars.h /usr/include/stdio.h whoami.h libpc.h
IOSYNC.o: IOSYNC.c h00vars.h /usr/include/stdio.h whoami.h
PCEXIT.o: PCEXIT.c h00vars.h /usr/include/stdio.h whoami.h
PCLOSE.o: PCLOSE.c h00vars.h /usr/include/stdio.h whoami.h libpc.h
PCSTART.o: PCSTART.c /usr/include/signal.h h00vars.h /usr/include/stdio.h
PCSTART.o: whoami.h libpc.h
PFCLOSE.o: PFCLOSE.c h00vars.h /usr/include/stdio.h whoami.h libpc.h
PERROR.o: PERROR.c /usr/include/stdio.h /usr/include/signal.h
PFLUSH.o: PFLUSH.c h00vars.h /usr/include/stdio.h whoami.h
PMFLUSH.o: PMFLUSH.c h00vars.h /usr/include/stdio.h whoami.h
UNSYNC.o: UNSYNC.c h00vars.h /usr/include/stdio.h whoami.h
blkclr.o: blkclr.c
blkcpy.o: blkcpy.c
APPEND.o: APPEND.c h00vars.h /usr/include/stdio.h whoami.h
SEEK.o: SEEK.c h00vars.h /usr/include/stdio.h whoami.h
TELL.o: TELL.c h00vars.h /usr/include/stdio.h whoami.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 28
E 6
E 1
