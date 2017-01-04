h51675
s 00018/00003/00436
d D 7.4 88/07/09 13:40:28 bostic 10 9
c install approved copyright notice
e
s 00026/00002/00413
d D 7.3 88/03/10 18:59:06 karels 9 8
c new definitions to go with last month's driver
e
s 00307/00212/00108
d D 7.2 87/10/23 11:06:25 bostic 8 7
c new version of mscp.h; (Chris Torek)
e
s 00001/00001/00319
d D 7.1 86/06/05 00:46:11 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00313
d D 6.3 85/06/08 13:44:01 mckusick 6 5
c Add copyright
e
s 00007/00000/00307
d D 6.2 84/06/27 20:49:13 sam 5 4
c check in for karels -- mscp messages actually larger than header 
c (uda50 doesn't care, but other controllers might)
e
s 00000/00000/00307
d D 6.1 83/07/29 07:20:41 sam 4 3
c 4.2 distribution
e
s 00001/00004/00306
d D 4.3 82/11/13 22:58:47 sam 3 2
c merge of 4.1b with 4.1c
e
s 00003/00008/00307
d D 4.2 82/05/26 14:58:50 sam 2 1
c 730 mods
e
s 00315/00000/00000
d D 4.1 81/11/04 10:53:55 wnj 1 0
c date and time created 81/11/04 10:53:55 by wnj
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 7
 * Copyright (c) 1982 Regents of the University of California.
E 7
I 7
D 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
I 9
D 10
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 9
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 10
 *
I 10
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms are permitted
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
 *
E 10
 *	%W% (Berkeley) %G%
 */
I 10

E 10
E 6
I 5
D 8

E 8
E 5
D 2

E 2
/*
 * Definitions for the Mass Storage Control Protocol
I 8
 * I WISH I KNEW WHAT MORE OF THESE WERE.  IT SURE WOULD BE NICE
 * IF DEC SOLD DOCUMENTATION FOR THEIR OWN CONTROLLERS.
E 8
 */

D 8

E 8
/*
 * Control message opcodes
 */
D 8
#define	M_OP_ABORT	0001	/* Abort command */
#define	M_OP_GTCMD	0002	/* Get command status command */
#define	M_OP_GTUNT	0003	/* Get unit status command */
#define	M_OP_STCON	0004	/* Set controller characteristics command */
#define	M_OP_SEREX	0007	/* Serious exception end message */
#define	M_OP_AVAIL	0010	/* Available command */
#define	M_OP_ONLIN	0011	/* Online command */
#define	M_OP_STUNT	0012	/* Set unit characteristics command */
#define	M_OP_DTACP	0013	/* Determine access paths command */
#define	M_OP_ACCES	0020	/* Access command */
#define	M_OP_CMPCD	0021	/* Compare controller data command */
#define	M_OP_ERASE	0022	/* Erase command */
#define	M_OP_FLUSH	0023	/* Flush command */
#define	M_OP_REPLC	0024	/* Replace command */
#define	M_OP_COMP	0040	/* Compare host data command */
#define	M_OP_READ	0041	/* Read command */
#define	M_OP_WRITE	0042	/* Write command */
#define	M_OP_AVATN	0100	/* Available attention message */
#define	M_OP_DUPUN	0101	/* Duplicate unit number attention message */
#define	M_OP_ACPTH	0102	/* Access path attention message */
#define	M_OP_END	0200	/* End message flag */
E 8
I 8
#define	M_OP_ABORT	0x01	/* Abort command */
#define	M_OP_GETCMDST	0x02	/* Get command status command */
#define	M_OP_GETUNITST	0x03	/* Get unit status command */
#define	M_OP_SETCTLRC	0x04	/* Set controller characteristics command */
#define	M_OP_SEREX	0x07	/* Serious exception end message */
#define	M_OP_AVAILABLE	0x08	/* Available command */
#define	M_OP_ONLINE	0x09	/* Online command */
#define	M_OP_SETUNITC	0x0a	/* Set unit characteristics command */
#define	M_OP_DTACCPATH	0x0b	/* Determine access paths command */
#define	M_OP_ACCESS	0x10	/* Access command */
#define	M_OP_COMPCD	0x11	/* Compare controller data command */
#define	M_OP_ERASE	0x12	/* Erase command */
#define	M_OP_FLUSH	0x13	/* Flush command */
#define	M_OP_REPLACE	0x14	/* Replace command */
#define	M_OP_COMPHD	0x20	/* Compare host data command */
#define	M_OP_READ	0x21	/* Read command */
#define	M_OP_WRITE	0x22	/* Write command */
#define	M_OP_AVAILATTN	0x40	/* Available attention message */
#define	M_OP_DUPUNIT	0x41	/* Duplicate unit number attention message */
#define	M_OP_ACCPATH	0x42	/* Access path attention message */
#define	M_OP_END	0x80	/* End message flag */
E 8


/*
 * Generic command modifiers
 */
D 8
#define	M_MD_EXPRS	0100000		/* Express request */
#define	M_MD_COMP	0040000		/* Compare */
#define	M_MD_CLSEX	0020000		/* Clear serious exception */
#define	M_MD_ERROR	0010000		/* Force error */
#define	M_MD_SCCHH	0004000		/* Suppress caching (high speed) */
#define	M_MD_SCCHL	0002000		/* Suppress caching (low speed) */
#define	M_MD_SECOR	0001000		/* Suppress error correction */
#define	M_MD_SEREC	0000400		/* Suppress error recovery */
#define	M_MD_SSHDW	0000200		/* Suppress shadowing */
#define	M_MD_WBKNV	0000100		/* Write back (non-volatile) */
#define	M_MD_WBKVL	0000040		/* Write back (volatile) */
#define	M_MD_WRSEQ	0000020		/* Write shadow set one unit at a time */
E 8
I 8
#define	M_MD_EXPRS	0x8000	/* Express request */
#define	M_MD_COMP	0x4000	/* Compare */
#define	M_MD_CLSEX	0x2000	/* Clear serious exception */
#define	M_MD_ERROR	0x1000	/* Force error */
#define	M_MD_SCCHH	0x0800	/* Suppress caching (high speed) */
#define	M_MD_SCCHL	0x0400	/* Suppress caching (low speed) */
#define	M_MD_SECOR	0x0200	/* Suppress error correction */
#define	M_MD_SEREC	0x0100	/* Suppress error recovery */
#define	M_MD_SSHDW	0x0080	/* Suppress shadowing */
#define	M_MD_WBKNV	0x0040	/* Write back (non-volatile) */
#define	M_MD_WBKVL	0x0020	/* Write back (volatile) */
#define	M_MD_WRSEQ	0x0010	/* Write shadow set one unit at a time */
E 8

/*
 * AVAILABLE command modifiers
 */
D 8
#define	M_MD_ALLCD	0000002		/* All class drivers */
#define	M_MD_SPNDW	0000001		/* Spin down */
E 8
I 8
#define	M_AVM_ALLCD	0x0002	/* All class drivers */
#define	M_AVM_SPINDOWN	0x0001	/* Spin down */
E 8

/*
 * FLUSH command modifiers
 */
D 8
#define	M_MD_FLENU	0000001		/* Flush entire unit */
#define	M_MD_VOLTL	0000002		/* Volatile only */
E 8
I 8
#define	M_FLM_FLUSHENU	0x0001	/* Flush entire unit */
#define	M_FLM_VOLATILE	0x0002	/* Volatile only */
E 8

/*
 * GET UNIT STATUS command modifiers
 */
D 8
#define	M_MD_NXUNT	0000001		/* Next unit */
E 8
I 8
#define	M_GUM_NEXTUNIT	0x0001	/* Next unit */
E 8

/*
 * ONLINE command modifiers
 */
D 8
#define	M_MD_RIP	0000001		/* Allow self destruction */
#define	M_MD_IGNMF	0000002		/* Ignore media format error */
E 8
I 8
#define	M_OLM_RIP	0x0001	/* Allow self destruction */
#define	M_OLM_IGNMF	0x0002	/* Ignore media format error */
E 8

/*
 * ONLINE and SET UNIT CHARACTERISTICS command modifiers
 */
D 8
#define	M_MD_ALTHI	0000040		/* Alter host identifier */
#define	M_MD_SHDSP	0000020		/* Shadow unit specified */
#define	M_MD_CLWBL	0000010		/* Clear write-back data lost */
#define	M_MD_STWRP	0000004		/* Set write protect */
E 8
I 8
#define	M_OSM_ALTERHI	0x0020	/* Alter host identifier */
#define	M_OSM_SHADOWSP	0x0010	/* Shadow unit specified */
#define	M_OSM_CLEARWBL	0x0008	/* Clear write-back data lost */
#define	M_OSM_SETWRPROT	0x0004	/* Set write protect */
E 8

/*
 * REPLACE command modifiers
 */
D 8
#define	M_MD_PRIMR	0000001		/* Primary replacement block */
E 8
I 8
#define	M_RPM_PRIMARY	0x0001	/* Primary replacement block */
E 8

D 8

E 8
/*
 * End message flags
 */
D 8
#define	M_EF_BBLKR	0200	/* Bad block reported */
#define	M_EF_BBLKU	0100	/* Bad block unreported */
#define	M_EF_ERLOG	0040	/* Error log generated */
#define	M_EF_SEREX	0020	/* Serious exception */
E 8
I 8
#define	M_EF_BBLKR	0x80	/* Bad block reported */
#define	M_EF_BBLKU	0x40	/* Bad block unreported */
#define	M_EF_ERLOG	0x20	/* Error log generated */
#define	M_EF_SEREX	0x10	/* Serious exception */
E 8

D 8

E 8
/*
 * Controller flags
 */
D 8
#define	M_CF_ATTN	0200	/* Enable attention messages */
#define	M_CF_MISC	0100	/* Enable miscellaneous error log messages */
#define	M_CF_OTHER	0040	/* Enable other host's error log messages */
#define	M_CF_THIS	0020	/* Enable this host's error log messages */
#define	M_CF_MLTHS	0004	/* Multi-host */
#define	M_CF_SHADW	0002	/* Shadowing */
#define	M_CF_576	0001	/* 576 byte sectors */
E 8
I 8
#define	M_CF_ATTN	0x80	/* Enable attention messages */
#define	M_CF_MISC	0x40	/* Enable miscellaneous error log messages */
#define	M_CF_OTHER	0x20	/* Enable other host's error log messages */
#define	M_CF_THIS	0x10	/* Enable this host's error log messages */
#define	M_CF_MLTHS	0x04	/* Multi-host */
#define	M_CF_SHADW	0x02	/* Shadowing */
#define	M_CF_576	0x01	/* 576 byte sectors */
E 8

D 8

E 8
/*
 * Unit flags
 */
D 8
#define	M_UF_REPLC	0100000		/* Controller initiated bad block replacement */
#define	M_UF_INACT	0040000		/* Inactive shadow set unit */
#define	M_UF_WRTPH	0020000		/* Write protect (hardware) */
#define	M_UF_WRTPS	0010000		/* Write protect (software or volume) */
#define	M_UF_SCCHH	0004000		/* Suppress caching (high speed) */
#define	M_UF_SCCHL	0002000		/* Suppress caching (low speed) */
#define	M_UF_RMVBL	0000200		/* Removable media */
#define	M_UF_WBKNV	0000100		/* Write back (non-volatile) */
#define	M_UF_576	0000004		/* 576 byte sectors */
#define	M_UF_CMPWR	0000002		/* Compare writes */
#define	M_UF_CMPRD	0000001		/* Compare reads */
E 8
I 8
#define	M_UF_REPLC	0x8000	/* Controller initiated bad block replacement */
#define	M_UF_INACT	0x4000	/* Inactive shadow set unit */
#define	M_UF_WRTPH	0x2000	/* Write protect (hardware) */
#define	M_UF_WRTPS	0x1000	/* Write protect (software or volume) */
#define	M_UF_SCCHH	0x8000	/* Suppress caching (high speed) */
#define	M_UF_SCCHL	0x4000	/* Suppress caching (low speed) */
#define	M_UF_RMVBL	0x0080	/* Removable media */
#define	M_UF_WBKNV	0x0040	/* Write back (non-volatile) */
#define	M_UF_576	0x0004	/* 576 byte sectors */
#define	M_UF_CMPWR	0x0002	/* Compare writes */
#define	M_UF_CMPRD	0x0001	/* Compare reads */
E 8

I 8
/*
 * Error Log message format codes
 */
#define	M_FM_CTLRERR	0x00	/* Controller error */
#define	M_FM_BUSADDR	0x01	/* Host memory access error */
#define	M_FM_DISKTRN	0x02	/* Disk transfer error */
#define	M_FM_SDI	0x03	/* SDI error */
#define	M_FM_SMLDSK	0x04	/* Small disk error */
E 8

/*
I 8
 * Error Log message flags
 */
#define	M_LF_SUCC	0x80	/* Operation successful */
#define	M_LF_CONT	0x40	/* Operation continuing */
#define	M_LF_SQNRS	0x01	/* Sequence number reset */

/*
E 8
 * Status codes
 */
D 8
#define	M_ST_MASK	037		/* Status code mask */
#define	M_ST_SUCC	000		/* Success */
#define	M_ST_ICMD	001		/* Invalid command */
#define	M_ST_ABRTD	002		/* Command aborted */
#define	M_ST_OFFLN	003		/* Unit offline */
#define	M_ST_AVLBL	004		/* Unit available */
#define	M_ST_MFMTE	005		/* Media format error */
#define	M_ST_WRTPR	006		/* Write protected */
#define	M_ST_COMP	007		/* Compare error */
#define	M_ST_DATA	010		/* Data error */
#define	M_ST_HSTBF	011		/* Host buffer access error */
#define	M_ST_CNTLR	012		/* Controller error */
#define	M_ST_DRIVE	013		/* Drive error */
#define	M_ST_DIAG	037		/* Message from an internal diagnostic */
E 8
I 8
#define	M_ST_MASK	0x1f	/* Status code mask */
#define	M_ST_SUCCESS	0x00	/* Success */
#define	M_ST_INVALCMD	0x01	/* Invalid command */
#define	M_ST_ABORTED	0x02	/* Command aborted */
#define	M_ST_OFFLINE	0x03	/* Unit offline */
#define	M_ST_AVAILABLE	0x04	/* Unit available */
#define	M_ST_MFMTERR	0x05	/* Media format error */
#define	M_ST_WRPROT	0x06	/* Write protected */
#define	M_ST_COMPERR	0x07	/* Compare error */
#define	M_ST_DATAERR	0x08	/* Data error */
#define	M_ST_HOSTBUFERR	0x09	/* Host buffer access error */
#define	M_ST_CTLRERR	0x0a	/* Controller error */
#define	M_ST_DRIVEERR	0x0b	/* Drive error */
#define	M_ST_DIAG	0x1f	/* Message from an internal diagnostic */
E 8

D 3

typedef	short	quad[4];		/* a word-aligned quadword */

E 3
/*
D 8
 * An MSCP packet
E 8
I 8
 * Subcodes of M_ST_OFFLINE
E 8
 */
I 8
#define	M_OFFLINE_UNKNOWN	(0 << 5) /* unknown or on other ctlr */
#define	M_OFFLINE_UNMOUNTED	(1 << 5) /* unmounted or RUN/STOP at STOP */
#define	M_OFFLINE_INOPERATIVE	(2 << 5) /* inoperative? */
#define	M_OFFLINE_DUPLICATE	(4 << 5) /* duplicate unit number */
#define	M_OFFLINE_INDIAGNOSTIC	(8 << 5) /* disabled by FS or diagnostic */
E 8

D 8
struct mscp {
	struct	mscp_header mscp_header;/* device specific header */
	long	mscp_cmdref;		/* command reference number */
	short	mscp_unit;		/* unit number */
	short	mscp_xxx1;		/* unused */
	u_char	mscp_opcode;		/* opcode */
	u_char	mscp_flags;		/* end message flags */
	short	mscp_modifier;		/* modifiers */
	union {
	struct {
		long	Mscp_bytecnt;	/* byte count */
		long	Mscp_buffer;	/* buffer descriptor */
		long	Mscp_xxx2[2];	/* unused */
		long	Mscp_lbn;	/* logical block number */
		long	Mscp_xxx4;	/* unused */
		long	*Mscp_dscptr;	/* pointer to descriptor (software) */
		long	Mscp_sftwds[4];	/* software words, padding */
	} mscp_generic;
	struct {
		short	Mscp_version;	/* MSCP version */
		short	Mscp_cntflgs;	/* controller flags */
		short	Mscp_hsttmo;	/* host timeout */
		short	Mscp_usefrac;	/* use fraction */
		long	Mscp_time;	/* time and date */
	} mscp_setcntchar;
	struct {
		short	Mscp_multunt;	/* multi-unit code */
		short	Mscp_unitflgs;	/* unit flags */
		long	Mscp_hostid;	/* host identifier */
		quad	Mscp_unitid;	/* unit identifier */
		long	Mscp_mediaid;	/* media type identifier */
		short	Mscp_shdwunt;	/* shadow unit */
		short	Mscp_shdwsts;	/* shadow status */
		short	Mscp_track;	/* track size */
		short	Mscp_group;	/* group size */
		short	Mscp_cylinder;	/* cylinder size */
		short	Mscp_xxx3;	/* reserved */
		short	Mscp_rctsize;	/* RCT table size */
		char	Mscp_rbns;	/* RBNs / track */
		char	Mscp_rctcpys;	/* RCT copies */
	} mscp_getunitsts;
	} mscp_un;
I 5
	short mscp_fil1;
	short mscp_fil2;
	short mscp_fil3;
E 8
I 8
/*
 * An MSCP packet begins with a header giving the length of
 * the entire packet (including the header itself)(?), two bytes
 * of device specific data, and the a whole bunch of variants
 * depending on message type.
 *
 * N.B.:  In most cases we distinguish between a `command' and
 * an `end' variant as well.  The command variant is that which
 * is given to the controller; the `end' variant is its response.
 */

/*
 * Generic sequential message variant (command and response).
 */
struct mscpv_seq {
	long	seq_bytecount;		/* byte count */
#define	seq_rbn		seq_bytecount	/* aka RBN (replace) */
#define	seq_outref	seq_bytecount	/* aka outref (abort/get cmd status) */
	long	seq_buffer;		/* buffer descriptor */
	long	seq_mapbase;		/* page map (first PTE) phys address */
	long	seq_xxx1;	/* ? */	/* unused */
	long	seq_lbn;		/* logical block number */
	long	seq_xxx2;	/* ? */	/* unused */
	long	*seq_addr;		/* pointer to cmd descriptor */
	long	seq_software[4];	/* reserved to software; unused */
E 8
E 5
};

I 5
D 8
#define mscp_msglen (sizeof (struct mscp) - sizeof(struct mscp_header))
E 8
I 8
/*
 * Set Controller Characteristics command variant
 */
struct mscpv_sccc {
	u_short	sccc_version;		/* MSCP version number */
	u_short	sccc_ctlrflags;		/* controller flags */
	u_short	sccc_hosttimo;		/* host timeout */
	u_short	sccc_usefrac;		/* use fraction */
	long	sccc_time;		/* time and date */
	long	sccc_xxx1;	/* ? */
	long	sccc_errlgfl;	/* ? */
	short	sccc_xxx2;	/* ? */
	short	sccc_copyspd;	/* ? */
};
E 8

E 5
/*
D 8
 * generic packet
E 8
I 8
 * Set Controller Characteristics end variant
E 8
 */
I 8
struct mscpv_scce {
	u_short	scce_version;		/* MSCP version number */
	u_short	scce_ctlrflags;		/* controller flags */
	u_short	scce_ctlrtimo;		/* controller timeout */
	u_short	scce_ctlrcmdl;		/* ??? */
	quad	scce_ctlrid;		/* controller ID */
	long	scce_xxx[3];	/* ? */
	long	scce_volser;		/* volume serial number */
};
E 8

D 8
#define	mscp_bytecnt	mscp_un.mscp_generic.Mscp_bytecnt
#define	mscp_buffer	mscp_un.mscp_generic.Mscp_buffer
#define	mscp_lbn	mscp_un.mscp_generic.Mscp_lbn
#define	mscp_dscptr	mscp_un.mscp_generic.Mscp_dscptr
#define	mscp_sftwds	mscp_un.mscp_generic.Mscp_sftwds
#define	mscp_status	mscp_modifier
E 8
I 8
/*
 * On Line command variant
 */
struct mscpv_onlc {
	long	onlc_xxx1[4];	/* ? */
	long	onlc_errlgfl;		/* error log flag? */
	short	onlc_xxx2;	/* ? */
	short	onlc_copyspd;		/* copy speed? */
};
E 8

/*
D 8
 * Abort / Get Command Status packet
E 8
I 8
 * On Line end variant
E 8
 */
I 8
struct mscpv_onle {
	long	onle_xxx1[3];	/* ? */
/*???*/	short	onle_xxx2;	/* ? */
	u_char	onle_drivetype;		/* drive type index (same in guse) */
	char	onle_xxx3;	/* ? */
	long	onle_mediaid;		/* media type id (same in guse) */
	long	onle_xxx4;	/* ? */
	long	onle_unitsize;		/* unit size in sectors */
	long	onle_volser;		/* volume serial number */
};
E 8

D 8
#define	mscp_outref	mscp_bytecnt
E 8
I 8
/*
 * Get Unit Status end variant (and Avail Attn?)
 */
struct mscpv_guse {
	u_short	guse_multunit;		/* multi-unit code */
	u_short	guse_unitflags;		/* unit flags */
	long	guse_hostid;		/* host id */
	long	guse_unitid0;	/*???*/
	short	guse_unitid1;	/*???*/
	u_char	guse_drivetype;		/* drive type index */
	u_char	guse_unitid2;	/*???*/
	long	guse_mediaid;		/* media type id (encoded) */
	short	guse_shadowunit;	/* shadow unit */
	short	guse_shadowstat;	/* shadow status */
	u_short	guse_nspt;		/* sectors per track */
	u_short	guse_group;		/* track group size */
	u_short	guse_ngpc;		/* groups per cylinder */
	u_short	guse_xxx;		/* reserved */
	u_short	guse_rctsize;		/* RCT size (sectors) */
	u_char	guse_nrpt;		/* RBNs per track */
	u_char	guse_nrct;		/* number of RCTs */
};
E 8

/*
I 9
 * Macros to break up and build media IDs.  An ID encodes the port
 * type in the top 10 bits, and the drive type in the remaining 22.
 * The 10 bits, and 15 of the 22, are in groups of 5, with the value
 * 0 representing space and values 1..26 representing A..Z.  The low
 * 7 bits represent a number in 0..127.  Hence an RA81 on a UDA50
 * is <D><U><R><A>< >81, or 0x25641051.  This encoding scheme is known
 * in part in uda.c.
 *
 * The casts below are just to make pcc generate better code.
 */
#define	MSCP_MEDIA_PORT(id)	(((long)(id) >> 22) & 0x3ff)	/* port */
#define	MSCP_MEDIA_DRIVE(id)	((long)(id) & 0x003fffff)	/* drive */
#define	MSCP_MID_ECH(n, id)	(((long)(id) >> ((n) * 5 + 7)) & 0x1f)
#define	MSCP_MID_CHAR(n, id) \
	(MSCP_MID_ECH(n, id) ? MSCP_MID_ECH(n, id) + '@' : ' ')
#define	MSCP_MID_NUM(id)	((id) & 0x7f)
/* for, e.g., RA81 */
#define	MSCP_MKDRIVE2(a, b, n) \
	(((a) - '@') << 17 | ((b) - '@') << 12 | (n))
/* for, e.g., RRD50 */
#define	MSCP_MKDRIVE3(a, b, c, n) \
	(((a) - '@') << 17 | ((b) - '@') << 12 | ((c) - '@') << 7 | (n))

/*
E 9
D 8
 * Online / Set Unit Characteristics packet
E 8
I 8
 * Error datagram variant.
E 8
 */
I 8
struct mscpv_erd {
	quad	erd_ctlrid;		/* controller ID */
	u_char	erd_ctlrsoftware;	/* controller software version */
	u_char	erd_ctlrhardware;	/* controller hardware version */
	u_short	erd_multiunit;		/* multi-unit code (?) */
	union {
		u_long	un_busaddr;	/* bus address, if mem access err */
		quad	un_unitid;	/* unit id, otherwise */
	} erd_un1;
#define	erd_busaddr	erd_un1.un_busaddr
#define	erd_unitid	erd_un1.un_unitid
	u_char	erd_unitsoftware;	/* unit software version */
	u_char	erd_unithardware;	/* unit hardware version */
	union {
		u_char	un_b[2];	/* level, retry (if disk xfer err) */
		u_short	un_s;		/* cylinder (if small disk error) */
	} erd_un2;
#define	erd_level	erd_un2.un_b[0]
#define	erd_retry	erd_un2.un_b[1]
#define	erd_sdecyl	erd_un2.un_s
	long	erd_volser;		/* volume serial number */
	u_long	erd_hdr;		/* `header' (block number) */
D 9
	char	erd_sdistat[12];	/* SDI status information (?) */
E 9
I 9
	u_char	erd_sdistat[12];	/* SDI status information (?) */
E 9
};
E 8

D 8
#define	mscp_errlgfl	mscp_lbn
#define	mscp_copyspd	mscp_shdwsts
E 8
I 8
/*
 * I am making brash assumptions about the first four bytes of all
 * MSCP packets.  These appear to be true for both UDA50s and TMSCP
 * devices (TU81, TA81, TK50).  DEC claim that these four bytes are
 * not part of MSCP itself, yet at least the length is necessary
 * for, e.g., error checking.
 */
struct mscp {
	u_short	mscp_msglen;		/* length in bytes */
	u_char	mscp_msgtc;		/* type (high 4 bits) and credits */
	u_char	mscp_vcid;		/* virtual circuit ID */
	long	mscp_cmdref;		/* command reference number */
	u_short	mscp_unit;		/* unit number */
	u_short	mscp_seqnum;		/* sequence number */
	u_char	mscp_opcode;		/* opcode */
#define	mscp_format	mscp_opcode	/* aka format (datagrams) */
	u_char	mscp_flags;		/* flags */
	u_short	mscp_modifier;		/* modifier (commands) */
#define	mscp_status	mscp_modifier	/* aka status (ends) */
#define	mscp_event	mscp_modifier	/* aka event (datagrams) */
	union {
		struct	mscpv_seq un_seq;	/* generic sequential msg */
		struct	mscpv_sccc un_sccc;	/* SCC command */
		struct	mscpv_scce un_scce;	/* SCC end */
		struct	mscpv_onlc un_onlc;	/* on line command */
		struct	mscpv_onle un_onle;	/* on line end */
		struct	mscpv_guse un_guse;	/* get unit status */
		struct	mscpv_erd un_erd;	/* error datagram */
	} mscp_un;
/*???*/	long	mscp_xxx;		/* pad to 64 bytes */
};
E 8

/*
D 8
 * Replace packet
E 8
I 8
 * Define message length according to the DEC specifications by dropping
 * the four byte header.
E 8
 */
I 8
#define	MSCP_MSGLEN	(sizeof (struct mscp) - 4)
E 8

D 8
#define	mscp_rbn	mscp_bytecnt

E 8
/*
D 8
 * Set Controller Characteristics packet
E 8
I 8
 * Shorthand
E 8
 */

D 8
#define	mscp_version	mscp_un.mscp_setcntchar.Mscp_version
#define	mscp_cntflgs	mscp_un.mscp_setcntchar.Mscp_cntflgs
#define	mscp_hsttmo	mscp_un.mscp_setcntchar.Mscp_hsttmo
#define	mscp_usefrac	mscp_un.mscp_setcntchar.Mscp_usefrac
#define	mscp_time	mscp_un.mscp_setcntchar.Mscp_time

E 8
/*
D 8
 * Get Unit Status end packet
E 8
I 8
 * Generic packet
E 8
 */
I 8
#define	mscp_seq	mscp_un.un_seq
E 8

D 8
#define	mscp_multunt	mscp_un.mscp_getunitsts.Mscp_multunt
#define	mscp_unitflgs	mscp_un.mscp_getunitsts.Mscp_unitflgs
#define	mscp_hostid	mscp_un.mscp_getunitsts.Mscp_hostid
#define	mscp_unitid	mscp_un.mscp_getunitsts.Mscp_unitid
#define	mscp_mediaid	mscp_un.mscp_getunitsts.Mscp_mediaid
#define	mscp_shdwunt	mscp_un.mscp_getunitsts.Mscp_shdwunt
#define	mscp_shdwsts	mscp_un.mscp_getunitsts.Mscp_shdwsts
#define	mscp_track	mscp_un.mscp_getunitsts.Mscp_track
#define	mscp_group	mscp_un.mscp_getunitsts.Mscp_group
#define	mscp_cylinder	mscp_un.mscp_getunitsts.Mscp_cylinder
#define	mscp_rctsize	mscp_un.mscp_getunitsts.Mscp_rctsize
#define	mscp_rbns	mscp_un.mscp_getunitsts.Mscp_rbns
#define	mscp_rctcpys	mscp_un.mscp_getunitsts.Mscp_rctcpys

E 8
/*
D 8
 * Online / Set Unit Characteristics end packet
E 8
I 8
 * Set Controller Characteristics packet
E 8
 */
I 8
#define	mscp_sccc	mscp_un.un_sccc
E 8

D 8
#define	mscp_untsize	mscp_dscptr
#define	mscp_volser	mscp_sftwds[0]

E 8
/*
 * Set Controller Characteristics end packet
 */
I 8
#define	mscp_scce	mscp_un.un_scce
E 8

D 8
#define	mscp_cnttmo	mscp_hsttmo
#define	mscp_cntcmdl	mscp_usefrac
#define	mscp_cntid	mscp_unitid
E 8
I 8
/*
 * Online / Set Unit Characteristics command packet
 */
#define	mscp_onlc	mscp_un.un_onlc
E 8

D 8

E 8
/*
D 8
 * Error Log message format codes
E 8
I 8
 * Online end packet
E 8
 */
D 8
#define	M_FM_CNTERR	0	/* Controller error */
#define	M_FM_BUSADDR	1	/* Host memory access error */
#define	M_FM_DISKTRN	2	/* Disk transfer error */
#define	M_FM_SDI	3	/* SDI error */
#define	M_FM_SMLDSK	4	/* Small disk error */
E 8
I 8
#define	mscp_onle	mscp_un.un_onle
E 8

/*
D 8
 * Error Log message flags
E 8
I 8
 * Get Unit Status end packet
E 8
 */
D 8
#define	M_LF_SUCC	0200	/* Operation successful */
#define	M_LF_CONT	0100	/* Operation continuing */
#define	M_LF_SQNRS	0001	/* Sequence number reset */
E 8
I 8
#define	mscp_guse	mscp_un.un_guse
E 8

/*
 * MSCP Error Log packet
D 8
 *
 *	NOTE: MSCP packet must be padded to this size.
E 8
 */
I 8
#define	mscp_erd	mscp_un.un_erd
E 8

D 8
struct mslg {
	struct	mscp_header mslg_header;/* device specific header */
	long	mslg_cmdref;		/* command reference number */
	short	mslg_unit;		/* unit number */
	short	mslg_seqnum;		/* sequence number */
	u_char	mslg_format;		/* format */
	u_char	mslg_flags;		/* error log message flags */
	short	mslg_event;		/* event code */
	quad	mslg_cntid;		/* controller id */
	u_char	mslg_cntsvr;		/* controller software version */
	u_char	mslg_cnthvr;		/* controller hardware version */
	short	mslg_multunt;		/* multi-unit code */
	quad	mslg_unitid;		/* unit id */
	u_char	mslg_unitsvr;		/* unit software version */
	u_char	mslg_unithvr;		/* unit hardware version */
D 2
	short	mslg_group;		/* group */
E 2
I 2
	short	mslg_group;		/* group; retry + level */
E 2
	long	mslg_volser;		/* volume serial number */
D 2
	long	mslg_cylinder;		/* cylinder */
	short	mslg_track;		/* track */
	short	mslg_sector;		/* sector */
	long	mslg_lbn;		/* logical block number */
	u_char	mslg_level;		/* level */
	u_char	mslg_retry;		/* retry */
E 2
I 2
	long	mslg_hdr;		/* header */
	char	mslg_sdistat[12];	/* SDI status information */
E 2
};
E 8
I 8
/*
 * MSCP seq_addr field actually belongs to overall packet.
 */
#define	mscp_addr	mscp_seq.seq_addr
E 8

D 3
#define	mslg_busaddr	mslg_unitid
E 3
I 3
D 8
#define	mslg_busaddr	mslg_unitid.val[0]
E 3
#define	mslg_sdecyl	mslg_group
E 8
I 8
/*
 * Macros to break up mscp_msgtc, and types.
 */
#define	MSCP_MSGTYPE(m)	((m) & 0xf0)
#define	MSCP_CREDITS(m)	((m) & 0x0f)
E 8
I 5

I 8
#define	MSCPT_SEQ		0x00	/* sequential message */
#define	MSCPT_DATAGRAM		0x10	/* error datagram */
#define	MSCPT_CREDITS		0x20	/* credit notification */
#define	MSCPT_MAINTENANCE	0xf0	/* who knows */


/*
 * Here begin more perhaps brash assumptions about MSCP devices...
 */

/*
 * MSCP controllers have `command rings' and `response rings'.  A
 * command ring is a pool of MSCP packets that the host uses to give
 * commands to the controller; a response ring is a pool of MSCP
 * packets that the controller uses to give back responses.  Entries
 * in the command and response rings are `owned' by either the host
 * or the controller; only the owner is allowed to alter any of the
 * fields in the MSCP packet.  Thus, free command packets are owned
 * by the host, and free response packets by the controller.  When
 * the host gives a packet to the controller, it tells the controller
 * by touching a device register; when the controller gives a response
 * to the host, it generates an interrupt if enabled, and sets
 * a device register as well.
 *
 * The pool is `described' by a set of pointers to the packets, along
 * with the two flags below.
 */
#define	MSCP_OWN	0x80000000	/* controller owns this packet */
#define	MSCP_INT	0x40000000	/* controller should interrupt */
E 8
E 5
E 1
