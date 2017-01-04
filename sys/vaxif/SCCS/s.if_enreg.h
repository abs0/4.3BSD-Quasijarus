h13360
s 00013/00002/00036
d D 7.2 88/08/04 15:17:30 bostic 6 5
c add Berkeley specific copyright
e
s 00001/00001/00037
d D 7.1 86/06/05 01:35:45 mckusick 5 4
c 4.3BSD release version
e
s 00007/00001/00031
d D 6.2 85/06/08 13:55:12 mckusick 4 3
c Add copyright
e
s 00000/00000/00032
d D 6.1 83/07/29 07:37:49 sam 3 2
c 4.2 distribution
e
s 00001/00001/00031
d D 4.2 81/11/07 14:15:22 wnj 2 1
c EN_&
e
s 00032/00000/00000
d D 4.1 81/11/07 11:03:08 wnj 1 0
c date and time created 81/11/07 11:03:08 by wnj
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 5
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
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
E 6
 *
 *	%W% (Berkeley) %G%
 */
E 4

/*
 * Xerox experimental ethernet registers.
 *
 * N.B.: status register and device address are read/write,
 * device address is read-only, rest are WRITE ONLY!
 */
struct endevice {
	short	en_owc;		/* output word count (10 bits) */
	short	en_oba;		/* output buffer address */
	short	en_ostat;	/* output control and status */
	short	en_odelay;	/* output start delay, 25usec units  */
	short	en_iwc;		/* input word count */
	short	en_iba;		/* input buffer address */
	short	en_istat;	/* input csr */
	short	en_addr;	/* ~device address (low 8 bits) */
};

/*
 * Control and status bits.
 */
#define EN_IERROR	0x8000		/* CRC error, buf ovflo or overrun */
#define	EN_OERROR	0x8000		/* collision or output underrun */
#define EN_OPDONE	0x0080		/* previous operation completed */
#define EN_IEN		0x0040		/* enable interrupt when DONE */
D 2
#define	EN_PROMISCUOOS	0x0002		/* promiscuous, input any packet */
E 2
I 2
#define	EN_PROMISCUOUS	0x0002		/* promiscuous, input any packet */
E 2
#define EN_GO		0x0001		/* start op bit */

#define	EN_BITS	"\10\20ERR\10OPDONE\7IEN\2PROM\1GO"

#define	spl_enet()	spl5()
E 1
