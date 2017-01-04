h15556
s 00007/00005/00033
d D 1.2 86/05/15 04:19:50 lepreau 2 1
c DESTDIR; ensure mode 644
e
s 00038/00000/00000
d D 1.1 84/08/17 10:51:10 ralph 1 0
c date and time created 84/08/17 10:51:10 by ralph
e
u
U
t
T
I 1
#
#	%W%	%G%
#
if ($#argv < 1) then
	echo 'Usage: install <-me file list>'
	exit
endif
I 2
if (! $?DEST) set DEST =
umask 22
E 2
echo stripping and installing $*
foreach i ($*)
	echo ${i}:
	ed $i << 'EOF'
1a
%beginstrip%
.
g/%beginstrip%/d
i
.\" This version has had comments stripped; an unstripped version is available.
.
+,$g/[. 	][ 	]*\\".*/s///
g/^$/d
g/\\n@/d
w _mac_temp_
q
'EOF'
	if ($i == tmac.e) then
D 2
		if (-d /usr/lib/tmac) then
			cp _mac_temp_ /usr/lib/tmac/tmac.e
E 2
I 2
		if (-d $DEST/usr/lib/tmac) then
			cp _mac_temp_ $DEST/usr/lib/tmac/tmac.e
E 2
		else
D 2
			cp _mac_temp_ /usr/lib/tmac.e
E 2
I 2
			cp _mac_temp_ $DEST/usr/lib/tmac.e
E 2
		endif
	else
D 2
		cp _mac_temp_ /usr/lib/me/$i
E 2
I 2
		cp _mac_temp_ $DEST/usr/lib/me/$i
E 2
	endif
	rm _mac_temp_
end
D 2
cp revisions /usr/lib/me/revisions
E 2
I 2
cp revisions $DEST/usr/lib/me/revisions
E 2
echo	"Done"
exit
E 1
