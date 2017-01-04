h20998
s 00010/00005/00056
d D 2.6 88/06/18 14:08:02 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00052
d D 2.5 87/12/23 14:29:57 bostic 6 5
c append Berkeley header; NASA wants a copy
e
s 00002/00000/00053
d D 2.4 86/05/20 12:09:13 karels 5 4
c yow!
e
s 00018/00002/00035
d D 2.3 86/05/16 00:42:38 bloom 4 3
c only byteswap when required
e
s 00008/00004/00029
d D 2.2 86/05/15 08:45:00 bloom 3 2
c LOOP packets don't use the time field, so don't swap it
c more packets should be done this way
e
s 00000/00000/00033
d D 2.1 85/12/10 13:06:21 bloom 2 1
c Multi network support
e
s 00033/00000/00000
d D 1.1 85/06/22 22:07:46 gusella 1 0
c date and time created 85/06/22 22:07:46 by gusella
e
u
U
t
T
I 1
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

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6

#include "globals.h"
#include <protocols/timed.h>

/*
 * Two routines to do the necessary byte swapping for timed protocol
 * messages. Protocol is defined in /usr/include/protocols/timed.h
 */

bytenetorder(ptr)
struct tsp *ptr;
{
	ptr->tsp_seq = htons((u_short)ptr->tsp_seq);
D 3
	ptr->tsp_time.tv_sec = htonl((u_long)ptr->tsp_time.tv_sec);
	ptr->tsp_time.tv_usec = htonl((u_long)ptr->tsp_time.tv_usec);
E 3
I 3
D 4
	if (ptr->tsp_type != TSP_LOOP) {
E 4
I 4
	switch (ptr->tsp_type) {

I 5
	case TSP_SETTIME:
E 5
	case TSP_ADJTIME:
	case TSP_SETDATE:
	case TSP_SETDATEREQ:
E 4
		ptr->tsp_time.tv_sec = htonl((u_long)ptr->tsp_time.tv_sec);
		ptr->tsp_time.tv_usec = htonl((u_long)ptr->tsp_time.tv_usec);
I 4
		break;
	
	default:
		break;		/* nothing more needed */
E 4
	}
E 3
}

bytehostorder(ptr)
struct tsp *ptr;
{
	ptr->tsp_seq = ntohs((u_short)ptr->tsp_seq);
D 3
	ptr->tsp_time.tv_sec = ntohl((u_long)ptr->tsp_time.tv_sec);
	ptr->tsp_time.tv_usec = ntohl((u_long)ptr->tsp_time.tv_usec);
E 3
I 3
D 4
	if (ptr->tsp_type != TSP_LOOP) {
E 4
I 4
	switch (ptr->tsp_type) {

I 5
	case TSP_SETTIME:
E 5
	case TSP_ADJTIME:
	case TSP_SETDATE:
	case TSP_SETDATEREQ:
E 4
		ptr->tsp_time.tv_sec = ntohl((u_long)ptr->tsp_time.tv_sec);
		ptr->tsp_time.tv_usec = ntohl((u_long)ptr->tsp_time.tv_usec);
I 4
		break;
	
	default:
		break;		/* nothing more needed */
E 4
	}
E 3
}
E 1
