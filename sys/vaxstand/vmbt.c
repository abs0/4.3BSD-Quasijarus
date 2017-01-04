/*
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)vmbt.c	7.3 (Berkeley) 7/1/04
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

vmbtopen(io)
	register struct iob *io;
{
	register int skip;
	register int qiostat;

	if (!vmb_info)
		return(ENXIO);
	qioinit(io->i_unit);
	for (skip = io->i_part; skip--;) {
		qiostat = qioentry(0, 0, 0, IO$_SKIPFILE, PHYSMODE,
					vmb_info->rpbbas);
		if (qiostat & 1)
			continue;
		else {
			printf("VMB error positioning tape: ");
			vmberr(qiostat);
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

	qiostat = qioentry(0, 0, 0, IO$_REWIND, PHYSMODE, vmb_info->rpbbas);
	if (qiostat & 1)
		return(0);
	else {
		printf("VMB error rewinding tape: ");
		vmberr(qiostat);
		io->i_error = EIO;
		return (-1);
	}
}
