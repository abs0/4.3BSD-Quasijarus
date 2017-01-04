h07726
s 00003/00002/00062
d D 7.3 04/07/01 20:15:43 msokolov 3 2
c QIO arguments in the wrong order
e
s 00004/00004/00060
d D 7.2 04/02/07 17:14:50 msokolov 2 1
c oops, can't use sprintf
e
s 00064/00000/00000
d D 7.1 04/02/07 17:03:21 msokolov 1 0
c date and time created 04/02/07 17:03:21 by msokolov
e
u
U
t
T
I 1
/*
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

/*
 * VMB tape device driver
 */

#include "param.h"
#include "inode.h"
#include "buf.h"
#include "fs.h"
#include "disklabel.h"

#include "saio.h"
#include "savax.h"

#include "../mdec/vmb.h"

extern struct vmb_info *vmb_info;
extern int (*qioentry)();
D 2
extern char *vmberr();
E 2

vmbtopen(io)
	register struct iob *io;
{
	register int skip;
	register int qiostat;

	if (!vmb_info)
		return(ENXIO);
	qioinit(io->i_unit);
	for (skip = io->i_part; skip--;) {
D 3
		qiostat = qioentry(vmb_info->rpbbas, PHYSMODE, IO$_SKIPFILE);
E 3
I 3
		qiostat = qioentry(0, 0, 0, IO$_SKIPFILE, PHYSMODE,
					vmb_info->rpbbas);
E 3
		if (qiostat & 1)
			continue;
		else {
D 2
			printf("VMB error positioning tape: %s\n",
				vmberr(qiostat));
E 2
I 2
			printf("VMB error positioning tape: ");
			vmberr(qiostat);
E 2
			io->i_error = EIO;
			return (-1);
		}
	}
	return (0);
}

vmbtclose(io)
	struct iob *io;
{
	register int qiostat;

D 3
	qiostat = qioentry(vmb_info->rpbbas, PHYSMODE, IO$_REWIND);
E 3
I 3
	qiostat = qioentry(0, 0, 0, IO$_REWIND, PHYSMODE, vmb_info->rpbbas);
E 3
	if (qiostat & 1)
		return(0);
	else {
D 2
		printf("VMB error rewinding tape: %s\n", vmberr(qiostat));
E 2
I 2
		printf("VMB error rewinding tape: ");
		vmberr(qiostat);
E 2
		io->i_error = EIO;
		return (-1);
	}
}
E 1
