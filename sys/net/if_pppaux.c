/*
 *	@(#)if_pppaux.c	7.3 (Berkeley) 4/5/08
 */

/*
 * The pppaux character device provides an auxiliary access channel
 * to a ppp interface for functions like authentication.
 */
#include "ppp.h"
#include "pppaux.h"

#if NPPPAUX > 0
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
#include "if_hdlc.h"
#include "if_pppvar.h"
#include "if_pppaux.h"

struct pppaux_softc pppaux_softc[NPPP];

pppaux_init()
{
	register struct pppaux_softc *ppa;
	register int i = 0;

	for (ppa = pppaux_softc, i = 0; i < NPPP; ppa++, i++)
		ppa->ppaux_rxq.ifq_maxlen = PPPAUX_RXQ_MAXLEN;
}

pppaux_open(dev, flag)
	dev_t dev;
{
	register int unit;

	unit = minor(dev);
	if (unit >= NPPP)
		return(ENXIO);
	return(0);
}

pppaux_close(dev, flag)
	dev_t dev;
{
	int unit = minor(dev);
	register struct pppaux_softc *ppa = &pppaux_softc[unit];
	int s;

	ppa->ppaux_nproto = 0;
	s = splnet();
	if_qflush(&ppa->ppaux_rxq);
	ppa->ppaux_flags = 0;
	ppa->ppaux_rsel = 0;
	splx(s);
	return(0);
}

pppaux_ioctl(dev, cmd, data, flag)
	caddr_t data;
{
	int unit = minor(dev);
	register struct ppp_softc *pp = &ppp_softc[unit];
	register struct pppaux_softc *ppa = &pppaux_softc[unit];
	struct pppaux_ioctl *ioc;
	struct pppaux_stat_ioctl *iocs;
	int i, s, error;
	struct ppp_authproto authbuf[PPP_NAUTH];

	switch (cmd) {

	case FIONBIO:
		if (*(int *)data)
			ppa->ppaux_flags |= PPPAUX_FLAGS_NBIO;
		else
			ppa->ppaux_flags &= ~PPPAUX_FLAGS_NBIO;
		return(0);

	case PPPAUXIOC_SETPROTOS:
		ioc = (struct pppaux_ioctl *) data;
		if (ioc->pauioc_count > PPPAUX_MAXPROTO)
			return(E2BIG);	/* best I could find */
		s = splnet();
		if (ioc->pauioc_count) {
			error = copyin(ioc->pauioc_buf, ppa->ppaux_protolist,
					ioc->pauioc_count * sizeof(u_short));
			if (error) {
				splx(s);
				return(error);
			}
		}
		ppa->ppaux_nproto = ioc->pauioc_count;
		splx(s);
		return(0);

	case PPPAUXIOC_GETPROTOS:
		ioc = (struct pppaux_ioctl *) data;
		if (ioc->pauioc_count > ppa->ppaux_nproto)
			ioc->pauioc_count = ppa->ppaux_nproto;
		if (ioc->pauioc_count)
			error = copyout(ppa->ppaux_protolist, ioc->pauioc_buf,
					ioc->pauioc_count * sizeof(u_short));
		else
			error = 0;
		return(error);

	case PPPAUXIOC_SETAUTHSELF:
		if (!suser())
			return (u.u_error);
		ioc = (struct pppaux_ioctl *) data;
		if (ioc->pauioc_count > PPP_NAUTH)
			return(E2BIG);	/* best I could find */
		bzero(authbuf, sizeof authbuf);
		if (ioc->pauioc_count) {
			error = copyin(ioc->pauioc_buf, authbuf,
			    ioc->pauioc_count * sizeof(struct ppp_authproto));
			if (error)
				return(error);
		}
		for (i = 0; i < ioc->pauioc_count; i++)
			if ((unsigned)authbuf[i].authproto_nparambytes >
			    PPP_AUTH_MAXP)
				return(EINVAL);
		s = splnet();
		pp->pp_busy = 1;
		if (pp->pp_state != PPP_STATE_INITIAL) {
			pp->pp_busy = 0;
			splx(s);
			return(EBUSY);
		}
		pp->pp_authself_nprotos = ioc->pauioc_count;
		bcopy(authbuf, pp->pp_authself_protos, sizeof authbuf);
		pp->pp_busy = 0;
		splx(s);
		return(0);

	case PPPAUXIOC_GETAUTHSELF:
		ioc = (struct pppaux_ioctl *) data;
		if (ioc->pauioc_count > pp->pp_authself_nprotos)
			ioc->pauioc_count = pp->pp_authself_nprotos;
		if (ioc->pauioc_count)
			error = copyout(pp->pp_authself_protos, ioc->pauioc_buf,
			    ioc->pauioc_count * sizeof(struct ppp_authproto));
		else
			error = 0;
		return(error);

	case PPPAUXIOC_GETSTATE:
		iocs = (struct pppaux_stat_ioctl *) data;
		bzero(iocs, sizeof(struct pppaux_stat_ioctl));
		s = splnet();
		pp->pp_busy = 1;
		iocs->paus_state = pp->pp_state;
		iocs->paus_flags = pp->pp_flags;
		if (pp->pp_peerconf & PEERCONF_NEEDAUTH)
			bcopy(pp->pp_authself_protos + pp->pp_authself_index,
				&iocs->paus_authself,
				sizeof(struct ppp_authproto));
		if (pp->pp_authpeer_nprotos)
			bcopy(pp->pp_authpeer_protos + pp->pp_authpeer_index,
				&iocs->paus_authpeer,
				sizeof(struct ppp_authproto));
		pp->pp_busy = 0;
		splx(s);
		return(0);

	default:
		return(ENOTTY);
	}
}

/*
 * Called from ppp_unknown_process() at splnet
 * Returns 1 if packet accepted, 0 otherwise.
 */
pppaux_input(pp, m, proto)
	struct ppp_softc *pp;
	struct mbuf *m;
	register int proto;
{
	register struct pppaux_softc *ppa = &pppaux_softc[pp->pp_if.if_unit];
	register int i;

	for (i = 0; i < ppa->ppaux_nproto; i++)
		if (ppa->ppaux_protolist[i] == proto) {
			pppaux_input_accept(ppa, m);
			return(1);
		}
	return(0);
}

pppaux_input_accept(ppa, m)
	register struct pppaux_softc *ppa;
	register struct mbuf *m;
{
	if (IF_QFULL(&ppa->ppaux_rxq)) {
		IF_DROP(&ppa->ppaux_rxq);
		m_freem(m);
		return;
	}
	IF_ENQUEUE(&ppa->ppaux_rxq, m);
	wakeup(&ppa->ppaux_rxq);
	if (ppa->ppaux_rsel) {
		selwakeup(ppa->ppaux_rsel, ppa->ppaux_flags&PPPAUX_FLAGS_RCOLL);
		ppa->ppaux_flags &= ~PPPAUX_FLAGS_RCOLL;
		ppa->ppaux_rsel = 0;
	}
}

pppaux_read(dev, uio)
	dev_t dev;
	register struct uio *uio;
{
	int unit = minor(dev);
	register struct pppaux_softc *ppa = &pppaux_softc[unit];
	register struct mbuf *m, *n;
	int s, error = 0;

retry:	s = splnet();
	IF_DEQUEUE(&ppa->ppaux_rxq, m);
	if (!m) {
		if (ppa->ppaux_flags & PPPAUX_FLAGS_NBIO) {
			splx(s);
			return(EWOULDBLOCK);
		} else {
			sleep(&ppa->ppaux_rxq, PZERO+1);
			splx(s);
			goto retry;
		}
	}
	splx(s);

	while (m && uio->uio_resid) {
		error = uiomove(mtod(m, caddr_t),
				MIN(m->m_len, uio->uio_resid), UIO_READ, uio);
		if (error)
			break;
		MFREE(m, n);
		m = n;
	}
	if (m)
		m_freem(m);
	return(error);
}

pppaux_select(dev, rw)
	dev_t dev;
	int rw;
{
	register struct pppaux_softc *ppa = &pppaux_softc[minor(dev)];
	int s = splnet();

	switch (rw) {

	case FREAD:
		if (ppa->ppaux_rxq.ifq_len) {
			splx(s);
			return(1);
		}
		if (ppa->ppaux_rsel &&
				ppa->ppaux_rsel->p_wchan == (caddr_t)&selwait)
			ppa->ppaux_flags |= PPPAUX_FLAGS_RCOLL;
		else
			ppa->ppaux_rsel = u.u_procp;
		break;

	case FWRITE:
		/* dump and run, always ready */
		splx(s);
		return(1);

	}
	splx(s);
	return (0);
}

pppaux_write(dev, uio)
	dev_t dev;
	register struct uio *uio;
{
	int unit = minor(dev);
	register struct ppp_softc *pp = &ppp_softc[unit];
	register struct mbuf *m, **mp;
	struct mbuf *top;
	struct sockaddr hh;
	int s, len, error;

	if (uio->uio_resid < sizeof(struct hdlc_header) + 1)
		return(EINVAL);
	hh.sa_family = AF_UNSPEC;
	error = uiomove(hh.sa_data, sizeof(struct hdlc_header), UIO_WRITE, uio);
	if (error)
		return(error);

	s = splnet();		/* this interlock is for the MTU sanity check */
	pp->pp_busy = 1;
	if (pp->pp_state != PPP_STATE_OPENED) {
		pp->pp_busy = 0;
		splx(s);
		return(ENETDOWN);
	}
	if (uio->uio_resid > pp->pp_if.if_mtu) {
		pp->pp_busy = 0;
		splx(s);
		return(EMSGSIZE);
	}
	pp->pp_busy = 0;
	splx(s);

	/*
	 * The following code has been lifted from sosend()
	 */
	top = 0;
	mp = &top;
	while (uio->uio_resid > 0) {
		MGET(m, M_WAIT, MT_DATA);
		if (uio->uio_resid >= CLBYTES / 2) {
			MCLGET(m);
			if (m->m_len != CLBYTES)
				goto nopages;
			len = MIN(CLBYTES, uio->uio_resid);
		} else {
nopages:		len = MIN(MLEN, uio->uio_resid);
		}
		error = uiomove(mtod(m, caddr_t), len, UIO_WRITE, uio);
		m->m_len = len;
		*mp = m;
		if (error) {
			m_freem(top);
			return(error);
		}
		mp = &m->m_next;
	}

	/* good to go! */
	return(pppoutput(&pp->pp_if, top, &hh));
}
#endif
