.\" Copyright (c) 1980,1986,1988 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	@(#)a.t	6.5 (Berkeley) 12/6/03
.\"
.de IR
\fI\\$1\fP\|\\$2
..
.ds LH "Installing/Operating \*(4B
.nr H1 6
.nr H2 0
.ds RH "Appendix A \- bootstrap details
.ds CF \*(DY
.bp
.LG
.B
.ce
APPENDIX A \- BOOTSTRAP DETAILS
.sp 2
.R
.NL
.PP
This appendix contains pertinent files and numbers regarding the
bootstrapping procedure for \*(4B.  You should never have to
look at this appendix.  However, if there are problems in installing
the distribution on your machine, the material contained here may
prove useful.
.SH
Contents of the distribution tape(s)
.PP
The distribution normally consists of two 1600bpi 2400' magnetic
tapes, one 6250bpi 2400' magnetic tape, or one TK50 tape cartridge.
The layout of the 6250bpi tape is listed below.
The TK50 tape and the 1600bpi tapes are in the same order, but the
\fItar\fP\|(1) images of source code are compressed with \fIcompress\fP\|(1).
In the 1600bpi distribution the binaries (first four tape files) are on the
first tape and the compressed sources (last two tape files) are on the second
tape.
All tape files are blocked in 10 kilobytes records, except for the
first file on the first tape that has 512 byte records.
.DS L
.TS
l l l.
Tape file	Records*	Contents
_
one	210	6 bootstrap monitor programs and a
		\fItp\fP\|(1) file containing \fIboot\fP, \fIformat\fP, and \fIcopy\fP
two	308	``mini root'' file system
three	430	\fIdump\fP\|(8) of distribution root file system
four	3000	\fItar\fP\|(1) image of binaries and libraries in /usr
five	720	\fItar\fP\|(1) image of /sys, including GENERIC system
six	2500	\fItar\fP\|(1) image of /usr/src
.TE
.FS
* The number of records in each tape file are approximate
and do not correspond to the actual tape.
.FE
.DE
.PP
The distribution tape is made with the shell scripts located
in the directory /sys/vaxdist.  To build a distribution tape
one must first create a mini root file system with the \fIbuildmini\fP
shell script.
.DS
#!/bin/sh -
#
# 4.3BSD-Quasijarus release-making script.
#
# This file is freely redistributable.
#
#	@(#)buildmini	4.10 (Berkeley) 10/3/99
#

dist=/sys/vaxdist
miniroot=ra0d
minimnt=/tmp/mini

date
mkdir ${minimnt}
newfs -s 6144 ${miniroot}
fsck /dev/r${miniroot}
mount /dev/${miniroot} ${minimnt}
cd ${minimnt}; sh ${dist}/get
cd /; sync
umount /dev/${miniroot}
fsck /dev/r${miniroot}
date
.DE
The \fIbuildmini\fP
script uses the \fIget\fP script to build the
file system.
.ID
#!/bin/sh -
#
# 4.3BSD-Quasijarus release-making script.
#
# This file is freely redistributable.
#
#	@(#)get	4.28 (Berkeley) 9/7/99
#

# Shell script to build a mini-root file system in preparation for building
# a distribution tape.  The file system created here is image copied onto
# tape, then image copied onto disk as the "first" step in a cold boot of
# 4.3 systems.

if [ `pwd` = '/' ]
then
	echo You just '(almost)' destroyed the root
	exit
fi
cp /nbsd/sys/GENERIC/vmunix vmunix

# create necessary directories
DIRLIST="bin dev etc a tmp usr usr/mdec sys sys/floppy \
	sys/cassette sys/consolerl"
rm -rf $DIRLIST
mkdir $DIRLIST

ETC="disktab disklabel diskpart fsck ifconfig init mknod mount newfs restore \
	rrestore umount arff flcopy passwd group"
for i in $ETC; do
	cp /nbsd/etc/$i etc/$i
done

BIN="[ cat cp dd echo expr ls mkdir mv rcp rm sh stty sync ed awk make mt"
for i in $BIN; do
	cp /nbsd/bin/$i bin/$i
done
ln bin/stty bin/STTY

cp /nbsd/sys/floppy/[Ma-z0-9]* sys/floppy
cp /nbsd/sys/consolerl/[Ma-z0-9]* sys/consolerl
cp /nbsd/sys/cassette/[Ma-z0-9]* sys/cassette
cp /nbsd/usr/mdec/* usr/mdec
cp /nbsd/boot boot
cp /nbsd/pcs750.bin pcs750.bin
cp /nbsd/.profile .profile

cat >etc/fstab <<EOF
/dev/hp0a:/a:xx:1:1
/dev/up0a:/a:xx:1:1
/dev/hk0a:/a:xx:1:1
/dev/ra0a:/a:xx:1:1
/dev/kra0a:/a:xx:1:1
/dev/rb0a:/a:xx:1:1
EOF

cat >xtr <<'EOF'
: ${disk?'Usage: disk=xx0 tape=yy xtr'}
: ${tape?'Usage: disk=xx0 tape=yy xtr'}
echo 'Build root file system'
newfs ${disk}a
sync
echo 'Check the file system'
fsck /dev/r${disk}a
mount /dev/${disk}a /a
cd /a
echo 'Rewind tape'
mt -f /dev/${tape}0 rew
echo 'Restore the dump image of the root'
restore rsf 3 /dev/${tape}0
cd /
sync
umount /dev/${disk}a
sync
fsck /dev/r${disk}a
echo 'Root filesystem extracted'
echo
echo 'If this is an 8650 or 8600, update the console rl02'
echo 'If this is a 780 or 785, update the floppy'
echo 'If this is a 730, update the cassette'
EOF
chmod +x xtr
rm -rf dev; mkdir dev
cp /nbsd/dev/MAKEDEV dev
chmod +x dev/MAKEDEV
cp /dev/null dev/MAKEDEV.local
cd dev
\&./MAKEDEV std hp0 hk0 up0 ra0 kra0 rb0
\&./MAKEDEV ts0; mv rmt12 ts0; rm *mt*;
\&./MAKEDEV tm0; mv rmt12 tm0; rm *mt*;
\&./MAKEDEV ht0; mv rmt12 ht0; rm *mt*;
\&./MAKEDEV ut0; mv rmt12 ut0; rm *mt*;
\&./MAKEDEV tms0; mv rmt12 tms0; rm *mt*;
\&./MAKEDEV mt0; mv rmt12 xt0; rm *mt*; mv xt0 mt0
cd ..
sync
.DE
The mini root file system must have enough space to hold the
files found on a floppy or cassette.
.PP
Once a mini root file system is constructed, the \fImaketape\fP
script makes a distribution tape.  
.ID
#!/bin/sh -
#
# 4.3BSD-Quasijarus release-making script.
#
# This file is freely redistributable.
#
#	@(#)maketape	4.36 (Berkeley) 12/6/03
#

# maketape releasedir
miniroot=ra0d
fullroot=ra1a
block=20
tflag=cbf

if [ $# -gt 0 ]; then
	releasedir=$1;
else
	echo usage: $0 releasedir
	exit
fi

cd /nbsd
sync

cd /nbsd/sys/vaxdist/tp
tp cmf /tmp/tape.$$ boot copy format
cd /nbsd/sys/mdec
echo "Build 1st level boot block file"
cat tmscpboot tsboot htboot tmboot mtboot utboot /tmp/tape.$$ | \
	dd of=${releasedir}/stand obs=512 conv=sync

echo "Add image of mini-root file system"
dd if=/dev/r${miniroot} count=308 bs=20b conv=sync of=${releasedir}/miniroot

echo "Add full dump of real file system"
/etc/dump 0f ${releasedir}/rootdump /dev/r${fullroot}

echo "Add tar image of /usr"
cd /nbsd/usr
tar ${tflag} ${block} ${releasedir}/usr.tar MAKEHOSTS adm bin dict games hosts \
	include lib local man mdec msgs new old preserve pub spool tmp ucb

echo "Add tar image of system sources"
cd /nbsd/usr/src/sys
tar ${tflag} ${block} ${releasedir}/srcsys.tar .

echo "Add user source code"
FILES="Makefile bin cci doc etc games include lib local man old \
	ucb undoc usr.bin usr.lib"
cd /nbsd/usr/src
tar ${tflag} ${block} ${releasedir}/src.tar ${FILES}
.DE
.PP
Summarizing then, to create a distribution tape you can
use the above scripts and the following commands.
.DS
\fB#\fP \fIbuildmini\fP
\fB#\fP \fImaketape /distdir\fP
.DE
This will generate the distribution tape file images in \fI/distdir\fP.
.SH
Control status register addresses
.PP
The distribution uses many standalone device drivers
that presume the location of a UNIBUS device's control status
register (CSR).
The following table summarizes these values.
.DS
.TS
l l l.
Device name	Controller	CSR address (octal)
_
ra	DEC UDA50	0172150
rb	DEC 730 IDC	0175606
rk	DEC RK11	0177440
rl	DEC RL11	0174400
tm	EMULEX TC-11	0172520
ts	DEC TS11	0172520
up	EMULEX SC-21V	0176700
ut	SI 9700	0172440
.TE
.DE
All MASSBUS controllers are located at standard offsets
from the base address of the MASSBUS adapter register bank.
BI bus controllers are located automatically.
.SH
Generic system control status register addresses
.PP
The 
.I generic
version of the operating system supplied with the distribution
contains the UNIBUS devices listed below. 
These devices will be recognized
if the appropriate control status registers respond at any of the
listed UNIBUS addresses.
.DS
.TS
l l l.
Device name	Controller	CSR addresses (octal)
_
hk	DEC RK11	0177440
tm	EMULEX TC-11	0172520
tmscp	DEC TU81, TMSCP	0174500
ts	DEC TS11	0172520
ut	SI 9700	0172440
up	EMULEX SC-21V	0176700, 0174400, 0176300
ra	DEC UDA-50	0172150, 0172550, 0177550
rb	DEC 730 IDC	0175606
rl	DEC RL11	0174400
dm	DM11 equivalent	0170500
dh	DH11 equivalent	0160020, 0160040
dhu	DEC DHU11	0160440, 0160500
dz	DEC DZ11	0160100, 0160110, ... 0160170
dmf	DEC DMF32	0160340
dmz	DEC DMZ32	0160540
lp	DEC LP11	0177514
en	Xerox 3MB ethernet	0161000
ec	3Com ethernet	0164330
ex	Excelan ethernet	0164344
il	Interlan ethernet	0164000
de	DEC DEUNA	0174510
.TE
.DE
If devices other than the above are located at any 
of the addresses listed, the system may not bootstrap
properly.
