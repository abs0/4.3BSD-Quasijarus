h05904
s 00001/00002/00330
d D 7.20 08/04/05 08:22:08 msokolov 87 86
c ppp authentication status retrieval rethought
e
s 00010/00001/00322
d D 7.19 08/02/18 04:17:26 msokolov 86 85
c new ioctls for pppaux
e
s 00015/00011/00308
d D 7.18 04/12/09 01:19:07 msokolov 85 84
c document TIOCMOD[GS] as forever unimplemented V7 relics
c move TIOCM_* bit definitions down under TIOCM{SET,BIS,BIC,GET}
e
s 00104/00104/00215
d D 7.17 04/12/08 07:43:38 msokolov 84 83
c ioctl debostication
e
s 00001/00000/00318
d D 7.16 04/02/27 02:02:19 msokolov 83 82
c add LK201DISC
e
s 00012/00000/00306
d D 7.15 03/04/07 00:42:18 msokolov 82 81
c add tty kb hacks ioctls
e
s 00002/00001/00304
d D 7.14 03/03/29 16:26:25 msokolov 81 80
c add KOI mode
e
s 00003/00000/00302
d D 7.13 02/08/02 22:15:09 msokolov 80 79
c start new ioctl class for network supervisory devices
e
s 00001/00000/00301
d D 7.12 02/07/30 23:45:45 msokolov 79 78
c add TIOCSOFTCAR ioctl to force soft carrier on at any time
e
s 00001/00000/00300
d D 7.11 02/07/23 23:55:21 msokolov 78 77
c add SIOCPPPGETIPCPS
e
s 00021/00004/00279
d D 7.10 02/07/22 21:07:24 msokolov 77 76
c add ppp if ioctls
e
s 00002/00002/00281
d D 7.9 02/07/12 15:32:53 msokolov 76 75
c no separate ppp and ppt modules after all, it's all ppp
e
s 00002/00000/00281
d D 7.8 02/07/08 00:03:58 msokolov 75 74
c add SIOCGIFMTU and SIOCSIFMTU
e
s 00006/00000/00275
d D 7.7 02/07/07 18:31:18 msokolov 74 73
c start Quasijarus tty ioctl additions for the improved SLIP implementation and
c upcoming async PPP
e
s 00077/00077/00198
d D 7.6 87/12/18 11:24:36 bostic 73 72
c fix for ANSI C
e
s 00001/00001/00274
d D 7.5 87/11/07 14:46:45 karels 72 70
c yech, how'd we get a dup
e
s 00001/00001/00274
d R 7.5 87/11/07 14:45:18 karels 71 70
c yech, how'd we get a dup
e
s 00002/00002/00273
d D 7.4 87/05/27 16:03:54 mckusick 70 69
c fix comments on FIOCLEX/FIONCLEX from fair@ucbarpa.berkeley.edu (Erik E. Fair)
e
s 00006/00004/00269
d D 7.3 87/02/19 14:16:28 karels 69 68
c larger ioctl's (for disklabels)
e
s 00001/00000/00272
d D 7.2 86/08/09 18:03:09 karels 68 67
c TIOCCONS ala sun
e
s 00001/00001/00271
d D 7.1 86/06/04 23:24:07 mckusick 67 66
c 4.3BSD release version
e
s 00001/00000/00271
d D 6.22 86/05/19 16:30:52 karels 66 65
c add UIOCCMD
e
s 00010/00008/00261
d D 6.21 86/02/20 10:54:37 bloom 65 64
c Someone forgot that ioctl.h didn't require types.h
e
s 00024/00007/00245
d D 6.20 86/02/19 22:38:45 karels 64 63
c pretty up winsize defn; add Sun-compat (for bloom)
e
s 00001/00001/00251
d D 6.19 86/02/17 17:15:47 karels 63 62
c typo
e
s 00001/00000/00251
d D 6.18 86/02/10 08:39:29 karels 62 61
c serial IP disc
e
s 00002/00000/00249
d D 6.17 86/02/08 14:19:37 karels 61 60
c add get/set metric IF ioctls
e
s 00000/00021/00249
d D 6.16 86/01/18 12:19:24 karels 60 59
c rm bbn junk
e
s 00001/00002/00269
d D 6.15 85/11/06 18:20:03 sam 59 58
c delete extraneous line discipline what with ioctl to set type
e
s 00004/00002/00267
d D 6.14 85/08/25 16:18:13 walsh 58 57
c adjusted tcp noactivity timer ioctl
e
s 00020/00000/00249
d D 6.13 85/08/22 09:57:43 walsh 57 56
c added ioctls to adjust bbn net protocol timers...
e
s 00002/00001/00247
d D 6.12 85/08/13 05:23:11 lepreau 56 55
c add PASS8: pass all 8 bits of input
e
s 00001/00000/00247
d D 6.11 85/06/08 15:44:58 sam 55 54
c fix copyright botch of comment
e
s 00007/00001/00240
d D 6.10 85/06/08 14:59:42 mckusick 54 53
c Add copyright
e
s 00001/00001/00240
d D 6.9 85/03/13 16:22:19 mckusick 53 52
c from sun!shannon
e
s 00004/00000/00237
d D 6.8 85/03/07 22:00:12 karels 52 51
c new pty, socket ioctls
e
s 00002/00002/00235
d D 6.7 85/01/24 19:31:00 bloom 51 50
c rename window size structure elements to begin "ws_"
e
s 00010/00000/00227
d D 6.6 85/01/03 08:39:47 bloom 50 48
c added window size support
e
s 00010/00000/00227
d R 6.6 84/12/31 12:44:09 bloom 49 48
c added window size support
e
s 00002/00002/00225
d D 6.5 84/08/28 17:29:08 bloom 48 47
c Change include paths.  No more ../h
e
s 00015/00001/00212
d D 6.4 84/08/02 14:27:13 karels 47 46
c don't get sgtty from /usr/include
e
s 00002/00001/00211
d D 6.3 84/04/13 10:25:32 karels 46 45
c add SIOCGIFBRDADDR
e
s 00004/00000/00208
d D 6.2 84/03/20 15:24:08 karels 45 44
c new ioctls for ARP
e
s 00000/00000/00208
d D 6.1 83/07/29 06:12:46 sam 44 43
c 4.2 distribution
e
s 00001/00010/00207
d D 4.34 83/06/13 02:59:27 sam 43 42
c new stuff goes...
e
s 00011/00009/00206
d D 4.33 83/06/12 19:49:14 sam 42 41
c revamp network ioctls
e
s 00002/00000/00213
d D 4.32 83/05/27 13:58:31 sam 41 40
c these will go away in a moment ...
e
s 00002/00000/00211
d D 4.31 83/05/18 02:41:57 sam 40 39
c sun changes
e
s 00016/00016/00195
d D 4.30 83/03/19 18:12:24 sam 39 38
c must make SIOCGIF stuff _IOWR so interface name is copied in
e
s 00001/00001/00210
d D 4.29 83/03/19 14:51:17 sam 38 37
c SIOCGIFCONF is read + write
e
s 00004/00000/00207
d D 4.28 83/03/19 10:33:30 sam 37 36
c water marks
e
s 00007/00007/00200
d D 4.27 83/03/15 18:16:51 sam 36 35
c socket ioctls
e
s 00000/00006/00207
d D 4.26 82/12/17 12:11:10 sam 35 34
c sun merge
e
s 00053/00036/00160
d D 4.25 82/12/13 17:47:31 sam 34 33
c put back L* for compatibility and add some new ones to get at ttychars
e
s 00077/00045/00119
d D 4.24 82/12/05 21:53:27 sam 33 32
c reorganize for new tty structure; include new files needed
e
s 00001/00000/00163
d D 4.23 82/11/22 17:16:00 sam 32 31
c put back TIOCSTI
e
s 00006/00000/00157
d D 4.22 82/10/31 15:58:42 root 31 30
c add keyboard and mouse ioctls (for sun)
e
s 00072/00057/00085
d D 4.21 82/08/01 19:20:16 sam 30 29
c new ioctl's
e
s 00002/00000/00140
d D 4.20 82/06/26 22:18:16 sam 29 28
c tablet line disciplines from lucas
e
s 00007/00005/00133
d D 4.19 82/03/11 23:44:10 wnj 28 27
c for remote ^S/^Q
e
s 00003/00000/00135
d D 4.18 82/03/03 11:10:43 root 27 26
c new ones for routing
e
s 00001/00000/00134
d D 4.17 82/02/18 13:21:10 wnj 26 25
c TIOCREMOTE
e
s 00017/00000/00117
d D 4.16 82/02/08 22:53:28 root 25 24
c modem control ioctl's for DZ32
e
s 00002/00002/00115
d D 4.15 82/01/24 18:45:40 wnj 24 23
c TIOC{EXCL,NXCL}
e
s 00002/00000/00115
d D 4.14 82/01/19 02:01:01 wnj 23 22
c TIOCSTOP and TIOCSTART
e
s 00006/00000/00109
d D 4.13 82/01/17 21:49:36 wnj 22 21
c add pty packet generation codes
e
s 00005/00000/00104
d D 4.12 82/01/17 01:03:42 wnj 21 20
c out of band on sockets
e
s 00007/00000/00097
d D 4.11 82/01/13 10:51:09 wnj 20 19
c SIOC's and FIO{NBIO,ASYNC}
e
s 00002/00000/00095
d D 4.10 81/12/21 12:01:45 root 19 18
c add SIOCDONE
e
s 00003/00003/00092
d D 4.9 81/10/17 16:14:17 wnj 18 17
c cleanup (mpx removal, old tty removal, beginnings of select)
e
s 00001/00000/00094
d D 4.8 81/08/31 01:12:25 wnj 17 16
c LNOFLSH (for EMACS)
e
s 00015/00014/00079
d D 4.7 81/03/17 18:44:55 wnj 16 15
c add LDECCTQ and fix rkreg names
e
s 00000/00018/00093
d D 4.6 81/02/25 23:29:40 wnj 15 14
c functional version with %b printf, etc
e
s 00000/00037/00111
d D 4.5 81/02/23 20:48:34 wnj 14 13
c delete non-distributed stuff
e
s 00001/00001/00147
d D 4.4 81/02/19 21:40:52 wnj 13 12
c %G%->%E%
e
s 00007/00000/00141
d D 4.3 81/01/26 20:43:04 wnj 12 11
c chaos
e
s 00027/00009/00114
d D 4.2 80/12/17 12:00:50 wnj 11 10
c changes per datakit, etc
e
s 00000/00000/00123
d D 4.1 80/11/09 17:01:07 bill 10 9
c stamp for 4bsd
e
s 00001/00003/00122
d D 3.9 80/09/27 17:54:33 bill 9 8
c locals poof
e
s 00002/00000/00123
d D 3.8 80/09/16 17:26:43 bill 8 7
c add TIOCSTI
e
s 00000/00001/00123
d D 3.7 80/07/18 14:53:42 bill 7 6
c minor
e
s 00001/00000/00123
d D 3.6 80/07/12 14:33:38 bill 6 5
c add OKI stuff
e
s 00001/00000/00122
d D 3.5 80/06/22 12:39:21 bill 5 4
c ???
e
s 00001/00001/00121
d D 3.4 80/06/07 02:58:09 bill 4 3
c %H%->%G%
e
s 00020/00020/00102
d D 3.3 80/06/04 13:26:44 bill 3 2
c reformat
e
s 00002/00002/00120
d D 3.2 80/05/24 19:46:40 bill 2 1
c sys
e
s 00122/00000/00000
d D 3.1 80/05/18 20:05:58 bill 1 0
c date and time created 80/05/18 20:05:58 by bill
e
u
U
f b 
t
T
I 1
D 4
/*	%M%	%I%	%H%	*/
E 4
I 4
D 13
/*	%M%	%I%	%G%	*/
E 13
I 13
D 54
/*	%M%	%I%	%E%	*/
E 54
E 13
E 4
/*
I 54
D 67
 * Copyright (c) 1982 Regents of the University of California.
E 67
I 67
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 67
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

I 55
/*
E 55
E 54
D 33
 * ioctl definitions, and special character and local tty definitions
E 33
I 33
 * Ioctl definitions
E 33
 */
#ifndef	_IOCTL_
#define	_IOCTL_
I 33
#ifdef KERNEL
D 48
#include "../h/ttychars.h"
#include "../h/ttydev.h"
E 48
I 48
#include "ttychars.h"
#include "ttydev.h"
E 48
#else
#include <sys/ttychars.h>
#include <sys/ttydev.h>
#endif

D 43
#ifndef NOCOMPAT
E 43
D 47
#include <sgtty.h>
E 47
E 33
struct tchars {
	char	t_intrc;	/* interrupt */
	char	t_quitc;	/* quit */
	char	t_startc;	/* start output */
	char	t_stopc;	/* stop output */
	char	t_eofc;		/* end-of-file */
	char	t_brkc;		/* input delimiter (like nl) */
};
struct ltchars {
	char	t_suspc;	/* stop process signal */
D 2
	char	t_dstopc;	/* delayed stop process signal */
E 2
I 2
	char	t_dsuspc;	/* delayed stop process signal */
E 2
	char	t_rprntc;	/* reprint line */
	char	t_flushc;	/* flush output (toggles) */
	char	t_werasc;	/* word erase */
	char	t_lnextc;	/* literal next character */
D 9
	char	t_lerase;	/* local erase */
	char	t_lkill;	/* local kill */
	char	t_lintr;	/* local interrupt */
E 9
};
I 47

/*
 * Structure for TIOCGETP and TIOCSETP ioctls.
 */

#ifndef _SGTTYB_
#define	_SGTTYB_
struct sgttyb {
	char	sg_ispeed;		/* input speed */
	char	sg_ospeed;		/* output speed */
	char	sg_erase;		/* erase character */
	char	sg_kill;		/* kill character */
	short	sg_flags;		/* mode flags */
};
#endif
E 47
I 33
D 43
#endif
E 43
E 33

I 50
/*
D 64
 * Window size structure
E 64
I 64
 * Window/terminal size structure.
 * This information is stored by the kernel
 * in order to provide a consistent interface,
 * but is not used by the kernel.
I 65
 *
 * Type must be "unsigned short" so that types.h not required.
E 65
E 64
 */
struct winsize {
D 51
	unsigned short	row, col;		/* character size of window */
	unsigned short	xpixel, ypixel;		/* pixel size of window */
E 51
I 51
D 64
	unsigned short	ws_row, ws_col;		/* character size of window */
	unsigned short	ws_xpixel, ws_ypixel;	/* pixel size of window */
E 64
I 64
D 65
	u_short	ws_row;			/* rows, in characters */
	u_short	ws_col;			/* columns, in characters */
	u_short	ws_xpixel;		/* horizontal size, pixels */
	u_short	ws_ypixel;		/* vertical size, pixels */
E 65
I 65
	unsigned short	ws_row;			/* rows, in characters */
	unsigned short	ws_col;			/* columns, in characters */
	unsigned short	ws_xpixel;		/* horizontal size, pixels */
	unsigned short	ws_ypixel;		/* vertical size, pixels */
E 65
E 64
E 51
};

I 64
/*
 * Pun for SUN.
 */
struct ttysize {
D 65
	u_short	ts_lines;
	u_short	ts_cols;
	u_short	ts_xxx;
	u_short	ts_yyy;
E 65
I 65
	unsigned short	ts_lines;
	unsigned short	ts_cols;
	unsigned short	ts_xxx;
	unsigned short	ts_yyy;
E 65
};
#define	TIOCGSIZE	TIOCGWINSZ
#define	TIOCSSIZE	TIOCSWINSZ

E 64
E 50
I 40
#ifndef _IO
E 40
/*
D 33
 * local mode settings
 */
D 16
#define	LCRTBS	01		/* correct backspacing for crt */
D 3
#define LPRTERA 02		/* printing terminal \ ... / erase */
E 3
I 3
#define	LPRTERA 02		/* printing terminal \ ... / erase */
E 3
#define	LCRTERA	04		/* do " \b " to wipe out character */
D 3
#define LTILDE	010		/* IIASA - hazeltine tilde kludge */
#define LMDMBUF	020		/* IIASA - start/stop output on carrier intr */
#define LLITOUT	040		/* IIASA - suppress any output translations */
D 2
#define LTOSTOP	0100		/* send stop for background tty output */
E 2
I 2
#define LTOSTOP	0100		/* send stop for any background tty output */
E 2
#define LFLUSHO	0200		/* flush output sent to terminal */
#define LNOHANG 0400		/* IIASA - don't send hangup on carrier drop */
#define LETXACK 01000		/* IIASA - diablo style buffer hacking */
E 3
I 3
#define	LTILDE	010		/* IIASA - hazeltine tilde kludge */
#define	LMDMBUF	020		/* IIASA - start/stop output on carrier intr */
#define	LLITOUT	040		/* IIASA - suppress any output translations */
#define	LTOSTOP	0100		/* send stop for any background tty output */
#define	LFLUSHO	0200		/* flush output sent to terminal */
#define	LNOHANG 0400		/* IIASA - don't send hangup on carrier drop */
#define	LETXACK 01000		/* IIASA - diablo style buffer hacking */
E 3
#define	LCRTKIL	02000		/* erase whole line on kill with " \b " */
D 3
#define LINTRUP 04000		/* interrupt on every input char - SIGTINT */
E 3
I 3
#define	LINTRUP 04000		/* interrupt on every input char - SIGTINT */
E 3
#define	LCTLECH	010000		/* echo control characters as ^X */
#define	LPENDIN	020000		/* tp->t_rawq is waiting to be reread */
E 16
I 16
#define	LCRTBS	0000001		/* correct backspacing for crt */
#define	LPRTERA 0000002		/* printing terminal \ ... / erase */
#define	LCRTERA	0000004		/* do " \b " to wipe out character */
#define	LTILDE	0000010		/* IIASA - hazeltine tilde kludge */
#define	LMDMBUF	0000020		/* IIASA - start/stop output on carrier intr */
#define	LLITOUT	0000040		/* IIASA - suppress any output translations */
#define	LTOSTOP	0000100		/* send stop for any background tty output */
#define	LFLUSHO	0000200		/* flush output sent to terminal */
#define	LNOHANG 0000400		/* IIASA - don't send hangup on carrier drop */
#define	LETXACK 0001000		/* IIASA - diablo style buffer hacking */
#define	LCRTKIL	0002000		/* erase whole line on kill with " \b " */
D 18
#define	LINTRUP 0004000		/* interrupt on every input char - SIGTINT */
E 18
I 18
#define	L004000	0004000
E 18
#define	LCTLECH	0010000		/* echo control characters as ^X */
#define	LPENDIN	0020000		/* tp->t_rawq is waiting to be reread */
#define	LDECCTQ 0040000		/* only ^Q starts after ^S */
I 17
#define	LNOFLSH 0100000		/* dont flush output on signals */
E 17
E 16

/* local state */
D 3
#define LSBKSL	01		/* state bit for lowercase backslash work */
E 3
I 3
#define	LSBKSL	01		/* state bit for lowercase backslash work */
E 3
#define	LSQUOT	02		/* last character input was \ */
D 3
#define LSERASE	04		/* within a \.../ for LPRTRUB */
E 3
I 3
#define	LSERASE	04		/* within a \.../ for LPRTRUB */
E 3
#define	LSLNCH	010		/* next character is literal */
#define	LSTYPEN	020		/* retyping suspended input (LPENDIN) */
I 8
#define	LSCNTTB	040		/* counting width of tab; leave LFLUSHO alone */
E 8

I 25
/* modem control */
#define	MLE	0001		/* line enable */
#define	MDTR	0002		/* data terminal ready */
#define	MRTS	0004		/* request to send */
#define	MST	0010		/* secondary transmit */
#define	MSR	0020		/* secondary receive */
#define	MCTS	0040		/* clear to send */
#define	MCAR	0100		/* carrier detect */
#define	MCD	MCAR
#define	MRNG	0200		/* ring */
#define	MRI	MRNG
#define	MDSR	0400		/* data set ready */

E 25
/*
E 33
I 30
 * Ioctl's have the command encoded in the lower word,
 * and the size of any in or out parameters in the upper
D 69
 * word.  The high 2 bits of the upper word are used
 * to encode the in/out status of the parameter; for now
 * we restrict parameters to at most 128 bytes.
E 69
I 69
 * word.  The high 3 bits of the upper word are used
 * to encode the in/out status of the parameter.
E 69
 */
D 69
#define	IOCPARM_MASK	0x7f		/* parameters must be < 128 bytes */
E 69
I 69
#define	IOCPARM_MASK	0x1fff		/* parameter length, at most 13 bits */
#define	IOCPARM_LEN(x)	(((x) >> 16) & IOCPARM_MASK)
#define	IOCPARM_MAX	NBPG		/* max size of ioctl, mult. of NBPG */
E 69
#define	IOC_VOID	0x20000000	/* no parameters */
#define	IOC_OUT		0x40000000	/* copy out parameters */
#define	IOC_IN		0x80000000	/* copy in parameters */
#define	IOC_INOUT	(IOC_IN|IOC_OUT)
I 69
#define	IOC_DIRMASK	0xe0000000	/* mask for IN/OUT/VOID */
E 69
/* the 0x20000000 is so we can distinguish new ioctl's from old */
D 73
#define	_IO(x,y)	(IOC_VOID|('x'<<8)|y)
#define	_IOR(x,y,t)	(IOC_OUT|((sizeof(t)&IOCPARM_MASK)<<16)|('x'<<8)|y)
#define	_IOW(x,y,t)	(IOC_IN|((sizeof(t)&IOCPARM_MASK)<<16)|('x'<<8)|y)
E 73
I 73
D 84
#define	_IO(x,y)	(IOC_VOID|(x<<8)|y)
#define	_IOR(x,y,t)	(IOC_OUT|((sizeof(t)&IOCPARM_MASK)<<16)|(x<<8)|y)
#define	_IOW(x,y,t)	(IOC_IN|((sizeof(t)&IOCPARM_MASK)<<16)|(x<<8)|y)
E 84
I 84
#define	_IO(x,y)	(IOC_VOID|('x'<<8)|y)
#define	_IOR(x,y,t)	(IOC_OUT|((sizeof(t)&IOCPARM_MASK)<<16)|('x'<<8)|y)
#define	_IOW(x,y,t)	(IOC_IN|((sizeof(t)&IOCPARM_MASK)<<16)|('x'<<8)|y)
E 84
E 73
/* this should be _IORW, but stdio got there first */
D 73
#define	_IOWR(x,y,t)	(IOC_INOUT|((sizeof(t)&IOCPARM_MASK)<<16)|('x'<<8)|y)
E 73
I 73
D 84
#define	_IOWR(x,y,t)	(IOC_INOUT|((sizeof(t)&IOCPARM_MASK)<<16)|(x<<8)|y)
E 84
I 84
#define	_IOWR(x,y,t)	(IOC_INOUT|((sizeof(t)&IOCPARM_MASK)<<16)|('x'<<8)|y)
E 84
E 73
I 40
#endif
E 40

/*
E 30
 * tty ioctl commands
 */
D 30
#define	TIOCGETD	(('t'<<8)|0)	/* get line discipline */
#define	TIOCSETD	(('t'<<8)|1)	/* set line discipline */
#define	TIOCHPCL	(('t'<<8)|2)	/* set hangup line on close bit */
#define	TIOCMODG	(('t'<<8)|3)	/* modem bits get (???) */
#define	TIOCMODS	(('t'<<8)|4)	/* modem bits set (???) */
#define	TIOCGETP	(('t'<<8)|8)	/* get parameters - like old gtty */
#define	TIOCSETP	(('t'<<8)|9)	/* set parameters - like old stty */
#define	TIOCSETN	(('t'<<8)|10)	/* set params w/o flushing buffers */
D 18
#define	TIOCEXCL	(('t'<<8)|13)	/* set exclusive use of tty */
#define	TIOCNXCL	(('t'<<8)|14)	/* reset exclusive use of tty */
E 18
I 18
D 24
/* 13 was EXCL */
/* 14 was NEXCL */
E 24
I 24
#define	TIOCEXCL	(('t'<<8)|13)	/* set exclusive use of tty */
#define	TIOCNXCL	(('t'<<8)|14)	/* reset exclusive use of tty */
E 24
E 18
#define	TIOCFLUSH	(('t'<<8)|16)	/* flush buffers */
#define	TIOCSETC	(('t'<<8)|17)	/* set special characters */
#define	TIOCGETC	(('t'<<8)|18)	/* get special characters */
I 11
#define	TIOCIOANS	(('t'<<8)|20)
#define	TIOCSIGNAL	(('t'<<8)|21)
#define	TIOCUTTY	(('t'<<8)|22)
E 30
I 30
D 73
#define	TIOCGETD	_IOR(t, 0, int)		/* get line discipline */
#define	TIOCSETD	_IOW(t, 1, int)		/* set line discipline */
#define	TIOCHPCL	_IO(t, 2)		/* hang up on last close */
#define	TIOCMODG	_IOR(t, 3, int)		/* get modem control state */
#define	TIOCMODS	_IOW(t, 4, int)		/* set modem control state */
E 73
I 73
D 84
#define	TIOCGETD	_IOR('t', 0, int)		/* get line discipline */
#define	TIOCSETD	_IOW('t', 1, int)		/* set line discipline */
#define	TIOCHPCL	_IO('t', 2)		/* hang up on last close */
#define	TIOCMODG	_IOR('t', 3, int)		/* get modem control state */
#define	TIOCMODS	_IOW('t', 4, int)		/* set modem control state */
E 84
I 84
#define	TIOCGETD	_IOR(t, 0, int)		/* get line discipline */
#define	TIOCSETD	_IOW(t, 1, int)		/* set line discipline */
#define	TIOCHPCL	_IO(t, 2)		/* hang up on last close */
I 85
/*
 * The following two definitions are from V7, but have never been implemented.
 * BSD has instead adopted the TIOCM{SET,BIS,BIC,GET} ioctls below.
 */
E 85
#define	TIOCMODG	_IOR(t, 3, int)		/* get modem control state */
#define	TIOCMODS	_IOW(t, 4, int)		/* set modem control state */
E 84
E 73
I 33
D 85
#define		TIOCM_LE	0001		/* line enable */
#define		TIOCM_DTR	0002		/* data terminal ready */
#define		TIOCM_RTS	0004		/* request to send */
#define		TIOCM_ST	0010		/* secondary transmit */
#define		TIOCM_SR	0020		/* secondary receive */
#define		TIOCM_CTS	0040		/* clear to send */
#define		TIOCM_CAR	0100		/* carrier detect */
#define		TIOCM_CD	TIOCM_CAR
#define		TIOCM_RNG	0200		/* ring */
#define		TIOCM_RI	TIOCM_RNG
#define		TIOCM_DSR	0400		/* data set ready */
E 85
E 33
D 73
#define	TIOCGETP	_IOR(t, 8,struct sgttyb)/* get parameters -- gtty */
#define	TIOCSETP	_IOW(t, 9,struct sgttyb)/* set parameters -- stty */
#define	TIOCSETN	_IOW(t,10,struct sgttyb)/* as above, but no flushtty */
#define	TIOCEXCL	_IO(t, 13)		/* set exclusive use of tty */
#define	TIOCNXCL	_IO(t, 14)		/* reset exclusive use of tty */
#define	TIOCFLUSH	_IOW(t, 16, int)	/* flush buffers */
#define	TIOCSETC	_IOW(t,17,struct tchars)/* set special characters */
#define	TIOCGETC	_IOR(t,18,struct tchars)/* get special characters */
E 73
I 73
D 84
#define	TIOCGETP	_IOR('t', 8,struct sgttyb)/* get parameters -- gtty */
#define	TIOCSETP	_IOW('t', 9,struct sgttyb)/* set parameters -- stty */
#define	TIOCSETN	_IOW('t',10,struct sgttyb)/* as above, but no flushtty */
#define	TIOCEXCL	_IO('t', 13)		/* set exclusive use of tty */
#define	TIOCNXCL	_IO('t', 14)		/* reset exclusive use of tty */
#define	TIOCFLUSH	_IOW('t', 16, int)	/* flush buffers */
#define	TIOCSETC	_IOW('t',17,struct tchars)/* set special characters */
#define	TIOCGETC	_IOR('t',18,struct tchars)/* get special characters */
E 84
I 84
#define	TIOCGETP	_IOR(t, 8,struct sgttyb)/* get parameters -- gtty */
#define	TIOCSETP	_IOW(t, 9,struct sgttyb)/* set parameters -- stty */
#define	TIOCSETN	_IOW(t,10,struct sgttyb)/* as above, but no flushtty */
#define	TIOCEXCL	_IO(t, 13)		/* set exclusive use of tty */
#define	TIOCNXCL	_IO(t, 14)		/* reset exclusive use of tty */
#define	TIOCFLUSH	_IOW(t, 16, int)	/* flush buffers */
#define	TIOCSETC	_IOW(t,17,struct tchars)/* set special characters */
#define	TIOCGETC	_IOR(t,18,struct tchars)/* get special characters */
E 84
E 73
E 30
E 11
D 34
/* locals, from 127 down */
D 3
#define TIOCLBIS	(('t'<<8)|127)	/* bis local mode bits */
#define TIOCLBIC	(('t'<<8)|126)	/* bic local mode bits */
#define TIOCLSET	(('t'<<8)|125)	/* set entire local mode word */
#define TIOCLGET	(('t'<<8)|124)	/* get local modes */
E 3
I 3
D 30
#define	TIOCLBIS	(('t'<<8)|127)	/* bis local mode bits */
#define	TIOCLBIC	(('t'<<8)|126)	/* bic local mode bits */
#define	TIOCLSET	(('t'<<8)|125)	/* set entire local mode word */
#define	TIOCLGET	(('t'<<8)|124)	/* get local modes */
E 3
#define	TIOCSBRK	(('t'<<8)|123)	/* set break bit */
D 3
#define TIOCCBRK	(('t'<<8)|122)	/* clear break bit */
#define TIOCSDTR	(('t'<<8)|121)	/* set data terminal ready */
#define TIOCCDTR	(('t'<<8)|120)	/* clear data terminal ready */
#define TIOCGPGRP	(('t'<<8)|119)	/* get pgrp of tty */
#define TIOCSPGRP	(('t'<<8)|118)	/* set pgrp of tty */
E 3
I 3
#define	TIOCCBRK	(('t'<<8)|122)	/* clear break bit */
#define	TIOCSDTR	(('t'<<8)|121)	/* set data terminal ready */
#define	TIOCCDTR	(('t'<<8)|120)	/* clear data terminal ready */
#define	TIOCGPGRP	(('t'<<8)|119)	/* get pgrp of tty */
#define	TIOCSPGRP	(('t'<<8)|118)	/* set pgrp of tty */
E 3
#define	TIOCSLTC	(('t'<<8)|117)	/* set local special characters */
#define	TIOCGLTC	(('t'<<8)|116)	/* get local special characters */
I 5
#define	TIOCOUTQ	(('t'<<8)|115)	/* number of chars in output queue */
I 8
#define	TIOCSTI		(('t'<<8)|114)	/* simulate a terminal in character */
I 20
#define	TIOCNOTTY	(('t'<<8)|113)	/* get rid of tty association */
I 22
#define	TIOCPKT		(('t'<<8)|112)	/* on pty: set/clear packet mode */
E 30
I 30
#define	TIOCLBIS	_IOW(t, 127, int)	/* bis local mode bits */
#define	TIOCLBIC	_IOW(t, 126, int)	/* bic local mode bits */
#define	TIOCLSET	_IOW(t, 125, int)	/* set entire local mode word */
#define	TIOCLGET	_IOR(t, 124, int)	/* get local modes */
#define	TIOCSBRK	_IO(t, 123)		/* set break bit */
#define	TIOCCBRK	_IO(t, 122)		/* clear break bit */
#define	TIOCSDTR	_IO(t, 121)		/* set data terminal ready */
#define	TIOCCDTR	_IO(t, 120)		/* clear data terminal ready */
#define	TIOCGPGRP	_IOR(t, 119, int)	/* get pgrp of tty */
#define	TIOCSPGRP	_IOW(t, 118, int)	/* set pgrp of tty */
#define	TIOCSLTC	_IOW(t,117,struct ltchars)/* set local special chars */
#define	TIOCGLTC	_IOR(t,116,struct ltchars)/* get local special chars */
I 32
#define	TIOCSTI		_IOW(t, 114, char)	/* simulate terminal input */
E 32
#define	TIOCNOTTY	_IO(t, 113)		/* void tty association */
#define	TIOCPKT		_IOW(t, 112, int)	/* pty: set/clear packet mode */
E 30
D 28
#define		TIOCPKT_DATA		0	/* data packet */
#define		TIOCPKT_FLUSHREAD	1	/* flush packet */
#define		TIOCPKT_FLUSHWRITE	2	/* flush packet */
#define		TIOCPKT_STOP		4	/* stop output */
#define		TIOCPKT_START		8	/* start output */
E 28
I 28
#define		TIOCPKT_DATA		0x00	/* data packet */
#define		TIOCPKT_FLUSHREAD	0x01	/* flush packet */
#define		TIOCPKT_FLUSHWRITE	0x02	/* flush packet */
#define		TIOCPKT_STOP		0x04	/* stop output */
#define		TIOCPKT_START		0x08	/* start output */
#define		TIOCPKT_NOSTOP		0x10	/* no more ^S, ^Q */
#define		TIOCPKT_DOSTOP		0x20	/* now do ^S ^Q */
E 28
I 23
D 30
#define	TIOCSTOP	(('t'<<8)|111)	/* stop output, like ^S */
#define	TIOCSTART	(('t'<<8)|110)	/* start output, like ^Q */
I 25
#define	TIOCMSET	(('t'<<8)|109)	/* set all modem bits */
#define	TIOCMBIS	(('t'<<8)|108)	/* bis modem bits */
#define	TIOCMBIC	(('t'<<8)|107)	/* bic modem bits */
#define	TIOCMGET	(('t'<<8)|106)	/* get all modem bits */
I 26
#define	TIOCREMOTE	(('t'<<8)|105)	/* remote input editing */
E 30
I 30
#define	TIOCSTOP	_IO(t, 111)		/* stop output, like ^S */
#define	TIOCSTART	_IO(t, 110)		/* start output, like ^Q */
#define	TIOCMSET	_IOW(t, 109, int)	/* set all modem bits */
#define	TIOCMBIS	_IOW(t, 108, int)	/* bis modem bits */
#define	TIOCMBIC	_IOW(t, 107, int)	/* bic modem bits */
#define	TIOCMGET	_IOR(t, 106, int)	/* get all modem bits */
#define	TIOCREMOTE	_IO(t, 105)		/* remote input editing */
I 33
#define	TIOCSET		_IOW(t, 104, long)	/* set tty flags */
#define	TIOCBIS		_IOW(t, 103, long)	/* bis tty flags */
#define	TIOCBIC		_IOW(t, 102, long)	/* bic tty flags */
#define	TIOCGET		_IOR(t, 101, long)	/* get all tty flags */
E 34
I 34
D 43
#define	TIOCSET		_IOW(t, 19, long)	/* set tty flags */
#define	TIOCBIS		_IOW(t, 20, long)	/* bis tty flags */
#define	TIOCBIC		_IOW(t, 21, long)	/* bic tty flags */
#define	TIOCGET		_IOR(t, 22, long)	/* get all tty flags */
E 43
E 34
#define		TANDEM		0x00000001	/* send stopc on out q full */
#define		CBREAK		0x00000002	/* half-cooked mode */
#define		LCASE		0x00000004	/* simulate lower case */
#define		ECHO		0x00000008	/* echo input */
#define		CRMOD		0x00000010	/* map \r to \r\n on output */
#define		RAW		0x00000020	/* no i/o processing */
#define		ODDP		0x00000040	/* get/send odd parity */
#define		EVENP		0x00000080	/* get/send even parity */
#define		ANYP		0x000000c0	/* get any parity/send none */
#define		NLDELAY		0x00000300	/* \n delay */
#define			NL0	0x00000000
#define			NL1	0x00000100	/* tty 37 */
#define			NL2	0x00000200	/* vt05 */
#define			NL3	0x00000300
#define		TBDELAY		0x00000c00	/* horizontal tab delay */
#define			TAB0	0x00000000
#define			TAB1	0x00000400	/* tty 37 */
#define			TAB2	0x00000800
#define		XTABS		0x00000c00	/* expand tabs on output */
#define		CRDELAY		0x00003000	/* \r delay */
#define			CR0	0x00000000
#define			CR1	0x00001000	/* tn 300 */
#define			CR2	0x00002000	/* tty 37 */
#define			CR3	0x00003000	/* concept 100 */
#define		VTDELAY		0x00004000	/* vertical tab delay */
#define			FF0	0x00000000
#define			FF1	0x00004000	/* tty 37 */
#define		BSDELAY		0x00008000	/* \b delay */
#define			BS0	0x00000000
#define			BS1	0x00008000
D 34
/* used to be local mode settings */
E 34
I 34
D 64
#define 	ALLDELAY	(NLDELAY|TBDELAY|CRDELAY|VTDELAY|BSDELAY)
E 64
I 64
#define		ALLDELAY	(NLDELAY|TBDELAY|CRDELAY|VTDELAY|BSDELAY)
E 64
E 34
#define		CRTBS		0x00010000	/* do backspacing for crt */
#define		PRTERA		0x00020000	/* \ ... / erase */
#define		CRTERA		0x00040000	/* " \b " to wipe out char */
#define		TILDE		0x00080000	/* hazeltine tilde kludge */
#define		MDMBUF		0x00100000	/* start/stop output on carrier intr */
#define		LITOUT		0x00200000	/* literal output */
#define		TOSTOP		0x00400000	/* SIGSTOP on background output */
#define		FLUSHO		0x00800000	/* flush output to terminal */
#define		NOHANG		0x01000000	/* no SIGHUP on carrier drop */
D 81
#define		L001000		0x02000000
E 81
I 81
#define		KOI		0x02000000	/* Soviet ASCII */
E 81
#define		CRTKIL		0x04000000	/* kill line with " \b " */
D 56
#define		L004000		0x08000000
E 56
I 56
#define		PASS8		0x08000000
E 56
#define		CTLECH		0x10000000	/* echo control chars as ^X */
#define		PENDIN		0x20000000	/* tp->t_rawq needs reread */
#define		DECCTQ		0x40000000	/* only ^Q starts after ^S */
#define		NOFLSH		0x80000000	/* no output flush on signal */
D 34
#define 	ALLDELAY	(NLDELAY|TBDELAY|CRDELAY|VTDELAY|BSDELAY)
E 34
I 34
D 43
#define	TIOCCSET	_IOW(t,23,struct ttychars)/* set special characters */
#define	TIOCCGET	_IOR(t,24,struct ttychars)/* get special characters */
E 43
/* locals, from 127 down */
D 43
#ifndef NOCOMPAT
E 43
D 73
#define	TIOCLBIS	_IOW(t, 127, int)	/* bis local mode bits */
#define	TIOCLBIC	_IOW(t, 126, int)	/* bic local mode bits */
#define	TIOCLSET	_IOW(t, 125, int)	/* set entire local mode word */
#define	TIOCLGET	_IOR(t, 124, int)	/* get local modes */
E 73
I 73
D 84
#define	TIOCLBIS	_IOW('t', 127, int)	/* bis local mode bits */
#define	TIOCLBIC	_IOW('t', 126, int)	/* bic local mode bits */
#define	TIOCLSET	_IOW('t', 125, int)	/* set entire local mode word */
#define	TIOCLGET	_IOR('t', 124, int)	/* get local modes */
E 84
I 84
#define	TIOCLBIS	_IOW(t, 127, int)	/* bis local mode bits */
#define	TIOCLBIC	_IOW(t, 126, int)	/* bic local mode bits */
#define	TIOCLSET	_IOW(t, 125, int)	/* set entire local mode word */
#define	TIOCLGET	_IOR(t, 124, int)	/* get local modes */
E 84
E 73
#define		LCRTBS		(CRTBS>>16)
#define		LPRTERA		(PRTERA>>16)
#define		LCRTERA		(CRTERA>>16)
#define		LTILDE		(TILDE>>16)
#define		LMDMBUF		(MDMBUF>>16)
#define		LLITOUT		(LITOUT>>16)
#define		LTOSTOP		(TOSTOP>>16)
#define		LFLUSHO		(FLUSHO>>16)
#define		LNOHANG		(NOHANG>>16)
I 81
#define		LKOI		(KOI>>16)
E 81
#define		LCRTKIL		(CRTKIL>>16)
I 56
#define		LPASS8		(PASS8>>16)
E 56
#define		LCTLECH		(CTLECH>>16)
#define		LPENDIN		(PENDIN>>16)
#define		LDECCTQ		(DECCTQ>>16)
#define		LNOFLSH		(NOFLSH>>16)
D 43
#endif
E 43
D 73
#define	TIOCSBRK	_IO(t, 123)		/* set break bit */
#define	TIOCCBRK	_IO(t, 122)		/* clear break bit */
#define	TIOCSDTR	_IO(t, 121)		/* set data terminal ready */
#define	TIOCCDTR	_IO(t, 120)		/* clear data terminal ready */
#define	TIOCGPGRP	_IOR(t, 119, int)	/* get pgrp of tty */
#define	TIOCSPGRP	_IOW(t, 118, int)	/* set pgrp of tty */
#define	TIOCSLTC	_IOW(t,117,struct ltchars)/* set local special chars */
#define	TIOCGLTC	_IOR(t,116,struct ltchars)/* get local special chars */
I 43
#define	TIOCOUTQ	_IOR(t, 115, int)	/* output queue size */
E 43
#define	TIOCSTI		_IOW(t, 114, char)	/* simulate terminal input */
#define	TIOCNOTTY	_IO(t, 113)		/* void tty association */
#define	TIOCPKT		_IOW(t, 112, int)	/* pty: set/clear packet mode */
E 73
I 73
D 84
#define	TIOCSBRK	_IO('t', 123)		/* set break bit */
#define	TIOCCBRK	_IO('t', 122)		/* clear break bit */
#define	TIOCSDTR	_IO('t', 121)		/* set data terminal ready */
#define	TIOCCDTR	_IO('t', 120)		/* clear data terminal ready */
#define	TIOCGPGRP	_IOR('t', 119, int)	/* get pgrp of tty */
#define	TIOCSPGRP	_IOW('t', 118, int)	/* set pgrp of tty */
#define	TIOCSLTC	_IOW('t',117,struct ltchars)/* set local special chars */
#define	TIOCGLTC	_IOR('t',116,struct ltchars)/* get local special chars */
#define	TIOCOUTQ	_IOR('t', 115, int)	/* output queue size */
#define	TIOCSTI		_IOW('t', 114, char)	/* simulate terminal input */
#define	TIOCNOTTY	_IO('t', 113)		/* void tty association */
#define	TIOCPKT		_IOW('t', 112, int)	/* pty: set/clear packet mode */
E 84
I 84
#define	TIOCSBRK	_IO(t, 123)		/* set break bit */
#define	TIOCCBRK	_IO(t, 122)		/* clear break bit */
#define	TIOCSDTR	_IO(t, 121)		/* set data terminal ready */
#define	TIOCCDTR	_IO(t, 120)		/* clear data terminal ready */
#define	TIOCGPGRP	_IOR(t, 119, int)	/* get pgrp of tty */
#define	TIOCSPGRP	_IOW(t, 118, int)	/* set pgrp of tty */
#define	TIOCSLTC	_IOW(t,117,struct ltchars)/* set local special chars */
#define	TIOCGLTC	_IOR(t,116,struct ltchars)/* get local special chars */
#define	TIOCOUTQ	_IOR(t, 115, int)	/* output queue size */
#define	TIOCSTI		_IOW(t, 114, char)	/* simulate terminal input */
#define	TIOCNOTTY	_IO(t, 113)		/* void tty association */
#define	TIOCPKT		_IOW(t, 112, int)	/* pty: set/clear packet mode */
E 84
E 73
#define		TIOCPKT_DATA		0x00	/* data packet */
#define		TIOCPKT_FLUSHREAD	0x01	/* flush packet */
#define		TIOCPKT_FLUSHWRITE	0x02	/* flush packet */
#define		TIOCPKT_STOP		0x04	/* stop output */
#define		TIOCPKT_START		0x08	/* start output */
#define		TIOCPKT_NOSTOP		0x10	/* no more ^S, ^Q */
#define		TIOCPKT_DOSTOP		0x20	/* now do ^S ^Q */
D 73
#define	TIOCSTOP	_IO(t, 111)		/* stop output, like ^S */
#define	TIOCSTART	_IO(t, 110)		/* start output, like ^Q */
#define	TIOCMSET	_IOW(t, 109, int)	/* set all modem bits */
#define	TIOCMBIS	_IOW(t, 108, int)	/* bis modem bits */
#define	TIOCMBIC	_IOW(t, 107, int)	/* bic modem bits */
#define	TIOCMGET	_IOR(t, 106, int)	/* get all modem bits */
D 53
#define	TIOCREMOTE	_IO(t, 105)		/* remote input editing */
E 53
I 53
#define	TIOCREMOTE	_IOW(t, 105, int)	/* remote input editing */
E 53
I 50
D 64
#define TIOCGWINSZ	_IOR(t, 104, struct winsize)	/* get window size */
#define TIOCSWINSZ	_IOW(t, 103, struct winsize)	/* set window size */
I 52
#define TIOCUCNTL	_IOW(t, 102, int)	/* pty: set/clr usr cntl mode */
E 64
I 64
#define	TIOCGWINSZ	_IOR(t, 104, struct winsize)	/* get window size */
#define	TIOCSWINSZ	_IOW(t, 103, struct winsize)	/* set window size */
#define	TIOCUCNTL	_IOW(t, 102, int)	/* pty: set/clr usr cntl mode */
I 66
#define		UIOCCMD(n)	_IO(u, n)		/* usr cntl op "n" */
I 68
D 72
#define	TIOCCONS	_IO(t, 102)		/* become virtual console */
E 72
I 72
#define	TIOCCONS	_IO(t, 98)		/* become virtual console */
E 73
I 73
D 84
#define	TIOCSTOP	_IO('t', 111)		/* stop output, like ^S */
#define	TIOCSTART	_IO('t', 110)		/* start output, like ^Q */
#define	TIOCMSET	_IOW('t', 109, int)	/* set all modem bits */
#define	TIOCMBIS	_IOW('t', 108, int)	/* bis modem bits */
#define	TIOCMBIC	_IOW('t', 107, int)	/* bic modem bits */
#define	TIOCMGET	_IOR('t', 106, int)	/* get all modem bits */
#define	TIOCREMOTE	_IOW('t', 105, int)	/* remote input editing */
#define	TIOCGWINSZ	_IOR('t', 104, struct winsize)	/* get window size */
#define	TIOCSWINSZ	_IOW('t', 103, struct winsize)	/* set window size */
#define	TIOCUCNTL	_IOW('t', 102, int)	/* pty: set/clr usr cntl mode */
#define		UIOCCMD(n)	_IO('u', n)		/* usr cntl op "n" */
#define	TIOCCONS	_IO('t', 98)		/* become virtual console */
E 84
I 84
#define	TIOCSTOP	_IO(t, 111)		/* stop output, like ^S */
#define	TIOCSTART	_IO(t, 110)		/* start output, like ^Q */
#define	TIOCMSET	_IOW(t, 109, int)	/* set all modem bits */
#define	TIOCMBIS	_IOW(t, 108, int)	/* bis modem bits */
#define	TIOCMBIC	_IOW(t, 107, int)	/* bic modem bits */
#define	TIOCMGET	_IOR(t, 106, int)	/* get all modem bits */
I 85
#define		TIOCM_LE	0001		/* line enable */
#define		TIOCM_DTR	0002		/* data terminal ready */
#define		TIOCM_RTS	0004		/* request to send */
#define		TIOCM_ST	0010		/* secondary transmit */
#define		TIOCM_SR	0020		/* secondary receive */
#define		TIOCM_CTS	0040		/* clear to send */
#define		TIOCM_CAR	0100		/* carrier detect */
#define		TIOCM_CD	TIOCM_CAR
#define		TIOCM_RNG	0200		/* ring */
#define		TIOCM_RI	TIOCM_RNG
#define		TIOCM_DSR	0400		/* data set ready */
E 85
#define	TIOCREMOTE	_IOW(t, 105, int)	/* remote input editing */
#define	TIOCGWINSZ	_IOR(t, 104, struct winsize)	/* get window size */
#define	TIOCSWINSZ	_IOW(t, 103, struct winsize)	/* set window size */
#define	TIOCUCNTL	_IOW(t, 102, int)	/* pty: set/clr usr cntl mode */
#define		UIOCCMD(n)	_IO(u, n)		/* usr cntl op "n" */
#define	TIOCCONS	_IO(t, 98)		/* become virtual console */
E 84
E 73
E 72
E 68
E 66
E 64
E 52
E 50
E 34
E 33
E 30
E 26
E 25
E 23
E 22
E 20
E 8
E 5

I 74
/* Quasijarus additions */
D 84
#define	TIOCSLATTACH	_IOW('t', 90, int)	/* attach sl<n>, set SLIPDISC */
D 76
#define	TIOCPPTATTACH	_IOW('t', 91, int)	/* attach ppt<n>, set PPPDISC */
#define	TIOCGETIF	_IOR('t', 92, int)	/* get sl/ppt if number */
E 76
I 76
#define	TIOCPPPATTACH	_IOW('t', 91, int)	/* attach ppp<n>, set PPPDISC */
#define	TIOCGETIF	_IOR('t', 92, int)	/* get sl/ppp if number */
I 79
#define	TIOCSOFTCAR	_IO('t',  93)		/* force soft carrier on */
E 84
I 84
#define	TIOCSLATTACH	_IOW(t, 90, int)	/* attach sl<n>, set SLIPDISC */
#define	TIOCPPPATTACH	_IOW(t, 91, int)	/* attach ppp<n>, set PPPDISC */
#define	TIOCGETIF	_IOR(t, 92, int)	/* get sl/ppp if number */
#define	TIOCSOFTCAR	_IO(t,  93)		/* force soft carrier on */
E 84
E 79
E 76

I 82
/* tty kb hacks */
D 84
#define	TIOCKBHACKS	_IOW('t', 70, int)	/* en/dis tty kb hacks */
#define	TIOCKBSFSTYLE	_IOW('t', 71, int)	/* set func key style */
#define	TIOCKBGFSTYLE	_IOR('t', 72, int)	/* get func key style */
#define	TIOCKBSF11MOD	_IOW('t', 73, int)	/* set F11=>ESC mode on/off */
#define	TIOCKBGF11MOD	_IOR('t', 74, int)	/* get F11=>ESC mode on/off */
#define	TIOCKBSFKEYS	_IOW('t', 75, char[3])	/* set RUS/LAT/META keys */
#define	TIOCKBGFKEYS	_IOR('t', 76, char[3])	/* get RUS/LAT/META keys */
#define	TIOCKBSRUSMAP	_IOW('t', 77, char[94])	/* set RUS map */
#define	TIOCKBGRUSMAP	_IOR('t', 78, char[94])	/* get RUS map */
#define	TIOCKBRESET	_IO('t', 79)		/* clear RUS/META modes */
E 84
I 84
#define	TIOCKBHACKS	_IOW(t, 70, int)	/* en/dis tty kb hacks */
#define	TIOCKBSFSTYLE	_IOW(t, 71, int)	/* set func key style */
#define	TIOCKBGFSTYLE	_IOR(t, 72, int)	/* get func key style */
#define	TIOCKBSF11MOD	_IOW(t, 73, int)	/* set F11=>ESC mode on/off */
#define	TIOCKBGF11MOD	_IOR(t, 74, int)	/* get F11=>ESC mode on/off */
#define	TIOCKBSFKEYS	_IOW(t, 75, char[3])	/* set RUS/LAT/META keys */
#define	TIOCKBGFKEYS	_IOR(t, 76, char[3])	/* get RUS/LAT/META keys */
#define	TIOCKBSRUSMAP	_IOW(t, 77, char[94])	/* set RUS map */
#define	TIOCKBGRUSMAP	_IOR(t, 78, char[94])	/* get RUS map */
#define	TIOCKBRESET	_IO(t, 79)		/* clear RUS/META modes */
E 84

E 82
E 74
I 9
D 11
#define	OTTYDISC	0
E 11
I 11
#define	OTTYDISC	0		/* old, v7 std tty driver */
E 11
E 9
#define	NETLDISC	1		/* line discip for berk net */
D 11
#define	NTTYDISC	2
E 11
I 11
#define	NTTYDISC	2		/* new tty discipline */
I 29
D 59
#define	TABLDISC	3		/* hitachi tablet discipline */
#define	NTABLDISC	4		/* gtco tablet discipline */
E 59
I 59
#define	TABLDISC	3		/* tablet discipline */
I 62
D 63
#define	SLIPLDISC	4		/* serial IP discipline */
E 63
I 63
#define	SLIPDISC	4		/* serial IP discipline */
I 74
#define	PPPDISC		5		/* async PPP discipline */
I 83
#define	LK201DISC	6		/* LK201 keyboard discipline */
E 83
E 74
E 63
E 62
E 59
E 29
D 14
#define	PKDISC		3		/* packet driver */
#define	TRDISC		4		/* datakit trailer protocol */
#define	TDKDISC		5		/* datakit terminal protocol */
E 14
E 11
I 6
D 7
#define	OKILDISC	3
E 7
E 6

D 14
#define	DIOCLSTN	(('d'<<8)|1)
D 11
#define	DIOCNTRL	(('d'<<8)|2)
E 11
I 11
#define	DIOCMD		(('d'<<8)|2)
E 11
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
D 11
#define	DIOCPAD		(('d'<<8)|16)
E 11
I 11
#define	DIOCUMERGE	(('d'<<8)|16)
E 11
#define	DIOCRMETA	(('d'<<8)|17)
#define	DIOCXOUT	(('d'<<8)|18)
#define	DIOCBMETA	(('d'<<8)|19)
#define	DIOCAMETA	(('d'<<8)|20)
#define	DIOCSBMETA	(('d'<<8)|21)
I 11
#define	DIOCLOOP	(('d'<<8)|22)
#define	DIOCPROTOCOL	(('d'<<8)|23)
#define	DIOCTRL		(('d'<<8)|24)
#define	DIOCDMETA	(('d'<<8)|25)
#define	DIOCSWR		(('d'<<8)|26)
E 11

E 14
D 30
#define	FIOCLEX		(('f'<<8)|1)
#define	FIONCLEX	(('f'<<8)|2)
E 30
I 30
D 70
#define	FIOCLEX		_IO(f, 1)		/* set exclusive use on fd */
#define	FIONCLEX	_IO(f, 2)		/* remove exclusive use */
E 70
I 70
D 73
#define	FIOCLEX		_IO(f, 1)		/* set close on exec on fd */
#define	FIONCLEX	_IO(f, 2)		/* remove close on exec */
E 73
I 73
D 84
#define	FIOCLEX		_IO('f', 1)		/* set close on exec on fd */
#define	FIONCLEX	_IO('f', 2)		/* remove close on exec */
E 84
I 84
#define	FIOCLEX		_IO(f, 1)		/* set close on exec on fd */
#define	FIONCLEX	_IO(f, 2)		/* remove close on exec */
E 84
E 73
E 70
E 30
/* another local */
D 30
#define	FIONREAD	(('f'<<8)|127)	/* get # bytes to read */
I 20
#define	FIONBIO		(('f'<<8)|126)
#define	FIOASYNC	(('f'<<8)|125)
E 30
I 30
D 73
#define	FIONREAD	_IOR(f, 127, int)	/* get # bytes to read */
#define	FIONBIO		_IOW(f, 126, int)	/* set/clear non-blocking i/o */
#define	FIOASYNC	_IOW(f, 125, int)	/* set/clear async i/o */
I 41
#define	FIOSETOWN	_IOW(f, 124, int)	/* set owner */
#define	FIOGETOWN	_IOR(f, 123, int)	/* get owner */
E 73
I 73
D 84
#define	FIONREAD	_IOR('f', 127, int)	/* get # bytes to read */
#define	FIONBIO		_IOW('f', 126, int)	/* set/clear non-blocking i/o */
#define	FIOASYNC	_IOW('f', 125, int)	/* set/clear async i/o */
#define	FIOSETOWN	_IOW('f', 124, int)	/* set owner */
#define	FIOGETOWN	_IOR('f', 123, int)	/* get owner */
E 84
I 84
#define	FIONREAD	_IOR(f, 127, int)	/* get # bytes to read */
#define	FIONBIO		_IOW(f, 126, int)	/* set/clear non-blocking i/o */
#define	FIOASYNC	_IOW(f, 125, int)	/* set/clear async i/o */
#define	FIOSETOWN	_IOW(f, 124, int)	/* set owner */
#define	FIOGETOWN	_IOR(f, 123, int)	/* get owner */
E 84
E 73
E 41
E 30
E 20
I 19

D 30
#define	SIOCDONE	(('s'<<8)|0)	/* shutdown read/write on socket */
I 20
#define	SIOCSKEEP	(('s'<<8)|1)	/* set keep alive */
#define	SIOCGKEEP	(('s'<<8)|2)	/* inspect keep alive */
#define	SIOCSLINGER	(('s'<<8)|3)	/* set linger time */
#define	SIOCGLINGER	(('s'<<8)|4)	/* get linger time */
I 21
#define	SIOCSENDOOB	(('s'<<8)|5)	/* send out of band */
#define	SIOCRCVOOB	(('s'<<8)|6)	/* get out of band */
#define	SIOCATMARK	(('s'<<8)|7)	/* at out of band mark? */
#define	SIOCSPGRP	(('s'<<8)|8)	/* set process group */
#define	SIOCGPGRP	(('s'<<8)|9)	/* get process group */
I 27
#define	SIOCADDRT	(('s'<<8)|10)	/* add a routing table entry */
#define	SIOCDELRT	(('s'<<8)|11)	/* delete a routing table entry */
#define	SIOCCHGRT	(('s'<<8)|12)	/* change a routing table entry */
E 30
I 30
/* socket i/o controls */
I 37
D 39
#define	SIOCSHIWAT	_IOW(s, 0, int)		/* set high water mark */
#define	SIOCGHIWAT	_IOR(s, 1, int)		/* get high water mark */
#define	SIOCSLOWAT	_IOW(s, 2, int)		/* set low water mark */
#define	SIOCGLOWAT	_IOR(s, 3, int)		/* get low water mark */
E 37
D 36
#define	SIOCDONE	_IOW(s, 0, int)		/* shutdown read/write */
#define	SIOCSKEEP	_IOW(s, 1, int)		/* set keep alive */
#define	SIOCGKEEP	_IOR(s, 2, int)		/* inspect keep alive */
#define	SIOCSLINGER	_IOW(s, 3, int)		/* set linger time */
#define	SIOCGLINGER	_IOR(s, 4, int)		/* get linger time */
D 33
/* these are really variable length */
#define	SIOCSENDOOB	_IOW(s, 5, char)	/* send out of band */
#define	SIOCRCVOOB	_IOR(s, 6, char)	/* get out of band */
E 33
I 33
#define	SIOCSENDOOB	_IOW(s, 5, char)	/* send oob data */
#define	SIOCRCVOOB	_IOR(s, 6, char)	/* recv oob data */
E 36
E 33
#define	SIOCATMARK	_IOR(s, 7, int)		/* at out of band mark? */
#define	SIOCSPGRP	_IOW(s, 8, int)		/* set process group */
#define	SIOCGPGRP	_IOR(s, 9, int)		/* get process group */
#define	SIOCADDRT	_IOW(s,10, struct rtentry)/* add route */
#define	SIOCDELRT	_IOW(s,11, struct rtentry)/* delete route */
I 36
#define	SIOCSIFADDR	_IOW(s,12, struct ifreq)/* set interface address */
#define	SIOCGIFADDR	_IOR(s,13, struct ifreq)/* get interface address */
#define	SIOCSIFDSTADDR	_IOW(s,14, struct ifreq)/* set point-point address */
#define	SIOCGIFDSTADDR	_IOR(s,15, struct ifreq)/* get point-point address */
#define	SIOCSIFFLAGS	_IOW(s,16, struct ifreq)/* set interface flags */
#define	SIOCGIFFLAGS	_IOR(s,17, struct ifreq)/* get interface flags */
D 38
#define	SIOCGIFCONF	_IOR(s,20, struct ifconf)/* get interface list */
E 38
I 38
#define	SIOCGIFCONF	_IOWR(s,20,struct ifconf)/* get interface list */
E 39
I 39
D 73
#define	SIOCSHIWAT	_IOW(s,  0, int)		/* set high watermark */
#define	SIOCGHIWAT	_IOR(s,  1, int)		/* get high watermark */
#define	SIOCSLOWAT	_IOW(s,  2, int)		/* set low watermark */
#define	SIOCGLOWAT	_IOR(s,  3, int)		/* get low watermark */
#define	SIOCATMARK	_IOR(s,  7, int)		/* at oob mark? */
#define	SIOCSPGRP	_IOW(s,  8, int)		/* set process group */
#define	SIOCGPGRP	_IOR(s,  9, int)		/* get process group */
E 73
I 73
D 84
#define	SIOCSHIWAT	_IOW('s',  0, int)		/* set high watermark */
#define	SIOCGHIWAT	_IOR('s',  1, int)		/* get high watermark */
#define	SIOCSLOWAT	_IOW('s',  2, int)		/* set low watermark */
#define	SIOCGLOWAT	_IOR('s',  3, int)		/* get low watermark */
#define	SIOCATMARK	_IOR('s',  7, int)		/* at oob mark? */
#define	SIOCSPGRP	_IOW('s',  8, int)		/* set process group */
#define	SIOCGPGRP	_IOR('s',  9, int)		/* get process group */
E 84
I 84
#define	SIOCSHIWAT	_IOW(s,  0, int)		/* set high watermark */
#define	SIOCGHIWAT	_IOR(s,  1, int)		/* get high watermark */
#define	SIOCSLOWAT	_IOW(s,  2, int)		/* set low watermark */
#define	SIOCGLOWAT	_IOR(s,  3, int)		/* get low watermark */
#define	SIOCATMARK	_IOR(s,  7, int)		/* at oob mark? */
#define	SIOCSPGRP	_IOW(s,  8, int)		/* set process group */
#define	SIOCGPGRP	_IOR(s,  9, int)		/* get process group */
E 84
E 73
D 42
#define	SIOCADDRT	_IOW(s, 10, struct rtentry)	/* add route */
#define	SIOCDELRT	_IOW(s, 11, struct rtentry)	/* delete route */
#define	SIOCSIFADDR	_IOW(s, 12, struct ifreq)	/* set ifnet address */
#define	SIOCGIFADDR	_IOWR(s,13, struct ifreq)	/* get ifnet address */
#define	SIOCSIFDSTADDR	_IOW(s, 14, struct ifreq)	/* set p-p address */
#define	SIOCGIFDSTADDR	_IOWR(s,15, struct ifreq)	/* get p-p address */
#define	SIOCSIFFLAGS	_IOW(s, 16, struct ifreq)	/* set ifnet flags */
#define	SIOCGIFFLAGS	_IOWR(s,17, struct ifreq)	/* get ifnet flags */
#define	SIOCGIFCONF	_IOWR(s,20, struct ifconf)	/* get ifnet list */
E 42
I 42

D 73
#define	SIOCADDRT	_IOW(r, 10, struct rtentry)	/* add route */
#define	SIOCDELRT	_IOW(r, 11, struct rtentry)	/* delete route */
E 73
I 73
D 84
#define	SIOCADDRT	_IOW('r', 10, struct rtentry)	/* add route */
#define	SIOCDELRT	_IOW('r', 11, struct rtentry)	/* delete route */
E 84
I 84
#define	SIOCADDRT	_IOW(r, 10, struct rtentry)	/* add route */
#define	SIOCDELRT	_IOW(r, 11, struct rtentry)	/* delete route */
E 84
E 73

D 73
#define	SIOCSIFADDR	_IOW(i, 12, struct ifreq)	/* set ifnet address */
#define	SIOCGIFADDR	_IOWR(i,13, struct ifreq)	/* get ifnet address */
#define	SIOCSIFDSTADDR	_IOW(i, 14, struct ifreq)	/* set p-p address */
#define	SIOCGIFDSTADDR	_IOWR(i,15, struct ifreq)	/* get p-p address */
#define	SIOCSIFFLAGS	_IOW(i, 16, struct ifreq)	/* set ifnet flags */
#define	SIOCGIFFLAGS	_IOWR(i,17, struct ifreq)	/* get ifnet flags */
I 46
#define	SIOCGIFBRDADDR	_IOWR(i,18, struct ifreq)	/* get broadcast addr */
I 52
#define	SIOCSIFBRDADDR	_IOW(i,19, struct ifreq)	/* set broadcast addr */
E 52
E 46
#define	SIOCGIFCONF	_IOWR(i,20, struct ifconf)	/* get ifnet list */
I 52
#define	SIOCGIFNETMASK	_IOWR(i,21, struct ifreq)	/* get net addr mask */
#define	SIOCSIFNETMASK	_IOW(i,22, struct ifreq)	/* set net addr mask */
I 61
#define	SIOCGIFMETRIC	_IOWR(i,23, struct ifreq)	/* get IF metric */
#define	SIOCSIFMETRIC	_IOW(i,24, struct ifreq)	/* set IF metric */
E 73
I 73
D 84
#define	SIOCSIFADDR	_IOW('i', 12, struct ifreq)	/* set ifnet address */
#define	SIOCGIFADDR	_IOWR('i',13, struct ifreq)	/* get ifnet address */
#define	SIOCSIFDSTADDR	_IOW('i', 14, struct ifreq)	/* set p-p address */
#define	SIOCGIFDSTADDR	_IOWR('i',15, struct ifreq)	/* get p-p address */
#define	SIOCSIFFLAGS	_IOW('i', 16, struct ifreq)	/* set ifnet flags */
#define	SIOCGIFFLAGS	_IOWR('i',17, struct ifreq)	/* get ifnet flags */
#define	SIOCGIFBRDADDR	_IOWR('i',18, struct ifreq)	/* get broadcast addr */
D 77
#define	SIOCSIFBRDADDR	_IOW('i',19, struct ifreq)	/* set broadcast addr */
E 77
I 77
#define	SIOCSIFBRDADDR	_IOW('i', 19, struct ifreq)	/* set broadcast addr */
E 77
#define	SIOCGIFCONF	_IOWR('i',20, struct ifconf)	/* get ifnet list */
#define	SIOCGIFNETMASK	_IOWR('i',21, struct ifreq)	/* get net addr mask */
D 77
#define	SIOCSIFNETMASK	_IOW('i',22, struct ifreq)	/* set net addr mask */
E 77
I 77
#define	SIOCSIFNETMASK	_IOW('i', 22, struct ifreq)	/* set net addr mask */
E 77
#define	SIOCGIFMETRIC	_IOWR('i',23, struct ifreq)	/* get IF metric */
D 77
#define	SIOCSIFMETRIC	_IOW('i',24, struct ifreq)	/* set IF metric */
E 77
I 77
#define	SIOCSIFMETRIC	_IOW('i', 24, struct ifreq)	/* set IF metric */
E 77
I 75
#define	SIOCGIFMTU	_IOWR('i',25, struct ifreq)	/* get IF MTU */
D 77
#define	SIOCSIFMTU	_IOW('i',26, struct ifreq)	/* set IF MTU */
E 77
I 77
#define	SIOCSIFMTU	_IOW('i', 26, struct ifreq)	/* set IF MTU */
E 84
I 84
#define	SIOCSIFADDR	_IOW(i, 12, struct ifreq)	/* set ifnet address */
#define	SIOCGIFADDR	_IOWR(i,13, struct ifreq)	/* get ifnet address */
#define	SIOCSIFDSTADDR	_IOW(i, 14, struct ifreq)	/* set p-p address */
#define	SIOCGIFDSTADDR	_IOWR(i,15, struct ifreq)	/* get p-p address */
#define	SIOCSIFFLAGS	_IOW(i, 16, struct ifreq)	/* set ifnet flags */
#define	SIOCGIFFLAGS	_IOWR(i,17, struct ifreq)	/* get ifnet flags */
#define	SIOCGIFBRDADDR	_IOWR(i,18, struct ifreq)	/* get broadcast addr */
#define	SIOCSIFBRDADDR	_IOW(i, 19, struct ifreq)	/* set broadcast addr */
#define	SIOCGIFCONF	_IOWR(i,20, struct ifconf)	/* get ifnet list */
#define	SIOCGIFNETMASK	_IOWR(i,21, struct ifreq)	/* get net addr mask */
#define	SIOCSIFNETMASK	_IOW(i, 22, struct ifreq)	/* set net addr mask */
#define	SIOCGIFMETRIC	_IOWR(i,23, struct ifreq)	/* get IF metric */
#define	SIOCSIFMETRIC	_IOW(i, 24, struct ifreq)	/* set IF metric */
#define	SIOCGIFMTU	_IOWR(i,25, struct ifreq)	/* get IF MTU */
#define	SIOCSIFMTU	_IOW(i, 26, struct ifreq)	/* set IF MTU */
E 84
E 77
E 75
E 73
E 61
E 52
I 45

D 73
#define	SIOCSARP	_IOW(i, 30, struct arpreq)	/* set arp entry */
D 46
#define	SIOCGARP	_IOWR(i, 31, struct arpreq)	/* get arp entry */
E 46
I 46
#define	SIOCGARP	_IOWR(i,31, struct arpreq)	/* get arp entry */
E 46
#define	SIOCDARP	_IOW(i, 32, struct arpreq)	/* delete arp entry */
E 73
I 73
D 84
#define	SIOCSARP	_IOW('i', 30, struct arpreq)	/* set arp entry */
#define	SIOCGARP	_IOWR('i',31, struct arpreq)	/* get arp entry */
#define	SIOCDARP	_IOW('i', 32, struct arpreq)	/* delete arp entry */
E 84
I 84
#define	SIOCSARP	_IOW(i, 30, struct arpreq)	/* set arp entry */
#define	SIOCGARP	_IOWR(i,31, struct arpreq)	/* get arp entry */
#define	SIOCDARP	_IOW(i, 32, struct arpreq)	/* delete arp entry */
E 84
I 77

/* Quasijarus additions for ppp */
D 84
#define	SIOCPPPGETSTATE	_IOWR('i',40, struct ifreq)	/* get ppp if state */
#define	SIOCPPPGETFLAGS	_IOWR('i',41, struct ifreq)	/* get ppp if flags */
#define	SIOCPPPGRESTIM	_IOWR('i',42, struct ifreq)	/* get Restart Timer */
#define	SIOCPPPSRESTIM	_IOW('i', 43, struct ifreq)	/* set Rsstart timer */
#define	SIOCPPPGMAXCONF	_IOWR('i',44, struct ifreq)	/* get Max-Configure */
#define	SIOCPPPSMAXCONF	_IOW('i', 45, struct ifreq)	/* set Max-Configure */
#define	SIOCPPPGMAXTERM	_IOWR('i',46, struct ifreq)	/* get Max-Terminate */
#define	SIOCPPPSMAXTERM	_IOW('i', 47, struct ifreq)	/* set Max-Terminate */
#define	SIOCPPPSPECACT	_IOW('i', 48, struct ifreq)	/* ppp special action */
I 78
#define	SIOCPPPGETIPCPS	_IOWR('i',49, struct ifreq)	/* get IPCP state */
E 84
I 84
#define	SIOCPPPGETSTATE	_IOWR(i,40, struct ifreq)	/* get ppp if state */
#define	SIOCPPPGETFLAGS	_IOWR(i,41, struct ifreq)	/* get ppp if flags */
#define	SIOCPPPGRESTIM	_IOWR(i,42, struct ifreq)	/* get Restart Timer */
D 86
#define	SIOCPPPSRESTIM	_IOW(i, 43, struct ifreq)	/* set Rsstart timer */
E 86
I 86
#define	SIOCPPPSRESTIM	_IOW(i, 43, struct ifreq)	/* set Restart Timer */
E 86
#define	SIOCPPPGMAXCONF	_IOWR(i,44, struct ifreq)	/* get Max-Configure */
#define	SIOCPPPSMAXCONF	_IOW(i, 45, struct ifreq)	/* set Max-Configure */
#define	SIOCPPPGMAXTERM	_IOWR(i,46, struct ifreq)	/* get Max-Terminate */
#define	SIOCPPPSMAXTERM	_IOW(i, 47, struct ifreq)	/* set Max-Terminate */
#define	SIOCPPPSPECACT	_IOW(i, 48, struct ifreq)	/* ppp special action */
#define	SIOCPPPGETIPCPS	_IOWR(i,49, struct ifreq)	/* get IPCP state */
I 86
D 87
#define	SIOCPPPGETAUTHS	_IOWR(i,50, struct ifreq)	/* get auth for self */
#define	SIOCPPPGETAUTHP	_IOWR(i,51, struct ifreq)	/* get auth for peer */
E 87
E 86
E 84
E 78

/* ppp special actions */
#define	PPPACT_RESET		0	/* reset ppp if */
#define	PPPACT_RECOVDEFAULT	1	/* set recovery mode to default */
#define	PPPACT_RECOVPERSIST	2	/* set recovery mode to persistent */
#define	PPPACT_RECOVPASSIVE	3	/* set recovery mode to passive */
I 86
#define	PPPACT_AUTHDONE		4	/* authentication phase done, go on */
E 86
E 77
E 73
I 57

I 80
/* network supervisory device ioctls */
D 84
#define	NIOCIFMON	_IOW('N',  0, struct ifreq)	/* monitor if */
E 84
I 84
#define	NIOCIFMON	_IOW(N,  0, struct ifreq)	/* monitor if */
I 86
#define	PPPAUXIOC_SETPROTOS	_IOW(N,  1, struct pppaux_ioctl)
#define	PPPAUXIOC_GETPROTOS	_IOWR(N, 2, struct pppaux_ioctl)
#define	PPPAUXIOC_SETAUTHSELF	_IOW(N,  3, struct pppaux_ioctl)
#define	PPPAUXIOC_GETAUTHSELF	_IOWR(N, 4, struct pppaux_ioctl)
#define	PPPAUXIOC_SETAUTHPEER	_IOW(N,  5, struct pppaux_ioctl)
#define	PPPAUXIOC_GETAUTHPEER	_IOWR(N, 6, struct pppaux_ioctl)
I 87
#define	PPPAUXIOC_GETSTATE	_IOR(N,  7, struct pppaux_stat_ioctl)
E 87
E 86
E 84

E 80
D 60
/* protocol i/o controls (bbn) */
#define SIOCSPUSH	_IO(b, 64)		/* tcp: set push */
#define SIOCCPUSH	_IO(b, 65)		/* tcp: clear push */
D 58
#define SIOCSNOACT	_IOW(b, 66, int)	/* tcp: set no activity timer */
#define SIOCGNOACT	_IOR(b, 67, int)	/* tcp: get no activity timer */
E 58
I 58
#define SIOCSNOACT	_IOW(b, 66, u_long)	/* tcp: set no activity timer */
#define SIOCGNOACT	_IOR(b, 67, u_long)	/* tcp: get no activity timer */
#define	    TCP_NOACTPROBE	0x80000000	/*	send pkt on timeout */
#define	    TCP_NOACTSIG	0x40000000	/*	advise user on timeout */
E 58
#define SIOCSINIT	_IOW(b, 68, int)	/* tcp: set init timer */
#define SIOCGINIT	_IOR(b, 69, int)	/* tcp: get init timer */
#define SIOCABORT	_IO(b, 70)		/* tcp: abort connection */

#define SIOCSNDGRAMS	_IOW(b, 71, int)	/* rdp: set max #dgrams rcv */
#define SIOCGNDGRAMS	_IOR(b, 72, int)	/* rdp: get max #dgrams rcv */
#define SIOCSSEQ	_IOW(b, 73, int)	/* rdp: set seq delivery */
#define SIOCGSEQ	_IOR(b, 74, int)	/* rdp: get seq delivery */
#define SIOCSNULL	_IOW(b, 77, int)	/* rdp: ~set KEEPALIVE timer */
#define SIOCGNULL	_IOR(b, 78, int)	/* rdp: ~get KEEPALIVE timer */

		/* tcp + rdp */
#define SIOCSRTTL	_IOW(b, 75, int)	/* set rxmit took too long */
#define SIOCGRTTL	_IOR(b, 76, int)	/* get rxmit took too long */
E 60
E 57
E 45
E 42
E 39
E 38
E 36
I 31
D 35

#define	KIOCTRANS	_IOW(k,0, int)	/* set keyboard translation */

#define	MIOCGPOS	_IOR(m,0, XXX)	/* get mouse info */
#define	MIOCGBUFS	_IOR(m,1, int)	/* get mouse buffer size */
#define	MIOCWBUFS	_IOW(m,1, int)	/* set mouse buffer size */
E 35
E 31
E 30
E 27
E 21
E 20
E 19
D 11
/* FIONREAD is not implemented on mpx channels yet */
E 11
D 15

I 11
/* mag tape io control commands */
#define MTIOCTOP	(('m'<<8)|1)	/* do a mag tape op (see <mtio.h>) */
#define MTIOCGET	(('m'<<8)|2)	/* get mag tape status (see <mtio.h>*/

/* mux io controls */
E 11
#define	MXLSTN		(('x'<<8)|1)
#define	MXNBLK		(('x'<<8)|2)

D 11
/*
 * These are defined in sys/vcmd.h
 *
E 11
I 11
#ifdef notdef
/* varian ioctls, which are defined in sys/vcmd.h */
E 11
#define	VGETSTATE	(('v'<<8)|0)
#define	VSETSTATE	(('v'<<8)|1)
D 11
 */
E 11
I 11
#endif

/* printer ioctls, see <lpio.h> */
#define	LGETSTATE	(('v'<<8)|2)
#define	LSETSTATE	(('v'<<8)|3)
E 15
I 12
D 14

/* chaos net io control commands */
#define CHIOCRNEXT	(('c'<<8)|1)	/* get chaos net unmatched rfc packet */
#define CHIOCRSKIP	(('c'<<8)|2)	/* Skip the unmatched RFC */
#define CHIOCRREAD	(('c'<<8)|3)	/* Read my RFC packet */
#define CHIOCTTY	(('c'<<8)|4)	/* make this channel a tty */
#define CHIOCFLUSH	(('c'<<8)|5)	/* flush current output packet */
E 14
E 12
E 11
#endif
E 1
