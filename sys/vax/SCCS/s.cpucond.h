h43135
s 00020/00003/00061
d D 7.4 04/03/18 19:19:15 msokolov 4 3
c add BabyVAX support (beginnings thereof)
c a few other todo closures and fixes along the way
e
s 00039/00001/00025
d D 7.3 04/01/27 22:25:40 msokolov 3 2
c add VARM 2nd ed. logic
e
s 00004/00004/00022
d D 7.2 04/01/10 22:27:08 msokolov 2 1
c #define our symbols to 1 so they can be used in #if
e
s 00026/00000/00000
d D 7.1 04/01/04 11:48:52 msokolov 1 0
c date and time created 04/01/04 11:48:52 by msokolov
e
u
U
t
T
I 1
/*
 * CPU support conditional compile maze
 *
 *	%W% (Berkeley) %G%
 */

#ifndef _CPUCOND_
#define	_CPUCOND_

I 4
/* CPU type and architecture subsetting logic */

E 4
#if VAX630 || VAX410
D 2
#define	NEED_UV2_SUPPORT
E 2
I 2
#define	NEED_UV2_SUPPORT	1
E 2
#endif

D 4
#if VAX6200 || VAX650 || VAX42
E 4
I 4
#if VAX6200 || VAX650 || VAX3100
E 4
D 2
#define	NEED_CVAX_SUPPORT
E 2
I 2
#define	NEED_CVAX_SUPPORT	1
E 2
#endif

D 4
#if VAX6400 || VAX670 || VAX43
E 4
I 4
#if VAX6400 || VAX670 || VS3100M76
E 4
D 2
#define	NEED_RIGEL_SUPPORT
E 2
I 2
#define	NEED_RIGEL_SUPPORT	1
E 2
#endif

I 4
#if NEED_UV2_SUPPORT || NEED_CVAX_SUPPORT || NEED_RIGEL_SUPPORT
#define	NEED_UVAX_SUPPORT	1
#endif

E 4
D 3
#if NEED_UV2_SUPPORT || NEED_CVAX_SUPPORT || NEED_RIGEL_SUPPORT
E 3
I 3
/*
 * Same mode emulation is not just for MicroVAXen any more.  Since VARM 2nd ed.
 * declared CRC, MATCHC, MOVTC, MOVTUC, and EDITPC obsolete there are even large
 * VAXen like the 9000 (which implements decimal instructions) that do not
 * implement them and thus require same mode emulation.
 */
D 4
#if NEED_UV2_SUPPORT || NEED_CVAX_SUPPORT || NEED_RIGEL_SUPPORT || VAX9000
E 4
I 4
#if NEED_UVAX_SUPPORT || VAX9000
E 4
E 3
D 2
#define	NEED_SAMEMODE_EMU
E 2
I 2
#define	NEED_SAMEMODE_EMU	1
I 3
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
I 4
#endif

/* Now go a bit beyond the CPU core */

#if VAX410 || VAX3100 || VS3100M76
#define	NEED_BABYVAX_SUPPORT	1
#endif

/* those damn Gregorian TOY chips */
#if VAX8200 || VAX630 || NEED_BABYVAX_SUPPORT
#define	NEED_GREGTOY_SUPPORT	1
E 4
E 3
E 2
#endif

#endif
E 1
