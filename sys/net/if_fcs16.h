/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
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
 *
 *	@(#)if_fcs16.h	7.1 (Berkeley) 7/12/02
 */

/*
 * CCITT Frame Check Sequence (16-bit) definitions
 */

#define	CCITT_FCS16_INIT	0xffff		/* Initial FCS value */
#define	CCITT_FCS16_GOOD	0xf0b8		/* Good final FCS value */

#ifdef KERNEL
extern u_short ccitt_fcs16tab[256];
#endif
