h08318
s 00001/00001/00032
d D 4.14 00/03/27 10:29:45 msokolov 25 24
c build and install the cf files too
e
s 00024/00071/00009
d D 4.13 88/05/01 19:59:02 bostic 24 23
m 
c Makefile for tahoe release
e
s 00007/00005/00073
d D 4.12 87/06/21 14:58:53 bostic 23 22
m 
c new template
e
s 00001/00002/00077
d D 4.11 87/04/02 11:43:05 bostic 22 21
m 
c setgid kmem now
e
s 00001/00003/00078
d D 4.10 86/11/03 10:30:49 mckusick 21 20
m 
c cf no longer exists
e
s 00008/00003/00073
d D 4.9 86/05/30 10:24:39 bloom 20 19
m 
c install cf file seperately, fix links on install
e
s 00001/00001/00075
d D 4.8 85/11/11 14:42:11 miriam 19 18
m 
c Cosmetic change.
e
s 00001/00001/00075
d D 4.7 85/11/11 14:35:15 miriam 18 17
m 
c Change makefile to reflect using system syslog, ie don't make 
c aux/syslog.
e
s 00005/00005/00071
d D 4.6 85/10/09 15:44:45 miriam 17 16
m 
c Install sendmail with explicit ownership of root.
e
s 00001/00001/00075
d D 4.5 85/09/19 00:24:00 mckusick 16 15
m 
c deal with fully specified host names
e
s 00001/00000/00075
d D 4.4 85/08/19 15:49:12 miriam 15 14
m 
c Put in chgrp to kmem for load average.
e
s 00014/00014/00061
d D 4.3 85/02/15 09:34:08 eric 14 13
m 
c cleanup for aux/syslog changes
e
s 00001/00001/00074
d D 4.2 83/09/12 13:36:52 karels 13 12
m 
c no "-c" on install (so make all will)
e
s 00000/00000/00075
d D 4.1 83/07/25 19:03:35 eric 12 11
m 
c 4.2 release version
e
s 00012/00012/00063
d D 3.11 83/07/09 22:55:48 sam 11 10
m 
c pass MFLAGS please!!!
e
s 00002/00002/00073
d D 3.10 83/06/18 16:02:29 sam 10 9
m 
c quit making documents, I'm getting tired of removing them 
c from the spool queue
e
s 00001/00001/00074
d D 3.9 83/05/20 12:20:34 eric 9 8
m 
c add "h" flag to tar so that rmail.c will be included
e
s 00017/00018/00058
d D 3.8 83/02/09 10:31:14 eric 8 7
m 
c clean up install entry to use install script
e
s 00001/00000/00075
d D 3.7 83/02/09 10:06:53 eric 7 6
m 
c clean up clean entry for 4.1c release
e
s 00001/00000/00074
d D 3.6 83/02/09 09:32:07 eric 6 5
m 
c make clean in doc
e
s 00004/00000/00070
d D 3.5 83/01/16 17:34:10 eric 5 4
m 
c add "make tar" to create a tar image of the distribution
e
s 00006/00005/00064
d D 3.4 83/01/10 09:30:47 eric 4 3
m 
c choose the configuration file by calling "hostname"
e
s 00013/00009/00056
d D 3.3 83/01/01 15:56:30 eric 3 2
m 
c install /usr/adm/newsyslog when syslog is installed
e
s 00001/00001/00064
d D 3.2 82/12/27 10:57:57 eric 2 1
m 109
c make it all work....
e
s 00065/00000/00000
d D 3.1 82/12/26 20:52:37 eric 1 0
m 109
c date and time created 82/12/26 20:52:37 by eric
e
u
U
f b 
f i 
t
T
I 1
#
D 24
#	Makefile for sendmail base directory
E 24
I 24
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 24
#
D 24
#		%W%	%Y%	%G%
E 24
I 24
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 24
#
I 24
#	%W% (Berkeley) %G%
#
D 25
SUBDIR=	lib src aux
E 25
I 25
SUBDIR=	lib src aux cf/cf
E 25
E 24

D 18
ALL=	src/sendmail aux/syslog
E 18
I 18
D 24
ALL=	src/sendmail
E 18
DIRS=	$(DESTDIR)/usr/spool/mqueue
SRCDIR=	$(DESTDIR)/usr/src/usr.lib/sendmail
D 21
ALLDIRS=include adm src aux md cf lib doc adb test
E 21
I 21
ALLDIRS=include adm src aux md lib doc adb test
E 21
D 4
MACH=	calder
E 4
I 4
BACKUP=	calder
E 4
SENDMAIL=$(DESTDIR)/usr/lib/sendmail
I 3
SYSLOG=	/usr/spool/mqueue/syslog
I 4
D 16
HOST=	`hostname | sed s/ucb//`
E 16
I 16
HOST=	`hostname | sed -e 's/ucb//' -e 's/\..*//'`
E 24
I 24
all: ${SUBDIR}
E 24
E 16
E 4
E 3

I 20
D 24
# When hardlinks are used, the references to LN below will need changes
# for DESTDIR != /
E 20
LN=	ln -s
CP=	cp
E 24
I 24
${SUBDIR}: FRC
	cd $@; make ${MFLAGS}
E 24

D 24
all:
D 11
	cd lib; make
	cd src; m4 Makefile.m4 > Makefile; make
D 2
	cd aux; make
E 2
I 2
	cd aux; m4 Makefile.m4 > Makefile; make
I 8
	cd cf;  make
D 10
	cd doc; make
E 10
I 10
#	cd doc; make
E 11
I 11
	cd lib; make ${MFLAGS}
	cd src; m4 Makefile.m4 > Makefile; make ${MFLAGS}
D 14
	cd aux; m4 Makefile.m4 > Makefile; make ${MFLAGS}
E 14
I 14
	-cd aux; m4 Makefile.m4 > Makefile; make ${MFLAGS}
E 14
D 21
	cd cf;  make ${MFLAGS}
E 21
#	cd doc; make ${MFLAGS}
E 24
I 24
clean: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 24
E 11
E 10
E 8
E 2

D 23
install: $(ALL) $(DIRS)
E 23
I 23
D 24
install:
E 23
D 8
	$(CP)	aux/syslog	$(DESTDIR)/etc/syslog
	$(CP)	aux/syslog.conf	$(DESTDIR)/etc/syslog.conf
	$(CP)	/dev/null	$(DESTDIR)/etc/syslog.pid
	chown	daemon		$(DESTDIR)/etc/syslog.pid
	chmod	644		$(DESTDIR)/etc/syslog.pid
D 3
	$(CP)	/dev/null	$(DESTDIR)/usr/spool/mqueue/syslog
	chown	daemon		$(DESTDIR)/usr/spool/mqueue/syslog
	chmod	644		$(DESTDIR)/usr/spool/mqueue/syslog
	$(CP)	src/sendmail	$(DESTDIR)/usr/lib/sendmail
	$(CP)	lib/sendmail.hf	$(DESTDIR)/usr/lib/sendmail.hf
	$(CP)	/dev/null	$(DESTDIR)/usr/lib/sendmail.st
	chmod	666		$(DESTDIR)/usr/lib/sendmail.st
	$(CP)	/dev/null	$(DESTDIR)/usr/lib/sendmail.fc
	$(CP)	cf/default.cf	$(DESTDIR)/usr/lib/sendmail.cf
E 3
I 3
	$(CP)	/dev/null	$(DESTDIR)$(SYSLOG)
	chown	daemon		$(DESTDIR)$(SYSLOG)
	chmod	644		$(DESTDIR)$(SYSLOG)
	for i in 0 1 2 3 4 5 6 7; do cp /dev/null $(DESTDIR)$(SYSLOG).$$i; done
	$(CP)	lib/newsyslog.sh $(DESTDIR)/usr/adm/newsyslog
E 8
I 8
D 14
	install -o 1		aux/syslog	$(DESTDIR)/etc/syslog
	install -c -o 1 -m 644	aux/syslog.conf	$(DESTDIR)/etc/syslog.conf
	install -c -o 1 -m 644	/dev/null	$(DESTDIR)/etc/syslog.pid
	install -c -o 1 -m 644	/dev/null	$(DESTDIR)$(SYSLOG)
	for i in 0 1 2 3 4 5 6 7; do install -c -o 1 -m 644 /dev/null $(DESTDIR)$(SYSLOG).$$i; done
	install -c -o 1		lib/newsyslog.sh $(DESTDIR)/usr/adm/newsyslog
E 8
D 10
	echo	'5 4 * * * sh /usr/adm/newsyslog' >> $(DESTDIR)/usr/lib/crontab
E 10
I 10
#	echo	'5 4 * * * sh /usr/adm/newsyslog' >> $(DESTDIR)/usr/lib/crontab
E 14
E 10
D 8
	$(CP)	src/sendmail	$(SENDMAIL)
	$(CP)	lib/sendmail.hf	$(SENDMAIL).hf
	$(CP)	/dev/null	$(SENDMAIL).st
	chmod	666		$(SENDMAIL).st
	$(CP)	/dev/null	$(SENDMAIL).fc
D 4
	$(CP)	cf/default.cf	$(SENDMAIL).cf
E 4
I 4
	$(CP)	cf/$(HOST).cf	$(SENDMAIL).cf
E 4
E 3
	$(LN)	$(SENDMAIL)	$(DESTDIR)/usr/ucb/newaliases
	$(LN)	$(SENDMAIL)	$(DESTDIR)/usr/ucb/mailq
E 8
I 8
D 13
	install -c -s -m 4755	src/sendmail	$(SENDMAIL)
E 13
I 13
D 17
	install -s -m 4755	src/sendmail	$(SENDMAIL)
E 17
I 17
D 22
	install -s -o root -m 4755	src/sendmail	$(SENDMAIL)
E 17
I 15
	chgrp kmem $(SENDMAIL)
E 22
I 22
	install -s -o root -g kmem -m 6755	src/sendmail	$(SENDMAIL)
E 22
E 15
E 13
D 17
	install -c -m 644	lib/sendmail.hf	$(SENDMAIL).hf
	install -c -m 666	/dev/null	$(SENDMAIL).st
	install -c -m 644	/dev/null	$(SENDMAIL).fc
	install -c -m 644	cf/$(HOST).cf	$(SENDMAIL).cf
E 17
I 17
D 23
	install -c -o root -m 644	lib/sendmail.hf	$(SENDMAIL).hf
	install -c -o root -m 666	/dev/null	$(SENDMAIL).st
	install -c -o root -m 644	/dev/null	$(SENDMAIL).fc
E 23
I 23
	install -c -o bin -g bin -m 644	lib/sendmail.hf	$(SENDMAIL).hf
	install -c -o bin -g bin -m 666	/dev/null	$(SENDMAIL).st
	install -c -o bin -g bin -m 644	/dev/null	$(SENDMAIL).fc
E 23
D 19
	install -c -o root -m 644	cf/$(HOST).cf	$(SENDMAIL).cf
E 19
E 17
	rm -f					$(DESTDIR)/usr/ucb/newaliases
D 20
	$(LN)			$(SENDMAIL)	$(DESTDIR)/usr/ucb/newaliases
E 20
I 20
	$(LN)			/usr/lib/sendmail  $(DESTDIR)/usr/ucb/newaliases
E 20
	rm -f					$(DESTDIR)/usr/ucb/mailq
D 20
	$(LN)			$(SENDMAIL)	$(DESTDIR)/usr/ucb/mailq
I 19
	install -c -o root -m 644	cf/$(HOST).cf	$(SENDMAIL).cf
E 20
I 20
	$(LN)			/usr/lib/sendmail  $(DESTDIR)/usr/ucb/mailq
#	install -c -o root -m 644	cf/$(HOST).cf	$(SENDMAIL).cf
E 20
E 19
I 14
#	install -o 1		aux/syslog	$(DESTDIR)/etc/syslog
#	install -c -o 1 -m 644	aux/syslog.conf	$(DESTDIR)/etc/syslog.conf
#	install -c -o 1 -m 644	/dev/null	$(DESTDIR)/etc/syslog.pid
#	install -c -o 1 -m 644	/dev/null	$(DESTDIR)$(SYSLOG)
#	for i in 0 1 2 3 4 5 6 7; do install -c -o 1 -m 644 /dev/null $(DESTDIR)$(SYSLOG).$$i; done
#	install -c -o 1		lib/newsyslog.sh $(DESTDIR)/usr/adm/newsyslog
#	echo	'5 4 * * * sh /usr/adm/newsyslog' >> $(DESTDIR)/usr/lib/crontab
E 24
I 24
depend: FRC
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
E 24
I 20

D 24
installcf:
D 23
	install -c -o root -m 644	cf/$(HOST).cf	$(SENDMAIL).cf
E 23
I 23
	install -c -o bin -g bin -m 644	cf/$(HOST).cf	$(SENDMAIL).cf
E 24
I 24
install: FRC
	-mkdir ${DESTDIR}/usr/spool/mqueue
	chown root.wheel ${DESTDIR}/usr/spool/mqueue
	chmod 775 ${DESTDIR}/usr/spool/mqueue
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} install); done
E 24
E 23
E 20
E 14
E 8

D 24
src/sendmail:
D 11
	cd src; make sendmail
E 11
I 11
	cd src; make ${MFLAGS} sendmail
E 11

aux/syslog:
D 11
	cd aux; make syslog
E 11
I 11
D 14
	cd aux; make ${MFLAGS} syslog
E 14
I 14
	-cd aux; make ${MFLAGS} syslog
E 14
E 11

$(DESTDIR)/usr/spool/mqueue:
	mkdir			$(DESTDIR)/usr/spool/mqueue
	chmod	777		$(DESTDIR)/usr/spool/mqueue

clean:
D 11
	cd src; make clean
I 7
	cd cf;  make clean
E 7
	cd aux; make clean
	cd lib; make clean
I 6
	cd doc; make clean
E 11
I 11
D 14
	cd src; make ${MFLAGS} clean
	cd cf;  make ${MFLAGS} clean
	cd aux; make ${MFLAGS} clean
	cd lib; make ${MFLAGS} clean
	cd doc; make ${MFLAGS} clean
E 14
I 14
	-cd src; make ${MFLAGS} clean
D 21
	-cd cf;  make ${MFLAGS} clean
E 21
	-cd aux; make ${MFLAGS} clean
	-cd lib; make ${MFLAGS} clean
	-cd doc; make ${MFLAGS} clean
I 23

depend:
E 23
E 14
E 11
E 6

dirs:
	mkdir $(SRCROOT)
	cd $(SRCROOT); mkdir $(ALLDIRS)

rcp:
D 4
	rsh $(MACH) mkdir sendmail
	rsh $(MACH) 'cd sendmail; mkdir $(ALLDIRS)'
	for i in `cat FILES`; do rcp $$i $(MACH):sendmail/$$i; done
E 4
I 4
	rsh $(BACKUP) mkdir sendmail
	rsh $(BACKUP) 'cd sendmail; mkdir $(ALLDIRS)'
	for i in `cat FILES`; do rcp $$i $(BACKUP):sendmail/$$i; done
E 4

srcinstall:
	for i in `cat FILES`; do rm -f $(SRCDIR)/$$i; cp $$i $(SRCDIR)/$$i; done
I 5

tar:
	rm -f sendmail.tar
D 9
	tar rcf sendmail.tar `cat FILES`
E 9
I 9
	tar rcfh sendmail.tar `cat FILES`
E 24
I 24
FRC:
E 24
E 9
E 5
E 1
