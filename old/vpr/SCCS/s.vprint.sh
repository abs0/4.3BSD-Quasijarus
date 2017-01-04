h18928
s 00021/00014/00003
d D 4.1 83/03/08 09:46:12 ralph 4 3
c new remote lpr replaces vpr, etc. This is for backwards compatibility.
e
s 00001/00000/00016
d D 1.3 82/11/29 14:34:45 aigrain 3 2
c add #!/bin/csh line
e
s 00011/00003/00005
d D 1.2 82/08/09 00:37:41 mckusick 2 1
c update to optimize for local host
e
s 00008/00000/00000
d D 1.1 80/11/30 15:56:47 root 1 0
c date and time created 80/11/30 15:56:47 by root
e
u
U
t
T
I 3
D 4
#!/bin/csh -f
E 4
I 4
#! /bin/csh -f
E 4
E 3
I 1
#
I 2
#	%W%	(Berkeley)	%G%
#
D 4
set remote = ucbernie
set execdir = /usr/ucb
if ($remote != `hostname`) then
	set cmd = "/usr/ucb/rsh $remote"
else
	set cmd = ""
endif
E 2
if ($1 == "-W") then
	shift
D 2
	pr -l86 $*:q | vpr -W
E 2
I 2
	pr -l86 $*:q | $cmd $execdir/vpr -W
E 2
else
D 2
	# pr -l84 $*:q | vpr
	pr -f $*:q | vpr -l
E 2
I 2
	pr -f $*:q | $cmd $execdir/vpr -l
E 2
endif
E 4
I 4
set flags = ()
set printer = -Pvarian
top:
	if ($#argv > 0) then
		switch ($argv[1])
		case -V:
			set printer = -Pvarian
			shift argv
			goto top
		case -W:
			set printer = -Pversatec
			shift argv
			goto top
		case -*:
			set flags = ($flags $argv[1])
			shift argv
			goto top
		endsw
	endif
/usr/ucb/lpr $printer -p $flags $*
E 4
E 1
