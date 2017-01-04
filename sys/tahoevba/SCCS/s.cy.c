h40996
s 00010/00005/01182
d D 7.2 88/06/29 17:50:50 bostic 20 19
c install approved copyright notice
e
s 00000/00000/01187
d D 7.1 88/05/31 08:42:05 karels 19 18
c bring up to revision 7 for tahoe release
e
s 00035/00079/01152
d D 1.17 88/05/26 09:42:29 karels 18 17
c use rawread/write (for bostic)
e
s 00017/00006/01214
d D 1.16 88/05/25 18:18:20 karels 17 15
c lint; Berkeley copyright (still a bit of CCI code somewhere!)
e
s 00013/00001/01219
d R 7.1 88/05/21 18:32:47 karels 16 15
c bring up to revision 7 for tahoe release
e
s 00006/00004/01214
d D 1.15 88/05/14 11:36:22 karels 15 14
c fix WEOF on close, retry logic
e
s 00004/00001/01214
d D 1.14 87/06/30 23:39:52 karels 14 13
c vbmapalloc has a return value now
e
s 00002/00002/01213
d D 1.13 87/04/09 12:04:12 karels 13 12
c correct error returns
e
s 00039/00013/01176
d D 1.12 87/04/09 11:03:23 karels 12 11
c fix up blksize/retry for buffered reads
e
s 00039/00041/01150
d D 1.11 87/04/01 11:57:19 karels 11 10
c allocate intermediate buffers in startup (low mem + page aligned),
c remove bdbtodb
e
s 00002/00000/01189
d D 1.10 87/01/30 14:40:08 karels 10 9
c don't lose it
e
s 00124/00075/01065
d D 1.9 87/01/11 21:23:19 karels 9 8
c more or less 4.3
e
s 00018/00015/01122
d D 1.8 86/12/15 20:24:57 sam 8 7
c lint
e
s 00004/00003/01133
d D 1.7 86/11/03 12:11:29 karels 7 6
c move uncache to cpu.h
e
s 00003/00004/01133
d D 1.6 86/01/27 09:16:40 sam 6 5
c fix error reporting 
e
s 00000/00001/01137
d D 1.5 86/01/26 14:18:43 sam 5 4
c no cy.h
e
s 00858/01526/00280
d D 1.4 86/01/26 13:49:18 sam 4 3
c almost working (fsf/bsf don't work properly)
e
s 00073/00077/01733
d D 1.3 86/01/12 15:53:04 sam 3 2
c start of autoconfig
e
s 01606/00880/00204
d D 1.2 86/01/05 18:37:24 sam 2 1
c 1st working version (mostly)
e
s 01084/00000/00000
d D 1.1 85/07/21 20:36:07 sam 1 0
c date and time created 85/07/21 20:36:07 by sam
e
u
U
t
T
I 1
D 17
/*	%M%	%I%	%E%	*/
E 17
I 17
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
 *
 *	%W% (Berkeley) %G%
 */
E 17
D 2
/*	cy.c	Tahoe version 	Mar 1983.	*/
E 2

D 5
#include "cy.h"
E 5
I 4
#include "yc.h"
E 4
D 2
#if NCY > 0 /* number of CYPHER tapes in system */
E 2
I 2
#if NCY > 0
E 2
/*
D 2
 * Cypher tape driver
 *
E 2
I 2
 * Cipher Tapemaster driver.
E 2
 */
I 9
#define CYDEBUG
#ifdef	CYDEBUG
E 9
D 2
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/vm.h"
#include "../h/buf.h"
#include "../h/dir.h"
#include "../h/conf.h"
#include "../h/user.h"
#include "../h/file.h"
#include "../machine/pte.h"
#include "../vba/vbavar.h"
#include "../h/mtio.h"
#include "../machine/mtpr.h"
#include "../h/ioctl.h"
#include "../h/cmap.h"
#include "../h/uio.h"
E 2
I 2
int	cydebug = 0;
I 4
D 9
#define	dlog	if (cydebug) log
E 9
I 9
#define	dlog(params)	if (cydebug) log params
#else
#define dlog(params)	/* */
#endif
E 9
E 4
E 2

D 2
#include "../vba/cyvar.h"
E 2
I 2
D 7
#include "../tahoe/mtpr.h"
#include "../tahoe/pte.h"
E 2

E 7
D 2
#define NTM 1		/* number of TAPEMASTER controllers */
E 2
I 2
#include "param.h"
#include "systm.h"
#include "vm.h"
#include "buf.h"
#include "file.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "signal.h"
#include "uio.h"
#include "ioctl.h"
#include "mtio.h"
#include "errno.h"
#include "cmap.h"
I 4
#include "kernel.h"
#include "syslog.h"
I 8
#include "tty.h"
E 8
I 7

#include "../tahoe/cpu.h"
#include "../tahoe/mtpr.h"
#include "../tahoe/pte.h"
E 7
E 4
E 2

D 2
/*
 * There is a ccybuf per tape controller.
 * It is used as the token to pass to the control routines
 * and also acts as a lock on the slaves on the
 * controller, since there is only one per controller.
 * In particular, when the tape is rewinding on close we release
 * the user process but any further attempts to use the tape drive
 * before the rewind completes will hang waiting for ccybuf.
 */
struct	buf	ccybuf[NTM];
E 2
I 2
#include "../tahoevba/vbavar.h"
I 4
#define	CYERROR
E 4
#include "../tahoevba/cyreg.h"
E 2

D 2
/*
 * Raw tape operations use rcybuf.  The driver
 * notices when rcybuf is being used and allows the user
 * program to continue after errors and read records
 * not of the standard length (BSIZE).
 */
struct	buf	rcybuf[NTM];
long	cybufused = 0;
E 2
I 2
D 4
#define	MAXCONTROLLERS		4
#define MAX_BLOCKSIZE		(TBUFSIZ*NBPG)
#define NUM_UNIT		(NCY * 4)
E 4
I 4
/*
 * There is a ccybuf per tape controller.
 * It is used as the token to pass to the internal routines
 * to execute tape ioctls, and also acts as a lock on the slaves
 * on the controller, since there is only one per controller.
 * In particular, when the tape is rewinding on close we release
 * the user process but any further attempts to use the tape drive
 * before the rewind completes will hang waiting for ccybuf.
 */
struct	buf ccybuf[NCY];
E 4
E 2

D 2
/*
 * Driver interface routines and variables.
 */
int	cyprobe(), cyslave(), cyattach(), cydgo(), cyintr();
int	cywait(), cyrewind();
unsigned	tminphys();
struct	vba_ctlr *cyminfo[NTM];
struct	vba_device *cydinfo[NCY];
struct	buf cyutab[NCY];
short	cytotm[NCY];
extern char	cyutl[];
long	cystd[] = { 0x400000, 0 };
struct	vba_driver cydriver =
 { cyprobe, cyslave, cyattach, cydgo, cystd, "yc", cydinfo, "cy",
	cyminfo, 0 };
E 2
I 2
D 4
#define	TRUE			1
#define	FALSE			0
E 4
I 4
D 18
/*
 * Raw tape operations use rcybuf.  The driver notices when
 * rcybuf is being used and allows the user program to contine
 * after errors and read records not of the standard length.
 */
struct	buf rcybuf[NCY];
E 4
E 2

E 18
D 2
/* bits in minor device */
#define	CYUNIT(dev)	(minor(dev)&07)		/* tape unit number */
#define	TMUNIT(dev)	(cytotm[CYUNIT(dev)])	/* tape controller number */
#define	T_NOREWIND	0x08			/* no rewind bit */
#define	T_100IPS	0x10			/* high speed flag */
E 2
I 2
D 4
#define	RETRY			1
#define EXTEND			2
#define	FATAL			3
E 2

D 2
int	pflag;			/* probe flag, set every interrupt by cyintr */
E 2
I 2
#define	MAINTAIN_POSITION	0
#define	DONT_MAINTAIN_POSITION	1
E 2

D 2
#define	INF	(daddr_t)1000000L
extern int hz;
E 2
I 2
#define	PROCESSED		0x80000000
#define	SLEEPING		0x80000000
#define	b_cmd	av_back		/* only unused word in request */
E 2

D 2
struct scp	/* SYSTEM CONFIGUREATION POINTER */
{
  char sysbus ;	/* width of system buss 0=8;1=16 */
  char nu1 ;
  char pt_scb[4] ;	/* pointer to ->SYSTEM CONFIGUREATION BLOCK */
E 2
I 2
extern	int cywrite_filemark(), cysearch_fm_forw(), cysearch_fm_back();
extern	int cy_space_forw(), cy_space_back(), cyrewind_tape_ta();
extern	int cyrewind_tape_unl(), cydrive_status(), cyrewind_tape_ov();
extern	int cyraw_read(), cyraw_write(), cybuf_read(), cybuf_write();
extern	int cywait_until_ready(), cywrite_0_fm(), cywrite_1_fm();
extern	int cywrite_2_fm(), cyno_op(), cywrite_eov();

static	int (*cmd_tbl[15])() = {
	cywrite_filemark,
#define	DO_W_FM	0
	cysearch_fm_forw,
#define	DO_SFMF	1
	cysearch_fm_back,
#define	DO_SFMB	2
	cy_space_forw,
#define	DO_SPF	3
	cy_space_back,
#define	DO_SPB	4
	cyrewind_tape_ta,
#define	DO_RWTA	5
	cyrewind_tape_unl,
#define	DO_RWUN	6
	cydrive_status,
#define	DO_STAT	7
	cyrewind_tape_ov,
#define	DO_RWOV	8
	cywait_until_ready,
#define DO_WAIT 9
	cywrite_eov,
#define DO_WEOV	10
	cyraw_read,
#define DO_RRD	11
	cyraw_write,
#define DO_RWT	12
	cybuf_read,
#define DO_BRD	13
	cybuf_write
#define DO_BWT	14
E 2
};

D 2
/* absolute address - jumpered on the controller */
#define	SCP	((struct scp *)0xc0000c06)
E 2
D 3

D 2
struct Scb	/* SYSTEM CONFIGUREATION BLOCK */
{
  char sysblk[1] ;	/* 0x03 fixed value code */
  char nu2[1] ;
  char pt_ccb[4] ;	/* pointer to ->CHANNEL CONTROL BLOCK */
}Scb;
E 2
I 2
extern	int cyprobe(), cyslave(), cyattach(), cydgo();
extern unsigned	cyminsize();
E 3
#if NCY > 0
extern	char	cy0utl[];
#endif
#if NCY > 1
extern	char	cy1utl[];
#endif
E 4
I 4
int	cyprobe(), cyslave(), cyattach();
struct	buf ycutab[NYC];
short	yctocy[NYC];
E 4
D 3
static	fmt_scp *scp_ptrs[MAXCONTROLLERS] =
    { (fmt_scp *)0xc0000c06, (fmt_scp *)0xc0000c16, };
E 3
struct	vba_ctlr *cyminfo[NCY];
D 4
struct	vba_device *cydinfo[NUM_UNIT];
E 4
I 4
struct	vba_device *ycdinfo[NYC];
E 4
D 3
struct vba_driver cydriver = {
    cyprobe, cyslave, cyattach, cydgo, (long *)scp_ptrs,
    "yc", cydinfo, "cy", cyminfo
};
E 3
I 3
long	cystd[] = { 0 };
D 4
int cyprobe(), cyslave(), cyattach(), cydgo();
E 4
struct	vba_driver cydriver =
D 4
   { cyprobe, cyslave, cyattach, cydgo, cystd, "yc", cydinfo, "cy", cyminfo };
fmt_scp	*cyscp[] = { (fmt_scp *)0xc0000c06, (fmt_scp *)0xc0000c16 };
unsigned cyminsize();
E 4
I 4
   { cyprobe, cyslave, cyattach, 0, cystd, "yc", ycdinfo, "cy", cyminfo };
E 4
E 3
E 2

I 4
/* bits in minor device */
#define	YCUNIT(dev)	(minor(dev)&03)
#define	CYUNIT(dev)	(yctocy[YCUNIT(dev)])
#define	T_NOREWIND	0x04
D 9
#define	T_1600BPI	0x08
#define	T_3200BPI	0x10
E 9
I 9
#define	T_1600BPI	0x00		/* pseudo */
#define	T_3200BPI	0x08		/* unused */
E 9

#define	INF	1000000L		/* close to infinity */
D 11
#define	CYMAXIO	(32*NBPG)		/* max i/o size */
E 11

E 4
D 2
struct ccb	/* CHANNEL CONTROL BLOCK */
{
  char ccw[1] ;		/* 0x11 normal; 0x09 clear non_vect interrupt */
  char gate[1] ;	/* This is "the" GATE */
  char pt_tpb[4] ;	/* pointer to ->TAPE OPERATION BLOCK or MOVE BLOCK */
}ccb;

struct tpb	/* TAPE OPERATIONS PARAMETER BLOCK */
{
  long cmd ;		/* COMMAND (input) */
  char control[2] ;	/* CONTROL (input) */
  short count ;	/* RETURN COUNT (output) */
  short size ;	/* BUFFER SIZE (input/output) */
  short rec_over ;	/* RECORDS/OVERRUN (input/output) */
  char pt_data[4] ;	/* pointer to ->SOURCE/DEST (input) */
  char status[2] ;	/* STATUS (output) */
  char pt_link[4] ;	/* pointer to ->INTERRUPT/PARAMETER BLOCK (input) */
} tpb[NTM];

struct tpb cycool	/* tape parameter block to clear interrupts */
= {
	0L,		/* command */
	0, 0,		/* control */
	0,		/* count */
	0,		/* size */
	0,		/* rec_over */
	0, 0, 0, 0,	/* pt_data */
	0, 0,		/* status */
	0, 0, 0, 0		/* pt_link */
} ;	
E 2
/*
D 2
 * Software state per tape transport.
 *
 * 1. A tape drive is a unique-open device; we refuse opens when it is already.
 * 2. We keep track of the current position on a block tape and seek
 *    before operations by forward/back spacing if necessary.
 * 3. We remember if the last operation was a write on a tape, so if a tape
 *    is open read write and the last thing done is a write we can
 *    write a standard end of tape mark (two eofs).
E 2
I 2
D 4
 * Per-controller data structure.
E 4
I 4
 * Software state and shared command areas per controller.
 *
D 11
 * The i/o buffer must be defined statically to insure
 * it's address will fit in 20-bits (YECH!!!!!!!!!!!!!!)
E 11
I 11
 * The i/o intermediate buffer must be allocated in startup()
 * so its address will fit in 20-bits (YECH!!!!!!!!!!!!!!).
E 11
E 4
E 2
 */
D 2
struct	cy_softc {
	char	cy_openf;	/* lock against multiple opens */
	char	cy_lastiow;	/* last op was a write */
	daddr_t	cy_blkno;	/* block number, for block device tape */
	daddr_t	cy_nxrec;	/* position of end of tape, if known */
	daddr_t	cy_timo;	/* time until timeout expires */
	short	cy_tact;	/* timeout is active */
	short	cy_count;	/* return count of last operation */
	char	cy_status[2];	/* return status of last operation */
} cy_softc[NTM];
E 2
I 2
D 4
typedef struct {
	struct pte	*map;
	char		*utl;
	int		(*interupt_path)();
	label_t		environ;  /* Environment variable for longjmps */
	struct buf	*my_request;
	struct buf	*wakeup_request;
	short		bs;	  /* buffer size */
	fmt_ccb		ccb;	  /* Channel control blocks */
	fmt_scb		scb;	  /* System configuration blocks */
	fmt_tpb		tpb;	  /* Tape parameter blocks */
	fmt_tpb		last;	  /* Tape parameter blocks */
	fmt_tpb		noop;	  /* Tape parameter blocks */
	long		rawbuf[MAX_BLOCKSIZE/sizeof(long)+1];
} ctlr_tab;
E 4
I 4
struct cy_softc {
D 11
	struct	pte *cy_map;	/* pte's for mapped buffer i/o */
	caddr_t	cy_utl;		/* mapped virtual address */
E 11
	int	cy_bs;		/* controller's buffer size */
D 9
	char	cy_buf[CYMAXIO];/* intermediate buffer */
E 9
	struct	cyscp *cy_scp;	/* system configuration block address */
	struct	cyccb cy_ccb;	/* channel control block */
	struct	cyscb cy_scb;	/* system configuration block */
	struct	cytpb cy_tpb;	/* tape parameter block */
	struct	cytpb cy_nop;	/* nop parameter block for cyintr */
I 9
D 11
	char	cy_buf[CYMAXIO];/* intermediate buffer */
E 11
I 11
	struct	vb_buf cy_rbuf;	/* vba resources */
E 11
E 9
} cy_softc[NCY];
E 4
E 2

D 2
/* 
 * I/O buffer for raw devices.
 */
char cybuf[TBUFSIZ*NBPG]; 		/* 10k buffer */
E 2
I 2
D 4
extern	int cy_normal_path();
ctlr_tab ctlr_info[NCY] = {
#if NCY > 0
	{CY0map, cy0utl, cy_normal_path},
#endif
#if NCY > 1
	{CY1map, cy1utl, cy_normal_path},
#endif
};
E 4
I 4
/*
 * Software state per tape transport.
 */
struct	yc_softc {
	char	yc_openf;	/* lock against multiple opens */
	char	yc_lastiow;	/* last operation was a write */
	short	yc_tact;	/* timeout is active */
	long	yc_timo;	/* time until timeout expires */
	u_short	yc_control;	/* copy of last tpcb.tpcontrol */
	u_short	yc_status;	/* copy of last tpcb.tpstatus */
	u_short	yc_resid;	/* copy of last bc */
	u_short	yc_dens;	/* prototype control word with density info */
	struct	tty *yc_ttyp;	/* user's tty for errors */
	daddr_t	yc_blkno;	/* block number, for block device tape */
	daddr_t	yc_nxrec;	/* position of end of tape, if known */
I 9
	int	yc_blksize;	/* current tape blocksize estimate */
	int	yc_blks;	/* number of I/O operations since open */
	int	yc_softerrs;	/* number of soft I/O errors since open */
E 9
} yc_softc[NYC];
E 4
E 2

/*
D 2
 * States for um->um_tab.b_active, the per controller state flag.
 * This is used to sequence control in the driver.
E 2
I 2
D 4
 * Per-drive information.
E 4
I 4
 * States for vm->um_tab.b_active, the per controller state flag.
 * This is used to sequence control in the driver.
E 4
E 2
 */
D 2
#define	SSEEK	1		/* seeking */
#define	SIO	2		/* doing seq i/o */
#define	SCOM	3		/* sending control command */
#define	SREW	4		/* sending a drive rewind */
E 2
I 2
D 4
typedef struct {
	int		(*cleanup)();
	struct buf	u_queue;
	struct buf	rawbp;
	long		blkno;
	long		file_number;
	short		last_control;
	short		last_status;
	short		last_resid;
	unsigned long	bad_count;
	unsigned	control_proto: 16;
	unsigned	error_count  : 8;
	unsigned	open	     : 1;
	unsigned	eof	     : 1;
	unsigned	bot	     : 1;
	unsigned	eot	     : 1;
	char		*message;
} unit_tab;
unit_tab unit_info[NUM_UNIT];
E 4
I 4
#define	SSEEK	1		/* seeking */
#define	SIO	2		/* doing seq i/o */
#define	SCOM	3		/* sending control command */
#define	SREW	4		/* sending a rewind */
#define	SERASE	5		/* erase inter-record gap */
#define	SERASED	6		/* erased inter-record gap */
E 4
E 2

I 4
/* there's no way to figure these out dynamically? -- yech */
struct	cyscp *cyscp[] =
    { (struct cyscp *)0xc0000c06, (struct cyscp *)0xc0000c16 };
#define	NCYSCP	(sizeof (cyscp) / sizeof (cyscp[0]))

E 4
D 2
/*
 * Determine if there is a controller for
 * a cypher at address ctlr_vaddr.  
 * Reset the controller.
 * Our goal is to make the device interrupt.
 */
E 2
D 3
cyprobe(ctlr_vaddr)
D 2
	caddr_t ctlr_vaddr;
E 2
I 2
	register caddr_t ctlr_vaddr;
E 3
I 3
cyprobe(reg, vm)
	caddr_t reg;
	struct vba_ctlr *vm;
E 3
E 2
{
D 2
	int *ip;
E 2
I 2
D 3
	static int ctlr = -1;			/* XXX */
E 3
I 3
	register br, cvec;			/* must be r12, r11 */
I 9
	register struct cy_softc *cy;
	int ctlr = vm->um_ctlr;
E 9
I 4
D 8
	struct cy_softc *cy;
E 8
E 4
E 3
E 2

I 8
#ifdef lint
	br = 0; cvec = br; br = cvec;
	cyintr(0);
#endif
E 8
D 2
	pflag = 0;			/* clear interrupt flag */
	if (badcyaddr(ctlr_vaddr + 1))	/* check for versabuss timeout  */
E 2
I 2
D 3
	ctlr++;
	if (badcyaddr(ctlr_vaddr + 1) || 
	    !cy_init_controller(ctlr_vaddr, ctlr, 1))
E 3
I 3
	if (badcyaddr(reg+1))
E 3
E 2
		return (0);
I 3
D 4
	br = 0x13, cvec = 0x80;			/* XXX */
E 3
I 2
	return (sizeof (caddr_t));		/* XXX */
E 4
I 4
D 9
	if (vm->um_ctlr > NCYSCP || cyscp[vm->um_ctlr] == 0)	/* XXX */
		return (0);					/* XXX */
	cy_softc[vm->um_ctlr].cy_scp = cyscp[vm->um_ctlr];	/* XXX */
E 9
I 9
	if (ctlr > NCYSCP || cyscp[ctlr] == 0)		/* XXX */
		return (0);
	cy = &cy_softc[ctlr];
	cy->cy_scp = cyscp[ctlr];			/* XXX */
E 9
	/*
	 * Tapemaster controller must have interrupt handler
	 * disable interrupt, so we'll just kludge things
	 * (stupid multibus non-vectored interrupt crud).
	 */
D 9
	br = 0x13, cvec = 0x80;					/* XXX */
	return (sizeof (struct cyccb));
E 9
I 9
	if (cyinit(ctlr, reg)) {
		uncache(&cy->cy_tpb.tpcount);
		cy->cy_bs = htoms(cy->cy_tpb.tpcount);
		/*
		 * Setup nop parameter block for clearing interrupts.
		 */
		cy->cy_nop.tpcmd = CY_NOP;
		cy->cy_nop.tpcontrol = 0;
		/*
		 * Allocate page tables.
		 */
D 11
		vbmapalloc(btoc(CYMAXIO)+1, &cy->cy_map, &cy->cy_utl);
E 11
I 11
		if (cybuf == 0) {
			printf("no cy buffer!!!\n");
			return (0);
		}
		cy->cy_rbuf.vb_rawbuf = cybuf + ctlr * CYMAXIO;
D 14
		vbainit(&cy->cy_rbuf, CYMAXIO, VB_20BIT);
E 14
I 14
		if (vbainit(&cy->cy_rbuf, CYMAXIO, VB_20BIT) == 0) {
			printf("cy%d: vbainit failed\n", ctlr);
			return (0);
		}
E 14
E 11

		br = 0x13, cvec = 0x80;			/* XXX */
		return (sizeof (struct cyccb));
	} else
		return (0);
E 9
E 4
}

/*
D 3
 * Initialize the controller after a controller reset or during autoconfigure.
 * All of the system control blocks are initialized and the controller is
 * asked to configure itself for later use.
 *
 * If the print value is true cy_first_TM_attention will anounce
 * the type of controller we are (Tapemasher) and will print the size
 * of the internal controller buffer.
E 3
I 3
 * Check to see if a drive is attached to a controller.
 * Since we can only tell that a drive is there if a tape is loaded and
 * the drive is placed online, we always indicate the slave is present.
E 3
 */
D 3
cy_init_controller(ctlr_vaddr, ctlr, print)
	register caddr_t ctlr_vaddr;
	register int ctlr, print;
E 3
I 3
cyslave(vi, addr)
	struct vba_device *vi;
	caddr_t addr;
E 3
{
I 3

#ifdef lint
	vi = vi; addr = addr;
#endif
	return (1);
}

D 4
/* THIS NEEDS TO BE REWRITTEN TO MOVE STUFF TO CYPROBE */
E 4
cyattach(vi)
	struct vba_device *vi;
{
D 4
	register unit_tab *ui = &unit_info[vi->ui_unit];
	register struct buf *cq = &vi->ui_mi->um_tab;
	register struct buf *uq = cq->b_forw;
	register struct buf *start_queue = uq;
E 4
I 4
	register struct cy_softc *cy;
	int ctlr = vi->ui_mi->um_ctlr;
E 4

D 4
	(void) cy_init_controller(vi->ui_addr, vi->ui_ctlr, 1);
	/* Add unit to controllers queue */
	if (cq->b_forw == NULL) {
		cq->b_forw = &ui->u_queue;
		ui->u_queue.b_forw = &ui->u_queue;
	} else {
		while (uq->b_forw != start_queue)
			uq = uq->b_forw;
		ui->u_queue.b_forw = start_queue;
		uq->b_forw = &ui->u_queue;
E 4
I 4
	yctocy[vi->ui_unit] = ctlr;
	cy = &cy_softc[ctlr];
D 9
	if (cy->cy_bs == 0 && cyinit(ctlr)) {
		uncache(&cy->cy_tpb.tpcount);
		cy->cy_bs = htoms(cy->cy_tpb.tpcount);
		printf("cy%d: %dkb buffer\n", ctlr, cy->cy_bs/1024);
		/*
		 * Setup nop parameter block for clearing interrupts.
		 */
		cy->cy_nop.tpcmd = CY_NOP;
		cy->cy_nop.tpcontrol = 0;
		/*
		 * Allocate page tables.
		 */
		vbmapalloc(btoc(CYMAXIO)+1, &cy->cy_map, &cy->cy_utl);
E 4
	}
E 9
I 9
	if (vi->ui_slave == 0 && cy->cy_bs)
		printf("; %dkb buffer", cy->cy_bs/1024);
E 9
D 4
	ui->cleanup = cyno_op;
	ui->last_status = 0;
	ui->last_control = 0;
	ui->file_number = 0;
	ui->bad_count = 0;
	ui->blkno = 0;
	ui->open = 0;
	ui->bot = 1;
	ui->eot = 0;
	ui->eof = 0;
	ui->message = NULL;
E 4
}

/*
 * Initialize the controller after a controller reset or
 * during autoconfigure.  All of the system control blocks
 * are initialized and the controller is asked to configure
 * itself for later use.
 */
D 4
cy_init_controller(addr, ctlr, print)
	caddr_t addr;
	int ctlr, print;
E 4
I 4
D 9
cyinit(ctlr)
E 9
I 9
cyinit(ctlr, addr)
E 9
	int ctlr;
I 9
	register caddr_t addr;
E 9
E 4
{
I 4
	register struct cy_softc *cy = &cy_softc[ctlr];
D 9
	register caddr_t addr = cyminfo[ctlr]->um_addr;
E 9
E 4
E 3
	register int *pte;
D 4
	register fmt_scp *SCP;
	register fmt_scb *SCB;
	register fmt_ccb *CCB;
	register ctlr_tab *ci;
E 4

E 2
	/*
D 2
	 * Initialize the system configuration pointer
E 2
I 2
	 * Initialize the system configuration pointer.
E 2
	 */
D 2
	ip = (int *)vtopte(0, btop(SCP)); *ip &= ~PG_PROT; *ip |= PG_KW;
	mtpr(SCP, TBIS);
	SCP->sysbus = 1;			/* system width = 16 bits. */
	/* initialize the pointer to the system configuration block */
	set_pointer((int)&Scb.sysblk[0], (char *)SCP->pt_scb);
E 2
I 2
D 3
	SCP = scp_ptrs[ctlr];
E 3
I 3
D 4
	SCP = cyscp[ctlr];
E 4
E 3
	/* make kernel writable */
D 4
	pte = (int *)vtopte((struct proc *)0, btop(SCP)); 
E 4
I 4
D 11
	pte = (int *)vtopte((struct proc *)0, btop(cy->cy_scp)); 
E 11
I 11
	pte = (int *)&Sysmap[btop((int)cy->cy_scp &~ KERNBASE)]; 
E 11
E 4
	*pte &= ~PG_PROT; *pte |= PG_KW;
D 4
	mtpr(TBIS, SCP);
E 4
I 4
	mtpr(TBIS, cy->cy_scp);
E 4
	/* load the correct values in the scp */
D 4
	SCP->bus_size = _16_BITS;
	load_mbus_addr((caddr_t)&ctlr_info[ctlr].scb, SCP->scb_ptr);
E 4
I 4
	cy->cy_scp->csp_buswidth = CSP_16BITS;
	cyldmba(cy->cy_scp->csp_scb, (caddr_t)&cy->cy_scb);
E 4
	/* put it back to read-only */
	*pte &= ~PG_PROT; *pte |= PG_KR;
D 4
	mtpr(TBIS, SCP);
E 4
I 4
	mtpr(TBIS, cy->cy_scp);
E 4

E 2
	/*
D 2
	 * Initialize the system configuration block.
E 2
I 2
	 * Init system configuration block.
E 2
	 */
D 2
	Scb.sysblk[0] = 0x3;		/* fixed value */
	/* initialize the pointer to the channel control block */
	set_pointer((int)&ccb.ccw[0], (char *)Scb.pt_ccb);
E 2
I 2
D 4
	SCB = &ctlr_info[ctlr].scb;
	SCB->fixed_value = 0x3;
E 4
I 4
D 9
	cy->cy_scb.csb_fixed = 0x3;
E 9
I 9
	cy->cy_scb.csb_fixed = CSB_FIXED;
E 9
E 4
	/* set pointer to the channel control block */
D 4
	load_mbus_addr((caddr_t)&ctlr_info[ctlr].ccb, SCB->ccb_ptr);
E 4
I 4
	cyldmba(cy->cy_scb.csb_ccb, (caddr_t)&cy->cy_ccb);
E 4

E 2
	/*
D 2
	 * Initialize the channel control block.
E 2
I 2
	 * Initialize the chanel control block.
E 2
	 */
D 2
	ccb.ccw[0] = 0x11;		/* normal interrupts */
	/* initialize the pointer to the tape parameter block */
	set_pointer((int)&tpb[0], (char *)ccb.pt_tpb);
E 2
I 2
D 4
	CCB = &ctlr_info[ctlr].ccb;
	CCB->ccw = CLEAR_INTERUPT;
	CCB->gate = GATE_OPEN;
E 4
I 4
	cy->cy_ccb.cbcw = CBCW_CLRINT;
	cy->cy_ccb.cbgate = GATE_OPEN;
E 4
	/* set pointer to the tape parameter block */
D 4
	load_mbus_addr((caddr_t)&ctlr_info[ctlr].tpb, CCB->tpb_ptr);
E 4
I 4
	cyldmba(cy->cy_ccb.cbtpb, (caddr_t)&cy->cy_tpb);
E 4

E 2
	/*
D 2
	 * set the command to be CONFIGURE.
E 2
I 2
D 4
	 * Issue a noop cmd and get the internal buffer size for buffered i/o.
E 4
I 4
	 * Issue a nop cmd and get the internal buffer size for buffered i/o.
E 4
E 2
	 */
D 2
	tpb[0].cmd = CONFIG;
	tpb[0].control[0] = CW_I;	/* interrupt on completion */
	tpb[0].control[1] = CW_16bits;
	ccb.gate[0] = GATE_CLOSED;	
	*ip &= ~PG_PROT; *ip |= PG_KR;
	mtpr(SCP, TBIS);
	TM_ATTENTION(ctlr_vaddr, 0xff);	/* execute! */
	if (cywait()) return(0);
	else return(1);
E 2
I 2
D 4
	ci = &ctlr_info[ctlr];
	/* set command to be CONFIGURE */
	ci->tpb.cmd = NO_OP;
	ci->tpb.control = CW_16bits;
	ci->ccb.gate = GATE_CLOSED;	
D 3
	CY_ATTENTION(ctlr_vaddr);	/* execute! */
E 3
I 3
	CY_ATTENTION(addr);	/* execute! */
E 3
	if (cywait(&ci->ccb) || (ci->tpb.status & CS_ERm)) {
D 3
		printf("yc%d: time-out during init\n", ctlr);
E 3
I 3
		printf("cy%d: time-out during init\n", ctlr);
E 4
I 4
	cy->cy_tpb.tpcmd = CY_NOP;
	cy->cy_tpb.tpcontrol = CYCW_16BITS;
	cy->cy_ccb.cbgate = GATE_CLOSED;	
	CY_GO(addr);
	if (cywait(&cy->cy_ccb) || (cy->cy_tpb.tpstatus&CYS_ERR)) {
		uncache(&cy->cy_tpb.tpstatus);
		printf("cy%d: timeout or err during init, status=%b\n", ctlr,
		    cy->cy_tpb.tpstatus, CYS_BITS);
E 4
E 3
		return (0);
	}
D 4
	ci->tpb.cmd = CONFIG;
	ci->tpb.control = CW_16bits;
	ci->ccb.gate = GATE_CLOSED;	
D 3
	CY_ATTENTION(ctlr_vaddr);	/* execute! */
E 3
I 3
	CY_ATTENTION(addr);		/* execute! */
E 3
	if (cywait(&ci->ccb) || (ci->tpb.status & CS_ERm)) {
		cyprint_err("Tapemaster configuration failure",
		    0, ci->tpb.status);
E 4
I 4
	cy->cy_tpb.tpcmd = CY_CONFIG;
	cy->cy_tpb.tpcontrol = CYCW_16BITS;
	cy->cy_ccb.cbgate = GATE_CLOSED;	
	CY_GO(addr);
	if (cywait(&cy->cy_ccb) || (cy->cy_tpb.tpstatus&CYS_ERR)) {
		uncache(&cy->cy_tpb.tpstatus);
		printf("cy%d: configuration failure, status=%b\n", ctlr,
		    cy->cy_tpb.tpstatus, CYS_BITS);
E 4
		return (0);
	}
D 4
	uncache(&ci->tpb.count);
	ci->bs = MULTIBUS_SHORT(ci->tpb.count);
	if (print)
D 3
		printf("yc%d: %dKb buffer\n", ctlr, ci->bs/1024);
E 3
I 3
		printf("cy%d: %dKb buffer\n", ctlr, ci->bs/1024);
E 4
E 3
	return (1);
E 2
D 3
}

/*
D 2
 * Due to a design flaw, we cannot ascertain if the tape
 * exists or not unless it is on line - ie: unless a tape is
 * mounted. This is too severe a restriction to bear,
 * so all units are assumed to exist.
E 2
I 2
 * Check to see if a drive is attached to a controller.
 * Since we can only tell that a drive is there if a tape is loaded and
 * the drive is placed online, we always indicate the slave is present.
E 2
 */
D 2
/*ARGSUSED*/
cyslave(ui, ctlr_vaddr)
	struct vba_device *ui;
	caddr_t ctlr_vaddr;
E 2
I 2
cyslave(vi, addr)
	struct vba_device *vi;
	caddr_t addr;
E 2
{

I 2
#ifdef lint
	vi = vi; addr = addr;
#endif
E 2
	return (1);
}

I 2
cyattach(dev_info)
	struct vba_device *dev_info;
{
	register unit_tab *ui = &unit_info[dev_info->ui_unit];
	register struct buf *cq = &dev_info->ui_mi->um_tab;
	register struct buf *uq = cq->b_forw;
	register struct buf *start_queue = uq;

	/* Add unit to controllers queue */
	if (cq->b_forw == NULL) {
		cq->b_forw = &ui->u_queue;
		ui->u_queue.b_forw = &ui->u_queue;
	} else {
		while(uq->b_forw != start_queue)
			uq = uq->b_forw;
		ui->u_queue.b_forw = start_queue;
		uq->b_forw = &ui->u_queue;
	}
	ui->cleanup = cyno_op;
	ui->last_status = 0;
	ui->last_control = 0;
	ui->file_number = 0;
	ui->bad_count = 0;
	ui->blkno = 0;
	ui->open = FALSE;
	ui->bot = TRUE;
	ui->eot = FALSE;
	ui->eof = FALSE;
	ui->message = NULL;
E 3
}

D 4
cydgo()
{

}

/* macro to pack the unit number into Tapemaster format */
#define	UNIT(unit) \
    (((cydinfo[unit]->ui_slave & 1) << 11) | \
     ((cydinfo[unit]->ui_slave & 2) << 9) | \
     ((cydinfo[unit]->ui_slave & 4) >> 2))

E 4
I 4
int	cytimer();
/*
 * Open the device.  Tapes are unique open
 * devices, so we refuse if it is already open.
 * We also check that a tape is available, and
 * don't block waiting here; if you want to wait
 * for a tape you should timeout in user code.
 */
E 4
cyopen(dev, flag)
I 4
	dev_t dev;
E 4
	register int flag;
D 4
	register dev_t dev;
E 4
{
D 4
	register int unit = CYUNIT(dev);
	register unit_tab *ui;
E 4
I 4
	register int ycunit;
	register struct vba_device *vi;
	register struct yc_softc *yc;
D 17
	int s;
E 17
E 4

D 4
	if (unit >= NUM_UNIT || cydinfo[unit] == 0 ||
	    (ui = &unit_info[unit])->open)
E 4
I 4
	ycunit = YCUNIT(dev);
	if (ycunit >= NYC || (vi = ycdinfo[ycunit]) == 0 || vi->ui_alive == 0)
E 4
		return (ENXIO);
D 4
	ui->control_proto = UNIT(unit) | CW_INTR | CW_16bits;
	ui->blkno = 0;
	ui->bad_count = 0;
	ui->eof = 0;
	ui->open = 1;
	cycmd(dev, DO_WAIT, 1);			/* wait for tape to rewind */
	if ((ui->last_status&CS_OL) == 0) {	/* not on-line */
		ui->open = 0;
E 4
I 4
	if ((yc = &yc_softc[ycunit])->yc_openf)
		return (EBUSY);
I 9
	yc->yc_openf = 1;
E 9
#define	PACKUNIT(vi) \
    (((vi->ui_slave&1)<<11)|((vi->ui_slave&2)<<9)|((vi->ui_slave&4)>>2))
	/* no way to select density */
	yc->yc_dens = PACKUNIT(vi)|CYCW_IE|CYCW_16BITS;
I 9
	if (yc->yc_tact == 0) {
		yc->yc_timo = INF;
		yc->yc_tact = 1;
		timeout(cytimer, (caddr_t)dev, 5*hz);
	}
E 9
	cycommand(dev, CY_SENSE, 1);
	if ((yc->yc_status&CYS_OL) == 0) {	/* not on-line */
D 15
		uprintf("yc%d: not online\n", ycunit);
E 15
I 15
		uprintf("cy%d: not online\n", ycunit);
E 15
I 10
		yc->yc_openf = 0;
E 10
E 4
D 13
		return (ENXIO);
E 13
I 13
		return (EIO);
E 13
	}
D 4
	if ((flag&FWRITE) && (ui->last_status&CS_P)) {
		uprintf("cy%d: write protected\n", unit);
		ui->open = 0;
E 4
I 4
	if ((flag&FWRITE) && (yc->yc_status&CYS_WP)) {
D 15
		uprintf("yc%d: no write ring\n", ycunit);
E 15
I 15
		uprintf("cy%d: no write ring\n", ycunit);
E 15
I 10
		yc->yc_openf = 0;
E 10
E 4
D 13
		return (ENXIO);
E 13
I 13
		return (EIO);
E 13
	}
D 4
	if (ui->last_status&CS_LP) {
		ui->file_number = 0;
		ui->bot = 1;
		ui->eof = ui->eot = 0;
E 4
I 4
D 9
	yc->yc_openf = 1;
E 9
	yc->yc_blkno = (daddr_t)0;
	yc->yc_nxrec = INF;
	yc->yc_lastiow = 0;
I 9
D 12
	yc->yc_blksize = 1024;		/* guess > 0 */
E 12
I 12
	yc->yc_blksize = CYMAXIO;		/* guess > 0 */
E 12
	yc->yc_blks = 0;
	yc->yc_softerrs = 0;
E 9
	yc->yc_ttyp = u.u_ttyp;
D 9
	s = splclock();
	if (yc->yc_tact == 0) {
		yc->yc_timo = INF;
		yc->yc_tact = 1;
		timeout(cytimer, (caddr_t)dev, 5*hz);
E 4
	}
I 4
	splx(s);
E 9
E 4
	return (0);
}

I 4
/*
 * Close tape device.
 *
 * If tape was open for writing or last operation was a write,
 * then write two EOF's and backspace over the last one.
 * Unless this is a non-rewinding special file, rewind the tape.
 * Make the tape available to others.
 */
E 4
cyclose(dev, flag)
D 4
	register dev_t dev;
	register flag;
E 4
I 4
	dev_t dev;
D 9
	register int flag;
E 9
I 9
	int flag;
E 9
E 4
{
D 4
	register int unit = CYUNIT(dev);
	register unit_tab *ui = &unit_info[unit];
E 4
I 4
D 9
	register struct yc_softc *yc = &yc_softc[YCUNIT(dev)];
E 9
I 9
	struct yc_softc *yc = &yc_softc[YCUNIT(dev)];
E 9
E 4

D 4
	if (ui->last_status&CS_OL) {
		if ((flag&FWRITE) && (minor(dev)&T_NOREWIND))
			cycmd(dev, DO_WEOV, 1);
		else if ((minor(dev) & T_NOREWIND) == 0)
			cycmd(dev, DO_RWOV, 1); 
E 4
I 4
	if (flag == FWRITE || (flag&FWRITE) && yc->yc_lastiow) {
D 15
		cycommand(dev, CY_WEOF, 2);
E 15
I 15
		cycommand(dev, CY_WEOF, 1);	/* can't use count with WEOF */
		cycommand(dev, CY_WEOF, 1);
E 15
		cycommand(dev, CY_SREV, 1);
E 4
	}
D 4
	if (ui->bad_count != 0) {
#ifdef notdef
		ui->bad_count *= 889;
		uprintf("cy%d: Warning - %d.%dcm of tape were used for recovering bad spots.\n", unit, ui->bad_count/100, ui->bad_count%100);
#endif
		ui->bad_count = 0;
	}
	ui->open = 0;
E 4
I 4
	if ((minor(dev)&T_NOREWIND) == 0)
		/*
		 * 0 count means don't hang waiting for rewind complete
		 * rather ccybuf stays busy until the operation completes
		 * preventing further opens from completing by preventing
		 * a CY_SENSE from completing.
		 */
		cycommand(dev, CY_REW, 0);
I 9
	if (yc->yc_blks > 10 && yc->yc_softerrs > yc->yc_blks / 10)
		log(LOG_INFO, "yc%d: %d soft errors in %d blocks\n",
		    YCUNIT(dev), yc->yc_softerrs, yc->yc_blks);
	dlog((LOG_INFO, "%d soft errors in %d blocks\n",
	    yc->yc_softerrs, yc->yc_blks));
E 9
	yc->yc_openf = 0;
I 11
	return (0);
E 11
E 4
}

E 2
/*
D 2
 * Record attachment of the unit to the controller.
E 2
I 2
D 4
 * Cycmd is used internally to implement all the ioctl functions.
 * We duplicate the code in physio
 * that is used for syncronizing the processes (sleep / wakeup) so
 * that we can treat our internal command requests exactly like
 * regular reads and writes.  They get put on the controller queue,
 * start processes them and iodone is called to wake us up on completion.
 *
 * We don't call physio directly because it expects data to be moved
 * and has a lot more overhead than we really need.
E 4
I 4
 * Execute a command on the tape drive a specified number of times.
E 4
E 2
 */
D 2
/*ARGSUSED*/
cyattach(ui)
	struct vba_device *ui;
E 2
I 2
D 4
cycmd(dev, command, count)
	register dev_t dev;
	register int command, count;
E 4
I 4
cycommand(dev, com, count)
	dev_t dev;
	int com, count;
E 4
E 2
{
I 2
D 8
	register int unit = CYUNIT(dev);
E 8
D 4
	register unit_tab *ui = &unit_info[unit];
	register struct buf *uq;
E 4
I 4
	register struct buf *bp;
E 4
	int s;
	
I 4
	bp = &ccybuf[CYUNIT(dev)];
E 4
	s = spl3();
D 4
	while (ui->rawbp.b_flags & B_BUSY) {
		ui->rawbp.b_flags |= B_WANTED;
		sleep((caddr_t)&ui->rawbp, PRIBIO+1);
E 4
I 4
D 9
	dlog(LOG_INFO, "cycommand(%o, %x, %d), b_flags %x\n",
	    dev, com, count, bp->b_flags);
E 9
I 9
	dlog((LOG_INFO, "cycommand(%o, %x, %d), b_flags %x\n",
	    dev, com, count, bp->b_flags));
E 9
	while (bp->b_flags&B_BUSY) {
		/*
		 * This special check is because B_BUSY never
		 * gets cleared in the non-waiting rewind case.
		 */
		if (bp->b_repcnt == 0 && (bp->b_flags&B_DONE))
			break;
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO);
E 4
	}
I 4
	bp->b_flags = B_BUSY|B_READ;
E 4
	splx(s);
D 4
	/* load the request queue element */
	ui->rawbp.b_error = 0;
	ui->rawbp.b_dev = dev;
	ui->rawbp.b_cmd = (struct buf *)command;
	ui->rawbp.b_bcount = count;
	ui->rawbp.b_flags = B_PHYS | B_BUSY;
	s = spl3();
	uq = &ui->u_queue;
	ui->rawbp.av_forw = NULL;
	if (uq->av_forw == NULL) 
		uq->av_forw = &ui->rawbp;
	else
		uq->av_back->av_forw = &ui->rawbp;
	uq->av_back = &ui->rawbp;
	cystart(cydinfo[unit]->ui_mi, &ui->rawbp, s);
E 2

D 2
	/*
	 * Cytotm is used in TMUNIT to index the ccybuf and rcybuf
	 * arrays given a cy unit number.
	 */
	cytotm[ui->ui_unit] = ui->ui_mi->um_ctlr;
E 2
I 2
	/* wait for operation to complete */
	while ((ui->rawbp.b_flags&B_DONE) == 0)
		sleep((caddr_t)&ui->rawbp, PRIBIO);
	ui->rawbp.b_flags &= ~(B_PHYS | B_BUSY);
	if (ui->rawbp.b_flags & B_WANTED)
		wakeup((caddr_t)&ui->rawbp);
	return (geterror(&ui->rawbp));
E 4
I 4
	bp->b_dev = dev;
	bp->b_repcnt = count;
	bp->b_command = com;
	bp->b_blkno = 0;
	cystrategy(bp);
	/*
	 * In case of rewind from close; don't wait.
	 * This is the only case where count can be 0.
	 */
	if (count == 0)
		return;
D 9
	iowait(bp);
E 9
I 9
	biowait(bp);
E 9
	if (bp->b_flags&B_WANTED)
		wakeup((caddr_t)bp);
	bp->b_flags &= B_ERROR;
E 4
E 2
}

D 2
int	cytimer();
E 2
I 2
cystrategy(bp)
	register struct buf *bp;
{
D 4
	register int unit = CYUNIT(bp->b_dev);
	register unit_tab *ui = &unit_info[unit];	
	register struct buf *uq;
E 4
I 4
	int ycunit = YCUNIT(bp->b_dev);
	register struct vba_ctlr *vm;
	register struct buf *dp;
E 4
	int s;

D 4
	/* check the validity of the request */
	if (bp->b_bcount > MAX_BLOCKSIZE) {
		uprintf("cy%d: Maximum block size is %dk!\n",
		    unit, MAX_BLOCKSIZE/1024);
		bp->b_error = EIO;
		bp->b_resid = bp->b_bcount;
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
	}
	vbasetup(bp, MAX_BLOCKSIZE);
	if (bp->b_flags & B_PHYS)
		bp->b_cmd = (struct buf *)(bp->b_flags&B_READ? DO_RRD : DO_RWT);
	else
		bp->b_cmd = (struct buf *)(bp->b_flags&B_READ? DO_BRD : DO_BWT);
	/* place request on queue and start it */
	s = spl3();
	uq = &ui->u_queue;
E 4
I 4
	/*
	 * Put transfer at end of unit queue.
	 */
D 9
	dlog(LOG_INFO, "cystrategy(%o, %x)\n", bp->b_dev, bp->b_command);
E 9
I 9
	dlog((LOG_INFO, "cystrategy(%o, %x)\n", bp->b_dev, bp->b_command));
E 9
	dp = &ycutab[ycunit];
E 4
	bp->av_forw = NULL;
I 9
D 11
	bp->b_errcnt = 0;
E 11
E 9
D 4
	if (uq->av_forw == NULL)
		uq->av_forw = bp;
	else
		uq->av_back->av_forw = bp;
	uq->av_back = bp;
	cystart(cydinfo[unit]->ui_mi, bp, s);
}

struct	buf *cyget_next();
int	cystart_timeout();
E 2
/*
D 2
 * Open the device.  Tapes are unique open
 * devices, so we refuse if it is already open.
 * We also check that a tape is available, and
 * don't block waiting here; if you want to wait
 * for a tape you should timeout in user code.
E 2
I 2
 * Cystart is called once for every request that is placed on a
 * controller's queue.  Start is responsible for fetching requests for
 * a controller queue, starting the operation, and waiting for completion,
 * and releasing the buf structure back to UNIX or cycmd, before fetching
 * the next request.
 *
 * The controller's queue looks like this:
 *
 *                      +---------------------------------------+
 *                      |                                       | 
 *      +-----------+   |   +-----------+        +-----------+  |
 *      |  b_forw   |---+-->|  b_forw   |--~ ~-->|  b_forw   |--+
 *      +-----------+       +-----------+        +-----------+
 *      |  b_back   |       | ......... |        | ......... |
 *      +-----------+       +-----------+        +-----------+
 *      | ......... |      First unit queue     Last unit queue
 *      +-----------+          element              element
 * head of controller queue
 *  (cyminfo[ctlr].um_tab)
E 2
 */
D 2
cyopen(dev, flag)
	dev_t dev;
	int flag;
E 2
I 2
cystart(vi, bp, s)
	register struct vba_ctlr *vi;
	register struct buf *bp;
E 2
{
D 2
	register int cyunit, s;
	register struct vba_device *ui;
	register struct cy_softc *cy;
E 2
I 2
	int unit = CYUNIT(bp->b_dev), ctlr = vi->um_ctlr;
	register struct buf *next, *cq = &vi->um_tab;
	register unit_tab *ui = &unit_info[unit];
	register ctlr_tab *ci = &ctlr_info[ctlr];
E 2

D 2
	cyunit = CYUNIT(dev);
	if (cyunit>=NCY || (cy = &cy_softc[cyunit])->cy_openf ||
	    (ui = cydinfo[cyunit]) == 0 || ui->ui_alive == 0)
		return ENXIO;
	cycommand(dev, (int)DRIVE_S, 1);	/* drive status */
	uncache(&tpb[cyunit].status[0]);
	if ((tpb[cyunit].status[0]&(CS_DR|CS_OL)) != (CS_DR|CS_OL)) {
		uprintf("cy%d: not online\n", cyunit);
		return EIO;
E 2
I 2
	if (cq->b_active&SLEEPING) {
		untimeout(cystart_timeout, (caddr_t)cq);
		cystart_timeout(cq);
E 2
	}
D 2
	if ((flag&FWRITE) && (tpb[cyunit].status[0]&CS_P)) {
		uprintf("cy%d: no write ring\n", cyunit);
		return EIO;
E 2
I 2
	if (cq->b_active) {
		sleep((caddr_t)bp, PRIBIO-1);
		if (bp->b_flags&PROCESSED) {
			if (ui->message) {
				uprintf("cy%d: %s\n", unit, ui->message);
				ui->message = 0;
			}
			bp->b_flags &= ~PROCESSED;
E 4
I 4
	vm = ycdinfo[ycunit]->ui_mi;
	/* BEGIN GROT */
D 18
	if (bp == &rcybuf[CYUNIT(bp->b_dev)]) {
E 18
I 18
	if (bp->b_flags & B_RAW) {
E 18
D 12
		if (bp->b_bcount > CYMAXIO) {
E 12
I 12
		if (bp->b_bcount >= CYMAXIO) {
E 12
			uprintf("cy%d: i/o size too large\n", vm->um_ctlr);
D 12
			bp->b_error = EIO;
E 12
I 12
			bp->b_error = EINVAL;
E 12
			bp->b_resid = bp->b_bcount;
			bp->b_flags |= B_ERROR;
E 4
D 9
			iodone(bp);
E 9
I 9
			biodone(bp);
E 9
			return;
		}
I 4
D 11
		vbasetup(bp, CYMAXIO);
E 11
E 4
E 2
	}
D 2
	cy->cy_openf = 1;
	cy->cy_blkno = (daddr_t)0;
	cy->cy_nxrec = INF;
	cy->cy_lastiow = 0;
	s = spl8();
	if (cy->cy_tact == 0) {
		cy->cy_timo = INF;
		cy->cy_tact = 1;
		timeout(cytimer, (caddr_t)dev, 5*hz);
	}
E 2
I 2
D 4
	cq->b_active = 1;
E 2
	splx(s);
D 2
	return 0;
E 2
I 2
	ci->my_request = bp;
	cydo_my_command(ctlr, cq, ci);
	if (ui->message) {
		uprintf("cy%d: %s\n", unit, ui->message);
		ui->message = 0;
	}
	bp->b_flags &= ~PROCESSED;
	iodone(bp);
	if ((next = cyget_next(cq)) != NULL)
		wakeup((caddr_t)next);
	else
		cq->b_active = 0;
E 2
}

/*
D 2
 * Close tape device.
 *
 * If tape was open for writing or last operation was
 * a write, then write two EOF's and backspace over the last one.
 * Unless this is a non-rewinding special file, rewind the tape.
 * Make the tape available to others.
E 2
I 2
 * Cystart_timeout wakes up the start routine after it's 3
 * second wait time is up or when a new command enters the queue.
 * The timer is used to give up the processor while all drives
 * on the queue are rewinding and we need to wait for them to be dome.
E 2
 */
D 2
cyclose(dev, flag)
	register dev_t dev;
	register flag;
E 2
I 2
cystart_timeout(cq)
	register struct buf *cq;
E 2
{
D 2
	register struct cy_softc *cy = &cy_softc[CYUNIT(dev)];
E 2

D 2
	if (flag == FWRITE || (flag&FWRITE) && cy->cy_lastiow) {
		cycommand(dev, (int)WRIT_FM, 1);	/* write file mark */
		cycommand(dev, (int)WRIT_FM, 1);
		cycommand(dev, (int)SP_BACK, 1);	/* space back */
E 2
I 2
	cq->b_active &= ~SLEEPING;
	wakeup((caddr_t)cq);
}

/*
 * Cydo_my command scans the request queues once for a
 * particular controller and calls the appropriate processing routine
 * each time we find a request that can be started.
 */
cydo_my_command(ctlr, cq, ci)
	register struct buf *cq;
	register ctlr_tab *ci;
{
	register struct buf *next;

	while ((next = cyget_next(cq)) != NULL) {
		if (cq->b_forw->b_active&SLEEPING) {
			cq->b_active |= SLEEPING;
			timeout(cystart_timeout, (caddr_t)cq, 1*60);
			sleep((caddr_t)cq, PRIBIO);
			continue;
		}
		if (setjmp(&ctlr_info[ctlr].environ))
			cydone(cq);
		else {
			register int cmd = (int)next->b_cmd;

			(*cmd_tbl[cmd])(next, cq);
		}
		if (next->b_flags & PROCESSED) {
			if (ci->my_request == next)
				break;
			wakeup((caddr_t)next);
		}
E 2
	}
D 2
	if ((minor(dev)&T_NOREWIND) == 0)
		/*
		 * 0 count means don't hang waiting for rewind complete
		 * rather ccybuf stays busy until the operation completes
		 * preventing further opens from completing by
		 * preventing a SENSE operation from completing.
		 */
		cycommand(dev, (int)REWD_TA, 0);
	cy->cy_openf = 0;
E 2
}

D 2
int commflag;	/* signal cystrategy that it is called from cycommand */
E 2
I 2
struct buf *
cyget_next(cq)
	register struct	buf *cq;
{
	register struct buf *bp, *uq, *next = NULL;
E 2

I 2
	cq->b_forw = cq->b_forw->b_forw;
	uq = cq->b_forw;
	do {
		if ((bp = uq->av_forw) != NULL) {
			if ((uq->b_active&SLEEPING) == 0) {
				cq->b_forw = uq;
				return (bp);
			}
			next = uq;
		}
		uq = uq->b_forw;
	} while(uq != cq->b_forw);
	if (next != NULL) {
		cq->b_forw = next;
		return (next->av_forw);
	}
	return (NULL);
}

E 2
/*
D 2
 * Execute a command on the tape drive
 * a specified number of times.
E 2
I 2
 * Mark the current command on the controller's q completed and remove it.
E 2
 */
D 2
cycommand(dev, com, count)
	dev_t dev;
	int com, count;
E 2
I 2
cydone(cq)
	struct buf *cq;
E 2
{
D 2
	register struct buf *bp;
E 2
I 2
	register struct buf *uq = cq->b_forw;
E 2
	int s;

D 2
	bp = &ccybuf[TMUNIT(dev)];
	s = spl8();
	while (bp->b_flags&B_BUSY) {
		/*
		 * This special check is because B_BUSY never
		 * gets cleared in the non-waiting rewind case.
		 */
		if (bp->b_repcnt == 0 && (bp->b_flags&B_DONE))
			break;
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO);
	}
	bp->b_flags = B_BUSY|B_READ;
E 2
I 2
	uq->av_forw->b_flags |= PROCESSED;
E 4
I 4
	/* END GROT */
E 4
	s = spl3();
D 4
	if ((uq->av_forw = uq->av_forw->av_forw) == NULL) 
		uq->av_back = NULL;
E 4
I 4
	if (dp->b_actf == NULL) {
		dp->b_actf = bp;
		/*
		 * Transport not already active...
		 * put at end of controller queue.
		 */
		 dp->b_forw = NULL;
		 if (vm->um_tab.b_actf == NULL)
			vm->um_tab.b_actf = dp;
		else
			vm->um_tab.b_actl->b_forw = dp;
	} else
		dp->b_actl->av_forw = bp;
	dp->b_actl = bp;
	/*
	 * If the controller is not busy, get it going.
	 */
	if (vm->um_tab.b_active == 0)
		cystart(vm);
E 4
E 2
	splx(s);
D 2
	bp->b_dev = dev;
	bp->b_repcnt = count;
	bp->b_command = com;
	bp->b_blkno = 0;
	commflag = 1;
	cystrategy(bp);
	commflag = 0;
	/*
	 * In case of rewind from close, don't wait.
	 * This is the only case where count can be 0.
	 */
	if (count == 0)
		return;
	iowait(bp);
	if (bp->b_flags&B_WANTED)
		wakeup((caddr_t)bp);
	bp->b_flags &= B_ERROR;
E 2
}

/*
D 2
 * Queue a tape operation.
E 2
I 2
D 4
 * The following routines implement the individual commands.
 *
 * Each command is responsible for a few things. 1) Each has to keep
 * track of special cases that are related to the individual command and
 * the previous commands sequence, 2) each is required to call iodone when
 * command is actually finished, 3) it must use cyexecute to actually
 * start the controller, and 4) they are required to keep the tape in
 * a consistant state so that other commands will not be messed up.
E 4
I 4
 * Start activity on a cy controller.
E 4
E 2
 */
D 2
cystrategy(bp)
E 2
I 2
D 4

/*
 * Read requests from the raw device.
 * The special cases are:
 *  1) we can not read after a write.  (writting defines end of file)
 *  2) reading past end of file returns 0 bytes;
 */
cyraw_read(bp, cq)
E 2
	register struct buf *bp;
I 2
	struct buf *cq;
E 4
I 4
cystart(vm)
	register struct vba_ctlr *vm;
E 4
E 2
{
D 2
	int cyunit = CYUNIT(bp->b_dev);
	int s;
	register struct vba_ctlr *um;
	register struct buf *dp;
E 2
I 2
D 4
	int unit = CYUNIT(bp->b_dev);
	register unit_tab *ui = &unit_info[unit];
	register ctlr_tab *ci = &ctlr_info[cydinfo[unit]->ui_ctlr];
	int addr, lock_flag, command;
E 4
I 4
	register struct buf *bp, *dp;
	register struct yc_softc *yc;
	register struct cy_softc *cy;
D 8
	register struct vba_device *vi;
E 8
	int ycunit;
	daddr_t blkno;
E 4
E 2

D 2
	/*
	 * Put transfer at end of unit queue
	 */
	dp = &cyutab[cyunit];
	bp->av_forw = NULL;
	s = spl8();
E 2
I 2
D 4
	if (ui->cleanup != cyno_op || ui->eof) {
		bp->b_resid = bp->b_bcount;
		bp->b_error = ENXIO, bp->b_flags |= B_ERROR;
		cydone(cq);
E 4
I 4
D 9
	dlog(LOG_INFO, "cystart()\n");
E 9
I 9
	dlog((LOG_INFO, "cystart()\n"));
E 9
	/*
	 * Look for an idle transport on the controller.
	 */
loop:
	if ((dp = vm->um_tab.b_actf) == NULL)
E 4
		return;
I 4
	if ((bp = dp->b_actf) == NULL) {
		vm->um_tab.b_actf = dp->b_forw;
		goto loop;
E 4
	}
D 4
	if (bp->b_bcount > ci->bs)
		command = READ_TA, lock_flag = CW_LOCK;
	else
		command = READ_BU, lock_flag = 0;
	ui->blkno++;
	addr = vbastart(bp, (caddr_t)ci->rawbuf, (long *)ci->map, ci->utl);
	cyexecute(command, bp->b_bcount, addr, lock_flag, unit, 10, FALSE);
	vbadone(bp, (caddr_t)ci->rawbuf, (long *)ci->map, ci->utl);
	cydone(cq);
}

E 2
/*
D 2
 * Next piece of logic takes care of unusual cases when more than
 * a full block is required. 
 * The driver reads the tape to a temporary buffer and
 * then moves the amount needed back to the process.
 * In this case, the flag NOT1K is set.
E 2
I 2
 * Write requests from the raw device.
 * The special cases are:
 *  1) we don't allow writes after end of tape is reached.
E 2
 */
I 2
cyraw_write(bp, cq)
	register struct buf *bp;
	struct buf *cq;
{
	int unit = CYUNIT(bp->b_dev);
	register unit_tab *ui = &unit_info[CYUNIT(unit)];
	register ctlr_tab *ci = &ctlr_info[cydinfo[unit]->ui_ctlr];
	int addr, lock_flag, command;
E 2

D 2
	if (commflag == 0)
		buf_setup(bp, 1);
	um = cydinfo[cyunit]->ui_mi;
	if (dp->b_actf == NULL) {
		dp->b_actf = bp;
		/*
		 * Transport not already active...
		 * put at end of controller queue.
		 */
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
	} else
		dp->b_actl->av_forw = bp;
	dp->b_actl = bp;
	/*
	 * If the controller is not busy, get
	 * it going.
	 */
	if (um->um_tab.b_active == 0)
		cystart(um);
	splx(s);
E 2
I 2
	if (ui->eot) {
		bp->b_resid = bp->b_bcount;
		bp->b_error = ENXIO, bp->b_flags |= B_ERROR;
		longjmp(&ci->environ);
E 4
I 4
	ycunit = YCUNIT(bp->b_dev);
	yc = &yc_softc[ycunit];
	cy = &cy_softc[CYUNIT(bp->b_dev)];
	/*
	 * Default is that last command was NOT a write command;
	 * if we do a write command we will notice this in cyintr().
	 */
	yc->yc_lastiow = 0;
	if (yc->yc_openf < 0 ||
	    (bp->b_command != CY_SENSE && (cy->cy_tpb.tpstatus&CYS_OL) == 0)) {
		/*
		 * Have had a hard error on a non-raw tape
		 * or the tape unit is now unavailable (e.g.
		 * taken off line).
		 */
D 9
		dlog(LOG_INFO, "openf %d command %x status %b\n",
		    yc->yc_openf, bp->b_command, cy->cy_tpb.tpstatus, CYS_BITS);
E 9
I 9
		dlog((LOG_INFO, "openf %d command %x status %b\n",
		   yc->yc_openf, bp->b_command, cy->cy_tpb.tpstatus, CYS_BITS));
E 9
		bp->b_flags |= B_ERROR;
		goto next;
E 4
	}
D 4
	ui->cleanup = cywrite_2_fm;
	if (bp->b_bcount > ci->bs)
		command = WRIT_TA, lock_flag = CW_LOCK;
	else
		command = WRIT_BU, lock_flag = 0;
	ui->blkno++;
	addr = vbastart(bp, (caddr_t)ci->rawbuf, (long *)ci->map, ci->utl);
	cyexecute(command, bp->b_bcount, addr, lock_flag, unit, 10, FALSE);
	vbadone(bp, (caddr_t)ci->rawbuf, (long *)ci->map, ci->utl);
	cydone(cq);
E 2
}

/*
D 2
 * Start activity on a cypher controller.
E 2
I 2
 * Write a filemark on a tape.
E 2
 */
D 2
cystart(um)
	register struct vba_ctlr *um;
E 2
I 2
cywrite_filemark(bp, cq)
	register struct buf *bp;
	struct buf *cq;
E 2
{
D 2
	register struct buf *bp, *dp;
	register struct tpb *tp; 
	register struct cy_softc *cy;
	register int phadr;
	int cyunit, timer;
	daddr_t blkno;
	caddr_t	ctlr_vaddr;
	ctlr_vaddr = um->um_addr;
	/*
	 * Look for an idle transport on the controller.
	 */
loop:
	if ((dp = um->um_tab.b_actf) == NULL)
E 2
I 2
	int unit = CYUNIT(bp->b_dev);
	register unit_tab *ui = &unit_info[CYUNIT(unit)];

	if (bp->b_bcount == 0) {
		cydone(cq);
E 2
		return;
D 2
	if ((bp = dp->b_actf) == NULL) {
		um->um_tab.b_actf = dp->b_forw;
		goto loop;
E 2
	}
D 2
	cyunit = CYUNIT(bp->b_dev);
	cy = &cy_softc[cyunit];
	tp = &tpb[cyunit];
	/*
	 * Default is that last command was NOT a write command;
	 * if we do a write command we will notice this in cyintr().
	 */
	cy->cy_lastiow = 0;
	uncache(&tp->status[0]);
	uncache(&tp->count);
	cy->cy_count = TM_SHORT(tp->count);
	cy->cy_status[0] = tp->status[0];
	cy->cy_status[1] = tp->status[1];
	if (cy->cy_openf < 0 || 
		(bp->b_command != DRIVE_S) && 
		((tp->status[0]&CS_OL) != CS_OL)) {
		/*
		 * Have had a hard error on a non-raw tape
		 * or the tape unit is now unavailable
		 * (e.g. taken off line).
		 */
		bp->b_flags |= B_ERROR;
		goto next;
E 2
I 2
	bp->b_bcount--;
	if (ui->cleanup == cywrite_1_fm)
		ui->cleanup = cywrite_0_fm;
	if (ui->cleanup == cywrite_2_fm || ui->cleanup == cyno_op)
		ui->cleanup = cywrite_1_fm;
	ui->file_number++;
	ui->eof = 1;
	ui->blkno = 0;
	cyexecute(WRIT_FM, (long)1, 0, 0, unit, 10, FALSE);
}

/*
**	cysearch_fm_forw is the ioctl to search for a filemark in the
**  forward direction on tape.
**
**	Since only one device can be active on a given controller at any
**  given instant in time, we try to be nice and let onther devices  on
**  this controller be scheduled after we space over each record.  This will
**  at least give the apperance of overlapped operations on the controller.
**
**  The special cases are:
**  1) if the last command was a write the we can't search.
*/

cysearch_fm_forw(request, cq)
register struct buf	*request;
register struct buf	*cq;
{
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[CYUNIT(unit)];
	register int		ctlr = cydinfo[unit]->ui_ctlr;
	register ctlr_tab	*ci = &ctlr_info[ctlr];

	if((ui->cleanup != cyno_op) || ui->eot) {
		request->b_resid = request->b_bcount;
		request->b_error = ENXIO, request->b_flags |= B_ERROR;
		longjmp(&ci->environ);
E 2
	}
D 2
	if (bp == &ccybuf[TMUNIT(bp->b_dev)]) {
		/*
		 * Execute control operation with the specified count.
		 * Set next state; give 5 minutes to complete
		 * rewind, or 10 seconds per iteration (minimum 60
		 * seconds and max 5 minutes) to complete other ops.
		 */
		if (bp->b_command == REWD_TA) {
			um->um_tab.b_active = SREW;
			cy->cy_timo = 5 * 60;
		} else {
			um->um_tab.b_active = SCOM;
			cy->cy_timo = imin(imax(10*(int)bp->b_repcnt, 60), 5*60);
E 2
I 2
	if(request->b_bcount && !ui->eot) {
		if(!ui->eot) {
			ui->blkno++;
			cyexecute(SPAC_FM, (long)1, 0, 0, unit, 5, FALSE);
			if(!(ui->eof || ui->eot))
				return;
E 4
I 4
	if (bp == &ccybuf[CYUNIT(bp->b_dev)]) {
		/*
		 * Execute control operation with the specified count.
		 *
		 * Set next state; give 5 minutes to complete
		 * rewind or file mark search, or 10 seconds per
		 * iteration (minimum 60 seconds and max 5 minutes)
		 * to complete other ops.
		 */
		if (bp->b_command == CY_REW) {
			vm->um_tab.b_active = SREW;
			yc->yc_timo = 5*60;
I 12
		} else if (bp->b_command == CY_FSF ||
		    bp->b_command == CY_BSF) {
			vm->um_tab.b_active = SCOM;
			yc->yc_timo = 5*60;
E 12
		} else {
			vm->um_tab.b_active = SCOM;
			yc->yc_timo = imin(imax(10*(int)bp->b_repcnt,60),5*60);
E 4
E 2
		}
D 2
		/*
		 * Prepare parameter block for controller
		 */
		tp->cmd = bp->b_command;
		tp->control[0] = (CW_I | (cyunit<<CW_TSs));
		if (minor(bp->b_dev)&T_100IPS)
			tp->control[1] = (CW_100ips | CW_16bits);
		else	tp->control[1] = (CW_25ips | CW_16bits);
		if (bp->b_command == SP_BACK) {
			tp->control[1] |= CW_R;
			tp->cmd = SPACE;
			tp->rec_over = TM_SHORT((short)bp->b_repcnt);
E 2
I 2
D 4
		request->b_bcount--;
		ui->eof = FALSE;
		if(!ui->eot) {
			ui->file_number++;
			ui->blkno = 0;
			return;
E 2
		}
E 4
I 4
		cy->cy_tpb.tprec = htoms(bp->b_repcnt);
I 11
		dlog((LOG_INFO, "bpcmd "));
E 11
		goto dobpcmd;
E 4
D 2
		if (bp->b_command == SP_FORW) 
			tp->rec_over = TM_SHORT((short)bp->b_repcnt);
		if (bp->b_command == SRFM_BK) {
			tp->control[1] |= CW_R;
			tp->cmd = SERH_FM;
			tp->rec_over = TM_SHORT((short)bp->b_repcnt);
		}
		if (bp->b_command == SRFM_FD) 
			tp->rec_over = TM_SHORT((short)bp->b_repcnt);
		tp->status[0] = tp->status[1] = 0;
		tp->count = 0;
		set_pointer((int)&tpb[cyunit], (char *)ccb.pt_tpb);
		goto dobpcmd;
E 2
	}
D 2
	/*
	 * The following checks handle boundary cases for operation
	 * on non-raw tapes.  On raw tapes the initialization of
	 * cy->cy_nxrec by cyphys causes them to be skipped normally
	 */
	if (bdbtofsb(bp->b_blkno) > cy->cy_nxrec) {
		/*
		 * Can't read past known end-of-file.
		 */
		bp->b_flags |= B_ERROR;
		bp->b_error = ENXIO;
		goto next;
E 2
I 2
D 4
	if(ui->eot) {
		request->b_resid = request->b_bcount;
		request->b_flags |= B_ERROR, request->b_error = ENXIO;
E 4
I 4
	/*
D 18
	 * The following checks handle boundary cases for operation
	 * on no-raw tapes.  On raw tapes the initialization of
	 * yc->yc_nxrec by cyphys causes them to be skipped normally
	 * (except in the case of retries).
E 18
I 18
	 * For raw I/O, save the current block
	 * number in case we have to retry.
E 18
	 */
D 11
	if (bdbtofsb(bp->b_blkno) > yc->yc_nxrec) {
E 11
I 11
D 18
	if (bp->b_blkno > yc->yc_nxrec) {
E 18
I 18
	if (bp->b_flags & B_RAW) {
		if (vm->um_tab.b_errcnt == 0) {
			yc->yc_blkno = bp->b_blkno;
			yc->yc_nxrec = yc->yc_blkno + 1;
		}
	} else {
E 18
E 11
		/*
D 18
		 * Can't read past known end-of-file.
E 18
I 18
		 * Handle boundary cases for operation
		 * on non-raw tapes.
E 18
		 */
D 18
		bp->b_flags |= B_ERROR;
		bp->b_error = ENXIO;
		goto next;
E 18
I 18
		if (bp->b_blkno > yc->yc_nxrec) {
			/*
			 * Can't read past known end-of-file.
			 */
			bp->b_flags |= B_ERROR;
			bp->b_error = ENXIO;
			goto next;
		}
		if (bp->b_blkno == yc->yc_nxrec && bp->b_flags&B_READ) {
			/*
			 * Reading at end of file returns 0 bytes.
			 */
			bp->b_resid = bp->b_bcount;
			clrbuf(bp);
			goto next;
		}
		if ((bp->b_flags&B_READ) == 0)
			/*
			 * Writing sets EOF.
			 */
			yc->yc_nxrec = bp->b_blkno + 1;
E 18
E 4
E 2
	}
D 2
	if (bdbtofsb(bp->b_blkno) == cy->cy_nxrec &&
	    bp->b_flags&B_READ) {
		/*
		 * Reading at end of file returns 0 bytes.
		 */
		bp->b_resid = bp->b_bcount;
		clrbuf(bp);
		goto next;
E 2
I 2
D 4
	cydone(cq);
}
E 4
I 4
D 11
	if (bdbtofsb(bp->b_blkno) == yc->yc_nxrec && bp->b_flags&B_READ) {
E 11
I 11
D 18
	if (bp->b_blkno == yc->yc_nxrec && bp->b_flags&B_READ) {
E 11
		/*
		 * Reading at end of file returns 0 bytes.
		 */
		bp->b_resid = bp->b_bcount;
		clrbuf(bp);
		goto next;
	}
	if ((bp->b_flags&B_READ) == 0)
		/*
		 * Writing sets EOF.
		 */
D 11
		yc->yc_nxrec = bdbtofsb(bp->b_blkno) + 1;
	if ((blkno = yc->yc_blkno) == bdbtofsb(bp->b_blkno)) {
E 11
I 11
		yc->yc_nxrec = bp->b_blkno + 1;
E 18
	if ((blkno = yc->yc_blkno) == bp->b_blkno) {
E 11
		caddr_t addr;
		int cmd;
E 4

D 4

/*
**	cysearch_fm_back is the ioctl to search for a filemark in the
**  reverse direction on tape.
**
**	Since only one device can be active on a given controller at any
**  given instant in time, we try to be nice and let onther devices  on
**  this controller be scheduled after we space over each record.  This will
**  at least give the apperance of overlapped operations on the controller.
**
**  The special cases are:
**  1) can't search past begining of tape.
**  2) if the lasr operation was a write data then we need to add
**     an end of volume record before we start searching.
*/

cysearch_fm_back(request, cq)
register struct buf	*request;
register struct buf	*cq;
{
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[CYUNIT(unit)];

	if(!ui->bot) {
		(*ui->cleanup)(unit, MAINTAIN_POSITION);
		if(ui->blkno == 0)
			request->b_bcount++;
		ui->blkno = 0xffffffff;
		if(request->b_bcount && !ui->bot) {
			cyexecute(SPAC_FM, (long)1, 0, CW_REV, unit, 6, FALSE);
			if(ui->eof) {
				ui->eof = FALSE;
				ui->file_number--;
				request->b_bcount--;
E 4
I 4
		/*
		 * Choose the appropriate i/o command based on the
D 9
		 * transfer size and the controller's internal buffer.
E 9
I 9
		 * transfer size, the estimated block size,
		 * and the controller's internal buffer size.
I 12
		 * If the request length is longer than the tape
		 * block length, a buffered read will fail,
		 * thus, we request at most the size that we expect.
		 * We then check for larger records when the read completes.
E 12
E 9
		 * If we're retrying a read on a raw device because
		 * the original try was a buffer request which failed
		 * due to a record length error, then we force the use
		 * of the raw controller read (YECH!!!!).
		 */
		if (bp->b_flags&B_READ) {
D 9
			if (bp->b_bcount > cy->cy_bs || bp->b_errcnt)
E 9
I 9
D 12
			if ((bp->b_bcount > cy->cy_bs &&
D 11
			    yc->yc_blksize > cy->cy_bs) || bp->b_errcnt)
E 11
I 11
			    yc->yc_blksize > cy->cy_bs) || vm->um_tab.b_errcnt)
E 11
E 9
				cmd = CY_RCOM;
			else
E 12
I 12
			if (yc->yc_blksize <= cy->cy_bs &&
			    vm->um_tab.b_errcnt == 0)
E 12
				cmd = CY_BRCOM;
I 12
			else
				cmd = CY_RCOM;
E 12
		} else {
			/*
			 * On write error retries erase the
			 * inter-record gap before rewriting.
			 */
			if (vm->um_tab.b_errcnt &&
			    vm->um_tab.b_active != SERASED) {
				vm->um_tab.b_active = SERASE;
				bp->b_command = CY_ERASE;
				yc->yc_timo = 60;
				goto dobpcmd;
E 4
			}
D 4
			return;
E 4
I 4
			cmd = (bp->b_bcount > cy->cy_bs) ? CY_WCOM : CY_BWCOM;
E 4
		}
D 4
		if(ui->bot) {
			ui->file_number = 0;
			if(request->b_bcount) {
				request->b_resid = request->b_bcount;
				request->b_error = ENXIO;
				request->b_flags |= B_ERROR;
			}
		}
		else {
			request->b_cmd = (struct buf *)DO_SFMF;
			request->b_bcount = 1;
			return;
		}
E 4
I 4
		vm->um_tab.b_active = SIO;
D 11
		addr = (caddr_t)vbastart(bp, cy->cy_buf,
		    (long *)cy->cy_map, cy->cy_utl);
E 11
I 11
		addr = (caddr_t)vbasetup(bp, &cy->cy_rbuf, 1);
E 11
		cy->cy_tpb.tpcmd = cmd;
		cy->cy_tpb.tpcontrol = yc->yc_dens;
		if (cmd == CY_RCOM || cmd == CY_WCOM)
			cy->cy_tpb.tpcontrol |= CYCW_LOCK;
		cy->cy_tpb.tpstatus = 0;
		cy->cy_tpb.tpcount = 0;
		cyldmba(cy->cy_tpb.tpdata, (caddr_t)addr);
		cy->cy_tpb.tprec = 0;
D 9
		cy->cy_tpb.tpsize = htoms(bp->b_bcount);
E 9
I 9
D 12
		if (cmd == CY_BRCOM && bp->b_bcount > cy->cy_bs)
			cy->cy_tpb.tpsize = htoms(cy->cy_bs);
E 12
I 12
		if (cmd == CY_BRCOM)
D 17
			cy->cy_tpb.tpsize = htoms(min(yc->yc_blksize,
			    bp->b_bcount));
E 17
I 17
			cy->cy_tpb.tpsize = htoms(imin(yc->yc_blksize,
			    (int)bp->b_bcount));
E 17
E 12
		else
			cy->cy_tpb.tpsize = htoms(bp->b_bcount);
E 9
		cyldmba(cy->cy_tpb.tplink, (caddr_t)0);
		do
			uncache(&cy->cy_ccb.cbgate);
		while (cy->cy_ccb.cbgate == GATE_CLOSED);
		cyldmba(cy->cy_ccb.cbtpb, (caddr_t)&cy->cy_tpb);
		cy->cy_ccb.cbcw = CBCW_IE;
		cy->cy_ccb.cbgate = GATE_CLOSED;
D 9
		dlog(LOG_INFO, "CY_GO(%x) cmd %x control %x size %d\n",
E 9
I 9
		dlog((LOG_INFO, "CY_GO(%x) cmd %x control %x size %d\n",
E 9
		    vm->um_addr, cy->cy_tpb.tpcmd, cy->cy_tpb.tpcontrol,
D 9
		    htoms(cy->cy_tpb.tpsize));
E 9
I 9
		    htoms(cy->cy_tpb.tpsize)));
E 9
		CY_GO(vm->um_addr);
		return;
E 4
E 2
	}
D 2
	if ((bp->b_flags&B_READ) == 0)
		/*
		 * Writing sets EOF
		 */
		cy->cy_nxrec = bdbtofsb(bp->b_blkno) + 1;
	/*
	 * If the data transfer command is in the correct place,
	 * set up the tape parameter block, and start the i/o.
	 */
	if ((blkno = cy->cy_blkno) == bdbtofsb(bp->b_blkno)) {
		um->um_tab.b_active = SIO;
		cy->cy_timo = 60;	/* premature, but should serve */
E 2
I 2
D 4
	ui->blkno = 0;
	ui->eof = FALSE;
	cydone(cq);
}
E 2

D 2
		phadr = get_ioadr(bp, cybuf, CYmap, cyutl);
E 2

D 2
		if ( (bp->b_flags & B_READ) == 0) 
			tp->cmd = WRIT_BU;
		else tp->cmd = READ_BU;
		tp->control[0] = (CW_I | (cyunit<<CW_TSs));
		if (minor(bp->b_dev)&T_100IPS)
			tp->control[1] = (CW_100ips | CW_16bits);
		else	tp->control[1] = (CW_25ips | CW_16bits);
		tp->status[0] = tp->status[1] = 0;
		tp->count = 0;
		tp->size = TM_SHORT(bp->b_bcount);
		set_pointer(phadr, (char *)tp->pt_data);
		set_pointer((int)&tpb[cyunit], (char *)ccb.pt_tpb);
		goto dobpcmd;
E 2
I 2
/*
**	cy_space_forw is used to search forward a given number of records on
**  tape.
**
**	Since only one device can be active on a given controller at any
**  given instant in time, we try to be nice and let onther devices  on
**  this controller be scheduled after we space over each record.  This will
**  at least give the apperance of overlapped operations on the controller.
**
**  The special cases are:
**  1) we can't space over a filemark.
**  2) if the last command was a write data or filemark we can't space forward.
*/

cy_space_forw(request, cq)
register struct buf	*request;
register struct buf	*cq;
{
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[CYUNIT(unit)];
	register int		ctlr = cydinfo[unit]->ui_ctlr;
	register ctlr_tab	*ci = &ctlr_info[ctlr];

	if((ui->cleanup != cyno_op) || ui->eof) {
		request->b_resid = request->b_bcount;
		request->b_error = ENXIO, request->b_flags |= B_ERROR;
		longjmp(&ci->environ);
E 4
I 4
	/*
	 * Tape positioned incorrectly; set to seek forwards
	 * or backwards to the correct spot.  This happens 
	 * for raw tapes only on error retries.
	 */
	vm->um_tab.b_active = SSEEK;
D 11
	if (blkno < bdbtofsb(bp->b_blkno)) {
E 11
I 11
	if (blkno < bp->b_blkno) {
E 11
		bp->b_command = CY_SFORW;
D 11
		cy->cy_tpb.tprec = htoms(bdbtofsb(bp->b_blkno) - blkno);
E 11
I 11
		cy->cy_tpb.tprec = htoms(bp->b_blkno - blkno);
E 11
	} else {
		bp->b_command = CY_SREV;
D 11
		cy->cy_tpb.tprec = htoms(blkno - bdbtofsb(bp->b_blkno));
E 11
I 11
		cy->cy_tpb.tprec = htoms(blkno - bp->b_blkno);
E 11
E 4
E 2
	}
D 2
	/*
	 * Tape positioned incorrectly;
	 * set to seek forwards or backwards to the correct spot.
	 */
	um->um_tab.b_active = SSEEK;
	tp->cmd = SPACE;
	tp->control[0] = (CW_I | (cyunit<<CW_TSs));
	if (minor(bp->b_dev)&T_100IPS)
		tp->control[1] = (CW_100ips | CW_16bits);
	else	tp->control[1] = (CW_25ips | CW_16bits);
	tp->status[0] = tp->status[1] = 0;
	set_pointer((int)&tpb[cyunit], (char *)ccb.pt_tpb);
	if (blkno < bdbtofsb(bp->b_blkno)) 
		tp->rec_over = TM_SHORT((short)(blkno - bdbtofsb(bp->b_blkno)));
	else {
		tp->rec_over = TM_SHORT((short)(bdbtofsb(bp->b_blkno) - blkno));
		tp->control[1] |= CW_R;
E 2
I 2
D 4
	if(request->b_bcount) {
		ui->blkno++;
		cyexecute(SPAC_FM, (long)1, 0, 0, unit, 10, FALSE);
		if(!ui->eof && request->b_bcount) {
			request->b_bcount--;
			return;
		}
E 4
I 4
D 17
	yc->yc_timo = imin(imax(10 * htoms(cy->cy_tpb.tprec), 60), 5*60);
E 17
I 17
	yc->yc_timo = imin(imax((int)(10 * htoms(cy->cy_tpb.tprec)), 60), 5*60);
E 17
dobpcmd:
	/*
	 * Do the command in bp.  Reverse direction commands
	 * are indicated by having CYCW_REV or'd into their
	 * value.  For these we must set the appropriate bit
	 * in the control field.
	 */
	if (bp->b_command&CYCW_REV) {
		cy->cy_tpb.tpcmd = bp->b_command &~ CYCW_REV;
		cy->cy_tpb.tpcontrol = yc->yc_dens | CYCW_REV;
I 11
dlog((LOG_INFO, "cmd %x control %x\n", cy->cy_tpb.tpcmd, cy->cy_tpb.tpcontrol));
E 11
	} else {
		cy->cy_tpb.tpcmd = bp->b_command;
		cy->cy_tpb.tpcontrol = yc->yc_dens;
I 11
dlog((LOG_INFO, "cmd %x control %x\n", cy->cy_tpb.tpcmd, cy->cy_tpb.tpcontrol));
E 11
E 4
E 2
	}
D 2
	cy->cy_timo = imin(imax(10 * (int)TM_SHORT(tp->rec_over), 60), 5 * 60);
dobpcmd:
	/*
	 * Do the command in bp.
	 */
	timer = 8000;			/* software tolerance for gate open */
	uncache(&ccb.gate[0]);
	while (ccb.gate[0] != GATE_OPEN) {
		if (--timer == 0) {
			ccb.ccw[0] = 0x9;	/* forget it...... */
			TM_RESET(ctlr_vaddr, 0xff);
			bp->b_flags |= B_ERROR;
			goto next;
E 2
I 2
D 4
	if(ui->eof) {
		request->b_resid = request->b_bcount;
		request->b_error = ENXIO, request->b_flags |= B_ERROR;
	}
	cydone(cq);
E 4
I 4
	cy->cy_tpb.tpstatus = 0;
	cy->cy_tpb.tpcount = 0;
	cyldmba(cy->cy_tpb.tplink, (caddr_t)0);
	do
		uncache(&cy->cy_ccb.cbgate);
	while (cy->cy_ccb.cbgate == GATE_CLOSED);
	cyldmba(cy->cy_ccb.cbtpb, (caddr_t)&cy->cy_tpb);
	cy->cy_ccb.cbcw = CBCW_IE;
	cy->cy_ccb.cbgate = GATE_CLOSED;
D 9
	dlog(LOG_INFO, "CY_GO(%x) cmd %x control %x rec %d\n",
E 9
I 9
	dlog((LOG_INFO, "CY_GO(%x) cmd %x control %x rec %d\n",
E 9
	    vm->um_addr, cy->cy_tpb.tpcmd, cy->cy_tpb.tpcontrol,
D 9
	    htoms(cy->cy_tpb.tprec));
E 9
I 9
	    htoms(cy->cy_tpb.tprec)));
E 9
	CY_GO(vm->um_addr);
	return;
next:
	/*
	 * Done with this operation due to error or the
D 11
	 * fact that it doesn't do anything.  Release VERSAbus
	 * resource (if any), dequeue the transfer and continue
E 11
I 11
	 * fact that it doesn't do anything.
	 * Dequeue the transfer and continue
E 11
	 * processing this slave.
	 */
D 11
	if (bp == &rcybuf[CYUNIT(bp->b_dev)])
		vbadone(bp, cy->cy_buf, (long *)cy->cy_map, cy->cy_utl);
E 11
	vm->um_tab.b_errcnt = 0;
	dp->b_actf = bp->av_forw;
D 9
	iodone(bp);
E 9
I 9
	biodone(bp);
E 9
	goto loop;
E 4
}

D 4

E 4
/*
D 4
**	Cy_space_back spaces backward a given number of records.
**
**	Since only one device can be active on a given controller at any
**  given instant in time, we try to be nice and let onther devices  on
**  this controller be scheduled after we space over each record.  This will
**  at least give the apperance of overlapped operations on the controller.
**
**  The special cases are:
**  1) we can't space over a filemark.
**  2) we can't space past the beginning of tape.
**  3) if the last operation was a write data then we need to add
**     an end of volume record before we start searching.
*/

cy_space_back(request, cq)
register struct buf	*request;
register struct buf	*cq;
{
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[CYUNIT(unit)];

	if(!ui->bot) {
		(*ui->cleanup)(unit, MAINTAIN_POSITION);
		if(request->b_bcount+1 && !ui->bot && !ui->eof) {
			request->b_bcount--;
			ui->blkno--;
			cyexecute(SPACE, (long)1, 0, CW_REV, unit, 15, FALSE);
			return;
E 2
		}
D 2
		uncache(&ccb.gate[0]);
E 2
I 2
		if(!ui->bot) {
			request->b_bcount = 1;
			cy_space_forw(request, cq);
		}
		ui->eof = FALSE;
E 2
	}
D 2
	ccb.ccw[0] = 0x11;		/* normal mode */
	ccb.gate[0] = GATE_CLOSED;	
	TM_ATTENTION(ctlr_vaddr, 0xff);		/* execute! */
	return;
E 2
I 2
	cydone(cq);
}
E 2

D 2
next:
	/*
	 * Done with this operation due to error or
	 * the fact that it doesn't do anything.
	 * dequeue the transfer and continue processing this slave.
	 */
	um->um_tab.b_errcnt = 0;
	dp->b_actf = bp->av_forw;
	iodone(bp);
	goto loop;
E 2
I 2
/*
 * Rewind tape and wait for completion.
 * An overlapped rewind is issued and then we change the command type to
 * a wait for ready ioctl.  Wait for ready contains the logic to poll
 * without blocking anything in the system, until the drive becomes ready or
 * drops off line whichever comes first.
E 4
I 4
 * Cy interrupt routine.
E 4
 */
D 4
/*ARGSUSED*/
cyrewind_tape_ta(bp, cq)
	struct buf *bp, *cq;
E 4
I 4
D 11
cyintr(cipher)
	int cipher;
E 11
I 11
cyintr(cyunit)
	int cyunit;
E 11
E 4
{
D 4

	cyrewind_tape(bp, REWD_OV);
	bp->b_cmd = (struct buf *)DO_WAIT;
E 2
}

/*
D 2
 * Kept for historical reasons. Probably not neccessary. 
E 2
I 2
 * Do an overlapped rewind and then unload the tape.
 * This feature is handled by the individual tape drive and
 * in some cases can not be performed.
E 2
 */
D 2
cydgo(um)
	struct vba_ctlr *um;
E 2
I 2
cyrewind_tape_unl(bp, cq)
	struct buf *bp, *cq;
E 2
{
I 2

	cyrewind_tape(bp, OFF_UNL);
	cydone(cq);
E 2
}

/*
D 2
 * Cy interrupt routine.
E 2
I 2
 * Do an overlapped rewind.
E 2
 */
D 2
/*ARGSUSED*/
cyintr(ctlr)
	int ctlr;
E 2
I 2
cyrewind_tape_ov(bp, cq)
	struct buf *bp, *cq;
E 2
{
D 2
	struct buf *dp;
E 2
I 2

	cyrewind_tape(bp, REWD_OV);
	cydone(cq);
}

/*
 * Common code for all rewind commands.
 * The special cases are:
 *  3) if the last operation was a write data then we need to add
 *     an end of volume record before we start searching.
 */
cyrewind_tape(bp, cmd)
E 4
I 4
	struct buf *dp;
E 4
E 2
	register struct buf *bp;
D 2
	register struct tpb *tp;
	register struct vba_ctlr *um = cyminfo[ctlr];
	register struct cy_softc *cy;
	caddr_t ctlr_vaddr;
	int cyunit;
	register state;
E 2
I 2
D 4
	int cmd;
{
	register int unit = CYUNIT(bp->b_dev);
	register unit_tab *ui = &unit_info[unit];
E 4
I 4
D 11
	register struct vba_ctlr *vm = cyminfo[cipher];
E 11
I 11
	register struct vba_ctlr *vm = cyminfo[cyunit];
E 11
	register struct cy_softc *cy;
	register struct yc_softc *yc;
D 11
	int cyunit, err;
E 11
I 11
	int err;
E 11
	register state;
E 4
E 2

D 2
	/*
	 * First we clear the interrupt and close the gate.
	 */
	ctlr_vaddr = um->um_addr;
	ccb.ccw[0] = 0x9;	/* clear the interrupt */
	ccb.gate[0] = GATE_CLOSED;
	set_pointer((int)&cycool, (char *)ccb.pt_tpb);
	cycool.cmd = NO_OP;	/* no operation */
	cycool.control[0] = 0;	/* No INTERRUPTS */
	cycool.control[1] = 0;
	TM_ATTENTION(ctlr_vaddr, 0xff);	/* cool it ! */
	cywait();
	/*
	 * Now we can start handling the interrupt.
	 */
	pflag = 1;		/* set for the probe routine */
	if (intenable == 0) return;	/* ignore all interrupts */
	if ((dp = um->um_tab.b_actf) == NULL)
E 2
I 2
D 4
	(*ui->cleanup)(unit, DONT_MAINTAIN_POSITION);
	ui->blkno = 0;
	ui->eof = FALSE;
	ui->bot = TRUE;
	ui->eot = FALSE;
	ui->file_number = 0;
	bp->b_resid = 0;
	ui->cleanup = cyno_op;
	cyexecute(cmd, (long)0, 0, 0, unit, cmd == REWD_OV ? 10 : 10*60, 0);
}

/*
**	Cywait_until_ready is used to wait for rewinds to complete.
**  We check the status and if the tape is still rewinding we re-enter ourself
**  on the activity queue to give other requests a chance to execute before we
**  check the status again.  One other thing is that we only want to  check
**  the status every five seconds.  so we set a timer for five seconds and
**  check the time left every time we enter this routine.  If there is still
**  time left then we simply reinsert ourself on the queue again and wait
**  until next time ..
*/
cywait_until_ready(request, cq)
register struct buf	*request;
register struct buf	*cq;
{
	extern int		cywait_timeout();
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[unit];

	cyexecute(DRIVE_S, (long)0, 0, 0, unit, 10, FALSE);
	if((!(ui->last_status & CS_OL)) || (ui->last_status & CS_RDY)) {
		cydone(cq);
E 4
I 4
D 9
	dlog(LOG_INFO, "cyintr(%d)\n", cipher);
E 9
I 9
D 11
	dlog((LOG_INFO, "cyintr(%d)\n", cipher));
E 11
I 11
	dlog((LOG_INFO, "cyintr(%d)\n", cyunit));
E 11
E 9
	/*
	 * First, turn off the interrupt from the controller
	 * (device uses Multibus non-vectored interrupts...yech).
	 */
	cy = &cy_softc[vm->um_ctlr];
	cy->cy_ccb.cbcw = CBCW_CLRINT;
D 8
	cyldmba(cy->cy_ccb.cbtpb, &cy->cy_nop);
E 8
I 8
	cyldmba(cy->cy_ccb.cbtpb, (caddr_t)&cy->cy_nop);
E 8
	cy->cy_ccb.cbgate = GATE_CLOSED;
	CY_GO(vm->um_addr);
	if ((dp = vm->um_tab.b_actf) == NULL) {
D 9
		dlog(LOG_ERR, "cy%d: stray interrupt", vm->um_ctlr);
E 9
I 9
		dlog((LOG_ERR, "cy%d: stray interrupt", vm->um_ctlr));
E 9
E 4
E 2
		return;
D 2
	bp = dp->b_actf;
	cyunit = CYUNIT(bp->b_dev);
	tp = &tpb[cyunit];
	cy = &cy_softc[cyunit];
	/*
	 * If last command was a rewind, and tape is still
	 * rewinding, wait for the rewind complete interrupt.
	 */
	if (um->um_tab.b_active == SREW) {
		um->um_tab.b_active = SCOM;
		/* uncache(&tp->status[1]); */
		/* if (tp->status[1]&CS_CC != CS_CC) { */ /* not completed */
			/* cy->cy_timo = 5*60; */	 /* 5 minutes */
			/* return; */
		/* } */
E 2
	}
D 2
	/*
	 * An operation completed... update status
	 */
	cy->cy_timo = INF;
	uncache(&tp->count);
	uncache(&tp->status[0]);
	cy->cy_count = TM_SHORT(tp->count);
	cy->cy_status[0] = tp->status[0];
	cy->cy_status[1] = tp->status[1];
	if ((bp->b_flags & B_READ) == 0)
		cy->cy_lastiow = 1;
	state = um->um_tab.b_active;
	um->um_tab.b_active = 0;
	/*
	 * Check for errors.
	 */
	if (tp->status[1] & CS_ERm) {
		/*
		 * If we hit the end of the tape file, update our position.
		 */
		if (tp->status[0] & CS_FM) 
		{
			cyseteof(bp);		/* set blkno and nxrec */
			state = SCOM;
			goto opdone;
E 2
I 2
D 4
	cq->b_forw->b_active |= SLEEPING;
	timeout(cywait_timeout, (caddr_t)cq->b_forw, 2*60);
}

/*
 * Reset the timing flag for nice_wait after 3 seconds.
 * This makes this drive eligible for scheduling again.
 */
cywait_timeout(uq)
	struct buf *uq;
{

	uq->b_active &= ~SLEEPING;
}

/*
 * Process a status ioctl request.
 * It depends entirly on the interupt routines to load the last_XXX
 * registers in unit_info[].
 */
cydrive_status(bp, cq)
	struct buf *bp, *cq;
{

	cyexecute(DRIVE_S, (long)0, 0, 0, CYUNIT(bp->b_dev), 10, FALSE);
	cydone(cq);
}

/*
**	cybuf_read handles the read requests from the block device.
**
**  The special cases are:
**  1)	we can not read after a write.  (writting defines end of file)
**  2)  reading past end of file returns 0 bytes;
**  3)  if we are mispositioned we have to seek to the correct block.
**  4)  we can hit end of tape while seeking.
**  5)  we want to be nice to other processes while seeking so we
**  	break the request up into smaller requests.
**  6)  returns error if the block was larger than requested. 
*/
cybuf_read(request, cq)
register struct buf	*request;
register struct buf	*cq;
{
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[CYUNIT(unit)];
	register int		ctlr = cydinfo[unit]->ui_ctlr;
	register ctlr_tab	*ci = &ctlr_info[ctlr];
	register int		addr, command, bus_lock;

	cydebug = 1;
	if(cyseek(request, cq)) {
		if(ui->cleanup != cyno_op) {
			clrbuf(request);
			longjmp(&ci->environ);
E 4
I 4
	bp = dp->b_actf;
D 11
	cyunit = CYUNIT(bp->b_dev);
E 11
	cy = &cy_softc[cyunit];
	cyuncachetpb(cy);
I 8
	yc = &yc_softc[YCUNIT(bp->b_dev)];
E 8
	/*
D 6
	 * If last command was a rewind or file mark search, and
	 * tape is still moving, wait for the operation to complete.
E 6
I 6
	 * If last command was a rewind and tape is
	 * still moving, wait for the operation to complete.
E 6
	 */
	if (vm->um_tab.b_active == SREW) {
		vm->um_tab.b_active = SCOM;
		if ((cy->cy_tpb.tpstatus&CYS_RDY) == 0) {
			yc->yc_timo = 5*60;	/* 5 minutes */
			return;
E 4
E 2
		}
D 2
		/* If reading raw device and block was too short ignore the
		 * error and let the user program decide what to do.
		 */
		if ((tp->status[0] & ER_TOF) && /* (bp->b_flags & B_PHYS) && */
			(bp->b_flags & B_READ)) goto cont;
		cy->cy_openf = -1;		/* cause to close */
		printf("cy%d: hard error bn %d er=%x\n", cyunit,
		    bp->b_blkno, tp->status[1]&CS_ERm);
		bp->b_flags |= B_ERROR;
		goto opdone;
E 2
I 2
D 4
		if(request->b_bcount > ci->bs)
			command = READ_TA, bus_lock = CW_LOCK;
		else
			command = READ_BU, bus_lock = 0;
		ui->blkno++;
		addr = vbastart(request, (caddr_t)ci->rawbuf, (long *)ci->map,
		    ci->utl);
		cyexecute(command,request->b_bcount,addr,bus_lock,unit,8,FALSE);
		vbadone(request, (caddr_t)ci->rawbuf, (long *)ci->map, ci->utl);
		cydone(cq);
E 4
E 2
	}
D 2
	/*
	 * If we were reading block tape and the record
	 * was too long, we consider this an error.
	 */
cont:
	uncache(&tp->count);
	uncache(&tp->cmd);
	if (bp != &rcybuf[TMUNIT(bp->b_dev)] && (tp->cmd == READ_BU) &&
	    bp->b_bcount < TM_SHORT(tp->count)) {
		cy->cy_openf = -1;		/* cause to close */
		printf("cy%d: error - tape block too long \n", cyunit);
		bp->b_flags |= B_ERROR;
		goto opdone;
E 2
I 2
D 4
}


/*
**	cybuf_write handles the write requests from the block device.
**
**  The special cases are:
**  1)  if we are mispositioned we have to seek to the correct block.
**  2)  we can hit end of tape while seeking.
**  3)  we want to be nice to other processes while seeking so we
**  	break the request up into smaller requests.
**  4) we don't allow writes after end of tape is reached.
*/

cybuf_write(request, cq)
register struct buf	*request;
register struct buf	*cq;
{
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[CYUNIT(unit)];
	register int		ctlr = cydinfo[unit]->ui_ctlr;
	register ctlr_tab	*ci = &ctlr_info[ctlr];
	register int		addr, command, bus_lock;
	
	if(ui->eot && (request->b_blkno >= ui->blkno)) {
		request->b_error = ENXIO, request->b_flags |= B_ERROR;
		request->b_resid = request->b_bcount;
		longjmp(&ci->environ);
E 4
I 4
	/*
	 * An operation completed...record status.
	 */
D 8
	yc = &yc_softc[YCUNIT(bp->b_dev)];
E 8
	yc->yc_timo = INF;
	yc->yc_control = cy->cy_tpb.tpcontrol;
	yc->yc_status = cy->cy_tpb.tpstatus;
	yc->yc_resid = bp->b_bcount - htoms(cy->cy_tpb.tpcount);
D 9
	dlog(LOG_INFO, "cmd %x control %b status %b resid %d\n",
E 9
I 9
	dlog((LOG_INFO, "cmd %x control %b status %b resid %d\n",
E 9
	    cy->cy_tpb.tpcmd, yc->yc_control, CYCW_BITS,
D 9
	    yc->yc_status, CYS_BITS, yc->yc_resid);
E 9
I 9
	    yc->yc_status, CYS_BITS, yc->yc_resid));
E 9
	if ((bp->b_flags&B_READ) == 0)
		yc->yc_lastiow = 1;
	state = vm->um_tab.b_active;
	vm->um_tab.b_active = 0;
	/*
	 * Check for errors.
	 */
	if (cy->cy_tpb.tpstatus&CYS_ERR) {
		err = cy->cy_tpb.tpstatus&CYS_ERR;
D 9
		dlog(LOG_INFO, "error %d\n", err);
E 9
I 9
		dlog((LOG_INFO, "error %d\n", err));
E 9
		/*
		 * If we hit the end of tape file, update our position.
		 */
		if (err == CYER_FM) {
			yc->yc_status |= CYS_FM;
			state = SCOM;		/* force completion */
			cyseteof(bp);		/* set blkno and nxrec */
			goto opdone;
		}
		/*
		 * Fix up errors which occur due to backspacing over
		 * the beginning of the tape.
		 */
		if (err == CYER_BOT && cy->cy_tpb.tpcontrol&CYCW_REV) {
			yc->yc_status |= CYS_BOT;
			goto ignoreerr;
		}
		/*
		 * If we were reading raw tape and the only error was that the
		 * record was too long, then we don't consider this an error.
		 */
D 18
		if (bp == &rcybuf[cyunit] && (bp->b_flags&B_READ) &&
E 18
I 18
		if ((bp->b_flags & (B_READ|B_RAW)) == (B_READ|B_RAW) &&
E 18
		    err == CYER_STROBE) {
			/*
D 9
			 * Retry reads once with the command changed to
			 * a raw read (if possible).  Setting b_errcnt
E 9
I 9
			 * Retry reads with the command changed to
			 * a raw read if necessary.  Setting b_errcnt
E 9
			 * here causes cystart (above) to force a CY_RCOM.
			 */
D 9
			if (bp->b_errcnt++ != 0)
E 9
I 9
D 12
			if (htoms(cy->cy_tpb.tprec) > cy->cy_bs &&
			    bp->b_bcount > cy->cy_bs && 
			    yc->yc_blksize <= cy->cy_bs &&
E 12
I 12
			if (cy->cy_tpb.tpcmd == CY_BRCOM &&
E 12
D 11
			    bp->b_errcnt++ == 0) {
E 11
I 11
			    vm->um_tab.b_errcnt++ == 0) {
E 11
				yc->yc_blkno++;
				goto opcont;
			} else
E 9
				goto ignoreerr;
D 9
			yc->yc_blkno++;
			goto opcont;
E 9
		}
		/*
		 * If error is not hard, and this was an i/o operation
		 * retry up to 8 times.
		 */
D 6
		err = 1 << err;
		if ((err&CYER_SOFT) && state == SIO) {
E 6
I 6
D 15
		if (((1<<err)&CYER_SOFT) && state == SIO) {
E 15
I 15
		if (state == SIO && (CYMASK(err) &
		    ((bp->b_flags&B_READ) ? CYER_RSOFT : CYER_WSOFT))) {
E 15
E 6
			if (++vm->um_tab.b_errcnt < 7) {
				yc->yc_blkno++;
				goto opcont;
			}
		} else
			/*
			 * Hard or non-i/o errors on non-raw tape
			 * cause it to close.
			 */
D 9
			if (yc->yc_openf>0 && bp != &rcybuf[cyunit])
E 9
I 9
D 18
			if (yc->yc_openf > 0 && bp != &rcybuf[cyunit])
E 18
I 18
			if ((bp->b_flags&B_RAW) == 0 &&
			    yc->yc_openf > 0)
E 18
E 9
				yc->yc_openf = -1;
		/*
		 * Couldn't recover from error.
		 */
		tprintf(yc->yc_ttyp,
D 9
		    "yc%d: hard error bn%d status=%b", YCUNIT(bp->b_dev),
		    bp->b_blkno, yc->yc_status, CYS_BITS);
		if (err < NCYERROR)
			tprintf(yc->yc_ttyp, ", %s", cyerror[err]);
		tprintf(yc->yc_ttyp, "\n");
E 9
I 9
		    "yc%d: hard error bn%d status=%b, %s\n", YCUNIT(bp->b_dev),
		    bp->b_blkno, yc->yc_status, CYS_BITS,
		    (err < NCYERROR) ? cyerror[err] : "");
E 9
		bp->b_flags |= B_ERROR;
		goto opdone;
I 12
	} else if (cy->cy_tpb.tpcmd == CY_BRCOM) {
		int reclen = htoms(cy->cy_tpb.tprec);

		/*
		 * If we did a buffered read, check whether the read
		 * was long enough.  If we asked the controller for less
		 * than the user asked for because the previous record
		 * was shorter, update our notion of record size
		 * and retry.  If the record is longer than the buffer,
		 * bump the errcnt so the retry will use direct read.
		 */
		if (reclen > yc->yc_blksize && bp->b_bcount > yc->yc_blksize) {
			yc->yc_blksize = reclen;
			if (reclen > cy->cy_bs)
				vm->um_tab.b_errcnt++;
			yc->yc_blkno++;
			goto opcont;
		}
E 12
E 4
E 2
	}
D 2
	/*
	 * No errors.
	 * Advance tape control FSM.
	 */
	switch (state) {
E 2
I 2
D 4
	if(cyseek(request, cq)) {
		ui->cleanup = cywrite_2_fm;
		ui->blkno++;
		if(request->b_bcount > ci->bs)
			command = WRIT_TA, bus_lock = CW_LOCK;
		else
			command = WRIT_BU, bus_lock = 0;
		addr = vbastart(request, (caddr_t)ci->rawbuf, (long *)ci->map,
		    ci->utl);
		load_mbus_addr((caddr_t)addr, (short *)&ci->tpb.data_ptr);
		cyexecute(command,request->b_bcount,addr,bus_lock,unit,5,FALSE);
		vbadone(request, (caddr_t)ci->rawbuf, (long *)ci->map, ci->utl);
		cydone(cq);
E 4
I 4
	/*
	 * Advance tape control FSM.
	 */
ignoreerr:
	/*
	 * If we hit a tape mark update our position.
	 */
	if (yc->yc_status&CYS_FM && bp->b_flags&B_READ) {
		cyseteof(bp);
		goto opdone;
E 4
	}
D 4
}
E 4
I 4
	switch (state) {
E 4
E 2

I 4
	case SIO:
		/*
		 * Read/write increments tape block number.
		 */
		yc->yc_blkno++;
I 9
		yc->yc_blks++;
		if (vm->um_tab.b_errcnt || yc->yc_status & CYS_CR)
			yc->yc_softerrs++;
		yc->yc_blksize = htoms(cy->cy_tpb.tpcount);
		dlog((LOG_ERR, "blocksize %d", yc->yc_blksize));
E 9
		goto opdone;
E 4
D 2
	case SIO:
		/*
		 * Read/write increments tape block number
		 */
		cy->cy_blkno++;
		end_transfer(bp, cybuf, CYmap, cyutl);
		goto opdone;
E 2

D 2
	case SCOM:
		/*
		 * For forward/backward space record update current position.
		 */
		if (bp == &ccybuf[TMUNIT(bp->b_dev)])
		switch (bp->b_command) {
E 2
I 2
D 4
/*
**	cyseek is used by the block device to position the tape correctly
**  before each read or write request.
**
**  The special cases are:
**  1)  we can hit end of tape while seeking.
**  2)  we want to be nice to other processes while seeking so we
**  	break the request up into smaller requests.
*/
cyseek(request, cq)
register struct buf	*request;
register struct buf	*cq;
{
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[CYUNIT(unit)];
	register int		ctlr = cydinfo[unit]->ui_ctlr;
	register ctlr_tab	*ci = &ctlr_info[ctlr];
E 4
I 4
	case SCOM:
		/*
		 * For forward/backward space record update current position.
		 */
D 8
		if (bp == &ccybuf[CYUNIT(bp->b_dev)]) switch (bp->b_command) {
E 8
I 8
		if (bp == &ccybuf[CYUNIT(bp->b_dev)])
			switch ((int)bp->b_command) {
E 8
E 4
E 2

D 2
		case SP_FORW:
			cy->cy_blkno += bp->b_repcnt;
			break;
E 2
I 2
D 4
#ifdef lint
	cq = cq;
#endif
	if(request->b_blkno < ui->blkno) {
		register int	count;
E 4
I 4
D 8
		case CY_SFORW:
			yc->yc_blkno -= bp->b_repcnt;
			break;
E 8
I 8
			case CY_SFORW:
				yc->yc_blkno -= bp->b_repcnt;
				break;
E 8
E 4
E 2

D 2
		case SP_BACK:
			cy->cy_blkno -= bp->b_repcnt;
			break;
E 2
I 2
D 4
		(*ui->cleanup)(unit, MAINTAIN_POSITION);
		count = ((request->b_blkno+1) == ui->blkno) ? 2 : 1;
		ui->blkno -= count;
		cyexecute(SPAC_FM, (long)1, 0, CW_REV, unit, 10, FALSE);
		if(!ui->eof)
			return FALSE;
		ui->eof = FALSE;
		request->b_blkno = ui->blkno + 1;
	}
	if(request->b_blkno > ui->blkno) {
		if((ui->cleanup != cyno_op) || ui->eof || ui->eot) {
			request->b_resid = request->b_bcount;
			request->b_error = ENXIO, request->b_flags |= B_ERROR;
			longjmp(&ci->environ);
E 4
I 4
D 8
		case CY_SREV:
			yc->yc_blkno += bp->b_repcnt;
			break;
E 4
E 2
		}
E 8
I 8
			case CY_SREV:
				yc->yc_blkno += bp->b_repcnt;
				break;
			}
E 8
D 2
		goto opdone;
E 2
I 2
D 4
		ui->blkno++;
		cyexecute(SPAC_FM, (long)1, 0, 0, unit, 10, FALSE);
		return FALSE;
	}
	return TRUE;
}
E 4
I 4
		goto opdone;
	
	case SSEEK:
D 11
		yc->yc_blkno = bdbtofsb(bp->b_blkno);
E 11
I 11
		yc->yc_blkno = bp->b_blkno;
E 11
		goto opcont;
E 4
E 2

D 2
	case SSEEK:
		cy->cy_blkno = bdbtofsb(bp->b_blkno);
		goto opcont;
E 2
D 4

D 2
	default:
		panic("cyintr");
E 2
I 2
/*
*/

cywrite_eov(request, cq)
register struct buf	*request;
register struct buf	*cq;
{
	extern int		cyno_op();
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[CYUNIT(unit)];

	if(ui->cleanup != cyno_op) {
		(*ui->cleanup)(unit, DONT_MAINTAIN_POSITION);
		cyexecute(SPACE, (long)2, 0, CW_REV, unit, 10, FALSE);
		cyexecute(SPACE, (long)1, 0, 0, unit, 10, FALSE);
		unit_info[unit].cleanup = cyno_op;
		ui->blkno = 0;
E 4
I 4
	case SERASE:
		/*
		 * Completed erase of the inter-record gap due to a
		 * write error; now retry the write operation.
		 */
		vm->um_tab.b_active = SERASED;
		goto opcont;
E 4
E 2
	}
D 2
opdone:
	/*
	 * Reset error count and remove
	 * from device queue.
	 */
	um->um_tab.b_errcnt = 0;
	dp->b_actf = bp->av_forw;
	uncache(&tp->count);
	bp->b_resid = bp->b_bcount - TM_SHORT(tp->count);
	iodone(bp);
	/*
	 * Circulate slave to end of controller
	 * queue to give other slaves a chance.
	 */
	um->um_tab.b_actf = dp->b_forw;
	if (dp->b_actf) {
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
E 2
I 2
D 4
	cydone(cq);
}
E 4

D 4

/*
**	Do nothing
*/
/*ARGSUSED*/
cyno_op(unit, action)
int	unit, action;
{
}


/*
**	Write 0 file marks to tape
*/
/*ARGSUSED*/
cywrite_0_fm(unit, action)
int	unit, action;
{
	unit_info[unit].cleanup = cyno_op;
}


/*
**	Write 1 file mark to tape
*/

cywrite_1_fm(unit, action)
int	unit, action;
{

	cyexecute(WRIT_FM, (long)1, 0, 0, unit, 5, FALSE);
	if(action == MAINTAIN_POSITION) {
		cyexecute(SPACE, (long)2, 0, CW_REV, unit, 10, FALSE);
		cyexecute(SPACE, (long)1, 0, 0, unit, 10, FALSE);
E 2
	}
D 2
	if (um->um_tab.b_actf == 0)
		return;
opcont:
	cystart(um);
E 2
I 2
	unit_info[unit].cleanup = cyno_op;
E 2
}

D 2
cytimer(dev)
	int dev;
E 2
I 2

/*
**	Write 2 file marks to tape
*/

cywrite_2_fm(unit, action)
int	unit, action;
E 2
{
D 2
	register struct cy_softc *cy = &cy_softc[CYUNIT(dev)];
	int	s;
E 2

D 2
	if (cy->cy_timo != INF && (cy->cy_timo -= 5) < 0) {
		printf("cy%d: lost interrupt\n", CYUNIT(dev));
		cy->cy_timo = INF;
		s = spl8();
		cyintr(TMUNIT(dev));
		splx(s);
		return;
E 2
I 2
	cyexecute(WRIT_FM, (long)1, 0, 0, unit, 5, FALSE);
	cyexecute(WRIT_FM, (long)1, 0, 0, unit, 5, FALSE);
	if(action == MAINTAIN_POSITION) {
		cyexecute(SPACE, (long)3, 0, CW_REV, unit, 10, FALSE);
		cyexecute(SPACE, (long)1, 0, 0, unit, 2, FALSE);
E 2
	}
D 2
	if (cy->cy_timo != INF ) timeout(cytimer, (caddr_t)dev, 5*hz);
E 2
I 2
	unit_info[unit].cleanup = cyno_op;
E 2
}

D 2
cyseteof(bp)
	register struct buf *bp;
E 2
I 2

extern	int cytimeout();
extern	int cy_normal_path();
/*
**	Cyexecute is used to start all commands to the controller.  We
**  do all common code here before starting.
*/

cyexecute(command, count, addr, control_flags, unit, time, interupt_routine)
	register int command;
	long count;
	int addr, control_flags, unit, time, interupt_routine;
E 2
{
D 2
	register int cyunit = CYUNIT(bp->b_dev);
	register struct cy_softc *cy = &cy_softc[cyunit];
	register struct tpb *tp;
E 2
I 2
	register int		priority;
	register int		ctlr = cydinfo[unit]->ui_ctlr;
	register unit_tab	*ui = &unit_info[unit];
	register ctlr_tab	*ci = &ctlr_info[ctlr];
	register struct buf	*request = ui->u_queue.av_forw;
E 2

D 2
	tp = &tpb[cyunit];
	uncache(&tp->rec_over);
	if (bp == &ccybuf[TMUNIT(bp->b_dev)]) {
		if (cy->cy_blkno > bdbtofsb(bp->b_blkno)) {
			/* reversing */
			cy->cy_nxrec = bdbtofsb(bp->b_blkno) - (int)TM_SHORT(tp->rec_over);
			cy->cy_blkno = cy->cy_nxrec;
		} else {
			/* spacing forward */
			cy->cy_blkno = bdbtofsb(bp->b_blkno) + (int)TM_SHORT(tp->rec_over);
			cy->cy_nxrec = cy->cy_blkno - 1;
E 2
I 2
	ci->tpb.cmd = command;
	ci->tpb.control = ui->control_proto | control_flags;
	ci->tpb.status = ci->tpb.count = (short)0;
	load_mbus_addr((caddr_t)addr, (short *)&ci->tpb.data_ptr);
	switch(command) {
		case READ_BU:
		case READ_TA:
		case WRIT_BU:
		case WRIT_TA:
			ci->tpb.size = MULTIBUS_SHORT((short)count);
			ci->tpb.rec_over = (short)0;
			break;
		default:
			ci->tpb.size = (short)0;
			ci->tpb.rec_over = MULTIBUS_SHORT((short)count);
			break;
	}
	load_mbus_addr((caddr_t)0, ci->tpb.link_ptr);
	if(!interupt_routine)
		ci->last = ci->tpb;
E 4
I 4
opdone:
E 4
	/*
D 4
	gag! but it the last possible moment to wait 
	for this controller to get out of it's own way.....
	*/
	uncache(&ci->ccb.gate);
	while(ci->ccb.gate == GATE_CLOSED)
		uncache(&ci->ccb.gate);
	load_mbus_addr((caddr_t)&ci->tpb, ci->ccb.tpb_ptr);
	ci->ccb.ccw = NORMAL_INTERUPT;
	ci->ccb.gate = GATE_CLOSED;
	if(!interupt_routine)
		ci->interupt_path = cy_normal_path;
	timeout(cytimeout, (caddr_t)ctlr, time*60);
	priority = spl3();
	CY_ATTENTION(cyminfo[ctlr]->um_addr);
	if(!interupt_routine) {
		sleep((caddr_t)ci, PRIBIO+3);
		splx(priority);
		if(request->b_flags & B_ERROR) {
			if((command == READ_BU) || (command == READ_TA) ||
			    (command == WRIT_BU) || (command == WRIT_TA))
				vbadone(request, (caddr_t)ci->rawbuf,
				     (long *)ci->map,ci->utl);
			longjmp(&ci->environ);
E 2
		}
		return;
E 4
I 4
	 * Reset error count and remove from device queue.
	 */
	vm->um_tab.b_errcnt = 0;
	dp->b_actf = bp->av_forw;
	/*
	 * Save resid and release resources.
	 */
	bp->b_resid = bp->b_bcount - htoms(cy->cy_tpb.tpcount);
D 11
	if (bp == &rcybuf[CYUNIT(bp->b_dev)])
		vbadone(bp, cy->cy_buf, (long *)cy->cy_map, cy->cy_utl);
E 11
I 11
	if (bp != &ccybuf[cyunit])
		vbadone(bp, &cy->cy_rbuf);
E 11
D 9
	iodone(bp);
E 9
I 9
	biodone(bp);
E 9
	/*
	 * Circulate slave to end of controller
	 * queue to give other slaves a chance.
	 */
	vm->um_tab.b_actf = dp->b_forw;
	if (dp->b_actf) {
		dp->b_forw = NULL;
		if (vm->um_tab.b_actf == NULL)
			vm->um_tab.b_actf = dp;
		else
			vm->um_tab.b_actl->b_forw = dp;
E 4
D 2
	} 
	/* eof on read */
	cy->cy_nxrec = bdbtofsb(bp->b_blkno);
E 2
I 2
	}
D 4
	splx(priority);
E 4
I 4
	if (vm->um_tab.b_actf == 0)
		return;
opcont:
	cystart(vm);
E 4
E 2
}

D 2
cyread(dev, uio)
dev_t dev;
struct uio *uio;
E 2
I 2
D 4

/*
**	cytimeout is the interupt timeout routine.  We assume that a
**  particular command has gone astray, so we completely reset the controller,
**  and call the interupt routine to help us clean up.  Before the interupt
**  routine is called we jam a controller timeout value in the status register
**  to fake out the calling routines.
*/

cytimeout(ctlr)
register int	ctlr;
E 4
I 4
cytimer(dev)
	int dev;
E 4
E 2
{
D 2
	register error;
E 2
I 2
D 4
	register int	priority = spl3();
	register char	*ctlr_vaddr = cyminfo[ctlr]->um_addr;
	register int	tmp_stat;
E 4
I 4
	register struct yc_softc *yc = &yc_softc[YCUNIT(dev)];
	int s;
E 4
E 2

I 9
	if (yc->yc_openf == 0 && yc->yc_timo == INF) {
		yc->yc_tact = 0;
		return;
	}
E 9
D 2
	error = cyphys(dev, uio);
	if (error)
		return error;
	while (cybufused) sleep (&cybufused, PRIBIO+1);
	cybufused = 1;
	error = physio(cystrategy, &rcybuf[TMUNIT(dev)], dev, B_READ, tminphys, uio);
	cybufused = 0;
	wakeup (&cybufused);
	return error;
E 2
I 2
D 4
	uncache(&ctlr_info[ctlr].tpb.status);
	tmp_stat = ctlr_info[ctlr].tpb.status;
	CY_RESET(ctlr_vaddr);
	cy_init_controller(ctlr_vaddr, ctlr, 0);
	splx(priority);
	ctlr_info[ctlr].tpb = ctlr_info[ctlr].last;
	ctlr_info[ctlr].tpb.status = (tmp_stat & ~CS_ERm) | CS_OL | ER_TIMOUT;
	cyintr(ctlr);
E 2
}

D 2
cywrite(dev, uio)
dev_t dev;
struct uio *uio;
E 2
I 2
/*
**	Cyintr is the interupt routine for the Tapemaster controller.
**
**	Due to controller problems, the first thing we have to do is turn
**  off the Tapemaster interupting mechanism.  If we don't we will be flooded
**  with bogus interupts and the system will spend all it's time processing
**  them.  To Turn the interupts off we issue a NOOP command with the 'turn
**  off interupts' code in the ccb.
**
**	  take note that since this command TURNS OFF the interupts it
**	  itself CANNOT interupt...  This means that polling must be done
**	  at sometime to make sure that tis command is completed.  The polling
**	  is done before the next command is issued to reduce polling (halting
**	  UNIX) time.
**
**	After we turn off interupts we uncache all the values in the tpb
**  and call the correct processing routine.  This routine can be for normal
**  interupts or for interupts generated during a retry operation.
*/

cyintr(ctlr)
register int ctlr;
E 2
{
D 2
	register error;
E 2
I 2
	extern int		cytimeout();
	register ctlr_tab	*ci = &ctlr_info[ctlr]; 
E 2

D 2
	error = cyphys(dev, uio);
	if (error)
		return error;
	while (cybufused) sleep (&cybufused, PRIBIO+1);
	cybufused = 1;
	error = physio(cystrategy, &rcybuf[TMUNIT(dev)], dev, B_WRITE, tminphys, uio);
	cybufused = 0;
	wakeup (&cybufused);
	return error;
E 2
I 2
	untimeout(cytimeout, (caddr_t)ctlr);
	/* turn off interupts for the stupid controller */
	ci->ccb.ccw = CLEAR_INTERUPT;
	ci->noop.cmd = NO_OP;
	ci->noop.control = (short)0;
	load_mbus_addr((caddr_t)&ci->noop, ci->ccb.tpb_ptr);
	ci->ccb.gate = GATE_CLOSED;
	CY_ATTENTION(cyminfo[ctlr]->um_addr);
	uncache_tpb(ci);
	(*ci->interupt_path)(ctlr);
E 2
}


D 2
cyreset(uban)
	int uban;
E 2
I 2
/*
**	This is the portion of the interupt routine that processes all
**  normal cases i.e. non retry cases.   We check the operations status
**  if it is retryable we set the interupt path to the retry routines and
**  start the backward spaceing.  when the spacing is done the retry logic
**  will be called and this routine will be skipped entirely.
**
**	If the command is ok or not retryable we set the status accordingly
**  and wakeup cyexecute to continue processing.
*/

cy_normal_path(ctlr)
register int ctlr;
E 2
{
D 2
	register struct vba_ctlr *um;
	register cy0f, cyunit;
	register struct vba_device *ui;
	register struct buf *dp;
E 2
I 2
	extern int		cy_retry_path();
	extern int		cy_extended_gap_path();
	register int		error;
	register struct buf	*cq = &cyminfo[ctlr]->um_tab;
	register struct buf	*uq = cq->b_forw;
	register struct buf	*request = uq->av_forw;
	register int		unit = CYUNIT(request->b_dev);
	register unit_tab	*ui = &unit_info[unit];
	register ctlr_tab	*ci = &ctlr_info[ctlr]; 
E 2

D 2
	for (cy0f = 0; cy0f < NTM; cy0f++) {
		if ((um = cyminfo[cy0f]) == 0 || um->um_alive == 0 ||
		   um->um_vbanum != uban)
			continue;
		printf(" cy%d", cy0f);
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
		for (cyunit = 0; cyunit < NCY; cyunit++) {
			if ((ui = cydinfo[cyunit]) == 0 || ui->ui_mi != um ||
			    ui->ui_alive == 0)
				continue;
			dp = &cyutab[cyunit];
			dp->b_active = 0;
			dp->b_forw = 0;
			dp->b_command = DRIVE_R;
			if (um->um_tab.b_actf == NULL)
				um->um_tab.b_actf = dp;
E 2
I 2
	if (error = cydecode_error(unit, ci->tpb.status)) {
		if(error != FATAL) {
			if (error == RETRY)
				ci->interupt_path = cy_retry_path;
E 2
			else
D 2
				um->um_tab.b_actl->b_forw = dp;
			um->um_tab.b_actl = dp;
			if (cy_softc[cyunit].cy_openf > 0)
				cy_softc[cyunit].cy_openf = -1;
E 2
I 2
				ci->interupt_path = cy_extended_gap_path;
			cyexecute(SPACE, (long)2, 0, CW_REV, unit, 5, TRUE);
			return;
E 2
		}
E 4
I 4
	if (yc->yc_timo != INF && (yc->yc_timo -= 5) < 0) {
		printf("yc%d: lost interrupt\n", YCUNIT(dev));
		yc->yc_timo = INF;
		s = spl3();
		cyintr(CYUNIT(dev));
		splx(s);
E 4
D 2
		cystart(um);
E 2
	}
I 2
D 4
	request->b_resid=request->b_bcount-MULTIBUS_SHORT(ci->tpb.count);
	ui->error_count = 0;
	ui->last_resid = request->b_resid;
	ui->last_status = ci->tpb.status;
	ui->last_control = ci->tpb.control;
	if (error == FATAL)
		request->b_flags |= B_ERROR, request->b_error = EIO;
	wakeup((caddr_t)ci);
E 4
I 4
	timeout(cytimer, (caddr_t)dev, 5*hz);
E 4
E 2
}

D 4

D 2
cyioctl(dev, cmd, data, flag)
	caddr_t data;
	dev_t dev;
E 2
I 2
/*
**	Cy_retry_path finishes up the retry sequence for the tape.
** If we were going in the reverse direction it means that we have to
** space forward to correctly position ourselfs in back of the tape gap
** instead of in front of it.  If we were going forward it means that
** we are positioned correctly and we can actually restart the instruction
** that failed before.
*/

cy_retry_path(ctlr)
register int	ctlr;
E 4
I 4
cyseteof(bp)
	register struct buf *bp;
E 4
E 2
{
D 2
	int cyunit = CYUNIT(dev);
	register struct cy_softc *cy = &cy_softc[cyunit];
	register struct buf *bp = &ccybuf[TMUNIT(dev)];
	register callcount;
	int fcount;
	struct mtop *mtop;
	struct mtget *mtget;
	/* we depend of the values and order of the MT codes here */
	static cyops[] =
	   {WRIT_FM, SRFM_FD, SRFM_BK, SP_FORW, SP_BACK, REWD_TA, OFF_UNL, NO_OP};
E 2
I 2
D 4
	extern int		cy_do_again_path();
	register struct buf	*cq = &cyminfo[ctlr]->um_tab;
	register struct buf	*uq = cq->b_forw;
	register struct buf	*request = uq->av_forw;
	register int		unit = CYUNIT(request->b_dev);
	register ctlr_tab	*ci = &ctlr_info[ctlr]; 
E 4
I 4
	register int cyunit = CYUNIT(bp->b_dev);
	register struct cy_softc *cy = &cy_softc[cyunit];
	register struct yc_softc *yc = &yc_softc[YCUNIT(bp->b_dev)];
E 4
E 2

D 2
	switch (cmd) {
		case MTIOCTOP:	/* tape operation */
		mtop = (struct mtop *)data;
		switch(mtop->mt_op) {
		case MTWEOF:
			callcount = mtop->mt_count;
			fcount = 1;
			break;
		case MTFSF: case MTBSF:
			callcount = mtop->mt_count;
			fcount = INF;
			break;
		case MTFSR: case MTBSR:
			callcount = 1;
			fcount = mtop->mt_count;
			break;
		case MTREW: case MTOFFL: case MTNOP:
			callcount = 1;
			fcount = 1;
			break;
		default:
			return ENXIO;
E 2
I 2
D 4
	if(!(ci->tpb.status & CS_OL)) {
		ci->interupt_path = cy_normal_path;
		cy_normal_path(ctlr);
		return;
	}
	if(ci->tpb.control & CW_REV) {
		if(!(ci->tpb.status & CS_LP)) {
			ci->interupt_path = cy_do_again_path;
			cyexecute(SPACE, (long)1, 0, 0, unit, 5, TRUE);
			return;
E 4
I 4
	if (bp == &ccybuf[cyunit]) {
D 11
		if (yc->yc_blkno > bdbtofsb(bp->b_blkno)) {
E 11
I 11
		if (yc->yc_blkno > bp->b_blkno) {
E 11
			/* reversing */
D 11
			yc->yc_nxrec = bdbtofsb(bp->b_blkno) -
			    htoms(cy->cy_tpb.tpcount);
E 11
I 11
			yc->yc_nxrec = bp->b_blkno - htoms(cy->cy_tpb.tpcount);
E 11
			yc->yc_blkno = yc->yc_nxrec;
		} else {
D 11
			yc->yc_blkno = bdbtofsb(bp->b_blkno) +
			    htoms(cy->cy_tpb.tpcount);
E 11
I 11
			yc->yc_blkno = bp->b_blkno + htoms(cy->cy_tpb.tpcount);
E 11
			yc->yc_nxrec = yc->yc_blkno - 1;
E 4
E 2
		}
D 2
		if (callcount <= 0 || fcount <= 0)
			return EINVAL;
		while (--callcount >= 0) {
			cycommand(dev, cyops[mtop->mt_op], fcount);
			if ((bp->b_flags&B_ERROR) || cy->cy_status[1]&CS_ERm)
				break;
E 2
I 2
D 4
		cy_do_again_path(ctlr);
	}
}


/*
**
*/

cy_extended_gap_path(ctlr)
register int	ctlr;
{
	extern int		cy_do_again_path();
	register ctlr_tab	*ci = &ctlr_info[ctlr]; 
	register struct buf	*cq = &cyminfo[ctlr]->um_tab;
	register struct buf	*uq = cq->b_forw;
	register struct buf	*request = uq->av_forw;
	register int		unit = CYUNIT(request->b_dev);

	if(!(ci->tpb.status & CS_OL)) {
		ci->interupt_path = cy_normal_path;
		cy_normal_path(ctlr);
E 4
		return;
	}
D 4
	if(ci->tpb.control & CW_REV) {
		if(!(ci->tpb.status & CS_LP)) {
			cyexecute(SPACE, (long)1, 0, 0, unit, 5, TRUE);
			return;
E 2
		}
D 2
		return geterror(bp);
	case MTIOCGET:
		mtget = (struct mtget *)data;
		mtget->mt_dsreg = cy->cy_status[0];
		mtget->mt_erreg = cy->cy_status[1];
		mtget->mt_resid = cy->cy_count;
		mtget->mt_type = MT_ISCY;
		break;
	default:
		return ENXIO;
E 2
	}
D 2
	return 0;
E 2
I 2
	ci->interupt_path = cy_do_again_path;
	cyexecute(ERASE_F, (long)unit_info[unit].error_count, 0, 0,
	    unit, 5, TRUE);
E 4
I 4
	/* eof on read */
D 11
	yc->yc_nxrec = bdbtofsb(bp->b_blkno);
E 11
I 11
	yc->yc_nxrec = bp->b_blkno;
E 11
E 4
E 2
D 18
}

D 4

I 2
/*
**
*/
E 2

I 2
cy_do_again_path(ctlr)
register int	ctlr;
E 4
I 4
cyread(dev, uio)
	dev_t dev;
	struct uio *uio;
E 4
{
D 4
	extern int		cy_normal_path();
	register ctlr_tab	*ci = &ctlr_info[ctlr]; 
E 4
I 4
	int errno;
E 4

D 4
	if(!(ci->tpb.status & CS_OL)) {
		ci->interupt_path = cy_normal_path;
		cy_normal_path(ctlr);
		return;
	}
	ci->tpb = ci->last;
	uncache(&ci->ccb.gate);
	while(ci->ccb.gate == GATE_CLOSED)
		uncache(&ci->ccb.gate);
	load_mbus_addr((caddr_t)&ci->tpb, ci->ccb.tpb_ptr);
	ci->ccb.ccw = NORMAL_INTERUPT;
	ci->ccb.gate = GATE_CLOSED;
	ci->interupt_path = cy_normal_path;
	CY_ATTENTION(cyminfo[ctlr]->um_addr);
E 4
I 4
	errno = cyphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(cystrategy, &rcybuf[CYUNIT(dev)], dev, B_READ, minphys, uio));
E 4
}

D 4

E 2
/*
D 2
 * Check that a raw device exists.
 * If it does, set up cy_blkno and cy_nxrec
 * so that the tape will appear positioned correctly.
 */
cyphys(dev, uio)
dev_t dev;
struct uio *uio;
E 2
I 2
**	for each longword in the tpb we call uncache to  purge it from
**  the cache.  This is done so that we can correctly access tpb data
**  that was placed there by the controller.
*/

uncache_tpb(ci)
ctlr_tab	*ci;
E 4
I 4
cywrite(dev, uio)
	dev_t dev;
	struct uio *uio;
E 4
E 2
{
D 2
	register int cyunit = CYUNIT(dev);
	register daddr_t a;
	register struct cy_softc *cy;
	register struct vba_device *ui;
E 2
I 2
D 4
	register long	*ptr = (long *)&ci->tpb;
	register int	i;
E 4
I 4
	int errno;
E 4
E 2

D 2
	if (cyunit >= NCY || (ui=cydinfo[cyunit]) == 0 || ui->ui_alive == 0)
		return ENXIO;
	cy = &cy_softc[cyunit];
	a = bdbtofsb(uio->uio_offset >> PGSHIFT);
	cy->cy_blkno = a;
	cy->cy_nxrec = a + 1;
	return 0;
E 2
I 2
D 4
	for(i=0; i<((sizeof(fmt_tpb)+sizeof(long)-1)/sizeof(long)); i++)
		uncache(ptr++);
E 4
I 4
	errno = cyphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(cystrategy, &rcybuf[CYUNIT(dev)], dev, B_WRITE, minphys, uio));
E 4
E 2
}

I 2
D 4

E 4
E 2
/*
D 2
 *  Set a TAPEMASTER pointer (first parameter), into the
 *  4 bytes array pointed by the second parameter.
 */
set_pointer(pointer, dest)
int pointer;
char * dest;
E 2
I 2
D 4
**	Cyprint_error is the common printing routine for all messages
**  that need to print the tape status along with it.  This is so we
**  we can save space, have consistant messages, and we can send the messages
**  to the correct places.
*/

cyprint_err(message, unit, status)
register char	*message;
register int	unit, status;
E 2
{
D 2
	*dest++ = pointer & 0xff;		/* low byte - offset */
	*dest++ = (pointer >> 8) & 0xff;	/* high byte - offset */
	*dest++ = 0; 
	*dest   = (pointer & 0xf0000) >> 12;	/* base */
E 2
I 2
	status &= 0xffff;
	printf("cy%d: %s!   Status = %x\n", unit, message, status);
E 2
}

I 2
/*
**	Decode the error to determine whether the previous command was
**  ok, retryable, or fatal and return the value.  If it was a hardware
**  problem we print the message to the console, otherwise we print it
**  to the user's terminal later when execute returns.
*/

cydecode_error(unit, status)
register int	unit,	status;
{
	register unit_tab	*ui = &unit_info[unit];
	register ctlr_tab	*ci = &ctlr_info[cydinfo[unit]->ui_ctlr];

	if(!(status & CS_OL) && (ci->tpb.cmd != OFF_UNL)) {
		ui->message = "Drive is not on-line";
		cyprint_err(ui->message, unit, status);
		return FATAL;
	}
	ui->bot = ((status & CS_LP) != 0);
	ui->eof = ((status & CS_FM) != 0);
	switch(status & CS_ERm) {
	case ER_EOT:
		if(ci->tpb.control & CW_REV) {
			ui->bot = TRUE;
			ui->eot = FALSE;
		}
		else if(!ui->eot){
			ui->message = "End of tape";
			ui->bot = FALSE;
			ui->eot = TRUE;
		}
	case 0 :
	case ER_FM:
	case ER_NOSTRM:
		return	0;
	case ER_TIMOUT:
	case ER_TIMOUT1:
	case ER_TIMOUT2:
	case ER_TIMOUT3:
	case ER_TIMOUT4:
		ui->message = "Drive timed out during transfer";
		cyprint_err(ui->message, unit, status);
		return FATAL;
	case ER_NEX:	
		ui->message =
		    "Controller referenced non-existant system memory";
		cyprint_err(ui->message, unit, status);
		return FATAL;
	case ER_DIAG:
	case ER_JUMPER:
		ui->message = "Controller diagnostics failed";
		cyprint_err(ui->message, unit, status);
		return FATAL;
	case ER_STROBE:
		if (ci->tpb.cmd == READ_BU) {
			ci->last.cmd = READ_TA;	
			return RETRY;
		}
		if(ci->tpb.cmd == READ_TA)
			return 0;
		ui->message = "Unsatisfactory media found";
		return	FATAL;
	case ER_FIFO:
	case ER_NOTRDY:
		ui->error_count = 1;
		return RETRY;
	case ER_PROT:
		ui->message = "Tape is write protected";
		return FATAL;
	case ER_CHKSUM:
		ui->message = "Checksum error in controller proms";
		cyprint_err(ui->message, unit, status);
		return FATAL;
	case ER_HARD:
		ui->error_count++;
		if((ci->tpb.cmd == WRIT_TA) ||
		    (ci->tpb.cmd == WRIT_BU) ||
		    (ci->tpb.cmd == WRIT_FM)) {
			ui->bad_count++;
			return EXTEND;
		}
		ui->message = "Unrecoverable media error during read";
		return FATAL;
	case ER_PARITY:
		if(++ui->error_count < 8)
			return	RETRY;
		ui->message = "Unrecoverable tape parity error";
		return FATAL;
	case ER_BLANK:
		ui->message="Blank tape found (data expected)";
		return FATAL;
	case ER_HDWERR:
	default:
		ui->message = "Unrecoverble hardware error";
		cyprint_err(ui->message, unit, status);
		return FATAL;
	}
}

cyread(dev, uio)
E 4
I 4
 * Check that a raw device exits.
 * If it does, set up the yc_blkno and yc_nxrec
 * so that the tape will appear positioned correctly.
 */
cyphys(dev, uio)
E 4
	dev_t dev;
	struct uio *uio;
{
D 4
	unit_tab *ui = &unit_info[CYUNIT(dev)];
	
	return (physio(cystrategy, &ui->rawbp, dev, B_READ, cyminsize, uio));
}
E 4
I 4
	register int ycunit = YCUNIT(dev);
	register daddr_t a;
	register struct yc_softc *yc;
	register struct vba_device *vi;
E 4

D 4

cywrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	unit_tab *ui = &unit_info[CYUNIT(dev)];

	return (physio(cystrategy,&ui->rawbp, dev, B_WRITE, cyminsize, uio));
E 4
I 4
	if (ycunit >= NYC || (vi = ycdinfo[ycunit]) == 0 || vi->ui_alive == 0)
		return (ENXIO);
	yc = &yc_softc[ycunit];
D 11
	a = bdbtofsb(uio->uio_offset >> DEV_BSHIFT);
E 11
I 11
	a = uio->uio_offset >> DEV_BSHIFT;
E 11
	yc->yc_blkno = a;
	yc->yc_nxrec = a + 1;
	return (0);
E 18
E 4
}

/*ARGSUSED*/
cyioctl(dev, cmd, data, flag)
D 4
	dev_t dev;
E 4
	caddr_t data;
I 4
	dev_t dev;
E 4
{
I 4
	int ycunit = YCUNIT(dev);
	register struct yc_softc *yc = &yc_softc[ycunit];
	register struct buf *bp = &ccybuf[CYUNIT(dev)];
	register callcount;
	int fcount, op;
	struct mtop *mtop;
	struct mtget *mtget;
	/* we depend of the values and order of the MT codes here */
	static cyops[] =
D 9
	{CY_WEOF,CY_SFORW,CY_SREV,CY_SFORW,CY_SREV,CY_REW,CY_OFFL,CY_SENSE};
E 9
I 9
	{CY_WEOF,CY_FSF,CY_BSF,CY_SFORW,CY_SREV,CY_REW,CY_OFFL,CY_SENSE};
E 9
E 4

	switch (cmd) {

D 4
	case MTIOCTOP: {
		struct mtop *mp = (struct mtop *)data;
E 4
I 4
	case MTIOCTOP:	/* tape operation */
		mtop = (struct mtop *)data;
		switch (op = mtop->mt_op) {
E 4

D 4
		if (mp->mt_op <= DO_WAIT)
			return (cycmd(dev, (int)mp->mt_op, (int)mp->mt_count));
		return (EIO);
	}
E 4
I 4
		case MTWEOF:
I 9
			callcount = mtop->mt_count;
			fcount = 1;
			break;

E 9
		case MTFSR: case MTBSR:
I 9
			callcount = 1;
			fcount = mtop->mt_count;
			break;

E 9
		case MTFSF: case MTBSF:
			callcount = mtop->mt_count;
			fcount = 1;
			break;
E 4

D 4
	case MTIOCGET: {
		register unit_tab *ui = &unit_info[CYUNIT(dev)];
		register struct mtget *mp = (struct mtget *)data;
E 4
I 4
		case MTREW: case MTOFFL: case MTNOP:
			callcount = 1;
			fcount = 1;
			break;
E 4

D 4
		mp->mt_type = MT_ISCY;
		mp->mt_dsreg = ui->last_control;
		mp->mt_erreg = ui->last_status;
		mp->mt_resid = ui->last_resid;
		mp->mt_fileno = ui->file_number;
		mp->mt_blkno = ui->blkno;
		cycmd(dev, DO_STAT, 1);
E 4
I 4
		default:
			return (ENXIO);
		}
		if (callcount <= 0 || fcount <= 0)
			return (EINVAL);
		while (--callcount >= 0) {
I 9
#ifdef notdef
E 9
			/*
			 * Gagh, this controller is the pits...
			 */
			if (op == MTFSF || op == MTBSF) {
				do
					cycommand(dev, cyops[op], 1);
				while ((bp->b_flags&B_ERROR) == 0 &&
				 (yc->yc_status&(CYS_EOT|CYS_BOT|CYS_FM)) == 0);
			} else
I 9
#endif
E 9
				cycommand(dev, cyops[op], fcount);
I 9
			dlog((LOG_INFO,
			    "cyioctl: status %x, b_flags %x, resid %d\n",
			    yc->yc_status, bp->b_flags, bp->b_resid));
E 9
			if ((bp->b_flags&B_ERROR) ||
			    (yc->yc_status&(CYS_BOT|CYS_EOT)))
				break;
		}
		bp->b_resid = callcount + 1;
		return (geterror(bp));

	case MTIOCGET:
		cycommand(dev, CY_SENSE, 1);
		mtget = (struct mtget *)data;
		mtget->mt_dsreg = yc->yc_status;
		mtget->mt_erreg = yc->yc_control;
		mtget->mt_resid = yc->yc_resid;
		mtget->mt_type = MT_ISCY;
E 4
		break;
D 4
	}
E 4

	default:
		return (ENXIO);
	}
	return (0);
}

/*
D 4
 * Dump routine.
 */
E 2
cydump(dev)
D 2
dev_t	dev;
E 2
I 2
	dev_t dev;
E 2
{
D 2
	register struct vba_device *ui;
	register struct tpb *tp;
	int cyunit = CYUNIT(dev);
	int blk, num;
	int start;
E 2
I 2
	register int		unit = CYUNIT(dev);
	register int		ctlr = cydinfo[unit]->ui_ctlr;
	register unit_tab	*ui = &unit_info[unit];
	register ctlr_tab	*ci = &ctlr_info[ctlr];
	register int		blk_siz;
	register int		num = maxfree;
	register int		start = 0x800;
E 2

D 2
	start = 0x800;
	num = maxfree;
	tp = &tpb[cyunit];
	if (cyunit >= NCY || (ui=cydinfo[cyunit]) == 0 || ui->ui_alive == 0) 
E 2
I 2
	if ((unit >= NCY) || cydinfo[unit]) 
E 2
		return(ENXIO);
D 2
	if (cywait) return(EFAULT);
E 2
I 2
	ui->control_proto = CW_LOCK | CW_25ips | CW_16bits;
	if (cywait(&ci->ccb))
		return(EFAULT);
E 2
	while (num > 0) {
D 2
		blk = num > TBUFSIZ ? TBUFSIZ : num;
		bcopy(start*NBPG, cybuf, blk*NBPG);
		tp->cmd = WRIT_BU;	
		tp->control[0] = cyunit<<CW_TSs;
		tp->control[1] = (CW_100ips | CW_16bits);
		tp->status[0] = tp->status[1] = 0;
		tp->size = TM_SHORT(blk*NBPG);
		set_pointer((int)cybuf, (char *)tp->pt_data);
		set_pointer((int)&tpb[cyunit], (char *)ccb.pt_tpb);
		ccb.gate[0] = GATE_CLOSED;	
		TM_ATTENTION(cyaddr, 0xff);		/* execute! */
		start += blk;
		num -= blk;
		if (cywait) return(EFAULT);
		uncache(&tp->status[1]);
		if (tp->status[1]&CS_ERm)		/* error */
E 2
I 2
		blk_siz = num > TBUFSIZ ? TBUFSIZ : num;
		bcopy((caddr_t)(start*NBPG), (caddr_t)ci->rawbuf,
		    (unsigned)(blk_siz*NBPG));
		ci->tpb.cmd = WRIT_TA;	
		ci->tpb.control = ui->control_proto;
		ci->tpb.status = 0;
		ci->tpb.size = MULTIBUS_SHORT(blk_siz*NBPG);
		load_mbus_addr((caddr_t)0, ci->tpb.link_ptr);
		load_mbus_addr((caddr_t)ci->rawbuf, (short *)&ci->tpb.data_ptr);
		load_mbus_addr((caddr_t)&ci->tpb, ci->ccb.tpb_ptr);
		ci->ccb.gate = GATE_CLOSED;	
		CY_ATTENTION(cyminfo[ctlr]->um_addr);
		start += blk_siz;
		num -= blk_siz;
		if (cywait(&ci->ccb))
			return(EFAULT);
		uncache(&ci->tpb);
		if (ci->tpb.status&CS_ERm)		/* error */
E 2
			return (EIO);
	}
D 2
	cyeof(tp, cyunit);
	if (cywait) return(EFAULT);
	cyeof(tp, cyunit);
	if (cywait) return(EFAULT);
	uncache(&tp->status[1]);
	if (tp->status[1]&CS_ERm)		/* error */
		return (EIO);
	cyrewind(tp, cyunit);
	return (0);
E 2
I 2
	for(num=0; num<2; num++) {
		ci->tpb.cmd = WRIT_FM;	
		ci->tpb.control = ui->control_proto;
		ci->tpb.status = ci->tpb.size = 0;
		ci->tpb.count = MULTIBUS_SHORT(1);
		load_mbus_addr((caddr_t)0, ci->tpb.link_ptr);
		load_mbus_addr((caddr_t)ci->rawbuf, (short *)&ci->tpb.data_ptr);
		load_mbus_addr((caddr_t)&ci->tpb, ci->ccb.tpb_ptr);
		ci->ccb.gate = GATE_CLOSED;	
		CY_ATTENTION(cyminfo[ctlr]->um_addr);
		if (cywait(&ci->ccb))
			return(EFAULT);
		uncache(&ci->tpb);
		if (ci->tpb.status&CS_ERm)		/* error */
			return (EIO);
	}
	ci->tpb.cmd = REWD_OV;	
	ci->tpb.control = ui->control_proto;
	ci->tpb.status = ci->tpb.size = 0;
	ci->tpb.count = MULTIBUS_SHORT(1);
	load_mbus_addr((caddr_t)0, ci->tpb.link_ptr);
	load_mbus_addr((caddr_t)ci->rawbuf, (short *)&ci->tpb.data_ptr);
	load_mbus_addr((caddr_t)&ci->tpb, ci->ccb.tpb_ptr);
	ci->ccb.gate = GATE_CLOSED;	
	CY_ATTENTION(cyminfo[ctlr]->um_addr);
	if (cywait(&ci->ccb))
		return EFAULT;
	uncache(&ci->tpb);
	return 0;
E 2
}

D 2
cywait()
E 2
I 2
/*
E 4
 * Poll until the controller is ready.
 */
cywait(cp)
D 4
	register fmt_ccb *cp;
E 4
I 4
	register struct cyccb *cp;
E 4
E 2
{
D 2
	register cnt;
E 2
I 2
	register int i = 5000;
E 2

D 2
	cnt = 5000;		/* 5 seconds timeout */
	do {
		--cnt;
E 2
I 2
D 4
	uncache(&cp->gate);
	while (i-- > 0 && cp->gate == GATE_CLOSED) {
E 4
I 4
	uncache(&cp->cbgate);
	while (i-- > 0 && cp->cbgate == GATE_CLOSED) {
E 4
E 2
		DELAY(1000);
D 2
		uncache(&ccb.gate[0]);
E 2
I 2
D 4
		uncache(&cp->gate);
E 4
I 4
		uncache(&cp->cbgate);
E 4
E 2
	}
D 2
	while (cnt>0 && ccb.gate[0] == GATE_CLOSED);
	if (cnt == 0) return(1);	/* timeout */
	else return(0);
E 2
I 2
	return (i <= 0);
E 2
}

D 2
cyeof(tp, unit)
	register struct tpb *tp;
	int unit;
E 2
I 2
/*
D 4
 * Load a 20 bit pointer into the i/o registers.
E 4
I 4
D 9
 * Load a 20 bit pointer into an i/o register.
E 9
I 9
 * Load a 20 bit pointer into a Tapemaster pointer.
E 9
E 4
 */
D 4
load_mbus_addr(in, out)
	caddr_t in;
	short *out;
E 4
I 4
D 9
cyldmba(wreg, value)
	short *wreg;
E 9
I 9
cyldmba(reg, value)
D 17
	register caddr_t reg;
E 17
I 17
	register u_char *reg;
E 17
E 9
	caddr_t value;
E 4
E 2
{
D 2
	tp->cmd = WRIT_FM;	
	tp->control[0] = unit<<CW_TSs;
	tp->control[1] = (CW_100ips | CW_16bits);
	tp->status[0] = tp->status[1] = 0;
	tp->rec_over = TM_SHORT(1);
	set_pointer((int)&tpb[unit], (char *)ccb.pt_tpb);
	ccb.gate[0] = GATE_CLOSED;	
	TM_ATTENTION(cyaddr, 0xff);		/* execute! */
E 2
I 2
D 4
	register int tmp_in = (int)in;
	register char *out_ptr = (char *)out;
E 4
I 4
	register int v = (int)value;
D 9
	register caddr_t reg = (caddr_t)wreg;
E 9
E 4

D 4
	*out_ptr++ = (char)(tmp_in & 0xff);
	*out_ptr++ = (char)((tmp_in >> 8) & 0xff);
	*out_ptr++ = (char)0;
	*out_ptr++ = (char)((tmp_in & 0xf0000) >> 12);
E 4
I 4
	*reg++ = v;
	*reg++ = v >> 8;
	*reg++ = 0;
	*reg = (v&0xf0000) >> 12;
E 4
E 2
}

D 2

cyrewind(tp, unit)
	register struct tpb *tp;
	int unit;
E 2
I 2
/*
D 4
**	CYMINSIZE s supposed to adjust the buffer size for any raw i/o.
**  since tapes can not read  the tail end of partial blocks we ignore
**  this request and strategy will return an appropriate error message later.
**
**	If this is not done UNIX will lose data that is on the tape.
*/
unsigned
cyminsize(bp)
	struct buf *bp;
E 2
{
D 2
	tp->cmd = REWD_TA;	
	tp->control[0] = unit<<CW_TSs;
	tp->control[1] = (CW_100ips | CW_16bits);
	tp->status[0] = tp->status[1] = 0;
	set_pointer((int)&tpb[unit], (char *)ccb.pt_tpb);
	ccb.gate[0] = GATE_CLOSED;	
	TM_ATTENTION(cyaddr, 0xff);		/* execute! */
E 2
I 2
	if (bp->b_bcount > MAX_BLOCKSIZE)
		bp->b_bcount = MAX_BLOCKSIZE;	
E 2
}

D 2
unsigned
tminphys(bp)
register struct buf *bp;
E 2
I 2
/*
E 4
 * Unconditionally reset all controllers to their initial state.
 */
cyreset(vba)
	int vba;
E 2
{
I 2
	register caddr_t addr;
	register int ctlr;
E 2

D 2
	if (bp->b_bcount > sizeof cybuf)
		bp->b_bcount = sizeof cybuf;
E 2
I 2
	for (ctlr = 0; ctlr < NCY; ctlr++)
		if (cyminfo[ctlr] && cyminfo[ctlr]->um_vbanum == vba) {
			addr = cyminfo[ctlr]->um_addr;
			CY_RESET(addr);
D 4
			if (!cy_init_controller(addr, ctlr, 0)) {
E 4
I 4
D 9
			if (!cyinit(ctlr)) {
E 9
I 9
			if (!cyinit(ctlr, addr)) {
E 9
E 4
				printf("cy%d: reset failed\n", ctlr);
				cyminfo[ctlr] = NULL;
			}
		}
I 4
}

cyuncachetpb(cy)
	struct cy_softc *cy;
{
	register long *lp = (long *)&cy->cy_tpb;
	register int i;

	for (i = 0; i < howmany(sizeof (struct cytpb), sizeof (long)); i++)
		uncache(lp++);
}

/*
 * Dump routine.
 */
I 12
#define	DUMPREC	(32*1024)
E 12
cydump(dev)
	dev_t dev;
{
	register struct cy_softc *cy;
	register int bs, num, start;
	register caddr_t addr;
D 8
	int unit = CYUNIT(dev), ctlr, error;
E 8
I 8
	int unit = CYUNIT(dev), error;
E 8

	if (unit >= NCY || cyminfo[unit] == 0 ||
	    (cy = &cy_softc[unit])->cy_bs == 0 || YCUNIT(dev) >= NYC)
		return (ENXIO);
	if (cywait(&cy->cy_ccb))
		return (EFAULT);
#define	phys(a)	((caddr_t)((int)(a)&~0xc0000000))
D 8
	addr = phys(cyminfo[ctlr]->um_addr);
E 8
I 8
	addr = phys(cyminfo[unit]->um_addr);
E 8
	num = maxfree, start = NBPG*2;
	while (num > 0) {
D 12
		bs = num > btoc(CYMAXIO) ? btoc(CYMAXIO) : num;
E 12
I 12
		bs = num > btoc(DUMPREC) ? btoc(DUMPREC) : num;
E 12
		error = cydwrite(cy, start, bs, addr);
		if (error)
			return (error);
		start += bs, num -= bs;
	}
	cyweof(cy, addr);
	cyweof(cy, addr);
	uncache(&cy->cy_tpb);
	if (cy->cy_tpb.tpstatus&CYS_ERR)
		return (EIO);
	cyrewind(cy, addr);
	return (0);
}

cydwrite(cy, pf, npf, addr)
	register struct cy_softc *cy;
	int pf, npf;
	caddr_t addr;
{

	cy->cy_tpb.tpcmd = CY_WCOM;
	cy->cy_tpb.tpcontrol = CYCW_LOCK|CYCW_25IPS|CYCW_16BITS;
	cy->cy_tpb.tpstatus = 0;
	cy->cy_tpb.tpsize = htoms(npf*NBPG);
	cyldmba(cy->cy_tpb.tplink, (caddr_t)0);
	cyldmba(cy->cy_tpb.tpdata, (caddr_t)(pf*NBPG));
	cyldmba(cy->cy_ccb.cbtpb, (caddr_t)&cy->cy_tpb);
	cy->cy_ccb.cbgate = GATE_CLOSED;
	CY_GO(addr);
	if (cywait(&cy->cy_ccb))
		return (EFAULT);
	uncache(&cy->cy_tpb);
	if (cy->cy_tpb.tpstatus&CYS_ERR)
		return (EIO);
	return (0);
}

cyweof(cy, addr)
	register struct cy_softc *cy;
	caddr_t addr;
{

	cy->cy_tpb.tpcmd = CY_WEOF;
	cy->cy_tpb.tpcount = htoms(1);
	cy->cy_ccb.cbgate = GATE_CLOSED;	
	CY_GO(addr);
	(void) cywait(&cy->cy_ccb);
}

cyrewind(cy, addr)
	register struct cy_softc *cy;
	caddr_t addr;
{

	cy->cy_tpb.tpcmd = CY_REW;	
	cy->cy_tpb.tpcount = htoms(1);
	cy->cy_ccb.cbgate = GATE_CLOSED;	
	CY_GO(addr);
	(void) cywait(&cy->cy_ccb);
E 4
E 2
}
#endif
E 1
