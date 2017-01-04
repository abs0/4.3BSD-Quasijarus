h30049
s 00014/00000/00014
d D 1.3 88/03/08 10:30:48 bostic 3 2
c add Berkeley specific copyright
e
s 00000/00000/00014
d D 1.2 87/11/23 11:15:40 minshall 2 1
c Add in some changes from Dave Borman (borman@monet).
e
s 00014/00000/00000
d D 1.1 87/11/23 11:14:09 minshall 1 0
c date and time created 87/11/23 11:14:09 by minshall
e
u
U
t
T
I 1
/*
I 3
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
E 3
 * The following is defined just in case someone should want to run
 * this telnet on a 4.2 system.
 *
 */

#ifndef	FD_SETSIZE

#define	FD_SET(n, p)	((p)->fds_bits[0] |= (1<<(n)))
#define	FD_CLR(n, p)	((p)->fds_bits[0] &= ~(1<<(n)))
#define	FD_ISSET(n, p)	((p)->fds_bits[0] & (1<<(n)))
#define FD_ZERO(p)	((p)->fds_bits[0] = 0)

#endif
E 1
