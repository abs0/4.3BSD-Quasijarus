h17244
s 00000/00001/00030
d D 1.2 87/06/25 15:35:41 bostic 2 1
c KERNBASE defined in machparam.h
e
s 00031/00000/00000
d D 1.1 86/02/25 16:04:40 sam 1 0
c date and time created 86/02/25 16:04:40 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include <sys/vm.h>

#define	PAGSIZ		(NBPG*CLSIZE)

#define DBNAME "adb\n"
#define LPRMODE "%R"
#define OFFMODE "+%R"
#define	TXTRNDSIZ	PAGSIZ

#define	MAXINT	0x7fffffff
#define	MAXSTOR (KERNBASE - ctob(UPAGES))
#define	MAXFILE 0xffffffff

/*
 * INSTACK tells whether its argument is a stack address.
 * INUDOT tells whether its argument is in the (extended) u. area.
 * These are used for consistency checking and dont have to be exact.
 *
 * INKERNEL tells whether its argument is a kernel space address.
 * KVTOPH trims a kernel virtal address back to its offset
 * in the kernel address space.
 */
#define	INSTACK(x)	(((int)(x)&0xf0000000) == 0xb0000000)
#define	INUDOT(x)	(((int)(x)&0xf0000000) == 0xb0000000)
#define	INKERNEL(x)	(((int)(x)&0xf0000000) == 0xc0000000)

D 2
#define	KERNBASE	0xc0000000
E 2
#define	KERNOFF		(KERNBASE + 0x800)	/* start of kernel's text */
#define	KVTOPH(x)	((x)&~ 0xc0000000)
E 1
