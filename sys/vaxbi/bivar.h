/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
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
 *	@(#)bivar.h	7.3 (Berkeley) 3/6/04
 */

/*
 * Software status per BI node.
 */

struct	binode_status {
/*	int	bh_type;		/* type of adapter */
	struct	biiregs *bh_bi;		/* virt addr of registers */
	struct	biiregs *bh_physbi;	/* phys addr of registers */
	int	bh_errcnt;		/* number of errors */
	int	bh_ivec;		/* interrupt vector */
	int	bh_arb;			/* arbitration */
};

/*
 * ... per BI
 */
#ifdef notdef
/* this isn't even compilable! (redefinition) who the hell wrote this? */
struct	bi_hd {
	short	bh_nodes;		/* which nodes are present */
	struct	binode_status bh_nodes[16];	/* info about those nodes */
};
#endif

/*
 * BI device table matching device types to drivers
 */
struct	bi_devtab {
	u_short	bidt_dtype;
	short	bidt_isctlr;
	struct	uba_driver *bidt_driver;
};

#ifdef KERNEL
extern struct bi_devtab bi_devtab[];
#endif
