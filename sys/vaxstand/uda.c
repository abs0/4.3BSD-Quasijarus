/*
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)uda.c	7.16 (Berkeley) 11/24/03
 */

/*
 * UDA50/RAxx disk device driver
 */

#include "param.h"
#include "inode.h"
#include "buf.h"
#include "fs.h"
#include "disklabel.h"

#include "../vax/pte.h"

#include "saio.h"
#include "savax.h"

/*
 * Unused, but needed in udareg.h
 */
#define NRSP	1
#define NCMD	1

#include "../vaxuba/udareg.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
#include "../vax/mscp.h"

#define	NRA		8	/* max. unit number on controller */
#define	SECTSIZ 	512	/* sector size in bytes */

#define	MAXCTLR		1		/* all addresses must be specified */
u_short udastd[MAXCTLR] = { 0772150 };

struct udadevice *udaddr[MAXNUBA][MAXCTLR];

struct	uda1 {
	struct	uda1ca uda1_ca;	/* communications area */
	struct	mscp uda1_rsp;	/* response packet */
	struct	mscp uda1_cmd;	/* command packet */
} uda1;

				/* Unibus address of uda structure */
struct	uda1 *ud_ubaddr[MAXNUBA][MAXCTLR];
struct	disklabel ralabel[MAXNUBA][MAXCTLR][NRA];
static	u_long ramedia[MAXNUBA][MAXCTLR][NRA];
char	lbuf[SECTSIZ];

raopen(io)
	register struct iob *io;
{
	register struct disklabel *lp;
	register struct udadevice *addr;
	register struct uda1 *ubaaddr;
	register int uba, unit;
	static int udainit[MAXNUBA][MAXCTLR];
	struct iob tio;

	if ((u_int)(uba = io->i_adapt) >= nuba)
		return (EADAPT);
	if ((u_int)io->i_ctlr >= MAXCTLR)
		return (ECTLR);
	if ((u_int)(unit = io->i_unit) >= NRA)
		return (EUNIT);
	addr = udaddr[uba][io->i_ctlr] =
	    (struct udadevice *)ubamem(uba, udastd[io->i_ctlr]);
	if (badaddr((char *)addr, sizeof(short)))
		return (ENXIO);
	if ((ubaaddr = ud_ubaddr[uba][io->i_ctlr]) == 0) {
		tio = *io;
		tio.i_ma = (caddr_t)&uda1;
		tio.i_cc = sizeof(uda1);
		ud_ubaddr[uba][io->i_ctlr] = ubaaddr =
		    (struct uda1 *)ubasetup(&tio, 2);
	}
	if (udainit[uba][io->i_ctlr] == 0) {
		addr->udaip = 0;
		while ((addr->udasa & UDA_STEP1) == 0);
		addr->udasa = UDA_ERR;
		while ((addr->udasa & UDA_STEP2) == 0);
		addr->udasa = (int)&ubaaddr->uda1_ca.ca_rspdsc;
		while ((addr->udasa & UDA_STEP3) == 0);
		addr->udasa = (int)&ubaaddr->uda1_ca.ca_rspdsc >> 16;
		while ((addr->udasa & UDA_STEP4) == 0);
		addr->udasa = UDA_GO;
		uda1.uda1_ca.ca_rspdsc = (long)&ubaaddr->uda1_rsp.mscp_cmdref;
		uda1.uda1_ca.ca_cmddsc = (long)&ubaaddr->uda1_cmd.mscp_cmdref;
		/* uda1.uda1_cmd.mscp_cntflgs = 0; */
		if (udcmd(M_OP_SETCTLRC, io)) {
			printf("ra: open error, SETCTLRC\n");
			return (ENXIO);
		}
		udainit[uba][io->i_ctlr] = 1;
	}
	lp = &ralabel[uba][io->i_ctlr][unit];
	if (ramedia[uba][io->i_ctlr][unit] == 0) {
		uda1.uda1_cmd.mscp_unit = unit;
		if (udcmd(M_OP_ONLINE, io)) {
			printf("ra: open error, ONLINE\n");
			return (ENXIO);
		}
		ramedia[uba][io->i_ctlr][unit] =
		    uda1.uda1_rsp.mscp_onle.onle_mediaid;
		tio = *io;
		tio.i_bn = LABELSECTOR;
		tio.i_ma = lbuf;
		tio.i_cc = SECTSIZ;
		tio.i_flgs |= F_RDDATA;
		if (rastrategy(&tio, READ) != SECTSIZ)
			return (ERDLAB);
		*lp = *(struct disklabel *)(lbuf + LABELOFFSET);
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
#ifdef COMPAT_42
			printf("ra%d: unlabeled\n", unit);
			ramaptype(io, lp);
#else
			return (EUNLAB);
#endif
		}
	}
	if ((u_int)io->i_part >= lp->d_npartitions ||
	    (io->i_boff = lp->d_partitions[io->i_part].p_offset) == -1)
		return (EPART);
	return (0);
}

int
udcmd(op, io)
	int op;
	register struct iob *io;
{
	register struct uda1 *u = &uda1;
	register struct mscp *mp;
	register int i;

	u->uda1_cmd.mscp_opcode = op;
	u->uda1_cmd.mscp_msglen = MSCP_MSGLEN;
	u->uda1_rsp.mscp_msglen = MSCP_MSGLEN;
	u->uda1_ca.ca_rspdsc |= MSCP_OWN|MSCP_INT;
	u->uda1_ca.ca_cmddsc |= MSCP_OWN|MSCP_INT;
	i = udaddr[io->i_adapt][io->i_ctlr]->udaip;	/* start uda polling */
#ifdef lint
	i = i;
#endif
	mp = &u->uda1_rsp;
	for (;;) {
		if (u->uda1_ca.ca_cmdint)
			u->uda1_ca.ca_cmdint = 0;
		if (u->uda1_ca.ca_rspdsc & MSCP_OWN)
			continue;
		u->uda1_ca.ca_rspint = 0;
		if (mp->mscp_opcode == (op | M_OP_END))
			break;
		printf("unexpected rsp type %x op %x ignored\n",
			MSCP_MSGTYPE(mp->mscp_msgtc), mp->mscp_opcode);
		u->uda1_ca.ca_rspdsc |= MSCP_OWN | MSCP_INT;
	}
	if ((mp->mscp_status&M_ST_MASK) != M_ST_SUCCESS)
		return (-1);
	return (0);
}

rastrategy(io, func)
	register struct iob *io;
	int func;
{
	register struct mscp *mp;
	register int ubinfo;

	ubinfo = ubasetup(io, 1);
	mp = &uda1.uda1_cmd;
	mp->mscp_unit = io->i_unit;
	mp->mscp_seq.seq_lbn = io->i_bn;
	mp->mscp_seq.seq_bytecount = io->i_cc;
	mp->mscp_seq.seq_buffer = UBAI_ADDR(ubinfo) | (UBAI_BDP(ubinfo) << 24);
	if (udcmd(func == READ ? M_OP_READ : M_OP_WRITE, io)) {
		printf("ra: I/O error\n");
		ubafree(io, ubinfo);
		return (-1);
	}
	ubafree(io, ubinfo);
	return (io->i_cc);
}

#ifdef COMPAT_42
u_long rc25_off[] = { 0, 15884, 0, -1, -1, -1, 25916, -1 };
u_long rx50_off[] = { 0, -1, 0, -1, -1, -1, -1, -1 };
u_long rd52_off[] = { 0, 15884, 0, -1, -1, -1, 25650, -1 };
u_long rd53_off[] = { 0, 15884, 0, -1, 0, 33440, 49324, 15884 };
u_long rd54_off[] = { 0, 16065, 0, 49725, 65790, 121890, 49725, -1 };
u_long ra60_off[] = { 0, 15884, 0, 49324, 131404, 49324, 242606, 49324 };
u_long ra70_off[] = { 0, 15972, 0, 341220, 357192, 413457, 341220, 49731 };
u_long ra71_off[] = { 0, 16422, 0, 375564, 391986, 699720, 375564, 83538 };
u_long ra72_off[] = { 0, 16320, 0, 375360, 391680, 699720, 375360, 83640 };
u_long ra73_off[] = { 0, 33810, 0, 458640, 590940, 2229990, 458640, 166110 };
u_long ra80_off[] = { 0, 15884, 0, -1, 49324, 49324, 49910, 131404 };
#ifndef	UCBRA
#ifdef RA_COMPAT
u_long ra81_off[] = { 0, 16422, 0, 49324, 131404, 412490, 375564, 83538 };
#else
#define ra81_off ra71_off
#endif
#else
u_long ra81_off[] = { 0, 15884, 0, 242606, 258490, 565690, 242606, 49324 };
#endif
u_long ra82_off[] = { 0, 16245, 0, 375345, 391590, 699390, 375345, 83790 };
u_long ra90_off[] = { 0, 16146, 0, 374946, 391092, 698763, 374946, 83421 };
#define ra92_off ra90_off
u_long rf30_off[] = { 0, 15984, 0, 49506, 65490, 121434, 49506, -1 };
u_long rf31_off[] = { 0, 16000, 0, 374800, 390800, 698000, 374800, 83200 };
u_long rf35_off[] = { 0, 15960, 0, 375060, 391020, 698250, 375060, 82992 };
u_long rf36_off[] = { 0, 32768, 0, 455186, 586258, 2224658, 455186, 163840 };
u_long rf71_off[] = { 0, 15984, 0, 374736, 390720, 697968, 374736, 82880 };
u_long rf72_off[] = { 0, 16800, 0, 375900, 392700, 700350, 375900, 84000 };
#define rf73_off ra73_off
u_long rf74_off[] = { 0, 32768, 0, 455186, 586258, 3863058, 455186, 163840 };

struct mediamap {
	u_long	id;		/* media ID */
	u_long	*off;		/* offsets */
} ra_map[] = {
	{ MSCP_MKDRIVE2('R', 'A', 60),		ra60_off },
	{ MSCP_MKDRIVE2('R', 'A', 70),		ra70_off },
	{ MSCP_MKDRIVE2('R', 'A', 71),		ra71_off },
	{ MSCP_MKDRIVE2('R', 'A', 72),		ra72_off },
	{ MSCP_MKDRIVE2('R', 'A', 73),		ra73_off },
	{ MSCP_MKDRIVE2('R', 'A', 80),		ra80_off },
	{ MSCP_MKDRIVE2('R', 'A', 81),		ra81_off },
	{ MSCP_MKDRIVE2('R', 'A', 82),		ra82_off },
	{ MSCP_MKDRIVE2('R', 'A', 90),		ra90_off },
	{ MSCP_MKDRIVE2('R', 'A', 92),		ra92_off },
	{ MSCP_MKDRIVE2('R', 'F', 30),		rf30_off },
	{ MSCP_MKDRIVE2('R', 'F', 31),		rf31_off },
	{ MSCP_MKDRIVE2('R', 'F', 35),		rf35_off },
	{ MSCP_MKDRIVE2('R', 'F', 36),		rf36_off },
	{ MSCP_MKDRIVE2('R', 'F', 71),		rf71_off },
	{ MSCP_MKDRIVE2('R', 'F', 72),		rf72_off },
	{ MSCP_MKDRIVE2('R', 'F', 73),		rf73_off },
	{ MSCP_MKDRIVE2('R', 'F', 74),		rf74_off },
	{ MSCP_MKDRIVE2('R', 'C', 25),		rc25_off },
	{ MSCP_MKDRIVE3('R', 'C', 'F', 25),	rc25_off },
	{ MSCP_MKDRIVE2('R', 'D', 52),		rd52_off },
	{ MSCP_MKDRIVE2('R', 'D', 53),		rd53_off },
	{ MSCP_MKDRIVE2('R', 'D', 54),		rd54_off },
	{ MSCP_MKDRIVE2('R', 'X', 50),		rx50_off },
	0
};

ramaptype(io, lp)
	register struct iob *io;
	register struct disklabel *lp;
{
	register struct partition *pp;
	register u_long i;
	register struct mediamap *map;

	i = MSCP_MEDIA_DRIVE(ramedia[io->i_adapt][io->i_ctlr][io->i_unit]);
	for (map = ra_map; map->id != 0; map++) {
		if (map->id == i) {
			lp->d_npartitions = 8;
			for (pp = lp->d_partitions, i = 0; i < 8; pp++, i++)
				pp->p_offset = map->off[i];
			return;
		}
	}
	printf("ra%d: media type 0x%x unsupported\n", io->i_unit, i);
	lp->d_npartitions = 0;
}
#endif
