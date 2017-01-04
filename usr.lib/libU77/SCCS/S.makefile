h07676
s 00005/00003/00385
d D 1.17 83/05/11 21:17:28 dlw 17 16
c old lib to /usr/old/lib. DLW
e
s 00047/00014/00341
d D 1.16 83/05/06 15:28:01 dlw 16 15
c added profiled library; hostnm; symlnk; lstat. DLW
e
s 00002/00000/00353
d D 1.15 83/04/30 16:35:51 dlw 15 14
c added symlnk. DLW
e
s 00002/00000/00351
d D 1.14 83/04/25 11:26:39 dlw 14 13
c added rename. DLW
e
s 00002/00000/00349
d D 1.13 83/04/23 10:48:04 dlw 13 12
c added hostnm. DLW
e
s 00002/00000/00347
d D 1.12 83/04/20 23:28:24 dlw 12 11
c added f77lid_.c. DLW
e
s 00003/00006/00340
d D 1.11 83/04/16 22:27:09 dlw 11 10
c added chmod_.c; removed man dir from 'make tape'. DLW
e
s 00002/00000/00340
d D 1.10 83/01/10 18:47:24 dlw 10 9
c added tapeio. DLW
e
s 00138/00094/00200
d D 1.9 83/01/03 23:08:18 dlw 9 8
c cleaned up & adapted to SCCS subdir. DLW
e
s 00002/00002/00292
d D 1.8 82/06/03 20:45:38 dlw 8 7
c minor syntax fixes. DLW
e
s 00007/00001/00289
d D 1.7 82/01/07 17:52:20 dlw 7 6
c mv'd man/s.makefile out of tar's path; added READ_ME. DLW
e
s 00012/00002/00278
d D 1.6 82/01/07 12:42:09 dlw 6 5
c added rules for Makefile and deleted SCCS from 'tape'. DLW
e
s 00002/00000/00278
d D 1.5 82/01/07 12:15:59 dlw 5 4
c added alarm_. DLW
e
s 00131/00001/00147
d D 1.4 81/08/17 23:45:10 dlw 4 3
c added SCCS dependencies. DLW
e
s 00008/00002/00140
d D 1.3 81/08/14 19:52:54 dlw 3 2
c added isatty & ttynam & global def for 'lpr'. DLW
e
s 00010/00002/00132
d D 1.2 81/04/19 22:28:02 dlw 2 1
c added specific defs for Vax & PDP11. DLW
e
s 00134/00000/00000
d D 1.1 81/02/26 16:32:55 dlw 1 0
c date and time created 81/02/26 16:32:55 by dlw
e
u
U
t
T
I 1
# Makefile for f77 system lib, libU77.a
#	%W%	%G%

I 9
DESTDIR =
E 9
D 2
LIBDIR = /usr/ucb/lib
E 2
LIB = libU77.a
I 16
LIB_P = libU77_p.a
E 16
I 3
LPR = lpr
E 3
D 2
TAPE = /dev/nrmt1
E 2

I 2
# for 11's
D 4
#LIBDIR = /usr/ucb/lib
E 4
I 4
#ENV = ucb
D 9
#LIBDIR = /usr/$(ENV)/lib
E 9
I 9
#LIBDIR = ${DESTDIR}/usr/$(ENV)/lib
I 17
#OLDDIR = ${DESTDIR}/usr/old/lib
E 17
E 9
E 4
#TAPE = /dev/nrmt1

# for Vax
D 9
LIBDIR = /usr/lib
E 9
I 9
LIBDIR = ${DESTDIR}/usr/lib
E 9
D 17
TAPE = /dev/rnmt0.1600
E 17
I 17
OLDDIR = ${DESTDIR}/usr/old/lib
TAPE = /dev/rnmt0
E 17

E 2
CFLAGS = -O

SOURCES = \
	access_.c \
I 5
	alarm_.c \
E 5
	chdir_.c \
I 11
	chmod_.c \
E 11
	ctime_.c \
	dtime_.c \
	etime_.c \
I 12
	f77lid_.c \
E 12
	fdate_.c \
	fgetc_.c \
	fork_.c \
	fputc_.c \
	fseek_.c \
	fstat_.c \
	ftell_.c \
	gerror_.c \
	getarg_.c \
	getc_.c \
I 2
	getcwd_.c \
E 2
	getenv_.c \
	getgid_.c \
	getlog_.c \
	getpid_.c \
	getuid_.c \
D 3
	iargc_.c \
E 3
	gmtime_.c \
I 13
	hostnm_.c \
E 13
I 3
	iargc_.c \
E 3
	idate_.c \
	ierrno_.c \
I 3
	isatty_.c \
E 3
	itime_.c \
	kill_.c \
D 16
	loc_.c \
E 16
	link_.c \
I 16
	loc_.c \
	lstat_.c \
E 16
	ltime_.c \
	perror_.c \
	putc_.c \
	qsort_.c \
I 14
	rename_.c \
E 14
	signal_.c \
	sleep_.c \
	stat_.c \
I 15
	symlnk_.c \
E 15
	system_.c \
I 10
	tapeio.c \
E 10
	time_.c \
I 3
	ttynam_.c \
E 3
	unlink_.c \
	wait_.c

OBJECTS = \
	access_.o \
I 5
	alarm_.o \
E 5
	chdir_.o \
I 11
	chmod_.o \
E 11
	ctime_.o \
	dtime_.o \
	etime_.o \
I 12
	f77lid_.o \
E 12
	fdate_.o \
	fgetc_.o \
	fork_.o \
	fputc_.o \
	fseek_.o \
	fstat_.o \
	ftell_.o \
	gerror_.o \
	getarg_.o \
	getc_.o \
I 2
	getcwd_.o \
E 2
	getenv_.o \
	getgid_.o \
	getlog_.o \
	getpid_.o \
	getuid_.o \
	gmtime_.o \
I 13
	hostnm_.o \
E 13
	iargc_.o \
	idate_.o \
	ierrno_.o \
I 3
	isatty_.o \
E 3
	itime_.o \
	kill_.o \
I 16
	link_.o \
E 16
	loc_.o \
I 16
	lstat_.o \
E 16
	ltime_.o \
D 16
	link_.o \
E 16
	perror_.o \
	putc_.o \
	qsort_.o \
I 14
	rename_.o \
E 14
	signal_.o \
	sleep_.o \
	stat_.o \
I 15
	symlnk_.o \
E 15
	system_.o \
I 10
	tapeio.o \
E 10
	time_.o \
I 3
	ttynam_.o \
E 3
	unlink_.o \
	wait_.o

D 16
all:	$(LIB)
E 16
I 16
all:	$(LIB) $(LIB_P)
E 16

$(LIB):	$(OBJECTS) Version
D 9
	@echo Loading...
E 9
D 16
	@rm -f $(LIB)
D 9
	@ar rc $(LIB) $(OBJECTS) Version
E 9
I 9
	ar rc $(LIB) $(OBJECTS) Version
E 9
	@chmod 664 $(LIB)
E 16
I 16
	ar ru $(LIB) $?
	ranlib $(LIB)
	@chmod 644 $(LIB)
E 16
D 9
	@echo "Done..."
E 9

D 9
install:	$(LIB)
E 9
I 9
D 16
install:	$(LIBDIR)/$(LIB)
E 16
I 16
$(LIB_P):	$(OBJECTS) Version
	cd profiled; ar ru ../$(LIB_P) $?
	ranlib $(LIB_P)
	@chmod 644 $(LIB_P)
E 16

I 16
install:	$(LIBDIR)/$(LIB) $(LIBDIR)/$(LIB_P)

E 16
$(LIBDIR)/$(LIB):	$(LIB)
E 9
D 17
	@-mv $(LIBDIR)/$(LIB) $(LIBDIR)/$(LIB).old
E 17
I 17
	@-mv $(LIBDIR)/$(LIB) $(OLDDIR)/$(LIB)
E 17
D 16
	cp $(LIB) $(LIBDIR)/$(LIB)
	ranlib $(LIBDIR)/$(LIB)
I 3
	@chmod 644 $(LIBDIR)/$(LIB)
E 16
I 16
	tar cf - $(LIB) | (cd $(LIBDIR); tar xvf - )
E 16
E 3

I 16
$(LIBDIR)/$(LIB_P):	$(LIB_P)
D 17
	@-mv $(LIBDIR)/$(LIB_P) $(LIBDIR)/$(LIB_P).old
E 17
I 17
	@-mv $(LIBDIR)/$(LIB_P) $(OLDDIR)/$(LIB_P)
E 17
	tar cf - $(LIB_P) | (cd $(LIBDIR); tar xvf - )
E 16

I 16

E 16
#compile and strip unnecessary symbols
.c.o:
I 16
	-cd profiled; cc $(CFLAGS) -p -c ../$*.c; ld -r -x $*.o; mv a.out $*.o
E 16
	cc $(CFLAGS) -c $*.c
	-ld -r -x $*.o
	mv a.out $*.o

Version:	$(SOURCES) mkvers
	@rm -f Version.c
D 8
	mkvers $(LIB) $(SOURCES) > Version.c
E 8
I 8
	./mkvers $(LIB) $(SOURCES) > Version.c
E 8
	cc -c Version.c
	mv Version.o Version
I 16
	@rm -f profiled/Version
	ln Version profiled/Version
E 16

mkvers:	mkvers.c
	@cc mkvers.c -o mkvers

print:	index
D 3
	@pr index Makefile `ls $(SOURCES)` | lpr
E 3
I 3
	@pr index Makefile `ls $(SOURCES)` | $(LPR)
E 3

index:	$(SOURCES) mkindx
D 8
	@mkindx "f77 $(LIB) Source Listing " Makefile $(SOURCES)
E 8
I 8
	@./mkindx "f77 $(LIB) Source Listing " Makefile $(SOURCES)
E 8

mkindx:	mkindx.c
	@cc mkindx.c -o mkindx

clean:
D 16
	rm -f $(OBJECTS) $(LIB)
E 16
I 16
	rm -f $(OBJECTS) Version $(LIB) $(LIB_P) profiled/*
E 16

D 6
tape:
E 6
I 6
# End of Makefile
# Below this is not normally distributed ...

Makefile:	makefile
	@sed -n -e "1,/End of Makefile/p" makefile > Makefile

tape:	Makefile
E 6
D 7
	@tar cbf 20 $(TAPE) Makefile man $(SOURCES) mkindx.c mkvers.c
E 7
I 7
D 11
	@-ln man/s.makefile man.s.makefile
	@ls man.s.makefile > /dev/null
	@rm -f man/s.makefile
D 9
	@-tar cbf 20 $(TAPE) READ_ME Makefile man $(SOURCES) mkindx.c mkvers.c
E 9
I 9
	-tar cbf 20 $(TAPE) READ_ME Makefile man $(SOURCES) mkindx.c mkvers.c
E 9
	@ln man.s.makefile man/s.makefile
	@rm -f man.s.makefile
E 11
I 11
	-tar cbf 20 $(TAPE) READ_ME Makefile $(SOURCES) mkindx.c mkvers.c
E 11

E 7
I 4

# below here is SCCS stuff ---

D 9
access_.c:	s.access_.c
E 9
I 9
access_.c:	SCCS/s.access_.c
E 9
	rm -f access_.c
D 9
	get s.access_.c
I 6
alarm_.c:	s.alarm_.c
E 9
I 9
	get SCCS/s.access_.c

alarm_.c:	SCCS/s.alarm_.c
E 9
	rm -f alarm_.c
D 9
	get s.alarm_.c
E 6
chdir_.c:	s.chdir_.c
E 9
I 9
	get SCCS/s.alarm_.c

chdir_.c:	SCCS/s.chdir_.c
E 9
	rm -f chdir_.c
D 9
	get s.chdir_.c
ctime_.c:	s.ctime_.c
E 9
I 9
	get SCCS/s.chdir_.c

I 11
chmod_.c:	SCCS/s.chmod_.c
	rm -f chmod_.c
	get SCCS/s.chmod_.c

E 11
ctime_.c:	SCCS/s.ctime_.c
E 9
	rm -f ctime_.c
D 9
	get s.ctime_.c
dtime_.c:	s.dtime_.c
E 9
I 9
	get SCCS/s.ctime_.c

dtime_.c:	SCCS/s.dtime_.c
E 9
	rm -f dtime_.c
D 9
	get s.dtime_.c
etime_.c:	s.etime_.c
E 9
I 9
	get SCCS/s.dtime_.c

etime_.c:	SCCS/s.etime_.c
E 9
	rm -f etime_.c
D 9
	get s.etime_.c
fdate_.c:	s.fdate_.c
E 9
I 9
	get SCCS/s.etime_.c

I 16
f77lid_.c:	SCCS/s.f77lid_.c
	rm -f f77lid_.c
	get SCCS/s.f77lid_.c

E 16
fdate_.c:	SCCS/s.fdate_.c
E 9
	rm -f fdate_.c
D 9
	get s.fdate_.c
fgetc_.c:	s.fgetc_.c
E 9
I 9
	get SCCS/s.fdate_.c

fgetc_.c:	SCCS/s.fgetc_.c
E 9
	rm -f fgetc_.c
D 9
	get s.fgetc_.c
fork_.c:	s.fork_.c
E 9
I 9
	get SCCS/s.fgetc_.c

fork_.c:	SCCS/s.fork_.c
E 9
	rm -f fork_.c
D 9
	get s.fork_.c
fputc_.c:	s.fputc_.c
E 9
I 9
	get SCCS/s.fork_.c

fputc_.c:	SCCS/s.fputc_.c
E 9
	rm -f fputc_.c
D 9
	get s.fputc_.c
fseek_.c:	s.fseek_.c
E 9
I 9
	get SCCS/s.fputc_.c

fseek_.c:	SCCS/s.fseek_.c
E 9
	rm -f fseek_.c
D 9
	get s.fseek_.c
fstat_.c:	s.fstat_.c
E 9
I 9
	get SCCS/s.fseek_.c

fstat_.c:	SCCS/s.fstat_.c
E 9
	rm -f fstat_.c
D 9
	get s.fstat_.c
ftell_.c:	s.ftell_.c
E 9
I 9
	get SCCS/s.fstat_.c

ftell_.c:	SCCS/s.ftell_.c
E 9
	rm -f ftell_.c
D 9
	get s.ftell_.c
gerror_.c:	s.gerror_.c
E 9
I 9
	get SCCS/s.ftell_.c

gerror_.c:	SCCS/s.gerror_.c
E 9
	rm -f gerror_.c
D 9
	get s.gerror_.c
getarg_.c:	s.getarg_.c
E 9
I 9
	get SCCS/s.gerror_.c

getarg_.c:	SCCS/s.getarg_.c
E 9
	rm -f getarg_.c
D 9
	get s.getarg_.c
getc_.c:	s.getc_.c
E 9
I 9
	get SCCS/s.getarg_.c

getc_.c:	SCCS/s.getc_.c
E 9
	rm -f getc_.c
D 9
	get s.getc_.c
getcwd_.c:	s.getcwd_.c
E 9
I 9
	get SCCS/s.getc_.c

getcwd_.c:	SCCS/s.getcwd_.c
E 9
	rm -f getcwd_.c
D 9
	get s.getcwd_.c
getenv_.c:	s.getenv_.c
E 9
I 9
	get SCCS/s.getcwd_.c

getenv_.c:	SCCS/s.getenv_.c
E 9
	rm -f getenv_.c
D 9
	get s.getenv_.c
getgid_.c:	s.getgid_.c
E 9
I 9
	get SCCS/s.getenv_.c

getgid_.c:	SCCS/s.getgid_.c
E 9
	rm -f getgid_.c
D 9
	get s.getgid_.c
getlog_.c:	s.getlog_.c
E 9
I 9
	get SCCS/s.getgid_.c

getlog_.c:	SCCS/s.getlog_.c
E 9
	rm -f getlog_.c
D 9
	get s.getlog_.c
getpid_.c:	s.getpid_.c
E 9
I 9
	get SCCS/s.getlog_.c

getpid_.c:	SCCS/s.getpid_.c
E 9
	rm -f getpid_.c
D 9
	get s.getpid_.c
getuid_.c:	s.getuid_.c
E 9
I 9
	get SCCS/s.getpid_.c

getuid_.c:	SCCS/s.getuid_.c
E 9
	rm -f getuid_.c
D 9
	get s.getuid_.c
gmtime_.c:	s.gmtime_.c
E 9
I 9
	get SCCS/s.getuid_.c

gmtime_.c:	SCCS/s.gmtime_.c
E 9
	rm -f gmtime_.c
D 9
	get s.gmtime_.c
iargc_.c:	s.iargc_.c
E 9
I 9
	get SCCS/s.gmtime_.c

I 16
hostnm_.c:	SCCS/s.hostnm_.c
	rm -f hostnm_.c
	get SCCS/s.hostnm_.c

E 16
iargc_.c:	SCCS/s.iargc_.c
E 9
	rm -f iargc_.c
D 9
	get s.iargc_.c
idate_.c:	s.idate_.c
E 9
I 9
	get SCCS/s.iargc_.c

idate_.c:	SCCS/s.idate_.c
E 9
	rm -f idate_.c
D 9
	get s.idate_.c
ierrno_.c:	s.ierrno_.c
E 9
I 9
	get SCCS/s.idate_.c

ierrno_.c:	SCCS/s.ierrno_.c
E 9
	rm -f ierrno_.c
D 9
	get s.ierrno_.c
isatty_.c:	s.isatty_.c
E 9
I 9
	get SCCS/s.ierrno_.c

isatty_.c:	SCCS/s.isatty_.c
E 9
	rm -f isatty_.c
D 9
	get s.isatty_.c
itime_.c:	s.itime_.c
E 9
I 9
	get SCCS/s.isatty_.c

itime_.c:	SCCS/s.itime_.c
E 9
	rm -f itime_.c
D 9
	get s.itime_.c
kill_.c:	s.kill_.c
E 9
I 9
	get SCCS/s.itime_.c

kill_.c:	SCCS/s.kill_.c
E 9
	rm -f kill_.c
D 9
	get s.kill_.c
loc_.c:	s.loc_.c
E 9
I 9
	get SCCS/s.kill_.c

I 16
link_.c:	SCCS/s.link_.c
	rm -f link_.c
	get SCCS/s.link_.c

E 16
loc_.c:	SCCS/s.loc_.c
E 9
	rm -f loc_.c
D 9
	get s.loc_.c
link_.c:	s.link_.c
E 9
I 9
	get SCCS/s.loc_.c

D 16
link_.c:	SCCS/s.link_.c
E 9
	rm -f link_.c
D 9
	get s.link_.c
ltime_.c:	s.ltime_.c
E 9
I 9
	get SCCS/s.link_.c
E 16
I 16
lstat_.c:	SCCS/s.lstat_.c
	rm -f lstat_.c
	get SCCS/s.lstat_.c
E 16

ltime_.c:	SCCS/s.ltime_.c
E 9
	rm -f ltime_.c
D 9
	get s.ltime_.c
perror_.c:	s.perror_.c
E 9
I 9
	get SCCS/s.ltime_.c

perror_.c:	SCCS/s.perror_.c
E 9
	rm -f perror_.c
D 9
	get s.perror_.c
putc_.c:	s.putc_.c
E 9
I 9
	get SCCS/s.perror_.c

putc_.c:	SCCS/s.putc_.c
E 9
	rm -f putc_.c
D 9
	get s.putc_.c
qsort_.c:	s.qsort_.c
E 9
I 9
	get SCCS/s.putc_.c

qsort_.c:	SCCS/s.qsort_.c
E 9
	rm -f qsort_.c
D 9
	get s.qsort_.c
signal_.c:	s.signal_.c
E 9
I 9
	get SCCS/s.qsort_.c

I 16
rename_.c:	SCCS/s.rename_.c
	rm -f rename_.c
	get SCCS/s.rename_.c

E 16
signal_.c:	SCCS/s.signal_.c
E 9
	rm -f signal_.c
D 9
	get s.signal_.c
sleep_.c:	s.sleep_.c
E 9
I 9
	get SCCS/s.signal_.c

sleep_.c:	SCCS/s.sleep_.c
E 9
	rm -f sleep_.c
D 9
	get s.sleep_.c
stat_.c:	s.stat_.c
E 9
I 9
	get SCCS/s.sleep_.c

stat_.c:	SCCS/s.stat_.c
E 9
	rm -f stat_.c
D 9
	get s.stat_.c
system_.c:	s.system_.c
E 9
I 9
	get SCCS/s.stat_.c
I 16

symlnk_.c:	SCCS/s.symlnk_.c
	rm -f symlnk_.c
	get SCCS/s.symlnk_.c
E 16

system_.c:	SCCS/s.system_.c
E 9
	rm -f system_.c
D 9
	get s.system_.c
time_.c:	s.time_.c
E 9
I 9
	get SCCS/s.system_.c

time_.c:	SCCS/s.time_.c
E 9
	rm -f time_.c
D 9
	get s.time_.c
ttynam_.c:	s.ttynam_.c
E 9
I 9
	get SCCS/s.time_.c

tapeio.c:	SCCS/s.tapeio.c
	@rm -f tapeio.c
	get SCCS/s.tapeio.c

ttynam_.c:	SCCS/s.ttynam_.c
E 9
	rm -f ttynam_.c
D 9
	get s.ttynam_.c
unlink_.c:	s.unlink_.c
E 9
I 9
	get SCCS/s.ttynam_.c

unlink_.c:	SCCS/s.unlink_.c
E 9
	rm -f unlink_.c
D 9
	get s.unlink_.c
wait_.c:	s.wait_.c
E 9
I 9
	get SCCS/s.unlink_.c

wait_.c:	SCCS/s.wait_.c
E 9
	rm -f wait_.c
D 9
	get s.wait_.c
E 9
I 9
	get SCCS/s.wait_.c

E 9
E 4
E 1
