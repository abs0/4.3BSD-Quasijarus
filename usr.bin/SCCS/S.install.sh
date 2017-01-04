h20244
s 00009/00000/00079
d D 4.9 87/07/06 18:32:08 bostic 10 9
c fail if chmod, chown, chgrp fail
e
s 00023/00006/00056
d D 4.8 86/03/06 17:34:12 mckusick 9 8
c when mv'ing and strip'ing file (-s and not -c), strip before mv to
c avoid fragmentation on the destination file system.
e
s 00002/00002/00060
d D 4.7 85/09/07 19:17:01 serge 8 7
c allow install /a/b /c/dir
e
s 00001/00001/00061
d D 4.6 85/08/31 18:09:39 sam 7 6
c use -f flag to chmod
e
s 00004/00000/00058
d D 4.5 83/10/12 12:40:35 karels 6 5
c don't remove target if source doesn't exist
e
s 00002/00002/00056
d D 4.4 83/04/28 11:18:53 ralph 5 4
c changed it to use chgrp -f.
e
s 00006/00000/00052
d D 4.3 83/04/22 14:50:58 ralph 4 2
c added a -g option to specify the group like the -o for owner.
e
s 00006/00000/00052
d R 4.3 83/04/22 14:14:59 ralph 3 2
c added -g flag to change group like the -o flag for owner.
e
s 00008/00005/00044
d D 4.2 83/03/08 17:51:50 mckusick 2 1
c changes to use -f option to install; check for install to self
e
s 00049/00000/00000
d D 4.1 82/10/20 22:46:31 mckusick 1 0
c date and time created 82/10/20 22:46:31 by mckusick
e
u
U
t
T
I 1
#! /bin/sh
#
#	%W%	(Berkeley)	%G%
#
D 9
cmd=/bin/mv
strip=""
E 9
I 9
cmd=""
stripbefore=""
stripafter=""
E 9
D 7
chmod="/bin/chmod 755"
E 7
I 7
chmod="/bin/chmod -f 755"
E 7
D 2
chown="/etc/chown root"
E 2
I 2
chown="/etc/chown -f root"
I 4
D 5
chgrp="/bin/chgrp staff"
E 5
I 5
chgrp="/bin/chgrp -f staff"
E 5
E 4
E 2
while true ; do
	case $1 in
D 9
		-s )	strip="/bin/strip"
E 9
I 9
		-s )	if [ $cmd ]
			then	stripafter="/bin/strip"
			else	stripbefore="/bin/strip"
			fi
E 9
			shift
			;;
D 9
		-c )	cmd="/bin/cp"
E 9
I 9
		-c )	if [ $cmd ]
			then	echo "install: multiple specifications of -c"
				exit 1
			fi
			cmd="/bin/cp"
			stripafter=$stripbefore
			stripbefore=""
E 9
			shift
			;;
D 8
		-m )	chmod="/bin/chmod $2"
E 8
I 8
		-m )	chmod="/bin/chmod -f $2"
E 8
			shift
			shift
			;;
D 2
		-o )	chown="/etc/chown $2"
E 2
I 2
		-o )	chown="/etc/chown -f $2"
E 2
			shift
			shift
			;;
I 4
D 5
		-g )	chgrp="/bin/chgrp $2"
E 5
I 5
		-g )	chgrp="/bin/chgrp -f $2"
E 5
			shift
			shift
			;;
E 4
		* )	break
			;;
	esac
done
I 9
if [ $cmd ]
then true
else cmd="/bin/mv"
fi
E 9

if [ ! ${2-""} ]
D 2
then	echo "install: no destination specified."
E 2
I 2
then	echo "install: no destination specified"
E 2
	exit 1
fi
if [ ${3-""} ]
D 2
then	echo "install: too many files specified-> $*"
E 2
I 2
then	echo "install: too many files specified -> $*"
E 2
	exit 1
fi
D 2

E 2
I 2
if [ $1 = $2 -o $2 = . ]
then	echo "install: can't move $1 onto itself"
	exit 1
fi
I 6
if [ '!' -f $1 ]
then	echo "install: can't open $1"
	exit 1
fi
E 6
E 2
if [ -d $2 ]
D 8
then	file=$2/$1
E 8
I 8
then	file=$2/`basename $1`
E 8
else	file=$2
fi
/bin/rm -f $file
I 9
if [ $stripbefore ]
then	$stripbefore $1
fi
E 9
$cmd $1 $file
D 9
if [ $strip ]
then	$strip $file
E 9
I 9
if [ $stripafter ]
then	$stripafter $file
E 9
fi
$chown $file
I 10
if [ $? -ne 0 ] ; then
	exit 1
fi
E 10
I 4
$chgrp $file
I 10
if [ $? -ne 0 ] ; then
	exit 1
fi
E 10
E 4
$chmod $file
I 10
if [ $? -ne 0 ] ; then
	exit 1
fi
E 10
E 1
