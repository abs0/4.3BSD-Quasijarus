h56678
s 00026/00000/00000
d D 1.1 85/08/08 15:31:17 miriam 1 0
c date and time created 85/08/08 15:31:17 by miriam
e
u
U
t
T
I 1
divert(10)
#
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
#
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
divert(0)
############################################################
############################################################
#####
#####		Local and Program Mailer specification
#####
############################################################
############################################################

Mlocal,	P=/bin/mail, F=rlsDFMmn, S=10, R=20, A=mail -d $u
Mprog,	P=/bin/sh,   F=lsDFMe,   S=10, R=20, A=sh -c $u

S10
R@			$n			errors to mailer-daemon
E 1
