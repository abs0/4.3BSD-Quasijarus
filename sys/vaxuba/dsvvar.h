/*
 * Things settable via WIOCDSV11MODES or in the config file
 *
 *	%W% (Berkeley) %E%
 */

#define	DSV11_MODE_INTLOOP	0x0001		/* Internal Loopback */
#define	DSV11_MODE_INTCLKENAB	0x0002		/* Internal Clock Enable */
#define	DSV11_MODE_INTCLKRATE	0x001C		/* Internal Clock Rate */
#define	DSV11_MODE_INTCLKRATE_SHIFT	2
#define	DSV11_MODE_DRIVER	0x01E0		/* Cable Driver Select */
#define	DSV11_MODE_DRIVER_SHIFT		5
/* NRZI is now considered device-independent */
#define	DSV11_MODE_USEINTCLK	0x0400		/* Clock TX from internal */
