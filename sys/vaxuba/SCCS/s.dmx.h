h09734
s 00031/00000/00000
d D 7.1 99/01/10 23:19:04 msokolov 1 0
c put dmx* under SCCS
e
u
U
t
T
I 1
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 *
 * Common structures and definitions
 * for merged DMF and DMZ drivers.
 */

/*
 * Software status per octet
 */

struct dmx_softc {
	char	dmx_flags;			/* flags, below */
	char	dmx_type;			/* hardware type as character */
	char	dmx_softCAR;			/* softCAR flags per octet */
	char	dmx_ubanum;			/* uba number */
	short	dmx_unit;			/* board unit number */
	short	dmx_unit0;			/* line number of first line */
	struct	dmx_octet *dmx_octet;		/* hardware registers */
	struct	tty *dmx_tty;			/* base of ttys for octet */
	int	dmx_dmacount[8];		/* output dma count, per line */
};

/*
 * flags
 */
#define	DMX_ACTIVE	0x01		/* has been opened */
E 1
