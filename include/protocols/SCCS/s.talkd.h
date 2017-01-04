h11609
s 00013/00002/00082
d D 5.3 88/07/09 14:41:15 bostic 5 4
c add Berkeley specific copyright
e
s 00067/00040/00017
d D 5.2 86/03/13 17:22:35 mckusick 4 3
c new version from sam@monet.berkeley.edu
e
s 00007/00001/00050
d D 5.1 85/06/06 09:14:50 dist 3 2
c Add copyright
e
s 00037/00043/00014
d D 1.2 84/04/11 15:13:24 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00057/00000/00000
d D 1.1 84/04/11 15:02:45 karels 1 0
c date and time created 84/04/11 15:02:45 by karels
e
u
U
t
T
I 1
D 2
/* $Header: ctl.h 1.4 83/03/28 20:46:27 moore Exp $ */
E 2
I 2
D 3
/*	%W% %G%	*/
E 3
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
E 5
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

I 4
#include <sys/types.h>
#include <sys/socket.h>
E 4
D 2
/* ctl.h describes the structure that talk and talkd pass back
   and forth
E 2
I 2
/*
D 4
 * ctl.h describes the structure that
 * talk and talkd pass back and forth.
E 4
I 4
 * This describes the protocol used by the talk server and clients.
 *
 * The talk server acts a repository of invitations, responding to
 * requests by clients wishing to rendezvous for the purpose of
 * holding a conversation.  In normal operation, a client, the caller,
 * initiates a rendezvous by sending a CTL_MSG to the server of
 * type LOOK_UP.  This causes the server to search its invitation
 * tables to check if an invitation currently exists for the caller
 * (to speak to the callee specified in the message).  If the lookup
 * fails, the caller then sends an ANNOUNCE message causing the server
 * to broadcast an announcement on the callee's login ports requesting
 * contact.  When the callee responds, the local server uses the
 * recorded invitation to respond with the appropriate rendezvous
 * address and the caller and callee client programs establish a
 * stream connection through which the conversation takes place.
E 4
E 2
 */

D 4
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

D 2
#define NAME_SIZE 9
#define TTY_SIZE 16
#define HOST_NAME_LENGTH 256
E 2
I 2
#define	NAME_SIZE	9
E 4
I 4
/*
 * Client->server request message format.
 */
typedef struct {
	u_char	vers;		/* protocol version */
	u_char	type;		/* request type, see below */
	u_char	answer;		/* not used */
	u_char	pad;
	u_long	id_num;		/* message id */
	struct	sockaddr addr;
	struct	sockaddr ctl_addr;
	long	pid;		/* caller's process id */
#define	NAME_SIZE	12
	char	l_name[NAME_SIZE];/* caller's name */
	char	r_name[NAME_SIZE];/* callee's name */
E 4
#define	TTY_SIZE	16
D 4
#define	HOST_NAME_LENGTH 256
E 4
I 4
	char	r_tty[TTY_SIZE];/* callee's tty name */
} CTL_MSG;
E 4
E 2

D 2
#define MAX_LIFE 60 /* maximum time an invitation is saved by the
			 talk daemons */
#define RING_WAIT 30  /* time to wait before refreshing invitation 
			 should be 10's of seconds less than MAX_LIFE */
E 2
I 2
D 4
#define MAX_LIFE	60	/* max time daemon saves invitations */
/* RING_WAIT should be 10's of seconds less than MAX_LIFE */
#define RING_WAIT	30	/* time to wait before refreshing invitation */
E 4
I 4
/*
 * Server->client response message format.
 */
typedef struct {
	u_char	vers;		/* protocol version */
	u_char	type;		/* type of request message, see below */
	u_char	answer;		/* respose to request message, see below */
	u_char	pad;
	u_long	id_num;		/* message id */
	struct	sockaddr addr;	/* address for establishing conversation */
} CTL_RESPONSE;
E 4
E 2

D 2
    /* the values for type */
E 2
I 2
D 4
/* type values */
#define LEAVE_INVITE	0
#define LOOK_UP		1
#define DELETE		2
#define ANNOUNCE	3
E 4
I 4
#define	TALK_VERSION	1		/* protocol version */
E 4
E 2

I 4
/* message type values */
#define LEAVE_INVITE	0	/* leave invitation with server */
#define LOOK_UP		1	/* check for invitation by callee */
#define DELETE		2	/* delete invitation by caller */
#define ANNOUNCE	3	/* announce invitation by caller */

E 4
D 2
#define LEAVE_INVITE 0
#define LOOK_UP 1
#define DELETE 2
#define ANNOUNCE 3

    /* the values for answer */

#define SUCCESS 0
#define NOT_HERE 1
#define FAILED 2
#define MACHINE_UNKNOWN 3
E 2
I 2
/* answer values */
D 4
#define SUCCESS		0
#define NOT_HERE	1
#define FAILED		2
#define MACHINE_UNKNOWN	3
E 2
#define PERMISSION_DENIED 4
D 2
#define UNKNOWN_REQUEST 5
E 2
I 2
#define UNKNOWN_REQUEST	5
E 4
I 4
#define SUCCESS		0	/* operation completed properly */
#define NOT_HERE	1	/* callee not logged in */
#define FAILED		2	/* operation failed for unexplained reason */
#define MACHINE_UNKNOWN	3	/* caller's machine name unknown */
#define PERMISSION_DENIED 4	/* callee's tty doesn't permit announce */
#define UNKNOWN_REQUEST	5	/* request has invalid type value */
#define	BADVERSION	6	/* request has invalid protocol version */
#define	BADADDR		7	/* request has invalid addr value */
#define	BADCTLADDR	8	/* request has invalid ctl_addr value */
E 4
E 2

D 2
typedef struct ctl_response CTL_RESPONSE;
E 2
I 2
D 4
typedef struct ctl_response {
	char	type;
	char	answer;
	int	id_num;
	struct	sockaddr_in addr;
} CTL_RESPONSE;
E 2

D 2
struct ctl_response {
    char type;
    char answer;
    int id_num;
    struct sockaddr_in addr;
};

typedef struct ctl_msg CTL_MSG;

struct ctl_msg {
    char type;
    char l_name[NAME_SIZE];
    char r_name[NAME_SIZE];
    int id_num;
    int pid;
    char r_tty[TTY_SIZE];
    struct sockaddr_in addr;
    struct sockaddr_in ctl_addr;
};
E 2
I 2
typedef struct ctl_msg {
	char	type;
	char	l_name[NAME_SIZE];
	char	r_name[NAME_SIZE];
	int	id_num;
	int	pid;
	char	r_tty[TTY_SIZE];
	struct	sockaddr_in addr;
	struct	sockaddr_in ctl_addr;
} CTL_MSG;
E 4
I 4
/*
 * Operational parameters.
 */
#define MAX_LIFE	60	/* max time daemon saves invitations */
/* RING_WAIT should be 10's of seconds less than MAX_LIFE */
#define RING_WAIT	30	/* time to wait before resending invitation */
E 4
E 2
E 1
