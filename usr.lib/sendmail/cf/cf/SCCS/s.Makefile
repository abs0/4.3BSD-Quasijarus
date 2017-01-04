h52346
s 00001/00000/00080
d D 1.26 03/12/04 18:28:14 msokolov 26 25
c dummy depend target to satisfy Sendmail global Makefile
e
s 00004/00002/00076
d D 1.25 00/05/26 23:46:12 msokolov 25 24
c add Harhan cf files
c have all cf files listed in $(ALL), not just the ones we build by default
e
s 00001/00001/00077
d D 1.24 00/03/27 10:33:35 msokolov 24 23
c missing backslash
e
s 00003/00000/00075
d D 1.23 00/03/27 10:28:28 msokolov 23 22
c add install target installing baretcpproto.cf as /usr/lib/sendmail.cf
e
s 00004/00002/00071
d D 1.22 00/03/27 10:24:10 msokolov 22 21
c Don't built Berkeley cf files, just the protos
c add baretcpproto to the latter
e
s 00003/00003/00070
d D 1.21 00/03/27 09:36:22 msokolov 21 20
c INTERNET_RELAY, ARPAKLUDGE, and nicregistered.m4 go away, tcp & tcpld => smtp
e
s 00000/00000/00073
d D 1.20 00/03/27 09:17:16 msokolov 20 19
c bump it up to 1.20
e
s 00031/00031/00042
d D 1.19 00/03/27 09:17:02 msokolov 19 18
c deltas 1.19-1.20 have apparently been lost, reconstructing from g-file 1.20
e
s 00010/00000/00063
d D 1.18 87/11/04 16:55:34 phil 18 17
c Added the build information.
e
s 00004/00003/00059
d D 1.17 87/10/28 21:23:32 phil 17 16
c Added okeeffe.
e
s 00010/00010/00052
d D 1.16 87/10/28 21:06:25 phil 16 15
c Foo.
e
s 00001/00001/00061
d D 1.15 87/07/15 11:22:43 phil 15 14
c ucbtcp.cf goes in ../cf
e
s 00017/00017/00045
d D 1.14 87/07/15 11:10:12 phil 14 13
c m4 includes now in ../m4
e
s 00001/00001/00061
d D 1.13 87/07/05 21:14:19 phil 13 12
c Remove uucphosts.m4
e
s 00002/00001/00060
d D 1.12 87/07/05 20:54:42 phil 12 11
c Added cadgroup.mc
e
s 00002/00003/00059
d D 1.11 87/06/30 00:34:41 phil 11 10
c Remove oz.
e
s 00002/00001/00060
d D 1.10 87/04/29 13:51:48 phil 10 9
c Added oz configuration file.
e
s 00002/00001/00059
d D 1.9 87/04/25 23:28:52 phil 9 8
c Added dependencies for ucbvax.
e
s 00004/00003/00056
d D 1.8 87/02/16 01:00:34 phil 8 7
c Created ucbuucp.mc, with macro definitions.
e
s 00001/00001/00058
d D 1.7 87/02/15 01:01:32 phil 7 6
c Removed berkhosts and cchosts dependencies.
e
s 00010/00018/00049
d D 1.6 87/02/14 23:54:53 phil 6 5
c Add cad.
e
s 00003/00000/00064
d D 1.5 86/08/12 11:55:07 rwh 5 4
c Add cogsci (now has uucp connection)
e
s 00020/00000/00044
d D 1.4 86/03/12 10:29:56 bloom 4 3
c add dependency rules
e
s 00003/00001/00041
d D 1.3 86/01/03 12:36:01 bloom 3 2
c add kim as another host with its own configuration file
e
s 00001/00000/00041
d D 1.2 85/11/14 09:40:13 miriam 2 1
c Include shell script to modify arpa.cf's basic rule0.
e
s 00041/00000/00000
d D 1.1 85/08/13 16:57:55 miriam 1 0
c date and time created 85/08/13 16:57:55 by miriam
e
u
U
t
T
I 1
#
D 19
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
E 19
I 19
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
E 19
#
D 19
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
E 19
I 19
# Redistribution and use in source and binary forms are permitted
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
E 19
#
D 3
#	@(#)Makefile	5.2 (Berkeley) 6/25/85
E 3
I 3
#	%W% (Berkeley) %G%
E 3
#
######################################################################
#
#	Makefile for Sendmail UCB configuration files
#
######################################################################


D 6
NSSRCS=	arpa.mc \
I 3
	kim.mc \
I 5
	cogsci.mc \
E 5
E 3
	monet.mc \
	ucbvax.mc
GENSRCS=ucbtcp.mc
E 6
I 6
D 12
NSSRCS	=	arpa.mc cad.mc cogsci.mc kim.mc monet.mc ucbvax.mc
E 12
I 12
D 14
NSSRCS	=	arpa.mc cad.mc cadgroup.mc cogsci.mc kim.mc monet.mc ucbvax.mc
E 14
I 14
D 16
NSSRCS	=	arpa.mc cad.mc cadgroup.mc cogsci.mc ucbvax.mc
E 16
I 16
D 17
NSSRCS	=	cad.mc cadgroup.mc cogsci.mc ucbarpa.mc ucbvax.mc
E 17
I 17
D 19
NSSRCS	=	cad.mc cadgroup.mc cogsci.mc okeeffe.mc ucbarpa.mc ucbvax.mc
E 19
I 19
HOSTS	=	cad.cf cogsci.cf ic.cf okeeffe.cf ucbarpa.cf ucbvax.cf
E 19
E 17
E 16
E 14
E 12
E 6

D 6
NSALL=	arpa.cf \
I 3
	kim.cf \
I 5
	cogsci.cf \
E 5
E 3
	monet.cf \
	ucbvax.cf
PROTOS=	ucbtcp.cf
ALL=	$(NSALL) $(PROTOS)
E 6
I 6
D 8
GENSRCS	=	ucbtcp.mc
E 8
I 8
D 14
GENSRCS	=	ucbtcp.mc ucbuucp.mc
E 14
I 14
D 17
GENSRCS	=	ucbproto.mc ucbuucp.mc
E 17
I 17
D 19
GENSRCS	=	ucbproto.mc
E 19
I 19
GROUPS	=	cadgroup.cf cc.cf cchem.cf
E 19
E 17
E 14
E 8
E 6

D 6
GET=	sccs get
E 6
I 6
D 10
NSALL	=	arpa.cf cad.cf cogsci.cf kim.cf monet.cf ucbvax.cf
E 10
I 10
D 11
NSALL	=	arpa.cf cad.cf cogsci.cf oz.cf ucbvax.cf
E 11
I 11
D 14
NSALL	=	arpa.cf cad.cf cogsci.cf ucbvax.cf
E 14
I 14
D 16
NSALL	=	arpa.cf cad.cf cadgroup.cf cogsci.cf ucbvax.cf
E 16
I 16
D 17
NSALL	=	cad.cf cadgroup.cf cogsci.cf ucbarpa.cf ucbvax.cf
E 17
I 17
D 19
NSALL	=	cad.cf cadgroup.cf cogsci.cf okeeffe.cf ucbarpa.cf ucbvax.cf
E 19
I 19
D 22
PROTOS	=	tcpproto.cf tcpuucpproto.cf uucpproto.cf ucbtcp.cf
E 22
I 22
UCBTCP	=	ucbtcp.cf
E 22
E 19
E 17
E 16
E 14
E 11
E 10
E 6

I 25
HARHAN	=	harhantcp.cf

E 25
I 6
D 16
PROTOS	=	ucbtcp.cf
E 16
I 16
D 19
PROTOS	=	ucbtcp.cf ucbtcp_fw.cf
E 19
I 19
D 22
ALL	=	$(HOSTS) $(GROUPS) $(PROTOS)
E 22
I 22
PROTOS	=	baretcpproto.cf tcpproto.cf tcpuucpproto.cf uucpproto.cf

D 25
ALL	=	$(PROTOS)
E 25
I 25
ALL	=	$(HOSTS) $(GROUPS) $(UCBTCP) $(HARHAN) $(PROTOS)
E 25
E 22
E 19
E 16

D 19
ALL	=	$(NSALL) $(PROTOS)

E 19
GET	=	sccs get

I 18
BLDFILE	=	buildinfo

E 18
E 6
.SUFFIXES: .mc .cf

.mc.cf:
I 18
	rm -f $(BLDFILE)
	echo "# built by `whoami` on `date`" > $(BLDFILE)
	echo "# in `pwd` on `hostname`" >> $(BLDFILE)
E 18
D 14
	m4 $*.mc > $*.cf
E 14
I 14
D 16
	m4 $*.mc > ../cf/$*.cf
E 16
I 16
	m4 $*.mc > $*.cf
I 18
	rm -f $(BLDFILE)
E 18
E 16
E 14

D 25
all: $(ALL)
E 25
I 25
all: $(PROTOS)
E 25
I 4

D 14
arpa.cf: arpa.mc
	m4 $*.mc > $*.cf
E 4
I 2
	sh arpa.ed
E 14
I 14
D 19
ucbtcp.cf: ucbproto.mc
I 18
	rm -f $(BLDFILE)
	echo "# built by `whoami` on `date`" > $(BLDFILE)
	echo "# in `pwd` on `hostname`" >> $(BLDFILE)
E 18
D 15
	m4 ucbproto.mc > ucbtcp.cf
E 15
I 15
D 16
	m4 ucbproto.mc > ../cf/ucbtcp.cf
E 16
I 16
	m4 ucbproto.mc > ucbtcp.cf
I 18
	rm -f $(BLDFILE)
E 18
E 16
E 15
E 14
E 2

E 19
I 4
D 6

E 6
E 4
clean:
	rm -f $(ALL) a.out core make.out
	rm -f ,*
I 4

I 23
install:
	install -c -o bin -g bin -m 644 baretcpproto.cf ${DESTDIR}/usr/lib/sendmail.cf

E 23
#
# Standard files included by all
#
D 7
$(ALL): nsmacros.m4 nsclasses.m4 cchosts.m4 nicregistered.m4 berkhosts.m4 \
E 7
I 7
D 14
$(ALL): nsmacros.m4 nsclasses.m4 nicregistered.m4 \
E 7
	version.m4 boilerplate.m4 prewriterule.m4 postwriterule.m4 rule3.m4 \
	localm.m4 nstcpm.m4 nstcpldm.m4 rule0.m4
E 14
I 14
D 19
$(ALL): ../m4/nsmacros.m4 ../m4/nsclasses.m4 ../m4/nicregistered.m4 \
	../m4/version.m4 ../m4/boilerplate.m4 ../m4/prewriterule.m4 \
	../m4/postwriterule.m4 ../m4/rule3.m4 ../m4/localm.m4 ../m4/nstcpm.m4 \
	../m4/nstcpldm.m4 ../m4/rule0.m4
E 19
I 19
$(ALL):	../m4/boilerplate.m4 ../m4/fake_domains.m4 ../m4/localm.m4 \
D 21
	../m4/nsclasses.m4 ../m4/nsmacros.m4 ../m4/nstcpldm.m4 \
	../m4/nstcpm.m4 ../m4/postwriterule.m4 ../m4/prewriterule.m4 \
E 21
I 21
	../m4/nsclasses.m4 ../m4/nsmacros.m4 ../m4/smtpm.m4 \
	../m4/postwriterule.m4 ../m4/prewriterule.m4 \
E 21
	../m4/rule0.m4 ../m4/rule3.m4 ../m4/rule5.m4 ../m4/smtpuucpm.m4 \
D 21
	../m4/uucpm.m4 ../m4/version.m4 ../sitedep/nicregistered.m4 \
E 21
I 21
D 24
	../m4/uucpm.m4 ../m4/version.m4
E 24
I 24
	../m4/uucpm.m4 ../m4/version.m4 \
E 24
E 21
	proto.mc
E 19
E 14

#
# Special include files used only by specific hosts
#
D 14
arpa.cf: mmdfm.m4 euucpm.m4
D 6

kim.cf: uucpm.m4

E 6
I 5
D 8
cogsci.cf: uucpm.m4
I 6
cad.cf: uucpm.m4
E 8
I 8
cogsci.cf: ucbuucp.mc uucp.cogsci.m4
cad.cf: ucbuucp.mc uucp.cad.m4
I 12
cadgroup.cf: ucbtcp.cf
E 12
I 10
D 11
oz.cf: ucbuucp.mc uucp.oz.m4
E 11
E 10
E 8
E 6
E 5
D 9
ucbvax.cf: uucphosts.m4 rule5.m4 berkm.m4 suucpm.m4 uucpm.m4 
E 9
I 9
D 13
ucbvax.cf: uucphosts.m4 rule5.m4 berkm.m4 suucpm.m4 uucpm.m4  \
E 13
I 13
ucbvax.cf: rule5.m4 berkm.m4 suucpm.m4 uucpm.m4  \
E 13
D 11
	uucp.cad.m4 uucp.cogsci.m4 uucp.oz.m4 uucp.ucbarpa.m4 uucp.ucbvax.m4
E 11
I 11
	uucp.cad.m4 uucp.cogsci.m4 uucp.ucbarpa.m4 uucp.ucbvax.m4
E 11
E 9
I 8
ucbuucp.mc: uucpm.m4
E 14
I 14
D 16
../cf/arpa.cf: ../m4/mmdfm.m4 ../m4/euucpm.m4
../cf/cad.cf: ucbproto.mc ../m4/uucp.cad.m4
../cf/cadgroup.cf: ucbproto.mc
../cf/cogsci.cf: ucbproto.mc ../m4/uucp.cogsci.m4
../cf/ucbvax.cf: ../m4/rule5.m4 ../m4/berkm.m4 ../m4/suucpm.m4 ../m4/uucpm.m4  \
E 16
I 16
D 19
cad.cf: ucbproto.mc ../m4/uucp.cad.m4
cadgroup.cf: ucbproto.mc
cogsci.cf: ucbproto.mc ../m4/uucp.cogsci.m4
I 17
okeeffe.cf: ucbproto.mc ../m4/uucp.okeeffe.m4
E 17
ucbarpa.cf: ucbproto.mc ../m4/uucp.ucbarpa.m4
ucbvax.cf: ../m4/rule5.m4 ../m4/berkm.m4 ../m4/suucpm.m4 ../m4/uucpm.m4  \
E 16
	../m4/uucp.cad.m4 ../m4/uucp.cogsci.m4 ../m4/uucp.ucbarpa.m4 \
	../m4/uucp.ucbvax.m4
E 19
I 19
cad.cf: ../sitedep/uucp.cad.m4
cogsci.cf: ../sitedep/uucp.cogsci.m4
okeeffe.cf: ../sitedep/uucp.okeeffe.m4
ucbarpa.cf: ../sitedep/uucp.ucbarpa.m4
ucbvax.cf: ../m4/suucpm.m4 ../sitedep/uucp.cad.m4 \
	../sitedep/uucp.cogsci.m4 ../sitedep/uucp.ucbarpa.m4 \
	../sitedep/uucp.ucbvax.m4

I 26
depend:
E 26
E 19
E 14
E 8
E 4
E 1
