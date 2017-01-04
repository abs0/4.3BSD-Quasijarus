h19178
s 00010/00005/00149
d D 5.5 88/06/29 20:22:22 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00145
d D 5.4 88/05/20 12:37:06 bostic 6 5
c add Berkeley specific header
e
s 00003/00002/00145
d D 5.3 87/02/20 20:09:14 sam 5 4
c fix from ajb@j.cc.purdue.edu - make answer messages correspond to protocol
e
s 00029/00036/00118
d D 5.2 86/03/13 17:41:05 mckusick 4 3
c new version from sam@monet.berkeley.edu
e
s 00007/00001/00147
d D 5.1 85/06/06 09:18:25 dist 3 2
c Add copyright
e
s 00111/00121/00037
d D 1.2 84/04/11 15:14:01 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00158/00000/00000
d D 1.1 84/04/11 15:02:55 karels 1 0
c date and time created 84/04/11 15:02:55 by karels
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

E 3
I 1
D 2
/* $Header: /a/guest/moore/talk/RCS/invite.c,v 1.7 83/07/06 00:17:32 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6
E 3
E 2

#include "talk_ctl.h"
#include <sys/time.h>
#include <signal.h>
#include <setjmp.h>
D 2
    
    /*
     * there wasn't an invitation waiting, so send a request containing
     * our sockt address to the remote talk daemon so it can invite
     * him 
     */
E 2

D 2
int local_id, remote_id;	/* the msg.id's for the invitations
				   on the local and remote machines.
				   These are used to delete the 
				   invitations. */
void re_invite();
jmp_buf	invitebuf;
E 2
I 2
/*
 * There wasn't an invitation waiting, so send a request containing
 * our sockt address to the remote talk daemon so it can invite
 * him 
 */
E 2

I 2
/*
 * The msg.id's for the invitations
 * on the local and remote machines.
 * These are used to delete the 
 * invitations.
 */
int	local_id, remote_id;
void	re_invite();
jmp_buf invitebuf;

E 2
invite_remote()
{
D 2
    int nfd, read_mask, template, new_sockt;
    struct itimerval itimer;
    CTL_RESPONSE response;
E 2
I 2
	int nfd, read_mask, template, new_sockt;
	struct itimerval itimer;
	CTL_RESPONSE response;
E 2

D 2
    itimer.it_value.tv_sec = RING_WAIT;
    itimer.it_value.tv_usec = 0;
    itimer.it_interval = itimer.it_value;

    if (listen(sockt, 5) != 0) {
	p_error("Error on attempt to listen for caller");
    }

    msg.addr = my_addr;
    msg.id_num = -1;		/* an impossible id_num */

    invitation_waiting = 1;

    announce_invite();

E 2
I 2
	itimer.it_value.tv_sec = RING_WAIT;
	itimer.it_value.tv_usec = 0;
	itimer.it_interval = itimer.it_value;
	if (listen(sockt, 5) != 0)
		p_error("Error on attempt to listen for caller");
D 4
	msg.addr = my_addr;
	msg.id_num = -1;		/* an impossible id_num */
E 4
I 4
	msg.addr = *(struct sockaddr *)&my_addr;
	msg.addr.sa_family = htons(msg.addr.sa_family);
	msg.id_num = htonl(-1);		/* an impossible id_num */
E 4
	invitation_waiting = 1;
	announce_invite();
E 2
	/*
D 2
	 * shut off the automatic messages for a while,
E 2
I 2
	 * Shut off the automatic messages for a while,
E 2
	 * so we can use the interupt timer to resend the invitation
	 */
D 2

    end_msgs();
    setitimer(ITIMER_REAL, &itimer, (struct itimerval *)0);
    message("Waiting for your party to respond");
    signal(SIGALRM, re_invite);
    (void) setjmp(invitebuf);

    while ((new_sockt = accept(sockt, 0, 0)) < 0) {
	if (errno != EINTR) {
	    p_error("Unable to connect with your party");
	} else {
	    /* we just returned from a interupt, keep trying */
	    continue;
E 2
I 2
	end_msgs();
	setitimer(ITIMER_REAL, &itimer, (struct itimerval *)0);
	message("Waiting for your party to respond");
	signal(SIGALRM, re_invite);
	(void) setjmp(invitebuf);
	while ((new_sockt = accept(sockt, 0, 0)) < 0) {
		if (errno == EINTR)
			continue;
		p_error("Unable to connect with your party");
E 2
	}
D 2
    }
E 2
I 2
	close(sockt);
	sockt = new_sockt;
E 2

D 2
    close(sockt);
    sockt = new_sockt;

	/* have the daemons delete the invitations now that we
	   have connected.
E 2
I 2
	/*
	 * Have the daemons delete the invitations now that we
	 * have connected.
E 2
	 */
I 2
	current_state = "Waiting for your party to respond";
	start_msgs();
E 2

D 2
    current_state = "Waiting for your party to respond";
    start_msgs();

    msg.id_num = local_id;
    ctl_transact(my_machine_addr, msg, DELETE, &response);
    msg.id_num = remote_id;
    ctl_transact(his_machine_addr, msg, DELETE, &response);
    invitation_waiting = 0;
E 2
I 2
D 4
	msg.id_num = local_id;
E 4
I 4
	msg.id_num = htonl(local_id);
E 4
	ctl_transact(my_machine_addr, msg, DELETE, &response);
D 4
	msg.id_num = remote_id;
E 4
I 4
	msg.id_num = htonl(remote_id);
E 4
	ctl_transact(his_machine_addr, msg, DELETE, &response);
	invitation_waiting = 0;
E 2
}

D 2
    /* routine called on interupt to re-invite the callee */

void re_invite()
E 2
I 2
/*
 * Routine called on interupt to re-invite the callee
 */
void
re_invite()
E 2
{
D 2
    message("Ringing your party again");
    current_line++;
E 2
I 2

	message("Ringing your party again");
	current_line++;
E 2
	/* force a re-announce */
D 2
    msg.id_num = remote_id + 1;
    announce_invite();
    longjmp(invitebuf, 1);
E 2
I 2
D 4
	msg.id_num = remote_id + 1;
E 4
I 4
	msg.id_num = htonl(remote_id + 1);
E 4
	announce_invite();
	longjmp(invitebuf, 1);
E 2
}

I 4
static	char *answers[] = {
I 5
	"answer #0",					/* SUCCESS */
E 5
	"Your party is not logged on",			/* NOT_HERE */
D 5
	"Target machine does not recognize us",		/* MACHINE_UNKNOWN */
	"Target machine can not handle remote talk",	/* UNKNOWN_REQUEST */
E 5
	"Target machine is too confused to talk to us",	/* FAILED */
I 5
	"Target machine does not recognize us",		/* MACHINE_UNKNOWN */
E 5
	"Your party is refusing messages",		/* PERMISSION_REFUSED */
I 5
	"Target machine can not handle remote talk",	/* UNKNOWN_REQUEST */
E 5
	"Target machine indicates protocol mismatch",	/* BADVERSION */
	"Target machine indicates protocol botch (addr)",/* BADADDR */
	"Target machine indicates protocol botch (ctl_addr)",/* BADCTLADDR */
};
#define	NANSWERS	(sizeof (answers) / sizeof (answers[0]))

E 4
D 2
    /* transmit the invitation and process the response */

E 2
I 2
/*
 * Transmit the invitation and process the response
 */
E 2
announce_invite()
{
D 2
    CTL_RESPONSE response;
E 2
I 2
	CTL_RESPONSE response;
E 2

D 2
    current_state = "Trying to connect to your party's talk daemon";
E 2
I 2
	current_state = "Trying to connect to your party's talk daemon";
	ctl_transact(his_machine_addr, msg, ANNOUNCE, &response);
	remote_id = response.id_num;
	if (response.answer != SUCCESS) {
D 4
		switch (response.answer) {
			
		case NOT_HERE :
			message("Your party is not logged on");
			break;
E 2

D 2
    ctl_transact(his_machine_addr, msg, ANNOUNCE, &response);
    remote_id = response.id_num;
E 2
I 2
		case MACHINE_UNKNOWN :
			message("Target machine does not recognize us");
			break;
E 2

D 2
    if (response.answer != SUCCESS) {
E 2
I 2
		case UNKNOWN_REQUEST :
			message("Target machine can not handle remote talk");
			break;
E 2

D 2
	switch (response.answer) {
	    
	    case NOT_HERE :
		message("Your party is not logged on");
		break;
E 2
I 2
		case FAILED :
			message("Target machine is too confused to talk to us");
			break;
E 2

D 2
	    case MACHINE_UNKNOWN :
		message("Target machine does not recognize us");
		break;

	    case UNKNOWN_REQUEST :
		message("Target machine can not handle remote talk");
		break;

	    case FAILED :
		message("Target machine is too confused to talk to us");
		break;

	    case PERMISSION_DENIED :
		message("Your party is refusing messages");
		break;
E 2
I 2
		case PERMISSION_DENIED :
			message("Your party is refusing messages");
			break;
		}
E 4
I 4
		if (response.answer < NANSWERS)
			message(answers[response.answer]);
E 4
		quit();
E 2
	}
D 2

	quit();
    }

E 2
	/* leave the actual invitation on my talk daemon */
D 2

    ctl_transact(my_machine_addr, msg, LEAVE_INVITE, &response);
    local_id = response.id_num;
E 2
I 2
	ctl_transact(my_machine_addr, msg, LEAVE_INVITE, &response);
	local_id = response.id_num;
E 2
}
D 2
    
E 2
I 2
D 4
	
E 4
I 4

E 4
/*
 * Tell the daemon to remove your invitation
 */
E 2
send_delete()
{
D 2
	/* tell the daemon to remove your invitation */
E 2

D 2
    msg.type = DELETE;

	/* this is just a extra clean up, so just send it
	   and don't wait for an answer */

    msg.id_num = remote_id;
    daemon_addr.sin_addr = his_machine_addr;
    if (sendto(ctl_sockt, &msg, sizeof(CTL_MSG), 0, &daemon_addr,
		    sizeof(daemon_addr)) != sizeof(CTL_MSG)) {
	    perror("send_delete remote");
    }

    msg.id_num = local_id;
    daemon_addr.sin_addr = my_machine_addr;
    if (sendto(ctl_sockt, &msg, sizeof(CTL_MSG), 0, &daemon_addr,
		    sizeof(daemon_addr)) != sizeof(CTL_MSG)) {
	    perror("send_delete local");
    }
E 2
I 2
	msg.type = DELETE;
	/*
	 * This is just a extra clean up, so just send it
	 * and don't wait for an answer
	 */
D 4
	msg.id_num = remote_id;
E 4
I 4
	msg.id_num = htonl(remote_id);
E 4
	daemon_addr.sin_addr = his_machine_addr;
D 4
	if (sendto(ctl_sockt, &msg, sizeof(CTL_MSG), 0, &daemon_addr,
	    sizeof(daemon_addr)) != sizeof(CTL_MSG))
		perror("send_delete remote");
	msg.id_num = local_id;
E 4
I 4
	if (sendto(ctl_sockt, &msg, sizeof (msg), 0, &daemon_addr,
	    sizeof (daemon_addr)) != sizeof(msg))
		perror("send_delete (remote)");
	msg.id_num = htonl(local_id);
E 4
	daemon_addr.sin_addr = my_machine_addr;
D 4
	if (sendto(ctl_sockt, &msg, sizeof(CTL_MSG), 0, &daemon_addr,
	    sizeof(daemon_addr)) != sizeof(CTL_MSG))
		perror("send_delete local");
E 4
I 4
	if (sendto(ctl_sockt, &msg, sizeof (msg), 0, &daemon_addr,
	    sizeof (daemon_addr)) != sizeof (msg))
		perror("send_delete (local)");
E 4
E 2
}
E 1
