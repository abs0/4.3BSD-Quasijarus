h49945
s 00002/00002/00028
d D 1.3 81/03/07 15:59:28 mckusic 4 3
c merge in onyx changes
e
s 00009/00008/00021
d D 1.2 81/01/13 15:15:40 mckusic 3 1
c modify to allow use by both ``pc'' and ``pi''
e
s 00009/00008/00021
d R 1.2 81/01/06 14:59:43 mckusic 2 1
c allow use with both static (pc) and dynamic (pi) count buffers
e
s 00029/00000/00000
d D 1.1 80/10/30 00:40:38 mckusick 1 0
c date and time created 80/10/30 00:40:38 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"

D 3
PMFLUSH(cntrs, rtns)
E 3
I 3
PMFLUSH(cntrs, rtns, bufaddr)
E 3

D 3
	long	cntrs;	/* total number of counters (stmt + routine) */
	long	rtns;	/* number of func and proc counters */
E 3
I 3
	long cntrs;	/* total number of counters (stmt + routine) */
	long rtns;	/* number of func and proc counters */
	long *bufaddr;	/* address of count buffers */
E 3
{
	register FILE	*filep;

D 3
	_pcpcount[0] = 0426;
	_pcpcount[1] = time();
	_pcpcount[2] = cntrs;
	_pcpcount[3] = rtns;
E 3
I 3
	bufaddr[0] = 0426;
D 4
	bufaddr[1] = time();
E 4
I 4
	time(&bufaddr[1]);
E 4
	bufaddr[2] = cntrs;
	bufaddr[3] = rtns;
E 3
	filep = fopen(PXPFILE, "w");
	if (filep == NULL)
		goto ioerr;
D 3
	fwrite(&_pcpcount[0], cntrs + 1, sizeof(long), filep);
E 3
I 3
D 4
	fwrite(bufaddr, cntrs + 1, sizeof(long), filep);
E 4
I 4
	fwrite(bufaddr, (int)(cntrs + 1), sizeof(long), filep);
E 4
E 3
	if (ferror(filep))
		goto ioerr;
	fclose(filep);
	if (!ferror(filep))
		return;
ioerr:
	perror(PXPFILE);
}
E 1
