h36049
s 00002/00000/00016
d R 5.2 88/01/22 16:25:42 bostic 7 6
c add MTAB define of "/etc/mtab"
e
s 00007/00001/00009
d D 5.1 85/05/30 09:37:12 dist 6 5
c Add copyright
e
s 00001/00001/00009
d D 4.4 83/05/28 12:59:41 sam 5 4
c too much, put it back
e
s 00002/00004/00008
d D 4.3 83/05/28 11:56:49 sam 4 3
c use define from fs.h
e
s 00007/00001/00005
d D 4.2 83/05/28 11:54:35 sam 3 1
c fix to hold max path length possible and mount type
e
s 00007/00001/00005
d R 4.2 83/05/28 11:51:39 sam 2 1
c redefine to hold largest possible pathname and also type
e
s 00006/00000/00000
d D 4.1 83/05/03 13:48:06 sam 1 0
c date and time created 83/05/03 13:48:06 by sam
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6

I 3
/*
D 4
 * Mounted device accouting file.
 * The size of m_path is the same
 * as MAXMNTLEN in <sys/fs.h>
E 4
I 4
 * Mounted device accounting file.
E 4
 */
E 3
struct mtab {
D 3
	char	m_path[32];		/* mounted on pathname */
E 3
I 3
D 4
	char	m_path[512];		/* mounted on pathname */
E 4
I 4
D 5
	char	m_path[MAXMNTLEN];	/* mounted on pathname */
E 5
I 5
	char	m_path[32];		/* mounted on pathname */
E 5
E 4
E 3
	char	m_dname[32];		/* block device pathname */
I 3
	char	m_type[4];		/* read-only, quotas */
E 3
};
E 1
