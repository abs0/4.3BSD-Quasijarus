h58219
s 00005/00003/00172
d D 1.21 83/05/11 21:19:38 dlw 21 20
c old lib to /usr/old/lib. DLW
e
s 00034/00012/00141
d D 1.20 83/05/06 16:20:55 dlw 20 19
c added profiled lib. DLW
e
s 00001/00002/00152
d D 1.19 83/04/29 16:24:45 dlw 19 18
c removed cabs, tanh, sinh - duplicated in libm. DLW
e
s 00001/00006/00153
d D 1.18 83/04/17 22:42:53 dlw 18 17
c removed man tree from 'tape'. DLW
e
s 00003/00002/00156
d D 1.17 83/04/15 15:57:01 dlw 17 16
c inserted CFLAGS macro. DLW
e
s 00002/00002/00156
d D 1.16 83/01/21 12:35:29 dlw 16 15
c added long/short conversions. DLW
e
s 00013/00004/00145
d D 1.15 83/01/21 10:44:50 dlw 15 14
c added Version. DLW
e
s 00036/00008/00111
d D 1.14 83/01/04 00:09:22 dlw 14 13
c cleaned up & adapted to SCCS subdir. DLW
e
s 00003/00003/00116
d D 1.13 82/06/03 20:43:29 dlw 13 12
c minor syntax fixes. DLW
e
s 00004/00002/00115
d D 1.12 82/06/03 00:53:03 dlw 12 11
c added defines for VAX (should be 'vax'). DLW
e
s 00029/00011/00088
d D 1.11 82/02/03 10:41:54 dlw 11 10
c added 'End of Makefile' & spcl distribution make. DLW
e
s 00002/00001/00097
d D 1.10 81/08/14 19:30:20 dlw 10 9
c added global def for 'lpr'. DLW
e
s 00001/00000/00097
d D 1.9 81/08/13 19:45:46 dlw 9 8
c added chmod 644 to install. DLW
e
s 00002/00002/00095
d D 1.8 81/08/13 19:36:20 dlw 8 7
c added traper_ to lib. DLW
e
s 00001/00001/00096
d D 1.7 81/08/13 18:39:14 dlw 7 6
c added UCBVAX compile flag for FPE reporting. DLW
e
s 00006/00006/00091
d D 1.6 81/08/12 11:07:49 dlw 6 5
c removed (signal,system,iargc,getenv,getarg), added exit. DLW
e
s 00029/00020/00068
d D 1.5 81/04/19 19:58:50 dlw 5 4
c added Vax vs PDP-11 specific defs. DLW
e
s 00001/00001/00087
d D 1.4 81/02/26 23:07:24 dlw 4 3
c enabled saving old lib on install. DLW
e
s 00003/00002/00085
d D 1.3 81/02/26 17:39:35 dlw 3 2
c made LIBDIR /usr/ucb/lib. DLW
e
s 00001/00001/00086
d D 1.2 81/02/25 15:26:45 dlw 2 1
c removed bit.o from OBJECTS list. DLW
e
s 00087/00000/00000
d D 1.1 81/02/25 15:23:56 dlw 1 0
c date and time created 81/02/25 15:23:56 by dlw
e
u
U
t
T
I 1
# Makefile for the f77 math & startup lib - libF77.a

#	%W%	%G%

I 14
DESTDIR =
E 14
D 3
LIBDIR = /usr/cc/lib
E 3
I 3
D 5
LIBDIR = /usr/ucb/lib
E 3
TAPE = /dev/nrmt1
E 5
I 5
LIB = libF77.a
I 20
LIB_P = libF77_p.a
E 20
I 10
LPR = lpr
I 17
CFLAGS = -O
E 17
E 10
E 5

I 5
# for the CFO 11's
D 14
#LIBDIR = /usr/ucb/lib
E 14
I 14
#LIBDIR = ${DESTDIR}/usr/ucb/lib
I 21
#OLDDIR = ${DESTDIR}/usr/old/lib
E 21
E 14
#TAPE = /dev/nrmt1
I 12
#OPTIONS = 
E 12

# for the VAX
D 14
LIBDIR = /usr/lib
E 14
I 14
LIBDIR = ${DESTDIR}/usr/lib
E 14
D 21
TAPE = /dev/rnmt0.1600
E 21
I 21
OLDDIR = ${DESTDIR}/usr/old/lib
TAPE = /dev/rnmt0
E 21
I 12
OPTIONS = -DUCBVAX
E 12

E 5
D 11
# compile, then strip unnecessary symbols
.c.o :
D 5
	cc -O -c -DPDP11 $*.c
E 5
I 5
D 7
	cc -O -c -DVAX $*.c
E 7
I 7
	cc -O -c -DVAX -DUCBVAX $*.c
E 7
E 5
	-ld -r -x $*.o
	mv a.out $*.o

E 11
D 5
MISC =	main.o s_rnge.o abort_.o getarg_.o iargc_.o signal_.o s_stop.o \
D 2
	s_paus.o system_.o getenv_.o rand_.o bit.o range.o \
E 2
I 2
	s_paus.o system_.o getenv_.o rand_.o range.o \
E 5
I 5
D 6
MISC =	Version.o main.o s_rnge.o abort_.o getarg_.o iargc_.o signal_.o \
	s_stop.o s_paus.o system_.o getenv_.o rand_.o range.o \
E 6
I 6
D 15
MISC =	Version.o main.o s_rnge.o abort_.o exit_.o \
E 15
I 15
D 16
MISC =	main.o s_rnge.o abort_.o exit_.o \
E 16
I 16
MISC =	main.o s_rnge.o abort_.o exit_.o long_.o short_.o \
E 16
E 15
D 8
	s_stop.o s_paus.o rand_.o range.o \
E 8
I 8
D 11
	s_stop.o s_paus.o rand_.o range.o traper_.o \
E 11
I 11
	s_stop.o s_paus.o rand_.o range.o traper_.o trapov_.o \
E 11
E 8
E 6
E 5
E 2
	dbesj0_.o dbesj1_.o dbesjn_.o dbesy0_.o dbesy1_.o dbesyn_.o \
	besj0_.o besj1_.o besjn_.o besy0_.o besy1_.o besyn_.o
POW =	pow_ci.o pow_dd.o pow_di.o pow_hh.o pow_ii.o  pow_ri.o pow_zi.o pow_zz.o
CX =	c_abs.o c_cos.o c_div.o c_exp.o c_log.o c_sin.o c_sqrt.o
DCX =	z_abs.o z_cos.o z_div.o z_exp.o z_log.o z_sin.o z_sqrt.o
REAL =	r_abs.o r_acos.o r_asin.o r_atan.o r_atn2.o r_cnjg.o r_cos.o\
	r_cosh.o r_dim.o r_exp.o r_imag.o r_int.o\
	r_lg10.o r_log.o r_mod.o r_nint.o r_sign.o\
	r_sin.o r_sinh.o r_sqrt.o r_tan.o r_tanh.o
DBL =	d_abs.o d_acos.o d_asin.o d_atan.o d_atn2.o\
	d_cnjg.o d_cos.o d_cosh.o d_dim.o d_exp.o\
	d_imag.o d_int.o d_lg10.o d_log.o d_mod.o\
	d_nint.o d_prod.o d_sign.o d_sin.o d_sinh.o\
	d_sqrt.o d_tan.o d_tanh.o 
INT =	i_abs.o i_dim.o i_dnnt.o i_indx.o i_len.o i_mod.o i_nint.o i_sign.o
HALF =	h_abs.o h_dim.o h_dnnt.o h_indx.o h_len.o h_mod.o  h_nint.o h_sign.o
CMP =	l_ge.o l_gt.o l_le.o l_lt.o hl_ge.o hl_gt.o hl_le.o hl_lt.o
D 5
CHAR =	s_cat.o s_cmp.o s_copy.o lnblnk_.o rindex_.o
E 5
I 5
EFL =	ef1asc_.o ef1cmc_.o
CHAR =	s_cat.o rindex_.o s_cmp.o s_copy.o lnblnk_.o
E 5

ALL =	$(MISC) $(POW) $(CX) $(DCX) $(REAL) $(DBL) $(INT) $(HALF) \
D 5
	$(CMP) $(CHAR) cabs.o tanh.o sinh.o
E 5
I 5
D 19
	$(CMP) $(EFL) $(CHAR) cabs.o tanh.o sinh.o
E 19
I 19
	$(CMP) $(EFL) $(CHAR)
E 19
E 5

D 5
libF77.a:	$(ALL)
E 5
I 5
D 20
all:	$(LIB)
E 20
I 20
all:	$(LIB) $(LIB_P)
E 20

D 15
$(LIB):	$(ALL)
E 15
I 15
$(LIB):	$(ALL) Version
E 15
E 5
D 14
	@echo 'Loading...'
E 14
D 5
	@rm -f libF77.a
	@ar rc libF77.a $(ALL)
	@ls -l libF77.a
	@echo 'Done'
E 5
I 5
D 20
	@rm -f $(LIB)
D 14
	@ar rc $(LIB) $(ALL)
E 14
I 14
D 15
	ar rc $(LIB) $(ALL)
E 15
I 15
	ar ru $(LIB) $(ALL) Version
E 20
I 20
	ar ru $(LIB) $?
	ranlib $(LIB)
	chmod 644 $(LIB)
E 20
E 15
E 14
	@ls -l $(LIB)
E 5

I 20
$(LIB_P):	$(ALL) Version
	cd profiled; ar ru ../$(LIB_P) $?
	ranlib $(LIB_P)
	chmod 644 $(LIB_P)
	@ls -l $(LIB_P)

E 20
D 6
c_abs.c c_cos.c c_div.c c_div.c c_exp.c c_log.c c_sin.c c_sqrt.c d_cnjg.c d_imag.c pow_ci.c pow_zi.c pow_zz.c r_cnjg.c r_imag.c z_abs.c z_cos.c z_div.c z_div.c z_exp.c z_log.c z_sin.c z_sqrt.c:	complex
E 6
I 6
c_abs.o c_cos.o c_div.o c_div.o c_exp.o c_log.o c_sin.o c_sqrt.o d_cnjg.o d_imag.o pow_ci.o pow_zi.o pow_zz.o r_cnjg.o r_imag.o z_abs.o z_cos.o z_div.o z_div.o z_exp.o z_log.o z_sin.o z_sqrt.o:	complex
E 6

I 11
trapov_.o: trapov_.c
D 12
	@cc -S trapov_.c
E 12
I 12
D 20
	@cc -S ${OPTIONS} trapov_.c
E 12
	@(echo "g/.set	L[0-9][0-9]*,0x0$$/s/0x0/0xf10/"; echo "x") \
E 20
I 20
	-cd profiled; \
		cc -S ${OPTIONS} ../trapov_.c; \
		(echo "g/.set	L[0-9][0-9]*,0x0$$/s/0x0/0xf10/"; echo "x") \
			| ex - trapov_.s; \
		as trapov_.s -o trapov_.o; \
		rm trapov_.s
	cc -S ${OPTIONS} trapov_.c
	(echo "g/.set	L[0-9][0-9]*,0x0$$/s/0x0/0xf10/"; echo "x") \
E 20
		| ex - trapov_.s
D 20
	@as trapov_.s -o trapov_.o
	@rm trapov_.s
E 20
I 20
	as trapov_.s -o trapov_.o
	rm trapov_.s
E 20

# compile, then strip unnecessary symbols
.c.o :
I 20
	-cd profiled; \
		cc -c -p ${CFLAGS} ${OPTIONS} ../$*.c; \
		ld -r -x $*.o; \
		mv a.out $*.o
E 20
D 12
	cc -O -c -DVAX -DUCBVAX $*.c
E 12
I 12
D 17
	cc -O -c ${OPTIONS} $*.c
E 17
I 17
	cc -c ${CFLAGS} ${OPTIONS} $*.c
E 17
E 12
	-ld -r -x $*.o
	mv a.out $*.o

E 11
D 5
install:	libF77.a
I 3
D 4
#	mv $(LIBDIR)/libF77.a $(LIBDIR)/libF77.a.old
E 4
I 4
	mv $(LIBDIR)/libF77.a $(LIBDIR)/libF77.a.old
E 4
E 3
	cp libF77.a $(LIBDIR)/libF77.a
	ranlib $(LIBDIR)/libF77.a
E 5
I 5
D 14
install:	$(LIB)
E 14
I 14
D 20
install:	$(LIBDIR)/$(LIB)
E 20
I 20
install:	$(LIBDIR)/$(LIB) $(LIBDIR)/$(LIB_P)
E 20

$(LIBDIR)/$(LIB):	$(LIB)
E 14
D 13
	mv $(LIBDIR)/$(LIB) $(LIBDIR)/$(LIB).old
E 13
I 13
D 21
	@-mv $(LIBDIR)/$(LIB) $(LIBDIR)/$(LIB).old
E 21
I 21
	@-mv $(LIBDIR)/$(LIB) $(OLDDIR)/$(LIB)
E 21
E 13
D 20
	cp $(LIB) $(LIBDIR)/$(LIB)
	ranlib $(LIBDIR)/$(LIB)
I 9
D 14
	chmod 644 $(LIBDIR)/$(LIB)
E 14
I 14
	@chmod 644 $(LIBDIR)/$(LIB)
E 20
I 20
	tar cf - $(LIB) | (cd $(LIBDIR); tar xvf - )
E 20
E 14
E 9
E 5

I 20
$(LIBDIR)/$(LIB_P):	$(LIB_P)
D 21
	@-mv $(LIBDIR)/$(LIB_P) $(LIBDIR)/$(LIB_P).old
E 21
I 21
	@-mv $(LIBDIR)/$(LIB_P) $(OLDDIR)/$(LIB_P)
E 21
	tar cf - $(LIB_P) | (cd $(LIBDIR); tar xvf - )

E 20
clean:
D 3
	rm -f *.o libF77.a
E 3
I 3
D 5
	rm -f $(ALL) libF77.a
E 5
I 5
D 20
	rm -f $(ALL) $(LIB)
E 20
I 20
	rm -f $(ALL) Version $(LIB) $(LIB_P) profiled/*
E 20
E 5
E 3

D 5
SOURCES = main.c s_rnge.c abort_.c getarg_.c iargc_.c signal_.c s_stop.c \
	s_paus.c system_.c getenv_.c rand_.c bit.c range.c \
E 5
I 5
D 6
SOURCES = Version.c main.c s_rnge.c abort_.c getarg_.c iargc_.c signal_.c \
	s_stop.c s_paus.c system_.c getenv_.c rand_.c bit.c range.c \
E 6
I 6
D 13
SOURCES = Version.c main.c s_rnge.c abort_.c exit_.c \
E 13
I 13
D 15
SOURCES = Version.c main.c s_rnge.c abort_.c exit_.c opcodes.h \
E 15
I 15
D 16
SOURCES = main.c s_rnge.c abort_.c exit_.c opcodes.h \
E 16
I 16
SOURCES = main.c s_rnge.c abort_.c exit_.c opcodes.h long_.c short_.c \
E 16
E 15
E 13
D 8
	s_stop.c s_paus.c rand_.c bit.c range.c \
E 8
I 8
D 11
	s_stop.c s_paus.c rand_.c bit.c range.c traper_.c \
E 11
I 11
	s_stop.c s_paus.c rand_.c bit.c range.c traper_.c trapov_.c \
E 11
E 8
E 6
E 5
	dbesj0_.c dbesj1_.c dbesjn_.c dbesy0_.c dbesy1_.c dbesyn_.c \
	besj0_.c besj1_.c besjn_.c besy0_.c besy1_.c besyn_.c \
D 19
	cabs.c tanh.c sinh.c \
E 19
	pow_ci.c pow_dd.c pow_di.c pow_hh.c pow_ii.c  pow_ri.c pow_zi.c \
	pow_zz.c \
	c_abs.c c_cos.c c_div.c c_exp.c c_log.c c_sin.c c_sqrt.c \
	z_abs.c z_cos.c z_div.c z_exp.c z_log.c z_sin.c z_sqrt.c \
	r_abs.c r_acos.c r_asin.c r_atan.c r_atn2.c r_cnjg.c r_cos.c \
	r_cosh.c r_dim.c r_exp.c r_imag.c r_int.c \
	r_lg10.c r_log.c r_mod.c r_nint.c r_sign.c \
	r_sin.c r_sinh.c r_sqrt.c r_tan.c r_tanh.c \
	d_abs.c d_acos.c d_asin.c d_atan.c d_atn2.c \
	d_cnjg.c d_cos.c d_cosh.c d_dim.c d_exp.c \
	d_imag.c d_int.c d_lg10.c d_log.c d_mod.c \
	d_nint.c d_prod.c d_sign.c d_sin.c d_sinh.c \
	d_sqrt.c d_tan.c d_tanh.c \
	i_abs.c i_dim.c i_dnnt.c i_indx.c i_len.c i_mod.c i_nint.c i_sign.c \
	h_abs.c h_dim.c h_dnnt.c h_indx.c h_len.c h_mod.c  h_nint.c h_sign.c \
	l_ge.c l_gt.c l_le.c l_lt.c hl_ge.c hl_gt.c hl_le.c hl_lt.c \
I 5
	ef1asc_.c ef1cmc_.c \
E 5
D 6
	s_cat.c s_cmp.c s_copy.c lnblnk_.o rindex_.o
E 6
I 6
	s_cat.c s_cmp.c s_copy.c lnblnk_.c rindex_.c
I 15

Version:	$(SOURCES) mkvers
	@rm -f Version.c
	./mkvers $(LIB) $(SOURCES) > Version.c
	cc -c Version.c
	mv Version.o Version
I 20
	@rm -f profiled/Version
	ln Version profiled/Version
E 20

mkvers:	mkvers.c
	@cc mkvers.c -o mkvers
E 15
E 6

print:	index
D 10
	@pr index Makefile `ls $(SOURCES)` | lpr
E 10
I 10
	@pr index Makefile `ls $(SOURCES)` | $(LPR)
E 10

index:	$(SOURCES) mkindx
D 13
	@mkindx "libF77 Sources " Makefile $(SOURCES)
E 13
I 13
	@./mkindx "libF77 Sources " Makefile $(SOURCES)
E 13

mkindx:	mkindx.c
	@cc mkindx.c -o mkindx

D 11
tape:
D 5
	@tar cbf 20 $(TAPE) Makefile man complex $(SOURCES) mkindx.c
E 5
I 5
	@tar cbf 20 $(TAPE) Makefile man complex $(SOURCES) \
	mkindx.c bit.c subout.c
E 11
I 11
# End of Makefile
D 14
# Below this line is not normally distributed ...
E 14
I 14
# Below this line normally is not distributed ...
E 14

Makefile:	makefile
	@sed -n -e "1,/End of Makefile/p" makefile > Makefile

tape:	Makefile
D 18
	@-ln man/s.makefile man.s.makefile
	@ls man.s.makefile > /dev/null
	@rm -f man/s.makefile
D 14
	@-tar cbf 20 $(TAPE) READ_ME Makefile man complex $(SOURCES) \
E 14
I 14
	-tar cbf 20 $(TAPE) READ_ME Makefile man complex $(SOURCES) \
E 18
I 18
	-tar cbf 20 $(TAPE) READ_ME Makefile complex $(SOURCES) \
E 18
E 14
D 17
		mkindx.c bit.c subout.c
E 17
I 17
		mkindx.c subout.c
E 17
D 18
	@ln man.s.makefile man/s.makefile
	@rm -f man.s.makefile
E 18
I 14

# below here is SCCS stuff ...

main.c:	SCCS/s.main.c
	@rm -f main.c
	get SCCS/s.main.c

lnblnk_.c:	SCCS/s.lnblnk_.c
	@rm -f lnblnk_.c
	get SCCS/s.lnblnk_.c

range.c:	SCCS/s.range.c
	@rm -f range.c
	get SCCS/s.range.c

rindex_.c:	SCCS/s.rindex_.c
	@rm -f rindex_.c
	get SCCS/s.rindex_.c

traper_.c:	SCCS/s.traper_.c
	@rm -f traper_.c
	get SCCS/s.traper_.c

trapov_.c:	SCCS/s.trapov_.c
	@rm -f trapov_.c
	get SCCS/s.trapov_.c
E 14
E 11
E 5
E 1
