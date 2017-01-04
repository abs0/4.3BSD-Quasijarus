h10736
s 00008/00006/00079
d D 1.3 88/02/02 15:56:56 bostic 4 3
c sprintf doesn't return a pointer to it's first arg, anymore
e
s 00018/00007/00067
d D 1.2 87/02/15 16:31:18 lepreau 3 1
c multiple group stuff; purge old crud (presumably by Sam 5/85, ci'ed by Jay)
e
s 00017/00006/00068
d R 1.2 87/02/15 16:28:11 lepreau 2 1
c add multiple group staff; purge old crud (by Sam 5/85)
e
s 00074/00000/00000
d D 1.1 83/11/11 15:53:14 karels 1 0
c date and time created 83/11/11 15:53:14 by karels
e
u
U
t
T
I 3
#include <sys/param.h>
E 3
I 1
# include	"../hdr/defines.h"

D 3
SCCSID(%W%);
E 3
I 3
SCCSID(%W%	%G%);
E 3

finduser(pkt)
register struct packet *pkt;
{
	register char *p;
	register int i;
	char *user;
D 3
	char *strend();
	char userid[6];
E 3
I 3
	char *index();
	int gid, ngroups = NGROUPS, groups[NGROUPS];
E 3
	int none;

	none = 1;
	user = logname();
D 3
	sprintf(userid,"%d",getuid() & 0377);
E 3
I 3
	if (getgroups(&ngroups, groups) < 0) {
		perror("getgroups");
		ngroups = 0;
	}
E 3
	while ((p = getline(pkt)) != NULL && *p != CTLCHAR) {
		none = 0;
		repl(p,'\n','\0');	/* this is done for equal test below */
D 3
		if (!pkt->p_user)
			if (equal(user,p) || equal(userid,p))
E 3
I 3
		if (!pkt->p_user) {
			if (equal(user,p))
E 3
				pkt->p_user = 1;
D 3
		*(strend(p)) = '\n';	/* repl \0 end of line w/ \n again */
E 3
I 3
			else if (gid = atoi(p))
				for (i = 0; i < ngroups; i++)
				    if (gid == groups[i]) {
					pkt->p_user = 1;
					break;
				    }
		}
		*(index(p,'\0')) = '\n';/* repl \0 end of line w/ \n again */
E 3
	}
	if (none)
		pkt->p_user = 1;
	if (p == NULL || p[1] != EUSERNAM)
		fmterr(pkt);
}


char	*Sflags[NFLAGS];

doflags(pkt)
struct packet *pkt;
{
	register char *p;
	register int k;

	for (k = 0; k < NFLAGS; k++)
		Sflags[k] = 0;
	while ((p = getline(pkt)) != NULL && *p++ == CTLCHAR && *p++ == FLAG) {
		NONBLANK(p);
		k = *p++ - 'a';
		NONBLANK(p);
		Sflags[k] = alloc(size(p));
		copy(p,Sflags[k]);
		for (p = Sflags[k]; *p++ != '\n'; )
			;
		*--p = 0;
	}
}


permiss(pkt)
register struct packet *pkt;
{
	extern char *Sflags[];
	register char *p;
	register int n;

	if (!pkt->p_user)
		fatal("not authorized to make deltas (co14)");
	if (p = Sflags[FLORFLAG - 'a']) {
D 4
		if (((unsigned)pkt->p_reqsid.s_rel) < (n = patoi(p)))
			fatal(sprintf(Error,"release %u < %u (floor) (co15)",
				pkt->p_reqsid.s_rel,n));
E 4
I 4
		if (((unsigned)pkt->p_reqsid.s_rel) < (n = patoi(p))) {
			sprintf(Error,"release %u < %u (floor) (co15)",pkt->p_reqsid.s_rel,n);
			fatal(Error);
		}
E 4
	}
	if (p = Sflags[CEILFLAG - 'a'])
D 4
		if (((unsigned)pkt->p_reqsid.s_rel) > (n = patoi(p)))
			fatal(sprintf(Error,"release %u > %u (ceiling) (co16)",
				pkt->p_reqsid.s_rel,n));
E 4
I 4
		if (((unsigned)pkt->p_reqsid.s_rel) > (n = patoi(p))) {
			sprintf(Error,"release %u > %u (ceiling) (co16)",pkt->p_reqsid.s_rel,n);
			fatal(Error);
		}
E 4
}
E 1
