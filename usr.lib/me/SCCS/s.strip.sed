h02928
s 00017/00000/00000
d D 5.1 88/04/22 12:15:53 bostic 1 0
c date and time created 88/04/22 12:15:53 by bostic
e
u
U
t
T
I 1
#! /bin/sed -f
#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
#
#	%W% (Berkeley) %G%
#
/%beginstrip%/{
	h
	s/.*/.\\" This version has had comments stripped; an unstripped version is available./p
	g
}
/%beginstrip%/,$s/[. 	][ 	]*\\".*//
/^$/d
/\\n@/d
E 1
