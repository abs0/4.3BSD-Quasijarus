h16511
s 00004/00004/00077
d D 1.3 87/02/15 16:42:38 lepreau 3 2
c modern syntax for asgops & inits; sccs keywords
e
s 00001/00001/00080
d D 1.2 85/05/04 00:31:36 sam 2 1
c purge old crud
e
s 00081/00000/00000
d D 1.1 85/05/03 12:36:29 sam 1 0
c date and time created 85/05/03 12:36:29 by sam
e
u
U
t
T
I 1
# include	"../hdr/defines.h"

D 3
SCCSID(@(#)setup	2.2);
E 3
I 3
static char Sccsid[] = "%W%	%G%";
E 3

setup(pkt,serial)
register struct packet *pkt;
int serial;
{
	register int n;
	register struct apply *rap;
D 3
	int	first_app	1;
E 3
I 3
	int	first_app = 1;
E 3

	pkt->p_apply[serial].a_inline = 1;
	for (n = maxser(pkt); n; n--) {
		rap = &pkt->p_apply[n];
		if (rap->a_inline) {
			if (n != 1 && pkt->p_idel[n].i_pred == 0)
				fmterr(pkt);
			pkt->p_apply[pkt->p_idel[n].i_pred].a_inline = 1;
			if (pkt->p_idel[n].i_datetime > pkt->p_cutoff)
				condset(rap,NOAPPLY,CUTOFF);
			else {
				if (first_app)
D 2
					move(&pkt->p_idel[n].i_sid,
E 2
I 2
					bcopy(&pkt->p_idel[n].i_sid,
E 2
					     &pkt->p_gotsid,
					     sizeof(pkt->p_gotsid));
				first_app = 0;
				condset(rap,APPLY,EMPTY);
			}
		}
		else
			condset(rap,NOAPPLY,EMPTY);
		if (rap->a_code == APPLY)
			ixgsetup(pkt->p_apply,&(pkt->p_idel[n].i_ixg));
	}
}


ixgsetup(ap,ixgp)
struct apply *ap;
struct ixg *ixgp;
{
	int n;
	int code, reason;
	register int *ip;
	register struct ixg *cur, *prev;

	for (cur = ixgp; cur = (prev = cur)->i_next; ) {
		switch (cur->i_type) {

		case INCLUDE:
			code = APPLY;
			reason = INCL;
			break;
		case EXCLUDE:
			code = NOAPPLY;
			reason = EXCL;
			break;
		case IGNORE:
			code = EMPTY;
			reason = IGNR;
			break;
		}
		ip = cur->i_ser;
		for (n = cur->i_cnt; n; n--)
			condset(&ap[*ip++],code,reason);
	}
}


condset(ap,code,reason)
register struct apply *ap;
int code, reason;
{
	if (code == EMPTY)
D 3
		ap->a_reason =| reason;
E 3
I 3
		ap->a_reason |= reason;
E 3
	else if (ap->a_code == EMPTY) {
		ap->a_code = code;
D 3
		ap->a_reason =| reason;
E 3
I 3
		ap->a_reason |= reason;
E 3
	}
}
E 1
