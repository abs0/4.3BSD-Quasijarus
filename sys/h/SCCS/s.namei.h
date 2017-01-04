h64483
s 00002/00000/00088
d D 7.2 88/01/05 16:42:37 bostic 17 16
c protect applications that include user.h from KERNEL #ifdef's.
e
s 00001/00001/00087
d D 7.1 86/06/04 23:25:43 mckusick 16 15
c 4.3BSD release version
e
s 00002/00000/00086
d D 6.12 86/03/28 11:47:22 mckusick 15 14
c ifdef KERNEL for kernel variables
e
s 00007/00005/00079
d D 6.11 86/02/20 21:03:30 karels 14 12
c rename nch to avoid name conflict
e
s 00008/00006/00078
d R 6.11 86/02/20 17:45:39 karels 13 12
c rename nch to avoid name collision 
e
s 00007/00001/00077
d D 6.10 85/06/08 15:02:36 mckusick 12 11
c Add copyright
e
s 00000/00001/00078
d D 6.9 85/03/07 19:55:51 karels 11 10
c garbage
e
s 00001/00000/00078
d D 6.8 85/02/15 16:24:30 mckusick 10 9
c add ni_endoff for shrinking directories (from kre)
e
s 00001/00001/00077
d D 6.7 84/08/28 17:29:23 bloom 9 8
c Change include paths.  No more ../h
e
s 00010/00004/00068
d D 6.6 84/07/08 16:03:20 mckusick 8 7
c comments; add provision for returning pathname buffers
e
s 00030/00007/00042
d D 6.5 84/07/08 15:47:45 mckusick 7 6
c rework `namei' interface to eliminate global variables
e
s 00011/00009/00038
d D 6.4 84/06/27 20:46:06 sam 6 5
c revise to hold soft references so . and .. can be held in cache
e
s 00013/00001/00034
d D 6.3 84/01/04 16:26:30 mckusick 5 4
c add namei statistics structure so that `vmstat' can summarize it
e
s 00019/00000/00016
d D 6.2 84/01/03 23:43:21 mckusick 4 3
c add system wide cacheing of path names in namei() (from kre)
e
s 00000/00000/00016
d D 6.1 83/07/29 06:13:18 sam 3 2
c 4.2 distribution
e
s 00006/00000/00010
d D 4.2 82/11/13 23:08:28 sam 2 1
c merge 4.1b and 4.1c
e
s 00010/00000/00000
d D 4.1 82/09/04 09:27:39 root 1 0
c date and time created 82/09/04 09:27:39 by root
e
u
U
f b 
t
T
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 16
 * Copyright (c) 1982 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 16
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12

D 7
struct namidata {
	int	ni_offset;
	int	ni_count;
	struct	inode *ni_pdir;
	struct	direct ni_dent;
E 7
I 7
#ifndef _NAMEI_
#define	_NAMEI_

#ifdef KERNEL
D 9
#include "../h/uio.h"
E 9
I 9
#include "uio.h"
E 9
#else
#include <sys/uio.h>
#endif

I 8
/*
 * Encapsulation of namei parameters.
 * One of these is located in the u. area to
 * minimize space allocated on the kernel stack.
 */
E 8
struct nameidata {
	caddr_t	ni_dirp;		/* pathname pointer */
I 8
	short	ni_nameiop;		/* see below */
	short	ni_error;		/* error return if any */
I 10
	off_t	ni_endoff;		/* end of useful stuff in directory */
E 10
E 8
	struct	inode *ni_pdir;		/* inode of parent directory of dirp */
D 8
	struct	iovec ni_iovec;
	struct	uio ni_uio;
E 8
I 8
D 11
	struct	buf *ni_pathbp;		/* unresolved pathname */
E 11
	struct	iovec ni_iovec;		/* MUST be pointed to by ni_iov */
	struct	uio ni_uio;		/* directory I/O parameters */
E 8
	struct	direct ni_dent;		/* current directory entry */
D 8
	short	ni_error;		/* error return if any */
	short	ni_nameiop;		/* see below */
E 8
E 7
};

D 7
enum nami_op { NAMI_LOOKUP, NAMI_CREATE, NAMI_DELETE };
E 7
I 7
#define	ni_base		ni_iovec.iov_base
#define	ni_count	ni_iovec.iov_len
#define	ni_iov		ni_uio.uio_iov
#define	ni_iovcnt	ni_uio.uio_iovcnt
#define	ni_offset	ni_uio.uio_offset
#define	ni_segflg	ni_uio.uio_segflg
#define	ni_resid	ni_uio.uio_resid
E 7
I 2

I 17
#ifdef KERNEL
E 17
D 7
/* this is temporary until the namei interface changes */
E 7
I 7
/*
D 14
 * namei opertions
E 14
I 14
 * namei operations and modifiers
E 14
 */
E 7
#define	LOOKUP		0	/* perform name lookup only */
#define	CREATE		1	/* setup for file creation */
#define	DELETE		2	/* setup for file deletion */
#define	LOCKPARENT	0x10	/* see the top of namei */
I 4
#define NOCACHE		0x20	/* name must not be left in cache */
I 7
#define FOLLOW		0x40	/* follow symbolic links */
#define	NOFOLLOW	0x0	/* don't follow symbolic links (pseudo) */
I 17
#endif
E 17
E 7

/*
 * This structure describes the elements in the cache of recent
 * names looked up by namei.
 */
D 5
#define	NCHNAMLEN	11	/* maximum name segment length we bother with */
E 5
I 5
D 6
#define	NCHNAMLEN	15	/* maximum name segment length we bother with */
E 6
E 5
D 14
struct	nch {
D 6
	struct	nch	*nc_forw, *nc_back;	/* hash chain, MUST BE FIRST */
	struct	nch	*nc_nxt, **nc_prev;	/* LRU chain */
	struct	inode	*nc_ip;			/* inode the name refers to */
	ino_t		 nc_ino;		/* ino of parent of name */
	dev_t		 nc_dev;		/* dev of parent of name */
	dev_t		 nc_idev;		/* dev of the name ref'd */
	char		 nc_nlen;		/* length of name */
	char		 nc_name[NCHNAMLEN];	/* segment name */
E 6
I 6
	struct	nch *nc_forw, *nc_back;	/* hash chain, MUST BE FIRST */
	struct	nch *nc_nxt, **nc_prev;	/* LRU chain */
E 14
I 14
struct	namecache {
	struct	namecache *nc_forw;	/* hash chain, MUST BE FIRST */
	struct	namecache *nc_back;	/* hash chain, MUST BE FIRST */
	struct	namecache *nc_nxt;	/* LRU chain */
	struct	namecache **nc_prev;	/* LRU chain */
E 14
	struct	inode *nc_ip;		/* inode the name refers to */
	ino_t	nc_ino;			/* ino of parent of name */
	dev_t	nc_dev;			/* dev of parent of name */
	dev_t	nc_idev;		/* dev of the name ref'd */
	long	nc_id;			/* referenced inode's id */
	char	nc_nlen;		/* length of name */
#define	NCHNAMLEN	15	/* maximum name segment length we bother with */
	char	nc_name[NCHNAMLEN];	/* segment name */
E 6
};
I 15
#ifdef KERNEL
E 15
D 14
struct	nch *nch;
E 14
I 14
struct	namecache *namecache;
E 14
int	nchsize;
I 15
#endif
E 15
I 5

/*
 * Stats on usefulness of namei caches.
 */
struct	nchstats {
	long	ncs_goodhits;		/* hits that we can reall use */
	long	ncs_badhits;		/* hits we must drop */
I 6
	long	ncs_falsehits;		/* hits with id mismatch */
E 6
	long	ncs_miss;		/* misses */
	long	ncs_long;		/* long names that ignore cache */
	long	ncs_pass2;		/* names found with passes == 2 */
	long	ncs_2passes;		/* number of times we attempt it */
};
I 7
#endif
E 7
E 5
E 4
E 2
E 1
