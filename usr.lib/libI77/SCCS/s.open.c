h19180
s 00003/00001/00241
d D 5.2 86/01/08 16:49:41 jerry 14 13
c check if exceeding number of scratch files mktemp will make.
e
s 00007/00001/00235
d D 5.1 85/06/07 23:52:55 kre 13 12
c Add copyright
e
s 00048/00003/00188
d D 1.12 85/05/21 19:25:07 libs 12 11
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00032/00004/00159
d D 1.11 85/05/06 14:44:00 libs 11 10
c set errno to F_ERSYS since old errno is useless & user may be opening to
c many files; also allow overwriting of file names via environment vars.
e
s 00001/00001/00162
d D 1.10 83/04/29 11:19:00 dlw 10 9
c changed FROM_OPEN to be "stu's quote". DLW
e
s 00002/00002/00161
d D 1.9 83/04/25 17:07:38 dlw 9 8
c changed default to be BOF. DLW
e
s 00004/00007/00159
d D 1.8 83/04/25 01:35:59 dlw 8 7
c changed definition of io flags. DLW
e
s 00010/00002/00156
d D 1.7 83/04/22 10:04:37 dlw 7 6
c fixed opnbof to creat if not found. DLW
e
s 00012/00002/00146
d D 1.6 83/04/21 23:25:23 dlw 6 5
c added global flags for ccntrl & blzero. DLW
e
s 00005/00002/00143
d D 1.5 83/04/14 22:26:46 dlw 5 4
c added flag to open at beginning of file. DLW
e
s 00007/00002/00138
d D 1.4 82/10/30 17:43:13 dlw 4 3
c default access mode is sequential. DLW
e
s 00006/00001/00134
d D 1.3 82/04/30 13:45:15 dlw 3 2
c added test for recl & seq/dir access. DLW
e
s 00006/00006/00129
d D 1.2 81/02/20 18:33:14 dlw 2 1
c changed to F_ER codes. DLW
e
s 00135/00000/00000
d D 1.1 81/02/18 18:01:42 dlw 1 0
c date and time created 81/02/18 18:01:42 by dlw
e
u
U
t
T
I 1
/*
D 13
char id_open[] = "%W%";
E 13
I 13
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
 *
I 13
 *	%W%	%G%
 */

/*
E 13
D 12
 * open.c  -  f77 file open routines
E 12
I 12
 * open.c  -  f77 file open and I/O library initialization routines
E 12
 */

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<errno.h>
#include	"fio.h"

#define SCRATCH	(st=='s')
#define NEW	(st=='n')
#define OLD	(st=='o')
#define OPEN	(b->ufd)
D 10
#define FROM_OPEN	"\1"	/* for use in f_clos() */
E 10
I 10
#define FROM_OPEN	"\2"	/* for use in f_clos() */
I 11
#define BUF_LEN 256
E 11
E 10

I 5
D 8
short	opnbof_;		/* open at beginning of file */
I 6
short	ccntrl_;		/* recognize carriage control */
short	blzero_;		/* blanks count as zero */
E 8
E 6
E 5
D 12
extern char *tmplate;
extern char *fortfile;
E 12
I 12
LOCAL char *tmplate = "tmp.FXXXXXX";	/* scratch file template */
LOCAL char *fortfile = "fort.%d";	/* default file template */
E 12

I 11
char *getenv();

E 11
f_open(a) olist *a;
{	unit *b;
	int n,exists;
D 11
	char buf[256],st;
E 11
I 11
	char buf[BUF_LEN], env_name[BUF_LEN];
	char *env_val, *p1, *p2, ch, st;
E 11
	cllist x;

	lfname = NULL;
	elist = NO;
	external = YES;			/* for err */
	errflag = a->oerr;
	lunit = a->ounit;
D 2
	if(not_legal(lunit)) err(errflag,101,"open")
E 2
I 2
	if(not_legal(lunit)) err(errflag,F_ERUNIT,"open")
E 2
	b= &units[lunit];
	if(a->osta) st = lcase(*a->osta);
	else st = 'u';
	if(SCRATCH)
	{	strcpy(buf,tmplate);
D 14
		mktemp(buf);
E 14
I 14
		/* make a new temp file name, err if mktemp fails */
		if( strcmp( mktemp(buf), "/" ) == 0 )
			err(errflag, F_ERSYS, "open")
E 14
	}
D 11
	else if(a->ofnm) g_char(a->ofnm,a->ofnmlen,buf);
	else sprintf(buf,fortfile,lunit);
E 11
I 11
	else 
	{
		if(a->ofnm) g_char(a->ofnm,a->ofnmlen,buf);
		else sprintf(buf,fortfile,lunit);
		/*   check if overriding file name via environment variable
		 *   first copy tail of name - delete periods as Bourne Shell
		 *      croaks if any periods in name
		 */
		 p1 = buf;
		 p2 = env_name;
		 while ((ch = *p1++) != '\0') {
			if(ch == '/') p2 = env_name;
			else if(ch != '.') *p2++ = ch;
		 }
		 if(p2 != env_name) {
		    *p2 = '\0';
		    if( (env_val = getenv( env_name  )) != NULL ) {
			if(strlen(env_val) >= BUF_LEN-1 )
			    err(errflag,F_ERSTAT,"open: file name too long");
			strcpy(buf, env_val);
		    }
		 }
	}
E 11
	lfname = &buf[0];
	if(OPEN)
	{
		if(!a->ofnm || inode(buf)==b->uinode)
		{
			if(a->oblnk) b->ublnk= (lcase(*a->oblnk)== 'z');
#ifndef KOSHER
			if(a->ofm && b->ufmt) b->uprnt = (lcase(*a->ofm)== 'p');
#endif
			return(OK);
		}
		x.cunit=lunit;
		x.csta=FROM_OPEN;
		x.cerr=errflag;
		if(n=f_clos(&x)) return(n);
	}
	exists = (access(buf,0)==NULL);
D 2
	if(!exists && OLD) err(errflag,118,"open");
	if( exists && NEW) err(errflag,117,"open");
E 2
I 2
	if(!exists && OLD) err(errflag,F_EROLDF,"open");
	if( exists && NEW) err(errflag,F_ERNEWF,"open");
I 11
	errno = F_ERSYS;
E 11
E 2
	if(isdev(buf))
	{	if((b->ufd = fopen(buf,"r")) != NULL) b->uwrt = NO;
		else	err(errflag,errno,buf)
	}
	else
D 5
	{	if((b->ufd = fopen(buf, "a")) != NULL) b->uwrt = YES;
E 5
I 5
D 7
	{	if(!opnbof_ && (b->ufd = fopen(buf, "a")) != NULL)
			b->uwrt = YES;
E 7
I 7
D 11
	{	if((b->ufd = fopen(buf, "a")) != NULL)
E 11
I 11
	{	
		errno = F_ERSYS;
		if((b->ufd = fopen(buf, "a")) != NULL)
E 11
D 8
		{	if(opnbof_)
E 8
I 8
D 9
		{	if(opnbof)
E 9
I 9
		{	if(!opneof)
E 9
E 8
			{	if(freopen(buf, "r", b->ufd) != NULL)
					b->uwrt = NO;
				else
					err(errflag, errno, buf)
			}
			else
				b->uwrt = YES;
		}
E 7
E 5
		else if((b->ufd = fopen(buf, "r")) != NULL)
D 5
		{	fseek(b->ufd, 0L, 2);
E 5
I 5
D 8
		{	if (!opnbof_)
E 8
I 8
D 9
		{	if (!opnbof)
E 9
I 9
		{	if (opneof)
E 9
E 8
				fseek(b->ufd, 0L, 2);
E 5
			b->uwrt = NO;
		}
		else	err(errflag, errno, buf)
	}
D 2
	if((b->uinode=finode(b->ufd))==-1) err(errflag,108,"open")
E 2
I 2
	if((b->uinode=finode(b->ufd))==-1) err(errflag,F_ERSTAT,"open")
E 2
	b->ufnm = (char *) calloc(strlen(buf)+1,sizeof(char));
D 2
	if(b->ufnm==NULL) err(errflag,113,"open")
E 2
I 2
	if(b->ufnm==NULL) err(errflag,F_ERSPACE,"open")
E 2
	strcpy(b->ufnm,buf);
	b->uscrtch = SCRATCH;
	b->uend = NO;
	b->useek = canseek(b->ufd);
D 3
	b->url = a->orl;
E 3
I 3
D 4
	if (a->oacc && lcase(*a->oacc)=='s' && a->orl > 0)
E 4
I 4
	if (a->oacc == NULL)
		a->oacc = "seq";
	if (lcase(*a->oacc)=='s' && a->orl > 0)
	{
E 4
		fputs("Warning: open: record length ignored on sequential access\n", units[0].ufd);
D 4
	else if (a->orl < 0 || (a->oacc && lcase(*a->oacc)=='d' && a->orl == 0))
E 4
I 4
		b->url = 0;
	}
	else if (a->orl < 0 || (lcase(*a->oacc)=='d' && a->orl == 0))
E 4
		err(errflag,F_ERARG,"recl on open")
	else
		b->url = a->orl;
E 3
D 6
	b->ublnk = (a->oblnk && (lcase(*a->oblnk)=='z'));
E 6
I 6
	if (a->oblnk)
		b->ublnk = (lcase(*a->oblnk)=='z');
	else if (lunit == STDERR)
		b->ublnk = NO;
	else
D 8
		b->ublnk = blzero_;
E 8
I 8
		b->ublnk = blzero;
E 8
E 6
	if (a->ofm)
	{
		switch(lcase(*a->ofm))
		{
		case 'f':
			b->ufmt = YES;
			b->uprnt = NO;
			break;
#ifndef KOSHER
		case 'p':	/* print file *** NOT STANDARD FORTRAN ***/
			b->ufmt = YES;
			b->uprnt = YES;
			break;
#endif
		case 'u':
			b->ufmt = NO;
			b->uprnt = NO;
			break;
		default:
D 2
			err(errflag,121,"open form=")
E 2
I 2
			err(errflag,F_ERARG,"open form=")
E 2
		}
	}
	else	/* not specified */
	{	b->ufmt = (b->url==0);
D 6
		b->uprnt = NO;
E 6
I 6
		if (lunit == STDERR)
			b->uprnt = NO;
		else
D 8
			b->uprnt = ccntrl_;
E 8
I 8
			b->uprnt = ccntrl;
E 8
E 6
	}
	if(b->url && b->useek) rewind(b->ufd);
	return(OK);
}

fk_open(rd,seq,fmt,n) ftnint n;
{	char nbuf[10];
	olist a;
	sprintf(nbuf, fortfile, (int)n);
	a.oerr=errflag;
	a.ounit=n;
	a.ofnm=nbuf;
	a.ofnmlen=strlen(nbuf);
	a.osta=NULL;
	a.oacc= seq==SEQ?"s":"d";
	a.ofm = fmt==FMT?"f":"u";
	a.orl = seq==DIR?1:0;
	a.oblnk=NULL;
	return(f_open(&a));
}

I 12
LOCAL
E 12
isdev(s) char *s;
{	struct stat x;
	int j;
	if(stat(s, &x) == -1) return(NO);
	if((j = (x.st_mode&S_IFMT)) == S_IFREG || j == S_IFDIR) return(NO);
	else	return(YES);
}

I 12
/*initialization routine*/
f_init()
{
	ini_std(STDERR, stderr, WRITE);
	ini_std(STDIN, stdin, READ);
	ini_std(STDOUT, stdout, WRITE);
	setlinebuf(stderr);
}

LOCAL
ini_std(u,F,w) FILE *F;
{	unit *p;
	p = &units[u];
	p->ufd = F;
	p->ufnm = NULL;
	p->useek = canseek(F);
	p->ufmt = YES;
	p->uwrt = (w==WRITE)? YES : NO;
	p->uscrtch = p->uend = NO;
	p->ublnk = blzero;
	p->uprnt = ccntrl;
	p->url = 0;
	p->uinode = finode(F);
}

LOCAL
canseek(f) FILE *f; /*SYSDEP*/
{	struct stat x;
	return( (fstat(fileno(f),&x)==0) &&
	(x.st_nlink > 0 /*!pipe*/) && !isatty(fileno(f)) );
}

LOCAL
finode(f) FILE *f;
{	struct stat x;
	if(fstat(fileno(f),&x)==0) return(x.st_ino);
	else return(-1);
}

inode(a) char *a;
{	struct stat x;
	if(stat(a,&x)==0) return(x.st_ino);
	else return(-1);
}
E 12
E 1
