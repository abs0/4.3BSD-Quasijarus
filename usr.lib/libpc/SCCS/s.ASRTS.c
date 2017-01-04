h27643
s 00015/00000/00000
d D 1.1 82/11/12 12:11:33 mckusick 1 0
c date and time created 82/11/12 12:11:33 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1982 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

char EASRTS[] = "Assertion failed: %s\n";

ASRTS(cond, stmt)
	short	cond;
	char	*stmt;
{
	if (cond)
		return;
	ERROR(EASRTS, stmt);
	return;
}
E 1
