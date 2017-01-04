h45619
s 00001/00001/00037
d D 4.2 83/03/13 18:22:57 sam 2 1
c typo
e
s 00038/00000/00000
d D 4.1 83/03/13 18:11:07 sam 1 0
c date and time created 83/03/13 18:11:07 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/*
 * Internet definitions and variables
 * specific to installation at Berkeley.
 */

/*
 * Local subnetwork address mapping.
 * The standard scheme is:
 *	internet address = network.local-part
 * where
 *	network is between 8 and 34 bits
 *	local-part is between 8 and 24 bits
 *
 * This is modified by interpreting network as 32 bits
 * and local-part as something between 8 and 23 bits
 * depending on the high bit in the local-part.  When
 * the high bit in the local-part is a 1, the upper byte
 * is interpreted as a local network extension, and used
 * as the high byte in the network (extending it to 32 bits).
 * The additional 8 bits of network number are administered
 * locally and are not visible outside Berkeley, since
 * they're part of the local-part.
 */
/* network mappings */
#define	CLASSA_LOCALNETMAP(n, in) \
	(in) & 0x800000 ? (n) | (((in) & 0xef0000) << 8) : (n)
#define	CLASSB_LOCALNETMAP(n, in) \
	(in) & 0x8000 ? (n) | (((in) & 0xef00) << 16) : (n)
#define	CLASSC_LOCALNETMAP(n, in)	(n)

/* local-part mappings */
#define	CLASSA_LOCALHOSTMAP(h, in) \
	(in) & 0x800000 ? (h) & ~0xef0000 : (h)
#define	CLASSB_LOCALHOSTMAP(h, in) \
D 2
	(in) & 0x8000 ? (n) & ~0xef00 : (h)
E 2
I 2
	(in) & 0x8000 ? (h) & ~0xef00 : (h)
E 2
#define	CLASSC_LOCALHOSTMAP(h, in)	(h)
E 1
