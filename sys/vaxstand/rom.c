/*
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)rom.c	7.1 (Berkeley) 2/7/04
 */

/*
 * 750-style boot ROM interface device driver
 */

#include "param.h"
#include "inode.h"
#include "buf.h"
#include "fs.h"
#include "disklabel.h"

#include "saio.h"
#include "savax.h"

#define	SECTSIZ 	512	/* sector size in bytes */
char	lbuf[SECTSIZ];

romopen(io)
	register struct iob *io;
{
	register struct disklabel *lp;
	struct iob tio;

	tio = *io;
	tio.i_bn = LABELSECTOR;
	tio.i_ma = lbuf;
	tio.i_cc = SECTSIZ;
	tio.i_flgs |= F_RDDATA;
	if (romstrategy(&tio, READ) != SECTSIZ)
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

romstrategy(io, func)
	register struct iob *io;
	int func;
{
	register int i, off, romstat;

	for (i = 0, off = 0; off < io->i_cc; i++, off += SECTSIZ) {
		romstat = romio(0, 0, io->i_bn + i, SECTSIZ, io->i_ma + off);
		if (romstat & 1)
			continue;
		else {
			printf("ROM read error: bn = %d, ROM error code %x\n",
				io->i_bn + i, romstat);
			io->i_error = EIO;
			return (-1);
		}
	}
}
