h14198
s 00001/00000/00199
d D 5.8 03/05/09 21:23:24 msokolov 11 10
c arghh, have to #include <arpa/inet.h> to pacify cc
e
s 00007/00006/00192
d D 5.7 03/05/09 21:21:43 msokolov 10 9
c Support poor hosts with hosed DNS that don't reverse-resolve
e
s 00010/00005/00188
d D 5.6 88/06/18 14:10:42 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00184
d D 5.5 88/05/20 11:53:31 bostic 8 7
c add Berkeley specific header
e
s 00001/00001/00186
d D 5.4 86/03/13 18:05:12 mckusick 7 6
c setgid to group "write" so that terminals need not be world writable
e
s 00084/00053/00103
d D 5.3 86/03/13 17:13:04 mckusick 6 5
c new version from sam@monet.berkeley.edu
e
s 00006/00004/00150
d D 5.2 85/06/08 15:22:58 bloom 5 4
c why do small reads?  Use stdio
e
s 00007/00001/00147
d D 5.1 85/06/07 20:30:11 mckusick 4 3
c Add copyright
e
s 00013/00003/00135
d D 1.3 84/12/20 15:51:44 bloom 3 2
c select terminal which is allowing messages.  allows window systems to
c have messages directed to the windows
e
s 00096/00113/00042
d D 1.2 84/04/11 15:14:43 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00155/00000/00000
d D 1.1 84/04/11 15:03:08 karels 1 0
c date and time created 84/04/11 15:03:08 by karels
e
u
U
t
T
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

E 4
I 1
D 2
/* $Header: process.c 1.5 83/03/28 20:16:07 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8
E 4
E 2

D 2
    /* process.c handles the requests, which can be of three types:

		ANNOUNCE - announce to a user that a talk is wanted

		LEAVE_INVITE - insert the request into the table
		
		LOOK_UP - look up to see if a request is waiting in
			  in the table for the local user

		DELETE - delete invitation

     */

E 2
I 2
/*
 * process.c handles the requests, which can be of three types:
 *	ANNOUNCE - announce to a user that a talk is wanted
 *	LEAVE_INVITE - insert the request into the table
 *	LOOK_UP - look up to see if a request is waiting in
 *		  in the table for the local user
 *	DELETE - delete invitation
 */
E 2
D 6
#include "ctl.h"
E 6
I 6
#include <sys/types.h>
E 6
I 3
#include <sys/stat.h>
I 5
#include <stdio.h>
I 6
#include <syslog.h>
#include <netdb.h>
#include <netinet/in.h>
I 11
#include <arpa/inet.h>
E 11
E 6
E 5
E 3
I 2

E 2
D 6
char *strcpy();
E 6
I 6
#include <protocols/talkd.h>

char	*strcpy();
E 6
CTL_MSG *find_request();
CTL_MSG *find_match();

D 6
process_request(request, response)
D 2
CTL_MSG *request;
CTL_RESPONSE *response;
E 2
I 2
	CTL_MSG *request;
	CTL_RESPONSE *response;
E 6
I 6
process_request(mp, rp)
	register CTL_MSG *mp;
	register CTL_RESPONSE *rp;
E 6
E 2
{
D 2
    CTL_MSG *ptr;
E 2
I 2
D 6
	CTL_MSG *ptr;
E 6
I 6
	register CTL_MSG *ptr;
	extern int debug;
E 6
E 2

D 2
    response->type = request->type;
    response->id_num = 0;
E 2
I 2
D 6
	response->type = request->type;
	response->id_num = 0;
E 6
I 6
	rp->vers = TALK_VERSION;
	rp->type = mp->type;
	rp->id_num = htonl(0);
	if (mp->vers != TALK_VERSION) {
		syslog(LOG_WARNING, "Bad protocol version %d", mp->vers);
		rp->answer = BADVERSION;
		return;
	}
	mp->id_num = ntohl(mp->id_num);
	mp->addr.sa_family = ntohs(mp->addr.sa_family);
	if (mp->addr.sa_family != AF_INET) {
		syslog(LOG_WARNING, "Bad address, family %d",
		    mp->addr.sa_family);
		rp->answer = BADADDR;
		return;
	}
	mp->ctl_addr.sa_family = ntohs(mp->ctl_addr.sa_family);
	if (mp->ctl_addr.sa_family != AF_INET) {
		syslog(LOG_WARNING, "Bad control address, family %d",
		    mp->ctl_addr.sa_family);
		rp->answer = BADCTLADDR;
		return;
	}
	mp->pid = ntohl(mp->pid);
	if (debug)
		print_request("process_request", mp);
	switch (mp->type) {
E 6
E 2

D 2
    switch (request->type) {
E 2
I 2
D 6
	switch (request->type) {
E 2

	case ANNOUNCE :
I 2
		do_announce(request, response);
E 6
I 6
	case ANNOUNCE:
		do_announce(mp, rp);
E 6
		break;
E 2

D 2
	    do_announce(request, response);
	    break;

E 2
D 6
	case LEAVE_INVITE :
I 2
		ptr = find_request(request);
		if (ptr != (CTL_MSG *) 0) {
			response->id_num = ptr->id_num;
			response->answer = SUCCESS;
E 6
I 6
	case LEAVE_INVITE:
		ptr = find_request(mp);
		if (ptr != (CTL_MSG *)0) {
			rp->id_num = htonl(ptr->id_num);
			rp->answer = SUCCESS;
E 6
		} else
D 6
			insert_table(request, response);
E 6
I 6
			insert_table(mp, rp);
E 6
		break;
E 2

D 2
	    ptr = find_request(request);
	    if (ptr != (CTL_MSG *) 0) {
		response->id_num = ptr->id_num;
		response->answer = SUCCESS;
	    } else {
		insert_table(request, response);
	    }
	    break;

E 2
D 6
	case LOOK_UP :
I 2
		ptr = find_match(request);
		if (ptr != (CTL_MSG *) 0) {
			response->id_num = ptr->id_num;
			response->addr = ptr->addr;
			response->answer = SUCCESS;
E 6
I 6
	case LOOK_UP:
		ptr = find_match(mp);
		if (ptr != (CTL_MSG *)0) {
			rp->id_num = htonl(ptr->id_num);
			rp->addr = ptr->addr;
			rp->addr.sa_family = htons(ptr->addr.sa_family);
			rp->answer = SUCCESS;
E 6
		} else
D 6
			response->answer = NOT_HERE;
E 6
I 6
			rp->answer = NOT_HERE;
E 6
		break;
E 2

D 2
	    ptr = find_match(request);
	    if (ptr != (CTL_MSG *) 0) {
		response->id_num = ptr->id_num;
		response->addr = ptr->addr;
		response->answer = SUCCESS;
	    } else {
		response->answer = NOT_HERE;
	    }
	    break;

E 2
D 6
	case DELETE :
I 2
		response->answer = delete_invite(request->id_num);
E 6
I 6
	case DELETE:
		rp->answer = delete_invite(mp->id_num);
E 6
		break;
E 2

D 2
	    response->answer = delete_invite(request->id_num);
	    break;

E 2
D 6
	default :
D 2

	    response->answer = UNKNOWN_REQUEST;
	    break;

    }
E 2
I 2
		response->answer = UNKNOWN_REQUEST;
E 6
I 6
	default:
		rp->answer = UNKNOWN_REQUEST;
E 6
		break;
	}
I 6
	if (debug)
		print_response("process_request", rp);
E 6
E 2
}

D 6
struct hostent *gethostbyaddr();

do_announce(request, response)
D 2
CTL_MSG *request;
CTL_RESPONSE *response;
E 2
I 2
	CTL_MSG *request;
	CTL_RESPONSE *response;
E 6
I 6
do_announce(mp, rp)
	register CTL_MSG *mp;
	CTL_RESPONSE *rp;
E 6
E 2
{
D 2
    struct hostent *hp;
    CTL_MSG *ptr;
    int result;
E 2
I 2
	struct hostent *hp;
I 10
	char *remotehost;
E 10
	CTL_MSG *ptr;
	int result;
E 2

	/* see if the user is logged */
D 2

    result = find_user(request->r_name, request->r_tty);

    if (result != SUCCESS) {
	response->answer = result;
	return;
    }

    hp = gethostbyaddr(&request->ctl_addr.sin_addr,
			  sizeof(struct in_addr), AF_INET);

    if ( hp == (struct hostent *) 0 ) {
	response->answer = MACHINE_UNKNOWN;
	return;
    }

    ptr = find_request(request);
    if (ptr == (CTL_MSG *) 0) {
	insert_table(request,response);
	response->answer = announce(request, hp->h_name);
    } else if (request->id_num > ptr->id_num) {
	    /*
	     * this is an explicit re-announce, so update the id_num
	     * field to avoid duplicates and re-announce the talk 
	     */
	ptr->id_num = response->id_num = new_id();
	response->answer = announce(request, hp->h_name);
    } else {
	    /* a duplicated request, so ignore it */
E 2
I 2
D 6
	result = find_user(request->r_name, request->r_tty);
E 6
I 6
	result = find_user(mp->r_name, mp->r_tty);
E 6
	if (result != SUCCESS) {
D 6
		response->answer = result;
E 6
I 6
		rp->answer = result;
E 6
		return;
	}
D 6
	hp = gethostbyaddr(&request->ctl_addr.sin_addr,
		sizeof(struct in_addr), AF_INET);
E 6
I 6
#define	satosin(sa)	((struct sockaddr_in *)(sa))
	hp = gethostbyaddr(&satosin(&mp->ctl_addr)->sin_addr,
		sizeof (struct in_addr), AF_INET);
E 6
D 10
	if (hp == (struct hostent *)0) {
D 6
		response->answer = MACHINE_UNKNOWN;
E 6
I 6
		rp->answer = MACHINE_UNKNOWN;
E 6
		return;
	}
E 10
I 10
	if (hp != (struct hostent *)0)
		remotehost = hp->h_name;
	else
		remotehost = inet_ntoa(&satosin(&mp->ctl_addr)->sin_addr);
E 10
D 6
	ptr = find_request(request);
E 6
I 6
	ptr = find_request(mp);
E 6
	if (ptr == (CTL_MSG *) 0) {
D 6
		insert_table(request,response);
		response->answer = announce(request, hp->h_name);
E 6
I 6
		insert_table(mp, rp);
D 10
		rp->answer = announce(mp, hp->h_name);
E 10
I 10
		rp->answer = announce(mp, remotehost);
E 10
E 6
		return;
	}
D 6
	if (request->id_num > ptr->id_num) {
E 6
I 6
	if (mp->id_num > ptr->id_num) {
E 6
		/*
D 6
		 * this is an explicit re-announce, so update the id_num
		 * field to avoid duplicates and re-announce the talk 
E 6
I 6
		 * This is an explicit re-announce, so update the id_num
		 * field to avoid duplicates and re-announce the talk.
E 6
		 */
D 6
		ptr->id_num = response->id_num = new_id();
		response->answer = announce(request, hp->h_name);
		return;
E 6
I 6
		ptr->id_num = new_id();
		rp->id_num = htonl(ptr->id_num);
D 10
		rp->answer = announce(mp, hp->h_name);
E 10
I 10
		rp->answer = announce(mp, remotehost);
E 10
	} else {
		/* a duplicated request, so ignore it */
		rp->id_num = htonl(ptr->id_num);
		rp->answer = SUCCESS;
E 6
	}
D 6
	/* a duplicated request, so ignore it */
E 2
	response->id_num = ptr->id_num;
	response->answer = SUCCESS;
E 6
D 2
    }

    return;
E 2
}

#include <utmp.h>

/*
 * Search utmp for the local user
 */
D 2

E 2
find_user(name, tty)
D 2
char *name;
char *tty;
E 2
I 2
D 6
	char *name;
	char *tty;
E 6
I 6
	char *name, *tty;
E 6
E 2
{
D 2
    struct utmp ubuf;
E 2
I 2
	struct utmp ubuf;
D 5
	int fd, status;
E 5
I 5
	int status;
	FILE *fd;
E 5
I 3
	struct stat statb;
	char ftty[20];
E 3
E 2

D 2
    int fd;

    if ((fd = open("/etc/utmp", 0)) == -1) {
	print_error("Can't open /etc/utmp");
	return(FAILED);
    }

    while (read(fd, (char *) &ubuf, sizeof ubuf) == sizeof(ubuf)) {
	if (strncmp(ubuf.ut_name, name, sizeof ubuf.ut_name) == 0) {
	    if (*tty == '\0') {
		    /* no particular tty was requested */
		(void) strcpy(tty, ubuf.ut_line);
		close(fd);
		return(SUCCESS);
	    } else if (strcmp(ubuf.ut_line, tty) == 0) {
		close(fd);
		return(SUCCESS);
	    }
E 2
I 2
D 5
	if ((fd = open("/etc/utmp", 0)) == -1) {
E 5
I 5
	if ((fd = fopen("/etc/utmp", "r")) == NULL) {
E 5
		perror("Can't open /etc/utmp");
		return (FAILED);
E 2
	}
D 2
    }

    close(fd);
    return(NOT_HERE);
E 2
I 2
#define SCMPN(a, b)	strncmp(a, b, sizeof (a))
	status = NOT_HERE;
I 3
	(void) strcpy(ftty, "/dev/");
E 3
D 5
	while (read(fd, (char *) &ubuf, sizeof ubuf) == sizeof(ubuf))
E 5
I 5
	while (fread((char *) &ubuf, sizeof ubuf, 1, fd) == 1)
E 5
		if (SCMPN(ubuf.ut_name, name) == 0) {
			if (*tty == '\0') {
I 3
				status = PERMISSION_DENIED;
E 3
				/* no particular tty was requested */
D 3
				(void) strcpy(tty, ubuf.ut_line);
				status = SUCCESS;
				break;
E 3
I 3
				(void) strcpy(ftty+5, ubuf.ut_line);
				if (stat(ftty,&statb) == 0) {
D 7
					if (!(statb.st_mode & 02))
E 7
I 7
					if (!(statb.st_mode & 020))
E 7
						continue;
					(void) strcpy(tty, ubuf.ut_line);
					status = SUCCESS;
					break;
				}
E 3
			}
			if (strcmp(ubuf.ut_line, tty) == 0) {
				status = SUCCESS;
				break;
			}
		}
D 5
	close(fd);
E 5
I 5
	fclose(fd);
E 5
	return (status);
E 2
}
E 1
