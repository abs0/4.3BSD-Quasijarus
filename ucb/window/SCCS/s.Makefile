h11228
s 00010/00005/00306
d D 3.9 88/06/29 21:35:19 bostic 10 9
c install approved copyright notice
e
s 00001/00001/00310
d D 3.8 88/05/22 03:27:40 edward 9 7
c added make.out and tags to clean
e
s 00001/00001/00310
d R 3.8 88/05/22 01:49:28 edward 8 7
c added make.out to clean
e
s 00010/00004/00301
d D 3.7 88/02/21 13:36:25 bostic 7 6
c attach Berkeley specific copyright
e
s 00011/00003/00294
d D 3.6 87/10/04 18:07:53 edward 6 5
c added Wyse 60 and 75 support (from mips!dce)
e
s 00127/00368/00170
d D 3.5 87/10/04 17:42:51 edward 5 4
c dependency changes made by an unknown person, probably done
c automatically.  maybe this thing shouldn't be under SCCS
e
s 00523/00448/00015
d D 3.4 87/07/27 17:03:20 bostic 4 3
c new template
e
s 00001/00001/00462
d D 3.3 87/04/09 13:00:06 edward 3 2
c remove a.out in make clean
e
s 00037/00022/00426
d D 3.2 86/08/04 15:15:49 edward 2 1
c ttzentec.c added
e
s 00448/00000/00000
d D 3.1 85/06/19 19:15:51 mckusick 1 0
c date and time created 85/06/19 19:15:51 by mckusick
e
u
U
t
T
I 1
#
D 4
# Copyright (c) 1980 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
D 7
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 7
I 7
# All rights reserved.
E 7
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
D 7
#	%W%	(Berkeley)	%G%
E 7
I 7
# Redistribution and use in source and binary forms are permitted
D 10
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 7
E 4
#
I 7
#	%W% (Berkeley) %G%
#
E 7
D 4
#
# Window makefile, update with mkmf (or "make depend")
#
CFLAGS        = -O -R
E 4
I 4
CFLAGS=	-O -R
LIBC=	/lib/libc.a
SRCS=	char.c cmd.c cmd1.c cmd2.c cmd3.c cmd4.c cmd5.c cmd6.c cmd7.c \
	context.c error.c lcmd.c lcmd1.c lcmd2.c main.c mloop.c parser1.c \
	parser2.c parser3.c parser4.c parser5.c scanner.c startup.c string.c \
	ttf100.c ttgeneric.c tth19.c tth29.c ttinit.c ttoutput.c tttermcap.c \
D 6
	tttvi925.c ttzentec.c var.c win.c wwadd.c wwalloc.c wwbox.c wwchild.c \
E 6
I 6
	tttvi925.c ttwyse60.c ttwyse75.c ttzentec.c \
	var.c win.c wwadd.c wwalloc.c wwbox.c wwchild.c \
E 6
	wwclose.c wwclreol.c wwclreos.c wwcursor.c wwdata.c wwdelchar.c \
	wwdelete.c wwdelline.c wwdump.c wwend.c wwenviron.c wwerror.c \
	wwflush.c wwframe.c wwgets.c wwinit.c wwinschar.c wwinsline.c \
	wwiomux.c wwlabel.c wwmisc.c wwmove.c wwopen.c wwprintf.c wwpty.c \
	wwputc.c wwputs.c wwredraw.c wwredrawwin.c wwrint.c wwscroll.c \
	wwsize.c wwspawn.c wwsuspend.c wwtty.c wwunframe.c wwupdate.c \
	wwwrite.c
OBJS=	char.o cmd.o cmd1.o cmd2.o cmd3.o cmd4.o cmd5.o cmd6.o cmd7.o \
	context.o error.o lcmd.o lcmd1.o lcmd2.o main.o mloop.o parser1.o \
	parser2.o parser3.o parser4.o parser5.o scanner.o startup.o string.o \
	ttf100.o ttgeneric.o tth19.o tth29.o ttinit.o ttoutput.o tttermcap.o \
D 6
	tttvi925.o ttzentec.o var.o win.o wwadd.o wwalloc.o wwbox.o wwchild.o \
E 6
I 6
	tttvi925.o ttwyse60.o ttwyse75.o ttzentec.o \
	var.o win.o wwadd.o wwalloc.o wwbox.o wwchild.o \
E 6
	wwclose.o wwclreol.o wwclreos.o wwcursor.o wwdata.o wwdelchar.o \
	wwdelete.o wwdelline.o wwdump.o wwend.o wwenviron.o wwerror.o \
	wwflush.o wwframe.o wwgets.o wwinit.o wwinschar.o wwinsline.o \
	wwiomux.o wwlabel.o wwmisc.o wwmove.o wwopen.o wwprintf.o wwpty.o \
	wwputc.o wwputs.o wwredraw.o wwredrawwin.o wwrint.o wwscroll.o \
	wwsize.o wwspawn.o wwsuspend.o wwtty.o wwunframe.o wwupdate.o \
	wwwrite.o
E 4

D 4
EXTHDRS	      = /usr/include/fcntl.h \
		/usr/include/setjmp.h \
		/usr/include/sgtty.h \
		/usr/include/signal.h \
		/usr/include/stdio.h \
		/usr/include/sys/errno.h \
		/usr/include/sys/ioctl.h \
		/usr/include/sys/resource.h \
		/usr/include/sys/signal.h \
		/usr/include/sys/socket.h \
		/usr/include/sys/time.h \
		/usr/include/sys/ttychars.h \
I 2
		/usr/include/sys/ttychars.h \
E 2
		/usr/include/sys/ttydev.h \
I 2
		/usr/include/sys/ttydev.h \
E 2
		/usr/include/sys/types.h \
D 2
		/usr/include/sys/wait.h
E 2
I 2
		/usr/include/sys/wait.h \
		/usr/include/time.h
E 4
I 4
all: window
E 4
E 2

D 4
HDRS	      = alias.h \
		char.h \
		context.h \
		defs.h \
		lcmd.h \
		local.h \
		parser.h \
		string.h \
		token.h \
		tt.h \
		value.h \
		var.h \
		ww.h
E 4
I 4
window: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} -ltermcap
E 4

D 4
LDFLAGS	      =
E 4
I 4
clean: FRC
D 9
	rm -f ${OBJS} core window
E 9
I 9
	rm -f ${OBJS} core window make.out tags
E 9
E 4

D 4
LIBS	      = /usr/lib/libtermcap.a
E 4
I 4
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 4

D 4
LINKER	      = cc
E 4
I 4
install: FRC
	install -s -o bin -g bin -m 755 window ${DESTDIR}/usr/ucb/window
#	install -c -o bin -g bin -m 755 windowrc ${DESTDIR}/usr/local/lib/windowrc
E 4

D 4
MAKEFILE      = Makefile
E 4
I 4
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 4

D 4
OBJS	      = char.o \
		cmd.o \
		cmd1.o \
		cmd2.o \
		cmd3.o \
		cmd4.o \
		cmd5.o \
		cmd6.o \
		cmd7.o \
		context.o \
		error.o \
		lcmd.o \
		lcmd1.o \
		lcmd2.o \
		main.o \
		mloop.o \
		parser1.o \
		parser2.o \
		parser3.o \
		parser4.o \
		parser5.o \
		scanner.o \
		startup.o \
		string.o \
		ttf100.o \
		ttgeneric.o \
		tth19.o \
		tth29.o \
		ttinit.o \
		ttoutput.o \
		tttermcap.o \
		tttvi925.o \
I 2
		ttzentec.o \
E 2
		var.o \
		win.o \
		wwadd.o \
		wwalloc.o \
		wwbox.o \
		wwchild.o \
		wwclose.o \
		wwclreol.o \
		wwclreos.o \
		wwcursor.o \
		wwdata.o \
		wwdelchar.o \
		wwdelete.o \
		wwdelline.o \
		wwdump.o \
		wwend.o \
		wwenviron.o \
		wwerror.o \
		wwflush.o \
		wwframe.o \
		wwgets.o \
		wwinit.o \
		wwinschar.o \
		wwinsline.o \
		wwiomux.o \
		wwlabel.o \
		wwmisc.o \
		wwmove.o \
		wwopen.o \
		wwprintf.o \
		wwpty.o \
		wwputc.o \
		wwputs.o \
		wwredraw.o \
		wwredrawwin.o \
		wwrint.o \
		wwscroll.o \
		wwsize.o \
		wwspawn.o \
		wwsuspend.o \
		wwtty.o \
		wwunframe.o \
		wwupdate.o \
		wwwrite.o
E 4
I 4
tags: FRC
	ctags ${SRCS}
E 4

D 4
PRINT	      = pr
E 4
I 4
FRC:
E 4

D 4
PROGRAM	      = a.out
E 4
I 4
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 4

D 4
SRCS	      = char.c \
		cmd.c \
		cmd1.c \
		cmd2.c \
		cmd3.c \
		cmd4.c \
		cmd5.c \
		cmd6.c \
		cmd7.c \
		context.c \
		error.c \
		lcmd.c \
		lcmd1.c \
		lcmd2.c \
		main.c \
		mloop.c \
		parser1.c \
		parser2.c \
		parser3.c \
		parser4.c \
		parser5.c \
		scanner.c \
		startup.c \
		string.c \
		ttf100.c \
		ttgeneric.c \
		tth19.c \
		tth29.c \
		ttinit.c \
		ttoutput.c \
		tttermcap.c \
		tttvi925.c \
I 2
		ttzentec.c \
E 2
		var.c \
		win.c \
		wwadd.c \
		wwalloc.c \
		wwbox.c \
		wwchild.c \
		wwclose.c \
		wwclreol.c \
		wwclreos.c \
		wwcursor.c \
		wwdata.c \
		wwdelchar.c \
		wwdelete.c \
		wwdelline.c \
		wwdump.c \
		wwend.c \
		wwenviron.c \
		wwerror.c \
		wwflush.c \
		wwframe.c \
		wwgets.c \
		wwinit.c \
		wwinschar.c \
		wwinsline.c \
		wwiomux.c \
		wwlabel.c \
		wwmisc.c \
		wwmove.c \
		wwopen.c \
		wwprintf.c \
		wwpty.c \
		wwputc.c \
		wwputs.c \
		wwredraw.c \
		wwredrawwin.c \
		wwrint.c \
		wwscroll.c \
		wwsize.c \
		wwspawn.c \
		wwsuspend.c \
		wwtty.c \
		wwunframe.c \
		wwupdate.c \
		wwwrite.c

all:		$(PROGRAM)

$(PROGRAM):     $(OBJS) $(LIBS)
		@echo -n "Loading $(PROGRAM) ... "
		@$(LINKER) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROGRAM)
		@echo "done"

D 3
clean:;		@rm -f $(OBJS) make.out
E 3
I 3
clean:;		@rm -f $(OBJS) make.out a.out
E 3

depend:;	@mkmf -f $(MAKEFILE) PROGRAM=$(PROGRAM)

install:	$(PROGRAM) windowrc
		install -s a.out $(DESTDIR)/usr/ucb/window
#		install -c windowrc $(DESTDIR)/usr/local/lib

print:;		@$(PRINT) $(MAKEFILE) README $(HDRS) $(SRCS)

tags:           $(HDRS) $(SRCS); @ctags $(HDRS) $(SRCS)

lint:;		@lint -z $(SRCS)

wc:;		@wc $(SRCS) $(HDRS)

###
char.o: char.h
cmd.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h char.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	char.h
E 2
cmd1.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h char.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	char.h
E 2
cmd2.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
E 2
cmd3.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h string.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	string.h
E 2
cmd4.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
E 2
cmd5.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
E 2
cmd6.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h string.h char.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	string.h char.h
E 2
cmd7.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
E 2
context.o: /usr/include/stdio.h value.h string.h context.h
error.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h value.h context.h \
	/usr/include/stdio.h char.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	value.h context.h /usr/include/stdio.h char.h
E 2
lcmd.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h value.h lcmd.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	value.h lcmd.h
E 2
lcmd1.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h string.h value.h lcmd.h \
	var.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	string.h value.h lcmd.h var.h
E 2
lcmd2.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h string.h value.h var.h \
	lcmd.h /usr/include/sys/resource.h alias.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	string.h value.h var.h lcmd.h /usr/include/sys/resource.h alias.h
E 2
main.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h \
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
E 2
	/usr/include/sys/signal.h /usr/include/stdio.h string.h char.h \
	local.h
mloop.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
E 2
parser1.o: parser.h /usr/include/stdio.h value.h context.h token.h string.h
parser2.o: parser.h /usr/include/stdio.h value.h context.h token.h string.h \
	var.h lcmd.h alias.h
parser3.o: parser.h /usr/include/stdio.h value.h context.h token.h string.h
parser4.o: parser.h /usr/include/stdio.h value.h context.h token.h string.h
parser5.o: parser.h /usr/include/stdio.h value.h context.h token.h string.h \
	var.h
scanner.o: /usr/include/stdio.h value.h token.h context.h string.h
startup.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h value.h var.h char.h \
	local.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	value.h var.h char.h local.h
E 2
string.o: string.h
ttf100.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
ttgeneric.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
tth19.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
tth29.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
ttinit.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
ttoutput.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h /usr/include/sys/errno.h
tttermcap.o: tt.h
tttvi925.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
I 2
ttzentec.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
E 2
var.o: value.h var.h string.h
win.o: defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h char.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	char.h
E 2
wwadd.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwalloc.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwbox.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwchild.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h /usr/include/sys/wait.h
wwclose.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h /usr/include/signal.h
wwclreol.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwclreos.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwcursor.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwdata.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwdelchar.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwdelete.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwdelline.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwdump.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwend.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwenviron.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h /usr/include/sys/signal.h
wwerror.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwflush.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwframe.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwgets.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h char.h
wwinit.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h /usr/include/sys/signal.h \
	/usr/include/fcntl.h char.h
wwinschar.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwinsline.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwiomux.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
D 2
	/usr/include/setjmp.h /usr/include/sys/time.h
E 2
I 2
	/usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h \
	/usr/include/sys/types.h
E 2
wwlabel.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h char.h
wwmisc.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h char.h
wwmove.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwopen.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h /usr/include/sys/types.h \
	/usr/include/sys/socket.h
wwprintf.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h /usr/include/stdio.h
wwpty.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwputc.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwputs.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwredraw.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwredrawwin.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwrint.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h /usr/include/fcntl.h /usr/include/sys/signal.h
wwscroll.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwsize.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwspawn.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h /usr/include/sys/signal.h
wwsuspend.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h /usr/include/sys/signal.h
wwtty.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h /usr/include/fcntl.h
wwunframe.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h
wwupdate.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h
wwwrite.o: ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h \
	/usr/include/sys/ttychars.h /usr/include/sys/ttydev.h \
	/usr/include/setjmp.h tt.h char.h
E 4
I 4
D 5
char.o: char.c
char.o:char.h
cmd.o: cmd.c
cmd.o:defs.h
cmd.o:ww.h
cmd.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
char.o: char.c char.h
cmd.o: cmd.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
cmd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
cmd.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
cmd.o:char.h
cmd1.o: cmd1.c
cmd1.o:defs.h
cmd1.o:ww.h
cmd1.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
cmd.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h char.h
cmd1.o: cmd1.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
cmd1.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmd1.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
cmd1.o:char.h
cmd2.o: cmd2.c
cmd2.o:defs.h
cmd2.o:ww.h
cmd2.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
cmd1.o: char.h
cmd2.o: cmd2.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
cmd2.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmd2.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
cmd3.o: cmd3.c
cmd3.o:defs.h
cmd3.o:ww.h
cmd3.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
cmd3.o: cmd3.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
cmd3.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmd3.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
cmd3.o:string.h
cmd4.o: cmd4.c
cmd4.o:defs.h
cmd4.o:ww.h
cmd4.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
cmd3.o: string.h
cmd4.o: cmd4.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
cmd4.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmd4.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
cmd5.o: cmd5.c
cmd5.o:defs.h
cmd5.o:ww.h
cmd5.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
cmd5.o: cmd5.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
cmd5.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmd5.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
cmd6.o: cmd6.c
cmd6.o:defs.h
cmd6.o:ww.h
cmd6.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
cmd6.o: cmd6.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
cmd6.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmd6.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
cmd6.o:string.h
cmd6.o:char.h
cmd7.o: cmd7.c
cmd7.o:defs.h
cmd7.o:ww.h
cmd7.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
cmd6.o: string.h char.h
cmd7.o: cmd7.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
cmd7.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmd7.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
context.o: context.c /usr/include/stdio.h
context.o:value.h
context.o:string.h
context.o:context.h
E 5
I 5
context.o: context.c /usr/include/stdio.h value.h string.h context.h
E 5
context.o: /usr/include/stdio.h
D 5
error.o: error.c
error.o:defs.h
error.o:ww.h
error.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
error.o: error.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
error.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
error.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
error.o:value.h
error.o:context.h
error.o: /usr/include/stdio.h
error.o:char.h
lcmd.o: lcmd.c
lcmd.o:defs.h
lcmd.o:ww.h
lcmd.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
error.o: value.h context.h /usr/include/stdio.h char.h
lcmd.o: lcmd.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
lcmd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lcmd.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
lcmd.o:value.h
lcmd.o:lcmd.h
lcmd1.o: lcmd1.c
lcmd1.o:defs.h
lcmd1.o:ww.h
lcmd1.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
lcmd.o: value.h lcmd.h
lcmd1.o: lcmd1.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
lcmd1.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lcmd1.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
lcmd1.o:string.h
lcmd1.o:value.h
lcmd1.o:lcmd.h
lcmd1.o:var.h
lcmd2.o: lcmd2.c
lcmd2.o:defs.h
lcmd2.o:ww.h
lcmd2.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
lcmd1.o: string.h value.h lcmd.h var.h
lcmd2.o: lcmd2.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
lcmd2.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
lcmd2.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
lcmd2.o:string.h
lcmd2.o:value.h
lcmd2.o:var.h
lcmd2.o:lcmd.h
lcmd2.o: /usr/include/sys/resource.h
lcmd2.o:alias.h
main.o: main.c
main.o:defs.h
main.o:ww.h
main.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
lcmd2.o: string.h value.h var.h lcmd.h /usr/include/sys/resource.h alias.h
main.o: main.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
main.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
main.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
main.o: /usr/include/sys/signal.h /usr/include/stdio.h
main.o:string.h
main.o:char.h
main.o:local.h
mloop.o: mloop.c
mloop.o:defs.h
mloop.o:ww.h
mloop.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
main.o: /usr/include/sys/signal.h /usr/include/machine/trap.h
main.o: /usr/include/stdio.h string.h char.h local.h
mloop.o: mloop.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
mloop.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
mloop.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
parser1.o: parser1.c
parser1.o:parser.h
parser1.o: /usr/include/stdio.h
parser1.o:value.h
parser1.o:context.h
parser1.o: /usr/include/stdio.h
parser1.o:token.h
parser1.o:string.h
parser2.o: parser2.c
parser2.o:parser.h
parser2.o: /usr/include/stdio.h
parser2.o:value.h
parser2.o:context.h
parser2.o: /usr/include/stdio.h
parser2.o:token.h
parser2.o:string.h
parser2.o:var.h
parser2.o:lcmd.h
parser2.o:alias.h
parser3.o: parser3.c
parser3.o:parser.h
parser3.o: /usr/include/stdio.h
parser3.o:value.h
parser3.o:context.h
parser3.o: /usr/include/stdio.h
parser3.o:token.h
parser3.o:string.h
parser4.o: parser4.c
parser4.o:parser.h
parser4.o: /usr/include/stdio.h
parser4.o:value.h
parser4.o:context.h
parser4.o: /usr/include/stdio.h
parser4.o:token.h
parser4.o:string.h
parser5.o: parser5.c
parser5.o:parser.h
parser5.o: /usr/include/stdio.h
parser5.o:value.h
parser5.o:context.h
parser5.o: /usr/include/stdio.h
parser5.o:token.h
parser5.o:string.h
parser5.o:var.h
scanner.o: scanner.c /usr/include/stdio.h
scanner.o:value.h
scanner.o:token.h
scanner.o:context.h
scanner.o: /usr/include/stdio.h
scanner.o:string.h
startup.o: startup.c
startup.o:defs.h
startup.o:ww.h
startup.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
parser1.o: parser1.c parser.h /usr/include/stdio.h value.h context.h
parser1.o: /usr/include/stdio.h token.h string.h
parser2.o: parser2.c parser.h /usr/include/stdio.h value.h context.h
parser2.o: /usr/include/stdio.h token.h string.h var.h lcmd.h alias.h
parser3.o: parser3.c parser.h /usr/include/stdio.h value.h context.h
parser3.o: /usr/include/stdio.h token.h string.h
parser4.o: parser4.c parser.h /usr/include/stdio.h value.h context.h
parser4.o: /usr/include/stdio.h token.h string.h
parser5.o: parser5.c parser.h /usr/include/stdio.h value.h context.h
parser5.o: /usr/include/stdio.h token.h string.h var.h
scanner.o: scanner.c /usr/include/stdio.h value.h token.h context.h
scanner.o: /usr/include/stdio.h string.h
startup.o: startup.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
startup.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
startup.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
D 5
startup.o:value.h
startup.o:var.h
startup.o:char.h
startup.o:local.h
string.o: string.c
string.o:string.h
ttf100.o: ttf100.c
ttf100.o:ww.h
ttf100.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
startup.o: value.h var.h char.h local.h
string.o: string.c string.h
ttf100.o: ttf100.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
ttf100.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
ttf100.o: /usr/include/setjmp.h
ttf100.o:tt.h
ttgeneric.o: ttgeneric.c
ttgeneric.o:ww.h
ttgeneric.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
ttf100.o: /usr/include/setjmp.h tt.h
ttgeneric.o: ttgeneric.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
ttgeneric.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
ttgeneric.o: /usr/include/setjmp.h
ttgeneric.o:tt.h
tth19.o: tth19.c
tth19.o:ww.h
tth19.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
ttgeneric.o: /usr/include/setjmp.h tt.h
tth19.o: tth19.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
tth19.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
tth19.o: /usr/include/setjmp.h
tth19.o:tt.h
tth29.o: tth29.c
tth29.o:ww.h
tth29.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
tth19.o: /usr/include/setjmp.h tt.h
tth29.o: tth29.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
tth29.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
tth29.o: /usr/include/setjmp.h
tth29.o:tt.h
ttinit.o: ttinit.c
ttinit.o:ww.h
ttinit.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
tth29.o: /usr/include/setjmp.h tt.h
ttinit.o: ttinit.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
ttinit.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
ttinit.o: /usr/include/setjmp.h
ttinit.o:tt.h
ttoutput.o: ttoutput.c
ttoutput.o:ww.h
ttoutput.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
ttinit.o: /usr/include/setjmp.h tt.h
ttoutput.o: ttoutput.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
ttoutput.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
ttoutput.o: /usr/include/setjmp.h
ttoutput.o:tt.h
ttoutput.o: /usr/include/sys/errno.h
tttermcap.o: tttermcap.c
tttermcap.o:tt.h
tttvi925.o: tttvi925.c
tttvi925.o:ww.h
tttvi925.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
ttoutput.o: /usr/include/setjmp.h tt.h /usr/include/sys/errno.h
tttermcap.o: tttermcap.c tt.h
tttvi925.o: tttvi925.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
tttvi925.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
tttvi925.o: /usr/include/setjmp.h
tttvi925.o:tt.h
ttzentec.o: ttzentec.c
ttzentec.o:ww.h
ttzentec.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
tttvi925.o: /usr/include/setjmp.h tt.h
I 6
ttwyse60.o: ttwyse60.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ttwyse60.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ttwyse60.o: /usr/include/setjmp.h tt.h
ttwyse75.o: ttwyse75.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ttwyse75.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
ttwyse75.o: /usr/include/setjmp.h tt.h
E 6
ttzentec.o: ttzentec.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
ttzentec.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
ttzentec.o: /usr/include/setjmp.h
ttzentec.o:tt.h
var.o: var.c
var.o:value.h
var.o:var.h
var.o:string.h
win.o: win.c
win.o:defs.h
win.o:ww.h
win.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
ttzentec.o: /usr/include/setjmp.h tt.h
var.o: var.c value.h var.h string.h
win.o: win.c defs.h ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
win.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
win.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
win.o:char.h
wwadd.o: wwadd.c
wwadd.o:ww.h
wwadd.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
win.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h char.h
wwadd.o: wwadd.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwadd.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwadd.o: /usr/include/setjmp.h
D 5
wwalloc.o: wwalloc.c
wwalloc.o:ww.h
wwalloc.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwalloc.o: wwalloc.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwalloc.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwalloc.o: /usr/include/setjmp.h
D 5
wwbox.o: wwbox.c
wwbox.o:ww.h
wwbox.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwbox.o: wwbox.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwbox.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwbox.o: /usr/include/setjmp.h
wwbox.o:tt.h
wwchild.o: wwchild.c
wwchild.o:ww.h
wwchild.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwbox.o: /usr/include/setjmp.h tt.h
wwchild.o: wwchild.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwchild.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwchild.o: /usr/include/setjmp.h /usr/include/sys/types.h
D 7
wwchild.o: /usr/include/sys/wait.h /usr/include/machine/machparam.h
E 7
I 7
wwchild.o: /usr/include/sys/wait.h /usr/include/machine/endian.h
E 7
D 5
wwclose.o: wwclose.c
wwclose.o:ww.h
wwclose.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwclose.o: wwclose.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwclose.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwclose.o: /usr/include/setjmp.h /usr/include/signal.h
D 5
wwclreol.o: wwclreol.c
wwclreol.o:ww.h
wwclreol.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwclose.o: /usr/include/machine/trap.h
wwclreol.o: wwclreol.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwclreol.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwclreol.o: /usr/include/setjmp.h
wwclreol.o:tt.h
wwclreos.o: wwclreos.c
wwclreos.o:ww.h
wwclreos.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwclreol.o: /usr/include/setjmp.h tt.h
wwclreos.o: wwclreos.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwclreos.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwclreos.o: /usr/include/setjmp.h
wwclreos.o:tt.h
wwcursor.o: wwcursor.c
wwcursor.o:ww.h
wwcursor.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwclreos.o: /usr/include/setjmp.h tt.h
wwcursor.o: wwcursor.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwcursor.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwcursor.o: /usr/include/setjmp.h
D 5
wwdata.o: wwdata.c
wwdata.o:ww.h
wwdata.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwdata.o: wwdata.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwdata.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwdata.o: /usr/include/setjmp.h
D 5
wwdelchar.o: wwdelchar.c
wwdelchar.o:ww.h
wwdelchar.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwdelchar.o: wwdelchar.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwdelchar.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwdelchar.o: /usr/include/setjmp.h
wwdelchar.o:tt.h
wwdelete.o: wwdelete.c
wwdelete.o:ww.h
wwdelete.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwdelchar.o: /usr/include/setjmp.h tt.h
wwdelete.o: wwdelete.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwdelete.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwdelete.o: /usr/include/setjmp.h
D 5
wwdelline.o: wwdelline.c
wwdelline.o:ww.h
wwdelline.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwdelline.o: wwdelline.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwdelline.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwdelline.o: /usr/include/setjmp.h
D 5
wwdump.o: wwdump.c
wwdump.o:ww.h
wwdump.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwdump.o: wwdump.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwdump.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwdump.o: /usr/include/setjmp.h
wwdump.o:tt.h
wwend.o: wwend.c
wwend.o:ww.h
wwend.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwdump.o: /usr/include/setjmp.h tt.h
wwend.o: wwend.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwend.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwend.o: /usr/include/setjmp.h
wwend.o:tt.h
wwenviron.o: wwenviron.c
wwenviron.o:ww.h
wwenviron.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwend.o: /usr/include/setjmp.h tt.h
wwenviron.o: wwenviron.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwenviron.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwenviron.o: /usr/include/setjmp.h /usr/include/sys/signal.h
D 5
wwerror.o: wwerror.c
wwerror.o:ww.h
wwerror.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwenviron.o: /usr/include/machine/trap.h
wwerror.o: wwerror.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwerror.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwerror.o: /usr/include/setjmp.h
D 5
wwflush.o: wwflush.c
wwflush.o:ww.h
wwflush.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwflush.o: wwflush.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwflush.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwflush.o: /usr/include/setjmp.h
wwflush.o:tt.h
wwframe.o: wwframe.c
wwframe.o:ww.h
wwframe.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwflush.o: /usr/include/setjmp.h tt.h
wwframe.o: wwframe.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwframe.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwframe.o: /usr/include/setjmp.h
wwframe.o:tt.h
wwgets.o: wwgets.c
wwgets.o:ww.h
wwgets.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwframe.o: /usr/include/setjmp.h tt.h
wwgets.o: wwgets.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwgets.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwgets.o: /usr/include/setjmp.h
wwgets.o:char.h
wwinit.o: wwinit.c
wwinit.o:ww.h
wwinit.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwgets.o: /usr/include/setjmp.h char.h
wwinit.o: wwinit.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwinit.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwinit.o: /usr/include/setjmp.h
wwinit.o:tt.h
wwinit.o: /usr/include/sys/signal.h /usr/include/fcntl.h
wwinit.o:char.h
wwinschar.o: wwinschar.c
wwinschar.o:ww.h
wwinschar.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwinit.o: /usr/include/setjmp.h tt.h /usr/include/sys/signal.h
wwinit.o: /usr/include/machine/trap.h /usr/include/fcntl.h char.h
wwinschar.o: wwinschar.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwinschar.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwinschar.o: /usr/include/setjmp.h
wwinschar.o:tt.h
wwinsline.o: wwinsline.c
wwinsline.o:ww.h
wwinsline.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwinschar.o: /usr/include/setjmp.h tt.h
wwinsline.o: wwinsline.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwinsline.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwinsline.o: /usr/include/setjmp.h
D 5
wwiomux.o: wwiomux.c
wwiomux.o:ww.h
wwiomux.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwiomux.o: wwiomux.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwiomux.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwiomux.o: /usr/include/setjmp.h /usr/include/sys/time.h /usr/include/time.h
wwiomux.o: /usr/include/sys/types.h
D 5
wwlabel.o: wwlabel.c
wwlabel.o:ww.h
wwlabel.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwlabel.o: wwlabel.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwlabel.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwlabel.o: /usr/include/setjmp.h
wwlabel.o:char.h
wwmisc.o: wwmisc.c
wwmisc.o:ww.h
wwmisc.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwlabel.o: /usr/include/setjmp.h char.h
wwmisc.o: wwmisc.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwmisc.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwmisc.o: /usr/include/setjmp.h
wwmisc.o:tt.h
wwmisc.o:char.h
wwmove.o: wwmove.c
wwmove.o:ww.h
wwmove.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwmisc.o: /usr/include/setjmp.h tt.h char.h
wwmove.o: wwmove.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwmove.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwmove.o: /usr/include/setjmp.h
D 5
wwopen.o: wwopen.c
wwopen.o:ww.h
wwopen.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwopen.o: wwopen.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwopen.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwopen.o: /usr/include/setjmp.h /usr/include/sys/types.h
wwopen.o: /usr/include/sys/socket.h
D 5
wwprintf.o: wwprintf.c
wwprintf.o:ww.h
wwprintf.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwprintf.o: wwprintf.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwprintf.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 6
wwprintf.o: /usr/include/setjmp.h /usr/include/stdio.h
E 6
I 6
wwprintf.o: /usr/include/setjmp.h /usr/include/varargs.h /usr/include/stdio.h
E 6
D 5
wwpty.o: wwpty.c
wwpty.o:ww.h
wwpty.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwpty.o: wwpty.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwpty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwpty.o: /usr/include/setjmp.h
D 5
wwputc.o: wwputc.c
wwputc.o:ww.h
wwputc.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwputc.o: wwputc.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwputc.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwputc.o: /usr/include/setjmp.h
D 5
wwputs.o: wwputs.c
wwputs.o:ww.h
wwputs.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwputs.o: wwputs.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwputs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwputs.o: /usr/include/setjmp.h
D 5
wwredraw.o: wwredraw.c
wwredraw.o:ww.h
wwredraw.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwredraw.o: wwredraw.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwredraw.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwredraw.o: /usr/include/setjmp.h
wwredraw.o:tt.h
wwredrawwin.o: wwredrawwin.c
wwredrawwin.o:ww.h
wwredrawwin.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwredraw.o: /usr/include/setjmp.h tt.h
wwredrawwin.o: wwredrawwin.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwredrawwin.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwredrawwin.o: /usr/include/setjmp.h
D 5
wwrint.o: wwrint.c
wwrint.o:ww.h
wwrint.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwrint.o: wwrint.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwrint.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwrint.o: /usr/include/setjmp.h /usr/include/fcntl.h /usr/include/sys/signal.h
D 5
wwscroll.o: wwscroll.c
wwscroll.o:ww.h
wwscroll.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwrint.o: /usr/include/machine/trap.h
wwscroll.o: wwscroll.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwscroll.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwscroll.o: /usr/include/setjmp.h
wwscroll.o:tt.h
wwsize.o: wwsize.c
wwsize.o:ww.h
wwsize.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwscroll.o: /usr/include/setjmp.h tt.h
wwsize.o: wwsize.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwsize.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwsize.o: /usr/include/setjmp.h
D 5
wwspawn.o: wwspawn.c
wwspawn.o:ww.h
wwspawn.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwspawn.o: wwspawn.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwspawn.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwspawn.o: /usr/include/setjmp.h /usr/include/sys/signal.h
D 5
wwsuspend.o: wwsuspend.c
wwsuspend.o:ww.h
wwsuspend.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwspawn.o: /usr/include/machine/trap.h
wwsuspend.o: wwsuspend.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwsuspend.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwsuspend.o: /usr/include/setjmp.h
wwsuspend.o:tt.h
wwsuspend.o: /usr/include/sys/signal.h
wwtty.o: wwtty.c
wwtty.o:ww.h
wwtty.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwsuspend.o: /usr/include/setjmp.h tt.h /usr/include/sys/signal.h
wwsuspend.o: /usr/include/machine/trap.h
wwtty.o: wwtty.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwtty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwtty.o: /usr/include/setjmp.h /usr/include/fcntl.h
D 5
wwunframe.o: wwunframe.c
wwunframe.o:ww.h
wwunframe.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwunframe.o: wwunframe.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwunframe.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
wwunframe.o: /usr/include/setjmp.h
D 5
wwupdate.o: wwupdate.c
wwupdate.o:ww.h
wwupdate.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwupdate.o: wwupdate.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwupdate.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwupdate.o: /usr/include/setjmp.h
wwupdate.o:tt.h
wwwrite.o: wwwrite.c
wwwrite.o:ww.h
wwwrite.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
I 5
wwupdate.o: /usr/include/setjmp.h tt.h
wwwrite.o: wwwrite.c ww.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 5
wwwrite.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
D 5
wwwrite.o: /usr/include/setjmp.h
wwwrite.o:tt.h
wwwrite.o:char.h
E 5
I 5
wwwrite.o: /usr/include/setjmp.h tt.h char.h
E 5

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1
