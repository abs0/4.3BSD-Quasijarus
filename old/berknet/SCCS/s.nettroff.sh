h31102
s 00059/00000/00000
d D 4.1 82/09/12 17:45:29 mckusick 1 0
c date and time created 82/09/12 17:45:29 by mckusick
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
#	nettroff 	typeset on CC or VAX typesetter
#
# 	don't change this code - it is updated remotely
# 	mail problems to "csvax:schmidt" -- your changes wil be lost
#
#	A machine phototypesetter version
#
set local=`cat /usr/include/whoami`
set typesetter=a
set troff=troff
set net=/usr/ucb/net
set whoami=/usr/ucb/whoami
onintr remove
set flags=() noglob length=() fonts=() fontf=()
top:
	if ($#argv > 0) then
		switch ($argv[1])

		case -l*:
		case -F:
		case -1:
		case -2:
		case -3:
		case -a:
		case -b:
		case -f:
		case -g:
		case -s*:
		case -w:
			echo $argv[1] not allowed.
			exit(1)

		case -*:
			set flags = ($flags $argv[1])
			shift argv
			goto top

		endsw
	endif
if ($#argv == 0) then
	set argv=(-)
endif
$troff -t $flags $fontf $* >/usr/tmp/vp$$
# check for valid format before sending off to A machine
/usr/net/bin/chktroff /usr/tmp/vp$$
if ($status != 0) then
	goto remove
endif
set person=`$whoami`
$net -q -m $typesetter -s /usr/tmp/vp$$ -c "nettroff $*" "/usr/lib/ntq -m $local -n $person"
remove:
rm -f /usr/tmp/vp$$
if ($#fontf) then
	rm -f $fontf
endif
E 1
