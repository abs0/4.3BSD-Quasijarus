h59563
s 00004/00004/00273
d D 4.3 85/01/09 15:52:01 ralph 3 2
c fix type warnings
e
s 00051/00029/00226
d D 4.2 83/06/21 16:15:51 garrison 2 1
c merged in changes made by Mark Horton and/or Ozalp Bablaoglu
c to create an fgrep file (and use it) if the .i[abc] files do not exist.
e
s 00255/00000/00000
d D 4.1 83/05/06 23:47:14 tut 1 0
c date and time created 83/05/06 23:47:14 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

D 2
#include <stdio.h>
#include <assert.h>
E 2
I 2
# include <stdio.h>
# include <assert.h>
E 2
extern char refdir[];
extern int keepold;
extern char *fgnames[];
extern char **fgnamp;
D 2
FILE *fd = 0;
int lmaster = 500;
E 2
I 2
FILE *fd =NULL;
int lmaster =500;
E 2
int *hfreq, hfrflg;
D 2
int colevel = 0;
int soutlen = 1000;
int reached = 0;
int iflong = 0;
int prfreqs = 0;
E 2
I 2
int colevel =0;
int measure=0;
int soutlen =1000;
int reached =0;
int iflong =0;
int prfreqs =0;
E 2
char usedir[100];
I 2
char * calloc(); 
char * todir();
E 2
char gfile[50];
D 2
static int full = 1000;
static int tags = 0;
E 2
I 2
static int full =1000;
static int tags =0;
E 2
char *sinput, *soutput, *tagout;
D 2
long indexdate = 0, gdate();
extern char *todir();
E 2
I 2
long indexdate =0, gdate();
E 2

main(argc,argv)
char *argv[];
{
	/* read query from stdin, expect name of indexes in argv[1] */
	static FILE *fa, *fb, *fc;
D 2
	char nma[100], nmb[100], nmc[100], *qitem[100], *rprog = 0;
E 2
I 2
	char nma[100], nmb[100], nmc[100], *qitem[100], *rprog = NULL;
E 2
	char nmd[100], grepquery[256];
	static char oldname[30] ;
D 2
	static int was = 0;
E 2
I 2
	static int was =0;
E 2
	/* these pointers are unions of pointer to int and pointer to long */
	long *hpt;
D 2
	unsigned *master = 0;
E 2
I 2
	unsigned *master =0;
E 2
	int falseflg, nhash, nitem, nfound, frtbl, kk;

	/* special wart for refpart: default is tags only */

	while (argv[1][0] == '-')
	{
		switch(argv[1][1])
		{
		case 'a': /* all output, incl. false drops */
			falseflg = 1; 
			break;
		case 'r':
			argc--; 
			argv++;
			rprog = argv[1];
			break;
		case 'F': /* put out full text */
			full = setfrom(argv[1][2]);
			break;
		case 'T': /* put out tags */
			tags = setfrom(argv[1][2]);
			break;
		case 'i': /* input in argument string */
			argc--; 
			argv++;
			sinput = argv[1];
			break;
		case 's': /*text output to string */
		case 'o':
			argc--; 
			argv++;
			soutput = argv[1];
D 3
			if (argv[2]<16000)
E 3
I 3
			if ((int) argv[2]<16000)
E 3
			{
D 2
				soutlen = argv[2];
E 2
I 2
				soutlen = (int)argv[2];
E 2
				argc--; 
				argv++;
			}
			break;
		case 't': /*tag output to string */
			argc--; 
			argv++;
			tagout = argv[1];
			break;
		case 'l': /* length of internal lists */
			argc--; 
			argv++;
			lmaster = atoi(argv[1]);
			break;
		case 'g': /* suppress fgrep search on old files */
			keepold = 0;
			break;
		case 'C': /* coordination level */
			colevel = atoi(argv[1]+2);
# if D1
			fprintf(stderr, "colevel set to %d\n",colevel);
# endif
			break;
		case 'P': /* print term freqs */
			prfreqs=1; 
			break;
I 2
		case 'm':
			measure=1; 
			break;
E 2
		}
		argc--; 
		argv++;
	}
	strcpy (nma, todir(argv[1]));
	if (was == 0 || strcmp (oldname, nma) !=0)
	{
		strcpy (oldname,nma);
		strcpy (nmb, nma); 
		strcpy (nmc, nmb); 
		strcpy(nmd,nma);
		strcat (nma, ".ia");
		strcat (nmb, ".ib");
		strcat (nmc, ".ic");
		strcat (nmd, ".id");
		if (was)
		{
			fclose(fa); 
			fclose(fb); 
			fclose(fc);
		}

		fa = fopen(nma, "r");
		if (fa==NULL)
		{
D 2
			err("No files %s",nma);
			exit(1);
E 2
I 2
			strcpy(*fgnamp++ = calloc(strlen(oldname)+2,1), oldname);
			fb=NULL;
			goto search;
E 2
		}
		fb = fopen(nmb, "r");
		fc = fopen(nmc, "r");
		was =1;
		if (fb== NULL || fc ==NULL)
		{
			err("Index incomplete %s", nmb);
			exit(1);
		}
		indexdate = gdate(fb);
		fd = fopen(nmd, "r");
	}
	fseek (fa, 0L, 0);
	fread (&nhash, sizeof(nhash), 1, fa);
	fread (&iflong, sizeof(iflong), 1, fa);
	if(master==0)
D 2
		master = calloc (lmaster, iflong? sizeof(long): sizeof(int));
E 2
I 2
D 3
		master = calloc (lmaster, iflong? 4: 2);
E 2
	hpt = calloc(nhash, sizeof(*hpt));
E 3
I 3
		master = (unsigned *) calloc (lmaster, iflong? sizeof(long): sizeof(unsigned));
	hpt = (long *) calloc(nhash, sizeof(*hpt));
E 3
	kk=fread( hpt, sizeof(*hpt), nhash, fa);
# if D1
	fprintf(stderr,"read %d hashes, iflong %d, nhash %d\n", kk, iflong, nhash);
# endif
	_assert (kk==nhash);
D 3
	hfreq = calloc(nhash, sizeof(*hfreq));
E 3
I 3
	hfreq = (int *) calloc(nhash, sizeof(*hfreq));
E 3
	_assert (hfreq != NULL);
	frtbl = fread(hfreq, sizeof(*hfreq), nhash, fa);
	hfrflg = (frtbl == nhash);
# if D1
	fprintf(stderr, "read freqs %d\n", frtbl);
# endif

I 2
search:
E 2
	while (1)
	{
		nitem = getq(qitem);
I 2
		if (measure) tick();
E 2
		if (nitem==0) continue;
		if (nitem < 0) break;
D 2
		nfound = doquery(hpt, nhash, fb, nitem, qitem, master);
E 2
I 2
		if (tagout) tagout[0]=0;
		if (fb!=NULL)
		{
			nfound = doquery(hpt, nhash, fb, nitem, qitem, master);
E 2
# if D1
D 2
		fprintf(stderr,"after doquery nfound %d\n", nfound);
E 2
I 2
			fprintf(stderr,"after doquery nfound %d\n", nfound);
E 2
# endif
D 2
		fgnamp=fgnames;
		if (falseflg == 0)
			nfound = baddrop(master, nfound, fc, nitem, qitem, rprog, full);
E 2
I 2
			fgnamp=fgnames;
			if (falseflg == 0)
				nfound = baddrop(master, nfound, fc, nitem, qitem, rprog, full);
E 2
# if D1
D 2
		fprintf(stderr,"after baddrop nfound %d\n", nfound);
E 2
I 2
			fprintf(stderr,"after baddrop nfound %d\n", nfound);
E 2
# endif
I 2
		}
E 2
		if (fgnamp>fgnames)
		{
			char **fgp, tgbuff[100];
			int k;
# if D1
			fprintf(stderr, "were %d bad files\n", fgnamp-fgnames);
# endif
			grepquery[0]=0;
			for(k=0; k<nitem; k++)
			{
				strcat(grepquery, " ");
				strcat(grepquery, qitem[k]);
			}
# if D1
			fprintf(stderr, "grepquery %s\n",grepquery);
# endif
			for(fgp=fgnames; fgp<fgnamp; fgp++)
			{
# if D1
				fprintf(stderr, "Now on %s query /%s/\n", *fgp, grepquery);
# endif
				makefgrep(*fgp);
# if D1
				fprintf(stderr, "grepmade\n");
# endif
				if (tagout==0)
					tagout=tgbuff;
				grepcall(grepquery, tagout, *fgp);
# if D1
				fprintf(stderr, "tagout now /%s/\n", tagout);
# endif
				if (full)
				{
					char bout[1000];
D 2
					findline(tagout, bout, 1000);
					fputs(bout,stdout);
E 2
I 2
					char *tagp;
					char *oldtagp;
					tagp = tagout;
					while (*tagp) {
						oldtagp = tagp;
						while (*tagp && (*tagp != '\n'))
							tagp++;
						if (*tagp)
							tagp++;
						findline(oldtagp, bout, 1000);
						fputs(bout,stdout);
					}
E 2
				}
			}
		}
		if (tags)
			result (master, nfound >tags ? tags: nfound, fc);
I 2
		if (measure) tock();
E 2
	}
}

char *
todir(t)
char *t;
{
	char *s;
	s=t;
	while (*s) s++;
	while (s>=t && *s != '/') s--;
	if (s<t) return(t);
	*s++ = 0;
	t = (*t ? t : "/");
	chdir (t);
	strcpy (usedir,t);
	return(s);
}
D 2

E 2
setfrom(c)
{
	switch(c)
	{
	case 'y': 
	case '\0':
	default:
		return(1000);
	case '1':
	case '2': 
	case '3': 
	case '4': 
	case '5':
	case '6': 
	case '7': 
	case '8': 
	case '9':
		return(c-'0');
	case 'n': 
	case '0':
		return(0);
	}
}
E 1
