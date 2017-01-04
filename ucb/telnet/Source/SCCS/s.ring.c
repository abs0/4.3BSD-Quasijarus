h48936
s 00016/00000/00272
d D 1.8 88/03/08 10:30:54 bostic 8 7
c add Berkeley specific copyright
e
s 00072/00030/00200
d D 1.7 88/01/07 15:26:48 minshall 7 6
c Make SYNCH work (ie: urgent (ie: ring markers)).
e
s 00003/00000/00227
d D 1.6 87/11/23 20:38:04 minshall 6 5
c Fixes from Dave Borman.
e
s 00006/00000/00221
d D 1.5 87/10/27 15:58:45 minshall 5 4
c Reset ring pointers when the ring empties out.
e
s 00047/00091/00174
d D 1.4 87/10/23 11:57:27 minshall 4 3
c Make the ring buffer a two-state buffer (supplier and consumer)
c rather than a three-state buffer (supplier, sender, and acker).
e
s 00012/00000/00253
d D 1.3 87/10/10 17:45:05 minshall 3 2
c Add ring_sent_acked() for simpletons.
e
s 00044/00006/00209
d D 1.2 87/10/10 14:27:28 minshall 2 1
c This is the first version to get near rings.  It compiles,
c but doesn't work.
e
s 00215/00000/00000
d D 1.1 87/10/10 12:39:06 minshall 1 0
c date and time created 87/10/10 12:39:06 by minshall
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
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

/*
E 8
D 4
 * This defines a structure for a receive or send ring buffer.
E 4
I 4
 * This defines a structure for a ring buffer.
E 4
 *
D 4
 * The circular buffer actually has three parts:
E 4
I 4
 * The circular buffer has two parts:
E 4
 *(((
D 4
 *	full, sent, not acked:	[ack, send)
 *	full, not sent:		[send, add)
 *	empty:			[add, ack)
E 4
I 4
 *	full:	[consume, supply)
 *	empty:	[supply, consume)
E 4
 *]]]
 *
D 4
 * Any given byte will go through "empty" -> "send" -> "ack" -> "empty"
 * as data is moved through it.  The transition from "ack" to "empty"
 * may occur instantaneously (as in the case of sending data up to another
 * process).
E 4
 */

#include	<stdio.h>
#include	<errno.h>

#ifdef	size_t
#undef	size_t
#endif

#include	<sys/types.h>
#include	<sys/ioctl.h>
#include	<sys/socket.h>

#include	"ring.h"
#include	"general.h"

/* Internal macros */

D 2
#if	!defined(min)
#define	min(a,b)	(((a)<(b))? (a):(b))
#endif	/* !defined(min) */
E 2
I 2
#if	!defined(MIN)
#define	MIN(a,b)	(((a)<(b))? (a):(b))
#endif	/* !defined(MIN) */
E 2

D 2
#define	ring_subtract(d,a,b)	((((int)(a))-((int)(b)) >= 0)? (a)-(b): (((a)-(b))+(d)->size))
E 2
I 2
#define	ring_subtract(d,a,b)	((((int)(a))-((int)(b)) >= 0)? \
					(a)-(b): (((a)-(b))+(d)->size))
E 2

#define	ring_increment(d,a,c)	(((a)+(c) < (d)->top)? \
					(a)+(c) : (((a)+(c))-(d)->size))

I 7
#define	ring_decrement(d,a,c)	(((a)-(c) >= (d)->bottom)? \
					(a)-(c) : (((a)-(c))-(d)->size))
E 7

I 7

E 7
/*
 * The following is a clock, used to determine full, empty, etc.
 *
 * There is some trickiness here.  Since the ring buffers are initialized
 * to ZERO on allocation, we need to make sure, when interpreting the
D 4
 * clock, that when the times are EQUAL, then the buffer is FULL, all
 * bytes have been SENT, no bytes are waiting to be ACKED, etc.
E 4
I 4
 * clock, that when the times are EQUAL, then the buffer is FULL.
E 4
 */
static u_long ring_clock = 0;


D 4
#define	ring_add_all(d) (((d)->ack == (d)->add) && \
				((d)->acktime >= (d)->addtime))
#define	ring_send_all(d) (((d)->add == (d)->send) && \
				((d)->addtime > (d)->sendtime))
#define	ring_ack_all(d) (((d)->send == (d)->ack) && \
				((d)->sendtime > (d)->acktime))
E 4
I 4
#define	ring_empty(d) (((d)->consume == (d)->supply) && \
				((d)->consumetime >= (d)->supplytime))
#define	ring_full(d) (((d)->supply == (d)->consume) && \
				((d)->supplytime > (d)->consumetime))
E 4





/* Buffer state transition routines */

I 2
ring_init(ring, buffer, count)
Ring *ring;
char *buffer;
int count;
{
    memset((char *)ring, 0, sizeof *ring);
E 2

I 2
    ring->size = count;

D 4
    ring->add = ring->send = ring->ack = ring->bottom = buffer;
E 4
I 4
    ring->supply = ring->consume = ring->bottom = buffer;
E 4

    ring->top = ring->bottom+ring->size;

    return 1;
}

I 7
/* Mark routines */

E 7
E 2
/*
I 7
 * Mark the most recently supplied byte.
 */

void
ring_mark(ring)
Ring *ring;
{
    ring->mark = ring_decrement(ring, ring->supply, 1);
}

/*
 * Is the ring pointing to the mark?
 */

int
ring_at_mark(ring)
Ring *ring;
{
    if (ring->mark == ring->consume) {
	return 1;
    } else {
	return 0;
    }
}

/*
 * Clear any mark set on the ring.
 */

void
ring_clear_mark(ring)
Ring *ring;
{
    ring->mark = 0;
}

/*
E 7
 * Add characters from current segment to ring buffer.
 */
void
D 4
ring_added(ring, count)
E 4
I 4
ring_supplied(ring, count)
E 4
Ring *ring;
int count;
{
D 4
    ring->add = ring_increment(ring, ring->add, count);
    ring->addtime = ++ring_clock;
E 4
I 4
    ring->supply = ring_increment(ring, ring->supply, count);
    ring->supplytime = ++ring_clock;
E 4
}

/*
D 4
 * We have just sent "c" bytes.
E 4
I 4
 * We have just consumed "c" bytes.
E 4
 */
void
D 4
ring_sent(ring, count)
E 4
I 4
ring_consumed(ring, count)
E 4
Ring *ring;
int count;
{
I 6
    if (count == 0)	/* don't update anything */
	return;

I 7
    if (ring->mark &&
		(ring_subtract(ring, ring->mark, ring->consume) < count)) {
	ring->mark = 0;
    }
E 7
E 6
D 4
    ring->send = ring_increment(ring, ring->send, count);
    ring->sendtime = ++ring_clock;
E 4
I 4
    ring->consume = ring_increment(ring, ring->consume, count);
    ring->consumetime = ++ring_clock;
I 5
    /*
     * Try to encourage "ring_empty_consecutive()" to be large.
     */
    if (ring_empty(ring)) {
	ring->consume = ring->supply = ring->bottom;
    }
E 5
E 4
}

D 4
/*
 * We have just received an "ack" for "c" bytes.
 */
void
ring_acked(ring, count)
Ring *ring;
int count;
{
    ring->ack = ring_increment(ring, ring->ack, count);
    ring->acktime = ++ring_clock;
}
E 4

I 3
D 4
/*
 * We just sent and acked some data.
 */
void
ring_sent_acked(ring, count)
Ring *ring;
int count;
{
    ring_sent(ring, count);
    ring_acked(ring, count);
}
E 4

E 3
D 4

E 4
/* Buffer state query routines */


D 4
/* Number of bytes that may be added */
E 4
I 4
/* Number of bytes that may be supplied */
E 4
int
ring_empty_count(ring)
Ring *ring;
{
D 4
    if (ring_add_all(ring)) {	/* if empty */
E 4
I 4
    if (ring_empty(ring)) {	/* if empty */
E 4
	    return ring->size;
    } else {
D 4
	return ring_subtract(ring, ring->ack, ring->add);
E 4
I 4
	return ring_subtract(ring, ring->consume, ring->supply);
E 4
    }
}

D 4
/* number of CONSECUTIVE bytes that may be added */
E 4
I 4
/* number of CONSECUTIVE bytes that may be supplied */
E 4
int
ring_empty_consecutive(ring)
Ring *ring;
{
D 4
    if ((ring->ack < ring->add) || ring_add_all(ring)) {
				    /*
				     * if ack is "below" add, or empty, then
				     * return distance to the top
				     */
	return ring_subtract(ring, ring->top, ring->add);
E 4
I 4
    if ((ring->consume < ring->supply) || ring_empty(ring)) {
			    /*
			     * if consume is "below" supply, or empty, then
			     * return distance to the top
			     */
	return ring_subtract(ring, ring->top, ring->supply);
E 4
    } else {
				    /*
				     * else, return what we may.
				     */
D 4
	return ring_subtract(ring, ring->ack, ring->add);
E 4
I 4
	return ring_subtract(ring, ring->consume, ring->supply);
E 4
    }
}

D 4
/* number of bytes that are available for sending */
E 4
I 4
D 7
/* number of bytes that are available for consuming */
E 7
I 7
/* Return the number of bytes that are available for consuming
 * (but don't give more than enough to get to cross over set mark)
 */

E 7
E 4
int
D 4
ring_unsent_count(ring)
E 4
I 4
ring_full_count(ring)
E 4
Ring *ring;
{
D 4
    if (ring_send_all(ring)) {
	return ring->size;	/* nothing sent, but full */
E 4
I 4
D 7
    if (ring_full(ring)) {
	return ring->size;	/* nothing consumed, but full */
E 7
I 7
    if ((ring->mark == 0) || (ring->mark == ring->consume)) {
	if (ring_full(ring)) {
	    return ring->size;	/* nothing consumed, but full */
	} else {
	    return ring_subtract(ring, ring->supply, ring->consume);
	}
E 7
E 4
    } else {
D 4
	return ring_subtract(ring, ring->add, ring->send);
E 4
I 4
D 7
	return ring_subtract(ring, ring->supply, ring->consume);
E 7
I 7
	return ring_subtract(ring, ring->mark, ring->consume);
E 7
E 4
    }
}

D 4
/* number of CONSECUTIVE bytes available for sending */
E 4
I 4
D 7
/* number of CONSECUTIVE bytes available for consuming */
E 7
I 7
/*
 * Return the number of CONSECUTIVE bytes available for consuming.
 * However, don't return more than enough to cross over set mark.
 */
E 7
E 4
int
D 4
ring_unsent_consecutive(ring)
E 4
I 4
ring_full_consecutive(ring)
E 4
Ring *ring;
{
D 4
    if ((ring->add < ring->send) || ring_send_all(ring)) {
	return ring_subtract(ring, ring->top, ring->send);
E 4
I 4
D 7
    if ((ring->supply < ring->consume) || ring_full(ring)) {
	return ring_subtract(ring, ring->top, ring->consume);
E 7
I 7
    if ((ring->mark == 0) || (ring->mark == ring->consume)) {
	if ((ring->supply < ring->consume) || ring_full(ring)) {
	    return ring_subtract(ring, ring->top, ring->consume);
	} else {
	    return ring_subtract(ring, ring->supply, ring->consume);
	}
E 7
E 4
    } else {
D 4
	return ring_subtract(ring, ring->add, ring->send);
E 4
I 4
D 7
	return ring_subtract(ring, ring->supply, ring->consume);
E 7
I 7
	if (ring->mark < ring->consume) {
	    return ring_subtract(ring, ring->top, ring->consume);
	} else {	/* Else, distance to mark */
	    return ring_subtract(ring, ring->mark, ring->consume);
	}
E 7
E 4
    }
}

D 4
/* number of bytes awaiting acking */
int
ring_unacked_count(ring)
Ring *ring;
{
    if (ring_ack_all(ring)) {
	    return ring->size;	/* last operation was a send - nothing done */
    } else {
	return ring_subtract(ring, ring->send, ring->ack);
    }
}


E 4
/*
D 4
 * Move data into the "add" portion of of the ring buffer.
E 4
I 4
 * Move data into the "supply" portion of of the ring buffer.
E 4
 */
void
D 4
ring_add_data(ring, buffer, count)
E 4
I 4
ring_supply_data(ring, buffer, count)
E 4
Ring *ring;
char *buffer;
int count;
{
    int i;

    while (count) {
D 2
	i = min(count, ring_empty_consecutive(ring));
E 2
I 2
	i = MIN(count, ring_empty_consecutive(ring));
E 2
D 4
	memcpy(ring->add, buffer, i);
	ring_added(ring, i);
E 4
I 4
	memcpy(ring->supply, buffer, i);
	ring_supplied(ring, i);
E 4
	count -= i;
	buffer += i;
    }
}


/*
D 4
 * Move data from the "send" portion of the ring buffer
E 4
I 4
 * Move data from the "consume" portion of the ring buffer
E 4
 */
void
D 4
ring_send_data(ring, buffer, count)
E 4
I 4
ring_consume_data(ring, buffer, count)
E 4
Ring *ring;
char *buffer;
int count;
{
    int i;

    while (count) {
D 2
	i = min(count, ring_unsent_consecutive(ring));
E 2
I 2
D 4
	i = MIN(count, ring_unsent_consecutive(ring));
E 2
	memcpy(buffer, ring->send, i);
	ring_sent(ring, i);
E 4
I 4
	i = MIN(count, ring_full_consecutive(ring));
	memcpy(buffer, ring->consume, i);
	ring_consumed(ring, i);
E 4
	count -= i;
	buffer += i;
    }
I 2
D 7
}

/* Mark routines */

/* XXX do something here */
void
ring_mark(ring)
Ring *ring;
{
}

int
ring_at_mark(ring)
Ring *ring;
{
    return 0;
}

void
ring_clear_mark(ring)
Ring *ring;
{
E 7
E 2
}
E 1
