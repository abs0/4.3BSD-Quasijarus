h07586
s 00007/00007/00148
d D 4.2 87/09/11 08:15:08 bostic 2 1
c get rid of old assignment operators
e
s 00155/00000/00000
d D 4.1 83/05/06 23:50:13 tut 1 0
c date and time created 83/05/06 23:50:13 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include "what..c"

struct filans files[NFILES];
char fnames[NAMES];
D 2
int relfeed 0;
E 2
I 2
int relfeed = 0;
E 2
char *rb[NFEED];
D 2
char rbb[200], *rbp rbb;
E 2
I 2
char rbb[200], *rbp = rbb;
E 2
;

main(argc,argv)
char *argv[];
{
	char *s, *t, *xargv[50], *wd[50];
	struct filans *af;
D 2
	int xargc 0, nw, nf, i;
E 2
I 2
	int xargc = 0, nw, nf, i;
E 2
	while (argc>1 && argv[1][0]=='-')
	{
		switch(argv[1][1])
		{
		case 'r': 
			relfeed=1; 
			break;
		}
		argc--; 
		argv++;
	}
	if (argc<=1)
	{
		printf("No query.\n");
		return(0);
	}
	nf = doclook(argc,argv,0);
	printf("   %d files\n",nf);
	if (relfeed && nf>NFEED)
	{
		wrdoc(NFEED, argc, argv, 1);
		nw = freqwd (rb, wd, argc);
		for(i=0; rb[i]; i++)
			unlink(rb[i]);
	}
	for(i=0; i<argc; i++)
		xargv[xargc++]=argv[i];
	if (relfeed)
	{
		printf("Adding: ");
		for(i=0; i<nw; i++)
			if (!lfind(wd[i], xargc, xargv))
				printf("%s ", xargv[xargc++]=wd[i]);
		printf("\n");
		nf = doclook(xargc, xargv, relfeed? xargc/4 : 0);
		printf("  %d files\n",nf);
	}
	shell (nf, comp, exch);
	wrdoc(nf, xargc, xargv, 0);
	return(0);
}

exch( i1, i2 )
{
	struct filans *p1, *p2;
	struct filans xt;
	p1=files+i1;
	p2=files+i2;
	xt = *p1;
	*p1 = *p2;
	*p2 = xt;
}

comp(i1, i2)
{
	struct filans *p1, *p2;
	p1 = files+i1;
	p2= files+i2;
	if (p1->fdate != p2->fdate)
		return(p2->fdate > p1->fdate);
	return(p2->uid >= p1->uid);
}

wrdoc ( np, argc, argv, relfeed )
{
	struct filans *af;
D 2
	char *s, *t, buf[200];
E 2
I 2
	char *s, *t, buf[200], *ctime();
E 2
	int eval, k, pid;
D 2
	FILE *rf NULL;
	FILE *ans NULL;
E 2
I 2
	FILE *rf = NULL;
	FILE *ans = NULL;
E 2
	pid=getpid();
	for(af=files; af<files+np; af++)
	{
		t = ctime(&af->fdate);
		getpw(af->uid, s=buf);
		while (*s && *s!=':') s++;
		*s=0;
		printf("%s (%.20s)  %s, %ld bytes\n",af->nm,t+4,buf,af->size);
		if (relfeed)
		{
			k=af-files;
			_assert (k<NFEED);
			sprintf(rb[k]=rbp, "rf%d.%d",pid, k);
			rf = fopen(rb[k], "w");
			while (*rbp++);
		}
		describe(af->nm, argc,argv, rf);
		if (relfeed)
		{
			printf("You like that one?");
			fflush(stdout);
			fgets(buf, 100, stdin);
			switch(buf[0])
			{
			case 'y': 
			case 'Y': 
				eval=1; 
				break;
			case 'n': 
			case 'N': 
				eval = -1; 
				break;
			default: 
				eval=0; 
				break;
			}
			fclose(rf);
			if (eval<=0)
			{
				unlink(rb[k]);
				rb[k][0]=0;
			}
		}
	}
	if (relfeed) rb[np]=0;
}

lfind( wl, n, wds)
char *wl, *wds[];
{
	int i;
	for(i=0; i<n; i++)
		if (str6cmp(wl, wds[i])==0)
			return(1);
	return(0);
}

str6cmp(s, t)
char *s, *t;
{
D 2
	int i 0, c;
E 2
I 2
	int i = 0, c;
E 2
	while ( (c= *s++ ) == ( *t++))
		if (c==0 || ++i ==6)
			return(0);
	return(1);
}
E 1
