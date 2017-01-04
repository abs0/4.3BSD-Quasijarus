h55740
s 00011/00071/00051
d D 5.3 87/04/07 15:55:11 mckusick 4 3
c port to tahoe by Nir peleg of CCI
e
s 00004/00004/00118
d D 5.2 87/03/17 20:33:22 lepreau 3 2
c pruge "& before fxn"
e
s 00008/00003/00114
d D 5.1 85/06/06 11:41:18 dist 2 1
c Add copyright
e
s 00117/00000/00000
d D 1.1 82/01/18 19:20:45 linton 1 0
c date and time created 82/01/18 19:20:45 by linton
e
u
U
t
T
I 1
D 2
/* Copyright (c) 1982 Regents of the University of California */
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 2

D 2
static char sccsid[] = "%Z%%M% %I% %G%";

E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
I 4

E 4
E 2
/*
D 4
 * These routines are used to access the debuggee process from
E 4
I 4
 * This routine is used to access the debuggee process from
E 4
 * outside the "process" module.
 *
 * They invoke "pio" which eventually leads to a call to "ptrace".
 * The system generates an I/O error when a ptrace fails, we catch
 * that here and assume its due to a misguided address.
 */

#include "defs.h"
#include <errno.h>
#include "process.h"
#include "process.rep"

D 4
#	if (isvaxpx)
#		include "pxinfo.h"
#	endif
E 4
I 4
#	include "pxinfo.h"
E 4

typedef int INTFUNC();

extern INTFUNC *onsyserr();

LOCAL badaddr;
I 4
LOCAL PIO_OP rwflg;
E 4
LOCAL rwerr();

/*
D 4
 * Read from the process' instruction area.  For px, this is actually
 * the data area.
E 4
I 4
 * Read/Write to the process' data area.
E 4
 */

D 4
iread(buff, addr, nbytes)
E 4
I 4
drdwr(rw, buff, addr, nbytes)
PIO_OP rw;
E 4
char *buff;
ADDRESS addr;
int nbytes;
{
	INTFUNC *f;

D 3
	f = onsyserr(EIO, &rwerr);
E 3
I 3
	f = onsyserr(EIO, rwerr);
E 3
D 4
#	if (isvaxpx)
		badaddr = addr + ENDOFF;
		pio(process, PREAD, DATASEG, buff, addr + ENDOFF, nbytes);
#	else
		badaddr = addr;
		pio(process, PREAD, TEXTSEG, buff, addr, nbytes);
#	endif
	onsyserr(EIO, f);
}

/* 
 * Write to the process' instruction area, usually in order to set
 * or unset a breakpoint.
 */

iwrite(buff, addr, nbytes)
char *buff;
ADDRESS addr;
int nbytes;
{
	INTFUNC *f;

D 3
	f = onsyserr(EIO, &rwerr);
E 3
I 3
	f = onsyserr(EIO, rwerr);
E 3
#	if (isvaxpx)
		badaddr = addr + ENDOFF;
		pio(process, PWRITE, DATASEG, buff, addr + ENDOFF, nbytes);
#	else
		badaddr = addr;
		pio(process, PWRITE, TEXTSEG, buff, addr, nbytes);
#	endif
	onsyserr(EIO, f);
}

/*
 * Read for the process' data area.
 */

dread(buff, addr, nbytes)
char *buff;
ADDRESS addr;
int nbytes;
{
	INTFUNC *f;

D 3
	f = onsyserr(EIO, &rwerr);
E 3
I 3
	f = onsyserr(EIO, rwerr);
E 4
E 3
	badaddr = addr;
D 4
	pio(process, PREAD, DATASEG, buff, addr, nbytes);
E 4
I 4
	rwflg = rw;
	pio(process, rw, DATASEG, buff, addr, nbytes);
E 4
	onsyserr(EIO, f);
}

/*
D 4
 * Write to the process' data area.
 */

dwrite(buff, addr, nbytes)
char *buff;
ADDRESS addr;
int nbytes;
{
	INTFUNC *f;

D 3
	f = onsyserr(EIO, &rwerr);
E 3
I 3
	f = onsyserr(EIO, rwerr);
E 3
	badaddr = addr;
	pio(process, PWRITE, DATASEG, buff, addr, nbytes);
	onsyserr(EIO, f);
}

/*
E 4
 * Error handler.
 */

LOCAL rwerr()
{
D 4
	error("bad read/write process address 0x%x", badaddr);
E 4
I 4
	error("bad %s process address 0x%x",
		rwflg == PREAD ? "read" : "write", badaddr);
E 4
}
E 1
