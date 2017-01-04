h07094
s 00002/00001/00128
d D 1.5 88/12/22 12:59:00 sam 5 4
c purge uses of alloca
e
s 00000/00002/00129
d D 1.4 87/07/12 19:26:06 sam 4 3
c pitch check for clock being set wrong (almost ALWAYS WRONG)
e
s 00004/00004/00127
d D 1.3 85/05/04 00:31:21 sam 3 2
c purge old crud
e
s 00001/00001/00130
d D 1.2 82/03/14 21:37:46 eric 2 1
c use defined constant for size of programmer name
e
s 00131/00000/00000
d D 1.1 81/04/13 16:26:15 eric 1 0
c date and time created 81/04/13 16:26:15 by eric
e
u
U
t
T
I 1
#include	"../hdr/defines.h"

# define ONEYEAR 31536000L

SCCSID(@(#)dodelt	2.1);

long	Timenow;

D 2
char	Pgmr[8];	/* for rmdel & chghist (rmchg) */
E 2
I 2
char	Pgmr[SZLNAM];	/* for rmdel & chghist (rmchg) */
E 2
int	First_esc;

dodelt(pkt,statp,sidp,type)
register struct packet *pkt;
struct stats *statp;
struct sid *sidp;
char type;
{
	extern	char	*satoi();
	struct deltab dt;
	register struct idel *rdp;
	int n, founddel;
	long timediff;
	register char *p;

	pkt->p_idel = 0;
	founddel = 0;

	time(&Timenow);
	stats_ab(pkt,statp);
	while (getadel(pkt,&dt) == BDELTAB) {
		if (pkt->p_idel == 0) {
			if (Timenow < dt.d_datetime)
				fprintf(stderr,"Clock may be set wrong! (co11)");
			timediff = Timenow - dt.d_datetime;
D 4
			if (timediff > ONEYEAR && pkt->p_verbose)
				fprintf(stderr,"Clock may be set wrong! (co11)\n");
E 4
			pkt->p_idel = alloc(n = ((dt.d_serial + 1) * sizeof(*pkt->p_idel)));
D 3
			zero(pkt->p_idel,n);
E 3
I 3
			bzero(pkt->p_idel,n);
E 3
			pkt->p_apply = alloc(n = ((dt.d_serial + 1) * sizeof(*pkt->p_apply)));
D 3
			zero(pkt->p_apply,n);
E 3
I 3
			bzero(pkt->p_apply,n);
E 3
			pkt->p_idel->i_pred = dt.d_serial;
		}
		if (dt.d_type == 'D') {
			if (sidp && eqsid(&dt.d_sid,sidp)) {
				copy(dt.d_pgmr,Pgmr);	/* for rmchg */
D 3
				zero(sidp,sizeof(*sidp));
E 3
I 3
				bzero(sidp,sizeof(*sidp));
E 3
				founddel = 1;
				First_esc = 1;
				for (p = pkt->p_line; *p && *p != 'D'; p++)
					;
				if (*p)
					*p = type;
			}
			else
				First_esc = founddel = 0;
			pkt->p_maxr = max(pkt->p_maxr,dt.d_sid.s_rel);
			rdp = &pkt->p_idel[dt.d_serial];
			rdp->i_sid.s_rel = dt.d_sid.s_rel;
			rdp->i_sid.s_lev = dt.d_sid.s_lev;
			rdp->i_sid.s_br = dt.d_sid.s_br;
			rdp->i_sid.s_seq = dt.d_sid.s_seq;
			rdp->i_pred = dt.d_pred;
			rdp->i_datetime = dt.d_datetime;
		}
		while ((n = getline(pkt)) != NULL)
			if (pkt->p_line[0] != CTLCHAR)
				break;
			else {
				switch (pkt->p_line[1]) {
				case EDELTAB:
					break;
				case COMMENTS:
				case MRNUM:
					if (founddel)
						escdodelt(pkt);
					continue;
				default:
					fmterr(pkt);
				case INCLUDE:
				case EXCLUDE:
				case IGNORE:
					if (dt.d_type == 'D')
						doixg(pkt->p_line,&rdp->i_ixg);
					continue;
				}
				break;
			}
		if (n == NULL || pkt->p_line[0] != CTLCHAR || getline(pkt) == NULL)
			fmterr(pkt);
		if (pkt->p_line[0] != CTLCHAR || pkt->p_line[1] != STATS)
			break;
	}
	return(pkt->p_idel);
}


getadel(pkt,dt)
register struct packet *pkt;
register struct deltab *dt;
{
	if (getline(pkt) == NULL)
		fmterr(pkt);
	return(del_ab(pkt->p_line,dt,pkt));
}


doixg(p,ixgp)
char *p;
struct ixg *ixgp;
{
	int *v, *ip;
	int type, cnt;
	struct ixg *cur, *prev;
I 5
	char buf[BUFSIZ];
E 5

D 5
	v = ip = alloca(BUFSIZ);
E 5
I 5
	v = ip = (int *)buf;
E 5
	++p;
	type = *p++;
	NONBLANK(p);
	while (numeric(*p)) {
		p = satoi(p,ip++);
		NONBLANK(p);
	}
	cnt = ip - v;
	for (cur = ixgp; cur = (prev = cur)->i_next; )
		;
	prev->i_next = cur = alloc(sizeof(*cur) + (cnt - 1) * sizeof(cur->i_ser[0]));
	cur->i_next = 0;
	cur->i_type = type;
	cur->i_cnt = cnt;
D 3
	move(v,cur->i_ser,cnt * sizeof(cur->i_ser[0]));
E 3
I 3
	bcopy(v,cur->i_ser,cnt * sizeof(cur->i_ser[0]));
E 3
}
E 1
