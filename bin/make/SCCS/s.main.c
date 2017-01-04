h00774
s 00001/00001/00411
d D 4.10 87/11/15 14:58:27 bostic 10 9
c use dirfd macro
e
s 00031/00000/00381
d D 4.9 87/05/21 17:21:10 bostic 9 8
c get machine type from environment
e
s 00001/00001/00380
d D 4.8 86/01/09 01:37:46 donn 8 7
c Don't close stdin after reading the makefile when doing 'make -f -'.
c Some programs don't work right if stdin isn't there.
e
s 00001/00001/00380
d D 4.7 85/08/30 09:32:05 bloom 7 6
c increase array sizes for pathnames (some people overflowed)
e
s 00001/00003/00380
d D 4.6 84/11/26 10:53:12 ralph 6 5
c fix #ifdef unix so it will compile w/o unix defined.
e
s 00005/00002/00378
d D 4.5 83/03/03 15:26:04 sam 5 4
c disallow unlink of directory which will succeed if use is root
e
s 00002/00000/00378
d D 4.4 82/10/11 13:33:25 sam 4 3
c oops -- forgot empty string
e
s 00054/00047/00324
d D 4.3 82/10/10 20:59:25 sam 3 2
c add MFLAGS -- options from command line
e
s 00003/00003/00368
d D 4.2 82/04/20 18:56:21 mckusick 2 1
c add new directory access routines
e
s 00371/00000/00000
d D 4.1 81/02/28 21:16:01 wnj 1 0
c date and time created 81/02/28 21:16:01 by wnj
e
u
U
t
T
I 1
static	char *sccsid = "%W% (Berkeley) %E%";
# include "defs"
/*
command make to update programs.
Flags:	'd'  print out debugging comments
	'p'  print out a version of the input graph
	's'  silent mode--don't print out commands
	'f'  the next argument is the name of the description file;
	     "makefile" is the default
	'i'  ignore error codes from the shell
	'S'  stop after any command fails (normally do parallel work)
	'n'   don't issue, just print, commands
	't'   touch (update time of) files but don't issue command
	'q'   don't do anything, but check if object is up to date;
	      returns exit code 0 if up to date, -1 if not
I 9
	'e'  environment variables have precedence over makefiles
E 9
*/

struct nameblock *mainname	= NULL;
struct nameblock *firstname	= NULL;
struct lineblock *sufflist	= NULL;
struct varblock *firstvar	= NULL;
struct pattern *firstpat	= NULL;
D 2
struct opendir *firstod		= NULL;
E 2
I 2
struct dirhdr *firstod		= NULL;
E 2

#include <signal.h>
int sigivalue	= 0;
int sigqvalue	= 0;
int waitpid	= 0;

int dbgflag	= NO;
int prtrflag	= NO;
int silflag	= NO;
int noexflag	= NO;
int keepgoing	= NO;
int noruleflag	= NO;
int touchflag	= NO;
int questflag	= NO;
int ndocoms	= NO;
int ignerr	= NO;    /* default is to stop on error */
int okdel	= YES;
I 9
int doenvlast	= NO;
E 9
int inarglist;
#ifdef pwb
char *prompt	= ">";	/* other systems -- pick what you want */
#else
char *prompt	= "";	/* other systems -- pick what you want */
#endif
int nopdir	= 0;
char junkname[20];
char funny[128];
I 3
char	options[26 + 1] = { '-' };
E 3

main(argc,argv)
int argc;
char *argv[];
{
register struct nameblock *p;
int i, j;
int descset, nfargs;
TIMETYPE tjunk;
char c, *s;
static char onechar[2] = "X";
#ifdef unix
int intrupt();
I 6
#endif
E 6
I 3
char *op = options + 1;
E 3

D 6


#endif
E 6

#ifdef METERFILE
meter(METERFILE);
#endif

descset = 0;

funny['\0'] = (META | TERMINAL);
for(s = "=|^();&<>*?[]:$`'\"\\\n" ; *s ; ++s)
	funny[*s] |= META;
for(s = "\n\t :;&>|" ; *s ; ++s)
	funny[*s] |= TERMINAL;


inarglist = 1;
for(i=1; i<argc; ++i)
	if(argv[i]!=0 && argv[i][0]!='-' && eqsign(argv[i]))
		argv[i] = 0;

setvar("$","$");
inarglist = 0;

D 3
for(i=1; i<argc; ++i)
    if(argv[i]!=0 && argv[i][0]=='-')
	{
	for(j=1 ; (c=argv[i][j])!='\0' ; ++j)  switch(c)
		{
		case 'd':
			dbgflag = YES;
			break;
E 3
I 3
for (i=1; i<argc; ++i)
	if (argv[i]!=0 && argv[i][0]=='-') {
		for (j=1 ; (c=argv[i][j])!='\0' ; ++j) {
			*op++ = c;
			switch (c) {
E 3

D 3
		case 'p':
			prtrflag = YES;
			break;
E 3
I 3
			case 'd':
				dbgflag = YES;
				break;
E 3

D 3
		case 's':
			silflag = YES;
			break;
E 3
I 3
			case 'p':
				prtrflag = YES;
				break;
E 3

D 3
		case 'i':
			ignerr = YES;
			break;
E 3
I 3
			case 's':
				silflag = YES;
				break;
E 3

D 3
		case 'S':
			keepgoing = NO;
			break;
E 3
I 3
			case 'i':
				ignerr = YES;
				break;
E 3

D 3
		case 'k':
			keepgoing = YES;
			break;
E 3
I 3
			case 'S':
				keepgoing = NO;
				break;
E 3

D 3
		case 'n':
			noexflag = YES;
			break;
E 3
I 3
			case 'k':
				keepgoing = YES;
				break;
E 3

D 3
		case 'r':
			noruleflag = YES;
			break;
E 3
I 3
			case 'n':
				noexflag = YES;
				break;
E 3

D 3
		case 't':
			touchflag = YES;
			break;
E 3
I 3
			case 'r':
				noruleflag = YES;
				break;
E 3

D 3
		case 'q':
			questflag = YES;
			break;
E 3
I 3
			case 't':
				touchflag = YES;
				break;
E 3

D 3
		case 'f':
			if(i >= argc-1)
			  fatal("No description argument after -f flag");
			if( rddescf(argv[i+1]) )
E 3
I 3
			case 'q':
				questflag = YES;
				break;

			case 'f':
				op--;		/* don't pass this one */
				if(i >= argc-1)
				  fatal("No description argument after -f flag");
				if( rddescf(argv[i+1]) )
E 3
				fatal1("Cannot open %s", argv[i+1]);
D 3
			argv[i+1] = 0;
			++descset;
			break;
E 3
I 3
				argv[i+1] = 0;
				++descset;
				break;
E 3

I 9
			case 'e':
				doenvlast = YES;
				break;

E 9
D 3
		default:
			onechar[0] = c;	/* to make lint happy */
			fatal1("Unknown flag argument %s", onechar);
E 3
I 3
			default:
				onechar[0] = c;	/* to make lint happy */
				fatal1("Unknown flag argument %s", onechar);
			}
E 3
		}
D 3

	argv[i] = 0;
E 3
I 3
		argv[i] = 0;
E 3
	}
I 3

*op++ = '\0';
I 4
if (strcmp(options, "-") == 0)
	*options = '\0';
E 4
setvar("MFLAGS", options);		/* MFLAGS=options to make */
E 3

I 9
setvar("MACHINE", MACHINE);

E 9
if( !descset )
#ifdef unix
	if( rddescf("makefile") )  rddescf("Makefile");
#endif
#ifdef gcos
	rddescf("makefile");
#endif

I 9
if (doenvlast == YES)
	readenv();

E 9
if(prtrflag) printdesc(NO);

if( srchname(".IGNORE") ) ++ignerr;
if( srchname(".SILENT") ) silflag = 1;
if(p=srchname(".SUFFIXES")) sufflist = p->linep;
if( !sufflist ) fprintf(stderr,"No suffix list.\n");

#ifdef unix
sigivalue = (int) signal(SIGINT, SIG_IGN) & 01;
sigqvalue = (int) signal(SIGQUIT, SIG_IGN) & 01;
enbint(intrupt);
#endif

nfargs = 0;

for(i=1; i<argc; ++i)
	if((s=argv[i]) != 0)
		{
		if((p=srchname(s)) == 0)
			{
			p = makename(s);
			}
		++nfargs;
		doname(p, 0, &tjunk);
		if(dbgflag) printdesc(YES);
		}

/*
If no file arguments have been encountered, make the first
name encountered that doesn't start with a dot
*/

if(nfargs == 0)
	if(mainname == 0)
		fatal("No arguments or description file");
	else	{
		doname(mainname, 0, &tjunk);
		if(dbgflag) printdesc(YES);
		}

exit(0);
}

I 5
#include <sys/stat.h>
E 5

D 5

E 5
#ifdef unix
intrupt()
{
struct varblock *varptr();
char *p;
TIMETYPE exists();
I 5
struct stat sbuf;
E 5

if(okdel && !noexflag && !touchflag &&
D 5
	(p = varptr("@")->varval) && exists(p)>0 && !isprecious(p) )
E 5
I 5
	(p = varptr("@")->varval) &&
	(stat(p, &sbuf) >= 0 && (sbuf.st_mode&S_IFMT) == S_IFREG) &&
	!isprecious(p) )
E 5
		{
		fprintf(stderr, "\n***  %s removed.", p);
		unlink(p);
		}

if(junkname[0])
	unlink(junkname);
fprintf(stderr, "\n");
exit(2);
}




isprecious(p)
char *p;
{
register struct lineblock *lp;
register struct depblock *dp;
register struct nameblock *np;

if(np = srchname(".PRECIOUS"))
	for(lp = np->linep ; lp ; lp = lp->nxtlineblock)
		for(dp = lp->depp ; dp ; dp = dp->nxtdepblock)
			if(! unequal(p, dp->depname->namep))
				return(YES);

return(NO);
}


enbint(k)
int (*k)();
{
if(sigivalue == 0)
	signal(SIGINT,k);
if(sigqvalue == 0)
	signal(SIGQUIT,k);
}
#endif

extern char *builtin[];

char **linesptr	= builtin;

FILE * fin;
int firstrd	= 0;


rddescf(descfile)
char *descfile;
{
FILE * k;

/* read and parse description */

if( !firstrd++ )
	{
	if( !noruleflag )
		rdd1( (FILE *) NULL);

I 9
	if (doenvlast == NO)
		readenv();

E 9
#ifdef pwb
		{
D 7
		char *nlog, s[100];
E 7
I 7
		char *nlog, s[BUFSIZ];
E 7
		nlog = logdir();
		if ( (k=fopen( concat(nlog,"/makecomm",s), "r")) != NULL)
			rdd1(k);
		else if ( (k=fopen( concat(nlog,"/Makecomm",s), "r")) != NULL)
			rdd1(k);
	
		if ( (k=fopen("makecomm", "r")) != NULL)
			rdd1(k);
		else if ( (k=fopen("Makecomm", "r")) != NULL)
			rdd1(k);
		}
#endif

	}
if(! unequal(descfile, "-"))
	return( rdd1(stdin) );

if( (k = fopen(descfile,"r")) != NULL)
	return( rdd1(k) );

return(1);
}




rdd1(k)
FILE * k;
{
extern int yylineno;
extern char *zznextc;

fin = k;
yylineno = 0;
zznextc = 0;

if( yyparse() )
	fatal("Description file error");

D 8
if(fin != NULL)
E 8
I 8
if(fin != NULL && fin != stdin)
E 8
	fclose(fin);

return(0);
}

printdesc(prntflag)
int prntflag;
{
struct nameblock *p;
struct depblock *dp;
struct varblock *vp;
D 2
struct opendir *od;
E 2
I 2
struct dirhdr *od;
E 2
struct shblock *sp;
struct lineblock *lp;

#ifdef unix
if(prntflag)
	{
	printf("Open directories:\n");
	for (od = firstod; od; od = od->nxtopendir)
D 2
		printf("\t%d: %s\n", fileno(od->dirfc), od->dirn);
E 2
I 2
D 10
		printf("\t%d: %s\n", od->dirfc->dd_fd, od->dirn);
E 10
I 10
		printf("\t%d: %s\n", dirfd(od->dirfc), od->dirn);
E 10
E 2
	}
#endif

if(firstvar != 0) printf("Macros:\n");
for(vp = firstvar; vp ; vp = vp->nxtvarblock)
	printf("\t%s = %s\n" , vp->varname , vp->varval);

for(p = firstname; p; p = p->nxtnameblock)
	{
	printf("\n\n%s",p->namep);
	if(p->linep != 0) printf(":");
	if(prntflag) printf("  done=%d",p->done);
	if(p==mainname) printf("  (MAIN NAME)");
	for(lp = p->linep ; lp ; lp = lp->nxtlineblock)
		{
		if( dp = lp->depp )
			{
			printf("\n depends on:");
			for(; dp ; dp = dp->nxtdepblock)
				if(dp->depname != 0)
					printf(" %s ", dp->depname->namep);
			}
	
		if(sp = lp->shp)
			{
			printf("\n commands:\n");
			for( ; sp!=0 ; sp = sp->nxtshblock)
				printf("\t%s\n", sp->shbp);
			}
		}
	}
printf("\n");
fflush(stdout);
I 9
}

readenv()
{
	register char **ep, *p;
	extern char **environ;

	for(ep = environ ; *ep ; ++ep) {
		for (p = *ep; *p; p++) {
			if (isalnum(*p))
				continue;
			if (*p == '=') {
				eqsign(*ep);
			}
			break;
		}
	}
E 9
}
E 1
