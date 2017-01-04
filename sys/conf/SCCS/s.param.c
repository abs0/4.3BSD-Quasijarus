h04975
s 00000/00005/00086
d D 7.3 86/12/06 22:34:53 sam 36 35
c no longer need tahoe bogosity
e
s 00007/00000/00084
d D 7.2 86/10/29 19:37:29 karels 35 34
c tahoe
e
s 00002/00002/00082
d D 7.1 86/06/05 01:47:10 mckusick 34 33
c 4.3BSD release version
e
s 00002/00003/00082
d D 6.13 86/02/23 23:36:19 karels 33 32
c add sccsid; rm unused
e
s 00004/00003/00081
d D 6.12 86/02/20 21:23:16 karels 32 31
c rename nch to avoid name conflict; slow rate of time skew when correcting
e
s 00001/00001/00083
d D 6.11 85/09/18 14:22:59 karels 31 29
c larger clists, so trim
e
s 00001/00001/00083
d R 6.11 85/06/25 13:21:07 karels 30 29
c decrease number of clists with larger clists
e
s 00011/00001/00073
d D 6.10 85/06/08 12:08:32 mckusick 29 28
c Add copyright
e
s 00001/00001/00073
d D 6.9 85/04/17 17:00:27 karels 28 27
c add a few text entries on the low end
e
s 00001/00000/00073
d D 6.8 84/12/20 15:46:18 karels 27 26
c tickadj (for adjtime)
e
s 00002/00002/00071
d D 6.7 84/08/23 16:22:33 mckusick 26 25
c insure that ndquot is at least as big as the inode table
e
s 00000/00001/00073
d D 6.6 84/07/08 15:35:54 sam 25 24
c ufs_nami.c -> ufs_namei.c and nami.h -> namei.h 
e
s 00003/00003/00071
d D 6.5 84/07/02 18:00:31 mckusick 24 23
c resize namei cache to cover the entire inode table
e
s 00002/00007/00072
d D 6.4 84/06/06 23:02:53 sam 23 22
c delete NETSLOP what with inetd
e
s 00003/00002/00076
d D 6.3 84/01/09 15:31:39 mckusick 22 20
c ninodes depends on the size of the namei() cache
e
s 00003/00002/00076
d R 6.3 84/01/09 15:26:15 mckusick 21 20
c ninodes depends on size of namei() cache
e
s 00003/00000/00075
d D 6.2 84/01/03 23:44:30 mckusick 20 19
c add system wide cacheing of path names in namei() (from kre)
e
s 00000/00000/00075
d D 6.1 83/07/29 07:41:23 sam 19 18
c 4.2 distribution
e
s 00007/00004/00068
d D 4.18 83/07/21 01:45:47 sam 18 17
c don't penalize others for our stupidity
e
s 00004/00002/00068
d D 4.17 83/07/21 01:33:14 sam 17 16
c up various tables to account for servers
e
s 00001/00001/00069
d D 4.16 82/11/15 10:16:05 sam 16 15
c temporary, until callout table is allocated at boot time
e
s 00002/00002/00068
d D 4.15 82/11/13 23:09:44 sam 15 14
c merge 4.1b and 4.1c
e
s 00004/00002/00066
d D 4.14 82/09/18 15:12:00 root 14 13
c add tick, drop dstflag
e
s 00009/00000/00059
d D 4.13 82/08/01 19:30:59 sam 13 12
c quota stuff
e
s 00001/00001/00058
d D 4.12 82/04/03 23:40:51 wnj 12 11
c much more generous NFILE
e
s 00001/00001/00058
d D 4.11 81/11/30 16:23:07 wnj 11 10
c lint
e
s 00000/00014/00059
d D 4.10 81/11/14 16:43:45 wnj 10 9
c before header overlay
e
s 00011/00012/00062
d D 4.9 81/11/08 16:56:29 wnj 9 8
c BBNNET->INET, contab XXX, 
e
s 00000/00001/00074
d D 4.8 81/11/07 11:09:42 wnj 8 7
c fixes per shannon
e
s 00004/00003/00071
d D 4.7 81/10/29 20:53:39 wnj 7 6
c s/bbnnet/inet/
e
s 00000/00003/00074
d D 4.6 81/10/29 18:10:32 wnj 6 5
c before inserting beauty header files
e
s 00001/00001/00076
d D 4.5 81/05/15 14:03:39 wnj 5 4
c adjusted NFILE formula
e
s 00020/00001/00057
d D 4.4 81/05/12 17:18:49 root 4 3
c add tcp/ip
e
s 00002/00000/00056
d D 4.3 81/04/28 02:55:11 root 3 2
c add nport
e
s 00001/00001/00055
d D 4.2 81/04/02 23:39:44 root 2 1
c more inodes!
e
s 00056/00000/00000
d D 4.1 81/03/09 01:52:15 wnj 1 0
c date and time created 81/03/09 01:52:15 by wnj
e
u
U
t
T
I 1
D 29
/*	%M%	%I%	%E%	*/
E 29
I 29
/*
D 34
 * Copyright (c) 1980 Regents of the University of California.
E 34
I 34
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 34
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
I 33
 *
 *	%W% (Berkeley) %G%
E 33
 */

#ifndef lint
char copyright[] =
D 34
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 34
I 34
"%Z% Copyright (c) 1980, 1986 Regents of the University of California.\n\
E 34
 All rights reserved.\n";
#endif not lint
E 29

#include "../h/param.h"
#include "../h/systm.h"
I 4
D 9
#ifdef BBNNET
D 7
#include "../bbnnet/net.h"
#include "../bbnnet/imp.h"
#include "../bbnnet/ucb.h"
E 7
I 7
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
#include "../inet/imp.h"
E 9
I 9
D 10
#ifdef INET
#include "../net/inet.h"
#include "../net/inet_systm.h"
#include "../net/imp.h"
#endif INET
E 10
E 9
#include "../h/socket.h"
E 7
D 9
#endif BBNNET
E 9
E 4
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/text.h"
#include "../h/inode.h"
#include "../h/file.h"
#include "../h/callout.h"
#include "../h/clist.h"
#include "../h/cmap.h"
I 3
D 9
#include "../h/port.h"
E 9
I 9
#include "../h/mbuf.h"
I 20
D 25
#include "../h/nami.h"
E 25
E 20
I 13
#include "../h/quota.h"
I 14
#include "../h/kernel.h"
E 14
E 13
E 9
E 3
/*
 * System parameter formulae.
 *
 * This file is copied into each directory where we compile
 * the kernel; it should be modified there to suit local taste
 * if necessary.
 *
 * Compiled with -DHZ=xx -DTIMEZONE=x -DDST=x -DMAXUSERS=xx
 */

I 35
#ifndef HZ
D 36
#ifdef VAX
E 36
E 35
I 14
#define	HZ 100
I 35
D 36
#endif
#ifdef TAHOE
#define	HZ 60
#endif
E 36
#endif
E 35
E 14
int	hz = HZ;
D 14
int	timezone = TIMEZONE;
int	dstflag = DST;
E 14
I 14
int	tick = 1000000 / HZ;
I 27
D 32
int	tickadj = 1000000 / HZ / 10;
E 32
I 32
int	tickadj = 240000 / (60 * HZ);		/* can adjust 240ms in 60s */
E 32
E 27
struct	timezone tz = { TIMEZONE, DST };
E 14
#define	NPROC (20 + 8 * MAXUSERS)
int	nproc = NPROC;
D 17
int	ntext = 24 + MAXUSERS;
E 17
I 17
D 18
/* the +20 here is for all the lousy server processes */
int	ntext = 24 + MAXUSERS + 20;
E 18
I 18
D 23
#ifdef INET
#define	NETSLOP	20			/* for all the lousy servers*/
#else
#define	NETSLOP	0
#endif
E 23
I 22
D 24
#define NCHSIZE (60 + 2 * MAXUSERS)
int	nchsize = NCHSIZE;
E 24
E 22
D 23
int	ntext = 24 + MAXUSERS + NETSLOP;
E 23
I 23
D 28
int	ntext = 24 + MAXUSERS;
E 28
I 28
int	ntext = 36 + MAXUSERS;
E 28
E 23
E 18
E 17
D 2
int	ninode = NPROC + 16 + MAXUSERS;
E 2
I 2
D 22
int	ninode = (NPROC + 16 + MAXUSERS) + 32;
E 22
I 22
D 24
int	ninode = (NPROC + 16 + MAXUSERS + (2 * NCHSIZE / 3)) + 32;
E 24
I 24
#define NINODE ((NPROC + 16 + MAXUSERS) + 32)
int	ninode = NINODE;
int	nchsize = NINODE * 11 / 10;
E 24
E 22
E 2
D 5
int	nfile = 8 * (NPROC + 16 + MAXUSERS) / 10;
E 5
I 5
D 12
int	nfile = 8 * (NPROC + 16 + MAXUSERS) / 10 + 32;
E 12
I 12
D 17
int	nfile = 16 * (NPROC + 16 + MAXUSERS) / 10 + 32;
E 17
I 17
D 18
/* the +40 here is for 20 server processes */
int	nfile = 16 * (NPROC + 16 + MAXUSERS) / 10 + 32 + 40;
E 18
I 18
D 23
int	nfile = 16 * (NPROC + 16 + MAXUSERS) / 10 + 32 + 2 * NETSLOP;
E 23
I 23
int	nfile = 16 * (NPROC + 16 + MAXUSERS) / 10 + 32;
E 23
E 18
E 17
E 12
E 5
D 16
int	ncallout = 16 + MAXUSERS;
E 16
I 16
int	ncallout = 16 + NPROC;
E 16
D 31
int	nclist = 100 + 16 * MAXUSERS;
E 31
I 31
int	nclist = 60 + 12 * MAXUSERS;
E 31
I 3
D 33
int	nport = NPROC / 2;
E 33
I 4
D 9
#ifdef BBNNET
int     nnetpages = NNETPAGES;
E 9
I 9
D 11
int     nmbpages = NMBPAGES;
E 11
I 11
int     nmbclusters = NMBCLUSTERS;
I 20
D 22
int	nchsize = 60 + 3 * MAXUSERS;
E 22
E 20
I 13
D 15
#if	QUOTA
E 15
I 15
#ifdef QUOTA
E 15
D 26
int	nquota = (MAXUSERS * 9)/7 + 3;
int	ndquot = (MAXUSERS*NMOUNT)/4 + NPROC;
E 26
I 26
int	nquota = (MAXUSERS * 9) / 7 + 3;
int	ndquot = NINODE + (MAXUSERS * NMOUNT) / 4;
E 26
#endif
E 13
E 11
D 10
#ifdef INET
E 9
D 6
int     nwork = NWORK;
E 6
int     nnetcon = NCON;
int     nhost = NHOST;
D 9
#endif BBNNET
E 9
I 9
#endif INET
E 10
E 9
E 4
E 3

/*
 * These are initialized at bootstrap time
 * to values dependent on memory size
 */
int	nbuf, nswbuf;

/*
 * These have to be allocated somewhere; allocating
D 32
 * them here forces loader errors if this file is omitted.
E 32
I 32
 * them here forces loader errors if this file is omitted
 * (if they've been externed everywhere else; hah!).
E 32
 */
struct	proc *proc, *procNPROC;
struct	text *text, *textNTEXT;
struct	inode *inode, *inodeNINODE;
struct	file *file, *fileNFILE;
struct 	callout *callout;
struct	cblock *cfree;
D 4

E 4
struct	buf *buf, *swbuf;
D 33
short	*swsize;
int	*swpf;
E 33
char	*buffers;
struct	cmap *cmap, *ecmap;
I 20
D 32
struct	nch *nch;
E 32
I 32
struct	namecache *namecache;
E 32
E 20
I 13
D 15
#if	QUOTA
E 15
I 15
#ifdef QUOTA
E 15
struct	quota *quota, *quotaNQUOTA;
struct	dquot *dquot, *dquotNDQUOT;
#endif
E 13
I 4
D 9
#ifdef BBNNET
D 6
struct  pfree *freetab;
struct  work *workfree, *workNWORK;
E 6
struct  ucb *contab, *conNCON;
E 9
I 9
D 10
#ifdef INET
E 9
struct  host *host, *hostNHOST;
D 8
struct  net netcb;
E 8
struct  net_stat netstat;
struct  impstat imp_stat;
D 9
#endif BBNNET
E 9
I 9
#endif INET
E 10
E 9
E 4
E 1
