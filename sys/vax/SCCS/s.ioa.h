h45318
s 00007/00004/00084
d D 7.2 86/08/09 15:12:22 karels 6 5
c add ifdefs for 8600 only
e
s 00000/00000/00088
d D 7.1 86/06/05 00:44:06 mckusick 5 4
c 4.3BSD release version
e
s 00024/00021/00064
d D 1.4 86/04/28 02:00:17 kjd 4 3
c Add DEC copyright
e
s 00000/00003/00085
d D 1.3 86/02/23 23:06:12 karels 3 2
c lint
e
s 00005/00002/00083
d D 1.2 85/08/05 12:23:05 bloom 2 1
c changes for berkeley support of 8600
e
s 00085/00000/00000
d D 1.1 85/08/05 12:18:23 bloom 1 0
c Version from ULTRIX sccs version 1.2 2/11/85
e
u
U
t
T
I 1
/*
 * %W% (Berkeley) %G%
 */
D 4
/************************************************************************
 *									*
 *			Copyright (c) 1983 by				*
 *		Digital Equipment Corporation, Maynard, MA		*
 *			All rights reserved.				*
 *									*
 *   This software is furnished under a license and may be used and	*
 *   copied  only  in accordance with the terms of such license and	*
 *   with the  inclusion  of  the  above  copyright  notice.   This	*
 *   software  or  any  other copies thereof may not be provided or	*
 *   otherwise made available to any other person.  No title to and	*
 *   ownership of the software is hereby transferred.			*
 *									*
 *   The information in this software is subject to change  without	*
 *   notice  and should not be construed as a commitment by Digital	*
 *   Equipment Corporation.						*
 *									*
 *   Digital assumes no responsibility for the use  or  reliability	*
 *   of its software on equipment which is not supplied by Digital.	*
 *									*
 ************************************************************************/
E 4
I 4

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
 *								*
 ****************************************************************/
E 4

D 6
#define	MAXNIOA 4
#define	NIOA8600 2
#define IOASIZE 0x2000000
#define IOAMAPSIZ 512			/* Map one page to get at SBIA regs */
E 6
I 6
#if VAX8600
#define	MAXNIOA		4
#define	NIOA8600	2
#define IOASIZE		0x2000000
#define IOAMAPSIZ 	512		/* Map one page to get at SBIA regs */
E 6
D 2
#define	IOA8600(i)	((short *)(0x20080000+IOASIZE*i))
E 2
I 2
#define	IOA8600(i)	((caddr_t)(0x20080000+IOASIZE*i))
E 2

#ifndef LOCORE
struct	sbia_regs
{
	int sbi_cfg;
	int sbi_csr;
	int sbi_errsum;
	int sbi_dctl;
	int sbi_dmaica;
	int sbi_dmaiid;
	int sbi_dmaaca;
	int sbi_dmaaid;
	int sbi_dmabcs;
	int sbi_dmabid;
	int sbi_dmaccs;
	int sbi_dmacid;
	int sbi_silo;
	int sbi_error;
	int sbi_timo;
	int sbi_fltsts;
	int sbi_silcmp;
	int sbi_maint;
	int sbi_unjam;
	int sbi_qclr;
	int sbi_unused[12];
	int sbi_iv10;
	int sbi_iv11;
	int sbi_iv12;
	int sbi_iv13;
	int sbi_iv14;
	int sbi_iv15;
	int sbi_iv16;
	int sbi_iv17;
	int sbi_iv18;
	int sbi_iv19;
	int sbi_iv1a;
	int sbi_iv1b;
	int sbi_iv1c;
	int sbi_iv1d;
	int sbi_iv1e;
};
struct	ioa {
	union ioacsr {
		long	ioa_csr;
		u_char	ioa_type;
	} ioacsr;
	long	ioa_pad[IOAMAPSIZ / sizeof (long) - 1];
};
#ifdef	KERNEL
struct ioa ioa[MAXNIOA];
#endif  KERNEL
#endif	LOCORE

#define IOA_TYPMSK 0xf0
D 2
#define IOA_SBIA 0x10
E 2
I 2
#define IOA_SBIA	0x10
I 6

#endif VAX8600
E 6
D 3
#define IOA_SBI780	0x01
#define IOA_CMI750	0x02
#define IOA_XXX730	0x04
E 3
E 2
E 1
