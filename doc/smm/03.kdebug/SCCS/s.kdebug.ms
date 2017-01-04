h53638
s 00037/00018/00778
d D 6.4 86/06/03 21:23:05 mckusick 5 4
c reorganization for ease of typesetting
e
s 00111/00009/00685
d D 6.3 86/06/03 20:01:24 karels 4 3
c add stack backtrace stuff
e
s 00319/00273/00375
d D 6.2 86/06/03 16:46:35 sam 3 2
c update and minor cleanups; someone should justify the u. script output
e
s 00008/00010/00640
d D 6.1 86/05/25 17:59:08 mckusick 2 1
c 4.3BSD beta release document
e
s 00650/00000/00000
d D 5.1 86/05/25 17:59:00 mckusick 1 0
c document distributed with 4.2BSD
e
u
U
t
T
I 1
.\" Copyright (c) 1983 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.bd S B 3
.de UX
.ie \\n(GA>0 \\$2UNIX\\$1
.el \{\
.if n \\$2UNIX\\$1*
.if t \\$2UNIX\\$1\\f1\(dg\\fP
.FS
.if n *UNIX
.if t \(dgUNIX
.ie \\$3=1 is a Footnote of Bell Laboratories.
.el is a Trademark of Bell Laboratories.
.FE
.nr GA 1\}
..
I 5
.de cw
.ft CW
..
.de pw
.ft P
..
E 5
.TL
Using ADB to Debug the
.UX
Kernel
D 2
.br
Revised January, 1983
E 2
.AU
D 2
Samuel J. Leffler
.AU
William N. Joy
E 2
I 2
Samuel J. Leffler and William N. Joy
E 2
.AI
Computer Systems Research Group
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, California  94720
D 2
(415) 642-7780
E 2
.de IR
\fI\\$1\fP\\$2
..
.de DT
.TA 8 16 24 32 40 48 56 64 72 80
..
.AB
.PP
.FS
*DEC and VAX are trademarks of
Digital Equipment Corporation.
.FE
D 3
This document describes the use of extensions made
to the 4.1bsd release of the VAX*
E 3
I 3
This document describes the facilities found in
the 4.3BSD version of the VAX*
E 3
.UX
debugger
.I adb
D 3
for the purpose of debugging the
E 3
I 3
which may be used to debug the
E 3
.UX
kernel.
D 3
It discusses the changes made to allow
standard
E 3
I 3
It discusses how standard
E 3
.I adb
D 3
commands to
function properly with the kernel and
E 3
I 3
commands may be used in examining the kernel and
E 3
introduces the basics necessary for users
to write
.I adb
D 3
command scripts which
may be used to augment the standard
E 3
I 3
command scripts which can augment the standard
E 3
.I adb
command set.  The examination techniques described here
D 3
may be applied to running systems, as well as 
E 3
I 3
may be applied both to running systems and
E 3
the post-mortem dumps automatically created
by the 
.IR savecore (8)
program after a system crash.
The reader is expected to have at least a
passing familiarity with the debugger command
language.
I 2
.sp
.LP
Revised %Q%
E 2
.AE
D 2
.ND
E 2
I 2
.LP
.OH 'Using ADB to Debug the Kernel''SMM:3-%'
.EH 'SMM:3-%''Using ADB to Debug the Kernel'
E 2
D 5
.ds LH "Using ADB on the UNIX Kernel
E 5
.ds RH Introduction
D 5
.ds CF \*(DY
E 5
.LP
D 3
.nr H1 1
E 3
D 5
.ds CH "
E 5
D 3
.bp
D 2
.nr % 1
.ds CH "\(hy \\n(PN \(hy
E 2
.LG
.B
.ce
1. INTRODUCTION
.sp 2
.R
.NL
E 3
I 3
.ne 2i
.NH
Introduction
E 3
.PP
Modifications have been made to the
standard VAX
.UX
debugger
.I adb
to simplify
examination of post-mortem
dumps automatically generated following a system crash.
These changes may also be used when examining
.UX
in its normal operation.
This document serves as
an introduction to the
.B use
of these facilities, and
should not be construed as a description
of \fIhow to debug the kernel\fP.
.NH 2
Invocation
.PP
D 4
When examining the
E 4
I 4
When examining post-mortem dumps of the
E 4
.UX
D 3
kernel a new option,
\fB\-k\fP, should be used, e.g.
.sp 1
.ti +5
adb \-k /vmunix /dev/mem
.sp 1
E 3
I 3
kernel the
\fB\-k\fP option should be used, e.g.
.DS
D 4
\f(CW% adb \-k /vmunix /dev/mem\fP
E 4
I 4
D 5
\f(CW% adb \-k vmunix.? vmcore.?\fP
E 5
I 5
.cw
% adb \-k vmunix.? vmcore.?
.pw
E 5
E 4
.DE
I 4
where the appropriate version of the saved operating system
image and core dump are supplied in place of ``?''.
E 4
E 3
This flag causes
.I adb
to partially simulate
the VAX virtual memory hardware when
accessing the
.I core
file.
In addition the internal state maintained
by the debugger is initialized from
data structures maintained by the
D 4
.UX
E 4
kernel explicitly for debugging\(dd.
D 4
A post-mortem dump may be examined in a similar
E 4
I 4
A running kernel may be examined in a similar
E 4
fashion,
D 3
.sp 1
.ti +5
adb \-k vmunix.? vmcore.?
.sp 1
E 3
I 3
.DS
D 4
\f(CW% adb \-k vmunix.? vmcore.?\fP
E 4
I 4
D 5
\f(CW% adb \-k /vmunix /dev/mem\fP
E 5
I 5
.cw
% adb \-k /vmunix /dev/mem
.pw
E 5
E 4
.DE
E 3
D 4
where the appropriate version of the saved operating system
image and core dump are supplied in place of ``?''.
E 4
.FS
\(dd If the \-k flag is not used when invoking
.I adb
the user must explicitly calculate virtual
addresses.  With the
.B \-k
option
.I adb
interprets page tables to automatically
perform virtual to physical address translation.
.FE
.NH 2
Establishing Context
.PP
During initialization
.I adb
attempts to establish the
context of the ``currently active process'' by examining
the value of the kernel variable \fImasterpaddr\fP.
This variable contains the virtual address of the 
process context block of the last process which
was set executing by the \fISwtch\fP routine.
\fIMasterpaddr\fP normally provides sufficient information
to locate the current stack frame (via the stack
pointers found in the context block).
D 3
By locating the VAX process context block for the
process,
E 3
I 3
By locating the process context block for the process
E 3
.I adb
may then perform virtual to
physical address translation using that process's
in-core page tables.
.PP
When examining post-mortem dumps locating the
D 3
most recent stack frame of the
``currently active process'' is nontrivial.
This is due to the different ways in which the
VAX may save state after a nonrecoverable error. 
E 3
I 3
most recent stack frame of the last
currently active process can be nontrivial.
This is due to the different ways in which
state may be saved after a nonrecoverable error. 
E 3
Crashes may or may not be ``clean'' (i.e.
D 3
the top of the interrupt stack contains the process's
E 3
I 3
the top of the interrupt stack contains a pointer
to the process's
E 3
kernel mode stack pointer and program counter);
an ``unclean'' crash will occur, for instance,
D 3
if the interrupt stack overflows.
Thus, one must manually try one of two possible techniques
to get a stack trace from a post-mortem dump.  If the
crash was clean the current stack pointer is present in the
restart parameter block, at \fIscb\-4\fP (or \fIrpb\fP+1fc),
and the command
.sp 1
.ti +5
*(\fBscb\fP\-4)$c
.sp 1
will generate a stack trace all the way from the kernel
E 3
I 3
if the interrupt stack overflows.  When
.I adb
is invoked on a post-mortem crash dump it tries
to automatically establish the proper stack frame.
This is done by first checking the stack pointer
normally saved in the restart parameter
D 4
block at \fIscb\-4\fP (or \fIrpb\fP+1fc).  If this
E 4
I 4
block at \fIrpb\fP+1fc (or \fIscb\fP\-4).  If this
E 4
value does not point to a valid stack frame,
.I adb
searches the interrupt stack looking for a valid stack
frame.  Should this also fail 
.I adb
then searches the kernel
stack located in the user structure associated with
the last executing process.  If
.I adb
is able to locate a valid stack frame using this procedure
the command
.DS
D 5
\f(CW$c\fP
E 5
I 5
.cw
$c
.pw
E 5
.DE
will generate a stack trace from the last point at which
the kernel was executing on behalf of the user process
all the way
E 3
to the top of the user process's stack (e.g. to the
D 3
\fImain\fP routine in the user process which was running).
Otherwise, one must scan through the interrupt stack
looking for the stack frame.  This is usually indicated
by a zero longword entry (the procedure call handler)
followed by a longword entry with bit 29 set (indicating
the call frame was generated as a result of a ``calls''
instruction).
.sp 1
.in +5
.nf
\fBintstack\fP/\fBX\fP
.fi
.in -5
.sp 1
Once the stack pointer has been located, the command
.sp 1
.ti +5
D 2
\fB.\^$\^c\fP
E 2
I 2
\&\fB.\^$\^c\fP
E 2
.sp 1
will generate a stack trace.
An alternate method may be used when a trace of a particular
process is required, see section 2.3.
E 3
I 3
\fImain\fP routine in the user process).
Should
.I adb
be unable to locate a valid stack frame it prints a message
and the current state is left undefined.
When a stack trace of a particular process (other than that
which was currently executing) is desired, an
D 4
alternate method, described in \(sc2.3, should be used.
E 4
I 4
alternate method, described in \(sc2.4, should be used.
.PP
Additional information may be obtained from the kernel stack.
Discussion of that subject is postponed until command scripts
have been introduced; see \(sc2.2.
E 4
E 3
.ds RH "Command Scripts
D 3
.LP
.nr H1 2
.bp
.LG
.B
.ce
2. ADB COMMAND SCRIPTS
.sp 2
.R
.nr H2 0
.NL
E 3
I 3
.ne 2i
.NH
Command Scripts
E 3
.NH 2
Extending the Formatting Facilities
.PP
Once the process context has been established, the
complete
.I adb
command set is available for interpreting
data structures.  In addition, a number of
.I adb
scripts have
been created to simplify the structured printing of commonly
referenced kernel data structures.  The scripts normally
reside in
the directory \fI/usr/lib/adb\fP, and are invoked
with the ``$<'' operator.
D 3
(A later table lists the ``standard'' scripts.)
E 3
I 3
(A later table lists the standard scripts
distributed with the system.)
E 3
.PP
As an example, consider the following listing which
contains a dump of a faulty process's state
(our typing is shown emboldened).
D 3
.sp 1
.nf
E 3
I 3
.ID
E 3
.DT
D 3
% \fBadb \-k vmunix.17 vmcore.17\fP
sbr 8001d064 slr d9c
p0br 800efa00 p0lr 34 p1br 7f8efe00 p1lr 1ffff2
\fB*(intstack\-4)$c\fP
_boot() from 80004025
_boot(0,4) from 80004025
_panic(80021185) from 800057e2
_soreceive(8017478c,0) from 80007c90
_read() from 800098d7
_syscall() from 8000b6e2
_Xsyscall(3,7fffe834,258) from 80000f64
?() from c1c
?() from 26a
?(0,7fffef18,7fffef1c) from 1d3
?() from 2f
\fB800021185/s\fP
_icpreg+99:	receive
E 3
I 3
D 5
.ft CW
E 5
I 5
.cw
E 5
% \fBadb \-k vmunix.175 vmcore.175\fP
sbr 5868 slr 2770
p0br 5a00 p0lr 236 p1br	6600 p1lr fff0
panic: dup biodone
\fB$c\fP
_boot()	from _boot+f3
_boot(0,0) from	_panic+3a
_panic(800413d0) from _biodone+17
_biodone(800791e8) from	_rxpurge+23
_rxpurge(80044754) from	_rxstart+5a
_rxstart(80044754) from	80031df8
_rxintr(0) from	_Xrxintr0+11
_Xrxintr0(45b01,3aaf4) from 457f
_Syssize(3aaf4)	from 365a
_Syssize() from	19a8
?() from 2ff3
_Syssize(4,7fffe834) from 9cf3
_Syssize(4,7fffe834,7fffe848) from 37
?()
E 3
\fBu$<u\fP
_u:
_u:		ksp		usp
D 3
		7fffff9c	7fffe59c
E 3
I 3
		7fffff94	7fffe24c
E 3
		r0		r1		r2		r3
D 3
		155c00		800237d4	80041800	3
E 3
I 3
		12e000		80044e60	800661bc	15fd1
E 3
		r4		r5		r6		r7
D 3
		0		0		11090		80041800
E 3
I 3
		13		4		80065114	16544
E 3
		r8		r9		r10		r11
D 3
		80021244	c		7fffe5b4	80000000
E 3
I 3
		a0		80066de8	15a08		80000000
E 3
		ap		fp		pc		psl
D 3
		7fffffe8		7fffffa4		8000b784	d80004
E 3
I 3
		7fffffe8	7fffffa4	80029ed2	180000
E 3
		p0br		p0lr		p1br		p1lr
D 3
		800efa00	4000034	7f8efe00	1ffff2
E 3
I 3
		802f5a00	4000236		7faf6600	1ffff0
E 3
		szpt		cmap2		sswap
D 3
		2		94000307	0
		sigc1		sigc2		sigc3
		1af03fb		fa007f02	40cbc6c
_u+78:		arg0		arg1		arg2
		3		7fffe834	258
_u+8c:		segflg	error	uid	gid	ruid	rgid	procp
		0	0	4	a	4	a	80041800
E 3
I 3
		6		94000e59	0
_u+80:		procp		ar0		comm
		80066de8	80000000	ccom^@^@^@^@^@^@^@^@^@^@^@^@
_u+9c:		arg0		arg1		arg2
		46bfc		3aefc		0
_u+bc:		uap		qsave
		7fffec9c	7fffffa4	8002a11a
_u+f8:		rv1		rv2		error	eosys
		0		3aafa		0	03
7fffed02:	uid	ruid	gid	rgid
		2025	2025	10	10
7fffed0a:	groups
		10	0	2	3	11	79	-1	-1
		-1	-1	-1	-1	-1	-1	-1	-1
E 3

D 3
_u+d4:		uap		rv1		rv2		ubase
		7ffff078		0		1		7fffe834
		count		off		cdir		rdir
		258		150		8003cf00	0
_u+f4:		pathname
		.netrc
		dirp		dino	entry	pdir
		3		1395	.netrc0
7ffff11c:	ofiles
		80040818	80040818	80040818	800406b0
		800406d4	800406ec	0		0
E 3
I 3
7fffed2c:	tsize		dsize		ssize
		aa		18c		6
7fffeff0:	odsize		ossize		outime
		52		40		0
7fffeffc:	signal
E 3
		0		0		0		0
		0		0		0		0
I 3
		7a10		0		0		0
E 3
		0		0		0		0
I 3
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		sigmask
		0		4000		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		1
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
7ffff0fc:	onstack		sigintr		oldmask
		0		0		80002
7ffff108:	code		sigstack	onsigstack
		0		0		0
7ffff114:	ofile
		80063e40	80063e58	80064ce0	0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
		0		0		0		0
E 3

D 3
		ofileflg
E 3
I 3
		pofile
E 3
		0	0	0	0	0	0	0	0
		0	0	0	0	0	0	0	0
D 3
		0	0	0	0
7ffff180:	sigs
		0		360c		1		360c
		0		0		0		aae
E 3
I 3
		0	0	0	0	0	0	0	0
		0	0	0	0	0	0	0	0
		0	0	0	0	0	0	0	0
		0	0	0	0	0	0	0	0
		0	0	0	0	0	0	0	0
		0	0	0	0	0	0	0	0
7ffff254:	lastfile
		2
7ffff258:	cdir		rdir		ttyp		ttyd	cmask
		80060f80	0		80056be8	106	02

		ru
7ffff268:	utime				stime
		1		15f90		1		cf850
7ffff278:	maxrss		ixrss		idrss		isrss
		432		28250		79590		0
7ffff288:	minflt		majflt		nswap
		64		7		0
7ffff294:	inblock		oublock		msgsnd		msgrcv
		12		19		0		0
7ffff2a4:	nsignals	nvcsw		nivcsw
		0		12		22
7ffff2b0:	cru
7ffff2b0:	utime				stime
E 3
		0		0		0		0
I 3
7ffff2c0:	maxrss		ixrss		idrss		isrss
E 3
		0		0		0		0
I 3
7ffff2d0:	minflt		majflt		nswap
		0		0		0
7ffff2dc:	inblock		oublock		msgsnd		msgrcv
E 3
		0		0		0		0
D 3
		1		0		0		0
E 3
I 3
7ffff2ec:	nsignals	nvcsw		nivcsw
		0		0		0
7ffff2f8:	itimers
E 3
		0		0		0		0
		0		0		0		0
I 3
		0		0		0		0
7ffff328:	XXX
		0		0		0
7ffff334:	start			acflag
		1985 Nov  1 21:27:18	0
7ffff340:	pr_base		pr_size		pr_off		scale
		0		0		0		0
7ffff350:	limits
		7fffffff	7fffffff	7fffffff	7fffffff
		600000		1000000		80000		1000000
		7fffffff	7fffffff	123000		123000
7ffff380:	quota		qflags
		80074a18	0
7ffff388:	nc_off		nc_inum		nc_dev	nc_time
		284		2		8	1985 Nov  1 21:27:19
7ffff398:	ni_dirp		nameiop	ni_err	ni_pdir		ni_bp
		7fffe8a8	41	0	200		800606c4
7ffff3a8:	ni_base		ni_count	ni_iovec	ni_iovcnt
		0		92		7ffff3a8	1
7ffff3b8:	ni_offset	ni_segflg	ni_resid
		284		0		0
7ffff3c4:	ni_dent.d_inum	reclen	namlen	name
		19		72	9	ctm110435^@c^@^@^@
\fB80066de8$<proc\fP
80066de8:	link		rlink		next		prev
		80044e50	0		80067dec	8004e198
E 3

D 3
		code		ar0		prbase		prsize
		0		80000000	0		0

.ne 2
7ffff248:	proff		prscal		eosys	sep	ttyp
		0		0		0	0	800288b4

7ffff258:	ttymin	ttymaj
		0	0
7ffff25e:	xmag		xtsiz		xdsiz		xbsiz
		3c000000	10000000	108c0000	a680000

		xssiz		entloc		relflg
		0		0		6c720000
7ffff27e:	directory
		ogin
		start		acflg	fpflg	cmsk	tsiz	dsiz
		11688		0	12	0	160000		60000

7ffff2a2:	ssiz
		80000
\fB80041800$<proc\fP
80041800:	link		rlink		addr
		800237d4	0		800efde0
8004180c:	upri	pri	cpu	stat	time	nice	slp	cursig
		073	073	045	03	023	024	0	0
80041814:	sig		siga0		siga1		flag
		0		80002		45		8001
80041824:	uid	pgrp	pid	ppid	poip	szpt	tsize
		4	bb	bc	bb	0	2	1e
80041834:	dsize		ssize		rssize		maxrss
		16		6		14		3fffff
80041844:	swrss		swaddr		wchan		textp
		0		0		0		80044ee0
80041854:	clktim		p0br		xlink		ticks
		0		800efa00	80041720	22
80041864:	%cpu				ndx	idhash	pptr
		+5.1369253545999527e\-02	1c	8	80041720
\fB80044ee0$<text\fP
80044ee0:	daddr
		7e2		0		0		0
E 3
I 3
80066df8:	addr		upri	pri	cpu	stat	time
		802f65d8	0150	0150	0330	03	04
80066e01:	nice	slp	cursig		sig
		0	0	0		0
80066e08:	mask		ignore		catch
		0		0		80
80066e14:	flag		uid	pgrp	pid	ppid
		1008001		2025	11019	11045	11043
80066e20:	xstat		ru		poip	szpt	tsize
		0		0		0	6	aa
80066e30:	dsize		ssize		rssize		maxrss
		18c		6		13c		918
80066e40:	swrss		swaddr		wchan		textp
		0		6d8		0		8006b400
80066e50:	p0br		xlink		ticks
		802f5a00	0		0
80066e5c:	%cpu				ndx	idhash	pptr
		+0.0000000000000000e+00		3ea4	106a	2e
80066e68:	cptr		osptr		ysptr
		80067dec	0		0
80066e74:	real itimer
E 3
		0		0		0		0
I 3
80066e84:	quota		0
\fB8006b400$<text\fP
8006b400:	forw		back
		1f30		0
		daddr
E 3
		0		0		0		0
I 3
		0		0		0		0
		0		0		2c2		aa
E 3

D 3
		ptdaddr	size		caddr		iptr
		352		1e		80041800	8003cfa0
E 3
I 3
		ptdaddr		size		caddr		iptr
		80066de8	8005f4a0	74		10001
E 3

		rssize	swrss	count	ccount	flag	slptim	poip
D 3
		1a	0	02	02	042	0	0
.sp 1
.fi
.PP
E 3
I 3
		22	0	0100	031	0	0	0
I 5
.pw
E 5
.DE
E 3
The cause of the crash was a ``panic''
D 3
(see the stack trace) due to the 0
argument passed the \fIsoreceive\fP routine.  The majority
E 3
I 3
(see the stack trace) due to an inconsistency recognized
inside the \fIbiodone\fP routine.  The majority
E 3
of the dump was done to illustrate the use of two command
scripts used to format kernel data structures.  The ``u''
D 3
script, invoked by the command ``u$<u'', is a lengthy series
of commands which pretty-prints the user vector.  Likewise,
E 3
I 3
script, invoked with the command ``u$<u'', is a lengthy series
of commands which pretty-prints the user structure.  Likewise,
E 3
``proc'' and ``text'' are scripts used to format the obvious
data structures.  Let's quickly examine the ``text'' script (the
script has been broken into a number of lines for convenience
here; in actuality it is a single line of text).
D 3
.sp 1
.nf
\&./"daddr"n12Xn\e
E 3
I 3
.DS
D 5
.ft CW
E 5
I 5
.cw
E 5
\&./"forw"16t"back"n2Xn\e
"daddr"n12Xn\e
E 3
"ptdaddr"16t"size"16t"caddr"16t"iptr"n4Xn\e
"rssize"8t"swrss"8t"count"8t"ccount"8t"flag"8t"slptim"8t"poip"n2x4bx++n
D 3
.sp 1
.fi
The first line produces the list of disk block addresses associated
E 3
I 3
D 5
.ft P
E 5
I 5
.pw
E 5
.DE
The first line displays the pointers associated with the doubly
linked list used in managing text segments.
The second line produces the list of disk block addresses associated
E 3
with a swapped out text segment.  The ``n'' format forces a new-line
character, with 12 hexadecimal integers printed immediately after.
Likewise, the remaining two lines of the command format the remainder
of the text structure.  The expression ``16t'' causes
.I adb
to tab
to the next column which is a multiple of 16.  
The last two plus operators are present
to round ``.'' to the end of the text structure.  This allows the
user to reinvoke the format on consecutive text structures without
having to be concerned about proper alignment of ``.''.
.PP
The majority of the scripts provided are of this nature.
When possible, the formatting scripts print a data structure
with a single format to allow subsequent reuse when interrogating
arrays of structures.  That is, the previous script could have
been written
D 3
.sp 1
.nf
\&./"daddr"n12Xn
E 3
I 3
.DS
D 5
.ft CW
E 5
I 5
.cw
E 5
\&./"forw"16t"back"n2Xn
+/"daddr"n12Xn
E 3
+/"ptdaddr"16t"size"16t"caddr"16t"iptr"n4Xn
+/"rssize"8t"swrss"8t"count"8t"ccount"8t"flag"8t"slptim"8t"poip"n2x4bx++n
D 3
.sp 1
.fi
E 3
I 3
D 5
.ft P
E 5
I 5
.pw
E 5
.DE
E 3
but then reuse of the format would have invoked only the last
line of the format.
I 4
.NH 2
Locating stack frames
.PP
It is frequently desirable to locate stack frames
in order to examine local and register variables.
In particular, frames created by a trap include saved values
of all registers and the trap context, and all registers are saved
upon a panic as well.
Two scripts are provided for tracing stack frames.
The first is capable of tracing through multiple frames,
printing the information common to each.
The second prints all of the information available
in the stack frame after a trap.
The following example illustrates their use.
.ID
.DT
D 5
.ft CW
E 5
I 5
.cw
E 5
% \fBadb -k vmunix.188 vmcore.188\fP
sbr 7068 slr 2770
p0br 5a00 p0lr 74 p1br 5e00 p1lr fff0
panic: Segmentation fault
\fB$c\fP
_boot()	from 80029ddb
_boot(0,0) from	_panic+3a
_panic(800447a8) from _trap+ac
_trap()	from _Xtransflt+1d
_Xtransflt() from _Xsyscall+c
_Xsyscall(7fffe7ac,1b6)	from 514
?(7fffe7ac) from 4ac
?() from 196
?(2,7fffe810,7fffe81c) from 3d
?()
\fB1000$s\fP
\fB*(rpb+1fc),4$<frame\fP
7ffffe74:	handler		psr		mask
		0		0		2101
		ap		fp		pc
		7ffffec0	7ffffe9c	80029ddb	_boot+103

7ffffe9c:	handler		psr		mask
		0		0		2f00
		ap		fp		pc
		7fffff14	7ffffed0	80012de2	_panic+3a

7ffffed0:	handler		psr		mask
		0		0		2fff
		ap		fp		pc
		7fffff70	7fffff2c	8002a408	_trap+ac

7fffff2c:	handler		psr		mask
		0		0		2fff
		ap		fp		pc
		7fffffe8	7fffffa4	80001031	_Xtransflt+1d

\fB<1$<trapframe\fP
7fffff2c:	handler		psr		mask
		0		0		2fff
		ap		fp		pc
		7fffffe8	7fffffa4	80001031	_Xtransflt+1d
		r0		r1		r2		r3
		0		80046988	80046a00	800728db
		r4		r5		r6		r7
		800728b0	80054158	80063a60	80066ee0
		r8		r9		r10		r11
		80041b80	8		7fffe578	80000000
7fffff70:	nargs		sp		type		code
		0		7fffe560	8		2a50b6ca
		pc		(pc)		ps
		80001651	_Swtch+2b	d80008
\fB80001651?i\fP
_Swtch+2b:	remque	*0(r1),r2
\fB80046988/X\fP
_qs:
_qs:		2a50b6ca
I 5
.pw
E 5
.DE
.PP
The example shows a panic due to a segmentation fault.
The command ``1000$s'' expands the range over which addresses will be
displayed symbolically.
The back trace indicates that the trap occurred four frames
from the end;
as the frame pointer is stored at \fIrpb\fP\+1fc, the command
``*(rpb+1fc),4$<frame'' prints the last four stack frames;
``*(rpb+1fc)'' is the initial frame pointer, and the count determines the number
of frames to print.
Having located the stack frame after the trap (the frame with a return PC
of Xtransflt+1d), that frame may be displayed again using the script
for a trap frame.
The previous frame pointer was left in register 1 by the previous script,
and thus ``<1$<trapframe'' displays the state at the time of the trap.
The PC at the time of the fault is shown on the last line from the script,
with the faulting address listed as the code in the previous line.
The instruction that caused the fault can then be examined.
In this example, the instruction was a remque that used a displacement
addressing mode indirecting through R1.
The location to which the register points is the first of the process
run queues, and its first element can be seen to be corrupted;
its forward pointer, 2a50b6ca, is invalid and is the address that caused
the fault.
E 4
.NH 2
Traversing Data Structures
.PP
The
.I adb
command language can be used to traverse complex data
D 3
structures.  One such data structure, a linked list, occurs
E 3
I 3
structures.  One data structure, a linked list, occurs
E 3
quite often in the kernel.  By using
.I adb
variables and the
normal expression operators it is a simple matter to construct
D 3
a script which chains down the list printing each element
E 3
I 3
a script which chains down a list printing each element
E 3
along the way.
.PP
For instance, the queue of processes awaiting timer events,
the callout queue, is printed with the following two scripts:
D 3
.sp 1
.nf
.ne 4
\fBcallout\fP:
E 3
I 3
.ID
D 5
.ft CW
E 5
I 5
.cw
E 5
E 3
.in +5
D 3
.sp 1
E 3
I 3
.ne 3
.ti -5
\fBcallout\fP:
E 3
calltodo/"time"16t"arg"16t"func"12+
*+$<callout.next
.sp 1
.ne 6
.ti -5
\fBcallout.next\fP:
D 3
.sp 1
E 3
\&./Dpp
*+>l
,#<l$<
<l$<callout.next
D 3
.sp 1
E 3
.in -5
I 5
.pw
E 5
D 3
.fi
.PP
E 3
I 3
.DE
E 3
The first line of the script \fBcallout\fP starts the traversal
at the global symbol
\fIcalltodo\fP and prints a set of headings.
It then skips the empty portion of the structure used
as the head of the queue.
The second line then invokes the script \fBcallout.next\fP
moving ``.'' to
the top of the queue (``*+'' performs the indirection
through the link entry of the structure at the head of the queue).
.PP
\fBcallout.next\fP prints values for each column, then performs
a conditional test on the link to the next entry.  This test
is performed as follows,
.IP "*+>l" 9
Place the value of the ``link'' in the
.I adb
variable ``<l''.
.IP ",#<l$<"
If the value stored in ``<l'' is non-zero, then the current
input stream (i.e. the script \fBcallout.next\fP) is terminated.
Otherwise, the expression ``#<l'' will be zero, and the ``$<''
will be ignored.  That is, the combination of the logical negation
D 3
operator ``#'',
E 3
I 3
operator ``#'', the
E 3
.I adb
D 3
variable ``<l'', and ``$<'' operator
E 3
I 3
variable ``<l'', and the ``$<'' operator
E 3
creates a statement of the form,
D 3
.sp 1
.ti +0.5i
if (!link) exit;
.sp 1
E 3
I 3
.DS
D 5
\f(CWif (!link) exit;\fP
E 5
I 5
.cw
if (!link) exit;
.pw
E 5
.DE
E 3
The remaining line of \fBcallout.next\fP simply reapplies the
script on the next element in the linked list.
.LP
A sample \fIcallout\fP dump is shown below.
D 3
.nf
.sp 1
.ne 14
E 3
I 3
.ID
D 5
.ft CW
E 5
I 5
.cw
E 5
E 3
% \fBadb \-k /vmunix /dev/mem\fP
sbr 8001f864 slr d9c
p0br 800efa00 p0lr 8e p1br 7f8efe00 p1lr 1ffff2
\fB$<callout\fP
_calltodo:
_calltodo:	time		arg			func
8004ecfc:	26		0			_dzscan
8004ed0c:	8		0			_upwatch
8004ed1c:	0		0			_ip_timeo
8004ed5c:	0		0			_tcp_timeo
8004ed6c:	0		0			_rkwatch
8004ecfc:	52		0			_dzscan
8004ed2c:	68		_Syssize+70	_tmtimer
8004ed3c:	2920		0			_memenable
I 5
.pw
E 5
D 3
.fi
.sp 1
E 3
I 3
.DE
E 3
.NH 2
Supplying Parameters
.PP
If one is clever, a command script may use the address
and count portions of an
.I adb
command as parameters.  An example of
this is the \fBsetproc\fP script used to switch to the
context of a process with a known process-id;
D 3
.sp 1
.ti +5
\fB0t99$<setproc\fP
.sp 1
E 3
I 3
.DS
D 5
\f(CW0t99$<setproc\fP
E 5
I 5
.cw
0t99$<setproc
.pw
E 5
.DE
E 3
The body of \fBsetproc\fP is
D 3
.sp 1
.in +5
.nf
E 3
I 3
.DS
D 5
.ft CW
E 5
I 5
.cw
E 5
E 3
\&.>4
*nproc>l
*proc>f
$<setproc.nxt
I 5
.pw
E 5
D 3
.in -5
.sp 1
.fi
E 3
I 3
.DE
E 3
while \fBsetproc.nxt\fP is
D 3
.sp 1
.nf
.in +5
(*(<f+28))&0xffff="pid "X
,#((*(<f+28)&0xffff)-<4)$<setproc.done
E 3
I 3
.DS
D 5
.ft CW
E 5
I 5
.cw
E 5
(*(<f+0t52))&0xffff="pid "D
,#((*(<f+0t52)&0xffff)-<4)$<setproc.done
E 3
<l-1>l
D 3
<f+70>f
E 3
I 3
<f+0t164>f
E 3
,#<l$<
$<setproc.nxt
I 5
.pw
E 5
D 3
.in -5
.sp 1
.fi
E 3
I 3
.DE
E 3
The process-id, supplied as the parameter, is stored in the
variable ``<4'', the number of processes is placed in ``<l'',
and the base of the array of process structures in ``<f''.
\fBsetproc.nxt\fP then performs a linear search through the
array until it matches the process-id requested, or until
it runs out of process structures to check.  The script
\fBsetproc.done\fP simply establishes the context of the
process, then exits.
.NH 2
Standard Scripts
.PP
D 3
The following table summarizes the command scripts currently
available in the directory \fI/usr/lib/adb\fP.
.TS
E 3
I 3
The following table summarizes the command scripts supplied
with 4.3BSD; these scripts are found in the directory \fI/usr/lib/adb\fP.
.TS H
E 3
center, box;
c s s
l | l | l
lb | l | l.
Standard Command Scripts
_
Name	Use	Description
_
I 3
.TH
E 3
buf	\fIaddr\fP$<\fBbuf\fP	format block I/O buffer
callout	$<\fBcallout\fP	print timer queue
clist	\fIaddr\fP$<\fBclist\fP	format character I/O linked list
dino	\fIaddr\fP$<\fBdino\fP	format directory inode
dir	\fIaddr\fP$<\fBdir\fP	format directory entry
dirblk	\fIaddr\fP$<\fBdirblk\fP	scan directory entries
I 3
dmap	\fIaddr\fP$<\fBdmap\fP	format a disk-map structure
dmcstats	$<\fBdmcstats\fP	dump statistics for dmc0
E 3
file	\fIaddr\fP$<\fBfile\fP	format open file structure
D 3
fs	\fIaddr\fP$<\fBfilsys\fP	format in-core super block structure
E 3
I 3
filsys	\fIaddr\fP$<\fBfilsys\fP	format in-core super block structure
findinode	\fIinum\fP$<\fBfindinode\fP	find an inode in the in-core inode table
E 3
findproc	\fIpid\fP$<\fBfindproc\fP	find process by process id
I 3
frame	\fIaddr\fP,\fIcount\fP$<\fBframe\fP	trace \fIcount\fP stack frames starting at \fIaddr\fP
E 3
hosts	\fIaddr\fP$<\fBhosts\fP	format IMP host table entries
hosttable	\fIaddr\fP$<\fBhosttable\fP	show all IMP host table entries
I 3
ifaddr	\fIaddr\fP$<\fBifaddr\fP	format a network interface address structure
E 3
ifnet	\fIaddr\fP$<\fBifnet\fP	format network interface structure
ifuba	\fIaddr\fP$<\fBifuba\fP	format UNIBUS resource structure
I 3
imp	\fIaddr\fP$<\fBimp\fP	format an IMP interface state structure
in_ifaddr	\fIaddr\fP$<\fBin_ifaddr\fP	format internet network addresses for an interface
E 3
inode	\fIaddr\fP$<\fBinode\fP	format in-core inode structure
inpcb	\fIaddr\fP$<\fBinpcb\fP	format internet protocol control block
iovec	\fIaddr\fP$<\fBiovec\fP	format a list of \fIiov\fP structures
ipreass	\fIaddr\fP$<\fBipreass\fP	format an ip reassembly queue
mact	\fIaddr\fP$<\fBmact\fP	show ``active'' list of mbuf's
I 3
mba_device	\fIaddr\fP$<\fBmba_device\fP	format an MBA device structure
mba_hd	\fIaddr\fP$<\fBmba_hd\fP	format an MBA queue head
E 3
mbstat	$<\fBmbstat\fP	show mbuf statistics
mbuf	\fIaddr\fP$<\fBmbuf\fP	show ``next'' list of mbuf's
I 3
mbufchain	\fIaddr\fP$<\fBmbufchain\fP	display a chain of mbufs queued at a socket
E 3
mbufs	\fIaddr\fP$<\fBmbufs\fP	show a number of mbuf's
mount	\fIaddr\fP$<\fBmount\fP	format mount structure
I 3
nameidata	\fIaddr\fP$<\fBnameidata\fP	format a namei parameter block
packetchain	\fIaddr\fP$<\fBpacketchain\fP	format a chain of packets
E 3
pcb	\fIaddr\fP$<\fBpcb\fP	format process context block
proc	\fIaddr\fP$<\fBproc\fP	format process table entry
I 3
protosw	\fIaddr\fP$<\fBprotosw\fP	format a protocol switch entry
quota	\fIaddr\fP$<\fBquota\fP	format a disk quota structure
E 3
rawcb	\fIaddr\fP$<\fBrawcb\fP	format a raw protocol control block
rtentry	\fIaddr\fP$<\fBrtentry\fP	format a routing table entry
I 3
rusage	\fIaddr\fP$<\fBrusage\fP	format a resource usage structure
E 3
setproc	\fIpid\fP$<\fBsetproc\fP	switch process context to \fIpid\fP
socket	\fIaddr\fP$<\fBsocket\fP	format socket structure
I 3
stat	\fIaddr\fP$<\fBstat\fP	format a stat structure
E 3
tcpcb	\fIaddr\fP$<\fBtcpcb\fP	format TCP control block
tcpip	\fIaddr\fP$<\fBtcpip\fP	format a TCP/IP packet header
tcpreass	\fIaddr\fP$<\fBtcpreass\fP	show a TCP reassembly queue
text	\fIaddr\fP$<\fBtext\fP	format text structure
traceall	$<\fBtraceall\fP	show stack trace for all processes
I 3
trapframe	\fIaddr\fP$<\fBtrapframe\fP	format a stack frame generated by a trap
E 3
tty	\fIaddr\fP$<\fBtty\fP	format tty structure
u	\fIaddr\fP$<\fBu\fP	format user vector, including pcb
I 3
ubadev	\fIaddr\fP$<\fBubadev\fP	format a UBA device structure
E 3
ubahd	\fIaddr\fP$<\fBubahd\fP	format a UNIBUS header structure
I 3
unpcb	\fIaddr\fP$<\fBunpcb\fP	format a UNIX domain protocol control block
E 3
.TE
.ds RH "Summary
D 3
.LP
.nr H1 2
.bp
.LG
.B
.ce
3. SUMMARY
.sp 2
.R
.nr H2 0
.NL
E 3
I 3
.NH
Summary
E 3
.PP
The extensions made to
.I adb
provide basic support for debugging the
.UX
kernel by eliminating the need for a user to carry
D 3
out virtual to physical address translation.  A collection
of scripts have been written to nicely format the major
E 3
I 3
out virtual to physical address translation and by automatically
locating the stack frame after a system crash.  A collection
of scripts have been written to format the major
E 3
kernel data structures and aid in switching between
D 3
process contexts.  This has been carried out with
only minimal changes to the debugger.
.PP
More work is needed to provide enough information
for the debugger to automatically establish context
after a system crash.  The system currently does not
always save enough state to allow the debugger to reliably
locate the stack frame just prior to an exception.
.PP
More work is also required on the user interface
to \fIadb\fP.  It appears the inscrutable
E 3
I 3
process contexts.  These facilities have been implemented with
only minimal changes to the debugger.  While the symbolic debugger
.I dbx
provides facilities similar to those described here it is
not yet a viable alternative to
E 3
.I adb
D 3
command language
has limited widespread use of much of the power of
\fIadb\fP.  One possibility is to provide a more comprehensible
``adb frontend'', just as \fIbc\fP(1) is used to
frontend \fIdc\fP(1).
.PP
Finally,
.I adb
could be significantly improved if it
were knowledgeable about a program's data structures.
This would eliminate the use of numeric offsets into
C structures.
E 3
I 3
because
.I dbx
takes too long to read in the symbol table.  As soon as
this problem is corrected there will be only limited need for
the facilities provided by \fIadb\fP.
E 3
E 1
