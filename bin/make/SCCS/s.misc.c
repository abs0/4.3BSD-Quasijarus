h65107
s 00002/00002/00340
d D 4.5 87/10/22 10:04:07 bostic 5 4
c ANSI C; sprintf now returns an int.
e
s 00003/00001/00339
d D 4.4 87/05/21 17:20:45 bostic 4 3
c get machine type from environment
e
s 00001/00001/00339
d D 4.3 85/08/30 09:32:09 bloom 3 2
c increase array sizes for pathnames (some people overflowed)
e
s 00001/00001/00339
d D 4.2 82/10/19 15:09:56 sam 2 1
c be more generous with buffer allocation
e
s 00340/00000/00000
d D 4.1 81/02/28 21:16:02 wnj 1 0
c date and time created 81/02/28 21:16:02 by wnj
e
u
U
t
T
I 1
static	char *sccsid = "%W% (Berkeley) %E%";
#include "defs"

FSTATIC struct nameblock *hashtab[HASHSIZE];
FSTATIC int nhashed	= 0;


/* simple linear hash.  hash function is sum of
   characters mod hash table size.
*/
hashloc(s)
char *s;
{
register int i;
register int hashval;
register char *t;

hashval = 0;

for(t=s; *t!='\0' ; ++t)
	hashval += *t;

hashval %= HASHSIZE;

for(i=hashval;
	hashtab[i]!=0 && unequal(s,hashtab[i]->namep);
	i = (i+1)%HASHSIZE ) ;

return(i);
}


struct nameblock *srchname(s)
char *s;
{
return( hashtab[hashloc(s)] );
}



struct nameblock *makename(s)
char *s;
{
/* make a fresh copy of the string s */

char *copys();
register struct nameblock *p;

if(nhashed++ > HASHSIZE-3)
	fatal("Hash table overflow");

p = ALLOC(nameblock);
p->nxtnameblock = firstname;
p->namep = copys(s);
p->linep = 0;
p->done = 0;
p->septype = 0;
p->modtime = 0;

firstname = p;
if(mainname == NULL)
	if(s[0]!='.' || hasslash(s) )
		mainname = p;

hashtab[hashloc(s)] = p;

return(p);
}



hasslash(s)
char *s;
{
for( ; *s ; ++s)
	if(*s == '/')
		return(YES);
return(NO);
}



char *copys(s)
register char *s;
{
char *calloc();
register char *t, *t0;

if( (t = t0 = calloc( strlen(s)+1 , sizeof(char)) ) == NULL)
	fatal("out of memory");
while(*t++ = *s++)
	;
return(t0);
}



char *concat(a,b,c)   /* c = concatenation of a and b */
register char *a,*b;
char *c;
{
register char *t;
t = c;

while(*t = *a++) t++;
while(*t++ = *b++);
return(c);
}



suffix(a,b,p)  /* is b the suffix of a?  if so, set p = prefix */
register char *a,*b,*p;
{
char *a0,*b0;
a0 = a;
b0 = b;

while(*a++);
while(*b++);

if( (a-a0) < (b-b0) ) return(0);

while(b>b0)
	if(*--a != *--b) return(0);

while(a0<a) *p++ = *a0++;
*p = '\0';

return(1);
}






int *ckalloc(n)
register int n;
{
register int *p;

if( p = (int *) calloc(1,n) )
	return(p);

fatal("out of memory");
/* NOTREACHED */
}

/* copy string a into b, substituting for arguments */
char *subst(a,b)
register char *a,*b;
{
static depth	= 0;
register char *s;
D 3
char vname[100];
E 3
I 3
char vname[BUFSIZ];
E 3
struct varblock *varptr(), *vbp;
char closer;

if(++depth > 100)
	fatal("infinitely recursive macro?");
if(a!=0)  while(*a)
	{
	if(*a != '$') *b++ = *a++;
	else if(*++a=='\0' || *a=='$')
		*b++ = *a++;
	else	{
		s = vname;
		if( *a=='(' || *a=='{' )
			{
			closer = ( *a=='(' ? ')' : '}');
			++a;
			while(*a == ' ') ++a;
			while(*a!=' ' && *a!=closer && *a!='\0') *s++ = *a++;
			while(*a!=closer && *a!='\0') ++a;
			if(*a == closer) ++a;
			}
		else	*s++ = *a++;

		*s = '\0';
		if( (vbp = varptr(vname)) ->varval != 0)
			{
			b = subst(vbp->varval, b);
			vbp->used = YES;
			}
		}
	}

*b = '\0';
--depth;
return(b);
}


setvar(v,s)
char *v, *s;
{
struct varblock *varptr(), *p;

p = varptr(v);
if(p->noreset == 0)
	{
	p->varval = s;
	p->noreset = inarglist;
	if(p->used && unequal(v,"@") && unequal(v,"*")
	    && unequal(v,"<") && unequal(v,"?") )
		fprintf(stderr, "Warning: %s changed after being used\n",v);
	}
}


eqsign(a)   /*look for arguments with equal signs but not colons */
char *a;
{
D 4
register char *s, *t;
E 4
I 4
register char *s, *t, c;
E 4

while(*a == ' ') ++a;
for(s=a  ;   *s!='\0' && *s!=':'  ; ++s)
	if(*s == '=')
		{
		for(t = a ; *t!='=' && *t!=' ' && *t!='\t' ;  ++t );
I 4
		c = *t;
E 4
		*t = '\0';

		for(++s; *s==' ' || *s=='\t' ; ++s);
		setvar(a, copys(s));
I 4
		*t = c;
E 4
		return(YES);
		}

return(NO);
}


struct varblock *varptr(v)
char *v;
{
register struct varblock *vp;

for(vp = firstvar; vp ; vp = vp->nxtvarblock)
	if(! unequal(v , vp->varname))
		return(vp);

vp = ALLOC(varblock);
vp->nxtvarblock = firstvar;
firstvar = vp;
vp->varname = copys(v);
vp->varval = 0;
return(vp);
}


fatal1(s, t)
char *s, *t;
{
D 2
char buf[100];
E 2
I 2
char buf[BUFSIZ];
E 2
D 5
sprintf(buf, s, t);
E 5
I 5
(void)sprintf(buf, s, t);
E 5
fatal(buf);
}



fatal(s)
char *s;
{
if(s) fprintf(stderr, "Make: %s.  Stop.\n", s);
else fprintf(stderr, "\nStop.\n");
#ifdef unix
exit(1);
#endif
#ifdef gcos
exit(0);
#endif
}



yyerror(s)
char *s;
{
char buf[50];
extern int yylineno;

D 5
sprintf(buf, "line %d: %s", yylineno, s);
E 5
I 5
(void)sprintf(buf, "line %d: %s", yylineno, s);
E 5
fatal(buf);
}



struct chain *appendq(head, tail)
struct chain *head;
char *tail;
{
register struct chain *p, *q;

p = ALLOC(chain);
p->datap = tail;

if(head)
	{
	for(q = head ; q->nextp ; q = q->nextp)
		;
	q->nextp = p;
	return(head);
	}
else
	return(p);
}





char *mkqlist(p)
struct chain *p;
{
register char *qbufp, *s;
static char qbuf[QBUFMAX];

if(p == NULL)
	{
	qbuf[0] = '\0';
	return;
	}

qbufp = qbuf;

for( ; p ; p = p->nextp)
	{
	s = p->datap;
	if(qbufp+strlen(s) > &qbuf[QBUFMAX-3])
		{
		fprintf(stderr, "$? list too long\n");
		break;
		}
	while (*s)
		*qbufp++ = *s++;
	*qbufp++ = ' ';
	}
*--qbufp = '\0';
return(qbuf);
}
E 1
