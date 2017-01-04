h39073
s 00014/00002/00016
d D 3.2 88/03/28 12:18:28 bostic 4 3
c add Berkeley specific headers
e
s 00000/00000/00018
d D 3.1 87/08/11 10:21:02 minshall 3 2
c New version numbering.
e
s 00002/00000/00016
d D 1.2 87/07/16 16:03:03 minshall 2 1
c Add sccs, copyrights.
e
s 00016/00000/00000
d D 1.1 87/06/19 09:34:23 minshall 1 0
c date and time created 87/06/19 09:34:23 by minshall
e
u
U
t
T
I 1
/*
I 4
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

/*
E 4
 * Where the fields fall on the formatted screen used by tncomp, tnrecv,
 * and tnsend.
I 2
D 4
 *
 * %W% (Berkeley) %G%
E 4
E 2
 */

#define	SEND_SEQUENCE		1
#define	SEND_SEQUENCE_LENGTH	23

#define	ACK_SEQUENCE	(SEND_SEQUENCE+SEND_SEQUENCE_LENGTH+1)
#define	ACK_SEQUENCE_LENGTH	22

#define	CHECKSUM	(ACK_SEQUENCE+ACK_SEQUENCE_LENGTH+1)
#define	CHECKSUM_LENGTH		32

#define	DATA		(CHECKSUM+CHECKSUM_LENGTH+1)
#define	DATA_LENGTH		((80*22)+79)
E 1
