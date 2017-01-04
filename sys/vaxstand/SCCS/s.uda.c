h62574
s 00007/00001/00268
d D 7.16 03/11/24 02:01:00 msokolov 31 30
c add RF35, RF36, and RF74
c new partitions for RA/RF73
e
s 00004/00002/00265
d D 7.15 03/11/16 21:32:05 msokolov 30 29
x 26
c reinstate 4.3BSD RD52 and RD53
c add correct RD54
e
s 00004/00000/00259
d D 7.14 01/02/14 13:19:57 msokolov 29 28
c add RA73 and RF73
e
s 00008/00000/00251
d D 7.13 01/02/10 22:33:44 msokolov 28 27
c add RF30, RF31, RF71, and RF72
e
s 00001/00001/00250
d D 7.12 99/09/06 20:54:37 msokolov 27 26
c on RX50 only partitions a and c are valid
e
s 00000/00004/00251
d D 7.11 99/09/06 20:50:40 msokolov 26 25
c In accordiance with the Quasijarus Project policy on the shipment of standard
c disk tables, remove RD52 and RD53
e
s 00012/00004/00243
d D 7.10 99/09/04 17:26:05 msokolov 25 24
c add RA71, RA72, RA90, and RA92
c the partitions were wrong for RA70 and RA82
e
s 00065/00052/00182
d D 7.9 88/07/09 14:38:57 karels 24 23
c updates from torek
e
s 00021/00037/00215
d D 7.8 88/03/22 09:54:56 bostic 23 21
c general cleanup, minor fixes
e
s 00019/00037/00215
d R 7.8 88/03/04 14:10:07 bostic 22 21
c general cleanup, minor fixes
e
s 00037/00046/00215
d D 7.7 88/02/23 15:54:45 bostic 21 19
c change to dev(a,b,c,d) format
e
s 00037/00044/00217
d R 7.7 88/02/22 13:00:14 bostic 20 19
c change to dev(a,b,c,d) format
e
s 00031/00034/00230
d D 7.6 88/01/28 20:53:30 karels 19 18
c uvax changes; fix devsw index in confxx; header updates
e
s 00002/00002/00262
d D 7.5 87/12/12 23:45:29 karels 18 17
c use private headers for now
e
s 00082/00074/00182
d D 7.4 87/11/13 16:45:07 bostic 17 16
c new version from Chris Torek and Jim McKie
e
s 00008/00008/00248
d D 7.3 87/09/16 13:00:13 karels 16 14
c fix error strings
e
s 00009/00009/00247
d R 7.3 87/09/16 12:59:32 karels 15 14
c fix error strings
e
s 00134/00078/00122
d D 7.2 87/02/21 11:41:48 karels 14 13
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00199
d D 7.1 86/06/05 01:46:35 mckusick 13 12
c 4.3BSD release version
e
s 00045/00005/00155
d D 6.4 86/04/14 11:00:55 karels 12 11
c partitions per drive type
e
s 00007/00001/00153
d D 6.3 85/06/08 13:13:22 mckusick 11 10
c Add copyright
e
s 00034/00024/00120
d D 6.2 84/10/04 14:13:55 mckusick 10 9
c only allow initialization to happen once (Jim McKie; mcvax!jim)
e
s 00000/00000/00144
d D 6.1 83/07/29 07:47:57 sam 9 8
c 4.2 distribution
e
s 00001/00001/00143
d D 4.8 83/02/20 19:35:26 sam 8 7
c will someone please decide what the default address is!!!!
e
s 00003/00003/00141
d D 4.7 83/02/16 23:45:06 sam 7 6
c uda50 and rl11 boot blocks; 730 crud
e
s 00001/00001/00143
d D 4.6 83/02/16 12:02:23 sam 6 5
c wrong address again
e
s 00010/00000/00134
d D 4.5 82/12/30 15:32:45 sam 5 4
c add ioctl's and errno
e
s 00001/00001/00133
d D 4.4 82/12/17 17:01:44 sam 4 3
c pte.h is now in ../machine/
e
s 00004/00004/00130
d D 4.3 82/11/13 23:15:38 sam 3 2
c move includes for 4.1c directory layout
e
s 00001/00000/00133
d D 4.2 82/07/15 21:32:36 root 2 1
c new boot scheme
e
s 00133/00000/00000
d D 4.1 81/12/01 09:35:18 sam 1 0
c date and time created 81/12/01 09:35:18 by sam
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
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
D 24
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 24
I 24
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 24
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11

/*
 * UDA50/RAxx disk device driver
 */
I 4
D 24
#include "../machine/pte.h"
E 24
E 4

D 17
#include "../h/param.h"
#include "../h/inode.h"
D 4
#include "../h/pte.h"
E 4
D 3
#include "../h/ubareg.h"
E 3
I 2
#include "../h/fs.h"
I 14
#include "../h/disklabel.h"
E 17
I 17
#include "param.h"
#include "inode.h"
I 24
#include "buf.h"
E 24
#include "fs.h"
#include "disklabel.h"
E 17
E 14
I 3

I 24
#include "../vax/pte.h"

E 24
E 3
E 2
#include "saio.h"
#include "savax.h"

I 12
D 14
#define	NRA	4
E 14
I 14
D 17
#define	NRA		4	/* drives per controller */
E 17
I 17
D 24
#define	NRA		8	/* max. unit number on controller */
E 17
#define	SECTSIZ 	512	/* sector size in bytes */
I 17

E 24
E 17
E 14
E 12
/*
D 17
 * Parameters for the communications area
E 17
I 17
 * Unused, but needed in udareg.h
E 17
 */
D 17
#define	NRSPL2	0
#define	NCMDL2	0
#define	NRSP	(1<<NRSPL2)
#define	NCMD	(1<<NCMDL2)
E 17
I 17
#define NRSP	1
#define NCMD	1
E 17

D 3
#include "../h/udareg.h"
#include "../h/mscp.h"

E 3
I 3
D 18
#include "../vaxuba/udareg.h"
E 18
I 18
D 19
#include "udareg.h"
E 19
I 19
#include "../vaxuba/udareg.h"
E 19
E 18
#include "../vaxuba/ubareg.h"
I 24
#include "../vaxuba/ubavar.h"
E 24
D 18
#include "../vax/mscp.h"
E 18
I 18
D 19
#include "mscp.h"
E 19
I 19
#include "../vax/mscp.h"
E 19
E 18
E 3

I 24
#define	NRA		8	/* max. unit number on controller */
#define	SECTSIZ 	512	/* sector size in bytes */

E 24
D 6
u_short udastd[] = { 0777550 };
E 6
I 6
D 8
u_short udastd[] = { 0772550 };
E 8
I 8
D 21
u_short udastd[] = { 0772150 };
E 21
I 21
#define	MAXCTLR		1		/* all addresses must be specified */
u_short udastd[MAXCTLR] = { 0772150 };
E 21
E 8
E 6

D 23
struct iob	cudbuf;

E 23
D 14
struct udadevice *udaddr = 0;
E 14
I 14
D 21
/*
 * Per-controller structures use dimension MAXNUBA,
 * as only one controller per UNIBUS is supported.
 */
D 19
struct udadevice *udaddr[MAXNUBA] = { 0 };
E 19
I 19
struct udadevice *udaddr[MAXNUBA];
E 21
I 21
struct udadevice *udaddr[MAXNUBA][MAXCTLR];
E 21
E 19
E 14

D 17
struct uda {
	struct udaca	uda_ca;
	struct mscp	uda_rsp;
	struct mscp	uda_cmd;
} uda;
E 17
I 17
struct	uda1 {
	struct	uda1ca uda1_ca;	/* communications area */
	struct	mscp uda1_rsp;	/* response packet */
	struct	mscp uda1_cmd;	/* command packet */
} uda1;
E 17

D 14
struct uda *ud_ubaddr;			/* Unibus address of uda structure */
E 14
I 14
D 17
struct	uda *ud_ubaddr[MAXNUBA];	/* Unibus address of uda structure */
E 17
I 17
D 21
struct	uda1 *ud_ubaddr[MAXNUBA];	/* Unibus address of uda structure */
E 17
struct	disklabel ralabel[MAXNUBA * NRA];
D 19
static	int ratype[MAXNUBA * NRA];
E 19
I 19
static	u_int ratype[MAXNUBA * NRA];
E 21
I 21
				/* Unibus address of uda structure */
struct	uda1 *ud_ubaddr[MAXNUBA][MAXCTLR];
struct	disklabel ralabel[MAXNUBA][MAXCTLR][NRA];
D 24
static	u_int ratype[MAXNUBA][MAXCTLR][NRA];
E 24
I 24
static	u_long ramedia[MAXNUBA][MAXCTLR][NRA];
E 24
E 21
E 19
char	lbuf[SECTSIZ];
D 19
struct	mscp *udcmd();
E 19
E 14

D 12
int uda_off[] = { 0, 15884, 0, -1, -1, -1, 49324, 131404 };
E 12
I 12
D 14
int ra25_off[] = { 0, 15884, 0, -1, -1, -1, 25916, -1 };
int ra60_off[] = { 0, 15884, 0, 49324, 131404, 49324, 242606, 49324 };
int ra80_off[] = { 0, 15884, 0, -1, 49324, 49324, 49910, 131404 };
#ifndef	UCBRA
#ifdef RA_COMPAT
int ra81_off[] = { 0, 16422, 0, 49324, 131404, 412490, 375564, 83538 };
#else
int ra81_off[] = { 0, 16422, 0, 375564, 391986, 699720, 375564, 83538 };
#endif
#else
int ra81_off[] = { 0, 15884, 0, 242606, 258490, 565690, 242606, 49324 };
#endif
E 12

struct mscp *udcmd();
I 12
static int ratype[NRA];
E 12

E 14
D 7
udopen(io)
E 7
I 7
raopen(io)
E 7
	register struct iob *io;
{
D 23
	register struct mscp *mp;
E 23
I 10
D 12
	static int udainit;
E 12
I 12
D 14
	static int udainit, udadriveinit[NRA];
E 12
E 10
	int i;
I 12
	daddr_t off;
E 14
I 14
D 17
	register struct disklabel *lp;
E 17
I 17
D 24
	register struct disklabel *lp, *dlp;
E 24
I 24
	register struct disklabel *lp;
E 24
E 17
	register struct udadevice *addr;
D 17
	register struct uda *ubaddr;
E 17
I 17
D 24
	register struct uda1 *ubaddr;
E 24
I 24
	register struct uda1 *ubaaddr;
E 24
E 17
D 23
	register unit;
E 23
I 23
	register int uba, unit;
E 23
D 17
	static int udainit[MAXNUBA], udadriveinit[MAXNUBA * NRA];
E 17
I 17
D 21
	static int udainit[MAXNUBA];
E 21
I 21
	static int udainit[MAXNUBA][MAXCTLR];
E 21
E 17
D 23
	int uba;
E 23
I 23
	struct iob tio;
E 23
E 14
E 12

I 24
	if ((u_int)(uba = io->i_adapt) >= nuba)
		return (EADAPT);
E 24
I 21
	if ((u_int)io->i_ctlr >= MAXCTLR)
		return (ECTLR);
E 21
D 14
	if (udaddr == 0)
		udaddr = (struct udadevice *)ubamem(io->i_unit, udastd[0]);
	if (ud_ubaddr == 0) {
E 14
I 14
D 24
	unit = io->i_unit;
D 21
	uba = UNITTOUBA(unit);
	if (udaddr[uba] == 0)
		udaddr[uba] = (struct udadevice *)ubamem(unit, udastd[0]);
	addr = udaddr[uba];
E 21
I 21
	uba = io->i_adapt;
E 24
I 24
	if ((u_int)(unit = io->i_unit) >= NRA)
		return (EUNIT);
E 24
	addr = udaddr[uba][io->i_ctlr] =
	    (struct udadevice *)ubamem(uba, udastd[io->i_ctlr]);
E 21
D 23
	if (badaddr((char *)addr, sizeof(short))) {
D 16
		printf("nonexistent device");
E 16
I 16
D 21
		printf("nonexistent device\n");
E 21
I 21
		printf("ra: nonexistent device\n");
E 23
I 23
	if (badaddr((char *)addr, sizeof(short)))
E 23
E 21
E 16
		return (ENXIO);
D 23
	}
E 23
D 21
	if (ud_ubaddr[uba] == 0) {
E 21
I 21
D 24
	if (ud_ubaddr[uba][io->i_ctlr] == 0) {
E 24
I 24
	if ((ubaaddr = ud_ubaddr[uba][io->i_ctlr]) == 0) {
E 24
E 21
E 14
I 10
D 23
		/*
D 14
		 * Initialise cudbuf.i_unit so that controllers
E 14
I 14
		 * Initialize cudbuf.i_unit so that controllers
E 14
		 * on UNIBUSes other than 0 can be used.
		 */
D 14
		cudbuf.i_unit = io->i_unit;
E 14
I 14
		cudbuf.i_unit = unit;
E 14
E 10
D 17
		cudbuf.i_ma = (caddr_t)&uda;
		cudbuf.i_cc = sizeof(uda);
D 14
		ud_ubaddr = (struct uda *)ubasetup(&cudbuf, 2);
E 14
I 14
		ud_ubaddr[uba] = (struct uda *)ubasetup(&cudbuf, 2);
E 17
I 17
		cudbuf.i_ma = (caddr_t)&uda1;
		cudbuf.i_cc = sizeof(uda1);
D 21
		ud_ubaddr[uba] = (struct uda1 *)ubasetup(&cudbuf, 2);
E 21
I 21
		ud_ubaddr[uba][io->i_ctlr] = (struct uda1 *)ubasetup(&cudbuf, 2);
E 23
I 23
		tio = *io;
		tio.i_ma = (caddr_t)&uda1;
		tio.i_cc = sizeof(uda1);
D 24
		ud_ubaddr[uba][io->i_ctlr] = (struct uda1 *)ubasetup(&tio, 2);
E 24
I 24
		ud_ubaddr[uba][io->i_ctlr] = ubaaddr =
		    (struct uda1 *)ubasetup(&tio, 2);
E 24
E 23
E 21
E 17
E 14
	}
D 10
	udaddr->udaip = 0;
	while ((udaddr->udasa & UDA_STEP1) == 0)
		;
	udaddr->udasa = UDA_ERR;
	while ((udaddr->udasa & UDA_STEP2) == 0)
		;
	udaddr->udasa = (short)&ud_ubaddr->uda_ca.ca_ringbase;
	while ((udaddr->udasa & UDA_STEP3) == 0)
		;
	udaddr->udasa = (short)(((int)&ud_ubaddr->uda_ca.ca_ringbase) >> 16);
	while ((udaddr->udasa & UDA_STEP4) == 0)
		;
	udaddr->udasa = UDA_GO;
	uda.uda_ca.ca_rspdsc[0] = (long)&ud_ubaddr->uda_rsp.mscp_cmdref;
	uda.uda_ca.ca_cmddsc[0] = (long)&ud_ubaddr->uda_cmd.mscp_cmdref;
	uda.uda_cmd.mscp_cntflgs = 0;
	if (udcmd(M_OP_STCON) == 0) {
		_stop("ra: open error, STCON");
		return;
	}
	uda.uda_cmd.mscp_unit = io->i_unit&7;
	if (udcmd(M_OP_ONLIN) == 0) {
		_stop("ra: open error, ONLIN");
		return;
E 10
I 10
D 14
	if (udainit == 0) {
		udaddr->udaip = 0;
		while ((udaddr->udasa & UDA_STEP1) == 0)
E 14
I 14
D 21
	ubaddr = ud_ubaddr[uba];
	if (udainit[uba] == 0) {
E 21
I 21
D 24
	ubaddr = ud_ubaddr[uba][io->i_ctlr];
E 24
	if (udainit[uba][io->i_ctlr] == 0) {
E 21
		addr->udaip = 0;
D 23
		while ((addr->udasa & UDA_STEP1) == 0)
E 14
			;
E 23
I 23
		while ((addr->udasa & UDA_STEP1) == 0);
E 23
D 14
		udaddr->udasa = UDA_ERR;
		while ((udaddr->udasa & UDA_STEP2) == 0)
E 14
I 14
		addr->udasa = UDA_ERR;
D 23
		while ((addr->udasa & UDA_STEP2) == 0)
E 14
			;
E 23
I 23
		while ((addr->udasa & UDA_STEP2) == 0);
E 23
D 14
		udaddr->udasa = (short)&ud_ubaddr->uda_ca.ca_ringbase;
		while ((udaddr->udasa & UDA_STEP3) == 0)
E 14
I 14
D 17
		addr->udasa = (short)&ubaddr->uda_ca.ca_ringbase;
E 17
I 17
D 24
		addr->udasa = (short)&ubaddr->uda1_ca.ca_rspdsc;
E 24
I 24
		addr->udasa = (int)&ubaaddr->uda1_ca.ca_rspdsc;
E 24
E 17
D 23
		while ((addr->udasa & UDA_STEP3) == 0)
E 14
			;
E 23
I 23
		while ((addr->udasa & UDA_STEP3) == 0);
E 23
D 14
		udaddr->udasa =
			(short)(((int)&ud_ubaddr->uda_ca.ca_ringbase) >> 16);
		while ((udaddr->udasa & UDA_STEP4) == 0)
E 14
I 14
D 24
		addr->udasa =
D 17
		    (short)(((int)&ubaddr->uda_ca.ca_ringbase) >> 16);
E 17
I 17
		    (short)(((int)&ubaddr->uda1_ca.ca_rspdsc) >> 16);
E 24
I 24
		addr->udasa = (int)&ubaaddr->uda1_ca.ca_rspdsc >> 16;
E 24
E 17
D 23
		while ((addr->udasa & UDA_STEP4) == 0)
E 14
			;
E 23
I 23
		while ((addr->udasa & UDA_STEP4) == 0);
E 23
D 14
		udaddr->udasa = UDA_GO;
		uda.uda_ca.ca_rspdsc[0] = (long)&ud_ubaddr->uda_rsp.mscp_cmdref;
		uda.uda_ca.ca_cmddsc[0] = (long)&ud_ubaddr->uda_cmd.mscp_cmdref;
E 14
I 14
		addr->udasa = UDA_GO;
D 17
		uda.uda_ca.ca_rspdsc[0] = (long)&ubaddr->uda_rsp.mscp_cmdref;
		uda.uda_ca.ca_cmddsc[0] = (long)&ubaddr->uda_cmd.mscp_cmdref;
E 14
		uda.uda_cmd.mscp_cntflgs = 0;
D 14
		if (udcmd(M_OP_STCON) == 0) {
			_stop("ra: open error, STCON");
			return;
E 14
I 14
		if (udcmd(M_OP_STCON, io) == 0) {
D 16
			printf("ra: open error, STCON");
E 16
I 16
			printf("ra: open error, STCON\n");
E 17
I 17
D 24
		uda1.uda1_ca.ca_rspdsc = (long)&ubaddr->uda1_rsp.mscp_cmdref;
		uda1.uda1_ca.ca_cmddsc = (long)&ubaddr->uda1_cmd.mscp_cmdref;
E 24
I 24
		uda1.uda1_ca.ca_rspdsc = (long)&ubaaddr->uda1_rsp.mscp_cmdref;
		uda1.uda1_ca.ca_cmddsc = (long)&ubaaddr->uda1_cmd.mscp_cmdref;
E 24
		/* uda1.uda1_cmd.mscp_cntflgs = 0; */
D 19
		if (udcmd(M_OP_SETCTLRC, io) == 0) {
E 19
I 19
		if (udcmd(M_OP_SETCTLRC, io)) {
E 19
			printf("ra: open error, SETCTLRC\n");
E 17
E 16
D 21
			return (EIO);
E 21
I 21
			return (ENXIO);
E 21
E 14
		}
I 17
D 21
		udainit[uba] = 1;
E 21
I 21
		udainit[uba][io->i_ctlr] = 1;
E 21
E 17
D 12
		uda.uda_cmd.mscp_unit = io->i_unit&7;
E 12
I 12
	}
D 14
	i = io->i_unit & 7;
	if (udadriveinit[i] == 0) {
		uda.uda_cmd.mscp_unit = i;
E 12
		if (udcmd(M_OP_ONLIN) == 0) {
			_stop("ra: open error, ONLIN");
			return;
E 14
I 14
D 21
	lp = &ralabel[unit];
D 17
	if (udadriveinit[unit] == 0) {
E 17
I 17
	if (ratype[unit] == 0) {
E 21
I 21
	lp = &ralabel[uba][io->i_ctlr][unit];
D 24
	if (ratype[uba][io->i_ctlr][unit] == 0) {
E 24
I 24
	if (ramedia[uba][io->i_ctlr][unit] == 0) {
E 24
E 21
E 17
D 23
		struct iob tio;

E 23
D 17
		uda.uda_cmd.mscp_unit = UNITTODRIVE(unit);
		if (udcmd(M_OP_ONLIN, io) == 0) {
D 16
			printf("ra: open error, ONLIN");
E 16
I 16
			printf("ra: open error, ONLIN\n");
E 17
I 17
D 21
		uda1.uda1_cmd.mscp_unit = UNITTODRIVE(unit);
E 21
I 21
		uda1.uda1_cmd.mscp_unit = unit;
E 21
D 19
		if (udcmd(M_OP_ONLINE, io) == 0) {
E 19
I 19
		if (udcmd(M_OP_ONLINE, io)) {
E 19
			printf("ra: open error, ONLINE\n");
E 17
E 16
D 21
			return (EIO);
E 21
I 21
			return (ENXIO);
E 21
E 14
		}
I 19
D 21
		ratype[unit] = uda1.uda1_rsp.mscp_onle.onle_drivetype;
E 21
I 21
D 24
		ratype[uba][io->i_ctlr][unit] =
		    uda1.uda1_rsp.mscp_onle.onle_drivetype;
E 24
I 24
		ramedia[uba][io->i_ctlr][unit] =
		    uda1.uda1_rsp.mscp_onle.onle_mediaid;
E 24
E 21
E 19
D 14
		udainit = 1;
E 14
I 14
D 17
		udainit[uba] = 1;
E 17
		tio = *io;
		tio.i_bn = LABELSECTOR;
		tio.i_ma = lbuf;
		tio.i_cc = SECTSIZ;
		tio.i_flgs |= F_RDDATA;
D 23
		if (rastrategy(&tio, READ) != SECTSIZ) {
D 16
			printf("can't read disk label");
E 16
I 16
D 21
			printf("can't read disk label\n");
E 16
			return (EIO);
E 21
I 21
			printf("ra: can't read disk label\n");
			return (ENXIO);
E 21
		}
E 23
I 23
		if (rastrategy(&tio, READ) != SECTSIZ)
			return (ERDLAB);
E 23
D 16
		*lp = *(struct disklabel *)(lbuf + LABELOFFSET);
E 16
D 17
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
E 17
I 17
D 19
		dlp = (struct disklabel *)(lbuf + LABELOFFSET);
		if (dlp->d_magic != DISKMAGIC || dlp->d_magic2 != DISKMAGIC) {
E 19
I 19
		*lp = *(struct disklabel *)(lbuf + LABELOFFSET);
D 23
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
E 19
E 17
			printf("ra%d: unlabeled\n", unit);
E 23
I 23
D 24
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC)
E 24
I 24
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
E 24
E 23
#ifdef COMPAT_42
I 23
D 24
		{
E 24
			printf("ra%d: unlabeled\n", unit);
E 23
			ramaptype(io, lp);
I 23
D 24
		}
E 24
E 23
#else
D 23
			return (ENXIO);
E 23
I 23
			return (EUNLAB);
E 23
#endif
I 24
		}
E 24
D 16
		}
E 16
I 16
D 19
		} else
D 17
			*lp = *(struct disklabel *)(lbuf + LABELOFFSET);
E 17
I 17
			*lp = *dlp;
E 19
I 19
D 23
		}
E 23
E 19
E 17
E 16
E 14
E 10
	}
D 12
	if (io->i_boff < 0 || io->i_boff > 7 || uda_off[io->i_boff] == -1)
E 12
I 12
D 14
	if (io->i_boff < 0 || io->i_boff > 7)
E 12
		_stop("ra: bad unit");
D 12
	io->i_boff = uda_off[io->i_boff];
E 12
I 12

	switch (ratype[i]) {
	case    25:
		off = ra25_off[io->i_boff];
		break;
	case    60:
		off = ra60_off[io->i_boff];
		break;
	case    80:
		off = ra80_off[io->i_boff];
		break;
	case    81:
		off = ra81_off[io->i_boff];
		break;
	default:
		printf("uda%d: don't support ra%d's\n", i, ratype[i]);
		off = -1;
		break;
E 14
I 14
D 21
	if ((unsigned)io->i_boff >= lp->d_npartitions ||
	    (io->i_boff = lp->d_partitions[io->i_boff].p_offset) == -1) {
D 16
		printf("ra: bad partition");
E 16
I 16
		printf("ra: bad partition\n");
E 16
		return (EUNIT);
E 14
	}
E 21
I 21
	if ((u_int)io->i_part >= lp->d_npartitions ||
	    (io->i_boff = lp->d_partitions[io->i_part].p_offset) == -1)
		return (EPART);
E 21
D 14
	if (off == -1)
		_stop("ra: bad partition");
	io->i_boff = off;
E 14
I 14
	return (0);
E 14
E 12
}

D 19
struct mscp *
E 19
I 19
int
E 19
D 14
udcmd(op)
E 14
I 14
udcmd(op, io)
E 14
	int op;
I 14
	register struct iob *io;
E 14
{
I 19
	register struct uda1 *u = &uda1;
E 19
D 17
	struct mscp *mp;
E 17
I 17
	register struct mscp *mp;
E 17
D 23
	int i;
E 23
I 23
	register int i;
E 23

D 17
	uda.uda_cmd.mscp_opcode = op;
	uda.uda_rsp.mscp_header.uda_msglen = sizeof (struct mscp);
	uda.uda_cmd.mscp_header.uda_msglen = sizeof (struct mscp);
	uda.uda_ca.ca_rspdsc[0] |= UDA_OWN|UDA_INT;
	uda.uda_ca.ca_cmddsc[0] |= UDA_OWN|UDA_INT;
E 17
I 17
D 19
	uda1.uda1_cmd.mscp_opcode = op;
	uda1.uda1_cmd.mscp_msglen = MSCP_MSGLEN;
	uda1.uda1_rsp.mscp_msglen = MSCP_MSGLEN;
	uda1.uda1_ca.ca_rspdsc |= MSCP_OWN|MSCP_INT;
	uda1.uda1_ca.ca_cmddsc |= MSCP_OWN|MSCP_INT;
E 19
I 19
	u->uda1_cmd.mscp_opcode = op;
	u->uda1_cmd.mscp_msglen = MSCP_MSGLEN;
	u->uda1_rsp.mscp_msglen = MSCP_MSGLEN;
	u->uda1_ca.ca_rspdsc |= MSCP_OWN|MSCP_INT;
	u->uda1_ca.ca_cmddsc |= MSCP_OWN|MSCP_INT;
E 19
E 17
D 14
	i = udaddr->udaip;
E 14
I 14
D 21
	i = udaddr[UNITTOUBA(io->i_unit)]->udaip;
E 21
I 21
D 23
	i = udaddr[io->i_adapt][io->i_ctlr]->udaip;
E 23
I 23
	i = udaddr[io->i_adapt][io->i_ctlr]->udaip;	/* start uda polling */
I 24
#ifdef lint
	i = i;
#endif
E 24
E 23
E 21
I 17
D 19
	mp = &uda1.uda1_rsp;
E 19
I 19
	mp = &u->uda1_rsp;
E 19
E 17
E 14
	for (;;) {
D 17
		if (uda.uda_ca.ca_cmdint)
			uda.uda_ca.ca_cmdint = 0;
		if (uda.uda_ca.ca_rspint)
E 17
I 17
D 19
		if (uda1.uda1_ca.ca_cmdint)
			uda1.uda1_ca.ca_cmdint = 0;
		if (uda1.uda1_ca.ca_rspint == 0)
E 19
I 19
		if (u->uda1_ca.ca_cmdint)
			u->uda1_ca.ca_cmdint = 0;
		if (u->uda1_ca.ca_rspint == 0)
E 19
			continue;
D 19
		uda1.uda1_ca.ca_rspint = 0;
E 19
I 19
		u->uda1_ca.ca_rspint = 0;
E 19
		if (mp->mscp_opcode == (op | M_OP_END))
E 17
			break;
I 17
D 19
		printf("unexpected mscp response (type 0x%x) ignored",
				MSCP_MSGTYPE(mp->mscp_msgtc));
		uda1.uda1_ca.ca_rspdsc |= MSCP_OWN | MSCP_INT;
E 19
I 19
		printf("unexpected rsp type %x op %x ignored\n",
			MSCP_MSGTYPE(mp->mscp_msgtc), mp->mscp_opcode);
		u->uda1_ca.ca_rspdsc |= MSCP_OWN | MSCP_INT;
E 19
E 17
	}
D 17
	uda.uda_ca.ca_rspint = 0;
	mp = &uda.uda_rsp;
	if (mp->mscp_opcode != (op|M_OP_END) ||
	    (mp->mscp_status&M_ST_MASK) != M_ST_SUCC)
E 17
I 17
	if ((mp->mscp_status&M_ST_MASK) != M_ST_SUCCESS)
E 17
D 19
		return(0);
I 12
D 17
	if (mp->mscp_opcode == (M_OP_ONLIN|M_OP_END))
D 14
		ratype[uda.uda_cmd.mscp_unit] = mp->mscp_mediaid & 0x7f;
E 14
I 14
		ratype[io->i_unit] = mp->mscp_mediaid & 0x7f;
E 17
I 17
	if (mp->mscp_opcode == (M_OP_ONLINE|M_OP_END))
		ratype[io->i_unit] = mp->mscp_onle.onle_drivetype;
E 17
E 14
E 12
	return(mp);
E 19
I 19
		return (-1);
	return (0);
E 19
}

D 7
udstrategy(io, func)
E 7
I 7
rastrategy(io, func)
E 7
	register struct iob *io;
I 24
	int func;
E 24
{
	register struct mscp *mp;
D 24
	int ubinfo;
E 24
I 24
	register int ubinfo;
E 24

	ubinfo = ubasetup(io, 1);
D 17
	mp = &uda.uda_cmd;
	mp->mscp_lbn = io->i_bn;
E 17
I 17
	mp = &uda1.uda1_cmd;
E 17
D 16
	mp->mscp_unit = io->i_unit&7;
E 16
I 16
D 21
	mp->mscp_unit = UNITTODRIVE(io->i_unit);
E 21
I 21
	mp->mscp_unit = io->i_unit;
E 21
E 16
D 17
	mp->mscp_bytecnt = io->i_cc;
	mp->mscp_buffer = (ubinfo & 0x3ffff) | (((ubinfo>>28)&0xf)<<24);
E 17
I 17
	mp->mscp_seq.seq_lbn = io->i_bn;
	mp->mscp_seq.seq_bytecount = io->i_cc;
D 24
	mp->mscp_seq.seq_buffer = (ubinfo & 0x3ffff) | (((ubinfo>>28)&0xf)<<24);
E 24
I 24
	mp->mscp_seq.seq_buffer = UBAI_ADDR(ubinfo) | (UBAI_BDP(ubinfo) << 24);
E 24
E 17
D 14
	if ((mp = udcmd(func == READ ? M_OP_READ : M_OP_WRITE)) == 0) {
E 14
I 14
D 19
	if ((mp = udcmd(func == READ ? M_OP_READ : M_OP_WRITE, io)) == 0) {
E 19
I 19
	if (udcmd(func == READ ? M_OP_READ : M_OP_WRITE, io)) {
E 19
E 14
		printf("ra: I/O error\n");
		ubafree(io, ubinfo);
D 24
		return(-1);
E 24
I 24
		return (-1);
E 24
	}
	ubafree(io, ubinfo);
D 24
	return(io->i_cc);
E 24
I 24
	return (io->i_cc);
E 24
}
I 5

D 21
/*ARGSUSED*/
D 7
udioctl(io, cmd, arg)
E 7
I 7
raioctl(io, cmd, arg)
E 7
	struct iob *io;
	int cmd;
	caddr_t arg;
{

	return (ECMD);
}
I 14

E 21
#ifdef COMPAT_42
D 24
u_long ra25_off[] = { 0, 15884, 0, -1, -1, -1, 25916, -1 };
E 24
I 24
u_long rc25_off[] = { 0, 15884, 0, -1, -1, -1, 25916, -1 };
E 24
I 17
D 27
u_long rx50_off[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
E 27
I 27
u_long rx50_off[] = { 0, -1, 0, -1, -1, -1, -1, -1 };
E 27
D 26
D 30
u_long rd52_off[] = { 0, 15884, 0, 0, 0, 0, 25650, 0 };
u_long rd53_off[] = { 0, 15884, 0, 0, 0, 33440, 49324, 15884 };
E 30
I 30
u_long rd52_off[] = { 0, 15884, 0, -1, -1, -1, 25650, -1 };
u_long rd53_off[] = { 0, 15884, 0, -1, 0, 33440, 49324, 15884 };
u_long rd54_off[] = { 0, 16065, 0, 49725, 65790, 121890, 49725, -1 };
E 30
E 26
E 17
u_long ra60_off[] = { 0, 15884, 0, 49324, 131404, 49324, 242606, 49324 };
I 24
D 25
#define ra70_off ra60_off
E 25
I 25
u_long ra70_off[] = { 0, 15972, 0, 341220, 357192, 413457, 341220, 49731 };
u_long ra71_off[] = { 0, 16422, 0, 375564, 391986, 699720, 375564, 83538 };
u_long ra72_off[] = { 0, 16320, 0, 375360, 391680, 699720, 375360, 83640 };
I 29
D 31
u_long ra73_off[] = { 0, 16170, 0, 376320, 392490, 699720, 376320, 83790 };
E 31
I 31
u_long ra73_off[] = { 0, 33810, 0, 458640, 590940, 2229990, 458640, 166110 };
E 31
E 29
E 25
E 24
u_long ra80_off[] = { 0, 15884, 0, -1, 49324, 49324, 49910, 131404 };
#ifndef	UCBRA
#ifdef RA_COMPAT
u_long ra81_off[] = { 0, 16422, 0, 49324, 131404, 412490, 375564, 83538 };
#else
D 25
u_long ra81_off[] = { 0, 16422, 0, 375564, 391986, 699720, 375564, 83538 };
E 25
I 25
#define ra81_off ra71_off
E 25
#endif
#else
u_long ra81_off[] = { 0, 15884, 0, 242606, 258490, 565690, 242606, 49324 };
#endif
I 24
D 25
u_long ra82_off[] = { 0, 15884, 0, 375345, 391590, 699390, 375345, 83790 };
E 25
I 25
u_long ra82_off[] = { 0, 16245, 0, 375345, 391590, 699390, 375345, 83790 };
u_long ra90_off[] = { 0, 16146, 0, 374946, 391092, 698763, 374946, 83421 };
#define ra92_off ra90_off
I 28
u_long rf30_off[] = { 0, 15984, 0, 49506, 65490, 121434, 49506, -1 };
u_long rf31_off[] = { 0, 16000, 0, 374800, 390800, 698000, 374800, 83200 };
I 31
u_long rf35_off[] = { 0, 15960, 0, 375060, 391020, 698250, 375060, 82992 };
u_long rf36_off[] = { 0, 32768, 0, 455186, 586258, 2224658, 455186, 163840 };
E 31
u_long rf71_off[] = { 0, 15984, 0, 374736, 390720, 697968, 374736, 82880 };
u_long rf72_off[] = { 0, 16800, 0, 375900, 392700, 700350, 375900, 84000 };
I 29
#define rf73_off ra73_off
I 31
u_long rf74_off[] = { 0, 32768, 0, 455186, 586258, 3863058, 455186, 163840 };
E 31
E 29
E 28
E 25
E 24

I 17
D 24
u_long	*ra_off[] = {
	0,		/* 0 = unused */
	ra80_off,	/* 1 = ra80 */
	ra25_off,	/* 2 = rc25 removable */
	ra25_off,	/* 3 = rc25 fixed */
	ra60_off,	/* 4 = ra60 */
	ra81_off,	/* 5 = ra81 */
	0,		/* 6 = ? */
	rx50_off,	/* 7 = rx50 */
	rd52_off,	/* 8 = rd52 */
	rd53_off,	/* 9 = rd53 */
E 24
I 24
struct mediamap {
	u_long	id;		/* media ID */
	u_long	*off;		/* offsets */
} ra_map[] = {
	{ MSCP_MKDRIVE2('R', 'A', 60),		ra60_off },
	{ MSCP_MKDRIVE2('R', 'A', 70),		ra70_off },
D 25
	{ MSCP_MKDRIVE2('R', 'A', 80),		ra80_off },
E 25
I 25
	{ MSCP_MKDRIVE2('R', 'A', 71),		ra71_off },
	{ MSCP_MKDRIVE2('R', 'A', 72),		ra72_off },
I 29
	{ MSCP_MKDRIVE2('R', 'A', 73),		ra73_off },
E 29
	{ MSCP_MKDRIVE2('R', 'A', 80),		ra80_off },
E 25
	{ MSCP_MKDRIVE2('R', 'A', 81),		ra81_off },
	{ MSCP_MKDRIVE2('R', 'A', 82),		ra82_off },
I 25
	{ MSCP_MKDRIVE2('R', 'A', 90),		ra90_off },
	{ MSCP_MKDRIVE2('R', 'A', 92),		ra92_off },
I 28
	{ MSCP_MKDRIVE2('R', 'F', 30),		rf30_off },
	{ MSCP_MKDRIVE2('R', 'F', 31),		rf31_off },
I 31
	{ MSCP_MKDRIVE2('R', 'F', 35),		rf35_off },
	{ MSCP_MKDRIVE2('R', 'F', 36),		rf36_off },
E 31
	{ MSCP_MKDRIVE2('R', 'F', 71),		rf71_off },
	{ MSCP_MKDRIVE2('R', 'F', 72),		rf72_off },
I 29
	{ MSCP_MKDRIVE2('R', 'F', 73),		rf73_off },
I 31
	{ MSCP_MKDRIVE2('R', 'F', 74),		rf74_off },
E 31
E 29
E 28
E 25
	{ MSCP_MKDRIVE2('R', 'C', 25),		rc25_off },
	{ MSCP_MKDRIVE3('R', 'C', 'F', 25),	rc25_off },
D 26
	{ MSCP_MKDRIVE2('R', 'D', 52),		rd52_off },
	{ MSCP_MKDRIVE2('R', 'D', 53),		rd53_off },
I 30
	{ MSCP_MKDRIVE2('R', 'D', 54),		rd54_off },
E 30
E 26
	{ MSCP_MKDRIVE2('R', 'X', 50),		rx50_off },
	0
E 24
};

D 19
#define NOFFS	(sizeof(ra_off)/sizeof(int))
E 19
I 19
D 24
#define NOFFS	(sizeof(ra_off)/sizeof(ra_off[0]))
E 19

E 24
E 17
ramaptype(io, lp)
	register struct iob *io;
	register struct disklabel *lp;
{
	register struct partition *pp;
D 17
	register i;
E 17
I 17
D 19
	register int i;
E 19
I 19
D 23
	register u_int i;
E 23
E 19
E 17
D 24
	register u_long *off;
I 23
	register u_int i;
E 24
I 24
	register u_long i;
	register struct mediamap *map;
E 24
E 23

D 17
	switch (ratype[io->i_unit]) {
	case    25:
		off = ra25_off;
		break;
	case    60:
		off = ra60_off;
		break;
	case    80:
		off = ra80_off;
		break;
	case    81:
		off = ra81_off;
		break;
	default:
		printf("uda%d: don't support ra%d's\n",
		    io->i_unit, ratype[io->i_unit]);
E 17
I 17
D 19
	i = ratype[io->i_unit];
	if ((unsigned)i >= NOFFS || (off = ra_off[i]) == 0) {
E 19
I 19
D 21
	if ((i = ratype[io->i_unit]) >= NOFFS || (off = ra_off[i]) == 0) {
E 21
I 21
D 24
	if ((i = ratype[io->i_adapt][io->i_ctlr][io->i_unit]) >= NOFFS ||
	    (off = ra_off[i]) == 0) {
E 21
E 19
		printf("ra%d: ra type %d unsupported\n", io->i_unit, i);
E 17
		lp->d_npartitions = 0;
		return;
E 24
I 24
	i = MSCP_MEDIA_DRIVE(ramedia[io->i_adapt][io->i_ctlr][io->i_unit]);
	for (map = ra_map; map->id != 0; map++) {
		if (map->id == i) {
			lp->d_npartitions = 8;
			for (pp = lp->d_partitions, i = 0; i < 8; pp++, i++)
				pp->p_offset = map->off[i];
			return;
		}
E 24
	}
D 24
	lp->d_npartitions = 8;
D 17
	pp = lp->d_partitions;
	for (i = 0; i < 8; i++, pp++)
E 17
I 17
	for (pp = lp->d_partitions, i = 0; i < 8; pp++, i++)
E 17
		pp->p_offset = *off++;
E 24
I 24
	printf("ra%d: media type 0x%x unsupported\n", io->i_unit, i);
	lp->d_npartitions = 0;
E 24
}
#endif
E 14
E 5
E 1
