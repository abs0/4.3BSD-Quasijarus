h05247
s 00029/00000/00000
d D 5.1 99/01/18 00:35:18 msokolov 1 0
c date and time created 99/01/18 00:35:18 by msokolov
e
u
U
t
T
I 1
/*
 * This code has been derived from Jean-loup Gailly's zlib.
 * It has been integrated into Berkeley UNIX by Michael Sokolov
 *
 *	%W% (Berkeley) %G%
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

struct inflate_codes_state;
typedef struct inflate_codes_state FAR inflate_codes_statef;

extern inflate_codes_statef *inflate_codes_new OF((
    uInt, uInt,
    inflate_huft *, inflate_huft *,
    z_streamp ));

extern int inflate_codes OF((
    inflate_blocks_statef *,
    z_streamp ,
    int));

extern void inflate_codes_free OF((
    inflate_codes_statef *,
    z_streamp ));

E 1
