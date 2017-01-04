h24443
s 00001/00001/00242
d D 7.7 03/11/24 02:05:09 msokolov 7 6
c new partitions for RA73
e
s 00002/00000/00241
d D 7.6 01/02/14 13:50:23 msokolov 6 5
c add RA73
e
s 00019/00003/00222
d D 7.5 99/09/04 18:02:03 msokolov 5 4
c resync the partition tables with the just updated standalone uda driver
e
s 00071/00057/00154
d D 7.4 88/07/08 15:38:28 bostic 4 3
c new version from Chris Torek
e
s 00010/00005/00201
d D 7.3 88/06/29 18:04:54 bostic 3 2
c install approved copyright notice
e
s 00014/00030/00192
d D 7.2 88/05/24 13:26:01 bostic 2 1
c change to dev(a,b,c,d) format
e
s 00222/00000/00000
d D 7.1 88/02/22 11:35:07 bostic 1 0
c date and time created 88/02/22 11:35:07 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 3
 *
 *	%W% (Berkeley) %G%
 */

/*
 * KDB50/RAxx disk device driver
 */
#include "../machine/pte.h"

#include "param.h"
#include "inode.h"
#include "fs.h"
#include "disklabel.h"

#include "saio.h"
#include "savax.h"

D 4
#define	NKRA		8	/* max unit number on ctlr */
E 4
I 4
/*
 * N.B.: on KDB50, controller == adapter
 * here we just use the controller number
 */

#define	NKRA		8	/* max drive number */
E 4
#define	SECTSIZ		512	/* sector size in bytes */

/*
D 4
 * Parameters for the communications area
E 4
I 4
 * Parameters for the communications area:
 * command and response rings both one entry.
E 4
 */
#define	NRSP	1
#define	NCMD	1

D 2
#include "../vax/bireg.h"
#include "../vax/kdbreg.h"
E 2
I 2
#include "../vaxbi/bireg.h"
#include "../vaxbi/kdbreg.h"
E 2
#include "../vax/mscp.h"

struct kdb {
	struct kdbca	kdb_ca;
	struct mscp	kdb_rsp;
	struct mscp	kdb_cmd;
} kdb;

int	kdbinit[MAXNKDB];
D 4
char	kratype[MAXNKDB * NKRA];
struct	disklabel kralabel[MAXNUBA * NKRA];
E 4
I 4
struct	disklabel kralabel[MAXNKDB][NKRA];
u_long	kramedia[MAXNKDB][NKRA];
E 4
char	lbuf[SECTSIZ];

kraopen(io)
	register struct iob *io;
{
D 4
	register struct mscp *mp;
E 4
	register struct kdb_regs *kr;
	register struct disklabel *lp;
D 4
	register int i, unit;
	daddr_t off;
E 4
I 4
	register int ctlr, unit;
	struct iob tio;
E 4

D 2
	i = io->i_unit >> 3;
	if (i >= nkdb) {
		printf("nonexistent device");
		return (ENXIO);
	}
E 2
I 2
D 4
	if ((i = io->i_unit) >= nkdb)
E 4
I 4
	if ((u_int)(ctlr = io->i_ctlr) >= nkdb)
		return (EADAPT);
	if ((u_int)(unit = io->i_unit) >= NKRA)
E 4
		return (EUNIT);
E 2
D 4
	kr = (struct kdb_regs *)kdbaddr[i];
	if (kdbinit[i] == 0) {
E 4
I 4
	kr = (struct kdb_regs *)kdbaddr[ctlr];
	if (kdbinit[ctlr] == 0) {
E 4
		kr->kdb_bi.bi_csr |= BICSR_NRST;
		DELAY(10000);	/* ??? */
		/* clear any bus errors */
		kr->kdb_bi.bi_ber = ~(BIBER_MBZ|BIBER_NMR|BIBER_UPEN);
		while ((kr->kdb_sa & KDB_STEP1) == 0)
D 4
			;
E 4
I 4
			/* void */;
E 4
		kr->kdb_bi.bi_bcicsr |= BCI_STOPEN | BCI_IDENTEN;
		kr->kdb_sw = KDB_ERR;
		while ((kr->kdb_sa & KDB_STEP2) == 0)
D 4
			;
E 4
I 4
			/* void */;
E 4
		kr->kdb_sw = (int)&kdb.kdb_ca.ca_rspdsc[0];
		while ((kr->kdb_sa & KDB_STEP3) == 0)
D 4
			;
E 4
I 4
			/* void */;
E 4
		kr->kdb_sw = (int)&kdb.kdb_ca.ca_rspdsc[0] >> 16;
		while ((kr->kdb_sa & KDB_STEP4) == 0)
D 4
			;
E 4
I 4
			/* void */;
E 4
		kr->kdb_sw = KDB_GO;
		kdb.kdb_ca.ca_rspdsc[0] = (long)&kdb.kdb_rsp.mscp_cmdref;
		kdb.kdb_ca.ca_cmddsc[0] = (long)&kdb.kdb_cmd.mscp_cmdref;
D 4
		if (kdbcmd(kr, M_OP_SETCTLRC)) {
			printf("open error, SETCTLRC");
			return (EIO);
E 4
I 4
		if (kdbcmd(M_OP_SETCTLRC, io)) {
			printf("kra: open error, SETCTLRC\n");
			return (ENXIO);
E 4
		}
D 4
		kdbinit[i] = 1;
E 4
I 4
		kdbinit[ctlr] = 1;
E 4
	}
D 4
	unit = io->i_unit;
	lp = &kralabel[unit];
	if (kratype[unit] == 0) {
		struct iob tio;

		kdb.kdb_cmd.mscp_unit = UNITTODRIVE(unit);
		if (kdbcmd(kr, M_OP_ONLINE)) {
			printf("open error, ONLINE");
			return (EIO);
E 4
I 4
	lp = &kralabel[ctlr][unit];
	if (kramedia[ctlr][unit] == 0) {
		kdb.kdb_cmd.mscp_unit = unit;
		if (kdbcmd(M_OP_ONLINE, io)) {
			printf("kra: open error, ONLINE\n");
			return (ENXIO);
E 4
		}
D 4
		kratype[unit] = kdb.kdb_rsp.mscp_onle.onle_drivetype;
E 4
I 4
		kramedia[ctlr][unit] = kdb.kdb_rsp.mscp_onle.onle_mediaid;
E 4
		tio = *io;
		tio.i_bn = LABELSECTOR;
		tio.i_ma = lbuf;
		tio.i_cc = SECTSIZ;
		tio.i_flgs |= F_RDDATA;
D 2
		if (krastrategy(&tio, READ) != SECTSIZ) {
			printf("can't read disk label\n");
			return (EIO);
		}
E 2
I 2
		if (krastrategy(&tio, READ) != SECTSIZ)
			return (ERDLAB);
E 2
		*lp = *(struct disklabel *)(lbuf + LABELOFFSET);
D 2
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
			printf("kra%d: unlabeled\n", unit);
E 2
I 2
D 4
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC)
E 4
I 4
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
E 4
E 2
#ifdef COMPAT_42
I 2
D 4
		{
E 4
			printf("kra%d: unlabeled\n", unit);
E 2
			kramaptype(io, lp);
I 2
D 4
		}
E 4
E 2
#else
D 2
			return (ENXIO);
E 2
I 2
			return (EUNLAB);
E 2
#endif
I 4
		}
E 4
D 2
		}
E 2
	}
D 2
	if ((unsigned)io->i_boff >= lp->d_npartitions ||
	    (io->i_boff = lp->d_partitions[io->i_boff].p_offset) == -1) {
		printf("kra: bad partition");
		return (EUNIT);
	}
E 2
I 2
D 4
	if ((unsigned)io->i_part >= lp->d_npartitions ||
E 4
I 4
	if ((u_int)io->i_part >= lp->d_npartitions ||
E 4
	    (io->i_boff = lp->d_partitions[io->i_part].p_offset) == -1)
		return (EPART);
E 2
	return (0);
}

D 4
kdbcmd(kr, op)
	struct kdb_regs *kr;
E 4
I 4
kdbcmd(op, io)
E 4
	int op;
I 4
	struct iob *io;
E 4
{
	register struct kdb *k = &kdb;
	register struct mscp *mp;
D 4
	int i;
E 4
I 4
	register int i;
E 4

	k->kdb_cmd.mscp_opcode = op;
	k->kdb_rsp.mscp_msglen = MSCP_MSGLEN;
	k->kdb_cmd.mscp_msglen = MSCP_MSGLEN;
	k->kdb_ca.ca_rspdsc[0] |= MSCP_OWN | MSCP_INT;
	k->kdb_ca.ca_cmddsc[0] |= MSCP_OWN | MSCP_INT;
D 4
	i = kr->kdb_ip;
E 4
I 4
	i = ((struct kdb_regs *)kdbaddr[io->i_ctlr])->kdb_ip;
#ifdef lint
	i = i;
#endif
E 4
	mp = &k->kdb_rsp;
	for (;;) {
		if (k->kdb_ca.ca_cmdint)
			k->kdb_ca.ca_cmdint = 0;
		if (k->kdb_ca.ca_rspint == 0)
			continue;
		k->kdb_ca.ca_rspint = 0;
		if (mp->mscp_opcode == (op | M_OP_END))
			break;
		printf("unexpected rsp type %x op %x ignored\n",
			MSCP_MSGTYPE(mp->mscp_msgtc), mp->mscp_opcode);
I 4
		k->kdb_ca.ca_rspdsc[0] |= MSCP_OWN | MSCP_INT;
E 4
	}
	if ((mp->mscp_status & M_ST_MASK) != M_ST_SUCCESS)
		return (-1);
	return (0);
}

krastrategy(io, func)
	register struct iob *io;
I 4
	int func;
E 4
{
	register struct mscp *mp;

	mp = &kdb.kdb_cmd;
D 4
	mp->mscp_unit = io->i_unit & 7;
E 4
I 4
	mp->mscp_unit = io->i_unit;
E 4
	mp->mscp_seq.seq_lbn = io->i_bn;
	mp->mscp_seq.seq_bytecount = io->i_cc;
	mp->mscp_seq.seq_buffer = (long)io->i_ma | KDB_PHYS;
D 4
	if (kdbcmd((struct kdb_regs *)kdbaddr[io->i_unit >> 3],
		    func == READ ? M_OP_READ : M_OP_WRITE)) {
E 4
I 4
	if (kdbcmd(func == READ ? M_OP_READ : M_OP_WRITE, io)) {
E 4
		printf("kra: I/O error\n");
		return (-1);
	}
	return (io->i_cc);
D 2
}

/*ARGSUSED*/
kraioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{

	return (ECMD);
E 2
}

#ifdef COMPAT_42
D 4
u_long kra25_off[] = { 0, 15884, 0, -1, -1, -1, 25916, -1 };
E 4
u_long kra60_off[] = { 0, 15884, 0, 49324, 131404, 49324, 242606, 49324 };
I 4
D 5
#define kra70_off kra60_off
E 5
I 5
u_long kra70_off[] = { 0, 15972, 0, 341220, 357192, 413457, 341220, 49731 };
u_long kra71_off[] = { 0, 16422, 0, 375564, 391986, 699720, 375564, 83538 };
u_long kra72_off[] = { 0, 16320, 0, 375360, 391680, 699720, 375360, 83640 };
I 6
D 7
u_long kra73_off[] = { 0, 16170, 0, 376320, 392490, 699720, 376320, 83790 };
E 7
I 7
u_long kra73_off[] = { 0, 33810, 0, 458640, 590940, 2229990, 458640, 166110 };
E 7
E 6
E 5
E 4
u_long kra80_off[] = { 0, 15884, 0, -1, 49324, 49324, 49910, 131404 };
D 5
u_long kra81_off[] = { 0, 15884, 0, 131404, 49324, 498790, 563050, 131404 };
D 4
u_long *kra_off[] = {
	0,
	kra80_off,		/* 1 = ra80 */
	kra25_off,		/* 2 = rc25-r */
	kra25_off,		/* 3 = rc25-r */
	kra60_off,		/* 4 = ra60 */
	kra81_off,		/* 5 = ra81 */
E 4
I 4
u_long kra82_off[] = { 0, 15884, 0, 375345, 391590, 699390, 375345, 83790 }; 
E 5
I 5
#ifndef	UCBRA
#ifdef RA_COMPAT
u_long kra81_off[] = { 0, 16422, 0, 49324, 131404, 412490, 375564, 83538 };
#else
#define kra81_off kra71_off
#endif
#else
u_long kra81_off[] = { 0, 15884, 0, 242606, 258490, 565690, 242606, 49324 };
#endif
u_long kra82_off[] = { 0, 16245, 0, 375345, 391590, 699390, 375345, 83790 };
u_long kra90_off[] = { 0, 16146, 0, 374946, 391092, 698763, 374946, 83421 };
#define kra92_off kra90_off
E 5

struct mediamap {
	u_long	id;		/* media ID */
	u_long	*off;		/* offsets */
} kra_map[] = {
	{ MSCP_MKDRIVE2('R', 'A', 60),		kra60_off },
	{ MSCP_MKDRIVE2('R', 'A', 70),		kra70_off },
I 5
	{ MSCP_MKDRIVE2('R', 'A', 71),		kra71_off },
	{ MSCP_MKDRIVE2('R', 'A', 72),		kra72_off },
I 6
	{ MSCP_MKDRIVE2('R', 'A', 73),		kra73_off },
E 6
E 5
	{ MSCP_MKDRIVE2('R', 'A', 80),		kra80_off },
	{ MSCP_MKDRIVE2('R', 'A', 81),		kra81_off },
	{ MSCP_MKDRIVE2('R', 'A', 82),		kra82_off },
I 5
	{ MSCP_MKDRIVE2('R', 'A', 90),		kra90_off },
	{ MSCP_MKDRIVE2('R', 'A', 92),		kra92_off },
E 5
	0
E 4
};
D 4
#define	NOFFS (sizeof(kra_off) / sizeof(kra_off[0]))
E 4

kramaptype(io, lp)
	register struct iob *io;
	register struct disklabel *lp;
{
	register struct partition *pp;
D 4
	register u_int i;
	register u_long *off;
E 4
I 4
	register u_long i;
	register struct mediamap *map;
E 4

D 4
	if ((i = kratype[io->i_unit]) >= NOFFS || (off = kra_off[i]) == 0) {
		printf("kra%d: type %d unsupported\n", io->i_unit, i);
		lp->d_npartitions = 0;
		return;
E 4
I 4
	i = MSCP_MEDIA_DRIVE(kramedia[io->i_ctlr][io->i_unit]);
	for (map = kra_map; map->id != 0; map++) {
		if (map->id == i) {
			lp->d_npartitions = 8;
			for (pp = lp->d_partitions, i = 0; i < 8; pp++, i++)
				pp->p_offset = map->off[i];
			return;
		}
E 4
	}
D 4
	lp->d_npartitions = 8;
	for (pp = lp->d_partitions, i = 0; i < 8; pp++, i++)
		pp->p_offset = *off++;
E 4
I 4
	printf("kra%d: media type 0x%x unsupported\n", io->i_unit, i);
	lp->d_npartitions = 0;
E 4
}
#endif
E 1
