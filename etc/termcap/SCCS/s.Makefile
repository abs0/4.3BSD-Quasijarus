h45343
s 00001/00001/00031
d D 5.6 99/10/02 21:36:49 msokolov 19 18
c group bin, not staff
e
s 00004/00001/00028
d D 5.5 88/01/21 15:10:35 bostic 18 15
c add map3270, change cp to install, set owner/groups/modes correctly
e
s 00004/00001/00028
d R 5.5 87/12/06 15:15:59 bostic 17 15
c add map3270, change cp to install, set owner/groups/modes correctly
e
s 00004/00001/00028
d R 5.5 87/11/20 12:35:07 bostic 16 15
c add map3270, change cp to install, set owner/groups/modes correctly
e
s 00010/00025/00019
d D 5.4 87/06/02 21:26:35 bostic 15 14
c new template
e
s 00002/00000/00042
d D 5.3 87/05/31 20:42:02 bostic 14 13
c added depend label
e
s 00003/00001/00039
d D 5.2 86/03/03 16:10:49 mckusick 13 12
c properly install the tabset file (from Chris Torek <chris@gyre.umd.edu>)
e
s 00006/00001/00034
d D 5.1 85/05/28 15:45:23 dist 12 11
c Add copyright
e
s 00001/00001/00034
d D 1.11 84/08/22 10:10:49 ralph 11 10
c install termcap read-only
e
s 00001/00002/00034
d D 1.10 83/07/01 11:03:46 layer 10 9
c changed install
e
s 00014/00007/00022
d D 1.9 83/05/11 20:37:56 layer 9 8
c added 'tabsetall that installs /usr/lib/tabset's on all machines
e
s 00003/00002/00026
d D 1.8 83/05/05 20:54:58 layer 8 7
c 
e
s 00013/00005/00015
d D 1.7 83/04/25 15:07:13 layer 7 6
c eliminated lots of dups and...
c entries that were just for names compatibility (i.e.,
c 2621-nl instead of 2621nl).
e
s 00002/00001/00018
d D 1.6 83/02/12 12:00:44 leres 6 5
c Made /etc/termcap owned by root, in group termcap, and with mode 664
e
s 00005/00010/00014
d D 1.5 83/02/11 07:15:50 layer 5 4
c fixed install
e
s 00003/00003/00021
d D 1.4 83/02/10 02:08:09 layer 4 3
c DESTDIR was wrong...
e
s 00001/00001/00023
d D 1.3 83/01/24 23:41:12 layer 3 2
c use ex instead of ed
e
s 00010/00004/00014
d D 1.2 83/01/23 15:05:10 layer 2 1
c 
e
s 00018/00000/00000
d D 1.1 83/01/23 15:02:10 layer 1 0
c date and time created 83/01/23 15:02:10 by layer
e
u
U
t
T
I 2
D 7
# %W%	%G%
E 7
I 7
D 12
# %W%	(Berkeley) %G%
E 12
I 12
#
D 15
# Copyright (c) 1980 Regents of the University of California.
E 15
I 15
# Copyright (c) 1987 Regents of the University of California.
E 15
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 15
#	%W% (Berkeley) %G%
E 15
I 15
#	%W%	(Berkeley)	%G%
E 15
E 12
E 7
E 2
I 1
#
# reorder gives an editor command for most common terminals
# (in reverse order from n'th to 1'st most commonly used)
# to move them to the front of termcap
#
D 2
termcap.obj: termcap.src
E 2
I 2
D 4
DESTDIR = /etc
E 4
I 4
D 15
DESTDIR =
E 15
I 15
all: termcap
E 15
I 5

E 5
E 4
D 7
termcap.obj: reorder termcap.src
E 7
I 7
termcap: reorder termcap.src
E 7
E 2
D 3
	ed - termcap.src < reorder
E 3
I 3
	ex - termcap.src < reorder
E 3
I 2

E 2
D 7
install: termcap.obj
D 2
	cp termcap.obj ${DESTDIR}/etc/termcap
E 2
I 2
D 4
	cp termcap.obj ${DESTDIR}/termcap
E 4
I 4
D 5
	install termcap.obj ${DESTDIR}/etc/termcap
E 5
I 5
D 6
	install -c termcap.obj ${DESTDIR}/etc/termcap
E 6
I 6
	install -o root -m 664 -c termcap.obj ${DESTDIR}/etc/termcap
E 7
I 7
D 9
install: termcap
E 9
I 9
D 15
install: termcap tabset
E 9
D 10
	install -o root -m 664 -c termcap ${DESTDIR}/etc/termcap
E 7
	chgrp termcap ${DESTDIR}/etc/termcap
E 10
I 10
D 11
	install -m 664 termcap ${DESTDIR}/etc/termcap
E 11
I 11
	install -m 444 termcap ${DESTDIR}/etc/termcap
E 15
I 15
clean: FRC
	rm -f termcap
E 15
E 11
E 10
I 9

D 13
tabset:
E 13
I 13
D 15
tabset: FRC
E 13
E 9
E 6
	rm -fr ${DESTDIR}/usr/lib/tabset
E 15
I 15
install: FRC
I 18
	install -c -o bin -g bin -m 444 map3270 ${DESTDIR}/etc/map3270
E 18
D 19
	install -o bin -g staff -m 444 termcap ${DESTDIR}/etc/termcap
E 19
I 19
	install -o bin -g bin -m 444 termcap ${DESTDIR}/etc/termcap
E 19
	rm -rf ${DESTDIR}/usr/lib/tabset
E 15
	mkdir ${DESTDIR}/usr/lib/tabset
D 18
	cp tabset/* ${DESTDIR}/usr/lib/tabset
E 18
I 18
	chown bin.bin ${DESTDIR}/usr/lib/tabset
	chmod 755 ${DESTDIR}/usr/lib/tabset
	install -c -o bin -g bin -m 444 tabset/* ${DESTDIR}/usr/lib/tabset
E 18
E 5
E 4

E 2
D 15
clean:
D 7
	rm -f termcap.obj
E 7
I 7
	rm -f termcap
I 13

E 15
I 14
depend:
D 15

E 15
I 15
lint:
tags:
E 15
E 14
FRC:
E 13
D 15

installall:
	cp termcap /etc/termcap
I 8
D 9
	rcp termcap arpa:/etc/termcap
E 8
	rcp termcap ernie:/etc/termcap
	rcp termcap kim:/etc/termcap
D 8
	rcp termcap calder:/etc/termcap
	rcp termcap arpa:/etc/termcap
E 8
	rcp termcap dali:/etc/termcap
I 8
	rcp termcap calder:/etc/termcap
	rcp termcap ucbvax:/etc/termcap
E 9
I 9
	@for i in arpa ernie kim dali calder ucbvax miro;\
		do echo $$i;\
		rcp termcap $$i':'/etc/termcap;\
		done

tabsetall: tabset
	@for i in arpa ernie kim dali calder ucbvax miro;\
		do echo $$i;\
		rsh $$i /bin/rm -fr /usr/lib/tabset;\
		rcp -r tabset $$i':'/usr/lib;\
		done
E 15
E 9
E 8
E 7
I 2
D 5

E 2
D 4
tabset:	/tmp
E 4
I 4
tabset:
E 4
D 2
	mkdir /usr/lib/tabset
E 2
I 2
	-mkdir /usr/lib/tabset
E 2
	cp tabset/* /usr/lib/tabset
I 2

E 2
VGRIND=	csh /usr/ucb/vgrind
vgrind:
	${VGRIND} -n -h "Terminal Capibility Data Base" \
D 2
	termcap.src reorder makefile
E 2
I 2
		    termcap.src reorder Makefile
E 5
E 2
E 1
