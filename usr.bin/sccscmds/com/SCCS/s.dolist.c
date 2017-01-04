h42250
s 00003/00003/00077
d D 4.3 87/02/15 16:42:26 lepreau 4 3
c modern syntax for asgops & inits; sccs keywords
e
s 00003/00001/00077
d D 4.2 81/01/15 13:32:45 eric 3 1
c fix botch in include/exclude lists
e
s 00005/00002/00076
d R 4.2 81/01/15 13:26:21 eric 2 1
c fixed botches in ranges during include/exclude
e
s 00078/00000/00000
d D 4.1 81/01/15 13:15:11 eric 1 0
c date and time created 81/01/15 13:15:11 by eric
e
u
U
f b 
f i 
t
T
I 1
# include	"../hdr/defines.h"

D 4
SCCSID(%W%);
E 4
I 4
static char Sccsid[] = "%W%	%G%";
E 4

D 4
static char br[] "bad range (co12)";
E 4
I 4
static char br[] = "bad range (co12)";
E 4

dolist(pkt,list,ch)
struct packet *pkt;
register char *list;
char ch;
{
	char str[32];
	struct sid lowsid, highsid, sid;
	int n;

	while (*list) {
		list = getasid(list,&lowsid);
		if (*list == '-') {
			++list;
			list = getasid(list,&highsid);
			if (lowsid.s_br == 0) {
				if ((highsid.s_br || highsid.s_seq ||
					highsid.s_rel < lowsid.s_rel ||
					(highsid.s_rel == lowsid.s_rel &&
					highsid.s_lev < lowsid.s_lev)))
						fatal(br);
				sid.s_br = sid.s_seq = 0;
				for (sid.s_rel = lowsid.s_rel; sid.s_rel <= highsid.s_rel; sid.s_rel++) {
					sid.s_lev = (sid.s_rel == lowsid.s_rel ? lowsid.s_lev : 1);
D 3
					for ( ; n = sidtoser(&sid,pkt); sid.s_lev++)
E 3
I 3
					for ( ; (sid.s_rel < highsid.s_rel ||
						 sid.s_lev <= highsid.s_lev) &&
						(n = sidtoser(&sid,pkt)); sid.s_lev++)
E 3
						enter(pkt,ch,n,&sid);
				}
			}
			else {
				if (!(highsid.s_rel == lowsid.s_rel &&
					highsid.s_lev == lowsid.s_lev &&
					highsid.s_br == lowsid.s_br &&
					highsid.s_seq >= lowsid.s_seq))
						fatal(br);
				for (; lowsid.s_seq <= highsid.s_seq &&
					(n = sidtoser(&lowsid,pkt)); lowsid.s_seq++)
						enter(pkt,ch,n,&lowsid);
			}
		}
		else {
			if (n = sidtoser(&lowsid,pkt))
				enter(pkt,ch,n,&lowsid);
		}
		if (*list == ',')
			++list;
	}
}


D 4
static char dls[] "delta list syntax (co13)";
E 4
I 4
static char dls[] = "delta list syntax (co13)";
E 4

getasid(p,sp)
register char *p;
register struct sid *sp;
{
	register char *old;

	p = sid_ab(old = p,sp);
	if (old == p || sp->s_rel == 0)
		fatal(dls);
	if (sp->s_lev == 0) {
		sp->s_lev = MAX;
		if (sp->s_br || sp->s_seq)
			fatal(dls);
	}
	else if (sp->s_br) {
		if (sp->s_seq == 0)
			sp->s_seq = MAX;
	}
	else if (sp->s_seq)
		fatal(dls);
	return(p);
}
E 1
