h59217
s 00009/00018/00398
d D 3.2 88/03/28 13:46:33 bostic 10 9
c add Berkeley specific header
e
s 00000/00000/00416
d D 3.1 87/08/11 10:17:39 minshall 9 8
c New version numbering.
e
s 00025/00000/00391
d D 1.8 87/07/17 10:01:32 minshall 8 7
c Install sccs headers and copyright notices.
e
s 00005/00003/00386
d D 1.7 87/07/09 10:39:19 minshall 7 6
c Forget ntohs, etc.; include general.h to get rid of memcpy
c on bcopy systems.
e
s 00032/00032/00357
d D 1.6 87/06/15 23:25:16 minshall 6 5
c Performance fixes.  Reading in huge input buffers sped things 
c up lot.  Before, a test case took 40 seconds to send 100 copy commands 
c back and forth (or copy command lookalikes).  After, the same test case 
c took only 1.4 seconds.
e
s 00004/00005/00385
d D 1.5 87/06/15 22:52:08 minshall 5 4
c Fix sequence numbers above 256.
e
s 00225/00037/00165
d D 1.4 87/06/15 14:55:23 minshall 4 3
c Name changes, send/receive sequence numbers, conversation flow, 
c api_exch_flush().
e
s 00018/00005/00184
d D 1.3 87/06/15 09:25:18 minshall 3 2
c Change error messages to be malleable.
e
s 00030/00004/00159
d D 1.2 87/06/12 13:55:45 minshall 2 1
c This version connects to the other side.
e
s 00163/00000/00000
d D 1.1 87/06/11 15:27:12 minshall 1 0
c date and time created 87/06/11 15:27:12 by minshall
e
u
U
t
T
I 8
/*
D 10
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 10
I 10
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 10
 *
D 10
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
E 10
I 10
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif	/* not lint */
E 10
I 10
#endif /* not lint */
E 10

E 8
I 1
#include <stdio.h>

I 7
#include "../general/general.h"

E 7
#include "api_exch.h"

I 2
static int sock;		/* Socket number */

I 3
static char whoarewe[40] = "";
I 4
#define	WHO_ARE_WE()	fprintf(stderr, "(API %s) ", whoarewe);
E 4

I 4
static enum {CONTENTION, SEND, RECEIVE } conversation;

static struct exch_exch exch_state;

static unsigned int
    my_sequence,
    your_sequence;

E 4
E 3
E 2
D 6
static char ibuffer[40], *ibuf_next, *ibuf_last;
E 6
I 6
static char ibuffer[4000], *ibuf_next, *ibuf_last;
E 6
#define	IBUFADDED(i)		ibuf_last += (i)
D 6
#define	IBUFAVAILABLE()		(ibuf_last -ibuf_next)
E 6
I 6
#define	IBUFAVAILABLE()		(ibuf_last-ibuf_next)
E 6
#define	IBUFFER()		ibuffer
I 6
#define	IBUFFREE()		(ibuffer+sizeof ibuffer-ibuf_last-1)
E 6
I 4
#define	IBUFGETBYTES(w,l)	{ memcpy(w, ibuf_next, l); ibuf_next += l; }
E 4
D 6
#define	IBUFGETCHAR()		(*ibuf_next++)
#define	IBUFGETSHORT()		((*ibuf_next++<<8)|(*ibuf_next++&0xff))
E 6
#define	IBUFRESET()		(ibuf_next = ibuf_last = ibuffer)

D 6
char obuffer[40], *obuf_next;
E 6
I 6
char obuffer[4000], *obuf_next;
E 6
#define	OBUFADDBYTES(w,l)	{ memcpy(obuf_next, w, l); obuf_next += l; }
D 6
#define	OBUFADDCHAR(c)		(*obuf_next++ = c)
#define	OBUFADDSHORT(s)		{*obuf_next++ = (s)>>8; *obuf_next++ = s; }
E 6
#define	OBUFAVAILABLE()		(obuf_next - obuffer)
#define	OBUFFER()		obuffer
#define	OBUFRESET()		obuf_next = obuffer
#define	OBUFROOM()		(obuffer+sizeof obuffer-obuf_next)


static int
outflush()
{
    int length = OBUFAVAILABLE();

    if (length != 0) {
	if (write(sock, OBUFFER(), length) != length) {
D 3
	    perror("writing to API client");
E 3
I 3
D 4
	    fprintf(stderr, "(API %s) ", whoarewe);
E 4
I 4
	    WHO_ARE_WE();
E 4
	    perror("write");
E 3
	    return -1;
	}
	OBUFRESET();
    }
    return 0;				/* All OK */
}


static int
D 6
infill(count)
int count;
E 6
I 6
iget(location, length)
char	*location;
int	length;
E 6
{
    int i;
I 6
    int count;
E 6

    if (OBUFAVAILABLE()) {
	if (outflush() == -1) {
	    return -1;
	}
    }
D 6
    if (ibuf_next == ibuf_last) {
	IBUFRESET();
E 6
I 6
    if ((count = IBUFAVAILABLE()) != 0) {
	if (count > length) {
	    count = length;
	}
	IBUFGETBYTES(location, count);
	length -= count;
	location += count;
E 6
    }
I 4
D 6
    if ((count -= IBUFAVAILABLE()) < 0) {
	return 0;
    }
E 4
    while (count) {
	if ((i = read(sock, IBUFFER(), count)) < 0) {
E 6
I 6
    while (length) {
	if (ibuf_next == ibuf_last) {
	    IBUFRESET();
	}
	if ((count = read(sock, IBUFFER(), IBUFFREE())) < 0) {
E 6
D 3
	    perror("reading from API client");
E 3
I 3
D 4
	    fprintf(stderr, "(API %s) ", whoarewe);
E 4
I 4
	    WHO_ARE_WE();
E 4
	    perror("read");
E 3
	    return -1;
	}
I 3
D 6
	if (i == 0) {
E 6
I 6
	if (count == 0) {
E 6
	    /* Reading past end-of-file */
D 4
	    fprintf(stderr, "(API %s) End of file read\r\n", whoarewe);
E 4
I 4
	    WHO_ARE_WE();
	    fprintf(stderr, "End of file read\r\n");
E 4
	    return -1;
	}
E 3
D 6
	count -= i;
	IBUFADDED(i);
E 6
I 6
	IBUFADDED(count);
	if (count > length) {
	    count = length;
	}
	IBUFGETBYTES(location, count);
	length -= count;
	location += count;
E 6
    }
    return 0;
}

I 4
static char *
exch_to_ascii(exch)
int exch;			/* opcode to decode */
{
    switch (exch) {
    case EXCH_EXCH_COMMAND:
	return "Command";
    case EXCH_EXCH_TYPE:
	return "Type";
    case EXCH_EXCH_TURNAROUND:
	return "Turnaround";
    case EXCH_EXCH_RTS:
	return "Request to Send";
    default:
	{
	    static char unknown[40];

	    sprintf(unknown, "(Unknown exchange 0x%02x)", exch&0xff);
	    return unknown;
	}
    }
}

/*
 * Send the exch structure, updating the sequnce number field.
 */

static int
send_state()
{
    if (OBUFROOM() < sizeof exch_state) {
	if (outflush() == -1) {
	    return -1;
	}
    }
D 5
    exch_state.my_sequence = ++my_sequence;
E 5
I 5
    my_sequence = (my_sequence+1)&0xff;
    exch_state.my_sequence = my_sequence;
E 5
    exch_state.your_sequence = your_sequence;
    OBUFADDBYTES((char *)&exch_state, sizeof exch_state);
    return 0;
}

/*
 * Receive the exch structure from the other side, checking
 * sequence numbering.
 */

static int
receive_state()
{
D 6
    if (IBUFAVAILABLE() < sizeof exch_state) {
	if (infill(sizeof exch_state) == -1) {
	    return -1;
	}
E 6
I 6
    if (iget((char *)&exch_state, sizeof exch_state) == -1) {
	return -1;
E 6
    }
D 6
    IBUFGETBYTES((char *)&exch_state, sizeof exch_state);
E 6
    if (conversation != CONTENTION) {
	if (exch_state.your_sequence != my_sequence) {
	    WHO_ARE_WE();
	    fprintf(stderr, "Send sequence number mismatch.\n");
	    return -1;
	}
D 5
	if (exch_state.my_sequence != ++your_sequence) {
E 5
I 5
	if (exch_state.my_sequence != ((++your_sequence)&0xff)) {
E 5
	    WHO_ARE_WE();
	    fprintf(stderr, "Receive sequence number mismatch.\n");
	    return -1;
	}
D 5
    } else {
	/* In contention state, no sequence numbering */
	your_sequence = exch_state.my_sequence;
E 5
    }
I 5
    your_sequence = exch_state.my_sequence;
E 5
    return 0;
}

static int
enter_receive()
{
    switch (conversation) {
    case CONTENTION:
	exch_state.opcode = EXCH_EXCH_TURNAROUND;
	if (send_state() == -1) {
	    return -1;
	}
	if (receive_state() == -1) {
	    return -1;
	}
	if (exch_state.opcode != EXCH_EXCH_RTS) {
	    WHO_ARE_WE();
	    fprintf(stderr, "In CONTENTION state:  ");
	    if (exch_state.opcode == EXCH_EXCH_TURNAROUND) {
		fprintf(stderr,
		    "Both sides tried to enter RECEIVE state.\n");
	    } else {
		fprintf(stderr,
		    "Protocol error trying to enter RECEIVE state.\n");
	    }
	    return -1;
	}
	break;
    case SEND:
	exch_state.opcode = EXCH_EXCH_TURNAROUND;
	if (send_state() == -1) {
	    return -1;
	}
	break;
    }
    conversation = RECEIVE;
    return 0;
}

static int
enter_send()
{
    switch (conversation) {
    case CONTENTION:
	exch_state.opcode = EXCH_EXCH_RTS;
	if (send_state() == -1) {
	    return -1;
	}
	 /* fall through */
    case RECEIVE:
	if (receive_state() == -1) {
	    return -1;
	}
	if (exch_state.opcode != EXCH_EXCH_TURNAROUND) {
	    WHO_ARE_WE();
	    fprintf(stderr, "Conversation error - both sides in SEND state.\n");
	    return -1;
	}
    }
    conversation = SEND;
    return 0;
}

E 4
D 2
static int
E 2
I 2
int
D 4
api_exch_inbyte()
E 4
I 4
api_exch_nextcommand()
E 4
{
D 4
    if (IBUFAVAILABLE() < 1) {
	if (infill(1) == -1) {
E 4
I 4
    if (conversation != RECEIVE) {
	if (enter_receive() == -1) {
E 4
	    return -1;
	}
    }
D 4
    return IBUFGETCHAR();
E 4
I 4
    if (receive_state() == -1) {
	return -1;
    }
    if (exch_state.opcode != EXCH_EXCH_COMMAND) {
	WHO_ARE_WE();
	fprintf(stderr, "Expected a %s exchange, received a %s exchange.\n",
	    exch_to_ascii(EXCH_EXCH_COMMAND), exch_to_ascii(exch_state.opcode));
	return -1;
    }
    return exch_state.command_or_type;
E 4
}


int
E 2
api_exch_incommand(command)
int command;
{
    int i;

D 4
    if (IBUFAVAILABLE() < 1) {
	if (infill(1) == -1) {
	    return -1;
	}
E 4
I 4
    if ((i = api_exch_nextcommand()) == -1) {
	return -1;
E 4
    }
D 4
    i = IBUFGETCHAR();
E 4
    if (i != command) {
I 4
	WHO_ARE_WE();
E 4
	fprintf(stderr, "Expected API command 0x%x, got API command 0x%x.\n",
				command, i);
	return -1;
    }
    return 0;
}


D 2
static int
E 2
I 2
int
E 2
api_exch_outcommand(command)
int command;
{
D 4
    if (OBUFROOM() < 1) {
	if (outflush() == -1) {
E 4
I 4
    if (conversation != SEND) {
	if (enter_send() == -1) {
E 4
	    return -1;
	}
    }
D 4
    OBUFADDCHAR(command);
    return 0;
E 4
I 4
    exch_state.command_or_type = command;
    exch_state.opcode = EXCH_EXCH_COMMAND;
    if (send_state() == -1) {
	return -1;
    } else {
	return 0;
    }
E 4
}


D 2
static int
E 2
I 2
int
E 2
api_exch_outtype(type, length, location)
int
    type,
    length;
char
    *location;
{
D 7
    int netleng = htons(length);
E 7
I 7
    int netleng = length;
E 7

D 4
    if (OBUFROOM() < 3) {
	if (outflush() == -1) {
E 4
I 4
    if (conversation != SEND) {
	if (enter_send() == -1) {
E 4
	    return -1;
	}
    }
D 4
    OBUFADDCHAR(type);
    OBUFADDSHORT(netleng);
    if (OBUFROOM() > length) {
	OBUFADDBYTES(location, length);
    } else {
	if (outflush() == -1) {
	    return -1;
E 4
I 4
    exch_state.opcode = EXCH_EXCH_TYPE;
    exch_state.command_or_type = type;
    exch_state.length = netleng;
    if (send_state() == -1) {
	return -1;
    }
    if (length) {
	if (OBUFROOM() > length) {
	    OBUFADDBYTES(location, length);
	} else {
	    if (outflush() == -1) {
		return -1;
	    }
	    if (write(sock, location, length) != length) {
		WHO_ARE_WE();
		perror("write");
		return -1;
	    }
E 4
	}
D 4
	if (write(sock, location, length) != length) {
D 3
	    perror("writing to API client");
E 3
I 3
	    fprintf(stderr, "(API %s) ", whoarewe);
	    perror("write");
E 3
	    return -1;
	}
E 4
    }
I 4
    return 0;
E 4
}


D 2
static int
E 2
I 2
int
E 2
api_exch_intype(type, length, location)
int
    type,
    length;
char
    *location;
{
D 7
    int i, netleng = htons(length);
E 7
I 7
    int i, netleng = length;
E 7

D 4
    if (IBUFAVAILABLE() < 3) {
	if (infill(3) == -1) {
E 4
I 4
    if (conversation != RECEIVE) {
	if (enter_receive() == -1) {
E 4
	    return -1;
	}
    }
D 4
    if ((i = IBUFGETCHAR()) != type) {
	fprintf(stderr, "Expected type 0x%x, got type 0x%x.\n", type, i);
E 4
I 4
    if (receive_state() == -1) {
E 4
	return -1;
    }
D 4
    if ((i = IBUFGETSHORT()) != netleng) {
E 4
I 4
    if (exch_state.opcode != EXCH_EXCH_TYPE) {
	WHO_ARE_WE();
	fprintf(stderr,
	    "Expected to receive a %s exchange, received a %s exchange.\n",
	    exch_to_ascii(EXCH_EXCH_TYPE), exch_to_ascii(exch_state.opcode));
	return -1;
    }
    if (exch_state.command_or_type != type) {
	WHO_ARE_WE();
	fprintf(stderr, "Expected type 0x%x, got type 0x%x.\n",
	    type, exch_state.command_or_type);
	return -1;
    }
    if (exch_state.length != netleng) {
E 4
	fprintf(stderr, "Type 0x%x - expected length %d, received length %d.\n",
D 4
		type, length, ntohs(i));
E 4
I 4
D 7
		type, length, ntohs(exch_state.length));
E 7
I 7
		type, length, exch_state.length);
E 7
E 4
	return -1;
    }
D 6
    while (length) {
	if ((i = read(sock, location, length)) < 0) {
D 3
	    perror("reading from API client");
E 3
I 3
D 4
	    fprintf(stderr, "(API %s) ", whoarewe);
E 4
I 4
	    WHO_ARE_WE();
E 4
	    perror("read");
E 3
	    return -1;
	}
	length -= i;
	location += i;
E 6
I 6
    if (iget(location, length) == -1) {
	return -1;
E 6
    }
I 2
    return 0;
}

int
I 4
api_exch_flush()
{
    return outflush();
}

int
E 4
D 3
api_exch_init(sock_number)
E 3
I 3
api_exch_init(sock_number, ourname)
E 3
int sock_number;
I 3
char *ourname;
E 3
{
    sock = sock_number;
I 3
    strcpy(whoarewe, ourname);		/* For error messages */
I 4

    my_sequence = your_sequence = 0;

    conversation = CONTENTION;		/* We don't know which direction */
E 4
E 3

    IBUFRESET();
    OBUFRESET();

E 2
    return 0;
}
E 1
