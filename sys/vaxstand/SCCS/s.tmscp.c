h34832
s 00001/00001/00278
d D 7.4 89/01/06 11:26:52 mckusick 5 4
c handle other than uba0 (4.3BSD-tahoe/sys/32)
e
s 00046/00069/00233
d D 7.3 88/03/04 14:06:09 bostic 4 3
c handle new device spec, remove tmscpioctl, reformat a bit
e
s 00015/00012/00287
d D 7.2 88/01/28 20:53:25 karels 3 2
c uvax changes; fix devsw index in confxx; header updates
e
s 00000/00000/00299
d D 7.1 86/06/05 01:45:55 mckusick 2 1
c 4.3BSD release version
e
s 00299/00000/00000
d D 1.1 86/04/28 14:08:01 kjd 1 0
c date and time created 86/04/28 14:08:01 by kjd
e
u
U
t
T
I 1

/*	%W% (Berkeley) %G% */

/****************************************************************
 *                                                              *
 *        Licensed from Digital Equipment Corporation           *
 *                       Copyright (c)                          *
 *               Digital Equipment Corporation                  *
 *                   Maynard, Massachusetts                     *
 *                         1985, 1986                           *
 *                    All rights reserved.                      *
 *                                                              *
 *        The Information in this software is subject to change *
 *   without notice and should not be construed as a commitment *
 *   by  Digital  Equipment  Corporation.   Digital   makes  no *
 *   representations about the suitability of this software for *
 *   any purpose.  It is supplied "As Is" without expressed  or *
 *   implied  warranty.                                         *
 *                                                              *
 *        If the Regents of the University of California or its *
 *   licensees modify the software in a manner creating         *
 *   diriviative copyright rights, appropriate copyright        *
 *   legends may be placed on  the drivative work in addition   *
 *   to that set forth above.                                   *
 ***************************************************************/
/*
 * tmscp.c - TMSCP (TK50/TU81) standalone driver
 */
 
# ifndef lint
static char *sccsid = "@(#)tmscp.c	1.5	(ULTRIX)	4/18/86";
# endif not lint
 
/* ------------------------------------------------------------------------
 * Modification History: /sys/stand/tmscp.c
 *
 * 3-15-85  afd
 *	Don't ask for an interrupt when commands are issued and
 *	check ownership bit in the response descriptor to detect when a
 *	command is complete.  Necessary due to the TU81's failure to set
 *	the response interrupt field in the communications area.
 *
 * ------------------------------------------------------------------------
 */
 
D 3
#include "../machine/pte.h"
E 3
D 4
 
E 4
D 3
#include "../h/param.h"
#include "../h/gnode.h"
#include "../h/devio.h"
 
E 3
I 3
#include "param.h"
#include "inode.h"
#include "fs.h"

#include "../vax/pte.h"

E 3
#include "savax.h"
D 3
 
E 3
#include "saio.h"
 
/*
 * Parameters for the communications area
 * (Only 1 cmd & 1 rsp packet)
 */
#define	NRSPL2	0
#define	NCMDL2	0
#define	NRSP	(1<<NRSPL2)
#define	NCMD	(1<<NCMDL2)
 
#include "../vaxuba/tmscpreg.h"
#include "../vaxuba/ubareg.h"
#include "../vax/tmscp.h"
 
D 4
u_short tmscpstd[] = { 0174500 };
E 4
I 4
#define	MAXCTLR		1		/* all addresses must be specified */
u_short tmscpstd[MAXCTLR] = { 0174500 };
E 4
 
struct iob	ctmscpbuf;
 
struct tmscpdevice *tmscpaddr = 0;
 
struct tmscp {
	struct tmscpca	tmscp_ca;
	struct mscp	tmscp_rsp;
	struct mscp	tmscp_cmd;
D 4
	} tmscp;
E 4
I 4
} tmscp;
E 4
 
struct tmscp *tmscp_ubaddr;		/* Unibus address of tmscp structure */
 
struct mscp *tmscpcmd();
 
int tmscp_offline = 1;		/* Flag to prevent multiple STCON */
int tms_offline[4] = {1,1,1,1}; /* Flag to prevent multiple ONLIN */
 
D 4
 
E 4
/*
 * Open a tmscp device. Initialize the controller and set the unit online.
 */
tmscpopen(io)
	register struct iob *io;
{
	register struct mscp *mp;
	int i;
 
I 4
	if ((u_int)io->i_ctlr >= MAXCTLR)
		return (ECTLR);
E 4
	/*
	 * Have the tmscp controller characteristics already been set up
	 * (STCON)?
	 */
D 4
	if (tmscp_offline)
		{
E 4
I 4
	if (tmscp_offline) {
E 4
		if (tmscpaddr == 0)
D 4
			tmscpaddr = (struct tmscpdevice *)ubamem(io->i_unit, tmscpstd[0]);
		if (tmscp_ubaddr == 0)
			{
E 4
I 4
			tmscpaddr = (struct tmscpdevice *)ubamem(io->i_adapt, tmscpstd[0]);
		if (tmscp_ubaddr == 0) {
E 4
D 5
			ctmscpbuf.i_unit = io->i_unit;
E 5
I 5
			ctmscpbuf = *io;
E 5
			ctmscpbuf.i_ma = (caddr_t)&tmscp;
			ctmscpbuf.i_cc = sizeof(tmscp);
			tmscp_ubaddr = (struct tmscp *)ubasetup(&ctmscpbuf, 2);
D 4
			}
E 4
I 4
		}
E 4
		/*
		 * Initialize the tmscp device and wait for the 4 steps
		 * to complete.
		 */
		tmscpaddr->tmscpip = 0;
D 4
		while ((tmscpaddr->tmscpsa & TMSCP_STEP1) == 0)
			;
E 4
I 4
		while ((tmscpaddr->tmscpsa & TMSCP_STEP1) == 0);
E 4
		tmscpaddr->tmscpsa =TMSCP_ERR|(NCMDL2<<11)|(NRSPL2<<8);
 
D 4
		while ((tmscpaddr->tmscpsa & TMSCP_STEP2) == 0)
			;
E 4
I 4
		while ((tmscpaddr->tmscpsa & TMSCP_STEP2) == 0);
E 4
#		define STEP1MASK 0174377
#		define STEP1GOOD (TMSCP_STEP2|TMSCP_IE|(NCMDL2<<3)|NRSPL2)
		if ((tmscpaddr->tmscpsa&STEP1MASK) != STEP1GOOD)
			printf("tmscpopen: step 1 not successful sa=%o\n",tmscpaddr->tmscpsa&0xffff);
		tmscpaddr->tmscpsa = (short)&tmscp_ubaddr->tmscp_ca.ca_ringbase;
 
D 4
		while ((tmscpaddr->tmscpsa & TMSCP_STEP3) == 0)
			;
E 4
I 4
		while ((tmscpaddr->tmscpsa & TMSCP_STEP3) == 0);
E 4
#		define STEP2MASK 0174377
#		define STEP2GOOD (TMSCP_STEP3)
		if ((tmscpaddr->tmscpsa&STEP2MASK) != STEP2GOOD)
			printf("tmscpopen: step 2 not successful sa=%o\n",tmscpaddr->tmscpsa&0xffff);
		tmscpaddr->tmscpsa = (short)(((int)&tmscp_ubaddr->tmscp_ca.ca_ringbase) >> 16);
 
D 4
		while ((tmscpaddr->tmscpsa & TMSCP_STEP4) == 0)
			;
E 4
I 4
		while ((tmscpaddr->tmscpsa & TMSCP_STEP4) == 0);
E 4
#		define STEP3MASK 0174000
#		define STEP3GOOD TMSCP_STEP4
		if ((tmscpaddr->tmscpsa&STEP3MASK) != STEP3GOOD)
			printf("tmscpopen: step 3 not successful sa=%o\n",tmscpaddr->tmscpsa&0xffff);
		tmscpaddr->tmscpsa = TMSCP_GO;
 
		/*
		 * Init cmd & rsp area
		 */
		tmscp.tmscp_ca.ca_cmddsc[0] = (long)&tmscp_ubaddr->tmscp_cmd.mscp_cmdref;
		tmscp.tmscp_cmd.mscp_dscptr = tmscp.tmscp_ca.ca_cmddsc;
		tmscp.tmscp_cmd.mscp_header.tmscp_vcid = 1;	/* for tape */
 
		tmscp.tmscp_ca.ca_rspdsc[0] = (long)&tmscp_ubaddr->tmscp_rsp.mscp_cmdref;
		tmscp.tmscp_rsp.mscp_dscptr = tmscp.tmscp_ca.ca_rspdsc;
		tmscp.tmscp_cmd.mscp_cntflgs = 0;
D 4
		if (tmscpcmd(M_OP_STCON, 0) == 0)
			{
E 4
I 4
		if (tmscpcmd(M_OP_STCON, 0) == 0) {
E 4
D 3
			_stop("tms: open error, STCON");
			return;
E 3
I 3
			printf("tms: open error, STCON\n");
			return (EIO);
E 3
D 4
			}
		tmscp_offline = 0;
E 4
		}
I 4
		tmscp_offline = 0;
	}
E 4
	tmscp.tmscp_cmd.mscp_unit = io->i_unit&03;
	/* 
	 * Has this unit been issued an ONLIN?
	 */
D 4
	if (tms_offline[tmscp.tmscp_cmd.mscp_unit])
		{
		if ((mp = tmscpcmd(M_OP_ONLIN, 0)) == 0)
			{
E 4
I 4
	if (tms_offline[tmscp.tmscp_cmd.mscp_unit]) {
		if ((mp = tmscpcmd(M_OP_ONLIN, 0)) == 0) {
E 4
D 3
			_stop("tms: open error, ONLIN");
			return;
E 3
I 3
			_stop("tms: open error, ONLIN\n");
			return (EIO);
E 3
D 4
			}
		tms_offline[tmscp.tmscp_cmd.mscp_unit] = 0;
E 4
		}
D 3
	if (io->i_boff < 0 || io->i_boff > 3)
		_stop("tms: bad offset");
E 3
I 3
D 4
	if (io->i_boff < 0 || io->i_boff > 3) {
		printf("tms: bad offset\n");
		return (EUNIT);
E 4
I 4
		tms_offline[tmscp.tmscp_cmd.mscp_unit] = 0;
E 4
	}
E 3
D 4
	else if (io->i_boff > 0)
E 4
I 4
	/*
	 * This makes no sense, but I could be wrong... KB
	 *
	 *	if ((u_int)io->i_part > 3)
	 *		return (EPART);
	 */
	if (io->i_part) {
E 4
		/*
		 * Skip forward the appropriate number of files on the tape.
		 */
D 4
		{
		tmscp.tmscp_cmd.mscp_tmkcnt = io->i_boff;
		tmscpcmd(M_OP_REPOS, 0);
E 4
I 4
		tmscp.tmscp_cmd.mscp_tmkcnt = io->i_part;
		(void)tmscpcmd(M_OP_REPOS, 0);
E 4
		tmscp.tmscp_cmd.mscp_tmkcnt = 0;
D 4
		}
E 4
I 4
	}
E 4
I 3
	return (0);
E 3
}
 
D 4
 
E 4
/*
 * Close the device (rewind it to BOT)
 */
tmscpclose(io)
	register struct iob *io;
{
D 4
	tmscpcmd(M_OP_REPOS, M_MD_REWND);
E 4
I 4
	(void)tmscpcmd(M_OP_REPOS, M_MD_REWND);
E 4
}
 
D 4
 
E 4
/*
 * Set up tmscp command packet.  Cause the controller to poll to pick up
 * the command.
 */
struct mscp *
tmscpcmd(op,mod)
	int op, mod;			/* opcode and modifier (usu 0) */
{
	struct mscp *mp;		/* ptr to cmd packet */
	int i;				/* read into to init polling */
 
	tmscp.tmscp_cmd.mscp_opcode = op;
	tmscp.tmscp_cmd.mscp_modifier = mod;
	tmscp.tmscp_cmd.mscp_header.tmscp_msglen = mscp_msglen;
	tmscp.tmscp_ca.ca_cmddsc[0] |= TMSCP_OWN;	/* | TMSCP_INT */
	tmscp.tmscp_rsp.mscp_header.tmscp_msglen = mscp_msglen;
	tmscp.tmscp_ca.ca_rspdsc[0] |= TMSCP_OWN;	/* | TMSCP_INT */
 
	i = tmscpaddr->tmscpip;
D 4
	for (;;)
		{
		if (tmscpaddr->tmscpsa & TMSCP_ERR)
			{
E 4
I 4
	for (;;) {
		if (tmscpaddr->tmscpsa & TMSCP_ERR) {
E 4
			printf("tmscpcmd: Fatal error sa=%o\n", tmscpaddr->tmscpsa & 0xffff);
			return(0);
D 4
			}
E 4
I 4
		}
E 4
 
		if (tmscp.tmscp_ca.ca_cmdint)
			tmscp.tmscp_ca.ca_cmdint = 0;
		/*
		 * This is to handle the case of devices not setting the
		 * interrupt field in the communications area. Some
		 * devices (early TU81's) only clear the ownership field
		 * in the Response Descriptor.
I 4
		 *
		 *
		 *	if (tmscp.tmscp_ca.ca_rspint)
		 *		break;
E 4
		 */
D 4
/*
		if (tmscp.tmscp_ca.ca_rspint)
			break;
*/
E 4
		if (!(tmscp.tmscp_ca.ca_rspdsc[0] & (TMSCP_OWN)))
			break;
D 4
		}
E 4
I 4
	}
E 4
	tmscp.tmscp_ca.ca_rspint = 0;
	mp = &tmscp.tmscp_rsp;
	if (mp->mscp_opcode != (op|M_OP_END) ||
D 4
	   (mp->mscp_status&M_ST_MASK) != M_ST_SUCC)
		{
		/* Detect hitting tape mark.  This signifies the end of the
E 4
I 4
	   (mp->mscp_status&M_ST_MASK) != M_ST_SUCC) {
		/*
		 * Detect hitting tape mark.  This signifies the end of the
E 4
		 * tape mini-root file.  We don't want to return an error
		 * condition to the strategy routine.
		 */
D 4
		if ((mp->mscp_status & M_ST_MASK) == M_ST_TAPEM)
			return(mp);
		return(0);
		}
E 4
I 4
		if ((mp->mscp_status & M_ST_MASK) != M_ST_TAPEM)
			return(0);
	}
E 4
	return(mp);
}
 
D 4
 
E 4
/*
 * Set up to do reads and writes; call tmscpcmd to issue the cmd.
 */
tmscpstrategy(io, func)
	register struct iob *io;
	int func;
{
	register struct mscp *mp;
	int ubinfo;
 
	ubinfo = ubasetup(io, 1);
	mp = &tmscp.tmscp_cmd;
	mp->mscp_lbn = io->i_bn;
	mp->mscp_unit = io->i_unit&03;
	mp->mscp_bytecnt = io->i_cc;
	mp->mscp_buffer = (ubinfo & 0x3fffff) | (((ubinfo>>28)&0xf)<<24);
D 4
	if ((mp = tmscpcmd(func == READ ? M_OP_READ : M_OP_WRITE, 0)) == 0)
		{
E 4
I 4
	if ((mp = tmscpcmd(func == READ ? M_OP_READ : M_OP_WRITE, 0)) == 0) {
E 4
		ubafree(io, ubinfo);
		printf("tms: I/O error\n");
		return(-1);
D 4
		}
E 4
I 4
	}
E 4
	ubafree(io, ubinfo);
	/*
	 * Detect hitting tape mark so we do it gracefully and return a
	 * character count of 0 to signify end of copy.  Rewind the tape
	 * before returning.
	 */
	if ((mp->mscp_status & M_ST_MASK) == M_ST_TAPEM)
		return(0);
	return(io->i_cc);
D 4
}
 
/*ARGSUSED*/
tmscpioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{
	return (ECMD);
E 4
}
E 1
