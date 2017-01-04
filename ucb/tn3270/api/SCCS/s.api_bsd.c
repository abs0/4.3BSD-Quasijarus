h39690
s 00009/00018/00250
d D 3.2 88/03/28 13:46:31 bostic 11 10
c add Berkeley specific header
e
s 00000/00000/00268
d D 3.1 87/08/11 10:17:37 minshall 10 9
c New version numbering.
e
s 00025/00000/00243
d D 1.9 87/07/17 10:01:28 minshall 9 8
c Install sccs headers and copyright notices.
e
s 00001/00001/00242
d D 1.8 87/07/15 15:24:34 minshall 8 7
c New directory structure
e
s 00028/00012/00215
d D 1.7 87/07/09 10:37:03 minshall 7 6
c Fixes to keep from having to enter password all the time.
e
s 00005/00001/00222
d D 1.6 87/07/09 10:17:54 minshall 6 5
c To compile on msdos and sun systems.
e
s 00008/00002/00215
d D 1.5 87/06/15 23:26:23 minshall 5 4
c Cut down on number of protocol exchanges by passing parm data 
c over with the initial parameters.
e
s 00026/00012/00191
d D 1.4 87/06/15 14:55:21 minshall 4 3
c Name changes, send/receive sequence numbers, conversation flow, 
c api_exch_flush().
e
s 00061/00000/00142
d D 1.3 87/06/15 09:23:27 minshall 3 2
c Add api_exch_api().
e
s 00082/00002/00060
d D 1.2 87/06/12 13:55:44 minshall 2 1
c This version connects to the other side.
e
s 00062/00000/00000
d D 1.1 87/06/11 15:03:15 minshall 1 0
c date and time created 87/06/11 15:03:15 by minshall
e
u
U
t
T
I 9
/*
D 11
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 11
I 11
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 11
 *
D 11
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 11
I 11
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif	/* not lint */
E 11
I 11
#endif /* not lint */
E 11

E 9
I 6
#if	defined(unix)

E 6
I 1
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>

D 8
#include "../api/api.h"
E 8
I 8
#include "../ctlr/api.h"
E 8
I 2
#include "api_exch.h"
E 2


I 4
int
api_close_api()
{
    if (api_exch_outcommand(EXCH_CMD_DISASSOCIATE) == -1) {
	return -1;
    } else if (api_exch_flush() == -1) {
	return -1;
    } else {
	return 0;
    }
}


int
E 4
D 2
static int sock = -1;

E 2
api_open_api(string)
char	*string;		/* if non-zero, where to connect to */
{
    struct sockaddr_in server;
    struct hostent *hp;
I 7
    struct storage_descriptor sd;
E 7
    char *getenv();
    char thehostname[100];
I 7
    char keyname[100];
    char inkey[100];
    FILE *keyfile;
E 7
I 2
    int sock;
E 2
    int port;
I 2
    int i;
E 2

    if (string == 0) {
	string = getenv("API3270");	/* Get API */
	if (string == 0) {
	    fprintf(stderr,
			"API3270 environmental variable not set - no API.\n");
	    return -1;			/* Nothing */
	}
    }

D 7
    if (sscanf(string, "%[^:]:%d", thehostname, &port) != 2) {
E 7
I 7
    if (sscanf(string, "%[^:]:%d:%s", thehostname, &port, keyname) != 3) {
E 7
	fprintf(stderr, "API3270 environmental variable has bad format.\n");
	return -1;
    }
    /* Now, try to connect */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
	perror("opening API socket");
	return -1;
    }
    server.sin_family = AF_INET;
    hp = gethostbyname(thehostname);
    if (hp == 0) {
	fprintf(stderr, "%s specifies bad host name.\n", string);
	return -1;
    }
    bcopy(hp->h_addr, &server.sin_addr, hp->h_length);
    server.sin_port = htons(port);

    if (connect(sock, &server, sizeof server) < 0) {
	perror("connecting to API server");
	return -1;
I 2
    }
    /* Now, try application level connection */
D 4
    if (api_exch_init(sock) == -1) {
E 4
I 4
    if (api_exch_init(sock, "client") == -1) {
E 4
	return -1;
    }
D 4
    if (api_exch_outcommand(EXCH_ASSOCIATE) == -1) {
E 4
I 4
    if (api_exch_outcommand(EXCH_CMD_ASSOCIATE) == -1) {
E 4
	return -1;
    }
I 7
    keyfile = fopen(keyname, "r");
    if (keyfile == 0) {
	perror("fopen");
	return -1;
    }
    if (fscanf(keyfile, "%s\n", inkey) != 1) {
	perror("fscanf");
	return -1;
    }
    sd.length = strlen(inkey)+1;
    if (api_exch_outtype(EXCH_TYPE_STORE_DESC, sizeof sd, (char *)&sd) == -1) {
	return -1;
    }
    if (api_exch_outtype(EXCH_TYPE_BYTES, sd.length, inkey) == -1) {
	return -1;
    }
E 7
D 4
    while ((i = api_exch_inbyte()) != EXCH_ASSOCIATED) {
E 4
I 4
    while ((i = api_exch_nextcommand()) != EXCH_CMD_ASSOCIATED) {
E 4
D 7
	struct storage_descriptor sd;
E 7
	int passwd_length;
	char *passwd, *getpass();
	char buffer[200];

	switch (i) {
D 4
	case EXCH_REJECTED:
E 4
I 4
	case EXCH_CMD_REJECTED:
E 4
	    if (api_exch_intype(EXCH_TYPE_STORE_DESC,
					sizeof sd, (char *)&sd) == -1) {
		return -1;
	    }
D 7
	    sd.length = ntohs(sd.length);
E 7
	    if (api_exch_intype(EXCH_TYPE_BYTES, sd.length, buffer) == -1) {
		return -1;
	    }
	    buffer[sd.length] = 0;
	    fprintf(stderr, "%s\n", buffer);
D 4
	    if (api_exch_outcommand(EXCH_ASSOCIATE) == -1) {
E 4
I 4
	    if (api_exch_outcommand(EXCH_CMD_ASSOCIATE) == -1) {
E 4
		return -1;
	    }
	    break;
D 4
	case EXCH_SEND_AUTH:
E 4
I 4
	case EXCH_CMD_SEND_AUTH:
E 4
	    if (api_exch_intype(EXCH_TYPE_STORE_DESC, sizeof sd, (char *)&sd) == -1) {
		return -1;
	    }
D 7
	    sd.length = ntohs(sd.length);
E 7
	    if (api_exch_intype(EXCH_TYPE_BYTES, sd.length, buffer) == -1) {
		return -1;
	    }
	    buffer[sd.length] = 0;
	    passwd = getpass(buffer);		/* Go to terminal */
	    passwd_length = strlen(passwd);
	    if (api_exch_intype(EXCH_TYPE_STORE_DESC, sizeof sd, (char *)&sd) == -1) {
		return -1;
	    }
D 7
	    sd.length = ntohs(sd.length);
E 7
	    if (api_exch_intype(EXCH_TYPE_BYTES, sd.length, buffer) == -1) {
		return -1;
	    }
	    buffer[sd.length] = 0;
	    if (sd.length) {
		char *ptr;

		ptr = passwd;
		i = 0;
		while (*ptr) {
		    *ptr++ ^= buffer[i++];
		    if (i >= sd.length) {
			i = 0;
		    }
		}
	    }
D 7
	    sd.length = htons(passwd_length);
E 7
I 7
	    sd.length = passwd_length;
E 7
D 4
	    if (api_exch_outcommand(EXCH_AUTH) == -1) {
E 4
I 4
	    if (api_exch_outcommand(EXCH_CMD_AUTH) == -1) {
E 4
		return -1;
	    }
	    if (api_exch_outtype(EXCH_TYPE_STORE_DESC, sizeof sd, (char *)&sd) == -1) {
		return -1;
	    }
	    if (api_exch_outtype(EXCH_TYPE_BYTES, passwd_length, passwd) == -1) {
		return -1;
	    }
	    break;
	case -1:
	    return -1;
	default:
	    fprintf(stderr,
		    "Waiting for connection indicator, received 0x%x.\n", i);
	    break;
	}
E 2
    }
    /* YEAH */
    return 0;		/* Happiness! */
}


D 5
api_exch_api(regs, sregs)
E 5
I 5
api_exch_api(regs, sregs, parms, length)
E 5
union REGS *regs;
struct SREGS *sregs;
I 5
char *parms;
int length;
E 5
{
I 3
    struct storage_descriptor sd;
    int i;

D 4
    if (api_exch_outcommand(EXCH_REQUEST) == -1) {
E 4
I 4
    if (api_exch_outcommand(EXCH_CMD_REQUEST) == -1) {
E 4
	return -1;
    }
    if (api_exch_outtype(EXCH_TYPE_REGS, sizeof *regs, (char *)regs) == -1) {
	return -1;
    }
    if (api_exch_outtype(EXCH_TYPE_SREGS, sizeof *sregs, (char *)sregs) == -1) {
	return -1;
    }
D 5
    sd.length = 0;
E 5
I 5
D 7
    sd.length = htons(length);
D 6
    sd.location = htonl(parms);
E 6
I 6
    sd.location = (long) htonl(parms);
E 7
I 7
    sd.length = length;
    sd.location = (long) parms;
E 7
E 6
E 5
    if (api_exch_outtype(EXCH_TYPE_STORE_DESC, sizeof sd, (char *)&sd) == -1) {
I 5
	return -1;
    }
    if (api_exch_outtype(EXCH_TYPE_BYTES, length, parms) == -1) {
E 5
	return -1;
    }
D 4
    while ((i = api_exch_inbyte()) != EXCH_REPLY) {
E 4
I 4
    while ((i = api_exch_nextcommand()) != EXCH_CMD_REPLY) {
E 4
	switch (i) {
D 4
	case EXCH_GIMME:
E 4
I 4
	case EXCH_CMD_GIMME:
E 4
	    if (api_exch_intype(EXCH_TYPE_STORE_DESC, sizeof sd, (char *)&sd)
					== -1) {
		return -1;
	    }
	    /*XXX validity check GIMME? */
D 4
	    if (api_exch_outcommand(EXCH_HEREIS) == -1) {
E 4
I 4
	    if (api_exch_outcommand(EXCH_CMD_HEREIS) == -1) {
E 4
		return -1;
	    }
	    if (api_exch_outtype(EXCH_TYPE_STORE_DESC, sizeof sd, (char *)&sd)
				== -1) {
		return -1;
	    }
D 7
	    if (api_exch_outtype(EXCH_TYPE_BYTES, ntohs(sd.length),
			    ntohl(sd.location)) == -1) {
E 7
I 7
	    if (api_exch_outtype(EXCH_TYPE_BYTES, sd.length,
			    sd.location) == -1) {
E 7
		return -1;
	    }
	    break;
D 4
	case EXCH_HEREIS:
E 4
I 4
	case EXCH_CMD_HEREIS:
E 4
	    if (api_exch_intype(EXCH_TYPE_STORE_DESC, sizeof sd, (char *)&sd)
					== -1) {
		return -1;
	    }
	    /* XXX Validty check HEREIS? */
D 7
	    if (api_exch_intype(EXCH_TYPE_BYTES, ntohs(sd.length),
			    ntohl(sd.location)) == -1) {
E 7
I 7
	    if (api_exch_intype(EXCH_TYPE_BYTES, sd.length,
			    sd.location) == -1) {
E 7
		return -1;
	    }
	    break;
	default:
	    fprintf(stderr, "Waiting for reply command, we got command %d.\n",
			i);
	    return -1;
	}
    }
    if (api_exch_intype(EXCH_TYPE_REGS, sizeof *regs, (char *)regs) == -1) {
	return -1;
    }
    if (api_exch_intype(EXCH_TYPE_SREGS, sizeof *sregs, (char *)sregs) == -1) {
	return -1;
    }
    /* YEAH */
    return 0;		/* Happiness! */
E 3
}
I 6

#endif	/* unix */
E 6
E 1
