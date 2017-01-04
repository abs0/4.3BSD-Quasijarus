h42962
s 00000/00004/00409
d D 5.16 88/05/04 13:54:10 rick 16 15
c remove 3Com unet support
e
s 00000/00010/00413
d D 5.15 88/04/25 19:09:38 bostic 15 14
c don't include sysexits.h in uucp.h, include it in uux.c
e
s 00022/00022/00401
d D 5.14 88/04/05 13:57:59 rick 14 13
c get defines right for generic uucp
e
s 00033/00031/00390
d D 5.13 88/04/05 12:24:10 rick 13 12
c use syslog for errors
e
s 00008/00002/00413
d D 5.12 88/02/24 20:49:25 rick 12 11
c add connect accounting ifdef. increase LLEN to 150
e
s 00020/00010/00395
d D 5.11 86/02/12 17:28:05 bloom 11 10
c new dialers and cleanup from rick adams
e
s 00003/00003/00402
d D 5.10 86/01/06 15:02:30 bloom 10 9
c more fixes from rick adams
e
s 00024/00018/00381
d D 5.9 85/10/24 09:35:59 bloom 9 8
c still more changes from rick@seismo
e
s 00012/00002/00387
d D 5.8 85/06/24 10:34:42 bloom 8 7
c new update from rick adams
e
s 00091/00060/00298
d D 5.7 85/06/23 13:35:30 bloom 7 6
c fixes from rick adams
e
s 00036/00006/00322
d D 5.6 85/04/10 15:21:49 ralph 6 5
c more changes from rick adams.
e
s 00010/00010/00318
d D 5.5 85/01/28 10:45:44 ralph 5 4
c include more devices by default.
e
s 00114/00058/00214
d D 5.4 85/01/22 14:12:25 ralph 4 3
c bug fixes and changes from Rick Adams
e
s 00001/00000/00271
d D 5.3 84/09/04 14:04:37 ralph 3 2
c added network device NET to allow uucp over sockets.
e
s 00001/00000/00270
d D 5.2 83/07/19 11:33:17 gray 2 1
c security fixes
e
s 00270/00000/00000
d D 5.1 83/07/02 17:56:14 sam 1 0
c date and time created 83/07/02 17:56:14 by sam
e
u
U
t
T
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*	%W%	%G%	*/
E 12

D 6
#include "stdio.h"
E 6
I 6
#include <stdio.h>
E 6

/*
 * Determine local uucp name of this machine.
 * Define one of the following:
 *
 * For UCB 4.1A and later systems, you will have the gethostname(2) call.
 * If this call exists, define GETHOSTNAME.
 *
 * For USG 3.0 and later systems, you will have the uname(2) call.
 * If this call exists, define UNAME.
 *
 * Some systems have a line of the form '#define sysname "myuucpname",'
 * in the file /usr/include/whoami.h, to identify their machine.
 * If your site does that, define WHOAMI.
 *
 * If your site has <whoami.h>, but you do not want to read
 * that file every time uucp runs, you can compile sysname into uucp.
 * This is faster and more reliable, but binaries do not port.
 * If you want to do that, define CCWHOAMI.
 *
 * Some systems put the local uucp name in a single-line file
 * named /etc/uucpname or /local/uucpname.
 * If your site does that, define UUNAME.
 *
D 16
 * Systems running 3Com's UNET will have the getmyhname() call.
 * If you want to, define GETMYHNAME.
 *
E 16
D 4
 * You should also define MYNANE to be your uucp name.
E 4
I 4
 * You should also define MYNAME to be your uucp name.
E 4
 *
 * For each of the above that are defined, uucp checks them in order.
 * It stops on the first method that returns a non null name.
 * If everything fails, it uses "unknown" for the system name.
 */
D 7
#define	GETHOSTNAME
I 4
/*#define CCWHOAMI	*/
E 7
I 7
#define	GETHOSTNAME	/**/
/* #define UNAME	/**/
/* #define WHOAMI	/**/
/* #define CCWHOAMI	/**/
/* #define UUNAME	/**/
D 16
/* #define GETMYHNAME	/**/
E 16
E 7
E 4
/* If the above fails ... */
D 7
#define	MYNAME	"erewhon"
E 7
I 7
#define	MYNAME	"erehwon"
E 7

/*
D 15
 * If you have it, include <sysexits.h> to use exit
 * codes that will be understood by sendmail.
 * Otherwise, define EX_NOHOST, EX_CANTCREAT, and EX_NOINPUT.
 */
#include <sysexits.h>
D 4
/*#define EX_NOHOST	101*/
/*#define EX_CANTCREAT	1*/
/*#define EX_NOINPUT	2*/
E 4
I 4
D 7
/*#define EX_NOINPUT	66*/
/*#define EX_NOHOST	68*/
/*#define EX_CANTCREAT	73*/
E 7
I 7
/*#define EX_NOINPUT	66	/**/
/*#define EX_NOHOST	68	/**/
/*#define EX_CANTCREAT	73	/**/
E 7
E 4

D 4
/* define UUDIR for uucp subdirectory kludge (recommended) */
#define	UUDIR

E 4
/*
E 15
 * Define the various kinds of connections to include.
 * The complete list is in the condevs array in condevs.c
 */
I 11
D 13
#define ATT2224		/* AT&T 2224 */
E 13
I 13
D 14
/* #define ATT2224		/* AT&T 2224 */
E 13
E 11
D 4
#define DN11		/* standard dialer */
/*#define DATAKIT		/* ATT's datakit */
E 4
I 4
D 5
/*#define DN11		/* standard dialer */
E 5
I 5
D 9
#define DN11		/* standard dialer */
E 5
/*#define DATAKIT	/* ATT's datakit */
E 4
/*#define PNET		/* Purdue network */
E 9
I 9
#define BSDTCP		/* 4.2bsd or 2.9bsd TCP/IP */
I 11
D 13
#define CDS224		/* Concord Data Systems 2400 */
E 13
I 13
/* #define CDS224		/* Concord Data Systems 2400 */
E 14
I 14
#define ATT2224		/* AT&T 2224 */
#define BSDTCP		/* 4.2bsd TCP/IP */
#define CDS224		/* Concord Data Systems 2400 */
E 14
E 13
E 11
/* #define DATAKIT	/* ATT's datakit */
E 9
D 5
/*#define DF02		/* Dec's DF02/DF03 */
D 4
#define HAYES		/* Hayes' Smartmodem */
#define VENTEL		/* ventel dialer */
#define VADIC		/* Racal-Vadic 3450 */
/*#define RVMACS		/* Racal-Vadic MACS 831 */
I 3
#define TCPNET		/* 4.2 TCP Network */
E 3
/*#define UNET		/* 3Com's UNET */
E 4
I 4
/*#define HAYES		/* Hayes' Smartmodem */
/*#define VENTEL	/* ventel dialer */
/*#define VADIC		/* Racal-Vadic 345x */
/*#define VA212		/* Racal-Vadic 212 */
/*#define VA811S	/* Racal-Vadic 811S dialer, 831 adaptor */
E 5
I 5
D 13
#define DF02		/* Dec's DF02/DF03 */
I 6
#define DF112		/* Dec's DF112 */
I 9
#define DN11		/* "standard" DEC dialer */
E 13
I 13
D 14
/* #define DF02		/* Dec's DF02/DF03 */
/* #define DF112		/* Dec's DF112 */
/* #define DN11		/* "standard" DEC dialer */
E 14
I 14
#define DF02		/* Dec's DF02/DF03 */
#define DF112		/* Dec's DF112 */
#define DN11		/* "standard" DEC dialer */
E 14
E 13
E 9
E 6
#define HAYES		/* Hayes' Smartmodem */
I 11
D 13
#define HAYES2400	/* Hayes' 2400 baud Smartmodem */
E 13
I 13
D 14
/* #define HAYES2400	/* Hayes' 2400 baud Smartmodem */
E 14
I 14
#define HAYES2400	/* Hayes' 2400 baud Smartmodem */
E 14
E 13
E 11
D 7
#define VENTEL		/* ventel dialer */
E 7
I 7
D 9
#define VENTEL		/* Ventel Dialer */
E 9
I 9
/* #define MICOM	/* Micom Mux port */
D 13
#define NOVATION	/* Novation modem */
#define PAD		/* X.25 PAD */
E 9
E 7
I 6
#define PENRIL		/* PENRIL Dialer */
E 13
I 13
D 14
/* #define NOVATION	/* Novation modem */
/* #define PAD		/* X.25 PAD */
/* #define PENRIL		/* PENRIL Dialer */
E 14
I 14
#define NOVATION	/* Novation modem */
#define PAD		/* X.25 PAD */
#define PENRIL		/* PENRIL Dialer */
E 14
E 13
E 6
D 9
#define VADIC		/* Racal-Vadic 345x */
E 9
I 9
/* #define PNET		/* Purdue network */
D 13
#define RVMACS		/* Racal-Vadic MACS  820 dialer, 831 adaptor */
E 13
I 13
D 14
/* #define RVMACS		/* Racal-Vadic MACS  820 dialer, 831 adaptor */
E 14
I 14
#define RVMACS		/* Racal-Vadic MACS  820 dialer, 831 adaptor */
E 14
E 13
/* #define SYTEK	/* Sytek Local Area Net */
/* #define UNETTCP	/* 3Com's UNET */
I 11
#define USR2400		/* USRobotics Courier 2400 */
E 11
E 9
D 13
#define VA212		/* Racal-Vadic 212 */
#define VA811S		/* Racal-Vadic 811S dialer, 831 adaptor */
E 5
#define VA820		/* Racal-Vadic 820 dialer, 831 adaptor */
D 5
/*#define RVMACS	/* Racal-Vadic MACS  820 dialer, 831 adaptor */
/*#define VMACS		/* Racal-Vadic MACS  811 dialer, 831 adaptor */
E 5
I 5
D 9
#define RVMACS		/* Racal-Vadic MACS  820 dialer, 831 adaptor */
E 9
I 9
#define VADIC		/* Racal-Vadic 345x */
#define VENTEL		/* Ventel Dialer */
E 9
#define VMACS		/* Racal-Vadic MACS  811 dialer, 831 adaptor */
E 13
I 13
D 14
/* #define VA212		/* Racal-Vadic 212 */
/* #define VA811S		/* Racal-Vadic 811S dialer, 831 adaptor */
/* #define VA820		/* Racal-Vadic 820 dialer, 831 adaptor */
/* #define VADIC		/* Racal-Vadic 345x */
/* #define VENTEL		/* Ventel Dialer */
/* #define VMACS		/* Racal-Vadic MACS  811 dialer, 831 adaptor */
E 14
I 14
#define VA212		/* Racal-Vadic 212 */
#define VA811S		/* Racal-Vadic 811S dialer, 831 adaptor */
#define VA820		/* Racal-Vadic 820 dialer, 831 adaptor */
#define VADIC		/* Racal-Vadic 345x */
#define VENTEL		/* Ventel Dialer */
#define VMACS		/* Racal-Vadic MACS  811 dialer, 831 adaptor */
E 14
E 13
E 5
D 9
/*#define UNETTCP	/* 3Com's UNET */
D 7
#define BSDTCP		/* 4.2bsd TCP/IP */
E 7
I 7
#define BSDTCP		/* 4.2bsd or 2.9bsd TCP/IP */
E 7
#define PAD		/* X.25 PAD */
E 4
/*#define MICOM		/* micom mux port */
I 4
D 5
/*#define NOVATION	/* Novation modem */
E 5
I 5
#define NOVATION	/* Novation modem */
E 9
E 5
E 4

I 11
#if defined(USR2400) && !defined(HAYES)
#define HAYES
#endif USR2400 && !HAYES

E 11
I 4
#if defined(UNETTCP) || defined(BSDTCP)
#define TCPIP
#endif

E 4
D 6
#ifdef	VENTEL
E 6
I 6
D 10
#if defined(VENTEL) || defined(NOVATION) || defined(DF112) || defined(PENRIL)
E 10
E 6
/*
D 10
 * We need a timer to write slowly to ventels.
E 10
I 10
 * We need a timer to write slowly to certain modems.
 * and for generating breaks.
 *
E 10
D 8
 * define INTERVALTIMER to use 4.2 bsd interval timer.
E 8
I 8
 * define INTERVALTIMER to use 4.[23] bsd interval timer.
E 8
 * define FASTTIMER if you have the nap() system call.
 * define FTIME if you have the ftime() system call.
 * define BUSYLOOP if you must do a busy loop.
 * Look at uucpdelay() in condevs.c for details.
 */
D 7
#define	FTIME
E 7
I 7
#define	INTERVALTIMER
I 9
/*#define FASTTIMER /**/
/*#define FTIME /**/
/*#define BUSYLOOP /**/
E 9
E 7
D 6
#endif
E 6
I 6
D 10
#endif VENTEL || NOVATION || DF112 || PENRIL
E 10
E 6

/*
 * If your site is using "ndir.h" to retrofit the Berkeley
 * directory reading routines, define NDIR.
 * You will probably also have to set LIBNDIR in Makefile.
 * Otherwise, <dir.h> is assumed to have the Berkeley directory definitions.
 */
D 4
/*#define	NDIR*/
E 4
I 4
D 7
/*#define	NDIR	*/
E 7
I 7
/*#define	NDIR	/**/
E 7
E 4

/*
D 4
 * If yours is a BTL system III, IV, or so-on site, define SYSIII.
 * Conditional compilations should produce the right code,
 * but if it doesn't (the compiler will probably complain loudly),
 * make the needed adjustments and guard the code with
 * #ifdef SYSIII, (code for system III), #else, (code for V7), #endif
E 4
I 4
D 7
 * If yours is a BTL system III, IV, or so-on site, define USG.
E 7
I 7
 * If yours is a BTL system III, IV, V or so-on site, define USG.
E 7
E 4
 */
D 4
/*#define	SYSIII*/
E 4
I 4
D 7
/*#define	USG	*/
E 7
I 7
/*#define	USG	/**/
E 7
E 4

I 4
/*
D 8
 * If you are running 4.2bsd, define BSD4_2
E 8
I 8
 * If you are running 4.3bsd, define BSD4_3 and BSD4_2
 * If you are just running 4.2bsd, define BSD4_2
I 11
 * If you are running the BRL version of 4.2BSD define BRL4_2, NOT BSD4_3
E 11
E 8
 */
I 8
#define BSD4_3 	/**/
E 8
D 7
#define BSD4_2
E 7
I 7
#define BSD4_2 	/**/
I 11
/*#define BRL4_2 /**/
E 11
E 7

I 11
#if defined(BRL4_2) && !defined(BSD4_2)
#define BSD4_2
#undef BSD4_3
#endif BRL4_2

E 11
/*
I 7
D 13
 * If you are running 2.9bsd, define BSD2_9
 */
/*#define BSD2_9 	/**/

/*
E 13
E 7
 * If you are using /etc/inetd with 4.2bsd, define BSDINETD
 */
D 7
#define BSDINETD
E 7
I 7
#define BSDINETD	/**/
I 8

/*
D 11
 * If you are running 4.3bsd, you are running the inetd
E 11
I 11
 * If you are running 4.3bsd or BRL 4.2, you are running the inetd
E 11
 */

D 11
#if defined(BSD4_3) && !defined(BSDINETD)
E 11
I 11
#if (defined(BSD4_3) || defined(BRL4_2)) && !defined(BSDINETD)
E 11
#define BSDINETD
D 11
#endif BSD4_3 && !BSDINETD
E 11
I 11
#endif (BSD4_3 ||BRL4_2) && !BSDINETD
E 11
E 8
E 7

/*#define VMSDTR	/* Turn on modem control on vms(works DTR) for
			   develcon and gandalf ports to gain access */
I 6
/*
 *	If you want to use the same modem for dialing in and out define
 *	DIALINOUT to be the localtion of the acucntrl program
 */
D 7
/* #define DIALINOUT	"/usr/lib/uucp/acucntrl" */
E 7
I 7
D 13
/* #define DIALINOUT	"/usr/lib/uucp/acucntrl" /**/
E 13
I 13
D 14
#define DIALINOUT	"/usr/lib/uucp/acucntrl" /**/
E 14
I 14
/* #define DIALINOUT	"/usr/lib/uucp/acucntrl" /**/
E 14
E 13
E 7
E 6

E 4
D 7
/* define the last characters for ACU */
D 4
/* burl!lda, rti!trt, isn't "<" more widely used than "-"? */
/* rti!trt: use -< as is done in 4.1c uucp */
E 4
#define ACULAST "-<"
E 7
I 7
/*
 *	If you want all ACU lines to be DIALINOUT, define ALLACUINOUT
 */
D 13
/* #define ALLACUINOUT	/**/
E 13
I 13
D 14
#define ALLACUINOUT	/**/
E 14
I 14
/* #define ALLACUINOUT	/**/
E 14
E 13
E 7

/* define the value of WFMASK - for umask call - used for all uucp work files */
#define WFMASK 0137

I 4
D 11
/* define UUSTAT if you need "uustat" command */
D 7
/* #define UUSTAT	*/
E 7
I 7
/* #define UUSTAT	/**/
E 7

D 7
/*	define UUSUB if you need "uusub" command */
E 7
I 7
/* define UUSUB if you need "uusub" command */
E 7
/* #define UUSUB /**/

E 11
E 4
/* define the value of LOGMASK - for LOGFILE, SYSLOG, ERRLOG */
D 7
#define	LOGMASK	0133
E 7
I 7
#define	LOGMASK		0133
E 7

/* All files are given at least the following at the final destination */
/* It is also the default mode, so '666' is recommended */
/* and 444 is minimal (minimally useful, maximally annoying) */
#define	BASEMODE	0666

D 4
/* All users with getuid() <= PRIV_UIDS are 'privileged'. */
/* Was 10, reduced to 3 as suggested by duke!dbl (David Leonard) */
#define	PRIV_UIDS	3
E 4
I 4
/*
 * Define NOSTRANGERS if you don't want to accept transactions from
 * sites that are not in your L.sys file (see cico.c)
 */
D 7
#define NOSTRANGERS
E 7
I 7
#define NOSTRANGERS	/**/
I 11

E 11
E 7
/*
 * Traditionally LCK (lock) files have been kept in /usr/spool/uucp.
 * If you want that define LOCKDIR to be ".".
D 9
 * If you want the locks kept in a subdirectory, define LOCKDIR as "LCK.".
E 9
I 9
 * If you want the locks kept in a subdirectory, define LOCKDIR as "LCK".
E 9
 * Good news about LCK. subdirectory: the directory can be mode 777 so
 * unprivileged programs can share the uucp locking system,
 * and the subdirectory keeps down clutter in the main directory.
 * The BAD news: you have to change 'tip' and another programs that
 * know where the LCK files are kept, and you have to change your /etc/rc
 * if your rc cleans out the lock files (as it should).
 */
D 6
/*#define	LOCKDIR	"LCK." */
E 6
I 6
D 7
/*#define	LOCKDIR	"LCK" */
E 6
#define	LOCKDIR	"."
E 7
I 7
D 9
/*#define	LOCKDIR	"LCK."	/**/
E 9
I 9
D 13
/*#define	LOCKDIR	"LCK"	/**/
E 9
#define LOCKDIR	"." /**/
E 13
I 13
D 14
#define	LOCKDIR	"LCK"	/**/
/* #define LOCKDIR	"." /**/
E 14
I 14
/* #define	LOCKDIR	"LCK"	/**/
#define LOCKDIR	"." /**/
E 14
E 13
E 7
E 4

I 4
D 9
/* 
E 9
I 9
/*
E 9
 * If you want uucp and uux to copy the data files by default,
 * don't define DONTCOPY (This is the way older 4bsd uucps worked)
 * If you want uucp and uux to use the original files instead of
 * copies, define DONTCOPY (This is the way System III and V work)
 */
D 7
#define DONTCOPY
E 7
I 7
#define DONTCOPY	/**/
E 7

/*
D 6
 * Very few (none I know of) systems use the sequence checking feature.
E 6
I 6
 * Very few (that I know of) systems use the sequence checking feature.
E 6
 * If you are not going to use it (hint: you are not),
 * do not define GNXSEQ.  This saves precious room on PDP11s.
 */
D 7
/*#define	GNXSEQ/* comment this out to save space */
E 7
I 7
/*#define	GNXSEQ	/* comment this out to save space */
E 7

I 6
/*
 * If you want the logfile stored in a file for each site instead
 * of one file
 * define LOGBYSITE as the directory to put the files in
 */
D 7
/*#define LOGBYSITE	"/usr/spool/uucp/LOG"	*/
E 7
I 7
D 13
/*#define LOGBYSITE	"/usr/spool/uucp/LOG" /**/
E 13
I 13
D 14
#define LOGBYSITE	"/usr/spool/uucp/LOG" /**/
E 14
I 14
/* #define LOGBYSITE	"/usr/spool/uucp/LOG" /**/
E 14
E 13
E 7

I 12
/*
I 13
 * define USE_SYSLOG if you want error messages to use SYSLOG instead
 * of being written to /usr/spool/log/ERRLOG
 */
#define USE_SYSLOG	/**/

/*
E 13
 * If you are doing rebilling and need connect accounting,
D 13
 * define DO_CONNECT_ACCOUNTING
E 13
I 13
 * define DO_CONNECT_ACCOUNTING to be the accounting file name
E 13
 */
D 13
/*#define DO_CONNECT_ACCOUNTING	/**/
E 13
I 13
/*#define DO_CONNECT_ACCOUNTING	"/usr/spool/uucp/CONNECT"	/**/
E 13

E 12
E 6
E 4
#define XQTDIR		"/usr/spool/uucp/XTMP"
#define SQFILE		"/usr/lib/uucp/SQFILE"
#define SQTMP		"/usr/lib/uucp/SQTMP"
#define SLCKTIME	5400	/* system/device timeout (LCK.. files) */
#define SEQFILE		"/usr/lib/uucp/SEQF"
#define SYSFILE		"/usr/lib/uucp/L.sys"
#define DEVFILE		"/usr/lib/uucp/L-devices"
#define DIALFILE	"/usr/lib/uucp/L-dialcodes"
#define USERFILE	"/usr/lib/uucp/USERFILE"
#define	CMDFILE		"/usr/lib/uucp/L.cmds"
I 6
#define	ALIASFILE	"/usr/lib/uucp/L.aliases"
E 6

#define SPOOL		"/usr/spool/uucp"
D 4
#define SQLOCK		"/usr/spool/uucp/LCK.SQ"
E 4
I 4
D 9
#define SQLOCK		"LCK.SQ"
E 9
I 9
D 11
#define SQLOCK		"SQ"
E 11
E 9
E 4
#define SYSLOG		"/usr/spool/uucp/SYSLOG"
#define PUBDIR		"/usr/spool/uucppublic"

I 11
#define SQLOCK		"SQ"
E 11
D 9
#define SEQLOCK		"LCK.SEQL"
E 9
I 9
#define SEQLOCK		"SEQL"
E 9
#define CMDPRE		'C'
#define DATAPRE		'D'
#define XQTPRE		'X'

D 7
#define LOGFILE	"/usr/spool/uucp/LOGFILE"
#define ERRLOG	"/usr/spool/uucp/ERRLOG"
I 4
#define CMDSDIR	"/usr/spool/uucp/C."
#define DATADIR	"/usr/spool/uucp/D."
#define XEQTDIR	"/usr/spool/uucp/X."
E 7
I 7
#define LOGFILE		"/usr/spool/uucp/LOGFILE"
#define ERRLOG		"/usr/spool/uucp/ERRLOG"
#define CMDSDIR		"/usr/spool/uucp/C."
#define DATADIR		"/usr/spool/uucp/D."
#define XEQTDIR		"/usr/spool/uucp/X."
E 7
E 4

#define RMTDEBUG	"AUDIT"
I 4
#define CORRUPT		"CORRUPT"
E 4
#define SQTIME		60
#define TRYCALLS	2	/* number of tries to dial call */

D 4
/*define PROTODEBUG = 1 if testing protocol - introduce errors */
E 4
I 4
D 12
#define LLEN	50
E 12
I 12
#define LLEN	150
E 12
#define MAXRQST	250

E 4
#define DEBUG(l, f, s) if (Debug >= l) fprintf(stderr, f, s); else

D 4
#define ASSERT(e, s1, s2, i1) if (!(e)) {\
assert(s1, s2, i1);\
cleanup(FAIL);} else
E 4
I 4
D 13
#define ASSERT(e, s1, s2, i1) if (!(e)) {assert(s1, s2, i1);cleanup(FAIL);}else
E 4

E 13
I 9
#define delock(dev)	rmlock(dev)
#define mlock(dev)	ulockf(dev, SLCKTIME)

E 9
D 4

E 4
D 7
#define SAME 0
D 4
#define ANYREAD 04
E 4
I 4
#define ANYREAD 0004
E 4
#define ANYWRITE 02
#define FAIL -1
#define SUCCESS 0
#define CNULL (char *) 0
#define STBNULL (struct sgttyb *) 0
#define MASTER 1
#define SLAVE 0
D 4
#define MAXFULLNAME 250
E 4
I 4
#define MAXFULLNAME 255
E 4
#define MAXMSGTIME 45
D 4
#define NAMESIZE 15
E 4
I 4
#define NAMESIZE 255
E 4
#define EOTMSG "\04\n\04\n"
#define CALLBACK 1
I 4
#define ONEDAY	86400L
E 7
I 7
#define SAME		0
#define ANYREAD		0004
#define ANYWRITE	02
#define FAIL		-1
#define SUCCESS		0
#define CNULL		(char *) 0
#define STBNULL		(struct sgttyb *) 0
#define MASTER		1
#define SLAVE		0
#define MAXFULLNAME	255
#define MAXMSGTIME	45
#define NAMESIZE	255
#define MAXBASENAME	14
#define SYSNSIZE	(MAXBASENAME-1-1-1-4)
#define EOTMSG		"\04\n\04\n"
#define CALLBACK	1
#define ONEDAY		86400L
E 7
E 4

	/*  commands  */
#define SHELL		"/bin/sh"
D 4
#define MAIL		"mail"
E 4
I 4
#define MAIL		"/usr/lib/sendmail"
E 4
#define UUCICO		"/usr/lib/uucp/uucico"
#define UUXQT		"/usr/lib/uucp/uuxqt"
#define UUCP		"uucp"

	/*  call connect fail stuff  */
#define CF_SYSTEM	-1
#define CF_TIME		-2
#define CF_LOCK		-3
#define	CF_NODEV	-4
#define CF_DIAL		-5
#define CF_LOGIN	-6

D 7
#define F_NAME 0
#define F_TIME 1
#define F_LINE 2
#define F_CLASS 3	/* an optional prefix and the speed */
#define F_PHONE 4
#define F_LOGIN 5
E 7
I 7
#define F_NAME		0
#define F_TIME		1
#define F_LINE		2
#define F_CLASS		3	/* an optional prefix and the speed */
#define F_PHONE		4
#define F_LOGIN		5
E 7

D 7
#define MAXPH	60	/* maximum length of a phone number */
E 7
I 7
#define MAXPH		60	/* maximum length of a phone number */
E 7

	/* This structure tells how to get to a device */
struct condev {
	char *CU_meth;		/* method, such as 'ACU' or 'DIR' */
	char *CU_brand;		/* brand, such as 'Hayes' or 'Vadic' */
	int (*CU_gen)();	/* what to call to search for brands */
	int (*CU_open)();	/* what to call to open brand */
	int (*CU_clos)();	/* what to call to close brand */
};

	/* This structure tells about a device */
struct Devices {
D 4
	char D_type[20];
	char D_line[20];
	char D_calldev[20];
	char D_class[20];
	int D_speed;
	char D_brand[20];	/* brand name, as 'Hayes' or 'Vadic' */
E 4
I 4
#define	D_type		D_arg[0]
#define	D_line		D_arg[1]
#define	D_calldev	D_arg[2]
#define	D_class		D_arg[3]
#define	D_brand		D_arg[4]
#define	D_CHAT		5
	int  D_numargs;
	int  D_speed;
	char *D_arg[20];
	char D_argbfr[100];
E 4
};

	/*  system status stuff  */
#define SS_OK		0
D 7
#define SS_FAIL		4
E 7
#define SS_NODEVICE	1
#define SS_CALLBACK	2
#define SS_INPROGRESS	3
I 7
#define SS_FAIL		4
E 7
#define SS_BADSEQ	5
I 4
#define SS_WRONGTIME	6
E 4

	/*  fail/retry parameters  */
D 4
#define RETRYTIME 3300
E 4
I 4
D 7
#define RETRYTIME 600
E 4
#define MAXRECALLS 20
E 7
I 7
#define RETRYTIME	600
#define MAXRECALLS	25
E 7

	/*  stuff for command execution  */
#define X_RQDFILE	'F'
#define X_STDIN		'I'
#define X_STDOUT	'O'
#define X_CMD		'C'
#define X_USER		'U'
#define X_SENDFILE	'S'
#define	X_NONOTI	'N'
I 4
#define X_RETURNTO	'R'
E 4
#define	X_NONZERO	'Z'
D 9
#define X_LOCK		"LCK.XQT"
E 9
I 9
#define X_LOCK		"XQT"
E 9
D 7
#define X_LOCKTIME	3600
E 7
I 7
#define X_LOCKTIME	3600L
E 7

D 7
#define WKDSIZE 100	/*  size of work dir name  */
E 7
I 7
#define WKDSIZE		100	/*  size of work dir name  */
E 7

I 6
#include <sys/types.h>
#ifndef USG
#include <sys/timeb.h>
#else USG
struct timeb
{
	time_t	time;
	unsigned short millitm;
	short	timezone;
	short	dstflag;
};
I 7
#define rindex strrchr
#define index strchr
E 7
#endif USG

I 13
#ifdef BSD4_2
#include <syslog.h>
#endif /* BSD4_2 */

E 13
extern struct timeb Now;

E 6
extern int Ifn, Ofn;
D 6
extern char Rmtname[];
E 6
I 6
extern char *Rmtname;
E 6
extern char User[];
extern char Loginuser[];
extern char *Spool;
extern char Myname[];
I 4
extern char Myfullname[];
E 4
extern int Debug;
D 4
extern int Pkdebug;
extern int Pkdrvon;
E 4
extern int Bspeed;
extern char Wrkdir[];
D 7
extern long Retrytime;
E 7
I 7
extern time_t Retrytime;
E 7
D 4
extern int Unet;
E 4
I 4
extern short Usrf;
extern int IsTcpIp;
E 4
extern char Progname[];
extern int (*CU_end)();
extern struct condev condevs[];
I 4
D 9
extern int nologinflag;
E 9
extern char NOLOGIN[];
E 4

D 4
#ifdef	UUDIR
#define	subfile(s)	SubFile(s)
#define	subdir(d, p)	SubDir(d, p)
#define	subchdir(d)	SubChDir(d)
extern	char DLocal[], DLocalX[], *SubFile(), *SubDir();
#else
#define	subfile(s)	s
#define	subdir(d, p)	d
#define	subchdir(d)	chdir(d)
#endif
E 4
I 4
extern	char DLocal[], DLocalX[], *subfile(), *subdir();
E 4

/* Commonly called routines which return non-int value */
extern	char *ttyname(), *strcpy(), *strcat(), *index(), *rindex(),
D 4
		*fgets(), *calloc(), *malloc(),
E 4
I 4
		*fgets(), *calloc(), *malloc(), *fdig(), *ttyname(),
E 4
D 7
		*cfgets();
E 7
I 7
		*cfgets(), *getwd(), *strpbrk(), *strncpy();
E 7
extern	long lseek();
I 2
D 13
extern	FILE *rpopen();
E 13
I 7
extern time_t time();
E 7
I 4

extern char _FAILED[], CANTOPEN[], DEVNULL[];
I 7

#ifdef lint
/* This horrible gross kludge is the only way I know to
 * convince lint that signal(SIGINT,SIG_IGN) is legal. It hates SIG_IGN.
 */
#ifdef SIG_IGN
#undef SIG_IGN
#endif /* SIG_IGN */
#define SIG_IGN	main
extern int main();
#ifdef DEBUG
#undef DEBUG
#endif DEBUG
#define DEBUG(a,b,c)
#endif /* lint */
E 7
E 4
E 2
E 1
