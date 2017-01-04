h32819
s 00003/00003/00062
d D 5.3 85/09/11 19:33:59 mckusick 4 3
c correctly handle 32 signals, not 16
e
s 00001/00001/00064
d D 5.2 85/06/07 22:50:21 kre 3 2
c Fix botch in previous delta
e
s 00005/00001/00060
d D 5.1 85/06/07 22:37:31 kre 2 1
c Add copyright
e
s 00065/00000/00000
d D 1.1 83/01/21 11:19:18 dlw 1 0
c date and time created 83/01/21 11:19:18 by dlw
e
u
U
t
T
I 1
/*
D 2
 *	"%W%"
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
 *
I 2
 *	%W%	%G%
D 3
 */
E 3
I 3
 *
E 3
E 2
 * change the action for a specified signal
 *
 * calling sequence:
 *	integer cursig, signal, savsig
 *	external proc
 *	cursig = signal(signum, proc, flag)
 * where:
 *	'cursig' will receive the current value of signal(2)
D 4
 *	'signum' must be in the range 0 <= signum <= 16
E 4
I 4
 *	'signum' must be in the range 0 <= signum <= 32
E 4
 *
 *	If 'flag' is negative, 'proc' must be an external proceedure name.
 *	
 *	If 'flag' is 0 or positive, it will be passed to signal(2) as the
 *	signal action flag. 0 resets the default action; 1 sets 'ignore'.
 *	'flag' may be the value returned from a previous call to signal.
 *
 * This routine arranges to trap user specified signals so that it can
 * pass the signum fortran style - by address. (boo)
 */

#include	"../libI77/f_errno.h"

D 4
static int (*dispatch[17])();
E 4
I 4
static int (*dispatch[33])();
E 4
int (*signal())();
int sig_trap();

long signal_(sigp, procp, flag)
long *sigp, *flag;
int (*procp)();
{
	int (*oldsig)();
	int (*oldispatch)();

	oldispatch = dispatch[*sigp];

D 4
	if (*sigp < 0 || *sigp > 16)
E 4
I 4
	if (*sigp < 0 || *sigp > 32)
E 4
		return(-((long)(errno=F_ERARG)));

	if (*flag < 0)	/* function address passed */
	{
		dispatch[*sigp] = procp;
		oldsig = signal((int)*sigp, sig_trap);
	}

	else		/* integer value passed */
		oldsig = signal((int)*sigp, (int)*flag);

	if (oldsig == sig_trap)
		return((long)oldispatch);
	return((long)oldsig);
}

sig_trap(sn)
int sn;
{
	long lsn = (long)sn;
	return((*dispatch[sn])(&lsn));
}
E 1
