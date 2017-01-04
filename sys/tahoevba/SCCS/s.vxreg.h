h62386
s 00010/00005/00146
d D 7.2 88/06/29 17:51:19 bostic 7 6
c install approved copyright notice
e
s 00013/00001/00138
d D 7.1 88/05/21 18:33:29 karels 6 5
c bring up to revision 7 for tahoe release
e
s 00027/00002/00112
d D 1.5 87/01/11 21:23:54 karels 5 4
c more or less 4.3
e
s 00044/00044/00070
d D 1.4 86/01/23 01:09:14 sam 4 3
c put back tabs
e
s 00008/00008/00106
d D 1.3 86/01/21 17:43:02 sam 3 2
c fix tabs
e
s 00093/00127/00021
d D 1.2 86/01/13 12:01:19 sam 2 1
c merge vc?.c files and rename  lots of stuff to ease identification;
c merge all the separate data structures into vx_softc; rename vxblok vxdevice;
c and lots more...
e
s 00148/00000/00000
d D 1.1 85/07/21 20:36:06 sam 1 0
c date and time created 85/07/21 20:36:06 by sam
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
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
 *
 *	%W% (Berkeley) %G%
 */
E 6

D 2
#define V_RESETTING 1		/* in process of reseting */
#define V_RESET 1		/* cause a vioc reset */
#define V_TRP	2		/* cause a vioc trap */
#define V_INTR	4		/* cause a vioc interrupt */
#define V_ERR	0x80		/* generic error flag */
#define V_BSY	0x80		/* generic busy flag */
#define V_UNBSY	0x80		/* not busy for unsolicited interrupt */

#define	VCVECT	0x40 		/* base vioc vector */

#define	VBAS(x)  ( (struct vblok *)(VIOCBAS[x]) )

#define	NVIOCX NVX		/* nbr of viocx's - defined by config in vx.h */
#define NVXPORTS 16*NVIOCX	/* Total nbr of viocx terminal ports */
#define NVCXBUFS 16*3		/* 3 bufs per port per viocx */
#define	VREADY 0x55		/* denotes no err in vioc self-initializaton */
#define PVIOCX	0x0A		/* old connector panel vioc-x */
#define VIOCX	0x0B		/* new (modular) connector panel vioc-x */
#define	NPVIOCX	0x1A		/* new pviocx */
#define	NWVIOCX	0x1B		/* new viocx */
#define	VBOPID	0x5		/* Vioc-bop */

#include "vbsc.h"
#if NVBSC > 0
#define VIOCB	0x0C
#define NWVIOCB 0x1C
#define BISYNC 0x1
#define LPARAX1 0x060a
#define MDMCTL1 0x1004
#define HUNTMD1 0x0804
#endif


#define	V_NEW	1		/* NPVIOCX | NVIOCX */
#define	V_OLD	0		/* PVIOCX | VIOCX */
/* Modem Control flags */
#define VMOD_ON 1
#define VMOD_OFF 0

#define VRESPLEN 12
#define VCMDLEN 64
#define VC_IQLEN 64			/* Interrupt circular queue length */
#define VC_CMDBUFL NVCXBUFS		/* circular cmd (to exec) queue len*/

#define SSPEED	13		/* standard speed 9600 bps */

#define V_ENAB	0002	/* auto + DTR */
#define V_DISAB	0000	/* auto + disable DTR */

#define BRK_CHR	040
#define DCD_ON	020
#define DCD_OFF	010
#define	CTS_ON	004
#define DSR_ON	0200	/* modem signal states for bisync */
#define DSR_OFF 0100
#define DSR_CHG	(DSR_ON | DSR_OFF)

#define SILOBAS 0x800
/* Command Operation Codes */
#define LIDENT	0x0000		/* load ident, set int vectors */
#define XMITDTA	0x0200		/* transmit */
#define XMITIMM	0x0400		/* xmit immediate */
#define FDTATOX	0x0300		/* flush data */
#define	LPARAX	0x0600		/* load params */
#define SNDBRKX	0x0C00		/* send break to port */
#define MDMCTL	0x1000		/* auto modem control */

#define PERROR	0x40
#define FERROR	0x80
#define RCVOVRN	0xc0

E 2
/*
D 2
 * Data Structures
E 2
I 2
 * Vioc hardware interface structure.
E 2
 */
D 2

struct	vblok	{		/* command sent to vioc  */
	char	v_vioc;		/*  0 type of interrupt + voic bsy flg */
E 2
I 2
struct	vxdevice {
	char	v_vioc;		/*  0 type of interrupt + vioc busy flag */
E 2
	char	v_hdwre;	/*  1 trap, reset, or hard interrupt */
	char	v_vcbsy;	/*  2 command busy (set by host) */
D 2
	char	v_vcid;		/*  3 command id. */
E 2
I 2
	char	v_vcid;		/*  3 command identifier */
E 2
	short	v_vcp[2];	/*  4 command pointer (sent by host) */
	short	v_unused;	/*  8 unused */
	short	v_rspoff;	/*  a offset into vblock for response buf */
	char	v_ustat;	/*  c status */
D 2
	char	v_uqual;	/*  d qualifies the interrupt */
E 2
I 2
	char	v_uqual;	/*  d interrupt qualifier */
E 2
	char	v_usdata[0x3E];	/*  e unsolicited interrupt data */
D 2
	short	v_maxxmt ;	/* 4C max xmit block size */
	short	v_maxsilo ;	/* 4E max silo size */
	char	v_ident ;	/* 50 identifies type of vioc */
	char	v_fault ;	/* 51 denotes fault or ready after reset */
	short	v_dcd ;		/* 52 bit mask for carr detect by port */
	short	v_cts ;		/* 54 bit mask for cts by port */
E 2
I 2
	short	v_maxxmt;	/* 4C max xmit block size */
	short	v_maxsilo;	/* 4E max silo size */
	char	v_ident;	/* 50 identifies type of vioc */
	char	v_fault;	/* 51 denotes fault or ready after reset */
	short	v_dcd;		/* 52 bit mask for carr detect by port */
	short	v_cts;		/* 54 bit mask for cts by port */
E 2
	short	v_dsr;		/* 56 bit mask for dsr by port */
	short	v_secrec;	/* 58 bit mask for secondary receive */
	short	v_badport;	/* 5a bit mask of failed ports */
	char	v_portyp[16];	/* 5c type of each port */
D 2
} ;
E 2
I 2
};
E 2

D 2
struct	vcmds	{
	int	v_cmdsem;		/* cmds waiting for itrque */
	int	v_curcnt;		/* count of cmds in itrque and executing */
	caddr_t	v_curcmd[VCMDLEN] ;	/* pointers to cmds being executed */
	int	v_fill ;		/* circular fill index */
	int	v_empty ;		/* circular empty index */
	caddr_t	cmdbuf[VC_CMDBUFL] ;	/* circular cmd (to exec) queue */
	int	v_itrfill ;		/* circular intr issue queue fill */
	int	v_itrempt ;		/* circular intr issue queue empty */
	short	v_itrqueu[VC_IQLEN] ;	/* circular intr issue queue */
} ;
E 2
I 2
/* control bits for v_vioc and v_hdwre */
D 4
#define V_RESET 0x1		/* cause a vioc reset */
#define V_TRP	0x2		/* cause a vioc trap */
#define V_INTR	0x4		/* cause a vioc interrupt */
#define V_ERR	0x80		/* generic error flag */
#define V_BSY	0x80		/* generic busy flag */
#define V_UNBSY	0x80		/* not busy for unsolicited interrupt */
E 4
I 4
#define	V_RESET 0x1		/* cause a vioc reset */
#define	V_TRP	0x2		/* cause a vioc trap */
#define	V_INTR	0x4		/* cause a vioc interrupt */
#define	V_ERR	0x80		/* generic error flag */
#define	V_BSY	0x80		/* generic busy flag */
#define	V_UNBSY	0x80		/* not busy for unsolicited interrupt */
E 4
E 2

D 2
struct	vxcmd	{
	struct	vxcmd	*c_fwd ;
	short	cmd ;
	char	par[58] ; /* 64 total size */
} ;
E 2
I 2
/* command identifier codes */
D 4
#define VXC_LIDENT	0x0000		/* load ident, set int vectors */
#define VXC_XMITDTA	0x0200		/* transmit */
#define VXC_XMITIMM	0x0400		/* xmit immediate */
#define VXC_FDTATOX	0x0300		/* flush data */
D 3
#define	VXC_LPARAX	0x0600		/* load params */
E 3
I 3
#define VXC_LPARAX	0x0600		/* load params */
E 3
#define VXC_SNDBRKX	0x0C00		/* send break to port */
#define VXC_MDMCTL	0x1000		/* auto modem control */
E 4
I 4
#define	VXC_LIDENT	0x0000		/* load ident, set int vectors */
#define	VXC_XMITDTA	0x0200		/* transmit */
#define	VXC_XMITIMM	0x0400		/* xmit immediate */
#define	VXC_FDTATOX	0x0300		/* flush data */
#define	VXC_LPARAX	0x0600		/* load params */
#define	VXC_SNDBRKX	0x0C00		/* send break to port */
#define	VXC_MDMCTL	0x1000		/* auto modem control */
E 4
/* bisync specific command identifiers */
D 4
#define VXC_LPARAX1	0x060a
#define VXC_MDMCTL1	0x1004
#define VXC_HUNTMD1	0x0804
E 4
I 4
#define	VXC_LPARAX1	0x060a
#define	VXC_MDMCTL1	0x1004
#define	VXC_HUNTMD1	0x0804
E 4
E 2

D 2
struct	vxmit	{
	char	line ;
	char	bcount ;
	char	ostream[6] ;
} ;
/* should be sizeof(struct vxmit), but has alignment problems */
#define sizvxmit 6
E 2
I 2
/* vioc types returned during config */
D 3
#define	VXT_VIOCBOP	0x05		/* vioc-bop */
E 3
I 3
D 4
#define VXT_VIOCBOP	0x05		/* vioc-bop */
E 3
#define VXT_PVIOCX	0x0A		/* old connector panel vioc-x */
#define VXT_VIOCX	0x0B		/* new connector panel vioc-x */
#define VXT_VIOCB	0x0C		/* vioc-bisync */
D 3
#define	VXT_NEW		0x10		/* new type bit (or'd in) */
E 3
I 3
#define VXT_NEW		0x10		/* new type bit (or'd in) */
E 4
I 4
#define	VXT_VIOCBOP	0x05		/* vioc-bop */
#define	VXT_PVIOCX	0x0A		/* old connector panel vioc-x */
#define	VXT_VIOCX	0x0B		/* new connector panel vioc-x */
#define	VXT_VIOCB	0x0C		/* vioc-bisync */
#define	VXT_NEW		0x10		/* new type bit (or'd in) */
E 4
E 3
E 2

D 2
struct	vcx	{
	char	v_loport ;	/* low port nbr */
	char	v_hiport ;	/* high port nbr */
	short	v_nbr ;		/* viocx number */
	short	v_maxcmd ;	/* max number of concurrent cmds */
	short	v_silosiz ;	/* silo size */
	short	v_vers ;	/* vioc/pvioc version */
	char	v_actflg ;	/* active command */
	char	v_xmtcnt ;	/* xmit commands pending */
	char	v_actport[16] ;	/* act flag per port per port */
	short	v_brkreq ;	/* send break requests pending */
	struct	vxcmd	*vx_avail ;
	struct	vxcmd	*vx_build ;
	struct	vxcmd	vx_lst[NVCXBUFS] ;
	short 	v_state;
	caddr_t v_mricmd;	/* Most recent issued cmd */
E 2
I 2
D 4
#define VX_BISYNC	0x1		/* bisync flag indicator for bscport */
E 4
I 4
#define	VX_BISYNC	0x1		/* bisync flag indicator for bscport */
E 4

I 5
/* connector panel types (per port) */
#define	VXT_NONE	0		/* no connector panel */
#define	VXT_8PORT	1		/* 8 port RS-232C */
#define	VXT_RS422	2		/* 8 port RS-422 (nonexistent) */
#define	VXT_4PORT	3		/* 4 port RS-232 (with DSR/RING) */
#define	VXT_PARALLEL	4		/* 4 port panel parallel port */

E 5
/* v_fault status values */
D 3
#define	VXF_READY	0x55		/* no err in vioc self-initializaton */
E 3
I 3
D 4
#define VXF_READY	0x55		/* no err in vioc self-initializaton */
E 4
I 4
#define	VXF_READY	0x55		/* no err in vioc self-initializaton */
E 4
E 3

I 5
/* line parameters, set with VXC_LPARAX */
#define	BITS5		0x00		/* 5 bits per character */
#define	BITS6		0x80		/* 6 bits per character */
#define	BITS7		0x40		/* 7 bits per character */
#define	BITS8		0xc0		/* 8 bits per character */

#define	VNOPARITY	0x00		/* no parity bit */
#define	VODDP		0x01		/* odd parity bit */
#define	VEVENP		0x03		/* even parity bit */

#define	VSTOP1		0x04		/* 1 stop bit */
#define	VSTOP2		0x0c		/* 2 stop bit */

#define	V19200		0x13		/* 19.2 kbaud */

E 5
/* modem control flags */
D 4
#define VMOD_ON		1
#define VMOD_OFF	0
E 4
I 4
#define	VMOD_ON		1
#define	VMOD_OFF	0
E 4

D 4
#define V_ENAB	0002			/* auto + DTR */
#define V_DISAB	0000			/* auto + disable DTR */
E 4
I 4
D 5
#define	V_ENAB	0002			/* auto + DTR */
#define	V_DISAB	0000			/* auto + disable DTR */
E 5
I 5
#define	V_AUTO		0x00		/* auto control of RTS, uses CTS */
#define	V_MANUAL	0x80		/* manual control of RTS, ignore CTS */
#define	V_DTR_ON	0x02		/* set DTR output */
#define	V_DTR_OFF	0x00		/* drop DTR output */
#define	V_RTS		0x01		/* set RTS output (manual only) */
E 5
E 4

D 4
#define BRK_CHR	040			/* break character */
#define DCD_ON	020			/* */
#define DCD_OFF	010			/* */
D 3
#define	CTS_ON	004			/* */
E 3
I 3
#define CTS_ON	004			/* */
E 3
#define DSR_ON	0200			/* modem signal states for bisync */
#define DSR_OFF 0100
#define DSR_CHG	(DSR_ON|DSR_OFF)
E 4
I 4
#define	BRK_CHR	040			/* break character */
#define	DCD_ON	020			/* */
#define	DCD_OFF	010			/* */
#define	CTS_ON	004			/* */
#define	DSR_ON	0200			/* modem signal states for bisync */
#define	DSR_OFF 0100
#define	DSR_CHG	(DSR_ON|DSR_OFF)
E 4

D 4
#define VX_SILO	0x800			/* offset to base of silo */
E 4
I 4
#define	VX_SILO	0x800			/* offset to base of silo */
E 4

/* input status bits returned in silo */
D 3
#define	VX_PE	0x40			/* parity error */
#define	VX_FE	0x80			/* framing error */
#define	VX_RO	0xc0			/* receiver overrun */
E 3
I 3
D 4
#define VX_PE	0x40			/* parity error */
#define VX_FE	0x80			/* framing error */
#define VX_RO	0xc0			/* receiver overrun */
E 4
I 4
#define	VX_PE	0x40			/* parity error */
#define	VX_FE	0x80			/* framing error */
#define	VX_RO	0xc0			/* receiver overrun */
E 4
E 3

D 4
#define VRESPLEN	12
#define VCMDLEN		64
#define VC_IQLEN	64		/* Interrupt circular queue length */
#define NVCXBUFS	16*3		/* 3 bufs per port per viocx */
#define VC_CMDBUFL	NVCXBUFS	/* circular cmd (to exec) queue len*/
E 4
I 4
#define	VRESPLEN	12
#define	VCMDLEN		64
#define	VC_IQLEN	64		/* Interrupt circular queue length */
#define	NVCXBUFS	16*3		/* 3 bufs per port per viocx */
#define	VC_CMDBUFL	NVCXBUFS	/* circular cmd (to exec) queue len*/
E 4

struct	vcmds {
	int	v_cmdsem;		/* # cmds waiting for itrque */
	int	v_curcnt;		/* # cmds in itrque and executing */
	caddr_t	v_curcmd[VCMDLEN];	/* pointers to cmds being executed */
	int	v_fill;			/* circular fill index */
	int	v_empty;		/* circular empty index */
	caddr_t	cmdbuf[VC_CMDBUFL];	/* circular cmd (to exec) queue */
	int	v_itrfill;		/* circular intr issue queue fill */
	int	v_itrempt;		/* circular intr issue queue empty */
	short	v_itrqueu[VC_IQLEN];	/* circular intr issue queue */
E 2
};

D 2
#ifdef KERNEL
caddr_t VIOCBAS[NVIOCX];	/* base I/O addr */
#define vpanic(x) printf("%s\n", x)
#endif
E 2
I 2
struct	vxcmd {
	struct	vxcmd *c_fwd;
	short	cmd;
	char	par[58];		/* pad to 64 total size */
};

struct	vxmit {
	char	line;
	char	bcount;
	char	ostream[6];
};

D 4
#define SSPEED	13			/* standard speed 9600 bps */
E 4
I 4
#define	SSPEED	13			/* standard speed 9600 bps */
E 4
E 2
E 1
