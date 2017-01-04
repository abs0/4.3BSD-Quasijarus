h43175
s 00010/00005/00421
d D 7.2 88/06/29 17:51:15 bostic 14 13
c install approved copyright notice
e
s 00013/00001/00413
d D 7.1 88/05/21 18:33:22 karels 13 12
c bring up to revision 7 for tahoe release
e
s 00009/00000/00405
d D 1.12 88/05/21 15:36:43 karels 12 11
c new vd_harderr routine; finish timeout code; on-line format support
c (untested)
e
s 00021/00000/00384
d D 1.11 87/06/30 23:40:41 karels 11 10
c define bits for ESDI, error recovery
e
s 00051/00019/00333
d D 1.10 87/04/02 15:59:53 karels 10 9
c scatter-gather; pack label cleanups
e
s 00006/00007/00346
d D 1.9 87/03/10 18:12:30 karels 9 8
c working (I think!) with uncacheable intermediate buffers:
c add vb_buf struct and vbinit to set up, rm b_upte, remove (old)vbasetup
c and rename vbastart to vbasetup ala uba; use bcopy to kernel, double-
c mapping to user space, and purge user-space cache with dkeyinval
e
s 00210/00360/00143
d D 1.8 87/02/18 21:58:12 sam 8 7
c rewrite; disk label support
e
s 00012/00014/00491
d D 1.7 87/01/11 21:23:37 karels 7 6
c more or less 4.3
e
s 00048/00046/00457
d D 1.6 86/10/28 21:03:33 karels 6 5
c fix error messages, various cleanups
e
s 00008/00004/00495
d D 1.5 86/08/12 17:35:09 karels 5 4
c snarf the rest of the eagle config, such as it is
e
s 00063/00034/00436
d D 1.4 86/07/31 22:03:16 sam 4 3
c add eagle and update to 1.21 release
e
s 00000/00032/00470
d D 1.3 86/01/20 23:49:33 sam 3 2
c move POLLTILLDONE to a subroutine
e
s 00001/00001/00501
d D 1.2 86/01/12 15:53:30 sam 2 1
c start of autoconfig
e
s 00502/00000/00000
d D 1.1 86/01/05 18:39:47 sam 1 0
c date and time created 86/01/05 18:39:47 by sam
e
u
U
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
 *
 *	%W% (Berkeley) %G%
 */
E 13

/*
D 8
 * VDDC (Versabus Direct Disk Controller) definitions.
E 8
I 8
 * Versabus VDDC/SMDE disk controller definitions.
E 8
 */
I 11
#define	VDDC_SECSIZE	512	/* sector size for VDDC */
#define	VD_MAXSECSIZE	1024	/* max sector size for SMD/E */
E 11

/*
D 8
 * DCB Command Codes
E 8
I 8
 * Controller communications block.
E 8
 */
D 8
#define	RD		0x80		/* Read Data */
#define	FTR		0xc0		/* Full Track Read */
#define	RAS		0x90		/* Read and Scatter */
D 4
#define	C		0xa0		/* Compare */
E 4
I 4
#define	RD_RAW		0x600		/* Read unformatted disk sector */
#define	CMP		0xa0		/* Compare */
E 4
#define	FTC		0xe0		/* Full Track Compare */
#define	RHDE		0x180		/* Read Header, Data & ECC (not used) */
#define	WD		0x00		/* Write Data */
#define	FTW		0x40		/* Full Track Write */
#define	WTC		0x20		/* Write Then Compare */
#define	FTWTC		0x60		/* Full Track Write Then Compare */
#define	GAW		0x10		/* Gather and Write */
#define	WDE		0x100		/* Write Data & ECC (not used) */
#define	FSECT		0x900		/* Format Sector */
#define	GWC		0x30		/* Gather Write & Compare */
#define	VDSTART		0x800		/* Start drives */
#define	VDRELEASE	0xa00		/* Stop drives */
#define	SEEK		0xb00		/* Seek */
#define	INIT		0xc00		/* Initialize VDDC */
#define	DIAG		0xd00		/* Diagnose (self-test) VDDC */
#define	RSTCFG		0xe00		/* Reset/Configure VDDC/DDI/Drive(s) */
#define	VDSTATUS	0xf00		/* VDDC Status */
E 8
I 8
struct vddevice {
	u_long	vdcdr;		/* controller device register */
	u_long	vdreset;	/* controller reset register */
	u_long	vdcsr;		/* control-status register */
	long	vdrstclr;	/* reset clear register */
	u_short	vdstatus[16];	/* per-drive status register */
	u_short	vdicf_status;	/* status change interupt control format */
	u_short	vdicf_done;	/* interrupt complete control format */
	u_short	vdicf_error;	/* interrupt error control format */
	u_short	vdicf_success;	/* interrupt success control format */
	u_short	vdtcf_mdcb;	/* mdcb transfer control format */
	u_short	vdtcf_dcb;	/* dcb transfer control format */
	u_short	vdtcf_trail;	/* trail transfer control format */
	u_short	vdtcf_data;	/* data transfer control format */
	u_long	vdccf;		/* controller configuration flags */
	u_long	vdsecsize;	/* sector size */
	u_short	vdfill0;
	u_char	vdcylskew;	/* cylinder to cylinder skew factor */
	u_char	vdtrackskew;	/* track to track skew factor */
	u_long	vdfill1;
	u_long	vddfr;		/* diagnostic flag register */
	u_long	vddda;		/* diagnostic dump address */
};
E 8

D 8
#define	ABORT		0x80000000	/* ABORT active i/o */
E 8
I 8
/* controller types */
#define	VDTYPE_VDDC	1	/* old vddc controller (smd only) */
#define	VDTYPE_SMDE	2	/* new smde controller (smd-e) */
E 8

/*
D 8
 * Error/status codes.
E 8
I 8
 * Controller status definitions.
E 8
 */
D 8
#define	HCRCERR		0x1		/* Header CRC Error */
#define	HCMPERR		0x2		/* Header Compare Error */
#define	WPTERR		0x4		/* Write Protect Error/Status */
#define	CTLRERR		0x8		/* Controller Error */
#define	DSEEKERR	0x10		/* Disk Seek Error */
#define	UCDATERR	0x20		/* Uncorrectable Data Error */
#define	NOTCYLERR	0x40		/* Not on Cylinder Error */
#define	DRVNRDY		0x80		/* Drive Not Ready Error/Status */
#define	ALTACC		0x100		/* Alternate (track) accessed Status */
#define	SEEKSTRT	0x200		/* Seek Started Status */
#define	INVDADR		0x400		/* Invalid Disk Address Error */
#define	DNEMEM		0x800		/* Non-Existant Memory Error */
#define	PARERR		0x1000		/* Memory Parity Error */
#define	DCOMPERR	0x2000		/* Data Compare Error */
#define	DDIRDY		0x4000		/* DDI Ready Error/Status */
#define	OPABRT		0x8000		/* Operator Abort (Host) Error/Status */
#define	DSERLY		0x10000		/* Data Strobe Early */
#define	DSLATE		0x20000		/* Data Strobe Late */
#define	TOPLUS		0x40000		/* Track Offset Plus */
#define	TOMNUS		0x80000		/* Track Offset Minus */
#define	CPDCRT		0x100000	/* Cntlr Performed Data Correction */
#define	HRDERR		0x200000	/* Hard Error */
#define	SFTERR		0x400000	/* Soft Error (retry succesful) */
#define	ANYERR		0x800000	/* Any Error */
#define INVCMD		0x1000000	/* Programmer error */
I 7
/*
 * DCB status codes.
 */
#define	DCBABT		0x10000000	/* DCB Aborted */
#define	DCBUSC		0x20000000	/* DCB Unsuccesfully Completed */
#define	DCBCMP		0x40000000	/* DCB Complete */
#define	DCBSTR		0x80000000	/* DCB Started */
E 8
I 8
#define	CS_SCS	0xf		/* status change source (drive number) */
#define	CS_ELC	0x10		/* error on last command */
#define	CS_ICC	0x60		/* interupt cause code */
#define   ICC_NOI  0x00		/* no interupt */
#define   ICC_DUN  0x20		/* no interupt */
#define   ICC_ERR  0x40		/* no interupt */
#define   ICC_SUC  0x60		/* no interupt */
#define	CS_GO	0x80		/* go bit (controller busy) */
#define	CS_BE	0x100		/* buss error */
#define	CS_BOK	0x4000		/* board ok */
#define	CS_SFL	0x8000		/* system fail */
#define	CS_LEC	0xff000000	/* last error code */
E 8
E 7

D 8
/* hard error */
#define	HTYPES \
    (HCRCERR|HCMPERR|WPTERR|CTLRERR|DSEEKERR|UCDATERR|NOTCYLERR|DRVNRDY|\
     INVDADR|DNEMEM|PARERR|DCOMPERR)

#define	ERRS	0x3FFF
/* retryable errors */
#define	CANRETRY \
    (CTLRERR|DSEEKERR|NOTCYLERR|DCOMPERR|UCDATERR|PARERR|DNEMEM|HCRCERR|HCMPERR)

#define	ERRBITS	"\20\1HCRC\2HCMP\3WPT\4CTLR\5DSEEK\6UCDATA\7NOTCYL\10DRVNRDY\
\11ALTACC\12SEEKSTRT\13INVDADR\14DNEMEM\15PAR\16DCOMP\17DDIRDY\20OPABRT\
\21DSERLY\22DSLATE\23TOPLUS\24TOPMNUS\25CPDCRT\26HRDERR\27SFTERR\30ANYERR\
D 7
\31INVCMD"
E 7
I 7
\31INVCMD\35ABORTED\36FAIL\37COMPLETE\40STARTED"
E 7

E 8
/*
D 7
 * DCB status codes.
 */
#define	DCBABT		0x10000000	/* DCB Aborted */
#define	DCBUSC		0x20000000	/* DCB Unsuccesfully Completed */
#define	DCBCMP		0x40000000	/* DCB Complete */
#define	DCBSTR		0x80000000	/* DCB Started */

/*
E 7
D 8
 * MDCB status codes.
E 8
I 8
 * Drive status definitions.
E 8
 */
D 8
#define	CTLRBSY		0x10000000	/* Cntlr Busy */
#define	INTCCDE		0x60000000	/* Interrupt Cause Code */
#define	DCBINT		0x80000000	/* DCB Interrupt Flag */
E 8
I 8
#define	STA_UR	0x1		/* unit ready */
#define	STA_OC	0x2		/* on cylinder */
#define	STA_SE	0x4		/* seek error */
#define	STA_DF	0x8		/* drive fault */
#define	STA_WP	0x10		/* write protected */
#define	STA_US	0x20		/* unit selected */
E 8

/*
D 8
 * VDDC interrupt modes.
E 8
I 8
 * Interupt Control Field definitions.
E 8
 */
D 8
#define	NOINT	0x0		/* No Interrupt */
#define	INTERR	0x2		/* Interrupt on Error */
#define	INTSUC	0x1		/* Interrupt on Success */
#define	INTDONE	0x3		/* Interrupt on Error or Success */
E 8
I 8
#define	ICF_IPL	0x7		/* interupt priority level */
#define	ICF_IEN	0x8		/* interupt enable */
#define	ICF_IV	0xff00		/* interupt vector */
E 8

D 8

E 8
/*
D 8
 * Constrol status definitions.
E 8
I 8
 * Transfer Control Format definitions.
E 8
 */
D 8
#define	CS_SCS	0xf		/* Status Change Source (drive number) */
#define	CS_ELC	0x10		/* Error on Last Command */
#define	CS_ICC	0x60		/* Interupt Cause Code */
#define   ICC_NOI  0x00		/* No interupt */
#define   ICC_DUN  0x20		/* No interupt */
#define   ICC_ERR  0x40		/* No interupt */
#define   ICC_SUC  0x60		/* No interupt */
#define	CS_GO	0x80		/* Go bit (controller working) */
#define	CS_BE	0x100		/* Buss Error */
#define	CS_BOK	0x4000		/* Board O.K. */
#define	CS_SFL	0x8000		/* System fail */
#define	CS_LEC	0xff000000	/* Last Error Code */

/* Status word bit assignments */
#define	STA_UR	0x1		/* Unit Ready */
#define	STA_OC	0x2		/* On Cylinder */
#define	STA_SE	0x4		/* Seek Error */
#define	STA_DF	0x8		/* Drive Fault */
#define	STA_WP	0x10		/* Write Protected */
#define	STA_US	0x20		/* Unit Selected */

/* Interupt Control Field bit assignments */
#define	ICF_IPL	0x7		/* Interupt Priority Level */
#define	ICF_IEN	0x8		/* Interupt ENable */
#define	ICF_IV	0xff00		/* Interupt Vector */

/* Transfer Control Format bit assignments */
E 8
#define	TCF_AM	0xff		/* Address Modifier */
#define	  AM_SNPDA   0x01	/* Standard Non-Privileged Data Access */
#define	  AM_SASA    0x81	/* Standard Ascending Sequential Access */
#define	  AM_ENPDA   0xf1	/* Extended Non-Privileged Data Access */
#define	  AM_EASA    0xe1	/* Extended Ascending Sequential Access */
#define	TCF_BTE	0x800		/* Block Transfer Enable */

D 8
/* Controller Configuration Flags bit assignments */
#define	CCF_STS	0x1		/* Sectors per Track Selectable */
#define	CCF_EAV	0x2		/* Enable Auto Vector */
#define	CCF_ERR	0x4		/* Enable Reset Register */
I 4
#define CCF_DER 0x8		/* Disable Error Recovery */
E 4
#define	CCF_XMD	0x60		/* XMD transfer mode (buss size) */
#define	  XMD_8BIT  0x20	/*   Do only 8 bit transfers */
#define	  XMD_16BIT 0x40	/*   Do only 16 bit transfers */
#define	  XMD_32BIT 0x60	/*   Do only 32 bit transfers */
#define	CCF_BSZ	0x300		/* Burst SiZe */
E 8
I 8
/*
 * Controller Configuration Flags.
 */
#define	CCF_STS	0x1		/* sectors per track selectable */
#define	CCF_EAV	0x2		/* enable auto vector */
#define	CCF_ERR	0x4		/* enable reset register */
#define CCF_DER 0x8		/* disable error recovery */
#define	CCF_XMD	0x60		/* xmd transfer mode (bus size) */
#define	  XMD_8BIT  0x20	/*   do only 8 bit transfers */
#define	  XMD_16BIT 0x40	/*   do only 16 bit transfers */
#define	  XMD_32BIT 0x60	/*   do only 32 bit transfers */
#define	CCF_BSZ	0x300		/* burst size */
E 8
#define	  BSZ_16WRD 0x000	/*   16 word transfer burst */
#define	  BSZ_12WRD 0x100	/*   12 word transfer burst */
#define	  BSZ_8WRD  0x200	/*   8 word transfer burst */
#define	  BSZ_4WRD  0x300	/*   4 word transfer burst */
I 4
D 8
#define CCF_SEN	0x400		/* Cylinder / track Skew ENable (for format) */
E 4
#define	CCF_ENP	0x1000		/* ENable Parity */
#define	CCF_EPE	0x2000		/* Enable Parity Errors */
#define	CCF_EDE	0x10000		/* Error Detection Enable */
#define	CCF_ECE	0x20000		/* Error Correction Enable */
E 8
I 8
#define CCF_SEN	0x400		/* cylinder/track skew enable (for format) */
#define	CCF_ENP	0x1000		/* enable parity */
#define	CCF_EPE	0x2000		/* enable parity errors */
#define	CCF_EDE	0x10000		/* error detection enable */
#define	CCF_ECE	0x20000		/* error correction enable */
E 8

/*
 * Diagnostic register definitions.
 */
D 8
#define	DIA_DC	0x7f		/* Dump count mask */
#define	DIA_DWR	0x80		/* Dump Write / Read flag */
#define	DIA_ARE	0x100		/* Auto Rebuild Enable */
#define	DIA_CEN	0x200		/* Call ENable flag */
#define	DIA_KEY	0xAA550000	/* Reset KEY */
E 8
I 8
#define	DIA_DC	0x7f		/* dump count mask */
#define	DIA_DWR	0x80		/* dump write/read flag */
#define	DIA_ARE	0x100		/* auto rebuild enable */
#define	DIA_CEN	0x200		/* call enable flag */
#define	DIA_KEY	0xAA550000	/* reset enable key */
I 11

/*
 * Hardware interface flags, in dcb.devselect and d_devflags
 */
#define VD_ESDI	0x10		/* drive is on ESDI interface */
#define	d_devflags	d_drivedata[0]		/* in disk label */

/*
 * Error recovery flags.
 */
#define	VDRF_RTZ	0x0001	/* return to zero */
#define	VDRF_OCF	0x0002	/* on cylinder false */
#define	VDRF_OSP	0x0004	/* offset plus */
#define	VDRF_OSM	0x0008	/* offset minus */
#define	VDRF_DSE	0x0080	/* data strobe early */
#define	VDRF_DSL	0x0100	/* data strobe late */

#define	VDRF_NONE	0
#define	VDRF_NORMAL	(VDRF_RTZ|VDRF_OCF|VDRF_OSP|VDRF_OSM|VDRF_DSE|VDRF_DSE)
E 11
E 8

D 8
/* Sector Header bit assignments */
#define	VDMF	0x8000		/* Manufacturer Fault 1=good sector */
#define	VDUF	0x4000		/* User Fault 1=good sector */
#define	VDALT	0x2000		/* Alternate Sector 1=alternate */
#define	VDWPT	0x1000		/* Write Protect 1=Read Only Sector */

/* DCB Bit assignments */
#define	INT_IC	0x3		/* Interupt Control */
#define	  IC_NOI  0x0		/*   NO Interupt */
#define	  IC_IOD  0x1		/*   Interupt On Done */
#define	  IC_IOE  0x2		/*   Interupt On Error */
#define	  IC_IOS  0x3		/*   Interupt On Success */
#define	INT_PBA	0x4		/* Proceed before ACK */

E 8
/*
 * Perform a reset on the controller.
 */
D 8
#define	VDDC_RESET(addr, type) { \
	if (type == SMD_ECTLR) { \
		(addr)->diag_flags = DIA_KEY|DIA_CEN; \
		(addr)->cdr_mdcb_ptr = (fmt_mdcb *)0xffffffff; \
E 8
I 8
#define	VDRESET(a,t) { \
	if ((t) == VDTYPE_SMDE) { \
		((struct vddevice *)(a))->vddfr = DIA_KEY|DIA_CEN; \
		((struct vddevice *)(a))->vdcdr = (u_long)0xffffffff; \
E 8
		DELAY(5000000); \
	} else { \
D 8
		(addr)->cdr_reset = 0x0; \
E 8
I 8
		((struct vddevice *)(a))->vdreset = 0; \
E 8
		DELAY(1500000); \
	} \
}

/*
 * Abort a controller operation.
 */
D 8
#define	VDDC_ABORT(a, type) { \
	if ((type) == SMDCTLR) { \
		movow(a, (ABORT & 0xffff0000) >> 16) ; \
		movow((int)(a)+2, ABORT & 0xffff); \
E 8
I 8
#define	VDABORT(a,t) { \
	if ((t) == VDTYPE_VDDC) { \
		movow((a), (VDOP_ABORT&0xffff0000)>>16) ; \
		movow((int)(a)+2, VDOP_ABORT&0xffff); \
E 8
	} else \
D 8
		(a)->cdr_mdcb_ptr = (fmt_mdcb *)ABORT; \
E 8
I 8
		((struct vddevice *)(a))->vdcdr = (u_long)VDOP_ABORT; \
E 8
	DELAY(1000000); \
}

/*
D 8
 * Start i/o on controller.
E 8
I 8
 * Start a command.
E 8
 */
D 8
#define VDDC_ATTENTION(ctlr, mdcbadr, type) {\
	if (type == SMDCTLR) { \
		movow(ctlr, ((int)mdcbadr & 0xffff0000) >> 16) ; \
		movow((int)(ctlr)+2, (int)mdcbadr & 0xffff); \
E 8
I 8
#define VDGO(a,mdcb,t) {\
	if ((t) == VDTYPE_VDDC) { \
		movow((a), ((int)(mdcb)&0xffff0000)>>16) ; \
		movow((int)((a))+2, (int)(mdcb)&0xffff); \
E 8
	} else \
D 8
		(ctlr)->cdr_mdcb_ptr = mdcbadr; \
E 8
I 8
		((struct vddevice *)(a))->vdcdr = (mdcb); \
E 8
}

/*
D 3
 * Poll controller until operation completes
 * or timeout expires.
 * YECH!!!! THIS SHOULD BE A SUBROUTINE!!!
 */
#define	POLLTILLDONE(c, a, x, t) { \
	vdtimeout = 1000 * (x); \
	uncache(&(a)->operrsta); \
	while ((((a)->operrsta) & (DCBCMP|DCBABT)) == 0) { \
		DELAY(1000); \
		vdtimeout--; \
		uncache(&(a)->operrsta); \
		if (vdtimeout <= 0) { \
			printf("vd%d: controller timeout", c); \
			VDDC_ABORT(c, t); \
			DELAY(30000); \
			break; \
		} \
	} \
	if (vdtimeout > 0) \
		if ((t) == SMD_ECTLR && vdtimeout > 0) { \
			uncache(&(c)->cdr_csr); \
			while((c)->cdr_csr&CS_GO) { \
				DELAY(50); \
				uncache(&(c)->cdr_csr); \
			} \
			DELAY(500); \
		} else \
			DELAY(200); \
	uncache(&(a)->operrsta); \
}

/*
E 3
D 8
 * A disk address.
E 8
I 8
 * MDCB layout.
E 8
 */
D 8
typedef struct {
	char	track;			/* all 8 bits */
	char	sector;			/* all 8  bits */
	short	cylinder;		/* low order 12 bits */
} dskadr;
E 8
I 8
struct mdcb {
	struct	dcb *mdcb_head;		/* first dcb in list */
	struct	dcb *mdcb_busy;		/* dcb being processed */
	struct	dcb *mdcb_intr;		/* dcb causing interrupt */
	long	mdcb_status;		/* status of dcb in mdcb_busy */
};
E 8

/*
D 8
 * Sector formats.
E 8
I 8
 * DCB definitions.
E 8
 */
D 8
typedef union {
	struct {
		dskadr	hdr_addr;
		short	smd_crc;
	} smd;
	struct {
		dskadr	physical;
		dskadr	logical;
		long	smd_e_crc;
	} smd_e;
} fmt_hdr;
E 8

/*
I 8
 * A disk address.
 */
typedef struct {
	u_char	track;			/* all 8 bits */
	u_char	sector;			/* all 8  bits */
	u_short	cylinder;		/* low order 12 bits */
} dskadr;

/*
E 8
 * DCB trailer formats.
 */
/* read/write trailer */
D 10
typedef struct {
E 10
I 10
struct trrw {
E 10
D 9
	char	*memadr;	/* memory address */
E 9
I 9
	u_long	memadr;		/* memory address */
E 9
	u_long	wcount;		/* 16 bit word count */
	dskadr	disk;		/* disk address */
D 10
} trrw;
E 10
I 10
};
E 10

/* scatter/gather trailer */
I 9
D 10
#define	VDMAXPAGES	32
E 9
typedef struct {
	trrw	start_addr;
	struct {
E 10
I 10
#define	VDMAXPAGES	(MAXPHYS / NBPG)
struct trsg {
	struct	trrw start_addr;
	struct addr_chain {
E 10
D 9
		char	*nxt_addr;
E 9
I 9
		u_long	nxt_addr;
E 9
		u_long	nxt_len;
D 9
	} addr_chain[126];
E 9
I 9
D 10
	} addr_chain[VDMAXPAGES+1];
E 9
} trsg;
E 10
I 10
	} addr_chain[VDMAXPAGES + 1];
};
E 10

/* seek trailer format */
D 10
typedef struct {
E 10
I 10
struct trseek {
E 10
	dskadr	skaddr;
D 10
} trseek;
E 10
I 10
};
E 10

/* format trailer */
D 10
typedef struct {
E 10
I 10
struct trfmt {
E 10
	char	*addr;		/* data buffer to be filled on sector*/
	long	nsectors;	/* # of sectors to be formatted */
	dskadr	disk;		/* disk physical address info */
	dskadr  hdr;		/* header address info */
D 10
} trfmt;
E 10
I 10
};
E 10

/* reset/configure trailer */
D 10
typedef struct {
E 10
I 10
struct treset {
E 10
	long	ncyl;		/* # cylinders */
	long	nsurfaces;	/* # surfaces */
	long	nsectors;	/* # sectors */
	long	slip_sec;	/* # of slip sectors */
I 4
	long	recovery;	/* recovery flags */
E 4
D 10
} treset;
E 10
I 10
};
E 10

I 10
/* ident trailer */
struct trid {
	long	name;
	long	id;
	long	date;
};

E 10
/*
 * DCB layout.
 */
D 8
typedef struct fmtdcb {
	struct	fmtdcb *nxtdcb;	/* next dcb */
E 8
I 8
struct dcb {
	struct	dcb *nxtdcb;	/* next dcb */
E 8
	short	intflg;		/* interrupt settings and flags */
	short	opcode;		/* DCB command code etc... */
	long	operrsta;	/* error & status info */
	short	fill;		/* not used */
	char	devselect;	/* drive selection */
	char	trailcnt;	/* trailer Word Count */
	long	err_memadr;	/* error memory address */
	char	err_code;	/* error codes for SMD/E */
	char	fill2;		/* not used */
	short	err_wcount;	/* error word count */
	char	err_trk;	/* error track/sector */
	char	err_sec;	/* error track/sector */
	short	err_cyl;	/* error cylinder adr */
	union {
D 10
		trseek	sktrail;	/* seek command trailer */
D 9
#ifdef notdef
E 9
		trsg	sgtrail;	/* scatter/gather trailer */
D 9
#endif
E 9
		trrw	rwtrail;	/* read/write trailer */
		trfmt	fmtrail;	/* format trailer */
		treset	rstrail;	/* reset/configure trailer */
E 10
I 10
		struct	trid idtrail;	/* ident command trailer */
		struct	trseek sktrail;	/* seek command trailer */
		struct	trsg sgtrail;	/* scatter/gather trailer */
		struct	trrw rwtrail;	/* read/write trailer */
		struct	trfmt fmtrail;	/* format trailer */
		struct	treset rstrail;	/* reset/configure trailer */
E 10
	} trail;
D 8
} fmt_dcb;
E 8
I 8
};
E 8

/*
I 10
 * smaller DCB with seek trailer only (no scatter-gather).
 */
struct skdcb {
	struct	dcb *nxtdcb;	/* next dcb */
	short	intflg;		/* interrupt settings and flags */
	short	opcode;		/* DCB command code etc... */
	long	operrsta;	/* error & status info */
	short	fill;		/* not used */
	char	devselect;	/* drive selection */
	char	trailcnt;	/* trailer Word Count */
	long	err_memadr;	/* error memory address */
	char	err_code;	/* error codes for SMD/E */
	char	fill2;		/* not used */
	short	err_wcount;	/* error word count */
	char	err_trk;	/* error track/sector */
	char	err_sec;	/* error track/sector */
	short	err_cyl;	/* error cylinder adr */
	union {
		struct	trseek sktrail;	/* seek command trailer */
	} trail;
};

/*
E 10
D 8
 * MDCB layout.
E 8
I 8
 * DCB command codes.
E 8
 */
D 8
typedef struct {
	fmt_dcb	*firstdcb;	/* first dcb in chain */
	fmt_dcb	*procdcb;	/* dcb being processed */
	fmt_dcb	*intdcb;	/* dcb causing interrupt */
	long	vddcstat;	/* VDDC status */
} fmt_mdcb;
E 8
I 8
#define	VDOP_RD		0x80		/* read data */
#define	VDOP_FTR	0xc0		/* full track read */
#define	VDOP_RAS	0x90		/* read and scatter */
#define	VDOP_RDRAW	0x600		/* read unformatted disk sector */
#define	VDOP_CMP	0xa0		/* compare */
#define	VDOP_FTC	0xe0		/* full track compare */
#define	VDOP_RHDE	0x180		/* read header, data & ecc */
#define	VDOP_WD		0x00		/* write data */
#define	VDOP_FTW	0x40		/* full track write */
#define	VDOP_WTC	0x20		/* write then compare */
#define	VDOP_FTWTC	0x60		/* full track write then compare */
#define	VDOP_GAW	0x10		/* gather and write */
#define	VDOP_WDE	0x100		/* write data & ecc */
#define	VDOP_FSECT	0x900		/* format sector */
#define	VDOP_GWC	0x30		/* gather write & compare */
#define	VDOP_START	0x800		/* start drives */
#define	VDOP_RELEASE	0xa00		/* stop drives */
#define	VDOP_SEEK	0xb00		/* seek */
#define	VDOP_INIT	0xc00		/* initialize controller */
#define	VDOP_DIAG	0xd00		/* diagnose (self-test) controller */
#define	VDOP_CONFIG	0xe00		/* reset & configure drive */
#define	VDOP_STATUS	0xf00		/* get drive status */
I 10
#define	VDOP_IDENT	0x700		/* identify controller */
E 10
E 8

I 8
#define	VDOP_ABORT	0x80000000	/* abort current command */

E 8
/*
D 8
 * Control-status communications block.
E 8
I 8
 * DCB status definitions.
E 8
 */
D 8
typedef struct {
	fmt_mdcb *cdr_mdcb_ptr;	/* controller's mdcb */
	u_long	cdr_reset;	/* controller reset register */
	u_long	cdr_csr;	/* control/status register */
	long	cdr_reserved;	/* reserved */
	u_short	cdr_status[16];	/* per-drive status register */
	u_short	stat_chng;	/* status change interupt register */
	u_short	done_icf;	/* interupt-complete register */
	u_short	error_icf;	/* error-interupt register */
	u_short	success_icf;	/* success-interupt register */
	u_short	mdcb_tcf;	/* mdcb transfer control register */
	u_short	dcb_tcf;	/* dcb transfer control register */
	u_short	trail_tcf;	/* trail transfer control register */
	u_short	data_tcf;	/* data transfer control register */
	u_long	cdr_ccf;	/* controller configuration flags */
	u_long	sec_size;	/* drive sector size */
I 4
	u_short	cdr_unused0;
	u_char	cyl_skew;	/* cylinder to cylinder skew factor */
	u_char	trk_skew;	/* track to track skew factor */
	u_long	cdr_unused1;
E 4
	u_long	diag_flags;	/* diagnostic flag register */
	u_long	diag_dump;	/* pointer for diagnostic addresses */
} cdr;
E 8
I 8
#define	DCBS_HCRC	0x00000001	/* header crc error */
#define	DCBS_HCE	0x00000002	/* header compare error */
#define	DCBS_WPT	0x00000004	/* drive write protected */
#define	DCBS_CHE	0x00000008	/* controller hardware error */
#define	DCBS_SKI	0x00000010	/* seek incomplete */
#define	DCBS_UDE	0x00000020	/* uncorrectable data error */
#define	DCBS_OCYL	0x00000040	/* off cylinder */
#define	DCBS_NRDY	0x00000080	/* drive not ready */
#define	DCBS_ATA	0x00000100	/* alternate track accessed */
#define	DCBS_SKS	0x00000200	/* seek started */
#define	DCBS_IVA	0x00000400	/* invalid disk address error */
#define	DCBS_NEM	0x00000800	/* non-existant memory error */
#define	DCBS_DPE	0x00001000	/* memory data parity error */
#define	DCBS_DCE	0x00002000	/* data compare error */
#define	DCBS_DDI	0x00004000	/* ddi ready */
#define	DCBS_OAB	0x00008000	/* operation aborted */
#define	DCBS_DSE	0x00010000	/* data strobe early */
#define	DCBS_DSL	0x00020000	/* data strobe late */
#define	DCBS_TOP	0x00040000	/* track offset plus */
#define	DCBS_TOM	0x00080000	/* track offset minus */
#define	DCBS_CCD	0x00100000	/* controller corrected data */
#define	DCBS_HARD	0x00200000	/* hard error */
#define	DCBS_SOFT	0x00400000	/* soft error (retry succesful) */
#define	DCBS_ERR	0x00800000	/* composite error */
#define DCBS_IVC	0x01000000	/* invalid command error */
/* bits 24-27 unused */
#define	DCBS_BSY	0x10000000	/* controller busy */
#define	DCBS_ICC	0x60000000	/* interrupt cause code */
#define	DCBS_INT	0x80000000	/* interrupt generated for this dcb */
E 8

D 8
/* controller types */
#define	UNKNOWN		-1
#define	SMDCTLR		1	/* smd interface */
#define	SMD_ECTLR	2	/* extended-smd interface */
E 8
I 8
#define	VDERRBITS	"\20\1HCRC\2HCE\3WPT\4CHE\5DSKI\6UDE\7OCYL\10NRDY\
\11ATA\12SKS\13IVA\14NEM\15DPE\16DCE\17DDI\20OAB\21DSE\22DSL\23TOP\24TOM\
\25CCD\26HARD\27SOFT\30ERR\31IVC\35ABORTED\36FAIL\37COMPLETE\40STARTED"
E 8

D 8
/* drive types */
#define	XSD	0
D 4
#define	FUJ	1 		/* fujitsu */
E 4
I 4
#define	FUJ	1 		/* Fujitsu 160 */
E 4
#define	XFD	2		/* CDC 340Mb Winchester */
#define	SMD	3		/* CDC 9766 or equivalent */
#define	FSD	4
I 4
#define	EGL	5		/* Fujitsu Eagle */
E 8
I 8
/* drive related errors */
#define	VDERR_DRIVE	(DCBS_SKI|DCBS_OCYL|DCBS_NRDY|DCBS_IVA)
/* controller related errors */
#define	VDERR_CTLR	(DCBS_CHE|DCBS_OAB|DCBS_IVC|DCBS_NEM)
/* potentially recoverable errors */
D 9
#define	VDERR_SOFT \
E 9
I 9
#define	VDERR_RETRY \
E 9
    (VDERR_DRIVE|VDERR_CTLR|DCBS_DCE|DCBS_DPE|DCBS_HCRC|DCBS_HCE)
/* uncorrected data errors */
D 9
#define	VDERR_HARD	(VDERR_SOFT|DCBS_WPT|DCBS_UDE)
E 9
I 9
#define	VDERR_HARD	(VDERR_RETRY|DCBS_WPT|DCBS_UDE)
E 9
E 8
E 4

/*
D 8
 * Drive logical partitions.
E 8
I 8
 * DCB status codes.
E 8
 */
D 8
typedef struct {
	long	par_start;	/* starting sector # */
	long	par_len;	/* size in sectors */
} par_tab;
E 8
I 8
#define	DCBS_ABORT	0x10000000	/* dcb aborted */
#define	DCBS_FAIL	0x20000000	/* dcb unsuccesfully completed */
#define	DCBS_DONE	0x40000000	/* dcb complete */
#define	DCBS_START	0x80000000	/* dcb started */
E 8

D 8
typedef struct {
	int	secsize;		/* bytes/sector */
	int	nsec;			/* sectors/track */
	int	ntrak;			/* tracks/cylinder */
	int	ncyl;			/* # cylinders */
	int	nslip;			/* # slip sectors */
	int	rpm;			/* revolutions/minute */
	int	nbits;			/* bits/track */
	char	*type_name;		/* drive name */
I 4
	char	*type_descrip;		/* drive description */
E 4
	long	fmt_pat[16];		/* patterns to be used for formatting */
	par_tab	partition[8];		/* partition tables */
} fs_tab;
E 8
I 8
/*
 * DCB interrupt control.
 */
#define	DCBINT_NONE	0x0		/* don't interrupt */
#define	DCBINT_ERR	0x2		/* interrupt on error */
#define	DCBINT_SUC	0x1		/* interrupt on success */
#define	DCBINT_DONE	(DCBINT_ERR|DCBINT_SUC)
#define	DCBINT_PBA	0x4		/* proceed before acknowledge */
E 8

D 8
/* physical information for known disk drives.  */
#ifdef VDGENDATA
D 2
long	vddcaddr[] = { 0xf2000, 0xf2100, 0xf2200, 0xf2300 };
E 2
I 2
D 4
long	vddcaddr[] = { 0xf2000, 0xf2100, 0xf2200, 0xf2300, 0 };
E 4
I 4
long	vddcaddr[] =
D 7
  { 0xf2000, 0xf2100, 0xf2200, 0xf2300, 0xf2400, 0xf2500, 0xf2600, 0xf2700, 0 };
E 4
E 2
long	vdtimeout = 0;
E 7
I 7
  { 0xffff2000, 0xffff2100, 0xffff2200, 0xffff2300, 0xffff2400, 0xffff2500,
    0xffff2600, 0xffff2700, 0 };
E 8
I 8
/*
 * Sector formats.
 */
typedef union {
	struct {
		dskadr	hdr_addr;
		short	smd_crc;
	} smd;
	struct {
		dskadr	physical;
		dskadr	logical;
		long	smd_e_crc;
	} smd_e;
} fmt_hdr;
E 8
E 7

D 8
fs_tab	vdst[] = {
D 4
	{512, 48, 24, 711, 0, 3600, 0,	"xsd",	/* 515 Mb FSD */
E 4
I 4
D 6
	{512, 48, 24, 711, 0, 3600, 30240,	"xsd",
E 6
I 6
	{512, 48, 24, 711, 0, 3600, 30240,	"CDC xsd",
E 6
	    "515 Mb Control Data Winchester drive",
E 4
		{ 0x0264c993, 0x04c99326, 0x0993264c, 0x13264c98,
		  0x264c9930, 0x4c993260, 0x993264c0, 0x3264c980,
		  0x64c99300, 0xc9932600, 0x93264c00, 0x264c9800,
		  0x4c993000, 0x99326000, 0x3264c000, 0x54c98000},
D 6
		{{0,	 30528},	/* xsd0a cyl   0 - 52 */
		{30528,	 30528},	/* xsd0b cyl  53 - 105 */
		{61056,	 345600}, 	/* xsd0c cyl 106 - 705 */
D 4
		{0,	 61056}, 	/* xsd0d cyl 709 - 710 (a & b) */
		{0,	 406656},	/* xsd0e cyl   0 - 705 */
		{30528,	 376128}, 	/* xsd0f cyl  53 - 705 (b & c) */
		{61056,	 172800},	/* xsd0g cyl 106 - 405 (1/2 of c) */
		{233856, 172800}}	/* xsd0h cyl 406 - 705 (1/2 of c) */
E 4
I 4
		{118656, 288000}, 	/* xsd0d cyl 206 - 705 */
		{176256, 230400},	/* xsd0e cyl 306 - 705 */
		{233856, 172800}, 	/* xsd0f cyl 406 - 705 */
		{291456, 115200},	/* xsd0g cyl 506 - 705 */
		{349056, 57600}}	/* xsd0h cyl 606 - 705 */
E 6
I 6
		{{0,	 30528},	/* a cyl   0 - 52 */
		{30528,	 30528},	/* b cyl  53 - 105 */
		{61056,	 345600}, 	/* c cyl 106 - 705 */
		{118656, 288000}, 	/* d cyl 206 - 705 */
		{176256, 230400},	/* e cyl 306 - 705 */
		{233856, 172800}, 	/* f cyl 406 - 705 */
		{291456, 115200},	/* g cyl 506 - 705 */
		{349056, 57600}}	/* h cyl 606 - 705 */
E 6
E 4
	},
D 4
	{512, 64, 10, 823, 0, 3600, 0,	"fuj",	/* 360 Mb Fujitsu */
E 4
I 4
D 6
	{512, 44, 20, 842, 0, 3961, 27720,	  "egl",
E 6
I 6
	{512, 44, 20, 842, 0, 3961, 27720,	  "eagle",
E 6
	     "474 Mb Fujitsu Eagle drive",
E 4
		{ 0x0264c993, 0x04c99326, 0x0993264c, 0x13264c98,
		  0x264c9930, 0x4c993260, 0x993264c0, 0x3264c980,
		  0x64c99300, 0xc9932600, 0x93264c00, 0x264c9800,
		  0x4c993000, 0x99326000, 0x3264c000, 0x54c98000},
I 4
D 5
		{{0,	26400},		/* egl0a */
		{26400,	33000},		/* egl0b */
		{59400,	308880},	/* egl0c */
		{0,	367840}}	/* egl0d */
E 5
I 5
		{{0,	 26400},	/* egl0a cyl   0 - 59 */
		{26400,	 33000},	/* egl0b cyl  60 - 134 */
		{59400,	 308880}, 	/* egl0c cyl 135 - 836 */
		{368280, 2640}, 	/* egl0d cyl 837 - 842 */
		{0, 368280},		/* egl0e cyl 0 - 836 */
		{0, 370920}, 		/* egl0f cyl 0 - 842 */
		{59400, 155320},	/* egl0g cyl 135 - 487 */
		{214720, 153560}}	/* egl0h cyl 488 - 836 */
E 5
	},
D 6
	{512, 64, 10, 823, 0, 3600, 40960,	"fuj",	/* 360 Mb Fujitsu */
E 6
I 6
	{512, 64, 10, 823, 0, 3600, 40960, "fuji 360",	/* 360 Mb Fujitsu */
E 6
	    "360 Mb Fujitsu Winchester drive",
		{ 0x0264c993, 0x04c99326, 0x0993264c, 0x13264c98,
		  0x264c9930, 0x4c993260, 0x993264c0, 0x3264c980,
		  0x64c99300, 0xc9932600, 0x93264c00, 0x264c9800,
		  0x4c993000, 0x99326000, 0x3264c000, 0x54c98000},
E 4
		{{0,	 19200},	/* fuj0a cyl   0 - 59 */
		{19200,	 24000},	/* fuj0b cyl  60 - 134 */
		{43200,	 218560}, 	/* fuj0c cyl 135 - 817 */
D 4
		{0,	 43200}, 	/* fuj0d cyl 821 - 822 (a & b) */
		{0,	 261760},	/* fuj0e cyl   0 - 817 */
		{19200,	 242560}, 	/* fuj0f cyl   0 - 134 (b & c) */
		{43200,  109440},	/* fuj0g cyl 135 - 476 (1/2 of c) */
		{152640, 109120}}	/* fug0h cyl 477 - 817 (1/2 of c) */
E 4
I 4
		{79680,	 182080}, 	/* fuj0d cyl 249 - 817 */
		{116160, 145600},	/* fuj0e cyl 363 - 817 */
		{152640, 109120}, 	/* fuj0f cyl 477 - 817 */
		{189120, 72640},	/* fuj0g cyl 591 - 817 */
		{225600, 36160}}	/* fug0h cyl 705 - 817 */
E 4
	},
D 4
	{512, 32, 24, 711, 0, 3600, 0,	"xfd",	/* 340 Mb FSD */
E 4
I 4
D 6
	{512, 32, 24, 711, 0, 3600, 20160,	"xfd",	/* 340 Mb FSD */
E 6
I 6
	{512, 32, 24, 711, 0, 3600, 20160, "CDC xfd",	/* 340 Mb FSD */
E 6
	    "340 Mb Control Data Winchester drive",
E 4
		{ 0x0d9b366c, 0x1b366cd8, 0x366cd9b0, 0x6cd9b360,
		  0xd9b366c0, 0xb366cd80, 0x66cd9b00, 0xcd9b3600,
		  0x9b366300, 0x366cd800, 0x6cd9b000, 0xd9b36000,
		  0xb366c000, 0x66cd8000, 0xcd9b0000, 0x9b360000},
D 6
#ifdef MICKEY
		{{ 0,	 20352 },	/* xfd0a cyl   0-52 */
		{ 20352, 20352 },	/* xfd0b cyl  53-105 */
		{ 40704, 230400 },	/* xfd0c cyl 106-705 */
		{ 271104,1920 },	/* xfd0d cyl 706-710 */
		{ 0,	 271104 },	/* xfd0e cyl   0-705 */
		{ 0,	 273024 }},	/* xfd0f cyl   0-710 */
E 6
I 6
#ifdef cci1.21
		{{ 0,	 20352 },	/* a cyl   0 - 52 */
		{ 20352, 20352 },	/* b cyl  53 - 105 */
		{ 40704, 230400 },	/* c cyl 106 - 705 */
		{79104,	 192000},	/* d cyl 206 - 705 */
		{117504, 153600},	/* e cyl 306 - 705 */
		{155904, 115200},	/* f cyl 406 - 705 */
		{194304, 76800},	/* g cyl 506 - 705 */
		{232704, 38400}}	/* h cyl 606 - 705 */
E 6
#else
D 6
		{{ 0,	 20352 },	/* xfd0a cyl   0 - 52 */
		{ 20352, 20352 },	/* xfd0b cyl  53 - 105 */
		{ 40704, 230400 },	/* xfd0c cyl 106 - 705 */
D 4
		{ 0,	 40704 },	/* xfd0d cyl 709 - 710 (a & b) */
		{ 0,	 271104 },	/* xfd0e cyl   0 - 705 */
		{ 20352, 250752 },	/* xfd0f cyl  53 - 705 (b & c) */
		{ 40704, 115200 },	/* xfd0g cyl 106 - 405 (1/2 of c) */
		{ 155904,115200 }}	/* xfd0h cyl 406 - 705 (1/2 of c) */
E 4
I 4
		{79104,	 192000},	/* xfd0d cyl 206 - 705 */
		{117504, 153600},	/* xfd0e cyl 306 - 705 */
		{155904, 115200},	/* xfd0f cyl 406 - 705 */
		{194304, 76800},	/* xfd0g cyl 506 - 705 */
		{232704, 38400}}	/* xfd0h cyl 606 - 705 */
E 6
I 6
		{{ 0,	 20352 },	/* a cyl   0 - 52 */
		{ 20352, 20352 },	/* b cyl  53 - 105 */
		{ 40704, 230400 },	/* c cyl 106 - 705 */
		{ 0,	 40704 },	/* d cyl 709 - 710 (a & b) */
		{ 0,	 271104 },	/* e cyl   0 - 705 */
		{ 20352, 250752 },	/* f cyl  53 - 705 (b & c) */
		{ 40704, 115200 },	/* g cyl 106 - 405 (1/2 of c) */
		{ 155904,115200 }}	/* h cyl 406 - 705 (1/2 of c) */
E 6
E 4
#endif
	},
D 4
	{512, 32, 19, 823, 0, 3600, 0,	"smd",	/* 300 Mb SMD */
E 4
I 4
D 6
	{512, 32, 19, 823, 0, 3600, 20160,	"smd",	/* 300 Mb SMD */
	    "300 Mb Control Data removable media drive",
E 6
I 6
	{512, 32, 19, 823, 0, 3600, 20160,	"9766",	/* 300 Mb SMD */
	    "300 Mb Control Data 9766 removable media drive",
E 6
E 4
		{ 0x0d9b366c, 0x1b366cd8, 0x366cd9b0, 0x6cd9b360,
		  0xd9b366c0, 0xb366cd80, 0x66cd9b00, 0xcd9b3600,
		  0x9b366300, 0x366cd800, 0x6cd9b000, 0xd9b36000,
		  0xb366c000, 0x66cd8000, 0xcd9b0000, 0x9b360000},
D 4
		{{ 0,	 20064},	/* smd0a cyl   0-65 */
		{ 20064, 13680},	/* smd0b cyl  66-110 */
		{ 33744, 214928},	/* smd0c cyl 111-817 */
		{ 248672,1520 },	/* smd0d cyl 818-822 */
		{ 0,	 248672 },	/* smd0e cyl   0-817 */
		{ 0,	 250192 }},	/* smd0f cyl   0-822 */
E 4
I 4
D 6
		{{0,	 20064},	/* smd0a cyl   0-65 */
		{20064, 13680},		/* smd0b cyl  66-110 */
		{33744, 214928},	/* smd0c cyl 111-817 */
		{69616,	 179056},	/* smd0d cyl 229 - 817 */
		{105488, 143184},	/* smd0e cyl 347 - 817 */
		{141360, 107312},	/* smd0f cyl 465 - 817 */
		{177232, 71440},	/* smd0g cyl 583 - 817 */
		{213104, 35568}}	/* smd0h cyl 701 - 817 */
E 6
I 6
		{{0,	 20064},	/* a cyl   0-65 */
		{20064, 13680},		/* b cyl  66-110 */
		{33744, 214928},	/* c cyl 111-817 */
		{69616,	 179056},	/* d cyl 229 - 817 */
		{105488, 143184},	/* e cyl 347 - 817 */
		{141360, 107312},	/* f cyl 465 - 817 */
		{177232, 71440},	/* g cyl 583 - 817 */
		{213104, 35568}}	/* h cyl 701 - 817 */
E 6
E 4
	},
D 4
	{512, 32, 10, 823, 0, 3600, 0,	"fsd",	/* 160 Mb FSD */
E 4
I 4
D 6
	{512, 32, 10, 823, 0, 3600, 20160,	"fsd",	/* 160 Mb FSD */
E 6
I 6
D 7
	{512, 32, 10, 823, 0, 3600, 20160, "CDC fsd",	/* 160 Mb FSD */
E 6
	    "160 Mb Control Data Winchester drive",
E 7
I 7
	{512, 32, 10, 823, 0, 3600, 20160, "fsd",	/* 160 Mb FSD */
	    "160 Mb Winchester drive",
E 7
E 4
		{ 0x0d9b366c, 0x1b366cd8, 0x366cd9b0, 0x6cd9b360,
		  0xd9b366c0, 0xb366cd80, 0x66cd9b00, 0xcd9b3600,
		  0x9b366300, 0x366cd800, 0x6cd9b000, 0xd9b36000,
		  0xb366c000, 0x66cd8000, 0xcd9b0000, 0x9b360000},
D 6
		{{0,	 9600},		/* fsd0a cyl   0 -  59 */
		{9600,	 12000},	/* fsd0b cyl  60 - 134 */
		{21600,	 109280},	/* fsd0c cyl 135 - 817 */
D 4
		{0,	 21600},	/* fsd0d cyl   0 - 134 (a & b) */
		{0,	 130880},	/* fsd0e cyl   0 - 817 */
		{9600,	 121280},	/* fsd0f cyl  60 - 817 (b & c) */
		{21600,  54240},	/* fsd0g cyl 135 - 473 (1/2 of c) */
		{75840,  55040}}	/* fsd0h cyl 474 - 817 (1/2 of c) */
E 4
I 4
		{39840,	 91040},	/* fsd0d cyl 249 - 817 */
		{58080,	 72800},	/* fsd0e cyl 363 - 817 */
		{76320,	 54560},	/* fsd0f cyl 477 - 817 */
		{94560,  36320},	/* fsd0g cyl 591 - 817 */
		{112800, 18080}}	/* fsd0h cyl 705 - 817 */
E 6
I 6
		{{0,	 9600},		/* a cyl   0 -  59 */
		{9600,	 12000},	/* b cyl  60 - 134 */
		{21600,	 109280},	/* c cyl 135 - 817 */
		{39840,	 91040},	/* d cyl 249 - 817 */
		{58080,	 72800},	/* e cyl 363 - 817 */
		{76320,	 54560},	/* f cyl 477 - 817 */
		{94560,  36320},	/* g cyl 591 - 817 */
		{112800, 18080}}	/* h cyl 705 - 817 */
E 6
E 4
	}
};

int	nvddrv = (sizeof (vdst) / sizeof (fs_tab));

#else
#ifdef STANDALONE
extern long	vddcaddr[];
D 7
extern long	vdtimeout;
E 7
extern fs_tab	vdst[];
extern int	nvddrv;
#endif
#endif
E 8
I 8
/* Sector Header bit assignments */
#define	VDMF	0x8000		/* Manufacturer Fault 1=good sector */
#define	VDUF	0x4000		/* User Fault 1=good sector */
#define	VDALT	0x2000		/* Alternate Sector 1=alternate */
#define	VDWPT	0x1000		/* Write Protect 1=Read Only Sector */
I 12

/* input register assignments for DIOCWFORMAT ioctl */
#define	dk_op		df_reg[0]	/* opcode */
#define	dk_althdr	df_reg[1]	/* alt. sect. header, in an int! */
#define	dk_fmtflags	df_reg[2]	/* header format flags */

/* output register assignments for DIOCWFORMAT ioctl */
#define	dk_operrsta	df_reg[0]	/* dcb operrsta */
#define	dk_ecode	df_reg[1]	/* smd-e err_code */
E 12
E 8
E 1
