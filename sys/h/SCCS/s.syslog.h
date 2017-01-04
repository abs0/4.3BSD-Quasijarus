h11202
s 00010/00005/00076
d D 7.10 88/06/27 18:42:06 bostic 23 22
c install approved copyright notice
e
s 00009/00003/00072
d D 7.9 88/06/06 09:42:01 bostic 22 21
c add Berkeley specific header
e
s 00009/00000/00066
d D 7.8 88/05/26 09:02:23 karels 21 20
c add FAC, PRI, MAKEPRI macros; add LOG_PRINTF for diskerr
e
s 00000/00000/00066
d D 7.7 87/04/20 12:13:05 karels 20 19
x 19
c put back "obsolete cruft" again! (eric: don't delete it this time,
c routed was broken by your change!  logmask takes a mask, not a pri.)
e
s 00000/00000/00060
d D 7.6 86/11/24 19:20:51 eric 19 18
x 18
c no it isn't.... routed was broken.  Honest!
e
s 00006/00000/00060
d D 7.5 86/11/15 17:19:54 sam 18 17
c put back "obsolete cruft" -- it's used
e
s 00001/00000/00059
d D 7.4 86/11/13 18:15:18 eric 17 16
c add facility for UUCP
e
s 00001/00007/00058
d D 7.3 86/11/12 19:21:57 eric 16 15
c remove obsolete cruft
e
s 00001/00000/00064
d D 7.2 86/10/23 16:49:54 eric 15 14
c add network news subsystem facility
e
s 00001/00001/00063
d D 7.1 86/06/04 23:28:36 mckusick 14 13
c 4.3BSD release version
e
s 00001/00001/00063
d D 4.12 86/03/28 14:59:21 karels 13 12
c priorities, priorities
e
s 00005/00004/00059
d D 4.11 86/03/21 10:48:40 karels 12 11
c add LOG_NOWAIT
e
s 00007/00001/00056
d D 4.10 86/02/16 20:42:33 karels 11 10
c macros for masks
e
s 00001/00000/00056
d D 4.9 85/11/17 11:32:02 eric 10 9
c add LOG_LPR facility
e
s 00004/00000/00052
d D 4.8 85/10/13 15:20:29 eric 9 8
c add LOG_NDELAY
e
s 00002/00001/00050
d D 4.7 85/10/12 23:07:04 eric 8 7
c added LOG_SYSLOG facility for internally generated messages
e
s 00029/00039/00022
d D 4.6 85/09/17 18:02:35 eric 7 6
c extensive mods to add facilities
e
s 00007/00001/00054
d D 4.5 85/06/08 15:08:47 mckusick 6 5
c Add copyright
e
s 00001/00001/00054
d D 4.4 85/02/25 14:39:45 karels 5 4
c LOG_WARN -> LOG_WARNING
e
s 00044/00046/00011
d D 4.3 85/01/31 17:01:21 ralph 4 2
c added kernel priorities, range is now 1 - 31.
e
s 00001/00000/00057
d R 4.3 84/05/04 14:28:11 ralph 3 2
c added LOG_STAYOPEN flag to keep socket open after execve(2).
e
s 00002/00018/00055
d D 4.2 84/04/25 11:43:21 ralph 2 1
c version for UNIX domain sockets
e
s 00073/00000/00000
d D 4.1 83/05/27 11:11:47 sam 1 0
c date and time created 83/05/27 11:11:47 by sam
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
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
D 22
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 22
I 22
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 23
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 23
I 23
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
E 23
E 22
 *
 *	%W% (Berkeley) %G%
 */
E 6

/*
D 4
 *  SYSLOG.H -- declarations for system logging program
E 4
I 4
D 7
 *  Declarations for system logging program
E 4
 *
D 4
 *	These are used as the first parameter to logmsg().
 *	Their meanings are approximately as follows:
 *
 *	LOG_ALERT -- this priority should essentially never
 *		be used.  It applies only to messages that
 *		are so important that every user should be
 *		aware of them, e.g., a serious hardware failure.
 *	LOG_SALERT -- messages of this priority should be
 *		issued only when immediate attention is needed
 *		by a qualified system person, e.g., when some
 *		valuable system resource dissappears.  They get
 *		sent to a list of system people.
 *	LOG_EMERG -- Emergency messages are not sent to users,
 *		but represent major conditions.  An example
 *		might be hard disk failures.  These could be
 *		logged in a separate file so that critical
 *		conditions could be easily scanned.
 *	LOG_ERR -- these represent error conditions, such as soft
 *		disk failures, etc.
 *	LOG_CRIT -- such messages contain critical information,
 *		but which can not be classed as errors, for example,
 *		'su' attempts.
 *	LOG_WARNING -- issued when an abnormal condition has been
 *		detected, but recovery can take place.
 *	LOG_NOTICE -- something that falls in the class of
 *		"important information"; this class is informational
 *		but important enough that you don't want to throw
 *		it away casually.
 *	LOG_INFO -- information level messages.  These messages
 *		could be thrown away without problems, but should
 *		be included if you want to keep a close watch on
 *		your system.
 *	LOG_DEBUG -- it may be useful to log certain debugging
 *		information.  Normally this will be thrown away.
E 4
I 4
 *	These are used as the first parameter to syslog().
E 7
I 7
 *  Facility codes
E 7
E 4
 */

D 2
/* some configuration parameters..... */
#define LOG_IPC				/* set if using 4.2 IPC, else mpx */
#define LOG_HOST 	"localhost"	/* name of host to log on */

E 2
D 4
/* defines for priorities */
#define	LOG_ALERT	1	/* alert -- send to all users */
#define	LOG_SALERT	2	/* subalert -- send to special users */
#define	LOG_EMERG	3	/* emergency conditions */
#define	LOG_ERROR	4	/* error */
#define	LOG_ERR		4	/* synonym of LOG_ERROR */
#define	LOG_CRIT	5	/* critical information */
#define	LOG_WARNING	6	/* warning */
#define	LOG_NOTICE	7	/* important information */
#define	LOG_INFO	8	/* informational message */
#define	LOG_DEBUG	9	/* debug level info */
E 4
I 4
D 7
	/* kernel priorities */
#define	KERN_EMERG	1	/* emergency -- send to all users (wall) */
#define	KERN_ALERT	2	/* alert -- system failure */
#define	KERN_ERR	3	/* hard errors */
#define	KERN_FAIL	4	/* table full/overflow */
#define	KERN_RECOV	5	/* recoverable errors (softecc) */
#define	KERN_INFO	6	/* inconsistency/configuration error */
E 7
I 7
#define LOG_KERN	(0<<3)	/* kernel messages */
#define LOG_USER	(1<<3)	/* random user-level messages */
#define LOG_MAIL	(2<<3)	/* mail system */
#define LOG_DAEMON	(3<<3)	/* system daemons */
#define LOG_AUTH	(4<<3)	/* security/authorization messages */
D 8
	/* codes 5 - 15 reserved for system use */
E 8
I 8
#define LOG_SYSLOG	(5<<3)	/* messages generated internally by syslogd */
I 10
#define LOG_LPR		(6<<3)	/* line printer subsystem */
I 15
#define LOG_NEWS	(7<<3)	/* network news subsystem */
I 17
#define LOG_UUCP	(8<<3)	/* UUCP subsystem */
E 17
E 15
E 10
	/* other codes through 15 reserved for system use */
E 8
#define LOG_LOCAL0	(16<<3)	/* reserved for local use */
#define LOG_LOCAL1	(17<<3)	/* reserved for local use */
#define LOG_LOCAL2	(18<<3)	/* reserved for local use */
#define LOG_LOCAL3	(19<<3)	/* reserved for local use */
#define LOG_LOCAL4	(20<<3)	/* reserved for local use */
#define LOG_LOCAL5	(21<<3)	/* reserved for local use */
#define LOG_LOCAL6	(22<<3)	/* reserved for local use */
#define LOG_LOCAL7	(23<<3)	/* reserved for local use */
E 7
E 4

I 4
D 7
	/* user abnormal conditions priorities */
#define	LOG_EMERG	7	/* system unusable -- send to all users */
#define	LOG_ALERT	8	/* missing files (e.g., /etc/utmp) */
#define	LOG_CRIT	9	/* critical conditions */
#define	LOG_ERR		10	/* init open faliures/fatal daemon errors */
#define	LOG_FAIL	11	/* getty failing, interface dropped */
D 5
#define	LOG_WARN	12	/* non-fatal daemon errs */
E 5
I 5
#define	LOG_WARNING	12	/* non-fatal daemon errs */
E 7
I 7
#define LOG_NFACILITIES	24	/* maximum number of facilities */
#define LOG_FACMASK	0x03f8	/* mask to extract facility part */
E 7
E 5

I 21
#define LOG_FAC(p)	(((p) & LOG_FACMASK) >> 3)	/* facility of pri */

E 21
D 7
	/* user priorities */
#define	LOG_SALERT	13	/* important information */
#define	LOG_SECURITY	14	/* root/su logins */
#define	LOG_FIXED	15	/* abnormal condition fixed (recovery action) */
#define	LOG_MAIL	16	/* mail failures */
#define	LOG_REJECT	17	/* login/daemon rejections */
#define	LOG_NOTICE	18	/* important info */
E 7
I 7
/*
 *  Priorities (these are ordered)
 */
E 7

D 7
	/* user information priorities */
#define	LOG_INFO	19	/* informational message */
#define	LOG_INFO1	20	/* informational message */
#define	LOG_INFO2	21	/* informational message */
#define	LOG_INFO3	22	/* informational message */
#define	LOG_INFO4	23	/* informational message */
#define	LOG_INFO5	24	/* informational message */
E 7
I 7
#define LOG_EMERG	0	/* system is unusable */
#define LOG_ALERT	1	/* action must be taken immediately */
#define LOG_CRIT	2	/* critical conditions */
#define LOG_ERR		3	/* error conditions */
#define LOG_WARNING	4	/* warning conditions */
#define LOG_NOTICE	5	/* normal but signification condition */
#define LOG_INFO	6	/* informational */
#define LOG_DEBUG	7	/* debug-level messages */
E 7

D 7
	/* user debug/local priorities */
#define	LOG_DEBUG	25	/* debugging info */
#define	LOG_LOCAL1	26	/* reserved for local use */
#define	LOG_LOCAL2	27	/* reserved for local use */
#define	LOG_LOCAL3	28	/* reserved for local use */
#define	LOG_LOCAL4	29	/* reserved for local use */
#define	LOG_LOCAL5	30	/* reserved for local use */
#define	LOG_LOCAL6	31	/* reserved for local use */
E 7
I 7
D 11
#define LOG_PRIMASK	0x0007	/* mask to extract priority part */
E 11
I 11
#define LOG_PRIMASK	0x0007	/* mask to extract priority part (internal) */
I 21
#define LOG_PRI(p)	((p) & LOG_PRIMASK)	/* extract priority */

#define	LOG_MAKEPRI(fac, pri)	(((fac) << 3) | (pri))

#ifdef KERNEL
#define LOG_PRINTF	-1	/* pseudo-priority to indicate use of printf */
#endif
E 21

/*
I 18
 * arguments to setlogmask.
 */
#define	LOG_MASK(pri)	(1 << (pri))		/* mask for one priority */
#define	LOG_UPTO(pri)	((1 << ((pri)+1)) - 1)	/* all priorities through pri */

/*
E 18
D 16
 * arguments to setlogmask.
 */
#define	LOG_MASK(pri)	(1 << (pri))		/* mask for one priority */
D 13
#define	LOG_UPTO(pri)	(1 << ((pri) + 1) - 1)	/* all priorities through pri */
E 13
I 13
#define	LOG_UPTO(pri)	((1 << ((pri)+1)) - 1)	/* all priorities through pri */
E 13
E 11
E 7

E 4
/*
E 16
D 2
 *  Mode parameters to initlog.
E 2
I 2
 *  Option flags for openlog.
I 9
 *
 *	LOG_ODELAY no longer does anything; LOG_NDELAY is the
 *	inverse of what it used to be.
E 9
E 2
 */
D 2
#define	LOG_NULL	0	/* don't touch log */
#define	LOG_SOUT	1	/* log standard & diag output */
#define	LOG_DIAG	2	/* log diagnostic output */
#define	LOG_INDEP	3	/* log independently */
#define	LOG_CLOSE	4	/* close the log */

/*
 *  Status parameters to initlog.
 */
#define	LOG_PID		0001	/* log the pid with each message */
#define	LOG_TIME	0002	/* log the time with each message */
#define	LOG_COOLIT	0004	/* suppress priority stuff */
#define	LOG_DGRAM	0010	/* running over a datagram socket */
E 2
I 2
D 12
#define	LOG_PID		01	/* log the pid with each message */
I 4
#define	LOG_CONS	02	/* log on the console if errors in sending */
#define	LOG_ODELAY	04	/* delay open until syslog() is called */
I 9
#define LOG_NDELAY	010	/* don't delay open */
E 12
I 12
#define	LOG_PID		0x01	/* log the pid with each message */
#define	LOG_CONS	0x02	/* log on the console if errors in sending */
D 16
#define	LOG_ODELAY	0x04	/* delay open until syslog() is called */
E 16
I 16
#define	LOG_ODELAY	0x04	/* delay open until first syslog() (default) */
E 16
#define LOG_NDELAY	0x08	/* don't delay open */
#define LOG_NOWAIT	0x10	/* if forking to log on console, don't wait() */
E 12
E 9
E 4
E 2
E 1
