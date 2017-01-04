h33470
s 00026/00011/00019
d D 4.7 88/03/27 11:24:30 bostic 9 7
c require '-' to run everybody's calendar; exit with correct status
c remove absolute path names
e
s 00007/00002/00028
d R 4.7 88/03/23 14:16:54 bostic 8 7
c require '-' to run everybody's calendar; exit with correct status
e
s 00001/00001/00029
d D 4.6 87/10/14 12:54:33 bostic 7 6
c add ucb to path to find new egrep
e
s 00007/00005/00023
d D 4.5 84/02/14 20:54:43 rrh 6 5
c add subject line saying what day it is
e
s 00002/00002/00026
d D 4.4 82/11/07 14:48:28 rrh 5 3
c Run the calendar files through /lib/cpp. This allows a global data base
c of dates to be included in users' calendar files.
e
s 00001/00001/00027
d R 4.4 82/11/07 14:42:15 rrh 4 3
c Run the calendar files through /lib/cpp. This allows a global data base
c of dates to be included in users' calendar files.
e
s 00002/00002/00026
d D 4.3 82/02/13 22:21:37 root 3 2
c added -f to all rm's
e
s 00012/00004/00016
d D 4.2 81/02/28 20:49:32 wnj 2 1
c fixes from various sources for clean termination
e
s 00020/00000/00000
d D 4.1 81/02/28 20:46:15 wnj 1 0
c date and time created 81/02/28 20:46:15 by wnj
e
u
U
t
T
I 1
D 9
: %M% %I% %E%
D 2
PATH=/bin:/usr/bin
E 2
I 2
D 7
PATH=/bin:/usr/bin:
E 7
I 7
PATH=/bin:/usr/bin:/usr/ucb
E 9
I 9
#!/bin/sh -
#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
PATH=/usr/lib:/bin:/usr/bin:/usr/ucb:/lib	# order important

E 9
E 7
E 2
D 6
tmp=/tmp/cal$$
D 2
trap "rm $tmp; exit" 0 1 2 13 15
E 2
I 2
trap "rm -f $tmp /tmp/cal2$$"
E 6
I 6
tmp=/tmp/cal0$$
trap "rm -f $tmp /tmp/cal1$$ /tmp/cal2$$"
E 6
trap exit 1 2 13 15
E 2
D 9
/usr/lib/calendar >$tmp
case $# in
0)
E 9
I 9
calendar >$tmp

if [ $# = 0 ]; then
E 9
I 2
D 3
	trap "rm $tmp ; exit" 0 1 2 13 15
E 3
I 3
	trap "rm -f $tmp ; exit" 0 1 2 13 15
E 3
E 2
D 5
	egrep -f $tmp calendar;;
E 5
I 5
D 9
	(/lib/cpp calendar | egrep -f $tmp);;
E 5
*)
E 9
I 9
	(cpp calendar | egrep -f $tmp)
	exit 0
fi

if [ $# = 1 ] && [ $1 = "-" ]; then
E 9
I 2
D 3
	trap "rm $tmp /tmp/cal2$$; exit" 0 1 2 13 15
E 3
I 3
D 6
	trap "rm -f $tmp /tmp/cal2$$; exit" 0 1 2 13 15
E 6
I 6
	trap "rm -f $tmp /tmp/cal1$$ /tmp/cal2$$; exit" 0 1 2 13 15
D 9
	/bin/echo -n "Subject: Calendar for " > /tmp/cal1$$
E 9
I 9
	echo -n "Subject: Calendar for " > /tmp/cal1$$
E 9
	date | sed -e "s/ [0-9]*:.*//" >> /tmp/cal1$$
E 6
E 3
E 2
	sed '
		s/\([^:]*\):.*:\(.*\):[^:]*$/y=\2 z=\1/
	' /etc/passwd \
	| while read x
	do
		eval $x
D 2
		if test -r $y/calendar; then
			egrep -f $tmp $y/calendar 2>/dev/null  | mail $z
E 2
I 2
		if test -r $y/calendar
		then
D 5
			egrep -f $tmp $y/calendar 2>/dev/null  > /tmp/cal2$$
E 5
I 5
D 6
			(/lib/cpp $y/calendar | egrep -f $tmp) 2>/dev/null  > /tmp/cal2$$
E 6
I 6
D 9
			(/lib/cpp $y/calendar | egrep -f $tmp) 2>/dev/null > /tmp/cal2$$
E 9
I 9
			(cpp $y/calendar | egrep -f $tmp) 2>/dev/null > /tmp/cal2$$
E 9
E 6
E 5
			if test -s /tmp/cal2$$
			then
D 6
				< /tmp/cal2$$ mail $z
E 6
I 6
D 9
				cat /tmp/cal1$$ /tmp/cal2$$ | /bin/mail $z
E 9
I 9
				cat /tmp/cal1$$ /tmp/cal2$$ | mail $z
E 9
E 6
			fi
E 2
		fi
	done
D 9
esac
E 9
I 9
	exit 0
fi

echo "usage: calendar [-]"
exit 1
E 9
E 1
