h06114
s 00006/00005/00033
d D 1.2 85/05/04 00:31:17 sam 2 1
c purge old crud
e
s 00038/00000/00000
d D 1.1 82/05/10 14:06:29 sam 1 0
c date and time created 82/05/10 14:06:29 by sam
e
u
U
t
T
I 1
# include	"../hdr/defines.h"

SCCSID(@(#)del_ab	2.1);

del_ab(p,dt,pkt)
register char *p;
register struct deltab *dt;
struct packet *pkt;
{
D 2
	extern	char	*satoi();
E 2
I 2
	extern	char *satoi(), *index();
E 2
	int n;
I 2
	register char *cp;
E 2
	extern char *Datep;

	if (*p++ != CTLCHAR)
		fmterr(pkt);
	if (*p++ != BDELTAB)
		return(*--p);
	NONBLANK(p);
	dt->d_type = *p++;
	NONBLANK(p);
	p = sid_ab(p,&dt->d_sid);
	NONBLANK(p);
	date_ab(p,&dt->d_datetime);
	p = Datep;
	NONBLANK(p);
D 2
	if ((n = index(p," ")) < 0)
E 2
I 2
	if ((cp = index(p,' ')) == 0)
E 2
		fmterr(pkt);
D 2
	move(p,dt->d_pgmr,n);
	dt->d_pgmr[n] = 0;
	p =+ n + 1;
E 2
I 2
	bcopy(p,dt->d_pgmr,cp-p);
	dt->d_pgmr[cp-p] = 0;
	p = cp + 1;
E 2
	NONBLANK(p);
	p = satoi(p,&dt->d_serial);
	NONBLANK(p);
	p = satoi(p,&dt->d_pred);
	if (*p != '\n')
		fmterr(pkt);
	return(BDELTAB);
}
E 1
