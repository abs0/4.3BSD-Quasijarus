h48451
s 00019/00000/00000
d D 5.1 99/01/18 00:35:19 msokolov 1 0
c date and time created 99/01/18 00:35:19 by msokolov
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

extern int inflate_fast OF((
    uInt,
    uInt,
    inflate_huft *,
    inflate_huft *,
    inflate_blocks_statef *,
    z_streamp ));
E 1
