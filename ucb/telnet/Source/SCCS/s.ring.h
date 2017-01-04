h43473
s 00014/00000/00048
d D 1.6 88/03/08 10:30:57 bostic 6 5
c add Berkeley specific copyright
e
s 00002/00001/00046
d D 1.5 88/01/07 15:26:50 minshall 5 4
c Make SYNCH work (ie: urgent (ie: ring markers)).
e
s 00014/00024/00033
d D 1.4 87/10/23 11:57:29 minshall 4 3
c Make the ring buffer a two-state buffer (supplier and consumer)
c rather than a three-state buffer (supplier, sender, and acker).
e
s 00002/00001/00055
d D 1.3 87/10/10 17:45:07 minshall 3 2
c Add ring_sent_acked() for simpletons.
e
s 00004/00000/00052
d D 1.2 87/10/10 14:27:30 minshall 2 1
c This is the first version to get near rings.  It compiles,
c but doesn't work.
e
s 00052/00000/00000
d D 1.1 87/10/10 12:39:07 minshall 1 0
c date and time created 87/10/10 12:39:07 by minshall
e
u
U
t
T
I 1
/*
I 6
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
E 6
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
typedef struct {
D 4
    char	*ack,		/* where you can't add at */
    		*send,		/* where data comes out of */
    		*add,		/* where data comes in to */
E 4
I 4
    char	*consume,	/* where data comes out of */
    		*supply,	/* where data comes in to */
E 4
		*bottom,	/* lowest address in buffer */
D 5
		*top;		/* highest address+1 in buffer */
E 5
I 5
		*top,		/* highest address+1 in buffer */
		*mark;		/* marker (user defined) */
E 5
    int		size;		/* size in bytes of buffer */
D 4
    u_long	acktime,	/* the relations between these clocks */
		sendtime,	/* help us keep straight full, empty, etc. */
		addtime;
E 4
I 4
    u_long	consumetime,	/* help us keep straight full, empty, etc. */
		supplytime;
E 4
} Ring;

/* Here are some functions and macros to deal with the ring buffer */


#if	defined(LINT_ARGS)

I 2
/* Initialization routine */
extern int
	ring_init(Ring *ring, char *buffer, int count);

E 2
/* Data movement routines */
extern void
D 4
	ring_add_data(Ring *ring, char *buffer, int count),
	ring_send_data(Ring *ring, char *buffer, int count);
E 4
I 4
	ring_supply_data(Ring *ring, char *buffer, int count),
	ring_consume_data(Ring *ring, char *buffer, int count);
E 4

/* Buffer state transition routines */
extern void
D 4
	ring_added(Ring *ring, int count),
	ring_sent(Ring *ring, int count),
D 3
	ring_acked(Ring *ring, int count);
E 3
I 3
	ring_acked(Ring *ring, int count),
	ring_sent_acked(Ring *ring, int count);
E 4
I 4
	ring_supplied(Ring *ring, int count),
	ring_consumed(Ring *ring, int count);
E 4
E 3

/* Buffer state query routines */
extern int
	ring_empty_count(Ring *ring),
	ring_empty_consecutive(Ring *ring),
D 4
	ring_unsent_count(Ring *ring),
	ring_unsent_consecutive(Ring *ring),
	ring_unacked_count(Ring *ring);
E 4
I 4
	ring_full_count(Ring *ring),
	ring_full_consecutive(Ring *ring);
E 4

#endif	/* defined(LINT_ARGS) */
E 1
