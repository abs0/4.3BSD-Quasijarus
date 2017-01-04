h58289
s 00000/00000/00037
d D 2.1 81/07/01 11:07:35 kurt 2 1
c Release to Heidi Stettner
e
s 00037/00000/00000
d D 1.1 80/10/08 09:49:11 kas 1 0
c date and time created 80/10/08 09:49:11 by kas
e
u
U
f b 
t
T
I 1
#

#include <signal.h>

/*
 * The following is for systems with botched signal() system entries
 * which don't return the proper value for the previous signal.
 */

int	oldsigs[17];

static char *SccsId = "%W% %G%";

int
(*Signal())(sig, spot)
	int spot;
{
	int ret;

	/* printf("Signal(%d, %.1o)\n", sig, spot); */
	if (sig < 1 || sig > 16)
		return(-1);
	ret = oldsigs[sig];
	oldsigs[sig] = (int) spot;
	signal(sig, spot);
	return(ret);
}

Siginit()
{
	register int i;

	for (i = 1; i < 17; i++) {
		oldsigs[i] = (int) signal(i, SIG_IGN);
		signal(i, (int (*)()) oldsigs[i]);
	}
}
E 1
