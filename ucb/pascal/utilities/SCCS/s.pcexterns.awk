h59640
s 00005/00002/00029
d D 5.1 85/06/05 16:33:39 dist 5 4
c Add copyright
e
s 00007/00001/00024
d D 4.4 83/07/25 20:39:45 mckusick 4 3
c add N_FLAGCHECKSUM field to stabs for library names
e
s 00011/00002/00014
d D 4.3 82/07/29 19:29:50 mckusick 3 2
c add comments
e
s 00002/00002/00014
d D 4.2 82/07/29 19:16:42 mckusick 2 1
c change to new stab format for library definitions
e
s 00016/00000/00000
d D 4.1 82/07/19 15:14:26 mckusick 1 0
c date and time created 82/07/19 15:14:26 by mckusick
e
u
U
t
T
I 1
D 5
# Copyright (c) 1982 Regents of the University of California
E 5
#
D 5
#	%W%	(Berkeley)	%G%
E 5
I 5
# Copyright (c) 1982 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 5
#
I 3
# This generates .stabs for all the global routines and variables
# in a library. The format of a stab can be found in man5/stab.5.
#
I 4
# This value must be coordinated with the one in ../src/pstab.h.
#
BEGIN {
	N_FLAGCHECKSUM = 1;
}
#
E 4
# Generate "source file" stab for the library name.
#
E 3
NR == 1	{
	name = substr($1, 1, index($1, ":") - 1);
D 4
	printf "	.stabs	\"%s\",0x30,0,0x1,0\n", name;
E 4
I 4
	printf "	.stabs	\"%s\",0x30,0,0x1,%d\n", name, N_FLAGCHECKSUM;
E 4
}
D 3

E 3
I 3
#
# Generate "library routine" stab.
#
E 3
NF == 3 && $2 == "T" {
D 2
	printf "	.stabs	\"%s\",0x30,0,0x7,0x%d\n", substr($3, 2), NR;
E 2
I 2
	printf "	.stabs	\"%s\",0x30,0,0xc,0x%d\n", substr($3, 2), NR;
E 2
}
D 3

E 3
I 3
#
# Generate "library variable" stab.
#
E 3
NF == 3 && $2 ~ /[ABD]/ {
D 2
	printf "	.stabs	\"%s\",0x30,0,0x6,0x%d\n", substr($3, 2), NR;
E 2
I 2
	printf "	.stabs	\"%s\",0x30,0,0xb,0x%d\n", substr($3, 2), NR;
E 2
}
E 1
