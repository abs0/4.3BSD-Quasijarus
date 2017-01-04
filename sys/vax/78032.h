/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)78032.h	7.1 (Berkeley) 3/18/04
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
