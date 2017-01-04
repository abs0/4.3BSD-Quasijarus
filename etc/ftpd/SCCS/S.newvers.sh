h33020
s 00011/00006/00014
d D 5.3 88/10/31 11:46:05 bostic 4 3
c correct Berkeley copyright
e
s 00008/00002/00012
d D 5.2 88/03/14 17:27:55 bostic 3 2
c add Berkeley specific header
e
s 00008/00000/00006
d D 5.1 85/06/06 11:09:59 dist 2 1
c Add copyright
e
s 00006/00000/00000
d D 4.1 83/01/15 16:53:23 sam 1 0
c date and time created 83/01/15 16:53:23 by sam
e
u
U
t
T
I 2
#!/bin/sh -
#
D 4
# Copyright (c) 1983 Regents of the University of California.
E 4
I 4
# Copyright (c) 1983 The Regents of the University of California.
E 4
D 3
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 3
I 3
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 4
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
#
#	%W% (Berkeley) %G%
#
E 2
I 1
if [ ! -r version ]; then echo 0 > version; fi
touch version
awk '	{	version = $1 + 1; }\
END	{	printf "char version[] = \"Version 4.%d ", version > "vers.c";\
		printf "%d\n", version > "version"; }' < version
echo `date`'";' >> vers.c
E 1
