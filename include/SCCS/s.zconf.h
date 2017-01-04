h03430
s 00059/00000/00000
d D 5.1 99/01/18 00:19:33 msokolov 1 0
c date and time created 99/01/18 00:19:33 by msokolov
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

/* $Id: zconf.h,v 1.1.1.1 1997/03/19 15:06:40 kivinen Exp $ */

#ifndef _ZCONF_H
#define _ZCONF_H

#define const

/* Maximum value for memLevel in deflateInit2 */
#ifndef MAX_MEM_LEVEL
#  define MAX_MEM_LEVEL 9
#endif

/* Maximum value for windowBits in deflateInit2 and inflateInit2 */
#ifndef MAX_WBITS
#  define MAX_WBITS   15 /* 32K LZ77 window */
#endif

/* The memory requirements for deflate are (in bytes):
            1 << (windowBits+2)   +  1 << (memLevel+9)
 that is: 128K for windowBits=15  +  128K for memLevel = 8  (default values)
 plus a few kilobytes for small objects. For example, if you want to reduce
 the default memory requirements from 256K to 128K, compile with
     make CFLAGS="-O -DMAX_WBITS=14 -DMAX_MEM_LEVEL=7"
 Of course this will generally degrade compression (there's no free lunch).

   The memory requirements for inflate are (in bytes) 1 << windowBits
 that is, 32K for windowBits=15 (default value) plus a few kilobytes
 for small objects.
*/

                        /* Type declarations */

#define OF(args)  ()

#define FAR

typedef unsigned char  Byte;  /* 8 bits */
typedef unsigned int   uInt;  /* 16 bits or more */
typedef unsigned long  uLong; /* 32 bits or more */

typedef Byte  FAR Bytef;
typedef char  FAR charf;
typedef int   FAR intf;
typedef uInt  FAR uIntf;
typedef uLong FAR uLongf;

typedef Byte FAR *voidpf;
typedef Byte     *voidp;

#define EXPORT

#endif /* _ZCONF_H */
E 1
