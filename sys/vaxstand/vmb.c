/*
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)vmb.c	7.3 (Berkeley) 7/1/04
 */

/*
 * VMB disk device driver
 */

#include "param.h"
#include "inode.h"
#include "buf.h"
#include "fs.h"
#include "disklabel.h"

#include "saio.h"
#include "savax.h"

#include "../mdec/vmb.h"

#define	SECTSIZ 	512	/* sector size in bytes */
char	lbuf[SECTSIZ];

extern struct vmb_info *vmb_info;
extern int (*qioentry)();

vmbopen(io)
	register struct iob *io;
{
	register struct disklabel *lp;
	struct iob tio;

	if (!vmb_info)
		return(ENXIO);
	qioinit(io->i_unit);
	tio = *io;
	tio.i_bn = LABELSECTOR;
	tio.i_ma = lbuf;
	tio.i_cc = SECTSIZ;
	tio.i_flgs |= F_RDDATA;
	if (vmbstrategy(&tio, READ) != SECTSIZ)
		return (ERDLAB);
	*lp = *(struct disklabel *)(lbuf + LABELOFFSET);
	if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
		return (EUNLAB);
	}
	if ((u_int)io->i_part >= lp->d_npartitions ||
	    (io->i_boff = lp->d_partitions[io->i_part].p_offset) == -1)
		return (EPART);
	return (0);
}

vmbstrategy(io, func)
	register struct iob *io;
	int func;
{
	register int qiostat;

	qiostat = qioentry(io->i_ma, io->i_cc, io->i_bn,
				(func==READ) ? IO$_READLBLK : IO$_WRITELBLK,
				PHYSMODE, vmb_info->rpbbas);
	if (qiostat & 1)
        	return (io->i_cc);
	else {
		printf("VMB %s error: bn = %d, ",
			(func==READ) ? "read" : "write", io->i_bn);
		vmberr(qiostat);
		io->i_error = EIO;
		return (-1);
	}
}
