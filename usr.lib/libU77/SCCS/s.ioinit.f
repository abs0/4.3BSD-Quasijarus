h27994
s 00005/00004/00105
d D 5.2 91/04/12 15:36:10 bostic 7 6
c new copyright; att/bsd/shared
e
s 00008/00001/00101
d D 5.1 85/06/08 00:02:01 kre 6 5
c Add copyright
e
s 00004/00004/00098
d D 1.5 83/04/25 17:06:03 dlw 5 4
c changed default open to be BOF. DLW
e
s 00001/00003/00101
d D 1.4 83/04/25 01:37:00 dlw 4 3
c changed common block definitions. DLW
e
s 00034/00020/00070
d D 1.3 83/04/21 23:26:13 dlw 3 2
c made separate flags for ccntrl & blzero. DLW
e
s 00020/00010/00070
d D 1.2 83/04/15 23:01:20 dlw 2 1
c cleaned up; added notification if no prefixNN found. DLW
e
s 00080/00000/00000
d D 1.1 83/04/14 22:19:54 dlw 1 0
c date and time created 83/04/14 22:19:54 by dlw
e
u
U
t
T
I 1
C
I 6
D 7
C Copyright (c) 1980 Regents of the University of California.
C All rights reserved.  The Berkeley software License Agreement
C specifies the terms and conditions for redistribution.
E 7
I 7
C Copyright (c) 1980 The Regents of the University of California.
C All rights reserved.
E 7
C
I 7
C %sccs.include.proprietary.f%
C
E 7
C	%W% (Berkeley) %G%
C
D 7
C
E 7
I 7

E 7
E 6
C ioinit - initialize the I/O system
D 6
C		%W%
E 6
I 6
C
E 6
C synopsis:
D 3
C	logical function ioinit (io66, ioapnd, prefix, vrbose)
C	logical io66, ioapnd
E 3
I 3
C	logical function ioinit (cctl, bzro, apnd, prefix, vrbose)
C	logical cctl, bzro, apnd, vrbose
E 3
C	character*(*) prefix
C
C where:
D 3
C	io66	is .true. to turn on fortran-66 carriage control
C	ioapnd	is .true. to open files at their end
E 3
I 3
C	cctl	is .true. to turn on fortran-66 carriage control
C	bzro	is .true. to cause blank space to be zero on input
C	apnd	is .true. to open files at their end
E 3
C	prefix	is a string defining environment variables to
C		be used to initialize logical units.
C	vrbose	is .true. if the caller wants output showing the lu association
C
C returns:
C	.true. if all went well
C
C David L. Wasley
C U.C.Bekeley
C
D 3
	logical function ioinit (io66, ioapnd, prefix, vrbose)
	logical		io66, ioapnd, vrbose
E 3
I 3
	logical function ioinit (cctl, bzro, apnd, prefix, vrbose)
	logical		cctl, bzro, apnd, vrbose
E 3
	character*(*)	prefix

D 2
	automatic	iok, ename, fname
	logical		iok
	integer*2	if66, ibof
E 2
I 2
D 3
	automatic	iok, fenv, ienv, ename, fname
E 3
I 3
	automatic	iok, fenv, ienv, ename, fname, form, blank
E 3
	logical		iok, fenv, ienv
D 3
	integer*2	ibof, i66
E 3
I 3
D 5
	integer*2	ibof, ictl, izro
E 5
I 5
	integer*2	ieof, ictl, izro
E 5
	character	form, blank
E 3
E 2
	character*32	ename
	character*256	fname
D 2
	common /init66/ if66
E 2
D 3
	common /opnbof/ ibof
I 2
	common /init66/ i66
E 3
I 3
D 4
	common /opnbof/	ibof
	common /ccntrl/	ictl
	common /blzero/	izro
E 4
I 4
D 5
	common /ioiflg/	ibof, ictl, izro
E 5
I 5
	common /ioiflg/	ieof, ictl, izro
E 5
E 4
E 3
E 2

D 3
	if (io66) then
D 2
		if66 = 1
E 2
I 2
		i66 = 1
		open (unit=6, form='p', blank='z')
E 3
I 3
	if (cctl) then
	    ictl = 1
	    form = 'p'
E 3
E 2
	else
D 2
		if66 = 0
E 2
I 2
D 3
		i66 = 0
		open (unit=6, form='f', blank='n')
E 3
I 3
	    ictl = 0
	    form = 'f'
E 3
E 2
	endif

D 3
	if (ioapnd) then
		ibof = 0
E 3
I 3
	if (bzro) then
	    izro = 1
	    blank = 'z'
E 3
	else
D 3
		ibof = 1
E 3
I 3
	    izro = 0
	    blank = 'n'
E 3
	endif

I 3
	open (unit=5, form=form, blank=blank)
	open (unit=6, form=form, blank=blank)

	if (apnd) then
D 5
	    ibof = 0
E 5
I 5
	    ieof = 1
E 5
	else
D 5
	    ibof = 1
E 5
I 5
	    ieof = 0
E 5
	endif

E 3
	iok = .true.
I 2
	fenv = .false.
	ienv = .false.
E 2
	lp = len (prefix)

	if ((lp .gt. 0) .and. (lp .le. 30) .and. (prefix .ne. " ")) then
I 2
	    ienv = .true.
E 2
	    nb = index (prefix, " ")
	    if (nb .eq. 0) nb = lp + 1
	    ename = prefix
D 2
	    if (vrbose) write (0, "('ioinit: initializing from ', a, 'nn')")
     +			    ename(:nb-1)
E 2
I 2
	    if (vrbose) write (0, 2002) ename(:nb-1)
E 2
	    do 200 lu = 0, 19
		write (ename(nb:), "(i2.2)") lu
		call getenv (ename, fname)
		if (fname .eq. " ") go to 200

		open (unit=lu, file=fname, form='f', access='s', err=100)
		if (vrbose) write (0, 2000) lu, fname(:lnblnk(fname))
I 2
		fenv = .true.
E 2
		go to 200

D 2
  100		write (0, "('ioinit: ', a, ' ', $)") ename(:lnblnk(ename))
E 2
I 2
  100		write (0, 2003) ename(:nb+1)
E 2
		call perror (fname(:lnblnk(fname)))
		iok = .false.

  200	    continue
	endif

	if (vrbose) then
D 2
	    write (0, "('ioinit: io66=', l, ', ioapnd=', l)") io66, ioapnd
E 2
I 2
	    if (ienv .and. (.not. fenv)) write (0, 2001) ename(:nb-1)
D 3
	    write (0, 2004) io66, ioapnd
E 3
I 3
	    write (0, 2004) cctl, bzro, apnd
E 3
E 2
	    call flush (0)
	endif

	ioinit = iok
	return

 2000	format ('ioinit: logical unit ', i2,' opened to ', a)
I 2
 2001	format ('ioinit: no initialization found for ', a)
 2002	format ('ioinit: initializing from ', a, 'nn')
 2003	format ('ioinit: ', a, ' ', $)
D 3
 2004	format ('ioinit: io66=', l, ', ioapnd=', l)
E 3
I 3
 2004	format ('ioinit: cctl=', l, ', bzro=', l, ', apnd=', l)
E 3
E 2
	end
E 1
