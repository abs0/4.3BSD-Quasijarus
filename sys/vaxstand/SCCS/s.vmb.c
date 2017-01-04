h27055
s 00002/00002/00072
d D 7.3 04/07/01 20:15:42 msokolov 3 2
c QIO arguments in the wrong order
e
s 00003/00003/00071
d D 7.2 04/02/07 17:14:48 msokolov 2 1
c oops, can't use sprintf
e
s 00074/00000/00000
d D 7.1 04/02/07 16:20:32 msokolov 1 0
c date and time created 04/02/07 16:20:32 by msokolov
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

D 3
	qiostat = qioentry(vmb_info->rpbbas, PHYSMODE,
E 3
I 3
	qiostat = qioentry(io->i_ma, io->i_cc, io->i_bn,
E 3
				(func==READ) ? IO$_READLBLK : IO$_WRITELBLK,
D 3
				io->i_bn, io->i_cc, io->i_ma);
E 3
I 3
				PHYSMODE, vmb_info->rpbbas);
E 3
	if (qiostat & 1)
        	return (io->i_cc);
	else {
D 2
		printf("VMB %s error: bn = %d, %s\n",
			(func==READ) ? "read" : "write", io->i_bn,
			vmberr(qiostat));
E 2
I 2
		printf("VMB %s error: bn = %d, ",
			(func==READ) ? "read" : "write", io->i_bn);
		vmberr(qiostat);
E 2
		io->i_error = EIO;
		return (-1);
	}
}
E 1
