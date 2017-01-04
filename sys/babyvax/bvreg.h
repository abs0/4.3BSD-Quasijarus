/*
 * BabyVAX register definitions.
 *
 *	@(#)bvreg.h	7.6 (Berkeley) 3/22/04
 */

/*
 * On BabyVAXen we have:
 *
 * A number of scattered registers, in blocks smaller than one page each
 * Larger address space ranges for some devices
 *
 * The latter are supported by their own drivers that may or may not be
 * compiled in.  They have their own maps.  For the former we have a single
 * 8-page structure with one map.
 */

struct babyvax_regs {
	u_short	bvr_cfgtst;		/* 0x20020000 */
	char	bvr_gap1[510];
	u_long	bvr_hltcod;		/* 0x20080000 */
	u_long	bvr_mser;		/* 0x20080004 */
	u_long	bvr_mear;		/* 0x20080008 */
	u_char	bvr_intmsk;		/* 0x2008000C */
	u_char	bvr_vdcorg;		/* 0x2008000D */
	u_char	bvr_vdcsel;		/* 0x2008000E */
	u_char	bvr_intreq;		/* 0x2008000F */
	u_short	bvr_diagdisp;		/* 0x20080010 3100 diag display (w/o) */
	u_short	bvr_pad60;
	u_long	bvr_par_ctl;		/* 0x20080014 3100 parity control */
	u_long	bvr_pad61;
	u_short	bvr_pad62;
	u_short	bvr_diagtime;		/* 0x2008001E 3100 diagnostic timer */
	u_long	bvr_gap2[120];
	u_long	bvr_idrom[32];		/* 0x20090000 */
	u_long	bvr_gap3[96];
	u_short	bvr_sercsr;		/* 0x200A0000 */
	u_short	bvr_gap4a;
	u_short	bvr_serrbuf;		/* 0x200A0004 */
	u_short	bvr_gap4b;
	u_char	bvr_sertcr;		/* 0x200A0008 */
	u_char	bvr_sermctl;
	u_short	bvr_gap4c;
	union {				/* 0x200A000C */
		u_short	su_msr;
		struct {
			u_char	ss_tdr;
			u_char	ss_brk;
		} su_tdr;
	} bvr_sermsrtdr;
	u_short	bvr_gap4d;
	u_long	bvr_gap5[124];
	u_short	bvr_toysecs;		/* 0x200B0000 seconds */
	u_short	bvr_pad8;
	u_short	bvr_toysecs_alarm;	/* not used			*/
	u_short	bvr_pad9;
	u_short	bvr_toymins;		/* minutes			*/
	u_short	bvr_pad10;
	u_short	bvr_toymins_alarm;	/* not used			*/
	u_short	bvr_pad11;
	u_short	bvr_toyhours;		/* hours			*/
	u_short	bvr_pad12;
	u_short	bvr_toyhours_alarm;	/* not used			*/
	u_short	bvr_pad13;
	u_short	bvr_toyday_week;	/* not used			*/
	u_short	bvr_pad14;
	u_short	bvr_toyday;		/* day of month			*/
	u_short	bvr_pad15;
	u_short	bvr_toymonth;		/* month			*/
	u_short	bvr_pad16;
	u_short	bvr_toyyear;		/* year				*/
	u_short	bvr_pad17;
	u_short	bvr_toycsra;		/* csr				*/
	u_short	bvr_pad18;
	u_short	bvr_toycsrb;		/* csr				*/
	u_short	bvr_pad19;
	u_short	bvr_toycsrc;		/* csr				*/
	u_short	bvr_pad20;
	u_short	bvr_toycsrd;		/* csr				*/
	u_short	bvr_pad21;
					/* NON-VOLATILE RAM		*/
	u_long	bvr_cpmbx;		/* Console program mailbox	*/
	u_long	bvr_cpflg;		/* Console program flags	*/
	u_long	bvr_lk201_id;		/* LK201 keyboard variation	*/
	u_long	bvr_console_id;		/* Console device type		*/
	u_long	bvr_scr[4];		/* Scratch RAM physical address	*/
	u_long	bvr_temp[12];		/* Used by System Firmware	*/
	u_long	bvr_bat_chk[4];		/* Battery check data		*/
	u_long	bvr_boot_dev[4];	/* Default boot device		*/
	u_long	bvr_boot_flg[4];	/* Default boot flags		*/
	u_long	bvr_scr_length;		/* # of pages of scratch RAM	*/
	u_long	bvr_cpu_scsi_id;	/* System's SCSI bus 0 & 1 IDs  */
	u_long	bvr_gap6[80];
	u_char	bvr_dkcreg;		/* 0x200C0000 */
	char	bvr_gap8a[3];
	u_char	bvr_dkccmd;		/* 0x200C0004 */
	char	bvr_gap8b[123];
	u_char	bvr_scsi0reg[128];	/* 0x200C0080 */
	char	bvr_gap8c[128];
	u_char	bvr_scsi1reg[128];	/* 0x200C0180 */
	u_short	bvr_nirdp;		/* 0x200E0000 */
	u_short	bvr_gap9a;
	u_short	bvr_nirap;		/* 0x200E0004 */
	u_short	bvr_gap9b;
	u_long	bvr_gap9c[126];
	u_short	bvr_curcmd;		/* 0x200F0000 */
	u_short	bvr_gap7a;
	u_short	bvr_curxpos;		/* 0x200F0004 */
	u_short	bvr_gap7b;
	u_short	bvr_curypos;		/* 0x200F0008 */
	u_short	bvr_gap7c;
	u_short	bvr_curxmin1;		/* 0x200F000C */
	u_short	bvr_gap7d;
	u_short	bvr_curxmax1;		/* 0x200F0010 */
	u_short	bvr_gap7e;
	u_short	bvr_curymin1;		/* 0x200F0014 */
	u_short	bvr_gap7f;
	u_short	bvr_curymax1;		/* 0x200F0018 */
	u_short	bvr_gap7g;
	u_long	bvr_gap7h[4];
	u_short	bvr_curxmin2;		/* 0x200F002C */
	u_short	bvr_gap7i;
	u_short	bvr_curxmax2;		/* 0x200F0030 */
	u_short	bvr_gap7j;
	u_short	bvr_curymin2;		/* 0x200F0034 */
	u_short	bvr_gap7k;
	u_short	bvr_curymax2;		/* 0x200F0038 */
	u_short	bvr_gap7l;
	u_short	bvr_curload;		/* 0x200F003C */
	u_short	bvr_gap7m;
	u_long	bvr_gap7n[112];
};
#define	bvr_ioreset	bvr_cfgtst
#define	bvr_intclr	bvr_intreq
#define	bvr_serlpr	bvr_serrbuf
#define	bvr_sermsr	bvr_sermsrtdr.su_msr
#define	bvr_sertdr	bvr_sermsrtdr.su_tdr.ss_tdr
#define	bvr_serbrk	bvr_sermsrtdr.su_tdr.ss_brk

#ifdef KERNEL
extern struct babyvax_regs bv_regs;
#endif

#define	CFGTST_MULTU	0x80
#define	CFGTST_NETOPT	0x40
#define	CFGTST_CACHPR	0x40	/* KA42 L2 cache presence flag */
#define	CFGTST_L3CON	0x20
#define	CFGTST_CURTEST	0x10
#define	CFGTST_VIDOPT	0x08
#define	CFGTST_MTYPE	0x07

/* CFGTST was extended to 16 bits on KA42 */
#define	CFGTST_SC_TYPE	0xC000		/* Storage controller type mask */
#define	CFGTST_SC_NONE	0xC000		/* No storage controller present */
#define	CFGTST_SCSIMFM	0x0000		/* ST506/SCSI controller */
#define	CFGTST_SCSISCSI	0x4000		/* SCSI/SCSI controller */
#define	CFGTST_DRIVEID	0x1F00		/* drive presence and type flags */

/* BabyVAX interrupt masks */
#define	BVINT_SR	0x80
#define	BVINT_ST	0x40
#define	BVINT_NP	0x20
#define	BVINT_NS	0x10
#define	BVINT_VF	0x08
#define	BVINT_VS	0x04
#define	BVINT_SC	0x02
#define	BVINT_DC	0x01

/* Parity Control Register (PAR_CTL) bit definitions */
#define	PAR_CTL_DPEN	0x00000001	/* DMA parity enable (bit 0) */
#define	PAR_CTL_CPEN	0x00000002	/* CPU parity enable (bit 1) */
#define	PAR_CTL_DMA	0x01000000	/* LANCE chip DMA control (bit 24) */

#define	TOYCSRA_UIP	0x0200
#define	TOYCSRA_DVX	0x01C0
#define	TOYCSRA_RSX	0x003C
#define	TOYCSRA_SET	0x0080	/* correct setting for DVX and RSX fields */

#define	TOYCSRB_SET	0x0200
#define	TOYCSRB_PIE	0x0100
#define	TOYCSRB_AIE	0x0080
#define	TOYCSRB_UIE	0x0040
#define	TOYCSRB_SQWE	0x0020
#define	TOYCSRB_DM	0x0010
#define	TOYCSRB_24HR	0x0008
#define	TOYCSRB_DSE	0x0004

#define	TOYCSRD_VRT	0x0200

#define	CPMBX_HLTSWX	0x00C0
#define	CPMBX_HLTSWX_SHIFT	6
#define	CPMBX_RIP	0x0020
#define	CPMBX_BIP	0x0010
#define	CPMBX_HLTACT	0x000C
#define	CPMBX_HLTACT_SHIFT	2
