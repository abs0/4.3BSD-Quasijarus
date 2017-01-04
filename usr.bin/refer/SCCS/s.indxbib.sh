h32659
s 00016/00000/00000
d D 4.1 83/05/08 15:08:38 mckusick 1 0
c date and time created 83/05/08 15:08:38 by mckusick
e
u
U
t
T
I 1
#! /bin/sh
#
#	%W%	(Berkeley)	%E%
#
#	indxbib sh script
#
if test $1
	then /usr/lib/refer/mkey $* | /usr/lib/refer/inv _$1
	mv _$1.ia $1.ia
	mv _$1.ib $1.ib
	mv _$1.ic $1.ic
else
	echo 'Usage:  indxbib database [ ... ]
	first argument is the basename for indexes
	indexes will be called database.{ia,ib,ic}'
fi
E 1
