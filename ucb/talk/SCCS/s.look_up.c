h05298
s 00010/00005/00077
d D 5.4 88/06/29 20:22:27 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00073
d D 5.3 88/05/20 12:37:09 bostic 6 5
c add Berkeley specific header
e
s 00019/00084/00057
d D 5.2 86/03/13 17:41:27 mckusick 5 4
c new version from sam@monet.berkeley.edu
e
s 00007/00001/00134
d D 5.1 85/06/06 09:18:58 dist 4 3
c Add copyright
e
s 00071/00001/00064
d D 1.3 84/05/11 14:20:11 layer 3 2
c Now works between SUNs and VAXen
e
s 00039/00052/00026
d D 1.2 84/04/11 15:14:25 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00078/00000/00000
d D 1.1 84/04/11 15:02:59 karels 1 0
c date and time created 84/04/11 15:02:59 by karels
e
u
U
t
T
I 4
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

E 4
I 1
D 2
/* $Header: look_up.c 1.2 83/03/28 00:34:22 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6
E 4
E 2

#include "talk_ctl.h"

I 3
D 5

E 5
E 3
D 2
    /* see if the local daemon has a invitation for us */

E 2
I 2
/*
D 5
 * See if the local daemon has a invitation for us
E 5
I 5
 * See if the local daemon has an invitation for us.
E 5
 */
E 2
check_local()
{
D 2
    CTL_RESPONSE response;
E 2
I 2
	CTL_RESPONSE response;
I 5
	register CTL_RESPONSE *rp = &response;
E 5
E 2

	/* the rest of msg was set up in get_names */
D 2

    msg.ctl_addr = ctl_addr;

    if (!look_for_invite(&response)) {

	    /* we must be initiating a talk */

	return(0);
    }

        /*
	 * there was an invitation waiting for us, 
E 2
I 2
D 5
	msg.ctl_addr = ctl_addr;
E 5
I 5
	msg.ctl_addr = *(struct sockaddr *)&ctl_addr;
	msg.ctl_addr.sa_family = htons(msg.ctl_addr.sa_family);
E 5
D 3
	if (!look_for_invite(&response))	/* must be initiating a talk */
E 3
I 3
	/* must be initiating a talk */
D 5
	if (!look_for_invite(&response))
E 5
I 5
	if (!look_for_invite(rp))
E 5
E 3
		return (0);
	/*
	 * There was an invitation waiting for us, 
E 2
	 * so connect with the other (hopefully waiting) party 
	 */
D 2

    current_state = "Waiting to connect with caller";

    while (connect(sockt, &response.addr, sizeof(response.addr)) != 0) {
E 2
I 2
	current_state = "Waiting to connect with caller";
D 5
again:
I 3
	swapresponse(&response);
E 3
	if (connect(sockt, &response.addr, sizeof(response.addr)) != -1)
		return (1);
	if (errno == EINTR)
		goto again;
E 5
I 5
	do {
		if (rp->addr.sa_family != AF_INET)
			p_error("Response uses invalid network address");
		errno = 0;
		if (connect(sockt, &rp->addr, sizeof (rp->addr)) != -1)
			return (1);
	} while (errno == EINTR);
E 5
E 2
	if (errno == ECONNREFUSED) {
D 2

		/* the caller gave up, but his invitation somehow
E 2
I 2
		/*
		 * The caller gave up, but his invitation somehow
E 2
		 * was not cleared. Clear it and initiate an 
		 * invitation. (We know there are no newer invitations,
		 * the talkd works LIFO.)
		 */
D 2

	    ctl_transact(his_machine_addr, msg, DELETE, &response);
	    close(sockt);
	    open_sockt();
	    return(0);
	} else if (errno == EINTR) {
		/* we have returned from an interupt handler */
	    continue;
	} else {
	    p_error("Unable to connect with initiator");
E 2
I 2
D 5
		ctl_transact(his_machine_addr, msg, DELETE, &response);
E 5
I 5
		ctl_transact(his_machine_addr, msg, DELETE, rp);
E 5
		close(sockt);
		open_sockt();
		return (0);
E 2
	}
D 2
    }

    return(1);
E 2
I 2
	p_error("Unable to connect with initiator");
	/*NOTREACHED*/
E 2
}

D 2
    /* look for an invitation on 'machine' */

E 2
I 2
/*
 * Look for an invitation on 'machine'
 */
E 2
D 5
look_for_invite(response)
D 2
CTL_RESPONSE *response;
E 2
I 2
	CTL_RESPONSE *response;
E 5
I 5
look_for_invite(rp)
	CTL_RESPONSE *rp;
E 5
E 2
{
D 2
    struct in_addr machine_addr;
E 2
I 2
	struct in_addr machine_addr;
E 2

D 2
    current_state = "Checking for invitation on caller's machine";
E 2
I 2
	current_state = "Checking for invitation on caller's machine";
D 5
	ctl_transact(his_machine_addr, msg, LOOK_UP, response);
E 5
I 5
	ctl_transact(his_machine_addr, msg, LOOK_UP, rp);
E 5
	/* the switch is for later options, such as multiple invitations */
D 5
	switch (response->answer) {
E 5
I 5
	switch (rp->answer) {
E 5
E 2

D 2
    ctl_transact(his_machine_addr, msg, LOOK_UP, response);

	/* the switch is for later options, such as multiple 
	   invitations */

    switch (response->answer) {

E 2
	case SUCCESS:
I 2
D 5
		msg.id_num = response->id_num;
E 5
I 5
		msg.id_num = htonl(rp->id_num);
E 5
		return (1);
E 2

D 2
	    msg.id_num = response->id_num;
	    return(1);

E 2
D 5
	default :
E 5
I 5
	default:
E 5
		/* there wasn't an invitation waiting for us */
D 2
	    return(0);
    }
E 2
I 2
		return (0);
	}
E 2
}
I 3
D 5

/*  
 * heuristic to detect if need to reshuffle CTL_RESPONSE structure
 */

#define swapshort(a) (((a << 8) | ((unsigned short) a >> 8)) & 0xffff)
#define swaplong(a) ((swapshort(a) << 16) | (swapshort(((unsigned)a >> 16))))

#ifdef sun
struct ctl_response_vax {
	char type;
	char answer;
	short junk;
	int id_num;
	struct sockaddr_in addr;
};

swapresponse(rsp)
	CTL_RESPONSE *rsp;
{
	struct ctl_response_vax swaprsp;
	
	if (rsp->addr.sin_family != AF_INET) {
		bcopy(rsp, &swaprsp, sizeof(CTL_RESPONSE));
		swaprsp.addr.sin_family = swapshort(swaprsp.addr.sin_family);
		if (swaprsp.addr.sin_family == AF_INET) {
			rsp->addr = swaprsp.addr;
			rsp->type = swaprsp.type;
			rsp->answer = swaprsp.answer;
			rsp->id_num = swaplong(swaprsp.id_num);
		}
	}
}
#endif

#ifdef vax
struct ctl_response_sun {
	char type;
	char answer;
	unsigned short id_num2;
	unsigned short id_num1;
	short sin_family;
	short sin_port;
	short sin_addr2;
	short sin_addr1;
};

swapresponse(rsp)
	CTL_RESPONSE *rsp;
{
	struct ctl_response_sun swaprsp;
	
	if (rsp->addr.sin_family != AF_INET) {
		bcopy(rsp, &swaprsp, sizeof(struct ctl_response_sun));
		if (swaprsp.sin_family == swapshort(AF_INET)) {
			rsp->type = swaprsp.type;
			rsp->answer = swaprsp.answer;
			rsp->id_num = swapshort(swaprsp.id_num1)
			    | (swapshort(swaprsp.id_num2) << 16);
			rsp->addr.sin_family = swapshort(swaprsp.sin_family);
 			rsp->addr.sin_port = swaprsp.sin_port;
			rsp->addr.sin_addr.s_addr =
			    swaprsp.sin_addr2 | (swaprsp.sin_addr1 << 16);
		}
	}
}
#endif
E 5
E 3
E 1
