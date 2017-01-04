h55776
s 00001/00002/00023
d D 1.2 83/01/10 16:43:00 mckusick 2 1
c SETRACE() -> kill()
e
s 00025/00000/00000
d D 1.1 81/06/10 00:48:04 mckusick 1 0
c date and time created 81/06/10 00:48:04 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include	<stdio.h>
#include	<signal.h>
D 2
#include	"h00vars.h"
E 2

/*
 * Routine PERROR is called from the runtime library when a runtime
 * I/O error occurs. Its arguments are a pointer to an error message and 
 * the name of the offending file.
 */
long
PERROR(msg, fname)

	char	*msg, *fname;
{
	PFLUSH();
	fputc('\n',stderr);
D 2
	SETRACE();
E 2
	fputs(msg, stderr);
	perror(fname);
I 2
	kill(getpid(), SIGTRAP);
E 2
	return 0;
}
E 1
