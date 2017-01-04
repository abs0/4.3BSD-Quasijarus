h61234
s 00006/00006/00343
d D 1.7 88/06/07 14:33:16 karels 7 6
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00000/00003/00349
d D 1.6 88/05/31 08:45:22 karels 6 5
c get rid of private blk* routines, use (faster) libc versions
e
s 00075/00053/00277
d D 1.5 87/11/23 15:29:09 karels 5 4
c working again, I think
e
s 00007/00006/00323
d D 1.4 87/06/01 20:59:31 sam 4 3
c header file changes (guess this works, noone's complained)
e
s 00001/00000/00328
d D 1.3 86/12/19 14:28:43 karels 3 2
c move vdtimeout from kernel header
e
s 00116/00080/00212
d D 1.2 86/11/04 21:27:24 karels 2 1
c checked in for sam
e
s 00292/00000/00000
d D 1.1 86/07/05 17:37:44 sam 1 0
c date and time created 86/07/05 17:37:44 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/*
D 2
**
*/

E 2
I 2
 * VERSAbus disk controller (vd) disk formatter.
 */
E 2
#include <setjmp.h>
#include "tahoe/mtpr.h"
#include "param.h"
#include "buf.h"
I 5
#include "disklabel.h" 
E 5
#include "inode.h" 
#include "fs.h"
#include "tahoevba/vbaparam.h"
#include "tahoevba/vdreg.h"

#include "tahoe/cp.h"
D 2
extern	struct cpdcb_i cpin;
E 2
I 2
D 7
extern	struct cpdcb_i cpin;		/* found in prf.c */
E 7
I 7
extern	struct cpdcb_i cpin;		/* found in cons.c */
E 7
E 2

/*
 * Poll console and return 1 if input is present.
 */
#define	input() \
    (uncache(&cpin.cp_hdr.cp_unit), (cpin.cp_hdr.cp_unit&CPDONE))

D 2
/* Configuration parameters */
#define	MAXCTLR		8			/* Maximum # of controllers */
#define	MAXDRIVE	16			/* Max drives per controller */
E 2
I 2
/*
 * Configuration parameters
 */
#define	MAXCTLR		8		/* Maximum # of controllers */
#define	MAXDRIVE	16		/* Max drives per controller */
E 2

D 2
#define NUMMAP		1			/* # Cyls in bad sector map */
#define	NUMMNT		1			/* # cyls for diagnostics */
#define	NUMREL		3			/* # Cyls in relocation area */
#define	NUMSYS		(NUMREL+NUMMNT+NUMMAP)	/* Total cyls used by system */
E 2
I 2
#define NUMMAP		1		/* # Cyls in bad sector map */
#define	NUMMNT		1		/* # cyls for diagnostics */
#define	NUMREL		3		/* # Cyls in relocation area */
#define	NUMSYS	(NUMREL+NUMMNT+NUMMAP)	/* Total cyls used by system */
E 2

#define	MAXTRKS		24
D 5
#define	MAXSECS_PER_TRK	64
E 5
I 5
#define	MAXSECS_PER_TRK	72		/* at 512 bytes/sector */
E 5
#define	MAXERR		1000
D 5
#define SECSIZ		512
#define	TRKSIZ		((SECSIZ/sizeof(long)) * MAXSECS_PER_TRK)
#define bytes_trk	(CURRENT->vc_nsec * SECSIZ)
E 5
I 5
#define	MAXTRKSIZ	((512/sizeof(long)) * MAXSECS_PER_TRK)
#define bytes_trk 	(lab->d_nsectors * lab->d_secsize)
E 5

D 2
#define	HARD_ERROR	(DRVNRDY | INVDADR | DNEMEM | PARERR | OPABRT | \
			 WPTERR | DSEEKERR | NOTCYLERR)
#define DATA_ERROR	(CTLRERR | UCDATERR | DCOMPERR | DSERLY | DSLATE | \
			 TOPLUS | TOMNUS | CPDCRT | \
			 HRDERR | SFTERR)
E 2
I 2
#define	HARD_ERROR \
D 4
    (DRVNRDY|INVDADR|DNEMEM|PARERR|OPABRT|WPTERR|DSEEKERR|NOTCYLERR)
E 4
I 4
    (DCBS_NRDY|DCBS_IVA|DCBS_NEM|DCBS_DPE|DCBS_OAB|DCBS_WPT|DCBS_SKI|DCBS_OCYL)
E 4
#define DATA_ERROR \
D 4
    (CTLRERR|UCDATERR|DCOMPERR|DSERLY|DSLATE|TOPLUS|TOMNUS|CPDCRT|HRDERR|SFTERR)
E 2
#define HEADER_ERROR	(HCRCERR | HCMPERR)
E 4
I 4
D 7
    (DCBS_HCE|DCBS_UDE|DCBS_DCE|DCBS_DSE|DCBS_DSL|DCBS_TOP|DCBS_TOM|DCBS_CCD|\
E 7
I 7
    (DCBS_UDE|DCBS_DCE|DCBS_DSE|DCBS_DSL|DCBS_TOP|DCBS_TOM|DCBS_CCD|\
E 7
     DCBS_HARD|DCBS_SOFT)
#define HEADER_ERROR	(DCBS_HCRC|DCBS_HCE)
E 4
#define	NRM		(short)0
#define	BAD		(short)VDUF
#define WPT		(short)(NRM | VDWPT)
#define RELOC_SECTOR	(short)(VDALT)
#define	ALT_SECTOR	(short)(VDALT)

I 2
typedef enum { false, true } boolean;
typedef enum { u_false, u_true, u_unknown } uncertain;
E 2

D 2
/* New types used by VDFORMAT */

typedef enum {false, true} boolean;	/* Standard boolean expression */

typedef enum {u_false, u_true, u_unknown} uncertain;


	/* Free bad block allocation bit map */
E 2
I 2
/*
 * Free bad block allocation bit map
 */
E 2
typedef struct {
D 7
	long	free_error;
E 7
D 2
	enum	{ALLOCATED, NOTALLOCATED} free_status;
E 2
I 2
	enum { ALLOCATED, NOTALLOCATED } free_status;
E 2
} fmt_free;

D 2
	/* Type of relocation that took place */
typedef enum {SINGLE_SECTOR, FULL_TRACK} rel_type;
E 2
I 2
typedef enum { SINGLE_SECTOR, FULL_TRACK } rel_type;	/* relocation type */
E 2

D 2
	/* Error table format */
E 2
I 2
/*
 * Error table format
 */
E 2
typedef struct {
	dskadr	err_adr;
	long	err_stat;
} fmt_err;

/* utilities */
I 2
D 6
int	blkcopy();
int	blkzero();
E 6
int	to_sector();
int	to_track();
int	data_ok();
D 6
boolean	blkcmp();
E 6
boolean	get_yes_no();
boolean	is_in_map();
boolean	is_formatted();
boolean	read_bad_sector_map();
dskadr	*from_sector();
dskadr	*from_track();
dskadr	*from_unix();
dskadr	is_relocated();
dskadr	*new_location();
E 2

D 2
int	blkcopy(), blkzero(), to_sector(), to_track(), data_ok();
boolean blkcmp(), get_yes_no(), is_in_map();
boolean	is_formatted(), read_bad_sector_map();
dskadr	*from_sector(), *from_track(), *from_unix();
dskadr	is_relocated(), *new_location();
E 2
I 2
/*
 * Operation table
 */
typedef struct {
	int	(*routine)();
	char	*op_name;
	char	*op_action;
} op_tbl;
E 2

D 2
/* Operation table */

extern int	format(), verify(), relocate(), info();
extern int	correct(), profile(), exercise();

E 2
#define	NUMOPS	7
D 2
	/* operation bit mask values (must match order in operations table) */
E 2
I 2
op_tbl	operations[NUMOPS];

/*
 * Operation bit mask values (must match order in operations table)
 */
E 2
#define	FORMAT_OP	0x01	/* Format operation bit */
#define	VERIFY_OP	0x02	/* Verify operation bit */
#define	RELOCATE_OP	0x04	/* Relocate operation bit */
#define	INFO_OP		0x08	/* Info operation bit */
#define	CORRECT_OP	0x10	/* Correct operation bit */
#define	PROFILE_OP	0x20	/* Profile operation bit */
#define	EXERCISE_OP	0x40	/* Exercise operation bit */

D 2
typedef struct {
	int	(*routine)();
	char	*op_name;
	char	*op_action;
} op_tbl;
E 2
I 2
extern	int format(), verify(), relocate(), info();
extern	int correct(), profile(), exercise();
E 2

D 2
op_tbl	operations[NUMOPS];
E 2

D 2

/* Operation table type and definitions */

E 2
I 2
/*
 * Operation table type and definitions
 */
E 2
typedef struct {
	int	op;
	int	numpat;
} op_spec;
D 2

E 2
op_spec	ops_to_do[MAXCTLR][MAXDRIVE];

I 2
/*
 * Contains all the current parameters
 */
typedef enum {
	formatted,
	half_formatted,
	unformatted,
	unknown
} drv_stat;
typedef enum {
	fmt,
	vfy,
	rel,
	cor,
	inf,
	cmd,
	exec,
	prof,
	setup
} state;
typedef enum {
	sub_chk,
	sub_rcvr,
	sub_stat,
	sub_rel,
	sub_vfy,
	sub_fmt,
D 7
	sub_sk
E 7
I 7
	sub_sk,
	sub_wmap
E 7
} substate;
E 2

D 2
/* Contains all the current parameters */

typedef enum {formatted, half_formatted, unformatted, unknown} drv_stat;
typedef enum {fmt, vfy, rel, cor, inf, cmd, exec, prof} state;
typedef enum {sub_chk,sub_rcvr,sub_stat,sub_rel,sub_vfy,sub_fmt,sub_sk}substate;

/* Different environments for setjumps */
E 2
I 2
/*
 * Different environments for setjumps
 */
E 2
jmp_buf	reset_environ;	/* Use when reset is issued */
jmp_buf	quit_environ;	/* Use when you want to quit what your doing */
jmp_buf	abort_environ;	/* Use when nothing can be done to recover */

D 2

/* Flaw map definitions and storage */

E 2
I 2
/*
 * Flaw map definitions and storage
 */
E 2
typedef struct {
	short	bs_cyl;			/* Cylinder position of flaw */
	short	bs_trk;			/* Track position of flaw */
	long	bs_offset;		/* (byte) Position of flaw on track */
	long	bs_length;		/* Length (in bits) of flaw */
	dskadr	bs_alt;			/* Addr of alt sector (all 0 if none) */
D 2
	enum {flaw_map, scanning, operator} bs_how; /* How it was found */
E 2
I 2
	enum { flaw_map, scanning, operator } bs_how; /* How it was found */
E 2
} bs_entry ;

D 2

E 2
struct {
	int		controller;
	int		drive;
	state		state;
	substate	substate;
	int		error;
	dskadr		daddr;
} cur;

D 2

/* Controller specific information */

E 2
I 2
/*
 * Controller specific information
 */
E 2
typedef struct {
	uncertain	alive;
D 4
	cdr		*addr;
E 4
I 4
	struct	vddevice *addr;
E 4
	char		*name;
	int		type;
D 7
	fmt_err		(*decode_pos)();
	bs_entry	(*code_pos)();
E 7
I 7
	fmt_err		*(*decode_pos)();
	bs_entry	*(*code_pos)();
E 7
D 5
	int		(*cylinder_skew)();
	int		(*track_skew)();
E 5
} ctlr_info;

I 2
D 5
#define	C_INFO	 c_info[cur.controller]
E 5
E 2
ctlr_info	c_info[MAXCTLR];
I 5
ctlr_info	*C_INFO;
E 5

D 2

/* drive specific information */

E 2
I 2
/*
 * Drive specific information
 */
E 2
typedef struct {
	uncertain	alive;
	int		id;
D 5
	struct	vdconfig *info;
	int		trk_size;
	int		num_slip;
	int		track_skew;
E 5
I 5
	struct		disklabel label;
E 5
	drv_stat	condition;
} drive_info;
I 5
#define	d_traksize	d_drivedata[1]
#define	d_pat		d_drivedata[2]
E 5

D 2
drive_info	d_info[MAXCTLR][MAXDRIVE];


E 2
D 5
#define	D_INFO	 d_info[cur.controller][cur.drive]
D 2
#define	C_INFO	 c_info[cur.controller]

E 2
#define	CURRENT	 D_INFO.info
E 5
I 2
drive_info	d_info[MAXCTLR][MAXDRIVE];
I 5
drive_info	*D_INFO;
struct disklabel *lab;
E 5

I 5
struct	disklabel vdproto[];
int	ndrives;
int	smddrives;

E 5
E 2
typedef struct {
	unsigned int	bs_id;		/* Pack id */
	unsigned int	bs_count;	/* number of known bad sectors */
	unsigned int	bs_max;		/* Maximum allowable bad sectors */
	bs_entry	list[1];
} bs_map;

D 5
#define MAX_FLAWS (((TRKSIZ*sizeof(long))-sizeof(bs_map))/sizeof(bs_entry))
E 5
I 5
#define MAX_FLAWS (((MAXTRKSIZ*sizeof(long))-sizeof(bs_map))/sizeof(bs_entry))
E 5

D 5
long	bs_map_space[TRKSIZ];
E 5
I 5
long	bs_map_space[MAXTRKSIZ];
E 5
D 2
bs_map		*bad_map;
E 2
I 2
bs_map	*bad_map;
E 2

D 2
boolean		kill_processes;
int		num_controllers;
E 2
I 2
boolean	kill_processes;
int	num_controllers;
I 3
extern	int vdtimeout;
E 3
E 2

D 2
/* Pattern buffers and the sort */
E 2
I 2
/*
 * Pattern buffers and the sort
 */
E 2
fmt_free	free_tbl[NUMREL*MAXTRKS][MAXSECS_PER_TRK];
D 4
fmt_mdcb	mdcb;		/* Master device control block */
fmt_dcb		dcb;		/* Device control blocks */
E 4
I 4
struct	mdcb	mdcb;		/* Master device control block */
struct	dcb	dcb;		/* Device control blocks */
E 4

D 5
long	pattern_0[TRKSIZ],  pattern_1[TRKSIZ];
long	pattern_2[TRKSIZ],  pattern_3[TRKSIZ];
long	pattern_4[TRKSIZ],  pattern_5[TRKSIZ];
long	pattern_6[TRKSIZ],  pattern_7[TRKSIZ];
long	pattern_8[TRKSIZ],  pattern_9[TRKSIZ];
long	pattern_10[TRKSIZ], pattern_11[TRKSIZ];
long	pattern_12[TRKSIZ], pattern_13[TRKSIZ];
long	pattern_14[TRKSIZ], pattern_15[TRKSIZ];
E 5
I 5
long	pattern_0[MAXTRKSIZ],  pattern_1[MAXTRKSIZ];
long	pattern_2[MAXTRKSIZ],  pattern_3[MAXTRKSIZ];
long	pattern_4[MAXTRKSIZ],  pattern_5[MAXTRKSIZ];
long	pattern_6[MAXTRKSIZ],  pattern_7[MAXTRKSIZ];
long	pattern_8[MAXTRKSIZ],  pattern_9[MAXTRKSIZ];
long	pattern_10[MAXTRKSIZ], pattern_11[MAXTRKSIZ];
long	pattern_12[MAXTRKSIZ], pattern_13[MAXTRKSIZ];
long	pattern_14[MAXTRKSIZ], pattern_15[MAXTRKSIZ];
E 5

D 2
/* Will be filled in at boot time with pointers to above patterns */
long	*pattern_address[16];
E 2
I 2
long	*pattern_address[16];	/* pointers to pattern_* */
E 2

D 2
/* Double buffer for scanning existing file systems and general scratch */
E 2
I 2
/*
 * Double buffer for scanning existing
 * file systems and general scratch
 */
E 2
D 5
long	scratch[TRKSIZ];
long	save[TRKSIZ];
E 5
I 5
long	scratch[MAXTRKSIZ];
long	save[MAXTRKSIZ];
E 5

D 2

E 2
/* XXX */
/*
 * Flaw map stuff 
 */
typedef struct {
	long	flaw_sync;
	short	flaw_cyl;
	char	flaw_trk;
	char	flaw_sec;
	struct {
		short	flaw_offset;
		short	flaw_length;
	} flaw_pos[4];
	char	flaw_status;
	char	flaw_junk[1024]; /* Fill up 518 byte block */
} flaw;

typedef struct {
	long		smde_sync;
	unsigned	adr_cyl  : 12;
	unsigned	adr_trk  : 8;
	unsigned	adr_sec  : 8;
	unsigned	sec_flgs : 4;
	unsigned	alt_cyl  : 12;
	unsigned	alt_trk  : 8;
	unsigned	alt_sec  : 8;
	char		smde_junk[1024];
} smde_hdr;

I 5
/* for MAXTOR */

typedef struct {
	unsigned long	esdi_flaw_sync;
	unsigned short	esdi_flaw_cyl;
	unsigned char	esdi_flaw_trk;
	unsigned char	esdi_flaw_sec;
	unsigned char	esdi_flags;
	unsigned char	esdi_ecc_1[2];
	unsigned char	esdi_pad_1[2];
	unsigned char	esdi_plo_sync[26];
} esdi_flaw_header;

typedef struct {
	unsigned long	esdi_data_sync;
	unsigned char	esdi_month;
	unsigned char	esdi_day;
	unsigned char	esdi_year;
	unsigned char	esdi_head;
	unsigned char	esdi_pad_2[2];
	unsigned char	esdi_flaws[50][5];  /* see esdi_flaw_entry */
	unsigned char	esdi_ecc_2[2];
	unsigned char	esdi_pad_3[2];
	char		esdi_flaw_junk[1024]; /* Fill up block */
} esdi_flaw_data;



typedef struct {
	esdi_flaw_header	esdi_header;
	esdi_flaw_data		esdi_data;
} esdi_flaw;



/*
**  since each flaw entry is 5 bytes and this forces alignment problems we
** define a structure here so that the entries can be BCOPYed into a
** reasonable work area before access.
*/

typedef struct {
	unsigned short	esdi_flaw_cyl;
	unsigned short	esdi_flaw_offset;
	unsigned char	esdi_flaw_length;
} esdi_flaw_entry;

E 5
#define	CDCSYNC		0x1919
#define	SMDSYNC		0x0019
#define	SMDESYNC	0x0009
#define	SMDE1SYNC	0x000d
I 5
#define	ESDISYNC	0x00fe
#define	ESDI1SYNC	0x00fe /* 0x00f8 */
E 5

/* XXX */

/*
D 5
 * Disk drive geometry definition.
 */
struct	geometry {
	u_short	g_nsec;		/* sectors/track */
	u_short	g_ntrak;	/* tracks/cylinder */
	u_int	g_ncyl;		/* cylinders/drive */
};

/*
E 5
 * Flaw testing patterns.
 */
struct	flawpat {
	u_int	fp_pat[16];
};
D 5

/*
 * Disk drive configuration information.
 */
struct	vdconfig {
	char	*vc_name;		/* drive name for selection */
	struct	geometry vc_geometry;	/* disk geometry */
#define	vc_nsec	vc_geometry.g_nsec
#define	vc_ntrak vc_geometry.g_ntrak
#define	vc_ncyl	vc_geometry.g_ncyl
	int	vc_nslip;		/* # of slip sectors */
	int	vc_rpm;			/* revolutions/minute */
	int	vc_traksize;		/* bits/track for flaw map interp */
	struct	flawpat *vc_pat;	/* flaw testing patterns */
	char	*vc_type;		/* informative description */
};
struct	vdconfig vdconfig[];
int	ndrives;
I 2
int	smddrives;
E 5
E 2
E 1
