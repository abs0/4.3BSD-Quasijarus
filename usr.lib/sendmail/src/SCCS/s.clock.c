h50585
s 00011/00009/00232
d D 5.6 88/06/30 14:58:21 bostic 26 25
c install approved copyright notice
e
s 00016/00010/00225
d D 5.5 88/03/13 19:51:32 bostic 25 24
c add Berkeley specific header
e
s 00001/00001/00234
d D 5.4 85/12/17 23:52:47 eric 24 23
m 
c lint
e
s 00002/00002/00233
d D 5.3 85/09/19 13:36:02 eric 23 22
m 
c lint
e
s 00000/00000/00235
d D 5.2 85/06/08 10:30:56 eric 22 21
m 
c lint for 4.3 release
e
s 00014/00002/00221
d D 5.1 85/06/07 14:29:40 dist 21 20
m 
c Add copyright
e
s 00005/00000/00218
d D 4.4 85/05/15 20:26:38 eric 20 19
m 
c reenable signals in an event that may be called to run the queue; this
c allows hung connections to time out properly during a queue run.  This
c fix provided by Bill Nowicki.
e
s 00002/00001/00216
d D 4.3 84/12/05 23:15:24 eric 19 18
m 
c Try to use flock call (this doesn't work because we don't always have an
c open fd); security and performance fixes from Kirk Smith at Purdue; "a"
c option is now the number of minutes to wait for "@:@" alias; fix bug in
c $[ $] using -t; random cleanup
e
s 00007/00004/00210
d D 4.2 84/03/11 13:38:29 eric 18 17
m 
c fixes from Greg Satz <satz@sri-tsc.ARPA>, mostly for PDP's
e
s 00000/00000/00214
d D 4.1 83/07/25 19:46:23 eric 17 16
m 
c 4.2 release version
e
s 00003/00003/00211
d D 3.15 83/05/21 11:01:45 eric 16 15
m 
c Miscellaneous changes for PDP-11's.
c Always send to a login name before a full name.
e
s 00001/00000/00213
d D 3.14 83/03/26 14:27:20 eric 15 14
m 214
c changes from MRH for USG UNIX 5.0
e
s 00008/00002/00205
d D 3.13 82/11/28 00:20:57 eric 14 13
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00004/00004/00203
d D 3.12 82/11/24 18:43:55 eric 13 12
m 
c lint it
e
s 00003/00004/00204
d D 3.11 82/09/08 21:19:42 eric 12 11
c try to avoid "Interrupted system call" on wait in deliver and on
c writes; fix returned message to have proper sender; handle extra
c mailer output more cleverly.
e
s 00004/00004/00204
d D 3.10 82/09/05 18:03:30 eric 11 10
c tune debugging
e
s 00006/00010/00202
d D 3.9 82/08/27 16:00:12 eric 10 8
c simplify timeout code; allow multiple simultaneous queue runs so that
c large messages don't freeze things up; fix EINTR problem in sfgets;
c clean up canonname to be really correct; lots of misc. cleanup
e
s 00000/00000/00212
d R 3.9 82/08/27 15:47:44 eric 9 8
c simplify timeout code; allow multiple simultaneous queue runs so that
c large messages don't freeze things up; fix EINTR in sfgets; clean up
c canonname to be really correct; lots of misc. cleanup
e
s 00007/00002/00205
d D 3.8 82/08/27 11:11:17 eric 8 7
c release e_id after fork in daemon code; ignore events scheduled by
c another process
e
s 00006/00004/00201
d D 3.7 82/08/25 16:18:35 eric 7 6
c apply ruleset 4 to rewrite addresses in the body of the message; fix
c a clock.c bug that caused it to lose events; more time cleanup.
e
s 00020/00013/00185
d D 3.6 82/08/24 10:27:17 eric 6 5
c clean up event handling so that events that do longjmp's don't turn
c off all future events.
e
s 00012/00000/00186
d D 3.5 82/08/15 11:55:40 eric 5 4
c don't choke on zero intervals
e
s 00036/00000/00150
d D 3.4 82/08/08 21:15:40 eric 4 3
c make "sleep" work correctly even in the face of other events; clean
c up the queue processing: child queue runs now go away when done.  more
c debugging logging is needed to verify that this works right though.
e
s 00128/00005/00022
d D 3.3 82/08/08 17:02:26 eric 3 2
c more general event mechanism
e
s 00001/00001/00026
d D 3.2 82/08/08 01:02:21 eric 2 1
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00027/00000/00000
d D 3.1 82/07/05 12:23:56 eric 1 0
c date and time created 82/07/05 12:23:56 by eric
e
u
U
f b 
f i 
t
T
I 21
/*
I 26
 * Copyright (c) 1983 Eric P. Allman
E 26
D 25
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 25
I 25
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 26
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 26
I 26
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
E 26
 */
E 25

#ifndef lint
D 25
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 25
I 25
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 25

E 21
I 1
# include "sendmail.h"
I 15
# include <signal.h>
E 15
D 21

SCCSID(%W%	%Y%	%G%);
E 21

/*
I 3
**  SETEVENT -- set an event to happen at a specific time.
**
I 14
**	Events are stored in a sorted list for fast processing.
**	An event only applies to the process that set it.
**
E 14
**	Parameters:
**		intvl -- intvl until next event occurs.
**		func -- function to call on event.
**		arg -- argument to func on event.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

EVENT *
setevent(intvl, func, arg)
	time_t intvl;
	int (*func)();
	int arg;
{
	register EVENT **evp;
	register EVENT *ev;
	auto time_t now;
	extern tick();

I 5
# ifdef DEBUG
	if (intvl <= 0)
	{
		syserr("setevent: intvl=%ld\n", intvl);
D 13
		return;
E 13
I 13
		return (NULL);
E 13
	}
# endif DEBUG

E 5
	(void) time(&now);

	/* search event queue for correct position */
	for (evp = &EventQueue; (ev = *evp) != NULL; evp = &ev->ev_link)
	{
		if (ev->ev_time >= now + intvl)
			break;
	}

	/* insert new event */
	ev = (EVENT *) xalloc(sizeof *ev);
	ev->ev_time = now + intvl;
	ev->ev_func = func;
	ev->ev_arg = arg;
I 8
	ev->ev_pid = getpid();
E 8
	ev->ev_link = *evp;
	*evp = ev;

D 10
	/* reschedule next clock tick if appropriate */
	if (ev == EventQueue)
	{
		/* we have a new event */
		(void) signal(SIGALRM, tick);
		(void) alarm(intvl);
	}

E 10
# ifdef DEBUG
D 11
	if (tTd(5, 2))
E 11
I 11
	if (tTd(5, 5))
E 11
		printf("setevent: intvl=%ld, for=%ld, func=%x, arg=%d, ev=%x\n",
			intvl, now + intvl, func, arg, ev);
# endif DEBUG

I 10
	tick();
E 10
	return (ev);
}
/*
**  CLREVENT -- remove an event from the event queue.
**
**	Parameters:
**		ev -- pointer to event to remove.
**
**	Returns:
**		none.
**
**	Side Effects:
**		arranges for event ev to not happen.
*/

clrevent(ev)
	register EVENT *ev;
{
	register EVENT **evp;

# ifdef DEBUG
D 11
	if (tTd(5, 2))
E 11
I 11
	if (tTd(5, 5))
E 11
		printf("clrevent: ev=%x\n", ev);
# endif DEBUG
I 5
	if (ev == NULL)
		return;
E 5

	/* find the parent event */
I 6
D 14
	signal(SIGALRM, SIG_IGN);
E 14
I 14
	(void) signal(SIGALRM, SIG_IGN);
E 14
E 6
	for (evp = &EventQueue; *evp != NULL; evp = &(*evp)->ev_link)
	{
		if (*evp == ev)
			break;
	}

	/* now remove it */
D 6
	if (*evp == NULL)
	{
		/* hmmmmm.... must have happened. */
		return;
	}

E 6
D 10
	*evp = ev->ev_link;
	free(ev);
E 10
I 10
	if (*evp != NULL)
	{
		*evp = ev->ev_link;
D 13
		free(ev);
E 13
I 13
		free((char *) ev);
E 13
	}
E 10
I 6

	/* restore clocks and pick up anything spare */
	tick();
E 6
}
/*
E 3
**  TICK -- take a clock tick
**
D 3
**	Someday this will have to do more complex event scheduling.
E 3
I 3
**	Called by the alarm clock.  This routine runs events as needed.
E 3
**
**	Parameters:
**		none.
**
**	Returns:
D 3
**		non-local through TickFrame.
E 3
I 3
**		none.
E 3
**
**	Side Effects:
D 3
**		none.
E 3
I 3
**		calls the next function in EventQueue.
E 3
*/

tick()
{
I 3
D 7
	auto time_t now;
E 7
I 7
	register time_t now;
E 7
	register EVENT *ev;
I 19
D 23
	int pid = getpid();
E 23
I 23
	int mypid = getpid();
E 23
E 19

I 4
D 6
	signal(SIGALRM, SIG_IGN);
E 6
I 6
D 14
	signal(SIGALRM, tick);
E 14
I 14
	(void) signal(SIGALRM, SIG_IGN);
	(void) alarm(0);
E 14
E 6
E 4
D 7
	(void) time(&now);
E 7
I 7
	now = curtime();
E 7

E 3
# ifdef DEBUG
D 2
	if (Debug > 0)
E 2
I 2
D 11
	if (tTd(5, 1))
E 11
I 11
	if (tTd(5, 4))
E 11
E 2
D 3
		printf("tick\n");
E 3
I 3
		printf("tick: now=%ld\n", now);
E 3
# endif DEBUG
D 3
	longjmp(TickFrame, 1);
E 3
I 3

D 12
	while (EventQueue != NULL && EventQueue->ev_time <= now)
E 12
I 12
	while ((ev = EventQueue) != NULL &&
D 19
	       (ev->ev_time <= now || ev->ev_pid != getpid()))
E 19
I 19
D 23
	       (ev->ev_time <= now || ev->ev_pid != pid))
E 23
I 23
	       (ev->ev_time <= now || ev->ev_pid != mypid))
E 23
E 19
E 12
	{
I 6
D 18
		int (*f)(), a;
E 18
I 18
		int (*f)();
		int arg;
		int pid;
E 18
I 8
D 12
		int pid;
E 12
E 8

E 6
		/* process the event on the top of the queue */
		ev = EventQueue;
		EventQueue = EventQueue->ev_link;
# ifdef DEBUG
D 11
		if (tTd(5, 3))
E 11
I 11
		if (tTd(5, 6))
E 11
D 8
			printf("tick: ev=%x, func=%x, arg=%d\n", ev,
				ev->ev_func, ev->ev_arg);
E 8
I 8
			printf("tick: ev=%x, func=%x, arg=%d, pid=%d\n", ev,
				ev->ev_func, ev->ev_arg, ev->ev_pid);
E 8
# endif DEBUG
D 6
		(*ev->ev_func)(ev->ev_arg);
E 6
I 6

		/* we must be careful in here because ev_func may not return */
I 14
		(void) signal(SIGALRM, tick);
I 20
#ifdef SIGVTALRM
		/* reset 4.2bsd signal mask to allow future alarms */
		(void) sigsetmask(sigblock(0) & ~sigmask(SIGALRM));
#endif SIGVTALRM

E 20
E 14
		f = ev->ev_func;
D 18
		a = ev->ev_arg;
E 18
I 18
		arg = ev->ev_arg;
		pid = ev->ev_pid;
E 18
I 8
D 12
		pid = ev->ev_pid;
E 12
E 8
E 6
D 13
		free(ev);
E 13
I 13
		free((char *) ev);
E 13
I 8
D 12
		if (pid != getpid())
E 12
I 12
D 18
		if (ev->ev_pid != getpid())
E 18
I 18
		if (pid != getpid())
E 18
E 12
			continue;
E 8
I 6
		if (EventQueue != NULL)
		{
			if (EventQueue->ev_time > now)
D 16
				(void) alarm(EventQueue->ev_time - now);
E 16
I 16
				(void) alarm((unsigned) (EventQueue->ev_time - now));
E 16
			else
D 7
				(void) alarm(1);
E 7
I 7
				(void) alarm(3);
E 7
		}
D 18
		(*f)(a);
E 18
I 18
		(*f)(arg);
E 18
		(void) alarm(0);
E 6
D 7
		(void) time(&now);
E 7
I 7
		now = curtime();
E 7
	}
I 14
	(void) signal(SIGALRM, tick);
E 14
I 7
	if (EventQueue != NULL)
D 16
		(void) alarm(EventQueue->ev_time - now);
E 16
I 16
		(void) alarm((unsigned) (EventQueue->ev_time - now));
E 16
E 7
D 6

	/* schedule the next clock tick */
	signal(SIGALRM, tick);
	if (EventQueue != NULL)
		(void) alarm(EventQueue->ev_time - now);
E 6
I 4
}
/*
**  SLEEP -- a version of sleep that works with this stuff
**
**	Because sleep uses the alarm facility, I must reimplement
**	it here.
**
**	Parameters:
**		intvl -- time to sleep.
**
**	Returns:
**		none.
**
**	Side Effects:
**		waits for intvl time.  However, other events can
**		be run during that interval.
*/

static bool	SleepDone;

sleep(intvl)
D 24
	int intvl;
E 24
I 24
	unsigned int intvl;
E 24
{
	extern endsleep();

I 5
	if (intvl == 0)
		return;
E 5
	SleepDone = FALSE;
D 13
	setevent(intvl, endsleep, 0);
E 13
I 13
D 16
	(void) setevent(intvl, endsleep, 0);
E 16
I 16
	(void) setevent((time_t) intvl, endsleep, 0);
E 16
E 13
	while (!SleepDone)
		pause();
}

static
endsleep()
{
	SleepDone = TRUE;
E 4
E 3
}
E 1
