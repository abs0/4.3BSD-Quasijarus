h30196
s 00005/00002/00038
d D 1.2 86/01/03 23:46:52 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00040/00000/00000
d D 1.1 85/07/31 17:07:57 sam 1 0
c date and time created 85/07/31 17:07:57 by sam
e
u
U
t
T
I 1
D 2
/* opcodes to be simulated by kernel software: */
E 2
I 2
/*	%M%	%I%	%E%	*/

/*
 * Opcodes to be emulated by kernel software.
 */
E 2
#define	CVLF	0x76
#define	CVLD	0x77
#define	CVFL	0x86
#define	CVDL	0x87
#define	LDFD	0x97
#define	CVDF	0xa6
#define	ADDF   	0xc6
#define	ADDD	0xc7
#define	SUBF	0xd6
#define	SUBD	0xd7
#define	MULF	0xe6
#define	MULD	0xe7
#define	DIVF	0xf6
#define	DIVD	0xf7
#define	SINF	0x05
#define	COSF	0x15
#define	ATANF	0x25
#define	LOGF	0x35
#define	SQRTF	0x45
#define	EXPF	0x55
D 2

E 2

/* HFS bits:	*/
#define HFS_UNDF	0x008	/* float underflow */
#define HFS_OVF		0x004	/* float overflow */

#define HFS_RANGE	0x8000	/* set u_error to ERANGE */
#define HFS_DOM		0x4000	/* set u_error to EDOM */
#define HFS_DIVZ	0x2000  /* divide by zero flag */

/* destination types for the f.p. opcodes:	*/
#define LONG	01
#define FLOAT	02
#define	DOUBLE	03

/* exceptions:	*/
#define OVF_EXC		0x003	/* floating overflow */
#define UNDF_EXC	0x004 	/* floating underflow */
#define DIV0_EXC	0x005	/* floating divide by 0 */
E 1
