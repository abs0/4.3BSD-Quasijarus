h52673
s 00005/00002/00010
d D 5.1 85/06/05 16:01:53 dist 3 2
c Add copyright
e
s 00000/00000/00012
d D 2.2 84/02/08 20:50:31 aoki 2 1
c synchronize to version 2
e
s 00012/00000/00000
d D 2.1 83/02/06 15:54:49 mckusick 1 0
c date and time created 83/02/06 15:54:49 by mckusick
e
u
U
t
T
I 1
D 3
# Copyright (c) 1983 Regents of the University of California
E 3
#
D 3
#	%W%	(Berkeley)	%E%
E 3
I 3
# Copyright (c) 1983 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 3
#
/^VERSION = /	{
		    n = split( $3, version, ".")
		    print "VERSION = " version[1] "." version[2]+1
		    break
		}
		{
		    print $0
		}
E 1
