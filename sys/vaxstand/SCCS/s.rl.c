h32201
s 00004/00002/00221
d D 7.6 88/07/09 14:40:01 karels 11 10
c check adaptor numbers against actual number
e
s 00005/00005/00218
d D 7.5 88/07/08 15:01:14 bostic 10 9
c don't redefine ubaddr
e
s 00001/00003/00222
d D 7.4 88/02/24 11:00:43 bostic 9 8
c default to dev error, doesn't tell you anything new
e
s 00029/00036/00196
d D 7.3 88/02/23 15:53:33 bostic 8 6
c change to dev(a,b,c,d) format
e
s 00030/00035/00197
d R 7.3 88/02/22 12:59:04 bostic 7 6
c change to dev(a,b,c,d) format
e
s 00021/00011/00211
d D 7.2 88/01/28 20:53:16 karels 6 5
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00221
d D 7.1 86/06/05 01:44:40 mckusick 5 4
c 4.3BSD release version
e
s 00007/00001/00215
d D 6.2 85/06/08 13:11:13 mckusick 4 3
c Add copyright
e
s 00000/00000/00216
d D 6.1 83/07/29 07:47:32 sam 3 2
c 4.2 distribution
e
s 00009/00000/00207
d D 4.2 83/02/16 23:45:02 sam 2 1
c uda50 and rl11 boot blocks; 730 crud
e
s 00207/00000/00000
d D 4.1 83/02/08 23:21:55 sam 1 0
c date and time created 83/02/08 23:21:55 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
D 11
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 11
E 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

/*
 * Standalone RL02 disk driver
 */
D 11
#include "../machine/pte.h"
E 11

D 6
#include "../h/param.h"
#include "../h/inode.h"
#include "../h/fs.h"
E 6
I 6
#include "param.h"
#include "inode.h"
#include "fs.h"
E 6

I 11
#include "../vax/pte.h"
E 11
#include "../vaxuba/rlreg.h"
#include "../vaxuba/ubareg.h"

#include "saio.h"
#include "savax.h"

D 8
u_short	rlstd[] = { 0774400 };
E 8
I 8
#define	MAXPART		8
#define	MAXCTLR		1		/* all addresses must be specified */
u_short	rlstd[MAXCTLR] = { 0774400 };
E 8
short	rl_off[] = { 0, 361, 0, -1, -1, -1, -1, -1 };

/* struct to keep state info about the controller */
struct	rl_stat {
	short	rl_dn;		/* drive number */
	short	rl_cylnhd;	/* cylinder and head */
	u_short	rl_bleft;	/* bytes left to transfer */
	u_short	rl_bpart;	/* bytes transferred */
D 8
} rl_stat[] = { -1, 0, 0, 0};
E 8
I 8
} rl_stat[MAXCTLR] = { -1, 0, 0, 0 };
E 8

rlopen(io)
	register struct iob *io;
{
D 8
	register struct rldevice *rladdr =
		(struct rldevice *)ubamem(io->i_unit, rlstd[0]);
	register struct rl_stat *st = &rl_stat[0];
E 8
I 8
	register struct rldevice *rladdr;
	register struct rl_stat *st;
E 8
	register int ctr = 0;

I 11
	if ((u_int)io->i_adapt >= nuba)
		return (EADAPT);
E 11
I 8
	if ((u_int)io->i_ctlr >= MAXCTLR)
		return (ECTLR);
	rladdr = (struct rldevice *)ubamem(io->i_adapt, rlstd[io->i_ctlr]);
E 8
D 6
	if (rl_off[io->i_boff] == -1 ||
	    io->i_boff < 0 || io->i_boff > 7)
		_stop("rl bad unit");
E 6
I 6
D 9
	if (badaddr((char *)rladdr, sizeof(short))) {
D 8
		printf("nonexistent device\n");
E 8
I 8
		printf("rl: nonexistent device\n");
E 9
I 9
	if (badaddr((char *)rladdr, sizeof(short)))
E 9
E 8
		return (ENXIO);
D 9
	}
E 9
D 8
	if ((unsigned)io->i_boff > 7 || rl_off[io->i_boff] == -1) {
		printf("rl bad unit\n");
		return (EUNIT);
	}
E 8
I 8
	if ((u_int)io->i_part >= MAXPART || rl_off[io->i_part] == -1)
		return (EPART);
E 8
E 6

	/*
	 * DEC reports that:
	 * For some unknown reason the RL02 (seems to be only drive 1)
	 * does not return a valid drive status the first time that a
	 * GET STATUS request is issued for the drive, in fact it can
	 * take up to three or more GET STATUS requests to obtain the
	 * correct status.
	 * In order to overcome this, the driver has been modified to
	 * issue a GET STATUS request and validate the drive status
	 * returned.  If a valid status is not returned after eight
	 * attempts, then an error message is printed.
	 */
	do {
		rladdr->rlda.getstat = RL_RESET;
		rladdr->rlcs = (io->i_unit <<8) | RL_GETSTAT; /* Get status*/
		rlwait(rladdr);
D 6
	} while( (rladdr->rlmp.getstat&RLMP_STATUS) != RLMP_STATOK && ++ctr<8 );
E 6
I 6
	} while ((rladdr->rlmp.getstat&RLMP_STATUS) != RLMP_STATOK && ++ctr<8);
E 6

D 6
	if ((rladdr->rlcs & RL_DE) || (ctr >= 8))
		_stop("rl unit does not respond");
E 6
I 6
	if ((rladdr->rlcs & RL_DE) || (ctr >= 8)) {
D 8
		printf("rl unit does not respond\n");
E 8
I 8
		printf("rl: unit does not respond\n");
E 8
		return (EUNIT);
	}
E 6

D 6
	if ((rladdr->rlmp.getstat & RLMP_DT) == 0 )	/* NO RL01'S */
		_stop("rl01 unit not supported");
E 6
I 6
	if ((rladdr->rlmp.getstat & RLMP_DT) == 0) {	/* NO RL01'S */
		printf("rl01 unit not supported\n");
D 8
		return (EUNIT);
E 8
I 8
		return (ENXIO);
E 8
	}
E 6

	/* Determine disk posistion */
	rladdr->rlcs = (io->i_unit << 8) | RL_RHDR;
	rlwait(rladdr);

	/* save disk drive posistion */
I 8
	st = &rl_stat[io->i_ctlr];
E 8
	st->rl_cylnhd = (rladdr->rlmp.readhdr & 0177700) >> 6;
	st->rl_dn = io->i_unit;

	/* byte offset for cylinder desired */
D 8
	io->i_boff = rl_off[io->i_boff] * NRLBPSC * NRLTRKS * NRLSECT;
E 8
I 8
	io->i_boff = rl_off[io->i_part] * NRLBPSC * NRLTRKS * NRLSECT;
E 8
I 6
	return (0);
E 6
}

rlstrategy(io, func)
	register struct iob *io;
{
D 8
	register struct rldevice *rladdr =
		(struct rldevice *)ubamem(io->i_unit, rlstd[0]);
	register struct rl_stat *st = &rl_stat[0];
E 8
I 8
	register struct rldevice *rladdr;
	register struct rl_stat *st;
E 8
	int com;
	daddr_t bn;
	short cn, sn, head;
D 10
	int diff, ubinfo, ubaddr, errcnt = 0;
E 10
I 10
	int diff, ubinfo, ubaaddr, errcnt = 0;
E 10

I 8
	rladdr = (struct rldevice *)ubamem(io->i_adapt, rlstd[io->i_ctlr]);
	st = &rl_stat[io->i_ctlr];
E 8
retry:
	ubinfo = ubasetup(io, 1);
	bn = io->i_bn;		/* block number */
	cn = bn / 40;		/* 40 512 byte blocks per cylinder */
	sn = (bn % 20) << 1;
	head = (bn / 20) & 1;
	st->rl_bleft = io->i_cc;	/* total number of bytes to trans */
D 10
	ubaddr = ubinfo;
E 10
I 10
	ubaaddr = ubinfo;
E 10

stupid_rl:
	/* find out how many cylinders to seek */
	diff = (st->rl_cylnhd >> 1) - cn;
D 8
	if ( diff == 0 && (st->rl_cylnhd & 1) == head )
E 8
I 8
	if (diff == 0 && (st->rl_cylnhd & 1) == head)
E 8
		goto noseek;

	/* first time or we switched drives */
	st->rl_dn = io->i_unit;	/* drive number */

D 8
	if ( diff < 0 )
E 8
I 8
	if (diff < 0)
E 8
		rladdr->rlda.seek = -diff<<7 | RLDA_HGH | head << 4;
	else
		rladdr->rlda.seek = diff<<7 | RLDA_LOW | head << 4;
	rladdr->rlcs = (st->rl_dn << 8) | RL_SEEK;

	/* reset position of drive */
	st->rl_cylnhd = (cn << 1) | head;

noseek:
	/* wait for controller and drive */
	while( (rladdr->rlcs & RL_DCRDY) != RL_DCRDY)
		continue;

	/* calculate the max number of bytes we can trans */
	st->rl_bpart = NRLSECT * NRLBPSC - (sn * NRLBPSC);
D 8
	if ( st->rl_bleft < st->rl_bpart )
E 8
I 8
	if (st->rl_bleft < st->rl_bpart)
E 8
		st->rl_bpart = st->rl_bleft;

	rladdr->rlda.rw = (st->rl_cylnhd << 6) | sn;
	rladdr->rlmp.rw = -(st->rl_bpart >> 1);
D 10
	rladdr->rlba = ubaddr;
E 10
I 10
	rladdr->rlba = ubaaddr;
E 10

D 10
	com = (st->rl_dn << 8) | ((ubaddr>>12)&RL_BAE);
E 10
I 10
	com = (st->rl_dn << 8) | ((ubaaddr>>12)&RL_BAE);
E 10

	if (func == READ)
		com |= RL_READ;
	else
		com |= RL_WRITE;
	rladdr->rlcs = com;

	/* wait for controller and drive */
	while( (rladdr->rlcs & RL_DCRDY) != RL_DCRDY)
		continue;

	if (rladdr->rlcs & RL_ERR) {
		int status;

D 8
		if ( rladdr->rlcs & RL_DE ) {
E 8
I 8
		if (rladdr->rlcs & RL_DE) {
E 8
			rladdr->rlda.getstat = RL_GSTAT;
			rladdr->rlcs = (st->rl_dn << 8) | RL_GETSTAT;
			rlwait(rladdr);
			status = rladdr->rlmp.getstat;
			rladdr->rlda.getstat = RL_RESET;
			rladdr->rlcs = (st->rl_dn <<8) | RL_GETSTAT;
			rlwait(rladdr);
		}
		printf("rl error: (cyl,head,sec)=(%d,%d,%d) cs=%b mp=%b\n",
		    cn, head, sn, rladdr->rlcs & 0xffff, RLCS_BITS,
		    status, RLER_BITS);

		/* Determine disk posistion */
		rladdr->rlcs = (st->rl_dn << 8) | RL_RHDR;
		rlwait(rladdr);

		/* save disk drive posistion */
		st->rl_cylnhd = (rladdr->rlmp.readhdr & 0177700) >> 6;

D 8
		if (errcnt == 10) {
E 8
I 8
		if (errcnt++ == 10) {
E 8
			printf("rl: unrecovered error\n");
			return (-1);
		}
D 8
		errcnt++;
E 8
		goto retry;
	}

	/* do we have to finish off the rest of the transfer? */
D 8
	if ( (st->rl_bleft -= st->rl_bpart) > 0 ) {
E 8
I 8
	if ((st->rl_bleft -= st->rl_bpart) > 0) {
E 8
		/* increment head and/or cylinder */
D 8
		if ( ++head > 1 ) {
E 8
I 8
		if (++head > 1) {
E 8
			cn++;		/* want next cyl, head 0 sector 0 */
			head = 0;
		}

		/* we always want sector to be zero */
		sn = 0;

		/*
		 * standalone code for ubafree does what regular
		 *   ubapurge does and we want to purge last transfer
		 */
		ubafree(io, ubinfo);

D 10
		ubaddr = ubinfo + io->i_cc - st->rl_bleft;
E 10
I 10
		ubaaddr = ubinfo + io->i_cc - st->rl_bleft;
E 10

		goto stupid_rl;
	}

	ubafree(io, ubinfo);

	if (errcnt)
		printf("rl: recovered by retry\n");
	return (io->i_cc);
}

I 8
static
E 8
rlwait(rladdr)
	register struct rldevice *rladdr;
{
D 8

	while ((rladdr->rlcs & RL_CRDY) == 0)
		continue;
}
I 2

rlioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{

	return (ECMD);
E 8
I 8
	while ((rladdr->rlcs & RL_CRDY) == 0);
E 8
}
E 2
E 1
