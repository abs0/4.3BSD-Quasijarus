h04421
s 00022/00000/00323
d D 4.9 87/06/18 20:38:09 bostic 10 9
c fix VPATH macro expansion
e
s 00014/00003/00309
d D 4.8 85/09/18 15:22:56 serge 9 8
c print exit status in human readable form
e
s 00001/00001/00311
d D 4.7 85/08/30 09:31:40 bloom 8 7
c increase array sizes for pathnames (some people overflowed)
e
s 00010/00005/00302
d D 4.6 85/04/16 14:57:26 mckusick 7 6
c vpath additions from Greg Couch (gregc@ucsfcgl)
e
s 00006/00002/00301
d D 4.5 85/01/09 17:55:54 mckusick 6 5
c get the rindex right once and for all!
e
s 00002/00000/00301
d D 4.4 84/12/23 17:25:00 sam 5 3
c check for null dependencies; from brl
e
s 00000/00000/00301
d R 4.4 84/11/28 22:39:47 bloom 4 3
x 2
c Fix 4.3 was incorrect.  Code was correct beforehand.
e
s 00001/00001/00300
d D 4.3 83/03/11 22:22:50 mckusick 3 2
c use proper semantics of rindex
e
s 00001/00000/00300
d D 4.2 83/02/03 16:38:56 mckusick 2 1
c always set up $*
e
s 00300/00000/00000
d D 4.1 81/02/28 21:15:52 wnj 1 0
c date and time created 81/02/28 21:15:52 by wnj
e
u
U
t
T
I 1
static	char *sccsid = "%W% (Berkeley) %E%";
#include "defs"
I 6
#include <strings.h>
I 9
#include <signal.h>
E 9
E 6

/*  BASIC PROCEDURE.  RECURSIVE.  */

/*
p->done = 0   don't know what to do yet
p->done = 1   file in process of being updated
p->done = 2   file already exists in current state
p->done = 3   file make failed
*/

I 9
extern char *sys_siglist[];

E 9
doname(p, reclevel, tval)
register struct nameblock *p;
int reclevel;
TIMETYPE *tval;
{
int errstat;
int okdel1;
int didwork;
TIMETYPE td, td1, tdep, ptime, ptime1, prestime();
register struct depblock *q;
struct depblock *qtemp, *srchdir(), *suffp, *suffp1;
struct nameblock *p1, *p2;
struct shblock *implcom, *explcom;
register struct lineblock *lp;
struct lineblock *lp1, *lp2;
D 8
char sourcename[100], prefix[100], temp[100], concsuff[20];
E 8
I 8
char sourcename[BUFSIZ], prefix[BUFSIZ], temp[BUFSIZ], concsuff[20];
E 8
D 6
char *pnamep, *p1namep;
E 6
I 6
char *pnamep, *p1namep, *cp;
E 6
char *mkqlist();
struct chain *qchain, *appendq();

I 10
{
	/*
	 * VPATH= ${PATH1}:${PATH2} didn't work.  This fix is so ugly I don't
	 * even want to think about it.  Basically it grabs VPATH and
	 * explicitly does macro expansion before resolving names.  Why
	 * VPATH didn't get handled correctly I have no idea; the symptom
	 * was that, while macro expansion got done, the .c files in the
	 * non-local directories wouldn't be found.
	 */
	struct varblock	*vpath_cp, *varptr();
	static int	vpath_first;
	char	vpath_exp[INMAX];

	if (!vpath_first) {
		vpath_first = 1;
		vpath_cp = varptr("VPATH");
		if (vpath_cp->varval) {
			subst(vpath_cp->varval, vpath_exp);
			setvar("VPATH",vpath_exp);
		}
	}
}
E 10
if(p == 0)
	{
	*tval = 0;
	return(0);
	}

if(dbgflag)
	{
	printf("doname(%s,%d)\n",p->namep,reclevel);
	fflush(stdout);
	}

if(p->done > 0)
	{
	*tval = p->modtime;
	return(p->done == 3);
	}

errstat = 0;
tdep = 0;
implcom = 0;
explcom = 0;
D 7
ptime = exists(p->namep);
E 7
I 7
ptime = exists(p); 
E 7
ptime1 = 0;
didwork = NO;
p->done = 1;	/* avoid infinite loops */

qchain = NULL;

/* Expand any names that have embedded metacharaters */

for(lp = p->linep ; lp ; lp = lp->nxtlineblock)
	for(q = lp->depp ; q ; q=qtemp )
		{
		qtemp = q->nxtdepblock;
		expand(q);
		}

/* make sure all dependents are up to date */

for(lp = p->linep ; lp ; lp = lp->nxtlineblock)
	{
	td = 0;
	for(q = lp->depp ; q ; q = q->nxtdepblock)
		{
		errstat += doname(q->depname, reclevel+1, &td1);
		if(dbgflag)
		    printf("TIME(%s)=%ld\n", q->depname->namep, td1);
		if(td1 > td) td = td1;
		if(ptime < td1)
			qchain = appendq(qchain, q->depname->namep);
		}
	if(p->septype == SOMEDEPS)
		{
		if(lp->shp!=0)
		     if( ptime<td || (ptime==0 && td==0) || lp->depp==0)
			{
			okdel1 = okdel;
			okdel = NO;
			setvar("@", p->namep);
			setvar("?", mkqlist(qchain) );
			qchain = NULL;
			if( !questflag )
				errstat += docom(lp->shp);
			setvar("@", (char *) NULL);
			okdel = okdel1;
			ptime1 = prestime();
			didwork = YES;
			}
		}

	else	{
		if(lp->shp != 0)
			{
			if(explcom)
				fprintf(stderr, "Too many command lines for `%s'\n",
					p->namep);
			else	explcom = lp->shp;
			}

		if(td > tdep) tdep = td;
		}
	}

/* Look for implicit dependents, using suffix rules */

for(lp = sufflist ; lp ; lp = lp->nxtlineblock)
    for(suffp = lp->depp ; suffp ; suffp = suffp->nxtdepblock)
	{
	pnamep = suffp->depname->namep;
	if(suffix(p->namep , pnamep , prefix))
		{
I 7

E 7
		srchdir( concat(prefix,"*",temp) , NO, (struct depblock *) NULL);
		for(lp1 = sufflist ; lp1 ; lp1 = lp1->nxtlineblock)
		    for(suffp1=lp1->depp ; suffp1 ; suffp1 = suffp1->nxtdepblock)
			{
			p1namep = suffp1->depname->namep;
			if( (p1=srchname(concat(p1namep, pnamep ,concsuff))) &&
			    (p2=srchname(concat(prefix, p1namep ,sourcename))) )
				{
				errstat += doname(p2, reclevel+1, &td);
				if(ptime < td)
					qchain = appendq(qchain, p2->namep);
if(dbgflag) printf("TIME(%s)=%ld\n", p2->namep, td);
				if(td > tdep) tdep = td;
				setvar("*", prefix);
D 7
				setvar("<", copys(sourcename));
E 7
I 7
				if (p2->alias) setvar("<", copys(p2->alias));
				else setvar("<", copys(p2->namep));
E 7
				for(lp2=p1->linep ; lp2 ; lp2 = lp2->nxtlineblock)
					if(implcom = lp2->shp) break;
				goto endloop;
				}
			}
I 2
D 3
		setvar("*", &prefix[rindex(prefix, '/')]);
E 3
I 3
D 6
		setvar("*", rindex(prefix, '/') + 1);
E 6
I 6
		cp = rindex(prefix, '/');
		if (cp++ == 0)
			cp = prefix;
		setvar("*", cp);
E 6
E 3
E 2
		}
	}

endloop:


if(errstat==0 && (ptime<tdep || (ptime==0 && tdep==0) ) )
	{
	ptime = (tdep>0 ? tdep : prestime() );
	setvar("@", p->namep);
	setvar("?", mkqlist(qchain) );
	if(explcom)
		errstat += docom(explcom);
	else if(implcom)
		errstat += docom(implcom);
	else if(p->septype == 0)
		if(p1=srchname(".DEFAULT"))
			{
D 7
			setvar("<", p->namep);
E 7
I 7
			if (p->alias) setvar("<", p->alias);
			else setvar("<", p->namep);
E 7
			for(lp2 = p1->linep ; lp2 ; lp2 = lp2->nxtlineblock)
				if(implcom = lp2->shp)
					{
					errstat += docom(implcom);
					break;
					}
			}
		else if(keepgoing)
			{
			printf("Don't know how to make %s\n", p->namep);
			++errstat;
			}
		else
			fatal1(" Don't know how to make %s", p->namep);

	setvar("@", (char *) NULL);
D 7
	if(noexflag || (ptime = exists(p->namep)) == 0)
E 7
I 7
	if(noexflag || (ptime = exists(p)) == 0)
E 7
		ptime = prestime();
	}

else if(errstat!=0 && reclevel==0)
	printf("`%s' not remade because of errors\n", p->namep);

else if(!questflag && reclevel==0  &&  didwork==NO)
	printf("`%s' is up to date.\n", p->namep);

if(questflag && reclevel==0)
	exit(ndocoms>0 ? -1 : 0);

p->done = (errstat ? 3 : 2);
if(ptime1 > ptime) ptime = ptime1;
p->modtime = ptime;
*tval = ptime;
return(errstat);
}

docom(q)
struct shblock *q;
{
char *s;
struct varblock *varptr();
int ign, nopr;
char string[OUTMAX];
I 7
char string2[OUTMAX];
E 7

++ndocoms;
if(questflag)
	return(NO);

if(touchflag)
	{
	s = varptr("@")->varval;
	if(!silflag)
		printf("touch(%s)\n", s);
	if(!noexflag)
		touch(YES, s);
	}

else for( ; q ; q = q->nxtshblock )
	{
D 7
	subst(q->shbp,string);
E 7
I 7
	subst(q->shbp,string2);
	fixname(string2, string);
E 7

	ign = ignerr;
	nopr = NO;
	for(s = string ; *s=='-' || *s=='@' ; ++s)
		if(*s == '-')  ign = YES;
		else nopr = YES;

	if( docom1(s, ign, nopr) && !ign)
		if(keepgoing)
			return(YES);
		else	fatal( (char *) NULL);
	}
return(NO);
}



docom1(comstring, nohalt, noprint)
register char *comstring;
int nohalt, noprint;
{
register int status;

if(comstring[0] == '\0') return(0);

if(!silflag && (!noprint || noexflag) )
	{
	printf("%s%s\n", (noexflag ? "" : prompt), comstring);
	fflush(stdout);
	}

if(noexflag) return(0);

if( status = dosys(comstring, nohalt) )
	{
D 9
	if( status>>8 )
		printf("*** Error code %d", status>>8 );
	else	printf("*** Termination code %d", status );
E 9
I 9
	unsigned sig = status & 0177;
	if( sig ) {
		if (sig < NSIG && sys_siglist[sig] != NULL &&
		    *sys_siglist[sig] != '\0')
			printf("*** %s", sys_siglist[sig]);
		else
			printf("*** Signal %d", sig);
		if (status & 0200)
			printf(" - core dumped");
	} else
		printf("*** Exit %d", status>>8 );
E 9

	if(nohalt) printf(" (ignored)\n");
	else	printf("\n");
	fflush(stdout);
	}

return(status);
}


/*
   If there are any Shell meta characters in the name,
   expand into a list, after searching directory
*/

expand(q)
register struct depblock *q;
{
register char *s;
char *s1;
struct depblock *p, *srchdir();

I 5
if (q->depname == NULL)
	return;
E 5
s1 = q->depname->namep;
for(s=s1 ; ;) switch(*s++)
	{
	case '\0':
		return;

	case '*':
	case '?':
	case '[':
		if( p = srchdir(s1 , YES, q->nxtdepblock) )
			{
			q->nxtdepblock = p;
			q->depname = 0;
			}
		return;
	}
}
E 1
