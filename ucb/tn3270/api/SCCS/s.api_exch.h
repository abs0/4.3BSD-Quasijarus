h00103
s 00014/00002/00125
d D 3.2 88/03/28 13:46:36 bostic 8 7
c add Berkeley specific header
e
s 00000/00000/00127
d D 3.1 87/08/11 10:17:42 minshall 7 6
c New version numbering.
e
s 00001/00000/00126
d D 1.6 87/07/17 10:01:37 minshall 6 5
c Install sccs headers and copyright notices.
e
s 00008/00004/00118
d D 1.5 87/07/09 10:37:57 minshall 5 4
c Fixes to keep from having to enter password all the time.
e
s 00068/00015/00054
d D 1.4 87/06/15 14:55:24 minshall 4 3
c Name changes, send/receive sequence numbers, conversation flow, 
c api_exch_flush().
e
s 00010/00009/00059
d D 1.3 87/06/15 09:24:06 minshall 3 2
c Add/rename some functions.
e
s 00006/00003/00062
d D 1.2 87/06/12 13:55:46 minshall 2 1
c This version connects to the other side.
e
s 00065/00000/00000
d D 1.1 87/06/11 15:28:38 minshall 1 0
c date and time created 87/06/11 15:28:38 by minshall
e
u
U
t
T
I 1
/*
I 8
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
 */

/*
E 8
 * This file describes the structures passed back and forth
 * between the API client and API server on a Unix-based
 * tn3270 implementation.
I 2
D 8
 *
I 6
 * %W% (Berkeley) %G%
E 8
E 6
D 4
 * A command is: <command code> <sequence number> <parameter>*
E 4
I 4
 */

/*
 * The following are the low-level opcodes exchanged between the
 * two sides.  These are designed to allow for type, sequence number,
 * and direction checking.
E 4
 *
I 4
 * We enforce conversation flow.  There are three states: CONTENTION,
 * SEND, and RECEIVE.  Both sides start in CONTENTION.
 * We never leave RECEIVE state without first reading a TURNAROUND
 * opcode.  We never leave SEND state without first writing a TURNAROUND
 * opcode.  This scheme ensures that we always have conversation flowing
 * in a synchronized direction (or detect an application error), and that
 * we never hang with both sides trying to read from the "wire".
 *
 * State	event			action
 *
 * CONTENTION	read request		send TURNAROUND
 *					read RTS
 *					enter RECEIVE
 * CONTENTION	write request		send RTS
 *					read TURNAROUND
 *					enter SEND
 *
 * RECEIVE	read request		read whatever
 * RECEIVE	write request		read TURNAROUND
 *
 * SEND		read request		send TURNAROUND
 * SEND		write			write whatever
E 4
E 2
 */

I 4
#define	EXCH_EXCH_COMMAND	0	/* The following is a command */
#define	EXCH_EXCH_TURNAROUND	1	/* Your turn to send */
#define	EXCH_EXCH_RTS		2	/* Request to send */
#define	EXCH_EXCH_TYPE		3	/* The following is a type */
E 4

D 2
#define	EXCH_CONNECT	23	/* Connect request [client->server] */
E 2
I 2
D 3
#define	EXCH_ASSOCIATE	23	/* Connect request [client->server] */
E 2
#define	EXCH_SEND_AUTH	44	/* Send auth (password) [server->client] */
E 3
I 3
D 4
#define	EXCH_ASSOCIATE		23	/* Connect [client->server] */
#define	EXCH_DISASSOCIATE	39	/* Disconnect [client->server] */
#define	EXCH_SEND_AUTH		44	/* Send password [server->client] */
E 4
I 4
struct exch_exch {
    unsigned char
	opcode,			/* COMMAND, TURNAROUND, or TYPE */
	my_sequence,		/* 0-ff, initially zero */
	your_sequence,		/* 0-ff, initially zero */
	command_or_type;	/* Application level command or type */
    unsigned short
	length;			/* The length of any following data */
};

/*
 * The following are the command codes which the higher level protocols
 * send and receive.
 */

#define	EXCH_CMD_ASSOCIATE	0	/* Connect [client->server] */
I 5
	/*
	 * struct storage_desc
	 * char key[]
	 */
E 5
#define	EXCH_CMD_DISASSOCIATE	1	/* Disconnect [client->server] */
#define	EXCH_CMD_SEND_AUTH	2	/* Send password [server->client] */
E 4
E 3
	/*
D 5
	 * struct storeage_desc
E 5
I 5
	 * struct storage_desc
E 5
	 * char prompt[]
D 5
	 * struct storeage_desc
E 5
I 5
	 * struct storage_desc
E 5
	 * char seed[]
	 */
D 3
#define	EXCH_AUTH	65	/* Authorization [client->server] */
E 3
I 3
D 4
#define	EXCH_AUTH		65	/* Authorization [client->server] */
E 4
I 4
#define	EXCH_CMD_AUTH		3	/* Authorization [client->server] */
E 4
E 3
	/*
D 5
	 * struct storeage_desc
E 5
I 5
	 * struct storage_desc
E 5
	 * char authenticator[]
	 */
D 2
#define	EXCH_CONNECTED	78	/* You are now connected [server->client] */
E 2
I 2
D 3
#define	EXCH_ASSOCIATED	78	/* You are now connected [server->client] */
E 2
#define	EXCH_REJECTED	93	/* Too bad [server->client] */
E 3
I 3
D 4
#define	EXCH_ASSOCIATED		78	/* Connected [server->client] */
#define	EXCH_REJECTED		93	/* Too bad [server->client] */
E 4
I 4
#define	EXCH_CMD_ASSOCIATED	4	/* Connected [server->client] */
#define	EXCH_CMD_REJECTED	5	/* Too bad [server->client] */
E 4
E 3
	/*
D 5
	 * struct storeage_desc
E 5
I 5
	 * struct storage_desc
E 5
	 * char message[]
	 */

D 3
#define	EXCH_REQUEST	19	/* A request [client->server] */
E 3
I 3
D 4
#define	EXCH_REQUEST		19	/* A request [client->server] */
E 4
I 4
#define	EXCH_CMD_REQUEST	6	/* A request [client->server] */
E 4
E 3
	/* struct regs,
	 * struct sregs,
	 * struct storage_desc
	 * char bytes[]
	 */
D 3
#define	EXCH_GIMME	20	/* I need client storage [server->client] */
E 3
I 3
D 4
#define	EXCH_GIMME		20	/* Send storage [server->client] */
E 4
I 4
#define	EXCH_CMD_GIMME		7	/* Send storage [server->client] */
E 4
E 3
	/*
	 * struct storage_desc
	 */
D 3
#define	EXCH_HEREIS	49	/* Here is some storage [BOTH WAYS] */
E 3
I 3
D 4
#define	EXCH_HEREIS		49	/* Here is storage [BOTH WAYS] */
E 4
I 4
#define	EXCH_CMD_HEREIS		8	/* Here is storage [BOTH WAYS] */
E 4
E 3
	/*
	 * struct storage_desc
	 * char bytes[]
	 */
D 3
#define	EXCH_REPLY	87	/* End of discussion */
E 3
I 3
D 4
#define	EXCH_REPLY		87	/* End of discussion */
E 4
I 4
#define	EXCH_CMD_REPLY		9	/* End of discussion */
E 4
E 3
	/*
	 * struct regs,
	 * struct sregs,
	 */

D 4
#define	EXCH_TYPE_REGS		13
#define	EXCH_TYPE_SREGS		27
#define	EXCH_TYPE_STORE_DESC	33
#define	EXCH_TYPE_BYTES		67
E 4
I 4
/*
 * The following are typed parameters sent across the wire.
 *
 * This should be done much more generally, with some form of
 * XDR or mapped conversation ability.
 */

#define	EXCH_TYPE_REGS		0
#define	EXCH_TYPE_SREGS		1
#define	EXCH_TYPE_STORE_DESC	2
#define	EXCH_TYPE_BYTES		3
E 4

/*
D 2
 * each structure that comes over looks like:
E 2
I 2
 * each parameter that comes over looks like:
E 2
 *
 *	char			type of following
 *	short (2 bytes)		length of following (network byte order)
 *	following
 */

struct storage_descriptor {
    long	location;	/* In network byte order */
    short	length;		/* In network byte order */
};
E 1
