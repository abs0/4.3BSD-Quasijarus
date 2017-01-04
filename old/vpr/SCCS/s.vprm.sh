h01114
s 00021/00009/00003
d D 4.1 83/03/08 09:46:15 ralph 3 2
c new remote lpr replaces vpr, etc. This is for backwards compatibility.
e
s 00001/00000/00011
d D 1.2 82/11/29 14:34:38 aigrain 2 1
c add #!/bin/csh line
e
s 00011/00000/00000
d D 1.1 82/08/09 00:38:17 mckusick 1 0
c date and time created 82/08/09 00:38:17 by mckusick
e
u
U
t
T
I 2
D 3
#!/bin/csh -f
E 3
I 3
#! /bin/csh -f
E 3
E 2
I 1
#
#	%W%	(Berkeley)	%G%
#
D 3
set remote = ucbernie
set execdir = /usr/ucb
if ($remote != `hostname`) then
	set cmd = "/usr/ucb/rsh $remote -n"
else
	set cmd = ""
endif
$cmd $execdir/vprm $argv
E 3
I 3
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
/usr/ucb/lprm $printer $flags $*
E 3
E 1
