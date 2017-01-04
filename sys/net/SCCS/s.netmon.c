h14538
s 00157/00000/00000
d D 7.1 02/08/02 22:10:51 msokolov 1 0
c date and time created 02/08/02 22:10:51 by msokolov
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
 */

/*
 * Network monitor character pseudo-device
 *
 * The network monitor allows user processes to sleep until certain events
 * occur in the network. A user opens a netmon unit (each netmon can only be
 * opened once) and configures it (with ioctl) to monitor the desired events.
 * A flag, initially cleared, is set whenever a monitored event occurs. The
 * netmon device will select as ready for reading only when the flag is set.
 * Reads clear the flag and return EOF like /dev/null.
 *
 * Currently the only network events monitored are net if state changes.
 */
#include "netmon.h"

#if NNETMON > 0
#include "param.h"
#include "mbuf.h"
#include "systm.h"
#include "time.h"
#include "proc.h"
#include "file.h"
#include "socket.h"
#include "socketvar.h"
#include "dir.h"
#include "user.h"
#include "ioctl.h"
#include "errno.h"
#include "if.h"

struct netmon_softc {
	short		mon_mode;
	short		mon_state;
	caddr_t		mon_object;
	struct proc	*mon_rsel;
} netmon_softc[NNETMON];

#define	MODE_FREE	0
#define	MODE_IDLE	1
#define	MODE_IFMON	2

#define	STATE_FLAG	0x0001
#define	STATE_SELACT	0x0002
#define	STATE_SELCOLL	0x0004

netmon_open(dev, flag)
	dev_t dev;
{
	register int unit;
	register struct netmon_softc *mon;

	unit = minor(dev);
	if (unit >= NNETMON)
		return(ENXIO);
	mon = &netmon_softc[unit];
	if (mon->mon_mode != MODE_FREE)
		return(EBUSY);
	mon->mon_mode = MODE_IDLE;
	return(0);
}

netmon_close(dev, flag)
	dev_t dev;
{
	register int unit = minor(dev);
	register struct netmon_softc *mon = &netmon_softc[unit];

	mon->mon_mode = MODE_FREE;
	return(0);
}

netmon_read(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	register int unit = minor(dev);
	register struct netmon_softc *mon = &netmon_softc[unit];
	int s;

	s = splimp();
	mon->mon_state &= ~STATE_FLAG;
	splx(s);
	return(0);
}

netmon_select(dev, rw)
	dev_t dev;
{
	register int unit = minor(dev);
	register struct netmon_softc *mon = &netmon_softc[unit];
	int s;

	if (rw != FREAD)
		return(0);		/* XXX */
	s = splimp();
	if (mon->mon_state & STATE_FLAG) {
		splx(s);
		return(1);
	}
	mon->mon_state |= STATE_SELACT;
	if (mon->mon_rsel && mon->mon_rsel->p_wchan == (caddr_t)&selwait)
		mon->mon_state |= STATE_SELCOLL;
	else
		mon->mon_rsel = u.u_procp;
	splx(s);
	return(0);
}

netmon_event(mon)
	struct netmon_softc *mon;
{
	mon->mon_state |= STATE_FLAG;
	if (mon->mon_state & STATE_SELACT) {
		selwakeup(mon->mon_rsel, mon->mon_state & STATE_SELCOLL);
		mon->mon_state &= ~(STATE_SELACT | STATE_SELCOLL);
		mon->mon_rsel = 0;
	}
}

netmon_ioctl(dev, cmd, data, flag)
	caddr_t data;
{
	register int unit = minor(dev);
	register struct netmon_softc *mon = &netmon_softc[unit];
	register struct ifnet *ifp;
	register struct ifreq *ifr;

	switch (cmd) {

	case NIOCIFMON:
		ifr = (struct ifreq *) data;
		ifp = ifunit(ifr->ifr_name);
		if (ifp == 0)
			return(ENXIO);
		mon->mon_mode = MODE_IFMON;
		mon->mon_object = (caddr_t) ifp;
		return(0);

	default:
		return(ENOTTY);
	}
}

netmon_ifevent(ifp)
	register struct ifnet *ifp;
{
	register struct netmon_softc *mon, *monlast;

	for (mon = netmon_softc, monlast = mon + NNETMON; mon < monlast; mon++)
		if (mon->mon_mode == MODE_IFMON &&
		    (struct ifnet *) mon->mon_object == ifp)
			netmon_event(mon);
}
#endif
E 1
