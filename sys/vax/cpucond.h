/*
 * CPU support conditional compile maze
 *
 *	@(#)cpucond.h	7.4 (Berkeley) 3/18/04
 */

#ifndef _CPUCOND_
#define	_CPUCOND_

/* CPU type and architecture subsetting logic */

#if VAX630 || VAX410
#define	NEED_UV2_SUPPORT	1
#endif

#if VAX6200 || VAX650 || VAX3100
#define	NEED_CVAX_SUPPORT	1
#endif

#if VAX6400 || VAX670 || VS3100M76
#define	NEED_RIGEL_SUPPORT	1
#endif

#if NEED_UV2_SUPPORT || NEED_CVAX_SUPPORT || NEED_RIGEL_SUPPORT
#define	NEED_UVAX_SUPPORT	1
#endif

/*
 * Same mode emulation is not just for MicroVAXen any more.  Since VARM 2nd ed.
 * declared CRC, MATCHC, MOVTC, MOVTUC, and EDITPC obsolete there are even large
 * VAXen like the 9000 (which implements decimal instructions) that do not
 * implement them and thus require same mode emulation.
 */
#if NEED_UVAX_SUPPORT || VAX9000
#define	NEED_SAMEMODE_EMU	1
#endif

/*
 * Another group of instructions declared obsolete by VARM 2nd ed. is
 * ACB{F,D,G,H}, EMODx and POLYx.  This is a problem for us since Berkeley
 * Software Architecture (like VARM 1st ed.) requires that floating point
 * instructions come in complete sets.  OTOH, the same VARM 2nd ed. puts F, D
 * and G formats in the base subset.  Our solution is that if we are configured
 * to support a VAX based on VARM 2nd ed. we force on the compilation of F, D
 * and G emulators.  This simultaneously guarantees the satisfaction of the base
 * subset requirement and fills any missing ACBx/EMODx/POLYx instructions.
 */
#if NEED_RIGEL_SUPPORT || VAX9000
#ifndef EMULFFLT
#define	EMULFFLT	1
#endif
#ifndef EMULDFLT
#define	EMULDFLT	1
#endif
#ifndef EMULGFLT
#define	EMULGFLT	1
#endif
#endif

/*
 * VAX 9000 is based on VARM 2nd ed. and also implements H-float.  But since the
 * VARM 2nd ed. subsetting of ACBx/EMODx/POLYx applies to H just like F/D/G, we
 * must compile in the H-float emulator since we are not allowed to present the
 * userland with a partial H instruction set.
 */
#if VAX9000 && !defined(EMULHFLT)
#define	EMULHFLT	1
#endif

/* Now go a bit beyond the CPU core */

#if VAX410 || VAX3100 || VS3100M76
#define	NEED_BABYVAX_SUPPORT	1
#endif

/* those damn Gregorian TOY chips */
#if VAX8200 || VAX630 || NEED_BABYVAX_SUPPORT
#define	NEED_GREGTOY_SUPPORT	1
#endif

#endif
