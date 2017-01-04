h07900
s 00002/00000/00141
d D 7.4 04/12/08 04:06:26 msokolov 26 25
c exception select for modem status changes
e
s 00001/00000/00140
d D 7.3 03/04/07 00:41:39 msokolov 25 24
c add flag for tty kb hacks (TS_KBHACKS)
e
s 00004/00001/00136
d D 7.2 03/03/29 16:26:27 msokolov 24 23
c add KOI mode
e
s 00001/00001/00136
d D 7.1 86/06/04 23:30:03 mckusick 23 22
c 4.3BSD release version
e
s 00007/00001/00130
d D 6.4 85/06/08 15:10:22 mckusick 22 21
c Add copyright
e
s 00001/00000/00130
d D 6.3 84/12/31 12:42:45 bloom 21 20
c added window sizes to tty structure
e
s 00002/00002/00128
d D 6.2 84/08/28 17:29:41 bloom 20 19
c Change include paths.  No more ../h
e
s 00000/00000/00130
d D 6.1 83/07/29 06:14:30 sam 19 18
c 4.2 distribution
e
s 00000/00001/00130
d D 4.13 82/12/19 17:29:50 sam 18 17
c t_char not used
e
s 00056/00063/00075
d D 4.12 82/12/05 21:52:44 sam 17 16
c merge local state and flags; move ioctl stuff to other files
e
s 00001/00000/00137
d D 4.11 82/03/15 04:48:58 wnj 16 15
c name changes; get/sethostname
e
s 00001/00000/00136
d D 4.10 82/02/08 23:50:36 root 15 14
c add DMGET for DZ32
e
s 00001/00001/00135
d D 4.9 82/01/30 19:15:12 wnj 14 13
c restore sccs line
e
s 00019/00003/00117
d D 4.8 82/01/30 19:14:39 wnj 13 12
c concessiont to bk line disc
e
s 00015/00013/00105
d D 4.7 82/01/14 17:01:40 wnj 12 11
c more non-blocking stuff
e
s 00045/00075/00073
d D 4.6 81/10/17 16:14:39 wnj 11 10
c cleanup (mpx removal, old tty removal, beginnings of select)
e
s 00001/00001/00147
d D 4.5 81/06/11 16:08:36 wnj 10 9
c /TTYHOG/s/256/255/ to fix problem with counting in chars in ttynew.c
e
s 00000/00001/00148
d D 4.4 81/04/19 13:36:48 wnj 9 8
c remove t_[io]bp
e
s 00001/00001/00148
d D 4.3 81/02/19 21:42:39 wnj 8 7
c %G%->%E%
e
s 00008/00003/00141
d D 4.2 80/12/17 11:46:48 wnj 7 6
c combined 750/780
e
s 00000/00000/00144
d D 4.1 80/11/09 17:01:53 bill 6 5
c stamp for 4bsd
e
s 00007/00002/00137
d D 3.5 80/09/27 17:55:21 bill 5 4
c speed dependent lo/hi water marks
e
s 00001/00001/00138
d D 3.4 80/06/07 03:01:36 bill 4 3
c %H%->%G%
e
s 00055/00116/00084
d D 3.3 80/05/15 17:18:19 bill 3 2
c new fields for new tty driver
e
s 00029/00002/00171
d D 3.2 80/05/08 10:14:51 bill 2 1
c added BNETLDIS
e
s 00173/00000/00000
d D 3.1 80/04/09 16:25:39 bill 1 0
c date and time created 80/04/09 16:25:39 by bill
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%H%	*/
E 4
I 4
D 8
/*	%M%	%I%	%G%	*/
E 8
I 8
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
D 14
/*	tty.h	4.8	82/01/20	*/
E 14
I 14
D 22
/*	%M%	%I%	%E%	*/
E 22
I 22
/*
D 23
 * Copyright (c) 1982 Regents of the University of California.
E 23
I 23
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 23
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 22
E 14
E 13
E 8
E 4
I 3

D 7
#include <sgtty.h>
E 7
I 7
#ifdef KERNEL
D 17
#include "../h/ioctl.h"
E 17
I 17
D 20
#include "../h/ttychars.h"
#include "../h/ttydev.h"
E 20
I 20
#include "ttychars.h"
#include "ttydev.h"
E 20
E 17
#else
E 7
D 17
#include <sys/ioctl.h>
E 17
I 17
#include <sys/ttychars.h>
#include <sys/ttydev.h>
E 17
I 7
#endif
D 17
#include <sgtty.h>
E 17
E 7

E 3
/*
D 11
 * A clist structure is the head
 * of a linked list queue of characters.
D 3
 * The characters are stored in 4-word
 * blocks containing a link and several characters.
 * The routines getc and putc
E 3
I 3
 * The characters are stored in
 * blocks containing a link and CBSIZE (param.h)
 * characters.  The routines getc, putc, ... in prim.c
E 3
 * manipulate these structures.
E 11
I 11
D 17
 * A clist structure is the head of a linked list queue of characters.
 * The characters are stored in blocks containing a link and CBSIZE (param.h)
 * characters.  The routines in prim.c manipulate these structures.
E 17
I 17
 * A clist structure is the head of a linked list queue
 * of characters.  The characters are stored in blocks
 * containing a link and CBSIZE (param.h) characters. 
 * The routines in tty_subr.c manipulate these structures.
E 17
E 11
 */
D 11
struct clist
{
E 11
I 11
struct clist {
E 11
	int	c_cc;		/* character count */
	char	*c_cf;		/* pointer to first char */
	char	*c_cl;		/* pointer to last char */
};

/*
D 11
 * A tty structure is needed for
 * each UNIX character device that
 * is used for normal terminal IO.
 * The routines in tty.c handle the
 * common code associated with
D 3
 * these structures.
 * The definition and device dependent
 * code is in each driver. (kl.c dz.c)
E 3
I 3
 * these structures.  The definition
 * and device dependent code is in
 * each driver. (cons.c, dh.c, dz.c, kl.c)
E 11
I 11
D 17
 * Per-tty structre.
E 17
I 17
 * Per-tty structure.
E 17
 *
 * Should be split in two, into device and tty drivers.
 * Glue could be masks of what to echo and circular buffer
 * (low, high, timeout).
E 11
E 3
 */
D 3

struct tc {
	char	t_intrc;	/* interrupt */
	char	t_quitc;	/* quit */
	char	t_startc;	/* start output */
	char	t_stopc;	/* stop output */
	char	t_eofc;		/* end-of-file */
	char	t_brkc;		/* input delimiter (like nl) */
};

E 3
D 17
struct tty
{
E 17
I 17
struct tty {
E 17
D 2
	struct	clist t_rawq;	/* input chars right off device */
	struct	clist t_canq;	/* input chars after erase and kill */
E 2
I 2
D 11
	union {
		struct {
			struct	clist T_rawq;
			struct	clist T_canq;
		} t_t;
D 3
#define	t_rawq	t_nu.t_t.T_rawq	/* input chars right off device */
#define	t_canq	t_nu.t_t.T_canq	/* input chars after erase and kill */
#ifdef BERKNET
E 3
I 3
#define	t_rawq	t_nu.t_t.T_rawq		/* raw characters or partial line */
#define	t_canq	t_nu.t_t.T_canq		/* complete input lines */
E 3
		struct {
			struct	buf *T_bufp;
			char	*T_cp;
			int	T_inbuf;
I 3
			int	T_rec;
E 3
		} t_n;
D 3
#define	t_bufp	t_nu.t_n.T_bufp	/* buffer we ripped off for network */
#define	t_cp	t_nu.t_n.T_cp	/* pointer into the ripped off buffer */
#define	t_inbuf	t_nu.t_n.T_inbuf/* number chars in the magic buffer */
#endif
E 3
I 3
#define	t_bufp	t_nu.t_n.T_bufp		/* buffer allocated to protocol */
#define	t_cp	t_nu.t_n.T_cp		/* pointer into the ripped off buffer */
#define	t_inbuf	t_nu.t_n.T_inbuf	/* number chars in the buffer */
#define	t_rec	t_nu.t_n.T_rec		/* have a complete record */
E 3
	} t_nu;
E 2
	struct	clist t_outq;	/* output list to device */
	int	(*t_oproc)();	/* routine to start output */
	int	(*t_iproc)();	/* routine to start input */
	struct chan *t_chan;	/* destination channel */
	caddr_t	t_linep;	/* aux line discipline pointer */
	caddr_t	t_addr;		/* device address */
	dev_t	t_dev;		/* device number */
	short	t_flags;	/* mode, settable by ioctl call */
	short	t_state;	/* internal state, not visible externally */
	short	t_pgrp;		/* process group name */
	char	t_delct;	/* number of delimiters in raw q */
	char	t_line;		/* line discipline */
	char	t_col;		/* printing column of device */
	char	t_erase;	/* erase character */
	char	t_kill;		/* kill character */
	char	t_char;		/* character temporary */
	char	t_ispeed;	/* input speed */
	char	t_ospeed;	/* output speed */
E 11
I 11
D 13
	struct	clist t_rawq;		/* device */
	struct	clist t_canq;		/* tty */
E 13
I 13
	union {
		struct {
			struct	clist T_rawq;
			struct	clist T_canq;
		} t_t;
#define	t_rawq	t_nu.t_t.T_rawq		/* raw characters or partial line */
#define	t_canq	t_nu.t_t.T_canq		/* raw characters or partial line */
		struct {
			struct	buf *T_bufp;
			char	*T_cp;
			int	T_inbuf;
			int	T_rec;
		} t_n;
#define	t_bufp	t_nu.t_n.T_bufp		/* buffer allocated to protocol */
#define	t_cp	t_nu.t_n.T_cp		/* pointer into the ripped off buffer */
#define	t_inbuf	t_nu.t_n.T_inbuf	/* number chars in the buffer */
#define	t_rec	t_nu.t_n.T_rec		/* have a complete record */
	} t_nu;
E 13
	struct	clist t_outq;		/* device */
	int	(*t_oproc)();		/* device */
	struct	proc *t_rsel;		/* tty */
D 12
				struct chan *T_CHAN;	/* ### */
E 12
I 12
	struct	proc *t_wsel;
E 12
				caddr_t	T_LINEP;	/* ### */
	caddr_t	t_addr;			/* ??? */
	dev_t	t_dev;			/* device */
D 17
	short	t_flags;		/* some of both */
	short	t_state;		/* some of both */
E 17
I 17
	int	t_flags;		/* some of both */
	int	t_state;		/* some of both */
E 17
	short	t_pgrp;			/* tty */
	char	t_delct;		/* tty */
I 17
D 18
	char	t_char;			/* tty */
E 18
E 17
	char	t_line;			/* glue */
	char	t_col;			/* tty */
D 17
	char	t_erase, t_kill;	/* tty */
	char	t_char;			/* tty */
E 17
	char	t_ispeed, t_ospeed;	/* device */
E 11
I 3
D 17
/* begin local */
E 17
D 11
	char	t_rocount;	/* chars input since a ttwrite() */
	char	t_rocol;	/* t_col when first input this line */
	struct	ltchars t_lchr;	/* local special characters */
	short	t_local;	/* local mode word */
	short	t_lstate;	/* local state bits */
E 11
I 11
	char	t_rocount, t_rocol;	/* tty */
D 17
	struct	ltchars t_lchr;		/* tty */
	short	t_local;		/* tty */
	short	t_lstate;		/* tty */
E 11
/* end local */
E 3
	union {
D 3
		struct tc t_chr;
E 3
I 3
D 11
		struct tchars t_chr;
E 3
		struct clist t_ctlq;
E 11
I 11
		struct tchars t_chr;	/* tty */
		struct clist T_CTLQ;
E 11
	} t_un;
E 17
I 17
	struct	ttychars t_chars;	/* tty */
I 21
	struct	winsize t_winsize;	/* window size */
E 21
/* be careful of tchars & co. */
#define	t_erase		t_chars.tc_erase
#define	t_kill		t_chars.tc_kill
#define	t_intrc		t_chars.tc_intrc
#define	t_quitc		t_chars.tc_quitc
#define	t_startc	t_chars.tc_startc
#define	t_stopc		t_chars.tc_stopc
#define	t_eofc		t_chars.tc_eofc
#define	t_brkc		t_chars.tc_brkc
#define	t_suspc		t_chars.tc_suspc
#define	t_dsuspc	t_chars.tc_dsuspc
#define	t_rprntc	t_chars.tc_rprntc
#define	t_flushc	t_chars.tc_flushc
#define	t_werasc	t_chars.tc_werasc
#define	t_lnextc	t_chars.tc_lnextc
E 17
I 7
D 9
	struct	buf *t_ibp, *t_obp;
E 9
E 7
};

D 17
#define	tun	tp->t_un.t_chr
I 3
#define	tlun	tp->t_lchr
E 3

E 17
D 3
/*
 * structure of arg for ioctl
 */
struct	ttiocb {
	char	ioc_ispeed;
	char	ioc_ospeed;
	char	ioc_erase;
	char	ioc_kill;
	short	ioc_flags;
};

E 3
#define	TTIPRI	28
#define	TTOPRI	29

D 3
#define	CERASE	'#'		/* default special characters */
#define	CEOT	004
E 3
I 3
D 17
#define	CTRL(c)	('c'&037)

/* default special characters */
#define	CERASE	'#'
#define	CEOT	CTRL(d)
E 3
#define	CKILL	'@'
#define	CQUIT	034		/* FS, cntl shift L */
#define	CINTR	0177		/* DEL */
D 3
#define	CSTOP	023		/* Stop output: ctl-s */
#define	CSTART	021		/* Start output: ctl-q */
E 3
I 3
#define	CSTOP	CTRL(s)
#define	CSTART	CTRL(q)
E 3
#define	CBRK	0377

E 17
/* limits */
D 5
#define	TTHIWAT	650
#define	TTLOWAT	125
E 5
I 5
#define	NSPEEDS	16
#define	TTMASK	15
I 17
#define	OBUFSIZ	100
#define	TTYHOG	255
E 17
#ifdef KERNEL
short	tthiwat[NSPEEDS], ttlowat[NSPEEDS];
#define	TTHIWAT(tp)	tthiwat[(tp)->t_ospeed&TTMASK]
#define	TTLOWAT(tp)	ttlowat[(tp)->t_ospeed&TTMASK]
I 17
extern	struct ttychars ttydefaults;
E 17
#endif
E 5
D 10
#define	TTYHOG	256
E 10
I 10
D 17
#define	TTYHOG	255
E 17
E 10

D 3
/* modes */
#define	TANDEM	01
#define	CBREAK	02
#define	LCASE	04
#define	ECHO	010
#define	CRMOD	020
#define	RAW	040
#define	ODDP	0100
#define	EVENP	0200
#define	NLDELAY	001400
#define	TBDELAY	006000
#define	XTABS	006000
#define	CRDELAY	030000
#define	VTDELAY	040000

/* Hardware bits */
E 3
I 3
D 17
/* hardware bits */
E 3
#define	DONE	0200
#define	IENABLE	0100

E 17
D 3
/* Internal state bits */
#define	TIMEOUT	01		/* Delay timeout in progress */
#define	WOPEN	02		/* Waiting for open to complete */
#define	ISOPEN	04		/* Device is open */
E 3
I 3
/* internal state bits */
D 11
#define	TIMEOUT	01		/* delay timeout in progress */
#define	WOPEN	02		/* waiting for open to complete */
#define	ISOPEN	04		/* device is open */
E 3
#define	FLUSH	010		/* outq has been flushed during DMA */
D 3
#define	CARR_ON	020		/* Software copy of carrier-present */
#define	BUSY	040		/* Output in progress */
#define	ASLEEP	0100		/* Wakeup when output done */
E 3
I 3
#define	CARR_ON	020		/* software copy of carrier-present */
#define	BUSY	040		/* output in progress */
#define	ASLEEP	0100		/* wakeup when output done */
E 3
#define	XCLUDE	0200		/* exclusive-use flag against open */
D 3
#define	TTSTOP	0400		/* Output stopped by ctl-s */
#define	HUPCLS	01000		/* Hang up upon last close */
E 3
I 3
#define	TTSTOP	0400		/* output stopped by ctl-s */
#define	HUPCLS	01000		/* hang up upon last close */
E 3
#define	TBLOCK	02000		/* tandem queue blocked */
#define	SPEEDS	04000		/* t_ispeed and t_ospeed used by driver */
D 7
#define	PROTO1	010000		/* reserved for line discipline */
E 7
I 7
#define	NDQB	010000
E 7
#define	EXTPROC	020000		/* external processor (kmc) */
#define	FSLEEP	040000		/* Wakeup on input framing */
D 7
#define	CNTLQ	0100000		/* interpret t_un as clist */
E 7
I 7
#define	BEXT	0100000		/* use (external) system buffers */
E 11
I 11
D 12
#define	TIMEOUT	000001		/* delay timeout in progress */
#define	WOPEN	000002		/* waiting for open to complete */
#define	ISOPEN	000004		/* device is open */
#define	FLUSH	000010		/* outq has been flushed during DMA */
#define	CARR_ON	000020		/* software copy of carrier-present */
#define	BUSY	000040		/* output in progress */
#define	ASLEEP	000100		/* wakeup when output done */
#define	XCLUDE	000200		/* exclusive-use flag against open */
#define	TTSTOP	000400		/* output stopped by ctl-s */
#define	HUPCLS	001000		/* hang up upon last close */
#define	TBLOCK	002000		/* tandem queue blocked */
#define	RCOLL	004000		/* collision in read select */
E 12
I 12
D 17
#define	TS_TIMEOUT	000001		/* delay timeout in progress */
#define	TS_WOPEN	000002		/* waiting for open to complete */
#define	TS_ISOPEN	000004		/* device is open */
#define	TS_FLUSH	000010		/* outq has been flushed during DMA */
#define	TS_CARR_ON	000020		/* software copy of carrier-present */
#define	TS_BUSY		000040		/* output in progress */
#define	TS_ASLEEP	000100		/* wakeup when output done */
#define	TS_XCLUDE	000200		/* exclusive-use flag against open */
#define	TS_TTSTOP	000400		/* output stopped by ctl-s */
#define	TS_HUPCLS	001000		/* hang up upon last close */
#define	TS_TBLOCK	002000		/* tandem queue blocked */
#define	TS_RCOLL	004000		/* collision in read select */
#define	TS_WCOLL	010000		/* collision in write select */
#define	TS_NBIO		020000		/* tty in non-blocking mode */
I 16
#define	TS_ASYNC	040000		/* tty in async i/o mode */
E 17
I 17
#define	TS_TIMEOUT	0x000001	/* delay timeout in progress */
#define	TS_WOPEN	0x000002	/* waiting for open to complete */
#define	TS_ISOPEN	0x000004	/* device is open */
#define	TS_FLUSH	0x000008	/* outq has been flushed during DMA */
#define	TS_CARR_ON	0x000010	/* software copy of carrier-present */
#define	TS_BUSY		0x000020	/* output in progress */
#define	TS_ASLEEP	0x000040	/* wakeup when output done */
#define	TS_XCLUDE	0x000080	/* exclusive-use flag against open */
#define	TS_TTSTOP	0x000100	/* output stopped by ctl-s */
#define	TS_HUPCLS	0x000200	/* hang up upon last close */
#define	TS_TBLOCK	0x000400	/* tandem queue blocked */
#define	TS_RCOLL	0x000800	/* collision in read select */
#define	TS_WCOLL	0x001000	/* collision in write select */
#define	TS_NBIO		0x002000	/* tty in non-blocking mode */
#define	TS_ASYNC	0x004000	/* tty in async i/o mode */
I 25
#define	TS_KBHACKS	0x008000	/* doing kb hacks on this tty */
E 25
/* state for intra-line fancy editing work */
#define	TS_BKSL		0x010000	/* state for lowercase \ work */
#define	TS_QUOT		0x020000	/* last character input was \ */
#define	TS_ERASE	0x040000	/* within a \.../ for PRTRUB */
#define	TS_LNCH		0x080000	/* next character is literal */
#define	TS_TYPEN	0x100000	/* retyping suspended input (PENDIN) */
#define	TS_CNTTB	0x200000	/* counting tab width; leave FLUSHO alone */
E 17
E 16
E 12
E 11
E 7
D 24

E 24
I 17
#define	TS_LOCAL	(TS_BKSL|TS_QUOT|TS_ERASE|TS_LNCH|TS_TYPEN|TS_CNTTB)
I 24
/* KOI-related states */
#define	TS_KOI7INRUS	0x00400000	/* KOI-7 input in RUS mode */
#define	TS_OUTKOI7TO8	0x00800000	/* KOI-7 to KOI-8 xlat on output */
#define	TS_OUTKOI8TO7	0x01000000	/* KOI-8 to KOI-7 xlat on output */
I 26
/* Other Quasijarus additions */
#define	TS_MODEMCHG	0x02000000	/* modem status changed */
E 26
E 24

E 17
D 3
/*
 * tty ioctl commands
 */
#define	TIOCGETD	(('t'<<8)|0)
#define	TIOCSETD	(('t'<<8)|1)
#define	TIOCHPCL	(('t'<<8)|2)
#define	TIOCMODG	(('t'<<8)|3)
#define	TIOCMODS	(('t'<<8)|4)
#define	TIOCGETP	(('t'<<8)|8)
#define	TIOCSETP	(('t'<<8)|9)
#define	TIOCSETN	(('t'<<8)|10)
#define	TIOCEXCL	(('t'<<8)|13)
#define	TIOCNXCL	(('t'<<8)|14)
#define	TIOCFLUSH	(('t'<<8)|16)
#define	TIOCSETC	(('t'<<8)|17)
#define	TIOCGETC	(('t'<<8)|18)
#define	TIOCSBRK	(('t'<<8)|19)
#define	DIOCLSTN	(('d'<<8)|1)
#define	DIOCNTRL	(('d'<<8)|2)
#define	DIOCMPX		(('d'<<8)|3)
#define	DIOCNMPX	(('d'<<8)|4)
#define	DIOCSCALL	(('d'<<8)|5)
#define	DIOCRCALL	(('d'<<8)|6)
#define	DIOCPGRP	(('d'<<8)|7)
#define	DIOCGETP	(('d'<<8)|8)
#define	DIOCSETP	(('d'<<8)|9)
#define	DIOCLOSE	(('d'<<8)|10)
#define	DIOCTIME	(('d'<<8)|11)
#define	DIOCRESET	(('d'<<8)|12)
#define	DIOCSMETA	(('d'<<8)|13)
#define	DIOCMERGE	(('d'<<8)|14)
#define	DIOCICHAN	(('d'<<8)|15)
#define	DIOCPAD		(('d'<<8)|16)
#define	DIOCRMETA	(('d'<<8)|17)
#define	DIOCXOUT	(('d'<<8)|18)
#define	DIOCBMETA	(('d'<<8)|19)
#define	DIOCAMETA	(('d'<<8)|20)
#define	DIOCSBMETA	(('d'<<8)|21)
#define	FIOCLEX		(('f'<<8)|1)
#define	FIONCLEX	(('f'<<8)|2)
#define	MXLSTN		(('x'<<8)|1)
#define	MXNBLK		(('x'<<8)|2)
E 3
I 3
/* define partab character types */
#define	ORDINARY	0
#define	CONTROL		1
#define	BACKSPACE	2
#define	NEWLINE		3
#define	TAB		4
#define	VTAB		5
#define	RETURN		6
E 3
I 2
D 17

D 3
/* ##bsb 1/12/80 (from stt) ioctl code for "capacity" call */
/* returns no. of bytes left before EOF or hang in cp_nbytes */
/* returns flag indicating EOF versus hang in cp_eof */

#define	FIOCAPACITY	(('f'<<8)|99)

struct	capacity {
	off_t	cp_nbytes;
	int	cp_eof;
};
E 3
I 3
/* define dmctl actions */
#define	DMSET		0
#define	DMBIS		1
#define	DMBIC		2
I 15
#define	DMGET		3
E 17
E 15
E 3
E 2
E 1
