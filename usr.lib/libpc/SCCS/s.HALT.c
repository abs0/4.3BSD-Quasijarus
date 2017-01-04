h61128
s 00003/00001/00009
d D 1.3 81/06/10 01:13:23 mckusic 4 2
c move text of error messages from ERROR to functions which gen them
e
s 00002/00001/00009
d R 1.3 81/06/10 00:58:39 mckusic 3 2
c do not call ERROR, since do not want to generate an error
e
s 00002/00002/00008
d D 1.2 81/06/10 00:38:08 mckusic 2 1
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00010/00000/00000
d D 1.1 80/10/30 00:33:29 mckusick 1 0
c date and time created 80/10/30 00:33:29 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 4
#include "h00vars.h"
E 4
D 2
#include "h01errs.h"
E 2

HALT()
{
D 2
	ERROR(EHALT, 0);
E 2
I 2
D 4
		ERROR("Call to procedure halt\n", 0);
E 4
I 4
		PFLUSH();
		fputs("Call to procedure halt\n", stderr);
E 4
		PCEXIT(0);
E 2
}
E 1
