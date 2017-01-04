h11659
s 00010/00005/00167
d D 5.6 88/06/18 14:10:38 bostic 8 7
c install approved copyright notice
e
s 00009/00003/00163
d D 5.5 88/05/20 11:53:28 bostic 7 6
c add Berkeley specific header
e
s 00006/00006/00160
d D 5.4 87/10/22 11:18:37 bostic 6 5
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00165
d D 5.3 86/03/13 18:05:03 mckusick 5 4
c setgid to group "write" so that terminals need not be world writable
e
s 00016/00018/00150
d D 5.2 86/03/13 17:12:49 mckusick 4 3
c new version from sam@monet.berkeley.edu
e
s 00007/00001/00161
d D 5.1 85/06/06 09:16:16 dist 3 2
c Add copyright
e
s 00114/00160/00048
d D 1.2 84/04/11 15:13:05 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00208/00000/00000
d D 1.1 84/04/11 15:02:40 karels 1 0
c date and time created 84/04/11 15:02:40 by karels
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

E 3
I 1
D 2
/* $Header: /a/guest/moore/talk/RCS/announce.c,v 1.8 83/07/06 00:16:57 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 3
E 2

D 4
#include "ctl.h"

E 4
I 4
#include <sys/types.h>
E 4
#include <sys/stat.h>
#include <sgtty.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
I 4
#include <syslog.h>
E 4

D 4
char *sprintf();
E 4
I 4
#include <protocols/talkd.h>
E 4

D 4
extern int errno;
extern char hostname[];
int nofork = 0;		/* to be set from the debugger */
E 4
I 4
extern	int errno;
extern	char hostname[];
E 4

/*
I 4
 * Announce an invitation to talk.
 *
E 4
 * Because the tty driver insists on attaching a terminal-less
 * process to any terminal that it writes on, we must fork a child
 * to protect ourselves
 */
D 4

E 4
announce(request, remote_machine)
D 2
CTL_MSG *request;
char *remote_machine;
E 2
I 2
	CTL_MSG *request;
	char *remote_machine;
E 2
{
D 2
    int pid, val, status;
E 2
I 2
	int pid, val, status;
E 2

D 2
    if (nofork) {
	return(announce_proc(request, remote_machine));
    }

    if ( pid = fork() ) {

	    /* we are the parent, so wait for the child */

	if (pid == -1) {
		/* the fork failed */
	    return(FAILED);
E 2
I 2
D 4
	if (nofork)
		return(announce_proc(request, remote_machine));
E 4
	if (pid = fork()) {
		/* we are the parent, so wait for the child */
		if (pid == -1)		/* the fork failed */
D 4
			return(FAILED);
E 4
I 4
			return (FAILED);
E 4
		do {
			val = wait(&status);
			if (val == -1) {
				if (errno == EINTR)
					continue;
				/* shouldn't happen */
D 4
				perror("wait");
E 4
I 4
				syslog(LOG_WARNING, "announce: wait: %m");
E 4
				return (FAILED);
			}
		} while (val != pid);
		if (status&0377 > 0)	/* we were killed by some signal */
			return (FAILED);
		/* Get the second byte, this is the exit/return code */
		return ((status >> 8) & 0377);
E 2
	}
D 2

	do {
	    val = wait(&status);
	    if (val == -1) {
		if (errno == EINTR) {
		    continue;
		} else {
			/* shouldn't happen */
		    print_error("wait");
		    return(FAILED);
		}
	    }
	} while (val != pid);

	if (status&0377 > 0) {
		/* we were killed by some signal */
	    return(FAILED);
	}

	    /* Get the second byte, this is the exit/return code */

	return((status>>8)&0377);

    } else {
	    /* we are the child, go and do it */
E 2
I 2
	/* we are the child, go and do it */
E 2
	_exit(announce_proc(request, remote_machine));
D 2
    }
E 2
}
	
D 2

    /* See if the user is accepting messages. If so, announce that 
       a talk is requested.
     */

E 2
I 2
/*
 * See if the user is accepting messages. If so, announce that 
 * a talk is requested.
 */
E 2
announce_proc(request, remote_machine)
D 2
CTL_MSG *request;
char *remote_machine;
E 2
I 2
	CTL_MSG *request;
	char *remote_machine;
E 2
{
D 2
    int pid, status;
    char full_tty[32];
    FILE *tf;
    struct stat stbuf;
E 2
I 2
	int pid, status;
	char full_tty[32];
	FILE *tf;
	struct stat stbuf;
E 2

D 2

    (void) sprintf(full_tty, "/dev/%s", request->r_tty);

    if (access(full_tty, 0) != 0) {
	return(FAILED);
    }

    if ((tf = fopen(full_tty, "w")) == NULL) {
	return(PERMISSION_DENIED);
    }

	/* open gratuitously attaches the talkd to
	   any tty it opens, so disconnect us from the
	   tty before we catch a signal */

    ioctl(fileno(tf), TIOCNOTTY, (struct sgttyb *) 0);

    if (fstat(fileno(tf), &stbuf) < 0) {
	return(PERMISSION_DENIED);
    }

    if ((stbuf.st_mode&02) == 0) {
	return(PERMISSION_DENIED);
    }

    print_mesg(tf, request, remote_machine);
    fclose(tf);
    return(SUCCESS);
E 2
I 2
D 4
	(void) sprintf(full_tty, "/dev/%s", request->r_tty);
E 4
I 4
D 6
	sprintf(full_tty, "/dev/%s", request->r_tty);
E 6
I 6
	(void)sprintf(full_tty, "/dev/%s", request->r_tty);
E 6
E 4
	if (access(full_tty, 0) != 0)
		return (FAILED);
	if ((tf = fopen(full_tty, "w")) == NULL)
		return (PERMISSION_DENIED);
	/*
D 4
	 * Open gratuitously attaches the talkd to
	 * any tty it opens, so disconnect us from the
	 * tty before we catch a signal
E 4
I 4
	 * On first tty open, the server will have
	 * it's pgrp set, so disconnect us from the
	 * tty before we catch a signal.
E 4
	 */
	ioctl(fileno(tf), TIOCNOTTY, (struct sgttyb *) 0);
	if (fstat(fileno(tf), &stbuf) < 0)
		return (PERMISSION_DENIED);
D 5
	if ((stbuf.st_mode&02) == 0)
E 5
I 5
	if ((stbuf.st_mode&020) == 0)
E 5
		return (PERMISSION_DENIED);
	print_mesg(tf, request, remote_machine);
	fclose(tf);
	return (SUCCESS);
E 2
}

#define max(a,b) ( (a) > (b) ? (a) : (b) )
#define N_LINES 5
#define N_CHARS 120

D 2
    /*
     * build a block of characters containing the message. 
     * It is sent blank filled and in a single block to
     * try to keep the message in one piece if the recipient
     * in in vi at the time
     */

E 2
I 2
/*
 * Build a block of characters containing the message. 
 * It is sent blank filled and in a single block to
 * try to keep the message in one piece if the recipient
 * in in vi at the time
 */
E 2
print_mesg(tf, request, remote_machine)
D 2
FILE *tf;
CTL_MSG *request;
char *remote_machine;
E 2
I 2
	FILE *tf;
	CTL_MSG *request;
	char *remote_machine;
E 2
{
D 2
    struct timeval clock;
    struct timezone zone;
    struct tm *localtime();
    struct tm *localclock;
    char line_buf[N_LINES][N_CHARS];
    int sizes[N_LINES];
    char big_buf[N_LINES*N_CHARS];
    char *bptr, *lptr;
    int i, j, max_size;
E 2
I 2
	struct timeval clock;
	struct timezone zone;
	struct tm *localtime();
	struct tm *localclock;
	char line_buf[N_LINES][N_CHARS];
	int sizes[N_LINES];
	char big_buf[N_LINES*N_CHARS];
	char *bptr, *lptr;
	int i, j, max_size;
E 2

D 2
    i = 0;
    max_size = 0;

    gettimeofday(&clock, &zone);
    localclock = localtime( &clock.tv_sec );

    sprintf(line_buf[i], " ");

    sizes[i] = strlen(line_buf[i]);
    max_size = max(max_size, sizes[i]);
    i++;

    sprintf(line_buf[i], "Message from Talk_Daemon@%s at %d:%02d ...",
E 2
I 2
	i = 0;
	max_size = 0;
	gettimeofday(&clock, &zone);
	localclock = localtime( &clock.tv_sec );
D 6
	sprintf(line_buf[i], " ");
E 6
I 6
	(void)sprintf(line_buf[i], " ");
E 6
	sizes[i] = strlen(line_buf[i]);
	max_size = max(max_size, sizes[i]);
	i++;
D 6
	sprintf(line_buf[i], "Message from Talk_Daemon@%s at %d:%02d ...",
E 6
I 6
	(void)sprintf(line_buf[i], "Message from Talk_Daemon@%s at %d:%02d ...",
E 6
E 2
	hostname, localclock->tm_hour , localclock->tm_min );
D 2

    sizes[i] = strlen(line_buf[i]);
    max_size = max(max_size, sizes[i]);
    i++;

    sprintf(line_buf[i], "talk: connection requested by %s@%s.",
E 2
I 2
	sizes[i] = strlen(line_buf[i]);
	max_size = max(max_size, sizes[i]);
	i++;
D 6
	sprintf(line_buf[i], "talk: connection requested by %s@%s.",
E 6
I 6
	(void)sprintf(line_buf[i], "talk: connection requested by %s@%s.",
E 6
E 2
		request->l_name, remote_machine);
D 2

    sizes[i] = strlen(line_buf[i]);
    max_size = max(max_size, sizes[i]);
    i++;

    sprintf(line_buf[i], "talk: respond with:  talk %s@%s",
E 2
I 2
	sizes[i] = strlen(line_buf[i]);
	max_size = max(max_size, sizes[i]);
	i++;
D 6
	sprintf(line_buf[i], "talk: respond with:  talk %s@%s",
E 6
I 6
	(void)sprintf(line_buf[i], "talk: respond with:  talk %s@%s",
E 6
E 2
		request->l_name, remote_machine);
D 2

    sizes[i] = strlen(line_buf[i]);
    max_size = max(max_size, sizes[i]);
    i++;

    sprintf(line_buf[i], " ");

    sizes[i] = strlen(line_buf[i]);
    max_size = max(max_size, sizes[i]);
    i++;

    bptr = big_buf;
    *(bptr++) = '';	/* send something to wake them up */
    *(bptr++) = '\r';	/* add a \r in case of raw mode */
    *(bptr++) = '\n';
    for(i = 0; i < N_LINES; i++) {

	    /* copy the line into the big buffer */

	lptr = line_buf[i];
	while (*lptr != '\0') {
	    *(bptr++) = *(lptr++);
	}

	    /* pad out the rest of the lines with blanks */

	for(j = sizes[i]; j < max_size + 2; j++) {
	    *(bptr++) = ' ';
	}

E 2
I 2
	sizes[i] = strlen(line_buf[i]);
	max_size = max(max_size, sizes[i]);
	i++;
D 6
	sprintf(line_buf[i], " ");
E 6
I 6
	(void)sprintf(line_buf[i], " ");
E 6
	sizes[i] = strlen(line_buf[i]);
	max_size = max(max_size, sizes[i]);
	i++;
	bptr = big_buf;
D 4
	*(bptr++) = ''; /* send something to wake them up */
E 2
	*(bptr++) = '\r';	/* add a \r in case of raw mode */
	*(bptr++) = '\n';
E 4
I 4
	*bptr++ = ''; /* send something to wake them up */
	*bptr++ = '\r';	/* add a \r in case of raw mode */
	*bptr++ = '\n';
E 4
D 2
    }
    *bptr = '\0';

    fprintf(tf, big_buf);
    fflush(tf);
    ioctl(fileno(tf), TIOCNOTTY, (struct sgttyb *) 0);
E 2
I 2
	for (i = 0; i < N_LINES; i++) {
		/* copy the line into the big buffer */
		lptr = line_buf[i];
		while (*lptr != '\0')
			*(bptr++) = *(lptr++);
		/* pad out the rest of the lines with blanks */
		for (j = sizes[i]; j < max_size + 2; j++)
			*(bptr++) = ' ';
		*(bptr++) = '\r';	/* add a \r in case of raw mode */
		*(bptr++) = '\n';
	}
	*bptr = '\0';
	fprintf(tf, big_buf);
	fflush(tf);
	ioctl(fileno(tf), TIOCNOTTY, (struct sgttyb *) 0);
E 2
}
E 1
