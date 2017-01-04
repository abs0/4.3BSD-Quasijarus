h55907
s 00014/00000/00032
d D 1.5 88/03/08 10:30:45 bostic 5 4
c add Berkeley specific copyright
e
s 00005/00005/00027
d D 1.4 87/10/23 11:57:16 minshall 4 3
c Make the ring buffer a two-state buffer (supplier and consumer)
c rather than a three-state buffer (supplier, sender, and acker).
e
s 00002/00002/00030
d D 1.3 87/10/10 16:11:08 minshall 3 2
c This version (appears to) works.
e
s 00010/00012/00022
d D 1.2 87/10/10 14:27:09 minshall 2 1
c This is the first version to get near rings.  It compiles,
c but doesn't work.
e
s 00034/00000/00000
d D 1.1 87/09/11 15:40:29 minshall 1 0
c date and time created 87/09/11 15:40:29 by minshall
e
u
U
t
T
I 5
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
 */

E 5
I 1
#define	settimer(x)	clocks.x = clocks.system++

#if	!defined(TN3270)

D 2
#define	ExitString(f,s,r)	{ fprintf(f, s); exit(r); }
E 2
I 2
#define	ExitString(s,r)	{ fprintf(stderr, s); exit(r); }
E 2
#define	Exit(x)			exit(x)
#define	SetIn3270()

#endif	/* !defined(TN3270) */

D 2
#define	NETADD(c)	{ *nfrontp++ = c; }
E 2
I 2
D 3
#define	NETADD(c)	{ *netoring.send = c; ring_added(&netoring, 1); }
E 3
I 3
D 4
#define	NETADD(c)	{ *netoring.add = c; ring_added(&netoring, 1); }
E 4
I 4
#define	NETADD(c)	{ *netoring.supply = c; ring_supplied(&netoring, 1); }
E 4
E 3
E 2
#define	NET2ADD(c1,c2)	{ NETADD(c1); NETADD(c2); }
D 2
#define NETLOC()	(nfrontp)
#define	NETMAX()	(netobuf+sizeof netobuf-1)
#define	NETBYTES()	(nfrontp-nbackp)
#define	NETROOM()	(NETMAX()-NETLOC()+1)
E 2
I 2
D 4
#define	NETBYTES()	(ring_unsent_count(&netoring))
E 4
I 4
#define	NETBYTES()	(ring_full_count(&netoring))
E 4
#define	NETROOM()	(ring_empty_count(&netoring))
E 2

D 2
#define	TTYADD(c)	{ if (!(SYNCHing||flushout)) { *tfrontp++ = c; } }
#define	TTYLOC()	(tfrontp)
#define	TTYMAX()	(ttyobuf+sizeof ttyobuf-1)
#define	TTYMIN()	(netobuf)
#define	TTYBYTES()	(tfrontp-tbackp)
#define	TTYROOM()	(TTYMAX()-TTYLOC()+1)
E 2
I 2
#define	TTYADD(c)	if (!(SYNCHing||flushout)) { \
D 3
				*ttyoring.send = c; \
E 3
I 3
D 4
				*ttyoring.add = c; \
E 3
				ring_added(&ttyoring, 1); \
E 4
I 4
				*ttyoring.supply = c; \
				ring_supplied(&ttyoring, 1); \
E 4
			}
D 4
#define	TTYBYTES()	(ring_unsent_count(&ttyoring))
E 4
I 4
#define	TTYBYTES()	(ring_full_count(&ttyoring))
E 4
#define	TTYROOM()	(ring_empty_count(&ttyoring))
E 2

/*	Various modes */
#define	MODE_LINE(m)	(modelist[m].modetype & LINE)
#define	MODE_LOCAL_CHARS(m)	(modelist[m].modetype &  LOCAL_CHARS)
#define	MODE_LOCAL_ECHO(m)	(modelist[m].modetype & LOCAL_ECHO)
#define	MODE_COMMAND_LINE(m)	(modelist[m].modetype & COMMAND_LINE)

#define	LOCAL_CHARS	0x01		/* Characters processed locally */
#define	LINE		0x02		/* Line-by-line mode of operation */
#define	LOCAL_ECHO	0x04		/* Echoing locally */
#define	COMMAND_LINE	0x08		/* Command line mode */
E 1
