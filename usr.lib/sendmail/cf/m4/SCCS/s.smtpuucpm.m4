h30921
s 00001/00001/00041
d D 1.3 00/03/27 09:43:34 msokolov 3 2
c remove the C flag, it's totally unusable with the current cf file architecture
e
s 00000/00000/00042
d D 1.2 00/03/27 09:07:11 msokolov 2 1
c bump it up to 1.2
e
s 00042/00000/00000
d D 1.1 00/03/27 09:06:51 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 1.2
e
u
U
t
T
I 1
divert(10)
#
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
#
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
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#
#	%W% (Berkeley) %G%
#
divert(0)
############################################################
############################################################
#####
#####		SMTP UUCP Mailer specification
#####
#####	This mailer sends UUCP traffic over an SMTP connection.
#####	Obviously, we only want to do this with UUCP hosts with
#####	whom we have SMTP connectivity.  The idea here is to
#####	avoid having to double queue (once for sendmail, once
#####	for UUCP) when there's no need.  Since we need to
#####	preserve uucp-ness (e.g., bangs), we use the UUCP mailer
#####	rewriting rulesets.
#####
############################################################
############################################################

D 3
Msmtpuucp,	P=[IPC], F=mDFMueXLC, S=13, R=23, A=IPC $h, E=\r\n
E 3
I 3
Msmtpuucp,	P=[IPC], F=mDFMueXL, S=13, R=23, A=IPC $h, E=\r\n
E 3

define(SMTPUUCPPAIR,
`R<@$1.uucp>:$+		$`#'smtpuucp$@$2$:`$'2
R$*<@$1.uucp>		$`#'smtpuucp$@$2$:`$'1')
E 1
