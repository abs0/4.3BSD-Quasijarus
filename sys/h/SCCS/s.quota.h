h44234
s 00010/00005/00145
d D 7.3 88/06/27 18:55:09 bostic 12 11
c install approved copyright notice
e
s 00008/00002/00142
d D 7.2 88/05/20 12:24:26 bostic 11 10
c add Berkeley specific header
e
s 00001/00001/00143
d D 7.1 86/06/04 23:27:02 mckusick 10 9
c 4.3BSD release version
e
s 00002/00002/00142
d D 6.3 85/10/28 15:04:19 karels 9 8
c use proper types for uids, gids
e
s 00007/00001/00137
d D 6.2 85/06/08 15:05:42 mckusick 8 7
c Add copyright
e
s 00000/00000/00138
d D 6.1 83/07/29 06:13:42 sam 7 6
c 4.2 distribution
e
s 00002/00006/00136
d D 4.6 83/05/27 16:15:52 sam 6 5
c move #ifdef's around for easier inclusion
e
s 00007/00004/00135
d D 4.5 83/05/24 10:26:23 sam 5 4
c retry #ifdef's so stuff can be included without #define QUOTA
e
s 00064/00042/00075
d D 4.4 83/05/21 23:18:40 sam 4 3
c make disk block fields long; cleanup
e
s 00024/00120/00093
d D 4.3 83/05/21 16:01:42 sam 3 2
c sorry robert; the devil made me do it (purge mush)
e
s 00003/00000/00210
d D 4.2 82/10/20 01:16:18 root 2 1
c lint
e
s 00210/00000/00000
d D 4.1 82/07/16 16:33:09 kre 1 0
c date and time created 82/07/16 16:33:09 by kre
e
u
U
f i 
t
T
I 1
D 3
/*	%M%	Melb %I%	%E%	*/
E 3
I 3
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 10
 * Copyright (c) 1982 Regents of the University of California.
E 10
I 10
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 10
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
E 11
 *
 *	%W% (Berkeley) %G%
 */
E 8
E 3

I 2
D 5
#ifdef QUOTA
E 5
E 2
/*
D 4
 *	Various junk to do with various quotas (etc) imposed upon
 *	the average user (big brother finally hits unix)
E 4
I 4
 * MELBOURNE DISC QUOTAS
E 4
 *
D 4
 *	The following structure exists in core for each logged on user
 *	It contains global junk relevant to that user's quotas
E 4
I 4
 * Various junk to do with various quotas (etc) imposed upon
 * the average user (big brother finally hits UNIX).
E 4
 *
D 4
 *	The u_quota field of each user struct contains a pointer to
 *	the quota struct relevant to the current process, this is changed
 *	by 'setuid' sys call, &/or by the Q_SETUID quota() call
E 4
I 4
 * The following structure exists in core for each logged on user.
 * It contains global junk relevant to that user's quotas.
 *
 * The u_quota field of each user struct contains a pointer to
 * the quota struct relevant to the current process, this is changed
 * by 'setuid' sys call, &/or by the Q_SETUID quota() call.
E 4
 */
D 3

typedef	long	class_t;

struct quinfo {
	u_short	qu_shares;	/* allocated shares (MUSH) */
	short	qu_plim;	/* process limit */
	long	qu_syflags;	/* system permission flags */
	float	qu_usage;	/* current resource usage (MUSH) */
	class_t	qu_class;	/* user classes (MUSH) */
};

E 3
D 5
#ifdef	KERNEL
E 5
I 5
D 6
#ifdef KERNEL
E 6
E 5
struct quota {
D 3
	struct	quota	*q_forw;	/* hash chain - MUST be first */
	struct	quota	*q_back;	/* hash chain - MUST be last */
	char	q_flg;			/* struct management flags */
	char	q_lcnt;			/* count of logins for user */
E 3
I 3
	struct	quota *q_forw, *q_back;	/* hash chain, MUST be first */
E 3
	short	q_cnt;			/* ref count (# processes) */
D 9
	short	q_uid;			/* real uid of owner */
E 9
I 9
	uid_t	q_uid;			/* real uid of owner */
E 9
D 3
	short	q_nice;			/* nice added to p_cpu (MUSH) */
	short	q_acnt;			/* count of 'at' processes (MUSH) */
	union	{
		struct	{
			long	Q_rate;	/* recent work rate (MUSH) */
			long	Q_cost;	/* cost in recent period (MUSH) */
		} q_s1;
		struct	{
			struct quota *Q_freef;
			struct quota **Q_freeb;
		} q_s2;
	} q_u;
	struct	quinfo q_uinfo;		/* user limits & usage (MUSH) */
E 3
I 3
D 4
	char	q_flg;			/* struct management flags */
E 4
I 4
	int	q_flags;		/* struct management flags */
E 4
#define	Q_LOCK	0x01		/* quota struct locked (for disc i/o) */
#define	Q_WANT	0x02		/* issue a wakeup when lock goes off */
#define	Q_NEW	0x04		/* new quota - no proc1 msg sent yet */
#define	Q_NDQ	0x08		/* account has NO disc quota */
	struct	quota *q_freef, **q_freeb;
E 3
	struct	dquot *q_dq[NMOUNT];	/* disc quotas for mounted filesys's */
};
D 4
#define	NOQUOT	((struct quota *) 0)
D 3
#define	q_rate		q_u.q_s1.Q_rate
#define	q_cost		q_u.q_s1.Q_cost
#define	q_freef		q_u.q_s2.Q_freef
#define	q_freeb		q_u.q_s2.Q_freeb
#define	q_shares	q_uinfo.qu_shares
#define	q_plim		q_uinfo.qu_plim
#define	q_syflags	q_uinfo.qu_syflags
#define	q_usage		q_uinfo.qu_usage
#define	q_class		q_uinfo.qu_class
E 3
#endif
E 4

I 5
D 6
#ifdef QUOTA
E 6
E 5
D 3
#define	QF_KASYNC	0x02		/* kill async procs at logout */
#define	QF_FASTTY	0x04		/* permitted to raise tty speed */
#define	QF_NASYNC	0x08		/* nice async procs at logout */
#define	QF_MODTTY	0x10		/* permitted to modify other tty */
#define	QF_UMASK	0x20		/* not permitted to alter umask */

E 3
D 4
#ifdef	KERNEL
E 4
I 4
#define	NOQUOTA	((struct quota *) 0)

I 6
#if defined(KERNEL) && defined(QUOTA)
E 6
E 4
D 3
struct quota *quota, *quotaNQUOTA;
E 3
I 3
struct	quota *quota, *quotaNQUOTA;
E 3
int	nquota;
D 3
struct quota *getquota(), *qfind();
E 3
I 3
struct	quota *getquota(), *qfind();
E 3
#endif
I 5
D 6
#endif
E 6
E 5

D 3
/*	q_flg flags	*/
#define	Q_LOCK		0x01		/* quota struct locked (for disc i/o) */
#define	Q_WANT		0x02		/* issue a wakeup when lock goes off */
#define	Q_NEW		0x04		/* new quota - no proc1 msg sent yet */
#define	Q_NDQ		0x08		/* account has NO disc quota */

E 3
/*
D 4
 *	The following structure defines the format of the disc quota file
 *	(as it appears on disc) - the file is an array of these structures
 *	indexed by user number. A sys call (setquota) establishes the
 *	inode for each applicable file (a pointer is retained in the mount
 *	structure)
E 4
I 4
 * The following structure defines the format of the disc quota file
 * (as it appears on disc) - the file is an array of these structures
 * indexed by user number.  The setquota sys call establishes the inode
 * for each quota file (a pointer is retained in the mount structure).
E 4
 *
D 4
 *	nb: warning fields contain the number of warnings left before
 *		allocation is halted completely
E 4
I 4
 * The following constants define the number of warnings given a user
 * before the soft limits are treated as hard limits (usually resulting
 * in an allocation failure).  The warnings are normally manipulated
 * each time a user logs in through the Q_DOWARN quota call.  If
 * the user logs in and is under the soft limit the warning count
 * is reset to MAX_*_WARN, otherwise a message is printed and the
 * warning count is decremented.  This makes MAX_*_WARN equivalent to
 * the number of logins before soft limits are treated as hard limits.
E 4
 */
D 3

E 3
D 4
typedef	unsigned short	dlim_t;

struct	dqblk {
	dlim_t	dqb_ilim;	/* max num allocated inodes + 1 */
	dlim_t	dqb_iq;		/* preferred inode limit */
	dlim_t	dqb_inod;	/* current num allocated inodes */
	dlim_t	dqb_iwarn;	/* # warnings about excessive inodes */
E 4
I 3
#define	MAX_IQ_WARN	3
E 3
D 4
	dlim_t	dqb_blim;	/* abs limit on disc blks alloc */
	dlim_t	dqb_quot;	/* preferred limit on disc blks */
	dlim_t	dqb_blks;	/* current block count */
	dlim_t	dqb_dwarn;	/* # warnings about excessive disc use */
E 4
D 3
};
#define	MAX_IQ_WARN	3
E 3
#define	MAX_DQ_WARN	3
I 4

struct	dqblk {
	u_long	dqb_bhardlimit;	/* absolute limit on disc blks alloc */
	u_long	dqb_bsoftlimit;	/* preferred limit on disc blks */
	u_long	dqb_curblocks;	/* current block count */
	u_short	dqb_ihardlimit;	/* maximum # allocated inodes + 1 */
	u_short	dqb_isoftlimit;	/* preferred inode limit */
	u_short	dqb_curinodes;	/* current # allocated inodes */
	u_char	dqb_bwarn;	/* # warnings left about excessive disc use */
	u_char	dqb_iwarn;	/* # warnings left about excessive inodes */
E 4
I 3
};
E 3

/*
D 4
 *	The following structure records disc usage for a user on a filesystem
 *	There is one allocated for each quota that exists on any filesystem
 *	for the current user. A cache is kept of other recently used entries.
E 4
I 4
 * The following structure records disc usage for a user on a filesystem.
 * There is one allocated for each quota that exists on any filesystem
 * for the current user. A cache is kept of other recently used entries.
E 4
 */
D 3

E 3
struct	dquot {
D 3
	struct	dquot	*dq_forw;	/* MUST be first entry */
	struct	dquot	*dq_back;	/* MUST be second entry */
E 3
I 3
	struct	dquot *dq_forw, *dq_back;/* MUST be first entry */
E 3
	union	{
D 3
		struct quota *Dq_own;	/* the quota that points to this */
		struct {
			struct dquot *Dq_freef;	/* forward free chain ptr */
			struct dquot **Dq_freeb;/* backward free chain ptr */
E 3
I 3
		struct	quota *Dq_own;	/* the quota that points to this */
		struct {		/* free list */
			struct	dquot *Dq_freef, **Dq_freeb;
E 3
		} dq_f;
	} dq_u;
D 4
	short	dq_flg;
E 4
I 4
	short	dq_flags;
E 4
I 3
#define	DQ_LOCK		0x01		/* this quota locked (no MODS) */
#define	DQ_WANT		0x02		/* wakeup on unlock */
#define	DQ_MOD		0x04		/* this quota modified since read */
#define	DQ_FAKE		0x08		/* no limits here, just usage */
#define	DQ_BLKS		0x10		/* has been warned about blk limit */
#define	DQ_INODS	0x20		/* has been warned about inode limit */
E 3
	short	dq_cnt;			/* count of active references */
D 9
	short	dq_uid;			/* user this applies to */
E 9
I 9
	uid_t	dq_uid;			/* user this applies to */
E 9
	dev_t	dq_dev;			/* filesystem this relates to */
	struct dqblk dq_dqb;		/* actual usage & quotas */
};
I 5

D 6
#ifdef QUOTA
E 6
E 5
#define	dq_own		dq_u.Dq_own
#define	dq_freef	dq_u.dq_f.Dq_freef
#define	dq_freeb	dq_u.dq_f.Dq_freeb
D 4
#define	dq_ilim		dq_dqb.dqb_ilim
#define	dq_iq		dq_dqb.dqb_iq
#define	dq_inod		dq_dqb.dqb_inod
E 4
I 4
#define	dq_bhardlimit	dq_dqb.dqb_bhardlimit
#define	dq_bsoftlimit	dq_dqb.dqb_bsoftlimit
#define	dq_curblocks	dq_dqb.dqb_curblocks
#define	dq_ihardlimit	dq_dqb.dqb_ihardlimit
#define	dq_isoftlimit	dq_dqb.dqb_isoftlimit
#define	dq_curinodes	dq_dqb.dqb_curinodes
#define	dq_bwarn	dq_dqb.dqb_bwarn
E 4
#define	dq_iwarn	dq_dqb.dqb_iwarn
D 4
#define	dq_blim		dq_dqb.dqb_blim
#define	dq_quot		dq_dqb.dqb_quot
#define	dq_blks		dq_dqb.dqb_blks
#define	dq_dwarn	dq_dqb.dqb_dwarn
E 4
I 4

E 4
#define	NODQUOT		((struct dquot *) 0)
#define	LOSTDQUOT	((struct dquot *) 1)

D 5
#ifdef	KERNEL
E 5
I 5
D 6
#ifdef KERNEL
E 6
I 6
#if defined(KERNEL) && defined(QUOTA)
E 6
E 5
D 3
struct	dquot	*dquot, *dquotNDQUOT;
E 3
I 3
struct	dquot *dquot, *dquotNDQUOT;
E 3
int	ndquot;
D 3
struct	dquot	*discquota(), *inoquota(), *dqalloc();
E 3
I 3
struct	dquot *discquota(), *inoquota(), *dqalloc(), *dqp();
E 3
D 6
#endif
E 6
I 5
#endif
E 5

D 3
/*	dq_flg flags	*/
#define	DQ_LOCK		0x01		/* this quota locked (no MODS) */
#define	DQ_WANT		0x02		/* wakeup on unlock */
#define	DQ_MOD		0x04		/* this quota modified since read */
#define	DQ_FAKE		0x08		/* no limits here, just usage */
#define	DQ_BLKS		0x10		/* has been warned about blk limit */
#define	DQ_INODS	0x20		/* has been warned about inode limit */

E 3
/*
D 4
 * Commands for the 'quota' system call
E 4
I 4
 * Definitions for the 'quota' system call.
E 4
 */
#define	Q_SETDLIM	1	/* set disc limits & usage */
#define	Q_GETDLIM	2	/* get disc limits & usage */
#define	Q_SETDUSE	3	/* set disc usage only */
D 4
#define	Q_SYNC		4	/* update disc copy if quota usages */
E 4
I 4
#define	Q_SYNC		4	/* update disc copy of quota usages */
E 4
D 3
#define	Q_LOGIN		5	/* Count this as a login process */
#define	Q_LCOUNT	6	/* get count of login processes */
#define	Q_PCOUNT	7	/* get count of processes */
#define	Q_USAGE		8	/* get current usage */
#define	Q_SFLAGS	9	/* set system flags */
#define	Q_SUSAGE	10	/* set usage */
#define	Q_SPLIMIT	11	/* set process limit */
#define	Q_ISLOGIN	12	/* is this a login process ?? */
#define	Q_SCLASS	13	/* set user class */
#define	Q_SCURCL	14	/* set current system classes */
#define	Q_GCURCL	15	/* get current system classes */
E 3
#define	Q_SETUID	16	/* change proc to use quotas for uid */
D 3
#define	Q_FLOGIN	17	/* "fake" login (counts as 1, but isn't) */
#define	Q_SETCOST	18	/* set system charge rates */
#define	Q_GETCOST	19	/* get system charge rates */
#define	Q_SSHARE	20	/* set shares */
#define	Q_SUINFO	21	/* set user info */
#define	Q_GUINFO	22	/* get user info */
#define	Q_ATJOB		23	/* this process is an 'at' job (background) */
#define	Q_ACOUNT	24	/* return count of procs descended from ATJ */
E 3
#define	Q_SETWARN	25	/* alter inode/block warning counts */
#define	Q_DOWARN	26	/* warn user about excessive space/inodes */
I 4

/*
 * Used in Q_SETDUSE.
 */
struct	dqusage {
	u_short	du_curinodes;
	u_long	du_curblocks;
};

/*
 * Used in Q_SETWARN.
 */
struct	dqwarn {
	u_char	dw_bwarn;
	u_char	dw_iwarn;
};
E 4
D 3
#define	Q_KILL		27	/* send signal to procs attatched to quota */
#define	Q_NICE		28	/* set niceness for procs attatched to quota */

/*
 * current class information
 *
 *	records sched biasing for classes that are to have priority
 *	enhanced or degraded
 */

#define	NCLASS	8

struct qclass {
	class_t	class;		/* classes this applies to */
	long	cost;		/* +/- mod to cost incurred */
	short	maxn;		/* in this class, no nice > this */
	short	minn;		/* in this class, no nice < this */
};

#ifdef	KERNEL
struct	qclass	curclass[NCLASS];
E 3
D 5
#endif
E 5
D 3

/*
 * Flag definitions for u_qflags in user struct (u_qflags)
 */
#define	QUF_LOGIN	0x0001		/* this process incremented login cnt */
#define	QUF_ATJ		0x0002		/* this process descended from atrun */
I 2

#endif QUOTA
E 3
E 2
E 1
