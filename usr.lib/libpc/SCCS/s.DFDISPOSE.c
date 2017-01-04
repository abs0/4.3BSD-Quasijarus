h27998
s 00001/00001/00031
d D 4.3 86/07/07 18:38:13 mckusick 3 2
c do not get too carried away (from tektronix!sutton <Carl D. Sutton>)
e
s 00001/00001/00031
d D 4.2 83/01/21 18:58:41 mckusick 2 1
c fix for prematurely removing temp files
e
s 00032/00000/00000
d D 4.1 83/01/10 14:50:59 mckusick 1 0
c date and time created 83/01/10 14:50:59 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1982 Regents of the University of California */

static	char sccsid[] = "%W%	(Berkeley)	%G%";

/*
 * Close all active files within a dynamic record,
 * then dispose of the record.
 */

#include "h00vars.h"
#include "libpc.h"

DFDISPOSE(var, size)
	char	**var;	/* pointer to pointer being deallocated */
	long	size;	/* sizeof(bletch) */
{
	register struct iorec	*next, *prev;
	struct iorec *start, *end;

	start = (struct iorec *)(*var);
	end = (struct iorec *)(*var + size);
	prev = (struct iorec *)(&_fchain);
	next = _fchain.fchain;
	while(next != FILNIL && (next->flev < GLVL || next < start)) {
		prev = next;
		next = next->fchain;
	}
D 3
	while(next != FILNIL && next < end)
E 3
I 3
	while(next != FILNIL && start <= next && next < end)
E 3
D 2
		next = PFCLOSE(next);
E 2
I 2
		next = PFCLOSE(next, TRUE);
E 2
	prev->fchain = next;
	DISPOSE(var, size);
}
E 1
