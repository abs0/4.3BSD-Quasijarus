h54129
s 00011/00001/00018
d D 3.2 88/03/28 12:54:47 bostic 5 4
c add Berkeley specific header
e
s 00000/00000/00019
d D 3.1 87/08/11 10:18:21 minshall 4 3
c New version numbering.
e
s 00001/00001/00018
d D 1.3 87/07/17 10:02:17 minshall 3 2
c Install sccs headers and copyright notices.
e
s 00004/00000/00015
d D 1.2 87/05/31 17:09:52 minshall 2 1
c Version without termcodes.m4.
e
s 00015/00000/00000
d D 1.1 87/05/10 11:35:13 minshall 1 0
c date and time created 87/05/10 11:35:13 by minshall
e
u
U
t
T
I 1
/*
D 3
 *	@(#)state.h	3.1  10/29/86
E 3
I 3
D 5
 * %W% (Berkeley) %G%
E 5
I 5
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
E 5
E 3
 */

#define	INCLUDED_STATE

/* this defines the state structure used by the key mapping routines */

I 2

#define	STATE_NULL	-1		/* Falls off edge */
#define	STATE_GOTO	-2		/* GOTO internal state */

E 2
#define state	struct State
struct State {
    int		match;		/* character to match */
    int		result;		/* 3270 control code */
    state	*next;		/* next entry in this same state */
    state	*address;	/* if goto, where is next state */
};
E 1
