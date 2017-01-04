h20546
s 00010/00005/00035
d D 5.3 88/07/09 11:24:34 bostic 3 2
c install approved copyright notice
e
s 00002/00000/00038
d D 5.2 88/03/27 14:28:07 bostic 2 1
c handle underlining in command name in manual pages
e
s 00038/00000/00000
d D 5.1 88/03/27 14:21:17 bostic 1 0
c date and time created 88/03/27 14:21:17 by bostic
e
u
U
t
T
I 1
#!/bin/sh -
#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 3
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
#
#	%W% (Berkeley) %G%
#
/(\([a-zA-Z0-9]*\).*UNIX Programmer's Manual/ {
	s;.*(\([a-zA-Z0-9]*\).*UNIX.*;\1;
	h
	d
}
/^NAME/!d

:name
	s;.*;;
	N
	s;\n;;
I 2
	# some twits underline the command name
	s;_;;g
E 2
	/^[^	 ]/b print
	H
	b name

:print
	x
	s;\n;;g
	/-/!d
	s;\([a-z][A-z]\)-[	 ][	 ]*;\1;
	s;\([a-zA-Z0-9,]\)[	 ][	 ]*;\1 ;g
	s;[^a-zA-Z0-9]*\([a-zA-Z0-9]*\)[^a-zA-Z0-9]*\(.*\) - \(.*\);\2 (\1) - \3;
	p
	d
E 1
