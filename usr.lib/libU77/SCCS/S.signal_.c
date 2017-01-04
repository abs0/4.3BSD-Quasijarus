h35138
s 00001/00001/00060
d D 1.4 81/04/19 20:01:47 dlw 4 3
c made dispatch table static. DLW
e
s 00011/00002/00050
d D 1.3 81/02/19 19:40:34 dlw 3 2
c fixed return value; must be from table if signal() returns sig_trap. DLW
e
s 00016/00002/00036
d D 1.2 81/02/19 19:18:48 dlw 2 1
c added local trap & dispatch table. DLW
e
s 00038/00000/00000
d D 1.1 81/02/14 14:45:37 dlw 1 0
c date and time created 81/02/14 14:45:37 by dlw
e
u
U
t
T
I 1
/*
char id_signal[] = "%W%";
 *
 * change the action for a specified signal
 *
 * calling sequence:
 *	integer cursig, signal, savsig
 *	external proc
 *	cursig = signal(signum, proc, flag)
 * where:
 *	'cursig' will receive the current value of signal(2)
 *	'signum' must be in the range 0 <= signum <= 16
 *
 *	If 'flag' is negative, 'proc' must be an external proceedure name.
 *	
 *	If 'flag' is 0 or positive, it will be passed to signal(2) as the
 *	signal action flag. 0 resets the default action; 1 sets 'ignore'.
 *	'flag' may be the value returned from a previous call to signal.
I 2
 *
 * This routine arranges to trap user specified signals so that it can
 * pass the signum fortran style - by address. (boo)
E 2
 */

#include	"../libI77/f_errno.h"

D 2
/*** NOTE: the type casts for procp and signal are problematical but work ***/
E 2
I 2
D 4
int (*dispatch[17])();
E 4
I 4
static int (*dispatch[17])();
E 4
E 2
int (*signal())();
I 2
int sig_trap();
E 2

long signal_(sigp, procp, flag)
long *sigp, *flag;
int (*procp)();
{
I 3
	int (*oldsig)();
	int (*oldispatch)();

	oldispatch = dispatch[*sigp];

E 3
	if (*sigp < 0 || *sigp > 16)
		return(-((long)(errno=F_ERARG)));

	if (*flag < 0)	/* function address passed */
D 2
		return((long)signal((int)*sigp, procp) );
E 2
I 2
	{
		dispatch[*sigp] = procp;
D 3
		return((long)signal((int)*sigp, sig_trap) );
E 3
I 3
		oldsig = signal((int)*sigp, sig_trap);
E 3
	}
E 2

	else		/* integer value passed */
D 3
		return((long)signal((int)*sigp, (int)*flag) );
E 3
I 3
		oldsig = signal((int)*sigp, (int)*flag);

	if (oldsig == sig_trap)
		return((long)oldispatch);
	return((long)oldsig);
E 3
I 2
}

sig_trap(sn)
int sn;
{
	long lsn = (long)sn;
	return((*dispatch[sn])(&lsn));
E 2
}
E 1
