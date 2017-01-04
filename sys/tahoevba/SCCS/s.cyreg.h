h33227
s 00008/00006/00189
d D 7.6 88/09/09 17:25:59 bostic 6 5
c the lock file got lost somewhere, so I'm checking this in for somebody
c this is what got shipped with 4.3BSD-tahoe
e
s 00007/00007/00188
d D 7.5 87/04/09 11:03:29 karels 5 4
c fix up blksize/retry for buffered reads
e
s 00007/00000/00188
d D 7.4 87/04/01 11:57:28 karels 4 3
c allocate intermediate buffers in startup (low mem + page aligned),
c remove bdbtodb
e
s 00036/00028/00152
d D 7.3 87/01/11 21:23:33 karels 3 2
c more or less 4.3
e
s 00158/00144/00022
d D 7.2 86/01/26 13:49:15 sam 2 1
c almost working (fsf/bsf don't work properly)
e
s 00166/00000/00000
d D 7.1 86/01/05 18:39:46 sam 1 0
c date and time created 86/01/05 18:39:46 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

D 2
/* get controller attention and start an operation */
#define CY_ATTENTION(addr) movob(addr, 0xff)	/* also known as: GO */
#define CY_RESET(addr)    CY_ATTENTION(addr+1) /* reset controller */
#define CYUNIT(d)	  (minor(d) & 0xf)
E 2
I 2
/*
 * Tapemaster controller definitions.
 */
E 2

I 4
/*
 * With 20-bit addressing, the intermediate buffer
 * must be allocated early in startup().
 */
D 5
#define	CYMAXIO	(32*NBPG)		/* max i/o size */
E 5
I 5
#define	CYMAXIO	(64*1024)		/* max i/o size + 1 */
E 5
char	*cybuf;

E 4
D 2
#define MULTIBUS_SHORT(x) (short)((((x)>>8)&0xff) | (((x)<<8)&0xff00))
E 2
I 2
/* for byte swapping Multibus values */
D 6
#define	htoms(x) (short)((((x)>>8)&0xff) | (((x)<<8)&0xff00))
E 6
I 6
#define	htoms(x) (u_short)((((x)>>8)&0xff) | (((x)<<8)&0xff00))
E 6
E 2

D 2
#define	NORMAL_INTERUPT	0x11
#define	CLEAR_INTERUPT	0x09
E 2
I 2
#define	b_repcnt  b_bcount
#define	b_command b_resid
E 2

D 2
#define	T_NOREWIND	0x80
E 2
I 2
/*
I 3
 * System configuration pointer.
 * Memory address is jumpered on controller.
 */
struct	cyscp {
	char	csp_buswidth;	/* system bus width */
#define	CSP_16BITS	1	/* 16-bit system bus */
#define	CSP_8BITS	0	/* 8-bit system bus */
	char	csp_unused;
	u_char	csp_scb[4];	/* point to system config block */
};

/*
 * System configuration block
 */
struct	cyscb {
	char	csb_fixed;	/* fixed value code (must be 3) */
	char	csb_unused;	/* unused */
	u_char	csb_ccb[4];	/* pointer to channel control block */
};

#define	CSB_FIXED	0x3

/*
E 3
 * Channel control block definitions
 */
struct	cyccb {
	char	cbcw;		/* channel control word */
	char	cbgate;		/* tpb access gate */
D 3
	short	cbtpb[2];	/* first tape parameter block */
E 3
I 3
	u_char	cbtpb[4];	/* first tape parameter block */
E 3
};
E 2

I 2
#define	GATE_OPEN	(char)(0x00)
#define	GATE_CLOSED	(char)(0xff)
E 2

D 2
/* Tape Parameter Block definitions */
typedef struct {
	long		cmd;		/* Command */
	short		control;	/* Control */
	short		count;		/* Return count */
	short		size;		/* Buffer size */
	short		rec_over;	/* Records/Overrun */
	char		*data_ptr;	/* Pointer to source/dest */
	short		status;		/* Status */
	short		link_ptr[2];	/* Pointer to next parameter block */
} fmt_tpb;
E 2
I 2
#define	CY_GO(addr)	movob((addr), 0xff)	/* channel attention */
#define	CY_RESET(addr)  movob((addr)+1, 0xff) 	/* software controller reset */
E 2

D 2
/* Controller commands */
E 2
I 2
#define	CBCW_IE		0x11		/* interrupt on cmd completion */
#define	CBCW_CLRINT	0x09		/* clear active interrupt */
E 2

D 2
/* Group. I Control status/commands */
#define	CONFIG	(0x00000000)	/* configure */
#define	SET_PA	(0x08000000)	/* set page */
#define	NO_OP	(0x20000000)	/* no operation */
#define	DRIVE_S	(0x28000000)	/* drive status */
#define	TAPE_AS	(0x74000000)	/* tape assign */
#define	DRIVE_R	(0x90000000)	/* drive reset */
E 2
I 2
/*
 * Tape parameter block definitions
 */
struct	cytpb {
D 5
	long	tpcmd;		/* command, see below */
	short	tpcontrol;	/* control word */
	short	tpcount;	/* return count */
	short	tpsize;		/* buffer size */
	short	tprec;		/* records/overrun */
E 5
I 5
	u_long	tpcmd;		/* command, see below */
	u_short	tpcontrol;	/* control word */
	u_short	tpcount;	/* return count */
	u_short	tpsize;		/* buffer size */
	u_short	tprec;		/* records/overrun */
E 5
D 3
	short	tpdata[2];	/* pointer to source/dest */
E 3
I 3
	u_char	tpdata[4];	/* pointer to source/dest */
E 3
D 5
	short	tpstatus;	/* status */
E 5
I 5
	u_short	tpstatus;	/* status */
E 5
D 3
	short	tplink[2];	/* pointer to next parameter block */
E 3
I 3
	u_char	tplink[4];	/* pointer to next parameter block */
E 3
};
E 2

D 2
/* Group. II Tape position commands */
#define	REWD_OV	(0x04000000)	/* rewind overlapped */
#define	READ_FO	(0x1C000000)	/* read foreign tape */
#define	REWD_TA	(0x34000000)	/* rewind tape */
#define	OFF_UNL	(0x38000000)	/* off_line and unload */
#define	WRIT_FM	(0x40000000)	/* write filemark */
#define	SERH_FM	(0x44000000)	/* search filemark */
#define	SRFM_FD	(0x44000000)	/* search filemark forward */
#define	SRFM_BK	(0xC4000000)	/* search filemark backward */
#define	SPACE	(0x48000000)	/* skip record */
#define	SP_FORW	(0x48000000)	/* space forward */
#define	SP_BACK	(0xC8000000)	/* space backwords */
#define	ERASE_F	(0x4C000000)	/* erase fixed length */
#define	ERASE_T	(0x50000000)	/* erase to end of tape */
#define	SPAC_FM	(0x70000000)	/* space filemark */
#define	SP_FM_F	(0x70000000)	/* space filemark forward */
#define	SP_FM_B	(0xC9000000)	/* space filemark backward */
#define	SERH_MU	(0x94000000)	/* search multiple filemarks */
E 2
I 2
/* control field bit definitions */
#define	CYCW_UNIT	(0x000c<<8) 	/* unit select mask, 2 bit field */
#define	CYCW_IE		(0x0020<<8)	/* interrupt enable */
#define	CYCW_LOCK	(0x0080<<8)	/* bus lock flag */
#define	CYCW_REV	(0x0400>>8)	/* reverse flag */
#define	CYCW_SPEED	(0x0800>>8)	/* speed/density */
#define	    CYCW_25IPS	0
#define	    CYCW_100IPS	(0x0800>>8)
#define	CYCW_WIDTH  	(0x8000>>8)	/* width */
#define	    CYCW_8BITS	0
#define	    CYCW_16BITS	(0x8000>>8)
E 2

D 2
/* Group. III Data transfer commands */
#define	READ_BU	(0x10000000)	/* read buffered */
#define	WRIT_BU	(0x14000000)	/* write buffered */
#define	EDIT_BU	(0x18000000)	/* edit buffered */
#define	READ_TA	(0x2C000000)	/* read tape */
#define	WRIT_TA	(0x30000000)	/* write tape */
#define	EDIT_TA	(0x3C000000)	/* edit tape */
#define	READ_ST	(0x60000000)	/* read streaming */
#define	WRIT_ST	(0x64000000)	/* write streaming */
E 2
I 2
#define	CYCW_BITS	"\20\3REV\005100IPS\00716BITS\16IE\20LOCK"
E 2

D 2
/* Group. IV Special commands */
#define	EXCHANG	(0x0C000000)	/* exchange system and tapemaster RAM */
#define	BLOCK_M	(0x80000000)	/* block move */
E 2
I 2
/*
 * Controller commands
 */
E 2

D 2
/* Group. V Diagnostic commands */
#define	TEST_SH	(0x54000000)	/* short memory test */
#define	TEST_LG	(0x58000000)	/* long memory test */
#define	TEST_CN	(0x5C000000)	/* controller confidence test */
#define	TEST_RW	(0x68000000)	/* test read/write timeing */
E 2
I 2
/* control status/commands */
#define	CY_CONFIG	(0x00<<24)	/* configure */
#define	CY_NOP		(0x20<<24)	/* no operation */
I 3
#define	CY_SETPAGE	(0x08<<24)	/* set page (addr bits 20-23) */
E 3
#define	CY_SENSE	(0x28<<24)	/* drive status */
#define	CY_CLRINT	(0x9c<<24)	/* clear Multibus interrupt */
E 2

I 2
/* tape position commands */
#define	CY_REW		(0x34<<24)	/* rewind tape */
#define	CY_OFFL		(0x38<<24)	/* off_line and unload */
#define	CY_WEOF		(0x40<<24)	/* write end-of-file mark */
#define	CY_SFORW	(0x70<<24)	/* space record forward */
D 3
#define	CY_SREV		(CY_SFORW|CYCW_REV)/* space record backwords */
E 3
I 3
#define	CY_SREV		(CY_SFORW|CYCW_REV) /* space record backwards */
#define	CY_FSF		(0x44<<24)	/* space file forward */
#define	CY_BSF		(CY_FSF|CYCW_REV) /* space file backwards */
E 3
#define	CY_ERASE	(0x4c<<24)	/* erase record */
E 2

D 2
/* Control field bit definitions */
#define	CW_UNIT		(0x000c<<8) /* tape select mask, 2 bit field */
#define	CW_MAIL		(0x0010<<8) /* mailbox flag */
#define	CW_INTR		(0x0020<<8) /* interrupt flag */
#define	CW_LINK		(0x0040<<8) /* link flag */
#define	CW_LOCK		(0x0080<<8) /* bus lock flag */
#define	CW_BANK		(0x0100>>8) /* bank select */
#define	CW_REV		(0x0400>>8) /* reverse flag */
#define	CW_SPEED	(0x0800>>8) /* speed/density */
#define	    CW_25ips	0
#define	    CW_100ips	(0x0800>>8)
#define	CW_STREAM  	(0x1000>>8) /* continuous */
#define	CW_WIDTH  	(0x8000>>8) /* width */
#define	    CW_8bits	0
#define	    CW_16bits	(0x8000>>8)
E 2
I 2
/* data transfer commands */
#define	CY_BRCOM	(0x10<<24)	/* read buffered */
#define	CY_BWCOM	(0x14<<24)	/* write buffered */
#define	CY_RCOM		(0x2c<<24)	/* read tape unbuffered */
#define	CY_WCOM		(0x30<<24)	/* write tape unbuffered */
E 2

I 2
/* status field bit definitions */
#define	CYS_WP		(0x0002<<8)	/* write protected, no write ring */
#define	CYS_BSY		(0x0004<<8)	/* formatter busy */
#define	CYS_RDY		(0x0008<<8)	/* drive ready */
#define	CYS_EOT		(0x0010<<8)	/* end of tape detected */
#define	CYS_BOT		(0x0020<<8)	/* tape is at load point */
#define	CYS_OL		(0x0040<<8)	/* drive on_line */
#define	CYS_FM		(0x0080<<8)	/* filemark detected */
#define	CYS_ERR		(0x1f00>>8)	/* error value mask */
#define	CYS_CR		(0x2000>>8)	/* controller executed retries */
#define	CYS_CC		(0x4000>>8)	/* command completed successfully */
#define	CYS_CE		(0x8000>>8)	/* command execution has begun */
E 2

D 2
/* Status field bit definitions */
#define	CS_P	(0x0002<<8)	/* Protected, no write ring */
#define	CS_FB	(0x0004<<8)	/* formatter busy */
#define	CS_RDY	(0x0008<<8)	/* drive ready */
#define	CS_EOT	(0x0010<<8)	/* end of tape detected */
#define	CS_LP	(0x0020<<8)	/* tape is at load point */
#define	CS_OL	(0x0040<<8)	/* drive on_line */
#define	CS_FM	(0x0080<<8)	/* Filemark detected */
#define	CS_ERm	(0x1F00>>8)	/* Error value mask */
#define	CS_CR	(0x2000>>8)	/* Controller executed retries */
#define	CS_CC	(0x4000>>8)	/* Command Completed successfully */
#define	CS_CE	(0x8000>>8)	/* Command execution has begun */
E 2
I 2
#define	CYS_BITS "\20\6CR\7CC\10CE\12WP\13BSY\14RDY\15EOT/BOT\16BOT\17OL\20FM"
E 2

D 2
#define	CYDS_BITS "\20\6CS_CR\7CS_CC\8CS_CE\12CS_P\13CS_FB\14CS_RDY\15CS_EOT\
\16CS_LP\17CS_OL\20CS_FM"
E 2
I 2
/* error codes for CYS_ERR */
#define	CYER_TIMOUT	0x01	/* timed out data busy false */
#define	CYER_TIMOUT1	0x02	/* data busy false,formatter,ready */
#define	CYER_TIMOUT2	0x03	/* time out ready busy false */
#define	CYER_TIMOUT3	0x04	/* time out ready busy true */
#define	CYER_TIMOUT4	0x05	/* time out data busy true */
#define	CYER_NXM	0x06	/* time out memory */
#define	CYER_BLANK	0x07	/* blank tape */
#define	CYER_DIAG	0x08	/* micro-diagnostic */
#define	CYER_EOT	0x09	/* EOT forward, BOT rev. */
#define	CYER_BOT	0x09	/* EOT forward, BOT rev. */
#define	CYER_HERR	0x0a	/* retry unsuccessful */
#define	CYER_FIFO	0x0b	/* FIFO over/under flow */
#define	CYER_PARITY	0x0d	/* drive to tapemaster parity error */
#define	CYER_CKSUM	0x0e	/* prom checksum */
#define	CYER_STROBE	0x0f	/* time out tape strobe */
#define	CYER_NOTRDY	0x10	/* tape not ready */
#define	CYER_PROT	0x11	/* write, no enable ring */
#define	CYER_JUMPER	0x13	/* missing diagnostic jumper */
#define	CYER_LINK	0x14	/* bad link, link inappropriate */
#define	CYER_FM		0x15	/* unexpected filemark */
#define	CYER_PARAM	0x16	/* bad parameter, byte count ? */
#define	CYER_HDWERR	0x18	/* unidentified hardware error */
#define	CYER_NOSTRM	0x19	/* streaming terminated */
E 2

D 2
/* Error value definitions for CS_ERm field */
#define	ER_TIMOUT	(0x01)	/* timed out data busy false */
#define	ER_TIMOUT1	(0x02)	/* data busy false,formatter,ready */
#define	ER_TIMOUT2	(0x03)	/* time out ready busy false */
#define	ER_TIMOUT3	(0x04)	/* time out ready busy true */
#define	ER_TIMOUT4	(0x05)	/* time out data busy true */
#define	ER_NEX		(0x06)	/* time out memory */
#define	ER_BLANK	(0X07)	/* blank tape */
#define	ER_DIAG		(0x08)	/* micro-diagnostic */
#define	ER_EOT		(0x09)	/* EOT forward, BOT rev. */
#define	ER_HARD		(0x0A)	/* retry unsuccessful */
#define	ER_FIFO		(0x0B)	/* FIFO over/under flow */
#define	ER_PARITY	(0x0D)	/* drive to tapemaster parity error */
#define	ER_CHKSUM	(0x0E)	/* prom checksum */
#define	ER_STROBE	(0x0F)	/* time out tape strobe */
#define	ER_NOTRDY	(0x10)	/* tape not ready */
#define	ER_PROT		(0x11)	/* write, no enable ring */
#define	ER_JUMPER	(0x13)	/* missing diagnostic jumper */
#define	ER_LINK		(0x14)	/* bad link, link inappropriate */
#define	ER_FM		(0x15)	/* unexpected filemark */
#define	ER_PARAM	(0x16)	/* bad parameter, byte count ? */
#define	ER_HDWERR	(0x18)	/* unidentified hardware error */
#define	ER_NOSTRM	(0x19)	/* streaming terminated */
E 2
I 2
#ifdef CYERROR
char	*cyerror[] = {
I 3
	"no error",
E 3
	"timeout",
	"timeout1",
	"timeout2",
	"timeout3",
	"timeout4", 
D 3
	"non-existant memory",
E 3
I 3
	"non-existent memory",
E 3
	"blank tape",
	"micro-diagnostic",
	"eot/bot detected",
	"retry unsuccessful",
	"fifo over/under-flow",
D 3
	"#12",
E 3
I 3
	"#0xc",
E 3
	"drive to controller parity error",
	"prom checksum",
	"time out tape strobe (record length error)",
	"tape not ready",
	"write protected",
D 3
	"#18",
E 3
I 3
	"#0x12",
E 3
	"missing diagnostic jumper",
	"invalid link pointer",
	"unexpected file mark",
D 3
	"invalid byte count",
E 3
I 3
	"invalid byte count/parameter",
	"#0x17",
E 3
	"unidentified hardware error",
	"streaming terminated"
};
#define	NCYERROR	(sizeof (cyerror) / sizeof (cyerror[0]))
#endif
E 2

I 2
/*
 * Masks defining hard and soft errors (must check against 1<<CYER_code).
 */
D 6
#define	CYMASK(e)	(1<<(CYER_/**/e))
#define	CYER_HARD	(CYMASK(TIMOUT)|CYMASK(TIMOUT1)|CYMASK(TIMOUT2)|\
    CYMASK(TIMOUT3)|CYMASK(TIMOUT4)|CYMASK(NXM)|CYMASK(DIAG)|CYMASK(JUMPER)|\
    CYMASK(STROBE)|CYMASK(PROT)|CYMASK(CKSUM)|CYMASK(HERR)|CYMASK(BLANK))
#define	CYER_SOFT	(CYMASK(FIFO)|CYMASK(NOTRDY)|CYMASK(PARITY))
E 6
I 6
#define	CYMASK(e)	(1 << (e))
#define	CYBIT(e)	(1<<(CYER_/**/e))
#define	CYER_HARD	(CYBIT(TIMOUT)|CYBIT(TIMOUT1)|CYBIT(TIMOUT2)|\
    CYBIT(TIMOUT3)|CYBIT(TIMOUT4)|CYBIT(NXM)|CYBIT(DIAG)|CYBIT(JUMPER)|\
    CYBIT(STROBE)|CYBIT(PROT)|CYBIT(CKSUM)|CYBIT(HERR)|CYBIT(BLANK))
#define	CYER_RSOFT	(CYBIT(FIFO)|CYBIT(NOTRDY)|CYBIT(PARITY))
#define	CYER_WSOFT	(CYBIT(HERR)|CYBIT(FIFO)|CYBIT(NOTRDY)|CYBIT(PARITY))
E 6
E 2
D 3

D 2
/* Channel control block definitions */
typedef struct {
	char	ccw;		/* channel control word */
	char	gate;		/* Tpb access gate */
	short	tpb_ptr[2];	/* points to first tape parameter block */
} fmt_ccb;

#define GATE_OPEN	(char)(0x00)
#define GATE_CLOSED	(char)(0xFF)
#define NORMAL_INTERUP	0x11   



/* System configuration block structrure definitions */
typedef struct {
	char	fixed_value;	/* 0x03 fixed value code */
	char	unused_scb;
	short	ccb_ptr[2];	/* pointer to ->CHANNEL CONTROL BLOCK */
} fmt_scb;


/* System configuration pointer structure definitions */
typedef struct {
	char	bus_size;	/* width of system bus 0=8; 1=16 */
	char	unused_scp;
	short	scb_ptr[2];	/* pointer to ->SYSTEM CONFIGUREATION BLOCK */
} fmt_scp;
E 2
I 2
/*
 * System configuration block
 */
struct	cyscb {
	char	csb_fixed;	/* fixed value code (must be 3) */
	char	csb_unused;	/* unused */
	short	csb_ccb[2];	/* pointer to channel control block */
};
E 2

D 2
#define	_16_BITS	1
#define	_8_BITS		0

E 2
I 2
/*
 * System configuration pointer
 */
struct	cyscp {
	char	csp_buswidth;	/* system bus width */
#define	CSP_16BITS	1	/* 16-bit system bus */
#define	CSP_8BITS	0	/* 8-bit system bus */
	char	csp_unused;
	short	csp_scb[2];	/* point to system config block */
};
E 3
E 2
E 1
