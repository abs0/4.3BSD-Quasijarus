h59561
s 00001/00001/00083
d D 5.2 85/06/06 13:10:03 edward 7 6
c cleaning up after bozos
e
s 00007/00001/00077
d D 5.1 85/06/04 11:12:16 dist 6 5
c Add copyright
e
s 00001/00005/00077
d D 4.5 84/12/13 14:40:29 edward 5 4
c performance
e
s 00002/00002/00080
d D 4.4 83/02/09 14:18:02 sam 4 3
c cleanups from sun
e
s 00004/00004/00078
d D 4.3 83/02/03 09:13:13 sam 3 2
c use high precision time calls
e
s 00001/00003/00081
d D 4.2 82/12/30 17:35:46 sam 2 1
c finally works (updated for 4.1c and merged with sun)
e
s 00084/00000/00000
d D 4.1 80/10/09 12:41:42 bill 1 0
c date and time created 80/10/09 12:41:42 by bill
e
u
U
t
T
I 1
D 5
/* %M% %I% %G% */
E 5
I 5
D 6
/* %W% (Berkeley) %G% */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
E 7
I 7
 * All rights reserved.  The Berkeley Software License Agreement
E 7
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6
E 5

/*
 * C shell - process structure declarations
 */

/*
 * Structure for each process the shell knows about:
 *	allocated and filled by pcreate.
 *	flushed by pflush; freeing always happens at top level
 *	    so the interrupt level has less to worry about.
 *	processes are related to "friends" when in a pipeline;
 *	    p_friends links makes a circular list of such jobs
 */
struct process	{
	struct	process *p_next;	/* next in global "proclist" */
	struct	process	*p_friends;	/* next in job list (or self) */
	struct	directory *p_cwd;	/* cwd of the job (only in head) */
	short	unsigned p_flags;	/* various job status flags */
	char	p_reason;		/* reason for entering this state */
	char	p_index;		/* shorthand job index */
D 4
	short	p_pid;
	short	p_jobid;		/* pid of job leader */
E 4
I 4
	int	p_pid;
	int	p_jobid;		/* pid of job leader */
E 4
	/* if a job is stopped/background p_jobid gives its pgrp */
D 3
	time_t	p_btime;		/* begin time */
	time_t	p_etime;		/* end time */
	long	p_stime;		/* system cpu time */
	long	p_utime;		/* user cpu time */
E 3
I 3
	struct	timeval p_btime;	/* begin time */
	struct	timeval p_etime;	/* end time */
E 3
D 2
#ifdef VMUNIX
	struct	vtimes p_vtimes;
#endif
E 2
I 2
	struct	rusage p_rusage;
I 3
D 5
	long	p_utime;	/* XXX */
	long	p_stime;	/* XXX */
E 5
E 3
E 2
	char	*p_command;		/* first PMAXLEN chars of command */
};

/* flag values for p_flags */
#define	PRUNNING	(1<<0)		/* running */
#define	PSTOPPED	(1<<1)		/* stopped */
#define	PNEXITED	(1<<2)		/* normally exited */
#define	PAEXITED	(1<<3)		/* abnormally exited */
#define	PSIGNALED	(1<<4)		/* terminated by a signal != SIGINT */

#define	PALLSTATES	(PRUNNING|PSTOPPED|PNEXITED|PAEXITED|PSIGNALED|PINTERRUPTED)
#define	PNOTIFY		(1<<5)		/* notify async when done */
#define	PTIME		(1<<6)		/* job times should be printed */
#define	PAWAITED	(1<<7)		/* top level is waiting for it */
#define	PFOREGND	(1<<8)		/* started in shells pgrp */
#define	PDUMPED		(1<<9)		/* process dumped core */
#define	PDIAG		(1<<10)		/* diagnostic output also piped out */
#define	PPOU		(1<<11)		/* piped output */
#define	PREPORTED	(1<<12)		/* status has been reported */
#define	PINTERRUPTED	(1<<13)		/* job stopped via interrupt signal */
#define	PPTIME		(1<<14)		/* time individual process */
#define	PNEEDNOTE	(1<<15)		/* notify as soon as practical */

#define	PNULL		(struct process *)0
#define	PMAXLEN		80

/* defines for arguments to pprint */
#define	NUMBER		01
#define	NAME		02
#define	REASON		04
#define	AMPERSAND	010
#define	FANCY		020
#define	SHELLDIR	040		/* print shell's dir if not the same */
#define	JOBDIR		0100		/* print job's dir if not the same */
#define	AREASON		0200

struct	process	proclist;		/* list head of all processes */
bool	pnoprocesses;			/* pchild found nothing to wait for */

struct	process *pholdjob;		/* one level stack of current jobs */

struct	process *pcurrjob;		/* current job */
struct	process	*pcurrent;		/* current job in table */
struct	process *pprevious;		/* previous job in table */

short	pmaxindex;			/* current maximum job index */
D 5

bool	timesdone;			/* shtimes buffer full ? */
E 5

int	psigint();
struct	process	*pgetcurr();
struct	process	*plookup();
struct	process *pfind();
E 1
