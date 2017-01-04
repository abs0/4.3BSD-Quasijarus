h52796
s 00006/00003/00054
d D 1.5 88/12/22 12:59:01 sam 5 4
c purge uses of alloca
e
s 00002/00002/00055
d D 1.4 87/02/15 16:42:31 lepreau 4 3
c modern syntax for asgops & inits; sccs keywords
e
s 00004/00004/00053
d D 1.3 85/05/04 00:31:32 sam 3 2
c purge old crud
e
s 00002/00002/00055
d D 1.2 81/04/13 16:08:35 eric 2 1
c use defined constant for size of login name
e
s 00057/00000/00000
d D 1.1 81/04/13 16:06:51 eric 1 0
c date and time created 81/04/13 16:06:51 by eric
e
u
U
t
T
I 1
# include	"../hdr/defines.h"

D 2
SCCSID(@(#)pf_ab	2.1.1.1);
E 2
I 2
D 4
SCCSID(%W%	%G%);
E 4
I 4
static char Sccsid[] = "%W%	%G%";
E 4
E 2

pf_ab(s,pp,all)
char *s;
register struct pfile *pp;
int all;
{
	register char *p;
	register int i;
	extern char *Datep;
D 5
	char *xp;
E 5
I 5
	char *xp, *buf;
E 5

D 5
	xp = p = alloca(size(s));
E 5
I 5
	xp = p = buf = alloc(size(s));
E 5
	copy(s,p);
	for (; *p; p++)
		if (*p == '\n') {
			*p = 0;
			break;
		}
	p = xp;
	p = sid_ab(p,&pp->pf_gsid);
	++p;
	p = sid_ab(p,&pp->pf_nsid);
	++p;
D 3
	i = index(p," ");
E 3
I 3
	xp = index(p,' ');
E 3
	pp->pf_user[0] = 0;
D 2
	if (((unsigned)i) < 8) {
E 2
I 2
D 3
	if (((unsigned)i) < SZLNAM) {
E 2
		move(p,pp->pf_user,i);
E 3
I 3
	if ((unsigned)(i = xp-p) < SZLNAM) {
		bcopy(p,pp->pf_user,i);
E 3
		pp->pf_user[i] = 0;
	}
	else
		fatal("bad p-file format (co17)");
D 3
	p = p + i + 1;
E 3
I 3
	p = xp + 1;
E 3
	date_ab(p,&pp->pf_date);
	p = Datep;
	pp->pf_ilist = 0;
	pp->pf_elist = 0;
D 5
	if (!all || !*p)
E 5
I 5
	if (!all || !*p) {
		free(buf);
E 5
		return;
I 5
	}
E 5
D 4
	p =+ 2;
E 4
I 4
	p += 2;
E 4
	xp = alloc(size(p));
	copy(p,xp);
	p = xp;
	if (*p == 'i') {
		pp->pf_ilist = ++p;
		for (; *p; p++)
			if (*p == ' ') {
				*p++ = 0;
				p++;
				break;
			}
	}
	if (*p == 'x')
		pp->pf_elist = ++p;
I 5
	free(buf);
E 5
}
E 1
