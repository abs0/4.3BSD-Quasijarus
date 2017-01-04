h53094
s 00010/00005/00052
d D 5.4 88/06/29 20:22:28 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00048
d D 5.3 88/05/20 12:37:10 bostic 5 4
c add Berkeley specific header
e
s 00005/00007/00046
d D 5.2 88/05/20 12:10:58 edward 4 3
c use getpwuid in addition to getlogin to get user name, and some cleanup
e
s 00007/00001/00046
d D 5.1 85/06/06 09:19:13 dist 3 2
c Add copyright
e
s 00022/00018/00025
d D 1.2 84/04/11 15:14:34 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00043/00000/00000
d D 1.1 84/04/11 15:03:03 karels 1 0
c date and time created 84/04/11 15:03:03 by karels
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */

E 3
I 1
D 2
/* $Header: /a/guest/moore/talk/RCS/msgs.c,v 1.4 83/07/06 00:17:22 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 3
E 2

/* 
D 2
 * a package to display what is happening every MSG_INTERVAL seconds
E 2
I 2
 * A package to display what is happening every MSG_INTERVAL seconds
E 2
 * if we are slow connecting.
 */

#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include "talk.h"

#define MSG_INTERVAL 4
D 4
#define LONG_TIME 100000
E 4

D 2
char *current_state;
int current_line = 0;
E 2
I 2
char	*current_state;
int	current_line = 0;
E 2

D 2
static struct itimerval itimer;
static struct timeval wait = { MSG_INTERVAL , 0};
static struct timeval undo = { LONG_TIME, 0};
    

E 2
I 2
D 4
static	struct itimerval itimer;
static	struct timeval wait = { MSG_INTERVAL , 0};
static	struct timeval undo = { LONG_TIME, 0};
	
E 4
E 2
disp_msg()
{
D 2
    message(current_state);
E 2
I 2

	message(current_state);
E 2
}

start_msgs()
{
I 4
	struct itimerval itimer;
E 4
D 2
    message(current_state);
    signal(SIGALRM, disp_msg);
    itimer.it_value = itimer.it_interval = wait;
    setitimer(ITIMER_REAL, &itimer, (struct timerval *)0);
E 2
I 2

	message(current_state);
	signal(SIGALRM, disp_msg);
D 4
	itimer.it_value = itimer.it_interval = wait;
E 4
I 4
	itimer.it_value.tv_sec = itimer.it_interval.tv_sec = MSG_INTERVAL;
	itimer.it_value.tv_usec = itimer.it_interval.tv_usec = 0;
E 4
	setitimer(ITIMER_REAL, &itimer, (struct timerval *)0);
E 2
}

end_msgs()
{
I 4
	struct itimerval itimer;
E 4
D 2
    signal(SIGALRM, SIG_IGN);
    timerclear(&itimer.it_value);
    timerclear(&itimer.it_interval);
    setitimer(ITIMER_REAL, &itimer, (struct timerval *)0);
E 2
I 2

D 4
	signal(SIGALRM, SIG_IGN);
E 4
	timerclear(&itimer.it_value);
	timerclear(&itimer.it_interval);
	setitimer(ITIMER_REAL, &itimer, (struct timerval *)0);
I 4
	signal(SIGALRM, SIG_DFL);
E 4
E 2
}
E 1
