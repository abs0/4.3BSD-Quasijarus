h17140
s 00055/00000/00000
d D 4.1 83/06/11 16:50:42 sam 1 0
c date and time created 83/06/11 16:50:42 by sam
e
u
U
t
T
I 1
static	char *sccsid = "%W% (Berkeley) %E%";

/*
 * C shell - old jobs library sigrelse meant unblock mask
 *	     AND reinstall handler, so we simulate it here.
 */
#include <signal.h>

#define	mask(s)	(1 << ((s)-1))

static	int (*actions[NSIG])();
static	int achanged[NSIG];

/*
 * Perform action and save handler state.
 */
sigset(s, a)
	int s, (*a)();
{

	actions[s] = a;
	achanged[s] = 0;
	return ((int)signal(s, a));
}

/*
 * Release any masking of signal and
 * reinstall handler in case someone's
 * done a sigignore.
 */
sigrelse(s)
	int s;
{

	if (achanged[s]) {
		signal(s, actions[s]);
		achanged[s] = 0;
	}
	sigsetmask(sigblock(0) &~ mask(s));
}

/*
 * Ignore signal but maintain state so sigrelse
 * will restore handler.  We avoid the overhead
 * of doing a signal for each sigrelse call by
 * marking the signal's action as changed.
 */
sigignore(s)
	int s;
{

	if (actions[s] != SIG_IGN)
		achanged[s] = 1;
	signal(s, SIG_IGN);
}
E 1
