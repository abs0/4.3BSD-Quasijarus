h57579
s 00022/00000/00000
d D 7.1 04/03/18 19:08:45 msokolov 1 0
c put common 78032 chip definitions in a header file of its own
e
u
U
t
T
I 1
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

/*
 * Definitions for the 78032 (MicroVAX II) chip.
 * Common to all systems using 78032.
 */

#define NMCUV2	10
struct mcuv2frame {
	int	mcuv2_bcnt;		/* byte count == 0xc */
	int	mcuv2_summary;		/* summary parameter */
	int	mcuv2_mrvaddr;		/* most recent vad */
	int	mcuv2_istate;		/* internal state */
	int	mcuv2_pc;		/* trapped pc */
	int	mcuv2_psl;		/* trapped psl */
};
E 1
