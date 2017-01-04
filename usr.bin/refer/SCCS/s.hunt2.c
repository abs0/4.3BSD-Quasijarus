h04655
s 00036/00031/00252
d D 4.5 87/09/28 18:56:48 bostic 5 4
c "master" declarations; bug report 4.3BSD/usr.bin/27
e
s 00000/00001/00283
d D 4.4 87/08/30 09:02:42 bostic 4 3
c misdeclaration of getw(); bug report 4.3BSD/usr.bin/81
e
s 00002/00002/00282
d D 4.3 85/07/29 09:43:51 bloom 3 2
c fix problem with fseek return in assertions
e
s 00007/00004/00277
d D 4.2 85/01/09 15:52:08 ralph 2 1
c fix type warnings
e
s 00281/00000/00000
d D 4.1 83/05/06 23:47:16 tut 1 0
c date and time created 83/05/06 23:47:16 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include "refer..c"

static int *coord = 0;
int hh[50]; 
extern int *hfreq, hfrflg, hcomp(), hexch();
extern int prfreqs;

doquery(hpt, nhash, fb, nitem, qitem, master)
long *hpt;
FILE *fb;
char *qitem[];
D 5
union ptr {
	unsigned *a; 
	long *b;
} master;
E 5
I 5
unsigned *master;
E 5
{
I 5
	union ptr {
		unsigned *a; 
		long *b;
	} umaster;
E 5
	long k;
	union ptr prevdrop;
	int nf = 0, best = 0, nterm = 0, i, g, j;
	int *prevcoord;
	long lp;
	extern int lmaster, colevel, reached;
	long getl(); 
D 4
	unsigned getw(); 
E 4
	extern int iflong;

# if D1
	fprintf(stderr, "entering doquery nitem %d\n",nitem);
	fprintf(stderr, "first few hashes are %ld %ld %ld %ld %ld\n", hpt[0],hpt[1],hpt[2],hpt[3],hpt[4]);
	fprintf(stderr, "and frequencies are  %d %d %d %d %d\n",hfreq[0],hfreq[1],hfreq[2],hfreq[3],hfreq[4]);
# endif
I 5
	if (iflong)
		umaster.b = (long *) master;
	else
		umaster.a = master;
E 5
	_assert (lmaster>0);
	if (coord==0)
D 2
		coord = zalloc(lmaster, sizeof(lmaster));
E 2
I 2
		coord = (int *) zalloc(lmaster, sizeof(lmaster));
E 2
	if (colevel>0)
	{
D 2
		prevdrop.a=zalloc(lmaster,iflong?sizeof(long): sizeof(int));
		prevcoord = zalloc(lmaster, sizeof(lmaster));
E 2
I 2
		if (iflong)
			prevdrop.b = (long *) zalloc(lmaster, sizeof(long));
		else
			prevdrop.a = (unsigned *) zalloc(lmaster, sizeof(int));
		prevcoord = (int *) zalloc(lmaster, sizeof(lmaster));
E 2
	}
	else
	{
D 5
		prevdrop.a=master.a;
E 5
I 5
		prevdrop.a=umaster.a;
E 5
		prevcoord=coord;
	}
# if D1
	fprintf(stderr, "nitem %d\n",nitem);
# endif
	for(i=0; i<nitem; i++)
	{
		hh[i] = hash(qitem[i])%nhash;
# if D1
		fprintf(stderr,"query wd X%sX has hash %d\n", qitem[i], hh[i]);
# endif
	}
# if D1
	fprintf(stderr, "past that loop nhash %d hpt is %lo\n", nhash, hpt);
# endif
	if (prfreqs)
		for(i=0; i<nitem; i++)
			fprintf(stderr,"item %s hash %d hfreq %d\n",qitem[i], hh[i], hfreq[hh[i]]);
	/* if possible, sort query into decreasing frequency of hashes */
	if (hfrflg)
		shell (nitem, hcomp, hexch);
# if D1
	for(i=0; i<nitem; i++)
		fprintf(stderr, "item hash %d frq %d\n", hh[i], hfreq[hh[i]]);
# endif
	lp = hpt [hh[0]];
# if D1
	fprintf(stderr,"first item hash %d lp %ld 0%lo\n", hh[0],lp,lp);
# endif
	_assert (fb!=NULL);
D 3
	_assert (fseek(fb,lp,0)==NULL);
E 3
I 3
	_assert (fseek(fb, lp, 0) != -1);
E 3
	for(i=0; i<lmaster; i++)
	{
		if (iflong)
D 5
			master.b[i] = getl(fb);
E 5
I 5
			umaster.b[i] = getl(fb);
E 5
		else
D 5
			master.a[i] = getw(fb);
E 5
I 5
			umaster.a[i] = getw(fb);
E 5
		coord[i]=1;
# if D2
		if (iflong)
D 5
			fprintf(stderr,"master has %ld\n",(master.b[i]));
E 5
I 5
			fprintf(stderr,"umaster has %ld\n",(umaster.b[i]));
E 5
		else
D 5
			fprintf(stderr,"master has %d\n",(master.a[i]));
E 5
I 5
			fprintf(stderr,"umaster has %d\n",(umaster.a[i]));
E 5
# endif
		_assert (i<lmaster);
		if (iflong)
		{
D 5
			if (master.b[i] == -1L) break;
E 5
I 5
			if (umaster.b[i] == -1L) break;
E 5
		}
		else
		{
D 5
			if (master.a[i] == -1) break;
E 5
I 5
			if (umaster.a[i] == -1) break;
E 5
		}
	}
	nf= i;
	for(nterm=1; nterm<nitem; nterm++)
	{
# ifdef D1
		fprintf(stderr, "item %d, hash %d\n", nterm, hh[nterm]);
# endif
		if (colevel>0)
		{
			for(j=0; j<nf; j++)
			{
				if (iflong)
D 5
					prevdrop.b[j] = master.b[j];
E 5
I 5
					prevdrop.b[j] = umaster.b[j];
E 5
				else
D 5
					prevdrop.a[j] = master.a[j];
E 5
I 5
					prevdrop.a[j] = umaster.a[j];
E 5
				prevcoord[j] = coord[j];
			}
		}
		lp = hpt[hh[nterm]];
D 3
		_assert (fseek(fb, lp, 0)==0);
E 3
I 3
		_assert (fseek(fb, lp, 0) != -1);
E 3
# if D1
		fprintf(stderr,"item %d hash %d seek to %ld\n",nterm,hh[nterm],lp);
# endif
		g=j=0;
		while (1)
		{
			if (iflong)
				k = getl(fb);
			else
				k = getw(fb);
			if (k== -1) break;
# if D2
			fprintf(stderr,"next term finds %ld\n",k);
# endif
# if D3
			if (iflong)
				fprintf(stderr, "bfwh j %d nf %d master %ld k %ld\n",j,nf,prevdrop.b[j],(long)(k));
			else
				fprintf(stderr, "bfwh j %d nf %d master %ld k %ld\n",j,nf,prevdrop.a[j],(long)(k));
# endif
			while (j<nf && (iflong?prevdrop.b[j]:prevdrop.a[j])<k)
			{
# if D3
				if (iflong)
					fprintf(stderr, "j %d nf %d prevdrop %ld prevcoord %d colevel %d nterm %d k %ld\n",
					j,nf,prevdrop.b[j], prevcoord[j], colevel, nterm, (long)(k));
				else
					fprintf(stderr, "j %d nf %d prevdrop %ld prevcoord %d colevel %d nterm %d k %ld\n",
					j,nf,prevdrop.a[j], prevcoord[j], colevel, nterm, (long)(k));
# endif
				if (prevcoord[j] + colevel <= nterm)
					j++;
				else
				{
					_assert (g<lmaster);
					if (iflong)
D 5
						master.b[g] = prevdrop.b[j];
E 5
I 5
						umaster.b[g] = prevdrop.b[j];
E 5
					else
D 5
						master.a[g] = prevdrop.a[j];
E 5
I 5
						umaster.a[g] = prevdrop.a[j];
E 5
					coord[g++] = prevcoord[j++];
# if D1
					if (iflong)
D 5
						fprintf(stderr, " not skip g %d doc %d coord %d note %d\n",g,master.b[g-1], coord[g-1],master.b[j-1]);
E 5
I 5
						fprintf(stderr, " not skip g %d doc %d coord %d note %d\n",g,umaster.b[g-1], coord[g-1],umaster.b[j-1]);
E 5
					else
D 5
						fprintf(stderr, " not skip g %d doc %ld coord %d nterm %d\n",g,master.a[g-1], coord[g-1],nterm);
E 5
I 5
						fprintf(stderr, " not skip g %d doc %ld coord %d nterm %d\n",g,umaster.a[g-1], coord[g-1],nterm);
E 5
# endif
					continue;
				}
			}
			if (colevel==0 && j>=nf) break;
			if (j<nf && (iflong? prevdrop.b[j]: prevdrop.a[j]) == k)
			{
				if (iflong)
D 5
					master.b[g]=k;
E 5
I 5
					umaster.b[g]=k;
E 5
				else
D 5
					master.a[g]=k;
E 5
I 5
					umaster.a[g]=k;
E 5
				coord[g++] = prevcoord[j++]+1;
# if D1
				if (iflong)
D 5
					fprintf(stderr, " at g %d item %ld coord %d note %ld\n",g,master.b[g-1],coord[g-1],master.b[j-1]);
E 5
I 5
					fprintf(stderr, " at g %d item %ld coord %d note %ld\n",g,umaster.b[g-1],coord[g-1],umaster.b[j-1]);
E 5
				else
D 5
					fprintf(stderr, " at g %d item %d coord %d note %d\n",g,master.a[g-1],coord[g-1],master.a[j-1]);
E 5
I 5
					fprintf(stderr, " at g %d item %d coord %d note %d\n",g,umaster.a[g-1],coord[g-1],umaster.a[j-1]);
E 5
# endif
			}
			else
				if (colevel >= nterm)
				{
					if (iflong)
D 5
						master.b[g]=k;
E 5
I 5
						umaster.b[g]=k;
E 5
					else
D 5
						master.a[g]=k;
E 5
I 5
						umaster.a[g]=k;
E 5
					coord[g++] = 1;
				}
		}
# if D1
		fprintf(stderr,"now have %d items\n",g);
# endif
		if (colevel>0)
			for ( ; j<nf; j++)
D 2
				if ((iflong?prevcoord.b[j]:prevcoord.a[j])+colevel > nterm)
E 2
I 2
				if (prevcoord[j]+colevel > nterm)
E 2
				{
					_assert(g<lmaster);
					if (iflong)
D 5
						master.b[g] = prevdrop.b[j];
E 5
I 5
						umaster.b[g] = prevdrop.b[j];
E 5
					else
D 5
						master.a[g] = prevdrop.a[j];
E 5
I 5
						umaster.a[g] = prevdrop.a[j];
E 5
					coord[g++] = prevcoord[j];
# if D3
					if(iflong)
D 5
						fprintf(stderr, "copied over %ld coord %d\n",master.b[g-1], coord[g-1]);
E 5
I 5
						fprintf(stderr, "copied over %ld coord %d\n",umaster.b[g-1], coord[g-1]);
E 5
					else
D 5
						fprintf(stderr, "copied over %d coord %d\n",master.a[g-1], coord[g-1]);
E 5
I 5
						fprintf(stderr, "copied over %d coord %d\n",umaster.a[g-1], coord[g-1]);
E 5
# endif
				}
		nf = g;
	}
	if (colevel>0)
	{
		best=0;
		for(j=0; j<nf; j++)
			if (coord[j]>best) best = coord[j];
# if D1
		fprintf(stderr, "colevel %d best %d\n", colevel, best);
# endif
		reached = best;
		for(g=j=0; j<nf; j++)
			if (coord[j]==best)
			{
				if (iflong)
D 5
					master.b[g++] = master.b[j];
E 5
I 5
					umaster.b[g++] = umaster.b[j];
E 5
				else
D 5
					master.a[g++] = master.a[j];
E 5
I 5
					umaster.a[g++] = umaster.a[j];
E 5
			}
		nf=g;
# if D1
		fprintf(stderr, "yet got %d\n",nf);
# endif
	}
# ifdef D1
	fprintf(stderr, " returning with %d\n",nf);
# endif
	if (colevel)
	{
		free(prevdrop, lmaster, iflong?sizeof(long): sizeof(int));
		free(prevcoord, lmaster, sizeof (lmaster));
	}
# if D3
	for(g=0;g<nf;g++)
		if(iflong)
D 5
			fprintf(stderr,":%ld\n",master.b[g]);
E 5
I 5
			fprintf(stderr,":%ld\n",umaster.b[g]);
E 5
		else
D 5
			fprintf(stderr,":%d\n",master.a[g]);
E 5
I 5
			fprintf(stderr,":%d\n",umaster.a[g]);
E 5
# endif
	return(nf);
}

long
getl(fb)
FILE *fb;
{
	return(getw(fb));
}

putl(ll, f)
long ll;
FILE *f;
{
	putw(ll, f);
}

hcomp( n1, n2)
{
	return (hfreq[hh[n1]]<=hfreq[hh[n2]]);
}

hexch( n1, n2 )
{
	int t;
	t = hh[n1];
	hh[n1] = hh[n2];
	hh[n2] = t;
}
E 1
