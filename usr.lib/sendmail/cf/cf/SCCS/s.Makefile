h54515
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
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
#
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
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
NSSRCS	=	cad.mc cadgroup.mc cogsci.mc okeeffe.mc ucbarpa.mc ucbvax.mc
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
GENSRCS	=	ucbproto.mc
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
NSALL	=	cad.cf cadgroup.cf cogsci.cf okeeffe.cf ucbarpa.cf ucbvax.cf
E 17
E 16
E 14
E 11
E 10
E 6

I 6
D 16
PROTOS	=	ucbtcp.cf
E 16
I 16
PROTOS	=	ucbtcp.cf ucbtcp_fw.cf
E 16

ALL	=	$(NSALL) $(PROTOS)

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

all: $(ALL)
I 4

D 14
arpa.cf: arpa.mc
	m4 $*.mc > $*.cf
E 4
I 2
	sh arpa.ed
E 14
I 14
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

I 4
D 6

E 6
E 4
clean:
	rm -f $(ALL) a.out core make.out
	rm -f ,*
I 4

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
$(ALL): ../m4/nsmacros.m4 ../m4/nsclasses.m4 ../m4/nicregistered.m4 \
	../m4/version.m4 ../m4/boilerplate.m4 ../m4/prewriterule.m4 \
	../m4/postwriterule.m4 ../m4/rule3.m4 ../m4/localm.m4 ../m4/nstcpm.m4 \
	../m4/nstcpldm.m4 ../m4/rule0.m4
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
E 14
E 8
E 4
E 1
