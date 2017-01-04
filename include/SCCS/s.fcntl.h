h02050
s 00011/00010/00029
d D 5.2 86/01/08 18:20:43 lepreau 5 4
c make dup defs from file.h be textually the same so cpp doesn't bitch.
c Probably ought to #infdef them but that would mean changing file.h too.
e
s 00007/00001/00032
d D 5.1 85/05/30 09:35:54 dist 4 3
c Add copyright
e
s 00006/00000/00027
d D 4.3 85/05/22 18:18:18 mckusick 3 2
c add missing modes
e
s 00009/00002/00018
d D 4.2 83/09/25 14:21:00 karels 2 1
c flags for F_[SG]ETFL
e
s 00020/00000/00000
d D 4.1 83/07/03 00:36:52 sam 1 0
c date and time created 83/07/03 00:36:52 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

/*
D 5
 * Flag values accessible to open(2) and fcntl(2)
 *  (The first three can only be set by open)
E 5
I 5
 * Flag values accessible to open(2) and fcntl(2)-- copied from
 * <sys/file.h>.  (The first three can only be set by open.)
E 5
 */
D 5
#define	O_RDONLY	0
#define	O_WRONLY	1
#define	O_RDWR		2
D 2
#define	O_NDELAY	04	/* Non-blocking I/O */
#define	O_APPEND	010	/* append (writes guaranteed at the end) */
E 2
I 2
#define	O_NDELAY	FNDELAY	/* Non-blocking I/O */
#define	O_APPEND	FAPPEND	/* append (writes guaranteed at the end) */
I 3
#define	O_CREAT		FCREAT	/* open with file create */
#define	O_TRUNC		FTRUNC	/* open with truncation */
#define	O_EXCL		FEXCL	/* error on create if file exists */
E 5
I 5
#define	O_RDONLY	000		/* open for reading */
#define	O_WRONLY	001		/* open for writing */
#define	O_RDWR		002		/* open for read & write */
#define	O_NDELAY	FNDELAY		/* non-blocking open */
					/* really non-blocking I/O for fcntl */
#define	O_APPEND	FAPPEND		/* append on each write */
#define	O_CREAT		FCREAT		/* open with file create */
#define	O_TRUNC		FTRUNC		/* open with truncation */
#define	O_EXCL		FEXCL		/* error on create if file exists */
E 5
E 3
E 2

I 2
#ifndef	F_DUPFD
E 2
/* fcntl(2) requests */
#define	F_DUPFD	0	/* Duplicate fildes */
#define	F_GETFD	1	/* Get fildes flags */
#define	F_SETFD	2	/* Set fildes flags */
#define	F_GETFL	3	/* Get file flags */
#define	F_SETFL	4	/* Set file flags */
#define	F_GETOWN 5	/* Get owner */
#define F_SETOWN 6	/* Set owner */
I 2

/* flags for F_GETFL, F_SETFL-- copied from <sys/file.h> */
#define	FNDELAY		00004		/* non-blocking reads */
#define	FAPPEND		00010		/* append on each write */
#define	FASYNC		00100		/* signal pgrp when data ready */
I 3
#define	FCREAT		01000		/* create if nonexistant */
#define	FTRUNC		02000		/* truncate to zero length */
#define	FEXCL		04000		/* error if already created */
E 3
#endif
E 2
E 1
