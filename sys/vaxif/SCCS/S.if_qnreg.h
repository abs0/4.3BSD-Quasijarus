h17194
s 00000/00000/00060
d D 7.1 86/06/05 01:38:27 mckusick 2 1
c 4.3BSD release version
e
s 00060/00000/00000
d D 6.1 86/04/22 12:00:11 kridle 1 0
c MicroVAX II Integration (KA630)
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
 *
 * DEQNA Ethernet Communications Controller interface
 */
struct qndevice {
	u_short	ad0;
	u_short ad1;
	u_short rbl;
	u_short rbh;
	u_short xbl;
	u_short xbh;
	u_short vec;
	u_short csr;
};

/*
 * Command and status bits
 */
#define	RI	0100000
#define	CA	0020000
#define	FOK	0010000
#define	SE	0002000
#define	EL	0001000
#define	ILDIS	0000400
#define	XI	0000200
#define	IE	0000100
#define	RL	0000040
#define	XL	0000020
#define	BDROM	0000010
#define	NMI	0000004
#define	SR	0000002
#define	RE	0000001

/* flag bits */
#define	BINIT	0100000
#define	VALID	0100000
#define	CHAIN	0040000
#define	EOM	0020000
#define	SETUP	0010000
#define	LOWT	0000200
#define	HIGHS	0000100

/* status bits */
#define	LASTNOT	0100000
#define	UERR	0040000
#define	LOSS	0010000
#define	NOCAR	0004000
#define	STE16	0002000
#define	ABORT	0001000
#define	FAIL	0000400

#define	RESETUP	0020000
#define	DISCARD	0010000
#define	RUNT	0004000
#define	RRLH	0003400
#define	FRAME	0000004
#define	CRCERR	0000002
#define	OVF	0000001
#define	RRLL	0000377
E 1
