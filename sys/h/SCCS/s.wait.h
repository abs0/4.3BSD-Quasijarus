h46189
s 00001/00001/00083
d D 7.4 88/01/27 17:14:27 karels 7 6
c no endian
e
s 00004/00004/00080
d D 7.3 88/01/07 11:33:45 karels 6 5
c rename endians
e
s 00018/00000/00066
d D 7.2 86/10/13 23:01:42 karels 5 4
c byteorder dependency
e
s 00001/00001/00065
d D 7.1 86/06/04 23:33:19 mckusick 4 3
c 4.3BSD release version
e
s 00007/00001/00059
d D 6.2 85/06/08 15:15:04 mckusick 3 2
c Add copyright
e
s 00000/00000/00060
d D 6.1 83/07/29 06:15:28 sam 2 1
c 4.2 distribution
e
s 00060/00000/00000
d D 4.1 83/02/10 21:42:09 sam 1 0
c date and time created 83/02/10 21:42:09 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
D 4
 * Copyright (c) 1982 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

/*
 * This file holds definitions relevent to the wait system call.
 * Some of the options here are available only through the ``wait3''
 * entry point; the old entry point with one argument has more fixed
 * semantics, never returning status of unstopped children, hanging until
 * a process terminates if any are outstanding, and never returns
 * detailed information about process resource utilization (<vtimes.h>).
 */

I 5
D 7
#ifndef ENDIAN
E 7
I 7
#ifndef BYTE_ORDER
E 7
D 6
#include <machine/machparam.h>
E 6
I 6
#include <machine/endian.h>
E 6
#endif

E 5
/*
 * Structure of the information in the first word returned by both
 * wait and wait3.  If w_stopval==WSTOPPED, then the second structure
 * describes the information returned, else the first.  See WUNTRACED below.
 */
union wait	{
	int	w_status;		/* used in syscall */
	/*
	 * Terminated process status.
	 */
	struct {
I 5
D 6
#if ENDIAN == LITTLE
E 6
I 6
#if BYTE_ORDER == LITTLE_ENDIAN 
E 6
E 5
		unsigned short	w_Termsig:7;	/* termination signal */
		unsigned short	w_Coredump:1;	/* core dump indicator */
		unsigned short	w_Retcode:8;	/* exit code if w_termsig==0 */
I 5
#endif
D 6
#if ENDIAN == BIG
E 6
I 6
#if BYTE_ORDER == BIG_ENDIAN 
E 6
		unsigned short	w_Filler;	/* upper bits filler */
		unsigned char	w_Retcode;	/* exit code if w_termsig==0 */
		unsigned char	w_Coredump:1;	/* core dump indicator */
		unsigned char	w_Termsig:7;	/* termination signal */
#endif
E 5
	} w_T;
	/*
	 * Stopped process status.  Returned
	 * only for traced children unless requested
	 * with the WUNTRACED option bit.
	 */
	struct {
I 5
D 6
#if ENDIAN == LITTLE
E 6
I 6
#if BYTE_ORDER == LITTLE_ENDIAN 
E 6
E 5
		unsigned short	w_Stopval:8;	/* == W_STOPPED if stopped */
		unsigned short	w_Stopsig:8;	/* signal that stopped us */
I 5
#else
		unsigned short	w_Filler;	/* upper bits filler */
		unsigned char	w_Stopsig;	/* signal that stopped us */
		unsigned char	w_Stopval;	/* == W_STOPPED if stopped */
#endif
E 5
	} w_S;
};
#define	w_termsig	w_T.w_Termsig
#define w_coredump	w_T.w_Coredump
#define w_retcode	w_T.w_Retcode
#define w_stopval	w_S.w_Stopval
#define w_stopsig	w_S.w_Stopsig


#define	WSTOPPED	0177	/* value of s.stopval if process is stopped */

/*
 * Option bits for the second argument of wait3.  WNOHANG causes the
 * wait to not hang if there are no stopped or terminated processes, rather
 * returning an error indication in this case (pid==0).  WUNTRACED
 * indicates that the caller should receive status about untraced children
 * which stop due to signals.  If children are stopped and a wait without
 * this option is done, it is as though they were still running... nothing
 * about them is returned.
 */
#define WNOHANG		1	/* dont hang in wait */
#define WUNTRACED	2	/* tell about stopped, untraced children */

#define WIFSTOPPED(x)	((x).w_stopval == WSTOPPED)
#define WIFSIGNALED(x)	((x).w_stopval != WSTOPPED && (x).w_termsig != 0)
#define WIFEXITED(x)	((x).w_stopval != WSTOPPED && (x).w_termsig == 0)
E 1
