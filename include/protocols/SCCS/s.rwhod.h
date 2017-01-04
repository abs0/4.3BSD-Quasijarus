h36304
s 00007/00001/00027
d D 5.1 85/05/28 15:34:36 dist 9 8
c Add copyright
e
s 00000/00002/00028
d D 4.8 83/06/01 16:17:55 sam 8 7
c notyet has come
e
s 00002/00000/00028
d D 4.7 83/05/25 15:18:30 sam 7 6
c back out for now
e
s 00007/00001/00021
d D 4.6 83/05/22 23:30:10 root 6 5
c backwards compatible 
e
s 00003/00001/00019
d D 4.5 83/05/05 11:13:30 sam 5 4
c add version field
e
s 00013/00008/00007
d D 4.4 83/05/04 16:29:58 sam 4 3
c add type field to allow protocol expansio
e
s 00002/00000/00013
d D 4.3 82/12/24 21:05:46 sam 3 2
c port not byte swapped; no more asm.sed; 
c move spool area to /usr/spool/rwho so /etc is always changing
e
s 00001/00001/00012
d D 4.2 82/11/14 15:18:01 sam 2 1
c convert to 4.1c sys calls and directory layout
e
s 00013/00000/00000
d D 4.1 82/04/02 10:29:13 wnj 1 0
c date and time created 82/04/02 10:29:13 by wnj
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9

I 4
/*
 * rwho protocol packet format.
 */
I 6
struct	outmp {
	char	out_line[8];		/* tty name */
	char	out_name[8];		/* user id */
	long	out_time;		/* time on */
};

E 6
E 4
struct	whod {
I 7
D 8
#ifdef notyet
E 8
E 7
I 5
	char	wd_vers;		/* protocol version # */
E 5
D 4
	int	wd_sendtime;
	int	wd_recvtime;
	char	wd_hostname[32];
	int	wd_loadav[3];
D 2
	int	wd_bootime;
E 2
I 2
	int	wd_boottime;
E 4
I 4
	char	wd_type;		/* packet type, see below */
D 5
	char	wd_pad[3];
E 5
I 5
	char	wd_pad[2];
I 7
D 8
#endif
E 8
E 7
E 5
	int	wd_sendtime;		/* time stamp by sender */
	int	wd_recvtime;		/* time stamp applied by receiver */
	char	wd_hostname[32];	/* hosts's name */
	int	wd_loadav[3];		/* load average as in uptime */
	int	wd_boottime;		/* time system booted */
E 4
E 2
	struct	whoent {
D 4
		struct	utmp we_utmp;
		int	we_idle;
E 4
I 4
D 6
		struct	utmp we_utmp;	/* active tty info */
E 6
I 6
		struct	outmp we_utmp;	/* active tty info */
E 6
		int	we_idle;	/* tty idle time */
E 4
	} wd_we[1024 / sizeof (struct whoent)];
};
I 3

I 5
#define	WHODVERSION	1
E 5
D 4
#define	RWHODIR	"/usr/spool/rwho"	/* where data is stored */
E 4
I 4
#define	WHODTYPE_STATUS	1		/* host status */
E 4
E 3
E 1
