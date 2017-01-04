h57062
s 00001/00000/00648
d D 4.17 87/12/21 12:26:21 bostic 17 16
c make ANSI C compatible
e
s 00001/00001/00647
d D 4.16 87/11/15 14:58:25 bostic 16 15
c use dirfd macro
e
s 00001/00001/00647
d D 4.15 87/05/05 08:54:17 bostic 15 14
c make VPATH feature uses *(char *)NUL (bug report 4.3BSD/bin/69)
e
s 00001/00001/00647
d D 4.14 86/10/13 16:49:51 sam 14 13
c tahoe assembler just like vax
e
s 00001/00001/00647
d D 4.13 86/07/24 16:52:55 bloom 13 12
c the a.out header is not vax or sun only, it is for 4BSD systems. 
c 2.9 uses that format of the header
e
s 00001/00001/00647
d D 4.12 86/01/09 01:33:44 donn 12 11
c There was a test for a leading '.' in VPATH to avoid searching the current
c directory twice; the test should have been for a leading '.:' so that users
c who set 'VPATH=../src' would still find files in the current directory.
e
s 00004/00004/00644
d D 4.11 85/08/30 09:31:49 bloom 11 10
c increase array sizes for pathnames (some people overflowed)
e
s 00118/00008/00530
d D 4.10 85/04/16 14:57:33 mckusick 10 9
c vpath additions from Greg Couch (gregc@ucsfcgl)
e
s 00003/00000/00535
d D 4.9 84/03/21 11:14:05 ralph 9 8
c close files on vfork properly.
e
s 00001/00001/00534
d D 4.8 83/06/30 08:28:57 nicklin 8 7
c Swapped .f and .F suffix precedence
e
s 00003/00003/00532
d D 4.7 83/05/18 16:02:04 nicklin 7 6
c Added .F.o rule for Fortran + C preprocessor
e
s 00002/00006/00533
d D 4.6 83/02/09 14:20:00 sam 6 5
c from sun
e
s 00001/00005/00538
d D 4.5 82/06/17 00:08:31 root 5 4
c remove lstats
e
s 00032/00037/00511
d D 4.4 82/04/20 18:56:12 mckusick 4 3
c add new directory access routines
e
s 00008/00000/00540
d D 4.3 82/03/14 13:27:08 sam 3 2
c state->lstat for symbolic links
e
s 00001/00001/00539
d D 4.2 81/02/28 21:17:56 wnj 2 1
c typo EC->FC
e
s 00540/00000/00000
d D 4.1 81/02/28 21:15:55 wnj 1 0
c date and time created 81/02/28 21:15:55 by wnj
e
u
U
t
T
I 1
static	char *sccsid = "%W% (Berkeley) %E%";
I 9
#include <fcntl.h>

E 9
/* UNIX DEPENDENT PROCEDURES */


/* DEFAULT RULES FOR UNIX */

char *builtin[] =
	{
#ifdef pwb
	".SUFFIXES : .L .out .o .c .f .e .r .y .yr .ye .l .s .z .x .t .h .cl",
#else
D 7
	".SUFFIXES : .out .o .c .f .e .r .y .yr .ye .l .s .cl .p",
E 7
I 7
D 8
	".SUFFIXES : .out .o .c .f .F .e .r .y .yr .ye .l .s .cl .p",
E 8
I 8
	".SUFFIXES : .out .o .c .F .f .e .r .y .yr .ye .l .s .cl .p",
E 8
E 7
#endif
	"YACC=yacc",
	"YACCR=yacc -r",
	"YACCE=yacc -e",
	"YFLAGS=",
	"LEX=lex",
	"LFLAGS=",
	"CC=cc",
D 6
#ifdef vax
E 6
I 6
D 14
#if defined(vax) || defined(sun)
E 14
I 14
#if defined(vax) || defined(sun) || defined(tahoe)
E 14
E 6
	"AS=as",
#else
	"AS=as -",
#endif
	"PC=pc",
	"PFLAGS=",
	"CFLAGS=",
	"RC=f77",
	"RFLAGS=",
D 2
	"EC=f77",
E 2
I 2
	"FC=f77",
E 2
	"EFLAGS=",
	"FFLAGS=",
	"LOADLIBES=",
#ifdef pwb
	"SCOMP=scomp",
	"SCFLAGS=",
	"CMDICT=cmdict",
	"CMFLAGS=",
#endif

	".c.o :",
	"\t$(CC) $(CFLAGS) -c $<",

	".p.o :",
	"\t$(PC) $(PFLAGS) -c $<",

	".cl.o :",
	"\tclass -c $<",

D 7
	".e.o .r.o .f.o :",
E 7
I 7
	".e.o .r.o .F.o .f.o :",
E 7
	"\t$(FC) $(RFLAGS) $(EFLAGS) $(FFLAGS) -c $<",

	".s.o :",
	"\t$(AS) -o $@ $<",

	".y.o :",
	"\t$(YACC) $(YFLAGS) $<",
	"\t$(CC) $(CFLAGS) -c y.tab.c",
	"\trm y.tab.c",
	"\tmv y.tab.o $@",

	".yr.o:",
	"\t$(YACCR) $(YFLAGS) $<",
	"\t$(RC) $(RFLAGS) -c y.tab.r",
	"\trm y.tab.r",
	"\tmv y.tab.o $@",

	".ye.o :",
	"\t$(YACCE) $(YFLAGS) $<",
	"\t$(EC) $(RFLAGS) -c y.tab.e",
	"\trm y.tab.e",
	"\tmv y.tab.o $@",

	".l.o :",
	"\t$(LEX) $(LFLAGS) $<",
	"\t$(CC) $(CFLAGS) -c lex.yy.c",
	"\trm lex.yy.c",
	"\tmv lex.yy.o $@",

	".y.c :",
	"\t$(YACC) $(YFLAGS) $<",
	"\tmv y.tab.c $@",

	".l.c :",
	"\t$(LEX) $(LFLAGS) $<",
	"\tmv lex.yy.c $@",

	".yr.r:",
	"\t$(YACCR) $(YFLAGS) $<",
	"\tmv y.tab.r $@",

	".ye.e :",
	"\t$(YACCE) $(YFLAGS) $<",
	"\tmv y.tab.e $@",

#ifdef pwb
	".o.L .c.L .t.L:",
	"\t$(SCOMP) $(SCFLAGS) $<",

	".t.o:",
	"\t$(SCOMP) $(SCFLAGS) -c $<",

	".t.c:",
	"\t$(SCOMP) $(SCFLAGS) -t $<",

	".h.z .t.z:",
	"\t$(CMDICT) $(CMFLAGS) $<",

	".h.x .t.x:",
	"\t$(CMDICT) $(CMFLAGS) -c $<",
#endif

	".s.out .c.out .o.out :",
	"\t$(CC) $(CFLAGS) $< $(LOADLIBES) -o $@",

D 7
	".f.out .r.out .e.out :",
E 7
I 7
	".f.out .F.out .r.out .e.out :",
E 7
	"\t$(FC) $(EFLAGS) $(RFLAGS) $(FFLAGS) $< $(LOADLIBES) -o $@",
	"\t-rm $*.o",

	".y.out :",
	"\t$(YACC) $(YFLAGS) $<",
	"\t$(CC) $(CFLAGS) y.tab.c $(LOADLIBES) -ly -o $@",
	"\trm y.tab.c",

	".l.out :",
	"\t$(LEX) $(LFLAGS) $<",
	"\t$(CC) $(CFLAGS) lex.yy.c $(LOADLIBES) -ll -o $@",
	"\trm lex.yy.c",

	0 };

#include "defs"
I 10
#include <sys/stat.h>
E 10
D 4
#include <sys/types.h>
E 4


D 10
TIMETYPE exists(filename)
char *filename;
E 10
I 10

TIMETYPE 
exists(pname)
struct nameblock *pname;
E 10
{
D 10
#include <sys/stat.h>
E 10
struct stat buf;
D 10
register char *s;
E 10
I 10
register char *s, *filename;
E 10
TIMETYPE lookarch();
I 10
extern char *findfl();
E 10

I 10
filename = pname->namep;

E 10
for(s = filename ; *s!='\0' && *s!='(' ; ++s)
	;

if(*s == '(')
	return(lookarch(filename));

I 3
D 6
#if vax
E 6
D 5
if (lstat(filename, &buf) < 0)
E 5
I 5
if (stat(filename, &buf) < 0)
I 10
{
	s = findfl(filename);
	if(s != (char *)-1)
	{
		pname->alias = copys(s);
		if(stat(pname->alias, &buf) == 0)
			return(buf.st_mtime);
	}
E 10
E 5
D 6
#else
E 3
if(stat(filename,&buf) < 0) 
I 3
#endif
E 6
E 3
	return(0);
I 10
}
E 10
else	return(buf.st_mtime);
}


TIMETYPE prestime()
{
TIMETYPE t;
time(&t);
return(t);
}



D 4
#include <sys/dir.h>
FSTATIC char n15[15];
FSTATIC char *n15end	= &n15[14];
E 4
I 4
FSTATIC char nbuf[MAXNAMLEN + 1];
FSTATIC char *nbufend	= &nbuf[MAXNAMLEN];
E 4



struct depblock *srchdir(pat, mkchain, nextdbl)
register char *pat; /* pattern to be matched in directory */
int mkchain;  /* nonzero if results to be remembered */
struct depblock *nextdbl;  /* final value for chain */
{
D 4
FILE * dirf;
E 4
I 4
DIR *dirf;
E 4
register int i;
int nread, cldir;
D 11
char *dirname, *dirpref, *endir, *filepat, *p, temp[100];
char fullname[100], *p1, *p2;
E 11
I 11
char *dirname, *dirpref, *endir, *filepat, *p, temp[BUFSIZ];
char fullname[BUFSIZ], *p1, *p2;
E 11
struct nameblock *q;
struct depblock *thisdbl;
D 4
struct opendir *od;
E 4
I 4
struct dirhdr *od;
E 4
struct pattern *patp;
D 10

E 10
I 10
struct varblock *cp, *varptr();
D 11
char *path, pth[100], *strcpy();
E 11
I 11
char *path, pth[BUFSIZ], *strcpy();
E 11
E 10
D 4
struct direct entry[32];
E 4
I 4
struct direct *dptr;
E 4


thisdbl = 0;

if(mkchain == NO)
	for(patp=firstpat ; patp ; patp = patp->nxtpattern)
		if(! unequal(pat, patp->patval)) return(0);

patp = ALLOC(pattern);
patp->nxtpattern = firstpat;
firstpat = patp;
patp->patval = copys(pat);

endir = 0;

for(p=pat; *p!='\0'; ++p)
	if(*p=='/') endir = p;

if(endir==0)
	{
D 10
	dirname = ".";
E 10
	dirpref = "";
	filepat = pat;
I 10
	cp = varptr("VPATH");
D 15
	if (*cp->varval == 0) path = ".";
E 15
I 15
	if (cp->varval == NULL) path = ".";
E 15
	else {
	       path = pth; 
	       *path = '\0';
D 12
	       if (*cp->varval != '.') strcpy(pth,".:");
E 12
I 12
	       if (strncmp(cp->varval, ".:", 2) != 0) strcpy(pth,".:");
E 12
	       strcat(pth, cp->varval);
	       }
E 10
	}
else	{
D 10
	dirname = pat;
E 10
	*endir = '\0';
D 10
	dirpref = concat(dirname, "/", temp);
E 10
I 10
	path = strcpy(pth, pat);
	dirpref = concat(pat, "/", temp);
E 10
	filepat = endir+1;
	}

I 10
while (*path) {			/* Loop thru each VPATH directory */
  dirname = path;
  for (; *path; path++)
    if (*path == ':') {
      *path++ = '\0';
      break;
      }

E 10
dirf = NULL;
cldir = NO;

for(od = firstod; od; od = od->nxtopendir)
	if(! unequal(dirname, od->dirn) )
		{
		dirf = od->dirfc;
D 4
		fseek(dirf, 0L, 0); /* start over at the beginning  */
E 4
I 4
		if (dirf != NULL)
			rewinddir(dirf); /* start over at the beginning  */
E 4
		break;
		}

if(dirf == NULL)
	{
D 4
	dirf = fopen(dirname, "r");
E 4
I 4
	dirf = opendir(dirname);
E 4
	if(nopdir >= MAXDIR)
		cldir = YES;
	else	{
		++nopdir;
D 4
		od = ALLOC(opendir);
E 4
I 4
		od = ALLOC(dirhdr);
E 4
		od->nxtopendir = firstod;
		firstod = od;
		od->dirfc = dirf;
		od->dirn = copys(dirname);
I 9
D 16
		fcntl(dirf->dd_fd, F_SETFD, 1);
E 16
I 16
		fcntl(dirfd(dirf), F_SETFD, 1);
E 16
E 9
		}
	}

if(dirf == NULL)
	{
	fprintf(stderr, "Directory %s: ", dirname);
	fatal("Cannot open");
	}

D 4
else do
E 4
I 4
else for (dptr = readdir(dirf); dptr != NULL; dptr = readdir(dirf))
E 4
	{
D 4
	nread = fread( (char *) &entry[0], sizeof(struct direct), 32, dirf) ;
	for(i=0; i<nread; ++i)
		if(entry[i].d_ino!= 0)
E 4
I 4
	p1 = dptr->d_name;
	p2 = nbuf;
	while( (p2<nbufend) && (*p2++ = *p1++)!='\0' )
		/* void */;
	if( amatch(nbuf,filepat) )
		{
		concat(dirpref,nbuf,fullname);
		if( (q=srchname(fullname)) ==0)
			q = makename(copys(fullname));
		if(mkchain)
E 4
			{
D 4
			p1 = entry[i].d_name;
			p2 = n15;
			while( (p2<n15end) &&
			  (*p2++ = *p1++)!='\0' );
			if( amatch(n15,filepat) )
				{
				concat(dirpref,n15,fullname);
				if( (q=srchname(fullname)) ==0)
					q = makename(copys(fullname));
				if(mkchain)
					{
					thisdbl = ALLOC(depblock);
					thisdbl->nxtdepblock = nextdbl;
					thisdbl->depname = q;
					nextdbl = thisdbl;
					}
				}
E 4
I 4
			thisdbl = ALLOC(depblock);
			thisdbl->nxtdepblock = nextdbl;
			thisdbl->depname = q;
			nextdbl = thisdbl;
E 4
			}
I 4
		}
	}
E 4

D 4
	} while(nread==32);

E 4
if(endir != 0)  *endir = '/';

D 4
if(cldir)
	fclose(dirf);
E 4
I 4
if(cldir) {
	closedir(dirf);
	dirf = NULL;
}
I 10
} /* End of VPATH loop */
E 10
E 4
return(thisdbl);
}

/* stolen from glob through find */

static amatch(s, p)
char *s, *p;
{
	register int cc, scc, k;
	int c, lc;

	scc = *s;
	lc = 077777;
	switch (c = *p) {

	case '[':
		k = 0;
		while (cc = *++p) {
			switch (cc) {

			case ']':
				if (k)
					return(amatch(++s, ++p));
				else
					return(0);

			case '-':
				k |= (lc <= scc)  & (scc <= (cc=p[1]) ) ;
			}
			if (scc==(lc=cc)) k++;
		}
		return(0);

	case '?':
	caseq:
		if(scc) return(amatch(++s, ++p));
		return(0);
	case '*':
		return(umatch(s, ++p));
	case 0:
		return(!scc);
	}
	if (c==scc) goto caseq;
	return(0);
}

static umatch(s, p)
char *s, *p;
{
	if(*p==0) return(1);
	while(*s)
		if (amatch(s++,p)) return(1);
	return(0);
}

#ifdef METERFILE
#include <pwd.h>
int meteron	= 0;	/* default: metering off */

meter(file)
char *file;
{
TIMETYPE tvec;
char *p, *ctime();
FILE * mout;
struct passwd *pwd, *getpwuid();

if(file==0 || meteron==0) return;

pwd = getpwuid(getuid());

time(&tvec);

if( (mout=fopen(file,"a")) != NULL )
	{
	p = ctime(&tvec);
	p[16] = '\0';
	fprintf(mout,"User %s, %s\n",pwd->pw_name,p+4);
	fclose(mout);
	}
}
#endif


/* look inside archives for notations a(b) and a((b))
	a(b)	is file member   b   in archive a
	a((b))	is entry point  _b  in object archive a
*/

#ifdef ASCARCH
#	include <ar.h>
#else
#	include <ar.h>
#endif
#include <a.out.h>

static long arflen;
static long arfdate;
static char arfname[16];
FILE *arfd;
long int arpos, arlen;

static struct exec objhead;

static struct nlist objentry;


TIMETYPE lookarch(filename)
char *filename;
{
D 4
char *p, *q, *send, s[15];
E 4
I 4
char *p, *q, *send, s[MAXNAMLEN + 1];
E 4
int i, nc, nsym, objarch;

for(p = filename; *p!= '(' ; ++p)
	;
*p = '\0';
openarch(filename);
*p++ = '(';

if(*p == '(')
	{
	objarch = YES;
	nc = 8;
	++p;
	}
else
	{
	objarch = NO;
D 4
	nc = 14;
E 4
I 4
	nc = MAXNAMLEN;
E 4
	}
send = s + nc;

for( q = s ; q<send && *p!='\0' && *p!=')' ; *q++ = *p++ )
	;
while(q < send)
	*q++ = '\0';
while(getarch())
	{
	if(objarch)
		{
		getobj();
		nsym = objhead.a_syms / sizeof(objentry);
		for(i = 0; i<nsym ; ++i)
			{
			fread( (char *) &objentry, sizeof(objentry),1,arfd);
			if( (objentry.n_type & N_EXT)
			   && ((objentry.n_type & ~N_EXT) || objentry.n_value)
			   && eqstr(objentry.n_un.n_name,s,nc))
				{
				clarch();
				return(arfdate);
				}
			}
		}

	else if( eqstr(arfname, s, nc))
		{
		clarch();
		return(arfdate);
		}
	}

clarch();
return( 0L);
}


clarch()
{
fclose( arfd );
}


openarch(f)
register char *f;
{
#ifdef ASCARCH
char magic[SARMAG];
#endif
int word;
#include <sys/stat.h>
struct stat buf;

I 3
D 5
#if vax
lstat(f, &buf);
#else
E 5
E 3
stat(f, &buf);
I 3
D 5
#endif
E 5
E 3
arlen = buf.st_size;

arfd = fopen(f, "r");
if(arfd == NULL)
	fatal1("cannot open %s", f);

	fread( (char *) &word, sizeof(word), 1, arfd);
#ifdef ASCARCH
	fseek(arfd, 0L, 0);
	fread(magic, SARMAG, 1, arfd);
	arpos = SARMAG;
	if( ! eqstr(magic, ARMAG, SARMAG) )
#else
	arpos = sizeof(word);
	if(word != ARMAG)
#endif
		fatal1("%s is not an archive", f);

arflen = 0;
}



getarch()
{
	struct ar_hdr arhead;
	long atol();

arpos += (arflen + 1) & ~1L;	/* round archived file length up to even */
if(arpos >= arlen)
	return(0);
fseek(arfd, arpos, 0);

	fread( (char *) &arhead, sizeof(arhead), 1, arfd);
	arpos += sizeof(arhead);
#ifdef ASCARCH
	arflen = atol(arhead.ar_size);
	arfdate = atol(arhead.ar_date);
#else
	arflen = arhead.ar_size;
	arfdate = arhead.ar_date;
#endif
	strncpy(arfname, arhead.ar_name, sizeof(arhead.ar_name));
return(1);
}


getobj()
{
long int skip;

fread( (char *) &objhead, sizeof(objhead), 1, arfd);
if (N_BADMAG(objhead))
	fatal1("%s is not an object module", arfname);
skip = objhead.a_text + objhead.a_data;
D 6
#ifdef vax
E 6
I 6
D 13
#if defined(vax) || defined(sun)
E 13
I 13
#ifndef pdp11
E 13
E 6
skip += objhead.a_trsize + objhead.a_drsize;
#else
if(! objhead.a_flag )
	skip *= 2;
#endif
fseek(arfd, skip, 1);
}


eqstr(a,b,n)
register char *a, *b;
int n;
{
register int i;
for(i = 0 ; i < n ; ++i)
	if(*a++ != *b++)
		return(NO);
return(YES);
I 10
}


/*
 *	findfl(name)	(like execvp, but does path search and finds files)
 */
static char fname[128];

char *execat();

char *findfl(name)
register char *name;
{
	register char *p;
	register struct varblock *cp;
	struct stat buf;
I 17
	struct varblock *varptr();
E 17

	for (p = name; *p; p++) 
		if(*p == '/') return(name);

	cp = varptr("VPATH");
	if(cp->varval == NULL || *cp->varval == 0)
		p = ":";
	else
		p = cp->varval;

	do
	{
		p = execat(p, name, fname);
		if(stat(fname,&buf) >= 0)
			return(fname);
	} while (p);
	return((char *)-1);
}

char *execat(s1, s2, si)
register char *s1, *s2;
char *si;
{
	register char *s;

	s = si;
	while (*s1 && *s1 != ':' && *s1 != '-')
		*s++ = *s1++;
	if (si != s)
		*s++ = '/';
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return(*s1? ++s1: 0);
}


/* copy s to d, changing file names to file aliases */
fixname(s, d)
char *s, *d;
{
	register char *r, *q;
	struct nameblock *pn;
D 11
	char name[100];
E 11
I 11
	char name[BUFSIZ];
E 11

	while (*s) {
		if (isspace(*s)) *d++ = *s++;
		else {
			r = name;
			while (*s) {
				if (isspace(*s)) break; 
				*r++ = *s++;
				}
			*r = '\0';
 		
			if (((pn = srchname(name)) != 0) && (pn->alias))
				q = pn->alias;
			else q = name;
	
			while (*q) *d++ = *q++;
			}
		}
	*d = '\0';
E 10
}
E 1
