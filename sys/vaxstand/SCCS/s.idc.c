h01687
s 00003/00003/00141
d D 7.4 88/07/09 14:39:56 karels 16 15
c check adaptor numbers against actual number
e
s 00019/00029/00125
d D 7.3 88/02/22 12:56:30 bostic 15 13
c change to dev(a,b,c,d) format; remove idcioctl()
e
s 00020/00030/00124
d R 7.3 88/02/22 12:55:53 bostic 14 13
c change to dev(a,b,c,d) format; remove idcioctl
e
s 00013/00008/00141
d D 7.2 88/01/28 20:53:03 karels 13 12
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00148
d D 7.1 86/06/05 01:43:05 mckusick 12 11
c 4.3BSD release version
e
s 00007/00001/00142
d D 6.3 85/06/08 13:09:17 mckusick 11 10
c Add copyright
e
s 00004/00005/00139
d D 6.2 83/12/13 13:48:44 karels 10 9
c boff is in blocks, and is added elsewhere.
e
s 00000/00000/00144
d D 6.1 83/07/29 07:47:13 sam 9 8
c 4.2 distribution
e
s 00001/00001/00143
d D 4.7 83/04/30 17:29:25 edward 8 6
c fixed rl02 sector size bug
e
s 00001/00001/00143
d R 4.7 83/04/30 17:14:33 root 7 6
c fixed rl02 sector size bug
e
s 00010/00000/00134
d D 4.6 82/12/30 15:32:39 sam 6 5
c add ioctl's and errno
e
s 00001/00001/00133
d D 4.5 82/12/17 17:00:38 sam 5 4
c pte.h is now in ../machine/
e
s 00018/00017/00116
d D 4.4 82/11/19 12:22:15 feldman 4 3
c handle arbitrary transfer sizes, multiple track transfers
e
s 00004/00002/00129
d D 4.3 82/11/13 23:14:45 sam 3 2
c move includes for 4.1c directory layout
e
s 00001/00000/00130
d D 4.2 82/07/15 21:31:13 root 2 1
c new boot scheme
e
s 00130/00000/00000
d D 4.1 82/05/27 17:07:54 sam 1 0
c date and time created 82/05/27 17:07:54 by sam
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 12
 * Copyright (c) 1982 Regents of the University of California.
E 12
I 12
D 16
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 16
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11

/*
 * IDC (RB730)
D 4
 *
 * This driver is full of kludges!
 * It depends heavily on the 1K file system.
E 4
 */
I 5
D 16
#include "../machine/pte.h"
E 16
E 5

D 13
#include "../h/param.h"
D 3
#include "../h/idcreg.h"
E 3
#include "../h/inode.h"
D 5
#include "../h/pte.h"
E 5
D 3
#include "../h/ubareg.h"
E 3
I 2
#include "../h/fs.h"
E 13
I 13
#include "param.h"
#include "inode.h"
#include "fs.h"
E 13
I 3

I 16
#include "../vax/pte.h"
E 16
#include "../vaxuba/idcreg.h"
#include "../vaxuba/ubareg.h"

E 3
E 2
#include "saio.h"
#include "savax.h"

D 15
u_short	idcstd[] = { 0175606 };
E 15
short	rb02_off[] = { 0, 400, 0, -1, -1, -1, -1, -1 };
short	rb80_off[] = { 0, 37, 0, -1, -1, -1, 115, 305 };

D 15
int idc_type[4];
E 15
I 15
#define	MAXCTLR		1
#define	MAXUNIT		4
#define	MAXPART		8
E 15

I 15
int	idc_type[MAXUNIT];

E 15
idcopen(io)
	register struct iob *io;
{
	register struct idcdevice *idcaddr;
	register int i;

D 15
	idcaddr = (struct idcdevice *)((caddr_t)ubauba(io->i_unit) + 0x200);
D 13
	if (io->i_boff < 0 || io->i_boff > 7)
		_stop("idc bad unit");
E 13
I 13
	if ((unsigned)io->i_boff > 7) {
		printf("idc bad unit");
E 15
I 15
D 16
	if ((u_int)io->i_adapt >= MAXNUBA)
E 16
I 16
	if (io->i_adapt != 0)
E 16
		return (EADAPT);
	if ((u_int)io->i_ctlr >= MAXCTLR)
		return (ECTLR);
	if ((u_int)io->i_unit >= MAXUNIT)
E 15
		return (EUNIT);
D 15
	}
E 15
I 15
	if ((u_int)io->i_part >= MAXPART)
		return (EPART);
	idcaddr = (struct idcdevice *)((caddr_t)ubauba(io->i_adapt) + 0x200);
E 15
E 13
	idcaddr->idcmpr = IDCGS_GETSTAT;
	idcaddr->idccsr = IDC_GETSTAT|(io->i_unit<<8);
	idcwait(idcaddr);
	i = idcaddr->idcmpr;
	idcaddr->idccsr = IDC_CRDY|(1<<(io->i_unit+16));
	idcwait(idcaddr);
	idcaddr->idccsr = (io->i_unit<<8)|IDC_RHDR;
	idcwait(idcaddr);
	if (idcaddr->idccsr & IDC_ERR) {
		printf("idc error: idccsr %x\n", idcaddr->idccsr);
D 13
		_stop("idc fatal error");
E 13
I 13
		return (EIO);
E 13
	}
	i = idcaddr->idcmpr;
	i = idcaddr->idcmpr;
	if (idcaddr->idccsr & IDC_R80) {
		idc_type[io->i_unit] = 1;
D 10
		io->i_boff = rb80_off[io->i_boff];
E 10
I 10
D 15
		io->i_boff = rb80_off[io->i_boff] * NRB80SECT * NRB80TRK;
E 15
I 15
		io->i_boff = rb80_off[io->i_part] * NRB80SECT * NRB80TRK;
E 15
E 10
	} else {
		idc_type[io->i_unit] = 0;
D 10
		io->i_boff = rb02_off[io->i_boff];
E 10
I 10
D 15
		io->i_boff = rb02_off[io->i_boff] * NRB02SECT/2 * NRB02TRK;
E 15
I 15
		io->i_boff = rb02_off[io->i_part] * NRB02SECT/2 * NRB02TRK;
E 15
E 10
	}
D 13
	if (io->i_boff < 0)
D 4
		_stop("idc bad unit");
E 4
I 4
		_stop("idc%d: bad unit type", io->i_unit);
E 13
I 13
D 15
	if (io->i_boff < 0) {
		printf("idc%d: bad unit type", io->i_unit);
		return (EUNIT);
	}
E 15
	return (0);
E 13
E 4
}

idcstrategy(io, func)
	register struct iob *io;
{
	register struct idcdevice *idcaddr;
	int com;
	daddr_t bn;
	short dn, cn, sn, tn;
I 4
	short ccleft, thiscc = 0;
E 4
	int ubinfo, errcnt = 0;

D 15
	idcaddr = (struct idcdevice *)((caddr_t)ubauba(io->i_unit) + 0x200);
E 15
I 15
	idcaddr = (struct idcdevice *)((caddr_t)ubauba(io->i_adapt) + 0x200);
E 15
D 4
retry:
E 4
	ubinfo = ubasetup(io, 1);
	bn = io->i_bn;
I 4
	ccleft = io->i_cc;
retry:
E 4
	dn = io->i_unit;
D 4
	if (io->i_cc != 1024) printf("idc: count %d != 1024\n", io->i_cc);
E 4
	if (idc_type[dn]) {
		cn = bn/(NRB80SECT*NRB80TRK);
		sn = bn%NRB80SECT;
		tn = (bn / NRB80SECT) % NRB80TRK;
D 4
		if (sn == NRB80SECT)
			io->i_cc = 512;
E 4
I 4
		thiscc = (NRB80SECT - sn) * 512;
E 4
	} else {
D 4
		bn *= 2;
		cn = bn/(NRB02SECT*NRB02TRK);
		sn = bn%NRB02SECT;
		tn = (bn / NRB02SECT) % NRB02TRK;
E 4
I 4
		cn = 2*bn/(NRB02SECT*NRB02TRK);
		sn = (2*bn)%NRB02SECT;
		tn = (2*bn / NRB02SECT) % NRB02TRK;
		thiscc = (NRB02SECT - sn) * 256;
E 4
	}
I 4
	thiscc = MIN(thiscc, ccleft);
	ccleft -= thiscc;
E 4
D 10
	cn += io->i_boff;
E 10
	idcaddr->idccsr = IDC_CRDY|IDC_SEEK|(dn<<8)|(1<<(dn+16));
	idcaddr->idcdar = (cn<<16)|(tn<<8)|sn;
	idcaddr->idccsr = IDC_SEEK|(dn<<8);
	idcwait(idcaddr);
	idcaddr->idccsr &= ~IDC_ATTN;
	com = dn<<8;
	if (func == READ)
		com |= IDC_READ;
	else
		com |= IDC_WRITE;
	idcaddr->idccsr = IDC_CRDY|com;
	idcaddr->idcbar = ubinfo&0x3ffff;
D 4
	idcaddr->idcbcr = -io->i_cc;
E 4
I 4
	idcaddr->idcbcr = -thiscc;
E 4
	idcaddr->idcdar = (cn<<16)|(tn<<8)|sn;
	idcaddr->idccsr = com;
	idcwait(idcaddr);
D 4
	ubafree(io, ubinfo);
E 4
	if (idcaddr->idccsr & IDC_ERR) {
D 10
		printf("idc error: (cyl,trk,sec)=(%d,%d,%d) csr=%b\n",
		    cn, tn, sn, idcaddr->idccsr, IDCCSR_BITS);
E 10
I 10
		printf("idc%d error: (cyl,trk,sec)=(%d,%d,%d) csr=%b\n",
		    dn, cn, tn, sn, idcaddr->idccsr, IDCCSR_BITS);
E 10
D 15
		if (errcnt == 10) {
E 15
I 15
		if (errcnt++ == 10) {
E 15
			printf("idc: unrecovered error\n");
I 4
			ubafree(io, ubinfo);
E 4
			return (-1);
		}
D 15
		errcnt++;
E 15
		goto retry;
	}
	if (errcnt)
		printf("idc: recovered by retry\n");
D 4
	if (idc_type[dn] && sn == NRB80SECT) {
		io->i_bn++;
E 4
I 4
	if (ccleft) {
D 8
		bn += thiscc/(idc_type[dn]?512:256);
E 8
I 8
		bn += thiscc/NBPG;
E 8
		ubinfo += thiscc;
E 4
		goto retry;
	}
D 4
	return (1024);
E 4
I 4
	ubafree(io, ubinfo);
	return (io->i_cc);
E 4
}

I 15
static
E 15
idcwait(idcaddr)
	register struct idcdevice *idcaddr;
{
D 15
	register int i;

E 15
	while ((idcaddr->idccsr & (IDC_CRDY|IDC_DRDY)) != (IDC_CRDY|IDC_DRDY))
D 15
		for (i = 10; i; i--)
			;
}
I 6

/*ARGSUSED*/
idcioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{

	return (ECMD);
E 15
I 15
		DELAY(10);
E 15
}
E 6
E 1
